"""Collect source-only receipts after all independent replay gates pass."""
from pathlib import Path
import collections,hashlib,json,re,shutil
P=Path('proof');A=Path(__file__).resolve().parent
owner='src/promoted/code1_0012.c';source=Path(owner).read_bytes();sha=hashlib.sha256(source).hexdigest()
files={'palette-source-evidence.json':'source-evidence.json','title-palette-owner/preservation.json':'owner-preservation.json','palette-preservation-evidence.json':'target-preservation.json','palette-machine-evidence.json':'palette-machine-evidence.json','candidate-color-families.json':'color-evidence.json','layer-call-proof.json':'layer-evidence.json','gp-color-evidence.json':'gp-evidence.json','preserved-slices-evidence.json':'preserved-slices-evidence.json','sprite-alpha-machine-evidence.json':'sprite-alpha-evidence.json','fade-machine-evidence.json':'fade-evidence.json'}
for src,dst in files.items():
 data=json.loads((P/src).read_text())
 if 'source_sha256' in data:assert data['source_sha256']==sha,(src,data['source_sha256'])
 if src=='fade-machine-evidence.json':data.pop('rows') # compact source-only receipt, full local rows stay in proof
 (A/dst).write_text(json.dumps(data,indent=2)+'\n')
verified=json.loads((P/'palette-owners.json').read_text());assert verified['summary']=={'MATCH':253,'ASM':46}
rows=verified['results'];owners={}
for row in rows:owners.setdefault(row['file'],collections.Counter())[row['status']]+=1
assert owners[owner]=={'MATCH':81,'ASM':1}
measure=(P/'palette-measure.log').read_text();assert 'obj 17496B  window 17616B' in measure and 'GUARDED_SCORE func_001265a0: 3986' in measure
lint=(P/'palette-lint.log').read_text();assert '0 error, 32 warn' in lint
native=(P/'palette-all-native.log').read_text();assert 'Ran 26 tests' in native and '\nOK\n' in native and not re.search(r'FAILED|skipped=',native)
assert native.count('title palette storage cases passed')==2
assert native.count('site_')>=30
for key in ('production','guard'):
 rec=json.loads((P/'title-palette-owner'/('after-'+key+'.json')).read_text());assert rec['source_sha256']==sha
report={'source_sha256':sha,'base':'bed91675c50af703b974bd44ede3234eef532590','status':'guarded nonmatching recovery; assembly fallback retained','production_summary':verified['summary'],'owner_statuses':owners,'guarded_target_bytes':17496,'retail_window_bytes':17616,'guarded_masked_differing_words':3986,'base_guarded_target_bytes':17468,'base_guarded_masked_differing_words':3995,'lint':{'errors':0,'existing_advisories':32},'native':{'tests':26,'skips':0,'palette_cases_per_optimization':123000,'optimizations':['O0','O2'],'palette_source_mutation_controls':34},'proof_boundaries':['selected palette words and source object storage','existing color/layer/alpha/fade scopes rerun','model-draw ABI/ACC unchanged and unproven'],'not_run':['full linked image','renderer or gameplay','CI','push or publication'],'new_exact_C_credit':0}
(A/'verification.json').write_text(json.dumps(report,indent=2)+'\n')
shutil.copyfile(P/'palette-all-native.log',A/'native.log')
print('Source-only receipts collected; all 26 native tests and scoped owner gates passed')
