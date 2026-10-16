/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "sdk_lbox_internal.h"
#include "include_asm.h"
#include "type.h"

// 256 bytes. Base struct for every type of resource
typedef struct Resrc
{
    u8 unkData[0x28];
    u32 flags; // 0x28
} Resrc;

#define SCENEDRAW_RESRC_FLAG_VISIBLE 0x00000002

extern Resrc* MT_Scene_GetRes(u16 resTypeId);
extern u8* MT_Scene_GetResListHead(s32 arg0);
extern void RwMatrixRotate(void *arg0, void *arg1, s32 arg2, f32 arg3);
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



// FUN_0014A5D0
void* SceneDraw_GetLightColorA(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x168;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x168;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x15c;
    }
    return NULL;
}
// FUN_0014A6C0
void* SceneDraw_GetLightColorB(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x178;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x178;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x16c;
    }
    return NULL;
}
// FUN_0014A7B0
void* SceneDraw_GetLightMatrixA(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x190;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x190;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x180;
    }
    return NULL;
}



// FUN_0014A8A0
void* SceneDraw_GetLightTint(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1d0;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1d0;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1c0;
    }
    return NULL;
}
// FUN_0014A990
void* SceneDraw_GetLightMatrixB(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1e0;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1e0;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = resrcMngFindResById(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1d0;
    }
    return NULL;
}
// FUN_0014AA80
void SceneDraw_ResetResource(u16 resTypeId)
{
    s32 sp[3];
    s32 one;
    u8 *temp_21;
    u8 *temp_19;
    u8 *temp_18;
    u8 *temp_17;
    u8 *temp_16;
    u32 type;

    temp_17 = SceneDraw_GetLightColorA(resTypeId);
    temp_16 = SceneDraw_GetLightColorB(resTypeId);
    temp_19 = SceneDraw_GetLightMatrixA(resTypeId);
    temp_21 = SceneDraw_GetLightTint(resTypeId);
    temp_18 = SceneDraw_GetLightMatrixB(resTypeId);
    *(s32 *)(temp_17 + 0x0) = 0x3f000000;
    *(s32 *)(temp_17 + 0x4) = 0x3f000000;
    *(s32 *)(temp_17 + 0x8) = 0x3f000000;
    *(s32 *)(temp_17 + 0xc) = 0;
    *(s32 *)(temp_16 + 0x0) = 0x3f000000;
    *(s32 *)(temp_16 + 0x4) = 0x3f000000;
    *(s32 *)(temp_16 + 0x8) = 0x3f000000;
    *(s32 *)(temp_16 + 0xc) = 0;
    *(s32 *)(temp_21 + 0x0) = 0;
    *(s32 *)(temp_21 + 0x4) = 0;
    *(s32 *)(temp_21 + 0x8) = 0;
    *(s32 *)(temp_21 + 0xc) = 0;
    one = 0x3f800000;
    *(s32 *)(temp_19 + 0x28) = one;
    *(s32 *)(temp_19 + 0x14) = one;
    *(s32 *)(temp_19 + 0x0) = one;
    *(s32 *)(temp_19 + 0x10) = 0;
    *(s32 *)(temp_19 + 0x8) = 0;
    *(s32 *)(temp_19 + 0x4) = 0;
    *(s32 *)(temp_19 + 0x24) = 0;
    *(s32 *)(temp_19 + 0x20) = 0;
    *(s32 *)(temp_19 + 0x18) = 0;
    *(s32 *)(temp_19 + 0x38) = 0;
    *(s32 *)(temp_19 + 0x34) = 0;
    *(s32 *)(temp_19 + 0x30) = 0;
    *(s32 *)(temp_19 + 0xc) = *(s32 *)(temp_19 + 0xc) | 0x20003;
    sp[0] = 0;
    sp[1] = one;
    sp[2] = 0;
    RwMatrixRotate(temp_19, &sp[0], 2, -180.0f);
    sp[0] = one;
    sp[1] = 0;
    sp[2] = 0;
    RwMatrixRotate(temp_19, &sp[0], 2, -45.0f);
    *(s32 *)(temp_18 + 0x28) = one;
    *(s32 *)(temp_18 + 0x14) = one;
    *(s32 *)(temp_18 + 0x0) = one;
    *(s32 *)(temp_18 + 0x10) = 0;
    *(s32 *)(temp_18 + 0x8) = 0;
    *(s32 *)(temp_18 + 0x4) = 0;
    *(s32 *)(temp_18 + 0x24) = 0;
    *(s32 *)(temp_18 + 0x20) = 0;
    *(s32 *)(temp_18 + 0x18) = 0;
    *(s32 *)(temp_18 + 0x38) = 0;
    *(s32 *)(temp_18 + 0x34) = 0;
    *(s32 *)(temp_18 + 0x30) = 0;
    *(s32 *)(temp_18 + 0xc) = *(s32 *)(temp_18 + 0xc) | 0x20003;
    sp[0] = 0;
    sp[1] = one;
    sp[2] = 0;
    RwMatrixRotate(temp_18, &sp[0], 2, -180.0f);
    sp[0] = one;
    sp[1] = 0;
    sp[2] = 0;
    RwMatrixRotate(temp_18, &sp[0], 2, -45.0f);
    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR || type == RESRC_TYPE_MODELNPC)
    {
        resrcMngFindResById(gMtScene->resManager, resTypeId);
    }
}
// FUN_0014ACD0
void* SceneDraw_GetList4FirstColor(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(4);
    if (res != NULL)
    {
        return res + 0x140;
    }
    return NULL;
}
// FUN_0014AD10
void* SceneDraw_GetList4SecondColor(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(4);
    if (res != NULL)
    {
        return res + 0x150;
    }
    return NULL;
}
// FUN_0014AD50
void* SceneDraw_GetList4Matrix(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(4);
    if (res != NULL)
    {
        return res + 0x160;
    }
    return NULL;
}
// FUN_0014AD90
void SceneDraw_InitResList4(void)
{
    s32 sp[3];
    s32 one;
    f32 temp_f0;
    f32 temp_f0_2;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_2_4;
    u8 *temp_2_5;
    u8 *var_16;
    u8 *var_17;
    u8 *var_18;
    u8 *var_19;
    u8 *var_20;

    temp_2 = MT_Scene_GetResListHead(4);
    if (temp_2 != NULL)
    {
        var_20 = temp_2 + 0x140;
    }
    else
    {
        var_20 = NULL;
    }
    temp_2_2 = MT_Scene_GetResListHead(4);
    if (temp_2_2 != NULL)
    {
        var_19 = temp_2_2 + 0x150;
    }
    else
    {
        var_19 = NULL;
    }
    temp_2_3 = MT_Scene_GetResListHead(4);
    if (temp_2_3 != NULL)
    {
        var_17 = temp_2_3 + 0x160;
    }
    else
    {
        var_17 = NULL;
    }
    temp_2_4 = MT_Scene_GetResListHead(4);
    if (temp_2_4 != NULL)
    {
        var_18 = temp_2_4 + 0x1a0;
    }
    else
    {
        var_18 = NULL;
    }
    temp_2_5 = MT_Scene_GetResListHead(4);
    if (temp_2_5 != NULL)
    {
        var_16 = temp_2_5 + 0x1b0;
    }
    else
    {
        var_16 = NULL;
    }
    temp_f0 = fGpffff809c;
    *(f32 *)(var_20 + 0x0) = temp_f0;
    *(f32 *)(var_20 + 0x4) = temp_f0;
    *(f32 *)(var_20 + 0x8) = temp_f0;
    *(s32 *)(var_20 + 0xc) = 0;
    temp_f0_2 = fGpffff838c;
    *(f32 *)(var_19 + 0x0) = temp_f0_2;
    *(f32 *)(var_19 + 0x4) = temp_f0_2;
    *(f32 *)(var_19 + 0x8) = temp_f0_2;
    *(s32 *)(var_19 + 0xc) = 0;
    *(s32 *)(var_18 + 0x0) = 0;
    *(s32 *)(var_18 + 0x4) = 0;
    *(s32 *)(var_18 + 0x8) = 0;
    *(s32 *)(var_18 + 0xc) = 0;
    one = 0x3f800000;
    *(s32 *)(var_17 + 0x28) = one;
    *(s32 *)(var_17 + 0x14) = one;
    *(s32 *)(var_17 + 0x0) = one;
    *(s32 *)(var_17 + 0x10) = 0;
    *(s32 *)(var_17 + 0x8) = 0;
    *(s32 *)(var_17 + 0x4) = 0;
    *(s32 *)(var_17 + 0x24) = 0;
    *(s32 *)(var_17 + 0x20) = 0;
    *(s32 *)(var_17 + 0x18) = 0;
    *(s32 *)(var_17 + 0x38) = 0;
    *(s32 *)(var_17 + 0x34) = 0;
    *(s32 *)(var_17 + 0x30) = 0;
    *(s32 *)(var_17 + 0xc) = *(s32 *)(var_17 + 0xc) | 0x20003;
    sp[0] = 0;
    sp[1] = one;
    sp[2] = 0;
    RwMatrixRotate(var_17, &sp[0], 2, -180.0f);
    sp[0] = one;
    sp[1] = 0;
    sp[2] = 0;
    RwMatrixRotate(var_17, &sp[0], 2, -45.0f);
    *(s32 *)(var_16 + 0x28) = one;
    *(s32 *)(var_16 + 0x14) = one;
    *(s32 *)(var_16 + 0x0) = one;
    *(s32 *)(var_16 + 0x10) = 0;
    *(s32 *)(var_16 + 0x8) = 0;
    *(s32 *)(var_16 + 0x4) = 0;
    *(s32 *)(var_16 + 0x24) = 0;
    *(s32 *)(var_16 + 0x20) = 0;
    *(s32 *)(var_16 + 0x18) = 0;
    *(s32 *)(var_16 + 0x38) = 0;
    *(s32 *)(var_16 + 0x34) = 0;
    *(s32 *)(var_16 + 0x30) = 0;
    *(s32 *)(var_16 + 0xc) = *(s32 *)(var_16 + 0xc) | 0x20003;
    sp[0] = 0;
    sp[1] = one;
    sp[2] = 0;
    RwMatrixRotate(var_16, &sp[0], 2, -180.0f);
    sp[0] = one;
    sp[1] = 0;
    sp[2] = 0;
    RwMatrixRotate(var_16, &sp[0], 2, -45.0f);
}
// FUN_0014B000
void* SceneDraw_GetList5FirstColor(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(5);
    if (res != NULL)
    {
        return res + 0x140;
    }
    return NULL;
}
// FUN_0014B040
void* SceneDraw_GetList5SecondColor(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(5);
    if (res != NULL)
    {
        return res + 0x150;
    }
    return NULL;
}
// FUN_0014B080
void* SceneDraw_GetList5Matrix(void)
{
    u8* res;

    res = MT_Scene_GetResListHead(5);
    if (res != NULL)
    {
        return res + 0x160;
    }
    return NULL;
}
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
