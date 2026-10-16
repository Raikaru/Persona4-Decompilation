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
extern void func_001fae60(s32 initialize, s32 update, s32 packet);
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
extern void btlCameraUpdateEffectList();

u8 *kwlnTaskGetTaskByName(s8 *name);

extern u8 D_006290F0[];

u32 kwlnTaskGetWork(void *task);
extern u8 D_00629698[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void chkmemAllocSiteTag();
extern void memset();

extern s32 btlResultHeroLvUpRun(u8 *task);
extern void func_002230a0(u8 *task);
extern void btlLogoDraw(u8 *drawData, s32 workAddress, void *callback);
extern s32 btlResultOverlayTick(u8 *task);
extern u8 D_00795F20[];
extern u8 D_006296D0[];
extern u8 D_008C0240[0x94];
extern void func_00460ac0(u8 *list, u8 *node);
extern u16 datPersonaCountValidMembers(void);
extern u16 *datPersonaRosterSlot(s16 slot);
extern u8 *shdPersonaTaskCreate(s32 parent, s32 priority, s32 mode, s32 layout, s32 option);
extern void shdPersonaSetPersonaId(u8 *window, s32 value);
extern void shdPersonaSetOrigin(u8 *window, f32 *position);
extern void shdPersonaStartSlideIn(u8 *window);
extern void shdPersonaSetDisplayState(u8 *window, s32 mode, u32 persona, s8 option);
extern u8 *shdPersonaLevelUpCreate(s32 parent, s32 window, u8 *record, s32 payload, s32 option, s32 *messages);
extern u32 shdPersonaLevelUpIsDone(u8 *child);
extern s32 shdPersonaDestroyTask(u8 *child);
extern s32 datMemberNoticeTryBegin(s32 mode);
extern s32 btlShuffleOverlayIdle(void);
extern void kAssertFail(const void *file, u32 line);
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
extern void btlResultOverlayOnEvent();
extern void btlResultOverlayDestroy(u8 *task);

extern u8 D_00629640[];
extern u8 D_00629738[];
extern s32 btlResultFriendPsUpdate(u8 *task);
extern void btlResultSummaryOnEventAlt();
extern void btlResultSummaryDestroy(u8 *task);
extern s32 btlUnitMotionClassValue(u8 *arg0, s32 arg1);
extern s32 btlUnitIsUnavailable(u8 *arg0, s32 arg1, s32 arg2);
extern void btlCameraWaitMotionFrames(u8 *arg0);
extern void btlCameraSelectPreset(int param_1);
extern s32 func_00243ce0(u8 *arg0);
extern void btlCameraFrameTarget(u8 *arg0, f32 arg1, f32 arg2);
extern void btlCameraFrameWrapTargetWalk(u8 *arg0, f32 arg1, f32 arg2);
extern u16 btlTargetGetUnitIndex(BtlTarget *target);
extern s32 btlActionAnyTargetHitRowFlagged(u8 *arg0);
extern void btlCameraApplyPosePair(u8 *arg0);
extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *out);
extern void btlTargetBlendVectors(void *out, void *first, void *second);
extern void btlCameraCopyPoseTarget(f32 *out, f32 *in);
extern f32 fGpffff80fc;
extern f32 fGpffff80dc;
extern f32 tanf(f32 angle);
extern u32 btlCameraClampOffsetToLimit(f32 *pose, f32 *out);
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
extern void btlCameraSetLimitFrame(u8 *camera, f32 angleLimit, s32 reverseSide, s32 forceActorSide);
extern void btlCameraFrameActorTarget(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration);
extern s32 btlActionSkillReachesTargets(u8 *action);

extern u8 D_006296B0[];
extern u8 D_006296E8[];

extern u8 D_00629700[];

void btlCameraUpdateFrame(void);

extern u8 *DAT_0076449c;
extern void btlCameraFrameAim(u8 *arg0);
extern s32 btlCameraUnitAnimFinished(u8 *arg0, u8 *arg1);
extern void btlUnitSetChildValue(BtlUnitStateWork *work, u16 value);
extern void btlUnitFaceTarget(BtlUnit *unit, const RwV3d *target);
extern s32 btlCameraSelectMode(u8 *camera);
extern void btlCameraUpdateMode(u8 *camera);
extern s32 btlUnitSkillBlocked(u8 *action, u8 *subordinate);
extern void btlCameraSelectEncounterPreset(u8 *camera);

extern u8 *btlUnitRecordFindByActionUID(u64 uid, u64 mask);
extern void datSetFlag(s32 arg0, s32 arg1);
extern s32 kwlnTaskIsLinked(void *target);
extern u8 *btlActionFindByUnit(s32 arg0);
extern void btlTargetSetDefeatState(u8 *arg0, s32 arg1);
extern void btlSoundStopBgmIfEnabled(void);


u8 *func_00455ea0(u8 *arg0, s32 arg1, s32 *arg2);



extern void (*jtbl_008873EC[])(void *arg0);
extern void shdPersonaFinishPhase(u8 *arg0);
extern void btlSoundFadeOutBgm(s16 fadeDuration);
extern void sdkSndPlayCue(s32 arg0, s32 arg1);
extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
extern void btlMainCurveReset(u16 *param_1, f32 *param_2);
extern void btlCameraCopyPoseSnapshot(f32 *arg0, f32 *arg1);
extern void btlCameraCopyPose(f32 *arg0, f32 *arg1);
extern void btlMainCurveSetPoses(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4);
extern void btlCameraSetDuration(u8 *arg0, f32 arg1);
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

extern u8 *btlCameraCreateSetStatePacket(u8 *arg0, s32 arg1);
extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern u8 *btlPacketCreateEffectCounter(s32 arg0, s32 arg1);
extern void btlCameraStartEffect(u8 *arg0, u8 *arg1, s32 arg2);
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern u8 D_00632240[];
extern u8 *btlUnitFindInSideById(s32 arg0, s32 arg1);
extern void btlUnitHideModel(u8 *arg0);
extern void datCalcClearAllBuffs(u8 *arg0);
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
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
extern BtlPacket *btlSoundCreateStreamPacket(u16 channel, const char *streamName);
extern BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern void btlFormationSetPlacement(u32 arg0);
extern u8 D_006354B0[];
extern u8 *iGpffffb444;
extern u8 *iGpffffb3ac;
extern u8 *scrStartProcedureIndex(s32 arg0, u8 *arg1, s32 arg2);
extern void func_0029dfe0(u8 *arg0, u8 *arg1);
extern u8 *func_0010d740(s16 arg0);
extern void itfMesWindowSetString(u8 *arg0, s32 arg1, u8 *arg2);
extern void kwlnTaskAddChild(u8 *arg0, u8 *arg1);
extern void btlCameraFrameActionCutscene(u8 *camera);
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

extern BtlPacket *btlEffectCreateSpriteFramePacket(u32 unit, u16 effect);
extern BtlPacket *btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
extern BtlPacket *btlUnitCreateRotateTowardUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u32 flags);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rotation, u32 flags);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *targetPosition, f32 speed, u32 flags);
extern u32 datCalcIsDead(void *unit, s32 hpDelta);
extern s32 datCalcIsStatusBlocked(u16 *unit);
extern s32 btlUnitSlotValueOrOne(s32 action);
extern u8 D_006354C0[], D_006354D0[], D_00635500[];
extern BtlPacket *btlFormationCreateSlotPacket(u16 group, u16 mask);
extern f32 fGpffff80e4;
extern f32 btlTargetQuatAngle(void *first, void *second);
extern s32 CrossfadeRequest(s16 frames);
extern s32 datCalcGetLevelById(s32 arg0);

// Intent: Report whether a shuffle child task has its cancel-request bit (0x4) set in its flag word [inferred]
// FUN_002218E0
s32 btlShuffleTaskIsCancelRequestedFor(KwlnTask *task)
{
    return (*(u16 *)kwlnTaskGetWork(task) & 4) != 0;
}
// Intent: Report whether the logo task named D_006290F0 exists. [inferred]
// FUN_00221910
s32 btlLogoTaskExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_006290F0) != 0;
}

// Intent: Report whether a shuffle child task is still loading its sprite blob (flag 0x10 clear; btlShuffle.c sets it when the load completes) [inferred]
// FUN_00221940
s32 btlShuffleTaskIsLoading(KwlnTask *task)
{
    return ((*(u16 *)kwlnTaskGetWork(task) & 0x10) != 0) ^ 1;
}
// Intent: Advance the logo stage flags and set the stage byte from the counter. [inferred]
// FUN_00221970
s32 btlLogoUnlockStage(u8 *arg0)
{
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;

    temp_2 = datCalcGetLevelById(1) & 0xFF;
    temp_3 = 0;
    if (temp_2 >= 0x1E) {
        if (datGetFlag(0x1202) == 0) {
            arg0[0x44] = 0xC;
            datSetFlag(0x1202, 1);
            datSetFlag(0x1201, 1);
            datSetFlag(0x1200, 1);
            temp_3 = 1;
            goto exit;
        }
    }
    if (temp_2 >= 0x19) {
        if (datGetFlag(0x1201) == 0) {
            arg0[0x44] = 0xA;
            datSetFlag(0x1201, 1);
            datSetFlag(0x1200, 1);
            temp_3 = 1;
            goto exit;
        }
    }
    if (temp_2 >= 0x14) {
        if (datGetFlag(0x1200) == 0) {
            arg0[0x44] = 8;
            datSetFlag(0x1200, 1);
            temp_3 = 1;
        }
    }
exit:
    temp_4 = temp_3;
    return temp_4;
}
typedef struct LogoVec2 {
    f32 x;
    f32 y;
} LogoVec2;
typedef struct LogoColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} LogoColor;

extern void sdkSpriteDrawOnceScaled(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);

static inline void logoDrawTitle(u8 *work, LogoVec2 ofs, LogoColor col, LogoVec2 pos)
{
    s32 res = *(s32 *)(work + 0x50);
    f32 x;
    f32 y;
    f32 qx;

    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    sdkSpriteDrawOnceScaled(*(s32 *)(work + 0x54), 0x1D, x, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - x), (s16)(pos.y - y));
    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    qx = (207.0f + x) - 6.0f;
    sdkSpriteDrawOnceScaled(res, 0xB2, qx, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - qx), (s16)(pos.y - y));
    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    qx = (300.0f + x) - 6.0f;
    sdkSpriteDrawOnceScaled(res, 0xB3, qx, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - qx), (s16)(pos.y - y));
    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    qx = (314.0f + x) - 6.0f;
    sdkSpriteDrawOnceScaled(res, 0xB3, qx, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - qx), (s16)(pos.y - y));
}

/* Logo title draw. Each call re-derives the sprite position from its
 * by-value origin and offset, so the y offset is recomputed per call as in
 * retail. The coloured-quad loops and the title loop share one counter;
 * opt_lifetimes splits it so the title counter colours after the helper's
 * resource. opt_loop_invariants hoists the colour constants and the invariant
 * parameter copies out of the loops, as retail does. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// Intent: Draw the logo title sprites at the given alpha. [inferred]
// FUN_00222210
void btlLogoDrawTitle(u8 *work, u32 alpha)
{
    extern f32 btlShuffleCalcWave(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern void func_00364c50(void);
    extern void func_00364c70(void);
    extern void PrimDrawPoints(u8 *arg0, u8 *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4);
    extern f32 fGpffff8384;
    extern f32 fGpffff8388;
    f32 var_f24;
    f32 var_f22;
    f32 var_f21;
    f32 var_f23;
    f32 var_f20;
    f32 coords[6];
    LogoVec2 pos;
    LogoVec2 base;
    LogoColor colors[3];
    LogoColor color;
    s32 i;

    if ((*(u16 *)work & 8) == 0) {
        var_f24 = 1.0f - btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 0.0f, 6.0f, 1);
        var_f22 = 1.0f - btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 0.0f, 6.0f, 1);
        var_f21 = 1.0f - btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 7.0f, 17.0f, 1);
        var_f23 = 1.0f - btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 13.0f, 25.0f, 1);
        if (*(u16 *)(work + 0x46) >= 7) {
            if (++*(u16 *)(work + 0x48) >= 0x28) {
                *(u16 *)(work + 0x48) = 0;
            }
            var_f20 = btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x48), 0.0f, 40.0f, 0);
        }
    } else {
        var_f24 = 0.0f;
        var_f22 = 0.0f;
        var_f21 = 0.0f;
        var_f23 = 0.0f;
        if (++*(u16 *)(work + 0x48) >= 0x28) {
            *(u16 *)(work + 0x48) = 0;
        }
        var_f20 = btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x48), 0.0f, 40.0f, 0);
    }
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);

    pos.x = (f32)0x109 + (f32)0x177 * var_f22;
    pos.y = 0.0f;
    coords[0] = pos.x;
    coords[1] = pos.y;
    coords[2] = (f32)0x177 + pos.x;
    coords[3] = pos.y;
    coords[4] = (f32)0x177 + pos.x;
    coords[5] = (f32)0x119 + pos.y;
    for (i = 0; i < 3; i++) {
        colors[i].r = 0xFF;
        colors[i].g = 0xFF;
        colors[i].b = 0xFF;
        colors[i].a = alpha;
    }
    func_00364c50();
    PrimDrawPoints((u8 *)colors, (u8 *)coords, 0.0f, 3, 5, 0);
    func_00364c70();

    pos.x = 348.0f + 292.0f * var_f24;
    pos.y = 0.0f;
    coords[0] = pos.x;
    coords[1] = pos.y;
    coords[2] = 292.0f + pos.x;
    coords[3] = pos.y;
    coords[4] = 292.0f + pos.x;
    coords[5] = 220.0f + pos.y;
    for (i = 0; i < 3; i++) {
        colors[i].r = 0xED;
        colors[i].g = 0x36;
        colors[i].b = 0x11;
        colors[i].a = alpha;
    }
    func_00364c50();
    PrimDrawPoints((u8 *)colors, (u8 *)coords, 0.0f, 3, 5, 0);
    func_00364c70();

    base.x = (220.0f + fGpffff8384 * var_f21) - 9.0f;
    base.y = -94.0f + fGpffff8388 * var_f21;
    pos.x = -(394.0f * var_f20);
    pos.y = 0.0f;
    color.r = 0xFF;
    color.g = 0xD4;
    color.b = 0;
    color.a = alpha;
    for (i = 0; i < 3; i++) {
        logoDrawTitle(work, pos, color, base);
        pos.x = pos.x + 394.0f;
    }

    base.x = 1.0f + ((f32)0x185 + fGpffff8384 * var_f23);
    base.y = (-5.0f + fGpffff8388 * var_f23) - 1.0f;
    pos.x = 0.0f;
    pos.y = 0.0f;
    color.r = 0xFF;
    color.g = 0xFF;
    color.b = 0xFF;
    color.a = alpha;
    logoDrawTitle(work, pos, color, base);
}
#pragma pop
/* 896/896 bytes and all 17 relocations resolve exactly.
 * Keep the opaque byte branch-local, snapshot coordinates before opacity
 * conversion, and pack the color before preparing the overlay dimensions. */
#pragma push
#pragma opt_propagation off
// Intent: Draw the logo scene and title for one frame. [inferred]
// FUN_00222D20
void btlLogoDraw(u8 *drawData, s32 workAddress, void *callback)
{
    typedef struct { f32 x, y; } Vec2fLocal;
    typedef struct { s32 lo, hi; } DescriptorPair;
    typedef union { Vec2fLocal draw; DescriptorPair descriptor; } OriginPair;
    extern void btlLogoDrawTitle(u8 *work, u32 alpha);
    extern void sdkRenderStateSetDefault(void);
    extern void nLineDrawSet(Vec2fLocal arg0, s32 arg1, s32 arg2, f32 arg3);
    extern void datScreenWipeDraw(u8 *arg0);
    extern s32 datScreenWipeTexture(u8 *arg0);
    extern void datScreenWipeGetPositions(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    extern void datScreenWipeGetScale(u8 *arg0, f32 *arg1);
    extern f32 btlShuffleCalcWave(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void func_00364680(f32 depth, f32 x, f32 y, f32 shadowX, f32 shadowY,
                              f32 width, f32 height, s32 color, s32 texture,
                              s32 shadow, s32 mode);
    extern void sflDataDrawEntry(DescriptorPair origin, f32 depth, s32 alpha, s16 *descriptor);
    extern s32 RpSkyRenderStateSet(s32 state, s32 value);
    extern s32 sdkSndStartChannel(s16 channel, const char *name);
    extern u8 D_00629680[];
    extern f32 fGpffff838c;
    u8 *work;
    u32 alpha;
    s32 texture;
    f32 phase;
    OriginPair origin;
    f32 position[2];
    f32 scale[2];

    work = (u8 *)workAddress;
    if ((*(u16 *)work & 2) != 0) {
        if ((*(u16 *)work & 8) == 0) {
            if (++*(u16 *)(work + 0x46) >= 54) {
                *(u16 *)work |= 8;
            }
            alpha = (u8)(255.0f * btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 0.0f, 5.0f, 1));
            if (*(u16 *)(work + 0x46) == 14) {
                sdkSndStartChannel(2, (const char *)D_00629680);
            }
        } else {
            u8 opaque = 255;
            alpha = opaque;
        }
        sdkRenderStateSetDefault();
        origin.draw.x = 0.0f;
        origin.draw.y = 0.0f;
        nLineDrawSet(origin.draw, alpha, 0x16, 0.0f);
        btlLogoDrawTitle(work, alpha);
        datScreenWipeDraw(*(u8 **)(work + 0x4C));
        origin.draw.x = 0.0f;
        origin.draw.y = 0.0f;
        texture = datScreenWipeTexture(*(u8 **)(work + 0x4C));
        if (texture != 0) {
            if (*(u16 *)(work + 0x46) >= 24) {
                u32 overlayAlpha;
                f32 opacity;
                f32 drawX;
                f32 drawY;
                s32 color;
                phase = btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 27.0f, 54.0f, 2);
                datScreenWipeGetPositions(*(u8 **)(work + 0x4C), 0, (u8 *)position, 0);
                datScreenWipeGetScale(*(u8 **)(work + 0x4C), scale);
                drawY = position[1];
                drawX = position[0];
                opacity = fGpffff838c * (f32)alpha;
                overlayAlpha = (u8)(opacity * (1.0f - phase));
                color = (s32)(overlayAlpha | 0xFFFFFF00U);
                func_00364680(0.0f, drawX, drawY, drawX, drawY,
                              256.0f * scale[0], 512.0f * scale[1],
                              color, texture, 0, 1);
                RpSkyRenderStateSet(3, 0x717FB);
                RpSkyRenderStateSet(2, 0x44);
            }
        }
        sflDataDrawEntry(origin.descriptor, 0.0f, alpha, (s16 *)(work + 0x58));
    }
}
#pragma pop
// Intent: Create the logo title task and its child draw. [inferred]
// FUN_002230E0
s32 btlLogoTitleCreate(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    chkmemAllocSiteTag(&D_00629698, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x74, 0x40000);
    memset(temp_2, 0, 0x74);
    temp_16 = (s32)((s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_00629640), 0xF, 0, 0, btlResultHeroLvUpRun, func_002230a0, (u8 *)(temp_2)));
    temp_2_2 = (u16 *)(kwlnTaskGetWork((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x3C) = (u16 *)(temp_2_2);
    memset((u8 *)(temp_2) + 0xC, 0, 0x30);
    *(void (**)(u8 *, s32, void *))((u8 *)(temp_2) + 0x14) = btlLogoDraw;
    *(u8 **)((u8 *)(temp_2) + 0x1C) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
// Intent: Advance the logo title task state after its overlay finishes. [inferred]
// FUN_002231E0
void btlLogoTitleAdvance(KwlnTask *task) {
    u16 *temp_2;

    temp_2 = (u16 *)(kwlnTaskGetWork(task));
    *(s32 *)((u8 *)(temp_2) + 8) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        btlShuffleStartOverlay();
        *(s32 *)((u8 *)(temp_2) + 4) = 4;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 5;
}

// Intent: Report whether the logo title task is ready (flag bit 1). [inferred]
// FUN_00223240
s32 btlLogoTitleIsReady(KwlnTask *task)
{
    return *(u16 *)kwlnTaskGetWork(task) & 1;
}
// Intent: Report whether the logo title task exists by name. [inferred]
// FUN_00223270
s32 btlLogoTitleExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_00629640) != 0;
}

// Intent: Run the result overlay state machine for one tick. [inferred]
// FUN_002232A0
/* 1036/1040 bytes; 26 code relocations and all nine switch entries exact. */
#pragma opt_propagation off
s32 btlResultOverlayTick(u8 *sdkTaskBytes)
{
    KwlnTask *task = (KwlnTask *)sdkTaskBytes;
    u8 *work;
    u8 *results;
    u8 *persona;
    u8 *payload;
    s32 index;
    s32 messages[11];
    f32 position[2];

    work = (u8 *)kwlnTaskGetWork(task);
    results = *(u8 **)(work + 0x40);
    *(u32 *)(work + 8) = 0;
    *(u32 *)(work + 0xC) = 0;
    func_00460ac0(D_00795F20, work + 8);

    switch (*(u32 *)(work + 4)) {
    case 0:
        *(s32 *)(work + 0x3C) = 0;
        *(s32 *)(work + 0x38) = (u16)datPersonaCountValidMembers();
        *(u8 **)(work + 0x4C) = shdPersonaTaskCreate(0, 15, 4, 5, 0);
        if (*(u8 **)(work + 0x4C) == 0) {
            kAssertFail(D_006296D0, 0x2F);
        }
        shdPersonaSetPersonaId(*(u8 **)(work + 0x4C), 0xAE);
        position[0] = 0.0f;
        position[1] = 19.0f;
        shdPersonaSetOrigin(*(u8 **)(work + 0x4C), position);
        shdPersonaStartSlideIn(*(u8 **)(work + 0x4C));
        *(s32 *)(work + 4) = 1;
        /* fall through */
    case 1:
        results += 0x60;
        while ((index = *(s32 *)(work + 0x3C)) < *(s32 *)(work + 0x38)) {
            u32 reward;

            persona = (u8 *)datPersonaRosterSlot((s16)index);
            reward = *(u32 *)(results + 8 + *(s32 *)(work + 0x3C) * 4);
            *(u32 *)(persona + 8) += reward;
            index = *(s32 *)(work + 0x3C);
            if (*(u8 *)(index * 0x88 + results + 0x38) > 0) {
                break;
            }
            *(s32 *)(work + 0x3C) = index + 1;
        }
        /* Constructor and transitions maintain 0 <= index <= count <= 12.
         * Consequently this arm always has a persona produced by the loop. */
        if (index != *(s32 *)(work + 0x38)) {
            s32 recordIndex;

            shdPersonaSetDisplayState(*(u8 **)(work + 0x4C), 1, (u32)persona, 0);
            messages[0] = 12;
            messages[1] = 0;
            messages[2] = 6;
            messages[3] = 9;
            messages[4] = 10;
            messages[5] = 11;
            messages[6] = 13;
            messages[7] = 14;
            messages[8] = 19;
            messages[9] = 20;
            messages[10] = 21;
            payload = func_00455ea0(
                *(u8 **)(*(u8 **)(work + 0x40) + 0x934), 0, 0);
            recordIndex = *(s32 *)(work + 0x3C);
            *(u8 **)(work + 0x50) = shdPersonaLevelUpCreate(
                (s32)task, *(s32 *)(work + 0x4C),
                results + recordIndex * 0x88 + 0x38,
                (s32)payload, 0, messages);
            *(u16 *)work |= 2;
            *(s32 *)(work + 4) = 2;
        } else if (*(u32 *)(*(u8 **)(work + 0x40) + 0x60) & 0x10) {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
        } else {
            *(u16 *)work &= 0xFFFE;
            *(s32 *)(work + 4) = 8;
            *(u16 *)work |= 4;
        }
        break;
    case 2:
        *(s32 *)(work + 4) = 3;
        /* fall through */
    case 3:
        if (shdPersonaLevelUpIsDone(*(u8 **)(work + 0x50)) == 0) {
            break;
        }
        shdPersonaDestroyTask(*(u8 **)(work + 0x50));
        *(s32 *)(work + 4) = 4;
        *(u16 *)(work + 0x48) = 0;
        /* fall through */
    case 4:
        if (++*(u16 *)(work + 0x48) < 45) {
            if ((*(u16 *)(D_008C0240 + 0xE) & 0x50) == 0) {
                if ((*(u16 *)(D_008C0240 + 0xC) & 0x10) == 0) {
                    break;
                }
                if (*(u16 *)(work + 0x48) < 4) {
                    break;
                }
            }
        }
        *(s32 *)(work + 0x3C) += 1;
        *(s32 *)(work + 4) = 1;
        break;
    case 5:
        if (datMemberNoticeTryBegin(1) != 0) {
            break;
        }
        *(u16 *)work &= 0xFFFE;
        *(s32 *)(work + 4) = 8;
        break;
    case 6:
        if (btlShuffleOverlayIdle() == 0) {
            break;
        }
        *(s32 *)(work + 4) = 7;
        /* fall through */
    case 7:
        if ((*(u16 *)work & 4) == 0) {
            if (++*(u16 *)(work + 0x48) < 5) {
                break;
            }
        }
        *(u16 *)work &= 0xFFFD;
        return -1;
    case 8:
    default:
        break;
    }
    return 0;
}
#pragma opt_propagation on
// Intent: Result overlay event callback; ignores events once the flag is set. [inferred]
// FUN_002236B0
void btlResultOverlayOnEvent(s32 arg0, u16 *arg1, s32 arg2)
{
    if ((*arg1 & 2) != 0) {
        return;
    }
}
// Intent: Destroy the result overlay task work. [inferred]
// FUN_002236C0
void btlResultOverlayDestroy(u8 *sdkTaskBytes)
{
    KwlnTask *task = (KwlnTask *)sdkTaskBytes;
    u8 *p;
    s32 h;

    p = (u8 *)kwlnTaskGetWork(task);
    if (*(u16 *)p & 4) {
        h = *(s32 *)(p + 0x4C);
        if (h != 0) {
            shdPersonaFinishPhase((u8 *)h);
            *(s32 *)(p + 0x4C) = 0;
        }
    }
    (*jtbl_008873EC)(p);
}

// Intent: Create the result overlay task. [inferred]
// FUN_00223730
s32 btlResultOverlayCreate(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    chkmemAllocSiteTag(&D_006296E8, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x54, 0x40000);
    memset(temp_2, 0, 0x54);
    temp_16 = (s32)((s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_006296B0), 0xF, 0, 0, btlResultOverlayTick, btlResultOverlayDestroy, (u8 *)(temp_2)));
    temp_2_2 = (u16 *)(kwlnTaskGetWork((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x40) = (u16 *)(temp_2_2);
    memset((u8 *)(temp_2) + 8, 0, 0x30);
    *(void (**)(u16 *))((u8 *)(temp_2) + 0x10) = (void (*)(u16 *))(btlResultOverlayOnEvent);
    *(u8 **)((u8 *)(temp_2) + 0x18) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
// Intent: Start the result overlay and set its state. [inferred]
// FUN_00223830
void btlResultOverlayStart(KwlnTask *task) {
    u16 *temp_2;

    temp_2 = (u16 *)(kwlnTaskGetWork(task));
    *(s16 *)((u8 *)(temp_2) + 0x48) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        btlShuffleStartOverlay();
        *(s32 *)((u8 *)(temp_2) + 4) = 6;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 7;
}

// Intent: Report whether the result overlay is ready. [inferred]
// FUN_00223890
s32 btlResultOverlayIsReady(KwlnTask *task)
{
    return *(u16 *)kwlnTaskGetWork(task) & 1;
}
// Intent: Report whether the result overlay task exists by name. [inferred]
// FUN_002238C0
s32 btlResultOverlayExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_006296B0) != 0;
}



// Intent: Result summary event callback (same body as the overlay callback). [inferred]
// FUN_00223ED0
void btlResultSummaryOnEventAlt(s32 arg0, u16 *arg1, s32 arg2)
{
    if ((*arg1 & 2) != 0) {
        return;
    }
}
// Intent: Destroy the result summary task work. [inferred]
// FUN_00223EE0
void btlResultSummaryDestroy(u8 *sdkTaskBytes)
{
    KwlnTask *task = (KwlnTask *)sdkTaskBytes;
    u8 *p;
    s32 h;

    p = (u8 *)kwlnTaskGetWork(task);
    h = *(s32 *)(p + 0x44);
    if (h != 0) {
        shdPersonaFinishPhase((u8 *)h);
        *(s32 *)(p + 0x44) = 0;
    }
    (*jtbl_008873EC)(p);
}

// Intent: Create the result summary task. [inferred]
// FUN_00223F40
s32 btlResultSummaryCreate(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    chkmemAllocSiteTag(&D_00629738, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x4C, 0x40000);
    memset(temp_2, 0, 0x4C);
    temp_16 = (s32)((s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_00629700), 0xF, 0, 0, btlResultFriendPsUpdate, btlResultSummaryDestroy, (u8 *)(temp_2)));
    temp_2_2 = (u16 *)(kwlnTaskGetWork((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x3C) = (u16 *)(temp_2_2);
    memset((u8 *)(temp_2) + 8, 0, 0x30);
    *(void (**)(u16 *))((u8 *)(temp_2) + 0x10) = (void (*)(u16 *))(btlResultSummaryOnEventAlt);
    *(u8 **)((u8 *)(temp_2) + 0x18) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
// Intent: Start the result summary task. [inferred]
// FUN_00224040
void btlResultSummaryStart(KwlnTask *task)
{
    u16 *temp_16;

    temp_16 = (u16 *)kwlnTaskGetWork(task);
    btlShuffleStartOverlay();
    *(s32 *)(temp_16 + 2) = 5;
}
// Intent: Report whether the result summary is ready. [inferred]
// FUN_00224080
s32 btlResultSummaryIsReady(KwlnTask *task)
{
    return *(u16 *)kwlnTaskGetWork(task) & 1;
}
// Intent: Report whether the result summary task exists by name. [inferred]
// FUN_002240B0
s32 btlResultSummaryExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_00629700) != 0;
}



#pragma push
#pragma opt_propagation off
/* Select the encounter camera's eye/focus preset from the actor's party
 * ordinal and the roster's highest-priority status. Preserve both complete
 * position/quaternion poses across the immediate/interpolated transition.
 * The presence predicate returns a signed halfword before conversion to the
 * unsigned preset index; this retains both retail narrowing operations.
 * Scoped propagation and distinct selector lifetimes reproduce native b210
 * O2: 876/880 bytes, 34 fully resolved relocations, four zero tail bytes.
 */
extern s32 func_00243d80(u8 *unitData);
extern s32 datCalcIsStatusBlocked(u16 *unitData);
extern void btlMainApplyUnitBaseColors(u8 *unit);
extern f32 fGpffff80e8;
extern u8 D_00634870[];
extern f32 D_00634874[];
extern f32 D_00634878[];
extern u8 D_0063487C[];

static inline s16 btlCameraPresetPresence(s32 present)
{
    return present != 0;
}

// Intent: Select the encounter camera preset from the party ordinal and roster status. [inferred]
// FUN_002240E0
void btlCameraSelectEncounterPreset(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    f32 z;
    u8 *enemy;
    s32 reset;
    s32 hasStatus;
    s32 hasPriorityStatus;
    u8 *unit;
    u16 variant;
    u8 *ally;
    f32 x;
    f32 y;
    struct EyeFocus { RwV3d eye; RwV3d focus; } *record;
    u8 *partyMember;
    u16 previousState;
    u32 ordinal;
    u16 partyIndex;

    previousState = *(u16 *)(iGpffffb3ac + 0x108);
    switch (previousState) {
    case 2:
    case 0x22:
    case 0x28:
    case 0x29:
        reset = 0;
        break;
    default:
        reset = 1;
        break;
    }
    if (*(s32 *)(camera + 0x148) != 0) {
        reset = 1;
        *(s32 *)(camera + 0x148) = 0;
    }
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    if (*(u8 *)(unit + 0xA2) != 0) {
        partyIndex = 0;
    } else {
        ordinal = 0;
        partyMember = *(u8 **)(iGpffffb3ac + 0x17C);
        while (partyMember != NULL) {
            if (unit == partyMember) {
                break;
            }
            ordinal = (u16)(ordinal + 1);
            partyMember = *(u8 **)(partyMember + 0xA68);
        }
        partyIndex = (u16)ordinal;
    }
    hasStatus = 0;
    hasPriorityStatus = 0;
    enemy = *(u8 **)(iGpffffb3ac + 0x180);
    while (enemy != NULL) {
        if ((*(u32 *)(enemy + 0x9C) & 8) != 0 &&
            *(u8 **)(enemy + 0xA64) != NULL &&
            func_00243d80(*(u8 **)(enemy + 0xA64)) != 0) {
            if (datCalcChkBadStatus(*(s32 *)(enemy + 0xA64), 0x100000) != 0) {
                hasStatus = 1;
            }
            if (datCalcIsStatusBlocked(*(u16 **)(enemy + 0xA64)) != 0) {
                hasPriorityStatus = 1;
            }
        }
        enemy = *(u8 **)(enemy + 0xA6C);
    }
    variant = hasPriorityStatus != 0 ? 2 : (u16)btlCameraPresetPresence(hasStatus);
    if (btlCurrentUnitId() == 0x208 && (u16)variant == 0) {
        ally = *(u8 **)(iGpffffb3ac + 0x178);
        while (ally != NULL) {
            if ((*(u32 *)(ally + 0x9C) & 8) != 0 &&
                *(u8 **)(ally + 0xA64) != NULL &&
                datCalcChkBadStatus(*(s32 *)(ally + 0xA64), 0x100) != 0) {
                variant = 2;
                break;
            }
            ally = *(u8 **)(ally + 0xA6C);
        }
    }
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (btlCurrentUnitId() != 0x215) {
        record = (struct EyeFocus *)(*(u8 **)(iGpffffb3ac + 0xB98) +
                 (u16)partyIndex * 0x48 + (u16)variant * 0x18);
        btlCameraLookAtQuat(&poses.secondRotation, &record->eye, &record->focus, D_0060A0E0);
        poses.second = record->eye;
    } else {
        btlCameraLookAtQuat(&poses.secondRotation, D_00634870, D_0063487C, D_0060A0E0);
        x = *(f32 *)D_00634870;
        y = D_00634874[0];
        z = D_00634878[0];
        poses.second.x = x;
        poses.second.y = y;
        poses.second.z = z;
    }
    if (reset != 0) {
        btlMainApplyUnitBaseColors(NULL);
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        btlMainCurveReset((u16 *)camera, (f32 *)&poses.second);
    } else {
        btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
        btlCameraSetDuration(camera, fGpffff80e8);
    }
}
#pragma pop
/* Select a skill camera preset from the roster status and actor party index.
 * The word-sized priority predicate and the later halfword preset have
 * separate lifetimes, preserving the retail narrowing and register reuse.
 * measured: native b210 -O2, 1312/1312 bytes and 46 resolved relocations.
 *
 * Original retail omission: with target mask 2, global flag 0x400, skill
 * classification 0 and encounter other than 0x215, the branch at 0x22466C
 * falls through to the final pose consumer without writing the second pose.
 * Preserve that path and its unwritten automatic storage. The corresponding
 * target-mask-1 path returns immediately; neither path is given new state.
 */
// Intent: Select the skill camera preset from the roster and actor party index. [inferred]
// FUN_00224450
void btlCameraSelectSkillPreset(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    extern s32 func_00243d80(u8 *unitData);
    extern s32 datCalcIsStatusBlocked(u16 *unitData);
    extern s32 btlCurrentUnitId(void);
    extern u32 btlEffectCollectGenusMask(s32 targets);
    extern void btlCameraReleaseOcclusion(u8 *camera);
    extern u8 D_00634890[];
    extern u8 D_0063489C[];
    u8 *battleWork;
    u16 previousState;
    u8 *enemy;
    s32 hasStatus;
    u32 hasPriorityStatus;
    u16 preset;
    s32 reset;
    u16 skill;
    s32 targetGroups;
    s32 classification;
    s32 unitData;
    s32 selectedPreset;
    u8 *ally;
    s32 targetMask;
    u8 *action;
    u8 *actor2;
    u8 *actor1;
    s32 partyIndex2;
    s32 ordinal2;
    u8 *partyMember2;
    s32 partyIndex1;
    u8 *partyMember1;
    s32 ordinal1;
    u8 *recordBase2;
    u8 *recordBase1;
    u8 *recordBase;
    u8 *record2;
    u8 *record1;
    u8 *record;

    *(s32 *)(DAT_0076449c + 0xC0C) = 0;
    battleWork = DAT_0076449c;
    previousState = *(u16 *)(battleWork + 0x108);
    switch (previousState) {
    case 2:
    case 0x21:
    case 0x28:
    case 0x29:
        reset = 0;
        break;
    default:
        reset = 1;
        break;
    }
    hasStatus = 0;
    hasPriorityStatus = 0;
    enemy = *(u8 **)(battleWork + 0x180);
    while (enemy != NULL) {
        if ((*(s32 *)(enemy + 0x9C) & 8) != 0) {
            unitData = *(s32 *)(enemy + 0xA64);
            if (unitData != 0 && func_00243d80((u8 *)unitData) != 0) {
                if (datCalcChkBadStatus(*(s32 *)(enemy + 0xA64), 0x100000) != 0) {
                    hasStatus = 1;
                }
                if (datCalcIsStatusBlocked(*(u16 **)(enemy + 0xA64)) != 0) {
                    hasPriorityStatus = 1;
                }
            }
        }
        enemy = *(u8 **)(enemy + 0xA6C);
    }
    if (hasPriorityStatus != 0) {
        selectedPreset = 2;
    } else {
        selectedPreset = (u16)btlCameraPresetPresence(hasStatus);
    }
    preset = selectedPreset & 0xFFFF;
    if (btlCurrentUnitId() == 0x208 && (preset & 0xFFFF) == 0) {
        ally = *(u8 **)(DAT_0076449c + 0x178);
        while (ally != NULL) {
            if ((*(s32 *)(ally + 0x9C) & 8) != 0) {
                unitData = *(s32 *)(ally + 0xA64);
                if (unitData != 0 && datCalcChkBadStatus(unitData, 0x100) != 0) {
                    preset = 2;
                    break;
                }
            }
            ally = *(u8 **)(ally + 0xA6C);
        }
    }
    action = *(u8 **)(camera + 0xE0);
    skill = *(u16 *)(action + 0x6E);
    targetGroups = btlEffectCollectGenusMask((s32)(action + 0x98)) & 0xFFFF;
    classification = btlSkillClassifyTargets(*(u8 **)(camera + 0xE0), 0, skill, 0) & 0xFFFF;
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    targetMask = targetGroups & 0xFFFF;
    if (targetMask == 2) {
        if ((*(s32 *)(DAT_0076449c + 0x10) & 0x400) != 0 && (classification & 0xFFFF) == 0) {
            btlCameraReleaseOcclusion(camera);
            *(s32 *)(DAT_0076449c + 0xC0C) = 1;
        } else {
            actor2 = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
            if (*(u8 *)(actor2 + 0xA2) != 0) {
                partyIndex2 = 0;
            } else {
                ordinal2 = 0;
                partyMember2 = *(u8 **)(DAT_0076449c + 0x17C);
                goto group2_party_check;
group2_party_body:
                if (actor2 == partyMember2) {
                    goto group2_party_done;
                }
                ordinal2 = (ordinal2 + 1) & 0xFFFF;
                partyMember2 = *(u8 **)(partyMember2 + 0xA68);
                goto group2_party_check;
group2_party_check:
                if (partyMember2 != NULL) {
                    goto group2_party_body;
                }
group2_party_done:
                partyIndex2 = ordinal2 & 0xFFFF;
            }
            recordBase2 = *(u8 **)(DAT_0076449c + 0xB98) + ((partyIndex2 & 0xFFFF) * 0x48) + ((preset & 0xFFFF) * 0x18);
            record2 = recordBase2 + 0x120;
            btlCameraLookAtQuat(&poses.secondRotation, record2, record2 + 0xC, D_0060A0E0);
            poses.second = *(RwV3d *)record2;
        }
    } else if (targetMask == 1) {
        if ((classification & 0xFFFF) != 0) {
            actor1 = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
            if (*(u8 *)(actor1 + 0xA2) != 0) {
                partyIndex1 = 0;
            } else {
                ordinal1 = 0;
                partyMember1 = *(u8 **)(DAT_0076449c + 0x17C);
                goto group1_party_check;
group1_party_body:
                if (actor1 == partyMember1) {
                    goto group1_party_done;
                }
                ordinal1 = (ordinal1 + 1) & 0xFFFF;
                partyMember1 = *(u8 **)(partyMember1 + 0xA68);
group1_party_check:
                if (partyMember1 != NULL) {
                    goto group1_party_body;
                }
group1_party_done:
                partyIndex1 = ordinal1 & 0xFFFF;
            }
            recordBase1 = *(u8 **)(DAT_0076449c + 0xB98) + ((partyIndex1 & 0xFFFF) * 0x48) + ((preset & 0xFFFF) * 0x18);
            record1 = recordBase1 + 0x240;
            btlCameraLookAtQuat(&poses.secondRotation, record1, record1 + 0xC, D_0060A0E0);
            poses.second = *(RwV3d *)record1;
        } else {
            btlCameraReleaseOcclusion(camera);
            *(s32 *)(DAT_0076449c + 0xC0C) = 1;
            return;
        }
    } else {
        recordBase = *(u8 **)(DAT_0076449c + 0xB98) + ((preset & 0xFFFF) * 0x18);
        record = recordBase + 0x360;
        btlCameraLookAtQuat(&poses.secondRotation, record, record + 0xC, D_0060A0E0);
        poses.second = *(RwV3d *)record;
    }
    if (btlCurrentUnitId() == 0x215) {
        btlCameraLookAtQuat(&poses.secondRotation, D_00634890, D_0063489C, D_0060A0E0);
        poses.second = *(RwV3d *)D_00634890;
    }
    if (reset != 0) {
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        btlMainCurveReset((u16 *)camera, (f32 *)&poses.second);
        return;
    }
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    btlCameraSetDuration(camera, 0.75f);
}
// Intent: Per-frame camera tick, run while the camera flag is set. [inferred]
// FUN_00224970
void btlCameraTickFrame(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC0C) != 0) {
        btlCameraUpdateFrame();
    }
}



// Intent: Apply actor and target pair height offsets and return the framing distance. [inferred]
// FUN_002249A0
/* measured: ordinary C, 1780/1792 bytes, 32 code relocations and zero
 * normalized differences; the remaining 12 bytes are zero tail alignment. */
f32 btlCameraApplyPairOffsets(u8 *actor, u8 *target, RwV3d *actorPosition, RwV3d *targetPosition)
{
    u32 actorKind;
    f32 height;

    btlUnitGetSphereWorldCenter((BtlUnit *)actor, actorPosition);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, targetPosition);

    actorKind = actor[0xA2];
    if (actorKind == 0 && target[0xA2] == 1) {
        switch (*(u16 *)(target + 0xA4)) {
        case 0x100:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 3.5f;
        case 0x101:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x102:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff8030 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8100 * height;
            return 4.5f;
        case 0x103:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 5.0f;
        case 0x110:
        case 0x111:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 5.0f;
        case 0x104:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8128 * height;
            return 4.5f;
        case 0x105:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x106:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.75f * height;
            return 5.0f;
        case 0x10F:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x107:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff813c * height;
            return 4.5f;
        case 0x108:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 5.0f;
        case 0x10A:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x112:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 4.5f;
        case 0x113:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 6.5f;
        }
    } else if (actorKind == 1 && target[0xA2] == 0) {
        switch (*(u16 *)(actor + 0xA4)) {
        case 0x100: {
            f32 coefficient;
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            coefficient = fGpffff8100;
            actorPosition->y = (0.0f + actorPosition->y) - coefficient * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + coefficient * height;
            return 4.5f;
        }
        case 0x102:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8100 * height;
            return 5.5f;
        case 0x110:
        case 0x111:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8030 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8128 * height;
            return 5.0f;
        }
    }
    return 3.5f;
}
// Intent: Frame the camera on the target with a distance offset and duration. [inferred]
// FUN_002250A0
/* 1688/1696 bytes; all 36 resolved code relocations exact. */
#pragma opt_scalarize off
void btlCameraFrameTarget(u8 *camera, f32 distanceOffset, f32 duration)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d basePosition;
    RwV3d focus;
    RwV3d offset;
    RwV3d direction;
    RwV3d eye;
    f32 baseXZ[2];
    f32 projectionXZ[2];
    struct {
        f32 perpendicular[2];
        f32 horizontal[2];
        f32 focusXZ[2];
        f32 eyeXZ[2];
        RtQuat yaw;
    } geometry;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *action;
    u8 *actor;
    u8 *target;
    u8 *farUnit;
    u8 *nearUnit;
    f32 framingScale;
    f32 actorRadius;
    f32 targetRadius;
    f32 length;
    f32 sideOffset;
    f32 along;
    f32 baseZ;
    f32 baseHeight;
    f32 side;
    f32 extent;
    f32 halfAngle;
    f32 distance;
    u16 flags;

    action = *(u8 **)(camera + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    framingScale = btlCameraApplyPairOffsets(actor, target, &actorPosition, &targetPosition);
    actorRadius = *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
    targetRadius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    geometry.horizontal[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    geometry.horizontal[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);

    if (*(u8 *)(actor + 0xA2) == 0) {
        btlTargetBlendVectors((u8 *)&geometry.yaw, (u8 *)&actorPosition, (u8 *)&targetPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &geometry.yaw);
        offset.x = offset.x * targetRadius;
        offset.y = offset.y * targetRadius;
        offset.z = offset.z * targetRadius;
        targetPosition.x = targetPosition.x + offset.x;
        targetPosition.y = targetPosition.y + offset.y;
        targetPosition.z = targetPosition.z + offset.z;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        nearUnit = actor;
        farUnit = target;
        basePosition = actorPosition;
        sideOffset = 1.25f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        along = fGpffff8128 * length;
        focus.x = direction.x * along;
        focus.y = direction.y * along;
        focus.z = direction.z * along;
        baseHeight = basePosition.y;
        eye.y = baseHeight;
    } else {
        btlTargetBlendVectors((u8 *)&geometry.yaw, (u8 *)&targetPosition, (u8 *)&actorPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &geometry.yaw);
        offset.x = offset.x * actorRadius;
        offset.y = offset.y * actorRadius;
        offset.z = offset.z * actorRadius;
        actorPosition.x = actorPosition.x + offset.x;
        actorPosition.y = actorPosition.y + offset.y;
        actorPosition.z = actorPosition.z + offset.z;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        nearUnit = target;
        farUnit = actor;
        basePosition = targetPosition;
        sideOffset = 0.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        along = fGpffff80fc * length;
        focus.x = direction.x * along;
        focus.y = direction.y * along;
        focus.z = direction.z * along;
        baseHeight = basePosition.y;
        eye.y = baseHeight;
    }
    focus.x = focus.x + targetPosition.x;
    focus.y = focus.y + targetPosition.y;
    focus.z = focus.z + targetPosition.z;
    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    side = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];
    if (!(side < 0.0f)) {
        eye.x = (0.0f + basePosition.x) + direction.z * sideOffset;
        baseZ = basePosition.z;
        eye.z = (0.0f + baseZ) - direction.x * sideOffset;
    } else {
        eye.x = (0.0f + basePosition.x) - direction.z * sideOffset;
        baseZ = basePosition.z;
        eye.z = (0.0f + baseZ) + direction.x * sideOffset;
    }
    btlCameraLookAtQuat(&poses.secondRotation, &eye, &focus, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1,
                           &poses.secondRotation);
    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    extent = btlTargetAngleBetween((u8 *)geometry.focusXZ, (u8 *)geometry.eyeXZ,
                          (u8 *)baseXZ, (u8 *)projectionXZ);
    extent = (0.0f + extent) + framingScale *
        (*(f32 *)(nearUnit + 0x90) * *(f32 *)(nearUnit + 0x2C));
    eye.x = projectionXZ[0];
    eye.y = baseHeight;
    eye.z = projectionXZ[1];
    halfAngle = 0.5f * *(f32 *)(camera + 0xB8);
    distance = extent / tanf(fGpffff8110 * halfAngle);
    distance = distance + distanceOffset;
    if (distance < 100.0f) {
        distance = 100.0f;
    }
    direction.x = direction.x * distance;
    direction.y = direction.y * distance;
    direction.z = direction.z * distance;
    poses.second.x = eye.x + direction.x;
    poses.second.y = eye.y + direction.y;
    poses.second.z = eye.z + direction.z;
    if (poses.second.y < 22.5f) {
        poses.second.y = 22.5f;
    }
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (!(btlTargetQuatAngle(&poses.firstRotation,
                        &poses.secondRotation) <= fGpffff80dc)) {
        btlCameraCopyPoseTarget((f32 *)&poses.first, (f32 *)&poses.second);
        flags = 3;
    } else {
        flags = 0xC3;
    }
    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), farUnit + 4,
                  (f32 *)&poses.second, 50.0f, flags);
    if (duration == 0.0f) {
        btlCameraCopyPoseTarget((f32 *)&poses.first, (f32 *)&poses.second);
        RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1,
                               &poses.firstRotation);
        direction.x = direction.x * 150.0f;
        direction.y = direction.y * 150.0f;
        direction.z = direction.z * 150.0f;
        poses.second.x = poses.first.x + direction.x;
        poses.second.y = poses.first.y + direction.y;
        poses.second.z = poses.first.z + direction.z;
        if (poses.second.y < 22.5f) {
            poses.second.y = 22.5f;
        }
        btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first,
                      (f32 *)&poses.second, 1);
        btlCameraSetDuration(camera, 2.0f);
    } else {
        btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first,
                      (f32 *)&poses.second, 1);
        btlCameraSetDuration(camera, duration);
    }
}
#pragma opt_scalarize on
// Intent: Choose the camera frame mode for a unit pair from the party flags. [inferred]
// FUN_00225740
void btlCameraFrameUnitPair(u8 *arg0)
{
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_16;
    u8 *base;
    extern s32 func_00243ce0(u8 *arg0);
    base = arg0;
    *(u16 *)(DAT_0076449c + 0xC00) = 0;
    temp_2 = *(u8 **)(base + 0xE0);
    temp_16 = *(u8 **)(temp_2 + 0x30);
    temp_4 = btlTargetGetUnitIndex((BtlTarget *)(temp_2 + 0x38));
    if (*(u8 *)(temp_16 + 0xA2) == 0) {
        if ((temp_4 & 0xFFFF & 1) == 0) {
            if (btlActionAnyTargetHitRowFlagged(*(u8 **)(base + 0xE0)) == 0) {
                btlCameraFrameTarget(base, 0.0f, 1.0f);
            }
        } else {
            btlCameraApplyPosePair(base);
            *(u16 *)(DAT_0076449c + 0xC00) = 1;
        }
    } else if ((temp_4 & 0xFFFF & 2) == 0) {
        if (func_00243ce0((u8 *)*(s32 *)(temp_16 + 0xA64)) != 0) {
            btlCameraFrameTarget(base, 0.0f, 1.0f);
            return;
        }
        btlCameraApplyPosePair(base);
        *(u16 *)(DAT_0076449c + 0xC00) = 1;
    }
}
// Intent: Tick the camera aim for the active action. [inferred]
// FUN_00225860
void btlCameraTickAim(u8 *arg0)
{
    u16 temp_5;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0xE0);
    if ((temp_3 != NULL) && ((*(u16 *)(temp_3 + 0x1A) & 1) != 0)) {
        temp_5 = *(u16 *)(DAT_0076449c + 0xC00);
        if (temp_5 == 1) {
            btlCameraFrameAim(arg0);
        }
    }
}

// Intent: Frame the camera on a wrapping target walk. [inferred]
// FUN_002258B0
/* Measured: 800/800 bytes, 20 resolved relocations, zero differences.
 * Disabling common-subexpression folding preserves the wrapping target walk. */
#pragma opt_common_subs off
void btlCameraFrameWrapTargetWalk(u8 *camera, f32 distanceOffset, f32 duration)
{
    u8 *action;
    u8 *unit;
    u8 *target;
    u32 index;
    f32 scale;
    f32 heightScale;

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL && (*(u16 *)(action + 0x1A) & 1) != 0) {
        if (action != NULL &&
            *(u8 *)((unit = *(u8 **)(action + 0x30)) + 0xA2) == 0) {
            index = 0;
            while ((action = *(u8 **)(camera + 0xE0)),
                   (u16)index < *(u16 *)(action + 0x6A)) {
                target = *(u8 **)(action + 0x38 + (u16)index * 4);
                target = *(u8 **)(target + 0x30);
                if (*(u8 *)(target + 0xA2) == 1) {
                    btlUnitFaceTarget((BtlUnit *)target, (const RwV3d *)(unit + 4));
                }
                index = (u16)(index + 1);
            }
        }
        unit = *(u8 **)(action + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            btlCameraSetLimitFrame(camera, 0.0f, 0, 1);
            return;
        }
        target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
        scale = 1.5f;
        heightScale = fGpffff803c;
        switch (*(u16 *)(unit + 0xA4)) {
        case 0x100:
            scale = 1.75f;
            heightScale = 0.0f;
            break;
        case 0x101:
            scale = 3.5f;
            heightScale = fGpffff8098;
            break;
        case 0x102:
            scale = 3.75f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8174;
            } else {
                heightScale = fGpffff8178;
            }
            break;
        case 0x103:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        case 0x104:
            scale = 4.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8030;
            } else {
                heightScale = fGpffff8178;
            }
            break;
        case 0x105:
            scale = 3.5f;
            heightScale = fGpffff8098;
            break;
        case 0x106:
            scale = 2.25f;
            heightScale = 0.0f;
            break;
        case 0x10F:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8118;
            } else {
                heightScale = 0.0f;
            }
            break;
        case 0x107:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        case 0x108:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = 0.0f;
            } else {
                heightScale = fGpffff817c;
            }
            break;
        case 0x10A:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = fGpffff8118;
            } else {
                heightScale = 0.0f;
            }
            break;
        case 0x10B:
            scale = 3.5f;
            heightScale = 0.0f;
            break;
        case 0x112:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        default:
            break;
        }
        btlCameraFrameActorTarget(camera, heightScale, scale, distanceOffset, duration);
    }
}
#pragma opt_common_subs on
// Intent: Frame the camera on a wrapped target with a default duration. [inferred]
// FUN_00225BD0
void btlCameraFrameWrapTarget(u8 *arg0)
{
    btlCameraFrameWrapTargetWalk(arg0, 0.0f, 2.0f);
}



// Intent: Tick the camera while waiting for the target motion. [inferred]
// FUN_00225C00
void btlCameraTickTargetWait(u8 *arg0)
{
    u8 *self;
    u8 *temp_3;

    self = arg0;
    temp_3 = *(u8 **)(self + 0xE0);
    if (temp_3 != NULL) {
        if (func_00243ce0((u8 *)*(s32 *)(*(u8 **)(temp_3 + 0x30) + 0xA64)) != 0) {
            if (btlUnitIsUnavailable(*(u8 **)(self + 0xE0), 0, 0) != 0) {
                btlCameraFrameWrapTargetWalk(self, 0.0f, 0.75f);
            } else {
                btlCameraFrameTarget(self, 0.0f, 0.75f);
            }
            arg0 = (u8 *)(s64)(s16)btlUnitMotionClassValue(
                *(u8 **)(*(u8 **)(self + 0xE0) + 0x30), 4);
            *(s16 *)(self + 0x10E) =
                btlUnitMotionHitFrames(*(u8 **)(*(u8 **)(self + 0xE0) + 0x30),
                              4, 1.0f, (s64)((u32)arg0 & 0xFFFF));
            *(s16 *)(self + 0x10C) = 0;
            *(s32 *)(self + 0x100) = *(s32 *)(*(u8 **)(self + 0xE0) + 0x38);
            return;
        }
        btlCameraWaitMotionFrames(self);
    }
}
/* measured 00225d00 plain-C reconstruction matches the complete 256-byte retail window at normalized_diff 0. */
#pragma optimization_level 1
// Intent: Tick the camera preset selection after the action flag. [inferred]
// FUN_00225D00
void btlCameraTickSelectPreset(u8 *arg0)
{
    u32 temp_4;
    s32 temp_3;
    u8 *temp_5;
    extern s32 func_00243ce0(u8 *arg0);

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if ((temp_5 != NULL) &&
        (*(u16 *)(temp_5 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x100) == *(s32 *)(temp_5 + 0x38)) &&
        ((*(u16 *)(temp_5 + 0x1A) & 1) != 0)) {
        if (func_00243ce0((u8 *)*(s32 *)(*(u8 **)(temp_5 + 0x30) + 0xA64)) == 0) {
            btlCameraSelectPreset((int)arg0);
            return;
        }
        temp_4 = *(u16 *)(arg0 + 0x10E);
        temp_3 = *(u16 *)(arg0 + 0x10C) + 1;
        *(u16 *)(arg0 + 0x10C) = temp_3;
        temp_3 = (u16)temp_3;
        if (temp_4 != temp_3) {
            return;
        }
        if (btlUnitIsUnavailable(*(u8 **)(arg0 + 0xE0), 0, 0) != 0) {
            btlCameraFrameWrapTargetWalk(arg0, 400.0f, fGpffff809c);
            return;
        }
        btlCameraFrameTarget(arg0, 400.0f, fGpffff809c);
    }
}
#pragma optimization_level 2

/* The flag at the top is an inlined early-return helper (a NULL action
 * returns 1, then a `switch` with no default per unit kind returns 0 for its
 * two battle ids, and one shared `return 1` follows), which reproduces
 * retail's beq/beq/b chains and its single shared `var16 = 1`; and
 * `battle == 10` is a one-case `switch`. `delta.y` reads the two zeroed
 * fields instead of folding `0.0f - 0.0f`.
 * Retail scales `delta` into three unfused products before three plain
 * add.s: each product is loaded into a named local and scaled in place
 * (`px = delta.x; px *= scale;`), which keeps the multiply out of the adds.
 * The two cutscene arms share one `return` after the if/else, so the first
 * arm branches to the second arm's exit as in retail. The ground clamp writes
 * `1.25f * top` twice; the repeated product is evaluated once with `top`
 * loaded first. `point.y` is read before it is written (retail reads the
 * uninitialised slot at sp+0x134), kept as in retail. */
static inline s32 func_00225ec0_flag(u8 *action)
{
    u16 battle;

    if (action == NULL) {
        return 1;
    }
    if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
        battle = *(u16 *)(iGpffffb3ac + 0x108);
        switch (battle) {
        case 0x21:
        case 0x22:
            return 0;
        }
    } else {
        battle = *(u16 *)(iGpffffb3ac + 0x108);
        switch (battle) {
        case 0x16:
        case 0x24:
            return 0;
        }
    }
    return 1;
}
#pragma opt_scalarize off
#pragma opt_scalarize on
#pragma opt_common_subs off
#pragma opt_common_subs on


#pragma opt_common_subs off
#pragma opt_common_subs on




#pragma opt_scalarize off
#pragma opt_scalarize on
#pragma opt_propagation off
#pragma opt_propagation on

/* measured: byte-exact (293/293 instructions, 0 differing words).  The
   roster walk is an inline helper returning u16 (retail masks the index at
   the helper's return and again at the use).  The 0x20-byte parameter block
   and the rotation centre are the stack locals at 0x70 and 0x90.  Saved
   registers follow declaration order: moveDelay, entry/delay, count,
   last/other, unit/target/move.
   `last` is deliberately left uninitialised: retail tests $s1 after the
   first scan without ever clearing it, so a battle with no candidate reads
   a stale register.  That is retail's behaviour, kept as found. */
static inline u16 btlUnitRosterIndex(u8 *unit)
{
    u8 *node;
    u16 index;

    if (unit[0xA2] != 0) {
        return 0;
    }
    index = 0;
    for (node = *(u8 **)(iGpffffb3ac + 0x17C); node != NULL; node = *(u8 **)(node + 0xA68)) {
        if (unit == node) {
            break;
        }
        index++;
    }
    return index;
}


 
#pragma opt_loop_invariants on
extern void btlEncounterResetUnit(u16 arg1);
#pragma opt_loop_invariants off
#pragma optimization_level 1
/* measured: closes optimization_level 1 around btlEncounterResetUnit. */
#pragma optimization_level 2






#pragma push
#pragma opt_loop_invariants on
#pragma pop
static inline u8 *cb90AddBaseIndex(u32 base, u32 index)
{
    return (u8 *)(base + index);
}
#pragma opt_propagation off
#pragma opt_propagation on

#pragma push
#pragma opt_propagation off
#pragma pop

