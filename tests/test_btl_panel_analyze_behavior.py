"""Exercise the recovered analysis panel with real 32-bit pointer layouts.

Check phase endpoints, statistic argument order, the skill-grid shape, and
callback mutations that distinguish observed pointers from stale snapshots.
"""
from pathlib import Path
import re
import tempfile
import unittest

from native32_support import ENTRY_C, RUNTIME_C, Native32Unavailable, native32_runtime

ROOT = Path(__file__).resolve().parents[1]

PRELUDE = r'''
#include "type.h"
static unsigned scenario;
#define CHECK(c) do { if (!(c)) native32_failure(__LINE__, scenario, #c); } while (0)
typedef union { u32 align; u8 bytes[0xB00]; } Buffer;
typedef struct { s32 mode, tile; f32 x, y; } Tile;
typedef struct { u32 value; s32 kind; f32 x, y; } Statistic;
static Buffer work, panel, parent, unit, data, task, camera;
static u8 kinds[0x180], replacementKinds[0x180], names[0x100];
u8 *iGpffffb3c4 = kinds;
u8 *iGpffffb444 = names;
u16 D_00628FB8[7];
u8 D_00628F80[1];
char iGpffffa59c;
f32 fGpffff84a4 = 1.57079632679489661923f;
f32 D_008872F8[1];
static u16 skills[8];
static u16 hp, sp;
static u32 skillCount;
static Tile tiles[96];
static Statistic statistics[2];
static u32 tileCount, statisticCount, affinityCount, textCount, resetCount;
static u32 beginCount, endCount, vertexCount, mutation, kindSeen, widthKind;
static u32 affinitySeen[7], taskReads, vertexState;
static f32 lastScale, lastFade, depthSeen[3], vertexX[3], vertexY[3];
static f32 backgroundX, backgroundY, backgroundHeight, lastCos, lastSin;
static u32 cosCalls, sinCalls;
static inline f32 panelAdd2(f32 a, f32 b) { return a + b; }
static void put16(u8 *p, u16 v) { memcpy(p, &v, sizeof(v)); }
static void put32(u8 *p, u32 v) { memcpy(p, &v, sizeof(v)); }
static void putptr(u8 *p, void *v) { memcpy(p, &v, sizeof(v)); }
static void putf(u8 *p, f32 v) { memcpy(p, &v, sizeof(v)); }
f32 cosf(f32 value) { lastCos = value; ++cosCalls; return value == 0.0f ? 1.0f : 0.25f; }
f32 sinf(f32 value) { lastSin = value; ++sinCalls; return value == 0.0f ? 0.0f : 0.5f; }
void sprintf(void *out, const void *format, s32 value) {
    char *text = out;
    CHECK(format == &iGpffffa59c && value == 42);
    text[0] = '4'; text[1] = '2'; text[2] = 0;
}
s32 strlen(const char *text) { s32 n = 0; while (text[n]) ++n; return n; }
void func_0046d730(const void *file, s32 line) { (void)file; (void)line; CHECK(0); }
u32 func_00452560(u8 *handle) { CHECK(handle == task.bytes); ++taskReads; return (u32)work.bytes; }
void func_00201350(void) { ++resetCount; }
void func_002012d0(u8 *w, f32 x, f32 y) { CHECK(w == work.bytes && x == 0.0f && y == 0.0f); }
void func_00201720(u8 *w, f32 scale, f32 fade) { CHECK(w == work.bytes); lastScale = scale; lastFade = fade; }
void func_00201650(u8 *w, s32 mode, s32 tile, f32 x, f32 y, u8 r, u8 g, u8 b, u8 a) {
    CHECK(w == work.bytes && tileCount < 96 && a == 255);
    (void)r; (void)g; (void)b;
    tiles[tileCount++] = (Tile){mode, tile, x, y};
    if (mode == 14 && y == 110.0f) kindSeen = tile - 0x20;
}
f32 func_00201950(u8 *w, s32 mode, s32 tile) {
    CHECK(w == work.bytes && mode == 14);
    widthKind = tile - 0x20;
    if (mutation & 1) iGpffffb3c4 = replacementKinds;
    return 20.0f;
}
s32 func_00231e20(void *d) { CHECK(d == data.bytes); return 42; }
u16 func_00231f80(void *d) { CHECK(d == data.bytes); return hp; }
u16 func_00232290(void *d) { CHECK(d == data.bytes); return sp; }
void func_00218760(void *w, u32 value, f32 x, s32 kind, f32 y) {
    CHECK(w == work.bytes && statisticCount < 2);
    statistics[statisticCount++] = (Statistic){value, kind, x, y};
}
void func_00218af0(f32 x, f32 y, f32 height) { backgroundX = x; backgroundY = y; backgroundHeight = height; }
s32 func_001f0950(s32 enemy, s32 affinity) {
    CHECK(enemy == 2 && affinityCount < 7 && affinity == (s32)affinityCount + 1);
    if (mutation & 2) D_00628FB8[affinityCount] += 100;
    return 1;
}
void func_00218c60(u8 *w, s32 d, s64 affinity, f32 x, f32 y) {
    CHECK(w == work.bytes && (u8 *)(u32)d == data.bytes);
    (void)x; (void)y;
    CHECK(affinityCount < 7);
    affinitySeen[affinityCount++] = (u32)affinity;
}
u32 func_0023e130(u8 *d) { CHECK(d == data.bytes); return skillCount; }
u8 *func_0023e140(u8 *d) { CHECK(d == data.bytes); return (u8 *)skills; }
u8 *func_00243840(s32 skill) { CHECK(skill > 0 && skill < 256); return names + skill; }
int func_00275020(f32 x, f32 y, f32 z, s32 color, s32 mode, s32 align, const void *text, s32 style, s32 count) {
    (void)x; (void)y; (void)color;
    CHECK(z == 0.0f && mode == 0 && align == 1 && count == -1);
    CHECK((const u8 *)text >= names && (const u8 *)text < names + sizeof(names));
    if (style == 8) ++textCount;
    return 0;
}
u8 *func_00457120(void) {
    if (mutation & 4) D_008872F8[0] = 1234.0f;
    return camera.bytes;
}
void func_00364c50(void) { CHECK(vertexState == 1); ++beginCount; }
void func_00364c70(void) { CHECK(vertexCount == 3); ++endCount; }
static void set_vertex_state(u32 key, u32 value) { CHECK(key == 1 && value == 0); vertexState = 1; }
void (*D_00887300[1])(u32, u32) = {set_vertex_state};
'''

VERTEX_CALLBACK = r'''
static s32 draw_vertices(s32 primitive, void *vertices, s32 count) {
    PanelQuad *p = vertices;
    CHECK(primitive == 4 && count == 3 && beginCount == 1);
    for (s32 i = 0; i < count; ++i) {
        CHECK(p[i].scale == 512.0f);
        CHECK(p[i].color[0] == 0x42E00000 && p[i].color[1] == 0x42E00000);
        CHECK(p[i].color[2] == 0x42E00000 && p[i].color[3] == 0x437F0000);
        vertexX[i] = p[i].x; vertexY[i] = p[i].y; depthSeen[i] = p[i].z;
    }
    vertexCount = count;
    return 0;
}
s32 (*D_00887310[1])(s32, void *, s32) = {draw_vertices};
'''

CHECKS = r'''
static void initialize(u16 flags, u16 frame) {
    memset(&work, 0xA5, sizeof(work)); memset(&panel, 0xA5, sizeof(panel));
    memset(&parent, 0xA5, sizeof(parent)); memset(&unit, 0xA5, sizeof(unit));
    put32(work.bytes, 1); put16(panel.bytes, flags); put16(panel.bytes + 4, frame);
    putptr(panel.bytes + 8, parent.bytes); putptr(panel.bytes + 0x10, task.bytes);
    putptr(parent.bytes + 0x30, unit.bytes); putptr(unit.bytes + 0xA64, data.bytes);
    put16(unit.bytes + 0xA4, 2); putf(camera.bytes + 0x80, 512.0f);
    iGpffffb3c4 = kinds; kinds[2 * 0x3C + 2] = 3; replacementKinds[2 * 0x3C + 2] = 9;
    D_008872F8[0] = 999.0f;
    for (u32 i = 0; i < 7; ++i) D_00628FB8[i] = i + 1;
    for (u32 i = 0; i < 8; ++i) skills[i] = i == 3 ? 0 : i + 10;
    skillCount = 8; hp = 1000; sp = 65535;
    tileCount = statisticCount = affinityCount = textCount = resetCount = 0;
    beginCount = endCount = vertexCount = vertexState = mutation = taskReads = 0;
    kindSeen = widthKind = 0; lastScale = lastFade = -1.0f;
    cosCalls = sinCalls = 0; lastCos = lastSin = -1.0f;
    ++scenario;
}
static Tile *tile(s32 mode, s32 id, u32 ordinal) {
    for (u32 i = 0; i < tileCount; ++i) if (tiles[i].mode == mode && tiles[i].tile == id) {
        if (ordinal == 0) return &tiles[i];
        --ordinal;
    }
    return 0;
}
static void run_panel(void) { func_00219790(77, panel.bytes); CHECK(taskReads == 1); }
int main(void) {
    const u16 limits[] = {0, 998, 999, 1000, 65535};
    initialize(0, 13); run_panel(); CHECK(resetCount == 0 && tileCount == 0);
    initialize(1, 13); put32(work.bytes, 0); run_panel(); CHECK(resetCount == 0 && tileCount == 0);
    initialize(0x15, 0); run_panel(); CHECK(resetCount == 1 && tileCount == 0 && cosCalls == 1);
    initialize(0x15, 4); run_panel(); CHECK(statisticCount == 0 && textCount == 0 && affinityCount == 7);
    CHECK(cosCalls == 3 && lastCos == 0.0f && sinCalls == 0);
    initialize(0x15, 8); run_panel(); CHECK(statisticCount == 2 && textCount == 7 && sinCalls == 1 && lastSin == 0.0f);
    CHECK(statistics[0].x == -110.0f && statistics[0].y == 167.0f);
    CHECK(tile(12, 0x5A, 0)->x == -107.0f && tile(12, 0x5A, 0)->y == 284.0f);
    CHECK(tile(10, 0x42, 0) == 0);
    for (u32 flags = 0; flags < 8; ++flags) for (u32 value = 0; value < 5; ++value) {
        initialize((u16)(1 | (flags << 2)), 13);
        hp = limits[value]; sp = limits[4 - value]; mutation = 7;
        run_panel();
        CHECK(resetCount == 1 && statisticCount == 2 && affinityCount == 7);
        CHECK(widthKind == 3 && kindSeen == 9);
        CHECK(backgroundX == -10.0f && backgroundY == 215.0f && backgroundHeight == 51.0f);
        CHECK(lastScale == 1.0f && lastFade == 1.0f);
        for (u32 i = 0; i < 7; ++i) CHECK(affinitySeen[i] == i + 101);
        CHECK(statistics[0].x == 15.0f && statistics[1].x == 15.0f);
        CHECK(statistics[0].y == 167.0f && statistics[1].y == 187.0f);
        if (flags & 2) {
            CHECK(statistics[0].kind == 2 && statistics[1].kind == 3);
            CHECK(statistics[0].value == 0 && statistics[1].value == 0);
        } else {
            CHECK(statistics[0].kind == 0 && statistics[1].kind == 1);
            CHECK(statistics[0].value == (hp > 999 ? 999 : hp));
            CHECK(statistics[1].value == (sp > 999 ? 999 : sp));
        }
        if (flags & 1) {
            if (flags & 2) {
                CHECK(vertexCount == 3 && beginCount == 1 && endCount == 1 && textCount == 0);
                CHECK(vertexX[0] == 22.0f && vertexX[1] == 110.0f && vertexX[2] == 22.0f);
                CHECK(vertexY[0] == 287.0f && vertexY[1] == 287.0f && vertexY[2] == 338.0f);
                CHECK(depthSeen[0] == 999.0f && depthSeen[1] == 999.0f && depthSeen[2] == 999.0f);
                CHECK(D_008872F8[0] == 1234.0f);
            } else {
                CHECK(textCount == 7 && vertexCount == 0);
                for (u32 i = 0; i < 8; ++i) {
                    Tile *left = tile(12, 0x5A, i), *right = tile(12, 0x5B, i);
                    CHECK(left && right && right->x - left->x == 192.0f && left->y == right->y);
                    CHECK(left->x == (i < 4 ? 18.0f : 216.0f));
                    CHECK(left->y == 284.0f + (i % 4) * 25.0f);
                }
            }
        } else CHECK(vertexCount == 0 && textCount == 0);
        if (flags & 4) {
            Tile *heading = tile(10, 0x42, 0), *detail = tile(10, 0x4B, 0);
            CHECK(heading && detail && heading->x == 18.0f && detail->x == 28.0f);
            CHECK(heading->y == (flags & 1 ? 399.0f : 282.0f));
            CHECK(detail->y - heading->y == 2.0f);
        } else CHECK(tile(10, 0x42, 0) == 0);
    }
    initialize(0x15, 65535); skillCount = 0; run_panel(); CHECK(textCount == 0 && tile(12, 0x5A, 0) == 0);
    CHECK(statisticCount == 2 && cosCalls == 0 && sinCalls == 0);
    initialize(0x15, 13); skillCount = 0x10008; run_panel(); CHECK(textCount == 7 && tile(12, 0x5A, 7));
    initialize(0x11, 10); run_panel(); CHECK(sinCalls == 1 && lastFade == 1.0f);
    CHECK(tile(10, 0x42, 0)->y == 287.75f && tile(10, 0x4B, 0)->y == 288.75f);
    native32_text("panel_cases="); native32_number(scenario); native32_text("\n");
    return 0;
}
'''


def actual_body() -> tuple[str, str]:
    source = (ROOT / "src/Battle/btlPanelAnalyze.c").read_text(encoding="utf-8")
    vertex_end = source.index("} PanelQuad;") + len("} PanelQuad;")
    vertex_start = source.rindex("typedef struct", 0, vertex_end)
    start = source.index("static inline u8 btlPanelEnemyKind")
    body = source[start:]
    if "INCLUDE_ASM" in body or "FUN_00219790 NONMATCHING" in body:
        raise AssertionError("The panel must be recovered C")
    return source[vertex_start:vertex_end], body


class BtlPanelAnalyzeBehaviorTests(unittest.TestCase):
    def setUp(self):
        try:
            self.runtime = native32_runtime()
        except Native32Unavailable as error:
            self.skipTest(str(error))

    def execute(self, body: str, level: str):
        vertex, _ = actual_body()
        with tempfile.TemporaryDirectory(prefix="p4_panel_analyze_") as name:
            directory = Path(name)
            source = directory / "fixture.c"
            source.write_text(RUNTIME_C + PRELUDE + vertex + VERTEX_CALLBACK + body + CHECKS + ENTRY_C)
            executable = self.runtime.compile(source, directory / "fixture", level, (ROOT / "include",))
            return self.runtime.run(executable)

    def test_panel_phases_layout_and_mutating_callbacks(self):
        _, body = actual_body()
        for level in ("-O0", "-O2"):
            with self.subTest(optimization=level):
                result = self.execute(body, level)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
                self.assertEqual(result.stdout, "panel_cases=48\n")
                print(level, result.stdout.strip())

    def test_fixture_detects_argument_geometry_and_observation_regressions(self):
        _, body = actual_body()
        changes = (
            ("statistic-row", "func_00218760(work, hp, nameX, 0, 167.0f)", "func_00218760(work, hp, nameX, 1, 167.0f)"),
            ("grid-column", "(skillIndex >> 2) * 0xC6", "(skillIndex >> 2) * 0xC5"),
            ("kind-observation", "(s32)btlPanelEnemyKind(tableOffset) + 0x20,", "(s32)kind + 0x20,"),
        )
        for name, before, after in changes:
            self.assertEqual(body.count(before), 1, name)
            with self.subTest(mutation=name):
                result = self.execute(body.replace(before, after), "-O2")
                self.assertEqual(result.returncode, 1, result.stdout + result.stderr)
                self.assertIn("scenario", result.stdout)


if __name__ == "__main__":
    unittest.main()
