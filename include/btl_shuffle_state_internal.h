#ifndef BTL_SHUFFLE_STATE_INTERNAL_H
#define BTL_SHUFFLE_STATE_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"

/* Thirty card records fill 0x1D6A0..0x1F1CF at a verified 0xE8-byte stride.
 * The sequence runners snapshot the position and the three pose vectors. */
typedef RwV3d BtlShufflePoseVector;
typedef struct BtlShuffleCardPose {
    u8 pad0[0x18];
    BtlShufflePoseVector position;
    u8 pad24[8];
    BtlShufflePoseVector axis, eye, origin;
    u8 pad50[0x98];
} BtlShuffleCardPose;

/* Partial shuffle context: the sequence runners agree on these offsets and
 * the draw consumers use the same task/resource slots. Unknown spans are opaque. */
typedef struct BtlShuffleContext {
    u8 pad0[0x1D6A0];
    BtlShuffleCardPose cards[30];
    u16 sequenceFlags;
    u16 sequenceFrames;
    u16 sequenceChoice;
    u8 pad1F1D6[2];
    union { s32 value; u16 low; } sequenceCount;
    s32 selectedCard;
    u8 pad1F1E0[0x34];
    s32 fadeCards[8];
    s32 fadeCardCount;
    u8 pad1F238[0x10];
    s32 unk1F248;
    u8 pad1F24C[0x44];
    u8 *rosterTask;
    u8 *viewTask;
    u8 *cardTask;
    u8 *trailTask;
    u8 pad1F2A0[0xC];
    s32 spriteResource;
    s32 backgroundResource;
    s32 backdropResource;
    u8 pad1F2B8[0x38];
    u16 elapsed;
    u8 pad1F2F2[2];
    u16 flags;
    u8 pad1F2F6[2];
    u32 phase;
    s32 pattern;
    s32 difficulty;
    s32 cardCount;
    s32 revealCard;
    s32 unk1F30C;
} BtlShuffleContext;

/* The sequence-local cursor starts at context + 0x1F1D0. */
typedef struct BtlShuffleSequence {
    u16 flags;
    u16 frames;
    u16 choice;
    u8 pad6[2];
    s32 count;
    s32 selectedCard;
} BtlShuffleSequence;

/* The roster callback's inline work is cleared as a 0x7C-byte block. */
typedef struct BtlShuffleRosterState {
    u8 pad0[0xC];
    u8 rosterId;
    u8 padD[3];
    s32 mode;
    u8 pad14[4];
    s32 result;
    u8 pad1C[0x60];
} BtlShuffleRosterState;

typedef struct BtlShuffleRosterWork {
    u8 *context;
    u16 flags;
    u8 pad6[0xC];
    u8 rosterId;
    u8 pad13;
    u32 result;
    BtlShuffleRosterState state;
} BtlShuffleRosterWork;

/* Draw-view allocation is 0xB0 bytes (btlShuffleDrawViewCreate). */
typedef struct BtlShuffleAnimation {
    u16 flags;
    u16 frame;
    u16 pulse;
    u16 desaturation;
    u8 opacity[15];
    u8 pad17;
} BtlShuffleAnimation;

typedef struct BtlShuffleFade {
    u16 frame;
    union { u8 color[4]; u16 words[2]; } payload;
} BtlShuffleFade;

typedef struct BtlShuffleGlow {
    u16 frame;
    u8 pad2[2];
    s32 cards[4];
    s32 count;
} BtlShuffleGlow;

typedef struct BtlShuffleDrawViewWork {
    u8 *context;
    BtlShuffleAnimation animation;
    u8 pad1C[2];
    s16 cueFrame;
    u16 frameFlags;
    u16 frameElapsed;
    u16 patternFlags;
    u16 patternElapsed;
    BtlShuffleGlow glow;
    u16 stepFrame;
    u8 stepColor[3];
    u8 pad45;
    BtlShuffleFade fade;
    u16 flags;
    u8 pad4E[2];
    u8 nodes[0x60];
} BtlShuffleDrawViewWork;

/* Card task allocates 0x1B8 bytes. Animation variants share the 0x1A0 slot. */
typedef struct BtlShuffleCardWork {
    u8 *context;
    u16 flags;
    u8 pad6[0x162];
    u16 ringFlags;
    u8 pad16A[0x26];
    u16 detailFrame;
    u16 detailElapsed;
    u16 detailFlags;
    u8 pad196[2];
    s32 detailKind;
    s32 previousDetailKind;
    u8 selection[0x14];
    u16 revealFrame;
    u16 revealFlags;
} BtlShuffleCardWork;

#endif
