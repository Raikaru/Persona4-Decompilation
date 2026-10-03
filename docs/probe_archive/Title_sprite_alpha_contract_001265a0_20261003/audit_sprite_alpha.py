"""Execute actual retail/rebuilt bounded scalar slices; record sprite boundaries.

ACC-derived coordinate/rotation values outside this repair become unknown tokens.
They are never modeled as verified arithmetic and may not reach a checked alpha,
scale or signed16 value. sinf is a controlled, ABI-clobbering boundary.
"""
from pathlib import Path
import hashlib,json,math,struct,sys
sys.path.insert(0,'tools');import verify as V
ROOT=Path.cwd();OUT=ROOT/'proof';cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1']);gp,symbols=V.symbol_addresses()
record=json.loads((OUT/'title-sprite-alpha-owner/after-guard.json').read_text())
assert record['source_sha256']==hashlib.sha256((ROOT/'src/promoted/code1_0012.c').read_bytes()).hexdigest()
fn=record['functions']['func_001265a0'];candidate=bytearray.fromhex(fn['bytes']);refs={r['offset']:r['symbol'] for r in fn['relocations']}
unresolved=set()
for r in fn['relocations']:
 if r['r_type']==7:
  address=V.resolve_symbol(r['symbol'],gp,symbols);w=struct.unpack_from('<I',candidate,r['offset'])[0]
  if address is None:unresolved.add(r['offset']);continue
  assert (w&65535)==0;struct.pack_into('<I',candidate,r['offset'],(w&0xffff0000)|((address-gp)&65535))
retail_code=retail.bytes_at(0x1265a0,17616)
retail_sites=[(0x126938,0x1269a8),(0x128438,0x1284a8),(0x128548,0x1285fc),(0x1286a8,0x12871c),(0x128c88,0x128cf8),(0x129220,0x1292d8),(0x1292e0,0x12938c),(0x129f38,0x129fd0),(0x12a520,0x12a598),(0x12a5ec,0x12a69c)]
candidate_sites=[(0x368,0x3dc),(0x1e6c,0x1ee0),(0x1f88,0x2014),(0x20c8,0x2140),(0x2690,0x2704),(0x2bf8,0x2cac),(0x2cb4,0x2d4c),(0x38c0,0x3960),(0x3f2c,0x3fac),(0x4000,0x4098)]
for site,((a,b),(c,d)) in enumerate(zip(retail_sites,candidate_sites)):
 assert struct.unpack('<I',retail.bytes_at(a,4))[0]==0x3c024f00
 assert struct.unpack_from('<I',candidate,c)[0]==0x3c024f00
 expected='func_0025f430' if site in (2,5,6,7,9) else 'func_0025f3f0'
 assert refs[d]==expected
 assert struct.unpack('<I',retail.bytes_at(b,4))[0]==0x0c000000|(int(expected[5:],16)>>2)
constants={}
for name,bits in [('fGpffff8094',0x3fc90fdb),('fGpffff8170',0x3f19999a)]:
 address=V.resolve_symbol(name,gp,symbols);assert retail.bytes_at(address,4)==struct.pack('<I',bits)
 constants[name]={'address':hex(address),'bits':hex(bits)}

def signed(v,n=32):v&=(1<<n)-1;return v-(1<<n) if v>>(n-1) else v
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def floating(v):assert v is not None,'unknown value reached checked arithmetic';return struct.unpack('<f',struct.pack('<I',v&0xffffffff))[0]
def rounded(v):return floating(bits(v))
def integer(v):
 word=bits(v);exponent=((word>>23)&255)-127;mantissa=(word&0x7fffff)|0x800000
 mag=0 if exponent<0 else mantissa>>(23-exponent) if exponent<=23 else mantissa<<(exponent-23)
 return (-mag if word>>31 else mag)&0xffffffff

CODE = {'retail': {0x1265a0+i:struct.unpack_from('<I',retail_code,i)[0] for i in range(0,len(retail_code),4)},
        'candidate': {i:struct.unpack_from('<I',candidate,i)[0] for i in range(0,len(candidate),4)}}

class Machine:
 def __init__(self,kind,start,stop,frame=136,sine=(0.3125,-0.3125),mutation=None):
  self.kind=kind;self.pc=start;self.stop=stop;self.frame=frame;self.sine=sine;self.calls=[];self.truncations=[];self.steps=0;self.cmp=False;self.pending=None
  data=retail_code if kind=='retail' else candidate;base=0x1265a0 if kind=='retail' else 0
  self.code=CODE[kind].copy() if mutation else CODE[kind]
  self.g=[0]*32;self.f=[bits(0.125)]*32;self.work=0x10000000;self.resource=0x23456780
  self.g[28]=gp
  if kind=='retail':self.g[20]=self.work;self.g[16]=frame;self.g[18]=0xffffff
  else:self.g[18]=self.work;self.g[17]=self.work+60;self.g[20]=frame;self.g[16]=0xffffff
  self.acc=None
  if mutation:
   at,value=mutation;self.code[at]=value
 def load(self,address):
  if address==self.work+60:return self.resource
  assert gp-0x8000<=address<=gp+0x7fff,('unexpected read',hex(self.pc),hex(address))
  return struct.unpack('<I',retail.bytes_at(address,4))[0]
 def run(self):
  while self.pc!=self.stop:
   self.steps+=1;assert self.steps<512
   pc=self.pc;w=self.code[pc];op=w>>26;rs=w>>21&31;rt=w>>16&31;rd=w>>11&31;sh=w>>6&31;f=w&63;imm=w&65535;si=signed(imm,16)
   target=None;nextpc=pc+4
   if w==0:pass
   elif op==15:self.g[rt]=signed(imm<<16)
   elif op==13:self.g[rt]=self.g[rs]|imm
   elif op==12:self.g[rt]=self.g[rs]&imm
   elif op==9:self.g[rt]=signed(self.g[rs]+si)
   elif op==10:self.g[rt]=int(signed(self.g[rs])<si)
   elif op==35:self.g[rt]=signed(self.load((self.g[rs]+si)&0xffffffff))
   elif op==49:
    assert self.kind=='retail' or pc not in unresolved,('unresolved load',hex(pc))
    self.f[rt]=self.load((self.g[rs]+si)&0xffffffff)
   elif op==0:
    if f==45:self.g[rd]=self.g[rs]+self.g[rt]
    elif f==37:self.g[rd]=self.g[rs]|self.g[rt]
    elif f==60:self.g[rd]=(self.g[rt]<<(32+sh))&0xffffffffffffffff
    elif f==63:self.g[rd]=signed(self.g[rt],64)>>(32+sh)
    elif f==62:self.g[rd]=(self.g[rt]&0xffffffffffffffff)>>(32+sh)
    else:raise AssertionError(('special',hex(pc),hex(w)))
   elif op in (4,5):
    if (self.g[rs]==self.g[rt])==(op==4):target=pc+4+si*4
   elif op==17:
    if rs==4:self.f[rd]=self.g[rt]&0xffffffff
    elif rs==0:assert self.f[rd] is not None;self.g[rt]=signed(self.f[rd])
    elif rs==8:
     if self.cmp==bool(rt&1):target=pc+4+si*4
    elif rs==20 and f==32:self.f[sh]=bits(signed(self.f[rd]))
    elif rs==16:
     if f in (24,26):self.acc=None
     elif f in (28,30):self.f[sh]=None
     elif f==6:self.f[sh]=self.f[rd]
     elif f in (52,54):self.cmp=floating(self.f[rd])<floating(self.f[rt]) if f==52 else floating(self.f[rd])<=floating(self.f[rt])
     elif f==36:
      v=floating(self.f[rd]);assert -2147483648<=v<2147483648,('undefined conversion',hex(pc),v)
      self.f[sh]=math.trunc(v)&0xffffffff;self.truncations.append(pc)
     else:
      a=floating(self.f[rd]);b=floating(self.f[rt]);assert f in (0,1,2,3),(hex(pc),hex(w))
      self.f[sh]=bits(a+b if f==0 else a-b if f==1 else a*b if f==2 else a/b)
    else:raise AssertionError(('cop1',hex(pc),hex(w)))
   elif op==3:
    assert self.code[pc+4]==0
    name=refs[pc] if self.kind=='candidate' else {0x44b7b0:'sinf',0x25f430:'func_0025f430',0x25f3f0:'func_0025f3f0'}[(w&0x3ffffff)<<2]
    if name=='sinf':
     n=len([x for x in self.calls if x[0]=='sinf']);assert n<2
     phase=self.frame if n==0 else max(0,self.frame-135);divisor=225 if n==0 else 90
     expected=rounded(rounded(floating(0x3fc90fdb)*phase)/divisor)
     assert self.f[12]==bits(expected),(self.kind,hex(pc),floating(self.f[12]),expected)
     self.calls.append((name,pc,self.f[12]))
     # Clobber caller-saved float registers, preserving only ABI callee-saved f20+.
     for j in range(20):self.f[j]=None
     self.f[0]=bits(self.sine[n])
    else:
     self.calls.append((name,pc,self.g[5],signed(self.g[10]),signed(self.g[11]),self.f[16],self.f[17]))
     for j in range(20):self.f[j]=None
    nextpc=pc+8
   else:raise AssertionError(('opcode',hex(pc),hex(w)))
   previous=self.pending;self.pending=target
   if previous is not None:assert target is None;nextpc=previous
   self.pc=nextpc;assert self.g[0]==0
  assert self.pending is None
  return self

def conversion(kind,site,value,scale=1.25,mutation=None):
 start,call=(retail_sites if kind=='retail' else candidate_sites)[site]
 m=Machine(kind,start,call,mutation=mutation)
 reg=(2 if site==2 else 21 if site in (5,6) else 1) if kind=='retail' else (20 if site in (5,6) else 1)
 m.f[reg]=bits(value)
 if site==5:m.f[16]=bits(scale);m.f[2]=bits(rounded(137*scale)) if kind=='retail' else m.f[2]
 m.run();assert m.g[5]==integer(value)&255,(kind,site,value,m.g[5])
 if site==5:
  expected=signed(integer(rounded(137*scale)),16)
  assert (signed(m.g[10]),signed(m.g[11]))==(expected,expected)
  assert m.f[16]==m.f[17]==bits(scale)
 return m

values=[]
for exponent in range(159):
 for mantissa in (0,1,2,0x3fffff,0x400000,0x7ffffd,0x7ffffe,0x7fffff):
  for sign in range(2):
   if sign and exponent==158 and mantissa:continue
   values.append(floating((sign<<31)|(exponent<<23)|mantissa))
count=0
for site in range(10):
 for value in values:
  for kind in ('retail','candidate'):conversion(kind,site,value);count+=1
subgraphs=0
for frame in (26,134,135,136,137,224,225):
 for first in (-1,-.75,-.3125,-.0625,0,.0625,.3125,.75,1):
  for second in (-1,-.75,-.3125,-.0625,0,.0625,.3125,.75,1):
   scale=rounded(floating(0x3f19999a)+rounded(1.5*first));alpha=integer(rounded(255*rounded(1-second)))&255;pair=signed(integer(rounded(137*scale)),16)
   for kind,start,stop in [('retail',0x129148,0x129394),('candidate',0x2b34,0x2d54)]:
    m=Machine(kind,start,stop,frame,(first,second)).run();calls=[x for x in m.calls if x[0]=='func_0025f430']
    assert len(calls)==2 and calls[0][2:]==(alpha,pair,pair,bits(scale),bits(scale)),(kind,calls,scale,pair)
    assert calls[1][2]==alpha and calls[1][3:5]==(107,230)
    assert len(m.truncations)==(3 if kind=='retail' else 4) # candidate retains unrelated second-scale numeric cast
    subgraphs+=1
negative=[]
for site,(start,call) in enumerate(candidate_sites):
 for name,value,at,word in [('old_low',127.75,start+56,0x44800000),('wrong_high',2147483648.0,start+40,0x34420080)]:
  try:conversion('candidate',site,value,mutation=(at,word))
  except AssertionError:negative.append({'site':site,'mutation':name,'rejected':True})
  else:raise AssertionError(('survived',site,name))
for name,at,word in [('alpha_drives_pair',0x2c4c,0x46140002),('pair_unsigned',0x2c60,0x000a543e),('wrong_pair_slot',0x2ca0,0x0000582d)]:
 try:conversion('candidate',5,127.75,-.75,mutation=(at,word))
 except AssertionError:negative.append({'site':5,'mutation':name,'rejected':True})
 else:raise AssertionError(('survived',name))
# Pin separately rounded scale, first-return preservation and both alpha source lifetimes.
pins={0x2b6c:0x46000506,0x2bd0:0x46140882,0x2bd8:0x46011400,0x2bf0:0x46000801,0x2bf4:0x46001502,0x2c4c:0x46100002,0x2c50:0x46000024,0x2c5c:0x0002543c,0x2c60:0x000a543f}
for at,word in pins.items():assert struct.unpack_from('<I',candidate,at)[0]==word,(hex(at),hex(word))
provider_words={0x25f49c:0x0140482d,0x25f4a0:0x0160502d,0x25f4a4:0x0c097a88,
                0x25f4dc:0x0140482d,0x25f4e0:0x0160502d,0x25f4e4:0x0c097a88,
                0x25ea70:0x0120902d,0x25ea74:0x0140882d,
                0x25eac8:0xa452001c,0x25eacc:0xa451001e}
for at,word in provider_words.items():assert retail.bytes_at(at,4)==struct.pack('<I',word)
report={'source_sha256':record['source_sha256'],'retail_sha1':windows['sha1'],'candidate_bytes':len(candidate),'constants':constants,'retail_sites':[[hex(a),hex(b)] for a,b in retail_sites],'candidate_sites':[[hex(a),hex(b)] for a,b in candidate_sites],'conversion_invocations':count,'subgraph_invocations':subgraphs,'negative_controls':negative,'candidate_dataflow_words':{hex(a):hex(w) for a,w in pins.items()},'provider_signed16_forwarding_and_stores':{hex(a):hex(w) for a,w in provider_words.items()},'unknown_acc_outputs_excluded_from_claim':True,'scope':'real retail/emitted bounded scalar instructions; sinf is controlled, calls recorded, no controller/renderer/gameplay execution'}
(OUT/'sprite-alpha-machine-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print(f'{count} actual retail/emitted conversion slices and {subgraphs} two-sine subgraphs passed; {len(negative)} machine controls rejected')
