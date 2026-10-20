#include "member_access.h"
#include "rw_object_internal.h"
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

extern void btlCameraSetLimitFrame(u8 *camera, f32 suppliedLimit, s32 reverse, s32 preserveSide);
extern void btlMainCurveReset(u16 *curve, f32 *pose);
extern u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                          P4CameraFrame *firstOut, P4CameraFrame *secondOut);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 RwV3dNormalize(RwV3d *first, const RwV3d *second);
extern void btlCameraCopyPose();
extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
extern RwMatrix *RwMatrixRotate(RwMatrix *first, const RwV3d *second, f32 third, s32 fourth);
extern RwV3d *func_003e4320(RwV3d *first, const RwV3d *second, const RwMatrix *third);
extern u32 btlCameraClampOffsetToLimit(f32 *pose, f32 *clampedPosition);
extern f32 tanf(f32 first);
extern f32 fGpffff80fc;
extern f32 fGpffff8114;
extern u8 *iGpffffb3ac; /* battle-state allocation */
extern u8 *iGpffffb3e0;
extern f32 fGpffff811c;
extern void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode);
extern s32 btlEffectCollectGenusMask(u8 *selection);
extern u32 btlFormationCurrentEntry(void *formation);
extern void btlCameraFrameStatus(u8 *camera, s32 unused);
extern void btlCameraFrameSideView(u8 *camera, s32 immediate);
extern void btlCameraUpdateOcclusion(u8 *camera);
extern void btlCameraMarkUnitFramed(u8 *unit);
extern void btlCameraClearUnitFramed(u8 *unitAddress);
extern u8 *kwlnGetCamera(void);
extern void btlCameraBuildPosePair(u8 *camera, P4CameraFrame *first, P4CameraFrame *second);
extern void btlMainCurveSetPoses(u16 *curve, f32 *firstPose, f32 *lastPose, u16 mode);
extern void btlCameraSetDuration(u8 *work, f32 value);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
extern RwMatrix *RwMatrixRotate(RwMatrix *first, const RwV3d *second, f32 third, s32 fourth);
extern RwV3d *func_003e4320(RwV3d *first, const RwV3d *second, const RwMatrix *third);
extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
extern u8 D_0060A0D0[];
extern u8 D_0060A0E0[];
extern RwV3d D_0060A0F0;
extern u8 D_0060A100[];
extern s32 btlTargetFindInRange(f32 *position, f32 *output);
extern f32 btlTargetVectorDistance(f32 *first, u8 *second);
extern s32 fptodp(f32 first);
extern s32 func_0044b310(s32 first);
extern f32 dptofp(s32 first);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001c.c; members 001c79e0-001c9820 */

/* Empty update callback for OVERLIMIT (state 32) in the retail camera table at 0x005F74C0. */
// FUN_001C79E0
void btlCameraOverlimitUpdate(void) {}

/* MATCH.  The last two words were the order of two operand loads feeding one
   add: retail loads the position Y coordinate into $f1 before the direction Y
   coordinate into $f0, this body did the reverse.  Snapshotting the position
   Y into an ordinary float local immediately before the first Y output, and
   using it in both Y expressions, gives retail's order - retail reuses that
   value in the final height calculation, which is why it loads it first.
   The position of the snapshot is the whole trick: taken before the X output
   it scores 5, and before the position X update 20, which is why the earlier
   pass recorded "hoisting pos138[1] into a local (5)" and concluded the load
   pair was a scheduler coin-flip.  It was not.
   Also measured at 2 and byte-identical on the way here: `schedule off`,
   `opt_loop_invariants on`, `opt_unroll_loops off`, an explicit `tmpMul`
   temporary, a reassociated `dir128[1] * var_f20 + pos138[1]`, and fully
   parenthesised operands.  Worse: reordering the three `outC0[i]` assignments
   (17 and 8), splitting the add into `= pos; += dir * f` (40), `schedule on`
   (388), `peephole off` (402), `opt_propagation off` (397),
   `opt_common_subs off` (401). */
/* Frame a target according to death, guarding, low HP and status, or frame the group. */
// FUN_001C79F0
void btlCameraFrameStatus(u8 *camera, s32 unused)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    struct Frame {
        u8 mat60[0x40];
        f32 poseA0[7];
        u8 padBC[4];
        f32 outC0[3];
        f32 quatCC[4];
        f32 padDC;
        f32 horizE0[2];
        f32 actorE8[3];
        f32 padF4;
        f32 baseF8[3];
        f32 pad104;
        f32 eye108[3];
        f32 pad114;
        f32 target118[3];
        f32 pad124;
        f32 dir128[3];
        f32 pad134;
        f32 pos138[3];
        f32 pad144;
        f32 min148;
        f32 max14C;
    } frame;
    extern f32 fGpffff8110;
    extern f32 fGpffff8128;
    extern f32 fGpffff812c;
    extern f32 fGpffff8118;
    extern f32 fGpffff8130;
    extern f32 fGpffff8134;
    extern f32 fGpffff8138;
    extern f32 fGpffff813c;
    extern f32 fGpffff8030;
    extern void btlUnitGetAttachedSphereCenter(u8 *context, f32 *value);
    extern s32 datCalcIsDead(s32 unit, s32 hpDelta);
    extern s32 datCalcIsGuarding(s32 unitFlags);
    extern s32 datCalcIsLowHp(s32 unit);
    extern f32 tanf(f32 camera);
    extern f32 func_003e41e0(f32 *camera, f32 *unused);
    f32 halfHeight;
    f32 distanceFactor;
    f32 heightFactor;
    f32 angleOrOffset;
    f32 distance;
    f32 positionY;
    u8 *savedCamera;
    u8 *targetAction;
    u8 *unit;
    (void)unused;

    savedCamera = camera;
    if (((BtlCameraStatusWork *)(savedCamera + 0x100))->groupMode != 0) {
        btlCameraCopyPose(frame.poseA0, (f32 *)(savedCamera + 0x9C));
        unit = (u8 *)((BtlAction *)((u8 *)((BtlCamera *)savedCamera)->action))->unit;
        distance = btlUnitGetGroupBounds(3, 0, (RwV3d *)(frame.target118), 0, 0, 1);
        btlUnitGetGroupBounds(1, 0, NULL, &frame.max14C, &frame.min148, 1);
        frame.target118[1] = frame.min148 + 0.5f * (frame.max14C - frame.min148);
        distance = (0.75f * distance) / tanf(fGpffff8110 * (0.5f * MEMBER(f32, savedCamera, BtlCamera, fovRad)));
        btlUnitGetGridSphereCenter((BtlUnit *)(unit), (RwV3d *)(frame.actorE8));
        frame.eye108[0] = frame.actorE8[0];
        frame.eye108[1] = frame.target118[1];
        frame.eye108[2] = frame.actorE8[2];
        frame.dir128[0] = frame.actorE8[0] - frame.target118[0];
        frame.dir128[1] = frame.target118[1] - frame.target118[1];
        frame.dir128[2] = frame.actorE8[2] - frame.target118[2];
        {
            f32 tmpLen;
            tmpLen = RwV3dNormalize((RwV3d *)frame.dir128, (const RwV3d *)frame.dir128);
            tmpLen = p4_cacd0_mul(fGpffff8128, tmpLen);
            frame.dir128[0] = frame.dir128[0] * tmpLen;
            frame.dir128[1] = frame.dir128[1] * tmpLen;
            frame.dir128[2] = frame.dir128[2] * tmpLen;
        }
        frame.baseF8[0] = frame.target118[0] + frame.dir128[0];
        frame.baseF8[1] = frame.target118[1] + frame.dir128[1];
        frame.baseF8[2] = frame.target118[2] + frame.dir128[2];
        frame.eye108[0] = frame.actorE8[0];
        frame.eye108[1] = frame.max14C;
        frame.eye108[2] = frame.actorE8[2];
        btlCameraLookAtQuat((void *)frame.quatCC, (void *)frame.eye108, (void *)frame.baseF8, (void *)D_0060A0E0);
        RtQuatTransformVectors((RwV3d *)frame.dir128, (const RwV3d *)D_0060A100, 1, (const RtQuat *)frame.quatCC);
        frame.dir128[0] = frame.dir128[0] * distance;
        frame.dir128[1] = frame.dir128[1] * distance;
        frame.dir128[2] = frame.dir128[2] * distance;
        distance = p4_cacd0_mul(distance * tanf(fGpffff8110 * (0.5f * ((BtlCamera *)savedCamera)->fovRad)), 0.21875f);
        distance = distance * fGpffff812c;
        frame.horizE0[0] = frame.dir128[0];
        frame.horizE0[1] = frame.dir128[2];
        func_003e41e0(frame.horizE0, frame.horizE0);
        frame.baseF8[0] = frame.horizE0[1] * distance + frame.baseF8[0] + 0.0f;
        frame.baseF8[2] = (frame.baseF8[2] + 0.0f) - frame.horizE0[0] * distance;
        frame.outC0[0] = frame.baseF8[0] + frame.dir128[0];
        frame.outC0[1] = frame.baseF8[1] + frame.dir128[1];
        frame.outC0[2] = frame.baseF8[2] + frame.dir128[2];
        btlCameraClampOffsetToLimit(frame.outC0, frame.outC0);
        btlMainCurveSetPoses((u16 *)savedCamera, frame.poseA0, frame.outC0, 1);
        btlCameraSetDuration(savedCamera, 0.75f);
    } else {
        ((BtlCamera *)savedCamera)->forceTransition = 1;
        targetAction = (u8 *)btlFormationCurrentEntry((u8 *)((BtlCamera *)savedCamera)->action + 0x98);
        unit = (u8 *)((BtlAction *)targetAction)->unit;
        distance = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)(unit))->scale;
        halfHeight = 0.5f * (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)(unit))->scale);
        if (datCalcIsDead(MEMBER(s32, unit, BtlUnit, datUnit), 0) != 0) {
            btlUnitGetAttachedSphereCenter(unit, frame.pos138);
            distanceFactor = 1.5f;
            heightFactor = 3.5f;
            angleOrOffset = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8118 * halfHeight;
        } else if (datCalcChkBadStatus(MEMBER(s32, unit, BtlUnit, datUnit), 0x100000) != 0) {
            btlUnitGetSphereWorldCenter(unit, frame.pos138);
            distanceFactor = fGpffff8130;
            heightFactor = fGpffff8134;
            angleOrOffset = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8118 * halfHeight;
        } else if (datCalcIsGuarding(MEMBER(s32, unit, BtlUnit, datUnit)) != 0) {
            btlUnitGetSphereWorldCenter(unit, frame.pos138);
            distanceFactor = fGpffff8138;
            heightFactor = 0.75f;
            angleOrOffset = 15.0f;
            frame.pos138[1] = frame.pos138[1] + fGpffff8118 * halfHeight;
        } else if (datCalcIsLowHp((s32)((BtlUnit *)unit)->datUnit) != 0) {
            btlUnitGetSphereWorldCenter(unit, frame.pos138);
            distanceFactor = fGpffff8138;
            heightFactor = 1.0f;
            angleOrOffset = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8030 * halfHeight;
        } else {
            btlUnitGetSphereWorldCenter(unit, frame.pos138);
            distanceFactor = 1.25f;
            heightFactor = 1.0f;
            angleOrOffset = 25.0f;
            frame.pos138[1] = frame.pos138[1] + fGpffff813c * halfHeight;
        }
        if (distance > halfHeight) {
            distance = (distance * distanceFactor) / tanf(fGpffff8110 * (0.5f * MEMBER(f32, savedCamera, BtlCamera, fovRad)));
        } else {
            distance = (halfHeight * distanceFactor) / tanf(0.5f * ((BtlCamera *)savedCamera)->fovRad);
        }
        RtQuatTransformVectors((RwV3d *)frame.dir128, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
        RwMatrixRotate((RwMatrix *)frame.mat60, (const RwV3d *)D_0060A0E0, angleOrOffset, 0);
        func_003e4320((RwV3d *)frame.dir128, (const RwV3d *)frame.dir128, (const RwMatrix *)frame.mat60);
        angleOrOffset = p4_cacd0_mul(distance * tanf(fGpffff8110 * (0.5f * ((BtlCamera *)savedCamera)->fovRad)), 0.21875f);
        angleOrOffset = angleOrOffset * fGpffff8118;
        frame.horizE0[0] = frame.dir128[0];
        frame.horizE0[1] = frame.dir128[2];
        func_003e41e0(frame.horizE0, frame.horizE0);
        frame.pos138[0] = frame.horizE0[1] * angleOrOffset + frame.pos138[0] + 0.0f;
        frame.pos138[2] = (frame.pos138[2] + 0.0f) - frame.horizE0[0] * angleOrOffset;
        frame.outC0[0] = frame.pos138[0] + frame.dir128[0] * distance;
        positionY = frame.pos138[1];
        frame.outC0[1] = positionY + frame.dir128[1] * distance;
        frame.outC0[2] = frame.pos138[2] + frame.dir128[2] * distance;
        frame.outC0[1] = positionY + halfHeight * heightFactor;
        btlCameraLookAtQuat((void *)frame.quatCC, (void *)frame.outC0, (void *)frame.pos138, (void *)D_0060A0E0);
        btlCameraSetupActionGeometry(targetAction, (u8 *)0, (f32 *)0, 0.0f, 1);
        btlMainCurveReset((u16 *)(savedCamera), (f32 *)frame.outC0);
    }
}

/* Interpolate the group and target orientations using a complete
 * quaternion cache and four complete poses. Position weights remain
 * distinct from the sine-adjusted quaternion weights.
 * b210 -O2: 2012 exact bytes and four zero alignment bytes. */
// FUN_001C80F0
void btlCameraFrameSideView(u8 *camera, s32 immediate)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    f32 top;
    RwV3d direction;
    RwV3d delta;
    RwV3d focus;
    RwV3d actorPosition;
    RwV3d center;
    P4CameraFrame frames[2];
    P4CameraFrame endpoints[2];
    P4CameraBlend blend;
    P4Vec4Holder_001EC2B0 heading;
    f32 distance;
    f32 doubledRadius;
    f32 separation;
    f32 halfFov;
    f32 heightDistance;
    f32 minimumDistance;
    f32 scale;
    f32 firstWeight;
    f32 secondWeight;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    u8 *unit;
    u8 *next;
    u8 *target;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern void btlCameraCopyPose(f32 *destination, f32 *source);
    extern void btlCameraCopyPoseTarget(f32 *destination, f32 *source);
    extern void btlTargetBlendVectors(u8 *rotation, u8 *first, u8 *second);
    extern void func_003dcc70(const void *first, const void *second, void *result);
    extern f32 tanf(f32 angle);
    extern f32 fGpffff8118, fGpffff80bc, fGpffff8120, fGpffff8124;
    extern f32 fGpffff8104, fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060, fGpffff8108;

    unit = (u8 *)((BtlAction *)(MEMBER(u8 *, camera, BtlCamera, action)))->unit;
    next = (u8 *)btlFormationCurrentEntry(MEMBER(u8 *, camera, BtlCamera, action) + 0x98);
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &actorPosition);
    doubledRadius = ((BtlUnit *)unit)->sphereRadius * MEMBER(f32, unit, BtlUnit, scale);
    doubledRadius *= 2.0f;
    actorPosition.y = 0.0f + actorPosition.y + fGpffff8118 * (MEMBER(f32, unit, BtlUnit, unk_8c) * MEMBER(f32, unit, BtlUnit, scale));
    distance = btlUnitGetGroupBounds(2, 0, &center, &top, NULL, 1);
    top *= fGpffff8100;
    center.y = top;
    btlTargetBlendVectors((u8 *)&heading, (u8 *)&actorPosition, (u8 *)&center);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)&heading);
    direction.x *= doubledRadius;
    direction.y *= doubledRadius;
    direction.z *= doubledRadius;
    actorPosition.x += direction.x;
    actorPosition.y += direction.y;
    actorPosition.z += direction.z;
    delta.x = actorPosition.x - center.x;
    delta.y = actorPosition.y - center.y;
    delta.z = actorPosition.z - center.z;
    separation = RwV3dNormalize(&delta, &delta);
    scale = fGpffff811c * separation;
    focus.x = delta.x * scale;
    focus.y = delta.y * scale;
    focus.z = delta.z * scale;
    focus.x += center.x;
    focus.y += center.y;
    focus.z += center.z;
    direction = actorPosition;
    btlCameraLookAtQuat(&endpoints[0].rot, &direction, &focus, D_0060A0E0);
    halfFov = 0.5f * MEMBER(f32, camera, BtlCamera, fovRad);
    if (((BtlCamera *)(camera))->status.groupMode == 0) {
        heightDistance = 0.75f * (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale);
        heightDistance /= tanf(halfFov);
        minimumDistance = (0.75f * distance) / tanf(halfFov);
    } else {
        heightDistance = fGpffff811c * (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale);
        heightDistance /= tanf(halfFov);
        minimumDistance = (fGpffff811c * distance) / tanf(halfFov);
    }
    distance = heightDistance + separation;
    distance = cameraSideRadius(distance, minimumDistance);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&endpoints[0].rot);
    scale = distance * tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    scale *= 0.109375f;
    scale *= fGpffff80bc;
    center.x = 0.0f + center.x + direction.z * scale;
    center.z = 0.0f + center.z - direction.x * scale;
    direction.x *= distance;
    direction.y *= distance;
    direction.z *= distance;
    endpoints[0].pos.x = center.x + direction.x;
    endpoints[0].pos.y = center.y + direction.y;
    endpoints[0].pos.z = center.z + direction.z;
    if (((BtlCameraStatusWork *)(camera + 0x100))->groupMode == 0) {
        target = (u8 *)((BtlAction *)next)->unit;
        btlUnitGetGridSphereCenter((BtlUnit *)(target), (RwV3d *)((f32 *)&center));
        if (!(50.0f <= center.y)) center.y = 50.0f;
        btlTargetBlendVectors((u8 *)&heading, (u8 *)&actorPosition, (u8 *)&center);
        RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)&heading);
        direction.x *= doubledRadius;
        direction.y *= doubledRadius;
        direction.z *= doubledRadius;
        actorPosition.x += direction.x;
        actorPosition.y += direction.y;
        actorPosition.z += direction.z;
        delta.x = actorPosition.x - center.x;
        delta.y = actorPosition.y - center.y;
        delta.z = actorPosition.z - center.z;
        RwV3dNormalize(&delta, &delta);
        scale = fGpffff811c * RwV3dNormalize(&delta, &delta);
        focus.x = delta.x * scale;
        focus.y = delta.y * scale;
        focus.z = delta.z * scale;
        focus.x += center.x;
        focus.y += center.y;
        focus.z += center.z;
        direction = actorPosition;
        btlCameraLookAtQuat(&endpoints[1].rot, &direction, &focus, D_0060A0E0);
        endpoints[1].pos = endpoints[0].pos;
        func_003dcc70(&endpoints[0].rot, &endpoints[1].rot, &blend);
        firstWeight = fGpffff8120;
        secondWeight = fGpffff8124;
        if (blend.flag == 0) {
            x = firstWeight * blend.scalar;
            x2 = x * x;
            r = 0.0f + fGpffff8054 + fGpffff8104 * x2;
            r = 0.0f + fGpffff8058 + x2 * r;
            r = 0.0f + fGpffff805c + x2 * r;
            r = 0.0f + fGpffff8060 + x2 * r;
            r2 = 0.0f + fGpffff8108 + x2 * r;
            r = x2 * x;
            firstWeight = 0.0f + x + r * r2;
            x = secondWeight * blend.scalar;
            x2 = x * x;
            r = 0.0f + fGpffff8054 + fGpffff8104 * x2;
            r = 0.0f + fGpffff8058 + x2 * r;
            r = 0.0f + fGpffff805c + x2 * r;
            r = 0.0f + fGpffff8060 + x2 * r;
            r2 = 0.0f + fGpffff8108 + x2 * r;
            r = x2 * x;
            secondWeight = 0.0f + x + r * r2;
        }
        frames[1].rot.quat.x = blend.first.quat.x * firstWeight;
        frames[1].rot.quat.y = blend.first.quat.y * firstWeight;
        frames[1].rot.quat.z = blend.first.quat.z * firstWeight;
        frames[1].rot.quat.x = 0.0f + frames[1].rot.quat.x + blend.second.quat.x * secondWeight;
        frames[1].rot.quat.y = 0.0f + frames[1].rot.quat.y + blend.second.quat.y * secondWeight;
        frames[1].rot.quat.z = 0.0f + frames[1].rot.quat.z + blend.second.quat.z * secondWeight;
        frames[1].rot.quat.w = blend.first.quat.w * firstWeight + blend.second.quat.w * secondWeight;
        x = endpoints[0].pos.x;
        x *= fGpffff8120;
        endpoints[0].pos.x = x;
        endpoints[0].pos.y *= fGpffff8120;
        endpoints[0].pos.z *= fGpffff8120;
        x = endpoints[1].pos.x;
        secondWeight = fGpffff8124;
        endpoints[1].pos.x = x * secondWeight;
        endpoints[1].pos.y *= secondWeight;
        endpoints[1].pos.z *= secondWeight;
        frames[1].pos.x = endpoints[0].pos.x + endpoints[1].pos.x;
        frames[1].pos.y = endpoints[0].pos.y + endpoints[1].pos.y;
        frames[1].pos.z = endpoints[0].pos.z + endpoints[1].pos.z;
    } else {
        btlCameraCopyPoseTarget((f32 *)&frames[1], (f32 *)&endpoints[0]);
    }
    if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
    if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 0xE0);
    if (immediate != 0) {
        btlMainCurveReset((u16 *)camera, (f32 *)&frames[1]);
        return;
    }
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, 0.75f);
}

/* Project three sphere samples to a screen rectangle and return its depth on success. */
// FUN_001C88D0
s32 btlCameraFindOccluder(u8 *unit, s32 *rectangle, f32 *depth, u8 *cameraMatrix)
{
    struct Frame {
        u8 pad48[0x8];
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
        f32 valueAC;
    } frame;
    f32 product;
    f32 distance1;
    f32 distance2;
    product = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale;
    distance1 = fGpffff809c * product;
    product = ((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale;
    distance2 = 0.5f * (fGpffff809c * product);
    btlUnitGetSphereWorldCenter(unit, &frame.valueA0);
    frame.value90 = frame.valueA0;
    frame.value94 = frame.valueA4 + distance2;
    frame.value98 = frame.valueA8;
    func_003e4320((RwV3d *)(u8 *)&frame.value70, (const RwV3d *)D_0060A0D0, (const RwMatrix *)cameraMatrix);
    frame.value70 = frame.value70 * distance1;
    frame.value74 = frame.value74 * distance1;
    frame.value78 = frame.value78 * distance1;
    frame.value80 = frame.valueA0 + frame.value70;
    frame.value84 = frame.valueA4 + frame.value74;
    frame.value88 = frame.valueA8 + frame.value78;
    if ((btlTargetFindInRange(&frame.valueA0, &frame.value68) != 0) &&
        (btlTargetFindInRange(&frame.value90, &frame.value60) != 0) &&
        (btlTargetFindInRange(&frame.value80, &frame.value58) != 0)) {
        *depth = btlTargetVectorDistance(&frame.valueA0, cameraMatrix + 0x30);
        distance1 = dptofp(
            func_0044b310(fptodp(frame.value64 - frame.value6C)));
        distance2 = dptofp(
            func_0044b310(fptodp(frame.value58 - frame.value68)));
        rectangle[0] = (s32)(frame.value68 - distance2);
        rectangle[1] = (s32)(frame.value6C - distance1);
        rectangle[3] = (s32)(2.0f * distance1);
        rectangle[2] = (s32)(2.0f * distance2);
        return 1;
    }
    return 0;
}

/* Compare projected unit rectangles and depths to mark units obscuring the framed target. */
// FUN_001C8B00
void btlCameraUpdateOcclusion(u8 *camera)
{
    /* Keep the external SDK camera handle byte-addressed at its frame-pointer ABI boundary. */
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    struct Frame {
        s32 value60;
        s32 value64;
        s32 value68;
        s32 value6C;
        s32 value70;
        s32 value74;
        s32 value78;
        s32 value7C;
        u8 pad80[8];
        f32 value88;
        f32 value8C;
    } frame;
    u8 *unit;
    u8 *targetUnit;
    u8 *cameraMatrix;
    s32 sideIndex;
    u8 *actorUnit;

    if (((BtlCameraStatusWork *)(camera + 0x100))->groupMode == 0) {
        cameraMatrix = (u8 *)((RwObject *)(kwlnGetCamera()))->parent + 0x10;
        targetUnit = (u8 *)((BtlAction *)((u8 *)btlFormationCurrentEntry(MEMBER(u8 *, camera, BtlCamera, action) + 0x98)))->unit;
        actorUnit = (u8 *)((BtlAction *)((u8 *)((BtlCamera *)camera)->action))->unit;
        if (btlCameraFindOccluder(targetUnit, &frame.value60, &frame.value88, cameraMatrix) != 0) {
            btlCameraClearUnitFramed(targetUnit);
            sideIndex = 0;
            goto outer_test;
outer_body:
            unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[sideIndex * 2];
            goto inner_test;
inner_body:
            if ((((s32)((BtlUnit *)unit)->flags3 & 8) != 0) &&
                (targetUnit != unit) &&
                (actorUnit != unit)) {
                if (btlCameraFindOccluder(unit, &frame.value70, &frame.value8C, cameraMatrix) == 0) {
                    btlCameraClearUnitFramed(targetUnit);
                } else if (!(frame.value8C <= frame.value88)) {
                    btlCameraClearUnitFramed(targetUnit);
                } else {
                    if (frame.value60 > frame.value70 + frame.value78) {
                        goto range_reject;
                    }
                    if (frame.value70 > frame.value60 + frame.value68) {
                        goto range_reject;
                    }
                    if (frame.value64 > frame.value74 + frame.value7C) {
                        goto range_reject;
                    }
                    if (frame.value74 > frame.value64 + frame.value6C) {
                        goto range_reject;
                    }
                    btlCameraMarkUnitFramed(unit);
                    goto range_done;
range_reject:
                    btlCameraClearUnitFramed(targetUnit);
range_done:
                    ;
                }
            }
            unit = (u8 *)((BtlUnit *)unit)->nextUnit;
inner_test:
            if (unit != NULL) {
                goto inner_body;
            }
            sideIndex += 1;
outer_test:
            if (sideIndex < 2) {
                goto outer_body;
            }
        }
    }
}

/* measured: optimization_level 1 probe for c8cf0 argument order. */
/* Cache target classification and genus mask, then clear the previously framed action. */
// FUN_001C8CF0
void btlCameraReleaseOcclusion(u8 *camera)
{
    u8 *action;
    u8 *actionArgument;
    s32 targetArgument;
    u16 entryIndex;

    action = (u8 *)((BtlCamera *)camera)->action;
    actionArgument = action;
    targetArgument = 0;
    entryIndex = ((BtlAction *)action)->unk_6e;
    ((BtlCameraStatusWork *)(camera + 0x100))->groupMode = btlSkillClassifyTargets(actionArgument, (u8 *)targetArgument, (u16)entryIndex, 0);
    ((BtlCameraStatusWork *)(camera + 0x100))->genusMask = btlEffectCollectGenusMask(action + 0x98);
    ((BtlCameraStatusWork *)(camera + 0x100))->action = NULL;
}

/* measured: close optimization_level after c8cf0. */
/* Reframe when the formation target changes, optionally updating occluding units first. */
// FUN_001C8D50
void btlCameraUpdateFrame(u8 *camera)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    s32 flag;
    u16 mode;
    u16 type;
    u8 *next;
    u8 *current;

    next = (u8 *)btlFormationCurrentEntry((u8 *)((BtlCamera *)camera)->action + 0x98);
    if (((BtlCamera *)(camera))->status.genusMask == 2) {
        btlCameraUpdateOcclusion(camera);
    }
    if ((next == NULL) ||
        ((current = ((BtlCameraStatusWork *)(camera + 0x100))->action, current == next)) ||
        ((current != NULL) && (((BtlCameraStatusWork *)(camera + 0x100))->groupMode != 0))) {
        return;
    }
    if (current == NULL) {
        mode = ((BtlBattleState *)iGpffffb3ac)->camera.stateHistory[0];
        switch (mode) {
        case 0x21:
        case 0x28:
        case 2:
        case 0x29:
            flag = 0;
            break;
        default:
            flag = 1;
            break;
        }
    } else {
        flag = 0;
    }
    ((BtlCameraStatusWork *)(camera + 0x100))->action = next;
    type = ((BtlCameraStatusWork *)(camera + 0x100))->genusMask;
    switch (type) {
    case 2:
        btlCameraFrameSideView(camera, flag);
        return;
    case 1:
    default:
        btlCameraFrameStatus(camera, flag);
        return;
    }
}

/* Produce current and adjusted poses with a limited quaternion angle.
 * The interpolation cache and all vectors are complete objects.
 * b210 -O2:2228 exact bytes and12 zero alignment bytes. */
// FUN_001C8E90
void btlCameraBuildPosePair(u8 *camera, P4CameraFrame *first, P4CameraFrame *second)
{
    /* Target storage is reused by AI commands; retain each access's word or pointer interpretation. */
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    f32 xz[2];
    RwV3d alternateEye;
    RwV3d viewDirection;
    RwV3d direction;
    RwV3d alternateDirection;
    RwV3d focus;
    RwV3d basePosition;
    RwV3d actorPosition;
    RwV3d targetPosition;
    P4Vec4Holder_001EC2B0 limitedRotation;
    P4Vec4Holder_001EC2B0 secondRotation;
    P4Vec4Holder_001EC2B0 firstRotation;
    P4CameraBlend blend;
    u8 *action;
    u8 *actor;
    u8 *targetAction;
    u8 *target;
    f32 distance;
    f32 height;
    f32 halfHeight;
    f32 span;
    f32 scale;
    f32 angle;
    f32 threshold;
    f32 ratio;
    f32 firstWeight;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 alignmentDot;
    f32 alternateDot;
    f32 baseZ;
    f32 horizontalLength;
    f32 firstAngle;
    f32 secondAngle;
    f32 lateralOffset;
    f32 tanHalfFov;
    f32 zero;
    extern void btlCameraCopyPose(f32 *destination, f32 *source);
    extern void btlUnitGetSphereCenterTowardTarget(BtlUnit *unit, BtlUnit *target, RwV3d *outPosition);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0 *right, P4Vec4Holder_001EC2B0 *left);
    extern void func_003dcc70(const void *first, const void *second, void *out);
    extern RtQuat *func_003dc740(RtQuat *quat, const RwV3d *axis, f32 angle, s32 combine);
    extern f32 tanf(f32 angle);
    extern f32 RwV2dLength(f32 *in);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 fabsf(f32 x);
    extern f32 fGpffff8118, fGpffff815c, fGpffff804c, fGpffff8160;
    extern f32 fGpffff8104, fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060, fGpffff8108;

    action = (u8 *)((BtlCamera *)camera)->action;
    actor = (u8 *)((BtlAction *)action)->unit;
    targetAction = ((BtlAction *)(action))->targets[0];
    target = (u8 *)((BtlAction *)targetAction)->unit;
    ((BtlCameraActionWork *)(camera + 0x100))->geometryTarget = targetAction;
    btlCameraCopyPose((f32 *)first, (f32 *)(camera + 0x9C));
    actorPosition.x = MEMBER(f32, actor, BtlUnit, moveDestination.x);
    actorPosition.y = ((BtlUnit *)actor)->sphereCenter.y * MEMBER(f32, actor, BtlUnit, scale);
    actorPosition.z = MEMBER(f32, actor, BtlUnit, moveDestination.z);
    btlUnitGetSphereCenterTowardTarget((BtlUnit *)target, (BtlUnit *)actor, &targetPosition);
    height = 0.0f + actorPosition.y + p4_cacd0_mul(((BtlUnit *)actor)->unk_8c, MEMBER(f32, actor, BtlUnit, scale)) * fGpffff8118;
    height += 0.0f + targetPosition.y + p4_cacd0_mul(((BtlUnit *)target)->unk_8c, MEMBER(f32, target, BtlUnit, scale)) * fGpffff8118;
    span = 0.0f + MEMBER(f32, actor, BtlUnit, stoppingDistance);
    span += MEMBER(f32, actor, BtlUnit, sphereRadius) * MEMBER(f32, actor, BtlUnit, scale);
    span += MEMBER(f32, target, BtlUnit, sphereRadius) * MEMBER(f32, target, BtlUnit, scale);
    targetPosition.y = 0.0f;
    actorPosition.y = 0.0f;
    zero = 0.0f;
    direction.x = ((BtlUnit *)actor)->moveDestination.x - targetPosition.x;
    direction.y = ((BtlUnit *)actor)->moveDestination.y - zero;
    direction.z = ((BtlUnit *)actor)->moveDestination.z - targetPosition.z;
    RwV3dNormalize(&direction, &direction);
    scale = 0.25f * span;
    focus.x = direction.x * scale;
    focus.y = direction.y * scale;
    focus.z = direction.z * scale;
    focus.x += targetPosition.x;
    focus.y += targetPosition.y;
    focus.z += targetPosition.z;
    halfHeight = 0.5f * height;
    focus.y = halfHeight;
    viewDirection = first->pos;
    viewDirection.y = height;
    ((BtlCameraFocusWork *)(camera + 0x100))->radius = 0.5f * ((BtlUnit *)actor)->stoppingDistance;
    ((BtlCameraFocusWork *)(camera + 0x100))->focus = focus;
    btlCameraLookAtQuat(&second->rot, &viewDirection, &focus, D_0060A0E0);
    height = 0.0f + span;
    height += MEMBER(f32, actor, BtlUnit, sphereRadius) * MEMBER(f32, actor, BtlUnit, scale);
    height += MEMBER(f32, target, BtlUnit, sphereRadius) * MEMBER(f32, target, BtlUnit, scale);
    angle = btlTargetQuatAngle(&first->rot, &second->rot);
    threshold = fGpffff815c;
    if (!(angle <= threshold)) {
        ratio = threshold / angle;
        func_003dcc70(&first->rot, &second->rot, &blend);
        if (ratio <= 0.0f) {
            limitedRotation = first->rot;
        } else if (1.0f <= ratio) {
            limitedRotation = second->rot;
        } else {
            firstWeight = 1.0f - ratio;
            if (blend.flag == 0) {
                x = firstWeight * blend.scalar;
                x2 = x * x;
                r = 0.0f + fGpffff8054 + fGpffff8104 * x2;
                r = 0.0f + fGpffff8058 + x2 * r;
                r = 0.0f + fGpffff805c + x2 * r;
                r = 0.0f + fGpffff8060 + x2 * r;
                r2 = 0.0f + fGpffff8108 + x2 * r;
                r = x2 * x;
                firstWeight = 0.0f + x + r * r2;
                x = ratio * blend.scalar;
                x2 = x * x;
                r = 0.0f + fGpffff8054 + fGpffff8104 * x2;
                r = 0.0f + fGpffff8058 + x2 * r;
                r = 0.0f + fGpffff805c + x2 * r;
                r = 0.0f + fGpffff8060 + x2 * r;
                r2 = 0.0f + fGpffff8108 + x2 * r;
                r = x2 * x;
                ratio = 0.0f + x + r * r2;
            }
            limitedRotation.quat.x = blend.first.quat.x * firstWeight;
            limitedRotation.quat.y = blend.first.quat.y * firstWeight;
            limitedRotation.quat.z = blend.first.quat.z * firstWeight;
            limitedRotation.quat.x = 0.0f + limitedRotation.quat.x + blend.second.quat.x * ratio;
            limitedRotation.quat.y = 0.0f + limitedRotation.quat.y + blend.second.quat.y * ratio;
            limitedRotation.quat.z = 0.0f + limitedRotation.quat.z + blend.second.quat.z * ratio;
            limitedRotation.quat.w = blend.first.quat.w * firstWeight + blend.second.quat.w * ratio;
        }
        RtQuatTransformVectors(&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&limitedRotation);
        viewDirection.x += focus.x;
        viewDirection.y += focus.y;
        viewDirection.z += focus.z;
        btlCameraLookAtQuat(&second->rot, &viewDirection, &focus, D_0060A0E0);
    } else if (angle < fGpffff804c) {
        func_003dc740((RtQuat *)&second->rot, (const RwV3d *)D_0060A0E0, fGpffff8160, 2);
    }
    if (height < 450.0f) height = 450.0f;
    tanHalfFov = tanf(fGpffff8110 * (0.5f * MEMBER(f32, camera, BtlCamera, fovRad)));
    distance = (0.5f * height) / tanHalfFov;
    RtQuatTransformVectors(&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&second->rot);
    direction.y = viewDirection.y;
    RwV3dNormalize(&direction, &direction);
    alignmentDot = viewDirection.x * direction.x + viewDirection.y * direction.y + viewDirection.z * direction.z;
    if (!(alignmentDot < 0.0f)) {
        height = ((BtlUnit *)actor)->sphereRadius * ((BtlUnit *)actor)->scale;
        basePosition = actorPosition;
    } else {
        height = ((BtlUnit *)target)->sphereRadius * ((BtlUnit *)target)->scale;
        basePosition = targetPosition;
    }
    alternateEye.x = 0.0f + targetPosition.x + direction.z * height;
    alternateEye.y = focus.y;
    alternateEye.z = 0.0f + targetPosition.z - direction.x * height;
    alternateDirection.x = alternateEye.x - focus.x;
    alternateDirection.y = focus.y - focus.y;
    alternateDirection.z = alternateEye.z - focus.z;
    RwV3dNormalize(&alternateDirection, &alternateDirection);
    alternateDot = alternateDirection.x * direction.x + alternateDirection.y * direction.y + alternateDirection.z * direction.z;
    if (!(fabsf(alignmentDot) <= fabsf(alternateDot)) && alternateDot != 0.0f && alignmentDot != 0.0f) {
        xz[0] = focus.x - basePosition.x;
        baseZ = basePosition.z;
        xz[1] = focus.z - baseZ;
        horizontalLength = RwV2dLength(xz);
        alternateEye.y = focus.y + (halfHeight * horizontalLength) / distance;
        alternateEye.x = 0.0f + basePosition.x + direction.z * height;
        alternateEye.z = 0.0f + baseZ - direction.x * height;
        btlCameraLookAtQuat(&firstRotation, &alternateEye, &focus, D_0060A0E0);
        firstAngle = btlTargetQuatAngle(&first->rot, &firstRotation);
        alternateEye.x = 0.0f + basePosition.x - direction.z * height;
        alternateEye.z = 0.0f + baseZ + direction.x * height;
        btlCameraLookAtQuat(&secondRotation, &alternateEye, &focus, D_0060A0E0);
        secondAngle = btlTargetQuatAngle(&first->rot, &secondRotation);
        if (firstAngle < secondAngle) second->rot = firstRotation;
        else second->rot = secondRotation;
        RtQuatTransformVectors(&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&second->rot);
    }
    viewDirection.x *= distance;
    viewDirection.y *= distance;
    viewDirection.z *= distance;
    tanHalfFov = tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    lateralOffset = distance * tanHalfFov;
    lateralOffset *= 0.21875f;
    lateralOffset *= 0.5f;
    xz[0] = viewDirection.x;
    xz[1] = viewDirection.z;
    func_003e41e0(xz, xz);
    focus.x = 0.0f + focus.x + xz[1] * lateralOffset;
    focus.z = 0.0f + focus.z - xz[0] * lateralOffset;
    second->pos.x = focus.x + viewDirection.x;
    second->pos.y = focus.y + viewDirection.y;
    second->pos.z = focus.z + viewDirection.z;
}

/* Build the adjusted endpoint and reset the camera curve to that pose. */
// FUN_001C9750
void btlCameraApplyPosePair(u8 *camera)
{
    struct {
        P4CameraFrame first;
        P4CameraFrame second;
    } work;

    btlCameraBuildPosePair(camera, &work.first, &work.second);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&work.first, (f32 *)&work.second, 1);
    btlCameraSetDuration(camera, fGpffff811c);
}

/* Refresh stored-focus geometry while the original target action remains active. */
// FUN_001C97B0
void btlCameraFrameAim(u8 *camera)
{
    /* Target storage is reused by AI commands; retain each access's word or pointer interpretation. */

    u8 *action;
    f32 value;

    action = (u8 *)((BtlCamera *)camera)->action;
    if ((action != NULL) &&
        (((BtlAction *)action)->unk_6a == 1) &&
        ((s32)((BtlCameraActionWork *)(camera + 0x100))->geometryTarget == (s32)((BtlAction *)(action))->targets[0]) &&
        ((((BtlAction *)action)->unk_1a & 1) != 0)) {
        value = ((BtlCameraFocusWork *)(camera + 0x100))->radius;
        btlCameraSetupActionGeometry(action, camera + 0x9C, (f32 *)(camera + 0x100), value, 0xC3);
    }
}

/* Construct an angle-limited camera transition from complete pose geometry. */
/* Select actor or target side framing and limit the transition by its quaternion angle. */
// FUN_001C9820
void btlCameraSetLimitFrame(u8 *camera, f32 suppliedLimit, s32 reverse, s32 preserveSide)
{
    /* Target storage is reused by AI commands; retain each access's word or pointer interpretation. */
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    RwV3d actorCenter;
    RwV3d targetCenter;
    RwV3d center;
    RwV3d focus;
    RwV3d direction;
    RwV3d eye;
    RwV3d savedDirection;
    P4CameraVec2 projectedCenter;
    P4CameraVec2 projection;
    struct { P4CameraVec2 horizontal; P4CameraVec2 camera;
             P4CameraVec2 focus; P4CameraVec2 eye; } plane;
    P4CameraFrame frames[2];
    u8 *action;
    u8 *actor;
    u8 *target;
    u8 *otherUnit;
    u8 *viewUnit;
    f32 distance;
    f32 angleLimit;
    f32 geometry;
    f32 actorRadius;
    f32 targetRadius;
    f32 forwardDot;
    f32 scale;
    f32 side;
    f32 difference;
    f32 tangent;
    f32 baseZ;
    f32 baseY;
    f32 angleScale;
    extern f32 fGpffff8098, fGpffff80cc, fGpffff810c, fGpffff8110;
    extern f32 fGpffff8128, fGpffff816c, fGpffff8168, fGpffff8170;
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
    extern void btlCameraCopyPose(f32 *destination, f32 *source);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *projection);
    extern f32 btlTargetQuatAngle(P4Vec4Holder_001EC2B0 *right, P4Vec4Holder_001EC2B0 *left);
    extern f32 tanf(f32 angle);

    angleLimit = suppliedLimit;
    btlCameraCopyPose((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    action = MEMBER(u8 *, camera, BtlCamera, action);
    actor = (u8 *)((BtlAction *)action)->unit;
    target = (u8 *)((BtlAction *)(((BtlAction *)(action))->targets[0]))->unit;
    btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorCenter);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetCenter);
    geometry = 0.0f + targetCenter.y + 0.5f * (MEMBER(f32, target, BtlUnit, unk_8c) * MEMBER(f32, target, BtlUnit, scale));
    if (targetCenter.y < 125.0f) targetCenter.y = 125.0f;
    actorRadius = MEMBER(f32, actor, BtlUnit, sphereRadius) * MEMBER(f32, actor, BtlUnit, scale);
    targetRadius = MEMBER(f32, target, BtlUnit, sphereRadius) * MEMBER(f32, target, BtlUnit, scale);
    direction.x = actorCenter.x - targetCenter.x;
    direction.y = actorCenter.y - targetCenter.y;
    direction.z = actorCenter.z - targetCenter.z;
    distance = RwV3dNormalize(&direction, &direction);
    scale = fGpffff8128 * distance;
    focus.x = direction.x * scale;
    focus.y = direction.y * scale;
    focus.z = direction.z * scale;
    focus.x += targetCenter.x;
    focus.y += targetCenter.y;
    focus.z += targetCenter.z;
    plane.camera.x = ((BtlCamera *)camera)->pose.pos.x - focus.x;
    plane.camera.y = ((BtlCamera *)camera)->pose.pos.z - focus.z;
    func_003e41e0((f32 *)&plane.camera, (f32 *)&plane.camera);
    plane.horizontal.x = direction.x;
    plane.horizontal.y = direction.z;
    forwardDot = plane.horizontal.x * plane.camera.x + plane.horizontal.y * plane.camera.y;
    if ((!(forwardDot < 0.0f) || preserveSide == 1) && reverse == 0) {
        viewUnit = actor;
        otherUnit = target;
        center = actorCenter;
        side = 2.5f * (MEMBER(f32, actor, BtlUnit, sphereRadius) * MEMBER(f32, actor, BtlUnit, scale));
        if (geometry <= 400.0f) {
            focus.y = 0.0f + focus.y + fGpffff8098 * (((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale);
        } else {
            focus.y = 0.0f + focus.y + fGpffff810c * (((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale);
        }
        plane.horizontal.x = direction.z;
        plane.horizontal.y = -direction.x;
        geometry = plane.horizontal.x * plane.camera.x + plane.horizontal.y * plane.camera.y;
        baseY = center.y;
        eye.y = 0.0f + baseY + 0.5f * (MEMBER(f32, actor, BtlUnit, unk_8c) * MEMBER(f32, actor, BtlUnit, scale));
        if (!(geometry < 0.0f)) {
            eye.x = 0.0f + center.x + direction.z * side;
            baseZ = center.z;
            eye.z = (0.0f + baseZ) - direction.x * side;
        } else {
            eye.x = (0.0f + center.x) - direction.z * side;
            baseZ = center.z;
            eye.z = 0.0f + baseZ + direction.x * side;
            savedDirection = direction;
        }
        btlCameraLookAtQuat(&frames[1].rot, &eye, &focus, D_0060A0E0);
        RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = center.x;
        projectedCenter.y = baseZ;
        distance = btlTargetAngleBetween((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        distance = 0.0f + distance + 2.0f * (MEMBER(f32, actor, BtlUnit, sphereRadius) * MEMBER(f32, actor, BtlUnit, scale));
        eye.x = projection.x;
        eye.y = 0.0f + baseY + 0.25f * (((BtlUnit *)actor)->unk_8c * MEMBER(f32, actor, BtlUnit, scale));
        eye.z = projection.y;
        angleScale = fGpffff8110;
        scale = distance / tanf(angleScale * (0.5f * MEMBER(f32, camera, BtlCamera, fovRad)));
        direction.x *= scale;
        direction.y *= scale;
        direction.z *= scale;
        if (geometry < 0.0f) {
            side = 2.0f * (((BtlUnit *)actor)->sphereRadius * ((BtlUnit *)actor)->scale);
            eye.x = 0.0f + eye.x + savedDirection.z * side;
            eye.z = (0.0f + eye.z) - savedDirection.x * side;
        }
        frames[1].pos.x = eye.x + direction.x;
        frames[1].pos.y = eye.y + direction.y;
        frames[1].pos.z = eye.z + direction.z;
    } else {
        f32 side;
        viewUnit = target;
        otherUnit = actor;
        scale = 0.5f * distance;
        focus.x = direction.x * scale;
        focus.y = direction.y * scale;
        focus.z = direction.z * scale;
        focus.x += targetCenter.x;
        focus.y += targetCenter.y;
        focus.z += targetCenter.z;
        center = targetCenter;
        side = 1.25f * (MEMBER(f32, target, BtlUnit, sphereRadius) * MEMBER(f32, target, BtlUnit, scale));
        plane.horizontal.x = direction.z;
        plane.horizontal.y = -direction.x;
        geometry = plane.horizontal.x * plane.camera.x + plane.horizontal.y * plane.camera.y;
        baseY = center.y;
        eye.y = baseY;
        if (baseY < actorCenter.y) eye.y = actorCenter.y;
        if (!(geometry < 0.0f)) {
            eye.x = 0.0f + center.x + direction.z * side;
            baseZ = center.z;
            eye.z = (0.0f + baseZ) - direction.x * side;
            savedDirection = direction;
        } else {
            eye.x = (0.0f + center.x) - direction.z * side;
            baseZ = center.z;
            eye.z = 0.0f + baseZ + direction.x * side;
        }
        btlCameraLookAtQuat(&frames[1].rot, &eye, &focus, D_0060A0E0);
        RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = center.x;
        projectedCenter.y = baseZ;
        distance = btlTargetAngleBetween((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        distance = 0.0f + distance + 1.5f * (MEMBER(f32, target, BtlUnit, sphereRadius) * MEMBER(f32, target, BtlUnit, scale));
        eye.x = projection.x;
        eye.y = baseY;
        eye.z = projection.y;
        angleScale = fGpffff8110;
        scale = distance / tanf(angleScale * (0.5f * ((BtlCamera *)camera)->fovRad));
        if (scale < (f32)550) scale = (f32)550;
        direction.x *= scale;
        direction.y *= scale;
        direction.z *= scale;
        if (!(geometry < 0.0f)) {
            side = 0.5f * (((BtlUnit *)target)->sphereRadius * ((BtlUnit *)target)->scale);
            eye.x = (0.0f + eye.x) - savedDirection.z * side;
            eye.z = 0.0f + eye.z + savedDirection.x * side;
        }
        frames[1].pos.x = eye.x + direction.x;
        frames[1].pos.y = eye.y + direction.y;
        frames[1].pos.z = eye.z + direction.z;
    }
    difference = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
    if (angleLimit > 0.0f) {
        angleLimit = p4_cacd0_mul(fGpffff816c, angleLimit);
        if (difference <= angleLimit) goto limitedTransition;
    }
    {
        if (forwardDot < 0.0f) {
            btlMainCurveReset((u16 *)camera, (f32 *)&frames[1]);
            RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
            direction.x *= 200.0f;
            direction.y *= 200.0f;
            direction.z *= 200.0f;
            frames[0].pos.x = frames[1].pos.x + direction.x;
            frames[0].pos.y = frames[1].pos.y + direction.y;
            frames[0].pos.z = frames[1].pos.z + direction.z;
            frames[0].rot = frames[1].rot;
            if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
            if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
            btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
            btlCameraSetDuration(camera, fGpffff8168);
        } else {
            forwardDot = MEMBER(f32, viewUnit, BtlUnit, sphereRadius) * MEMBER(f32, viewUnit, BtlUnit, scale);
            direction.x = actorCenter.x - targetCenter.x;
            direction.y = actorCenter.y - targetCenter.y;
            direction.z = actorCenter.z - targetCenter.z;
            RwV3dNormalize(&direction, &direction);
            eye.y = 0.0f + baseY + fGpffff8170 * (MEMBER(f32, viewUnit, BtlUnit, unk_8c) * MEMBER(f32, viewUnit, BtlUnit, scale));
            if (!(geometry < 0.0f)) {
                eye.x = (0.0f + center.x) - direction.z * forwardDot;
                eye.z = 0.0f + baseZ + direction.x * forwardDot;
            } else {
                eye.x = 0.0f + center.x + direction.z * forwardDot;
                eye.z = (0.0f + baseZ) - direction.x * forwardDot;
            }
            btlCameraLookAtQuat(&frames[0].rot, &eye, &focus, D_0060A0E0);
            RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot);
            plane.focus.x = focus.x;
            plane.focus.y = focus.z;
            plane.eye.x = eye.x;
            plane.eye.y = eye.z;
            projectedCenter.x = center.x;
            projectedCenter.y = baseZ;
            btlTargetAngleBetween((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
            eye.x = projection.x;
            eye.y = 0.0f + baseY + fGpffff8170 * (((BtlUnit *)viewUnit)->unk_8c * MEMBER(f32, viewUnit, BtlUnit, scale));
            eye.z = projection.y;
            tangent = tanf(angleScale * (0.5f * ((BtlCamera *)camera)->fovRad));
            scale = (4.0f * (((BtlUnit *)viewUnit)->sphereRadius * ((BtlUnit *)viewUnit)->scale)) / tangent;
            direction.x *= scale;
            direction.y *= scale;
            direction.z *= scale;
            frames[0].pos.x = eye.x + direction.x;
            frames[0].pos.y = eye.y + direction.y;
            frames[0].pos.z = eye.z + direction.z;
            if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
            if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
            btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
            btlCameraSetDuration(camera, fGpffff8168);
        }
        actorRadius = actorRadius > targetRadius ? actorRadius : targetRadius;
        btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, otherUnit + 4, (f32 *)&frames[1], actorRadius, 3);
        return;
    }
limitedTransition:
    actorRadius = actorRadius > targetRadius ? actorRadius : targetRadius;
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, otherUnit + 4, (f32 *)&frames[1], actorRadius, 0xC3);
    if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
    if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
    difference = btlTargetQuatAngle(&frames[0].rot, &frames[1].rot);
    forwardDot = 1.25f;
    if (!(difference <= 0.0f)) {
        scale = angleLimit / difference;
        if (!(scale <= 1.0f)) forwardDot = scale * fGpffff80cc;
        else forwardDot = fGpffff80cc;
        if (!(forwardDot <= 1.25f)) forwardDot = 1.25f;
    }
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    btlCameraSetDuration(camera, forwardDot);
}

