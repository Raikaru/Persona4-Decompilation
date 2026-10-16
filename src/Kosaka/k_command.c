#include "mt_scene_internal.h"
#include "model_callbacks_internal.h"
#include "model_motion_internal.h"
/* Source unit: "k_command.c" (__FILE__ group 0x00176C70..0x00178500; P3 twin src/Kosaka/k_command.c). Members 0x0025C6D0, 0x0025D100 and 0x00299FD0 have no __FILE__ evidence; they stay in this file as its existing members. */
#include "Kosaka/k_command_internal.h"
#include "scr_internal.h"

extern char* strcpy(char* destination, const char* source);
extern s32 sprintf(char* destination, const char* format, ...);
extern char* strcat(char* destination, const char* source);
#include "type.h"
#include "scene_event_internal.h"
#include "model_matrix_internal.h"
#include "include_asm.h"

extern void kwlnSetColorRgba(u8 arg0, u8 arg1, u8 arg2, u8 arg3);

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

extern void kAssertFail(const char* file, s32 line);
extern s32 kwlnGetCamera(void);
extern void* FldEvent_GetNearestEntry(void);
extern void* FldEvent_GetTriggerEntry(void);
extern s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 value);
extern s32 datCalcGetLevelById(s32 value);
extern u8* MT_Scene_GetResListHead(s32 arg0);
extern void FldFrame_RotateTaskCreate(s32 a, s32 b, s32 c);
extern void FldFrameRotateTaskCreate(s32 a, s32 b, s32 c);
extern s32 mdlPrepareModel(void* arg0);
extern void* mdlCloneModelObject(s32 arg0);
extern void mdlDestroyModelObject(u32 arg0);
extern void mdlAdvanceModelFromFlags(s32 arg0);
extern void mdlSetLayerTime(s32 a, s32 b, f32 c);
extern void mdlApplyModelMatrix(s32 a, void* b, s32 c);
extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
extern void mdlSetLayerWeight(s32 arg0, s32 arg1, f32 arg2);
extern void* mdlGetMatrix(u32 arg0);
extern void mdlScale(s32 arg0, void* arg1, s32 arg2);
extern f32 KDraw_MatrixPitchDeg(u8* arg0);
extern f32 KDraw_MatrixYawDeg(u8* arg0);
extern f32 KDraw_MatrixRollDeg(u8* arg0);
extern s32 FldResource_FindFrameForId(s32 a, s32 b, s32* c);
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
extern s32 FldFrameTask_SetHeight(s32 arg0, f32 arg1);
extern f32 FldFrameTask_GetHeight(s32 arg0);
extern void FldFrameTask_UpdateTile(s32 arg0);
extern void FldStepUpdateBandRes(void);
extern void FldCameraUpdateOrbit(s32 arg0);
extern void FldAI_ChaserDisable(s32 arg0);
extern void FldShadow_SetRingParticles(s32 arg0, f32 arg1);
extern u8* MT_Scene_GetFrameState(void);

typedef struct
{
    f32 x, y, z;
} Vec3f;

typedef struct
{
    f32 m[16];
} Mat4;



extern s32 FldStepIndex(void);
extern void (*jtbl_008873EC[])(void *);
extern s32 FldSceneLoadReady(void);
extern void fclMiscStopAndClose(void);
extern void fclMiscSetDoneFlag(void);
/* Script command 0x1002 (group 1 table 0x63D440 + 0x010, FLD_FUNCTION_0002). */
// FUN_00176880
s32 K_Cmd_FLD_STEP_INDEX(void)
{
    scrSetReturnInt(FldStepIndex());
    return 1;
}


/* Script command 0x1000 (group 1 table 0x63D440 + 0x000, FLD_FUNCTION_0000). */
// FUN_001768B0
s32 K_Cmd_FLD_SCENE_LOAD_READY(void)
{
    scrSetReturnInt(FldSceneLoadReady());
    return 1;
}


// FUN_00176C20
u32 Cmd_SetSceneResourceParam()
{
    s32 resourceId;

    resourceId = scrGetParamInt(0);
    SceneDraw_SetResVisible((u16)resourceId, scrGetParamInt(1));
    return true;
}





/* Retail command operands narrow animation to s16 and converted frame to
   u16 at each dispatch; these are caller conversions, not the shared ABI. */
// FUN_00176C70
s32 Cmd_PlayModelMotion(void)
{
    s32 v = scrGetParamInt(0);
    s32 w = scrGetParamInt(1);
    s32 x = scrGetParamInt(2);
    s32 iv = (s32)scrGetParamFloat(3);
    f32 g = scrGetParamFloat(4);
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
                mdlDispatchAnimIfPresent((u8*)*(s32*)(p + 0x164), 0, (s16)w, (u16)iv, 1);
            }
            else
            {
                mdlDispatchAnimIfPresent((u8*)*(s32*)(p + 0x164), 0, (s16)w, (u16)iv, 0);
            }
            mdlSetLayerWeight(*(s32*)(p + 0x164), 0, g);
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
                mdlDispatchAnimIfPresent((u8*)*(s32*)(p + 0x164), 0, (s16)w, (u16)iv, 1);
            }
            else
            {
                mdlDispatchAnimIfPresent((u8*)*(s32*)(p + 0x164), 0, (s16)w, (u16)iv, 0);
            }
            mdlSetLayerWeight(*(s32*)(p + 0x164), 0, g);
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
                mdlDispatchAnimIfPresent((u8*)*(s32*)(p + 0x144), 0, (s16)w, (u16)iv, 1);
            }
            else
            {
                mdlDispatchAnimIfPresent((u8*)*(s32*)(p + 0x144), 0, (s16)w, (u16)iv, 0);
            }
            mdlSetLayerWeight(*(s32*)(p + 0x144), 0, g);
        }
        break;
    }
    default:
        kAssertFail(D_005F1858, 0x1E0);
        break;
    }
    return 1;
}



// FUN_00176EF0
s32 Cmd_CheckModelFlag(void)
{
    s32 v = scrGetParamInt(0);
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
        kAssertFail(D_005F1858, 0x212);
        break;
    }
    return 1;
}



// FUN_00176FF0
s32 Cmd_SetModelFloatParam(void)
{
    s32 v = scrGetParamInt(0);
    f32 f = scrGetParamFloat(1);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            mdlSetLayerTime(*(s32*)(p + 0x164), 0, f);
        }
        break;
    }
    case 3:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            mdlSetLayerTime(*(s32*)(p + 0x164), 0, f);
        }
        break;
    }
    case 10:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            mdlSetLayerTime(*(s32*)(p + 0x144), 0, f);
        }
        break;
    }
    default:
        kAssertFail(D_005F1858, 0x23C);
        break;
    }
    return 1;
}



// FUN_00177120
s32 Cmd_CompareModelThreshold(void)
{
    s32 v = scrGetParamInt(0);
    f32 threshold = 0.0f;
    f32 f = scrGetParamFloat(1);
    s32 k = (v & 0xFFC00) >> 10;
    u8* p;
    s32 result;
    switch (k)
    {
    case 1:
        p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            threshold = mdlGetLayerWeight(*(s32*)(p + 0x164), 0);
        }
        break;
    case 3:
        if (MT_Scene_GetRes(v & 0xFFFF) != 0)
        {
            threshold = mdlGetLayerWeight(*(s32*)(p + 0x164), 0);
        }
        break;
    case 10:
        if (MT_Scene_GetRes(v & 0xFFFF) != 0)
        {
            threshold = mdlGetLayerWeight(*(s32*)(p + 0x164), 0);
        }
        break;
    default:
        kAssertFail(D_005F1858, 0x264);
        break;
    }
    return (f >= threshold) ^ 1;
}



// FUN_00177280
s32 Cmd_SetModelScale(void)
{
    s32 v = scrGetParamInt(0);
    f32 pos[3];
    s32 k;
    pos[0] = scrGetParamFloat(1);
    pos[1] = scrGetParamFloat(1);
    pos[2] = scrGetParamFloat(1);
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
        kAssertFail(D_005F1858, 0x294);
        break;
    }
    return 1;
}



// FUN_001773D0
s32 Cmd_SetShadowRingRadius(void)
{
    s32 v = scrGetParamInt(0);
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
            f32 f = scrGetParamFloat(1);
            FldShadow_SetRingParticles(*(s32*)(p + 0x230), f);
        }
        break;
    }
    case 10:
        break;
    default:
        kAssertFail(D_005F1858, 0x2B2);
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
s32 Cmd_PlaceFieldResource(void)
{
    s32 resourceId;
    s32 placementId;
    u8 *placement;
    s32 resourceType;
    f32 translation[3];
    f32 negativeTranslation[3];
    resourceId = scrGetParamInt(0);
    placementId = scrGetParamInt(1);
    placement = MT_Scene_GetResListHead(14);
    {
        Vec3f rotationAxis = {0.0f, 1.0f, 0.0f};
        if (placement == 0) {
            kAssertFail(D_005F1858, 0x2C3);
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
                mdlTranslateMatrix(*(s32 *)(resource + 0x164), negativeTranslation, 2);
                mdlRotateMatrix((void *)(u32)*(s32 *)(resource + 0x164), &rotationAxis, *(f32 *)(placement + 0x14C), 0);
                mdlTranslateMatrix(*(s32 *)(resource + 0x164), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x164));
                *(Vec3f *)(matrix + 0x30) = *(Vec3f *)(placement + 0x140);
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x164)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix(*(s32 *)(resource + 0x164)));
                FldFrameTask_UpdateTile(*(s32 *)(resource + 0x220));
                FldStepUpdateBandRes();
                for (i = 0; i < 3; i++) {
                    hasWork = 0;
                    entry = D_007EF9B0 + i * 0x750;
                    if (*(s32 *)(entry + 0x798) != 0) {
                        if (*(s32 *)(entry + 0x7A4) != 0) {
                            hasWork = 1;
                        }
                    }
                    if (fieldPlacementEnabled(hasWork) && *(s32 *)(entry + 0x900) != 0) {
                        FldAI_ChaserDisable(*(s32 *)(entry + 0x900));
                    }
                }
                fieldState = MT_Scene_GetFrameState();
                if (*(s32 *)(fieldState + 4) != 0) {
                    FldCameraUpdateOrbit(*(s32 *)(MT_Scene_GetFrameState() + 4));
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
                mdlTranslateMatrix(*(s32 *)(resource + 0x164), negativeTranslation, 2);
                mdlRotateMatrix((void *)(u32)*(s32 *)(resource + 0x164), &rotationAxis, *(f32 *)(placement + 0x14C), 2);
                mdlTranslateMatrix(*(s32 *)(resource + 0x164), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x164));
                *(Vec3f *)(matrix + 0x30) = *(Vec3f *)(placement + 0x140);
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x164)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix(*(s32 *)(resource + 0x164)));
                if (*(s32 *)(resource + 0x22C) != 0) {
                    uniformScale = FldFrameTask_GetHeight(*(s32 *)(resource + 0x228));
                    scale[2] = uniformScale;
                    scale[1] = uniformScale;
                    scale[0] = uniformScale;
                    mdlRotateMatrix((void *)(u32)*(s32 *)(resource + 0x22C), &rotationAxis, *(f32 *)(placement + 0x14C), 2);
                    mdlScale(*(s32 *)(resource + 0x22C), scale, 2);
                    mdlTranslateMatrix(*(s32 *)(resource + 0x22C), placement + 0x140, 2);
                    mdlAdvanceModelFromFlags(*(s32 *)(resource + 0x22C));
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
                mdlTranslateMatrix(*(s32 *)(resource + 0x144), negativeTranslation, 2);
                mdlRotateMatrix((void *)(u32)*(s32 *)(resource + 0x144), &rotationAxis, *(f32 *)(placement + 0x14C), 0);
                mdlTranslateMatrix(*(s32 *)(resource + 0x144), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x144));
                *(Vec3f *)(matrix + 0x30) = *(Vec3f *)(placement + 0x140);
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x144)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix(*(s32 *)(resource + 0x144)));
            }
            break;
        }
        default:
            kAssertFail(D_005F1858, 0x337);
            break;
        }
        return 1;
    }
}

/* P4 flowscript library (build/p4flow/Field.json, index 0x100D): FLD_NPC_MODEL_LOAD(major, minor). The P3 name is kept. */
// FUN_00177A10
u32 K_Cmd_CREATE_FLD_MDL()
{
    char path[64];
    char buff[64];
    s32 majorId;
    u32 minorId;
    Model* mdl;

    majorId = scrGetParamInt(0);
    minorId = scrGetParamInt(1);

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

    mdl = mdlCreateModelObjectFromData(4, minorId, path, 0);
    scrSetReturnInt((s32)mdl);

    return true;
}





// FUN_00177B30
s32 Cmd_CreateFieldModel(void)
{
    s32 v = scrGetParamInt(0);
    s32 w = scrGetParamInt(1);
    s32 flag = 0;
    s32 created = 0;
    u8* p2 = 0;
    s32 tmp;
    if (mdlPrepareModel((void*)v) == 1)
    {
        u8* p = MT_Scene_GetRes((w & 0x3FF) | 0x2800);
        if (p != 0)
        {
            mdlDestroyModelObject(v);
            scrSetReturnInt(0);
            return 1;
        }
        flag = MT_Scene_CreateModelFldRes(w & 0xFFFF, v) & 0xFFFF;
        while (*(s32*)(D_00762EA0 + 0x24) > 0)
        {
            p2 = (u8*)FldResource_FindFrameForId(*(s32*)(D_00762EA0 + 0x28), w, &tmp);
            break;
        }
        if (p2 != 0)
        {
            f32 vec[3];
            p2 = (u8*)func_003e9700((s32)p2);
            vec[0] = KDraw_MatrixPitchDeg(p2);
            vec[1] = KDraw_MatrixYawDeg(p2);
            vec[2] = KDraw_MatrixRollDeg(p2);
            MT_Scene_SetResPlacement(flag & 0xFFFF, (u8*)(p2 + 0x30), (u8 *)&vec);
            mdlApplyModelMatrix(v, p2, 0);
            mdlDispatchAnimIfPresent((u8*)v, 0, 0, 8, 1);
        }
        if (tmp == 1)
        {
            u8* r = MT_Scene_GetRes(flag & 0xFFFF);
            *(s32*)(r + 0x150) = 1;
        }
        created = 1;
    }
    scrSetReturnInt(flag);
    return created;
}

// FUN_00177D10
u32 Cmd_CreateModelResource()
{
    Model* model;
    u32 resourceId;
    u32 created;

    model = (Model*)scrGetParamInt(0);
    resourceId = 0;
    created = 0;
    if (mdlPrepareModel(model) == true)
    {
        resourceId = (u16)MT_Scene_CreateModelFldRes(MT_Scene_FindFreeResId(10), (s32)model);
        created = 1;
    }
    scrSetReturnInt(resourceId);

    return created;
}





// FUN_00177DB0
s32 Cmd_SetResourceWord150(void)
{
    s32 a = scrGetParamInt(0);
    s32 b = scrGetParamInt(1);
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

    type = scrGetParamInt(0);
    id = scrGetParamInt(1);

    mdl = mdlFindOrCreateModelObject((u16)type, id, 0);

    scrSetReturnInt((s32)mdl);

    return true;
}





// FUN_00177E80
s32 Cmd_CreateSceneResource(void)
{
    s32 type = scrGetParamInt(0);
    s32 id = scrGetParamInt(1);
    s32 res = 0;
    s32 created = 0;
    if (mdlPrepareModel((void*)type) == 1)
    {
        u8* p;
        res = (u16)MT_Scene_CreateModelNpcShadowRes(MT_Scene_FindFreeResId(3), (u16)id, type);
        p = MT_Scene_GetRes(res);
        *(s32*)(p + 0x22C) = (s32)mdlCloneModelObject(D_00764364);
        created = 1;
    }
    scrSetReturnInt(res);
    return created;
}



// FUN_00177F50
s32 Cmd_SetFieldFloat(void)
{
    s32 v = scrGetParamInt(0);
    f32 f = scrGetParamFloat(1);
    s32 k = (v & 0xFFC00) >> 10;
    switch (k)
    {
    case 1:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            FldFrameTask_SetHeight(*(s32*)(p + 0x220), f);
        }
        break;
    }
    case 3:
    {
        u8* p = MT_Scene_GetRes(v & 0xFFFF);
        if (p != 0)
        {
            FldFrameTask_SetHeight(*(s32*)(p + 0x228), f);
            if (*(s32*)(p + 0x22C) != 0)
            {
                f32 vec[3];
                vec[2] = f;
                vec[1] = f;
                vec[0] = f;
                mdlScale(*(s32*)(p + 0x22C), vec, 2);
                mdlAdvanceModelFromFlags(*(s32*)(p + 0x22C));
            }
        }
        break;
    }
    default:
        kAssertFail(D_005F1858, 0x404);
        break;
    }
    return 1;
}



/* P4 flowscript library (build/p4flow/Field.json, index 0x1017): FLD_CAMERA_ROTATE(degrees, speed).
 * FldFrame_RotateTaskCreate creates a camera rotation task: yaw delta from the player's yaw plus degrees, at speed. */
// FUN_00178070
s32 K_Cmd_FLD_CAMERA_ROTATE(void)
{
    s32 a = scrGetParamInt(0);
    s32 b = scrGetParamInt(1);
    FldFrame_RotateTaskCreate(0, b, a);
    return 1;
}



/* P4 flowscript library (build/p4flow/Field.json, index 0x1018): FLD_CAMERA_ROTATE_BEHIND(degrees, speed).
 * FldFrameRotateTaskCreate takes an absolute target yaw (wrapped to 360) where FldFrame_RotateTaskCreate adds
 * degrees to the player's yaw. The library name is kept. */
// FUN_001780D0
s32 K_Cmd_FLD_CAMERA_ROTATE_BEHIND(void)
{
    s32 a = scrGetParamInt(0);
    s32 b = scrGetParamInt(1);
    FldFrameRotateTaskCreate(0, b, a);
    return 1;
}



// FUN_00178130
s32 Cmd_FaceNearestAxis(void)
{
    s32 v = scrGetParamInt(0);
    u8* p = FldEvent_GetNearestEntry();
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
        KDraw_MatrixYawDeg((u8*)func_003e9700(*(s32*)((u8*)kwlnGetCamera() + 4)));
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
        FldFrameRotateTaskCreate(0, v, (s32)angle);
    }
    return 1;
}



// FUN_00178360
s32 Cmd_SetWorkValues(void)
{
    D_00724B3C = scrGetParamInt(0);
    D_00724B40 = scrGetParamInt(1);
    D_00724B44 = scrGetParamInt(2);
    D_00724B48 = 0;
    return 1;
}

// FUN_001783B0
s32 Cmd_SetSceneMode(void)
{
    u8 temp_17;
    u8 temp_16;

    temp_17 = scrGetParamInt(0) & 0xFF;
    temp_16 = scrGetParamInt(1) & 0xFF;
    kwlnSetColorRgba(temp_17, temp_16, scrGetParamInt(2) & 0xFF, 0);
    return 1;
}





// FUN_00178420
s32 Cmd_SetCameraFloat(void)
{
    f32 value = scrGetParamFloat(0);
    *(f32*)((u8*)kwlnGetCamera() + 0x88) = value;
    kwlnGetCamera();
    return 1;
}

// FUN_00178470
s32 Cmd_SetFloatGlobal(void)
{
    D_00764B5C = scrGetParamFloat(0);
    return 1;
}





// FUN_001784A0
s32 Cmd_LoadFieldWord(void)
{
    u16* p = FldEvent_GetNearestEntry();
    if (p != 0)
    {
        scrSetReturnInt(*p);
    }
    else
    {
        kAssertFail(D_005F1858, 0x462);
    }
    return 1;
}



// FUN_00178500
s32 Cmd_LoadFieldWordAlt(void)
{
    u16* p = FldEvent_GetTriggerEntry();
    if (p != 0)
    {
        scrSetReturnInt(*p);
    }
    else
    {
        kAssertFail(D_005F1858, 0x474);
    }
    return 1;
}

// FUN_00178970
u32 Cmd_TestResourceValue()
{
    s32 resourceId;
    s32 value;

    resourceId = scrGetParamInt(0);
    value = scrGetParamInt(1);

    return fclMiscHasEntry(resourceId, value) == 0;
}



/* Script command 0x102C (group 1 table 0x63D440 + 0x160, FLD_FUNCTION_002C). */
// FUN_001789D0
s32 K_Cmd_FLD_RESET_FCL_CHANNEL(void)
{
    fclMiscStopAndClose();
    fclMiscSetDoneFlag();
    return 1;
}


s32 datGetTimeSlot(void);
// Intent: Script command: returns the current time slot (datGetTimeSlot) as the script return value [inferred]
// FUN_0025C420
s32 scrGetTimeSlot(void) {
    scrSetReturnInt(datGetTimeSlot() & 0xFF);
    return 1;
}


// FUN_0025C6D0
u32 Cmd_SetResourceValueByte(void)
{
    s32 rawResourceId;
    u16 resourceId;
    s32 value;

    rawResourceId = scrGetParamInt(0);
    value = scrGetParamInt(1);
    resourceId = (u16)(rawResourceId & 0x3ff) | 0x400;
    MT_Scene_SpawnResIconTask(resourceId, (u8)value);
    return 1;
}


// FUN_0025D100
u32 Cmd_LoadTableWord()
{
    scrSetReturnInt((u8)datItemCount((s16)scrGetParamInt(0)));

    return true;
}

u32 datCalcGetHpById(s16 arg0);
u16 datCalcMaxHpById(s16 arg0);
u32 datCalcGetSpById(s16 arg0);
extern void datSetUnitHp(s16 arg0, s16 arg1);
extern s64 scrGetParamIntS64(s32 arg0);
extern s32 cmmCommunityGetCurrentSecondary(void);
extern u16 datCalcMaxSpById(s16 arg0);
extern void datSetUnitSp(s16 arg0, s16 arg1);
/* Script command 0x300D (group 3 table 0x63DE80 + 0x68, EVT_FUNCTION_000D). */
// FUN_00298340
s32 K_Cmd_CMM_COMMUNITY_CURRENT_SECONDARY(void) {
    scrSetReturnInt(cmmCommunityGetCurrentSecondary());
    return 1;
}


/* Script command 0x5E (group 0 table 0x63D070 + 0x2F0, FUNCTION_005E). */
// FUN_00299C60
s32 K_Cmd_CALC_GET_HP(void) {
    scrSetReturnInt(datCalcGetHpById(scrGetParamInt(0)) & 0xFFFF);
    return 1;
}


/* Script command 0x5F (group 0 table 0x63D070 + 0x2F8, FUNCTION_005F). */
// FUN_00299CB0
s32 K_Cmd_CALC_MAX_HP(void) {
    scrSetReturnInt(datCalcMaxHpById((s16)scrGetParamInt(0)) & 0xFFFF);
    return 1;
}


/* Script command 0x60 (group 0 table 0x63D070 + 0x300, FUNCTION_0060). */
// FUN_00299D00
s32 K_Cmd_SET_UNIT_HP(void)
{
    s64 temp_16;
    s64 temp_17;

    temp_16 = scrGetParamIntS64(0);
    temp_17 = scrGetParamIntS64(1);
    datSetUnitHp((s16)temp_16, (s16)temp_17);
    return 1;
}


/* Script command 0x61 (group 0 table 0x63D070 + 0x308, FUNCTION_0061). */
// FUN_00299D60
s32 K_Cmd_CALC_GET_SP(void) {
    scrSetReturnInt(datCalcGetSpById(scrGetParamInt(0)) & 0xFFFF);
    return 1;
}


/* Script command 0x62 (group 0 table 0x63D070 + 0x310, FUNCTION_0062). */
// FUN_00299DB0
s32 K_Cmd_CALC_MAX_SP(void) {
    scrSetReturnInt(datCalcMaxSpById((s16)scrGetParamIntS64(0)) & 0xFFFF);
    return 1;
}


/* Script command 0x63 (group 0 table 0x63D070 + 0x318, FUNCTION_0063). */
// FUN_00299E00
s32 K_Cmd_SET_UNIT_SP(void)
{
    s64 temp_16;
    s64 temp_17;

    temp_16 = scrGetParamIntS64(0);
    temp_17 = scrGetParamIntS64(1);
    datSetUnitSp((s16)temp_16, (s16)temp_17);
    return 1;
}


// FUN_00299FD0
u32 Cmd_LoadTableWordAlt(void)
{
    scrSetReturnInt((u8)datCalcGetLevelById((s16)scrGetParamInt(0)));

    return 1;
}
extern void fclClearMoonFlagEntries(void);
extern void fclCombineApplyPackedResult(void);
/* Script command 0x56 (group 0 table 0x63D070 + 0x2B0, FUNCTION_0056). */
// FUN_00331950
s32 K_Cmd_FCL_CLEAR_APPLY_COMBINE(void)
{
    fclClearMoonFlagEntries();
    fclCombineApplyPackedResult();
    return 1;
}


