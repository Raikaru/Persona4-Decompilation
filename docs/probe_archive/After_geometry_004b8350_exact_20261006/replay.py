"""Reproduce complete native-owner proof for the exact After geometry recovery."""
from pathlib import Path
import argparse
import json
import sys

HERE = Path(__file__).resolve().parent
ROOT = next(path for path in HERE.parents if (path / 'tools/verify.py').is_file())
sys.path[:0] = [str(HERE), str(ROOT / 'tools')]
import owner_evidence as E
import verify as V
import probe_variants as P
import measure_guarded as M
import fnalign as A


def save(path, data):
    path.write_text(json.dumps(data, indent=2) + '\n', encoding='utf-8')


def force(source, address):
    marker, name = 'FUN_' + address.upper(), 'func_' + address
    body = M.extract_guarded_body(source, marker, name)
    return P.splice_region(source, *P.region_for(source, marker, name), body, '\n')


def compile_owner(out, source, logical, excluded, cfg, windows, retail):
    out.mkdir()
    path = out / 'owner.c'
    path.write_text(source, encoding='utf-8')
    objpath = out / 'owner.o'
    with P.scratch_source(logical) as temporary:
        temporary.write_text(source, encoding='utf-8')
        ok, log = P._compile_in_context(temporary, logical, cfg, objpath)
    (out / 'owner.log').write_text(log, encoding='utf-8')
    assert ok, log
    markers = {marker['name']: marker for marker in V.scan_markers(path)}
    obj = V.ObjectFile(objpath)
    bases, data_proof = E.prove_data(obj, markers, retail, exclude=excluded)
    functions = {}
    for name, marker in markers.items():
        address = marker['addr']
        native = retail.bytes_at(address, windows['windows'][f'{address:08x}'])
        code, relocations = obj.function(name)
        resolved, references, offsets = E.resolve_function(obj, name, native, bases)
        functions[name] = {
            'address': f'{address:08x}', 'classification': 'ASM' if marker.get('asm') else 'C',
            'size': len(code), 'window': len(native), 'code_sha256': E.sha(code),
            'relocations': E.canonical_relocs(obj, relocations),
            'resolved_sha256': E.sha(resolved), 'resolved_words': len(offsets),
            'resolved_offsets': offsets, 'resolved_relocations': references,
        }
        if name in ('func_004b8350', 'func_004b8f40', 'func_004b6030'):
            (out / (name + '-resolved.bin')).write_bytes(resolved)
    report = {'source_sha256': E.sha(path.read_bytes()), 'object_sha256': E.sha(obj.data),
              'functions': functions, 'data_sections': E.data_summary(obj),
              'data_relocations': E.canonical_data_relocs(obj), 'data_proof': data_proof,
              'data_placement_excluded': excluded}
    save(out / 'owner-proof.json', report)
    print(out.name, {name: (row['size'], row['resolved_words']) for name, row in functions.items()
                     if name in ('func_004b8350', 'func_004b8f40', 'func_004b6030')}, flush=True)
    return report


def equal_siblings(before, after, excluded=()):
    def rows(report):
        return {name: {key: row[key] for key in ('size', 'code_sha256', 'relocations')}
                for name, row in report['functions'].items() if name not in excluded}
    assert rows(before) == rows(after), 'A sibling payload or relocation changed'
    assert before['data_sections'] == after['data_sections'], 'Allocated data changed'
    assert before['data_relocations'] == after['data_relocations'], 'Allocated data references changed'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path, default=HERE / 'proof')
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    binding = json.loads((HERE / 'source-binding.json').read_text())
    for name, expected in binding['sources'].items():
        assert E.sha((HERE / name).read_bytes()) == expected, name
    cfg = V.load_config()
    windows = V._read_json(V.FUNCTION_WINDOWS)
    retail = V.RetailElf(cfg['retail_elf'], V._read_json(V.TARGET), windows['sha1'])
    sources = ['after-original.c', 'after-reviewed32.c', 'after-promoted.c',
               'afpack-original.c', 'afpack-caller.c']
    inputs = {}
    for name in sources:
        inputs.update(E.header_closure(HERE / name))
    for path in (ROOT / 'tools/verify.py', ROOT / 'tools/probe_variants.py', ROOT / 'tools/measure_guarded.py',
                 ROOT / 'config/symbol_addrs.txt', ROOT / 'config/symbol_data_addrs.txt',
                 V.FUNCTION_WINDOWS, V.TARGET, HERE / 'owner_evidence.py', HERE / 'replay.py'):
        inputs[Path(path)] = E.sha(Path(path).read_bytes())
    cases = [
        ('after-original-default', 'after-original.c', []),
        ('after-original-all-guards', 'after-original.c', ['004b8350', '004b8f40']),
        ('after-reviewed32-all-guards', 'after-reviewed32.c', ['004b8350', '004b8f40']),
        ('after-promoted-default', 'after-promoted.c', []),
        ('after-promoted-all-guards', 'after-promoted.c', ['004b8f40']),
        ('afpack-original-default', 'afpack-original.c', []),
        ('afpack-original-all-guards', 'afpack-original.c', ['004b6030']),
        ('afpack-caller-default', 'afpack-caller.c', []),
        ('afpack-caller-all-guards', 'afpack-caller.c', ['004b6030']),
    ]
    reports, contexts = {}, {}
    for label, filename, enabled in cases:
        after = label.startswith('after-')
        logical = ROOT / ('src/Graphics/Effect/eff_after.c' if after else 'src/Graphics/Effect/eff_afpack.c')
        compiler = Path(V.unit_compiler(logical, cfg))
        contexts[logical.relative_to(ROOT).as_posix()] = {
            'compiler': str(compiler), 'compiler_sha256': E.sha(compiler.read_bytes()),
            'flags': V.unit_compile_flags(logical, cfg['compile_flags']),
        }
        source = (HERE / filename).read_text()
        for address in enabled:
            source = force(source, address)
        excluded = ['func_004b8350', 'func_004b8f40'] if after else ['func_004b6030']
        reports[label] = compile_owner(out / label, source, logical, excluded, cfg, windows, retail)
        save(out / 'owner-proof.json', {'source_binding': binding, 'contexts': contexts, 'owners': reports})
    equal_siblings(reports['after-original-default'], reports['after-promoted-default'], ['func_004b8350'])
    equal_siblings(reports['after-original-all-guards'], reports['after-promoted-all-guards'], ['func_004b8350'])
    equal_siblings(reports['after-reviewed32-all-guards'], reports['after-promoted-all-guards'], ['func_004b8350'])
    equal_siblings(reports['afpack-original-default'], reports['afpack-caller-default'])
    equal_siblings(reports['afpack-original-all-guards'], reports['afpack-caller-all-guards'])
    for label in ('after-original-default', 'after-promoted-default', 'afpack-original-default', 'afpack-caller-default'):
        assert all(row['resolved_words'] == 0 for row in reports[label]['functions'].values()), label
    for label in ('after-promoted-default', 'after-promoted-all-guards'):
        target = reports[label]['functions']['func_004b8350']
        assert target['classification'] == 'C' and target['size'] == target['window'] == 2720 and target['resolved_words'] == 0
    for path, digest in inputs.items():
        assert E.sha(path.read_bytes()) == digest, 'Input drift: ' + str(path)
    save(out / 'owner-proof.json', {'source_binding': binding, 'contexts': contexts,
         'inputs': {str(path.relative_to(ROOT)): digest for path, digest in inputs.items()},
         'retail_sha1': windows['sha1'], 'owners': reports,
         'checks': {'all_sibling_payloads_preserved': True, 'all_allocated_data_preserved': True,
                    'native_default_owners_exact': True, 'promoted_target_exact_in_both_modes': True,
                    'input_drift': []}})
    print('All complete owner checks passed.', flush=True)


if __name__ == '__main__':
    main()
