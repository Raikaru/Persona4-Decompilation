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







out=Path('build/community/origin-projection');out.mkdir(parents=True,exist_ok=True);cfg=V.load_config()
path=Path('src/promoted/code1_0035.c').resolve();new=path.read_text();old=new
import recovery_quality as Q
bodies=Q.function_bodies(path)
changed_functions={}
for name,arg in [('func_00356250','arg0'),('func_0035e8b0','arg2')]:
 body=bodies[name][1];original=body
 for offset in (4,8):
  after=f'*(f32 *)({arg} + {offset}) = 0.0f;';before=f'*(s32 *)({arg} + {offset}) = 0;'
  assert body.count(after)==1,(name,after);original=original.replace(after,before)
 assert old.count(body)==1;old=old.replace(body,original,1)
 changed_functions[name]={'new_body_sha256':sha(body.encode()),'baseline_body_sha256':sha(original.encode())}
result={'source_sha256':sha(new.encode()),'reversed_baseline_sha256':sha(old.encode()),'changed_functions':changed_functions,'phases':{}}
groups={}
for group,name in re.findall(r'INCLUDE_ASM\("asm/nonmatchings/([^\"]+)\",\s*func_([0-9a-fA-F]+)\)',new):
 if not Path('asm/nonmatchings',group,'func_'+name+'.s').exists():groups.setdefault(group,set()).add(name)
for group,names in groups.items():subprocess.run([sys.executable,'tools/extract_nonmatching_asm.py',*sorted(names),'--group',group],check=True,stdout=subprocess.DEVNULL)
for phase in ['production','guards']:
 objects=[]
 for label,source in [('baseline',old),('candidate',new)]:
  obj=out/(phase+'-'+label+'.o')
  with P.scratch_source(path)as scratch:
   scratch.write_text(('#define NON_MATCHING\n'if phase=='guards'else'')+source);ok,log=P._compile_in_context(scratch,path,cfg,obj);obj.with_suffix('.log').write_text(log);assert ok,log
  objects.append(V.ObjectFile(obj))
 a,b=objects;assert a.data==b.data,(phase,'whole object differs')
 markers=V.scan_markers(path)
 assert all(canonical_function(a,m['name'])==canonical_function(b,m['name'])for m in markers)
 result['phases'][phase]={'functions':len(markers),'entire_object_identical':True,'object_sha256':sha(a.data),'changed_function_bytes':{n:len(a.function(n)[0])for n in changed_functions}}
(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
