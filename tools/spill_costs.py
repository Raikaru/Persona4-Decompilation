"""Explain b210 spill scores: which references each virtual register's score counts.

    spill_costs.py SNAPSHOT [--vreg N ...] [--loop-weights]

SNAPSHOT is an ``after_colorgraph_assignment`` JSON from ``build/cap.py``
from the mwccps2-debugger. It reimplements
b210's spill-cost estimator (0x0055E5C0), which runs once per register class
after the interference graph is built and before colorgraph:

    for each basic block B, w = 1 when 0x006365CC is set, else B.loop_weight (+0x28)
      for each PCode P in B
        uses (operand attribute 0x1) of the class being coloured:
            score += 2w, or w when the node's +0x08 owner is set
        defs (operand attribute 0x2):
            score += w, or -w when the node's +0x08 owner is set or
            P's property flags have 0x8000

Our builds run with 0x006365CC set (the GPR model then reproduces every
captured score), so by default every counted reference weighs 1: a score is
uses + defs, minus 2 for each def that is excluded. --loop-weights models the
other mode and needs snapshots with block ``loop_weight_i32``.

The model is checked against every captured node score; the per-register
listing then shows which source-level reads and writes produced the score.
"""
from __future__ import annotations

import argparse
import json
import sys
from collections import defaultdict


def walk(graph: dict, need_weights: bool):
    blocks = {b["id"]: b for b in graph["blocks"]}
    pcodes = {p["id"]: p for p in graph["pcodes"]}
    heads = {b["id"] for b in graph["blocks"]} - {
        b["next"]["id"] for b in graph["blocks"] if b["next"].get("id")}
    block = blocks[min(heads)] if heads else None
    while block is not None:
        if need_weights and "loop_weight_i32" not in block:
            sys.exit("snapshot lacks block loop_weight_i32; recapture with the updated debugger")
        pcode = pcodes.get(block["pcode_head"].get("id")) if block["pcode_head"].get("id") else None
        while pcode is not None:
            yield block, pcode
            if pcode["id"] == block["pcode_tail"].get("id"):
                break
            nxt = pcode["next"].get("id")
            pcode = pcodes.get(nxt) if nxt else None
        nxt = block["next"].get("id")
        block = blocks.get(nxt) if nxt else None


def estimate(snapshot: dict, uniform: bool):
    ra = snapshot["register_allocation"]
    cls = ra["class"]["id"]
    owned = {n["array_index"] for n in ra["nodes"]
             if (n.get("backing") or {}).get("unique_aux_owner_raw")}
    score = defaultdict(int)
    refs = defaultdict(list)
    for block, pcode in walk(snapshot["graph"], not uniform):
        weight = 1 if uniform else block["loop_weight_i32"]
        flags = int(pcode["property_flags"], 16)
        mnemonic = ((pcode.get("opcode_metadata") or {}).get("mnemonic") or {}).get("text", "?")
        ops = [o for o in pcode["operands"]
               if o["kind"] == "register" and o["register_class"]["code"] == cls]
        for role, bit in (("use", 0x1), ("def", 0x2)):
            for op in ops:
                attrs = int(op["attributes_u16"], 16)
                if not attrs & bit:
                    continue
                reg = op["register_number_i16"]
                if role == "use":
                    delta = weight if (reg in owned or uniform) else 2 * weight
                else:
                    delta = -weight if (reg in owned or flags & 0x8000) else weight
                score[reg] += delta
                refs[reg].append((pcode["id"], mnemonic, role, weight, delta, block["id"]))
    return score, refs


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("snapshot")
    ap.add_argument("--vreg", type=int, nargs="*", default=[])
    ap.add_argument("--loop-weights", action="store_true",
                    help="model the loop-weighted mode (0x006365CC clear)")
    args = ap.parse_args()
    snapshot = json.load(open(args.snapshot, encoding="utf-8"))
    ra = snapshot["register_allocation"]
    score, refs = estimate(snapshot, not args.loop_weights)
    captured = {n["array_index"]: n["spill_score_i32"] for n in ra["nodes"]}
    physical = ra["class"]["physical_slots"]
    virtual = [i for i in captured if i >= physical]
    mismatched = [i for i in virtual if captured[i] != score.get(i, 0)]
    print(f"class {ra['class']['label']}: model agrees on {len(virtual) - len(mismatched)}/{len(virtual)} virtual scores")
    if mismatched:
        print("  disagree:", ", ".join(f"r{i} model {score.get(i, 0)} captured {captured[i]}"
                                       for i in mismatched[:20]))
    for reg in args.vreg:
        print(f"r{reg}: model {score.get(reg, 0)} captured {captured.get(reg)}")
        for pid, mnemonic, role, weight, delta, block in refs.get(reg, []):
            print(f"  {pid} {block} {mnemonic:10s} {role} w={weight} {delta:+d}")


if __name__ == "__main__":
    main()
