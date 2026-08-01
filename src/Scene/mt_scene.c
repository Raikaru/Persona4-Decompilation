/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00145270)
/* Source unit: src/Scene/mt_scene_00145270.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b5d10 (verified MATCH there).
 * 007cd540 -> PTR_DAT_00762ea0, 003b54c0 -> func_00147530. */

typedef struct Resrc Resrc;
typedef struct ResrcManager ResrcManager;

typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

extern MtScene* gMtScene;
extern Resrc* func_00147530(ResrcManager* resManager, u16 resTypeId);

// FUN_00145270
Resrc* func_00145270(u16 resTypeId)
{
    if (gMtScene->resManager == NULL)
    {
        return NULL;
    }

    return func_00147530(gMtScene->resManager, resTypeId);
}
#endif /* P4_UNIT_00145270 */

#if defined(P4_UNIT_00145300)
/* Source unit: src/Scene/mt_scene_00145300.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b5df0 (verified MATCH there).
 * 007cd540 -> PTR_DAT_00762ea0, 003b5550 -> func_001475c0. */

#define RESRC_TYPE_MAX 22

typedef struct ResrcManager ResrcManager;

typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

extern MtScene* gMtScene;
extern u32 func_001475c0(ResrcManager* resManager, u8 resType);

// FUN_00145300
u32 func_00145300(u32 resType)
{
    s32 i;
    s32 total;
    ResrcManager* resManager;
    u32 type;

    type = resType;
    total = 0;
    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        return 0;
    }

    // Loop over every resource type; only the requested type contributes.
    for (i = 0; i < RESRC_TYPE_MAX; i++)
    {
        if (i == type)
        {
            total += func_001475c0(resManager, i);
        }
    }

    return total;
}
#endif /* P4_UNIT_00145300 */

#if defined(P4_UNIT_001458B0)
/* Source unit: src/Scene/mt_scene_001458b0.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b63c0 (verified MATCH there).
 * 007cd540 -> PTR_DAT_00762ea0, 006a2bb0 -> D_005EF820, 005225a8 ->
 * func_00440b68, 003b50d0 -> func_00147190. */

#define RESRC_ID_MASK 0x3ff
#define RESRC_MAKE_TYPEID(resId, resType) (((resId) & RESRC_ID_MASK) | ((resType) << 10))
#define RESRC_TYPE_LIGHTCHAR 4

typedef struct Resrc Resrc;
typedef struct ResrcManager ResrcManager;

typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

extern MtScene* gMtScene;
extern int func_00440b68(const char* format, ...);
extern Resrc* func_00147190(ResrcManager* resManager, u16 resTypeId);

// FUN_001458B0
u16 func_001458b0(u16 resId)
{
    ResrcManager* resManager;
    u16 resTypeId;

    resTypeId = RESRC_MAKE_TYPEID(resId, RESRC_TYPE_LIGHTCHAR);

    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        func_00440b68("not found active resmanager\n");
        return 0;
    }

    if (func_00147190(resManager, resTypeId) == NULL)
    {
        return 0;
    }

    return resTypeId;
}
#endif /* P4_UNIT_001458B0 */

#if defined(P4_UNIT_00145930)
/* Source unit: src/Scene/mt_scene_00145930.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b6440 (verified MATCH there).
 * 007cd540 -> PTR_DAT_00762ea0, 006a2bb0 -> D_005EF820, 005225a8 ->
 * func_00440b68, 003b50d0 -> func_00147190. */

#define RESRC_ID_MASK 0x3ff
#define RESRC_MAKE_TYPEID(resId, resType) (((resId) & RESRC_ID_MASK) | ((resType) << 10))
#define RESRC_TYPE_LIGHTNPC 5

typedef struct Resrc Resrc;
typedef struct ResrcManager ResrcManager;

typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

extern MtScene* gMtScene;
extern int func_00440b68(const char* format, ...);
extern Resrc* func_00147190(ResrcManager* resManager, u16 resTypeId);

// FUN_00145930
u16 func_00145930(u16 resId)
{
    ResrcManager* resManager;
    u16 resTypeId;

    resTypeId = RESRC_MAKE_TYPEID(resId, RESRC_TYPE_LIGHTNPC);

    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        func_00440b68("not found active resmanager\n");
        return 0;
    }

    if (func_00147190(resManager, resTypeId) == NULL)
    {
        return 0;
    }

    return resTypeId;
}
#endif /* P4_UNIT_00145930 */

#if defined(P4_UNIT_00146F50)
/* Source unit: src/Scene/mt_scene_00146f50.c */
#include "type.h"

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b79a0 (verified MATCH there).
 * 006a2a60 -> D_005EFA10, 006a2a70 -> D_005EFA20, 006a2a80 -> D_005EFA30,
 * 004c31b0 -> func_003e0870, 004c35d0 -> func_003e0c90. */

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct RwMatrix
{
    u32 flags; // 0x00
    u32 pad[15];
} RwMatrix;

extern u8 D_005EFA10[];
extern u8 D_005EFA20[];
extern u8 D_005EFA30[];
extern void func_003e0870(RwMatrix* matrix, const RwV3d* axis, f32 angle, s32 mode);
extern void func_003e0c90(RwMatrix* matrix, u64 param_2, s32 mode);

// FUN_00146F50
void func_00146f50(u32* param_1, u64 param_2, u32* param_3)
{
    u32 uVar1;
    u32 uVar2;
    f32* pfParam3;
    u32* puVar4;
    int iVar3;
    u32 auStack_40[16];

    auStack_40[10] = 0x3f800000;
    auStack_40[5] = 0x3f800000;
    auStack_40[0] = 0x3f800000;
    auStack_40[4] = 0;
    auStack_40[2] = 0;
    auStack_40[1] = 0;
    auStack_40[9] = 0;
    auStack_40[8] = 0;
    auStack_40[6] = 0;
    auStack_40[14] = 0;
    auStack_40[13] = 0;
    auStack_40[12] = 0;
    auStack_40[3] = auStack_40[3] | 0x20003;

    pfParam3 = (f32*)param_3;
    func_003e0870((RwMatrix*)auStack_40, (const RwV3d*)D_005EFA20, pfParam3[1], 1);
    func_003e0870((RwMatrix*)auStack_40, (const RwV3d*)D_005EFA10, pfParam3[0], 1);
    func_003e0870((RwMatrix*)auStack_40, (const RwV3d*)D_005EFA30, pfParam3[2], 1);
    func_003e0c90((RwMatrix*)auStack_40, param_2, 2);

    puVar4 = auStack_40;
    iVar3 = 8;
    do
    {
        uVar1 = *puVar4;
        uVar2 = puVar4[1];
        puVar4 = puVar4 + 2;
        iVar3 = iVar3 + -1;
        *param_1 = uVar1;
        param_1[1] = uVar2;
        param_1 = param_1 + 2;
    } while (0 < iVar3);

    return;
}
#endif /* P4_UNIT_00146F50 */
