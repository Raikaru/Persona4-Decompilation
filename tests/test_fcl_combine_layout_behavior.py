"""Check the combine-layout controller against a retail-derived schedule.

The actual body runs with real 32-bit pointers, signed inputs, provider-side
mutations, and undefined-behavior traps. These are behavior checks, not a claim
that the full renderer has been executed.
"""
from pathlib import Path
import re
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import measure_guarded
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

OWNER = ROOT / "src/Event/Fcl/y_fclCombine.c"

PRELUDE = r'''
#include "fcl_draw_types.h"
static unsigned scenario;
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__, scenario, #c); } while (0)
typedef union { u32 alignment; u8 bytes[0x180]; } Work;
typedef union { u32 alignment; u8 bytes[0x50]; } Task;
static Work work, expectedWork;
static Task task, expectedTask;
static u8 sprites[6][0x90], expectedSprites[6][0x90];
u8 D_00640760[8 * 12] __attribute__((aligned(4)));
u8 D_00640790[12] __attribute__((aligned(4)));
u8 D_0064079C[12] __attribute__((aligned(4)));
u8 D_006407A8[12] __attribute__((aligned(4)));
u8 D_006407C0[9 * 12] __attribute__((aligned(4)));
u8 D_006407F0[12] __attribute__((aligned(4)));
static const u32 randomValues[] = {0, 49, 50, 99, 149, 150, 299, 300, 0x80000000u, 0xFFFFFFFFu};
static u32 randomCursor, randomStart, randomExpected, callCount, spriteCalls, expectedCalls;
static u32 mutateTables, entering, hiding;
/* Columns are source-table row, visual slot, work row, entrance delay and side.
   They are transcribed independently from the retail loads and arguments,
   including layout 8's unusual final visual slot 4 / work row 4. */
typedef struct { u8 row, visual, workRow, delay, right; } Placement;
static const Placement layout6[] = {
    {1,0,0,0,0}, {2,1,1,4,0}, {3,2,2,8,0}, {6,8,5,2,1}, {5,7,4,6,1}, {4,6,3,10,1}
};
static const Placement layout8[] = {
    {0,0,0,0,0}, {1,1,1,4,0}, {2,2,2,8,0}, {3,3,3,12,0},
    {7,8,7,2,1}, {6,7,6,6,1}, {5,6,5,10,1}, {4,4,4,14,1}
};
static const Placement layout5[] = {
    {2,0,0,0,0}, {6,8,4,2,1}, {3,1,1,4,0}, {5,7,3,6,1}, {4,6,2,8,0}
};
static const Placement layout7[] = {
    {1,0,0,0,0}, {7,8,6,2,1}, {2,1,1,4,0}, {6,7,5,6,1},
    {3,2,2,8,0}, {5,6,4,10,1}, {4,3,3,12,0}
};
static const Placement layout9[] = {
    {0,0,0,0,0}, {8,8,8,2,1}, {1,1,1,4,0}, {7,7,7,6,1},
    {2,2,2,8,0}, {6,6,6,10,1}, {3,3,3,12,0}, {5,5,5,14,1}, {4,4,4,16,0}
};
static const Placement *placements;
static s32 currentLayout;
static s32 signed16(u32 value) { value &= 65535u; return value < 32768u ? (s32)value : (s32)value - 65536; }
static void put16(u8 *p, s32 value) { u16 narrowed = (u16)value; memcpy(p, &narrowed, 2); }
static u32 nextExpectedRandom(void) {
    u32 value = randomValues[(randomStart + randomExpected) % 10];
    ++randomExpected;
    return value;
}
u32 RpRandom(void) {
    CHECK(memcmp(&work, &expectedWork, sizeof(work)) == 0);
    CHECK(randomCursor < expectedCalls + 1);
    return randomValues[(randomStart + randomCursor++) % 10];
}
FclVec2 func_002b2970(f32 x, f32 y) { FclVec2 out = {x,y}; return out; }
u8 *func_002b6150(s16 sprite) {
    CHECK(hiding && callCount == expectedCalls && randomCursor == randomExpected);
    CHECK(spriteCalls < 12 && sprite == 0x216 + (s32)(spriteCalls / 2));
    CHECK(memcmp(sprites, expectedSprites, sizeof(sprites)) == 0);
    if ((spriteCalls & 1u) == 0) expectedSprites[spriteCalls / 2][0x73] = 0;
    ++spriteCalls;
    return sprites[sprite - 0x216];
}
'''

CALLBACK = r'''
static FclCombineLayoutSlot *slotFor(const Placement *placement) {
    if (currentLayout == 6 && callCount >= 3) {
        if (placement->row == 6) return (FclCombineLayoutSlot *)D_006407A8;
        if (placement->row == 5) return (FclCombineLayoutSlot *)D_0064079C;
        return (FclCombineLayoutSlot *)D_00640790;
    }
    if (currentLayout == 8 && callCount == 7) return (FclCombineLayoutSlot *)D_00640790;
    if (currentLayout & 1) {
        if (callCount + 1 == expectedCalls) return (FclCombineLayoutSlot *)D_006407F0;
        return (FclCombineLayoutSlot *)D_006407C0 + placement->row;
    }
    return (FclCombineLayoutSlot *)D_00640760 + placement->row;
}
void func_00317900(u8 *inputTask, FclVec2 start, FclVec2 end,
                   s8 visual, s16 delay, s16 depth, s16 order) {
    CHECK(inputTask == task.bytes && callCount < expectedCalls);
    CHECK(memcmp(&work, &expectedWork, sizeof(work)) == 0);
    const Placement *placement = placements + callCount;
    FclCombineLayoutSlot *slot = slotFor(placement);
    CHECK(visual == placement->visual);
    CHECK(delay == (entering ? placement->delay : placement->delay / 2));
    CHECK(depth == signed16(slot->col * 3 + 62));
    CHECK(order == signed16(slot->row + 87));
    if (entering) {
        CHECK(start.x == (placement->right ? 700.0f : -200.0f));
        CHECK(start.y == 100.0f + slot->y);
        CHECK(end.x == slot->x && end.y == slot->y);
    } else {
        s32 jitter = (s32)(nextExpectedRandom() % 300u) - 150;
        f32 targetX = placement->right ? 700.0f : -300.0f;
        if ((currentLayout & 1) && callCount + 1 == expectedCalls)
            targetX = nextExpectedRandom() % 100u >= 50u ? -300.0f : 700.0f;
        CHECK(start.x == slot->x && start.y == slot->y);
        CHECK(end.x == targetX && end.y == slot->y + jitter);
    }
    CHECK(randomCursor == randomExpected);
    /* Retail reloads the two halfwords after this call. Mutation distinguishes
       that observation from caching the scalar arguments before the call. */
    if (mutateTables) {
        slot->col = (s16)(slot->col ^ 0x4321);
        slot->row = (s16)(slot->row ^ 0x1765);
        work.bytes[0x10] ^= (u8)(callCount + 1);
        expectedWork.bytes[0x10] ^= (u8)(callCount + 1);
    }
    if (entering) {
        put16(expectedWork.bytes + 0xCA + placement->workRow * 10, slot->col * 3 + 62);
        put16(expectedWork.bytes + 0xCC + placement->workRow * 10, slot->row + 87);
    }
    ++callCount;
}
'''

CHECKS = r'''
static void seedTables(u32 seed) {
    static const s16 components[] = {-32768, 32767, -1, 0, 1, -20000, 20000, -87, 32710};
    for (u32 i = 0; i < 9; ++i) {
        FclCombineLayoutSlot value;
        value.x = (f32)(i * 19) - 81.25f;
        value.y = 27.5f - (f32)(i * 31);
        value.col = components[(i + seed) % 9];
        value.row = components[(8 - i + seed) % 9];
        memcpy(D_006407C0 + i * 12, &value, 12);
        if (i < 8) memcpy(D_00640760 + i * 12, &value, 12);
    }
    memcpy(D_00640790, D_00640760 + 4 * 12, 12);
    memcpy(D_0064079C, D_00640760 + 5 * 12, 12);
    memcpy(D_006407A8, D_00640760 + 6 * 12, 12);
    memcpy(D_006407F0, D_006407C0 + 4 * 12, 12);
}
static void runCase(u32 layout, s32 mode, u32 seed, u32 mutation) {
    currentLayout = layout < 128u ? (s32)layout : (s32)layout - 256;
    entering = (mode & 255) == 0;
    hiding = (mode & 255) == 1;
    mutateTables = mutation;
    placements = 0;
    expectedCalls = 0;
    switch (currentLayout) {
        case 5: placements = layout5; expectedCalls = 5; break;
        case 6: placements = layout6; expectedCalls = 6; break;
        case 7: placements = layout7; expectedCalls = 7; break;
        case 8: placements = layout8; expectedCalls = 8; break;
        case 9: placements = layout9; expectedCalls = 9; break;
    }
    memset(&work, 0xCC, sizeof(work));
    memset(&task, 0xA5, sizeof(task));
    memset(sprites, 0x3C, sizeof(sprites));
    work.bytes[0xB5] = (u8)layout;
    u8 *pointer = work.bytes;
    memcpy(task.bytes + 0x38, &pointer, 4);
    memcpy(&expectedWork, &work, sizeof(work));
    memcpy(&expectedTask, &task, sizeof(task));
    memcpy(expectedSprites, sprites, sizeof(sprites));
    seedTables(seed);
    randomStart = seed;
    randomCursor = randomExpected = callCount = spriteCalls = 0;
    func_002eb270(task.bytes, mode);
    CHECK(callCount == expectedCalls && randomCursor == randomExpected);
    CHECK(spriteCalls == (hiding ? 12u : 0u));
    CHECK(memcmp(&work, &expectedWork, sizeof(work)) == 0);
    CHECK(memcmp(&task, &expectedTask, sizeof(task)) == 0);
    CHECK(memcmp(sprites, expectedSprites, sizeof(sprites)) == 0);
    ++scenario;
}
int main(void) {
    CHECK(sizeof(FclCombineLayoutSlot) == 12);
    CHECK(__builtin_offsetof(FclCombineLayoutSlot, x) == 0);
    CHECK(__builtin_offsetof(FclCombineLayoutSlot, y) == 4);
    CHECK(__builtin_offsetof(FclCombineLayoutSlot, col) == 8);
    CHECK(__builtin_offsetof(FclCombineLayoutSlot, row) == 10);
    /* Exhaust the signed layout selector. Modes cover the low-byte contract,
       random exit, hiding only for one, and unrelated high bits. */
    static const s32 modes[] = {0,1,2,127,128,255,256,257,-256,-255,-1,0x12345600,0x12345601};
    for (u32 layout = 0; layout < 256; ++layout)
        for (u32 mode = 0; mode < sizeof(modes) / sizeof(modes[0]); ++mode)
            for (u32 seed = 0; seed < 10; ++seed)
                runCase(layout, modes[mode], seed, seed & 1);
    /* Exhaust every mode byte for the five supported layouts. */
    for (u32 layout = 5; layout <= 9; ++layout)
        for (u32 mode = 0; mode < 256; ++mode)
            for (u32 seed = 0; seed < 10; ++seed)
                runCase(layout, (s32)(mode | 0x76543200u), seed, seed & 1);
    native32_text("layout_cases="); native32_number(scenario); native32_text("\n");
    return 0;
}
'''


def actual_source():
    source = OWNER.read_text(encoding="utf-8")
    end = source.index("} FclCombineLayoutSlot;") + len("} FclCombineLayoutSlot;")
    start = source.rindex("typedef struct", 0, end)
    body = measure_guarded.extract_guarded_body(source, "FUN_002EB270", "func_002eb270")
    return source[start:end], body


class FclCombineLayoutBehavior(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def execute(self, body, optimization):
        layout_type, _ = actual_source()
        with tempfile.TemporaryDirectory(prefix="p4_fcl_layout_") as temporary:
            directory = Path(temporary)
            source = directory / "fixture.c"
            source.write_text(RUNTIME_C + PRELUDE + layout_type + CALLBACK + body + CHECKS + ENTRY_C)
            executable = self.runtime.compile(source, directory / "fixture", optimization, (ROOT / "include",))
            return self.runtime.run(executable)

    def test_layout_modes_positions_stores_random_and_hiding(self):
        _, body = actual_source()
        for optimization in ("-O0", "-O2"):
            with self.subTest(optimization=optimization):
                result = self.execute(body, optimization)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "layout_cases=46080\n")
                print(optimization, result.stdout.strip())

    def test_fixture_detects_independent_behavior_regressions(self):
        _, body = actual_source()
        mutations = (
            ("right-grid-row", "(7 - right8) * 10", "(6 - right8) * 10"),
            ("central-direction", "RpRandom() % 100 >= 50", "RpRandom() % 100 > 50"),
            ("unsigned-random", "RpRandom() % 300", "(s32)RpRandom() % 300"),
            ("hide-byte", "[0x73] = 0", "[0x72] = 0"),
            ("mode-width", "if ((s8)transition == 1)", "if (transition == 1)"),
            ("right-phase-copy", "rightTransition8 = leftTransition8", "rightTransition8 = 0"),
            ("left-phase-entry", "leftTransition8 = (s8)transition", "leftTransition8 = 0"),
        )
        for optimization in ("-O0", "-O2"):
            for name, old, new in mutations:
                with self.subTest(optimization=optimization, mutation=name):
                    self.assertIn(old, body)
                    result = self.execute(body.replace(old, new), optimization)
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertIn("scenario", result.stdout)

    def test_animation_provider_signature_is_consistent(self):
        declaration = re.search(r"extern void func_00317900\(([^;]+)\);", OWNER.read_text()).group(1)
        provider = (ROOT / "src/Event/Fcl/y_fclCombineDraw.c").read_text()
        definition = re.search(r"void func_00317900\(([^)]+)\)\s*\{", provider).group(1)
        def types(parameters):
            return [re.sub(r"(?<=[\s*])[A-Za-z_]\w*$", "", parameter.strip()).replace(" ", "")
                    for parameter in parameters.split(",")]
        self.assertEqual(types(declaration), types(definition))


if __name__ == "__main__":
    unittest.main()
