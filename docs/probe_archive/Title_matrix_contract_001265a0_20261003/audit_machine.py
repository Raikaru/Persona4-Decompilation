"""Execute emitted axis copies and four-call slice with explicit recorder outputs.

No trig, VU or full provider execution is claimed. Supplied matrix bytes are
boundary test outputs, including deliberate pad tags. Real provider copy loops
are exercised separately with fully initialized test sources.
"""
from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
P=Path('proof');cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS);retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1']);gp,symbols=V.symbol_addresses()
rec=json.loads((P/'title-matrix-owner/after-guard.json').read_text());sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert rec['source_sha256']==sha
fn=rec['functions']['func_001265a0'];raw=bytes.fromhex(fn['bytes']);candidate=bytearray(raw);refs={r['offset']:r['symbol'] for r in fn['relocations']}
for r in fn['relocations']:
 if r['symbol'] not in ('D_005E5628','D_005E5638'):continue
 at=r['offset'];w=struct.unpack_from('<I',candidate,at)[0];addr=V.resolve_symbol(r['symbol'],gp,symbols);assert addr in (0x5e5628,0x5e5638)
 if r['r_type']==5:w|=(addr+0x8000)>>16
 elif r['r_type']==6:w=(w&0xffff0000)|((addr+(w&65535))&65535)
 else:raise AssertionError(r)
 struct.pack_into('<I',candidate,at,w)
assert [(at,refs[at]) for at in (0x39fc,0x3a14,0x3a38,0x3a4c)]==[(0x39fc,'RwMatrixRotate'),(0x3a14,'RwMatrixRotate'),(0x3a38,'RwMatrixTranslate'),(0x3a4c,'func_0047a1c0')]
expected=[0x27a403b0,0x27a50420,0x4600d306,0x0000302d,0x0c000000,0,0x27a403b0,0x27a50410,0x4600ab06,0x24060002,0x0c000000,0,0xafa00400,0x3c02c2b4,0xafa20404,0xafa00408,0x27a403b0,0x27a50400,0x24060001,0x0c000000,0,0x0220202d,0x27a503b0,0x0000302d,0x0c000000,0]
assert raw[0x39ec:0x3a54]==struct.pack('<26I',*expected)
def words(b):return list(struct.unpack('<'+'I'*(len(b)//4),b))
def bits(f):return struct.unpack('<I',struct.pack('<f',f))[0]
def signed(v):v&=0xffffffff;return v-0x100000000 if v&0x80000000 else v
def si(w):return (w&65535)-65536 if w&32768 else w&65535
CODES={'retail':{i:struct.unpack('<I',retail.bytes_at(i,4))[0] for a,b in ((0x1265e4,0x126614),(0x12a25c,0x12a2c4)) for i in range(a,b,4)},'candidate':{i:struct.unpack_from('<I',candidate,i)[0] for a,b in ((0x54,0x84),(0x39ec,0x3a54)) for i in range(a,b,4)}}

class Machine:
 def __init__(self,kind,pattern,mutation=None):
  self.kind=kind;self.sp=0x10000000;self.model=0x23456000+pattern*128;self.g=[None]*32;self.g[0]=0;self.g[29]=self.sp;self.f=[None]*32;self.mem={};self.writes=[];self.reads=[];self.calls=[];self.pattern=pattern
  self.matrix,self.yaw,self.pitch,self.translation=(0x550,0x5c8,0x5b8,0x5a8) if kind=='retail' else (0x3b0,0x420,0x410,0x400)
  self.g[16 if kind=='retail' else 17]=self.model
  self.axis=[struct.pack('<3f',pattern*.125+0.5,-pattern*.25-1,pattern*.5+2),struct.pack('<3f',-pattern*.75-3,pattern*1.25+4,-pattern*1.5-5)]
  self.angles=[bits(pattern*.375-571.25),bits(-pattern*.625+183.875)]
  self.f[23 if kind=='retail' else 26]=self.angles[0];self.f[24 if kind=='retail' else 21]=self.angles[1]
  for a,data in zip((0x5e5628,0x5e5638),self.axis):self.seed(a,data)
  for home,size in ((self.matrix,64),(self.yaw,12),(self.pitch,12),(self.translation,12)):
   self.seed(self.sp+home-4,b'\xa5'*4);self.seed(self.sp+home+size,b'\xa5'*4)
  self.code=CODES[kind].copy();self.matrix_limit=64
  mutations={'axis_tail':(0x68,0),( 'angle'):(0x39f4,0x4600ab06),'first_mode':(0x39f8,0x24060001),'second_mode':(0x3a10,0x24060001),'translation_y':(0x3a20,0x3c0242b4),'translation_z':(0x3a28,0xafa20408),'translation_mode':(0x3a34,0x24060002),'model_pointer':(0x3a40,0x26240001),'model_mode':(0x3a48,0x24060001),'matrix_pointer':(0x39ec,0x27a403b4),'axis_pointer':(0x39f0,0x27a50410)}
  if mutation=='short_matrix':self.matrix_limit=4
  elif mutation:at,w=mutations[mutation];self.code[at]=w
 def seed(self,a,b):self.mem.update({a+i:v for i,v in enumerate(b)})
 def read(self,a,n):
  assert all(a+i in self.mem for i in range(n)),('unwritten read',hex(a),n)
  self.reads.append((a,n));return int.from_bytes(bytes(self.mem[a+i] for i in range(n)),'little')
 def write(self,a,v,n):
  assert any(self.sp+h<=a and a+n<=self.sp+h+s for h,s in ((self.matrix,self.matrix_limit),(self.yaw,12),(self.pitch,12),(self.translation,12))),('out of object',hex(a),n)
  self.writes.append((a,n));self.seed(a,(v&((1<<(n*8))-1)).to_bytes(n,'little'))
 def call(self,pc):
  stage=len(self.calls);name=refs[pc] if self.kind=='candidate' else {0x12a26c:'RwMatrixRotate',0x12a284:'RwMatrixRotate',0x12a2a8:'RwMatrixTranslate',0x12a2bc:'func_0047a1c0'}[pc]
  assert name==('RwMatrixRotate' if stage<2 else 'RwMatrixTranslate' if stage==2 else 'func_0047a1c0')
  m=self.sp+self.matrix
  if stage<3:
   assert self.g[4]==m and self.g[6]==(0,2,1)[stage]
   p=self.sp+(self.yaw if stage==0 else self.pitch if stage==1 else self.translation)
   assert self.g[5]==p
   expected=self.axis[stage] if stage<2 else struct.pack('<3I',0,0xc2b40000,0)
   assert self.read(p,12)==int.from_bytes(expected,'little')
   if stage<2:assert self.f[12]==self.angles[stage]
  else:assert self.g[4]==self.model and self.g[5]==m and self.g[6]==0
  if stage:assert self.read(m,64)==int.from_bytes(self.output,'little')
  if stage<3:
   self.output=bytes((self.pattern*13+stage*79+i*3)&255 for i in range(64));self.write(m,int.from_bytes(self.output,'little'),64)
  self.calls.append(name)
  for r in (*range(1,16),24,25):self.g[r]=None
  for r in range(20):self.f[r]=None
 def run(self,start,end):
  for pc in range(start,end,4):
   w=self.code[pc];op=w>>26;rs=w>>21&31;rt=w>>16&31;rd=w>>11&31;fd=w>>6&31
   if w==0:continue
   if op==15:self.g[rt]=signed((w&65535)<<16)
   elif op==9:self.g[rt]=signed(self.g[rs]+si(w))
   elif op in (55,35,49):
    n=8 if op==55 else 4;v=self.read((self.g[rs]+si(w))&0xffffffff,n)
    if op==49:self.f[rt]=v
    else:self.g[rt]=v
   elif op in (63,43,57):self.write((self.g[rs]+si(w))&0xffffffff,self.f[rt] if op==57 else self.g[rt],8 if op==63 else 4)
   elif op==0 and w&63==45:self.g[rd]=self.g[rs]+self.g[rt]
   elif op==17 and rs==16 and w&63==6:self.f[fd]=self.f[rd]
   elif op==3:assert self.code[pc+4]==0;self.call(pc)
   else:raise AssertionError((hex(pc),hex(w)))
  return self
 def check(self):
  assert len(self.calls)==4
  for home,size in ((self.matrix,64),(self.yaw,12),(self.pitch,12),(self.translation,12)):
   assert self.read(self.sp+home-4,4)==0xa5a5a5a5 and self.read(self.sp+home+size,4)==0xa5a5a5a5
  assert self.read(self.sp+self.yaw,12)==int.from_bytes(self.axis[0],'little') and self.read(self.sp+self.pitch,12)==int.from_bytes(self.axis[1],'little')
  return self

def execute(kind,pattern,mutation=None):
 m=Machine(kind,pattern,mutation)
 for a,b in (((0x1265e4,0x126614),(0x12a25c,0x12a2c4)) if kind=='retail' else ((0x54,0x84),(0x39ec,0x3a54))):m.run(a,b)
 return m.check()
count=0
for kind in CODES:
 for pattern in range(1024):execute(kind,pattern);count+=1
controls=[]
for name in ('axis_tail','angle','first_mode','second_mode','translation_y','translation_z','translation_mode','model_pointer','model_mode','matrix_pointer','axis_pointer','short_matrix'):
 try:execute('candidate',3,name)
 except AssertionError:controls.append(name)
 else:raise AssertionError(('control survived',name))
# Actual candidate storage census. Check all direct memory operations touching
# these objects, and all their address materializations over the entire body.
homes={'matrix':(0x3b0,64),'yaw':(0x420,12),'pitch':(0x410,12),'translation':(0x400,12)}
widths={30:16,31:16,32:1,33:2,35:4,36:1,37:2,39:4,40:1,41:2,43:4,49:4,53:8,55:8,57:4,61:8,63:8,54:16,62:16};access=[];addresses=[]
for at,w in enumerate(words(raw)):
 at*=4;op=w>>26;off=si(w)
 if w>>21&31!=29:continue
 if op in widths:
  n=widths[op];hit=[(name,h,s) for name,(h,s) in homes.items() if off<h+s and off+n>h]
  if hit:
   assert len(hit)==1;name,h,s=hit[0];assert h<=off and off+n<=h+s
   access.append({'instruction':at,'name':name,'home':off,'size':n})
 if op==9:
  hit=[name for name,(h,s) in homes.items() if h<=off<h+s]
  if hit:assert off==homes[hit[0]][0];addresses.append({'instruction':at,'name':hit[0],'home':off})
assert [(x['name'],x['size']) for x in access]==[('yaw',8),('yaw',4),('pitch',8),('pitch',4),('translation',4),('translation',4),('translation',4)]
assert [x['name'] for x in addresses]==['matrix','yaw','matrix','pitch','matrix','translation','matrix']
colors=json.loads((P/'candidate-color-families.json').read_text())['candidate_objects'];alpha=json.loads((P/'alpha-alias-evidence.json').read_text())['alpha_accesses'];palette=json.loads((P/'palette-machine-evidence.json').read_text())
others=[(x,4) for x in colors.values()]+[(x['home'],4) for x in alpha]+[(x['source_sp'],24) for x in palette['snapshots']]+[(x['destination_sp'],24) for x in palette['copies']]+[(0x390,32),(0x3f0,16),(0,0xd0)]
for name,(h,n) in homes.items():
 assert 0<=h and h+n<=0x500 and (name!='matrix' or h%16==0)
 for other,(o,s) in homes.items():assert name==other or h+n<=o or o+s<=h
 for o,s in others:assert h+n<=o or o+s<=h,(name,hex(o),s)
# Execute the actual replacement copy loops with fully supplied source bytes.
# Their input is explicit boundary data; no provider-created padding is read.
def copy_loop(kind,pattern,mutation=None):
 start,end=(0x3e0770,0x3e079c) if kind=='rotate' else (0x3e0e54,0x3e0e7c)
 code={at:struct.unpack('<I',retail.bytes_at(at,4))[0] for at in range(start,end,4)}
 g=[0]*32;g[29]=0x1000;g[16]=0x2000
 source=0x1060 if kind=='rotate' else 0x3000
 if kind=='model':g[5]=source
 mem={source+i:(pattern*17+i*37)&255 for i in range(64)};read=[];write=[]
 if mutation=='short_count':code[start+(4 if kind=='rotate' else 0)]=0x24040007
 if mutation=='source_stride':code[0x3e078c if kind=='rotate' else 0x3e0e70]=0x24c60010 if kind=='rotate' else 0x24a50010
 if mutation=='last_lane':at=0x3e0790 if kind=='rotate' else 0x3e0e6c;code[at]&=0xffff0000
 pc=start;pending=None;steps=0
 while pc<end:
  steps+=1;assert steps<90;w=code[pc];op=w>>26;rs=w>>21&31;rt=w>>16&31;rd=w>>11&31;nextpc=pc+4;target=None
  if op==9:g[rt]=g[rs]+si(w)
  elif op==0 and w&63==45:g[rd]=g[rs]+g[rt]
  elif op==35:
   a=g[rs]+si(w);assert source<=a and a+4<=source+64;g[rt]=int.from_bytes(bytes(mem[a+i] for i in range(4)),'little');read.append(a)
  elif op==43:
   a=g[rs]+si(w);assert 0x2000<=a and a+4<=0x2040
   mem.update({a+i:v for i,v in enumerate((g[rt]&0xffffffff).to_bytes(4,'little'))});write.append(a)
  elif op==7:
   if g[rs]>0:target=pc+4+si(w)*4
  else:raise AssertionError(hex(w))
  prev=pending;pending=target
  if prev is not None:assert target is None;nextpc=prev
  pc=nextpc
 assert pending is None and g[4]==0
 assert read==list(range(source,source+64,4)) and write==list(range(0x2000,0x2040,4))
 assert bytes(mem[0x2000+i] for i in range(64))==bytes(mem[source+i] for i in range(64))
copy_cases=0;copy_controls=[]
for kind in ('rotate','model'):
 for pattern in range(256):copy_loop(kind,pattern);copy_cases+=1
 for name in ('short_count','source_stride','last_lane'):
  try:copy_loop(kind,3,name)
  except AssertionError:copy_controls.append(kind+':'+name)
  else:raise AssertionError(('copy control survived',kind,name))
r={'source_sha256':sha,'retail_sha1':windows['sha1'],'executed_retail_candidate_cases':count,'actual_provider_copy_cases':copy_cases,'provider_copy_controls':copy_controls,'negative_controls':controls,'candidate_homes':homes,'full_object_direct_access_census':access,'full_object_address_census':addresses,'disjoint_from_52_colors_15_palettes_fade_uv_other_live_storage':True,'candidate_axis_slice_sha256':hashlib.sha256(raw[0x54:0x84]).hexdigest(),'candidate_call_slice_sha256':hashlib.sha256(raw[0x39ec:0x3a54]).hexdigest(),'caller_saved_registers_clobbered_at_every_boundary':True,'scope':'Actual axis-copy and call/storage instructions only; complete 64-byte tagged recorder outputs test pointer transport and bounds; no matrix arithmetic, trig/VU or full-provider C execution'}
(P/'matrix-machine-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print(f'{count} retail/candidate bounded machine cases; {len(controls)} controls rejected; complete storage census and disjointness passed')
