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

void func_001f14f0(u8 *arg0);
void func_001eb3b0(u8 *arg0);


BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *func_0019bbe0(u8 *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern BtlPacket *btlUnitCreateModelReleasePacket(BtlUnit *unit);
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);

extern u8 *iGpffffb3b8;
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *target, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
extern f32 fGpffff811c;
extern u32 datCalcGetBadStatus(s32 arg0);
extern s16 func_001f6d60(u8 *arg0);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
extern void func_001f0a10(u8 *arg0);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateHpRatio(u8 *arg0);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
extern BtlPacket *btlFormationCreateReturnPacket(u16 arg0);
extern u8 *btlUnitCreateLookAtSidePacket(u8 *unit, s16 value);
extern BtlPacket *btlFormationCreateEventPacket(u32 action);
BtlPacket *btlMainCreateColorSetPacket(s32 arg0);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
u8 *func_001fa720(const void *data);
s32 func_001eb860(void);
u8 *func_001fa8f0(void);
u8 *func_001faa60(void);
extern void btlDamageSetSource(u8 *arg0, s32 arg1);
s32 func_0019ff60(u8 *arg0);
s64 *btlActionGetQueueFront(void);
s32 func_001d94d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));
u32 btlCountUnitRecordsById(u32 arg0);
u8 *btlCutinCreatePacket(u8 *arg0);
u8 *btlUnitCreateRotateTowardUnitPacket(u8 *arg0, u8 *arg1, s32 arg2);
u8 *btlPacketAllocZeroed(s32 arg0, s32 arg1);
u8 *btlEffectCreateFormationPacket(s32 arg0, s32 arg1, s32 arg2, s64 arg3, s32 arg4);
u8 *func_001f99c0(u8 *arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 *btlCutinCreateEndPacket(void);
u8 *btlCutinCreateStartPacket(void);
extern void btlMessageStartShort(u8 *task, u8 *unit);
extern s32 btlMessageIsActive(s32 task);
extern s32 btlMessageGetResult(s32 task);
extern void btlMessageReset(s32 task);
s16 func_001d15a0(void);
s32 btlSideCountNotBad(s32 arg0, s32 arg1);
u32 datCalcChkBadStatus(s32 arg0, u32 arg1);

BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
BtlPacket *btlSoundCreateChannelCuePacket(u16 arg0, u16 arg1, u16 arg2);
extern f32 D_0076144C;
s32 func_001fac80(u8 *arg0);
void func_001fad10(void);

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001ade90-001afb50 */

extern s32 func_001a05f0(BtlAction *action);
extern void btlActionSkillUpdate(u8 *arg0);
u8 func_0023e1f0(u8 *unitData);
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
    return record + 0xF0;
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
        unit = *(u8 **)(action + 48);
        badStatus = datCalcGetBadStatus(*(s32 *)(unit + 2660));
        packetIdentity = *(s64 *)action;
        statusKind = badStatus & 0xFFFFF;
        switch (statusKind) {
        case 0x20:
            {
                func_001f0a10((u8 *)&result);
                result.flags = result.flags | 0x100;
                delta = (s16)func_001f6d60(action);
                result.hpDelta = delta;
                if (delta < 0) {
                    resultPacket = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                    *(s16 *)(resultPacket + 72) = 12;
                    btlPacketEnqueue(resultPacket, 1);
                    healthPacket = btlPacketCreateHpRatio(unit);
                    *(healthPacket + 0) = 4;
                    *(s64 *)(healthPacket + 8) = *(s64 *)(resultPacket + 88);
                    btlPacketEnqueue(healthPacket, 1);
                    displayPacket = btlPacketCreateHitDisplay((s32)unit, (s32)unit, -1, 0, 0, 0, 1, &result, 0);
                    *(displayPacket + 0) = 4;
                    *(s64 *)(displayPacket + 8) = *(s64 *)(resultPacket + 88);
                    *(displayPacket + 71) = *(displayPacket + 71) & 0xDF;
                    btlPacketEnqueue(displayPacket, 3);
                    gaugePacket = btlPacketCreateUnitCounter((s32)unit, 0, 0);
                    *(gaugePacket + 0) = 4;
                    *(s64 *)(gaugePacket + 8) = *(s64 *)(resultPacket + 88);
                    *(gaugePacket + 71) = *(gaugePacket + 71) & 0xDF;
                    btlPacketEnqueue(gaugePacket, 3);
                    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 48), -2, 0, 1.0f, 0);
                    *(animationPacket + 0) = 4;
                    *(s64 *)(animationPacket + 8) = *(s64 *)(resultPacket + 88);
                    *(animationPacket + 32) = 10;
                    *(s16 *)(animationPacket + 40) = 769;
                    *(s64 *)(animationPacket + 96) = packetIdentity;
                    btlPacketEnqueue(animationPacket, 0);
                    soundPacket = (u8 *)btlSoundCreateChannelCuePacket(10, 2, 24);
                    *(soundPacket + 0) = 4;
                    *(s64 *)(soundPacket + 8) = *(s64 *)(resultPacket + 88);
                    btlPacketEnqueue(soundPacket, 1);
                }
                {
                    u16 actionKind = *(u16 *)(action + 108);
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
                func_001f0a10((u8 *)&result);
                result.flags = result.flags | 0x100;
                delta = (s16)func_001f6d60(action);
                result.spDelta = delta;
                if (delta < 0) {
                    resultPacket = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                    *(s16 *)(resultPacket + 72) = 12;
                    btlPacketEnqueue(resultPacket, 1);
                    healthPacket = btlPacketCreateHpRatio(unit);
                    *(healthPacket + 0) = 4;
                    *(s64 *)(healthPacket + 8) = *(s64 *)(resultPacket + 88);
                    btlPacketEnqueue(healthPacket, 1);
                    displayPacket = btlPacketCreateHitDisplay((s32)unit, (s32)unit, -1, 0, 0, 0, 1, &result, 0);
                    *(displayPacket + 0) = 4;
                    *(s64 *)(displayPacket + 8) = *(s64 *)(resultPacket + 88);
                    *(displayPacket + 71) = *(displayPacket + 71) & 0xDF;
                    btlPacketEnqueue(displayPacket, 3);
                    gaugePacket = btlPacketCreateUnitCounter((s32)unit, 1, 0);
                    *(gaugePacket + 0) = 4;
                    *(s64 *)(gaugePacket + 8) = *(s64 *)(resultPacket + 88);
                    *(gaugePacket + 71) = *(gaugePacket + 71) & 0xDF;
                    btlPacketEnqueue(gaugePacket, 3);
                    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 48), -2, 0, 1.0f, 0);
                    *(animationPacket + 0) = 4;
                    *(s64 *)(animationPacket + 8) = *(s64 *)(resultPacket + 88);
                    *(animationPacket + 32) = 10;
                    *(s16 *)(animationPacket + 40) = 769;
                    *(s64 *)(animationPacket + 96) = packetIdentity;
                    btlPacketEnqueue(animationPacket, 0);
                    soundPacket = (u8 *)btlSoundCreateChannelCuePacket(10, 2, 24);
                    *(soundPacket + 0) = 4;
                    *(s64 *)(soundPacket + 8) = *(s64 *)(resultPacket + 88);
                    btlPacketEnqueue(soundPacket, 1);
                }
                {
                    u16 actionKind = *(u16 *)(action + 108);
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
                u16 actionKind = *(u16 *)(action + 108);
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
s32 btlActionGetCounter428(BtlAction *action)
{
    return *(s32 *)((u8 *)action + 0x428);
}

/* Build the return-to-action packet sequence and select an available target.
 * Native b210 O2: 1072/1072 bytes, every relocation resolved; all other
 * owner functions and data preserved. See the 001ae3d0 recovery note. */
// FUN_001AE3D0
void btlActionRoundupMesInit(u8 *action)
{
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

    currentAction = *(u8 **)(iGpffffb3ac + 372);
    while (currentAction != NULL) {
        if (func_001a05f0((BtlAction *)currentAction) != 0) {
            packet = (u8 *)btlUnitCreateModelReleasePacket(*(BtlUnit **)(*(u8 **)(currentAction + 48) + 2572));
            *(s64 *)(packet + 96) = *(s64 *)currentAction;
            btlPacketEnqueue(packet, 1);
        }
        currentAction = *(u8 **)(currentAction + 1104);
    }
    target = NULL;
    if (*(u8 *)(*(u8 **)(action + 48) + 162) == 0) {
        selectedAction = (u32)action;
    } else {
        selectedAction = (u32)*(u8 **)(action + 56);
    }
    if (selectedAction != 0) {
        u16 i;
        u8 *tableBase;
        s32 count;
        u32 current;
        i = 0;
        tableBase = iGpffffb3ac;
        count = *(u16 *)(tableBase + 3160);
        while ((s32)i < count) {
            current = *(u32 *)(tableBase + (u32)i * 4 + 3144);
            if (current == selectedAction) {
                target = (u8 *)selectedAction;
                break;
            }
            i++;
        }
    }
    if (target == NULL) {
        target = actionTargetAt((ActionTargetTable *)iGpffffb3ac, (datCalcRandomBelow(*(u16 *)(iGpffffb3ac + 3160)) & 0xFFFF));
    }
    cutin.mode = 1;
    cutin.unitId = *(u16 *)(*(u8 **)(target + 48) + 164);
    packet = func_001fa720(&cutin);
    *(s64 *)(packet + 96) = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    if (*(u8 *)(*(u8 **)(action + 48) + 162) != 0) {
        changeFormation = 0;
    } else if ((*(s16 *)(iGpffffb3ac + 2672) != -1) &&
               (enemyCount = btlSideCountNotBad(2, 0x80000) & 0xFFFF,
                (u32)(*(s16 *)(iGpffffb3ac + 2674) >> 1) >= enemyCount) &&
               (previousFormation = *(s16 *)(iGpffffb3ac + 2672),
                previousFormation != (s16)func_001d15a0())) {
        changeFormation = 1;
    } else {
        changeFormation = 0;
    }
    if (changeFormation != 0) {
        packet = (u8 *)btlFormationCreateReturnPacket(1);
        *(s64 *)(packet + 96) = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
    }
    packet = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(*(u8 **)(iGpffffb3ac + 368) + 48), 0, 0, 1.0f, 1);
    *(s64 *)(packet + 96) = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    targetIndex = 0;
    while ((s32)targetIndex < *(u16 *)(iGpffffb3ac + 3160)) {
        targetAction = *(u8 **)(iGpffffb3ac + ((u32)targetIndex * 4) + 3144);
        packet = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(targetAction + 48), 0, 0, 1.0f, 1);
        *(s64 *)(packet + 96) = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
        targetIndex++;
    }
    packet = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s64 *)(packet + 96) = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = btlUnitCreateLookAtSidePacket(0, 3);
    *(s64 *)(packet + 96) = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    packet = (u8 *)btlUnitCreateLookAtDeactivatePacket(NULL, 3);
    *(s64 *)(packet + 96) = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    packet = (u8 *)btlFormationCreateEventPacket((u32)action);
    *(s64 *)(packet + 96) = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = (u8 *)btlMainCreateColorSetPacket(0);
    *(s64 *)(packet + 96) = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 7);
    *(s64 *)(packet + 96) = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    flags = *(u32 *)(iGpffffb3ac + 12);
    flags = flags & 0xFFBFFFFF;
    *(u32 *)(iGpffffb3ac + 12) = flags;
    *(u16 *)(iGpffffb3ac + 24) = 0;
    if (func_001eb860() == 1) {
        flags = *(u32 *)(iGpffffb3ac + 12);
        flags = flags & ~0x2000;
        *(u32 *)(iGpffffb3ac + 12) = flags;
        btlDamageSetSource(*(u8 **)(iGpffffb3ac + 3540), 0);
    }
    *(u8 **)(action + 1052) = target;
    *(s32 *)(action + 1056) = 0;
    *(s32 *)(action + 1060) = 0;
    *(s32 *)(action + 1064) = 0;
    *(u16 *)(action + 1068) = 12;
}

// FUN_001AE800
void btlActionRoundupMesUpdate(u8 *arg0)
{
    u8 *gp2;
    u8 *packet1;
    u8 *packet2;
    u8 *packet3;
    u8 *packet4;
    u16 i;
    u32 loop_i;
    u8 frame[0x10];

    if (*(s32 *)(arg0 + 0x424) == 0) {
        if (btlCountUnitRecordsById(0xC00) != 0) {
            return;
        }
        if (btlCountUnitRecordsById(0xC04) != 0) {
            return;
        }
        *(s16 *)frame = 0;
        i = 0;
        gp2 = D_0076449C;
        while ((s32)(loop_i = i) < *(u16 *)(gp2 + 0xC58)) {
            packet1 = *(u8 **)(gp2 + 0xC48 + ((u32)i * 4));
            *(u16 *)(frame + 2 + ((u32)i * 2)) =
                *(u16 *)(*(u8 **)(packet1 + 0x30) + 0xA4);
            i++;
        }
        *(u16 *)(frame + 8) = *(u16 *)(gp2 + 0xC58);
        packet1 = btlCutinCreatePacket(frame);
        btlPacketEnqueue(packet1, 1);
        packet2 = func_001fa8f0();
        *(s16 *)(packet2 + 0x48) = *(s16 *)(arg0 + 0x42C);
        btlPacketEnqueue(packet2, 1);
        packet3 = btlPacketAllocZeroed((s32)btlActionGetCounter428, (s32)arg0);
        *(s16 *)(packet3 + 0x48) = *(s16 *)(arg0 + 0x42C);
        btlPacketEnqueue(packet3, 1);
        packet4 = btlEffectCreateFormationPacket(
            *(s32 *)(D_0076449C + 0xD8C),
            *(s32 *)(arg0 + 0x30), 0,
            *(s64 *)(packet3 + 0x58), 0x8000);
        *(s16 *)(packet4 + 0x48) = *(s16 *)(arg0 + 0x42C);
        btlPacketEnqueue(packet4, 2);
        *(s32 *)(arg0 + 0x424) = 1;
    }

    if (*(s32 *)(arg0 + 0x420) == 0) {
        if (*(s16 *)(arg0 + 0x42C) <= 0) {
            btlMessageStartShort(*(u8 **)(D_0076449C + 0xDD4),
                          *(u8 **)(arg0 + 0x41C));
            *(s32 *)(arg0 + 0x420) = 1;
        } else {
            *(s16 *)(arg0 + 0x42C) = *(s16 *)(arg0 + 0x42C) - 1;
        }
    }

    if (btlUnitRecordFindByActionUID(*(u64 *)arg0,
                      0x3FFFFFFFFFFFFFFFULL) != 0) {
        return;
    }

    if (*(s32 *)(arg0 + 0x428) == 0) {
        if (btlMessageIsActive(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            return;
        }
        if (btlMessageGetResult(*(s32 *)(D_0076449C + 0xDD4)) == 0) {
            packet1 = btlTargetCreateActionPacket(arg0, 2);
            *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
            btlPacketEnqueue(packet1, 1);
            *(s32 *)(*(u8 **)(D_0076449C + 0x170) + 0x434) =
                *(s32 *)(arg0 + 0x41C);
            *(s16 *)(*(u8 **)(D_0076449C + 0x170) + 0x16) = 0x1F;
            func_001b0e30(*(s32 *)(D_0076449C + 0x170));
            packet2 = (u8 *)btlActionGetQueueFront();
            if ((*(u8 *)(*(u8 **)(packet2 + 0x30) + 0xA2) == 0) &&
                (*(u8 *)(packet2 + 0x28) != 0)) {
                *(u16 *)(packet2 + 0x18) |= 0x8000;
            }
            btlPacketEnqueue(
                func_001f99c0(*(u8 **)(arg0 + 0x41C), 6, 1, 0, 0), 1);
        } else {
            btlPacketEnqueue(
                func_001f99c0(*(u8 **)(arg0 + 0x41C), 6, 0, 0, 0), 1);
            packet1 = btlCutinCreateStartPacket();
            *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
            btlPacketEnqueue(packet1, 1);
        }

        packet1 = func_001faa60();
        *(u64 *)(packet1 + 0x60) = *(u64 *)arg0;
        btlPacketEnqueue(packet1, 1);
        packet2 = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 1);
        *(u64 *)(packet2 + 0x60) = *(u64 *)arg0;
        btlPacketEnqueue(packet2, 1);
        *(u16 *)(arg0 + 0x18) &= 0xFFF7;
        if (func_001eb860() == 1) {
            *(s32 *)(D_0076449C + 0xC) |= 0x2000;
            btlDamageSetSource(*(u8 **)(D_0076449C + 0xDD4), 1);
        }
        *(s32 *)(arg0 + 0x428) = 1;
        *(u16 *)(arg0 + 0x42E) = 6;
        return;
    }

    if (*(u16 *)(arg0 + 0x42E) == 0) {
        btlMessageReset(*(s32 *)(D_0076449C + 0xDD4));
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 7;
        btlActionSetState((BtlAction *)arg0, 0x20);
        return;
    }
    *(u16 *)(arg0 + 0x42E) = *(u16 *)(arg0 + 0x42E) - 1;
}

// FUN_001AEC20
void btlActionRoundupInit(u8 *arg0)
{
    s32 activeCountMasked;
    s32 unitIndex;
    s32 activeCount;
    s32 slotIndex;
    s32 unitCount;
    s32 slotCount;
    u8 *slot;

    func_001eb3b0(arg0 + 0x38);
    btlSkillClassifyTargets(arg0, arg0 + 0x98, 0x100, 0);
    unitIndex = 0;
    goto loop_2_test;
loop_2_body:
    slot = arg0 + ((u16)unitIndex * 4);
    *(s32 *)(slot + 0x38) = *(s32 *)(slot + 0x98);
    unitIndex = (unitIndex + 1) & 0xFFFF;
loop_2_test:
    unitCount = *(u16 *)(arg0 + 0xD0);
    if ((unitIndex & 0xFFFF) < unitCount) {
        goto loop_2_body;
    }
    *(u16 *)(arg0 + 0x6A) = unitCount;
    *(s16 *)(arg0 + 0x6C) = 2;
    *(s16 *)(arg0 + 0x6E) = 0x100;
    func_001f14f0(arg0);
    activeCount = 0;
    slotIndex = 0;
    slotCount = *(u16 *)(arg0 + 0x6A);
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(*(u8 **)(arg0 + ((u16)slotIndex * 4) + 0x38) + 0xE0) != 0) {
        activeCount = (activeCount + 1) & 0xFFFF;
    }
    slotIndex = (slotIndex + 1) & 0xFFFF;
loop_7_test:
    if ((slotIndex & 0xFFFF) < slotCount) {
        goto loop_7_body;
    }
    activeCountMasked = activeCount & 0xFFFF;
    if (slotCount == activeCountMasked) {
        *(s16 *)(arg0 + 0x6E) = 0x102;
        return;
    }
    if (activeCountMasked != 0) {
        *(s16 *)(arg0 + 0x6E) = 0x100;
        return;
    }
    *(s16 *)(arg0 + 0x6E) = 0x101;
}

/* Native b210/O2: 3196/3200 bytes, all 99 relocations resolved and the four
 * retail tail bytes zero. All 70 siblings and four data sections preserved.
 * Evidence: build/cos20814/resume-battle/aed50-resume27-exact-owner/resolved/
 */
// FUN_001AED50
#pragma push
/* measured: func_001aed50 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void btlActionRoundupUpdate(u8 *arg0)
{
    typedef struct PartyActionView {
        u8 unknown00[0x30];
        u8 *unit;
    } PartyActionView;
    typedef struct PartyStateView {
        u8 unknown00[0xC48];
        PartyActionView *members[4];
        u16 count;
    } PartyStateView;
    extern s32 btlFormationAllocWork(u32 arg0);
    extern void btlFormationSetPlacement(u32 arg0);
    extern u32 btlFormationGetFlags(s32 arg0);
    extern u8 *func_001d7bf0(u32 arg0, u32 arg1, u32 arg2);
    extern u8 *btlTargetCreateRecordPacket(u8 *arg0);
    extern s32 btlUnitSlotValueOrOne(s32 arg0);
    extern void btlBossResetPendingCue(u8 *arg0);
    extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
    extern void btlMainSkillColorPairDefaults(u32 arg0, s32 *arg1, s32 *arg2);
    extern s32 btlMainSkillColorDefault(s32 arg0);
    extern s32 btlMainSkillTintDefault(s32 arg0);
    extern void btlMainSkillColorPairDefaultsAlt(u32 arg0, s32 *arg1, s32 *arg2);
    extern BtlPacket *btlMainCreateColorLerpPacket(u32 arg0, u32 arg1, u32 arg2);
    extern BtlPacket *btlMainCreateColorWorkPacket(s32 first, s32 second, s32 third, u32 frames, u16 mode);
    extern BtlPacket *btlMainCreateTintPacket(u32 arg0, u32 arg1);
    extern BtlPacket *btlCreateTimingPacket(u32 arg0);
    extern BtlPacket *btlMainCreateFadePacket(s32 arg0, s16 arg1);
    extern BtlPacket *btlMainCreateColorFadePacket(s32 arg0);
    extern BtlPacket *btlSoundCreateStreamPacket(u16 arg0, const char *arg1);
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
    extern u8 D_005F6D38[];
    extern u8 D_005F6D48[];
    extern u8 D_005F6D58[];
    extern u8 *iGpffffb3bc;
    s32 outHi;
    s32 outLo;
    s32 sp1D8[3];
    union { u8 bytes[32]; s32 words[8]; } tmpBuf;
    char workBuf[128];
    u8 *pkt12C;
    u8 *pkt128;
    u32 handle;
    u16 sp110;
    s32 sp100;
    u16 var23;
    u8 *rec;
    u16 var22;
    u8 *setupPacket;
    u8 *unit19;
    u8 *chain;
    u8 *anim;
    u8 *unit17;
    u8 *target;
    s64 uid;
    s32 aux;
    u32 selector;
    s64 cur58;
    u16 frameInterval;
    s32 colorKind;
    u32 formationFlags;
    u16 k;
    u8 *list;

    uid = *(s64 *)arg0;
    handle = btlFormationAllocWork(1);
    for (list = *(u8 **)(iGpffffb3ac + 0x174); list != NULL; list = *(u8 **)(list + 0x450)) {
        if (*(u8 *)(list + 0x28) != 0) {
            u8 *pk;
            pk = btlTargetCreateActionPacket(list, 2);
            *(s64 *)(pk + 0x60) = uid;
            btlPacketEnqueue(pk, 1);
        }
    }
    aux = *(s16 *)(arg0 + 0x6E);
    target = *(u8 **)(arg0 + 0x38);
    for (k = 0; k < ((PartyStateView *)iGpffffb3ac)->count; k++) {
        sp1D8[k] = (s32)((PartyStateView *)iGpffffb3ac)->members[k]->unit;
    }
    for (; k < 3U; k++) {
        sp1D8[k] = 0;
    }
    {
        u8 *pk;
        pk = func_001d7bf0(sp1D8[0], sp1D8[1], sp1D8[2]);
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    setupPacket = btlCutinCreateEndPacket();
    *setupPacket = 10;
    *(s16 *)(setupPacket + 8) = 0xC00;
    *(setupPacket + 0x10) = 10;
    *(s16 *)(setupPacket + 0x18) = 0xC05;
    *(s64 *)(setupPacket + 0x60) = uid;
    btlPacketEnqueue(setupPacket, 1);
    {
        u8 *pk;
        pk = (u8 *)btlSoundCreateChannelCuePacket(0xE, 4, 4);
        *pk = 5;
        *(s64 *)(pk + 8) = *(s64 *)(setupPacket + 0x58);
        *(s64 *)(pk + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(pk, 1);
    }
    cur58 = *(s64 *)(setupPacket + 0x58);
    {
        u8 *pk;
        pk = func_001f99c0(*(u8 **)(arg0 + 0x434), 7, 0, 0, 0);
        *pk = 5;
        *(s64 *)(pk + 8) = *(s64 *)(setupPacket + 0x58);
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(pk, 1);
    }
    selector = (u16)aux;
    btlMainSkillColorPairDefaults(selector, &outHi, &outLo);
    {
        u8 *pk;
        pk = (u8 *)btlMainCreateColorLerpPacket((u32)outHi, (u32)outLo, 0x10);
        *pk = 5;
        *(s64 *)(pk + 8) = cur58;
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    colorKind = btlMainSkillColorDefault(selector);
    btlMainSkillColorPairDefaultsAlt(selector, &outHi, &outLo);
    /* Palette entries are four bytes; their flags are the second halfword. */
    sp100 = (s16)aux;
    {
        u8 *pk;
        pk = (u8 *)btlMainCreateColorWorkPacket(colorKind, outHi, outLo, 0x10, ((((const u16 *)(iGpffffb3bc + 2))[sp100 * 2] & 2) ? 1U : 0U));
        *pk = 5;
        *(s64 *)(pk + 8) = cur58;
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    {
        u8 *pk;
        aux = (u16)aux;
        pk = (u8 *)btlMainCreateTintPacket(btlMainSkillTintDefault(aux), 0x10);
        *pk = 5;
        *(s64 *)(pk + 8) = cur58;
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    {
        u8 *pk;
        pk = (u8 *)btlMainCreateUnitTintPacket((BtlAction *)arg0, aux, 0x10);
        *pk = 5;
        *(s64 *)(pk + 8) = cur58;
        *(s16 *)(pk + 0x48) = 0x3C;
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    btlFormationFormatName(aux, workBuf);
    pkt12C = (u8 *)btlFormationCreateNamedPacket(handle, workBuf, 0);
    *pkt12C = 5;
    *(s64 *)(pkt12C + 8) = cur58;
    *(s16 *)(pkt12C + 0x48) = 0x3C;
    *(s64 *)(pkt12C + 0x60) = uid;
    btlPacketEnqueue(pkt12C, 1);
    for (unit17 = *(u8 **)(iGpffffb3ac + 0x178); unit17 != NULL; unit17 = *(u8 **)(unit17 + 0xA6C)) {
        if (datCalcChkBadStatus(*(s32 *)(unit17 + 0xA64), 0x100117) != 0 || datCalcIsDead(*(s32 *)(unit17 + 0xA64), 0) != 0) {
            u8 *pk;
            pk = func_0019bbe0(unit17, 0xFFFFFF, 0, 0, 4, 0);
            *pk = 4;
            *(s64 *)(pk + 8) = *(s64 *)(pkt12C + 0x58);
            *(s64 *)(pk + 0x60) = uid;
            btlPacketEnqueue(pk, 0);
        }
    }
    pkt128 = (u8 *)btlFormationCreatePacket(handle, *(u32 *)(arg0 + 0x30), *(u32 *)(target + 0x30), 0, 0);
    *pkt128 = 4;
    *(s64 *)(pkt128 + 8) = *(s64 *)(pkt12C + 0x58);
    *(s64 *)(pkt128 + 0x60) = uid;
    btlPacketEnqueue(pkt128, 2);
    {
        u8 *pk;
        switch (sp100) {
        case 0x100:
            pk = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D38);
            break;
        case 0x101:
            pk = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D48);
            break;
        default:
            pk = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D58);
            break;
        }
        *pk = 5;
        *(s64 *)(pk + 8) = *(s64 *)(pkt128 + 0x58);
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    sp110 = 0;
    frameInterval = (u16)btlUnitSlotValueOrOne(selector);
    for (var23 = 0; var23 < *(u16 *)(arg0 + 0x6A); var23++) {
        unit17 = *(u8 **)(arg0 + (u32)var23 * 4 + 0x38);
        btlBossResetPendingCue(unit17);
        formationFlags = btlFormationGetFlags((s32)(unit17 + 0xD8));
        if (*(s32 *)(unit17 + 0xE4) != 0) {
            unit19 = arg0;
        } else {
            unit19 = unit17;
        }
        {
            u8 *pk;
            pk = btlPacketCreateHpRatio(*(u8 **)(unit19 + 0x30));
            *(s64 *)(pk + 0x60) = uid;
            btlPacketEnqueue(pk, 1);
        }
        chain = (u8 *)btlFormationCreatePacket(handle, *(u32 *)(arg0 + 0x30), *(u32 *)(unit19 + 0x30), 1, formationFlags | 0x1000);
        *chain = 4;
        *(s64 *)(chain + 8) = *(s64 *)(pkt12C + 0x58);
        *(s16 *)(chain + 0x48) = sp110;
        *(s64 *)(chain + 0x60) = uid;
        btlPacketEnqueue(chain, 2);
        {
            u8 *pk;
            pk = (u8 *)btlSoundCreateChannelCuePacket(0xA, 0, 4);
            *pk = 0xB;
            *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
            btlPacketEnqueue(pk, 1);
        }
        if (*(s32 *)(unit17 + 0xE4) != 0) {
            u8 *pk;
            pk = (u8 *)btlFormationCreatePacket(*(u32 *)(iGpffffb3ac + 0xD28), *(u32 *)(arg0 + 0x30), *(u32 *)(unit17 + 0x30), 1, 0);
            *pk = 0xB;
            *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
            btlPacketEnqueue(pk, 1);
        }
        if (*(u16 *)(unit17 + 0xDC) == 0x400) {
            u8 *pk;
            pk = (u8 *)btlFormationCreatePacket(*(u32 *)(iGpffffb3ac + 0xD2C), *(u32 *)(arg0 + 0x30), *(u32 *)(unit19 + 0x30), 1, 0);
            *pk = 0xB;
            *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
            btlPacketEnqueue(pk, 1);
        }
        for (var22 = 0; var22 < *(u8 *)(unit17 + 0xD9); var22++) {
            u16 *flags;
            rec = unit17 + ((u32)var22 << 5);
            anim = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(unit19 + 0x30), (s32)*(s8 *)(rec + 0x10C), 0, 1.0f, 0);
            *anim = 0xB;
            *(s64 *)(anim + 8) = *(s64 *)(chain + 0x58);
            *(s64 *)(anim + 0x60) = uid;
            btlPacketEnqueue(anim, 0);
            {
                u8 *pk;
                pk = btlUnitCreateRotateTowardUnitPacket(*(u8 **)(unit17 + 0x30), *(u8 **)(arg0 + 0x30), 2);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(pk + 0x47) &= (u8)~0x20;
                *(s64 *)(pk + 0x60) = uid;
                btlPacketEnqueue(pk, 1);
            }
            {
                u8 *pk;
                pk = (u8 *)btlTargetCreateDataPacket((s32)arg0, (s32)unit19, battleHitPayload(rec), *(u16 *)(unit17 + 0xDC), *(u16 *)(unit17 + 0xDE));
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(s64 *)(pk + 0x60) = uid;
                btlPacketEnqueue(pk, 1);
            }
            {
                u8 *pk;
                pk = btlTargetCreateRecordPacket(unit17);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(s64 *)(pk + 0x60) = uid;
                btlPacketEnqueue(pk, 1);
            }
            if (var23 == *(u16 *)(arg0 + 0x6A) - 1 && var22 == *(u8 *)(unit17 + 0xD9) - 1) {
                u8 *pk;
                pk = btlTargetCreateRecordPacket(arg0);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(s64 *)(pk + 0x60) = uid;
                btlPacketEnqueue(pk, 1);
            }
            if (var22 == 0 && *(const s32 *)battleHitPayload(rec) != 0) {
                u8 *pk;
                pk = btlPacketCreateUnitCounter(*(s32 *)(unit19 + 0x30), 0, 0);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(pk + 0x47) &= (u8)~0x20;
                *(s64 *)(pk + 0x60) = uid;
                btlPacketEnqueue(pk, 3);
            }
            flags = (u16 *)(rec + 0x10E);
            if ((*flags & 1) != 0) {
                u8 *pk;
                func_001f0a10(tmpBuf.bytes);
                tmpBuf.words[3] = 0x100001;
                pk = (u8 *)btlTargetCreateDataPacket((s32)unit17, (s32)unit17, tmpBuf.bytes, 1, 1);
                *pk = 4;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(s64 *)(pk + 0x60) = uid;
                btlPacketEnqueue(pk, 1);
                if ((*flags & 2) != 0) {
                    u8 *pk2;
                    pk2 = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(unit17 + 0x30), 0xB, 0, 1.0f, 0);
                    *pk2 = 4;
                    *(s64 *)(pk2 + 8) = *(s64 *)(anim + 0x58);
                    *(s64 *)(pk2 + 0x60) = uid;
                    btlPacketEnqueue(pk2, 0);
                    pk2 = (u8 *)btlUnitCreateMotionSettlePacket(*(BtlUnit **)(unit17 + 0x30));
                    *pk2 = 4;
                    *(s64 *)(pk2 + 8) = *(s64 *)(anim + 0x58);
                    *(s64 *)(pk2 + 0x60) = uid;
                    btlPacketEnqueue(pk2, 0);
                }
            }
            {
                u8 *pk;
                pk = btlPacketCreateHitDisplay(*(s32 *)(arg0 + 0x30), *(s32 *)(unit19 + 0x30), sp100, *(u16 *)(unit17 + 0xDC), *(u16 *)(unit17 + 0xDE), var22, *(u8 *)(unit17 + 0xD9), battleHitPayload(rec), 0);
                *pk = 5;
                *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
                *(pk + 0x47) &= (u8)~0x20;
                *(s64 *)(pk + 0x60) = uid;
                btlPacketEnqueue(pk, 3);
            }
        }
        sp110 += frameInterval;
    }
    for (unit17 = *(u8 **)(iGpffffb3ac + 0x178); unit17 != NULL; unit17 = *(u8 **)(unit17 + 0xA6C)) {
        if (datCalcChkBadStatus(*(s32 *)(unit17 + 0xA64), 0x100117) != 0 || datCalcIsDead(*(s32 *)(unit17 + 0xA64), 0) != 0) {
            u8 *pk;
            pk = func_0019bbe0(unit17, -1, 0xC, 0, 3, 0);
            *pk = 0xB;
            *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
            *(s16 *)(pk + 0x48) = 6;
            *(s64 *)(pk + 0x60) = uid;
            btlPacketEnqueue(pk, 0);
        }
    }
    {
        u8 *pk;
        pk = (u8 *)btlCreateTimingPacket(0x10);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
        *(pk + 0x47) &= (u8)~0x20;
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    {
        u8 *pk;
        pk = (u8 *)btlMainCreateFadePacket(0x10, 0);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
        *(pk + 0x47) &= (u8)~0x20;
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    {
        u8 *pk;
        pk = (u8 *)btlMainCreateColorFadePacket(0x10);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(anim + 0x58);
        *(pk + 0x47) &= (u8)~0x20;
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    {
        u8 *pk;
        pk = (u8 *)btlMainCreateColorSetPacket(8);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
        *(pk + 0x47) &= (u8)~0x20;
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 0);
    }
    {
        u8 *pk;
        pk = func_001d7bf0(0, 0, 0);
        *pk = 4;
        *(s64 *)(pk + 8) = *(s64 *)(chain + 0x58);
        *(pk + 0x10) = 4;
        *(s64 *)(pk + 0x18) = *(s64 *)(pkt128 + 0x58);
        *(s64 *)(pk + 0x60) = uid;
        btlPacketEnqueue(pk, 1);
    }
    btlFormationSetPlacement(handle);
    btlActionSetState((BtlAction *)arg0, 0x20);
}

#pragma pop
// FUN_001AF9D0
void btlActionPacketInit(void)
{
}

// FUN_001AF9E0
void btlActionPacketUpdate(BtlAction *action)
{
    if (btlUnitRecordFindByActionUID(*(s64 *)action, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        btlActionSetState(action, 0x21U);
    }
}

// FUN_001AFA50
void btlActionEndInit(u8 *arg0)
{
    if (*(u16 *)(arg0 + 0x18) & 0x4000) {
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 6;
        *(u16 *)(arg0 + 0x18) &= 0xBFFF;
    }
    *(u16 *)(arg0 + 0x18) &= 0xFEFF;
    if (*(u16 *)(arg0 + 0x18) & 0x200) {
        *(s32 *)(D_0076449C + 0xC) |= 0x400000;
        *(u16 *)(D_0076449C + 0x18) |= 0x20;
        *(u16 *)(arg0 + 0x18) &= 0xFDFF;
    }
    if (func_001fac80(arg0) != 0) {
        *(void (**)(void))(arg0 + 0x440) = func_001fad10;
        *(s16 *)(arg0 + 0x43C) = 0x21;
        btlActionSetState((BtlAction *)arg0, 0x16);
        return;
    }
    *(u16 *)(arg0 + 0x18) &= 0xC7FF;
}

/* Finish readiness, queued-order and status processing for this action.
 * Native b210 O2: 1228 executable bytes and four zero alignment bytes.
 * This paired recovery preserves the other 69 functions and allocated data.
 * See docs/probe_archive/Action_readiness_001afb50_20260924.md. */
// FUN_001AFB50
void btlActionEndUpdate(u8 *action)
{
    s32 func_0019ff60(u8 *action);
    s32 btlCheckBattleEnd(void);
    s32 func_001b0e30(s32 action);
    s32 btlOrderRemoveActionAll(u8 *action);
    void btlOrderQueueAction(u8 *action);
    void btlOrderSetCurrentAction(u8 *action);
    void btlActionCheckStepTrigger(s32 advance);
    void datCalcAdvanceSecondaryBuffs(u8 *unit);
    void func_001f2cc0(u8 *action);
    void datCalcSetHp(s32 unit, u16 hp);
    u32 datCalcSetBadStatus(s32 unit, u32 badStatus);

    u16 entryFlags;
    s32 specialOrder;
    s32 restart;
    s32 dead;
    s32 resetUnit;
    u8 *packet;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80) == 0) {
        entryFlags = *(u16 *)(action + 0x18);
        specialOrder = (entryFlags & 4) != 0;
        if ((entryFlags & 8) != 0 && func_0019ff60(action) != 0) {
            if (btlCountUnitRecordsById(0x504) != 0) {
                return;
            }
            if (btlCountUnitRecordsById(0x506) != 0) {
                return;
            }
            *(s16 *)(action + 0x16) = 30;
            func_001b0e30((s32)action);
            restart = 1;
        } else {
            *(u16 *)(action + 0x18) = *(u16 *)(action + 0x18) & 0xFFF7;
            restart = 0;
        }
        if ((*(u16 *)(action + 0x18) & 0x8000) == 0 && specialOrder == 0) {
            *(s32 *)(action + 0x20) = *(s32 *)(action + 0x20) + 1;
        }
        if (btlCheckBattleEnd() == 0) {
            if ((*(u16 *)(action + 0x18) & 0x8000) == 0 && specialOrder == 0) {
                if (*(action + 0x29) > 0) {
                    if (*(action + 0x28) == 0 && datCalcIsDead(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0) == 0) {
                        *(action + 0x29) = *(action + 0x29) - 1;
                    } else {
                        *(action + 0x29) = 0;
                    }
                }
                dead = datCalcIsDead(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0);
                if ((*(action + 0x28) == 0 && *(action + 0x29) == 0) || dead != 0) {
                    if (dead != 0) {
                        *(action + 0x28) = 0;
                        *(action + 0x29) = 0;
                        btlOrderRemoveActionAll(action);
                    }
                    {
                        u16 unitFlags = *(u16 *)(action + 0x1A);
                        if ((unitFlags & 1) == 0) {
                            resetUnit = 0;
                        } else {
                            u8 *unit = *(u8 **)(*(u8 **)(action + 0x30) + 0xA0C);
                            if ((unitFlags & 0x10) == 0) {
                                resetUnit = 0;
                            } else {
                                if ((*(u32 *)(unit + 0x98) & 2) != 0) {
                                    resetUnit = 1;
                                } else {
                                    resetUnit = 0;
                                }
                            }
                        }
                    }
                    if (resetUnit != 0) {
                        packet = (u8 *)btlUnitCreateModelReleasePacket(*(BtlUnit **)(*(u8 **)(action + 0x30) + 0xA0C));
                        *(s64 *)(packet + 0x60) = *(s64 *)action;
                        btlPacketEnqueue(packet, 1);
                    }
                    datCalcAdvanceSecondaryBuffs(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64));
                    btlActionCheckStepTrigger(1);
                    btlOrderQueueAction(action);
                } else {
                    btlOrderSetCurrentAction(action);
                    btlActionCheckStepTrigger(0);
                }
            } else {
                {
                    u16 unitFlags = *(u16 *)(action + 0x1A);
                    if ((unitFlags & 1) == 0) {
                        resetUnit = 0;
                    } else {
                        u8 *unit = *(u8 **)(*(u8 **)(action + 0x30) + 0xA0C);
                        if ((unitFlags & 0x10) == 0) {
                            resetUnit = 0;
                        } else {
                            if ((*(u32 *)(unit + 0x98) & 2) != 0) {
                                resetUnit = 1;
                            } else {
                                resetUnit = 0;
                            }
                        }
                    }
                }
                if (resetUnit != 0) {
                    packet = (u8 *)btlUnitCreateModelReleasePacket(*(BtlUnit **)(*(u8 **)(action + 0x30) + 0xA0C));
                    *(s64 *)(packet + 0x60) = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                btlOrderQueueAction(action);
            }
        } else {
            *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x80;

        }
        if (specialOrder == 0) {
            *(u16 *)(action + 0x18) = *(u16 *)(action + 0x18) & 0x7FFF;
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80) == 0) {
            if (restart != 0) {
                btlActionSetState((BtlAction *)action, 1);
                return;
            }
            if ((*(u16 *)(action + 0x18) & 0x20) == 0) {
                btlActionSetState((BtlAction *)action, 0x22);
                return;
            }
            btlOrderRemoveActionAll(action);
            if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 1) {
                datCalcSetBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0x80000);
                datCalcSetHp(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0);
            }
            if (btlCheckBattleEnd() != 0) {
                *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) | 0x80;
            }
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if ((*(u16 *)(action + 0x18) & 0x20) != 0) {
            btlOrderRemoveActionAll(action);
            if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 1) {
                datCalcSetBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0x80000);
                datCalcSetHp(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0);
            }
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if (datCalcIsDead(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0) != 0) {
            func_001f2cc0(action);
            btlActionSetState((BtlAction *)action, 1);
        }
        return;
    }
}

