/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00102980-00102980 */

#include "sdk_dbprt.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_ot_state_api.h"
extern u8 *D_00764298;
#pragma push
#pragma tailcall off
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_common_subs on
// FUN_00102980
s32 func_00102980(void)
{
    return *(s32 *)(*(u8 **)((u8 *)D_00764298 + 0x38) + 4);
}
#pragma pop
