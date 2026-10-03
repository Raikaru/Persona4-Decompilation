"""Reproduce scoped guarded compiles, preservation and retail storage evidence.

Run from the checkout root with the licensed compiler/retail configured:
  python docs/probe_archive/Large_Battle_storage_20261003/audit.py OUTPUT
Only ignored OUTPUT and an automatically removed source scratch file are written.
"""
from pathlib import Path
import re
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
from test_large_battle_storage_contracts import uid_statements
BASE = '28bf2efd677ec0436eef6c864603e416f1f26943'
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
    def word(address):
        return struct.unpack('<I', retail.bytes_at(address, 4))[0]
    def expect(address, expected):
        actual=word(address)
        assert actual==expected,(hex(address),hex(actual),hex(expected))
        return {'address':hex(address),'word':hex(actual)}
    census={}
    for name, count, stores, actions in (('func_001a7720',108,272,12),('func_001a59a0',9,81,1)):
        start=int(name[5:],16);size=windows[name[5:]]
        packet_loads=[];uid_stores=[];action_loads=[]
        for address in range(start,start+size,4):
            w=word(address); op=w>>26; base=(w>>21)&31; off=w&0xffff
            if base==29: continue  # Stack records are checked explicitly below.
            if op in (0x23,0x37) and off==0x58:
                assert op==0x37,hex(address)
                packet_loads.append({'address':hex(address),'word':hex(w)})
            if op in (0x2b,0x3f) and off in (8,0x18,0x28,0x60):
                assert op==0x3f,hex(address)
                uid_stores.append({'address':hex(address),'offset':hex(off),'word':hex(w)})
            if op==0x37 and off==0:
                action_loads.append({'address':hex(address),'word':hex(w)})
        assert (len(packet_loads),len(uid_stores),len(action_loads))==(count,stores,actions)
        # Source and retail have equal full-window UID access counts. Do not
        # pretend source order maps each store one-for-one: a few stores are
        # reordered around one packet in retail branch delay slots.
        body=extract_guarded_body(OWNER.read_text(),'FUN_'+name[5:].upper(),name)
        source_stores,source_loads=uid_statements(body)
        assert len(source_stores)==stores
        assert len([l for l in body.splitlines() if re.search(r'0x58\b',l)])==count
        counts={}
        for row in uid_stores: counts[row['offset']]=counts.get(row['offset'],0)+1
        source_counts={}
        for statement,target,source,rhs in source_stores:
            key=hex(target[1]);source_counts[key]=source_counts.get(key,0)+1
            assert re.search(r'\bs32\b',statement) is None,statement
        assert source_counts==counts
        assert sum(r[2] == ('arg0', 0) for r in source_stores) + sum(r[2] == ('arg0', 0) for r in source_loads) == actions
        census[name]={'packet_uid_loads':packet_loads,'action_uid_loads':action_loads,
                      'uid_stores':uid_stores,'source_store_offsets':source_counts,
                      'extracted_scalar_uid_assignments':[r[0] for r in source_loads]}
    # Action ownership and dependency values are full doublewords, including
    # the dependency carried across the loop in 59a0 and saved locals in 7720.
    decisive=((0x1a59dc,0xde910000),(0x1a5e5c,0xdc500058),
              (0x1a685c,0xdc420058),(0x1a6860,0xffa202c0),
              (0x1a7788,0xffa00468),(0x1a8004,0xde310058),
              (0x1a81b0,0xde310058),(0x1a81b4,0xffb10468),
              (0x1a829c,0xdfa30468),(0x1a8794,0xffa20480),
              (0x1aba00,0xdfa30480),(0x1a96f4,0xde220058),
              (0x1a96f8,0x7fa20190),
              # The actual provider's fourth formal is a UID in a3.
              (0x1a834c,0x8fa40598),(0x1a8350,0x8e850030),
              (0x1a8354,0x0000302d),(0x1a8358,0xde470058),
              (0x1a835c,0x24080100),(0x1a8360,0x0c075974),
              # Hit index and provider result address are byte offsets.
              (0x1a66f8,0x00021140),(0x1a66fc,0x02421021),
              (0x1a6700,0x7fa20110),(0x1a6710,0x8042010c),
              (0x1a6f9c,0x00021140),(0x1a6fa0,0x02421021),
              (0x1a6fa4,0x244200f0),(0x1a6fa8,0xafa201f0),
              (0x1a6fb4,0x0040302d),(0x1a6fc0,0x0c07cdb8),
              (0x1aa190,0x00021140),(0x1aa198,0x02421021),
              (0x1aa19c,0x7fa20110),(0x1aa1a0,0x2442010c),
              (0x1aa1a4,0x7fa20100),(0x1aa1ac,0x8042010c))
    return {'census':census,'decisive_instructions':[expect(a,w) for a,w in decisive]}

def main():
    out = Path(sys.argv[1]).resolve(); out.mkdir(parents=True, exist_ok=True)
    cfg = V.load_config()
    windows_doc = json.loads(V.FUNCTION_WINDOWS.read_text())
    retail = V.RetailElf(cfg['retail_elf'], json.loads(V.TARGET.read_text()), windows_doc['sha1'])
    original = subprocess.check_output(['git','show',BASE+':src/promoted/code1_001a.c'], cwd=ROOT).decode()
    final = OWNER.read_text()
    markers = V.scan_markers(OWNER)
    report = {'baseline': BASE, 'tests_sha256': {str(p.relative_to(ROOT)):sha(p.read_bytes()) for p in (ROOT/'tests/test_large_battle_storage_contracts.py',ROOT/'tests/large_battle_storage_fixture.c.in',ROOT/'tests/large_battle_uid_payload_fixture.c.in')}, 'source_sha256': sha(final.encode()),
              'baseline_source_sha256': sha(original.encode()),
              'retail_sha256': sha(retail.data), 'compiler': V.unit_compiler(OWNER,cfg),
              'flags': V.unit_compile_flags(OWNER,cfg['compile_flags']),
              'retail': retail_evidence(retail, windows_doc['windows']), 'compiles': {}}
    objects = {}
    cases = [('baseline', original, ()), ('baseline-59a0',original,TARGETS[:1]),
             ('baseline-7720',original,TARGETS[1:]), ('baseline-both',original,TARGETS), ('final',final,()),
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
