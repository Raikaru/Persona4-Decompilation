#include "list_item_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"

#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
#include "btl_action_internal.h"
typedef struct BtlPacket BtlPacket;
extern BtlPacket *btlFormationCreateNamedPacket(u32 formation, const char *text, u16 mode);
u32 datCalcRandomBelow(u32 bound);
typedef struct BtlTarget BtlTarget;
extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrames, f32 speed, u16 mode);

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 kind, u32 a, u32 b, u32 c);
static inline u8 *actionTargetPacketBytes(u8 *action, u16 kind, u32 a, u32 b, u32 c)
{
    return (u8 *)btlTargetCreateTargetPacket((u32)action, kind, a, b, c);
}
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
static inline void actionSetDelayBytes(u8 *action, s32 state, s32 delay)
{
    btlActionSetStateWithDelay((BtlAction *)action, (u16)state, (u16)delay);
}
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
static inline u8 *actionRotatePacketBytes(u8 *unit, void *rot, s32 flags)
{
    return (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, (const RwV3d *)rot, (u32)flags);
}
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
static inline u8 *actionRecoveryPacketBytes(BtlUnit *unit)
{
    return (u8 *)btlUnitCreateMotionSettlePacket(unit);
}
extern BtlPacket *btlPacketCreateEffectCounter(s32 unit, s32 message);
static inline void *actionMessagePacketBytes(s32 unit, s32 message)
{
    return btlPacketCreateEffectCounter(unit, message);
}
extern BtlPacket *btlVoiceCreatePacket(BtlAction *action, u16 cue, s32 unitId, s32 a, s32 b);
extern void btlUnitGetAnchorPose(u8 *, u8 *, f32 *, f32 *);
extern f32 btlTargetVectorDistance(const RwV3d *, const RwV3d *);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *, const RwV3d *, f32, u32);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

void btlActionSetState(BtlAction *action, u16 state);
u8 *btlUnitRecordFindByActionUID(u64 arg0, u64 arg1);
static inline s32 func_001a_add_offset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 func_001a_fix_var(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}
void btlSoundBumpStatusCounters(void);

void btlTargetResolveSelectedSkill(u8 *arg0);
void func_001eb3b0(u8 *arg0);
extern void btlEffectCollectTargetUnits(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3, u32 arg4);
void btlEffectSelectNearestEntry(void *arg0, void *arg1);

s32 btlUnitIsMoving(u8 *arg0);

void btlActionFinishPresentation(BtlAction *action);
void btlAICommandPickAiTarget(void *arg0, s32 arg1);
BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern void btlUnitSelectRecordTable(u8 *arg0);
extern void btlTargetClearWork(void *arg0);
extern void btlDamageStart(u8 *arg0, u8 *arg1);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern void func_001eb4a0(u8 *arg0, u8 *arg1, u32 status);
extern s32 btlSoundSelectCureableStatuses(u8 *arg0);
extern s32 btlSoundIsStatusCounterHigh(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *arg0);
extern void btlSoundCancelPlayback(void);
extern s32 btlSoundPickResistVoice(u8 *arg0);
extern void btlSoundStopBank3(void);
extern void func_001f9a50(s32 arg0, s32 arg1);
extern void func_001f9a90(void);
extern void btlEncounterEntryClearMessageFade(s32 arg0);
extern void btlEncounterEntrySetMessageFade(s32 arg0);
extern void btlMessageSetup(u8 *arg0, u8 *arg1);
extern s32 btlMessageIsIdle(s32 arg0);
extern void btlMessageSetPendingValue(u8 *arg0, s32 arg1);
extern void btlMessageSetDone(s32 arg0);
extern void btlMessageSetHidden(s32 arg0);
extern u8 *btlUnitCreateColorPacket(u8 *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern u8 *btlUnitCreateShowPacket(u8 *arg0);
extern u8 *btlUnitCreateHidePacket(u8 *arg0);
extern u16 btlSelectionGetTargetMark(s32 task);
extern u32 btlEffectCollectGenusMask(s32 formation);
extern void btlSelectionResetUnitFlags(s32 arg0);
extern u32 btlSelectionGetFormationEntryAlt(s32 task);
extern u32 btlSelectionGetFormationEntry(s32 task);
extern s32 func_001faf70(u8 *arg0, s32 arg1, s32 arg2);
extern void btlSelectionClearTargetMark(s32 arg0);
extern void func_00203880(s32 arg0, s32 arg1);
extern BtlPacket *btlUnitCreateModelReleasePacket(BtlUnit *unit);
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
u32 func_001deeb0(void *arg0);
void btlAICommandSetUnitAction();
u32 btlAICommandTryReleaseProc();
s32 datCalcDefaultSkillId(u8 *unit);
u32 func_001d8bc0(void *arg0);
void func_001d8be0(s32 formation, u64 *unit);

extern u8 *iGpffffb3b8;
void btlEffectSelectTargetByStatus(u8 *arg0, u8 *arg1);
void btlSelectionMarkTargets(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3);
extern void btlDamageSetActive(s32 task);
void btlUnitRequestLookAtOthers(u8 *arg0);
u8 func_0023e1f0(u8 *unitData);
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *target, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
u8 *btlUnitCreateMotionRequestPacket(u8 *arg0, u16 arg1);
extern void btlTargetResetRecordCounter(u8 *arg0);
extern BtlPacket *btlUnitCreateMoveToUnitPacket(BtlUnit *unit, BtlUnit *target, f32 distance, f32 speed, u32 flags);
extern BtlPacket *btlFormationCreateWaitPacket(u32 source, u32 target, u16 mode);
extern f32 fGpffff811c;
extern u32 datCalcGetBadStatus(s32 arg0);
extern s16 btlSoundCalcStatusHpSpDelta(u8 *arg0);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
extern void btlTargetClearResultBuffer(u8 *arg0);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateHpRatio(u8 *arg0);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
u8 *btlPacketCreateImmediate(void);
extern BtlPacket *btlFormationCreateReturnPacket(u16 arg0);
extern u8 *btlUnitCreateLookAtSidePacket(u8 *unit, s16 value);
extern BtlPacket *btlFormationCreateEventPacket(u32 action);
BtlPacket *btlMainCreateColorSetPacket(s32 arg0);
BtlPacket *btlEffectCreateReleasePacket(u16 mode);
u8 *btlPacketCreateFinishEffect(void);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern s32 datCalcAilmentChance(u8 *unit, s32 element);
u8 *func_001fa720(const void *data);
s32 func_001eb860(void);
extern void btlMessageInstallWindow(s32 task, u8 *arg1);
u8 *func_001fa8f0(void);
extern s32 btlMessageIsActiveAlt2(s32 task);
extern s32 btlMessageGetResultAlt2(s32 task);
u8 *func_001faa60(void);
extern void btlMessageRelease(s32 task);
extern void btlDamageSetSource(u8 *arg0, s32 arg1);
s32 btlActionCanFollowUpAfterEnemiesDown(u8 *arg0);
s64 *btlActionGetQueueFront(void);
s32 btlEffectFindUnitMatchingCallback(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));
s32 btlTargetGetStatusEffectMsgCode(u8 *arg0, u8 *arg1);
s32 datCalcSkillElement(u8 *arg0, u16 arg1);
u8 *func_001fa9c0(void);
s32 btlAICommandNomalStatusCheck(u8 *arg0, s64 arg1);
u32 btlCountUnitRecordsById(u32 arg0);
u8 *btlCutinCreatePacket(u8 *arg0);
extern void btlMessageStartLong(u8 *arg0, u8 *arg1);
u8 *btlUnitCreateRotateTowardUnitPacket(u8 *arg0, u8 *arg1, s32 arg2);
u8 *btlPacketAllocZeroed(s32 arg0, s32 arg1);
u8 *btlEffectCreateFormationPacket(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
extern s32 btlMessageIsActiveAlt(s32 task);
extern s32 btlMessageGetResultAlt(s32 task);
u8 *func_001f99c0(u8 *arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 *btlCutinCreateEndPacket(void);
u8 *btlCutinCreateStartPacket(void);
u8 *btlFormationCreateDefaultPacket(void);
extern void btlMessageResetAlt(s32 task);
extern void btlMessageStartShort(u8 *task, u8 *unit);
extern s32 btlMessageIsActive(s32 task);
extern s32 btlMessageGetResult(s32 task);
extern void btlMessageReset(s32 task);
s16 btlCameraSelectFormationIndex(void);
void func_001eb7f0(void);
s32 btlSideCountNotBad(s32 arg0, s32 arg1);
s32 func_001fabe0(u8 *arg0);
u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
s32 datCalcGetSkillMask(u8 *arg0);
s64 datCalcFindStrongBuff(u8 *arg0);
s32 datCalcIsStatusBlocked(u16 *arg0);
s32 btlSoundRollStatusCure(u8 *arg0);
s32 func_001fac30(void);
s32 btlActionGetCounter420(BtlAction *action);

u8 *btlPacketCreateSpriteTable(u32 arg0, u16 arg1);
s32 datPersonaSelectRosterMemberById(s32 arg0);
extern void btlUnitInitChild(u8 *arg0, u16 arg1);
extern void datPersonaRemoveSelectedRosterMember(void);
extern s32 datGetFlag(s32 arg0);
BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
BtlPacket *btlSoundCreateChannelCuePacket(u16 arg0, u16 arg1, u16 arg2);
extern f32 D_0076144C;
s32 func_001fac80(u8 *arg0);
void func_001fad10(void);



extern void btlActionSkillUpdate(u8 *arg0);
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off









#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_common_subs on
static inline void actionCopySelectedTarget(u8 *action, const u16 *index)
{
    u8 *slot = action + *index * 4;
    *(u8 **)(slot + 0x38) = *(u8 **)(slot + 0x98);
}

static inline u8 *actionSelectionOffset(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}

/* The task helpers explicitly consume their task and return the selected
 * formation entry. Sparse switches preserve retail's separate branch joins;
 * the u16 copy cursor wraps at its stored width. Sequence the count load before
 * reading that cursor so the configured b210 -O2 owner emits all 1528 retail
 * bytes, followed by eight zero alignment bytes. CSE remains at its default. */

#pragma pop
#pragma push
#pragma opt_loop_invariants on
#pragma pop




#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop
#pragma push

#pragma pop
#pragma push
/* The loader and cleanup visit all 0x30 resource slots at +0xD04. */
typedef struct ActionRecoveryResourceView {
    u8 beforeResources[0xD04];
    u32 resources[0x30];
} ActionRecoveryResourceView;

static inline u32 actionRecoveryResourceAt(
    const ActionRecoveryResourceView *snappedBase, s32 signedSlot)
{
    return snappedBase->resources[signedSlot];
}


#pragma pop


/* Recovered action selection. Configured b210 -O2 emits 1092 retail bytes
 * plus 12 zero alignment bytes. The workspace keeps the signed element in
 * actual halfword storage and both twelve-entry target lists at their observed
 * 16-byte alignment. Scalarization is disabled for this storage; propagation
 * is disabled to preserve the unit load before the element's signed-word
 * promotion. The affinity provider retains its canonical s32 input. */
#pragma push
/* Keep the promoted shuffle count and output base at their explicit
 * phase boundaries. The index reference preserves each narrow read. */
#pragma opt_loop_invariants off
static inline u8 *actionReadCandidate(u8 *action, const u16 *index)
{
    return *(u8 **)(action + 0x98 + *index * 4);
}

#pragma opt_scalarize off
#pragma opt_propagation off
#pragma pop

/* The two fields belong to the same battle-state allocation. Keeping their
 * shared view preserves the single state-pointer load used by retail. */
typedef struct ActionState001a4800 {
    u8 pad0[0x1A];
    u16 kind;
    u8 pad1C[0x290 - 0x1C];
    u16 flags;
} ActionState001a4800;

#pragma push
#pragma opt_common_subs off
#pragma pop
#pragma push
#pragma opt_lifetimes on
#pragma opt_dead_assignments off

#pragma pop



#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop





/* measured 001a59a0 2026-09-19: object 1929 against retail 1884 (+45, +2.39%, band 1828-1940, 11 instr headroom), 1715 differing words via probe_variants, 905 fnalign edits (+17 reloc-only) via fnalign --candidate, frame retail -0x330 vs object -0x410.
   From m2c transcription: v2 base 2032 (+148, +7.8%, 1830 words), v3 all-s32 narrowing plus byte-arithmetic fix 1953 (+69, +3.6%, 1714 words), v5 GP single-load fix (iGpffffb3ac/b3bc/(s32)b3cc) 1930 (+46, +2.44%, 1707 words), v6 float GP (fGpffff8128/8358, new symbols) 1929 (+45, +2.39%, 1715 words, final).
   Widths: s64 kept only for temp_16/temp_17 (64-bit ld/sd), all other s64/s128 narrowed to s32 (79 instr win v2->v3); GP mapping saves 23 instrs v3->v5; floats save 1 v5->v6. File idiom: s64 *arg0 (retail daddu), local externs with empty prototypes (like 001a7720), explicit field expansions, (u8 *)arg0 byte arithmetic. New data symbols fGpffff8128/8358 added for retail lwc1 sites. */
/* 2026-10-03: canonical motion/animation calls use a real f32 rate and
   signed-halfword results. Retail has six timing queries and four animation
   creations here; the unfinished controller remains ASM-backed. See
   docs/probe_archive/Large_Battle_animation_contracts_20261003.md. */
/* 2026-10-03 storage repair: preserve action/packet UIDs as doublewords
   and select true 0x20-byte hit records. The old narrowing measurements above
   are historical, not type evidence. See Large_Battle_storage_20261003.md.
   2026-10-08: opt_loop_invariants on lowers fnalign from 837 to 752 edits.
 * 2026-10-09: 752 -> 709: the m2c label loops are while loops.
 * 696: range tests in retail's slti $at form.
 * 666: type sweep.
 * 660: swap sweep.
 * 652: type sweep.
 * 651: type sweep.
 * 646: conversion lever (temp_18:(0, 2)).
 * 642: conversion lever (var_6:(0, 2)).
 * 2026-10-10: 642 -> 614 aligned edits by replacing seven undefined or
 * redundant sign-extension shifts with explicit signed-halfword/byte casts.
 * The local 001d15a0 provider returns s16; measured in battle lane scratch.
 * sdiff struct 413 -> 395: arg0 accessed through a u8 * local; the (u8 *)(s64 *) cast at every use made MWCC CSE and spill field addresses.
 * sdiff struct 395 -> 393: the two close-camera decisions through one inline helper (btlCloseCamera_001a59a0) instead of m2c's switch/goto copies.
 * fnalign 575 -> 545: the 0x13/0x10 selection as a var_2_8 flag test with the 0x13 call first (no goto block_224), as in func_001a7720.
 * fnalign 545 -> 527: the tail state switch (cases 1,3,2 and default both set state 0x20) as in the matched-path sibling 001a7720, with the real btlActionSetState(BtlAction *, u16) prototype (retail daddiu per arm, one shared call).
 * fnalign 527 -> 521: btlCloseCamera reads the unit id before the switch, sends every failing path to one shared result = 0 (default arm, goto fail) and tests the 0x8000 flag first (retail polarity).
 * fnalign 521 -> 493: integer-cast +0x30 unit reads at selected sites (b210 does not CSE the address across calls, as retail).
 * fnalign 493 -> 455: integer-cast field-base reads (no cross-call address CSE).
 * fnalign 455 -> 453: integer-cast field-base reads (second pass).
 * 2026-10-12 measured: fnalign 453 -> 452; the hit-effect flag is a word (retail sw/lw), not s16.
 * 2026-10-12 measured: fnalign 452 -> 405; let the timing APIs narrow their u16 motion argument, without a shared masked temporary.
 * 2026-10-12 measured: fnalign 405 -> 343; captured regalloc requires the source unit before the phase locals. Sound query contracts now match their providers.
 * 2026-10-12 frame audit: fnalign 343 -> 340, frame 0x3C0 -> 0x3B0; voice option is s32 and the target count is already bounded by u16, so no masked spill is needed.
 * 2026-10-12 row lifetime: fnalign 340 -> 335; retain the unbiased target-plus-hit-stride base, restoring retail's separate row spill and +0xF0 payload address (frame 0x3C0).
 * 2026-10-12 UID accessor: fnalign 335 -> 331, frame 0x3C0 -> 0x3B0; inline packet UID reads eliminate the cross-call +0x58 address spill.
 * 2026-10-12 kind accessor: fnalign 331 -> 327, frame 0x3B0 -> 0x3A0; reload the source-unit kind directly rather than spilling its field address.
 * 2026-10-12 effect-unit accessor: fnalign 327 -> 325; inline unit reads in the effect phase replace one spilled-address reload with retail's direct +0x30 load.
 * 2026-10-12 paired-effect unit: fnalign 325 -> 322; the first paired-effect constructor reloads its unit through the existing accessor rather than a spilled field address.
 * 2026-10-12 target layout: fnalign 322 -> 318, frame 0x3A0 -> 0x380; type the target action's effect/flags at 0xDC/0xDE, removing both hoisted field-address spills.
 * 2026-10-12 target unit member: fnalign 318 -> 309, frame 0x380 -> 0x370; recover the target's +0x30 unit field and remove its cross-call address spill.
 * 2026-10-12 selected-action layout: fnalign 309 -> 239, frame 0x370 -> 0x340; the selected action shares the typed +0x30 unit member, eliminating three quadword field-address spills and the redundant accessor.
 * 2026-10-12 animation packet type: fnalign 239 -> 218, frame 0x340 -> retail 0x330; keep the constructor's BtlPacket pointer type, avoiding a coalesced 16-byte byte-pointer spill.
 * 2026-10-12 hit-count consumers: fnalign 218 -> 214; preserve the signed-halfword normalization of the byte-loaded hit count and its conditional snapshot, matching retail's two sign extensions.
 * 2026-10-12 captured spill order: fnalign 214 -> 93, every frameslots offset now agrees at 0x330; declare the surviving packet/result pointers beside their aliases (b210 graph replay preserves their spill choices).
 * 2026-10-12 count/selector joins: fnalign 93 -> 88; keep the repeat-count snapshot signed and the branch-selected effect-table index full-width, removing two non-retail masks.
 * 2026-10-12 row phases: fnalign 88 -> 82; use unsigned byte-address indices inside both loops and recompute the hit-result view after the repeat phase, separate from the retained hitRow snapshot.
 * 2026-10-12 opening scan index: fnalign 82 -> 74; narrow the row index independently from the masked loop bound, preserving retail's separate halfword normalizations.
 * 2026-10-12 opening packet contract: fnalign 74 -> 72; use the matched sibling's BtlPacket *(u32, u16) constructor signature to preserve native halfword argument evaluation.
 * 2026-10-12 paired-target flag: fnalign 72 -> 70; normalize the masked flag before inverting it, matching retail's sltu/xori sequence.
 * 2026-10-12 motion dispatch: fnalign 70 -> 62; recover the two-case switch instead of the empty negated if, preserving retail's two positive tests and default jump.
 * 2026-10-12 camera table order: fnalign 62 -> 56; place the table base before the native halfword index so b210 evaluates the global load before scaling, as in both retail camera checks.
 * 2026-10-12 animation timing dispatch: fnalign 56 -> 54; restore the two-case delay switch, including its explicit default packet-delay path.
 * 2026-10-12 distance-packet address word: fnalign 54 -> 52; read the existing unit-address word at the integer ABI boundary instead of hoisting a pointer-to-integer conversion across the distance branch.
 * 2026-10-12 result-packet address word: fnalign 52 -> 50; likewise read the selected unit as the constructor's native integer address, restoring source/target argument materialization order.
 * 2026-10-12 camera reaching definitions: fnalign 50 -> 23; assign the predicate in each successful case rather than eagerly initializing it, matching both retail constant/load order and the case-1 success jump.
 * 2026-10-12 reaction reaching definitions: fnalign 23 -> 15; retain the truthy byte/random gate values and the ID comparison's shared one until the common decision test, without an extra boolean-result block.
 * 2026-10-12 post-repeat row accessor: fnalign 15 -> 8; reread the halfword index through the byte-row accessor, then retain the caller's typed result snapshot. Retail's lhu/move and every 0x330-frame offset now agree.
 * 2026-10-12 effect-index API: fnalign 8 -> 6; the canonical callee consumes only the skill key's low halfword and remains byte-exact with u16. Its sole C caller now materializes the native halfword argument in retail order.
 * 2026-10-12 camera field origin: fnalign 6 -> 4; pass the first signed-halfword field to the strided reader, preserving the GP load and both retail index-first addu operands. Four branch-target differences remain.
 * 2026-10-12 selected-target join: fnalign 4 -> 3; select into a separate target local before handing it to the packet phase. The coalesced copy retains retail's intermediate branch-only join without emitting an instruction.
 * 2026-10-12 reaction short circuits: fnalign 3 -> 0; stage the real gate values and jump directly to reaction construction on each shortcut. Only the fallback predicate passes through the common boolean test.
 */
#pragma push
/* measured: initial loop-invariant hoisting reduced fnalign from 837 to 752 edits. */
#pragma opt_loop_invariants on
static inline u8 *btlHitResult_001a59a0(u8 *action, const u16 *index)
{
    return action + (u32)*index * 0x20 + 0xF0;
}
static inline s16 btlCameraField_001a59a0(u16 unitId, s16 *firstField)
{
    return *(s16 *)((u8 *)firstField + (u16)unitId * 0xE8);
}
static inline s32 btlCloseCamera_001a59a0(u8 *unit, s32 noPartner)
{
    extern u8 *iGpffffb3bc;
    extern u8 *iGpffffb3cc;
    u8 *ctx = *(u8 **)(unit + 0xA64);
    u16 unitId = *(u16 *)(ctx + 2);
    s32 result;

    switch (*(u8 *)(unit + 0xA2)) {
    case 0:
        {
            s32 state = func_0023e1f0(ctx) & 0xFF;

            if (state == 5) {
                result = 1;
                break;
            }
            if (state != 3) {
                goto fail;
            }
            if (!(*(u16 *)(iGpffffb3bc + 2) & 0x8000) && noPartner != 0) {
                goto fail;
            }
            result = 1;
        }
        break;
    case 1:
        if (btlCameraField_001a59a0(unitId, (s16 *)(iGpffffb3cc + 0x22)) == 1) {
            result = 1;
        } else {
            goto fail;
        }
        break;
    default:
    fail:
        result = 0;
        break;
    }
    return result;
}
static inline s64 btlPacketUID_001a59a0(u8 *packet)
{
    return *(s64 *)(packet + 0x58);
}
static inline u8 btlUnitKind_001a59a0(u8 *unit)
{
    return unit[0xA2];
}
#pragma pop

/* Queue an action's hit sequence: per-target formation, camera, animation,
 * effect and damage packets for every hit row.
 * Retail compiled it under opt_loop_invariants: the hit loop's row count,
 * last-hit index and hit delay are hoisted preheader temporaries.
 * targetPos is the per-target copy that keeps targetIndexS32 a word local;
 * the same-side flag and the primary target are single conditional
 * expressions; the late hit-row addresses go through the row index's
 * address, so CSE recomputes them as retail does. */
/* Effect lead time after the animation; as an inline body it is evaluated
 * before the other call arguments, as in retail. */
static inline s32 btlEffectDelay_001a7720(s32 frames)
{
    s32 delay;
    delay = frames + 6;
    return delay;
}
/* Hit-row address through the row index's address, like btlHitResult_001a59a0. */
static inline u8 *btlHitRow_001a7720(u8 *action, const u16 *index)
{
    return action + (*index << 5);
}
#pragma push
#pragma opt_loop_invariants on
#pragma pop
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on

#pragma pop







/* This view covers every resource slot used by this action (through 0x21). */
typedef struct ActionResourcePrefix {
    u8 beforeResources[0xD04];
    s32 resources[0x22];
} ActionResourcePrefix;
static inline s32 actionResourceAt(ActionResourcePrefix *table, u16 index)
{
    return table->resources[index];
}
/* Queue this action's animation, effect, camera and dependent state changes.
 * Native b210 O2: 1036 executable bytes and four zero alignment bytes;
 * all neighboring functions and allocated data remain unchanged.
 * See docs/probe_archive/Action_animation_sequence_001ac700_20260924.md. */
/* Measured: 1580 executable bytes and four zero tail bytes. The 129.6f
 * scale is a compiler literal at 0x00761440; its load follows vector X.
 * Typed action views and local packet lifetimes preserve the retail frame;
 * loop-invariant optimization retains the shared loop bound. */
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop




typedef struct ActionTargetTable {
    u8 beforeTargets[0xC48];
    u8 *targets[4];
    u16 count;
} ActionTargetTable;
static inline u8 *actionTargetAt(ActionTargetTable *table, u16 index)
{
    return table->targets[index];
}
/* A hit's result payload is shared by its effect and message packets. */
static inline const void *battleHitPayload(const u8 *record)
{
    return record + 0xF0;
}

#pragma push
#pragma opt_loop_invariants on
#pragma pop

