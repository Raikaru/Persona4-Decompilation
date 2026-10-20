#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

s32 kwlnTaskGetTaskByName(void *name);
extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;

s16 datGetDateIndex(void);
void calSplitDayOfYear(s64 dateIndex, s32 *monthOut, s32 *dayOut);
s32 calGetWeekdayOfDay(s64 dateIndex);


extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *colors, void *positions, f32 depth,
                           s32 count, s32 primitiveType, s32 preserveState);
extern void PrimDrawRadialTriangle(s32 centerX, s32 centerY, void *color, s32 radius,
                           f32 angle, f32 depth, s32 preserveState);


// FUN_0025C310
void K_Cmd_TASK_LOOKUP(void) {
    kwlnTaskGetTaskByName(D_006367C0);
}

/* Split the current calendar date and return its month component. */
// FUN_0025C340
s32 scrCommonGetMonth(void) {
    s32 month;
    s32 day;

    month = 0;
    day = 0;
    calSplitDayOfYear(datGetDateIndex(), &month, &day);
    scrSetReturnInt(month);
    return 1;
}

/* Split the current calendar date and return its day-of-month component. */
// FUN_0025C390
s32 scrCommonGetDay(void) {
    s32 month;
    s32 day;

    month = 0;
    day = 0;
    calSplitDayOfYear(datGetDateIndex(), &month, &day);
    scrSetReturnInt(day);
    return 1;
}

// FUN_0025C3E0
s32 K_Cmd_DATE_WEEKDAY(void) {
    scrSetReturnInt(calGetWeekdayOfDay(datGetDateIndex()));
    return 1;
}

