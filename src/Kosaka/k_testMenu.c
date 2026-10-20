#include "field_transition_internal.h"
/* Whole-file translation unit (functions contiguous in retail). */
#include "sdk_lbox_internal.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "sdk_task_registration.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u16 D_008C024E[];

extern const KWindowEntryDescriptor D_005F55B0[];
extern u8 D_005F56F0[];
extern u8 D_005F5700[];
extern f32 D_00761624;
extern f32 D_0076151C;

extern void chkmemAllocSiteTag(void *file, s32 line);
extern void kAssertFail(void *file, s32 line);
extern s32 kwlnTaskIsLinked(s32 target);
extern s32 kwlnTaskGetTaskByName(void *name);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);


extern s32 FldMapTestTaskCreate(u8 *parent);
extern s32 K_Test_CreateLauncher(u8 *parentTask);
extern void K_ReadTexTaskCreate(void);
extern s32 FldRainTaskCreate(f32 parent, u8 *textureIndex, s32 distance, f32 acceleration, f32 speed, f32 spacing,
                          s32 alpha, s32 trailLength, s32 spawnInterval);
extern s32 FldPlayerIconTaskCreate(u8 *task);
extern s32 K_Clump_CreateLoadTask(s32);
extern s32 K_TexStripBuildTaskCreate(s32);
extern s32 K_TexStripLoadTaskCreate(s32);
extern s32 K_TexStripCodeLogTaskCreate(s32);

/* The create routine allocates exactly 0xc bytes for the menu and child handles. */
typedef struct TestMenuWork
{
    s32 state;
    u8 *listBox;
    s32 childTask;
} TestMenuWork;

/* Launch the selected debug task and suspend selection until its child exits. */
// FUN_0018E050
s32 K_TestMenu_Update(u8 *task)
{
    TestMenuWork *work;
    s32 state;

    work = (TestMenuWork *)((KwlnTask *)task)->work;
    state = work->state;
    switch (state) {
    case 0:
    {
        KwlnTask *listBox;

        listBox = sdkLboxCreate((KwlnTask *)task, 0x100, 0x40);
        *(KwlnTask **)&work->listBox = listBox;
        sdkLboxAddDescriptors(listBox, D_005F55B0, 0xA);
        sdkLboxSetVisibleRows(work->listBox, 0x14);
        sdkLboxSetState(work->listBox, 4);
        sdkLboxSetSelection(work->listBox, 1);
        work->state = work->state + 1;
        break;
    }
    case 1:
        if (D_008C024E[0] & 0x40) {
            switch (sdkLboxGetSelectedId(work->listBox)) {
            case 0:
                work->childTask = FldMapTestTaskCreate(task);
                break;
            case 1:
                work->childTask = K_Test_CreateLauncher(task);
                break;
            case 2:
                K_ReadTexTaskCreate();
                break;
            case 3:
                work->childTask = FldRainTaskCreate(200.0f, task, 0, D_00761624,
                                                  D_0076151C, 30.0f, 0x30, 8,
                                                  0xA);
                break;
            case 4:
                work->childTask = FldNoiseTaskCreate(task);
                break;
            case 5:
                work->childTask = FldPlayerIconTaskCreate(task);
                break;
            case 6:
                work->childTask = K_Clump_CreateLoadTask(0);
                break;
            case 7:
                work->childTask = K_TexStripBuildTaskCreate(0);
                break;
            case 8:
                work->childTask = K_TexStripLoadTaskCreate(0);
                break;
            case 9:
                work->childTask = K_TexStripCodeLogTaskCreate(0);
                break;
            default:
                kAssertFail(D_005F56F0, 0xA1);
                break;
            }
            sdkLboxSetSelection(work->listBox, 0);
            work->state = 2;
        } else if (D_008C024E[0] & 0x20) {
            work->state = 3;
        }
        break;
    case 2:
        if (kwlnTaskIsLinked(work->childTask) != 1) {
            sdkLboxSetSelection(work->listBox, 1);
            work->state = 1;
        }
        break;
    case 3:
        return -1;
    }
    return 0;
}

/* Free menu work; the scheduler owns destruction of child tasks. */
// FUN_0018E310
void K_TestMenu_Destroy(u8 *task)
{
    jtbl_008873EC[0]((void *)((KwlnTask *)task)->work);
}

/* Create the top-level debug menu with zeroed work. */
// FUN_0018E340
void K_TestMenu_Create(void)
{
    chkmemAllocSiteTag(D_005F56F0, 0xCB);
    kwlnTaskCreate((const void *)(D_005F5700), 0xF, 0, 0, K_TestMenu_Update, K_TestMenu_Destroy, (u8 *)(D_008873F4[0](1, 0xC, 0x40000)));
}

// FUN_0018E3C0
s32 K_TestMenu_IsActive(void)
{
    return kwlnTaskGetTaskByName(D_005F5700) != 0;
}

/* Locate and destroy the menu hierarchy; absence is an assertion failure. */
// FUN_0018E3F0
void K_TestMenu_Close(void)
{
    s32 menuTask;

    menuTask = kwlnTaskGetTaskByName(D_005F5700);
    if (menuTask == 0) {
        kAssertFail(D_005F56F0, 0xF2);
    }
    kwlnTaskDestroyWithHierarchy((KwlnTask *)menuTask);
}
