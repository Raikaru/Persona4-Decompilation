#!/usr/bin/env python3
"""Run pinned m2c on one function, supplying its jump tables from image.bin.

    m2c_with_jtbl.py OWNER FUNC_ADDR OUT.c [--stack-structs]

tools/m2c_decompile.py stops at the first `jr` whose table is not in the
input. This script copies the function's .s, appends a .rodata section with
every `jtbl_XXXXXXXX` it references (entries read from image.bin until one
points outside the function or at a non-label), and runs m2c on the result.
"""
from __future__ import annotations

import glob
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO / "tools"))
import m2c_decompile as M  # noqa: E402

IMAGE_VRAM = 0x00100000


def main() -> None:
    owner, addr, out = sys.argv[1], sys.argv[2].lower(), Path(sys.argv[3])
    stack_structs = "--stack-structs" in sys.argv
    func = "func_" + addr
    asm = Path(glob.glob(str(REPO / "asm" / "nonmatchings" / "*" / f"{func}.s"))[0])
    text = asm.read_text(errors="replace")
    labels = {int(m.group(1), 16) for m in re.finditer(r"^\s*\.L([0-9A-Fa-f]{8}):", text, re.M)}
    addrs = [int(m.group(1), 16) for m in re.finditer(r"/\*\s+[0-9A-F]+\s+([0-9A-F]{8})\s", text)]
    lo, hi = min(addrs), max(addrs) + 4
    image = (REPO / "image.bin").read_bytes()
    tables = sorted(set(re.findall(r"\bjtbl_([0-9A-Fa-f]{8})\b", text)))
    instr_addrs = set(addrs)
    rodata = []
    targets = set()
    for t in tables:
        base = int(t, 16)
        rodata.append(f"glabel jtbl_{t}")
        k = 0
        while True:
            off = base - IMAGE_VRAM + 4 * k
            if off + 4 > len(image):
                break
            value = struct.unpack_from("<I", image, off)[0]
            if not (lo <= value < hi) or value not in instr_addrs:
                break
            rodata.append(f".word .L{value:08X}")
            targets.add(value)
            k += 1
    missing = targets - labels
    if missing:
        lines = []
        for line in text.split("\n"):
            m = re.search(r"/\*\s+[0-9A-F]+\s+([0-9A-F]{8})\s", line)
            if m and int(m.group(1), 16) in missing:
                lines.append(f"  .L{int(m.group(1), 16):08X}:")
            lines.append(line)
        text = "\n".join(lines)
    work = REPO / "build" / "m2c"
    work.mkdir(parents=True, exist_ok=True)
    full = work / f"{func}.jt.s"
    full.write_text(".set noat\n.set noreorder\n.section .text\n" + text +
                    "\n.section .rodata\n" + "\n".join(rodata) + "\n")
    ctx = work / f"{func}.ctx.c"
    M.preprocess_context(Path(owner).resolve(), ctx, None)
    m2c = M.find_m2c(None)
    cmd = [sys.executable, str(m2c), "--target", "mipsee-mwcc-c", "--context", str(ctx),
           "--globals=used", "-f", func]
    if stack_structs:
        cmd.append("--stack-structs")
    if "--valid-syntax" in sys.argv:
        cmd.append("--valid-syntax")
    cmd.append(str(full))
    r = subprocess.run(cmd, cwd=REPO, capture_output=True, text=True)
    out.write_text(r.stdout)
    if r.returncode:
        sys.stderr.write(r.stdout[-2000:] + r.stderr[-2000:])
        raise SystemExit(r.returncode)
    print("wrote", out, "tables", len(tables))


if __name__ == "__main__":
    main()
