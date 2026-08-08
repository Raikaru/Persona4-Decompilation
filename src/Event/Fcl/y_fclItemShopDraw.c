/* Original translation unit y_fclItemShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(void *ptr);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_0064A380[];
extern u8 D_0064A3D8[];
extern u8 D_0064A3F0[];
extern f32 D_0064A090[];
extern f32 iGpffff8504;
extern u8 D_00793E80[];

void func_00332bb0(u8 *arg0);
extern void func_00332a80(void);
extern void func_0033cc40();
void func_0044ea90(const void *, u32);
u8 *func_00451fc0(void *, u8 *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
void func_002e29a0(void);
void func_00454bd0(void *);
void func_0046b0d0(void *);
s32 func_00106a90(s64);
s32 func_002e71c0(s32, s32);
void func_002e24a0(s32, s32, s32, s32);
void *func_0046d200(void *, s32, void *, s32);
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
void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);

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

/* measured: candidate object_size 328/window 336 with normalized_diff 57; the loop body matched but call setup remained wrong, so the candidate was discarded and the bare assembly fallback restored. */
// FUN_0033BE40
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_0033be40);

/* measured: retail window 1280 bytes; no real C body was produced in this lane, so this function remains the bare assembly fallback. */
// FUN_0033BF90
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_0033bf90);

/* measured: retail window 1840 bytes; no real C body was produced in this lane, so this function remains the bare assembly fallback. */
// FUN_0033C490
INCLUDE_ASM("asm/nonmatchings/y_fclItemShopDraw", func_0033c490);

// FUN_0033CBC0
u32 func_0033cbc0(void *arg0, s64 arg1) {
    u8 *work = *(u8 **)((u8 *)arg0 + 0x38);
    u32 d = (u32)((s32)(*(s8 *)(work + 9) * (s32)func_00106a90((s64)(s16)arg1)) * 0x14) / 100U;

    return (u32)func_00106a90((s64)(s16)(s32)arg1) - d;
}

/* measured: retail evaluates func_0025ecd0's 14 args in the order [3, 8, f12-f14,
   1, 2, 4, 5, 6, 7, f15-f17] (nested call first, then arg3/arg8/first floats, then
   the rest positionally). mwcc b210 emits [2, 3, 6, 7, 8, f12-f14, 1, 4, 5, f15-f17]
   regardless of spelling: inline, hoisted locals (sibling y_fclShopDraw func_002e0100
   has the identical residual, nd 66), locals at function top, s32/u16 local types,
   and #pragma schedule on (which regresses to nd 267). nd 40 (40 of 1216 words).
   Argument-evaluation-order scheduling floor; the func_002b2a30 constant-first order
   is the same family. */
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

