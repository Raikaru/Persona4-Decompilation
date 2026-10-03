"""Exercise the actual guarded timing/clamp fragment over signed-halfword inputs."""
from pathlib import Path
import sys
import tempfile
import unittest
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from measure_guarded import extract_guarded_body
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime


def fragment():
    body=extract_guarded_body((ROOT/'src/promoted/code1_001a.c').read_text(),'FUN_001A59A0','func_001a59a0')
    start=body.index('    var_18 = (s16)var_23;')
    end=body.index('    temp_2_6 = ',start)
    consumer=next(line.strip() for line in body.splitlines() if line.strip().startswith('temp_2_17 = '))
    assert consumer=='temp_2_17 = (s16)var_18;'
    return body[start:end]+consumer+'\n'


def fixture(mutation=None):
    source=fragment()
    changes={
      'old_zero_cap':('timingAdjustment = 25;','timingAdjustment = 0;'),
      'cap_26':('timingAdjustment = 25;','timingAdjustment = 26;'),
      'quarter_scale':('fGpffff8128 *','0.25f *'),
      'round_instead_of_truncate':('(s32)(fGpffff8128 * (f32)(temp_2_4 - var_23))','(s32)(fGpffff8128 * (f32)(temp_2_4 - var_23) + 0.5f)'),
      'both_optional_flags':('(sp258 != 0) || (sp254 != 0)','(sp258 != 0) && (sp254 != 0)'),
      'wrong_paired_addition':('var_18 + 0xC','var_18 + 8'),
      'lost_halfword_wrap':('(s16)','(s32)'),
    }
    if mutation:
        old,new=changes[mutation];assert old in source;source=source.replace(old,new)
    template=Path(__file__).with_name('large_battle_timing_clamp_fixture.c.in').read_text()
    return RUNTIME_C+template.replace('@CALCULATION@',source)+ENTRY_C


class LargeBattleTimingClamp(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:cls.runtime=native32_runtime()
        except Native32Unavailable as error:raise unittest.SkipTest(str(error)) from error

    def execute(self,opt,mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_timing_clamp_') as temporary:
            directory=Path(temporary);source=directory/'fixture.c';source.write_text(fixture(mutation))
            binary=self.runtime.compile(source,directory/'fixture',opt,(ROOT/'include',))
            return self.runtime.run(binary)

    def test_signed_timing_difference_clamp_additions_and_transport(self):
        for opt in ('-O0','-O2'):
            with self.subTest(optimization=opt):
                result=self.execute(opt)
                self.assertEqual(result.returncode,0,result.stdout+result.stderr)
                self.assertEqual(result.stdout,'timing_clamp_cases=1572864\n')
                print(opt,result.stdout.strip())

    def test_negative_controls(self):
        for mutation in ('old_zero_cap','cap_26','quarter_scale','round_instead_of_truncate','both_optional_flags','wrong_paired_addition','lost_halfword_wrap'):
            with self.subTest(mutation=mutation):
                result=self.execute('-O2',mutation)
                self.assertEqual(result.returncode,1,result.stdout+result.stderr)
                self.assertIn('scenario',result.stdout)


if __name__=='__main__':unittest.main()
