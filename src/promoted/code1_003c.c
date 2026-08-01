/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_003C1D20)
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
#endif /* P4_UNIT_003C1D20 */

#if defined(P4_UNIT_003C2130)
#include "type.h"

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
#endif /* P4_UNIT_003C2130 */

#if defined(P4_UNIT_003C2A60)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop) and colors the halfword scratch $v0; retail fills the slot
   with the final store and colors it $v1 (nd 15 -> 0). */
// FUN_003C2A60
#pragma schedule on
u8 *func_003c2a60(u8 *arg0) {
    ((s16 *)arg0)[7] = (s16)(((s16 *)arg0)[7] + 1);
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003C2A60 */

#if defined(P4_UNIT_003C4A40)
#include "type.h"

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 11 -> 0). */
// FUN_003C4A40
#pragma schedule on
u8 *func_003c4a40(u8 *arg0) {
    ((s32 *)arg0)[2] = 0;
    ((s32 *)arg0)[0] = 0;
    ((s32 *)arg0)[1] = 0;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003C4A40 */

#if defined(P4_UNIT_003C8CA0)
#include "type.h"

extern s32 D_007647EC;

/* measured: without #pragma schedule on, MWCC leaves the jr $ra delay slot
   unfilled (nop); retail fills it with the final store (nd 15 -> 0). */
// FUN_003C8CA0
#pragma schedule on
s32 func_003c8ca0(s32 arg0) {
    D_007647EC++;
    return arg0;
}
#pragma schedule off
#endif /* P4_UNIT_003C8CA0 */

#if defined(P4_UNIT_003CC130)
#include "type.h"

void func_003cc460();
void func_003d4e00();
void func_003d4e90();
void func_003d4d70();

/* measured: without #pragma schedule on, MWCC emits ld $ra / addiu $sp /
   jr $ra / nop; retail restores sp in the jr delay slot (nd 6 -> 0). */
// FUN_003CC130
#pragma schedule on
void func_003cc130(void) {
    func_003cc460();
    func_003d4e00();
    func_003d4e90();
    func_003d4d70();
}
#pragma schedule off
#endif /* P4_UNIT_003CC130 */

#if defined(P4_UNIT_003CC240)
#include "type.h"

/* measured: without #pragma schedule on, MWCC emits addiu $v0, 1 before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */
// FUN_003CC240
#pragma schedule on
s32 func_003cc240(void) {
    return 1;
}
#pragma schedule off
#endif /* P4_UNIT_003CC240 */

#if defined(P4_UNIT_003CC6E0)
#include "type.h"

void func_003f32d0();

/* measured: schedule on is load-bearing for the jal/jr $ra delay slots.
   NONMATCHING: retail sinks the if-body out of line (bnez/ b exit; ld ra /
   body / b back / jr ra; addiu sp, 15 instr); b210 compiles every honest
   form of this if inline as a beql skip (13 instr) across 30+ probe
   shapes, so the layout is not reproducible.  Residual: nd 17. */
// FUN_003CC6E0 NONMATCHING
#pragma schedule on
void func_003cc6e0(u8 *arg0) {
    if (((s32 *)arg0)[6] != 0) {
        func_003f32d0();
        func_003f32d0();
    }
}
#pragma schedule off
#endif /* P4_UNIT_003CC6E0 */

#if defined(P4_UNIT_003CFA70)
#include "type.h"

extern s32 D_0070B110[];

/* measured: without #pragma schedule on, MWCC emits lui / addiu before
   jr $ra with an unfilled delay slot; retail fills the slot (nd 6 -> 0). */
// FUN_003CFA70
#pragma schedule on
s32 *func_003cfa70(void) {
    return D_0070B110;
}
#pragma schedule off
#endif /* P4_UNIT_003CFA70 */
