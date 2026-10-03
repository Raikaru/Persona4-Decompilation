"""Seal compact source-only evidence with repository-relative manifest keys."""
from pathlib import Path
import collections,hashlib,json,re,sys
sys.path.insert(0,'tools');import verify as V
ROOT=Path.cwd().resolve();P=ROOT/'proof';A=Path(__file__).resolve().parent
owner='src/promoted/code1_0012.c';sha=hashlib.sha256(Path(owner).read_bytes()).hexdigest()
files={'matrix-source-evidence.json':'source-evidence.json','title-matrix-owner/preservation.json':'owner-preservation.json','matrix-preservation-evidence.json':'target-preservation.json','matrix-machine-evidence.json':'matrix-machine-evidence.json','entry-machine-evidence.json':'entry-machine-evidence.json','matrix-prior-scopes.json':'prior-scopes.json','model-machine-evidence.json':'model-machine-evidence.json','palette-machine-evidence.json':'palette-machine-evidence.json','candidate-color-families.json':'color-evidence.json','layer-call-proof.json':'layer-evidence.json','gp-color-evidence.json':'gp-evidence.json','alpha-alias-evidence.json':'alpha-evidence.json','sprite-alpha-machine-evidence.json':'sprite-alpha-evidence.json','fade-machine-evidence.json':'fade-evidence.json'}
for source,destination in files.items():
 data=json.loads((P/source).read_text())
 if 'source_sha256' in data:assert data['source_sha256']==sha
 if source=='fade-machine-evidence.json':data.pop('rows')
 (A/destination).write_text(json.dumps(data,indent=2)+'\n')
v=json.loads((P/'matrix-owners.json').read_text());assert v['summary']=={'MATCH':510,'ASM':63}
owners={}
for row in v['results']:owners.setdefault(row['file'],collections.Counter())[row['status']]+=1
assert len(owners)==13 and owners[owner]=={'MATCH':81,'ASM':1}
names=('func_0012aa70','func_00452560','func_004623a0','func_00461390','func_00124bb0','func_003e0680','func_003e0870','func_003e0e20','RwMatrixTranslate','func_0047a1c0')
providers=[{k:r[k] for k in ('file','addr','name','object_size','window','normalized_diff','status')} for r in v['results'] if r.get('name') in names]
assert len(providers)==10 and all(p['status']==('ASM' if p['name'] in ('func_003e0680','func_003e0870','func_003e0e20') else 'MATCH') for p in providers)
measure=(P/'matrix-measure.log').read_text();assert 'obj 16840B  window 17616B' in measure and 'GUARDED_SCORE func_001265a0: 3980' in measure
lint=(P/'matrix-lint.log').read_text();assert '0 error, 32 warn' in lint
prior=(P/'matrix-prior-native.log').read_text();native=(P/'matrix-native.log').read_text()
assert 'Ran 29 tests' in prior and 'Ran 4 tests' in prior and prior.count('\nOK\n')==2
assert 'Ran 3 tests' in native and native.count('\nOK\n')==1
assert not re.search(r'FAILED|skipped=',prior+native)
assert native.count('4096 title matrix storage/call cases passed')==2
assert len(re.findall(r'-O[02] [a-z_]+ rejected:',native))==30
assert prior.count('512 title entry cases passed')==2 and prior.count('583680 title model call cases passed')==4
for config in ('production','guard'):
 rec=json.loads((P/'title-matrix-owner'/('after-'+config+'.json')).read_text());assert rec['source_sha256']==sha
machine=json.loads((P/'matrix-machine-evidence.json').read_text());assert machine['actual_provider_copy_cases']==512 and len(machine['provider_copy_controls'])==6
cfg=V.load_config();flags=V.unit_compile_flags(Path(owner),cfg['compile_flags'])
report={'base':'9bb8b6ad0fafafca04007d67acadff673449bdfa','source_sha256':sha,'status':'guarded matrix/vector storage and call-ABI recovery; production fallback retained','compiler':'MWCCPS2 3.0.1 build 210','flags':flags,'production_summary':v['summary'],'owner_statuses':owners,'providers':providers,'guarded_target_bytes':16840,'retail_window_bytes':17616,'guarded_masked_differing_words':3980,'base_guarded_target_bytes':16820,'base_guarded_masked_differing_words':3985,'frame_before':0x4b0,'frame_after':0x500,'lint':{'errors':0,'existing_advisories':32},'native':{'tests':36,'prior_tests':33,'new_tests':3,'skips':0,'matrix_cases_per_optimization':4096,'optimizations':['O0','O2'],'matrix_control_runs':30,'matrix_providers_executed':False,'matrix_output_source':'explicit fully initialized recorder bytes; not actual provider results'},'matrix_machine_cases':2048,'matrix_machine_controls':12,'provider_copy_cases':512,'provider_copy_controls':6,'prior_machine_auditors':8,'entry_machine_replayed':True,'padding_limit':'Actual rotate provider local pad words +0x1c,+0x2c,+0x3c are not initialized before full matrix transfer; no values guessed or source initialization added','full_title_execution':False,'full_provider_execution':False,'new_exact_C_credit':0,'not_run':['full linked-image build','full repository test suite','renderer/gameplay','CI','push','upload','publication']}
(A/'verification.json').write_text(json.dumps(report,indent=2)+'\n');(A/'native.log').write_text(native);(A/'prior-native.log').write_text(prior)
inputs=[ROOT/owner,ROOT/'tests/test_title_matrix_contract.py',A.with_suffix('.md')]+sorted(p for p in A.iterdir() if p.is_file() and p.name!='manifest.json')
manifest={p.relative_to(ROOT).as_posix():hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}
assert all(not Path(k).is_absolute() and '..' not in Path(k).parts for k in manifest)
(A/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print('Source-only relative-path receipts sealed: 36 native tests; prior/current machine scopes; exact owner/branch/storage/reference preservation')
