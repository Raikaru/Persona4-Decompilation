#!/usr/bin/env python3
"""Try several source spellings of one function and report the diff each gives.

Matching a function is a search over source spellings that all mean the same
thing but compile differently.  Doing that by hand costs a verify round-trip
per idea and makes it tempting to stop at "close enough".  This runs the
candidates in one go and prints the reloc-masked differing-word count for each,
so the choice is measured rather than argued.

Each candidate is a file holding the replacement text for the function body
region.  The region is located by its `// FUN_XXXXXXXX` marker and runs to the
next marker (or EOF).  The original text is always restored, including when a
candidate fails to compile or the run is interrupted.

    python tools/probe_variants.py src/cmmMisc.c func_00246940 \
        --candidate a=/tmp/a.c --candidate b=/tmp/b.c

Exit status is 0 if at least one candidate reached zero differing words.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
MARKER_RE = re.compile(r"^//\s*(FUN_[0-9A-Fa-f]{8})\b", re.MULTILINE)


def region_for(text: str, address: str) -> tuple[int, int]:
    """Return the [start, end) slice of `text` owned by the marker `address`."""
    wanted = address.upper()
    marks = [(m.start(), m.group(1).upper()) for m in MARKER_RE.finditer(text)]
    for index, (start, name) in enumerate(marks):
        if name != wanted:
            continue
        # Body starts after the marker line, ends at the next marker or EOF.
        body = text.index("\n", start) + 1
        end = marks[index + 1][0] if index + 1 < len(marks) else len(text)
        return body, end
    raise SystemExit(f"no // {wanted} marker in the file")


def differing_words(source: Path, function: str) -> int | None:
    """Reloc-masked differing-word count, or None if it did not compile."""
    proc = subprocess.run(
        [sys.executable, str(REPO / "tools" / "fndiff.py"), str(source), function],
        capture_output=True,
        text=True,
        cwd=REPO,
    )
    match = re.search(r"differing words \(reloc-masked\):\s*(\d+)", proc.stdout)
    if match:
        return int(match.group(1))
    return None


def address_of(function: str) -> str:
    digits = re.search(r"([0-9A-Fa-f]{8})", function)
    if not digits:
        raise SystemExit(f"cannot derive an address from {function!r}")
    return "FUN_" + digits.group(1).upper()


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("file", help="C source file containing the function")
    parser.add_argument("function", help="object symbol, e.g. func_00246940")
    parser.add_argument(
        "--candidate",
        action="append",
        default=[],
        metavar="NAME=PATH",
        help="a replacement body to try; repeatable",
    )
    parser.add_argument("--marker", help="override the FUN_ marker to replace")
    parser.add_argument(
        "--keep",
        metavar="NAME",
        help="leave this candidate in the file instead of restoring",
    )
    args = parser.parse_args()

    source = Path(args.file)
    marker = args.marker or address_of(args.function)
    original = source.read_bytes()
    text = original.decode("utf-8")
    start, end = region_for(text, marker)

    candidates: list[tuple[str, str]] = [("baseline", text[start:end])]
    for spec in args.candidate:
        name, _, path = spec.partition("=")
        if not path:
            raise SystemExit(f"--candidate wants NAME=PATH, got {spec!r}")
        candidates.append((name, Path(path).read_text(encoding="utf-8")))

    results: list[tuple[str, int | None]] = []
    winner: str | None = None
    try:
        for name, body in candidates:
            # Byte-level write: Path.write_text would rewrite every newline.
            with open(source, "wb") as handle:
                handle.write((text[:start] + body + text[end:]).encode("utf-8"))
            score = differing_words(source, args.function)
            results.append((name, score))
            shown = "COMPILE ERROR" if score is None else f"{score:5d}"
            print(f"  {name:<18} {shown}", flush=True)
            if score == 0 and winner is None:
                winner = name
    finally:
        keep = args.keep or winner
        kept = next((b for n, b in candidates if n == keep), None) if keep else None
        with open(source, "wb") as handle:
            if kept is None:
                handle.write(original)
            else:
                handle.write((text[:start] + kept + text[end:]).encode("utf-8"))

    scored = [(n, s) for n, s in results if s is not None]
    if scored:
        best_name, best = min(scored, key=lambda row: row[1])
        print(f"\nbest: {best_name} ({best} differing words)")
    if winner:
        print(f"kept {winner} in {source} (MATCH)")
    elif args.keep:
        print(f"kept {args.keep} in {source} (still not matching)")
    else:
        print(f"restored {source} unchanged")
    return 0 if winner else 1


if __name__ == "__main__":
    raise SystemExit(main())
