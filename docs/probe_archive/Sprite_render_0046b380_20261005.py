#!/usr/bin/env python3
"""Reproduce the guarded sdkSpr recovery and independently resolve the whole owner.

Uses only the repository's configured compiler/retail image and immutable git
baseline. All objects, logs and temporary source stay in a new build directory.
The target remains NONMATCHING; the default production path remains ASM.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[2]
OWNER = ROOT / 'src/Kernel/sdkSpr.c'
FUNCTION = 'func_0046b380'
ADDRESS = 0x0046B380
sys.path.insert(0,str(ROOT/'tools'))
import verify as V
import probe_variants as P
import fnalign
import build as B

def SHA(data):
    return hashlib.sha256(data).hexdigest()


def compile_source(label, text, native=True, physical=None):
    directory = OUT / label
    directory.mkdir(exist_ok=True)
    source = directory / 'owner.c'
    source.write_text(text, encoding='utf-8', newline='\n')
    objpath = directory / 'owner.o'
    cfg = V.load_config()
    if native:
        cfg = dict(cfg, compile_flags=[*cfg['compile_flags'], '-DNON_MATCHING'])
    compiled_source = physical if physical else source
    if physical:
        assert physical.read_text(encoding='utf-8') == text
    ok, log = P._compile_in_context(compiled_source, OWNER, cfg, objpath)
    (directory / 'compile.log').write_text(log, encoding='utf-8')
    if not ok:
        print(label, 'COMPILE_ERROR', log[-10000:], flush=True)
        raise SystemExit(1)
    obj = V.ObjectFile(objpath)
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg['retail_elf'], V._read_json(V.TARGET), windows['sha1'])
    body, relocs = obj.function(FUNCTION)
    target = retail.bytes_at(ADDRESS, windows['windows'][f'{ADDRESS:08x}'])
    nd, first = V.compare(body, relocs, target)
    edits, count, reloc_count = fnalign.align(fnalign.decode(target, ADDRESS),
        fnalign.decode(body, ADDRESS), {r['offset'] // 4 for r in relocs})
    record = dict(label=label, native=native,
        source_sha256=SHA(source.read_bytes()), object_sha256=SHA(objpath.read_bytes()),
        compiled_source=compiled_source.relative_to(ROOT).as_posix(),
        compiled_source_sha256=SHA(compiled_source.read_bytes()),
        logical_owner=OWNER.relative_to(ROOT).as_posix(),
        flags=V.unit_compile_flags(OWNER, cfg['compile_flags']),
        bytes=len(body), window=len(target), masked_byte_differences=nd,
        first_differences=first, alignment_edits=count, alignment_reloc_only=reloc_count,
        relocations=len(relocs), frame=-int.from_bytes(body[:2], 'little', signed=True),
        tail_bytes=max(0, len(target)-len(body)), tail_all_zero=not any(target[len(body):]))
    peers = []
    for marker in V.scan_markers(source):
        if not marker.get('name'):
            continue
        code, references = obj.function(marker['name'])
        wanted = retail.bytes_at(marker['addr'], windows['windows'][f"{marker['addr']:08x}"])
        different, _ = V.compare(code, references, wanted)
        peers.append(dict(name=marker['name'], bytes=len(code), window=len(wanted),
                          masked_byte_differences=different, raw_sha256=SHA(code),
                          relocations=references, tail_all_zero=not any(wanted[len(code):])))
    record['functions'] = peers
    (directory / 'score.json').write_text(json.dumps(record, indent=2) + '\n')
    for name, code in [('candidate', body), ('retail', target)]:
        (directory / (name + '.txt')).write_text('\n'.join(
            f'{offset:04x} {fnalign.disassemble(code[offset:offset+4], ADDRESS+offset)}'
            for offset in range(0, len(code), 4)) + '\n')
    (directory / 'align.json').write_text(json.dumps(edits, indent=2) + '\n')
    print(json.dumps({k:v for k,v in record.items() if k not in ('functions','first_differences','flags')}), flush=True)
    return record


def sign16(value):
    return (value & 0x7fff) - (value & 0x8000)


def section_relocations(obj, index):
    result = []
    for section in obj.sections:
        if section['type'] != 9 or section['info'] != index:
            continue
        table = obj.symtabs[section['link']]
        for at in range(section['offset'], section['offset'] + section['size'], section['entsize'] or 8):
            offset, info = struct.unpack_from('<II', obj.data, at)
            symbol = table[info >> 8]
            result.append(dict(offset=offset, r_type=info & 255, symbol=symbol['name'],
                target_section=symbol['shndx'], target_value=symbol['value']))
    return result


def resolve(raw, references, values, bases, gp):
    resolved = bytearray(raw)
    pending = defaultdict(list)
    records = []
    for reference in references:
        name, kind, offset = reference['symbol'], reference['r_type'], reference['offset']
        address = V.resolve_symbol(name or '', gp, values)
        if not name and reference.get('target_section') in bases:
            address = bases[reference['target_section']] + reference.get('target_value', 0)
        if address is None:
            raise ValueError('Unresolved reference: ' + repr(reference))
        word, = struct.unpack_from('<I', raw, offset)
        entry = dict(offset=offset, kind=kind, symbol=name, address=address)
        records.append(entry)
        key = (name, reference.get('target_section') if not name else None, address)
        if kind == 4:
            addend = (word & 0x03ffffff) << 2
            result = (address + addend) & 0xffffffff
            assert result % 4 == 0
            struct.pack_into('<I', resolved, offset, word & 0xfc000000 | result >> 2 & 0x03ffffff)
            entry.update(addend=addend, resolved=result)
        elif kind == 5:
            pending[key].append((offset, word, entry))
        elif kind == 6:
            low = sign16(word)
            for high_offset, high_word, high_entry in pending.pop(key, []):
                addend = ((high_word & 65535) << 16) + low
                result = (address + addend) & 0xffffffff
                struct.pack_into('<I', resolved, high_offset,
                    high_word & 0xffff0000 | (result + 0x8000) >> 16 & 65535)
                high_entry.update(addend=addend, resolved=result, low_offset=offset)
            struct.pack_into('<I', resolved, offset, word & 0xffff0000 | address + low & 65535)
            entry.update(addend=low, resolved=(address + low) & 0xffffffff)
        elif kind in (7, 8):
            addend = sign16(word)
            displacement = address + addend - gp
            assert -32768 <= displacement < 32768, (name, displacement)
            struct.pack_into('<I', resolved, offset, word & 0xffff0000 | displacement & 65535)
            entry.update(addend=addend, resolved=address + addend)
        elif kind == 2:
            result = (address + word) & 0xffffffff
            struct.pack_into('<I', resolved, offset, result)
            entry.update(addend=word, resolved=result)
        else:
            raise ValueError('Unsupported reference: ' + repr(reference))
    assert not pending, pending
    return bytes(resolved), records


def proof(label):
    directory = OUT / label
    score = json.loads((directory / 'score.json').read_text())
    source = directory / 'owner.c'
    objpath = directory / 'owner.o'
    assert SHA(source.read_bytes()) == score['source_sha256']
    assert SHA(objpath.read_bytes()) == score['object_sha256']
    obj = V.ObjectFile(objpath)
    cfg = V.load_config()
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg['retail_elf'], V._read_json(V.TARGET), windows['sha1'])
    markers = [m for m in V.scan_markers(source) if m.get('name')]
    assert len({m['name'] for m in markers}) == len(markers)
    emitted_functions = sorted({s['name'] for s in obj.symbols
        if s['info'] & 15 == 2 and s['size'] and 0 < s['shndx'] < len(obj.sections)
        and obj.sections[s['shndx']]['flags'] & 4})
    assert emitted_functions == sorted(m['name'] for m in markers), emitted_functions
    executable_coverage = []
    for section in obj.sections:
        if not section['size'] or not section['flags'] & 4:
            continue
        covered = bytearray(section['size'])
        for symbol in obj.symbols:
            if symbol['name'] in emitted_functions and symbol['shndx'] == section['idx']:
                covered[symbol['value']:symbol['value']+symbol['size']] = bytes([1])*symbol['size']
        raw = obj.data[section['offset']:section['offset']+section['size']]
        assert len(covered) == len(raw)
        assert not any(byte for byte, belongs in zip(raw,covered) if not belongs)
        executable_coverage.append(dict(section=section['name'], bytes=len(raw),
            unowned_zero_bytes=covered.count(0)))
    gp, values = B.load_lcf_symbols()
    values.update(B.load_symbol_addr_map())
    values.update(V.symbol_addresses()[1])
    values['_gp'] = gp
    values.update({m['name']:m['addr'] for m in markers})
    witnesses = []
    for marker in markers:
        if marker['name'] == FUNCTION:
            continue
        code, references = obj.function(marker['name'])
        target = retail.bytes_at(marker['addr'], windows['windows'][f"{marker['addr']:08x}"])
        if V.compare(code, references, target)[0] == 0 and len(code) <= len(target) and not any(target[len(code):]):
            witnesses.append(marker)
    bases = B.recover_section_bases(obj, witnesses, retail, gp)
    for symbol in obj.symbols:
        if symbol['name'] in values and 0 < symbol['shndx'] < len(obj.sections):
            section = obj.sections[symbol['shndx']]
            if section['flags'] & 4:
                base = values[symbol['name']] - symbol['value']
                assert bases.setdefault(symbol['shndx'], base) == base
    for symbol in obj.symbols:
        if symbol['name'] and symbol['shndx'] in bases:
            values[symbol['name']] = bases[symbol['shndx']] + symbol['value']
    functions = []
    for marker in markers:
        code, references = obj.function(marker['name'])
        target = retail.bytes_at(marker['addr'], windows['windows'][f"{marker['addr']:08x}"])
        resolved, bindings = resolve(code, references, values, bases, gp)
        differences = [n for n in range(max(len(resolved), len(target)))
                       if (n < len(resolved) or target[n]) and resolved[n:n+1] != target[n:n+1]]
        exact = not differences and len(resolved) <= len(target) and not any(target[len(resolved):])
        is_asm = marker.get('asm', False) and (marker['name'] != FUNCTION or not score['native'])
        status = ('ASM' if is_asm else 'MATCH') if exact else 'NONMATCHING'
        entry = dict(name=marker['name'], address=marker['addr'], status=status,
            source_kind='ASM' if is_asm else 'C', bytes=len(code), window=len(target),
            raw_sha256=SHA(code), resolved_sha256=SHA(resolved),
            resolved_byte_differences=len(differences),
            resolved_word_differences=len({n//4 for n in differences}),
            tail_bytes=max(0,len(target)-len(code)), tail_all_zero=not any(target[len(code):]),
            relocations=bindings)
        functions.append(entry)
        if marker['name'] == FUNCTION:
            (directory / 'resolved.bin').write_bytes(resolved)
            edits, count, reloc_count = fnalign.align(fnalign.decode(target, ADDRESS),
                fnalign.decode(resolved, ADDRESS), set())
            entry.update(alignment_edits=count, alignment_reloc_only=reloc_count,
                         mismatch_offsets=sorted({n//4*4 for n in differences}))
            (directory / 'resolved-alignment.json').write_text(json.dumps(edits, indent=2) + '\n')
            (directory / 'resolved.txt').write_text('\n'.join(
                f'{offset:04x} {fnalign.disassemble(resolved[offset:offset+4], ADDRESS+offset)}'
                for offset in range(0,len(resolved),4)) + '\n')
    sections = []
    data_negative_controls = []
    for section in obj.sections:
        if not section['size'] or not section['flags'] & 2 or section['flags'] & 4:
            continue
        raw = bytes(section['size']) if section['type'] == 8 else obj.data[section['offset']:section['offset']+section['size']]
        resolved, bindings = resolve(raw, section_relocations(obj, section['idx']), values, bases, gp)
        base = bases.get(section['idx'])
        sections.append(dict(name=section['name'], bytes=len(raw), type=section['type'],
            alignment=section['addralign'], base=base, raw_sha256=SHA(raw),
            resolved_sha256=SHA(resolved), relocations=bindings,
            retail_equal=base is not None and resolved == retail.bytes_at(base,len(resolved))))
        if bindings and sections[-1]['retail_equal']:
            chosen = bindings[0]['symbol']
            changed = dict(values, **{chosen:values[chosen]+4})
            wrong, _ = resolve(raw, section_relocations(obj,section['idx']),changed,bases,gp)
            assert wrong != resolved and wrong != retail.bytes_at(base,len(wrong))
            data_negative_controls.append(dict(section=section['name'],
                binding=chosen+' + 4', rejected=True))
    report = dict(label=label, native=score['native'], source_sha256=score['source_sha256'],
        object_sha256=score['object_sha256'], logical_owner=score['logical_owner'],
        compiled_source=score['compiled_source'], flags=score['flags'],
        compiled_source_sha256=score.get('compiled_source_sha256',score['source_sha256']),
        compiler_sha256=SHA(Path(V.unit_compiler(OWNER,cfg)).read_bytes()),
        compiler_name=Path(V.unit_compiler(OWNER,cfg)).name,
        retail_sha1=windows['sha1'], counts=dict(Counter(row['status'] for row in functions)),
        functions=functions, allocated_data=sections, owned_data_exact=all(s['retail_equal'] for s in sections),
        data_witnesses=[m['name'] for m in witnesses],
        emitted_functions=emitted_functions, executable_coverage=executable_coverage,
        code_relocations=sum(len(f['relocations']) for f in functions),
        data_relocations=sum(len(s['relocations']) for s in sections))
    # Use an exact sibling for a strict negative control, including native
    # runs whose requested target remains unmatched.
    witness = next(m for m in witnesses if any(r['r_type'] == 4 for r in obj.function(m['name'])[1]))
    code, references = obj.function(witness['name'])
    chosen = next(r['symbol'] for r in references if r['r_type'] == 4)
    correct, _ = resolve(code,references,values,bases,gp)
    changed = dict(values)
    changed[chosen] = V.resolve_symbol(chosen,gp,values) + 4
    wrong, _ = resolve(code,references,changed,bases,gp)
    target = retail.bytes_at(witness['addr'],len(correct))
    assert correct == target and wrong != target
    report['negative_controls'] = dict(code={'function':witness['name'],
        'binding':chosen+' + 4', 'rejected':True}, data=data_negative_controls)
    (directory / 'proof.json').write_text(json.dumps(report,indent=2) + '\n')
    target = next(row for row in functions if row['name'] == FUNCTION)
    print(json.dumps({key:report[key] for key in ('label','counts','owned_data_exact','code_relocations','data_relocations')} |
        {key:target[key] for key in ('bytes','window','resolved_byte_differences','resolved_word_differences','alignment_edits','tail_all_zero')}), flush=True)
    return report


def canonical_bindings(bindings):
    """Compiler-local names may change; their independently resolved targets may not."""
    return [{key:value for key,value in entry.items() if key != 'symbol'} for entry in bindings]


def compare_preserved(before, after):
    before_functions = {f['name']:f for f in before['functions']}
    after_functions = {f['name']:f for f in after['functions']}
    assert before_functions.keys() == after_functions.keys()
    checked = []
    for name, original in before_functions.items():
        if name == FUNCTION:
            continue
        current = after_functions[name]
        for key in ('address','bytes','window','raw_sha256','resolved_sha256',
                    'resolved_byte_differences','tail_bytes','tail_all_zero'):
            assert original[key] == current[key], (name,key)
        assert current['status'] == 'MATCH'
        assert canonical_bindings(original['relocations']) == canonical_bindings(current['relocations']),name
        checked.append(name)
    assert len(checked) == 15
    assert before['owned_data_exact'] and after['owned_data_exact']
    assert len(before['allocated_data']) == len(after['allocated_data'])
    for original,current in zip(before['allocated_data'],after['allocated_data']):
        for key in ('name','bytes','type','alignment','base','raw_sha256','resolved_sha256'):
            assert original[key] == current[key],('data',key)
        assert canonical_bindings(original['relocations']) == canonical_bindings(current['relocations'])
    return dict(siblings=checked, sibling_bytes_and_bindings_equal=True,
                allocated_storage_and_bindings_equal=True)


def main():
    global OUT
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',help='New directory below build; defaults to a unique scratch directory.')
    args = parser.parse_args()
    if args.output:
        OUT = (ROOT / args.output).resolve()
        OUT.relative_to((ROOT/'build').resolve())
        OUT.mkdir(parents=True,exist_ok=False)
    else:
        OUT = Path(tempfile.mkdtemp(prefix='sprite-render-proof-',dir=ROOT/'build'))
    baseline_blob = '1675f5180285f3fc22ad5dcd0bb1644b009ee26e'
    result = subprocess.run(['git','cat-file','blob',baseline_blob],cwd=ROOT,
                            stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True)
    previous = result.stdout.decode('utf-8').replace('\r\n','\n')
    current = OWNER.read_text(encoding='utf-8')
    proofs = {}
    # These are complete-owner compilations. The current pair compiles the
    # physical repository path, and the old pair uses its immutable git blob.
    for label,source,native,physical in [
        ('baseline-native',previous,True,None),
        ('baseline-asm',previous,False,None),
        ('installed-native',current,True,OWNER),
        ('installed-asm',current,False,OWNER),
    ]:
        compile_source(label,source,native,physical)
        proofs[label] = proof(label)
    preservation = {}
    for kind in ('native','asm'):
        preservation[kind] = compare_preserved(proofs['baseline-'+kind],proofs['installed-'+kind])
    for label in ('baseline-asm','installed-asm'):
        target = next(f for f in proofs[label]['functions'] if f['name'] == FUNCTION)
        assert target['status'] == 'ASM' and target['bytes'] == target['window'] == 7808
        assert target['resolved_byte_differences'] == 0
    old_target = next(f for f in proofs['baseline-asm']['functions'] if f['name'] == FUNCTION)
    new_target = next(f for f in proofs['installed-asm']['functions'] if f['name'] == FUNCTION)
    assert old_target['raw_sha256'] == new_target['raw_sha256']
    assert old_target['resolved_sha256'] == new_target['resolved_sha256']
    assert canonical_bindings(old_target['relocations']) == canonical_bindings(new_target['relocations'])
    cfg = V.load_config()
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
    axis = struct.unpack('<3f',retail.bytes_at(0x007130D8,12))
    dispatch = struct.unpack('<6I',retail.bytes_at(0x0070C2E0,24))
    assert axis == (0.0,0.0,1.0) and dispatch[4] == 0x0040BAC0
    receipt = dict(function=FUNCTION, baseline_git_blob=baseline_blob,
        logical_owner=OWNER.relative_to(ROOT).as_posix(),
        owner_physical_sha256=SHA(OWNER.read_bytes()),
        proofs=proofs, preservation=preservation,
        production_assembly_byte_identical=True,
        consumer_data=dict(axis_address=0x007130D8,axis=list(axis),
                           dispatch_address=0x0070C2E0,primitive_four_consumer=dispatch[4]))
    (OUT/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print('Complete owner/data receipts: '+(OUT/'receipt.json').relative_to(ROOT).as_posix())


if __name__ == '__main__':
    main()
