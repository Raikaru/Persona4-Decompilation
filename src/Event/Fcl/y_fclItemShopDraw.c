/* Original translation unit y_fclItemShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *(*D_008873F4[])(s32, s32, s32);

typedef struct {
    f32 x;
    f32 y;
} F2_0033;

extern void func_002b2970(F2_0033 *out, f32 x, f32 y);
extern s32 func_002e7a60(void);
extern s32 func_002b3170(s32 arg0);
extern void func_0033d3c0(void *, f32);
extern void func_0033d3e0(void *, F2_0033, F2_0033, u32, u32, s64);
extern void func_0033d4b0(void *, u8, u8, u8, s16, s64);
extern void func_0033d4e0(void *, s8, s16, s64, f32, f32);
extern f32 D_0064A1D8[];
extern f32 D_0064A1E0[];
extern f32 D_0064A1E8[];
extern f32 D_0064A0E8[];


extern f32 iGpffff8504;
extern u8 D_00793E80[];
extern f32 D_0064A090[];
extern f32 D_0064A380[];
extern u8 D_0064A3D8[];
extern u8 D_0064A3F0[];

void func_00332bb0(u8 *arg0);
extern void func_00332a80(void);
extern s32 func_0033cc40();
void func_0044ea90(const void *, u32);
u8 *func_00451fc0(void *, u8 *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
void func_002e29a0(void);
void func_00454bd0(void *);
void func_0046b0d0(void *);
s32 func_00106a90(s64);
void *func_0046d200(void *, s32, ...);
void func_002e24a0(s32, s32, s32, s32);
f32 func_0046b260(void *);
f32 func_0046b2f0(void *);
void func_0046d280(void *);
s32 func_0033d390(void *, s32);
void func_0033d320(void *, s32, s32);
f32 func_002b2aa0(s32, f32, f32, f32, f32);
s32 func_002b2a30(s32, s32, s32, s32);
s16 func_002b2cb0(s32, s32, s32, s32, s32);
s16 func_002b2d00(s32, s32, s32, s32, s32);
void func_0043f810(void *, s32, s32);
s32 func_002b89a0(void *);
void *func_00460990(void);
void func_00460ac0(void *, void *);
void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, void *);

/* measured: retail window 37392 bytes; no real C body was produced in this lane, so this function remains the bare assembly fallback. */
// FUN_00332BB0
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_00332bb0);

// FUN_0033BDC0
void func_0033bdc0(u8 *arg0) {
    u8 *work = *(u8 **)(arg0 + 0x38);

    func_002e29a0();
    if (*(s32 *)(work + 0x428) != 0) {
        func_00454bd0((void *)*(s32 *)(work + 0x428));
    }
    if (*(s32 *)(work + 0xC) != 0) {
        func_0046b0d0((void *)*(s32 *)(work + 0xC));
        *(s32 *)(work + 0xC) = 0;
    }
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

/* measured: object_size 324/window 336, normalized_diff 0 (retail tail is
   zero padding). MWCCPS2 needs opt_loop_invariants on to hoist the loop's
   `1` constant before the entry jump, matching retail's preheader materialisation. */
#pragma opt_loop_invariants on
// FUN_0033BE40
u8 *func_0033be40(u8 *arg0) {
    s32 i;
    s32 one;
    u8 *temp_17;
    s8 *temp_2;

    func_0044ea90(D_0064A380, 0x958);
    temp_2 = (s8 *)D_008873F4[0](1, 0x42C, 0x40000);
    temp_17 = func_00451fc0(arg0, D_0064A3D8, 0xF, 0, 0, func_00332bb0, func_0033bdc0, (u8 *)temp_2);
    *(s8 *)(temp_2 + 0) = 0;
    *(s32 *)(temp_2 + 0xC) = 0;
    *(f32 *)(temp_2 + 0x1E0) = (f32)0x28A;
    *(s32 *)(temp_2 + 0x1E4) = 0x41700000;
    *(s16 *)(temp_2 + 0x1EA) = 0;
    *(s16 *)(temp_2 + 0x1EC) = 0;
    *(s8 *)(temp_2 + 1) = 0;
    *(s32 *)(temp_2 + 0x2B0) = 0;
    *(s32 *)(temp_2 + 0x2A8) = 0;
    *(s32 *)(temp_2 + 0x2AC) = 0;
    *(s8 *)(temp_2 + 0x424) = 0;
    one = 1;
    i = 0;
    while ((s16)i < 0x24) {
        *(s8 *)(temp_2 + (s16)i + 0x2D8) = one;
        i = (s16)(i + 1);
    }
    if (func_002e71c0() == 1) {
        *(s8 *)(temp_2 + 0x424) = 1;
    }
    func_002e24a0(0x10000, 0, 2, 1);
    return temp_17;
}
/* measured: closes the opt_loop_invariants scope required by func_0033be40. */
#pragma opt_loop_invariants off

// FUN_0033BF90
void func_0033bf90(u8 *arg0) {
    s32 i;
    u8 *work;
    s32 item_index;
    s64 layer;
    f32 *coords;
    u8 *item;
    void *font;
    register u8 *table;
    f32 x;
    f32 y;
    F2_0033 pos0;
    F2_0033 pos1;
    F2_0033 pos2;
    F2_0033 pos3;
    F2_0033 pos4;
    F2_0033 pos5;
    F2_0033 pos6;
    F2_0033 pos7;
    F2_0033 pos8;
    F2_0033 pos9;
    F2_0033 pos10;
    F2_0033 pos11;

    work = *(u8 **)(arg0 + 0x38);
    i = 0;
    while ((s16)i < 4) {
        layer = (s64)(s16)((s16)i * 3);
        item_index = (s16)i + 3;
        coords = (f32 *)((u8 *)D_0064A090 + (item_index * 8));
        item = work + (s16)i * 4 + 0x1C;
        func_0033d4e0((void *)*(s32 *)item, 0, 10, layer, 1.0f, 0.5f);
        func_0033d4b0((void *)*(s32 *)item, 0xFF, 0, 0, 10, layer);
        func_0033d3d0((void *)*(s32 *)item, 0xAC);
        font = func_0046d200((void *)*(s32 *)(work + 0xC), item_index);
        func_002b2970(&pos0, coords[0], coords[1]);
        x = (func_0046b260(font) / 10.0f) * 1.5f + coords[0] + 0.0f;
        y = (func_0046b2f0(font) / 10.0f) * 1.5f + coords[1] + 0.0f;
        func_002b2970(&pos1, x, y);
        func_0033d3e0((void *)*(s32 *)item, pos0, pos1, 0, 10, layer);
        func_0046d280(font);
        i = (s16)(i + 1);
    }
    func_0033d320((void *)*(s32 *)(work + 0x14), 0, 0);
    func_0033d4b0((void *)*(s32 *)(work + 0x14), 0xFF, 0, 0, 10, 0);
    func_0033d3d0((void *)*(s32 *)(work + 0x14), 0xAC);
    table = (u8 *)D_0064A1D8;
    func_002b2970(&pos2, *(f32 *)(table + 0), *(f32 *)(table + 4));
    func_002b2970(&pos3, -180.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xB4), pos2, pos3, 0, 0x14, 0);
    table = (u8 *)D_0064A1E0;
    func_002b2970(&pos4, *(f32 *)(table + 0), *(f32 *)(table + 4));
    func_002b2970(&pos5, -200.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xB8), pos4, pos5, 0, 10, 0);
    table = (u8 *)D_0064A1E8;
    func_002b2970(&pos6, 153.0f, *(f32 *)(table + 4));
    func_002b2970(&pos7, -100.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0xBC), pos6, pos7, 0, 0x14, 0);
    func_002b2970(&pos8, 203.0f, *(f32 *)(table + 4));
    func_002b2970(&pos9, -50.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0x178), pos8, pos9, 0, 0x14, 0);
    table = (u8 *)D_0064A0E8;
    func_002b2970(&pos10, *(f32 *)(table + 0), *(f32 *)(table + 4));
    func_002b2970(&pos11, -200.0f, *(f32 *)(table + 4));
    func_0033d3e0((void *)*(s32 *)(work + 0x3C), pos10, pos11, 0, 0xF, 0);
    func_0033d4e0((void *)*(s32 *)(work + 0xB0), 0, 0xF, 0, 1.0f, 4.5f);
    i = 0;
    while ((s16)i < 3) {
        func_0033d4e0((void *)*(s32 *)(work + (s16)i * 4 + 0x17C), 0, 0xF, 0, 1.0f, 4.5f);
        i = (s16)(i + 1);
    }
    func_0033d3c0((void *)*(s32 *)(work + 0x110), 84.0f);
    func_0033d3c0((void *)*(s32 *)(work + 0x114), 84.0f);
    func_0033d3c0((void *)*(s32 *)(work + 0x60), 83.0f);
    *(f32 *)(work + 0x1D0) = 580.0f - (f32)func_002b3170(func_002e7a60()) * 21.0f;
    *(s32 *)(work + 0x1D4) = 0x41700000;
    *(f32 *)(work + 0x1D8) = (f32)0x28A;
    *(s32 *)(work + 0x1DC) = 0x41700000;
    *(s16 *)(work + 0x1EA) = 0;
    *(s8 *)(work + 0) = 0x11;
}

/* measured: retail window 1840 bytes; no real C body was produced in this lane, so this function remains the bare assembly fallback. */
// FUN_0033C490
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_0033c490);

// FUN_0033CBC0
u32 func_0033cbc0(void *arg0, s64 arg1) {
    u8 *work = *(u8 **)((u8 *)arg0 + 0x38);
    u32 d = (u32)((s32)(*(s8 *)(work + 9) * (s32)func_00106a90((s64)(s16)arg1)) * 0x14) / 100U;

    return (u32)func_00106a90((s64)(s16)(s32)arg1) - d;
}

/* triage: retail window 1216 bytes. The best reconstructed candidate measured
   normalized_diff 40 (40 differing words); retail's final mixed-argument calls
   at 0x0033D06C and 0x0033D10C materialise func_0025ecd0's 14 arguments in
   [3, 8, f12-f14, 1, 2, 4, 5, 6, 7, f15-f17], while b210 schedules
   [2, 3, 6, 7, 8, f12-f14, 1, 4, 5, f15-f17] for every tested spelling.
   Classification: argument-evaluation-order scheduling floor; the same
   constant-first residual appears in func_002b2a30. Fallback kept. */
// FUN_0033CC40
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_0033cc40);

// FUN_0033D100
void func_0033d100(u8 *arg0) {
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0033D130
/* Counter must be s32 with explicit (s16) casts at each use to reproduce
   retail's $a3 counter coloring and the per-use dsll32/dsra32 normalization.
   measured: without this pragma mwcc rematerializes the 0xFF / 0x3F800000
   constants inside the loop body (nd 50+); with it they hoist to the
   preheader exactly as retail does (nd 0). */
#pragma opt_loop_invariants on
u8 *func_0033d130(void *arg0, s32 arg1, s32 arg2) {
    s32 i;
    u8 *temp_17;
    u8 *work;
    f32 *item_data;
    void *r;

    func_0044ea90(D_0064A380, 0xACA);
    work = D_008873F4[0](1, 0x104, 0x40000);
    temp_17 = func_00451fc0(arg0, D_0064A3F0, 0xF, 0, 0, (void (*)(u8 *))func_0033cc40, func_0033d100, work);
    work[0] = 0;
    *(s16 *)(work + 0xF8) = arg1;
    *(s32 *)(work + 0xF4) = arg2;
    item_data = (f32 *)((u8 *)D_0064A090 + ((arg1 & 0xFFFF) * 8));
    for (i = 0; (s16)i < 3; i = (s16)(i + 1)) {
        *(f32 *)(work + (s16)i * 8 + 0x1C) = item_data[0];
        *(f32 *)(work + (s16)i * 8 + 0x20) = item_data[1];
        work[(s16)i + 0x60] = 0xFF;
        *(s32 *)(work + (s16)i * 4 + 0x8C) = 0x3F800000;
        *(s32 *)(work + (s16)i * 4 + 0x98) = 0x3F800000;
        *(s32 *)(work + (s16)i * 4 + 0xBC) = 0;
        work[(s16)i * 4 + 0x73] = 0xFF;
        work[(s16)i * 4 + 0x72] = 0xFF;
        work[(s16)i * 4 + 0x71] = 0xFF;
    }
    *(s32 *)(work + 8) = 0x42C80000;
    *(s32 *)(work + 0xFC) = 0x55;
    *(s16 *)(work + 4) = 0;
    r = func_0046d200((void *)*(s32 *)(work + 0xF4), 0, item_data, i);
    *(s16 *)(work + 0x100) = (s16)(s32)(func_0046b260(r) / 2.0f);
    *(s16 *)(work + 0x102) = (s16)(s32)(func_0046b2f0(r) / 2.0f);
    func_0046d280(r);
    return temp_17;
}
/* measured: see annotation above (func_0033d130). */
#pragma opt_loop_invariants off

