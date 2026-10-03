"""Authenticate and execute bounded retail/candidate callback transport slices.

Only producer stores, dispatch argument loads, target entry forwarding, actual
getter load/return and scene-view capture execute. Allocation and submission are
boundary inputs; surrounding renderer and the inferred dispatcher C do not run.
"""
from pathlib import Path
import hashlib,json,struct,sys
sys.path.insert(0,'tools');import verify as V
P=Path('proof');cfg=V.load_config();windows=V._read_json(V.FUNCTION_WINDOWS)
e=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),windows['sha1'])
rec=json.loads((P/'title-entry-owner/after-guard.json').read_text());sha=hashlib.sha256(Path('src/promoted/code1_0012.c').read_bytes()).hexdigest();assert rec['source_sha256']==sha
f=rec['functions']['func_001265a0'];candidate=bytes.fromhex(f['bytes'])
def words(raw):return list(struct.unpack('<'+'I'*(len(raw)//4),raw))
slices={
 'producer':(0x12b614,[0x0040282d,0x3c030012,0x246365a0,0xac430008,0xac530010]),
 'dispatch_callback':(0x4623b8,[0x8e060008]),
 'dispatch_arguments':(0x4623e0,[0x2604001c,0x8e050010,0x00c0f809,0]),
 'target':(0x1265d4,[0x00a0202d,0x0c114958,0,0x0040a02d]),
 'getter':(0x452560,[0x8c820038,0x03e00008,0]),
 'post_callback_command':(0x4623f0,[0x96030018])}
receipts={}
for name,(address,expected) in slices.items():
 raw=e.bytes_at(address,4*len(expected));assert words(raw)==expected
 receipts[name]={'address':hex(address),'bytes':len(raw),'sha256':hashlib.sha256(raw).hexdigest(),'words':[hex(w) for w in expected]}
assert [r for r in f['relocations'] if r['symbol']=='func_00452560']==[{'offset':0x48,'r_type':4,'type':'R_MIPS_26','symbol':'func_00452560'}]
assert words(candidate[0x44:0x54])==[0x00a0202d,0x0c000000,0,0x0040a02d]
# Authenticate complete save-only prefixes. None writes incoming a0/a1.
for name,raw in [('retail',e.bytes_at(0x1265a0,0x34)),('candidate',candidate[:0x44])]:
 ws=words(raw);assert ws[0]>>16==0x27bd
 for w in ws[1:]:assert w>>26 in (31,57,63) and w>>21&31==29
 receipts[name+'_save_only_prefix']={'bytes':len(raw),'sha256':hashlib.sha256(raw).hexdigest(),'incoming_a0_a1_unchanged':True}

def execute(kind,pattern,mutation=None):
 node=0x10000000+pattern*256;task=0x20000000+pattern*256;work=0x30000000+pattern*256
 g={i:0xcafe0000+i for i in range(32)};g[0]=0;g[2]=node;g[19]=task
 mem={task+0x38:work,task+0x34:work+16,node+0x18:pattern}
 callback=None;getters=0
 def step(w):
  nonlocal callback,getters
  op=w>>26;rs=w>>21&31;rt=w>>16&31;rd=w>>11&31;imm=w&65535;si=imm-65536 if imm&32768 else imm
  if w==0:return
  if op==0 and w&63==45:g[rd]=(g[rs]+g[rt])&0xffffffff
  elif op==15:g[rt]=imm<<16
  elif op==9:g[rt]=(g[rs]+si)&0xffffffff
  elif op==43:mem[g[rs]+si]=g[rt]
  elif op==35:g[rt]=mem[g[rs]+si]
  elif op==37:g[rt]=mem[g[rs]+si]&65535
  elif op==0 and w&63==9:
   assert g[rs]==0x1265a0;assert g[4]==node+0x1c;assert g[5]==task;callback=g[rs]
  elif op==3:
   # The candidate relocation and exact retail JAL target were checked above.
   assert g[4]==task,'getter must receive second callback input before any read'
   getter=slices['getter'][1][:]
   if mutation=='getter_offset':getter[0]=0x8c820034
   for word in getter:step(word)
   assert g[2]==work;getters+=1
  elif w==0x03e00008:pass # return boundary, delay-slot is separately executed
  else:raise AssertionError(hex(w))
 for w in slices['producer'][1]:
  if mutation=='data_store' and w==0xac530010:w=0xac520010
  step(w)
 assert mem[node+8]==0x1265a0 and mem[node+16]==task
 g[16]=node;step(slices['dispatch_callback'][1][0])
 for w in slices['dispatch_arguments'][1]:
  if mutation=='first_argument' and w==0x2604001c:w=0x26040018
  if mutation=='second_argument' and w==0x8e050010:w=0x8e050008
  step(w)
 assert callback==0x1265a0
 entry=slices['target'][1][:] if kind=='retail' else words(candidate[0x44:0x54])
 if mutation=='no_forwarding':entry[0]=0
 if mutation=='wrong_forwarding':entry[0]=0x0080202d
 for w in entry:step(w)
 assert getters==1 and g[20]==work
 # Immediate post-call behavior is independent of callback v0. Broader return
 # non-consumption is also represented by the existing void node contract.
 for value in (0,0xdeadbeef):
  g[2]=value;step(slices['post_callback_command'][1][0]);assert g[3]==pattern
 return True
count=0
for kind in ('retail','candidate'):
 for pattern in range(1024):execute(kind,pattern);count+=1
controls=[]
for name in ('data_store','first_argument','second_argument','no_forwarding','wrong_forwarding','getter_offset'):
 try:execute('candidate',3,name)
 except AssertionError:controls.append(name)
 else:raise AssertionError(('control did not reject',name))
report={'source_sha256':sha,'retail_sha1':windows['sha1'],'slices':receipts,'candidate_entry_offset':0x44,
 'candidate_entry_words':[hex(w) for w in words(candidate[0x44:0x54])],'executed_cases':count,'negative_controls':controls,
 'getter_input_identity_checked_before_read':True,'scene_view_register':20,'full_dispatcher_C_executed':False,
 'scope':'Bounded actual machine argument/store/load slices; allocation/submission supplied; renderer and command switch excluded'}
(P/'entry-machine-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print(str(count)+' bounded retail/candidate entry cases passed; '+str(len(controls))+' machine controls rejected')
