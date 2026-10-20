#include "rw_camera_internal.h"
#include "Kosaka/k_field_state_internal.h"
#include "mdl_file_internal.h"
#include "resrc_manager_internal.h"
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

extern void kwlnSetColorRgba(u8 red, u8 green, u8 blue, u8 alpha);

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
extern s32 MT_Scene_SpawnResIconTask(u32 resourceId, u32 icon);
extern s32 datCalcGetLevelById(s32 unitId);
extern u8* MT_Scene_GetResListHead(s32 resourceType);
extern void FldFrame_RotateTaskCreate(s32 parentTask, s32 duration, s32 relativeAngle);
extern void FldFrameRotateTaskCreate(s32 parentTask, s32 duration, s32 absoluteAngle);
extern s32 mdlPrepareModel(void* model);
extern void* mdlCloneModelObject(s32 source);
extern void mdlDestroyModelObject(u32 model);
extern void mdlAdvanceModelFromFlags(s32 model);
extern void mdlSetLayerTime(s32 model, s32 layer, f32 frameValue);
extern void mdlApplyModelMatrix(s32 model, void* matrix, s32 combineOp);
extern f32 mdlGetLayerWeight(s32 model, s32 layer);
extern void mdlSetLayerWeight(s32 model, s32 layer, f32 speed);
extern void* mdlGetMatrix(u32 model);
extern void mdlScale(s32 model, void* scale, s32 combineOp);
extern f32 KDraw_MatrixPitchDeg(u8* matrix);
extern f32 KDraw_MatrixYawDeg(u8* matrix);
extern f32 KDraw_MatrixRollDeg(u8* matrix);
extern s32 FldResource_FindFrameForId(s32 resource, s32 entryId, s32* flagsOut);
extern s32 func_003e9700(s32);
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
extern s32 FldFrameTask_SetHeight(s32 task, f32 height);
extern f32 FldFrameTask_GetHeight(s32 task);
extern void FldFrameTask_UpdateTile(s32 task);
extern void FldStepUpdateBandRes(void);
extern void FldCameraUpdateOrbit(s32 task);
extern void FldAI_ChaserDisable(s32 task);
extern void FldShadow_SetRingParticles(s32 task, f32 radius);
extern u8* MT_Scene_GetFrameState(void);

typedef RwV3d Vec3f;

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


/* Set scene-resource visibility using the script resource identifier narrowed to a halfword. */
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
/* measured: typing the model-pointer reads in the looping dispatch branches individually loses MATCH; the
 * non-looping branches and weight calls remain typed. */
// FUN_00176C70
s32 Cmd_PlayModelMotion(void)
{
    s32 resourceId = scrGetParamInt(0);
    s32 animationId = scrGetParamInt(1);
    s32 loop = scrGetParamInt(2);
    s32 frame = (s32)scrGetParamFloat(3);
    f32 weight = scrGetParamFloat(4);
    s32 resourceType = (resourceId & 0xFFC00) >> 10;
    switch (resourceType)
    {
    case 1:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            if (loop != 0)
            {
                mdlDispatchAnimIfPresent((u8*)*(s32*)(resource + 0x164), 0, (s16)animationId, (u16)frame, 1);
            }
            else
            {
                mdlDispatchAnimIfPresent((u8 *)((ResrcRecord *)resource)->modelHandle164, 0, (s16)animationId, (u16)frame, 0);
            }
            mdlSetLayerWeight((s32)((ResrcRecord *)resource)->modelHandle164, 0, weight);
        }
        break;
    }
    case 3:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            if (loop != 0)
            {
                mdlDispatchAnimIfPresent((u8*)*(s32*)(resource + 0x164), 0, (s16)animationId, (u16)frame, 1);
            }
            else
            {
                mdlDispatchAnimIfPresent((u8 *)((ResrcRecord *)resource)->modelHandle164, 0, (s16)animationId, (u16)frame, 0);
            }
            mdlSetLayerWeight((s32)((ResrcRecord *)resource)->modelHandle164, 0, weight);
        }
        break;
    }
    case 10:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            if (loop != 0)
            {
                mdlDispatchAnimIfPresent((u8*)*(s32*)(resource + 0x144), 0, (s16)animationId, (u16)frame, 1);
            }
            else
            {
                mdlDispatchAnimIfPresent((u8 *)((ResrcRecord *)resource)->slotHandle[1], 0, (s16)animationId, (u16)frame, 0);
            }
            mdlSetLayerWeight((s32)((ResrcRecord *)resource)->slotHandle[1], 0, weight);
        }
        break;
    }
    default:
        kAssertFail(D_005F1858, 0x1E0);
        break;
    }
    return 1;
}



/* Query the completion byte of the selected character, NPC, or field model. */
// FUN_00176EF0
s32 Cmd_CheckModelFlag(void)
{
    s32 resourceId = scrGetParamInt(0);
    s32 resourceType = (resourceId & 0xFFC00) >> 10;
    switch (resourceType)
    {
    case 1:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            return ((MdlFileModel *)((s32)((ResrcRecord *)resource)->modelHandle164))->finished == 1;
        }
        break;
    }
    case 3:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            return ((MdlFileModel *)((s32)((ResrcRecord *)resource)->modelHandle164))->finished == 1;
        }
        break;
    }
    case 10:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            return ((MdlFileModel *)((s32)((ResrcRecord *)resource)->slotHandle[1]))->finished == 1;
        }
        break;
    }
    default:
        kAssertFail(D_005F1858, 0x212);
        break;
    }
    return 1;
}



/* Set animation-layer zero time for the selected resource model. */
// FUN_00176FF0
s32 Cmd_SetModelFloatParam(void)
{
    s32 resourceId = scrGetParamInt(0);
    f32 time = scrGetParamFloat(1);
    s32 resourceType = (resourceId & 0xFFC00) >> 10;
    switch (resourceType)
    {
    case 1:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            mdlSetLayerTime((s32)((ResrcRecord *)resource)->modelHandle164, 0, time);
        }
        break;
    }
    case 3:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            mdlSetLayerTime((s32)((ResrcRecord *)resource)->modelHandle164, 0, time);
        }
        break;
    }
    case 10:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            mdlSetLayerTime((s32)((ResrcRecord *)resource)->slotHandle[1], 0, time);
        }
        break;
    }
    default:
        kAssertFail(D_005F1858, 0x23C);
        break;
    }
    return 1;
}



/* Compare the script value with layer-zero weight; retain the existing resource-local reuse in types 3 and 10. */
// FUN_00177120
s32 Cmd_CompareModelThreshold(void)
{
    s32 resourceId = scrGetParamInt(0);
    f32 threshold = 0.0f;
    f32 value = scrGetParamFloat(1);
    s32 resourceType = (resourceId & 0xFFC00) >> 10;
    u8* resource;
    s32 result;
    switch (resourceType)
    {
    case 1:
        resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            threshold = mdlGetLayerWeight((s32)((ResrcRecord *)resource)->modelHandle164, 0);
        }
        break;
    case 3:
        if (MT_Scene_GetRes(resourceId & 0xFFFF) != 0)
        {
            threshold = mdlGetLayerWeight((s32)((ResrcRecord *)resource)->modelHandle164, 0);
        }
        break;
    case 10:
        if (MT_Scene_GetRes(resourceId & 0xFFFF) != 0)
        {
            threshold = mdlGetLayerWeight((s32)((ResrcRecord *)resource)->modelHandle164, 0);
        }
        break;
    default:
        kAssertFail(D_005F1858, 0x264);
        break;
    }
    return (value >= threshold) ^ 1;
}



/* Apply uniform scaling; retail reads parameter one for all three components. */
// FUN_00177280
s32 Cmd_SetModelScale(void)
{
    s32 resourceId = scrGetParamInt(0);
    f32 scale[3];
    s32 resourceType;
    scale[0] = scrGetParamFloat(1);
    scale[1] = scrGetParamFloat(1);
    scale[2] = scrGetParamFloat(1);
    resourceType = (resourceId & 0xFFC00) >> 10;
    switch (resourceType)
    {
    case 1:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            mdlScale((s32)((ResrcRecord *)resource)->modelHandle164, scale, 2);
        }
        break;
    }
    case 3:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            mdlScale((s32)((ResrcRecord *)resource)->modelHandle164, scale, 2);
        }
        break;
    }
    case 10:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            mdlScale((s32)((ResrcRecord *)resource)->slotHandle[1], scale, 2);
        }
        break;
    }
    default:
        kAssertFail(D_005F1858, 0x294);
        break;
    }
    return 1;
}



/* Set the ring-particle radius only for NPC resources with a shadow handle. */
/* measured: typing the shadow-handle guard loses MATCH; the handle passed after the guard stays typed. */
// FUN_001773D0
s32 Cmd_SetShadowRingRadius(void)
{
    s32 resourceId = scrGetParamInt(0);
    s32 resourceType = (resourceId & 0xFFC00) >> 10;
    switch (resourceType)
    {
    case 1:
        break;
    case 3:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0 && *(s32*)(resource + 0x230) != 0)
        {
            f32 radius = scrGetParamFloat(1);
            FldShadow_SetRingParticles(((ResrcRecord *)resource)->handle230, radius);
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
/* measured: typing the remaining model-handle, heading, or translated-placement operands individually loses
 * MATCH. The position aggregate copies reinterpret the named three-float placement array as the native
 * vector type. */
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
            placement = (u8 *)((ResrcRecord *)placement)->next;
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
                *(Vec3f *)translation = ((struct RwMatrixTag *)(matrix))->pos;
                negativeTranslation[0] = -1.0f * translation[0];
                negativeTranslation[1] = -1.0f * translation[1];
                negativeTranslation[2] = -1.0f * translation[2];
                mdlTranslateMatrix(*(s32 *)(resource + 0x164), negativeTranslation, 2);
                mdlRotateMatrix((void *)(u32)*(s32 *)(resource + 0x164), &rotationAxis, *(f32 *)(placement + 0x14C), 0);
                mdlTranslateMatrix(*(s32 *)(resource + 0x164), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x164));
                ((struct RwMatrixTag *)(matrix))->pos = *(Vec3f *)((ResrcRecord *)placement)->placement;
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x164)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix((s32)((ResrcRecord *)resource)->modelHandle164));
                FldFrameTask_UpdateTile(((ResrcRecord *)resource)->handle220);
                FldStepUpdateBandRes();
                for (i = 0; i < 3; i++) {
                    hasWork = 0;
                    entry = D_007EF9B0 + i * 0x750;
                    if (((FldPartySlot *)entry)[1].active != 0) {
                        if ((s32)((FldPartySlot *)entry)[1].resource != 0) {
                            hasWork = 1;
                        }
                    }
                    if (fieldPlacementEnabled(hasWork) && ((FldPartySlot *)entry)[1].chaser != 0) {
                        FldAI_ChaserDisable(((FldPartySlot *)entry)[1].chaser);
                    }
                }
                fieldState = MT_Scene_GetFrameState();
                if (((FldSceneTasks *)fieldState)->camera != 0) {
                    FldCameraUpdateOrbit(((FldSceneTasks *)MT_Scene_GetFrameState())->camera);
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
                *(Vec3f *)translation = ((struct RwMatrixTag *)(matrix))->pos;
                negativeTranslation[0] = -1.0f * translation[0];
                negativeTranslation[1] = -1.0f * translation[1];
                negativeTranslation[2] = -1.0f * translation[2];
                mdlTranslateMatrix(*(s32 *)(resource + 0x164), negativeTranslation, 2);
                mdlRotateMatrix((void *)(u32)*(s32 *)(resource + 0x164), &rotationAxis, *(f32 *)(placement + 0x14C), 2);
                mdlTranslateMatrix(*(s32 *)(resource + 0x164), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x164));
                ((struct RwMatrixTag *)(matrix))->pos = *(Vec3f *)((ResrcRecord *)placement)->placement;
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x164)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix((s32)((ResrcRecord *)resource)->modelHandle164));
                if (*(s32 *)(resource + 0x22C) != 0) {
                    uniformScale = FldFrameTask_GetHeight((s32)((ResrcRecord *)resource)->handle228);
                    scale[2] = uniformScale;
                    scale[1] = uniformScale;
                    scale[0] = uniformScale;
                    mdlRotateMatrix((void *)(u32)*(s32 *)(resource + 0x22C), &rotationAxis, *(f32 *)(placement + 0x14C), 2);
                    mdlScale(*(s32 *)(resource + 0x22C), scale, 2);
                    mdlTranslateMatrix(*(s32 *)(resource + 0x22C), placement + 0x140, 2);
                    mdlAdvanceModelFromFlags((s32)((ResrcRecord *)resource)->handle22C);
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
                *(Vec3f *)translation = ((struct RwMatrixTag *)(matrix))->pos;
                negativeTranslation[0] = -1.0f * translation[0];
                negativeTranslation[1] = -1.0f * translation[1];
                negativeTranslation[2] = -1.0f * translation[2];
                mdlTranslateMatrix(*(s32 *)(resource + 0x144), negativeTranslation, 2);
                mdlRotateMatrix((void *)(u32)*(s32 *)(resource + 0x144), &rotationAxis, *(f32 *)(placement + 0x14C), 0);
                mdlTranslateMatrix(*(s32 *)(resource + 0x144), translation, 2);
                matrix = mdlGetMatrix(*(s32 *)(resource + 0x144));
                ((struct RwMatrixTag *)(matrix))->pos = *(Vec3f *)((ResrcRecord *)placement)->placement;
                RwEngineGetMatrixTolerances(&tolerance);
                RwMatrixOptimize(mdlGetMatrix(*(s32 *)(resource + 0x144)), &tolerance);
                RwMatrixUpdate(mdlGetMatrix((s32)((ResrcRecord *)resource)->slotHandle[1]));
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





/* The frame-list words at +24/+28 lie beyond the published SceneContext prefix; no constructor/allocation
 * extent proving that tail was found, so do not invent a larger context. */
// FUN_00177B30
s32 Cmd_CreateFieldModel(void)
{
    s32 model = scrGetParamInt(0);
    s32 resourceIndex = scrGetParamInt(1);
    s32 resourceId = 0;
    s32 created = 0;
    u8* placementFrame = 0;
    s32 frameFlag;
    if (mdlPrepareModel((void*)model) == 1)
    {
        u8* existingResource = MT_Scene_GetRes((resourceIndex & 0x3FF) | 0x2800);
        if (existingResource != 0)
        {
            mdlDestroyModelObject(model);
            scrSetReturnInt(0);
            return 1;
        }
        resourceId = MT_Scene_CreateModelFldRes(resourceIndex & 0xFFFF, model) & 0xFFFF;
        while (*(s32*)(D_00762EA0 + 0x24) > 0)
        {
            placementFrame = (u8*)FldResource_FindFrameForId(*(s32*)(D_00762EA0 + 0x28), resourceIndex, &frameFlag);
            break;
        }
        if (placementFrame != 0)
        {
            f32 rotation[3];
            placementFrame = (u8*)func_003e9700((s32)placementFrame);
            rotation[0] = KDraw_MatrixPitchDeg(placementFrame);
            rotation[1] = KDraw_MatrixYawDeg(placementFrame);
            rotation[2] = KDraw_MatrixRollDeg(placementFrame);
            MT_Scene_SetResPlacement(resourceId & 0xFFFF, (u8*)(placementFrame + 0x30), (u8 *)&rotation);
            mdlApplyModelMatrix(model, placementFrame, 0);
            mdlDispatchAnimIfPresent((u8*)model, 0, 0, 8, 1);
        }
        if (frameFlag == 1)
        {
            u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
            ((ResrcRecord *)resource)->value150 = 1;
        }
        created = 1;
    }
    scrSetReturnInt(resourceId);
    return created;
}

/* Prepare a model and assign a free field-model resource identifier; return whether creation succeeded. */
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





/* Store the script value in the resource-specific word at +150 when the resource exists. */
// FUN_00177DB0
s32 Cmd_SetResourceWord150(void)
{
    s32 resourceId = scrGetParamInt(0);
    s32 value = scrGetParamInt(1);
    u8* resource = MT_Scene_GetRes(resourceId);
    if (resource != 0)
    {
        ((ResrcRecord *)resource)->value150 = value;
    }
    return 1;
}

/* Find or create a model by its halfword type and identifier, then return the handle to the script. */
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





/* Prepare a model as an NPC resource and attach a clone of the shared shadow model. */
// FUN_00177E80
s32 Cmd_CreateSceneResource(void)
{
    s32 model = scrGetParamInt(0);
    s32 npcId = scrGetParamInt(1);
    s32 resourceId = 0;
    s32 created = 0;
    if (mdlPrepareModel((void*)model) == 1)
    {
        u8* resource;
        resourceId = (u16)MT_Scene_CreateModelNpcShadowRes(MT_Scene_FindFreeResId(3), (u16)npcId, model);
        resource = MT_Scene_GetRes(resourceId);
        ((ResrcRecord *)resource)->handle22C = (void *)mdlCloneModelObject(D_00764364);
        created = 1;
    }
    scrSetReturnInt(resourceId);
    return created;
}



/* Set resource height and rescale an attached NPC shadow when present. */
/* measured: typing the remaining shadow-handle guard and scale operand individually loses MATCH; the height
 * calls and final model update stay typed. */
// FUN_00177F50
s32 Cmd_SetFieldFloat(void)
{
    s32 resourceId = scrGetParamInt(0);
    f32 height = scrGetParamFloat(1);
    s32 resourceType = (resourceId & 0xFFC00) >> 10;
    switch (resourceType)
    {
    case 1:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            FldFrameTask_SetHeight(((ResrcRecord *)resource)->handle220, height);
        }
        break;
    }
    case 3:
    {
        u8* resource = MT_Scene_GetRes(resourceId & 0xFFFF);
        if (resource != 0)
        {
            FldFrameTask_SetHeight((s32)((ResrcRecord *)resource)->handle228, height);
            if (*(s32*)(resource + 0x22C) != 0)
            {
                f32 scale[3];
                scale[2] = height;
                scale[1] = height;
                scale[0] = height;
                mdlScale(*(s32*)(resource + 0x22C), scale, 2);
                mdlAdvanceModelFromFlags((s32)((ResrcRecord *)resource)->handle22C);
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
    s32 angle = scrGetParamInt(0);
    s32 frames = scrGetParamInt(1);
    FldFrame_RotateTaskCreate(0, frames, angle);
    return 1;
}



/* P4 flowscript library (build/p4flow/Field.json, index 0x1018): FLD_CAMERA_ROTATE_BEHIND(degrees, speed).
 * FldFrameRotateTaskCreate takes an absolute target yaw (wrapped to 360) where FldFrame_RotateTaskCreate adds
 * degrees to the player's yaw. The library name is kept. */
// FUN_001780D0
s32 K_Cmd_FLD_CAMERA_ROTATE_BEHIND(void)
{
    s32 angle = scrGetParamInt(0);
    s32 frames = scrGetParamInt(1);
    FldFrameRotateTaskCreate(0, frames, angle);
    return 1;
}



/* Choose a cardinal heading facing the player from the nearest entry forward axis and start a camera turn. */
/* measured: typing the remaining resource model-handle loads individually loses MATCH; the matrix axes,
 * position, and camera parent are typed. */
// FUN_00178130
s32 Cmd_FaceNearestAxis(void)
{
    s32 frames = scrGetParamInt(0);
    u8* entry = FldEvent_GetNearestEntry();
    Vec3f diff;
    Vec3f forward;
    f32 coordinate;
    f32 angle;
    f32 dot;
    if (entry != 0)
    {
        forward = ((struct RwMatrixTag *)((u8*)mdlGetMatrix(*(s32*)(entry + 0x144))))->at;
        coordinate = ((RwMatrixTag *)mdlGetMatrix(*(s32*)(entry + 0x144)))->pos.x;
        diff.x = coordinate - ((RwMatrixTag *)mdlGetMatrix(D_007EFA00[0]))->pos.x;
        coordinate = ((RwMatrixTag *)mdlGetMatrix(*(s32*)(entry + 0x144)))->pos.y;
        diff.y = coordinate - ((RwMatrixTag *)mdlGetMatrix(D_007EFA00[0]))->pos.y;
        coordinate = ((RwMatrixTag *)mdlGetMatrix((s32)((ResrcRecord *)entry)->slotHandle[1]))->pos.z;
        diff.z = coordinate - ((RwMatrixTag *)mdlGetMatrix(D_007EFA00[0]))->pos.z;
        RwV3dNormalize(&diff.x, &diff.x);
        RwV3dNormalize(&forward.x, &forward.x);
        KDraw_MatrixYawDeg((u8*)func_003e9700((s32)((RwCamera *)kwlnGetCamera())->object.object.parent));
        dot = diff.x * forward.x + diff.y * forward.y + diff.z * forward.z;
        if (dot < 0.0f)
        {
            forward.x = -forward.x;
            forward.y = -forward.y;
            forward.z = -forward.z;
        }
        if (forward.x > 0.5f)
        {
            angle = 90.0f;
        }
        else if (forward.x < -0.5f)
        {
            angle = 270.0f;
        }
        else if (forward.z > 0.5f)
        {
            angle = 0.0f;
        }
        else if (forward.z < -0.5f)
        {
            angle = 180.0f;
        }
        FldFrameRotateTaskCreate(0, frames, (s32)angle);
    }
    return 1;
}



/* Store three script operands and reset the shared work-state word. */
// FUN_00178360
s32 Cmd_SetWorkValues(void)
{
    D_00724B3C = scrGetParamInt(0);
    D_00724B40 = scrGetParamInt(1);
    D_00724B44 = scrGetParamInt(2);
    D_00724B48 = 0;
    return 1;
}

/* Set the scene RGB channels from byte-truncated script operands with alpha zero. */
// FUN_001783B0
s32 Cmd_SetSceneMode(void)
{
    u8 red;
    u8 green;

    red = scrGetParamInt(0) & 0xFF;
    green = scrGetParamInt(1) & 0xFF;
    kwlnSetColorRgba(red, green, scrGetParamInt(2) & 0xFF, 0);
    return 1;
}





/* Update the active camera fog plane; retain the second camera lookup performed by retail. */
// FUN_00178420
s32 Cmd_SetCameraFloat(void)
{
    f32 value = scrGetParamFloat(0);
    ((RwCamera *)kwlnGetCamera())->fogPlane = value;
    kwlnGetCamera();
    return 1;
}

/* Store the real script operand in shared state; its wider gameplay role is not established. */
// FUN_00178470
s32 Cmd_SetFloatGlobal(void)
{
    D_00764B5C = scrGetParamFloat(0);
    return 1;
}





/* Return the nearest entry identifier; assert when no entry is available. */
// FUN_001784A0
s32 Cmd_LoadFieldWord(void)
{
    u16* entry = FldEvent_GetNearestEntry();
    if (entry != 0)
    {
        scrSetReturnInt(*entry);
    }
    else
    {
        kAssertFail(D_005F1858, 0x462);
    }
    return 1;
}



/* Return the trigger entry identifier; assert when no entry is available. */
// FUN_00178500
s32 Cmd_LoadFieldWordAlt(void)
{
    u16* entry = FldEvent_GetTriggerEntry();
    if (entry != 0)
    {
        scrSetReturnInt(*entry);
    }
    else
    {
        kAssertFail(D_005F1858, 0x474);
    }
    return 1;
}

/* Return whether the requested resource/value pair is absent from the field-sequence records. */
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


/* Form a character-resource identifier from the low ten operand bits and spawn its byte-sized icon. */
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


/* Return the item count using a signed-halfword item identifier and byte-sized result. */
// FUN_0025D100
u32 Cmd_LoadTableWord()
{
    scrSetReturnInt((u8)datItemCount((s16)scrGetParamInt(0)));

    return true;
}

u32 datCalcGetHpById(s16 unitId);
u16 datCalcMaxHpById(s16 unitId);
u32 datCalcGetSpById(s16 unitId);
extern void datSetUnitHp(s16 unitId, s16 hp);
extern s64 scrGetParamIntS64(s32);
extern s32 cmmCommunityGetCurrentSecondary(void);
extern u16 datCalcMaxSpById(s16 unitId);
extern void datSetUnitSp(s16 unitId, s16 sp);
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
    s64 unitId;
    s64 hitPoints;

    unitId = scrGetParamIntS64(0);
    hitPoints = scrGetParamIntS64(1);
    datSetUnitHp((s16)unitId, (s16)hitPoints);
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
    s64 unitId;
    s64 skillPoints;

    unitId = scrGetParamIntS64(0);
    skillPoints = scrGetParamIntS64(1);
    datSetUnitSp((s16)unitId, (s16)skillPoints);
    return 1;
}


/* Return the character level using a signed-halfword identifier and byte-sized result. */
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


