#!/usr/bin/env python3
"""Map first-party functions to their owner files and flag file collisions.

Two agents editing one file clobber each other even when they own different
functions in it, and a function address does not tell you its filename.  That
combination produced three wrong dispatches in one session - five agents on
`y_fclCombine.c`, two on `code1_0035.c`, two on `effPolygonWind.c` - each
caught only after the batch was already running.

Resolve ownership before dispatching, not after:

    python3 -E -s tools/owner_of.py func_004a3640 func_004a2310
    src/Graphics/Effect/effPolygonWind.c  func_004a2310 func_004a3640
    COLLISION: 1 file carries more than one requested function

Exit status is 1 when any file carries two or more of the requested
functions, so a dispatch script can simply refuse.
"""
from __future__ import annotations

import re
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]


def owner_files() -> dict[str, str]:
    """Return {function: owning source file} for every first-party marker."""
    owners: dict[str, str] = {}
    for path in sorted((REPO / "src").rglob("*.c")):
        if path.parent.name == "generated" or path.name.startswith("."):
            continue
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue
        for match in re.finditer(r"// FUN_([0-9A-Fa-f]{8})", text):
            owners[f"func_{match.group(1).lower()}"] = str(path.relative_to(REPO))
    return owners


def main() -> int:
    wanted = [name.lower() for name in sys.argv[1:]]
    if not wanted:
        print(__doc__.strip().split("\n\n")[0])
        print("\nusage: tools/owner_of.py func_00123456 [func_... ...]")
        return 2
    owners = owner_files()
    grouped: dict[str, list[str]] = defaultdict(list)
    missing = []
    for name in wanted:
        where = owners.get(name)
        if where is None:
            missing.append(name)
        else:
            grouped[where].append(name)
    for path in sorted(grouped):
        print(f"{path}  {' '.join(sorted(grouped[path]))}")
    for name in missing:
        print(f"UNKNOWN: {name} has no // FUN_ marker in a first-party source")
    clashes = sum(1 for names in grouped.values() if len(names) > 1)
    if clashes:
        print(f"COLLISION: {clashes} file(s) carry more than one requested function")
    return 1 if clashes or missing else 0


if __name__ == "__main__":
    raise SystemExit(main())
