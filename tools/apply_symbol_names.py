#!/usr/bin/env python3
"""Apply evidence-backed function names from ``config/symbol_names*.txt`` into C sources.

Every recovered name maps one canonical function address to a real identifier
(``Name = 0xADDRESS; // type:func  evidence: ...``, the same curated line
contract that ``tools/reconcile_function_boundaries.py`` enforces).  The
placeholder identifier ``func_<address>`` is renamed in C definitions,
declarations, call sites, and function-pointer references. The second argument
of ``INCLUDE_ASM`` is a filename and linker symbol, not a renameable C call;
renaming an address still referenced by any fallback or assembly is refused.

Renames are whole identifiers only (``func_001a1100`` never touches
``func_001a11001``) and are restricted to code: comments and string/char
literals are left byte-for-byte alone, so a ``// FUN_XXXXXXXX`` marker line
keeps its address form no matter what (verify.py keys on the marker address,
not on the C function name below it).  Files are written in BINARY mode with
their original line endings, so a run is byte-preserving apart from the
identifier swaps themselves.

``--check`` reports pending C renames without changing files, labelling
addresses blocked by assembly linkage, out-of-scope C references, or headers.
It exits non-zero until the backlog is resolved.
"""

from __future__ import annotations

import argparse
import json
import re
import sys
from collections.abc import Iterable
from itertools import chain
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
# The second INCLUDE_ASM argument names an on-disk .s file. Match on sanitized
# source so comments/strings cannot masquerade as macro syntax; allow multiline
# macro invocations without swallowing any other identifier on that line.
ASM_ARG = re.compile(
    r"\bINCLUDE_ASM\s*\(\s*[^,()]*,\s*(func_[0-9a-fA-F]{8})\s*\)"
)



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


def header_files(root: Path) -> list[Path]:
    """Headers outside the C rewrite set may still declare or call old names."""
    return sorted(
        path
        for parent in (root / "src", root / "include")
        for path in parent.rglob("*.h")
        if not is_generated(path)
    )


def plan_file(
    path: Path, names: dict[int, str], *, encoding: str = "utf-8"
) -> list[tuple[int, int, int, str, str]]:
    """Locate renames in one file: (1-based line, start, end, old, new).

    Matches are found on the comment/string-sanitized copy of each line, so
    only code-context occurrences qualify. Latin-1 is for inventory scans of
    legacy headers: ASCII identifiers survive byte-for-byte, and those spans
    are never passed to rewrite().
    """
    text = path.read_bytes().decode(encoding)
    lines = text.split("\n")
    sanitized = sanitize_c_lines(lines)
    clean_text = "\n".join(sanitized)
    asm_args = {match.start(1) for match in ASM_ARG.finditer(clean_text)}
    changes: list[tuple[int, int, int, str, str]] = []
    offset = 0
    for index, clean in enumerate(sanitized, 1):
        for match in CODE_IDENT.finditer(clean):
            if offset + match.start() in asm_args:
                continue
            address = int(match.group(1), 16)
            name = names.get(address)
            if name is not None and match.group(0) != name:
                changes.append((index, match.start(), match.end(), match.group(0), name))
        offset += len(clean) + 1
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


def assembly_names(root: Path) -> set[int]:
    """Addresses whose old linker symbols still occur in assembly or fallbacks."""
    addresses: set[int] = set()
    manifest = root / "config" / "generated_asm.json"
    if manifest.is_file():
        # A partial generated fallback tree cannot prove that an assembly
        # caller is absent. Fail closed before rewriting any C source.
        generated = json.loads(manifest.read_text(encoding="utf-8"))["generated"]
        missing = next(
            (item["path"] for item in generated if not (root / item["path"]).is_file()),
            None,
        )
        if missing is not None:
            raise RuntimeError(f"assembly inventory incomplete ({missing}); regenerate it before renaming")
    for path in chain(source_files(root), header_files(root)):
        clean = "\n".join(sanitize_c_lines(path.read_bytes().decode("latin-1").split("\n")))
        addresses.update(int(match.group(1)[5:], 16) for match in ASM_ARG.finditer(clean))
    for path in (root / "asm").rglob("*.s"):
        addresses.update(
            int(match.group(1), 16)
            for match in CODE_IDENT.finditer(path.read_text(encoding="utf-8"))
        )
    return addresses

def unplanned_references(files: Iterable[Path], names: dict[int, str]) -> dict[int, Path]:
    """First code-context occurrence of each name outside the rewrite scope."""
    found: dict[int, Path] = {}
    for path in files:
        changes = plan_file(path, names, encoding="latin-1")
        for _line, _start, _end, old, _new in changes:
            found.setdefault(int(old[5:], 16), path)
    return found


def run(root: Path, paths: list[str], check: bool) -> int:
    """Plan C renames and reject partial C/header/assembly symbol migrations."""
    canonical = canonical_addresses(root)
    sources = source_files(root)
    if paths:
        files = []
        for name in paths:
            path = Path(name)
            files.append(path if path.is_absolute() else root / path)
    else:
        files = sources
    names = load_names(sorted((root / "config").glob("symbol_names*.txt")), canonical)
    source_set = set(sources)

    planned: dict[Path, list[tuple[int, int, int, str, str]]] = {}
    total = 0
    for path in files:
        if path.suffix != ".c" or is_generated(path):
            continue
        if path not in source_set:
            raise RuntimeError(f"{path}: not a source under src/")
        try:
            changes = plan_file(path, names)
        except UnicodeDecodeError as error:
            raise RuntimeError(f"{path}: not valid UTF-8 ({error})") from error
        if changes:
            planned[path] = changes
            total += len(changes)

    if not planned:
        if check:
            print("all curated names are applied; nothing to do")
        else:
            print("renamed 0 occurrence(s) in 0 file(s)")
        return 0

    pending = {int(old[5:], 16) for changes in planned.values()
               for _line, _start, _end, old, _new in changes}
    pending_names = {addr: names[addr] for addr in pending}
    assembly = pending & assembly_names(root)
    scope = set(files)
    outside = unplanned_references(
        (path for path in sources if path not in scope), pending_names
    ) if paths else {}
    headers = unplanned_references(header_files(root), pending_names)
    blocked = assembly | set(outside) | set(headers)

    def shown(path: Path) -> str:
        try:
            return path.relative_to(root).as_posix()
        except ValueError:
            return str(path)

    if check:
        for path in sorted(planned):
            for line, _start, _end, old, new in planned[path]:
                address = int(old[5:], 16)
                reasons = []
                if address in assembly:
                    reasons.append("assembly-linked")
                if address in outside:
                    reasons.append(f"out-of-scope C: {shown(outside[address])}")
                if address in headers:
                    reasons.append(f"header: {shown(headers[address])}")
                suffix = f" [blocked: {', '.join(reasons)}]" if reasons else " [ready]"
                print(f"{shown(path)}:{line}: {old} -> {new}{suffix}")
        print(f"{total} pending occurrence(s) in {len(planned)} file(s); "
              f"{len(blocked)} address(es) blocked")
        return 1

    if blocked:
        examples = ", ".join(
            f"func_{addr:08x}"
            + (f" (C: {shown(outside[addr])})" if addr in outside else "")
            + (f" (header: {shown(headers[addr])})" if addr in headers else "")
            for addr in sorted(blocked)[:8]
        )
        raise RuntimeError(
            f"cannot rename assembly-linked or partially scoped addresses ({examples}); "
            "all C uses and headers must migrate with their linker symbols"
        )

    for path in sorted(planned):
        count = rewrite(path, planned[path])
        print(f"{shown(path)}: renamed {count} occurrence(s)")
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
