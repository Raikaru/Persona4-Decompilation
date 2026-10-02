from pathlib import Path
import hashlib,json,struct,subprocess,sys,re
sys.path[:0]=['tools'];import verify as V,probe_variants as P,fnalign as F
def sha(data):
    return hashlib.sha256(data).hexdigest()


def section_key(obj, index):
    section = obj.sections[index]
    key = (section['name'], section['type'], section['flags'])
    number = sum((s['name'], s['type'], s['flags']) == key for s in obj.sections[:index])
    return (*key, number)


def symbol_key(obj, symbol):
    if symbol['name'] and not symbol['name'].startswith('@'):
        return ('named', symbol['name'])
    return ('section', section_key(obj, symbol['shndx']), symbol['value'], symbol['size'])


def canonical_function(obj, name):
    code, relocations = obj.function(name)
    relocations = [dict(r) for r in relocations]
    for r in relocations:
        if r['symbol'].startswith('@'):
            symbol = next(s for s in obj.symbols if s['name'] == r['symbol'])
            r['symbol'] = symbol_key(obj, symbol)
    return code, relocations


def allocated(obj, include_text=True):
    sections, relocations = [], []
    for index, section in enumerate(obj.sections):
        if section['flags'] & 2 and (include_text or not section['flags'] & 4):
            content = obj.data[section['offset']:section['offset'] + section['size']] if section['type'] != 8 else b''
            sections.append((section_key(obj, index), section['size'], sha(content)))
        if section['type'] != 9:
            continue
        destination = obj.sections[section['info']]
        if not destination['flags'] & 2 or (not include_text and destination['flags'] & 4):
            continue
        refs = []
        for i in range(section['size'] // (section['entsize'] or 8)):
            offset, info = struct.unpack_from(obj.endian + 'II', obj.data,
                                             section['offset'] + i * (section['entsize'] or 8))
            refs.append((offset, info & 255, symbol_key(obj, obj.symtabs[section['link']][info >> 8])))
        relocations.append((section_key(obj, section['info']), refs))
    return sections, relocations







out=Path('build/community/origin');out.mkdir(parents=True,exist_ok=True);cfg=V.load_config();base='0d58b7c703fe46d4ee8fb5ccb0e311c37214b3ae'
units=['src/promoted/code1_0035.c']
result={'base':base,'phases':{},'source_hashes':{}};objects={}
for rel in units:
 path=Path(rel).resolve();new=path.read_text();old=subprocess.check_output(['git','show',base+':'+rel],text=True)
 result['source_hashes'][rel]={'base':sha(old.encode()),'candidate':sha(new.encode())}
 for phase in ['production','guards']:
  for label,source in [('base',old),('candidate',new)]:
   obj=out/(path.stem+'-'+phase+'-'+label+'.o')
   with P.scratch_source(path)as scratch:
    scratch.write_text(('#define NON_MATCHING\n'if phase=='guards'else'')+source);ok,log=P._compile_in_context(scratch,path,cfg,obj);obj.with_suffix('.log').write_text(log);assert ok,log
   objects[rel,phase,label]=V.ObjectFile(obj)
  a,b=[objects[rel,phase,label]for label in ['base','candidate']];markers=V.scan_markers(path)
  changed=[m['name']for m in markers if canonical_function(a,m['name'])!=canonical_function(b,m['name'])]
  expected=[]
  assert changed==expected,(rel,phase,changed)
  if phase=='guards':assert allocated(a,False)==allocated(b,False),(rel,phase,'nontext allocated')
  else:assert allocated(a)==allocated(b),(rel,phase,'allocated')
  assert a.data==b.data,(rel,phase,'whole object')
  result['phases'][rel+':'+phase]={'functions':len(markers),'changed':changed,'allocated_canonical_refs_preserved':True,'entire_object_identical':True}
  (out/'partial.json').write_text(json.dumps(result,indent=2)+'\n');print(rel,phase,len(markers),changed,flush=True)
code,refs=objects[units[-1],'guards','candidate'].function('func_003599c0')
oldcode,oldrefs=objects[units[-1],'guards','base'].function('func_003599c0')
assert [dict(x,offset=0)for x in refs]==[dict(x,offset=0)for x in oldrefs]
r=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),V._read_json(V.FUNCTION_WINDOWS)['sha1']);raw=r.bytes_at(0x3599c0,4768)
a,b=F.decode(raw,0x3599c0),F.decode(code,0);mask={x['offset']//4 for x in refs};_,greedy,ro=F.align(a,b,mask)
def dist(a,b,mask):
 prev=list(range(len(b)+1))
 for i,x in enumerate(a):
  row=[i+1]
  for j,y in enumerate(b):row.append(min(row[-1]+1,prev[j+1]+1,prev[j]+(0 if x==y or j in mask and F.strip_immediates(x)==F.strip_immediates(y)else 1)))
  prev=row
 return prev[-1]
ri=[i for i,x in enumerate(a)if x=='jal'];ci=[x['offset']//4 for x in refs if x['r_type']==4];assert len(ri)==len(ci)==16
parts=[];pa=pb=0
for i,j in zip(ri+[len(a)],ci+[len(b)]):parts.append(dist(a[pa:i],b[pb:j],{x-pb for x in mask if pb<=x<j}));pa,pb=i+1,j+1
result.update({'target_bytes':len(code),'frame':-struct.unpack_from('<h',code,0)[0],'target_sha256':sha(code),'full_window_global':dist(a,b,mask),'call_anchored':sum(parts),'anchor_parts':parts,'full_window_greedy':greedy,'relocation_only':ro,'reference_count':len(refs),'ordered_references_and_addends_preserved':True,'static_call_count':len(ri)})
(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
