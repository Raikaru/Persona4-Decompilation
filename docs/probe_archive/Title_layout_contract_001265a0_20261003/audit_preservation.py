"""Exact retained instruction map, full branch targets and reference/addend census.

The compiler reassigns s0/s1 for the earlier counter/row live ranges. This is an
explicit whole-region bijection on decoded GPR operands, not a register mask.
No branch, opcode, reference target or addend is ignored.
"""
from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
P=Path('proof/title-layout-owner');rec=[json.loads((P/(s+'-guard.json')).read_text()) for s in ('before','after')]
sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert rec[1]['source_sha256']==sha
fn=[r['functions']['func_001265a0'] for r in rec];code=[bytes.fromhex(f['bytes']) for f in fn];words=[list(struct.unpack('<'+'I'*(len(c)//4),c)) for c in code]
assert [len(c) for c in code]==[16840,16712]
RANGES=[(0,0x7ec,0),(0x7f0,0xe60,4),(0xe74,0x1214,8),(0x1218,0x1298,12),(0x12d0,0x12dc,-4),(0x12e0,0x3284,0),(0x3298,0x376c,4),(0x37b4,0x3864,-0x2c),(0x38ac,0x3918,-0x5c),(0x396c,0x39c0,-0x80),(0x39ec,16840,-0x80)]
map={a:a+d for first,last,d in RANGES for a in range(first,last,4)}
# Explicit semantic starts of rewritten boundaries reached by preserved branches.
map.update({0x1214:0x121c,0x1298:0x12a4,0x12a4:0x12b0,0x12a8:0x12b4,0x12dc:0x12d8,0x39c0:0x3940})
def si(w):return (w&65535)-65536 if w&32768 else w&65535
def rename(w):
 op=w>>26;rs=w>>21&31
 if op in (2,3):fields=[]
 elif op==0:fields=[21,16,11]
 elif op==17:fields=[16] if rs in (0,4) else []
 elif op in (49,57,53,61):fields=[21] # FPR is not a GPR
 elif op==15:fields=[16]
 elif op in (1,6,7):fields=[21] # REGIMM rt is a condition selector
 else:fields=[21,16]
 for shift in fields:
  r=w>>shift&31
  if r in (16,17):w=(w&~(31<<shift))|((33-r)<<shift)
 return w
branches=[];renamed=[]
for first,last,delta in RANGES:
 for a in range(first,last,4):
  b=a+delta;wa,wb=words[0][a//4],words[1][b//4];op=wa>>26;expected=rename(wa) if 0x204<=a<0x2ef8 else wa
  if expected!=wa:renamed.append({'before':a,'after':b,'old_word':f'{wa:08x}','new_word':f'{expected:08x}'})
  if op in (4,5,6,7,20,21,22,23) or op==1 or (op==17 and wa>>21&31==8):
   target=a+4+si(wa)*4;assert target in map,('unmapped target',hex(a),hex(target));newtarget=b+4+si(wb)*4
   assert newtarget==map[target],('target',hex(a),hex(target),hex(newtarget),hex(map[target]));expected=(expected&0xffff0000)|(((newtarget-b-4)//4)&65535)
   branches.append({'before':a,'after':b,'target_before':target,'target_after':newtarget})
  assert expected==wb,(hex(a),hex(b),hex(wa),hex(wb),hex(expected))
# Every retained relocation is equal, including target identity and instruction addend.
for first,last,delta in RANGES:
 def refs(i):return [(x['offset']-(first+(delta if i else 0)),x['r_type'],x['symbol'],words[i][x['offset']//4]&65535) for x in fn[i]['relocations'] if first+(delta if i else 0)<=x['offset']<last+(delta if i else 0)]
 assert refs(0)==refs(1),(hex(first),refs(0),refs(1))
# Full reference sequence. Only seven GP table events expand into exact HI/LO
# pairs, and the earlier speed default-promotion call disappears.
def other(i):return [(r['r_type'],r['symbol'],words[i][r['offset']//4]&65535) for r in fn[i]['relocations'] if r['symbol'] not in ('D_005E5230','fptodp')]
assert other(0)==other(1)
fpt=[[(r['offset'],r['r_type'],r['symbol'],words[i][r['offset']//4]&65535) for r in fn[i]['relocations'] if r['symbol']=='fptodp'] for i in (0,1)]
assert len(fpt[0])==len(fpt[1])+1
assert [(map[a],t,n,v) for a,t,n,v in fpt[0] if a!=0x12ac]==fpt[1]
roots=[[(r['offset'],r['r_type'],words[i][r['offset']//4]&65535) for r in fn[i]['relocations'] if r['symbol']=='D_005E5230'] for i in (0,1)]
assert roots[0]==[(a,7,0) for a in (0x7ec,0xe60,0x1214,0x12dc,0x3284,0x3770,0x3868)]
assert roots[1]==[(at+n,5 if n==0 else 6,0) for at in (0x7ec,0xe70,0x121c,0x12d8,0x3290,0x3774,0x383c) for n in (0,4)]
gp,symbols=V.symbol_addresses();addr=V.resolve_symbol('D_005E5230',gp,symbols);assert addr==0x5e5230
# Verify resolved retail table and alias addresses without treating a wrong
# scalar GP relocation as an acceptable wildcard. Root is outside signed GP16.
assert not -32768<=addr-gp<=32767
aliases={}
for name,want in [('D_005E5230',0x5e5230),('D_005E523C',0x5e523c),('D_005E5240',0x5e5240),('D_005E5248',0x5e5248),('D_005E5254',0x5e5254)]:
 assert V.resolve_symbol(name,gp,symbols)==want
 rr=[r for r in fn[1]['relocations'] if r['symbol']==name];assert len(rr)%2==0
 for hi,lo in zip(rr[::2],rr[1::2]):
  assert hi['r_type']==5 and lo['r_type']==6 and lo['offset']==hi['offset']+4
  wh=words[1][hi['offset']//4];wl=words[1][lo['offset']//4];assert wh&65535==0 and wl&65535==0
  assert wh>>26==15 and wl>>21&31==wh>>16&31
  resolved=((want+0x8000)&0xffff0000)+si(want);assert resolved==want
 aliases[name]={'address':want,'byte_offset_from_root':want-addr,'addend':0,'checked_pairs':len(rr)//2}
switches=[]
for section,t in rec[0]['target_tables'].items():
 new=rec[1]['target_tables'][section];assert [map[x] for x in t['entries']]==new['entries']
 switches.append({'before':t['entries'],'after':new['entries'],'all16_destinations_checked':True})
report={'source_sha256':sha,'base':'c0da65b93e785858dad848163c2482b7b0d533cb','retained_ranges':[{'before':[a,b],'after':[a+d,b+d]} for a,b,d in RANGES],'semantic_boundary_map':{str(k):v for k,v in map.items() if not any(a<=k<b for a,b,d in RANGES)},'exact_retained_instructions':sum((b-a)//4 for a,b,d in RANGES),'register_bijection':{'before_region':[0x204,0x2ef8],'mapping':{'s0':'s1','s1':'s0'},'instructions':renamed},'branches':branches,'all_outside_opcodes_exact':True,'all_retained_reference_targets_and_addends_exact':True,'all_other_reference_events_exact':True,'removed_default_promotion':0x12ac,'table_GP16_not_representable':True,'table_address':addr,'gp':gp,'table_reference_before':roots[0],'table_reference_after':roots[1],'aliases':aliases,'switches':switches}
Path('proof/layout-preservation-evidence.json').write_text(json.dumps(report,indent=2)+'\n');print(f'Exact {report["exact_retained_instructions"]} retained instructions with explicit s0/s1 bijection; {len(branches)} branches; all references/addends and 16 switch entries checked')
