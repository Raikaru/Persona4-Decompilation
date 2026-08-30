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
extern u32 func_002694f0(u32 param_1, u8 param_2, u32 param_3, u32 param_4);
extern u32 func_00269820(u16 *param_1, s32 param_2, s64 param_3, s64 param_4,
                         s32 param_5, s32 param_6, float param_7);
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
extern SceneVecBits D_0063B120[];
extern f32 D_0063B128[];
extern SceneVecBits D_0063B130[];
extern f32 D_0063B138[];
extern SceneVecBits D_0063B140[];
extern f32 D_0063B148[];
extern SceneVecBits D_0063B150[];
extern f32 D_0063B158[];
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

extern u8 *func_00145270();
extern void func_0026c740(s32 object);
extern float func_0026cdb0(char *param_1);
extern s32 func_0026da30(u16 arg0, s32 arg1);
extern s32 func_0017b990(s32 arg0, s32 arg1, s32 arg2);
extern void func_0043f9c8(void *dst, s32 value, s32 size);
extern f32 func_003e40b0();
extern s64 D_0063B110;
extern f32 D_0063B118;
extern u8 D_0063B110_abs[];
extern f32 fGpffff8048;
extern void func_003e0870(void *dst, void *src, f32 angle, s32 mode);
extern u8 *func_003e4320(void *dst, void *src, void *mat);
extern s32 func_003e05d0(void *arg0);
extern s32 func_00168ec0();
extern s32 func_00479dd0(u32 arg0, u16 arg1, s16 arg2);
extern void func_0047a0e0(u32 arg0, u16 arg1, f32 arg2);
extern s32 func_00479940(u32 arg0, u16 arg1, s16 arg2, u16 arg3, u16 arg4);
extern void func_00479e60(u32 arg0, u16 arg1, f32 arg2);
extern u8 *func_0047a250(u32 arg0);
extern void func_004b14f0(u32 arg0, void *arg1);
extern void func_0044ea90(const void *msg, u32 id);
extern s32 func_00451fc0(s32 arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4,
                         void (*arg5)(u8 *), void (*arg6)(u8 *), u8 *arg7);
extern void func_0046d730(const void *msg, u32 line);
extern void func_00440b68(const void *msg, u32 value);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u32 *jtbl_008873E8[];
extern s32 func_004577d0(void *arg0, f32 arg1);
extern u8 *func_00457120(void);
extern u8 *func_003e0f80(void);
extern void func_003e0c90(void *dst, void *src, s32 mode);
extern s32 func_0026d400(void *arg0);
extern void func_003e9df0(void *arg0);
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern void func_003e0f40(void *arg0);
extern void func_00146f50(void *arg0, void *arg1, void *arg2);
extern void func_0026bfc0(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 *arg1);
extern u8 *func_00147620(u32 arg0);
extern f32 func_0044b610(f32 arg0);
extern f32 func_0044b938(f32 arg0);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern u32 PTR_DAT_00762ea0;
extern u32 D_005F08B0[];
extern u8 D_0063B090[];
extern u8 D_0063B0A0[];
extern u8 D_0063B0D0[];
extern u8 D_0063B080[];
extern u8 D_0063B088[];
extern s64 D_0063B0F0;
extern f32 D_0063B0F8;
extern s64 D_0063B100;
extern f32 D_0063B108;
extern s64 D_0063B0B8[];
extern f32 D_0063B0C0[];
extern void func_00268a70(u8 *arg0);
extern void func_00268ad0(u8 *arg0);
extern u8 D_0063B160_abs[];
extern u8 D_0063B170_abs[];
extern u8 D_0063B180_abs[];
extern u8 D_0063B190_abs[];
extern void func_0026c190(float *out, void *resource, f32 scale);

// FUN_00268B20
void func_00268b20(u32 arg0)
{
    u8 *p;

    func_0044ea90(D_0063B090, 0x31);
    p = D_008873F4[0](1, 8, 0x40000);
    if (func_00451fc0(0, (char *)D_0063B0A0, 0, 1, 1, func_00268a70, func_00268ad0, p) != 0) {
        *(u32 *)(p + 0) = 2;
        *(u32 *)(p + 4) = arg0;
    }
}

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



/* measured: volatile casts on the D_0063B0B8/D_0063B0C0 global loads and the
   source-local stores force mwcc b210 to batch both loads before both stores
   (retail: lui+ld, lui+lwc1, sd, swc1) and to emit the exact FPU
   mul.s/adda.s/madd.s dot chain with the zero term in $f5; the plain form
   emits load-store-load-store. Same pattern as the matched P3FES port
   FUN_0026C860. */
// FUN_00268CE0
u32 func_00268ce0(float *first, float *second, float *output, float *third)
{
    u32 uVar1;
    float fVar2;
    u64 txy;
    float tz;
    float dif[3];
    float afStack_20[4];
    SceneVecBits source;

    txy = ((volatile SceneVecBits *)D_0063B0B8)->xy;
    tz = *(volatile float *)D_0063B0C0;
    *(volatile u64 *)&source.xy = txy;
    *(volatile float *)&source.z = tz;
    dif[0] = second[0] - first[0];
    dif[1] = second[1] - first[1];
    dif[2] = second[2] - first[2];
    fVar2 = func_003e40b0(afStack_20, dif);
    if (fVar2 == 0.0f) {
        return 0;
    }
    afStack_20[1] = 0.0f;
    uVar1 = func_0044dcd8(afStack_20[0] * ((float *)&source.xy)[0] +
                          afStack_20[1] * ((float *)&source.xy)[1] +
                          afStack_20[2] * source.z);
    uVar1 = func_0044b8d8(uVar1);
    fVar2 = fGpffff8428 * func_0044e7d8(uVar1);
    if (afStack_20[0] < 0.0f) {
        fVar2 = fVar2 * -1.0f;
    }
    *third = fVar2;
    *(RwV3d *)output = *(RwV3d *)dif;
    return 1;
}

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
s32 func_00268f20(u32 arg0, SVec3 *arg1, u32 arg2, u8 arg3)
{
    s32 result;
    u8 *p = func_00145270(arg0);

    if (p == NULL) return 0;
    if (p == NULL) {
        result = 0;
    } else {
        *(u32 *)(p + 0x28) |= 1;
        *(u32 *)(p + 0x28) &= ~0x40;
        *(u32 *)(p + 0x28) &= ~0x10;
        *(SVec3 *)(p + 0x30) = *(SVec3 *)(p + 4);
        *(SVec3 *)(p + 0x3C) = *(SVec3 *)(arg1);
        *(u32 *)(p + 0x64) = arg2;
        result = 1;
        *(u8 *)(p + 0x54) = result;
        *(u8 *)(p + 0x2C) = arg3;
        *(u32 *)(p + 0x60) = 0;
    }
    return result;
}

// FUN_00269000
s32 func_00269000(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0, f32 fparg1,
                  f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, s32 arg3,
                  s8 arg4) {
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
s32 func_002690b0(u32 arg0, u8 *arg1, u8 *arg2, f32 fparg0, f32 fparg1,
                  f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, s32 arg3,
                  s8 arg4)
{
    u8 *p = func_00145270(arg0);
    s32 result;

    if (p != NULL) {
        result = func_00269000(p, arg1, arg2, fparg0, fparg1, fparg2, fparg3, fparg4, fparg5, arg3, arg4);
    } else {
        result = 0;
    }
    return result;
}

// FUN_00269190
u32 func_00269190(Resrc *param_1, u32 param_2, float param_3, u32 param_4)
{
    u32 uVar1;
    u32 uVar2;
    u32 *puVar4;
    int iVar3;
    int iVar5;

    if (param_1 == 0) return 0;
    iVar3 = (int)param_1;
    uVar1 = param_1->flags;
    uVar1 = uVar1 | 1;
    param_1->flags = uVar1;
    uVar1 = uVar1 & 0xFFFFFFBF;
    param_1->flags = uVar1;
    if (param_4 == 1) {
        param_1->flags = param_1->flags | 0x40;
    }
    *(float *)(iVar3 + 0x5C) = param_3;
    *(u8 *)(iVar3 + 0x54) = 2;
    *(u32 *)(iVar3 + 0x60) = 0;
    if (*(u32 *)(iVar3 + 0x58) == 0) {
        func_0044ea90(D_0063B090, 0x269);
        uVar2 = (u32)((u32(*)(u32, u32))jtbl_008873E8[0])(0x130, 0x40000);
        *(u32 *)(iVar3 + 0x58) = uVar2;
        if (uVar2 == 0) {
            func_0046d730(D_0063B090, 0x26A);
        }
    }
    puVar4 = *(u32 **)(iVar3 + 0x58);
    iVar5 = 0x26;
    do {
        uVar1 = *(u32 *)param_2;
        uVar2 = *((u32 *)param_2 + 1);
        param_2 = (u32)((u32 *)param_2 + 2);
        iVar5--;
        *puVar4 = uVar1;
        puVar4[1] = uVar2;
        puVar4 += 2;
    } while (0 < iVar5);
    {
        float fVar6;
        fVar6 = func_0026cdb0((char *)*(u32 *)(iVar3 + 0x58));
        *(float *)(iVar3 + 0x64) = fVar6;
        func_00440b68(D_0063B0D0, func_0044dcd8(fVar6));
    }
    return 1;
}


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
s32 func_00269340(u32 arg0, SVec3 *arg1, u32 arg2, u8 arg3)
{
    SVec3 values;
    u8 *p = func_00145270(arg0);

    if (p == NULL) return 0;
    values = *arg1;
    if (p == NULL) return 0;
    func_0026c740((s32)p);
    func_0026c680((float *)&values);
    *(u32 *)(p + 0x28) |= 4;
    *(SVec3 *)(p + 0x68) = *(SVec3 *)(p + 0x10);
    *(SVec3 *)(p + 0x74) = values;
    *(u8 *)(p + 0x80) = 0;
    *(u8 *)(p + 0x81) = arg3;
    *(u32 *)(p + 0x84) = arg2;
    *(u32 *)(p + 0x88) = 0;
    return 1;
}

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
u32 func_002694f0(u32 param_1, u8 param_2, u32 param_3, u32 param_4)
{
    u8 tmp[8];
    u8 bVar;

    if (param_1 == 0) return 0;
    switch (((s32)(*(u16 *)param_1 & 0xFFC00)) >> 10) {
    case 3:
    {
        u8 *tp = func_0047a250(*(u32 *)((u8 *)param_1 + 0x164));
        u8 b0 = *tp++;
        u8 b1 = *tp++;
        u8 b2 = *tp++;
        u8 b3 = *tp++;

        tmp[4] = b0;
        tmp[5] = b1;
        tmp[6] = b2;
        tmp[7] = b3;
        bVar = tmp[7];
        if (param_4 == 1) {
            *(u8 *)((u8 *)param_1 + 0x100) = 1;
        } else {
            *(u8 *)((u8 *)param_1 + 0x100) = 0;
        }
        break;
    }
    case 6:
        func_004b14f0(*(u32 *)((u8 *)param_1 + 0x144), tmp);
        bVar = tmp[3];
        break;
    default:
        return 0;
    }
    *(u32 *)((u8 *)param_1 + 0x28) |= 0x4000;
    *(u8 *)((u8 *)param_1 + 0xF4) = bVar;
    *(u8 *)((u8 *)param_1 + 0xF5) = param_2;
    *(u32 *)((u8 *)param_1 + 0xF8) = param_3;
    *(u32 *)((u8 *)param_1 + 0xFC) = 0;
    return 1;
}

// FUN_00269620
u32 func_00269620(u32 param_1, u8 param_2, u32 param_3, u32 param_4)
{
    u32 lVar1;
    u32 uVar2;

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
s32 func_00269740(void)
{
    u8 *p = func_00145270();

    if (p == NULL) return 0;
    if (p == NULL) return 0;
    *(u32 *)(p + 0x28) &= ~1;
    *(u32 *)(p + 0x28) &= ~4;
    *(u32 *)(p + 0x28) &= 0xFFFF7FFF;
    *(u32 *)(p + 0x28) &= ~0x40;
    *(u32 *)(p + 0x28) &= ~0x400;
    *(u32 *)(p + 0x28) &= ~0x800;
    *(u32 *)(p + 0x28) &= ~0x1000;
    *(u32 *)(p + 0x28) &= ~0x2000;
    *(u32 *)(p + 0x28) &= ~0x4000;
    *(u32 *)(p + 0x28) &= ~0x10;
    *(u32 *)(p + 0x28) &= 0xF7FFFFFF;
    return 1;
}

// FUN_00269820
u32 func_00269820(u16 *arg0, s32 arg1, s64 arg2, s64 arg3, s32 arg4, s32 arg5,
                  float fparg0)
{
    s32 var_17;
    s32 var_16;

    if (arg0 == NULL) return 0;
    switch (((s32)(arg0[0] & 0xFFC00)) >> 10) {
    case 1:
        var_16 = *(s32 *)((u8 *)arg0 + 0x164);
        break;
    case 2:
        var_16 = *(s32 *)((u8 *)arg0 + 0x158);
        break;
    case 3:
        var_16 = *(s32 *)((u8 *)arg0 + 0x164);
        break;
    case 10:
        var_16 = *(s32 *)((u8 *)arg0 + 0x144);
        break;
    default:
        return 0;
    }
    var_17 = 0;
    if (arg4 == 1) {
        var_17 |= 1;
    }
    if (func_00479dd0(var_16, arg1, (s16)arg2) == 0) {
        func_0047a0e0(var_16, arg1, fparg0);
        func_00479940(var_16, arg1, (s16)arg2, arg3 & 0xFFFF, var_17 & 0xFFFF);
        if (arg5 > 0) {
            func_00479e60(var_16, arg1, (f32)arg5);
        }
    }
    *(s32 *)((u8 *)arg0 + 0x28) &= ~0x2000;
    return 1;
}
// FUN_002699D0
u32 func_002699d0(u32 *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, f32 fparg0)
{
    u8 *dst;

    if (arg0 == NULL) return 0;
    switch (((s32)(*(u16 *)arg0 & 0xFFC00)) >> 10) {
    case 1:
        dst = (u8 *)arg0 + 0x14C;
        break;
    case 2:
        dst = (u8 *)arg0 + 0x140;
        break;
    case 3:
        dst = (u8 *)arg0 + 0x14C;
        break;
    default:
        return 0;
    }
    *(u32 *)((u8 *)arg0 + 0x28) |= 0x2000;
    *(u32 *)(dst + 0) = arg1;
    *(u32 *)(dst + 4) = arg2;
    *(u32 *)(dst + 8) = arg3;
    *(u32 *)(dst + 0xC) = arg4;
    *(u32 *)(dst + 0x10) = arg5;
    *(f32 *)(dst + 0x14) = fparg0;
    return 1;
}

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
            func_00269820((u16 *)lVar2, 0, param_2, param_3, 1, 0, 1.0f);
        }
        goto end;
    }

    lVar4 = (u32)MT_Scene_GetRes(uVar1);
    if (lVar4 == 0) {
        goto second_done;
    }
    func_00269820((u16 *)lVar4, 0, param_2, param_3, 0, 0, 1.0f);

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



/* measured: retail batches each group's two global loads (ld D_0063B0F0 + lwc1
   D_0063B0F8) before both stores, hoists the first call's src-pointer addiu
   between the groups, and emits mov.s $f12 before move $a2 in the second
   func_003e0870 call; mwcc b210 emits load-store-load-store per element, the
   pointer addiu last, and move $a2 before mov.s $f12. Tried: direct stores,
   temp locals (optimized away), struct-temp copies (extra stack traffic),
   array-vs-scalar global spellings (array form fixed addressing, kept the
   layout/frame exact). All give identical nd 13. Load-sinking + argument-
   evaluation-order floors. */
// FUN_00269C70
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_00269c70);

/* measured: opt_propagation off closes nd 5 -> 0 for global-load ordering. */
#pragma opt_propagation off
// FUN_00269DB0
void func_00269db0(float *param_1, float *param_2)
{
    typedef struct SceneMatrixAngles {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } SceneMatrixAngles;
    SceneMatrixAngles matrix;
    RwV3d input;
    RwV3d zero = {0.0f, 0.0f, 0.0f};
    RwV3d axis;
    f32 at_x;
    f32 axis_x;
    f32 scale;
    f32 value;
    s32 adjusted;

    {
        s64 xy = *(s64 *)D_0063B110_abs;
        f32 z = *(f32 *)(D_0063B110_abs + 8);
        *(s64 *)&axis.x = xy;
        axis.z = z;
    }
    adjusted = 0;
    func_003e40b0(&input, param_2);
    matrix.pos = zero;
    matrix.at = input;
    func_003e40b0(&matrix.at, &matrix.at);

    matrix.right.x = matrix.at.y * axis.z - matrix.at.z * axis.y;
    at_x = matrix.at.x;
    axis_x = axis.x;
    matrix.right.y = matrix.at.z * axis_x - at_x * axis.z;
    matrix.right.z = at_x * axis.y - matrix.at.y * axis_x;
    func_003e40b0(&matrix.right, &matrix.right);

    matrix.up.x = matrix.at.y * matrix.right.z - matrix.at.z * matrix.right.y;
    matrix.up.y = matrix.at.z * matrix.right.x - matrix.at.x * matrix.right.z;
    matrix.up.z = matrix.at.x * matrix.right.y - matrix.at.y * matrix.right.x;
    func_003e40b0(&matrix.up, &matrix.up);
    func_003e05d0(&matrix);

    param_1[1] = func_0044b950(matrix.at.x, matrix.at.z);
    param_1[0] = -func_0044b938(matrix.at.y);
    if (func_0044b610(param_1[0]) != 0.0f) {
        param_1[2] =
            func_0044b938(matrix.right.y / func_0044b610(param_1[0]));
        adjusted = 1;
    } else {
        param_1[1] = func_0044b950(-matrix.right.z, matrix.right.x);
        param_1[0] = -func_0044b938(matrix.at.y);
        param_1[2] = 0.0f;
    }

    value = param_1[0];
    scale = fGpffff8048;
    param_1[0] = value * scale;
    param_1[1] = param_1[1] * scale;
    param_1[2] = param_1[2] * scale;
    if (adjusted != 0 && matrix.up.y < 0.0f) {
        param_1[0] = 180.0f - param_1[0];
    }
}
#pragma opt_propagation on

/* measured: not attempted — 6720B window with nested switches (jtbl_00748080),
   half-scaler (u>>1|u&1) patterns and mula/madd MAC chains; complexity exceeds
   the wave budget. Left as INCLUDE_ASM. */
// FUN_0026A020
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026a020);

/* measured: ported from m2c + P3FES idioms. Best nd 60 (obj 428B/window 432B)
   with hoisted temp_3[0]/temp_3[4] loads + sp40p base pointer. Residual:
   retail materializes func_00168ec0 arg3 (&sp40) via addiu $a2,$sp,0x40 at the
   loop top (before the D_0063B080/B088 loads); a sp40p local forces it early
   but spills to callee-saved $s3 (frame 0x70 vs 0x60). Without sp40p, nd 84
   with frame 0x60. Argument-materialization + load-position scheduling floor. */
// FUN_0026BA60
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026ba60);

// FUN_0026BC10
s32 func_0026bc10(u32 arg0, u32 arg1)
{
    u8 *p = func_00145270(arg0);

    if (p == NULL) return 0;
    if (p == NULL) return 0;
    if (func_0026da30(*(u16 *)p, arg1 & 0xFF) != 0) goto done;
    return 0;
done:
    return 1;
}

// FUN_0026BC90
s32 func_0026bc90(u8 *arg0, s32 arg1)
{
    s32 var_6 = 0;

    if (arg0 == NULL) return 0;
    switch (((s32)(*(u16 *)arg0 & 0xFFC00)) >> 10) {
    case 1:
        var_6 = *(s32 *)((u8 *)arg0 + 0x224);
        break;
    case 3:
        var_6 = *(s32 *)((u8 *)arg0 + 0x230);
        break;
    default:
        break;
    }
    if (var_6 == 0) return 0;
    if (arg1 == 1) {
        func_0017b990(var_6, 0, var_6);
    } else {
        func_0017b990(var_6, 1, var_6);
    }
    return 1;
}

// FUN_0026BD50
s32 func_0026bd50(u32 unk, s32 arg1) {
    u8 *temp_2 = (u8*)MT_Scene_GetRes();

    if (temp_2 != NULL) {
        return func_0026bc90(temp_2, arg1);
    }
    return 0;
}



// FUN_0026BDA0
s32 func_0026bda0(u32 arg0, s8 arg1, s8 arg2, s16 arg3, s16 arg4, s8 arg5)
{
    u8 *p = func_00145270(arg0);

    if (p == NULL) return 0;
    if (p == NULL) return 0;
    {
        u8 *q = p + 0xE8;
        func_0043f9c8(q, 0, 0xA);
        *(u8 *)(q + 0) = arg1;
        *(u8 *)(q + 1) = 0;
        *(u8 *)(q + 3) = arg2;
        *(u16 *)(q + 6) = arg3;
        *(u16 *)(q + 8) = arg4;
        *(u8 *)(q + 2) = arg5;
    }
    return 1;
}

// FUN_0026BE60
s32 func_0026be60(void)
{
    u8 *p = func_00145270();

    if (p == NULL) return 0;
    if (p == NULL) return 0;
    if ((((s32)(*(u16 *)p & 0xFFC00)) >> 10) != 7) return 0;
    {
        u8 *v = func_001452b0(7);

        while (v != NULL) {
            *(s32 *)(v + 0x148) = 0;
            v = *(u8 **)(v + 0x138);
        }
        *(s32 *)(p + 0x148) = 1;
    }
    return 1;
}

// FUN_0026BF20
void func_0026bf20(void) {
    u8 *var_3 = func_001452b0(7);

    while (var_3 != NULL) {
        *(s32 *)(var_3 + 0x148) = 0;
        var_3 = *(u8 **)(var_3 + 0x138);
    }
}


// FUN_0026BF70
void func_0026bf70(u32 arg0)
{
    if (((s32)((u16)arg0 & 0xFFC00) >> 10) == 7) {
        u8 *p = func_00145270(arg0);
        if (p != NULL) {
            *(u16 *)(p + 0x14C) = 0;
            *(u32 *)(p + 0x144) = 0;
        }
    }
}

/* measured: ported from P3FES FUN_003bb450 with the P4 global addresses and
   interleaved func_003e0870 declaration. Corrected func_003e4320's return
   declaration to u8 * (verified definition); plain C remains nd 9, object
   460B/window 464B. The first differing fndiff rows are offset 0x70
   (axis2's retail lwc1 versus mwcc's second aggregate ld), 0x78 (retail swc1
   versus mwcc sd), and offsets 0x80/0x88/0x8C (axis3 global-load order and
   register assignment). Direct axis2-width, direct axis3-load, typed-component,
   and load-order variants all measured worse or unchanged; committed at nd 9. */
// FUN_0026BFC0 NONMATCHING
#ifdef NON_MATCHING

void func_0026bfc0(f32 *input, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 *result) {
    typedef struct SceneMatrixLocal {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } SceneMatrixLocal;
    typedef union SceneVectorLocal {
        RwV3d value;
        struct {
            u64 xy;
            f32 z;
            u32 pad;
        } raw;
    } SceneVectorLocal;
    extern SceneVecBits D_0063B120[];
    extern f32 D_0063B128[];
    extern SceneVecBits D_0063B130[];
    extern f32 D_0063B138[];
    extern SceneVecBits D_0063B140[];
    extern f32 D_0063B148[];
    extern SceneVecBits D_0063B150[];
    extern f32 D_0063B158[];
    SceneVectorLocal axis0;
    SceneVectorLocal transformed;
    SceneVectorLocal source;
    SceneVectorLocal output;
    SceneVectorLocal axis1;
    SceneVectorLocal axis2;
    SceneVectorLocal axis3;
    SceneMatrixLocal matrix;
    u64 xy;
    f32 z;

    xy = *(u64 *)D_0063B120;
    z = *(f32 *)D_0063B128;
    axis0.raw.xy = xy;
    axis0.raw.z = z;
    xy = *(u64 *)D_0063B130;
    z = *(f32 *)D_0063B138;
    axis1.raw.xy = xy;
    axis1.raw.z = z;
    *(SceneVecBits *)&axis2.raw.xy = *(SceneVecBits *)D_0063B140;
    xy = *(u64 *)D_0063B150;
    z = *(f32 *)D_0063B158;
    axis3.raw.xy = xy;
    axis3.raw.z = z;

    matrix.at.z = 1.0f;
    matrix.up.y = 1.0f;
    matrix.right.x = 1.0f;
    matrix.up.x = 0.0f;
    matrix.right.z = 0.0f;
    matrix.right.y = 0.0f;
    matrix.at.y = 0.0f;
    matrix.at.x = 0.0f;
    matrix.up.z = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.x = 0.0f;
    matrix.flags |= 0x20003;

    func_003e0870(&matrix, &axis2.value, fparg2, 1);
    func_003e0870(&matrix, &axis1.value, fparg1, 1);
    func_003e0870(&matrix, &axis3.value, fparg3, 1);
    func_003e4320(&transformed, &axis0, &matrix);
    source.value = *(RwV3d *)input;
    output.value.x = source.value.x - transformed.value.x * fparg0;
    output.value.y = source.value.y - transformed.value.y * fparg0;
    output.value.z = source.value.z - transformed.value.z * fparg0;
    *(RwV3d *)result = output.value;
}
#else
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026bfc0);
#endif



/* measured: ported P3FES FUN_003bb620 (also nd 4 there). Only residual is the
   direction-vector stores: retail sd $v0,0xd0($sp)/swc1 $f0,0xd8($sp) direct;
   b210 either stores through a cached dest ptr (nd 4) or materializes the
   func_003e40b0 $a1 base after the stores (nd 8). Direct/pointer/staged forms
   probed, all >= nd 4. Cached-dest-pointer scheduling floor. */
// FUN_0026C190
INCLUDE_ASM("asm/nonmatchings/mt_sceneFunc", func_0026c190);

/* measured: opt_propagation off closes 15 load-order differences; lverify MATCH. */
#pragma opt_propagation off
// FUN_0026C310
void func_0026c310(u8 *param_1)
{
    typedef struct SceneMatrixC310 {
        RwV3d right;
        u32 flags;
        RwV3d up;
        u32 pad1;
        RwV3d at;
        u32 pad2;
        RwV3d pos;
        u32 pad3;
    } SceneMatrixC310;
    typedef struct SceneC310Locals {
        u64 leading_pad;
        union {
            u64 raw;
            struct {
                f32 x;
                f32 y;
            } value;
        } axis;
        union {
            f32 axis_z;
            u64 scratch_pad;
        } overlap;
        f32 scratch[6];
        f32 vec2[4];
        f32 vec1[4];
        f32 vec0[4];
        f32 outv[4];
    } SceneC310Locals;
    u8 *scene;
    s32 model;
    s32 result;
    SceneMatrixC310 *matrix;
    SceneC310Locals locals;
    f32 fc;
    f32 fb;
    f32 fa;
    f32 axis_y;
    f32 axis_z;
    f32 axis_x;

    scene = func_00457120();

    {
        u64 xy = *(u64 *)D_0063B160_abs;
        f32 z = *(f32 *)(D_0063B160_abs + 8);
        *(u64 *)locals.vec0 = xy;
        locals.vec0[2] = z;
    }
    {
        u64 xy = *(u64 *)D_0063B170_abs;
        f32 z = *(f32 *)(D_0063B170_abs + 8);
        *(u64 *)locals.vec1 = xy;
        locals.vec1[2] = z;
    }
    {
        u64 xy = *(u64 *)D_0063B180_abs;
        f32 z = *(f32 *)(D_0063B180_abs + 8);
        *(u64 *)locals.vec2 = xy;
        locals.vec2[2] = z;
    }

    model = *(s32 *)(scene + 4);
    if (((param_1 == NULL) || (scene == NULL)) || (model == 0)) {
        return;
    }

    func_0026c190(locals.outv, param_1, 0.0f);
    fb = locals.outv[0];
    fc = locals.outv[1];
    fa = locals.outv[2];
    *(f32 *)(param_1 + 4) = fb;
    *(f32 *)(param_1 + 8) = fc;
    *(f32 *)(param_1 + 0xc) = fa;

    matrix = (SceneMatrixC310 *)func_003e0f80();
    {
        u64 xy = *(u64 *)D_0063B190_abs;
        f32 z = *(f32 *)(D_0063B190_abs + 8);
        locals.axis.raw = xy;
        locals.overlap.axis_z = z;
    }
    if ((*(u32 *)(param_1 + 0x28) & 0x08000000) != 0) {
        *(u32 *)(param_1 + 0x28) &= ~0x08000000;
        fb = *(f32 *)(param_1 + 4);
        fc = *(f32 *)(param_1 + 8);
        fa = *(f32 *)(param_1 + 0xc);
        matrix->pos.x = fb;
        matrix->pos.y = fc;
        matrix->pos.z = fa;
        matrix->at.x = *(f32 *)(param_1 + 0x10) - matrix->pos.x;
        matrix->at.y = *(f32 *)(param_1 + 0x14) - matrix->pos.y;
        matrix->at.z = *(f32 *)(param_1 + 0x18) - matrix->pos.z;
        func_003e40b0(&matrix->at, &matrix->at);

        axis_y = locals.axis.value.y;
        axis_z = locals.overlap.axis_z;
        matrix->right.x =
            matrix->at.y * axis_z - matrix->at.z * axis_y;
        fc = matrix->at.x;
        fa = matrix->at.z;
        axis_x = locals.axis.value.x;
        matrix->right.y = fa * axis_x - fc * axis_z;
        matrix->right.z =
            matrix->at.x * axis_y - matrix->at.y * axis_x;
        func_003e40b0(&matrix->right, &matrix->right);

        matrix->up.x =
            matrix->at.y * matrix->right.z -
            matrix->at.z * matrix->right.y;
        matrix->up.y =
            matrix->at.z * matrix->right.x -
            matrix->at.x * matrix->right.z;
        matrix->up.z =
            matrix->at.x * matrix->right.y -
            matrix->at.y * matrix->right.x;
        func_003e40b0(&matrix->up, &matrix->up);
        func_003e05d0(matrix);
    } else {
        matrix->at.z = 1.0f;
        matrix->up.y = 1.0f;
        matrix->right.x = 1.0f;
        matrix->up.x = 0.0f;
        matrix->right.z = 0.0f;
        matrix->right.y = 0.0f;
        matrix->at.y = 0.0f;
        matrix->at.x = 0.0f;
        matrix->up.z = 0.0f;
        matrix->pos.z = 0.0f;
        matrix->pos.y = 0.0f;
        matrix->pos.x = 0.0f;
        matrix->flags |= 0x20003;

        func_003e0870(matrix, locals.vec0, *(f32 *)(param_1 + 0x14), 1);
        func_003e0870(matrix, locals.vec1, *(f32 *)(param_1 + 0x10), 1);
        func_003e0870(matrix, locals.vec2, *(f32 *)(param_1 + 0x18), 1);
        func_003e0c90(matrix, locals.outv, 2);
    }

    result = func_0026d400(&locals.scratch[4]);
    if (result == 1) {
        locals.scratch[0] = locals.scratch[4];
        locals.scratch[1] = locals.scratch[5];
        locals.scratch[2] = 0.0f;
        func_003e0c90(matrix, locals.scratch, 1);
    }

    func_003e9df0((void *)model);
    func_003e9cb0((void *)model, matrix, 0);
    func_003e0f40(matrix);
    func_004577d0(scene, *(f32 *)(param_1 + 0x140));
}
#pragma opt_propagation on

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
void func_0026ca10(char *param_2, float param_1, float *param_3)
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
float func_0026cba0(u32 arg0, float param_2, float param_3)
{
    u8 *p;
    u8 auStack[0x138];

    if (arg0 >= 6) {
        func_0046d730(D_0063B090, 0xA24);
    }
    if (param_2 == 0.0f) {
        param_3 = 1.0f;
    }
    else {
        param_3 = param_3 / param_2;
    }
    auStack[0] = 1;
    *(u32 *)(auStack + 4) = 0;
    *(u32 *)(auStack + 8) = 0;
    *(u32 *)(auStack + 0xC) = 0;
    p = func_00147620(arg0);
    *(f32 *)(auStack + 0x10) = *(f32 *)(p + 0);
    *(f32 *)(auStack + 0x14) = *(f32 *)(p + 8);
    *(u32 *)(auStack + 0x18) = 0;
    *(f32 *)(auStack + 0x1C) = *(f32 *)(p + 4);
    *(f32 *)(auStack + 0x20) = *(f32 *)(p + 0xC);
    *(u32 *)(auStack + 0x24) = 0;
    *(u32 *)(auStack + 0x28) = 0x3F800000;
    *(u32 *)(auStack + 0x2C) = 0x3F800000;
    *(u32 *)(auStack + 0x30) = 0;
    func_0026ca10((char *)auStack, param_3, (f32 *)(auStack + 0x130));
    return *(f32 *)(auStack + 0x134) * param_2;
}
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
