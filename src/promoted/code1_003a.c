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

extern s32 D_00708460[];
extern s32 iGpffffb614;
extern s32 iGpffffb610;
extern s32 func_003e8930(s32 a, s32 b, void *c, void *d);
extern s32 func_003c1ab0(s32 a, s32 b, void *c, void *d, s32 e);
extern void func_003a2ce0(void);
extern void func_003a2d90(void);
extern void func_003a15e0(void);
extern void func_003a1600(void);
extern u8 *func_003a2390();
extern s32 func_003a20e0();

extern void func_003c02e0(void);


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

/* measured fallback: direct C reached normalized_diff 44, object 76/80;
   archive: build/WALastMile1_code1a_park_archive.json. */
// FUN_003A2340 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_003a", func_003a2340);
// measured: closing bracket for the schedule-on above; satisfies decomp_lint
// P001 balance and restores the -O2 default for any following code.
#pragma schedule off


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
