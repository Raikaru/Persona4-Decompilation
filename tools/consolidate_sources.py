#!/usr/bin/env python3
"""Consolidate address-suffixed Persona 4 C sources into module files.

Each recovered function keeps its original source text inside a selectable unit:
``P4_UNIT_<address>``.  The build and verifier compile one unit at a time, so
function-local declarations retain the independent layouts that made the
original one-function translation units safe.  The checked-in source tree is
therefore organized by module without silently changing matching C codegen.
"""

from __future__ import annotations

import argparse
from collections import defaultdict
from pathlib import Path
import re
import sys

REPO = Path(__file__).resolve().parents[1]
SRC = REPO / "src"
ADDRESS_SUFFIX = re.compile(r"_(?P<address>[0-9A-Fa-f]{8})\.c$")
MARKER = re.compile(r"^\s*//\s*FUN_(?P<address>[0-9A-Fa-f]{8})\b", re.MULTILINE)
GUARD = re.compile(r"^\s*#if\s+defined\(P4_UNIT_(?P<address>[0-9A-Fa-f]{8})\)\s*$", re.MULTILINE)


def is_generated(path: Path) -> bool:
    relative = path.relative_to(SRC)
    return (
        path.name.endswith(".match.c")
        or path.name.startswith(".permute_")
        or any(part.startswith("generated") for part in relative.parts)
    )


def marker_addresses(path: Path) -> list[int]:
    text = path.read_text(encoding="utf-8", errors="replace")
    return [int(match.group("address"), 16) for match in MARKER.finditer(text)]


def module_path(path: Path) -> Path:
    match = ADDRESS_SUFFIX.search(path.name)
    if not match:
        return path
    return path.with_name(path.name[: match.start()] + ".c")


def source_files() -> list[Path]:
    return sorted(path for path in SRC.rglob("*.c") if not is_generated(path))


def render_group(target: Path, units: list[Path]) -> str:
    lines = [
        "/* Consolidated Persona 4 source units. */",
        "/* Build with -DP4_UNIT_<address> to select one original source unit. */",
        "",
    ]
    for source in units:
        addresses = marker_addresses(source)
        if not addresses:
            raise RuntimeError(
                f"cannot guard {source.relative_to(REPO)}: no // FUN marker"
            )
        address = addresses[0]
        macro = f"P4_UNIT_{address:08X}"
        relative = source.relative_to(REPO).as_posix()
        body = source.read_text(encoding="utf-8")
        lines.extend(
            [
                f"#if defined({macro})",
                f"/* Source unit: {relative} ({len(addresses)} function markers) */",
                body.rstrip("\n"),
                f"#endif /* {macro} */",
                "",
            ]
        )
    return "\n".join(lines)


def plan() -> dict[Path, tuple[Path, list[Path]]]:
    grouped: dict[Path, list[Path]] = defaultdict(list)
    for path in source_files():
        grouped[module_path(path)].append(path)

    result: dict[Path, tuple[Path, list[Path]]] = {}
    for module, paths in grouped.items():
        suffixed = [path for path in paths if ADDRESS_SUFFIX.search(path.name)]
        if not suffixed:
            continue
        unsuffixed = [path for path in paths if path not in suffixed]
        if unsuffixed:
            # An existing multi-function module already has the canonical name;
            # keep it independent and put newly recovered functions beside it.
            if len(marker_addresses(unsuffixed[0])) > 1:
                target = module.with_name(f"{module.stem}_functions.c")
                units = suffixed
            else:
                target = module
                units = paths
        else:
            target = module
            units = suffixed
        result[module] = (target, sorted(units, key=lambda path: marker_addresses(path)[0]))
    return result


def check() -> int:
    errors: list[str] = []
    for source in source_files():
        if ADDRESS_SUFFIX.search(source.name):
            errors.append(f"unconsolidated source: {source.relative_to(REPO)}")
    for path in sorted(SRC.rglob("*.c")):
        if is_generated(path):
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        guards = list(GUARD.finditer(text))
        if not guards:
            continue
        expected: list[int] = []
        for guard in guards:
            end = next(
                (cursor for cursor in range(guard.end(), len(text))
                 if re.match(r"^\s*#endif\b", text[cursor:])),
                None,
            )
            if end is None:
                errors.append(f"unterminated guard: {path.relative_to(REPO)}")
                continue
            body = text[guard.end():end]
            addresses = [int(match.group("address"), 16) for match in MARKER.finditer(body)]
            address = int(guard.group("address"), 16)
            if not addresses or addresses[0] != address:
                errors.append(
                    f"guard/marker mismatch: {path.relative_to(REPO)} "
                    f"guard={address:08x} markers={addresses}"
                )
            expected.extend(addresses)
        if expected != marker_addresses(path):
            errors.append(
                f"guard/marker order mismatch: {path.relative_to(REPO)}"
            )
    if errors:
        for error in errors:
            print(error, file=sys.stderr)
        return 1
    return 0


def write_groups() -> int:
    for _module, (target, units) in plan().items():
        if target in units:
            # Read all source text before replacing the target itself.
            rendered = render_group(target, units)
        else:
            rendered = render_group(target, units)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(rendered, encoding="utf-8")
        for source in units:
            if source != target and source.exists():
                source.unlink()
    return check()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--check", action="store_true", help="validate grouped source units")
    args = parser.parse_args()
    return check() if args.check else write_groups()


if __name__ == "__main__":
    raise SystemExit(main())
