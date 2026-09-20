#!/usr/bin/env python3
"""Find guarded bodies that pull in compiler helper calls retail does not make.

The EE has no hardware doubles and no 64-bit float conversions, so MWCC calls
into its runtime for them.  Every such call is a `jal` the retail function
does not have, plus the argument shuffling around it, and it is always caused
by a width or literal mistake in the reconstruction rather than by anything
retail did:

    __fixsfdi   float -> s64     an `s64` temp that should be `s16`/`s32`
    __floatdisf s64 -> float     the same, in the other direction
    __adddf3 and friends         a bare `1.5` literal, which is a double

On `func_002db400` narrowing the `s64` temps removed 13 `__fixsfdi` calls and
took the floor from 1744 to 102 edits.  On `func_00471370`, 86 unsuffixed
constants were pulling in about 155 double-emulation calls.

This compiles each guarded body and counts the helper calls in the OBJECT,
so it reports the defect directly rather than inferring it from a symptom.
"""
from __future__ import annotations

import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

HELPER = re.compile(r"__(?:fix|float|add|sub|mul|div|cmp|extend|trunc|neg|unord)\w*")
RELOC = re.compile(r"R_MIPS_\w+:(\S+)")


def helpers_in(rel: str, function: str) -> dict[str, int] | None:
    """Return {helper: count} for the object compiled from the guarded body."""
    # measure_guarded prints the object's relocations with their symbol names
    # (`R_MIPS_26:__fixsfdi`); fnalign's listing shows the call as `jal 0`
    # with the name stripped, so it cannot see helper calls at all.
    out = subprocess.run(
        [sys.executable, "-E", "-s", "tools/measure_guarded.py", rel, function],
        cwd=REPO, capture_output=True, text=True, timeout=1800).stdout
    if "GUARDED_SCORE" not in out:
        return None
    found: dict[str, int] = {}
    for name in RELOC.findall(out):
        if HELPER.fullmatch(name):
            found[name] = found.get(name, 0) + 1
    return found


def main() -> None:
    for raw in sys.stdin:
        raw = raw.strip()
        if not raw:
            continue
        rel, function = raw.split()[-2:]
        found = helpers_in(rel, function)
        if not found:
            continue
        total = sum(found.values())
        detail = "  ".join(f"{name} x{count}"
                           for name, count in sorted(found.items(), key=lambda kv: -kv[1]))
        print(f"{function}  {total} helper calls in the object: {detail}", flush=True)


if __name__ == "__main__":
    main()
