#include "btl_camera_framing_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "rw_types_internal.h"
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
extern void btlMainApplyUnitBaseColors(u8 *unit);
extern u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                          P4CameraFrame *firstOut, P4CameraFrame *secondOut);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 RwV3dNormalize(RwV3d *first, const RwV3d *second);
extern void btlCameraCopyPose();
extern void btlUnitGetAnimBoundsWorldCenter(BtlUnit *unit, RwV3d *outPosition);
extern RwMatrix *RwMatrixRotate(RwMatrix *first, const RwV3d *second, f32 third, s32 fourth);
extern RwV3d *func_003e4320(RwV3d *first, const RwV3d *second, const RwMatrix *third);
extern f32 tanf(f32 first);
extern f32 fGpffff80fc;
extern f32 fGpffff8114;
extern u8 *iGpffffb3ac; /* battle-state allocation */
extern u8 *iGpffffb3e0;
extern f32 fGpffff811c;
extern void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode);
extern void btlCameraFrameSweep(u8 *camera, f32 angle, f32 duration);
extern void btlCameraFrameFourPoseCurve(u8 *camera, f32 sweepAngle, f32 duration);
extern void btlUnitSetChildValue(BtlUnitStateWork *work, u16 value);
extern s32 btlCameraUnitAnimFinished(u8 *camera, u8 *unit);
extern void btlMainCurveSetPoses(u16 *curve, f32 *firstPose, f32 *lastPose, u16 mode);
extern void btlCameraSetDuration(u8 *work, f32 value);
extern void btlCameraStartEffect(u8 *camera, u8 *script, s32 options);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern s32 btlActionHasNoTargetClass(u8 *action);
extern void btlCameraFrameWithFlags(u8 *camera, s32 notify, s32 distinctPoses);
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
extern RwMatrix *RwMatrixRotate(RwMatrix *first, const RwV3d *second, f32 third, s32 fourth);
extern RwV3d *func_003e4320(RwV3d *first, const RwV3d *second, const RwMatrix *third);
extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
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
extern RwV3d *RtQuatTransformVectors(RwV3d *first, const RwV3d *second, s32 third, const RtQuat *fourth);
static inline f32 func_001c_mul_add(f32 first, f32 second, f32 third)
{
    return first * second + third;
}
static inline void func_001c_copy_pair(s64 *first, f32 *second,
                                       s64 *third, f32 *fourth)
{
    s64 pair;
    f32 value;

    pair = *third;
    value = *fourth;
    *first = pair;
    *second = value;
}
static inline void func_001c_rotate(RwMatrix *first, const RwV3d *second,
                                    f32 third, s32 fourth)
{
    RwMatrixRotate(first, second, third, fourth);
}


/* P3 btlCameraFrameActionSide (002a6ee0, donor NONMATCHING), adapted to P4; b210 -O2: 1208 bytes plus 8 retail zero bytes. */

static inline f32 cameraSideRadius(f32 first, f32 second)
{
    if (first > second) return first;
    return second;
}

/* Source unit: src/promoted/code1_001c.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001c.c; members 001ca590-001cbf80 */

/* measured: optimization_level 1 probe for c8cf0 argument order. */
/* measured: close optimization_level after c8cf0. */
/* Rotate around actor/target focus, resolving the side with the smaller quaternion change. */
// FUN_001CA590
void btlCameraFrameSweep(u8 *camera, f32 angle, f32 duration)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    f32 xz[2];
    RwV3d alternateEye;
    RwV3d viewDirection;
    RwV3d direction;
    RwV3d alternateDirection;
    RwV3d focus;
    RwV3d basePosition;
    RwV3d actorPosition;
    RwV3d targetPosition;
    struct {
        f32 perp[2];
        f32 horiz[2];
    } horizontal;
    P4Vec4Holder_001EC2B0 secondRotation;
    P4Vec4Holder_001EC2B0 firstRotation;
    RwMatrix matrix;
    P4CameraFrame frames[2];
    u8 *action;
    u8 *actorUnit;
    u8 *targetUnit;
    f32 distance;
    f32 height;
    f32 extent;
    f32 sideDot;
    f32 alignmentDot;
    f32 alternateDot;
    f32 tanHalfFov;
    f32 finalTanHalfFov;
    f32 halfHeight;
    f32 lateralOffset;
    f32 firstAngle;
    f32 secondAngle;
    f32 horizontalLength;
    f32 baseZ;
    f32 zero;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 fGpffff8118;
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 RwV2dLength(f32 *in);
    extern f32 fabsf(f32 x);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0* right, P4Vec4Holder_001EC2B0* left);
    extern f32 tanf(f32 angle);
    extern void btlCameraCopyPose(f32 *destination, f32 *source);

    action = (u8 *)((BtlCamera *)camera)->action;
    actorUnit = (u8 *)((BtlAction *)action)->unit;
    targetUnit = (u8 *)((BtlAction *)(*(u8 **)(action + 0x38)))->unit;
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    actorPosition.x = *(f32 *)(actorUnit + 0xDC);
    actorPosition.y = ((BtlUnit *)actorUnit)->sphereCenter.y * *(f32 *)(actorUnit + 0x2C);
    actorPosition.z = *(f32 *)(actorUnit + 0xE4);
    btlUnitGetSphereWorldCenter((BtlUnit *)targetUnit, &targetPosition);
    height = (0.0f + actorPosition.y + p4_cacd0_mul(((BtlUnit *)actorUnit)->unk_8c, *(f32 *)(actorUnit + 0x2C)) * fGpffff8118);
    height += (0.0f + targetPosition.y + p4_cacd0_mul(((BtlUnit *)targetUnit)->unk_8c, *(f32 *)(targetUnit + 0x2C)) * fGpffff8118);
    extent = 0.0f + *(f32 *)(actorUnit + 0xE8);
    extent += *(f32 *)(actorUnit + 0x90) * *(f32 *)(actorUnit + 0x2C);
    extent += *(f32 *)(targetUnit + 0x90) * *(f32 *)(targetUnit + 0x2C);
    targetPosition.y = 0.0f;
    actorPosition.y = 0.0f;
    zero = 0.0f;
    direction.x = ((BtlUnit *)actorUnit)->moveDestination.x - targetPosition.x;
    direction.y = ((BtlUnit *)actorUnit)->moveDestination.y - zero;
    direction.z = ((BtlUnit *)actorUnit)->moveDestination.z - targetPosition.z;
    RwV3dNormalize(&direction, &direction);
    focus.x = direction.x * (0.25f * extent);
    focus.y = direction.y * (0.25f * extent);
    focus.z = direction.z * (0.25f * extent);
    focus.x = focus.x + targetPosition.x;
    focus.y = focus.y + targetPosition.y;
    focus.z = focus.z + targetPosition.z;
    halfHeight = 0.5f * height;
    focus.y = halfHeight;
    ((BtlCameraFocusWork *)(camera + 0x100))->radius = 0.5f * ((BtlUnit *)actorUnit)->stoppingDistance;
    ((BtlCameraFocusWork *)(camera + 0x100))->focus = focus;
    horizontal.perp[0] = direction.z;
    horizontal.perp[1] = -direction.x;
    horizontal.horiz[0] = frames[0].pos.x - focus.x;
    horizontal.horiz[1] = frames[0].pos.z - focus.z;
    func_003e41e0(horizontal.perp, horizontal.perp);
    func_003e41e0(horizontal.horiz, horizontal.horiz);
    viewDirection.x = frames[0].pos.x - focus.x;
    viewDirection.y = frames[0].pos.y - focus.y;
    viewDirection.z = frames[0].pos.z - focus.z;
    sideDot = horizontal.perp[0] * horizontal.horiz[0] + horizontal.perp[1] * horizontal.horiz[1];
    if (!(sideDot < 0.0f)) {
        RwMatrixRotate(&matrix, (const RwV3d *)D_0060A0E0, angle, 0);
    } else {
        RwMatrixRotate(&matrix, (const RwV3d *)D_0060A0E0, -angle, 0);
    }
    func_003e4320(&viewDirection, &viewDirection, &matrix);
    viewDirection.x = viewDirection.x + focus.x;
    viewDirection.y = viewDirection.y + focus.y;
    viewDirection.z = viewDirection.z + focus.z;
    btlCameraLookAtQuat(&frames[1].rot, &viewDirection, &focus, D_0060A0E0);
    if (extent < 400.0f) {
        extent = 400.0f;
    }
    tanHalfFov = tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    distance = (0.5f * extent) / tanHalfFov;
    RtQuatTransformVectors((RwV3d *)&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
    direction.y = viewDirection.y;
    RwV3dNormalize(&direction, &direction);
    alignmentDot = viewDirection.x * direction.x + viewDirection.y * direction.y + viewDirection.z * direction.z;
    if (!(alignmentDot < 0.0f)) {
        extent = ((BtlUnit *)actorUnit)->sphereRadius * ((BtlUnit *)actorUnit)->scale;
        basePosition = actorPosition;
    } else {
        extent = ((BtlUnit *)targetUnit)->sphereRadius * ((BtlUnit *)targetUnit)->scale;
        basePosition = targetPosition;
    }
    alternateEye.x = 0.0f + targetPosition.x + direction.z * extent;
    alternateEye.y = focus.y;
    alternateEye.z = 0.0f + targetPosition.z - direction.x * extent;
    alternateDirection.x = alternateEye.x - focus.x;
    alternateDirection.y = focus.y - focus.y;
    alternateDirection.z = alternateEye.z - focus.z;
    RwV3dNormalize(&alternateDirection, &alternateDirection);
    alternateDot = alternateDirection.x * direction.x + alternateDirection.y * direction.y + alternateDirection.z * direction.z;
    if (!(fabsf(alignmentDot) <= fabsf(alternateDot)) && (alternateDot != 0.0f) && (alignmentDot != 0.0f)) {
        xz[0] = focus.x - basePosition.x;
        baseZ = basePosition.z;
        xz[1] = focus.z - baseZ;
        horizontalLength = RwV2dLength(xz);
        alternateEye.y = focus.y + (halfHeight * horizontalLength) / distance;
        alternateEye.x = 0.0f + basePosition.x + direction.z * extent;
        alternateEye.z = 0.0f + baseZ - direction.x * extent;
        btlCameraLookAtQuat(&firstRotation, &alternateEye, &focus, D_0060A0E0);
        firstAngle = btlTargetQuatAngle(&frames[0].rot, &firstRotation);
        alternateEye.x = 0.0f + basePosition.x - direction.z * extent;
        alternateEye.z = 0.0f + baseZ + direction.x * extent;
        btlCameraLookAtQuat(&secondRotation, &alternateEye, &focus, D_0060A0E0);
        secondAngle = btlTargetQuatAngle(&frames[0].rot, &secondRotation);
        if (firstAngle < secondAngle) {
            frames[1].rot = firstRotation;
        } else {
            frames[1].rot = secondRotation;
        }
        RtQuatTransformVectors((RwV3d *)&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
    }
    viewDirection.x = viewDirection.x * distance;
    viewDirection.y = viewDirection.y * distance;
    viewDirection.z = viewDirection.z * distance;
    finalTanHalfFov = tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    lateralOffset = distance * finalTanHalfFov;
    lateralOffset *= 0.21875f;
    xz[0] = viewDirection.x;
    xz[1] = viewDirection.z;
    func_003e41e0(xz, xz);
    focus.x = 0.0f + focus.x + xz[1] * lateralOffset;
    focus.z = 0.0f + focus.z - xz[0] * lateralOffset;
    frames[1].pos.x = focus.x + viewDirection.x;
    frames[1].pos.y = focus.y + viewDirection.y;
    frames[1].pos.z = focus.z + viewDirection.z;
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0].pos, (f32 *)&frames[1].pos, 1);
    btlCameraSetDuration(camera, duration);
}

/* 1052/1056 bytes; 19 resolved relocations; four zero alignment bytes.
 * Build the current pose plus three orbit keys with a halfword frame index. */
// FUN_001CACD0
void btlCameraFrameFourPoseCurve(u8 *camera, f32 sweepAngle, f32 duration)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    struct Quat {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct Frame {
        RwV3d pos;
        struct Quat rot;
    };
    struct Work {
        struct Frame frames[4];
        u8 matrix[0x40];
        f32 xzA[2];
        f32 xzB[2];
        RwV3d unit;
        u8 pad12C[4];
        RwV3d delta;
        u8 pad13C[4];
        RwV3d rotated;
        u8 pad14C[4];
        RwV3d scaled;
        u8 pad15C[4];
        RwV3d diff;
        u8 pad16C[4];
    } work;
    u8 *action;
    u8 *actorUnit;
    u8 *targetUnit;
    f32 prod;
    f32 height;
    f32 dot;
    f32 len;
    f32 angle;
    f32 step;
    f32 zero;
    u16 i;
    struct Frame *base;
    extern f32 fGpffff8118;
    extern f32 func_003e41e0(f32 *camera, f32 *first);
    extern void btlMainCurveSetFourPoses(void *camera, void *first, void *second, void *third, void *fourth, u16 mode);
    extern void btlCameraCopyPose(f32 *destination, f32 *source);

    action = (u8 *)((BtlCamera *)camera)->action;
    actorUnit = (u8 *)((BtlAction *)action)->unit;
    targetUnit = (u8 *)((BtlAction *)(*(u8 **)(action + 0x38)))->unit;
    btlCameraCopyPose((f32 *)&work.frames[0], (f32 *)(camera + 0x9C));
    prod = ((BtlUnit *)actorUnit)->sphereCenter.y * *(f32 *)(actorUnit + 0x2C);
    btlUnitGetSphereWorldCenter(targetUnit, (f32 *)&work.unit);
    height = (0.0f + prod + p4_cacd0_mul(((BtlUnit *)actorUnit)->unk_8c, ((BtlUnit *)actorUnit)->scale) * fGpffff8118);
    height += (0.0f + work.unit.y + (((BtlUnit *)targetUnit)->unk_8c * ((BtlUnit *)targetUnit)->scale) * fGpffff8118);
    work.unit.y = 0.0f;
    zero = 0.0f;
    work.diff.x = ((BtlUnit *)actorUnit)->moveDestination.x - work.unit.x;
    work.diff.y = ((BtlUnit *)actorUnit)->moveDestination.y - zero;
    work.diff.z = ((BtlUnit *)actorUnit)->moveDestination.z - work.unit.z;
    len = RwV3dNormalize((RwV3d *)&work.diff, (const RwV3d *)&work.diff);
    work.scaled.x = work.diff.x * (0.5f * len);
    work.scaled.y = work.diff.y * (0.5f * len);
    work.scaled.z = work.diff.z * (0.5f * len);
    work.scaled.x = work.scaled.x + work.unit.x;
    work.scaled.y = work.scaled.y + work.unit.y;
    work.scaled.z = work.scaled.z + work.unit.z;
    height = p4_cacd0_mul(0.5f, height);
    work.scaled.y = height;
    work.xzA[0] = work.diff.z;
    work.xzA[1] = -work.diff.x;
    work.xzB[0] = work.frames[0].pos.x - work.scaled.x;
    work.xzB[1] = work.frames[0].pos.z - work.scaled.z;
    func_003e41e0(work.xzA, work.xzA);
    func_003e41e0(work.xzB, work.xzB);
    dot = work.xzA[0] * work.xzB[0] + work.xzA[1] * work.xzB[1];
    if (!(dot < 0.0f)) {
        work.scaled.x = work.diff.x * (fGpffff8118 * len);
        work.scaled.y = work.diff.y * (fGpffff8118 * len);
        work.scaled.z = work.diff.z * (fGpffff8118 * len);
    } else {
        work.scaled.x = work.diff.x * (0.5f * len);
        work.scaled.y = work.diff.y * (0.5f * len);
        work.scaled.z = work.diff.z * (0.5f * len);
    }
    work.scaled.x = work.scaled.x + work.unit.x;
    work.scaled.y = work.scaled.y + work.unit.y;
    work.scaled.z = work.scaled.z + work.unit.z;
    work.scaled.y = height;
    ((BtlCameraFocusWork *)(camera + 0x100))->radius = 0.5f * ((BtlUnit *)actorUnit)->stoppingDistance;
    ((BtlCameraFocusWork *)(camera + 0x100))->focus = work.scaled;
    work.delta.x = work.frames[0].pos.x - work.scaled.x;
    work.delta.y = work.frames[0].pos.y - work.scaled.y;
    work.delta.z = work.frames[0].pos.z - work.scaled.z;
    angle = sweepAngle / 3.0f;
    step = angle;
    i = 1;
    while (i < 4) {
        if (!(dot < 0.0f)) {
            RwMatrixRotate((RwMatrix *)work.matrix, (const RwV3d *)D_0060A0E0, angle, 0);
        } else {
            RwMatrixRotate((RwMatrix *)work.matrix, (const RwV3d *)D_0060A0E0, -angle, 0);
        }
        func_003e4320((RwV3d *)&work.rotated, (const RwV3d *)&work.delta, (const RwMatrix *)work.matrix);
        base = &work.frames[(u16)i];
        base->pos.x = work.rotated.x + work.scaled.x;
        base->pos.y = work.rotated.y + work.scaled.y;
        base->pos.z = work.rotated.z + work.scaled.z;
        btlCameraLookAtQuat(&base->rot, &base->pos, &work.scaled, D_0060A0E0);
        angle = angle + step;
        i++;
    }
    btlMainCurveSetFourPoses(camera, &work.frames[0], &work.frames[1], &work.frames[2], &work.frames[3], 1);
    btlCameraSetDuration(camera, duration);
}

/* Choose a two-key sweep or four-key orbit from the camera mode and battle flag. */
// FUN_001CB0F0
void btlCameraUpdateSweepFrame(u8 *camera)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */

    u8 *action;
    u8 *battle;
    u16 mode;

    action = (u8 *)((BtlCamera *)camera)->action;
    if (((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->genus != 0) {
        return;
    }
    ((BtlCameraActionWork *)(camera + 0x100))->sweepTarget = (u8 *)(*(s32 *)(action + 0x38));
    battle = iGpffffb3ac;
    if (((s32)((BtlBattleState *)battle)->flags & 0x200000) == 0) {
        mode = ((BtlBattleState *)battle)->camera.repeatedStateCount;
        switch (mode) {
        case 0:
            btlCameraFrameSweep(camera, 40.0f, 2.0f);
            return;
        case 1:
            btlCameraFrameFourPoseCurve(camera, 100.0f, 3.0f);
            return;
        }
    } else {
        mode = ((BtlBattleState *)battle)->camera.repeatedStateCount;
        switch (mode) {
        case 0:
            btlCameraFrameSweep(camera, 20.0f, 2.0f);
            return;
        case 1:
            btlCameraFrameFourPoseCurve(camera, 50.0f, 3.0f);
            return;
        }
    }
}

/* Maintain stored-focus geometry while the active single-target action is unchanged. */
// FUN_001CB200
void btlCameraHoldFrame(u8 *camera)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */

    s32 active;
    u16 mode;
    u8 *action;

    action = (u8 *)((BtlCamera *)camera)->action;
    active = 0;
    if ((action != NULL) &&
        (((BtlAction *)action)->unk_6a == 1) &&
        ((s32)((BtlCameraActionWork *)(camera + 0x100))->sweepTarget == *(s32 *)(action + 0x38)) &&
        ((active = ((BtlAction *)action)->unk_1a & 1, active != 0)) &&
        (((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->genus == 0)) {
        mode = ((BtlBattleState *)iGpffffb3ac)->camera.repeatedStateCount;
        switch (mode) {
        case 0:
            if ((action != NULL) && (active != 0)) {
                btlCameraSetupActionGeometry(action, camera + 0x9C, (f32 *)(camera + 0x100),
                              ((BtlCameraFocusWork *)(camera + 0x100))->radius, 0xC3);
                return;
            }
            break;
        case 1:
        default:
            if ((action != NULL) && (active != 0)) {
                btlCameraSetupActionGeometry(action, camera + 0x9C, (f32 *)(camera + 0x100),
                              ((BtlCameraFocusWork *)(camera + 0x100))->radius, 0xC3);
            }
            break;
        }
    }
}

/* Select one of two character-specific camera scripts, each 0xF4 bytes. */
// FUN_001CB2E0
void btlCameraSpawnRandomWork(u8 *camera)
{
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    value = ((BtlUnit *)((u8 *)((BtlAction *)((u8 *)((BtlCamera *)camera)->action))->unit))->charId;
    flag_offset = (effMiscRand(0) & 1) * 0xF4;
    index_offset = (value & 0xFFFF) * 0x1E8;
    target = (u8 *)&D_005F7CA0 + index_offset;
    btlCameraStartEffect(camera, target + flag_offset, 2);
}

// FUN_001CB380
void btlCameraEffectListTick(void) {
    btlCameraUpdateEffectList();
}

/* Apply actor base colors and start a randomly selected character camera script. */
// FUN_001CB3A0
void btlCameraSpawnEffectB(u8 *camera)
{
    u8 *action;
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    action = (u8 *)((BtlCamera *)camera)->action;
    value = ((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->charId;
    btlMainApplyUnitBaseColors((u8 *)((BtlAction *)action)->unit);
    flag_offset = (effMiscRand(0) & 1) * 0xF4;
    index_offset = ((value & 0xFFFF) - 2) * 0x1E8;
    target = (u8 *)&D_005F91A0 + index_offset;
    btlCameraStartEffect(camera, target + flag_offset, 2);
}

// FUN_001CB440
void btlCameraEffectListTickAlt(void) {
    btlCameraUpdateEffectList();
}

/* Use a character script for a no-target-class action; otherwise build flagged framing. */
// FUN_001CB460
void btlCameraFrameRandomCut(u8 *camera)
{
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    value = ((BtlUnit *)((u8 *)((BtlAction *)(*(u8 **)(camera + 0xE0)))->unit))->charId;
    if (btlActionHasNoTargetClass(*(u8 **)(camera + 0xE0)) != 0) {
        flag_offset = (effMiscRand(0) & 1) * 0xF4;
        index_offset = ((value & 0xFFFF) - 2) * 0x1E8;
        target = (u8 *)&D_005FA2D0 + index_offset;
        btlCameraStartEffect(camera, target + flag_offset, 2);
        btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 3);
    } else {
        btlCameraFrameWithFlags(camera, 0, 1);
    }
}

/* Advance a no-target-class script, or restore completed child-unit animation state. */
// FUN_001CB540
void btlCameraFrameAnimWait(u8 *camera)
{
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    u8 *action;

    if (btlActionHasNoTargetClass(*(u8 **)(camera + 0xE0)) != 0) {
        btlCameraUpdateEffectList(camera);
        goto done;
    }
    action = (u8 *)((BtlCamera *)camera)->action;
    if (action == NULL)
        goto done;
    if (((BtlCamera *)camera)->frame != 0)
        goto done;
    if (action == NULL)
        goto done;
    if ((((BtlAction *)action)->unk_1a & 1) == 0)
        goto done;
    if (((BtlCamera *)camera)->delay == 0) {
        btlCameraSetupActionGeometry(action, NULL, NULL, 0.0f, 0x11);
    }
    if (btlCameraUnitAnimFinished(camera, *(u8 **)(camera + 0x12C)) != 0) {
        btlUnitSetChildValue((BtlUnitStateWork*)((BtlCamera *)camera)->animationUnit, ((BtlCamera *)camera)->animationValue);
    }
done:
    ;
}

/* 840/848 bytes; 27 resolved relocations; eight zero alignment bytes.
   Build both position/quaternion keys before clamping their heights. */
// FUN_001CB610
void btlCameraFrameRotateView(u8 *camera)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Matrix {
        struct Vec3 right;
        u32 flags;
        struct Vec3 up;
        u32 pad1;
        struct Vec3 at;
        u32 pad2;
        struct Vec3 pos;
        u32 pad3;
    };
    struct Work {
        struct Vec3 firstPosition;
        u8 firstView[0x10];
        struct Vec3 secondPosition;
        u8 secondView[0x18];
        struct Matrix rotation;
        struct Vec3 center;
        u8 padBC[4];
        struct Vec3 direction;
        u8 padCC[4];
        struct Vec3 scaled;
        u8 padDC[4];
    } work;
    u8 *target;
    f32 angleScale;
    f32 rotationAngle;
    f32 y;

    target = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x38);
    target = (u8 *)((BtlAction *)(target))->unit;
    btlUnitGetAnimBoundsWorldCenter((BtlUnit *)target, (RwV3d *)&work.center.x);
    work.center.y = 0.0f + work.center.y +
                    DAT_00761278 *
                    (((BtlUnit *)target)->unk_8c *
                     ((BtlUnit *)target)->scale);
    work.center.y = work.center.y + 10.0f;
    RtQuatTransformVectors((RwV3d *)&work.direction, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)(target + 0x1C));
    work.scaled.x = work.direction.x * 200.0f;
    work.scaled.y = work.direction.y * 200.0f;
    work.scaled.z = work.direction.z * 200.0f;
    y = work.center.y + work.scaled.y;
    y = y + 10.0f;
    work.direction.x = (work.center.x + work.scaled.x) - work.center.x;
    work.direction.y = y - work.center.y;
    work.direction.z = (work.center.z + work.scaled.z) - work.center.z;
    RwV3dNormalize((RwV3d *)&work.direction, (const RwV3d *)&work.direction);
    rotationAngle = 30.0f;
    RwMatrixRotate((RwMatrix *)&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * -rotationAngle, 0);
    func_003e4320((RwV3d *)&work.scaled, (const RwV3d *)&work.direction, (const RwMatrix *)&work.rotation);
    angleScale = 115.0f /
                 tanf(fGpffff8110 *
                      (0.5f * *(f32 *)(camera + 0xB8)));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.firstPosition.x = work.center.x + work.scaled.x;
    work.firstPosition.y = work.center.y + work.scaled.y;
    work.firstPosition.z = work.center.z + work.scaled.z;
    btlCameraLookAtQuat(work.firstView, &work.firstPosition, &work.center,
                  D_0060A0E0);
    RwMatrixRotate((RwMatrix *)&work.rotation, (const RwV3d *)D_0060A0E0, 15.0f, 0);
    func_003e4320((RwV3d *)&work.scaled, (const RwV3d *)&work.direction, (const RwMatrix *)&work.rotation);
    angleScale = 165.0f /
                 tanf(fGpffff8110 *
                      (0.5f * ((BtlCamera *)camera)->fovRad));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.secondPosition.x = work.center.x + work.scaled.x;
    work.secondPosition.y = work.center.y + work.scaled.y;
    work.secondPosition.z = work.center.z + work.scaled.z;
    btlCameraLookAtQuat(work.secondView, &work.secondPosition, &work.center,
                  D_0060A0E0);
    if (work.firstPosition.y < 25.0f) {
        work.firstPosition.y = 25.0f;
    }
    if (work.secondPosition.y < 25.0f) {
        work.secondPosition.y = 25.0f;
    }
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 3);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&work.firstPosition, (f32 *)&work.secondPosition, 1);
    btlCameraSetDuration(camera, 2.0f);
}

/* Empty update callback for ATTACK_SCF (state 17) in the retail camera table at 0x005F74C0. */
// FUN_001CB960
void btlCameraAttackScfUpdate(void) {}

/* Frame the two animation-bound centers and retain the selected side
 * between updates. Two complete poses feed the spline submission.
 * b210 -O2:1540 exact bytes,12 zero alignment bytes; comparison
 * lowering is documented in Camera_001cb970_20260920.md. */
// FUN_001CB970
void btlCameraApplyPreset(u8 *camera, f32 duration, s32 initialize)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d basePosition;
    RwV3d focus;
    RwV3d direction;
    RwV3d eye;
    f32 baseXZ[2];
    f32 projectedXZ[2];
    struct {
        f32 perpendicular[2];
        f32 horizontal[2];
        f32 focusXZ[2];
        f32 eyeXZ[2];
    } geometry;
    P4CameraFrame poses[2];
    u8 *actor;
    u8 *target;
    u8 *selectedUnit;
    u8 *otherUnit;
    f32 length;
    f32 focusScale;
    f32 sideRadius;
    f32 radiusFactor;
    f32 firstDot;
    f32 secondDot;
    f32 projectedRadius;
    f32 tanHalfFov;
    f32 distance;
    f32 baseZ;
    f32 baseY;
    u16 mode;
    u8 *action;
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0 *right, P4Vec4Holder_001EC2B0 *left);
    extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *projection);
    extern f32 tanf(f32 angle);
    extern void btlCameraCopyPoseTarget(f32 *destination, f32 *source);
    extern void btlCameraCopyPose(f32 *destination, f32 *source);
    extern f32 fGpffff80dc;
    extern f32 fGpffff8128;
    extern f32 fGpffff8138;

    action = *(u8 **)(camera + 0xE0);
    actor = (u8 *)((BtlAction *)action)->unit;
    target = (u8 *)((BtlAction *)(*(u8 **)(action + 0x38)))->unit;
    btlUnitGetAnimBoundsWorldCenter((BtlUnit *)actor, &actorPosition);
    btlUnitGetAnimBoundsWorldCenter((BtlUnit *)target, &targetPosition);
    direction.x = actorPosition.x - targetPosition.x;
    direction.y = actorPosition.y - targetPosition.y;
    direction.z = actorPosition.z - targetPosition.z;
    length = RwV3dNormalize(&direction, &direction);
    geometry.horizontal[0] = ((BtlCamera *)camera)->pose.pos.x - actorPosition.x;
    geometry.horizontal[1] = ((BtlCamera *)camera)->pose.pos.z - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);
    geometry.perpendicular[0] = direction.x;
    geometry.perpendicular[1] = direction.z;
    firstDot = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];
    if (initialize != 0) {
        if (((s32)((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) != 0) {
            ((BtlCameraPresetWork *)(camera + 0x100))->actorSide = 0;
        } else {
            ((BtlCameraPresetWork *)(camera + 0x100))->actorSide = firstDot >= 0.0f;
        }
    }
    if (((BtlCameraPresetWork *)(camera + 0x100))->actorSide == 1) {
        selectedUnit = actor;
        otherUnit = target;
        basePosition = actorPosition;
        sideRadius = 1.25f * (((BtlUnit *)actor)->sphereRadius * ((BtlUnit *)actor)->scale);
        radiusFactor = fGpffff8138;
        focusScale = fGpffff8128 * length;
        focus.x = direction.x * focusScale;
        focus.y = direction.y * focusScale;
        focus.z = direction.z * focusScale;
        if (basePosition.y < 100.0f) basePosition.y = 100.0f;
        baseY = basePosition.y;
        eye.y = baseY;
    } else {
        selectedUnit = target;
        otherUnit = actor;
        basePosition = targetPosition;
        sideRadius = fGpffff8128 * (((BtlUnit *)target)->sphereRadius * *(f32 *)(target + 0x2C));
        radiusFactor = 2.5f;
        actorPosition.y = (actorPosition.y + 0.0f) - 0.25f * (((BtlUnit *)target)->unk_8c * *(f32 *)(target + 0x2C));
        if (actorPosition.y < 100.0f) actorPosition.y = 100.0f;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        focusScale = 0.25f * length;
        focus.x = direction.x * focusScale;
        focus.y = direction.y * focusScale;
        focus.z = direction.z * focusScale;
        baseY = basePosition.y;
        eye.y = baseY;
    }
    focus.x += targetPosition.x;
    focus.y += targetPosition.y;
    focus.z += targetPosition.z;
    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    secondDot = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];
    if (initialize != 0) {
        ((BtlCameraPresetWork *)(camera + 0x100))->rightSide = secondDot >= 0.0f;
    }
    if (((BtlCameraPresetWork *)(camera + 0x100))->rightSide == 1) {
        eye.x = (basePosition.x + 0.0f) + direction.z * sideRadius;
        baseZ = basePosition.z;
        eye.z = (baseZ + 0.0f) - direction.x * sideRadius;
    } else {
        eye.x = (basePosition.x + 0.0f) - direction.z * sideRadius;
        baseZ = basePosition.z;
        eye.z = (baseZ + 0.0f) + direction.x * sideRadius;
    }
    btlCameraLookAtQuat(&poses[1].rot, &eye, &focus, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&poses[1].rot);
    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    projectedRadius = btlTargetAngleBetween((u8 *)geometry.focusXZ, (u8 *)geometry.eyeXZ, (u8 *)baseXZ, (u8 *)projectedXZ);
    projectedRadius = projectedRadius + 0.0f + radiusFactor * (((BtlUnit *)selectedUnit)->sphereRadius * ((BtlUnit *)selectedUnit)->scale);
    eye.x = projectedXZ[0];
    eye.y = baseY;
    eye.z = projectedXZ[1];
    tanHalfFov = tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    distance = projectedRadius / tanHalfFov;
    if (distance < 500.0f) distance = 500.0f;
    direction.x *= distance;
    direction.y *= distance;
    direction.z *= distance;
    poses[1].pos.x = eye.x + direction.x;
    poses[1].pos.y = eye.y + direction.y;
    poses[1].pos.z = eye.z + direction.z;
    if (poses[1].pos.y < 12.5f) poses[1].pos.y = 12.5f;
    btlCameraCopyPose((f32 *)&poses[0], (f32 *)(camera + 0x9C));
    if (initialize != 0) {
        if (!(btlTargetQuatAngle(&poses[0].rot, &poses[1].rot) <= fGpffff80dc)) {
            btlCameraCopyPoseTarget((f32 *)&poses[0], (f32 *)&poses[1]);
            mode = 3;
        } else {
            mode = 0x83;
        }
        btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, otherUnit + 4, (f32 *)&poses[1], 50.0f, mode);
    }
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses[0], (f32 *)&poses[1], 1);
    btlCameraSetDuration(camera, duration);
}

/* Record motion duration and target action for subsequent camera wait updates. */
// FUN_001CBF80
void btlCameraWaitMotionFrames(u8 *camera) {
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    ((BtlCameraMotionWaitWork *)(camera + 0x100))->duration =
        btlUnitMotionFrames((u8 *)((BtlAction *)(*(u8 **)(camera + 0xE0)))->unit, 4, 1.0f);
    ((BtlCameraMotionWaitWork *)(camera + 0x100))->targetAction = *(s32 *)((u8 *)((BtlCamera *)camera)->action + 0x38);
    ((BtlCameraMotionWaitWork *)(camera + 0x100))->elapsed = 0;
}

