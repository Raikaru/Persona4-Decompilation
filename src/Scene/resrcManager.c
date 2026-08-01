/* Source unit: src/Scene/resrcManager_001470e0.c */
#include "type.h"

typedef struct Resrc Resrc;

/* ResrcType enum from P3FES include/Scene/resrcManager.h: MODELCHAR=1 .. 21,
 * RESRC_TYPE_MAX = 22. */
enum { RESRC_TYPE_MAX = 22 };

typedef struct ResrcManager
{
    Resrc* resLists[RESRC_TYPE_MAX]; /* 0x00. Head of list for every type of resource */
} ResrcManager;

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

extern Resrc* resrcMngGetListHead(ResrcManager* resManager, u8 resType);
extern void func_00147430(ResrcManager* resManager, Resrc* res);

/* Ported from P3FES src/Scene/resrcManager.c FUN_003b5020 (verified MATCH
 * there). 003b5430 -> func_00147500, 003b5360 -> func_00147430,
 * RwFree (rwGlobals.memFuncs.RwFree slot 0096017c) -> DAT_008873ec. */


#pragma alias DAT_008873ec_abs DAT_008873ec

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


// FUN_00147500
Resrc* resrcMngGetListHead(ResrcManager* resManager, u8 resType)
{
    if (resType >= RESRC_TYPE_MAX)
    {
        return NULL;
    }

    return resManager->resLists[resType];
}
