#include "include_asm.h"
#include "type.h"

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

extern void func_001bdeb0();
extern void func_001c9820(u8 *camera, f32 angleLimit, s32 reverse, s32 preserveSide);
extern void func_001ce620(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_001ce8c0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void func_001b73f0(u8 *arg0);
extern void func_004b3110(s32 arg0);
extern void func_001bab00(u16 *arg0, f32 *arg1);
extern u32 func_001c6f40(u8 *camera, s32 resultCode, s32 useAlternate,
                          P4CameraFrame *firstOut, P4CameraFrame *secondOut);
extern void func_001cfad0(u8 *arg0, f32 arg1, f32 arg2);
extern f32 fGpffff809c;
extern f32 fGpffff8198;
extern f32 fGpffff8110;
extern f32 DAT_00761278;
extern f32 fGpffff8100;
extern f32 func_003e40b0(RwV3d *arg0, const RwV3d *arg1);
extern f32 func_003e4180(f32 *arg0);
extern void func_001bd560();
extern void func_001958f0(BtlUnit *unit, RwV3d *out);
extern void func_001959d0(BtlUnit *arg0, RwV3d *arg1);
extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
extern RwMatrix *func_003e0870(RwMatrix *arg0, const RwV3d *arg1, f32 arg2, s32 arg3);
extern RwV3d *func_003e4320(RwV3d *arg0, const RwV3d *arg1, const RwMatrix *arg2);
extern u32 func_001bc3a0(f32 *arg0, f32 *arg1);
extern f32 tanf(f32 arg0);
extern f32 fGpffff80fc;
extern f32 fGpffff8114;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern f32 fGpffff811c;
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg3, u16 arg4);
extern void func_001ca590(u8 *arg0, f32 arg1, f32 arg2);
extern void func_001cacd0(u8 *arg0, f32 arg1, f32 arg2);
extern void func_0019de70(BtlUnitStateWork *work, u16 value);
extern s32 func_001bc560(u8 *arg0, u8 *arg1);
extern s16 func_001d7f10(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_001d8df0(u8 *arg0);
extern u32 func_001d8bc0(void *formation);
extern void func_001c79f0(u8 *arg0, s32 arg1);
extern void func_001c80f0(u8 *arg0, s32 arg1);
extern void func_001c8b00(u8 *arg0);
extern void func_001bd4f0(u8 *arg0);
extern void func_001bd530(u8 *arg0);
extern u8 *func_00457120(void);
extern void func_001c8e90(u8 *camera, P4CameraFrame *first, P4CameraFrame *second);
extern void func_001bac20(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
extern void func_001bbef0(u8 *arg0, f32 arg1);
extern void func_001bdd80(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 func_004bd050(s32 arg0);
extern s16 func_001991c0(u8 *arg0, s32 arg1, f32 arg2);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern s32 func_001f0ff0(u8 *arg0);
extern void func_001c2ee0(u8 *arg0, s32 arg1, s32 arg2);
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern u32 func_00231d70(u32 arg0);
extern s32 func_001bc140(u8 *arg0);
extern s32 func_001eb440(u8 *arg0);
extern s32 func_001f1030(u8 *arg0);
extern s32 func_001f11e0(s16 arg0);
extern s32 func_001f1210(s32 arg0, s16 arg1, s32 arg2);
extern u32 func_00232710(s32 arg0, u32 arg1);
extern s32 func_0022f950(u8 *arg0, u8 *arg1);
extern void func_00194fa0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
extern void func_00195850(u8 *arg0, f32 *arg1);
extern RwMatrix *func_003e0870(RwMatrix *arg0, const RwV3d *arg1, f32 arg2, s32 arg3);
extern RwV3d *func_003e4320(RwV3d *arg0, const RwV3d *arg1, const RwMatrix *arg2);
extern void func_001bd780(void *arg0, const void *arg1, const void *arg2, const void *arg3);
extern u8 D_0060A0D0[];
extern u8 D_0060A0E0[];
extern RwV3d D_0060A0F0;
extern u8 D_0060A100[];
extern s32 func_001ec4a0(f32 *arg0, f32 *arg1);
extern f32 func_001ec250(f32 *arg0, u8 *arg1);
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
extern u8 *func_001d0730(s32 arg0, s32 arg1);
extern RwV3d *func_003dcb40(RwV3d *arg0, const RwV3d *arg1, s32 arg2, const RtQuat *arg3);
extern void func_001c1040(u8 *arg0, s32 arg1);
extern void func_001c17a0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001c21d0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_001c3f70(u8 *arg0, s32 arg1, s32 arg2);
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
    func_003e0870(arg0, arg1, arg2, arg3);
}

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

/* P3 btlCameraFrameActionSide (002a6ee0, donor NONMATCHING), adapted to P4; b210 -O2: 1208 bytes plus 8 retail zero bytes. */

static inline f32 cameraSideRadius(f32 first, f32 second)
{
    if (first > second) return first;
    return second;
}
// FUN_001C04E0
void func_001c04e0(u8 *camera)
{
    extern void btlUnitGetSphereWorldCenter(BtlUnit *, RwV3d *);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern f32 func_003e41e0(f32 *, f32 *);
    extern f32 func_001ec3d0(u8 *, u8 *, u8 *, u8 *);
    extern f32 func_0044b868(f32);
    extern void func_001bd5a0(f32 *, f32 *);
    extern void func_001bab00(u16 *, f32 *);
    extern void func_001bcd40(u8 *, u8 *, f32 *, f32, u16);
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
    func_001bd780(&frame.rot, &position, &sideDir, D_0060A0E0);
    func_003dcb40(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frame.rot);
    rayFrom[0] = sideDir.x;
    rayFrom[1] = sideDir.z;
    rayTo[0] = position.x;
    rayTo[1] = position.z;
    eyePoint[0] = eyeBase.x;
    eyePoint[1] = eyeZ;
    result = func_001ec3d0((u8 *)rayFrom, (u8 *)rayTo, (u8 *)eyePoint, (u8 *)output);
    distance = 0.0f + result + radiusFactor * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C));
    position.x = output[0];
    position.y = eyeY;
    position.z = output[1];
    projection = distance / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    if (projection < 500.0f) projection = 500.0f;
    direction.x *= projection;
    direction.y *= projection;
    direction.z *= projection;
    frame.pos.x = position.x + direction.x;
    frame.pos.y = position.y + direction.y;
    frame.pos.z = position.z + direction.z;
    if (frame.pos.y < 25.0f) frame.pos.y = 25.0f;
    func_001bd5a0((f32 *)(camera + 0x9C), (f32 *)&frame);
    func_001c8e90(camera, &frame, &adjusted);
    func_001bab00((u16 *)camera, (f32 *)&adjusted);
    func_001bcd40(*(u8 **)(camera + 0xE0), camera + 0x9C, (f32 *)(camera + 0x100), 0.5f * (radius2 + (length + radius1)),
                  3);
    radius1 = cameraSideRadius(radius1, radius2);
    func_001bcd40(*(u8 **)(camera + 0xE0), (u8 *)&center1, (f32 *)&center2, radius1, 3);
}
// FUN_001C09A0
void func_001c09a0(void) {}
/* Ported from current P3FES src/Battle/btlCamera.c btlCameraFrameActionTarget
 * (0x002a7390, donor 04d95e2). Historical donor verification is
 * recorded in the recovery note; no fresh P3 retail run is claimed.
 * Complete pose and quaternion objects retain the retail copy boundaries.
 * measured: 1156/1168 bytes; all executable bytes and relocations exact. */
// FUN_001C09B0
void func_001c09b0(u8* camera)
{
    extern void func_001bd560(f32*, f32*);
    extern void func_00194ff0(u8*, u8*, f32*, f32*);
    extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0* first, P4Vec4Holder_001EC2B0* second);
    extern void func_003dcc70(f32*, f32*, void*);
    extern f32 func_0044b868(f32);
    extern f32 func_003e41e0(f32*, f32*);
    extern f32 fGpffff8118, fGpffff815c, fGpffff804c, fGpffff8160, fGpffff8110, fGpffff818c;
    extern f32 fGpffff8180;
    extern f32 fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060, fGpffff8108;
    extern RtQuat* func_003dc740(RtQuat*, const RwV3d*, f32, s32);
    f32 horiz[2];
    RwV3d eyeAdj;
    RwV3d center;
    P4Vec4Holder_001EC2B0 blended;
    P4CameraBlend blend;
    P4CameraFrame frames[2];
    u8* unit;
    f32 height;
    f32 angle;
    f32 ratio;
    f32 w1;
    f32 x;
    f32 x2;
    f32 r;
    f32 r2;
    f32 dist;
    f32 sideOffset;

    unit = *(u8**)(*(u8**)(camera + 0xe0) + 0x30);
    func_001bd560((f32*)&frames[0], (f32*)(camera + 0x9c));
    func_00194ff0(unit, (u8*)&center, NULL, NULL);
    height = *(f32*)(unit + 0x84) * *(f32*)(unit + 0x2c);
    height += fGpffff8118 * (*(f32*)(unit + 0x8c) * *(f32*)(unit + 0x2c));
    center.y = height;
    eyeAdj = frames[0].pos;
    eyeAdj.y = height;
    func_001bd780(&frames[1].rot, &eyeAdj, &center, D_0060A0E0);
    angle = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    if (angle > fGpffff815c)
    {
        ratio = fGpffff815c / angle;
        func_003dcc70((f32*)&frames[0].rot, (f32*)&frames[1].rot, &blend);
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
        func_003dcb40(&eyeAdj, (const RwV3d*)D_0060A100, 1, (const RtQuat*)&blended);
        eyeAdj.x = eyeAdj.x + center.x;
        eyeAdj.y = eyeAdj.y + center.y;
        eyeAdj.z = eyeAdj.z + center.z;
        func_001bd780(&frames[1].rot, &eyeAdj, &center, D_0060A0E0);
    }
    else if (angle < fGpffff804c)
    {
        func_003dc740((RtQuat*)&frames[1].rot, (const RwV3d*)D_0060A0E0, fGpffff8160, 2);
    }
    func_003dcb40(&eyeAdj, (const RwV3d*)D_0060A100, 1, (const RtQuat*)&frames[1].rot);
    dist = 375 / func_0044b868(fGpffff8110 * (0.5f * *(f32*)(camera + 0xb8)));
    eyeAdj.x = eyeAdj.x * dist;
    eyeAdj.y = eyeAdj.y * dist;
    eyeAdj.z = eyeAdj.z * dist;
    sideOffset = dist * func_0044b868(fGpffff8110 * (0.5f * *(f32*)(camera + 0xb8)));
    sideOffset = sideOffset * 0.21875f;
    horiz[0] = eyeAdj.x;
    horiz[1] = eyeAdj.z;
    func_003e41e0(horiz, horiz);
    center.x = 0.0f + center.x + horiz[1] * sideOffset;
    center.z = 0.0f + center.z - horiz[0] * sideOffset;
    frames[1].pos.x = center.x + eyeAdj.x;
    frames[1].pos.y = center.y + eyeAdj.y;
    frames[1].pos.z = center.z + eyeAdj.z;
    if (frames[1].pos.y < 25.0f)
    {
        frames[1].pos.y = 25.0f;
    }
    func_001bac20((u16*)camera, (f32*)&frames[0], (f32*)&frames[1], 1);
    func_001bbef0(camera, fGpffff818c);
}

// FUN_001C0E40
void func_001c0e40(void) {}
// FUN_001C0E50
s32 func_001c0e50(u8 *arg0) {
    s16 mode;
    s32 state;
    s32 check;
    s32 result;
    u8 *work;
    u8 *data;
    u8 *other;

    work = *(u8 **)(arg0 + 0xE0);
    mode = *(s16 *)(work + 0x6E);
    if (func_001f0ff0(work) != 0) {
        data = *(u8 **)(arg0 + 0xE0);
        if (*(s32 *)(data + 0x38) == (s32)data) {
            return 1;
        }
        if (func_001bc140(arg0) != 0) {
            return 2;
        }
        if (func_001f11e0(mode) == 0) {
            return 2;
        }
        other = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
        if ((*(u8 *)(other + 0xA2) == 0) &&
            (func_001f1210(*(s32 *)(other + 0xA0C), mode, 1) == 0)) {
            return 2;
        }
        return 4;
    }
    state = func_001eb440(*(u8 **)(arg0 + 0xE0) + 0x38) & 0xFFFF;
    if (((state & 3) == 3) ||
        (((check = *(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA64),
           check != 0) &&
          (func_00232710(check, 0x100) != 0)))) {
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
void func_001c1040(u8 *camera, s32 unused)
{
    extern s32 func_001bc240(s32 cameraAddress);
    extern s32 func_001bc1b0(u8 *camera);
    extern void func_001bd560(f32 *out, f32 *in);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 fGpffff8128;
    extern f32 fGpffff807c;
    extern f32 func_0044b868(f32 camera);
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
    func_001bd560((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
    groupRadius = func_00196040(3, 1, &groupCenter, &top, 0, 0);
    if (func_001bc240((s32)camera) != 0 || func_001bc1b0(camera) != 0) {
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
        cameraDistance = groupRadius / func_0044b868(angleToRadians * (halfFov * *(f32 *)(camera + 0xB8)));
        if (cameraDistance < 1000.0f) cameraDistance = 1000.0f;
        if (groupCenter.x == unitCenter.x && groupCenter.z == unitCenter.z) {
            direction = D_0060A0F0;
        } else {
            direction.x = groupCenter.x - unitCenter.x;
            direction.y = groupCenter.y - unitCenter.y;
            direction.z = groupCenter.z - unitCenter.z;
            func_003e40b0(&direction, &direction);
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
        cameraDistance = groupRadius / func_0044b868(angleToRadians * (halfFov * *(f32 *)(camera + 0xB8)));
        if (cameraDistance < 1200.0f) cameraDistance = 1200.0f;
        if (groupCenter.x == unitCenter.x && groupCenter.z == unitCenter.z) {
            direction = D_0060A0F0;
        } else {
            direction.x = groupCenter.x - unitCenter.x;
            direction.y = groupCenter.y - unitCenter.y;
            direction.z = groupCenter.z - unitCenter.z;
            func_003e40b0(&direction, &direction);
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
        scale = fGpffff8128 * func_003e40b0(&delta, &delta);
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
    scale = fGpffff8128 * func_003e40b0(&delta, &delta);
    x = delta.x * scale;
    focus.x = x;
    y = delta.y * scale;
    focus.y = y;
    z = delta.z * scale;
    focus.z = z;
    focus.x = x + groupCenter.x;
    focus.y = y + groupCenter.y;
    focus.z = z + groupCenter.z;
    func_001bd780(&frames[1].rot, &eye, &focus, D_0060A0E0);
    direction.x = eye.x - focus.x;
    direction.y = eye.y - focus.y;
    direction.z = eye.z - focus.z;
    func_003e40b0(&direction, &direction);
    lateralOffset = cameraDistance * func_0044b868(angleToRadians * (halfFov * *(f32 *)(camera + 0xB8)));
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
    if (func_004bd050(0) & 1) {
        func_003e0870(&matrix, (const RwV3d *)D_0060A0E0, -30.0f, 0);
    } else {
        func_003e0870(&matrix, (const RwV3d *)D_0060A0E0, 30.0f, 0);
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
    func_001bd780(&frames[0].rot, (f32 *)&frames[0], &focus, D_0060A0E0);
    func_004b3110(8);
    func_001bc3a0((f32 *)&frames[0], (f32 *)&frames[0]);
    func_001bc3a0((f32 *)&frames[1], (f32 *)&frames[1]);
    if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
    if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
    func_001bac20((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    func_001bbef0(camera, 10.0f);
}
/* Build the two animation or orbit camera poses around the acting unit.
 * Vector snapshots, horizontal directions and pose frames are complete objects. */
// FUN_001C17A0
void func_001c17a0(u8 *camera, s32 notify, s32 unused)
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
    extern s32 func_001bc330(u8 *camera);
    extern f32 func_003e41e0(f32 *camera, f32 *notify);
    extern f32 func_0044b868(f32 camera);
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
    useOrbit = func_001bc330(camera) != 0;
    work = *(u8 **)(camera + 0xE0);
    if ((*(u16 *)(work + 0x1A) & 0x10) == 0) {
        return;
    }
    unit = *(u8 **)(work + 0x30);
    target = *(u8 **)(unit + 0xA0C);
    if (useOrbit == 0) {
        animation = (u16 *)func_001d0730(*(u16 *)(target + 0xA4), 1);
        if ((*(u16 *)(iGpffffb3e0 + *(u16 *)(target + 0xA4) * 0x58) & 1) == 0) {
            func_0019de70((BtlUnitStateWork *)target, 0);
        } else {
            func_0019de70((BtlUnitStateWork *)target, 1);
        }
        func_003dcb40((RwV3d *)&animationPosition, (const RwV3d *)((u8 *)animation + 4), 1, (const RtQuat *)(unit + 0x1C));
        func_003dcb40((RwV3d *)&focus, (const RwV3d *)((u8 *)animation + 0x1C), 1, (const RtQuat *)(unit + 0x1C));
        func_001bd780(&transition.frames[0].rot, &animationPosition, &focus, D_0060A0E0);
        transition.frames[0].pos.x = animationPosition.x + *(f32 *)(unit + 4);
        transition.frames[0].pos.y = animationPosition.y + *(f32 *)(unit + 8);
        transition.frames[0].pos.z = animationPosition.z + *(f32 *)(unit + 0xC);
        func_003dcb40((RwV3d *)&animationPosition, (const RwV3d *)((u8 *)animation + 0x10), 1, (const RtQuat *)(unit + 0x1C));
        func_003dcb40((RwV3d *)&focus, (const RwV3d *)((u8 *)animation + 0x28), 1, (const RtQuat *)(unit + 0x1C));
        func_001bd780(&transition.frames[1].rot, &animationPosition, &focus, D_0060A0E0);
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
        func_003dcb40((RwV3d *)&forward, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(unit + 0x1C));
        transition.unitHorizontal.x = forward.z;
        transition.unitHorizontal.y = -forward.x;
        func_003e41e0((f32 *)&transition.unitHorizontal, (f32 *)&transition.unitHorizontal);
        sideDot = transition.unitHorizontal.x * transition.cameraHorizontal.x + transition.unitHorizontal.y * transition.cameraHorizontal.y;
        if (!(sideDot < 0.0f)) {
            func_003e0870((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, 37.5f, 0);
        } else {
            func_003e0870((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, -37.5f, 0);
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
        func_003e40b0((RwV3d *)&orbitDirection, (const RwV3d *)&orbitDirection);
        func_001bd780(&transition.frames[1].rot, &position, &focus, D_0060A0E0);
        cameraDistance = orbitRadius / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        secondOffset = cameraDistance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
            func_003e0870((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, 70.0f, 0);
        } else {
            func_003e0870((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, -70.0f, 0);
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
        func_003e40b0((RwV3d *)&orbitDirection, (const RwV3d *)&orbitDirection);
        focus = savedCenter;
        func_001bd780(&transition.frames[0].rot, &position, &focus, D_0060A0E0);
        firstOffset = cameraDistance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
    func_001bac20((u16 *)(iGpffffb3ac + 0x24), (f32 *)&transition.frames[0].pos, (f32 *)&transition.frames[1].pos, 1);
    func_001bbef0(iGpffffb3ac + 0x24, (f32)frameCount / 30.0f);
    if (notify != 0) {
        func_004b3110(8);
    }
}
// FUN_001C1F70
void func_001c1f70(u8 *arg0)
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
        temp_16 = (u16 *)func_001d0730(*(u16 *)(temp_18 + 0xA4), 0);
        if ((*(u16 *)(iGpffffb3e0 +
                      *(u16 *)(temp_18 + 0xA4) * 0x58) & 1) == 0) {
            func_0019de70((BtlUnitStateWork *)temp_18, 0);
        } else {
            func_0019de70((BtlUnitStateWork *)temp_18, 1);
        }
        func_003dcb40((RwV3d *)&frame.valueA0,
                      (const RwV3d *)((u8 *)temp_16 + 4),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        func_003dcb40((RwV3d *)&frame.value90,
                      (const RwV3d *)((u8 *)temp_16 + 0x1C),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        func_001bd780(&frame.value5C, &frame.valueA0,
                      &frame.value90, D_0060A0E0);
        frame.value50 = frame.valueA0 + *(f32 *)(temp_17 + 4);
        frame.value54 = frame.valueA4 + *(f32 *)(temp_17 + 8);
        frame.value58 = frame.valueA8 + *(f32 *)(temp_17 + 0xC);
        func_003dcb40((RwV3d *)&frame.valueA0,
                      (const RwV3d *)((u8 *)temp_16 + 0x10),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        func_003dcb40((RwV3d *)&frame.value90,
                      (const RwV3d *)((u8 *)temp_16 + 0x28),
                      1, (const RtQuat *)(temp_17 + 0x1C));
        func_001bd780(&frame.value78, &frame.valueA0,
                      &frame.value90, D_0060A0E0);
        frame.value6C = frame.valueA0 + *(f32 *)(temp_17 + 4);
        frame.value70 = frame.valueA4 + *(f32 *)(temp_17 + 8);
        frame.value74 = frame.valueA8 + *(f32 *)(temp_17 + 0xC);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 1);
        func_001bac20((u16 *)(iGpffffb3ac + 0x24), &frame.value50, &frame.value6C, 1);
        temp_2 = *temp_16;
        var_f1 = (f32)(u16)temp_2;
        func_001bbef0(iGpffffb3ac + 0x24, var_f1 / 30.0f);
    }
}
/* cold 001c21d0 (2026-09-18): refused - outside 3% count gate, production stays INCLUDE_ASM. */
/* probe 689 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c21d0 --candidate commons_off=/var/tmp/cold1c21d0/v3_commons_off.c` (v1 695, v3 696, v4 696, decl swaps tie 689); fnalign retail 833 vs object 710 instrs (123 short, -14.8%; gate 808-858) 1026 edits (+2 reloc-only) via `python3 -E -s tools/fnalign.py src/promoted/code1_001c.c func_001c21d0 --candidate /var/tmp/cold1c21d0/v3_commons_off.c --quiet`. M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c func_001c21d0 -o /var/tmp/cold1c21d0/m2c.c`; romwright via `python3 -E -s tools/romwright_decompile.py func_001c21d0 > /var/tmp/cold1c21d0/rw.c` (--types: arity 3, arg0 pointer, arg1/2 scalar; prologue reads $4/$5/$6 before write, so (u8 *, s32, s32) stands) plus --raw. De-noised to file idiom reusing existing decls (func_00195850, func_0022f950, func_001bc330/0240/01b0, func_003e40b0, func_003e41e0, func_003dcb40, func_001bd780, func_001ec3d0, func_0044b868, func_004bd050, func_001bac20/bbef0/9de70/bcd40). Read func_001c79f0 MATCH note (7p snapshot placement: before first Y output 0, one statement earlier 5, three earlier 20) and code1_001f.c func_001f4e50 57->13 (row address plus two element pointers dereferenced at zero, second assigned lazily). Recipe in order: (1) free pragmas - opt_common_subs off 696->689 scoped push/pop, opt_loop_invariants on tie, opt_unroll_loops off tie, schedule off tie; (2) subscript form - no variable index in this unit (constant 0x2C/0x8C/0x90/0xA4 field loads), P[i] probe not applicable; (3) fresh loop counters (7n) - no backwards branches in retail (all forward b/bc1, zero for/while in either decompiler), nothing to split; (4) colouring - decl swaps for temp_v9/temp_v12 and vis21/alt16 tie at 689. Branch-order fix (romwright swapped the two large arms: 1.25f path first vs retail 2.5f path first) moved fnalign 960->929 edits but words 695->696. Width fixes (u64->u32, int quat->f32) scored 696. Two non-improving rounds above 60, stopping per batch. Gap lives in missing aggregate spills, not calls: jal counts exact both sides (4x00195850, 3x0019de70, 1x001bac20/bbef0/bc1b0/bc240/bc330/bcd40, 3x001bd780, 2x001ec3d0, 1x0022f950, 2x003dcb40, 1x003e0870, 2x003e40b0/41e0, 1x003e4320, 3x0044b868, 1x004b3110/bd050); frame retail -0x200 vs object -0x140 (192B of spills absent); largest fnalign holes are retail[434:471] 37 vs object 1 (quatFC copy plus out10C add plus 25.0 clamp), retail[138:156] 18 (0x2EE/cvt plus fGp80fc/8140 select plus fGp8118 scale), retail[565:585] 20. Excluded: scheduling (off tie), loop-invariant hoists, unrolling, declaration colouring, inverted-condition vs swapped-arm spellings. Best candidate kept at /var/tmp/cold1c21d0/v3_commons_off.c (689) for the next pass, which should rebuild it on a Frame from 0xB0 to 0x1F8 with 16-byte-aligned vector/quat fields. */
/* cold 001c21d0 (2026-09-19): honest redo per Main — 138:156 recovered (18, real, explicit (f32)0x2EE + volatile f32, gone from >15 list); surplus at 740:761 removed (pure-float 548 vs 833 -285 774 edits, no object-larger vs baseline 710 with 11 vs 40 + 9 vs 41); 434:471 37 vs 1 (quatFC copy + out10C add + 25.0 clamp) and 565:585 24 vs 1 (saves + madd) still missing (61); volatile 855 vs 836 +19 1008 edits frame -0x200 vs -0x180 128B game jal 32 exact in band only via cancelling (61 missing +64 lump 21 vs 85 at 740:761) refused per 7u; production stays INCLUDE_ASM. */
/* Construct side or approach camera poses from actor and target geometry. */
// FUN_001C21D0
void func_001c21d0(u8 *camera, s32 notify, s32 distinctPoses)
{
    extern s32 func_001bc330(u8 *camera);
    extern s32 func_001bc240(s32 cameraAddress);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern s32 func_001bc1b0(u8 *camera);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
    extern f32 func_0044b868(f32 angle);
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
    resourceMode = func_0022f950(work, resource) != 0;
    alternateMode = func_001bc330(camera) != 0;
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
    forceSide = func_001bc240((s32)camera);
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
    centerDistance = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);
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
    if ((forceSide != 0) || (((func_004bd050(0) & 1) != 0) && (func_001bc1b0(camera) != 0))) {
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
        func_003e0870(&matrix, &D_0060A0F0, tilt, 0);
        func_003e4320((RwV3d *)&rotatedUp, (const RwV3d *)D_0060A0E0, (const RwMatrix *)&matrix);
        func_001bd780(&frames[0].rot.quat, &eye, &focus, &rotatedUp);
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = func_001ec3d0((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        extentScale = 0.0f + lineDistance + frameRadius * extentScale;
        eye.x = projection.x;
        eye.y = 0.0f + snapshotCenter.y + 0.25f * actorTop;
        eye.z = projection.y;
        extentScale = extentScale / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        direction.x = direction.x * extentScale;
        direction.y = direction.y * extentScale;
        direction.z = direction.z * extentScale;
        if (sideDot < 0.0f) {
            extentScale = extentScale * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
        func_001bd780(&frames[0].rot.quat, &eye, &focus, D_0060A0E0);
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = func_001ec3d0((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        targetExtent = 0.0f + lineDistance + targetExtent * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        eye.x = projection.x;
        eye.y = snapshotCenter.y;
        eye.z = projection.y;
        {
            f32 cameraDistance = targetExtent / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
        centerDistance = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);
        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &snapshotCenter);
        snapshotCenter.y = 0.0f + snapshotCenter.y + 0.25f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        func_001bd780(&frames[0].rot.quat, &frames[1].pos, (f32 *)&snapshotCenter, D_0060A0E0);
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
    func_001bac20((u16 *)camera, (f32 *)&frames[0].pos, (f32 *)&frames[1].pos, 1);
    func_001bbef0(camera, extentScale);
    if (notify != 0) {
        func_004b3110(8);
    }
}
/* cold 001c2ee0 (2026-09-18): faithful direction only - production stays INCLUDE_ASM. */
/* counts: retail 1012 header (1009 fnalign) vs 793 faithful (762 v1 +31); band 982-1042 -> OUTSIDE (189 short of floor). Faithful = 3 duplicated scalings + t13 recompute (no pragmas) via /tmp/base_3dup.c: `fnalign --candidate /tmp/base_3dup.c --quiet` 793 instrs, 654 edits (+13 reloc) vs v1 651; `probe_variants --candidate base=/tmp/base_3dup.c` 904 vs v1 897. jal 49/49 both sides (tanf x9, grep/objdump), 5 switch arms present (0x4E/0x38/0x35/0x34/default). Side-by-side both tanf deletes (fnalign retail[640:649] + retail[729:738], 9 each): retail recomputes 0.5*B8 per use (mul $f1,$f1,$f0), GP per-use load (lwc1 -0x7EF0), mul GP*(0.5*B8), jal tanf, post-scale mul + lui 0x3E60/mtc1/nop; candidate caches t13=GP*B8*0.5 once for 4 tanfs and merges scalings into one path (retail 19 vs object 4 at 222:258; 38 vs 15 at 400:438). Same merge repeats all three scalings (first 2-elem t8, second 3-elem t12, third 3-elem aux t12) per 7k do-not-hoist-what-retail-recomputes. Remaining 1009-793=216 diffuse recompute-vs-cache of the same kind. */
/* rejected: pragma inflation into band measured +185 and refused as gate-defeating per Main (gate proves shape, not volume; real wins 10-60 words per 7s). `opt_common_subs off` 811 (+49), `commons+dead` 832 (+70), triple `commons+dead+peephole` 947 (+185); triple+3dup 982 (890 edits/probe 929) and +prop 984 (892/probe 926) via /tmp/cand_982.c + /tmp/cand_984.c -- DO NOT INSTALL. Re-assoc of 4 tanf args closed (v9_7p 758 instrs, probe 901 vs 897). Method: M2C/romwright de-noise as before with block externs func_0044b868/func_003e41e0; faithful diff held in /tmp/base_3dup.c. */
/* Build side or group camera poses, retaining both focus snapshots. */
// FUN_001C2EE0
void func_001c2ee0(u8 *camera, s32 notify, s32 distinctPoses)
{
    extern s32 func_001bc330(u8 *camera);
    extern s32 func_001bc240(s32 cameraAddress);
    extern s32 func_001bc630(u8 *camera);
    extern s32 func_001bc1b0(u8 *camera);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 func_0044b868(f32 angle);
    extern void func_001bbf40(u8 *camera, f32 duration);
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
    extern f32 func_00196040(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern RwV3d *func_003dcb40(RwV3d *camera, const RwV3d *notify, s32 distinctPoses, const RtQuat *arg3);
    extern void func_001bd780(void *camera, const void *notify, const void *distinctPoses, const void *arg3);
    extern s32 func_004bd050(s32 camera);
    extern void func_0019de70(BtlUnitStateWork *work, u16 value);
    extern void func_001bcd40(u8 *camera, u8 *notify, f32 *distinctPoses, f32 arg3, u16 arg4);
    extern u32 func_001bc3a0(f32 *camera, f32 *notify);
    extern void func_001bac20(u16 *camera, f32 *notify, f32 *distinctPoses, u16 arg3);
    extern void func_001bbef0(u8 *camera, f32 notify);
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
    alternateMode = (func_001bc330(camera) != 0);
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
    groupRadius = func_00196040(2, 0, (RwV3d *)((f32 *)&groupCenter), &top, NULL, 1);
    func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)(actor + 0x1C));
    groupCenter.y = 0.5f * top;
    delta.x = actorCenter.x - groupCenter.x;
    delta.y = actorCenter.y - groupCenter.y;
    delta.z = actorCenter.z - groupCenter.z;
    scale = func_003e40b0((RwV3d *)&delta, (const RwV3d *)&delta);
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
    forceSide = func_001bc240((s32)camera);
    specialMode = func_001bc630(camera);
    if ((alternateMode == 1) || ((*(u16 *)(iGpffffb3e0 + (*(u16 *)(target + 0xA4) * 10 + *(u16 *)(target + 0xA4)) * 8) & 0x20) == 0)) {
        chooseSide = (func_004bd050(0) & 1) != 0;
    } else {
        chooseSide = 0;
    }
    if ((forceSide != 0) || ((chooseSide == 1) && (func_001bc1b0(camera) != 0) && (specialMode == 0))) {
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
        extent = func_003e40b0(&direction, &direction);
        cachedAngle = fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8));
        tangent = func_0044b868(cachedAngle);
        radius = radius / tangent;
        tangent = func_0044b868(cachedAngle);
        radius = radius > distance / tangent ? radius : distance / tangent;
        extent = extent + radius;
        distance = func_0044b868(cachedAngle);
        extent = extent > groupRadius / distance ? extent : groupRadius / distance;
        distance = extent * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
        func_001bd780(&frames[1].rot.quat, &frames[1].pos, &focus, D_0060A0E0);
        btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorCenter);
        actorCenter.y = 0.0f + actorCenter.y + fGpffff8118 * (*(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C));
        distance = 2.5f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)(actor + 0x1C));
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
        func_001bd780(&frames[0].rot.quat, &firstEye, &savedFocus, D_0060A0E0);
        extent = 4.0f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        direction.x = firstEye.x - savedFocus.x;
        direction.y = firstEye.y - savedFocus.y;
        direction.z = firstEye.z - savedFocus.z;
        distance = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);
        radius = func_0044b868(cachedAngle);
        distance = distance + extent / radius;
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        extent = distance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
        distance = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);
        if (groupRadius < 300.0f) groupRadius = 300.0f;
        tangent = func_0044b868(0.5f * *(f32 *)(camera + 0xB8));
        distance = distance + groupRadius / tangent;
        extent = distance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
        func_001bd780(&frames[1].rot.quat, &frames[1].pos, &focus, D_0060A0E0);
        if (specialMode == 0) {
            if (!(sideDot < 0.0f)) {
                func_003e0870((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, -27.5f, 0);
            } else {
                func_003e0870((RwMatrix *)&matrix, (const RwV3d *)D_0060A0E0, 27.5f, 0);
            }
            func_003e4320((RwV3d *)&delta, (const RwV3d *)&direction, (const RwMatrix *)&matrix);
            distance = distance * fGpffff80e8;
            extent = distance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
            extent = func_003e40b0((RwV3d *)&delta, (const RwV3d *)&delta);
            extent = p4_cacd0_mul(0.25f, extent);
            focus.x = delta.x * extent;
            focus.y = delta.y * extent;
            focus.z = delta.z * extent;
            focus.x = focus.x + groupCenter.x;
            focus.y = focus.y + groupCenter.y;
            focus.z = focus.z + groupCenter.z;
            func_001bd780(&frames[0].rot.quat, &frames[0].pos, &focus, D_0060A0E0);
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
            func_001bd780(&frames[0].rot.quat, &frames[0].pos, &focus, D_0060A0E0);
        }
    }
    if ((distinctPoses == 0) && (specialMode == 0)) {
        frames[0].rot.quat = frames[1].rot.quat;
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)&frames[0].rot.quat);
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
    func_001bc3a0((f32 *)&frames[0], (f32 *)&frames[0]);
    func_001bc3a0((f32 *)&frames[1], (f32 *)&frames[1]);
    func_001bac20((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    if (directTiming == 0) {
        func_001bbef0(camera, distance);
    } else {
        func_001bbf40(camera, distance);
    }
    if (notify != 0) {
        func_004b3110(8);
    }
}

// FUN_001C3EB0
void func_001c3eb0(u8 *arg0, s32 arg1)
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
        if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
        }
    }
}
/* Frame target and actor geometry with separate side and approach poses. */
// FUN_001C3F70
void func_001c3f70(u8 *camera, s32 notify, s32 distinctPoses)
{
    extern s32 func_001bc240(s32 cameraAddress);
    extern s32 func_001bc1b0(u8 *camera);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern void func_001bd780(void *camera, const void *notify, const void *distinctPoses, const void *arg3);
    extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
    extern f32 func_0044b868(f32 angle);
    extern s32 func_004bd050(s32 camera);
    extern void func_0019de70(BtlUnitStateWork *action, u16 value);
    extern void func_001bcd40(u8 *camera, u8 *notify, f32 *distinctPoses, f32 arg3, u16 arg4);
    extern void func_001bac20(u16 *camera, f32 *notify, f32 *distinctPoses, u16 arg3);
    extern void func_001bbef0(u8 *camera, f32 notify);
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
        sideView = func_001bc240((s32)camera);
        if (!((resourceTop - targetTop) < 125.0f)) {
            sideView = 0;
        } else {
            sideView = (sideView != 0);
            if (sideView == 0) {
                sideView = (func_004bd050(0) & 1) != 0;
                if (sideView != 0) {
                    sideView = (func_001bc1b0(camera) != 0);
                }
            }
        }
    }
    if (sideView != 0) {
        direction.x = resourceCenter.x - targetCenter.x;
        direction.y = resourceCenter.y - targetCenter.y;
        direction.z = resourceCenter.z - targetCenter.z;
        directionDistance = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);
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
        directionDistance = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);
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
        func_001bd780(&frames[1].rot.quat, &eye, &focus, D_0060A0E0);
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = func_001ec3d0((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
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
        cameraDistance = cameraDistance / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        direction.x = direction.x * cameraDistance;
        direction.y = direction.y * cameraDistance;
        direction.z = direction.z * cameraDistance;
        if (sideDot < 0.0f) {
            cameraDistance = cameraDistance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
        directionDistance = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);
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
        func_001bd780(&frames[0].rot.quat, &eye, &focus, D_0060A0E0);
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = func_001ec3d0((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        cameraDistance = func_001c_mul_add(actorRadius, 3.0f, 0.0f + lineDistance);
        eye.x = projection.x;
        eye.y = 0.0f + snapshotCenter.y + 0.25f * actorTop;
        eye.z = projection.y;
        cameraDistance = cameraDistance / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        direction.x = direction.x * cameraDistance;
        direction.y = direction.y * cameraDistance;
        direction.z = direction.z * cameraDistance;
        if (sideDot < 0.0f) {
            cameraDistance = cameraDistance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
        func_001bd780(&frames[0].rot.quat, &eye, &focus, D_0060A0E0);
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot.quat);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = snapshotCenter.x;
        projectedCenter.y = snapshotCenter.z;
        lineDistance = func_001ec3d0((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        cameraDistance = 0.0f + lineDistance + 1.5f * (*(f32 *)(targetUnit + 0x90) * *(f32 *)(targetUnit + 0x2C));
        eye.x = projection.x;
        eye.y = snapshotCenter.y;
        eye.z = projection.y;
        cameraDistance = cameraDistance / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        if (cameraDistance < (f32)0x226) cameraDistance = (f32)0x226;
        direction.x = direction.x * cameraDistance;
        direction.y = direction.y * cameraDistance;
        direction.z = direction.z * cameraDistance;
        if (!(sideDot < 0.0f)) {
            cameraDistance = cameraDistance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
        cameraDistance = func_003e40b0((RwV3d *)&direction, (const RwV3d *)&direction);
        btlUnitGetSphereWorldCenter((BtlUnit *)selectedUnit, &snapshotCenter);
        snapshotCenter.y = 0.0f + snapshotCenter.y + fGpffff8030 * (*(f32 *)(selectedUnit + 0x8C) * *(f32 *)(selectedUnit + 0x2C));
        func_001bd780(&frames[0].rot.quat, &frames[1].pos, (f32 *)&snapshotCenter, D_0060A0E0);
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
    func_001bac20((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    func_001bbef0(camera, duration);
    if (notify != 0) {
        func_004b3110(8);
    }
}
// FUN_001C5110
void func_001c5110(u8 *arg0)
{
    u8 *temp;
    s32 arg1;
    s32 arg2;
    s32 mode;

    temp = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp = *(u8 **)(temp + 0xA0C);
    arg1 = 1;
    arg2 = 1;
    *(u16 *)(arg0 + 0x110) = (u16)func_001c0e50(arg0);
    if (*(u16 *)(arg0 + 0xE4) == 0x1D) {
        arg1 = 0;
        arg2 = 0;
    }
    if ((temp != NULL) &&
        (func_0022f950(*(u8 **)(arg0 + 0xE0), temp) != 0)) {
        *(s32 *)(arg0 + 0x114) = 1;
    } else {
        *(s32 *)(arg0 + 0x114) = 0;
    }
    mode = *(u16 *)(arg0 + 0x110);
    switch (mode) {
    case 1:
        func_001c17a0(arg0, arg1, arg2);
        return;
    case 2:
        func_001c21d0(arg0, arg1, arg2);
        return;
    case 3:
        func_001c2ee0(arg0, arg1, arg2);
        return;
    case 4:
        if ((*(s32 *)(arg0 + 0x114) == 0) &&
            ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0)) {
            func_001c3f70(arg0, arg1, arg2);
            return;
        }
        func_001c21d0(arg0, arg1, arg2);
        return;
    case 5:
        func_001c2ee0(arg0, arg1, arg2);
        return;
    case 6:
        func_001c1040(arg0, 1);
    default:
        return;
    }
}
// FUN_001C52C0
void func_001c52c0(u8 *arg0)
{
    switch (*(u16 *)(arg0 + 0x110)) {
    case 0:
    case 1:
        break;
    case 2:
        if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
            ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0) &&
            (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
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
            if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
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
                if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
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
                (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
                func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                              *(u16 *)(arg0 + 0x130));
            }
        }
        break;
    case 5:
        func_001c3eb0(arg0, 0);
        break;
    case 6:
        if ((*(u8 **)(arg0 + 0xE0) != NULL) &&
            ((*(u16 *)(*(u8 **)(arg0 + 0xE0) + 0x1A) & 1) != 0) &&
            (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0)) {
            func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C),
                          *(u16 *)(arg0 + 0x130));
        }
        break;
    default:
        return;
    }
}
// FUN_001C5500
void func_001c5500(u8 *arg0, s32 arg1)
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
    extern void func_001bd560(f32 *out, f32 *in);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_001ec3d0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0* first, P4Vec4Holder_001EC2B0* second);
    extern void func_001bd5e0(f32 *arg0, f32 *arg1);
    extern f32 func_0044b868(f32 arg0);

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
    func_001bd780(&poses.second.rot, &eye, &focus, D_0060A0E0);
    func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&poses.second.rot);

    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    projDist = func_001ec3d0((u8 *)geometry.focusXZ,
                             (u8 *)geometry.eyeXZ,
                             (u8 *)baseXZ,
                             (u8 *)projectionXZ);
    accumDist = projDist + radiusScale * (*(f32 *)(primaryUnit + 0x90) * *(f32 *)(primaryUnit + 0x2C));
    eye.x = projectionXZ[0];
    eye.y = unitY;
    eye.z = projectionXZ[1];

    tanFov = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
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

    func_001bd560((f32 *)&poses.first, (f32 *)(arg0 + 0x9C));
    if (!(func_001ec2b0((P4Vec4Holder_001EC2B0*)(&poses.first.rot), (P4Vec4Holder_001EC2B0*)(&poses.second.rot)) <= fGpffff8158)) {
        func_001bd5e0((f32 *)&poses.first, (f32 *)&poses.second);
        func_003dcb40((RwV3d *)&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&poses.first.rot);
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
    func_001bac20((u16 *)arg0, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    func_001bbef0(arg0, duration);
}
/* measured 001c5b80: 515 differing words guarded via `python3 tools/measure_guarded.py src/promoted/code1_001c.c func_001c5b80` (GUARDED_SCORE 515); probe 515 via `python3 tools/probe_variants.py src/promoted/code1_001c.c func_001c5b80 --candidate v16=/var/tmp/cold1c5b80/v16.c`; fnalign retail 629 vs object 626 instrs, 231 edits (+15 reloc-only) via `python3 tools/fnalign.py src/promoted/code1_001c.c func_001c5b80 --candidate /var/tmp/cold1c5b80/v16.c --quiet`. M2C via `python3 -E -s tools/m2c_decompile.py src/promoted/code1_001c.c func_001c5b80 -o /var/tmp/cold1c5b80/m2c.c`; romwright raw via `python3 tools/romwright_decompile.py func_001c5b80 --raw -o /var/tmp/cold1c5b80/rw_raw.c` (m2c-shaped fails on CONCAT44 intrinsic); de-noised to file idiom reusing existing decls (func_001bd560, func_003e40b0, func_003e4180, func_001958f0, func_00196040, func_003e0870, func_003e4320, func_001bd780, func_001bc3a0, func_001bac20, func_001bbef0, func_004b3110, func_001eb440, func_004bd050, D_0060A0E0, iGpffffb3ac, fGpffff8110) plus block externs (func_001bc630(u8*), func_003e41e0(f32*,f32*), func_0044b868(f32)->f32, fGpffff8118/fGpffff8128). Frame 0x160 with pose50[7]+out6C[3]+quat78[4]+pad88+mat90+padD0+pairD8+valE0+padE4+pairE8[2]+pairF0+valF8+padFC+actor100[3]+pad10C+out110[3]+pad11C+dir120[3]+pad12C+tmp130[3]+pad13C+center140[3]+pad14C+center150[3]+top15C (0x110 locals). Round1 v1 535 (629 vs 629, 125+16) -> v2 535 tie (single-mask group + (f32)0x226/0x2EE for 550/750). Round2 v3 530 (reversed float decls, -5) vs v4 532 (branch >=2 first, -3). Round3 v5 518 (v3+branch+center-center zero, -12) vs v6 530 tie (u16 counter). Round4 v7 518 tie (switch descending 4E-first) vs v8 522 (50-first numerator, +4). Round5 v9 517 (for-loop, -1) vs v10 518 tie (1.25 reorder). Round6 v11/v12 517 ties (0.5/len and 8128/len swaps). Round7 v13 522 (len-first decls, +5) vs v14 516 (centerY/Z cache, -1). Round8 v15 516 tie (split side) vs v16 515 (double copy_pair, -1). Round9 v17/v18 515 ties (split on v16, p4_cacd0_mul). Round10 v19/v20 515 ties (plain +0 removal, inclusive compare). Two unproductive rounds, stopping. Top remaining: FPU color shift (retail $f23/$f21 vs object $f21/$f22), COP1 adda/madd at +0x3E8/+0x3EC and adda/madd+msub at +0x6AC..+0x6C4 per archive (plain C emits mul/add, source-unreachable floor), ld/sd vs lw/sw copy, branch $at vs $v0, switch dispatch. Pragma sweep singles+28 pairs: best ties 515 (loopinv/strength/unroll), none installed. Within 3% size gate (626/629=99.5%), banked as floor. */
/* measured 001c5b80 (owner, 2026-09-19): fnalign **231 -> 191 edits**, count
   626 -> 626 against retail 629, by putting one switch's arms in REVERSED
   order.  Case order is EMISSION order and the right one is whatever retail emitted:
   a chain converted to a switch wants ascending, a jump table wants the table's own
   layout, and a `beq` chain with no table can want the reverse of the source order.
   All three orderings were measured on every switch in this body and this is the
   only one that improved it; swept across the 167 first-party floors carrying a
   switch, just four responded at all. */
// FUN_001C5B80 NONMATCHING
#ifdef NON_MATCHING
void func_001c5b80(u8 *arg0, s32 arg1)
{
    struct Frame {
        f32 pose50[7];
        f32 out6C[3];
        f32 quat78[4];
        u8 pad88[8];
        u8 mat90[0x40];
        u8 padD0[8];
        s64 pairD8;
        f32 valE0;
        u8 padE4[4];
        f32 pairE8[2];
        s64 pairF0;
        f32 valF8;
        u8 padFC[4];
        f32 actor100[3];
        u8 pad10C[4];
        f32 out110[3];
        u8 pad11C[4];
        f32 dir120[3];
        u8 pad12C[4];
        f32 tmp130[3];
        u8 pad13C[4];
        f32 center140[3];
        u8 pad14C[4];
        f32 center150[3];
        f32 top15C;
    } frame;
    extern s32 func_001bc630(u8 *arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern f32 func_0044b868(f32 arg0);
    extern f32 fGpffff8110;
    extern f32 fGpffff8118;
    extern f32 fGpffff8128;
    f32 centerY;
    f32 centerZ;
    f32 cand;
    f32 tanRes;
    f32 scale;
    f32 len;
    f32 var_f23;
    f32 var_f22;
    f32 var_f21;
    f32 var_f20;
    s32 isZero;
    s32 group;
    s32 var_17;
    u8 *saved_arg0;
    u8 *work;
    u8 *entry;
    u8 *unit;
    (void)arg1;
    saved_arg0 = arg0;
    isZero = func_001bc630(saved_arg0);
    func_001bd560(frame.pose50, saved_arg0 + 0x9C);
    work = *(u8 **)(saved_arg0 + 0xE0);
    if (*(u16 *)(work + 0x6A) >= 2) {
        group = func_001eb440(work + 0x38);
    } else {
        group = 3;
    }
    group = group & 0xFFFF;
    var_f21 = func_00196040(group, 1, (RwV3d *)(frame.center150), &frame.top15C, NULL, 0);
    frame.center150[1] = 0.75f * frame.top15C;
    var_f23 = var_f21 / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
    if (var_f23 < 1000.0f) {
        var_f23 = 1000.0f;
    }
    func_00196040(group, 1, (RwV3d *)(frame.center140), NULL, NULL, 1);
    var_f20 = 0.0f;
    for (var_17 = 0; (var_17 & 0xFFFF) < *(u16 *)(*(u8 **)(saved_arg0 + 0xE0) + 0x6A); var_17 = (var_17 + 1) & 0xFFFF) {
        work = *(u8 **)(saved_arg0 + 0xE0);
        entry = *(u8 **)(work + ((var_17 & 0xFFFF) * 4) + 0x38);
        if ((*(u16 *)(entry + 0x1A) & 1) != 0) {
            func_001958f0((BtlUnit *)(*(u8 **)(entry + 0x30)), (RwV3d *)(frame.actor100));
            frame.tmp130[0] = frame.center140[0] - frame.actor100[0];
            frame.tmp130[1] = frame.center140[1] - frame.actor100[1];
            frame.tmp130[2] = frame.center140[2] - frame.actor100[2];
            len = func_003e4180(frame.tmp130);
            if (!(len <= var_f20)) {
                func_001c_copy_pair(&frame.pairF0, &frame.valF8, (s64 *)frame.actor100, &frame.actor100[2]);
                var_f20 = len;
            }
        }
    }
    work = *(u8 **)(saved_arg0 + 0xE0);
    unit = *(u8 **)(work + 0x30);
    func_001958f0((BtlUnit *)(unit), (RwV3d *)(frame.actor100));
    frame.tmp130[0] = frame.center140[0] - frame.actor100[0];
    frame.tmp130[1] = frame.center140[1] - frame.actor100[1];
    frame.tmp130[2] = frame.center140[2] - frame.actor100[2];
    len = func_003e4180(frame.tmp130);
    if (!(len <= var_f20)) {
        func_001c_copy_pair(&frame.pairD8, &frame.valE0, (s64 *)frame.actor100, &frame.actor100[2]);
        func_001c_copy_pair(&frame.pairF0, &frame.valF8, &frame.pairD8, &frame.valE0);
        frame.dir120[0] = frame.actor100[0] - frame.center150[0];
        frame.dir120[1] = frame.actor100[1] - frame.center150[1];
        frame.dir120[2] = frame.actor100[2] - frame.center150[2];
        len = func_003e40b0((RwV3d *)frame.dir120, (const RwV3d *)frame.dir120);
        var_f20 = len;
        scale = fGpffff8128 * len;
        frame.actor100[0] = frame.dir120[0] * scale;
        frame.actor100[1] = frame.dir120[1] * scale;
        frame.actor100[2] = frame.dir120[2] * scale;
        centerY = frame.center150[1];
        centerZ = frame.center150[2];
        frame.center150[0] = frame.center150[0] + frame.actor100[0];
        frame.center150[1] = centerY + frame.actor100[1];
        frame.center150[2] = centerZ + frame.actor100[2];
        unit = *(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30);
        cand = len + (1.25f * (*(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C))) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
        if (!(cand <= var_f23)) {
            var_f23 = cand;
        }
    } else if (var_f20 != 0.0f) {
        if (*(u16 *)(*(u8 **)(saved_arg0 + 0xE0) + 0x6A) >= 2) {
            frame.dir120[0] = frame.actor100[0] - frame.center150[0];
            frame.dir120[1] = frame.actor100[1] - frame.center150[1];
            frame.dir120[2] = frame.actor100[2] - frame.center150[2];
            len = func_003e40b0((RwV3d *)frame.dir120, (const RwV3d *)frame.dir120);
            cand = (len + *(f32 *)(*(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30) + 0x90) * *(f32 *)(*(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30) + 0x2C) + 50.0f) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
            if (!(cand <= var_f23)) {
                var_f23 = cand;
            }
            frame.dir120[0] = frame.actor100[0] - *(f32 *)&frame.pairF0;
            frame.dir120[1] = frame.actor100[1] - *(f32 *)((u8 *)&frame.pairF0 + 4);
            frame.dir120[2] = frame.actor100[2] - frame.valF8;
            scale = 0.5f * func_003e40b0((RwV3d *)frame.dir120, (const RwV3d *)frame.dir120);
            frame.actor100[0] = frame.dir120[0] * scale;
            frame.actor100[1] = frame.dir120[1] * scale;
            frame.actor100[2] = frame.dir120[2] * scale;
            *(f32 *)&frame.pairF0 = *(f32 *)&frame.pairF0 + frame.actor100[0];
            *(f32 *)((u8 *)&frame.pairF0 + 4) = *(f32 *)((u8 *)&frame.pairF0 + 4) + frame.actor100[1];
            frame.valF8 = frame.valF8 + frame.actor100[2];
        }
    } else if (var_f20 == 0.0f) {
        func_001958f0((BtlUnit *)(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30)), (RwV3d *)((f32 *)&frame.pairF0));
    }
    *(f32 *)((u8 *)&frame.pairF0 + 4) = frame.center150[1];
    frame.tmp130[0] = *(f32 *)&frame.pairF0 - frame.center150[0];
    frame.tmp130[1] = frame.center150[1] - frame.center150[1];
    frame.tmp130[2] = frame.valF8 - frame.center150[2];
    func_003e40b0((RwV3d *)frame.tmp130, (const RwV3d *)frame.tmp130);
    frame.tmp130[0] = frame.tmp130[0] * var_f21;
    frame.tmp130[1] = frame.tmp130[1] * var_f21;
    frame.tmp130[2] = frame.tmp130[2] * var_f21;
    var_f22 = frame.center150[0] + frame.tmp130[0];
    var_f20 = frame.center150[2] + frame.tmp130[2];
    var_f21 = 1.25f * frame.top15C;
    frame.dir120[0] = var_f22 - frame.center150[0];
    frame.dir120[2] = var_f20 - frame.center150[2];
    frame.dir120[1] = 0.0f;
    scale = fGpffff8118 * func_003e40b0((RwV3d *)frame.dir120, (const RwV3d *)frame.dir120);
    frame.dir120[0] = frame.dir120[0] * scale;
    frame.dir120[1] = frame.dir120[1] * scale;
    frame.dir120[2] = frame.dir120[2] * scale;
    frame.out110[0] = frame.center150[0] + frame.dir120[0];
    frame.out110[1] = frame.center150[1] + frame.dir120[1];
    frame.out110[2] = frame.center150[2] + frame.dir120[2];
    frame.out110[1] = frame.center150[1];
    if (var_f21 < 250.0f) {
        var_f21 = 250.0f;
    }
    frame.tmp130[0] = var_f22 - frame.out110[0];
    frame.tmp130[1] = var_f21 - frame.out110[1];
    frame.tmp130[2] = var_f20 - frame.out110[2];
    func_003e40b0((RwV3d *)frame.tmp130, (const RwV3d *)frame.tmp130);
    tanRes = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
    scale = var_f23 * tanRes * 0.21875f;
    frame.pairE8[0] = frame.tmp130[0];
    frame.pairE8[1] = frame.tmp130[2];
    func_003e41e0(frame.pairE8, frame.pairE8);
    frame.out110[0] = frame.pairE8[1] * scale + frame.out110[0] + 0.0f;
    frame.out110[2] = (frame.out110[2] + 0.0f) - frame.pairE8[0] * scale;
    if (func_004bd050(0) & 1) {
        scale = 7.5f;
    } else {
        scale = -7.5f;
    }
    func_003e0870((RwMatrix *)frame.mat90, (const RwV3d *)D_0060A0E0, scale, 0);
    func_003e4320((RwV3d *)frame.dir120, (const RwV3d *)frame.tmp130, (const RwMatrix *)frame.mat90);
    frame.dir120[0] = frame.dir120[0] * var_f23;
    frame.dir120[1] = frame.dir120[1] * var_f23;
    frame.dir120[2] = frame.dir120[2] * var_f23;
    frame.out6C[0] = frame.out110[0] + frame.dir120[0];
    frame.out6C[1] = frame.out110[1] + frame.dir120[1];
    frame.out6C[2] = frame.out110[2] + frame.dir120[2];
    func_001bd780(frame.quat78, frame.out6C, frame.out110, D_0060A0E0);
    if (isZero == 0) {
        func_003e0870((RwMatrix *)frame.mat90, (const RwV3d *)D_0060A0E0, -scale, 0);
        func_003e4320((RwV3d *)frame.dir120, (const RwV3d *)frame.tmp130, (const RwMatrix *)frame.mat90);
        frame.dir120[0] = frame.dir120[0] * var_f23;
        frame.dir120[1] = frame.dir120[1] * var_f23;
        frame.dir120[2] = frame.dir120[2] * var_f23;
        frame.pose50[0] = frame.out110[0] + frame.dir120[0];
        frame.pose50[1] = frame.out110[1] + frame.dir120[1];
        frame.pose50[2] = frame.out110[2] + frame.dir120[2];
        func_001bd780(&frame.pose50[3], frame.pose50, frame.out110, D_0060A0E0);
        func_004b3110(8);
        scale = 8.0f;
    } else {
        frame.pose50[0] = frame.out6C[0];
        frame.pose50[1] = frame.out6C[1];
        frame.pose50[2] = frame.out6C[2];
        switch (*(u16 *)(*(u8 **)(saved_arg0 + 0xE0) + 0x6E)) {
        case 52:
            frame.pose50[1] = 500.0f;
            frame.out110[1] = 450.0f;
            scale = 2.75f;
            break;
        case 53:
            frame.pose50[1] = 600.0f;
            frame.out110[1] = (f32)0x226;
            scale = 3.0f;
            break;
        case 56:
            frame.pose50[1] = 800.0f;
            frame.out110[1] = 700.0f;
            scale = 3.75f;
            break;
        case 78:
            frame.pose50[1] = 1000.0f;
            frame.out110[1] = (f32)0x2EE;
            scale = 2.5f;
            break;
        default:
            frame.pose50[1] = 500.0f;
            frame.out110[1] = 450.0f;
            scale = 2.75f;
            break;
        }
        func_001bd780(&frame.pose50[3], frame.pose50, frame.out110, D_0060A0E0);
        func_004b3110(8);
    }
    func_001bc3a0(frame.pose50, frame.pose50);
    func_001bc3a0(frame.out6C, frame.out6C);
    func_001bac20((u16 *)saved_arg0, frame.pose50, frame.out6C, 1);
    func_001bbef0(saved_arg0, scale);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_001c", func_001c5b80);
#endif
// FUN_001C79E0
void func_001c79e0(void) {}
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
// FUN_001C79F0
void func_001c79f0(u8 *arg0, s32 arg1)
{
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
    extern void func_00195d50(u8 *arg0, f32 *arg1);
    extern s32 func_002428f0(s32 arg0, s32 arg1);
    extern s32 func_00243e30(s32 arg0);
    extern s32 func_00242930(s32 arg0);
    extern f32 func_0044b868(f32 arg0);
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    f32 var_f24;
    f32 var_f23;
    f32 var_f22;
    f32 var_f21;
    f32 var_f20;
    f32 positionY;
    u8 *saved_arg0;
    u8 *var17;
    u8 *var16;
    (void)arg1;

    saved_arg0 = arg0;
    if (*(u16 *)(saved_arg0 + 0x106) != 0) {
        func_001bd560(frame.poseA0, (f32 *)(saved_arg0 + 0x9C));
        var16 = *(u8 **)(*(u8 **)(saved_arg0 + 0xE0) + 0x30);
        var_f20 = func_00196040(3, 0, (RwV3d *)(frame.target118), 0, 0, 1);
        func_00196040(1, 0, NULL, &frame.max14C, &frame.min148, 1);
        frame.target118[1] = frame.min148 + 0.5f * (frame.max14C - frame.min148);
        var_f20 = (0.75f * var_f20) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
        func_001958f0((BtlUnit *)(var16), (RwV3d *)(frame.actorE8));
        frame.eye108[0] = frame.actorE8[0];
        frame.eye108[1] = frame.target118[1];
        frame.eye108[2] = frame.actorE8[2];
        frame.dir128[0] = frame.actorE8[0] - frame.target118[0];
        frame.dir128[1] = frame.target118[1] - frame.target118[1];
        frame.dir128[2] = frame.actorE8[2] - frame.target118[2];
        {
            f32 tmpLen;
            tmpLen = func_003e40b0((RwV3d *)frame.dir128, (const RwV3d *)frame.dir128);
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
        func_001bd780((void *)frame.quatCC, (void *)frame.eye108, (void *)frame.baseF8, (void *)D_0060A0E0);
        func_003dcb40((RwV3d *)frame.dir128, (const RwV3d *)D_0060A100, 1, (const RtQuat *)frame.quatCC);
        frame.dir128[0] = frame.dir128[0] * var_f20;
        frame.dir128[1] = frame.dir128[1] * var_f20;
        frame.dir128[2] = frame.dir128[2] * var_f20;
        var_f20 = p4_cacd0_mul(var_f20 * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8))), 0.21875f);
        var_f20 = var_f20 * fGpffff812c;
        frame.horizE0[0] = frame.dir128[0];
        frame.horizE0[1] = frame.dir128[2];
        func_003e41e0(frame.horizE0, frame.horizE0);
        frame.baseF8[0] = frame.horizE0[1] * var_f20 + frame.baseF8[0] + 0.0f;
        frame.baseF8[2] = (frame.baseF8[2] + 0.0f) - frame.horizE0[0] * var_f20;
        frame.outC0[0] = frame.baseF8[0] + frame.dir128[0];
        frame.outC0[1] = frame.baseF8[1] + frame.dir128[1];
        frame.outC0[2] = frame.baseF8[2] + frame.dir128[2];
        func_001bc3a0(frame.outC0, frame.outC0);
        func_001bac20((u16 *)saved_arg0, frame.poseA0, frame.outC0, 1);
        func_001bbef0(saved_arg0, 0.75f);
    } else {
        *(s32 *)(saved_arg0 + 0x148) = 1;
        var17 = (u8 *)func_001d8bc0(*(u8 **)(saved_arg0 + 0xE0) + 0x98);
        var16 = *(u8 **)(var17 + 0x30);
        var_f20 = *(f32 *)(var16 + 0x90) * *(f32 *)(var16 + 0x2C);
        var_f24 = 0.5f * (*(f32 *)(var16 + 0x8C) * *(f32 *)(var16 + 0x2C));
        if (func_002428f0(*(s32 *)(var16 + 0xA64), 0) != 0) {
            func_00195d50(var16, frame.pos138);
            var_f23 = 1.5f;
            var_f22 = 3.5f;
            var_f21 = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8118 * var_f24;
        } else if (func_00232710(*(s32 *)(var16 + 0xA64), 0x100000) != 0) {
            func_00195850(var16, frame.pos138);
            var_f23 = fGpffff8130;
            var_f22 = fGpffff8134;
            var_f21 = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8118 * var_f24;
        } else if (func_00243e30(*(s32 *)(var16 + 0xA64)) != 0) {
            func_00195850(var16, frame.pos138);
            var_f23 = fGpffff8138;
            var_f22 = 0.75f;
            var_f21 = 15.0f;
            frame.pos138[1] = frame.pos138[1] + fGpffff8118 * var_f24;
        } else if (func_00242930(*(s32 *)(var16 + 0xA64)) != 0) {
            func_00195850(var16, frame.pos138);
            var_f23 = fGpffff8138;
            var_f22 = 1.0f;
            var_f21 = 25.0f;
            frame.pos138[1] = frame.pos138[1] - fGpffff8030 * var_f24;
        } else {
            func_00195850(var16, frame.pos138);
            var_f23 = 1.25f;
            var_f22 = 1.0f;
            var_f21 = 25.0f;
            frame.pos138[1] = frame.pos138[1] + fGpffff813c * var_f24;
        }
        if (var_f20 > var_f24) {
            var_f20 = (var_f20 * var_f23) / func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8)));
        } else {
            var_f20 = (var_f24 * var_f23) / func_0044b868(0.5f * *(f32 *)(saved_arg0 + 0xB8));
        }
        func_003dcb40((RwV3d *)frame.dir128, (const RwV3d *)(&D_0060A0F0), 1, (const RtQuat *)(var16 + 0x1C));
        func_003e0870((RwMatrix *)frame.mat60, (const RwV3d *)D_0060A0E0, var_f21, 0);
        func_003e4320((RwV3d *)frame.dir128, (const RwV3d *)frame.dir128, (const RwMatrix *)frame.mat60);
        var_f21 = p4_cacd0_mul(var_f20 * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(saved_arg0 + 0xB8))), 0.21875f);
        var_f21 = var_f21 * fGpffff8118;
        frame.horizE0[0] = frame.dir128[0];
        frame.horizE0[1] = frame.dir128[2];
        func_003e41e0(frame.horizE0, frame.horizE0);
        frame.pos138[0] = frame.horizE0[1] * var_f21 + frame.pos138[0] + 0.0f;
        frame.pos138[2] = (frame.pos138[2] + 0.0f) - frame.horizE0[0] * var_f21;
        frame.outC0[0] = frame.pos138[0] + frame.dir128[0] * var_f20;
        positionY = frame.pos138[1];
        frame.outC0[1] = positionY + frame.dir128[1] * var_f20;
        frame.outC0[2] = frame.pos138[2] + frame.dir128[2] * var_f20;
        frame.outC0[1] = positionY + var_f24 * var_f22;
        func_001bd780((void *)frame.quatCC, (void *)frame.outC0, (void *)frame.pos138, (void *)D_0060A0E0);
        func_001bcd40(var17, (u8 *)0, (f32 *)0, 0.0f, 1);
        func_001bab00((u16 *)(saved_arg0), (f32 *)frame.outC0);
    }
}
/* Interpolate the group and target orientations using a complete
 * quaternion cache and four complete poses. Position weights remain
 * distinct from the sine-adjusted quaternion weights.
 * b210 -O2: 2012 exact bytes and four zero alignment bytes. */
// FUN_001C80F0
void func_001c80f0(u8 *camera, s32 immediate)
{
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
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern void func_001bd560(f32 *out, f32 *in);
    extern void func_001bd5e0(f32 *out, f32 *in);
    extern void func_001ec1c0(u8 *out, u8 *first, u8 *second);
    extern void func_003dcc70(const void *first, const void *second, void *result);
    extern f32 func_0044b868(f32 angle);
    extern f32 fGpffff8118, fGpffff80bc, fGpffff8120, fGpffff8124;
    extern f32 fGpffff8104, fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060, fGpffff8108;

    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    next = (u8 *)func_001d8bc0(*(u8 **)(camera + 0xE0) + 0x98);
    func_001bd560((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    btlUnitGetSphereWorldCenter((BtlUnit *)unit, &actorPosition);
    doubledRadius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    doubledRadius *= 2.0f;
    actorPosition.y = 0.0f + actorPosition.y + fGpffff8118 * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    distance = func_00196040(2, 0, &center, &top, NULL, 1);
    top *= fGpffff8100;
    center.y = top;
    func_001ec1c0((u8 *)&heading, (u8 *)&actorPosition, (u8 *)&center);
    func_003dcb40(&direction, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)&heading);
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
    func_001bd780(&endpoints[0].rot, &direction, &focus, D_0060A0E0);
    halfFov = 0.5f * *(f32 *)(camera + 0xB8);
    if (*(u16 *)(camera + 0x106) == 0) {
        heightDistance = 0.75f * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        heightDistance /= func_0044b868(halfFov);
        minimumDistance = (0.75f * distance) / func_0044b868(halfFov);
    } else {
        heightDistance = fGpffff811c * (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
        heightDistance /= func_0044b868(halfFov);
        minimumDistance = (fGpffff811c * distance) / func_0044b868(halfFov);
    }
    distance = heightDistance + separation;
    distance = cameraSideRadius(distance, minimumDistance);
    func_003dcb40(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&endpoints[0].rot);
    scale = distance * func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
    if (*(u16 *)(camera + 0x106) == 0) {
        target = *(u8 **)(next + 0x30);
        func_001958f0((BtlUnit *)(target), (RwV3d *)((f32 *)&center));
        if (!(50.0f <= center.y)) center.y = 50.0f;
        func_001ec1c0((u8 *)&heading, (u8 *)&actorPosition, (u8 *)&center);
        func_003dcb40(&direction, (const RwV3d *)D_0060A0D0, 1, (const RtQuat *)&heading);
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
        func_001bd780(&endpoints[1].rot, &direction, &focus, D_0060A0E0);
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
        func_001bd5e0((f32 *)&frames[1], (f32 *)&endpoints[0]);
    }
    if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
    if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
    func_001bcd40(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0xE0);
    if (immediate != 0) {
        func_001bab00((u16 *)camera, (f32 *)&frames[1]);
        return;
    }
    func_001bac20((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    func_001bbef0(camera, 0.75f);
}
// FUN_001C88D0
s32 func_001c88d0(u8 *arg0, s32 *arg1, f32 *arg2, u8 *arg3)
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
    product = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    distance1 = fGpffff809c * product;
    product = *(f32 *)(arg0 + 0x8C) * *(f32 *)(arg0 + 0x2C);
    distance2 = 0.5f * (fGpffff809c * product);
    func_00195850(arg0, &frame.valueA0);
    frame.value90 = frame.valueA0;
    frame.value94 = frame.valueA4 + distance2;
    frame.value98 = frame.valueA8;
    func_003e4320((RwV3d *)(u8 *)&frame.value70, (const RwV3d *)D_0060A0D0, (const RwMatrix *)arg3);
    frame.value70 = frame.value70 * distance1;
    frame.value74 = frame.value74 * distance1;
    frame.value78 = frame.value78 * distance1;
    frame.value80 = frame.valueA0 + frame.value70;
    frame.value84 = frame.valueA4 + frame.value74;
    frame.value88 = frame.valueA8 + frame.value78;
    if ((func_001ec4a0(&frame.valueA0, &frame.value68) != 0) &&
        (func_001ec4a0(&frame.value90, &frame.value60) != 0) &&
        (func_001ec4a0(&frame.value80, &frame.value58) != 0)) {
        *arg2 = func_001ec250(&frame.valueA0, arg3 + 0x30);
        distance1 = func_0044e7d8(
            func_0044b310(func_0044dcd8(frame.value64 - frame.value6C)));
        distance2 = func_0044e7d8(
            func_0044b310(func_0044dcd8(frame.value58 - frame.value68)));
        arg1[0] = (s32)(frame.value68 - distance2);
        arg1[1] = (s32)(frame.value6C - distance1);
        arg1[3] = (s32)(2.0f * distance1);
        arg1[2] = (s32)(2.0f * distance2);
        return 1;
    }
    return 0;
}
// FUN_001C8B00
void func_001c8b00(u8 *arg0)
{
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
    u8 *var20;
    u8 *temp19;
    u8 *temp18;
    s32 var17;
    u8 *temp16;

    if (*(u16 *)(arg0 + 0x106) == 0) {
        temp18 = *(u8 **)(func_00457120() + 4) + 0x10;
        temp19 = *(u8 **)((u8 *)func_001d8bc0(*(u8 **)(arg0 + 0xE0) + 0x98) + 0x30);
        temp16 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
        if (func_001c88d0(temp19, &frame.value60, &frame.value88, temp18) != 0) {
            func_001bd530(temp19);
            var17 = 0;
            goto outer_test;
outer_body:
            var20 = *(u8 **)(iGpffffb3ac + (var17 << 3) + 0x178);
            goto inner_test;
inner_body:
            if (((*(s32 *)(var20 + 0x9C) & 8) != 0) &&
                (temp19 != var20) &&
                (temp16 != var20)) {
                if (func_001c88d0(var20, &frame.value70, &frame.value8C, temp18) == 0) {
                    func_001bd530(temp19);
                } else if (!(frame.value8C <= frame.value88)) {
                    func_001bd530(temp19);
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
                    func_001bd4f0(var20);
                    goto range_done;
range_reject:
                    func_001bd530(temp19);
range_done:
                    ;
                }
            }
            var20 = *(u8 **)(var20 + 0xA6C);
inner_test:
            if (var20 != NULL) {
                goto inner_body;
            }
            var17 += 1;
outer_test:
            if (var17 < 2) {
                goto outer_body;
            }
        }
    }
}
/* measured: optimization_level 1 probe for c8cf0 argument order. */
#pragma optimization_level 1
// FUN_001C8CF0
void func_001c8cf0(u8 *arg0)
{
    u8 *temp_16;
    u8 *call_arg0;
    s32 call_arg1;
    s32 call_arg2;

    temp_16 = *(u8 **)(arg0 + 0xE0);
    call_arg0 = temp_16;
    call_arg1 = 0;
    call_arg2 = *(u16 *)(temp_16 + 0x6E);
    *(s16 *)(arg0 + 0x106) = func_001d7f10((s32)call_arg0, call_arg1, call_arg2, 0);
    *(s16 *)(arg0 + 0x104) = func_001d8df0(temp_16 + 0x98);
    *(s32 *)(arg0 + 0x100) = 0;
}
/* measured: close optimization_level after c8cf0. */
#pragma optimization_level 2
// FUN_001C8D50
void func_001c8d50(u8 *arg0)
{
    s32 flag;
    u16 mode;
    u16 type;
    u8 *next;
    u8 *current;

    next = (u8 *)func_001d8bc0(*(u8 **)(arg0 + 0xE0) + 0x98);
    if (*(u16 *)(arg0 + 0x104) == 2) {
        func_001c8b00(arg0);
    }
    if ((next == NULL) ||
        ((current = *(u8 **)(arg0 + 0x100), current == next)) ||
        ((current != NULL) && (*(u16 *)(arg0 + 0x106) != 0))) {
        return;
    }
    if (current == NULL) {
        mode = *(u16 *)(iGpffffb3ac + 0x108);
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
    *(u8 **)(arg0 + 0x100) = next;
    type = *(u16 *)(arg0 + 0x104);
    switch (type) {
    case 2:
        func_001c80f0(arg0, flag);
        return;
    case 1:
    default:
        func_001c79f0(arg0, flag);
        return;
    }
}
/* Produce current and adjusted poses with a limited quaternion angle.
 * The interpolation cache and all vectors are complete objects.
 * b210 -O2:2228 exact bytes and12 zero alignment bytes. */
// FUN_001C8E90
void func_001c8e90(u8 *camera, P4CameraFrame *first, P4CameraFrame *second)
{
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
    extern void func_001bd560(f32 *out, f32 *in);
    extern void func_00195aa0(BtlUnit *unit, BtlUnit *target, RwV3d *out);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0 *first, P4Vec4Holder_001EC2B0 *second);
    extern void func_003dcc70(const void *first, const void *second, void *out);
    extern RtQuat *func_003dc740(RtQuat *quat, const RwV3d *axis, f32 angle, s32 combine);
    extern f32 func_0044b868(f32 angle);
    extern f32 func_003e41b0(f32 *in);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 fabsf(f32 x);
    extern f32 fGpffff8118, fGpffff815c, fGpffff804c, fGpffff8160;
    extern f32 fGpffff8104, fGpffff8054, fGpffff8058, fGpffff805c, fGpffff8060, fGpffff8108;

    action = *(u8 **)(camera + 0xE0);
    actor = *(u8 **)(action + 0x30);
    targetAction = *(u8 **)(action + 0x38);
    target = *(u8 **)(targetAction + 0x30);
    *(u8 **)(camera + 0x124) = targetAction;
    func_001bd560((f32 *)first, (f32 *)(camera + 0x9C));
    actorPosition.x = *(f32 *)(actor + 0xDC);
    actorPosition.y = *(f32 *)(actor + 0x84) * *(f32 *)(actor + 0x2C);
    actorPosition.z = *(f32 *)(actor + 0xE4);
    func_00195aa0((BtlUnit *)target, (BtlUnit *)actor, &targetPosition);
    height = 0.0f + actorPosition.y + p4_cacd0_mul(*(f32 *)(actor + 0x8C), *(f32 *)(actor + 0x2C)) * fGpffff8118;
    height += 0.0f + targetPosition.y + p4_cacd0_mul(*(f32 *)(target + 0x8C), *(f32 *)(target + 0x2C)) * fGpffff8118;
    span = 0.0f + *(f32 *)(actor + 0xE8);
    span += *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
    span += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    targetPosition.y = 0.0f;
    actorPosition.y = 0.0f;
    zero = 0.0f;
    direction.x = *(f32 *)(actor + 0xDC) - targetPosition.x;
    direction.y = *(f32 *)(actor + 0xE0) - zero;
    direction.z = *(f32 *)(actor + 0xE4) - targetPosition.z;
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
    *(f32 *)(camera + 0x10C) = 0.5f * *(f32 *)(actor + 0xE8);
    *(RwV3d *)(camera + 0x100) = focus;
    func_001bd780(&second->rot, &viewDirection, &focus, D_0060A0E0);
    height = 0.0f + span;
    height += *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
    height += *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    angle = func_001ec2b0(&first->rot, &second->rot);
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
        func_003dcb40(&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&limitedRotation);
        viewDirection.x += focus.x;
        viewDirection.y += focus.y;
        viewDirection.z += focus.z;
        func_001bd780(&second->rot, &viewDirection, &focus, D_0060A0E0);
    } else if (angle < fGpffff804c) {
        func_003dc740((RtQuat *)&second->rot, (const RwV3d *)D_0060A0E0, fGpffff8160, 2);
    }
    if (height < 450.0f) height = 450.0f;
    tanHalfFov = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    distance = (0.5f * height) / tanHalfFov;
    func_003dcb40(&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&second->rot);
    direction.y = viewDirection.y;
    RwV3dNormalize(&direction, &direction);
    alignmentDot = viewDirection.x * direction.x + viewDirection.y * direction.y + viewDirection.z * direction.z;
    if (!(alignmentDot < 0.0f)) {
        height = *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
        basePosition = actorPosition;
    } else {
        height = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
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
        horizontalLength = func_003e41b0(xz);
        alternateEye.y = focus.y + (halfHeight * horizontalLength) / distance;
        alternateEye.x = 0.0f + basePosition.x + direction.z * height;
        alternateEye.z = 0.0f + baseZ - direction.x * height;
        func_001bd780(&firstRotation, &alternateEye, &focus, D_0060A0E0);
        firstAngle = func_001ec2b0(&first->rot, &firstRotation);
        alternateEye.x = 0.0f + basePosition.x - direction.z * height;
        alternateEye.z = 0.0f + baseZ + direction.x * height;
        func_001bd780(&secondRotation, &alternateEye, &focus, D_0060A0E0);
        secondAngle = func_001ec2b0(&first->rot, &secondRotation);
        if (firstAngle < secondAngle) second->rot = firstRotation;
        else second->rot = secondRotation;
        func_003dcb40(&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&second->rot);
    }
    viewDirection.x *= distance;
    viewDirection.y *= distance;
    viewDirection.z *= distance;
    tanHalfFov = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
// FUN_001C9750
void func_001c9750(u8 *arg0)
{
    struct {
        P4CameraFrame first;
        P4CameraFrame second;
    } work;

    func_001c8e90(arg0, &work.first, &work.second);
    func_001bac20((u16 *)arg0, (f32 *)&work.first, (f32 *)&work.second, 1);
    func_001bbef0(arg0, fGpffff811c);
}
// FUN_001C97B0
void func_001c97b0(u8 *arg0)
{
    u8 *temp_4;
    f32 value;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if ((temp_4 != NULL) &&
        (*(u16 *)(temp_4 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x124) == *(s32 *)(temp_4 + 0x38)) &&
        ((*(u16 *)(temp_4 + 0x1A) & 1) != 0)) {
        value = *(f32 *)(arg0 + 0x10C);
        func_001bcd40(temp_4, arg0 + 0x9C, (f32 *)(arg0 + 0x100), value, 0xC3);
    }
}
/* Construct an angle-limited camera transition from complete pose geometry. */
// FUN_001C9820
void func_001c9820(u8 *camera, f32 suppliedLimit, s32 reverse, s32 preserveSide)
{
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
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern void func_001bd560(f32 *out, f32 *in);
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
    extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0 *first, P4Vec4Holder_001EC2B0 *second);
    extern f32 func_0044b868(f32 angle);

    angleLimit = suppliedLimit;
    func_001bd560((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    action = *(u8 **)(camera + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorCenter);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetCenter);
    geometry = 0.0f + targetCenter.y + 0.5f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    if (targetCenter.y < 125.0f) targetCenter.y = 125.0f;
    actorRadius = *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
    targetRadius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    direction.x = actorCenter.x - targetCenter.x;
    direction.y = actorCenter.y - targetCenter.y;
    direction.z = actorCenter.z - targetCenter.z;
    distance = func_003e40b0(&direction, &direction);
    scale = fGpffff8128 * distance;
    focus.x = direction.x * scale;
    focus.y = direction.y * scale;
    focus.z = direction.z * scale;
    focus.x += targetCenter.x;
    focus.y += targetCenter.y;
    focus.z += targetCenter.z;
    plane.camera.x = *(f32 *)(camera + 0x9C) - focus.x;
    plane.camera.y = *(f32 *)(camera + 0xA4) - focus.z;
    func_003e41e0((f32 *)&plane.camera, (f32 *)&plane.camera);
    plane.horizontal.x = direction.x;
    plane.horizontal.y = direction.z;
    forwardDot = plane.horizontal.x * plane.camera.x + plane.horizontal.y * plane.camera.y;
    if ((!(forwardDot < 0.0f) || preserveSide == 1) && reverse == 0) {
        viewUnit = actor;
        otherUnit = target;
        center = actorCenter;
        side = 2.5f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        if (geometry <= 400.0f) {
            focus.y = 0.0f + focus.y + fGpffff8098 * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
        } else {
            focus.y = 0.0f + focus.y + fGpffff810c * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
        }
        plane.horizontal.x = direction.z;
        plane.horizontal.y = -direction.x;
        geometry = plane.horizontal.x * plane.camera.x + plane.horizontal.y * plane.camera.y;
        baseY = center.y;
        eye.y = 0.0f + baseY + 0.5f * (*(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C));
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
        func_001bd780(&frames[1].rot, &eye, &focus, D_0060A0E0);
        func_003dcb40(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = center.x;
        projectedCenter.y = baseZ;
        distance = func_001ec3d0((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        distance = 0.0f + distance + 2.0f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
        eye.x = projection.x;
        eye.y = 0.0f + baseY + 0.25f * (*(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C));
        eye.z = projection.y;
        angleScale = fGpffff8110;
        scale = distance / func_0044b868(angleScale * (0.5f * *(f32 *)(camera + 0xB8)));
        direction.x *= scale;
        direction.y *= scale;
        direction.z *= scale;
        if (geometry < 0.0f) {
            side = 2.0f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
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
        side = 1.25f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
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
        func_001bd780(&frames[1].rot, &eye, &focus, D_0060A0E0);
        func_003dcb40(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
        plane.focus.x = focus.x;
        plane.focus.y = focus.z;
        plane.eye.x = eye.x;
        plane.eye.y = eye.z;
        projectedCenter.x = center.x;
        projectedCenter.y = baseZ;
        distance = func_001ec3d0((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
        distance = 0.0f + distance + 1.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        eye.x = projection.x;
        eye.y = baseY;
        eye.z = projection.y;
        angleScale = fGpffff8110;
        scale = distance / func_0044b868(angleScale * (0.5f * *(f32 *)(camera + 0xB8)));
        if (scale < (f32)550) scale = (f32)550;
        direction.x *= scale;
        direction.y *= scale;
        direction.z *= scale;
        if (!(geometry < 0.0f)) {
            side = 0.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
            eye.x = (0.0f + eye.x) - savedDirection.z * side;
            eye.z = 0.0f + eye.z + savedDirection.x * side;
        }
        frames[1].pos.x = eye.x + direction.x;
        frames[1].pos.y = eye.y + direction.y;
        frames[1].pos.z = eye.z + direction.z;
    }
    difference = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    if (angleLimit > 0.0f) {
        angleLimit = p4_cacd0_mul(fGpffff816c, angleLimit);
        if (difference <= angleLimit) goto limitedTransition;
    }
    {
        if (forwardDot < 0.0f) {
            func_001bab00((u16 *)camera, (f32 *)&frames[1]);
            func_003dcb40(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
            direction.x *= 200.0f;
            direction.y *= 200.0f;
            direction.z *= 200.0f;
            frames[0].pos.x = frames[1].pos.x + direction.x;
            frames[0].pos.y = frames[1].pos.y + direction.y;
            frames[0].pos.z = frames[1].pos.z + direction.z;
            frames[0].rot = frames[1].rot;
            if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
            if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
            func_001bac20((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
            func_001bbef0(camera, fGpffff8168);
        } else {
            forwardDot = *(f32 *)(viewUnit + 0x90) * *(f32 *)(viewUnit + 0x2C);
            direction.x = actorCenter.x - targetCenter.x;
            direction.y = actorCenter.y - targetCenter.y;
            direction.z = actorCenter.z - targetCenter.z;
            func_003e40b0(&direction, &direction);
            eye.y = 0.0f + baseY + fGpffff8170 * (*(f32 *)(viewUnit + 0x8C) * *(f32 *)(viewUnit + 0x2C));
            if (!(geometry < 0.0f)) {
                eye.x = (0.0f + center.x) - direction.z * forwardDot;
                eye.z = 0.0f + baseZ + direction.x * forwardDot;
            } else {
                eye.x = 0.0f + center.x + direction.z * forwardDot;
                eye.z = (0.0f + baseZ) - direction.x * forwardDot;
            }
            func_001bd780(&frames[0].rot, &eye, &focus, D_0060A0E0);
            func_003dcb40(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[0].rot);
            plane.focus.x = focus.x;
            plane.focus.y = focus.z;
            plane.eye.x = eye.x;
            plane.eye.y = eye.z;
            projectedCenter.x = center.x;
            projectedCenter.y = baseZ;
            func_001ec3d0((u8 *)&plane.focus, (u8 *)&plane.eye, (u8 *)&projectedCenter, (u8 *)&projection);
            eye.x = projection.x;
            eye.y = 0.0f + baseY + fGpffff8170 * (*(f32 *)(viewUnit + 0x8C) * *(f32 *)(viewUnit + 0x2C));
            eye.z = projection.y;
            tangent = func_0044b868(angleScale * (0.5f * *(f32 *)(camera + 0xB8)));
            scale = (4.0f * (*(f32 *)(viewUnit + 0x90) * *(f32 *)(viewUnit + 0x2C))) / tangent;
            direction.x *= scale;
            direction.y *= scale;
            direction.z *= scale;
            frames[0].pos.x = eye.x + direction.x;
            frames[0].pos.y = eye.y + direction.y;
            frames[0].pos.z = eye.z + direction.z;
            if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
            if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
            func_001bac20((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
            func_001bbef0(camera, fGpffff8168);
        }
        actorRadius = actorRadius > targetRadius ? actorRadius : targetRadius;
        func_001bcd40(*(u8 **)(camera + 0xE0), otherUnit + 4, (f32 *)&frames[1], actorRadius, 3);
        return;
    }
limitedTransition:
    actorRadius = actorRadius > targetRadius ? actorRadius : targetRadius;
    func_001bcd40(*(u8 **)(camera + 0xE0), otherUnit + 4, (f32 *)&frames[1], actorRadius, 0xC3);
    if (frames[0].pos.y < 25.0f) frames[0].pos.y = 25.0f;
    if (frames[1].pos.y < 25.0f) frames[1].pos.y = 25.0f;
    difference = func_001ec2b0(&frames[0].rot, &frames[1].rot);
    forwardDot = 1.25f;
    if (!(difference <= 0.0f)) {
        scale = angleLimit / difference;
        if (!(scale <= 1.0f)) forwardDot = scale * fGpffff80cc;
        else forwardDot = fGpffff80cc;
        if (!(forwardDot <= 1.25f)) forwardDot = 1.25f;
    }
    func_001bac20((u16 *)camera, (f32 *)&frames[0], (f32 *)&frames[1], 1);
    func_001bbef0(camera, forwardDot);
}
// FUN_001CA550
void func_001ca550(u8 *arg0) {
    func_001c9820(arg0, 50.0f, 0, 0);
}
// FUN_001CA590
void func_001ca590(u8 *camera, f32 angle, f32 duration)
{
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
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 fGpffff8118;
    extern f32 func_003e41e0(f32 *out, f32 *in);
    extern f32 func_003e41b0(f32 *in);
    extern f32 fabsf(f32 x);
    extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0* first, P4Vec4Holder_001EC2B0* second);
    extern f32 func_0044b868(f32 angle);
    extern void func_001bd560(f32 *out, f32 *in);

    action = *(u8 **)(camera + 0xE0);
    actorUnit = *(u8 **)(action + 0x30);
    targetUnit = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_001bd560((f32 *)&frames[0], (f32 *)(camera + 0x9C));
    actorPosition.x = *(f32 *)(actorUnit + 0xDC);
    actorPosition.y = *(f32 *)(actorUnit + 0x84) * *(f32 *)(actorUnit + 0x2C);
    actorPosition.z = *(f32 *)(actorUnit + 0xE4);
    btlUnitGetSphereWorldCenter((BtlUnit *)targetUnit, &targetPosition);
    height = (0.0f + actorPosition.y + p4_cacd0_mul(*(f32 *)(actorUnit + 0x8C), *(f32 *)(actorUnit + 0x2C)) * fGpffff8118);
    height += (0.0f + targetPosition.y + p4_cacd0_mul(*(f32 *)(targetUnit + 0x8C), *(f32 *)(targetUnit + 0x2C)) * fGpffff8118);
    extent = 0.0f + *(f32 *)(actorUnit + 0xE8);
    extent += *(f32 *)(actorUnit + 0x90) * *(f32 *)(actorUnit + 0x2C);
    extent += *(f32 *)(targetUnit + 0x90) * *(f32 *)(targetUnit + 0x2C);
    targetPosition.y = 0.0f;
    actorPosition.y = 0.0f;
    zero = 0.0f;
    direction.x = *(f32 *)(actorUnit + 0xDC) - targetPosition.x;
    direction.y = *(f32 *)(actorUnit + 0xE0) - zero;
    direction.z = *(f32 *)(actorUnit + 0xE4) - targetPosition.z;
    RwV3dNormalize(&direction, &direction);
    focus.x = direction.x * (0.25f * extent);
    focus.y = direction.y * (0.25f * extent);
    focus.z = direction.z * (0.25f * extent);
    focus.x = focus.x + targetPosition.x;
    focus.y = focus.y + targetPosition.y;
    focus.z = focus.z + targetPosition.z;
    halfHeight = 0.5f * height;
    focus.y = halfHeight;
    *(f32 *)(camera + 0x10C) = 0.5f * *(f32 *)(actorUnit + 0xE8);
    *(RwV3d *)(camera + 0x100) = focus;
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
        func_003e0870(&matrix, (const RwV3d *)D_0060A0E0, angle, 0);
    } else {
        func_003e0870(&matrix, (const RwV3d *)D_0060A0E0, -angle, 0);
    }
    func_003e4320(&viewDirection, &viewDirection, &matrix);
    viewDirection.x = viewDirection.x + focus.x;
    viewDirection.y = viewDirection.y + focus.y;
    viewDirection.z = viewDirection.z + focus.z;
    func_001bd780(&frames[1].rot, &viewDirection, &focus, D_0060A0E0);
    if (extent < 400.0f) {
        extent = 400.0f;
    }
    tanHalfFov = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    distance = (0.5f * extent) / tanHalfFov;
    func_003dcb40((RwV3d *)&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
    direction.y = viewDirection.y;
    RwV3dNormalize(&direction, &direction);
    alignmentDot = viewDirection.x * direction.x + viewDirection.y * direction.y + viewDirection.z * direction.z;
    if (!(alignmentDot < 0.0f)) {
        extent = *(f32 *)(actorUnit + 0x90) * *(f32 *)(actorUnit + 0x2C);
        basePosition = actorPosition;
    } else {
        extent = *(f32 *)(targetUnit + 0x90) * *(f32 *)(targetUnit + 0x2C);
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
        horizontalLength = func_003e41b0(xz);
        alternateEye.y = focus.y + (halfHeight * horizontalLength) / distance;
        alternateEye.x = 0.0f + basePosition.x + direction.z * extent;
        alternateEye.z = 0.0f + baseZ - direction.x * extent;
        func_001bd780(&firstRotation, &alternateEye, &focus, D_0060A0E0);
        firstAngle = func_001ec2b0(&frames[0].rot, &firstRotation);
        alternateEye.x = 0.0f + basePosition.x - direction.z * extent;
        alternateEye.z = 0.0f + baseZ + direction.x * extent;
        func_001bd780(&secondRotation, &alternateEye, &focus, D_0060A0E0);
        secondAngle = func_001ec2b0(&frames[0].rot, &secondRotation);
        if (firstAngle < secondAngle) {
            frames[1].rot = firstRotation;
        } else {
            frames[1].rot = secondRotation;
        }
        func_003dcb40((RwV3d *)&viewDirection, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&frames[1].rot);
    }
    viewDirection.x = viewDirection.x * distance;
    viewDirection.y = viewDirection.y * distance;
    viewDirection.z = viewDirection.z * distance;
    finalTanHalfFov = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
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
    func_001bac20((u16 *)camera, (f32 *)&frames[0].pos, (f32 *)&frames[1].pos, 1);
    func_001bbef0(camera, duration);
}
/* 1052/1056 bytes; 19 resolved relocations; four zero alignment bytes.
 * Build the current pose plus three orbit keys with a halfword frame index. */
// FUN_001CACD0
void func_001cacd0(u8 *arg0, f32 fparg0, f32 fparg1)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Quat {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };
    struct Frame {
        struct Vec3 pos;
        struct Quat rot;
    };
    struct Work {
        struct Frame frames[4];
        u8 matrix[0x40];
        f32 xzA[2];
        f32 xzB[2];
        struct Vec3 unit;
        u8 pad12C[4];
        struct Vec3 delta;
        u8 pad13C[4];
        struct Vec3 rotated;
        u8 pad14C[4];
        struct Vec3 scaled;
        u8 pad15C[4];
        struct Vec3 diff;
        u8 pad16C[4];
    } work;
    u8 *action;
    u8 *s0;
    u8 *s2;
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
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);
    extern void func_001bb3d0(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, u16 arg5);
    extern void func_001bd560(f32 *arg0, f32 *arg1);

    action = *(u8 **)(arg0 + 0xE0);
    s0 = *(u8 **)(action + 0x30);
    s2 = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_001bd560((f32 *)&work.frames[0], (f32 *)(arg0 + 0x9C));
    prod = *(f32 *)(s0 + 0x84) * *(f32 *)(s0 + 0x2C);
    func_00195850(s2, (f32 *)&work.unit);
    height = (0.0f + prod + p4_cacd0_mul(*(f32 *)(s0 + 0x8C), *(f32 *)(s0 + 0x2C)) * fGpffff8118);
    height += (0.0f + work.unit.y + (*(f32 *)(s2 + 0x8C) * *(f32 *)(s2 + 0x2C)) * fGpffff8118);
    work.unit.y = 0.0f;
    zero = 0.0f;
    work.diff.x = *(f32 *)(s0 + 0xDC) - work.unit.x;
    work.diff.y = *(f32 *)(s0 + 0xE0) - zero;
    work.diff.z = *(f32 *)(s0 + 0xE4) - work.unit.z;
    len = func_003e40b0((RwV3d *)&work.diff, (const RwV3d *)&work.diff);
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
    *(f32 *)(arg0 + 0x10C) = 0.5f * *(f32 *)(s0 + 0xE8);
    *(struct Vec3 *)(arg0 + 0x100) = work.scaled;
    work.delta.x = work.frames[0].pos.x - work.scaled.x;
    work.delta.y = work.frames[0].pos.y - work.scaled.y;
    work.delta.z = work.frames[0].pos.z - work.scaled.z;
    angle = fparg0 / 3.0f;
    step = angle;
    i = 1;
    while (i < 4) {
        if (!(dot < 0.0f)) {
            func_003e0870((RwMatrix *)work.matrix, (const RwV3d *)D_0060A0E0, angle, 0);
        } else {
            func_003e0870((RwMatrix *)work.matrix, (const RwV3d *)D_0060A0E0, -angle, 0);
        }
        func_003e4320((RwV3d *)&work.rotated, (const RwV3d *)&work.delta, (const RwMatrix *)work.matrix);
        base = &work.frames[(u16)i];
        base->pos.x = work.rotated.x + work.scaled.x;
        base->pos.y = work.rotated.y + work.scaled.y;
        base->pos.z = work.rotated.z + work.scaled.z;
        func_001bd780(&base->rot, &base->pos, &work.scaled, D_0060A0E0);
        angle = angle + step;
        i++;
    }
    func_001bb3d0(arg0, &work.frames[0], &work.frames[1], &work.frames[2], &work.frames[3], 1);
    func_001bbef0(arg0, fparg1);
}
// FUN_001CB0F0
void func_001cb0f0(u8 *arg0)
{
    u8 *temp_5;
    u8 *temp_6;
    u16 temp_5_2;

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if (*(u8 *)(*(u8 **)(temp_5 + 0x30) + 0xA2) != 0) {
        return;
    }
    *(s32 *)(arg0 + 0x128) = *(s32 *)(temp_5 + 0x38);
    temp_6 = iGpffffb3ac;
    if ((*(s32 *)(temp_6 + 0xC) & 0x200000) == 0) {
        temp_5_2 = *(u16 *)(temp_6 + 0x10E);
        switch (temp_5_2) {
        case 0:
            func_001ca590(arg0, 40.0f, 2.0f);
            return;
        case 1:
            func_001cacd0(arg0, 100.0f, 3.0f);
            return;
        }
    } else {
        temp_5_2 = *(u16 *)(temp_6 + 0x10E);
        switch (temp_5_2) {
        case 0:
            func_001ca590(arg0, 20.0f, 2.0f);
            return;
        case 1:
            func_001cacd0(arg0, 50.0f, 3.0f);
            return;
        }
    }
}
// FUN_001CB200
void func_001cb200(u8 *arg0)
{
    s32 temp_5;
    u16 temp_3;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    temp_5 = 0;
    if ((temp_4 != NULL) &&
        (*(u16 *)(temp_4 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x128) == *(s32 *)(temp_4 + 0x38)) &&
        ((temp_5 = *(u16 *)(temp_4 + 0x1A) & 1, temp_5 != 0)) &&
        (*(u8 *)(*(u8 **)(temp_4 + 0x30) + 0xA2) == 0)) {
        temp_3 = *(u16 *)(iGpffffb3ac + 0x10E);
        switch (temp_3) {
        case 0:
            if ((temp_4 != NULL) && (temp_5 != 0)) {
                func_001bcd40(temp_4, arg0 + 0x9C, (f32 *)(arg0 + 0x100),
                              *(f32 *)(arg0 + 0x10C), 0xC3);
                return;
            }
            break;
        case 1:
        default:
            if ((temp_4 != NULL) && (temp_5 != 0)) {
                func_001bcd40(temp_4, arg0 + 0x9C, (f32 *)(arg0 + 0x100),
                              *(f32 *)(arg0 + 0x10C), 0xC3);
            }
            break;
        }
    }
}
// FUN_001CB2E0
void func_001cb2e0(u8 *arg0)
{
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    value = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA4);
    flag_offset = (func_004bd050(0) & 1) * 0xF4;
    index_offset = (value & 0xFFFF) * 0x1E8;
    target = (u8 *)&D_005F7CA0 + index_offset;
    func_001bdd80(arg0, target + flag_offset, 2);
}
// FUN_001CB380
void func_001cb380(void) {
    func_001bdeb0();
}
// FUN_001CB3A0
void func_001cb3a0(u8 *arg0)
{
    u8 *temp;
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    temp = *(u8 **)(arg0 + 0xE0);
    value = *(u16 *)(*(u8 **)(temp + 0x30) + 0xA4);
    func_001b73f0(*(u8 **)(temp + 0x30));
    flag_offset = (func_004bd050(0) & 1) * 0xF4;
    index_offset = ((value & 0xFFFF) - 2) * 0x1E8;
    target = (u8 *)&D_005F91A0 + index_offset;
    func_001bdd80(arg0, target + flag_offset, 2);
}
// FUN_001CB440
void func_001cb440(void) {
    func_001bdeb0();
}
// FUN_001CB460
void func_001cb460(u8 *arg0)
{
    u16 value;
    s32 flag_offset;
    s32 index_offset;
    u8 *target;

    value = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA4);
    if (func_001f0ff0(*(u8 **)(arg0 + 0xE0)) != 0) {
        flag_offset = (func_004bd050(0) & 1) * 0xF4;
        index_offset = ((value & 0xFFFF) - 2) * 0x1E8;
        target = (u8 *)&D_005FA2D0 + index_offset;
        func_001bdd80(arg0, target + flag_offset, 2);
        func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 3);
    } else {
        func_001c2ee0(arg0, 0, 1);
    }
}
// FUN_001CB540
void func_001cb540(u8 *arg0)
{
    u8 *temp;

    if (func_001f0ff0(*(u8 **)(arg0 + 0xE0)) != 0) {
        func_001bdeb0(arg0);
        goto done;
    }
    temp = *(u8 **)(arg0 + 0xE0);
    if (temp == NULL)
        goto done;
    if (*(s32 *)(arg0 + 0xD8) != 0)
        goto done;
    if (temp == NULL)
        goto done;
    if ((*(u16 *)(temp + 0x1A) & 1) == 0)
        goto done;
    if (*(s32 *)(arg0 + 0xDC) == 0) {
        func_001bcd40(temp, NULL, NULL, 0.0f, 0x11);
    }
    if (func_001bc560(arg0, *(u8 **)(arg0 + 0x12C)) != 0) {
        func_0019de70(*(BtlUnitStateWork **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
    }
done:
    ;
}
/* 840/848 bytes; 27 resolved relocations; eight zero alignment bytes.
   Build both position/quaternion keys before clamping their heights. */
// FUN_001CB610
void func_001cb610(u8 *arg0)
{
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
    u8 *temp17;
    f32 angleScale;
    f32 rotationAngle;
    f32 y;

    temp17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x38);
    temp17 = *(u8 **)(temp17 + 0x30);
    func_001959d0((BtlUnit *)temp17, (RwV3d *)&work.center.x);
    work.center.y = 0.0f + work.center.y +
                    DAT_00761278 *
                    (*(f32 *)(temp17 + 0x8C) *
                     *(f32 *)(temp17 + 0x2C));
    work.center.y = work.center.y + 10.0f;
    func_003dcb40((RwV3d *)&work.direction, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)(temp17 + 0x1C));
    work.scaled.x = work.direction.x * 200.0f;
    work.scaled.y = work.direction.y * 200.0f;
    work.scaled.z = work.direction.z * 200.0f;
    y = work.center.y + work.scaled.y;
    y = y + 10.0f;
    work.direction.x = (work.center.x + work.scaled.x) - work.center.x;
    work.direction.y = y - work.center.y;
    work.direction.z = (work.center.z + work.scaled.z) - work.center.z;
    func_003e40b0((RwV3d *)&work.direction, (const RwV3d *)&work.direction);
    rotationAngle = 30.0f;
    func_003e0870((RwMatrix *)&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * -rotationAngle, 0);
    func_003e4320((RwV3d *)&work.scaled, (const RwV3d *)&work.direction, (const RwMatrix *)&work.rotation);
    angleScale = 115.0f /
                 tanf(fGpffff8110 *
                      (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.firstPosition.x = work.center.x + work.scaled.x;
    work.firstPosition.y = work.center.y + work.scaled.y;
    work.firstPosition.z = work.center.z + work.scaled.z;
    func_001bd780(work.firstView, &work.firstPosition, &work.center,
                  D_0060A0E0);
    func_003e0870((RwMatrix *)&work.rotation, (const RwV3d *)D_0060A0E0, 15.0f, 0);
    func_003e4320((RwV3d *)&work.scaled, (const RwV3d *)&work.direction, (const RwMatrix *)&work.rotation);
    angleScale = 165.0f /
                 tanf(fGpffff8110 *
                      (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled.x = work.scaled.x * angleScale;
    work.scaled.y = work.scaled.y * angleScale;
    work.scaled.z = work.scaled.z * angleScale;
    work.secondPosition.x = work.center.x + work.scaled.x;
    work.secondPosition.y = work.center.y + work.scaled.y;
    work.secondPosition.z = work.center.z + work.scaled.z;
    func_001bd780(work.secondView, &work.secondPosition, &work.center,
                  D_0060A0E0);
    if (work.firstPosition.y < 25.0f) {
        work.firstPosition.y = 25.0f;
    }
    if (work.secondPosition.y < 25.0f) {
        work.secondPosition.y = 25.0f;
    }
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 3);
    func_001bac20((u16 *)arg0, (f32 *)&work.firstPosition, (f32 *)&work.secondPosition, 1);
    func_001bbef0(arg0, 2.0f);
}
// FUN_001CB960
void func_001cb960(void) {}
/* Frame the two animation-bound centers and retain the selected side
 * between updates. Two complete poses feed the spline submission.
 * b210 -O2:1540 exact bytes,12 zero alignment bytes; comparison
 * lowering is documented in Camera_001cb970_20260920.md. */
// FUN_001CB970
void func_001cb970(u8 *camera, f32 duration, s32 initialize)
{
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
    extern f32 func_001ec2b0(P4Vec4Holder_001EC2B0 *first, P4Vec4Holder_001EC2B0 *second);
    extern f32 func_001ec3d0(u8 *first, u8 *second, u8 *point, u8 *out);
    extern f32 func_0044b868(f32 angle);
    extern void func_001bd5e0(f32 *out, f32 *in);
    extern void func_001bd560(f32 *out, f32 *in);
    extern f32 fGpffff80dc;
    extern f32 fGpffff8128;
    extern f32 fGpffff8138;

    action = *(u8 **)(camera + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    func_001959d0((BtlUnit *)actor, &actorPosition);
    func_001959d0((BtlUnit *)target, &targetPosition);
    direction.x = actorPosition.x - targetPosition.x;
    direction.y = actorPosition.y - targetPosition.y;
    direction.z = actorPosition.z - targetPosition.z;
    length = RwV3dNormalize(&direction, &direction);
    geometry.horizontal[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    geometry.horizontal[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);
    geometry.perpendicular[0] = direction.x;
    geometry.perpendicular[1] = direction.z;
    firstDot = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];
    if (initialize != 0) {
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
            *(s32 *)(camera + 0x104) = 0;
        } else {
            *(s32 *)(camera + 0x104) = firstDot >= 0.0f;
        }
    }
    if (*(s32 *)(camera + 0x104) == 1) {
        selectedUnit = actor;
        otherUnit = target;
        basePosition = actorPosition;
        sideRadius = 1.25f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
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
        sideRadius = fGpffff8128 * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
        radiusFactor = 2.5f;
        actorPosition.y = (actorPosition.y + 0.0f) - 0.25f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
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
        *(s32 *)(camera + 0x108) = secondDot >= 0.0f;
    }
    if (*(s32 *)(camera + 0x108) == 1) {
        eye.x = (basePosition.x + 0.0f) + direction.z * sideRadius;
        baseZ = basePosition.z;
        eye.z = (baseZ + 0.0f) - direction.x * sideRadius;
    } else {
        eye.x = (basePosition.x + 0.0f) - direction.z * sideRadius;
        baseZ = basePosition.z;
        eye.z = (baseZ + 0.0f) + direction.x * sideRadius;
    }
    func_001bd780(&poses[1].rot, &eye, &focus, D_0060A0E0);
    func_003dcb40(&direction, (const RwV3d *)D_0060A100, 1, (const RtQuat *)&poses[1].rot);
    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    projectedRadius = func_001ec3d0((u8 *)geometry.focusXZ, (u8 *)geometry.eyeXZ, (u8 *)baseXZ, (u8 *)projectedXZ);
    projectedRadius = projectedRadius + 0.0f + radiusFactor * (*(f32 *)(selectedUnit + 0x90) * *(f32 *)(selectedUnit + 0x2C));
    eye.x = projectedXZ[0];
    eye.y = baseY;
    eye.z = projectedXZ[1];
    tanHalfFov = func_0044b868(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    distance = projectedRadius / tanHalfFov;
    if (distance < 500.0f) distance = 500.0f;
    direction.x *= distance;
    direction.y *= distance;
    direction.z *= distance;
    poses[1].pos.x = eye.x + direction.x;
    poses[1].pos.y = eye.y + direction.y;
    poses[1].pos.z = eye.z + direction.z;
    if (poses[1].pos.y < 12.5f) poses[1].pos.y = 12.5f;
    func_001bd560((f32 *)&poses[0], (f32 *)(camera + 0x9C));
    if (initialize != 0) {
        if (!(func_001ec2b0(&poses[0].rot, &poses[1].rot) <= fGpffff80dc)) {
            func_001bd5e0((f32 *)&poses[0], (f32 *)&poses[1]);
            mode = 3;
        } else {
            mode = 0x83;
        }
        func_001bcd40(*(u8 **)(camera + 0xE0), otherUnit + 4, (f32 *)&poses[1], 50.0f, mode);
    }
    func_001bac20((u16 *)camera, (f32 *)&poses[0], (f32 *)&poses[1], 1);
    func_001bbef0(camera, duration);
}
// FUN_001CBF80
void func_001cbf80(u8 *arg0) {
    *(s16 *)(arg0 + 0x10E) =
        func_001991c0(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30), 4, 1.0f);
    *(s32 *)(arg0 + 0x100) = *(s32 *)(*(u8 **)(arg0 + 0xE0) + 0x38);
    *(s16 *)(arg0 + 0x10C) = 0;
}
/* measured: opt_propagation off probe for ce470 mixed-load ordering. */
#pragma opt_propagation off
// FUN_001CE470
void func_001ce470(u8 *arg0)
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

    if (*(s32 *)(arg0 + 0xD8) == 0) {
        func_001bd780(&frame.value1C,
                      (f32 *)D_00607DD0, D_00607DF0, D_0060A0E0);
        func_001c_copy_pair((s64 *)&frame.value10,
                            &frame.value18,
                            (s64 *)D_00607DD0,
                            (f32 *)D_00607DD8);
        func_001bd780(&frame.value38,
                      D_00607E10, D_00607E30, D_0060A0E0);
        vector = &frame.value2C;
        *(struct Vec3 *)&frame.value2C =
            *(struct Vec3 *)D_00607E10;
        func_001bac20((u16 *)(iGpffffb3ac + 0x24), &frame.value10, vector, 1);
        func_001bbef0(iGpffffb3ac + 0x24, fGpffff819c);
        return;
    }
    if (*(s32 *)(arg0 + 0xD8) == 0x25) {
        func_001bd780(&frame.value1C,
                      D_00607DDC, D_00607DFC, D_0060A0E0);
        *(struct Vec3 *)&frame.value10 =
            *(struct Vec3 *)D_00607DDC;
        func_001bd780(&frame.value38,
                      D_00607E1C, D_00607E3C, D_0060A0E0);
        vector = &frame.value2C;
        *(struct Vec3 *)&frame.value2C =
            *(struct Vec3 *)D_00607E1C;
        func_001bac20((u16 *)(iGpffffb3ac + 0x24), &frame.value10, vector, 1);
        func_001bbef0(iGpffffb3ac + 0x24, fGpffff809c);
    }
}
/* measured: close ce470 opt_propagation off probe. */
#pragma opt_propagation on
// FUN_001CE620
void func_001ce620(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    struct Frame {
        u8 matrix[0x40];
        f32 result[3];
        f32 quat[4];
        u8 pad5C[4];
        f32 transformed[3];
    } frame;
    f32 scale;

    if (*(s32 *)(arg0 + 0x120) != 0) {
        *(f32 *)(arg0 + 0x11C) =
            func_00196040(3, 0, (RwV3d *)(arg0 + 0x104), 0, 0, 1);
        *(f32 *)(arg0 + 0x108) = 0.0f;
        *(s32 *)(arg0 + 0x120) = 0;
    }
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0D0, arg1, 0);
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0E0,
                     *(f32 *)(arg0 + 0x100), 2);
    func_003e4320((RwV3d *)frame.transformed, (const RwV3d *)(&D_0060A0F0), (const RwMatrix *)frame.matrix);
    scale = (*(f32 *)(arg0 + 0x11C) * arg3) /
            tanf(fGpffff8110 *
                          (0.5f * *(f32 *)(arg0 + 0xB8)));
    frame.transformed[0] *= scale;
    frame.transformed[1] *= scale;
    frame.transformed[2] *= scale;
    frame.result[0] = frame.transformed[0] + *(f32 *)(arg0 + 0x104);
    frame.result[1] = frame.transformed[1] + *(f32 *)(arg0 + 0x108);
    frame.result[2] = frame.transformed[2] + *(f32 *)(arg0 + 0x10C);
    func_001bd780(frame.quat, frame.result, arg0 + 0x104,
                  D_0060A0E0);
    if (frame.result[1] < 25.0f) {
        frame.result[1] = 25.0f;
    }
    *(f32 *)(arg0 + 0x100) += arg2;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
        func_001bc3a0(frame.result, frame.result);
    }
    func_001bab00((u16 *)(arg0), (f32 *)(frame.result));
}
/* measured probe: optimization_level 1 for 001CE7F0 register coloring. */
#pragma optimization_level 1
// FUN_001CE7F0
void func_001ce7f0(u8 *arg0) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = func_00231d70(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    *(f32 *)(arg0 + 0x100) = value;
    *(s32 *)(arg0 + 0x120) = 1;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}
/* measured probe: close optimization_level 1 for 001CE7F0. */
#pragma optimization_level 2
// FUN_001CE880
void func_001ce880(u8 *arg0) {
    func_001ce620(arg0, -17.5f, 0.25f, 0.75f);
}
// FUN_001CE8C0
void func_001ce8c0(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
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

    if (*(s32 *)(arg0 + 0x120) != 0) {
        func_00196040(2, 1, (RwV3d *)(frame.target), 0, 0, 1);
        *(f32 *)(arg0 + 0x11C) =
            func_00196040(3, 0, (RwV3d *)(arg0 + 0x104), 0, 0, 2);
        *(f32 *)(arg0 + 0x108) = 0.0f;
        frame.diff[0] = *(f32 *)(arg0 + 0x104) - frame.target[0];
        frame.diff[1] = *(f32 *)(arg0 + 0x108) - frame.target[1];
        frame.diff[2] = *(f32 *)(arg0 + 0x10C) - frame.target[2];
        scale = fGpffff8100 * func_003e40b0((RwV3d *)frame.diff, (const RwV3d *)frame.diff);
        frame.diff[0] *= scale;
        frame.diff[1] *= scale;
        frame.diff[2] *= scale;
        *(f32 *)(arg0 + 0x104) = frame.target[0] + frame.diff[0];
        *(f32 *)(arg0 + 0x108) = frame.target[1] + frame.diff[1];
        *(f32 *)(arg0 + 0x10C) = frame.target[2] + frame.diff[2];
        *(f32 *)(arg0 + 0x108) = frame.target[1];
        *(f32 *)(arg0 + 0x110) =
            *(f32 *)(arg0 + 0x104) - frame.target[0];
        *(f32 *)(arg0 + 0x114) =
            *(f32 *)(arg0 + 0x108) - frame.target[1];
        *(f32 *)(arg0 + 0x118) =
            *(f32 *)(arg0 + 0x10C) - frame.target[2];
        func_003e40b0((RwV3d *)(arg0 + 0x110),
                      (const RwV3d *)(arg0 + 0x110));
        *(s32 *)(arg0 + 0x120) = 0;
    }
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0D0, arg1, 0);
    func_001c_rotate((RwMatrix *)frame.matrix, (const RwV3d *)D_0060A0E0,
                     *(f32 *)(arg0 + 0x100), 2);
    func_003e4320((RwV3d *)frame.diff, (const RwV3d *)(arg0 + 0x110), (const RwMatrix *)frame.matrix);
    if (*(f32 *)(arg0 + 0x11C) < 600.0f) {
        *(f32 *)(arg0 + 0x11C) = 600.0f;
    }
    scale = (*(f32 *)(arg0 + 0x11C) * arg3) /
            tanf(fGpffff8110 *
                          (0.5f * *(f32 *)(arg0 + 0xB8)));
    frame.diff[0] *= scale;
    frame.diff[1] *= scale;
    frame.diff[2] *= scale;
    frame.result[0] = frame.diff[0] + *(f32 *)(arg0 + 0x104);
    frame.result[1] = frame.diff[1] + *(f32 *)(arg0 + 0x108);
    frame.result[2] = frame.diff[2] + *(f32 *)(arg0 + 0x10C);
    func_001bd780(frame.quat, frame.result, arg0 + 0x104,
                  D_0060A0E0);
    if (frame.result[1] < 25.0f) {
        frame.result[1] = 25.0f;
    }
    *(f32 *)(arg0 + 0x100) += arg2;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
        func_001bc3a0(frame.result, frame.result);
    }
    func_001bab00((u16 *)(arg0), (f32 *)(frame.result));
}
// FUN_001CEBA0
void func_001ceba0(u8 *arg0)
{
    s32 index;
    s32 check;
    u16 index16;
    s32 count;
    u8 *current;

    *(s32 *)(arg0 + 0x100) = 0xC1900000;
    *(s32 *)(arg0 + 0x120) = 1;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
    if (*(u16 *)(arg0 + 0xD0) == 7) {
        current = *(u8 **)(iGpffffb3ac + 0x174);
        while (current != NULL) {
            if (*(s32 *)(iGpffffb3ac + 0x170) != (s32)current) {
                if ((*(u16 *)(current + 0x1A) & 1) != 0) {
                    if (*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) != 1) {
                        index = 0;
                        count = *(u16 *)(iGpffffb3ac + 0xC58);
                        goto loop_test;
loop_body:
                        index16 = (u16)index;
                        if (*(u8 **)(iGpffffb3ac + 0xC48 +
                                     index16 * 4) == current) {
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
                            func_00194fa0(*(u8 **)(current + 0x30), 2,
                                          count, iGpffffb3ac, index);
                            *(s8 *)(*(u8 **)(current + 0x30) + 0x37) = 0;
                        }
                    }
                }
            }
            current = *(u8 **)(current + 0x450);
        }
    }
}
// FUN_001CECB0
void func_001cecb0(u8 *arg0) {
    func_001ce8c0(arg0, -16.0f, fGpffff8198, fGpffff80fc);
}
// FUN_001CECE0
void func_001cece0(u8 *arg0)
{
    struct Frame {
        u8 first[0x1C];
        f32 result[3];
        u8 second[0x28];
        f32 source[4];
        f32 target[4];
    } frame;
    f32 scale;
    f32 length;
    u8 *work;

    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_001bd560(frame.first, arg0 + 0x9C);
    scale = func_00196040(3, 1, (RwV3d *)(frame.target), 0, 0, 1);
    frame.target[1] = 0.0f;
    func_001958f0((BtlUnit *)(work), (RwV3d *)(frame.source));
    frame.source[1] +=
        (*(f32 *)(work + 0x8C) * *(f32 *)(work + 0x2C)) * 0.5f;
    func_001bd780(frame.second, frame.source, frame.target, D_0060A0E0);
    scale /= tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    *(f32 *)(frame.second + 0x18) = frame.source[0] - frame.target[0];
    *(f32 *)(frame.second + 0x1C) = frame.source[1] - frame.target[1];
    *(f32 *)(frame.second + 0x20) = frame.source[2] - frame.target[2];
    length = func_003e40b0((RwV3d *)(frame.second + 0x18),
                           (const RwV3d *)(frame.second + 0x18));
    length += (*(f32 *)(work + 0x90) * *(f32 *)(work + 0x2C) * 5.0f) /
              tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    scale = (scale > length) ? scale : length;
    *(f32 *)(frame.second + 0x18) *= scale;
    *(f32 *)(frame.second + 0x1C) *= scale;
    *(f32 *)(frame.second + 0x20) *= scale;
    frame.result[0] = *(f32 *)(frame.second + 0x18) + frame.target[0];
    frame.result[1] = *(f32 *)(frame.second + 0x1C) + frame.target[1];
    frame.result[2] = *(f32 *)(frame.second + 0x20) + frame.target[2];
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0)
        func_001bc3a0(frame.result, frame.result);
    func_001bac20((u16 *)arg0, (f32 *)frame.first, frame.result, 1);
    func_001bbef0(arg0, 1.0f);
}
/* measured probe: optimization_level 1 preserves 001CEF20 low-bit OR coloring. */
#pragma optimization_level 1
// FUN_001CEF20
void func_001cef20(u8 *arg0) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = func_00231d70(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    *(f32 *)(arg0 + 0x100) = value;
    *(s32 *)(arg0 + 0x120) = 1;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}
/* measured: closes optimization_level 1 for 001CEF20. */
#pragma optimization_level 2
// FUN_001CEFB0
void func_001cefb0(u8 *arg0) {
    func_001ce620(arg0, -10.0f, 0.125f, fGpffff809c);
}
// FUN_001CEFF0
void func_001ceff0(void) {
    func_001b73f0(NULL);
    func_004b3110(5);
}
// FUN_001CF020
void func_001cf020(u8 *arg0) {
    P4CameraFrame frame;

    func_001c6f40(arg0, 0, 0, NULL, &frame);
    func_001bab00((u16 *)(arg0), (f32 *)(&frame));
}
// FUN_001CF070
void func_001cf070(u8 *arg0, u8 *arg1)
{
    s16 mode;
    u8 *target;

    mode = *(s16 *)(*(u8 **)(arg0 + 0xE0) + 0x448);
    target = arg1;
    switch (mode) {
    case 1:
        target = (u8 *)&D_005F78C0 + (func_004bd050(0) & 1) * 0xF4;
        break;
    case 0:
        target = (u8 *)&D_005F7AB0 + (func_004bd050(0) & 1) * 0xF4;
        break;
    }
    func_001bdd80(arg0, target, 2);
    func_004b3110(5);
}
// FUN_001CF140
void func_001cf140(void) {
    func_001bdeb0();
}
/* measured probe: optimization_level 1 preserves 001CF160 low-bit OR coloring. */
#pragma optimization_level 1
// FUN_001CF160
void func_001cf160(u8 *arg0) {
    s32 random;
    u32 shifted;
    u32 masked;
    f32 value;

    random = func_00231d70(0x168);
    if (random >= 0) {
        value = (f32)random;
    } else {
        shifted = (u32)random >> 1;
        masked = (u32)random & 1;
        shifted |= masked;
        value = (f32)(s32)shifted;
        value += value;
    }
    *(f32 *)(arg0 + 0x100) = value;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}
/* measured: closes optimization_level 1 for 001CF160. */
#pragma optimization_level 2
// FUN_001CF1F0
void func_001cf1f0(u8 *arg0)
{
    struct Frame {
        u8 pad20[0x40];
        f32 vec60[3];
        f32 value6C;
        u8 pad70[0x10];
        f32 vec80[4];
        f32 vec90[4];
    } frame;

    func_00195850(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                  &frame.vec90[0]);
    frame.vec90[1] = 0.0f;
    func_003e0870((RwMatrix *)(u8 *)&frame, (const RwV3d *)D_0060A0D0, -30.0f, 0);
    func_003e0870((RwMatrix *)(u8 *)&frame, (const RwV3d *)D_0060A0E0,
                  *(f32 *)(arg0 + 0x100), 2);
    func_003e4320((RwV3d *)(u8 *)&frame.vec80[0], (const RwV3d *)(&D_0060A0F0), (const RwMatrix *)(u8 *)&frame);
    frame.vec60[0] = func_001c_mul_add(frame.vec80[0],
                                        400.0f, frame.vec90[0]);
    frame.vec60[1] = func_001c_mul_add(frame.vec80[1],
                                        400.0f, frame.vec90[1]);
    frame.vec60[2] = func_001c_mul_add(frame.vec80[2],
                                        400.0f, frame.vec90[2]);
    func_001bd780(&frame.value6C, &frame.vec60[0],
                  &frame.vec90[0], D_0060A0E0);
    if (frame.vec60[1] < 25.0f) {
        frame.vec60[1] = 25.0f;
    }
    *(f32 *)(arg0 + 0x100) = *(f32 *)(arg0 + 0x100) + 0.25f;
    func_001bcd40(NULL, NULL, NULL, 0.0f, 4);
    func_001bab00((u16 *)(arg0), (f32 *)&frame.vec60[0]);
}
// FUN_001CF350
void func_001cf350(u8 *arg0)
{
    struct {
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 sp4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 sp5C;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 sp6C;
        f32 sp70;
        f32 sp74;
        u8 pad_to_80[8];
        u8 sp80[0x40];
        u8 pad_to_C8[8];
        f32 spC8;
        f32 spCC;
        f32 spD0;
        f32 spD4;
        f32 spD8;
        u8 pad_to_E0[4];
        f32 spE0;
        f32 spE4;
        f32 spE8;
        u8 pad_to_F0[4];
        f32 spF0;
        f32 spF4;
        f32 spF8;
        u8 pad_to_100[4];
        f32 sp100;
        f32 sp104;
        f32 sp108;
        u8 pad_to_110[4];
        f32 sp110;
        f32 sp114;
        f32 sp118;
        u8 pad_tail[4];
    } frame;
    u8 *work;
    f32 var_f21;
    f32 temp_f20;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    extern f32 fGpffff80e8;
    extern u8 D_0060A100[];
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);

    work = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    var_f21 = func_00196040(3, 1, (RwV3d *)((u8 *)&frame.spD0), 0, 0, 1);
    if (var_f21 < 550.0f) {
        var_f21 = 550.0f;
    }
    func_001958f0((BtlUnit *)(work), (RwV3d *)(&frame.sp110));
    frame.sp100 = frame.sp110 - frame.spD0;
    frame.sp104 = frame.sp114 - frame.spD4;
    frame.sp108 = frame.sp118 - frame.spD8;
    temp_f1 = 0.25f * func_003e40b0((RwV3d *)&frame.sp100, (const RwV3d *)&frame.sp100);
    frame.spF0 = frame.sp100 * temp_f1;
    frame.spF4 = frame.sp104 * temp_f1;
    frame.spF8 = frame.sp108 * temp_f1;
    frame.spE0 = frame.spD0 + frame.spF0;
    frame.spE4 = frame.spD4 + frame.spF4;
    frame.spE8 = frame.spD8 + frame.spF8;
    var_f21 = var_f21 * fGpffff80e8;
    temp_f20 = var_f21 / tanf(fGpffff8110 *
                                         (0.5f * *(f32 *)(arg0 + 0xB8)));
    func_003e0870((RwMatrix *)frame.sp80, (const RwV3d *)D_0060A0D0, 32.5f, 0);
    func_003e4320((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, (const RwMatrix *)frame.sp80);
    func_003dcb40((RwV3d *)&frame.sp100, (const RwV3d *)&frame.spF0, 1,
                  (const RtQuat *)(work + 0x1C));
    frame.sp110 = frame.sp100 * var_f21;
    frame.sp114 = frame.sp104 * var_f21;
    frame.sp118 = frame.sp108 * var_f21;
    frame.sp110 = frame.sp110 + frame.spD0;
    frame.sp114 = frame.sp114 + frame.spD4;
    frame.sp118 = frame.sp118 + frame.spD8;
    func_001bd780(&frame.sp68, &frame.sp110, &frame.spE0, D_0060A0E0);
    func_003dcb40((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)&frame.sp68);
    frame.sp100 = frame.spF0 * temp_f20;
    frame.sp104 = frame.spF4 * temp_f20;
    frame.sp108 = frame.spF8 * temp_f20;
    temp_f1 = temp_f20 * tanf(fGpffff8110 *
                                         (0.5f * *(f32 *)(arg0 + 0xB8)));
    temp_f1 = temp_f1 * 0.21875f;
    var_f21 = temp_f1 * fGpffff80e8;
    frame.spC8 = frame.sp100;
    frame.spCC = frame.sp108;
    func_003e41e0(&frame.spC8, &frame.spC8);
    frame.spE0 = 0.0f + frame.spE0 + frame.spCC * var_f21;
    frame.spE8 = 0.0f + frame.spE8 - frame.spC8 * var_f21;
    frame.sp5C = frame.spE0 + frame.sp100;
    frame.sp60 = frame.spE4 + frame.sp104;
    frame.sp64 = frame.spE8 + frame.sp108;
    temp_f1 = frame.sp68;
    temp_f2 = frame.sp6C;
    temp_f3 = frame.sp70;
    temp_f4 = frame.sp74;
    frame.sp4C = temp_f1;
    frame.sp50 = temp_f2;
    frame.sp54 = temp_f3;
    frame.sp58 = temp_f4;
    temp_f1 = temp_f20 - 100.0f;
    temp_f2 = frame.spF0 * temp_f1;
    frame.sp100 = temp_f2;
    temp_f3 = frame.spF4 * temp_f1;
    frame.sp104 = temp_f3;
    temp_f4 = frame.spF8 * temp_f1;
    frame.sp108 = temp_f4;
    frame.sp40 = frame.spE0 + temp_f2;
    frame.sp44 = frame.spE4 + temp_f3;
    frame.sp48 = frame.spE8 + temp_f4;
    func_001bcd40(NULL, NULL, NULL, 0.0f, 0x100);
    func_001bc3a0(&frame.sp40, &frame.sp40);
    func_001bc3a0(&frame.sp5C, &frame.sp5C);
    func_001bac20((u16 *)arg0, &frame.sp40, &frame.sp5C, 1);
    func_001bbef0(arg0, 3.0f);
}
// FUN_001CF730
void func_001cf730(u8 *arg0)
{
    struct {
        f32 sp40;
        f32 sp44;
        f32 sp48;
        f32 sp4C;
        f32 sp50;
        f32 sp54;
        f32 sp58;
        f32 sp5C;
        f32 sp60;
        f32 sp64;
        f32 sp68;
        f32 sp6C;
        f32 sp70;
        f32 sp74;
        u8 pad_to_80[8];
        u8 sp80[0x40];
        u8 pad_to_C8[8];
        f32 spC8;
        f32 spCC;
        f32 spD0;
        f32 spD4;
        f32 spD8;
        u8 pad_to_E0[4];
        f32 spE0;
        f32 spE4;
        f32 spE8;
        u8 pad_to_F0[4];
        f32 spF0;
        f32 spF4;
        f32 spF8;
        u8 pad_to_100[4];
        f32 sp100;
        f32 sp104;
        f32 sp108;
        u8 pad_to_110[4];
        f32 sp110;
        f32 sp114;
        f32 sp118;
        u8 pad_tail[4];
    } frame;
    u8 *work;
    f32 var_f21;
    f32 temp_f20;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    extern f32 DAT_0076112c;
    extern f32 fGpffff80e8;
    extern u8 D_0060A100[];
    extern f32 func_003e41e0(f32 *arg0, f32 *arg1);

    work = *(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30);
    var_f21 = func_00196040(2, 1, (RwV3d *)((u8 *)&frame.spD0), 0, 0, 1);
    func_001958f0((BtlUnit *)(work), (RwV3d *)(&frame.sp110));
    frame.sp100 = frame.sp110 - frame.spD0;
    frame.sp104 = frame.sp114 - frame.spD4;
    frame.sp108 = frame.sp118 - frame.spD8;
    temp_f1 = DAT_0076112c * func_003e40b0((RwV3d *)&frame.sp100, (const RwV3d *)&frame.sp100);
    frame.spF0 = frame.sp100 * temp_f1;
    frame.spF4 = frame.sp104 * temp_f1;
    frame.spF8 = frame.sp108 * temp_f1;
    frame.spE0 = frame.spD0 + frame.spF0;
    frame.spE4 = frame.spD4 + frame.spF4;
    frame.spE8 = frame.spD8 + frame.spF8;
    if (var_f21 < 450.0f) {
        var_f21 = 450.0f;
    }
    temp_f20 = var_f21 / tanf(fGpffff8110 *
                                          (0.5f * *(f32 *)(arg0 + 0xB8)));
    func_001c_rotate((RwMatrix *)frame.sp80, (const RwV3d *)D_0060A0D0, 35.0f, 0);
    func_003e4320((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, (const RwMatrix *)frame.sp80);
    func_003dcb40((RwV3d *)&frame.sp100, (const RwV3d *)&frame.spF0, 1,
                  (const RtQuat *)(work + 0x1C));
    frame.sp110 = frame.sp100 * var_f21;
    frame.sp114 = frame.sp104 * var_f21;
    frame.sp118 = frame.sp108 * var_f21;
    func_001bd780(&frame.sp68, &frame.sp110, &frame.spE0, D_0060A0E0);
    func_003dcb40((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, 1,
                  (const RtQuat *)&frame.sp68);
    temp_f1 = 50.0f + temp_f20;
    frame.sp100 = frame.spF0 * temp_f1;
    frame.sp104 = frame.spF4 * temp_f1;
    frame.sp108 = frame.spF8 * temp_f1;
    var_f21 = temp_f20 * tanf(fGpffff8110 *
                                          (0.5f * *(f32 *)(arg0 + 0xB8)));
    var_f21 = var_f21 * 0.21875f;
    var_f21 = var_f21 * fGpffff80e8;
    frame.spC8 = frame.sp100;
    frame.spCC = frame.sp108;
    func_003e41e0(&frame.spC8, &frame.spC8);
    frame.spE0 = 0.0f + frame.spE0 + frame.spCC * var_f21;
    frame.spE8 = 0.0f + frame.spE8 - frame.spC8 * var_f21;
    frame.sp5C = frame.spE0 + frame.sp100;
    frame.sp60 = frame.spE4 + frame.sp104;
    frame.sp64 = frame.spE8 + frame.sp108;
    temp_f1 = frame.sp68;
    temp_f2 = frame.sp6C;
    temp_f3 = frame.sp70;
    temp_f4 = frame.sp74;
    frame.sp4C = temp_f1;
    frame.sp50 = temp_f2;
    frame.sp54 = temp_f3;
    frame.sp58 = temp_f4;
    temp_f1 = temp_f20 - 50.0f;
    temp_f2 = frame.spF0 * temp_f1;
    frame.sp100 = temp_f2;
    temp_f3 = frame.spF4 * temp_f1;
    frame.sp104 = temp_f3;
    temp_f4 = frame.spF8 * temp_f1;
    frame.sp108 = temp_f4;
    frame.sp40 = frame.spE0 + temp_f2;
    frame.sp44 = frame.spE4 + temp_f3;
    frame.sp48 = frame.spE8 + temp_f4;
    func_001bcd40(NULL, NULL, NULL, 0.0f, 0x100);
    func_001bac20((u16 *)arg0, &frame.sp40, &frame.sp5C, 1);
    func_001bbef0(arg0, 3.5f);
}
// FUN_001CFAD0
void func_001cfad0(u8 *arg0, f32 arg1, f32 arg2)
{
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

    unit = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    status = func_00232710(*(s32 *)(unit + 0xA64), 0x100000);
    func_001959d0((BtlUnit *)unit, (RwV3d *)work.center);
    if (status == 0) {
        work.center[1] = 0.0f + work.center[1] + fGpffff810c *
                         (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    } else {
        work.center[1] = 0.0f + work.center[1] - fGpffff810c *
                         (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    }
    func_003dcb40((RwV3d *)work.direction, (const RwV3d *)(&D_0060A0F0), 1,
                  (const RtQuat *)(unit + 0x1C));
    work.scaled[0] = 200.0f * work.direction[0];
    work.scaled[1] = 200.0f * work.direction[1];
    work.scaled[2] = 200.0f * work.direction[2];
    y = work.center[1] + work.scaled[1];
    y = y + 55.0f;
    work.direction[0] = (work.center[0] + work.scaled[0]) - work.center[0];
    work.direction[1] = y - work.center[1];
    work.direction[2] = (work.center[2] + work.scaled[2]) - work.center[2];
    func_003e40b0((RwV3d *)work.direction, (const RwV3d *)work.direction);
    extent = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    if (extent < 75.0f) {
        extent = 75.0f;
    }
    firstScale = extent * arg1;
    arg1 = extent * arg2;
    choice = (s32)func_00231d70(2);
    switch (choice) {
    case 0:
        arg2 = 30.0f;
        break;
    case 1:
    default:
        arg2 = -30.0f;
        break;
    }
    func_001c_rotate(&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * -arg2, 0);
    func_003e4320((RwV3d *)work.scaled, (const RwV3d *)work.direction,
                  &work.rotation);
    firstScale = firstScale /
        tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled[0] = work.scaled[0] * firstScale;
    work.scaled[1] = work.scaled[1] * firstScale;
    work.scaled[2] = work.scaled[2] * firstScale;
    work.first[0] = work.center[0] + work.scaled[0];
    work.first[1] = work.center[1] + work.scaled[1];
    work.first[2] = work.center[2] + work.scaled[2];
    func_001bd780(&work.first[3], work.first, work.center, D_0060A0E0);
    func_001c_rotate(&work.rotation, (const RwV3d *)D_0060A0E0, 0.5f * arg2, 0);
    func_003e4320((RwV3d *)work.scaled, (const RwV3d *)work.direction,
                  &work.rotation);
    arg1 = arg1 /
        tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    work.scaled[0] = work.scaled[0] * arg1;
    work.scaled[1] = work.scaled[1] * arg1;
    work.scaled[2] = work.scaled[2] * arg1;
    work.second[0] = work.center[0] + work.scaled[0];
    work.second[1] = work.center[1] + work.scaled[1];
    work.second[2] = work.center[2] + work.scaled[2];
    func_001bd780(&work.second[3], work.second, work.center, D_0060A0E0);
    if (work.first[1] < 25.0f) {
        work.first[1] = 25.0f;
    }
    if (work.second[1] < 25.0f) {
        work.second[1] = 25.0f;
    }
    func_001b73f0(unit);
    func_001bac20((u16 *)arg0, work.first, work.second, 1);
    func_001bbef0(arg0, 3.0f);
}
// FUN_001CFED0
void func_001cfed0(u8 *arg0) {
    func_001cfad0(arg0, fGpffff8114, 2.5f);
}
// FUN_001CFF00
void func_001cff00(u8 *arg0)
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
        u8 second[0x28];
    } fr;
    f32 speed;
    f32 half_speed;
    f32 scale;
    f32 length;
    f32 x;
    f32 y;
    f32 limit;
    u8 *work;

    func_001bd560(fr.first, arg0 + 0x9C);
    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    func_00195850(work, (f32 *)&target);
    target.y = *(f32 *)(work + 0x84) * *(f32 *)(work + 0x2C);
    speed = *(f32 *)(work + 0x90) * *(f32 *)(work + 0x2C);
    half_speed = (*(f32 *)(work + 0x8C) * *(f32 *)(work + 0x2C)) * 0.5f;
    source = target;
    source.y += half_speed * 0.25f;
    if (speed > half_speed) {
        scale = (3.0f * speed) /
                tanf(fGpffff8110 *
                              (0.5f * *(f32 *)(arg0 + 0xB8)));
    } else {
        scale = (3.0f * half_speed) /
                tanf(0.5f * *(f32 *)(arg0 + 0xB8));
    }
    *(f32 *)(fr.second + 0x18) =
        fr.first[0] - source.x;
    *(f32 *)(fr.second + 0x1C) =
        fr.first[1] - source.y;
    *(f32 *)(fr.second + 0x20) =
        fr.first[2] - source.z;
    length = func_003e4180((f32 *)(fr.second + 0x18));
    length *= fGpffff811c;
    *(f32 *)(fr.second + 0x18) =
        fr.first[0] - source.x;
    *(f32 *)(fr.second + 0x1C) =
        fr.first[1] - source.y;
    *(f32 *)(fr.second + 0x20) =
        fr.first[2] - source.z;
    func_003e40b0((RwV3d *)(fr.second + 0x18),
                  (const RwV3d *)(fr.second + 0x18));
    x = *(f32 *)(fr.second + 0x18) *
        ((scale > length) ? scale : length);
    y = *(f32 *)(fr.second + 0x1C) *
        ((scale > length) ? scale : length);
    scale = (scale > length) ? scale : length;
    fr.first[7] = source.x + x;
    fr.first[8] = source.y + y;
    fr.first[9] = source.z +
                      *(f32 *)(fr.second + 0x20) * scale;
    limit = target.y + half_speed * 1.25f;
    if (fr.first[8] < limit) {
        fr.first[8] = limit;
    }
    func_001bd780(fr.second, &fr.first[7], &source, D_0060A0E0);
    func_001bac20((u16 *)arg0, fr.first, &fr.first[7], 1);
    func_001bbef0(arg0, 4.5f);
}
