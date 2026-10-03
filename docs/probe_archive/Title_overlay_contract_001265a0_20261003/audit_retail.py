from pathlib import Path
import hashlib,json,re,struct,sys
sys.path.insert(0,'tools');import verify as V
cfg=V.load_config();window=V._read_json(V.FUNCTION_WINDOWS);retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),window['sha1'])
def fbits(value):return struct.unpack('<I',struct.pack('<f',value))[0]
def signed(value):return value-0x100000000 if value&0x80000000 else value

def setup(address):
 data=retail.bytes_at(address-80,80);g={0:0,29:('sp',0)};f={}
 for pos in range(0,len(data),4):
  w=struct.unpack_from('<I',data,pos)[0];op=w>>26;rs=(w>>21)&31;rt=(w>>16)&31;rd=(w>>11)&31;imm=w&65535;si=imm-65536 if imm&32768 else imm
  if op==15:g[rt]=imm<<16
  elif op==13:g[rt]=(g[rs]|imm) if isinstance(g.get(rs),int) else None
  elif op==9:
   a=g.get(rs);g[rt]=(a+si)&0xffffffff if isinstance(a,int) else ('sp',a[1]+si) if isinstance(a,tuple) and a[0]=='sp' else None
  elif op==0 and (w&63) in (33,45):
   a=g.get(rs);b=g.get(rt);g[rd]=a if b==0 else b if a==0 else (a+b)&0xffffffff if isinstance(a,int) and isinstance(b,int) else None
  elif op==17:
   fmt=rs;ft=rt;fs=rd;fd=(w>>6)&31;fn=w&63
   if fmt==4:f[fs]=g.get(ft)
   elif fmt==16 and fn==6:f[fd]=f.get(fs)
   elif fmt==20 and fn==32:f[fd]=fbits(float(signed(f[fs]))) if isinstance(f.get(fs),int) else None
   elif fmt in (16,17,20):f[fd]=None
  elif op==49:f[rt]=None
  elif op in (32,33,35,36,37,39,55):g[rt]=None
 return g,f
rows=[]
for start,size,colors,depths,height in [(0x1265a0,17616,[0x680,0x6bc,0x6bc,0x678,0x670,0x668,0x660,0x658,0x650,0x648,0x640,0x638,0x630,0x6bc],[65535.0,0.0]+[65535.0]*12,448.0),(0x126090,1296,[0x7c],[0.0],480.0)]:
 b=retail.bytes_at(start,size);calls=[start+i for i in range(0,len(b),4) if struct.unpack_from('<I',b,i)[0]==(3<<26)|(0x2aaf20>>2)];assert len(calls)==len(colors),(hex(start),len(calls))
 for a,color,depth in zip(calls,colors,depths):
  assert retail.bytes_at(a+4,4)==b'\0'*4
  g,f=setup(a)
  expectedg={4:('sp',color),5:0x12,6:0};expectedf={12:fbits(0),13:fbits(0),14:fbits(depth),15:fbits(640),16:fbits(height)}
  assert all(g.get(k)==v for k,v in expectedg.items()),(hex(a),g,expectedg)
  assert all(f.get(k)==v for k,v in expectedf.items()),(hex(a),f,expectedf)
  rows.append({'caller':hex(start),'callsite':hex(a),'color_stack_offset':hex(color),'x':0,'y':0,'depth':depth,'width':640,'height':height,'flags':18,'parent':None,'argument_registers_verified':True,'delay_slot_nop':True})
# The live provider prologue carries the independent FPR/GPR counters in the
# actual x/y/depth/color/width/height/flags/parent source order.
expected={0x2aaf4c:0x46006606,0x2aaf50:0x46006dc6,0x2aaf54:0x46007506,0x2aaf58:0x0080982d,0x2aaf5c:0x46007d86,0x2aaf60:0x46008546,0x2aaf64:0x00a0902d,0x2aaf68:0x00c0882d}
for a,w in expected.items():assert struct.unpack('<I',retail.bytes_at(a,4))[0]==w,(hex(a),hex(w))
report={'retail_sha1':window['sha1'],'provider':'002aaf20','provider_prologue_verified':True,'sites':rows,'source_sha256':hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest()}
Path('proof/retail-call-setup.json').write_text(json.dumps(report,indent=2)+'\n');print('Verified',len(rows),'retail calls and canonical provider argument transports')
