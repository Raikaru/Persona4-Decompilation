/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/h_snd.c; members 00459760-00459760 */

#include "include_asm.h"
#include "type.h"
#include "primitive_rectangle_packet.h"
#include "shd_misc_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "rw_types_internal.h"
extern s32 D_008D2B90[];
extern s16 D_008D2B98[];
#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
// FUN_00459760
s16 func_00459760(void)
{
    if (D_008D2B90[0] == 0) {
        return -1;
    }
    return D_008D2B98[0];
}
#pragma pop
