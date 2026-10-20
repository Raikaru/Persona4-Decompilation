/* Whole-file translation unit: src/Main/gameSequence.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"
#include "sdk_task_registration.h"

extern void poolSetAllocationSite(const void *allocationFile, u32 allocationLine);
extern s32 H_Calloc(s32, s32);

extern void kAssertFail(const void *file, u32 line);
extern s32 kwlnTaskGetTaskByName(void *name);
extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern char D_005E51C0[];
extern char D_005E51D0[];
extern void calendarResetPending(void);
extern s32 clndSceneUpdate(u8 *task);
extern void taskReleaseSlotModel(u8 *task);

/* Starts the "gameSequence" task with clndSceneUpdate as its update, then runs the scene start. */
// FUN_00124240
void gameSequenceStart(void)
{
    s32 work;

    poolSetAllocationSite(D_005E51C0, 0x178);
    work = H_Calloc(1, 0x10);
    if (work != 0) {
        (s32)kwlnTaskCreate((const void *)(D_005E51D0), 0x100, 0, 0, clndSceneUpdate, taskReleaseSlotModel, (u8 *)(work));
        calendarResetPending();
    }
}

/* Reports whether the "gameSequence" task is running. */
// FUN_001242C0
s32 gameSequenceIsRunning(void)
{
    return (s32)(kwlnTaskGetTaskByName(D_005E51D0) != 0);
}

/* Stops the "gameSequence" task; the caller must have started it. */
// FUN_001242F0
void gameSequenceStop(void)
{
    s32 task;

    task = kwlnTaskGetTaskByName(D_005E51D0);
    if (task == 0) {
        kAssertFail(D_005E51C0, 0x1CC);
    }
    kwlnTaskDestroyWithHierarchy(task);
}
