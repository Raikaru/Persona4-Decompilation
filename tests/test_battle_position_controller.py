"""Execute the actual production 001b2380 with complete provider outputs.

The expected routes and dependency ordinals come from retail 001b2380..001b33b8.
The scoped production pragmas and source body are preserved. No target-body
ABI or pointer-width rewrites are made for the host fixture.
"""
from pathlib import Path
import re
import tempfile
import unittest
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]
OWNER = ROOT / 'src/promoted/code1_001b.c'


def target_body():
    text = OWNER.read_text()
    signature = text.index('s32 func_001b2380(void)')
    start = text.rfind('#pragma push\n', 0, signature)
    assert start >= 0, 'missing production target pragma scope'
    assert '#pragma opt_lifetimes on\n' in text[start:signature]
    assert '// FUN_001B2380\n' in text[start:signature]
    i = text.index('{', signature) + 1
    depth = 1
    while depth:
        depth += (text[i] == '{') - (text[i] == '}')
        i += 1
    closing_scope = re.match(r'\s*#pragma pop(?:\n|$)', text[i:])
    assert closing_scope, 'missing production target pragma pop'
    return text[start:i + closing_scope.end()]


TARGET_MUTATIONS = {
    'readiness16': ('if (func_00193c70() == 0)', 'if ((u16)func_00193c70() == 0)'),
    'omit_delay_submission': (
        'func_00194590((u8 *)func_0019aa70((BtlUnit *)unit,\n'
        '              func_00199500(unit,0x13,1.0f)),1);',
        '(void)func_0019aa70((BtlUnit *)unit,\n'
        '              func_00199500(unit,0x13,1.0f));'),
    'uid32': ('*(u64 *)(nodeOrPacket + 0x58)', '(u32)*(u64 *)(nodeOrPacket + 0x58)'),
    'list_stride4': ('(u16)group * 8 + 0x178', '(u16)group * 4 + 0x178'),
    'signed_class8': ('s16 unitClassOrFrames;', 's8 unitClassOrFrames;'),
    'lose_y': ('offset.y = position.y;', 'offset.y = 0.0f;'),
    'group_bonus_crossed': ('(hasSkill214 == 1)', '(hasSkill213 == 1)'),
    'wrong_special_distance': ('offset.x = offset.x * 100.0f;', 'offset.x = offset.x * 300.0f;'),
    'missing_vector_z': ('offset.z = offset.z * 500.0f;', 'offset.z = offset.z;'),
    'wrong_packet_phase': (
        '*(u64 *)(movePacket + 8) = *(u64 *)(nodeOrPacket + 0x58);',
        '*(u64 *)(movePacket + 8) = *(u64 *)(unit + 0x58);'),
    'skip_bonus_cursor_reset': (
        'hasSkill215 = 0;\n'
        '        for (unit = *(u8 **)(D_0076449C + (u16)group * 8 + 0x178);',
        'hasSkill215 = 0;\n'
        '        for (unit = NULL;'),
    'wrong_frame_boundary': ('if (animationFrames > 8)', 'if (animationFrames > 9)'),
    'missed_encounter_id': ('case 0x20b:', 'case 0x20c:'),
    'missed_normal_mode': ('            case 1:\n              goto normal_opening;',
                           '            case 3:\n              goto normal_opening;'),
}
TARGET_NEGATIVE_CONTROLS = ('broken_precondition', *TARGET_MUTATIONS)


def fixture(mutation=None):
    body = target_body()
    template = (ROOT / 'tests/battle_position_controller_fixture.c.in').read_text()
    if mutation == 'broken_precondition':
        old = ('return readiness != 0 || !(*(u32 *)(battle.bytes+0xc)&0x20000000) ||\n'
               '        *(u8 **)(battle.bytes+0x180) != 0;')
        assert old in template, old
        template = template.replace(old, 'return 1;')
    elif mutation is not None:
        assert mutation in TARGET_MUTATIONS, mutation
        old, new = TARGET_MUTATIONS[mutation]
        assert old in body, old
        body = body.replace(old, new)
    return RUNTIME_C + template.replace('%%TARGET%%', body) + ENTRY_C


class BattlePositionController(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as exc:
            raise unittest.SkipTest(str(exc))

    def execute(self, text, optimization):
        with tempfile.TemporaryDirectory() as tmp:
            p = Path(tmp)
            source = p / 'fixture.c'
            source.write_text(text)
            exe = self.runtime.compile(source, p / 'fixture', optimization, (ROOT / 'include',))
            return self.runtime.run(exe)

    def test_retail_routes_and_vectors(self):
        for optimization in ('-O0', '-O2'):
            with self.subTest(optimization=optimization):
                result = self.execute(fixture(), optimization)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertIn('battle-position scenarios passed', result.stdout)

    def test_negative_controls(self):
        for mutation in TARGET_NEGATIVE_CONTROLS:
            for optimization in ('-O0', '-O2'):
                with self.subTest(mutation=mutation, optimization=optimization):
                    result = self.execute(fixture(mutation), optimization)
                    self.assertNotEqual(result.returncode, 0, 'undetected: ' + mutation)


def equipment_fixture(mutation=None):
    text = (ROOT / 'src/Main/Battle/Data/datCalc.c').read_text()
    signature = text.index('s32 func_00232950(')
    start = text.rfind('#pragma push\n', 0, signature)
    assert start >= 0, 'missing equipment provider pragma scope'
    assert '#pragma opt_propagation off\n' in text[start:signature]
    end = text.index('\n}', signature) + 2
    closing_scope = re.match(r'\s*#pragma pop(?:\n|$)', text[end:])
    assert closing_scope, 'missing equipment provider pragma pop'
    body = text[start:end + closing_scope.end()]
    if mutation == 'second_record':
        body = body.replace('func_00106cd0(id, 1)', 'func_00106cd0(id, 0)')
    elif mutation == 'selector_width':
        body = body.replace('    u16 val;', '    u32 val;').replace('val = (u16)arg1;', 'val = arg1;')
    return RUNTIME_C + r'''
#include "btl_equipment_count_internal.h"
static u32 scenario, slotReads, assertions;
static u16 equipment[2], valueTable[2];
u8 D_00635938[1];
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__, scenario, #c); } while(0)
static void func_0046d730(void *file,s32 line) { CHECK(file==D_00635938 && line==0x263);++assertions; }
static s16 func_00106cd0(s16 character,s16 slot) { CHECK(character==3 && slot>=0 && slot<2);++slotReads;return equipment[slot]; }
static u16 func_001069d0(s16 id) { CHECK(id>=0 && id<2);return valueTable[id]; }
''' + body + r'''
int main(void) {
    u16 unit[3] = {0,3,0};
    s32 (*query)(u8 *,s32) = func_00232950;
    equipment[0]=0;equipment[1]=1;
    for(u32 blocked=0;blocked<2;++blocked)for(u32 bits=0;bits<4;++bits)for(u32 high=0;high<2;++high){
        ++scenario;unit[0]=blocked?4:0;valueTable[0]=(bits&1)?0x53:0x54;valueTable[1]=(bits&2)?0x53:0x54;slotReads=0;
        CHECK(query((u8 *)unit,0x53+(high?0x10000:0))==(blocked?0:(s32)((bits&1)+((bits>>1)&1))));CHECK(slotReads==(blocked?0:2));
    }
    CHECK(assertions==0);native32_text("equipment-count scenarios passed\n");return 0;
}
''' + ENTRY_C


class EquipmentCountProvider(BattlePositionController):
    def test_retail_routes_and_vectors(self):
        for optimization in ('-O0', '-O2'):
            result = self.execute(equipment_fixture(), optimization)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertIn('equipment-count scenarios passed', result.stdout)

    def test_negative_controls(self):
        for mutation in ('second_record', 'selector_width'):
            for optimization in ('-O0', '-O2'):
                result = self.execute(equipment_fixture(mutation), optimization)
                self.assertNotEqual(result.returncode, 0, mutation)


def sound_packet_fixture(mutation=None):
    source = (ROOT / 'src/Battle/btlSound.c').read_text()
    definitions = []
    for name in ('func_001f8280', 'func_001f82b0', 'func_001f8300', 'func_001f8330'):
        marker = source.index('// FUN_' + name[5:].upper())
        start = source.index('\n', marker) + 1
        end = source.index('\n}', start) + 2
        definitions.append(source[start:end])
    body = '\n'.join(definitions)
    if mutation == 'null_return':
        body = body.replace('return packet;', 'return 0;')
    elif mutation == 'wrong_kind':
        body = body.replace('func_00194470(0x909, 4)', 'func_00194470(0x90A, 4)')
    elif mutation == 'wrong_unit_payload':
        body = body.replace('*(struct BtlUnit**)packet->workData = unit;',
                            '*(struct BtlUnit**)packet->workData = 0;')
    elif mutation == 'wrong_update':
        body = body.replace('packet->updateFunc = func_001f8280;',
                            'packet->updateFunc = func_001f8300;')
    elif mutation is not None:
        raise AssertionError(mutation)
    start = source.index('typedef u32 (*BtlPacketFunc)')
    end = source.index('extern BtlPacket* func_00194470', start)
    layout = source[start:end]
    return RUNTIME_C + '#include "btl_packet_create_internal.h"\n' + layout + r'''
static u32 scenario, count;
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__, scenario, #c); } while(0)
static BtlPacket packets[2];
static struct BtlUnit *work[2];
static u32 kinds[2];
static u8 unitData[0xa00];
u32 func_001f8280(void *work);
u32 func_001f8300(void *work);
static BtlPacket *func_00194470(u32 type, u32 size) {
    CHECK(count < 2 && size == 4);
    packets[count].workData = &work[count];
    kinds[count] = type;
    return &packets[count++];
}
''' + body + r'''
int main(void) {
    struct BtlUnit *unit = (struct BtlUnit *)unitData;
    struct BtlPacket *(*create[2])(struct BtlUnit *) = {func_001f82b0, func_001f8330};
    for (scenario=0; scenario<2; ++scenario) {
        BtlPacket *packet = create[scenario](unit);
        CHECK(packet == &packets[scenario]);
        CHECK(kinds[scenario] == (scenario ? 0x90a : 0x909));
        CHECK(*(struct BtlUnit **)packet->workData == unit);
        CHECK(packet->updateFunc == (scenario ? func_001f8300 : func_001f8280));
        for (u32 flags=0; flags<4; ++flags) {
            *(u32 *)(unitData + 0x98) = flags;
            *(u16 *)(unitData + 0x9d8) = scenario ? 0xa5a5 : 0xa5b5;
            CHECK(packet->updateFunc(packet->workData) == 1);
            CHECK(*(u16 *)(unitData + 0x9d8) == ((flags & 2) ?
                (scenario ? 0xa5b5 : 0xa5a5) : (scenario ? 0xa5a5 : 0xa5b5)));
        }
    }
    native32_text("sound-packet scenarios passed\n");return 0;
}
''' + ENTRY_C


class SoundPacketProviders(BattlePositionController):
    def test_retail_routes_and_vectors(self):
        for optimization in ('-O0', '-O2'):
            result = self.execute(sound_packet_fixture(), optimization)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertIn('sound-packet scenarios passed', result.stdout)

    def test_negative_controls(self):
        for mutation in ('null_return', 'wrong_kind', 'wrong_unit_payload', 'wrong_update'):
            for optimization in ('-O0', '-O2'):
                result = self.execute(sound_packet_fixture(mutation), optimization)
                self.assertNotEqual(result.returncode, 0, mutation)


if __name__ == '__main__':
    unittest.main()
