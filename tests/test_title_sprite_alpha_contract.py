"""Source-bound sprite alpha and independently rounded signed-pair contracts.

The ten actual conversion-to-call slices execute with independent finite inputs.
The two-sine subgraph separately preserves its actual source expressions and calls;
sinf and sprite APIs are typed, controlled boundaries, not the real renderer.
"""
from pathlib import Path
import re, sys, tempfile, unittest
ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT/'tools'), str(ROOT/'tests')]
from measure_guarded import extract_guarded_body
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable
from test_title_fade_contract import runtime

SITES = [('var_5','temp_f1'),('var_5_10','temp_f1_8'),('var_5_11','temp_f2'),
         ('var_5_12','temp_f1_9'),('var_5_13','temp_f1_10'),('var_5_14','temp_f21_2'),
         ('var_5_15','temp_f21_2'),('var_5_18','temp_f1_15'),
         ('var_5_19','temp_f1_16'),('var_5_20','temp_f1_17')]

def parts():
    text=(ROOT/'src/promoted/code1_0012.c').read_text()
    body=extract_guarded_body(text,'FUN_001265A0','func_001265a0')
    blocks=[]
    for var,value in SITES:
        point=body.index(var+' = (u32)(s32)'+value+' & 0xFF;')
        start=body.rindex('if (!(',0,point)
        call=re.search(r'func_0025f(?:3f0|430)\(',body[point:])
        end=body.index(';',point+call.start())+1
        blocks.append(body[start:end])
    start=body.index('temp_f20_5 = sinf(')
    end=body.index(';',body.index('func_0025f430(-9.0f',start))+1
    subgraph=body[start:end]
    names=[v for pair in SITES for v in pair]
    names+=['temp_f20','temp_f21','temp_f7','temp_f8','temp_f14','temp_f14_2',
            'temp_f16','temp_f16_2','temp_f16_3','temp_10','temp_20','temp_f20_5',
            'temp_16','var_2_21']
    names=list(dict.fromkeys(names))
    declarations='\n'.join(re.search(r'(?m)^    (?:f32|s32|u32) \*?'+n+r';',body)[0] for n in names)
    prototypes='\n'.join(re.search(r'extern s32 '+name+r'\([^;]+;',body)[0] for name in ('func_0025f3f0','func_0025f430'))
    return blocks,subgraph,declarations,prototypes

SUBGRAPH_CONTROLS={
 'first_return_truncated':('temp_f20_5 = sinf(', 'temp_f20_5 = (f32)(s32)sinf('),
 'scale_truncated':('temp_f16 = fGpffff8170 + temp_f16;', 'temp_f16 = (f32)(s32)(fGpffff8170 + temp_f16);'),
 'alpha_float_truncated':('temp_f21_2 = 255.0f *', 'temp_f21_2 = (f32)(s32)(255.0f *'),
 'alpha_drives_pair':('(137.0f * temp_f16)', '(temp_f21_2)'),
 'wrong_pair_factor':('(137.0f * temp_f16)', '(136.0f * temp_f16)'),
 'pair_unsigned':('(s16)(s32)(137.0f * temp_f16)', '(u16)(s32)(137.0f * temp_f16)'),
 'wrong_selection':('temp_16 >= 0x88', 'temp_16 >= 0x89'),
 'wrong_phase_divisor':('/ 225.0f', '/ 224.0f'),
 'wrong_second_phase':('/ 90.0f', '/ 89.0f'),
 'wrong_pair_slot':('1, temp_10, temp_10,', '1, temp_10, temp_10 + 1,'),
 'wrong_scale_slot':('temp_f16, temp_f16);', 'temp_f16, temp_f16 + 1.0f);'),
 'alpha_input_mutated':('temp_10 = (s16)', 'temp_f21_2 += 1.0f;\n                temp_10 = (s16)'),
}

def fixture(mutation=None):
    blocks,subgraph,decl,proto=parts()
    if mutation and mutation.startswith(('old_low_','wrong_high_','wrong_call_')):
        kind,index=mutation.rsplit('_',1);index=int(index);var,value=SITES[index]
        if kind=='old_low':old,new=var+' = (u32)(s32)'+value+' & 0xFF;',var+' = 0x4F000000 & 0xFF;'
        elif kind=='wrong_high':old,new='0x80000000U','0x80000080U'
        else:old,new=', '+var+',',', '+var+' + 1,'
        assert blocks[index].count(old)==1
        blocks[index]=blocks[index].replace(old,new,1)
    elif mutation:
        old,new=SUBGRAPH_CONTROLS[mutation];assert subgraph.count(old)==1,mutation
        subgraph=subgraph.replace(old,new,1)
        if mutation=='alpha_float_truncated':
            old='(1.0f - temp_f21_2);';assert subgraph.count(old)==1;subgraph=subgraph.replace(old,'(1.0f - temp_f21_2));')
    functions=[]
    for index,((var,value),block) in enumerate(zip(SITES,blocks)):
        functions.append('static void site_'+str(index)+'(f32 value) {\n'+decl+'\n'+
                         'SETUP_LOCALS; '+value+'=value;\n'+block+'\n CHECK(draws==1);}\n')
    template=Path(__file__).with_name('title_sprite_alpha_contract_fixture.c.in').read_text()
    values=dict(PROTOTYPES=proto,LOCALS=decl,FUNCTIONS='\n'.join(functions),SUBGRAPH=subgraph,
                SITE_FUNCTIONS=', '.join('site_'+str(i) for i in range(10)))
    for key,value in values.items():template=template.replace('@'+key+'@',value)
    assert not re.search(r'@[A-Z_]+@',template)
    return RUNTIME_C+template+ENTRY_C

class TitleSpriteAlphaContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_sprite_alpha_') as name:
            path=Path(name);source=path/'fixture.c';source.write_text(fixture(mutation))
            return self.runtime.run(self.runtime.compile(source,path/'fixture',opt,(ROOT/'include',)))
    def test_all_actual_conversion_calls_and_sine_subgraph(self):
        for opt in ('-O0','-O2'):
            result=self.execute(opt);self.assertEqual(result.returncode,0,result.stdout+result.stderr)
            self.assertEqual(result.stdout,'conversion_calls=25370 subgraph_calls=32400 pair_cases=30841\n')
            print(opt,result.stdout.strip())
    def test_each_site_negative_controls(self):
        for kind in ('old_low','wrong_high','wrong_call'):
            for index in range(10):
                with self.subTest(kind=kind,index=index):
                    result=self.execute('-O2',kind+'_'+str(index))
                    self.assertEqual(result.returncode,1,result.stdout+result.stderr);self.assertIn('scenario',result.stdout)
    def test_independent_subgraph_controls(self):
        for mutation in SUBGRAPH_CONTROLS:
            with self.subTest(mutation=mutation):
                result=self.execute('-O2',mutation)
                self.assertEqual(result.returncode,1,result.stdout+result.stderr);self.assertIn('scenario',result.stdout)

if __name__=='__main__':unittest.main()
