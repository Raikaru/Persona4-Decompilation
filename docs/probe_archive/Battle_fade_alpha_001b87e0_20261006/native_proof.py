"""Read-only native owner proof using the retained ActionSkill relocation logic.

Only read/proof functions are imported. This module has no compiler entry point.
Detailed results belong in private scratch; the portable manifest keeps digests.
"""
from collections import defaultdict
from pathlib import Path
import hashlib
import json
import struct
import sys

def digest(data):
    return hashlib.sha256(data).hexdigest()

def word(data, offset):
    return struct.unpack_from('<I', data, offset)[0]

def signed16(value):
    return (value & 0x7fff) - (value & 0x8000)

def relocate(code, relocations, gp, symbols, bases, verify):
    """Same REL addend/GP/HI-LO handling as ActionSkill proof.py.txt.

    Return a comparison-only buffer, never a patched native object. Fail closed
    for missing symbols, orphaned high/low halves or an invalid displacement.
    """
    linked = bytearray(code)
    pending = defaultdict(list)
    resolved = []
    for r in relocations:
        offset, kind, symbol = r['offset'], r['r_type'], r['symbol']
        if offset % 4 or not 0 <= offset <= len(code) - 4:
            raise ValueError('Unbounded code relocation')
        if r.get('target_section') is not None:
            address = bases.get(r['target_section'])
            if address is not None:
                address += r.get('target_value', 0)
        else:
            address = verify.resolve_symbol(symbol, gp, symbols)
        if address is None:
            raise ValueError('Unresolved reference: ' + str(symbol))
        value = word(code, offset)
        if kind == 4:
            addend = (value & 0x3ffffff) << 2
            destination = address + addend
            if destination % 4:
                raise ValueError('Unaligned call target')
            encoded = (value & 0xfc000000) | ((destination >> 2) & 0x3ffffff)
        elif kind in (7, 8):
            addend = signed16(value)
            displacement = address + addend - gp
            if not -0x8000 <= displacement < 0x8000:
                raise ValueError('GP displacement outside signed-16 range')
            encoded = (value & 0xffff0000) | (displacement & 0xffff)
        elif kind == 5:
            pending[(symbol, address)].append((r, value & 0xffff))
            continue
        elif kind == 6:
            pairs = pending.pop((symbol, address), [])
            if not pairs:
                raise ValueError('Unpaired LO16: ' + str(symbol))
            for high, high_addend in pairs:
                addend = (high_addend << 16) + signed16(value)
                destination = address + addend
                hi_word = (word(code, high['offset']) & 0xffff0000) | (((destination + 0x8000) >> 16) & 0xffff)
                struct.pack_into('<I', linked, high['offset'], hi_word)
                resolved.append({**high, 'symbol_address': address, 'addend': addend, 'resolved_word': hi_word})
            encoded = (value & 0xffff0000) | (destination & 0xffff)
        else:
            raise ValueError('Unsupported code relocation: ' + str(kind))
        struct.pack_into('<I', linked, offset, encoded)
        resolved.append({**r, 'symbol_address': address, 'addend': addend, 'resolved_word': encoded})
    if any(pending.values()) or len(resolved) != len(relocations):
        raise ValueError('Unresolved high-half relocation')
    return bytes(linked), resolved

def inspect_owner(root, owner, object_path, target_name, cfg, named=None):
    sys.path.insert(0, str(root / 'tools'))
    import verify as V
    import build as B
    meta = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg['retail_elf'], V._read_json(V.TARGET), meta['sha1'])
    obj = V.ObjectFile(object_path)
    markers = [m for m in V.scan_markers(root / owner) if m.get('name')]
    gp, symbols = V.symbol_addresses()
    if gp is None:
        raise ValueError('Missing GP')
    symbols = dict(symbols)
    for name, address in (named or {}).items():
        if name in symbols and symbols[name] != address:
            raise ValueError('Conflicting canonical address: ' + name)
        symbols[name] = address
    symbols.update({m['name']: m['addr'] for m in markers})
    stable = []
    for marker in markers:
        code, refs = obj.function(marker['name'])
        size = meta['windows'][f"{marker['addr']:08x}"]
        expected = retail.bytes_at(marker['addr'], size)
        if (marker['name'] != target_name and len(code) <= size
                and not any(expected[len(code):]) and V.compare(code, refs, expected)[0] == 0):
            stable.append(marker)
    votes = B._section_base_votes(obj, stable, retail, gp)
    if any(len(v) != 1 for v in votes.values()):
        raise ValueError('Conflicting owned-storage anchors')
    bases = {index: next(iter(v)) for index, v in votes.items()}
    sections = [s for s in obj.sections if s['flags'] & 2 and not s['flags'] & 4 and s['size']]
    for symbol in obj.symbols:
        address = V.resolve_symbol(symbol['name'], gp, symbols)
        if address is not None:
            symbols[symbol['name']] = address
            if any(s['idx'] == symbol['shndx'] for s in sections):
                base = address - symbol['value']
                if symbol['shndx'] in bases and bases[symbol['shndx']] != base:
                    raise ValueError('Canonical symbol contradicts storage anchor')
                bases[symbol['shndx']] = base
    if any(s['idx'] not in bases for s in sections):
        for index, address in (B.recover_pointer_data_bases(obj, stable, retail, gp) or {}).items():
            if index in bases and bases[index] != address:
                raise ValueError('Conflicting pointer-data anchor')
            bases[index] = address
    # A scalar used only by the unmatched target cannot be anchored by siblings.
    # Admit a narrow, explicit joint code/data proof instead: every native use
    # must be an R_MIPS_LITERAL at the same position with identical nonrelocated
    # instruction bits; two or more independent sites must agree on one base.
    # The native scalar payload and every fully resolved use are checked below.
    target_marker = next(m for m in markers if m['name'] == target_name)
    target_code, target_refs = obj.function(target_name)
    target_expected = retail.bytes_at(target_marker['addr'], meta['windows'][f"{target_marker['addr']:08x}"])
    literal_anchors = {}
    for section in sections:
        if section['idx'] in bases or section['name'] != '.lit4' or section['size'] != 4:
            continue
        # MWCC marks its GP-relative literal pools SHF_WRITE (0x10000003).
        # Preserve that native metadata; do not mistake it for extra storage.
        if (section['type'] != 1 or section['flags'] not in (2, 3, 0x10000002, 0x10000003)
                or B.section_relocs(obj, section['idx'])):
            continue
        names = {s['name'] for s in obj.symbols if s['shndx'] == section['idx']}
        refs = [r for r in target_refs if r['symbol'] in names or r.get('target_section') == section['idx']]
        if len({r['offset'] for r in refs}) < 2:
            continue
        if any(r['r_type'] != 8 or r['offset']+4 > len(target_expected)
               or word(target_code, r['offset']) >> 16 != word(target_expected, r['offset']) >> 16 for r in refs):
            continue
        choices = B._section_base_votes(obj, [target_marker], retail, gp).get(section['idx'], {})
        if len(choices) != 1 or sum(choices.values()) != len(refs):
            raise ValueError('Target-local literal witnesses disagree')
        bases[section['idx']] = next(iter(choices))
        literal_anchors[section['idx']] = [r['offset'] for r in refs]
    storage = []
    for section in sections:
        index = section['idx']
        if index not in bases:
            raise ValueError('Unanchored storage: ' + str((index, section['name'], section['size'])))
        address = bases[index]
        if address % max(1, section['addralign']):
            raise ValueError('Storage alignment violation')
        refs = B.section_relocs(obj, index)
        if section['type'] == 8:
            if refs:
                raise ValueError('Relocated BSS unsupported')
            payload = bytes(section['size'])
        elif not refs:
            payload = obj.data[section['offset']:section['offset'] + section['size']]
        elif section['name'] == '.rodata':
            payload = B._independent_rodata_payload(obj, section, stable, retail, address, symbols)
        else:
            payload = B.resolved_initialized_payload(obj, section, stable, bases, symbols)
        if payload is None or payload != retail.bytes_at(address, section['size']):
            raise ValueError('Owned storage differs: ' + str((index, section['name'])))
        storage.append({'section': index, 'name': section['name'], 'address': address,
                        'size': section['size'], 'alignment': section['addralign'],
                        'sha256': digest(payload), 'references': refs, 'exact': True,
                        'target_literal_witness_offsets': literal_anchors.get(index, [])})
    for symbol in obj.symbols:
        if symbol['name'] and symbol['shndx'] in bases:
            address = bases[symbol['shndx']] + symbol['value']
            if symbol['name'] in symbols and symbols[symbol['name']] != address:
                raise ValueError('Inconsistent local storage symbol')
            symbols[symbol['name']] = address
    functions, covered = [], defaultdict(set)
    linked_functions = {}
    for marker in markers:
        name, address = marker['name'], marker['addr']
        code, refs = obj.function(name)
        linked, resolved = relocate(code, refs, gp, symbols, bases, V)
        size = meta['windows'][f'{address:08x}']
        expected = retail.bytes_at(address, size)
        if name == target_name:
            for offsets in literal_anchors.values():
                if any(linked[i:i+4] != expected[i:i+4] for i in offsets):
                    raise ValueError('Target-local literal failed resolved-reference proof')
        offsets = [i for i in range(0, max(len(linked), size), 4)
                   if linked[i:i+4].ljust(4, b'\0') != expected[i:i+4].ljust(4, b'\0')]
        zero_tail = len(code) <= size and not any(expected[len(code):])
        functions.append({'name': name, 'address': address, 'bytes': len(code), 'window': size,
                          'source_kind': 'C' if name == target_name or not marker.get('asm') else 'ASM',
                          'code_sha256': digest(code), 'resolved_sha256': digest(linked),
                          'reference_count': len(resolved), 'references': resolved,
                          'fully_resolved_words': len(offsets), 'residual_offsets': offsets,
                          'zero_tail': zero_tail, 'zero_tail_bytes': size-len(code) if zero_tail else None,
                          'exact': not offsets and zero_tail})
        linked_functions[name] = linked
        symbol = next(s for s in obj.symbols if s['name'] == name and s['size'] and s['shndx'] != 0)
        interval = set(range(symbol['value'], symbol['value']+symbol['size']))
        if interval & covered[symbol['shndx']]:
            raise ValueError('Overlapping executable extents')
        covered[symbol['shndx']].update(interval)
    coverage = []
    for section in obj.sections:
        if section['flags'] & 6 != 6:
            continue
        payload = obj.data[section['offset']:section['offset']+section['size']]
        unused = set(range(section['size'])) - covered[section['idx']]
        if any(payload[i] for i in unused):
            raise ValueError('Nonzero executable bytes have no owner')
        for offset, _, _ in B.section_relocs(obj, section['idx']):
            if not set(range(offset, offset+4)) <= covered[section['idx']]:
                raise ValueError('Unowned executable relocation')
        coverage.append({'section': section['idx'], 'bytes': len(payload),
                         'owned_bytes': len(covered[section['idx']]), 'zero_alignment_bytes': len(unused)})
    stable_names = {m['name'] for m in stable}
    if any(not f['exact'] for f in functions if f['name'] in stable_names):
        raise ValueError('Storage anchor depended on a nonexact sibling')
    target = next(f for f in functions if f['name'] == target_name)
    siblings = [f for f in functions if f['name'] != target_name]
    report = {'owner': owner, 'object_sha256': digest(obj.data), 'target': target,
              'functions': functions, 'storage': storage, 'coverage': coverage,
              'code_references_resolved': sum(f['reference_count'] for f in functions),
              'data_references_resolved': sum(len(s['references']) for s in storage),
              'sibling_count': len(siblings), 'exact_siblings': sum(f['exact'] for f in siblings),
              'sibling_kinds': {kind: sum(f['source_kind'] == kind for f in siblings) for kind in ('C', 'ASM')},
              'regressed_siblings': [f['name'] for f in siblings if not f['exact']],
              'all_references_resolved': True, 'all_storage_exact': True,
              'promotion_eligible': target['exact'] and all(f['exact'] for f in siblings)}
    return report, linked_functions, (gp, symbols, bases)
