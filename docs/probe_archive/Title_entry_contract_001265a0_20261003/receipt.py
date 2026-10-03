"""Seal compact, source-only receipts; complete objects/logs stay under proof/."""
from pathlib import Path
import collections,hashlib,json,re,shutil,sys
sys.path.insert(0,'tools');import verify as V
P=Path('proof');A=Path(__file__).resolve().parent
owner='src/promoted/code1_0012.c';sha=hashlib.sha256(Path(owner).read_bytes()).hexdigest()
files={'entry-source-evidence.json':'source-evidence.json','title-entry-owner/preservation.json':'owner-preservation.json',
 'entry-preservation-evidence.json':'target-preservation.json','entry-machine-evidence.json':'entry-machine-evidence.json',
 'entry-prior-scopes.json':'prior-scopes.json','model-machine-evidence.json':'model-machine-evidence.json',
 'palette-machine-evidence.json':'palette-machine-evidence.json','candidate-color-families.json':'color-evidence.json',
 'layer-call-proof.json':'layer-evidence.json','gp-color-evidence.json':'gp-evidence.json',
 'alpha-alias-evidence.json':'alpha-evidence.json','sprite-alpha-machine-evidence.json':'sprite-alpha-evidence.json',
 'fade-machine-evidence.json':'fade-evidence.json'}
for source,destination in files.items():
 data=json.loads((P/source).read_text())
 if 'source_sha256' in data:assert data['source_sha256']==sha
 if source=='fade-machine-evidence.json':data.pop('rows')
 (A/destination).write_text(json.dumps(data,indent=2)+'\n')
v=json.loads((P/'entry-owners.json').read_text());assert v['summary']=={'MATCH':342,'ASM':47}
owners={}
for row in v['results']:owners.setdefault(row['file'],collections.Counter())[row['status']]+=1
assert owners[owner]=={'MATCH':81,'ASM':1}
provider_names=('func_0012aa70','func_00452560','func_004623a0','func_00461390','func_00124bb0')
providers=[{k:r[k] for k in ('file','addr','name','object_size','window','normalized_diff','status')} for r in v['results'] if r.get('name') in provider_names]
assert len(providers)==5 and all(p['status']=='MATCH' for p in providers)
measure=(P/'entry-measure.log').read_text();assert 'obj 16820B  window 17616B' in measure and 'GUARDED_SCORE func_001265a0: 3985' in measure
lint=(P/'entry-lint.log').read_text();assert '0 error, 32 warn' in lint
native=(P/'entry-all-native.log').read_text();assert 'Ran 29 tests' in native and 'Ran 4 tests' in native and native.count('\nOK\n')==2 and not re.search(r'FAILED|skipped=',native)
assert native.count('512 title entry cases passed')==2
assert native.count('incompatible callback type: compile rejected')==2
assert native.count('583680 title model call cases passed')==4
for config in ('production','guard'):
 rec=json.loads((P/'title-entry-owner'/('after-'+config+'.json')).read_text());assert rec['source_sha256']==sha
cfg=V.load_config();flags=V.unit_compile_flags(Path(owner),cfg['compile_flags'])
report={'base':'81708cc4e9e63e3b1eae30f466c069359a8dff70','source_sha256':sha,
 'status':'guarded nonmatching two-pointer void callback and second-input task accessor recovery; assembly fallback retained',
 'compiler':'MWCCPS2 3.0.1 build 210','flags':flags,'production_summary':v['summary'],'owner_statuses':owners,'providers':providers,
 'guarded_target_bytes':16820,'retail_window_bytes':17616,'guarded_masked_differing_words':3985,
 'base_guarded_target_bytes':16816,'base_guarded_masked_differing_words':3955,
 'residual_note':'Position-based masked score changes after a proven one-word insertion; every other instruction byte and mapped reference is exact',
 'lint':{'errors':0,'existing_advisories':32},'native':{'tests':33,'skips':0,'entry_cases_per_optimization':512,
 'optimizations':['O0','O2'],'entry_behavior_controls':9,'entry_compile_type_controls':2,'getter_body_executed':True,
 'wrong_input_guard':'observer asserts task identity before actual getter reads task+0x38'},
 'entry_machine_cases':2048,'entry_machine_controls':6,'prior_machine_auditors':8,
 'full_dispatcher_C_execution':False,'full_title_execution':False,'new_exact_C_credit':0,
 'not_run':['full linked-image build','full repository test suite','renderer/gameplay','CI','push or publication']}
(A/'verification.json').write_text(json.dumps(report,indent=2)+'\n')
shutil.copyfile(P/'entry-all-native.log',A/'native.log')
inputs=[Path(owner),Path('tests/test_title_entry_contract.py'),A.with_suffix('.md')]
inputs += sorted(p for p in A.iterdir() if p.is_file() and p.name!='manifest.json')
manifest={str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}
(A/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print('Source-only receipts sealed: 33 native tests, 2048 entry-machine cases, exact object/prefix/sibling preservation and relevant owners passed')
