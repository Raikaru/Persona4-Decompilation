"""Strict scoped production audit. Requires the configured licensed inputs.

Only public9938 and current sources are used. All generated objects, compiled
bytes and logs belong in the supplied private output directory, never in Git.
"""
from pathlib import Path
import argparse,hashlib,json,os,re,struct,subprocess,sys
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools'))
import verify as V
import probe_variants as P
BASE='9938a483606bdf00f62f489664457d722850eb09'
TARGET='func_001b4880'
OWNERS=('src/Battle/btlMain.c','src/Battle/btlFormation.c',
        'src/promoted/code1_001a.c','src/promoted/code1_001b.c','src/promoted/code1_001e.c')
def sha(data):return hashlib.sha256(data).hexdigest()
def section_key(obj,index):
 s=obj.sections[index];key=(s['name'],s['type'],s['flags'])
 return (*key,sum((x['name'],x['type'],x['flags'])==key for x in obj.sections[:index]))
def symbol_key(obj,s):
 if s['name'] and not s['name'].startswith('@'):return ('named',s['name'])
 return ('section',section_key(obj,s['shndx']),s['value'],s['size'])
def function(obj,name):
 code,refs=obj.function(name);refs=[dict(r) for r in refs]
 for r in refs:
  if r['symbol'].startswith('@'):
   sym=next(s for s in obj.symbols if s['name']==r['symbol']);r['symbol']=symbol_key(obj,sym)
 return code,refs

def allocated_data(obj):
 sections,refs=[],[]
 for i,s in enumerate(obj.sections):
  if s['flags']&2 and not s['flags']&4:
   data=obj.data[s['offset']:s['offset']+s['size']] if s['type']!=8 else b''
   sections.append((section_key(obj,i),s['size'],sha(data)))
  if s['type']!=9:continue
  dest=obj.sections[s['info']]
  if not dest['flags']&2 or dest['flags']&4:continue
  entries=[]
  for n in range(s['size']//(s['entsize'] or 8)):
   off,info=struct.unpack_from(obj.endian+'II',obj.data,s['offset']+n*(s['entsize'] or 8))
   entries.append((off,info&255,symbol_key(obj,obj.symtabs[s['link']][info>>8])))
  refs.append((section_key(obj,s['info']),entries))
 return sections,refs

def compile_source(owner,text,out,cfg):
 with P.scratch_source(owner) as temporary:
  temporary.write_text(text);ok,log=P._compile_in_context(temporary,owner,cfg,out)
 out.with_suffix('.log').write_text(log)
 if not ok:raise RuntimeError(log)
 return V.ObjectFile(out)

def literal_payload(obj,name):
 s=next(x for x in obj.symbols if x['name']==name);sec=obj.sections[s['shndx']]
 return obj.data[sec['offset']+s['value']:sec['offset']+s['value']+s['size']]
def signed16(word):return (word&65535)-((word&32768)<<1)

def resolve_target(obj,owner,retail,gp,table):
 # Bind anonymous literals by preserved sibling instruction sites and actual
 # payloads, never by repeated value alone or a shifted target instruction.
 literals={}
 for m in V.scan_markers(owner):
  if m['name']==TARGET:continue
  body,refs=obj.function(m['name'])
  for r in refs:
   if not r['symbol'].startswith('@') or r['r_type'] not in (7,8):continue
   off=r['offset'];word=struct.unpack('<I',retail.bytes_at(m['addr']+off,4))[0];current=struct.unpack_from('<I',body,off)[0]
   assert word&0xffff0000==current&0xffff0000
   address=gp+signed16(word)-signed16(current);payload=literal_payload(obj,r['symbol'])
   assert payload==retail.bytes_at(address,len(payload))
   assert r['symbol'] not in literals or literals[r['symbol']]==address
   literals[r['symbol']]=address
 body,refs=obj.function(TARGET);resolved=bytearray(body);rows=[]
 for r in refs:
  address=V.resolve_symbol(r['symbol'],gp,table)
  if address is None:address=literals.get(r['symbol'])
  assert address is not None,r
  off=r['offset'];word=struct.unpack_from('<I',body,off)[0];add=signed16(word);kind=r['r_type']
  if kind==4:
   assert word&0x3ffffff==0
   value=(word&0xfc000000)|((address>>2)&0x3ffffff)
  elif kind==5:
   assert word&65535==0
   value=(word&0xffff0000)|(((address+0x8000)>>16)&65535)
  elif kind==6:
   assert add==0
   value=(word&0xffff0000)|((address+add)&65535)
  elif kind in (7,8):value=(word&0xffff0000)|((address-gp+add)&65535)
  else:raise ValueError(r)
  struct.pack_into('<I',resolved,off,value);rows.append({**r,'address':hex(address)})
 return body,bytes(resolved),rows

def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('output',type=Path);args=parser.parse_args()
 out=args.output.resolve();out.mkdir(parents=True,exist_ok=True);os.chdir(ROOT);cfg=V.load_config()
 retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),V._read_json(V.FUNCTION_WINDOWS)['sha1']);gp,table=V.symbol_addresses()
 for line in (ROOT/'config/symbol_addrs.txt').read_text().splitlines():
  m=re.match(r'\s*([A-Za-z_.$][\w.$]*)\s*=\s*(0x[0-9a-fA-F]+)',line)
  if m:table.setdefault(m.group(1),int(m.group(2),16))
 rows=[];exceptions=[];count=0
 for relative in OWNERS:
  owner=ROOT/relative;current=owner.read_text();public=subprocess.check_output(['git','show',BASE+':'+relative],text=True)
  before=compile_source(owner,public,out/(owner.stem+'-public.o'),cfg)
  after=compile_source(owner,current,out/(owner.stem+'-production.o'),cfg)
  markers=V.scan_markers(owner);count+=len(markers);changed=[]
  for m in markers:
   name=m['name']
   if name==TARGET:continue
   if function(before,name)!=function(after,name):changed.append(name)
   ab,ar=before.function(name);bb,br=after.function(name)
   assert ab==bb and len(ar)==len(br)
   for old,new in zip(ar,br):
    if old==new:continue
    assert {k:v for k,v in old.items() if k!='symbol'}=={k:v for k,v in new.items() if k!='symbol'}
    assert old['symbol'].startswith('@') and new['symbol'].startswith('@') and old['r_type'] in (7,8)
    payload=literal_payload(before,old['symbol']);assert payload==literal_payload(after,new['symbol'])
    off=old['offset'];actual=struct.unpack('<I',retail.bytes_at(m['addr']+off,4))[0];word=struct.unpack_from('<I',ab,off)[0]
    assert actual&0xffff0000==word&0xffff0000
    address=gp+signed16(actual)-signed16(word);assert payload==retail.bytes_at(address,len(payload))
    exceptions.append({'owner':relative,'function':name,'offset':off,'old_symbol':old['symbol'],'new_symbol':new['symbol'],'retail_address':hex(address),'payload_hex':payload.hex(),'payload_sha256':sha(payload)})
  assert not changed and allocated_data(before)==allocated_data(after),(relative,changed)
  rows.append({'owner':relative,'source_sha256':sha(current.encode()),'object_sha256':sha(after.data),'function_count':len(markers),'non_target_changed_functions':changed,'allocated_data_equal':True,'whole_object_equal_public':before.data==after.data})
  if relative=='src/promoted/code1_001b.c':target_obj=after;target_owner=owner
 marker=next(m for m in V.scan_markers(target_owner) if m['name']==TARGET)
 assert not marker.get('asm',False) and not marker.get('nonmatching',False)
 assert not P._has_include_fallback(target_owner.read_text(),'FUN_001B4880',TARGET)
 body,resolved,refs=resolve_target(target_obj,target_owner,retail,gp,table);expected=retail.bytes_at(0x1b4880,2688)
 last_jr=max(i for i in range(0,len(expected),4) if expected[i:i+4]==bytes.fromhex('0800e003'));assert last_jr+8==2688
 calls=lambda x:[(struct.unpack_from('<I',x,i)[0]&0x3ffffff)<<2 for i in range(0,len(x),4) if struct.unpack_from('<I',x,i)[0]>>26==3]
 assert len(body)==2688 and resolved==expected and len(refs)==75 and calls(resolved)==calls(expected) and len(calls(expected))==47
 assert count==375 and len(V.scan_markers(target_owner))-1==122
 report={'public_base':BASE,'production_owners':rows,'total_functions':375,'unchanged_other_functions':374,'target':{'live_bytes':2688,'retail_tail_bytes':0,'frame':-struct.unpack_from('<h',body)[0],'fully_resolved_differences':0,'references':refs,'reference_count':75,'call_count':47,'sibling_count':122,'object_sha256':sha(target_obj.data)},'literal_name_exceptions':exceptions}
 (out/'validation.json').write_text(json.dumps(report,indent=2)+'\n');(out/'target.resolved.bin').write_bytes(resolved)
 print(json.dumps({**report,'target':{k:v for k,v in report['target'].items() if k!='references'}},indent=2))
if __name__=='__main__':main()
