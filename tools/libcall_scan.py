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
import sys
import tempfile
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

import fnalign
from measure_guarded import extract_guarded_body
from verify import load_config

HELPER = re.compile(r"__(?:fix|float|add|sub|mul|div|cmp|extend|trunc|neg|unord)\w*")
RELOC = re.compile(r"R_MIPS_\w+:(\S+)")


def helpers_in(rel: str, function: str) -> list[tuple[int, str]] | None:
    """Return [(object byte offset, helper name)] for the guarded body.

    The offset is what makes this usable.  Counting alone stalls the moment a
    body has more candidate sites than helper calls: y_fclShopDraw's
    `func_002be530` has about thirty float-to-s64 stores and eleven of the
    reverse, yet emits only three helpers, and narrowing all of them to find
    the three would have cost roughly 120 instructions and pushed the floor
    out of the band.  The relocation already knows where the call is, so say
    so.
    """
    source = REPO / rel
    text = source.read_text(errors="replace")
    marker = "FUN_" + function[-8:].upper()
    with tempfile.TemporaryDirectory() as scratch:
        candidate = Path(scratch) / f"{function}.c"
        try:
            candidate.write_text(extract_guarded_body(text, marker, function))
            _body, relocations = fnalign._object_for(source, function, candidate,
                                                     load_config())
        except BaseException:
            return None
    return sorted((int(r["offset"]), r["symbol"]) for r in relocations
                  if r.get("symbol") and HELPER.fullmatch(r["symbol"]))


def main() -> None:
    for raw in sys.stdin:
        raw = raw.strip()
        if not raw:
            continue
        rel, function = raw.split()[-2:]
        found = helpers_in(rel, function)
        if not found:
            continue
        sites = "  ".join(f"{name}@+{offset:#x}" for offset, name in found)
        print(f"{function}  {len(found)} helper calls in the OBJECT "
              f"(retail side not machine-checked): {sites}", flush=True)


if __name__ == "__main__":
    main()
