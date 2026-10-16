#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"

typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
extern s32 func_00106600(s16 id);
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void btlEncounterEntrySetRetracted(u8 *arg0);
extern s32 btlEncountRollChance(u8 *arg0);
extern s32 btlShuffleSelectMember(u8 *arg0, s16 arg1, s32 arg2);
extern s32 datCalcGetBadStatus(s32 arg0);
extern void btlEncounterStart(u8 *arg0);
extern s32 btlShuffleCreate(s32 arg0, u8 *arg1);
extern void btlShuffleCancel(s32 arg0);
extern s32 datCalcGetLevel(s32 arg0);
extern s32 func_00193260(u8 *arg0);
extern void memset(void *dst, s32 value, s32 size);
extern void hFadeTaskStart(s16 arg0);
extern s32 mcIconTaskCreate(u8 *parent, s32 mode);
extern void fieldSceneLoad(s32 arg0, s32 arg1);
extern s32 func_003bbb60(u8 *arg0);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void *SceneDraw_GetList4FirstColor(void);
extern s32 btlActionQueuePush(u8 *arg0);
extern s32 btlOrderRemoveActionAll(u8 *arg0);
extern void *SceneDraw_GetList4SecondColor(void);
extern void btlMainLoadBattleFieldScene();
extern void btlUnitRecordCommitPending(void);
extern s32 func_00122640(s32 arg0, s32 arg1);
extern s32 btlFormationAllocWork(s32 arg0);
extern BtlPacket *btlFormationCreateNamedPacket(u32 arg0, const char *arg1, u16 arg2);
extern u8 *btlSoundCreateSkillSEPacket(s32 arg0, s32 arg1);
extern u8 *btlMainCreateColorLerpPacket(s32 arg0, s32 arg1, s32 arg2);
extern BtlPacket *btlMainCreateColorWorkPacket(s32 first, s32 second, s32 third, u32 frames, u16 mode);
extern u8 *btlMainCreateTintPacket(s32 arg0, s32 arg1);
extern void func_001f0a10(u8 *arg0);
extern u8 *btlPacketCreateHpRatio(u8 *arg0);
extern BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
extern u8 *btlCreateTimingPacket(s32 arg0);
extern u8 *btlMainCreateFadePacket(s32 arg0, s32 arg1);
extern u8 *btlMainCreateColorFadePacket(s32 arg0);
extern u16 datCalcGetHp(s32 unit);
extern u16 datCalcGetSp(s32 unit);
extern void btlMainSkillColorPairDefaults(u32 arg0, s32 *arg1, s32 *arg2);
extern s32 btlMainSkillColorDefault(s32 arg0);
extern s32 btlMainSkillTintDefault(s32 arg0);
extern void btlMainSkillColorPairDefaultsAlt(u32 arg0, s32 *arg1, s32 *arg2);
extern void btlFormationSetPlacement(s32 arg0);
extern void btlUnitSetFlags(u8 *arg0, s32 arg1);
extern void btlUnitClearFlags(u8 *arg0, s32 arg1);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *arg0);
extern u32 kwlnTaskGetWork(s32 arg0);
extern s32 func_00459760(s32 arg0);
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern void btlEncounterSetFinish(s32 task);
extern u32 datCalcIsDead(s32 arg0, s32 arg1);
extern u8 *btlUnitRecordFindByActionUID(u64 arg0, u64 arg1);
extern s32 btlSoundIsPlaybackActive(void);
extern s32 fieldSceneLoadStep(void);
extern void (*jtbl_008873EC[])(void *);
extern void GeometryBlockDestroy(void *arg0);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];
extern s32 btlUnitIsMoving(u8 *arg0);
extern void func_00194ff0(u8 *unit, u8 *position, f32 *rotation, f32 *direction);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *direction, u32 flags);
extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern void btlActionSetState(BtlAction *arg0, u16 arg1);
extern void func_002bbcc0(void);
extern s32 func_002bb600(void);
extern s32 func_002bb140(void);
extern void func_002bb380(void);
extern void func_002bb4e0(void);

extern u8 *D_0076449C;
extern s32 func_0022bd20(void);
extern void btlEncounterInitGlobals(void);
extern s32 func_001fadc0(u8 *arg0);
extern u32 btlCountUnitRecords(void);
extern BtlPacket *btlTargetCreateTargetPacket(u32 arg0, u16 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void btlUnitShowModel(u8 *arg0);
extern void btlUnitHideModel(u8 *arg0);
extern s32 btlCurrentUnitId(void);
extern void func_002aaaa0(void);
extern void btlFadeStart(s32 arg0);
extern s32 func_001faaa0(u8 *arg0);
extern s32 btlBossIsAllowedAction(void);
extern s32 func_001fae10(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern void H_Fade_SetCustomColor(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_002aa3f0(void);
extern void btlResetEffectSlots(void);
extern void fieldSceneUnload();
extern s32 func_001ba0e0(struct ColorBlendWork *work);
extern u8 *btlPacketAlloc(s32 size, s32 align);
extern void func_001ec5e0(u8 *arg0, f32 fp);
extern void btlMainUnloadFieldScene(void);
extern s32 func_001ba590(u8 *arg0);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void func_001eb380(u8 *arg0);
extern s64 btlGetUID(void);
extern u32 datCalcRandomBelow(u32 arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u32 datCalcGetBattleStat(u8 *arg0, s32 arg1);
extern void btlBossCollectTargets(u8 *arg0);
extern s32 datCalcUnitClass(u8 *arg0);
extern void btlActionQueueSortByRank(s32 arg0);
extern void btlActionQueueRequeueLeadingEnemies(s32 arg0);
extern u32 iGpffffa0b8;
extern void func_0014a2e0(u32 arg0);
extern void btlMainSetupCameraAndEffects(void);
extern u32 datGetFlag(s32 arg0);
extern BtlPacket *btlVoiceCreateIdPacket(u16 arg0);
extern u8 *btlSoundCreateWaitPacket(void);
extern u8 *btlBossCreateLoadPakPacket(void);
extern s32 btlBossMapUnitIdToEntryId(void);
extern BtlPacket *btlBossCreateLoadEndBgmPacket(s32 arg0);
extern void func_002aaa80(void);
extern void hFadeSetCustomWhite(void);
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern s32 btlShuffleIsIdle(s32 task);
extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
extern s32 func_001faaf0(void);
extern s32 func_001fab40(u8 *arg0);
extern s32 func_001fab90(void);
extern void btlDamageSetSource(u8 *arg0, s32 arg1);
BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
extern u8 func_002baac0(u8 *message);
void func_002bad10(u32 arg0);
void func_002bb050(u32 arg0);
void func_002baf40(u32 arg0);
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern void btlMainApplyUnitBaseColors(u8 *arg0);
extern void btlCameraStartEffect(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 func_001be990(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern void *SceneDraw_GetList4Matrix(void);
extern u8 *resrcMngGetColorValue(void);
extern u8 *resrcMngGetColorTarget(void);
extern s32 btlCameraFrameActionStart(u8 *arg0, u8 *arg1);
extern u8 *btlCameraGetCurrentEntry(u8 *arg0);
extern void btlCameraInitWork(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void btlCameraUpdateEffectList(u8 *arg0);
extern BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern u8 *btlPacketCreateImmediate(void);
extern BtlPacket *btlTargetCreateEmptyPacket(void);
extern void btlSoundStopBank3(void);
extern void btlDamageStartFlash(s32 arg0);
extern void btlEncounterSetReady(s32 task);
extern s32 btlEncounterIsIntroDone(s32 task);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 btlShuffleIsCanceled(s32 task);
extern s32 btlEncounterIsInactive(s32 arg0);
extern s32 btlShuffleIsBusy(s32 task);
extern s32 func_00122720(void);
extern BtlPacket *func_0019bbe0(BtlUnit *arg0, u32 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5);
extern BtlPacket *btlSoundCreateChannelCuePacket(u16 arg0, u16 arg1, u16 arg2);
extern void btlUnitUnlinkAndFree(u8 *arg0);
extern void func_001b08f0(void *arg0);
extern void btlCameraReleaseActionRefs(u8 *arg0);
extern void datUnitRemoveEncounterUnit(DatUnitEc *arg0, DatUnit *arg1);
extern void func_001bdd60(void);
extern u8 *datUnitGetRecord(s16 arg0);
extern u16 *datPersonaGetRecord(u16 arg0);
extern s32 datPersonaFindSkillSlot(u8 *arg0, u16 arg1);
extern void btlPanelReset(s32 arg0);
extern void datCalcSetHp(s32 arg0, u16 arg1);
extern void datCalcSetSp(s32 arg0, u16 arg1);
extern u16 datCalcMaxHp(DatUnit *arg0);
extern u16 datCalcMaxSp(DatUnit *arg0);
extern s32 datCalcAddHp(DatUnit *arg0, s32 arg1);
extern s32 datCalcAddSp(DatUnit *arg0, s32 arg1);
extern s32 datCalcHasSkill(u8 *arg0, s32 arg1);
extern u32 datCalcClearBadStatus(s32 arg0, u32 arg1);
extern void datCalcClearAllBuffs(u8 *arg0);
extern void btlUnitSetColor(u8 *arg0, s32 arg1);
extern void btlCameraSetState(s32 state, BtlAction *action, u32 param_3);
extern void btlCameraLookAtQuat(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern void btlCameraCopyPose(f32 *arg0, f32 *arg1);
extern void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3);
extern u32 btlMainCurveAppendKeyframe(u16 *arg0, f32 *arg1, f32 *arg2);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 btlTargetSmoothStep(f32 value, f32 *state);
extern u32 btlCameraSampleKeyframes(u8 *arg0, f32 *arg1, f32 *arg2);
extern u32 btlCameraAdvanceKeyframes(u8 *arg0, f32 arg1);
extern f32 fGpffff8430;
extern void primQuad3D(f32 *arg0, u8 *arg1, s32 arg2, f32 arg3);
extern void primAxisLine3D(f32 *arg0, s32 arg1, f32 arg2);
extern u8 *btlEncounterGetRecord(s32 arg0);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern s32 func_00457120(void);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void func_001bd390(void);
extern u8 *func_003e8180(u8 *arg0, f32 arg1);
extern s32 func_003bbbe0(s32 arg0, s32 arg1, void *arg2);
extern void func_001d12e0(void *arg0);
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;
extern void func_003dcc70(f32 *arg0, f32 *arg1, f32 *arg2);

s32 btlTargetIsSlotAlive(u8 *arg0);

void func_004b1680(s32 arg0, s16 arg1, s32 arg2, s32 arg3);




extern u8 *btlActionFindByUnit(s32 arg0);
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_common_subs off
#pragma pop












#pragma opt_rebuildconditionals off
#pragma opt_rebuildconditionals on
#pragma push
#pragma opt_lifetimes on

#pragma pop
#pragma push
#pragma opt_rebuildconditionals off
#pragma pop




#include "btl_camera_sequence_internal.h"

typedef struct BtlCameraColorReal {
    f32 red, green, blue, alpha;
} BtlCameraColorReal;

/* Complete the four byte-to-real conversions before in-place modulation. */
static inline void btlCameraNormalizeColor(BtlCameraColorReal *result, const u8 *bytes)
{
    result->red = (1.0f / 255.0f) * (f32)bytes[0];
    result->green = (1.0f / 255.0f) * (f32)bytes[1];
    result->blue = (1.0f / 255.0f) * (f32)bytes[2];
    result->alpha = (1.0f / 255.0f) * (f32)bytes[3];
}
/* Input and result may share the same real-color record, component by component. */
static inline void btlCameraMultiplyColor(BtlCameraColorReal *result, const BtlCameraColorReal *base, const BtlCameraColorReal *ambient)
{
    result->red = base->red * ambient->red;
    result->green = base->green * ambient->green;
    result->blue = base->blue * ambient->blue;
    result->alpha = base->alpha * ambient->alpha;
}
/* The SDK byte-to-real factor is the existing retail 0x3b808081 literal.
 * Keep four palette calls in the caller; this phase consumes their snapshots. */
static inline s32 btlCameraBlendAmbient(f32 ambientRed, f32 ambientGreen,
                                       f32 ambientBlue, f32 ambientAlpha)
{
    union BtlCameraPackedColor { s32 word; u8 bytes[4]; } color;
    BtlCameraColorReal normalized;
    BtlCameraColorReal ambient;
    s32 redByte, greenByte, blueByte, alphaByte;
    color.word = (s32)0xFF808080U;
    btlCameraNormalizeColor(&normalized, color.bytes);
    ambient.red = ambientRed;
    ambient.green = ambientGreen;
    ambient.blue = ambientBlue;
    ambient.alpha = ambientAlpha;
    btlCameraMultiplyColor(&normalized, &normalized, &ambient);
    redByte = (s32)(normalized.red * 255.0f + 0.5f);
    color.bytes[0] = redByte;
    greenByte = (s32)(normalized.green * 255.0f + 0.5f);
    color.bytes[1] = greenByte;
    blueByte = (s32)(normalized.blue * 255.0f + 0.5f);
    color.bytes[2] = blueByte;
    alphaByte = (s32)(normalized.alpha * 255.0f + 0.5f);
    color.bytes[3] = alphaByte;
    return color.word;
}








#pragma push
#pragma opt_loop_invariants on

#pragma pop
#pragma opt_propagation off
#pragma opt_propagation on









#pragma push
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma pop
typedef struct { u8 r; u8 g; u8 b; u8 a; } BlendColor;
typedef struct ColorBlendWork {
    BlendColor target;
    BlendColor start;
    u32 frames;
    u32 frame;
} ColorBlendWork;
static inline u8 blendChannel(u8 start, u8 target, f32 t, f32 inv)
{
    f32 s = (1.0f / 255.0f) * (f32)start;
    f32 e = (1.0f / 255.0f) * (f32)target;
    f32 m = s * inv + e * t;
    return ((s32)(m * 255.0f + 0.5f)) & 0xFF;
}


// FUN_001BA790
void func_001ba790(f32 *arg0, f32 *arg1, f32 *arg2, f32 fparg0)
{
    struct Ba790Local {
        f32 f50;
        f32 f54;
        f32 f58;
        f32 f5C;
        f32 f60;
        f32 f64;
        f32 f68;
        f32 f6C;
        f32 f70;
        s32 flag;
    } local;
    f32 var_f20;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;

    var_f20 = 1.0f - fparg0;
    temp_f5 = arg1[1] * var_f20;
    temp_f4 = arg1[2] * var_f20;
    temp_f3 = arg2[1] * fparg0;
    temp_f2 = arg2[2] * fparg0;
    arg0[0] = (arg1[0] * var_f20) + (arg2[0] * fparg0);
    arg0[1] = temp_f5 + temp_f3;
    arg0[2] = temp_f4 + temp_f2;
    func_003dcc70(arg1 + 3, arg2 + 3, &local.f50);
    if (fparg0 <= 0.0f) {
        temp_f3 = arg1[3];
        temp_f2 = arg1[4];
        temp_f1 = arg1[5];
        temp_f0 = arg1[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (1.0f <= fparg0) {
        temp_f3 = arg2[3];
        temp_f2 = arg2[4];
        temp_f1 = arg2[5];
        temp_f0 = arg2[6];
        arg0[3] = temp_f3;
        arg0[4] = temp_f2;
        arg0[5] = temp_f1;
        arg0[6] = temp_f0;
        goto done;
    }
    if (local.flag == 0) {
        temp_f0 = var_f20 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        var_f20 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
        temp_f0 = fparg0 * local.f70;
        temp_f1 = temp_f0 * temp_f0;
        temp_f2 = fGpffff8104 * temp_f1 + fGpffff8054;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8058;
        temp_f2 = temp_f1 * temp_f2 + fGpffff805c;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8060;
        temp_f2 = temp_f1 * temp_f2 + fGpffff8108;
        fparg0 = temp_f0 + func_001ba790_mul(temp_f1 * temp_f0, temp_f2);
    }
    arg0[3] = local.f50 * var_f20;
    arg0[4] = local.f54 * var_f20;
    arg0[5] = local.f58 * var_f20;
    arg0[3] = local.f60 * fparg0 + arg0[3];
    arg0[4] = local.f64 * fparg0 + arg0[4];
    arg0[5] = local.f68 * fparg0 + arg0[5];
    arg0[6] = local.f5C * var_f20 + local.f6C * fparg0;
done:
    ;
}



#pragma opt_propagation off
#pragma opt_propagation on







/* Apply ordered visibility rules before testing the XZ camera segment.
 * Unit group IDs come from the 0019d210 constructors (0, 1, or 2).
 * measured b210 -O2: 1472/1472 bytes, all 22 relocations resolved.
 * Loop invariants retain the flag tests; separate target ordinals and
 * the u16 accessor preserve each search's index conversions. */
static inline u8 *cameraVisibilityTarget(u8 *action, u16 index)
{
    return *(u8 **)(action + index * 4 + 0x38);
}

struct RwV3d;

#pragma push
#pragma opt_loop_invariants on
#pragma pop
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_common_subs off
#pragma opt_common_subs on







#pragma opt_propagation off
#pragma opt_propagation on
/* Camera providers use a four-float P4 quaternion holder and the RenderWare
 * vector/quaternion ABI. The backend vector transform reads exactly sixteen
 * quaternion bytes and returns its original output pointer. */
typedef struct P4Vec4_001EC2B0 { f32 x, y, z, w; } P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 { P4Vec4_001EC2B0 quat; } P4Vec4Holder_001EC2B0;
extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0 *, P4Vec4Holder_001EC2B0 *);
extern RwV3d *RtQuatTransformVectors(RwV3d *, const RwV3d *, s32, const RtQuat *);
extern void btlMainCurveSetPoses(u16 *, f32 *, f32 *, u16);

