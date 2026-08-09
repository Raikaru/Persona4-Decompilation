#!/usr/bin/env python3
"""Give every canonical function a ``// FUN_<addr>`` marker.

``verify.py`` only scans functions that already carry a marker in a ``.c`` file,
so the progress denominator (4800 first-party of 5540 scanned) measures what has
been *promoted*, not the true size of the image. ``tools/slus21782_functions.json``
lists 13085 canonical functions; the rest are invisible to every progress and
gate tool.

This promotes them: it picks an owning translation unit for each unmarked
address, extracts the retail assembly into ``asm/nonmatchings/<group>/``, and
inserts a plain marker plus an ``INCLUDE_ASM`` fallback in ADDRESS ORDER.

Ownership rules, strongest evidence first:

1. ``interval`` -- the address lies strictly between two existing markers that
   live in the same file. That file already owns the surrounding retail range,
   so the function belongs to it. This is the only rule that can place a
   function into a hand-written unit.
2. ``generated`` -- ``src/generated/code1_XXXX.c`` carries a marker for the
   address. Splat grouped that unit by retail address prefix, so the matching
   ``src/promoted/code1_XXXX.c`` is the right home; it is created if absent.
3. ``prefix`` -- neither of the above. Fall back to ``src/promoted/code1_XXXX.c``
   named from the address's own prefix.

An ``INCLUDE_ASM`` fallback reproduces its window byte-for-byte by construction,
so promoting a function never disturbs a translation unit's link eligibility or
the bytes of the shipped image; it only makes the function visible to the tools.
"""
from __future__ import annotations

import argparse
import bisect
import json
import os
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
SRC = REPO / "src"
GENERATED = SRC / "generated"
PROMOTED = SRC / "promoted"
WINDOWS = REPO / "tools" / "slus21782_functions.json"
EXTRACT = REPO / "tools" / "extract_nonmatching_asm.py"

MARKER_RE = re.compile(r"\s*//\s*FUN_([0-9A-Fa-f]{8})\b")
# A marker's explanatory note sits directly above it and belongs to it, so a new
# function must be inserted above the whole block, never between note and marker.
NOTE_RE = re.compile(r"\s*(/\*|\*|//|$)")


def read(path: Path) -> str:
    return path.read_bytes().decode("utf-8", "replace")


def newline_of(text: str) -> str:
    """The file's dominant line ending. Sources are mixed LF and CRLF."""
    return "\r\n" if text.count("\r\n") * 2 >= text.count("\n") else "\n"


def scan_markers(skip_generated: bool = True) -> dict[int, Path]:
    """Every authoritative ``// FUN_`` marker in the tree -> its file."""
    found: dict[int, Path] = {}
    for path in sorted(SRC.rglob("*.c")):
        if skip_generated and GENERATED in path.parents:
            continue
        for line in read(path).split("\n"):
            match = MARKER_RE.match(line)
            if match:
                found[int(match.group(1), 16)] = path
    return found


def scan_generated() -> dict[int, str]:
    """Address -> generated unit stem (``code1_0020``)."""
    found: dict[int, str] = {}
    if not GENERATED.is_dir():
        return found
    for path in sorted(GENERATED.glob("*.c")):
        for line in read(path).split("\n"):
            match = MARKER_RE.match(line)
            if match:
                found.setdefault(int(match.group(1), 16), path.stem)
    return found


def load_windows() -> dict[int, int]:
    data = json.loads(WINDOWS.read_text(encoding="utf-8"))
    return {int(k, 16): v for k, v in data["windows"].items()}


def prefix_unit(addr: int) -> str:
    return f"code1_{addr >> 16:04x}"


def assign(markers: dict[int, Path], generated: dict[int, str],
           windows: dict[int, int]) -> dict[Path, list[tuple[int, str]]]:
    """Owning file -> [(addr, rule)], for every unmarked canonical function."""
    known = sorted(markers)
    plan: dict[Path, list[tuple[int, str]]] = defaultdict(list)
    for addr in sorted(windows):
        if addr in markers:
            continue
        index = bisect.bisect_left(known, addr)
        owner = None
        rule = ""
        if 0 < index < len(known):
            low, high = known[index - 1], known[index]
            if markers[low] == markers[high]:
                owner, rule = markers[low], "interval"
        if owner is None:
            stem = generated.get(addr) or prefix_unit(addr)
            owner, rule = PROMOTED / f"{stem}.c", "generated" if addr in generated else "prefix"
        plan[owner].append((addr, rule))
    return plan


def group_for(path: Path) -> str:
    """The ``asm/nonmatchings/<group>`` directory a file's fallbacks live in.

    Existing units are self-consistent: the group is the file stem. Trust an
    ``INCLUDE_ASM`` already in the file over the stem, because a few hand-written
    units were renamed after their fallbacks were extracted.
    """
    if path.is_file():
        match = re.search(r'INCLUDE_ASM\("asm/nonmatchings/([^"]+)"', read(path))
        if match:
            return match.group(1)
    return path.stem


def extract(addrs: list[int], group: str) -> None:
    """Write ``asm/nonmatchings/<group>/func_*.s`` for each address."""
    if not addrs:
        return
    cmd = [sys.executable, str(EXTRACT), "--group", group]
    cmd += [f"{a:08x}" for a in addrs]
    done = subprocess.run(cmd, cwd=REPO, capture_output=True, text=True)
    if done.returncode != 0:
        raise SystemExit(
            f"promote: extraction failed for {group}\n{done.stdout}\n{done.stderr}"
        )


def block_for(addr: int, group: str, nl: str) -> list[str]:
    return [
        f"// FUN_{addr:08X}",
        f'INCLUDE_ASM("asm/nonmatchings/{group}", func_{addr:08x});',
    ]


def note_start(lines: list[str], marker_index: int) -> int:
    """First line of the note attached to the marker at this index.

    A marker's note is load-bearing: ``nd_audit`` reads the ``nd N`` claim from
    the comment directly above a preserved body, so inserting between the two
    silently detaches the claim. Notes are separated from their marker by a
    blank line in places, and multi-line ones do not prefix continuation lines
    with ``*``, so the block has to be found by walking a ``*/`` back to its
    ``/*`` rather than by matching each line.
    """
    start = marker_index
    while start > 0:
        probe = start - 1
        while probe >= 0 and lines[probe].strip() == "":
            probe -= 1
        if probe < 0 or MARKER_RE.match(lines[probe]):
            break
        line = lines[probe]
        if "*/" in line and "/*" not in line:
            while probe >= 0 and "/*" not in lines[probe]:
                probe -= 1
            if probe < 0:
                break
        elif not NOTE_RE.match(line):
            break
        start = probe
    return start


def insert(path: Path, additions: list[int], group: str) -> int:
    """Insert markers and fallbacks in address order. Returns lines added."""
    if not path.is_file():
        header = (
            '#include "include_asm.h"\n'
            '#include "type.h"\n'
            "\n"
            "/* Promoted from the canonical function map: every function here is a\n"
            "   retail window with an INCLUDE_ASM fallback and no C body yet. */\n"
        )
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(header.encode("utf-8"))

    text = read(path)
    nl = newline_of(text)
    lines = [l.rstrip("\r") for l in text.replace("\r\n", "\n").split("\n")]

    existing = [(int(m.group(1), 16), i)
                for i, l in enumerate(lines) if (m := MARKER_RE.match(l))]
    added = 0
    for addr in sorted(additions, reverse=True):
        after = [i for a, i in existing if a > addr]
        at = note_start(lines, min(after)) if after else len(lines)
        block = block_for(addr, group, nl)
        if at > 0 and lines[at - 1].strip() != "":
            block = [""] + block
        lines[at:at] = block
        added += len(block)
        existing = [(a, i + len(block) if i >= at else i) for a, i in existing]
        existing.append((addr, at))

    path.write_bytes(nl.join(lines).encode("utf-8"))
    return added


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--file", help="only promote into this destination file")
    parser.add_argument("--limit", type=int, help="stop after N functions")
    parser.add_argument("--plan", action="store_true",
                        help="print the ownership plan and write nothing")
    args = parser.parse_args()

    markers = scan_markers()
    generated = scan_generated()
    windows = load_windows()
    plan = assign(markers, generated, windows)

    if args.file:
        want = (REPO / args.file).resolve()
        plan = {p: v for p, v in plan.items() if p.resolve() == want}
        if not plan:
            raise SystemExit(f"promote: no unmarked functions belong to {args.file}")

    total = sum(len(v) for v in plan.values())
    print(f"unmarked canonical functions: {total} across {len(plan)} file(s)")
    rules = defaultdict(int)
    for entries in plan.values():
        for _, rule in entries:
            rules[rule] += 1
    print("  by rule: " + ", ".join(f"{k}={v}" for k, v in sorted(rules.items())))

    if args.plan:
        for path in sorted(plan, key=lambda p: str(p)):
            entries = plan[path]
            print(f"  {path.relative_to(REPO)}: {len(entries)}")
        return

    budget = args.limit if args.limit else total
    promoted = 0
    for path in sorted(plan, key=lambda p: str(p)):
        if promoted >= budget:
            break
        entries = plan[path]
        addrs = [a for a, _ in entries][: budget - promoted]
        group = group_for(path)
        extract(addrs, group)
        insert(path, addrs, group)
        promoted += len(addrs)
        print(f"  {path.relative_to(REPO)}: +{len(addrs)} (group {group})")
    print(f"promoted {promoted} function(s)")


if __name__ == "__main__":
    main()
