/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0014A0F0)
/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "type.h"

// 256 bytes. Base struct for every type of resource
typedef struct Resrc
{
    u8 unkData[0x28];
    u32 flags; // 0x28
} Resrc;

#define SCENEDRAW_RESRC_FLAG_VISIBLE 0x00000002

extern Resrc* func_00145270(u16 resTypeId);

// FUN_0014A0F0
void func_0014a0f0(u16 resTypeId, u32 visible)
{
    Resrc* res;

    res = func_00145270(resTypeId);
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
#endif /* P4_UNIT_0014A0F0 */

#if defined(P4_UNIT_0014A300)
/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "type.h"

typedef struct ResrcManager ResrcManager;
typedef struct Resrc
{
    u8 unkData[0x28];
    u32 flags; // 0x28
} Resrc;

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
#endif /* P4_UNIT_0014A300 */

#if defined(P4_UNIT_0014A460)
/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "type.h"

typedef struct ResrcManager ResrcManager;
typedef struct Resrc
{
    u8 unkData[0x28];
    u32 flags; // 0x28
} Resrc;

// 40 bytes
typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

#define RESRC_TYPE_MASK 0xffc00
#define RESRC_GET_TYPE(resTypeId) (((resTypeId) & RESRC_TYPE_MASK) >> 10)

#define SCENEDRAW_RESRC_FLAG_DIRECTIONAL_ONLY 0x40000000

#define RESRC_TYPE_MODELCHAR 1
#define RESRC_TYPE_MODELUNK  2
#define RESRC_TYPE_MODELNPC  3

extern u32 PTR_DAT_00762ea0;
#define gMtScene ((MtScene*)PTR_DAT_00762ea0)
extern Resrc* func_00147530(ResrcManager* resManager, u16 resTypeId);

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
#endif /* P4_UNIT_0014A460 */

#if defined(P4_UNIT_0014A7B0)
/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "type.h"

typedef struct ResrcManager ResrcManager;
typedef struct Resrc
{
    u8 unkData[0x28];
    u32 flags; // 0x28
} Resrc;

// 40 bytes
typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

#define RESRC_TYPE_MASK 0xffc00
#define RESRC_GET_TYPE(resTypeId) (((resTypeId) & RESRC_TYPE_MASK) >> 10)

#define RESRC_TYPE_MODELCHAR 1
#define RESRC_TYPE_MODELUNK  2
#define RESRC_TYPE_MODELNPC  3

extern u32 PTR_DAT_00762ea0;
#define gMtScene ((MtScene*)PTR_DAT_00762ea0)
extern Resrc* func_00147530(ResrcManager* resManager, u16 resTypeId);

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
#endif /* P4_UNIT_0014A7B0 */

#if defined(P4_UNIT_0014B0C0)
/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "type.h"

typedef struct ResrcManager ResrcManager;
typedef struct Resrc
{
    u8 unkData[0x28];
    u32 flags; // 0x28
} Resrc;

// 40 bytes
typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

#define SCENEDRAW_RESRC_FLAG_VISIBLE 0x00000002

extern u32 PTR_DAT_00762ea0;
#define gMtScene ((MtScene*)PTR_DAT_00762ea0)
extern Resrc* func_00147530(ResrcManager* resManager, u16 resTypeId);

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
#endif /* P4_UNIT_0014B0C0 */

#if defined(P4_UNIT_0014B150)
/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "type.h"

typedef struct ResrcManager ResrcManager;
typedef struct Resrc
{
    u8 unkData[0x28];
    u32 flags; // 0x28
} Resrc;

// 40 bytes
typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

#define SCENEDRAW_RESRC_FLAG_PERSONA 0x00010000

extern u32 PTR_DAT_00762ea0;
#define gMtScene ((MtScene*)PTR_DAT_00762ea0)
extern Resrc* func_00147530(ResrcManager* resManager, u16 resTypeId);

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
#endif /* P4_UNIT_0014B150 */

#if defined(P4_UNIT_00470250)
/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;

extern KwlnTask* func_00470280(KwlnTask* parent, u32 width, u32 height, u32 mode);

// FUN_00470250
KwlnTask* func_00470250(KwlnTask* parent, u32 width, u32 height, u32 unused)
{
    (void)unused;
    return func_00470280(parent, width, height, 0);
}
#endif /* P4_UNIT_00470250 */

#if defined(P4_UNIT_00470810)
/* Source unit: src/Kosaka/Field/k_sceneDraw.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;
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
#endif /* P4_UNIT_00470810 */
