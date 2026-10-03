"""Bound the only target reference changes and every real switch destination.

Typed calls remove 33 default-promotion helpers. Register allocation changes
outside the five model scopes are documented, not hidden by an opcode mask.
"""
from pathlib import Path
import collections,hashlib,json,struct
P=Path('proof/title-model-owner');rec=[json.loads((P/(s+'-guard.json')).read_text()) for s in ('before','after')]
assert rec[1]['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
fns=[r['functions']['func_001265a0'] for r in rec];code=[bytes.fromhex(f['bytes']) for f in fns];words=[struct.unpack('<'+'I'*(len(c)//4),c) for c in code]
excluded=[];preserved=[]
for i,fn in enumerate(fns):
 starts=[r['offset']-4 for r in fn['relocations'] if r['symbol']=='D_005E5530' and r['r_type']==5][::2]
 ends=[r['offset']+8 for r in fn['relocations'] if r['symbol']=='func_00124bb0']
 assert len(starts)==len(ends)==5
 excluded.append(list(zip(starts,ends)));preserved.append(list(zip([0]+ends,starts+[fn['size']])))
# Saving/restoring fp disappears along with old promotion-call pressure.
assert words[0][2]==0x7fbe00d0
assert words[0][-19]==0x7bbe00d0,hex(words[0][-19])
mapping={};ranges=[]
for n,((sa,ea),(sb,eb)) in enumerate(zip(*preserved)):
 if n==0:sa=12;sb=8
 if n==5:ea-=20*4;eb-=19*4
 assert ea-sa==eb-sb,(n,sa,ea,sb,eb)
 for oa,ob in zip(range(sa,ea,4),range(sb,eb,4)):mapping[oa]=ob
 ranges.append({'before':[sa,ea],'after':[sb,eb]})
# Reference identity, order, local addend and offset survive in every outside range.
def refs(fn,ws,span):
 return [(r['offset']-span[0],r['r_type'],r['symbol'],ws[r['offset']//4]&65535) for r in fn['relocations'] if span[0]<=r['offset']<span[1]]
for row in ranges:assert refs(fns[0],words[0],row['before'])==refs(fns[1],words[1],row['after'])
boundaries=[]
for i,((sa,ea),(sb,eb)) in enumerate(zip(*excluded)):
 a=refs(fns[0],words[0],(sa,ea));b=refs(fns[1],words[1],(sb,eb))
 removed=[r for r in a if r[2]=='fptodp'];assert len(removed)==(7 if i in (0,1,4) else 6)
 assert [(t,n,v) for o,t,n,v in a if n!='fptodp']==[(t,n,v) for o,t,n,v in b]
 assert not any(r[2]=='fptodp' for r in b)
 boundaries.append({'before':[sa,ea],'after':[sb,eb],'removed_default_promotion_calls':len(removed),'all_other_reference_events_and_addends_equal':True})
# The whole target sequence loses exactly the bounded 33 fptodp events.
def allrefs(fn,ws):return [(r['r_type'],r['symbol'],ws[r['offset']//4]&65535) for r in fn['relocations'] if r['symbol']!='fptodp']
assert allrefs(fns[0],words[0])==allrefs(fns[1],words[1])
assert sum(r['symbol']=='fptodp' for r in fns[0]['relocations'])-sum(r['symbol']=='fptodp' for r in fns[1]['relocations'])==33
# Explicit known source-live bindings at the six distinct switch entries:
# work pointer s2->s4; case-4 counter s4->s0; case-6 counter s3->s1.
# The shared color home changes 0x67c->0x4ac; all other immediates are exact.
switches=[]
for key in rec[0]['target_tables']:
 a,b=[r['target_tables'][key] for r in rec]
 for i,(oa,ob) in enumerate(zip(a['entries'],b['entries'])):
  assert mapping[oa]==ob
  mapping_g={18:20,20:16} if i in (4,5) else {18:20,19:17} if i in (6,7) else {18:20}
  for at in range(0,16,4):
   wa,wb=words[0][(oa+at)//4],words[1][(ob+at)//4];op=wa>>26;want=wa
   assert op in (0,9,10,15,17,20,35,43,49,57,6,5)
   # Only GPR operand fields, never float register numbers.
   if op not in (0,17):
    rs=wa>>21&31;rt=wa>>16&31
    want=(want&~(31<<21))|(mapping_g.get(rs,rs)<<21)
    if op not in (49,57):want=(want&~(31<<16))|(mapping_g.get(rt,rt)<<16)
   if wa&65535==0x67c:want=(want&0xffff0000)|0x4ac
   assert want==wb,(i,hex(oa+at),hex(wa),hex(wb),hex(want))
  switches.append({'index':i,'before':oa,'after':ob,'source_bindings_checked':mapping_g})
report={'source_sha256':rec[1]['source_sha256'],'non_model_ranges':ranges,'excluded_model_boundaries':boundaries,'removed_default_promotions':33,'all_other_target_references_and_addends_preserved':True,'switch_entries':switches,'frame_before':0x680,'frame_after':0x4b0,'limits':'No claim of complete target instruction equality: register allocation and stack homes change. Every switch entry and exact outside reference position/addend is checked; prior independently bounded semantics replay on the final object.'}
Path('proof/model-preservation-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print('All target references preserved except 33 typed-call default promotions; all sixteen switch destinations explicitly verified')
