
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

/* Unit settings: common subexpressions and propagation on; loop invariants off. */
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_loop_invariants off
extern u16 *D_00764658;
#pragma push
#pragma no_branch_likely off
// Clear the SMAP reveal bitmap (24 halfwords).
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
#pragma no_branch_likely off
// Return a pointer to the SMAP reveal bitmap.
// FUN_002AC3B0
u32 smapRevealTablePtr(void) {
    return (u32)D_00764658;
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// Test one SMAP reveal bit: bit column in the given row.
// FUN_002AC3C0
s64 smapRevealTestBit(s32 column, s32 row) {
    s32 bitIndex;

    bitIndex = column & 0xff;
    return (s8)(((1 << bitIndex) & 0xffff & D_00764658[row & 0xff]) >> bitIndex);
}
#pragma pop
