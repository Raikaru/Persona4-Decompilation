#!/usr/bin/env python3
"""Replay actual installed btlEPL default/guarded compiles and strict native proof.

Outputs must be in a private directory below build/. Existing completed modes
are authenticated and reused, never compiled again. No source is modified.
"""
from pathlib import Path
from collections import Counter
import argparse
import hashlib
import json
import os
import re
import subprocess
import sys

sys.dont_write_bytecode = True
import native as N
import probe_variants as P

ARCHIVE = Path(__file__).resolve().parent
EXPECTED_SOURCE = '8f90e0ff43a8a274aecaef5607ca2202a2f30e5fe8aede71cbfc61d3ca187195'
EXPECTED_OBJECTS = {
    'default': '4e5931e137ad15617182f5f169519c110353cb45ba4663810828c3629c55659c',
    'guarded': 'c19771f85df33a8028eb11750078cbf5b037c21ed29918a71c42d2a47f4fb6bf',
}


def load(path):
    return json.loads(path.read_text(encoding='utf-8'))


def save(path, value):
    path.write_text(json.dumps(value, indent=2, sort_keys=True)+'\n', encoding='utf-8')


def file_hash(path):
    return N.digest(path.read_bytes())


def stable_hash(value):
    return N.digest(json.dumps(value, sort_keys=True, separators=(',', ':')).encode())


def inputs():
    paths = set()

    def visit(path):
        path = path.resolve()
        if path in paths:
            return
        path.relative_to(N.ROOT)
        paths.add(path)
        for name in re.findall(r'^\s*#\s*include\s*[<"]([^>"\n]+)', path.read_text(errors='replace'), re.M):
            candidates = [path.parent / name, N.ROOT / 'include' / name]
            selected = next((p for p in candidates if p.is_file()), None)
            if selected is None:
                raise RuntimeError('unresolved include: '+name)
            visit(selected)

    visit(N.OWNER)
    for rel in (
        'tools/verify.py', 'tools/probe_variants.py', 'tools/build.py',
        'tools/build_cache.py', 'tools/asm.py', 'tools/elf_text_runs.py',
        'tools/gnu_link.py', 'tools/fnalign.py', 'tools/eedis.py',
        'tools/decomp_lint.py', 'tools/verify_config.json',
        'config/symbol_addrs.txt', 'config/symbol_data_addrs.txt',
        'config/symbols_recovered.txt', 'config/compiler_units.txt',
        'config/gcc_units.txt', 'config/speed_units.txt', 'config/version_flags.txt',
        'asm/macro.inc',
    ):
        path = N.ROOT / rel
        if path.is_file():
            paths.add(path)
    paths.update((N.ROOT / 'tools/mwccgap').rglob('*.py'))
    paths.update((N.V.FUNCTION_WINDOWS, N.V.TARGET, ARCHIVE / 'native.py', ARCHIVE / 'replay.py'))
    for folder, name in re.findall(r'INCLUDE_ASM\("([^"]+)",\s*(\w+)\)', N.OWNER.read_text()):
        assembly = N.ROOT / folder / (name+'.s')
        if not assembly.is_file():
            raise RuntimeError('regenerate the required assembly fallback before replay')
        paths.add(assembly)
    compiler = Path(N.V.unit_compiler(N.OWNER, N.CFG))
    return dict(files={p.relative_to(N.ROOT).as_posix(): file_hash(p) for p in sorted(paths)},
                compiler=dict(name=compiler.name, sha256=file_hash(compiler)),
                flags=N.V.unit_compile_flags(N.OWNER, N.CFG['compile_flags']),
                retail_sha1=N.WINDOWS['sha1'])


def checked_mode(out, mode, bindings, reuse_only):
    directory = out / mode
    record_path = directory / 'compile.json'
    object_path = directory / 'src_promoted_btlEPL.c.o'
    cfg = dict(N.CFG)
    cfg['compile_flags'] = list(N.CFG['compile_flags']) + (['-DNON_MATCHING'] if mode == 'guarded' else [])
    flags = N.V.unit_compile_flags(N.OWNER, cfg['compile_flags'])
    binding_hash = stable_hash(bindings)
    if record_path.exists():
        record = load(record_path)
        assert record['input_hash'] == binding_hash, 'completed mode input binding changed'
        assert record['source_sha256'] == EXPECTED_SOURCE
        assert record['flags'] == flags
        assert file_hash(directory / 'owner.c') == EXPECTED_SOURCE
        assert file_hash(object_path) == record['object_sha256'] == EXPECTED_OBJECTS[mode]
        assert file_hash(directory / 'official.json') == record['official_sha256']
        print(mode+': authenticated completed mode; no compilation', flush=True)
        return load(directory / 'official.json')
    assert not reuse_only, 'no completed mode available for reuse'
    assert not directory.exists(), 'incomplete output exists: inspect it instead of repeating compilation'
    assert file_hash(N.OWNER) == EXPECTED_SOURCE
    directory.mkdir()
    (directory / 'owner.c').write_bytes(N.OWNER.read_bytes())
    save(directory / 'pending.json', dict(source_sha256=EXPECTED_SOURCE, input_hash=binding_hash, flags=flags))
    boundaries = sorted({int(k, 16) for k in N.WINDOWS['windows']} |
                        {int(k, 16)+v for k, v in N.WINDOWS['windows'].items() if v})
    original_compile = N.V._compile

    def capture(path, config, destination):
        # The actual authoritative owner is the compiler input. Only output is
        # redirected; the standard verifier and owner-specific flags are used.
        assert path.resolve() == N.OWNER.resolve()
        with P._owner_lock(N.OWNER):
            ok, log = original_compile(path, config, destination)
        (directory / 'compiler.log').write_text(log, encoding='utf-8')
        return ok, log

    N.V._compile = capture
    try:
        rows = N.V.verify_file(N.OWNER, cfg, N.RETAIL, boundaries, directory)
    finally:
        N.V._compile = original_compile
    for row in rows:
        row['file'] = N.OWNER.relative_to(N.ROOT).as_posix()
    save(directory / 'official.json', rows)
    assert not any(r['status'] in ('COMPILE_ERROR', 'NO_SYMBOL', 'UNKNOWN_ADDR') for r in rows), rows
    assert file_hash(object_path) == EXPECTED_OBJECTS[mode], 'fresh native object differs from reviewed result'
    assert inputs() == bindings, 'inputs changed during compilation'
    record = dict(source_sha256=EXPECTED_SOURCE, input_hash=binding_hash, flags=flags,
                  object_sha256=file_hash(object_path), official_sha256=file_hash(directory / 'official.json'),
                  compiler_input=N.OWNER.relative_to(N.ROOT).as_posix())
    save(record_path, record)
    print(mode+': fresh actual-owner compile '+str(dict(Counter(r['status'] for r in rows))), flush=True)
    return rows


def compact(default, guarded, diagnosis, official):
    # The strict per-mode proof is retained privately. The portable receipt
    # stores the shared owner once and the only changed function separately.
    target = next(r for r in guarded['functions'] if r['name'] == N.NAME)
    return dict(installed_source_sha256=EXPECTED_SOURCE,
                objects={m: proof['object_sha256'] for m, proof in (('default', default), ('guarded', guarded))},
                official={m: dict(Counter(r['status'] for r in rows)) for m, rows in official.items()},
                default_functions=default['functions'], guarded_target=target,
                guarded_unchanged_siblings=[r['name'] for r in default['functions'] if r['name'] != N.NAME],
                allocated_data=default['allocated_data'], storage_spans=default['storage_spans'],
                executable_sections={m: proof['executable_sections'] for m, proof in (('default', default), ('guarded', guarded))},
                resolved_code_relocations={m: sum(r['relocations'] for r in proof['functions'])
                                           for m, proof in (('default', default), ('guarded', guarded))},
                owned_storage_unchanged=True, all_allocated_bytes_accounted_for=True,
                diagnosis=diagnosis, new_exact_functions=0)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True, help='private output directory below build/')
    parser.add_argument('--reuse-only', action='store_true', help='authenticate and inspect completed objects without compiling')
    parser.add_argument('--record', action='store_true', help='record new evidence before an archive receipt exists')
    args = parser.parse_args()
    out = args.out.resolve()
    out.relative_to((N.ROOT / 'build').resolve())
    assert out != (N.ROOT / 'build').resolve()
    out.mkdir(parents=True, exist_ok=True)
    bindings = inputs()
    assert file_hash(N.OWNER) == EXPECTED_SOURCE, 'installed source changed'
    receipt_path = ARCHIVE / 'receipt.json'
    expected = None if args.record else load(receipt_path)
    if expected:
        assert bindings == expected['inputs'], 'archive input binding changed'
    official = {}
    proofs = {}
    functions = {}
    for mode in ('default', 'guarded'):
        official[mode] = checked_mode(out, mode, bindings, args.reuse_only)
        proofs[mode], functions[mode] = N.inspect(out / mode)
    assert dict(Counter(r['status'] for r in official['default'])) == {'MATCH': 26, 'ASM': 1}
    assert dict(Counter(r['status'] for r in official['guarded'])) == {'MATCH': 26, 'NONMATCHING': 1}
    assert all(r['exact'] for r in proofs['default']['functions'])
    changes = [name for name in functions['default'] if functions['default'][name] != functions['guarded'][name]]
    assert changes == [N.NAME], changes
    signature = lambda proof: sorted((r['address'], r['size'], r['alignment'], r['sha256']) for r in proof['allocated_data'])
    assert signature(proofs['default']) == signature(proofs['guarded'])
    guarded_target = next(r for r in proofs['guarded']['functions'] if r['name'] == N.NAME)
    assert (guarded_target['size'], guarded_target['window'], guarded_target['differing_words'],
            guarded_target['differing_bytes'], guarded_target['relocations'], guarded_target['zero_suffix']) == (2172, 2176, 90, 127, 22, 4)
    diagnosis = N.classify_rotation(functions['guarded'][N.NAME], out)
    assert diagnosis['actual_differing_words'] == 90 and not diagnosis['unexplained_differences']
    measured = compact(proofs['default'], proofs['guarded'], diagnosis, official)
    if expected:
        assert measured == expected['native'], 'native proof differs from sealed archive'
    assert inputs() == bindings
    save(out / 'measured.json', dict(inputs=bindings, native=measured))
    save(out / 'completed.json', dict(source_sha256=EXPECTED_SOURCE, measured_sha256=file_hash(out / 'measured.json'),
                                      modes=['default', 'guarded'], no_source_mutations=True,
                                      new_exact_functions=0))
    print('PASS: actual installed modes, all references/storage, 26 unchanged siblings; target remains nonexact.', flush=True)


if __name__ == '__main__':
    main()
