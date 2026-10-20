
#include "rw_types_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
#include "btl_result_ui_internal.h"
typedef struct KwlnTask KwlnTask;

extern u32 datGetFlag(s32 bit);
u8 *kwlnTaskGetTaskByName(s8 *name);
extern u8 D_006290F0[];
u32 kwlnTaskGetWork(void *task);
extern void datSetFlag(s32 work, s32);
extern s32 datCalcGetLevelById(s32 unitId);
// Report whether a shuffle child task has its cancel-request bit (0x4) set in its flag word.
// FUN_002218E0
s32 btlShuffleTaskIsCancelRequestedFor(KwlnTask *task)
{
    return (*(u16 *)kwlnTaskGetWork(task) & 4) != 0;
}

// Report whether the logo task named D_006290F0 exists.
// FUN_00221910
s32 btlLogoTaskExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_006290F0) != 0;
}

// Report whether a shuffle child task is still loading its sprite blob; btlShuffle.c sets flag 0x10
// when the load completes.
// FUN_00221940
s32 btlShuffleTaskIsLoading(KwlnTask *task)
{
    return ((*(u16 *)kwlnTaskGetWork(task) & 0x10) != 0) ^ 1;
}

// Advance the logo stage flags and set the stage byte from the counter.
// FUN_00221970
s32 btlLogoUnlockStage(u8 *work)
{
    s32 level;
    s32 unlocked;
    s32 result;

    level = datCalcGetLevelById(1) & 0xFF;
    unlocked = 0;
    if (level >= 0x1E) {
        if (datGetFlag(0x1202) == 0) {
            ((BtlLogoWork *)work)->stage = 0xC;
            datSetFlag(0x1202, 1);
            datSetFlag(0x1201, 1);
            datSetFlag(0x1200, 1);
            unlocked = 1;
            goto exit;
        }
    }
    if (level >= 0x19) {
        if (datGetFlag(0x1201) == 0) {
            ((BtlLogoWork *)work)->stage = 0xA;
            datSetFlag(0x1201, 1);
            datSetFlag(0x1200, 1);
            unlocked = 1;
            goto exit;
        }
    }
    if (level >= 0x14) {
        if (datGetFlag(0x1200) == 0) {
            ((BtlLogoWork *)work)->stage = 8;
            datSetFlag(0x1200, 1);
            unlocked = 1;
        }
    }
exit:
    result = unlocked;
    return result;
}
