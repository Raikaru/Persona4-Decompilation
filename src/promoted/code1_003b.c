#include "include_asm.h"
#include "type.h"

extern s32 iGpffffb668;

extern s32 func_003df360(s32 arg0, void *arg1, s32 arg2);
extern s32 func_003df240(s32 arg0, s32 arg1, s32 arg2);
extern s32 D_00764758;
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
/* measured: nd 47 at retail's real 68-byte body. Counts the entries of the
   gp-based descriptor at iGpffffb668 whose +0xC word is set. Retail hoists the
   zeroed accumulator and the loop index into the guard's delay slots and walks
   the entry pointer with the stride in the back-edge slot; b210 keeps the
   accumulator in a different register class and orders the guard the other
   way. schedule on does not move it (nd 47). Committed at nd 46. */
// FUN_003BCF10 NONMATCHING
#ifdef NON_MATCHING
/* measured: -O2 coalesces two values retail keeps in separate registers
   and folds a mask retail re-issues; level 1 does neither. */
#pragma optimization_level 1
s32 func_003bcf10(s32 arg0) {
    u8 *t = (u8 *)(arg0 + iGpffffb668);
    s32 n = *(s32 *)t;
    s32 count = 0;
    u8 *e;
    s32 i;

    if (n > 0) {
        e = *(u8 **)(t + 4);
        i = 0;
        do {
            if (*(s32 *)(e + 0xC) != 0) {
                count++;
            }
            i++;
            e += 0x10;
        } while (i < n);
    }
    return count;
}
/* measured: closes the level 1 scope above at the file's -O2 baseline. */
#pragma optimization_level 2
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcf10);
#endif

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

/* measured: the flat early-return chain is nd 43 -- b210 inverts every test
   and lays the early exits inline, while retail orders the blocks
   [func1 test][retarg][ret0][do2].  Writing that exact block order with
   explicit label targets (retarg = shared `return arg0`, ret0 = `return 0`,
   do2 = second guarded call) makes it byte-exact (nd 43 -> MATCH).
   #pragma no_branch_likely is load-bearing: without it the same body measures
   nd 46 (b210 emits bnel/beql).  Three functions in this file share the shape,
   differing only in the two gp-relative operands. */
// FUN_003BD470
#pragma no_branch_likely on
s32 func_003bd470(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_00764794, 4) == 0) {
        goto ret0;
    }
    if (arg1 == 8) {
        goto do2;
    }
retarg:
    return arg0;
ret0:
    return 0;
do2:
    if (func_003df360(arg0, &D_00764790, 4) != 0) {
        goto retarg;
    }
    return 0;
}
#pragma no_branch_likely off

/* measured: nd 48 of 28 words, obj 112/112 (correct size).  Two residuals
   no source shape or schedule/optimization knob removes: (1) retail hoists
   the first `lw *(arg2+0x6C)` to offset 4, before the register saves, to
   hide load latency; mwcc schedules it after the saves (offsets 4-20
   shifted).  (2) retail emits `movz $s1,$zero,$v0` for the second
   conditional return; mwcc emits `bnez; move $s1,$0` instead.  Tried: flat
   early returns, goto block layout, result variable, ternaries (both
   directions), nested ifs, &&, cached base local, #pragma schedule on --
   all nd 48.  #pragma no_branch_likely is load-bearing: without it mwcc
   emits bnel (nd 57). */
// FUN_003BD4F0 NONMATCHING
#ifdef NON_MATCHING
#pragma no_branch_likely on
s32 func_003bd4f0(s32 arg0, s32 arg1, s32 arg2)
{
    s32 result = arg0;
    if (func_003df240(arg0, *(s32 *)(arg2 + 0x6C) + 0x2C, 4) == 0) {
        return 0;
    }
    if (func_003df240(arg0, *(s32 *)(arg2 + 0x6C) + 0x30, 4) == 0) {
        result = 0;
    }
    return result;
}
#pragma no_branch_likely off
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd4f0);
#endif

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
// FUN_003BD590
#pragma no_branch_likely on
s32 func_003bd590(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_0076478C, 4) == 0) {
        goto ret0;
    }
    if (arg1 == 8) {
        goto do2;
    }
retarg:
    return arg0;
ret0:
    return 0;
do2:
    if (func_003df360(arg0, &D_00764788, 4) != 0) {
        goto retarg;
    }
    return 0;
}
#pragma no_branch_likely off

/* measured: same two residuals as func_003bd4f0 (prologue load hoisting +
   movz vs branch), nd 48, obj 112/112.  See the func_003bd4f0 note for the
   shapes tried.  #pragma no_branch_likely is load-bearing (nd 57 without). */
/* measured: the two guarded func_003df240 calls, the reloaded 0x7C field and
   the `return 0` block all match. Residual nd 37: retail folds the final
   `r ? arg0 : 0` into a single `movz $s1,$zero,$v0` where b210 emits
   `beql` + `move`, and it hoists the first 0x7C load above the prologue
   stores. Measured: no_branch_likely on turns the beql into a branch pair and
   costs more (nd 56 with the ternary, nd 48 with an `if (r == 0) arg0 = 0;`),
   `#pragma conditional_move on` changes nothing, and schedule on changes
   nothing. Conditional-move materialisation floor. Committed at nd 37. */
// FUN_003BD610 NONMATCHING
#ifdef NON_MATCHING
s32 func_003bd610(s32 arg0, s32 arg1, u8 *arg2) {
    s32 r;

    if (func_003df240(arg0, *(s32 *)(arg2 + 0x7C) + 0x2C, 4) == 0) {
        return 0;
    }
    r = func_003df240(arg0, *(s32 *)(arg2 + 0x7C) + 0x30, 4);
    return r ? arg0 : 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd610);
#endif

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
/* measured: same shape as func_003bd470; see that note.  The explicit-label
   block order (retarg/ret0/do2) makes it byte-exact (nd 43 -> MATCH). */
// FUN_003BE820
#pragma no_branch_likely on
s32 func_003be820(s32 arg0, s32 arg1)
{
    if (func_003df360(arg0, &D_007647AC, 4) == 0) {
        goto ret0;
    }
    if (arg1 == 8) {
        goto do2;
    }
retarg:
    return arg0;
ret0:
    return 0;
do2:
    if (func_003df360(arg0, &D_007647A8, 4) != 0) {
        goto retarg;
    }
    return 0;
}
#pragma no_branch_likely off

/* measured: same two residuals as func_003bd4f0 (prologue load hoisting +
   movz vs branch), nd 48, obj 112/112.  See the func_003bd4f0 note for the
   shapes tried.  #pragma no_branch_likely is load-bearing (nd 57 without). */
/* measured: the two guarded func_003df240 calls, the reloaded 0x6C field and
   the `return 0` block all match. Residual nd 37: retail folds the final
   `r ? arg0 : 0` into a single `movz $s1,$zero,$v0` where b210 emits
   `beql` + `move`, and it hoists the first 0x6C load above the prologue
   stores. Measured: no_branch_likely on turns the beql into a branch pair and
   costs more (nd 56 with the ternary, nd 48 with an `if (r == 0) arg0 = 0;`),
   `#pragma conditional_move on` changes nothing, and schedule on changes
   nothing. Conditional-move materialisation floor. Committed at nd 37. */
// FUN_003BE8A0 NONMATCHING
#ifdef NON_MATCHING
s32 func_003be8a0(s32 arg0, s32 arg1, u8 *arg2) {
    s32 r;

    if (func_003df240(arg0, *(s32 *)(arg2 + 0x6C) + 0x2C, 4) == 0) {
        return 0;
    }
    r = func_003df240(arg0, *(s32 *)(arg2 + 0x6C) + 0x30, 4);
    return r ? arg0 : 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be8a0);
#endif

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
