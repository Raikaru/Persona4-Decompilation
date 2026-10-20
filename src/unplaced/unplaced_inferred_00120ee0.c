/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00120ee0-001211a0 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdktask.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern s32 D_007242B0;
extern void (*jtbl_008873EC[])(void *);
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern s32 iGpffffb1c8;
extern s32 datGetPendingDateIndex(void);
extern s32 datGetPendingTimeSlot(void);
extern s32 datGetPendingFlag(void);
extern void datSetPendingDateIndex();
extern void datSetPendingTimeSlot();
extern void datSetPendingFlag();
extern s32 calHasDayEntry();
extern void cldSchedulerStart(void);
/* Task work fields read/written by the accessors below; +0x18 is unknown. */
typedef struct CalendarStepWork {
    s32 state;
    s32 unk4;
    u8 pad8[8];
    s32 request10;
    s32 request14;
    s32 unk18;
    struct { f32 x, y; } position;
} CalendarStepWork;

typedef struct { f32 x, y; } TaskRecordPosition;

/* Report whether the task work state has reached 2. */
// FUN_00120EE0
s32 taskRecordIsDone(void *task)
{
    return ((CalendarStepWork *)((SdkTask *)task)->work)->state == 2;
}

/* Set the request word at +0x14; its consumer is outside this unit. */
// FUN_00120F00
void taskRecordRequestSecondary(void *task)
{
    ((CalendarStepWork *)((SdkTask *)task)->work)->request14 = 1;
}

/* Set the request word at +0x10; its consumer is outside this unit. */
// FUN_00120F20
void taskRecordRequestPrimary(void *task)
{
    ((CalendarStepWork *)((SdkTask *)task)->work)->request10 = 1;
}

/* Copy the packed two-float position into the task work. */
// FUN_00120F40
void taskRecordSetPosition(u8 *task, s64 packedPosition)
{
    TaskRecordPosition position;
    u8 *work;
    *(s64 *)&position = packedPosition;
    work = ((SdkTask *)task)->work;
    *(TaskRecordPosition *)&((CalendarStepWork *)work)->position = position;
}

/* Apply a pending date, then prepare the next valid calendar time slot. */
// FUN_00120F70
s32 calendarStepTimeSlot(u8 *task) {
    s32 *state;
    s32 currentState;

    state = (s32 *)((SdkTask *)task)->work;
    currentState = *state;
    switch (currentState) {
    case 0:
        *state = 2;
    case 2:
        if ((iGpffffb1c8 == 0) && (datGetPendingFlag() != 0)) {
            datSetDateIndex(datGetPendingDateIndex());
            datSetTimeSlot(datGetPendingTimeSlot());
            datSetPendingFlag(0);
        }
        if ((datGetTimeSlot() & 0xFF) == 5) {
            datSetPendingDateIndex((s64)(s16)((s16)datGetDateIndex() + 1));
            datSetPendingTimeSlot(0);
        } else if (calHasDayEntry(
                       (s64)(s16)datGetDateIndex()) == 0) {
            datSetPendingDateIndex(datGetDateIndex());
            datSetPendingTimeSlot(((datGetTimeSlot() & 0xFF) + 1) & 0xFF);
        } else {
            datSetPendingDateIndex(datGetDateIndex());
            if ((datGetTimeSlot() & 0xFF) == 0) {
                datSetPendingTimeSlot(3);
            } else if ((datGetTimeSlot() & 0xFF) == 3) {
                datSetPendingTimeSlot(5);
            } else {
                datSetPendingTimeSlot(((datGetTimeSlot() & 0xFF) + 1) & 0xFF);
            }
        }
        datSetPendingFlag(1);
        *state = 3;
    case 3:
        cldSchedulerStart();
        return -1;
    default:
        return 0;
    }
}

/* Release the task work and clear the active task indicator. */
// FUN_00121170
void taskRecordDestroy(u8 *task)
{
    void *work = ((SdkTask *)task)->work;
    D_007242B0 = 0;
    jtbl_008873EC[0](work);
}

/* Task callback with no work; keep the registered callback signature. */
// FUN_001211A0
s32 func_001211a0(u8 *unusedTask)
{
    return 0;
}

#include "btl_shuffle_draw_internal.h"
