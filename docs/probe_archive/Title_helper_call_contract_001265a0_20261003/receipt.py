"""Seal only source and compact receipts after all fresh bounded gates pass."""
from pathlib import Path
import collections,hashlib,json,re,sys
sys.path.insert(0,'tools');import verify as V
ROOT=Path.cwd().resolve();P=ROOT/'proof';A=Path(__file__).resolve().parent
owner='src/promoted/code1_0012.c';sha=hashlib.sha256(Path(owner).read_bytes()).hexdigest()
files={'helper-source-evidence.json':'source-evidence.json','title-helper-owner/preservation.json':'owner-preservation.json','helper-preservation-evidence.json':'target-preservation.json','helper-machine-evidence.json':'helper-machine-evidence.json','helper-prior-scopes.json':'prior-scopes.json','layout-machine-evidence.json':'layout-machine-evidence.json','matrix-machine-evidence.json':'matrix-machine-evidence.json','entry-machine-evidence.json':'entry-machine-evidence.json','model-machine-evidence.json':'model-machine-evidence.json','palette-machine-evidence.json':'palette-machine-evidence.json','candidate-color-families.json':'color-evidence.json','layer-call-proof.json':'layer-evidence.json','gp-color-evidence.json':'gp-evidence.json','alpha-alias-evidence.json':'alpha-evidence.json','sprite-alpha-machine-evidence.json':'sprite-alpha-evidence.json','fade-machine-evidence.json':'fade-evidence.json'}
for source,destination in files.items():
 data=json.loads((P/source).read_text())
 if 'source_sha256' in data:assert data['source_sha256']==sha
 if source=='fade-machine-evidence.json':data.pop('rows')
 (A/destination).write_text(json.dumps(data,indent=2)+'\n')
v=json.loads((P/'helper-owners.json').read_text());assert v['summary']=={'MATCH':510,'ASM':63}
owners={}
for row in v['results']:owners.setdefault(row['file'],collections.Counter())[row['status']]+=1
assert len(owners)==13 and owners[owner]=={'MATCH':81,'ASM':1}
providers=[{k:r[k] for k in ('file','addr','name','object_size','window','normalized_diff','status')} for r in v['results'] if r.get('name') in ('func_00124f70','func_00125e80','func_00126090')]
assert len(providers)==3 and all(p['status']=='MATCH' for p in providers)
measure=(P/'helper-measure.log').read_text();assert 'obj 16664B  window 17616B' in measure and 'GUARDED_SCORE func_001265a0: 3933' in measure
lint=(P/'helper-lint.log').read_text();assert '0 error, 32 warn' in lint
native=(P/'helper-all-native.log').read_text();assert re.search(r'Ran 44 tests in',native) and '\nOK\n' in native and not re.search(r'FAILED|skipped',native)
assert native.count('560 live helper expression cases passed')==2
assert native.count('35 independent argument-field controls rejected')==2 and native.count('15 wrong-order/arity/pointer-type controls rejected')==2
assert native.count('direct float-to-s8 sanitizer SIGILL: -4')==2 or native.count('direct float-to-s8 sanitizer SIGILL: 132')==2
machine=json.loads((P/'helper-machine-evidence.json').read_text());assert machine['cases']==11760 and len(machine['machine_controls'])==64
prior=json.loads((P/'helper-prior-scopes.json').read_text());assert len(prior['auditors'])==11
pres=json.loads((P/'helper-preservation-evidence.json').read_text());assert pres['exact_retained_instructions']==4140 and len(pres['branches'])==287 and pres['fptodp_counts']==[15,12]
for mode in ('production','guard'):assert json.loads((P/'title-helper-owner'/('after-'+mode+'.json')).read_text())['source_sha256']==sha
cfg=V.load_config();flags=V.unit_compile_flags(Path(owner),cfg['compile_flags'])
r={'base':'6807e26bf4896fd803f01b9cb9182ea3df8d3a86','source_sha256':sha,'compiler':'MWCCPS2 3.0.1 build 210','flags':flags,'status':'guarded seven-call contract recovery; production fallback retained','production_summary':v['summary'],'owner_statuses':owners,'providers':providers,'guarded_target_bytes':16664,'retail_window_bytes':17616,'guarded_masked_differing_words':3933,'base_guarded_target_bytes':16712,'base_guarded_masked_differing_words':3973,'runtime_fptodp_before_after':[15,12],'folded_constant_promotions_removed':9,'lint':{'errors':0,'advisories':32},'native':{'tests':44,'prior_tests':39,'new_tests':5,'skips':0,'cases_per_optimization':560,'optimizations':['O0','O2'],'field_control_runs':70,'compile_control_runs':30,'actual_sanitizer_SIGILL_controls':2,'real_32bit_pointers':True,'full_providers_executed':False},'machine':{'cases':11760,'controls':64,'prior_scopes':11,'pulse_X_boundary':'supplied after actual ACC output; geometry unproven'},'all_target_instructions_accounted':True,'new_exact_C_credit':0,'inherited_full_gate_evidence':{'commit':'6807e26bf4896fd803f01b9cb9182ea3df8d3a86','receipt':'docs/probe_archive/Title_layout_contract_001265a0_20261003/verification.json','fresh_full_build_or_verify':False},'not_run':['fresh full repository verification','fresh full production build/link','full repository native suite','whole controller/renderer/gameplay','CI','push','upload','publication']}
(A/'verification.json').write_text(json.dumps(r,indent=2)+'\n')
# Compact, deterministic summaries; full raw logs and per-case arrays stay local.
lines=[]
for line in native.splitlines():
 if line.startswith(('test_','-O0','-O2','OK','Ran ')):
  if line.startswith('Ran '):line='Ran 44 tests'
  lines.append(line)
(A/'native-summary.log').write_text('\n'.join(lines)+'\n')
(A/'prior-machine-summary.log').write_text((P/'helper-prior-machine.log').read_text())
(A/'owner-summary.log').write_text((P/'helper-owners.log').read_text())
inputs=[ROOT/owner,A.with_suffix('.md'),ROOT/'tests/native32_support.py',ROOT/'tests/test_btl_motion_override_contract.py']+sorted((ROOT/'tests').glob('test_title_*.py'))+sorted((ROOT/'tests').glob('title_*.c.in'))+sorted(p for p in A.iterdir() if p.is_file() and p.name!='manifest.json')
for tool in ('verify.py','measure_guarded.py','probe_variants.py','eedis.py'):inputs.append(ROOT/'tools'/tool)
for row in prior['auditors']:inputs.append(ROOT/row['auditor'])
manifest={p.relative_to(ROOT).as_posix():hashlib.sha256(p.read_bytes()).hexdigest() for p in inputs}
assert all(not Path(k).is_absolute() and '..' not in Path(k).parts for k in manifest)
(A/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print('Sealed bounded source-only receipts: 44 native tests without skips, 11 prior machine scopes, exact preservation and 13 owner gates')
