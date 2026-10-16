#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
extern u8 *datPersonaGetSkills(void);
extern s32 datPersonaCollectLearnableSkills(u8 *persona, void *skills, void *levels);
extern void func_0010e710(s32, u8 *, s32);
typedef struct {
    f32 x;
    f32 y;
} Vec2f;
void datEntryDrawIdName(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3);
void ShdSkill_DrawDescriptor(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3);
void ShdSkill_DrawEntryName(Vec2f arg0, f32 fparg0, u8 arg1, void *arg2, s32 arg3);
void datPanelDrawCompareIcon(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
void drawUnitStatusPanel(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3, s32 arg4_2);
extern s32 iGpffffb1b4;
extern u8 iGpffff9bb8[8]; /* Default surname at gp - 0x6448. */
extern u8 iGpffff9bc0[8]; /* Default given name at gp - 0x6440. */

extern s32 D_005E45E0[];
extern s8 D_005E3A02[];
extern s8 D_005E3A04[];
extern u8 D_00797B7C[];
extern s32 D_0079B40C[];

extern u8 D_0079B6D8[];

extern s8 D_005E3A00[];

s32 func_0029e970(void);
void func_0029e980(s32);

void func_00106390(s32, s32);
s32 calReadDayFlagMask(void);
void calWriteDayFlagMask(s32);
void datInitDefaultGameState(void);
void func_004534f0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern s32 iGpffffb1bc;
extern s32 iGpffffb19c;
extern void calSplitDayOfYear(s32 seed, s32 *month, s32 *day);
extern s32 iGpffffb1b8;
extern s32 iGpffffb1f0;
extern void (*jtbl_008873EC[])(void *);
extern u8 *datSaveBuildImage(s32 a, s32 *b, s32 c);
extern u8 D_007BBF00[];
extern void memcpy(void *dst, void *src, s32 n);
extern s16 D_00797B7A[];

extern u8 D_0079BEF4[];
extern s32 D_005E4610[];
extern s32 datGetFlag(s32 arg0);
extern void H_Pad_StopRumble(void);
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
typedef struct KwlnTask KwlnTask;
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);
extern u16 datCalcThresholdKindById(s16 arg0, s32 arg1);
extern u32 datCalcSkillCostById(s16 arg0, s32 arg1);
extern void *datCalcGetIdRecord(u16 arg0);

extern void sdkSpriteDrawOnceAux(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, f32 z, s32 arg4);
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          f32 z, s32 arg6);
extern u32 datEntryGetFlags(s16 arg0);
extern s32 resourceFindByName(void *param);
extern u16 func_001068b0(s16 arg0);
extern u16 func_001068e0(s16 arg0);
extern u16 func_00106940(s16 arg0);
extern u16 func_00106970(s16 arg0);
extern s32 func_00106c30(s16 arg0, s16 arg1);
extern s32 datIdBand(s16 arg0);
extern s16 func_00106cd0(s16 arg0, s16 arg1);
extern u8 *datPersonaDisplayName(s16 arg0);
extern s8 calendarGetValueLowByte(void);
extern s16 calendarStateDaysSinceApr5(void);
extern s16 calendarStatePeriod(void);
extern u8 D_005E4F70[];
extern s8 D_005E47F0[];
static inline s64 p4_0011_signext16(s16 arg0)
{
    return (s64)arg0;
}
static inline s32 p4_00113520_add(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 p4_00110850_add(s32 offset, s32 base)
{
    s32 temp;

    temp = offset;
    return base + temp;
}
static inline s32 p4_0011_add_left(s32 left, s32 right)
{
    return left + right;
}
static inline s64 p4_0011_load_s8(s8 *ptr)
{
    s64 temp;

    temp = *ptr;
    return temp;
}


// Intent: Return the saved word at the cleared-state global; g_data stores it as the cleared flag [inferred]
// FUN_00110460
u32 datGetClearedWord(void) {
    return *(u32 *)D_0079BEF4;
}
// Intent: Return the day count of the calendar month at 1-based index arg0 from the twelve-entry month-length table, in the April-based year [inferred]
// FUN_001104A0
s32 calGetMonthLength(s32 arg0)
{
    return D_005E45E0[(arg0 - 1) % 12];
}



 
/* measured: opt_loop_invariants on hoists the divisor and table base into the loop preheader. */
#pragma opt_loop_invariants on
/* measured: opt_propagation off preserves the retail duplicate table loads and local colouring. */
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
/* measured: restore opt_propagation after calSplitDayOfYear. */
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Return the weekday index (0 to 6) of a day count within the 365-day year [inferred]
// FUN_00110580
s32 calGetWeekdayOfDay(s32 arg0) {
    return (((arg0 % 0x16D) % 7) + 5) % 7;
}
// Intent: Return the week of the year (1-based) for a day count, from its day of the year [inferred]
// FUN_001105B0
s32 calGetWeekOfYear(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    calSplitDayOfYear(arg0, &sp1C, &sp18);
    sp18 = (sp18 - 1) / 7;
    return sp18 + 1;
}

/* The month index is walked in the PARAMETER, not a fresh local: retail keeps
   it in $a0 for the whole loop, and any separate `cur` local rotates the three
   live values through $a3/$a2/$a0 instead (identical instruction sequence,
   11 differing words). */
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
// Intent: Set one byte of the 1536-entry state table; the new-game reset clears the table [inferred]
// FUN_00110810
void datSetStateTableEntry(s32 arg0, u8 arg1)
{
    D_0079B6D8[arg0] = arg1;
}



// Intent: Return a day-table value for day arg0 and phase arg1: a flag-based result for today's date, else the byte from the day table [inferred]
// FUN_00110850
s64 calGetDayTableValue(s32 arg0, u32 arg1)
{
    s32 temp_4;
    s32 temp_5;
    s32 temp_6;
    u32 var_5;

    var_5 = arg1;
    if ((arg0 == D_00797B7A[0]) && (var_5 == D_00797B7C[0])) {
        if (D_0079B40C[0] & 8) {
            return 0;
        }
        if (D_0079B40C[0] & 0x10) {
            return 1;
        }
        if (D_0079B40C[0] & 0x20) {
            return 2;
        }
        if (D_0079B40C[0] & 0x40) {
            return 3;
        }
        if (D_0079B40C[0] & 0x80) {
            return 4;
        }
        goto block_12;
    }
block_12:
    switch (var_5) {
    case 0:
    case 1:
        var_5 = 0;
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        var_5 = 1;
        break;
    }
    temp_4 = arg0 * 6;
    temp_5 = p4_00110850_add(temp_4, (s32)&D_005E3A02);
    temp_6 = var_5 * 2;
    return (s64) ((s64) *((u8 *)(temp_6 + temp_5)) << 0x38) >> 0x38;
}
/* measured: opt_propagation off retains the retail byte-load staging. */
#pragma opt_propagation off
/* measured probe: opt_common_subs off preserves the retail fallback loads. */
#pragma opt_common_subs off
// Intent: Return the day-table entry for a day and phase: the override value when one is set, else the stored byte [inferred]
// FUN_00110960
s64 calGetDayEntryByPhase(s32 arg0, u32 arg1)
{
    s32 loaded;
    s32 value;
    s64 result;
    s32 selection;

    result = -1;
    if ((arg0 == (s16)calendarStateDaysSinceApr5()) &&
        (arg1 == (s16)calendarStatePeriod())) {
        result = (s8)calendarGetValueLowByte();
    }
    if ((s8)result == -1) {
        switch (arg1) {
        case 0:
        case 1:
            selection = 0;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            selection = 1;
            break;
        }
        value = arg0 * 6;
        value = p4_00110850_add(value, (s32)&D_005E3A02);
        selection *= 2;
        value = p4_0011_add_left(selection, value);
        loaded = p4_0011_load_s8((s8 *)value);
        result = loaded;
    }
    return result;
}
/* measured: restore opt_propagation after calGetDayEntryByPhase. */
#pragma opt_propagation on
/* measured probe: restore opt_common_subs after calGetDayEntryByPhase. */
#pragma opt_common_subs on
static inline s64 calendarOverrideValue(s32 date, s32 phase)
{
    s64 result;
    s32 address;
    s32 loaded;

    result = -1;
    if (date == (s16)calendarStateDaysSinceApr5() && (s16)calendarStatePeriod() == phase)
        result = (s8)calendarGetValueLowByte();
    if ((s8)result == -1) {
        address = p4_00110850_add(date * 6, (s32)D_005E3A02);
        loaded = p4_0011_load_s8((s8 *)address + 2);
        result = loaded;
    }
    return result;
}

/* Measured: keep the shared month divisor live through December wrapping,
   and retain the signed override staging in both inlined phase branches. */
#pragma opt_propagation off
#pragma opt_common_subs off
// Intent: Return the day-table entry for a month and day, choosing phase 3 or 4 from the day-of-year test [inferred]
// FUN_00110A60
s64 calGetDayEntryForMonthDay(s32 month, s32 day)
{
    extern s32 calHasDayEntry(s32 date);
    s32 previous;
    s32 total;
    s32 next;
    s32 divisor;

    total = 0;
    if (month != 4) {
        previous = month - 1;
        if (previous == 0) previous = 12;
        do {
            next = previous - 1;
            divisor = 12;
            total += D_005E45E0[next % divisor];
            if (previous == 4) break;
            previous = next;
            if (next == 0) previous = divisor;
        } while (1);
    }
    if (calHasDayEntry(total + (day - 1)) == 1)
        return calendarOverrideValue(calDayOfYearFromMonthDay(month, day), 3);
    return calendarOverrideValue(calDayOfYearFromMonthDay(month, day), 4);
}
#pragma opt_common_subs on
#pragma opt_propagation on
// Intent: Return the packed 16-bit day entry for day arg0, combining two byte table values [inferred]
// FUN_00110C50
s32 calGetPackedDayEntry(s32 arg0, s32 arg1)
{
    s32 temp_3_3;
    s32 temp_4;
    s32 temp_5;
    s32 temp_2;
    u16 temp_3;
    u16 temp_3_2;
    s32 var_2;
    s32 var_5;

    if ((arg1 + 3) < arg0) {
        temp_4 = arg0 * 6;
        temp_3 = *(u16 *)((s32)&D_005E3A02 + temp_4);
        if (temp_3 & 0x8000) {
            temp_5 = (u16)(temp_3 & 0x7F00) >> 8;
            var_5 = temp_5 & 0xFFFF;
        } else {
            var_5 = temp_3 & 0xFF;
        }
        temp_3_2 = *(u16 *)((s32)&D_005E3A04 + temp_4);
        if (temp_3_2 & 0x8000) {
            temp_2 = (u16)(temp_3_2 & 0x7F00) >> 8;
            var_2 = temp_2 & 0xFFFF;
        } else {
            var_2 = temp_3_2 & 0xFF;
        }
    } else {
        temp_3_3 = arg0 * 6;
        var_5 = *(u8 *)((s32)&D_005E3A02 + temp_3_3);
        var_2 = *(u8 *)((s32)&D_005E3A04 + temp_3_3);
    }
    return ((var_5 & 0xFFFF) + ((var_2 & 0xFFFF) * 0x10)) & 0xFFFF;
}
// Intent: Return whether the day table has an entry for day arg0 [inferred]
// FUN_00110D30
s32 calHasDayEntry(s32 arg0)
{
    return D_005E3A00[arg0 * 6] != 0;
}



/* measured: opt_rebuildconditionals off preserves the direct range guards. */
#pragma opt_rebuildconditionals off
// Intent: Return flag 1 when day-of-year arg0 is in Apr 1 to Jun 12 or on or after Oct 10, and flag 2 when the day table has an entry for the current day [inferred]
// FUN_00110D60
s32 calGetDayWindowFlags(s32 arg0)
{
    s32 temp_18;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 var_16;
    s32 var_2;
    s32 var_2_2;

    var_16 = 0;
    temp_18 = calDayOfYearFromMonthDay(4, 1);
    temp_2 = calDayOfYearFromMonthDay(6, 0xC);
    if ((arg0 >= temp_18) && (arg0 <= temp_2)) {
        var_2 = 1;
    } else {
        var_2 = 0;
    }
    if (var_2 == 0) {
        temp_2_2 = calDayOfYearFromMonthDay(0xA, 0xA);
        temp_2_3 = temp_2_2 + 0x16C;
        if ((arg0 >= temp_2_2) && (arg0 <= temp_2_3)) {
            var_2_2 = 1;
        } else {
            var_2_2 = 0;
        }
        if (var_2_2 != 0) {
            goto block_10;
        }
    } else {
block_10:
        var_16 |= 1;
    }
    if (D_005E3A00[D_00797B7A[0] * 6] != 0) {
        var_16 |= 2;
    }
    return var_16;
}
/* measured: restore opt_rebuildconditionals on after calGetDayWindowFlags. */
#pragma opt_rebuildconditionals on
// Intent: Set the state-image pending flag that calRestoreStateImage reads [inferred]
// FUN_00110E70
void calSetStateImagePending(s32 arg0)
{
    iGpffffb1b4 = arg0;
}

// Intent: Capture the current save state into the state buffer and mark it pending [inferred]
// FUN_00110E80
void calCaptureStateImage(void) {
    s32 sp3C;
    u8 *p;
    s32 n;

    p = datSaveBuildImage(0, &sp3C, 1);
    n = sp3C;
    memcpy(D_007BBF00, p, n);
    iGpffffb1b8 = n;
    jtbl_008873EC[0](p);
    iGpffffb1b4 = 1;
}

/* measured: opt_propagation off is required to preserve retail GP-load argument materialization order. */
#pragma opt_propagation off
// Intent: Restore the captured state image when one is pending, then clear the pending flag [inferred]
// FUN_00110F00
s32 calRestoreStateImage(void)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_18;
    s32 buffer;
    s32 zero;
    s32 var_2;

    var_2 = 0;
    temp_16 = iGpffffb19c;
    if (iGpffffb1b4 != 0) {
        sdlSchedulerDestroy();
        func_00122520(1, 1);
        temp_17 = calReadDayFlagMask();
        datInitDefaultGameState();
        iGpffffb1f0 = 1;
        buffer = (s32)&D_007BBF00;
        temp_18 = iGpffffb1b8;
        zero = 0;
        buffer += 4;
        func_0010e710(zero, (u8 *)buffer, temp_18);
        calWriteDayFlagMask(temp_17);
        iGpffffb19c = temp_16;
        func_001029a0(0x1A, 0, 0, 0);
        var_2 = 1;
    }
    return var_2;
}
/* measured: restore opt_propagation after calRestoreStateImage. */
#pragma opt_propagation on
// Intent: Destroy the scheduler, then run the two cleanup calls with arguments (1, 1) and (0x1B, 0, 0, 8) [inferred]
// FUN_00110FC0
void sdlSchedulerTeardown(void) {
    sdlSchedulerDestroy();
    func_00122520(1, 1);
    func_001029a0(0x1B, 0, 0, 8);
}

// Intent: Release the active script-process handle if one exists; kwln registers it as a callback [inferred]
// FUN_00111010
void scrReleaseActiveHandle(void)
{
    s32 temp_2;

    if ((temp_2 = func_0029e970()) != 0) {
        func_0029e980(temp_2);
    }
}



// Intent: Set the six default day flags (0x39 to 0x3E) and clear the saved mask when arg0 is nonzero [inferred]
// FUN_00111050
void calSetDefaultDayFlags(s32 arg0)
{
    func_00106390(0x39, 1);
    func_00106390(0x3A, 1);
    func_00106390(0x3B, 0);
    func_00106390(0x3C, 1);
    func_00106390(0x3D, 1);
    func_00106390(0x3E, 0);
    if (arg0 != 0) {
        iGpffffb1bc = 0;
    }
}

// Intent: Read the six day flags in the flag table into a six-bit mask [inferred]
// FUN_001110E0
s32 calReadDayFlagMask(void) {
    u32 var_17;
    s32 var_16;

    var_16 = 0;
    for (var_17 = 0; var_17 < 6U; var_17++) {
        if (datGetFlag(D_005E4610[var_17]) != 0) {
            var_16 |= 1 << var_17;
        }
    }
    return var_16;
}
// Intent: Write each of the six day flags from the matching bit of a six-bit mask [inferred]
// FUN_00111160
void calWriteDayFlagMask(s32 arg0)
{
    u32 var_16;
    var_16 = 0;
    for (var_16 = 0; var_16 < 6U; var_16++) {
        if (arg0 & (1 << var_16)) {
            func_00106390(D_005E4610[var_16], 1);
        } else {
            func_00106390(D_005E4610[var_16], 0);
        }
    }
}
// Intent: Read the six day flags into a mask, mark it valid with bit 31, and store it as the saved mask [inferred]
// FUN_00111200
s32 calCaptureDayFlagMask(void)
{
    u32 var_17;
    s32 var_16;
    s32 result;

    var_16 = 0;
    for (var_17 = 0; var_17 < 6U; var_17++) {
        if (datGetFlag(D_005E4610[var_17]) != 0) {
            var_16 |= 1 << var_17;
        }
    }
    result = var_16 | 0x80000000;
    iGpffffb1bc = result;
    return result;
}
// Intent: Restore the six day flags from the saved mask when it is valid, else from the defaults, then clear the saved mask [inferred]
// FUN_00111290
void calRestoreDayFlagMask(void)
{
    s32 temp_16;
    u32 var_17;

    temp_16 = iGpffffb1bc;
    if (temp_16 & 0x80000000) {
        for (var_17 = 0; var_17 < 6U; var_17++) {
            if (temp_16 & (1 << var_17)) {
                func_00106390(D_005E4610[var_17], 1);
            } else {
                func_00106390(D_005E4610[var_17], 0);
            }
        }
    } else {
        func_00106390(0x39, 1);
        func_00106390(0x3A, 1);
        func_00106390(0x3B, 0);
        func_00106390(0x3C, 1);
        func_00106390(0x3D, 1);
        func_00106390(0x3E, 0);
    }
    iGpffffb1bc = 0;
}
/* Measured: 1032 bytes, 58 resolved relocations, eight zero alignment bytes.
 * Default names are separate eight-byte objects. Keep each table's base
 * with the trailing halfword offsets and reload maxima after Persona setup. */
// Intent: Reset unit, roster, party, time and community state to the new-game defaults [inferred]
// FUN_001113B0
void datInitDefaultGameState(void)
{
    s32 j;
    s32 i;
    u8 *p;
    u8 *q;
    u16 datCalcMaxHpById(s16);
    u16 datCalcMaxSpById(s16);
    void datSetCategoryValueById(s16, s16, s16);
    void datCalcInitUnitById(s16);
    void func_00105690(s16, u8);
    void func_001056e0(s16, s16);
    void func_00105730(s16, s16);
    void datSetHeroExp(s16, u32);
    void func_00105c90(s16, s16);
    void datCalcSetBadStatusById(s16, s16);
    void func_00105dc0(s16, s16, s16);
    void datSetMoney(u32);
    void datSetPartyId(s32, s16);
    void datSetDateIndex(s16);
    void datSetTimeSlot(u8);
    void datSetPendingDateIndex(s16);
    void datSetPendingTimeSlot(u8);
    void datSetPendingFlag(u32);
    void func_00106480(void);
    void datPersonaClearRosterMode(void);
    void func_001065c0(void);
    void func_00106d40(s16, s16, s16);
    void cmmCommunityClearTable(void);
    s32 datPersonaPlaceRosterMember(s32, u16);
    void datPersonaResetRosterMode(s16);
    void func_0010d490(u8 *, u8 *);
    void func_0010f390(void);
    void func_0010f4c0(void);
    void func_0010fc80(void);
    void func_00155250(void);
    void func_0015a630(void);
    void func_00162120(void);
    extern u16 D_005E4630[];
    extern s16 D_005E4650[];

    calSetStateImagePending(0);
    datSetPendingFlag(0);
    func_0010d490(iGpffff9bb8, iGpffff9bc0);
    datSetMoney(0);
    func_0010fc80();

    i = 1;
    goto loop_1_check;
loop_1:
    datCalcInitUnitById((s16)i);
    if (i == 1) {
        func_00105690((s16)i, 1);
        datSetHeroExp((s16)i, 0);
    }
    func_001056e0((s16)i, 1);
    func_00105730((s16)i, 1);
    j = 0;
    goto loop_2_check;
loop_2:
    datSetCategoryValueById((s16)i, (s16)j, 0);
    j++;
loop_2_check:
    if (j < 5) {
        goto loop_2;
    }
    func_00105c90((s16)i, 0);
    datCalcSetBadStatusById((s16)i, 0);
    func_00105dc0((s16)i, 0, -1);
    func_00105dc0((s16)i, 1, -1);
    func_00105dc0((s16)i, 2, -1);
    datPersonaResetRosterMode((s16)i);
    q = (u8 *)D_005E4630 + i * 2;
    datPersonaPlaceRosterMember(i & 0xFFFF, *(u16 *)(q - 2));
    func_001056e0((s16)i, (s16)datCalcMaxHpById((s16)i));
    func_00105730((s16)i, (s16)datCalcMaxSpById((s16)i));
    i++;
loop_1_check:
    if (i < 11) {
        goto loop_1;
    }

    func_00106480();
    func_001065c0();
    datPersonaClearRosterMode();
    datSetTimeSlot(5);
    datSetDateIndex(9);
    datSetPendingTimeSlot(5);
    datSetPendingDateIndex(9);
    i = 0;
    goto loop_3_check;
loop_3:
    func_00106620((s16)i, 0);
    i++;
loop_3_check:
    if (i < 1536) {
        goto loop_3;
    }

    i = 1;
    goto loop_4_check;
loop_4:
    p = (u8 *)D_005E4650 + i * 6;
    func_00106d40((s16)i, 0, *(s16 *)(p - 6));
    func_00106d40((s16)i, 1, *(s16 *)(p - 4));
    func_00106d40((s16)i, 2, *(s16 *)(p - 2));
    i++;
loop_4_check:
    if (i < 11) {
        goto loop_4;
    }

    datSetPartyId(0, 0);
    datSetPartyId(1, 0);
    datSetPartyId(2, 0);
    datSetPartyId(3, 0);
    func_00155250();
    func_00162120();
    func_0015a630();
    func_0010f390();
    func_0010f4c0();
    cmmCommunityClearTable();

    i = 0;
    goto loop_5_check;
loop_5:
    datSetStateTableEntry(i, 0);
    i++;
loop_5_check:
    if (i < 1536) {
        goto loop_5;
    }
    iGpffffb1f0 = 0;
    iGpffffb19c = 0;
    func_00106390(0x39, 1);
    func_00106390(0x3A, 1);
    func_00106390(0x3B, 0);
    func_00106390(0x3C, 1);
    func_00106390(0x3D, 1);
    func_00106390(0x3E, 0);
}
// Intent: Carry persistent state across a reset: save the flags, category values and money, reset to the defaults, then restore them with the new end date [inferred]
// FUN_00111BC0
#pragma opt_propagation off
void datCarryOverPersistentState(void)
{
    s32 saved;
    s32 value;
    s32 end_date;
    s32 result;
    s32 count;
    s8 flag;
    s32 i;
    s32 buf[344];
    s32 func_001064f0(s32);
    void func_00106550(s32, u32);
    s32 func_00106600(s16);
    s32 datGetFlag(s32);
    void func_00106390(s32, s32);
    s16 datGetCategoryValueById(s16, s16);
    u32 datGetMoney(void);
    void datSetMoney(u32);
    void datSetCategoryValueById(s16, s16, s16);
    u32 datGetClearedWord(void);
    void func_00110470(u32);
    void fclCombineSaveSnapshot(void);
    void fclCombineRestoreSnapshot(void);
    extern float D_005E4700[4];
    typedef struct { float a; float b; float c; float d; } Vec4;
    saved = iGpffffb19c;
    count = 0;
    flag = 0;
    *(Vec4 *)buf = *(Vec4 *)D_005E4700;
    value = func_001064f0(0x7C);
    end_date = (s32)datGetClearedWord() + 1;
    if ((func_00106600(0x4A0) & 0xFF) > 0) {
        buf[4] = 0x4A0;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A1) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A1;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A2) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A2;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A3) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A3;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A4) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A4;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A5) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A5;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A6) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A6;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A7) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A7;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A8) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A8;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4A9) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A9;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AA) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AA;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AB) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AB;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AC) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AC;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AD) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AD;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AE) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AE;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4AF) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AF;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B0) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B0;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B1) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B1;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B2) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B2;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x4B3) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B3;
        count = (count + 1) & 0xFF;
    }
    if ((func_00106600(0x418) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x418;
        count = (count + 1) & 0xFF;
    }
    if (datGetFlag(0x2F) != 0) {
        flag = 1;
    }
    if (datGetFlag(0x1DD) != 0) {
        flag = 1;
    }
    i = 0;
    goto loop1_check;
loop1:
    buf[332 + i] = datGetFlag(i + 0x39);
    i++;
loop1_check:
    if (i < 7) {
        goto loop1;
    }
    result = 0;
    goto loop2_check;
loop2:
    {
        s32 *p = &buf[result];
        s32 v = *p;
        if (v == 0) {
            goto loop2_done;
        }
        buf[132 + result] = datGetFlag(v);
        result++;
    }
loop2_check:
    if (result < 200) {
        goto loop2;
    }
loop2_done:
    fclCombineSaveSnapshot();
    i = 0;
    goto loop3_check;
loop3:
    ((s16 *)buf)[680 + i] = datGetCategoryValueById(1, (s16)i);
    i++;
loop3_check:
    if (i < 5) {
        goto loop3;
    }
    result = (s32)datGetMoney();
    datInitDefaultGameState();
    i = 0;
    goto loop4_check;
loop4:
    func_00106390(i + 0x39, buf[332 + i]);
    i++;
loop4_check:
    if (i < 7) {
        goto loop4;
    }
    i = 0;
    goto loop5_check;
loop5:
    {
        s32 *p = &buf[i];
        s32 v = *p;
        if (v == 0) {
            goto loop5_done;
        }
        func_00106390(v, buf[132 + i]);
        i++;
    }
loop5_check:
    if (i < 200) {
        goto loop5;
    }
loop5_done:
    i = 0;
    count &= 0xFF;
    goto loop6_check;
loop6:
    func_00106620(((s16 *)buf)[8 + i * 2], 1);
    i++;
loop6_check:
    if (i < count) {
        goto loop6;
    }
    if (flag == 1) {
        func_00106390(0x1DD, 1);
    }
    fclCombineRestoreSnapshot();
    func_00106390(0x1210, 1);
    func_00106550(0x7C, (u32)value);
    func_00110470((u32)end_date);
    i = 0;
    goto loop7_check;
loop7:
    datSetCategoryValueById(1, (s16)i, ((s16 *)buf)[680 + i]);
    i++;
loop7_check:
    if (i < 5) {
        goto loop7;
    }
    datSetMoney((u32)result);
    func_00106390(0x800, 1);
    iGpffffb19c = saved;
}
#pragma opt_propagation on
// Intent: Draw one entry row: the name text, the stat value, the count, and the badges, at the entry's position and depth [inferred]
// FUN_00112300
void datEntryDrawRow(Vec2f arg0, f32 inputDepth, u8 arg1, u8 *inputEntry)
{
    f32 fparg0;
    u8 *arg2;
    u8 buf[256];
    s32 temp16;
    s32 temp19;
    union {
        s64 whole;
        f32 values[2];
        Vec2f position;
    } xy;
    f32 temp_1;
    s32 temp_2;
    
    s32 func_00106a90(s16);
    void sprintf(void *, void *, s32);
    s32 resourceFindByName(void *);
    void kAssertFail(void *, s32);
    void datEntryDrawBadges(Vec2f, f32, u8, u8 *, s32, s32);
    void datEntryDrawStatValue(Vec2f, f32, u8, u8 *, s32);
    void datEntryDrawCount(Vec2f, f32, u8, u8 *, s32);
    extern f32 D_005E4790[];
    extern f32 D_005E4794[];
    extern f32 D_005E479C[];
    extern u8 D_005E5830[];
    extern u8 D_005E5850[];
    extern u8 iGpffff9be0;
    extern u8 iGpffff9bd8;
    extern u8 iGpffff9be8;

    fparg0 = inputDepth;
    arg2 = inputEntry;
    temp16 = resourceFindByName(D_005E5830);
    temp19 = resourceFindByName(D_005E5850);
    if (temp16 == 0) {
        kAssertFail(&iGpffff9be0, 0x93);
    }
    if (temp19 == 0) {
        kAssertFail(&iGpffff9be0, 0x94);
    }
    if (*(u16 *)(arg2 + 0x14) != 0) {
        datEntryDrawBadges(arg0, fparg0, arg1, arg2, temp16, temp19);
        arg0.x = arg0.x + 45.0f;
    }
    if (*(s32 *)(arg2 + 0xC) != 0) {
        temp19 = arg1 & 0xFF;
        temp_2 = (s32)datGetItemNameId(*(s16 *)arg2);
        frFontExDrawTextWithCharWidth(
            arg0.x,
            arg0.y,
            fparg0,
            temp19 | ~0xFF,
            *(s8 *)(&iGpffff9bd8 + *(s16 *)(arg2 + 0x16)),
            1,
            (const char *)temp_2,
            0,
            -1);
    }
    if (*(s32 *)(arg2 + 0x10) != 0) {
        xy.values[0] = arg0.x +
                       D_005E4790[*(s16 *)(arg2 + 0x18) * 4];
        temp_1 = 9.0f;
        temp_1 += arg0.y;
        xy.values[1] = temp_1;
        datEntryDrawStatValue(xy.position, fparg0, arg1, arg2, temp16);
    }
    if (*(s16 *)(arg2 + 2) != -1) {
        xy.position.x = arg0.x +
                        D_005E4794[*(s16 *)(arg2 + 0x18) * 4];
        temp_1 = 12.0f;
        temp_1 += arg0.y;
        xy.position.y = temp_1;
        datEntryDrawCount(xy.position, fparg0, arg1, arg2, temp16);
    }
    if (*(s32 *)(arg2 + 8) != -1) {
        xy.values[0] = arg0.x +
                       D_005E479C[*(s16 *)(arg2 + 0x18) * 4];
        xy.values[1] = arg0.y;
        temp16 = ((arg1 & 0xFF) * 0xFF) / 255U;
        sprintf(buf, &iGpffff9be8,
                      func_00106a90(*(s16 *)arg2));
        frFontExDrawText(
            (f32)(s32)xy.values[0],
            (f32)(s32)xy.values[1],
            fparg0,
            temp16 | ~0xFF,
            *(s8 *)(&iGpffff9bd8 + *(s16 *)(arg2 + 0x16)),
            0,
            (void *)buf,
            0,
            0);
    }
}
#pragma opt_propagation on
// Intent: Reset the entry's fields to their defaults: sentinel -1 for the indices and 3 for the state [inferred]
// FUN_001125D0
void datEntryReset(u8 *arg0) {
    s32 temp_1;
    s32 temp_m1;

    temp_1 = 1;
    *(s16 *)(arg0 + 0) = temp_1;
    temp_m1 = -1;
    *(s16 *)(arg0 + 2) = temp_m1;
    *(s16 *)(arg0 + 6) = temp_m1;
    *(s32 *)(arg0 + 8) = temp_m1;
    *(s32 *)(arg0 + 0xC) = temp_1;
    *(s32 *)(arg0 + 0x10) = 0;
    temp_m1 = 3;
    *(s16 *)(arg0 + 0x14) = temp_m1;
    *(s16 *)(arg0 + 0x18) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
}
// Intent: Draw the entry's icons when the flag bits in the state word at 0x14 are set, using the colours from the two colour tables [inferred]
// FUN_00112610
void datEntryDrawBadges(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3, s32 arg4)
{
    typedef struct {
        u8 b[4];
    } Color4;
    extern u8 D_005E4710[];
    extern u8 D_005E4730[];
    void datEntryDrawFlagIcon(s64, f32, Color4, s16, s32, s32);
    Color4 color_a;
    Color4 color_b;
    Vec2f pos;
    s32 flags;
    s32 mode;
    s32 selected;
    u8 *table;
    s32 alpha;

    flags = datEntryGetFlags(*(s16 *)(arg2 + 0));
    if (*(u16 *)(arg2 + 0x14) & 2) {
        table = &D_005E4710[(*(s16 *)(arg2 + 0x16)) * 4];
        color_a = *(Color4 *)table;
        mode = -1;
        if (flags & 0x3FFF) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0xC000) {
            mode = 3;
            selected = arg3;
        } else if (flags & 0x10000) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0x20000) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0x40000) {
            mode = 2;
            selected = arg3;
        }
        if (mode != -1) {
            alpha = 255;
            alpha -= arg1 & 0xFF;
            sdkSpriteDrawOnceTinted(0, selected, mode, arg0.x, arg0.y,
                          alpha & 0xFF,
                          color_a.b[0], color_a.b[1], color_a.b[2],
                          fparg0, 0);
        }
    }
    if (*(u16 *)(arg2 + 0x14) & 1) {
        table = &D_005E4730[(*(s16 *)(arg2 + 0x16)) * 4];
        color_b = *(Color4 *)table;
        color_b.b[3] = arg1;
        pos.x = arg0.x + 3.0f;
        pos.y = arg0.y + 2.0f;
        datEntryDrawFlagIcon(*(s64 *)&pos, fparg0, color_b,
                      *(s16 *)(arg2 + 0), arg3, arg4);
    }
}

typedef struct {
    u8 b[4];
} StatColor;

static inline void func_00112830_number(Vec2f pos, f32 depth, u16 value,
                                        StatColor color, s32 tex)
{
    f32 x;

    if (value / 100 != 0) {
        x = 30.0f + pos.x;
    } else {
        x = 22.0f + pos.x;
    }
    do {
        sdkSpriteDrawOnceTinted(0, tex, value % 10 + 0x1E, x, pos.y, 0xFF - color.b[3],
                      color.b[0], color.b[1], color.b[2], depth, 0);
        x -= 15.0f;
        value /= 10;
    } while (value > 0);
}

static inline void func_00112830_arrow(Vec2f pos, f32 depth, StatColor color,
                                       u16 value, u16 prev, s32 tex)
{
    s32 glyph;

    if (value != prev) {
        if (value < prev) {
            glyph = 40;
        } else if (prev < value) {
            glyph = 41;
        }
        sdkSpriteDrawOnceTinted(0, tex, glyph, pos.x, pos.y - 1.0f, 0xFF - color.b[3],
                      color.b[0], color.b[1], color.b[2], depth, 0);
    }
}

/* measured: loop invariants hoist the green/blue/alpha channels and the
   row y out of the digit loops, as retail does (without it: 2088 B). */
#pragma push
#pragma opt_loop_invariants on
// Intent: Draw a stat value and, when it differs from the previous value, its up or down arrow glyph, then its digits [inferred]
// FUN_00112830
void datEntryDrawStatValue(Vec2f pos, f32 depth, u8 alpha, u8 *arg2, s32 tex)
{
    extern StatColor D_005E4750[];
    StatColor color;
    u16 value;
    s32 i;

    color = D_005E4750[*(s16 *)(arg2 + 0x16)];
    color.b[3] = alpha;
    switch (datIdBand(*(s16 *)arg2)) {
    case 0:
        value = func_001068b0(*(s16 *)arg2);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            func_00112830_arrow(pos, depth, color,
                                func_001068b0(*(s16 *)(arg2 + 6)), value, tex);
        }
        pos.x += 42.0f;
        value = func_001068e0(*(s16 *)arg2);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            func_00112830_arrow(pos, depth, color,
                                func_001068e0(*(s16 *)(arg2 + 6)), value, tex);
        }
        break;
    case 1:
        value = func_00106940(*(s16 *)arg2);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            func_00112830_arrow(pos, depth, color,
                                func_00106940(*(s16 *)(arg2 + 6)), value, tex);
        }
        pos.x += 42.0f;
        value = func_00106970(*(s16 *)arg2);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            func_00112830_arrow(pos, depth, color,
                                func_00106970(*(s16 *)(arg2 + 6)), value, tex);
        }
        break;
    case 2:
        pos.x += 35.0f;
        pos.y += 4.0f;
        for (i = 0; i < 4; i++) {
            sdkSpriteDrawOnceTinted(0, tex, 60, pos.x, pos.y, 0xFF - alpha,
                          color.b[0], color.b[1], color.b[2], depth, 0);
            pos.x += 34.0f;
        }
        break;
    }
}
#pragma pop
typedef struct { u8 r, g, b, a; } FontGlyphColor;
static inline s32 fontDrawLeadingGlyph(const Vec2f *position, f32 depth, u8 opacity, s32 texture,
    const FontGlyphColor *color, u32 *blue, u32 *green)
{
    s32 alpha;

    *blue = color->b;
    *green = color->g;
    alpha = 255 - (opacity & 0xFF);
    sdkSpriteDrawOnceTinted(0, texture, 0x47, position->x, 2.0f + position->y,
                  alpha, color->r, *green, *blue, depth, 0);
    return alpha;
}

/* Native b210 -O2: 440 executable bytes, nine resolved relocations,
 * and eight retail alignment zeros. The leading draw keeps inverse
 * opacity live while the loop retains its blue and green snapshots. */
// Intent: Draw the entry's count as text glyphs, right to left, after the leading glyph [inferred]
// FUN_001130C0
void datEntryDrawCount(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3)
{
    struct {
        s8 text[0x4C];
        FontGlyphColor color;
    } stack;
    s16 temp_21;
    u32 color2;
    u32 color1;
    s32 alpha_byte;
    s32 var_20;
    u8 loop_color2;
    u8 loop_color1;
    u8 *temp_2;
    extern u8 D_005E4770[];
    extern u8 D_005E4798[];
    extern s32 iGpffff9bec;
    extern s32 sprintf(void *, const void *, ...);
    extern s32 strlen(const void *);

    temp_21 = *(s16 *)(arg2 + 2);
    temp_2 = D_005E4770 + (*(s16 *)(arg2 + 0x16) * 4);
    stack.color = *(FontGlyphColor *)temp_2;
    alpha_byte = fontDrawLeadingGlyph(&arg0, fparg0, arg1, arg3,
        &stack.color, &color2, &color1);
    sprintf(stack.text, &iGpffff9bec, (s16)temp_21);
    arg0.x = arg0.x + (14.0f +
        *(f32 *)(D_005E4798 + (*(s16 *)(arg2 + 0x18) * 0x10)));
    var_20 = strlen(stack.text) - 1;
    loop_color2 = color2;
    loop_color1 = color1;
    while (var_20 >= 0) {
        sdkSpriteDrawOnceTinted(0, arg3, stack.text[var_20] - 0x27,
                      arg0.x, arg0.y, alpha_byte,
                      stack.color.r, loop_color1, loop_color2, fparg0, 0);
        arg0.x -= 14.0f;
        var_20--;
    }
}

// Intent: Draw the icon for the first set flag bit, with its sprite mode and id, at the given position [inferred]
// FUN_00113280
void datEntryDrawFlagIcon(Vec2f arg0, f32 fparg0, s32 arg1, s16 arg2, s32 arg3,
                   s32 arg4)
{
    f32 scale;
    s32 flags;
    s32 mode;
    s32 id;
    s32 alpha;

    scale = fparg0;
    flags = datEntryGetFlags(arg2);
    mode = -1;
    if (flags & 0x81) {
        mode = 0x14;
        id = arg3;
    } else if (flags & 0x102) {
        mode = 0x15;
        id = arg3;
    } else if (flags & 0x204) {
        mode = 0x16;
        id = arg3;
    } else if (flags & 0x408) {
        mode = 0x17;
        id = arg3;
    } else if (flags & 0x810) {
        mode = 0x18;
        id = arg3;
    } else if (flags & 0x1020) {
        mode = 0x19;
        id = arg3;
    } else if (flags & 0x2040) {
        mode = 0x1A;
        id = arg3;
    } else if (flags & 0x4000) {
        mode = 0x1B;
        id = arg3;
    } else if (flags & 0x8000) {
        mode = 0x1C;
        id = arg3;
    } else if (flags & 0x10000) {
        mode = 0x1B;
        id = arg4;
    } else if (flags & 0x20000) {
        mode = 0x1C;
        id = arg4;
    } else if (flags & 0x40000) {
        mode = 0x1A;
        id = arg4;
    }
    if (mode != -1) {
        alpha = 0xFF;
        alpha -= ((u8 *)&arg1)[3];
        sdkSpriteDrawOnceTinted(0, id, mode, arg0.x, arg0.y,
                      alpha & 0xFF,
                      ((u8 *)&arg1)[0], ((u8 *)&arg1)[1],
                      ((u8 *)&arg1)[2], scale, 0);
    }
}
// Intent: Forward a draw to the subsystem routine only while flag 0x39 is set [inferred]
// FUN_00113480
void datEntryDrawGatedByFlag39(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (datGetFlag(0x39) != 0) {
        func_004534f0(arg0, arg1, arg2, arg3);
    }
}
// Intent: Stop controller rumble [inferred]
// FUN_00113500
void datStopPadRumble(void) {
    H_Pad_StopRumble();
}
// Intent: Fill a skill cost row from the table entry at the index: the skill id at +2, and the cost at +4 or +8 by the threshold kind; return 1 when the entry is present [inferred]
// FUN_00113520
s32 datPersonaFillSkillCostRow(s32 arg0, s32 arg1, s32 arg2, u8 *arg3)
{
    s32 temp_3;
    u16 temp_2;
    u16 temp_5;

    *(u16 *)(arg3 + 2) = 0;
    *(s32 *)(arg3 + 4) = 0;
    *(s32 *)(arg3 + 8) = 0;
    temp_2 = *(u16 *)(p4_00113520_add(arg2 * 2, arg1) + 0xC);
    if (temp_2 != 0) {
        *(u16 *)(arg3 + 2) = temp_2;
        if (arg0 != 0) {
            temp_5 = *(u16 *)(arg3 + 2);
            if ((s32)temp_5 < 0x1B8) {
                temp_3 = datCalcThresholdKindById((s16)arg0, temp_5) & 0xFFFF;
                switch (temp_3) {
                case 1:
                    *(s32 *)(arg3 + 4) = datCalcSkillCostById((s16)arg0, *(u16 *)(arg3 + 2));
                    break;
                case 2:
                    *(s32 *)(arg3 + 8) = datCalcSkillCostById((s16)arg0, *(u16 *)(arg3 + 2));
                    break;
                }
            }
        }
        return 1;
    }
    return 0;
}
// Intent: Fill the persona's skill rows: up to eight learned skills first, then the learnable skills, with the counts at 0x60 and 0x224 [inferred]
// FUN_00113610
void datPersonaFillSkillRows(s32 arg0, u8 *arg1)
{
    u16 sp70[32];
    u16 sp30[32];
    u8 *table;
    u8 *entry;
    s16 i;
    s16 j;
    s32 count;
    s32 index;
    u16 value;

    table = datPersonaGetSkills();
    i = 0;
    while (i < 8) {
        index = (s32)i * 0xC;
        entry = arg1 + index;
        *(s32 *)(entry + 4) = 0;
        *(s32 *)(entry + 8) = 0;
        value = *(u16 *)(table + ((s32)i * 2));
        if (value == 0) {
            break;
        }
        *(u16 *)(entry + 2) = value;
        i++;
    }
    *(s16 *)(arg1 + 0x60) = i;
    count = (s16)datPersonaCollectLearnableSkills((u8 *)(u32)arg0, sp70, sp30);
    j = 0;
    while (j < count) {
        index = (s32)j * 0xC;
        entry = arg1 + index;
        *(s32 *)(entry + 0x68) = 0;
        *(s32 *)(entry + 0x6C) = 0;
        *(u16 *)(entry + 0x66) = sp70[(s32)j];
        *(u16 *)(arg1 + ((s32)j * 2) + 0x1E4) = sp30[(s32)j];
        j++;
    }
    *(s16 *)(arg1 + 0x224) = count;
}
// Intent: Clear the first three halfwords of a record [inferred]
// FUN_00113730
void datRecordClearHeader(s16 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
}
// Intent: Reset a record: zero the two halfword counters, set the two indices at +4 and +5 to -1, and clear the 0x22C bytes from +8 [inferred]
// FUN_00113750
void datRecordResetAll(u8 *arg0) {
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 2) = 0;
    *(s8 *)(arg0 + 4) = -1;
    *(s8 *)(arg0 + 5) = -1;
    memset(arg0 + 8, 0, 0x22C);
}
// Intent: Draw an entry by its kind: kind 0 draws the id name, kind 1 the skill descriptor, kind 2 the skill entry name [inferred]
// FUN_00113790
void datEntryDrawByKind(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4)
{
    s16 temp_8;

    temp_8 = *(s16 *)arg2;
    switch (temp_8) {
    case 0:
        datEntryDrawIdName(arg0, arg4, arg1, arg2, arg3);
        return;
    case 1:
        ShdSkill_DrawDescriptor(arg0, arg4, arg1, arg2, arg3);
        return;
    case 2:
        ShdSkill_DrawEntryName(arg0, arg4, arg1, arg2, arg3);
        return;
    }
}
/* measured: declaring the f32 parameter immediately after the Vec2f aggregate
   reproduces retail's FP-first prologue save order. Probe object 184B/window
   192B; the only two fndiff residual words are zero-padding tail bytes.
   The plain-char table read preserves lb before the final f14 move with
   the shared signed-byte font API; an s8 read swaps those two words. */
// Intent: Draw the record's id name at a position with the given alpha and the font index from the table [inferred]
// FUN_00113800
void datEntryDrawIdName(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3)
{
    f32 scale;
    s32 color;
    char index;
    void *temp;

    scale = arg4;

    temp = datCalcGetIdRecord(*(u16 *)((u8 *)arg2 + 0xA));
    color = -0x100 | (((arg1 & 0xFF) * 0xFF) / 255U);
    index = *(char *)((s32)D_005E47F0 + (*(s16 *)((u8 *)arg2 + 2) * 2));
    frFontExDrawText((f32)(s32)arg0.x, (f32)(s32)arg0.y, scale, color, index, 1, temp, 0, 0);
}
// Intent: Reset a panel: zero two 0x3C-byte sub-blocks and set the header to 1, 0, 0 [inferred]
// FUN_00115830
void datPanelReset(u8 *arg0) {
    memset(arg0 + 8, 0, 0x3C);
    memset(arg0 + 0x44, 0, 0x3C);
    *(s16 *)(arg0 + 0) = 1;
    *(s16 *)(arg0 + 2) = 0;
    *(s32 *)(arg0 + 4) = 0;
}
// Intent: Return whether the stage field at +8 of the work block is 8; the meaning of stage 8 is not established [inferred]
// FUN_0011FCF0
s32 datBlockStageIsEight(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 8) == 8;
}
// Intent: Destroy a task and its hierarchy through the kwln task destroy call; same body as shdPersonaDestroyTask [inferred]
// FUN_0011FD10
void kwlnTaskDestroyHierarchyAlt(s32 task) {
    kwlnTaskDestroyWithHierarchy((KwlnTask *)task);
}
// Intent: Reset a panel's cursor: index at +4 to -1 and the count at +6 to 0 [inferred]
// FUN_0011FD30
void datPanelResetCursor(u8 *arg0) {
    *(s16 *)(arg0 + 4) = -1;
    *(s16 *)(arg0 + 6) = 0;
}
// Intent: Draw a panel row by its kind: kind 0 draws the comparison icon, kinds 1 and 2 the status panel, kind 3 the status panel in variant 1 [inferred]
// FUN_0011FD50
void datPanelDrawByKind(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3)
{
    s32 temp_7;

    temp_7 = *(s32 *)(arg2 + 8);
    switch (temp_7) {
    case 0:
        datPanelDrawCompareIcon(arg0, arg4, arg1, arg2, temp_7);
        return;
    case 1:
        drawUnitStatusPanel(arg0, arg4, arg1, arg2, 0, arg3);
        return;
    case 2:
        drawUnitStatusPanel(arg0, arg4, arg1, arg2, 0, arg3);
        return;
    case 3:
        drawUnitStatusPanel(arg0, arg4, arg1, arg2, 1, arg3);
        return;
    }
}
// Intent: Draw a comparison icon for an entry: sprite 4 when equal to the reference value of its band (always for band 3), 1 when higher, 2 when lower, 3 when no reference applies [inferred]
// FUN_0011FDF0
void datPanelDrawCompareIcon(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3)
{
    s16 temp_17;
    s32 temp_2;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_20_3;
    s32 alpha;
    s32 mode;

    temp_2 = resourceFindByName(D_005E4F70);
    temp_17 = *(s16 *)(arg2 + 4);
    if (temp_2 == 0) {
        temp_2 = arg1 & 0xFF;
        frFontExDrawText((f32)(s32)arg0.x, (f32)(s32)arg0.y, arg4,
                      temp_2 | -0x100, 0, 4,
                      (const char *)datPersonaDisplayName(*(s16 *)arg2), 0, 0);
        return;
    }
    if (p4_0011_signext16(temp_17) == -1) {
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 3, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
    if (func_00106c30(temp_17, *(s16 *)arg2) == 0) {
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 3, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
    mode = datIdBand(temp_17);
    switch (mode) {
    case 0:
        temp_20 = func_001068b0(temp_17) & 0xFFFF;
        if (temp_20 == (func_001068b0(func_00106cd0(*(s16 *)arg2, 0)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_2 = func_001068b0(temp_17) & 0xFFFF;
        if (temp_17_2 >= (func_001068b0(func_00106cd0(*(s16 *)arg2, 0)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 1:
        temp_20_2 = func_00106940(temp_17) & 0xFFFF;
        if (temp_20_2 >= (func_00106940(func_00106cd0(*(s16 *)arg2, 1)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_3 = func_00106940(temp_17) & 0xFFFF;
        if (temp_17_3 >= (func_00106940(func_00106cd0(*(s16 *)arg2, 1)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 2:
        temp_20_3 = func_00106970(temp_17) & 0xFFFF;
        if (temp_20_3 >= (func_00106970(func_00106cd0(*(s16 *)arg2, 2)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_4 = func_00106970(temp_17) & 0xFFFF;
        if (temp_17_4 >= (func_00106970(func_00106cd0(*(s16 *)arg2, 2)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 3:
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
}
