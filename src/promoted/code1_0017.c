#include "include_asm.h"
#include "type.h"
extern void func_0015f660();

extern void (*jtbl_008873EC[])(u8 *arg0);

extern s32 func_0029d020(void);
extern s32 func_00110f00(void);
extern void func_0029cf50(s32 arg0);

extern s32 func_0029cc00(s32 arg0);
extern u8 *func_0029d040(void);
extern void func_002bd240(s32 arg0);
extern void func_002bd270(s32 arg0);
extern void func_002bd280(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern u8 *D_007643D0;

extern u8 *func_004571a0(void);
extern u8 *func_004571b0(void);
extern u8 *func_004571c0(void);



/* measured: ONE real defect, and it is the `slt $at` family. Retail emits
   `slti $at,$v0,4; bnez $at` where b210 emits `slti $v0,$v0,4; bnez $v0`,
   reusing the dead call result as the comparison destination. obj 92B vs
   window 96B, so the reported count also includes one padding word.
   `#pragma schedule off` and hoisting the call result into a local both leave
   it unchanged.

   Do NOT record this as a blanket floor. A census of the retail image shows the
   $at form in 276 first-party functions that ALREADY MATCH, so it is reachable
   from C -- it appears when the comparison feeds a short-circuit `&&`/`||`
   chain, or when its source register is still live afterwards (see the matched
   datCalc func_00231ef0: `if (arg1 > 99 && !(*(u16 *)arg0 & 4))` compiles to
   `andi $v1; slti $at,$v1,0x64; bnez $at`). What is NOT reachable is this
   shape: a single bare comparison on a dead call result, where b210 always
   recycles the source register. 359 of the remaining first-party ASM functions
   contain an $at comparison, so the distinction is worth knowing before writing
   any of them off. */
// FUN_00176220 NONMATCHING
#ifdef NON_MATCHING
s32 func_00176220(void)
{
    if (func_0029d020() >= 4) {
        func_0029cf50(func_00110f00());
        return 1;
    }
    func_0029cf50(0);
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_00176220);
#endif

// FUN_00176280
void func_00176280(void)
{
    func_0015f660();
}

// FUN_001788E0
s32 func_001788e0(void)
{
    s32 temp_17;
    s32 temp_16;

    temp_17 = func_0029cc00(0);
    temp_16 = func_0029cc00(1);
    func_002bd240(1);
    func_002bd270(*(s32 *)(func_0029d040() + 0x124));
    func_002bd280(temp_17, temp_16, 0, 0);
    return 1;
}



// FUN_00178C00
/* Returns the stored constant: retail materializes the 1 in $v0 and stores
   from there, which only happens when it is also the return value. */
s32 func_00178c00(void)
{
    *(s32 *)(D_007643D0 + 8) = 1;
    D_007643D0 = 0;
    return 1;
}



/* The __FILE__ evidence groups 0x0017B510..0x0017CCC0 as one translation unit
   named k_shadow.c (tu_audit HIGH, score 5). The existing
   src/Kosaka/Field/k_shadow.c is a different, already-linked TU at
   0x001026B0, so these stay here with their two group siblings until the
   real TU is split out. They were canonical windows with no marker, i.e.
   invisible to the verifier and supplied to the link as retail bytes. */

// FUN_0017B510
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017b510);

// FUN_0017B990
void func_0017b990(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0017B9A0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017b9a0);

// FUN_0017BB50
void func_0017bb50(u8 *arg0, u8 *arg1)
{
    *(s32 *)(arg1 + 0x3C) = func_004571b0()[2];
    func_004571b0()[2] = 0;
    func_004571b0();
    *(s32 *)(arg1 + 0x38) = func_004571c0()[2];
    func_004571c0()[2] = 0;
    func_004571c0();
    *(s32 *)(arg1 + 0x34) = func_004571a0()[2];
    func_004571a0()[2] = 0;
    func_004571a0();
}



// FUN_0017BBE0
void func_0017bbe0(u8 *arg0, u8 *arg1)
{
    u8 temp_16;

    temp_16 = arg1[0x3C];
    func_004571b0()[2] = temp_16;
    func_004571b0();
    temp_16 = arg1[0x38];
    func_004571c0()[2] = temp_16;
    func_004571c0();
    temp_16 = arg1[0x34];
    func_004571a0()[2] = temp_16;
    func_004571a0();
}

// FUN_0017BC60
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017bc60);

// FUN_0017C010
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c010);

// FUN_0017C270
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c270);

// FUN_0017C670
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c670);

// FUN_0017C930
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017c930);

// FUN_0017CC90
void func_0017cc90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0017CCC0
INCLUDE_ASM("asm/nonmatchings/code1_0017", func_0017ccc0);

