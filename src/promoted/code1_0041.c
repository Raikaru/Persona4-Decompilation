/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00419628)
#include "type.h"

/* measured: baseline -O2 emits lw/sw/srl/andi/jr/nop with the return andi
   before jr (nd 6); schedule-on fills the jr delay slot with the andi but
   reorders the srl ahead of the store (nd 8), so the plain -O2 form is
   kept. Residual vs retail (lw/sw/srl/jr/andi): the andi/jr pair swapped. */
// FUN_00419628 NONMATCHING
s32 func_00419628(u32 *arg0, u32 arg1)
{
    u32 temp = *arg0;

    *arg0 = arg1;
    return (temp >> 8) & 1;
}
#endif /* P4_UNIT_00419628 */

#if defined(P4_UNIT_0041F2A8)
#include "type.h"

/* measured: schedule-on fills the jr delay slot with the sltiu; without it
   the delay slot is a nop (nd 14 -> 2).  The `x < 1` form is required:
   `x == 0` compiles to xor/sltiu (nd 13).  Residual vs retail
   (lw $v1 / lw $v0 / jr / sltiu): b210 coalesces the base load into $v0
   where retail keeps it in $v1 -- the documented getter coloring floor. */
// FUN_0041F2A8 NONMATCHING
#pragma schedule on
s32 func_0041f2a8(u8 *arg0)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    return *(u32 *)(p + 4) < 1;
}
#pragma schedule off
#endif /* P4_UNIT_0041F2A8 */

#if defined(P4_UNIT_0041F2B8)
#include "type.h"

/* measured: schedule-on fills the jr delay slot with the final sw (nd 9 ->
   4).  Residual vs retail (lw $v0 base): b210 colors the store base $v1
   where retail uses $v0 -- the documented setter coloring floor. */
// FUN_0041F2B8 NONMATCHING
#pragma schedule on
void func_0041f2b8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s32 *)(p + 0xB0) = arg3;
    *(s32 *)(p + 0xA8) = arg1;
    *(s32 *)(p + 0xAC) = arg2;
}
#pragma schedule off
#endif /* P4_UNIT_0041F2B8 */

#if defined(P4_UNIT_0041F2D0)
#include "type.h"

/* measured: schedule-on fills the jr delay slot with the final sw (nd 18 ->
   9).  Residual vs retail: b210 reuses the dead $a0 for the base and $v1
   for all three load results, where retail keeps the base in $t0 and
   alternates $v0/$v1/$v0 -- allocator coloring floor (probed: explicit
   locals nd 15, s32* pointer nd 9, non-void return nd 9). */
// FUN_0041F2D0 NONMATCHING
#pragma schedule on
void func_0041f2d0(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *arg1 = *(s32 *)(p + 0xA8);
    *arg2 = *(s32 *)(p + 0xAC);
    *arg3 = *(s32 *)(p + 0xB0);
}
#pragma schedule off
#endif /* P4_UNIT_0041F2D0 */

#if defined(P4_UNIT_0041F550)
#include "type.h"

/* measured: opt_common_subs off is load-bearing -- with it MWCC merges the
   store constant into the return register (single addiu, nd 9); without it
   the two constant-1s stay separate (nd 5).  schedule-on fills the jr delay
   slot.  Residual vs retail: b210 swaps the base/value registers (base $a0
   vs $v1, stored 1 in $v1 vs $a0) -- allocator coloring floor. */
// FUN_0041F550 NONMATCHING
#pragma opt_common_subs off
#pragma schedule on
s32 func_0041f550(u8 *arg0, s64 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s64 *)(p + 0x90) = arg1;
    *(s32 *)(p + 0x8C) = 1;
    return 1;
}
#pragma schedule off
#pragma opt_common_subs on
#endif /* P4_UNIT_0041F550 */

#if defined(P4_UNIT_0041F568)
#include "type.h"

/* measured: schedule-on fills the jr delay slot with the zero store
   (without it nd 13). */
// FUN_0041F568
#pragma schedule on
s32 func_0041f568(u8 *arg0)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s64 *)(p + 0x90) = 0;
    *(s32 *)(p + 0x8C) = 0;
    return 1;
}
#pragma schedule off
#endif /* P4_UNIT_0041F568 */

#if defined(P4_UNIT_0041F5E0)
#include "type.h"

/* measured: opt_common_subs off is load-bearing -- with it MWCC merges the
   store constant into the return register (single addiu, nd 13); without it
   the two constant-1s stay separate and only the base register differs.
   schedule-on fills the jr delay slot with the sd.  Residual vs retail
   (base in $a2): b210 reuses the dead $a0 for the base -- allocator
   coloring floor (nd 3). */
// FUN_0041F5E0 NONMATCHING
#pragma opt_common_subs off
#pragma schedule on
s32 func_0041f5e0(u8 *arg0, s64 arg1)
{
    u8 *p = *(u8 **)(arg0 + 0x40);

    *(s32 *)(p + 0x108) = 1;
    *(s64 *)(p + 0x100) = arg1;
    return 1;
}
#pragma schedule off
#pragma opt_common_subs on
#endif /* P4_UNIT_0041F5E0 */

#if defined(P4_UNIT_0041F6C8)
#include "type.h"

/* measured: schedule-on fills the jr delay slot with the final store
   (without it nd 4). */
// FUN_0041F6C8
#pragma schedule on
void func_0041f6c8(u8 *arg0, s32 arg1, s32 arg2)
{
    *(s32 *)(arg0 + 0xC) = arg1;
    *(s32 *)(arg0 + 4) = arg2;
    *(s32 *)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 8) = arg1;
}
#pragma schedule off
#endif /* P4_UNIT_0041F6C8 */

#if defined(P4_UNIT_0041F788)
#include "type.h"

void func_00420e50(u8 *);

/* measured: schedule-on fills both the jal delay slot (addiu $a0, 0x68) and
   the jr delay slot (addiu $sp); without it nd 17.  Residual vs retail
   (lw $a0, 0x40($a0)): b210 loads the call argument base into $v0 where
   retail loads straight into the dead $a0 -- allocator coloring floor
   (probed: param reuse, opt3, result local, pointer-typed arg -- all nd 2). */
// FUN_0041F788 NONMATCHING
#pragma schedule on
s32 func_0041f788(u8 *arg0)
{
    func_00420e50(*(u8 **)(arg0 + 0x40) + 0x68);
    return 1;
}
#pragma schedule off
#endif /* P4_UNIT_0041F788 */

#if defined(P4_UNIT_0041F7B0)
#include "type.h"

void func_00420f38(u8 *);

/* measured: schedule-on fills both the jal delay slot (addiu $a0, 0x68) and
   the jr delay slot (addiu $sp); without it nd 17.  Residual vs retail
   (lw $a0, 0x40($a0)): b210 loads the call argument base into $v0 where
   retail loads straight into the dead $a0 -- allocator coloring floor
   (probed: param reuse, opt3, result local, pointer-typed arg -- all nd 2). */
// FUN_0041F7B0 NONMATCHING
#pragma schedule on
s32 func_0041f7b0(u8 *arg0)
{
    func_00420f38(*(u8 **)(arg0 + 0x40) + 0x68);
    return 1;
}
#pragma schedule off
#endif /* P4_UNIT_0041F7B0 */
