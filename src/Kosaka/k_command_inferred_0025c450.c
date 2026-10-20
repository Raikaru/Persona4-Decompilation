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
void calSplitDayOfYear(s64 dateIndex, s32 *monthOut, s32 *dayOut);

s16 calDayOfYearFromMonthDay(s32 month, s32 day);
void datSetPendingDateIndex(s64 date);
void datSetPendingTimeSlot(s32 timeSlot);
void datSetPendingFlag(s32 flags);
s32 calIsDayInRange(s64 dateIndex, s32 startMonth, s32 startDay, s32 endMonth, s32 endDay);


s32 datGetTimeSlot(void);
s8 calGetDayEntryByPhase(s16 day, s32 phase);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern void PrimDrawPoints(void *colors, void *positions, f32 farg0,
                           s32 count, s32 primitiveType, s32 preserveState);
extern void PrimDrawRadialTriangle(s32 centerX, s32 centerY, void *color, s32 radius,
                           f32 farg0, f32 farg1, s32 preserveState);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0025; members 0025c450-0025c600 */

// FUN_0025C450
s32 K_Cmd_DAY_ENTRY_BY_PHASE(void) {
    s16 dateIndex;

    dateIndex = datGetDateIndex();
    scrSetReturnInt((s32)calGetDayEntryByPhase(dateIndex, datGetTimeSlot() & 0xFF));
    return 1;
}

// Intent: Common script command CHK_DAYS (p4flow Common 0x0037): checks the current date against month and day [inferred]
// FUN_0025C4B0
s32 scrCommonChkDays(void) {
    s32 month;
    s32 day;
    s32 requestedDay;
    s32 requestedMonth;

    month = 0;
    day = 0;
    requestedMonth = scrGetParamInt(0);
    requestedDay = scrGetParamInt(1);
    calSplitDayOfYear(datGetDateIndex(), &month, &day);
    if ((month == requestedMonth) && (day == requestedDay)) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

/* Stage a month/day and byte-sized time slot, then mark the pending calendar update. */
// FUN_0025C560
s32 K_Cmd_DATE_SCHEDULE(void) {
    s32 month;
    s32 day;
    s32 timeSlot;

    month = scrGetParamInt(0);
    day = scrGetParamInt(1);
    timeSlot = scrGetParamInt(2);
    datSetPendingDateIndex(calDayOfYearFromMonthDay(month, day));
    datSetPendingTimeSlot(timeSlot & 0xFF);
    datSetPendingFlag(1);
    return 1;
}

/* Test the current date against script-provided calendar endpoints. */
// FUN_0025C600
s32 K_Cmd_DATE_IN_RANGE(void) {
    s32 startMonth;
    s32 startDay;
    s32 endMonth;
    s32 endDay;

    startMonth = scrGetParamInt(0);
    startDay = scrGetParamInt(1);
    endMonth = scrGetParamInt(2);
    endDay = scrGetParamInt(3);
    if (calIsDayInRange(datGetDateIndex(), startMonth, startDay, endMonth, endDay) == 1) {
        scrSetReturnInt(1);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

