"""Replay the exact follower proposal in private whole-owner builds.

Accept the recorded baseline or installed proposal, authenticate the text patch,
and reconstruct both source versions in memory. No production file is modified.
All emitted objects and detailed proofs stay in the chosen build directory.
"""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ARCHIVE = Path(__file__).resolve().parent
ROOT = next(p for p in ARCHIVE.parents if (p / 'tools/verify.py').is_file() and (p / 'src').is_dir())
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'docs/probe_archive')]
import build as B
import probe_variants as P
import verify as V
from Field_axis_contract_20261005_proof import prove
from Field_AI_follower_0017d3c0_20261005_proof import resolve


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def save(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')


def apply_recorded_patch(raw, patch, reverse=False):
    """Apply one authenticated unified diff, checking every preimage line."""
    source = raw.decode('utf-8').splitlines(keepends=True)
    lines = patch.decode('utf-8').splitlines(keepends=True)
    output, position, cursor = [], 0, 0
    hunks = 0
    while cursor < len(lines):
        match = re.match(r'^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@', lines[cursor])
        if not match:
            assert lines[cursor].startswith(('--- ', '+++ ')), lines[cursor]
            cursor += 1
            continue
        old_start, old_count = int(match[1]), int(match[2] or 1)
        new_start, new_count = int(match[3]), int(match[4] or 1)
        start = (new_start if reverse else old_start) - 1
        assert start >= position
        output.extend(source[position:start])
        position = start
        cursor += 1
        consumed = added = 0
        while cursor < len(lines) and not lines[cursor].startswith('@@ '):
            line = lines[cursor]
            assert line and line[0] in ' +-', line
            operation, payload = line[0], line[1:]
            if reverse and operation != ' ':
                operation = '+' if operation == '-' else '-'
            if operation in (' ', '-'):
                assert position < len(source) and source[position] == payload, (hunks, position + 1)
                position += 1
                consumed += 1
            if operation in (' ', '+'):
                output.append(payload)
                added += 1
            cursor += 1
        assert consumed == (new_count if reverse else old_count)
        assert added == (old_count if reverse else new_count)
        hunks += 1
    assert hunks
    output.extend(source[position:])
    return ''.join(output).encode('utf-8')


def canonical(obj, relocs):
    gp, symbols = V.symbol_addresses()
    result = []
    for original in relocs:
        row = dict(original)
        name = row['symbol']
        if name and name.startswith('@'):
            symbol, = [s for s in obj.symbols if s['name'] == name and s['shndx'] != 0]
            section = obj.sections[symbol['shndx']]
            assert not section['flags'] & 4
            raw = obj.data[section['offset']:section['offset'] + section['size']]
            row['symbol'] = {'section': section['name'], 'size': section['size'],
                             'value': symbol['value'], 'payload_sha256': sha(raw)}
        else:
            address = V.resolve_symbol(name or '', gp, symbols)
            row['symbol'] = {'address': address} if address is not None else name
        result.append(row)
    return result


def owned_data(obj):
    result = []
    for section in obj.sections:
        if not section['flags'] & 2 or section['flags'] & 4:
            continue
        raw = obj.data[section['offset']:section['offset'] + section['size']] if section['type'] != 8 else bytes(section['size'])
        result.append({'section': section['name'], 'type': section['type'], 'size': section['size'],
            'alignment': section['addralign'], 'flags': section['flags'], 'payload_sha256': sha(raw),
            'relocations': B.section_relocs(obj, section['idx'])})
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--hashes-only', action='store_true')
    parser.add_argument('--out', type=Path, default=ROOT / 'build/field-follower-exact-replay')
    args = parser.parse_args()
    receipt = json.loads((ARCHIVE / 'receipt.json').read_text(encoding='utf-8'))
    for relative, expected in receipt['archive_payload_sha256'].items():
        assert sha((ARCHIVE / relative).read_bytes()) == expected, relative
    for relative, expected in receipt['project_inputs'].items():
        assert sha((ROOT / relative).read_bytes()) == expected, relative
    owner = ROOT / receipt['owner']
    actual = owner.read_bytes()
    patch = (ARCHIVE / 'proposal.patch').read_bytes()
    if sha(actual) == receipt['baseline_source_sha256']:
        baseline, proposal = actual, apply_recorded_patch(actual, patch)
        phase = 'baseline'
    else:
        assert sha(actual) == receipt['proposal_source_sha256'], 'Owner is neither recorded source version'
        proposal, baseline = actual, apply_recorded_patch(actual, patch, reverse=True)
        phase = 'installed'
    assert sha(baseline) == receipt['baseline_source_sha256']
    assert sha(proposal) == receipt['proposal_source_sha256']
    assert apply_recorded_patch(proposal, patch, reverse=True) == baseline
    assert apply_recorded_patch(baseline, patch) == proposal
    print('Authenticated archive, project inputs, and both source versions; phase:', phase, flush=True)
    if args.hashes_only:
        return
    out = args.out.resolve()
    out.relative_to(ROOT / 'build')
    assert not out.exists(), 'Choose a fresh --out; prior evidence is immutable'
    out.mkdir(parents=True)
    (out / 'baseline.c').write_bytes(baseline)
    (out / 'proposal.c').write_bytes(proposal)
    cfg = V.load_config()
    assert sha(Path(V.unit_compiler(owner, cfg)).read_bytes()) == receipt['compiler_sha256']
    assert V.unit_compile_flags(owner, cfg['compile_flags']) == receipt['compile_flags']
    meta = V._read_json(V.FUNCTION_WINDOWS)
    assert meta['sha1'] == receipt['retail_sha1']
    retail = V.RetailElf(cfg['retail_elf'], V._read_json(V.TARGET), meta['sha1'])
    markers = V.scan_markers(out / 'proposal.c')
    old_markers = V.scan_markers(out / 'baseline.c')
    assert {m['name']: m['addr'] for m in markers} == {m['name']: m['addr'] for m in old_markers}
    objects = {}
    for mode in ('default', 'guarded'):
        for variant, raw in (('baseline', baseline), ('proposal', proposal)):
            key = mode + '-' + variant
            path = out / (key + '.c')
            path.write_bytes((b'#define NON_MATCHING 1\n' if mode == 'guarded' else b'') + raw)
            object_path = out / (key + '.o')
            ok, log = P._compile_in_context(path, owner, cfg, object_path)
            (out / (key + '.compile.log')).write_text(log, encoding='utf-8')
            assert ok, log
            objects[key] = V.ObjectFile(object_path)
    strict = prove(objects['default-proposal'], markers, retail, meta['windows'])
    prove(objects['default-baseline'], old_markers, retail, meta['windows'])
    save(out / 'default-owner-proof.json', strict)
    siblings = []
    targets = {}
    for mode in ('default', 'guarded'):
        before, after = objects[mode + '-baseline'], objects[mode + '-proposal']
        for marker in markers:
            name = marker['name']
            if name == 'func_0017d3c0':
                continue
            a, ar = before.function(name)
            b, br = after.function(name)
            assert a == b and canonical(before, ar) == canonical(after, br), (mode, name)
            siblings.append({'mode': mode, 'name': name, 'bytes': len(b), 'code_sha256': sha(b)})
        assert owned_data(before) == owned_data(after), mode
        target = resolve(after, 'func_0017d3c0', 0x0017D3C0, retail, meta['windows']['0017d3c0'], True)
        assert target['code_bytes'] == 5236 and target['resolved_relocations'] == 118
        assert target['resolved_sha256'] == receipt['target_resolved_sha256']
        targets[mode] = target
        save(out / (mode + '-target-proof.json'), target)
    assert objects['default-proposal'].function('func_0017d3c0') == objects['guarded-proposal'].function('func_0017d3c0')
    raw = retail.bytes_at(0x0017D3C0, 5248)
    expected_calls = [(i * 4, (word & 0x03FFFFFF) << 2) for i, (word,) in enumerate(struct.iter_unpack('<I', raw)) if word >> 26 == 3]
    actual_calls = [(r['offset'], r['symbol_address'] + r['addend']) for r in targets['default']['relocations'] if r['r_type'] == 4]
    assert expected_calls == actual_calls and len(actual_calls) == 92
    for marker in markers:
        code, refs = objects['default-proposal'].function(marker['name'])
        expected = retail.bytes_at(marker['addr'], meta['windows'][f"{marker['addr']:08x}"])
        assert V.compare(code, refs, expected)[0] == 0 and len(code) <= len(expected) and not any(expected[len(code):])
    summary = dict(Counter('ASM' if m.get('asm') else 'MATCH' for m in markers))
    assert summary == {'MATCH': 10, 'ASM': 1}
    assert owner.read_bytes() == actual
    for relative, expected in receipt['project_inputs'].items():
        assert sha((ROOT / relative).read_bytes()) == expected, relative
    result = {'source_phase': phase, 'summary': summary, 'target_bytes': 5236, 'window_bytes': 5248,
        'zero_tail_bytes': 12, 'resolved_target_relocations': 118, 'resolved_differing_words': 0,
        'ordered_direct_calls_identical': 92, 'default_function_count': strict['function_count'],
        'default_resolved_code_relocations': strict['code_relocation_count'],
        'default_owned_data_bytes': strict['owned_data_bytes'], 'sibling_preservation': siblings,
        'owned_data_preserved_both_modes': True, 'production_unchanged': True,
        'objects_sha256': {name: sha(obj.data) for name, obj in objects.items()}}
    save(out / 'completed.json', result)
    print(json.dumps({k: v for k, v in result.items() if k not in ('sibling_preservation', 'objects_sha256')}, indent=2), flush=True)


if __name__ == '__main__':
    main()
