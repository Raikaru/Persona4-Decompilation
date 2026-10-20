#include "member_access.h"
#include "btl_camera_framing_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "rw_types_internal.h"
#include "btl_motion_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"


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
extern void btlCameraFrameRotated(u8 *camera, f32 pitch, f32 yawStep, f32 distanceFactor);
extern void btlCameraFrameRotatedWide(u8 *camera, f32 pitch, f32 yawStep, f32 distanceFactor);
extern void btlMainApplyUnitBaseColors(u8 *unit);
extern void CrossfadeRequest(s32 frameLimit);
extern void btlMainCurveReset(u16 *curve, f32 *pose);
extern u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                          P4CameraFrame *firstOut, P4CameraFrame *secondOut);
extern void btlCameraFrameStatusRoll(u8 *camera, f32 firstFactor, f32 secondFactor);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 RwV3dNormalize(RwV3d *first, const RwV3d *second);
extern f32 RwV3dLength(f32 *first);
extern void btlCameraCopyPose();
extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
extern void btlUnitGetAnimBoundsWorldCenter(BtlUnit *unit, RwV3d *outPosition);
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
extern void btlMainCurveSetPoses(u16 *curve, f32 *firstPose, f32 *lastPose, u16 mode);
extern void btlCameraSetDuration(u8 *work, f32 value);
extern void btlCameraStartEffect(u8 *camera, u8 *script, s32 options);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern u32 datCalcRandomBelow(u32 limit);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern void btlUnitSetFlags(u8 *first, s32 second, s32 third, u8 *fourth, s32 fifth);
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


/* Source unit: src/promoted/code1_001c.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001c.c; members 001ce470-001cff00 */

/* measured: opt_propagation off probe for ce470 mixed-load ordering. */
/* measured: func_001ce470 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Submit fixed pose pairs at entry and frame 0x25 with their respective durations. */
// FUN_001CE470
void btlCameraFrameFixed(u8 *camera)
{
    struct Frame {
        f32 value10;
        f32 value14;
        f32 value18;
        f32 value1C;
        u8 pad20[0xC];
        f32 value2C;
        f32 value30;
        f32 value34;
        f32 value38;
        u8 tail3C[0x14];
    } frame;
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 *vector;

    if (((BtlCamera *)camera)->frame == 0) {
        btlCameraLookAtQuat(&frame.value1C,
                      (f32 *)D_00607DD0, D_00607DF0, D_0060A0E0);
        func_001c_copy_pair((s64 *)&frame.value10,
                            &frame.value18,
                            (s64 *)D_00607DD0,
                            (f32 *)D_00607DD8);
        btlCameraLookAtQuat(&frame.value38,
                      D_00607E10, D_00607E30, D_0060A0E0);
        vector = &frame.value2C;
        *(struct Vec3 *)&frame.value2C =
            *(struct Vec3 *)D_00607E10;
        btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24), &frame.value10, vector, 1);
        btlCameraSetDuration(iGpffffb3ac + 0x24, fGpffff819c);
        return;
    }
    if (((BtlCamera *)camera)->frame == 0x25) {
        btlCameraLookAtQuat(&frame.value1C,
                      D_00607DDC, D_00607DFC, D_0060A0E0);
        *(struct Vec3 *)&frame.value10 =
            *(struct Vec3 *)D_00607DDC;
        btlCameraLookAtQuat(&frame.value38,
                      D_00607E1C, D_00607E3C, D_0060A0E0);
        vector = &frame.value2C;
        *(struct Vec3 *)&frame.value2C =
            *(struct Vec3 *)D_00607E1C;
        btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24), &frame.value10, vector, 1);
        btlCameraSetDuration(iGpffffb3ac + 0x24, fGpffff809c);
    }
}

/* measured: close ce470 opt_propagation off probe. */
/* measured: func_001ce620 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
/* Cache group bounds once, then advance yaw and submit a pitch-rotated pose. */
// FUN_001CE620
void btlCameraFrameRotated(u8 *camera, f32 pitch, f32 yawStep, f32 distanceFactor)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    struct Frame {
        u8 matrix[0x40];
        f32 result[3];
        f32 quat[4];
        u8 pad5C[4];
        f32 transformed[3];
    } frame;
    f32 scale;

    if (((BtlCamera *)(camera))->orbit.refreshBounds != 0) {
        ((BtlCameraOrbitWork *)(camera + 0x100))->radius =
            btlUnitGetGroupBounds(3, 0, (RwV3d *)(camera + 0x104), 0, 0, 1);
        ((BtlCameraOrbitWork *)(camera + 0x100))->focus.y = 0.0f;
        ((BtlCameraOrbitWork *)(camera + 0x100))->refreshBounds = 0;
    }
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0D0, pitch, 0);
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0E0,
                     ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw, 2);
    func_003e4320((RwV3d *)frame.transformed, (const RwV3d *)(&D_0060A0F0), (const RwMatrix *)frame.matrix);
    scale = (((BtlCameraOrbitWork *)(camera + 0x100))->radius * distanceFactor) /
            tanf(fGpffff8110 *
                          (0.5f * ((BtlCamera *)camera)->fovRad));
    frame.transformed[0] *= scale;
    frame.transformed[1] *= scale;
    frame.transformed[2] *= scale;
    frame.result[0] = frame.transformed[0] + ((BtlCameraOrbitWork *)(camera + 0x100))->focus.x;
    frame.result[1] = frame.transformed[1] + ((BtlCameraOrbitWork *)(camera + 0x100))->focus.y;
    frame.result[2] = frame.transformed[2] + ((BtlCameraOrbitWork *)(camera + 0x100))->focus.z;
    btlCameraLookAtQuat(frame.quat, frame.result, camera + 0x104,
                  D_0060A0E0);
    if (frame.result[1] < 25.0f) {
        frame.result[1] = 25.0f;
    }
    ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw += yawStep;
    if (((s32)((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) == 0) {
        btlCameraClampOffsetToLimit(frame.result, frame.result);
    }
    btlMainCurveReset((u16 *)(camera), (f32 *)(frame.result));
}

/* measured probe: optimization_level 1 for 001CE7F0 register coloring. */
/* measured: func_001ce7f0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* Initialize random yaw and request fresh group bounds for rotating framing. */
// FUN_001CE7F0
void btlCameraFrameRandomShift(u8 *camera) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = datCalcRandomBelow(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw = value;
    ((BtlCameraOrbitWork *)(camera + 0x100))->refreshBounds = 1;
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 0x100);
}

/* measured probe: close optimization_level 1 for 001CE7F0. */
/* measured: btlAct_ROUNDUP_MES, func_001ce8c0, func_001ceba0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_001CE880
void btlCameraFrameRotatedAlt(u8 *camera) {
    btlCameraFrameRotated(camera, -17.5f, 0.25f, 0.75f);
}

/* Cache a group-to-target bearing, then orbit it with a minimum framing extent. */
// FUN_001CE8C0
void btlCameraFrameRotatedWide(u8 *camera, f32 pitch, f32 yawStep, f32 distanceFactor)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    struct Frame {
        u8 matrix[0x40];
        f32 result[3];
        f32 quat[4];
        u8 pad5C[4];
        f32 diff[3];
        u8 pad6C[4];
        f32 target[3];
    } frame;
    f32 scale;

    if (((BtlCamera *)(camera))->orbit.refreshBounds != 0) {
        btlUnitGetGroupBounds(2, 1, (RwV3d *)(frame.target), 0, 0, 1);
        ((BtlCameraOrbitWork *)(camera + 0x100))->radius =
            btlUnitGetGroupBounds(3, 0, (RwV3d *)(camera + 0x104), 0, 0, 2);
        ((BtlCamera *)(camera))->orbit.focus.y = 0.0f;
        frame.diff[0] = ((BtlCamera *)(camera))->orbit.focus.x - frame.target[0];
        frame.diff[1] = ((BtlCamera *)(camera))->orbit.focus.y - frame.target[1];
        frame.diff[2] = ((BtlCamera *)(camera))->orbit.focus.z - frame.target[2];
        scale = fGpffff8100 * RwV3dNormalize((RwV3d *)frame.diff, (const RwV3d *)frame.diff);
        frame.diff[0] *= scale;
        frame.diff[1] *= scale;
        frame.diff[2] *= scale;
        ((BtlCameraOrbitWork *)(camera + 0x100))->focus.x = frame.target[0] + frame.diff[0];
        ((BtlCameraOrbitWork *)(camera + 0x100))->focus.y = frame.target[1] + frame.diff[1];
        ((BtlCameraOrbitWork *)(camera + 0x100))->focus.z = frame.target[2] + frame.diff[2];
        ((BtlCameraOrbitWork *)(camera + 0x100))->focus.y = frame.target[1];
        ((BtlCameraOrbitWork *)(camera + 0x100))->direction.x =
            ((BtlCameraOrbitWork *)(camera + 0x100))->focus.x - frame.target[0];
        ((BtlCameraOrbitWork *)(camera + 0x100))->direction.y =
            ((BtlCameraOrbitWork *)(camera + 0x100))->focus.y - frame.target[1];
        ((BtlCameraOrbitWork *)(camera + 0x100))->direction.z =
            ((BtlCameraOrbitWork *)(camera + 0x100))->focus.z - frame.target[2];
        RwV3dNormalize((RwV3d *)(camera + 0x110),
                      (const RwV3d *)(camera + 0x110));
        ((BtlCameraOrbitWork *)(camera + 0x100))->refreshBounds = 0;
    }
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0D0, pitch, 0);
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0E0,
                     ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw, 2);
    func_003e4320((RwV3d *)frame.diff, (const RwV3d *)(camera + 0x110), (const RwMatrix *)frame.matrix);
    if (((BtlCamera *)(camera))->orbit.radius < 600.0f) {
        ((BtlCameraOrbitWork *)(camera + 0x100))->radius = 600.0f;
    }
    scale = (((BtlCameraOrbitWork *)(camera + 0x100))->radius * distanceFactor) /
            tanf(fGpffff8110 *
                          (0.5f * ((BtlCamera *)camera)->fovRad));
    frame.diff[0] *= scale;
    frame.diff[1] *= scale;
    frame.diff[2] *= scale;
    frame.result[0] = frame.diff[0] + ((BtlCameraOrbitWork *)(camera + 0x100))->focus.x;
    frame.result[1] = frame.diff[1] + ((BtlCameraOrbitWork *)(camera + 0x100))->focus.y;
    frame.result[2] = frame.diff[2] + ((BtlCameraOrbitWork *)(camera + 0x100))->focus.z;
    btlCameraLookAtQuat(frame.quat, frame.result, camera + 0x104,
                  D_0060A0E0);
    if (frame.result[1] < 25.0f) {
        frame.result[1] = 25.0f;
    }
    ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw += yawStep;
    if (((s32)((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) == 0) {
        btlCameraClampOffsetToLimit(frame.result, frame.result);
    }
    btlMainCurveReset((u16 *)(camera), (f32 *)(frame.result));
}

/* Initialize rotating framing and flag nonselected actions absent from the party action list. */
// FUN_001CEBA0
void btlCameraSetUnitFlags(u8 *camera)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    s32 index;
    s32 check;
    u16 index16;
    s32 count;
    u8 *current;

    ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yawBits = 0xC1900000;
    ((BtlCameraOrbitWork *)(camera + 0x100))->refreshBounds = 1;
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 0x100);
    if (((BtlCamera *)camera)->state == 7) {
        current = ((BtlBattleState *)iGpffffb3ac)->actions;
        while (current != NULL) {
            if ((s32)((BtlBattleState *)iGpffffb3ac)->selectedAction != (s32)current) {
                if ((((BtlAction *)current)->unk_1a & 1) != 0) {
                    if (((BtlUnit *)(MEMBER(u8 *, current, BtlAction, unit)))->genus != 1) {
                        index = 0;
                        count = ((BtlBattleState *)iGpffffb3ac)->partyActionCount;
                        goto loop_test;
loop_body:
                        index16 = (u16)index;
                        if (((BtlBattleState *)(iGpffffb3ac))->partyActions[index16] == current) {
                            goto search_done;
                        }
                        index = (index + 1) & 0xFFFF;
loop_test:
                        check = index & 0xFFFF;
                        if (check < count) {
                            goto loop_body;
                        }
search_done:
                        if (check == count) {
                            btlUnitSetFlags(MEMBER(u8 *, current, BtlAction, unit), 2,
                                          count, iGpffffb3ac, index);
                            ((BtlUnit *)((u8 *)((BtlAction *)current)->unit))->cols[1].alpha = 0;
                        }
                    }
                }
            }
            current = (u8 *)((BtlAction *)current)->next;
        }
    }
}

// FUN_001CECB0
void btlCameraFrameRotatedWideAlt(u8 *camera) {
    btlCameraFrameRotatedWide(camera, -16.0f, fGpffff8198, fGpffff80fc);
}

/* Frame actor and group bounds using whichever requires the larger camera distance. */
// FUN_001CECE0
void btlAct_ROUNDUP_MES(u8 *camera)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    struct Frame {
        u8 first[0x1C];
        f32 result[3];
        struct {
            u8 rotation[0x10];
            u8 pad10[8];
            RwV3d direction;
            u8 pad24[4];
        } second;
        f32 source[4];
        f32 target[4];
    } frame;
    f32 scale;
    f32 length;
    u8 *work;

    work = (u8 *)((BtlAction *)((u8 *)((BtlCamera *)camera)->action))->unit;
    btlCameraCopyPose(frame.first, camera + 0x9C);
    scale = btlUnitGetGroupBounds(3, 1, (RwV3d *)(frame.target), 0, 0, 1);
    frame.target[1] = 0.0f;
    btlUnitGetGridSphereCenter((BtlUnit *)(work), (RwV3d *)(frame.source));
    frame.source[1] +=
        (((BtlUnit *)work)->unk_8c * MEMBER(f32, work, BtlUnit, scale)) * 0.5f;
    btlCameraLookAtQuat(frame.second.rotation, frame.source, frame.target, D_0060A0E0);
    scale /= tanf(fGpffff8110 * (0.5f * MEMBER(f32, camera, BtlCamera, fovRad)));
    frame.second.direction.x = frame.source[0] - frame.target[0];
    frame.second.direction.y = frame.source[1] - frame.target[1];
    frame.second.direction.z = frame.source[2] - frame.target[2];
    length = RwV3dNormalize((RwV3d *)(&frame.second.direction),
                           (const RwV3d *)(&frame.second.direction));
    length += (((BtlUnit *)work)->sphereRadius * ((BtlUnit *)work)->scale * 5.0f) /
              tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    scale = (scale > length) ? scale : length;
    frame.second.direction.x *= scale;
    frame.second.direction.y *= scale;
    frame.second.direction.z *= scale;
    frame.result[0] = frame.second.direction.x + frame.target[0];
    frame.result[1] = frame.second.direction.y + frame.target[1];
    frame.result[2] = frame.second.direction.z + frame.target[2];
    if (((s32)((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) == 0)
        btlCameraClampOffsetToLimit(frame.result, frame.result);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)frame.first, frame.result, 1);
    btlCameraSetDuration(camera, 1.0f);
}

/* measured probe: optimization_level 1 preserves 001CEF20 low-bit OR coloring. */
/* measured: func_001cef20 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* Initialize random yaw and invalidate the rotating frame bounds cache. */
// FUN_001CEF20
void btlCameraFrameRandomHold(u8 *camera) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = datCalcRandomBelow(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw = value;
    ((BtlCameraOrbitWork *)(camera + 0x100))->refreshBounds = 1;
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 0x100);
}

/* measured: closes optimization_level 1 for 001CEF20. */
/* measured: func_001cf020, func_001cf070 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_001CEFB0
void btlCameraFrameRotatedFar(u8 *camera) {
    btlCameraFrameRotated(camera, -10.0f, 0.125f, fGpffff809c);
}

/* Restore unit base colors and request the camera-end crossfade. */
// FUN_001CEFF0
void btlCameraFrameEnd(void) {
    btlMainApplyUnitBaseColors(NULL);
    CrossfadeRequest(5);
}

/* Build the alternate endpoint and reset the camera curve to that pose. */
// FUN_001CF020
void btlCameraFrameBuildPair(u8 *camera) {
    P4CameraFrame frame;

    btlCameraBuildFramePair(camera, 0, 0, NULL, &frame);
    btlMainCurveReset((u16 *)(camera), (f32 *)(&frame));
}

/* Select a script by action mode, start it and request a crossfade. */
// FUN_001CF070
void btlCameraFrameSpawn(u8 *camera, u8 *defaultScript)
{
    /* The signed script selector at action+0x448 lies in the unrecovered mode-specific action tail. */

    s16 mode;
    u8 *target;

    mode = ((BtlAction *)((u8 *)((BtlCamera *)camera)->action))->cooperation.mode;
    target = defaultScript;
    switch (mode) {
    case 1:
        target = (u8 *)&D_005F78C0 + (effMiscRand(0) & 1) * 0xF4;
        break;
    case 0:
        target = (u8 *)&D_005F7AB0 + (effMiscRand(0) & 1) * 0xF4;
        break;
    }
    btlCameraStartEffect(camera, target, 2);
    CrossfadeRequest(5);
}

// FUN_001CF140
void btlCameraEffectListTickC(void) {
    btlCameraUpdateEffectList();
}

/* measured probe: optimization_level 1 preserves 001CF160 low-bit OR coloring. */
/* measured: func_001cf160 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* Initialize random yaw without invalidating cached group bounds. */
// FUN_001CF160
void btlCameraFrameRandomHoldAlt(u8 *camera) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = datCalcRandomBelow(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw = value;
    btlCameraSetupActionGeometry((u8 *)((BtlCamera *)camera)->action, NULL, NULL, 0.0f, 0x100);
}

/* measured: closes optimization_level 1 for 001CF160. */
/* measured: btlAct_ALL, btlAct_TARGET_ONLY, func_001cf1f0, func_001cf350, func_001cfad0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* Advance yaw by a quarter-degree while framing the selected actor at fixed distance. */
// FUN_001CF1F0
void btlCameraFrameMatrixOffset(u8 *camera)
{
    struct Frame {
        u8 pad20[0x40];
        f32 vec60[3];
        f32 value6C;
        u8 pad70[0x10];
        f32 vec80[4];
        f32 vec90[4];
    } frame;

    btlUnitGetSphereWorldCenter((u8 *)((BtlAction *)(((BtlBattleState *)iGpffffb3ac)->selectedAction))->unit,
                  &frame.vec90[0]);
    frame.vec90[1] = 0.0f;
    RwMatrixRotate((RwMatrix *)(u8 *)&frame, (const RwV3d *)D_0060A0D0, -30.0f, 0);
    RwMatrixRotate((RwMatrix *)(u8 *)&frame, (const RwV3d *)D_0060A0E0,
                  ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw, 2);
    func_003e4320((RwV3d *)(u8 *)&frame.vec80[0], (const RwV3d *)(&D_0060A0F0), (const RwMatrix *)(u8 *)&frame);
    frame.vec60[0] = func_001c_mul_add(frame.vec80[0],
                                        400.0f, frame.vec90[0]);
    frame.vec60[1] = func_001c_mul_add(frame.vec80[1],
                                        400.0f, frame.vec90[1]);
    frame.vec60[2] = func_001c_mul_add(frame.vec80[2],
                                        400.0f, frame.vec90[2]);
    btlCameraLookAtQuat(&frame.value6C, &frame.vec60[0],
                  &frame.vec90[0], D_0060A0E0);
    if (frame.vec60[1] < 25.0f) {
        frame.vec60[1] = 25.0f;
    }
    ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw = ((BtlCameraOrbitWork *)(camera + 0x100))->angle.yaw + 0.25f;
    btlCameraSetupActionGeometry(NULL, NULL, NULL, 0.0f, 4);
    btlMainCurveReset((u16 *)(camera), (f32 *)&frame.vec60[0]);
}

/* Build a clamped group shot with a 100-unit distance change over three seconds. */
// FUN_001CF350
void btlCameraFrameClampedRotate(u8 *camera)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    struct {
        f32 firstX;
        f32 firstY;
        f32 firstZ;
        f32 firstQuatX;
        f32 firstQuatY;
        f32 firstQuatZ;
        f32 firstQuatW;
        f32 secondX;
        f32 secondY;
        f32 secondZ;
        f32 secondQuatX;
        f32 secondQuatY;
        f32 secondQuatZ;
        f32 secondQuatW;
        u8 pad_to_80[8];
        u8 rotationMatrix[0x40];
        u8 pad_to_C8[8];
        f32 horizontalX;
        f32 horizontalZ;
        f32 groupX;
        f32 groupY;
        f32 groupZ;
        u8 pad_to_E0[4];
        f32 focusX;
        f32 focusY;
        f32 focusZ;
        u8 pad_to_F0[4];
        f32 directionX;
        f32 directionY;
        f32 directionZ;
        u8 pad_to_100[4];
        f32 scaledX;
        f32 scaledY;
        f32 scaledZ;
        u8 pad_to_110[4];
        f32 unitX;
        f32 unitY;
        f32 unitZ;
        u8 pad_tail[4];
    } frame;
    u8 *work;
    f32 extentOrOffset;
    f32 cameraDistance;
    f32 factorOrQuatX;
    f32 valueY;
    f32 valueZ;
    f32 valueW;
    extern f32 fGpffff80e8;
    extern u8 D_0060A100[];
    extern f32 func_003e41e0(f32 *camera, f32 *first);

    work = (u8 *)((BtlAction *)(((BtlBattleState *)iGpffffb3ac)->selectedAction))->unit;
    extentOrOffset = btlUnitGetGroupBounds(3, 1, (RwV3d *)((u8 *)&frame.groupX), 0, 0, 1);
    if (extentOrOffset < 550.0f) {
        extentOrOffset = 550.0f;
    }
    btlUnitGetGridSphereCenter((BtlUnit *)(work), (RwV3d *)(&frame.unitX));
    frame.scaledX = frame.unitX - frame.groupX;
    frame.scaledY = frame.unitY - frame.groupY;
    frame.scaledZ = frame.unitZ - frame.groupZ;
    factorOrQuatX = 0.25f * RwV3dNormalize((RwV3d *)&frame.scaledX, (const RwV3d *)&frame.scaledX);
    frame.directionX = frame.scaledX * factorOrQuatX;
    frame.directionY = frame.scaledY * factorOrQuatX;
    frame.directionZ = frame.scaledZ * factorOrQuatX;
    frame.focusX = frame.groupX + frame.directionX;
    frame.focusY = frame.groupY + frame.directionY;
    frame.focusZ = frame.groupZ + frame.directionZ;
    extentOrOffset = extentOrOffset * fGpffff80e8;
    cameraDistance = extentOrOffset / tanf(fGpffff8110 *
                                         (0.5f * MEMBER(f32, camera, BtlCamera, fovRad)));
    RwMatrixRotate((RwMatrix *)frame.rotationMatrix, (const RwV3d *)D_0060A0D0, 32.5f, 0);
    func_003e4320((RwV3d *)&frame.directionX, (const RwV3d *)D_0060A100, (const RwMatrix *)frame.rotationMatrix);
    RtQuatTransformVectors((RwV3d *)&frame.scaledX, (const RwV3d *)&frame.directionX, 1,
                  (const RtQuat *)(work + 0x1C));
    frame.unitX = frame.scaledX * extentOrOffset;
    frame.unitY = frame.scaledY * extentOrOffset;
    frame.unitZ = frame.scaledZ * extentOrOffset;
    frame.unitX = frame.unitX + frame.groupX;
    frame.unitY = frame.unitY + frame.groupY;
    frame.unitZ = frame.unitZ + frame.groupZ;
    btlCameraLookAtQuat(&frame.secondQuatX, &frame.unitX, &frame.focusX, D_0060A0E0);
    RtQuatTransformVectors((RwV3d *)&frame.directionX, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)&frame.secondQuatX);
    frame.scaledX = frame.directionX * cameraDistance;
    frame.scaledY = frame.directionY * cameraDistance;
    frame.scaledZ = frame.directionZ * cameraDistance;
    factorOrQuatX = cameraDistance * tanf(fGpffff8110 *
                                         (0.5f * ((BtlCamera *)camera)->fovRad));
    factorOrQuatX = factorOrQuatX * 0.21875f;
    extentOrOffset = factorOrQuatX * fGpffff80e8;
    frame.horizontalX = frame.scaledX;
    frame.horizontalZ = frame.scaledZ;
    func_003e41e0(&frame.horizontalX, &frame.horizontalX);
    frame.focusX = 0.0f + frame.focusX + frame.horizontalZ * extentOrOffset;
    frame.focusZ = 0.0f + frame.focusZ - frame.horizontalX * extentOrOffset;
    frame.secondX = frame.focusX + frame.scaledX;
    frame.secondY = frame.focusY + frame.scaledY;
    frame.secondZ = frame.focusZ + frame.scaledZ;
    factorOrQuatX = frame.secondQuatX;
    valueY = frame.secondQuatY;
    valueZ = frame.secondQuatZ;
    valueW = frame.secondQuatW;
    frame.firstQuatX = factorOrQuatX;
    frame.firstQuatY = valueY;
    frame.firstQuatZ = valueZ;
    frame.firstQuatW = valueW;
    factorOrQuatX = cameraDistance - 100.0f;
    valueY = frame.directionX * factorOrQuatX;
    frame.scaledX = valueY;
    valueZ = frame.directionY * factorOrQuatX;
    frame.scaledY = valueZ;
    valueW = frame.directionZ * factorOrQuatX;
    frame.scaledZ = valueW;
    frame.firstX = frame.focusX + valueY;
    frame.firstY = frame.focusY + valueZ;
    frame.firstZ = frame.focusZ + valueW;
    btlCameraSetupActionGeometry(NULL, NULL, NULL, 0.0f, 0x100);
    btlCameraClampOffsetToLimit(&frame.firstX, &frame.firstX);
    btlCameraClampOffsetToLimit(&frame.secondX, &frame.secondX);
    btlMainCurveSetPoses((u16 *)camera, &frame.firstX, &frame.secondX, 1);
    btlCameraSetDuration(camera, 3.0f);
}

/* Frame the enemy group with two offset poses and a three-and-a-half-second transition. */
// FUN_001CF730
void btlAct_ALL(u8 *camera)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    struct {
        f32 firstX;
        f32 firstY;
        f32 firstZ;
        f32 firstQuatX;
        f32 firstQuatY;
        f32 firstQuatZ;
        f32 firstQuatW;
        f32 secondX;
        f32 secondY;
        f32 secondZ;
        f32 secondQuatX;
        f32 secondQuatY;
        f32 secondQuatZ;
        f32 secondQuatW;
        u8 pad_to_80[8];
        u8 rotationMatrix[0x40];
        u8 pad_to_C8[8];
        f32 horizontalX;
        f32 horizontalZ;
        f32 groupX;
        f32 groupY;
        f32 groupZ;
        u8 pad_to_E0[4];
        f32 focusX;
        f32 focusY;
        f32 focusZ;
        u8 pad_to_F0[4];
        f32 directionX;
        f32 directionY;
        f32 directionZ;
        u8 pad_to_100[4];
        f32 scaledX;
        f32 scaledY;
        f32 scaledZ;
        u8 pad_to_110[4];
        f32 unitX;
        f32 unitY;
        f32 unitZ;
        u8 pad_tail[4];
    } frame;
    u8 *work;
    f32 extentOrOffset;
    f32 cameraDistance;
    f32 factorOrQuatX;
    f32 valueY;
    f32 valueZ;
    f32 valueW;
    extern f32 DAT_0076112c;
    extern f32 fGpffff80e8;
    extern u8 D_0060A100[];
    extern f32 func_003e41e0(f32 *camera, f32 *first);

    work = (u8 *)((BtlAction *)(((BtlBattleState *)iGpffffb3ac)->selectedAction))->unit;
    extentOrOffset = btlUnitGetGroupBounds(2, 1, (RwV3d *)((u8 *)&frame.groupX), 0, 0, 1);
    btlUnitGetGridSphereCenter((BtlUnit *)(work), (RwV3d *)(&frame.unitX));
    frame.scaledX = frame.unitX - frame.groupX;
    frame.scaledY = frame.unitY - frame.groupY;
    frame.scaledZ = frame.unitZ - frame.groupZ;
    factorOrQuatX = DAT_0076112c * RwV3dNormalize((RwV3d *)&frame.scaledX, (const RwV3d *)&frame.scaledX);
    frame.directionX = frame.scaledX * factorOrQuatX;
    frame.directionY = frame.scaledY * factorOrQuatX;
    frame.directionZ = frame.scaledZ * factorOrQuatX;
    frame.focusX = frame.groupX + frame.directionX;
    frame.focusY = frame.groupY + frame.directionY;
    frame.focusZ = frame.groupZ + frame.directionZ;
    if (extentOrOffset < 450.0f) {
        extentOrOffset = 450.0f;
    }
    cameraDistance = extentOrOffset / tanf(fGpffff8110 *
                                          (0.5f * MEMBER(f32, camera, BtlCamera, fovRad)));
    func_001c_rotate((RwMatrix *)frame.rotationMatrix, (const RwV3d *)D_0060A0D0, 35.0f, 0);
    func_003e4320((RwV3d *)&frame.directionX, (const RwV3d *)D_0060A100, (const RwMatrix *)frame.rotationMatrix);
    RtQuatTransformVectors((RwV3d *)&frame.scaledX, (const RwV3d *)&frame.directionX, 1,
                  (const RtQuat *)(work + 0x1C));
    frame.unitX = frame.scaledX * extentOrOffset;
    frame.unitY = frame.scaledY * extentOrOffset;
    frame.unitZ = frame.scaledZ * extentOrOffset;
    btlCameraLookAtQuat(&frame.secondQuatX, &frame.unitX, &frame.focusX, D_0060A0E0);
    RtQuatTransformVectors((RwV3d *)&frame.directionX, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)&frame.secondQuatX);
    factorOrQuatX = 50.0f + cameraDistance;
    frame.scaledX = frame.directionX * factorOrQuatX;
    frame.scaledY = frame.directionY * factorOrQuatX;
    frame.scaledZ = frame.directionZ * factorOrQuatX;
    extentOrOffset = cameraDistance * tanf(fGpffff8110 *
                                          (0.5f * ((BtlCamera *)camera)->fovRad));
    extentOrOffset = extentOrOffset * 0.21875f;
    extentOrOffset = extentOrOffset * fGpffff80e8;
    frame.horizontalX = frame.scaledX;
    frame.horizontalZ = frame.scaledZ;
    func_003e41e0(&frame.horizontalX, &frame.horizontalX);
    frame.focusX = 0.0f + frame.focusX + frame.horizontalZ * extentOrOffset;
    frame.focusZ = 0.0f + frame.focusZ - frame.horizontalX * extentOrOffset;
    frame.secondX = frame.focusX + frame.scaledX;
    frame.secondY = frame.focusY + frame.scaledY;
    frame.secondZ = frame.focusZ + frame.scaledZ;
    factorOrQuatX = frame.secondQuatX;
    valueY = frame.secondQuatY;
    valueZ = frame.secondQuatZ;
    valueW = frame.secondQuatW;
    frame.firstQuatX = factorOrQuatX;
    frame.firstQuatY = valueY;
    frame.firstQuatZ = valueZ;
    frame.firstQuatW = valueW;
    factorOrQuatX = cameraDistance - 50.0f;
    valueY = frame.directionX * factorOrQuatX;
    frame.scaledX = valueY;
    valueZ = frame.directionY * factorOrQuatX;
    frame.scaledY = valueZ;
    valueW = frame.directionZ * factorOrQuatX;
    frame.scaledZ = valueW;
    frame.firstX = frame.focusX + valueY;
    frame.firstY = frame.focusY + valueZ;
    frame.firstZ = frame.focusZ + valueW;
    btlCameraSetupActionGeometry(NULL, NULL, NULL, 0.0f, 0x100);
    btlMainCurveSetPoses((u16 *)camera, &frame.firstX, &frame.secondX, 1);
    btlCameraSetDuration(camera, 3.5f);
}

/* Build two rolled actor views, adjusting focus for the status flag. */
// FUN_001CFAD0
void btlCameraFrameStatusRoll(u8 *camera, f32 firstFactor, f32 secondFactor)
{
    /* measured: direct fields, typed pointer locals and array forms change MWCC bytes at MEMBER sites; see FullBattle4.culprits.tsv. */

    struct {
        f32 first[7];
        f32 second[7];
        RwMatrix rotation __attribute__((aligned(16)));
        f32 center[4];
        f32 direction[4];
        f32 scaled[4];
    } work;
    u8 *unit;
    u32 status;
    s32 choice;
    f32 extent;
    f32 firstScale;
    f32 y;
    extern f32 fGpffff810c;

    unit = (u8 *)((BtlAction *)((u8 *)((BtlCamera *)camera)->action))->unit;
    status = datCalcChkBadStatus((s32)((BtlUnit *)unit)->datUnit, 0x100000);
    btlUnitGetAnimBoundsWorldCenter((BtlUnit *)unit, (RwV3d *)work.center);
    if (status == 0) {
        work.center[1] = 0.0f + work.center[1] + fGpffff810c *
                         (((BtlUnit *)unit)->unk_8c * MEMBER(f32, unit, BtlUnit, scale));
    } else {
        work.center[1] = 0.0f + work.center[1] - fGpffff810c *
                         (((BtlUnit *)unit)->unk_8c * ((BtlUnit *)unit)->scale);
    }
    RtQuatTransformVectors((RwV3d *)work.direction, (const RwV3d *)(&D_0060A0F0), 1,
                  (const RtQuat *)(unit + 0x1C));
    work.scaled[0] = 200.0f * work.direction[0];
    work.scaled[1] = 200.0f * work.direction[1];
    work.scaled[2] = 200.0f * work.direction[2];
    y = work.center[1] + work.scaled[1];
    y = y + 55.0f;
    work.direction[0] = (work.center[0] + work.scaled[0]) - work.center[0];
    work.direction[1] = y - work.center[1];
    work.direction[2] = (work.center[2] + work.scaled[2]) - work.center[2];
    RwV3dNormalize((RwV3d *)work.direction, (const RwV3d *)work.direction);
    extent = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale;
    if (extent < 75.0f) {
        extent = 75.0f;
    }
    firstScale = extent * firstFactor;
    firstFactor = extent * secondFactor;
    choice = (s32)datCalcRandomBelow(2);
    switch (choice) {
    case 0:
        secondFactor = 30.0f;
        break;
    case 1:
    default:
        secondFactor = -30.0f;
        break;
    }
    func_001c_rotate(&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * -secondFactor, 0);
    func_003e4320((RwV3d *)work.scaled, (const RwV3d *)work.direction,
                  &work.rotation);
    firstScale = firstScale /
        tanf(fGpffff8110 * (0.5f * MEMBER(f32, camera, BtlCamera, fovRad)));
    work.scaled[0] = work.scaled[0] * firstScale;
    work.scaled[1] = work.scaled[1] * firstScale;
    work.scaled[2] = work.scaled[2] * firstScale;
    work.first[0] = work.center[0] + work.scaled[0];
    work.first[1] = work.center[1] + work.scaled[1];
    work.first[2] = work.center[2] + work.scaled[2];
    btlCameraLookAtQuat(&work.first[3], work.first, work.center, D_0060A0E0);
    func_001c_rotate(&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * secondFactor, 0);
    func_003e4320((RwV3d *)work.scaled, (const RwV3d *)work.direction,
                  &work.rotation);
    firstFactor = firstFactor /
        tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    work.scaled[0] = work.scaled[0] * firstFactor;
    work.scaled[1] = work.scaled[1] * firstFactor;
    work.scaled[2] = work.scaled[2] * firstFactor;
    work.second[0] = work.center[0] + work.scaled[0];
    work.second[1] = work.center[1] + work.scaled[1];
    work.second[2] = work.center[2] + work.scaled[2];
    btlCameraLookAtQuat(&work.second[3], work.second, work.center, D_0060A0E0);
    if (work.first[1] < 25.0f) {
        work.first[1] = 25.0f;
    }
    if (work.second[1] < 25.0f) {
        work.second[1] = 25.0f;
    }
    btlMainApplyUnitBaseColors(unit);
    btlMainCurveSetPoses((u16 *)camera, work.first, work.second, 1);
    btlCameraSetDuration(camera, 3.0f);
}

// FUN_001CFED0
void btlAct_ENEMY_ALL(u8 *camera) {
    btlCameraFrameStatusRoll(camera, fGpffff8114, 2.5f);
}

/* Frame only the actor with minimum distance and a height floor from unit bounds. */
// FUN_001CFF00
void btlAct_TARGET_ONLY(u8 *camera)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Vec3 target;
    struct Vec3 source;
    struct {
        f32 first[10];
        struct {
            u8 rotation[0x10];
            u8 pad10[8];
            RwV3d direction;
            u8 pad24[4];
        } second;
    } fr;
    f32 speed;
    f32 half_speed;
    f32 scale;
    f32 length;
    f32 x;
    f32 y;
    f32 limit;
    u8 *work;

    btlCameraCopyPose(fr.first, camera + 0x9C);
    work = (u8 *)((BtlAction *)((u8 *)((BtlCamera *)camera)->action))->unit;
    btlUnitGetSphereWorldCenter(work, (f32 *)&target);
    target.y = ((BtlUnit *)work)->sphereCenter.y * ((BtlUnit *)work)->scale;
    speed = ((BtlUnit *)work)->sphereRadius * ((BtlUnit *)work)->scale;
    half_speed = (((BtlUnit *)work)->unk_8c * ((BtlUnit *)work)->scale) * 0.5f;
    source = target;
    source.y += half_speed * 0.25f;
    if (speed > half_speed) {
        scale = (3.0f * speed) /
                tanf(fGpffff8110 *
                              (0.5f * ((BtlCamera *)camera)->fovRad));
    } else {
        scale = (3.0f * half_speed) /
                tanf(0.5f * ((BtlCamera *)camera)->fovRad);
    }
    fr.second.direction.x =
        fr.first[0] - source.x;
    fr.second.direction.y =
        fr.first[1] - source.y;
    fr.second.direction.z =
        fr.first[2] - source.z;
    length = RwV3dLength((f32 *)(&fr.second.direction));
    length *= fGpffff811c;
    fr.second.direction.x =
        fr.first[0] - source.x;
    fr.second.direction.y =
        fr.first[1] - source.y;
    fr.second.direction.z =
        fr.first[2] - source.z;
    RwV3dNormalize((RwV3d *)(&fr.second.direction),
                  (const RwV3d *)(&fr.second.direction));
    x = fr.second.direction.x *
        ((scale > length) ? scale : length);
    y = fr.second.direction.y *
        ((scale > length) ? scale : length);
    scale = (scale > length) ? scale : length;
    fr.first[7] = source.x + x;
    fr.first[8] = source.y + y;
    fr.first[9] = source.z +
                      fr.second.direction.z * scale;
    limit = target.y + half_speed * 1.25f;
    if (fr.first[8] < limit) {
        fr.first[8] = limit;
    }
    btlCameraLookAtQuat(fr.second.rotation, &fr.first[7], &source, D_0060A0E0);
    btlMainCurveSetPoses((u16 *)camera, fr.first, &fr.first[7], 1);
    btlCameraSetDuration(camera, 4.5f);
}

