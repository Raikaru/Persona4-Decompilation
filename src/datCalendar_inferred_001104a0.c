/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/datCalendar.c; members 001104a0-00110810 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
extern s32 D_005E45E0[];
extern u8 D_0079B6D8[];
extern void calSplitDayOfYear(s32 seed, s32 *month, s32 *day);
extern s16 D_00797B7A[];
// Intent: Return the day count of the calendar month at 1-based index arg0 from the twelve-entry month-length table, in the April-based year [inferred]
// FUN_001104A0
s32 calGetMonthLength(s32 month)
{
    return D_005E45E0[(month - 1) % 12];
}

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
// Intent: Split a day count within the 365-day year into a 1-based month and day by subtracting month lengths from April [inferred]
// FUN_001104D0
void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut)
{
    s32 monthIndex;
    s32 nextMonth;
    s32 month;
    s32 remainingDays;
    s32 monthsVisited;

    remainingDays = dateIndex % 0x16D;
    month = 3;
    monthsVisited = 0;
    goto loop_test;
loop_body:
    nextMonth = month + 1;
    monthIndex = nextMonth - 1;
    if (remainingDays < D_005E45E0[(nextMonth - 1) % 0xC]) {
        goto done;
    }
    remainingDays = remainingDays - D_005E45E0[monthIndex % 0xC];
    month = nextMonth;
    if (nextMonth < 0xC) {
        goto loop_increment;
    }
    month = 0;
loop_increment:
    monthsVisited = monthsVisited + 1;
loop_test:
    if (monthsVisited < 0xC) {
        goto loop_body;
    }
done:
    *monthOut = month + 1;
    *dayOut = remainingDays + 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return the weekday index (0 to 6) of a day count within the 365-day year [inferred]
// FUN_00110580
s32 calGetWeekdayOfDay(s32 dateIndex) {
    return (((dateIndex % 0x16D) % 7) + 5) % 7;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return the one-based seven-day bucket within the month (despite the recovered function name) [inferred]
// FUN_001105B0
s32 calGetWeekOfYear(s32 dateIndex) {
    s32 month;
    s32 day;

    calSplitDayOfYear(dateIndex, &month, &day);
    day = (day - 1) / 7;
    return day + 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return the day-of-year offset of a month and day: the summed month lengths from April plus day minus one [inferred]
// FUN_00110600
s32 calDayOfYearFromMonthDay(s32 month, s32 day) {
    s32 sum = 0;
    s32 next;

    if (month != 4) {
        month = month - 1;
        if (month == 0) {
            month = 12;
        }
        do {
            next = month - 1;
            sum = sum + D_005E45E0[next % 12];
            if (month == 4) {
                break;
            }
            month = next;
            if (next == 0) {
                month = 12;
            }
        } while (1);
    }
    return sum + (day - 1);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return whether the current calendar day equals month arg1 and day arg2 [inferred]
// FUN_00110680
s32 calIsCurrentMonthDay(s32 unused, s32 month, s32 day) {
    s32 currentMonth;
    s32 currentDay;

    calSplitDayOfYear(D_00797B7A[0], &currentMonth, &currentDay);
    if (currentMonth == month && currentDay == day) {
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return 1 when day count arg0 lies between the start month-day (arg1, arg2) and the end month-day (arg3, arg4), by summed month lengths [inferred]
// FUN_001106F0
s32 calIsDayInRange(s32 dateIndex, s32 startMonth, s32 startDay, s32 endMonth, s32 endDay)
{
    s32 previousEndMonth;
    s32 startMonthCursor;
    s32 startMonthDays;
    s32 endMonthDays;
    s32 previousStartMonth;
    s32 endMonthCursor;
    s32 lower;
    s32 upper;

    startMonthDays = 0;
    if (startMonth != 4) {
        startMonthCursor = startMonth - 1;
        if (startMonthCursor == 0) {
            startMonthCursor = 0xC;
        }
loop_3:
        previousStartMonth = startMonthCursor - 1;
        startMonthDays += D_005E45E0[previousStartMonth % 12];
        if (startMonthCursor != 4) {
            startMonthCursor = previousStartMonth;
            if (previousStartMonth == 0) {
                startMonthCursor = 0xC;
            }
            goto loop_3;
        }
    }
    lower = startMonthDays + (startDay - 1);
    endMonthDays = 0;
    if (endMonth != 4) {
        endMonthCursor = endMonth - 1;
        if (endMonthCursor == 0) {
            endMonthCursor = 0xC;
        }
loop_9:
        previousEndMonth = endMonthCursor - 1;
        endMonthDays += D_005E45E0[previousEndMonth % 12];
        if (endMonthCursor != 4) {
            endMonthCursor = previousEndMonth;
            if (previousEndMonth == 0) {
                endMonthCursor = 0xC;
            }
            goto loop_9;
        }
    }
    upper = endMonthDays + (endDay - 1);
    if (dateIndex < lower) {
        goto fail;
    }
    if (dateIndex > upper) {
        goto fail;
    }
    return 1;
fail:
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Set one byte of the 1536-entry state table; the new-game reset clears the table [inferred]
// FUN_00110810
void datSetStateTableEntry(s32 index, u8 flags)
{
    D_0079B6D8[index] = flags;
}
#pragma pop
