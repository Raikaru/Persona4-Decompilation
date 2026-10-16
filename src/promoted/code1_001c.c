#include "btl_motion_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"

/* Preserve source operand order in the camera's height products. */
static inline f32 p4_cacd0_mul(f32 left, f32 right)
{
    return left * right;
}

typedef struct BtlUnitStateWork BtlUnitStateWork;
typedef struct BtlUnit BtlUnit;
typedef struct RwV3d RwV3d;
typedef struct RwMatrixTag RwMatrix;
typedef struct RtQuat RtQuat;

struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
};

typedef struct P4Vec4_001EC2B0 { f32 x, y, z, w; } P4Vec4_001EC2B0;
typedef struct P4Vec4Holder_001EC2B0 { P4Vec4_001EC2B0 quat; } P4Vec4Holder_001EC2B0;
typedef struct P4CameraFrame { RwV3d pos; P4Vec4Holder_001EC2B0 rot; } P4CameraFrame;
typedef struct P4CameraBlend {
    P4Vec4Holder_001EC2B0 first, second;
    f32 scalar;
    s32 flag;
} P4CameraBlend;
typedef struct P4CameraVec2 { f32 x, y; } P4CameraVec2;


struct RwMatrixTag {
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
};

extern void btlCameraUpdateEffectList();
extern void btlCameraSetLimitFrame(u8 *camera, f32 angleLimit, s32 reverse, s32 preserveSide);
extern void btlCameraFrameRotated(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void btlCameraFrameRotatedWide(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void btlMainApplyUnitBaseColors(u8 *arg0);
extern void CrossfadeRequest(s32 arg0);
extern void btlMainCurveReset(u16 *arg0, f32 *arg1);
extern u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                          P4CameraFrame *firstOut, P4CameraFrame *secondOut);
extern void btlCameraFrameStatusRoll(u8 *arg0, f32 arg1, f32 arg2);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 RwV3dNormalize(RwV3d *arg0, const RwV3d *arg1);
extern f32 RwV3dLength(f32 *arg0);
extern void btlCameraCopyPose();
extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *out);
extern void btlUnitGetAnimBoundsWorldCenter(BtlUnit *arg0, RwV3d *arg1);
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
extern RwMatrix *RwMatrixRotate(RwMatrix *arg0, const RwV3d *arg1, f32 arg2, s32 arg3);
extern RwV3d *func_003e4320(RwV3d *arg0, const RwV3d *arg1, const RwMatrix *arg2);
extern u32 btlCameraClampOffsetToLimit(f32 *arg0, f32 *arg1);
extern f32 tanf(f32 arg0);
extern f32 fGpffff80fc;
extern f32 fGpffff8114;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern f32 fGpffff811c;
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg3, u16 arg4);
extern void btlCameraFrameSweep(u8 *arg0, f32 arg1, f32 arg2);
extern void btlCameraFrameFourPoseCurve(u8 *arg0, f32 arg1, f32 arg2);
extern void btlUnitSetChildValue(BtlUnitStateWork *work, u16 value);
extern s32 btlCameraUnitAnimFinished(u8 *arg0, u8 *arg1);
extern s32 btlEffectCollectGenusMask(u8 *arg0);
extern u32 func_001d8bc0(void *formation);
extern void btlCameraFrameStatus(u8 *arg0, s32 arg1);
extern void btlCameraFrameSideView(u8 *arg0, s32 arg1);
extern void btlCameraUpdateOcclusion(u8 *arg0);
extern void btlCameraMarkUnitFramed(u8 *arg0);
extern void btlCameraClearUnitFramed(u8 *arg0);
extern u8 *kwlnGetCamera(void);
extern void btlCameraBuildPosePair(u8 *camera, P4CameraFrame *first, P4CameraFrame *second);
extern void btlMainCurveSetPoses(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
extern void btlCameraSetDuration(u8 *arg0, f32 arg1);
extern void btlCameraStartEffect(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern s32 btlActionHasNoTargetClass(u8 *arg0);
extern void btlCameraFrameWithFlags(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern u32 datCalcRandomBelow(u32 arg0);
extern s32 btlCameraIsActionBlocked(u8 *arg0);
extern s32 btlTargetGetUnitIndex(u8 *arg0);
extern s32 btlTargetGroupStateMatches(u8 *arg0);
extern s32 btlTargetIsEntryActive(s16 arg0);
extern s32 btlTargetCanSelectEntry(u8 *arg0, s16 arg1, s32 arg2);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 btlUnitSkillBlocked(u8 *arg0, u8 *arg1);
extern void btlUnitSetFlags(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern RwMatrix *RwMatrixRotate(RwMatrix *arg0, const RwV3d *arg1, f32 arg2, s32 arg3);
extern RwV3d *func_003e4320(RwV3d *arg0, const RwV3d *arg1, const RwMatrix *arg2);
extern void btlCameraLookAtQuat(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern u8 D_0060A0D0[];
extern u8 D_0060A0E0[];
extern RwV3d D_0060A0F0;
extern u8 D_0060A100[];
extern s32 btlTargetFindInRange(f32 *arg0, f32 *arg1);
extern f32 btlTargetVectorDistance(f32 *arg0, u8 *arg1);
extern s32 func_0044dcd8(f32 arg0);
extern s32 func_0044b310(s32 arg0);
extern f32 func_0044e7d8(s32 arg0);
extern f32 fGpffff819c;
extern u8 D_00607DD0[];
extern u8 D_00607DD8[];
extern f32 D_00607DDC[];
extern f32 D_00607DE0[];
extern f32 D_00607DE4[];
extern f32 D_00607DF0[];
extern f32 D_00607DFC[];
extern f32 D_00607E10[];
extern f32 D_00607E14[];
extern f32 D_00607E18[];
extern f32 D_00607E1C[];
extern f32 D_00607E20[];
extern f32 D_00607E24[];
extern f32 D_00607E30[];
extern f32 D_00607E3C[];
extern u8 *btlCameraRandomTableEntry(s32 arg0, s32 arg1);
extern RwV3d *RtQuatTransformVectors(RwV3d *arg0, const RwV3d *arg1, s32 arg2, const RtQuat *arg3);
extern void btlCameraFrameRandomOrbit(u8 *arg0, s32 arg1);
extern void btlCameraFrameRandomEntry(u8 *arg0, s32 arg1, s32 arg2);
extern void btlCameraFrameDistinctPair(u8 *arg0, s32 arg1, s32 arg2);
extern void btlCameraFrameSplit(u8 *arg0, s32 arg1, s32 arg2);
static inline f32 func_001c_mul_add(f32 arg0, f32 arg1, f32 arg2)
{
    return arg0 * arg1 + arg2;
}
static inline void func_001c_copy_pair(s64 *arg0, f32 *arg1,
                                       s64 *arg2, f32 *arg3)
{
    s64 pair;
    f32 value;

    pair = *arg2;
    value = *arg3;
    *arg0 = pair;
    *arg1 = value;
}
static inline void func_001c_rotate(RwMatrix *arg0, const RwV3d *arg1,
                                    f32 arg2, s32 arg3)
{
    RwMatrixRotate(arg0, arg1, arg2, arg3);
}

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* P3 btlCameraFrameActionSide (002a6ee0, donor NONMATCHING), adapted to P4; b210 -O2: 1208 bytes plus 8 retail zero bytes. */

static inline f32 cameraSideRadius(f32 first, f32 second)
{
    if (first > second) return first;
    return second;
}


#pragma optimization_level 1
#pragma optimization_level 2
#pragma opt_propagation off
#pragma opt_propagation on
#pragma optimization_level 1
#pragma optimization_level 2
#pragma optimization_level 1
#pragma optimization_level 2
#pragma optimization_level 1
#pragma optimization_level 2
