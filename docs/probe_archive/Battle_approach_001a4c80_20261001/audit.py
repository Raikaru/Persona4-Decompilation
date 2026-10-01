"""Compare captures and independently resolve every target relocation.

Run from the publication repository root:
  python docs/probe_archive/Battle_approach_001a4c80_20261001/audit.py BASELINE_CHECKOUT OUTPUT
OUTPUT must contain baseline/ and final/ captures from capture_owners.py.
"""
import sys,json,hashlib,struct,re,subprocess
from pathlib import Path
sys.path.insert(0,'tools')
import verify as V
ROOT=Path.cwd();out=Path(sys.argv[2]);oldRoot=Path(sys.argv[1])
base='a78c378b3da3cc826aea3c66462ee1f07f287759'
def skey(o,idx):
 s=o.sections[idx];same=[r for r in o.sections[:idx+1] if (r['name'],r['type'],r['flags'])==(s['name'],s['type'],s['flags'])];return(s['name'],s['type'],s['flags'],len(same)-1)
def symkey(o,s):
 if not s['name'] or s['name'].startswith('@'):return ('section',skey(o,s['shndx']),s['value'],s['size'])
 return ('named',s['name'],s['value'],s['size'],s['info'])
def canon(o,name):
 code,rs=o.function(name);refs=[]
 for r in rs:
  r=r.copy()
  if r['symbol'] and r['symbol'].startswith('@'):r['symbol']=symkey(o,next(s for s in o.symbols if s['name']==r['symbol']))
  if 'target_section' in r:r['target_section']=skey(o,r['target_section'])
  refs.append(r)
 return code,refs
def alloc(o,text=True):
 return [(skey(o,s['idx']),s['size'],hashlib.sha256(o.data[s['offset']:s['offset']+s['size']] if s['type']!=8 else bytes(s['size'])).hexdigest()) for s in o.sections if s['flags']&2 and (text or not s['flags']&4)]
def allrels(o,text=True):
 result=[]
 for sec in o.sections:
  target=o.sections[sec['info']]
  if sec['type']!=9 or not target['flags']&2 or (not text and target['flags']&4):continue
  refs=[]
  for i in range(sec['size']//(sec['entsize'] or 8)):
   off,info=struct.unpack_from(o.endian+'II',o.data,sec['offset']+i*(sec['entsize']or 8));refs.append((off,info&255,symkey(o,o.symtabs[sec['link']][info>>8])))
  result.append((skey(o,sec['info']),refs))
 return result
owners=['src/promoted/code1_001a.c','src/promoted/code1_0019.c','src/promoted/code1_001f.c','src/promoted/code1_0022.c','src/promoted/code1_001b.c','src/promoted/code1_001c.c','src/Battle/btlCamera.c','src/Battle/btlUnit.c','src/Battle/btlFormation.c'];reports=[];total=0;unchanged=0
cfg=V.load_config();target=V._read_json(V.TARGET);windows=V._read_json(V.FUNCTION_WINDOWS);retail=V.RetailElf(cfg['retail_elf'],target,windows['sha1']);gp,addresses=V.symbol_addresses()
for file in ['config/symbol_addrs.txt','config/symbols_recovered.txt']:
 for line in Path(file).read_text().splitlines():
  m=re.match(r'\s*([\w.$]+)\s*=\s*(0x[\da-fA-F]+)',line)
  if m:addresses[m[1]]=int(m[2],16)
for owner in owners:
 key=Path(owner).stem;old=V.ObjectFile(out/'baseline'/(key+'.o'));new=V.ObjectFile(out/'final'/(key+'.o'));rows=[]
 for f in V.scan_markers(ROOT/owner):
  name=f['name'];a=canon(old,name);b=canon(new,name);equal=a==b
  rows.append({'name':name,'size':len(b[0]),'bytes_and_relocations_equal':equal});total+=1;unchanged+=equal
  if name!='func_001a4c80':assert equal,(owner,name)
 row={'owner':owner,'source_sha256':hashlib.sha256((ROOT/owner).read_bytes()).hexdigest(),'functions':rows,'unchanged_functions':sum(r['bytes_and_relocations_equal'] for r in rows),'total_functions':len(rows),'allocated_sections_equal':alloc(old)==alloc(new),'allocated_relocations_equal':allrels(old)==allrels(new),'nontext_allocated_sections_equal':alloc(old,False)==alloc(new,False),'nontext_allocated_relocations_equal':allrels(old,False)==allrels(new,False)}
 assert row['nontext_allocated_sections_equal'] and row['nontext_allocated_relocations_equal']
 if owner!='src/promoted/code1_001a.c':assert row['allocated_sections_equal'] and row['allocated_relocations_equal'],owner
 reports.append(row)
 print(owner,row['unchanged_functions'],'/',row['total_functions'],flush=True)
obj=V.ObjectFile(out/'final/code1_001a.o');cb,rs=obj.function('func_001a4c80');rb=retail.bytes_at(0x1a4c80,2336);nd,first=V.compare(cb,rs,rb);assert len(cb)==len(rb)==2336 and nd==0
resolved=[]
for r in rs:
 addr=V.resolve_symbol(r['symbol'],gp,addresses);assert addr is not None,r
 off=r['offset'];cw,rw=struct.unpack_from('<I',cb,off)[0],struct.unpack_from('<I',rb,off)[0];add=cw&65535;sgn=add-65536 if add&32768 else add;typ=r['r_type']
 if typ==4:expected=(addr>>2)&0x3ffffff;actual=rw&0x3ffffff;assert cw&0x3ffffff==0,r
 elif typ==7:expected=(addr-gp+sgn)&65535;actual=rw&65535;assert -32768<=addr-gp+sgn<=32767
 elif typ==5:
  low=next(x for x in rs if x['offset']>off and x['symbol']==r['symbol'] and x['r_type']==6);lw=struct.unpack_from('<I',cb,low['offset'])[0]&65535;ls=lw-65536 if lw&32768 else lw;expected=((addr+(add<<16)+ls+32768)>>16)&65535;actual=rw&65535
 elif typ==6:expected=(addr+sgn)&65535;actual=rw&65535
 else:raise AssertionError(r)
 resolved.append({**r,'address':hex(addr),'expected':hex(expected),'retail':hex(actual),'equal':expected==actual});assert expected==actual,(r,hex(expected),hex(actual))
# Guard recovery statements remain the main versions. Only canonical ABI
# declaration removals are permitted in their text regions.
from measure_guarded import extract_guarded_body
names=['func_001990d0','func_001991c0','func_00199350','func_00199500','func_001996d0','func_001999f0','func_00196bd0','func_00199d00','func_001f1210','func_001f11e0','func_0022fa90']
def normalize_guard(s):
 for name in names:s=re.sub(r'(?m)^\s*(?:extern )?(?:s16|s32|s64|f32) '+name+r'\([^;{}]*\);\n','',s)
 return s
oldsrc=(oldRoot/'src/promoted/code1_001a.c').read_text();newsrc=Path('src/promoted/code1_001a.c').read_text();guards={}
for addr in ['001A7720','001A59A0']:
 a=extract_guarded_body(oldsrc,'FUN_'+addr,'func_'+addr.lower());b=extract_guarded_body(newsrc,'FUN_'+addr,'func_'+addr.lower());equal=normalize_guard(a)==normalize_guard(b);assert equal,addr
 guards['func_'+addr.lower()]={'statements_unchanged':equal,'only_canonical_declaration_removal':a!=b}
report={'baseline':base,'total_functions':total,'unchanged_functions':unchanged,'owners':reports,'target':{'size':len(cb),'retail_window':len(rb),'normalized_different_bytes':nd,'frame':-struct.unpack('<h',cb[:2])[0],'resolved_relocations':resolved},'guard_preservation':guards,'speed_values':{'address':'0x5f6d20','first_five_hex':retail.bytes_at(0x5f6d20,20).hex()},'reposition_factor':{'address':'0x761450','hex':retail.bytes_at(0x761450,4).hex()}}
(out/'preservation.json').write_text(json.dumps(report,indent=2)+'\n');print('TOTAL',unchanged,'/',total,'unchanged;',len(rs),'target references exact')
