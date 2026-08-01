#!/usr/bin/env python3
"""Apply evidence-backed function names from ``config/symbol_names*.txt`` into C sources.

Every recovered name maps one canonical function address to a real identifier
(``Name = 0xADDRESS; // type:func  evidence: ...``, the same curated line
contract that ``tools/reconcile_function_boundaries.py`` enforces).  The
placeholder identifier ``func_<address>`` is renamed to that name in every code
context of every ``src/**/*.c`` file (excluding ``src/generated``): function
definitions, forward declarations, extern prototypes, call sites, and
function-pointer references.

Renames are whole identifiers only (``func_001a1100`` never touches
``func_001a11001``) and are restricted to code: comments and string/char
literals are left byte-for-byte alone, so a ``// FUN_XXXXXXXX`` marker line
keeps its address form no matter what (verify.py keys on the marker address,
not on the C function name below it).  Files are written in BINARY mode with
their original line endings, so a run is byte-preserving apart from the
identifier swaps themselves.

``--check`` reports every rename that *would* happen and exits non-zero, so CI
can assert the tree is fully applied; a fully applied tree exits 0.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
TOOLS = REPO / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))
# Reuse verify's scanning semantics so the rename never touches anything the
# verifier would not compile: src/generated and other tool-generated units are
# excluded, and sanitize_c_lines blanks comments/strings so we can locate code
# contexts exactly.
from verify import is_generated, sanitize_c_lines  # noqa: E402

# The curated line contract, kept identical to
# tools/reconcile_function_boundaries.py::NAME_LINE (a unit test locks the two
# patterns together so they cannot drift).
NAME_LINE = re.compile(
    r"^\s*(?P<name>[A-Za-z_]\w*)\s*=\s*0x(?P<addr>[0-9A-Fa-f]{8})\s*;"
    r"\s*//\s*type:func\b(?P<rest>.*)$"
)
PLACEHOLDER = re.compile(r"^(?:FUN|func)_[0-9A-Fa-f]+$")

# A recovered name that itself contains a boundary-delimited placeholder could
# be re-renamed by a later run (breaking idempotence) or silently shadow a
# different address's placeholder.  Reject it up front.
EMBEDDED_PLACEHOLDER = re.compile(
    r"(?<![A-Za-z0-9_])(?:FUN|func)_[0-9A-Fa-f]{8}(?![A-Za-z0-9_])"
)

# The placeholder identifier in code.  ``func_`` is lowercase (the marker
# comments are ``FUN_`` uppercase and are comments anyway); the hex digits may
# be either case in hand-written sources, so both are mapped through the
# address.  Both sides are word-boundary-checked: no substring renames.
CODE_IDENT = re.compile(r"(?<![A-Za-z0-9_])func_([0-9a-fA-F]{8})(?![A-Za-z0-9_])")


def canonical_addresses(root: Path) -> set[int]:
    """Canonical function boundary addresses, same source reconcile uses."""
    windows = json.loads(
        (root / "tools" / "slus21782_functions.json").read_text(encoding="utf-8")
    )
    return {int(address, 16) for address in windows["windows"]}


def load_names(files: list[Path], canonical: set[int]) -> dict[int, str]:
    """Parse the curated ``symbol_names*.txt`` producer set.

    Every entry must satisfy the reconcile contract (canonical boundary,
    non-placeholder name, evidence note, unique name and address); any
    violation is a hard error so a half-written producer file can never
    rename garbage into the tree.
    """
    names: dict[int, str] = {}
    seen: dict[str, int] = {}
    for path in sorted(files):
        for number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
            stripped = line.strip()
            if not stripped or stripped.startswith("//"):
                continue
            match = NAME_LINE.match(line)
            where = f"{path.name}:{number}"
            if not match:
                raise RuntimeError(
                    f"{where}: expected `name = 0xADDR; // type:func  evidence: ...`"
                )
            name, address = match["name"], int(match["addr"], 16)
            if PLACEHOLDER.match(name) or EMBEDDED_PLACEHOLDER.search(name):
                raise RuntimeError(f"{where}: {name!r} is a placeholder, not a recovered name")
            if "evidence:" not in match["rest"]:
                raise RuntimeError(f"{where}: {name} has no `evidence:` note")
            if address not in canonical:
                raise RuntimeError(f"{where}: {address:#010x} is not a canonical boundary")
            if address in names:
                raise RuntimeError(f"{where}: duplicate address {address:#010x}")
            if name in seen:
                raise RuntimeError(f"{where}: name {name!r} already used for {seen[name]:#010x}")
            names[address] = name
            seen[name] = address
    return names


def source_files(root: Path) -> list[Path]:
    """All C sources the tool may rename: src/**/*.c minus generated units."""
    return sorted(
        path for path in (root / "src").rglob("*.c") if not is_generated(path)
    )


def plan_file(path: Path, names: dict[int, str]) -> list[tuple[int, int, int, str, str]]:
    """Locate renames in one file: (1-based line, start, end, old, new).

    Matches are found on the comment/string-sanitized copy of each line, so
    only code-context occurrences qualify; the spans map 1:1 onto the original
    line because sanitization pads, never reflows.
    """
    text = path.read_bytes().decode("utf-8")
    lines = text.split("\n")
    sanitized = sanitize_c_lines(lines)
    changes: list[tuple[int, int, int, str, str]] = []
    for index, (original, clean) in enumerate(zip(lines, sanitized), 1):
        for match in CODE_IDENT.finditer(clean):
            address = int(match.group(1), 16)
            name = names.get(address)
            if name is not None and match.group(0) != name:
                changes.append((index, match.start(), match.end(), match.group(0), name))
    return changes


def rewrite(path: Path, changes: list[tuple[int, int, int, str, str]]) -> int:
    """Apply the planned renames, writing back in binary mode.

    Each change splices exactly its own span, so a placeholder that also
    appears in a comment or string on the same line is left alone.  Only the
    identifier spans change; line endings and every other byte are preserved
    exactly (the file is decoded/re-encoded as UTF-8 and written with
    ``write_bytes``, never through a text-mode ``write_text``).
    """
    text = path.read_bytes().decode("utf-8")
    lines = text.split("\n")
    by_line: dict[int, list[tuple[int, int, str]]] = {}
    for index, start, end, _old, new in changes:
        by_line.setdefault(index, []).append((start, end, new))
    for index, spans in by_line.items():
        line = lines[index - 1]
        out, position = [], 0
        for start, end, new in spans:
            out.append(line[position:start])
            out.append(new)
            position = end
        out.append(line[position:])
        lines[index - 1] = "".join(out)
    path.write_bytes("\n".join(lines).encode("utf-8"))
    return len(changes)


def run(root: Path, paths: list[str], check: bool) -> int:
    """Plan (and optionally apply) every pending rename under ``root``.

    Returns an exit code: 0 when nothing is pending (or everything was
    applied), 1 from ``--check`` when renames are pending.
    """
    canonical = canonical_addresses(root)
    files = [Path(path) for path in paths] if paths else source_files(root)
    names = load_names(sorted((root / "config").glob("symbol_names*.txt")), canonical)

    planned: dict[Path, list[tuple[int, int, int, str, str]]] = {}
    total = 0
    for path in files:
        if path.suffix != ".c" or is_generated(path):
            continue
        try:
            changes = plan_file(path, names)
        except UnicodeDecodeError as error:
            raise RuntimeError(f"{path}: not valid UTF-8 ({error})") from error
        if changes:
            planned[path] = changes
            total += len(changes)

    if check:
        if planned:
            for path in sorted(planned):
                try:
                    relative = path.relative_to(root).as_posix()
                except ValueError:
                    relative = str(path)
                for line, _start, _end, old, new in planned[path]:
                    print(f"{relative}:{line}: {old} -> {new}")
            print(f"{total} occurrence(s) in {len(planned)} file(s) would change")
            return 1
        print("all curated names are applied; nothing to do")
        return 0

    for path in sorted(planned):
        count = rewrite(path, planned[path])
        try:
            shown = path.relative_to(root).as_posix()
        except ValueError:
            shown = str(path)
        print(f"{shown}: renamed {count} occurrence(s)")
    print(f"renamed {total} occurrence(s) in {len(planned)} file(s)")
    return 0


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument(
        "--check",
        action="store_true",
        help="report pending renames and exit non-zero instead of applying them",
    )
    parser.add_argument(
        "paths",
        nargs="*",
        help="specific .c files to consider (default: all of src/ minus src/generated)",
    )
    args = parser.parse_args(argv)
    try:
        return run(REPO, args.paths, args.check)
    except (RuntimeError, OSError, json.JSONDecodeError) as error:
        print(f"apply_symbol_names: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
