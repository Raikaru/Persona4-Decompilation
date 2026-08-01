/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_003D38E0)
#include "type.h"

/* measured: schedule on is load-bearing for retail's b/exit delay-slot moves.
   NONMATCHING: retail keeps both null-returns out of line (beqz; lw; beqz;
   sw; b exit/move $v0,$a0; b exit/move $v0,$zero; move $v0,$zero; jr $ra,
   12 instr); b210 if-converts the branch to beql with the move annulled in
   its slot and merges the exits (11 instr, nd 19 -> 15 with schedule on).
   Residual: nd 15. */
// FUN_003D38E0 NONMATCHING
#pragma schedule on
u8 *func_003d38e0(u8 *arg0, s32 arg1) {
    u8 *p;

    if (arg0 != NULL) {
        p = *(u8 **)((u8 *)arg0 + 0x14);
        if (p != NULL) {
            *(s32 *)(p + 0x14) = arg1;
            return arg0;
        }
    }
    return NULL;
}
#pragma schedule off
#endif /* P4_UNIT_003D38E0 */

#if defined(P4_UNIT_003D6010)
#include "type.h"

void func_003df7f0(s32 arg0);

/* measured: without #pragma schedule on, MWCC emits lw $a0, 0x10($a0) before
   the jal with a nop in its delay slot and leaves the jr slot unfilled;
   retail fills both slots (nd 17 -> 0). */
// FUN_003D6010
#pragma schedule on
s32 func_003d6010(u8 *arg0) {
    func_003df7f0(*(s32 *)(arg0 + 0x10));
    return 1;
}
#pragma schedule off
#endif /* P4_UNIT_003D6010 */

#if defined(P4_UNIT_003D7CD0)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 18 -> 0). */
// FUN_003D7CD0
#pragma schedule on
u8 **func_003d7cd0(u8 **arg0) {
    u8 *p;

    p = *(u8 **)((u8 *)arg0 + 0x14);
    *(s32 *)(p + 0x40) += 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003D7CD0 */

#if defined(P4_UNIT_003D8130)
#include "type.h"

extern s32 D_0072483C;

/* measured: schedule on is required for the final lw in the jr delay slot
   (nd 12 -> 1).
   NONMATCHING: residual is the final addu's commutative operand order
   (ours addu $v0, $v1, $v0; retail addu $v0, $v0, $v1) -- probed 15+
   expression orders and temp/pointer shapes; MWCC always emits rs=left
   while retail's allocator put the sll result in $v0.  Floor. */
// FUN_003D8130 NONMATCHING
#pragma schedule on
s32 func_003d8130(s32 arg0, s32 arg1) {
    return *(s32 *)(arg0 + D_0072483C + arg1 * 4 + 8);
}
#pragma schedule off
#endif /* P4_UNIT_003D8130 */

#if defined(P4_UNIT_003D81A0)
#include "type.h"

/* measured: schedule on is load-bearing (nd 18 -> 14; default keeps the
   b/exit structure but leaves its delay slot empty).  NONMATCHING: retail
   keeps the else body out of line (sltiu; beqz; nop; addiu; sllv;
   b exit/sll; move $v0,$zero; jr $ra); b210 if-converts the branch to
   beql with the move annulled in its slot across all probed shapes. */
// FUN_003D81A0 NONMATCHING
#pragma schedule on
s32 func_003d81a0(u32 arg0) {
    if (arg0 < 9U) {
        return (1 << arg0) * 4;
    }
    return 0;
}
#pragma schedule off
#endif /* P4_UNIT_003D81A0 */

#if defined(P4_UNIT_003DF440)
#include "type.h"

extern s32 D_0072484C;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 16 -> 0). */
// FUN_003DF440
#pragma schedule on
s32 func_003df440(s32 arg0) {
    D_0072484C += 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003DF440 */

#if defined(P4_UNIT_003DF460)
#include "type.h"

extern s32 D_0072484C;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 16 -> 0). */
// FUN_003DF460
#pragma schedule on
s32 func_003df460(s32 arg0) {
    D_0072484C -= 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003DF460 */

#if defined(P4_UNIT_003DF4B0)
#include "type.h"

extern s32 D_00724854;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final sw (nd 16 -> 0). */
// FUN_003DF4B0
#pragma schedule on
s32 func_003df4b0(s32 arg0) {
    D_00724854 -= 1;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003DF4B0 */

#if defined(P4_UNIT_003DF870)
#include "type.h"

/* NONMATCHING: retail schedules the result addu into the jr $ra delay slot
   (lw 0xc; mult; lw 0; jr; addu).  #pragma schedule on fills the slot but
   hoists the independent base load above the mult and recolors the stride
   load to $v1 (nd 8 -> 9); every probed expression order/temp form does the
   same, and default leaves the slot as nop (nd 8).  Floor. */
// FUN_003DF870 NONMATCHING
s32 func_003df870(s32 *arg0, s32 arg1) {
    return arg0[0] + arg0[3] * arg1;
}
#endif /* P4_UNIT_003DF870 */

#if defined(P4_UNIT_003DF8A0)
#include "type.h"

/* NONMATCHING: retail schedules the result addu into the jr $ra delay slot
   (lw 0xc; lw 4; mult; lw 0; jr; addu).  #pragma schedule on fills the slot
   but hoists the independent base load above the mult and recolors the
   stride load to $v1 (nd 8 -> 10); default leaves the slot as nop (nd 8).
   Floor. */
// FUN_003DF8A0 NONMATCHING
s32 func_003df8a0(s32 *arg0) {
    return arg0[0] + arg0[3] * arg0[1];
}
#endif /* P4_UNIT_003DF8A0 */
