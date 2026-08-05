#!/usr/bin/env python3
"""Show the immediate/target differences between a matched twin and an ASM function.

The masked signature says the two functions have the same shape; this says exactly
which constants changed, which is the edit to make in the twin's C.
"""
import json
import struct
import subprocess
import sys

sys.path.insert(0, 'tools')
from verify import RetailElf, load_config

sizes = json.loads(open('tools/slus21782_functions.json').read())
cfg = load_config()
target_cfg = json.loads(open('config/target.json').read())
retail = RetailElf(cfg['retail_elf'], target_cfg, sizes['sha1'])


def words_of(addr_hex):
    a = int(addr_hex, 16)
    w = sizes['windows'][addr_hex]
    b = retail.bytes_at(a, w)
    out = [struct.unpack('<I', b[i:i + 4])[0] for i in range(0, len(b) - 3, 4)]
    while out and out[-1] == 0:
        out.pop()
    return a, out


def disasm(addr_hex):
    a, ws = words_of(addr_hex)
    import pathlib
    p = pathlib.Path(f'C:/tmp/td_{addr_hex}.bin')
    p.write_bytes(b''.join(struct.pack('<I', w) for w in ws))
    out = subprocess.run(['wsl', 'mipsel-linux-gnu-objdump', '-D', '-b', 'binary',
                          '-m', 'mips:5900', '-EL', f'--adjust-vma=0x{addr_hex}',
                          f'/mnt/c/tmp/td_{addr_hex}.bin'],
                         capture_output=True, text=True).stdout
    rows = []
    for line in out.splitlines():
        if ':\t' not in line:
            continue
        parts = line.split('\t')
        if len(parts) < 3:
            continue
        rows.append(' '.join(x.strip() for x in parts[2:]))
    return rows


def main():
    twin, asmf = sys.argv[1], sys.argv[2]
    _, tw = words_of(twin)
    _, aw = words_of(asmf)
    td, ad = disasm(twin), disasm(asmf)
    print(f'{"":4} {"twin " + twin:44} {"asm " + asmf}')
    n = 0
    for i, (a, b) in enumerate(zip(tw, aw)):
        if a == b:
            continue
        n += 1
        print(f'  {i * 4:4} {td[i] if i < len(td) else "":44} {ad[i] if i < len(ad) else ""}')
    print(f'\n{n} differing word(s) of {len(tw)}')


if __name__ == '__main__':
    main()
