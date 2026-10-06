"""Section-aware map-owner proof; R_MIPS_LITERAL uses signed gp offsets.

Derived from the retained owner proof used for the first-party matching campaign.
This copy is self-contained apart from the tracked tools/verify.py module.
"""
from pathlib import Path
from collections import defaultdict
import hashlib
import json
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'tools'))
import verify as V

def sha(data):
    return hashlib.sha256(data).hexdigest()

def word(data, offset):
    return struct.unpack_from('<I', data, offset)[0]

def signed16(value):
    value &= 65535
    return value - 65536 if value & 32768 else value

def header_closure(path, seen=None):
    seen = {} if seen is None else seen
    path = path.resolve()
    if path in seen:
        return seen
    raw = path.read_bytes()
    seen[path] = sha(raw)
    for name in re.findall(rb'^\s*#\s*include\s*[<"]([^>"\n]+)', raw, re.M):
        for candidate in [path.parent / name.decode(), ROOT / 'include' / name.decode(), ROOT / name.decode()]:
            if candidate.is_file():
                header_closure(candidate, seen)
                break
    return seen

def data_sections(obj):
    return [s for s in obj.sections if s['flags'] & 2 and not s['flags'] & 4 and s['size']]

def section_keys(obj):
    counts = defaultdict(int)
    keys = {}
    for section in obj.sections:
        names = sorted({s['name'] for s in obj.symbols if s['shndx'] == section['idx']
                        and s['info'] & 15 == 2 and s['name']})
        ordinal = counts[section['name']]
        counts[section['name']] += 1
        keys[section['idx']] = ('functions:' + ','.join(names) if names else
                                section['name'] + '#' + str(ordinal))
    return keys

def symbol_map(obj):
    return {s['name']: s for s in obj.symbols if s['name'] and 0 < s['shndx'] < len(obj.sections)}

def local_target(obj, reloc):
    if 'target_section' in reloc:
        return reloc['target_section'], reloc.get('target_value', 0)
    symbol = symbol_map(obj).get(reloc.get('symbol'))
    return (symbol['shndx'], symbol['value']) if symbol is not None else None

def canonical_relocs(obj, relocs):
    keys = section_keys(obj)
    out = []
    for reloc in relocs:
        target = local_target(obj, reloc)
        out.append({'offset': reloc['offset'], 'type': reloc['r_type'],
                    'target': [keys[target[0]], target[1]] if target else reloc.get('symbol')})
    return out

def data_relocs(obj):
    out = []
    wanted = {s['idx'] for s in data_sections(obj)}
    for section in obj.sections:
        if section['type'] != 9 or section['info'] not in wanted:
            continue
        for at in range(section['offset'], section['offset'] + section['size'], section['entsize'] or 8):
            offset, info = struct.unpack_from('<II', obj.data, at)
            symbol = obj.symtabs[section['link']][info >> 8]
            out.append({'section': section['info'], 'offset': offset, 'type': info & 255,
                        'target_section': symbol['shndx'], 'target_value': symbol['value'],
                        'target_name': symbol['name']})
    return out

def canonical_data_relocs(obj):
    keys = section_keys(obj)
    return [{'section': keys[r['section']], 'offset': r['offset'], 'type': r['type'],
             'target': [keys[r['target_section']], r['target_value']]
             if r['target_section'] in keys else r['target_name']} for r in data_relocs(obj)]

def data_summary(obj):
    keys = section_keys(obj)
    return {keys[s['idx']]: {'bytes': s['size'], 'alignment': s['addralign'],
                            'sha256': sha(b'\0' * s['size'] if s['type'] == 8 else
                                          obj.data[s['offset']:s['offset'] + s['size']])}
            for s in data_sections(obj)}

def globals_table():
    gp, table = V.symbol_addresses()
    for path in [ROOT / 'config/symbol_addrs.txt', ROOT / 'config/symbol_data_addrs.txt']:
        for line in path.read_text().splitlines():
            match = re.match(r'\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[\da-fA-F]+)', line)
            if match:
                table[match[1]] = int(match[2], 16)
    return gp, table

def resolve_function(obj, name, target, runtime_bases=None):
    code, relocs = obj.function(name)
    runtime_bases = {} if runtime_bases is None else runtime_bases
    gp, table = globals_table()
    resolved = bytearray(code)
    pending = defaultdict(list)
    proof = []
    for r in relocs:
        off, kind, symbol = r['offset'], r['r_type'], r.get('symbol')
        local = local_target(obj, r)
        if local:
            assert local[0] in runtime_bases, (r, local, 'unplaced local reference')
            address = runtime_bases[local[0]] + local[1]
        else:
            address = V.resolve_symbol(symbol or '', gp, table)
        assert address is not None, (name, r, 'unresolved reference')
        value = word(code, off)
        entry = dict(r, symbol_address=f'0x{address:08x}')
        proof.append(entry)
        if kind == 4:
            addend = (value & 0x03FFFFFF) << 2
            value = value & 0xFC000000 | (((address + addend) >> 2) & 0x03FFFFFF)
        elif kind == 5:
            pending[symbol].append((off, value))
            continue
        elif kind == 6:
            low = signed16(value)
            for highoff, highword in pending.pop(symbol, []):
                full = address + ((highword & 65535) << 16) + low
                high = highword & 0xFFFF0000 | ((full + 0x8000) >> 16 & 65535)
                struct.pack_into('<I', resolved, highoff, high)
            value = value & 0xFFFF0000 | (address + low & 65535)
        elif kind in (7, 8):
            assert gp is not None
            value = value & 0xFFFF0000 | (address + signed16(value) - gp & 65535)
        else:
            raise AssertionError((name, r))
        struct.pack_into('<I', resolved, off, value)
    assert not pending, (name, pending)
    for entry in proof:
        off, kind = entry['offset'], entry['r_type']
        value, expected = word(resolved, off), word(target, off)
        mask = 0x03FFFFFF if kind == 4 else 65535
        entry.update(resolved_instruction=f'{value:08x}', retail_instruction=f'{expected:08x}',
                     target_bits_equal=(value & mask) == (expected & mask))
    offsets = [off for off in range(0, max(len(code), len(target)), 4)
               if (off < len(code) or any(target[off:off+4])) and
               resolved[off:off+4] != target[off:off+4]]
    return bytes(resolved), proof, offsets

def prove_data(obj, markers, retail, exclude=()):
    gp, table = globals_table()
    wanted = {s['idx'] for s in data_sections(obj)}
    placements, references = defaultdict(set), defaultdict(list)
    for name, marker in markers.items():
        if name in exclude:
            continue
        code, relocs = obj.function(name)
        target = retail.bytes_at(marker['addr'], len(code))
        pending = {}
        for r in relocs:
            destination = local_target(obj, r)
            if destination is None or destination[0] not in wanted:
                continue
            sid, value = destination
            off, kind = r['offset'], r['r_type']
            if kind == 5:
                pending[destination] = off
            elif kind == 6 and destination in pending:
                high = pending.pop(destination)
                address = ((word(target, high) & 65535) << 16) + signed16(word(target, off))
                addend = ((word(code, high) & 65535) << 16) + signed16(word(code, off))
                placements[sid].add(address - addend - value)
                references[sid].append({'function': name, 'hi_offset': high, 'lo_offset': off})
            elif kind in (7, 8):
                assert gp is not None
                placements[sid].add(gp + signed16(word(target, off)) - signed16(word(code, off)) - value)
                references[sid].append({'function': name, 'gp_offset': off})
            else:
                raise AssertionError((name, r))
    assert set(placements) == wanted, (placements, wanted)
    assert all(len(values) == 1 for values in placements.values()), placements
    bases = {sid: next(iter(values)) for sid, values in placements.items()}
    for symbol in obj.symbols:
        if symbol['name'] in markers and symbol['size']:
            base = markers[symbol['name']]['addr'] - symbol['value']
            if symbol['shndx'] in bases:
                assert bases[symbol['shndx']] == base
            bases[symbol['shndx']] = base
    keys, relocs, proof = section_keys(obj), data_relocs(obj), []
    for section in data_sections(obj):
        sid = section['idx']
        payload = bytearray(obj.data[section['offset']:section['offset'] + section['size']])
        entries = []
        for r in relocs:
            if r['section'] != sid:
                continue
            assert r['type'] == 2, r
            relative = r['target_value'] + word(payload, r['offset'])
            target_sid = r['target_section']
            if target_sid in bases:
                address = bases[target_sid] + relative
            else:
                address = V.resolve_symbol(r['target_name'], gp, table)
                assert address is not None, r
                address += relative
            struct.pack_into('<I', payload, r['offset'], address)
            entries.append({'offset': r['offset'], 'retail_target': f'0x{address:08x}'})
        actual = retail.bytes_at(bases[sid], len(payload))
        assert payload == actual, (keys[sid], bases[sid], payload.hex(), actual.hex())
        proof.append({'section': keys[sid], 'retail_address': f'0x{bases[sid]:08x}', 'bytes': len(payload),
                      'fully_resolved_sha256': sha(payload), 'retail_equal': True,
                      'references': references[sid], 'pointer_entries': entries})
    return bases, proof
