#ifndef BTL_RESULT_UI_INTERNAL_H
#define BTL_RESULT_UI_INTERNAL_H

#include "type.h"
#include "primitive_queue_internal.h"

/* The title constructor allocates 0x74 bytes. DrawTitle/Draw share the two
 * counters, sprite handles, wipe pointer, and trailing SFL descriptor. */
typedef struct BtlLogoWork {
    u16 flags;
    u8 pad02[2];
    s32 state;
    s32 frame;
    u8 drawNode[0x30];
    u8 *parentWork;
    u8 pad40[4];
    u8 stage;
    u8 pad45;
    u16 animationFrame;
    u16 waveFrame;
    u8 pad4A[2];
    u8 *wipe;
    s32 sprite;
    s32 titleSprite;
    s16 descriptor[14];
} BtlLogoWork;

/* Overlay constructor: 0x54 bytes; Tick walks the roster and holds the
 * persona display and level-up child until their state transitions finish. */
typedef struct BtlResultOverlayWork {
    u16 flags;
    u8 pad02[2];
    s32 state;
    u8 drawNode[0x30];
    s32 rosterCount;
    s32 rosterIndex;
    u8 *results;
    u8 pad44[4];
    u16 waitFrame;
    u8 pad4A[2];
    u8 *personaWindow;
    u8 *levelUpTask;
} BtlResultOverlayWork;

/* Summary constructor allocates 0x4C; its destructor releases the +0x44 child. */
typedef struct BtlResultSummaryWork {
    u16 flags;
    u8 pad02[2];
    s32 state;
    u8 drawNode[0x30];
    s32 partyIndex;     /* 0x38: four friend-persona slots */
    u8 *parentWork;
    u16 waitFrame;
    u8 pad42[2];
    u8 *personaWindow;
    u8 *levelUpTask;
} BtlResultSummaryWork;

/* PrepareAwards clears 0x8D4 bytes. Preview records have an observed 0x88
 * stride; their internal layout belongs to datPersona, not the result UI. */
typedef struct BtlXpAwards {
    u32 flags;
    s32 heroExp;
    s32 rosterExp[12];
    u8 rosterPreviews[12][0x88];
    s16 unk698;
    u16 partyIds[4];
    u8 pad6A2[2];
    s32 partyExp[4];
    u8 partyPreviews[4][0x88];
} BtlXpAwards;

typedef struct BtlXpItem {
    s16 id;
    s16 count;
} BtlXpItem;

/* Award producers/consumers establish the halfword party IDs, three item
 * pairs, divisor, and enemy level used by the level-difference scale table. */
typedef struct BtlXpReward {
    u16 flags;
    u8 pad02[2];
    s32 experience;
    s32 money;
    s32 encounterIndex;
    s16 unk10;
    u16 partyIds[5];
    s32 partyCount;
    s32 divisor;
    BtlXpItem items[3];
    s32 itemCount;
    u8 pad34[4];
    s32 enemyLevel;
} BtlXpReward;

/* Same 0x94C-byte parent allocated by btlShuffleCreate and described in
 * datCalc_inferred_0021a7b0.c. The overlay consumes awards at +0x60 and the
 * archive handle at +0x934, followed by five child-task handles. */
typedef struct BtlResultWork {
    s32 flags;
    s32 phase;
    u8 parameters[0x58];
    BtlXpAwards awards;
    s32 file;
    s32 shuffleTask;
    s32 resultTask;
    s32 titleTask;
    s32 overlayTask;
    s32 summaryTask;
} BtlResultWork;

typedef char BtlResultWorkSizeCheck[sizeof(BtlResultWork) == 0x94C ? 1 : -1];
typedef char BtlLogoWorkSizeCheck[sizeof(BtlLogoWork) == 0x74 ? 1 : -1];
typedef char BtlResultOverlayWorkSizeCheck[sizeof(BtlResultOverlayWork) == 0x54 ? 1 : -1];
typedef char BtlResultSummaryWorkSizeCheck[sizeof(BtlResultSummaryWork) == 0x4C ? 1 : -1];
typedef char BtlXpAwardsSizeCheck[sizeof(BtlXpAwards) == 0x8D4 ? 1 : -1];

#endif
