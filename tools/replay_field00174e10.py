#!/usr/bin/env python3
"""Bounded whole-owner replay. Requires existing authorized compiler/retail inputs.

No provider source is inspected. Output is a path-free receipt; transient source,
objects and compiler diagnostics stay in a deleted temporary directory.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile

sys.dont_write_bytecode = True
import verify as V
import model_replay_elf as A
from replay_model00471370 import metrics

OWNER = 'src/promoted/k_fldEvent.c'
BASELINE = '1e0ce8a012b3ca8762d19bf14119bf52aa280a5d'
SOURCE_SHA256 = '0ba2684b49c11e82bb3a8138b2221a8f5cc4b369125225812d67cf5bca91f232'
TARGET = 'func_00174e10'
sha = lambda data: hashlib.sha256(data).hexdigest()


class ReplayError(RuntimeError):
    pass


def require(condition, message):
    if not condition:
        raise ReplayError(message)


def enable_target(source):
    source, count = re.subn(rb'(// FUN_00174E10 NONMATCHING\r?\n)#ifdef NON_MATCHING',
                            rb'\g<1>#if 1', source)
    require(count == 1, 'target guard missing or duplicated')
    return source


def allocated(obj):
    """Section-local byte/relocation identities, excluding executable sections."""
    result = []
    for sec in obj.sections:
        if not sec['flags'] & 2 or sec['flags'] & 4:
            continue
        raw = bytes(sec['size']) if sec['type'] == 8 else obj.data[sec['offset']:sec['offset'] + sec['size']]
        result.append((sec['name'], sec['type'], sec['size'], sec['flags'], sec['addralign'],
                       sha(raw), A.refs(obj, sec['idx'])))
    return result


def analyze(obj, source, retail, windows):
    markers = {m['name']: m for m in V.scan_markers(source)}
    definitions = [s for s in obj.symbols if s['info'] & 15 == 2
                   and 0 < s['shndx'] < len(obj.sections) and s['size']]
    require(len(markers) == 26 and {s['name'] for s in definitions} == set(markers), 'owner census changed')
    bases = {}
    for sym in definitions:
        base = markers[sym['name']]['addr'] - sym['value']
        require(bases.setdefault(sym['shndx'], base) == base, 'ambiguous code base')
    siblings, controls, target = {}, set(), {}
    refs_count = 0
    for sym in definitions:
        name = sym['name']
        raw, refs = obj.function(name)
        linked, bindings = A.resolve(obj, raw, refs, bases)
        require(not any('error' in r for r in bindings), 'unresolved code reference')
        refs_count += len(bindings)
        addr = markers[name]['addr']
        rw = retail.bytes_at(addr, windows[f'{addr:08x}'])
        exact = len(linked) <= len(rw) and linked == rw[:len(linked)] and not any(rw[len(linked):])
        if name != TARGET:
            require(exact, 'sibling differs from retail')
            siblings[name] = (sha(raw), sha(linked), len(raw), refs)
        else:
            words = struct.unpack('<%dI' % (len(rw) // 4), rw)
            live = max(i * 4 + 8 for i, word in enumerate(words) if word == 0x03e00008)
            require(not any(rw[live:]), 'nonzero alignment tail')
            words_of = lambda b: struct.unpack('<%dI' % (len(b) // 4), b)
            calls = lambda b: [(w & 0x3ffffff) << 2 for w in words_of(b) if w >> 26 == 3]
            gp_refs = lambda b: [(w >> 26, A.gp + (w & 32767) - (w & 32768)) for w in words_of(b)
                                 if (w >> 21 & 31) == 28 and (w >> 26 >= 32 or w >> 26 in (8, 9))]
            target = dict(metrics=metrics(rw[:live], linked), frame=-struct.unpack_from('<h', raw)[0],
                          retail_frame=-struct.unpack_from('<h', rw)[0], exact=exact,
                          raw_sha256=sha(raw), resolved_sha256=sha(linked),
                          calls_equal=calls(linked) == calls(rw), gp_equal=gp_refs(linked) == gp_refs(rw))
        for kind in (4, 5, 7, 8):
            key = ('target' if name == TARGET else 'sibling', kind)
            if key in controls:
                continue
            ref = next((r for r in bindings if r['r_type'] == kind and r.get('symbol')), None)
            if ref:
                wrong, wr = A.resolve(obj, raw, refs, bases, {ref['symbol']: ref['address'] + 4})
                require(not any('error' in r for r in wr) and wrong != linked, 'ineffective reference control')
                require(not exact or wrong != rw[:len(wrong)], 'wrong reference accepted')
                controls.add(key)
    # No new owned-data binding is asserted: all allocated non-text bytes and
    # relocations must equal current-main, and production object identity is exact.
    return dict(siblings=siblings, target=target, references=refs_count,
                negative_controls=sorted(controls), data=allocated(obj))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--baseline', default=BASELINE, help='current-main commit to compare')
    args = parser.parse_args()
    repo = V.REPO
    for key in ('P4_MWCC', 'P4_RETAIL_ELF', 'P4_AS'):
        require(bool(os.environ.get(key)) and Path(os.environ[key]).is_file(), 'set authorized ' + key)
    cfg = V.load_config()
    require(not any('NON_MATCHING' in f for f in V.unit_compile_flags(repo / OWNER, cfg['compile_flags'])),
            'global NON_MATCHING is forbidden')
    current = (repo / OWNER).read_bytes()
    require(sha(current) == SOURCE_SHA256, 'reviewed source binding changed')
    baseline = subprocess.check_output(['git', 'show', args.baseline + ':' + OWNER], cwd=repo, stderr=subprocess.PIPE)
    target_config = V._read_json(V.TARGET)
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg['retail_elf'], target_config, windows['sha1'])
    values = {}
    for filename in ('symbol_addrs.txt', 'symbol_data_addrs.txt', 'symbols_recovered.txt'):
        for line in (repo / 'config' / filename).read_text().splitlines():
            match = re.match(r'\s*([\w.$]+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;', line)
            if match:
                name, value = match[1], int(match[2], 16)
                require(values.setdefault(name, value) == value, 'symbol values conflict')
    A.V, A.values, A.gp = V, values, int(target_config['elf']['gp'], 0)
    with tempfile.TemporaryDirectory(prefix='field00174e10-') as temp:
        work = Path(temp)
        env = dict(os.environ, PYTHONDONTWRITEBYTECODE='1', TMPDIR=temp, TEMP=temp, TMP=temp)
        def compile_owner(label, source, skip_asm=False):
            path, output = work / (label + '.c'), work / (label + '.o')
            path.write_bytes(source)
            command = V._mwccgap_command(repo / OWNER, cfg, output)
            command[2] = str(path)
            if skip_asm:
                command.append('--skip-asm')
            proc = subprocess.run(command, cwd=repo, env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=300)
            require(proc.returncode == 0 and output.is_file(), 'compile failed: ' + label)
            return path, V.ObjectFile(output)
        bp, bo = compile_owner('baseline-spliced', baseline)
        cp, co = compile_owner('current-spliced', current)
        ep, eo = compile_owner('target-spliced', enable_target(current))
        _, repeat = compile_owner('target-repeat', enable_target(current))
        _, bc = compile_owner('baseline-c-only', baseline, True)
        _, cc = compile_owner('current-c-only', current, True)
        require(bo.data == co.data, 'production spliced object changed')
        require(bc.data == cc.data, 'production C-only object changed')
        require(eo.data == repeat.data, 'repeat object differs')
        base = analyze(bo, bp, retail, windows['windows'])
        candidate = analyze(eo, ep, retail, windows['windows'])
        require(base['target']['exact'], 'production target differs from retail')
        require(candidate['siblings'] == base['siblings'], 'sibling byte/relocation identity changed')
        require(candidate['data'] == base['data'], 'allocated data byte/relocation identity changed')
        t = candidate['target']
        require(t['metrics']['unit_word_levenshtein'] == 10 and t['metrics']['candidate_bytes'] == 3976
                and t['metrics']['retail_bytes'] == 3992 and t['frame'] == t['retail_frame'] == 0x130,
                'accepted target metrics changed')
        require(t['calls_equal'] and t['gp_equal'], 'call or GP destinations changed')
        require(len(candidate['negative_controls']) >= 6, 'reference control coverage decreased')
        result = dict(status='PASS; remains NONMATCHING', baseline_commit=args.baseline,
                      baseline_source_sha256=sha(baseline), source_sha256=sha(current), target=t,
                      production_spliced_identical=True, production_spliced_object_sha256=sha(co.data),
                      production_c_only_identical=True, production_c_only_object_sha256=sha(cc.data),
                      candidate_object_sha256=sha(eo.data), repeated_identical=True,
                      unchanged_siblings=len(candidate['siblings']), unchanged_allocated_nontext_sections=len(candidate['data']),
                      references=candidate['references'], actual_reference_errors=0,
                      rejected_reference_controls=candidate['negative_controls'])
    print(json.dumps(result, indent=2, sort_keys=True))


if __name__ == '__main__':
    try:
        main()
    except Exception as error:
        print(json.dumps(dict(status='FAIL', error=str(error) if type(error) is ReplayError else type(error).__name__)))
        sys.exit(1)
