#include "include_asm.h"
/* Source unit: src/Scene/resrcManager_001470e0.c */
#include "type.h"

typedef struct Resrc Resrc;

/* ResrcType enum from P3FES include/Scene/resrcManager.h: MODELCHAR=1 .. 21,
 * RESRC_TYPE_MAX = 22. */
typedef enum
{
    RESRC_TYPE_MODELCHAR = 1,
    RESRC_TYPE_MODELUNK,
    RESRC_TYPE_MODELNPC,
    RESRC_TYPE_LIGHTCHAR,
    RESRC_TYPE_LIGHTNPC,
    RESRC_TYPE_06,
    RESRC_TYPE_07,
    RESRC_TYPE_08,
    RESRC_TYPE_09,
    RESRC_TYPE_MODELFLD,
    RESRC_TYPE_11,
    RESRC_TYPE_FLD,
    RESRC_TYPE_FLDHIT,
    RESRC_TYPE_14,
    RESRC_TYPE_15,
    RESRC_TYPE_16,
    RESRC_TYPE_17,
    RESRC_TYPE_18,
    RESRC_TYPE_19,
    RESRC_TYPE_20,
    RESRC_TYPE_21,
    RESRC_TYPE_MAX
} ResrcType;

#define RESRC_ID_MASK   0x3ff
#define RESRC_TYPE_MASK 0xffc00
#define RESRC_GET_ID(resTypeId)   ((resTypeId) & RESRC_ID_MASK)
#define RESRC_GET_TYPE(resTypeId) (((resTypeId) & RESRC_TYPE_MASK) >> 10)

/* P4 layout: next/prev at 0x138/0x13C (P3FES had 0xf8/0xfc), size 0x140. */
struct Resrc
{
    u16 resTypeId;      /* 0x00. bits 0-9 = id. bits 10-15 = type */
    u8 unkData1[0x1a];
    f32 unk_1c;         /* 0x1c */
    f32 unk_20;         /* 0x20 */
    f32 unk_24;         /* 0x24 */
    u8 unkData2[0x110]; /* 0x28 */
    Resrc* next;        /* 0x138 */
    Resrc* prev;        /* 0x13C */
};

typedef struct ResrcManager
{
    Resrc* resLists[RESRC_TYPE_MAX]; /* 0x00. Head of list for every type of resource */
} ResrcManager;

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

extern void func_0044ea90(const char* file, s32 line);
extern void func_0046d730(const char* file, s32 line);
extern void func_00440b68(const char* fmt, ...);
extern void func_0043f9c8(void* dst, s32 value, u32 size);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void* ptr);
extern char D_005EFA40[];
extern char D_005EFA50[];
extern char D_005EFA70[];

extern Resrc* resrcMngGetListHead(ResrcManager* resManager, u8 resType);
extern void func_00147430(ResrcManager* resManager, Resrc* res);

/* Ported from P3FES src/Scene/resrcManager.c FUN_003b5020 (verified MATCH
 * there). 003b5430 -> func_00147500, 003b5360 -> func_00147430,
 * RwFree (rwGlobals.memFuncs.RwFree slot 0096017c) -> DAT_008873ec. */



// FUN_00147070
ResrcManager* resrcMngCreate()
{
    ResrcManager* resMgr;

    func_0044ea90(D_005EFA40, 0x29);
    resMgr = (ResrcManager*)(*jtbl_008873E8)(sizeof(ResrcManager), 0x40000);
    func_0043f9c8(resMgr, 0, sizeof(ResrcManager));

    return resMgr;
}

// FUN_001470E0
void resrcMngDestroy(ResrcManager* resManager)
{
    s32 i;
    Resrc* currList;

    if (resManager != NULL)
    {
        for (i = 0; i < RESRC_TYPE_MAX; i++)
        {
            currList = resrcMngGetListHead(resManager, i);

            while (currList != NULL)
            {
                func_00147430(resManager, currList);

                currList = resrcMngGetListHead(resManager, i);
            }
        }

        DAT_008873ec_abs[0](resManager);
    }
}


// FUN_00147190
Resrc* resrcMngCreateRes(ResrcManager* resManager, u16 resTypeId)
{
    Resrc* res;
    Resrc* currRes;
    Resrc* listHead;
    u32 resSize;
    u16 resId;
    s32 resType;

    resId = resTypeId & 0xffff;
    resType = RESRC_GET_TYPE(resId);
    resSize = 0;
    if (resType >= RESRC_TYPE_MAX)
    {
        func_00440b68(D_005EFA50, D_005EFA40);
        return NULL;
    }

    switch (resType)
    {
    case RESRC_TYPE_MODELCHAR:
        resSize = 0x230;
        break;
    case RESRC_TYPE_MODELUNK:
        resSize = 0x220;
        break;
    case RESRC_TYPE_MODELNPC:
        resSize = 0x370;
        break;
    case RESRC_TYPE_LIGHTCHAR:
        resSize = 0x200;
        break;
    case RESRC_TYPE_LIGHTNPC:
        resSize = 0x200;
        break;
    case RESRC_TYPE_06:
        resSize = 0x148;
        break;
    case RESRC_TYPE_07:
        resSize = 0x150;
        break;
    case RESRC_TYPE_08:
        resSize = sizeof(Resrc);
        break;
    case RESRC_TYPE_MODELFLD:
        resSize = 0x170;
        break;
    case RESRC_TYPE_11:
        resSize = 0x148;
        break;
    case RESRC_TYPE_FLD:
        resSize = 0x1B0;
        break;
    case RESRC_TYPE_FLDHIT:
    case RESRC_TYPE_21:
        resSize = 0x190;
        break;
    case RESRC_TYPE_14:
    case RESRC_TYPE_15:
    case RESRC_TYPE_16:
    case RESRC_TYPE_17:
    case RESRC_TYPE_18:
    case RESRC_TYPE_19:
        resSize = 0x150;
        break;
    case RESRC_TYPE_20:
        resSize = 0x304;
        break;
    }

    if (resSize == 0)
    {
        return NULL;
    }

    func_0044ea90(D_005EFA40, 0x92);
    res = (Resrc*)(*jtbl_008873E8)(resSize, 0x40000);
    func_0043f9c8(res, 0, resSize);
    res->resTypeId = resTypeId;
    res->unk_24 = 1.0f;
    res->unk_20 = 1.0f;
    res->unk_1c = 1.0f;

    currRes = resManager->resLists[resType];
    for (listHead = currRes; listHead != NULL; listHead = listHead->next)
    {
        if (listHead->resTypeId == resId)
        {
            (*jtbl_008873EC)(res);
            func_00440b68(D_005EFA70, D_005EFA40);
            func_0046d730(D_005EFA40, 0xAB);
            return NULL;
        }
    }

    if (currRes != NULL)
    {
        while (currRes->next != NULL)
        {
            currRes = currRes->next;
        }

        currRes->next = res;
        res->prev = currRes;
        res->next = NULL;
    }
    else
    {
        resManager->resLists[resType] = res;
        res->next = NULL;
        res->prev = NULL;
    }

    return res;
}

// FUN_00147430
INCLUDE_ASM("asm/nonmatchings/resrcManager", func_00147430);
// FUN_00147500
Resrc* resrcMngGetListHead(ResrcManager* resManager, u8 resType)
{
    if (resType >= RESRC_TYPE_MAX)
    {
        return NULL;
    }

    return resManager->resLists[resType];
}
