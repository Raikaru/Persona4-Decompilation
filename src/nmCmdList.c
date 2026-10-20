#include "nm_message_record.h"
/* Source unit: src/nmCmdList_002baa90.c */
#include "include_asm.h"
#include "type.h"
#include "message_handle.h"

extern u8 DAT_00882F60_abs[];
extern u8 DAT_00882F64_abs[];
extern u8 DAT_00882F65_abs[];
extern u32 DAT_00882F68_abs[];
extern u8 DAT_00882F6C_abs[];
extern u8 DAT_00882F6D_abs[];
extern u8 *D_00882F40[];
extern u8 *nmMesWindowCurrent(void);
extern s32 nmMesWindowApplyStyle(s32* record, s32 style);
extern void nmMesWindowSetCurrentRunning(int running);
extern s32 itfMesWindowSetStyle(s32 handle, s16 kind);
extern int itfMesWindowGetAnim(int handle);

extern u32 DAT_0063F2B0_abs[];
extern void itfMesWindowReleaseIfActive(s32 handle);
extern s8 iGpffffb578;


#pragma push


/* Initialize a command record without touching its reserved bytes. */
// FUN_002BAA90
void nmMesWindowInitRecord(int recordAddress)

{

  u32 *recordWords;

  

  recordWords = (u32 *)recordAddress;

  if (recordAddress != 0) {

    *recordWords = 0xffffffff;

    ((NmMesWindowRecord *)recordWords)->state = 0;

    ((NmMesWindowRecord *)recordWords)->paused = 0;

    ((NmMesWindowRecord *)recordWords)->pendingRecord = 0xffffffff;

    ((NmMesWindowRecord *)recordWords)->cursor = 1;

    ((NmMesWindowRecord *)recordWords)->result = 1;

  }

  return;

}

#pragma pop


#pragma push


/* Install the current message after resetting its command record; return whether opened. */
// FUN_002BAAC0
u8 nmMesWindowOpenCurrent(u8* message)
{
    extern s32 itfMesWindowInstall(u8* record);
    s32* command;

    if (DAT_00882F60_abs != NULL)
    {
        *(u32*)DAT_00882F60_abs = 0xffffffff;
        DAT_00882F64_abs[0] = 0;
        DAT_00882F65_abs[0] = 0;
        DAT_00882F68_abs[0] = 0xffffffff;
        DAT_00882F6C_abs[0] = 1;
        DAT_00882F6D_abs[0] = 1;
    }

    command = (s32*)nmMesWindowCurrent();
    if (*command < 0)
    {
        *command = itfMesWindowInstall(message);
        nmMesWindowApplyStyle(command, 0);
        return 1;
    }

    return 0;
}

#pragma pop


#pragma push


/* Store the current cursor byte only when its window handle is valid. */
// FUN_002BB050
void nmMesWindowSetCurrentFlag(u8 cursor)

{

  u8 *record;

  

  record = nmMesWindowCurrent();

  if (record == 0)
    return;

  if (*(int *)record < 0)
    return;

  ((NmMesWindowRecord *)record)->cursor = cursor;

  return;

}

#pragma pop


#pragma push


/* Store the slot cursor byte only when its window handle is valid. */
// FUN_002BB0A0
void nmMesWindowSetSlotFlag(s64 slotIndex, s8 cursor)
{
    u8 *record;

    record = D_00882F40[(s8)slotIndex];
    if ((record != NULL) && (*(s32 *)record >= 0)) {
        ((NmMesWindowRecord *)record)->cursor = cursor;
    }
}
/* Return the current animation result, or -1 for a missing/invalid window. */
// FUN_002BB0E0
u32 nmMesWindowCurrentAnim(void)

{
  int *recordWords;
  u32 result;
  recordWords = (int *)nmMesWindowCurrent();

  if (recordWords == 0) {
    result = 0xffffffffffffffff;
  } else if (0 > *recordWords) {
    result = 0xffffffffffffffff;
  } else {
    result = itfMesWindowGetAnimAux(*recordWords);
  }

  return result;
}

#pragma pop


#pragma push


/* Return the current latched animation result, defaulting to one for no record. */
// FUN_002BB140
s32 nmMesWindowCurrentAnimFlag(void)
{
  s32 result;

  u8 *record;

  

  record = nmMesWindowCurrent();

  if (record == 0) {

    result = 1;

  }

  else {

    result = ((NmMesWindowRecord *)record)->result;

  }

  return result;

}

#pragma pop


#pragma push


/* Stop and clear the current window, optionally releasing its message data. */
// FUN_002BB1E0
u32 nmMesWindowCloseCurrent(int release)

{

  u32 closed;

  u8 *record;

  int *recordWords;

  

  record = nmMesWindowCurrent();

  if (record == 0) {

    closed = 0;

  }

  else {

    recordWords = (int *)record;

    if (*recordWords < 0) {

      closed = 0;

    }

    else {

      itfMesWindowSetState(*recordWords,0);

      if (release != 0) {

        itfMesWindowRelease(*recordWords);

      }

      itfMesWindowClear(*recordWords,0);

      nmMesWindowSetCurrentRunning(1);

      ((NmMesWindowRecord *)recordWords)->state = 0;

      closed = 1;

    }

  }

  return closed;

}

#pragma pop


#pragma push


// measured target CSE probe
#pragma optimization_level 1
/* Stop a slot window and clear its command state, optionally releasing the message. */
// FUN_002BB290
s32 nmMesWindowCloseSlot(s64 slotIndex, s32 release)
{
    extern void itfMesWindowSetState(s32 handle, s8 state);
    extern void itfMesWindowRelease(s32 handle);
    extern void itfMesWindowClear(s32 handle, s32 clearLabel);
    extern void nmMesWindowSetSlotRunning(s64 slotIndex, s32 running);
    u8 **slot;
    u8 *record;
    s32 handle;
    s32 **wordSlot;

    slot = &D_00882F40[(s8)slotIndex];
    record = *slot;
    if (record == NULL) {
        return 0;
    }
    handle = *(s32 *)record;
    if (handle < 0) {
        return 0;
    }
    itfMesWindowSetState(handle, 0);
    if (release != 0) {
        itfMesWindowRelease(*(s32 *)*slot);
    }
    wordSlot = (s32 **)&D_00882F40[(s8)slotIndex];
    itfMesWindowClear(**wordSlot, 0);
    nmMesWindowSetSlotRunning(slotIndex, 1);
    ((NmMesWindowRecord *)*wordSlot)->state = 0;
    return 1;
}
// measured target CSE probe
#pragma optimization_level 2
/* Release and clear the current window while preserving the command record. */
// FUN_002BB380
u32 nmMesWindowReleaseCurrent(void)

{

  u32 released;

  u8 *record;

  int *recordWords;

  

  record = nmMesWindowCurrent();

  if (record == 0) {

    released = 0;

  }

  else {

    recordWords = (int *)record;

    if (*recordWords < 0) {

      released = 0;

    }

    else {

      itfMesWindowSetState(*recordWords,0);

      itfMesWindowRelease(*recordWords);

      itfMesWindowClear(*recordWords,0);

      nmMesWindowSetCurrentRunning(1);

      ((NmMesWindowRecord *)recordWords)->state = 0;

      released = 1;

    }

  }

  return released;

}

#pragma pop


#pragma push


/* Hide the ready state while paused; absent or invalid windows report zero. */
// FUN_002BB600
s32 nmMesWindowCurrentOpenState(void)
{
  s32 state;
  int *recordWords;
  u8 *record;

  record = nmMesWindowCurrent();
  if (record == 0) {
    state = 0;
  }
  else {
    recordWords = (int *)record;
    if (*recordWords < 0) {
      state = 0;
    }
    else {
      if (((NmMesWindowRecord *)recordWords)->paused == '\0') {
        goto value;
      }
      if (((NmMesWindowRecord *)recordWords)->state != '\x02') {
        goto value;
      }
      state = 0;
      goto done;
value:
      state = ((NmMesWindowRecord *)recordWords)->state;
done:
      ;
    }
  }
  return state;
}

#pragma pop


#pragma push


/* Latch the auxiliary animation result once an animation is active. */
// FUN_002BB700
u32 nmMesWindowLatchAnimAux(void)

{

  u32 result;

  u32 latched;

  u8 *record;
  int animation;
  u8 *current;

  

  record = nmMesWindowCurrent();

  if (record == 0) {

    latched = 0;

  }

  else if (*(int *)record < 0) {

    latched = 0;

  }

  else {

    animation = itfMesWindowGetAnim(*(int *)record);

    if (animation < 0) {

      latched = 0;

    }

    else {

      current = nmMesWindowCurrent();

      if (current == 0) {

        result = -1;

      }

      else if (*(int *)current < 0) {

        result = -1;

      }

      else {

        result = itfMesWindowGetAnimAux(*(int *)current);

      }

      ((NmMesWindowRecord *)record)->result = result;

      latched = 1;

    }

  }

  return latched;

}

#pragma pop


#pragma push


/* Set a message string variable through the current command record. */
// FUN_002BBD20
void nmMesWindowSetCurrentString(s32 variable,void *text)

{

  u8 *record;

  

  record = nmMesWindowCurrent();

  if (record != 0) {

    itfMesWindowSetString(*(u32 *)record,variable,text);

  }

  return;

}

#pragma pop


#pragma push


/* Pause command processing with the two window hold bits, or resume its state. */
// FUN_002BBDD0
void nmMesWindowSetCurrentRunning(int running)

{

  extern u8 *nmMesWindowCurrent(void);
  u32 recordAddress;

  u32 *recordWords;

  

  recordAddress = (u32)nmMesWindowCurrent();

  if (recordAddress != 0) {

    recordWords = (u32 *)recordAddress;

    if (running != 0) {

      itfMesWindowClearFlagBits(*recordWords,0x800000);

      itfMesWindowClearFlagBits(*recordWords,0x100000);

      ((NmMesWindowRecord *)recordWords)->paused = 0;

      itfMesWindowSetState(*recordWords,1);

      ((NmMesWindowRecord *)recordWords)->state = 1;

    }

    else {

      itfMesWindowSetFlagBits(*recordWords,0x800000);

      itfMesWindowSetFlagBits(*recordWords,0x100000);

      ((NmMesWindowRecord *)recordWords)->paused = 1;

    }

  }

  return;

}

#pragma pop


#pragma push


/* Pause or resume the slot window and update its local pause/state bytes. */
// FUN_002BBE90
void nmMesWindowSetSlotRunning(s64 slotIndex, s32 running)
{
    u8 **slot;
    u8 *record;
    s32 index;

    index = (s8)slotIndex;
    slot = D_00882F40 + index;
    record = *slot;
    if (record != NULL) {
        if (running != 0) {
            itfMesWindowClearFlagBits(((NmMesWindowRecord *)record)->handle, 0x800000);
            itfMesWindowClearFlagBits(((NmMesWindowRecord *)*slot)->handle, 0x100000);
            ((NmMesWindowRecord *)*slot)->paused = 0;
            itfMesWindowSetState(((NmMesWindowRecord *)*slot)->handle, 1);
            ((NmMesWindowRecord *)*slot)->state = 1;
            return;
        }
        itfMesWindowSetFlagBits(((NmMesWindowRecord *)record)->handle, 0x800000);
        itfMesWindowSetFlagBits(((NmMesWindowRecord *)*slot)->handle, 0x100000);
        ((NmMesWindowRecord *)*slot)->paused = 1;
    }
}
// FUN_002BBF60
void nmMesWindowRequestRefresh(void)
{
    iGpffffb578 = 1;
}
// FUN_002BBF70
u8 *nmMesWindowCurrent(void)
{
    return (u8 *)DAT_00882F60_abs;
}
/* Map command styles to window styles (0, 2, 1); other values leave it unchanged. */
// FUN_002BBF80
s32 nmMesWindowApplyStyle(s32 *record, s32 style)
{
    switch (style) {
    case 0:
        itfMesWindowSetStyle(*record, 0);
        break;
    case 1:
        itfMesWindowSetStyle(*record, 2);
        break;
    case 2:
        itfMesWindowSetStyle(*record, 1);
        break;
    }
    return 0;
}
/* Install a message into the indexed persistent handle table. */
// FUN_002BC010
void nmMesWindowInstallHandle(int index,u8 *message)

{

  u32 handle;

  

  handle = itfMesWindowInstall(message);

  DAT_0063F2B0_abs[index] = handle;

  return;

}

#pragma pop


#pragma push


/* Release a valid persistent handle and restore its -1 sentinel. */
// FUN_002BC060
void nmMesWindowReleaseHandle(int index)
{
  s32 handle;

  handle = DAT_0063F2B0_abs[index];
  if (handle >= 0) {
    itfMesWindowReleaseIfActive(handle);
    DAT_0063F2B0_abs[index] = -1;
  }
}

#pragma pop
