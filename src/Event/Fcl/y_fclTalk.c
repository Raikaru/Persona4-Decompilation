#include "list_item_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "kwln_task_internal.h"
/* Persona 4 USA decompilation - y_fclTalk.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "member_access.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern char D_0064A000[];
extern char D_0064A018[];
extern char D_0064A030[];
extern char D_0064A050[];
extern void chkmemAllocSiteTag(const void *file, s32 line);

extern s8 nmMesWindowAcquire(void *);
extern s32 nmMesWindowShowSlotRecord(s8, s32);
extern void nmMesWindowSetSlotString(s8, s32, void *);
extern void *datGetItemNameId(s16);
extern void frFontExCopyString(void *, void *, s32);
extern s32 datGetFlag(s32);
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s32 fclCalendarMonthOrder(u8);
extern s32 nmMesWindowSlotStatus(s8);
extern void nmMesWindowStepSlotRelease(s32);
extern void nmMesWindowDestroySlot(s8);
extern u8 D_00645240[];
extern u8 D_006450E0[];
extern u8 D_00647EE0[];
extern u32 D_0064A078[];
extern u32 D_0064A07C[];
extern u32 D_0064A080[];
extern u8 D_006450B0[];
extern s32 datItemMoonGateFirst(s16);
extern s32 datItemMoonGateSecond(s16);
extern s32 fclShopIsSpecialItem(u16);
extern u32 RpRandom(void);
extern s32 weaponShopTalkUpdate(u8 *task);
extern void weaponShopTalkDestroy(u8 *task);
extern s32 itemShopTalkUpdate(u8 *task);
extern void itemShopTalkDestroy(u8 *task);
extern s32 wshopMaterialTalkUpdate(u8 *task);
extern void wshopMaterialTalkDestroy(u8 *task);

/* Two-byte dialogue task allocation: phase followed by the message slot. */
typedef struct FclTalkWork {
    s8 state;
    s8 messageSlot;
} FclTalkWork;

/* Material task allocation (0x180C): 0x600 item indices and their count. */
typedef struct FclMaterialTalkWork {
    s8 state;
    s8 messageSlot;
    u8 pad02[2];
    s32 items[0x600];
    s32 count;
    s8 dateRange;
    u8 pad1809[3];
} FclMaterialTalkWork;

/* Twelve-byte item-shop message rows and four-byte material date windows. */
typedef struct FclShopTalkRecord {
    s16 message;
    u8 pad02[2];
    s32 flag;
    u8 startMonth, startDay, endMonth, endDay;
} FclShopTalkRecord;
typedef struct FclTalkDateRange {
    u8 startMonth, startDay, endMonth, endDay;
} FclTalkDateRange;

/* Create a two-byte weapon-shop dialogue task under parent; only the phase is initialized. */
// FUN_00331FC0
void weaponShopTalkCreate(u8 *parent) {
    u8 *work;

    chkmemAllocSiteTag(D_0064A018, 0xC8);
    work = D_008873F4[0](1, 2, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064A030), 0xF, 0, 0, weaponShopTalkUpdate, weaponShopTalkDestroy, (u8 *)(work));
    *work = 0;
}
/* measured: nd 165 with a full C body (object 592B against a 576B window).
   Wave 9 ran out of turns here and left it uncommitted, so this is a partial
   adaptation rather than a settled floor -- re-attempt from the m2c draft with
   the brief's recipes before treating any of it as established. */
/* Select the first flagged item-shop message whose calendar window includes today, then release its message slot. */
// FUN_00332060
s32 itemShopTalkUpdate(u8 *task) {
    FclShopTalkRecord *talkRecord;
    /* measured: access-site typing hoists the flag address; a separate typed record local preserves the reload. */
    s8 *work;
    u8 *entry;
    s8 i;
    s32 currentDate;
    s16 calendarDate;
    s16 startDate;
    s16 endDate;

    work = (s8 *)((KwlnTask *)task)->work;
    i = 0;
    calendarDate = (s16)(100 * (fclCalendarMonthOrder(fclCalendarMonth()) & 0xFF) +
                        (fclCalendarDay() & 0xFF));
    switch (((FclTalkWork *)work)->state) {
    case 0:
        goto state_zero;
    case 1:
        goto state_one;
    default:
        goto done;
    }

state_zero:
    currentDate = calendarDate;
    do {
        entry = D_006450E0 + (i * 0xC);
        talkRecord = (FclShopTalkRecord *)entry;
        startDate = (s16)(((FclShopTalkRecord *)entry)->startDay +
                    100 * (fclCalendarMonthOrder(((FclShopTalkRecord *)entry)->startMonth) & 0xFF));
        endDate = (s16)(((FclShopTalkRecord *)entry)->endDay +
                    100 * (fclCalendarMonthOrder(((FclShopTalkRecord *)entry)->endMonth) & 0xFF));
        if (datGetFlag(((FclShopTalkRecord *)entry)->flag) != 0 ||
            talkRecord->flag == 0) {
            if (startDate > currentDate) {
                goto scan_next;
            }
            if (endDate >= currentDate) {
                work[1] = nmMesWindowAcquire(D_00647EE0);
                nmMesWindowShowSlotRecord(work[1], ((FclShopTalkRecord *)entry)->message);
                (*work)++;
                return 0;
            }
        }
scan_next:
        i++;
    } while (((FclShopTalkRecord *)entry)->message != -1);
    (*work)++;
    goto done;

state_one:
    if (nmMesWindowSlotStatus(work[1]) != 0) {
        nmMesWindowStepSlotRelease(work[1]);
        goto done;
    }
    nmMesWindowDestroySlot(work[1]);
    return -1;

done:
    return 0;
}
/* Release the item-shop dialogue allocation after its task finishes. */
// FUN_003322A0
void itemShopTalkDestroy(u8 *task) {
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Create a two-byte item-shop dialogue task under parent. */
// FUN_003322D0
void itemShopTalkCreate(u8 *parent) {
    u8 *work;

    chkmemAllocSiteTag(D_0064A018, 0x12D);
    work = D_008873F4[0](1, 2, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064A050), 0xF, 0, 0, itemShopTalkUpdate, itemShopTalkDestroy, (u8 *)(work));
    *work = 0;
}

/* Show a material requirement using the packed material item id and the selected item category label. */
// FUN_00332370
void wshopMaterialTalkShowRequirement(u8 *task, s32 itemId, s32 materialInfo) {
    u8 categoryName[0x20];
    s32 category;
    u8 *work;
    s16 materialId;

    work = ((KwlnTask *)task)->work;
    materialId = (s16)((materialInfo & 0xFFF00) >> 8);
    if (materialInfo == 0) {
        *(work + 1) = nmMesWindowAcquire(D_00645240);
        nmMesWindowSetSlotString(*(work + 1), 0, datGetItemNameId(materialId));
        nmMesWindowShowSlotRecord(*(work + 1), 0x1E);
        return;
    }
    *(work + 1) = nmMesWindowAcquire(D_00645240);
    nmMesWindowSetSlotString(*(work + 1), 0, datGetItemNameId(materialId));
    category = datEntryEvaluateFlags((s16)itemId);
    if (category == 0xE) {
        frFontExCopyString((void *)D_0064A07C[0], categoryName, 0x20);
        nmMesWindowSetSlotString(*(work + 1), 1, categoryName);
    } else if (category == 0xF) {
        frFontExCopyString((void *)D_0064A080[0], categoryName, 0x20);
        nmMesWindowSetSlotString(*(work + 1), 1, categoryName);
    } else {
        frFontExCopyString((void *)D_0064A078[0], categoryName, 0x20);
        nmMesWindowSetSlotString(*(work + 1), 1, categoryName);
    }
    nmMesWindowShowSlotRecord(*(work + 1), 0x1F);
}

/* Build the date-gated material candidate list, show a randomly selected requirement and wait for dialogue completion. */
// FUN_00332520
s32 wshopMaterialTalkUpdate(u8 *task) {
    FclMaterialTalkWork *materialWork;
    /* measured: a typed work local preserves the count reloads; MEMBER retains the indexed selection address order. */
    s8 *work;
    s32 currentDate;
    s16 calendarDate;
    s8 index;
    u8 *entry;
    s32 i;
    s32 category;
    s32 selected;
    u32 offset;
    s16 startDate;
    s16 endDate;

    work = (s8 *)((KwlnTask *)task)->work;
    materialWork = (FclMaterialTalkWork *)work;
    calendarDate = (s16)(100 * (fclCalendarMonthOrder(fclCalendarMonth()) & 0xFF) +
                        (fclCalendarDay() & 0xFF));
    index = 0;
    switch (((FclTalkWork *)work)->state) {
    case 0:
        goto state_zero_32520;
    case 1:
        goto state_one_32520;
    case 2:
        goto state_two_32520;
    case 3:
        goto state_three_32520;
    default:
        goto done_32520;
    }

state_zero_32520:
    currentDate = calendarDate;
    do {
        entry = D_006450B0 + (index * 4);
        startDate = (s16)(((FclTalkDateRange *)entry)->startDay +
                    100 * (fclCalendarMonthOrder(((FclTalkDateRange *)entry)->startMonth) & 0xFF));
        endDate = (s16)(((FclTalkDateRange *)entry)->endDay +
                    100 * (fclCalendarMonthOrder(((FclTalkDateRange *)entry)->endMonth) & 0xFF));
        if (startDate > currentDate) {
            goto state_zero_next_32520;
        }
        if (endDate >= currentDate) {
            (*work)++;
            work[0x1808] = index;
            return 0;
        }
state_zero_next_32520:
        index++;
    } while (((FclTalkDateRange *)entry)->startMonth != 0);
    return -1;

state_one_32520:
    ((FclMaterialTalkWork *)work)->count = 0;
    for (i = 0; i < 0x600; i++) {
        ((FclMaterialTalkWork *)work)->items[i] = 0;
        category = datEntryEvaluateFlags((s16)i);
        if (category != 0x10 && category != 0x11 && category != 0x12) {
            if (work[0x1808] == datItemAvailableMonth((s16)i)) {
                if (fclShopIsSpecialItem(
                        (u16)((datItemMoonGateFirst((s16)i) & 0xFFF00) >> 8)) == 0) {
                    if (fclMoonPhaseAtLeast(
                            (datItemMoonGateFirst((s16)i) & 0xFFF00) >> 8,
                            datItemMoonGateFirst((s16)i) & 0xFF) == 0 ||
                        fclMoonPhaseAtLeast(
                            (datItemMoonGateSecond((s16)i) & 0xFFF00) >> 8,
                            datItemMoonGateSecond((s16)i) & 0xFF) == 0) {
                        ((FclMaterialTalkWork *)work)->items[materialWork->count] = i;
                        materialWork->count =
                            materialWork->count + 1;
                    }
                }
            }
        }
    }
    (*work)++;
    goto done_32520;

state_two_32520:
    if (((FclMaterialTalkWork *)work)->count == 0) {
        work[1] = nmMesWindowAcquire(D_00645240);
        nmMesWindowShowSlotRecord(work[1], 0x1D);
    } else {
        offset = (RpRandom() % materialWork->count) * 4;
        selected = MEMBER(s32, offset + (u32)work, FclMaterialTalkWork, items[0]);
        if (((datItemMoonGateFirst((s16)selected) & 0xFFF00) >> 8) != 0x500) {
            wshopMaterialTalkShowRequirement(task, selected,
                          datItemMoonGateFirst((s16)selected));
        } else if (((datItemMoonGateSecond((s16)selected) & 0xFFF00) >> 8) !=
                   0x500) {
            wshopMaterialTalkShowRequirement(task, selected,
                          datItemMoonGateSecond((s16)selected));
        }
    }
    (*work)++;
    goto done_32520;

state_three_32520:
    if (nmMesWindowSlotStatus(work[1]) != 0) {
        nmMesWindowStepSlotRelease(work[1]);
        goto done_32520;
    }
    nmMesWindowDestroySlot(work[1]);
    return -1;

done_32520:
    return 0;

}
/* Release the material dialogue task allocation. */
// FUN_003329B0
void wshopMaterialTalkDestroy(u8 *task) {
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

/* Create the 0x180C-byte material dialogue work and initialize its phase/date-window index. */
// FUN_003329E0
void wshopMaterialTalkCreate(u8 *parent) {
    u8 *work;

    chkmemAllocSiteTag(D_0064A018, 0x1EC);
    work = D_008873F4[0](1, 0x180C, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064A000), 0xF, 0, 0, wshopMaterialTalkUpdate, wshopMaterialTalkDestroy, (u8 *)(work));
    *work = 0;
    *(work + 0x1808) = 0;
}
