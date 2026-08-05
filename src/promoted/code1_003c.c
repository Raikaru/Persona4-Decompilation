#include "include_asm.h"
#include "type.h"


extern s32 D_007647BC;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 15 -> 0). */

// FUN_003C1D20
#pragma schedule on
s32 func_003c1d20(s32 arg0) {
    D_007647BC--;
    return arg0;
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 13 -> 0). */

// FUN_003C2130
#pragma schedule on
s32 func_003c2130(s32 arg0, u8 *arg1, s16 arg2, s16 arg3, s16 arg4) {
    ((s16 *)arg1)[0] = arg2;
    ((s16 *)arg1)[1] = arg3;
    ((s16 *)arg1)[2] = arg4;
    return arg0;
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colors the halfword scratch $v0; retail fills the slot
   with the final store and colors it $v1 (nd 15 -> 0). */

// FUN_003C2290
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c2290);

// FUN_003C2A60
#pragma schedule on
u8 *func_003c2a60(u8 *arg0) {
    ((s16 *)arg0)[7] = (s16)(((s16 *)arg0)[7] + 1);
    return arg0;
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 11 -> 0). */

// FUN_003C2C90
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c2c90);

// FUN_003C38B0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c38b0);

// FUN_003C3CC0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3cc0);

// FUN_003C3E10
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3e10);

// FUN_003C3F20
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3f20);

// FUN_003C3FA0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c3fa0);

// FUN_003C40D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c40d0);

// FUN_003C42B0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c42b0);

// FUN_003C47C0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c47c0);

// FUN_003C4A40
#pragma schedule on
u8 *func_003c4a40(u8 *arg0) {
    ((s32 *)arg0)[2] = 0;
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    return arg0;
}
#pragma schedule off


extern s32 D_007647EC;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 15 -> 0). */

// FUN_003C54A0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c54a0);

// FUN_003C5700
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c5700);

// FUN_003C5760
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c5760);

// FUN_003C8CA0
#pragma schedule on
s32 func_003c8ca0(s32 arg0) {
    D_007647EC++;
    return arg0;
}
#pragma schedule off


void func_003cc460();
void func_003d4e00();
void func_003d4e90();
void func_003d4d70();

/* measured: without #pragma schedule on, MWCC emits ld $ra / addiu $sp /
   jr $ra / nop; retail restores sp in the jr delay slot (nd 6 -> 0). */

// FUN_003C9530
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c9530);

// FUN_003C96D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003c96d0);

// FUN_003CA830
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca830);

// FUN_003CA890
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca890);

// FUN_003CA8E0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca8e0);

// FUN_003CA960
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca960);

// FUN_003CA9D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003ca9d0);

// FUN_003CB720
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb720);

// FUN_003CB820
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb820);

// FUN_003CB870
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cb870);

// FUN_003CBC10
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cbc10);

// FUN_003CBC90
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cbc90);

// FUN_003CC010
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc010);

// FUN_003CC070
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc070);

// FUN_003CC0D0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc0d0);

// FUN_003CC130
#pragma schedule on
void func_003cc130(void) {
    func_003cc460();
    func_003d4e00();
    func_003d4e90();
    func_003d4d70();
}
#pragma schedule off


/* measured: without #pragma schedule on, MWCC emits addiu $v0, 1 before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

// FUN_003CC240
#pragma schedule on
s32 func_003cc240(void) {
    return 1;
}
#pragma schedule off


void func_003f32d0();

/* measured (merged TU): schedule on was load-bearing per-unit for the
   jal/jr $ra delay slots, but in the merged TU it worsens the near-miss
   (nd 17 with vs nd 15 without), so the pragma was removed.
   NONMATCHING: retail sinks the if-body out of line (bnez/ b exit; ld ra /
   body / b back / jr ra; addiu sp, 15 instr); b210 compiles every honest
   form of this if inline as a beql skip (13 instr) across 30+ probe
   shapes, so the layout is not reproducible.  Residual: nd 15. */

// FUN_003CC250
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc250);

// FUN_003CC500
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc500);

// FUN_003CC680
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc680);

// FUN_003CC6E0 NONMATCHING
#ifdef NON_MATCHING
void func_003cc6e0(u8 *arg0) {
    if (((s32 *)arg0)[6] != 0) {
        func_003f32d0();
        func_003f32d0();
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cc6e0);
#endif


extern s32 D_0070B110[];

/* measured: without #pragma schedule on, MWCC emits lui / addiu before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */

// FUN_003CF9B0
INCLUDE_ASM("asm/nonmatchings/code1_003c", func_003cf9b0);

// FUN_003CFA70
#pragma schedule on
s32 *func_003cfa70(void) {
    return D_0070B110;
}
#pragma schedule off
