"""Authenticate actual retail/candidate helper writers and unchanged providers.

Native observers establish source transport only. Here real emitted words and
relocations authenticate EE lanes; pulse X is expressly supplied after each
ACC output boundary. No unresolved sine/geometry producer is emulated.
"""
from pathlib import Path
import hashlib,json,struct,math,sys
sys.path.insert(0,'tools');import verify as V
A=Path(__file__).resolve().parent;P=Path('proof');evidence=json.loads((A/'retail-contract.json').read_text());cfg=V.load_config();ws=V._read_json(V.FUNCTION_WINDOWS);elf=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),ws['sha1'])
sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();rec=json.loads((P/'title-helper-owner/after-guard.json').read_text());assert rec['source_sha256']==sha
f=rec['functions']['func_001265a0'];raw=bytes.fromhex(f['bytes'])
def word(a):return struct.unpack('<I',elf.bytes_at(a,4))[0]
def bits(v):return struct.unpack('<I',struct.pack('<f',v))[0]
def flt(b):return struct.unpack('<f',struct.pack('<I',b&0xffffffff))[0]
def signed(v):return (v&0x7fffffff)-(v&0x80000000)
def op(w):return w>>26
def rs(w):return w>>21&31
def rt(w):return w>>16&31
def rd(w):return w>>11&31
def fd(w):return w>>6&31
def gdef(w):
 if op(w)==0 and w&63 not in (8,12,13):return rd(w)
 if op(w)==17 and rs(w)==0:return rt(w)
 if op(w) in (8,9,10,11,12,13,14,15,24,25,30,32,33,34,35,36,37,38,39,55):return rt(w)
 return None
for r in evidence['exact_word_receipts']:
 b=elf.bytes_at(int(r['start'],16),r['size']);assert hashlib.sha256(b).hexdigest()==r['sha256'];assert list(struct.unpack('<'+'I'*(len(b)//4),b))==[int(w,16) for w in r['words']]
# Repeat direct-JAL census against all authenticated function windows.
scan={int(k,16):[] for k in evidence['full_function_window_direct_jal_census']}
for start,size in ws['windows'].items():
 a=int(start,16);b=elf.bytes_at(a,size)
 for n,w in enumerate(struct.unpack('<'+'I'*(size//4),b)):
  if op(w)==3 and (w&0x3ffffff)*4 in scan:scan[(w&0x3ffffff)*4].append({'address':a+n*4,'owner':a})
assert {hex(k):v for k,v in scan.items()}==evidence['full_function_window_direct_jal_census']
CODES={'retail':{a:word(a) for a in range(0x1265a0,0x12aa70,4)},'candidate':{a:struct.unpack_from('<I',raw,a)[0] for a in range(0,len(raw),4)}}
CALLS={'retail':[0x126fd0,0x128258,0x129ee4,0x126cd0,0x128e54,0x129008,0x129a88],'candidate':[0x9e8,0x1aa4,0x35c0,0x6e4,0x2668,0x2800,0x3184]}
STARTS={'retail':[0x126fa8,0x128244,0x129ed0,0x126cb0,0x128e38,0x128fe8,0x129a68],'candidate':[0x9c0,0x1a90,0x35ac,0x6cc,0x264c,0x27e8,0x316c]}
relocation_rows=[]
for name,indices in [('func_00124f70',range(3)),('func_00125e80',range(3,7))]:
 refs=[r for r in f['relocations'] if r['symbol']==name];assert [r['offset'] for r in refs]==[CALLS['candidate'][n] for n in indices]
 for n,r in zip(indices,refs):
  at=r['offset'];assert r['r_type']==4 and CODES['candidate'][at]==0x0c000000 and CODES['candidate'][at+4]==0
  assert CODES['retail'][CALLS['retail'][n]]==0x0c000000|(int(name[5:],16)>>2)
  relocation_rows.append({'site':n,'offset':at,'target':name,'addend':0,'delay_slot':0})
# Scene capture is a true stable value from the getter in each complete target.
scene_defs={}
for kind,code in CODES.items():
 defs=[a for a,w in code.items() if gdef(w)==20];assert len(defs)==2
 capture=0x1265e0 if kind=='retail' else 0x50
 assert defs[0]==capture and code[capture]==0x0040a02d and op(code[defs[1]])==30 and rs(code[defs[1]])==29
 scene_defs[kind]=defs
# Exact provider entry readers and meaningful full-width uses, unchanged bodies.
roles={0x125018:0x0000302d,0x125a9c:0x44950000,0x125aa4:0x46800060,0x125d20:0x02a31825,0x125d6c:0x02a31825,0x125db8:0x02a31825,0x125e04:0x02a21025,0x125f50:0x322500ff,0x125f58:0x4600a386,0x125f70:0x8e08003c,0x125f98:0x46160080,0x125fa8:0x46150040,0x126048:0x4600a306}
for a,w in roles.items():assert word(a)==w
providers=[]
for name,window in [('func_00124f70',3856),('func_00125e80',528),('func_00126090',1296)]:
 a=int(name[5:],16);record=rec['functions'][name];b=bytes.fromhex(record['bytes']);want=elf.bytes_at(a,window);diff,_=V.compare(b,record['relocations'],want);assert diff==0 and not any(want[len(b):])
 if hex(a) in evidence['providers']:assert hashlib.sha256(want).hexdigest()==evidence['providers'][hex(a)]['retail_sha256']
 providers.append({'name':name,'bytes':len(b),'window':window,'normalized_difference':0,'zero_tail_bytes':window-len(b),'retail_sha256':hashlib.sha256(want).hexdigest(),'candidate_sha256':hashlib.sha256(b).hexdigest()})
class M:
 def __init__(self,kind,index,pointer,phase,x,mutation=None):
  self.code=CODES[kind];self.g={0:0,19:index,23:index,20:pointer,15:0x12345678};self.f={21:bits(phase),24:bits(phase),12:bits(x)};self.mutation=mutation
 def run(self,start,end):
  for a in range(start,end,4):
   w=self.code[a]
   if self.mutation and self.mutation[0]==a:w=self.mutation[1]
   o=op(w);s,t,d=rs(w),rt(w),rd(w);n=w&65535;imm=n-65536 if n&32768 else n;fun=w&63
   if w==0:continue
   if o==15:self.g[t]=n<<16
   elif o==9:self.g[t]=(self.g[s]+imm)&0xffffffff
   elif o==0 and fun==45:self.g[d]=(self.g[s]+self.g[t])&0xffffffff
   elif o==17 and s==4:self.f[d]=self.g[t]
   elif o==17 and s==0:self.g[t]=self.f[d]
   elif o==17 and s==16 and fun==2:self.f[fd(w)]=bits(flt(self.f[d])*flt(self.f[t]))
   elif o==17 and s==16 and fun==36:self.f[fd(w)]=math.trunc(flt(self.f[d]))&0xffffffff
   else:raise AssertionError((hex(a),hex(w),'unsupported'))
  self.g[0]=0

def case(kind,n,index,pointer,phase,x,mutation=None):
 call=CALLS[kind][n];start=STARTS[kind][n];m=M(kind,index,pointer,phase,x,mutation)
 if n in (3,5,6):
  # X is an explicit supplied boundary. Execute the actual zero-Y writer;
  # authenticate, but do not execute or claim equivalence of, ACC producers.
  m.run(start,start+4)
  if kind=='candidate':assert m.code[call-20]==0x4616bb1d
  else:assert m.code[call-20] in (0x46020b1d,0x4600131d)
  m.run(call-16,call)
 else:m.run(start,call)
 assert m.code[call+4]==0
 if n<3:
  got=[signed(m.g[k]) for k in (4,5,6,7)]+[m.g[8]]
  want=[index,math.trunc(flt(bits(255.*flt(bits(phase))))),0,1,pointer] if n==0 else [10,255,255,64,pointer]
 else:
  got=[m.f[k] for k in (12,13,14)]+[signed(m.g[4]),m.g[5]]
  want=[bits(200. if n==4 else x),bits(0.),bits(10.),[178,255,255,153][n-3],pointer]
 assert got==want,(kind,n,got,want)
 return got
runs=0
for kind in CODES:
 for ptr in (0x10008000,0xe5002400):
  for idx in range(1,8):
   for phase in (-.875,-.5,-.125,-0.,0.,.125,.49,.5,.75,.999):
    for x in (-500.5,-1.25,-0.,.5,200.,1000.25):
     for n in range(7):case(kind,n,idx,ptr,phase,x);runs+=1
# Actual writer mutations, 32 each: pulse-X arithmetic is outside the scope.
rejections=[]
for kind in CODES:
 for n,start in enumerate(STARTS[kind]):
  call=CALLS[kind][n];mutations=[]
  if n<3:
   sites=[call-16,call-20,call-12,call-8,call-4] if n==0 else [call-20,call-16,call-12,call-8,call-4]
   for pos,a in enumerate(sites):
    old=CODES[kind][a]
    if op(old)==9:new=(old&~65535)|((old+1)&65535)
    elif op(old)==17:new=(old&~(31<<11))|(12<<11)
    else:new=(old&~(31<<21))|(15<<21)
    mutations.append((pos,a,new))
  else:
   y=start if n!=4 else start+8
   for pos,a,new in [(1,y,(CODES[kind][y]&~(31<<16))|(15<<16)),(2,call-16,CODES[kind][call-16]^0x10),(3,call-8,CODES[kind][call-8]^1),(4,call-4,(CODES[kind][call-4]&~(31<<21))|(15<<21))]:mutations.append((pos,a,new))
   if n==4:mutations.append((0,start,CODES[kind][start]^1))
  for field,a,new in mutations:
   try:case(kind,n,5,0x10008000,.75,321.25,(a,new))
   except AssertionError:rejections.append({'kind':kind,'site':n,'field':field,'address':hex(a),'word':hex(new)})
   else:raise AssertionError(('undetected',kind,n,field,hex(a)))
receipts=[]
for kind in CODES:
 for n,start in enumerate(STARTS[kind]):
  call=CALLS[kind][n];b=b''.join(struct.pack('<I',CODES[kind][a]) for a in range(start,call+8,4));receipts.append({'kind':kind,'site':n,'start':start,'call':call,'size':len(b),'sha256':hashlib.sha256(b).hexdigest(),'pulse_X_supplied':n in (3,5,6)})
r={'source_sha256':sha,'retail_sha1':ws['sha1'],'cases':runs,'cases_per_machine':runs//2,'machine_controls':rejections,'writer_receipts':receipts,'candidate_resolved_call_targets':relocation_rows,'providers':providers,'provider_role_words':{hex(a):hex(w) for a,w in roles.items()},'scene_only_definitions':scene_defs,'direct_call_census':{hex(k):v for k,v in scan.items()},'limits':'Actual retail/candidate final writer slices, with pulse X supplied after authenticated ACC output. No sine/ACC producer or complete provider execution. Native typed observers alone do not establish EE ABI. Independent register banks do not prove unique cross-bank source chronology; exact existing providers supply source order.'}
(P/'helper-machine-evidence.json').write_text(json.dumps(r,indent=2)+'\n');print(f'{runs} actual retail/candidate boundary cases; {len(rejections)} actual writer controls rejected; exact provider roles/matches preserved')
