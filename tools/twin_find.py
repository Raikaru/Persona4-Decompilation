#!/usr/bin/env python3
"""Find INCLUDE_ASM functions whose retail code is a structural twin of a match.

frFont func_00272b00 matched because func_00272b50, sitting right next to it, was
already matched and had the same shape - only the stored width and offset differed.
That is a general opportunity: if an unmatched function's instruction sequence is
identical to a matched one once immediates are masked out, the matched function's C
is a template and only the constants need changing.

Masking keeps opcode and register fields and drops the 16-bit immediate, so two
functions differing only in offsets, constants or call targets compare equal.

Because `jal` targets are masked too, ALWAYS check the callees with twin_diff before
adapting - two functions can share a shape and call different things.

Usage:
  python tools/twin_find.py build/verify.json
  python tools/twin_diff.py <twin-addr> <asm-addr>    # exactly which words differ
"""
import collections
import json
import struct
import sys

sys.path.insert(0, 'tools')
import verify
from verify import RetailElf, load_config


def mask(word):
    op = word >> 26
    if op in (2, 3):                       # j / jal: target is a relocation
        return op << 26
    if op == 0:                            # SPECIAL: keep rs/rt/rd/funct
        return word & 0xFFFFF83F
    if op in (4, 5, 6, 7, 20, 21, 22, 23, 1):   # branches: drop the displacement
        return word & 0xFFFF0000
    if 8 <= op <= 15 or 32 <= op <= 63:    # immediate / load / store
        return word & 0xFFFF0000
    return word


def signature(data):
    words = [struct.unpack('<I', data[i:i + 4])[0] for i in range(0, len(data) - 3, 4)]
    while words and words[-1] == 0:
        words.pop()
    return tuple(mask(w) for w in words), len(words)


def main():
    cfg = load_config()
    sizes = json.loads(open('tools/slus21782_functions.json').read())
    target = json.loads(open('config/target.json').read())
    retail = RetailElf(cfg['retail_elf'], target, sizes['sha1'])
    report = json.loads(open(sys.argv[1]).read())

    rows = []
    for r in report['results']:
        a = r.get('address') or r.get('addr')
        if isinstance(a, str):
            a = int(a, 16)
        if a is None and r['name'].startswith('func_'):
            a = int(r['name'][len('func_'):], 16)
        if a is None:
            continue
        rows.append((a, r['name'], r['status'], r['file']))

    sigs = collections.defaultdict(list)
    for a, name, status, f in rows:
        w = sizes['windows'].get(f'{a:08x}')
        if not w or w < 16:
            continue
        try:
            sig, n = signature(retail.bytes_at(a, w))
        except Exception:
            continue
        if n < 4:
            continue
        sigs[sig].append((a, name, status, f))

    hits = []
    for sig, members in sigs.items():
        matched = [m for m in members if m[2] == 'MATCH' and not verify.is_third_party(m[3])]
        asm = [m for m in members if m[2] == 'ASM' and not verify.is_third_party(m[3])]
        if matched and asm:
            for t in asm:
                hits.append({'asm': f'{t[0]:08x}', 'asm_name': t[1], 'asm_file': t[3],
                             'twin': f'{matched[0][0]:08x}', 'twin_name': matched[0][1],
                             'twin_file': matched[0][3], 'words': len(sig)})
    hits.sort(key=lambda h: -h['words'])
    print(f'ASM functions with a MATCHED structural twin: {len(hits)}')
    for h in hits[:40]:
        print(f"  {h['asm']} {h['asm_name']:20} <- {h['twin']} {h['twin_name']:20} "
              f"{h['words']:4} words  {h['twin_file'].split(chr(92))[-1]}")
    json.dump(hits, open('C:/tmp/p4_twins.json', 'w'), indent=1)


if __name__ == '__main__':
    main()
