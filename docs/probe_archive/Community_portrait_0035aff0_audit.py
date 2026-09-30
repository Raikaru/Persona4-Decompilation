#!/usr/bin/env python3
"""Measure the community-portrait candidate without changing the owning source.

Run from the repository root after preparing the normal retail/toolchain inputs.
The optional reference tree supplies generated undefined_syms_auto.txt when the
current independent checkout has only the target's generated assembly.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import probe_variants as P
import recovery_quality as Q
from measure_guarded import extract_guarded_body
import verify as V


def allocated_sections(obj):
    result = []
    for section in obj.sections:
        if not section['flags'] & 2:
            continue
        data = (obj.data[section['offset']:section['offset'] + section['size']]
                if section['type'] != 8 else b'')
        result.append((section['name'], section['size'], section['type'], data))
    return result


def production_relocations(obj, records):
    """Ignore private compiler labels only when their exact section/value agree."""
    result = []
    for relocation in records:
        row = dict(relocation)
        name = row.get('symbol')
        if name and name.startswith('@'):
            symbol = next(item for item in obj.symbols if item['name'] == name)
            row['symbol'] = ('private', symbol['shndx'], symbol['value'], symbol['size'])
        result.append(row)
    return result


def private_data_relocations(obj, records):
    """Bind renamed data labels to exact bytes, outgoing fixups and data order.

    Staging C may add a relocation section and shift all following ELF section
    indices. Only a compiler-private label in a non-code allocated section may
    be normalized, and its within-section value/size remain part of the key.
    """
    data_indices = [i for i, section in enumerate(obj.sections)
                    if section['flags'] & 2 and not section['flags'] & 4]
    result = []
    for relocation in records:
        row = dict(relocation)
        name = row.get('symbol', '')
        if name.startswith('@'):
            symbol = next(item for item in obj.symbols if item['name'] == name)
            if symbol['shndx'] in data_indices:
                section = obj.sections[symbol['shndx']]
                data, outgoing = obj.function(name)
                row['symbol'] = ('private-data', data_indices.index(symbol['shndx']),
                                 section['name'], section['type'], section['flags'],
                                 symbol['value'], symbol['size'], data.hex(), outgoing)
        result.append(row)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--reference-tree', type=Path, default=ROOT)
    parser.add_argument('--baseline', default='8407da0ac22444a65389d64fc01aae67e3d481fd')
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    owner = ROOT / 'src/promoted/code1_0035.c'
    config = V.load_config()
    original = subprocess.check_output(
        ['git', 'show', args.baseline + ':src/promoted/code1_0035.c'],
        cwd=ROOT, text=True)
    source = owner.read_text(encoding='utf-8')
    body = extract_guarded_body(source, 'FUN_0035AFF0', 'func_0035aff0')
    start, end = P.region_for(source, 'FUN_0035AFF0', 'func_0035aff0')
    staged = P.splice_region(source, start, end, body, '\n')
    objects = {}
    for label, text in [('baseline', original), ('production', source), ('candidate', staged),
                        ('baseline_guarded', original), ('production_guarded', source)]:
        with P.scratch_source(owner) as temporary:
            temporary.write_text(text, encoding='utf-8')
            output = args.output / (label + '.o')
            unit_config = dict(config)
            if label.endswith('_guarded'):
                unit_config['compile_flags'] = config['compile_flags'] + ['-DNON_MATCHING']
            success, log = P._compile_in_context(temporary, owner, unit_config, output)
            (args.output / (label + '.log')).write_text(log, encoding='utf-8')
            if not success:
                raise RuntimeError(log)
            objects[label] = V.ObjectFile(output)
    target = V._read_json(V.TARGET)
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(config['retail_elf'], target, windows['sha1'])
    code, relocations = objects['candidate'].function('func_0035aff0')
    expected = retail.bytes_at(0x0035AFF0, 2784)
    difference, first = V.compare(code, relocations, expected)
    mask = V.mask_bytes(max(len(code), len(expected)), relocations)
    words = 0
    for offset in range(0, len(mask), 4):
        if offset >= len(code) and not any(expected[offset:offset + 4]):
            continue
        if any((code[index] if index < len(code) else None) !=
               (expected[index] if index < len(expected) else None)
               for index in range(offset, min(offset + 4, len(mask))) if not mask[index]):
            words += 1
    markers = V.scan_markers(owner)
    production_unchanged = True
    production_destinations_unchanged = True
    anonymous_renamings = []
    siblings = []
    for marker in markers:
        name = marker['name']
        original_code, original_relocations = objects['baseline'].function(name)
        final_code, final_relocations = objects['production'].function(name)
        production_unchanged &= ((original_code, original_relocations) ==
                                 (final_code, final_relocations))
        equivalent = (original_code == final_code and
                      production_relocations(objects['baseline'], original_relocations) ==
                      production_relocations(objects['production'], final_relocations))
        production_destinations_unchanged &= equivalent
        if original_relocations != final_relocations:
            anonymous_renamings.append(dict(function=name, same_section_destinations=equivalent))
        if name == 'func_0035aff0':
            continue
        sibling, sibling_relocations = objects['candidate'].function(name)
        window = windows['windows'].get(f'{marker["addr"]:08X}')
        if window is None:
            window = windows['windows'][f'{marker["addr"]:08x}']
        sibling_difference, _ = V.compare(
            sibling, sibling_relocations, retail.bytes_at(marker['addr'], window))
        siblings.append(dict(name=name, bytes=len(sibling),
                             size_unchanged=len(sibling) == len(original_code),
                             instructions_identical=sibling == original_code,
                             relocation_records_identical=sibling_relocations == original_relocations,
                             same_section_index_destinations=production_relocations(objects['candidate'], sibling_relocations) == production_relocations(objects['baseline'], original_relocations),
                             equivalent_private_data_destinations=private_data_relocations(objects['candidate'], sibling_relocations) == private_data_relocations(objects['baseline'], original_relocations),
                             normalized_diff=sibling_difference))
    addresses = {}
    for path in (ROOT / 'config/symbols_recovered.txt', ROOT / 'config/symbol_data_addrs.txt',
                 args.reference_tree / 'undefined_syms_auto.txt'):
        if not path.exists():
            continue
        for line in path.read_text().splitlines():
            match = re.match(r'\s*(\w+)\s*=\s*(0x[0-9a-fA-F]+)', line)
            if match:
                addresses[match[1]] = int(match[2], 16)
    references = []
    for name in sorted({row['symbol'] for row in relocations if row['r_type'] in (5, 6, 7)}):
        address = addresses.get(name)
        if address is None:
            gp, symbol_table = V.symbol_addresses()
            address = V.resolve_symbol(name, gp, symbol_table)
        entry = dict(name=name, address=f'{address:#010x}' if address else None,
                     forms=sorted({row['type'] for row in relocations if row['symbol'] == name}))
        if address and 0x00761100 <= address < 0x00761200:
            raw = retail.bytes_at(address, 4)
            entry.update(retail_bits=raw.hex(), retail_float=struct.unpack('<f', raw)[0])
        references.append(entry)
    gp, symbol_table = V.symbol_addresses()
    retail_calls = [(word & 0x3ffffff) << 2 for (word,) in struct.iter_unpack('<I', expected) if word >> 26 == 3]
    candidate_calls = [V.resolve_symbol(row['symbol'], gp, symbol_table) for row in relocations if row['r_type'] == 4]
    calls = dict(retail_count=len(retail_calls), candidate_count=len(candidate_calls),
                 retail_indirect_count=sum((word & 0xfc00003f) == 9 for (word,) in struct.iter_unpack('<I', expected)),
                 candidate_indirect_count=sum((word & 0xfc00003f) == 9 for (word,) in struct.iter_unpack('<I', code)),
                 same_ordered_destinations=retail_calls == candidate_calls,
                 same_destinations_and_multiplicities=Counter(retail_calls) == Counter(candidate_calls))
    palette_data = {f'{address:#010x}': retail.bytes_at(address,4).hex() for address in (0x64cd30,0x64cd34,0x64cd38)}
    candidate_data = [(section['name'], section['size'], objects['candidate'].data[section['offset']:section['offset']+section['size']]) for section in objects['candidate'].sections if section['flags'] & 2 and not section['flags'] & 4]
    baseline_data = [(section['name'], section['size'], objects['baseline'].data[section['offset']:section['offset']+section['size']]) for section in objects['baseline'].sections if section['flags'] & 2 and not section['flags'] & 4]
    report = dict(
        baseline=args.baseline, owner_sha256=hashlib.sha256(source.encode()).hexdigest(),
        body_sha256=hashlib.sha256(body.encode()).hexdigest(),
        production_functions=len(markers), production_instructions_and_relocations_identical=production_unchanged,
        production_instructions_and_relocation_destinations_identical=production_destinations_unchanged,
        anonymous_relocation_renamings=anonymous_renamings,
        production_allocatable_sections_identical=(allocated_sections(objects['baseline']) ==
                                                  allocated_sections(objects['production'])),
        candidate_data_sections_identical=candidate_data == baseline_data, candidate_data_section_sizes=[(name,size) for name,size,_ in candidate_data],
        calls=calls, retail_normal_data=palette_data, candidate=dict(bytes=len(code), retail_bytes=2784, normalized_diff=difference,
                       differing_words=words, first_diffs=first,
                       frame_bytes=-struct.unpack('<h', code[:2])[0],
                       relocations=relocations, data_references=references), siblings=siblings)
    # Exact C must resolve every relocation, not only its masked opcode.
    resolved = []
    for relocation in relocations:
        row = dict(relocation)
        offset = row['offset']
        name = row['symbol']
        address = V.resolve_symbol(name, gp, symbol_table)
        if address is None:
            address = addresses.get(name)
        if address is None:
            raise AssertionError(('Unresolved reference', row))
        candidate_word = struct.unpack_from('<I', code, offset)[0]
        retail_word = struct.unpack_from('<I', expected, offset)[0]
        addend = candidate_word & 0xffff
        signed = addend - 0x10000 if addend & 0x8000 else addend
        kind = row['r_type']
        if kind == 4:
            expected_field = ((address >> 2) + (candidate_word & 0x3ffffff)) & 0x3ffffff
            retail_field = retail_word & 0x3ffffff
        elif kind == 5:
            # All target HI16 addends are zero and pair with zero-addend LO16.
            assert addend == 0, row
            expected_field = ((address + 0x8000) >> 16) & 0xffff
            retail_field = retail_word & 0xffff
        elif kind == 6:
            expected_field = (address + signed) & 0xffff
            retail_field = retail_word & 0xffff
        elif kind == 7:
            assert gp is not None
            displacement = address - gp + signed
            assert -0x8000 <= displacement < 0x8000, row
            expected_field = displacement & 0xffff
            retail_field = retail_word & 0xffff
        else:
            raise AssertionError(('Unhandled reference', row))
        assert expected_field == retail_field, (row, expected_field, retail_field)
        resolved.append(dict(offset=offset, symbol=name, address=f'{address:#010x}',
                             kind=row['type'], candidate_addend=signed,
                             retail_field=f'{retail_field:#x}', exact=True))
    report['target_relocations_resolved_exactly'] = resolved
    report['retail_zero_tail_bytes'] = len(expected) - len(code)
    report['retail_zero_tail_only'] = not any(expected[len(code):])
    report['all_79_siblings_unchanged'] = all(
        row['size_unchanged'] and row['instructions_identical'] and
        row['equivalent_private_data_destinations'] for row in siblings)
    guarded_siblings = []
    for marker in markers:
        name = marker['name']
        if name == 'func_0035aff0':
            continue
        old_code, old_rel = objects['baseline_guarded'].function(name)
        new_code, new_rel = objects['production_guarded'].function(name)
        guarded_siblings.append(dict(name=name, bytes=len(new_code),
            instructions_and_size_identical=old_code == new_code,
            relocation_destinations_identical=(
                private_data_relocations(objects['baseline_guarded'], old_rel) ==
                private_data_relocations(objects['production_guarded'], new_rel))))
    report['guarded_siblings'] = guarded_siblings
    report['all_79_guarded_siblings_unchanged'] = all(
        row['instructions_and_size_identical'] and row['relocation_destinations_identical']
        for row in guarded_siblings)
    report['guarded_data_sections_identical'] = (
        [item for item in allocated_sections(objects['baseline_guarded']) if item[0] != '.text'] ==
        [item for item in allocated_sections(objects['production_guarded']) if item[0] != '.text'])
    report['full_link_and_hash_validation'] = 'Not performed by this owner audit; see the separate linked-build receipt'
    (args.output / 'candidate.c').write_text(body)
    (args.output / 'audit.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({key: value for key, value in report.items() if key not in ('candidate', 'siblings')}, indent=2))
    print('Candidate:', {key: value for key, value in report['candidate'].items()
                         if key not in ('relocations', 'data_references', 'first_diffs')})
    print('Calls:', calls)
    print('Siblings:', len(siblings), 'all original instructions and sizes:',
          all(row['instructions_identical'] and row['size_unchanged'] for row in siblings))


if __name__ == '__main__':
    main()
