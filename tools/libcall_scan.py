#!/usr/bin/env python3
"""Count MWCC runtime-helper calls in the object compiled from a guarded body.

The EE has no hardware doubles and no 64-bit float conversions, so MWCC calls
into its runtime for them.  A surplus of such calls OFTEN points to a width
or literal mistake, though correct C semantics can require one - a genuine
full-range s64-to-float conversion, or real double arithmetic:

    __fixsfdi   float -> s64     an `s64` temp that should be `s16`/`s32`
    __floatdisf s64 -> float     the same, in the other direction
    __adddf3 and friends         a bare `1.5` literal, which is a double

On `func_002db400` narrowing the `s64` temps removed 13 `__fixsfdi` calls and
took the floor from 1744 to 102 edits.  On `func_00235520` the census went
8 -> 0 and the object shortened by 24.

SCOPE, stated exactly, because an earlier version of this docstring claimed
more than the tool does.  This counts the OBJECT side only.  The retail side
is NOT machine-checked, and cannot be from the material in this repo:

  * `asm/nonmatchings/*.s` disassembles every callee as `jal func_XXXXXXXX`
    from its address, so a helper call there carries no helper name and a
    symbol scan of the asm would report zero for every function, always.
  * the retail image `orig/SLUS_217.82` exports no symbol table.  The linked
    `build/slus21782.elf` DOES carry 22309 symbols, but those names are
    project metadata rather than anything the retail bytes authenticate, and
    none of them is a conversion helper - so the absence proves nothing and
    there is still no address to compare a retail `jal` target against.

Resolving the addresses is not impossible, only unimplemented: the configured
`mwld-wrapper.sh` could link a probe that references each helper and the
resolved `jal` target read back, after which retail calls could be counted by
decoding `(word >> 26) == 3` and comparing targets.  Until that exists this
tool reports one side.

So a nonzero census means "this body calls a runtime helper", and explicitly
not "retail does not".  That second half has held on every floor examined so far - the helpers
disappear when a width is corrected, and the object moves toward retail when
they do - but it is an argument from evidence, not something this output
establishes.  Treat a hit as a strong lead to verify, not a proven defect.
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
        print(f"{function}  {total} helper calls in the OBJECT "
              f"(retail side not machine-checked): {detail}", flush=True)


if __name__ == "__main__":
    main()
