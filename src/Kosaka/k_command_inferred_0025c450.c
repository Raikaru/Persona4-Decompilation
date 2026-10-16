#include "btl_action_internal.h"
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
extern s32 D_006367C0[];
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;

s16 datGetDateIndex(void);
void calSplitDayOfYear(s64 arg0, s32 *arg1, s32 *arg2);

s16 calDayOfYearFromMonthDay(s32 arg0, s32 arg1);
void datSetPendingDateIndex(s64 arg0);
void datSetPendingTimeSlot(s32 arg0);
void datSetPendingFlag(s32 arg0);
s32 calIsDayInRange(s64 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);


s32 datGetTimeSlot(void);
s8 calGetDayEntryByPhase(s16 arg0, s32 arg1);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *arg0, void *arg1, f32 farg0,
                           s32 arg2, s32 arg3, s32 arg4);
extern void func_0045ee00(s32 arg0, s32 arg1, void *arg2, s32 arg3,
                           f32 farg0, f32 farg1, s32 arg4);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Source unit: src/promoted/code1_0025.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0025.c; members 0025c450-0025c600 */

// FUN_0025C450
s32 K_Cmd_DAY_ENTRY_BY_PHASE(void) {
    s16 temp_16;

    temp_16 = datGetDateIndex();
    scrSetReturnInt((s32)calGetDayEntryByPhase(temp_16, datGetTimeSlot() & 0xFF));
    return 1;
}

// Intent: Common script command CHK_DAYS (p4flow Common 0x0037): checks the current date against month and day [inferred]
// FUN_0025C4B0
s32 scrCommonChkDays(void) {
    s32 sp3C;
    s32 sp38;
    s32 temp_16;
    s32 temp_17;

    sp3C = 0;
    sp38 = 0;
    temp_17 = scrGetParamInt(0);
    temp_16 = scrGetParamInt(1);
    calSplitDayOfYear(datGetDateIndex(), &sp3C, &sp38);
    if ((sp3C == temp_17) && (sp38 == temp_16)) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

// FUN_0025C560
s32 K_Cmd_DATE_SCHEDULE(void) {
    s32 temp_18;
    s32 temp_17;
    s32 temp_16;

    temp_18 = scrGetParamInt(0);
    temp_17 = scrGetParamInt(1);
    temp_16 = scrGetParamInt(2);
    datSetPendingDateIndex(calDayOfYearFromMonthDay(temp_18, temp_17));
    datSetPendingTimeSlot(temp_16 & 0xFF);
    datSetPendingFlag(1);
    return 1;
}

// FUN_0025C600
s32 K_Cmd_DATE_IN_RANGE(void) {
    s32 temp_19;
    s32 temp_18;
    s32 temp_17;
    s32 temp_16;

    temp_19 = scrGetParamInt(0);
    temp_18 = scrGetParamInt(1);
    temp_17 = scrGetParamInt(2);
    temp_16 = scrGetParamInt(3);
    if (calIsDayInRange(datGetDateIndex(), temp_19, temp_18, temp_17, temp_16) == 1) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

