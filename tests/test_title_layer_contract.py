"""Exercise all 30 actual layer calls through the real layer/vertex providers."""
from pathlib import Path
import re,sys,tempfile,unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path[:0]=[str(ROOT/'tools'),str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from test_btl_motion_override_contract import definition
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime

def parts():
    text=(ROOT/'src/promoted/code1_0012.c').read_text();body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
    calls=re.findall(r'func_0045d6e0\(\(u8 \*\)&(\w+), \(f32 \*\)&(\w+), (0\.0f|10\.0f), ([01])\);',body)
    assert len(calls)==30
    prototype=re.search(r'extern void func_0045d6e0\(u8 \*color, f32 \*rectangle, f32 depth, s32 saveState\);',body)[0]
    provider_source=(ROOT/'src/promoted/code1_0045.c').read_text()
    types=re.search(r'typedef struct \{\s*f32 v\[4\];\s*\} Code45Float4;',provider_source)[0]+'\n'+re.search(r'typedef struct Code45RenderState \{.*?\} Code45RenderState;',provider_source,re.S)[0]
    types+='\n'+re.search(r'typedef union \{ f32 value; u8 bytes\[4\]; \} TitleDrawColor;',text)[0]
    wrappers=[]
    for index,(color,rect,depth,state) in enumerate(calls):
        cdecl=re.search(r'(?m)^\s*\w+ '+color+r';',body)[0].strip()
        rdecl=re.search(r'(?m)^\s*\w+ '+rect+r';',body)[0].strip()
        call=f'func_0045d6e0((u8 *)&{color}, (f32 *)&{rect}, {depth}, {state});'
        assert call in body
        wrappers.append('''static void call_%d(void) {
    struct { u32 before[4]; %s u32 after[4]; } c;
    struct { u32 before[4]; %s u32 after[4]; } r;
    memset(&c,0xA5,sizeof(c));memset(&r,0xA5,sizeof(r));
    CHECK(sizeof(c.%s)==4&&sizeof(r.%s)==16);
    memcpy(&c.%s,colorValue,4);memcpy(&r.%s,rectangleValue,16);
#define %s c.%s
#define %s r.%s
    %s
#undef %s
#undef %s
    CHECK(memcmp(&c.%s,colorValue,4)==0&&memcmp(&r.%s,rectangleValue,16)==0);
    for(u32 i=0;i<4;++i)CHECK(c.before[i]==0xA5A5A5A5U&&c.after[i]==0xA5A5A5A5U&&r.before[i]==0xA5A5A5A5U&&r.after[i]==0xA5A5A5A5U);
}'''%(index,cdecl,rdecl,color,rect,color,rect,color,color,rect,rect,call,color,rect,color,rect))
    sites='\n'.join('{call_%d, %s, %s},'%(i,d,s) for i,(_,_,d,s) in enumerate(calls))
    return dict(TYPES=types,PROTOTYPE=prototype,CALLERS='\n'.join(wrappers),SITES=sites,
                PROVIDERS='\n'.join(definition('src/promoted/code1_0045.c',n) for n in ('func_0045ce40','func_0045d6e0')))

def fixture(mutation=None):
    v=parts()
    changes={
      'zero_depth_wrong':('CALLERS',', 0.0f, 1);',', 1.0f, 1);'),
      'ten_depth_lost':('CALLERS',', 10.0f, 1);',', 0.0f, 1);'),
      'state_flag_lost':('CALLERS',', 0.0f, 1);',', 0.0f, 0);'),
      'wrong_color_identity':('CALLERS','(u8 *)&sp6BC, (f32 *)&sp590','(u8 *)&sp590, (f32 *)&sp590'),
      'wrong_rectangle_word':('PROVIDERS','work.pos = *(Code45Float4 *)arg1;','work.pos = *(Code45Float4 *)arg1; work.pos.v[0] = 0.0f;'),
      'short_vertex_clear':('PROVIDERS','memset(work.out, 0, 0x100);','memset(work.out, 0x11, 0x100);'),
      'state_restore_missing':('PROVIDERS','D_00887300[0](p->state, work.saved[j]);','D_00887300[0](p->state, p->val);'),
      'wrong_vertex_depth':('PROVIDERS','z = D_008872F8_abs[0] - z;','z = D_008872F8_abs[0] + z;'),
      'get_set_swapped':('PROVIDERS','D_00887304[0](p->state, (void *)&work.saved[i]);\n            D_00887300[0](p->state, p->val);','D_00887300[0](p->state, p->val);\n            D_00887304[0](p->state, (void *)&work.saved[i]);'),
      'alpha_missing':('PROVIDERS','v7[11] = (f32)colors[3];','v7[11] = 0.0f;'),
    }
    if mutation:
        k,a,b=changes[mutation];assert a in v[k];v[k]=v[k].replace(a,b)
    text=Path(__file__).with_name('title_layer_contract_fixture.c.in').read_text()
    for k,x in v.items():text=text.replace('@'+k+'@',x)
    assert not re.search(r'@[A-Z_]+@',text)
    return RUNTIME_C+text+ENTRY_C

class TitleLayerContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_layer_') as temporary:
            path=Path(temporary);source=path/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,path/'fixture',opt,(ROOT/'include',))
            return self.runtime.run(binary)
    def test_all_actual_calls_and_layer_vertex_providers(self):
        for opt in ('-O0','-O2'):
            r=self.execute(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr);self.assertEqual(r.stdout,'122880 layer caller/provider cases passed\n');print(opt,r.stdout.strip())
    def test_negative_controls(self):
        for mutation in ('zero_depth_wrong','ten_depth_lost','state_flag_lost','wrong_color_identity','wrong_rectangle_word','short_vertex_clear','state_restore_missing','wrong_vertex_depth','alpha_missing','get_set_swapped'):
            with self.subTest(mutation=mutation):
                r=self.execute('-O2',mutation);self.assertEqual(r.returncode,1,r.stdout+r.stderr);self.assertIn('scenario',r.stdout)

if __name__=='__main__':unittest.main()
