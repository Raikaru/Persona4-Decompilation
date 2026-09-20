#!/usr/bin/env python3
"""Name what a short guarded body is MISSING, by opcode and by address.

A floor whose object is materially shorter than retail is missing code, not
mistuned, and spelling work on it is wasted: `func_00131a00` absorbed a full
session of spelling for -4 edits, and then a single absent region - retail's
second `0x20` flag test at 0x00132F5C, one `andi 0x20` against retail's two -
was worth 4431 -> 1833.

So this reports, per floor:

  * the instruction deficit and where it sits against the 3% band;
  * the opcode histogram delta, retail minus object, worst first - which is
    what named the missing `andi` above;
  * the longest retail-only runs in the alignment, with their retail
    addresses, so the region can be read straight out of the disassembly.

Usage: rows of `<file> <function>` on stdin, as gate_audit.py emits them.
"""
from __future__ import annotations

import re
import subprocess
import sys
import tempfile
from collections import Counter
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))

HUNK = re.compile(r"^(replace|insert|delete)\s+retail\[(\d+):(\d+)\] object\[(\d+):(\d+)\]")
HEAD = re.compile(r"@ (0x[0-9a-fA-F]+)\s+retail (\d+) instrs\s+object (\d+) instrs")


def mnemonic(line: str) -> str:
    text = line.strip()
    return text.split()[0] if text else ""


def align(rel: str, function: str):
    """Return (address, retail count, object count, hunks) for one floor."""
    scratch = Path(tempfile.gettempdir()) / f"deficit_{function}.c"
    subprocess.run([sys.executable, "-E", "-s", "tools/measure_guarded.py", rel, function,
                    "--save-candidate", str(scratch)],
                   cwd=REPO, capture_output=True, timeout=1800)
    if not scratch.is_file():
        return None
    out = subprocess.run([sys.executable, "-E", "-s", "tools/fnalign.py", rel, function,
                          "--candidate", str(scratch)],
                         cwd=REPO, capture_output=True, text=True, timeout=1800).stdout
    head = HEAD.search(out)
    if not head:
        return None
    hunks, kind, retail, obj, span = [], None, [], [], None
    for line in out.split("\n"):
        m = HUNK.match(line)
        if m:
            if kind:
                hunks.append((kind, span, retail, obj))
            kind = m.group(1)
            span = (int(m.group(2)), int(m.group(3)))
            retail, obj = [], []
            continue
        if line.startswith("   retail  "):
            retail.append(line[11:])
        elif line.startswith("   object  "):
            obj.append(line[11:])
    if kind:
        hunks.append((kind, span, retail, obj))
    return int(head.group(1), 16), int(head.group(2)), int(head.group(3)), hunks


def report(rel: str, function: str) -> None:
    got = align(rel, function)
    if got is None:
        print(f"{function}: could not measure", flush=True)
        return
    address, retail_n, object_n, hunks = got
    deficit = retail_n - object_n
    band = "INSIDE" if abs(object_n - retail_n) <= retail_n * 0.03 else "OUTSIDE"
    pct = (object_n - retail_n) / retail_n * 100 if retail_n else 0.0
    print(f"\n{function} @ {address:#010x}  retail {retail_n}  object {object_n}  "
          f"({pct:+.1f}%, {band})  deficit {deficit}", flush=True)
    if deficit <= 0:
        print("  object is not short; opcode deficit is not the lever here", flush=True)

    have, want = Counter(), Counter()
    for _, _, retail_lines, object_lines in hunks:
        want.update(mnemonic(x) for x in retail_lines)
        have.update(mnemonic(x) for x in object_lines)
    delta = [(want[op] - have[op], op) for op in set(want) | set(have)
             if want[op] - have[op] > 0]
    delta.sort(reverse=True)
    if delta:
        top = "  ".join(f"{op} +{n}" for n, op in delta[:8])
        print(f"  retail has more: {top}", flush=True)

    # A long retail-only run is not automatically missing code.  On
    # func_002f0f00 the three biggest runs were alignment CROSSES - an object
    # lump of 475 paired against a single retail instruction, and retail runs
    # of 201 and 83 paired against one or two object instructions - and the
    # fix was raising local similarity so the aligner could re-sync, not
    # writing anything.  One reload line unslid two of them and was worth 836
    # edits.  So report the object side of each run: a comparable lump nearby
    # means CROSS, nothing nearby means the code really is ABSENT.
    object_len = [len(object_lines) for _, _, _, object_lines in hunks]
    runs = []
    for index, (kind, span, retail_lines, object_lines) in enumerate(hunks):
        if kind == "delete" or (kind == "replace" and
                                len(retail_lines) > len(object_lines) + 2):
            # Judge locally: the object lump that "ate" the run is in this
            # hunk or one beside it.  A global maximum would call every run
            # in a function a CROSS as soon as one big object hunk exists
            # anywhere in it.
            neighbourhood = max(object_len[max(0, index - 1):index + 2])
            runs.append((len(retail_lines), span, len(object_lines), neighbourhood))
    for length, span, paired, neighbourhood in sorted(runs)[-3:][::-1]:
        start = address + span[0] * 4
        # You cannot be missing more instructions than you are short.  A run
        # longer than the whole deficit is code the object HAS and the
        # aligner could not pair - func_001b2380 is 24 short yet carries a
        # 591-instruction run.  Only a run that fits inside the deficit can
        # actually be absent.
        verdict = "CROSS" if length > max(deficit, 0) else "ABSENT"
        print(f"  retail-only run of {length} at {start:#010x}-"
              f"{address + span[1] * 4:#010x}  paired against {paired} object "
              f"instrs, {neighbourhood} nearby -> likely {verdict}", flush=True)


def main() -> None:
    for raw in sys.stdin:
        raw = raw.strip()
        if not raw:
            continue
        parts = raw.split()
        report(parts[-2], parts[-1])


if __name__ == "__main__":
    main()
