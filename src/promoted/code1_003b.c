/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_003BBE60)
#include "type.h"

extern s32 D_00764784;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colours the increment $v0; retail fills the slot with
   the sw and colours it $v1 (nd 15 -> 0). */
// FUN_003BBE60
#pragma schedule on
s32 func_003bbe60(s32 arg0) {
    D_00764784 += 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003BBE60 */

#if defined(P4_UNIT_003BBE80)
#include "type.h"

extern s32 D_00764784;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colours the increment $v0; retail fills the slot with
   the sw and colours it $v1 (nd 15 -> 0). */
// FUN_003BBE80
#pragma schedule on
s32 func_003bbe80(s32 arg0) {
    D_00764784 -= 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003BBE80 */

#if defined(P4_UNIT_003BD560)
#include "type.h"

/* measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
   b's delay slot unfilled (12 instr, 48B, nd 17).  #pragma schedule on
   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
   the first beqz into a beql with move $v0, $zero hoisted into its delay
   slot and retargets it past the shared move; retail keeps beqz + nop.
   NONMATCHING: b210 converts the first branch of a two-test chain whose
   shared single-instruction return-0 target feeds a leaf [jr; nop]
   epilogue; every honest source shape (&&, ||, nested ifs, early
   returns, ternary, switch, result variable, goto forms) and every
   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
   beql; a whole-ELF scan shows retail never hoists a shared return-move
   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
   all have non-shared targets with multi-instruction epilogues).
   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17). */
// FUN_003BD560 NONMATCHING
#pragma schedule on
s32 func_003bd560(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x6C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
#pragma schedule off
#endif /* P4_UNIT_003BD560 */

#if defined(P4_UNIT_003BD680)
#include "type.h"

/* measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
   b's delay slot unfilled (12 instr, 48B, nd 17).  #pragma schedule on
   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
   the first beqz into a beql with move $v0, $zero hoisted into its delay
   slot and retargets it past the shared move; retail keeps beqz + nop.
   NONMATCHING: b210 converts the first branch of a two-test chain whose
   shared single-instruction return-0 target feeds a leaf [jr; nop]
   epilogue; every honest source shape (&&, ||, nested ifs, early
   returns, ternary, switch, result variable, goto forms) and every
   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
   beql; a whole-ELF scan shows retail never hoists a shared return-move
   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
   all have non-shared targets with multi-instruction epilogues).
   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17). */
// FUN_003BD680 NONMATCHING
#pragma schedule on
s32 func_003bd680(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x7C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
#pragma schedule off
#endif /* P4_UNIT_003BD680 */

#if defined(P4_UNIT_003BE7C0)
#include "type.h"

extern s32 D_0076479C;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colours the increment $v0; retail fills the slot with
   the sw and colours it $v1 (nd 16 -> 0). */
// FUN_003BE7C0
#pragma schedule on
s32 func_003be7c0(s32 arg0) {
    D_0076479C -= 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003BE7C0 */

#if defined(P4_UNIT_003BE7E0)
#include "type.h"

extern s32 D_0076479C;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colours the increment $v0; retail fills the slot with
   the sw and colours it $v1 (nd 16 -> 0). */
// FUN_003BE7E0
#pragma schedule on
s32 func_003be7e0(s32 arg0) {
    D_0076479C += 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003BE7E0 */

#if defined(P4_UNIT_003BE910)
#include "type.h"

/* measured: with -O2 alone MWCC leaves the addiu $v0, 8 inline with the
   b's delay slot unfilled (12 instr, 48B, nd 17).  #pragma schedule on
   fills the b slot (11 instr, 44B, nd 4) but the scheduler also converts
   the first beqz into a beql with move $v0, $zero hoisted into its delay
   slot and retargets it past the shared move; retail keeps beqz + nop.
   NONMATCHING: b210 converts the first branch of a two-test chain whose
   shared single-instruction return-0 target feeds a leaf [jr; nop]
   epilogue; every honest source shape (&&, ||, nested ifs, early
   returns, ternary, switch, result variable, goto forms) and every
   schedule/optimization knob (-opt level 1-4, space, speed, schedule on,
   opt_peephole/opt_common_subs/opt_branch_folding off) reproduces the
   beql; a whole-ELF scan shows retail never hoists a shared return-move
   into a branch-likely slot (the 46 retail beql+daddu $v0,$0,$0 cases
   all have non-shared targets with multi-instruction epilogues).
   Residual: 2 words at offsets 4/8.  measured: removing #pragma schedule
   on regresses the addiu $v0, 8 back out of the b delay slot (nd 4 -> 17). */
// FUN_003BE910 NONMATCHING
#pragma schedule on
s32 func_003be910(u8 *arg0) {
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x6C);
    if ((temp_2 != NULL) && (*(s32 *)(temp_2 + 0x2C) != 0)) {
        return 8;
    }
    return 0;
}
#pragma schedule off
#endif /* P4_UNIT_003BE910 */

#if defined(P4_UNIT_003BE940)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colours the increment $v0; retail fills the slot with
   the sw and colours it $v1 (nd 15 -> 0). */
// FUN_003BE940
#pragma schedule on
s32 func_003be940(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003BE940 */

#if defined(P4_UNIT_003BE960)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colours the increment $v0; retail fills the slot with
   the sw and colours it $v1 (nd 15 -> 0). */
// FUN_003BE960
#pragma schedule on
s32 func_003be960(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003BE960 */

#if defined(P4_UNIT_003BE980)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colours the increment $v0; retail fills the slot with
   the sw and colours it $v1 (nd 15 -> 0). */
// FUN_003BE980
#pragma schedule on
s32 func_003be980(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003BE980 */
