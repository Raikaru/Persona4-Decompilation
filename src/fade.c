#include "include_asm.h"
#include "sdk_task_registration.h"
/* Source unit: src/fade_00122430.c */
#include "type.h"
#include "calendar_fade_internal.h"

extern char D_005E5068[];
extern char D_005E5078[];
extern char iGpffff9c60;
extern u8 *iGpffffb1cc;
extern void *(*D_008873F4[])(size_t, size_t, u32);

void chkmemAllocSiteTag();

s32 fadeTaskStep(u8 *unusedTask);
void fadeTaskDestroy(u8 *unusedTask);
s32 fadeQueueCallback(u8 *unusedTask);

extern char D_005E5090[];
extern char iGpffffb1d8;
extern char iGpffffb1d4;
extern char iGpffffb1d0;

void kAssertFailAt(const void *msg, const void *file, u32 line);

extern char D_005E50B0[];



// FUN_00122430
/* Allocate the fade controller and attach its update and draw tasks to parentTask. */
s32 fadeCreateController(s32 parentTask)
{
    s32 fadeTask;
    CalendarFade *work;

    chkmemAllocSiteTag(&iGpffff9c60, 0x14D);
    work = D_008873F4[0](1, 0x20, 0x40000);
    if (work == NULL) {
        return 0;
    }
    iGpffffb1cc = (u8 *)work;
    fadeTask = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005E5068), 0x98, 0, 0, fadeTaskStep, fadeTaskDestroy, (u8 *)(work));
    work->mode = 1;
    (s32)kwlnTaskCreateChild((void *)(fadeTask), (const void *)(D_005E5078), 0x99, 0, 0, fadeQueueCallback, 0, (u8 *)(NULL));
    return fadeTask;
}



// FUN_00122520
/* Begin an idle fade; mode 4 can also request its special child while state 3 is active. */
s32 fadeBeginTransition(s32 mode, s32 duration)
{
    CalendarFade *work;

    work = (CalendarFade *)iGpffffb1cc;
    if (work == NULL) {
        return 0;
    }
    if (mode == 4 && work->state == 3) {
        work->mode = mode;
        work->specialRequested = 1;
        iGpffffb1d8 = 0;
        iGpffffb1d4 = 0;
        iGpffffb1d0 = 0;
        goto done;
    }
    if (work->state == 0) {
        if (mode == 0) {
            kAssertFailAt(D_005E5090, &iGpffff9c60, 0x17D);
            if (work->mode == 0) {
                work->mode = 1;
            }
        } else {
            work->mode = mode;
        }
        if (duration > 0) {
            work->duration = duration;
        } else {
            work->duration = 0x1E;
        }
        work->state = 1;
        work->counter = 0;
    } else {
        return 0;
    }
    work->specialRequested = 1;
    iGpffffb1d8 = 0;
    iGpffffb1d4 = 0;
    iGpffffb1d0 = 0;
done:
    return 1;
}


// FUN_00122640
/* Start the return transition from state 3, defaulting nonpositive durations to 30 frames. */
s32 fadeBeginReturnTransition(s32 mode, s32 duration)
{
    CalendarFade *work;

    work = (CalendarFade *)iGpffffb1cc;
    if (work == NULL) {
        return 0;
    }
    if (work->state == 3) {
        if (mode == 0) {
            if (work->mode == 0) {
                kAssertFailAt(D_005E50B0, &iGpffff9c60, 0x19E);
                work->mode = 1;
            }
        } else {
            work->mode = mode;
        }
        if (duration > 0) {
            work->duration = duration;
            work->counter = duration;
        } else {
            work->duration = 0x1E;
            work->counter = 0x1E;
        }
        work->state = 4;
    } else {
        return 0;
    }
    return 1;
}
