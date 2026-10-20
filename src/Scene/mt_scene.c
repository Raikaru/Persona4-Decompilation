/* Source unit: src/Scene/mt_scene_00145270.c */
#include "type.h"
#include "scene_event_internal.h"

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b5d10 (verified MATCH there).
 * 007cd540 -> PTR_DAT_00762ea0, 003b54c0 -> resrcMngFindResById. */

typedef struct Resrc Resrc;
typedef struct ResrcManager ResrcManager;
extern u8* PTR_DAT_00762ea0;
extern u8 *iGpffff9db0;
extern u8 *resrcMngGetListHead(u8 *resManager, s32 resType);

typedef struct MtScene
{
    s32 fldMajorId;           // 0x00
    s32 fldMinorId;           // 0x04
    ResrcManager* resManager; // 0x08
} MtScene;

extern MtScene* gMtScene;
extern u8 *resrcMngFindResById(ResrcManager* manager, u16 resourceId);
extern void MT_Scene_ApplyResTransform(u8 *resource, u8 *position, u8 *rotation, u8 *scaleInput);

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b5df0 (verified MATCH there).
 * 007cd540 -> PTR_DAT_00762ea0, 003b5550 -> resrcMngGetTotalResInList. */

#define RESRC_TYPE_MAX 22
extern u32 resrcMngGetTotalResInList(ResrcManager* resLists, u8 resType);

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b63c0 (verified MATCH there).
 * 007cd540 -> PTR_DAT_00762ea0, 006a2bb0 -> D_005EF820, 005225a8 ->
 * func_00440b68, 003b50d0 -> func_00147190. */

#define RESRC_ID_MASK 0x3ff
#define RESRC_MAKE_TYPEID(resId, resType) (((resId) & RESRC_ID_MASK) | ((resType) << 10))
#define RESRC_TYPE_LIGHTCHAR 4
extern int func_00440b68(const char* format, ...);
extern Resrc* resrcMngCreateRes(ResrcManager* resManager, u16 resTypeId);
#define RESRC_TYPE_LIGHTNPC 5

/* Ported from P3FES src/Scene/mt_scene.c FUN_003b79a0 (verified MATCH there).
 * 006a2a60 -> D_005EFA10, 006a2a70 -> D_005EFA20, 006a2a80 -> D_005EFA30,
 * 004c31b0 -> func_003e0870, 004c35d0 -> func_003e0c90. */

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct RwMatrixTag RwMatrix;

extern u8 D_005EFA10[];
extern u8 D_005EFA20[];
extern u8 D_005EFA30[];
extern RwMatrix* RwMatrixRotate(RwMatrix* matrix, const RwV3d* axis, f32 angle, s32 mode);
extern RwMatrix* RwMatrixTranslate(RwMatrix* matrix, const RwV3d* translation, s32 mode);



// FUN_00145250
s32 MT_Scene_GetObject(void) {
    return (s32)PTR_DAT_00762ea0;
}
// FUN_00145260
u32 MT_Scene_GetResManager(void)
{
    return (u32)((MtScene *)PTR_DAT_00762ea0)->resManager;
}
/* Look up the packed resource type/id in the active manager. */
// FUN_00145270
u8 *MT_Scene_GetRes(u16 resTypeId)
{
    if (gMtScene->resManager == NULL)
    {
        return NULL;
    }

    return resrcMngFindResById(gMtScene->resManager, resTypeId);
}



/* Return the selected resource list, or NULL when no manager is active. */
// FUN_001452B0
u8 *MT_Scene_GetResListHead(s32 resourceType)
{
    u8 *resManager;

    resManager = (u8 *)((MtScene *)iGpffff9db0)->resManager;
    if (resManager == NULL) {
        return NULL;
    }
    return resrcMngGetListHead(resManager, (u8)(resourceType & 0xFF));
}
/* Count resources of the requested type; out-of-range types contribute nothing. */
// FUN_00145300
u32 MT_Scene_GetTotalResInList(u32 resType)
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
            total += resrcMngGetTotalResInList(resManager, i);
        }
    }

    return total;
}



/* Allocate a character-light resource and return its packed type/id, or zero on failure. */
// FUN_001458B0
u16 MT_Scene_CreateResLightChar(u16 resId)
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

    if (resrcMngCreateRes(resManager, resTypeId) == NULL)
    {
        return 0;
    }

    return resTypeId;
}



/* Allocate an NPC-light resource and return its packed type/id, or zero on failure. */
// FUN_00145930
u16 MT_Scene_CreateResLightNpc(u16 resId)
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

    if (resrcMngCreateRes(resManager, resTypeId) == NULL)
    {
        return 0;
    }

    return resTypeId;
}



/* Apply position and rotation only when the resource exists. */
// FUN_00146E60
void MT_Scene_SetResPlacement(u16 resourceId, u8 *position, u8 *angles)
{
    u8 *resource;

    if (((MtScene *)PTR_DAT_00762ea0)->resManager == 0)
    {
        resource = 0;
    }
    else
    {
        resource = resrcMngFindResById(((MtScene *)PTR_DAT_00762ea0)->resManager, resourceId);
    }

    if (resource != 0)
    {
        (MT_Scene_ApplyResTransform)(resource, position, angles, 0);
    }
}



/* Forward the optional vector through the transform scale-input slot, as retail does. */
/* The vector is forwarded to ApplyResTransform's scale slot; despite the current symbol name, this wrapper changes scale. */
// FUN_00146EE0
void MT_Scene_SetResAngles(u16 resourceId, u8 *scale)
{
    u8 *resource;

    if (((MtScene *)PTR_DAT_00762ea0)->resManager == 0)
    {
        resource = 0;
    }
    else
    {
        resource = resrcMngFindResById(((MtScene *)PTR_DAT_00762ea0)->resManager, resourceId);
    }

    if (resource != 0)
    {
        (MT_Scene_ApplyResTransform)(resource, 0, 0, scale);
    }
}
/* Build a Y/X/Z rotation followed by translation and copy the 64-byte RenderWare matrix. */
// FUN_00146F50
void MT_Scene_BuildResMatrix(u32* outputWords, const void* position, u32* angles)
{
    u32 firstWord;
    u32 secondWord;
    f32* rotation;
    u32* sourceWords;
    s32 remainingPairs;
    u32 matrixWords[16];

    matrixWords[10] = 0x3f800000;
    matrixWords[5] = 0x3f800000;
    matrixWords[0] = 0x3f800000;
    matrixWords[4] = 0;
    matrixWords[2] = 0;
    matrixWords[1] = 0;
    matrixWords[9] = 0;
    matrixWords[8] = 0;
    matrixWords[6] = 0;
    matrixWords[14] = 0;
    matrixWords[13] = 0;
    matrixWords[12] = 0;
    matrixWords[3] = matrixWords[3] | 0x20003;

    rotation = (f32*)angles;
    RwMatrixRotate((RwMatrix*)matrixWords, (const RwV3d*)D_005EFA20, rotation[1], 1);
    RwMatrixRotate((RwMatrix*)matrixWords, (const RwV3d*)D_005EFA10, rotation[0], 1);
    RwMatrixRotate((RwMatrix*)matrixWords, (const RwV3d*)D_005EFA30, rotation[2], 1);
    RwMatrixTranslate((RwMatrix*)matrixWords, (const RwV3d*)position, 2);

    sourceWords = matrixWords;
    remainingPairs = 8;
    do
    {
        firstWord = *sourceWords;
        secondWord = sourceWords[1];
        sourceWords = sourceWords + 2;
        remainingPairs = remainingPairs + -1;
        *outputWords = firstWord;
        outputWords[1] = secondWord;
        outputWords = outputWords + 2;
    } while (0 < remainingPairs);

    return;
}
