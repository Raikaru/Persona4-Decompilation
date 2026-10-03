"""Execute all remaining Title byte-clear, alpha-alias and raw-copy families."""
from pathlib import Path
import re,sys,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
OWNER=ROOT/'src/promoted/code1_0012.c'

def families():
    source=OWNER.read_text();body=extract_guarded_body(source,'FUN_001265A0','func_001265a0');rows=[]
    for m in re.finditer(r'(var_3_\d+) = (sp[0-9A-F]+)\.bytes;',body):
        pointer,src=m.groups();tail=body[m.end():]
        copy=re.search(r'titleCopyValue\(\(u8 \*\)&(sp[0-9A-F]+), \(const u8 \*\)&'+src+r'\);',tail);assert copy
        dst=copy[1];prefix=tail[:copy.end()];counter=re.search(r'(var_2_\d+) = 4;',prefix)[1]
        layer=src+'.bytes[3] = 0xFF;' in prefix
        calls=list(re.finditer(r'func_0045d6e0\([^;]+;',tail)) if layer else list(re.finditer(r'titleRectangle\([^;]+;',tail))
        last=calls[1 if layer else 0];block=body[m.start():m.end()+last.end()]
        rows.append(dict(pointer=pointer,source=src,destination=dst,counter=counter,layer=layer,copy=copy[0],block=block))
    assert len(rows)==24 and sum(r['layer'] for r in rows)==11
    return source,body,rows

def fixture(mutation=None):
    source,body,rows=families();objects=sorted({r[k] for r in rows for k in ('source','destination')});assert len(objects)==46
    names=set(objects)
    for row in rows:names|={row['pointer'],row['counter']}|set(re.findall(r'\bsp[0-9A-F]+\b',row['block']))
    decl={name:re.search(r'(?m)^\s*(\w+ \*?'+name+r';)',body)[1] for name in names}
    assert all(decl[n]=='TitleDrawColor '+n+';' for n in objects)
    guards='\n'.join('struct { u8 before[16]; '+decl[n]+' u8 after[16]; } guard_'+n+';' for n in objects)
    aliases='\n'.join('#define '+n+' guard_'+n+'.'+n for n in objects)
    unalias='\n'.join('#undef '+n for n in objects)
    locals_='\n'.join(decl[n] for n in sorted(names-set(objects)))
    pointers=', '.join('(u8 *)&'+n for n in objects)
    guardchecks='\n'.join('for(u32 i=0;i<16;++i)CHECK(guard_'+n+'.before[i]==0xA5&&guard_'+n+'.after[i]==0xA5);' for n in objects)
    initialize='\n'.join('memset(&guard_'+n+',0xA5,sizeof(guard_'+n+'));' for n in objects)
    cases=[]
    for index,r in enumerate(rows):
        pre='expectedSource=(u8 *)&'+r['source']+'; expectedColor=(u8 *)&'+r['destination']+';layer='+str(int(r['layer']))+';'
        pre+='CHECK(sizeof(*'+r['pointer']+')==1);store_word(expectedSource,word);'+r['copy']+'CHECK(load_word(expectedColor)==word&&load_word(expectedSource)==word);'
        pre+='for(u32 i=0;i<46;++i)memcpy(snapshot[i],colors[i],4);phase=0;'
        block=r['block']
        if mutation=='wrong_alpha' and r['layer']:block=block.replace('.bytes[3] = 0xFF;', '.bytes[0] = 0xFF;')
        if mutation=='short_clear':block=block.replace(r['counter']+' = 4;',r['counter']+' = 3;')
        if mutation=='wrong_source' and index==0:block=block.replace('(const u8 *)&'+r['source'], '(const u8 *)&sp61C')
        if mutation=='recopy_between_calls' and r['layer']:
            matches=list(re.finditer(r'func_0045d6e0\([^;]+;',block));at=matches[1].start();block=block[:at]+r['copy']+'\n'+block[at:]
        if mutation=='source_alias' and r['layer']:block=block.replace('func_0045d6e0((u8 *)&'+r['destination'], 'func_0045d6e0((u8 *)&'+r['source'])
        cases.append('case '+str(index)+': { '+pre+'\n'+block+'\nCHECK('+r['pointer']+'=='+r['source']+'.bytes+4&&'+r['counter']+'==0);\nbreak; }')
    helpers=source[source.index('typedef union { f32 value; u8 bytes[4]; } TitleDrawColor;'):source.index('static inline f32 titleBlend')]
    if mutation=='numeric_copy':helpers=helpers.replace('*(TitleDrawColor *)destination = *(const TitleDrawColor *)source;','((TitleDrawColor *)destination)->value = (f32)*(const s32 *)source;')
    if mutation=='short_copy':helpers=helpers.replace('*(TitleDrawColor *)destination = *(const TitleDrawColor *)source;','for(s32 i=0;i<3;++i)destination[i]=source[i];')
    if mutation=='wide_clear':
        locals_=locals_.replace('u8 *var_3_3;','s32 *var_3_3;')
        cases[0]=cases[0].replace('var_3_3 = sp624.bytes;','var_3_3 = (s32 *)sp624.bytes;')
    text=Path(__file__).with_name('title_color_families_fixture.c.in').read_text()
    for key,val in dict(HELPERS=helpers,GUARDS=guards,ALIASES=aliases,UNALIAS=unalias,LOCALS=locals_,POINTERS=pointers,GUARD_CHECKS=guardchecks,INITIALIZE=initialize,CASES='\n'.join(cases)).items():text=text.replace('@'+key+'@',val)
    assert not re.search(r'@[A-Z_]+@',text)
    return RUNTIME_C+text+ENTRY_C

class TitleColorFamilies(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_color_families_') as temporary:
            path=Path(temporary);source=path/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,path/'fixture',opt,(ROOT/'include',))
            return self.runtime.run(binary)
    def test_all_actual_color_families(self):
        for opt in ('-O0','-O2'):
            r=self.execute(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr);self.assertEqual(r.stdout,'49872 color-family cases passed\n');print(opt,r.stdout.strip())
    def test_negative_controls(self):
        for m in ('wrong_alpha','short_clear','wrong_source','recopy_between_calls','source_alias','numeric_copy','short_copy','wide_clear'):
            with self.subTest(mutation=m):
                r=self.execute('-O2',m);self.assertEqual(r.returncode,1,r.stdout+r.stderr);self.assertIn('scenario',r.stdout)

if __name__=='__main__':unittest.main()
