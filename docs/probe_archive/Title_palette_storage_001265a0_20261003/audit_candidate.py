"""Verify actual snapshot/copy/selection instructions and execute all ten loops."""
from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
R=Path('proof');record=json.loads((R/'title-palette-owner/after-guard.json').read_text())
assert record['source_sha256']==hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()
fn=record['functions']['func_001265a0'];code=bytes.fromhex(fn['bytes']);words=list(struct.unpack('<'+'I'*(len(code)//4),code));refs=fn['relocations'];frame=-(struct.unpack_from('<h',code)[0])
cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS);retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1']);gp,symbols=V.symbol_addresses()
assert V.resolve_symbol('D_005E5540',gp,symbols)==V.resolve_symbol('D_005E5530',gp,symbols)+16==0x5e5540
real=list(struct.unpack('<6I',retail.bytes_at(0x5e5530,24)))
def op(w):return w>>26
def rs(w):return w>>21&31
def rt(w):return w>>16&31
def si(w):return (w&65535)-65536 if w&32768 else w&65535
loops=[]
for i in range(len(words)-9):
 p=words[i:i+9]
 if op(p[7])!=7 or si(p[7])!=-8 or p[8]!=0:continue
 if not (op(p[0])==op(p[1])==35 and op(p[4])==op(p[5])==43):continue
 src,dst,count=rs(p[0]),rs(p[4]),rs(p[7]);a,b=rt(p[0]),rt(p[1])
 assert p==[(35<<26)|(src<<21)|(a<<16),(35<<26)|(src<<21)|(b<<16)|4,
  (9<<26)|(src<<21)|(src<<16)|8,(9<<26)|(count<<21)|(count<<16)|65535,
  (43<<26)|(dst<<21)|(a<<16),(43<<26)|(dst<<21)|(b<<16)|4,
  (9<<26)|(dst<<21)|(dst<<16)|8,(7<<26)|(count<<21)|65528,0]
 if words[i-1]!=(9<<26)|(count<<16)|3:continue
 assert words[i-2]&0xffff0000==(9<<26)|(29<<21)|(dst<<16)
 dest=words[i-2]&65535
 setups=[j for j in range(max(0,i-12),i) if words[j]&0xffff0000==(9<<26)|(29<<21)|(src<<16)]
 assert len(setups)==1,(hex(i*4),setups)
 source=words[setups[0]]&65535
 calls=[r['offset']//4 for r in refs if r['symbol']=='func_00124bb0' and r['offset']//4>i];end=min(calls)
 loads=[j for j in range(i+9,end) if op(words[j])==35 and si(words[j])==dest and rs(words[j])==2]
 assert len(loads)==1,(hex(i*4),loads)
 selected=loads[0];prev=words[selected-1]
 assert op(prev)==0 and prev&63==33 and prev>>11&31==2 and 29 in (rs(prev),rt(prev))
 loops.append({'offset':i*4,'source_sp':source,'destination_sp':dest,'src_reg':src,'dst_reg':dst,'count_reg':count,'selected_load':selected*4,'selection_register':rt(words[selected]),'setup':setups[0]*4,'loop_words':p})
assert len(loops)==10,len(loops)
assert all(loops[i]['source_sp']==loops[i+1]['source_sp'] for i in range(0,10,2))
homes=[row['source_sp'] for row in loops[::2]]+[row['destination_sp'] for row in loops]
assert len(homes)==len(set(homes))==15
colors=json.loads((R/'candidate-color-families.json').read_text())['candidate_objects']
for h in homes:
 assert h%4==0 and 0<=h and h+24<=frame
 for k in homes:assert h==k or h+24<=k or k+24<=h
 for k in colors.values():assert h+24<=k or k+4<=h
snapshots=[]
palette_refs=[r for r in refs if r['symbol']=='D_005E5530'];assert len(palette_refs)==20
for group,row in enumerate(loops[::2]):
 rr=palette_refs[group*4:group*4+4];start=rr[0]['offset']//4
 assert [r['r_type'] for r in rr]==[5,6,5,6]
 assert [r['offset'] for r in rr]==list(range(start*4,start*4+16,4))
 p=words[start:start+6]
 assert p[0]==p[2]==0x3c020000 and p[1]==0x78430000 and p[3]==0xdc420010
 assert p[4]==0x7fa30000|row['source_sp'] and p[5]==0xffa20000|(row['source_sp']+16)
 assert row['setup']==(start-1)*4
 # Relocation is D_005E5530 +16, the authenticated D_005E5540 address.
 snapshots.append({'offset':start*4,'source_sp':row['source_sp'],'reads':[{'address':'0x5e5530','bytes':16},{'address':'0x5e5540','bytes':8}],'tail_relocation_symbol':'D_005E5530','tail_addend':16,'tail_alias_address_equivalent':True})
assert not any(r['symbol'] in ('sp','D_005E5540','titlePaletteCopy') for r in refs)
# Check every direct stack access intersecting any of the actual palette objects.
widths={30:16,31:16,32:1,33:2,34:4,35:4,36:1,37:2,38:4,39:4,40:1,41:2,42:4,43:4,44:8,45:8,46:4,49:4,53:8,55:8,57:4,61:8,63:8}
accesses=[]
for i,w in enumerate(words):
 width=widths.get(op(w));offset=si(w)
 if rs(w)!=29 or not width:continue
 matches=[h for h in homes if offset<h+24 and offset+width>h]
 if matches:
  assert len(matches)==1 and matches[0]<=offset and offset+width<=matches[0]+24,(hex(i*4),width,matches)
  accesses.append({'offset':i*4,'object_sp':matches[0],'access_sp':offset,'bytes':width})
assert len(accesses)==10 # five complete LQ/SQ + LD/SD snapshot stores
# Bounded execution interprets emitted loop words, with every memory byte tracked.
def execute(row,values,mutation=None):
 p=row['loop_words'][:]
 if mutation=='source_stride':p[2]=(p[2]&0xffff0000)|128
 if mutation=='destination_stride':p[6]=(p[6]&0xffff0000)|32
 if mutation=='second_word':p[1]&=0xffff0000
 reg=[0]*32;reg[row['src_reg']]=0x1000;reg[row['dst_reg']]=0x2000;reg[row['count_reg']]=3
 memory={0x1000+i*4:v for i,v in enumerate(values)};reads=[];writes=[];pc=0;pending=None;steps=0
 while pc!=9:
  steps+=1;assert steps<40
  w=p[pc];nextpc=pc+1;target=None
  if op(w)==35:
   addr=reg[rs(w)]+si(w);assert addr in memory,'unwritten palette read';reg[rt(w)]=memory[addr];reads.append(addr)
  elif op(w)==43:
   addr=reg[rs(w)]+si(w);assert 0x2000<=addr<0x2018,'palette destination overflow';memory[addr]=reg[rt(w)];writes.append(addr)
  elif op(w)==9:reg[rt(w)]=reg[rs(w)]+si(w)
  elif op(w)==7:
   if reg[rs(w)]>0:target=pc+1+si(w)
  else:assert w==0
  previous=pending;pending=target
  if previous is not None:assert target is None;nextpc=previous
  pc=nextpc
 assert reads==list(range(0x1000,0x1018,4)) and writes==list(range(0x2000,0x2018,4))
 assert [memory[a] for a in writes]==values
 assert (reg[row['src_reg']],reg[row['dst_reg']],reg[row['count_reg']])==(0x1018,0x2018,0)
 # Execute actual selected LW for each valid index using its real local address.
 load=words[row['selected_load']//4]
 for index in range(6):
  address=0x2000-row['destination_sp']+index*4+si(load)
  assert memory[address]==values[index]
 return 6
cases=0;negative=[]
for row in loops:
 for values in [real,*[[((v+i*37)&255)<<(channel*8) | (0x963157ac&~(255<<(channel*8))) for i in range(6)] for channel in range(4) for v in range(256)]]:
  cases+=execute(row,values)
 for mutation in ('source_stride','destination_stride','second_word'):
  try:execute(row,[0x981031+i*0x1020304 for i in range(6)],mutation)
  except AssertionError:negative.append({'copy_offset':row['offset'],'mutation':mutation,'rejected':True})
  else:raise AssertionError(('mutation survived',mutation))
report={'source_sha256':record['source_sha256'],'retail_sha1':windows['sha1'],'frame':frame,'snapshots':snapshots,'copies':[{k:v for k,v in row.items() if k!='loop_words'} for row in loops],'all15objects_disjoint':True,'direct_palette_stack_accesses':accesses,'disjoint_from_prior50colors':True,'executed_copy_selection_cases':cases,'negative_controls':negative,'scope':'actual emitted pair loops and selected LW; source snapshot instruction/address audit; no model draw, ACC, whole-controller or renderer execution'}
(R/'palette-machine-evidence.json').write_text(json.dumps(report,indent=2)+'\n');print(f'Five actual snapshots, ten loops, all local selections verified; {cases} loop/index cases; {len(negative)} controls rejected')
