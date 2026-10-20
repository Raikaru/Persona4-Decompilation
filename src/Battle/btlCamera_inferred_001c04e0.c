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

extern void btlMainCurveReset(u16 *curve, f32 *pose);
extern u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                          P4CameraFrame *firstOut, P4CameraFrame *secondOut);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 RwV3dNormalize(RwV3d *first, const RwV3d *second);
extern f32 tanf(f32 first);
extern f32 fGpffff80fc;
extern f32 fGpffff8114;
extern u8 *iGpffffb3ac; /* battle-state allocation */
extern u8 *iGpffffb3e0;
extern f32 fGpffff811c;
extern void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode);
extern void btlCameraBuildPosePair(u8 *camera, P4CameraFrame *first, P4CameraFrame *second);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001c.c; members 001c04e0-001c09a0 */

/* Place side-view endpoints around actor and target, with floor and minimum-distance clamps. */
// FUN_001C04E0
void btlCameraFrameActionSide(u8 *camera)
{
    /* Action+0x38 is variant target/AI-command storage; keep its opaque pointer/word interpretation. */
    /* measured: each remaining raw field spelling was tested separately; struct access changed MWCC instruction bytes. */

    extern void btlUnitGetSphereWorldCenter(BtlUnit *, RwV3d *);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern f32 btlTargetAngleBetween(u8 *, u8 *, u8 *, u8 *);
    extern f32 tanf(f32);
    extern void btlCameraCopyPoseSnapshot(f32 *, f32 *);
    extern void btlMainCurveReset(u16 *, f32 *);
    extern void btlCameraSetupActionGeometry(u8 *, u8 *, f32 *, f32, u16);
    extern f32 fGpffff8030;
    RwV3d center1;
    RwV3d center2;
    RwV3d eyeBase;
    RwV3d sideDir;
    RwV3d direction;
    RwV3d position;
    f32 eyePoint[2];
    f32 output[2];
    f32 rayTo[2];
    f32 rayFrom[2];
    f32 horizontal[4];
    P4CameraFrame frame;
    P4CameraFrame adjusted;
    u8 *action;
    u8 *unit;
    u8 *unit2;
    f32 length;
    f32 radiusFactor;
    f32 radius1;
    f32 radius2;
    f32 eyeZ;
    f32 eyeY;
    f32 weight;
    f32 dot;
    f32 dot2;
    f32 offset;
    f32 radius;
    f32 result;
    f32 distance;
    f32 projection;

    action = *(u8 **)(camera + 0xE0);
    unit = (u8*)((BtlAction *)action)->unit;
    unit2 = (u8*)((BtlAction *)*(u8 **)(action + 0x38))->unit;
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &center1);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit2, &center2);
    radius1 = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    radius2 = *(f32 *)(unit2 + 0x90) * *(f32 *)(unit2 + 0x2C);
    direction.x = center1.x - center2.x;
    direction.y = center1.y - center2.y;
    direction.z = center1.z - center2.z;
    length = RwV3dNormalize(&direction, &direction);
    horizontal[2] = ((BtlCamera *)camera)->pose.pos.x - center1.x;
    horizontal[3] = ((BtlCamera *)camera)->pose.pos.z - center1.z;
    func_003e41e0(horizontal + 2, horizontal + 2);
    weight = fGpffff80fc * length;
    sideDir.x = direction.x * weight;
    sideDir.y = direction.y * weight;
    sideDir.z = direction.z * weight;
    sideDir.x += center2.x;
    sideDir.y += center2.y;
    sideDir.z += center2.z;
    horizontal[0] = direction.x;
    horizontal[1] = direction.z;
    dot = direction.x * horizontal[2] + direction.z * horizontal[3];
    if (!(dot < 0.0f)) {
        eyeBase = center1;
        radius = ((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale;
        offset = 2.5f * radius;
        radiusFactor = 2.25f;
        if (eyeBase.y < 125.0f) eyeBase.y = 125.0f;
    } else {
        unit = unit2;
        eyeBase = center2;
        radius = ((BtlUnit *)unit2)->sphereRadius * ((BtlUnit *)unit2)->scale;
        offset = 2.5f * radius;
        radiusFactor = 2.25f;
    }
    horizontal[0] = direction.z;
    horizontal[1] = -direction.x;
    eyeY = eyeBase.y;
    position.y = 0.0f + eyeY + fGpffff8030 * (((BtlUnit *)unit)->unk_8c * *(f32 *)(unit + 0x2C));
    dot2 = horizontal[0] * horizontal[2] + horizontal[1] * horizontal[3];
    if (!(dot2 < 0.0f)) {
        position.x = 0.0f + eyeBase.x + horizontal[0] * offset;
        eyeZ = eyeBase.z;
        position.z = 0.0f + eyeZ - direction.x * offset;
    } else {
        position.x = 0.0f + eyeBase.x - horizontal[0] * offset;
        eyeZ = eyeBase.z;
        position.z = 0.0f + eyeZ + direction.x * offset;
    }
    btlCameraLookAtQuat(&frame.rot, &position, &sideDir, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.rot);
    rayFrom[0] = sideDir.x;
    rayFrom[1] = sideDir.z;
    rayTo[0] = position.x;
    rayTo[1] = position.z;
    eyePoint[0] = eyeBase.x;
    eyePoint[1] = eyeZ;
    result = btlTargetAngleBetween((u8 *)rayFrom, (u8 *)rayTo, (u8 *)eyePoint, (u8 *)output);
    distance = 0.0f + result + radiusFactor * (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale);
    position.x = output[0];
    position.y = eyeY;
    position.z = output[1];
    projection = distance / tanf(fGpffff8110 * (0.5f * ((BtlCamera *)camera)->fovRad));
    if (projection < 500.0f) projection = 500.0f;
    direction.x *= projection;
    direction.y *= projection;
    direction.z *= projection;
    frame.pos.x = position.x + direction.x;
    frame.pos.y = position.y + direction.y;
    frame.pos.z = position.z + direction.z;
    if (frame.pos.y < 25.0f) frame.pos.y = 25.0f;
    btlCameraCopyPoseSnapshot((f32 *)(camera + 0x9C), (f32 *)&frame);
    btlCameraBuildPosePair(camera, &frame, &adjusted);
    btlMainCurveReset((u16 *)camera, (f32 *)&adjusted);
    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), camera + 0x9C, (f32 *)(camera + 0x100), 0.5f * (radius2 + (length + radius1)),
                  3);
    radius1 = cameraSideRadius(radius1, radius2);
    btlCameraSetupActionGeometry((u8*)((BtlCamera *)camera)->action, (u8 *)&center1, (f32 *)&center2, radius1, 3);
}

/* Empty update callback for MOVE_TARGET_A (state 23) in the retail camera table at 0x005F74C0. */
// FUN_001C09A0
void btlCameraMoveTargetSideUpdate(void) {}

