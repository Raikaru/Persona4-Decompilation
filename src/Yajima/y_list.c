#include "list_item_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "g_data_internal.h"
#include "kwln_task_internal.h"

/* gp-relative global at 0x0076467C (gp - 0x4A74): pointer to the active list. */
static u8 *iGpffffb58c;
/* Shared runtime-loaded persona records; storage is owned by cmmMisc.c. */
extern u8 *iGpffffb3d4;

extern char D_0063FC48[];
extern char D_0063FC58[];
extern u8 *D_00882F70[];
extern s32 fclFusePairByte(s32 , s32 , s32 );
extern s32 fclFuseTripleByte(u16 *, u8 *, u8 *, u8 *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);

extern s32 fclSubClamped(s32 , s32 , s32 , s32 , s8 );
extern void chkmemAllocSiteTag(void *msg, s32 id);
extern void kwlnTaskDestroyWithHierarchy(s32 handle);


extern s32 comuDataApplyListRebuild(u8 *);
extern s32 comuDataApplyOwnedListRebuild(u8 *);
extern void comuDataDestroyListRequest(u8 *);
extern s32 yListSlotRefresh(u8 *);
extern void yListDestroy(void);
extern s8 yListSlotFindFree(void);
extern void yListSlotRelease(s8 );
extern void *memset(void *dest, s32 value, u32 size);
extern s32 yListCompareByKeyDesc(const void *, const void *);
extern s32 yListCompareByWeightedKeyDesc(const void *, const void *);
#include "rw/std/stdlib.h"
#include "datPersona_internal.h"
extern u8 *datPersonaCachedRecord(s32 );

extern void datPersonaInitAllRecords(void);
extern s32 yListRecordsDiffer(u8 *, u8 *);
extern s32 fclAddClamped(s32 , s32 , s32 , s32 , s8 );
extern s64 cmmCommunityIsListable(s32 id);
extern s32 cmmCommunityPassesFlagGate(s32 id);
extern s32 cmmCommunityHasFlagGate(s32 id);
extern void *memcpy(void *dst, const void *src, u32 size);
extern s32 datItemCount(s16 );
extern u32 datEntryGetFlags(s16 );
extern u32 datEntryCategoryMask(s16 );
extern u32 datItemMoonGateFirst(s16 );
extern u32 datItemMoonGateSecond(s16 );

/* The 0x1810-byte item work area stores either paired IDs and quantities
   or a compact ID list. Compaction reads the paired ID after each move. */
typedef struct YListItemRow {
    s16 id;
    s16 quantity;
} YListItemRow;

typedef struct YListItemWork {
    u8 enabled;
    s8 kind;
    s16 count;
    s32 filterA;
    s32 filterB;
    s8 order;
    u8 unknown0D;
    union {
        YListItemRow paired[0x600];
        s16 ids[0x600];
    } rows;
} YListItemWork;

/* Slot constructors allocate 0x3014 bytes. Kinds using the roster reserve
   a 12-by-12 availability matrix before their twelve 0x30-byte records;
   other kinds use the full 256-record array at the same union origin. */
typedef struct YListPersonaWork {
    u8 ready;
    u8 pad01[3];
    union { s32 value; u32 unsignedValue; } kind;
    union { s32 value; s16 half; u16 unsignedHalf; } count;
    u8 pad0C[2];
    s16 cursor;
    s16 scroll;
    u8 pad12[2];
    union {
        DatPersonaRecord records[0x100];
        struct {
            u8 availability[12][12];
            DatPersonaRecord records[12];
            u8 available[12];
        } roster;
    } entries;
} YListPersonaWork;

/* Runtime persona metadata has a 14-byte stride; these are the flags,
   arcana and level bytes consumed by the list filters. */
typedef struct YListPersonaMetadata {
    u16 flags;
    u8 arcana;
    u8 level;
    u8 pad04[10];
} YListPersonaMetadata;

/* 228/240 bytes; fifteen resolved relocations and twelve zero alignment bytes. */
// FUN_002E24A0
/* Create the active item-list task, replacing the previous active list. */
void yListCreate(s32 filterA, s32 filterB, s8 kind, s8 order) {
    u8 *work;

    if (iGpffffb58c != NULL) {
        yListDestroy();
    }
    chkmemAllocSiteTag(D_0063FC48, 0x67);
    work = D_008873F4[0](1, 0x1810, 0x40000);
    iGpffffb58c = (u8 *)(s32)kwlnTaskCreate((const void *)(D_0063FC58), 0xF, 0, 0, comuDataApplyListRebuild, comuDataDestroyListRequest, (u8 *)(work));
    ((YListItemWork *)(work))->filterA = filterA;
    ((YListItemWork *)(work))->filterB = filterB;
    ((YListItemWork *)(work))->kind = kind;
    ((YListItemWork *)(work))->enabled = 1;
    ((YListItemWork *)(work))->order = order;
}

// FUN_002E2590
/* Create a filtered child item list without replacing the active-list handle. */
void yListCreateChild(s32 parent, s32 filterA, s32 filterB, s8 kind, s8 order) {
    u8 *work;

    chkmemAllocSiteTag(D_0063FC48, 0x82);
    work = D_008873F4[0](1, 0x1810, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0063FC58), 0xF, 0, 0, comuDataApplyOwnedListRebuild, comuDataDestroyListRequest, (u8 *)(work));
    ((YListItemWork *)(work))->filterA = filterA;
    ((YListItemWork *)(work))->filterB = filterB;
    ((YListItemWork *)(work))->kind = kind;
    ((YListItemWork *)(work))->enabled = 1;
    ((YListItemWork *)(work))->order = order;
}

// FUN_002E2670
s16 yListCount(void) {
    u8 *task = iGpffffb58c;

    if (task == NULL) {
        return -1;
    }
    return ((YListItemWork *)(((KwlnTask *)(task))->work))->count;
}

// Intent: index of the last entry in the current list (count - 1, clamped), or -1 when no list is active. Pairs with yListCount.
// FUN_002E26A0
s32 yListLastIndex(void) {
    u8 *task = iGpffffb58c;

    if (task == NULL) {
        return -1;
    }
    return fclSubClamped(((YListItemWork *)(((KwlnTask *)(task))->work))->count, 1, 0, 0, 1);
}

// FUN_002E26F0
s16 yListCountFor(void *task) {
    return ((YListItemWork *)(((KwlnTask *)((u8 *)task))->work))->count;
}

// Intent: index of the last entry in the list `task` (count - 1, clamped). Pairs with yListCountFor.
// FUN_002E2700
s32 yListLastIndexFor(void *task) {
    return fclSubClamped(((YListItemWork *)(((KwlnTask *)((u8 *)task))->work))->count, 1, 0, 0, 1);
}

// FUN_002E2740
/* Read an ID using the list kind's paired or compact row representation. */
s32 yListValueAt(s32 index) {
    u8 *task = iGpffffb58c;
    u8 *work;
    s32 count;

    if (task == NULL) {
        return -1;
    }
    work = ((KwlnTask *)(task))->work;
    if (task == NULL) {
        count = -1;
    } else {
        count = ((YListItemWork *)(work))->count;
    }
    if (count < index) {
        return -1;
    }
    switch (((YListItemWork *)(work))->kind) {
    case 1: {
        s32 rowOffset = index * 4;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->id;
    }
    case 2: {
        s32 rowOffset = index * 4;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->id;
    }
    case 3: {
        s32 rowOffset = index * 2;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->id;
    }
    case 4: {
        s32 rowOffset = index * 4;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->id;
    }
    default:
        return -1;
    }
}

// FUN_002E2830
/* Read a task-owned list ID using its kind-dependent row stride. */
s32 yListValueAtFor(u8 *task, s32 index) {
    u8 *work = ((KwlnTask *)(task))->work;

    if (((YListItemWork *)(work))->count < index) {
        return -1;
    }
    switch (((YListItemWork *)(work))->kind) {
    case 1: {
        s32 rowOffset = index * 4;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->id;
    }
    case 2: {
        s32 rowOffset = index * 4;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->id;
    }
    case 3: {
        s32 rowOffset = index * 2;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->id;
    }
    case 4: {
        s32 rowOffset = index * 4;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->id;
    }
    default:
        return -1;
    }
}

// FUN_002E28F0
/* Read the paired quantity, or return one for kinds without quantities. */
s16 yListAuxValueAtFor(u8 *task, s32 index) {
    u8 *work = ((KwlnTask *)(task))->work;

    if (((YListItemWork *)(work))->count < index) {
        return -1;
    }
    switch (((YListItemWork *)(work))->kind) {
    case 1: {
        s32 rowOffset = index * 4;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->quantity;
    }
    case 2:
        return 1;
    case 3:
        return 1;
    case 4: {
        s32 rowOffset = index * 4;
        return ((YListItemRow *)((u8 *)(rowOffset + (u32)work) + 0xE))->quantity;
    }
    default:
        return -1;
    }
}

// FUN_002E29A0
void yListDestroy(void) {
    u8 *task = iGpffffb58c;

    if (task != NULL) {
        kwlnTaskDestroyWithHierarchy((s32)task);
        iGpffffb58c = NULL;
    }
}

// FUN_002E29D0
s8 yListKind(void) {
    u8 *task = iGpffffb58c;

    if (task != NULL) {
        return (s8)((YListItemWork *)(((KwlnTask *)(task))->work))->enabled;
    }
    return -1;
}

// FUN_002E2A00
s8 yListKindFor(void *task) {
    return (s8)((YListItemWork *)(((KwlnTask *)((u8 *)task))->work))->enabled;
}


#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants on
static inline s32 yListAcceptsItem(u8 *owner, s16 id)
{
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    u8 *filter = *(u8 **)(owner + 0x38);
    if (*(s32 *)(filter + 4) == 0 && *(s32 *)(filter + 8) == 0) {
        return 1;
    }
    if (*(s32 *)(filter + 4) == 0 && (*(s32 *)(filter + 8) & datEntryCategoryMask(id))) {
        return 1;
    }
    if (*(s32 *)(filter + 8) == 0 && (*(s32 *)(filter + 4) & datEntryGetFlags(id))) {
        return 1;
    }
    if ((*(s32 *)(filter + 4) & datEntryGetFlags(id)) &&
        (*(s32 *)(filter + 8) & datEntryCategoryMask(id))) {
        return 1;
    }
    return 0;
}

/* measured: 2888 code bytes and eight zero alignment bytes; the scoped
   common-subexpression and loop-invariant settings preserve all siblings. */
// FUN_002E2A10
/* Rebuild the active filtered item list, optionally moving flagged IDs first or sorting by price. */
void yListRebuild(s32 filterA, s32 filterB, s8 kind, s8 order) {
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    s32 reorder[0x600];
    s32 sortedIds[0x600];
    s32 outputCount;
    s8 mode;
    s16 count;
    s16 category;
    s32 value;
    s32 accepted;
    YListItemWork *work;
    u8 *task;
    task = iGpffffb58c;
    if (task == NULL) {
        return;
    }
    work = *(YListItemWork **)(task + 0x38);
    work->filterA = filterA;
    work->filterB = filterB;
    work->kind = kind;
    work->count = 0;
    category = work->kind;
    switch (category) {
    case 1: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            work->rows.paired[i].quantity = 0;
            work->rows.paired[i].id = 0;
            if ((datItemCount(i) & 0xFF) > 0) {
                accepted = yListAcceptsItem(iGpffffb58c, i);
                if ((accepted == 1) && !(datEntryCategoryMask(i) & 0x2000)) {
                    work->rows.paired[work->count].id = i;
                    work->rows.paired[work->count].quantity = datItemCount(i) & 0xFF;
                    count = fclAddClamped(work->count, 1, 0, 0, 0);
                    work->count = count;
                }
            }
        }
        break;
    }
    case 2: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            accepted = yListAcceptsItem(iGpffffb58c, i);
            if (accepted == 1) {
                category = (s16)func_002be1b0(i);
                if ((category != 0x10) && (category != 0x11) && (category != 0x12)) {
                    if (datGetFlag(0x1462) == 0) {
                        value = (s32)(datItemMoonGateFirst(i) & 0xFFF00) >> 8;
                        if (fclMoonPhaseAtLeast(value, datItemMoonGateFirst(i) & 0xFF) == 1) {
                            value = (s32)(datItemMoonGateSecond(i) & 0xFFF00) >> 8;
                            if (fclMoonPhaseAtLeast(value, datItemMoonGateSecond(i) & 0xFF) == 1) {
                                work->rows.paired[i].quantity = 0;
                                work->rows.paired[work->count].id = i;
                                count = fclAddClamped(work->count, 1, 0, 0, 0);
                                work->count = count;
                            }
                        }
                    } else {
                        work->rows.paired[i].quantity = 0;
                        work->rows.paired[work->count].id = i;
                        count = fclAddClamped(work->count, 1, 0, 0, 0);
                        work->count = count;
                    }
                } else if (datGetFlag(0x1462) == 0) {
                    if (fclItemIsDateAvailable(i) == 1) {
                        work->rows.paired[i].quantity = 0;
                        work->rows.paired[work->count].id = i;
                        count = fclAddClamped(work->count, 1, 0, 0, 0);
                        work->count = count;
                    }
                } else {
                    work->rows.paired[i].quantity = 0;
                    work->rows.paired[work->count].id = i;
                    count = fclAddClamped(work->count, 1, 0, 0, 0);
                    work->count = count;
                }
            }
        }
        break;
    }
    case 3: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            work->rows.ids[i] = 0;
            accepted = yListAcceptsItem(iGpffffb58c, i);
            if (accepted == 1) {
                work->rows.ids[work->count] = i;
                count = fclAddClamped(work->count, 1, 0, 0, 0);
                work->count = count;
            }
        }
        break;
    }
    case 4: {
        s16 i;
        count = fclAddClamped(work->count, 1, 0, 0, 0);
        work->count = count;
        for (i = 0; i < 0x600; i++) {
            work->rows.paired[i].quantity = 0;
            work->rows.paired[i].id = 0;
            if ((datItemCount(i) & 0xFF) > 0) {
                accepted = yListAcceptsItem(iGpffffb58c, i);
                if (accepted == 1) {
                    work->rows.paired[work->count].id = i;
                    work->rows.paired[work->count].quantity = datItemCount(i) & 0xFF;
                    count = fclAddClamped(work->count, 1, 0, 0, 0);
                    work->count = count;
                }
            }
        }
        break;
    }
    default:
        break;
    }
    mode = (s8)order;
    if (mode == 1) {
        s16 fillIndex;
        s16 markIndex;
        s16 compactIndex;
        s16 copyIndex;
        outputCount = 0;
        for (fillIndex = 0; fillIndex < 0x600; fillIndex++) {
            reorder[fillIndex] = -1;
        }
        for (markIndex = 0; markIndex < work->count; markIndex++) {
            if ((clndGetMoonPhase(work->rows.paired[markIndex].id) & 0xFF) & 1) {
                reorder[outputCount] = work->rows.paired[markIndex].id;
                value = clndGetMoonPhase(work->rows.paired[markIndex].id);
                datSetStateTableEntry(work->rows.paired[markIndex].id, (value | 2) & 0xFF);
                work->rows.paired[markIndex].id = -1;
                work->rows.paired[markIndex].quantity = 1;
                outputCount++;
            }
        }
        for (compactIndex = 0; compactIndex < work->count; compactIndex++) {
            if (work->rows.paired[compactIndex].id != -1) {
                reorder[outputCount] = work->rows.paired[compactIndex].id;
                work->rows.paired[compactIndex].quantity = 0;
                outputCount++;
            }
        }
        for (copyIndex = 0; copyIndex < work->count; copyIndex++) {
            work->rows.paired[copyIndex].id = (s16)reorder[copyIndex];
        }
    }
    if (mode == 2) {
        s16 collectIndex;
        s16 sortedIndex;
        for (collectIndex = 0; collectIndex < work->count; collectIndex++) {
            sortedIds[collectIndex] = work->rows.paired[collectIndex].id;
        }
        qsort(sortedIds, work->count, 4, datItemPriceCompare);
        for (sortedIndex = 0; sortedIndex < work->count; sortedIndex++) {
            work->rows.paired[sortedIndex].id = (s16)sortedIds[sortedIndex];
            work->rows.paired[sortedIndex].quantity = 0;
            if ((clndGetMoonPhase(work->rows.paired[sortedIndex].id) & 0xFF) & 1) {
                work->rows.paired[sortedIndex].quantity = 1;
                value = clndGetMoonPhase(work->rows.paired[sortedIndex].id);
                datSetStateTableEntry(work->rows.paired[sortedIndex].id, (value | 2) & 0xFF);
            }
        }
    }
}

#pragma pop
#pragma opt_common_subs on

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants on
/* measured: all 2864 code bytes match with the same scoped settings. */
// FUN_002E3560
/* Rebuild a task-owned filtered item list with the selected ordering mode. */
void yListRebuildFor(u8 *task, s32 filterA, s32 filterB, s8 kind, s32 order) {
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    s32 reorder[0x600];
    s32 sortedIds[0x600];
    s32 outputCount;
    s8 mode;
    s16 count;
    s16 category;
    s32 value;
    s32 accepted;
    YListItemWork *work;
    work = *(YListItemWork **)(task + 0x38);
    work->filterA = filterA;
    work->filterB = filterB;
    work->kind = kind;
    work->count = 0;
    category = work->kind;
    switch (category) {
    case 1: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            work->rows.paired[i].quantity = 0;
            work->rows.paired[i].id = 0;
            if ((datItemCount(i) & 0xFF) > 0) {
                accepted = yListAcceptsItem(task, i);
                if ((accepted == 1) && !(datEntryCategoryMask(i) & 0x2000)) {
                    work->rows.paired[work->count].id = i;
                    work->rows.paired[work->count].quantity = datItemCount(i) & 0xFF;
                    count = fclAddClamped(work->count, 1, 0, 0, 0);
                    work->count = count;
                }
            }
        }
        break;
    }
    case 2: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            accepted = yListAcceptsItem(task, i);
            if (accepted == 1) {
                category = (s16)func_002be1b0(i);
                if ((category != 0x10) && (category != 0x11) && (category != 0x12)) {
                    if (datGetFlag(0x1462) == 0) {
                        value = (s32)(datItemMoonGateFirst(i) & 0xFFF00) >> 8;
                        if (fclMoonPhaseAtLeast(value, datItemMoonGateFirst(i) & 0xFF) == 1) {
                            value = (s32)(datItemMoonGateSecond(i) & 0xFFF00) >> 8;
                            if (fclMoonPhaseAtLeast(value, datItemMoonGateSecond(i) & 0xFF) == 1) {
                                work->rows.paired[i].quantity = 0;
                                work->rows.paired[work->count].id = i;
                                count = fclAddClamped(work->count, 1, 0, 0, 0);
                                work->count = count;
                            }
                        }
                    } else {
                        work->rows.paired[i].quantity = 0;
                        work->rows.paired[work->count].id = i;
                        count = fclAddClamped(work->count, 1, 0, 0, 0);
                        work->count = count;
                    }
                } else if (datGetFlag(0x1462) == 0) {
                    if (fclItemIsDateAvailable(i) == 1) {
                        work->rows.paired[i].quantity = 0;
                        work->rows.paired[work->count].id = i;
                        count = fclAddClamped(work->count, 1, 0, 0, 0);
                        work->count = count;
                    }
                } else {
                    work->rows.paired[i].quantity = 0;
                    work->rows.paired[work->count].id = i;
                    count = fclAddClamped(work->count, 1, 0, 0, 0);
                    work->count = count;
                }
            }
        }
        break;
    }
    case 3: {
        s16 i;
        for (i = 0; i < 0x600; i++) {
            work->rows.ids[i] = 0;
            accepted = yListAcceptsItem(task, i);
            if (accepted == 1) {
                work->rows.ids[work->count] = i;
                count = fclAddClamped(work->count, 1, 0, 0, 0);
                work->count = count;
            }
        }
        break;
    }
    case 4: {
        s16 i;
        count = fclAddClamped(work->count, 1, 0, 0, 0);
        work->count = count;
        for (i = 0; i < 0x600; i++) {
            work->rows.paired[i].quantity = 0;
            work->rows.paired[i].id = 0;
            if ((datItemCount(i) & 0xFF) > 0) {
                accepted = yListAcceptsItem(task, i);
                if (accepted == 1) {
                    work->rows.paired[work->count].id = i;
                    work->rows.paired[work->count].quantity = datItemCount(i) & 0xFF;
                    count = fclAddClamped(work->count, 1, 0, 0, 0);
                    work->count = count;
                }
            }
        }
        break;
    }
    default:
        break;
    }
    mode = (s8)order;
    if (mode == 1) {
        s16 fillIndex;
        s16 markIndex;
        s16 compactIndex;
        s16 copyIndex;
        outputCount = 0;
        for (fillIndex = 0; fillIndex < 0x600; fillIndex++) {
            reorder[fillIndex] = -1;
        }
        for (markIndex = 0; markIndex < work->count; markIndex++) {
            if ((clndGetMoonPhase(work->rows.paired[markIndex].id) & 0xFF) & 1) {
                reorder[outputCount] = work->rows.paired[markIndex].id;
                value = clndGetMoonPhase(work->rows.paired[markIndex].id);
                datSetStateTableEntry(work->rows.paired[markIndex].id, (value | 2) & 0xFF);
                work->rows.paired[markIndex].id = -1;
                work->rows.paired[markIndex].quantity = 1;
                outputCount++;
            }
        }
        for (compactIndex = 0; compactIndex < work->count; compactIndex++) {
            if (work->rows.paired[compactIndex].id != -1) {
                reorder[outputCount] = work->rows.paired[compactIndex].id;
                work->rows.paired[compactIndex].quantity = 0;
                outputCount++;
            }
        }
        for (copyIndex = 0; copyIndex < work->count; copyIndex++) {
            work->rows.paired[copyIndex].id = (s16)reorder[copyIndex];
        }
    }
    if (mode == 2) {
        s16 collectIndex;
        s16 sortedIndex;
        for (collectIndex = 0; collectIndex < work->count; collectIndex++) {
            sortedIds[collectIndex] = work->rows.paired[collectIndex].id;
        }
        qsort(sortedIds, work->count, 4, datItemPriceCompare);
        for (sortedIndex = 0; sortedIndex < work->count; sortedIndex++) {
            work->rows.paired[sortedIndex].id = (s16)sortedIds[sortedIndex];
            work->rows.paired[sortedIndex].quantity = 0;
            if ((clndGetMoonPhase(work->rows.paired[sortedIndex].id) & 0xFF) & 1) {
                work->rows.paired[sortedIndex].quantity = 1;
                value = clndGetMoonPhase(work->rows.paired[sortedIndex].id);
                datSetStateTableEntry(work->rows.paired[sortedIndex].id, (value | 2) & 0xFF);
            }
        }
    }
}

#pragma pop
#pragma opt_common_subs on


/* Case 6 compares the inventory persona with its compendium record.
 * Read the copied record ID before both metadata and compendium lookup. */
// FUN_002E4090
#pragma push
#pragma opt_lifetimes on
s32 yListSlotRefresh(u8 *task) {
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    DatPersonaRecord registered;
    DatPersonaRecord current;
    s16 slotIndex;
    u16 *selectedRecord;
    u8 *work;
    u32 kind;
    work = *(u8 **)(task + 0x38);
    if (*(s8 *)work == 1) {
        return 0;
    }
    *(s32 *)(work + 8) = 0;
    kind = *(u32 *)(work + 4);
    switch (kind) {
    case 0:
        for (slotIndex = 1; slotIndex < 0xC; slotIndex++) {
            datPersonaInitRecord(work + ((slotIndex - 1) * 0x30) + 0x14, (u16)slotIndex);
            *(s32 *)(work + 8) += 1;
        }
        break;
    case 1:
        for (slotIndex = 0; slotIndex < (datPersonaRosterCapacity() & 0xFFFF); slotIndex++) {
            if (datPersonaRosterSlotActive(slotIndex) == 1) {
                memset(work + (*(s32 *)(work + 8) * 0x30) + 0xA4, 0, 0x30);
                memcpy(work + (*(s32 *)(work + 8) * 0x30) + 0xA4, datPersonaRosterSlot(slotIndex), 0x30);
                *(s32 *)(work + 8) += 1;
            }
        }
        break;
    case 2:
        for (slotIndex = 0; slotIndex < 0x100; slotIndex++) {
            if (datPersonaCachedRecord(slotIndex) != 0) {
                memset(work + (*(s32 *)(work + 8) * 0x30) + 0x14, 0, 0x30);
                memcpy(work + (*(s32 *)(work + 8) * 0x30) + 0x14, datPersonaCachedRecord(slotIndex), 0x30);
                *(s32 *)(work + 8) += 1;
            }
        }
        break;
    case 5:
        for (slotIndex = 0; slotIndex < (datPersonaRosterCapacity() & 0xFFFF); slotIndex++) {
            if (datPersonaRosterSlotActive(slotIndex) == 1) {
                selectedRecord = (u16 *)datPersonaGetRecord(1);
                if (selectedRecord != (u16 *)datPersonaRosterSlot(slotIndex)) {
                    memset(work + (*(s32 *)(work + 8) * 0x30) + 0xA4, 0, 0x30);
                    memcpy(work + (*(s32 *)(work + 8) * 0x30) + 0xA4, datPersonaRosterSlot(slotIndex), 0x30);
                    *(s32 *)(work + 8) += 1;
                }
            }
        }
        break;
    case 6:
        for (slotIndex = 0; slotIndex < (datPersonaRosterCapacity() & 0xFFFF); slotIndex++) {
            if (datPersonaRosterSlotActive(slotIndex) == 1) {
                memcpy(&current, datPersonaRosterSlot(slotIndex), 0x30);
                if (*(u8 *)(iGpffffb3d4 + current.id * 0xE + 2) < 0x16) {
                    memcpy(&registered, datPersonaCachedRecord(current.id), 0x30);
                    if (yListRecordsDiffer((u8 *)&current, (u8 *)&registered) == 1) {
                        memset(work + (*(s32 *)(work + 8) * 0x30) + 0xA4, 0, 0x30);
                        memcpy(work + (*(s32 *)(work + 8) * 0x30) + 0xA4, datPersonaRosterSlot(slotIndex), 0x30);
                        *(s32 *)(work + 8) += 1;
                    }
                }
            }
        }
        break;
    case 7:
        for (slotIndex = 1; slotIndex < 0xC0; slotIndex++) {
            datPersonaInitRecord(work + ((slotIndex - 1) * 0x30) + 0x14, (u16)slotIndex);
            *(s32 *)(work + 8) += 1;
        }
        break;
    case 8:
        datPersonaInitAllRecords();
        for (slotIndex = 1; slotIndex < 0xC0; slotIndex++) {
            datPersonaInitRecord(work + ((slotIndex - 1) * 0x30) + 0x14, (u16)slotIndex);
            *(s32 *)(work + 8) += 1;
        }
        break;
    default:
        break;
    }
    *work = 1;
    return 0;
}


#pragma pop
// FUN_002E45E0
void yListSlotDestroy(u8 *task) {
    jtbl_008873EC[0](((KwlnTask *)((u8 *)task))->work);
}

// FUN_002E4610
/* Create a persona-list slot and initialize its availability matrix for roster kinds. */
void yListSlotCreate(s32 kind, s8 list) {
    u8 *work;
    u8 **slot;
    u8 *matrixRow;
    s16 rowIndex;
    s16 columnIndex;

    yListSlotFindFree();
    slot = &D_00882F70[list];
    if (*slot != NULL) {
        yListSlotRelease(list);
    }
    chkmemAllocSiteTag(D_0063FC48, 0x38F);
    work = D_008873F4[0](1, 0x3014, 0x40000);
    *slot = (u8 *)(s32)kwlnTaskCreate((const void *)(D_0063FC58), 0xF, 0, 0, yListSlotRefresh, yListSlotDestroy, (u8 *)(work));
    ((YListPersonaWork *)work)->ready = 0;
    ((YListPersonaWork *)(work))->kind.value = kind;
    ((YListPersonaWork *)(work))->count.value = 0;
    switch (kind) {
    case 1:
    case 0xA:
    case 6:
        for (rowIndex = 0; rowIndex < 0xC; rowIndex++) {
            columnIndex = 0;
            matrixRow = work + rowIndex * 12;
            while (columnIndex < 0xC) {
                ((YListPersonaWork *)matrixRow)->entries.roster.availability[0][columnIndex] = 0;
                columnIndex++;
            }
        }
        break;
    default:
        break;
    }
    if (kind == 0xA) {
        ((YListPersonaWork *)work)->ready = 1;
    }
}
// FUN_002E47B0
/* Return the first unused slot among the fifteen persona-list handles, or minus one. */
s8 yListSlotFindFree(void) {
    s16 listIndex = 0;
    u8 **slots = D_00882F70;

    while (listIndex < 15) {
        if (slots[listIndex] == NULL) {
            return (s8)listIndex;
        }
        listIndex++;
    }
    return -1;
}

// FUN_002E4820
void yListSlotRelease(s8 list) {
    u8 **p = &D_00882F70[list];

    if (*p != NULL) {
        kwlnTaskDestroyWithHierarchy((s32)*p);
        *p = NULL;
    }
}

// FUN_002E4870
u8 *yListSlotWork(s8 list) {
    return ((KwlnTask *)(D_00882F70[list]))->work;
}

// FUN_002E48A0
/* Select a persona record from the full-record or roster representation. */
u8 *yListSlotEntry(s8 list, s16 index) {
    u8 *work = ((KwlnTask *)(D_00882F70[list]))->work;

    switch (((YListPersonaWork *)(work))->kind.unsignedValue) {
    case 0:
    case 2:
    case 7:
    case 8:
        return work + ((index * 3) * 0x10) + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        return work + ((index * 3) * 0x10) + 0xA4;
    default:
        return work + ((index * 3) * 0x10) + 0x14;
    }
}

/* measured 2026-08-08: this reconstruction is a park at object
   348B/window 352B and nd 16.  The scheduling lever is retained: the
   dispatch operations are in retail order at 0x1C..0x28 (lw pointer,
   lw type, addiu literal 6, beq), after moving the named n3=6 assignment
   into the default loop and using the direct switch expression.  The
   remaining thirteen instruction rows are scratch-register colouring only
   ($a3 versus $t0), plus retail's final zero-padding word at 0x15C:
   0x1C lw a3,38(v1) vs lw t0,38(v1); 0x20 lw a1,4(a3) vs lw a1,4(t0);
   0x24 addiu t0,zero,6 vs addiu a3,zero,6; 0x28 beq a1,t0 vs beq a1,a3;
   0x90/0xDC/0x128 addu v1,v1,a3 vs addu v1,v1,t0;
   0x12C addiu a3,v1,14 vs addiu a2,v1,14; 0x130/0x134 lw via a3 vs a2;
   0x138 addiu a3,a3,8 vs addiu a2,a2,8; 0x13C addiu t0,t0,-1 vs
   addiu a3,a3,-1; 0x14C bgtz t0 vs bgtz a3; 0x15C retail-only nop.
   Ruled out declaration order, pointer type, assignment order, integer
   base spelling, counter-first source, operand-order changes, removal of
   the named type local, removal of the early named constant, and the
   direct switch rewrite; all retained nd 19 or worsened the object.
   Committed at nd 16. */
// FUN_002E4960
/* Copy a persona record as six pairs of words; byte cursors address its representation, not fields. */
void yListSlotCopyEntry(u8 *destination, s8 list, s16 index) {
    u8 *work;
    u8 *fullWork;
    u8 *rosterWork;
    s32 defaultChunks;
    u8 *source;
    u8 *defaultSource;
    s32 chunks;
    work = ((KwlnTask *)(D_00882F70[list]))->work;
    switch (((YListPersonaWork *)(work))->kind.value) {
    case 0:
    case 7:
    case 8:
        fullWork = work;
        source = fullWork;
        source = (u8 *)(u32)source;
        source = (u8 *)((s32)index * 0x30) + (u32)source;
        source += 0x14;
        chunks = 6;
        do {
            s32 firstWord = *(s32 *)source;
            s32 secondWord = *(s32 *)(source + 4);
            source += 8;
            chunks--;
            *(s32 *)destination = firstWord;
            *(s32 *)(destination + 4) = secondWord;
            destination += 8;
        } while (chunks > 0);
        break;
    case 1:
    case 10:
    case 5:
    case 6:
        rosterWork = work;
        source = rosterWork;
        source = (u8 *)(u32)source;
        source = (u8 *)((s32)index * 0x30) + (u32)source;
        source += 0xa4;
        chunks = 6;
        do {
            s32 firstWord = *(s32 *)source;
            s32 secondWord = *(s32 *)(source + 4);
            source += 8;
            chunks--;
            *(s32 *)destination = firstWord;
            *(s32 *)(destination + 4) = secondWord;
            destination += 8;
        } while (chunks > 0);
        break;
    default:
        defaultSource = work;
        defaultSource = (u8 *)(u32)defaultSource;
        defaultSource = (u8 *)((s32)index * 0x30) + (u32)defaultSource;
        defaultSource += 0x14;
        defaultChunks = 6;
        do {
            s32 firstWord = *(s32 *)defaultSource;
            s32 secondWord = *(s32 *)(defaultSource + 4);
            defaultSource += 8;
            defaultChunks--;
            *(s32 *)destination = firstWord;
            *(s32 *)(destination + 4) = secondWord;
            destination += 8;
        } while (defaultChunks > 0);
        break;
    }
}





static inline u8 *yListWork(s8 list) {
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    return *(u8 **)(D_00882F70[list] + 0x38);
}

static inline u8 *yListEntryInWork(u8 *work, s16 index) {
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    switch (*(u32 *)(work + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        work += index * 0x30;
        return work + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        work += index * 0x30;
        return work + 0xA4;
    default:
        work += index * 0x30;
        return work + 0x14;
    }
}

/* Build pair or triple availability for list kinds 1, 6 and 10. The mode is
 * retained before arg0 becomes the signed-byte result of each combination.
 * Triple mode also updates the corresponding destination-list matrix. */
// FUN_002E4AC0
#pragma push
#pragma opt_loop_invariants on
void yListBuildAvailability(s32 modeOrResult, s32 selectedIndex) {
    u8 *base;
    u8 *row;
    u8 *flag;
    u8 *destination;
    u8 *mirror;
    s32 kind;
    s16 i;
    s16 j;
    s8 mode;
    s8 selected;

    base = yListWork(0);
    kind = ((YListPersonaWork *)(base))->kind.value;
    switch (kind) {
    case 1:
    case 10:
    case 6:
        i = 0;
        mode = (s8)modeOrResult;
        selected = (s8)selectedIndex;
        for (; i < ((YListPersonaWork *)(yListWork(0)))->count.value; i++) {
            base[i + 0x2E4] = 0;
            j = 0;
            row = base + i * 12;
            for (; j < ((YListPersonaWork *)(yListWork(0)))->count.value; j++) {
                flag = row + j + 0x14;
                *flag = 0;
                if (i != j) {
                    if (mode == 0) {
                        destination = yListEntryInWork(yListWork((s8)(i + 1)), j);
                        modeOrResult = (s8)fclFusePairByte((s32)destination,
                            (s16)((DatPersonaRecord *)yListEntryInWork(yListWork(0), i))->id,
                            (s16)((DatPersonaRecord *)yListEntryInWork(yListWork(0), j))->id);
                    } else if (mode == 1) {
                        if (selected == i || selected == j) {
                            modeOrResult = 0;
                        } else {
                            destination = yListEntryInWork(yListWork((s8)(i + 1)), j);
                            modeOrResult = (s8)fclFuseTripleByte((u16 *)destination,
                                yListEntryInWork(yListWork(0), selected),
                                yListEntryInWork(yListWork(0), i),
                                yListEntryInWork(yListWork(0), j));
                        }
                        /* Match the neighboring accessors' EE word-address view. */
                        mirror = (u8 *)(i * 12 +
                            (u32)((KwlnTask *)(D_00882F70[i + 1]))->work) + j + 0x14;
                        *mirror = 0;
                        if ((s8)modeOrResult != 0) {
                            *mirror = 1;
                            if ((s8)modeOrResult == 2) {
                                *mirror = 2;
                            }
                        }
                    }
                    if ((s8)modeOrResult != 0) {
                        *flag = 1;
                        if ((s8)modeOrResult == 2) {
                            *flag = 2;
                        }
                    }
                }
            }
        }
        break;
    default:
        break;
    }
}
#pragma pop

extern s32 fclFuseSpecialPartner(u8 *, s32 , s32 );

/* Fill the availability matrix and each row's corresponding pair-result list.
 * Complete the destination lookup before reading the two source record IDs. */
// FUN_002E5000
#pragma push
#pragma opt_loop_invariants on
void yListBuildPairFlags(void) {
    u8 *base;
    u8 *row;
    u8 *flag;
    u8 *destination;
    s16 i;
    s16 j;

    base = yListWork(0);
    for (i = 0; i < ((YListPersonaWork *)(yListWork(0)))->count.value; i++) {
        j = 0;
        row = base + i * 12;
        for (; j < ((YListPersonaWork *)(yListWork(0)))->count.value; j++) {
            flag = row + j + 0x14;
            *flag = 0;
            destination = yListEntryInWork(yListWork((s8)(i + 1)), j);
            if (fclFuseSpecialPartner(destination,
                    ((DatPersonaRecord *)(yListEntryInWork(yListWork(0), i)))->id,
                    ((DatPersonaRecord *)(yListEntryInWork(yListWork(0), j)))->id) == 1) {
                *flag = 1;
            }
        }
    }
}
#pragma pop

// FUN_002E5270
/* Compare level, base stats, second stat bonuses, skills and experience of two records. */
s32 yListRecordsDiffer(u8 *left, u8 *right) {
    s16 statIndex;
    s16 bonusIndex;
    s16 skillIndex;

    if (((DatPersonaRecord *)(left))->level != ((DatPersonaRecord *)(right))->level) {
        return 1;
    }
    for (statIndex = 0; statIndex < 5; statIndex++) {
        if (((DatPersonaRecord *)left)->stats[statIndex] != ((DatPersonaRecord *)right)->stats[statIndex]) {
            return 1;
        }
    }
    for (bonusIndex = 0; bonusIndex < 5; bonusIndex++) {
        if ((u8)((DatPersonaRecord *)left)->statBonusB[bonusIndex] != (u8)((DatPersonaRecord *)right)->statBonusB[bonusIndex]) {
            return 1;
        }
    }
    for (skillIndex = 0; skillIndex < 8; skillIndex++) {
        if (((DatPersonaRecord *)left)->skills[skillIndex] != ((DatPersonaRecord *)right)->skills[skillIndex]) {
            return 1;
        }
    }
    return (u32)((DatPersonaRecord *)(left))->exp != (u32)((DatPersonaRecord *)(right))->exp;
}
// FUN_002E53B0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
/* measured: without `opt_loop_invariants on` the switch jump-table base is
   rematerialized in the loop body instead of hoisted to the preheader (nd 30+). */
/* Test whether an allocated list contains the requested persona ID. */
s32 yListSlotContainsId(s8 list, s16 id) {
    u8 **slot = &D_00882F70[list];
    u8 *task;
    u8 *work;
    u8 *record;
    s32 count;
    s32 key;
    s16 rowIndex = 0;

    if (*(u32 *)slot != 0) {
        rowIndex = 0;
        key = (s16)id;
        work = ((KwlnTask *)((u8 *)*(u32 *)slot))->work;
        count = ((YListPersonaWork *)(work))->count.value;
        for (; rowIndex < count; rowIndex++) {
            task = *slot;
            work = ((KwlnTask *)(task))->work;
            switch (((YListPersonaWork *)(work))->kind.unsignedValue) {
            case 0:
            case 2:
            case 7:
            case 8:
                record = work + ((rowIndex * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                record = work + ((rowIndex * 3) * 0x10) + 0xA4;
                break;
            default:
                record = work + ((rowIndex * 3) * 0x10) + 0x14;
                break;
            }
            if (key == ((DatPersonaRecord *)(record))->id) {
                return 1;
            }
        }
    }
    return 0;
}
/* measured: see the annotation above the matching `on` pragma (func_002e53b0). */
#pragma opt_loop_invariants off

// FUN_002E54C0
/* measured: without `opt_loop_invariants on` MWCC rematerializes the switch
   jump-table base (lui/addiu) inside the loop body instead of hoisting it into
   the preheader as retail does, giving nd 30+. */
#pragma opt_loop_invariants on
/* Find the first matching persona ID, returning minus one when absent. */
s16 yListSlotIndexOf(s8 list, s16 id) {
    s16 rowIndex = 0;
    u8 **slot = &D_00882F70[list];
    u8 *task;
    u8 *work;
    u8 *record;
    s32 count;
    s32 key;

    if (*(u32 *)slot != 0) {
        rowIndex = 0;
        key = (s16)id;
        work = ((KwlnTask *)((u8 *)*(u32 *)slot))->work;
        count = ((YListPersonaWork *)(work))->count.value;
        for (; rowIndex < count; rowIndex++) {
            task = *slot;
            work = ((KwlnTask *)(task))->work;
            switch (((YListPersonaWork *)(work))->kind.unsignedValue) {
            case 0:
            case 2:
            case 7:
            case 8:
                record = work + ((rowIndex * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                record = work + ((rowIndex * 3) * 0x10) + 0xA4;
                break;
            default:
                record = work + ((rowIndex * 3) * 0x10) + 0x14;
                break;
            }
            if (key == ((DatPersonaRecord *)(record))->id) {
                return rowIndex;
            }
        }
    }
    return -1;
}
/* measured: see the annotation above the matching `on` pragma (func_002e54c0). */
#pragma opt_loop_invariants off

/* measured: direct C reconstruction. Disabling common-subexpression
   elimination preserves retail's repeated D_00882F70[arg0] address
   materialization; explicit (u16)arg1 preserves ac10's 16-bit argument. */
#pragma opt_common_subs off
// FUN_002E55C0
/* Append a default or roster-derived persona record and increment the list count. */
void yListSlotAppend(s8 list, s32 id, s8 useRoster) {
    u8 **slot;
    u8 *task;

    slot = &D_00882F70[list];
    task = *slot;
    if (task != NULL) {
        if (useRoster == 0) {
            u8 *work;
            u8 *record;
            s16 index;

            work = ((KwlnTask *)(task))->work;
            index = ((YListPersonaWork *)(work))->count.half;
            switch (((YListPersonaWork *)(work))->kind.value) {
            case 0:
            case 2:
            case 7:
            case 8:
                record = work + ((index * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                record = work + ((index * 3) * 0x10) + 0xA4;
                break;
            default:
                record = work + ((index * 3) * 0x10) + 0x14;
                break;
            }
            datPersonaInitRecord(record, id & 0xFFFF);
        } else if ((s16)datPersonaFindRosterSlotById(id) == -1) {
            {
                u8 *work;
                u8 *record;
                s16 index;

                work = ((KwlnTask *)(D_00882F70[list]))->work;
                index = ((YListPersonaWork *)(work))->count.half;
                switch (((YListPersonaWork *)(work))->kind.value) {
                case 0:
                case 2:
                case 7:
                case 8:
                    record = work + ((index * 3) * 0x10) + 0x14;
                    break;
                case 1:
                case 5:
                case 6:
                case 10:
                    record = work + ((index * 3) * 0x10) + 0xA4;
                    break;
                default:
                    record = work + ((index * 3) * 0x10) + 0x14;
                    break;
                }
                datPersonaInitRecord(record, id & 0xFFFF);
            }
            {
                u8 *work;
                u8 *record;
                s16 index;

                work = ((KwlnTask *)(D_00882F70[list]))->work;
                index = ((YListPersonaWork *)(work))->count.half;
                switch (((YListPersonaWork *)(work))->kind.value) {
                case 0:
                case 2:
                case 7:
                case 8:
                    record = work + ((index * 3) * 0x10) + 0x14;
                    break;
                case 1:
                case 5:
                case 6:
                case 10:
                    record = work + ((index * 3) * 0x10) + 0xA4;
                    break;
                default:
                    record = work + ((index * 3) * 0x10) + 0x14;
                    break;
                }
                ((DatPersonaRecord *)(record))->level = 0;
            }
        } else {
            u8 *work;
            u8 *record;
            u16 *rosterRecord;
            s16 index;

            work = ((KwlnTask *)(D_00882F70[list]))->work;
            index = ((YListPersonaWork *)(work))->count.half;
            switch (((YListPersonaWork *)(work))->kind.value) {
            case 0:
            case 2:
            case 7:
            case 8:
                record = work + ((index * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                record = work + ((index * 3) * 0x10) + 0xA4;
                break;
            default:
                record = work + ((index * 3) * 0x10) + 0x14;
                break;
            }
            rosterRecord = (u16 *)datPersonaFindRosterRecordById((u16)id);
            memcpy(record, rosterRecord, 0x30);
        }
        (((YListPersonaWork *)(((KwlnTask *)(*slot))->work))->count.value)++;
    }
}

/* measured: restore common-subexpression elimination after func_002e55c0. */
#pragma opt_common_subs on
// FUN_002E5960
/* Clear the kind-dependent record region and reset cursor, scroll and count. */
void yListSlotClear(s8 list) {
    u8 *work;
    s16 recordIndex;
    s16 rosterIndex;
    s32 kind;

    if (D_00882F70[list] == NULL) {
        return;
    }
    work = ((KwlnTask *)(D_00882F70[list]))->work;
    kind = ((YListPersonaWork *)(work))->kind.value;
    switch (kind) {
    case 0:
    case 7:
    case 8:
        for (recordIndex = 0; recordIndex < 0x100; recordIndex++) {
            memset(work + ((recordIndex * 3) * 0x10) + 0x14, 0, 0x30);
        }
        break;
    case 1:
    case 10:
    case 5:
    case 6:
        for (rosterIndex = 0; rosterIndex < 0xC; rosterIndex++) {
            memset(work + ((rosterIndex * 3) * 0x10) + 0xA4, 0, 0x30);
            ((YListPersonaWork *)work)->entries.roster.available[rosterIndex] = 0;
        }
        break;
    default:
        break;
    }
    ((YListPersonaWork *)(work))->cursor = 0;
    ((YListPersonaWork *)(work))->scroll = 0;
    ((YListPersonaWork *)(work))->count.value = 0;
}

/* Signed level, bound and metadata-offset snapshots recover the retail spill
   lifetimes; separate membership counters preserve the initial and expanded
   searches. slotp is declared after level and read as *(u8 **)(u32)slotp in
   the first membership search. That repeated conversion keeps slotp a local
   at its declared number (docs/matching.md, "Keep a load local alive").
   The expanded scan reuses the first scan's counter i under
   opt_lifetimes, so its split lifetime is numbered after the per-entry
   index, as in func_001b11c0. Together they give retail's saved registers. */
// FUN_002E5AE0
#pragma push
#pragma opt_lifetimes on
extern s32 yListIsExcludedId(u16 , u16 *);
/* Fill eligible persona IDs around the requested level, widening an empty search until it yields more than five. */
void yListSlotFillNearLevel(s8 list, u16 *exclude, s8 requestedLevel)
{
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    u8 *work;
    s16 lowerLevel;
    s32 level;
    u8 **slotp;
    s32 upperLevel;
    s16 i;
    s16 initialRow;
    s16 expandedRow;
    s32 found;
    u16 id;
    u8 *refreshedWork;
    s16 rowIndex;
    u32 clearKind;
    u32 initializeKind;
    u8 *clearDestination;
    u8 *initializeDestination;
    s16 expandedLowerLevel;
    s16 expandedUpperLevel;
    s16 outer;
    s32 lowLimit;
    s32 expandedHighLimit;
    s32 expandedLowLimit;
    slotp = &D_00882F70[list];
    if (*slotp == NULL) {
        return;
    }
    work = *(u8 **)(*slotp + 0x38);
    yListSlotClear(list);
    level = (s8)requestedLevel;
    lowerLevel = (s16)fclSubClamped(level, 10, 1, 0x63, 1);
    upperLevel = (s16)fclAddClamped(level, 1, 0x63, 1, 1);
    i = 0;
    lowLimit = (s16)lowerLevel;
    for (; i < 0xC0; i++) {
        s32 signedIndex = i;
        s32 metadataOffset;
        u8 *metadata;
        u8 kind;
        metadata = iGpffffb3d4;
        metadataOffset = signedIndex * 14;
        metadata += metadataOffset;
        kind = metadata[2];
        if (kind < 2 || kind >= 0x16) {
            continue;
        }
        id = (u16)i;
        if (cmmCommunityIsListable(id) == 0) {
            continue;
        }
        if (cmmCommunityPassesFlagGate(id) == 0) {
            continue;
        }
        if (yListIsExcludedId(id, exclude) != 0) {
            continue;
        }
        if (*(u8 **)(u32)slotp != NULL) {
            for (initialRow = 0; initialRow < *(s32 *)(*(u8 **)(*(u8 **)(u32)slotp + 0x38) + 8); initialRow++) {
                if (signedIndex == *(u16 *)(yListSlotEntry(list, initialRow) + 2)) {
                    found = 1;
                    goto initialSearchDone;
                }
            }
        }
        found = 0;
initialSearchDone:
        if (found != 0) {
            continue;
        }
        if (cmmCommunityHasFlagGate(id) != 0) {
            continue;
        }
        metadata = iGpffffb3d4;
        metadata += metadataOffset;
        if (upperLevel < metadata[3] || lowLimit > metadata[3]) {
            continue;
        }
        rowIndex = *(s16 *)(work + 8);
        refreshedWork = *(u8 **)(*slotp + 0x38);
        clearKind = *(u32 *)(refreshedWork + 4);
        switch (clearKind) {
        case 0:
        case 2:
        case 7:
        case 8:
            clearDestination = refreshedWork + rowIndex * 0x30 + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            clearDestination = refreshedWork + rowIndex * 0x30 + 0xA4;
            break;
        default:
            clearDestination = refreshedWork + rowIndex * 0x30 + 0x14;
            break;
        }
        memset(clearDestination, 0, 0x30);
        rowIndex = *(s16 *)(work + 8);
        refreshedWork = *(u8 **)(*slotp + 0x38);
        initializeKind = *(u32 *)(refreshedWork + 4);
        switch (initializeKind) {
        case 0:
        case 2:
        case 7:
        case 8:
            initializeDestination = refreshedWork + rowIndex * 0x30 + 0x14;
            break;
        case 1:
        case 5:
        case 6:
        case 10:
            initializeDestination = refreshedWork + rowIndex * 0x30 + 0xA4;
            break;
        default:
            initializeDestination = refreshedWork + rowIndex * 0x30 + 0x14;
            break;
        }
        datPersonaInitRecord(initializeDestination, id);
        *(s32 *)(work + 8) = *(s32 *)(work + 8) + 1;
    }
    if (level >= 0x3C && *(s32 *)(work + 8) < 3) {
        yListSlotClear(list);
    }
    if (*(s32 *)(work + 8) != 0) {
        return;
    }
    outer = 0;
    do {
        s32 expansion = outer;
        expandedLowerLevel = (s16)fclSubClamped(level, expansion * 5 + 10, 1, 0x63, 1);
        expandedUpperLevel = (s16)fclAddClamped(level, expansion + 1, 0x63, 1, 1);
        yListSlotClear(list);
        i = 0;
        expandedHighLimit = (s16)expandedUpperLevel;
        expandedLowLimit = (s16)expandedLowerLevel;
        for (; i < 0xC0; i++) {
            s32 signedIndex = i;
            s32 metadataOffset;
            u8 *metadata;
            u8 kind;
            metadata = iGpffffb3d4;
            metadataOffset = signedIndex * 14;
            metadata += metadataOffset;
            kind = metadata[2];
            if (kind < 2 || kind >= 0x16) {
                continue;
            }
            id = (u16)i;
            if (cmmCommunityIsListable(id) == 0) {
                continue;
            }
            if (cmmCommunityPassesFlagGate(id) == 0) {
                continue;
            }
            if (yListIsExcludedId(id, exclude) != 0) {
                continue;
            }
            if (*slotp != NULL) {
                for (expandedRow = 0; expandedRow < *(s32 *)(*(u8 **)(*slotp + 0x38) + 8); expandedRow++) {
                    if (signedIndex == *(u16 *)(yListSlotEntry(list, expandedRow) + 2)) {
                        found = 1;
                        goto expandedSearchDone;
                    }
                }
            }
            found = 0;
expandedSearchDone:
            if (found != 0) {
                continue;
            }
            if (cmmCommunityHasFlagGate(id) != 0) {
                continue;
            }
            metadata = iGpffffb3d4;
            metadata += metadataOffset;
            if (expandedHighLimit < metadata[3] || expandedLowLimit > metadata[3]) {
                continue;
            }
            rowIndex = *(s16 *)(work + 8);
            refreshedWork = *(u8 **)(*slotp + 0x38);
            clearKind = *(u32 *)(refreshedWork + 4);
            switch (clearKind) {
            case 0:
            case 2:
            case 7:
            case 8:
                clearDestination = refreshedWork + rowIndex * 0x30 + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                clearDestination = refreshedWork + rowIndex * 0x30 + 0xA4;
                break;
            default:
                clearDestination = refreshedWork + rowIndex * 0x30 + 0x14;
                break;
            }
            memset(clearDestination, 0, 0x30);
            rowIndex = *(s16 *)(work + 8);
            refreshedWork = *(u8 **)(*slotp + 0x38);
            initializeKind = *(u32 *)(refreshedWork + 4);
            switch (initializeKind) {
            case 0:
            case 2:
            case 7:
            case 8:
                initializeDestination = refreshedWork + rowIndex * 0x30 + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                initializeDestination = refreshedWork + rowIndex * 0x30 + 0xA4;
                break;
            default:
                initializeDestination = refreshedWork + rowIndex * 0x30 + 0x14;
                break;
            }
            datPersonaInitRecord(initializeDestination, id);
            *(s32 *)(work + 8) = *(s32 *)(work + 8) + 1;
        }
        outer++;
    } while (*(s32 *)(work + 8) <= 5);
}
#pragma pop

/* True when `id` is one of the 13 entries of `exclude`. yListSlotFillByLevel uses it
   inline; func_002e5ae0 calls the out-of-line copy. */
static inline s32 yListExcluded(u16 id, u16 *exclude)
{
    s32 j = 0;
    s32 key = id & 0xFFFF;

    while (j < 13) {
        if (exclude[j] == key) {
            return 1;
        }
        j++;
    }
    return 0;
}

// FUN_002E6230
s32 yListIsExcludedId(u16 id, u16 *exclude) {
    return yListExcluded(id, exclude);
}

static inline u8 *yListEntry(s8 list, s16 index)
{
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    u8 *p = *(u8 **)(D_00882F70[list] + 0x38);

    switch (*(u32 *)(p + 4)) {
    case 0:
    case 2:
    case 7:
    case 8:
        return p + ((index * 3) * 0x10) + 0x14;
    case 1:
    case 5:
    case 6:
    case 10:
        return p + ((index * 3) * 0x10) + 0xA4;
    default:
        return p + ((index * 3) * 0x10) + 0x14;
    }
}

static inline s32 yListContains(s8 list, s16 id)
{
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    s16 k;

    if (D_00882F70[list] != NULL) {
        for (k = 0; k < *(s32 *)(*(u8 **)(D_00882F70[list] + 0x38) + 8); k++) {
            if (id == *(u16 *)(yListSlotEntry(list, k) + 2)) {
                return 1;
            }
        }
    }
    return 0;
}

#pragma push
/* measured: MATCH. The exclusion, membership and entry-address steps are
   inline helpers, which gives retail's 1/0 joins and the two duplicated
   jump-table switches. The persona id passed to the u16 callees is `i`
   itself (a separate u16 local changes the saved-register order).
   measured: loop-invariant motion is required (29 words without it). */
#pragma opt_loop_invariants on
// FUN_002E6280
/* Fill eligible arcana-one personas up to level plus three, excluding supplied IDs. */
void yListSlotFillByLevel(s8 list, u16 *exclude, s8 level)
{
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    u8 *data;
    s32 limit;
    s16 i;

    if (D_00882F70[list] == NULL) {
        return;
    }
    data = *(u8 **)(D_00882F70[list] + 0x38);
    yListSlotClear(list);
    limit = (s16)fclAddClamped(level, 3, 99, 1, 1);
    for (i = 0; i < 0xC0; i++) {
        if (iGpffffb3d4[i * 0xE + 2] == 1 && (*(u16 *)&iGpffffb3d4[i * 0xE] & 8) == 0) {
            if (cmmCommunityIsListable((u16)i) != 0 && cmmCommunityPassesFlagGate((u16)i) != 0 && yListExcluded(i, exclude) == 0 &&
                yListContains(list, i) == 0 && cmmCommunityHasFlagGate((u16)i) == 0 &&
                limit >= iGpffffb3d4[i * 0xE + 3]) {
                memset(yListEntry(list, *(s32 *)(data + 8)), 0, 0x30);
                datPersonaInitRecord(yListEntry(list, *(s32 *)(data + 8)), i);
                *(s32 *)(data + 8) += 1;
            }
        }
    }
}
#pragma pop

/* measured: 640B/640B, exact instructions and all 44 jump-table entries.
   Keep each signed index's byte offset across its repeated accessor pair.
   The comparator's O1 scope preserves the retail selector and key lifetimes. */
// FUN_002E6630
#pragma optimization_level 1
/* Compare persona levels weighted by one hundred times their metadata arcana. */
s32 yListCompareByWeightedKeyDesc(const void *left, const void *right) {
    s16 leftIndex = *(const s16 *)left;
    s16 rightIndex = *(const s16 *)right;
    u8 *base = ((KwlnTask *)(D_00882F70[0]))->work;
    u8 *leftRecord;
    u8 *leftIdRecord;
    u8 *rightRecord;
    u8 *rightIdRecord;
    s32 leftOffset;
    s32 rightOffset;
    u8 *metadata;
    u16 leftKey;
    s32 rightKey;
    s32 maskedLeftKey;
    switch (((YListPersonaWork *)(base))->kind.unsignedValue) {
    case 0:
    case 2:
    case 7:
    case 8:
        leftOffset = (leftIndex * 3) * 0x10;
        leftRecord = base + leftOffset + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        leftOffset = (leftIndex * 3) * 0x10;
        leftRecord = base + leftOffset + 0xA4;
        break;
    default:
        leftOffset = (leftIndex * 3) * 0x10;
        leftRecord = base + leftOffset + 0x14;
        break;
    }
    switch (((YListPersonaWork *)(base))->kind.unsignedValue) {
    case 0:
    case 2:
    case 7:
    case 8:
        leftIdRecord = base + leftOffset + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        leftIdRecord = base + leftOffset + 0xA4;
        break;
    default:
        leftIdRecord = base + leftOffset + 0x14;
        break;
    }
    metadata = iGpffffb3d4 + 2;
    leftKey = leftRecord[4] + 100 * metadata[14 * ((DatPersonaRecord *)(leftIdRecord))->id];
    switch (((YListPersonaWork *)(base))->kind.unsignedValue) {
    case 0:
    case 2:
    case 7:
    case 8:
        rightOffset = (rightIndex * 3) * 0x10;
        rightRecord = base + rightOffset + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        rightOffset = (rightIndex * 3) * 0x10;
        rightRecord = base + rightOffset + 0xA4;
        break;
    default:
        rightOffset = (rightIndex * 3) * 0x10;
        rightRecord = base + rightOffset + 0x14;
        break;
    }
    switch (((YListPersonaWork *)(base))->kind.unsignedValue) {
    case 0:
    case 2:
    case 7:
    case 8:
        rightIdRecord = base + rightOffset + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        rightIdRecord = base + rightOffset + 0xA4;
        break;
    default:
        rightIdRecord = base + rightOffset + 0x14;
        break;
    }
    rightKey = (u16)(rightRecord[4] + 100 * metadata[14 * ((DatPersonaRecord *)(rightIdRecord))->id]);
    maskedLeftKey = leftKey & 0xFFFF;
    if (rightKey < maskedLeftKey) {
        return 1;
    }
    return -(maskedLeftKey < rightKey);
}
#pragma optimization_level 2





// FUN_002E68B0
/* measured: without `opt_loop_invariants on` MWCC keeps the loop2 switch
   jump-table base (lui/addiu) inside the dispatch instead of hoisting it
   into the preheader as retail does. */
#pragma opt_loop_invariants on
/* Sort indices by the weighted key, then rebuild records from their cached persona IDs. */
void yListSlotSortWeighted(s8 list) {
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    u8 **slot = &D_00882F70[list];
    u8 *task;
    u8 *work;
    u8 **workPointer;
    u8 *sourceWork;
    s32 count;
    s16 collectIndex;
    s16 readIndex;
    u8 *destination;
    s16 writeIndex;
    s16 sortedIndex;
    s16 sortedIndices[0x100];
    s16 sortedIds[0x100];

    task = *slot;
    if (task == NULL) {
        return;
    }
    workPointer = (u8 **)(task + 0x38);
    work = *(u8 **)(task + 0x38);
    for (collectIndex = 0; collectIndex < *(s32 *)(*(u8 **)(task + 0x38) + 8); collectIndex++) {
        sortedIndices[collectIndex] = collectIndex;
    }
    qsort(sortedIndices, *(u16 *)((u8 *)*workPointer + 8), 2, yListCompareByWeightedKeyDesc);
    readIndex = 0;
    count = *(s32 *)(*(u8 **)((u8 *)*slot + 0x38) + 8);
    if (count > 0) {
        sourceWork = *(u8 **)((u8 *)*(u8 **)((u8 *)D_00882F70 + (u32)(s8)list * 4) + 0x38);
        for (; readIndex < count; readIndex++) {
            u8 *sourceRecord;

            sortedIndex = sortedIndices[readIndex];
            switch (*(u32 *)(sourceWork + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                sourceRecord = sourceWork + ((sortedIndex * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                sourceRecord = sourceWork + ((sortedIndex * 3) * 0x10) + 0xA4;
                break;
            default:
                sourceRecord = sourceWork + ((sortedIndex * 3) * 0x10) + 0x14;
                break;
            }
            sortedIds[readIndex] = *(u16 *)(sourceRecord + 2);
        }
    }
    for (writeIndex = 0; writeIndex < *(s32 *)(*(u8 **)((u8 *)*slot + 0x38) + 8); writeIndex++) {
        destination = work + ((writeIndex * 3) * 0x10) + 0x14;

        memset(destination, 0, 0x30);
        memcpy(destination, datPersonaCachedRecord(sortedIds[writeIndex]), 0x30);
    }
}
/* measured: see the annotation above the matching `on` pragma (func_002e68b0). */
#pragma opt_loop_invariants off

/* measured 2026-08-12: best plain-C comparator body is archived at
   build/D2E6_002e6b20_body.c (object 360B/window 368B, normalized_diff 10;
   differing byte offsets 6,7,10,11,12,13,14,16,18,19). The direct body has
   no calls and its s16 *arg0/s16 *arg1 signature is confirmed. The remaining
   residual is the initial retail load order (lh arg0, lh arg1, then the
   global base) versus MWCCPS2's lh arg0, global base, lh arg1 schedule.
   Retained: s32 vb, s32 va_mask, opt_common_subs off. Ruled out:
   schedule-on, propagation-off, declaration-order, pointer-load,
   ordered-assignment/initializer, const/alias typed-load, optimization_level
   1, dependent-index, and split-global forms. */
/* measured: unmodified m2c candidate from src/generated, installed as a permuter seed; not a verified body. */
// FUN_002E6B20
#pragma schedule on
#pragma optimization_level 1
/* Compare persona records by their level byte, with equal keys returning zero. */
s32 yListCompareByKeyDesc(const void *left, const void *right) {
    const s16 *rightPointer = right;
    const s16 *leftPointer = left;
    s16 leftIndex;
    u8 *base;
    s16 rightIndex;
    u8 *leftRecord;
    u8 *rightRecord;
    s32 rightKey;
    u16 leftKey;
    s32 maskedLeftKey;
    leftIndex = *leftPointer;
    rightIndex = *rightPointer;
    base = ((KwlnTask *)(D_00882F70[0]))->work;
    switch ((u32)((YListPersonaWork *)(base))->kind.value) {
    case 0:
    case 2:
    case 7:
    case 8:
        leftRecord = base + leftIndex * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        leftRecord = base + leftIndex * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        leftRecord = base + leftIndex * 0x30 + 0x14;
        break;
    }
    leftKey = ((DatPersonaRecord *)(leftRecord))->level;
    switch ((u32)((YListPersonaWork *)(base))->kind.value) {
    case 0:
    case 2:
    case 7:
    case 8:
        rightRecord = base + rightIndex * 0x30 + 0x14;
        break;
    case 1:
    case 5:
    case 6:
    case 10:
        rightRecord = base + rightIndex * 0x30 + 0xA4;
        break;
    case 3:
    case 4:
    case 9:
    default:
        rightRecord = base + rightIndex * 0x30 + 0x14;
        break;
    }
    rightKey = ((DatPersonaRecord *)(rightRecord))->level;
    maskedLeftKey = leftKey & 0xFFFF;
    if (rightKey < maskedLeftKey) {
        return 1;
    }
    return -(maskedLeftKey < rightKey);
}
#pragma optimization_level 2
#pragma schedule off



/* func_002e6c90 was closed by porting the MATCHED sibling func_002e68b0: same
   declaration order, same p2 re-index spelling
   `(u8 *)*(u8 **)((u8 *)D_00882F70 + (u32)(s8)arg0 * 4)`, same loop2/loop3
   shapes, with func_002e6b20 as the sort comparator. That fixed the old
   "arg0 not saved to $s2" defect and the missing p2 re-index, taking the
   recorded nd 140 to 52; the remaining loop2 register rotation then cleared.
   measured: `opt_loop_invariants on` is required here — without it MWCC keeps
   the loop-invariant slot address live in the loop body instead of hoisting it
   into the preheader, which is the rotation retail does not have. */
// FUN_002E6C90
/* measured: open opt_loop_invariants scope for func_002e6c90. */
#pragma opt_loop_invariants on
/* Sort indices by level, then rebuild records from their cached persona IDs. */
void yListSlotSortByKey(s8 list) {
    /* Layouts are proven above; typed accesses changed the retail codegen in
       whole-file comparison. Keep the original byte-address form here. */
    u8 **slot = &D_00882F70[list];
    u8 *task;
    u8 *work;
    u8 **workPointer;
    u8 *sourceWork;
    s32 count;
    s16 collectIndex;
    s16 readIndex;
    u8 *destination;
    s16 writeIndex;
    s16 sortedIndex;
    s16 sortedIndices[0x100];
    s16 sortedIds[0x100];

    task = *slot;
    if (task == NULL) {
        return;
    }
    workPointer = (u8 **)(task + 0x38);
    work = *(u8 **)(task + 0x38);
    for (collectIndex = 0; collectIndex < *(s32 *)(*(u8 **)(task + 0x38) + 8); collectIndex++) {
        sortedIndices[collectIndex] = collectIndex;
    }
    qsort(sortedIndices, *(u16 *)((u8 *)*workPointer + 8), 2, yListCompareByKeyDesc);
    readIndex = 0;
    count = *(s32 *)(*(u8 **)((u8 *)*slot + 0x38) + 8);
    if (count > 0) {
        sourceWork = *(u8 **)(*(u8 **)((u8 *)D_00882F70 +
              (u32)(s8)list * 4) + 0x38);
        for (; readIndex < count; readIndex++) {
            u8 *sourceRecord;

            sortedIndex = sortedIndices[readIndex];
            switch (*(u32 *)(sourceWork + 4)) {
            case 0:
            case 2:
            case 7:
            case 8:
                sourceRecord = sourceWork + ((sortedIndex * 3) * 0x10) + 0x14;
                break;
            case 1:
            case 5:
            case 6:
            case 10:
                sourceRecord = sourceWork + ((sortedIndex * 3) * 0x10) + 0xA4;
                break;
            default:
                sourceRecord = sourceWork + ((sortedIndex * 3) * 0x10) + 0x14;
                break;
            }
            sortedIds[readIndex] = *(u16 *)(sourceRecord + 2);
        }
    }
    for (writeIndex = 0; writeIndex < *(s32 *)(*(u8 **)((u8 *)*slot + 0x38) + 8); writeIndex++) {
        destination = work + ((writeIndex * 3) * 0x10) + 0x14;

        memset(destination, 0, 0x30);
        memcpy(destination, datPersonaCachedRecord(sortedIds[writeIndex]), 0x30);
    }
}
/* measured: closing the scope restores the file baseline; leaving
   `opt_loop_invariants on` open inflates the following functions. */
#pragma opt_loop_invariants off
// FUN_002E6F00
/* measured: without `opt_loop_invariants on` MWCC rematerializes the -1 store
   constant at the top of the loop body (nd 6) instead of hoisting it into the
   preheader as retail does (addiu $a1,$zero,-1 before the initial branch). */
#pragma opt_loop_invariants on
/* Allocate forty-eight minus-one indices followed by a zero count. */
u8 *yListAllocIndexTable(void) {
    s16 *indices;
    s16 index;
    s16 value;

    chkmemAllocSiteTag(D_0063FC48, 0x649);
    indices = (s16 *)D_008873F4[0](1, 0x62, 0x40000);
    index = 0;
    value = -1;
    while (index < 0x30) {
        indices[index] = value;
        index++;
    }
    indices[0x30] = 0;
    return (u8 *)indices;
}
/* measured: see the annotation above the matching `on` pragma (func_002e6f00). */
#pragma opt_loop_invariants off
