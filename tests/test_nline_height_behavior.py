"""Check recovered nLine height animation against an indexed geometry oracle.

The real function, its initialized output-reference helper, and the vertex
writer execute unchanged with real 32-bit pointers. The oracle models timing,
geometry and observable callback mutation independently of their source shape.
"""
from __future__ import annotations

from pathlib import Path
import re
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]

PRELUDE = r'''
#include "nline_vertex_internal.h"

typedef union { f32 alignment; u8 bytes[0x1800]; } State;
typedef union { f32 alignment; u8 bytes[0x100]; } Camera;
typedef struct { u32 tag; u32 words[10]; } Event;
typedef struct {
    State state;
    Camera camera;
    Event events[8];
    u32 event_count;
    int mutations;
    f32 ease_result;
} Context;
static Context *current;
static f32 D_008872F8[1], D_0088467C[1];
static f32 iGpffff8094 = 1.57079637f;
static f32 iGpffff8220 = 212.5f;
static u32 tests, vertices;
static inline f32 addF(f32 a, f32 b) { return a + b; }
static void put_float(u8 *p, f32 f) { memcpy(p, &f, sizeof(f)); }
static f32 get_float(const u8 *p) { f32 f; memcpy(&f, p, sizeof(f)); return f; }
static void put_s32(u8 *p, s32 value) { memcpy(p, &value, sizeof(value)); }
static s32 get_s32(const u8 *p) { s32 value; memcpy(&value, p, sizeof(value)); return value; }
static void put_s16(u8 *p, s16 value) { memcpy(p, &value, sizeof(value)); }
static s16 get_s16(const u8 *p) { s16 value; memcpy(&value, p, sizeof(value)); return value; }
static u32 bits(f32 value) { u32 result; memcpy(&result, &value, sizeof(result)); return result; }
static Event *event(u32 tag) {
    Event *e;
    if (current->event_count == 8) native32_failure(__LINE__, tests, "event capacity");
    e = &current->events[current->event_count++];
    memset(e, 0, sizeof(*e)); e->tag = tag; return e;
}
static f32 sinf(f32 input) {
    event(1)->words[0] = bits(input);
    if (current->mutations & 1) {
        current->state.bytes[0x994] ^= 0xA5;
        put_float(current->state.bytes + 0x99C, 36.25f);
        put_float(current->state.bytes + 0x9A0, -19.5f);
        put_float(current->state.bytes + 0x1688, 0.0f);
    }
    return current->ease_result;
}
static s32 func_00457120(void) {
    event(2);
    if (current->mutations & 2) {
        current->state.bytes[0x994] ^= 0x5A;
        put_float(current->state.bytes + 0x99C, 101.25f);
        put_float(current->state.bytes + 0x9A0, 37.5f);
        put_float(current->camera.bytes + 0x80, 256.0f);
        D_008872F8[0] = 701.5f; D_0088467C[0] = 7.25f;
    }
    return (s32)(u32)current->camera.bytes;
}
'''

WRITER = r'''
void func_0034f0d0(u8 *vertex, f32 x, f32 y, f32 z, f32 reciprocal,
                  u8 red, u8 green, u8 blue, u8 alpha) {
    s32 offset = vertex - current->state.bytes;
    Event *e = event(3);
    if (offset < 0 || offset + 0x40 > sizeof(current->state.bytes)) {
        native32_failure(__LINE__, tests, "vertex bounds");
    }
    e->words[0] = (u32)offset;
    e->words[1] = bits(x); e->words[2] = bits(y);
    e->words[3] = bits(z); e->words[4] = bits(reciprocal);
    e->words[5] = red; e->words[6] = green; e->words[7] = blue; e->words[8] = alpha;
    actual_vertex_writer(vertex, x, y, z, reciprocal, red, green, blue, alpha);
    ++vertices;
    if (current->mutations & 4) {
        current->state.bytes[0x994] ^= 0x55;
        put_float(current->state.bytes + 0x99C, (f32)offset);
        put_float(current->state.bytes + 0x9A0, -(f32)offset);
        put_float(current->camera.bytes + 0x80, 1024.0f);
        D_008872F8[0] += 4.5f; D_0088467C[0] += 1.25f;
    }
}
'''

ORACLE = r'''
static void reference_rectangle(u8 *state, s32 direction) {
    f32 amount, duration, elapsed, height, top, left, depth, reciprocal;
    u8 alpha;
    int corner;
    duration = get_float(state + 0x1688);
    amount = 1.0f;
    if (get_s32(state + 0x1690) == 0) {
        elapsed = (f32)get_s16(state + 0x1684);
        if (elapsed < duration) amount = sinf((iGpffff8094 * elapsed) / duration);
    }
    if (direction == 0) amount = 1.0f - amount;
    height = 171.0f * amount;
    alpha = (u8)((f32)state[0x994] * amount);
    put_s32(state + 0x990, 0);
    top = (iGpffff8220 - (171.0f * amount) / 2.0f) + get_float(state + 0x9A0);
    left = 77.0f + get_float(state + 0x99C);
    depth = D_008872F8[0] - D_0088467C[0];
    reciprocal = 1.0f / get_float(((u8 *)(u32)func_00457120()) + 0x80);
    for (corner = 0; corner != 4; ++corner) {
        f32 x = corner < 2 ? left : left + 580.0f;
        f32 y = corner == 1 || corner == 2 ? top + height : top;
        func_0034f0d0(state + 0x690 + corner * 0x40, x, y, depth, reciprocal,
                      255, 233, 44, alpha);
    }
}
static void initialize(Context *c, s16 elapsed, int mode, int alpha, int mutations) {
    static const f32 amounts[] = {0.0f, 0.125f, 0.375f, 0.875f, 1.0f};
    memset(c, 0, sizeof(*c));
    memset(c->state.bytes, 0xA5, sizeof(c->state.bytes));
    put_float(c->state.bytes + 0x1688, 64.0f);
    put_s16(c->state.bytes + 0x1684, elapsed);
    put_s32(c->state.bytes + 0x1690, mode);
    put_float(c->state.bytes + 0x99C, -31.25f);
    put_float(c->state.bytes + 0x9A0, 17.5f);
    c->state.bytes[0x994] = (u8)alpha;
    put_float(c->camera.bytes + 0x80, 512.0f);
    c->mutations = mutations;
    c->ease_result = amounts[alpha % 5];
}
int main(void) {
    const s16 phases[] = {-1, 0, 1, 63, 64, 90};
    int p, mode, alpha, direction, mutations;
    Context expected, got;
    f32 final_depth, final_plane;
    for (p=0; p<6; ++p) for (mode=0; mode<2; ++mode)
    for (alpha=0; alpha<256; ++alpha) for (direction=0; direction<2; ++direction)
    for (mutations=0; mutations<8; ++mutations) {
        initialize(&expected, phases[p], mode, alpha, mutations); got = expected;
        D_008872F8[0] = 1000.25f; D_0088467C[0] = 4.5f;
        current = &expected; reference_rectangle(expected.state.bytes, direction);
        final_depth = D_008872F8[0]; final_plane = D_0088467C[0];
        D_008872F8[0] = 1000.25f; D_0088467C[0] = 4.5f;
        current = &got; func_0034ddf0(got.state.bytes, direction);
        if (memcmp(&expected, &got, sizeof(got)) || bits(final_depth) != bits(D_008872F8[0]) ||
            bits(final_plane) != bits(D_0088467C[0])) {
            native32_failure(__LINE__, tests, "full state, callback trace and depth must agree");
        }
        ++tests;
    }
    native32_text("geometry_cases="); native32_number(tests);
    native32_text(" vertex_calls="); native32_number(vertices); native32_text("\n");
    return 0;
}
'''


def actual_body() -> tuple[str, str]:
    nline = (ROOT / "src/promoted/nLine.c").read_text(encoding="utf-8")
    start = nline.index("static inline void nLineHeight")
    end = nline.index("// FUN_0034E0B0", start)
    body = nline[start:end]
    if "INCLUDE_ASM" in body or "// FUN_0034DDF0 NONMATCHING" in body:
        raise AssertionError("Height animation must be recovered C")
    body = re.sub(r"^#pragma[^\n]*\n", "", body, flags=re.M)
    provider = (ROOT / "src/promoted/code1_0034.c").read_text(encoding="utf-8")
    marker = re.search(r"^// FUN_0034F0D0\b[^\n]*\n", provider, re.M)
    if marker is None:
        raise AssertionError("Missing vertex writer")
    following = re.search(r"^// FUN_", provider[marker.end():], re.M)
    end = len(provider) if following is None else marker.end() + following.start()
    writer = provider[marker.end():end].replace("func_0034f0d0", "actual_vertex_writer")
    writer = re.sub(r"^#pragma[^\n]*\n", "", writer, flags=re.M)
    return body, writer


class NLineHeightBehaviorTests(unittest.TestCase):
    def setUp(self) -> None:
        try:
            self.runtime = native32_runtime()
        except Native32Unavailable as error:
            self.skipTest(str(error))

    def execute(self, body: str, writer: str, level: str):
        with tempfile.TemporaryDirectory(prefix="p4_nline_height_") as directory:
            directory = Path(directory)
            source = directory / "fixture.c"
            source.write_text(RUNTIME_C + PRELUDE + writer + WRITER + body + ORACLE + ENTRY_C,
                              encoding="utf-8")
            executable = self.runtime.compile(source, directory / "fixture", level, (ROOT / "include",))
            return self.runtime.run(executable)

    def test_actual_height_animation_and_mutating_callbacks(self) -> None:
        body, writer = actual_body()
        for level in ("-O0", "-O2"):
            with self.subTest(optimization=level):
                result = self.execute(body, writer, level)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "geometry_cases=49152 vertex_calls=393216\n")
                print(level, result.stdout.strip())

    def test_fixture_rejects_geometry_direction_and_callback_regressions(self) -> None:
        body, writer = actual_body()
        mutations = (
            ("height", "*height = 171.0f * *amount;", "*height = 170.0f * *amount;"),
            ("direction", "if (arg1 == 0)", "if (arg1 != 0)"),
            ("alpha-lifetime", "temp_3 = (u8)temp_16;", "temp_3 = *(u8 *)(arg0 + 0x994);"),
        )
        for name, before, after in mutations:
            self.assertEqual(body.count(before), 1, name)
            mutated = body.replace(before, after)
            for level in ("-O0", "-O2"):
                with self.subTest(mutation=name, optimization=level):
                    result = self.execute(mutated, writer, level)
                    self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                    self.assertIn("full state, callback trace and depth must agree", result.stdout)


if __name__ == "__main__":
    unittest.main()
