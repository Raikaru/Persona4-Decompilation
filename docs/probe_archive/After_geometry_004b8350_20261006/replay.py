"""Replay the complete-owner proof using only this package and tracked tools.

Run from anywhere inside a configured checkout. Sources in src are never edited.
An existing output directory is refused so earlier measurements stay immutable.
"""
from pathlib import Path
import argparse
import json
import sys

HERE = Path(__file__).resolve().parent
ROOT = next(p for p in HERE.parents if (p / 'tools/verify.py').is_file())
sys.path.insert(0, str(ROOT / 'tools'))
import verify as V
import probe_variants as P
import measure_guarded as M
import owner_evidence as E


def save(path, data):
    path.write_text(json.dumps(data, indent=2) + '\n', encoding='utf-8')


def force_target(source, address):
    marker = 'FUN_' + address.upper()
    name = 'func_' + address
    body = M.extract_guarded_body(source, marker, name)
    return P.splice_region(source, *P.region_for(source, marker, name), body, '\n')


def compare_owner(out, label, source, logical, target_address, forced, cfg, windows, retail):
    if forced:
        source = force_target(source, target_address)
    source_path = out / (label + '.c')
    source_path.write_text(source, encoding='utf-8')
    object_path = out / (label + '.o')
    with P.scratch_source(logical) as temp:
        temp.write_text(source, encoding='utf-8')
        ok, log = P._compile_in_context(temp, logical, cfg, object_path)
    (out / (label + '.log')).write_text(log, encoding='utf-8')
    assert ok, log
    markers = {m['name']: m for m in V.scan_markers(source_path)}
    obj = V.ObjectFile(object_path)
    excluded = ['func_' + target_address] if forced else []
    bases, data_proof = E.prove_data(obj, markers, retail, exclude=excluded)
    functions = {}
    for name, marker in markers.items():
        address = marker['addr']
        target = retail.bytes_at(address, windows['windows'][f'{address:08x}'])
        code, relocs = obj.function(name)
        resolved, references, differences = E.resolve_function(obj, name, target, bases)
        functions[name] = {
            'address': f'{address:08x}', 'classification': 'ASM' if marker.get('asm') else 'C',
            'size': len(code), 'window': len(target), 'code_sha256': E.sha(code),
            'relocations': E.canonical_relocs(obj, relocs),
            'resolved_sha256': E.sha(resolved), 'resolved_words': len(differences),
            'resolved_offsets': differences, 'resolved_relocations': references,
        }
        if name == 'func_' + target_address:
            (out / (label + '-resolved.bin')).write_bytes(resolved)
    result = {
        'source_sha256': E.sha(source_path.read_bytes()), 'object_sha256': E.sha(obj.data),
        'functions': functions, 'data_sections': E.data_summary(obj),
        'data_relocations': E.canonical_data_relocs(obj), 'data_proof': data_proof,
    }
    print(label, 'compiled', len(functions), 'functions;', functions['func_' + target_address]['resolved_words'],
          'resolved target words', flush=True)
    return result


def same_payload(a, b, excluded=()):
    def rows(report):
        return {name: {key: row[key] for key in ('size', 'code_sha256', 'relocations')}
                for name, row in report['functions'].items() if name not in excluded}
    assert rows(a) == rows(b), 'A function or relocation changed'
    assert a['data_sections'] == b['data_sections'], 'Allocated data changed'
    assert a['data_relocations'] == b['data_relocations'], 'Data relocation changed'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, default=HERE / 'proof')
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    manifest = json.loads((HERE / 'inputs.json').read_text())
    for name, expected in manifest['inputs'].items():
        assert E.sha((HERE / name).read_bytes()) == expected, name
    cfg = V.load_config()
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg['retail_elf'], V._read_json(V.TARGET), windows['sha1'])
    report = {'input_manifest': manifest, 'contexts': {}, 'owners': {}}
    for owner, prefix, address, proposal in [
            ('src/Graphics/Effect/eff_after.c', 'after', '004b8350', 'after-guarded.c'),
            ('src/Graphics/Effect/eff_afpack.c', 'afpack', '004b6030', 'afpack-caller.c')]:
        logical = ROOT / owner
        initial_owner = logical.read_bytes()
        baseline = (HERE / (prefix + '-baseline.c')).read_text()
        candidate = (HERE / proposal).read_text()
        compiler = Path(V.unit_compiler(logical, cfg))
        report['contexts'][owner] = {
            'live_source_sha256': E.sha(initial_owner),
            'compiler_filename': compiler.name, 'compiler_sha256': E.sha(compiler.read_bytes()),
            'flags': V.unit_compile_flags(logical, cfg['compile_flags']),
            'headers': {p.relative_to(ROOT).as_posix(): digest for p, digest in E.header_closure(logical).items()},
        }
        variants = [('baseline-default', baseline, False), ('candidate-default', candidate, False),
                    ('candidate-forced', candidate, True)]
        if prefix == 'after':
            variants.append(('reviewed-forced', (HERE / 'after-reviewed.c').read_text(), True))
        else:
            variants.append(('baseline-forced', baseline, True))
        runs = {name: compare_owner(out, prefix + '-' + name, source, logical, address, forced,
                                   cfg, windows, retail) for name, source, forced in variants}
        same_payload(runs['baseline-default'], runs['candidate-default'])
        same_payload(runs['candidate-default'], runs['candidate-forced'], excluded=['func_' + address])
        if prefix == 'after':
            same_payload(runs['reviewed-forced'], runs['candidate-forced'])
            target = runs['candidate-forced']['functions']['func_004b8350']
            assert target['size'] == target['window'] == 2720
            assert target['resolved_words'] == 32
        else:
            same_payload(runs['baseline-forced'], runs['candidate-forced'])
            assert runs['candidate-default']['functions']['func_004b6900']['resolved_words'] == 0
        assert logical.read_bytes() == initial_owner, 'Source owner changed during replay'
        report['owners'][owner] = runs
    after = report['owners']['src/Graphics/Effect/eff_after.c']['candidate-default']['functions']
    afpack = report['owners']['src/Graphics/Effect/eff_afpack.c']['candidate-default']['functions']
    assert all(row['resolved_words'] == 0 for row in list(after.values()) + list(afpack.values()))
    report['conclusion'] = {
        'default_owners_fully_resolved_and_unchanged': True,
        'after_formatting_forced_code_and_relocations_unchanged': True,
        'afpack_caller_default_and_forced_code_and_relocations_unchanged': True,
        'all_siblings_unchanged': True, 'all_allocated_data_resolved_and_retail_equal': True,
        'after_classification': {'C': sum(r['classification'] == 'C' for r in after.values()),
                                 'ASM': sum(r['classification'] == 'ASM' for r in after.values())},
        'afpack_classification': {'C': sum(r['classification'] == 'C' for r in afpack.values()),
                                  'ASM': sum(r['classification'] == 'ASM' for r in afpack.values())},
        'after_candidate_resolved_words': 32, 'after_candidate_bytes': 2720,
        'new_exact_C': 0, 'production_source_changed': False,
    }
    report['replay_inputs'] = {name: E.sha((HERE / name).read_bytes()) for name in
                               ('replay.py', 'owner_evidence.py', 'inputs.json')}
    report['verification_inputs'] = {path.relative_to(ROOT).as_posix(): E.sha(path.read_bytes()) for path in
                                     [V.FUNCTION_WINDOWS, V.TARGET, ROOT / 'tools/verify.py',
                                      ROOT / 'tools/probe_variants.py', ROOT / 'tools/measure_guarded.py',
                                      ROOT / 'config/symbol_addrs.txt', ROOT / 'config/symbol_data_addrs.txt']}
    save(out / 'owner-proof.json', report)
    print(json.dumps(report['conclusion'], indent=2), flush=True)


if __name__ == '__main__':
    main()
