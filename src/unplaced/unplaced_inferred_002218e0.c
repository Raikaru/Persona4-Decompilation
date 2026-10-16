/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 002218e0-00221970 */

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
typedef struct KwlnTask KwlnTask;

extern u32 datGetFlag(s32 bit);
u8 *kwlnTaskGetTaskByName(s8 *name);
extern u8 D_006290F0[];
u32 kwlnTaskGetWork(void *task);
extern void datSetFlag(s32 arg0, s32 arg1);
extern s32 datCalcGetLevelById(s32 arg0);
// Intent: Report whether a shuffle child task has its cancel-request bit (0x4) set in its flag word [inferred]
// FUN_002218E0
s32 btlShuffleTaskIsCancelRequestedFor(KwlnTask *task)
{
    return (*(u16 *)kwlnTaskGetWork(task) & 4) != 0;
}

// Intent: Report whether the logo task named D_006290F0 exists. [inferred]
// FUN_00221910
s32 btlLogoTaskExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_006290F0) != 0;
}

// Intent: Report whether a shuffle child task is still loading its sprite blob (flag 0x10 clear; btlShuffle.c sets it when the load completes) [inferred]
// FUN_00221940
s32 btlShuffleTaskIsLoading(KwlnTask *task)
{
    return ((*(u16 *)kwlnTaskGetWork(task) & 0x10) != 0) ^ 1;
}

// Intent: Advance the logo stage flags and set the stage byte from the counter. [inferred]
// FUN_00221970
s32 btlLogoUnlockStage(u8 *arg0)
{
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;

    temp_2 = datCalcGetLevelById(1) & 0xFF;
    temp_3 = 0;
    if (temp_2 >= 0x1E) {
        if (datGetFlag(0x1202) == 0) {
            arg0[0x44] = 0xC;
            datSetFlag(0x1202, 1);
            datSetFlag(0x1201, 1);
            datSetFlag(0x1200, 1);
            temp_3 = 1;
            goto exit;
        }
    }
    if (temp_2 >= 0x19) {
        if (datGetFlag(0x1201) == 0) {
            arg0[0x44] = 0xA;
            datSetFlag(0x1201, 1);
            datSetFlag(0x1200, 1);
            temp_3 = 1;
            goto exit;
        }
    }
    if (temp_2 >= 0x14) {
        if (datGetFlag(0x1200) == 0) {
            arg0[0x44] = 8;
            datSetFlag(0x1200, 1);
            temp_3 = 1;
        }
    }
exit:
    temp_4 = temp_3;
    return temp_4;
}
