#!/usr/bin/env python3
"""Generate a self-contained C context for decomp.me / the permuter.

Recursively inlines project (`#include "..."`) headers from include/ into one
file so a function can be pasted into decomp.me with the mwccps2 compiler.
System includes (`#include <...>`) are left as-is. For consolidated sources
(units guarded by `#if defined(P4_UNIT_<addr>)`), pass --unit <addr> to emit
only that unit's body with the guard stripped.

Usage:
  python tools/m2ctx.py src/Battle/btlTarget.c --unit 001EC630
  python tools/m2ctx.py src/Battle/btlTarget.c --unit 001EC630 --decompme
  python tools/m2ctx.py src/Battle/btlTarget.c -o ctx.c
"""
from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
INCLUDE_DIRS = [REPO / "include", REPO]

# decomp.me scratch settings for this project's compiler (MWCCPS2 3.0.1 b210,
# preset id verified against decomp.me's compilers.linux.yaml; flags mirror
# tools/verify_config.json's compile_flags). --decompme prints these verbatim.
DECOMPME_COMPILER_ID = "mwcps2-3.0.1b210-060308"
DECOMPME_PLATFORM = "ps2"
DECOMPME_FLAGS = "-O2 -Iinclude"

QUOTE_INC = re.compile(r'^\s*#\s*include\s*"([^"]+)"')
COND_START = re.compile(r"^\s*#\s*(?:if|ifdef|ifndef)\b")
COND_END = re.compile(r"^\s*#\s*endif\b")
UNIT_GUARD = re.compile(r"^\s*#\s*if\s+defined\(P4_UNIT_([0-9a-fA-F]{8})\)\s*$")


def resolve(inc: str, current: Path) -> Path | None:
    """Resolve a quoted include the way the compiler would: including file's
    directory first, then the -Iinclude search path, then the repo root."""
    for base in [current.parent, *INCLUDE_DIRS]:
        cand = (base / inc).resolve()
        if cand.is_file():
            return cand
    return None


def inline(path: Path, seen: set[Path], out: list[str]) -> None:
    """Append one header's lines to out, recursively inlining its quoted
    includes. `seen` prevents infinite recursion on circular includes."""
    rp = path.resolve()
    if rp in seen:
        return
    seen.add(rp)
    for line in path.read_text(errors="replace").splitlines():
        m = QUOTE_INC.match(line)
        if m:
            target = resolve(m.group(1), path)
            if target is not None:
                inline(target, seen, out)
                continue
        out.append(line)


def unit_regions(lines: list[str]) -> list[tuple[int, int, int]]:
    """Return (addr, start, end) for top-level `#if defined(P4_UNIT_...)`
    guard regions. start/end are the indices of the guard `#if` and its
    matching `#endif`; the unit body is lines[start + 1 : end]. Nested
    conditional directives are balanced with a depth counter."""
    regions: list[tuple[int, int, int]] = []
    pending: tuple[int, int] | None = None
    depth = 0
    for index, line in enumerate(lines):
        if pending is not None:
            if COND_START.match(line):
                depth += 1
            elif COND_END.match(line):
                depth -= 1
                if depth == 0:
                    regions.append((pending[0], pending[1], index))
                    pending = None
        else:
            guard = UNIT_GUARD.match(line)
            if guard is not None and depth == 0:
                pending = (int(guard.group(1), 16), index)
                depth = 1
            elif COND_START.match(line):
                depth += 1
            elif COND_END.match(line) and depth > 0:
                depth -= 1
    return regions


def emit(body: list[str], origin: Path, out: list[str], seen: set[Path]) -> None:
    """Emit body lines, replacing project quoted includes with their inlined
    content. Unresolvable quoted includes are passed through verbatim."""
    for line in body:
        m = QUOTE_INC.match(line)
        if m:
            target = resolve(m.group(1), origin)
            if target is not None:
                inline(target, seen, out)
                continue
        out.append(line)


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("c_file", type=Path, help="source file to build the context from")
    ap.add_argument("-u", "--unit", metavar="ADDR", default=None,
                    help="P4_UNIT address (hex, e.g. 001EC630) to select from a consolidated source")
    ap.add_argument("-o", "--output", type=Path, default=None,
                    help="write the context to PATH instead of stdout")
    ap.add_argument("--decompme", action="store_true",
                    help="also print the decomp.me scratch settings (compiler id, platform, flags)")
    args = ap.parse_args()

    cpath = args.c_file.resolve()
    if not cpath.is_file():
        ap.error(f"no such file: {args.c_file}")
    relative = cpath.relative_to(REPO)

    unit = None
    if args.unit is not None:
        try:
            unit = int(str(args.unit), 16)
        except ValueError:
            ap.error(f"invalid --unit address: {args.unit!r} (expected hex, e.g. 001EC630)")

    lines = cpath.read_text(errors="replace").splitlines()
    regions = unit_regions(lines)
    body = lines
    if unit is not None:
        for addr, start, end in regions:
            if addr == unit:
                body = lines[start + 1:end]
                break
        else:
            available = ", ".join(f"{addr:08X}" for addr, _, _ in regions) or "none"
            ap.error(f"no P4_UNIT_{unit:08X} guard in {relative} (available: {available})")

    out: list[str] = []
    emit(body, cpath, out, set())
    text = "\n".join(out) + "\n"

    if args.output is not None:
        args.output.write_text(text)
        print(f"wrote {args.output} ({len(out)} lines)")
    else:
        sys.stdout.write(text)

    if args.decompme:
        print(f"== decomp.me scratch settings ==\n"
              f"compiler id: {DECOMPME_COMPILER_ID}\n"
              f"platform: {DECOMPME_PLATFORM}\n"
              f"flags: {DECOMPME_FLAGS}")


if __name__ == "__main__":
    main()
