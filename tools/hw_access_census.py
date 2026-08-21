#!/usr/bin/env python3
"""Which not-yet-decompiled functions genuinely touch hardware?

`volatile` is banned in this tree when it is used to steer the compiler, and
required when it guards a real device access. That distinction is only
decidable from the retail code, so this reads the retail bytes of every
first-party function still on `INCLUDE_ASM` and reports the ones that
materialise an address inside a hardware range.

The scan has to be segment-aware. EE code reaches MMIO through KSEG1, so a
timer register at physical 0x10000000 appears in the instruction stream as
`lui 0xB000` / `ori 0x1000` -- 0xB0001000. Masking 0x1FFFFFFF off any address
in 0x80000000-0xBFFFFFFF recovers the physical address; a scan that only
looked for literal 0x1000xxxx constants would miss essentially every real
device access in the game.

Two forms are recognised:

  * a constant pair, `lui rX,hi` followed by `ori`/`addiu rX,rX,lo`, which
    builds a device address in a register;
  * a load or store whose base register was last set by a bare `lui` into a
    hardware range, where the 16-bit displacement supplies the low half.

Usage:
    python -E -s tools/hw_access_census.py [--report build/verify_report.json]
                                           [--json build/hw_access.json]
"""

import argparse
import json
import os
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(REPO, "tools"))

from verify import RetailElf, load_config, is_third_party, is_vendor_address  # noqa: E402

# Physical ranges, named. These mirror decomp_lint.HARDWARE_RANGES, which is
# what actually decides whether a `volatile` is accepted or reported as H001.
RANGES = (
    (0x10000000, 0x10010000, "EE peripherals (timers, DMAC, GIF, VIF, IPU)"),
    (0x11000000, 0x11010000, "VU0/VU1 micro and data memory"),
    (0x12000000, 0x12002000, "GS privileged registers"),
    (0x1F800000, 0x1F810000, "scratchpad / misc"),
    (0x1FC00000, 0x20000000, "BIOS"),
    (0x70000000, 0x70004000, "scratchpad mirror"),
)

LOADS_STORES = {
    0x20: "lb", 0x21: "lh", 0x22: "lwl", 0x23: "lw", 0x24: "lbu", 0x25: "lhu",
    0x26: "lwr", 0x27: "lwu", 0x28: "sb", 0x29: "sh", 0x2A: "swl", 0x2B: "sw",
    0x2E: "swr", 0x37: "ld", 0x3F: "sd", 0x31: "lwc1", 0x39: "swc1",
    0x36: "lqc2", 0x3E: "sqc2", 0x1E: "lq", 0x1F: "sq",
}


# Stores read rt; loads overwrite it. The scan needs the distinction to know
# when a register's pending `lui` upper half is still valid.
STORES = {0x28, 0x29, 0x2A, 0x2B, 0x2E, 0x3F, 0x39, 0x3E, 0x1F}


def physical(addr):
    """Physical address behind a KSEG0/KSEG1 pointer, else the address."""
    if 0x80000000 <= addr <= 0xBFFFFFFF:
        return addr & 0x1FFFFFFF
    return addr


def classify(addr):
    phys = physical(addr)
    for lo, hi, name in RANGES:
        if lo <= phys < hi:
            return name, phys
    return None, phys


def scan(words, base_addr):
    """-> list of (offset, kind, address, region) for hardware touches."""
    upper = {}          # register -> value of its pending lui, shifted
    hits = []
    for i, w in enumerate(words):
        op = w >> 26
        rs = (w >> 21) & 31
        rt = (w >> 16) & 31
        imm = w & 0xFFFF
        simm = imm - 0x10000 if imm & 0x8000 else imm

        if op == 0x0F:                                   # lui
            upper[rt] = imm << 16
            continue

        if op in (0x0D, 0x09):                           # ori / addiu
            if upper.get(rs) is not None:
                full = (upper[rs] | imm) if op == 0x0D else (upper[rs] + simm)
                region, _ = classify(full)
                if region:
                    hits.append((i * 4, "address in register", full, region))
            # rt now holds a completed value, not a pending upper half.
            upper.pop(rt, None)
            continue

        if op in LOADS_STORES:
            if upper.get(rs) is not None:
                full = upper[rs] + simm
                region, _ = classify(full)
                if region:
                    hits.append((i * 4, LOADS_STORES[op], full, region))
            # A LOAD overwrites rt. Forgetting this is what made the scanner
            # claim `sq v1,0x0(v0)` targeted 0x10000000 in func_0039c730: an
            # earlier `lui v0,0x1000` fed an OR into a GIF tag word, then
            # `lw v0,-0x477c(gp)` reloaded v0 as a packet pointer, and the
            # stale upper half was still attributed to it.
            if op not in STORES:
                upper.pop(rt, None)
            continue

        # Anything else that writes a register invalidates its pending lui.
        if op == 0x00:                                   # SPECIAL: rd is target
            rd = (w >> 11) & 31
            upper.pop(rd, None)
        elif op in (0x08, 0x0A, 0x0B, 0x0C, 0x0E):
            upper.pop(rt, None)
    return hits


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", default="build/verify_report.json")
    ap.add_argument("--json", default="build/hw_access.json")
    args = ap.parse_args()

    cfg = load_config()
    target = json.load(open(os.path.join(REPO, "config", "target.json")))
    elf = RetailElf(cfg["retail_elf"], target, target["elf"]["sha1"])
    windows = json.load(open(os.path.join(REPO, "tools",
                                          "slus21782_functions.json")))["windows"]

    rows = json.load(open(os.path.join(REPO, args.report)))["results"]
    out = []
    for r in rows:
        if r["status"] != "ASM":
            continue
        if is_third_party(r["file"]) or is_vendor_address(r.get("addr")):
            continue
        addr = r["addr"]
        addr = int(str(addr), 16) if isinstance(addr, str) else addr
        size = windows.get("%08x" % addr)
        if not size:
            continue
        data = elf.bytes_at(addr, size)
        words = [int.from_bytes(data[i:i + 4], "little") for i in range(0, size, 4)]
        hits = scan(words, addr)
        if hits:
            out.append({"name": r["name"],
                        "file": r["file"].replace("\\", "/"),
                        "addr": "%08x" % addr,
                        "window": size,
                        "hits": [{"offset": o, "kind": k,
                                  "address": "%08X" % a, "region": g}
                                 for o, k, a, g in hits]})

    with open(os.path.join(REPO, args.json), "w") as f:
        json.dump(out, f, indent=1)

    print("first-party ASM functions touching hardware: %d  (%s)"
          % (len(out), args.json))
    by_region = {}
    for e in out:
        for h in e["hits"]:
            by_region.setdefault(h["region"], set()).add(e["name"])
    for region, names in sorted(by_region.items(), key=lambda kv: -len(kv[1])):
        print("  %-45s %d functions" % (region, len(names)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
