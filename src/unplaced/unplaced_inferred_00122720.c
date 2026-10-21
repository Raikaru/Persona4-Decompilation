
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "calendar_fade_internal.h"
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
/* Report fade progress: 0 transitioning, 2 held, or 1 inactive/child-waiting. */
// FUN_00122720
/* Jump table: state 0 returns 1, states 1/2/4/5 return 0, state 3 returns 2, anything else returns
 * 1; labels follow retail body order. */
s32 fadeStatus(void) {
    CalendarFade *state;

    state = (CalendarFade *)iGpffffb1cc;
    if (state == NULL) {
        return 1;
    }
    switch ((u32)state->state) {
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
/* Return the configured fade mode, or 1 when no fade exists. */
// FUN_001227A0
s32 fadeState(void)
{
    if (iGpffffb1cc == 0) {
        return 1;
    }
    return ((CalendarFade *)iGpffffb1cc)->mode;
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Request calendar synchronization after the fade reaches its hold state. */
// FUN_001227D0
void fadeBegin(void)
{
    if (iGpffffb1cc != 0) {
        ((CalendarFade *)iGpffffb1cc)->changeRequested = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Report whether a calendar-change request is no longer pending. */
// FUN_001227F0
s32 fadeIsIdle(void)
{
    s32 result;
    u8 *fade;
    result = 1;
    fade = (u8 *)iGpffffb1cc;
    if (fade == NULL)
        return 1;
    if (((CalendarFade *)fade)->changeRequested != 0)
        result = 0;
    return result;
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Start the day-change task with the previous and current day. */
// FUN_00122820
void calendarStartDayChange(s32 previousDay, s32 currentDay)
{
    cldDayChangeStartTask(0, previousDay, currentDay, D_00796670);
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Start the time-change task with the previous and current period. */
// FUN_00122860
void calendarStartTimeChange(s32 previousPeriod, s32 currentPeriod)
{
    cldTimeChangeCreate(0, previousPeriod, currentPeriod, D_00796670);
}
#pragma pop

#include "btl_shuffle_draw_internal.h"
