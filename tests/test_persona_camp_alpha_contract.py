"""Execute the actual Camp opacity producer across all byte input pairs."""
from pathlib import Path
import sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
OWNER=ROOT/'src/Camp/cmpPersona.c'
def fixture_source(mutation=None):
    source=OWNER.read_text();start=source.index('/* The menu initializer and transition copier')
    end=source.index('/* measured: b210 -O2 emits 1340 exact bytes',start)
    types=source[start:end]
    body=Q.function_bodies(OWNER)['func_00137890'][1]
    if mutation:
        before,after=mutation
        if body.count(before)!=1:raise AssertionError((before,body.count(before)))
        body=body.replace(before,after)
    fixture=(ROOT/'tests/persona_camp_alpha_fixture.c.in').read_text()
    fixture=fixture.replace('/* REFERENCE_CALLER */',(ROOT/'tests/persona_camp_alpha_reference.c.in').read_text()).replace('/* ACTUAL_CALLER */',body)
    return RUNTIME_C+'\n#include "type.h"\n#include "shd_misc_internal.h"\n'+types+fixture+ENTRY_C
class PersonaCampAlphaContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,mutation=None,level='-O2'):
        with tempfile.TemporaryDirectory(prefix='p4_camp_alpha_') as directory:
            directory=Path(directory);source=directory/'fixture.c';source.write_text(fixture_source(mutation))
            executable=self.runtime.compile(source,directory/'fixture',level,(ROOT/'include',))
            return self.runtime.run(executable)
    def test_all_byte_pairs_and_callback_mutations(self):
        for level in ('-O0','-O2'):
            result=self.execute(level=level);self.assertEqual(result.returncode,0,result.stdout+result.stderr)
            self.assertEqual(result.stdout,'persona-camp alpha cases: 131072; actual byte producer and callback snapshots verified\n')
    def test_reject_bad_opacity_boundaries(self):
        for mutation in [
            ('func_00115c40(position, spriteOpacity,','func_00115c40(position, menu->alpha,'),
            ('opacity = (f32)entry_alpha * ((f32)base_alpha / 255.0f);','opacity = (f32)entry_alpha * ((f32)base_alpha / 256.0f);')]:
            for level in ('-O0','-O2'):
                self.assertNotEqual(self.execute(mutation,level).returncode,0,'Mutation escaped')
if __name__=='__main__':unittest.main()
