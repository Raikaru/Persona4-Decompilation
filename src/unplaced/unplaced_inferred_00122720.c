/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00122720-00122860 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern void cldDayChangeStartTask();
extern s32 D_00796670[];
extern void cldTimeChangeCreate();
extern s32 iGpffffb1cc;
#pragma push
#pragma opt_propagation on
// FUN_00122720
/* The case values come from decoding the jump table at 0x007466C0 with
   tools/jtbl.py: entry 0 returns 1, entries 1/2/4/5 share one body returning
   0, entry 3 returns 2, and anything >= 6 falls through to the default 1.
   The labels are declared in that object order because b210 lays case bodies
   out in declaration order. */
s32 fadeStatus(void) {
    s32 *state;

    state = (s32 *)iGpffffb1cc;
    if (state == NULL) {
        return 1;
    }
    switch ((u32)state[0]) {
    case 0:
        return 1;
    case 1:
    case 2:
    case 4:
    case 5:
        return 0;
    case 3:
        return 2;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_001227A0
s32 fadeState(void)
{
    if (iGpffffb1cc == 0) {
        return 1;
    }
    return *(s32 *)(iGpffffb1cc + 4);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_001227D0
void fadeBegin(void)
{
    if (iGpffffb1cc != 0) {
        *(s32 *)(iGpffffb1cc + 0x14) = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_001227F0
s32 fadeIsIdle(void)
{
    s32 result;
    u8 *temp_3;
    result = 1;
    temp_3 = (u8 *)iGpffffb1cc;
    if (temp_3 == NULL)
        return 1;
    if (*(s32 *)(temp_3 + 0x14) != 0)
        result = 0;
    return result;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_00122820
void calendarStartDayChange(s32 arg0, s32 arg1)
{
    cldDayChangeStartTask(0, arg0, arg1, D_00796670);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_00122860
void calendarStartTimeChange(s32 arg0, s32 arg1)
{
    cldTimeChangeCreate(0, arg0, arg1, D_00796670);
}
#pragma pop

#include "btl_shuffle_draw_internal.h"
