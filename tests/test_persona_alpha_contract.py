"""Check the actual byte-alpha providers against frozen wide source and pulse arithmetic."""
from pathlib import Path
import sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import recovery_quality as Q
OWNER=ROOT/'src/promoted/shdPersona.c'
def fixture_source(mutation=None):
    bodies=Q.function_bodies(OWNER)
    actual='\n'.join(bodies[f][1] for f in ['func_00116d40','func_001162f0'])
    if mutation:
        before,after=mutation
        if actual.count(before)!=1:raise AssertionError((before,actual.count(before)))
        actual=actual.replace(before,after)
    fixture=(ROOT/'tests/persona_alpha_fixture.c.in').read_text()
    fixture=fixture.replace('/* REFERENCE_PROVIDERS */',(ROOT/'tests/persona_alpha_reference.c.in').read_text())
    fixture=fixture.replace('/* ACTUAL_PROVIDERS */',actual)
    return RUNTIME_C+'\n#include "type.h"\n#include "shd_misc_internal.h"\n'+fixture+ENTRY_C
class PersonaAlphaContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error
    def execute(self,mutation=None,level='-O2'):
        with tempfile.TemporaryDirectory(prefix='p4_persona_alpha_') as directory:
            directory=Path(directory);source=directory/'fixture.c';source.write_text(fixture_source(mutation))
            executable=self.runtime.compile(source,directory/'fixture',level,(ROOT/'include',))
            return self.runtime.run(executable)
    def test_all_byte_values_and_provider_boundaries(self):
        for level in ('-O0','-O2'):
            with self.subTest(level=level):
                result=self.execute(level=level)
                self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                self.assertEqual(result.stdout,'persona-alpha provider cases: 129536; independent pulse and byte-domain boundary verified\n')
    def test_reject_provider_mutations(self):
        mutations={
            'pulse':('(u8)((f32)alpha * rate)','(u8)alpha'),
            'signed_alpha':('(u8)((f32)alpha * rate)','(u8)((f32)(s8)alpha * rate)'),
            'meter_width':('((filled & 0xFF) * 204) / 99 + 10','((filled & 0xFF) * 204) / 99 + 11'),
            'border_alpha':('m = arg1 & 0xFF;','m = arg1 & 0x7F;'),
        }
        for name,mutation in mutations.items():
            for level in ('-O0','-O2'):
                with self.subTest(mutation=name,level=level):
                    result=self.execute(mutation,level)
                    self.assertNotEqual(result.returncode,0,'Mutation escaped: '+name)
if __name__=='__main__':unittest.main()
