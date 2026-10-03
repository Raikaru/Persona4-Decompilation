"""Execute six actual GP-color copy chains through fullscreen/layer providers."""
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
    prototype=re.search(r'extern void func_0045c870\(u8 \*colors, s32 enabled\);',body)[0]
    wrappers=[];schedules=[];symbols=[]
    for index,suffix in enumerate(('70','74','78','7c','88','8c')):
        symbol='fGpffff9c'+suffix;symbols.append(symbol)
        match=re.search(r'(?m)^\s*(temp_f0(?:_\d+)?) = '+symbol+r';\n\s*(sp[0-9A-F]+) = \1;\n\s*sp6BC.value = \1;',body);assert match
        temp,backup=match[1],match[2];chain=match[0].strip()
        decl={n:re.search(r'(?m)^\s*(\w+ '+n+r';)',body)[1] for n in (temp,backup,'sp6BC','sp590')}
        fullscreen=suffix not in ('7c','88')
        provider_name='func_0045c870' if fullscreen else 'func_0045d6e0'
        call=re.search(provider_name+r'\([^;]+;',body[match.end():])[0]
        if mutation=='numeric_gp':chain=chain.replace('= '+symbol+';','= (f32)(s32)'+symbol+';')
        if mutation=='wrong_shared_copy':chain=chain.replace('sp6BC.value = '+temp+';','sp6BC.value = 0.0f;')
        if mutation=='wrong_fullscreen_state' and fullscreen:call=call.replace(', 1);',', 0);')
        if mutation=='wrong_color_identity':call=call.replace('(u8 *)&sp6BC','(u8 *)&'+backup)
        wrappers.append('''static void call_%d(void) {
    struct { u8 before[16]; %s u8 after[16]; } shared;
    struct { u8 before[16]; %s u8 after[16]; } saved;
    %s
    %s
    memset(&shared,0xA5,sizeof(shared));memset(&saved,0xA5,sizeof(saved));
    memcpy(&sp590,rectangle,16);
#define sp6BC shared.sp6BC
#define %s saved.%s
    CHECK(sizeof(sp6BC)==4&&sizeof(%s)==4);
    %s
    CHECK(load_word(&%s)==word&&load_word(&%s)==word&&load_word(&sp6BC)==word);
    expectedColor=(u8 *)&sp6BC;
    %s
    CHECK(load_word(&sp6BC)==drawWord&&load_word(&%s)==word);
    for(u32 i=0;i<16;++i)CHECK(shared.before[i]==0xA5&&shared.after[i]==0xA5&&saved.before[i]==0xA5&&saved.after[i]==0xA5);
#undef sp6BC
#undef %s
}'''%(index,decl['sp6BC'],decl[backup],decl[temp],decl['sp590'],backup,backup,backup,chain,temp,backup,call,backup,backup))
        schedules.append('{call_'+str(index)+', '+str(int(fullscreen))+'},')
    providers='\n'.join(definition('src/promoted/code1_0045.c',n) for n in ('func_0045c870','func_0045ce40','func_0045d6e0'))
    if mutation=='missing_fullscreen_alpha':providers=providers.replace('work.out[11] = (f32)colors[3];','work.out[11] = 0.0f;')
    if mutation=='wrong_fullscreen_width':providers=providers.replace('work.out[32] = 640.0f;','work.out[32] = 639.0f;')
    if mutation=='get_set_swapped':
        providers=providers.replace('D_00887304[0](p[0], (void *)&work.saved[i]);\n            D_00887300[0](p[0], p[1]);','D_00887300[0](p[0], p[1]);\n            D_00887304[0](p[0], (void *)&work.saved[i]);')
    data=dict(TYPES=layer_parts()['TYPES'],PROTOTYPE=prototype,GP_DECLS='\n'.join('static f32 '+s+';' for s in symbols),GP_SETUP='\n'.join('memcpy(&'+s+',&word,4);' for s in symbols),GP_CHECKS='\n'.join('CHECK(load_word(&'+s+')==word);' for s in symbols),PROVIDERS=providers,CALLERS='\n'.join(wrappers),SITES='\n'.join(schedules))
    template=Path(__file__).with_name('title_gp_color_transport_fixture.c.in').read_text()
    for k,v in data.items():template=template.replace('@'+k+'@',v)
    assert not re.search(r'@[A-Z_]+@',template)
    return RUNTIME_C+template+ENTRY_C

class TitleGpColorTransport(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_gp_color_') as temporary:
            path=Path(temporary);source=path/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,path/'fixture',opt,(ROOT/'include',))
            return self.runtime.run(binary)
    def test_six_actual_copy_chains_and_draw_providers(self):
        for opt in ('-O0','-O2'):
            r=self.execute(opt);self.assertEqual(r.returncode,0,r.stdout+r.stderr);self.assertEqual(r.stdout,'6234 GP color/provider cases passed\n');print(opt,r.stdout.strip())
    def test_negative_controls(self):
        for m in ('numeric_gp','wrong_shared_copy','wrong_fullscreen_state','wrong_color_identity','missing_fullscreen_alpha','wrong_fullscreen_width','get_set_swapped'):
            with self.subTest(mutation=m):
                r=self.execute('-O2',m);self.assertEqual(r.returncode,1,r.stdout+r.stderr);self.assertIn('scenario',r.stdout)

if __name__=='__main__':unittest.main()
