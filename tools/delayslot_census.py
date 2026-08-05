#!/usr/bin/env python3
"""Census unmatched functions whose retail fills the `jr $ra` delay slot.

b210 at -O2 leaves the return delay slot empty. Retail often does not, and the
resulting `jr $ra` / instruction pair is a whole-instruction shift that no
amount of register tuning fixes - so a function in this family reads as an
unexplained 2-6 word residual with correct-looking logic.

Two things make it actionable:

  * `#pragma schedule on` is what lets b210 fill the slot at all.
  * b210 only ever sinks a STORE into the slot. Across 3387 matched
    first-party functions the slot holds a store in every case bar the
    two-instruction `return K;` shape - never the arithmetic that computes a
    return value. So a retail slot holding an `andi`/`addu`/`mult` that feeds
    $v0 is not reachable from b210 and points at another toolchain instead.
  * A store sinks into the slot only while the value it needs is free early,
    which usually means the pointer being stored through lives in $v0 - i.e.
    the function returns it and the caller discards it. Adding that return is
    what closed func_0041f2b8.

Usage:
  python tools/delayslot_census.py build/verify.json
  python tools/delayslot_census.py build/verify.json --matched   # the precedent set
"""
import collections
import json
import struct
import sys

sys.path.insert(0, 'tools')
import verify
from verify import RetailElf, load_config

JR_RA = 0x03E00008
SW, SH, SD, SQ = 43, 41, 63, 57
STORE_OPS = (SW, SH, SD, SQ, 40, 42, 56, 62)


def slot_after_jr(words):
    """The instruction in the `jr $ra` delay slot, or None if empty/absent.

    Stack teardown (`addiu $sp,$sp,K`) does not count: b210 emits that itself
    for any framed function, so it is not evidence of scheduling.
    """
    for i, w in enumerate(words):
        if w == JR_RA and i + 1 < len(words):
            nxt = words[i + 1]
            if nxt == 0 or (nxt >> 16) == 0x27BD:
                return None
            return nxt
    return None


def words_of(data):
    out = [struct.unpack('<I', data[i:i + 4])[0] for i in range(0, len(data) - 3, 4)]
    while out and out[-1] == 0:
        out.pop()
    return out


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    want = 'MATCH' if '--matched' in sys.argv else 'ASM'
    cfg = load_config()
    sizes = json.loads(open('tools/slus21782_functions.json').read())
    target = json.loads(open('config/target.json').read())
    retail = RetailElf(cfg['retail_elf'], target, sizes['sha1'])
    report = json.loads(open(args[0]).read())

    rows = []
    for r in report['results']:
        if r['status'] != want or verify.is_third_party(r['file']):
            continue
        if not r['name'].startswith('func_'):
            continue
        try:
            a = int(r['name'][len('func_'):], 16)
        except ValueError:
            continue
        w = sizes['windows'].get(f'{a:08x}')
        if not w or w < 8:
            continue
        try:
            ws = words_of(retail.bytes_at(a, w))
        except Exception:
            continue
        slot = slot_after_jr(ws)
        if slot is None:
            continue
        rows.append({'addr': f'{a:08x}', 'file': r['file'], 'words': len(ws),
                     'slot': slot, 'op': slot >> 26,
                     'store': (slot >> 26) in STORE_OPS})

    rows.sort(key=lambda r: (not r['store'], r['words']))
    store = [r for r in rows if r['store']]
    print(f'{want} first-party functions with a filled jr $ra delay slot: {len(rows)}')
    print(f'  slot holds a store (b210 can reach this):      {len(store)}')
    print(f'  slot holds other work (no precedent in b210):  {len(rows) - len(store)}')
    hist = collections.Counter(r['op'] for r in rows)
    print('  slot opcode histogram:', dict(sorted(hist.items(), key=lambda kv: -kv[1])))
    for r in rows[:30]:
        kind = 'store' if r['store'] else 'other'
        print(f"  {r['addr']} {r['words']:4}w op={r['op']:2} {kind:5}  "
              f"{r['file'].split(chr(92))[-1]}")
    out = 'build/delayslot_matched.json' if want == 'MATCH' else 'build/delayslot_asm.json'
    json.dump(rows, open(out, 'w'), indent=1)
    print(f'wrote {out}')


if __name__ == '__main__':
    main()
