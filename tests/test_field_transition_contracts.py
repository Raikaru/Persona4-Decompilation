"""Exercise recovered field-transition providers using their actual C definitions."""
from pathlib import Path
import re
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, native32_runtime
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import recovery_quality as Q

GETTERS = ROOT / 'src/promoted/code1_0015.c'
ENVIRONMENT = ROOT / 'src/promoted/k_fldEnvironment.c'
AREA = ROOT / 'src/promoted/code1_0018.c'

FIXTURE = r'''
#include "type.h"
#include "field_transition_internal.h"
#include "sdk_task_registration.h"
static unsigned scenario, checks;
#define CHECK(x) do { ++checks; if (!(x)) native32_failure(__LINE__, scenario, #x); } while (0)
static s32 period, fieldMode, story, special, eventPresent, conditionValue;
static u8 eventData[16];
s32 func_001060c0(void) { return period; }
s16 func_001060b0(void) { return 123; }
s32 func_00110960(s16 day, u8 phase) { CHECK(day == 123); CHECK(phase == (u8)period); return conditionValue; }
u32 datGetFlag(s32 bit) { CHECK(bit == 0x8a || bit == 0xf52); return bit == 0x8a ? story : special; }
s32 func_0014a160(void) { return fieldMode; }
s32 func_0015a0c0(void) { return eventPresent ? (s32)eventData : 0; }
static inline s32 fldEnvironmentEventState(s32 state) {
    u8 *entry = (u8 *)func_0015a0c0();
    if (entry == NULL) return state;
    return entry[0xd];
}
static unsigned allocationCalls, registrationCalls, locationCalls;
static u8 parentTask[64], workArea[0x88d0], returnedTask[64];
char D_005F1DF8[8], D_005F1E08[8];
s32 func_00185850(u8 *task) { return 0; }
void func_00186610(u8 *task) {}
static void *allocate(size_t heap, size_t bytes, u32 flags) {
    CHECK(heap == 1); CHECK(bytes == sizeof(workArea)); CHECK(flags == 0x40000);
    ++allocationCalls; return workArea;
}
void *(*D_008873F4[])(size_t, size_t, u32) = {allocate};
void func_0044ea90(const void *file, u32 line) {
    CHECK(file == D_005F1DF8); CHECK(line == 0x299); ++locationCalls;
}
void *func_00451fc0(void *parent, const void *name, s32 priority, s32 delay,
                   s32 freeDelay, SdkTaskUpdate update, SdkTaskDestroy destroy, u8 *work) {
    CHECK(parent == parentTask); CHECK(name == D_005F1E08); CHECK(priority == 15);
    CHECK(delay == 0); CHECK(freeDelay == 0); CHECK(update == func_00185850);
    CHECK(destroy == func_00186610); CHECK(work == workArea); ++registrationCalls;
    return returnedTask;
}
'''
ORACLE = r'''
static s32 expectedEnvironment(s32 rawKind, s32 rawState, s32 condition) {
    s32 kind = (u16)rawKind, state = (u16)rawState, result = state;
    unsigned phase = (u8)period;
    if (kind == 28 && state == 2) return special == 1 ? 3 : 2;
    if (kind >= 20 && kind < 40) return state;
    if (fieldMode == 1) return eventPresent ? eventData[13] : state;
    if (kind == 4 || kind == 14 || kind == 15 || kind == 16) return state;
    if (kind == 6 && state < 6) result = 1;
    if (kind == 7 && state != 1) result = 2;
    if (kind == 8) { if (state == 2) result = 1; if (result > 2 && result <= 8) return result; }
    if (kind == 9 && state != 1 && state != 4) return state;
    if (kind == 10 && state == 4) result = 3;
    if (kind == 11 && state == 2) return state;
    if (kind == 12 && state == 4) return state;
    if (kind == 13 && state != 8) return state;
    if (kind == 17 && state == 2) result = 1;
    /* Kind 7 rooms 2/3 keep normal period mapping at period 5. */
    if (story == 1 && !(kind == 7 && (state == 2 || state == 3) && phase == 5)) {
        if (condition == 0 || condition == 2) result += 800;
        else if (condition == 1 || condition == 3 || condition == 4) result += 900;
    } else if (condition == 0) {
        if (phase == 4) result += 100;
        else if (phase == 5) result += 200;
    } else if (condition == 2) {
        if (phase < 5) result += 400;
        else if (phase == 5) result += 500;
    } else if (condition == 1 || condition == 3 || condition == 4) {
        if (phase < 5) result += 600;
        else if (phase == 5) result += 700;
    }
    return result;
}
int main(void) {
    u8 task[64], payload[64];
    static const s32 states[] = {-65537, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 65535, 65536, 65538};
    static const s32 conditions[] = {-257, -129, -1, 0, 1, 2, 3, 4, 5, 127, 128, 255, 256};
    *(u8 **)(task + 0x38) = payload;
    for (unsigned value = 0; value < 65536; ++value) {
        scenario = value;
        *(u16 *)(payload + 0x18) = (u16)value;
        *(u16 *)(payload + 0x1a) = (u16)(value ^ 0x5a5a);
        *(u16 *)(payload + 0x20) = (u16)(value ^ 0xa5a5);
        CHECK(func_00156170(task) == value);
        CHECK(func_00156180(task) == (value ^ 0x5a5a));
        CHECK(func_00156190(task) == (value ^ 0xa5a5));
    }
    eventData[13] = 219;
    for (s32 kind = -2; kind <= 70; ++kind)
    for (unsigned si = 0; si < sizeof(states)/sizeof(states[0]); ++si)
    for (unsigned ci = 0; ci < sizeof(conditions)/sizeof(conditions[0]); ++ci)
    for (period = 0; period < 8; ++period)
    for (story = 0; story < 2; ++story) {
        scenario++;
        s32 rawKind = kind + ((si & 1) ? 65536 : 0);
        fieldMode = (si % 3) == 0;
        eventPresent = (ci & 1);
        special = (si & 1);
        conditionValue = conditions[ci];
        CHECK(func_00154720(rawKind, states[si], conditionValue) ==
              expectedEnvironment(rawKind, states[si], conditionValue));
        CHECK(func_001546a0(rawKind, states[si]) ==
              expectedEnvironment(rawKind, states[si], (s8)conditionValue));
    }
    for (unsigned ci = 0; ci < sizeof(conditions)/sizeof(conditions[0]); ++ci) {
        conditionValue = conditions[ci];
        CHECK(captureWrapper(0x7654001c, -65535) == 17);
        CHECK(capturedKind == 0x7654001c && capturedRoom == -65535);
        CHECK(capturedCondition == (s8)conditionValue);
    }
    CHECK(func_00186640(parentTask) == (s32)returnedTask);
    CHECK(allocationCalls == 1 && registrationCalls == 1 && locationCalls == 1);
    native32_text("field transition provider cases "); native32_number(scenario + 1);
    native32_text(", checks "); native32_number(checks); native32_text("\n");
    return 0;
}
'''

def source(mutant=None):
    pieces=[]
    for owner,names in [(GETTERS,['func_00156170','func_00156180','func_00156190']),
                        (ENVIRONMENT,['func_001546a0','func_00154720']),
                        (AREA,['func_00186640'])]:
        bodies=Q.function_bodies(owner)
        pieces.extend(bodies[n][1] for n in names)
    wrapper=Q.function_bodies(ENVIRONMENT)['func_001546a0'][1]
    wrapper_probe=r'''static s32 capturedKind, capturedRoom, capturedCondition;
static s32 captureEnvironment(s32 kind, s32 room, s32 condition) {
    capturedKind=kind; capturedRoom=room; capturedCondition=condition; return 17;
}
#define func_00154720 captureEnvironment
#define func_001546a0 captureWrapper
''' + wrapper + '\n#undef func_001546a0\n#undef func_00154720\n'
    providers='\n'.join(pieces)+wrapper_probe
    if mutant:
        old,new=mutant
        if old not in providers: raise AssertionError('stale mutant: '+old)
        providers=providers.replace(old,new)
    return RUNTIME_C+FIXTURE+providers+ORACLE+ENTRY_C

class FieldTransitionContracts(unittest.TestCase):
    def run_fixture(self, code, optimization):
        runtime=native32_runtime()
        with tempfile.TemporaryDirectory(prefix='field-transition-') as directory:
            path=Path(directory); c=path/'test.c'; c.write_text(code)
            executable=runtime.compile(c,path/'test',optimization,(ROOT/'include',))
            return runtime.run(executable)

    def test_real_providers(self):
        for optimization in ['-O0','-O2']:
            result=self.run_fixture(source(),optimization)
            self.assertEqual(result.returncode,0,result.stdout+result.stderr)
            print(result.stdout.strip())

    def test_negative_controls(self):
        mutants=[
            ('+ 0x18)', '+ 0x1A)'),
            ('return *(u16 *)', 'return *(s16 *)'),
            ('state = (u16)baseState;', 'state = baseState;'),
            ('kind = (u16)fieldKind;', 'kind = fieldKind;'),
            ('(s8)func_00110960', '(u8)func_00110960'),
            ('return (s32)func_00451fc0', 'return !(s32)func_00451fc0'),
        ]
        for mutant in mutants:
            with self.subTest(mutant=mutant[0]):
                result=self.run_fixture(source(mutant),'-O2')
                self.assertNotEqual(result.returncode,0,'mutant escaped: '+str(mutant))

if __name__=='__main__': unittest.main()
