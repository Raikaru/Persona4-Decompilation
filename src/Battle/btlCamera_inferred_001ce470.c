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
extern void btlCameraFrameRotated(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void btlCameraFrameRotatedWide(u8 *arg0, f32 arg1, f32 arg2, f32 arg3);
extern void btlMainApplyUnitBaseColors(u8 *arg0);
extern void func_004b3110(s32 arg0);
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
extern void func_001bcd40(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg3, u16 arg4);
extern void btlMainCurveSetPoses(u16 *arg0, f32 *arg1, f32 *arg2, u16 arg3);
extern void btlCameraSetDuration(u8 *arg0, f32 arg1);
extern void btlCameraStartEffect(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 D_005F7CA0[];
extern u8 D_005F91A0[];
extern u8 D_005FA2D0[];
extern u8 D_005F78C0[];
extern u8 D_005F7AB0[];
extern u32 datCalcRandomBelow(u32 arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern void btlUnitSetFlags(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001c.c; members 001ce470-001cff00 */

/* measured: opt_propagation off probe for ce470 mixed-load ordering. */
/* measured: func_001ce470 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001CE470
void btlCameraFrameFixed(u8 *arg0)
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
    if (*(s32 *)(arg0 + 0xD8) == 0x25) {
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
// FUN_001CE620
void btlCameraFrameRotated(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
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
            btlUnitGetGroupBounds(3, 0, (RwV3d *)(arg0 + 0x104), 0, 0, 1);
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
    btlCameraLookAtQuat(frame.quat, frame.result, arg0 + 0x104,
                  D_0060A0E0);
    if (frame.result[1] < 25.0f) {
        frame.result[1] = 25.0f;
    }
    *(f32 *)(arg0 + 0x100) += arg2;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
        btlCameraClampOffsetToLimit(frame.result, frame.result);
    }
    btlMainCurveReset((u16 *)(arg0), (f32 *)(frame.result));
}

/* measured probe: optimization_level 1 for 001CE7F0 register coloring. */
/* measured: func_001ce7f0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// FUN_001CE7F0
void btlCameraFrameRandomShift(u8 *arg0) {
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
    *(f32 *)(arg0 + 0x100) = value;
    *(s32 *)(arg0 + 0x120) = 1;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}

/* measured probe: close optimization_level 1 for 001CE7F0. */
/* measured: btlAct_ROUNDUP_MES, func_001ce8c0, func_001ceba0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_001CE880
void btlCameraFrameRotatedAlt(u8 *arg0) {
    btlCameraFrameRotated(arg0, -17.5f, 0.25f, 0.75f);
}

// FUN_001CE8C0
void btlCameraFrameRotatedWide(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
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
        btlUnitGetGroupBounds(2, 1, (RwV3d *)(frame.target), 0, 0, 1);
        *(f32 *)(arg0 + 0x11C) =
            btlUnitGetGroupBounds(3, 0, (RwV3d *)(arg0 + 0x104), 0, 0, 2);
        *(f32 *)(arg0 + 0x108) = 0.0f;
        frame.diff[0] = *(f32 *)(arg0 + 0x104) - frame.target[0];
        frame.diff[1] = *(f32 *)(arg0 + 0x108) - frame.target[1];
        frame.diff[2] = *(f32 *)(arg0 + 0x10C) - frame.target[2];
        scale = fGpffff8100 * RwV3dNormalize((RwV3d *)frame.diff, (const RwV3d *)frame.diff);
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
        RwV3dNormalize((RwV3d *)(arg0 + 0x110),
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
    btlCameraLookAtQuat(frame.quat, frame.result, arg0 + 0x104,
                  D_0060A0E0);
    if (frame.result[1] < 25.0f) {
        frame.result[1] = 25.0f;
    }
    *(f32 *)(arg0 + 0x100) += arg2;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) == 0) {
        btlCameraClampOffsetToLimit(frame.result, frame.result);
    }
    btlMainCurveReset((u16 *)(arg0), (f32 *)(frame.result));
}

// FUN_001CEBA0
void btlCameraSetUnitFlags(u8 *arg0)
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
                            btlUnitSetFlags(*(u8 **)(current + 0x30), 2,
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
void btlCameraFrameRotatedWideAlt(u8 *arg0) {
    btlCameraFrameRotatedWide(arg0, -16.0f, fGpffff8198, fGpffff80fc);
}

// FUN_001CECE0
void btlAct_ROUNDUP_MES(u8 *arg0)
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
    btlCameraCopyPose(frame.first, arg0 + 0x9C);
    scale = btlUnitGetGroupBounds(3, 1, (RwV3d *)(frame.target), 0, 0, 1);
    frame.target[1] = 0.0f;
    btlUnitGetGridSphereCenter((BtlUnit *)(work), (RwV3d *)(frame.source));
    frame.source[1] +=
        (*(f32 *)(work + 0x8C) * *(f32 *)(work + 0x2C)) * 0.5f;
    btlCameraLookAtQuat(frame.second, frame.source, frame.target, D_0060A0E0);
    scale /= tanf(fGpffff8110 * (0.5f * *(f32 *)(arg0 + 0xB8)));
    *(f32 *)(frame.second + 0x18) = frame.source[0] - frame.target[0];
    *(f32 *)(frame.second + 0x1C) = frame.source[1] - frame.target[1];
    *(f32 *)(frame.second + 0x20) = frame.source[2] - frame.target[2];
    length = RwV3dNormalize((RwV3d *)(frame.second + 0x18),
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
        btlCameraClampOffsetToLimit(frame.result, frame.result);
    btlMainCurveSetPoses((u16 *)arg0, (f32 *)frame.first, frame.result, 1);
    btlCameraSetDuration(arg0, 1.0f);
}

/* measured probe: optimization_level 1 preserves 001CEF20 low-bit OR coloring. */
/* measured: func_001cef20 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// FUN_001CEF20
void btlCameraFrameRandomHold(u8 *arg0) {
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
    *(f32 *)(arg0 + 0x100) = value;
    *(s32 *)(arg0 + 0x120) = 1;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}

/* measured: closes optimization_level 1 for 001CEF20. */
/* measured: func_001cf020, func_001cf070 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_001CEFB0
void btlCameraFrameRotatedFar(u8 *arg0) {
    btlCameraFrameRotated(arg0, -10.0f, 0.125f, fGpffff809c);
}

// FUN_001CEFF0
void btlCameraFrameEnd(void) {
    btlMainApplyUnitBaseColors(NULL);
    func_004b3110(5);
}

// FUN_001CF020
void btlCameraFrameBuildPair(u8 *arg0) {
    P4CameraFrame frame;

    btlCameraBuildFramePair(arg0, 0, 0, NULL, &frame);
    btlMainCurveReset((u16 *)(arg0), (f32 *)(&frame));
}

// FUN_001CF070
void btlCameraFrameSpawn(u8 *arg0, u8 *arg1)
{
    s16 mode;
    u8 *target;

    mode = *(s16 *)(*(u8 **)(arg0 + 0xE0) + 0x448);
    target = arg1;
    switch (mode) {
    case 1:
        target = (u8 *)&D_005F78C0 + (effMiscRand(0) & 1) * 0xF4;
        break;
    case 0:
        target = (u8 *)&D_005F7AB0 + (effMiscRand(0) & 1) * 0xF4;
        break;
    }
    btlCameraStartEffect(arg0, target, 2);
    func_004b3110(5);
}

// FUN_001CF140
void btlCameraEffectListTickC(void) {
    btlCameraUpdateEffectList();
}

/* measured probe: optimization_level 1 preserves 001CF160 low-bit OR coloring. */
/* measured: func_001cf160 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
// FUN_001CF160
void btlCameraFrameRandomHoldAlt(u8 *arg0) {
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
    *(f32 *)(arg0 + 0x100) = value;
    func_001bcd40(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 0x100);
}

/* measured: closes optimization_level 1 for 001CF160. */
/* measured: btlAct_ALL, btlAct_TARGET_ONLY, func_001cf1f0, func_001cf350, func_001cfad0 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_001CF1F0
void btlCameraFrameMatrixOffset(u8 *arg0)
{
    struct Frame {
        u8 pad20[0x40];
        f32 vec60[3];
        f32 value6C;
        u8 pad70[0x10];
        f32 vec80[4];
        f32 vec90[4];
    } frame;

    btlUnitGetSphereWorldCenter(*(u8 **)(*(u8 **)(iGpffffb3ac + 0x170) + 0x30),
                  &frame.vec90[0]);
    frame.vec90[1] = 0.0f;
    RwMatrixRotate((RwMatrix *)(u8 *)&frame, (const RwV3d *)D_0060A0D0, -30.0f, 0);
    RwMatrixRotate((RwMatrix *)(u8 *)&frame, (const RwV3d *)D_0060A0E0,
                  *(f32 *)(arg0 + 0x100), 2);
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
    *(f32 *)(arg0 + 0x100) = *(f32 *)(arg0 + 0x100) + 0.25f;
    func_001bcd40(NULL, NULL, NULL, 0.0f, 4);
    btlMainCurveReset((u16 *)(arg0), (f32 *)&frame.vec60[0]);
}

// FUN_001CF350
void btlCameraFrameClampedRotate(u8 *arg0)
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
    var_f21 = btlUnitGetGroupBounds(3, 1, (RwV3d *)((u8 *)&frame.spD0), 0, 0, 1);
    if (var_f21 < 550.0f) {
        var_f21 = 550.0f;
    }
    btlUnitGetGridSphereCenter((BtlUnit *)(work), (RwV3d *)(&frame.sp110));
    frame.sp100 = frame.sp110 - frame.spD0;
    frame.sp104 = frame.sp114 - frame.spD4;
    frame.sp108 = frame.sp118 - frame.spD8;
    temp_f1 = 0.25f * RwV3dNormalize((RwV3d *)&frame.sp100, (const RwV3d *)&frame.sp100);
    frame.spF0 = frame.sp100 * temp_f1;
    frame.spF4 = frame.sp104 * temp_f1;
    frame.spF8 = frame.sp108 * temp_f1;
    frame.spE0 = frame.spD0 + frame.spF0;
    frame.spE4 = frame.spD4 + frame.spF4;
    frame.spE8 = frame.spD8 + frame.spF8;
    var_f21 = var_f21 * fGpffff80e8;
    temp_f20 = var_f21 / tanf(fGpffff8110 *
                                         (0.5f * *(f32 *)(arg0 + 0xB8)));
    RwMatrixRotate((RwMatrix *)frame.sp80, (const RwV3d *)D_0060A0D0, 32.5f, 0);
    func_003e4320((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, (const RwMatrix *)frame.sp80);
    RtQuatTransformVectors((RwV3d *)&frame.sp100, (const RwV3d *)&frame.spF0, 1,
                  (const RtQuat *)(work + 0x1C));
    frame.sp110 = frame.sp100 * var_f21;
    frame.sp114 = frame.sp104 * var_f21;
    frame.sp118 = frame.sp108 * var_f21;
    frame.sp110 = frame.sp110 + frame.spD0;
    frame.sp114 = frame.sp114 + frame.spD4;
    frame.sp118 = frame.sp118 + frame.spD8;
    btlCameraLookAtQuat(&frame.sp68, &frame.sp110, &frame.spE0, D_0060A0E0);
    RtQuatTransformVectors((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, 1,
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
    btlCameraClampOffsetToLimit(&frame.sp40, &frame.sp40);
    btlCameraClampOffsetToLimit(&frame.sp5C, &frame.sp5C);
    btlMainCurveSetPoses((u16 *)arg0, &frame.sp40, &frame.sp5C, 1);
    btlCameraSetDuration(arg0, 3.0f);
}

// FUN_001CF730
void btlAct_ALL(u8 *arg0)
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
    var_f21 = btlUnitGetGroupBounds(2, 1, (RwV3d *)((u8 *)&frame.spD0), 0, 0, 1);
    btlUnitGetGridSphereCenter((BtlUnit *)(work), (RwV3d *)(&frame.sp110));
    frame.sp100 = frame.sp110 - frame.spD0;
    frame.sp104 = frame.sp114 - frame.spD4;
    frame.sp108 = frame.sp118 - frame.spD8;
    temp_f1 = DAT_0076112c * RwV3dNormalize((RwV3d *)&frame.sp100, (const RwV3d *)&frame.sp100);
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
    RtQuatTransformVectors((RwV3d *)&frame.sp100, (const RwV3d *)&frame.spF0, 1,
                  (const RtQuat *)(work + 0x1C));
    frame.sp110 = frame.sp100 * var_f21;
    frame.sp114 = frame.sp104 * var_f21;
    frame.sp118 = frame.sp108 * var_f21;
    btlCameraLookAtQuat(&frame.sp68, &frame.sp110, &frame.spE0, D_0060A0E0);
    RtQuatTransformVectors((RwV3d *)&frame.spF0, (const RwV3d *)D_0060A100, 1,
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
    btlMainCurveSetPoses((u16 *)arg0, &frame.sp40, &frame.sp5C, 1);
    btlCameraSetDuration(arg0, 3.5f);
}

// FUN_001CFAD0
void btlCameraFrameStatusRoll(u8 *arg0, f32 arg1, f32 arg2)
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
    status = datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100000);
    btlUnitGetAnimBoundsWorldCenter((BtlUnit *)unit, (RwV3d *)work.center);
    if (status == 0) {
        work.center[1] = 0.0f + work.center[1] + fGpffff810c *
                         (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
    } else {
        work.center[1] = 0.0f + work.center[1] - fGpffff810c *
                         (*(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C));
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
    extent = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    if (extent < 75.0f) {
        extent = 75.0f;
    }
    firstScale = extent * arg1;
    arg1 = extent * arg2;
    choice = (s32)datCalcRandomBelow(2);
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
    btlCameraLookAtQuat(&work.first[3], work.first, work.center, D_0060A0E0);
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
    btlCameraLookAtQuat(&work.second[3], work.second, work.center, D_0060A0E0);
    if (work.first[1] < 25.0f) {
        work.first[1] = 25.0f;
    }
    if (work.second[1] < 25.0f) {
        work.second[1] = 25.0f;
    }
    btlMainApplyUnitBaseColors(unit);
    btlMainCurveSetPoses((u16 *)arg0, work.first, work.second, 1);
    btlCameraSetDuration(arg0, 3.0f);
}

// FUN_001CFED0
void btlAct_ENEMY_ALL(u8 *arg0) {
    btlCameraFrameStatusRoll(arg0, fGpffff8114, 2.5f);
}

// FUN_001CFF00
void btlAct_TARGET_ONLY(u8 *arg0)
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

    btlCameraCopyPose(fr.first, arg0 + 0x9C);
    work = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    btlUnitGetSphereWorldCenter(work, (f32 *)&target);
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
    length = RwV3dLength((f32 *)(fr.second + 0x18));
    length *= fGpffff811c;
    *(f32 *)(fr.second + 0x18) =
        fr.first[0] - source.x;
    *(f32 *)(fr.second + 0x1C) =
        fr.first[1] - source.y;
    *(f32 *)(fr.second + 0x20) =
        fr.first[2] - source.z;
    RwV3dNormalize((RwV3d *)(fr.second + 0x18),
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
    btlCameraLookAtQuat(fr.second, &fr.first[7], &source, D_0060A0E0);
    btlMainCurveSetPoses((u16 *)arg0, fr.first, &fr.first[7], 1);
    btlCameraSetDuration(arg0, 4.5f);
}

