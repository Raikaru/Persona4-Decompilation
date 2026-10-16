/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00110850-001113b0 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
extern void func_0010e710(s32, u8 *, s32);
extern s32 iGpffffb1b4;
extern u8 iGpffff9bb8[8]; /* Default surname at gp - 0x6448. */
extern u8 iGpffff9bc0[8]; /* Default given name at gp - 0x6440. */
extern s32 D_005E45E0[];
extern s8 D_005E3A02[];
extern s8 D_005E3A04[];
extern u8 D_00797B7C[];
extern s32 D_0079B40C[];
extern s8 D_005E3A00[];
s32 func_0029e970(void);
void func_0029e980(s32);
void datSetFlag(s32, s32);
s32 calReadDayFlagMask(void);
void calWriteDayFlagMask(s32);
void datInitDefaultGameState(void);
extern s32 iGpffffb1bc;
extern s32 iGpffffb19c;
extern s32 iGpffffb1b8;
extern s32 iGpffffb1f0;
extern void (*jtbl_008873EC[])(void *);
extern u8 *datSaveBuildImage(s32 a, s32 *b, s32 c);
extern u8 D_007BBF00[];
extern void memcpy(void *dst, void *src, s32 n);
extern s16 D_00797B7A[];
extern s32 D_005E4610[];
extern s32 datGetFlag(s32 arg0);
extern s8 calendarGetValueLowByte(void);
extern s16 calendarStateDaysSinceApr5(void);
extern s16 calendarStatePeriod(void);
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

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
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
#pragma pop

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

s32 calDayOfYearFromMonthDay(s32 arg0, s32 arg1);

#pragma push
#pragma opt_loop_invariants off
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
// Intent: Return whether the day table has an entry for day arg0 [inferred]
// FUN_00110D30
s32 calHasDayEntry(s32 arg0)
{
    return D_005E3A00[arg0 * 6] != 0;
}
#pragma pop

s32 calDayOfYearFromMonthDay(s32 arg0, s32 arg1);

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Set the state-image pending flag that calRestoreStateImage reads [inferred]
// FUN_00110E70
void calSetStateImagePending(s32 arg0)
{
    iGpffffb1b4 = arg0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Destroy the scheduler, then run the two cleanup calls with arguments (1, 1) and (0x1B, 0, 0, 8) [inferred]
// FUN_00110FC0
void sdlSchedulerTeardown(void) {
    sdlSchedulerDestroy();
    func_00122520(1, 1);
    func_001029a0(0x1B, 0, 0, 8);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Release the active script-process handle if one exists; kwln registers it as a callback [inferred]
// FUN_00111010
void scrReleaseActiveHandle(void)
{
    s32 temp_2;

    if ((temp_2 = func_0029e970()) != 0) {
        func_0029e980(temp_2);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Set the six default day flags (0x39 to 0x3E) and clear the saved mask when arg0 is nonzero [inferred]
// FUN_00111050
void calSetDefaultDayFlags(s32 arg0)
{
    datSetFlag(0x39, 1);
    datSetFlag(0x3A, 1);
    datSetFlag(0x3B, 0);
    datSetFlag(0x3C, 1);
    datSetFlag(0x3D, 1);
    datSetFlag(0x3E, 0);
    if (arg0 != 0) {
        iGpffffb1bc = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Write each of the six day flags from the matching bit of a six-bit mask [inferred]
// FUN_00111160
void calWriteDayFlagMask(s32 arg0)
{
    u32 var_16;
    var_16 = 0;
    for (var_16 = 0; var_16 < 6U; var_16++) {
        if (arg0 & (1 << var_16)) {
            datSetFlag(D_005E4610[var_16], 1);
        } else {
            datSetFlag(D_005E4610[var_16], 0);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
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
                datSetFlag(D_005E4610[var_17], 1);
            } else {
                datSetFlag(D_005E4610[var_17], 0);
            }
        }
    } else {
        datSetFlag(0x39, 1);
        datSetFlag(0x3A, 1);
        datSetFlag(0x3B, 0);
        datSetFlag(0x3C, 1);
        datSetFlag(0x3D, 1);
        datSetFlag(0x3E, 0);
    }
    iGpffffb1bc = 0;
}
#pragma pop

void datSetStateTableEntry(s32 arg0, u8 arg1);

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
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
    void datSetUnitHp(s16, s16);
    void datSetUnitSp(s16, s16);
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
    void MT_Scene_ResetFrameState(void);
    void FldStepResetTables(void);
    void FldStateTablesClear(void);
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
    datSetUnitHp((s16)i, 1);
    datSetUnitSp((s16)i, 1);
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
    datSetUnitHp((s16)i, (s16)datCalcMaxHpById((s16)i));
    datSetUnitSp((s16)i, (s16)datCalcMaxSpById((s16)i));
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
    datItemSetCount((s16)i, 0);
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
    MT_Scene_ResetFrameState();
    FldStateTablesClear();
    FldStepResetTables();
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
    datSetFlag(0x39, 1);
    datSetFlag(0x3A, 1);
    datSetFlag(0x3B, 0);
    datSetFlag(0x3C, 1);
    datSetFlag(0x3D, 1);
    datSetFlag(0x3E, 0);
}
#pragma pop
