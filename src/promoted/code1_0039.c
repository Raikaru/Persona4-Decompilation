/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_003901E0)
#include "type.h"

extern s32 D_007246B0;
extern s32 D_007246B4;
extern u8 D_008872E0[];

/* measured: #pragma schedule on hoists the return-value move to the top,
 * sinks the counter store, and fills the jr delay slot. */
#pragma schedule on
// FUN_003901E0
s32 func_003901e0(s32 arg0)
{
    D_007246B0 += 1;
    *(s32 *)(D_008872E0 + D_007246B4) = 0;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003901E0 */

#if defined(P4_UNIT_00390210)
#include "type.h"

extern s32 D_007246B0;

/* measured: #pragma schedule on hoists the return-value move before the
 * counter arithmetic and fills the jr delay slot with the final sw. */
#pragma schedule on
// FUN_00390210
s32 func_00390210(s32 arg0)
{
    D_007246B0 -= 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_00390210 */

#if defined(P4_UNIT_003963B0)
#include "type.h"

/* measured: retail computes count*0x24 as lw/addiu/jr + EE 3-op mult in the
 * return delay slot (16B). b210 strength-reduces every x*36 form to an
 * sll/addu/sll chain -- probed ~30 shapes across O0/O1/O2/O3, schedule
 * on/off, opt_rebuildconditionals, u8/u16/u32/s32/s64 casts, computed
 * operands, address feeds, inlined getters, locals and consts -- so the
 * mult cannot be reproduced and the shift chain cannot fit the 16B window.
 * Compiler-version codegen floor. NONMATCHING */
#pragma optimization_level 3
// FUN_003963B0 NONMATCHING
s32 func_003963b0(u8 *arg0)
{
    return 0x24 * *(s32 *)(arg0 + 4);
}
#endif /* P4_UNIT_003963B0 */

#if defined(P4_UNIT_0039AB10)
#include "type.h"

s32 func_00399530(void);

/* measured: optimization_level 3 is load-bearing -- b210 at -O2 always
 * emits jal + frame for a trailing call; retail is a tail j. */
#pragma optimization_level 3
// FUN_0039AB10
void func_0039ab10(void)
{
    func_00399530();
}
#endif /* P4_UNIT_0039AB10 */

#if defined(P4_UNIT_0039AC20)
#include "type.h"

extern s32 D_007246EC;

/* measured: #pragma schedule on hoists the return-value move before the
 * counter arithmetic and fills the jr delay slot with the final sw. */
#pragma schedule on
// FUN_0039AC20
s32 func_0039ac20(s32 arg0)
{
    D_007246EC += 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_0039AC20 */

#if defined(P4_UNIT_0039AC40)
#include "type.h"

extern s32 D_007246EC;

/* measured: #pragma schedule on hoists the return-value move before the
 * counter arithmetic and fills the jr delay slot with the final sw. */
#pragma schedule on
// FUN_0039AC40
s32 func_0039ac40(s32 arg0)
{
    D_007246EC -= 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_0039AC40 */

#if defined(P4_UNIT_0039B510)
#include "type.h"

s32 func_0039b6e0(s32 arg0);

/* measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
 * scheduler (plain -O2 emits a 56B frame; #pragma schedule on or
 * optimization_level 3 both give the exact 48B shape). arg1/arg2 are
 * hidden params: retail moves arg3 ($a3) into the callee's $a0. */
#pragma optimization_level 3
// FUN_0039B510
s32 func_0039b510(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 8) = func_0039b6e0(arg3);
    return 1;
}
#endif /* P4_UNIT_0039B510 */

#if defined(P4_UNIT_0039B540)
#include "type.h"

s32 func_0039b6e0(s32 arg0);

/* measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
 * scheduler (plain -O2 emits a 56B frame; #pragma schedule on or
 * optimization_level 3 both give the exact 48B shape). arg1/arg2 are
 * hidden params: retail moves arg3 ($a3) into the callee's $a0. */
#pragma optimization_level 3
// FUN_0039B540
s32 func_0039b540(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 0x6C) = func_0039b6e0(arg3);
    return 1;
}
#endif /* P4_UNIT_0039B540 */

#if defined(P4_UNIT_0039B570)
#include "type.h"

s32 func_0039b6e0(s32 arg0);

/* measured: retail's sd/sdq-16 + jal + sw/ld/lq epilogue needs the
 * scheduler (plain -O2 emits a 56B frame; #pragma schedule on or
 * optimization_level 3 both give the exact 48B shape). arg1/arg2 are
 * hidden params: retail moves arg3 ($a3) into the callee's $a0. */
#pragma optimization_level 3
// FUN_0039B570
s32 func_0039b570(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    *(s32 *)(arg0 + 0x7C) = func_0039b6e0(arg3);
    return 1;
}
#endif /* P4_UNIT_0039B570 */

#if defined(P4_UNIT_0039B6E0)
#include "type.h"

extern s32 D_00884ACC[];
void *func_0039bb70(void *list, s32 key);

/* measured: optimization_level 3 gives the right prologue, absolute
 * lui/addiu addressing for &D_00884ACC (array decl), and arg order.
 * Residual: retail keeps the if-body as beqz + nop + b .Lend with the lw
 * in the b's delay slot and the return-0 block out-of-line (14 instr);
 * every if/else/switch/goto/ternary form at O2/O2+schedule/O3 compiles the
 * same selection to beql $v0,$zero + move-in-delay + inline lw (12 instr,
 * nd 17). Scheduler branch-shape floor. NONMATCHING */
#pragma optimization_level 3
// FUN_0039B6E0 NONMATCHING
s32 func_0039b6e0(s32 arg0)
{
    u8 *temp_2;

    temp_2 = (u8 *)(func_0039bb70(D_00884ACC, arg0));
    if (temp_2 != NULL)
    {
        return (s32)(*(s32 *)(temp_2 + 0x10));
    }
    return 0;
}
#endif /* P4_UNIT_0039B6E0 */
