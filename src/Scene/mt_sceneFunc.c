#include "include_asm.h"
/* Source unit: src/mt_scene/mt_scene_00268bd0.c (1 function markers) */
#include "type.h"

typedef struct Resrc {
    u8 data[0x28];
    u32 flags;
} Resrc;

extern Resrc* MT_Scene_GetRes();

u32 func_00268ce0(float* first, float* second, float* output, float* third);

typedef struct { f32 x, y, z; } SVec3;
extern u32 func_00269190(Resrc* param_1, u32 param_2, float param_3, u32 param_4);
extern u64 func_002694f0(u32 param_1, u64 param_2, u64 param_3, u64 param_4);
extern u32 func_00269820(u32 param_1, u32 param_2, u32 param_3, u32 param_4,
                         u32 param_5, u32 param_6, float param_7);
extern u32 func_002699d0(u32 *param_1, u32 param_2, u32 param_3, u32 param_4,
                         u32 param_5, u32 param_6, float param_7);
extern u32 func_00269bd0(void* resource, s32 enabled);
extern s32 func_0026bc90(u8 *arg0, s32 arg1);

extern u8 *func_001452b0(s32 arg0);

extern void func_0026c680(float *param_1);

// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbb90 (verified MATCH
// there). 006a2f48 -> D_0063b1a0, 006a2f50 -> D_0063b1a8, 004c69f0 ->
// func_003e40b0, 00530da0 -> func_0044dcd8, 0052e9a0 -> func_0044b8d8,
// 005318a0 -> func_0044e7d8, 007caf18 -> fGpffff8428 (gp 0x007690f0 - 0x7bd8).

typedef struct SceneVecBits
{
    u64 xy;
    float z;
} __attribute__((packed)) SceneVecBits;

extern SceneVecBits D_0063b1a0[];
extern float D_0063b1a8[];
extern float RwV3dNormalize(float *dst, const float *src);
extern u32 func_0044dcd8(float param_1);
extern u32 func_0044b8d8(u32 value);
extern float func_0044e7d8(u32 value);
extern float fGpffff8428;

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbc90 (verified MATCH there). */

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbd40 (verified MATCH
// there). 003bbc90 -> func_0026c960.

extern void func_0026c960(float param_1, float *param_2, float *param_3, float *param_4, float *param_5, float *param_6, float *param_7);
extern f32 RwV3dLength(const RwV3d *vector);

// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bc0e0 (verified MATCH
// there). 007cb0b8 -> D_007614c0, 003bbfd0 -> func_0026cca0.

extern f32 D_007614c0;
extern float func_0026cca0(float param_1, float param_2, float *param_3, float *param_4, float *param_5, float *param_6, float *param_7);

// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bcc80 (verified MATCH
// there). 007ce658 -> D_00764580, 003500e0 -> func_004b15d0.

extern u16 D_00764580;
extern void func_004b15d0(void);



// FUN_00268B20
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00268b20);

// FUN_00268BD0
u32 func_00268bd0(Resrc* resource, s32 enabled)
{
    if (resource == NULL)
    {
        return 0;
    }

    if (enabled == 1)
    {
        resource->flags |= 8;
    }
    else
    {
        resource->flags &= ~8;
    }

    return 1;
}



// FUN_00268C20
u32 func_00268c20(u32 resTypeId, s32 enabled)
{
    Resrc* res;

    res = MT_Scene_GetRes(resTypeId);
    if (res == NULL)
    {
        return 0;
    }
    else if (res == NULL)
    {
        return 0;
    }
    else
    {
        if (enabled == 1)
        {
            res->flags |= 8;
        }
        else
        {
            res->flags &= ~8;
        }

        return 1;
    }
}



// FUN_00268CB0
u8 func_00268cb0(Resrc* resource)
{
    if (resource == NULL)
    {
        return 0;
    }

    return (resource->flags & 8) != 0;
}



// FUN_00268CE0
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00268ce0);

// FUN_00268E30
u32 func_00268e30(float* first, float* second, float* third)
{
    float output[4];

    return func_00268ce0(first, second, output, third);
}



// FUN_00268E60
s32 func_00268e60(u32 unk, u8 *arg1, f32 fparg0) {
    s32 temp_4;
    u8 *temp_2 = (u8*)MT_Scene_GetRes();

    if (temp_2 == NULL) {
        return 0;
    }
    if (temp_2 == NULL) {
        return 0;
    }
    temp_4 = *(s32 *)(temp_2 + 0x28) | 1;
    *(s32 *)(temp_2 + 0x28) = temp_4;
    *(s32 *)(temp_2 + 0x28) = temp_4 & ~0x40;
    *(SVec3 *)(temp_2 + 0x30) = *(SVec3 *)(temp_2 + 4);
    *(SVec3 *)(temp_2 + 0x3C) = *(SVec3 *)arg1;
    *(f32 *)(temp_2 + 0x5C) = fparg0;
    *(s8 *)(temp_2 + 0x54) = 0;
    return 1;
}



// FUN_00268F20
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00268f20);

// FUN_00269000
s32 func_00269000(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s8 arg4, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5) {
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;

    if (arg0 == NULL) {
        return 0;
    }
    temp_3 = *(s32 *)(arg0 + 0x28) | 0x10;
    *(s32 *)(arg0 + 0x28) = temp_3;
    temp_3_2 = temp_3 & ~1;
    *(s32 *)(arg0 + 0x28) = temp_3_2;
    temp_3_3 = temp_3_2 & ~4;
    *(s32 *)(arg0 + 0x28) = temp_3_3;
    *(s32 *)(arg0 + 0x28) = temp_3_3 & ~0x40;
    *(SVec3 *)(arg0 + 0x90) = *(SVec3 *)arg1;
    *(SVec3 *)(arg0 + 0x9C) = *(SVec3 *)arg2;
    *(f32 *)(arg0 + 0xA8) = fparg0;
    *(f32 *)(arg0 + 0xAC) = fparg1;
    *(f32 *)(arg0 + 0xB0) = fparg2;
    *(f32 *)(arg0 + 0xB4) = fparg3;
    *(f32 *)(arg0 + 0xB8) = fparg4;
    *(f32 *)(arg0 + 0xBC) = fparg5;
    *(s32 *)(arg0 + 0xC0) = arg3;
    *(s8 *)(arg0 + 0x8C) = arg4;
    *(s32 *)(arg0 + 0xC4) = 0;
    return 1;
}


// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003b89f0 (verified MATCH
// there). 003b5d10 -> func_00145270, 003b88c0 -> func_00269190.


// FUN_002690B0
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_002690b0);

// FUN_00269190
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00269190);

// FUN_002692D0
u32 func_002692d0(u32 param_1, u32 param_2, float param_3, u32 param_4)
{
    u32 lVar1;
    u32 uVar2;

    lVar1 = (u32)MT_Scene_GetRes();
    if (lVar1 != 0)
    {
        uVar2 = func_00269190((Resrc*)lVar1, param_2, param_3, param_4);
    }
    else
    {
        uVar2 = 0;
    }
    return uVar2;
}



// FUN_00269340
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00269340);

// FUN_00269440
s32 func_00269440(u32 unk, u8 *arg1, s32 arg2) {
    u8 *temp_2 = (u8*)MT_Scene_GetRes();

    if (temp_2 == NULL) {
        return 0;
    }
    if (temp_2 == NULL) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x28) |= 0x8000;
    *(SVec3 *)(temp_2 + 0xC8) = *(SVec3 *)(temp_2 + 0x1C);
    *(SVec3 *)(temp_2 + 0xD4) = *(SVec3 *)arg1;
    *(s32 *)(temp_2 + 0xE0) = arg2;
    *(s32 *)(temp_2 + 0xE4) = 0;
    return 1;
}


// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003b8e10 (verified MATCH
// there). 003b5d10 -> func_00145270, 003b8ce0 -> func_002694f0.


// FUN_002694F0
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_002694f0);

// FUN_00269620
u64 func_00269620(u64 param_1, u64 param_2, u64 param_3, u64 param_4)
{
    u32 lVar1;
    u64 uVar2;

    lVar1 = (u32)MT_Scene_GetRes();
    if (lVar1 != 0)
    {
        uVar2 = func_002694f0(lVar1, param_2, param_3, param_4);
    }
    else
    {
        uVar2 = 0;
    }
    return uVar2;
}



// FUN_00269690
s32 func_00269690(u32 unk, f32 fparg0, s32 arg1) {
    u8 *temp_2 = (u8*)MT_Scene_GetRes();

    if (temp_2 == NULL) {
        return 0;
    }
    if (temp_2 == NULL) {
        return 0;
    }
    if (((*(u16 *)temp_2 & 0xFFC00) >> 0xA) != 7) {
        return 0;
    }
    *(s32 *)(temp_2 + 0x28) |= 0x400;
    *(f32 *)(temp_2 + 0x104) = *(f32 *)(temp_2 + 0x140);
    *(f32 *)(temp_2 + 0x108) = fparg0;
    *(s32 *)(temp_2 + 0x10C) = arg1;
    *(s32 *)(temp_2 + 0x110) = 0;
    return 1;
}


// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003b93c0 (verified MATCH
// there). 003b5d10 -> func_00145270, 003b8ff0 -> func_00269820,
// 003b9260 -> func_002699d0.


// FUN_00269740
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00269740);

// FUN_00269820
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00269820);

// FUN_002699D0
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_002699d0);

// FUN_00269A90
void func_00269a90(u32 param_1, short param_2, short param_3, short param_4,
                   short param_5)
{
    u32 uVar1;
    u32 uVar3;
    u32 lVar2;
    u32 lVar4;

    uVar1 = (u16)param_1;
    uVar1 = (u16)(uVar1 & 0x3ff | 0xc00);

    uVar3 = (u32)param_4;
    if (uVar3 == -1) {
        lVar2 = (u32)MT_Scene_GetRes(uVar1);
        if (lVar2 != 0) {
            func_00269820(lVar2, 0, param_2, param_3, 1, 0, 1.0f);
        }
        goto end;
    }

    lVar4 = (u32)MT_Scene_GetRes(uVar1);
    if (lVar4 == 0) {
        goto second_done;
    }
    func_00269820(lVar4, 0, param_2, param_3, 0, 0, 1.0f);

second_done:
    lVar2 = (u32)MT_Scene_GetRes(uVar1);
    if (lVar2 != 0) {
        func_002699d0((u32 *)lVar2, 0, uVar3, param_5, 1, 0, 1.0f);
    }

end:
    return;
}



// FUN_00269BD0
u32 func_00269bd0(void* resource, s32 enabled)
{
    u32 result;
    s32 address;

    address = (s32)resource;
    if (resource == NULL)
    {
        result = 0;
    }
    else
    {
        if (enabled == 1)
        {
            *(u32*)(address + 0x28) |= 2;
        }
        else
        {
            *(u32*)(address + 0x28) &= 0xfffffffd;
        }
        result = 1;
    }

    return result;
}



// FUN_00269C20
s32 func_00269c20(u32 unk, s32 arg1) {
    u8 *temp_2 = (u8*)MT_Scene_GetRes();

    if (temp_2 != NULL) {
        return func_00269bd0(temp_2, arg1);
    }
    return 0;
}



// FUN_00269C70
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00269c70);

// FUN_00269DB0
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00269db0);

// FUN_0026A020
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026a020);

// FUN_0026BA60
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026ba60);

// FUN_0026BC10
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026bc10);

// FUN_0026BC90
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026bc90);

// FUN_0026BD50
s32 func_0026bd50(u32 unk, s32 arg1) {
    u8 *temp_2 = (u8*)MT_Scene_GetRes();

    if (temp_2 != NULL) {
        return func_0026bc90(temp_2, arg1);
    }
    return 0;
}



// FUN_0026BDA0
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026bda0);

// FUN_0026BE60
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026be60);

// FUN_0026BF20
void func_0026bf20(void) {
    u8 *var_3 = func_001452b0(7);

    while (var_3 != NULL) {
        *(s32 *)(var_3 + 0x148) = 0;
        var_3 = *(u8 **)(var_3 + 0x138);
    }
}


// FUN_0026BF70
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026bf70);

// FUN_0026BFC0
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026bfc0);

// FUN_0026C190
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026c190);

// FUN_0026C310
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026c310);

/* Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bb9b0 (verified MATCH there). */
/* Removing this loses FUN_003bb9b0 (MATCH nd0 -> MISMATCH nd143) - measured W161. */
#pragma opt_loop_invariants on

// FUN_0026C680
void func_0026c680(float *param_1)
{
    int iVar2;
    float afStack_10 [4];

    afStack_10[0] = *param_1;
    afStack_10[1] = param_1[1];
    afStack_10[2] = param_1[2];
    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
        while (afStack_10[iVar2] >= 360.0f) {
            afStack_10[iVar2] = afStack_10[iVar2] - 360.0f;
        }
        while (afStack_10[iVar2] < 0.0f) {
            afStack_10[iVar2] = afStack_10[iVar2] + 360.0f;
        }
    }

    *param_1 = afStack_10[0];
    param_1[1] = afStack_10[1];
    param_1[2] = afStack_10[2];
    return;
}
#pragma opt_loop_invariants off



// FUN_0026C740
void func_0026c740(s32 object)
{
    (func_0026c680)((float*)(object + 0x10));
}


// Ported from P3FES src/Scene/mt_sceneFunc.c FUN_003bbaa0 (verified MATCH
// there). 003bb9b0 -> func_0026c680.

/* opt_loop_invariants on: measured off nd 95, object 236/240; on nd 0, object 228/240 (MATCH); retain on. */
#pragma opt_loop_invariants on

// FUN_0026C770
void func_0026c770(float *param_1, float *param_2, float *param_3)
{
    int iVar1;
    float delta[4];
    float adjusted[4];
    const float wrap = 360.0f;
    const float limit = 180.0f;

    delta[0] = param_2[0] - param_1[0];
    delta[1] = param_2[1] - param_1[1];
    delta[2] = param_2[2] - param_1[2];
    func_0026c680(delta);
    adjusted[0] = delta[0];
    adjusted[1] = delta[1];
    adjusted[2] = delta[2];
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
        if (adjusted[iVar1] <= limit) {
            continue;
        }
        adjusted[iVar1] = -(wrap - adjusted[iVar1]);
    }
    param_3[0] = adjusted[0];
    param_3[1] = adjusted[1];
    param_3[2] = adjusted[2];
}
#pragma opt_loop_invariants off


// The volatile-qualified staging of the D_0063b1a0/D_0063b1a8 header into the
// local SceneVecBits is carried from the P3 donor (FUN_003bbb90), which is
// MATCH nd0 there with the same construct. measured in P4: removing the four
// volatile qualifiers regressed 0026c860 MATCH nd0 -> MISMATCH nd10 (object
// 256/256 both ways); retained to reproduce retail's load/store sequence.


// FUN_0026C860
void func_0026c860(const float *param_1, float *param_2)
{
    u32 uVar1;
    float fVar2;
    u64 txy;
    float tz;
    SceneVecBits source;
    float afStack_20[4];

    txy = ((volatile SceneVecBits *)D_0063b1a0)->xy;
    tz = *(volatile float *)D_0063b1a8;
    *(volatile u64 *)&source.xy = txy;
    *(volatile float *)&source.z = tz;

    fVar2 = RwV3dNormalize(afStack_20, param_1);
    if (fVar2 == 0.0f) {
        param_2[0] = 0.0f;
        param_2[1] = 0.0f;
        param_2[2] = 0.0f;
    }
    else {
        afStack_20[1] = 0.0f;
        uVar1 = func_0044dcd8(afStack_20[0] * ((float *)&source.xy)[0] +
                              afStack_20[1] * ((float *)&source.xy)[1] +
                              afStack_20[2] * source.z);
        uVar1 = func_0044b8d8(uVar1);
        fVar2 = fGpffff8428 * func_0044e7d8(uVar1);
        if (afStack_20[0] < 0.0f) {
            fVar2 = fVar2 * -1.0f;
        }
        param_2[1] = fVar2;
        param_2[0] = 0.0f;
        param_2[2] = 0.0f;
    }
}



// FUN_0026C960
void func_0026c960(float t, float *x, float *y, float *z, float *outX,
                   float *outY, float *outZ)
{
    float oneMinus = 1.0f - t;
    float oneMinusSquared = oneMinus * oneMinus;
    float w0;
    float w1;
    float w2;
    float w3;
    float tSquared;
    float rx;

    RwV3d result;
    w0 = oneMinus * oneMinusSquared;
    rx = x[0] * w0;
    w1 = t * (3.0f * oneMinusSquared);
    rx += x[1] * w1;
    tSquared = t * t;
    w2 = (3.0f * oneMinus) * tSquared;
    rx += x[2] * w2;
    w3 = t * tSquared;
    rx += x[3] * w3;
    result.x = rx;
    rx = y[0] * w0;
    rx += y[1] * w1;
    rx += y[2] * w2;
    rx += y[3] * w3;
    result.y = rx;
    rx = z[0] * w0;
    rx += z[1] * w1;
    rx += z[2] * w2;
    rx += z[3] * w3;
    result.z = rx;

    *outX = result.x;
    *outY = result.y;
    *outZ = result.z;
}


/* opt_lifetimes on: measured nd 62 -> 0, object 400/400 -> 400/400. */
#pragma opt_lifetimes on

// FUN_0026CA10
void func_0026ca10(float param_1, char *param_2, float *param_3)
{
    char cVar1;
    int iVar2;
    int segmentIndex;
    int iVar3;
    float fVar5;
    float auStack_10 [4];
    float auStack_20 [4];
    float auStack_30 [4];

    cVar1 = *param_2;
    if ('\0' < cVar1) {
        if (!(param_1 < 1.0f)) {
            iVar3 = 0;
            segmentIndex = cVar1 - 1;
            param_2 += segmentIndex * 0x24;
            for (; iVar3 < 4; iVar3 = iVar3 + 1) {
                iVar2 = iVar3 * 0xc;
                auStack_10[iVar3] = *(float *)(param_2 + iVar2 + 4);
                auStack_20[iVar3] = *(float *)(param_2 + iVar2 + 8);
                auStack_30[iVar3] = *(float *)(param_2 + iVar2 + 0xc);
            }
            func_0026c960(1.0f, auStack_10, auStack_20, auStack_30, param_3, param_3 + 1, param_3 + 2);
        }
        else {
            fVar5 = 1.0f / (float)(int)cVar1;
            segmentIndex = (int)(param_1 / fVar5);
            iVar3 = 0;
            param_2 += segmentIndex * 0x24;
            for (; iVar3 < 4; iVar3 = iVar3 + 1) {
                iVar2 = iVar3 * 0xc;
                auStack_10[iVar3] = *(float *)(param_2 + iVar2 + 4);
                auStack_20[iVar3] = *(float *)(param_2 + iVar2 + 8);
                auStack_30[iVar3] = *(float *)(param_2 + iVar2 + 0xc);
            }
            while (param_1 > fVar5) {
                param_1 = param_1 - fVar5;
            }
            func_0026c960(param_1 / fVar5, auStack_10, auStack_20, auStack_30, param_3, param_3 + 1, param_3 + 2);
        }
    }
    return;
}
#pragma opt_lifetimes off



// FUN_0026CBA0
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026cba0);

// FUN_0026CCA0
float func_0026cca0(float param_1, float param_2, float *param_3, float *param_4,
                    float *param_5, float *param_6, float *param_7)
{
    RwV3d delta;
    float first_x;
    float second_x;
    float first_y;
    float second_y;
    float first_z;
    float second_z;
    float first_len;

    func_0026c960(param_1, param_3, param_4, param_5, &first_x, &first_y, &first_z);
    func_0026c960(param_2, param_3, param_4, param_5, &second_x, &second_y, &second_z);
    delta.x = second_x - first_x;
    delta.y = second_y - first_y;
    delta.z = second_z - first_z;
    first_len = RwV3dLength(&delta);
    *param_6 = first_x;
    param_6[1] = first_y;
    param_6[2] = first_z;
    *param_7 = second_x;
    param_7[1] = second_y;
    param_7[2] = second_z;
    return first_len;
}



// FUN_0026CDB0
float func_0026cdb0(char *param_1)
{
    int iVar1;
    int lVar2;
    int iVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float scale;
    float auStack_10 [4];
    float auStack_20 [4];
    float auStack_30 [4];
    float auStack_40 [4];
    float auStack_50 [4];

    fVar5 = 0.0f;
    for (lVar2 = 0; lVar2 < *param_1; lVar2 = lVar2 + 1) {
        {
            char *curve;
            int copyIndex;

            copyIndex = 0;
            curve = param_1 + lVar2 * 0x24;
            for (; copyIndex < 4; copyIndex = copyIndex + 1) {
                iVar1 = copyIndex * 0xc;
                auStack_30[copyIndex] = *(float *)(curve + iVar1 + 4);
                auStack_40[copyIndex] = *(float *)(curve + iVar1 + 8);
                auStack_50[copyIndex] = *(float *)(curve + iVar1 + 0xc);
            }
        }

        fVar6 = 0.0f;
        for (iVar3 = 0; iVar3 < 0x14; iVar3 = iVar3 + 1) {
            fVar4 = (float)iVar3;
            scale = D_007614c0;
            fVar4 = fVar4 * scale;
            fVar4 = func_0026cca0(fVar4, (float)(iVar3 + 1) * scale,
                                  auStack_30, auStack_40, auStack_50, auStack_10, auStack_20);
            fVar6 = fVar6 + fVar4;
        }
        fVar5 = fVar5 + fVar6;
    }
    return fVar5;
}



// FUN_0026D810
void func_0026d810(void)
{
    *(u16 *)&D_00764580 = 0;
    func_004b15d0();
    return;
}
