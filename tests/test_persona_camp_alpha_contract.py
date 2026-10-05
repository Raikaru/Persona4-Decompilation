"""Execute the actual Camp opacity producer across all byte input pairs."""
from pathlib import Path
import sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
OWNER=ROOT/'src/Camp/cmpPersona.c'
BASE_SHARDS=((0,64),(64,128),(128,192),(192,256))
def fixture_source(mutation=None,*,base_begin=0,base_end=256):
    if type(base_begin) is not int or type(base_end) is not int or not 0<=base_begin<base_end<=256:
        raise ValueError('Invalid exhaustive base-alpha interval')
    source=OWNER.read_text();start=source.index('/* The menu initializer and transition copier')
    end=source.index('/* measured: b210 -O2 emits 1340 exact bytes',start)
    types=source[start:end]
    body=Q.function_bodies(OWNER)['func_00137890'][1]
    if mutation:
        before,after=mutation
        if body.count(before)!=1:raise AssertionError((before,body.count(before)))
        body=body.replace(before,after)
    fixture=(ROOT/'tests/persona_camp_alpha_fixture.c.in').read_text()
    if fixture.count('%%BASE_BEGIN%%')!=2 or fixture.count('%%BASE_END%%')!=1:
        raise AssertionError('Fixture base-alpha interval markers drifted')
    fixture=fixture.replace('%%BASE_BEGIN%%',str(base_begin)).replace('%%BASE_END%%',str(base_end))
    fixture=fixture.replace('/* REFERENCE_CALLER */',(ROOT/'tests/persona_camp_alpha_reference.c.in').read_text()).replace('/* ACTUAL_CALLER */',body)
    return RUNTIME_C+'\n#include "type.h"\n#include "shd_misc_internal.h"\n'+types+fixture+ENTRY_C
class PersonaCampAlphaContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,mutation=None,level='-O2',*,base_begin=0,base_end=256):
        with tempfile.TemporaryDirectory(prefix='p4_camp_alpha_') as directory:
            directory=Path(directory);source=directory/'fixture.c';source.write_text(fixture_source(mutation,base_begin=base_begin,base_end=base_end))
            executable=self.runtime.compile(source,directory/'fixture',level,(ROOT/'include',))
            return self.runtime.run(executable)
    def test_all_byte_pairs_and_callback_mutations(self):
        self.assertEqual([base for begin,end in BASE_SHARDS for base in range(begin,end)],list(range(256)))
        for level in ('-O0','-O2'):
            completed=0
            for begin,end in BASE_SHARDS:
                with self.subTest(optimization=level,base_begin=begin,base_end=end):
                    result=self.execute(level=level,base_begin=begin,base_end=end)
                    self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                    expected=(end-begin)*256*2
                    self.assertEqual(result.stdout,f'persona-camp alpha cases: {expected}; actual byte producer and callback snapshots verified\n')
                    completed+=int(result.stdout.split(': ',1)[1].split(';',1)[0])
            self.assertEqual(completed,131072)
    def test_reject_bad_opacity_boundaries(self):
        for mutation in [
            ('func_00115c40(position, spriteOpacity,','func_00115c40(position, menu->alpha,'),
            ('opacity = (f32)entry_alpha * ((f32)base_alpha / 255.0f);','opacity = (f32)entry_alpha * ((f32)base_alpha / 256.0f);')]:
            for level in ('-O0','-O2'):
                self.assertNotEqual(self.execute(mutation,level).returncode,0,'Mutation escaped')
if __name__=='__main__':unittest.main()
