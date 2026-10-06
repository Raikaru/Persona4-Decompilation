#!/usr/bin/env python3
"""Replay the actual owner and bounded behavioral evidence in private scratch.

Run from any directory with the repository's configured Python/compiler:
  python docs/probe_archive/YDraw_update_002b6ec0_20261005/replay.py --output build/ydraw-replay-new

The output directory must be new. --retained OBJECT_DIRECTORY checks objects
from an existing installed-verify directory without repeating compilation.
No shared source, configuration, cache, build report or version-control state
is changed. Native objects remain in the requested private output directory.
"""
from collections import Counter
from pathlib import Path
import argparse
import hashlib
import json
import os
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
ROOT = next(path for path in HERE.parents if (path/'tools/verify.py').is_file())
sys.path.insert(0,str(ROOT/'tools'))
import verify as V
import proof_core as C
import behavior as A

OWNER = ROOT/'src/promoted/y_draw.c'
NAME,ADDRESS = 'func_002b6ec0',0x002B6EC0

def sha(raw):
    return hashlib.sha256(raw).hexdigest()

def dump(path,value):
    path.write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')

def owner_proof(path,markers,retail,windows):
    obj = V.ObjectFile(path)
    bases,data = C.prove_data(obj,markers,retail,exclude=(NAME,))
    rows = []
    target_code = None
    for name,marker in markers.items():
        body,relocs = obj.function(name)
        window = windows[f'{marker["addr"]:08x}']
        target = retail.bytes_at(marker['addr'],max(window,len(body)))
        resolved,reference_proof,differences = C.resolve_function(obj,name,target,bases)
        tail = target[len(body):window]
        exact = not differences and len(body)<=window and not any(tail)
        if name != NAME:
            assert exact,(name,'sibling differs from retail')
        else:
            target_code = resolved
        rows.append(dict(name=name,bytes=len(body),window=window,exact=exact,
            zero_tail=len(tail) if not any(tail) else None,
            raw_sha256=sha(body),resolved_sha256=sha(resolved),resolved_words=len(differences),
            canonical_relocations_sha256=sha(json.dumps(C.canonical_relocs(obj,relocs),sort_keys=True).encode()),
            references=reference_proof))
    assert target_code is not None
    return dict(object_sha256=sha(path.read_bytes()),functions=rows,data=data,
                allocated_data=C.data_summary(obj)),target_code

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--retained',type=Path)
    args = parser.parse_args()
    expected = json.loads((HERE/'receipt.json').read_text())
    assert sha(OWNER.read_bytes()) == expected['source_sha256'],'Source has changed since this receipt'
    for name,digest in expected['inputs'].items():
        assert sha((ROOT/name).read_bytes()) == digest,('Changed input',name)
    output = args.output.resolve()
    output.mkdir(parents=True,exist_ok=False)
    temp = output/'temporary'
    temp.mkdir()
    for name in ('TMP','TEMP','TMPDIR'):
        os.environ[name] = str(temp)
    os.environ['PYTHONDONTWRITEBYTECODE'] = '1'
    tempfile.tempdir = str(temp)
    config = V.load_config()
    compiler = Path(V.unit_compiler(OWNER,config))
    assert sha(compiler.read_bytes()) == expected['compiler_sha256']
    assert V.unit_compile_flags(OWNER,config['compile_flags']) == expected['flags']
    manifest = V._read_json(V.FUNCTION_WINDOWS)
    windows = manifest['windows']
    retail = V.RetailElf(config['retail_elf'],V._read_json(V.TARGET),manifest['sha1'])
    assert manifest['sha1'] == expected['retail_sha1']
    markers = {m['name']:m for m in V.scan_markers(OWNER) if m['name']}
    boundaries = sorted({int(a,16) for a in windows} | {int(a,16)+s for a,s in windows.items() if s})
    if args.retained:
        retained = args.retained.resolve()
        default_object = retained/'default/src_promoted_y_draw.c.o'
        c_object = retained/'exposed/owner.o'
        assert sha(default_object.read_bytes()) == expected['default_object_sha256']
        assert sha(c_object.read_bytes()) == expected['exposed_object_sha256']
        native = json.loads((retained/'default/native.json').read_text())
    else:
        default_dir = output/'default'
        default_dir.mkdir()
        native = V.verify_file(OWNER,config,retail,boundaries,default_dir)
        default_object = default_dir/'src_promoted_y_draw.c.o'
        c_object = output/'exposed.o'
        command = V._mwccgap_command(OWNER,config,c_object)+['-DNON_MATCHING','--skip-asm']
        process = subprocess.run(command,cwd=ROOT,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
        (output/'exposed-compile.log').write_text(process.stdout,encoding='utf-8')
        assert process.returncode == 0,process.stdout
    assert Counter(row['status'] for row in native) == Counter(MATCH=57,ASM=1)
    default,_ = owner_proof(default_object,markers,retail,windows)
    exposed,code = owner_proof(c_object,markers,retail,windows)
    assert all(row['exact'] for row in default['functions'])
    assert default['allocated_data'] == exposed['allocated_data'] == {}
    recorded = {r['name']:r for r in expected['default_functions']}
    for row in default['functions']:
        old = recorded[row['name']]
        for key in ('bytes','raw_sha256','resolved_sha256','canonical_relocations_sha256'):
            assert row[key] == old[key],(row['name'],key)
    base = {r['name']:r for r in default['functions']}
    for row in exposed['functions']:
        if row['name'] != NAME:
            for key in ('bytes','raw_sha256','resolved_sha256','canonical_relocations_sha256'):
                assert row[key] == base[row['name']][key],(row['name'],key)
    target = retail.bytes_at(ADDRESS,windows['002b6ec0'])
    gp,table = C.globals_table()
    global_address = V.resolve_symbol('iGpffffb574',gp,table)
    threshold_address = V.resolve_symbol('fGpffff8504',gp,table)
    behavioral = A.audit_pair(target,code,gp,global_address,threshold_address)
    assert behavioral['passed'] == behavioral['cases'] == 92
    assert behavioral['retail_instructions_covered'] == 381
    assert sha(OWNER.read_bytes()) == expected['source_sha256']
    dump(output/'native.json',native)
    dump(output/'default-resolved.json',default)
    dump(output/'exposed-resolved.json',exposed)
    dump(output/'behavior.json',behavioral)
    summary = dict(source_sha256=expected['source_sha256'],native_counts=dict(Counter(r['status'] for r in native)),
        default_functions_exact=len(default['functions']),exposed_siblings_exact=len(exposed['functions'])-1,
        target=next({k:v for k,v in row.items() if k!='references'} for row in exposed['functions'] if row['name']==NAME),
        behavior_cases=behavioral['cases'],behavior_passed=behavioral['passed'],
        retail_instructions_covered=behavioral['retail_instructions_covered'],retained_objects=bool(args.retained))
    dump(output/'receipt.json',summary)
    print(json.dumps(summary,indent=2))

if __name__ == '__main__':
    main()
