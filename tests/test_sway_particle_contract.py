"""Execute the actual kind-11 controller with bounded native32 seams.

Scalar/VU providers are deterministic test doubles. Callback mutations probe
captured versus live reads, not behavior of the actual providers. These tests
make no transitive actual-provider definedness or exceptional-math claim.
"""
import hashlib
from pathlib import Path
import sys
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import recovery_quality as Q

SCENARIO_COUNT = 28


def replace_once(text, old, new):
    count = text.count(old)
    if count != 1:
        raise AssertionError((old, count))
    return text.replace(old, new, 1)


def controller_source():
    return Q.function_bodies(ROOT / "src/promoted/code1_0049.c")["func_00492100"][1]


def fixture_source(mutation=None):
    body = controller_source()
    if mutation:
        body = replace_once(body, *mutation)
    else:
        # Bind each receipt to the definition actually compiled, without pinning
        # ordinary tests to a historical candidate or an untracked proof file.
        print("sway controller source SHA256: " + hashlib.sha256(body.encode("utf-8")).hexdigest())
    spawn = (ROOT / "include/particle_spawn_internal.h").read_text()
    seam_boundary = "/* VF28..30"
    if spawn.count(seam_boundary) != 1:
        raise AssertionError("Public spawn header seam changed")
    spawn = spawn.split(seam_boundary)[0] + "\n#endif\n"
    spawn = replace_once(
        spawn, '#include "effect_vu0_internal.h"',
        'typedef struct EffectVuVector { f32 lane[4]; } '
        '__attribute__((aligned(16))) EffectVuVector;')
    header = replace_once(
        (ROOT / "include/sway_particle_internal.h").read_text(),
        '#include "particle_spawn_internal.h"', spawn)
    seams = """
typedef struct EffRandState EffRandState;
typedef struct { u32 word[4]; } __attribute__((aligned(16))) u_long128;
void effectVuLoad10(const EffectVuVector *);
void effectVuLoad11(const EffectVuVector *);
void effectVuStore10(EffectVuVector *);
void spawnVuTransform10(void);
void spawnVuAdd10(void);
void spawnVuNormalize10(void);
void spawnVuMultiply10(void);
"""
    return (RUNTIME_C + header + seams + body
            + (ROOT / "tests/sway_particle_fixture.c.in").read_text() + ENTRY_C)


class SwayParticleMutationBinding(unittest.TestCase):
    def test_every_mutation_replaces_exactly_once(self):
        body = controller_source()
        for name, mutation in MUTANTS.items():
            with self.subTest(mutation=name):
                replace_once(body, *mutation)


class SwayParticleContract(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as exc:
            raise unittest.SkipTest(str(exc)) from exc

    def run_fixture(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix="p4_sway_particle_") as tmp:
            path = Path(tmp)
            source = path / "fixture.c"
            source.write_text(fixture_source(mutation))
            for level in ("-O0", "-O2"):
                with self.subTest(optimization=level):
                    exe = self.runtime.compile(source, path / ("fixture" + level),
                                               level, (ROOT / "include",))
                    result = self.runtime.run(exe)
                    diagnostic = result.stdout + result.stderr
                    if mutation is None:
                        self.assertEqual(result.returncode, 0, diagnostic)
                        self.assertEqual(result.stdout,
                                         f"sway particle scenarios: {SCENARIO_COUNT} passed\n")
                        print(level + ": " + result.stdout.strip())
                    else:
                        self.assertEqual(result.returncode, 1,
                                         "Mutant must fail an ordinary assertion: " + diagnostic)
                        self.assertRegex(result.stdout, r"line [0-9]+, scenario [0-9]+: ")

    def test_actual_controller(self):
        self.run_fixture()


LIVE_SNAPSHOT = """else_branch:
    {
        u_long128 *snapshot = &previousPosition;
        *snapshot = *(u_long128 *)&particle->position;
    }"""

MUTANTS={
 'bounce_factor':('    b = (one - a) + a * b;','    b = (one - a) + b;'),
 'zero_lifetime':('if (lifetime == 0)','if (lifetime == -99)'),
 'capture_count':('if (index < count)','if (index < emitter->primaryCount)'),
 'state_stride':('state += 1;','state += 2;'),
 'absolute_budget':('ftmp1 = fabsf(ftmp1);','ftmp1 = ftmp1;'),
 'spread_w':('spread.lane[3] = 0.0f;','spread.lane[3] = 1.0f;'),
 'direction_w':('direction.lane[3] = zero;','direction.lane[3] = 1.0f;'),
 'spawn_snapshot':('particle->age, &previousPosition);','particle->age, (u_long128 *)particle);'),
 'trail_live_parameters':('if (preroll != 0) {\n        trailCount = emitter->parameters->trailCount;','if (preroll != 0) {\n        trailCount = parameters->trailCount;'),
 'trail_live_count':('            trail = emitter->particles + (emitter->primaryCount + particleIndex * trailSpan);', '            trail = emitter->particles + (count + particleIndex * trailSpan);'),
 'preroll_age_reload':('particle->age = particle->age + 1;','particle->age = age + 1;'),
 'live_age_snapshot':('particle->age = age + 1;','particle->age = particle->age + 1;'),
 'snapshot_w':(LIVE_SNAPSHOT, LIVE_SNAPSHOT + '\n    previousPosition.word[3] = 0;'),
 'expired_terminal':('tmp = -2;','tmp = -1;'),
 'angle_sign':('if ((effMiscRand(0) & 1) != 0)','if ((effMiscRand(0) & 1) == 0)'),
 'angle_snapshot':('state->phase = angleRange * b;','state->phase = fGpffff8080 * b;'),
 'live_budget_count':('ftmp2 = (f32)emitter->primaryCount;','ftmp2 = (f32)count;'),
 'physical_snapshot':('state->speed = state->speed - deceleration;','state->speed = state->speed - parameters->deceleration;'),
 'floor_snapshot':('if (particle->position.lane[1] < floorHeight)','if (particle->position.lane[1] < parameters->floorHeight)'),
 'bounce_decay':('state->bounceScale = state->bounceScale * bounceDecay;','state->bounceScale = state->bounceScale;'),
 'bounce_depth':('floorHeight + state->bounceScale * (particle->position.lane[1] - floorHeight)','floorHeight + state->bounceScale * particle->position.lane[1]'),
 'phase_before_sine':('ftmp1 = sinf(state->phase);','state->phase += state->phaseStep; ftmp1 = sinf(state->phase);'),
 'old_amplitude':('c = state->amplitude * ftmp2;','c = (state->amplitude + state->amplitudeStep) * ftmp2;'),
 'initial_amplitude_callback':('a = parameters->finalAmplitudeVariation;','state->amplitude = initialAmplitude; a = parameters->finalAmplitudeVariation;'),
 'live_center':('effectVuLoad11((const EffectVuVector *)&parameters->position);','effectVuLoad11((const EffectVuVector *)&parameters->rotation);'),
}

MUTANTS.update({
    "capture_rise_flags": (
        "if ((flags & 1) != 0) {\n        state->riseDirection",
        "if ((emitter->flags & 1) != 0) {\n        state->riseDirection"),
    "capture_direction_flags": (
        "if ((flags & 1) == 0) {", "if ((emitter->flags & 1) == 0) {"),
    "capture_position_flags": (
        "if ((flags & 1) != 0) {\n        effectVuLoad10(&direction);",
        "if ((emitter->flags & 1) != 0) {\n        effectVuLoad10(&direction);"),
    "capture_angle_mode": ("if (angleMode != 2)", "if (parameters->angleMode != 2)"),
    "capture_angle_offset_mode": ("if (angleMode == 1)", "if (parameters->angleMode == 1)"),
    "runtime_initial_direction": (
        "effectVuLoad10((const EffectVuVector *)&D_00713D40);",
        "direction.lane[0] = 0; direction.lane[1] = 1; direction.lane[2] = 0; "
        "direction.lane[3] = 0; effectVuLoad10(&direction);"),
    "expiry_live_particle_index": (
        "\n        particleIndex = (u32)((u8 *)particle - (u8 *)emitter->particles) / sizeof(*particle);",
        "\n        particleIndex = index;"),
    "preroll_live_particle_index": (
        "\n            particleIndex = (u32)((u8 *)particle - (u8 *)emitter->particles) / sizeof(*particle);",
        "\n            particleIndex = index;"),
    "expiry_live_count": (
        "\n        trail = emitter->particles + (emitter->primaryCount + particleIndex * trailSpan);",
        "\n        trail = emitter->particles + (count + particleIndex * trailSpan);"),
    "expiry_live_parameters": (
        "particle->age = tmp;\n    trailCount = emitter->parameters->trailCount;",
        "particle->age = tmp;\n    trailCount = parameters->trailCount;"),
    "matrix_call_count": ("    func_004bceb0();", "    func_004bceb0(); func_004bceb0();"),
    "random_call_count": (
        "direction.lane[0] = two * (effMiscRandFloat(0) - half);",
        "direction.lane[0] = two * (0.75f - half);"),
    "sine_random_order": (
        "state->previousSine = sinf(state->phase);\n    b = effMiscRandFloat(0);",
        "b = effMiscRandFloat(0);\n    state->previousSine = sinf(state->phase);"),
})


def negative(mutation):
    def test(self):
        self.run_fixture(mutation)
    return test


for name, mutation in MUTANTS.items():
    setattr(SwayParticleContract, "test_reject_" + name, negative(mutation))

if __name__ == "__main__":
    unittest.main()
