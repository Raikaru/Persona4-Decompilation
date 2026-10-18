/* Original translation unit evtMessage.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "scene_event_internal.h"

/* 0x34-byte object: close clears the full object; open initializes the five
   cached entries at +0x20. The update switch establishes each request field. */
typedef struct EvtMessageWindow {
    s32 active;
    s32 style;
    s32 windowId;
    s32 state;
    s32 recordId;
    s32 layoutId;
    s32 resultSlot;
    s32 result;
    s32 entries[5];
} EvtMessageWindow;
extern void itfMesWindowReleaseIfActive();
extern void memset();
extern s32 itfMesWindowInstall();
extern void itfMesWindowApplyStyle(s32 windowId, s32 style, s32 flags);
/* Source unit: src/Event/mt_evtMessage_00290a50.c (donor FUN_0039f2a0) */

extern void kAssertFail(u8 *file, s32 line);
extern u8 D_0063C820[];
extern s32 itfMesWindowEntryValue(s32 windowId, s32 entryIndex);

extern void itfMesWindowSetState();
extern void itfMesWindowRelease();
extern void itfMesWindowClear();
extern void itfMesWindowClearFlagBits();
extern void func_00276e70_typed(s32, u8);
extern void func_00277250_typed(s32);
extern void func_00277ad0_typed(s32, s32);
extern void func_002781e0_typed(s32, u32);
/* Source unit: src/Event/mt_evtMessage_00290e10.c (donor FUN_0039f710) */

extern u32 itfMesWindowRecordCount(int object);

/* measured: a named u8 boolean preserves retail's sltu materialisation;
   object 188B matches the 192-byte retail window with zero padding. */
// Opens the message window in this slot: installs it with the given style and marks the object active [inferred].
// FUN_00290880
s32 evtMessageWindowOpen(u8 *object, s32 style) {
    s32 windowId;
    u8 active;

    active = (((EvtMessageWindow *)object)->active != 0);
    if (active != 0) {
        kAssertFail(D_0063C820, 0x2D);
    }
    ((EvtMessageWindow *)object)->style = 0;
    windowId = itfMesWindowInstall(style);
    if (windowId < 0) {
        kAssertFail(D_0063C820, 0x33);
    }
    itfMesWindowApplyStyle(windowId, 0, 0);
    ((EvtMessageWindow *)object)->windowId = windowId;
    ((EvtMessageWindow *)object)->active = 1;
    memset(((EvtMessageWindow *)object)->entries, -1, 0x14);
    return windowId;
}
// Closes the message window: resets it when active, releases it and zeroes the object.
// FUN_00290940
void evtMessageWindowResetTyped(u32 *object);
void evtMessageWindowReset(int *object);

void evtMessageWindowClose(u32 *object)
{
  u32 *window;
  u8 active;

  window = object;

  active = ((EvtMessageWindow *)window)->active != 0;
  if (active) {
    evtMessageWindowResetTyped(object);
    itfMesWindowReleaseIfActive(((EvtMessageWindow *)window)->windowId);
    ((EvtMessageWindow *)window)->active = 0;
    memset(object, 0, 0x34);
  }
  return;
}
/* Source unit: src/Event/mt_evtMessage_002909a0.c */
// Returns 1 when the message window object is active (open), else 0.
// FUN_002909A0
u32 evtMessageWindowIsOpen(u32 *object)
{
    return ((EvtMessageWindow *)object)->active != 0;
}
// Requests a message display: resets any previous display, then records the style, record, layout and result slot and starts the update state machine [inferred].
// FUN_002909B0
/* Keep the word-array view of EvtMessageWindow here: typed member accesses
   changed MWCC alias/reload decisions and lost the retail match. */
void evtMessageWindowRequest(int *object, int style, int recordId, int layoutId, int resultSlot)
{
  if ((u8)(*object != 0)) {
    if (object[3] != 0) {
      evtMessageWindowReset(object);
    }
    object[3] = 1;
    object[1] = style;
    object[4] = recordId;
    object[5] = layoutId;
    object[6] = resultSlot;
    object[7] = -1;
  }
  return;
}




// Resets the window display: clears its contents and flags and returns it to the idle state.
// FUN_00290A50
/* Keep the word-array view of EvtMessageWindow here: typed member accesses
   changed MWCC alias/reload decisions and lost the retail match. */
void evtMessageWindowReset(int *object)
{
  int windowId;

  windowId = object[2];
  if ((u8)(*object != 0)) {
    if (object[3] != 0) {
      itfMesWindowSetState(windowId,0);
      itfMesWindowRelease(windowId);
      itfMesWindowClear(windowId,0);
      itfMesWindowClearFlagBits(windowId,0x800000);
      itfMesWindowClearFlagBits(windowId,0x100000);
      itfMesWindowSetState(windowId,1);
      object[3] = 0;
    }
  }
  return;
}



// Same reset as evtMessageWindowReset, through the typed window wrappers.
// FUN_00290B00
/* Keep the word-array view of EvtMessageWindow here: typed member accesses
   changed MWCC alias/reload decisions and lost the retail match. */
void evtMessageWindowResetTyped(u32 *object)
{
  int windowId;
  u8 active;

  active = *object != 0;
  if (active && (object[3] != 0)) {
    windowId = object[2];
    if (active && (object[3] != 0)) {
      func_00276e70_typed(windowId,0);
      func_00277250_typed(windowId);
      func_00277ad0_typed(windowId,0);
      func_002781e0_typed(windowId,0x800000);
      func_002781e0_typed(windowId,0x100000);
      func_00276e70_typed(windowId,1);
      object[3] = 0;
    }
  }
  return;
}

// Steps the message display state machine (idle, bind, wait, layout, wait for animation, reset), storing the result slot when the animation finishes [inferred].
// FUN_00290BC0
/* Keep the word-array view of EvtMessageWindow here: typed member accesses
   changed MWCC alias/reload decisions and lost the retail match. */
void evtMessageWindowUpdate(int *object)
{
  u32 active;
  int windowOrResultSlot;
  int windowState;
  u32 result;
  int recordId;

  active = *object != 0;
  if (active) {
    windowOrResultSlot = object[2];
    switch (object[3]) {
    case 0:
      break;
    case 1:
      recordId = object[4];
      if (recordId >= 0) {
        itfMesWindowSetStyle(object[2], object[1]);
        itfMesWindowSetFlagBits(object[2], 0x200000);
        itfMesWindowBindRecord(object[2], object[4], 0);
        itfMesWindowSetAnim(object[2], -1);
        object[3] = 2;
      } else {
        object[3] = 3;
      }
      break;
    case 2:
      windowState = itfMesWindowState(windowOrResultSlot);
      if (windowState < 0) {
        object[3] = 3;
      }
      break;
    case 3:
      if (object[5] >= 0) {
        itfMesWindowSetCursor(windowOrResultSlot, 0);
        itfMesWindowLayout(windowOrResultSlot, object[5]);
        object[3] = 4;
      } else {
        object[3] = 5;
      }
      break;
    case 4:
      windowState = itfMesWindowGetAnim(windowOrResultSlot);
      if (windowState < 0) {
        result = func_00278260(windowOrResultSlot);
        windowOrResultSlot = object[6];
        if ((windowOrResultSlot >= 0) && (windowOrResultSlot < 10)) {
          evtResultSet(windowOrResultSlot, result);
        }
        object[7] = (int)result;
        object[3] = 5;
      }
      break;
    case 5:
      if (active && (object[3] != 0)) {
        itfMesWindowSetState(windowOrResultSlot, 0);
        itfMesWindowRelease(windowOrResultSlot);
        itfMesWindowClear(windowOrResultSlot, 0);
        itfMesWindowClearFlagBits(windowOrResultSlot, 0x800000);
        itfMesWindowClearFlagBits(windowOrResultSlot, 0x100000);
        itfMesWindowSetState(windowOrResultSlot, 1);
        object[3] = 0;
      }
      break;
    }
  }
  return;
}


/* Source unit: src/Event/mt_evtMessage_00290de0.c (donor FUN_0039f6e0) */


// Returns 1 when no message is open, or when the open message's state machine is idle (the message is done).
// FUN_00290DE0
s32 evtMessageWindowIsDone(void *object)
{
  int *windowWords = object;
  if ((u8)(((EvtMessageWindow *)windowWords)->active != 0)) goto nonzero;
  return 1;

nonzero:
  return ((EvtMessageWindow *)windowWords)->state == 0;
}



// Returns the open window's record count, or 0 when no message is open.
// FUN_00290E10
u32 evtMessageWindowRecordCount(int *object)
{
  if ((u8)(((EvtMessageWindow *)object)->active != 0)) goto nonzero;
  return 0;

nonzero:
  return itfMesWindowRecordCount(((EvtMessageWindow *)object)->windowId);
}

// Returns the window's entry value for the given index; asserts the window is open.
// FUN_00290E50
s32 evtMessageWindowEntryValue(u8 *object, s32 entryIndex)
{
    if (!(u8)(((EvtMessageWindow *)object)->active != 0)) {
        kAssertFail(D_0063C820, 0x122);
    }
    return itfMesWindowEntryValue(((EvtMessageWindow *)object)->windowId, entryIndex);
}
