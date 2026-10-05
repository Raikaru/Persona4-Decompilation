"""Execute the actual Wave controller in the native 32-bit ABI.

Only VU0 primitives and external callees are modeled. The fixture does not
claim target floating exception equivalence or a full effect/game simulation.
"""
from pathlib import Path
import re,sys,tempfile,unittest
from native32_support import ENTRY_C,RUNTIME_C,Native32Unavailable,native32_runtime
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'));import recovery_quality as Q

def fixture_source(mutation=None):
 body=Q.function_bodies(ROOT/'src/promoted/code1_0048.c')['func_0048b9e0'][1]
 if mutation:
  old,new=mutation
  if body.count(old)!=1:raise AssertionError((old,body.count(old)))
  body=body.replace(old,new)
 header=(ROOT/'include/particle_spawn_internal.h').read_text().split('/* VF28..30')[0]
 header=header.replace('#include "effect_vu0_internal.h"','typedef struct EffectVuVector { f32 lane[4]; } __attribute__((aligned(16))) EffectVuVector;')+'\n#endif\n'
 return RUNTIME_C+header+'''
typedef struct { u32 word[4]; } __attribute__((aligned(16))) u_long128;
typedef struct EffRandState EffRandState;
u32 effMiscRand(EffRandState *);
f32 effMiscRandFloat(EffRandState *);
f32 fabsf(f32);
void effectVuLoad10(const EffectVuVector *);
void effectVuLoad11(const EffectVuVector *);
void effectVuStore10(EffectVuVector *);
void spawnVuTransform10(void);
void spawnVuNormalize10(void);
void spawnVuMultiply10(void);
void spawnVuAdd10(void);
void func_004bceb0(void);
'''+body+(ROOT/'tests/wave_spawn_fixture.c.in').read_text()+ENTRY_C
class WaveSpawnContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def run_fixture(self, mutation=None, invalid_conversion=False):
        with tempfile.TemporaryDirectory(prefix="p4_wave_spawn_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(fixture_source(mutation))
            for level in ("-O0", "-O2"):
                executable = self.runtime.compile(
                    source, directory / ("fixture" + level), level, (ROOT / "include",))
                result = self.runtime.run(executable)
                if mutation is None:
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertIn("wave spawn scenarios: 13", result.stdout)
                    print(result.stdout.strip())
                elif invalid_conversion:
                    # The signed-remainder mutation creates a negative value,
                    # then an out-of-range unsigned-float-to-signed-age cast.
                    # This is a UBSan trap control, not a semantic assertion.
                    self.assertIn(result.returncode, (-4, 132), result.stdout + result.stderr)
                else:
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertIn("line ", result.stdout)

    def test_actual_controller(self):
        self.run_fixture()


MUTANTS = {'unsigned_rate': ('ftmp2 = (f32)(u32)tmp;', 'ftmp2 = (f32)(s32)tmp;'),
 'zero_lifetime': ('if (lifetime == 0)', 'if (lifetime == -99)'),
 'preroll_byte': ('(parameters->preroll != 0)', '(parameters->unknownbc != 0)'),
 'unsigned_rng': ('(u32)effMiscRand(0) % (u32)lifetime', '(s32)effMiscRand(0) % lifetime'),
 'negative_accumulator': ('ftmp1 = fabsf(ftmp1);', 'ftmp1 = ftmp1;'),
 'cached_count': ('ftmp2 = (f32)emitter->primaryCount;', 'ftmp2 = (f32)count;'),
 'loop_count': ('if (index < count)', 'if (index < emitter->primaryCount)'),
 'trail_age': ('trail->age = -1;\n        trail += 1;', 'trail->age = 0;\n        trail += 1;'),
 'expired_age': ('tmp = -2;', 'tmp = -1;'),
 'angle_sign': ('if ((effMiscRand(0) & 1) != 0)', 'if ((effMiscRand(0) & 1) == 0)'),
 'callback_order': ('finalAmplitudeVariation = parameters->finalAmplitudeVariation;',
                    'state->amplitude = c; finalAmplitudeVariation = '
                    'parameters->finalAmplitudeVariation;'),
 'preroll_increment': ('particle->age = particle->age + 1;', 'particle->age = age + 1;'),
 'live_increment': ('particle->age = age + 1;', 'particle->age = particle->age + 1;'),
 'snapshot_w': ('else_branch:\n'
                '    {\n'
                '        u_long128 *snapshot = &b220buf;\n'
                '        *snapshot = *(u_long128 *)&particle->position;\n'
                '    }',
                'else_branch:\n'
                '    {\n'
                '        u_long128 *snapshot = &b220buf;\n'
                '        *snapshot = *(u_long128 *)&particle->position;\n'
                '    }\n'
                '    b220buf.word[3] = 0;'),
 'preroll_extra_phase': ('state->phase = state->phase + state->phaseStep;\n'
                         '        state->amplitude',
                         'state->phase = state->phase;\n        state->amplitude'),
 'state_stride': ('state += 1;', 'state += 2;'),
 'unit_scalar': ('one = 1.0f;', 'one = 2.0f;'),
 'gravity_product': ('gravitySquaredDistance = prerollElapsed * gravityDistance;',
                     'gravitySquaredDistance = gravityDistance;'),
 'trail_element_index': ('            trail = emitter->particles + (emitter->primaryCount + '
                         'particleIndex * (u32)trailLength);',
                         '            trail = emitter->particles + (emitter->primaryCount + '
                         '(particleIndex + 1U) * (u32)trailLength);'),
 'narrow_preroll_flag': ('u8 initialPreroll = 1;', 'u8 initialPreroll = 0;')}


def negative(name, mutation):
    def test(self):
        self.run_fixture(mutation, invalid_conversion=(name == "unsigned_rng"))
    return test


for name, mutation in MUTANTS.items():
    setattr(WaveSpawnContract, "test_reject_" + name, negative(name, mutation))

if __name__ == "__main__":
    unittest.main()
