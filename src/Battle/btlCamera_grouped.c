/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
static inline u8 *btlCamera_add_index(s32 index, u8 *base)
{
    return (u8 *)(index + (u32)base);
}

/* Canonical grouped function declarations. */
u32 func_001d10d0(void* camera);
void func_00195850(u8* arg0, f32* arg1);
void func_001bcd40(u8* arg0, u8* arg1, f32* arg2, f32 arg4, u16 arg3);
extern s32 func_004bd050(s32 arg0);
extern u8 D_005FE1D0[];
extern u32 func_00231d70(s32 arg0);

/* Source unit: src/Battle/btlCamera_001be8d0.c */

void FUN_001be050(u8* camera, f32 nearDegrees, f32 farDegrees);

// FUN_001BE8D0
void btlCameraSetDefaultDistanceA(void* camera)
{
    FUN_001be050((u8 *)camera, 45.0f, 200.0f);
}

/* Source unit: src/Battle/btlCamera_001d05b0.c */

void FUN_001be050(u8* camera, f32 nearDegrees, f32 farDegrees);

// FUN_001D05B0
void btlCameraSetDefaultDistanceB(void* camera)
{
    FUN_001be050((u8 *)camera, 45.0f, 200.0f);
}

/* Source unit: src/Battle/btlCamera_001d0670.c */

void FUN_001be050(u8* camera, f32 nearDegrees, f32 farDegrees);

// FUN_001D05E0
void func_001d05e0(u8 *arg0)
{
    f32 sp30[3];
    u8 *temp_16;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if (temp_4 != NULL) {
        if ((*(u16 *)(temp_4 + 0x1A) & 1) != 0) {
            temp_16 = *(u8 **)(temp_4 + 0x30);
            func_00195850(temp_16, sp30);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, sp30, 0.5f * (*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C)),
                          0xC1);
        }
    }
}
// FUN_001D0670
void btlCameraSetDefaultDistanceC(void* camera)
{
    FUN_001be050((u8 *)camera, 45.0f, 200.0f);
}

/* Source unit: src/Battle/btlCamera_001d10d0.c */

// FUN_001D06A0
void func_001d06a0(u8 *arg0)
{
    f32 sp30[3];
    u8 *temp_16;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0xE0);
    if (temp_4 != NULL) {
        if ((*(u16 *)(temp_4 + 0x1A) & 1) != 0) {
            temp_16 = *(u8 **)(temp_4 + 0x30);
            func_00195850(temp_16, sp30);
            func_001bcd40(*(u8 **)(arg0 + 0xE0), arg0 + 0x9C, sp30, 0.5f * (*(f32 *)(temp_16 + 0x90) * *(f32 *)(temp_16 + 0x2C)),
                          0xC1);
        }
    }
}
// FUN_001D0730
u8 *func_001d0730(s32 arg0, s32 arg1)
{
    if (arg1 != 0) {
        return (u8 *)((s32)&D_005FE1D0 + ((((arg0 & 0xFFFF) * 3) + 2) * 0x34));
    }
    return (u8 *)((s32)&D_005FE1D0 + ((((arg0 & 0xFFFF) * 3) + (func_004bd050(0) & 1)) * 0x34));
}
typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RtQuat { RwV3d imag; f32 real; } RtQuat;
typedef struct RwMatrixTag {
    RwV3d right; u32 flags;
    RwV3d up; u32 pad1;
    RwV3d at; u32 pad2;
    RwV3d pos; u32 pad3;
} RwMatrix;
typedef struct P4CameraFrame { RwV3d pos; RtQuat rot; } P4CameraFrame;
typedef struct BtlUnit BtlUnit;

/* Round the Y/Z displacement products before adding their focus coordinates. */
static inline f32 btlCamera_product(f32 left, f32 right)
{
    return left * right;
}

// FUN_001D07E0
s32 func_001d07e0(u8 *arg0, u8 *arg1)
{
    extern u32 func_001d10d0(void *camera);
    extern u8 *func_001b0c80(s32 arg0);
    extern void func_00195aa0(BtlUnit *unit, BtlUnit *target, RwV3d *out);
    extern void func_001ec1c0(u8 *out, u8 *first, u8 *second);
    extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
    extern void func_001959d0(BtlUnit *unit, RwV3d *out);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *out);
    extern void func_001bd780(void *out, const void *first, const void *second, const void *config);
    extern RwMatrix *func_003e0870(RwMatrix *matrix, const RwV3d *axis, f32 angle, s32 mode);
    extern RwV3d *func_003e4320(RwV3d *out, const RwV3d *in, const RwMatrix *matrix);
    extern void func_001bac20(u16 *camera, f32 *first, f32 *second, u16 mode);
    extern void func_001bbe80(u8 *arg0, f32 arg1);
    extern void func_001bbef0(u8 *arg0, f32 arg1);
    extern void func_001bbf40(u8 *arg0, f32 arg1);
    extern RwV3d D_0060A0E0;
    extern RwV3d D_0060A0F0;
    extern RwV3d D_0060A100;
    RwV3d direction;
    RwV3d position;
    RwV3d offsetA;
    RwV3d offsetB;
    RwV3d up;
    RwV3d centerA;
    RwV3d centerB;
    P4CameraFrame poses[2];
    RwMatrix matrix;
    RtQuat rotationA;
    RtQuat rotationB;
    RwV3d transformed[2];
    RwV3d focus[2];
    u8 *base;
    s16 index;
    s16 next;
    u8 *entry;
    u8 *unit0;
    u8 *unit1;
    u8 *tmpUnit;
    f32 angle;
    u16 cntC;
    s16 dur;
    u16 sw1;
    u16 sw2;

    if (func_001d10d0(arg1) == 0) {
        return 0;
    }
    base = *(u8 **)(arg1 + 0x10);
    index = *(s16 *)(arg1 + 0xA);
    if (base == NULL) {
        return 0;
    }
    if (index >= 4) {
        return 0;
    }
    if (index == -1) {
        goto next_entry;
    }
    cntC = *(u16 *)(arg1 + 0xC);
    dur = *(s16 *)(btlCamera_add_index(index * 0x3C, base) + 4);
    if ((s32)cntC < (s32)dur) {
        goto bump_tick;
    }
next_entry:
    next = index;
    ++next;
    if ((s32)next >= (s32)*(u8 *)base) {
        goto clear_flag;
    }
    if (*(u8 **)(arg1 + 0) == NULL) {
        goto clear_flag;
    }
    if (func_001b0c80(*(s32 *)(*(u8 **)(arg1 + 0) + 0x30)) == NULL) {
        goto clear_flag;
    }
    if (*(u8 **)(arg1 + 4) == NULL) {
        goto clear_flag;
    }
    if (func_001b0c80(*(s32 *)(*(u8 **)(arg1 + 4) + 0x30)) == NULL) {
        goto clear_flag;
    }
    entry = base + next * 0x3C + 4;
    unit1 = *(u8 **)(*(u8 **)(arg1 + 4) + 0x30);
    unit0 = *(u8 **)(*(u8 **)(arg1 + 0) + 0x30);
    if (unit0 != unit1) {
        if ((*(u16 *)(arg1 + 0xE) & 0x20) == 0) {
            func_001ec1c0((u8 *)&rotationA, (u8 *)(unit0 + 4), (u8 *)(unit1 + 4));
            func_001ec1c0((u8 *)&rotationB, (u8 *)(*(u8 **)(*(u8 **)(arg1 + 4) + 0x30) + 4), (u8 *)(*(u8 **)(*(u8 **)(arg1 + 0) + 0x30) + 4));
        } else {
            func_00195aa0((BtlUnit *)unit0, (BtlUnit *)unit1, &centerA);
            func_00195aa0(*(BtlUnit **)(*(u8 **)(arg1 + 4) + 0x30), *(BtlUnit **)(*(u8 **)(arg1 + 0) + 0x30), &centerB);
            func_001ec1c0((u8 *)&rotationA, (u8 *)&centerA, (u8 *)&centerB);
            func_001ec1c0((u8 *)&rotationB, (u8 *)&centerB, (u8 *)&centerA);
        }
    } else {
        rotationA = *(RtQuat *)(unit0 + 0x1C);
        tmpUnit = *(u8 **)(*(u8 **)(arg1 + 0) + 0x30);
        rotationB = *(RtQuat *)(tmpUnit + 0x1C);
    }
    offsetA = *(RwV3d *)(entry + 4);
    offsetB = *(RwV3d *)(entry + 16);
    if ((*(u16 *)(arg1 + 0xE) & 2) != 0) {
        offsetA.x = offsetA.x * -1.0f;
        offsetB.x = offsetB.x * -1.0f;
    }
    sw1 = *(u16 *)(entry + 2);
    switch (sw1) {
    case 1:
        tmpUnit = *(u8 **)(*(u8 **)(arg1 + 0) + 0x30);
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationA);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationA);
        poses[0].pos.x = *(f32 *)(tmpUnit + 4) + transformed[0].x;
        poses[0].pos.y = *(f32 *)(tmpUnit + 8) + transformed[0].y;
        poses[0].pos.z = *(f32 *)(tmpUnit + 12) + transformed[0].z;
        poses[1].pos.x = *(f32 *)(tmpUnit + 4) + transformed[1].x;
        poses[1].pos.y = *(f32 *)(tmpUnit + 8) + transformed[1].y;
        poses[1].pos.z = *(f32 *)(tmpUnit + 12) + transformed[1].z;
        break;
    case 2:
        tmpUnit = *(u8 **)(*(u8 **)(arg1 + 4) + 0x30);
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationB);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationB);
        poses[0].pos.x = *(f32 *)(tmpUnit + 4) + transformed[0].x;
        poses[0].pos.y = *(f32 *)(tmpUnit + 8) + transformed[0].y;
        poses[0].pos.z = *(f32 *)(tmpUnit + 12) + transformed[0].z;
        poses[1].pos.x = *(f32 *)(tmpUnit + 4) + transformed[1].x;
        poses[1].pos.y = *(f32 *)(tmpUnit + 8) + transformed[1].y;
        poses[1].pos.z = *(f32 *)(tmpUnit + 12) + transformed[1].z;
        break;
    }
    offsetA = *(RwV3d *)(entry + 32);
    offsetB = *(RwV3d *)(entry + 44);
    if ((*(u16 *)(arg1 + 0xE) & 2) != 0) {
        offsetA.x = offsetA.x * -1.0f;
        offsetB.x = offsetB.x * -1.0f;
    }
    sw2 = *(u16 *)(entry + 28);
    switch (sw2) {
    case 1:
        tmpUnit = *(u8 **)(*(u8 **)(arg1 + 0) + 0x30);
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationA);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationA);
        focus[0].x = *(f32 *)(tmpUnit + 4) + transformed[0].x;
        focus[0].y = *(f32 *)(tmpUnit + 8) + transformed[0].y;
        focus[0].z = *(f32 *)(tmpUnit + 12) + transformed[0].z;
        focus[1].x = *(f32 *)(tmpUnit + 4) + transformed[1].x;
        focus[1].y = *(f32 *)(tmpUnit + 8) + transformed[1].y;
        focus[1].z = *(f32 *)(tmpUnit + 12) + transformed[1].z;
        break;
    case 2:
        tmpUnit = *(u8 **)(*(u8 **)(arg1 + 4) + 0x30);
        RtQuatTransformVectors(&transformed[0], &offsetA, 1, &rotationB);
        RtQuatTransformVectors(&transformed[1], &offsetB, 1, &rotationB);
        focus[0].x = *(f32 *)(tmpUnit + 4) + transformed[0].x;
        focus[0].y = *(f32 *)(tmpUnit + 8) + transformed[0].y;
        focus[0].z = *(f32 *)(tmpUnit + 12) + transformed[0].z;
        focus[1].x = *(f32 *)(tmpUnit + 4) + transformed[1].x;
        focus[1].y = *(f32 *)(tmpUnit + 8) + transformed[1].y;
        focus[1].z = *(f32 *)(tmpUnit + 12) + transformed[1].z;
        break;
    case 3:
        tmpUnit = *(u8 **)(*(u8 **)(arg1 + 4) + 0x30);
        if ((*(u32 *)(tmpUnit + 0x9C) & 0x8000) == 0) {
            func_001959d0((BtlUnit *)tmpUnit, &position);
        } else {
            btlUnitGetSphereWorldCenter((BtlUnit *)tmpUnit, &position);
        }
        RtQuatTransformVectors(&direction, &D_0060A100, 1, &rotationA);
        {
            RwV3d displacement;
            displacement.x = direction.x * (*(f32 *)(tmpUnit + 0x90) * *(f32 *)(tmpUnit + 0x2C));
            displacement.y = btlCamera_product(direction.y, (*(f32 *)(tmpUnit + 0x90) * *(f32 *)(tmpUnit + 0x2C)));
            displacement.z = btlCamera_product(direction.z, (*(f32 *)(tmpUnit + 0x90) * *(f32 *)(tmpUnit + 0x2C)));
            focus[0].x = 0.0f + position.x + displacement.x;
            focus[0].y = position.y + displacement.y;
            focus[0].z = position.z + displacement.z;
        }
        if (focus[0].y < 100.0f) {
            focus[0].y = 100.0f;
        } else {
            if ((*(u16 *)(arg1 + 0xE) & 8) != 0) {
                if (focus[0].y > 250.0f) {
                    focus[0].y = 250.0f;
                }
            } else if ((*(u16 *)(arg1 + 0xE) & 0x10) != 0) {
                if (focus[0].y > 500.0f) {
                    focus[0].y = 500.0f;
                }
            } else if (((*(u16 *)(arg1 + 0xE) & 4) != 0) && (focus[0].y > 150.0f)) {
                focus[0].y = 150.0f;
            }
        }
        focus[1] = focus[0];
        break;
    }
    func_001bd780(&poses[0].rot, &poses[0].pos, &focus[0], &D_0060A0E0);
    angle = *(f32 *)(entry + 56);
    if (angle != 0.0f) {
        func_003e0870(&matrix, &D_0060A0F0, angle, 0);
        func_003e4320(&up, &D_0060A0E0, &matrix);
    } else {
        up = D_0060A0E0;
    }
    func_001bd780(&poses[1].rot, &poses[1].pos, &focus[1], &up);
    func_001bac20((u16 *)arg0, (f32 *)&poses[0], (f32 *)&poses[1], 1);
    switch (*(s16 *)(base + 2)) {
    case 0:
        func_001bbf40(arg0, (f32)*(s16 *)entry / 30.0f);
        break;
    case 1:
        func_001bbe80(arg0, (f32)*(s16 *)entry / 30.0f);
        break;
    case 2:
        func_001bbef0(arg0, (f32)*(s16 *)entry / 30.0f);
        break;
    }
    *(s16 *)(arg1 + 0xA) = (s16)(index + 1);
    *(u16 *)(arg1 + 0xC) = 0;
    goto tick;
clear_flag:
    *(u16 *)(arg1 + 0xE) = (u16)(*(u16 *)(arg1 + 0xE) & 0xFFFE);
    goto tick;
bump_tick:
    *(u16 *)(arg1 + 0xC) = (u16)(*(u16 *)(arg1 + 0xC) + 1);
tick:
    *(u16 *)(arg1 + 0x8) = (u16)(*(u16 *)(arg1 + 0x8) + 1);
    return 1;
}
// FUN_001D10D0
u32 func_001d10d0(void* camera)
{
    return (*(u16*)((u8*)camera + 0xE) & 1) != 0;
}

/* Source unit: src/Battle/btlCamera_001d12e0.c */

void FUN_0043f9c8(void* memory, s32 value, u32 size);

// FUN_001D10F0
void func_001d10f0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4)
{
    s32 flags;

    *(s32 *)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 4) = arg2;
    *(u8 **)(arg0 + 0x10) = arg3;
    *(s16 *)(arg0 + 8) = 0;
    *(s16 *)(arg0 + 0xA) = -1;
    *(s16 *)(arg0 + 0xC) = 0;
    *(u16 *)(arg0 + 0xE) |= 1;
    *(u16 *)(arg0 + 0xE) &= 0xFFFD;
    flags = arg4 & 0xFFFF;
    if ((flags & 1) && !(arg3[1] & 1) && (func_00231d70(0x64) >= 0x32U)) {
        *(u16 *)(arg0 + 0xE) |= 2;
    }
    if (flags & 2) {
        *(u16 *)(arg0 + 0xE) |= 4;
    }
    if (flags & 4) {
        *(u16 *)(arg0 + 0xE) |= 8;
    }
    if (flags & 8) {
        *(u16 *)(arg0 + 0xE) |= 0x10;
    }
    if (flags & 0x10) {
        *(u16 *)(arg0 + 0xE) |= 0x20;
    }
}
// FUN_001D1200
u8 *func_001d1200(u8 *arg0)
{
    u8 *base;
    s16 index;
    s32 condition;

    if ((*(u16 *)(arg0 + 0xE) & 1) == 0) {
        return 0;
    }
    base = *(u8 **)(arg0 + 0x10);
    index = *(s16 *)(arg0 + 0xA);
    if (base == 0) {
        return 0;
    }
    if (index == -1) {
        goto increment;
    }
    condition = *(u16 *)(arg0 + 0xC) < *(s16 *)(btlCamera_add_index(index * 0x3C, base) + 4);
    if (condition != 0) {
        goto done;
    }
increment:
    index++;
done:
    if (base[0] > index) {
        goto bound_ok;
    }
    return 0;
bound_ok:
    if (index >= 4) {
        return 0;
    }
    return base + index * 0x3C + 4;
}
// FUN_001D12E0
void btlCameraResetWork(void* work)
{
    FUN_0043f9c8(work, 0, 0x14);
}
