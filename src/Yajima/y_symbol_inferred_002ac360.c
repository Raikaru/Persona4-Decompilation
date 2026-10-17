/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/Yajima/y_symbol.c); members 002ac360-002ac3c0 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
extern u16 *D_00764658;
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Clear the SMAP reveal bitmap (24 halfwords) [inferred]
// FUN_002AC360
void smapClearRevealTable(void) {
    s16 i;

    i = 0;
    while (i < 0x18) {
        D_00764658[i] = 0;
        i++;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Return a pointer to the SMAP reveal bitmap [inferred]
// FUN_002AC3B0
u32 smapRevealTablePtr(void) {
    return (u32)D_00764658;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Test one SMAP reveal bit: bit index arg0 in row arg1 [inferred]
// FUN_002AC3C0
s64 smapRevealTestBit(s32 arg0, s32 arg1) {
    s32 temp;

    temp = arg0 & 0xff;
    return (s8)(((1 << temp) & 0xffff & D_00764658[arg1 & 0xff]) >> temp);
}
#pragma pop
