/* Original translation unit evtEvent.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
extern s32 evtFindTask();

void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern u32 kwlnTaskGetWork(void *task);
extern void (*jtbl_008873EC[])(void *);
void evtMemAccount(s32 arg0, s32 arg1);

s32 kwlnTaskGetTaskByName(void *arg0);
extern s32 D_0063C2F8[];
extern void kAssertFail(u8 *file, s32 line);
extern u8 D_0063C2C8[];
extern u8 D_00748340[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void chkmemAllocSiteTag(const void *file, s32 line);

extern void memset(void *dest, s32 value, s32 size);
extern s32 evtStart(s32, s32);
extern void evtSetId(u32, s32, s32, s32);
extern void evtMarkTaskStarted(s32 task);
extern s32 evtTaskIsMarked(s32);
extern void evtResetEventScene(s32, s32 *);
extern void evtUpdateSceneLights(s32 *);
extern void evtMessageWindowUpdate(s32 *);
void evtUpdateNodeWaitFlags(u8 *arg0);
extern s32 taskRecordIsDone(s32);
extern s32 fadeStatus(void);
extern s32 evtScriptLoadIsReady(s32);
extern void evtRefreshNodeResources(u8 *);
extern void func_00440b68(void *);
extern u8 D_0063C2E0[];
s32 evtNodeTaskUpdate(u8 *task);
void func_002853c0(void);



// Returns the work block of the event's task, or 0 when the event has no task yet [inferred].
// FUN_00285480
s32 evtGetEventTaskWork(u8 *arg0)
{
    s32 handle;

    if (arg0 == 0) {
        kAssertFail(D_0063C2C8, 0x2E);
    }
    handle = *(s32 *)(arg0 + 0xC);
    if (handle == 0) {
        return 0;
    }
    return (s32)kwlnTaskGetWork((void *)handle);
}

// Clears the event's wait flags once the thing each one waits on is done, then refreshes its resources when the busy state changes [inferred].
// FUN_002854E0
void evtUpdateNodeWaitFlags(u8 *arg0)
{
    s32 temp_4_4;
    s32 var_4;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;

    if (arg0 != NULL) {
        if ((*(s32 *)(arg0 + 0) & 0x20) && (evtMessageWindowIsDone(arg0 + 0x678) == 1)) {
            *(s32 *)(arg0 + 0) &= ~0x20;
        }
        if ((*(s32 *)(arg0 + 0) & 0x200) && ((temp_4 = *(s32 *)(arg0 + 0x6C4), temp_4 != 0) || (taskRecordIsDone(temp_4) != 0))) {
            *(s32 *)(arg0 + 0) &= ~0x200;
        }
        if ((*(s32 *)(arg0 + 0) & 0x400) && ((temp_4_2 = *(s32 *)(arg0 + 0x6C8), temp_4_2 != 0) || (taskRecordIsDone(temp_4_2) != 0))) {
            *(s32 *)(arg0 + 0) &= ~0x400;
        }
        if ((*(s32 *)(arg0 + 0) & 0x800) && ((temp_4_3 = *(s32 *)(arg0 + 0x6CC), temp_4_3 != 0) || (taskRecordIsDone(temp_4_3) != 0))) {
            *(s32 *)(arg0 + 0) &= ~0x800;
        }
        if ((*(s32 *)(arg0 + 0) & 0x2000) && (fadeStatus() != 1)) {
            *(s32 *)(arg0 + 0) &= ~0x2000;
        }
        if ((*(s32 *)(arg0 + 0) & 0x4000) && (kwlnTaskIsLinked(*(s32 *)(arg0 + 0x75C)) == 0)) {
            *(s32 *)(arg0 + 0) &= ~0x4000;
            *(s32 *)(arg0 + 0x75C) = 0;
        }
        if ((*(s32 *)(arg0 + 0) & 0x80000) && (evtScriptLoadIsReady(*(s32 *)(arg0 + 0x760)) != 0)) {
            *(s32 *)(arg0 + 0) &= 0xFFF7FFFF;
        }
        temp_4_4 = *(s32 *)(arg0 + 0);
        if ((temp_4_4 & 1) || (temp_4_4 & 0x20) || (temp_4_4 & 0x200) || (temp_4_4 & 0x400) || (temp_4_4 & 0x800) || (temp_4_4 & 0x1000) || (temp_4_4 & 0x2000) || (temp_4_4 & 0x80000) || (temp_4_4 & 0x4000) || (temp_4_4 & 0x100000)) {
            var_4 = 1;
        } else {
            var_4 = 0;
        }
        if (*(s32 *)(arg0 + 0x5D4) != var_4) {
            *(s32 *)(arg0 + 0x5D4) = var_4;
            evtRefreshNodeResources(arg0);
            func_00440b68(&D_0063C2E0);
        }
    }
}

// Steps the event's frame counter (unless it is busy); returns 1 once the counter reaches its limit [inferred].
// FUN_00285760
s32 evtStepEventFrame(u8 *arg0)
{
    s32 var_5;
    s32 var_2;

    var_5 = *(s32 *)(arg0 + 0x14);
    var_2 = 0;
    if (*(s32 *)(arg0 + 0x5D4) == 0) {
        if (var_5 >= *(s32 *)(arg0 + 0x10)) {
            var_2 = 1;
        } else {
            var_5 += 1;
        }
    }
    if (*(s32 *)(arg0 + 0x1C) != 0) {
        var_5 = *(s32 *)(arg0 + 0x20);
        *(s32 *)(arg0 + 0x1C) = 0;
    }
    *(s32 *)(arg0 + 0x14) = var_5;
    return var_2;
}

// Event task update: runs the event's wait checks, then steps its frame counter while it is not busy [inferred].
// FUN_002857C0
s32 evtNodeTaskUpdate(u8 *task)
{
    u8 *temp_2;
    u8 *temp_2_2;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 var_2;

    temp_2 = (u8 *)kwlnTaskGetWork(task);
    if (temp_2 == NULL) {
        kAssertFail(D_0063C2C8, 0x2E);
    }
    temp_4 = *(s32 *)(temp_2 + 0xC);
    if (temp_4 != 0) {
        kwlnTaskGetWork((void *)temp_4);
    }
    temp_4_2 = *(s32 *)(temp_2 + 0);
    switch (temp_4_2) {
    case 0:
        *(s32 *)(temp_2 + 0) = 5;
        /* fallthrough */
    case 5:
        if (evtTaskIsMarked(*(s32 *)(temp_2 + 0xC)) != 0) {
            *(s32 *)(temp_2 + 0) = 3;
        }
        goto done;
    case 3:
        *(s32 *)(temp_2 + 0) = 4;
        /* fallthrough */
    case 4:
        temp_2_2 = (u8 *)kwlnTaskGetWork((void *)*(s32 *)(temp_2 + 0xC));
        *(s32 *)(temp_2_2 + 0) &= ~1;
        temp_4_3 = *(s32 *)(temp_2_2 + 0x14);
        if (temp_4_3 != *(s32 *)(temp_2_2 + 0x18)) {
            evtResetEventScene(temp_4_3, (s32 *)temp_2_2);
        }
        *(s32 *)(temp_2_2 + 0x18) = *(s32 *)(temp_2_2 + 0x14);
        evtUpdateSceneLights((s32 *)temp_2_2);
        if ((*(s32 *)(temp_2_2 + 4) != 0) && (evtMessageWindowIsOpen((u32 *)(temp_2_2 + 0x678)) != 0)) {
            evtMessageWindowUpdate((s32 *)(temp_2_2 + 0x678));
        }
        evtUpdateNodeWaitFlags(temp_2_2);
        if (*(s32 *)(temp_2_2 + 0x14) >= *(s32 *)(temp_2_2 + 0x10)) {
            var_2 = 1;
        } else {
            evtStepEventFrame(temp_2_2);
            var_2 = 0;
        }
        if (var_2 != 0) {
            *(s32 *)(temp_2 + 0) = 6;
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
    s32 *temp_2;

    temp_2 = (s32 *)kwlnTaskGetWork(task);
    kwlnTaskDestroyWithHierarchy(*(s32 *)((u8 *)temp_2 + 0xC));
    jtbl_008873EC[0](temp_2);
    evtMemAccount(0, -0x60);
}



// Creates the event task (0x60-byte work block) for the given event id and major/minor numbers, and returns the task handle [inferred].
// FUN_002859E0
s32 evtCreateEventTask(s32 arg0, s32 arg1)
{
    s32 temp_17;
    u8 *temp_16;
    s32 temp_2;

    chkmemAllocSiteTag(&D_00748340, 0x52);
    temp_16 = D_008873F4[0](1, 0x60, 0x40000);
    evtMemAccount(0, 0x60);
    memset(temp_16, 0, 0x60);
    temp_17 = (s32)kwlnTaskCreate((const void *)(&D_0063C2F8), 0xF, 0, 0, evtNodeTaskUpdate, evtNodeTaskDestroy, (u8 *)(temp_16));
    temp_2 = evtStart(0, 0);
    *(s32 *)(temp_16 + 0xC) = temp_2;
    evtSetId(temp_2, arg0, arg1, 0);
    evtMarkTaskStarted(*(s32 *)(temp_16 + 0xC));
    *(s32 *)(temp_16 + 0) = 0;
    return temp_17;
}
// Makes sure the event task exists, creating it through func_002853c0 when it is missing [inferred].
// FUN_00285AF0
void evtEnsureEventTask(void) {
    if (kwlnTaskGetTaskByName(D_0063C2F8) == 0) {
        func_002853c0();
    }
}

// Returns the event's frame counter, or -1 when no event task exists.
// FUN_00285B30
s32 evtGetEventFrame(void) {
    s32 h = evtFindTask();

    if (h == 0) {
        return -1;
    }
    return *(s32 *)((u8 *)kwlnTaskGetWork((void *)h) + 0x14);
}

/* Retail's outer-loop count check uses `sltu $at,$s3,$v0; bnez $at`, while
   b210 reuses $v0 for the result (`sltu $v0,$s3,$v0; bnez $v0`). Exact
   executable body otherwise; fndiff offsets 68 and 72 are that register
   choice, offsets 120 and 124 are the D_0063C2C8 relocations, and offset
   308 is the retail-only tail padding. Comparison polarity, >=/< /> forms,
   u32 loads, and loop declaration reorder were ruled out. obj 308B/window
   320B, nd 2. Committed at nd 2. */
// Intent: Returns the arg1-th kind-3 entry of the node list whose resource id is 0x384..0x386 (ordinal among those matches), or NULL when there is none [inferred]
// FUN_00285B80
u8 *evtFindSlotEntry(u8 *arg0, s32 arg1)
{
  s32 line;
  s32 count;
  s32 i;
  s32 matched;
  u8 *entry_base;
  u8 *p;
  u32 j;
  u16 flags;
  u8 *arg_base;
  int is_target;
  s32 *count_ptr;
  s32 kind;
  p = (void *) 0;
  count_ptr = (s32 *) (arg0 + 0x48);
  matched = 0;
  i = *count_ptr;
  arg_base = arg0;
  entry_base = arg_base;
  count = i;
  i = 0;
  goto outer_check;
  process_entry:
  if (((u32) (*((s32 *) (entry_base + 0x48)))) > ((u32) i))
  {
    goto traverse;
  }

  p = (void *) 0;
  goto classify;
  traverse:
  p = *(u8 **) (arg_base + 0x4C);

  j = 0;
  goto inner_check;
  inner_body:
  if ((*((u8 **) (p + 0x90))) == ((void *) 0))
  {
    line = 0x18F;
    kAssertFail(D_0063C2C8, line);
  }

  p = *((u8 **) (p + 0x90));
  j += 1;
  inner_check:
  if (j < ((u32) i))
  {
    goto inner_body;
  }

  goto classify;
  classify:
  flags = *((u16 *) (p + 0xC));

  kind = ((s32) (flags & 0xFFC00)) >> 10;
  if ((((((((((((kind == ((unsigned char) 3)) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF) & 0xFF)
  {
    if (((flags & 0x3FF) >= 0x384) && ((flags & 0x3FF) < 0x387))
    {
      is_target = (((((((((matched == arg1) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF;
      if ((((is_target & 0xFFFF) & 0xFFFF) & 0xFFFF) != (((*((u8 **) (p + 0x90))) == ((void *) 0)) * 0))
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
