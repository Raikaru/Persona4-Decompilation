/* Consolidated Persona 4 source units. */
/* Original translation unit cmmRankUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"
extern u8 *func_00460990();
extern void func_00251d80();
extern u8 D_007963D0[];
extern void func_00460ac0();
extern void func_002516f0();

/* Absolute-addressed data (retail emits lui/addiu for these, so they must be
 * array-typed; scalar spelling would switch them to GPREL16). */
extern u8 D_00635CF8[];
extern u8 D_00635D18[];
extern u8 D_006367C0[];
extern void *(*D_008873F4[])(s32, s32, s32);

void func_0044ea90(void *msg, s32 id);
void func_0046d730(const void *file, s32 line);
extern u8 *func_00145270(s32 size);
extern void func_0047a6d0(s32 arg0, s32 arg1, void *arg2);
extern void func_00189ec0();
extern void func_00268bd0(s32 arg0, s32 arg1);
extern void func_003ef3a0(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_0047a0e0(s32 arg0, s32 arg1, f32 arg2);
extern void *memset(void *destination, s32 value, size_t count);

/* 128-bit object copies (retail lq/sq). */
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u_long128 D_00636730;
extern void func_0045d6e0(void *arg0, void *arg1, f32 fparg0, s32 arg2);

/* Old-style: the two callbacks passed here (func_00251e60 takes one s32,
 * func_00251ec0 takes none) do not share a signature, and a typed prototype
 * would force casts at every call site. */
s32 func_00451fc0();

/* Forward declarations for asm-fallback siblings referenced by C bodies. */
void func_00253850();
void func_00254a70();
void func_0025b240();
void func_0025c100();

typedef int (*code)(...);
extern code DAT_008873ec_abs[];


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.



// FUN_00251D80
void func_00251d80(s32 arg0, s32 *arg1) {
    extern s32 *func_00452560();
    u8 *base;
    s32 i;
    u8 *entry;

    base = (u8 *)func_00452560(arg1);
    entry = base;
    for (i = 0; i < 0x10; i++) {
        if (*(u32 *)entry & 1) {
            if (*(void **)(entry + 8) == NULL) {
                func_0046d730(D_00635CF8, 0x289);
            }
            if ((*(s32 (**)(u8 *, u8 *, u8 *))(entry + 8))(base, entry, *(u8 **)(base + 0x9E0)) != 0) {
                *(u32 *)entry &= ~1;
            }
        }
        entry += 0x78;
    }
    func_002516f0(base, *(u8 **)(base + 0x9E0));
}



// FUN_00251E60
s32 func_00251e60(s32 arg0) {
    u8 *p;

    func_00452560();
    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00251d80;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(D_007963D0, p);
    return 0;
}

// FUN_00251EC0
void func_00251ec0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}



// FUN_00251F00
void func_00251f00(s32 arg0, u32 *arg1) {
    u8 *temp_2;

    func_0044ea90(D_00635CF8, 0x277);
    temp_2 = (u8 *)D_008873F4[0](1, 0x9E4, 0x40000);
    *(u8 **)(temp_2 + 0x9E0) = (u8 *)arg1;
    if (temp_2 == NULL) {
        func_0046d730(D_00635CF8, 0x2D5);
    }
    func_00451fc0(arg0, D_00635D18, 0xF, 0, 0, func_00251e60, func_00251ec0, temp_2);
}



/* Seven spellings were tried without this pragma - ~2 / 0xFFFFFFFD / -3
 * literals, mask locals before and after the call, for and while forms,
 * |= and &= operators, and a ternary - all stuck at nd 24.
 * measured: MWCC rematerializes the flag-clear mask (addiu a0,zero,-3) inside
 * the else-branch instead of the loop preheader, shifting every temp register;
 * with the pragma the object is byte-identical (nd 3 = window padding). */
#pragma opt_loop_invariants on

// FUN_00251FC0
void func_00251fc0(s32 arg0, s32 arg1) {
    extern u32 *func_00452560();
    u32 *p;
    u32 temp;
    s32 i;

    p = func_00452560();
    for (i = 0; i < 0x10; i++) {
        temp = *p;
        if (temp & 1) {
            if (arg1 != 0) {
                *p = temp | 2;
            } else {
                *p = temp & ~2;
            }
        }
        p = (u32 *)((u8 *)p + 0x78);
    }
}
/* measured: scope closer for the hoist above - leaving it on changes the
   next functions in this file, so it is turned off immediately after. */
#pragma opt_loop_invariants off
// FUN_00252050
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252050);



// FUN_00252230
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252230);



// FUN_00252710
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252710);



// FUN_00252A60
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252a60);



// FUN_00253850
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00253850);



// FUN_00254A70
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00254a70);



// FUN_00255B00
s32 func_00255b00(s32 arg0, s32 *arg1) {
    s32 v;
    s32 rv;

    rv = 0;
    if (arg1[1] < 0x3C || !(arg1[0] & 2)) {
        arg1[1]++;
    }
    v = arg1[1];
    if (v >= 0x78) {
        rv = 1;
    }
    if (v < 0x3D) {
        func_00253850();
    } else {
        func_00254a70();
    }
    return rv;
}



// FUN_00255B90
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00255b90);



// FUN_00255ED0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00255ed0);



// FUN_00256040
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00256040);



// FUN_002561F0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002561f0);



// FUN_00256460
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00256460);



// FUN_002566D0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002566d0);



// FUN_00256BE0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00256be0);



// FUN_002570F0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_002570f0);



/* measured: retail materializes the s64 size init as `daddiu $s1, $zero, 0x400`
 * BEFORE the first func_00145270 call and keeps the call arg as an independent
 * `addiu $a0, $zero, 0x400`; mwcc b210 always emits `addiu` for the size init
 * (even with 0x400LL / (s64)0x400 / u64) and schedules it AFTER the call's
 * delay slot. 12+ spellings tried (declaration init, init-before/after call,
 * s64/u64, LL literals, cast forms, pragma schedule on/off, optimization_level
 * 3): every variant bottoms out at the same nd 2 on exactly those two words.
 * Everything else in the function is byte-identical. */
// FUN_00257820
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00257820);



// FUN_00257900
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00257900);



// FUN_0025B0F0
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_0025b0f0);

// FUN_0025B240
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_0025b240);



/* measured: retail hoists the jtbl_008873EC base into $s0 (reusing the dead
 * loop counter) and reloads the element per call; mwcc b210 rematerializes
 * the base at the FIRST call site (lui+lw) even when the base is cached in a
 * local (nd 34 with late assignment, nd 69 with early assignment, nd 28
 * direct). Loop and all other calls match byte-for-byte. Same floor as the
 * confirmed D_00887300 vtable calls. */
// FUN_0025C100
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_0025c100);



// FUN_0025C230
void func_0025c230(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *p;

    if (arg1 == 0) {
        func_0046d730(D_00635CF8, 0xC40);
    }
    func_0044ea90(D_00635CF8, 0xC41);
    p = (u8 *)D_008873F4[0](1, 0x5C, 0x40000);
    *(s32 *)(p + 0x18) = arg1;
    *(s32 *)(p + 0x1C) = arg2;
    *(s32 *)(p + 0x20) = arg3;
    *(s32 *)(p + 0x4) = 0;
    func_00451fc0(arg0, D_006367C0, 0xF, 0, 0, func_0025b240, func_0025c100, p);
}
