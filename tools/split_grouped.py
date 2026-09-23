#!/usr/bin/env python3
"""Split a grouped C source by an address-to-unit map without overwriting owners.

The map names bare .c files in one output directory. Cross-directory assignments
must be handled separately. Non-body declarations and pragmas remain in their
original order in every output; removing them changes MWCC code generation.
"""

from __future__ import annotations

import argparse
import json
import re
from collections import defaultdict
from pathlib import Path

from verify import sanitize_c_lines

MARKER = re.compile(r"^// FUN_([0-9A-Fa-f]{8})(?: NONMATCHING)?\s*$")


def entries(lines: list[str]) -> list[tuple[str, int, int]]:
    """Return (address, first line, last line exclusive) for every marker."""
    clean = sanitize_c_lines(lines)
    starts = [(match.group(1).lower(), i) for i, line in enumerate(lines)
              if (match := MARKER.match(line))]
    found = []
    for index, (addr, first) in enumerate(starts):
        limit = starts[index + 1][1] if index + 1 < len(starts) else len(lines)
        pos = first + 1
        while pos < limit and not clean[pos].strip():
            pos += 1
        if pos < limit and clean[pos].lstrip().startswith("#ifdef NON_MATCHING"):
            nesting = 1
            pos += 1
            while pos < limit and nesting:
                directive = clean[pos].lstrip()
                if directive.startswith(("#if ", "#if\t", "#ifdef ", "#ifndef ")):
                    nesting += 1
                elif directive.startswith("#endif"):
                    nesting -= 1
                pos += 1
            if nesting:
                raise ValueError(f"FUN_{addr.upper()}: unterminated NON_MATCHING guard")
            found.append((addr, first, pos))
            continue
        if pos < limit and "INCLUDE_ASM(" in clean[pos]:
            found.append((addr, first, pos + 1))
            continue
        depth = 0
        opened = False
        while pos < limit:
            for char in clean[pos]:
                if char == "{":
                    depth += 1
                    opened = True
                elif char == "}":
                    depth -= 1
            pos += 1
            if opened and depth == 0:
                break
        if not opened or depth != 0:
            raise ValueError(f"FUN_{addr.upper()}: body crosses next marker or is unbalanced")
        found.append((addr, first, pos))
    return found


def split(source: Path, attribution: dict[str, str], outdir: Path, dry_run: bool = False) -> dict[str, int]:
    """Split one source; reject *all* output before writing if an owner exists."""
    lines = source.read_text(encoding="utf-8").splitlines()
    spans = entries(lines)
    if not spans:
        raise ValueError("source has no // FUN_ markers; refusing to delete it")
    assigned: dict[str, list[tuple[int, int]]] = defaultdict(list)
    for addr, first, last in spans:
        assigned[attribution.get(addr, "")].append((first, last))
    unknown = set(attribution) - {addr for addr, _first, _last in spans}
    if unknown:
        raise ValueError(f"map contains {len(unknown)} addresses absent from source")
    owners = [unit for unit in assigned if unit]
    invalid = [unit for unit in owners if Path(unit).name != unit or not unit.endswith(".c")]
    if invalid:
        raise ValueError(f"owner must be a bare .c filename: {', '.join(sorted(invalid))}")
    conflicts = [outdir / unit for unit in owners if (outdir / unit).exists()]
    if conflicts:
        raise FileExistsError("refusing to overwrite existing owner files: "
                              + ", ".join(str(path) for path in sorted(conflicts)))
    counts = {unit or "<unattributed>": len(items) for unit, items in sorted(assigned.items())}
    if dry_run:
        return counts

    all_owned_lines = {i for _addr, first, last in spans for i in range(first, last)}

    def render(owned: list[tuple[int, int]], limit: int) -> str:
        keep = {i for first, last in owned for i in range(first, last)}
        return "\n".join(line for i, line in enumerate(lines[:limit])
                         if i not in all_owned_lines or i in keep) + "\n"

    outdir.mkdir(parents=True, exist_ok=True)
    for unit in sorted(owners):
        owned = assigned[unit]
        last = max(end for _start, end in owned)
        (outdir / unit).write_text(render(owned, last), encoding="utf-8")
    residual = assigned.get("", [])
    if residual:
        source.write_text(render(residual, len(lines)), encoding="utf-8")
    else:
        source.unlink()
    return counts


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("source", type=Path)
    parser.add_argument("map", type=Path, help="JSON address-to-bare-.c owner map")
    parser.add_argument("outdir", type=Path)
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()
    try:
        counts = split(args.source, json.loads(args.map.read_text(encoding="utf-8")),
                       args.outdir, args.dry_run)
    except (ValueError, OSError) as error:
        parser.error(str(error))
    for owner, count in counts.items():
        print(f"{owner}: {count}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
