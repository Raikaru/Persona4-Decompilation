#!/usr/bin/env python3
"""Disassemble a retail function window with rabbitizer.

rabbitizer prints the Emotion Engine extensions as `.word 0x46...` tagged
INVALID, and inside those words it names float registers with INTEGER register
names, so `$a2` can silently mean `$f6`. To decode the FPU multiply-accumulate
ops (mula.S / madda.S / madd.S / msub.S / adda.S / suba.S) and the COP2/VU
macro-mode ops, decode the word with tools/eedis.py instead.

Needs user site-packages (rabbitizer), so it must run with PYTHONNOUSERSITE unset.

Usage:
    python -E -s tools/recon_dis.py 003e4030 [more addrs ...]
"""

import json
import os
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def windows():
    """addr -> retail window size, from the canonical function table."""
    with open(os.path.join(REPO, "tools", "slus21782_functions.json")) as f:
        return json.load(f)["windows"]


def dis_rabbitizer(addr, size):
    sys.path.insert(0, os.path.join(REPO, "tools"))
    import rabbitizer                      # needs user site-packages
    from verify import RetailElf, load_config

    cfg = load_config()
    target = json.load(open(os.path.join(REPO, "config", "target.json")))
    elf = RetailElf(cfg["retail_elf"], target, target["elf"]["sha1"])
    data = elf.bytes_at(addr, size)
    out = ["--- %08x size %d  [rabbitizer -- EE ops will show as INVALID]" % (addr, size)]
    for i in range(0, size, 4):
        word = int.from_bytes(data[i:i + 4], "little")
        out.append("%08x: %08x %s"
                   % (addr + i, word, rabbitizer.Instruction(word, addr + i).disassemble()))
    return "\n".join(out)


def main(argv):
    addrs = [a for a in argv if not a.startswith("-")]
    if not addrs:
        print(__doc__.strip())
        return 2

    win = windows()
    for spec in addrs:
        addr = int(spec, 16)
        size = win.get("%08x" % addr)
        if size is None:
            print("RECON_dis: no canonical window for %08x" % addr, file=sys.stderr)
            continue
        print(dis_rabbitizer(addr, size))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
