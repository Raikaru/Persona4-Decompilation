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

// FUN_003B0B80
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b0b80);
// FUN_003B12A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b12a0);
// FUN_003B1A10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b1a10);
// FUN_003B31A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b31a0);
// FUN_003B3240
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b3240);
// FUN_003B3570
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b3570);
// FUN_003B3880
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b3880);
// FUN_003B3F50
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b3f50);
// FUN_003B4020
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4020);
// FUN_003B4120
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4120);
// FUN_003B4230
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4230);
// FUN_003B42E0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b42e0);
// FUN_003B4470
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4470);
// FUN_003B47F0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b47f0);
// FUN_003B4AB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4ab0);
// FUN_003B4C10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4c10);
// FUN_003B4DB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4db0);
// FUN_003B4FF0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b4ff0);
// FUN_003B5160
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5160);
// FUN_003B53B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b53b0);
// FUN_003B5650
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5650);
// FUN_003B5820
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5820);
// FUN_003B5AC0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5ac0);
// FUN_003B5BF0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5bf0);
// FUN_003B5D20
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5d20);
// FUN_003B5FB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b5fb0);
// FUN_003B6020
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6020);
// FUN_003B61E0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b61e0);
// FUN_003B6390
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6390);
// FUN_003B6420
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6420);
// FUN_003B64C0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b64c0);
// FUN_003B6540
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6540);
// FUN_003B65D0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b65d0);
// FUN_003B6680
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6680);
// FUN_003B6CB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6cb0);
// FUN_003B6CC0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6cc0);
// FUN_003B6DA0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6da0);
// FUN_003B6E00
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6e00);
// FUN_003B6E70
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6e70);
// FUN_003B6F00
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b6f00);
// FUN_003B7060
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7060);
// FUN_003B7110
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7110);
// FUN_003B7150
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7150);
// FUN_003B71B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b71b0);
// FUN_003B7290
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7290);
// FUN_003B7450
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7450);
// FUN_003B7480
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7480);
// FUN_003B7510
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7510);
// FUN_003B7590
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7590);
// FUN_003B7680
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7680);
// FUN_003B7860
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7860);
// FUN_003B7970
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7970);
// FUN_003B79F0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b79f0);
// FUN_003B7A10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b7a10);
// FUN_003B88D0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b88d0);
// FUN_003B8930
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8930);
// FUN_003B8AD0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8ad0);
// FUN_003B8D20
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8d20);
// FUN_003B8D30
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8d30);
// FUN_003B8D40
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8d40);
// FUN_003B8E50
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b8e50);
// FUN_003B90B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b90b0);
// FUN_003B9A40
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003b9a40);
// FUN_003BB030
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb030);
// FUN_003BB0D0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb0d0);
// FUN_003BB210
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb210);
// FUN_003BB330
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb330);
// FUN_003BB3A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb3a0);
// FUN_003BB4A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb4a0);
// FUN_003BB5B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bb5b0);
// FUN_003BBA90
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bba90);
// FUN_003BBB60
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bbb60);
// FUN_003BBBE0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bbbe0);
// FUN_003BBE20
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bbe20);
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

// FUN_003BBEA0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bbea0);

// FUN_003BBF80
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bbf80);

// FUN_003BC150
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc150);

// FUN_003BC400
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc400);

// FUN_003BC620
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc620);

// FUN_003BC740
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc740);

// FUN_003BC880
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc880);

// FUN_003BC9C0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bc9c0);

// FUN_003BCBC0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcbc0);

// FUN_003BCBE0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcbe0);

// FUN_003BCC80
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcc80);

// FUN_003BCD50
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcd50);

// FUN_003BCE20
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bce20);

// FUN_003BCE50
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bce50);
// Archived C body: build/WBHygiene_func_003bcf10_archive.txt; no current park body remains.
// FUN_003BCF10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcf10);

/* measured: ascending switch labels generate retail's descending 3/2/1
   comparisons; no_branch_likely keeps each comparison as a plain beq. */
#pragma no_branch_likely on

// FUN_003BCF60
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcf60);

// FUN_003BCFB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bcfb0);

// FUN_003BD000
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd000);

// FUN_003BD040
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd040);

// FUN_003BD050
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd050);

// FUN_003BD070
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd070);

// FUN_003BD090
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd090);

// FUN_003BD0B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd0b0);

// FUN_003BD0D0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd0d0);

// FUN_003BD0F0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd0f0);
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

// FUN_003BD160
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd160);
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
// Archived C body: build/WBHygiene_func_003bd4f0_archive.txt; no current park body remains.
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
// Archived C body: build/WBHygiene_func_003bd610_archive.txt; no current park body remains.
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

// FUN_003BD6B0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bd6b0);
// FUN_003BDD00
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bdd00);
// FUN_003BE180
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be180);
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

// FUN_003BE800
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be800);

// FUN_003BE810
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be810);
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
// Archived C body: build/WBHygiene_func_003be8a0_archive.txt; no current park body remains.
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

// FUN_003BE9A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be9a0);
// FUN_003BE9F0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003be9f0);
// FUN_003BEA60
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bea60);
// FUN_003BEB10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003beb10);
// FUN_003BEBB0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bebb0);
// FUN_003BED10
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bed10);
// FUN_003BEE80
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bee80);
// FUN_003BF1A0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf1a0);
// FUN_003BF330
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf330);
// FUN_003BF360
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf360);
// FUN_003BF3D0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf3d0);
// FUN_003BF5F0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf5f0);
// FUN_003BF930
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bf930);
// FUN_003BFAE0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfae0);
// FUN_003BFC40
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfc40);
// FUN_003BFD00
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfd00);
// FUN_003BFDF0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfdf0);
// FUN_003BFE60
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfe60);
// FUN_003BFE90
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bfe90);
// FUN_003BFF30
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bff30);
// FUN_003BFFC0
INCLUDE_ASM("asm/nonmatchings/code1_003b", func_003bffc0);