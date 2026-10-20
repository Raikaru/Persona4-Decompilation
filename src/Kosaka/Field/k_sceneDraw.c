/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "sdk_lbox_internal.h"
#include "include_asm.h"
#include "type.h"
#include "Kosaka/k_sceneDraw_lighting.h"

// 256 bytes. Base struct for every type of resource
typedef struct Resrc
{
    u8 unkData[0x28];
    u32 flags; // 0x28
} Resrc;

#define SCENEDRAW_RESRC_FLAG_VISIBLE 0x00000002

extern Resrc* MT_Scene_GetRes(u16 resTypeId);
extern u8* MT_Scene_GetResListHead(s32 resourceType);
extern void RwMatrixRotate(void *, void *, s32, f32);
extern f32 fGpffff809c;
extern f32 fGpffff838c;

typedef struct ResrcManager ResrcManager;

// 40 bytes
typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

#define RESRC_TYPE_MASK 0xffc00
#define RESRC_GET_TYPE(resTypeId) (((resTypeId) & RESRC_TYPE_MASK) >> 10)

#define SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT 0x80000000

#define RESRC_TYPE_MODELCHAR 1
#define RESRC_TYPE_MODELUNK  2
#define RESRC_TYPE_MODELNPC  3

extern u32 PTR_DAT_00762ea0;
#define gMtScene ((MtScene*)PTR_DAT_00762ea0)
extern Resrc* resrcMngFindResById(ResrcManager* resManager, u16 resTypeId);

#define SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY 0x40000000

#define SCENEDRAW_RESRC_FLAG_PERSONA 0x00010000



extern u32 sdkLboxAddEntry(KwlnTask* task, const char* name);
extern void sdkLboxSetText(KwlnTask* task, u32 id, const char* text);
extern void sdkLboxSetRefValue(KwlnTask* task, u32 id, s32 value);
extern void sdkLboxSetIntRange(KwlnTask* task, u32 id, s32 value, s32 minValue,
                          s32 maxValue, s32 flags);
extern void sdkLboxSetFloatRange(KwlnTask* task, u32 id, s32 value, s32 minValue,
                          s32 maxValue);
extern void sdkLboxSetCallback(KwlnTask* task, u32 id, KWindowEntryCallback callback);



/* Update visibility only when the requested scene resource exists. */
// FUN_0014A0F0
void SceneDraw_SetResVisible(u16 resTypeId, u32 visible)
{
    Resrc* res;

    res = MT_Scene_GetRes(resTypeId);
    if (res != NULL)
    {
        if (visible == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_VISIBLE;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_VISIBLE;
        }
    }
}



/* Toggle custom lighting for character, NPC and alternate-model resources. */
// FUN_0014A300
void SceneDraw_SetCustomLight(u16 resTypeId, u32 customLight)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (customLight == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
            return;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
            return;
        }
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (customLight == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
            return;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
            return;
        }
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (customLight == 1) res->flags |= SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
        else res->flags &= ~SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
    }
}



/* Toggle directional-only lighting for the three supported model resource kinds. */
// FUN_0014A460
void SceneDraw_SetDirectionalOnly(u16 resTypeId, u32 directionalOnly)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (directionalOnly == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
            return;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
            return;
        }
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (directionalOnly == 1)
        {
            res->flags |= SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
            return;
        }
        else
        {
            res->flags &= ~SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
            return;
        }
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (directionalOnly == 1) res->flags |= SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
        else res->flags &= ~SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
    }
}



/* Return the first light color for a supported model resource, or NULL. */
// FUN_0014A5D0
void* SceneDraw_GetLightColorA(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->light.firstColor;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->light.firstColor;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldAlternateModelLighting *)res)->firstColor;
    }
    return NULL;
}
/* Return the second light color for a supported model resource, or NULL. */
// FUN_0014A6C0
void* SceneDraw_GetLightColorB(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->light.secondColor;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->light.secondColor;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldAlternateModelLighting *)res)->secondColor;
    }
    return NULL;
}
/* Return the first light direction matrix for a supported model resource, or NULL. */
// FUN_0014A7B0
void* SceneDraw_GetLightMatrixA(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->light.matrix;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->light.matrix;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldAlternateModelLighting *)res)->firstMatrix;
    }
    return NULL;
}



/* Return the light tint for a supported model resource, or NULL. */
// FUN_0014A8A0
void* SceneDraw_GetLightTint(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->tint;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->tint;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldAlternateModelLighting *)res)->tint;
    }
    return NULL;
}
/* Return the second light direction matrix for a supported model resource, or NULL. */
// FUN_0014A990
void* SceneDraw_GetLightMatrixB(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->secondMatrix;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldModelLighting *)res)->secondMatrix;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : &((FldAlternateModelLighting *)res)->secondMatrix;
    }
    return NULL;
}
/* Integer accesses to float members below preserve the original IEEE-754 word stores. */
/* Restore half-intensity light colors, clear tint, and orient both light matrices to the defaults. */
// FUN_0014AA80
void SceneDraw_ResetResource(u16 resTypeId)
{
    s32 rotationAxisBits[3];
    s32 one;
    u8 *tint;
    u8 *firstMatrix;
    u8 *secondMatrix;
    u8 *firstColor;
    u8 *secondColor;
    u32 type;

    firstColor = SceneDraw_GetLightColorA(resTypeId);
    secondColor = SceneDraw_GetLightColorB(resTypeId);
    firstMatrix = SceneDraw_GetLightMatrixA(resTypeId);
    tint = SceneDraw_GetLightTint(resTypeId);
    secondMatrix = SceneDraw_GetLightMatrixB(resTypeId);
    *(s32 *)&((SceneLightVector *)firstColor)->x = 0x3f000000;
    *(s32 *)&((SceneLightVector *)firstColor)->y = 0x3f000000;
    *(s32 *)&((SceneLightVector *)firstColor)->z = 0x3f000000;
    *(s32 *)&((SceneLightVector *)firstColor)->w = 0;
    *(s32 *)&((SceneLightVector *)secondColor)->x = 0x3f000000;
    *(s32 *)&((SceneLightVector *)secondColor)->y = 0x3f000000;
    *(s32 *)&((SceneLightVector *)secondColor)->z = 0x3f000000;
    *(s32 *)&((SceneLightVector *)secondColor)->w = 0;
    *(s32 *)&((SceneLightVector *)tint)->x = 0;
    *(s32 *)&((SceneLightVector *)tint)->y = 0;
    *(s32 *)&((SceneLightVector *)tint)->z = 0;
    *(s32 *)&((SceneLightVector *)tint)->w = 0;
    one = 0x3f800000;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.z = one;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.y = one;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.x = one;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->flags = *(s32 *)&((SceneLightMatrix *)firstMatrix)->flags | 0x20003;
    rotationAxisBits[0] = 0;
    rotationAxisBits[1] = one;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(firstMatrix, &rotationAxisBits[0], 2, -180.0f);
    rotationAxisBits[0] = one;
    rotationAxisBits[1] = 0;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(firstMatrix, &rotationAxisBits[0], 2, -45.0f);
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.z = one;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.y = one;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.x = one;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->flags = *(s32 *)&((SceneLightMatrix *)secondMatrix)->flags | 0x20003;
    rotationAxisBits[0] = 0;
    rotationAxisBits[1] = one;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(secondMatrix, &rotationAxisBits[0], 2, -180.0f);
    rotationAxisBits[0] = one;
    rotationAxisBits[1] = 0;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(secondMatrix, &rotationAxisBits[0], 2, -45.0f);
    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR || type == RESRC_TYPE_MODELNPC)
    {
        resrcMngFindResById(gMtScene->resManager, resTypeId);
    }
}
/* Return the first color of the character-light resource, when present. */
// FUN_0014ACD0
void* SceneDraw_GetList4FirstColor(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(4);
    if (res != NULL)
    {
        return (u8 *)&((FldSceneLighting *)res)->light.firstColor;
    }
    return NULL;
}
/* Return the second color of the character-light resource, when present. */
// FUN_0014AD10
void* SceneDraw_GetList4SecondColor(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(4);
    if (res != NULL)
    {
        return (u8 *)&((FldSceneLighting *)res)->light.secondColor;
    }
    return NULL;
}
/* Return the first direction matrix of the character-light resource, when present. */
// FUN_0014AD50
void* SceneDraw_GetList4Matrix(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(4);
    if (res != NULL)
    {
        return (u8 *)&((FldSceneLighting *)res)->light.matrix;
    }
    return NULL;
}
/* Integer accesses to float members below preserve the original IEEE-754 word stores. */
/* Initialize the character-light resource colors, tint and pair of rotated direction matrices. */
// FUN_0014AD90
void SceneDraw_InitResList4(void)
{
    s32 rotationAxisBits[3];
    s32 one;
    f32 firstIntensity;
    f32 secondIntensity;
    u8 *firstColorResource;
    u8 *secondColorResource;
    u8 *firstMatrixResource;
    u8 *tintResource;
    u8 *secondMatrixResource;
    u8 *secondMatrix;
    u8 *firstMatrix;
    u8 *tint;
    u8 *secondColor;
    u8 *firstColor;

    firstColorResource = MT_Scene_GetResListHead(4);
    if (firstColorResource != NULL)
    {
        firstColor = (u8 *)&((FldSceneLighting *)firstColorResource)->light.firstColor;
    }
    else
    {
        firstColor = NULL;
    }
    secondColorResource = MT_Scene_GetResListHead(4);
    if (secondColorResource != NULL)
    {
        secondColor = (u8 *)&((FldSceneLighting *)secondColorResource)->light.secondColor;
    }
    else
    {
        secondColor = NULL;
    }
    firstMatrixResource = MT_Scene_GetResListHead(4);
    if (firstMatrixResource != NULL)
    {
        firstMatrix = (u8 *)&((FldSceneLighting *)firstMatrixResource)->light.matrix;
    }
    else
    {
        firstMatrix = NULL;
    }
    tintResource = MT_Scene_GetResListHead(4);
    if (tintResource != NULL)
    {
        tint = (u8 *)&((FldSceneLighting *)tintResource)->tint;
    }
    else
    {
        tint = NULL;
    }
    secondMatrixResource = MT_Scene_GetResListHead(4);
    if (secondMatrixResource != NULL)
    {
        secondMatrix = (u8 *)&((FldSceneLighting *)secondMatrixResource)->secondMatrix;
    }
    else
    {
        secondMatrix = NULL;
    }
    firstIntensity = fGpffff809c;
    ((SceneLightVector *)firstColor)->x = firstIntensity;
    ((SceneLightVector *)firstColor)->y = firstIntensity;
    ((SceneLightVector *)firstColor)->z = firstIntensity;
    *(s32 *)&((SceneLightVector *)firstColor)->w = 0;
    secondIntensity = fGpffff838c;
    ((SceneLightVector *)secondColor)->x = secondIntensity;
    ((SceneLightVector *)secondColor)->y = secondIntensity;
    ((SceneLightVector *)secondColor)->z = secondIntensity;
    *(s32 *)&((SceneLightVector *)secondColor)->w = 0;
    *(s32 *)&((SceneLightVector *)tint)->x = 0;
    *(s32 *)&((SceneLightVector *)tint)->y = 0;
    *(s32 *)&((SceneLightVector *)tint)->z = 0;
    *(s32 *)&((SceneLightVector *)tint)->w = 0;
    one = 0x3f800000;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.z = one;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.y = one;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.x = one;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->right.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->at.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->up.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.z = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.y = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->pos.x = 0;
    *(s32 *)&((SceneLightMatrix *)firstMatrix)->flags = *(s32 *)&((SceneLightMatrix *)firstMatrix)->flags | 0x20003;
    rotationAxisBits[0] = 0;
    rotationAxisBits[1] = one;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(firstMatrix, &rotationAxisBits[0], 2, -180.0f);
    rotationAxisBits[0] = one;
    rotationAxisBits[1] = 0;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(firstMatrix, &rotationAxisBits[0], 2, -45.0f);
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.z = one;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.y = one;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.x = one;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->right.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->at.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->up.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.z = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.y = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->pos.x = 0;
    *(s32 *)&((SceneLightMatrix *)secondMatrix)->flags = *(s32 *)&((SceneLightMatrix *)secondMatrix)->flags | 0x20003;
    rotationAxisBits[0] = 0;
    rotationAxisBits[1] = one;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(secondMatrix, &rotationAxisBits[0], 2, -180.0f);
    rotationAxisBits[0] = one;
    rotationAxisBits[1] = 0;
    rotationAxisBits[2] = 0;
    RwMatrixRotate(secondMatrix, &rotationAxisBits[0], 2, -45.0f);
}
/* Return the first color of the NPC-light resource, when present. */
// FUN_0014B000
void* SceneDraw_GetList5FirstColor(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(5);
    if (res != NULL)
    {
        return (u8 *)&((FldSceneLighting *)res)->light.firstColor;
    }
    return NULL;
}
/* Return the second color of the NPC-light resource, when present. */
// FUN_0014B040
void* SceneDraw_GetList5SecondColor(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(5);
    if (res != NULL)
    {
        return (u8 *)&((FldSceneLighting *)res)->light.secondColor;
    }
    return NULL;
}
/* Return the first direction matrix of the NPC-light resource, when present. */
// FUN_0014B080
void* SceneDraw_GetList5Matrix(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(5);
    if (res != NULL)
    {
        return (u8 *)&((FldSceneLighting *)res)->light.matrix;
    }
    return NULL;
}
/* Set visibility when a scene manager exists; the resource lookup is assumed valid. */
// FUN_0014B0C0
void SceneDraw_SetResVisibleChecked(u16 resTypeId, u32 visible)
{
    Resrc* res;

    if (gMtScene->resManager == NULL)
    {
        goto done;
    }
    res = resrcMngFindResById(gMtScene->resManager, resTypeId);
    goto setFlags;

done:
    return;

setFlags:
    if (visible == 1)
    {
        res->flags |= SCENEDRAW_RESRC_FLAG_VISIBLE;
    }
    else
    {
        res->flags &= ~SCENEDRAW_RESRC_FLAG_VISIBLE;
    }
}



/* Toggle the persona draw flag when a scene manager exists; lookup is assumed valid. */
// FUN_0014B150
void SceneDraw_SetResPersona(u16 resTypeId, u32 persona)
{
    Resrc* res;

    if (gMtScene->resManager == NULL)
    {
        goto done;
    }
    res = resrcMngFindResById(gMtScene->resManager, resTypeId);
    goto setFlags;

done:
    return;

setFlags:
    if (persona == 1)
    {
        res->flags |= SCENEDRAW_RESRC_FLAG_PERSONA;
    }
    else
    {
        res->flags &= ~SCENEDRAW_RESRC_FLAG_PERSONA;
    }
}



// FUN_00470250
KwlnTask* sdkLboxCreate(KwlnTask* parent, u32 width, u32 height)
{
    return (KwlnTask*)sdkLboxCreateEx((u8*)parent, width, height, 0);
}



/* Populate listbox entries from typed descriptors and register optional entry callbacks. */
// FUN_00470810
void sdkLboxAddDescriptors(KwlnTask* task, const KWindowEntryDescriptor* descriptors,
                   u32 count)
{
    u32 i;
    u32 id;

    i = 0;
    while (i < count)
    {
        id = sdkLboxAddEntry(task, descriptors->name);
        switch (descriptors->type)
        {
            case 0:
                break;
            case 1:
                sdkLboxSetText(task, id, descriptors->text);
                break;
            case 2:
                sdkLboxSetRefValue(task, id, descriptors->value0);
                break;
            case 3:
                sdkLboxSetIntRange(task, id, descriptors->value0,
                              descriptors->value1, descriptors->value2,
                              descriptors->value3);
                break;
            case 4:
                sdkLboxSetFloatRange(task, id, descriptors->value0,
                              descriptors->value1, descriptors->value2);
                break;
        }
        if (descriptors->callback != NULL)
        {
            sdkLboxSetCallback(task, id, descriptors->callback);
        }
        i++;
        descriptors++;
    }
}
