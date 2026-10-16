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
s32 calGetMonthLength(s32 arg0)
{
    return D_005E45E0[(arg0 - 1) % 12];
}

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
// Intent: Split a day count within the 365-day year into a 1-based month and day by subtracting month lengths from April [inferred]
// FUN_001104D0
void calSplitDayOfYear(s32 arg0, s32 *arg1, s32 *arg2)
{
    s32 temp_8;
    s32 temp_9;
    s32 var_12;
    s32 var_11;
    s32 var_10;

    var_11 = arg0 % 0x16D;
    var_12 = 3;
    var_10 = 0;
    goto loop_test;
loop_body:
    temp_9 = var_12 + 1;
    temp_8 = temp_9 - 1;
    if (var_11 < D_005E45E0[(temp_9 - 1) % 0xC]) {
        goto done;
    }
    var_11 = var_11 - D_005E45E0[temp_8 % 0xC];
    var_12 = temp_9;
    if (temp_9 < 0xC) {
        goto loop_increment;
    }
    var_12 = 0;
loop_increment:
    var_10 = var_10 + 1;
loop_test:
    if (var_10 < 0xC) {
        goto loop_body;
    }
done:
    *arg1 = var_12 + 1;
    *arg2 = var_11 + 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return the weekday index (0 to 6) of a day count within the 365-day year [inferred]
// FUN_00110580
s32 calGetWeekdayOfDay(s32 arg0) {
    return (((arg0 % 0x16D) % 7) + 5) % 7;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return the week of the year (1-based) for a day count, from its day of the year [inferred]
// FUN_001105B0
s32 calGetWeekOfYear(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    calSplitDayOfYear(arg0, &sp1C, &sp18);
    sp18 = (sp18 - 1) / 7;
    return sp18 + 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return the day-of-year offset of a month and day: the summed month lengths from April plus day minus one [inferred]
// FUN_00110600
s32 calDayOfYearFromMonthDay(s32 arg0, s32 arg1) {
    s32 sum = 0;
    s32 next;

    if (arg0 != 4) {
        arg0 = arg0 - 1;
        if (arg0 == 0) {
            arg0 = 12;
        }
        do {
            next = arg0 - 1;
            sum = sum + D_005E45E0[next % 12];
            if (arg0 == 4) {
                break;
            }
            arg0 = next;
            if (next == 0) {
                arg0 = 12;
            }
        } while (1);
    }
    return sum + (arg1 - 1);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Intent: Return whether the current calendar day equals month arg1 and day arg2 [inferred]
// FUN_00110680
s32 calIsCurrentMonthDay(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp3C;
    s32 sp38;

    calSplitDayOfYear(D_00797B7A[0], &sp3C, &sp38);
    if (sp3C == arg1 && sp38 == arg2) {
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
s32 calIsDayInRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 temp_6;
    s32 var_11;
    s32 var_10;
    s32 var_10_2;
    s32 temp_9;
    s32 var_7;
    s32 lower;
    s32 upper;

    var_10 = 0;
    if (arg1 != 4) {
        var_11 = arg1 - 1;
        if (var_11 == 0) {
            var_11 = 0xC;
        }
loop_3:
        temp_9 = var_11 - 1;
        var_10 += D_005E45E0[temp_9 % 12];
        if (var_11 != 4) {
            var_11 = temp_9;
            if (temp_9 == 0) {
                var_11 = 0xC;
            }
            goto loop_3;
        }
    }
    lower = var_10 + (arg2 - 1);
    var_10_2 = 0;
    if (arg3 != 4) {
        var_7 = arg3 - 1;
        if (var_7 == 0) {
            var_7 = 0xC;
        }
loop_9:
        temp_6 = var_7 - 1;
        var_10_2 += D_005E45E0[temp_6 % 12];
        if (var_7 != 4) {
            var_7 = temp_6;
            if (temp_6 == 0) {
                var_7 = 0xC;
            }
            goto loop_9;
        }
    }
    upper = var_10_2 + (arg4 - 1);
    if (arg0 < lower) {
        goto fail;
    }
    if (arg0 > upper) {
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
void datSetStateTableEntry(s32 arg0, u8 arg1)
{
    D_0079B6D8[arg0] = arg1;
}
#pragma pop
