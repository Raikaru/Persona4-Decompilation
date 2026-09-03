#include "include_asm.h"
#include "type.h"

extern s32 *D_008864B8[];
extern void func_0039c730(void);
extern void func_003d0970(u8 *arg0);
extern void func_0039cb80(u8 *arg0);
extern void func_0039d360(u8 *arg0);
extern void func_0039dcc0(u8 *arg0);
extern void func_0039e740(u8 *arg0);
extern s32 func_003a03a0(u8 *arg0);
extern s32 func_003a0aa0(u8 *arg0);
extern s32 func_003a8d20(u8 *arg0, u8 **arg1);

extern s32 iGpffffb614;
extern s32 iGpffffb610;
extern s64 iGpffffb8d0;
extern s32 iGpffffb94c;
extern s32 iGpffffb730;
extern s32 iGpffffb934;
extern u8 iGpffffb984;
extern s32 func_0040f570();
extern void func_00410390();
extern void func_003a3d50(u8 *arg0);
extern void func_003a3de0(u8 *arg0);
extern s32 func_003e8930(s32 a, s32 b, void *c, void *d);
extern s32 func_003c1ab0(s32 a, s32 b, void *c, void *d, s32 e);
extern void func_003a4d50();
extern void func_003e1ea0(s32 arg0);
extern s32 func_003a2ce0(s32 arg0);
extern s32 func_003a2d90(s32 arg0);
extern s32 func_003a15e0(s32 arg0);
extern u8 *func_003a1600(u8 *arg0);

extern void func_003c02e0(void);
extern void func_003c42b0(void *arg0, s32 arg1);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern s32 func_004115d0(void);
extern void func_00411670(s32 arg0);
extern s32 func_004125e0(s32 arg0);
extern s32 func_00412ca0(s32 arg0);
extern s32 func_00412fb0(s32 arg0, s32 arg1, void *arg2, s32 arg3);
extern u8 *func_003cf9b0(u8 *arg0, s32 arg1, void *arg2);
extern s32 *func_003cfa70(void);
extern s32 func_00412e90(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 D_007084A0[];
extern void func_003a76c0(u8 *arg0, s32 *arg2, s32 arg4);
extern u8 D_008872E0[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern s32 func_003a8500(u8 *arg0);
extern s32 func_003a7160(u8 *arg0);
extern s32 func_003a6ba0(void);
extern s32 func_003a7f80(void);
extern u8 *func_003bfae0();
extern s32 **func_003ce050();
extern u8 *func_003cfa30();
extern s32 func_003a8ca0(void);
extern s32 func_003a92d0(void);
extern void func_003a72a0(void);
extern void func_003a55a0(u8 *arg0, u8 *arg1, s32 *arg2, u8 *arg3,
                          u32 arg4);
extern void func_003a5280();
extern void func_003b0b80(void);
extern void func_003b12a0(void);
extern void func_003b1a10(void);
extern void func_003b31a0(void);
extern void func_003b3240(void);
extern void func_003b3570(void);
extern void func_003b3880(void);
extern void func_003b3f50(void);
extern void func_003b4020(void);
extern void func_003b4120(void);
extern void func_003b4230(void);
extern void func_003b6680(void);
extern void func_003b6cb0(void);
extern void func_003aa9f0(void);
extern void func_003ab100(void);
extern void func_003abf60(void);
extern void func_003aa370(void);
extern void func_003adc40(void);
extern void func_003acb10(void);
extern void func_003aed60(void);
extern void func_003af990(void);




// measured: b210 at -O2 leaves branch/jal delay slots unfilled and orders the
// prologue after the global-address load; schedule on reproduces retail order.
#pragma schedule on


// FUN_003A0260
void func_003a0260(u8 *arg0)
{
    if (D_008864B8[0] != NULL) {
        func_0039c730();
    }
    func_003d0970(arg0);
}
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off


// measured: b210 at -O2 leaves branch/jal delay slots unfilled and orders the
// prologue after the global-address load; schedule on reproduces retail order.
#pragma schedule on


// FUN_003A02A0
void func_003a02a0(u8 *arg0)
{
    if (D_008864B8[0] != NULL) {
        func_0039c730();
    }
    func_0039cb80(arg0);
}
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off


// measured: b210 at -O2 leaves branch/jal delay slots unfilled and orders the
// prologue after the global-address load; schedule on reproduces retail order.
#pragma schedule on


// FUN_003A02E0
void func_003a02e0(u8 *arg0)
{
    if (D_008864B8[0] != NULL) {
        func_0039c730();
    }
    func_0039d360(arg0);
}
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off


// measured: b210 at -O2 leaves branch/jal delay slots unfilled and orders the
// prologue after the global-address load; schedule on reproduces retail order.
#pragma schedule on


// FUN_003A0320
void func_003a0320(u8 *arg0)
{
    if (D_008864B8[0] != NULL) {
        func_0039c730();
    }
    func_0039dcc0(arg0);
}
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off


// measured: b210 at -O2 leaves branch/jal delay slots unfilled and orders the
// prologue after the global-address load; schedule on reproduces retail order.
#pragma schedule on


// FUN_003A0360
void func_003a0360(u8 *arg0)
{
    if (D_008864B8[0] != NULL) {
        func_0039c730();
    }
    func_0039e740(arg0);
}
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off




// FUN_003A03A0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a03a0);
// FUN_003A0AA0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a0aa0);
// measured: b210 at -O2 leaves branch/jal delay slots unfilled and orders the
// prologue after the global-address load; schedule on reproduces retail order.
#pragma schedule on
// FUN_003A1470
void func_003a1470(u8 *arg0)
{
    if (D_008864B8[0] != NULL) {
        func_0039c730();
    }
    func_003a03a0(arg0);
}
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off


// measured: b210 at -O2 leaves branch/jal delay slots unfilled and orders the
// prologue after the global-address load; schedule on reproduces retail order.
#pragma schedule on


// FUN_003A14B0
void func_003a14b0(u8 *arg0)
{
    if (D_008864B8[0] != NULL) {
        func_0039c730();
    }
    func_003a0aa0(arg0);
}
#pragma schedule off




// FUN_003A14F0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a14f0);
// measured: schedule on preserves retail's callback setup order for func_003a15e0.
#pragma schedule on
// FUN_003A15E0
s32 func_003a15e0(s32 arg0)
{
    *(s32 *)(arg0 + iGpffffb610) = 0;
    return arg0;
}
// measured: closes schedule-on bracket for func_003a15e0.
#pragma schedule off
// measured: no_branch_likely on reproduces retail's plain beqz tests.
#pragma no_branch_likely on
// measured: schedule on preserves retail's callback setup order for func_003a1600.
#pragma schedule on
// FUN_003A1600
u8 *func_003a1600(u8 *arg0)
{
    if (*(u8 **)(arg0 + iGpffffb610) != NULL) {
        func_003c42b0(*(void **)(*(void **)(*(u8 **)(arg0 + 0x18) + 0x20)), 0);
        if (*(s32 *)(*(u8 **)(arg0 + iGpffffb610) + 0xC) != 0) {
            func_003a3de0(arg0);
            func_003a3d50(arg0);
            (*jtbl_008873EC)(*(u8 **)(*(u8 **)(arg0 + iGpffffb610) + 0xC));
        }
        (*jtbl_008873EC)(*(u8 **)(arg0 + iGpffffb610));
        *(s32 *)(arg0 + iGpffffb610) = 0;
    }
    return arg0;
}
// measured: closes schedule-on bracket for func_003a1600.
#pragma schedule off
// measured: closes no_branch_likely for func_003a1600.
#pragma no_branch_likely off
// measured: schedule on reproduces retail's filled delay slots and second-call
// argument materialization order (lui before the moves, addiu in the jal slot).
#pragma schedule on
// FUN_003A16C0
s32 func_003a16c0(void) {
    iGpffffb614 = func_003e8930(4, 0x12F, (void *)func_003a2ce0, (void *)func_003a2d90);
    if (iGpffffb614 < 0) {
        return 0;
    }
    iGpffffb610 = func_003c1ab0(4, 0x12F, (void *)func_003a15e0, (void *)func_003a1600, 0);
    return iGpffffb610 >= 0;
}
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off

// FUN_003A1730
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a1730);
// FUN_003A1C40
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a1c40);
// FUN_003A20E0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a20e0);
// FUN_003A2290
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2290);
// FUN_003A2340
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2340);



// FUN_003A2390
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2390);
// measured: b210 at -O2 refuses tail-call collapse and leaves the jr delay
// slot unfilled; schedule on + O3 reproduce retail's `j func_003c02e0` tail
// call with its nop slot.
#pragma schedule on
// measured: the same tail-call measurement as the schedule pragma directly
// above; level 3 is what actually collapses the call.
#pragma optimization_level 3
// FUN_003A2760
void func_003a2760(void)
{
    func_003c02e0();
}
// measured: closing bracket for the schedule-on/O3 above; satisfies
// decomp_lint P001 balance and restores the -O2 default.
#pragma schedule off

// FUN_003A2770
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2770);
// measured: schedule on probe for 003a2920 delay-slot and register order.
#pragma schedule on
// FUN_003A2920
s32 func_003a2920(s32 arg0)
{
    u8 *temp_5;
    temp_5 = *(u8 **)(arg0 + iGpffffb610);
    *(s32 *)(temp_5 + 0x40) = *(s32 *)(temp_5 + 0x40) | *(s32 *)(temp_5 + 0x3c);
    *(s32 *)(temp_5 + 0x3c) = 0;
    return arg0;
}
// measured: closes the schedule bracket opened above func_003a2920.
#pragma schedule off
// FUN_003A2950
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2950);
// FUN_003A29F0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a29f0);
// measured: schedule on for 003a2ad0 materialization order.
#pragma schedule on
// measured: no-branch-likely keeps 2ad0 dispatches as plain beq tests.
#pragma no_branch_likely on
// FUN_003A2AD0
s32 func_003a2ad0(u8 *arg0, u8 *arg1)
{
    u8 *temp_6;
    u32 temp_4;
    u32 temp_3;
    u32 temp_3_2;
    u64 var_7 = 0;

    if (arg1 == NULL)
    {
        goto block_17;
    }
    temp_6 = *(u8 **)(arg0 + 0x4C);
    temp_4 = *(s32 *)(arg1 + 0x50);
    temp_3 = (temp_4 & 0xF00) >> 8;
    switch (temp_3)
    {
    case 1:
        var_7 = 0;
        var_7 &= (s64)-4;
        goto block_9;
    case 3:
        var_7 |= 1;
        goto block_9;
    case 2:
        goto block_0;
    case 4:
        goto block_0;
    default:
        goto block_0;
    }
block_0:
    return 0;
block_9:
    temp_3_2 = (temp_4 & 0xF000) >> 0xC;
    switch (temp_3_2)
    {
    case 1:
        var_7 &= (s64)-0xD;
        goto block_16;
    case 3:
        var_7 |= 4;
        goto block_16;
    case 2:
        goto block_18;
    case 4:
        goto block_18;
    default:
        goto block_18;
    }
block_16:
    *(s64 *)(temp_6 + 0xC0) = var_7;
block_17:
    return 1;
block_18:
    return 0;
}
// measured: closes the 003a2ad0 schedule-on probe.
#pragma schedule off
// measured: closes no-branch-likely for func_003a2ad0.
#pragma no_branch_likely off
// FUN_003A2BB0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2bb0);
// measured: schedule-on probe for func_003a2ce0 prologue and callback setup.
#pragma schedule on
// measured: no_branch_likely keeps the allocation-null test as a plain beqz.
#pragma no_branch_likely on
// FUN_003A2CE0
s32 func_003a2ce0(s32 arg0)
{
    u8 *temp_2;

    temp_2 = (u8 *)(*jtbl_008873E8)(0x18, 0x4012F);
    if (temp_2 != NULL) {
        *(u8 **)(D_008872E0 + iGpffffb614) = temp_2;
        *(s32 *)(temp_2 + 4) = 0;
        *(s32 *)(temp_2 + 8) = 0;
        *(s32 *)(temp_2 + 0xC) = 0;
        *(s32 *)(temp_2 + 0x10) = 0;
        *(s32 *)(temp_2 + 0x14) = 0;
        func_003a8500(temp_2);
        func_003a7160(temp_2);
        *(s32 *)(temp_2 + 0) = func_003a8ca0();
        *(s32 *)(temp_2 + 0x14) = func_003a92d0();
        return arg0;
    }
    return 0;
}
// measured: closes schedule-on probe for func_003a2ce0.
// measured: closes no_branch_likely for func_003a2ce0.
#pragma no_branch_likely off
#pragma schedule off
// measured: schedule-on preserves 003a2d90's global setup and callback order.
#pragma schedule on
// measured: no_branch_likely keeps the six cleanup tests as plain beqz.
#pragma no_branch_likely on
// FUN_003A2D90
s32 func_003a2d90(s32 arg0)
{
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 temp_4_6;
    u8 *temp_17;

    temp_17 = *(u8 **)(D_008872E0 + iGpffffb614);
    if (temp_17 != NULL) {
        temp_4 = *(s32 *)(temp_17 + 8);
        if (temp_4 != 0) {
            func_00411670(temp_4);
        }
        temp_4_2 = *(s32 *)(temp_17 + 4);
        if (temp_4_2 != 0) {
            func_00411670(temp_4_2);
        }
        temp_4_3 = *(s32 *)(temp_17 + 0x10);
        if (temp_4_3 != 0) {
            func_00411670(temp_4_3);
        }
        temp_4_4 = *(s32 *)(temp_17 + 0xC);
        if (temp_4_4 != 0) {
            func_00411670(temp_4_4);
        }
        temp_4_5 = *(s32 *)(temp_17 + 0x14);
        if (temp_4_5 != 0) {
            func_00411670(temp_4_5);
        }
        temp_4_6 = *(s32 *)(temp_17 + 0);
        if (temp_4_6 != 0) {
            func_00411670(temp_4_6);
        }
        (*jtbl_008873EC)(temp_17);
    }
    return arg0;
}
// measured: closes no_branch_likely for func_003a2d90.
#pragma no_branch_likely off
// measured: closes schedule-on for func_003a2d90.
#pragma schedule off
// FUN_003A2E60
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2e60);
// FUN_003A3050
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3050);
// FUN_003A3500
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3500);
// FUN_003A3670
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3670);
/* measured: schedule on fills the loop back-edge delay slot and the jr $ra delay slot for func_003a3d50. */
#pragma schedule on
// FUN_003A3D50
void func_003a3d50(u8 *arg0)
{
    s32 count;
    u8 *base;
    u8 *list;
    u8 *node;

    base = *(u8 **)(arg0 + iGpffffb610);
    if ((*(s32 *)(base + 0x44) & 0x10) == 0) {
        list = *(u8 **)(base + 0x9C);
        count = 0;
        node = list;
        do {
            if (*(s32 *)(node + 0x138) != 0) {
                func_003e1ea0(*(s32 *)(node + 0x138));
                *(s32 *)(node + 0x138) = 0;
            }
            node += 4;
        } while ((u32)*(s32 *)(list + 0xE8) >= (u32)++count);
    }
}
/* measured: closing schedule for func_003a3d50. */
#pragma schedule off
// FUN_003A3E90 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3e90);
// FUN_003A4270
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a4270);
// FUN_003A45C0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a45c0);
// FUN_003A4850
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a4850);
// FUN_003A4AB0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a4ab0);
// FUN_003A4D50
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a4d50);
// FUN_003A5180 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5180);
// FUN_003A5280
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5280);
/* measured: schedule on fills the beq/jal/b delay slots (move $s3, move $a0,
   the trailing sw) and puts `ld $ra` in the exit branch's slot; the file is
   schedule-off here. */
#pragma schedule on
/* measured: no_branch_likely on keeps the flag stores as plain bnez/nop. */
#pragma no_branch_likely on
/* The offset-first `addu $a0,$a0,$s1` needs the operands to travel through a
   helper's parameters; a plain `idx * 0x24 + base` is canonicalised to
   base-first (the k_encount encSlot lever). The goto chain reproduces
   retail's out-of-line flag bodies, and the `goto dispatch_end` from the last
   body is what makes the exit a shared backward branch. */
static inline u32 slot_003a55a0(u32 offset, u32 base)
{
    return offset + base;
}
// FUN_003A55A0
void func_003a55a0(u8 *arg0, u8 *arg1, s32 *arg2, u8 *arg3, u32 arg4)
{
    extern void func_003a2bb0(s32 *arg0);
    extern void func_003f4370(void);
    u8 *base;
    s32 idx;

    base = *(u8 **)(arg2 + 0x4C / 4);
    idx = *(s32 *)(base + 0xE4);
    if (arg4 & 0x10000000) {
        func_003a2bb0(arg2);
    }
    func_003f4370();
    *(s32 *)(arg0 + 8) = ((arg4 & 2) == 2) || ((arg4 & 0x2000) == 0x2000);
    *(s32 *)(arg0 + 4) = ((arg4 & 0x80) == 0x80) || ((arg4 & 0x80000) == 0x80000);
    *(s32 *)(arg0 + 0) = 1;
    *(s32 *)(arg0 + 0xC) = ((arg4 & 4) == 4) || ((arg4 & 0x4000) == 0x4000);
    if (*(s32 *)(arg0 + 0) != 0) {
        goto block_0;
    }
dispatch_8:
    if (*(s32 *)(arg0 + 8) != 0) {
        goto block_8;
    }
dispatch_4:
    if (*(s32 *)(arg0 + 4) != 0) {
        goto block_4;
    }
dispatch_c:
    if (*(s32 *)(arg0 + 0xC) != 0) {
        goto block_c;
    }
dispatch_end:
    return;
block_0:
    *(s32 *)(arg0 + 0x10) = *(s32 *)((u8 *)slot_003a55a0(idx * 0x24, (u32)base) + 0x140);
    *(s32 *)(arg0 + 0x14) = 0x10;
    goto dispatch_8;
block_8:
    *(s32 *)(arg0 + 0x20) = *(s32 *)((u8 *)slot_003a55a0(idx * 0x24, (u32)base) + 0x150);
    *(s32 *)(arg0 + 0x24) = 4;
    goto dispatch_4;
block_4:
    *(s32 *)(arg0 + 0x18) = *(s32 *)((u8 *)slot_003a55a0(idx * 0x24, (u32)base) + 0x15C);
    *(s32 *)(arg0 + 0x1C) = 0x10;
    goto dispatch_c;
block_c:
    *(s32 *)(arg0 + 0x28) = *(s32 *)((u8 *)slot_003a55a0(idx * 0x24, (u32)base) + 0x14C);
    *(s32 *)(arg0 + 0x2C) = 8;
    goto dispatch_end;
}
/* measured: closes both scopes after func_003a55a0. */
#pragma no_branch_likely off
#pragma schedule off
// FUN_003A5740
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5740);
// FUN_003A5940
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5940);
// FUN_003A5B50
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5b50);
// FUN_003A5DC0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5dc0);
// FUN_003A5FE0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5fe0);
// FUN_003A6230
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a6230);
// FUN_003A63B0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a63b0);
// measured: probe schedule-on for 003a6570's preheader constants.
#pragma schedule on
// FUN_003A6570
s32 func_003a6570(u8 *arg0, u8 *arg1)
{
    s32 temp_10;
    s32 temp_4;
    s32 temp_7;
    s32 temp_8;
    s32 temp_9;
    s32 temp_11;
    s32 temp_12;
    s32 mask = 0xEFFFFFFF;
    void (*callback)(u8 *, u8 *, s32 *, u8 *, u32) = func_003a55a0;
    u8 *temp_14;
    u8 *temp_16;
    u8 *temp_2;
    temp_14 = *(u8 **)(arg0 + 0x2C);
    temp_4 = *(s32 *)(arg0 + 8);
    temp_16 = *(u8 **)(temp_4 + iGpffffb610);
    temp_2 = *(u8 **)(temp_16 + 0x9C);
    temp_7 = *(s32 *)(temp_2 + 0xE4) * 0x24;
    *(s32 *)((s32)temp_7 + (s32)temp_2 + 0x140) =
        *(s32 *)(arg1 + 0xC);
    temp_11 = *(s32 *)(temp_2 + 0xE4) * 0x24;
    *(s32 *)((s32)temp_11 + (s32)temp_2 + 0x150) =
        *(s32 *)(arg1 + 0);
    temp_12 = *(s32 *)(temp_2 + 0xE4) * 0x24;
    *(s32 *)((s32)temp_12 + (s32)temp_2 + 0x14C) =
        *(s32 *)(arg1 + 4);
    temp_9 = *(s32 *)(temp_2 + 0xE4);
    temp_10 = *(s32 *)(arg1 + 8);
    temp_8 = temp_9 * 0x24;
    *(s32 *)((s32)temp_8 + (s32)temp_2 + 0x15C) = temp_10;
    *(void (**)(u8 *, u8 *, s32 *, u8 *, u32))(temp_16 + 0x24) = callback;
    func_003b42e0(temp_4, temp_16 + 0x50,
                  *(s32 *)(temp_14 + 4), mask);
    *(void (**)(void))(temp_16 + 0x24) = func_003a5280;
    return 1;
}
// measured: closes schedule-on probe for 003a6570.
#pragma schedule off
// FUN_003A6650
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a6650);
// FUN_003A6BA0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a6ba0);
// FUN_003A6DF0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a6df0);
// FUN_003A6FB0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a6fb0);
// FUN_003A7160
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a7160);
// FUN_003A72A0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a72a0);
// FUN_003A76C0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a76c0);

// FUN_003A7970
s32 func_003a7970(u8 *arg0, u8 *arg1)
{
    // measured: in-body O3 probe for func_003a7970 code generation.
    #pragma optimization_level 3
    s32 mask = 0xEFFFFFFF;
    void (*callback)(u8 *, s32 *, s32) = func_003a76c0;
    u8 *arg0_2c = *(u8 **)(arg0 + 0x2C);
    s32 temp_4;
    u8 *temp_16;
    u8 *temp_2;
    s32 index;
    s32 temp_10;

    temp_4 = *(s32 *)(arg0 + 8);
    temp_16 = *(u8 **)(temp_4 + iGpffffb610);
    temp_2 = *(u8 **)(temp_16 + 0x9C);
    {
        s32 offset;
        offset = *(s32 *)(temp_2 + 0xE4) * 0x24;
        *(s32 *)((s32)offset + (s32)temp_2 + 0x140) =
            *(s32 *)(arg1 + 4);
    }
    {
        s32 offset;
        offset = *(s32 *)(temp_2 + 0xE4) * 0x24;
        *(s32 *)((s32)offset + (s32)temp_2 + 0x154) =
            *(s32 *)(arg1 + 0);
    }
    index = *(s32 *)(temp_2 + 0xE4);
    temp_10 = *(s32 *)(arg1 + 8);
    {
        s32 offset;
        offset = index * 0x24;
        *(s32 *)((s32)offset + (s32)temp_2 + 0x160) = temp_10;
    }
    *(void (**)(u8 *, s32 *, s32))(temp_16 + 0x24) = callback;
    func_003b42e0(temp_4, temp_16 + 0x50,
                  (u32)*(u32 *)(arg0_2c + 4) >> 2, mask);
    *(void (**)(u8 *, s32 *, s32))(temp_16 + 0x24) =
        (void (*)(u8 *, s32 *, s32))func_003a72a0;
    return 1;
}
// FUN_003A7A30
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a7a30);
// FUN_003A7F80
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a7f80);
// FUN_003A8180
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a8180);
// FUN_003A8340
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a8340);
// FUN_003A8500
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a8500);
// FUN_003A8640
// measured: schedule on / no_branch_likely on / opt_rebuildconditionals off /
// opt_propagation off together reproduce retail's index-refresh branch
// scheduling and delay-slot fills for func_003a8640.
#pragma schedule on
#pragma no_branch_likely on
#pragma opt_rebuildconditionals off
#pragma opt_propagation off
s32 func_003a8640(s32 arg0, u8 *arg1, s32 arg2, s32 arg3)
{
    s32 *work;
    s32 index;
    s32 value;
    s32 flags;
    u8 *dst;
    u8 byte0;
    u8 byte1;
    u8 byte2;
    u8 byte3;
    f32 float0;
    f32 float1;

    extern void func_003a2bb0(u8 *arg0);
    extern void func_0043f810(void *dst, const void *src, u32 size);
    work = *(s32 **)(arg1 + 0x4C);
    flags = arg3;
    if (work[56] == 1) {
        index = work[57];
        if (index >= work[58]) {
            goto wrap_index;
        }
        index += 1;
apply_index:
        work[index + 59] |= flags;
        value = work[work[57] + 59];
        if (value != 0) {
            work[work[57] + 59] = 0;
            flags |= value;
        }
    }
    if (flags == 0) {
        goto done_index;
    }
    if ((flags & 0x10000000) != 0) {
        goto refresh_index;
    }
second_mask:
    if ((flags & 0x80000) != 0 && (*(s32 *)(arg1 + 0x58) & 0x80000) != 0) {
        func_0043f810(*(void **)(arg1 + 0x3C), arg1 + 0x90, 0x10);
    }
    if ((flags & 0x100000) != 0 && (*(s32 *)(arg1 + 0x58) & 0x100000) != 0) {
        func_0043f810(*(void **)(arg1 + 0x44), arg1 + 0x90, 0x20);
    }
    if ((flags & 0x2000) != 0 && (*(s32 *)(arg1 + 0x58) & 0x40042) == 0) {
        dst = *(u8 **)(arg1 + 0x24);
        byte0 = *(u8 *)(arg1 + 0x7C);
        byte1 = *(u8 *)(arg1 + 0x7D);
        byte2 = *(u8 *)(arg1 + 0x7E);
        byte3 = *(u8 *)(arg1 + 0x7F);
        dst[0] = byte0;
        dst[1] = byte1;
        dst[2] = byte2;
        dst[3] = byte3;
    }
    if ((flags & 0x40000) != 0 && (*(s32 *)(arg1 + 0x58) & 0x40000) != 0) {
        func_0043f810(*(void **)(arg1 + 0x2C), arg1 + 0x80, 0x10);
    }
    if ((flags & 0x20000) != 0 && (*(s32 *)(arg1 + 0x58) & 0x20000) != 0) {
        dst = *(u8 **)(arg1 + 0x34);
        *(f32 *)dst = *(f32 *)(arg1 + 0x78);
        *(f32 *)(dst + 4) = *(f32 *)(arg1 + 0x78);
    }
    if ((flags & 0x4000) != 0 && (*(s32 *)(arg1 + 0x58) & 4) == 0) {
        dst = *(u8 **)(arg1 + 0x1C);
        float0 = *(f32 *)(arg1 + 0x70);
        float1 = *(f32 *)(arg1 + 0x74);
        *(f32 *)dst = float0;
        *(f32 *)(dst + 4) = float1;
    }
done_index:
    return 1;
wrap_index:
    index = 0;
    goto apply_index;
refresh_index:
    func_003a2bb0(arg1);
    goto second_mask;
return_index:
    return 1;
}
#pragma opt_propagation on
// measured: closes the schedule/no_branch_likely/rebuildconditionals/
// propagation bracket opened above func_003a8640 and restores the -O2
// baseline for the rest of the file.
#pragma schedule off
#pragma opt_rebuildconditionals on
#pragma no_branch_likely off
// FUN_003A8840
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a8840);
// measured: schedule on places the prologue sq in func_003a8ca0's jal delay slot.
#pragma schedule on
// measured: no_branch_likely on reproduces retail's plain beqz tests.
#pragma no_branch_likely on
// FUN_003A8CA0
s32 func_003a8ca0(void)
{
    s32 temp_2;
    s32 temp_2_2;

    temp_2 = func_004115d0();
    if (temp_2 != 0) {
        temp_2_2 = func_00412ca0(temp_2);
        if ((temp_2_2 != 0) &&
            (func_004125e0(func_00412fb0(temp_2_2, 0, &D_007084A0, 0)) != 0)) {
            return temp_2;
        }
        func_00411670(temp_2);
    }
    return 0;
}
// measured: closes schedule-on bracket for func_003a8ca0.
// measured: closes no_branch_likely for func_003a8ca0.
#pragma no_branch_likely off
// measured: closes schedule-on bracket for func_003a8ca0.
#pragma schedule off
// FUN_003A8D20
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a8d20);
// FUN_003A92D0
// measured: schedule on fills saved-register and call-argument delay slots in func_003a92d0.
#pragma schedule on
// measured: no_branch_likely on keeps func_003a92d0's null tests as plain beqz instructions.
#pragma no_branch_likely on
s32 func_003a92d0(void)
{
    s32 temp_2;
    s32 *temp_2_3;
    s32 temp_2_2;

    temp_2 = func_004115d0();
    if (temp_2 != 0) {
        temp_2_2 = func_00412ca0(temp_2);
        if (temp_2_2 != 0) {
            temp_2_3 = func_003cfa70();
            temp_2_2 = func_00412fb0(temp_2_2, 0, temp_2_3, 0);
            func_00412e90(temp_2_2, *temp_2_3, 0, 0);
            temp_2_2 = func_004125e0(temp_2_2);
            if (temp_2_2 != 0) {
                func_003cf9b0(
                    (u8 *)func_00412e90(temp_2_2, *temp_2_3, 0, 0),
                    1,
                    (void *)func_003a8d20);
                return temp_2;
            }
        }
        func_00411670(temp_2);
        goto block_5;
    }
block_5:
    return 0;
}
// measured: closes no_branch_likely for func_003a92d0.
#pragma no_branch_likely off
// measured: closes the schedule-on bracket for func_003a92d0.
#pragma schedule off
// FUN_003A93B0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a93b0);
// FUN_003A9880
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a9880);
// FUN_003A9C70
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a9c70);
// measured: schedule on fills the call-argument and store delay slots in func_003a9e50.
#pragma schedule on
// measured: no_branch_likely on keeps func_003a9e50's null tests as plain beqz/bnez.
#pragma no_branch_likely on
/* measured: retail keeps two separate `b epilogue; move $v0,$zero` return-0 blocks
   with the NULL-node one placed between the failed-check return and the main body;
   a forward goto over both returns reproduces that layout (nested if/else and
   fall-through forms merge the NULL return into the epilogue, nd61). */
// FUN_003A9E50
s32 func_003a9e50(u8 *arg0)
{
    extern u8 *func_003c2630(s32 arg0, s32 arg1, s32 arg2);
    extern s32 func_003c22f0(u8 *arg0);
    extern void func_003c0210(u8 *arg0, u8 *arg1, s32 arg2);
    extern void func_003c2a80(u8 *arg0);
    extern u8 *func_003c4140(void);
    extern void func_003c4a80(u8 *arg0, u8 *arg1);
    extern void func_003c4220(u8 *arg0);
    u8 *node;
    u8 *frame;
    u8 *sub;
    u8 *state;

    node = func_003c2630(0, 0, 0);
    if (node != NULL) {
        sub = *(u8 **)(node + 0x5C);
        *(s32 *)(sub + 4) = 0;
        *(s32 *)(sub + 8) = 0;
        *(s32 *)(sub + 0xC) = 0;
        *(f32 *)(sub + 0x10) = 1.0f;
        if (func_003c22f0(node) != 0) {
            goto proceed;
        }
        return 0;
    }
    return 0;
proceed:
    func_003c0210(arg0, node, 0);
    func_003c2a80(node);
    frame = func_003c4140();
    func_003c4a80(node + 0x20, frame);
    func_003c4220(frame);
    state = *(u8 **)(arg0 + iGpffffb610);
    *(s32 *)(state + 0x24) = 0;
    *(s32 *)(state + 0x28) = 0;
    *(s32 *)(state + 0x2C) = 0;
    *(s32 *)(state + 0x30) = 0;
    *(s32 *)(state + 0x34) = 0;
    *(s32 *)(state + 0x38) = 0;
    return 1;
}
// measured: closes no_branch_likely for func_003a9e50.
#pragma no_branch_likely off
// measured: closes the schedule-on bracket for func_003a9e50.
#pragma schedule off
// FUN_003A9F40
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a9f40);
// measured: schedule and no_branch_likely preserve retail callback-selection
// branch and delay-slot ordering for func_003aa0b0.
#pragma schedule on
#pragma no_branch_likely on
// FUN_003AA0B0
void func_003aa0b0(s32 arg0)
{
    u8 *obj;
    u8 *obj2;
    s32 flags;
    void (*callback)(void);

    callback = func_003b6680;
    obj = *(u8 **)((u8 *)arg0 + iGpffffb610);
    *(void (**)(void))(obj + 0x24) = callback;
    flags = *(s32 *)(obj + 0xA8);
    obj2 = obj + 0x50;
    if ((flags & 8) == 8) {
        if ((flags & 0x01000000) == 0x01000000) {
            *(void (**)(void))(obj + 0x28) = func_003b12a0;
        } else {
            *(void (**)(void))(obj + 0x28) = func_003b0b80;
        }
    } else if ((flags & 0x8000) == 0x8000) {
        if ((flags & 0x01000000) == 0x01000000) {
            *(void (**)(void))(obj + 0x28) = func_003aa9f0;
        } else {
            *(void (**)(void))(obj + 0x28) = func_003aa370;
        }
    } else if ((flags & 0x20) == 0x20) {
        if ((flags & 4) == 4) {
            if ((flags & 0x01000000) == 0x01000000) {
                *(void (**)(void))(obj + 0x28) = func_003af990;
            } else {
                *(void (**)(void))(obj + 0x28) = func_003acb10;
            }
        } else if ((flags & 0x01000000) == 0x01000000) {
            *(void (**)(void))(obj + 0x28) = func_003adc40;
        } else {
            *(void (**)(void))(obj + 0x28) = func_003ab100;
        }
    } else if ((flags & 4) == 4) {
        if ((flags & 0x01000000) == 0x01000000) {
            *(void (**)(void))(obj + 0x28) = func_003aed60;
        } else {
            *(void (**)(void))(obj + 0x28) = func_003abf60;
        }
    } else if ((flags & 0x01000000) == 0x01000000) {
        *(void (**)(void))(obj + 0x28) = func_003aa9f0;
    } else {
        *(void (**)(void))(obj + 0x28) = func_003aa370;
    }

    flags = *(s32 *)(obj2 + 0x58);
    if ((flags & 0x80) == 0x80) {
        goto stage2_304;
    }
    if ((flags & 0x100) == 0x100) {
        goto stage2_314;
    }
    if ((flags & 0x80000) == 0x80000) {
        goto stage2_324;
    }
    if ((flags & 0x100000) == 0x100000) {
        *(void (**)(void))(obj + 0x2C) = func_003b4120;
        goto stage3;
    }
    *(void (**)(void))(obj + 0x2C) = NULL;

stage3:
    flags = *(s32 *)(obj2 + 0x58);
    if ((flags & 2) == 2) {
        goto stage3_334;
    }
    if ((flags & 0x40) == 0x40) {
        goto stage3_344;
    }
    if ((flags & 0x40000) == 0x40000) {
        *(void (**)(void))(obj + 0x30) = func_003b3240;
        goto stage4;
    }
    *(void (**)(void))(obj + 0x30) = func_003b3570;

stage4:
    flags = *(s32 *)(obj2 + 0x58);
    if ((flags & 0x10) == 0x10) {
        goto stage4_354;
    }
    goto finish;

finish:
    *(void (**)(void))(obj + 0x38) = func_003b6cb0;
    return;

stage2_304:
    *(void (**)(void))(obj + 0x2C) = func_003b3880;
    goto stage3;
stage2_314:
    *(void (**)(void))(obj + 0x2C) = func_003b3f50;
    goto stage3;
stage2_324:
    *(void (**)(void))(obj + 0x2C) = func_003b4020;
    goto stage3;
stage3_334:
    *(void (**)(void))(obj + 0x30) = func_003b1a10;
    goto stage4;
stage3_344:
    *(void (**)(void))(obj + 0x30) = func_003b31a0;
    goto stage4;
stage4_354:
    *(void (**)(void))(obj + 0x34) = func_003b4230;
    goto finish;
}
#pragma no_branch_likely off
#pragma schedule off
// FUN_003AA370
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003aa370);
// FUN_003AA9F0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003aa9f0);
// FUN_003AB100
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003ab100);
// FUN_003ABF60
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003abf60);
// FUN_003ACB10
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003acb10);
// FUN_003ADC40
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003adc40);
// FUN_003AED60
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003aed60);
// FUN_003AF990
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003af990);
