#!/usr/bin/env python3
"""Attribute functions to translation units using the retail binary's __FILE__ strings.

Assert macros pass `__FILE__`, so a function that materialises the address of the
string `"btlSupport.c"` almost certainly lives in `btlSupport.c`. That is the
strongest TU evidence available without source, and it is under-used: 73 of the
filenames present in the retail executable have no corresponding file in `src/`.

How it works:
  1. find every `<name>.c` / `.h` string in the ELF's loadable image, with its address
  2. walk every canonical function window looking for a `lui`/`addiu` pair (or
     `lui` + any load/store displacement) that materialises one of those addresses
  3. report filename -> functions, and flag the ones whose current file disagrees

`tu_audit.py` looks for the same idea but finds far less, because it only considers
strings it can already tie to a known group.

Usage:
  python tools/file_evidence.py                       # summary + disagreements
  python tools/file_evidence.py --json build/file_evidence.json
  python tools/file_evidence.py --name btlSupport.c   # just one TU
"""
from pathlib import Path
import argparse
import json
import re
import struct
import sys

TOOLS = Path(__file__).resolve().parent
REPO = TOOLS.parent
sys.path.insert(0, str(TOOLS))
import verify  # noqa: E402

NAME_RE = re.compile(rb'([A-Za-z_][A-Za-z0-9_]{2,63}\.(?:c|cpp|h|s))\x00')


def load_image():
    """Return (bytes, base_address) for the retail LOADABLE image.

    `RetailElf.bytes_at` only serves function windows, so building the image out of
    those misses `.rodata` entirely - and the filename strings live there. `segs`
    carries the real mapping: (vaddr, file offset, size).
    """
    cfg = verify.load_config()
    sizes = json.loads((TOOLS / "slus21782_functions.json").read_text())
    target = json.loads((REPO / "config" / "target.json").read_text())
    retail = verify.RetailElf(cfg["retail_elf"], target, sizes["sha1"])
    vaddr, off, size = retail.segs[0]
    return bytes(retail.data[off:off + size]), vaddr


def find_strings(image, base):
    """Map filename -> list of addresses where that string lives."""
    out = {}
    for m in NAME_RE.finditer(image):
        out.setdefault(m.group(1).decode("ascii"), []).append(base + m.start())
    return out


def materialised_addresses(words):
    """Every absolute address a lui/lo pair in `words` could form."""
    hi = {}
    found = set()
    for w in words:
        op = w >> 26
        if op == 0x0F:                                  # lui rt, imm
            hi[(w >> 16) & 0x1F] = (w & 0xFFFF) << 16
            continue
        rs = (w >> 21) & 0x1F
        if rs in hi:
            lo = w & 0xFFFF
            if lo >= 0x8000:
                lo -= 0x10000
            # addiu/ori and every load/store use the same displacement field
            if op in (0x09, 0x0D, 0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29,
                      0x2B, 0x37, 0x3F, 0x31, 0x39):
                found.add((hi[rs] + lo) & 0xFFFFFFFF)
    return found


def scan(only=None):
    cfg = verify.load_config()
    sizes = json.loads((TOOLS / "slus21782_functions.json").read_text())
    target = json.loads((REPO / "config" / "target.json").read_text())
    retail = verify.RetailElf(cfg["retail_elf"], target, sizes["sha1"])
    image, base = load_image()
    strings = find_strings(image, base)
    if only:
        strings = {k: v for k, v in strings.items() if k == only}
    addr_to_name = {a: n for n, addrs in strings.items() for a in addrs}
    hits = {}
    for a, w in sizes["windows"].items():
        if not w:
            continue
        addr = int(a, 16)
        try:
            data = retail.bytes_at(addr, w)
        except Exception:
            continue
        words = [struct.unpack("<I", data[i:i + 4])[0] for i in range(0, len(data) - 3, 4)]
        for target_addr in materialised_addresses(words):
            name = addr_to_name.get(target_addr)
            if name:
                hits.setdefault(name, []).append(a)
    return strings, hits


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--json", type=Path)
    ap.add_argument("--name")
    args = ap.parse_args()
    strings, hits = scan(args.name)
    report = verify  # keep the import meaningful for is_third_party below
    have = {p.name for p in (REPO / "src").rglob("*.c")}
    have |= {p.name for p in (REPO / "include").rglob("*.h")}

    print(f"{len(strings)} filename strings in the retail image; "
          f"{sum(1 for n in strings if n not in have)} have no file in the tree")
    print(f"{len(hits)} of them are referenced by at least one function\n")
    missing = [(n, v) for n, v in sorted(hits.items()) if n not in have]
    print(f"{len(missing)} referenced filenames with NO file in the tree:")
    for n, funcs in missing:
        print(f"  {n:34} {len(funcs):4} function(s)  e.g. {', '.join(funcs[:5])}")
    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps(
            {"strings": {k: [f"{a:08x}" for a in v] for k, v in strings.items()},
             "references": hits}, indent=2) + "\n")
        print(f"\nwrote {args.json}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
