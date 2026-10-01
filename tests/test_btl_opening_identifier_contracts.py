"""Exercise the signed-halfword skill and opening-motion provider contracts."""
from pathlib import Path
import re
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
SOURCES = {'func_001f11e0':'src/promoted/code1_001f.c',
           'func_00199d00':'src/promoted/code1_0019.c',
           'func_001f1210':'src/promoted/code1_001f.c',
           'func_0022fa90':'src/promoted/code1_0022.c',
           'func_0022f950':'src/promoted/code1_0022.c'}

def definition(name):
    text = (ROOT / SOURCES[name]).read_text()
    m = re.search(r'(?m)^[\w *]+\b' + name + r'\([^;]*?\)\s*\{', text)
    end = m.end()
    depth = 1
    while depth:
        depth += (text[end] == '{') - (text[end] == '}')
        end += 1
    return text[m.start():end]

PRELUDE = r'''
#include "type.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "btl_skill_internal.h"
static unsigned scenario;
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__, scenario, #c); } while (0)
static u8 skillTable[65536 * 40];
u8 *iGpffffb3b8 = skillTable + 32768 * 40;
static BtlSkillFlags flagTable[65536];
BtlSkillFlags *iGpffffb3bc = flagTable + 32768;
static u8 unitFlagTable[0x200];
u8 *iGpffffb3e0 = unitFlagTable;
static inline u32 addOffsetFirst(u32 offset, u32 base) { return offset + base; }
static inline u32 addBaseFirst(u32 base, u32 offset) { return base + offset; }
static u64 battleStorage[0x1100 / 8], unitStorage[0xB00 / 8], actionStorage[0x100 / 8];
u8 *iGpffffb3ac = (u8 *)battleStorage;
u8 *DAT_0076449c = (u8 *)battleStorage;
static s32 queryMode, queryMutate, result70, result00;
static u32 queryCalls;
s32 func_001f0ff0(u32 value) {
    u8 *action = (u8 *)actionStorage;
    CHECK(value == (u32)action);
    ++queryCalls;
    if (queryMutate) *(s16 *)(action + 0x6E) = 2;
    return queryMode;
}
s32 func_0022ff70(u8 *action) { CHECK(action == (u8 *)actionStorage); return result70; }
s32 func_0022fc00(u8 *action) { CHECK(action == (u8 *)actionStorage); return result00; }
static s32 classification;
static u32 classificationCalls;
static u8 data[4];
s32 func_0023d8e0(u8 *unit, u16 skill) {
    CHECK(unit == data && skill < 440);
    ++classificationCalls;
    return classification;
}
'''
CHECKS = r'''
int main(void) {
    const u16 flagValues[] = {0, 1, 0x200, 0x201};
    const s32 classes[] = {0x10, 0x11, 1, 3};
    const s16 invalid[] = {-1, 440, 32767};
    const s8 states[] = {-128, -2, -1, 0, 127};
    u8 *unit = (u8 *)unitStorage;
    u8 *action = (u8 *)actionStorage;
    *(u8 **)(unit + 0xA64) = data;
    *(u16 *)(unit + 0xA4) = 2;
    *(u8 **)(action + 0x30) = unit;
    for (u32 bits = 0; bits < 65536; ++bits) {
        s16 skill = (s16)bits;
        ++scenario;
        iGpffffb3b8[(s32)skill * 40 + 2] = (u8)(bits & 1);
        CHECK(func_001f11e0(skill) == (s32)(bits & 1));
    }
    for (s32 skill = 0; skill < 440; ++skill)
    for (u32 kind = 0; kind < 2; ++kind)
    for (u32 flag = 0; flag < 4; ++flag)
    for (u32 paired = 0; paired < 2; ++paired)
    for (u32 boss = 0; boss < 2; ++boss)
    for (u32 cls = 0; cls < 4; ++cls) {
        s32 expected;
        ++scenario;
        iGpffffb3b8[skill * 40 + 2] = kind;
        iGpffffb3bc[skill].flags = flagValues[flag];
        *(u32 *)(iGpffffb3ac + 0xC) = boss ? 0x200000 : 0;
        classification = classes[cls]; classificationCalls = 0;
        if (kind == 1) {
            if (!(flagValues[flag] & 0x200)) expected = paired && (flagValues[flag] & 1) ? 2 : 1;
            else expected = boss && !paired ? 1 : 0;
        } else expected = cls < 2 ? 1 : 3;
        CHECK(func_00199d00(0x55667788, unit, (s16)skill, paired) == expected);
        CHECK(classificationCalls == (kind == 1 ? 0u : 1u));
        *(u16 *)(unitFlagTable + 2 * 0x58) = boss ? 0x10 : 0;
        CHECK(func_001f1210(unit, (s16)skill, paired) == (kind == 1 && paired && !boss && (flagValues[flag] & 1)));
    }
    for (u32 i = 0; i < 3; ++i) {
        ++scenario;
        classificationCalls = 0;
        CHECK(func_00199d00(0, 0, invalid[i], 0) == 1 && classificationCalls == 0);
    }
    for (u32 boss = 0; boss < 2; ++boss)
    for (u32 active = 0; active < 2; ++active)
    for (u32 kind = 0; kind < 3; ++kind)
    for (u32 motion = 4; motion <= 8; motion += 4)
    for (u32 value = 0; value < 5; ++value) {
        s32 expected;
        ++scenario;
        *(u32 *)(iGpffffb3ac + 0xC) = boss ? 0x200000 : 0;
        *(u16 *)(action + 0x1A) = active;
        unit[0xA2] = kind;
        iGpffffb3ac[0xC10 + motion] = (u8)states[value];
        expected = !boss || !active || kind != 1 || states[value] != -2;
        CHECK(func_0022fa90(action, (s16)motion) == expected);
    }
    {
        const u16 unitFlags[] = {0, 1, 0x10, 0x20, 0x21};
        for (u32 boss = 0; boss < 2; ++boss)
        for (u32 paired = 0; paired < 2; ++paired)
        for (u32 flag = 0; flag < 5; ++flag)
        for (u32 r70 = 0; r70 < 2; ++r70)
        for (u32 r00 = 0; r00 < 2; ++r00)
        for (u32 mutate = 0; mutate < 2; ++mutate) {
            s32 expected;
            ++scenario;
            *(u32 *)(iGpffffb3ac + 0xC) = boss ? 0x200000 : 0;
            *(u16 *)(unitFlagTable + 2 * 0x58) = unitFlags[flag];
            iGpffffb3b8[1 * 40 + 2] = 1; iGpffffb3b8[2 * 40 + 2] = 0;
            iGpffffb3bc[1].flags = iGpffffb3bc[2].flags = 1;
            *(u16 *)(action + 0x6E) = 1;
            queryMode = paired; queryMutate = mutate; queryCalls = 0;
            result70 = r70; result00 = r00;
            if (!boss) expected = 0;
            else if (unitFlags[flag] & 1) expected = !(!mutate && paired);
            else if (!paired && (unitFlags[flag] & 0x20)) expected = 1;
            else expected = r70 == 1 || r00 == 0;
            CHECK(func_0022f950(action, unit) == expected);
            CHECK(queryCalls == boss);
        }
    }
    CHECK(scenario == 122139);
    native32_text("122139 signed-identifier cases passed\n");
    return 0;
}
'''

def fixture(mutation=None, wide=None):
    bodies = []
    for name in SOURCES:
        b = definition(name)
        if name == mutation:
            if name == 'func_001f11e0': b = b.replace('== 1', '== 2')
            if name == 'func_00199d00': b = b.replace('0x1B8', '0x1B7')
            if name == 'func_001f1210': b = b.replace('return 1;', 'return 0;')
            if name == 'func_0022fa90': b = b.replace('!= -2', '!= -1')
            if name == 'func_0022f950':
                b, n = re.subn(r'(paired = func_001f0ff0\(\(u32\)arg0\);)(\s*)(skill = \*\(s16 \*\)\(arg0 \+ 0x6E\);)', r'\3\2\1', b)
                assert n == 1
        if name == wide:
            parameter = {'func_001f11e0':'arg0','func_00199d00':'arg2','func_001f1210':'arg1','func_0022fa90':'arg1'}[name]
            b = b.replace('s16 ' + parameter, 's64 ' + parameter, 1)
        bodies.append(b)
    return RUNTIME_C + PRELUDE + '\n'.join(bodies) + CHECKS + ENTRY_C

class OpeningIdentifierContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as exc:
            raise unittest.SkipTest(str(exc))

    def execute(self, text, optimization):
        with tempfile.TemporaryDirectory() as tmp:
            p = Path(tmp)
            source = p / 'fixture.c'; source.write_text(text)
            executable = self.runtime.compile(source, p / 'fixture', optimization, (ROOT / 'include',))
            return self.runtime.run(executable)

    def test_actual_providers(self):
        for opt in ('-O0', '-O2'):
            with self.subTest(optimization=opt):
                result = self.execute(fixture(), opt)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertIn('122139 signed-identifier cases passed', result.stdout)

    def test_wrong_results_are_detected(self):
        for name in SOURCES:
            with self.subTest(provider=name):
                result = self.execute(fixture(mutation=name), '-O2')
                self.assertNotEqual(result.returncode, 0)

    def test_wide_contracts_are_rejected(self):
        for name in ('func_001f11e0', 'func_00199d00', 'func_001f1210', 'func_0022fa90'):
            with self.subTest(provider=name), self.assertRaisesRegex(RuntimeError, 'compilation failed'):
                self.execute(fixture(wide=name), '-O2')

if __name__ == '__main__':
    unittest.main()
