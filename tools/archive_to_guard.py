#!/usr/bin/env python3
"""Reinstall archived near-miss bodies as `#ifdef NON_MATCHING` guarded blocks.

Waves archive their best candidate body to `build/<LANE>_<addr>_body.c` and then
revert the source to bare `INCLUDE_ASM`. That is right for the tree -- an unproven
body must not ship -- but it hides the body from `tools/permute_sweep.py`, which
discovers its targets by scanning for `#ifdef NON_MATCHING`. The permuter needs a
starting body: from bare `INCLUDE_ASM` there is nothing to mutate.

This bridges the two. For every archive it finds the owning source file by marker
address, checks the function is currently bare `INCLUDE_ASM`, and rewrites it as

    // FUN_XXXXXXXX NONMATCHING
    #ifdef NON_MATCHING
    <archived body>
    #else
    INCLUDE_ASM("asm/nonmatchings/<unit>", func_xxxxxxxx);
    #endif

which is inert for the build (NON_MATCHING is never defined) and visible to the
sweep. When several archives target one address the largest is used, on the
assumption that the most developed body is the best permuter seed.

    python tools/archive_to_guard.py --list
    python tools/archive_to_guard.py --apply [--exclude src/a.c,src/b.c]
"""
import argparse
import re
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
ADDR = re.compile(r"([0-9a-fA-F]{8})")
MEASURED = re.compile(r"^\s*/\*.*\*/\s*$")


def archives() -> dict[str, Path]:
    """Best archive per address: the largest body wins."""
    by_addr: dict[str, list[Path]] = defaultdict(list)
    for path in sorted((REPO / "build").glob("*_body.c")):
        match = ADDR.search(path.name)
        if match:
            by_addr[match.group(1).lower()].append(path)
    return {a: max(v, key=lambda p: p.stat().st_size) for a, v in by_addr.items()}


def body_text(path: Path) -> str:
    """The archive minus its leading measurement comment lines."""
    lines = path.read_text(errors="replace").splitlines()
    start = 0
    for i, line in enumerate(lines):
        if line.strip() and not MEASURED.match(line):
            start = i
            break
    return "\n".join(lines[start:]).strip("\n")


def sources() -> dict[Path, list[str]]:
    """Every tracked source file's lines, read once.

    Lanes running concurrently create and delete temporary files inside src/,
    so a file that existed when the glob ran can be gone by the time it is
    read. Those are never real targets, so they are skipped rather than fatal.
    """
    out: dict[Path, list[str]] = {}
    for src in sorted((REPO / "src").rglob("*.c")):
        if src.name.startswith("tmp"):
            continue
        try:
            out[src] = src.read_text(encoding="utf-8", errors="replace").splitlines()
        except OSError:
            continue
    return out


def locate(addr: str, cache: dict[Path, list[str]]) -> tuple[Path, int, str] | None:
    """The file, marker line index and INCLUDE_ASM line for a bare function."""
    name = "func_" + addr
    marker = "// FUN_" + addr.upper()
    for src, lines in cache.items():
        for i, line in enumerate(lines):
            if line.strip().rstrip(" NONMATCHING").strip() != marker:
                continue
            # Only bare INCLUDE_ASM is convertible: a live body is already better
            # than any archive, and a guarded one is already a sweep target.
            for j in range(i + 1, min(len(lines), i + 3)):
                if lines[j].startswith("INCLUDE_ASM(") and name in lines[j]:
                    return src, i, lines[j]
                if lines[j].strip() and not lines[j].startswith("/*"):
                    break
    return None


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--exclude", default="", help="comma-separated files to skip")
    args = ap.parse_args()

    skip = {s.strip() for s in args.exclude.split(",") if s.strip()}
    found, edits = [], defaultdict(list)
    cache = sources()

    for addr, archive in archives().items():
        hit = locate(addr, cache)
        if hit is None:
            continue
        src, marker_line, include = hit
        rel = src.relative_to(REPO).as_posix()
        if rel in skip:
            continue
        found.append((rel, addr, archive.name))
        edits[src].append((marker_line, include, body_text(archive)))

    for rel, addr, name in sorted(found):
        print("%-44s func_%s  <- %s" % (rel, addr, name))
    print("%d archived body/bodies installable across %d file(s)"
          % (len(found), len(edits)))

    if not args.apply:
        return 0

    for src, items in edits.items():
        lines = src.read_text(encoding="utf-8", errors="replace").splitlines()
        # Descending so earlier line numbers stay valid as we splice.
        for marker_line, include, body in sorted(items, reverse=True):
            end = next(i for i in range(marker_line + 1, len(lines))
                       if lines[i] == include)
            block = [lines[marker_line].rstrip()]
            if not block[0].endswith("NONMATCHING"):
                block[0] += " NONMATCHING"
            block += ["#ifdef NON_MATCHING", body, "#else", include, "#endif"]
            lines[marker_line:end + 1] = block
        src.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print("installed %d body/bodies in %s"
              % (len(items), src.relative_to(REPO).as_posix()))
    return 0


if __name__ == "__main__":
    sys.exit(main())
