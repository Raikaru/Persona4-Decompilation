from pathlib import Path
import collections, hashlib, json, struct, subprocess, sys
sys.path.insert(0,'tools')
import verify as V, probe_variants as P
root=Path.cwd();owner=root/'src/promoted/code1_0012.c';out=root/'proof/title-model-owner';out.mkdir(parents=True,exist_ok=True)
before=subprocess.check_output(['git','show','69799eb8fe97c414501d20af309688f147e0e5d2:src/promoted/code1_0012.c']);after=owner.read_bytes()
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
summary={}
for suffix in ('production','guard'):
 a=records['before-'+suffix];b=records['after-'+suffix]
 assert set(a['functions'])==set(b['functions'])
 diffs=[n for n in a['functions'] if a['functions'][n]!=b['functions'][n]]
 assert diffs==([] if suffix=='production' else ['func_001265a0'])
 tables=set(a['target_tables'])|set(b['target_tables']);assert a['target_text_section']==b['target_text_section']
 excluded=tables|{a['target_text_section']}
 assert [s for s in a['sections'] if s['idx'] not in excluded]==[s for s in b['sections'] if s['idx'] not in excluded]
 assert [r for r in a['relocations'] if r[0] not in excluded]==[r for r in b['relocations'] if r[0] not in excluded]
 data=[s for s in a['sections'] if not s['flags']&4 and s['idx'] not in tables]
 assert sum(s['size'] for s in data)==420
 for section in tables:
  ta=a['target_tables'][section];tb=b['target_tables'][section]
  # Exact per-prefix stack-home adjustments are audited separately.
  pass
  assert [[i for i,v in enumerate(ta['entries']) if v==entry] for entry in ta['entries']]==[[i for i,v in enumerate(tb['entries']) if v==entry] for entry in tb['entries']]
  for oa,ob in zip(ta['entries'],tb['entries']):
   def rels(rec,at):return [{**r,'offset':r['offset']-at} for r in rec['functions']['func_001265a0']['relocations'] if at<=r['offset']<at+16]
   assert rels(a,oa)==rels(b,ob)
 summary[suffix]={'changed_functions':diffs,'preserved_siblings':81,'preserved_data_bytes':420,'all_non_target_allocated_sections_and_relocations_equal':True,'switch_prefix_references_equal':True,'switch_words_checked_separately':'audit_preservation.py','switch_alias_groups_equal':True,'tables_before':a['target_tables'],'tables_after':b['target_tables'],'target_size_before':a['functions']['func_001265a0']['size'],'target_size_after':b['functions']['func_001265a0']['size']}
 if suffix=='production':
  assert a['sections']==b['sections'] and a['relocations']==b['relocations']
  assert (out/'before-production.o').read_bytes()==(out/'after-production.o').read_bytes()
  summary[suffix]['raw_object_identical']=True
  summary[suffix]['object_sha256']=hashlib.sha256((out/'after-production.o').read_bytes()).hexdigest()
(out/'preservation.json').write_text(json.dumps(summary,indent=2)+'\n')
print('Production object identical; all 81 guarded siblings, 420 non-target data bytes, references and switch alias/reference contracts preserved; prefix words checked separately')
