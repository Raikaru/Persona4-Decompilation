/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00298FC0)
/* Source unit: src/Script/scrCommonCommand_00298fc0.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;

extern s32 func_0029cc00(s32 paramIdx);
extern u32 func_0029d020(void);

// FUN_00298FC0
u32 scrCommand_WAIT()
{
    s32 cmdTimer;

    if (func_0029cc00(0) < 1)
    {
        return 1;
    }

    cmdTimer = func_0029d020();

    return func_0029cc00(0) <= cmdTimer;
}
#endif /* P4_UNIT_00298FC0 */

#if defined(P4_UNIT_002995C0)
/* Source unit: src/Script/scrCommonCommand_002995c0.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;

extern s32 func_0029cc00(s32 paramIdx);
extern u32 func_00452490(KwlnTask* task);

// FUN_002995C0
u32 scrCommand_SCR_KILL_SYNC()
{
    KwlnTask* task;

    task = (KwlnTask*)func_0029cc00(0);

    return func_00452490(task) == 0;
}
#endif /* P4_UNIT_002995C0 */

#if defined(P4_UNIT_00299600)
/* Source unit: src/Script/scrCommonCommand_00299600.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;

extern s32 func_0029cc00(s32 paramIdx);
extern u32 func_00452490(KwlnTask* task);
extern void func_0029cf50(s32 retVal);

// FUN_00299600
u32 scrCommand_SCR_EXISTS()
{
    KwlnTask* task;

    task = (KwlnTask*)func_0029cc00(0);

    if (func_00452490(task))
    {
        func_0029cf50(1);
    }
    else
    {
        func_0029cf50(0);
    }

    return 1;
}
#endif /* P4_UNIT_00299600 */

#if defined(P4_UNIT_00299660)
/* Source unit: src/Script/scrCommonCommand_00299660.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;

extern s32 func_0029cc00(s32 paramIdx);
extern u32 func_00452490(KwlnTask* task);
extern void func_0029cf50(s32 retVal);
extern u32 func_00452540(KwlnTask* task);

// FUN_00299660
u32 scrCommand_SCR_GET_TIMER()
{
    KwlnTask* task;

    task = (KwlnTask*)func_0029cc00(0);

    if (!func_00452490(task))
    {
        func_0029cf50(0);
    }
    else
    {
        func_0029cf50(func_00452540(task));
    }

    return 1;
}
#endif /* P4_UNIT_00299660 */
