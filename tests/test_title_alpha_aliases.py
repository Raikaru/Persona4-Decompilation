"""Exercise the two GP-color alpha aliases and their actual conversion branches."""
from pathlib import Path
import re,sys,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime

def source_parts():
    text=(ROOT/'src/promoted/code1_0012.c').read_text();body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
    blocks=[]
    for first in ('sp69C.value =','temp_f2_3 = fGpffff8094;'):
        start=body.index(first);end=body.index(';',body.index('func_0045d6e0(',start))+1;blocks.append(body[start:end])
    start=blocks[1].index('if (!(temp_f1_11 >=');end=blocks[1].index('sp698.bytes[3]');conversion=blocks[1][start:end]
    names=('sp69C','sp698','sp6BC','sp500','sp4F0','sp590','var_3_26','var_3_29','temp_f2_3','temp_f0_5','temp_f1_11','temp_16')
    decl={n:re.search(r'(?m)^\s*(\w+ '+n+r';)',body)[1] for n in names}
    return text,body,blocks,conversion,decl

def fixture(mutation=None):
    text,body,blocks,conversion,decl=source_parts()
    helpers=text[text.index('typedef union { f32 value; u8 bytes[4]; } TitleDrawColor;'):text.index('static inline f32 titleBlend')]
    guards='\n'.join('struct { u8 before[16]; '+decl[n]+' u8 after[16]; } guard_'+n+';' for n in ('sp69C','sp698','sp6BC','sp590'))
    aliases='\n'.join('#define '+n+' guard_'+n+'.'+n for n in ('sp69C','sp698','sp6BC','sp590'));unalias='\n'.join('#undef '+n for n in ('sp69C','sp698','sp6BC','sp590'))
    init='\n'.join('memset(&guard_'+n+',0xA5,sizeof(guard_'+n+'));' for n in ('sp69C','sp698','sp6BC','sp590'))
    checks='\n'.join('for(u32 i=0;i<16;++i)CHECK(guard_'+n+'.before[i]==0xA5&&guard_'+n+'.after[i]==0xA5);' for n in ('sp69C','sp698','sp6BC','sp590'))
    if mutation=='old_constant_alpha':blocks[0]=blocks[0].replace('(u32)(s32)255.0f & 0xFF','0x4F000000 & 0xFF')
    if mutation=='old_dynamic_alpha':blocks[1]=blocks[1].replace('(u32)(s32)temp_f1_11 & 0xFF','0x4F000000 & 0xFF')
    if mutation=='wrong_alpha_alias':blocks=[b.replace('.bytes[3] =','.bytes[0] =') for b in blocks]
    if mutation=='numeric_gp_color':blocks=[b.replace('= fGpffff9c80;','= (f32)(s32)fGpffff9c80;').replace('= fGpffff9c84;','= (f32)(s32)fGpffff9c84;') for b in blocks]
    if mutation=='wrong_rectangle_identity':
        blocks[0]=blocks[0].replace('(f32 *)&sp590','(f32 *)&sp500')
        blocks[1]=blocks[1].replace('(f32 *)&sp590','(f32 *)&sp4F0')
    if mutation=='numeric_phase':blocks[1]=blocks[1].replace('temp_f2_3 = fGpffff8094;','temp_f2_3 = (f32)(s32)fGpffff8094;')
    if mutation=='copy_before_alpha':
        for i,(src,var) in enumerate((('sp69C','var_3_26'),('sp698','var_3_29'))):
            a=src+'.bytes[3] = (u8)'+var+';';c='titleCopyValue((u8 *)&sp6BC, (const u8 *)&'+src+');';assert blocks[i].index(a)<blocks[i].index(c)
            blocks[i]=blocks[i].replace(a,'@SWAP@').replace(c,a).replace('@SWAP@',c)
    if mutation=='wrong_high_byte':conversion=conversion.replace('0x80000000U','0x80000080U')
    if mutation=='numeric_copy':helpers=helpers.replace('*(TitleDrawColor *)destination = *(const TitleDrawColor *)source;','((TitleDrawColor *)destination)->value = (f32)*(const s32 *)source;')
    template=Path(__file__).with_name('title_alpha_alias_fixture.c.in').read_text()
    data=dict(HELPERS=helpers,GUARDS=guards,ALIASES=aliases,UNALIAS=unalias,INITIALIZE=init,GUARD_CHECKS=checks,CONSTANT=blocks[0],DYNAMIC=blocks[1],CONVERSION=conversion,CONVERSION_DECL=decl['var_3_29'],CONVERSION_INPUT_DECL=decl['temp_f1_11'],LOCALS='\n'.join(decl[n] for n in decl if n not in ('sp69C','sp698','sp6BC','sp590')))
    for k,v in data.items():template=template.replace('@'+k+'@',v)
    assert not re.search(r'@[A-Z_]+@',template)
    return RUNTIME_C+template+ENTRY_C

class TitleAlphaAliases(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_alpha_alias_') as temporary:
            path=Path(temporary);source=path/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,path/'fixture',opt,(ROOT/'include',))
            return self.runtime.run(binary)
    def test_actual_alpha_alias_blocks(self):
        for opt in ('-O0','-O2'):
            r=self.execute(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr);self.assertEqual(r.stdout,'alpha_calls=16508 conversion_cases=2537\n');print(opt,r.stdout.strip())
    def test_negative_controls(self):
        for m in ('old_constant_alpha','old_dynamic_alpha','wrong_alpha_alias','numeric_gp_color','numeric_phase','copy_before_alpha','wrong_high_byte','numeric_copy','wrong_rectangle_identity'):
            with self.subTest(mutation=m):
                r=self.execute('-O2',m);self.assertEqual(r.returncode,1,r.stdout+r.stderr);self.assertIn('scenario',r.stdout)

if __name__=='__main__':unittest.main()
