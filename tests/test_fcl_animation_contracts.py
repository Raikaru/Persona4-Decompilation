"""Check animation argument transport and color layout using the actual recovered C."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import probe_variants
from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

SOURCES = {
    "002B2A60": "src/promoted/code1_002b.c",
    "002B82D0": "src/promoted/y_draw.c",
    "002B8300": "src/promoted/y_draw.c",
    "002B8340": "src/promoted/y_draw.c",
    "002E04E0": "src/promoted/code1_002e.c",
    "002E0570": "src/promoted/code1_002e.c",
    "002E0660": "src/promoted/code1_002e.c",
    "002E0690": "src/promoted/code1_002e.c",
    "002E06D0": "src/promoted/code1_002e.c",
    "002E0940": "src/promoted/code1_002e.c",
    "0033D4B0": "src/promoted/code1_0033.c",
    "0033D4E0": "src/promoted/code1_0033.c",
    "0033D520": "src/promoted/code1_0033.c",
}

PREFIX = r'''
#include "fcl_color.h"
#include "fcl_animation_internal.h"
typedef union { u32 alignment; u8 bytes[0x140]; } AnimationWork;
typedef union { u32 alignment; u8 bytes[0x50]; } AnimationTask;
static AnimationWork work, expected;
static AnimationTask task, unchangedTask;
static unsigned scenario, colors, transports, queries;
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__, scenario, #c); } while (0)
static void put16(u8 *where, u16 value) { memcpy(where, &value, sizeof(value)); }
static void putFloat(u8 *where, f32 value) { memcpy(where, &value, sizeof(value)); }
static void prepare(u32 seed, u16 flags) {
    u8 *destination = work.bytes;
    for (u32 i = 0; i < sizeof(work.bytes); ++i) {
        seed = seed * 1664525u + 1013904223u;
        work.bytes[i] = (u8)(seed >> 24);
    }
    memset(&task, 0xC3, sizeof(task));
    memcpy(task.bytes + 0x38, &destination, sizeof(destination));
    put16(work.bytes + 4, flags);
    memcpy(&expected, &work, sizeof(work));
    memcpy(&unchangedTask, &task, sizeof(task));
}
static void check_buffers(void) {
    CHECK(memcmp(&work, &expected, sizeof(work)) == 0);
    CHECK(memcmp(&task, &unchangedTask, sizeof(task)) == 0);
    ++transports; ++scenario;
}
'''

ORACLE = r'''
/* These byte offsets and flag masks come from the retail setters. The complete
   work and task buffers are compared, including every unrelated field. */
static void opacity(u8 first, u8 second, u8 mode, u32 duration, u64 delay, u16 flags) {
    u8 *out = expected.bytes + 4;
    put16(out, flags | 4);
    put16(out + 0x58, (u16)duration);
    put16(out + 0x5A, 0);
    out[0x5C] = first; out[0x5D] = second; out[0x5E] = first;
    put16(out + 0x60, (u16)delay);
    out[0x62] = mode;
}
static void scale(f32 a, f32 b, f32 c, f32 d, u32 mode, u32 duration, u64 delay, u16 flags) {
    u8 *out = expected.bytes + 4;
    put16(out, flags | 0x10);
    put16(out + 0x82, (u16)duration);
    put16(out + 0x84, 0);
    putFloat(out + 0x88, a); putFloat(out + 0x8C, b); putFloat(out + 0x90, a);
    putFloat(out + 0x94, c); putFloat(out + 0x98, d); putFloat(out + 0x9C, c);
    put16(out + 0xA0, (u16)delay);
    out[0xA2] = (u8)mode;
}
static void rotation(f32 first, f32 second, u8 mode, u32 duration, u64 delay, u16 flags) {
    u8 *out = expected.bytes + 4;
    put16(out, flags | 8);
    putFloat(out + 0xB8, first); putFloat(out + 0xBC, second); putFloat(out + 0xC0, first);
    put16(out + 0xC4, 0);
    put16(out + 0xC6, (u16)duration);
    put16(out + 0xC8, (u16)delay);
    out[0xCA] = mode;
}
int main(void) {
    static const u32 words[] = {0, 1, 0x7FFF, 0x8000, 0xFFFF, 0x10000,
                                0x7FFFFFFF, 0x80000000u, 0xFFFFFFFFu};
    static const u64 delays[] = {0, 1, 0x7FFF, 0x8000, 0xFFFF, 0x10000,
                                 0x123456789ABCDEF0ULL, 0xFFFFFFFFFFFFFFFFULL};
    static const u32 modes[] = {0, 1, 0x80, 0xFF, 0x12345678u};
    static const f32 floats[][4] = {{0.0f, -0.0f, 1.0f, -1.0f},
                                    {1.5f, -7.25f, 100.125f, -200.75f},
                                    {65536.0f, 0.125f, -0.25f, 32767.0f}};
    for (u32 w = 0; w < sizeof(words) / sizeof(words[0]); ++w)
    for (u32 d = 0; d < sizeof(delays) / sizeof(delays[0]); ++d)
    for (u32 m = 0; m < sizeof(modes) / sizeof(modes[0]); ++m)
    for (u32 v = 0; v < sizeof(floats) / sizeof(floats[0]); ++v) {
        u16 flags = (u16)(0xA55Au ^ (w * 0x1111u) ^ (d * 0x123u));
        u8 first = (u8)(w * 53u + d), second = (u8)(255u - w * 29u - d);
        prepare(scenario, flags);
        opacity(first, second, (u8)modes[m], words[w], delays[d], flags);
        func_002e0660(task.bytes, first, second, (u8)modes[m], (s32)words[w], (s16)delays[d]);
        check_buffers();
        prepare(scenario, flags);
        opacity(first, second, (u8)modes[m], words[w], delays[d], flags);
        func_0033d4b0(task.bytes, first, second, (u8)modes[m], (s32)words[w], (s64)delays[d]);
        check_buffers();
        prepare(scenario, flags);
        scale(floats[v][0], floats[v][1], floats[v][0], floats[v][1], modes[m], words[w], delays[d], flags);
        func_002e0690(task.bytes, floats[v][0], floats[v][1], modes[m], words[w], (s64)delays[d]);
        check_buffers();
        prepare(scenario, flags);
        scale(floats[v][0], floats[v][1], floats[v][2], floats[v][3], modes[m], words[w], delays[d], flags);
        func_002e06d0(task.bytes, floats[v][0], floats[v][1], floats[v][2], floats[v][3], modes[m], words[w], (s64)delays[d]);
        check_buffers();
        prepare(scenario, flags);
        scale(floats[v][0], floats[v][1], floats[v][0], floats[v][1], modes[m], words[w], delays[d], flags);
        func_0033d4e0(task.bytes, floats[v][0], floats[v][1], modes[m], words[w], (s64)delays[d]);
        check_buffers();
        prepare(scenario, flags);
        rotation(floats[v][0], floats[v][1], (u8)modes[m], words[w], delays[d], flags);
        func_002e0940(task.bytes, floats[v][0], floats[v][1], (u8)modes[m], (s32)words[w], (s64)delays[d]);
        check_buffers();
        prepare(scenario, flags);
        rotation(floats[v][0], floats[v][1], (u8)modes[m], words[w], delays[d], flags);
        func_0033d520(task.bytes, floats[v][0], floats[v][1], (u8)modes[m], (s32)words[w], (s64)delays[d]);
        check_buffers();
    }
    /* Every value of every channel is exercised with asymmetric neighboring
       bytes; wider helper inputs must be reduced to their low byte. */
    for (u32 channel = 0; channel < 4; ++channel)
    for (u32 value = 0; value < 256; ++value) {
        u8 expectedColor[4] = {17, 109, 203, 255};
        u8 guarded[12], expectedGuarded[12];
        FclDrawColor actual;
        s32 input[4] = {0x12340011, -147, -53, -1};
        input[channel] = (s32)(0xABCD0000u | value);
        expectedColor[channel] = (u8)value;
        actual = func_002b2a60((u8)input[0], (u8)input[1], (u8)input[2], (u8)input[3]);
        CHECK(memcmp(&actual, expectedColor, 4) == 0);
        fclConstructColor(&actual, input[0], input[1], input[2], input[3]);
        CHECK(memcmp(&actual, expectedColor, 4) == 0);
        memset(guarded, 0x5A, sizeof(guarded));
        memcpy(expectedGuarded, guarded, sizeof(guarded));
        memcpy(expectedGuarded + 3, expectedColor, 4);
        fclWriteColorBytes(guarded + 3, input[0], input[1], input[2], input[3]);
        CHECK(memcmp(guarded, expectedGuarded, sizeof(guarded)) == 0);
        ++colors; ++scenario;
    }
    for (u32 flags = 0; flags < 0x10000; flags += 257) {
        prepare(flags, (u16)flags);
        CHECK(func_002e04e0(task.bytes) == work.bytes);
        for (s32 bit = 0; bit < 16; ++bit) {
            CHECK(func_002e0570(task.bytes, bit) == (s8)((flags >> bit) & 1));
            ++queries; ++scenario;
        }
        CHECK(memcmp(&work, &expected, sizeof(work)) == 0);
        CHECK(memcmp(&task, &unchangedTask, sizeof(task)) == 0);
    }
    native32_text("animation transports: "); native32_number(transports);
    native32_text(", color cases: "); native32_number(colors);
    native32_text(", flag queries: "); native32_number(queries); native32_text("\n");
    return 0;
}
'''


def fixture_source(overrides=None):
    overrides = overrides or {}
    bodies = []
    for address, relative in SOURCES.items():
        source = Path(overrides.get(relative, ROOT / relative)).read_text(encoding="utf-8")
        start, end = probe_variants.region_for(source, "FUN_" + address, "func_" + address.lower())
        bodies.append(source[start:end])
    return "\n".join((RUNTIME_C, PREFIX, *bodies, ORACLE, ENTRY_C))


class FclAnimationContracts(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        try:
            cls.runtime = native32_runtime()
        except Native32Unavailable as error:
            raise unittest.SkipTest(str(error)) from error

    def check_optimization(self, optimization):
        with tempfile.TemporaryDirectory(prefix="p4_fcl_animation_") as directory:
            directory = Path(directory)
            source = directory / "fixture.c"
            source.write_text(fixture_source(), encoding="utf-8")
            executable = self.runtime.compile(source, directory / "fixture", optimization, (ROOT / "include",))
            result = self.runtime.run(executable)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertEqual(result.stdout, "animation transports: 7560, color cases: 1024, flag queries: 4096\n")

    def test_animation_and_color_unoptimized(self):
        self.check_optimization("-O0")

    def test_animation_and_color_optimized(self):
        self.check_optimization("-O2")


if __name__ == "__main__":
    unittest.main()
