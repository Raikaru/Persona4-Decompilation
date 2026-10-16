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

extern void func_004b3110(s32 arg0);
extern u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                          P4CameraFrame *firstOut, P4CameraFrame *secondOut);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 RwV3dNormalize(RwV3d *arg0, const RwV3d *arg1);
extern f32 RwV3dLength(f32 *arg0);
extern void btlCameraCopyPose();
extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *out);
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
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg3, u16 arg4);
extern void func_0019de70(BtlUnitStateWork *work, u16 value);
extern s32 btlCameraUnitAnimFinished(u8 *arg0, u8 *arg1);
extern void btlCameraFrameStatus(u8 *arg0, s32 arg1);
extern void btlMainCurveSetPoses(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
extern void btlCameraSetDuration(u8 *arg0, f32 arg1);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern s32 btlActionHasNoTargetClass(u8 *arg0);
extern void btlCameraFrameWithFlags(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern s32 btlCameraIsActionBlocked(u8 *arg0);
extern s32 btlTargetGetUnitIndex(u8 *arg0);
extern s32 func_001f1030(u8 *arg0);
extern s32 func_001f11e0(s16 arg0);
extern s32 func_001f1210(u8 *arg0, s16 arg1, s32 arg2);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 btlUnitSkillBlocked(u8 *arg0, u8 *arg1);
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
extern RwMatrix *RwMatrixRotate(RwMatrix *arg0, const RwV3d *arg1, f32 arg2, s32 arg3);
extern RwV3d *func_003e4320(RwV3d *arg0, const RwV3d *arg1, const RwMatrix *arg2);
extern void btlCameraLookAtQuat(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern u8 D_0060A0D0[];
extern u8 D_0060A0E0[];
extern RwV3d D_0060A0F0;
extern u8 D_0060A100[];
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

/* Source unit: src/promoted/code1_001c.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001c.c; members 001c0e40-001c5b80 */

// FUN_001C0E40
void func_001c0e40(void) {}

// FUN_001C0E50
s32 btlCameraSelectMode(u8 *arg0) {
    s16 mode;
    s32 state;
    s32 check;
    s32 result;
    u8 *work;
    u8 *data;
    u8 *other;

    work = *(u8 **)(arg0 + 0xE0);
    mode = *(s16 *)(work + 0x6E);
    if (btlActionHasNoTargetClass(work) != 0) {
        data = *(u8 **)(arg0 + 0xE0);
        if (*(s32 *)(data + 0x38) == (s32)data) {
            return 1;
        }
        if (btlCameraIsActionBlocked(arg0) != 0) {
            return 2;
        }
        if (func_001f11e0(mode) == 0) {
            return 2;
        }
        other = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
        if ((*(u8 *)(other + 0xA2) == 0) &&
            (func_001f1210(*(u8 **)(other + 0xA0C), mode, 1) == 0)) {
            return 2;
        }
        return 4;
    }
    state = btlTargetGetUnitIndex(*(u8 **)(arg0 + 0xE0) + 0x38) & 0xFFFF;
    if (((state & 3) == 3) ||
        (((check = *(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA64),
           check != 0) &&
          (datCalcChkBadStatus(check, 0x100) != 0)))) {
        return 6;
    }
    work = *(u8 **)(arg0 + 0xE0);
    if ((*(u8 *)(*(u8 **)(work + 0x30) + 0xA2) == 0) && ((state & 1) != 0)) {
        if (func_001f1030(work) != 0) {
            return 6;
        }
        data = *(u8 **)(arg0 + 0xE0);
        if (*(s32 *)(data + 0x38) == (s32)data) {
            return 1;
        }
        if (func_001f11e0(mode) != 0) {
            result = 4;
        } else {
            result = 2;
        }
        return result;
    }
    if (func_001f11e0(mode) == 0) {
        return 3;
    }
    return 5;
}

/* Frame the acting unit and group with two complete camera poses. */
// FUN_001C1040
void btlCameraFrameRandomOrbit(u8 *camera, s32 unused)
{
    extern s32 btlCameraIsTargetPrioritized(s32 cameraAddress);
    extern s32 btlCameraIsTargetEligible(u8 *camera);
    extern void btlCameraCopyPose(f32 *out, f32 *in);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 fGpffff8128;
    extern f32 fGpffff807c;
    extern f32 tanf(f32 camera);
    f32 top;
    RwV3d unitCenter;
    RwV3d groupCenter;
    RwV3d eye;
    RwV3d direction;
    RwV3d delta;
    RwV3d focus;
    RwV3d branchGroundPoint;
    P4CameraVec2 horizontal;
    RwV3d groundPoint;
    RwMatrix matrix;
    P4CameraFrame frames[2];
    f32 groupRadius;
    f32 cameraDistance;
    f32 halfFov;
    f32 angleToRadians;
    f32 lateralOffset;
    f32 scale;
    f32 x;
    f32 y;
    f32 z;
    u8 *unit;
    u8 *resource;

    (void)unused;
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
    groupRadius = btlUnitGetGroupBounds(3, 1, &groupCenter, &top, 0, 0);
    if (btlCameraIsTargetPrioritized((s32)camera) != 0 || btlCameraIsTargetEligible(camera) != 0) {
        resource = *(u8 **)(unit + 0xA0C);
        if (resource != 0) {
            func_0019de70((BtlUnitStateWork *)resource, 0);
            *(u8 **)(camera + 0x12C) = *(u8 **)(unit + 0xA0C);
            *(s16 *)(camera + 0x130) = 1;
        }
        groupCenter.y = 0.75f * top;
        unitCenter.y = groupCenter.y;
        halfFov = 0.5f;
        angleToRadians = fGpffff8110;
        cameraDistance = groupRadius / tanf(angleToRadians * (halfFov * *(f32 *)(camera + 0xB8)));
        if (cameraDistance < 1000.0f) cameraDistance = 1000.0f;
        if (groupCenter.x == unitCenter.x && groupCenter.z == unitCenter.z) {
            direction = D_0060A0F0;
        } else {
            direction.x = groupCenter.x - unitCenter.x;
            direction.y = groupCenter.y - unitCenter.y;
            direction.z = groupCenter.z - unitCenter.z;
            RwV3dNormalize(&direction, &direction);
        }
        x = direction.x * groupRadius;
        direction.x = x;
        y = direction.y * groupRadius;
        direction.y = y;
        z = direction.z * groupRadius;
        direction.z = z;
        eye.x = groupCenter.x + x;
        eye.y = groupCenter.y + y;
        eye.z = groupCenter.z + z;
        eye.y = 1.25f * top;
    } else {
        resource = *(u8 **)(unit + 0xA0C);
        if (resource != 0) {
            func_0019de70((BtlUnitStateWork *)resource, 0);
            *(u8 **)(camera + 0x12C) = *(u8 **)(unit + 0xA0C);
            *(s16 *)(camera + 0x130) = 1;
        }
        groupCenter.y = 0.75f * top;
        unitCenter.y = groupCenter.y;
        halfFov = 0.5f;
        angleToRadians = fGpffff8110;
        cameraDistance = groupRadius / tanf(angleToRadians * (halfFov * *(f32 *)(camera + 0xB8)));
        if (cameraDistance < 1200.0f) cameraDistance = 1200.0f;
        if (groupCenter.x == unitCenter.x && groupCenter.z == unitCenter.z) {
            direction = D_0060A0F0;
        } else {
            direction.x = groupCenter.x - unitCenter.x;
            direction.y = groupCenter.y - unitCenter.y;
            direction.z = groupCenter.z - unitCenter.z;
            RwV3dNormalize(&direction, &direction);
        }
        x = direction.x * groupRadius;
        direction.x = x;
        y = direction.y * groupRadius;
        direction.y = y;
        z = direction.z * groupRadius;
        direction.z = z;
        eye.x = groupCenter.x + x;
        eye.y = groupCenter.y + y;
        eye.z = groupCenter.z + z;
        eye.y = fGpffff807c * top;
        if (!(eye.y <= 200.0f)) eye.y = 200.0f;
        branchGroundPoint = eye;
        branchGroundPoint.y = groupCenter.y;
        delta.x = branchGroundPoint.x - groupCenter.x;
        delta.y = branchGroundPoint.y - groupCenter.y;
        delta.z = branchGroundPoint.z - groupCenter.z;
        scale = fGpffff8128 * RwV3dNormalize(&delta, &delta);
        x = delta.x * scale;
        focus.x = x;
        y = delta.y * scale;
        focus.y = y;
        z = delta.z * scale;
        focus.z = z;
        focus.x = x + groupCenter.x;
        focus.y = y + groupCenter.y;
        focus.z = z + groupCenter.z;
    }
    groundPoint = eye;
    groundPoint.y = groupCenter.y;
    delta.x = groundPoint.x - groupCenter.x;
    delta.y = groundPoint.y - groupCenter.y;
    delta.z = groundPoint.z - groupCenter.z;
    scale = fGpffff8128 * RwV3dNormalize(&delta, &delta);
    x = delta.x * scale;
    focus.x = x;
    y = delta.y * scale;
    focus.y = y;
    z = delta.z * scale;
    focus.z = z;
    focus.x = x + groupCenter.x;
    focus.y = y + groupCenter.y;
    focus.z = z + groupCenter.z;
    btlCameraLookAtQuat(&frames[1].rot, &eye, &focus, D_0060A0E0);
    direction.x = eye.x - focus.x;
    direction.y = eye.y - focus.y;
    direction.z = eye.z - focus.z;
    RwV3dNormalize(&direction, &direction);
    lateralOffset = cameraDistance * tanf(angleToRadians * (halfFov * *(f32 *)(camera + 0xB8)));
    lateralOffset *= 0.21875f;
    horizontal.x = direction.x;
    horizontal.y = direction.z;
    func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
    focus.x = (0.0f + focus.x) + horizontal.y * lateralOffset;
    focus.z = (0.0f + focus.z) - horizontal.x * lateralOffset;
    x = direction.x * cameraDistance;
    delta.x = x;
    y = direction.y * cameraDistance;
    delta.y = y;
    z = direction.z * cameraDistance;
    delta.z = z;
    frames[1].pos.x = focus.x + x;
    frames[1].pos.y = focus.y + y;
    frames[1].pos.z = focus.z + z;
    if (effMiscRand(0) & 1) {
        RwMatrixRotate(&matrix, (const RwV3d *)D_0060A0E0, -30.0f, 0);
    } else {
        RwMatrixRotate(&matrix, (const RwV3d *)D_0060A0E0, 30.0f, 0);
    }
    func_003e4320(&delta, &direction, &matrix);
    x = delta.x * cameraDistance;
    delta.x = x;
    y = delta.y * cameraDistance;
    delta.y = y;
    z = delta.z * cameraDistance;
    delta.z = z;
    frames[0].pos.x = focus.x + x;
    frames[0].pos.y = focus.y + y;
    frames[0].pos.z = focus.z + z;
    btlCameraLookAtQuat(&frames[0].rot, (f32 *)&frames[0], &focus, D_0060A0E0);
    func_004b3110(8);
    btlCameraClampOffsetToLimit((f32 *)&frames[0], (f32 *)&frames[0]);
    btlCameraClampOffsetToLimit((f32 *)&frames[1], (f32 *)&frames[1]);
    if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
    if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, 10.0f);
}

/* Build the two animation or orbit camera poses around the acting unit.
 * Vector snapshots, horizontal directions and pose frames are complete objects. */
// FUN_001C17A0
void btlCameraFrameRandomEntry(u8 *camera, s32 notify, s32 unused)
{
    RwV3d orbitDirection;
    RwV3d animationPosition;
    RwV3d focus;
    RwV3d baseCenter;
    RwV3d unitCenter;
    RwV3d secondaryCenter;
    RwV3d position;
    RwV3d forward;
    P4CameraVec2 horizontal;
    RwV3d savedCenter;
    struct {
        P4CameraVec2 unitHorizontal;
        P4CameraVec2 cameraHorizontal;
        P4CameraFrame frames[2];
    } transition;
    RwMatrix matrix;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern s32 btlCameraIsOrbitAction(u8 *camera);
    extern f32 func_003e41e0(f32 *camera, f32 *notify);
    extern f32 tanf(f32 camera);
    extern f32 fGpffff80e8;
    extern f32 fGpffff8110;
    s32 useOrbit;
    u8 *work;
    u8 *unit;
    u8 *target;
    u16 *animation;
    s32 frameCount;
    f32 rawRadius;
    f32 firstOffset;
    f32 orbitRadius;
    f32 cameraDistance;
    f32 secondOffset;
    f32 unitHeight;
    f32 minimumHeight;
    f32 sideDot;
    f32 baseY;
    f32 baseZ;
    (void)unused;
    useOrbit = btlCameraIsOrbitAction(camera) != 0;
    work = *(u8 **)(camera + 0xE0);
    if ((*(u16 *)(work + 0x1A) & 0x10) == 0) {
        return;
    }
    unit = *(u8 **)(work + 0x30);
    target = *(u8 **)(unit + 0xA0C);
    if (useOrbit == 0) {
        animation = (u16 *)btlCameraRandomTableEntry(*(u16 *)(target + 0xA4), 1);
        if ((*(u16 *)(iGpffffb3e0 + *(u16 *)(target + 0xA4) * 0x58) & 1) == 0) {
            func_0019de70((BtlUnitStateWork *)target, 0);
        } else {
            func_0019de70((BtlUnitStateWork *)target, 1);
        }
        RtQuatTransformVectors((RwV3d *)&animationPosition, (const RwV3d *)((u8 *)animation + 4), 1, (const RtQuat *)(unit + 0x1C));
        RtQuatTransformVectors((RwV3d *)&focus, (const RwV3d *)((u8 *)animation + 0x1C), 1, (const RtQuat *)(unit + 0x1C));
        btlCameraLookAtQuat(&transition.frames[0].rot, &animationPosition, &focus, D_0060A0E0);
        transition.frames[0].pos.x = animationPosition.x + *(f32 *)(unit + 4);
        transition.frames[0].pos.y = animationPosition.y + *(f32 *)(unit + 8);
        transition.frames[0].pos.z = animationPosition.z + *(f32 *)(unit + 0xC);
        RtQuatTransformVectors((RwV3d *)&animationPosition, (const RwV3d *)((u8 *)animation + 0x10), 1, (const RtQuat *)(unit + 0x1C));
        RtQuatTransformVectors((RwV3d *)&focus, (const RwV3d *)((u8 *)animation + 0x28), 1, (const RtQuat *)(unit + 0x1C));
        btlCameraLookAtQuat(&transition.frames[1].rot, &animationPosition, &focus, D_0060A0E0);
        transition.frames[1].pos.x = animationPosition.x + *(f32 *)(unit + 4);
        transition.frames[1].pos.y = animationPosition.y + *(f32 *)(unit + 8);
        transition.frames[1].pos.z = animationPosition.z + *(f32 *)(unit + 0xC);
        frameCount = *animation;
    } else {
        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
        btlUnitGetSphereWorldCenter((BtlUnit *)target, &secondaryCenter);
        unitHeight = 0.0f + unitCenter.y + 0.5f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        rawRadius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
        savedCenter = unitCenter;
        baseCenter = savedCenter;
        focus = savedCenter;
        minimumHeight = 1.0f + unitHeight;
        orbitRadius = 5.0f * rawRadius;
        transition.cameraHorizontal.x = *(f32 *)(camera + 0x9C) - focus.x;
        transition.cameraHorizontal.y = *(f32 *)(camera + 0xA4) - focus.z;
        func_003e41e0((f32 *)&transition.cameraHorizontal, (f32 *)&transition.cameraHorizontal);
        RtQuatTransformVectors((RwV3d *)&forward, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
        transition.unitHorizontal.x = forward.z;
        transition.unitHorizontal.y = -forward.x;
        func_003e41e0((f32 *)&transition.unitHorizontal, (f32 *)&transition.unitHorizontal);
        sideDot = transition.unitHorizontal.x * transition.cameraHorizontal.x + transition.unitHorizontal.y * transition.cameraHorizontal.y;
        if (!(sideDot < 0.0f)) {
            RwMatrixRotate((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, 37.5f, 0);
        } else {
            RwMatrixRotate((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, -37.5f, 0);
        }
        func_003e4320((RwV3d *)&orbitDirection, (const RwV3d *)&forward, (const RwMatrix *)&matrix);
        orbitDirection.x = orbitDirection.x * orbitRadius;
        orbitDirection.y = orbitDirection.y * orbitRadius;
        orbitDirection.z = orbitDirection.z * orbitRadius;
        position.x = orbitDirection.x + baseCenter.x;
        baseY = baseCenter.y;
        position.y = orbitDirection.y + baseY;
        baseZ = baseCenter.z;
        position.z = orbitDirection.z + baseZ;
        if (unitHeight < minimumHeight) {
            position.y = fGpffff80e8 * minimumHeight;
        }
        orbitDirection.x = position.x - focus.x;
        orbitDirection.y = position.y - focus.y;
        orbitDirection.z = position.z - focus.z;
        RwV3dNormalize((RwV3d *)&orbitDirection, (const RwV3d *)&orbitDirection);
        btlCameraLookAtQuat(&transition.frames[1].rot, &position, &focus, D_0060A0E0);
        cameraDistance = orbitRadius / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        secondOffset = cameraDistance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        secondOffset *= 0.21875f;
        horizontal.x = orbitDirection.x;
        horizontal.y = orbitDirection.z;
        func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
        focus.x = 0.0f + focus.x + horizontal.y * secondOffset;
        focus.z = 0.0f + focus.z - horizontal.x * secondOffset;
        position.x = orbitDirection.x * cameraDistance;
        position.y = orbitDirection.y * cameraDistance;
        position.z = orbitDirection.z * cameraDistance;
        transition.frames[1].pos.x = focus.x + position.x;
        transition.frames[1].pos.y = focus.y + position.y;
        transition.frames[1].pos.z = focus.z + position.z;
        if (!(sideDot < 0.0f)) {
            RwMatrixRotate((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, 70.0f, 0);
        } else {
            RwMatrixRotate((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, -70.0f, 0);
        }
        func_003e4320((RwV3d *)&orbitDirection, (const RwV3d *)&forward, (const RwMatrix *)&matrix);
        orbitDirection.x = orbitDirection.x * orbitRadius;
        orbitDirection.y = orbitDirection.y * orbitRadius;
        orbitDirection.z = orbitDirection.z * orbitRadius;
        position.x = orbitDirection.x + baseCenter.x;
        position.y = orbitDirection.y + baseY;
        position.z = orbitDirection.z + baseZ;
        if (unitHeight < minimumHeight) {
            position.y = fGpffff80e8 * minimumHeight;
        }
        orbitDirection.x = position.x - focus.x;
        orbitDirection.y = position.y - focus.y;
        orbitDirection.z = position.z - focus.z;
        RwV3dNormalize((RwV3d *)&orbitDirection, (const RwV3d *)&orbitDirection);
        focus = savedCenter;
        btlCameraLookAtQuat(&transition.frames[0].rot, &position, &focus, D_0060A0E0);
        firstOffset = cameraDistance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        firstOffset *= 0.21875f;
        horizontal.x = orbitDirection.x;
        horizontal.y = orbitDirection.z;
        func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
        focus.x = 0.0f + focus.x + horizontal.y * firstOffset;
        focus.z = 0.0f + focus.z - horizontal.x * firstOffset;
        position.x = orbitDirection.x * cameraDistance;
        position.y = orbitDirection.y * cameraDistance;
        position.z = orbitDirection.z * cameraDistance;
        transition.frames[0].pos.x = focus.x + position.x;
        transition.frames[0].pos.y = focus.y + position.y;
        transition.frames[0].pos.z = focus.z + position.z;
        frameCount = 0x4B;
    }
    func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 1);
    btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24), (f32 *)&transition.frames[0].pos, (f32 *)&transition.frames[1].pos, 1);
    btlCameraSetDuration(iGpffffb3ac + 0x24, (f32)frameCount / 30.0f);
    if (notify != 0) {
        func_004b3110(8);
    }
}

// FUN_001C1F70
void btlCameraEnterRandomFrame(u8 *arg0)
{
    struct Frame {
        f32 value50;
        f32 value54;
        f32 value58;
        f32 value5C;
        f32 value60;
        f32 value64;
        f32 value68;
        f32 value6C;
        f32 value70;
        f32 value74;
        f32 value78;
        f32 value7C;
        f32 value80;
        f32 value84;
        f32 value88;
        f32 value8C;
        f32 value90;
        f32 value94;
        f32 value98;
        f32 value9C;
        f32 valueA0;
        f32 valueA4;
        f32 valueA8;
    } frame;
    f32 var_f1;
    u16 *temp_16;
    u16 temp_2;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if ((*(u16 *)(temp_4 + 0x1A) & 0x10) != 0) {
        temp_17 = *(u8 **)(temp_4 + 0x30);
        temp_18 = *(u8 **)(temp_17 + 0xA0C);
        temp_16 = (u16 *)btlCameraRandomTableEntry(*(u16 *)(temp_18 + 0xA4), 0);
        if ((*(u16 *)(iGpffffb3e0 +
                      *(u16 *)(temp_18 + 0xA4) * 0x58) & 1) == 0) {
            func_0019de70((BtlUnitStateWork *)temp_18, 0);
        } else {
            func_0019de70((BtlUnitStateWork *)temp_18, 1);
        }
        RtQuatTransformVectors((RwV3d *)&frame.valueA0,
                      (const RwV3d *)((u8 *)temp_16 + 4),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        RtQuatTransformVectors((RwV3d *)&frame.value90,
                      (const RwV3d *)((u8 *)temp_16 + 0x1C),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        btlCameraLookAtQuat(&frame.value5C, &frame.valueA0,
                      &frame.value90, D_0060A0E0);
        frame.value50 = frame.valueA0 + *(f32 *)(temp_17 + 4);
        frame.value54 = frame.valueA4 + *(f32 *)(temp_17 + 8);
        frame.value58 = frame.valueA8 + *(f32 *)(temp_17 + 0xC);
        RtQuatTransformVectors((RwV3d *)&frame.valueA0,
                      (const RwV3d *)((u8 *)temp_16 + 0x10),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        RtQuatTransformVectors((RwV3d *)&frame.value90,
                      (const RwV3d *)((u8 *)temp_16 + 0x28),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        btlCameraLookAtQuat(&frame.value78, &frame.valueA0,
                      &frame.value90, D_0060A0E0);
        frame.value6C = frame.valueA0 + *(f32 *)(temp_17 + 4);
        frame.value70 = frame.valueA4 + *(f32 *)(temp_17 + 8);
        frame.value74 = frame.valueA8 + *(f32 *)(temp_17 + 0xC);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
        btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24), &frame.value50, &frame.value6C, 1);
        temp_2 = *temp_16;
        var_f1 = (f32)(u16)temp_2;
        btlCameraSetDuration(iGpffffb3ac + 0x24, var_f1 / 30.0f);
    }
}

/* cold 001c21d0 (2026-09-18): refused - outside 3% count gate, production stays INCLUDE_ASM. */
/* probe 689 via `python3 tools/probe_variants.py src/promoted/code1_001c.c btlCameraFrameDistinctPair --candidate commons_off=/var/tmp/cold1c21d0/v3_commons_off.c` (v1 695, v3 696, v4 696, decl swaps tie 689); fnalign retail 833 vs object 710 instrs (123 short, -14.8%; gate 808-858) 1026 edits (+2 reloc-only) via `python3 -E -s tools/fnalign.py src/promoted/code1_001c.c btlCameraFrameDistinctPair --candidate /var/tmp/cold1c21d0/v3_commons_off.c --quiet`. M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c btlCameraFrameDistinctPair -o /var/tmp/cold1c21d0/m2c.c`; romwright via `python3 -E -s tools/romwright_decompile.py btlCameraFrameDistinctPair > /var/tmp/cold1c21d0/rw.c` (--types: arity 3, arg0 pointer, arg1/2 scalar; prologue reads $4/$5/$6 before write, so (u8 *, s32, s32) stands) plus --raw. De-noised to file idiom reusing existing decls (func_00195850, func_0022f950, func_001bc330/0240/01b0, func_003e40b0, func_003e41e0, func_003dcb40, btlCameraLookAtQuat, btlTargetAngleBetween, func_0044b868, func_004bd050, func_001bac20/bbef0/9de70/bcd40). Read btlCameraFrameStatus MATCH note (7p snapshot placement: before first Y output 0, one statement earlier 5, three earlier 20) and code1_001f.c func_001f4e50 57->13 (row address plus two element pointers dereferenced at zero, second assigned lazily). Recipe in order: (1) free pragmas - opt_common_subs off 696->689 scoped push/pop, opt_loop_invariants on tie, opt_unroll_loops off tie, schedule off tie; (2) subscript form - no variable index in this unit (constant 0x2C/0x8C/0x90/0xA4 field loads), P[i] probe not applicable; (3) fresh loop counters (7n) - no backwards branches in retail (all forward b/bc1, zero for/while in either decompiler), nothing to split; (4) colouring - decl swaps for temp_v9/temp_v12 and vis21/alt16 tie at 689. Branch-order fix (romwright swapped the two large arms: 1.25f path first vs retail 2.5f path first) moved fnalign 960->929 edits but words 695->696. Width fixes (u64->u32, int quat->f32) scored 696. Two non-improving rounds above 60, stopping per batch. Gap lives in missing aggregate spills, not calls: jal counts exact both sides (4x00195850, 3x0019de70, 1x001bac20/bbef0/bc1b0/bc240/bc330/bcd40, 3x001bd780, 2x001ec3d0, 1x0022f950, 2x003dcb40, 1x003e0870, 2x003e40b0/41e0, 1x003e4320, 3x0044b868, 1x004b3110/bd050); frame retail -0x200 vs object -0x140 (192B of spills absent); largest fnalign holes are retail[434:471] 37 vs object 1 (quatFC copy plus out10C add plus 25.0 clamp), retail[138:156] 18 (0x2EE/cvt plus fGp80fc/8140 select plus fGp8118 scale), retail[565:585] 20. Excluded: scheduling (off tie), loop-invariant hoists, unrolling, declaration colouring, inverted-condition vs swapped-arm spellings. Best candidate kept at /var/tmp/cold1c21d0/v3_commons_off.c (689) for the next pass, which should rebuild it on a Frame from 0xB0 to 0x1F8 with 16-byte-aligned vector/quat fields. */
/* cold 001c21d0 (2026-09-19): honest redo per Main — 138:156 recovered (18, real, explicit (f32)0x2EE + volatile f32, gone from >15 list); surplus at 740:761 removed (pure-float 548 vs 833 -285 774 edits, no object-larger vs baseline 710 with 11 vs 40 + 9 vs 41); 434:471 37 vs 1 (quatFC copy + out10C add + 25.0 clamp) and 565:585 24 vs 1 (saves + madd) still missing (61); volatile 855 vs 836 +19 1008 edits frame -0x200 vs -0x180 128B game jal 32 exact in band only via cancelling (61 missing +64 lump 21 vs 85 at 740:761) refused per 7u; production stays INCLUDE_ASM. */
/* Construct side or approach camera poses from actor and target geometry. */
// FUN_001C21D0
void btlCameraFrameDistinctPair(u8 *camera, s32 notify, s32 distinctPoses)
{
    extern s32 btlCameraIsOrbitAction(u8 *camera);
    extern s32 btlCameraIsTargetPrioritized(s32 cameraAddress);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern s32 btlCameraIsTargetEligible(u8 *camera);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *out);
    extern f32 tanf(f32 angle);
    extern f32 fGpffff8030;
    extern f32 fGpffff8098;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    extern f32 fGpffff8138;
    extern f32 fGpffff813c;
    extern f32 fGpffff8140;
    RwV3d unitCenter;
    RwV3d targetCenter;
    RwV3d resourceCenter;
    RwV3d snapshotCenter;
    RwV3d focus;
    RwV3d direction;
    RwV3d eye;
    RwV3d savedDirection;
    P4CameraVec2 projectedCenter;
    P4CameraVec2 projection;
    P4CameraVec2 horizontal;
    RwV3d rotatedUp;
    struct {
        P4CameraVec2 sideDirection;
        P4CameraVec2 cameraHorizontal;
        P4CameraVec2 focus;
        P4CameraVec2 eye;
    } plane;
    P4CameraFrame frames[2];
    RwMatrix matrix;
    u8 *work;
    u8 *target;
    u8 *resource;
    u8 *unit;
    s32 resourceMode;
    s32 alternateMode;
    s32 forceSide;
    f32 centerDistance;
    f32 frameRadius;
    f32 actorTop;
    f32 targetTop;
    f32 resourceTop;
    f32 extentScale;
    f32 sideDot;
    f32 lineDistance;

    work = *(u8 **)(camera + 0xE0);
    unit = *(u8 **)(work + 0x30);
    target = *(u8 **)(*(u8 **)(work + 0x38) + 0x30);
    resource = *(u8 **)(unit + 0xA0C);
    extentScale = 1.0f;
    resourceMode = btlUnitSkillBlocked(work, resource) != 0;
    alternateMode = btlCameraIsOrbitAction(camera) != 0;
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
    btlUnitGetSphereWorldCenter((BtlUnit *)resource, &resourceCenter);
    actorTop = 0.0f + unitCenter.y + 0.5f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    resourceTop = 0.0f + resourceCenter.y + 0.5f * (*(f32 *)(resource + 0x8C) * *(f32 *)(resource + 0x2C));
    if ((resourceMode == 0) && (actorTop < resourceTop) && (alternateMode == 0)) {
        unitCenter.y = 0.25f * (actorTop + resourceTop);
        actorTop = resourceTop;
    }
    frameRadius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    {
        f32 resourceRadius = *(f32 *)(resource + 0x90) * *(f32 *)(resource + 0x2C);
        if ((resourceMode == 0) && (frameRadius < resourceRadius) && (alternateMode == 0)) {
            frameRadius = resourceRadius;
        }
    }
    if (frameRadius < 50.0f) frameRadius = 50.0f;
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetCenter);
    {
        targetTop = 0.0f + targetCenter.y + 0.5f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
        if (!(targetTop < 450.0f)) {
            targetCenter.y = (0.0f + targetCenter.y) - fGpffff8098 * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
            targetTop = 450.0f;
        }
    }
    forceSide = btlCameraIsTargetPrioritized((s32)camera);
    if ((alternateMode == 0) && (forceSide == 0) && ((*(u16 *)(iGpffffb3e0 + *(u16 *)(resource + 0xA4) * 0x58) & 1) != 0)) {
        if (resourceTop < (f32)0x2EE) {
            unitCenter.y = fGpffff80fc * resourceTop;
        } else {
            unitCenter.y = fGpffff8140 * resourceTop;
        }
        targetCenter.y = fGpffff8118 * targetTop;
        extentScale = 1.5f;
    }
    direction.x = unitCenter.x - targetCenter.x;
    direction.y = unitCenter.y - targetCenter.y;
    direction.z = unitCenter.z - targetCenter.z;
    centerDistance = RwV3dNormalize((RwV3d *)&direction, (const RwV3d *)&direction);
    {
        f32 focusScale = fGpffff8128 * centerDistance;
        focus.x = direction.x * focusScale;
        focus.y = direction.y * focusScale;
        focus.z = direction.z * focusScale;
        focus.x = focus.x + targetCenter.x;
        focus.y = focus.y + targetCenter.y;
        focus.z = focus.z + targetCenter.z;
    }
    plane.cameraHorizontal.x = *(f32 *)(camera + 0x9C) - focus.x;
    plane.cameraHorizontal.y = *(f32 *)(camera + 0xA4) - focus.z;
    func_003e41e0((f32 *)&plane.cameraHorizontal, (f32 *)&plane.cameraHorizontal);
    if ((forceSide != 0) || (((effMiscRand(0) & 1) != 0) && (btlCameraIsTargetEligible(camera) != 0))) {
        f32 sideRadius;
        f32 targetHeightProduct;
        f32 tilt;
        func_0019de70((BtlUnitStateWork *)resource, 1);
        *(u8 **)(camera + 0x12C) = resource;
        *(u16 *)(camera + 0x130) = 0;
        unit = target;
        snapshotCenter = unitCenter;
        sideRadius = 2.25f * frameRadius;
        extentScale = p4_cacd0_mul(fGpffff8138, extentScale);
        plane.sideDirection.x = direction.z;
        plane.sideDirection.y = -direction.x;
        sideDot = plane.sideDirection.x * plane.cameraHorizontal.x + plane.sideDirection.y * plane.cameraHorizontal.y;
        if (actorTop < targetTop) {
            eye.y = 0.0f + snapshotCenter.y + fGpffff8030 * actorTop;
        } else {
            eye.y = (0.0f + snapshotCenter.y) - fGpffff8030 * actorTop;
        }
        if (!(sideDot < 0.0f)) {
            eye.x = 0.0f + snapshotCenter.x + direction.z * sideRadius;
            eye.z = (0.0f + snapshotCenter.z) - direction.x * sideRadius;
        } else {
            eye.x = (0.0f + snapshotCenter.x) - direction.z * sideRadius;
            eye.z = 0.0f + snapshotCenter.z + direction.x * sideRadius;
            {
                f32 halfDistance = 0.5f * centerDistance;
                focus.x = direction.x * halfDistance;
                focus.y = direction.y * halfDistance;
                focus.z = direction.z * halfDistance;
                focus.x = focus.x + targetCenter.x;
                focus.y = focus.y + targetCenter.y;
                focus.z = focus.z + targetCenter.z;
            }
        }
        targetHeightProduct = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
        focus.y = (0.0f + focus.y) + fGpffff8030 * targetHeightProduct;
        if (sideDot >= 0.0f) tilt = 2.5f;
        else tilt = -2.5f;
        RwMatrixRotate(&matrix, &D_0060A0F0, tilt, 0);
        func_003e4320((RwV3d *)&rotatedUp, (const RwV3d *)D_0060A0E0, (const RwMatrix *)&matrix);
        btlCameraLookAtQuat(&frames[0].rot.quat, &eye, &focus, &rotatedUp);
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = btlTargetAngleBetween((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        extentScale = 0.0f + lineDistance + frameRadius * extentScale;
        eye.x = projection.x;
        eye.y = 0.0f + snapshotCenter.y + 0.25f * actorTop;
        eye.z = projection.y;
        extentScale = extentScale / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        direction.x = direction.x * extentScale;
        direction.y = direction.y * extentScale;
        direction.z = direction.z * extentScale;
        if (sideDot < 0.0f) {
            extentScale = extentScale * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
            extentScale *= 0.21875f;
            extentScale *= 1.25f;
            horizontal.x = direction.x;
            horizontal.y = direction.z;
            func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
            eye.x = 0.0f + eye.x + horizontal.y * extentScale;
            eye.z = (0.0f + eye.z) - horizontal.x * extentScale;
        }
        frames[1].rot.quat = frames[0].rot.quat;
        frames[1].pos.x = eye.x + direction.x;
        frames[1].pos.y = eye.y + direction.y;
        frames[1].pos.z = eye.z + direction.z;
        if (frames[1].pos.y < 25.0f) {
            frames[1].pos.y = 25.0f;
        }
        eye.y = (0.0f + eye.y) - fGpffff8118 * actorTop;
        frames[0].pos.x = eye.x + direction.x;
        frames[0].pos.y = eye.y + direction.y;
        frames[0].pos.z = eye.z + direction.z;
        if (frames[0].pos.y < 25.0f) {
            frames[0].pos.y = 25.0f;
        }
        extentScale = 3.0f;
    } else {
        f32 targetRadius;
        f32 targetExtent;
        f32 sideDot;
        if ((*(u16 *)(iGpffffb3e0 + *(u16 *)(resource + 0xA4) * 0x58) & 1) == 0) {
            func_0019de70((BtlUnitStateWork *)resource, 0);
        } else {
            func_0019de70((BtlUnitStateWork *)resource, 1);
        }
        *(u8 **)(camera + 0x12C) = resource;
        *(u16 *)(camera + 0x130) = 1;
        snapshotCenter = targetCenter;
        targetRadius = 1.25f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        targetExtent = 1.5f * extentScale;
        if (snapshotCenter.y < 125.0f) {
            snapshotCenter.y = 125.0f;
        }
        plane.sideDirection.x = direction.z;
        plane.sideDirection.y = -direction.x;
        sideDot = plane.sideDirection.x * plane.cameraHorizontal.x + plane.sideDirection.y * plane.cameraHorizontal.y;
        eye.y = snapshotCenter.y;
        if (!(sideDot < 0.0f)) {
            eye.x = 0.0f + snapshotCenter.x + direction.z * targetRadius;
            eye.z = (0.0f + snapshotCenter.z) - direction.x * targetRadius;
            savedDirection = direction;
        } else {
            eye.x = (0.0f + snapshotCenter.x) - direction.z * targetRadius;
            eye.z = 0.0f + snapshotCenter.z + direction.x * targetRadius;
        }
        btlCameraLookAtQuat(&frames[0].rot.quat, &eye, &focus, D_0060A0E0);
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = btlTargetAngleBetween((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        targetExtent = 0.0f + lineDistance + targetExtent * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        eye.x = projection.x;
        eye.y = snapshotCenter.y;
        eye.z = projection.y;
        {
            f32 cameraDistance = targetExtent / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
            if (cameraDistance < (f32)0x226) {
                cameraDistance = (f32)0x226;
            }
            direction.x = direction.x * cameraDistance;
            direction.y = direction.y * cameraDistance;
            direction.z = direction.z * cameraDistance;
        }
        if (!(sideDot < 0.0f)) {
            f32 targetHalfRadius = 0.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            eye.x = (0.0f + eye.x) - savedDirection.z * targetHalfRadius;
            eye.z = 0.0f + eye.z + savedDirection.x * targetHalfRadius;
        }
        frames[0].pos.x = eye.x + direction.x;
        frames[0].pos.y = eye.y + direction.y;
        frames[0].pos.z = eye.z + direction.z;
        frames[1].rot.quat = frames[0].rot.quat;
        frames[1].pos = frames[0].pos;
        direction.x = unitCenter.x - frames[1].pos.x;
        direction.y = unitCenter.y - frames[1].pos.y;
        direction.z = unitCenter.z - frames[1].pos.z;
        centerDistance = RwV3dNormalize((RwV3d *)&direction, (const RwV3d *)&direction);
        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &snapshotCenter);
        snapshotCenter.y = 0.0f + snapshotCenter.y + 0.25f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        btlCameraLookAtQuat(&frames[0].rot.quat, &frames[1].pos, (f32 *)&snapshotCenter, D_0060A0E0);
        {
            f32 approachScale = fGpffff813c * centerDistance;
            direction.x = direction.x * approachScale;
            direction.y = direction.y * approachScale;
            direction.z = direction.z * approachScale;
            frames[0].pos.x = frames[1].pos.x + direction.x;
            frames[0].pos.y = frames[1].pos.y + direction.y;
            frames[0].pos.z = frames[1].pos.z + direction.z;
        }
        if (frames[0].pos.y < 25.0f) {
            frames[0].pos.y = 25.0f;
        }
        if (frames[1].pos.y < 25.0f) {
            frames[1].pos.y = 25.0f;
        }
        extentScale = 2.25f;
    }
    if (distinctPoses == 0) {
        frames[0].pos = frames[1].pos;
        frames[0].rot.quat = frames[1].rot.quat;
    }
    func_001bcd40(*(u8 **)(camera + 0xE0), unit + 4, (f32 *)&frames[0].pos, 50.0f, 3);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0].pos, (f32 *)&frames[1].pos, 1);
    btlCameraSetDuration(camera, extentScale);
    if (notify != 0) {
        func_004b3110(8);
    }
}

/* cold 001c2ee0 (2026-09-18): faithful direction only - production stays INCLUDE_ASM. */
/* counts: retail 1012 header (1009 fnalign) vs 793 faithful (762 v1 +31); band 982-1042 -> OUTSIDE (189 short of floor). Faithful = 3 duplicated scalings + t13 recompute (no pragmas) via /tmp/base_3dup.c: `fnalign --candidate /tmp/base_3dup.c --quiet` 793 instrs, 654 edits (+13 reloc) vs v1 651; `probe_variants --candidate base=/tmp/base_3dup.c` 904 vs v1 897. jal 49/49 both sides (tanf x9, grep/objdump), 5 switch arms present (0x4E/0x38/0x35/0x34/default). Side-by-side both tanf deletes (fnalign retail[640:649] + retail[729:738], 9 each): retail recomputes 0.5*B8 per use (mul $f1,$f1,$f0), GP per-use load (lwc1 -0x7EF0), mul GP*(0.5*B8), jal tanf, post-scale mul + lui 0x3E60/mtc1/nop; candidate caches t13=GP*B8*0.5 once for 4 tanfs and merges scalings into one path (retail 19 vs object 4 at 222:258; 38 vs 15 at 400:438). Same merge repeats all three scalings (first 2-elem t8, second 3-elem t12, third 3-elem aux t12) per 7k do-not-hoist-what-retail-recomputes. Remaining 1009-793=216 diffuse recompute-vs-cache of the same kind. */
/* rejected: pragma inflation into band measured +185 and refused as gate-defeating per Main (gate proves shape, not volume; real wins 10-60 words per 7s). `opt_common_subs off` 811 (+49), `commons+dead` 832 (+70), triple `commons+dead+peephole` 947 (+185); triple+3dup 982 (890 edits/probe 929) and +prop 984 (892/probe 926) via /tmp/cand_982.c + /tmp/cand_984.c -- DO NOT INSTALL. Re-assoc of 4 tanf args closed (v9_7p 758 instrs, probe 901 vs 897). Method: M2C/romwright de-noise as before with block externs func_0044b868/func_003e41e0; faithful diff held in /tmp/base_3dup.c. */
/* Build side or group camera poses, retaining both focus snapshots. */
// FUN_001C2EE0
void btlCameraFrameWithFlags(u8 *camera, s32 notify, s32 distinctPoses)
{
    extern s32 btlCameraIsOrbitAction(u8 *camera);
    extern s32 btlCameraIsTargetPrioritized(s32 cameraAddress);
    extern s32 btlCameraStateRecordFlag(u8 *camera);
    extern s32 btlCameraIsTargetEligible(u8 *camera);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 tanf(f32 angle);
    extern void btlCameraSetTransitionDuration(u8 *camera, f32 duration);
    extern f32 fGpffff80cc;
    extern f32 fGpffff80e8;
    extern f32 fGpffff8110;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    extern f32 fGpffff8130;
    extern f32 fGpffff8138;
    extern f32 fGpffff8144;
    extern f32 fGpffff8148;
    extern f32 fGpffff814c;
    extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern RwV3d *RtQuatTransformVectors(RwV3d *camera, const RwV3d *notify, s32 distinctPoses, const RtQuat *arg3);
    extern void btlCameraLookAtQuat(void *camera, const void *notify, const void *distinctPoses, const void *arg3);
    extern void func_0019de70(BtlUnitStateWork *work, u16 value);
    extern void func_001bcd40(u8 *camera, u8 *notify, f32 *distinctPoses, f32 arg3, u16 arg4);
    extern u32 btlCameraClampOffsetToLimit(f32 *camera, f32 *notify);
    extern void btlMainCurveSetPoses(u16 *camera, f32 *notify, f32 *distinctPoses, u16 arg3);
    extern void btlCameraSetDuration(u8 *camera, f32 notify);
    extern void func_004b3110(s32 camera);
    f32 top;
    RwV3d direction;
    RwV3d delta;
    RwV3d actorCenter;
    RwV3d groupCenter;
    RwV3d resourceCenter;
    RwV3d focus;
    RwV3d savedFocus;
    RwV3d secondEye;
    RwV3d firstEye;
    P4CameraVec2 horizontal;
    P4CameraFrame frames[2];
    RwMatrix matrix;
    struct { P4CameraVec2 side; P4CameraVec2 camera; } bearings;
    u8 *target;
    u8 *singleTarget;
    s32 alternateMode;
    s32 forceSide;
    s32 specialMode;
    s32 directTiming;
    u8 *actor;
    u16 mode;
    s32 chooseSide;
    f32 groupRadius;
    f32 radius;
    f32 cachedAngle;
    f32 sideDot;
    f32 extent;
    f32 tangent;
    f32 scale;
    f32 distance;

    actor = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    target = *(u8 **)(actor + 0xA0C);
    alternateMode = (btlCameraIsOrbitAction(camera) != 0);
    directTiming = 0;
    btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorCenter);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &resourceCenter);
    distance = 0.0f + actorCenter.y + 0.5f * (*(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C));
    radius = 0.0f + resourceCenter.y + 0.5f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    if ((distance < radius) && (alternateMode == 0)) {
        actorCenter.y = (distance + radius) * 0.25f;
        distance = radius;
    }
    scale = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    radius = 1.25f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
    if ((radius < scale) && (alternateMode == 0)) {
        radius = scale;
    }
    if (distance < (f32)0x113) {
        distance = (f32)0x113;
        actorCenter.y = fGpffff8144;
    }
    groupRadius = btlUnitGetGroupBounds(2, 0, (RwV3d *)((f32 *)&groupCenter), &top, NULL, 1);
    RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)(actor + 0x1C));
    groupCenter.y = 0.5f * top;
    delta.x = actorCenter.x - groupCenter.x;
    delta.y = actorCenter.y - groupCenter.y;
    delta.z = actorCenter.z - groupCenter.z;
    scale = RwV3dNormalize((RwV3d *)&delta, (const RwV3d *)&delta);
    scale = p4_cacd0_mul(fGpffff8128, scale);
    focus.x = delta.x * scale;
    focus.y = delta.y * scale;
    focus.z = delta.z * scale;
    focus.x = focus.x + groupCenter.x;
    focus.y = focus.y + groupCenter.y;
    focus.z = focus.z + groupCenter.z;
    savedFocus = focus;
    bearings.camera.x = *(f32 *)(camera + 0x9C) - focus.x;
    bearings.camera.y = *(f32 *)(camera + 0xA4) - focus.z;
    func_003e41e0((f32 *)&bearings.camera, (f32 *)&bearings.camera);
    bearings.side.x = delta.z;
    bearings.side.y = -delta.x;
    sideDot = bearings.side.x * bearings.camera.x + bearings.side.y * bearings.camera.y;
    forceSide = btlCameraIsTargetPrioritized((s32)camera);
    specialMode = btlCameraStateRecordFlag(camera);
    if ((alternateMode == 1) || ((*(u16 *)(iGpffffb3e0 + (*(u16 *)(target + 0xA4) * 10 + *(u16 *)(target + 0xA4)) * 8) & 0x20) == 0)) {
        chooseSide = (effMiscRand(0) & 1) != 0;
    } else {
        chooseSide = 0;
    }
    if ((forceSide != 0) || ((chooseSide == 1) && (btlCameraIsTargetEligible(camera) != 0) && (specialMode == 0))) {
        func_0019de70((BtlUnitStateWork *)target, 1);
        *(u8 **)(camera + 0x12C) = target;
        *(u16 *)(camera + 0x130) = 0;
        if (!(sideDot < 0.0f)) {
            direction.x = direction.x * radius;
            direction.y = direction.y * radius;
            direction.z = direction.z * radius;
        } else {
            f32 negativeRadius = -radius;
            direction.x = direction.x * negativeRadius;
            direction.y = direction.y * negativeRadius;
            direction.z = direction.z * negativeRadius;
        }
        secondEye.x = actorCenter.x + direction.x;
        secondEye.y = actorCenter.y + direction.y;
        secondEye.z = actorCenter.z + direction.z;
        distance = secondEye.y = fGpffff80cc * distance;
        direction.x = secondEye.x - focus.x;
        direction.y = distance - focus.y;
        direction.z = secondEye.z - focus.z;
        extent = RwV3dNormalize(&direction, &direction);
        cachedAngle = fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8));
        tangent = tanf(cachedAngle);
        radius = radius / tangent;
        tangent = tanf(cachedAngle);
        radius = radius > distance / tangent ? radius : distance / tangent;
        extent = extent + radius;
        distance = tanf(cachedAngle);
        extent = extent > groupRadius / distance ? extent : groupRadius / distance;
        distance = extent * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        distance *= 0.21875f;
        horizontal.x = direction.x;
        horizontal.y = direction.z;
        func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
        focus.x = 0.0f + focus.x + horizontal.y * distance;
        focus.z = (0.0f + focus.z) - horizontal.x * distance;
        {
            RwV3d displacement;
            displacement.x = p4_cacd0_mul(direction.x, extent);
            displacement.y = p4_cacd0_mul(direction.y, extent);
            displacement.z = p4_cacd0_mul(direction.z, extent);
            frames[1].pos.x = focus.x + displacement.x;
            frames[1].pos.y = focus.y + displacement.y;
            frames[1].pos.z = focus.z + displacement.z;
        }
        btlCameraLookAtQuat(&frames[1].rot.quat, &frames[1].pos, &focus, D_0060A0E0);
        btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorCenter);
        actorCenter.y = 0.0f + actorCenter.y + fGpffff8118 * (*(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C));
        distance = 2.5f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)(actor + 0x1C));
        if (!(sideDot < 0.0f)) {
            direction.x = direction.x * -distance;
            direction.y = direction.y * -distance;
            direction.z = direction.z * -distance;
        } else {
            direction.x = direction.x * distance;
            direction.y = direction.y * distance;
            direction.z = direction.z * distance;
        }
        firstEye.x = actorCenter.x + direction.x;
        firstEye.y = actorCenter.y + direction.y;
        firstEye.z = actorCenter.z + direction.z;
        btlCameraLookAtQuat(&frames[0].rot.quat, &firstEye, &savedFocus, D_0060A0E0);
        extent = 4.0f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        direction.x = firstEye.x - savedFocus.x;
        direction.y = firstEye.y - savedFocus.y;
        direction.z = firstEye.z - savedFocus.z;
        distance = RwV3dNormalize((RwV3d *)&direction, (const RwV3d *)&direction);
        radius = tanf(cachedAngle);
        distance = distance + extent / radius;
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        extent = distance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        extent *= 0.21875f;
        horizontal.x = direction.x;
        horizontal.y = direction.z;
        func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
        savedFocus.x = 0.0f + savedFocus.x + horizontal.y * extent;
        savedFocus.z = (0.0f + savedFocus.z) - horizontal.x * extent;
        direction.x = direction.x * distance;
        direction.y = direction.y * distance;
        direction.z = direction.z * distance;
        frames[0].pos.x = savedFocus.x + direction.x;
        frames[0].pos.y = savedFocus.y + direction.y;
        frames[0].pos.z = savedFocus.z + direction.z;
        distance = fGpffff8148;
    } else {
        func_0019de70((BtlUnitStateWork *)target, 0);
        *(u8 **)(camera + 0x12C) = target;
        *(u16 *)(camera + 0x130) = 1;
        secondEye = groupCenter;
        secondEye.y = fGpffff814c * top;
        if (*(u16 *)(*(u8 **)(camera + 0xE0) + 0x6A) == 1) {
            singleTarget = *(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30);
            if (!(sideDot < 0.0f)) {
                extent = *(f32 *)(singleTarget + 0x90) * *(f32 *)(singleTarget + 0x2C);
                direction.x = direction.x * extent;
                direction.y = direction.y * extent;
                direction.z = direction.z * extent;
            } else {
                extent = -(*(f32 *)(singleTarget + 0x90) * *(f32 *)(singleTarget + 0x2C));
                direction.x = direction.x * extent;
                direction.y = direction.y * extent;
                direction.z = direction.z * extent;
            }
            secondEye.x = secondEye.x + direction.x;
            secondEye.y = secondEye.y + direction.y;
            secondEye.z = secondEye.z + direction.z;
        }
        if (secondEye.y < 125.0f) {
            secondEye.y = 125.0f;
        }
        direction.x = secondEye.x - focus.x;
        direction.y = secondEye.y - focus.y;
        direction.z = secondEye.z - focus.z;
        distance = RwV3dNormalize((RwV3d *)&direction, (const RwV3d *)&direction);
        if (groupRadius < 300.0f) groupRadius = 300.0f;
        tangent = tanf(0.5f * *(f32 *)(camera + 0xB8));
        distance = distance + groupRadius / tangent;
        extent = distance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        extent *= 0.21875f;
        extent *= 0.5f;
        horizontal.x = direction.x;
        horizontal.y = direction.z;
        func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
        focus.x = 0.0f + focus.x + horizontal.y * extent;
        focus.z = (0.0f + focus.z) - horizontal.x * extent;
        {
            RwV3d displacement;
            displacement.x = p4_cacd0_mul(direction.x, distance);
            displacement.y = p4_cacd0_mul(direction.y, distance);
            displacement.z = p4_cacd0_mul(direction.z, distance);
            frames[1].pos.x = focus.x + displacement.x;
            frames[1].pos.y = focus.y + displacement.y;
            frames[1].pos.z = focus.z + displacement.z;
        }
        btlCameraLookAtQuat(&frames[1].rot.quat, &frames[1].pos, &focus, D_0060A0E0);
        if (specialMode == 0) {
            if (!(sideDot < 0.0f)) {
                RwMatrixRotate((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, -27.5f, 0);
            } else {
                RwMatrixRotate((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, 27.5f, 0);
            }
            func_003e4320((RwV3d *)&delta, (const RwV3d *)&direction, (const RwMatrix *)&matrix);
            distance = distance * fGpffff80e8;
            extent = distance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
            extent *= 0.21875f;
            extent *= 0.5f;
            horizontal.x = delta.x;
            horizontal.y = delta.z;
            func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
            focus.x = 0.0f + focus.x + horizontal.y * extent;
            focus.z = (0.0f + focus.z) - horizontal.x * extent;
            {
                RwV3d displacement;
                displacement.x = p4_cacd0_mul(delta.x, distance);
                displacement.y = p4_cacd0_mul(delta.y, distance);
                displacement.z = p4_cacd0_mul(delta.z, distance);
                frames[0].pos.x = focus.x + displacement.x;
                frames[0].pos.y = focus.y + displacement.y;
                frames[0].pos.z = focus.z + displacement.z;
            }
            frames[0].pos.y = fGpffff80cc * top;
            delta.x = actorCenter.x - groupCenter.x;
            delta.y = actorCenter.y - groupCenter.y;
            delta.z = actorCenter.z - groupCenter.z;
            extent = RwV3dNormalize((RwV3d *)&delta, (const RwV3d *)&delta);
            extent = p4_cacd0_mul(0.25f, extent);
            focus.x = delta.x * extent;
            focus.y = delta.y * extent;
            focus.z = delta.z * extent;
            focus.x = focus.x + groupCenter.x;
            focus.y = focus.y + groupCenter.y;
            focus.z = focus.z + groupCenter.z;
            btlCameraLookAtQuat(&frames[0].rot.quat, &frames[0].pos, &focus, D_0060A0E0);
            distance = 3.75f;
        } else {
            mode = *(u16 *)(*(u8 **)(camera + 0xE0) + 0x6E);
            switch (mode) {
            case 52:
                focus.y = 500.0f;
                frames[0].pos.y = 200.0f;
                distance = 1.25f;
                directTiming = 1;
                notify = 0;
                *(s32 *)(camera + 0xDC) = 0xC;
                break;
            case 53:
                focus.y = 600.0f;
                frames[0].pos.y = 200.0f;
                distance = fGpffff8130;
                directTiming = 0;
                notify = 0;
                *(s32 *)(camera + 0xDC) = 8;
                break;
            case 56:
                focus.y = 800.0f;
                frames[0].pos.y = 500.0f;
                distance = 2.0f;
                directTiming = 1;
                notify = 0;
                *(s32 *)(camera + 0xDC) = 0xC;
                break;
            case 78:
                focus.y = 1000.0f;
                frames[0].pos.y = 500.0f;
                distance = 1.5f;
                directTiming = 0;
                notify = 0;
                *(s32 *)(camera + 0xDC) = 4;
                break;
            default:
                focus.y = 500.0f;
                frames[0].pos.y = 200.0f;
                distance = fGpffff8138;
                directTiming = 1;
                notify = 0;
                *(s32 *)(camera + 0xDC) = 0;
                break;
            }
            frames[0].pos.x = frames[1].pos.x;
            frames[0].pos.z = frames[1].pos.z;
            btlCameraLookAtQuat(&frames[0].rot.quat, &frames[0].pos, &focus, D_0060A0E0);
        }
    }
    if ((distinctPoses == 0) && (specialMode == 0)) {
        frames[0].rot.quat = frames[1].rot.quat;
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)&frames[0].rot.quat);
        direction.x = direction.x * 100.0f;
        direction.y = direction.y * 100.0f;
        direction.z = direction.z * 100.0f;
        frames[0].pos.x = frames[1].pos.x + direction.x;
        frames[0].pos.y = frames[1].pos.y + direction.y;
        frames[0].pos.z = frames[1].pos.z + direction.z;
    }
    if (*(s32 *)(camera + 0xDC) > 0) {
        func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 1);
    }
    btlCameraClampOffsetToLimit((f32 *)&frames[0], (f32 *)&frames[0]);
    btlCameraClampOffsetToLimit((f32 *)&frames[1], (f32 *)&frames[1]);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    if (directTiming == 0) {
        btlCameraSetDuration(camera, distance);
    } else {
        btlCameraSetTransitionDuration(camera, distance);
    }
    if (notify != 0) {
        func_004b3110(8);
    }
}

// FUN_001C3EB0
void btlCameraWaitForAnimFrame(u8 *arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if ((temp_4 != NULL) && ((*(u16 *)(temp_4 + 0x1A) & 1) != 0)) {
        if (*(s32 *)(arg0 + 0xDC) == 0) {
            if (arg1 == 0) {
                func_001bcd40(temp_4, NULL, NULL, 0.0f, 3);
            } else {
                func_001bcd40(temp_4, NULL, NULL, 0.0f, 0x11);
            }
        }
        if (btlCameraUnitAnimFinished(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
        }
    }
}

/* Frame target and actor geometry with separate side and approach poses. */
// FUN_001C3F70
void btlCameraFrameSplit(u8 *camera, s32 notify, s32 distinctPoses)
{
    extern s32 btlCameraIsTargetPrioritized(s32 cameraAddress);
    extern s32 btlCameraIsTargetEligible(u8 *camera);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern void btlCameraLookAtQuat(void *camera, const void *notify, const void *distinctPoses, const void *arg3);
    extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *out);
    extern f32 tanf(f32 angle);
    extern void func_0019de70(BtlUnitStateWork *action, u16 value);
    extern void func_001bcd40(u8 *camera, u8 *notify, f32 *distinctPoses, f32 arg3, u16 arg4);
    extern void btlMainCurveSetPoses(u16 *camera, f32 *notify, f32 *distinctPoses, u16 arg3);
    extern void btlCameraSetDuration(u8 *camera, f32 notify);
    extern void func_004b3110(s32 camera);
    extern f32 fGpffff8030;
    extern f32 fGpffff803c;
    extern f32 fGpffff80f0;
    extern f32 fGpffff8110;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    extern f32 fGpffff8138;
    extern f32 fGpffff8150;
    extern f32 fGpffff8154;
    RwV3d actorCenter;
    RwV3d targetCenter;
    RwV3d resourceCenter;
    RwV3d snapshotCenter;
    RwV3d focus;
    RwV3d direction;
    RwV3d eye;
    RwV3d savedDirection;
    P4CameraVec2 projectedCenter;
    P4CameraVec2 projection;
    P4CameraVec2 horizontal;
    struct { P4CameraVec2 side; P4CameraVec2 camera;
             P4CameraVec2 focus; P4CameraVec2 eye; } plane;
    P4CameraFrame frames[2];
    u8 *action;
    u8 *targetUnit;
    u8 *resourceUnit;
    u8 *selectedUnit;
    s32 sideView;
    f32 initialDistance;
    f32 sideDot;
    f32 duration;
    f32 actorRadius;
    f32 targetTop;
    f32 resourceTop;
    f32 actorTop;
    f32 directionDistance;
    f32 lineDistance;
    f32 resourceRadius;

    action = *(u8 **)(camera + 0xE0);
    selectedUnit = *(u8 **)(action + 0x30);
    targetUnit = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    resourceUnit = *(u8 **)(selectedUnit + 0xA0C);
    btlUnitGetSphereWorldCenter((BtlUnit *)selectedUnit, &actorCenter);
    btlUnitGetSphereWorldCenter((BtlUnit *)targetUnit, &targetCenter);
    btlUnitGetSphereWorldCenter((BtlUnit *)resourceUnit, &resourceCenter);
    actorTop = 0.0f + actorCenter.y + 0.5f * (*(f32 *)(selectedUnit + 0x8C) * *(f32 *)(selectedUnit + 0x2C));
    targetTop = 0.0f + targetCenter.y + 0.5f * (*(f32 *)(targetUnit + 0x8C) * *(f32 *)(targetUnit + 0x2C));
    resourceTop = 0.0f + resourceCenter.y + 0.5f * (*(f32 *)(resourceUnit + 0x8C) * *(f32 *)(resourceUnit + 0x2C));
    actorRadius = *(f32 *)(selectedUnit + 0x90) * *(f32 *)(selectedUnit + 0x2C);
    resourceRadius = *(f32 *)(resourceUnit + 0x90) * *(f32 *)(resourceUnit + 0x2C);
    *(RwV3d *)(camera + 0x104) = targetCenter;
    *(u8 **)(camera + 0x100) = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x38);
    if (resourceTop < 135.0f) {
        resourceTop = 135.0f;
        resourceCenter.y = 67.5f;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        sideView = 1;
    } else {
        sideView = btlCameraIsTargetPrioritized((s32)camera);
        if (!((resourceTop - targetTop) < 125.0f)) {
            sideView = 0;
        } else {
            sideView = (sideView != 0);
            if (sideView == 0) {
                sideView = (effMiscRand(0) & 1) != 0;
                if (sideView != 0) {
                    sideView = (btlCameraIsTargetEligible(camera) != 0);
                }
            }
        }
    }
    if (sideView != 0) {
        direction.x = resourceCenter.x - targetCenter.x;
        direction.y = resourceCenter.y - targetCenter.y;
        direction.z = resourceCenter.z - targetCenter.z;
        directionDistance = RwV3dNormalize((RwV3d *)&direction, (const RwV3d *)&direction);
        initialDistance = directionDistance;
        {
            f32 focusScale = fGpffff8128 * directionDistance;
            focus.x = direction.x * focusScale;
            focus.y = direction.y * focusScale;
            focus.z = direction.z * focusScale;
        }
    } else {
        f32 t3;
        f32 t2;
        f32 t1;
        t3 = resourceCenter.x + actorCenter.x;
        snapshotCenter.x = t3;
        t2 = resourceCenter.y + actorCenter.y;
        snapshotCenter.y = t2;
        t1 = resourceCenter.z + actorCenter.z;
        snapshotCenter.z = t1;
        t3 = t3 * 0.5f;
        snapshotCenter.x = t3;
        t2 = t2 * 0.5f;
        snapshotCenter.y = t2;
        t1 = t1 * 0.5f;
        snapshotCenter.z = t1;
        direction.x = t3 - targetCenter.x;
        direction.y = t2 - targetCenter.y;
        direction.z = t1 - targetCenter.z;
        directionDistance = RwV3dNormalize((RwV3d *)&direction, (const RwV3d *)&direction);
        initialDistance = directionDistance;
        {
            f32 focusScale = fGpffff8128 * directionDistance;
            focus.x = direction.x * focusScale;
            focus.y = direction.y * focusScale;
            focus.z = direction.z * focusScale;
        }
    }
    focus.x = focus.x + targetCenter.x;
    focus.y = focus.y + targetCenter.y;
    focus.z = focus.z + targetCenter.z;
    plane.camera.x = *(f32 *)(camera + 0x9C) - focus.x;
    plane.camera.y = *(f32 *)(camera + 0xA4) - focus.z;
    func_003e41e0((f32 *)&plane.camera, (f32 *)&plane.camera);
    if (sideView != 0) {
        f32 cameraDistance;
        f32 side;
        f32 tprod;
        func_0019de70((BtlUnitStateWork *)resourceUnit, 1);
        *(u8 **)(camera + 0x12C) = resourceUnit;
        *(u16 *)(camera + 0x130) = 0;
        selectedUnit = targetUnit;
        snapshotCenter = resourceCenter;
        side = 1.5f * resourceRadius;
        plane.side.x = direction.z;
        plane.side.y = -direction.x;
        sideDot = plane.side.x * plane.camera.x + plane.side.y * plane.camera.y;
        if (!(sideDot < 0.0f)) {
            eye.x = 0.0f + snapshotCenter.x + direction.z * side;
            eye.z = (0.0f + snapshotCenter.z) - direction.x * side;
        } else {
            eye.x = (0.0f + snapshotCenter.x) - direction.z * side;
            eye.z = 0.0f + snapshotCenter.z + direction.x * side;
            {
                f32 rs = 0.5f * initialDistance;
                focus.x = direction.x * rs;
                focus.y = direction.y * rs;
                focus.z = direction.z * rs;
                focus.x = focus.x + targetCenter.x;
                focus.y = focus.y + targetCenter.y;
                focus.z = focus.z + targetCenter.z;
            }
        }
        if (!(resourceTop < targetTop)) {
            focus.y = 0.0f + focus.y + fGpffff8118 * (*(f32 *)(targetUnit + 0x8C) * *(f32 *)(targetUnit + 0x2C));
            if (!(resourceTop <= focus.y)) {
                eye.y = 0.0f + focus.y + fGpffff8030 * (*(f32 *)(resourceUnit + 0x8C) * *(f32 *)(resourceUnit + 0x2C));
            } else {
                eye.y = snapshotCenter.y;
            }
        } else {
            if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) && !(targetTop < 500.0f)) {
                focus.y = 0.0f + focus.y + fGpffff8030 * (*(f32 *)(targetUnit + 0x8C) * *(f32 *)(targetUnit + 0x2C));
                eye.y = 0.0f + snapshotCenter.y + 0.25f * resourceTop;
            } else {
                focus.y = (0.0f + focus.y) - fGpffff80f0 * (*(f32 *)(targetUnit + 0x8C) * *(f32 *)(targetUnit + 0x2C));
                eye.y = 0.0f + snapshotCenter.y + 0.25f * resourceTop;
            }
        }
        btlCameraLookAtQuat(&frames[1].rot.quat, &eye, &focus, D_0060A0E0);
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = btlTargetAngleBetween((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        cameraDistance = 0.0f + lineDistance + resourceRadius * fGpffff8138;
        if (cameraDistance < (f32)0x113) {
            cameraDistance = (f32)0x113;
        }
        eye.x = projection.x;
        if (!(resourceTop < targetTop)) {
            if (!(resourceTop <= focus.y)) {
                eye.y = 0.0f + focus.y + fGpffff803c * (*(f32 *)(resourceUnit + 0x8C) * *(f32 *)(resourceUnit + 0x2C));
            } else {
                eye.y = 0.0f + snapshotCenter.y + 0.25f * (*(f32 *)(resourceUnit + 0x8C) * *(f32 *)(resourceUnit + 0x2C));
            }
        } else {
            eye.y = 0.0f + snapshotCenter.y + 0.25f * resourceTop;
        }
        eye.z = projection.y;
        cameraDistance = cameraDistance / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        direction.x = direction.x * cameraDistance;
        direction.y = direction.y * cameraDistance;
        direction.z = direction.z * cameraDistance;
        if (sideDot < 0.0f) {
            cameraDistance = cameraDistance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
            cameraDistance *= 0.21875f;
            cameraDistance *= 1.25f;
            horizontal.x = direction.x;
            horizontal.y = direction.z;
            func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
            eye.x = 0.0f + eye.x + horizontal.y * cameraDistance;
            eye.z = (0.0f + eye.z) - horizontal.x * cameraDistance;
        }
        frames[1].pos.x = eye.x + direction.x;
        frames[1].pos.y = eye.y + direction.y;
        frames[1].pos.z = eye.z + direction.z;
        if (frames[1].pos.y < 25.0f) {
            frames[1].pos.y = 25.0f;
        }
        direction.x = actorCenter.x - targetCenter.x;
        direction.y = actorCenter.y - targetCenter.y;
        direction.z = actorCenter.z - targetCenter.z;
        directionDistance = RwV3dNormalize((RwV3d *)&direction, (const RwV3d *)&direction);
        {
            f32 focusScale = fGpffff8128 * directionDistance;
            focus.x = direction.x * focusScale;
            focus.y = direction.y * focusScale;
            focus.z = direction.z * focusScale;
            focus.x = focus.x + targetCenter.x;
            focus.y = focus.y + targetCenter.y;
            focus.z = focus.z + targetCenter.z;
        }
        snapshotCenter = actorCenter;
        side = 2.0f * actorRadius;
        eye.y = 0.0f + snapshotCenter.y + 0.5f * actorTop;
        if (!(sideDot < 0.0f)) {
            eye.x = 0.0f + snapshotCenter.x + direction.z * side;
            eye.z = (0.0f + snapshotCenter.z) - direction.x * side;
        } else {
            eye.x = (0.0f + snapshotCenter.x) - direction.z * side;
            eye.z = 0.0f + snapshotCenter.z + direction.x * side;
            {
                f32 halfDistance = 0.5f * directionDistance;
                focus.x = direction.x * halfDistance;
                focus.y = direction.y * halfDistance;
                focus.z = direction.z * halfDistance;
                focus.x = focus.x + targetCenter.x;
                focus.y = focus.y + targetCenter.y;
                focus.z = focus.z + targetCenter.z;
            }
        }
        focus.y = 0.0f + focus.y + fGpffff8030 * (*(f32 *)(targetUnit + 0x8C) * *(f32 *)(targetUnit + 0x2C));
        btlCameraLookAtQuat(&frames[0].rot.quat, &eye, &focus, D_0060A0E0);
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = btlTargetAngleBetween((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        cameraDistance = func_001c_mul_add(actorRadius, 3.0f, 0.0f + lineDistance);
        eye.x = projection.x;
        eye.y = 0.0f + snapshotCenter.y + 0.25f * actorTop;
        eye.z = projection.y;
        cameraDistance = cameraDistance / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        direction.x = direction.x * cameraDistance;
        direction.y = direction.y * cameraDistance;
        direction.z = direction.z * cameraDistance;
        if (sideDot < 0.0f) {
            cameraDistance = cameraDistance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
            cameraDistance *= 0.21875f;
            cameraDistance *= 1.25f;
            horizontal.x = direction.x;
            horizontal.y = direction.z;
            func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
            eye.x = 0.0f + eye.x + horizontal.y * cameraDistance;
            eye.z = (0.0f + eye.z) - horizontal.x * cameraDistance;
        }
        frames[0].pos.x = eye.x + direction.x;
        frames[0].pos.y = eye.y + direction.y;
        frames[0].pos.z = eye.z + direction.z;
        if (frames[0].pos.y < 25.0f) {
            frames[0].pos.y = 25.0f;
        }
        duration = 2.5f;
    } else {
        f32 sideDot;
        f32 cameraDistance;
        f32 side;
        f32 minimumSide;
        func_0019de70((BtlUnitStateWork *)resourceUnit, 0);
        *(u8 **)(camera + 0x12C) = resourceUnit;
        *(u16 *)(camera + 0x130) = 1;
        snapshotCenter = targetCenter;
        side = fGpffff8150 * (*(f32 *)(targetUnit + 0x90) * *(f32 *)(targetUnit + 0x2C));
        minimumSide = 0.75f * resourceRadius;
        if (!(minimumSide <= side)) side = minimumSide;
        if (snapshotCenter.y < 125.0f) {
            snapshotCenter.y = 125.0f;
        }
        plane.side.x = direction.z;
        plane.side.y = -direction.x;
        sideDot = plane.side.x * plane.camera.x + plane.side.y * plane.camera.y;
        eye.y = snapshotCenter.y;
        if (!(sideDot < 0.0f)) {
            eye.x = 0.0f + snapshotCenter.x + direction.z * side;
            eye.z = (0.0f + snapshotCenter.z) - direction.x * side;
            savedDirection = direction;
        } else {
            eye.x = (0.0f + snapshotCenter.x) - direction.z * side;
            eye.z = 0.0f + snapshotCenter.z + direction.x * side;
        }
        if (!(resourceTop < targetTop)) {
            focus.y = 0.0f + focus.y + fGpffff8030 * (*(f32 *)(resourceUnit + 0x8C) * *(f32 *)(resourceUnit + 0x2C));
        } else {
            focus.y = 0.0f + focus.y + fGpffff8154 * (*(f32 *)(resourceUnit + 0x8C) * *(f32 *)(resourceUnit + 0x2C));
        }
        btlCameraLookAtQuat(&frames[0].rot.quat, &eye, &focus, D_0060A0E0);
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = btlTargetAngleBetween((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        cameraDistance = 0.0f + lineDistance + 1.5f * (*(f32 *)(targetUnit + 0x90) * *(f32 *)(targetUnit + 0x2C));
        eye.x = projection.x;
        eye.y = snapshotCenter.y;
        eye.z = projection.y;
        cameraDistance = cameraDistance / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        if (cameraDistance < (f32)0x226) cameraDistance = (f32)0x226;
        direction.x = direction.x * cameraDistance;
        direction.y = direction.y * cameraDistance;
        direction.z = direction.z * cameraDistance;
        if (!(sideDot < 0.0f)) {
            cameraDistance = cameraDistance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
            cameraDistance *= 0.21875f;
            cameraDistance *= 2.0f;
            horizontal.x = savedDirection.x;
            horizontal.y = savedDirection.z;
            func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
            eye.x = (0.0f + eye.x) - horizontal.y * cameraDistance;
            eye.z = 0.0f + eye.z + horizontal.x * cameraDistance;
        }
        frames[0].pos.x = eye.x + direction.x;
        frames[0].pos.y = eye.y + direction.y;
        frames[0].pos.z = eye.z + direction.z;
        frames[1].rot.quat = frames[0].rot.quat;
        frames[1].pos = frames[0].pos;
        direction.x = actorCenter.x - frames[1].pos.x;
        direction.y = actorCenter.y - frames[1].pos.y;
        direction.z = actorCenter.z - frames[1].pos.z;
        cameraDistance = RwV3dNormalize((RwV3d *)&direction, (const RwV3d *)&direction);
        btlUnitGetSphereWorldCenter((BtlUnit *)selectedUnit, &snapshotCenter);
        snapshotCenter.y = 0.0f + snapshotCenter.y + fGpffff8030 * (*(f32 *)(selectedUnit + 0x8C) * *(f32 *)(selectedUnit + 0x2C));
        btlCameraLookAtQuat(&frames[0].rot.quat, &frames[1].pos, (f32 *)&snapshotCenter, D_0060A0E0);
        {
            f32 focusScale = fGpffff8128 * cameraDistance;
            direction.x = direction.x * focusScale;
            direction.y = direction.y * focusScale;
            direction.z = direction.z * focusScale;
            frames[0].pos.x = frames[1].pos.x + direction.x;
            frames[0].pos.y = frames[1].pos.y + direction.y;
            frames[0].pos.z = frames[1].pos.z + direction.z;
        }
        if (frames[0].pos.y < 25.0f) {
            frames[0].pos.y = 25.0f;
        }
        if (frames[1].pos.y < 25.0f) {
            frames[1].pos.y = 25.0f;
        }
        duration = 2.25f;
    }
    if (distinctPoses == 0) {
        frames[0].pos = frames[1].pos;
        frames[0].rot.quat = frames[1].rot.quat;
    }
    func_001bcd40(*(u8 **)(camera + 0xE0), selectedUnit + 4, (f32 *)&frames[0].pos, 50.0f, 3);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, duration);
    if (notify != 0) {
        func_004b3110(8);
    }
}

// FUN_001C5110
void btlCameraUpdateMode(u8 *arg0)
{
    u8 *temp;
    s32 arg1;
    s32 arg2;
    s32 mode;

    temp = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp = *(u8 **)(temp + 0xA0C);
    arg1 = 1;
    arg2 = 1;
    *(u16 *)(arg0 + 0x110) = (u16)btlCameraSelectMode(arg0);
    if (*(u16 *)(arg0 + 0xE4) == 0x1D) {
        arg1 = 0;
        arg2 = 0;
    }
    if ((temp != NULL) &&
        (btlUnitSkillBlocked(*(u8 **)(arg0 + 0xE0), temp) != 0)) {
        *(s32 *)(arg0 + 0x114) = 1;
    } else {
        *(s32 *)(arg0 + 0x114) = 0;
    }
    mode = *(u16 *)(arg0 + 0x110);
    switch (mode) {
    case 1:
        btlCameraFrameRandomEntry(arg0, arg1, arg2);
        return;
    case 2:
        btlCameraFrameDistinctPair(arg0, arg1, arg2);
        return;
    case 3:
        btlCameraFrameWithFlags(arg0, arg1, arg2);
        return;
    case 4:
        if ((*(s32 *)(arg0 + 0x114) == 0) &&
            ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0)) {
            btlCameraFrameSplit(arg0, arg1, arg2);
            return;
        }
        btlCameraFrameDistinctPair(arg0, arg1, arg2);
        return;
    case 5:
        btlCameraFrameWithFlags(arg0, arg1, arg2);
        return;
    case 6:
        btlCameraFrameRandomOrbit(arg0, 1);
    default:
        return;
    }
}

// FUN_001C52C0
void btlCameraUpdateWaitMode(u8 *arg0)
{
    switch (*(u16 *)(arg0 + 0x110)) {
    case 0:
    case 1:
        break;
    case 2:
        if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
            ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0) &&
            (btlCameraUnitAnimFinished(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                          *(u16 *)(arg0 + 0x130));
            return;
        }
        break;
    case 3:
        if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
            ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0)) {
            if (*(s32 *)(arg0 + 0xDC) == 0) {
                func_001bcd40(*(u8 **)(arg0 + 0xE0),
                              NULL, NULL, 0.0f, 3);
            }
            if (btlCameraUnitAnimFinished(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
                func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                              *(u16 *)(arg0 + 0x130));
                return;
            }
        }
        break;
    case 4:
        if (*(s32 *)(arg0 + 0x114) == 0) {
            if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
                (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6A) == 1) &&
                (*(s32 *)(arg0 + 0x100) ==
                 *(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x38)) &&
                ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0)) {
                if (btlCameraUnitAnimFinished(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
                    func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                                  *(u16 *)(arg0 + 0x130));
                }
                func_001bcd40(*(u8 **)(arg0 + 0xE0),
                              arg0 + 0x9C, (f32 *)(arg0 + 0x104), 10.0f, 0xC3);
                return;
            }
        } else {
            if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
                ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0) &&
                (btlCameraUnitAnimFinished(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
                func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                              *(u16 *)(arg0 + 0x130));
            }
        }
        break;
    case 5:
        btlCameraWaitForAnimFrame(arg0, 0);
        break;
    case 6:
        if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
            ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0) &&
            (btlCameraUnitAnimFinished(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                          *(u16 *)(arg0 + 0x130));
        }
        break;
    default:
        return;
    }
}

// FUN_001C5500
void btlCameraFrameTargetPose(u8 *arg0, s32 arg1)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d basePosition;
    RwV3d focus;
    RwV3d direction;
    RwV3d eye;
    RwV3d savedDirection;
    f32 baseXZ[2];
    f32 projectionXZ[2];
    struct {
        f32 perpendicular[2];
        f32 horizontal[2];
        f32 focusXZ[2];
        f32 eyeXZ[2];
    } geometry;
    struct {
        P4CameraFrame first;
        P4CameraFrame second;
    } poses;
    u8 *action;
    u8 *actor;
    u8 *target;
    u8 *primaryUnit;
    u8 *secondaryUnit;
    f32 length;
    f32 scale;
    f32 crossProduct;
    f32 dotProduct;
    f32 radius;
    f32 radiusScale;
    f32 heightFactor;
    f32 offsetFactor;
    f32 baseZ;
    f32 unitY;
    f32 projDist;
    f32 accumDist;
    f32 tanFov;
    f32 distScale;
    f32 duration;
    u16 command;
    extern f32 fGpffff8128;
    extern f32 fGpffff8118;
    extern f32 fGpffff8158;
    extern f32 fGpffff814c;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern void btlCameraCopyPose(f32 *out, f32 *in);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 btlTargetAngleBetween(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0* first, P4Vec4Holder_001EC2B0* second);
    extern void btlCameraCopyPoseTarget(f32 *arg0, f32 *arg1);
    extern f32 tanf(f32 arg0);

    (void)arg1;
    action = *(u8 **)(arg0 + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorPosition);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetPosition);

    direction.x = actorPosition.x - targetPosition.x;
    direction.y = actorPosition.y - targetPosition.y;
    direction.z = actorPosition.z - targetPosition.z;
    length = RwV3dNormalize(&direction, &direction);

    geometry.horizontal[0] = *(f32 *)(arg0 + 0x9C) - actorPosition.x;
    geometry.horizontal[1] = *(f32 *)(arg0 + 0xA4) - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);

    scale = fGpffff8128 * length;
    focus.x = direction.x * scale;
    focus.y = direction.y * scale;
    focus.z = direction.z * scale;
    focus.x += targetPosition.x;
    focus.y += targetPosition.y;
    focus.z += targetPosition.z;

    geometry.perpendicular[0] = direction.x;
    geometry.perpendicular[1] = direction.z;
    dotProduct = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];

    if (!(dotProduct < 0.0f)) {
        primaryUnit = actor;
        secondaryUnit = target;
        basePosition = actorPosition;
        radius = 1.5f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        radiusScale = 1.5f;
        heightFactor = fGpffff8118;
        offsetFactor = 0.0f;
        if (basePosition.y < 125.0f) {
            basePosition.y = 125.0f;
        }
    } else {
        primaryUnit = target;
        secondaryUnit = actor;
        basePosition = targetPosition;
        if (*(u8 *)(target + 0xA2) == 0) {
            radius = 1.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            radiusScale = 3.5f;
        } else {
            radius = 1.25f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            radiusScale = 1.75f;
        }
        heightFactor = 0.25f;
        offsetFactor = heightFactor;
    }

    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    crossProduct = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];
    unitY = basePosition.y;
    eye.y = unitY + offsetFactor * (*(f32 *)(primaryUnit + 0x8C) * *(f32 *)(primaryUnit + 0x2C));

    if (!(crossProduct < 0.0f)) {
        eye.x = basePosition.x + direction.z * radius;
        baseZ = basePosition.z;
        eye.z = baseZ - direction.x * radius;
    } else {
        eye.x = basePosition.x - direction.z * radius;
        baseZ = basePosition.z;
        eye.z = baseZ + direction.x * radius;
    }

    savedDirection = direction;
    btlCameraLookAtQuat(&poses.second.rot, &eye, &focus, D_0060A0E0);
    RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&poses.second.rot);

    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    projDist = btlTargetAngleBetween((u8 *)geometry.focusXZ,
                             (u8 *)geometry.eyeXZ,
                             (u8 *)baseXZ,
                             (u8 *)projectionXZ);
    accumDist = projDist + radiusScale * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
    eye.x = projectionXZ[0];
    eye.y = unitY;
    eye.z = projectionXZ[1];

    tanFov = tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    distScale = accumDist / tanFov;
    if (distScale < 500.0f) {
        distScale = 500.0f;
    }
    direction.x *= distScale;
    direction.y *= distScale;
    direction.z *= distScale;

    if (!(dotProduct < 0.0f)) {
        if (crossProduct < 0.0f) {
            eye.x += savedDirection.z * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
            eye.z -= savedDirection.x * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
        }
    } else {
        if (!(crossProduct < 0.0f)) {
            eye.x -= savedDirection.z * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
            eye.z += savedDirection.x * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
        }
    }

    eye.y = unitY + heightFactor * (*(f32 *)(primaryUnit + 0x8C) * *(f32 *)(primaryUnit + 0x2C));
    poses.second.pos.x = eye.x + direction.x;
    poses.second.pos.y = eye.y + direction.y;
    poses.second.pos.z = eye.z + direction.z;

    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(arg0 + 0x9C));
    if (!(btlTargetQuatAngle((P4Vec4Holder_001EC2B0*)(&poses.first.rot), (P4Vec4Holder_001EC2B0*)(&poses.second.rot)) <= fGpffff8158)) {
        btlCameraCopyPoseTarget((f32 *)&poses.first, (f32 *)&poses.second);
        RtQuatTransformVectors((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&poses.first.rot);
        direction.x *= 150.0f;
        direction.y *= 150.0f;
        direction.z *= 150.0f;
        poses.second.pos.x += direction.x;
        poses.second.pos.y += direction.y;
        poses.second.pos.z += direction.z;
        command = 3;
        if (*(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x88) == 0) {
            func_004b3110(8);
        }
        duration = 1.5f;
    } else {
        command = 0xC3;
        duration = fGpffff814c;
    }

    if (poses.first.pos.y < 25.0f) {
        poses.first.pos.y = 25.0f;
    }
    if (poses.second.pos.y < 25.0f) {
        poses.second.pos.y = 25.0f;
    }

    func_001bcd40(*(u8 **)(arg0 + 0xE0), secondaryUnit + 4, (f32 *)&poses.second, 50.0f, command);
    btlMainCurveSetPoses((u16 *)arg0, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    btlCameraSetDuration(arg0, duration);
}

/* Frame the whole group, then place two poses around the farthest unit.  Load-bearing shapes,
   measured against b210: the unit table is indexed as `((u8 **)work + 14)[i]` (an array subscript keeps
   the u16 counter's mask separate per use and puts the base register first in the address add);
   `farthest = actorPos` is written twice in the last-unit branch, which is how retail's struct copy
   comes out (one compiler temporary, then two stores; a single assignment is one direct ld/sd pair).
   Locals are declared in stack order (highest address first): b210 lays them out in declaration order
   and puts small objects ahead of the matrix and pose block, so `top` fills the pad after `groupCenter`. */
// FUN_001C5B80
void btlCameraFrameFlagged(u8 *arg0, s32 arg1)
{
    extern s32 btlCameraStateRecordFlag(u8 *arg0);
    extern void btlCameraCopyPose(f32 *out, f32 *in);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 tanf(f32 arg0);
    extern f32 fGpffff8110;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    f32 top;
    RwV3d groupCenter;
    RwV3d optionCenter;
    RwV3d delta;
    RwV3d direction;
    RwV3d focus;
    RwV3d actorPos;
    RwV3d farthest;
    P4CameraVec2 horizontal;
    RwMatrix matrix;
    P4CameraFrame frames[2];
    f32 cameraDistance;
    f32 edgeX;
    f32 groupRadius;
    f32 maxLen;
    f32 focusHeight;
    f32 edgeZ;
    f32 lateralOffset;
    f32 angle;
    f32 duration;
    f32 len;
    f32 scale;
    f32 candidate;
    f32 reach;
    s32 fixedShot;
    s32 group;
    u16 i;
    u8 *work;
    u8 *entry;
    u8 *unit;

    (void)arg1;
    fixedShot = btlCameraStateRecordFlag(arg0);
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)(arg0 + 0x9C));
    work = *(u8 **)(arg0 + 0xE0);
    if (*(u16 *)(work + 0x6A) > 1) {
        group = btlTargetGetUnitIndex(work + 0x38);
    } else {
        group = 3;
    }
    group = group & 0xFFFF;
    groupRadius = btlUnitGetGroupBounds(group, 1, &groupCenter, &top, NULL, 0);
    groupCenter.y = 0.75f * top;
    cameraDistance = groupRadius / tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    if (cameraDistance < 1000.0f) {
        cameraDistance = 1000.0f;
    }
    btlUnitGetGroupBounds(group, 1, &optionCenter, NULL, NULL, 1);
    maxLen = 0.0f;
    for (i = 0; i < *(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6A); i++) {
        work = *(u8 **)(arg0 + 0xE0);
        entry = (((u8 **)work) + 14)[i];
        if ((*(u16 *)(entry + 0x1A) & 1) != 0) {
            btlUnitGetGridSphereCenter((BtlUnit *)(*(u8 **)(entry + 0x30)), &actorPos);
            delta.x = optionCenter.x - actorPos.x;
            delta.y = optionCenter.y - actorPos.y;
            delta.z = optionCenter.z - actorPos.z;
            len = RwV3dLength((f32 *)&delta);
            if (!(len <= maxLen)) {
                farthest = actorPos;
                maxLen = len;
            }
        }
    }
    work = *(u8 **)(arg0 + 0xE0);
    unit = *(u8 **)(work + 0x30);
    btlUnitGetGridSphereCenter((BtlUnit *)unit, &actorPos);
    delta.x = optionCenter.x - actorPos.x;
    delta.y = optionCenter.y - actorPos.y;
    delta.z = optionCenter.z - actorPos.z;
    len = RwV3dLength((f32 *)&delta);
    if (!(len <= maxLen)) {
        farthest = actorPos;
        farthest = actorPos;
        direction.x = actorPos.x - groupCenter.x;
        direction.y = actorPos.y - groupCenter.y;
        direction.z = actorPos.z - groupCenter.z;
        maxLen = RwV3dNormalize(&direction, &direction);
        scale = fGpffff8128 * maxLen;
        actorPos.x = direction.x * scale;
        actorPos.y = direction.y * scale;
        actorPos.z = direction.z * scale;
        groupCenter.x = groupCenter.x + actorPos.x;
        groupCenter.y = groupCenter.y + actorPos.y;
        groupCenter.z = groupCenter.z + actorPos.z;
        unit = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
        candidate = maxLen + (1.25f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C))) / tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
        if (!(candidate <= cameraDistance)) {
            cameraDistance = candidate;
        }
    } else if (maxLen != 0.0f) {
        if (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6A) > 1) {
            direction.x = actorPos.x - groupCenter.x;
            direction.y = actorPos.y - groupCenter.y;
            direction.z = actorPos.z - groupCenter.z;
            len = RwV3dNormalize(&direction, &direction);
            reach = len + (50.0f + *(f32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0x90) * *(f32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0x2C));
            candidate = reach / tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
            if (!(candidate <= cameraDistance)) {
                cameraDistance = candidate;
            }
            direction.x = actorPos.x - farthest.x;
            direction.y = actorPos.y - farthest.y;
            direction.z = actorPos.z - farthest.z;
            scale = 0.5f * RwV3dNormalize(&direction, &direction);
            actorPos.x = direction.x * scale;
            actorPos.y = direction.y * scale;
            actorPos.z = direction.z * scale;
            farthest.x = farthest.x + actorPos.x;
            farthest.y = farthest.y + actorPos.y;
            farthest.z = farthest.z + actorPos.z;
        }
    } else if (maxLen == 0.0f) {
        btlUnitGetGridSphereCenter((BtlUnit *)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30)), &farthest);
    }
    farthest.y = groupCenter.y;
    delta.x = farthest.x - groupCenter.x;
    delta.y = farthest.y - groupCenter.y;
    delta.z = farthest.z - groupCenter.z;
    RwV3dNormalize(&delta, &delta);
    delta.x = delta.x * groupRadius;
    delta.y = delta.y * groupRadius;
    delta.z = delta.z * groupRadius;
    edgeX = groupCenter.x + delta.x;
    edgeZ = groupCenter.z + delta.z;
    focusHeight = 1.25f * top;
    direction.x = edgeX - groupCenter.x;
    direction.z = edgeZ - groupCenter.z;
    direction.y = 0.0f;
    scale = fGpffff8118 * RwV3dNormalize(&direction, &direction);
    direction.x = direction.x * scale;
    direction.y = direction.y * scale;
    direction.z = direction.z * scale;
    focus.x = groupCenter.x + direction.x;
    focus.y = groupCenter.y + direction.y;
    focus.z = groupCenter.z + direction.z;
    focus.y = groupCenter.y;
    if (focusHeight < 250.0f) {
        focusHeight = 250.0f;
    }
    delta.x = edgeX - focus.x;
    delta.y = focusHeight - focus.y;
    delta.z = edgeZ - focus.z;
    RwV3dNormalize(&delta, &delta);
    lateralOffset = cameraDistance * tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    lateralOffset *= 0.21875f;
    horizontal.x = delta.x;
    horizontal.y = delta.z;
    func_003e41e0((f32 *)&horizontal, (f32 *)&horizontal);
    focus.x = (0.0f + focus.x) + horizontal.y * lateralOffset;
    focus.z = (0.0f + focus.z) - horizontal.x * lateralOffset;
    if (effMiscRand(0) & 1) {
        angle = 7.5f;
    } else {
        angle = -7.5f;
    }
    RwMatrixRotate(&matrix, (const RwV3d *)D_0060A0E0, angle, 0);
    func_003e4320(&direction, &delta, &matrix);
    direction.x = direction.x * cameraDistance;
    direction.y = direction.y * cameraDistance;
    direction.z = direction.z * cameraDistance;
    frames[1].pos.x = focus.x + direction.x;
    frames[1].pos.y = focus.y + direction.y;
    frames[1].pos.z = focus.z + direction.z;
    btlCameraLookAtQuat(&frames[1].rot, &frames[1].pos, &focus, D_0060A0E0);
    if (fixedShot == 0) {
        RwMatrixRotate(&matrix, (const RwV3d *)D_0060A0E0, -angle, 0);
        func_003e4320(&direction, &delta, &matrix);
        direction.x = direction.x * cameraDistance;
        direction.y = direction.y * cameraDistance;
        direction.z = direction.z * cameraDistance;
        frames[0].pos.x = focus.x + direction.x;
        frames[0].pos.y = focus.y + direction.y;
        frames[0].pos.z = focus.z + direction.z;
        btlCameraLookAtQuat(&frames[0].rot, &frames[0].pos, &focus, D_0060A0E0);
        func_004b3110(8);
        duration = 8.0f;
    } else {
        frames[0].pos = frames[1].pos;
        switch (*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x6E)) {
        case 52:
            frames[0].pos.y = 500.0f;
            focus.y = 450.0f;
            duration = 2.75f;
            break;
        case 53:
            frames[0].pos.y = 600.0f;
            focus.y = 550.0f;
            duration = 3.0f;
            break;
        case 56:
            frames[0].pos.y = 800.0f;
            focus.y = 700.0f;
            duration = 3.75f;
            break;
        case 78:
            frames[0].pos.y = 1000.0f;
            focus.y = 750.0f;
            duration = 2.5f;
            break;
        default:
            frames[0].pos.y = 500.0f;
            focus.y = 450.0f;
            duration = 2.75f;
            break;
        }
        btlCameraLookAtQuat(&frames[0].rot, &frames[0].pos, &focus, D_0060A0E0);
        func_004b3110(8);
    }
    btlCameraClampOffsetToLimit((f32 *)&frames[0], (f32 *)&frames[0]);
    btlCameraClampOffsetToLimit((f32 *)&frames[1], (f32 *)&frames[1]);
    btlMainCurveSetPoses((u16 *)arg0, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(arg0, duration);
}

