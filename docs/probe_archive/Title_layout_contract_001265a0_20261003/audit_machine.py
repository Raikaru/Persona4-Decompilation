"""Execute actual retail/emitted selection, raw field and speed instructions.

Callbacks record arguments and clobber caller-saved registers. They deliberately
change the selected row and model slot; provider storage executes actual retail
instructions. Negative signed model words only run conversion/predicate slices.
No pointer is formed from a negative or large converted model index.
"""
from pathlib import Path
import hashlib,json,math,struct,sys
sys.path[:0]=['tools','tests'];import verify as V
from test_title_layout_contract import RECORD_WORDS
P=Path('proof');cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS);retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1']);gp,symbols=V.symbol_addresses()
rec=json.loads((P/'title-layout-owner/after-guard.json').read_text());sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert rec['source_sha256']==sha
fn=rec['functions']['func_001265a0'];raw=bytes.fromhex(fn['bytes']);linked=bytearray(raw)
def si(w):return (w&65535)-65536 if w&32768 else w&65535
def signed(v):v&=0xffffffff;return v-0x100000000 if v&0x80000000 else v
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def floating(v):assert v is not None;return struct.unpack('<f',struct.pack('<I',v&0xffffffff))[0]
# Resolve only actual named references needed by these bounded scopes. No
# relocation masks, zeroed immediates or guessed symbol destinations are used.
names={'D_005E5230','D_005E523C','D_005E5240','D_005E5248','D_005E5254','D_005E5548','fGpffff9c8c','fGpffff8110','func_004782b0','func_00479940','func_0045c870','func_0046d730','func_0047a0e0'}
resolved=[]
for r in fn['relocations']:
 if not isinstance(r['symbol'],str) or r['symbol'] not in names:continue
 at=r['offset'];w=struct.unpack_from('<I',linked,at)[0];addr=V.resolve_symbol(r['symbol'],gp,symbols);assert addr is not None
 if r['r_type']==4:assert w&0x3ffffff==0;value=(w&0xfc000000)|(addr>>2)
 elif r['r_type']==5:assert w&65535==0;value=(w&0xffff0000)|((addr+0x8000)>>16)
 elif r['r_type']==6:assert w&65535==0;value=(w&0xffff0000)|(addr&65535)
 elif r['r_type']==7:assert w&65535==0 and -32768<=addr-gp<=32767;value=(w&0xffff0000)|((addr-gp)&65535)
 else:raise AssertionError(r)
 struct.pack_into('<I',linked,at,value);resolved.append({'offset':at,'symbol':r['symbol'],'address':addr,'type':r['r_type'],'addend':0})
CODES={'candidate':{i:struct.unpack_from('<I',linked,i)[0] for i in range(0,len(linked),4)},'retail':{a:struct.unpack('<I',retail.bytes_at(a,4))[0] for a in range(0x1265a0,0x12aa70,4)}}
PROVIDER={a:struct.unpack('<I',retail.bytes_at(a,4))[0] for a in range(0x47a0e0,0x47a114,4)}
class Machine:
 def __init__(self,kind,row=0,index=0,result=1,mutate=0,counter=0,mutation=None):
  self.kind=kind;self.g=[None]*32;self.f=[None]*32;self.g[0]=0;self.g[28]=gp;self.g[29]=0x10000000;self.g[20]=0x20000000
  self.work=self.g[20];self.mem={};self.reads=[];self.writes=[];self.calls=[];self.code=CODES[kind].copy() if mutation else CODES[kind];self.valid=0;self.animate=0;self.speed=0;self.phase=0
  self.rows=[r[:] for r in RECORD_WORDS];self.row=row;self.firstModel=self.rows[row][0] if index==16 else index;self.rows[row][0]=self.firstModel
  self.secondRow=(row+1)%19;self.secondModel=self.rows[self.secondRow][0] if index==16 else (index+1)%16
  self.result=result;self.mutate=mutate;self.counter=counter;self.slot=self.firstModel
  for n,r in enumerate(self.rows):
   for off,v in enumerate(r):self.seed(0x5e5230+n*40+off*4,v)
  self.seed(self.work+12,counter);self.seed(self.work+132,row)
  for n in range(15):self.seed(self.work+68+n*4,self.model(n))
  for n in range(32):self.seed(self.model(n)+216,0x5a5a5a5a)
  self.seed(gp-0x6374,0x3f000000);self.seed(gp-0x7ef0,0x3df5c28f)
  self.initial=self.model(self.slot);self.reload=self.model((self.slot+17)%32)
  self.providerOnly=False;self.raw_speed=0x3df5c28f
  if kind=='candidate':self.g[16]=self.work+12
  if mutation:
   at,value=mutation;self.code[at]=value
 def model(self,n):return 0x30000000+n*0x400
 def seed(self,a,v):
  for i,b in enumerate((v&0xffffffff).to_bytes(4,'little')):self.mem[a+i]=b
 def read(self,a,n=4):
  assert all(a+i in self.mem for i in range(n)),('unseeded',hex(a),n)
  self.reads.append((a,n));return int.from_bytes(bytes(self.mem[a+i] for i in range(n)),'little')
 def write(self,a,v):
  assert self.work<=a<self.work+0x200 or self.g[29]<=a<self.g[29]+0x800 or any(self.model(n)<=a<self.model(n)+0x400 for n in range(32)),('invalid store',hex(a))
  self.writes.append((a,v&0xffffffff));self.seed(a,v)
 def call(self,addr):
  self.calls.append(addr);ret=None
  if addr==0x4782b0:
   assert self.g[4]==self.initial,('validator pointer',self.g[4],self.initial);self.valid+=1
   if self.mutate:self.seed(self.work+68+self.slot*4,self.reload)
   ret=self.result
  elif addr==0x479940:
   assert self.phase==0;assert self.g[4]==(self.reload if self.mutate else self.initial)
   assert self.g[5:9]==[0,2,0,1];self.animate+=1
  elif addr==0x45c870:
   assert self.phase==0 and self.g[5]==1;assert self.read(self.g[4])==0x3f000000
   self.phase=1;self.slot=self.secondModel;self.seed(self.work+132,self.secondRow);self.seed(0x5e5230+self.secondRow*40,self.secondModel)
   self.initial=self.model(self.slot);self.reload=self.model((self.slot+17)%32);self.seed(self.work+68+self.slot*4,self.initial)
  elif addr==0x47a0e0:
   assert self.g[5]==0 and self.f[12] is not None;self.speed+=1
   if self.providerOnly:assert self.g[4]==self.model(0) and self.f[12]==self.raw_speed
   else:
    assert self.phase==1 and self.g[4]==(self.reload if self.mutate else self.initial)
    row=self.rows[self.secondRow];assert self.f[12]==row[9]
    regs=(24,23,21) if self.kind=='retail' else (21,26,20)
    assert [self.f[r] for r in regs]==[row[3],row[4],row[6]]
   self.write(self.g[4]+244,self.f[12]);self.write(self.g[4]+580,self.f[12])
  else:raise AssertionError(('unexpected call',hex(addr)))
  for r in (*range(1,16),24,25):self.g[r]=None
  for r in range(20):self.f[r]=None
  self.g[2]=ret
 def run(self,start,stops):
  pc=start;pending=None;steps=0
  while pc not in stops:
   steps+=1;assert steps<250;w=self.code[pc];op=w>>26;rs=w>>21&31;rt=w>>16&31;rd=w>>11&31;fd=w>>6&31;fun=w&63;nextpc=pc+4;target=None
   if w==0:pass
   elif op==15:self.g[rt]=(w&65535)<<16
   elif op==9:self.g[rt]=(self.g[rs]+si(w))&0xffffffff
   elif op==10:self.g[rt]=int(signed(self.g[rs])<si(w))
   elif op==11:self.g[rt]=int((self.g[rs]&0xffffffff)<(si(w)&0xffffffff))
   elif op==12:self.g[rt]=self.g[rs]&(w&65535)
   elif op==13:self.g[rt]=self.g[rs]|(w&65535)
   elif op in (35,36,49):
    v=self.read((self.g[rs]+si(w))&0xffffffff,1 if op==36 else 4)
    if op==49:self.f[rt]=v
    else:self.g[rt]=v
   elif op in (43,57):self.write((self.g[rs]+si(w))&0xffffffff,self.f[rt] if op==57 else self.g[rt])
   elif op==0:
    if fun==0:self.g[rd]=(self.g[rt]<<fd)&0xffffffff
    elif fun in (33,45):self.g[rd]=(self.g[rs]+self.g[rt])&0xffffffff
    elif fun==36:self.g[rd]=self.g[rs]&self.g[rt]
    elif fun==37:self.g[rd]=self.g[rs]|self.g[rt]
    elif fun==8:target=self.g[rs]
    else:raise AssertionError(('special',hex(pc),hex(w)))
   elif op in (4,5,6):
    cond=(self.g[rs]==self.g[rt]) if op==4 else (self.g[rs]!=self.g[rt]) if op==5 else signed(self.g[rs])<=0
    if cond:target=pc+4+si(w)*4
   elif op==17:
    if rs==0:self.g[rt]=self.f[rd]
    elif rs==4:self.f[rd]=self.g[rt]
    elif rs==20 and fun==32:self.f[fd]=bits(signed(self.f[rd]))
    elif rs==16 and fun==36:
     v=floating(self.f[rd]);assert -2147483648<=v<2147483648;self.f[fd]=math.trunc(v)&0xffffffff
    elif rs==16 and fun==6:self.f[fd]=self.f[rd]
    else:raise AssertionError(('cop1',hex(pc),hex(w)))
   elif op==3:
    assert self.code[pc+4]==0;self.call((w&0x3ffffff)<<2);nextpc=pc+8
   else:raise AssertionError(('opcode',hex(pc),hex(w)))
   prev=pending;pending=target
   if prev is not None:assert target is None;nextpc=prev
   pc=nextpc;assert self.g[0]==0
  assert pending is None;return self
 def check(self):
  first=self.counter==0 and self.firstModel<15;second=self.secondModel<15
  assert self.valid==first+second and self.animate==bool(first and self.result)
  assert self.speed==bool(second and self.result) and self.phase==1
  assert self.read(self.work+12)==(self.counter+1 if self.counter<600 else self.counter)
  if second and self.result:
   p=self.reload if self.mutate else self.initial
   assert self.read(p+244)==self.rows[self.secondRow][9] and self.read(p+580)==self.rows[self.secondRow][9]
   flags=[v for a,v in self.writes if a==p+216];v=0x5a5a5a5a&~8
   assert flags==[v,v|0x10,v|0x10|0x100000,v|0x10|0x100000|0x40000]
  return self

def execute(kind,row,index,result,mutate,counter,mutation=None):
 m=Machine(kind,row,index,result,mutate,counter,mutation)
 start=0x12a024 if kind=='retail' else 0x3754;stops=(0x12a25c,0x12a4d4) if kind=='retail' else (0x396c,0x3bec)
 return m.run(start,stops).check()
count=0
for kind in ('retail','candidate'):
 for row in range(19):
  for index in range(17):
   for result in (0,1,2,-1):
    for mutate in (0,1):
     for counter in (0,599,600):execute(kind,row,index,result,mutate,counter);count+=1
# Negative/large model conversion never runs a slot-address instruction.
probes=[(0,0),(14,14),(15,15),(256,256),(-1,-1),(-256,-256),(16777217,16777216),(-16777217,-16777216),(-2147483648,-2147483648),(2147483520,2147483520)]
conversion_cases=0
for kind in ('retail','candidate'):
 for start,stop in (((0x12a030,0x12a064),(0x12a0fc,0x12a130)) if kind=='retail' else ((0x3764,0x3798),(0x382c,0x3860))):
  for row in range(19):
   for value,want in probes:
    m=Machine(kind,row);m.seed(0x5e5230+row*40,value);m.run(start,(stop,));assert signed(m.g[3])==want and m.g[2]==int(want<15);conversion_cases+=1
# Actual unsigned row diagnostic predicate in isolation, before any invalid read.
for kind,at,reg in (('retail',0x12a210,17),('candidate',0x3920,18)):
 for value,want in ((0,1),(18,1),(19,0),(0xffffffff,0)):
  m=Machine(kind);m.g[reg]=value;m.run(at,(at+4,));assert m.g[2]==want
# Both earlier speed boundaries use the actual unchanged GP raw float expression.
early=0
for kind,start,stop in (('retail',0x1278e8,0x1278f8),('candidate',0x12b4,0x12c4)):
 for word in (0,0x80000000,0x3df5c28f,0x3f000000,0xc0d98000,0x7f7fffff):
  m=Machine(kind);m.providerOnly=True;m.g[4]=m.model(0);m.raw_speed=word;m.seed(gp-0x7ef0,word);m.run(start,(stop,));assert m.speed==1 and m.read(m.model(0)+244)==word and m.read(m.model(0)+580)==word;early+=1
# Actual provider instructions, including the s32 formal's 0xffff mask, execute
# against a valid sparse model object spanning every masked layer offset.
provider_cases=0
for layer in (0,1,2,65535,65536,-1,-65536):
 for word in (0,0x80000000,0x3f800000,0xbf800000,0x3df5c28f,0x3f000000,0xc0d98000,0x3effffde,0x7f7fffff,0xff7fffff):
  m=Machine('retail');m.code=PROVIDER;m.g[4]=0x40000000;m.g[5]=layer&0xffffffff;m.g[31]=0xffffffff;m.f[12]=word;m.seed(0x40000244,0x9abcdef0)
  writes=[]
  def write(a,v):
   assert 0x40000000<=a<0x40000000+65536*164+0x248;writes.append((a,v));m.seed(a,v)
  m.write=write;m.run(0x47a0e0,(0xffffffff,));off=(layer&65535)*164+244
  assert writes==[(0x40000000+off,word)]+([(0x40000244,word)] if layer&65535==0 else [])
  assert m.read(0x40000244)==(word if layer&65535==0 else 0x9abcdef0);provider_cases+=1
# Independent machine mutations; each changes a real executed instruction.
mutations={'wrong_record_stride':(0x3770,0x00021940),'first_byte_load':(0x3780,0x90420000),'second_byte_load':(0x3848,0x90420000),'drop_roundtrip':(0x3784,0),'double_slot_scale':(0x3874,0x00031100),'validator_positive_only':(0x388c,0x18400004),'wrong_reload':(0x3894,0x0040882d),'pitch_load':(0x38c8,0xc45a0000),'yaw_load':(0x38d8,0xc4550000),'scale_load':(0x38e8,0xc4550000),'speed_wrong_lane':(0x3960,0xc44e0000),'speed_wrong_layer':(0x395c,0x24050001),'wrong_counter_limit':(0x3800,0x28410259)}
controls=[]
for name,mutation in mutations.items():
 try:execute('candidate',1,2,-1,1,600 if name=='wrong_counter_limit' else 0,mutation)
 except (AssertionError,TypeError):controls.append(name)
 else:raise AssertionError(('survived',name))
for name,at,w in [('unsigned_rejection',0x3794,0x2c62000f),('precision_roundtrip_removed',0x3784,0)]:
 m=Machine('candidate',1,mutation=(at,w));m.seed(0x5e5230+40,-16777217)
 if name=='precision_roundtrip_removed':m.code[0x3788]=0 # identity: omit both conversions
 m.run(0x3764,(0x3798,))
 assert signed(m.g[3])!=-16777216 or m.g[2]!=1;controls.append(name)
m=Machine('candidate',mutation=(0x12b8,0xc78e8110));m.providerOnly=True;m.g[4]=m.model(0)
try:m.run(0x12b4,(0x12c4,))
except (AssertionError,TypeError):controls.append('early_speed_wrong_lane')
else:raise AssertionError('early lane survived')
r={'source_sha256':sha,'retail_sha1':windows['sha1'],'executed_full_selection_cases':count,'conversion_predicate_only_cases':conversion_cases,'unsigned_diagnostic_predicate_cases':8,'earlier_speed_cases':early,'actual_provider_instruction_cases':provider_cases,'negative_controls':controls,'resolved_references':resolved,'candidate_selection_slice_sha256':hashlib.sha256(raw[0x3754:0x396c]).hexdigest(),'retail_selection_slice_sha256':hashlib.sha256(retail.bytes_at(0x12a024,0x238)).hexdigest(),'full_selection_domain':'Rows0..18; actual retail model words or synthetic0..15, with15 rejecting before pointer formation; counters0,599,600; validators0,1,2,-1; independent row and slot mutations','negative_model_domain':'Conversion/predicate only, no slot-address instruction, includes±16777217','limits':'Callback recorders only; no complete controller, ACC producer, renderer or hardware-wide float emulation claim'}
(P/'layout-machine-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print(f'{count} actual retail/candidate full selection slices; {conversion_cases} pointer-free conversion probes; {early} early speed and {provider_cases} actual provider cases; {len(controls)} controls rejected')
