#!/usr/bin/env python3
"""Remove the permuter seeds installed by tools/archive_to_guard.py --source generated.

A sweep needs a starting body, so seeds are installed tree-wide as inert
`#ifdef NON_MATCHING` blocks. They are scaffolding and must never be committed.
Reverting the whole tree would also throw away the lanes' real work, which is
not confined to the function bodies -- a closure often also fixes a callee
prototype or a file-scope declaration elsewhere in the unit.

So this removes only the seeds, identified by the exact note
`archive_to_guard` writes above each one, and leaves every other edit alone.
Each seed collapses back to the bare `INCLUDE_ASM` it replaced:

    /* measured: unmodified m2c candidate ... */      <- dropped
    // FUN_XXXXXXXX NONMATCHING                       <- suffix dropped
    #ifdef NON_MATCHING                               <- dropped
    <seed body>                                       <- dropped
    #else                                             <- dropped
    INCLUDE_ASM("asm/nonmatchings/unit", func_x);     <- kept
    #endif                                            <- dropped

A seed whose marker no longer carries the note is left untouched: that means a
lane adopted it, and its body is now real work rather than scaffolding.

    python tools/strip_seed_guards.py [--dry-run]
"""
import argparse
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
NOTE = ("/* measured: unmodified m2c candidate from src/generated,"
        " installed as a permuter seed; not a verified body. */")


def strip(lines: list[str]) -> tuple[list[str], int]:
    out: list[str] = []
    i = 0
    removed = 0
    while i < len(lines):
        if lines[i].strip() != NOTE:
            out.append(lines[i])
            i += 1
            continue
        # note, marker, #ifdef, body..., #else, INCLUDE_ASM, #endif
        marker = i + 1
        if marker >= len(lines) or not lines[marker].lstrip().startswith("// FUN_"):
            out.append(lines[i])
            i += 1
            continue
        ifdef = marker + 1
        if ifdef >= len(lines) or lines[ifdef].strip() != "#ifdef NON_MATCHING":
            out.append(lines[i])
            i += 1
            continue
        try:
            els = next(j for j in range(ifdef, len(lines))
                       if lines[j].strip() == "#else")
            end = next(j for j in range(els, len(lines))
                       if lines[j].strip() == "#endif")
        except StopIteration:
            out.append(lines[i])
            i += 1
            continue
        out.append(lines[marker].replace(" NONMATCHING", "").rstrip())
        out.extend(lines[els + 1:end])
        removed += 1
        i = end + 1
    return out, removed


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    total, files = 0, 0
    for src in sorted((REPO / "src").rglob("*.c")):
        raw = src.read_bytes()
        if NOTE.encode() not in raw:
            continue
        lines = raw.decode("utf-8", errors="replace").splitlines()
        new, removed = strip(lines)
        if not removed:
            continue
        total += removed
        files += 1
        if not args.dry_run:
            eol = "\r\n" if b"\r\n" in raw else "\n"
            # Preserve whether the file ended with a newline. Unconditionally
            # appending one rewrites the last line of every file that did not,
            # which shows up as a spurious one-line diff in dozens of units.
            tail = eol if raw.endswith((b"\n", b"\r\n")) else ""
            src.write_bytes((eol.join(new) + tail).encode("utf-8"))
    print("%s %d seed(s) across %d file(s)"
          % ("would remove" if args.dry_run else "removed", total, files))
    return 0


if __name__ == "__main__":
    sys.exit(main())
