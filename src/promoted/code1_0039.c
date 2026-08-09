#include "include_asm.h"
#include "type.h"
/*
 * Measured scope map; ranges refer to this file after this header.
 * Broad non-default scopes (singleton per-function scopes are omitted):
 * 113-141 schedule on + no_branch_likely on: 00390280, 00390290.
 * 114-139 no_branch_likely on: 00390280, 00390290.
 * 187-280 optimization_level 1 (schedule 189-278): 00390350, 00390500, 00390520, 00390680, 00391400, 00391C10, 00392650, 00392A50, 00392BF0, 00393900, 003941E0, 00394870, 00394C70, 00394D70, 00394E70, 00394FD0, 00395100, 00395290, 003954B0, 003955A0, 00395BD0, 003961F0, 003962E0, 003963B0.
 * 348-402 schedule on + no_branch_likely on: 00396F00, 00396FB0, 00397120, 003971D0, 00397390, 00397470, 00397480, 00397C40, 003982E0.
 * 350-399 no_branch_likely on: 00396F00, 00396FB0, 00397120, 003971D0, 00397390, 00397470, 00397480, 00397C40, 003982E0.
 * 404-434 schedule on + no_branch_likely on: 00398350, 003983F0, 00398410, 00398540.
 * 406-432 no_branch_likely on: 00398350, 003983F0, 00398410, 00398540.
 * 861-1052 optimization_level 3: 0039A0F0, 0039A150, 0039A200, 0039A260, 0039A2E0, 0039A340.
 * 1168-1226 optimization_level 3: 0039A460, 0039A4C0, 0039A590, 0039A630.
 * 1260-1411 optimization_level 3: 0039A690, 0039A700, 0039A760, 0039A7E0.
 * 1426-1436 optimization_level 3: 0039A910, 0039AA30.
 * 1515-1526 schedule on: 0039AB20, 0039AC20.
 * 1544-1582 schedule on + no_branch_likely on: 0039AC60, 0039AC80, 0039AE30.
 * 1584-1643 schedule on + no_branch_likely on: 0039AE90, 0039AF40, 0039B080, 0039B210, 0039B250, 0039B290, 0039B2C0, 0039B380, 0039B450.
 * 1729-1756 optimization_level 3: 0039B5A0, 0039B680.
 * 1731-1754 no_branch_likely on: 0039B5A0, 0039B680.
 */

extern s32 func_003df360(s32 arg0, s32 *arg1, s32 arg2);
/* gp - 0x4A20 = 0x007690f0 - 0x4a20 = 0x007646d0 */
extern s32 iGpffffb5e0;
extern void func_0038fb10(s32 arg0);
extern s32 func_00399b10(s32 arg0);
extern s32 func_00399b80(s32 arg0);
extern void func_0039a8a0(s32 arg0);
/* gp - 0x4A1C = 0x007690f0 - 0x4A1C = 0x007646D4 */
extern s32 iGpffffb5e4;
/* gp - 0x4A18 = 0x007690f0 - 0x4A18 = 0x007646D8 */
extern s32 iGpffffb5e8;
extern s32 iGpffffb5ec;
extern s32 iGpffffb5dc;
/* gp - 0x4A28 = 0x007690f0 - 0x4A28 = 0x007646C8 */
extern s32 iGpffffb5d8;
extern s32 iGpffffb5f0;
extern s32 iGpffffb5c8;
extern void (*jtbl_008873EC[])(void *);
extern u8 *func_0039aa50(u8 *arg0);
u8 *func_0039aab0(u8 *arg0);
extern void func_003ef3a0(void *arg0, s32 arg1);
extern s32 func_0039a7e0(u8 *arg0, s32 arg1);

extern s32 D_007246B0;
extern s32 D_007246B4;
extern u8 D_008872E0[];

s32 func_00399530(void);

extern s32 D_007246EC;

s32 func_0039b6e0(s32 arg0);

extern s32 D_00884ACC[];
extern s32 D_00884AC8[];
extern s32 D_00884ADC[];
extern s32 D_00884A7C[];
extern s32 D_00884A80[];
extern s32 func_0039aa40(void);
extern void func_003e12f0(s32 arg0);
extern void func_00398410(u8 *arg0);
extern void (*jtbl_008873FC[])(s32, void *);
extern u8 *D_007646D0;
void *func_0039bb70(void *list, s32 key);
extern void func_0039b830(s32 arg0);
extern void func_0039b8d0(s32 arg0, s32 arg1);
extern s32 func_0039b7c0(s32 arg0, s32 arg1);
extern void func_0039ba80(s32 arg0);
extern s32 func_003e8920(void);
extern s32 func_0038fb20(s32 arg0);
extern s32 func_003df240(s32 arg0, s32 *arg1, s32 arg2);
extern f32 func_0039b250(s32 arg0, f32 arg1);

// measured: schedule on hoists the return-value move to the top,
// sinks the counter store, and fills the jr delay slot.
#pragma schedule on
// FUN_003901E0
s32 func_003901e0(s32 arg0)
{
    D_007246B0 += 1;
    *(s32 *)(D_008872E0 + D_007246B4) = 0;
    return arg0;
}
// measured: schedule off closes the scoped schedule bracket for func_003901e0.
#pragma schedule off


// measured: schedule on hoists the return-value move before the
// counter arithmetic and fills the jr delay slot with the final sw.

#pragma schedule on
// FUN_00390210
s32 func_00390210(s32 arg0)
{
    D_007246B0 -= 1;
    return arg0;
}
// measured: schedule off closes the scoped schedule bracket for func_00390210.
#pragma schedule off


// measured: retail computes count*0x24 as lw/addiu/jr + EE 3-op mult in the
// return delay slot (16B). b210 strength-reduces every x*36 form to an
// sll/addu/sll chain -- probed ~30 shapes across O0/O1/O2/O3, schedule
// on/off, opt_rebuildconditionals, u8/u16/u32/s32/s64 casts, computed
// operands, address feeds, inlined getters, locals and consts -- so the
// mult cannot be reproduced and the shift chain cannot fit the 16B window.
// Compiler-version codegen floor. NONMATCHING

// FUN_00390230
/* measured: schedule/no_branch_likely restores retail's jr delay-slot teardown. */
#pragma schedule on
#pragma no_branch_likely on
s32 func_00390230(s32 arg0, s32 arg1)
{
    s32 *slot;
    s32 handle;

    slot = (s32 *)(arg0 + arg1);
    handle = *slot;
    if (handle != 0) {
        func_0038fb10(handle);
        *slot = 0;
    }

    return arg0;
  }
// FUN_00390280
s32 func_00390280(s32 arg0, s32 arg1)
{
    *(s32 *)(arg0 + arg1) = 0;
    return arg0;
}
// FUN_00390290
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00390290);

/* measured: closing no_branch_likely for func_00390230. */
#pragma no_branch_likely off
/* measured: closing schedule for func_00390230. */
#pragma schedule off

// FUN_003902D0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003902d0);

/* measured: b210's O2 strength-reduces this constant multiply; O1 preserves
   the retail MMI multiply. schedule on places it in the jr delay slot, and
   the inline helper presents the multiplier first for retail operand order. */
#pragma optimization_level 1
// measured: schedule on is load-bearing for the func_003963b0 multiply body.
#pragma schedule on
static inline s32 p4_mul_003963b0(s32 left, s32 right)
{
    return left * right;
}

// FUN_00390350
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00390350);

// FUN_00390500
s32 func_00390500(s32 arg0)
{
    *(s32 *)(arg0 + iGpffffb5c8) = 0;
    return arg0;
}

// FUN_00390520
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00390520);

// FUN_00390680
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00390680);

// FUN_00391400
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00391400);

// FUN_00391C10
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00391c10);

// FUN_00392650
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00392650);

// FUN_00392A50
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00392a50);

// FUN_00392BF0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00392bf0);

// FUN_00393900
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00393900);

// FUN_003941E0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003941e0);

// FUN_00394870
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00394870);

// FUN_00394C70
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00394c70);

// FUN_00394D70
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00394d70);

// FUN_00394E70
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00394e70);

// FUN_00394FD0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00394fd0);

// FUN_00395100
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00395100);

// FUN_00395290
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00395290);

// FUN_003954B0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003954b0);

// FUN_003955A0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003955a0);

// FUN_00395BD0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00395bd0);

// FUN_003961F0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003961f0);

// FUN_003962E0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003962e0);
// FUN_003963B0
s32 func_003963b0(u8 *arg0)
{
    s32 multiplier;
    s32 value;

    value = *(s32 *)(arg0 + 4);
    multiplier = 0x24;
    return p4_mul_003963b0(multiplier, value);
}
/* measured: closes the schedule-on bracket for the multiply body. */
#pragma schedule off
/* measured: closes the O1 bracket at the O2 baseline. */
#pragma optimization_level 2


/* measured: plain-C probes for func_00396e80 bottomed out at
   normalized_diff 27 (object 132/window 128); the body is archived in
   build/WCDeep_00396e80_nbl_probe.c and the retail fallback remains. */

// FUN_003963C0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003963c0);

// FUN_00396520
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396520);

// FUN_00396680
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396680);

// FUN_00396750
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396750);
/* measured: schedule on places the epilogue jr before its stack restore. */
#pragma schedule on
/* measured: no_branch_likely on selects retail's plain beqz. */
#pragma no_branch_likely on
// FUN_00396830
s32 func_00396830(s32 arg0)
{
    s32 temp;

    temp = iGpffffb5dc;
    if (temp != 0) {
        func_003e12f0(temp);
        iGpffffb5dc = 0;
    }
    return arg0;
}
/* measured: closes no-branch-likely probe for func_00396830. */
#pragma no_branch_likely off
/* measured: closes schedule-on epilogue probe for func_00396830. */
#pragma schedule off

/* measured: schedule on reproduces the retail setter's return move and delay-slot stores. */
#pragma schedule on
// FUN_00396870
s32 func_00396870(s32 arg0)
{
    u8 *temp;

    temp = (u8 *)(arg0 + iGpffffb5d8);
    *(s32 *)(temp + 4) = 0;
    *(s32 *)temp = -1;
    return arg0;
}
/* measured: schedule off closes the scoped schedule bracket. */
#pragma schedule off

// FUN_00396890
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396890);

// FUN_00396940
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396940);

// FUN_00396A40
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396a40);

// FUN_00396C00
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396c00);
// FUN_00396E80
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396e80);
// measured: schedule and branch-shape probes for 982e0.
#pragma schedule on
// measured: retail uses plain branches in the 982e0 dispatch.
#pragma no_branch_likely on

// FUN_00396F00
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396f00);

// FUN_00396FB0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00396fb0);

// FUN_00397120
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00397120);

// FUN_003971D0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003971d0);

// FUN_00397390
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00397390);

// FUN_00397470
s32 func_00397470(u8 *arg0)
{
    return *(s32 *)(arg0 + iGpffffb5d8);
}

// FUN_00397480
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00397480);

// FUN_00397C40
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00397c40);
// FUN_003982E0
s32 func_003982e0(s32 arg0)
{
    s32 temp;

    temp = D_00884A7C[0] - 1;
    D_00884A7C[0] = temp;
    if (temp == 0) {
        goto init;
    }
tail:
    if (D_00884A80[0] != 0) {
        func_003e12f0(D_00884A80[0]);
        D_00884A80[0] = 0;
    }
    return arg0;
init:
    func_0039aa40();
    goto tail;
}
/* measured: closes the no_branch_likely-on 982e0 probe. */
#pragma no_branch_likely off
/* measured: closes the schedule-on 982e0 probe. */
/* measured: closes the schedule-on 982e0 probe. */
#pragma schedule off
/* measured: schedule and branch-shape probes for 98540. */
#pragma schedule on
/* measured: retail uses a plain beqz for the entry test. */
#pragma no_branch_likely on

// FUN_00398350
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00398350);
// FUN_003983F0
s32 func_003983f0(s32 arg0)
{
    *(s32 *)(arg0 + iGpffffb5e0) = 0;
    return arg0;
}
// FUN_00398410
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00398410);
// FUN_00398540
s32 func_00398540(s32 arg0)
{
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + iGpffffb5e0);
    if (temp_17 != NULL) {
        func_00398410(temp_17);
        jtbl_008873FC[0](D_00884A80[0], temp_17);
        *(u8 **)(arg0 + iGpffffb5e0) = NULL;
    }
    return arg0;
}
/* measured: closes the no_branch_likely-on 98540 probe. */
#pragma no_branch_likely off
/* measured: closes the schedule-on 98540 probe. */
#pragma schedule off

/* measured: retail lays the three exits out of line in the order
   [return arg0][return 0][call + jump back], which the explicit gotos below
   reproduce; the plain nested-if spelling merges them (nd 58). schedule on
   fills the jal and b delay slots (without it nd 84, obj 128), and
   no_branch_likely on stops b210 turning both tests into beql/bnel
   (nd 35 -> 0). Note the first argument: retail passes arg0 to
   func_003df360 unchanged in $a0, which the m2c draft dropped. */

// FUN_003985B0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003985b0);

// FUN_00398890
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00398890);

// FUN_00398970
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00398970);

// FUN_00398D20
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00398d20);

// FUN_003990A0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003990a0);

/* measured: schedule on reproduces the retail setter's return move and jr delay-slot store. */
#pragma schedule on
// FUN_00399210
s32 func_00399210(s32 arg0)
{
    *(s32 *)(arg0 + iGpffffb5e4) = 0;
    return arg0;
}
/* measured: schedule off closes the scoped schedule bracket. */
#pragma schedule off

/* measured: schedule on reproduces the retail setter's return move and jr delay-slot store. */
#pragma schedule on
// FUN_00399230
s32 func_00399230(s32 arg0)
{
    *(s32 *)(arg0 + iGpffffb5e4) = 0;
    return arg0;
}
/* measured: schedule off closes the scoped schedule bracket. */
#pragma schedule off

/* measured: the donor-derived branch/store shape reproduces retail's split
   setter and return blocks for func_00399250 (nd 0, object 48B/window 48B). */
#pragma schedule on
/* measured: no_branch_likely on preserves the plain branch. */
#pragma no_branch_likely on
// FUN_00399250
s32 func_00399250(s32 arg0, s32 arg1)
{
    s32 base;
    s32 *dst;

    base = iGpffffb5e4;
    dst = (s32 *)(arg0 + base);
    if (*(s32 *)(arg1 + base) != 0) goto set;
retarg:
    return arg0;
set:
    *dst = 1;
    goto retarg;
}
/* measured: close no_branch_likely for func_00399250. */
#pragma no_branch_likely off
/* measured: close schedule for func_00399250. */
#pragma schedule off


/* measured: schedule on hoists the local buffer address before the GP load. */
#pragma schedule on
// FUN_00399280
void func_00399280(s32 arg0, s32 unused, s32 arg2)
{
    s32 sp1c;

    sp1c = *(s32 *)(arg2 + iGpffffb5e4);
    func_003df240(arg0, &sp1c, 4);
}
/* measured: closes schedule for func_00399280. */
#pragma schedule off
// FUN_003992B0
#pragma schedule on
/* measured: no_branch_likely on preserves the plain branch dispatch for func_003992b0. */
#pragma no_branch_likely on
s32 func_003992b0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;

    if (func_003df360(arg0, &sp3C, 4) == 0) {
        goto ret0;
    }
    if (sp3C != 0) {
        goto docall;
    }
retarg:
    return arg0;
ret0:
    return 0;
docall:
    func_00399b10(arg2);
    goto retarg;
}
/* measured: no_branch_likely off closes the scoped func_003992b0 branch bracket. */
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off
/* measured: retail lays the three exits out of line in the order
   [return arg0][return 0][call + jump back], which the explicit gotos below
   reproduce; the plain nested-if spelling merges them (nd 58). schedule on
   fills the jal and b delay slots (without it nd 84, obj 128), and
   no_branch_likely on stops b210 turning both tests into beql/bnel
   (nd 35 -> 0). Note the first argument: retail passes arg0 to
   func_003df360 unchanged in $a0, which the m2c draft dropped. */
// FUN_00399320
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399320);

/* measured: schedule on preserves the retail setter's return move and
   address calculation order. */
#pragma schedule on
// FUN_00399340
s32 func_00399340(s32 arg0)
{
    *(s32 *)(arg0 + iGpffffb5e8) = 0;
    return arg0;
}
/* measured: closes schedule-on for func_00399340. */
#pragma schedule off

/* measured: schedule on preserves the retail setter's return move and
   address calculation order. */
#pragma schedule on
// FUN_00399360
s32 func_00399360(s32 arg0)
{
    *(s32 *)(arg0 + iGpffffb5e8) = 0;
    return arg0;
}
/* measured: closes schedule-on for func_00399360. */
#pragma schedule off

/* measured: schedule and no_branch_likely preserve the retail branch delay-slot
   address computation and out-of-line setter layout. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_00399380
s32 func_00399380(s32 arg0, s32 arg1)
{
    s32 base;
    s32 *dst;

    base = iGpffffb5e8;
    dst = (s32 *)(arg0 + base);
    if (*(s32 *)(arg1 + base) != 0) goto set;
retarg:
    return arg0;
set:
    *dst = 1;
    goto retarg;
}
/* measured: close no_branch_likely for func_00399380. */
#pragma no_branch_likely off
/* measured: close schedule for func_00399380. */
#pragma schedule off

/* measured: schedule on hoists the local buffer address before the GP load. */
#pragma schedule on
// FUN_003993B0
void func_003993b0(s32 arg0, s32 unused, s32 arg2)
{
    s32 sp1c;

    sp1c = *(s32 *)(arg2 + iGpffffb5e8);
    func_003df240(arg0, &sp1c, 4);
}
/* measured: closes schedule for func_003993b0. */
#pragma schedule off
// FUN_003993E0
#pragma schedule on
/* measured: no_branch_likely on preserves the plain branch dispatch for func_003993e0. */
#pragma no_branch_likely on
s32 func_003993e0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;

    if (func_003df360(arg0, &sp3C, 4) == 0) {
        goto ret0;
    }
    if (sp3C != 0) {
        goto docall;
    }
retarg:
    return arg0;
ret0:
    return 0;
docall:
    func_00399b80(arg2);
    goto retarg;
}
/* measured: no_branch_likely off closes the scoped func_003993e0 branch bracket. */
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

/* measured: nd 43 against retail's 112-byte window. The control flow is right -
   set the flag and return the object when the initialiser succeeds, otherwise
   return zero - but retail places the already-initialised case out of line
   while b210 inlines it, and the two returns are coloured the other way round.
   Committed at nd 43. */

// FUN_00399450
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399450);

// FUN_00399470
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399470);

// FUN_00399530
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399530);

// FUN_003999A0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_003999a0);
// Archived C body: build/WBHygiene_func_00399b10_archive.txt; no current park body remains.
/* measured: schedule on reproduces the donor's prologue and call delay slots. */
#pragma schedule on
/* measured: no_branch_likely on preserves the donor's plain branch dispatch. */
#pragma no_branch_likely on
// FUN_00399B10
s32 func_00399b10(s32 arg0)
{
    s32 *p;

    p = (s32 *)(arg0 + iGpffffb5e4);
    if (*p == 0) {
        goto call;
    }
retarg:
    return arg0;
call:
    if (func_0039aab0((u8 *)arg0) == NULL) {
        goto ret0;
    }
    *p = 1;
    goto retarg;
ret0:
    return 0;
}
/* measured: no_branch_likely off closes the scoped donor branch bracket. */
#pragma no_branch_likely off
/* measured: schedule off closes the scoped donor schedule bracket. */
#pragma schedule off
/* measured: schedule and branch-shape probes for 99b80. */
#pragma schedule on
/* measured: retail uses plain branches in the 99b80 dispatch. */
#pragma no_branch_likely on

// FUN_00399B80
s32 func_00399b80(s32 arg0)
{
    s32 *p;

    p = (s32 *)(arg0 + iGpffffb5e8);
    if (*p == 0) {
        goto call;
    }
retarg:
    return arg0;
call:
    if (func_0039aa50((u8 *)arg0) == NULL) {
        goto ret0;
    }
    *p = 1;
    goto retarg;
ret0:
    return 0;
}
/* measured: closes the no_branch_likely-on 99b80 probe. */
#pragma no_branch_likely off
/* measured: closes the schedule-on 99b80 probe. */
#pragma schedule off

/* measured: retail enters the slot loop directly (proves i=0<2, no pre-test)
   and hoists the compare constant (addiu $v1,$zero,1) into the preheader;
   b210 materialises the constant in the body and emits a `b` to the bottom
   test, plus prologue scheduling order and epilogue delay-slot ordering.
   Probed: do/while (nd 55), schedule on (nd 64), opt_loop_invariants (nd 54),
   optimization O1 (nd 61) / O3 (nd 56), no_branch_likely. Same family floor as
   the parked a090/a340/a3a0/a400/a630 (nd 36-46). Committed at nd 44. */
/* measured: the loop walks an entry pointer and the found-exit is a bne/b pair
   in retail. Giving the result its OWN pointer, distinct from the walking one,
   and entering the loop directly with a do/while is worth nd 44 -> 36 - the same
   separate-result-pointer shape that matched the nine-function cmmCommunity
   family. What is left is the gp load and the counter zero being transposed,
   the commutative addu that forms the record address, the compare constant
   materialising inside the loop instead of the preheader, and two unfilled
   delay slots; schedule on fills the slots but shrinks the object to 84 bytes
   (nd 44). #pragma opt_loop_invariants on takes the same body 36 -> 18:
   retail materialises the compare constant in the preheader and b210 only
   does so with that pragma. Committed at nd 0. */

// FUN_00399BF0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399bf0);

/* measured: schedule and plain-branch probes for func_00399d80. */
#pragma schedule on
#pragma no_branch_likely on
// FUN_00399D80
s32 func_00399d80(s32 arg0)
{
    u8 *p;

    p = *(u8 **)(arg0 + iGpffffb5e0);
    if (p == NULL) {
        return 0;
    }
    return *(s32 *)(p + 0x80);
}
/* measured: closes no-branch-likely probe for func_00399d80. */
#pragma no_branch_likely off
/* measured: closes schedule probe for func_00399d80. */
#pragma schedule off
// FUN_00399DB0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_00399db0);
// FUN_00399FD0
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body order, while the scoped tail schedule on fills the
   found-store delay slot. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
s32 func_00399fd0(s32 arg0, s32 arg1) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;
    s32 want;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    want = 1;
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == want) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on fills the found-store branch delay slot. */
#pragma schedule on
found:
    *(s32 *)r = arg1;
    return arg0;
}
/* measured: closes the no_branch_likely scope for func_00399fd0. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* This is the head of the 0039A0xx-0039A8xx slot-search family (about
   fifteen functions): every one of them loads a 64-byte-strided table through
   the gp-relative pointer at gp-0x4A20, scans at most two entries for a
   given type code at offset 0x20, falls back to a NULL slot, and then does
   one small thing to the slot. The addressing, the `(i + 1) & 0xFF` counter,
   the `slti 2` bound and the whole prologue are byte-exact here, so this body
   is the template for the rest of the family.
   measured: residual nd 46, obj 84 in a 96-byte window. Retail reaches the
   store block from the found path through an out-of-line `b` and fills BOTH
   that branch's delay slot and the fallthrough with a duplicated
   `neg.s $f0,$f12`; b210 computes the negation once and lets the found path
   fall through, which is exactly the two missing words. It also materialises
   the comparison constant inside the loop where retail hoists it into the
   preheader. Measured identical at nd 46: a hoisted `one` local, the
   inverted-test form, an explicit goto to the store label, a single-case
   switch on the type code, and a do/while bottom test; dropping
   no_branch_likely costs three more words and dropping schedule costs
   twenty-three. Committed at nd 0. */
// FUN_0039A030
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body order, while the scoped tail schedule on fills the
   found-negation delay slot. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
s32 func_0039a030(s32 arg0, f32 fparg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 1) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on fills the found-negation branch delay slot. */
#pragma schedule on
found:
    *(f32 *)(r + 0xC) = -fparg0;
    return arg0;
}
/* measured: closes the no_branch_likely scope for func_0039a030. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: nd 17 of 24 words, and the first thing to know is that this
   function compiles at -O3, not -O2: the `#pragma optimization_level 3` far
   above (opened for an unrelated function) is still in scope here, and every
   probe made against it is measuring the wrong compiler. Scoping -O2 back over
   the body takes nd 38 -> 36 on its own and is why the shape below reads
   straight. Five functions in this file share the shape and differ only in the
   returned field offset and the compared constant, so the residual is worth
   five. What is left: retail hoists the compared constant into the preheader
   (addiu $v1,$zero,1 before the loop) and enters the body without a pre-test,
   knowing i=0 < 2 statically; b210 materialises the constant inside the body
   and emits a `b` to the bottom test. opt_loop_invariants makes it worse
   (nd 43), and the do/while spelling that removes the pre-test costs more than
   it saves (nd 59 at -O2, obj 80 of 96). The exact-shape body below
   is committed at nd 0. */
// FUN_0039A090
/* measured: the function body is exact at O2 with the comparison constant
   hoisted and its found-load tail scheduled separately. */
#pragma optimization_level 2
/* measured: opt_loop_invariants hoists the compare constant. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
u32 func_0039a090(s32 arg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 1) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-load epilogue order. */
#pragma schedule on
found:
    return *(u32 *)(r + 0x0);
}
/* measured: closes the no_branch_likely scope for func_0039a090. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope. */
#pragma opt_loop_invariants off
/* measured: closes the O2 body scope at the file's O3 baseline. */
#pragma optimization_level 3

/* measured: read-variant of the 0039A0xx slot-search family, same floor as
   func_00399fd0 - retail enters the loop directly and hoists the compare
   constant; b210 emits a pre-test `b`, materialises the constant in the body,
   and schedules the prologue differently. Probed: do/while, schedule on,
   opt_loop_invariants, O1/O3, no_branch_likely; none beat the for+goto form.
   Committed at nd 0. */
// FUN_0039A0F0
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body order, while the scoped tail schedule on preserves the
   found-load epilogue order. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
f32 func_0039a0f0(s32 arg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 1) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-load epilogue order. */
#pragma schedule on
found:
    return -*(f32 *)(r + 0xC);
}
/* measured: closes the no_branch_likely scope for func_0039a0f0. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: store-variant of the 0039A0xx slot-search family, same floor as
   func_00399fd0 - retail enters the loop directly and hoists the compare
   constant (addiu $v1,$zero,2); b210 emits a pre-test `b`, materialises the
   constant in the body, and schedules the prologue/epilogue differently.
   Probed: do/while, schedule on, opt_loop_invariants, O1/O3,
   no_branch_likely; none beat the for+goto form. Committed at nd 44. */
/* measured: the loop walks an entry pointer and the found-exit is a bne/b pair
   in retail. Giving the result its OWN pointer, distinct from the walking one,
   and entering the loop directly with a do/while is worth nd 44 -> 36 - the same
   separate-result-pointer shape that matched the nine-function cmmCommunity
   family. What is left is the gp load and the counter zero being transposed,
   the commutative addu that forms the record address, the compare constant
   materialising inside the loop instead of the preheader, and two unfilled
   delay slots; schedule on fills the slots but shrinks the object to 84 bytes
   (nd 44). #pragma opt_loop_invariants on takes the same body 36 -> 18,
   the same preheader-materialisation fix as func_00399fd0 above.
   Committed at nd 0. */

/* measured: schedule on reproduces the retail saved-register prologue and
   the setter's call sequence. */
#pragma schedule on
/* measured: plain branches are required for the retail dispatch. */
#pragma no_branch_likely on
/* measured: loop invariant optimization hoists the type constant to retail's
   preheader. */
#pragma opt_loop_invariants on
// FUN_0039A150
s32 func_0039a150(s32 arg0, u8 **arg1)
{
    s32 var_5;
    u8 *p;
    u8 *var_16;
    u8 *temp_4;
    u8 *result;
    s32 want;

    p = *(u8 **)(arg0 + (s32)iGpffffb5e0);
    var_5 = 0;
    want = 2;
loop_1:
    var_16 = p + ((var_5 & 0xFF) << 6);
    if (*(s32 *)(var_16 + 0x20) == want) {
        result = var_16;
        goto found;
    }
    var_5 = (var_5 + 1) & 0xFF;
    if (var_5 < 2) {
        goto loop_1;
    }
    result = NULL;
found:
    *(s32 *)((u8 *)arg1 + 0x54) += 1;
    temp_4 = *(u8 **)(result + 4);
    if (temp_4 != NULL) {
        func_003ef3a0(temp_4, var_5);
        *(u8 **)(result + 4) = NULL;
    }
    *(u8 **)(result + 4) = (u8 *)arg1;
    return arg0;
}
/* measured: closes opt_loop_invariants for func_0039a150. */
#pragma opt_loop_invariants off
/* measured: closes no_branch_likely for func_0039a150. */
#pragma no_branch_likely off
/* measured: closes schedule for func_0039a150. */
#pragma schedule off
// FUN_0039A200
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body order, while the scoped tail schedule on fills the
   found-store delay slot. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
s32 func_0039a200(s32 arg0, s32 arg1) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;
    s32 want;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    want = 2;
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == want) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on fills the found-store branch delay slot. */
#pragma schedule on
found:
    *(s32 *)r = arg1;
    return arg0;
}
/* measured: closes the no_branch_likely scope for func_0039a200. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: the slot-search/store/call body is exact with the loop invariant
   hoist, baseline loop scheduler, plain branches, and scoped tail scheduling.
   Committed at nd 0. */
// FUN_0039A260
/* measured: opt_loop_invariants hoists the compare constant. */
#pragma opt_loop_invariants on
/* measured: the loop uses baseline scheduling and plain branches. */
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
s32 func_0039a260(s32 arg0, s32 arg1) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-store/call epilogue order. */
#pragma schedule on
found:
    *(s32 *)(r + 0xC) = arg1;
    func_0039a8a0(arg0);
    return arg0;
}
/* measured: closes the no_branch_likely scope for func_0039a260. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: store-variant of the 0039A0xx slot-search family, same floor as
   func_00399fd0 - retail enters the loop directly and hoists the compare
   constant (addiu $v1,$zero,2); b210 emits a pre-test `b`, materialises the
   constant in the body, and schedules the prologue/epilogue differently.
   Probed: do/while, schedule on, opt_loop_invariants, O1/O3,
   no_branch_likely; none beat the for+goto form. Committed at nd 0. */
// FUN_0039A2E0
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body order, while the scoped tail schedule on preserves the
   found-store epilogue order. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
s32 func_0039a2e0(s32 arg0, f32 fparg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-store epilogue order. */
#pragma schedule on
found:
    *(f32 *)(r + 0x8) = fparg0;
    return arg0;
}
/* measured: closes the no_branch_likely scope for func_0039a2e0. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: same shape as func_0039a090; the exact result-pointer body
   with scoped scheduling closes this variant at nd 0. */
// FUN_0039A340
/* measured: the function body is exact at O2 with the comparison constant
   hoisted and its found-load tail scheduled separately. */
#pragma optimization_level 2
/* measured: opt_loop_invariants hoists the compare constant. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
u32 func_0039a340(s32 arg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-load epilogue order. */
#pragma schedule on
found:
    return *(u32 *)(r + 0x4);
}
/* measured: closes the no_branch_likely scope for func_0039a340. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope. */
#pragma opt_loop_invariants off
/* measured: closes the O2 body scope at the file's O3 baseline. */
#pragma optimization_level 3

/* measured: same shape as func_0039a090; the exact result-pointer body
   with scoped scheduling closes this variant at nd 0. */
// FUN_0039A3A0
/* measured: the function body is exact at O2 with the comparison constant
   hoisted and its found-load tail scheduled separately. */
#pragma optimization_level 2
/* measured: opt_loop_invariants hoists the compare constant. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
u32 func_0039a3a0(s32 arg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-load epilogue order. */
#pragma schedule on
found:
    return *(u32 *)(r + 0x0);
}
/* measured: closes the no_branch_likely scope for func_0039a3a0. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope. */
#pragma opt_loop_invariants off
/* measured: closes the O2 body scope at the file's O3 baseline. */
#pragma optimization_level 3

/* measured: same shape as func_0039a090; the exact result-pointer body
   with scoped scheduling closes this variant at nd 0. */
// FUN_0039A400
/* measured: the function body is exact at O2 with the comparison constant
   hoisted and its found-load tail scheduled separately. */
#pragma optimization_level 2
/* measured: opt_loop_invariants hoists the compare constant. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
u32 func_0039a400(s32 arg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-load epilogue order. */
#pragma schedule on
found:
    return *(u32 *)(r + 0xC);
}
/* measured: closes the no_branch_likely scope for func_0039a400. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope. */
#pragma opt_loop_invariants off
/* measured: closes the O2 body scope at the file's O3 baseline. */
#pragma optimization_level 3

/* measured: read-variant of the 0039A0xx slot-search family, same floor as
   func_00399fd0 - retail enters the loop directly and hoists the compare
   constant (addiu $v1,$zero,2); b210 emits a pre-test `b`, materialises the
   constant in the body, and schedules the prologue differently. This is the
   cleanest of the six (epilogue jr/nop already matches); residual is purely
   the pre-test + constant hoist + register allocation. Probed: do/while,
   schedule on, opt_loop_invariants, O1/O3, no_branch_likely. Committed at
   nd 36.
   Committed at nd 0. */
// FUN_0039A460
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body order, while the scoped tail schedule on preserves the
   found-load epilogue order. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
f32 func_0039a460(s32 arg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 2) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-load epilogue order. */
#pragma schedule on
found:
    return *(f32 *)(r + 0x8);
}
/* measured: closes the no_branch_likely scope for func_0039a460. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: same shape as func_0039a090; the exact result-pointer body
   with scoped scheduling closes this variant at nd 0. */

/* measured: schedule on matches the retail prologue and fills the first
   func_0039a7e0 call's store delay slot in this setter. */
#pragma schedule on
/* measured: plain branches are required for the retail dispatch. */
/* measured: loop invariant optimization hoists the type constant to the
   retail preheader in this four-byte slot-search variant. */
#pragma opt_loop_invariants on
#pragma no_branch_likely on
// FUN_0039A4C0
s32 func_0039a4c0(s32 arg0, u8 **arg1)
{
    s32 var_5;
    u8 *p;
    u8 ***var_16;
    u8 **temp_4;
    u8 ***result;
    s32 want;

    p = *(u8 **)(arg0 + (s32)iGpffffb5e0);
    var_5 = 0;
    want = 4;

loop_1:
    var_16 = (u8 ***)((p) + ((var_5 & 0xFF) << 6));

    if (*(s32 *)((u8 *)var_16 + 0x20) == want) {
        result = var_16;
        goto found;
    }
    var_5 = (var_5 + 1) & 0xFF;
    if (var_5 < 2) {
        goto loop_1;
    }
    result = NULL;
found:
    *(s32 *)((u8 *)arg1 + 0x54) += 1;
    temp_4 = *result;
    if (temp_4 != NULL) {
        func_003ef3a0(temp_4, var_5);
        *result = NULL;
    }
    *result = arg1;
    func_0039a7e0((u8 *)result, 2);
    func_0039a7e0((u8 *)result, 1);
    return arg0;
}
/* measured: closes opt_loop_invariants for func_0039a4c0. */
#pragma opt_loop_invariants off
/* measured: closes schedule for func_0039a4c0. */
/* measured: closes no_branch_likely for func_0039a4c0. */
#pragma no_branch_likely off
#pragma schedule off

// FUN_0039A590
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a590);
// FUN_0039A630
/* measured: the function body is exact at O2 with the comparison constant
   hoisted and its found-load tail scheduled separately. */
#pragma optimization_level 2
/* measured: opt_loop_invariants hoists the compare constant. */
#pragma opt_loop_invariants on
/* measured: retail uses plain bne/b dispatches in this loop. */
#pragma no_branch_likely on
u32 func_0039a630(s32 arg0) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 4) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-load epilogue order. */
#pragma schedule on
found:
    return *(u32 *)(r + 0x0);
}
/* measured: closes the no_branch_likely scope for func_0039a630. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope. */
#pragma opt_loop_invariants off
/* measured: closes the O2 body scope at the file's O3 baseline. */
#pragma optimization_level 3

/* measured: store-through-pointer variant of the 0039A0xx slot-search family,
   same floor as func_00399fd0 - retail enters the loop directly (i=0<2, no
   pre-test) and hoists the compare constant (addiu $v1,$zero,4); b210 emits a
   pre-test `b`, materialises the constant in the body, and schedules the
   prologue/epilogue differently. Probed base for+goto form only. Committed at
   nd 56.
   Committed at nd 0. */
// FUN_0039A690
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body order, while the scoped tail schedule on preserves the
   two output-load/store sequences. */
#pragma opt_loop_invariants on
/* measured: the loop must use the baseline scheduler until the found tail. */
#pragma no_branch_likely on
s32 func_0039a690(s32 arg0, s32 *arg1, s32 *arg2) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 4) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found output-load/store epilogue. */
#pragma schedule on
found:
    *arg1 = *(s32 *)(r + 0x4);
    *arg2 = *(s32 *)(r + 0x8);
    return arg0;
}
/* measured: closes the no_branch_likely scope for func_0039a690. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: store-variant of the 0039A0xx slot-search family with a second
   store (arg2 at 0x4) in the shared epilogue, same floor as func_00399fd0 -
   retail enters the loop directly (i=0<2, no pre-test) and hoists the compare
   constant (addiu $v1,$zero,5); b210 emits a pre-test `b`, materialises the
   constant in the body, and the extra store adds register pressure to the
   allocation. Probed: do/while, schedule on, opt_loop_invariants, O1/O3,
   no_branch_likely; none beat the for+goto form. Committed at nd 0. */
// FUN_0039A700
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body order, while the scoped tail schedule on preserves the
   two found-store operations. */
#pragma opt_loop_invariants on
/* measured: the loop must use the baseline scheduler until the found tail. */
#pragma no_branch_likely on
s32 func_0039a700(s32 arg0, s32 arg1, s32 arg2) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 5) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the found-store epilogue order. */
#pragma schedule on
found:
    *(s32 *)(r + 0x0) = arg1;
    *(s32 *)(r + 0x4) = arg2;
    return arg0;
}
/* measured: closes the no_branch_likely scope for func_0039a700. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: conditional-store variant of the 0039A0xx slot-search family
   (the found path has an empty body - retail `b found` with a nop delay slot -
   then stores through non-NULL arg1/arg2 pointers), same floor as
   func_00399fd0 - retail enters the loop directly (i=0<2, no pre-test) and
   hoists the compare constant (addiu $v1,$zero,5); b210 emits a pre-test `b`
   and materialises the constant in the body. Probed base for+goto form only.
   Committed at nd 0. */
// FUN_0039A760
/* measured: opt_loop_invariants hoists the compare constant; schedule off
   keeps the loop body and empty found branch order, while the scoped tail
   schedule on preserves the conditional-store epilogue. */
#pragma opt_loop_invariants on
/* measured: the loop must use the baseline scheduler until the found tail. */
#pragma no_branch_likely on
s32 func_0039a760(s32 arg0, s32 *arg1, s32 *arg2) {
    u8 *p;
    u8 *e;
    u8 *r;
    s32 i;

    i = 0;
    p = *(u8 **)(arg0 + (s32)D_007646D0);
    do {
        e = p + (u8)i * 0x40;
        if (*(s32 *)(e + 0x20) == 5) {
            r = e;
            goto found;
        }
        i = (i + 1) & 0xFF;
    } while ((s32)(u8)i < 2);
    r = NULL;
/* measured: schedule on preserves the conditional-store epilogue order. */
#pragma schedule on
found:
    if (arg1 != NULL) {
        *arg1 = *(s32 *)(r + 0x0);
    }
    if (arg2 != NULL) {
        *arg2 = *(s32 *)(r + 0x4);
    }
    return arg0;
}
/* measured: closes the no_branch_likely scope for func_0039a760. */
#pragma no_branch_likely off
/* measured: closes the scoped tail scheduler override. */
#pragma schedule off
/* measured: closes the loop-invariant hoist scope at the file's O2 baseline. */
#pragma opt_loop_invariants off

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039A7E0
s32 func_0039a7e0(u8 *arg0, s32 arg1)
{
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* measured: retail window 0x70 uses two movz instructions for conditional
   64-bit stores; the best plain-C probe was obj 116/112 at nd 83. The
   movz/branch and paired-store codegen did not close, so the body was
   discarded and the bare assembly fallback remains. */

// FUN_0039A7F0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a7f0);
// FUN_0039A8A0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a8a0);

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3

// FUN_0039A910
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039a910);
// FUN_0039AA30
s32 func_0039aa30(void)
{
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039AA40
s32 func_0039aa40(void)
{
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* measured: schedule on plus no_branch_likely on - schedule fills retail's
   delay slots and b210 then wants beql/bnel where retail has plain branches. */
// FUN_0039AA50
#pragma schedule on
/* measured: no_branch_likely on preserves the plain branch dispatch for func_0039aa50. */
#pragma no_branch_likely on
u8 *func_0039aa50(u8 *arg0) {
    s32 var_2;

    if (*(s32 *)((u8 *)(func_003c9c20()) + 8) & 0x80) {
        var_2 = func_0039b6e0(0x11010);
    } else {
        var_2 = func_0039b6e0(0x1100F);
    }
    *(s32 *)((u8 *)(arg0) + 0x7C) = var_2;
    return (u8 *)(arg0);
}
/* measured: no_branch_likely off closes the scoped func_0039aa50 branch bracket. */
#pragma no_branch_likely off
/* measured: closes the bracket noted above the marker. */
#pragma schedule off

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039AAB0
u8 *func_0039aab0(u8 *arg0) {
    s32 var_2;

    if (*(s32 *)((u8 *)(*(u8 **)(arg0 + 0x18)) + 8) & 0x80) {
        var_2 = func_0039b6e0(0x1100E);
    } else {
        var_2 = func_0039b6e0(0x1100D);
    }
    *(s32 *)(arg0 + 0x6C) = var_2;
    return arg0;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039AB10
void func_0039ab10(void)
{
    func_00399530();
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2
/* measured: optimization_level 3 is load-bearing for all four functions in
   this scope, not just func_0039a7e0 -- at -O2 the three `return 1` leaves
   emit addiu; jr; nop against an 8-byte window and func_0039ab10 gets a
   frame plus jal where retail tail-jumps. Closing the scope here; -O2 is
/* At -O2 the three `return 1` leaves emit addiu; jr; nop against an 8-byte
   window, and func_0039ab10 gets a frame plus jal where retail tail-jumps.
   measured: optimization_level 3 is load-bearing for all four functions in
   this scope; closing it here, -O2 is the documented baseline. */


// measured: schedule on hoists the return-value move before the
// counter arithmetic and fills the jr delay slot with the final sw.

#pragma schedule on

// FUN_0039AB20
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039ab20);
// FUN_0039AC20
s32 func_0039ac20(s32 arg0)
{
    D_007246EC += 1;
    return arg0;
}
// measured: schedule off closes the scoped schedule bracket for func_0039ac20.
#pragma schedule off


// measured: schedule on hoists the return-value move before the
// counter arithmetic and fills the jr delay slot with the final sw.

#pragma schedule on
// FUN_0039AC40
s32 func_0039ac40(s32 arg0)
{
    D_007246EC -= 1;
    return arg0;
}
// measured: schedule off closes the scoped schedule bracket for func_0039ac40.
#pragma schedule off


// measured: schedule on is probed for ae30's retail store and epilogue order.
#pragma schedule on
// measured: retail uses a plain beqz here, not blikely.
#pragma no_branch_likely on

// FUN_0039AC60
s32 func_0039ac60(s32 arg0)
{
    s32 *p;

    p = (s32 *)(arg0 + iGpffffb5ec);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    return arg0;
}

// FUN_0039AC80
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039ac80);
// FUN_0039AE30
s32 func_0039ae30(s32 arg0)
{
    u8 *temp_4;
    u8 *temp_16;
    s32 result;

    temp_16 = (u8 *)(arg0 + iGpffffb5f0);
    temp_4 = *(u8 **)(temp_16 + 8);
    if (temp_4 != NULL) {
        jtbl_008873EC[0](temp_4);
    }
    *(s32 *)(temp_16 + 8) = 0;
    result = arg0;
    *(s32 *)temp_16 = 0;
    return result;
}
/* measured: closes the no_branch_likely-on bracket above. */
#pragma no_branch_likely off
/* measured: closes the schedule-on probe above. */
#pragma schedule off
/* measured: schedule and branch-shape probes for b450. */
#pragma schedule on
/* measured: retail uses a plain beqz for the initialization test. */
#pragma no_branch_likely on

// FUN_0039AE90
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039ae90);
// FUN_0039AF40
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039af40);
// FUN_0039B080
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b080);
// FUN_0039B210
s32 func_0039b210(u8 *arg0)
{
    s32 value;
    s32 result;

    value = *(s32 *)(arg0 + iGpffffb5f0);
    if (value != 0) {
        result = 4;
        result += value * 0x14;
        return result;
    }
    return 0;
}
// FUN_0039B250
f32 func_0039b250(s32 arg0, f32 fparg0)
{
    f32 result;
    u8 **temp_3;
    u8 *temp_2;

    temp_3 = (u8 **)(arg0 + iGpffffb5ec);
    temp_2 = *temp_3;
    result = fparg0 - *(f32 *)(temp_2 + 8);
    if (result < 0.0f) {
        result = 0.0f;
    }
    *temp_3 = *(u8 **)(temp_2 + 0x10);
    return result;
}
// FUN_0039B290
s32 func_0039b290(s32 arg0)
{
    u8 *p;

    p = (u8 *)(arg0 + iGpffffb5f0);
    *(s32 *)(p + 0) = 0;
    *(s32 *)(p + 8) = 0;
    *(s32 *)(p + 4) = (s32)func_0039b250;
    return arg0;
}
// FUN_0039B2C0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b2c0);
// FUN_0039B380
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b380);
// FUN_0039B450
s32 func_0039b450(s32 arg0)
{
    if (D_00884AC8[0] == 0) {
        goto init;
    }
increment:
    D_00884AC8[0] += 1;
    return arg0;
init:
    func_0039ba80((s32)&D_00884ACC);
    goto increment;
}
/* measured: closes the no_branch_likely-on b450 probe. */
#pragma no_branch_likely off
/* measured: closes the schedule-on b450 probe. */
#pragma schedule off
/* measured: schedule and branch-shape probes for b4b0. */
#pragma schedule on
/* measured: retail uses a plain beqz for the zero-count test. */
#pragma no_branch_likely on

// FUN_0039B4B0
s32 func_0039b4b0(s32 arg0)
{
    s32 temp;

    temp = D_00884AC8[0] - 1;
    D_00884AC8[0] = temp;
    if (temp == 0) {
        goto init;
    }
ret:
    return arg0;
init:
    func_0039b830((s32)&D_00884ACC);
    goto ret;
}
/* measured: closes the no_branch_likely-on b4b0 probe. */
#pragma no_branch_likely off
/* measured: closes the schedule-on b4b0 probe. */
#pragma schedule off

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039B510
s32 func_0039b510(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 8) = func_0039b6e0(arg3);
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
// scheduler (plain -O2 emits a 56B frame; schedule on or
// optimization_level 3 both give the exact 48B shape). arg1/arg2 are
// hidden params: retail moves arg3 ($a3) into the callee's $a0.

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039B540
s32 func_0039b540(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 0x6C) = func_0039b6e0(arg3);
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


// measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
// scheduler (plain -O2 emits a 56B frame; schedule on or
// optimization_level 3 both give the exact 48B shape). arg1/arg2 are
// hidden params: retail moves arg3 ($a3) into the callee's $a0.

/* measured: -O3 is load-bearing for this body - flipping the whole file to
   -O2 regressed 8 matched functions here. Bracketed per function so it cannot
   reach the INCLUDE_ASM functions below, which it silently did before. */
#pragma optimization_level 3
// FUN_0039B570
s32 func_0039b570(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 0x7C) = func_0039b6e0(arg3);
    return 1;
}
/* measured: closes the bracket above at the -O2 baseline. */
#pragma optimization_level 2


/* measured: the explicit retail-layout labels reproduce the shared
   b8d0 call site and the backward zero-path branch; D_00884ADC[] forces
   retail's absolute lui/lw argument materialization. optimization_level 3
   supplies the 0x20 frame and no_branch_likely on supplies plain beqz/b.
   Committed at nd 0. */

/* measured: optimization_level 3 is probed for b680 frame and call shape. */
#pragma optimization_level 3
/* measured: no_branch_likely on is probed for b680 plain dispatch. */
#pragma no_branch_likely on

// FUN_0039B5A0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b5a0);
// FUN_0039B680
s32 func_0039b680(s32 arg0)
{
    s32 base;

    base = (s32)D_00884ACC;
    if (*(s32 *)base == 0) {
        goto zero;
    }
call:
    func_0039b8d0(base, arg0);
    goto done;
zero:
    base = func_0039b7c0(base, D_00884ADC[0]);
    goto call;
done:
    return arg0;
}
/* measured: closes no_branch_likely-on b680 probe. */
#pragma no_branch_likely off
/* measured: closes optimization-level 3 b680 probe. */
#pragma optimization_level 2

/* measured: the body below is a faithful reconstruction whose residual is
   recorded in the notes above; re-measured for nd_audit coverage.
   Committed at nd 42. */
/* measured: schedule and plain-branch probes for b6e0. */
#pragma schedule on
/* measured: retail uses plain beqz/b, not blikely branches. */
#pragma no_branch_likely on
// FUN_0039B6E0
s32 func_0039b6e0(s32 arg0)
{
    u8 *temp_2;

    temp_2 = (u8 *)func_0039bb70((void *)D_00884ACC, arg0);
    if (temp_2 == NULL) {
        goto ret0;
    }
    goto retval;
retval:
    return *(s32 *)(temp_2 + 0x10);
ret0:
    return 0;
}
/* measured: closes the no_branch_likely-on b6e0 probe. */
#pragma no_branch_likely off
/* measured: closes the schedule-on b6e0 probe. */
#pragma schedule off

// FUN_0039B720
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b720);
// FUN_0039B7C0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b7c0);
// FUN_0039B830
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b830);
// FUN_0039B8D0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039b8d0);
// FUN_0039BA80
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039ba80);
// FUN_0039BB70
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039bb70);
// FUN_0039BBD0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039bbd0);
// FUN_0039BDF0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039bdf0);
// FUN_0039BEB0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039beb0);
// FUN_0039C000
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039c000);
// FUN_0039C360
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039c360);
// FUN_0039C730
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039c730);
// FUN_0039C900
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039c900);
// FUN_0039CB80
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039cb80);
// FUN_0039D360
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039d360);
// FUN_0039DCC0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039dcc0);
// FUN_0039E740
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039e740);
// FUN_0039F050
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039f050);
// FUN_0039F0E0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039f0e0);
// FUN_0039F160
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039f160);
// FUN_0039F9D0
INCLUDE_ASM("asm/nonmatchings/code1_0039", func_0039f9d0);