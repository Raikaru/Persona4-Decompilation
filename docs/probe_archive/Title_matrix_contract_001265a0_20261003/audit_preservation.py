"""Exact instruction/reference/branch map outside the two repaired boundaries."""
from pathlib import Path
import hashlib,json,struct
P=Path('proof/title-matrix-owner');rec=[json.loads((P/(s+'-guard.json')).read_text()) for s in ('before','after')]
sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert rec[1]['source_sha256']==sha
fn=[r['functions']['func_001265a0'] for r in rec];code=[bytes.fromhex(f['bytes']) for f in fn];words=[list(struct.unpack('<'+'I'*(len(c)//4),c)) for c in code]
assert [len(c) for c in code]==[16820,16840]
ranges=[{'before':[0,0x54],'after':[0,0x54]}, {'before':[0x64,0x39cc],'after':[0x84,0x39ec]}, {'before':[0x3a40,16820],'after':[0x3a54,16840]}]
map={a:b for r in ranges for a,b in zip(range(*r['before'],4),range(*r['after'],4))}
def si(w):return (w&65535)-65536 if w&32768 else w&65535
def stack(offset):
 if offset==0x3b0:return 0x3f0
 if 0x3dc<=offset<0x4b0:return offset+0x50
 return offset
branches=[];changes=[];stacks=[]
for a,b in map.items():
 wa,wb=words[0][a//4],words[1][b//4];op=wa>>26;expected=wa
 if op in (4,5,6,7,20,21,22,23) or (op==1) or (op==17 and wa>>21&31==8):
  target=a+4+si(wa)*4;assert target in map,(hex(a),hex(target));newtarget=b+4+si(wb)*4
  assert newtarget==map[target];expected=(wa&0xffff0000)|(((newtarget-b-4)//4)&65535)
  branches.append({'before':a,'after':b,'target_before':target,'target_after':newtarget})
 elif wa>>21&31==29 and op in (9,31,35,40,43,49,57,63):
  off=si(wa)
  if a==0:expected=(wa&0xffff0000)|((-0x500)&65535)
  elif op==9 and wa>>16&31==29:assert off==0x4b0;expected=(wa&0xffff0000)|0x500
  else:
   expected=(wa&0xffff0000)|(stack(off)&65535)
   if off!=stack(off):stacks.append({'instruction_before':a,'instruction_after':b,'home_before':off,'home_after':stack(off)})
 assert expected==wb,(hex(a),hex(b),hex(wa),hex(wb),hex(expected))
 if wa!=wb:changes.append(a)
# References at every retained instruction are identical, including addends.
for r in ranges:
 def refs(i):return [(x['offset']-r['before' if i==0 else 'after'][0],x['r_type'],x['symbol'],words[i][x['offset']//4]&65535) for x in fn[i]['relocations'] if r['before' if i==0 else 'after'][0]<=x['offset']<r['before' if i==0 else 'after'][1]]
 assert refs(0)==refs(1)
# Exact full reference sequence changes: 2 GP axis references become 8 HI/LO
# references including +8 tails; two fptodp calls disappear, nothing else.
def other(i):return [(r['r_type'],r['symbol'],words[i][r['offset']//4]&65535) for r in fn[i]['relocations'] if r['symbol'] not in ('D_005E5628','D_005E5638','fptodp')]
assert other(0)==other(1)
a=[r for r in fn[0]['relocations'] if r['symbol']=='fptodp'];b=[r for r in fn[1]['relocations'] if r['symbol']=='fptodp'];assert len(a)-len(b)==2
assert [x['offset'] for x in a if 0x39cc<=x['offset']<0x3a40]==[0x39d0,0x39f4]
for name in ('D_005E5628','D_005E5638'):
 assert [(r['r_type'],words[0][r['offset']//4]&65535) for r in fn[0]['relocations'] if r['symbol']==name]==[(7,0)]
 assert [(r['r_type'],words[1][r['offset']//4]&65535) for r in fn[1]['relocations'] if r['symbol']==name]==[(5,0),(6,0),(5,0),(6,8)]
switches=[]
for section,t in rec[0]['target_tables'].items():
 new=rec[1]['target_tables'][section]
 assert [map[x] for x in t['entries']]==new['entries']
 for a,b in zip(t['entries'],new['entries']):
  assert all(map[a+n]==b+n for n in range(0,16,4))
 switches.append({'before':t['entries'],'after':new['entries'],'all16_destinations_and_prefixes_checked':True})
report={'source_sha256':sha,'base':'9bb8b6ad0fafafca04007d67acadff673449bdfa','non_matrix_ranges':ranges,'exact_mapped_instructions':len(map),'branches':branches,'stack_home_changes':stacks,'allowed_stack_regions':[{'before':[0x3b0,0x3c0],'after':[0x3f0,0x400]},{'before':[0x3dc,0x4b0],'after':[0x42c,0x500]}],'frame_before':0x4b0,'frame_after':0x500,'all_outside_opcodes_and_registers_exact':True,'every_outside_branch_destination_checked':True,'all_references_except_two_axis_transports_and_two_promotions_exact':True,'removed_default_promotions':2,'switches':switches,'changed_retained_words':len(changes)}
Path('proof/matrix-preservation-evidence.json').write_text(json.dumps(report,indent=2)+'\n');print(f'Exact {len(map)} retained instructions; {len(branches)} branch destinations; stack homes; all references and 16 switch destinations checked')
