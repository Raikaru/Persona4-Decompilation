/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00120ee0-001211a0 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
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
extern void func_00260450(void);
typedef struct {
    f32 x;
    f32 y;
} SVec2_0012;

// FUN_00120EE0
s32 taskRecordIsDone(void *arg0)
{
    return *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38)) == 2;
}

// FUN_00120F00
void func_00120f00(void *arg0)
{
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x14) = 1;
}

// FUN_00120F20
void func_00120f20(void *arg0)
{
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x10) = 1;
}

// FUN_00120F40
void taskRecordSetPosition(u8 *arg0, s64 arg1)
{
    SVec2_0012 sp8;
    u8 *temp_3;
    *(s64 *)&sp8 = arg1;
    temp_3 = *(u8 **)(arg0 + 0x38);
    *(SVec2_0012 *)(temp_3 + 0x1C) = sp8;
}

// FUN_00120F70
s32 calendarStepTimeSlot(u8 *arg0) {
    s32 *temp_16;
    s32 temp_3;

    temp_16 = *(s32 **)(arg0 + 0x38);
    temp_3 = *temp_16;
    switch (temp_3) {
    case 0:
        *temp_16 = 2;
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
        *temp_16 = 3;
    case 3:
        func_00260450();
        return -1;
    default:
        return 0;
    }
}

// FUN_00121170
void taskRecordDestroy(u8 *arg0)
{
    void *p = *(void **)((u8 *)arg0 + 0x38);
    D_007242B0 = 0;
    jtbl_008873EC[0](p);
}

// FUN_001211A0
s32 func_001211a0(u8 *unusedTask)
{
    return 0;
}

#include "btl_shuffle_draw_internal.h"
