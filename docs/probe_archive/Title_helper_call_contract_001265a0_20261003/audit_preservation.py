"""Exact instruction/branch/reference/switch preservation, with no opcode masks.

Only seven call boundaries differ. Retained registers and frame homes are exact;
branch immediates are checked by mapped destinations, not silently ignored.
"""
from pathlib import Path
import hashlib,json,struct
P=Path('proof/title-helper-owner');rec=[json.loads((P/(s+'-guard.json')).read_text()) for s in ('before','after')]
sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert rec[1]['source_sha256']==sha
fn=[r['functions']['func_001265a0'] for r in rec];code=[bytes.fromhex(f['bytes']) for f in fn];words=[list(struct.unpack('<'+'I'*(len(c)//4),c)) for c in code]
assert [len(c) for c in code]==[16712,16664]
RANGES=[(0,0x6cc,0),(0x6f0,0x9e0,-0xc),(0x9f0,0x2664,-0x18),(0x2680,0x2800,-0x18),(0x2824,0x3190,-0x24),(0x31b4,0x4148,-0x30)]
map={a:a+d for first,last,d in RANGES for a in range(first,last,4)}
map.update({0x6cc:0x6cc,0x9e0:0x9d4,0x2664:0x264c,0x2800:0x27e8,0x3190:0x316c})
def si(w):return (w&65535)-65536 if w&32768 else w&65535
branches=[]
for first,last,delta in RANGES:
 for a in range(first,last,4):
  b=a+delta;wa,wb=words[0][a//4],words[1][b//4];op=wa>>26;expected=wa
  if op in (4,5,6,7,20,21,22,23) or op==1 or (op==17 and wa>>21&31==8):
   target=a+4+si(wa)*4;assert target in map,('unmapped',hex(a),hex(target));newtarget=b+4+si(wb)*4
   assert newtarget==map[target],('target',hex(a),hex(target),hex(newtarget),hex(map[target]));expected=(wa&0xffff0000)|(((newtarget-b-4)//4)&65535)
   branches.append({'before':a,'after':b,'target_before':target,'target_after':newtarget})
  assert expected==wb,(hex(a),hex(b),hex(wa),hex(wb))
 for i in (0,1):
  refs=[(x['offset']-(first+(delta if i else 0)),x['r_type'],x['symbol'],words[i][x['offset']//4]&65535) for x in fn[i]['relocations'] if first+(delta if i else 0)<=x['offset']<last+(delta if i else 0)]
  if i==0:oldrefs=refs
  else:assert oldrefs==refs
# Every changed instruction is explicitly frozen as an actual call rewrite.
SLICES=[(0x6cc,0x6f0,0x6cc,0x6e4,[0x4616bb1d,0x0c000000,0,0x3c034024,0x0003403c,0x240400b2,0x0280282d,0x0040302d,0x0000382d],[0x44806800,0x4616bb1d,0x3c024120,0x44827000,0x240400b2,0x0280282d]),(0x9e0,0x9f0,0x9d4,0x9d8,[0x44020000,0,0x00022e3c,0x00052e3f],[0x44050000]),(0x2664,0x2680,0x264c,0x2668,[0x3c024069,0x0002303c,0x3c024024,0x0002403c,0x240400ff,0x0280282d,0x0000382d],[0x3c024348,0x44826000,0x44806800,0x3c024120,0x44827000,0x240400ff,0x0280282d])]
for old,new,brightness in [(0x2800,0x27e8,255),(0x3190,0x316c,153)]:
 SLICES.append((old,old+36,new,new+24,[0x4616bb1d,0x0c000000,0,0x3c034024,0x0003403c,0x24040000|brightness,0x0280282d,0x0040302d,0x0000382d],[0x44806800,0x4616bb1d,0x3c024120,0x44827000,0x24040000|brightness,0x0280282d]))
for a,z,b,y,old,new in SLICES:assert words[0][a//4:z//4]==old and words[1][b//4:y//4]==new
# Complete, disjoint coverage of both instruction streams.
for i in (0,1):
 covered=[a+(d if i else 0) for first,last,d in RANGES for a in range(first,last,4)]+[x for a,z,b,y,old,new in SLICES for x in range(b if i else a,y if i else z,4)]
 assert sorted(covered)==list(range(0,len(code[i]),4))
def references(i):return [(r['r_type'],r['symbol'],words[i][r['offset']//4]&65535) for r in fn[i]['relocations'] if r['symbol']!='fptodp']
assert references(0)==references(1)
fpt=[[(r['offset'],r['r_type'],r['symbol'],words[i][r['offset']//4]&65535) for r in fn[i]['relocations'] if r['symbol']=='fptodp'] for i in (0,1)]
assert [len(x) for x in fpt]==[15,12]
removed=[0x6d0,0x2804,0x3194];assert [(map[a],t,n,v) for a,t,n,v in fpt[0] if a not in removed]==fpt[1]
switches=[]
for section,t in rec[0]['target_tables'].items():
 new=rec[1]['target_tables'][section];assert [map[x] for x in t['entries']]==new['entries'];switches.append({'before':t['entries'],'after':new['entries']})
r={'source_sha256':sha,'base':'6807e26bf4896fd803f01b9cb9182ea3df8d3a86','retained_ranges':[{'before':[a,b],'after':[a+d,b+d]} for a,b,d in RANGES],'semantic_boundary_map':{str(k):v for k,v in map.items() if not any(a<=k<b for a,b,d in RANGES)},'exact_retained_instructions':sum((b-a)//4 for a,b,d in RANGES),'changed_instruction_slices':[{'before':[a,z],'after':[b,y],'before_words':[hex(w) for w in old],'after_words':[hex(w) for w in new]} for a,z,b,y,old,new in SLICES],'branches':branches,'all_instruction_words_accounted':True,'all_retained_register_operands_and_stack_homes_exact':True,'all_other_reference_events_and_addends_exact':True,'fptodp_counts':[15,12],'removed_default_promotions':removed,'switches':switches}
Path('proof/helper-preservation-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print(f'Exact {r["exact_retained_instructions"]} retained instructions, {len(branches)} branches, all changed words, references/addends and 16 switch entries checked; fptodp15→12')
