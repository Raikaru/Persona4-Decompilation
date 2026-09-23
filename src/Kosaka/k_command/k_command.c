#include "model_motion_internal.h"
/* Source unit: src/Kosaka/k_command/k_command_00176c20.c (1 function markers) */
#include "Kosaka/k_command_internal.h"

extern char* strcpy(char* destination, const char* source);
extern s32 sprintf(char* destination, const char* format, ...);
extern char* strcat(char* destination, const char* source);
#include "type.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "include_asm.h"

extern s32 func_0029cc00(s32 arg0);
extern void func_00457140(u8 arg0, u8 arg1, u8 arg2, u8 arg3);

extern f32 func_0029cd50(s32 arg0);
extern f32 D_00764B5C;

extern u8 D_00724B3C;
extern u8 D_00724B40;
extern u8 D_00724B44;
extern u8 D_00724B48;
extern char D_005F1858[];
extern s32 D_007EFA00[];
extern u8 D_007EF9B0[];
extern s32 D_00764364;
extern u8* D_00762EA0;

extern void func_0046d730(const char* file, s32 line);
extern s32 func_00457120(void);
extern void* func_00174c00(void);
extern void* func_00174c10(void);
extern u8* MT_Scene_GetRes(u16 arg0);
extern u8* func_001452b0(s32 arg0);
extern s32 func_00145780(u16 arg0, s32 arg1, s32 arg2);
extern void func_0016f130(s32 a, s32 b, s32 c);
extern void func_0016f3b0(s32 a, s32 b, s32 c);
extern s32 func_004782b0(void* arg0);
extern void* func_00478750(s32 arg0);
extern void func_004787e0(u32 arg0);
extern void func_00478e70(s32 arg0);
extern void func_00479e60(s32 a, s32 b, f32 c);
extern void func_0047a1c0(s32 a, void* b, s32 c);
extern f32 func_0047a080(s32 arg0, s32 arg1);
extern void func_0047a0e0(s32 arg0, s32 arg1, f32 arg2);
extern void* mdlGetMatrix(u32 arg0);
extern void mdlScale(s32 arg0, void* arg1, s32 arg2);
extern f32 func_0014b660(u8* arg0);
extern f32 func_0014b5d0(u8* arg0);
extern f32 func_0014b6f0(u8* arg0);
extern s32 func_00151580(s32 a, s32 b, s32* c);
extern s32 func_003e9700(s32 arg0);
extern void RwV3dNormalize(f32* a, f32* b);
/* Layout and return types from the matrix API used by the field command. */
typedef struct RwMatrixTolerance {
    f32 Normal;
    f32 Orthogonal;
    f32 Identity;
} RwMatrixTolerance;
struct RwMatrixTag;
extern s32 RwEngineGetMatrixTolerances(RwMatrixTolerance *tolerance);
extern struct RwMatrixTag *RwMatrixOptimize(struct RwMatrixTag *matrix,
                                      const RwMatrixTolerance *tolerance);
extern struct RwMatrixTag *RwMatrixUpdate(struct RwMatrixTag *matrix);
extern s32 func_00168780(s32 arg0, f32 arg1);
extern f32 func_00168770(s32 arg0);
extern void func_00168c00(s32 arg0);
extern void func_0015bae0(void);
extern void func_0016ec90(s32 arg0);
extern void func_0017e9b0(s32 arg0);
extern void func_0017b9a0(s32 arg0, f32 arg1);
extern u8* func_00155280(void);

typedef struct
{
    f32 x, y, z;
} Vec3f;

typedef struct
{
    f32 m[16];
} Mat4;



// FUN_00176C20
u32 func_00176c20()
{
    s32 resourceId;

    resourceId = func_0029cc00(0);
    func_0014a0f0((u16)resourceId, func_0029cc00(1));
    return true;
}





/* Retail command operands narrow animation to s16 and converted frame to
   u16 at each dispatch; these are caller conversions, not the shared ABI. */
// FUN_00176C70
s32 func_00176c70(void)
{
    s32 v = func_0029cc00(0);
    s32 w = func_0029cc00(1);
    s32 x = func_0029cc00(2);
    s32 iv = (s32)func_0029cd50(3);
    f32 g = func_0029cd50(4);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            if (x != 0)
            {
                func_00479940((u8*)*(s32*)(p + 0x164), 0, (s16)w, (u16)iv, 1);
            }
            else
            {
                func_00479940((u8*)*(s32*)(p + 0x164), 0, (s16)w, (u16)iv, 0);
            }
            func_0047a0e0(*(s32*)(p + 0x164), 0, g);
        }
        break;
    }
    case 3:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            if (x != 0)
            {
                func_00479940((u8*)*(s32*)(p + 0x164), 0, (s16)w, (u16)iv, 1);
            }
            else
            {
                func_00479940((u8*)*(s32*)(p + 0x164), 0, (s16)w, (u16)iv, 0);
            }
            func_0047a0e0(*(s32*)(p + 0x164), 0, g);
        }
        break;
    }
    case 10:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            if (x != 0)
            {
                func_00479940((u8*)*(s32*)(p + 0x144), 0, (s16)w, (u16)iv, 1);
            }
            else
            {
                func_00479940((u8*)*(s32*)(p + 0x144), 0, (s16)w, (u16)iv, 0);
            }
            func_0047a0e0(*(s32*)(p + 0x144), 0, g);
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x1E0);
        break;
    }
    return 1;
}



// FUN_00176EF0
s32 func_00176ef0(void)
{
    s32 v = func_0029cc00(0);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            return *(u8*)(*(s32*)(p + 0x164) + 0xEE) == 1;
        }
        break;
    }
    case 3:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            return *(u8*)(*(s32*)(p + 0x164) + 0xEE) == 1;
        }
        break;
    }
    case 10:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            return *(u8*)(*(s32*)(p + 0x144) + 0xEE) == 1;
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x212);
        break;
    }
    return 1;
}



// FUN_00176FF0
s32 func_00176ff0(void)
{
    s32 v = func_0029cc00(0);
    f32 f = func_0029cd50(1);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            func_00479e60(*(s32*)(p + 0x164), 0, f);
        }
        break;
    }
    case 3:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            func_00479e60(*(s32*)(p + 0x164), 0, f);
        }
        break;
    }
    case 10:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            func_00479e60(*(s32*)(p + 0x144), 0, f);
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x23C);
        break;
    }
    return 1;
}



// FUN_00177120
s32 func_00177120(void)
{
    s32 v = func_0029cc00(0);
    f32 threshold = 0.0f;
    f32 f = func_0029cd50(1);
    s32 k = (v & 0xFFC00) >> 10;
    u8* p;
    s32 result;
    switch (k)
    {
    case 1:
        p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            threshold = func_0047a080(*(s32*)(p + 0x164), 0);
        }
        break;
    case 3:
        if (MT_Scene_GetRes(v & 0xFFFF) != 0)
        {
            threshold = func_0047a080(*(s32*)(p + 0x164), 0);
        }
        break;
    case 10:
        if (MT_Scene_GetRes(v & 0xFFFF) != 0)
        {
            threshold = func_0047a080(*(s32*)(p + 0x164), 0);
        }
        break;
    default:
        func_0046d730(D_005F1858, 0x264);
        break;
    }
    return (f >= threshold) ^ 1;
}



// FUN_00177280
s32 func_00177280(void)
{
    s32 v = func_0029cc00(0);
    f32 pos[3];
    s32 k;
    pos[0] = func_0029cd50(1);
    pos[1] = func_0029cd50(1);
    pos[2] = func_0029cd50(1);
    k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            mdlScale(*(s32*)(p + 0x164), pos, 2);
        }
        break;
    }
    case 3:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            mdlScale(*(s32*)(p + 0x164), pos, 2);
        }
        break;
    }
    case 10:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            mdlScale(*(s32*)(p + 0x144), pos, 2);
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x294);
        break;
    }
    return 1;
}



// FUN_001773D0
s32 func_001773d0(void)
{
    s32 v = func_0029cc00(0);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
        break;
    case 3:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0 && *(s32*)(p + 0x230) != 0)
        {
            f32 f = func_0029cd50(1);
            func_0017b9a0(*(s32*)(p + 0x230), f);
        }
        break;
    }
    case 10:
        break;
    default:
        func_0046d730(D_005F1858, 0x2B2);
        break;
    }
    return 1;
}



/* Native b210 O2: 1384/1392 executable bytes and eight zero alignment bytes.
 * The local axis is the retail (0, 1, 0) vector; each matrix-tolerance buffer
 * contains exactly the three floats read and written by the matrix API.
 * See docs/probe_archive/Field_placement_001774a0_20260924.md. */
/* Normalize the field-work predicate at the original inline boundary. */
static inline u32 fieldPlacementEnabled(u32 value)
{
    return value != 0;
}
// FUN_001774A0
s32 func_001774a0(void)
{
    s32 resourceId;
    s32 placementId;
    u8 *placement;
    s32 resourceType;
    f32 translation[3];
    f32 negativeTranslation[3];
    resourceId = func_0029cc00(0);
    placementId = func_0029cc00(1);
    placement = func_001452b0(14);
    {
        Vec3f rotationAxis = {0.0f, 1.0f, 0.0f};
        if (placement == 0) {
            func_0046d730(D_005F1858, 0x2C3);
        }
        while (placement != 0) {
            if ((*(u16 *)placement & 0x3FF) == placementId) {
                break;
            }
            placement = *(u8 **)(placement + 0x138);
        }
        resourceType = (resourceId & 0xFFC00) >> 10;
        switch (resourceType) {
        case 1:
        {
            u8 *resource;
            u8 *matrix;
            RwMatrixTolerance tolerance;
            s32 i;
            u32 hasWork;
            u8 *entry;
            u8 *fieldState;
            resource = MT_Scene_GetRes(resourceId & 0xFFFF);
            if (resource != 0) {
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x164));
                *(Vec3f *)translation = *(Vec3f *)(matrix + 0x30);
                negativeTranslation[0] = -1.0f * translation[0];
                negativeTranslation[1] = -1.0f * translation[1];
                negativeTranslation[2] = -1.0f * translation[2];
                func_0047a180(*(s32 *)(resource + 0x164), negativeTranslation, 2);
                func_0047a1a0((void *)(u32)*(s32 *)(resource + 0x164), &rotationAxis, *(f32 *)(placement + 0x14C), 0);
                func_0047a180(*(s32 *)(resource + 0x164), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x164));
                *(Vec3f *)(matrix + 0x30) = *(Vec3f *)(placement + 0x140);
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x164)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix(*(s32 *)(resource + 0x164)));
                func_00168c00(*(s32 *)(resource + 0x220));
                func_0015bae0();
                for (i = 0; i < 3; i++) {
                    hasWork = 0;
                    entry = D_007EF9B0 + i * 0x750;
                    if (*(s32 *)(entry + 0x798) != 0) {
                        if (*(s32 *)(entry + 0x7A4) != 0) {
                            hasWork = 1;
                        }
                    }
                    if (fieldPlacementEnabled(hasWork) && *(s32 *)(entry + 0x900) != 0) {
                        func_0017e9b0(*(s32 *)(entry + 0x900));
                    }
                }
                fieldState = func_00155280();
                if (*(s32 *)(fieldState + 4) != 0) {
                    func_0016ec90(*(s32 *)(func_00155280() + 4));
                }
            }
            break;
        }
        case 3:
        {
            u8 *resource;
            u8 *matrix;
            RwMatrixTolerance tolerance;
            f32 uniformScale;
            f32 scale[3];
            resource = MT_Scene_GetRes(resourceId & 0xFFFF);
            if (resource != 0) {
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x164));
                *(Vec3f *)translation = *(Vec3f *)(matrix + 0x30);
                negativeTranslation[0] = -1.0f * translation[0];
                negativeTranslation[1] = -1.0f * translation[1];
                negativeTranslation[2] = -1.0f * translation[2];
                func_0047a180(*(s32 *)(resource + 0x164), negativeTranslation, 2);
                func_0047a1a0((void *)(u32)*(s32 *)(resource + 0x164), &rotationAxis, *(f32 *)(placement + 0x14C), 2);
                func_0047a180(*(s32 *)(resource + 0x164), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x164));
                *(Vec3f *)(matrix + 0x30) = *(Vec3f *)(placement + 0x140);
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x164)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix(*(s32 *)(resource + 0x164)));
                if (*(s32 *)(resource + 0x22C) != 0) {
                    uniformScale = func_00168770(*(s32 *)(resource + 0x228));
                    scale[2] = uniformScale;
                    scale[1] = uniformScale;
                    scale[0] = uniformScale;
                    func_0047a1a0((void *)(u32)*(s32 *)(resource + 0x22C), &rotationAxis, *(f32 *)(placement + 0x14C), 2);
                    mdlScale(*(s32 *)(resource + 0x22C), scale, 2);
                    func_0047a180(*(s32 *)(resource + 0x22C), placement + 0x140, 2);
                    func_00478e70(*(s32 *)(resource + 0x22C));
                }
            }
            break;
        }
        case 10:
        {
            u8 *resource;
            u8 *matrix;
            RwMatrixTolerance tolerance;
            resource = MT_Scene_GetRes(resourceId & 0xFFFF);
            if (resource != 0) {
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x144));
                *(Vec3f *)translation = *(Vec3f *)(matrix + 0x30);
                negativeTranslation[0] = -1.0f * translation[0];
                negativeTranslation[1] = -1.0f * translation[1];
                negativeTranslation[2] = -1.0f * translation[2];
                func_0047a180(*(s32 *)(resource + 0x144), negativeTranslation, 2);
                func_0047a1a0((void *)(u32)*(s32 *)(resource + 0x144), &rotationAxis, *(f32 *)(placement + 0x14C), 0);
                func_0047a180(*(s32 *)(resource + 0x144), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x144));
                *(Vec3f *)(matrix + 0x30) = *(Vec3f *)(placement + 0x140);
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x144)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix(*(s32 *)(resource + 0x144)));
            }
            break;
        }
        default:
            func_0046d730(D_005F1858, 0x337);
            break;
        }
        return 1;
    }
}

// FUN_00177A10
u32 K_Cmd_CREATE_FLD_MDL()
{
    char path[64];
    char buff[64];
    s32 majorId;
    u32 minorId;
    Model* mdl;

    majorId = func_0029cc00(0);
    minorId = func_0029cc00(1);

    if (majorId > -1)
    {
        strcpy(path, "field/rmd/m");

        sprintf(buff, "%03d_", majorId);
        strcat(path, buff);

        sprintf(buff, "%03d.RMD", minorId);
        strcat(path, buff);
    }
    else
    {
        strcpy(path, "field/grmd/fobj");
        sprintf(buff, "%03d.RMD", minorId);
        strcat(path, buff);
    }

    mdl = func_00477e80(4, minorId, path, 0);
    func_0029cf50((s32)mdl);

    return true;
}





// FUN_00177B30
s32 func_00177b30(void)
{
    s32 v = func_0029cc00(0);
    s32 w = func_0029cc00(1);
    s32 flag = 0;
    s32 created = 0;
    u8* p2 = 0;
    s32 tmp;
    if (func_004782b0((void*)v) == 1)
    {
        u8* p = MT_Scene_GetRes((w & 0x3FF) | 0x2800);
        if (p != 0)
        {
            func_004787e0(v);
            func_0029cf50(0);
            return 1;
        }
        flag = func_00145ac0(w & 0xFFFF, v) & 0xFFFF;
        while (*(s32*)(D_00762EA0 + 0x24) > 0)
        {
            p2 = (u8*)func_00151580(*(s32*)(D_00762EA0 + 0x28), w, &tmp);
            break;
        }
        if (p2 != 0)
        {
            f32 vec[3];
            p2 = (u8*)func_003e9700((s32)p2);
            vec[0] = func_0014b660(p2);
            vec[1] = func_0014b5d0(p2);
            vec[2] = func_0014b6f0(p2);
            func_00146e60(flag & 0xFFFF, (u8*)(p2 + 0x30), (u8 *)&vec);
            func_0047a1c0(v, p2, 0);
            func_00479940((u8*)v, 0, 0, 8, 1);
        }
        if (tmp == 1)
        {
            u8* r = MT_Scene_GetRes(flag & 0xFFFF);
            *(s32*)(r + 0x150) = 1;
        }
        created = 1;
    }
    func_0029cf50(flag);
    return created;
}

// FUN_00177D10
u32 func_00177d10()
{
    Model* model;
    u32 resourceId;
    u32 created;

    model = (Model*)func_0029cc00(0);
    resourceId = 0;
    created = 0;
    if (func_004782b0(model) == true)
    {
        resourceId = (u16)func_00145ac0(func_0014b510(10), (s32)model);
        created = 1;
    }
    func_0029cf50(resourceId);

    return created;
}





// FUN_00177DB0
s32 func_00177db0(void)
{
    s32 a = func_0029cc00(0);
    s32 b = func_0029cc00(1);
    u8* p = MT_Scene_GetRes(a);
    if (p != 0)
    {
        *(s32*)(p + 0x150) = b;
    }
    return 1;
}

// FUN_00177E20
u32 K_Cmd_CREATE_MDL()
{
    s32 type;
    s32 id;
    Model* mdl;

    type = func_0029cc00(0);
    id = func_0029cc00(1);

    mdl = func_00478140(type, id, 0);

    func_0029cf50((s32)mdl);

    return true;
}





// FUN_00177E80
s32 func_00177e80(void)
{
    s32 type = func_0029cc00(0);
    s32 id = func_0029cc00(1);
    s32 res = 0;
    s32 created = 0;
    if (func_004782b0((void*)type) == 1)
    {
        u8* p;
        res = (u16)func_00145780(func_0014b510(3), (u16)id, type);
        p = MT_Scene_GetRes(res);
        *(s32*)(p + 0x22C) = (s32)func_00478750(D_00764364);
        created = 1;
    }
    func_0029cf50(res);
    return created;
}



// FUN_00177F50
s32 func_00177f50(void)
{
    s32 v = func_0029cc00(0);
    f32 f = func_0029cd50(1);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            func_00168780(*(s32*)(p + 0x220), f);
        }
        break;
    }
    case 3:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            func_00168780(*(s32*)(p + 0x228), f);
            if (*(s32*)(p + 0x22C) != 0)
            {
                f32 vec[3];
                vec[2] = f;
                vec[1] = f;
                vec[0] = f;
                mdlScale(*(s32*)(p + 0x22C), vec, 2);
                func_00478e70(*(s32*)(p + 0x22C));
            }
        }
        break;
    }
    default:
        func_0046d730(D_005F1858, 0x404);
        break;
    }
    return 1;
}



// FUN_00178070
s32 func_00178070(void)
{
    s32 a = func_0029cc00(0);
    s32 b = func_0029cc00(1);
    func_0016f130(0, b, a);
    return 1;
}



// FUN_001780D0
s32 func_001780d0(void)
{
    s32 a = func_0029cc00(0);
    s32 b = func_0029cc00(1);
    func_0016f3b0(0, b, a);
    return 1;
}



// FUN_00178130
s32 func_00178130(void)
{
    s32 v = func_0029cc00(0);
    u8* p = func_00174c00();
    Vec3f diff;
    Vec3f v1;
    f32 v2x;
    f32 angle;
    f32 dot;
    if (p != 0)
    {
        v1 = *(Vec3f*)((u8*)mdlGetMatrix(*(s32*)(p + 0x144)) + 0x20);
        v2x = ((Vec3f*)((u8*)mdlGetMatrix(*(s32*)(p + 0x144)) + 0x30))->x;
        diff.x = v2x - ((Vec3f*)((u8*)mdlGetMatrix(D_007EFA00[0]) + 0x30))->x;
        v2x = ((Vec3f*)((u8*)mdlGetMatrix(*(s32*)(p + 0x144)) + 0x30))->y;
        diff.y = v2x - ((Vec3f*)((u8*)mdlGetMatrix(D_007EFA00[0]) + 0x30))->y;
        v2x = ((Vec3f*)((u8*)mdlGetMatrix(*(s32*)(p + 0x144)) + 0x30))->z;
        diff.z = v2x - ((Vec3f*)((u8*)mdlGetMatrix(D_007EFA00[0]) + 0x30))->z;
        RwV3dNormalize(&diff.x, &diff.x);
        RwV3dNormalize(&v1.x, &v1.x);
        func_0014b5d0((u8*)func_003e9700(*(s32*)((u8*)func_00457120() + 4)));
        dot = diff.x * v1.x + diff.y * v1.y + diff.z * v1.z;
        if (dot < 0.0f)
        {
            v1.x = -v1.x;
            v1.y = -v1.y;
            v1.z = -v1.z;
        }
        if (v1.x > 0.5f)
        {
            angle = 90.0f;
        }
        else if (v1.x < -0.5f)
        {
            angle = 270.0f;
        }
        else if (v1.z > 0.5f)
        {
            angle = 0.0f;
        }
        else if (v1.z < -0.5f)
        {
            angle = 180.0f;
        }
        func_0016f3b0(0, v, (s32)angle);
    }
    return 1;
}



// FUN_00178360
s32 func_00178360(void)
{
    D_00724B3C = func_0029cc00(0);
    D_00724B40 = func_0029cc00(1);
    D_00724B44 = func_0029cc00(2);
    D_00724B48 = 0;
    return 1;
}

// FUN_001783B0
s32 func_001783b0(void)
{
    u8 temp_17;
    u8 temp_16;

    temp_17 = func_0029cc00(0) & 0xFF;
    temp_16 = func_0029cc00(1) & 0xFF;
    func_00457140(temp_17, temp_16, func_0029cc00(2) & 0xFF, 0);
    return 1;
}





// FUN_00178420
s32 func_00178420(void)
{
    f32 value = func_0029cd50(0);
    *(f32*)((u8*)func_00457120() + 0x88) = value;
    func_00457120();
    return 1;
}

// FUN_00178470
s32 func_00178470(void)
{
    D_00764B5C = func_0029cd50(0);
    return 1;
}





// FUN_001784A0
s32 func_001784a0(void)
{
    u16* p = func_00174c00();
    if (p != 0)
    {
        func_0029cf50(*p);
    }
    else
    {
        func_0046d730(D_005F1858, 0x462);
    }
    return 1;
}



// FUN_00178500
s32 func_00178500(void)
{
    u16* p = func_00174c10();
    if (p != 0)
    {
        func_0029cf50(*p);
    }
    else
    {
        func_0046d730(D_005F1858, 0x474);
    }
    return 1;
}

// FUN_00178970
u32 func_00178970()
{
    s32 resourceId;
    s32 value;

    resourceId = func_0029cc00(0);
    value = func_0029cc00(1);

    return func_002bd360(resourceId, value) == 0;
}



// FUN_0025D100
u32 func_0025d100()
{
    func_0029cf50((u8)func_00106600((s16)func_0029cc00(0)));

    return true;
}
