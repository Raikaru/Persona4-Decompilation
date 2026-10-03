"""Seal compact evidence, rejecting missing gates and non-relative manifests."""
from pathlib import Path
import collections,hashlib,json,re,sys
sys.path.insert(0,'tools');import verify as V
ROOT=Path.cwd().resolve();P=ROOT/'proof';A=Path(__file__).resolve().parent
owner='src/promoted/code1_0012.c';sha=hashlib.sha256(Path(owner).read_bytes()).hexdigest()
files={'layout-source-evidence.json':'source-evidence.json','title-layout-owner/preservation.json':'owner-preservation.json','layout-preservation-evidence.json':'target-preservation.json','layout-retail-evidence.json':'retail-evidence.json','layout-machine-evidence.json':'layout-machine-evidence.json','matrix-machine-evidence.json':'matrix-machine-evidence.json','entry-machine-evidence.json':'entry-machine-evidence.json','layout-prior-scopes.json':'prior-scopes.json','model-machine-evidence.json':'model-machine-evidence.json','palette-machine-evidence.json':'palette-machine-evidence.json','candidate-color-families.json':'color-evidence.json','layer-call-proof.json':'layer-evidence.json','gp-color-evidence.json':'gp-evidence.json','alpha-alias-evidence.json':'alpha-evidence.json','sprite-alpha-machine-evidence.json':'sprite-alpha-evidence.json','fade-machine-evidence.json':'fade-evidence.json'}
for source,destination in files.items():
 data=json.loads((P/source).read_text())
 if 'source_sha256' in data:assert data['source_sha256']==sha
 if source=='fade-machine-evidence.json':data.pop('rows')
 (A/destination).write_text(json.dumps(data,indent=2)+'\n')
v=json.loads((P/'layout-owners.json').read_text());assert v['summary']=={'MATCH':510,'ASM':63}
owners={}
for row in v['results']:owners.setdefault(row['file'],collections.Counter())[row['status']]+=1
assert len(owners)==13 and owners[owner]=={'MATCH':81,'ASM':1}
names=('func_0012aa70','func_0047a0e0','func_00124f70','func_00124bb0')
providers=[{k:r[k] for k in ('file','addr','name','object_size','window','normalized_diff','status')} for r in v['results'] if r.get('name') in names]
assert len(providers)==4 and all(p['status']=='MATCH' for p in providers)
measure=(P/'layout-measure.log').read_text();assert 'obj 16712B  window 17616B' in measure and 'GUARDED_SCORE func_001265a0: 3973' in measure
lint=(P/'layout-lint.log').read_text();assert '0 error, 32 warn' in lint
prior=(P/'layout-prior-native.log').read_text();native=(P/'layout-native.log').read_text()
assert 'Ran 29 tests' in prior and 'Ran 4 tests' in prior and 'Ran 3 tests' in prior and prior.count('\nOK\n')==3
assert 'Ran 3 tests' in native and native.count('\nOK\n')==1
assert not re.search(r'FAILED|skipped=',prior+native)
assert native.count('13465 title layout selection/read/provider cases passed')==2
assert len(re.findall(r'-O[02] [a-z0-9_]+ rejected:',native))==48
assert prior.count('512 title entry cases passed')==2 and prior.count('4096 title matrix storage/call cases passed')==2
for config in ('production','guard'):
 rec=json.loads((P/'title-layout-owner'/('after-'+config+'.json')).read_text());assert rec['source_sha256']==sha
machine=json.loads((P/'layout-machine-evidence.json').read_text());assert machine['executed_full_selection_cases']==15504 and machine['conversion_predicate_only_cases']==760 and len(machine['negative_controls'])==16
# Full verification and production linkage must be freshly present and successful.
full=(P/'layout-full-verify.log').read_text();build=(P/'layout-build-progress.log').read_text()
assert 'functions scanned:' in full and 'first-party functions scanned:' in full
assert not re.search(r'WRONG CALLEE|WRONG SYMBOL|COMPILE_ERROR|SIZE_MISMATCH|NO_SYMBOL|STALE_NONMATCHING|UNKNOWN_ADDR|Traceback|\bMISMATCH\b|make: \*\*\*',full)
assert 'loadable image sha1: 3d1d3d2b9d6ccb60836db239ab49674223025a78  OK' in build
assert 'SLUS_217.82 sha1: 4eeec0360cf2715535d9f7e52eb69d786fb0158c  OK' in build
linked=json.loads(Path('build/linked_report.json').read_text());assert linked['build_succeeded'] and linked['image_sha1']=='3d1d3d2b9d6ccb60836db239ab49674223025a78' and linked['retail_sha1']=='4eeec0360cf2715535d9f7e52eb69d786fb0158c'
linked_owner=[r for r in linked['linked_functions'] if r['file']==owner];assert len(linked_owner)==82
assert sum(r['name']=='func_001265a0' for r in linked_owner)==1 # production ASM fallback inside linked owner
cfg=V.load_config();flags=V.unit_compile_flags(Path(owner),cfg['compile_flags'])
report={'base':'c0da65b93e785858dad848163c2482b7b0d533cb','source_sha256':sha,'status':'guarded record/index/float/speed recovery; production fallback retained','compiler':'MWCCPS2 3.0.1 build 210','flags':flags,'production_summary':v['summary'],'owner_statuses':owners,'providers':providers,'guarded_target_bytes':16712,'retail_window_bytes':17616,'guarded_masked_differing_words':3973,'base_guarded_target_bytes':16840,'base_guarded_masked_differing_words':3980,'lint':{'errors':0,'advisories':32},'native':{'tests':39,'prior_tests':36,'new_tests':3,'skips':0,'cases_per_optimization':13465,'optimizations':['O0','O2'],'control_runs':48,'actual_speed_provider_executed':True,'negative_model_values_form_no_slot_pointer':True},'machine':{k:machine[k] for k in ('executed_full_selection_cases','conversion_predicate_only_cases','unsigned_diagnostic_predicate_cases','earlier_speed_cases','actual_provider_instruction_cases','negative_controls')},'prior_machine_auditors':10,'source_unchanged_matrix_vector_repair':True,'full_title_execution':False,'new_exact_C_credit':0,'full_production_build':{'build_succeeded':True,'image_sha1':linked['image_sha1'],'retail_sha1':linked['retail_sha1'],'linked_tu_count':linked['linked_tu_count'],'linked_function_count':linked['linked_function_count'],'title_linked_rows':linked_owner,'title_C_siblings':81,'title_controller_linkage':'assembly fallback carried by unchanged production owner; no exact-C credit'},'not_run':['full repository native suite','renderer/gameplay','CI','push','upload','publication']}
(A/'verification.json').write_text(json.dumps(report,indent=2)+'\n');(A/'native.log').write_text('\n'.join(line.rstrip() for line in native.splitlines())+'\n');(A/'prior-native.log').write_text('\n'.join(line.rstrip() for line in prior.splitlines())+'\n')
# Full verify summary contains no binaries/disassembly or proprietary paths.
(A/'full-verify-summary.log').write_text(full)
(A/'build-hash-summary.log').write_text('\n'.join(line.split('  (')[0] for line in build.splitlines() if 'sha1:' in line or line.startswith(('C objects linked','Sony SDK objects linked','eligible C objects:','build cache:')))+'\n')
inputs=[ROOT/owner,ROOT/'tests/test_title_layout_contract.py',ROOT/'tests/test_title_palette_storage.py',A.with_suffix('.md')]+sorted(p for p in A.iterdir() if p.is_file() and p.name!='manifest.json')
manifest={p.relative_to(ROOT).as_posix():hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}
assert all(not Path(k).is_absolute() and '..' not in Path(k).parts for k in manifest)
(A/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print('Sealed source-only relative-path receipts: 39 native tests, all machine scopes, exact preservation and full production hashes/linkage')
