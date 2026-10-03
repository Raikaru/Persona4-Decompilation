"""Execute the actual two opening rectangle snapshots through both providers."""
from pathlib import Path
import re,sys,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from test_btl_motion_override_contract import definition
from test_title_layer_contract import parts as layer_parts
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime

def fixture(mutation=None):
    text=(ROOT/'src/promoted/code1_0012.c').read_text();body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
    typ=re.search(r'typedef union TitleRectangleWords \{.*?\} TitleRectangleWords;',body,re.S)[0]
    start=body.index('sp520.bits =');calls=list(re.finditer(r'func_0045d6e0\([^;]+;',body[start:]));block=body[start:start+calls[1].end()]
    cstart=body.index('temp_2 = (s32)(M2C_FIELD(temp_20, s32 *, 0x88) + 1);');cend=body.index('temp_f0_4 =',cstart);counter=body[cstart:cend]
    names=('sp520','sp510','sp590','sp6BC','temp_f20','temp_2')
    decl={n:re.search(r'(?m)^\s*(\w+ '+n+r';)',body)[1] for n in names}
    guards='\n'.join('struct { u8 before[16]; '+decl[n]+' u8 after[16]; } guard_'+n+';' for n in names[:4])
    aliases='\n'.join('#define '+n+' guard_'+n+'.'+n for n in names[:4]);unalias='\n'.join('#undef '+n for n in names[:4])
    init='\n'.join('memset(&guard_'+n+',0xA5,sizeof(guard_'+n+'));' for n in names[:4])
    checks='\n'.join('for(u32 i=0;i<16;++i)CHECK(guard_'+n+'.before[i]==0xA5&&guard_'+n+'.after[i]==0xA5);' for n in names[:4])
    if mutation=='stale_first_template':block=block.replace('sp590 = sp520.bits;','sp590 = D_005E5650;')
    if mutation=='stale_second_template':block=block.replace('sp590 = sp510.bits;','sp590 = D_005E5660;')
    if mutation=='wrong_first_member':block=block.replace('sp520.words[1] =','sp520.words[0] =')
    if mutation=='wrong_second_member':block=block.replace('sp510.words[1] =','sp510.words[2] =')
    if mutation=='early_truncation':block=block.replace('temp_f20 = 42.0f * (1.0f - ((f32) M2C_FIELD(temp_20, s32 *, 0x88) / 20.0f));','temp_f20 = (f32)(s32)(42.0f * (1.0f - ((f32) M2C_FIELD(temp_20, s32 *, 0x88) / 20.0f)));')
    if mutation=='wrong_y_base':block=block.replace('406.0f + temp_f20','405.0f + temp_f20')
    if mutation=='float_y_bits':block=block.replace('sp520.words[1] = (s32)-temp_f20;','((f32 *)sp520.words)[1] = -temp_f20;')
    providers='\n'.join(definition('src/promoted/code1_0045.c',n) for n in ('func_0045ce40','func_0045d6e0'))
    v=dict(TYPES=layer_parts()['TYPES']+'\n'+typ,PROVIDERS=providers,BLOCK=block,COUNTER=counter,GUARDS=guards,ALIASES=aliases,UNALIAS=unalias,INITIALIZE=init,GUARD_CHECKS=checks,LOCALS=decl['temp_f20']+'\n'+decl['temp_2'])
    template=Path(__file__).with_name('title_rectangle_alias_fixture.c.in').read_text()
    for k,value in v.items():template=template.replace('@'+k+'@',value)
    assert not re.search(r'@[A-Z_]+@',template)
    return RUNTIME_C+template+ENTRY_C

class TitleRectangleAliases(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_rectangle_alias_') as temporary:
            path=Path(temporary);source=path/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,path/'fixture',opt,(ROOT/'include',))
            return self.runtime.run(binary)
    def test_live_rectangle_snapshots(self):
        for opt in ('-O0','-O2'):
            r=self.execute(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr);self.assertEqual(r.stdout,'65536 rectangle snapshot/provider cases passed\n');print(opt,r.stdout.strip())
    def test_negative_controls(self):
        for m in ('stale_first_template','stale_second_template','wrong_first_member','wrong_second_member','early_truncation','wrong_y_base','float_y_bits'):
            with self.subTest(mutation=m):
                r=self.execute('-O2',m);self.assertEqual(r.returncode,1,r.stdout+r.stderr);self.assertIn('scenario',r.stdout)

if __name__=='__main__':unittest.main()
