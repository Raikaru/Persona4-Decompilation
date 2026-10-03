"""Execute actual defined call-boundary slices; producers are supplied, not modeled.

The disconnected slices preserve only proven live index/color/lane values. Channel
interpolation and the special ACC geometry are excluded. Special retail outputs
are supplied at their six ACC destination boundaries; the candidate retains one
unproven shared expression and copies its supplied output. No geometry equality
for independent retail outputs or full-provider execution is claimed.
"""
from pathlib import Path
import hashlib,json,math,struct,sys
sys.path.insert(0,'tools');import verify as V
P=Path('proof');cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1']);gp,symbols=V.symbol_addresses()
record=json.loads((P/'title-model-owner/after-guard.json').read_text());sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert record['source_sha256']==sha
fn=record['functions']['func_001265a0'];data={'retail':retail.bytes_at(0x1265a0,17616),'candidate':bytes.fromhex(fn['bytes'])}
W={k:list(struct.unpack('<'+'I'*(len(v)//4),v)) for k,v in data.items()}
refs={r['offset']:r for r in fn['relocations']};calls={
 'retail':[i for i in range(0,17616,4) if W['retail'][i//4]==0x0c0492ec],
 'candidate':[r['offset'] for r in fn['relocations'] if r['symbol']=='func_00124bb0']}
assert all(len(c)==5 for c in calls.values())
def op(w):return w>>26
def rs(w):return w>>21&31
def rt(w):return w>>16&31
def rd(w):return w>>11&31
def fd(w):return w>>6&31
def signed(v):return (v&0xffffffff)-0x100000000 if v&0x80000000 else v&0xffffffff
def si(w):return (w&65535)-65536 if w&32768 else w&65535
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def floating(v):return struct.unpack('<f',struct.pack('<I',v&0xffffffff))[0]

rows=[]
for kind in W:
 for site,call in enumerate(calls[kind]):
  w=W[kind];start=max(calls[kind][site-1]+8 if site else 0,call-1100)
  model=[]
  for at in range(start,call-12,4):
   a,b,c,d=w[at//4:at//4+4]
   if op(a)==49 and op(b)==17 and rs(b)==20 and b&63==32 and op(c)==17 and rs(c)==16 and c&63==36 and op(d)==17 and rs(d)==0 and rt(d)==4:
    assert rt(a)==rd(b)==fd(b)==rd(c)==fd(c)==rd(d);model.append(at)
  assert len(model)==1,(kind,site,model)
  if site in (2,3):
   name='D_005E5370' if site==2 else 'D_005E5398';address=int(name[2:],16)
   if kind=='candidate':assert refs[model[0]]['symbol']==name and refs[model[0]]['r_type']==7
   else:
    load=w[model[0]//4];lui=w[model[0]//4-1]
    assert op(lui)==15 and rt(lui)==rs(load) and ((lui&65535)<<16)+si(load)==address

  shifts={n:[at for at in range(start,call,4) if op(w[at//4])==0 and w[at//4]&63==0 and fd(w[at//4])==n] for n in (24,16,8)}
  assert all(len(v)==1 for v in shifts.values()),(kind,site,shifts)
  red,green,blue=(shifts[n][0]-4 for n in (24,16,8))
  for at,n in ((red,24),(green,16),(blue,8)):
   a,b=w[at//4:at//4+2];assert op(a)==12 and a&65535==255 and rt(a)==rt(b) and fd(b)==n
  assert w[call//4-2]==(9<<26)|(7<<16)|(0x40 if site in (2,3) else 0x42)
  assert w[call//4-1]==0x0280402d and w[call//4+1]==0 # actual model pointer s4 -> a4
  special=site in (2,3)
  base=[at for at in range(call-180,call,4) if w[at//4]==0x344500ff]
  assert len(base)==1;base=base[0]-8 # addiu v0,-256; and v0,v1|a1,v0; ori a1
  assert op(w[base//4])==9 and rt(w[base//4])==2 and rs(w[base//4])==0 and si(w[base//4])==-256
  assert op(w[(base+4)//4])==0 and w[(base+4)//4]&63==36
  if not special:
   loads=[]
   for at in range(call-64,call,4):
    a=w[at//4]
    if op(a)==49:loads.append((at,rt(a),si(a),rs(a)))
   assert [(r,o) for at,r,o,b in loads]==[(12,4),(14,8),(15,12),(16,16),(17,20),(18,24)]
   assert len({b for at,r,o,b in loads})==1
  else:
   loads=[]
   if kind=='retail':
    producers=[at for at in range(call-160,call,4) if op(w[at//4])==17 and rs(w[at//4])==16 and w[at//4]&63==28]
    assert [fd(w[at//4]) for at in producers]==[12,14,15,16,17,18]
   else:
    producers=[at for at in range(call-320,call,4) if op(w[at//4])==17 and rs(w[at//4])==16 and w[at//4]&63==28 and fd(w[at//4])==12]
    assert len(producers)==1
    assert w[call//4-7:call//4-2]==[(17<<26)|(16<<21)|(12<<11)|(r<<6)|6 for r in (14,15,16,17,18)]
  zeros=[at for at in range(call-160,call,4) if w[at//4]==0x44806800];assert len(zeros)==1
  rows.append({'kind':kind,'site':site,'call':call,'model':model[0],'red':red,'green':green,'blue':blue,'base':base,'zero':zeros[0],'loads':loads,'special':special,'producers':producers if special else []})

def gpr_definition(w):
 o=op(w)
 if o==0 and w&63 not in (8,12,13):return rd(w)
 if o==17 and rs(w)==0:return rt(w)
 if o in (8,9,10,11,12,13,14,15,24,25,30,32,33,34,35,36,37,38,39,55):return rt(w)
 return None

def fpr_definition(w):
 if op(w)==49:return rt(w)
 if op(w)==17:
  if rs(w)==4:return rd(w)
  if rs(w)==20:return fd(w)
  if rs(w)==16 and w&63 not in (24,25,26,52,54):return fd(w)
 return None

# The actual model-array pointer is the unchanged task-work result, held in s4
# until epilogue. No omitted producer can silently retarget that pointer.
pointer_bindings={}
for kind,words in W.items():
 definitions=[at for at in range(0,len(words)*4,4) if gpr_definition(words[at//4])==20]
 assert len(definitions)==2 and words[definitions[0]//4]==0x0040a02d
 first=definitions[0]-8
 if kind=='candidate':assert refs[first]['symbol']=='func_00452560'
 else:assert words[first//4]==0x0c114958
 assert op(words[definitions[1]//4])==30 and rs(words[definitions[1]//4])==29
 pointer_bindings[kind]={'work_result_move':definitions[0],'epilogue_restore':definitions[1]}

def carried(row,reg,start,stop):
 for at in range(start,stop,4):
  assert gpr_definition(W[row['kind']][at//4])!=reg,('overwritten boundary value',row['kind'],row['site'],reg,hex(at))

for row in rows:
 w=W[row['kind']];red,green,blue,call=(row[n] for n in ('red','green','blue','call'))
 carried(row,4,row['model']+16,call)
 # The top-byte word survives to the actual green OR. For generic candidates
 # that OR is inside the final blue/green packing sequence.
 carried(row,rd(w[(red+4)//4]),red+8,green+8)
 if row['kind']=='retail' or row['special']:
  carried(row,rd(w[(green+8)//4]),green+12,blue+8)
 end=blue+16 if row['kind']=='retail' or row['special'] else blue+28
 assert rt(w[(end-4)//4])==6 and op(w[(end-4)//4])==13
 carried(row,6,end,call)
 carried(row,5,row['base']+12,call)
 for at in range(row['zero']+4,call,4):assert fpr_definition(w[at//4])!=13
 if not row['special']:
  for load,reg,offset,base in row['loads']:
   for at in range(load+4,call,4):assert fpr_definition(w[at//4])!=reg
 else:
  for producer in row['producers']:
   reg=fd(w[producer//4])
   for at in range(producer+4,call,4):assert fpr_definition(w[at//4])!=reg
 row['omitted_spans_preserve_live_integer_values']=True
 row['final_floating_writers_and_zero_lane_checked']=True

class Machine:
 def __init__(self,row,model,fields,base,channels,ptr,index,mutation=None):
  self.row=row;self.g={0:0,20:ptr};self.f={};self.mem={};self.w=W[row['kind']][:] if mutation else W[row['kind']]
  self.model=model;self.fields=fields;self.base=base;self.channels=channels;self.ptr=ptr;self.index=index
  if mutation:
   at,word=mutation;self.w[at//4]=word
 def load(self,at,value):
  w=self.w[at//4];self.g[rs(w)]=0x10000000;self.mem[(self.g[rs(w)]+si(w))&0xffffffff]=value
 def run(self,start,stop):
  for at in range(start,stop,4):
   w=self.w[at//4];o=op(w);a,b,c=rs(w),rt(w),rd(w);f=w&63
   if w==0:continue
   if o==49:self.f[b]=self.mem[(self.g[a]+si(w))&0xffffffff]
   elif o==35:self.g[b]=self.mem[(self.g[a]+si(w))&0xffffffff]
   elif o==9:self.g[b]=(self.g[a]+si(w))&0xffffffff
   elif o==12:self.g[b]=self.g[a]&(w&65535)
   elif o==13:self.g[b]=self.g[a]|(w&65535)
   elif o==0 and f==0:self.g[c]=(self.g[b]<<fd(w))&0xffffffff
   elif o==0 and f==37:self.g[c]=self.g[a]|self.g[b]
   elif o==0 and f==36:self.g[c]=self.g[a]&self.g[b]
   elif o==0 and f in (33,45):self.g[c]=(self.g[a]+self.g[b])&0xffffffff
   elif o==17 and a==4:self.f[c]=self.g[b]
   elif o==17 and a==0:self.g[b]=self.f[c]
   elif o==17 and a==20 and f==32:self.f[fd(w)]=bits(signed(self.f[c]))
   elif o==17 and a==16 and f==36:self.f[fd(w)]=math.trunc(floating(self.f[c]))&0xffffffff
   elif o==17 and a==16 and f==6:self.f[fd(w)]=self.f[c]
   else:raise AssertionError(('unsupported boundary instruction',hex(at),hex(w)))
 def execute(self):
  r=self.row;red,green,blue=self.channels
  self.load(r['model'],self.model&0xffffffff);self.run(r['model'],r['model']+16)
  # Each channel is supplied only at the actual byte-mask input, after the
  # unresolved arithmetic. The actual shift/OR words perform every packing bit.
  self.g[rs(self.w[r['red']//4])]=red;self.run(r['red'],r['red']+8)
  if r['kind']=='retail' or r['special']:
   self.g[rs(self.w[r['green']//4])]=green;self.run(r['green'],r['green']+12)
  else:self.g[rs(self.w[r['green']//4])]=green
  self.g[rs(self.w[r['blue']//4])]=blue
  end=r['blue']+16 if r['kind']=='retail' or r['special'] else r['blue']+28
  self.run(r['blue'],end)
  self.run(r['zero'],r['zero']+4)
  # For candidate the local palette LW is supplied by the separately checked
  # palette-selection proof. Retail already holds that exact selected word.
  andword=self.w[(r['base']+4)//4];raw=rs(andword) if rt(andword)==2 else rt(andword)
  self.g[raw]=self.base;self.run(r['base'],r['base']+12)
  if not r['special']:
   for at,reg,offset,base in r['loads']:
    self.g[base]=0x30000000
    for i,value in enumerate(self.fields):self.mem[0x30000004+i*4]=value
    self.run(at,at+4)
  else:
   # Supply existing source expression result only, never recovered ACC math.
   self.f[12]=self.fields[0]
   if r['kind']=='retail':
    for at in r['producers']:self.f[fd(self.w[at//4])]=self.fields[0]
   else:self.run(r['call']-28,r['call']-8)
  self.run(r['call']-8,r['call'])
  expected=[self.fields[0],0,*self.fields[1:]] if not r['special'] else [self.fields[0],0,*([self.fields[0]]*5)]
  assert [self.f[i] for i in range(12,19)]==expected,'floating lane mismatch'
  assert signed(self.g[4])==math.trunc(floating(bits(self.model))),'model index mismatch'
  assert self.g[5]==self.base&0xffffff00|255,'base word mismatch'
  assert self.g[6]==((red&255)<<24)|((green&255)<<16)|((blue&255)<<8)|255,'highlight word mismatch'
  assert self.g[7]==(0x40 if r['special'] else 0x42),'flag mismatch'
  assert self.g[8]==self.ptr,'model pointer mismatch'

# Actual nineteen retail rows, plus nineteen separately tagged finite records.
records=[]
for index in range(19):
 raw=retail.bytes_at(0x5e5230+40*index,40);v=struct.unpack('<10I',raw)
 assert all(math.isfinite(floating(x)) for x in v[1:7]);records.append((signed(v[0]),list(v[1:7])))
for index in range(19):records.append(((-16777217 if index==17 else 16777217 if index==18 else -index-1) if index&1 else (16777217 if index==18 else index+1),[bits(x) for x in (index*1.25-9.75,index*-2.25+13.125,index*3.5-74.5,index*-4.75+53.25,index*5.25-117.875,index*.375+1.0625)]))
count=0
for r in rows:
 for i,(model,fields) in enumerate(records):
  for pattern in range(1024):
   channel,byte=divmod(pattern,256);base=0x96c31547^(i*0x132735)
   base=(base&~(255<<(channel*8)))|(byte<<(channel*8));channels=[(byte+19)&255,(byte*3+41)&255,(byte*7+83)&255]
   Machine(r,model,fields,base,channels,0x24567800+i*16,i%6).execute();count+=1
controls=[]
for r in rows:
 if r['kind']!='candidate':continue
 mutations=[('red_shift',r['red']+4,(W['candidate'][(r['red']+4)//4]&~(31<<6))|(16<<6)),
 ('green_shift',r['green']+4,(W['candidate'][(r['green']+4)//4]&~(31<<6))|(8<<6)),
 ('flags',r['call']-8,0x24070000),('pointer',r['call']-4,0x26880004)]
 # Direct field/lane substitutions are meaningful only for recovered generic
 # fields; special independent-output arithmetic remains explicitly unproven.
 if not r['special']:
  for j,(at,reg,offset,base) in enumerate(r['loads']):mutations.append(('field_'+str(offset),at,(W['candidate'][at//4]&0xffff0000)|((offset%24)+4)))
 for name,at,w in mutations:
  try:Machine(r,*records[-1],0x963147a8,[129,171,253],0x24567890,5,(at,w)).execute()
  except (AssertionError,KeyError):controls.append({'site':r['site'],'mutation':name,'rejected':True})
  else:raise AssertionError(('control survived',r['site'],name))
report={'source_sha256':sha,'retail_sha1':windows['sha1'],'boundaries':rows,'model_pointer_live_bindings':pointer_bindings,'retail_record_count':19,'distinct_synthetic_records':19,'executed_cases':count,'negative_controls':controls,'provider_executed':False,'special_source_expression_outputs_supplied':True,'special_retail_producer_destinations_audited':True,'special_geometry_equivalence_claimed':False,'limits':'Actual disconnected defined integer packing/model-conversion/ABI slices, supplied channel and special-expression outputs; provider matrix flags and all upstream ACC arithmetic excluded.'}
(P/'model-machine-evidence.json').write_text(json.dumps(report,indent=2)+'\n');print(count,'retail/rebuilt defined boundary cases;',len(controls),'controls rejected')
