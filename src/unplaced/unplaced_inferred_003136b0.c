/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 003136b0-003142f0 */

#include "include_asm.h"
#include "type.h"
#include "shdPersona_internal.h"
#include "datPersona_internal.h"
extern void (*jtbl_008873EC[])(void *);
extern u32 D_00642EF0[];
extern u32 D_00642F00[];
extern u8 *yListSlotWork(s8 arg0);
extern void yListSlotAppend(s8 arg0, s32 arg1, s8 arg2);
extern u8 *yListSlotEntry();
static inline s32 func_0031_ne(s32 value, s32 target)
{
    return value != target;
}

extern s32 datGetFlag(s32 arg0);
extern s32 datItemCount(s16 id);
extern u16 cmmCommunityRecordValue(u16 arg0);
extern u8 D_006432B0[];
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern void fclCalGetNextDate(s32 *month, s32 *day);
extern void cmmDateSelectionSelect(u8 *arg0, u8 month, s32 day, s8 mode);
static inline s8 findDateEntry(u8 month, u8 day)
{
    s8 index = 0;
    u8 *entry;

    for (;;) {
        index++;
        entry = D_006432B0 + index * 0x1C;
        if (*(s8 *)entry == -1 && *(s8 *)(entry + 1) == -1) return -1;
        if (*(s8 *)entry == month && *(s8 *)(entry + 1) == day) return index;
    }
}

#pragma push
#pragma opt_loop_invariants off
// FUN_003136B0
s32 fclCombineMaterialAvailable(u16 arg0)
{
    s32 value;
    s32 result;

    value = arg0 & 0xFFFF;
    if (value == 0x93) {
        result = (datItemCount(0x4A8) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0xB9) {
        result = (datItemCount(0x4A4) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x26) {
        result = (datItemCount(0x4A6) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x53) {
        result = (datItemCount(0x4AD) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0x68) {
        result = (datItemCount(0x4AF) & 0xFF) >= 1;
        goto done;
    }
    if (value == 0xA6) {
        if ((cmmCommunityRecordValue(0x1E) & 0xFFFF) == 0xA) {
            result = 1;
        } else {
            result = datGetFlag(0x1DD) != 0;
        }
        goto done;
    }
    result = 1;
done:
    return result;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// FUN_00313800
void fclCombineMaterialListBuild(s8 arg0)
{
    u8 *items;
    s16 row;
    s16 item;
    s16 selected;
    s32 column;
    u8 *entry;
    u8 *table;
    s16 *value;

    selected = 0;
    row = 0;
    table = (u8 *)D_00642F00 + arg0 * 8;
    for (; row < 6; row++) {
        entry = *(u8 **)(table - 0x10) + row * 0x20;
        if (*(u16 *)entry != 0 && fclCombineMaterialAvailable(*(u16 *)entry) == 1) {
            yListSlotAppend(0, *(s16 *)entry, 0);
            items = entry + 4;
            yListSlotWork(0)[0x14 + selected] = 1;
            item = 0;
            column = selected + 1;
            for (; item < arg0; item++) {
                value = (s16 *)(items + item * 2 + 4);
                yListSlotAppend((s8)column, *value, 1);
                yListSlotWork((s8)column)[0x14 + item] = 0;
                if (datPersonaFindRosterRecordById(*(u16 *)value) != NULL) {
                    yListSlotWork((s8)column)[0x14 + item] = 1;
                }
            }
            selected++;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_003139D0
s32 fclCombineMaterialsHeld(s8 arg0, s8 arg1)
{
    s32 i;
    s32 start;
    s64 limit;
    s32 result;

    i = 0;
    start = arg1 + 1;
    limit = arg0;
    goto loop_test;
loop_body:
    if (datPersonaFindRosterRecordById(*(u16 *)(yListSlotEntry((s8)start, i) + 2)) == 0) {
        result = 0;
        goto done;
    }
    i = (s16)(i + 1);
loop_test:
    if ((s16)i < limit) {
        goto loop_body;
    }
    result = 1;
done:
    return result;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_00313A80
s32 fclCombineSlotOwned(s8 arg0, s8 arg1)
{
    return datPersonaFindRosterRecordById(*(u16 *)(*(u8 **)((u8 *)D_00642EF0 + (arg0 * 8)) + (arg1 * 0x20))) != 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_00313AE0
s8 fclCombineItemSlot(s8 arg0, u16 arg1)
{
    s32 i;
    s32 id;
    u8 **table;

    i = 0;
    id = arg1;
    table = (u8 **)((u8 *)D_00642F00 + arg0 * 8);
    for (; i < 6; i++) {
        if (!func_0031_ne(*(u16 *)(table[-4] + i * 0x20), id)) {
            return i;
        }
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// FUN_00313B50
void cmmDateSelectionRefresh(u8 *arg0)
{
    s32 month;
    s32 day;
    u8 current_day;
    u8 current_month;
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    current_day = fclCalendarDay();
    current_month = fclCalendarMonth();
    *(s8 *)(work + 0x2D4) = findDateEntry(current_month, current_day);
    cmmDateSelectionSelect(arg0, fclCalendarMonth(), fclCalendarDay(), 0);
    month = fclCalendarMonth();
    day = (u8)fclCalendarDay() + 1;
    fclCalGetNextDate(&month, &day);
    *(s8 *)(work + 0x2D5) = findDateEntry((u8)month, (u8)day);
    cmmDateSelectionSelect(arg0, (u8)month, (u8)day, 1);
    *(u8 *)(work + 0x2D2) = month;
    *(u8 *)(work + 0x2D3) = day;
    *(u8 *)(work + 0x2D6) = 0;
}
#pragma pop

/* Select the highest-priority enabled date entry, retaining mandatory
 * priority-100 entries and the retail repeated count-flag reads.
 * The calendar branch consumes the low day byte; the explicit-date
 * branch reuses that parameter as its signed-halfword loop index. */
typedef struct DateSelectionWork {
    u8 beforeCounts[0x2C0];
    s16 counts[2];
    u8 selectedFlags[2][5];
    u8 beforeDate[4];
    u8 nextMonth;
    u8 nextDay;
    s8 slots[2];
    u8 nextSelection;
    u8 padding;
} DateSelectionWork;

#pragma push
#pragma opt_loop_invariants off
// FUN_00313D20
#pragma push
#pragma opt_loop_invariants on
void cmmDateSelectionSelect(u8 *task, u8 month, s32 day, s8 mode)
{
    extern s64 calGetDayEntryForMonthDay(s32 month, s32 day);
    extern u8 D_00643D00[];
    s16 best;
    DateSelectionWork *state;
    s8 selected;
    s32 savedMode;
    s8 slot;

    state = *(DateSelectionWork **)(task + 0x38);
    best = -1;
    savedMode = mode;
    slot = state->slots[mode];
    if (slot == -1) {
        u8 *fallback;
        s16 i;
        u8 *entry;
        s8 priority;
        fallback = D_00643D00 + 20 * (s8)calGetDayEntryForMonthDay(month, (u8)day);
        for (i = 0; i < 5; i++) {
            state->selectedFlags[savedMode][i] = 0;
            entry = fallback + 4 * i;
            if (*(s8 *)entry != 0) {
                priority = *((s8 *)entry + 1);
                if (best < priority) {
                    selected = i;
                    best = priority;
                }
            }
        }
        if (best != -1) state->selectedFlags[savedMode][selected] = 1;
    } else {
        u8 *date;
        s16 j;
        u8 *flag;
        u8 *entry;
        s8 priority;
        date = D_006432B0 + 28 * slot;
        state->counts[mode] = 0;
        /* Retail tests this same flag three times; the date pointer stays fixed. */
        for (j = 0; j < 3; j++) {
            if (*((s8 *)date + 2) != 0) ++state->counts[mode];
        }
        /* The calendar path consumes day; this branch reuses it as an index. */
        day = 0;
        while ((s16)day < 5) {
            flag = &state->selectedFlags[(u32)mode][(s16)day];
            *flag = 0;
            entry = date + 4 * (s16)day;
            if (*((s8 *)entry + 8) != 0) {
                ++state->counts[mode];
                priority = *((s8 *)entry + 9);
                if (priority == 100) *flag = 1;
                else if (best < priority) {
                    selected = day;
                    best = priority;
                }
            }
            day = (s16)(day + 1);
        }
        if (best != -1) state->selectedFlags[(u32)mode][selected] = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_00313FB0
s32 datPersonaExpToNextLevel(u8 *arg0)
{
    s32 temp;

    temp = datPersonaGetExpForLevel(arg0, (arg0[4] + 1) & 0xFFFF);
    return temp - datPersonaGetExpForLevel(arg0, arg0[4]);
}
#pragma pop

/* measured: corrected all six callee declarations from the verified definitions. */
extern void shdPersonaSetDisplayState(u8 *arg0, s32 arg1, u32 arg2, s8 arg3);
extern s32 shdPersonaIsTransitioning(u8 *arg0);
extern void shdPersonaStartSlideIn(u8 *arg0);
extern void shdPersonaBeginClose(u8 *arg0);
extern u8 shdPersonaGetAlpha(u8 *arg0);
#pragma push
#pragma opt_loop_invariants off
// FUN_00314010
s32 fclDrawTaskStep(u8 *arg0) {
    s32 value;
    s8 state;
    u8 *work;
    s8 arg3;
    u32 arg2;
    s32 task_int;
    u8 *task;

    work = *(u8 **)(arg0 + 0x38);
    state = *(s8 *)(work + 0);
    switch (state) {
    case 0:
        arg3 = *(s8 *)(work + 0xC);
        arg2 = *(u32 *)(work + 8);
        task_int = 0;
        task = *(u8 **)(work + 4);
        shdPersonaSetDisplayState(task, task_int, arg2, arg3);
        shdPersonaSetExtraValue((int)*(u8 **)(work + 4), 0);
        *(s8 *)(work + 0) = 1;
        /* fallthrough */
    case 1:
        if ((shdPersonaGetAlpha(*(u8 **)(work + 4)) & 0xFF) == 0xFF) {
            *(s8 *)(work + 0) = 5;
        } else if (shdPersonaIsTransitioning(*(u8 **)(work + 4)) != 1) {
            shdPersonaStartSlideIn(*(u8 **)(work + 4));
        } else {
            *(s8 *)(work + 0) = 2;
        }
        goto block_33;
    case 2:
        if (shdPersonaIsTransitioning(*(u8 **)(work + 4)) != 1) {
            *(s8 *)(work + 0) = 5;
        }
        goto block_33;
    case 3:
        if (shdPersonaIsTransitioning(*(u8 **)(work + 4)) != 1) {
            shdPersonaBeginClose(*(u8 **)(work + 4));
        } else {
            *(s8 *)(work + 0) = 4;
        }
        goto block_33;
    case 4:
        if (shdPersonaIsTransitioning(*(u8 **)(work + 4)) != 1) {
            *(s8 *)(work + 0) = 6;
        }
        goto block_33;
    case 8:
        shdPersonaSetDisplayState(*(u8 **)(work + 4), 0, *(u32 *)(work + 8), *(s8 *)(work + 0xC));
        value = *(s32 *)(work + 0x10);
        if (value != 0) {
            shdPersonaSetExtraValue((int)*(u8 **)(work + 4), value);
        }
        *(s8 *)(work + 0) = 9;
        /* fallthrough */
    case 9:
        if ((shdPersonaGetAlpha(*(u8 **)(work + 4)) & 0xFF) == 0xFF) {
            *(s8 *)(work + 0) = 0xD;
        } else if (shdPersonaIsTransitioning(*(u8 **)(work + 4)) != 1) {
            shdPersonaStartSlideIn(*(u8 **)(work + 4));
        } else {
            *(s8 *)(work + 0) = 0xA;
        }
        goto block_33;
    case 10:
        if (shdPersonaIsTransitioning(*(u8 **)(work + 4)) != 1) {
            *(s8 *)(work + 0) = 0xD;
        }
        goto block_33;
    case 11:
        if (shdPersonaIsTransitioning(*(u8 **)(work + 4)) != 1) {
            shdPersonaBeginClose(*(u8 **)(work + 4));
        } else {
            *(s8 *)(work + 0) = 0xC;
        }
        goto block_33;
    case 12:
        if (shdPersonaIsTransitioning(*(u8 **)(work + 4)) != 1) {
            *(s8 *)(work + 0) = 0xE;
        }
        goto block_33;
    case 15:
        if (shdPersonaIsTransitioning((u8 *)*(s32 *)(work + 4)) != 1) {
            return -1;
        }
        goto block_33;
    case 16:
        return -1;
    default:
block_33:
        return 0;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_003142F0
void fclDrawTaskDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop
