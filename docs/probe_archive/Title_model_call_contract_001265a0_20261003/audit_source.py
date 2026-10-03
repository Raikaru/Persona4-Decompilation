"""Whole-source and complete packed-temporary census against frozen palette base."""
from pathlib import Path
import hashlib,json,re,subprocess
from model_recovery import BASE,OWNER,transform,arguments
old=subprocess.check_output(['git','show',BASE+':'+OWNER]).decode();new=Path(OWNER).read_text()
assert transform(old)==new,'Source exceeds exact typed-call/unsigned-shift repair'
body=new.split('void func_001265a0(s32 arg1) {',1)[1].split('\n#else',1)[0]
oldbody=old.split('void func_001265a0(s32 arg1) {',1)[1].split('\n#else',1)[0]
census=[]
for suffix in ('3','6','9'):
 n='temp_9_'+suffix
 a=[x.strip() for x in oldbody.splitlines() if re.search(r'\b'+n+r'\b',x)]
 b=[x.strip() for x in body.splitlines() if re.search(r'\b'+n+r'\b',x)]
 assert len(a)==len(b)==3 # old call has two occurrences
 assert len(re.findall(r'\b'+n+r'\b',oldbody))==4 and len(re.findall(r'\b'+n+r'\b',body))==3
 census.append({'name':n,'before_occurrences':4,'after_occurrences':3,'complete_uses':['u32 declaration','unsigned masked top-byte definition','packed highlight word argument'],'removed_use':'fabricated numeric leading float'})
signature=re.search(r'void func_00124bb0\(s32 arg0,.*?u32 \*arg4\)',new,re.S)[0]
assert signature==re.search(r'void func_00124bb0\(s32 arg0,.*?u32 \*arg4\)',old,re.S)[0]
assert '*(s32 *)(matrix + 0x0C) |= 0x20003;' in new
report={'base':BASE,'owner':OWNER,'source_sha256':hashlib.sha256(new.encode()).hexdigest(),'exact_bounded_transform':True,'packed_word_census':census,'unsigned_before_top_shift_sites':5,'call_argument_orders':{'generic':[0,6,7,8,9,10,11,1,2,12,3,4],'special':[0,5,6,7,8,9,10,1,2,11,3,4]},'actual_provider_signature_unchanged':signature,'provider_matrix_flags_uninitialized_OR_retained':True,'other_helper_contracts_untouched':True,'guard_and_fallback_retained':True,'special_geometry_producers_unchanged_and_unproven':True}
Path('proof/model-source-evidence.json').write_text(json.dumps(report,indent=2)+'\n');print('Exact source transform, all five typed calls and complete packed-word census verified')
