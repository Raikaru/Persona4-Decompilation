#include "sdktask.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void *memset(void *dst, s32 value, s32 size);
extern u8 D_0063E8E0[];
extern u8 D_0063E918[];
extern void yTimeLimitReset(void);
extern void hsndQueueSound(s32 id, s32 unused);
extern s32 sdkSpriteRequestLoad(u8 *name);
extern s32 hMaestroDecodeIsReady(s32 handle);
extern s32 kwlnTaskGetState(s32 handle);
extern s32 yTimeLimitTaskUpdate(u8 *task);
extern void yTimeLimitTaskDestroy(u8 *task);
extern u8 D_0063E900[];
extern u8 D_0063E8F0[];
extern s32 D_00764630;
extern s32 timeLimitEntryUpdate(u8 *task);

/* timeLimitTaskCreate allocates and clears 0x18 bytes. The entry task owns
 * the sprite request and waits for the child display task before exiting. */
typedef struct TimeLimitEntryWork {
    s32 state;
    s32 unk04;
    s32 sprite;
    s32 unk0C;
    s32 childTask;
    s32 unk14;
} TimeLimitEntryWork;

// FUN_002A2420
/* Case values decoded from jtbl_007486C0 with tools/jtbl.py: a 0/1/2/3/5/6
   state machine with case 4 and the out-of-range default both falling to the
   shared `return 0`, declared in that object order.
   Two prototypes had to be widened for this: kwlnTaskCreateChild's `init` callback
   returns s32 (retail's func_002a2420 leaves 0 or -1 in $v0 and the window
   manager takes it), and yTimeLimitTaskUpdate is one of those callbacks. */
s32 timeLimitEntryUpdate(u8 *task) {
    TimeLimitEntryWork *work;
    u8 *childWork;
    s32 childTask;

    work = (TimeLimitEntryWork *)((SdkTask *)task)->work;
    switch ((u32)work->state) {
    case 0:
        yTimeLimitReset();
        work->state = 1;
        hsndQueueSound(0x14, 0x1E);
        break;
    case 1:
        work->sprite = sdkSpriteRequestLoad(D_0063E900);
        work->state = 2;
        break;
    case 2:
        if (hMaestroDecodeIsReady(work->sprite) != 1) {
            break;
        }
        D_00764630 = work->sprite;
        chkmemAllocSiteTag(D_0063E8E0, 0xA5E);
        childWork = D_008873F4[0](1, 0x1C6C, 0x40000);
        if (childWork == NULL) {
            childTask = 0;
        } else {
            memset(childWork, 0, 0x1C6C);
            childTask = (s32)kwlnTaskCreateChild((void *)(task), (const void *)(D_0063E8F0), 0xF, 0, 0, yTimeLimitTaskUpdate, yTimeLimitTaskDestroy, (u8 *)(childWork));
        }
        work->childTask = childTask;
        work->state = 3;
        break;
    case 3:
        work->unk0C = 0;
        work->state = 5;
        break;
    case 5:
        if (kwlnTaskGetState(work->childTask) != 3) {
            if (kwlnTaskGetState(work->childTask) != 0) {
                break;
            }
        }
        work->childTask = 0;
        work->state = 6;
        break;
    case 6:
        D_00764630 = 0;
        return -1;
    case 4:
        break;
    }
    return 0;
}

/* Release any loaded time-limit sprite and free the entry task work. */
// FUN_002A2600
void timeLimitEntryDestroy(u8 *task)
{
    TimeLimitEntryWork *work = (TimeLimitEntryWork *)((SdkTask *)task)->work;
    if (work->sprite != 0) {
        sdkSpriteRelease(work->sprite);
        work->sprite = 0;
    }
    jtbl_008873EC[0](work);
}

// Intent: Create the time limit task as a child of the given parent, with its update and destroy callbacks [inferred]
// FUN_002A2650
s32 timeLimitTaskCreate(u8 *parent)
{
    u8 *work;

    chkmemAllocSiteTag(D_0063E8E0, 0xB03);
    work = D_008873F4[0](1, 0x18, 0x40000);
    if (work == NULL) {
        return 0;
    }
    memset(work, 0, 0x18);
    return (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0063E918), 0xF, 0, 0, timeLimitEntryUpdate, timeLimitEntryDestroy, (u8 *)(work));
}

