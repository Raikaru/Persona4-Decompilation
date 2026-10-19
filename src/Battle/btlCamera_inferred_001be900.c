#include "btl_camera_framing_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
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
#include "btl_camera_sequence_internal.h"

#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern s32 iGpffffb3ac; /* battle-state allocation */
extern u8 *iGpffffb3e0;
extern void (*jtbl_008873EC[])(void *);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];

extern u8 *D_0076449C;
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *first);
extern u32 datCalcRandomBelow(u32 first);
extern u32 iGpffffa0b8;
extern void btlUnitGetSphereWorldCenter(u8 *first, f32 *second);
extern void btlCameraSetupActionGeometry(u8 *first, u8 *second, f32 *third, f32 fifth, u16 fourth);
extern void btlMainApplyUnitBaseColors(u8 *first);
extern void btlCameraStartEffect(u8 *first, u8 *second, s32 third);
extern s32 btlCameraFrameActionGeneral(u8 *first, s32 second, s32 third, s32 fourth);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern void btlCameraUpdateEffectList(u8 *first);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern void btlCameraLookAtQuat(void *first, const void *second, const void *third, const void *fourth);
extern void btlCameraCopyPose(f32 *first, f32 *second);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void btlCameraUpdateUnitInRangeFlags(void);
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
extern void func_003dcc70(f32 *first, f32 *second, f32 *third);






#pragma push
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001b; members 001be900-001c04d0 */

extern void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode);
extern void btlCameraUpdateUnitInRangeFlags(void);
struct RwV3d;
typedef struct P4Vec4_001EC2B0 { f32 x, y, z, w; } P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 { P4Vec4_001EC2B0 quat; } P4Vec4Holder_001EC2B0;
extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0 *, P4Vec4Holder_001EC2B0 *);
extern RwV3d *RtQuatTransformVectors(RwV3d *, const RwV3d *, s32, const RtQuat *);
extern void btlMainCurveSetPoses(u16 *, f32 *, f32 *, u16);
/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
/* measured: scoped opt_lifetimes on with these disjoint work-pointer
 * lifetimes reproduces the complete 4156-byte retail body; all 122 owner
 * siblings, allocated data and 122 exact-position references are preserved.
 * The separate retained-height caller-domain proof remains required. */
#pragma push
#pragma pop
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
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
/* measured: disabling propagation preserves retail's independent outer-index
   materialisation after the preheader branch. */
/* measured: disabling common-subexpression folding preserves retail's second
   masked loop-counter use. */
/* measured: closes opt_common_subs for the following translation-unit code. */
/* measured: closes opt_propagation for the following translation-unit code. */
/* measured: opt_common_subs off preserves the retail per-use masked index. */
/* measured: restore common-subexpression optimization after btlCameraUpdateUnitInRangeFlags. */
/* Refresh action geometry around the actor sphere while action flag 1 remains set. */
// FUN_001BE900
void btlCameraFrameUnitWide(u8 *camera)
{
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    RwV3d sphereCenter;
    u8 *unit;
    u8 *action;

    action = *(u8 **)(camera + 0xE0);
    if ((action != NULL) && ((((BtlAction *)action)->unk_1a & 1) != 0)) {
        unit = (u8*)((BtlAction *)action)->unit;
        btlUnitGetSphereWorldCenter(unit, (f32 *)&sphereCenter);
        btlCameraSetupActionGeometry((u8*)((BtlCamera *)camera)->action, camera + 0x9C, (f32 *)&sphereCenter, 0.5f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale),
                      0xC1);
    }
}

/* Exact P4 general action camera, ported from P3 FES btlCameraFrameAction
   (04d95e2) with the P4 rejection path, literals and interpolation state.
   2564/2576 bytes; all 73 relocations and the duration literal resolved.
   See docs/probe_archive/Action_camera_frame_action_20260920.md. */
// FUN_001BE990
s32 btlCameraFrameActionGeneral(u8 *camera, s32 closeView, s32 nearScale, s32 farScale)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */


    typedef struct RwMatrixTag { RwV3d right; u32 flags; RwV3d up; u32 pad1; RwV3d at; u32 pad2; RwV3d pos; u32 pad3; } RwMatrix;
    typedef enum RwOpCombineType { rwCOMBINEREPLACE, rwCOMBINEPRECONCAT, rwCOMBINEPOSTCONCAT, rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF } RwOpCombineType;
    typedef P4Vec4Holder_001EC2B0 ActionQuat;
    typedef struct { RwV3d pos; ActionQuat rot; } ActionFrame;
    typedef struct { ActionQuat first, second; f32 scalar; s32 flag; } ActionBlend;
    struct BtlTarget;
    extern u16 btlTargetGetUnitIndex(struct BtlTarget *);
    extern s32 btlActionHasNoTargetClass(u32);
    extern void btlTargetBlendVectors(u8 *,u8 *,u8 *);
    extern f32 btlUnitGetGroupBounds(u32,u32,RwV3d *,f32 *,f32 *,u32);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, RwV3d *);
    extern RwMatrix *RwMatrixRotate(RwMatrix *,const RwV3d *,f32,RwOpCombineType);
    extern RwV3d *func_003e4320(RwV3d *,const RwV3d *,const RwMatrix *);
    extern f32 tanf(f32);
    extern void btlCameraSetDuration(u8 *,f32);
    extern f32 fGpffff8190,fGpffff8194,fGpffff8170,fGpffff8110,fGpffff8168,fGpffff8130,fGpffff8128;
    extern u8 D_0060A0D0[],D_0060A0F0[],D_0060A100[];
    f32 maxY;
    RwV3d scaled;
    RwV3d forward;
    RwV3d sphereCenter;
    RwV3d rotated;
    RwV3d center;
    RwV3d candidate;
    RwV3d targetCenter;
    RwMatrix rotation;
    ActionQuat blendedRot;
    ActionQuat quaternion;
    ActionBlend blend;
    ActionFrame frames[2];
    f32 distance;
    f32 fovDistance;
    f32 nearDistance;
    f32 radius;
    f32 half;
    f32 angle;
    f32 nearAngle;
    f32 ratio;
    f32 firstWeight;
    f32 x;
    f32 xSquared;
    f32 r;
    f32 r2;
    u8* unit;
    s32 targetAction;
    unit = (u8*)((BtlAction *)*(u8 **)(camera + 0xE0))->unit;
    if (closeView == 0)
    {
        btlCameraCopyPose((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
        distance = ((BtlUnit *)unit)->sphereRadius * *(f32 *)(unit + 0x2C);
        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &sphereCenter);
        RtQuatTransformVectors(&forward, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
        half = 0.5f * distance;
        scaled.x = forward.x * half;
        scaled.y = forward.y * half;
        scaled.z = forward.z * half;
        candidate.x = sphereCenter.x + scaled.x;
        candidate.y = sphereCenter.y + scaled.y;
        candidate.z = sphereCenter.z + scaled.z;
        candidate.y += 0.25f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        btlUnitGetGroupBounds(3, 0, 0, &maxY, 0, 1);
        scaled = frames[0].pos;
        if (maxY < scaled.y)
        {
            scaled.y = maxY;
        }
        else
        {
            x = ((BtlUnit *)unit)->scale;
            half = ((BtlUnit *)unit)->unk_8c * x;
            if (!(half <= scaled.y))
            {
                scaled.y = half;
            }
        }
        btlCameraLookAtQuat(&frames[1].rot, &scaled, &candidate, &D_0060A0E0);
        angle = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
        x = (f32)nearScale;
        nearDistance = fGpffff8190 * x;
        if (!(angle <= nearDistance))
        {
            if (!(angle <= fGpffff8190 * (f32)farScale)) return 0;
            radius = nearDistance / angle;
            func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot,
                         (f32*)&blend);
            if (radius <= 0.0f)
            {
                blendedRot = frames[0].rot;
            }
            else if (1.0f <= radius)
            {
                blendedRot = frames[1].rot;
            }
            else
            {
                firstWeight = 1.0f - radius;
                if (blend.flag == 0)
                {
                    x = firstWeight * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8194 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    firstWeight = r * r2 + x;
                    x = radius * blend.scalar;
                    xSquared = x * x;
                    r = fGpffff8054 + fGpffff8194 * xSquared;
                    r = fGpffff8058 + xSquared * r;
                    r = fGpffff805c + xSquared * r;
                    r = fGpffff8060 + xSquared * r;
                    r2 = fGpffff8108 + xSquared * r;
                    r = xSquared * x;
                    radius = r * r2 + x;
                }
                blendedRot.quat.x = blend.first.quat.x * firstWeight;
                blendedRot.quat.y = blend.first.quat.y * firstWeight;
                blendedRot.quat.z = blend.first.quat.z * firstWeight;
                blendedRot.quat.x = 0.0f + blendedRot.quat.x +
                                    blend.second.quat.x * radius;
                blendedRot.quat.y = 0.0f + blendedRot.quat.y +
                                    blend.second.quat.y * radius;
                blendedRot.quat.z = 0.0f + blendedRot.quat.z +
                                    blend.second.quat.z * radius;
                blendedRot.quat.w = blend.first.quat.w * firstWeight +
                                  blend.second.quat.w * radius;
            }
            RtQuatTransformVectors(&forward, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blendedRot));
            scaled.x = candidate.x + forward.x;
            scaled.y = candidate.y + forward.y;
            scaled.z = candidate.z + forward.z;
            btlCameraLookAtQuat(&frames[1].rot, &scaled, &candidate,
                         &D_0060A0E0);

        }
        forward.x = frames[0].pos.x - candidate.x;
        forward.y = frames[0].pos.y - candidate.y;
        forward.z = frames[0].pos.z - candidate.z;
        radius = RwV3dNormalize(&forward, &forward);
        radius = radius * fGpffff8170;
        half = 0.5f * ((BtlCamera *)camera)->fovRad;
        fovDistance = 1.5f * distance / tanf(half);
        if (!(fovDistance <= radius))
        {
            radius = fovDistance;
        }
        if (radius < (f32)0x226)
        {
            radius = (f32)0x226;
        }
        RtQuatTransformVectors(&forward, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
        scaled.x = forward.x * radius;
        scaled.y = forward.y * radius;
        scaled.z = forward.z * radius;
        frames[1].pos.x = candidate.x + scaled.x;
        frames[1].pos.y = candidate.y + scaled.y;
        frames[1].pos.z = candidate.z + scaled.z;
        if (frames[0].pos.y < 25.0f)
        {
            frames[0].pos.y = 25.0f;
        }
        if (frames[1].pos.y < 25.0f)
        {
            frames[1].pos.y = 25.0f;
        }
        angle = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
        radius = 2.15f;
        if (!(angle <= 0.0f)) {
            ratio = nearDistance / angle;
            if (!(ratio <= 1.0f)) radius = ratio * fGpffff8168;
            else radius = fGpffff8168;
            if (!(radius <= 2.15f)) radius = 2.15f;
        }
        btlMainCurveSetPoses((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
        btlCameraSetDuration(camera, radius);
        goto action_done;
    }

    targetAction = btlActionHasNoTargetClass((u32)*(u8 **)(camera + 0xE0));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &candidate);
    candidate.y = 0.0f + candidate.y + fGpffff8128 * (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale);
    if (((BtlAction *)*(u8 **)(camera + 0xE0))->unk_6a == 1 &&
        unit == (u8*)((BtlAction *)*(u8 **)((u8 *)((BtlCamera *)camera)->action + 0x38))->unit)
    {
        RtQuatTransformVectors(&rotated, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
    }
    else
    {
        if (targetAction != 0)
        {
            btlUnitGetSphereWorldCenter(
                (BtlUnit *)(u8*)((BtlAction *)*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38))->unit,
                &targetCenter);
        }
        else
        {
            btlUnitGetGroupBounds((s32)btlTargetGetUnitIndex((struct BtlTarget *)(*(u8 **)(camera + 0xE0) + 0x38)) & 0xffff,
                         1, &targetCenter, 0, 0, 1);
        }
        btlTargetBlendVectors((u8 *)&quaternion, (u8 *)&candidate, (u8 *)&targetCenter);
        RtQuatTransformVectors(&rotated, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(&quaternion));
    }
    nearAngle = 4.0f * (((BtlUnit *)unit)->sphereRadius * *(f32 *)(unit + 0x2C));
    half = 2.5f * (((BtlUnit *)unit)->sphereRadius * *(f32 *)(unit + 0x2C));
    switch (datCalcRandomBelow(3))
    {
    case 0:
        radius = 30.0f;
        break;
    case 1:
        radius = -30.0f;
        break;
    default:
        radius = 0.0f;
        break;
    }
    switch (datCalcRandomBelow(3))
    {
    case 0:
        angle = 15.0f;
        break;
    case 1:
        angle = -15.0f;
        break;
    default:
        angle = 0.0f;
        break;
    }
    RwMatrixRotate(&rotation, (const RwV3d *)D_0060A0D0, angle, 0);
    RwMatrixRotate(&rotation, (const RwV3d *)D_0060A0E0, radius, 2);
    func_003e4320(&forward, &rotated, &rotation);
    distance = nearAngle / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    forward.x *= distance;
    forward.y *= distance;
    forward.z *= distance;
    center.x = candidate.x;
    center.y = candidate.y;
    center.z = candidate.z;
    frames[0].pos.x = center.x + forward.x;
    frames[0].pos.y = center.y + forward.y;
    frames[0].pos.z = center.z + forward.z;
    btlCameraLookAtQuat(&frames[0].rot, &frames[0].pos, &center,
                 &D_0060A0E0);
    distance = half / tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    forward.x = rotated.x * distance;
    forward.y = rotated.y * distance;
    forward.z = rotated.z * distance;
    center.x = candidate.x;
    center.y = candidate.y;
    center.z = candidate.z;
    frames[1].pos.x = center.x + forward.x;
    frames[1].pos.y = center.y + forward.y;
    frames[1].pos.z = center.z + forward.z;
    btlCameraLookAtQuat(&frames[1].rot, &frames[1].pos, &center,
                 &D_0060A0E0);
    btlMainApplyUnitBaseColors(unit);
    btlCameraSetupActionGeometry((u8*)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 1);
    if (frames[0].pos.y < 25.0f)
    {
        frames[0].pos.y = 25.0f;
    }
    if (frames[1].pos.y < 25.0f)
    {
        frames[1].pos.y = 25.0f;
    }
    btlMainCurveSetPoses((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, 1.75f);
action_done:
    return 1;
}

/* Choose general framing or a character-specific effect script and remember which updater owns the frame. */
// FUN_001BF3A0
void btlCameraChooseActionStyle(u8 *camera)
{
    /* The script-dispatch word at camera+0x144 is still opaque padding in the shared camera layout. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    u8 *frameResult;
    u16 characterId;
    u8 *unit;

    switch (((BtlBattleState *)D_0076449C)->camera.stateHistory[0]) {
    case 0x22:
        frameResult = 0;
        goto first_done;
    default:
        goto first_random;
    }
first_random:
    if (datCalcRandomBelow(0x64) <= 0x19) goto first_random_zero;
    frameResult = (u8 *)btlCameraFrameActionGeneral(camera, 0, 0x23, 0x3C);
    goto first_done;
first_random_zero:
    frameResult = 0;
first_done:
    if (frameResult != NULL) goto done;
    if (datCalcRandomBelow(0x64) <= 0x19) goto second_random;
    unit = (u8*)((BtlAction *)*(u8 **)(camera + 0xE0))->unit;
    characterId = ((BtlUnit *)unit)->charId;
    btlMainApplyUnitBaseColors(unit);
    btlCameraStartEffect(camera,
                  func_001bf3a0_add((effMiscRand(0) & 1) * 0xF4,
                                    (u8 *)((s32)D_005FB400 +
                                           ((characterId & 0xFFFF) * 0x1E8))),
                  2);
    btlMainApplyUnitBaseColors(unit);
    btlCameraSetupActionGeometry((u8*)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 1);
    *(s32 *)(camera + 0x144) = 1;
    goto finish;
second_random:
    btlCameraFrameActionGeneral(camera, 1, 0x23, 0x3C);
    *(s32 *)(camera + 0x144) = 0;
    goto finish;
done:
    *(s32 *)(camera + 0x144) = 0;
finish:
    ;
}

/* Advance the selected effect script, or refresh geometry using a quarter of the actor radius. */
// FUN_001BF530
void btlCameraUpdateActionFrame(u8 *camera)
{
    /* The script-dispatch word at camera+0x144 is still opaque padding in the shared camera layout. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    RwV3d sphereCenter;
    u8 *unit;
    u8 *action;

    if (*(s32 *)(camera + 0x144) == 0) goto process;
    btlCameraUpdateEffectList(camera);
    goto done;
process:
    action = *(u8 **)(camera + 0xE0);
    if ((action != NULL) && ((((BtlAction *)action)->unk_1a & 1) != 0)) {
        unit = (u8*)((BtlAction *)action)->unit;
        btlUnitGetSphereWorldCenter(unit, (f32 *)&sphereCenter);
        btlCameraSetupActionGeometry((u8*)((BtlCamera *)camera)->action, camera + 0x9C, (f32 *)&sphereCenter, 0.25f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale),
                      0xC1);
    }
done:
    ;
}

/* Adapted from P3 FES btlCameraFrameActionPair at 04d95e2.
   P4 unit fields, lens constants and radius choices are verified against retail.
   See docs/probe_archive/Action_camera_pair_duel_20260920.md. */
// FUN_001BF5E0
void btlCameraFrameActionPair(u8 *camera)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */


    typedef RwV3d PairVec3;
    typedef P4Vec4Holder_001EC2B0 PairQuat;
    typedef struct { PairVec3 pos; PairQuat rot; } PairFrame;
    typedef struct { PairQuat first, second; f32 scalar; s32 flag; } PairBlend;
    extern f32 RwV3dLength(f32 *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern f32 RwV3dNormalize(PairVec3 *, const PairVec3 *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, PairVec3 *);
    extern void btlCameraSetDuration(u8 *, f32);
    extern f32 fGpffff803c, fGpffff80fc, fGpffff8158;
    extern u8 D_0060A100[];
    PairVec3 secondPos;
    PairVec3 dir;
    PairVec3 firstPos;
    PairVec3 center1;
    PairVec3 center2;
    PairQuat blended;
    PairBlend blend;
    PairFrame frames[2];
    f32 hs[4];
    u8* action;
    u8* unit;
    u8* unit2;
    f32 len2;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dot;
    f32 angle;

    action = (u8*)((BtlCamera *)camera)->action;
    unit = (u8*)((BtlAction *)action)->unit;
    unit2 = (u8*)((BtlAction *)*(int*)((u8*)action + 0x38))->unit;
    btlCameraCopyPose((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &center1);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit2, &center2);
    center1.y = 0.0f + center1.y + fGpffff803c * (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale);
    if (center1.y < 100.0f)
    {
        center1.y = 100.0f;
    }
    dir.x = frames[0].pos.x - center1.x;
    dir.y = frames[0].pos.y - center1.y;
    dir.z = frames[0].pos.z - center1.z;
    len2 = RwV3dLength((f32 *)&dir);
    len2 = len2 * fGpffff80fc;
    hs[2] = dir.x;
    hs[3] = dir.z;
    func_003e41e0(hs + 2, hs + 2);
    center2.y = center1.y;
    dir.x = center2.x - center1.x;
    dir.y = center2.y - center1.y;
    dir.z = center2.z - center1.z;
    RwV3dNormalize(&dir, &dir);
    hs[0] = dir.x;
    hs[1] = dir.z;
    dot = dir.x * hs[2] + dir.z * hs[3];
    if (dot < 0.0f)
    {
        dir.x = -dir.x;
        dir.y = -dir.y;
        dir.z = -dir.z;
    }
    secondPos.x = dir.x * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale);
    secondPos.y = dir.y * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale);
    secondPos.z = dir.z * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale);
    firstPos.x = center1.x + secondPos.x;
    firstPos.y = center1.y + secondPos.y;
    firstPos.z = center1.z + secondPos.z;
    dir.x = dir.x * (5.0f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale));
    dir.y = dir.y * (5.0f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale));
    dir.z = dir.z * (5.0f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale));
    secondPos.x = center1.x + dir.x;
    secondPos.y = center1.y + dir.y;
    secondPos.z = center1.z + dir.z;
    secondPos.y = 0.0f + center2.y + 0.5f * (((BtlUnit *)unit2)->unk_8c * ((BtlUnit *)unit2)->scale);
    dir.x = secondPos.x - center1.x;
    dir.y = secondPos.y - center1.y;
    dir.z = secondPos.z - center1.z;
    RwV3dNormalize(&dir, &dir);
    btlCameraLookAtQuat(&frames[1].rot, &secondPos, &firstPos, &D_0060A0E0);
    angle = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff8158)
    {
        ratio = fGpffff8158 / angle;
        func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8104 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                w1 = x + r * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8104 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                ratio = x + r * r2;
            }
            blended.quat.x = blend.first.quat.x * w1;
            blended.quat.y = blend.first.quat.y * w1;
            blended.quat.z = blend.first.quat.z * w1;
            blended.quat.x = 0.0f + blended.quat.x +
                             blend.second.quat.x * ratio;
            blended.quat.y = 0.0f + blended.quat.y +
                             blend.second.quat.y * ratio;
            blended.quat.z = 0.0f + blended.quat.z +
                             blend.second.quat.z * ratio;
            blended.quat.w = blend.first.quat.w * w1 +
                           blend.second.quat.w * ratio;
        }
        RtQuatTransformVectors(&dir, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blended));
        secondPos.x = firstPos.x + dir.x;
        secondPos.y = firstPos.y + dir.y;
        secondPos.z = firstPos.z + dir.z;
        btlCameraLookAtQuat(&frames[1].rot, &secondPos, &firstPos, &D_0060A0E0);
    }
    if (len2 < 600.0f)
    {
        len2 = 600.0f;
    }
    dir.x = dir.x * len2;
    dir.y = dir.y * len2;
    dir.z = dir.z * len2;
    frames[1].pos.x = firstPos.x + dir.x;
    frames[1].pos.y = firstPos.y + dir.y;
    frames[1].pos.z = firstPos.z + dir.z;
    btlMainCurveSetPoses((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, 1.0f);
}

/* Refresh tight action geometry from the actor sphere and current camera pose. */
// FUN_001BFB70
void btlCameraFrameUnitTight(u8 *camera)
{
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    RwV3d sphereCenter;
    u8 *unit;
    u8 *action;

    action = *(u8 **)(camera + 0xE0);
    if ((action != NULL) && ((((BtlAction *)action)->unk_1a & 1) != 0)) {
        unit = (u8*)((BtlAction *)action)->unit;
        btlUnitGetSphereWorldCenter(unit, (f32 *)&sphereCenter);
        btlCameraSetupActionGeometry((u8*)((BtlCamera *)camera)->action, camera + 0x9C, (f32 *)&sphereCenter, 0.25f * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale),
                      0xC3);
    }
}

/* Adapted from P3 FES btlCameraFrameActionDuel at 04d95e2.
   P4 unit fields, lens constants and radius choices are verified against retail.
   See docs/probe_archive/Action_camera_pair_duel_20260920.md. */
// FUN_001BFC00
void btlAct_SKILL_RECITE_E(u8 *camera)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */


    typedef RwV3d DuelVec3;
    typedef P4Vec4Holder_001EC2B0 DuelQuat;
    typedef struct { DuelVec3 pos; DuelQuat rot; } DuelFrame;
    typedef struct { DuelQuat first, second; f32 scalar; s32 flag; } DuelBlend;
    extern f32 RwV2dLength(f32 *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern f32 RwV3dNormalize(DuelVec3 *, const DuelVec3 *);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, DuelVec3 *);
    extern void *func_003dc740(void *, const void *, f32, s32);
    extern u32 btlCameraClampOffsetToLimit(f32 *, f32 *);
    extern void btlCameraSetDuration(u8 *, f32);
    extern f32 tanf(f32);
    extern f32 fabsf(f32);
    extern f32 fGpffff8118, fGpffff815c, fGpffff804c, fGpffff8160;
    extern f32 fGpffff8110, fGpffff8180;
    extern u8 D_0060A100[];
    f32 horiz[2];
    DuelVec3 candidate;
    DuelVec3 eyeAdj;
    DuelVec3 direction;
    DuelVec3 sideDirection;
    DuelVec3 center;
    DuelVec3 selectedCenter;
    DuelVec3 unitPoint;
    DuelVec3 targetCenter;
    DuelQuat blended;
    DuelQuat rots[2];
    DuelBlend blend;
    DuelFrame frames[2];
    u8* unit;
    u8* target;
    f32 radius;
    f32 sideOffset;
    f32 height;
    f32 angle;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dist;
    f32 selectedRadius;
    f32 dot;
    f32 sideLength;
    unit = (u8*)((BtlAction *)(u8*)((BtlCamera *)camera)->action)->unit;
    target = (u8*)((BtlAction *)*(u8 **)((u8*)((BtlCamera *)camera)->action + 0x38))->unit;
    btlCameraCopyPose((f32*)&frames[0], (f32*)((u8*)camera + 0x9c));
    unitPoint.x = *(f32 *)(unit + 0xDC);
    unitPoint.y = ((BtlUnit *)unit)->sphereCenter.y * *(f32 *)(unit + 0x2C);
    unitPoint.z = *(f32 *)(unit + 0xE4);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetCenter);
    {
        f32 targetHeight;
    height = ((BtlUnit *)unit)->unk_8c * *(f32 *)(unit + 0x2C);
    height = unitPoint.y + fGpffff8118 * height;
    ratio = ((BtlUnit *)target)->unk_8c * *(f32 *)(target + 0x2C);
    targetHeight = targetCenter.y + fGpffff8118 * ratio;
    height = height + targetHeight;
    radius = *(f32*)((u8*)unit + 0xe8);
    radius += *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    radius += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    targetCenter.y = 0.0f;
    unitPoint.y = 0.0f;
    direction.x = ((BtlUnit *)unit)->moveDestination.x - targetCenter.x;
    direction.y = ((BtlUnit *)unit)->moveDestination.y - unitPoint.y;
    direction.z = ((BtlUnit *)unit)->moveDestination.z - targetCenter.z;
    RwV3dNormalize(&direction, &direction);
    targetHeight = 0.25f * radius;
    center.x = direction.x * targetHeight;
    center.y = direction.y * targetHeight;
    center.z = direction.z * targetHeight;
    center.x = targetCenter.x + center.x;
    center.y = targetCenter.y + center.y;
    center.z = targetCenter.z + center.z;
    {
        f32 halfHeight;
    halfHeight = 0.5f * height;
    center.y = halfHeight;
    eyeAdj = frames[0].pos;
    eyeAdj.y = height;
    ((BtlCameraFocusWork *)((u8 *)camera + 0x100))->radius =
        0.5f * ((BtlUnit *)unit)->stoppingDistance;
    ((BtlCameraFocusWork *)(camera + 0x100))->focus = center;
    btlCameraLookAtQuat(&frames[1].rot, &eyeAdj, &center, &D_0060A0E0);
    height = radius;
    height += *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    height += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    angle = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff815c)
    {
        ratio = fGpffff815c / angle;
        func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot, (f32*)&blend);
        if (ratio <= 0.0f)
        {
            blended = frames[0].rot;
        }
        else if (1.0f <= ratio)
        {
            blended = frames[1].rot;
        }
        else
        {
            w1 = 1.0f - ratio;
            if (blend.flag == 0)
            {
                x = w1 * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8180 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                w1 = x + r * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = fGpffff8054 + fGpffff8180 * x2;
                r = fGpffff8058 + x2 * r;
                r = fGpffff805c + x2 * r;
                r = fGpffff8060 + x2 * r;
                r2 = fGpffff8108 + x2 * r;
                r = x2 * x;
                ratio = x + r * r2;
            }
            blended.quat.x = blend.first.quat.x * w1;
            blended.quat.y = blend.first.quat.y * w1;
            blended.quat.z = blend.first.quat.z * w1;
            blended.quat.x = 0.0f + blended.quat.x + blend.second.quat.x * ratio;
            blended.quat.y = 0.0f + blended.quat.y + blend.second.quat.y * ratio;
            blended.quat.z = 0.0f + blended.quat.z + blend.second.quat.z * ratio;
            blended.quat.w = blend.first.quat.w * w1 + blend.second.quat.w * ratio;
        }
        RtQuatTransformVectors(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&blended));
        eyeAdj.x = eyeAdj.x + center.x;
        eyeAdj.y = eyeAdj.y + center.y;
        eyeAdj.z = eyeAdj.z + center.z;
        btlCameraLookAtQuat(&frames[1].rot, &eyeAdj, &center, &D_0060A0E0);
    }
    else if (angle < fGpffff804c)
    {
        func_003dc740((f32*)&frames[1].rot, (const f32*)&D_0060A0E0, fGpffff8160, 2);
    }
    if (height < 600.0f)
    {
        height = 600.0f;
    }
    dist = (1.5f * (0.5f * height)) /
           tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    RtQuatTransformVectors(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
    direction.y = eyeAdj.y;
    RwV3dNormalize(&direction, &direction);
    angle = eyeAdj.x * direction.x +
            eyeAdj.y * direction.y +
            eyeAdj.z * direction.z;
    if (angle >= 0.0f)
    {
        selectedRadius = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale;
        selectedCenter = unitPoint;
    }
    else
    {
        selectedRadius = ((BtlUnit *)target)->sphereRadius * ((BtlUnit *)target)->scale;
        selectedCenter = targetCenter;
    }
    candidate.x = targetCenter.x + direction.z * selectedRadius;
    candidate.y = center.y;
    candidate.z = targetCenter.z - direction.x * selectedRadius;
    sideDirection.x = candidate.x - center.x;
    sideDirection.y = candidate.y - center.y;
    sideDirection.z = candidate.z - center.z;
    RwV3dNormalize(&sideDirection, &sideDirection);
    dot = 0.0f +
          sideDirection.x * direction.x +
          sideDirection.y * direction.y +
          sideDirection.z * direction.z;
    if (fabsf(angle) > fabsf(dot) &&
        dot != 0.0f && angle != 0.0f)
    {
        horiz[0] = center.x - selectedCenter.x;
        horiz[1] = center.z - selectedCenter.z;
        sideLength = RwV2dLength(horiz);
        candidate.y = center.y + halfHeight * sideLength / dist;
        candidate.x = selectedCenter.x + direction.z * selectedRadius;
        candidate.z = selectedCenter.z - direction.x * selectedRadius;
        btlCameraLookAtQuat(&rots[0], &candidate, &center, &D_0060A0E0);
        angle = btlTargetQuatAngle(&frames[0].rot, &rots[0]);
        candidate.x = selectedCenter.x - direction.z * selectedRadius;
        candidate.z = selectedCenter.z + direction.x * selectedRadius;
        btlCameraLookAtQuat(&rots[1], &candidate, &center, &D_0060A0E0);
        ratio = btlTargetQuatAngle(&frames[0].rot, &rots[1]);
        if (angle < ratio)
        {
            frames[1].rot = rots[0];
        }
        else
        {
            frames[1].rot = rots[1];
        }
        RtQuatTransformVectors(&eyeAdj, (const RwV3d *)(&D_0060A100), 1, (const RtQuat *)(&frames[1].rot));
    }
    eyeAdj.x = eyeAdj.x * dist;
    eyeAdj.y = eyeAdj.y * dist;
    eyeAdj.z = eyeAdj.z * dist;
    sideOffset = dist * tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    sideOffset = sideOffset * 0.21875f;
    horiz[0] = eyeAdj.x;
    horiz[1] = eyeAdj.z;
    func_003e41e0(horiz, horiz);
    center.x = 0.0f + center.x + horiz[1] * sideOffset;
    center.z = 0.0f + center.z - horiz[0] * sideOffset;
    frames[1].pos.x = center.x + eyeAdj.x;
    frames[1].pos.y = center.y + eyeAdj.y;
    frames[1].pos.z = center.z + eyeAdj.z;
    btlCameraClampOffsetToLimit((f32*)&frames[0], (f32*)&frames[0]);
    btlCameraClampOffsetToLimit((f32*)&frames[1], (f32*)&frames[1]);
    btlMainCurveSetPoses((u16*)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, 2.0f);
    }
    }
}

/* Empty update callback for MOVE_TARGET (state 22) in the retail camera table at 0x005F74C0. */
// FUN_001C04D0
void btlCameraMoveTargetUpdate(void)
{
}

