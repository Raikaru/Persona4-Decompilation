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

extern s32 iGpffffb614;
extern s32 iGpffffb610;
extern void func_003a3d50(u8 *arg0);
extern void func_003a3de0(u8 *arg0);
extern s32 func_003e8930(s32 a, s32 b, void *c, void *d);
extern s32 func_003c1ab0(s32 a, s32 b, void *c, void *d, s32 e);
extern void func_003e1ea0(s32 arg0);
extern void func_003a2ce0(void);
extern void func_003a2d90(void);
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
extern s32 D_007084A0[];
extern void func_003b42e0(s32 arg0, u8 *arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5, s32 arg6);
extern void func_003a76c0(u8 *arg0, s32 *arg2, s32 arg4);
extern void func_003a72a0(void);


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
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off




// FUN_003A14F0
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
// measured: closes schedule-on probe at the file's schedule-off baseline.
#pragma schedule off
// FUN_003A2950
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2950);
// FUN_003A29F0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a29f0);
// FUN_003A2AD0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2ad0);
// FUN_003A2BB0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2bb0);
// FUN_003A2CE0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2ce0);
// FUN_003A2D90
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2d90);
// FUN_003A2E60
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2e60);
// FUN_003A3050
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3050);
// FUN_003A3500
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3500);
// FUN_003A3670
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3670);
// FUN_003A3D50
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3d50);
// FUN_003A3DE0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a3de0);
// FUN_003A3E90
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
// FUN_003A5180
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5180);
// FUN_003A5280
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a5280);
// FUN_003A55A0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a55a0);
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
// FUN_003A6570
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a6570);
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
/* Measured compiled-C park: schedule-on reaches the retail preheader and delay
   slot ordering; object 188B / window 192B, normalized_diff 17. Committed at nd 17. */
// measured: opening schedule-on bracket for the parked func_003a7970 probe.
// FUN_003A7970 NONMATCHING
#ifdef NON_MATCHING
#pragma schedule on
s32 func_003a7970(u8 *arg0, u8 *arg1)
{
    s32 temp_10;
    s32 temp_4;
    s32 temp_8;
    s32 temp_9;
    u8 *temp_16;
    u8 *temp_14;
    u8 *temp_2;

    temp_14 = *(u8 **)(arg0 + 0x2C);
    temp_4 = *(s32 *)(arg0 + 8);
    temp_16 = *(u8 **)(temp_4 + iGpffffb610);
    temp_2 = *(u8 **)(temp_16 + 0x9C);
    *(s32 *)(temp_2 + (*(s32 *)(temp_2 + 0xE4) * 0x24) + 0x140) =
        *(s32 *)(arg1 + 4);
    *(s32 *)(temp_2 + (*(s32 *)(temp_2 + 0xE4) * 0x24) + 0x154) =
        *(s32 *)(arg1 + 0);
    temp_9 = *(s32 *)(temp_2 + 0xE4);
    temp_10 = *(s32 *)(arg1 + 8);
    temp_8 = temp_9 * 0x24;
    *(s32 *)(temp_2 + temp_8 + 0x160) = temp_10;
    *(void (**)(u8 *, s32 *, s32))(temp_16 + 0x24) = func_003a76c0;
    func_003b42e0(temp_4, temp_16 + 0x50,
                  ((u32)*(s32 *)(temp_14 + 4) >> 2), 0xEFFFFFFF,
                  temp_8, temp_9, temp_10);
    *(void (**)(u8 *, s32 *, s32))(temp_16 + 0x24) =
        (void (*)(u8 *, s32 *, s32))func_003a72a0;
    return 1;
}
// measured: closes schedule-on bracket for the parked func_003a7970 probe.
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a7970);
#endif
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
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a8640);
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
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a92d0);
// FUN_003A93B0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a93b0);
// FUN_003A9880
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a9880);
// FUN_003A9C70
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a9c70);
// FUN_003A9E50
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a9e50);
// FUN_003A9F40
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a9f40);
// FUN_003AA0B0
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003aa0b0);
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