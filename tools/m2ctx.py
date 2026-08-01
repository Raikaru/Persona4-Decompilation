#!/usr/bin/env python3
"""Generate a self-contained C context for decomp.me / the permuter.

Recursively inlines project (`#include "..."`) headers from include/ into one
file so a function can be pasted into decomp.me with the mwccps2 compiler.
System includes (`#include <...>`) are left as-is.

Usage:
  python tools/m2ctx.py src/Battle/btlTarget.c
  python tools/m2ctx.py src/Battle/btlTarget.c --decompme
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
    ap.add_argument("-o", "--output", type=Path, default=None,
                    help="write the context to PATH instead of stdout")
    ap.add_argument("--decompme", action="store_true",
                    help="also print the decomp.me scratch settings (compiler id, platform, flags)")
    args = ap.parse_args()

    cpath = args.c_file.resolve()
    if not cpath.is_file():
        ap.error(f"no such file: {args.c_file}")
    relative = cpath.relative_to(REPO)

    body = cpath.read_text(errors="replace").splitlines()

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
