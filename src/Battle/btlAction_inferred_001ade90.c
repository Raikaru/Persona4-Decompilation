#include "member_access.h"
/* Measured alias-sensitive fields use MEMBER; typed access-site, local-pointer
 * and applicable array forms are recorded in FullBattle2.culprits.tsv. */
#include "btl_character_camera_internal.h"
#include "btl_effect_internal.h"
#include "list_item_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_skill_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"

#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
#include "btl_action_internal.h"
typedef struct BtlPacket BtlPacket;
extern BtlPacket *btlFormationCreateNamedPacket(u32 resource, const char *path, u16 mode);
u32 datCalcRandomBelow(u32 limit);
typedef struct BtlTarget BtlTarget;
extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode);

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 command, u32 argument, u32 extraArgument, u32 flags);
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
extern BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit);
static inline void *actionMessagePacketBytes(s32 unit, s32 message)
{
    return btlPacketCreateEffectCounter(unit, message);
}
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

void btlActionSetState(BtlAction *action, u16 state);
u8 *btlUnitRecordFindByActionUID(u64, u64);
static inline s32 actionAddOffset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 actionNonzeroOrMinusOne(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}

void btlTargetResolveSelectedSkill(u8 *);
void btlTargetResetCommandRecord(u8 *);


BtlPacket *btlFormationCreateSlotPacket(u16, u16);
s64 btlPacketEnqueue(u8 *, u32);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *btlUnitCreateColorPacket(u8 *, u32, s16, s16, u8, u8);
extern BtlPacket *btlUnitCreateModelReleasePacket(BtlUnit *unit);
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);

extern u8 *iGpffffb3b8;
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
extern f32 fGpffff811c;
extern u32 datCalcGetBadStatus(s32);
extern s16 btlSoundCalcStatusHpSpDelta(u8 *);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
extern void btlTargetClearResultBuffer(u8 *);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateHpRatio(u8 *);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
extern BtlPacket *btlFormationCreateReturnPacket(u16);
extern u8 *btlUnitCreateLookAtSidePacket(u8 *unit, s16 sideFlags);
extern BtlPacket *btlFormationCreateEventPacket(u32 value);
BtlPacket *btlMainCreateColorSetPacket(s32);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
u8 *btlSoundLoadPacketNew(const void *request);
s32 btlTargetCanControlDamagePhase(void);
u8 *btlSoundLoadTaskStart(void);
u8 *btlSoundReleaseTaskStart(void);
extern void btlDamageSetSource(u8 *, s32);
s32 btlActionCanFollowUpAfterEnemiesDown(u8 *);
s64 *btlActionGetQueueFront(void);
s32 btlEffectFindUnitMatchingCallback(u8 *, s32, s32, s32, s32,
                  s32 (*)(u8 *, s64));
u32 btlCountUnitRecordsById(u32);
u8 *btlCutinCreatePacket(u8 *);
u8 *btlUnitCreateRotateTowardUnitPacket(u8 *, u8 *, s32);
u8 *btlPacketAllocZeroed(s32, s32);
u8 *btlEffectCreateFormationPacket(s32, s32, s32, s64, s32);
u8 *func_001f99c0(u8 *, u16, s32, s32, s32);
u8 *btlCutinCreateEndPacket(void);
u8 *btlCutinCreateStartPacket(void);
extern void btlMessageStartShort(u8 *task, u8 *action);
extern s32 btlMessageIsActive(s32 task);
extern s32 btlMessageGetResult(s32 task);
extern void btlMessageReset(s32 task);
s16 btlCameraSelectFormationIndex(void);
s32 btlSideCountNotBad(s32, s32);
u32 datCalcChkBadStatus(s32, u32);

BtlPacket *btlFormationCreatePacket(u32, u32, u32, u16, u32);
BtlPacket *btlSoundCreateChannelCuePacket(u16, u16, u16);
extern f32 D_0076144C;
s32 btlStatusWindowShowSlot3Callback(u8 *);
void btlTaskSlotLinkedSlot3Callback(void);

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001ade90-001afb50 */
/* Access-site layouts preserve the original byte-pointer locals. Raw-site
 * measurements quote the whole-owner verifier's object size and differing-byte
 * count (nd = normalized_diff); each non-table exception was tested separately. */

extern s32 btlActionLinkedUnitIsActive(BtlAction *action);
extern void btlActionSkillUpdate(u8 *);
u8 datCalcGetCharacterTableKind(u8 *unit);
/* firstField is an interior halfword column; retain the 0xE8 row-to-row stride. */
static inline s16 btlCameraField_001a59a0(u16 unitId, s16 *firstField)
{
    return ((BtlCharacterCameraField *)firstField)[(u16)unitId].value;
}
/* Determine close-camera eligibility from unit class and the class-specific camera table. */
static inline s32 btlCloseCamera_001a59a0(u8 *unit, s32 noPartner)
{
    extern BtlSkillFlags *iGpffffb3bc;
    extern u8 *iGpffffb3cc;
    u8 *ctx = *(u8 * *)&((BtlUnit *)unit)->datUnit;
    u16 unitId = ((DatUnit *)ctx)->id;
    s32 result;

    switch (((BtlUnit *)unit)->genus) {
    case 0:
        {
            s32 state = datCalcGetCharacterTableKind(ctx) & 0xFF;

            if (state == 5) {
                result = 1;
                break;
            }
            if (state != 3) {
                goto fail;
            }
            if (!(iGpffffb3bc[0].flags & 0x8000) && noPartner != 0) {
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
/* Ten-byte request copied by btlCutinCreatePacket; case 0 reads the three
 * resource IDs and the count. Keep the caller's original byte-array storage. */
typedef struct BtlCutinRequest {
    u16 kind;
    s16 ids[3];
    s16 count;
} BtlCutinRequest;

typedef struct ActionTargetTable {
    u8 beforeTargets[0xC48];
    u8 *targets[4];
    u16 count;
} ActionTargetTable;
static inline u8 *actionTargetAt(ActionTargetTable *table, u16 index)
{
    return table->targets[index];
}
static inline const void *battleHitPayload(const u8 *record)
{
    return &((const BtlAction *)record)->targetBlock.hitRows[0];
}
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: close loop-invariant probe for 001A0140. */
#pragma push
#pragma pop
/* measured: opt_propagation off plus one named local per address term. mwcc
   keeps source operand order for `named + named` (addu off,base / addu idx,sum
   as retail) but commutes an inline product on the left (`a * k + b` emits
   addu b,a*k); the table base must be copied first so its lw leads the block. */
/* measured: restore propagation for the rest of the unit. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
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
/* Select eligible targets, preserving the reference action when required,
 * then queue voice, cut-in and dependent formation packets. Both local
 * target lists hold twelve entries; single-target selection requires
 * a nonempty eligible set. */
#pragma pop
#pragma push
/* measured: b210 -O2 with this scoped setting emits 1148/1152 exact bytes.
 * The ushort counter wrap and offset-first helper preserve retail's operation
 * order. All 39 code relocations and the 52-byte switch table were resolved. */
#pragma pop
#pragma push
#pragma pop
/* Measured: 656/656 bytes and 15 resolved relocations match retail.
 * Preserve unit/UID reloads across queue callbacks and the ordered distance test. */
#pragma push
#pragma pop
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
#pragma pop
#pragma push
/* measured: loop-invariant hoisting is required for retail's hit-loop preheader (506 -> 33 edits when introduced). */
#pragma pop
#pragma push
#pragma pop
/* Measured: 644/656 bytes, 22 resolved relocations and 12 zero tail bytes.
 * Packet submissions retain callback-visible unit, UID and global reloads. */
#pragma push
#pragma pop
// FUN_001ADE90
void btlActionBadDamageInit(void)
{
}

/* Queue the status-damage result and dependent display, animation and sound.
 * Native b210 O2: all 1312 bytes and every relocation match retail.
 * The result is a complete 32-byte object; the ID snapshot follows the
 * status query. See docs/probe_archive/Action_status_response_001adea0_20260924.md. */
// FUN_001ADEA0
void btlActionBadDamageUpdate(u8 *action)
{
    /* Historical whole-layout trial: 1340B; remaining exceptions are measured per access below. */
    u32 datCalcGetBadStatus(s32 unit);
    u8 *unit;
    s64 packetIdentity;
    u32 statusKind;
    u32 badStatus;
    struct {
        s32 hpDelta;
        s32 spDelta;
        u8 otherResults[22];
        u16 flags;
    } result;
    s32 delta;
    u8 *resultPacket;
    u8 *healthPacket;
    u8 *displayPacket;
    u8 *gaugePacket;
    u8 *animationPacket;
    u8 *soundPacket;

    if (btlCountUnitRecordsById(0x700) == 0 && btlCountUnitRecordsById(0x506) == 0 && btlCountUnitRecordsById(0x507) == 0) {
        unit = *(u8* *)&((BtlAction *)action)->unit;
        badStatus = datCalcGetBadStatus(*(s32 *)&((BtlUnit *)unit)->datUnit);
        packetIdentity = *(s64 *)action;
        statusKind = badStatus & 0xFFFFF;
        switch (statusKind) {
        case 0x20:
            {
                btlTargetClearResultBuffer((u8 *)&result);
                result.flags = result.flags | 0x100;
                delta = (s16)btlSoundCalcStatusHpSpDelta(action);
                result.hpDelta = delta;
                if (delta < 0) {
                    resultPacket = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                    *(s16 *)&((BtlPacket *)resultPacket)->delay = 12;
                    btlPacketEnqueue(resultPacket, 1);
                    healthPacket = btlPacketCreateHpRatio(unit);
                    *(healthPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)healthPacket)->dependencyUID = *(s64 *)&((BtlPacket *)resultPacket)->uid;
                    btlPacketEnqueue(healthPacket, 1);
                    displayPacket = btlPacketCreateHitDisplay((s32)unit, (s32)unit, -1, 0, 0, 0, 1, &result, 0);
                    *(displayPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)displayPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 1324B, nd 925. */;
                    *(displayPacket + 71) = *(displayPacket + 71) & 0xDF;
                    btlPacketEnqueue(displayPacket, 3);
                    gaugePacket = btlPacketCreateUnitCounter((s32)unit, 0, 0);
                    *(gaugePacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)gaugePacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 1324B, nd 925. */;
                    *(gaugePacket + 71) = *(gaugePacket + 71) & 0xDF;
                    btlPacketEnqueue(gaugePacket, 3);
                    animationPacket = (u8 *)btlUnitCreateAnimPacket(MEMBER(BtlUnit *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 1324B, nd 927. */, -2, 0, 1.0f, 0);
                    *(animationPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)animationPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 1324B, nd 923. */;
                    *(animationPacket + 32) = 10;
                    *(s16 *)&((BtlPacketCondition *)animationPacket)[2].value.id = 769;
                    *(s64 *)&((BtlPacket *)animationPacket)->actionUID = packetIdentity;
                    btlPacketEnqueue(animationPacket, 0);
                    soundPacket = (u8 *)btlSoundCreateChannelCuePacket(10, 2, 24);
                    *(soundPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)soundPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 1324B, nd 924. */;
                    btlPacketEnqueue(soundPacket, 1);
                }
                {
                    u16 actionKind = ((BtlAction *)action)->unk_6c;
                    u16 nextState;
                    switch (actionKind) {
                    case 1:
                    case 3:
                    case 2:
                        nextState = 32;
                        break;
                    default:
                        nextState = 32;
                        break;
                    }
                    btlActionSetState((BtlAction *)action, nextState);
                }
                return;
            }
            break;
        case 0x40:
            {
                btlTargetClearResultBuffer((u8 *)&result);
                result.flags = result.flags | 0x100;
                delta = (s16)btlSoundCalcStatusHpSpDelta(action);
                result.spDelta = delta;
                if (delta < 0) {
                    resultPacket = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                    *(s16 *)&((BtlPacket *)resultPacket)->delay = 12;
                    btlPacketEnqueue(resultPacket, 1);
                    healthPacket = btlPacketCreateHpRatio(unit);
                    *(healthPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)healthPacket)->dependencyUID = *(s64 *)&((BtlPacket *)resultPacket)->uid;
                    btlPacketEnqueue(healthPacket, 1);
                    displayPacket = btlPacketCreateHitDisplay((s32)unit, (s32)unit, -1, 0, 0, 0, 1, &result, 0);
                    *(displayPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)displayPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 1324B, nd 928. */;
                    *(displayPacket + 71) = *(displayPacket + 71) & 0xDF;
                    btlPacketEnqueue(displayPacket, 3);
                    gaugePacket = btlPacketCreateUnitCounter((s32)unit, 1, 0);
                    *(gaugePacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)gaugePacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 1324B, nd 928. */;
                    *(gaugePacket + 71) = *(gaugePacket + 71) & 0xDF;
                    btlPacketEnqueue(gaugePacket, 3);
                    animationPacket = (u8 *)btlUnitCreateAnimPacket(MEMBER(BtlUnit *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 1324B, nd 927. */, -2, 0, 1.0f, 0);
                    *(animationPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)animationPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 1324B, nd 926. */;
                    *(animationPacket + 32) = 10;
                    *(s16 *)&((BtlPacketCondition *)animationPacket)[2].value.id = 769;
                    *(s64 *)&((BtlPacket *)animationPacket)->actionUID = packetIdentity;
                    btlPacketEnqueue(animationPacket, 0);
                    soundPacket = (u8 *)btlSoundCreateChannelCuePacket(10, 2, 24);
                    *(soundPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)soundPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 1324B, nd 927. */;
                    btlPacketEnqueue(soundPacket, 1);
                }
                {
                    u16 actionKind = ((BtlAction *)action)->unk_6c;
                    u16 nextState;
                    switch (actionKind) {
                    case 1:
                    case 3:
                    case 2:
                        nextState = 32;
                        break;
                    default:
                        nextState = 32;
                        break;
                    }
                    btlActionSetState((BtlAction *)action, nextState);
                }
                return;
            }
            break;
        default:
            {
                u16 actionKind = ((BtlAction *)action)->unk_6c;
                u16 nextState;
                switch (actionKind) {
                case 1:
                case 3:
                case 2:
                    nextState = 32;
                    break;
                default:
                    nextState = 32;
                    break;
                }
                btlActionSetState((BtlAction *)action, nextState);
            }
            break;
        }
    }
}

// FUN_001AE3C0
/* Return the action completion counter used by the callback-wait packet. */
s32 btlActionGetCounter428(BtlAction *action)
{
    return ((BtlAction *)(u8 *)action)->unk_428;
}

/* Build the return-to-action packet sequence and select an available target.
 * Native b210 O2: 1072/1072 bytes, every relocation resolved; all other
 * owner functions and data preserved. See the 001ae3d0 recovery note. */
// FUN_001AE3D0
void btlActionRoundupMesInit(u8 *action)
{
    /* Historical whole-layout trial: 1076B; remaining exceptions are measured per access below. */
    u8 *currentAction;
    u8 *target;
    u32 flags;
    u8 *targetAction;
    u8 *packet;
    /* The cut-in constructor copies ten bytes. Mode 1 uses only the
     * leading mode and unit ID; the remaining representation is opaque. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    u32 selectedAction;
    s32 changeFormation;
    u32 enemyCount;
    s16 previousFormation;
    u16 targetIndex;

    currentAction = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (currentAction != NULL) {
        if (btlActionLinkedUnitIsActive((BtlAction *)currentAction) != 0) {
            packet = (u8 *)btlUnitCreateModelReleasePacket(((BtlUnit *)*(u8* *)&((BtlAction *)currentAction)->unit)->childUnit);
            *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)currentAction;
            btlPacketEnqueue(packet, 1);
        }
        currentAction = *(u8* *)&((BtlAction *)currentAction)->next;
    }
    target = NULL;
    if (((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->genus == 0) {
        selectedAction = (u32)action;
    } else {
        selectedAction = (u32)((BtlAction *)action)->targets[0];
    }
    if (selectedAction != 0) {
        u16 i;
        u8 *tableBase;
        s32 count;
        u32 current;
        i = 0;
        tableBase = iGpffffb3ac;
        count = ((BtlBattleState *)tableBase)->partyActionCount;
        while ((s32)i < count) {
            current = *(u32 *)&((BtlBattleState *)tableBase)->partyActions[(u32)i];
            if (current == selectedAction) {
                target = (u8 *)selectedAction;
                break;
            }
            i++;
        }
    }
    if (target == NULL) {
        target = actionTargetAt((ActionTargetTable *)iGpffffb3ac, (datCalcRandomBelow(((BtlBattleState *)iGpffffb3ac)->partyActionCount) & 0xFFFF));
    }
    cutin.mode = 1;
    cutin.unitId = ((BtlUnit *)*(u8* *)&((BtlAction *)target)->unit)->charId;
    packet = btlSoundLoadPacketNew(&cutin);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    if (((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 1076B, nd 696. */)->genus != 0) {
        changeFormation = 0;
    } else if ((((BtlBattleState *)iGpffffb3ac)->unkA70 != -1) &&
               (enemyCount = btlSideCountNotBad(2, 0x80000) & 0xFFFF,
                (u32)(((BtlBattleState *)iGpffffb3ac)->unkA72 >> 1) >= enemyCount) &&
               (previousFormation = ((BtlBattleState *)iGpffffb3ac)->unkA70,
                previousFormation != (s16)btlCameraSelectFormationIndex())) {
        changeFormation = 1;
    } else {
        changeFormation = 0;
    }
    if (changeFormation != 0) {
        packet = (u8 *)btlFormationCreateReturnPacket(1);
        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
    }
    packet = (u8 *)btlUnitCreateAnimPacket(((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit, 0, 0, 1.0f, 1);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    targetIndex = 0;
    while ((s32)targetIndex < ((BtlBattleState *)iGpffffb3ac)->partyActionCount) {
        targetAction = ((BtlBattleState *)iGpffffb3ac)->partyActions[(u32)targetIndex];
        packet = (u8 *)btlUnitCreateAnimPacket(((BtlAction *)targetAction)->unit, 0, 0, 1.0f, 1);
        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
        targetIndex++;
    }
    packet = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = btlUnitCreateLookAtSidePacket(0, 3);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    packet = (u8 *)btlUnitCreateLookAtDeactivatePacket(NULL, 3);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    packet = (u8 *)btlFormationCreateEventPacket((u32)action);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = (u8 *)btlMainCreateColorSetPacket(0);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 7);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    flags = ((BtlBattleState *)iGpffffb3ac)->flags;
    flags = flags & 0xFFBFFFFF;
    ((BtlBattleState *)iGpffffb3ac)->flags = flags;
    ((BtlBattleState *)iGpffffb3ac)->actionEndFlags = 0;
    if (btlTargetCanControlDamagePhase() == 1) {
        flags = ((BtlBattleState *)iGpffffb3ac)->flags;
        flags = flags & ~0x2000;
        ((BtlBattleState *)iGpffffb3ac)->flags = flags;
        btlDamageSetSource(*(u8* *)&((BtlBattleState *)iGpffffb3ac)->uiTask, 0);
    }
    *(u8* *)&((BtlAction *)action)->unk_41c = target;
    ((BtlAction *)action)->unk_420 = 0;
    ((BtlAction *)action)->unk_424 = 0;
    ((BtlAction *)action)->unk_428 = 0;
    *(u16 *)&((BtlAction *)action)->unk_42c = 12;
}

// FUN_001AE800
/* Wait for cut-in and voice packets, present the follow-up prompt, then queue the chosen continuation. */
void btlActionRoundupMesUpdate(u8 *action)
{
    /* Historical whole-layout trial: 1092B; remaining exceptions are measured per access below. */
    u8 *gp2;
    u8 *packet1;
    u8 *packet2;
    u8 *packet3;
    u8 *packet4;
    u16 i;
    u32 loopIndex;
    u8 frame[0x10];

    if (((BtlAction *)action)->unk_424 == 0) {
        if (btlCountUnitRecordsById(0xC00) != 0) {
            return;
        }
        if (btlCountUnitRecordsById(0xC04) != 0) {
            return;
        }
        *(s16 *)frame = 0;
        i = 0;
        gp2 = D_0076449C;
        while ((s32)(loopIndex = i) < ((BtlBattleState *)gp2)->partyActionCount) {
            packet1 = ((BtlBattleState *)gp2)->partyActions[(u32)i];
            *(u16 *)&((BtlCutinRequest *)frame)->ids[(u32)i] =
                ((BtlUnit *)*(u8* *)&((BtlAction *)packet1)->unit)->charId;
            i++;
        }
        *(u16 *)&((BtlCutinRequest *)frame)->count = ((BtlBattleState *)gp2)->partyActionCount;
        packet1 = btlCutinCreatePacket(frame);
        btlPacketEnqueue(packet1, 1);
        packet2 = btlSoundLoadTaskStart();
        *(s16 *)&((BtlPacket *)packet2)->delay = *(s16 *)&((BtlAction *)action)->unk_42c;
        btlPacketEnqueue(packet2, 1);
        packet3 = btlPacketAllocZeroed((s32)btlActionGetCounter428, (s32)action);
        *(s16 *)&((BtlPacket *)packet3)->delay = MEMBER(s16, action, BtlAction, unk_42c) /* measured: BtlAction.unk_42c typing gives 1064B, nd 742. */;
        btlPacketEnqueue(packet3, 1);
        packet4 = btlEffectCreateFormationPacket(
            *(s32 *)&((BtlBattleState *)D_0076449C)->formations[34],
            *(s32 *)&((BtlAction *)action)->unit, 0,
            *(s64 *)&((BtlPacket *)packet3)->uid, 0x8000);
        *(s16 *)&((BtlPacket *)packet4)->delay = MEMBER(s16, action, BtlAction, unk_42c) /* measured: BtlAction.unk_42c typing gives 1064B, nd 741. */;
        btlPacketEnqueue(packet4, 2);
        MEMBER(s32, action, BtlAction, unk_424) /* measured: BtlAction.unk_424 typing gives 1064B, nd 745. */ = 1;
    }

    if (((BtlAction *)action)->unk_420 == 0) {
        if (*(s16 *)&((BtlAction *)action)->unk_42c <= 0) {
            btlMessageStartShort(*(u8* *)&((BtlBattleState *)D_0076449C)->uiTask,
                          *(u8* *)&((BtlAction *)action)->unk_41c);
            MEMBER(s32, action, BtlAction, unk_420) /* measured: BtlAction.unk_420 typing gives 1056B, nd 539. */ = 1;
        } else {
            MEMBER(s16, action, BtlAction, unk_42c) /* measured: BtlAction.unk_42c typing gives 1056B, nd 517. */ = *(s16 *)&((BtlAction *)action)->unk_42c - 1;
        }
    }

    if (btlUnitRecordFindByActionUID(*(u64 *)action,
                      0x3FFFFFFFFFFFFFFFULL) != 0) {
        return;
    }

    if (((BtlAction *)action)->unk_428 == 0) {
        if (btlMessageIsActive(((BtlBattleState *)D_0076449C)->uiTask) == 0) {
            return;
        }
        if (btlMessageGetResult(((BtlBattleState *)D_0076449C)->uiTask) == 0) {
            packet1 = btlTargetCreateActionPacket(action, 2);
            ((BtlPacket *)packet1)->actionUID = *(u64 *)action;
            btlPacketEnqueue(packet1, 1);
            ((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->unk_434 =
                ((BtlAction *)action)->unk_41c;
            ((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->unk_16 = 0x1F;
            btlActionActiveListPush(*(s32 *)&((BtlBattleState *)D_0076449C)->selectedAction);
            packet2 = (u8 *)btlActionGetQueueFront();
            if ((((BtlUnit *)*(u8* *)&((BtlAction *)packet2)->unit)->genus == 0) &&
                (((BtlAction *)packet2)->unk_28 != 0)) {
                ((BtlAction *)packet2)->flags |= 0x8000;
            }
            btlPacketEnqueue(
                func_001f99c0(MEMBER(u8 *, action, BtlAction, unk_41c) /* measured: BtlAction.unk_41c typing gives 1056B, nd 386. */, 6, 1, 0, 0), 1);
        } else {
            btlPacketEnqueue(
                func_001f99c0(*(u8* *)&((BtlAction *)action)->unk_41c, 6, 0, 0, 0), 1);
            packet1 = btlCutinCreateStartPacket();
            ((BtlPacket *)packet1)->actionUID = *(u64 *)action;
            btlPacketEnqueue(packet1, 1);
        }

        packet1 = btlSoundReleaseTaskStart();
        ((BtlPacket *)packet1)->actionUID = *(u64 *)action;
        btlPacketEnqueue(packet1, 1);
        packet2 = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 1);
        ((BtlPacket *)packet2)->actionUID = *(u64 *)action;
        btlPacketEnqueue(packet2, 1);
        ((BtlAction *)action)->flags &= 0xFFF7;
        if (btlTargetCanControlDamagePhase() == 1) {
            *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x2000;
            btlDamageSetSource(*(u8* *)&((BtlBattleState *)D_0076449C)->uiTask, 1);
        }
        MEMBER(s32, action, BtlAction, unk_428) /* measured: BtlAction.unk_428 typing gives 1056B, nd 450. */ = 1;
        ((u16 *)&((BtlAction *)action)->unk_42c)[1] = 6;
        return;
    }

    if (((u16 *)&((BtlAction *)action)->unk_42c)[1] == 0) {
        btlMessageReset(((BtlBattleState *)D_0076449C)->uiTask);
        *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x400000;
        ((BtlBattleState *)D_0076449C)->actionEndFlags |= 7;
        btlActionSetState((BtlAction *)action, 0x20);
        return;
    }
    *(u16 *)&((BtlAction *)(action))->roundupTimers[1] /* measured: u16.unk_42c typing gives 1060B, nd 98. */ = ((u16 *)&((BtlAction *)action)->unk_42c)[1] - 1;
}

// FUN_001AEC20
/* Copy eligible targets and choose the roundup skill from the number of reacting targets. */
void btlActionRoundupInit(u8 *action)
{
    /* Historical whole-layout trial: 328B; remaining exceptions are measured per access below. */
    s32 activeCountMasked;
    s32 unitIndex;
    s32 activeCount;
    s32 slotIndex;
    s32 unitCount;
    s32 slotCount;
    u8 *slot;

    btlTargetResetCommandRecord(action + 0x38);
    btlSkillClassifyTargets(action, action + 0x98, 0x100, 0);
    unitIndex = 0;
    goto loop_2_test;
loop_2_body:
    slot = action + ((u16)unitIndex * 4);
    *(s32 *)&((BtlAction *)slot)->targets[0] = *(s32 *)&((BtlAction *)slot)->parameters.candidates[0];
    unitIndex = (unitIndex + 1) & 0xFFFF;
loop_2_test:
    unitCount = ((BtlAction *)action)->unk_d0;
    if ((unitIndex & 0xFFFF) < unitCount) {
        goto loop_2_body;
    }
    ((BtlAction *)action)->unk_6a = unitCount;
    *(s16 *)&((BtlAction *)action)->unk_6c = 2;
    *(s16 *)&((BtlAction *)action)->unk_6e = 0x100;
    btlTargetResolveSelectedSkill(action);
    activeCount = 0;
    slotIndex = 0;
    slotCount = MEMBER(u16, action, BtlAction, unk_6a) /* measured: BtlAction.unk_6a typing gives 316B, nd 239. */;
    goto loop_7_test;
loop_7_body:
    if (((BtlAction *)((BtlAction *)action)->targets[(u16)slotIndex])->targetBlock.reactionFlag != 0) {
        activeCount = (activeCount + 1) & 0xFFFF;
    }
    slotIndex = (slotIndex + 1) & 0xFFFF;
loop_7_test:
    if ((slotIndex & 0xFFFF) < slotCount) {
        goto loop_7_body;
    }
    activeCountMasked = activeCount & 0xFFFF;
    if (slotCount == activeCountMasked) {
        MEMBER(s16, action, BtlAction, unk_6e) /* measured: BtlAction.unk_6e typing gives 316B, nd 243. */ = 0x102;
        return;
    }
    if (activeCountMasked != 0) {
        MEMBER(s16, action, BtlAction, unk_6e) /* measured: BtlAction.unk_6e typing gives 316B, nd 243. */ = 0x100;
        return;
    }
    MEMBER(s16, action, BtlAction, unk_6e) /* measured: BtlAction.unk_6e typing gives 316B, nd 243. */ = 0x101;
}

/* Native b210/O2: 3196/3200 bytes, all 99 relocations resolved and the four
 * retail tail bytes zero. All 70 siblings and four data sections preserved.
 * Evidence: build/cos20814/resume-battle/aed50-resume27-exact-owner/resolved/
 */
// FUN_001AED50
#pragma push
/* measured: func_001aed50 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* measured: fully typed body gives 3368B / nd 2202; opt_common_subs off
 * gives 3212B / nd 2208. Neither matches, so no additional pragma is retained. */
/* Queue the roundup formation, per-hit results and dependent animation/display packets for every target. */
void btlActionRoundupUpdate(u8 *action)
{
    /* Historical whole-layout trial: 3300B; remaining exceptions are measured per access below. */
    extern s32 btlFormationAllocWork(u32 mode);
    extern void btlFormationSetPlacement(u32 formation);
    extern u32 btlFormationGetFlags(s32 record);
    extern u8 *btlFormationDispatchPacketNew(u32 action, u32, u32);
    extern u8 *btlTargetCreateRecordPacket(u8 *action);
    extern s32 btlUnitSlotValueOrOne(s32 unitId);
    extern void btlBossResetPendingCue(u8 *action);
    extern u32 datCalcChkBadStatus(s32 action, u32);
    extern void btlMainSkillColorPairDefaults(u32 action, s32 *, s32 *);
    extern s32 btlMainSkillColorDefault(s32 skill);
    extern s32 btlMainSkillTintDefault(s32 skill);
    extern void btlMainSkillColorPairDefaultsAlt(u32 action, s32 *, s32 *);
    extern BtlPacket *btlMainCreateColorLerpPacket(u32 action, u32, u32);
    extern BtlPacket *btlMainCreateColorWorkPacket(s32 lightColor, s32 ambientColor, s32 fogColor, u32 duration, u16 flags);
    extern BtlPacket *btlMainCreateTintPacket(u32 action, u32);
    extern BtlPacket *btlCreateTimingPacket(u32 value);
    extern BtlPacket *btlMainCreateFadePacket(s32 action, s16);
    extern BtlPacket *btlMainCreateColorFadePacket(s32 arg);
    extern BtlPacket *btlSoundCreateStreamPacket(u16 action, const char *);
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
    extern u8 D_005F6D38[];
    extern u8 D_005F6D48[];
    extern u8 D_005F6D58[];
    extern BtlSkillFlags *iGpffffb3bc;
    s32 outHi;
    s32 outLo;
    s32 partyUnits[3];
    union { u8 bytes[32]; s32 words[8]; } tmpBuf;
    char workBuf[128];
    u8 *namedFormationPacket;
    u8 *formationPacket;
    u32 handle;
    u16 targetDelay;
    s32 skillId;
    u16 targetIndex;
    u8 *rec;
    u16 hitIndex;
    u8 *setupPacket;
    u8 *effectAction;
    u8 *chain;
    u8 *anim;
    u8 *targetOrUnit;
    u8 *target;
    s64 uid;
    s32 aux;
    u32 selector;
    s64 setupUID;
    u16 frameInterval;
    s32 colorKind;
    u32 formationFlags;
    u16 k;
    u8 *list;

    uid = *(s64 *)action;
    handle = btlFormationAllocWork(1);
    for (list = ((BtlBattleState *)iGpffffb3ac)->actions; list != NULL; list = *(u8* *)&((BtlAction *)list)->next) {
        if (((BtlAction *)list)->unk_28 != 0) {
            u8 *packet;
            packet = btlTargetCreateActionPacket(list, 2);
            *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
            btlPacketEnqueue(packet, 1);
        }
    }
    aux = *(s16 *)&((BtlAction *)action)->unk_6e;
    target = ((BtlAction *)action)->targets[0];
    for (k = 0; k < ((BtlBattleState *)iGpffffb3ac)->partyActionCount; k++) {
        partyUnits[k] = (s32)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->partyActions[k])->unit;
    }
    for (; k < 3U; k++) {
        partyUnits[k] = 0;
    }
    {
        u8 *packet;
        packet = btlFormationDispatchPacketNew(partyUnits[0], partyUnits[1], partyUnits[2]);
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    setupPacket = btlCutinCreateEndPacket();
    *setupPacket = 10;
    *(s16 *)&((BtlPacketCondition *)setupPacket)[0].value.id = 0xC00;
    *(setupPacket + 0x10) = 10;
    *(s16 *)&((BtlPacketCondition *)setupPacket)[1].value.id = 0xC05;
    *(s64 *)&((BtlPacket *)setupPacket)->actionUID = uid;
    btlPacketEnqueue(setupPacket, 1);
    {
        u8 *packet;
        packet = (u8 *)btlSoundCreateChannelCuePacket(0xE, 4, 4);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)setupPacket)->uid;
        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
    }
    setupUID = MEMBER(s64, setupPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3200B, nd 2012. */;
    {
        u8 *packet;
        packet = func_001f99c0(*(u8* *)&((BtlAction *)action)->unk_434, 7, 0, 0, 0);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, setupPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3200B, nd 2014. */;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
    }
    selector = (u16)aux;
    btlMainSkillColorPairDefaults(selector, &outHi, &outLo);
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorLerpPacket((u32)outHi, (u32)outLo, 0x10);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = setupUID;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    colorKind = btlMainSkillColorDefault(selector);
    btlMainSkillColorPairDefaultsAlt(selector, &outHi, &outLo);
    /* Palette entries are four bytes; their flags are the second halfword. */
    skillId = (s16)aux;
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorWorkPacket(colorKind, outHi, outLo, 0x10, ((iGpffffb3bc[skillId].flags & 2) ? 1U : 0U));
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = setupUID;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        aux = (u16)aux;
        packet = (u8 *)btlMainCreateTintPacket(btlMainSkillTintDefault(aux), 0x10);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = setupUID;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateUnitTintPacket((BtlAction *)action, aux, 0x10);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = setupUID;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    btlFormationFormatName(aux, workBuf);
    namedFormationPacket = (u8 *)btlFormationCreateNamedPacket(handle, workBuf, 0);
    *namedFormationPacket = 5;
    *(s64 *)&((BtlPacket *)namedFormationPacket)->dependencyUID = setupUID;
    *(s16 *)&((BtlPacket *)namedFormationPacket)->delay = 0x3C;
    *(s64 *)&((BtlPacket *)namedFormationPacket)->actionUID = uid;
    btlPacketEnqueue(namedFormationPacket, 1);
    for (targetOrUnit = ((BtlBattleState *)iGpffffb3ac)->unitLists[0]; targetOrUnit != NULL; targetOrUnit = *(u8* *)&((BtlUnit *)targetOrUnit)->nextUnit) {
        if (datCalcChkBadStatus(*(s32 *)&((BtlUnit *)targetOrUnit)->datUnit, 0x100117) != 0 || datCalcIsDead(MEMBER(s32, targetOrUnit, BtlUnit, datUnit) /* measured: BtlUnit.datUnit typing gives 3200B, nd 1608. */, 0) != 0) {
            u8 *packet;
            packet = btlUnitCreateColorPacket(targetOrUnit, 0xFFFFFF, 0, 0, 4, 0);
            *packet = 4;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)namedFormationPacket)->uid;
            *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
            btlPacketEnqueue(packet, 0);
        }
    }
    formationPacket = (u8 *)btlFormationCreatePacket(handle, *(u32 *)&((BtlAction *)action)->unit, *(u32 *)&((BtlAction *)target)->unit, 0, 0);
    *formationPacket = 4;
    *(s64 *)&((BtlPacket *)formationPacket)->dependencyUID = *(s64 *)&((BtlPacket *)namedFormationPacket)->uid;
    *(s64 *)&((BtlPacket *)formationPacket)->actionUID = uid;
    btlPacketEnqueue(formationPacket, 2);
    {
        u8 *packet;
        switch (skillId) {
        case 0x100:
            packet = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D38);
            break;
        case 0x101:
            packet = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D48);
            break;
        default:
            packet = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D58);
            break;
        }
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)formationPacket)->uid;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    targetDelay = 0;
    frameInterval = (u16)btlUnitSlotValueOrOne(selector);
    for (targetIndex = 0; targetIndex < ((BtlAction *)action)->unk_6a; targetIndex++) {
        targetOrUnit = ((BtlAction *)action)->targets[(u32)targetIndex];
        btlBossResetPendingCue(targetOrUnit);
        formationFlags = btlFormationGetFlags((s32)(targetOrUnit + 0xD8));
        if (((BtlAction *)targetOrUnit)->targetBlock.specialHitFlag != 0) {
            effectAction = action;
        } else {
            effectAction = targetOrUnit;
        }
        {
            u8 *packet;
            packet = btlPacketCreateHpRatio(*(u8* *)&((BtlAction *)effectAction)->unit);
            *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
            btlPacketEnqueue(packet, 1);
        }
        chain = (u8 *)btlFormationCreatePacket(handle, MEMBER(u32, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 1493. */, MEMBER(u32, effectAction, BtlAction, unit) /* measured: BtlAction.unit typing gives 3200B, nd 1258. */, 1, formationFlags | 0x1000);
        *chain = 4;
        *(s64 *)&((BtlPacket *)chain)->dependencyUID = MEMBER(s64, namedFormationPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3196B, nd 135. */;
        *(s16 *)&((BtlPacket *)chain)->delay = targetDelay;
        *(s64 *)&((BtlPacket *)chain)->actionUID = uid;
        btlPacketEnqueue(chain, 2);
        {
            u8 *packet;
            packet = (u8 *)btlSoundCreateChannelCuePacket(0xA, 0, 4);
            *packet = 0xB;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)chain)->uid;
            btlPacketEnqueue(packet, 1);
        }
        if (MEMBER(s32, targetOrUnit, BtlAction, targetBlock.specialHitFlag) /* measured: BtlAction.targetBlock.specialHitFlag typing gives 3200B, nd 1282. */ != 0) {
            u8 *packet;
            packet = (u8 *)btlFormationCreatePacket(*(u32 *)&((BtlBattleState *)iGpffffb3ac)->formations[9], MEMBER(u32, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 1500. */, *(u32 *)&((BtlAction *)targetOrUnit)->unit, 1, 0);
            *packet = 0xB;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, chain, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3200B, nd 1150. */;
            btlPacketEnqueue(packet, 1);
        }
        if (((BtlAction *)targetOrUnit)->targetBlock.hitOutcome == 0x400) {
            u8 *packet;
            packet = (u8 *)btlFormationCreatePacket(*(u32 *)&((BtlBattleState *)iGpffffb3ac)->formations[10], MEMBER(u32, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 1499. */, MEMBER(u32, effectAction, BtlAction, unit) /* measured: BtlAction.unit typing gives 3200B, nd 1258. */, 1, 0);
            *packet = 0xB;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, chain, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3200B, nd 1150. */;
            btlPacketEnqueue(packet, 1);
        }
        for (hitIndex = 0; hitIndex < ((BtlAction *)targetOrUnit)->targetBlock.hitRowCount; hitIndex++) {
            u16 *flags;
            rec = targetOrUnit + ((u32)hitIndex << 5);
            anim = (u8 *)btlUnitCreateAnimPacket(MEMBER(BtlUnit *, effectAction, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 1272. */, (s32)((BtlAction *)rec)->targetBlock.hitRows[0].motion, 0, 1.0f, 0);
            *anim = 0xB;
            *(s64 *)&((BtlPacket *)anim)->dependencyUID = MEMBER(s64, chain, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 1171. */;
            *(s64 *)&((BtlPacket *)anim)->actionUID = uid;
            btlPacketEnqueue(anim, 0);
            {
                u8 *packet;
                packet = btlUnitCreateRotateTowardUnitPacket(*(u8* *)&((BtlAction *)targetOrUnit)->unit, MEMBER(u8 *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 1495. */, 2);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)anim)->uid;
                *(packet + 0x47) &= (u8)~0x20;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
            }
            {
                u8 *packet;
                packet = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)effectAction, battleHitPayload(rec), MEMBER(u16, targetOrUnit, BtlAction, targetBlock.hitOutcome) /* measured: BtlAction.targetBlock.hitOutcome typing gives 3208B, nd 1099. */, ((BtlAction *)targetOrUnit)->targetBlock.targetFlags);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 945. */;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
            }
            {
                u8 *packet;
                packet = btlTargetCreateRecordPacket(targetOrUnit);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 950. */;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
            }
            if (targetIndex == MEMBER(u16, action, BtlAction, unk_6a) /* measured: BtlAction.unk_6a typing gives 3208B, nd 845. */ - 1 && hitIndex == MEMBER(u8, targetOrUnit, BtlAction, targetBlock.hitRowCount) /* measured: BtlAction.targetBlock.hitRowCount typing gives 3208B, nd 828. */ - 1) {
                u8 *packet;
                packet = btlTargetCreateRecordPacket(action);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 954. */;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
            }
            if (hitIndex == 0 && *(const s32 *)battleHitPayload(rec) != 0) {
                u8 *packet;
                packet = btlPacketCreateUnitCounter(MEMBER(s32, effectAction, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 1277. */, 0, 0);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 957. */;
                *(packet + 0x47) &= (u8)~0x20;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 3);
            }
            flags = (u16 *)(rec + 0x10E);
            if ((*flags & 1) != 0) {
                u8 *packet;
                btlTargetClearResultBuffer(tmpBuf.bytes);
                tmpBuf.words[3] = 0x100001;
                packet = (u8 *)btlTargetCreateDataPacket((s32)targetOrUnit, (s32)targetOrUnit, tmpBuf.bytes, 1, 1);
                *packet = 4;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 956. */;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
                if ((*flags & 2) != 0) {
                    u8 *recoveryPacket;
                    recoveryPacket = (u8 *)btlUnitCreateAnimPacket(MEMBER(BtlUnit *, targetOrUnit, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 979. */, 0xB, 0, 1.0f, 0);
                    *recoveryPacket = 4;
                    *(s64 *)&((BtlPacket *)recoveryPacket)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 957. */;
                    *(s64 *)&((BtlPacket *)recoveryPacket)->actionUID = uid;
                    btlPacketEnqueue(recoveryPacket, 0);
                    recoveryPacket = (u8 *)btlUnitCreateMotionSettlePacket(MEMBER(BtlUnit *, targetOrUnit, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 982. */);
                    *recoveryPacket = 4;
                    *(s64 *)&((BtlPacket *)recoveryPacket)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 958. */;
                    *(s64 *)&((BtlPacket *)recoveryPacket)->actionUID = uid;
                    btlPacketEnqueue(recoveryPacket, 0);
                }
            }
            {
                u8 *packet;
                packet = btlPacketCreateHitDisplay(MEMBER(s32, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 1503. */, MEMBER(s32, effectAction, BtlAction, unit) /* measured: BtlAction.unit typing gives 3208B, nd 1277. */, skillId, MEMBER(u16, targetOrUnit, BtlAction, targetBlock.hitOutcome) /* measured: BtlAction.targetBlock.hitOutcome typing gives 3208B, nd 1111. */, MEMBER(u16, targetOrUnit, BtlAction, targetBlock.targetFlags) /* measured: BtlAction.targetBlock.targetFlags typing gives 3208B, nd 936. */, hitIndex, MEMBER(u8, targetOrUnit, BtlAction, targetBlock.hitRowCount) /* measured: BtlAction.targetBlock.hitRowCount typing gives 3208B, nd 541. */, battleHitPayload(rec), 0);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3208B, nd 955. */;
                *(packet + 0x47) &= (u8)~0x20;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 3);
            }
        }
        targetDelay += frameInterval;
    }
    for (targetOrUnit = ((BtlBattleState *)iGpffffb3ac)->unitLists[0]; targetOrUnit != NULL; targetOrUnit = *(u8* *)&((BtlUnit *)targetOrUnit)->nextUnit) {
        if (datCalcChkBadStatus(*(s32 *)&((BtlUnit *)targetOrUnit)->datUnit, 0x100117) != 0 || datCalcIsDead(MEMBER(s32, targetOrUnit, BtlUnit, datUnit) /* measured: BtlUnit.datUnit typing gives 3200B, nd 374. */, 0) != 0) {
            u8 *packet;
            packet = btlUnitCreateColorPacket(targetOrUnit, -1, 0xC, 0, 3, 0);
            *packet = 0xB;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)chain)->uid;
            *(s16 *)&((BtlPacket *)packet)->delay = 6;
            *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
            btlPacketEnqueue(packet, 0);
        }
    }
    {
        u8 *packet;
        packet = (u8 *)btlCreateTimingPacket(0x10);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)anim)->uid;
        *(packet + 0x47) &= (u8)~0x20;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateFadePacket(0x10, 0);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3200B, nd 247. */;
        *(packet + 0x47) &= (u8)~0x20;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorFadePacket(0x10);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3200B, nd 247. */;
        *(packet + 0x47) &= (u8)~0x20;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorSetPacket(8);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)chain)->uid;
        *(packet + 0x47) &= (u8)~0x20;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 0);
    }
    {
        u8 *packet;
        packet = btlFormationDispatchPacketNew(0, 0, 0);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, chain, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3200B, nd 124. */;
        *(packet + 0x10) = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID2 = MEMBER(s64, formationPacket, BtlPacket, uid) /* measured: BtlPacket.uid typing gives 3200B, nd 1401. */;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    btlFormationSetPlacement(handle);
    btlActionSetState((BtlAction *)action, 0x20);
}

#pragma pop
// FUN_001AF9D0
void btlActionPacketInit(void)
{
}

/* Advance to action-end processing once no queued packet retains this action UID. */
// FUN_001AF9E0
void btlActionPacketUpdate(BtlAction *action)
{
    if (btlUnitRecordFindByActionUID(*(s64 *)&((BtlAction *)action)->uid, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        btlActionSetState(action, 0x21U);
    }
}

// FUN_001AFA50
/* Transfer pending action-end flags to the battle controller, or wait for the status-window callback. */
void btlActionEndInit(u8 *action)
{
    /* Historical whole-layout trial: 264B; remaining exceptions are measured per access below. */
    if (((BtlAction *)action)->flags & 0x4000) {
        *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x400000;
        ((BtlBattleState *)D_0076449C)->actionEndFlags |= 6;
        MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 256B, nd 183. */ &= 0xBFFF;
    }
    MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 256B, nd 183. */ &= 0xFEFF;
    if (MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 256B, nd 180. */ & 0x200) {
        *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x400000;
        ((BtlBattleState *)D_0076449C)->actionEndFlags |= 0x20;
        MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 256B, nd 183. */ &= 0xFDFF;
    }
    if (btlStatusWindowShowSlot3Callback(action) != 0) {
        *(void (**)(void))(action + 0x440) = btlTaskSlotLinkedSlot3Callback;
        ((BtlAction *)action)->unk_43c = 0x21;
        btlActionSetState((BtlAction *)action, 0x16);
        return;
    }
    MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 264B, nd 188. */ &= 0xC7FF;
}

/* Finish readiness, queued-order and status processing for this action.
 * Native b210 O2: 1228 executable bytes and four zero alignment bytes.
 * This paired recovery preserves the other 69 functions and allocated data.
 * See docs/probe_archive/Action_readiness_001afb50_20260924.md. */
// FUN_001AFB50
void btlActionEndUpdate(u8 *action)
{
    /* Historical whole-layout trial: 1260B; remaining exceptions are measured per access below. */
    s32 btlActionCanFollowUpAfterEnemiesDown(u8 *action);
    s32 btlCheckBattleEnd(void);
    s32 btlActionActiveListPush(s32 action);
    s32 btlOrderRemoveActionAll(u8 *action);
    void btlOrderQueueAction(u8 *action);
    void btlOrderSetCurrentAction(u8 *action);
    void btlActionCheckStepTrigger(s32 context);
    void datCalcAdvanceSecondaryBuffs(u8 *unit);
    void btlTargetRecordDefeatReward(u8 *action);
    void datCalcSetHp(s32 unit, u16 hp);
    u32 datCalcSetBadStatus(s32 unit, u32 badStatus);

    u16 entryFlags;
    s32 specialOrder;
    s32 restart;
    s32 dead;
    s32 resetUnit;
    u8 *packet;

    if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x80) == 0) {
        entryFlags = ((BtlAction *)action)->flags;
        specialOrder = (entryFlags & 4) != 0;
        if ((entryFlags & 8) != 0 && btlActionCanFollowUpAfterEnemiesDown(action) != 0) {
            if (btlCountUnitRecordsById(0x504) != 0) {
                return;
            }
            if (btlCountUnitRecordsById(0x506) != 0) {
                return;
            }
            ((BtlAction *)action)->unk_16 = 30;
            btlActionActiveListPush((s32)action);
            restart = 1;
        } else {
            ((BtlAction *)action)->flags = ((BtlAction *)action)->flags & 0xFFF7;
            restart = 0;
        }
        if ((MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 1240B, nd 811. */ & 0x8000) == 0 && specialOrder == 0) {
            *(s32 *)&((BtlAction *)action)->unk_20 = *(s32 *)&((BtlAction *)action)->unk_20 + 1;
        }
        if (btlCheckBattleEnd() == 0) {
            if ((MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 1240B, nd 811. */ & 0x8000) == 0 && specialOrder == 0) {
                if (*(action + 0x29) > 0) {
                    if (*(action + 0x28) == 0 && datCalcIsDead(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0) == 0) {
                        *(action + 0x29) = *(action + 0x29) - 1;
                    } else {
                        *(action + 0x29) = 0;
                    }
                }
                dead = datCalcIsDead(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0);
                if ((*(action + 0x28) == 0 && *(action + 0x29) == 0) || dead != 0) {
                    if (dead != 0) {
                        *(action + 0x28) = 0;
                        *(action + 0x29) = 0;
                        btlOrderRemoveActionAll(action);
                    }
                    {
                        u16 unitFlags = ((BtlAction *)action)->unk_1a;
                        if ((unitFlags & 1) == 0) {
                            resetUnit = 0;
                        } else {
                            u8 *unit = *(u8* *)&((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 1240B, nd 842. */)->childUnit;
                            if ((unitFlags & 0x10) == 0) {
                                resetUnit = 0;
                            } else {
                                if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
                                    resetUnit = 1;
                                } else {
                                    resetUnit = 0;
                                }
                            }
                        }
                    }
                    if (resetUnit != 0) {
                        packet = (u8 *)btlUnitCreateModelReleasePacket(((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 1240B, nd 842. */)->childUnit);
                        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
                        btlPacketEnqueue(packet, 1);
                    }
                    datCalcAdvanceSecondaryBuffs(*(u8* *)&((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 1240B, nd 842. */)->datUnit);
                    btlActionCheckStepTrigger(1);
                    btlOrderQueueAction(action);
                } else {
                    btlOrderSetCurrentAction(action);
                    btlActionCheckStepTrigger(0);
                }
            } else {
                {
                    u16 unitFlags = ((BtlAction *)action)->unk_1a;
                    if ((unitFlags & 1) == 0) {
                        resetUnit = 0;
                    } else {
                        u8 *unit = *(u8* *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->childUnit;
                        if ((unitFlags & 0x10) == 0) {
                            resetUnit = 0;
                        } else {
                            if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
                                resetUnit = 1;
                            } else {
                                resetUnit = 0;
                            }
                        }
                    }
                }
                if (resetUnit != 0) {
                    packet = (u8 *)btlUnitCreateModelReleasePacket(((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->childUnit);
                    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                btlOrderQueueAction(action);
            }
        } else {
            *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags = *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags | 0x80;

        }
        if (specialOrder == 0) {
            ((BtlAction *)action)->flags = ((BtlAction *)action)->flags & 0x7FFF;
        }
        if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x80) == 0) {
            if (restart != 0) {
                btlActionSetState((BtlAction *)action, 1);
                return;
            }
            if ((MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 1240B, nd 811. */ & 0x20) == 0) {
                btlActionSetState((BtlAction *)action, 0x22);
                return;
            }
            btlOrderRemoveActionAll(action);
            if (((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->genus == 1) {
                datCalcSetBadStatus(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0x80000);
                datCalcSetHp(*(s32 *)&((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 1232B, nd 222. */)->datUnit, 0);
            }
            if (btlCheckBattleEnd() != 0) {
                *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags = *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags | 0x80;
            }
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if ((MEMBER(u16, action, BtlAction, flags) /* measured: BtlAction.flags typing gives 1240B, nd 812. */ & 0x20) != 0) {
            btlOrderRemoveActionAll(action);
            if (((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->genus == 1) {
                datCalcSetBadStatus(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0x80000);
                datCalcSetHp(*(s32 *)&((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit) /* measured: BtlAction.unit typing gives 1232B, nd 124. */)->datUnit, 0);
            }
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if (datCalcIsDead(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0) != 0) {
            btlTargetRecordDefeatReward(action);
            btlActionSetState((BtlAction *)action, 1);
        }
        return;
    }
}

