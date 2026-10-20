#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "datScript_internal.h"
extern void chkmemAllocSiteTag(void *file, s32 line);

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00635990[];
extern u8 D_006359A0[];
extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern s32 kwlnTaskGetTaskByName(void *name);
extern void kAssertFail(void *file, s32 line);
extern u8 D_006359B0[];
extern u8 D_006359C0[];

extern f32 D_00761260;
extern f32 fGpffff811c;

extern s32 mdlNeckTestUpdateNoop(u8 *unusedTask);
extern void mdlNeckTestDestroyNoop(u8 *unusedTask);
// Creates the model_neck_test debug task with the mdlNeckTest.c alloc site.
// FUN_002465A0
void mdlNeckTestCreate(void)
{
    chkmemAllocSiteTag(D_00635990, 0xD1);
    (s32)kwlnTaskCreate((const void *)(D_006359A0), 0xF, 0, 0, mdlNeckTestUpdateNoop, mdlNeckTestDestroyNoop, (u8 *)(D_008873F4[0](1, 8, 0x40000)));
}

// FUN_00246620
void mdlNeckTestStart(void)
{
    mdlNeckTestCreate();
}

// Reports whether the model_neck_test debug task exists.
// FUN_00246640
s32 mdlNeckTestExists(void)
{
    return kwlnTaskGetTaskByName(D_006359B0) != 0;
}

// Destroys the model_neck_test debug task, asserting it exists (niidaTestMenu.c).
// FUN_00246670
void mdlNeckTestDestroy(void)
{
    s32 task;

    task = kwlnTaskGetTaskByName(D_006359B0);
    if (task == 0) {
        kAssertFail(D_006359C0, 0x3D);
    }
    kwlnTaskDestroyWithHierarchy(task);
}

