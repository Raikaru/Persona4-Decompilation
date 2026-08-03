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
extern void func_0047a0e0(u8 *arg0, s32 arg1, f32 arg2);
extern void *memset(void *destination, s32 value, size_t count);

/* 128-bit object copies (retail lq/sq). */
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u_long128 D_00636730;
extern void func_0045d6e0(void *arg0, void *arg1, s32 arg2, f32 fparg0);

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

/* Absolute-addressed float data for func_00252050's stack snapshot. */
extern f32 D_00635D28[];
extern f32 D_00635D2C[];
extern f32 D_00635D30[];
extern u8 D_00635D40[];
extern u8 D_00636180[];
extern u8 *func_00251d30(u8 *arg0);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void *func_002467b0(s32 arg0);
extern s32 func_00106330(s32 flag);
extern s64 func_00248d80(s16 arg0);
extern void func_00279d40(s32 arg0);
extern u8 *func_00279030(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2,
                         s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern u8 *func_002736d0(u8 **arg0, s32 arg1);
extern s32 func_002738d0(u8 *arg0);
extern void func_00272a10(u8 *arg0, f32 fparg0, f32 fparg1);
extern void func_00272ba0(u8 *arg0, s32 arg1);
extern void func_00273170(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00271b70(u8 *arg0);
extern u8 *func_001452b0(s32 arg0);
extern s32 func_00268cb0(u8 *arg0);
extern void func_00268c20(s32 arg0, s32 arg1);

/* measured: volatile casts on the D_00635D28/2C/30 loads and the spFloat
   stores force mwcc b210 to batch the three lwc1 before the three swc1;
   with plain float temps it interleaves each load/store pair. Loop 1's
   value pair and loop 2's counter are value-class locals (v/w/t) so they
   land in $v1/$v0, and loop 2 uses fresh pointer locals so mwcc
   re-allocates $a1/$a2 instead of keeping loop 1's $a2/$a3. */
// FUN_00252050
void func_00252050(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 *func_00452560();
    f32 spFloat[3];
    s32 copy2[0x87 * 2];
    s32 copy1[0x1B];
    u8 *src;
    u8 *p;
    u8 *srcp;
    u8 *dstp;
    u8 *srcp2;
    u8 *dstp2;
    s32 i;
    s32 v;
    s32 w;
    s32 t;
    s32 temp_18;
    f32 fa;
    f32 fb;
    f32 fc;

    fa = *(volatile f32 *)D_00635D28;
    fb = *(volatile f32 *)D_00635D2C;
    fc = *(volatile f32 *)D_00635D30;
    *(volatile f32 *)&spFloat[0] = fa;
    *(volatile f32 *)&spFloat[1] = fb;
    *(volatile f32 *)&spFloat[2] = fc;

    srcp = D_00635D40;
    dstp = (u8 *)copy2;
    i = 0x87;
    do {
        v = *(s32 *)(srcp + 0);
        w = *(s32 *)(srcp + 4);
        srcp += 8;
        i--;
        *(s32 *)(dstp + 0) = v;
        *(s32 *)(dstp + 4) = w;
        dstp += 8;
    } while (i > 0);

    srcp2 = D_00636180;
    dstp2 = (u8 *)copy1;
    v = 0x1B;
    do {
        t = *(s32 *)(srcp2 + 0);
        srcp2 += 4;
        v--;
        *(s32 *)(dstp2 + 0) = t;
        dstp2 += 4;
    } while (v > 0);

    p = func_00452560(arg0);
    if (arg1 >= 3) {
        func_0046d730(D_00635CF8, 0x329);
    }
    switch (arg1) {
    case 0:
        src = (u8 *)copy2 + arg2 * 0x6C;
        break;
    case 1:
        src = (u8 *)copy1 + arg2 * 0x6C;
        break;
    case 2:
        src = NULL;
        break;
    }
    temp_18 = *(s32 *)&spFloat[arg1];
    p = func_00251d30(p);
    if (p == NULL) {
        func_0046d730(D_00635CF8, 0x2A5);
    }
    func_0043f9c8(p, 0, 0x78);
    *(u32 *)p |= 1;
    *(s32 *)(p + 8) = temp_18;
    if (src != NULL) {
        func_0043f810(p + 0xC, src, 0x6C);
    }
}



/* measured: everything matches except the 8 doubled-alpha sites' register
   allocation (nd 25): retail ORs the doubling value into the SRL's dest
   ($a3) and CVTs straight into fa's f-register with a self-add, mwcc b210
   ORs into the ANDI's dest ($v1) and CVTs into a temp then adds (per-site
   2-4 words). Tried: named h, h |= form, separate shift local, textual
   (f32)h + (f32)h duplicate (fails CSE in this dense context, nd 424),
   2.0f * (f32)h (real lui+mtc1+mul.s), swapped operands (flips emit
   order), s32/u32 h. The float channels' adda.s/madd.s and the s16
   channels match byte-for-byte; the doubled-alpha idiom per the
   k_sceneDraw-family recipe (s32 native var, >= 0 polarity, u32 shifts,
   srl+andi+or). Saved/f-register rotation floor. */
// FUN_00252230
INCLUDE_ASM("asm/nonmatchings/cmmRankUp", func_00252230);


/* measured: retail keeps the arg2 copy in $2 ACROSS the func_00252230
   call (mwcc interprocedural register analysis - the callee is in the
   same TU and provably never writes $2); with func_00252230 as an asm
   fallback mwcc spills arg2 to a saved reg (nd 197, plus the whole
   register map shifts). Blocked on the func_00252230 floor above: the
   color-blend function must be C in this TU first, and its doubled-alpha
   register allocation is itself a recorded floor (nd 25). The m2c body
   here is complete and correct; convert after func_00252230 matches. */
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
u8 *func_00255b90(void) {
    u8 *entry;
    s32 count;
    u8 *cnt;
    u8 *node1;
    u8 *node2;
    u8 *node3;
    u8 *node4;

    count = 0;
    cnt = func_001452b0(1);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(2);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(3);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    cnt = func_001452b0(0xA);
    while (cnt != NULL) {
        count++;
        cnt = *(u8 **)(cnt + 0x138);
    }
    func_0044ea90(D_00635CF8, 0x5FA);
    entry = (u8 *)D_008873F4[0](1, (count + 1) * 0x10, 0x40000);
    count = 0;
    node1 = func_001452b0(1);
    while (node1 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node1 + 0x164);
        *(s32 *)(e + 0xC) = func_00268cb0(node1);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node1 + 0x164) + 0xF4);
        *(u8 **)(e + 8) = node1;
        count++;
        func_0047a0e0(*(u8 **)(node1 + 0x164), 0, 0.0f);
        func_00268c20(*(u16 *)(node1 + 0), 1);
        node1 = *(u8 **)(node1 + 0x138);
    }
    node2 = func_001452b0(2);
    while (node2 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node2 + 0x158);
        *(s32 *)(e + 0xC) = func_00268cb0(node2);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node2 + 0x158) + 0xF4);
        *(u8 **)(e + 8) = node2;
        count++;
        func_0047a0e0(*(u8 **)(node2 + 0x158), 0, 0.0f);
        func_00268c20(*(u16 *)(node1 + 0), 1);
        node2 = *(u8 **)(node2 + 0x138);
    }
    node3 = func_001452b0(3);
    while (node3 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node3 + 0x164);
        *(s32 *)(e + 0xC) = func_00268cb0(node3);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node3 + 0x164) + 0xF4);
        *(u8 **)(e + 8) = node3;
        count++;
        func_0047a0e0(*(u8 **)(node3 + 0x164), 0, 0.0f);
        func_00268c20(*(u16 *)(node3 + 0), 1);
        node3 = *(u8 **)(node3 + 0x138);
    }
    node4 = func_001452b0(0xA);
    while (node4 != NULL) {
        u8 *e = entry + count * 0x10;
        *(u8 **)(e + 4) = *(u8 **)(node4 + 0x144);
        *(s32 *)(e + 0xC) = func_00268cb0(node4);
        *(f32 *)(e + 0) = *(f32 *)(*(u8 **)(node4 + 0x144) + 0xF4);
        *(u8 **)(e + 8) = node4;
        count++;
        func_0047a0e0(*(u8 **)(node4 + 0x144), 0, 0.0f);
        func_00268c20(*(u16 *)(node4 + 0), 1);
        node4 = *(u8 **)(node4 + 0x138);
    }
    return entry;
}



// FUN_00255ED0
s32 func_00255ed0(s64 arg0, s32 arg1) {
    if ((*(s32 *)((u8 *)func_002467b0((u16)arg0) + 4) & 0x10) != 0 &&
        (arg0 != 0x18 || func_00106330(0x38) != 0)) {
        if ((s16)func_00248d80(arg0) == 3 ||
            (s16)func_00248d80(arg0) == 4) {
            if (arg1 == 3) {
                return 7;
            }
            if (arg1 == 6) {
                return 8;
            }
            if (arg1 == 10) {
                return 9;
            }
        } else {
            if (arg1 == 3) {
                return 2;
            }
            if (arg1 == 7) {
                return 3;
            }
            if (arg1 == 5) {
                return 4;
            }
            if (arg1 == 9) {
                return 5;
            }
            if (arg1 == 1) {
                return 6;
            }
        }
    }
    return 0;
}



// FUN_00256040
void func_00256040(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, s32 arg1,
                   s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6,
                   s32 arg7) {
    u8 *spAC;
    u8 *var_18;
    u8 *var_17;
    s32 var_16;

    func_00279d40(arg5);
    spAC = func_00279030((arg0 << 8) | arg1, fparg0, fparg1, fparg2, arg2,
                         arg3, arg4, arg5, arg6);
    if (spAC != NULL) {
        var_18 = func_002736d0(&spAC, arg7);
        if (var_18 == NULL) {
            var_18 = spAC;
            spAC = NULL;
        }
        var_17 = var_18;
        var_16 = 0;
        while (var_17 != NULL) {
            var_16 += func_002738d0(var_17);
            var_17 = *(u8 **)(var_17 + 0x24);
        }
        func_00272a10(var_18, fparg0 - ((f32)var_16 / 2.0f), fparg1);
        func_00272ba0(var_18, arg1 | ~0xFF);
        func_00273170(var_18, 1, 0);
        func_00271b70(var_18);
        if (spAC != NULL) {
            func_00271b70(spAC);
        }
    }
}



/* measured: retail's loop keeps d0-d3, the hoisted `1` constant, and the
   per-iteration address temp in saved regs ($s4-$s0, $s5) with the
   byte-extract values precomputed before the loop; mwcc b210 instead
   saves whichever THREE byte-extract values are computed first (in
   reverse order, nd 153/153) and keeps the loop counter in a saved reg.
   Tried: named c/d/e/g locals (both d-first and c-first declaration
   order), all-inline byte expressions (mwcc then does not hoist them out
   of the loop at all), s32/u32 counters, for/while forms. Saved-register
   rotation floor; the m2c candidate (code1_0025.c) is structurally
   correct and ready for a source that reproduces retail's allocation. */
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



/* measured: retail hoists `addiu $a0, $sp, 0x5C` (the &sp5C arg for
   func_0045d6e0) above the lwc1/swc1 float copy and `addiu $a1, $sp, 0x40`
   between the two D_00636730 lq/sq stores; mwcc b210 sinks both address
   materializations to just before the jal (nd 12, all twelve shifted
   words are this scheduling). Tried: direct &sp5C/&sp3x[1], pointer
   locals assigned at the store points, separate sp30/sp40 locals, the
   sp40 = sp30 copy form, and a two-element u_long128 array. Same
   load-sinking floor as the recorded mc.c FUN_002A4D10 func_0045d6e0
   case (nd 62 there). */
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
