#ifndef BATTLE_APPROACH_ACTION_FIXTURE_H
#define BATTLE_APPROACH_ACTION_FIXTURE_H

#include "type.h"

/* Fixture-only complete action and hit views. The production approach
 * controller retains its own audited partial views; this header does not
 * install either unrelated guarded action-controller recovery. */
/* The producer 001f14f0 writes 0x20-byte results at action+0xf0.
 * The consumer 001a7720 loads both transfer amounts with lh and motion with
 * lb. Field 1d is retained but not written by this producer. The last of
 * 24 slots ends at 0x3ef, before the independent pointer at 0x3f0.
 * Retail trusts the hit-count tables (00243650); it adds no capacity clamp. */
typedef struct BtlActionHitResult {
    s32 hpDelta, spDelta;
    u32 addedStatus, removedStatus;
    u32 field10;
    s32 field14;
    s16 hpTransfer, spTransfer;
    s8 motion;
    u8 field1d;
    u16 flags;
} BtlActionHitResult;

/* Action allocation 001b0930 reserves and clears 0x458 bytes. The 12 target
 * pointers and their count are the embedded target list initialized at +0x38.
 * Only fields consumed here or established by the state/target providers are
 * interpreted; the remaining storage keeps its actual opaque extent. */
typedef struct BtlActionSequence {
    s64 uid;
    u32 serial;
    u16 currentState, pendingState, oldState, pendingTimer, state, field16, flags, flags1a;
    u32 stateTimer;
    u8 field20[8];
    u8 field28;
    u8 field29[7];
    u8 *unit;
    u16 field34, field36;
    u8 *targets[12];
    u16 field68, targetCount, mode;
    s16 skill;
    u16 field70, resolvedSkill;
    u8 field74[0x14];
    u8 *redirectAction;
    u8 *followupAction;
    struct BtlActionSequence *selectedAction;
    u8 field94[0x44];
    u8 resultFlags, hitCount, fieldda, statusFlags;
    u16 effect, targetFlags;
    s32 fielde0, fielde4;
    s32 fielde8;
    s16 fieldec, endDelay;
    BtlActionHitResult hits[24];
    void *field3f0;
    u16 survivalSkill;
    u8 field3f6[0x56];
    struct BtlActionSequence *previous, *next;
    u8 field454[4];
} BtlActionSequence;

#endif
