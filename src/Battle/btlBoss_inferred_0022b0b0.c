#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "effect_instance_internal.h"
typedef struct BtlTarget BtlTarget;
typedef struct BtlCamera BtlCamera;
typedef struct BtlUnitStateWork BtlUnitStateWork;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct RwV3d RwV3d;
typedef struct DatUnit DatUnit;
typedef struct KwlnTask KwlnTask;
typedef struct Model Model;
typedef struct RwMatrix RwMatrix;
extern u8 *iGpffff9db0;
extern u8 D_006355C0[], D_006355E0[], D_00635600[];
extern u8 *resrcMngFindResById(u8 *lists, u16 id);
extern u16 datCalcMaxHp(DatUnit *unit);
extern u32 datCalcChkBadStatus(s32 unit, u32 mask);
extern u32 func_001064f0(s32 counter);
extern void func_00106550(s32 counter, u32 value);
extern void btlEncounterSetSequence(s32 initialize, s32 update, s32 packet);
extern void mdlScale(Model *model, const RwV3d *scale, int combineOp);
/* Retail forwards the matrix result as well as all three inputs. */
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
typedef struct BtlAction BtlAction;
extern void btlActionSetState(BtlAction *action, u16 state);
extern void btlActionRunPresentation(u8 *packet);
extern void btlActionRunMotionSequence(u8 *packet);
struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
};
typedef struct RtQuat {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} RtQuat;
typedef struct RwRGBA {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} RwRGBA;
extern RwRGBA iGpffffb45c;
extern char D_007636C0[8];
extern char D_007636C8[8];
extern char D_007636D0[8];
extern u8 D_0062E070[];
extern void mdlSetFrameColorByName(void *model, s32 name, u8 alpha);
extern s32 datCalcAddHp(DatUnit *unit, s32 hpDelta);
extern void datCalcClearBuffLevel(u8 *unit, s32 effect);
extern RtQuat *func_003dc740(RtQuat *out, const RwV3d *axis, f32 angle, s32 mode);
extern void btlUnitSetRot(BtlUnit *unit, const RtQuat *rotation);
extern void btlUnitSetColor(BtlUnit *unit, RwRGBA color);
extern u32 datCalcClearBadStatus(s32 unit, u32 mask);
extern void btlUnitShowModel(u8 *unit);
extern u32 datGetFlag(s32 bit);


extern u8 D_006290F0[];

u32 kwlnTaskGetWork(void *task);
extern u8 D_00629698[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern u8 D_00795F20[];
extern u8 D_006296D0[];
extern u8 D_008C0240[0x94];
extern u8 D_00635560[], D_00635580[];
extern u8 iGpffffa4d8[4];
extern u8 *func_001ebb00(s32 action, s32 kind, u8 *name);
extern u8 *btlPacketAllocZeroed(void *callback, void *data);
extern BtlPacket *btlEffectCreateMessagePacket(u8 *values, u16 duration);
extern BtlPacket *btlEffectCreateFadeLevelPacket(u16 duration);
extern BtlPacket *btlUnitCreateModelReleasePacket(BtlUnit *unit);
extern u8 *btlUnitCreateModelLoadPacket(u8 *unit, u16 id, s16 animation);
extern BtlPacket *btlBossCreateLoadEndBgmPacket(s32 id);
extern BtlPacket *btlBossCreateReleaseEndBgmPacket(void);
extern BtlPacket *btlBossCreateStepEndBgmPacket(void);
extern BtlPacket *btlBossCreateStopEndBgmPacket(void);
extern BtlPacket *btlCreateTimingPacket(u32 duration);
extern BtlPacket *btlMainCreateFadePacket(s32 duration, s16 mode);
extern BtlPacket *btlMainCreateColorFadePacket(s32 duration);
extern BtlPacket *btlMainCreateColorSetPacket(s32 duration);

extern u8 D_00629640[];
extern u8 D_00629738[];
extern f32 fGpffff80fc;
extern f32 fGpffff80dc;
extern f32 fGpffff8110;
extern u8 D_0060A100[];
extern f32 fGpffff8100;
extern f32 fGpffff810c;
extern f32 fGpffff8128;
extern f32 fGpffff813c;
extern f32 fGpffff809c;
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8098;
extern f32 fGpffff8118;
extern f32 fGpffff8174;
extern f32 fGpffff8178;
extern f32 fGpffff817c;

extern u8 D_006296B0[];
extern u8 D_006296E8[];

extern u8 D_00629700[];


extern u8 *DAT_0076449c;
extern s32 btlUnitSkillBlocked(u8 *action, u8 *subordinate);

extern u8 *btlUnitRecordFindByActionUID(u64 uid, u64 mask);
extern void datSetFlag(s32 arg0, s32 arg1);
extern s32 kwlnTaskIsLinked(void *target);
extern u8 *btlActionFindByUnit(s32 arg0);
extern void btlTargetSetDefeatState(u8 *arg0, s32 arg1);
extern void btlSoundStopBgmIfEnabled(void);


u8 *H_Cdvd_GetArchiveEntry(u8 *arg0, s32 arg1, s32 *arg2);



extern void (*jtbl_008873EC[])(void *arg0);
extern void btlSoundFadeOutBgm(s16 fadeDuration);
extern void sdkSndPlayCue(s32 arg0, s32 arg1);
extern u32 datCalcRandomBelow(u32 arg0);
extern u8 D_0060A0E0[];
extern s32 btlCurrentUnitId(void);
extern u8 D_006348B0[];
extern u8 D_00634CB0[];
extern u8 D_006350B0[];
extern u8 *iGpffffb414;
extern u8 D_0062A5F0[];
extern u8 D_0062AD40[];
extern u8 D_0062B490[];
extern u8 D_0062BBE0[];
extern u8 D_0062C330[];
extern s32 btlActionGetActiveOrQueueFront(void);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern f32 fGpffff834c;
extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
extern void btlUnitSetPos(u8 *arg0, s32 *arg1);
extern void btlTargetPositionToCell(s16 *outX, s16 *outZ, f32 *position);
extern u8 *iGpffffb3e0;
extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlTargetCanSelectEntry(u8 *arg0, s16 arg1, s32 arg2);
extern s32 btlBossTargetBlocked(u8 *arg0);
extern s32 btlBossSkillResultBlocked(u8 *arg0);

extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern u8 D_00632240[];
extern u8 *btlUnitFindInSideById(s32 arg0, s32 arg1);
extern u8 D_0062D920[];
extern void btlActionFinishPresentation(s64 *arg0);
extern s32 btlFormationAllocWork(u32 param_1);
extern void btlFormationSetSlot(s32 formation, u32 data);
extern u8 *btlFormationGetRecord(s32 arg0);
extern void btlFormationCopyRecord(int destination, u32 source);
extern BtlPacket *btlUnitCreateColorPacket(BtlUnit *unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags);
extern void btlTargetClearResultBuffer(u8 *arg0);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlUnitCreateAnimPacket(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern void btlFormationSetPlacement(u32 arg0);
extern u8 D_006354B0[];
extern u8 *iGpffffb444;
extern u8 *iGpffffb3ac;
extern u8 *scrStartProcedureIndex(s32 arg0, u8 *arg1, s32 arg2);
extern void scrSetTaskProc(u8 *arg0, u8 *arg1);
extern u8 *func_0010d740(s16 arg0);
extern void itfMesWindowSetString(u8 *arg0, s32 arg1, u8 *arg2);
extern void kwlnTaskAddChild(u8 *arg0, u8 *arg1);
extern u8 D_00629750[], D_00629EA0[], D_0062CA80[], D_0062D1D0[];
extern u8 D_0062E7C0[], D_0062EF10[], D_0062F660[], D_0062FDB0[];
extern u8 D_00630500[], D_00630C50[], D_006313A0[], D_00631AF0[];
extern u8 D_006355A0[];
extern void datPersonaClearRoster(void);
extern u8 *datPersonaAddRosterMember(u16 personaId);
extern s32 datPersonaSelectRosterMemberById(s32 personaId);
extern void btlUnitInitChild(u8 *unit, u16 action);
extern void func_00106d40(s16 character, s16 slot, s16 value);
extern u16 datCalcMaxHpById(s16 character);
extern u16 datCalcMaxSpById(s16 character);
extern void datSetUnitHp(s16 character, s16 value);
extern void datSetUnitSp(s16 character, s16 value);
extern void datCalcClearBadStatusById(s16 character, u32 mask);
extern s32 btlActionQueuePush(u8 *target);

extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rotation, u32 flags);
extern u32 datCalcIsDead(void *unit, s32 hpDelta);
extern u8 D_006354C0[], D_006354D0[], D_00635500[];
extern f32 fGpffff80e4;

/* Source unit: src/promoted/code1_0022.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0022.c; members 0022b0b0-0022fb10 */

extern void btlCameraApplyPartyPose(u8 *camera);
extern void btlEncounterStartSequence(u8 *arg0);
extern s32 btlEncounterFinishStep(u8 *arg0);
extern void btlActionRunPresentation(u8 *action);
extern s32 btlEncounterWaitCleared(s64 *arg0);
extern void btlActionRunMotionSequence(u8 *arg0);
extern s32 btlEncounterReleaseFlags(s64 *arg0);
extern void btlEncounterStartCameraState(u8 *arg0);
extern s32 btlEncounterWaitReleaseEvents(s64 *arg0);
extern void btlEncounterResetSlots(u8 *arg0);
extern s32 btlEncounterWaitIdle(s64 *arg0);
static inline u8 *cb90AddBaseIndex(u32 base, u32 index)
{
    return (u8 *)(base + index);
}
#pragma push
#pragma pop
/* 896/896 bytes and all 17 relocations resolve exactly.
 * Keep the opaque byte branch-local, snapshot coordinates before opacity
 * conversion, and pack the color before preparing the overlay dimensions. */
#pragma push
#pragma pop
/* 1036/1040 bytes; 26 code relocations and all nine switch entries exact. */
#pragma push
#pragma pop
/* 1688/1696 bytes; all 36 resolved code relocations exact. */
/* Measured: 800/800 bytes, 20 resolved relocations, zero differences.
 * Disabling common-subexpression folding preserves the wrapping target walk. */
/* measured 00225d00 plain-C reconstruction matches the complete 256-byte retail window at normalized_diff 0. */
/* measured: opt_scalarize off retains the real horizontal vector stores.
 * Staged radius scaling and the scoped two-halfword skill table give
 * 1420/1424 bytes, 21 code relocations and zero normalized differences. */
/* 1516/1520 bytes, 48 resolved code relocations and all
 * seven switch targets match retail; four zero tail-alignment bytes. */
/* measured: opt_common_subs off preserves per-use 16-bit ordinal masks.
 * Independent target/party ordinals and the materialized subordinate predicate
 * give 1620/1632 bytes, 50 code relocations and zero normalized differences.
 * Each pose pair is two contiguous seven-float poses, without padding. */
/* measured: closing opt_common_subs off for btlCameraApplyPartyPose. */
/* 2444/2448 bytes; all 56 resolved code relocations exact. */
/* measured: opt_propagation off preserves btlEncounterStartSequence's initial GP-load/store order (nd 0). */
/* measured: close opt_propagation after btlEncounterStartSequence (nd 0). */
// Intent: Set the encounter state to 0x2D. [inferred]
// FUN_0022B0B0
s32 btlEncounterSetState2D(void)
{
    btlSoundFadeOutBgm(0x2D);
    return 1;
}

// Intent: Play the cue when the frame flag 0x40 is set. [inferred]
// FUN_0022B0E0
s32 btlEncounterPlayCueIfFlag40(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC) & 0x40) {
        sdkSndPlayCue(6, 1);
    }
    return 1;
}

// Intent: Run the formation presentation sequence for an action. [inferred]
// FUN_0022B120
/* 1860/1872 bytes; all 67 resolved code relocations exact. */
void btlActionRunFormationSequence(u8 *action)
{
    u8 *actor;
    s32 openingFormation;
    s32 closingFormation;
    u8 *wait1;
    u8 *wait0;
    u8 *anchor;
    u8 *cleanup;
    u8 *packet;
    RwV3d rotation;

    actor = *(u8 **)(action + 0x30);
    *(u32 *)(DAT_0076449c + 0xC) |= 0x400000;
    *(u16 *)(DAT_0076449c + 0x18) |= 0x23;
    btlActionFinishPresentation((s64 *)action);
    openingFormation = btlFormationAllocWork(0);
    closingFormation = btlFormationAllocWork(0);
    btlFormationCopyRecord(openingFormation, (u32)btlFormationGetRecord(0xC));
    btlFormationCopyRecord(closingFormation, (u32)btlFormationGetRecord(0xD));
    *(u32 *)(DAT_0076449c + 0xC) |= 0x80000;

    anchor = func_001ebb00((s32)action, 3, D_00635560);
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    btlPacketEnqueue(anchor, 1);

    packet = btlPacketAllocZeroed((void *)btlEncounterSetState2D, action);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    packet = btlUnitCreateAnimPacket(actor, 0x13, 0, 2, 1.0f);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 2;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 0);

    packet = (u8 *)btlBossCreateStepEndBgmPacket();
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 0x33;
    btlPacketEnqueue(packet, 1);

    wait1 = (u8 *)btlFormationCreatePacket((u32)openingFormation, (u32)actor, (u32)actor, 0, 0x200);
    wait1[0] = 4;
    *(u64 *)(wait1 + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(wait1 + 0x60) = *(u64 *)action;
    btlPacketEnqueue(wait1, 2);

    wait0 = (u8 *)btlFormationCreatePacket((u32)openingFormation, (u32)actor, (u32)actor, 1, 0x200);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    btlPacketEnqueue(wait0, 2);

    packet = (u8 *)btlEffectCreateMessagePacket(iGpffffa4d8, 0x1E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 0x19A;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = (f32)3000;
    packet = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)actor, &rotation, 2);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 0);

    anchor = (u8 *)btlUnitCreateModelReleasePacket((BtlUnit *)actor);
    anchor[0] = 4;
    *(u64 *)(anchor + 8) = *(u64 *)(wait1 + 0x58);
    anchor[0x10] = 4;
    *(u64 *)(anchor + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(anchor + 0x48) = 1;
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    btlPacketEnqueue(anchor, 1);

    packet = (u8 *)btlBossCreateStopEndBgmPacket();
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait1 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    cleanup = (u8 *)btlBossCreateReleaseEndBgmPacket();
    cleanup[0] = 4;
    *(u64 *)(cleanup + 8) = *(u64 *)(wait1 + 0x58);
    cleanup[0x10] = 4;
    *(u64 *)(cleanup + 0x18) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(cleanup + 0x48) = 3;
    *(u64 *)(cleanup + 0x60) = *(u64 *)action;
    btlPacketEnqueue(cleanup, 1);

    wait0 = btlUnitCreateModelLoadPacket(actor, 0x10E, 0x216);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait0 + 0x48) = 2;
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    btlPacketEnqueue(wait0, 1);

    anchor = func_001ebb00((s32)action, 3, D_00635580);
    anchor[0] = 4;
    *(u64 *)(anchor + 8) = *(u64 *)(wait0 + 0x58);
    *(u16 *)(anchor + 0x48) = 2;
    *(u16 *)(anchor + 0x4A) = 0xC;
    *(u64 *)(anchor + 0x60) = *(u64 *)action;
    btlPacketEnqueue(anchor, 1);

    packet = btlPacketAllocZeroed((void *)btlEncounterPlayCueIfFlag40, action);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 1;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlBossCreateLoadEndBgmPacket(0x10E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(cleanup + 0x58);
    *(u16 *)(packet + 0x48) = 1;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlUnitCreateColorPacket((BtlUnit *)actor, 0xFFFFFFFFU, 1, 0, 3, 0);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 2;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlEffectCreateFadeLevelPacket(0x1E);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(packet + 0x48) = 4;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    wait0 = (u8 *)btlFormationCreatePacket((u32)closingFormation, (u32)actor, (u32)actor, 0, 0x200);
    wait0[0] = 4;
    *(u64 *)(wait0 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait0 + 0x48) = 2;
    *(u64 *)(wait0 + 0x60) = *(u64 *)action;
    btlPacketEnqueue(wait0, 2);

    wait1 = (u8 *)btlFormationCreatePacket((u32)closingFormation, (u32)actor, (u32)actor, 1, 0x200);
    wait1[0] = 4;
    *(u64 *)(wait1 + 8) = *(u64 *)(anchor + 0x58);
    *(u16 *)(wait1 + 0x48) = 2;
    *(u64 *)(wait1 + 0x60) = *(u64 *)action;
    btlPacketEnqueue(wait1, 2);

    packet = (u8 *)btlCreateTimingPacket(0x10);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlMainCreateFadePacket(0x10, 0);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlMainCreateColorFadePacket(0x10);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlMainCreateColorSetPacket(8);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(wait0 + 0x58);
    packet[0x10] = 4;
    *(u64 *)(packet + 0x18) = *(u64 *)(wait1 + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 0);

    btlFormationSetPlacement((u32)closingFormation);
    btlFormationSetPlacement((u32)openingFormation);
}

/* measured: opt_loop_invariants on probe for btlEncounterFinishSetup. */
/* measured: btlEncounterFinishSetup MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: Finish encounter setup once the presentation completes. [inferred]
// FUN_0022B870
s32 btlEncounterFinishSetup(u8 *arg0)
{
    extern void btlUnitInitFromRecord(u8 *arg0, s32 arg1);
    extern u32 datUnitInit(DatUnit *unit, u8 genus, u16 id);
    extern s32 btlActionQueuePush(u8 *arg0);
    extern s32 btlActionGetQueueFront(void);
    extern void btlBossCollectTargets(u8 *arg0);
    extern u8 *btlSoundGetCharacterBank(u8 *arg0);
    extern u8 D_00630C50[];
    u32 index;
    s32 value;
    s32 fill;
    u8 *temp;

    if (btlUnitRecordFindByActionUID(*(u64 *)arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        *(s32 *)(DAT_0076449c + 0xC) &= 0xFFF7FFFF;
        btlUnitInitFromRecord(*(u8 **)(arg0 + 0x30), 0x10E);
        datUnitInit((DatUnit *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64)), 1, 0x10E);
        datSetFlag(0x15FF, 1);
        *(u8 **)(DAT_0076449c + 0xB98) = &D_00630C50[0];
        *(s32 *)(DAT_0076449c + 0xC40) = 1;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) |= 0x2000;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= 0xFFFF7FFF;
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= ~0x20;
        temp = *(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64);
        *(u16 *)temp |= 0x20;
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        btlActionQueuePush(arg0);
        btlBossCollectTargets((u8 *)btlActionGetQueueFront());
        index = 0;
        fill = -1;
        goto loop_test;
loop_body:
        *(s8 *)(DAT_0076449c + index + 0xC10) = fill;
        index++;
loop_test:
        if (index < 0x1E) {
            goto loop_body;
        }
        value = (s32)btlSoundGetCharacterBank(*(u8 **)(arg0 + 0x30));
        *(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA00) + 0x2DC) = value;
        btlUnitUpdateStatusMotion(*(u8 **)(arg0 + 0x30), 6);
        datSetFlag(0x15C0, 0);
        *(s32 *)(DAT_0076449c + 0xBB4) = 0;
        *(s32 *)(DAT_0076449c + 0xBC8) = 0;
        *(u16 *)(DAT_0076449c + 0x290) |= 0x10;
        return 0;
    }
    return 1;
}

/* measured: closes opt_loop_invariants around btlEncounterFinishSetup. */
/* measured: optimization_level 1 preserves btlEncounterResetUnit's loop branch. */
// Intent: Reset the encounter unit by id. [inferred]
// FUN_0022BA40
void btlEncounterResetUnit(u16 arg1)
{
    s32 value;
    s32 id;
    u8 *p;

    p = *(u8 **)(DAT_0076449c + 0x180);
    id = 0x10E;
    goto check;
body:
    value = *(u16 *)(p + 0xA4);
    if (value == id) {
        goto found;
    }
    p = *(u8 **)(p + 0xA6C);
check:
    if (p != NULL) {
        goto body;
    }
found:
    if (p != NULL) {
        p = (u8 *)btlActionFindByUnit((s32)p);
        if (p != NULL) {
            btlTargetSetDefeatState(p, 0);
            btlSoundStopBgmIfEnabled();
        }
    }
}

/* measured: closes optimization_level 1 around btlEncounterResetUnit. */
// FUN_0022BAC0
s32 func_0022bac0(void)
{
    return 0;
}

// Intent: Show the unit status window for the given slot. [inferred]
// FUN_0022BAD0
s32 btlUnitStatusWindowShow(u8 *arg0, u16 arg1)
{
    u8 *target;
    u8 *handle;
    u8 *state;
    u8 *unit;
    u8 *slot;
    u8 *temp;

    slot = &((u8 *)(((u32)arg1 & 0xFFFF) * 4))
        [(u32)iGpffffb3ac];
    if (*(s32 *)(slot + 0xBA8) != *(s32 *)(arg0 + 8)) {
        goto changed;
    }
    if (*(s32 *)(slot + 0xBBC) != *(s32 *)(arg0 + 0x20)) {
        goto changed;
    }
    return 0;
changed:
    if (arg0 == NULL) {
        target = *(u8 **)(iGpffffb3ac + 0x170);
    } else {
        target = arg0;
    }
    temp = btlFormationGetRecord(0);
    handle = scrStartProcedureIndex(
        *(s32 *)(*(u8 **)(iGpffffb3ac + 0xDC8) + 0x20) - 1,
        temp, arg1);
    scrSetTaskProc(handle, target);
    state = (u8 *)kwlnTaskGetWork(handle);
    if (*(s32 *)(state + 0x130) >= 0) {
        unit = *(u8 **)(target + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            itfMesWindowSetString(
                *(u8 **)(state + 0x130), 0,
                func_0010d740(*(s16 *)(unit + 0xA4)));
        } else {
            itfMesWindowSetString(
                *(u8 **)(state + 0x130), 0,
                iGpffffb444 + (u16)(*(u16 *)(unit + 0xA4)) * 0x15);
        }
    }
    kwlnTaskAddChild(*(u8 **)(iGpffffb3ac + 0xDC8), handle);
    *(u8 **)(iGpffffb3ac + 0xBA0) = handle;
    *(u16 *)(iGpffffb3ac + 0xBA4) = arg1;
    *(s32 *)(&((u8 *)(((u32)arg1 & 0xFFFF) * 4))
              [(u32)iGpffffb3ac] + 0xBA8) =
        *(s32 *)(arg0 + 8);
    *(s32 *)(&((u8 *)(((u32)arg1 & 0xFFFF) * 4))
              [(u32)iGpffffb3ac] + 0xBBC) =
        *(s32 *)(arg0 + 0x20);
    return 1;
}

// Intent: Report whether the task slot is linked. [inferred]
// FUN_0022BC80
s32 btlTaskSlotIsLinked(s32 arg0) {
    u8 *b = DAT_0076449c;
    u8 *o = *(u8 **)(b + 0xBA0);

    if (o == NULL) {
        return 0;
    }
    if (*(u16 *)(b + 0xBA4) != (arg0 & 0xFFFF)) {
        return 0;
    }
    if (kwlnTaskIsLinked(o) == 0) {
        *(s32 *)(DAT_0076449c + 0xBA0) = 0;
        return 0;
    }
    return 1;
}

// Intent: Report whether the task slot is set. [inferred]
// FUN_0022BD00
s32 btlTaskSlotIsSet(void)
{
    return *(s32 *)(DAT_0076449c + 0xBA0) != 0;
}

// FUN_0022BD20
s32 func_0022bd20(void)
{
    return (*(s32 *)(iGpffffb414 +
                     *(u16 *)(*(u8 **)(DAT_0076449c + 0xC68) + 8) * 0x18) &
            0x20) != 0;
}

/* measured: 1744/1744 bytes, all 152 code relocations and 22 switch-table
   targets exact. Loop-invariant motion keeps the signed empty-slot sentinel
   in the clearing-loop preheader. The pragma does not affect other functions. */
#pragma push
// Intent: Initialise the encounter globals for each battle id. [inferred]
// FUN_0022BD60
void btlEncounterInitGlobals(void)
{
    u32 i;

    *(u32 *)(DAT_0076449c + 0xC) |= 0x200000;
    *(u32 *)(DAT_0076449c + 0x10) |= 1;
    switch (btlCurrentUnitId()) {
    case 0x200:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_00629750;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x201:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_00629EA0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x202:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062A5F0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x203:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x400;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062B490;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x204:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062CA80;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x205:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x200;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062D1D0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x206:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062D920;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        *(u16 *)(DAT_0076449c + 0xC34) = 0;
        break;
    case 0x207:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062E7C0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x208:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062EF10;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x209:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x80;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x800;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062F660;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x20A:
        *(u32 *)(DAT_0076449c + 0xC) &= ~0x400U;
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x100;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x200;
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062FDB0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x20B:
    case 0x215:
        *(u32 *)(DAT_0076449c + 0xC) &= ~0x400U;
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x200;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x2000;
        if (btlCurrentUnitId() == 0x20B) {
            *(u8 **)(DAT_0076449c + 0xB98) = D_00630500;
        } else {
            *(u8 **)(DAT_0076449c + 0xB98) = D_00630C50;
        }
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x20C:
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        break;
    case 0x20D:
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x80;
        *(u8 **)(DAT_0076449c + 0xB98) = D_006313A0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        break;
    case 0x214:
        *(u32 *)(DAT_0076449c + 0xC) &= ~0x400U;
        *(u32 *)(DAT_0076449c + 0x10) |= 2;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x10;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x1000000;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x100;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x200;
        *(u8 **)(DAT_0076449c + 0xB98) = D_00631AF0;
        *(u8 **)(DAT_0076449c + 0xC30) = D_006355A0;
        datSetFlag(0x1438, 1);
        break;
    }
    for (i = 0; i < 30; i++) {
        *(s8 *)(DAT_0076449c + i + 0xC10) = -1;
    }
}

#pragma pop
/* measured: 1876B / 1888B window; 123 code relocations and all 22 table
   relocations resolve exactly. The omitted 12B are zero alignment.
   Keep each lookup/allocation/set/store sequence and its global reload. */
// Intent: Allocate the encounter formation slots for each battle id. [inferred]
// FUN_0022C430
void btlFormationAllocEncounterSlots(void)
{
    u8 *data;
    s32 formation;

    switch (btlCurrentUnitId()) {
    case 0x200:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x201:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        break;
    case 0x202:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        break;
    case 0x203:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x204:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x205:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x206:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        data = btlFormationGetRecord(9);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF4) = formation;
        break;
    case 0x207:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        break;
    case 0x208:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x209:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(5);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE4) = formation;
        data = btlFormationGetRecord(6);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE8) = formation;
        data = btlFormationGetRecord(7);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBEC) = formation;
        break;
    case 0x20A:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x20B:
    case 0x215:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    case 0x20D:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(5);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE4) = formation;
        data = btlFormationGetRecord(6);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE8) = formation;
        data = btlFormationGetRecord(7);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBEC) = formation;
        break;
    case 0x214:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBE0) = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        *(s32 *)(DAT_0076449c + 0xBF0) = formation;
        break;
    }
}

// Intent: Look up the formation slot index for a unit. [inferred]
// FUN_0022CB90
s32 btlFormationLookupSlot(u8 *arg0, u16 arg1)
{
    s32 temp_6;
    s8 temp_2;
    u16 temp_3_2;
    u8 *temp_7;
    u16 temp_3_3;

    if (*(u8 *)(arg0 + 0xA2) != 1) {
        return -1;
    }
    temp_7 = DAT_0076449c;
    temp_6 = *(s32 *)(temp_7 + 0xC30);
    if (temp_6 == 0) {
        return -1;
    }
    temp_3_2 = *(u16 *)(arg0 + 0xA4);
    switch (temp_3_2) {
    case 0x10D:
    case 0x110:
    case 0x111:
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    case 0x10F:
        temp_3_3 = (u16)arg1;
        if (((temp_3_3 == 0) || (temp_3_3 == 0x12)) &&
            (*(s16 *)(temp_7 + 0xC34) != 3)) {
            return 0xB;
        }
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    default:
        temp_2 = *(s8 *)cb90AddBaseIndex((u32)temp_7 + 0xC10,
                                         (u32)(arg1 & 0xFFFF));
        if (temp_2 >= 0) {
            return temp_2;
        }
        return *(u8 *)(temp_6 + (arg1 & 0xFFFF));
    }
}

/* measured: btlFormationClearSlots MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: Clear the formation slots and their placements. [inferred]
// FUN_0022CC90
void btlFormationClearSlots(void)
{
    extern void H_Cdvd_Destroy(s32 arg0);
    extern void btlFormationSetPlacement(s32 arg0, u8 *arg1);
    s16 i;
    s32 value;
    s32 temp_index;
    s32 index;
    s16 index16;
    u8 *slot;
    u8 *base;

    switch (btlCurrentUnitId()) {
    case 0x214:
        datPersonaClearRoster();
        datPersonaAddRosterMember(1);
        datPersonaSelectRosterMemberById(1);
        func_00106d40(1, 0, 1);
        break;
    }
    i = 0;
    while (i < 8) {
        base = DAT_0076449c;
        slot = base + i * 4;
        value = *(s32 *)(slot + 0xBE0);
        if (value != 0) {
            index16 = i;
            temp_index = (s32)(s64)(s16)index16;
            index = temp_index * 4;
            btlFormationSetPlacement(value, base);
            base = DAT_0076449c;
            *(s32 *)(base + index + 0xBE0) = 0;
        }
        i++;
    }
    value = *(s32 *)(DAT_0076449c + 0xB94);
    if (value != 0) {
        H_Cdvd_Destroy(value);
        *(s32 *)(DAT_0076449c + 0xB94) = 0;
    }
    value = *(s32 *)(DAT_0076449c + 0xB90);
    if (value != 0) {
        H_Cdvd_Destroy(value);
        *(s32 *)(DAT_0076449c + 0xB90) = 0;
    }
}

/* measured: btlUnitApplyPacketEffects, btlUnitReactToDeath MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// Intent: Return the encounter record for an index, or NULL. [inferred]
// FUN_0022CDB0
u8 *btlEncounterGetRecord(s32 arg0)
{
    s32 temp_2;
    u8 *var_2;

    if ((*(s32 *)(DAT_0076449c + 0x10) & 0x10) == 0) {
        return NULL;
    }
    temp_2 = btlCurrentUnitId();
    switch (temp_2) {
    case 0x20B:
        if (*(s32 *)(DAT_0076449c + 0xC40) == 0) {
            var_2 = (u8 *)((s32)&D_00634CB0 +
                           ((arg0 & 0xFFFF) * 0x14));
        } else {
            var_2 = (u8 *)((s32)&D_006350B0 +
                           ((arg0 & 0xFFFF) * 0x14));
        }
        break;
    case 0x215:
        var_2 = (u8 *)((s32)&D_006350B0 +
                       ((arg0 & 0xFFFF) * 0x14));
        break;
    default:
        var_2 = (u8 *)((s32)&D_006348B0 +
                       ((arg0 & 0xFFFF) * 0x14));
        break;
    }
    if ((*(s32 *)(var_2 + 0) == 0) &&
        (*(s32 *)(var_2 + 4) == 0)) {
        var_2 = NULL;
    }
    return var_2;
}

// Intent: Return the formation record for an index. [inferred]
// FUN_0022CED0
u8 *btlFormationGetRecord(s32 arg0)
{
    return H_Cdvd_GetArchiveEntry(*(u8 **)(DAT_0076449c + 0xB90), arg0 & 0xFFFF, 0);
}

// Intent: Return the action anchor height for a unit. [inferred]
// FUN_0022CF00
f32 btlUnitGetActionAnchorHeight(u8 *arg0, u8 *arg1, u16 arg2) {
    s32 temp_3;
    u16 temp_2;

    if (!(*(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return -1.0f;
    }
    if (*(u8 *)(arg1 + 0xA2) != 1) {
        return -1.0f;
    }
    temp_3 = arg2 & 0xFFFF;
    if ((temp_3 != 4) && (temp_3 != 0xC) &&
        (temp_3 != 5) && (temp_3 != 7)) {
        return -1.0f;
    }
    temp_2 = *(u16 *)(arg1 + 0xA4);
    switch (temp_2) {
    case 0x100:
        return 100.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x101:
        return 25.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x102:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x103:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x110:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x111:
        return 150.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x104:
        return 50.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x105:
        return 200.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x106:
        return 250.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x10F:
        return 250.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x107:
        return 200.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x108:
        return 300.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x10A:
        return 500.0f + (*(f32 *)(arg1 + 0x90) *
                         *(f32 *)(arg1 + 0x2C));
    case 0x113:
        return 75.0f + (*(f32 *)(arg1 + 0x90) *
                        *(f32 *)(arg1 + 0x2C));
    case 0x109:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x112:
    default:
        goto fail;
    }
fail:
    return -1.0f;
}

// Intent: Select the formation slot for the action's unit. [inferred]
// FUN_0022D200
/* Measured: 824/832 bytes, one resolved relocation, zero differences;
 * the remaining eight retail bytes are zero alignment. */
s32 btlActionSelectFormationSlot(u8 *action)
{
    u8 *global;
    u8 *unit;
    u16 unitId;
    u16 skill;

    global = iGpffffb3ac;
    if ((*(u32 *)(global + 0xC) & 0x200000) == 0) {
        return 0;
    }
    if ((*(u16 *)(action + 0x1A) & 1) == 0) {
        return 0;
    }
    unit = *(u8 **)(action + 0x30);
    if (*(u8 *)(unit + 0xA2) != 1) {
        return 0;
    }
    unitId = *(u16 *)(unit + 0xA4);
    switch (unitId) {
    case 0x100:
        skill = *(u16 *)(action + 0x6E);
        return skill == 0x160 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x103:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x166 || skill == 0x167 || skill == 0x168) {
            return *(s32 *)(global + 0xBF0);
        }
        return *(s32 *)(global + 0xBE0);
    case 0x104:
        skill = *(u16 *)(action + 0x6E);
        return skill == 0x169 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x106:
    case 0x10F:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x16D || skill == 0x173 || skill == 0x174 ||
            skill == 0x175 || skill == 0x176 || skill == 0x177) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x172 ? *(s32 *)(global + 0xBF4) : *(s32 *)(global + 0xBE0);
    case 0x105:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x16B) {
            return *(s32 *)(global + 0xBF0);
        }
        if (skill == 0x16A) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x16C ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x108:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x17A) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x17C ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x10A:
    case 0x113:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x17F || skill == 0x186) {
            return *(s32 *)(global + 0xBF0);
        }
        return skill == 0x180 ? *(s32 *)(global + 0xBF0) : *(s32 *)(global + 0xBE0);
    case 0x10B:
    case 0x10E:
        skill = *(u16 *)(action + 0x6E);
        if (skill == 0x181 || skill == 0x18B || skill == 0x182 || skill == 0x185) {
            return *(s32 *)(global + 0xBF0);
        }
        return *(s32 *)(global + 0xBE0);
    default:
        return *(s32 *)(global + 0xBE0);
    }
}

// Intent: Report whether an action has a formation slot. [inferred]
// FUN_0022D540
s32 btlActionHasFormationSlot(u8 *arg0, u8 *arg1) {
    u16 temp_3;
    u8 *temp_4;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 0;
    }
    if (!(*(u16 *)(arg0 + 0x1A) & 1)) {
        return 0;
    }
    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) != 1) {
        return 0;
    }
    temp_3 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_3) {
    case 0x112:
    case 0x109:
        *(s32 *)(arg1 + 0) = *(s32 *)(temp_6 + 0xBE4);
        *(s32 *)(arg1 + 4) = *(s32 *)(DAT_0076449c + 0xBE8);
        *(s32 *)(arg1 + 8) = *(s32 *)(DAT_0076449c + 0xBEC);
        return 1;
    default:
        return 0;
    }
}

/* measured: 1412B / 1424B window, all 59 relocations exact; twelve
   retail zero-alignment bytes. Keep the real unused source input and the
   explicit unsigned counter update with its signed clamp interpretation. */
// Intent: Update the unit HP gauge from the packet. [inferred]
// FUN_0022D600
void btlUnitUpdateHpGauge(void *source, u8 *packet, s32 *hpDelta)
{
    u8 *unit;
    u8 *resource;
    void *model;
    u32 hp;
    u32 maxHp;
    u32 remaining;
    s32 percentage;
    RwV3d scale;
    RwV3d translation;

    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0)
        return;
    unit = *(u8 **)(packet + 0x30);
    if (*(u8 *)(unit + 0xA2) != 1)
        return;
    switch (*(u16 *)(unit + 0xA4)) {
    case 0x102:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    case 0x103:
        resource = resrcMngFindResById(*(u8 **)(iGpffff9db0 + 8), 0x2804);
        if (resource == NULL || *(void **)(resource + 0x144) == NULL)
            break;
        hp = *(u16 *)(*(u8 **)(*(u8 **)(packet + 0x30) + 0xA64) + 8);
        maxHp = datCalcMaxHp(*(DatUnit **)(*(u8 **)(packet + 0x30) + 0xA64));
        scale.x = *(f32 *)(*(u8 **)(packet + 0x30) + 0x2C);
        scale.y = *(f32 *)(*(u8 **)(packet + 0x30) + 0x2C);
        scale.z = *(f32 *)(*(u8 **)(packet + 0x30) + 0x2C);
        translation.x = 0.0f;
        translation.y = 0.0f;
        translation.z = -450.0f;
        if (hp < maxHp) {
            mdlScale(*(Model **)(resource + 0x144), &scale, 0);
            mdlTranslateMatrix(*(RwMatrix **)(resource + 0x144), &translation, 2);
            model = *(void **)(resource + 0x144);
            mdlSetFrameColorByName(model, (s32)D_006355C0, 0xFF);
        }
        if (hp * 100 <= maxHp * 50) {
            mdlScale(*(Model **)(resource + 0x144), &scale, 0);
            mdlTranslateMatrix(*(RwMatrix **)(resource + 0x144), &translation, 2);
            model = *(void **)(resource + 0x144);
            mdlSetFrameColorByName(model, (s32)D_006355E0, 0xFF);
        }
        if (hp * 100 <= maxHp * 75) {
            mdlScale(*(Model **)(resource + 0x144), &scale, 0);
            mdlTranslateMatrix(*(RwMatrix **)(resource + 0x144), &translation, 2);
            model = *(void **)(resource + 0x144);
            mdlSetFrameColorByName(model, (s32)D_00635600, 0xFF);
        }
        break;
    case 0x104:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    case 0x105:
        if (!datGetFlag(0x15C0)) {
            if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
                *(s8 *)(iGpffffb3ac + 0xC12) = 3;
            else
                *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        } else {
            remaining = func_001064f0(0x7A);
            remaining += (u32)*hpDelta;
            if ((s32)remaining <= 0) {
                btlEncounterSetSequence((s32)btlEncounterResetSlots, (s32)btlEncounterWaitIdle, (s32)packet);
                remaining = 0;
            }
            func_00106550(0x7A, remaining);
        }
        break;
    case 0x106:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000) &&
            *(s16 *)(iGpffffb3ac + 0xC34) == 0)
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        if (*(s16 *)(iGpffffb3ac + 0xC34) == 0 || *hpDelta >= 0)
            break;
        packet = btlUnitFindInSideById(1, 0x10F);
        if (packet == NULL)
            break;
        datCalcAddHp(*(DatUnit **)(packet + 0xA64), *hpDelta);
        packet = btlActionFindByUnit((s32)packet);
        /* The paired unit has an active packet; retail deliberately falls through. */
    case 0x10F:
        if (*(s16 *)(iGpffffb3ac + 0xC34) == 0)
            break;
        if (*(s16 *)(iGpffffb3ac + 0xC34) == 1)
            percentage = 40;
        else if (*(s16 *)(iGpffffb3ac + 0xC34) == 2)
            percentage = 60;
        else
            percentage = 100;
        if (btlCond_MYHP(packet, 100 - percentage) ||
            *(u16 *)(*(u8 **)(*(u8 **)(packet + 0x30) + 0xA64) + 8) < 2)
            btlEncounterSetSequence((s32)btlEncounterStartSequence, (s32)btlEncounterFinishStep, (s32)packet);
        break;
    case 0x107:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    case 0x10B:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    case 0x112:
        if (datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100000))
            *(s8 *)(iGpffffb3ac + 0xC12) = 3;
        else
            *(s8 *)(iGpffffb3ac + 0xC12) = -1;
        break;
    }
}

// Intent: Select the unit's record table by battle id. [inferred]
// FUN_0022DB90
void btlUnitSelectRecordTable(u8 *arg0) {
    u16 id;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if ((*(s32 *)(temp_6 + 0xC) & 0x200000) &&
        (temp_5 = *(u8 **)(arg0 + 0x30), *(u8 *)(temp_5 + 0xA2) == 1)) {
        id = *(u16 *)(temp_5 + 0xA4);
        switch (id) {
        case 0x102:
            *(u8 **)(temp_6 + 0xB98) = D_0062A5F0;
            return;
        case 0x10D:
            *(u8 **)(temp_6 + 0xB98) = D_0062AD40;
            return;
        case 0x103:
            *(u8 **)(temp_6 + 0xB98) = D_0062B490;
            return;
        case 0x110:
            *(u8 **)(temp_6 + 0xB98) = D_0062BBE0;
            return;
        case 0x111:
            *(u8 **)(temp_6 + 0xB98) = D_0062C330;
            break;
        }
    }
}

/* measured: 2164B / 2176B window, 74 code and 20 table relocations exact.
   Twelve bytes are retail zero alignment. Keep node declared before started:
   reversing them swaps saved-register uses in nine retail instructions. */
// Intent: Apply packet flags to the unit state. [inferred]
// FUN_0022DC70
void btlUnitApplyPacketFlags(u8 *packet)
{
    u8 *node;
    s32 started;
    u8 *unit;
    s32 *counter;

    if ((*(u32 *)(DAT_0076449c + 0xC) & 0x200000) == 0)
        return;
    unit = *(u8 **)(packet + 0x30);
    if (unit[0xA2] != 1) {
        switch (btlCurrentUnitId()) {
        case 0x215:
            if (*(u16 *)(packet + 0x6C) == 2 && *(u16 *)(packet + 0x6E) == 0x115)
                btlEncounterSetSequence((s32)btlEncounterResetUnit, (s32)func_0022bac0, (s32)packet);
            break;
        }
        return;
    }
    switch (*(u16 *)(unit + 0xA4)) {
    case 0x100:
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x160)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x101:
        if (*(u16 *)(packet + 0x6C) == 2 || *(u16 *)(packet + 0x6C) == 1) {
            if (*(u16 *)(packet + 0x6E) == 0x161)
                *(s8 *)(DAT_0076449c + 0xC14) = 12;
            else
                *(s8 *)(DAT_0076449c + 0xC14) = -1;
        }
        break;
    case 0x102:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062A5F0;
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x163)
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
            else if (*(u16 *)(packet + 0x6E) == 0x162)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x10D:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062AD40;
        break;
    case 0x103:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062B490;
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x166)
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
            else if (*(u16 *)(packet + 0x6E) == 0x167)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else if (*(u16 *)(packet + 0x6E) == 0x168)
                *(s8 *)(DAT_0076449c + 0xC18) = 14;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x110:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062BBE0;
        break;
    case 0x111:
        *(u8 **)(DAT_0076449c + 0xB98) = D_0062C330;
        break;
    case 0x104:
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x169)
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x105:
        if (*(u16 *)(packet + 0x6C) == 2) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x16B:
                *(s8 *)(DAT_0076449c + 0xC10) = 14;
                *(s8 *)(DAT_0076449c + 0xC13) = 14;
                *(s8 *)(DAT_0076449c + 0xC28) = 14;
                *(s8 *)(DAT_0076449c + 0xC22) = 14;
                *(s8 *)(DAT_0076449c + 0xC1A) = 14;
                *(s8 *)(DAT_0076449c + 0xC12) = 15;
                *(s8 *)(DAT_0076449c + 0xC18) = 17;
                *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) |= 0x20;
                break;
            case 0x16A:
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                break;
            case 0x16C:
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                break;
            default:
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
                break;
            }
        }
        break;
    case 0x106:
        if (*(u16 *)(packet + 0x6C) == 2 || *(u16 *)(packet + 0x6C) == 1) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x16E:
            case 0x16F:
            case 0x170:
            case 0x171:
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
                *(s8 *)(DAT_0076449c + 0xC14) = -1;
                *(u32 *)(DAT_0076449c + 0xC) |= 0x400000;
                *(u16 *)(DAT_0076449c + 0x18) |= 2;
                break;
            default:
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
                *(s8 *)(DAT_0076449c + 0xC14) = -1;
                break;
            }
        }
        break;
    case 0x107:
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x178)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    case 0x108:
        if (*(u16 *)(packet + 0x6C) == 2) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x17B:
            case 0x184:
                btlEncounterSetSequence((s32)btlActionRunPresentation, (s32)btlEncounterWaitCleared, (s32)packet);
                *(u16 *)(packet + 0x6C) = 8;
                btlActionSetState((BtlAction *)packet, 25);
                *(s32 *)(DAT_0076449c + 0xC38) = 3;
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
                break;
            case 0x17A:
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                break;
            case 0x17C:
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                break;
            default:
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
                break;
            }
        }
        started = 0;
        counter = (s32 *)(DAT_0076449c + 0xC38);
        if (*counter > 0) {
            *counter -= 1;
            if (*(s32 *)(DAT_0076449c + 0xC38) <= 0) {
                node = *(u8 **)(DAT_0076449c + 0x174);
                while (node != NULL) {
                    if ((*(u16 *)(node + 0x1A) & 1) != 0) {
                        unit = *(u8 **)(node + 0x30);
                        if ((*(u32 *)(unit + 0x9C) & 8) != 0 &&
                            datCalcChkBadStatus((s32)*(u8 **)(unit + 0xA64), 0x100) == 0)
                            break;
                    }
                    node = *(u8 **)(node + 0x450);
                }
                if (node != NULL) {
                    btlEncounterSetSequence((s32)btlActionRunMotionSequence, (s32)btlEncounterReleaseFlags, (s32)packet);
                    started = 1;
                }
            }
        }
        counter = (s32 *)(DAT_0076449c + 0xC3C);
        if (*counter > 0 && started == 0) {
            *counter -= 1;
            if (*(s32 *)(DAT_0076449c + 0xC3C) <= 0 && datGetFlag(0x1435) != 0)
                btlEncounterSetSequence((s32)btlEncounterStartCameraState, (s32)btlEncounterWaitReleaseEvents, (s32)packet);
        }
        break;
    case 0x10A:
    case 0x113:
        if (*(u16 *)(packet + 0x6C) == 2) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x17D:
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
                break;
            case 0x17E:
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
                break;
            case 0x17F:
            case 0x186:
                *(s8 *)(DAT_0076449c + 0xC10) = 14;
                *(s8 *)(DAT_0076449c + 0xC13) = 14;
                *(s8 *)(DAT_0076449c + 0xC28) = 14;
                *(s8 *)(DAT_0076449c + 0xC22) = 14;
                *(s8 *)(DAT_0076449c + 0xC1A) = 14;
                *(s8 *)(DAT_0076449c + 0xC12) = 14;
                *(s8 *)(DAT_0076449c + 0xC18) = 18;
                *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) |= 0x20;
                break;
            case 0x180:
                *(s8 *)(DAT_0076449c + 0xC10) = -1;
                *(s8 *)(DAT_0076449c + 0xC13) = -1;
                *(s8 *)(DAT_0076449c + 0xC28) = -1;
                *(s8 *)(DAT_0076449c + 0xC22) = -1;
                *(s8 *)(DAT_0076449c + 0xC1A) = -1;
                *(s8 *)(DAT_0076449c + 0xC12) = -1;
                *(s8 *)(DAT_0076449c + 0xC18) = -2;
                *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) &= ~0x20;
                break;
            default:
                if (*(s8 *)(DAT_0076449c + 0xC10) == 14)
                    *(s8 *)(DAT_0076449c + 0xC18) = 17;
                else
                    *(s8 *)(DAT_0076449c + 0xC18) = -1;
                break;
            }
        }
        break;
    case 0x10B:
    case 0x10E:
        if (*(u16 *)(packet + 0x6C) == 2) {
            if (*(u16 *)(packet + 0x6E) == 0x10B) {
                *(s8 *)(DAT_0076449c + 0xC18) = 12;
                *(u32 *)(DAT_0076449c + 0xC) |= 0x400000;
                *(u16 *)(DAT_0076449c + 0x18) |= 7;
            } else if (*(u16 *)(packet + 0x6E) == 0x185)
                *(s8 *)(DAT_0076449c + 0xC18) = 4;
            else if (*(u16 *)(packet + 0x6E) == 0x182)
                *(s8 *)(DAT_0076449c + 0xC18) = 13;
            else
                *(s8 *)(DAT_0076449c + 0xC18) = -1;
        }
        break;
    }
}

// Intent: Report whether the action matches the expected skill. [inferred]
// FUN_0022E4F0
s32 btlActionMatchesSkill(u8 *arg0, s32 arg1) {
    u16 temp_4_2;
    u8 *temp_4;
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 0;
    }
    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) != 1) {
        return 0;
    }
    temp_4_2 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_4_2) {
    case 0x102:
        if (arg1 == 0x163) {
            return 1;
        }
        goto block_25;
    case 0x100:
        if (arg1 == 0x160) {
            return 1;
        }
        goto block_25;
    case 0x103:
        if (arg1 == 0x166) {
            return 1;
        }
        if (arg1 == 0x167) {
            return 1;
        }
        goto block_25;
    case 0x10A:
    case 0x113:
        if (*(s8 *)(temp_6 + 0xC10) == 0xE) {
            return 1;
        }
        if (arg1 == 0x17E) {
            return 1;
        }
        goto block_25;
    case 0x108:
        if (arg1 == 0x17C) {
            return 1;
        }
        goto block_25;
    }
block_25:
    return 0;
}

/* measured: first complete C candidate, 1172/1184 bytes with twelve zero
   alignment bytes; all 28 relocations resolved and no executable differences.
   Enqueue always receives the target, including the four unconditional calls
   for battle 0x215. Stat results and the status-clear mask are explicit. */
// Intent: Apply the encounter roster to the unit. [inferred]
// FUN_0022E630
s32 btlUnitApplyEncounterRoster(u8 *arg0)
{
    u8 *unit;
    if ((*(s32 *)(DAT_0076449c + 0xC) & 0x200000) == 0) {
        return 0;
    }
    unit = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(unit + 0xA2) != 1) {
        switch (btlCurrentUnitId()) {
        case 0x214:
            datPersonaClearRoster();
            datPersonaAddRosterMember(0xE0);
            datPersonaSelectRosterMemberById(0xE0);
            btlUnitInitChild(unit, 0xE0);
            func_00106d40(1, 0, 4);
            *(u16 *)(arg0 + 0x18) |= 0x40;
            break;
        case 0x215:
            datPersonaClearRoster();
            datPersonaAddRosterMember(0xE1);
            datPersonaSelectRosterMemberById(0xE1);
            btlUnitInitChild(unit, 0xE1);
            datSetUnitHp(1, (s16)datCalcMaxHpById(1));
            datSetUnitSp(1, (s16)datCalcMaxSpById(1));
            datCalcClearBadStatusById(1, -1);
            *(u16 *)(arg0 + 0x18) |= 0x40;
            break;
        }
        return 0;
    }
    switch (*(u16 *)(unit + 0xA4)) {
    case 0x100:
        *(u32 *)(unit + 0x9C) |= 0x4000;
        break;
    case 0x102:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        break;
    case 0x104:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        **(u16 **)(unit + 0xA64) |= 0x20;
        break;
    case 0x105:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        break;
    case 0x106:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        **(u16 **)(unit + 0xA64) |= 0x20;
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        btlActionQueuePush(arg0);
        break;
    case 0x10F:
        *(u16 *)(arg0 + 0x1A) &= ~8;
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        *(u32 *)(unit + 0x9C) &= ~8;
        *(u32 *)(unit + 0x9C) |= 0x2000;
        **(u16 **)(unit + 0xA64) |= 0x20;
        *(u16 *)(unit + 0x9D8) |= 0x20;
        btlActionQueuePush(arg0);
        break;
    case 0x107:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        break;
    case 0x109:
        *(u16 *)(arg0 + 0x1A) |= 0x200;
        *(u16 *)(arg0 + 0x1A) |= 0x10;
        btlUnitInitChild(unit, 0xCE);
        break;
    case 0x10A:
        *(u16 *)(arg0 + 0x1A) |= 0x100;
        btlActionQueuePush(arg0);
        break;
    case 0x10B:
        **(u16 **)(unit + 0xA64) |= 0x20;
        *(u32 *)(unit + 0x9C) |= 0x8000;
        break;
    case 0x10E:
        *(u32 *)(unit + 0x9C) |= 0x2000;
        *(u32 *)(unit + 0x9C) &= ~0x8000;
        if (btlCurrentUnitId() != 0x215) {
            **(u16 **)(unit + 0xA64) |= 0x20;
            *(u16 *)(arg0 + 0x1A) |= 0x100;
            btlActionQueuePush(arg0);
        } else {
            datSetFlag(0x15C0, 1);
            *(u16 *)(arg0 + 0x1A) |= 0x2000;
            btlActionQueuePush(arg0);
            btlActionQueuePush(arg0);
            btlActionQueuePush(arg0);
            btlActionQueuePush(arg0);
        }
        break;
    case 0x112:
        *(u32 *)(unit + 0x9C) |= 0x8000;
        *(u16 *)(arg0 + 0x1A) |= 0x10;
        btlUnitInitChild(unit, 7);
        break;
    case 0x113:
        **(u16 **)(unit + 0xA64) |= 0x20;
        break;
    }
    return 1;
}

// Intent: Realign enemy cells for battle 0x202. [inferred]
// FUN_0022EAD0
s32 btlUnitRealignCells(void) {
    struct {
        s32 sp20;
        s32 sp24;
        f32 sp28;
    } temps;
    u8 *var_16;

    if (!( *(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return 0;
    }
    switch (btlCurrentUnitId()) {
    case 0x202:
        var_16 = *(u8 **)(DAT_0076449c + 0x180);
        goto loop_check;
loop_body:
        if (*(u16 *)(var_16 + 0xA4) == 0x10D) {
            temps.sp20 = 0x439B0000;
            temps.sp24 = 0;
            temps.sp28 = fGpffff834c;
            btlTargetPositionToCell((s16 *)(var_16 + 0x94), (s16 *)(var_16 + 0x96),
                          (f32 *)&temps.sp20);
            btlUnitSetPos(var_16, &temps.sp20);
        }
        var_16 = *(u8 **)(var_16 + 0xA6C);
loop_check:
        if (var_16 != NULL) {
            goto loop_body;
        }
        break;
    default:
        break;
    }
    return 1;
}

/* measured: 2428B / 2432B window; all 115 relocations resolve exactly.
   The remaining four bytes are retail zero alignment. Keep the single-case
   action switch, model reloads before each callback, and structured list loop. */
// Intent: Apply packet effects to the unit by battle id. [inferred]
// FUN_0022EBA0
s32 btlUnitApplyPacketEffects(u8 *packet)
{
    u8 *unit;
    u8 *other;
    u8 *target;
    u8 *node;
    void *model;
    u32 index;
    RtQuat rotation;

    if ((*(u32 *)(DAT_0076449c + 0xC) & 0x200000) == 0)
        return 1;
    unit = *(u8 **)(packet + 0x30);
    if (unit[0xA2] != 1)
        return 1;
    switch (*(u16 *)(unit + 0xA4)) {
    case 0x105:
        if (*(u16 *)(packet + 0x6C) == 2) {
            switch (*(u16 *)(packet + 0x6E)) {
            case 0x16A:
                *(s8 *)(DAT_0076449c + 0xC10) = -1;
                *(s8 *)(DAT_0076449c + 0xC13) = -1;
                *(s8 *)(DAT_0076449c + 0xC28) = -1;
                *(s8 *)(DAT_0076449c + 0xC22) = -1;
                *(s8 *)(DAT_0076449c + 0xC1A) = -1;
                *(s8 *)(DAT_0076449c + 0xC12) = -1;
                break;
            }
        }
        if (*(s8 *)(DAT_0076449c + 0xC10) == 0xE)
            *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) |= 0x20;
        else
            *(u16 *)(*(u8 **)(packet + 0x30) + 0x9D8) &= ~0x20;
        break;
    case 0x106:
        if (*(u16 *)(packet + 0x6C) != 2)
            break;
        other = btlUnitFindInSideById(1, 0x10F);
        if (other == 0 || *(u8 **)(other + 0xA00) == 0)
            break;
        switch (*(u16 *)(packet + 0x6E)) {
        case 0x16E:
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636C0, 0);
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636C8, 0);
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636D0, 255);
            *(s16 *)(DAT_0076449c + 0xC34) = 1;
            **(u16 **)(unit + 0xA64) |= 0x20;
            target = btlActionFindByUnit((s32)other);
            *(u16 *)(target + 0x1A) &= ~0x400;
            datCalcAddHp(*(DatUnit **)(other + 0xA64), 0xFFFFFFF);
            btlUnitSetMotion(other, 0, 0, 1.0f, 1);
            btlUnitShowModel(other);
            break;
        case 0x16F:
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636C0, 0);
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636C8, 255);
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636D0, 255);
            *(s16 *)(DAT_0076449c + 0xC34) = 2;
            **(u16 **)(unit + 0xA64) |= 0x20;
            target = btlActionFindByUnit((s32)other);
            *(u16 *)(target + 0x1A) &= ~0x400;
            datCalcAddHp(*(DatUnit **)(other + 0xA64), 0xFFFFFFF);
            btlUnitSetMotion(other, 0, 0, 1.0f, 1);
            btlUnitShowModel(other);
            break;
        case 0x170:
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636C0, 255);
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636C8, 255);
            model = *(void **)(other + 0xA00);
            mdlSetFrameColorByName(model, (s32)D_007636D0, 255);
            /* fall through */
        case 0x171:
            *(s16 *)(DAT_0076449c + 0xC34) = 3;
            **(u16 **)(unit + 0xA64) |= 0x20;
            datCalcAddHp(*(DatUnit **)(other + 0xA64), 0xFFFFFFF);
            btlUnitUpdateStatusMotion(other, 0);
            btlUnitSetMotion(other, 0, 0, 1.0f, 1);
            *(u8 **)(DAT_0076449c + 0xB98) = D_0062E070;
            target = btlActionFindByUnit((s32)other);
            *(u16 *)(packet + 0x1A) &= ~8;
            *(u32 *)(unit + 0x9C) &= ~8;
            *(u16 *)(target + 0x1A) |= 8;
            *(u16 *)(target + 0x1A) &= ~0x400;
            *(u32 *)(other + 0x9C) |= 8;
            if (*(u16 *)(packet + 0x6E) == 0x171) {
                *(u32 *)(other + 0x9C) &= ~0x2000;
                func_003dc740(&rotation, (const RwV3d *)D_0060A0E0, 180.0f, 0);
                btlUnitSetRot((BtlUnit *)other, &rotation);
                *(u32 *)(other + 0x9C) |= 0x2000;
                btlUnitShowModel(other);
            }
            break;
        }
        break;
    case 0x108:
        if (*(u16 *)(packet + 0x6C) != 2 || *(u16 *)(packet + 0x6E) != 0x17A)
            break;
        if (datGetFlag(0x15C0) != 0) {
            datSetFlag(0x15C5, 1);
            datSetFlag(0x15C6, 0);
            datSetFlag(0x15C7, 0);
            datSetFlag(0x15C8, 0);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x15C1) != 0) {
            datSetFlag(0x15C5, 0);
            datSetFlag(0x15C6, 1);
            datSetFlag(0x15C7, 0);
            datSetFlag(0x15C8, 0);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x15C2) != 0) {
            datSetFlag(0x15C5, 0);
            datSetFlag(0x15C6, 0);
            datSetFlag(0x15C7, 1);
            datSetFlag(0x15C8, 0);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x15C3) != 0) {
            datSetFlag(0x15C5, 0);
            datSetFlag(0x15C6, 0);
            datSetFlag(0x15C7, 0);
            datSetFlag(0x15C8, 1);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x15C4) != 0) {
            datSetFlag(0x15C5, 0);
            datSetFlag(0x15C6, 0);
            datSetFlag(0x15C7, 0);
            datSetFlag(0x15C8, 0);
            datSetFlag(0x15C5 + datCalcRandomBelow(4), 1);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x1435) != 0)
            *(s32 *)(DAT_0076449c + 0xC3C) = 3;
        break;
    case 0x10A:
    case 0x113:
        if (*(u16 *)(packet + 0x6E) != 0x180)
            break;
        node = *(u8 **)(DAT_0076449c + 0x174);
        while (node != 0) {
            if ((*(u16 *)(node + 0x1A) & 1) != 0) {
                unit = *(u8 **)(node + 0x30);
                if ((*(u32 *)(unit + 0x9C) & 8) != 0 && *(u8 **)(unit + 0xA64) != 0)
                    datCalcClearBuffLevel(*(u8 **)(unit + 0xA64), 0x14);
            }
            node = *(u8 **)(node + 0x450);
        }
        break;
    case 0x10E:
        if (*(u16 *)(packet + 0x6E) != 0x181)
            break;
        *(u32 *)(DAT_0076449c + 0x10) |= 0x20000000;
        target = *(u8 **)(packet + 0x88);
        if (target != 0) {
            *(u32 *)(*(u8 **)(target + 0x30) + 0x9C) &= ~8;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x40) = iGpffffb45c;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x44) = iGpffffb45c;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x48) = iGpffffb45c;
            btlUnitSetColor((BtlUnit *)*(u8 **)(target + 0x30), iGpffffb45c);
            datCalcClearBadStatus((s32)*(u8 **)(*(u8 **)(target + 0x30) + 0xA64), 0xFFF7FFFF);
            unit = *(u8 **)(target + 0x30);
            if ((*(u32 *)(unit + 0x98) & 2) != 0)
                *(u16 *)(unit + 0x9D8) |= 0x10;
        } else {
            index = 0;
            goto targets_check;
targets_body:
            target = *(u8 **)(packet + index * 4 + 0x38);
            if (*(u8 **)(DAT_0076449c + 0x170) == target)
                *(u32 *)(DAT_0076449c + 0x10) |= 0x10000000;
            *(u32 *)(*(u8 **)(target + 0x30) + 0x9C) &= ~8;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x40) = iGpffffb45c;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x44) = iGpffffb45c;
            *(RwRGBA *)(*(u8 **)(target + 0x30) + 0x48) = iGpffffb45c;
            btlUnitSetColor((BtlUnit *)*(u8 **)(target + 0x30), iGpffffb45c);
            datCalcClearBadStatus((s32)*(u8 **)(*(u8 **)(target + 0x30) + 0xA64), 0xFFF7FFFF);
            unit = *(u8 **)(target + 0x30);
            if ((*(u32 *)(unit + 0x98) & 2) != 0)
                *(u16 *)(unit + 0x9D8) |= 0x10;
            index++;
targets_check:
            if (index < *(u16 *)(packet + 0x6A))
                goto targets_body;
        }
        break;
    }
    return 1;
}

// Intent: React to the death of unit 0x102 with an animation. [inferred]
// FUN_0022F520
s32 btlUnitReactToDeath(void)
{
    struct {
        s64 a;
        s64 b;
        s64 c;
    } sp30;
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    if ((*(s32 *)(DAT_0076449c + 0xC) & 0x200000) == 0) {
        return 0;
    }
    temp_2 = btlCurrentUnitId();
    switch (temp_2) {
    case 0x202: {
        u8 *var_17;
        u8 *temp_16;
        temp_2_2 = btlUnitFindInSideById(1, 0x102);
        if ((temp_2_2 == NULL) ||
            (datCalcIsDead(*(s32 **)(temp_2_2 + 0xA64), 0) != 0)) {
            btlTargetClearResultBuffer((u8 *)&sp30);
            *(s32 *)&sp30 = 0xFFF00001;
            var_17 = *(u8 **)(DAT_0076449c + 0x174);
            goto loop_0022f520_14_check;
loop_0022f520_14_body:
            if ((*(u16 *)(var_17 + 0x1A) & 1) != 0) {
                temp_16 = *(u8 **)(var_17 + 0x30);
                if ((*(u8 *)(temp_16 + 0xA2) == 1) &&
                    (*(u16 *)(temp_16 + 0xA4) != 0x102) &&
                    (datCalcIsDead(*(s32 **)(temp_16 + 0xA64), 0) == 0)) {
                    btlPacketEnqueue(
                        (u8 *)btlTargetCreateDataPacket((s32)(u32)var_17, (s32)(u32)var_17,
                                            (void *)&sp30, 1, 1),
                        1);
                    btlPacketEnqueue(
                        btlUnitCreateAnimPacket(temp_16, 2, 0, 0, 1.0f),
                        1);
                }
            }
            var_17 = *(u8 **)(var_17 + 0x450);
loop_0022f520_14_check:
            if (var_17 != NULL) {
                goto loop_0022f520_14_body;
            }
            return 1;
        }
        goto block_0022f520_27;
    }
    case 0x203: {
        u8 *temp_17;
        u8 *var_16;
        temp_2_3 = btlUnitFindInSideById(1, 0x103);
        if ((temp_2_3 == NULL) ||
            (datCalcIsDead(*(s32 **)(temp_2_3 + 0xA64), 0) != 0)) {
            btlTargetClearResultBuffer((u8 *)&sp30);
            *(s32 *)&sp30 = 0xFFF00001;
            var_16 = *(u8 **)(DAT_0076449c + 0x174);
            goto loop_0022f520_25_check;
loop_0022f520_25_body:
            if ((*(u16 *)(var_16 + 0x1A) & 1) != 0) {
                temp_17 = *(u8 **)(var_16 + 0x30);
                if ((*(u8 *)(temp_17 + 0xA2) == 1) &&
                    (*(u16 *)(temp_17 + 0xA4) != 0x103) &&
                    (datCalcIsDead(*(s32 **)(temp_17 + 0xA64), 0) == 0)) {
                    btlPacketEnqueue(
                        (u8 *)btlTargetCreateDataPacket((s32)(u32)var_16, (s32)(u32)var_16,
                                            (void *)&sp30, 1, 1),
                        1);
                    btlPacketEnqueue(
                        btlUnitCreateAnimPacket(temp_17, 2, 0, 0, 1.0f),
                        1);
                }
            }
            var_16 = *(u8 **)(var_16 + 0x450);
loop_0022f520_25_check:
            if (var_16 != NULL) {
                goto loop_0022f520_25_body;
            }
            return 1;
        }
        goto block_0022f520_27;
    }
    default:
        goto block_0022f520_27;
    }
block_0022f520_27:
    return 0;
}

// Intent: Return the entry position for a unit. [inferred]
// FUN_0022F7D0
s32 btlUnitGetEntryPosition(u8 *arg0, u8 *arg1) {
    s32 temp_2;
    u8 *temp_2_2;
    u8 *temp_4;

    temp_2 = btlCurrentUnitId();
    switch (temp_2) {
    case 0x208:
        temp_2_2 = (u8 *)btlActionGetActiveOrQueueFront();
        if (temp_2_2 != NULL) {
            temp_4 = *(u8 **)(*(u8 **)(temp_2_2 + 0x30) + 0xA64);
            if ((temp_4 != NULL) && (datCalcChkBadStatus((s32)temp_4, 0x100) == 0)) {
                return 0;
            }
        }
        btlUnitGetGridSphereCenter((BtlUnit *)(*(u8 **)(*(u8 **)(DAT_0076449c + 0x170) + 0x30)),
                      (RwV3d *)arg1);
        return 1;
    case 0x10E:
        *(s32 *)(arg1 + 0) = 0;
        *(s32 *)(arg1 + 4) = 0;
        *(f32 *)(arg1 + 8) = (f32)0xBB8;
        return 1;
    default:
        return 0;
    }
}

// FUN_0022F8B0
s32 func_0022f8b0(u8 *arg0, s32 arg1)
{
    u8 *temp_2;

    if (*(s32 *)(DAT_0076449c + 0xC) & 0x200000) {
        goto check_flag;
    }
    return 0;
check_flag:
    if (*(u16 *)(arg0 + 0x1A) & 1) {
        goto load_temp;
    }
    return 0;
load_temp:
    temp_2 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_2 + 0xA2) == 1) {
        goto check_id;
    }
    return 0;
check_id:
    switch (*(u16 *)(temp_2 + 0xA4)) {
    case 0x104:
        if (arg1 != 0x169) {
            goto fail;
        }
        goto done;
    default:
        goto fail;
    }
done:
    return 1;
fail:
    return 0;
}

// FUN_0022F950
/* measured: scoped propagation preserves the post-query skill reload
 * before the unit move; canonical s16 arguments leave two swapped words
 * without it. The query receives its real action pointer. */
// Intent: Report whether the unit's skill is blocked. [inferred]
#pragma push
/* measured: btlUnitSkillBlocked MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
s32 btlUnitSkillBlocked(u8 *arg0, u8 *arg1) {
    s32 paired;
    s16 skill;
    u8 *unit;

    if (*(s32 *)(DAT_0076449c + 0xC) & 0x200000) {
        if (*(u16 *)(iGpffffb3e0 +
                    (*(u16 *)(arg1 + 0xA4) * 0x58)) & 1) {
            paired = btlActionHasNoTargetClass((u32)arg0);
            skill = *(s16 *)(arg0 + 0x6E);
            unit = arg1;
            return (btlTargetCanSelectEntry(unit, skill, paired) != 0) ^ 1;
        }
        if ((btlActionHasNoTargetClass((u32)arg0) == 0) &&
            (*(u16 *)(iGpffffb3e0 +
                     (*(u16 *)(arg1 + 0xA4) * 0x58)) & 0x20)) {
            return 1;
        }
        if (btlBossSkillResultBlocked(arg0) == 1) {
            return 1;
        }
        if (btlBossTargetBlocked(arg0) == 0) {
            return 1;
        }
    }
    return 0;
}

#pragma pop
// Intent: Report whether the slot is open for the unit. [inferred]
// FUN_0022FA90
s32 btlUnitSlotIsOpen(u8 *arg0, s16 arg1)
{
    u8 *temp_6;

    temp_6 = DAT_0076449c;
    if (!( *(s32 *)(temp_6 + 0xC) & 0x200000)) {
        return 1;
    }
    if (!(*(u16 *)(arg0 + 0x1A) & 1)) {
        return 1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 1) {
        return 1;
    }
    /* Form the EE byte address without arithmetic on an invented pointer. */
    return *(s8 *)((u32)(s32)arg1 + (u32)temp_6 + 0xC10) != -2;
}

// Intent: Report whether the encounter skips the presentation. [inferred]
// FUN_0022FB10
s32 btlEncounterSkipsPresentation(void)
{
    s32 temp_2;

    if (!(*(s32 *)(DAT_0076449c + 0xC) & 0x200000)) {
        return 1;
    }
    temp_2 = btlCurrentUnitId();
    switch (temp_2) {
    case 0x209:
    case 0x20C:
    case 0x20D:
        return 1;
    default:
        return 0;
    }
}

