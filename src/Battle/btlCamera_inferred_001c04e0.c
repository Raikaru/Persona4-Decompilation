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

extern void btlMainCurveReset(u16 *arg0, f32 *arg1);
extern u32 btlCameraBuildFramePair(u8 *camera, s32 resultCode, s32 useAlternate,
                          P4CameraFrame *firstOut, P4CameraFrame *secondOut);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 RwV3dNormalize(RwV3d *arg0, const RwV3d *arg1);
extern f32 tanf(f32 arg0);
extern f32 fGpffff80fc;
extern f32 fGpffff8114;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern f32 fGpffff811c;
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg3, u16 arg4);
extern void btlCameraBuildPosePair(u8 *camera, P4CameraFrame *first, P4CameraFrame *second);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
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
extern RwV3d *RtQuatTransformVectors(RwV3d *arg0, const RwV3d *arg1, s32 arg2, const RtQuat *arg3);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001c.c; members 001c04e0-001c09a0 */

// FUN_001C04E0
void btlCameraFrameActionSide(u8 *camera)
{
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
    unit = *(u8 **)(action + 0x30);
    unit2 = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &center1);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit2, &center2);
    radius1 = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    radius2 = *(f32 *)(unit2 + 0x90) * *(f32 *)(unit2 + 0x2C);
    direction.x = center1.x - center2.x;
    direction.y = center1.y - center2.y;
    direction.z = center1.z - center2.z;
    length = RwV3dNormalize(&direction, &direction);
    horizontal[2] = *(f32 *)(camera + 0x9C) - center1.x;
    horizontal[3] = *(f32 *)(camera + 0xA4) - center1.z;
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
        radius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
        offset = 2.5f * radius;
        radiusFactor = 2.25f;
        if (eyeBase.y < 125.0f) eyeBase.y = 125.0f;
    } else {
        unit = unit2;
        eyeBase = center2;
        radius = *(f32 *)(unit2 + 0x90) * *(f32 *)(unit2 + 0x2C);
        offset = 2.5f * radius;
        radiusFactor = 2.25f;
    }
    horizontal[0] = direction.z;
    horizontal[1] = -direction.x;
    eyeY = eyeBase.y;
    position.y = 0.0f + eyeY + fGpffff8030 * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
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
    distance = 0.0f + result + radiusFactor * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    position.x = output[0];
    position.y = eyeY;
    position.z = output[1];
    projection = distance / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), (u8 *)&center1, (f32 *)&center2, radius1, 3);
}

// FUN_001C09A0
void func_001c09a0(void) {}

