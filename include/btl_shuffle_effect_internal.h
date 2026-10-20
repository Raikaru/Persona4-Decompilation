#ifndef BTL_SHUFFLE_EFFECT_INTERNAL_H
#define BTL_SHUFFLE_EFFECT_INTERNAL_H

#include "btl_shuffle_state_internal.h"
#include "kwln_task_internal.h"

/* Nine 8-byte slots follow the context pointer and active mask in the 0x50-byte allocation. */
typedef struct BtlShuffleEffectSlot {
    s16 frame;
    u8 pad02[2];
    u8 *effect;
} BtlShuffleEffectSlot;

typedef struct BtlShuffleEffectWork {
    s32 context;
    u16 activeMask;
    u8 pad06[2];
    BtlShuffleEffectSlot slots[9];
} BtlShuffleEffectWork;

#endif
