#ifndef BTL_SHUFFLE_SEQUENCE_INTERNAL_H
#define BTL_SHUFFLE_SEQUENCE_INTERNAL_H

#include "btl_shuffle_state_internal.h"
#include "btl_shuffle_card_internal.h"

/* Variant payloads start at context + 0x1F1D0. The grid stores sixteen
 * halfword card indices, while the row game records up to seven word indices. */
typedef struct BtlShuffleGridState {
    u16 flags, frames, cursor, heldMask, attempts, attemptLimit;
    u16 cards[16];
    u16 cardCount, pad2E;
    s32 firstCard, secondCard;
} BtlShuffleGridState;

typedef struct BtlShuffleRowState {
    u16 flags, frames, row, pad06;
    s32 stoppedRows;
    s32 cards[7];
    s32 cardCount;
} BtlShuffleRowState;

/* Message-driven descriptor replacement payload at context + 0x1F210. */
typedef struct BtlShuffleReplacementState {
    s32 phase;
    s32 cards[8];
    s32 cardCount;
    u8 pad28[4];
} BtlShuffleReplacementState;

typedef struct BtlShuffleMessageState { s32 phase, result; } BtlShuffleMessageState;

/* Two-word copy unit used while swapping opaque 0xFB0-byte card records. */
typedef struct BtlShuffleCopyPair { s32 first, second; } BtlShuffleCopyPair;

/* Packed input positions really travel in 64-bit argument registers. */
typedef union BtlShuffleScreenPoint {
    s64 packed;
    struct { f32 x, y; } point;
} BtlShuffleScreenPoint;

#endif
