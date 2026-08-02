#!/usr/bin/env python3
"""Restore the INCLUDE_ASM fallback for every MISMATCH function in a file.

A MISMATCH is worse than an untouched fallback: the file claims to implement the
function but compiles to different bytes, so the build silently stops being
byte-exact. After a large matching wave — especially one where agents are
interrupted mid-edit — the fastest way back to a trustworthy tree is to keep
every MATCH and put the rest back.

This does exactly that, and nothing else:

    python tools/revert_mismatches.py src/foo.c            # show what it would do
    python tools/revert_mismatches.py src/foo.c --apply

The asm unit name is read from the file's surviving INCLUDE_ASM lines rather
than guessed from the path, because several files were merged from translation
units whose unit name does not match their filename.

Functions reported COMPILE_ERROR are deliberately NOT reverted: a compile error
is usually one bad line breaking a whole file of otherwise good matches, and
blindly reverting would throw those away. Fix the compile error first, then run
this.
"""

from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
INCLUDE_ASM_RE = re.compile(r'INCLUDE_ASM\("([^"]+)",\s*([A-Za-z_][A-Za-z0-9_]*)\)')
MARKER_RE = re.compile(r"^//\s*(FUN_[0-9A-Fa-f]{8})\b.*$", re.MULTILINE)


def verify(path: Path) -> list[dict]:
    """Per-function rows for one file, via verify.py's JSON report."""
    with tempfile.TemporaryDirectory() as tmp:
        report = Path(tmp) / "r.json"
        subprocess.run(
            [sys.executable, str(REPO / "tools" / "verify.py"), str(path),
             "--json", str(report)],
            capture_output=True, text=True, cwd=REPO,
        )
        if not report.is_file():
            return []
        return json.loads(report.read_text(encoding="utf-8"))["results"]


def asm_unit(text: str) -> str | None:
    """The unit string this file's own INCLUDE_ASM lines already use."""
    units = INCLUDE_ASM_RE.findall(text)
    if not units:
        return None
    # Every fallback in a file shares one unit; take the most common anyway.
    counts: dict[str, int] = {}
    for unit, _ in units:
        counts[unit] = counts.get(unit, 0) + 1
    return max(counts, key=counts.get)


def unit_from_asm_tree(symbol: str, source: Path) -> str | None:
    """Find the unit owning `symbol` by looking for its extracted .s file.

    A file whose fallbacks were all converted has no INCLUDE_ASM line left to
    copy a unit name from, so fall back to the asm tree, which is the same
    source the INCLUDE_ASM path refers to.

    A symbol can appear under more than one unit — frFont and frFontEx both
    carry the frFontEx symbols, because the extractor sliced overlapping
    windows. Prefer the unit named after this source file; only give up when
    that does not disambiguate, since guessing wrong would point INCLUDE_ASM at
    another translation unit's bytes.
    """
    root = REPO / "asm" / "nonmatchings"
    hits = [d.name for d in root.iterdir()
            if d.is_dir() and (d / f"{symbol}.s").is_file()]
    if len(hits) == 1:
        return f"asm/nonmatchings/{hits[0]}"
    stem = source.stem
    if stem in hits:
        return f"asm/nonmatchings/{stem}"
    return None


def region_after_marker(text: str, address: str) -> tuple[int, int] | None:
    """Slice owned by `address`: after its marker line, up to the next marker."""
    marks = [(m.start(), m.end(), m.group(1).upper()) for m in MARKER_RE.finditer(text)]
    for index, (_start, end, name) in enumerate(marks):
        if name != address.upper():
            continue
        body = end + 1
        stop = marks[index + 1][0] if index + 1 < len(marks) else len(text)
        return body, stop
    return None


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("files", nargs="+")
    parser.add_argument("--apply", action="store_true", help="write the changes")
    args = parser.parse_args()

    total = 0
    for name in args.files:
        path = Path(name)
        rows = verify(path)
        if not rows:
            print(f"{path}: could not verify (compile error?) — skipping")
            continue
        broken = [r for r in rows if r["status"] == "MISMATCH"]
        errors = [r for r in rows if r["status"] == "COMPILE_ERROR"]
        if errors:
            print(f"{path}: {len(errors)} COMPILE_ERROR — fix the compile error first, "
                  "not reverting")
            continue
        if not broken:
            print(f"{path}: already clean")
            continue

        text = path.read_text(encoding="utf-8")
        unit = asm_unit(text)
        if unit is None and broken:
            unit = unit_from_asm_tree(broken[0]["name"], path)
        if unit is None:
            print(f"{path}: cannot determine the asm unit name — skipping")
            continue

        # Replace from the bottom up so earlier offsets stay valid.
        edits = []
        for row in broken:
            marker = "FUN_" + f"{int(row['addr'], 16):08X}"
            span = region_after_marker(text, marker)
            if span is None:
                print(f"  {marker}: no marker found — skipping")
                continue
            edits.append((span, row["name"], marker))
        edits.sort(key=lambda e: e[0][0], reverse=True)

        for (start, stop), symbol, marker in edits:
            replacement = f'INCLUDE_ASM("{unit}", {symbol});\n\n'
            print(f"  {marker} -> INCLUDE_ASM  ({symbol})")
            text = text[:start] + replacement + text[stop:]
            total += 1

        if args.apply:
            # Byte-level write: text mode would rewrite every newline on Windows.
            with open(path, "wb") as handle:
                handle.write(text.encode("utf-8"))
            print(f"{path}: reverted {len(edits)}")
        else:
            print(f"{path}: would revert {len(edits)} (use --apply)")

    print(f"\n{'reverted' if args.apply else 'would revert'} {total} function(s)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
