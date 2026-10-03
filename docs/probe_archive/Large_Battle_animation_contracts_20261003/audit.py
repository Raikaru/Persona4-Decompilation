"""Reproduce scoped guarded compiles, preservation and retail call evidence.

Run from the checkout root with the licensed compiler/retail configured:
  python docs/probe_archive/Large_Battle_animation_contracts_20261003/audit.py OUTPUT
Only ignored OUTPUT and an automatically removed source scratch file are written.
"""
from pathlib import Path
import bisect
import hashlib
import json
import struct
import subprocess
import sys
ROOT = Path(__file__).resolve().parents[3]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import verify as V
import probe_variants as P
from measure_guarded import extract_guarded_body
from test_large_battle_animation_contracts import SITES
BASE = 'f6a8c57a1485a869dc5dbd1cc27a2c5184996f1c'
OWNER = ROOT / 'src/promoted/code1_001a.c'
TARGETS = ('func_001a59a0', 'func_001a7720')


def sha(data):
    return hashlib.sha256(data).hexdigest()


def enable(text, names):
    for name in names:
        marker = 'FUN_' + name[5:].upper()
        body = extract_guarded_body(text, marker, name)
        lo, hi = P.region_for(text, marker, name)
        text = text[:lo] + body + text[hi:]
    return text


def skey(obj, index):
    sec = obj.sections[index]
    prior = [s for s in obj.sections[:index+1]
             if (s['name'], s['type'], s['flags']) == (sec['name'], sec['type'], sec['flags'])]
    return sec['name'], sec['type'], sec['flags'], len(prior)-1


def canonical(obj, name):
    code, relocs = obj.function(name)
    refs = []
    for reloc in relocs:
        r = reloc.copy()
        if r['symbol'] and r['symbol'].startswith('@'):
            symbol = next(s for s in obj.symbols if s['name'] == r['symbol'])
            r['symbol'] = (skey(obj, symbol['shndx']), symbol['value'], symbol['size'])
        if 'target_section' in r:
            r['target_section'] = skey(obj, r['target_section'])
        refs.append(r)
    return code, refs


def retail_evidence(retail, windows):
    def word(addr):
        return struct.unpack('<I', retail.bytes_at(addr, 4))[0]
    def expect(addr, wanted):
        actual = word(addr)
        assert actual == wanted, (hex(addr), hex(actual), hex(wanted))
        return {'address': hex(addr), 'word': hex(actual)}
    facts = []
    # Provider preserves the independent FP register and four integer registers;
    # the normal packet work layout is unit/id/frame/rate/mode at +0/+4/+6/+8/+c.
    for addr, value in ((0x199f00, 0x00c0902d), (0x199f04, 0x46006506),
                        (0x199f08, 0x00e0882d), (0x199fd4, 0xa4900004),
                        (0x199fd8, 0xa4920006), (0x199fdc, 0xe4940008),
                        (0x199fe0, 0xa491000c), (0x1a83a8, 0x8ca40a0c),
                        (0x1a83ac, 0x87a60450), (0x1a83b4, 0x0c066740),
                        (0x1a83bc, 0x0002b43c), (0x1a83c0, 0x0016b43f),
                        (0x1aa23c, 0x80450000)):
        facts.append(expect(addr, value))
    creator_word = 0x0c000000 | (0x199ee0 >> 2)
    calls = []
    for start, size in ((0x1a59a0, 7536), (0x1a7720, 17536)):
        got = [a for a in range(start, start+size, 4) if word(a) == creator_word]
        wanted = [s[0] for s in SITES if start <= s[0] < start+size]
        assert got == wanted
        calls += got
    # Check the complete decisive setup spans at each call, without relying on
    # relocation masking or a guessed source signature.
    setups = {
        0x1a5e30: (0x1a5e18, [0x001e2c3c,0x00052c3f,0x3207ffff,0x0260202d,0x0000302d,0x4600a306]),
        0x1a6534: (0x1a651c, [0x3c023f80,0x44826000,0x8ec40030,0x2405001a,0x0000302d,0x0000382d]),
        0x1a6570: (0x1a6558, [0x3c023f80,0x44826000,0x8e440030,0x2405001a,0x0000302d,0x24070002]),
        0x1a67a4: (0x1a6788, [0x87a202a0,0x0040282d,0x3c023f80,0x44826000,0x8ec40030,0x0000302d,0x0000382d]),
        0x1a7fe4: (0x1a7fcc, [0x3246ffff,0x3c023f80,0x44826000,0x8e840030,0x2405000d,0x24070004]),
        0x1a8444: (0x1a842c, [0x3c023f80,0x44826000,0x8e840030,0x2405000f,0x0000302d,0x24070005]),
        0x1a8628: (0x1a8610, [0x3c023f80,0x44826000,0x8fa404d0,0x02c0282d,0x0000302d,0x24070002]),
        0x1a8854: (0x1a883c, [0x3c023f80,0x44826000,0x8e840030,0x24050016,0x24060006,0x0000382d]),
        0x1a8be0: (0x1a8bcc, [0x8e840030,0x87a50430,0x24060006,0x4600a306,0x0220382d]),
        0x1a8ebc: (0x1a8ea4, [0x3c023f80,0x44826000,0x8e840030,0x24050006,0x0000302d,0x24070002]),
        0x1a8f60: (0x1a8f48, [0x3c023f80,0x44826000,0x8e840030,0x24050007,0x24060006,0x24070002]),
        0x1a92b8: (0x1a92a0, [0x3c023f80,0x44826000,0x8ec40030,0x2405001a,0x0000302d,0x0000382d]),
        0x1a9300: (0x1a92e4, [0x3c023f80,0x44826000,0x8fa204e0,0x8c440030,0x2405001a,0x0000302d,0x24070002]),
        0x1a9400: (0x1a93e4, [0x3c023f80,0x44826000,0x8fa204e0,0x8c440030,0x2405000a,0x0000302d,0x24070001]),
        0x1aa250: (0x1aa238, [0x7ba20100,0x80450000,0x8ea40030,0x0000302d,0x4600a306,0x0000382d]),
    }
    rows = []
    for address, motion, frame, rate, mode in SITES:
        start, words = setups[address]
        rows.append({'call': hex(address), 'motion': motion, 'blend_frames': frame,
                     'speed': rate, 'mode': mode,
                     'setup': [expect(start+4*i, w) for i, w in enumerate(words)],
                     'jal': expect(address, creator_word), 'delay_slot': expect(address+4, 0)})
    # Scan every validated loadable segment; owner names are inferred only when
    # the address falls inside the canonical function window, not merely near it.
    bounds = sorted(int(a, 16) for a in windows)
    references = []
    opening_references = []
    exact_address_words = {'0x199ee0': [], '0x199d00': []}
    for vaddr, offset, size in retail.segs:
        for index in range(0, size-3, 4):
            w = struct.unpack_from('<I', retail.data, offset+index)[0]
            address = vaddr+index
            if hex(w) in exact_address_words:
                exact_address_words[hex(w)].append(hex(address))
            if w not in (creator_word, 0x0c066740):
                continue
            owner = bounds[bisect.bisect_right(bounds, address)-1]
            inside = owner <= address < owner+windows[f'{owner:08x}']
            row = {'call': hex(address), 'owner': hex(owner) if inside else None}
            (references if w == creator_word else opening_references).append(row)
    return {'provider_and_opening': facts, 'animation_calls': rows,
            'retail_animation_jal_census': references,
            'retail_opening_jal_census': opening_references,
            'exact_address_word_census': exact_address_words}


def main():
    out = Path(sys.argv[1]).resolve(); out.mkdir(parents=True, exist_ok=True)
    cfg = V.load_config()
    windows_doc = json.loads(V.FUNCTION_WINDOWS.read_text())
    retail = V.RetailElf(cfg['retail_elf'], json.loads(V.TARGET.read_text()), windows_doc['sha1'])
    original = subprocess.check_output(['git','show',BASE+':src/promoted/code1_001a.c'], cwd=ROOT).decode()
    final = OWNER.read_text()
    markers = V.scan_markers(OWNER)
    report = {'baseline': BASE, 'source_sha256': sha(final.encode()),
              'baseline_source_sha256': sha(original.encode()),
              'retail_sha256': sha(retail.data), 'compiler': V.unit_compiler(OWNER,cfg),
              'flags': V.unit_compile_flags(OWNER,cfg['compile_flags']),
              'retail': retail_evidence(retail, windows_doc['windows']), 'compiles': {}}
    objects = {}
    cases = [('baseline', original, ()), ('baseline-59a0',original,TARGETS[:1]),
             ('baseline-7720',original,TARGETS[1:]), ('final',final,()),
             ('final-59a0',final,TARGETS[:1]), ('final-7720',final,TARGETS[1:]),
             ('final-both',final,TARGETS)]
    with P.scratch_source(OWNER) as scratch:
        for label, source, enabled in cases:
            scratch.write_text(enable(source, enabled))
            objpath = out/(label+'.o')
            ok, log = V._compile(scratch, cfg, objpath)
            (out/(label+'.log')).write_text(log)
            row = {'success': ok, 'enabled_guards': list(enabled)}
            report['compiles'][label] = row
            print(label, 'compiled' if ok else 'compile error', flush=True)
            if label.startswith('baseline-'):
                assert not ok
                continue
            assert ok, log
            obj = objects[label] = V.ObjectFile(objpath)
            row['object_sha256'] = sha(obj.data)
            row['scores'] = {}
            for name in enabled:
                code, relocs = obj.function(name)
                address = int(name[5:],16); size = windows_doc['windows'][name[5:]]
                nd, _ = V.compare(code, relocs, retail.bytes_at(address,size))
                row['scores'][name] = {'object_bytes':len(code),'retail_window':size,
                                      'normalized_differing_bytes':nd,
                                      'frame_bytes':-struct.unpack('<h',code[:2])[0]}
            if label != 'baseline':
                rows = []
                for marker in markers:
                    name = marker['name']
                    if name in enabled: continue
                    equal = canonical(objects['baseline'],name) == canonical(obj,name)
                    rows.append({'function':name,'bytes_and_relocations_equal':equal})
                    assert equal,(label,name)
                row['preserved_functions'] = rows
    report['production_object_identical'] = objects['baseline'].data == objects['final'].data
    assert report['production_object_identical']
    (out/'proof.json').write_text(json.dumps(report,indent=2)+'\n')
    print('Production object identical; all guarded siblings preserved; retail evidence exact')


if __name__ == '__main__':
    main()
