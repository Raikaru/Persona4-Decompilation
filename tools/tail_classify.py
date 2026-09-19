#!/usr/bin/env python3
"""Classify what is left in a near-MATCH floor: registers, schedule, or structure.

Handoff 7bf says the sub-50 tail is allocator noise and that effort belongs
above 100 edits - but "treat as banked unless a STRUCTURAL difference is
visible" is only actionable if something looks.  This does.

Each aligned hunk is one of:
  register   same mnemonic and same immediates, different register names
  schedule   the same instructions on both sides in a different order
  structure  different mnemonics, or an instruction on one side only
Only `structure` is worth a person's time.
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

REPO = Path("/home/raikaru/Projects/Persona 3 Decomp/source/Persona4-Decompilation")
sys.path.insert(0, str(REPO / "tools"))

HUNK = re.compile(r"^(replace|insert|delete|reloc-only)\s+retail\[(\d+):(\d+)\] object\[(\d+):(\d+)\]")
REG = re.compile(r"\$(?:[a-z]{1,2}\d{0,2}|\d{1,2})")


def shape(instruction):
    """Mnemonic plus immediates, with register names removed."""
    return REG.sub("$", instruction.strip())


def mnemonic(instruction):
    return instruction.strip().split()[0] if instruction.strip() else ""


def classify(retail, obj):
    if not retail or not obj:
        return "structure"
    if len(retail) == len(obj) and all(shape(a) == shape(b) for a, b in zip(retail, obj)):
        return "register"
    if sorted(x.strip() for x in retail) == sorted(x.strip() for x in obj):
        return "schedule"
    # Same mnemonics but a different shape means an operand differs - an
    # immediate, an offset, a count.  That is real work, not a rotation.
    return "structure"


def run(rel, function):
    cand = Path(tempfile.gettempdir()) / f"tailclass_{function}.c"
    cand.parent.mkdir(parents=True, exist_ok=True)
    subprocess.run([sys.executable, "-E", "-s", "tools/measure_guarded.py", rel, function,
                    "--save-candidate", str(cand)], cwd=REPO, capture_output=True, timeout=1800)
    if not cand.is_file():
        return None
    out = subprocess.run([sys.executable, "-E", "-s", "tools/fnalign.py", rel, function,
                          "--candidate", str(cand)],
                         cwd=REPO, capture_output=True, text=True, timeout=1800).stdout
    tally, hunks, retail, obj, kind = {}, 0, [], [], None
    for line in out.split("\n"):
        m = HUNK.match(line)
        if m:
            if kind is not None:
                verdict = classify(retail, obj)
                tally[verdict] = tally.get(verdict, 0) + 1
            kind, retail, obj = m.group(1), [], []
            hunks += 1
            continue
        if line.startswith("   retail  "):
            retail.append(line[11:])
        elif line.startswith("   object  "):
            obj.append(line[11:])
    if kind is not None:
        verdict = classify(retail, obj)
        tally[verdict] = tally.get(verdict, 0) + 1
    edits = re.search(r"edit instructions: (\d+)", out)
    return (int(edits.group(1)) if edits else -1), tally


def main() -> None:
    """Read `<score> <file> <function>` rows, as tools/gate_audit.py emits them."""
    for raw in sys.stdin:
        raw = raw.strip()
        if not raw:
            continue
        parts = raw.split()
        rel, function = parts[-2], parts[-1]
        got = run(rel, function)
        if got is None:
            print(f"{function}: no body", flush=True)
            continue
        edits, tally = got
        order = ["structure", "schedule", "register"]
        summary = "  ".join(f"{k} {tally[k]}" for k in order if k in tally)
        flag = "   <<< STRUCTURE" if tally.get("structure") else ""
        print(f"{function:16s} edits {edits:4d}   {summary}{flag}", flush=True)


if __name__ == "__main__":
    main()
