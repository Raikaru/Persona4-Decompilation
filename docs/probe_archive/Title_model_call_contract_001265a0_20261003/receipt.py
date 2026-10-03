"""Seal source-only records; licensed binaries and complete reports stay in proof/."""
from pathlib import Path
import collections,hashlib,json,re,shutil
P=Path('proof');A=Path(__file__).resolve().parent
owner='src/promoted/code1_0012.c';sha=hashlib.sha256(Path(owner).read_bytes()).hexdigest()
files={'model-source-evidence.json':'source-evidence.json','title-model-owner/preservation.json':'owner-preservation.json','model-preservation-evidence.json':'target-preservation.json','model-machine-evidence.json':'model-machine-evidence.json','palette-machine-evidence.json':'palette-machine-evidence.json','candidate-color-families.json':'color-evidence.json','layer-call-proof.json':'layer-evidence.json','gp-color-evidence.json':'gp-evidence.json','alpha-alias-evidence.json':'alpha-evidence.json','sprite-alpha-machine-evidence.json':'sprite-alpha-evidence.json','fade-machine-evidence.json':'fade-evidence.json'}
for source,destination in files.items():
 data=json.loads((P/source).read_text())
 if 'source_sha256' in data:assert data['source_sha256']==sha
 if source=='fade-machine-evidence.json':data.pop('rows')
 (A/destination).write_text(json.dumps(data,indent=2)+'\n')
v=json.loads((P/'model-owners.json').read_text());assert v['summary']=={'MATCH':253,'ASM':46}
owners={}
for row in v['results']:owners.setdefault(row['file'],collections.Counter())[row['status']]+=1
assert owners[owner]=={'MATCH':81,'ASM':1}
provider=[r for r in v['results'] if r.get('name')=='func_00124bb0'];assert len(provider)==1 and provider[0]['status']=='MATCH',provider
measure=(P/'model-measure.log').read_text();assert 'obj 16816B  window 17616B' in measure and 'GUARDED_SCORE func_001265a0: 3955' in measure
lint=(P/'model-lint.log').read_text();assert '0 error, 32 warn' in lint
native=(P/'model-all-native.log').read_text();assert 'Ran 29 tests' in native and '\nOK\n' in native and not re.search(r'FAILED|skipped=',native)
assert native.count('583680 title model call cases passed')==4
assert native.count('roundtrip: rejected:')==5
assert native.count('site_')>=100 # 70 model controls plus 30 palette site controls
assert 'signed top-byte shift: sanitizer rejected' in native
machine=json.loads((A/'model-machine-evidence.json').read_text());assert machine['executed_cases']==389120 and len(machine['negative_controls'])==38
for config in ('production','guard'):
 rec=json.loads((P/'title-model-owner'/('after-'+config+'.json')).read_text());assert rec['source_sha256']==sha
report={'base':'69799eb8fe97c414501d20af309688f147e0e5d2','source_sha256':sha,'status':'guarded nonmatching typed-call and packed-word recovery; assembly fallback retained','production_summary':v['summary'],'owner_statuses':owners,'model_provider':{k:provider[0][k] for k in ('file','addr','name','object_size','window','normalized_diff','status')},'guarded_target_bytes':16816,'retail_window_bytes':17616,'guarded_masked_differing_words':3955,'base_guarded_target_bytes':17496,'base_guarded_masked_differing_words':3986,'frame_before':1664,'frame_after':1200,'removed_default_promotion_calls':33,'lint':{'errors':0,'existing_advisories':32},'native':{'tests':29,'skips':0,'model_cases_per_mode_optimization':583680,'modes':['unaltered source expressions','explicit supplied special-producer outputs'],'optimizations':['O0','O2'],'model_source_controls':71,'signed_shift_control':'undefined-behavior sanitizer trap'},'machine_model_cases':389120,'machine_model_controls':38,'provider_native_execution':False,'special_ACC_arithmetic_equivalence':False,'new_exact_C_credit':0,'not_run':['full linked-image build','renderer/gameplay','CI','push or publication']}
(A/'verification.json').write_text(json.dumps(report,indent=2)+'\n')
shutil.copyfile(P/'model-all-native.log',A/'native.log')
print('Source-only receipts sealed: 29 native tests; 71 source and 38 model-machine controls; relevant owner/provider gates passed')
