from pathlib import Path
import sys,subprocess,json,hashlib,struct
sys.path[:0]=['tools'];import verify as V,probe_variants as P
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








out=Path('build/immediate-rectangle');out.mkdir(parents=True,exist_ok=True);owner=Path('src/promoted/code1_0045.c').resolve();base='58553aa1b6ffd6d42c58f623d1d97677e00b1be3';old=subprocess.check_output(['git','show',base+':src/promoted/code1_0045.c'],text=True);new=owner.read_text();cfg=V.load_config();result={'base':base,'source_sha256':sha(new.encode()),'phases':{}};objects={}
for phase in ['production','guards']:
    for label,src in [('base',old),('candidate',new)]:
        obj=out/(phase+'-'+label+'.o')
        with P.scratch_source(owner)as scratch:
            scratch.write_text(('#define NON_MATCHING\n'if phase=='guards'else'')+src);ok,log=P._compile_in_context(scratch,owner,cfg,obj);obj.with_suffix('.log').write_text(log);assert ok,log
        objects[phase,label]=V.ObjectFile(obj)
    a,b=[objects[phase,label]for label in ['base','candidate']];markers=V.scan_markers(owner)
    assert all(a.function(m['name'])==b.function(m['name'])for m in markers)
    assert allocated(a)==allocated(b)
    result['phases'][phase]={'functions':len(markers),'raw_function_bytes_and_all_relocations_identical':True,'all_allocated_sections_and_bindings_identical':True}
code,refs=objects['production','candidate'].function('func_0045d6e0');retail=V.RetailElf(cfg['retail_elf'],V._read_json(V.TARGET),V._read_json(V.FUNCTION_WINDOWS)['sha1']);rc=retail.bytes_at(0x45d6e0,len(code));assert V.compare(code,refs,rc)[0]==0
result.update({'bytes':len(code),'reference_count':len(refs),'sha256':sha(code),'frame':-struct.unpack_from('<h',code)[0],'retail_masked_differences':0,'target_refs':refs})
(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:v for k,v in result.items()if k!='target_refs'},indent=2))
