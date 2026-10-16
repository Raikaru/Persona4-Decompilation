/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00115830-00115830 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Reset a panel: zero two 0x3C-byte sub-blocks and set the header to 1, 0, 0 [inferred]
// FUN_00115830
void datPanelReset(u8 *arg0) {
    memset(arg0 + 8, 0, 0x3C);
    memset(arg0 + 0x44, 0, 0x3C);
    *(s16 *)(arg0 + 0) = 1;
    *(s16 *)(arg0 + 2) = 0;
    *(s32 *)(arg0 + 4) = 0;
}
#pragma pop
