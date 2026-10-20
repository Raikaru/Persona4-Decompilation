#ifndef BTL_SHUFFLE_TASK_INTERNAL_H
#define BTL_SHUFFLE_TASK_INTERNAL_H

#include "btl_shuffle_state_internal.h"
#include "btl_shuffle_card_internal.h"
#include "primitive_queue_internal.h"

/* Parent allocation is 0x21ABC; two 0x30-byte queue slots precede the
 * embedded draw context at 0x70 and the scene resource storage at 0x1F384. */
typedef struct BtlShuffleQueueSlot {
    PrimQueueNode node;
    u8 pad14[0x1C];
} BtlShuffleQueueSlot;

typedef struct BtlShuffleTaskWork {
    u16 flags, frames;
    s32 messageIndex, phase;
    BtlShuffleQueueSlot queues[2];
    void *parentWork;
    BtlShuffleContext drawing;
    f32 fieldOfView;
    u8 sceneResources[0x2738];
} BtlShuffleTaskWork;

/* The producer writes up to four persona IDs and the draw setup consumes
 * the remaining four words (the 8-byte ID array is not a word cursor). */
typedef struct BtlShuffleSelection {
    s16 personas[4];
    s32 personaCount, cardCount, pattern, difficulty;
} BtlShuffleSelection;

typedef struct BtlShuffleRewardResult {
    s32 result;
    u16 personaId, replacement;
    u16 previous;
    u8 pad0A[2];
} BtlShuffleRewardResult;

typedef struct BtlShuffleSkillPair { u16 first, second; } BtlShuffleSkillPair;

/* Persona-ID-indexed replacement rows selected by the reward's low halfword. */
typedef struct BtlShufflePersonaPair { u16 first, second; } BtlShufflePersonaPair;

/* Candidate table cursor advances by 14; only flags and the level byte
 * participate in selection here. Other table properties remain unknown. */
typedef struct BtlShufflePersonaCandidate {
    u16 flags;
    u8 unk02, level;
    u8 pad04[10];
} BtlShufflePersonaCandidate;

/* Packed 12-byte flag/selector/callback rows at D_0064E7B0. */
typedef struct BtlShuffleRewardRule {
    s32 flag;
    u16 kind, variant;
    s32 (*apply)(s32, s32 *);
} BtlShuffleRewardRule;

#endif
