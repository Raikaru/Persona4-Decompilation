#include "include_asm.h"
#include "sdk_task_registration.h"
/* Source unit: src/Main/logoDraw_0012bbb0.c */
#include "type.h"
#include "primitive_queue_internal.h"


extern void func_00440b68(...);
extern void chkmemAllocSiteTag(const void *file, u32 line);
extern void kAssertFail(const void *file, u32 line);
extern void *H_Cdvd_AcquireDirectory(const char *path, s32 flags);
extern void H_Cdvd_Destroy(void *cdvd);
extern s32 H_Cdvd_IsFileLoaded(void *cdvd);

extern s32 kwlnTaskIsLinked(s32);
extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern s32 filerEnqueueRequest(s32, const char *, s32, s32, s32, s32, s32, s32, s64, s64);
extern void *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *, void *);
extern void fadeBeginTransition(s32, s32);
extern void fadeBeginReturnTransition(s32, s32);
extern s32 fadeStatus(void);
extern s32 titleFileLoadStep(u8 *unusedTask);
extern void titleLoaderDestroy(u8 *unusedTask);
extern void titleDrawChildImage(void);
extern void *kwlnTaskGetWork();
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern char D_00762D88;
extern char D_00762D98;
extern char D_005E5730[];
extern char D_005E5760[];
extern char D_005E5770[];
extern char D_005E5790[];
extern char D_005E57A8[];
extern char D_00795E60[];
extern s32 logoTaskUpdate(u8 *sdkTaskBytes);
extern void logoTaskDestroy(u8 *unusedTask);


/* Keep the allocator table base as a u32 local so MWCCPS2 hoists its
 * address into $s2 and reuses it at both allocation call sites. */
typedef struct {
    s32 state;
    s32 index;
    s32 counter;
    s32 handle;
    s32 task10;
    s32 task14;
} LogoWork;

/* Logo task update: loads the logo file, starts its two child tasks, then fades the logo in and out. */
// FUN_0012BBB0

s32 logoTaskUpdate(u8 *sdkTaskBytes)
{
    s32 task = (s32)sdkTaskBytes;
    s32 firstChildTask;
    s32 secondChildTask;
    s32 firstLogoFrame;
    s32 secondLogoFrame;
    s32 firstChildReady;
    s32 secondChildReady;
    s32 *firstChildWork;
    s32 *secondChildWork;
    LogoWork *work;
    s32 state;
    s32 *firstLoader;
    s32 *secondLoader;
    u32 allocator;
    void *drawNode;

    work = (LogoWork *)kwlnTaskGetWork();
    state = work->state;
    switch (state) {
    case 0:
        work->state = 1;
    case 1:
        work->state = 2;
        func_00440b68(&D_00762D88, &D_005E5730, 0xB5);
        work->handle = (s32)H_Cdvd_AcquireDirectory(D_005E5760, 1);
    case 2:
        if (H_Cdvd_IsFileLoaded((void *)work->handle) != 0) {
            work->state = 3;
            chkmemAllocSiteTag(&D_005E5730, 0x4D);
            allocator = (u32)D_008873F4;
            firstLoader = (s32 *)((void *(*)(s32, s32, u32))*(u32 *)allocator)(1, 0xC, 0x40000);
            firstLoader[0] = 0;
            firstLoader[1] = (s32)filerEnqueueRequest(0, D_005E5770, 0, 0, 0, 0, 0, 0, 0, 0);
            work->task10 = (s32)kwlnTaskCreate((const void *)(&D_00762D98), 0x100, 0, 0, titleFileLoadStep, titleLoaderDestroy, (u8 *)(firstLoader));
            chkmemAllocSiteTag(&D_005E5730, 0x4D);
            secondLoader = (s32 *)((void *(*)(s32, s32, u32))*(u32 *)allocator)(1, 0xC, 0x40000);
            secondLoader[0] = 0;
            secondLoader[1] = (s32)filerEnqueueRequest(0, D_005E5790, 0, 0, 0, 0, 0, 0, 0, 0);
            work->task14 = (s32)kwlnTaskCreate((const void *)(&D_00762D98), 0x100, 0, 0, titleFileLoadStep, titleLoaderDestroy, (u8 *)(secondLoader));
        }
        break;
    case 3:
        firstChildTask = work->task10;
        firstChildWork = (s32 *)kwlnTaskGetWork(firstChildTask);
        if (kwlnTaskIsLinked(firstChildTask) == 0) {
            firstChildReady = 0;
        } else if (*firstChildWork == 3) {
            firstChildReady = 1;
        } else {
            firstChildReady = 0;
        }
        if (firstChildReady != 0) {
            secondChildTask = work->task14;
            secondChildWork = (s32 *)kwlnTaskGetWork(secondChildTask);
            if (kwlnTaskIsLinked(secondChildTask) == 0) {
                secondChildReady = 0;
            } else if (*secondChildWork == 3) {
                secondChildReady = 1;
            } else {
                secondChildReady = 0;
            }
            if (secondChildReady != 0) {
                work->state = 4;
            }
        }
        break;
    case 4:
        work->state = 5;
        work->counter = 0;
        fadeBeginReturnTransition(0, 0xA);
    case 5:
        firstLogoFrame = work->counter + 1;
        work->counter = firstLogoFrame;
        if (firstLogoFrame >= 0x46) {
            work->state = 6;
            fadeBeginTransition(1, 0xA);
        }
        break;
    case 6:
        if (fadeStatus() != 0) {
            work->state = 7;
        case 7:
            work->state = 8;
            work->counter = 0;
            fadeBeginReturnTransition(0, 0xA);
        case 8:
            secondLogoFrame = work->counter + 1;
            work->counter = secondLogoFrame;
            if (secondLogoFrame >= 0x46) {
                work->state = 9;
                fadeBeginTransition(1, 0xA);
            }
        }
        break;
    case 9:
        if (fadeStatus() != 0) {
            work->state = 0xA;
        case 10:
            if (fadeStatus() != 0) {
                work->index = 1;
            }
        }
        break;
    }
    drawNode = PrimAllocQueueNode();
    *(s32 *)&((PrimQueueNode *)drawNode)->callback = (s32)titleDrawChildImage;
    *(s32 * *)&((PrimQueueNode *)drawNode)->argument.data = (s32 *)task;
    PrimAppendNode(&D_00795E60, drawNode);
    return 0;
}



/* Destroy callback of the logo task: checks the child tasks, then releases them and the handle. */
// FUN_0012BFB0
void logoTaskDestroy(u8 *unusedTask)
{
    typedef struct LogoWork LogoWork;
    struct LogoWork
    {
        s32 state;
        s32 index;
        s32 counter;
        void *handle;
        s32 task10;
        s32 task14;
    };
    LogoWork *work;
    s32 *firstChildWork;
    s32 *secondChildWork;
    s32 firstChildTask;
    s32 secondChildTask;
    s32 firstChildReady;
    s32 secondChildReady;

    work = kwlnTaskGetWork();
    firstChildTask = work->task10;
    firstChildWork = kwlnTaskGetWork(firstChildTask);
    if (kwlnTaskIsLinked(firstChildTask) == 0) {
        firstChildReady = 0;
    } else if (*firstChildWork == 3) {
        firstChildReady = 1;
    } else {
        firstChildReady = 0;
    }
    if (firstChildReady == 0) {
        kAssertFail(&D_005E5730, 0xF8);
    }
    secondChildTask = work->task14;
    secondChildWork = kwlnTaskGetWork(secondChildTask);
    if (kwlnTaskIsLinked(secondChildTask) == 0) {
        secondChildReady = 0;
    } else if (*secondChildWork == 3) {
        secondChildReady = 1;
    } else {
        secondChildReady = 0;
    }
    if (secondChildReady == 0) {
        kAssertFail(&D_005E5730, 0xF9);
    }
    kwlnTaskDestroyWithHierarchy(work->task10);
    kwlnTaskDestroyWithHierarchy(work->task14);
    H_Cdvd_Destroy(work->handle);
    jtbl_008873EC[0](work);
}



/* Starts the logo task with the logo work block. */
// FUN_0012C110
s32 logoTaskStart(void)
{
    void *work;

    chkmemAllocSiteTag(&D_005E5730, 0x107);
    work = D_008873F4[0](1, 0x18, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ((LogoWork *)work)->index = 0;
    return (s32)kwlnTaskCreate((const void *)(&D_005E57A8), 0xF, 0, 0, logoTaskUpdate, logoTaskDestroy, (u8 *)(work));
}

