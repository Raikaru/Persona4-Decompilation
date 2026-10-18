/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "sdk_task_registration.h"
#include "kwln_task_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern u8 D_005F5718[];
extern u8 D_00763098;

extern void chkmemAllocSiteTag(void *msg, s32 id);

extern void mdlDestroyModelObject(s32 handle);
extern void *memset(void *dest, s32 value, s32 size);
extern void func_001029a0(s32 id, void *data, s32 size, s32 flag);
extern s32 *MT_Scene_GetFrameState(void);
extern s32 FldLoadTaskIsDone(s32 handle);
extern s32 mtSceneResListPrepareAll(void);

extern s32 K_Test_LauncherUpdate(u8 *arg0);
extern void K_Test_LauncherDestroy(u8 *arg0);

typedef struct
{
    u16 field0;    // 0x00
    u16 field1;    // 0x02
    s16 field2;    // 0x04
    s16 field3;    // 0x06
    s16 field4;    // 0x08
    u8 pad[0x12];  // 0x0A
} TestMenuMsg;

/* Both test tasks allocate 0x1c bytes; only the state and model handle are read here. */
typedef struct TestWork
{
    u32 state;
    s32 modelHandle;
    u8 pad08[0x14];
} TestWork;

/* Create the launcher with its zero-initialized work allocation. */
// FUN_0018E520
void K_Test_CreateLauncher(s32 parentTask)
{
    chkmemAllocSiteTag(D_005F5718, 0x7A);
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(&D_00763098), 0xF, 0, 0, K_Test_LauncherUpdate, K_Test_LauncherDestroy, (u8 *)(D_008873F4[0](1, 0x1C, 0x40000)));
}

/* Alternate two scene requests after each asynchronous field load completes. */
// FUN_0018E5B0
s32 K_Test_Update(u8 *task)
{
    TestWork *work;
    u32 state;
    TestMenuMsg message;

    work = (TestWork *)((KwlnTask *)task)->work;
    state = work->state;
    switch (state) {
    case 0:
        work->state = state + 1;
        break;
    case 1:
    case 2:
    case 3:
        work->state = state + 1;
        break;
    case 4:
        if (FldLoadTaskIsDone(*MT_Scene_GetFrameState()) != 0 && mtSceneResListPrepareAll() != 0) {
            memset(&message, 0, 0x1C);
            message.field0 = 6;
            message.field1 = 6;
            message.field2 = 0;
            message.field4 = 0;
            func_001029a0(9, &message, 0x1C, 3);
            work->state += 1;
        }
        break;
    case 5:
    case 6:
    case 7:
        work->state = state + 1;
        break;
    case 8:
        if (FldLoadTaskIsDone(*MT_Scene_GetFrameState()) != 0 && mtSceneResListPrepareAll() != 0) {
            memset(&message, 0, 0x1C);
            message.field0 = 6;
            message.field1 = 2;
            message.field2 = 5;
            message.field4 = 0;
            func_001029a0(9, &message, 0x1C, 3);
            work->state = 1;
        }
        break;
    }
    return 0;
}

/* Release the optional model handle before freeing the test work. */
// FUN_0018E730
/* The 0x1c-byte TestWork has its model handle at offset 4. A typed rewrite
 * changed five instruction bytes; retain the byte view and final work-slot reload. */
void K_Test_Destroy(u8 *task)
{
    u8 *work;
    s32 modelHandle;

    work = *(u8 **)(task + 0x38);
    modelHandle = *(s32 *)(work + 4);
    if (modelHandle != 0) {
        mdlDestroyModelObject(modelHandle);
    }
    jtbl_008873EC[0](*(void **)(task + 0x38));
}

/* Start the scene-cycling test under the supplied parent task. */
// FUN_0018E780
void K_Test_Create(s32 parentTask)
{
    chkmemAllocSiteTag(D_005F5718, 0xE0);
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(&D_00763098), 0x12, 0, 0, K_Test_Update, K_Test_Destroy, (u8 *)(D_008873F4[0](1, 0x1C, 0x40000)));
}
