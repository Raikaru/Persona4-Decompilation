#ifndef BTL_HIT_RESULT_INTERNAL_H
#define BTL_HIT_RESULT_INTERNAL_H

#include "type.h"

/* 0x20-byte hit record. 001f14f0 writes these at action+0xF0 + i*0x20 (the
 * action's hit rows); the controllers in btlAction build the same
 * provider-sized payload. Kept in its own header so TUs that only need the
 * record do not pull in the whole battle unit/action graph. */
typedef struct LargeBattleHitResult {
    s32 hpDelta, spDelta;
    u32 addedStatus, removedStatus;
    u32 field10;
    s32 field14;
    s16 hpTransfer, spTransfer;
    s8 motion;
    u8 field1d;
    u16 flags;
} LargeBattleHitResult;

#endif
