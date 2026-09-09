/* Fresh panel composition recovery: func_0020fa70
 * Owner: src/promoted/code1_0020.c. Exact1156 executable bytes in1168-byte
 * retail window,19 call and5 float literal relocations independently resolved,
 * 12 zero alignment bytes. All1168 retail bytes equal.
 * 
 * Initial s32 palette/old sprite prototype:1148/1168 bytes,nd760.
 * Byte palette alone:1168/1168,nd357,extra promotion masks.
 * Byte RGB provider parameters:1156/1168,nd24.
 * All four color parameters u8:1156/1168,nd0.
 * The existing btlPanelAnalyze declaration already used four byte channels.
 * Canonical include/btl_panel_internal.h now replaces the contradictory int,
 * s64 and misordered declarations. A scoped opt_propagation-off opacity base
 * keeps func_00201650 at its original92 bytes and identical instructions.
 * Byte channel snapshots preserve func_0020e420's original412 bytes and masks.
 * The other144 old owner functions, including the color provider, retain
 * identical instruction bytes and relocations after the complete cutover.
 * 
 * The radial call uses canonical Vec2f plus packed32 colors, five floats,
 * u32 segments and mode from include/shd_misc_internal.h. Existing radial
 * callers func_0021bbb0 (604/608),func_00356170 (96/96),func_003561d0 (116/128)
 * remain exact. The latter takes its actual Vec2f position input; other callers
 * retain defined union views for raw position/color storage. No compatibility
 * aliases, invented inputs, fixed registers or artificial padding were added.
 * 
 * 336896 Wasm32 composition cases passed with nine actual provider bodies:
 * pointer-add, origin setter, render-state setup, sprite setup, byte-color
 * wrapper, rotation/crop setter, texture-scale setter, blend-state setter,
 * and scale setter. An independent model compares whole guarded fixtures,
 * queued44-byte sprite descriptors and ordered renderer/radial/child calls.
 * Radial and child renderers are opaque submission boundaries, not simulated
 * PS2 rendering. Mutations cover pre-palette flags, cached extent, late pulse
 * alpha, work origins/scales/UVs, child modifications and final resets.
 * 65536 cases cover all halfword flags;270336 cover all pulse bytes over33
 * bounded extents and32 mutation modes;1024 cover negative-zero early exits.
 * All floating conversion inputs are within provider bounds.
 * 131072 native radial-wrapper argument cases pass Clang address/undefined/
 * float-cast-overflow/float-divide-by-zero sanitizers with real wrapper bodies,
 * covering typed coordinates, arbitrary packed colors, alpha-gated modes,
 * full-width segment forwarding, and radius/angle transformation.
 * 
 * Full make all lint-errors passes:172 linked objects,both retail SHA1s equal,
 * 12720 scanned functions,7797 MATCH/4923 ASM overall,6167 MATCH/693 ASM first
 * party (89.9%),339 linted first-party files and zero findings.
 *
 */

#include "type.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
typedef struct { u8 c0, c1, c2, c3; } Color4;
extern void func_00201350(void);
extern void func_002012d0(u8 *, f32, f32);
extern void func_002019d0(u8 *, f32, f32);
extern void func_00201820(s32);
extern void func_00201720(u8 *, f32, f32);
extern void func_002016e0(u8 *, s16, s16, f32);

// FUN_0020FA70
void func_0020fa70(u8 *work, u8 *state)
{
    extern void func_0020f730(u8 *work, u8 *state, s32 color, s32 index);
    union { Color4 rgba; s32 bits; } ring, fill, saved, black, transparent;
    Vec2f position;
    u8 red;
    u8 green;
    u8 blue;
    s32 index;
    f32 extent;
    extent = *(f32 *)(state + 8);
    if (extent == 0.0f) return;
    func_00201350();
    if (*(s16 *)(state + 4) & 4) {
        red = 140; green = 170; blue = 255;
        ring.rgba.c0 = 102; ring.rgba.c1 = 130; ring.rgba.c2 = 255;
        fill.rgba.c0 = 0; fill.rgba.c1 = 25; fill.rgba.c2 = 255;
    } else {
        red = 255; green = 140; blue = 170;
        ring.rgba.c0 = 255; ring.rgba.c1 = 102; ring.rgba.c2 = 110;
        fill.rgba.c0 = 255; fill.rgba.c1 = 0; fill.rgba.c2 = 21;
    }
    ring.rgba.c3 = 51;
    fill.rgba.c3 = (u8)(255.0f * extent);
    func_002012d0(work, (f32)279, 229.0f);
    func_002019d0(work, 1.0f, 1.0f);
    saved.rgba = fill.rgba;
    position.x = (f32)279;
    position.y = 229.0f;
    transparent.rgba.c0 = black.rgba.c0 = 0;
    transparent.rgba.c1 = black.rgba.c1 = 0;
    transparent.rgba.c2 = black.rgba.c2 = 0;
    black.rgba.c3 = (u8)(76.0f * extent);
    transparent.rgba.c3 = 0;
    func_00365f00(position, 0.0f, black.bits, transparent.bits, 100.0f, 0.0f, 12, 1.066f, 1.0f, 0);
    transparent.rgba.c0 = saved.rgba.c0;
    transparent.rgba.c1 = saved.rgba.c1;
    transparent.rgba.c2 = saved.rgba.c2;
    transparent.rgba.c3 = 0;
    func_00201820(2);
    func_00365f00(position, 0.0f, fill.bits, transparent.bits, 125.0f, 0.0f, 12, 1.066f, 1.0f, 0);
    func_00201720(work, extent, 1.0f);
    func_002016e0(work, 0, 0, 90.0f);
    func_00201650(work, 10, 45, 20.0f, -57.0f * extent, red, green, blue, 255);
    if (state[0]) {
        func_00201720(work, 1.2f, 1.5f);
        func_00201650(work, 10, 45, 30.0f, -68.4f, red, green, blue, state[0]);
    }
    func_00201720(work, 1.0f, extent);
    func_002016e0(work, 0, 0, 0.0f);
    func_00201650(work, 10, 46, 12.0f, -5.0f * extent, red, green, blue, 255);
    func_00201720(work, 1.066f, extent);
    for (index = 1; index < 12; index++) func_0020f730(work, state, ring.bits, index);
    func_002016e0(work, 0, 0, 0.0f);
    func_00201720(work, 1.0f, 1.0f);
    func_002019d0(work, 1.0f, 1.0f);
}