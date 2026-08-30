/* Consolidated Persona 4 source units. */
/* Original translation unit cmpSkill.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    Vec3f v;
} StSkill;

s16 func_0010b510(void);
u16 func_0010b6f0(void);
s32 func_0010ace0(s16);
void func_0010b3b0(s16);
s32 func_00113520(s32, s32, s32, void *);
s32 func_0010a900(u16);
u16 *func_001094d0(s32);
void func_0010fa80(s32, s32, u16, s32, s32 *, s32, s32);
void func_001437b0(void *, s32, s32);
void func_0046d280(void *);
s32 func_0034c210(void);
s32 func_003b7060(void);
s16 func_0023d8e0(void *, s32);
void func_0034f1e0(void);
void func_0034c270(Vec2f, u8, f32);
void func_0034f320(void *, u8, u8, u8, s32, s32, s32, s32, f32, f32, f32, f32, f32);
void func_0034f2e0(void *, u8, u8, u8, s32, f32, f32);
void func_0034f9d0(Vec2f, u8, s16, void *, f32);
void func_0013b370(void *, Vec2f, u32);
void func_0013b420(void *, Vec2f, s32, void *);
void func_00113730(void *);
void func_00113790(Vec2f, u8, void *, s32, f32);
void func_0013ad40(void *, s32, s32);
extern u8 D_00762DC0[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E4[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F4[];
void *func_0046a770(char *);
s32 func_0046d200(void *, u8);
s16 func_00353b50(void *);
void func_0046d730(char *, s32);
void func_0043f9c8(void *, s32, s32);
s32 func_0013a040(s16 *, s32, s16);
void func_0013a060(void *);
void func_0013a4a0(void *);
void func_00138bf0(void *);
s32 func_0013a530(u8 *, s32);
void func_00138490(void *);
extern char D_005ED9C0[];
extern char D_005E57F0[];
extern char D_005E5830[];
extern char D_005E5850[];
extern u8 D_005ED750[];
extern u8 D_005EB5D0[];
extern u8 D_005EBA00[];
extern u8 D_005EBE30[];
extern u8 D_005EC260[];
extern u8 D_005EC690[];
extern u8 D_005ECAC0[];
extern u8 D_005ECEF0[];
extern u8 D_005ED320[];
extern u8 D_005ED790[];
extern f32 DAT_00761640;

/* measured: the signed 16-bit bitfield keeps retail's dsll32/dsra32
   narrowing while the s32 loop carriers reproduce its saved-register
   allocation. The ordered asset-id loads and chained third-asset assignment,
   with the two measured optimization settings below, close all 1248 bytes. */
// FUN_00137FB0
/* measured: opt_propagation off preserves the retail constant and argument-load schedule. */
#pragma opt_propagation off
/* measured: opt_loop_invariants on hoists the table and conversion constants like retail. */
#pragma opt_loop_invariants on
void func_00137fb0(u8 *arg0)
{
    s16 i;
    s16 j;
    s16 k;
    s32 m;
    s32 m_index;
    u8 *src;
    u8 *dst;
    u8 asset_id;
    f32 value;
    void *asset0;
    void *asset1;
    void *asset2;
    s32 *slot;
    s32 n;
    struct {
        s32 half : 16;
    } narrow;

    func_0043f9c8(arg0, 0, 0x1338);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *arg0 = 0xFF;
    *(s32 *)(arg0 + 0x18) = -1;

    for (i = 0; i < 4; i++) {
        *(s16 *)(arg0 + i * 2 + 0x5C) = 0;
    }

    for (j = 0; j < 0x26; j++) {
        src = D_005EBA00 + j * 0x1C;
        dst = arg0 + j * 0x30;
        *(f32 *)(dst + 0x594) = *(f32 *)(src + 0);
        *(f32 *)(dst + 0x598) = *(f32 *)(src + 4);
        *(u8 *)(dst + 0x59E) = *(u8 *)(src + 0x10);
        value = *(f32 *)(src + 8);
        *(u16 *)(dst + 0x5A4) = (u16)value;
        value = *(f32 *)(src + 0xC);
        *(u16 *)(dst + 0x5AA) = (u16)value;
    }

    for (k = 0; k < 0x1C; k++) {
        dst = arg0 + k * 0x30;
        *(s32 *)(dst + 0xCB4) = 0;
        *(s32 *)(dst + 0xCB8) = 0;
        *(u8 *)(dst + 0xCBE) = 0;
        *(s32 *)(dst + 0xCCC) = 0;
        *(s32 *)(dst + 0xCD0) = 8;
        if (k % 0xE < 6) {
            *(s16 *)(dst + 0xCC0) = 0x64;
            *(s16 *)(dst + 0xCC2) = 0x64;
            *(s16 *)(dst + 0xCC6) = 0x64;
            *(s16 *)(dst + 0xCC8) = 0x64;
            *(u8 *)(dst + 0xCBC) = 0;
            *(u8 *)(dst + 0xCBD) = 0xFF;
        } else {
            *(s16 *)(dst + 0xCC0) = 0x64;
            *(s16 *)(dst + 0xCC2) = 0xB4;
            *(s16 *)(dst + 0xCC6) = 0x64;
            *(s16 *)(dst + 0xCC8) = 0xB4;
            *(u8 *)(dst + 0xCBC) = 0;
            *(u8 *)(dst + 0xCBD) = 0x7F;
        }
        *(s16 *)(arg0 + k * 2 + 0x24) = (k * 3) % 8;
    }

    m = 0;
    goto loop4_test;
loop4_body:
    narrow.half = m;
    m_index = narrow.half;
    dst = arg0 + m_index * 0x30;
    *(s32 *)(dst + 0x11F4) = 0;
    *(s32 *)(dst + 0x11E4) = 0;
    *(s32 *)(dst + 0x11F0) = 0;
    *(s32 *)(dst + 0x11E8) = 0;
    *(u8 *)(dst + 0x11FD) = 0;
    *(u8 *)(dst + 0x11FC) = 0;
    *(s32 *)(dst + 0x120C) = 0;
    *(s32 *)(dst + 0x1210) = 3;
    m = (s16)(m + 1);
loop4_test:
    if ((s16)m < 2) {
        goto loop4_body;
    }

    *(s16 *)(arg0 + 0xFC) = func_00353b50(arg0 + 0xF4);
    *(s16 *)(arg0 + 0x580) = 0;

    asset0 = func_0046a770(D_005E5830);
    if (asset0 == 0) {
        func_0046d730(D_005ED9C0, 0x25F);
    }
    asset1 = func_0046a770(D_005E5850);
    if (asset1 == 0) {
        func_0046d730(D_005ED9C0, 0x261);
    }
    *(void **)(arg0 + 0x1334) = asset2 = func_0046a770(D_005E57F0);
    if (asset2 == 0) {
        func_0046d730(D_005ED9C0, 0x263);
    }

    n = 0;
    goto resolve_test;
resolve_body:
    if (narrow.half < 0x1B) {
        narrow.half = n;
        slot = (s32 *)(arg0 + narrow.half * 4 + 0x1244);
        asset_id = D_005ED750[narrow.half];
        *slot = func_0046d200(asset0, asset_id);
    } else if (narrow.half < 0x3A) {
        narrow.half = n;
        slot = (s32 *)(arg0 + narrow.half * 4 + 0x1244);
        asset_id = D_005ED750[narrow.half];
        *slot = func_0046d200(asset1, asset_id);
    } else {
        narrow.half = n;
        slot = (s32 *)(arg0 + narrow.half * 4 + 0x1244);
        asset_id = D_005ED750[narrow.half];
        *slot = func_0046d200(asset2, asset_id);
    }
    if (*slot == 0) {
        func_0046d730(D_005ED9C0, 0x270);
    }
    narrow.half = n + 1;
    n = narrow.half;
resolve_test:
    narrow.half = n;
    if (narrow.half < 0x3C) {
        goto resolve_body;
    }

    func_0013a530(arg0, 0);
    func_00138490(arg0);
}
/* measured: restore propagation after matching func_00137fb0. */
#pragma opt_propagation on
/* measured: restore loop-invariant optimization after matching func_00137fb0. */
#pragma opt_loop_invariants off

/* measured: retail keeps var30 in $fp, var19 in $s3, temp20 in $s4 and uses
   a 0x100 frame with 10 saved registers ($fp/$s7..$s0) across the nested
   sort loops; mwcc b210 allocates a 0xD0 frame and different $s6/$s4/$s7
   registers (nd 309). The m2c draft's s128/s64 stack values (sq 0xB0/0xA0/
   0xC0) and the ld/sd swap collapse to different register coloring. Tried
   the m2c body converted to C89 — frame/register allocation floor. */
// FUN_00138490
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00138490);

// FUN_00138AD0
s32 func_00138ad0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00138B20
s32 func_00138b20(u8 *arg0)
{
    s32 i;
    s32 result = 1;
    u8 *p;
    s32 v;

    v = *(s16 *)(arg0 + 0x20);
    if (v < 0x64) {
        *(s16 *)(arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 0x26; i++) {
        p = arg0 + i * 0x30;
        v = *(s16 *)(arg0 + 0x20);
        func_001437b0(p + 0x584, v, 0);
        if (*(u8 *)(p + 0x59E) != 0) {
            result = 0;
        }
    }
    func_0013a060(arg0);
    func_0013a4a0(arg0);
    func_00138bf0(arg0);
    return result;
}
/* measured: retail uses VU0/COP2 FMAC (adda.s/madd.s) and raw .word COP2
   opcodes in the skill-render loops; m2c emits M2C_ERROR for these. VU0/COP2
   — not matchable in plain C, standard skip. */
// FUN_00138BF0
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00138bf0);

// FUN_0013A040
s32 func_0013a040(s16 *arg0, s32 arg1, s16 arg2)
{
    arg0[arg1 + 0x54] = arg0[arg1 + 0x2E];
    arg0[arg1 + 0x2E] = arg2;
    return 1;
}

/* measured: delayed s16 narrowing fixes the loop-counter live ranges, named
   float temporaries preserve the retail load schedule, and the two settings
   below close the full 1076-byte object (normalized_diff 0). */
// FUN_0013A060
/* measured: opt_common_subs off preserves the retail per-iteration address formation. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves the retail scalar and FP operand order. */
#pragma opt_propagation off
void func_0013a060(void *arg0)
{
    s32 i;
    s32 idx;
    s16 *counter;
    u8 *row;
    s32 *statep;
    s32 state;
    s32 count;
    s32 hundred;
    s32 hundred_eighty;
    u8 *flagp;
    u8 *p;
    f32 *x;
    f32 *y;
    f32 *table;
    f32 value;
    f32 divisor;
    f32 scale;
    f32 half;
    f32 temp;
    u32 random;

    for (i = 0; i < 0x1C; i++) {
        idx = i * 2;
        counter = (s16 *)((u8 *)arg0 + idx + 0x24);
        count = *counter + 1;
        *counter = count;
        row = (u8 *)arg0 + (idx + i) * 0x10;
        statep = (s32 *)(row + 0xCD0);
        state = *statep;
        count = (s16)count;
        if (state < count) {
            if (i % 0xE < 6) {
                if (state == 0xA) {
                    *(s16 *)(row + 0xCC8) =
                        *(s16 *)(row + 0xCC2) = 0x64;
                    *(s32 *)(row + 0xCA4) = 0;
                    *(s32 *)(row + 0xCA8) = 0;
                    *(s32 *)(row + 0xCAC) = 0;
                    *(s32 *)(row + 0xCB0) = 0;
                    *statep = 6;
                }
                flagp = row + 0xCBE;
                if (*flagp != 0) {
                    p = (u8 *)arg0 + i * 0x30;
                    *(f32 *)(p + 0xCA4) = *(f32 *)(p + 0xCAC);
                    *(f32 *)(p + 0xCA8) = *(f32 *)(p + 0xCB0);
                    *statep = 0x10;
                } else {
                    p = (u8 *)arg0 + i * 0x30;
                    x = (f32 *)(p + 0xCA4);
                    random = (u32)func_003b7060() % 0x28 - 0x14;
                    *x = (f32)random;
                    y = (f32 *)(p + 0xCA8);
                    random = (u32)func_003b7060() % 0x28 - 0x14;
                    *y = (f32)random;
                    *(f32 *)(p + 0xCAC) = *x;
                    *(f32 *)(p + 0xCB0) = *y;
                    *statep = 8;
                }
                p = (u8 *)arg0 + i * 0x30;
                *(u8 *)(p + 0xCBD) = *(u8 *)(p + 0xCBC);
                *(u8 *)(p + 0xCBC) = *flagp;
            } else {
                flagp = row + 0xCBE;
                if (*flagp != 0) {
                    if (count < state + 0xA) {
                        continue;
                    }
                    *(f32 *)(row + 0xCA4) = *(f32 *)(row + 0xCAC);
                    *(f32 *)(row + 0xCA8) = *(f32 *)(row + 0xCB0);
                    *(u16 *)(row + 0xCC0) = *(u16 *)(row + 0xCC2);
                    *(u16 *)(row + 0xCC6) = *(u16 *)(row + 0xCC8);
                    *statep = 4;
                } else {
                    x = (f32 *)(row + 0xCA4);
                    random = (u32)func_003b7060() % 0x28 - 0x14;
                    *x = (f32)random;
                    y = (f32 *)(row + 0xCA8);
                    random = (u32)func_003b7060() % 0x28 - 0x14;
                    *y = (f32)random;
                    table = (f32 *)(D_005ED790 + i * 0x14);
                    temp = table[2];
                    value =
                        (57.0f * temp) / (divisor = 4096.0f);
                    scale = DAT_00761640;
                    value =
                        (scale * value - value) / (half = 2.0f);
                    *(f32 *)(row + 0xCAC) = *x - value;
                    temp = table[3];
                    value = (60.0f * temp) / divisor;
                    value = (scale * value - value) / half;
                    *(f32 *)(row + 0xCB0) = *y - value;
                    hundred = 0x64;
                    *(s16 *)(row + 0xCC0) = hundred;
                    hundred_eighty = 0xB4;
                    *(s16 *)(row + 0xCC2) = hundred_eighty;
                    *(s16 *)(row + 0xCC6) = hundred;
                    *(s16 *)(row + 0xCC8) = hundred_eighty;
                    *statep = 8;
                }
                p = (u8 *)arg0 + i * 0x30;
                *(u8 *)(p + 0xCBD) = *(u8 *)(p + 0xCBC);
                *(u8 *)(p + 0xCBC) = *flagp;
            }
            *counter = 0;
        }
        func_001437b0(row + 0xCA4, *counter, 1);
    }
}
/* measured: restore propagation after matching func_0013a060. */
#pragma opt_propagation on
/* measured: restore common-subexpression optimization after matching func_0013a060. */
#pragma opt_common_subs on

/* measured: without #pragma opt_common_subs off, mwcc b210 CSEs the
   (u8*)arg0 + 0x22 address into a callee-saved pointer (nd 34); with it off
   each access keeps base+offset like retail (nd 3 = 3 padding words only).
   Same call-site trick as the cmpPersona sibling func_00135cf0. */
// FUN_0013A4A0
#pragma opt_common_subs off
void func_0013a4a0(void *arg0)
{
    s32 i;
    u8 *p;
    s32 v;

    v = *(s16 *)((u8 *)arg0 + 0x22);
    if (v < 0x64) {
        *(s16 *)((u8 *)arg0 + 0x22) = v + 1;
    }
    for (i = 0; i < 2; i++) {
        p = (u8 *)arg0 + i * 0x30 + 0x11E4;
        func_001437b0(p, *(s16 *)((u8 *)arg0 + 0x22), 0);
    }
}
/* measured: opt_common_subs off is required for the retail base+offset access order. */
#pragma opt_common_subs on

/* measured: setup/switch and data-copy loops match with common-subexpression
   elimination disabled; re-enabling it before the table loop reproduces the
   retail source/destination registers and hoisted float-conversion constants.
   Loop-invariant optimization is required for the conversion preheader. */
#pragma opt_common_subs off
#pragma opt_loop_invariants on
// FUN_0013A530
s32 func_0013a530(u8 *arg0, s32 arg1)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *p;
    u8 *src;
    f32 value;

    table = 0;
    if (*(s32 *)(arg0 + 0x18) == arg1) {
        return 0;
    }
    for (i = 0; i < 0x26; i++) {
        p = arg0 + i * 0x30;
        *(f32 *)(p + 0x584) = *(f32 *)(p + 0x594);
        *(f32 *)(p + 0x588) = *(f32 *)(p + 0x598);
        *(u16 *)(p + 0x5A0) = *(u16 *)(p + 0x5A4);
        *(u16 *)(p + 0x5A6) = *(u16 *)(p + 0x5AA);
        *(u8 *)(p + 0x59C) = *(u8 *)(p + 0x59E);
    }
    switch (arg1) {
    case 0:
        table = D_005EB5D0;
        *(s32 *)(arg0 + 0x1C) = 0x220B;
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 1:
        table = D_005EBA00;
        break;
    case 2:
        *(s32 *)(arg0 + 0x1C) = 0x220B;
        table = D_005EBE30;
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 3:
        *(s32 *)(arg0 + 0x1C) = 0x269B;
        table = D_005EC260;
        *(s16 *)(arg0 + 0x582) = 1;
        break;
    case 4:
        *(s32 *)(arg0 + 0x1C) = 0x241B;
        table = D_005EC690;
        *(s16 *)(arg0 + 0x582) = 1;
        break;
    case 5:
        table = D_005ECAC0;
        *(s32 *)(arg0 + 0x1C) = 0xC61;
        *(f32 *)(arg0 + 0x8B8) =
            34.0f * (f32)*(s16 *)(arg0 + 0x5E);
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 6:
        table = D_005ECAC0;
        *(s32 *)(arg0 + 0x1C) = 0x1861;
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 7:
        table = D_005ECEF0;
        *(s32 *)(arg0 + 0x1C) = 0xD61;
        *(f32 *)(arg0 + 0x8B8) =
            34.0f * (f32)*(s16 *)(arg0 + 0x5E);
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 8:
        table = D_005ECEF0;
        *(s32 *)(arg0 + 0x1C) = 0x1961;
        *(s16 *)(arg0 + 0x582) = 0;
        break;
    case 9:
        table = D_005ED320;
        *(s32 *)(arg0 + 0x1C) = 0x249B;
        *(s16 *)(arg0 + 0x582) = 2;
        break;
    case 10:
        table = D_005ED320;
        *(s32 *)(arg0 + 0x1C) = 0x249B;
        *(s16 *)(arg0 + 0x582) = 2;
        break;
    default:
        func_0046d730(D_005ED9C0, 0x5C9);
        break;
    }
    if (table != 0) {
        /* measured: re-enable common-subexpression optimization here to
           reproduce retail's table-loop register allocation. */
#pragma opt_common_subs on
        for (j = 0; j < 0x26; j++) {
            src = table + j * 0x1C;
            p = arg0 + j * 0x30;
            *(f32 *)(p + 0x58C) = *(f32 *)(src + 0);
            *(f32 *)(p + 0x590) = *(f32 *)(src + 4);
            *(u8 *)(p + 0x59D) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(p + 0x5A2) = (u16)value;
            value = *(f32 *)(src + 0xC);
            *(u16 *)(p + 0x5A8) = (u16)value;
            *(s32 *)(p + 0x5AC) = *(s32 *)(src + 0x14);
            *(s32 *)(p + 0x5B0) = *(s32 *)(src + 0x18);
        }
        *(s32 *)(arg0 + 0x18) = arg1;
        *(s16 *)(arg0 + 0x20) = 0;
    }
    return 1;
}
#pragma opt_loop_invariants off
/* measured: retail hoists the lui 0x41c8 (25.0f constant) into the loop
   preheader; mwcc b210 sinks the materialization into the if-branch unless
   #pragma opt_loop_invariants on is active. Tried s32/u32/f32 locals, register,
   ternary, chained-assign, while-loop spellings — all nd 30 without the pragma. */
// FUN_0013A8A0
#pragma opt_loop_invariants on
void func_0013a8a0(u8 *arg0)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *q = arg0 + i * 0x30;
        *(f32 *)(q + 0x5B4) = *(f32 *)(q + 0x5C4);
        *(f32 *)(q + 0x5B8) = *(f32 *)(q + 0x5C8);
        *(u8 *)(q + 0x5CC) = *(u8 *)(q + 0x5CE);
        *(f32 *)(q + 0x674) = *(f32 *)(q + 0x684);
        *(f32 *)(q + 0x678) = *(f32 *)(q + 0x688);
        *(u8 *)(q + 0x68C) = *(u8 *)(q + 0x68E);
        if (*(s16 *)(arg0 + 0x5C) == i) {
            *(s32 *)(q + 0x5BC) = 0x41C80000;
            *(s32 *)(q + 0x67C) = 0x41C80000;
        } else {
            *(s32 *)(q + 0x5BC) = 0;
            *(s32 *)(q + 0x67C) = 0;
        }
    }
    *(s16 *)(arg0 + 0x20) = 0;
}
/* measured: opt_loop_invariants on is required for the retail preheader constant hoist. */
#pragma opt_loop_invariants off
// FUN_0013A930
void func_0013a930(void *arg0)
{
    f32 f0;
    f32 f1;
    *(u32 *)((u8 *)arg0 + 0x11E4) = 0x437F0000;
    *(u32 *)((u8 *)arg0 + 0x11EC) = 0x437F0000;
    *(u32 *)((u8 *)arg0 + 0x11F4) = 0x437F0000;
    *(u8 *)((u8 *)arg0 + 0x11FC) = 0xFF;
    *(u8 *)((u8 *)arg0 + 0x11FE) = 0xFF;
    *(u8 *)((u8 *)arg0 + 0x11FD) = 0;
    *(u32 *)((u8 *)arg0 + 0x1220) = 0;
    if (*(s16 *)((u8 *)arg0 + 0x60) > *(s16 *)((u8 *)arg0 + 0xAC)) {
        f0 = 21.0f + *(f32 *)((u8 *)arg0 + 0x8F8);
        *(f32 *)((u8 *)arg0 + 0x11F8) = f0;
        *(f32 *)((u8 *)arg0 + 0x11E8) = f0;
        *(f32 *)((u8 *)arg0 + 0x11F0) = *(f32 *)((u8 *)arg0 + 0x11F8) - 10.0f;
        *(u32 *)((u8 *)arg0 + 0x1218) = 0xC1200000;
    } else {
        f1 = 21.0f + *(f32 *)((u8 *)arg0 + 0x9E8);
        f0 = 170.0f + f1;
        *(f32 *)((u8 *)arg0 + 0x11F8) = f0;
        *(f32 *)((u8 *)arg0 + 0x11E8) = f0;
        *(f32 *)((u8 *)arg0 + 0x11F0) = 10.0f + *(f32 *)((u8 *)arg0 + 0x11F8);
        *(u32 *)((u8 *)arg0 + 0x1218) = 0x41200000;
    }
    *(s16 *)((u8 *)arg0 + 0x22) = 0;
}

/* measured: same lui-hoist floor as func_0013a8a0 (constant 0x41C80000 into
   preheader); without #pragma opt_loop_invariants on mwcc b210 sinks the lui
   into the branch — identical nd 30 on every spelling tried. */
// FUN_0013AA00
#pragma opt_loop_invariants on
void func_0013aa00(u8 *arg0)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *q = arg0 + i * 0x30;
        *(f32 *)(q + 0xA04) = *(f32 *)(q + 0xA14);
        *(f32 *)(q + 0xA08) = *(f32 *)(q + 0xA18);
        *(u8 *)(q + 0xA1C) = *(u8 *)(q + 0xA1E);
        *(f32 *)(q + 0xAC4) = *(f32 *)(q + 0xAD4);
        *(f32 *)(q + 0xAC8) = *(f32 *)(q + 0xAD8);
        *(u8 *)(q + 0xADC) = *(u8 *)(q + 0xADE);
        if (*(s16 *)(arg0 + 0x62) == i) {
            *(s32 *)(q + 0xA0C) = 0x41C80000;
            *(s32 *)(q + 0xACC) = 0x41C80000;
        } else {
            *(s32 *)(q + 0xA0C) = 0;
            *(s32 *)(q + 0xACC) = 0;
        }
    }
    *(s16 *)(arg0 + 0x20) = 0;
}
/* measured: opt_loop_invariants on is required for the retail preheader constant hoist. */
#pragma opt_loop_invariants off

// FUN_0013AA90
void func_0013aa90(void *arg0)
{
    s32 i;
    for (i = 0; i < 6; i++) {
        if (!(func_003b7060() & 1)) {
            u8 *q = (u8 *)arg0 + i * 0x30;
            *(s16 *)(q + 0xCC2) = 0xFA;
            *(s16 *)(q + 0xCC8) = 0x190;
            *(u32 *)(q + 0xCA4) = 0xC1F00000;
            *(u32 *)(q + 0xCA8) = 0xC1F00000;
            *(u32 *)(q + 0xCAC) = 0xC1F00000;
            *(u32 *)(q + 0xCB0) = 0xC1F00000;
            *(u32 *)(q + 0xCD0) = 10;
            *(s16 *)((u8 *)arg0 + i * 2 + 0x24) = 0;
        }
    }
}

// FUN_0013AB30
void func_0013ab30(u8 *arg0)
{
    s32 i;
    s32 *slot;

    for (i = 0; i < 0x3C; i++) {
        slot = (s32 *)(arg0 + i * 4 + 0x1244);
        if (*slot != 0) {
            func_0046d280((void *)*slot);
            *slot = 0;
        }
    }
    *(s32 *)(arg0 + 0x1C) = 0;
}

// FUN_0013ABB0
s32 func_0013abb0(u8 *arg0)
{
    s32 result;
    s32 i;
    s32 threshold;

    /* i is zeroed before the threshold load, and threshold is held as s32:
       an s16 local makes mwcc re-sign-extend it on every iteration. */
    result = 1;
    i = 0;
    threshold = *(s16 *)(arg0 + 0x20);
    while (i < 0x26) {
        if (threshold < *(s32 *)(arg0 + i * 48 + 0x5B0)) {
            result = 0;
        }
        i++;
    }
    return result & func_0034c210();
}

/* measured: retail fills the switch dispatch `jr $v0` delay slot with the
   first case body (addiu $v0, 0x2b) and the table points at the following b;
   mwcc b210 leaves the delay slot as nop for every spelling tried (s32/s64
   switch value, direct-call vs local, return-in-case vs break+result,
   #pragma schedule on / optimization_level 3). Real defect is exactly 1 word:
   nd 2 (1 real + 1 padding) with the correct s32-arg0 + s32-second-param
   prototypes (func_0023d8e0's second param is s32 per its own m2c body). */
/* Case values decoded from jtbl_007469C0 with tools/jtbl.py: twenty dense
   entries mapping index+1 to 0x2B..0x32, with 9-19 sharing 0x33 and index 0
   returning -1; >= 0x14 hits the assert. The labels are declared in that
   object order because b210 lays case bodies out in declaration order.
   This function is also why func_0023d8e0's second parameter is s32 and not
   s16: retail passes arg0 with a plain `move $a1,$a0` and masks the COPY,
   where the s16 prototype forced a dsll32/dsra32 pair and shifted the whole
   body (nd 177). Widening it matched this function and regressed none of the
   ten already matching in this file. */
// FUN_0013AC30
s32 func_0013ac30(s32 arg0) {
    s32 v;

    if ((arg0 & 0xFFFF) >= 0x1B8) {
        return 0x35;
    }
    v = func_0023d8e0(NULL, arg0) + 1;
    switch ((u32)v) {
    case 1:
        return 0x2B;
    case 2:
        return 0x2C;
    case 3:
        return 0x2D;
    case 4:
        return 0x2E;
    case 5:
        return 0x2F;
    case 6:
        return 0x30;
    case 7:
        return 0x31;
    case 8:
        return 0x32;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
        return 0x33;
    case 0:
        return -1;
    }
    func_0046d730(D_005ED9C0, 0x6B2);
    return -1;
}

