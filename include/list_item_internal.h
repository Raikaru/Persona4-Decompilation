#ifndef P4_LIST_ITEM_INTERNAL_H
#define P4_LIST_ITEM_INTERNAL_H

#include "type.h"

/* Item IDs are signed halfwords; flag-table indices are signed words. */
void datItemSetCount(s16 itemId, s32 count);
u32 datEntryGetKind(s16 itemId);
s8 datItemAvailableMonth(s16 itemId);
s8 datItemAvailableDay(s16 itemId);
s64 datItemBankOffset(s16 encodedItemId);
void datSetStateTableEntry(s32 index, u8 flags);
u8 clndGetMoonPhase(s32 daysSinceApr5);
void fclMesWindowDrawItemCategory(f32 inputDepth, s16 item, s32 x, s32 y, s32 inputColor, s32 inputFont, s32 inputMode);
s32 fclItemIsDateAvailable(s16 item);
s32 fclMoonPhaseAtLeast(s32 dateIndex, s32 requiredPhase);
s32 datEntryEvaluateFlags(s16 item);
s32 datItemPriceCompare(const void *left, const void *right);
s32 yListValueAt(s32 index);
void yListRebuild(s32 filterA, s32 filterB, s8 kind, s8 order);
void yListRebuildFor(u8 *task, s32 filterA, s32 filterB, s8 kind, s32 order);

#endif
