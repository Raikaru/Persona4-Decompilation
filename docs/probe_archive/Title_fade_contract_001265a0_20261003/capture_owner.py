from pathlib import Path
import collections, hashlib, json, struct, subprocess, sys
sys.path.insert(0,'tools')
import verify as V, probe_variants as P
root=Path.cwd();owner=root/'src/promoted/code1_0012.c';out=root/'proof/title-fade-owner';out.mkdir(parents=True,exist_ok=True)
before=subprocess.check_output(['git','show','fd71083ec6e1a69e27b86f947618e913e5acd20e:src/promoted/code1_0012.c']);after=owner.read_bytes()
records={};cfg=V.load_config()
for label,source in [('before',before),('after',after)]:
 for guard in [False,True]:
  local=dict(cfg); local['compile_flags']=[*cfg['compile_flags'],*(['-DNON_MATCHING'] if guard else [])]
  name=label+('-guard' if guard else '-production');objpath=out/(name+'.o')
  with P.scratch_source(owner) as scratch:
   scratch.write_bytes(source)
   assert V.unit_compiler(scratch,local)==V.unit_compiler(owner,local)
   assert V.unit_compile_flags(scratch,local['compile_flags'])==V.unit_compile_flags(owner,local['compile_flags'])
   ok,log=V._compile(scratch,local,objpath)
  (out/(name+'.log')).write_text(log); assert ok,log
  obj=V.ObjectFile(objpath)
  def key(sym):
   i=sym['shndx']
   return ('named',sym['name']) if sym['name'] and not sym['name'].startswith('@') else (i,obj.sections[i]['name'],sym['value'],sym['size'],sym['info'])
  secs=[];rels=[];funcs={}
  for s in obj.sections:
   if s['flags']&2:secs.append({k:s[k] for k in ['idx','name','size','type','flags','addralign']}|{'bytes':obj.data[s['offset']:s['offset']+s['size']].hex() if s['type']!=8 else ''})
   if s['type']==9:
    tab=obj.symtabs[s['link']]
    for pos in range(s['offset'],s['offset']+s['size'],s['entsize'] or 8):
     off,info=struct.unpack_from('<II',obj.data,pos);rels.append((s['info'],obj.sections[s['info']]['name'],off,info&255,key(tab[info>>8])))
  for m in obj.symbols:
   if (m['info'] & 15) != 2 or not m['size'] or m['shndx'] in (0,0xfff1): continue
   body,rs=obj.function(m['name'])
   symbols_by_name={sym['name']:sym for sym in obj.symbols}
   for rel in rs:
    relname=rel.get('symbol','')
    if relname.startswith('@'):
     rel['symbol']=key(symbols_by_name[relname])
   funcs[m['name']]={'size':len(body),'bytes':body.hex(),'relocations':rs}
  target_symbol=next(sym for sym in obj.symbols if sym['name']=='func_001265a0')
  target_tables={}
  for sec in obj.sections:
   if sec['type']!=9 or not obj.sections[sec['info']]['flags']&2 or obj.sections[sec['info']]['flags']&4: continue
   rr=[]
   for pos in range(sec['offset'],sec['offset']+sec['size'],sec['entsize'] or 8):
    off,info=struct.unpack_from('<II',obj.data,pos); rr.append((off,info&255,obj.symtabs[sec['link']][info>>8]['name']))
   if rr and all(row[2]=='func_001265a0' for row in rr):
    data_sec=obj.sections[sec['info']]; assert data_sec['size']==64 and sorted(x[0] for x in rr)==list(range(0,64,4)) and all(x[1]==2 for x in rr)
    words=list(struct.unpack_from('<16I',obj.data,data_sec['offset'])); target_body=obj.function('func_001265a0')[0]
    assert all(0<=word<len(target_body)-16 and word%4==0 for word in words)
    target_tables[data_sec['idx']]={'entries':words,'entry_prefixes':[target_body[word:word+16].hex() for word in words]}
  records[name]={'target_text_section':target_symbol['shndx'],'target_tables':target_tables,'source_sha256':hashlib.sha256(source).hexdigest(),'guarded':guard,'sections':secs,'relocations':rels,'functions':funcs}
  (out/(name+'.json')).write_text(json.dumps(records[name],indent=2)+'\n')
  print(name,len(funcs),flush=True)
# The entire pre-tail instruction/reference prefix is preserved except exact
# stack-home displacements caused by replacing a 4-byte fake object with 32
# real bytes. Check every word, never broadly mask opcodes or relocations.
old=records['before-guard']['functions']['func_001265a0']
new=records['after-guard']['functions']['func_001265a0']
old_code=bytes.fromhex(old['bytes']);new_code=bytes.fromhex(new['bytes'])
assert old_code[:4]==struct.pack('<I',0x27BDFB00)
assert new_code[:4]==struct.pack('<I',0x27BDFAE0)
stack_map={x:x+32 for x in range(0x3d0,0x500,4)}
stack_map.update({x:x+36 for x in range(0x3f8,0x420,4)})
# Byte-alpha stores address the final member of four-byte objects.
stack_map.update({x:x+32 for x in (0x42f,0x437,0x43f,0x447,0x44f,0x457,0x45f,0x467,0x46f,0x477,0x47f,0x4df,0x4eb,0x4ef)})
stack_changes=[]
for at in range(4,0x42ac,4):
    a=struct.unpack_from('<I',old_code,at)[0];b=struct.unpack_from('<I',new_code,at)[0]
    if a==b:continue
    assert a&0xffff0000==b&0xffff0000 and (a>>21)&31==29,(hex(at),hex(a),hex(b))
    assert (a>>26) in (9,31,35,40,43,49,57,63)
    assert stack_map.get(a&65535)==b&65535,(hex(at),hex(a),hex(b))
    stack_changes.append({'offset':at,'before':hex(a),'after':hex(b)})
assert len(stack_changes)==187
assert [r for r in old['relocations'] if r['offset']<0x42ac]==[r for r in new['relocations'] if r['offset']<0x42ac]
prefix_proof={'bytes_checked':0x42ac,'frame_before':0x500,'frame_after':0x520,'all_non_stack_words_equal':True,'all_references_equal':True,'exact_stack_changes':stack_changes}
summary={}
for suffix in ['production','guard']:
 a=records['before-'+suffix];b=records['after-'+suffix]
 assert set(a['functions'])==set(b['functions'])
 if suffix=='production':
  assert a['sections']==b['sections'] and a['relocations']==b['relocations']
 diffs=[name for name in a['functions'] if a['functions'][name]!=b['functions'][name]]
 changed_sections=[x['name'] for x,y in zip(a['sections'],b['sections']) if x!=y]
 summary[suffix]={'functions':len(a['functions']),'changed_function_names':diffs,'changed_section_names':changed_sections,'allocated_relocations_equal':a['relocations']==b['relocations']}
 assert diffs==([] if suffix=='production' else ['func_001265a0']),summary
 tables=set(a['target_tables']) | set(b['target_tables'])
 assert a['target_text_section']==b['target_text_section']
 excluded=tables | {a['target_text_section']}
 assert [x for x in a['sections'] if x['idx'] not in excluded]==[x for x in b['sections'] if x['idx'] not in excluded]
 ad=[x for x in a['sections'] if not x['flags']&4 and x['idx'] not in tables];bd=[x for x in b['sections'] if not x['flags']&4 and x['idx'] not in tables];assert ad==bd
 assert set(a['target_tables'])==set(b['target_tables'])
 for section in tables:
  ta=a['target_tables'][section];tb=b['target_tables'][section]
  changes=[]
  for index,(old,new) in enumerate(zip(ta['entry_prefixes'],tb['entry_prefixes'])):
   ow=struct.unpack('<4I',bytes.fromhex(old));nw=struct.unpack('<4I',bytes.fromhex(new))
   if old!=new:
    assert suffix=='guard'
    if index==0:
     assert ow==(0xAE400088,0xC7800000,0xE7A004FC,0x27A404FC)
     assert nw==(0xAE400088,0xC7800000,0xE7A0051C,0x27A4051C)
    elif index in (1,2,3):
     assert ow==(0xC7800000,0xE7A004FC,0x27A404FC,0x24050001)
     assert nw==(0xC7800000,0xE7A0051C,0x27A4051C,0x24050001)
    else:
     assert index in range(10,16)
     assert ow==(0x8E43002C,0x1860003E,0,0x3C130000)
     assert nw==(0x8E43002C,0x18600034,0,0x3C060000)
     # Each skip still reaches its real restore epilogue, never a padded label.
     for rec,table0,words in ((a,ta,ow),(b,tb,nw)):
      target=table0['entries'][index]+8+(words[1]&65535)*4
      data=bytes.fromhex(rec['functions']['func_001265a0']['bytes'])
      assert struct.unpack_from('<I',data,target)[0]==0xDFBF00E0
    changes.append(index)
   def prefix_refs(record,offset):
    return [{**r,'offset':r['offset']-offset} for r in record['functions']['func_001265a0']['relocations'] if offset<=r['offset']<offset+16]
   assert prefix_refs(a,ta['entries'][index])==prefix_refs(b,tb['entries'][index])
  assert changes==([0,1,2,3,10,11,12,13,14,15] if suffix=='guard' else [])
  assert ta['entries']==tb['entries']
  summary[suffix]['target_prefix_contracts']={'changed_entries':changes,'exact_old_new_words_checked':True,'all_prefix_references_equal':True,'all_case_offsets_equal':True,'shared_color_frame_growth':32 if suffix=='guard' else 0,'fade_skip_reaches_restore_epilogue':True}
  assert [[i for i,v in enumerate(ta['entries']) if v==entry] for entry in ta['entries']]==[[i for i,v in enumerate(tb['entries']) if v==entry] for entry in tb['entries']]
 outside=lambda record:[r for r in record['relocations'] if r[0] not in tables | {record['target_text_section']}]
 assert outside(a)==outside(b)
 summary[suffix]['all_non_target_allocated_data_unchanged']=True
 summary[suffix]['non_target_allocated_data_bytes']=sum(x['size'] for x in ad)
 summary[suffix]['all_non_target_allocated_references_unchanged']=True
 summary[suffix]['baseline_target_tables']=a['target_tables']
 summary[suffix]['target_tables']=b['target_tables']
 if suffix=='guard': summary[suffix]['pre_tail_prefix_proof']=prefix_proof
 summary[suffix]['baseline_target_size']=a['functions']['func_001265a0']['size']
 summary[suffix]['candidate_target_size']=b['functions']['func_001265a0']['size']
(out/'preservation.json').write_text(json.dumps(summary,indent=2)+'\n');print(json.dumps(summary,indent=2))
assert (out/'before-production.o').read_bytes()==(out/'after-production.o').read_bytes()
summary['production']['raw_object_identical']=True
summary['production']['object_sha256']=hashlib.sha256((out/'after-production.o').read_bytes()).hexdigest()
(out/'preservation.json').write_text(json.dumps(summary,indent=2)+'\n')
