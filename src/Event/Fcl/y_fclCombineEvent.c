#include "evt_internal.h"
/* Original translation unit y_fclCombineEvent.c (from __FILE__ assert strings). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdktask.h"

/* Scene work is allocated as 0x14 bytes by fclCombineEventSceneCreate. */
typedef struct FclCombineEventScene {
    s8 state;
    u8 pad01[3];
    s32 eventId;
    s32 eventType;
    s32 eventTask;
    s32 readerTask;
} FclCombineEventScene;

typedef struct FclCombineEventWork {
    s8 state;
    u8 pad01[0xF];
    s8 mode;
    u8 pad11[3];
} FclCombineEventWork;
extern void sdkSndFadeOutChannelFrames();
extern void (*jtbl_008873EC[])(void *ptr);
extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern u8 D_0064A400[];
extern u8 D_0064A420[];
extern u8 D_0064A440[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern s32 fclCombineEventTaskUpdate(u8 *task);
extern void fclCombineEventTaskDestroy(u8 *task);
extern s32 fclCombineEventGate(u8 *task);
extern s32 fclCombineEventSceneUpdate(u8 *task);
extern s32 evtGetEventFrame(void);
extern void datSetFlag(s32 flagId, s32 enabled);
extern u16 D_008C024E[];
extern s32 evtPMFileReaderCreate(s32 eventId, s32 variantId, s32 value, s32 useAllocatedTables);
extern s32 evtPMFileReaderIsDone(s32 task);
extern s32 evtPMFileReaderGetFirstEntry(s32 task, s32 *firstValue, s32 *secondValue, s32 *byteValue, s32 *halfwordValue);
extern void fieldSceneLoad(s32 fieldId, s32 roomId);
extern void fieldSceneRequestRoom(s64 roomId);
extern void fieldSceneRequestSecondaryRoom(s64 roomId);
extern s32 fieldSceneLoadStep(void);
extern s32 evtCreateEventTask(s32 a, s32 b, s32 c); /* lint: allow H011 -- caller stores the returned handle; the definition takes two arguments and ignores the third */
extern s32 kwlnTaskIsLinked(s32 target);
extern void kwlnTaskDestroyWithHierarchy(s32 task);
extern void fieldSceneUnload(void);


/* Register the combine-event controller and store its signed mode byte. */
// FUN_0033DC90
void fclCombineEventTaskCreate(u8 *parentTask, s8 mode)
{
    FclCombineEventWork *work;

    chkmemAllocSiteTag(D_0064A400, 0xAF);
    work = D_008873F4[0](1, 0x14, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0064A420), 0xF, 0, 0, fclCombineEventTaskUpdate, fclCombineEventTaskDestroy, (u8 *)(work));
    work->state = 0;
    work->mode = mode;
}


// Fcl combine event gate: returns -1 and sets the event's flag when a blocking flag or map range applies, else 0.
// FUN_0033DD40
s32 fclCombineEventGate(u8 *task)
{
    s32 *flagId;

    flagId = (s32 *)((SdkTask *)task)->work;
    if (evtGetEventFrame() >= 4) {
        if ((evtGetEventFrame() >= 0x11D) && (evtGetEventFrame() < 0x12C)) {
            return 0;
        }
        if ((evtGetEventFrame() >= 0x1A5) && (evtGetEventFrame() < 0x1BD)) {
            return 0;
        }
        if (D_008C024E[0] & 0x800) {
            datSetFlag(*flagId, 1);
            return -1;
        }
        if (D_008C024E[0] & 0x40) {
            datSetFlag(*flagId, 1);
            return -1;
        }
    }
    return 0;
}


// Fcl combine event destroy: stops sound channel 2 and frees the task's work buffer.
// FUN_0033DE40
void fclCombineEventDestroy(u8 *task) {
    sdkSndFadeOutChannelFrames(2, 0, 0);
    jtbl_008873EC[0](((SdkTask *)task)->work);
}


/* Register a gate whose four-byte work allocation holds the flag to set. */
// FUN_0033DE90
void fclCombineEventGateCreate(u8 *parentTask, s32 flagId)
{
    s32 *work;

    chkmemAllocSiteTag(D_0064A400, 0x10A);
    work = D_008873F4[0](1, 4, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0064A440), 0xF, 0, 0, fclCombineEventGate, fclCombineEventDestroy, (u8 *)(work));
    *work = flagId;
}


/* Resolve the event's map entry, load its room, run the event, then release it.
   Event type 10 owns the scene load/unload; other types reuse the current scene. */
// FUN_0033DF40
s32 fclCombineEventSceneUpdate(u8 *task)
{
    s32 sceneId;
    s32 sceneVariant;
    s32 roomId;
    s32 entryExtra;
    s32 readerTask;
    s8 state;
    FclCombineEventScene *work;

    work = (FclCombineEventScene *)((SdkTask *)task)->work;
    state = work->state;
    switch (state) {
    case 0:
        work->readerTask = evtPMFileReaderCreate(work->eventId, work->eventType, 0, 0);
        work->state = (s8)(work->state + 1);
        /* fallthrough */
    case 1:
        if ((evtPMFileReaderIsDone(work->readerTask) != 0) && (evtPMFileReaderGetFirstEntry(work->readerTask, &sceneId, &sceneVariant, &roomId, &entryExtra) == 1)) {
            if (work->eventType == 0xA) {
                fieldSceneLoad(sceneId, sceneVariant);
            }
            fieldSceneRequestRoom((s16)roomId);
            fieldSceneRequestSecondaryRoom(3);
            work->state = (s8)(work->state + 1);
        }
        goto out;
    case 2:
        if (fieldSceneLoadStep() != 0) {
            work->eventTask = evtCreateEventTask(work->eventId, work->eventType, 0);
            work->state = (s8)(work->state + 1);
        case 3:
            if (kwlnTaskIsLinked(work->eventTask) != 1) {
                readerTask = work->readerTask;
                if (readerTask != 0) {
                    kwlnTaskDestroyWithHierarchy(readerTask);
                }
                if (work->eventType == 0xA) {
                    fieldSceneUnload();
                }
                work->state = (s8)(work->state + 1);
            }
        }
        goto out;
    case 4:
    case 5:
        work->state = (s8)(state + 1);
        goto out;
    case 6:
        return -1;
    default:
    out:
        return 0;
    }
}


// FUN_0033E0F0
void fclCombineEventSceneDestroy(u8 *task) {
    jtbl_008873EC[0](((SdkTask *)task)->work);
}


/* Allocate the scene controller with its event identifier and event type. */
// FUN_0033E120
void fclCombineEventSceneCreate(u8 *parentTask, s32 eventId, s32 eventType)
{
    FclCombineEventScene *work;

    chkmemAllocSiteTag(D_0064A400, 0x192);
    work = D_008873F4[0](1, 0x14, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0064A440), 0xF, 0, 0, fclCombineEventSceneUpdate, fclCombineEventSceneDestroy, (u8 *)(work));
    work->eventId = eventId;
    work->eventType = eventType;
    work->state = 0;
}
