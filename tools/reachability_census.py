#!/usr/bin/env python3
"""Is the remaining work ordinary C, or is some of it unreachable from C?

The useful question is not "does this function contain an unusual
instruction" -- it is "has that instruction ever appeared in a function we
already match". A MATCHED function is proof by construction that MWCCPS2 b210
emits the instruction from plain C in this tree. So every class below is
counted twice, over matched and over unmatched first-party functions, and the
matched column is the control:

  * matched count > 0  -> reachable from C; its presence proves nothing.
  * matched count == 0 -> no C in this tree has ever produced it, so an
    unmatched function containing it is a candidate for genuinely not being
    plain C (inline asm in the original source, an SDK macro, or a compiler
    we are not using).

That is evidence, not proof: a class could be reachable and simply rare. Read
the ratio, and read `only_class` -- functions whose ONLY unusual content is
one never-matched class are the strongest candidates.

Usage:
    python -E -s tools/reachability_census.py [--report build/verify_report.json]
                                              [--json build/reachability.json]
"""

import argparse
import collections
import json
import os
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, "tools"))

from verify import RetailElf, load_config, is_third_party, is_vendor_address  # noqa: E402

SPECIAL = {
    0x0A: "movz/movn",
    0x0B: "movz/movn",
    0x0C: "syscall",
    0x0D: "break",
    0x0F: "sync",
}


def classify(word):
    """Name of the unusual class this instruction belongs to, else None."""
    op = word >> 26
    if op == 0x00:
        return SPECIAL.get(word & 0x3F)
    if op == 0x10:
        return "COP0 (mfc0/mtc0/tlb/eret)"
    if op == 0x12:
        return "COP2 (VU0 macro mode)"
    if op in (0x36, 0x3E):
        return "lqc2/sqc2 (VU0 quadword)"
    if op == 0x1C:
        return "MMI (EE multimedia)"
    if op == 0x2F:
        return "cache"
    if op == 0x33:
        return "pref"
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", default="build/verify_report.json")
    ap.add_argument("--json", default="build/reachability.json")
    args = ap.parse_args()

    cfg = load_config()
    target = json.load(open(os.path.join(REPO, "config", "target.json")))
    elf = RetailElf(cfg["retail_elf"], target, target["elf"]["sha1"])
    windows = json.load(open(os.path.join(REPO, "tools",
                                          "slus21782_functions.json")))["windows"]

    matched = collections.Counter()
    unmatched = collections.Counter()
    per_function = {}
    totals = collections.Counter()

    for r in json.load(open(os.path.join(REPO, args.report)))["results"]:
        status = r["status"]
        if status not in ("MATCH", "ASM"):
            continue
        if is_third_party(r["file"]) or is_vendor_address(r.get("addr")):
            continue
        addr = r["addr"]
        addr = int(str(addr), 16) if isinstance(addr, str) else addr
        size = windows.get("%08x" % addr)
        if not size:
            continue
        totals[status] += 1
        data = elf.bytes_at(addr, size)
        found = set()
        for i in range(0, size, 4):
            name = classify(int.from_bytes(data[i:i + 4], "little"))
            if name:
                found.add(name)
        if not found:
            continue
        (matched if status == "MATCH" else unmatched).update(found)
        if status == "ASM":
            per_function[r["name"]] = {"file": r["file"].replace("\\", "/"),
                                       "addr": "%08x" % addr,
                                       "window": size,
                                       "classes": sorted(found)}

    classes = sorted(set(matched) | set(unmatched))
    print("first-party scanned: %d MATCH, %d ASM\n"
          % (totals["MATCH"], totals["ASM"]))
    print("%-28s %9s %9s   %s" % ("class", "matched", "unmatched", "verdict"))
    unreachable = set()
    for c in classes:
        m, u = matched[c], unmatched[c]
        if m == 0:
            verdict = "NEVER matched -- suspect"
            unreachable.add(c)
        else:
            verdict = "reachable from C"
        print("%-28s %9d %9d   %s" % (c, m, u, verdict))

    # Functions whose only unusual content is a never-matched class.
    only = [n for n, e in per_function.items()
            if e["classes"] and all(c in unreachable for c in e["classes"])]
    print("\nunmatched functions containing a NEVER-matched class only: %d" % len(only))
    for n in sorted(only)[:20]:
        e = per_function[n]
        print("  %-16s win %-6d %-34s %s"
              % (n, e["window"], e["file"], ",".join(e["classes"])))

    with open(os.path.join(REPO, args.json), "w") as f:
        json.dump({"matched": dict(matched), "unmatched": dict(unmatched),
                   "never_matched_classes": sorted(unreachable),
                   "only_never_matched": sorted(only),
                   "per_function": per_function}, f, indent=1)
    return 0


if __name__ == "__main__":
    sys.exit(main())
