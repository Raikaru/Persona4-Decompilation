#ifndef P4_LIST_ITEM_INTERNAL_H
#define P4_LIST_ITEM_INTERNAL_H

#include "type.h"

/* Item IDs are signed halfwords; flag-table indices are signed words. */
void datItemSetCount(s16 item, s32 quantity);
u32 datEntryGetKind(s16 item);
s8 datItemAvailableMonth(s16 item);
s8 datItemAvailableDay(s16 item);
s64 datItemBankOffset(s16 item);
void datSetStateTableEntry(s32 item, u8 flags);
u8 clndGetMoonPhase(s32 index);
void fclMesWindowDrawItemCategory(f32 depth, s16 item, s32 x, s32 y, s32 color, s32 font, s32 mode);
s32 fclItemIsDateAvailable(s16 item);
s32 fclMoonPhaseAtLeast(s32 index, s32 required);
s32 datEntryEvaluateFlags(s16 item);
s32 datItemPriceCompare(const void *left, const void *right);
s32 yListValueAt(s32 row);
void yListRebuild(s32 filterA, s32 filterB, s8 kind, s8 order);
void yListRebuildFor(u8 *owner, s32 filterA, s32 filterB, s8 kind, s32 order);

#endif
