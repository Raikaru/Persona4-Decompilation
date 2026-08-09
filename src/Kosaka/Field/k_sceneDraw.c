/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
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
extern u8* func_001452b0(s32 arg0);
extern void func_003e0870(void *arg0, void *arg1, s32 arg2, f32 arg3);
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
extern Resrc* func_00147530(ResrcManager* resManager, u16 resTypeId);

#define SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY 0x40000000

#define SCENEDRAW_RESRC_FLAG_PERSONA 0x00010000

typedef struct KwlnTask KwlnTask;

extern KwlnTask* func_00470280(KwlnTask* parent, u32 width, u32 height, u32 mode);
typedef void (*KWindowEntryCallback)(void* value);
typedef struct KWindowEntryDescriptor
{
    const char* name;
    s32 type;
    const char* text;
    s32 value0;
    s32 value1;
    s32 value2;
    s32 value3;
    KWindowEntryCallback callback;
} KWindowEntryDescriptor;

extern u32 func_00470970(KwlnTask* task, const char* name);
extern void func_00470ad0(KwlnTask* task, u32 id, const char* text);
extern void func_00470c10(KwlnTask* task, u32 id, s32 value);
extern void func_00470b40(KwlnTask* task, u32 id, s32 value, s32 minValue,
                          s32 maxValue, s32 flags);
extern void func_00470c80(KwlnTask* task, u32 id, s32 value, s32 minValue,
                          s32 maxValue);
extern void func_00470a90(KwlnTask* task, u32 id, KWindowEntryCallback callback);



// FUN_0014A0F0
void func_0014a0f0(u16 resTypeId, u32 visible)
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
void func_0014a300(u16 resTypeId, u32 customLight)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
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
        res = func_00147530(gMtScene->resManager, resTypeId);
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
        res = func_00147530(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (customLight == 1) res->flags |= SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
        else res->flags &= ~SCENEDRAW_RESRC_FLAG_CUSTOM_LIGHT;
    }
}



// FUN_0014A460
void func_0014a460(u16 resTypeId, u32 directionalOnly)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
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
        res = func_00147530(gMtScene->resManager, resTypeId);
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
        res = func_00147530(gMtScene->resManager, resTypeId);
        if (res == NULL) return;
        if (directionalOnly == 1) res->flags |= SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
        else res->flags &= ~SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY;
    }
}



// FUN_0014A5D0
void* func_0014a5d0(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x168;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x168;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x15c;
    }
    return NULL;
}
// FUN_0014A6C0
void* func_0014a6c0(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x178;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x178;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x16c;
    }
    return NULL;
}
// FUN_0014A7B0
void* func_0014a7b0(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x190;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x190;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x180;
    }
    return NULL;
}



// FUN_0014A8A0
void* func_0014a8a0(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1d0;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1d0;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1c0;
    }
    return NULL;
}
// FUN_0014A990
void* func_0014a990(u16 resTypeId)
{
    Resrc* res;
    u32 type;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1e0;
    }
    if (type == RESRC_TYPE_MODELNPC)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1e0;
    }
    if (type == RESRC_TYPE_MODELUNK)
    {
        res = func_00147530(gMtScene->resManager, resTypeId);
        return res == NULL ? NULL : (u8*)res + 0x1d0;
    }
    return NULL;
}
// FUN_0014AA80
void func_0014aa80(u16 resTypeId)
{
    s32 sp[3];
    s32 one;
    u8 *temp_21;
    u8 *temp_19;
    u8 *temp_18;
    u8 *temp_17;
    u8 *temp_16;
    u32 type;

    temp_17 = func_0014a5d0(resTypeId);
    temp_16 = func_0014a6c0(resTypeId);
    temp_19 = func_0014a7b0(resTypeId);
    temp_21 = func_0014a8a0(resTypeId);
    temp_18 = func_0014a990(resTypeId);
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
    func_003e0870(temp_19, &sp[0], 2, -180.0f);
    sp[0] = one;
    sp[1] = 0;
    sp[2] = 0;
    func_003e0870(temp_19, &sp[0], 2, -45.0f);
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
    func_003e0870(temp_18, &sp[0], 2, -180.0f);
    sp[0] = one;
    sp[1] = 0;
    sp[2] = 0;
    func_003e0870(temp_18, &sp[0], 2, -45.0f);
    type = RESRC_GET_TYPE(resTypeId);
    if (type == RESRC_TYPE_MODELCHAR || type == RESRC_TYPE_MODELNPC)
    {
        func_00147530(gMtScene->resManager, resTypeId);
    }
}
// FUN_0014ACD0
void* func_0014acd0(void)
{
    u8* res;

    res = func_001452b0(4);
    if (res != NULL)
    {
        return res + 0x140;
    }
    return NULL;
}
// FUN_0014AD10
void* func_0014ad10(void)
{
    u8* res;

    res = func_001452b0(4);
    if (res != NULL)
    {
        return res + 0x150;
    }
    return NULL;
}
// FUN_0014AD50
void* func_0014ad50(void)
{
    u8* res;

    res = func_001452b0(4);
    if (res != NULL)
    {
        return res + 0x160;
    }
    return NULL;
}
// FUN_0014AD90
void func_0014ad90(void)
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

    temp_2 = func_001452b0(4);
    if (temp_2 != NULL)
    {
        var_20 = temp_2 + 0x140;
    }
    else
    {
        var_20 = NULL;
    }
    temp_2_2 = func_001452b0(4);
    if (temp_2_2 != NULL)
    {
        var_19 = temp_2_2 + 0x150;
    }
    else
    {
        var_19 = NULL;
    }
    temp_2_3 = func_001452b0(4);
    if (temp_2_3 != NULL)
    {
        var_17 = temp_2_3 + 0x160;
    }
    else
    {
        var_17 = NULL;
    }
    temp_2_4 = func_001452b0(4);
    if (temp_2_4 != NULL)
    {
        var_18 = temp_2_4 + 0x1a0;
    }
    else
    {
        var_18 = NULL;
    }
    temp_2_5 = func_001452b0(4);
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
    func_003e0870(var_17, &sp[0], 2, -180.0f);
    sp[0] = one;
    sp[1] = 0;
    sp[2] = 0;
    func_003e0870(var_17, &sp[0], 2, -45.0f);
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
    func_003e0870(var_16, &sp[0], 2, -180.0f);
    sp[0] = one;
    sp[1] = 0;
    sp[2] = 0;
    func_003e0870(var_16, &sp[0], 2, -45.0f);
}
// FUN_0014B000
void* func_0014b000(void)
{
    u8* res;

    res = func_001452b0(5);
    if (res != NULL)
    {
        return res + 0x140;
    }
    return NULL;
}
// FUN_0014B040
void* func_0014b040(void)
{
    u8* res;

    res = func_001452b0(5);
    if (res != NULL)
    {
        return res + 0x150;
    }
    return NULL;
}
// FUN_0014B080
void* func_0014b080(void)
{
    u8* res;

    res = func_001452b0(5);
    if (res != NULL)
    {
        return res + 0x160;
    }
    return NULL;
}
// FUN_0014B0C0
void func_0014b0c0(u16 resTypeId, u32 visible)
{
    Resrc* res;

    if (gMtScene->resManager == NULL)
    {
        goto done;
    }
    res = func_00147530(gMtScene->resManager, resTypeId);
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
void func_0014b150(u16 resTypeId, u32 persona)
{
    Resrc* res;

    if (gMtScene->resManager == NULL)
    {
        goto done;
    }
    res = func_00147530(gMtScene->resManager, resTypeId);
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
KwlnTask* func_00470250(KwlnTask* parent, u32 width, u32 height, u32 unused)
{
    (void)unused;
    return func_00470280(parent, width, height, 0);
}



// FUN_00470810
void func_00470810(KwlnTask* task, const KWindowEntryDescriptor* descriptors,
                   u32 count)
{
    u32 i;
    u32 id;

    i = 0;
    while (i < count)
    {
        id = func_00470970(task, descriptors->name);
        switch (descriptors->type)
        {
            case 0:
                break;
            case 1:
                func_00470ad0(task, id, descriptors->text);
                break;
            case 2:
                func_00470c10(task, id, descriptors->value0);
                break;
            case 3:
                func_00470b40(task, id, descriptors->value0,
                              descriptors->value1, descriptors->value2,
                              descriptors->value3);
                break;
            case 4:
                func_00470c80(task, id, descriptors->value0,
                              descriptors->value1, descriptors->value2);
                break;
        }
        if (descriptors->callback != NULL)
        {
            func_00470a90(task, id, descriptors->callback);
        }
        i++;
        descriptors++;
    }
}
