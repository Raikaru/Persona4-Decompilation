/* Original translation unit evtMessage.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "scene_event_internal.h"
extern void itfMesWindowReleaseIfActive();
extern void memset();
extern s32 itfMesWindowInstall();
extern void itfMesWindowApplyStyle(s32 arg0, s32 arg1, s32 arg2);
/* Source unit: src/Event/mt_evtMessage_00290a50.c (donor FUN_0039f2a0) */

extern void kAssertFail(u8 *file, s32 line);
extern u8 D_0063C820[];
extern s32 itfMesWindowEntryValue(s32 arg0, s32 arg1);

extern void itfMesWindowSetState();
extern void itfMesWindowRelease();
extern void itfMesWindowClear();
extern void itfMesWindowClearFlagBits();
extern void func_00276e70_typed(s32, u8);
extern void func_00277250_typed(s32);
extern void func_00277ad0_typed(s32, s32);
extern void func_002781e0_typed(s32, u32);
/* Source unit: src/Event/mt_evtMessage_00290e10.c (donor FUN_0039f710) */

extern u32 itfMesWindowRecordCount(int param_1);

/* measured: a named u8 boolean preserves retail's sltu materialisation;
   object 188B matches the 192-byte retail window with zero padding. */
// Opens the message window in this slot: installs it with the given style and marks the object active [inferred].
// FUN_00290880
s32 evtMessageWindowOpen(u8 *arg0, s32 arg1) {
    s32 temp_2;
    u8 active;

    active = (*(s32 *)arg0 != 0);
    if (active != 0) {
        kAssertFail(D_0063C820, 0x2D);
    }
    *(s32 *)(arg0 + 4) = 0;
    temp_2 = itfMesWindowInstall(arg1);
    if (temp_2 < 0) {
        kAssertFail(D_0063C820, 0x33);
    }
    itfMesWindowApplyStyle(temp_2, 0, 0);
    *(s32 *)(arg0 + 8) = temp_2;
    *(s32 *)arg0 = 1;
    memset(arg0 + 0x20, -1, 0x14);
    return temp_2;
}
// Closes the message window: resets it when active, releases it and zeroes the object.
// FUN_00290940
void evtMessageWindowResetTyped(u32 *param_1);
void evtMessageWindowReset(int *param_1);

void evtMessageWindowClose(u32 *param_1)
{
  u32 *piVar1;
  u8 bVar1;

  piVar1 = param_1;

  bVar1 = *piVar1 != 0;
  if (bVar1) {
    evtMessageWindowResetTyped(param_1);
    itfMesWindowReleaseIfActive(piVar1[2]);
    *piVar1 = 0;
    memset(param_1, 0, 0x34);
  }
  return;
}
/* Source unit: src/Event/mt_evtMessage_002909a0.c */
// Returns 1 when the message window object is active (open), else 0.
// FUN_002909A0
u32 evtMessageWindowIsOpen(u32 *object)
{
    return *object != 0;
}
// Requests a message display: resets any previous display, then records the style, record, layout and result slot and starts the update state machine [inferred].
// FUN_002909B0
void evtMessageWindowRequest(int *param_1, int a2, int a3, int a4, int a5)
{
  if ((u8)(*param_1 != 0)) {
    if (param_1[3] != 0) {
      evtMessageWindowReset(param_1);
    }
    param_1[3] = 1;
    param_1[1] = a2;
    param_1[4] = a3;
    param_1[5] = a4;
    param_1[6] = a5;
    param_1[7] = -1;
  }
  return;
}




// Resets the window display: clears its contents and flags and returns it to the idle state.
// FUN_00290A50
void evtMessageWindowReset(int *param_1)
{
  int iVar1;

  iVar1 = param_1[2];
  if ((u8)(*param_1 != 0)) {
    if (param_1[3] != 0) {
      itfMesWindowSetState(iVar1,0);
      itfMesWindowRelease(iVar1);
      itfMesWindowClear(iVar1,0);
      itfMesWindowClearFlagBits(iVar1,0x800000);
      itfMesWindowClearFlagBits(iVar1,0x100000);
      itfMesWindowSetState(iVar1,1);
      param_1[3] = 0;
    }
  }
  return;
}



// Same reset as evtMessageWindowReset, through the typed window wrappers.
// FUN_00290B00
void evtMessageWindowResetTyped(u32 *param_1)
{
  int iVar1;
  u8 bVar1;

  bVar1 = *param_1 != 0;
  if (bVar1 && (param_1[3] != 0)) {
    iVar1 = param_1[2];
    if (bVar1 && (param_1[3] != 0)) {
      func_00276e70_typed(iVar1,0);
      func_00277250_typed(iVar1);
      func_00277ad0_typed(iVar1,0);
      func_002781e0_typed(iVar1,0x800000);
      func_002781e0_typed(iVar1,0x100000);
      func_00276e70_typed(iVar1,1);
      param_1[3] = 0;
    }
  }
  return;
}

// Steps the message display state machine (idle, bind, wait, layout, wait for animation, reset), storing the result slot when the animation finishes [inferred].
// FUN_00290BC0
void evtMessageWindowUpdate(int *param_1)
{
  u32 bVar0;
  int iVar2;
  int lVar3;
  u32 uVar4;
  int iVar5;

  bVar0 = *param_1 != 0;
  if (bVar0) {
    iVar2 = param_1[2];
    switch (param_1[3]) {
    case 0:
      break;
    case 1:
      iVar5 = param_1[4];
      if (iVar5 >= 0) {
        itfMesWindowSetStyle(param_1[2], param_1[1]);
        itfMesWindowSetFlagBits(param_1[2], 0x200000);
        itfMesWindowBindRecord(param_1[2], param_1[4], 0);
        itfMesWindowSetAnim(param_1[2], -1);
        param_1[3] = 2;
      } else {
        param_1[3] = 3;
      }
      break;
    case 2:
      lVar3 = itfMesWindowState(iVar2);
      if (lVar3 < 0) {
        param_1[3] = 3;
      }
      break;
    case 3:
      if (param_1[5] >= 0) {
        itfMesWindowSetCursor(iVar2, 0);
        itfMesWindowLayout(iVar2, param_1[5]);
        param_1[3] = 4;
      } else {
        param_1[3] = 5;
      }
      break;
    case 4:
      lVar3 = itfMesWindowGetAnim(iVar2);
      if (lVar3 < 0) {
        uVar4 = func_00278260(iVar2);
        iVar2 = param_1[6];
        if ((iVar2 >= 0) && (iVar2 < 10)) {
          evtResultSet(iVar2, uVar4);
        }
        param_1[7] = (int)uVar4;
        param_1[3] = 5;
      }
      break;
    case 5:
      if (bVar0 && (param_1[3] != 0)) {
        itfMesWindowSetState(iVar2, 0);
        itfMesWindowRelease(iVar2);
        itfMesWindowClear(iVar2, 0);
        itfMesWindowClearFlagBits(iVar2, 0x800000);
        itfMesWindowClearFlagBits(iVar2, 0x100000);
        itfMesWindowSetState(iVar2, 1);
        param_1[3] = 0;
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
  int *param_1 = object;
  if ((u8)(*param_1 != 0)) goto nonzero;
  return 1;

nonzero:
  return param_1[3] == 0;
}



// Returns the open window's record count, or 0 when no message is open.
// FUN_00290E10
u32 evtMessageWindowRecordCount(int *param_1)
{
  if ((u8)(*param_1 != 0)) goto nonzero;
  return 0;

nonzero:
  return itfMesWindowRecordCount(param_1[2]);
}

// Returns the window's entry value for the given index; asserts the window is open.
// FUN_00290E50
s32 evtMessageWindowEntryValue(u8 *arg0, s32 arg1)
{
    if (!(u8)(*(u32 *)arg0 != 0)) {
        kAssertFail(D_0063C820, 0x122);
    }
    return itfMesWindowEntryValue(*(s32 *)(arg0 + 8), arg1);
}
