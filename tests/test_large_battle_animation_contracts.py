"""Execute all 15 guarded animation call expressions against their live factory.

This intentionally does not execute the unfinished controllers: unrelated UID,
output-buffer and expression defects remain. Calls are extracted without
rewriting their arguments. Expectations come from retail register setup.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime
ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
from measure_guarded import extract_guarded_body
from test_btl_motion_override_contract import definition

CREATOR = 'btlUnitCreateAnimPacket'
# Retail order in each controller, including constants and dynamic values.
SITES = ((0x1a5e30, 'raw', 0, 'rate', 'mode'),
         (0x1a6534, 26, 0, 1, 0), (0x1a6570, 26, 0, 1, 2),
         (0x1a67a4, 'raw', 0, 1, 0),
         (0x1a7fe4, 13, 'frame', 1, 4), (0x1a8444, 15, 0, 1, 5),
         (0x1a8628, 'raw', 0, 1, 2), (0x1a8854, 22, 6, 1, 0),
         (0x1a8be0, 'raw', 6, 'rate', 'mode'), (0x1a8ebc, 6, 0, 1, 2),
         (0x1a8f60, 7, 6, 1, 2), (0x1a92b8, 26, 0, 1, 0),
         (0x1a9300, 26, 0, 1, 2), (0x1a9400, 10, 0, 1, 1),
         (0x1aa250, 'byte', 0, 'rate', 0))


def guarded(name):
    text = (ROOT / 'src/promoted/code1_001a.c').read_text()
    return extract_guarded_body(text, 'FUN_' + name[5:].upper(), name)


def calls(body, name):
    found = []
    for match in re.finditer(r'\b' + name + r'\(', body):
        prefix = body[body.rfind('\n', 0, match.start()) + 1:match.start()]
        if prefix.lstrip().startswith('extern '):
            continue
        end, depth = match.end(), 1
        while depth:
            depth += (body[end] == '(') - (body[end] == ')')
            end += 1
        found.append(body[match.start():end])
    return found


def fixture(mutation=None):
    bodies = [guarded('func_001a59a0'), guarded('func_001a7720')]
    expressions = calls(bodies[0], CREATOR) + calls(bodies[1], CREATOR)
    assert len(expressions) == len(SITES)
    factory = definition('src/Battle/btlUnit.c', CREATOR)
    creator_type = re.search(r'(?m)^extern BtlPacket \*btlUnitCreateAnimPacket\([^;]+;',
                            (ROOT / 'src/promoted/code1_001a.c').read_text())[0]
    if mutation == 'unsigned_byte':
        assert '*(s8 *)(u32)sp100' in expressions[-1]
        expressions[-1] = expressions[-1].replace('*(s8 *)(u32)sp100', '*(u8 *)(u32)sp100')
    if mutation == 'lost_rate':
        factory = factory.replace('work->speed = speed;', 'work->speed = 1.0f;')
    if mutation == 'wrong_mode':
        factory = factory.replace('work->mode = mode;', 'work->mode = blendFrameCount;')
    if mutation == 'unsigned_id':
        factory = factory.replace('s16 _id;', 'u16 _id;')
    if mutation == 'wrong_blend':
        factory = factory.replace('work->blendFrameCount = blendFrameCount;', 'work->blendFrameCount = mode;')
    if mutation == 'lost_special':
        factory = factory.replace('case -2:', 'case -6:')
    if mutation == 'wide_signature':
        factory = factory.replace('s16 id,', 's32 id,')
    wrappers = []
    for index, expression in enumerate(expressions):
        # All source-local names retain their actual pointer and scalar types.
        # Source call expressions are used verbatim, including conversion sites.
        wrappers.append('static BtlPacket *site_%x(void) {\n' % SITES[index][0] + r'''
    u8 *arg0 = action, *temp_19 = (u8 *)&unit;
    s64 *var_22_3 = (s64 *)action, *temp_18 = (s64 *)action;
    u8 *sp4D0 = (u8 *)&unit, *temp_22_3 = action, *temp_2_64 = action, *var_21_2 = action;
    s32 var_30 = raw, var_16 = mode, sp2A0 = raw, temp_22 = raw;
    s16 sp430 = (s16)raw;
    s64 var_18_2 = frame;
    s32 var_17_5 = mode, sp100 = (s32)&byte;
    f32 var_f20 = rate, var_f20_2 = rate;
    return ''' + expression + ';\n}')
    expectation = []
    for address, motion, frame, speed, mode in SITES:
        expectation.append('{%s, %s, %s, %s, site_%x}' %
                           ({'raw': '-1000', 'byte': '-1001'}.get(motion, motion),
                            -1 if frame == 'frame' else frame,
                            '-1.0f' if speed == 'rate' else str(speed) + '.0f',
                            -1 if mode == 'mode' else mode, address))
    prelude = (ROOT / 'tests/large_battle_animation_fixture.c.in').read_text()
    return (RUNTIME_C + prelude.replace('%%CREATOR_TYPE%%', creator_type)
            .replace('%%FACTORY%%', factory).replace('%%CALLS%%', '\n'.join(wrappers))
            .replace('%%SITES%%', ',\n'.join(expectation)) + ENTRY_C)


class LargeBattleAnimationContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as exc:
            raise unittest.SkipTest(str(exc))

    def exercise(self, mutation=None):
        with tempfile.TemporaryDirectory(prefix='p4_large_battle_') as directory:
            p = Path(directory)
            source = p / 'fixture.c'
            source.write_text(fixture(mutation))
            for opt in ('-O0', '-O2'):
                executable = self.runtime.compile(source, p / ('fixture' + opt), opt, (ROOT / 'include',))
                result = self.runtime.run(executable)
                if mutation:
                    self.assertNotEqual(result.returncode, 0, mutation + ' escaped at ' + opt)
                else:
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                    self.assertEqual(result.stdout, '6300 animation caller/factory cases passed\n')

    def test_actual_calls_and_factory(self):
        self.exercise()

    def test_mutation_controls(self):
        for mutation in ('unsigned_byte', 'lost_rate', 'wrong_mode', 'unsigned_id', 'wrong_blend', 'lost_special'):
            with self.subTest(mutation=mutation):
                self.exercise(mutation)

    def test_signature_is_canonical(self):
        with tempfile.TemporaryDirectory() as directory:
            p = Path(directory)
            source = p / 'fixture.c'
            source.write_text(fixture('wide_signature'))
            with self.assertRaisesRegex(RuntimeError, 'conflicting types'):
                self.runtime.compile(source, p / 'fixture', '-O2', (ROOT / 'include',))


class LargeBattleCallSource(unittest.TestCase):
    def test_no_animation_local_override(self):
        for name in ('func_001a59a0', 'func_001a7720'):
            self.assertNotRegex(guarded(name), r'extern[^;]*\bbtlUnitCreateAnimPacket\s*\(')

    def test_timing_calls_have_defined_narrowing(self):
        for name in ('func_001a59a0', 'func_001a7720'):
            body = guarded(name)
            for fn in ('func_001991c0', 'func_00199350', 'func_00199500', 'func_001999f0', 'func_00199d00'):
                for expression in calls(body, fn):
                    self.assertNotIn(expression + ' << 0x30', body)


def opening_assignment():
    body = guarded('func_001a7720')
    lines = [line.strip() for line in body.splitlines()
             if 'temp_22 =' in line and 'func_00199d00(' in line]
    assert len(lines) == 1
    return lines[0]


def opening_fixture(mutation=None):
    import test_btl_opening_identifier_contracts as opening
    assignment = opening_assignment()
    if mutation == 'wrong_skill':
        assignment = assignment.replace(', sp450,', ', -1,')
    if mutation == 'wrong_paired':
        assignment = assignment.replace(', sp33C)', ', 0)')
    wrapper = '''
static s32 largeBattleOpeningCall(u8 *unit, s16 skill, s32 paired) {
    u8 *temp_5 = unit;
    s16 sp450 = skill;
    s32 sp33C = paired, temp_22;
    ''' + assignment + '''
    return temp_22;
}
'''
    checks = opening.CHECKS.replace(
        'func_00199d00(0x55667788, unit, (s16)skill, paired)',
        'largeBattleOpeningCall(unit, (s16)skill, paired)').replace(
        'func_00199d00(0, 0, invalid[i], 0)',
        'largeBattleOpeningCall(unit, invalid[i], 0)')
    checks = checks.replace('*(u8 **)(unit + 0xA64) = data;',
                            '*(u8 **)(unit + 0xA64) = data;\n    *(u32 *)(unit + 0xA0C) = 0xF00DA123U;')
    providers = '\n'.join(opening.definition(name) for name in opening.SOURCES)
    return RUNTIME_C + opening.PRELUDE + providers + wrapper + checks + ENTRY_C


class LargeBattleOpeningContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as exc:
            raise unittest.SkipTest(str(exc))

    def test_actual_opening_call_and_providers(self):
        with tempfile.TemporaryDirectory(prefix='p4_large_opening_') as directory:
            p = Path(directory)
            for mutation in (None, 'wrong_skill', 'wrong_paired'):
                source = p / 'fixture.c'
                source.write_text(opening_fixture(mutation))
                for opt in ('-O0', '-O2'):
                    with self.subTest(mutation=mutation, optimization=opt):
                        exe = self.runtime.compile(source, p / ('fixture' + opt), opt, (ROOT / 'include',))
                        result = self.runtime.run(exe)
                        if mutation:
                            self.assertNotEqual(result.returncode, 0)
                        else:
                            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                            self.assertIn('122139 signed-identifier cases passed', result.stdout)

    def test_opening_result_conversion_boundary(self):
        # The real selector returns 0..3. These are isolated ABI-boundary stress
        # inputs, not an assertion that gameplay produces out-of-domain values.
        for mutation in (False, True):
            assignment = opening_assignment()
            if mutation:
                assignment = assignment.replace('(s16)func_00199d00', '(u16)func_00199d00')
            source_text = RUNTIME_C + r'''
#include "type.h"
static s32 result;
static u64 storage[0xA10 / 8];
static u8 *temp_5 = (u8 *)storage;
static s16 sp450;
static s32 sp33C;
static s32 func_00199d00(s32 unused, u8 *unit, s16 skill, s32 paired) {
    if ((u32)unused != 0xF00DA123U || unit != temp_5 || skill != sp450 || paired != sp33C)
        native32_exit(2);
    return result;
}
int main(void) {
    s32 temp_22;
    *(u32 *)(temp_5 + 0xA0C) = 0xF00DA123U;
    for (u32 raw = 0; raw < 65536; ++raw) {
        result = (s32)(0x12340000U | raw);
        sp450 = (s16)raw; sp33C = raw & 1;
        ''' + assignment + r'''
        if (temp_22 != (s16)raw) return 1;
    }
    return 0;
}
''' + ENTRY_C
            with tempfile.TemporaryDirectory() as directory:
                p = Path(directory); source = p / 'fixture.c'; source.write_text(source_text)
                for opt in ('-O0', '-O2'):
                    result = self.runtime.run(self.runtime.compile(source, p / ('f' + opt), opt, (ROOT / 'include',)))
                    self.assertEqual(result.returncode, 1 if mutation else 0, result.stdout + result.stderr)


def timing_fixture(mutation=None):
    body = guarded('func_001a59a0')
    names = ('func_001991c0', 'func_001999f0', 'func_00199500', 'func_00199350')
    expressions = []
    for name in names:
        expressions.extend((body.index(call), name, call) for call in calls(body, name))
    expressions.sort()
    assert len(expressions) == 6
    declarations = re.search(r'^    (?:s32|f32) var_f20;', body, re.M)[0]
    initialization = re.search(r'if \(temp_2 != 0\) \{\s*var_f20 =[^}]+\} else \{\s*var_f20 =[^}]+\}', body)[0]
    if mutation == 'integer_rate':
        declarations = declarations.replace('f32', 's32')
        initialization = initialization.replace('1.75f', '0x3FE00000').replace('1.0f', '0x3F800000')
    wrappers = []
    for index, (_, name, call) in enumerate(expressions):
        if mutation == 'wrong_hit' and index == 5:
            call = call.replace('(sp200 + 1) & 0xFFFF', '0')
        wrappers.append('static s16 timing_%d(void) {\n' % index + r'''
    u8 *temp_19 = unit;
    s64 *arg0 = (s64 *)action;
    s32 var_30 = rawMotion, sp200 = hit - 1, temp_2 = fast;
''' + declarations + '\n' + initialization + '\nreturn ' + call + ';\n}')
    return RUNTIME_C + r'''
#include "type.h"
#include "btl_motion_internal.h"
static u64 unitStorage[0xA70/8], actionStorage[0x100/8];
static u8 *unit = (u8 *)unitStorage, *action = (u8 *)actionStorage;
static s32 rawMotion, hit, fast;
static s16 result;
static u8 *seenUnit;
static u16 seenMotion;
static f32 seenRate;
static s64 seenHit;
static s32 seenKind;
static s16 record(u8 *u, u16 m, f32 r, s64 h, s32 kind) {
    seenUnit=u; seenMotion=m; seenRate=r; seenHit=h; seenKind=kind; return result;
}
s16 func_001991c0(u8 *u,u16 m,f32 r) { return record(u,m,r,0,0); }
s16 func_001999f0(u8 *u,u16 m,f32 r,s64 h) { return record(u,m,r,h,1); }
s16 func_00199500(u8 *u,u16 m,f32 r) { return record(u,m,r,0,2); }
s16 func_00199350(u8 *u,u16 m,f32 r) { return record(u,m,r,0,3); }
''' + '\n'.join(wrappers) + r'''
static s16 (*const sites[])(void) = {timing_0,timing_1,timing_2,timing_3,timing_4,timing_5};
int main(void) {
    const u32 values[] = {0,0x7fff,0x8000,0xffff,0x10000,0xffff8000};
    const s16 returns[] = {-32768,-1,0,1,32767};
    const s32 kinds[] = {0,1,2,2,3,1};
    *(u8 **)(action+0x30)=unit; *(u8 **)(action+0x88)=action;
    for(s32 site=0;site<6;++site)for(s32 i=0;i<6;++i)for(s32 j=0;j<6;++j)
    for(fast=0;fast<2;++fast)for(s32 r=0;r<5;++r) {
        rawMotion=(s32)values[i];hit=(s32)(values[j]&0x1ffff);result=returns[r];
        if(sites[site]()!=result || seenUnit!=unit || seenKind!=kinds[site])return 1;
        if(seenMotion!=(site==3?26:(u16)rawMotion))return 2;
        if(seenRate!=(site==3?1.0f:fast?1.75f:1.0f))return 3;
        if(seenHit!=(site==5?(u16)hit:0))return 4;
    }
    return 0;
}
''' + ENTRY_C


class LargeBattleTimingCalls(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as exc:
            raise unittest.SkipTest(str(exc))

    def test_six_actual_calls_and_rate_selection(self):
        with tempfile.TemporaryDirectory() as directory:
            p = Path(directory)
            for mutation in (None, 'integer_rate', 'wrong_hit'):
                source = p / 'fixture.c'; source.write_text(timing_fixture(mutation))
                for opt in ('-O0', '-O2'):
                    with self.subTest(mutation=mutation, optimization=opt):
                        result = self.runtime.run(self.runtime.compile(source, p / ('f' + opt), opt, (ROOT/'include',)))
                        if mutation:
                            self.assertNotEqual(result.returncode, 0)
                        else:
                            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
