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
s16 func_0023d8e0(void *, s16);
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
s32 func_0013a530(void *, s32);
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

/* measured: retail keeps arg0 in $s5 and hoists the D_005EBA00 base plus the
   0x4F000000/0x80000000 float-conversion constants into pre-loop registers;
   mwcc b210 rematerializes them per-iteration and runs the float->int guard
   as c.olt.s where retail has c.ole.s. Tried (s16)(s32) cast, explicit
   two-branch guard, srcbase pointer hoist, m2c declaration order, and
   #pragma opt_propagation off — all nd 277-281 with fully divergent $s0..$s5
   register allocation across all five loops. */
// FUN_00137FB0
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_00137fb0);

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

/* measured: the bltz int->float random conversion (srl/andi/or/cvt.s.w/
   add.s) and the overall control flow match; the remaining 258 words are
   retail's 10-saved-register allocation ($fp/$s7..$s0 holding the base,
   CA4/CA8/CD0/CBE and counter pointers live across the func_003b7060 calls)
   vs mwcc b210's own register coloring. Tried pointer hoisting of CD0/CA4/
   CA8/CBE, m2c declaration order, s16/s32 counter — all nd 258. Register-
   allocation floor. */
// FUN_0013A060
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013a060);

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
#pragma opt_common_subs on

/* measured: switch and both data-copy loops match; the final loop's
   float->s16 conversion guard (c.ole.s 0x4F000000; bc1t; sub.s/cvt.w.s/or
   0x80000000) is the documented cmpPersona floor -- mwcc b210 emits bc1f
   (or c.olt.s) for the out-of-line sub branch and different mfc1/or
   registers, no spelling reproduces retail's c.ole.s+bc1t. Tried (s32)&
   0xFFFF, (s16)(s32), explicit if/else in both orders, constant-left
   comparison, #pragma opt_loop_invariants on (hoists the constants, -17
   words) -- nd 59 floor, plus register allocation in both loops. */
// FUN_0013A530
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013a530);
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
// FUN_0013AC30
INCLUDE_ASM("asm/nonmatchings/cmpSkill", func_0013ac30);

