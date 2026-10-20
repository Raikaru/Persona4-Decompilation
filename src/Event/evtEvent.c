/* Original translation unit evtEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "scene_event_internal.h"
#include "include_asm.h"
extern s32 evtFindTask();

void kwlnTaskDestroyWithHierarchy(s32 task);
extern u32 kwlnTaskGetWork(void *task);
extern void (*jtbl_008873EC[])(void *);
void evtMemAccount(s32 slot, s32 byteCount);

s32 kwlnTaskGetTaskByName(void *name);
extern s32 D_0063C2F8[];
extern void kAssertFail(u8 *file, s32 line);
extern u8 D_0063C2C8[];
extern u8 D_00748340[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void chkmemAllocSiteTag(const void *file, s32 line);

extern void memset(void *dest, s32 value, s32 size);
extern s32 evtStart(s32, s32);
extern void evtSetId(u32, s32, s32, s32);
extern void evtRequestLoad(s32 task);
extern s32 evtLoaderIsIdle(s32);
extern void evtResetEventScene(s32, s32 *);
extern void evtUpdateSceneLights(s32 *);
extern void evtMessageWindowUpdate(s32 *);
void evtUpdateNodeWaitFlags(u8 *eventWork);
extern s32 taskRecordIsDone(s32);
extern s32 fadeStatus(void);
extern s32 evtScriptLoadIsReady(s32);
extern void evtRefreshNodeResources(u8 *);
extern void func_00440b68(void *);
extern u8 D_0063C2E0[];
s32 evtNodeTaskUpdate(u8 *task);
void evtLookupTask(void);



// Returns the work block of the event's task, or 0 when the event has no task yet [inferred].
// FUN_00285480
s32 evtGetEventTaskWork(u8 *event)
{
    EvtEventTask *task = (EvtEventTask *)event;
    s32 handle;

    if (event == 0) {
        kAssertFail(D_0063C2C8, 0x2E);
    }
    handle = task->eventTask;
    if (handle == 0) {
        return 0;
    }
    return (s32)kwlnTaskGetWork((void *)handle);
}

// Clears the event's wait flags once the thing each one waits on is done, then refreshes its resources when the busy state changes [inferred].
// FUN_002854E0
void evtUpdateNodeWaitFlags(u8 *eventWork)
{
    EvtEventWork *work = (EvtEventWork *)eventWork;
    s32 waitFlags;
    s32 busy;
    s32 firstWaitTask;
    s32 secondWaitTask;
    s32 thirdWaitTask;

    if (eventWork != NULL) {
        if ((work->waitFlags & 0x20) && (evtMessageWindowIsDone(work->messageWindow) == 1)) {
            work->waitFlags &= ~0x20;
        }
        if ((work->waitFlags & 0x200) && ((firstWaitTask = work->waitTask[0], firstWaitTask != 0) || (taskRecordIsDone(firstWaitTask) != 0))) {
            work->waitFlags &= ~0x200;
        }
        if ((work->waitFlags & 0x400) && ((secondWaitTask = work->waitTask[1], secondWaitTask != 0) || (taskRecordIsDone(secondWaitTask) != 0))) {
            work->waitFlags &= ~0x400;
        }
        if ((work->waitFlags & 0x800) && ((thirdWaitTask = work->waitTask[2], thirdWaitTask != 0) || (taskRecordIsDone(thirdWaitTask) != 0))) {
            work->waitFlags &= ~0x800;
        }
        if ((work->waitFlags & 0x2000) && (fadeStatus() != 1)) {
            work->waitFlags &= ~0x2000;
        }
        if ((work->waitFlags & 0x4000) && (kwlnTaskIsLinked(work->linkedTask) == 0)) {
            work->waitFlags &= ~0x4000;
            work->linkedTask = 0;
        }
        if ((work->waitFlags & 0x80000) && (evtScriptLoadIsReady(work->scriptLoad) != 0)) {
            work->waitFlags &= 0xFFF7FFFF;
        }
        waitFlags = work->waitFlags;
        if ((waitFlags & 1) || (waitFlags & 0x20) || (waitFlags & 0x200) || (waitFlags & 0x400) || (waitFlags & 0x800) || (waitFlags & 0x1000) || (waitFlags & 0x2000) || (waitFlags & 0x80000) || (waitFlags & 0x4000) || (waitFlags & 0x100000)) {
            busy = 1;
        } else {
            busy = 0;
        }
        if (work->busy != busy) {
            work->busy = busy;
            evtRefreshNodeResources(eventWork);
            func_00440b68(&D_0063C2E0);
        }
    }
}

// Steps the event's frame counter (unless it is busy); returns 1 once the counter reaches its limit [inferred].
// FUN_00285760
s32 evtStepEventFrame(u8 *eventWork)
{
    EvtEventWork *work = (EvtEventWork *)eventWork;
    s32 frame;
    s32 finished;

    frame = work->frame;
    finished = 0;
    if (work->busy == 0) {
        if (frame >= work->frameLimit) {
            finished = 1;
        } else {
            frame += 1;
        }
    }
    if (work->resetRequested != 0) {
        frame = work->resetFrame;
        work->resetRequested = 0;
    }
    work->frame = frame;
    return finished;
}

// Event task update: runs the event's wait checks, then steps its frame counter while it is not busy [inferred].
// FUN_002857C0
s32 evtNodeTaskUpdate(u8 *task)
{
    EvtEventTask *taskWork;
    EvtEventWork *eventWork;
    s32 eventTask;
    s32 state;
    s32 frame;
    s32 finished;

    taskWork = (EvtEventTask *)kwlnTaskGetWork(task);
    if (taskWork == NULL) {
        kAssertFail(D_0063C2C8, 0x2E);
    }
    eventTask = taskWork->eventTask;
    if (eventTask != 0) {
        kwlnTaskGetWork((void *)eventTask);
    }
    state = taskWork->state;
    switch (state) {
    case 0:
        taskWork->state = 5;
        /* fallthrough */
    case 5:
        if (evtLoaderIsIdle(taskWork->eventTask) != 0) {
            taskWork->state = 3;
        }
        goto done;
    case 3:
        taskWork->state = 4;
        /* fallthrough */
    case 4:
        eventWork = (EvtEventWork *)kwlnTaskGetWork((void *)taskWork->eventTask);
        eventWork->waitFlags &= ~1;
        frame = eventWork->frame;
        if (frame != eventWork->lastFrame) {
            evtResetEventScene(frame, (s32 *)eventWork);
        }
        eventWork->lastFrame = eventWork->frame;
        evtUpdateSceneLights((s32 *)eventWork);
        if ((eventWork->sceneSource != 0) && (evtMessageWindowIsOpen((u32 *)eventWork->messageWindow) != 0)) {
            evtMessageWindowUpdate((s32 *)eventWork->messageWindow);
        }
        evtUpdateNodeWaitFlags((u8 *)eventWork);
        if (eventWork->frame >= eventWork->frameLimit) {
            finished = 1;
        } else {
            evtStepEventFrame((u8 *)eventWork);
            finished = 0;
        }
        if (finished != 0) {
            taskWork->state = 6;
        }
        goto done;
    case 6:
        return -1;
    default:
    done:
        return 0;
    }
}
// Event task destroy: destroys the event's task hierarchy, frees its work block and releases the account [inferred].
// FUN_00285980
void evtNodeTaskDestroy(u8 *task) {
    EvtEventTask *taskWork;

    taskWork = (EvtEventTask *)kwlnTaskGetWork(task);
    kwlnTaskDestroyWithHierarchy(taskWork->eventTask);
    jtbl_008873EC[0](taskWork);
    evtMemAccount(0, -0x60);
}



// Creates the event task (0x60-byte work block) for the given event id and major/minor numbers, and returns the task handle [inferred].
// FUN_002859E0
s32 evtCreateEventTask(s32 majorId, s32 minorId)
{
    s32 task;
    EvtEventTask *taskWork;
    s32 eventTask;

    chkmemAllocSiteTag(&D_00748340, 0x52);
    taskWork = D_008873F4[0](1, 0x60, 0x40000);
    evtMemAccount(0, 0x60);
    memset(taskWork, 0, 0x60);
    // Task name D_0063C2F8 is "evtEvent" (retail string at VA 0x63C2F8), priority 0xF, with evtNodeTaskUpdate and evtNodeTaskDestroy.
    task = (s32)kwlnTaskCreate((const void *)(&D_0063C2F8), 0xF, 0, 0, evtNodeTaskUpdate, evtNodeTaskDestroy, (u8 *)(taskWork));
    eventTask = evtStart(0, 0);
    taskWork->eventTask = eventTask;
    evtSetId(eventTask, majorId, minorId, 0);
    evtRequestLoad(taskWork->eventTask);
    taskWork->state = 0;
    return task;
}
// Makes sure the event task exists, creating it through func_002853c0 when it is missing [inferred].
// FUN_00285AF0
void evtEnsureEventTask(void) {
    if (kwlnTaskGetTaskByName(D_0063C2F8) == 0) {
        evtLookupTask();
    }
}

// Returns the event's frame counter, or -1 when no event task exists.
// FUN_00285B30
s32 evtGetEventFrame(void) {
    s32 h = evtFindTask();

    if (h == 0) {
        return -1;
    }
    return ((EvtEventWork *)kwlnTaskGetWork((void *)h))->frame;
}

/* Retail's outer-loop count check uses `sltu $at,$s3,$v0; bnez $at`, while
   b210 reuses $v0 for the result (`sltu $v0,$s3,$v0; bnez $v0`). Exact
   executable body otherwise; fndiff offsets 68 and 72 are that register
   choice, offsets 120 and 124 are the D_0063C2C8 relocations, and offset
   308 is the retail-only tail padding. Comparison polarity, >=/< /> forms,
   u32 loads, and loop declaration reorder were ruled out. obj 308B/window
   320B, nd 2. Committed at nd 2. */
// Intent: Returns the requested ordinal kind-3 entry of the node list whose resource id is 0x384..0x386 (ordinal among those matches), or NULL when there is none [inferred]
// FUN_00285B80
u8 *evtFindSlotEntry(u8 *eventWork, s32 ordinal)
{
  /* measured: typed count/next conditions retain field addresses across the assert and lose MATCH; keep those raw reads. */
  /* The repeated masks and zero-product test are the existing matching control-flow shape, not simplified here. */
  s32 line;
  s32 count;
  s32 i;
  s32 matched;
  u8 *entryBase;
  u8 *p;
  u32 j;
  u16 flags;
  u8 *eventBase;
  int isTarget;
  s32 *countPtr;
  s32 kind;
  p = (void *) 0;
  countPtr = &((EvtEventWork *)eventWork)->nodeCount;
  matched = 0;
  i = *countPtr;
  eventBase = eventWork;
  entryBase = eventBase;
  count = i;
  i = 0;
  goto outer_check;
  process_entry:
  if (((u32) (*((s32 *) (entryBase + 0x48)))) > ((u32) i))
  {
    goto traverse;
  }

  p = (void *) 0;
  goto classify;
  traverse:
  p = (u8 *)((EvtEventWork *)eventBase)->nodeList;

  j = 0;
  goto inner_check;
  inner_body:
  if ((*((u8 **) (p + 0x90))) == ((void *) 0))
  {
    line = 0x18F;
    kAssertFail(D_0063C2C8, line);
  }

  p = (u8 *)((EvtNode *)p)->next;
  j += 1;
  inner_check:
  if (j < ((u32) i))
  {
    goto inner_body;
  }

  goto classify;
  classify:
  flags = ((EvtNode *)p)->flags;

  kind = ((s32) (flags & 0xFFC00)) >> 10;
  if ((((((((((((kind == ((unsigned char) 3)) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF)
  {
    if (((flags & 0x3FF) >= 0x384) && ((flags & 0x3FF) < 0x387))
    {
      isTarget = (((((((((matched == ordinal) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF;
      if ((((isTarget & 0xFFFF) & 0xFFFF) & 0xFFFF) != (((*((u8 **) (p + 0x90))) == ((void *) 0)) * 0))
      {
        return p;
      }
      matched += 1;
    }
  }
  i += 1;
  outer_check:
  if (i < count)
  {
    goto process_entry;
  }

  return (void *) 0;
}
