"""Recheck the actual final object's earlier alpha aliases and unchanged fade tail."""
from pathlib import Path
import hashlib,json,struct
ROOT=Path.cwd();P=ROOT/'proof/title-sprite-alpha-owner'
a=json.loads((P/'before-guard.json').read_text());b=json.loads((P/'after-guard.json').read_text());name='func_001265a0'
assert b['source_sha256']==hashlib.sha256((ROOT/'src/promoted/code1_0012.c').read_bytes()).hexdigest()
old=a['functions'][name];new=b['functions'][name];ob=bytes.fromhex(old['bytes']);nb=bytes.fromhex(new['bytes'])
def rels(fn,start,end):return [{**r,'offset':r['offset']-start} for r in fn['relocations'] if start<=r['offset']<end]
def symbol(fn,name):return next(r['offset'] for r in fn['relocations'] if r['symbol']==name)
rows=[];objects={}
for sym in ('fGpffff9c80','fGpffff9c84'):
 oa=symbol(old,sym);na=symbol(new,sym)
 if sym.endswith('84'):
  # Include complete phase construction and the actual sine call before the GP load.
  def phase(fn,at):return max(r['offset'] for r in fn['relocations'] if r['offset']<at and r['symbol']=='fGpffff8094')
  os=phase(old,oa);ns=phase(new,na)
 else:os,ns=oa,na
 def end(fn,at):return next(r['offset']+8 for r in fn['relocations'] if r['offset']>at and r['symbol']=='func_0045d6e0')
 oe,ne=end(old,oa),end(new,na)
 assert ob[os:oe]==nb[ns:ne] and rels(old,os,oe)==rels(new,ns,ne)
 w=struct.unpack_from('<I',nb,na+4)[0];assert w>>26==57 and w>>21&31==29
 obj=w&65535;objects[sym]=obj
 rows.append({'symbol':sym,'old_range':[hex(os),hex(oe)],'new_range':[hex(ns),hex(ne)],'all_bytes_and_normalized_references_identical':True,'source_sp':hex(obj)})
base_colors=json.loads((ROOT/'proof/candidate-color-families.json').read_text())['candidate_objects'];all_offsets=list(base_colors.values())+list(objects.values())
assert len(all_offsets)==52 and len(set(all_offsets))==52
widths={0x1e:16,0x1f:16,0x20:1,0x21:2,0x22:4,0x23:4,0x24:1,0x25:2,0x26:4,0x27:4,0x28:1,0x29:2,0x2a:4,0x2b:4,0x2c:8,0x2d:8,0x2e:4,0x31:4,0x35:8,0x37:8,0x39:4,0x3d:8,0x3f:8}
census=[]
for at in range(0,len(nb),4):
 w=struct.unpack_from('<I',nb,at)[0];op=w>>26;offset=w&65535;width=widths.get(op)
 if w>>21&31!=29 or not width:continue
 matches=[(sym,off) for sym,off in objects.items() if offset<off+4 and offset+width>off]
 if matches:
  assert len(matches)==1 and matches[0][1]<=offset and offset+width<=matches[0][1]+4
  census.append({'offset':hex(at),'symbol':matches[0][0],'width':width})
assert len(census)==6
key=next(iter(a['target_tables']));os=a['target_tables'][key]['entries'][10];ns=b['target_tables'][key]['entries'][10]
assert ob[os:]==nb[ns:] and rels(old,os,len(ob))==rels(new,ns,len(nb))
report={'source_sha256':b['source_sha256'],'alpha_alias_ranges':rows,'52_distinct_color_objects':True,'alpha_direct_access_census':census,'tail_old_start':hex(os),'tail_new_start':hex(ns),'entire_tail_and_epilogue_bytes_and_references_equal':True}
(ROOT/'proof/preserved-slices-evidence.json').write_text(json.dumps(report,indent=2)+'\n')
print('Both previous alpha-alias phase/convert/copy/call slices and entire fade tail/epilogue unchanged; 52 distinct colors retained')
