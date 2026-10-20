/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 003136b0-003142f0 */

/* Unit optimizer settings shared by the neighboring functions. */
#pragma opt_loop_invariants off

#include "include_asm.h"
#include "member_access.h"
#include "type.h"
#include "operand_order_internal.h"
#include "kwln_task_internal.h"
#include "shdPersona_internal.h"
#include "datPersona_internal.h"
#include "fcl_combine_row_internal.h"
typedef struct FclPersonaDrawWork {
    s8 state;
    u8 pad01[3];
    union { u8 *task; s32 handle; } display;
    u32 mode;
    s8 kind;
    u8 pad0D[3];
    s32 extraValue;
} FclPersonaDrawWork;

typedef struct CmmDateOption { s8 enabled, priority; u8 pad02[2]; } CmmDateOption;
typedef struct CmmDateRecord {
    s8 month, day;
    s8 countFlag;
    u8 pad03[5];
    CmmDateOption options[5];
} CmmDateRecord;
typedef struct FclMaterialTableEntry { u8 *recipes; s32 unk04; } FclMaterialTableEntry;

typedef struct FclMaterialRecipe {
    u16 result;
    u8 pad02[6];
    s16 materials[8];
    u8 pad18[8];
} FclMaterialRecipe;

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

extern void (*jtbl_008873EC[])(void *);
extern u32 D_00642EF0[];
extern u32 D_00642F00[];
extern u8 *yListSlotWork(s8 );
extern void yListSlotAppend(s8 , s32 , s8 );
extern u8 *yListSlotEntry();
extern s32 datGetFlag(s32 );
extern s32 datItemCount(s16 itemId);
extern u16 cmmCommunityRecordValue(u16 );
extern u8 D_006432B0[];
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern void fclCalGetNextDate(s32 *month, s32 *day);
extern void cmmDateSelectionSelect(u8 *, u8 month, s32 day, s8 mode);
/* Search dates starting at index one, returning minus one at the sentinel. */
static inline s8 cmmFindDateEntry(u8 month, u8 day)
{
    s8 index = 0;
    u8 *entry;

    for (;;) {
        index++;
        entry = D_006432B0 + index * 0x1C;
        if (((CmmDateRecord *)entry)->month == -1 && ((CmmDateRecord *)entry)->day == -1) return -1;
        if (((CmmDateRecord *)entry)->month == month && ((CmmDateRecord *)entry)->day == day) return index;
    }
}

/* Apply the item and community/flag prerequisites for the specially gated fusion results. */
// FUN_003136B0
s32 fclCombineMaterialAvailable(u16 persona)
{
    s32 value;
    s32 result;

    value = persona & 0xFFFF;
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

/* Populate the result and material list slots, marking materials already present in the roster. */
// FUN_00313800
void fclCombineMaterialListBuild(s8 materialCount)
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
    /* D_00642F00 labels the third eight-byte descriptor; select the preceding descriptor pair by index. */
    table = (u8 *)D_00642F00 + materialCount * 8;
    for (; row < 6; row++) {
        entry = ((FclMaterialTableEntry *)table)[-2].recipes + row * 0x20;
        if (((FclMaterialRecipe *)entry)->result != 0 && fclCombineMaterialAvailable(((FclMaterialRecipe *)entry)->result) == 1) {
            yListSlotAppend(0, (s16)((FclMaterialRecipe *)entry)->result, 0);
            items = entry + 4;
            yListSlotWork(0)[0x14 + selected] = 1;
            item = 0;
            column = selected + 1;
            for (; item < materialCount; item++) {
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

/* Require every material in the selected list slot to be present in the Persona roster. */
// FUN_003139D0
s32 fclCombineMaterialsHeld(s8 materialCount, s8 slot)
{
    s32 i;
    s32 start;
    s64 limit;
    s32 result;

    i = 0;
    start = slot + 1;
    limit = materialCount;
    goto loop_test;
loop_body:
    if (datPersonaFindRosterRecordById(((FclCombinePersonaHeader *)yListSlotEntry((s8)start, i))->personaId) == 0) {
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

// FUN_00313A80
s32 fclCombineSlotOwned(s8 materialCount, s8 slot)
{
    return datPersonaFindRosterRecordById(((FclMaterialRecipe *)((u8 **)D_00642EF0)[materialCount * 2])[slot].result) != 0;
}

/* Find the result id in the selected six-row recipe table, falling back to row zero. */
// FUN_00313AE0
s8 fclCombineItemSlot(s8 materialCount, u16 persona)
{
    s32 i;
    s32 id;
    u8 **table;

    i = 0;
    id = persona;
    table = (u8 **)((u8 *)D_00642F00 + materialCount * 8);
    for (; i < 6; i++) {
        if (!operandOrderNotEqual(((FclMaterialRecipe *)table[-4])[i].result, id)) {
            return i;
        }
    }
    return 0;
}

/* Resolve date-selection entries for today and tomorrow, then clear the pending selection. */
#pragma push
#pragma opt_loop_invariants on
/* measured: cached and typed date-table bases do not match; baseline retains 101 differing words. */
// FUN_00313B50
void cmmDateSelectionRefresh(u8 *task)
{
    s32 month;
    s32 day;
    u8 current_day;
    u8 current_month;
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    current_day = fclCalendarDay();
    current_month = fclCalendarMonth();
    ((DateSelectionWork *)work)->slots[0] = cmmFindDateEntry(current_month, current_day);
    cmmDateSelectionSelect(task, fclCalendarMonth(), fclCalendarDay(), 0);
    month = fclCalendarMonth();
    day = (u8)fclCalendarDay() + 1;
    fclCalGetNextDate(&month, &day);
    ((DateSelectionWork *)work)->slots[1] = cmmFindDateEntry((u8)month, (u8)day);
    cmmDateSelectionSelect(task, (u8)month, (u8)day, 1);
    ((DateSelectionWork *)work)->nextMonth = month;
    ((DateSelectionWork *)work)->nextDay = day;
    ((DateSelectionWork *)work)->nextSelection = 0;
}
#pragma pop

/* Select the highest-priority enabled date entry, retaining mandatory
 * priority-100 entries and the retail repeated count-flag reads.
 * The calendar branch consumes the low day byte; the explicit-date
 * branch reuses that parameter as its signed-halfword loop index. */


/* Select the highest-priority enabled date option while retaining mandatory priority-100 options. */
#pragma push
#pragma opt_loop_invariants on
/* measured: cached selection/count pointers and typed option access do not match; baseline retains 133 differing words. */
// FUN_00313D20
void cmmDateSelectionSelect(u8 *task, u8 month, s32 day, s8 mode)
{
    extern s64 calGetDayEntryForMonthDay(s32 month, s32 day);
    extern u8 D_00643D00[];
    s16 best;
    DateSelectionWork *state;
    s8 selected;
    s32 savedMode;
    s8 slot;

    state = (DateSelectionWork *)((struct KwlnTask *)task)->work;
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
            if (((CmmDateOption *)entry)->enabled != 0) {
                priority = ((CmmDateOption *)entry)->priority;
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
            if (((CmmDateRecord *)date)->countFlag != 0) ++state->counts[mode];
        }
        /* The calendar path consumes day; this branch reuses it as an index. */
        day = 0;
        while ((s16)day < 5) {
            flag = &state->selectedFlags[(u32)mode][(s16)day];
            *flag = 0;
            entry = date + 4 * (s16)day;
            if (((CmmDateOption *)(entry + 8))->enabled != 0) {
                ++state->counts[mode];
                priority = ((CmmDateOption *)(entry + 8))->priority;
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

/* Subtract the current level threshold from the next level threshold. */
// FUN_00313FB0
s32 datPersonaExpToNextLevel(u8 *persona)
{
    s32 temp;

    temp = datPersonaGetExpForLevel(persona, (persona[4] + 1) & 0xFFFF);
    return temp - datPersonaGetExpForLevel(persona, persona[4]);
}

/* measured: corrected all six callee declarations from the verified definitions. */
extern void shdPersonaSetDisplayState(u8 *, s32 , u32 , s8 );
extern s32 shdPersonaIsTransitioning(u8 *);
extern void shdPersonaStartSlideIn(u8 *);
extern void shdPersonaBeginClose(u8 *);
extern u8 shdPersonaGetAlpha(u8 *);
/* Drive the child Persona display through opening, reconfiguration and closing transitions. */
// FUN_00314010
s32 fclDrawTaskStep(u8 *ownerTask) {
    /* measured: remaining task/date/recipe byte accesses preserve b210 reload and address scheduling; individual typed substitutions lose MATCH. */
    s32 value;
    s8 state;
    u8 *work;
    s8 kind;
    u32 mode;
    s32 displayState;
    u8 *task;

    work = ((struct KwlnTask *)ownerTask)->work;
    state = ((FclPersonaDrawWork *)work)->state;
    switch (state) {
    case 0:
        kind = ((FclPersonaDrawWork *)work)->kind;
        mode = ((FclPersonaDrawWork *)work)->mode;
        displayState = 0;
        task = ((FclPersonaDrawWork *)work)->display.task;
        shdPersonaSetDisplayState(task, displayState, mode, kind);
        shdPersonaSetExtraValue((int)MEMBER(u8 *, work, FclPersonaDrawWork, display.task), 0);
        ((FclPersonaDrawWork *)work)->state = 1;
        /* fallthrough */
    case 1:
        if ((shdPersonaGetAlpha(((FclPersonaDrawWork *)work)->display.task) & 0xFF) == 0xFF) {
            ((FclPersonaDrawWork *)work)->state = 5;
        } else if (shdPersonaIsTransitioning(MEMBER(u8 *, work, FclPersonaDrawWork, display.task)) != 1) {
            shdPersonaStartSlideIn(MEMBER(u8 *, work, FclPersonaDrawWork, display.task));
        } else {
            ((FclPersonaDrawWork *)work)->state = 2;
        }
        goto block_33;
    case 2:
        if (shdPersonaIsTransitioning(((FclPersonaDrawWork *)work)->display.task) != 1) {
            ((FclPersonaDrawWork *)work)->state = 5;
        }
        goto block_33;
    case 3:
        if (shdPersonaIsTransitioning(((FclPersonaDrawWork *)work)->display.task) != 1) {
            shdPersonaBeginClose(MEMBER(u8 *, work, FclPersonaDrawWork, display.task));
        } else {
            ((FclPersonaDrawWork *)work)->state = 4;
        }
        goto block_33;
    case 4:
        if (shdPersonaIsTransitioning(((FclPersonaDrawWork *)work)->display.task) != 1) {
            ((FclPersonaDrawWork *)work)->state = 6;
        }
        goto block_33;
    case 8:
        shdPersonaSetDisplayState(((FclPersonaDrawWork *)work)->display.task, 0, ((FclPersonaDrawWork *)work)->mode, ((FclPersonaDrawWork *)work)->kind);
        value = ((FclPersonaDrawWork *)work)->extraValue;
        if (value != 0) {
            shdPersonaSetExtraValue((int)MEMBER(u8 *, work, FclPersonaDrawWork, display.task), value);
        }
        ((FclPersonaDrawWork *)work)->state = 9;
        /* fallthrough */
    case 9:
        if ((shdPersonaGetAlpha(((FclPersonaDrawWork *)work)->display.task) & 0xFF) == 0xFF) {
            ((FclPersonaDrawWork *)work)->state = 0xD;
        } else if (shdPersonaIsTransitioning(MEMBER(u8 *, work, FclPersonaDrawWork, display.task)) != 1) {
            shdPersonaStartSlideIn(MEMBER(u8 *, work, FclPersonaDrawWork, display.task));
        } else {
            ((FclPersonaDrawWork *)work)->state = 0xA;
        }
        goto block_33;
    case 10:
        if (shdPersonaIsTransitioning(((FclPersonaDrawWork *)work)->display.task) != 1) {
            ((FclPersonaDrawWork *)work)->state = 0xD;
        }
        goto block_33;
    case 11:
        if (shdPersonaIsTransitioning(((FclPersonaDrawWork *)work)->display.task) != 1) {
            shdPersonaBeginClose(MEMBER(u8 *, work, FclPersonaDrawWork, display.task));
        } else {
            ((FclPersonaDrawWork *)work)->state = 0xC;
        }
        goto block_33;
    case 12:
        if (shdPersonaIsTransitioning(((FclPersonaDrawWork *)work)->display.task) != 1) {
            ((FclPersonaDrawWork *)work)->state = 0xE;
        }
        goto block_33;
    case 15:
        if (shdPersonaIsTransitioning((u8 *)((FclPersonaDrawWork *)work)->display.handle) != 1) {
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

// FUN_003142F0
void fclDrawTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
}
