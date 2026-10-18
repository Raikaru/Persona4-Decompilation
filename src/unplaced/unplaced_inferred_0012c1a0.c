/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0012c1a0-0012c460 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdktask.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern void (*jtbl_008873EC[])(void *);
extern void func_001029a0(s32 , void *, s32 , s32 );
extern s32 shdWindowTaskCreate(u8 *, s32 , s32 );
extern void shdWindowMarkDone(s32 );
extern s32 shdWindowQueryState(s32 );
extern s32 kwlnTaskIsLinked();
extern void *kwlnTaskGetWork();
extern void kwlnTaskDestroyWithHierarchy();
/* titleStartSoundTask allocates exactly 0x10 bytes; the step callback owns
 * the state, memcard result, countdown, and child window handle. */
typedef struct TitleSoundWork {
    u32 state;
    s32 result;
    s32 countdown;
    s32 windowTask;
} TitleSoundWork;

extern s32 chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005E57B8[];
extern u8 D_005E57D0[];
extern s32 titleSoundStartStep(u8 *);
#include "btl_shuffle_draw_internal.h"
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Reap a linked sound-start task when its result is available. */
// FUN_0012C1A0
s32 titleSoundReapTask(s32 task)
{
    TitleSoundWork *work;

    if ((task == 0) || (kwlnTaskIsLinked() == 0)) {
        return -1;
    }
    work = (TitleSoundWork *)(kwlnTaskGetWork(task));
    if (work->result != 0) {
        kwlnTaskDestroyWithHierarchy(task);
    }
    return work->result;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Wait for sound slots, then run memcard slot creation and its result/retry windows. */
// FUN_0012C220
/* Typed TitleSoundWork accesses changed this callback (508/496 bytes);
 * retain byte-offset loads/stores to preserve the measured whole-file match. */
s32 titleSoundStartStep(u8 *task) {
    s32 countdown;
    s32 result;
    s32 windowState;
    u32 state;
    u8 *work;

    work = ((SdkTask *)task)->work;
    state = *(u32 *)(work + 0);
    switch (state) {
    case 0:
        if ((hsndSlotIsStarting(0) != 0) && (hsndSlotIsStarting(1) != 0)) {
            *(u32 *)(work + 0) = 1U;
        }
        goto block_20;
    default:
        goto block_20;
    case 1:
        *(s32 *)(work + 0xC) = shdWindowTaskCreate(task, 1, 0xF);
        *(s32 *)(work + 8) = 0x3C;
        *(u32 *)(work + 0) = 2U;
        goto block_20;
    case 2:
        countdown = *(s32 *)(work + 8) - 1;
        *(s32 *)(work + 8) = countdown;
        if (countdown == 0) {
            H_Memcard_Reset();
            *(u32 *)(work + 0) = 3U;
        }
        goto block_20;
    case 3:
        result = H_Memcard_CreateSlotsStep();
        *(s32 *)(work + 4) = result;
        if (result != 0) {
            if (result == 0x64) {
                shdWindowMarkDone(*(s32 *)(work + 0xC));
                return -1;
            }
            *(u32 *)(work + 0) = 4U;
            goto block_20;
        }
        goto block_20;
    case 4:
        shdWindowMarkDone(*(s32 *)(work + 0xC));
        if (*(s32 *)(work + 4) == -6) {
            *(s32 *)(work + 0xC) = shdWindowTaskCreate(task, 1, 0x15);
        } else {
            *(s32 *)(work + 0xC) = shdWindowTaskCreate(task, 1, 0x10);
        }
        *(u32 *)(work + 0) = 5U;
        goto block_20;
    case 5:
        windowState = shdWindowQueryState(*(s32 *)(work + 0xC));
        if (windowState == 1) {
            shdWindowMarkDone(*(s32 *)(work + 0xC));
            return -1;
        }
        if (windowState == 2) {
            shdWindowMarkDone(*(s32 *)(work + 0xC));
            *(u32 *)(work + 0) = 1U;
        }
        goto block_20;
    }
block_20:
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Free the sound-start work and request the next scene state. */
// FUN_0012C410
void titleSoundStartDestroy(u8 *task)
{
    jtbl_008873EC[0](((SdkTask *)task)->work);
    func_001029a0(1, 0, 0, 5);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Allocate and register the 0x10-byte sound-start work under the given parent. */
// FUN_0012C460
s32 titleStartSoundTask(s32 parent) {
    s32 task;
    u8 *work;

    chkmemAllocSiteTag(D_005E57B8, 0x74);
    work = D_008873F4[0](1, 0x10, 0x40000);
    if (work == NULL) {
        return 0;
    }
    task = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005E57D0), 0xF, 0, 0, titleSoundStartStep, titleSoundStartDestroy, (u8 *)(work));
    if (task == 0) {
        return 0;
    }
    return task;
}
#pragma pop
