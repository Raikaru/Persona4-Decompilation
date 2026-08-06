#include "include_asm.h"
#include "type.h"

extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 D_00764794;
extern s32 D_00764790;
extern s32 D_0076478C;
extern s32 D_00764788;
extern s32 D_007647AC;
extern s32 D_007647A8;
extern s32 D_00764784;

extern s32 D_0076479C;


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BBE60
#pragma schedule on
s32 func_003bbe60(s32 arg0) {
    D_00764784 += 1;
    return arg0;
}
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BBE80
#pragma schedule on
s32 func_003bbe80(s32 arg0) {
    D_00764784 -= 1;
    return arg0;
}
#pragma schedule off


// measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
//   b's delay slot unfilled (12 instr, 48B, nd 17).  schedule on
//   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
//   the first beqz into a beql with move $v0, $zero hoisted into its delay
//   slot and retargets it past the shared move; retail keeps beqz + nop.
//   NONMATCHING: b210 converts the first branch of a two-test chain whose
//   shared single-instruction return-0 target feeds a leaf [jr; nop]
//   epilogue; every honest source shape (&&, ||, nested ifs, early
//   returns, ternary, switch, result variable, goto forms) and every
//   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
//   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
//   beql; a whole-ELF scan shows retail never hoists a shared return-move
//   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
//   all have non-shared targets with multi-instruction epilogues).
//   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
//   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17).

#pragma schedule on
// FUN_003BCF10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcf10);

/* measured: ascending switch labels generate retail's descending 3/2/1
   comparisons; no_branch_likely keeps each comparison as a plain beq. */
#pragma no_branch_likely on
// FUN_003BD110
s32 func_003bd110(s32 arg0)
{
    switch (arg0) {
    case 1:
        return 4;
    case 2:
        return 4;
    case 3:
        return 4;
    default:
        return 0;
    }
}
#pragma no_branch_likely off

/* measured: nd 43 of 32 words, and the shape is right - the residual is
   branch polarity and block layout only. Retail tests positively and puts both
   `return 0` paths OUT OF LINE past the default `return arg0`; b210 inverts
   every test and lays the early exits inline. no_branch_likely is required just
   to stop b210 emitting bnel/beql here (nd 60 -> 44), and of the three
   plausible source shapes the flat early-return chain is closest (nd 43, obj
   124 of 128): nesting the whole body under one positive guard costs nd 59, and
   a single-case switch on arg1 == 8 costs nd 66.  Four functions in this file
   share the shape, differing only in the two gp-relative operands. */
// FUN_003BD470
#ifdef NON_MATCHING
#pragma no_branch_likely on
s32 func_003bd470(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_00764794, 4) == 0) {
        return 0;
    }
    if (arg1 != 8) {
        return arg0;
    }
    if (func_003df360(arg0, &D_00764790, 4) == 0) {
        return 0;
    }
    return arg0;
}
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd470);
#endif

// FUN_003BD4F0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd4f0);

// FUN_003BD560
/* measured: b210 emits a branch-likely (beql) where retail uses a plain beqz.
   The retail window for func_003bd560 contains no branch-likely instruction at all, so the
   likely form is simply wrong here; nd 4 -> MATCH with this pragma. */
#pragma no_branch_likely on
s32 func_003bd560(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x6C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_003bd560). */
#pragma no_branch_likely off
#pragma schedule off


// measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
//   b's delay slot unfilled (12 instr, 48B, nd 17).  schedule on
//   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
//   the first beqz into a beql with move $v0, $zero hoisted into its delay
//   slot and retargets it past the shared move; retail keeps beqz + nop.
//   NONMATCHING: b210 converts the first branch of a two-test chain whose
//   shared single-instruction return-0 target feeds a leaf [jr; nop]
//   epilogue; every honest source shape (&&, ||, nested ifs, early
//   returns, ternary, switch, result variable, goto forms) and every
//   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
//   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
//   beql; a whole-ELF scan shows retail never hoists a shared return-move
//   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
//   all have non-shared targets with multi-instruction epilogues).
//   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
//   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17).

#pragma schedule on
/* measured: same shape as func_003bd470; see that note. nd 43. */
// FUN_003BD590
#ifdef NON_MATCHING
#pragma no_branch_likely on
s32 func_003bd590(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_0076478C, 4) == 0) {
        return 0;
    }
    if (arg1 != 8) {
        return arg0;
    }
    if (func_003df360(arg0, &D_00764788, 4) == 0) {
        return 0;
    }
    return arg0;
}
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd590);
#endif

// FUN_003BD610
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd610);

// FUN_003BD680
/* measured: b210 emits a branch-likely (beql) where retail uses a plain beqz.
   The retail window for func_003bd680 contains no branch-likely instruction at all, so the
   likely form is simply wrong here; nd 4 -> MATCH with this pragma. */
#pragma no_branch_likely on
s32 func_003bd680(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x7C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_003bd680). */
#pragma no_branch_likely off
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 16 -> 0).

// FUN_003BE7C0
#pragma schedule on
s32 func_003be7c0(s32 arg0) {
    D_0076479C -= 1;
    return arg0;
}
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 16 -> 0).

// FUN_003BE7E0
#pragma schedule on
s32 func_003be7e0(s32 arg0) {
    D_0076479C += 1;
    return arg0;
}
#pragma schedule off


// measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
//   b's delay slot unfilled (12 instr, 48B, nd 17).  schedule on
//   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
//   the first beqz into a beql with move $v0, $zero hoisted into its delay
//   slot and retargets it past the shared move; retail keeps beqz + nop.
//   NONMATCHING: b210 converts the first branch of a two-test chain whose
//   shared single-instruction return-0 target feeds a leaf [jr; nop]
//   epilogue; every honest source shape (&&, ||, nested ifs, early
//   returns, ternary, switch, result variable, goto forms) and every
//   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
//   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
//   beql; a whole-ELF scan shows retail never hoists a shared return-move
//   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
//   all have non-shared targets with multi-instruction epilogues).
//   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
//   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17).

#pragma schedule on
/* measured: same shape as func_003bd470; see that note. nd 43. */
// FUN_003BE820
#ifdef NON_MATCHING
#pragma no_branch_likely on
s32 func_003be820(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_007647AC, 4) == 0) {
        return 0;
    }
    if (arg1 != 8) {
        return arg0;
    }
    if (func_003df360(arg0, &D_007647A8, 4) == 0) {
        return 0;
    }
    return arg0;
}
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be820);
#endif

// FUN_003BE8A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be8a0);

// FUN_003BE910
/* measured: b210 emits a branch-likely (beql) where retail uses a plain beqz.
   The retail window for func_003be910 contains no branch-likely instruction at all, so the
   likely form is simply wrong here; nd 4 -> MATCH with this pragma. */
#pragma no_branch_likely on
s32 func_003be910(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x6C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_003be910). */
#pragma no_branch_likely off
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BE940
#pragma schedule on
s32 func_003be940(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BE960
#pragma schedule on
s32 func_003be960(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
#pragma schedule off


// measured: without schedule on, MWCC leaves the jr $ra delay slot
//   unfilled (nop) and colours the increment $v0; retail fills the slot with
//   the sw and colours it $v1 (nd 15 -> 0).

// FUN_003BE980
#pragma schedule on
s32 func_003be980(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
#pragma schedule off
