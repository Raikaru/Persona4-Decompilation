#ifndef BTL_SHUFFLE_CARD_INTERNAL_H
#define BTL_SHUFFLE_CARD_INTERNAL_H

#include "psc_model_internal.h"

/* Draw initialization steps by 0xFB0; resource selectors reuse PscModel. */
typedef struct BtlShuffleCard {
    PscModel model;
    u8 pad688[0x920];
    s32 packet;
    u16 flags;
    u8 padFAE[2];
} BtlShuffleCard;

/* Eight-byte selector records consumed by btlShuffleCardInit. */
typedef struct BtlShuffleCardSpec {
    s32 kind;
    u16 id;
    u16 index;
} BtlShuffleCardSpec;

#endif
