#ifndef P4_LIST_ITEM_INTERNAL_H
#define P4_LIST_ITEM_INTERNAL_H

#include "type.h"

/* Item IDs are signed halfwords; flag-table indices are signed words. */
void func_00106620(s16 item, s32 quantity);
u32 func_00106850(s16 item);
s8 func_00106ac0(s16 item);
s8 func_00106af0(s16 item);
s64 func_00106b80(s16 item);
void func_00110810(s32 item, u8 flags);
u8 clndGetMoonPhase(s32 index);
void func_002bc4b0(f32 depth, s16 item, s32 x, s32 y, s32 color, s32 font, s32 mode);
s32 func_002bdff0(s16 item);
s32 func_002be160(s32 index, s32 required);
s32 func_002be1b0(s16 item);
s32 func_002b3230(const void *left, const void *right);
s32 func_002e2740(s32 row);
void func_002e2a10(s32 filterA, s32 filterB, s8 kind, s8 order);
void func_002e3560(u8 *owner, s32 filterA, s32 filterB, s8 kind, s32 order);

#endif
