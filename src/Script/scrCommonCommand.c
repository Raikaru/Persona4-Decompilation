/* Source unit: src/Script/scrCommonCommand_00298fc0.c */
#include "type.h"

typedef struct KwlnTask KwlnTask;

extern s32 func_0029cc00(s32 paramIdx);
extern u32 func_0029d020(void);

void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
/* Source unit: src/Kosaka/k_command/k_command_00299400.c (1 function markers) */
#include "Kosaka/k_command_internal.h"
#include "include_asm.h"

extern u32 func_00452490(KwlnTask* task);
extern void func_0029cf50(s32 retVal);
extern u32 kwlnTaskGetTimer(KwlnTask* task);




// FUN_00298DB0
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00298db0);

// FUN_00298E20
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00298e20);

// FUN_00298E90
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00298e90);

// FUN_00298F40
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00298f40);

// FUN_00298F90
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00298f90);

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




// FUN_00299020
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00299020);

// FUN_00299060
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00299060);

// FUN_002990A0
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_002990a0);

// FUN_002990E0
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_002990e0);

// FUN_00299140
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00299140);

// FUN_00299170
s32 func_00299170(void) {
    s16 sp1C[2]; /* measured: 2-element form required for retail slot at 0x1c */

    sp1C[0] = func_0029cc00(0);
    func_001029a0(0x1D, sp1C, 2, 0xA);
    return 1;
}




// FUN_002991C0
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_002991c0);

// FUN_002991F0
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_002991f0);

// FUN_00299290
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00299290);

// FUN_002992D0
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_002992d0);

// FUN_00299310
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00299310);

// FUN_002993C0
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_002993c0);

// FUN_00299400
u32 func_00299400()
{
    func_00106550(func_0029cc00(0), func_0029cc00(1));

    return true;
}




// FUN_00299450
INCLUDE_ASM("asm/nonmatchings/scrCommonCommand", func_00299450);

// FUN_002995C0
u32 scrCommand_SCR_KILL_SYNC()
{
    KwlnTask* task;

    task = (KwlnTask*)func_0029cc00(0);

    return func_00452490(task) == 0;
}



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
        func_0029cf50(kwlnTaskGetTimer(task));
    }

    return 1;
}
