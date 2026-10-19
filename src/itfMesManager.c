/* Source unit: src/itfMesManager_002770d0.c */
#include "type.h"
#include "itf_mes_objects.h"
#include "primitive_queue_internal.h"
#include "message_handle.h"
#include "message_procedure_api.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "datPersona_internal.h"

s32 scrGetMessageManager(void);
s32 scrGetParamInt(s32 index);
void itfMesWindowSetHandle(s32 handle, u32 index);
void func_00440b68();
extern char D_0063BE20[];
void itfMesWindowFormatValue(int value,int index,int count,u32 flags);
u32 itfMesWindowSetParam(int value,int index,int count);
extern void itfMesWindowSetString(int a, int b, char *c);
extern int func_002438b0(int value);
extern int func_00243840(int value);
extern char iGpffffa760;
extern int iGpffffb444;

extern void itfMesWindowApplyStyle(s32 value, s16 index, s32 count);

/* Interior alias of each manager entry at +0xC, retaining its 0x20-byte stride. */
typedef struct {
    u8 *window;
    u8 pad[28];
} ItfMesWindowSlot;

extern ItfMesWindowSlot D_00881808[];

void datSetIndexedWord(int value, u32 index);

void frFontEnableList(int value);
extern u8 DAT_008817EC_abs[];
extern u8 DAT_008817E4_abs[];
extern u16 D_008817E8_abs[];
extern u8 *D_008817F4_abs[];
extern u8 D_008817FC_abs[];
void itfMesWindowUpdateLists(u32 value);
extern char D_0063BE10[];
void kAssertFail(const char *file, s32 line);
void fmGslContPoolInit();

s32 itfMesWindowTaskUpdate(u8 *task);
void itfMesWindowFreeAll(u8 *task);
extern char D_0063BF10[];
extern char D_0063BF20[];
void itfMesWindowFreeSlots();
void poolFree();
void poolSetAllocationSite();
void *poolAlloc();
void memset();
void itfMesEntryReset();
void itfMesClearSlots();
void itfMesWindowClearStateField(s32 value); /* lint: allow H011 -- caller passes the stored pointer as s32 (*(s32 *)(row + 0x28)); the definition takes s32 *, and retyping the caller's load is unmeasured */
void func_0027b830(s32 value);
void fmGslContPoolUnlink();
s8 frFontRunCommand(int value, int index, int count);
u8 *frFontBuildTextSimple(u32 value, u32 index, u32 count, u32 flags, u32 effect, u32 intensity, u32 text, u32 tail);
u32 itfMesRecordTextAt(int value, int index);
void itfMesListSetValue(u8 *value, s32 index);
void itfMesListSetAlpha(int value, u32 index);
void itfMesWindowSetString(s32 value, s32 index, char *count);
void itfMesWindowSetNumber(s32 value, s32 index, s32 count);
s32 sprintf(char *buf, const char *fmt, ...);
s32 func_002438b0(s32 value);
s32 func_00243840(s32 value);
u32 datPersonaDisplayName(s16 value);
u32 datGetItemNameId(s16 value);
extern char iGpffffa760;
extern s32 iGpffffb444;
int itfMesRecordEntry(int value, int index);
s32 itfMesListWidth(int value);
void frFontLoadSystemSlot(u8 *value);
u8 *frFontBuildTextFull(u32 value, u32 index, u32 count, u32 flags, u32 effect, u32 intensity, u32 text, u32 tail, u32 duration);
void memcpy(void *value, void *index, u32 count);
s32 strlen(const void *value);
void frFontSetGlyphAux(u8 *value, s32 index);
void frFontSetGlyphColor(u8 *value, s32 index);
void frFontExSetScale(u8 *value, f32 fparg0);
void *fmGslContPoolAlloc(void *value);
extern char D_0063BE60[];
void func_0027b7c0(s32 value);
void itfMesWindowSetSelectionText(u8 *value, u8 *index);
void itfMesWindowBuildRow(u8 *value);
s32 frFontNodeWidth(u8 *value);
u8 *frFontAppendList(u8 *value, u8 *index, s32 count);
extern char D_0063BE80[];
extern char D_0063BEA0[];
typedef signed __int128 s128;
u32 frFontMaskFlags(u32 value);
s32 itfMesWindowGetProcedureParam(s32 value, s32 index);
void func_0027bb60(s32 value);
void func_0027bbc0(s32 value);
int itfMesCountClearBits(int value, u32 index);
u8 *itfMesBuildGlyphRun(u32 *value, s32 index, u32 count, s32 flags, s32 mode, s32 kind, s32 effect, s32 tail);
s32 frFontListTail(int value);
void itfMesWindowSendLayoutLists(s32 value);
s32 itfMesLineCount(u8 *value, u8 *index);
void itfMesWindowSetMetrics(int value, int index);
void itfMesListEnableVisible(int value);
extern u8 D_00881530[];
void itfMesWindowSetLabel(u8 *value, u8 *index);
extern s32 iGpffffb4b0;
void itfMesApplySlotTable();
void frFontSetListSlot();
void frFontDrawListMode();
u8 *itfMesWindowBuildEntry(f32 fparg0, f32 fparg1, f32 fparg2, s32 value, s32 index, s32 count, s32 flags, s32 mode, s32 kind);
void itfMesWindowDrawCallback(u8 *value, s32 index);
void *PrimAllocQueueNode();
void PrimAppendNode();
u8 *itfMesObjectSetRecord(u8 *value, u8 *index);
s32 itfMesWindowBindRecord(s32 value, s32 index, s32 count);
s32 itfMesWindowSetStyle(s32 value, s16 index);
void itfMesWindowRelease(s32 value);
void itfMesWindowSetFlagBits(s32 value, s32 index);
void itfMesWindowClearFlagBits(s32 value, s32 index);
extern s32 DAT_007245C4;
void itfMesWindowSetProcedureParam(s32 value, s32 index, s32 count);
void func_0027b8a0(s32 value);
void itfMesWindowClear(s32 value, s32 index);
void itfMesWindowLayout(s32 value, s32 index);
void itfMesWindowEnd(s32 value);
void scrSetReturnInt(s32 value);
void itfMesWindowFree(s32 value);
void itfMesObjectFree(u8 *value);
s32 itfMesRecordIsValid(u8 *value);
u8 *itfMesObjectCreate(u8 *value);
extern u8 DAT_008817E0_abs[];
s32 frFontListKeepOrRelease(s32 value);
void itfMesSlotReset(void *value, s32 index);
void itfMesRecordReset(void *value, s32 index);
void func_0027baa0(s32 value);
void itfMesWindowClearObject(u8 *value, s32 index);
void frFontMoveListTo(s32 value, s32 index, s32 count);
void itfMesWindowResetObject(u8 *value);
void itfMesObjectSetString(u8 *value, s32 index, s32 count, s32 flags);
void itfMesObjectSetNumber(u8 *value, s32 index, s32 count);
void itfMesRecordFixup(u8 *value);
void itfMesWindowSetProcedure(void *value, s16 index);
extern char D_0063BED0[];
s32 H_Cdvd_AcquireDirectory(char *value, s32 index);
void H_Cdvd_ReadSync(s32 value);
void msgWinStart(s32 value);
extern char D_0063BF00[];
extern char DAT_00723858;


/* Execute the script open command; return one once its asynchronous row state completes. */
// FUN_00276630
s32 itfMesCmdWindowOpen(void)
{
    s32 index;
    s32 handle;
    u8 *object;
    u8 *base;
    s8 flag;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x165);

    handle = scrGetParamInt(0);
    base = object + 0x1C;
    flag = ((ItfMesWindow *)object)->row.state.value;
    if (flag == 0) {
        itfMesWindowSetStyle(index, 0);
        if (itfMesWindowBindRecord(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        ((ItfMesRow *)base)->state.value = 0;
        return 1;
    }
    return 0;
}

/* Drive the close command through release and its ten-frame completion delay. */
// FUN_00276730
s32 itfMesCmdWindowClose(void)
{
    s32 index;
    s32 handle;
    s32 count;
    u8 *object;
    u8 *base;
    s8 flag;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x18F);

    handle = scrGetParamInt(0);
    base = object + 0x1C;
    flag = ((ItfMesWindow *)object)->row.state.value;
    if (flag == 0) {
        itfMesWindowSetStyle(index, 1);
        itfMesWindowSetFlagBits(index, 0x200000);
        if (itfMesWindowBindRecord(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            itfMesWindowRelease(index);
            ((ItfMesRow *)base)->state.value = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0xA) {
                ((ItfMesRow *)base)->state.value = 0;
                return 1;
            }
        } else if ((((ItfMesWindow *)object)->flags.bits & 0x300) == 0) {
            itfMesWindowRelease(index);
            itfMesWindowSetStyle(index, 0);
            itfMesWindowClearFlagBits(index, 0x400000);
            ((ItfMesRow *)base)->state.value = 0;
            return 1;
        }
    }
    return 0;
}

/* Open using kind one and the script parameter, then wait for release completion. */
// FUN_002768E0
s32 itfMesCmdWindowOpenStyled(void)
{
    s32 index;
    s32 handle;
    s32 count;
    s32 result;
    u8 *object;
    u8 *base;
    s8 flag;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x1CE);

    handle = scrGetParamInt(0);
    base = object + 0x1C;
    flag = ((ItfMesWindow *)object)->row.state.value;
    if (flag == 0) {
        itfMesWindowSetStyle(index, 1);
        itfMesWindowSetFlagBits(index, 0x200000);
        result = itfMesWindowBindRecord(index, handle, 0);
        itfMesWindowSetProcedureParam(index, 0, scrGetParamInt(1));
        func_0027b8a0(index);
        if (result == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            itfMesWindowRelease(index);
            ((ItfMesRow *)base)->state.value = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0xA) {
                ((ItfMesRow *)base)->state.value = 0;
                return 1;
            }
        } else if ((((ItfMesWindow *)object)->flags.bits & 0x300) == 0) {
            itfMesWindowRelease(index);
            itfMesWindowSetStyle(index, 0);
            itfMesWindowClearFlagBits(index, 0x400000);
            ((ItfMesRow *)base)->state.value = 0;
            return 1;
        }
    }
    return 0;
}

/* Bind a record and selection mask, then return the committed entry to the script. */
// FUN_00276AC0
s32 itfMesCmdWindowOpenAt(void)
{
    s32 index;
    s32 h0;
    s32 h1;
    s32 h2;
    u8 *object;
    u8 *base;
    s16 f;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x210);

    h0 = scrGetParamInt(0);
    h1 = scrGetParamInt(1);
    h2 = scrGetParamInt(2);
    base = object + 0x3C;
    f = ((ItfMesWindow *)object)->selection.state;
    if (f == 0) {
        itfMesWindowSetStyle(index, 3);
        itfMesWindowSetFlagBits(index, 0x200000);
        if (itfMesWindowBindRecord(index, h0, 0) == 0)
            return 1;
        itfMesWindowSetHandle(index, h2);
        itfMesWindowLayout(index, h1);
    } else if (f < 0) {
        ((ItfMesSelection *)base)->state = 0;
        itfMesWindowClear(index, 0);
        ((ItfMesWindow *)object)->row.state.value = 0;
        scrSetReturnInt(((ItfMesSelection *)base)->selected);
        itfMesWindowEnd(index);
        itfMesWindowRelease(index);
        return 1;
    }
    return 0;
}

/* Open using kind four and retain the script wait/release state machine. */
// FUN_00276C60
s32 itfMesCmdWindowOpenHold(void)
{
    s32 index;
    s32 handle;
    s32 count;
    u8 *object;
    u8 *base;
    s8 flag;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x249);

    handle = scrGetParamInt(0);
    base = object + 0x1C;
    flag = ((ItfMesWindow *)object)->row.state.value;
    if (flag == 0) {
        itfMesWindowSetStyle(index, 4);
        itfMesWindowSetFlagBits(index, 0x200000);
        if (itfMesWindowBindRecord(index, handle, 0) == 0)
            return 1;
    } else if (flag < 0) {
        if (flag == -1) {
            itfMesWindowRelease(index);
            ((ItfMesRow *)base)->state.value = -2;
            DAT_007245C4 = 0;
        } else if (flag == -2) {
            count = DAT_007245C4 + 1;
            DAT_007245C4 = count;
            if (count > 0x14) {
                ((ItfMesRow *)base)->state.value = 0;
                return 1;
            }
        } else if ((((ItfMesWindow *)object)->flags.bits & 0x300) == 0) {
            itfMesWindowRelease(index);
            itfMesWindowSetStyle(index, 0);
            itfMesWindowClearFlagBits(index, 0x400000);
            ((ItfMesRow *)base)->state.value = 0;
            return 1;
        }
    }
    return 0;
}

/* Read the signed row status associated with a window handle. */
// FUN_00276E10
s8 itfMesWindowState(s32 handle)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x284);
    return ((ItfMesWindow *)object)->row.state.value;
}

/* Store the row status after asserting that the handle owns a window. */
// FUN_00276E70
void itfMesWindowSetState(s32 handle, s8 state)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x29F);
    ((ItfMesWindow *)object)->row.state.value = state;
}

/* Wait for a selection and publish its chosen entry to the script return register. */
// FUN_00276ED0
s32 itfMesCmdWindowResult(void)
{
    s32 index;
    s32 h;
    u8 *object;
    u8 *base;
    s16 f;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x2C2);

    h = scrGetParamInt(0);
    base = object + 0x3C;
    f = ((ItfMesWindow *)object)->selection.state;
    if (f == 0) {
        itfMesWindowLayout(index, h);
    } else if (f < 0) {
        ((ItfMesSelection *)base)->state = 0;
        scrSetReturnInt(((ItfMesSelection *)base)->selected);
        itfMesWindowEnd(index);
        return 1;
    }
    return 0;
}

/* Read the signed selection phase for a checked window handle. */
// FUN_00276FB0
s16 itfMesWindowGetAnim(s32 handle)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x2F0);
    return ((ItfMesWindow *)object)->selection.state;
}

/* Set the signed selection phase for a checked window handle. */
// FUN_00277010
void itfMesWindowSetAnim(s32 handle, s16 state)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x306);
    ((ItfMesWindow *)object)->selection.state = state;
}

/* Read the selection cursor, which may be minus one before selection begins. */
// FUN_00277070
s32 itfMesWindowGetAnimAux(s32 handle)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x31F);
    return ((ItfMesWindow *)object)->selection.cursor;
}
/* Apply the script-supplied choice mask to the current message window. */
// FUN_002770D0
u32 itfMesCmdWindowSetHandle(void)
{
  int value;
  u32 other;

  value = scrGetMessageManager();
  if (value < 0)
    return 1;

  other = scrGetParamInt(0);
  itfMesWindowSetHandle(value, other);
  return 1;
}



/* Select the default procedure kind and request its opening transition. */
// FUN_00277130
s32 itfMesCmdWindowReset(void)
{
    s32 index;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;
    itfMesWindowApplyStyle(index, 0, 0);
    itfMesWindowSetFlagBits(index, 0x200000);
    return 1;
}

/* Release an opening or active window, and report when its transition group is idle. */
// FUN_002771A0
s32 itfMesCmdWindowIsIdle(void)
{
    s32 index;
    u8 *object;
    s32 flags;

    index = scrGetMessageManager();
    if (index < 0)
        return 1;

    object = D_00881808[index].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x398);

    flags = ((ItfMesWindow *)object)->flags.value & 0x300;
    if (flags == 0x100 || flags == 0x200)
        itfMesWindowRelease(index);
    return flags == 0;
}

/* Notify the procedure, request active transition groups to close, and release row/choice lists. */
// FUN_00277250
void itfMesWindowRelease(s32 handle)
{
    s32 v;
    s32 w;
    u8 *node;
    u8 *obj;

    obj = D_00881808[handle].window;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0x3B8);

    node = *(u8 **)DAT_008817EC_abs;
    while (node != NULL) {
        if (((ItfMesManagerEntry *)node)->object.bits == (u32)obj) {
            v = ((ItfMesManagerEntry *)node)->handle.value;
            goto out;
        } else {
            node = ((ItfMesManagerEntry *)node)->next.bytes;
        }
    }
    v = -1;
out:
    func_0027baa0(v);

    w = ((ItfMesWindow *)obj)->flags.bits;
    if (w & 0x300) {
        w = w & ~0x300;
        ((ItfMesWindow *)obj)->flags.bits = w;
        ((ItfMesWindow *)obj)->flags.bits = w | 0x300;
    }
    w = ((ItfMesWindow *)obj)->flags.bits;
    if (w & 0x3000) {
        w = w & ~0x3000;
        ((ItfMesWindow *)obj)->flags.bits = w;
        ((ItfMesWindow *)obj)->flags.bits = w | 0x3000;
    }
    itfMesWindowClear(handle, 1);
    itfMesWindowEnd(handle);
    ((ItfMesWindow *)obj)->flags.bits &= 0xFFDFFFFF;
}
/* Decode a slot, value and format from the script and update the window substitution. */
// FUN_00277370
u32 itfMesCmdWindowSetValue(void)
{
  int handle;
  u32 slotIndex;
  u32 value;
  u32 format;

  handle = scrGetMessageManager();
  if (handle < 0) {
    return 1;
  }
  slotIndex = scrGetParamInt(0);
  value = scrGetParamInt(1);
  format = scrGetParamInt(2);
  func_00440b68(D_0063BE20,slotIndex,value,format);
  slotIndex = scrGetParamInt(0);
  value = scrGetParamInt(1);
  format = scrGetParamInt(2);
  itfMesWindowFormatValue(handle,slotIndex,value,format);
  return 1;
}



/* Install the script-supplied button-to-choice binding in the current window. */
// FUN_00277450
u32 itfMesCmdWindowSetParam(void)
{
  s32 handle;
  u32 button;
  u32 entryIndex;

  handle = scrGetMessageManager();
  if (handle < 0) {
    return 1;
  }
  button = scrGetParamInt(0);
  entryIndex = scrGetParamInt(1);
  itfMesWindowSetParam(handle,button,entryIndex);
  return 1;
}



/* Install the first free slot, retaining retail's diagnostic and copy ordering.
   measured: integer-address testing and pointer-address reloading prevent
   whole-slot CSE; propagation off keeps the scaled index across the copy call.
   Neither lever alone matches. Exact 452B instructions plus 12B zero tail. */
#pragma push
#pragma opt_propagation off
/* Allocate a manager entry and its window, preserving the prior active window flags on replacement. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 119, 190, 304, 338; retain their original address/alias expressions. */
// FUN_002774D0
s32 itfMesWindowInstall(u8 *record)
{
    s32 savedWindow[0x4C];
    s32 result;
    s32 i;
    s32 found;
    s32 *oldWindow;
    u8 *manager;
    u8 *obj;

    if (itfMesRecordIsValid(record) != 1)
        kAssertFail(D_0063BE10, 0x525);
    manager = (u8 *)fmGslContPoolAlloc(DAT_008817EC_abs);
    if (manager == NULL)
        kAssertFail(D_0063BE10, 0x529);
    result = ((ItfMesManagerEntry *)manager)->handle.value;
    obj = itfMesObjectCreate(record);
    if (manager == NULL || obj == NULL)
        kAssertFail(D_0063BE10, 0x4F4);
    i = 0;
    goto slot_test;
slot_loop:
    if (*(s32 *)(manager + i * 4 + 0x10) == 0) {
        *(u8 **)(manager + i * 4 + 0x10) = obj;
        goto slot_done;
    }
    i++;
slot_test:
    if (i < 4)
        goto slot_loop;
    i = -1;
slot_done:
    if (i != 0)
        kAssertFail(D_0063BE10, 0x530);
    found = 0;
    if (i >= 0 || i < 4) {
        i *= 4;
        if (*(s32 *)(i + (u32)manager + 0x10) != 0) {
            oldWindow = ((ItfMesManagerEntry *)manager)->object.words;
            if (oldWindow != NULL) {
                memcpy(savedWindow, oldWindow, 0x130);
                found = 1;
            }
            *(s32 **)(manager + 0xC) = *(s32 **)(manager + i + 0x10);
            if (found)
                **(s32 **)(manager + 0xC) = savedWindow[0];
        }
    }
    *(s32 *)DAT_008817E0_abs += 1;
    func_00440b68(D_0063BE60, ((ItfMesWindow *)obj)->kind.value);
    return result;
}
#pragma pop
/* Allocate the 0x130-byte window and initialize its record, label, row, choice and slot work. */
// FUN_002776A0
u8 *itfMesObjectCreate(u8 *record)
{
    u8 *obj;

    if (itfMesRecordIsValid(record) != 1)
        kAssertFail(D_0063BE10, 0x55A);
    poolSetAllocationSite(D_0063BE10, 0x567);
    obj = poolAlloc(0x130);
    memset(obj, 0, 0x130);
    ((ItfMesWindow *)obj)->record.value = 0;
    itfMesObjectSetRecord(obj, record);
    ((ItfMesWindow *)obj)->flags.value = 0;
    ((ItfMesWindow *)obj)->value.value = 0;
    ((ItfMesWindow *)obj)->kind.value = 0;
    itfMesWindowSetProcedure(obj + 0x114, 0);
    itfMesSlotReset(obj + 0x14, 1);
    itfMesRecordReset(obj + 0x1C, 1);
    itfMesEntryReset(obj + 0x3C);
    itfMesClearSlots(obj + 0x94);
    return obj;
}

/* Validate MSG0/MSG1 data before returning the number of record entries. */
// FUN_002777A0
s32 itfMesRecordCount(u8 *record)
{
    if (itfMesRecordIsValid(record) != 1)
        kAssertFail(D_0063BE10, 0x589);
    return ((ItfMesRecord *)record)->entryCount;
}

/* Free a nonnegative handle only when its manager entry still owns a window. */
// FUN_002777F0
void itfMesWindowReleaseIfActive(s32 handle)
{
    if (handle >= 0) {
        if (((ItfMesManager *)DAT_008817E0_abs)->entries[handle].object.value != 0)
            itfMesWindowFree(handle);
    }
}

/* Validate the handle and return the embedded procedure work at window offset 0x114. */
// FUN_00277840
s32 itfMesWindowGetSubTable(s32 handle)
{
    u8 *object;

    if (handle < 0 || handle >= 0x40)
        kAssertFail(D_0063BE10, 0x134);
    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x5C7);
    return (s32)object + 0x114;
}

/* Bind a text record, build its selected row and enter the appropriate opening/active phase. */
// FUN_002778C0
s32 itfMesWindowBindRecord(s32 handle, s32 recordIndex, s32 rowIndex)
{
    s32 bits;
    s32 m3;
    s32 v;
    u8 *base;
    u8 *obj;
    u8 *r;
    u8 *r2;

    if (handle < 0 || handle >= 0x40)
        kAssertFail(D_0063BE10, 0x134);
    obj = D_00881808[handle].window;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0x5DE);
    r = (u8 *)itfMesRecordEntry((s32)obj, recordIndex);
    if (((ItfMesRecordEntry *)r)->kind == 1) {
        itfMesWindowLayout(handle, recordIndex);
        return 1;
    }
    r2 = ((ItfMesRecordEntry *)r)->data.bytes;
    base = obj + 0x1C;
    *(u8 **)base = r2;
    ((ItfMesRow *)base)->index = (s16)rowIndex;
    ((ItfMesRow *)base)->count = ((ItfMesTextRecord *)r2)->count;
    if (((ItfMesTextRecord *)r2)->count == 0)
        return 0;
    itfMesWindowSetSelectionText(obj, r2);
    itfMesApplySlotTable(obj + 0x94);
    v = ((ItfMesWindow *)obj)->font.value;
    if (v != 0)
        frFontLoadSystemSlot((u8 *)v);
    func_0027b7c0(handle);
    itfMesWindowBuildRow(obj);
    bits = ((ItfMesWindow *)obj)->flags.value;
    m3 = bits & 0x300;
    if ((bits & 0x200000) && (m3 == 0 || m3 == 0x300)) {
        func_00440b68(D_0063BE80);
        v = ((ItfMesWindow *)obj)->flags.value & ~0x300;
        ((ItfMesWindow *)obj)->flags.value = v;
        v |= 0x100;
        ((ItfMesWindow *)obj)->flags.value = v;
        v &= ~7;
        ((ItfMesWindow *)obj)->flags.value = v;
        ((ItfMesWindow *)obj)->flags.value = v | 2;
    } else {
        v = (s32)(((ItfMesWindow *)obj)->flags.bits & ~7u);
        ((ItfMesWindow *)obj)->flags.value = v;
        ((ItfMesWindow *)obj)->flags.value = v | 3;
    }
    ((ItfMesRow *)base)->state.value = 1;
    ((ItfMesWindow *)obj)->flags.value |= 0x1000000;
    func_00440b68(D_0063BEA0, ((ItfMesWindow *)obj)->kind.value);
    return 1;
}

/* Clear row text and optionally the label for a nonnegative window handle. */
// FUN_00277AD0
void itfMesWindowClear(s32 handle, s32 clearLabel)
{
    if (handle >= 0)
        itfMesWindowClearObject(D_00881808[handle].window, clearLabel);
}

/* Release row text, clear row transition bits, and optionally release the label list. */
// FUN_00277B10
void itfMesWindowClearObject(u8 *window, s32 clearLabel)
{
    u8 *base;
    u8 *base2;
    s32 v;

    base = window + 0x1C;
    if (((ItfMesWindow *)window)->row.list.value != 0) {
        frFontListKeepOrRelease(((ItfMesWindow *)window)->row.list.value);
        ((ItfMesRow *)base)->list.value = 0;
    }
    itfMesRecordReset(base, 0);
    v = ((ItfMesWindow *)window)->flags.value & ~7;
    ((ItfMesWindow *)window)->flags.value = v;
    v = v & ~0x300;
    ((ItfMesWindow *)window)->flags.value = v;
    ((ItfMesWindow *)window)->flags.value = v & 0xFFFDFFFF;
    if (clearLabel != 0) {
        base2 = window + 0x14;
        if (((ItfMesLabel *)base2)->list.value != 0) {
            frFontListKeepOrRelease(((ItfMesLabel *)base2)->list.value);
            ((ItfMesLabel *)base2)->list.value = 0;
        }
        itfMesSlotReset(window + 0x14, 0);
    }
}

/* Instruction-exact candidate: docs/probe_archive/BoA_00277be0_best_body.c,
   664B/672B; fndiff differs only in two absent zero-tail words.
   An s32 count still spills with SQ/LQ; declaring the second getter result
   before the third reproduces the retail register/stack assignment.
   Retain ASM pending semantic closure: the candidate's 1U << index requires
   index < 32, but the signed table count has no proven bound. Retail SLLV
   wraps the shift count; explicitly masking adds an instruction. */
/* Recovered: this body was measured at zero differing words in
   docs/probe_archive/MessagePrepareRecovery_00277be0_body.c and never
   installed. */
/* Run choice predicates, build the unhidden choices and initialize selection transition state. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 330, 335, 336, 343, 350; retain their original address/alias expressions. */
// FUN_00277BE0
void itfMesWindowLayout(s32 handle, s32 recordIndex)
{
    u8 *object;
    s32 flags;
    s32 index;
    s32 *text;
    s32 x;
    s32 y;
    s32 savedFont;
    u32 remainingMask;
    u8 *base;
    s32 font;
    s32 activeFlags;
    s32 modeFlags;
    s32 count;
    u32 mask;
    s32 oldFont;
    u32 newMask;
    u8 *record;
    s32 spacing;
    u8 *data;
    s32 visibleCount;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x686);
    record = (u8 *)itfMesRecordEntry((s32)object, recordIndex);
    if (((ItfMesRecordEntry *)record)->kind != 1)
        kAssertFail(D_0063BE10, 0x68A);
    base = object + 0x3C;
    oldFont = ((ItfMesWindow *)object)->selection.list.value;
    if (oldFont != 0) {
        frFontListKeepOrRelease(oldFont);
        ((ItfMesSelection *)base)->list.value = 0;
    }
    data = ((ItfMesRecordEntry *)record)->data.bytes;
    remainingMask = ((ItfMesSelection *)base)->hiddenMask.bits;
    count = (s32)((ItfMesChoiceRecord *)data)->count;
    text = (s32 *)(data + 0x20);
    newMask = 0;
    index = 0;
    while (index < count) {
        if (remainingMask & 1U) {
            remainingMask >>= 1;
        } else {
            frFontRunCommand(*text, 2, 0);
            if (frFontMaskFlags(8) != 0)
                newMask |= 1U << index;
        }
        index += 1;
        text++;
    }
    mask = *(u32 *)(base + 8) | newMask;
    *(u32 *)(base + 8) = mask;
    visibleCount = itfMesCountClearBits(*(s16 *)(data + 0x1A), mask);
    itfMesWindowSetProcedureParam(handle, 0, visibleCount);
    func_0027bb60(handle);
    x = itfMesWindowGetProcedureParam(handle, 0);
    y = itfMesWindowGetProcedureParam(handle, 1);
    spacing = itfMesWindowGetProcedureParam(handle, 2);
    itfMesApplySlotTable(object + 0x94);
    font = ((ItfMesWindow *)object)->font.value;
    if (font != 0)
        frFontLoadSystemSlot((u8 *)font);
    savedFont = iGpffffb4b0;
    if (savedFont == 0)
        iGpffffb4b0 = 0x7B;
    ((ItfMesSelection *)base)->list.value = (s32)itfMesBuildGlyphRun(
        (u32 *)(data + 0x20),
        *(s16 *)(data + 0x1A),
        *(u32 *)(base + 8),
        x, y, ((ItfMesWindow *)object)->value.value, spacing, 0);
    iGpffffb4b0 = savedFont;
    func_0027bbc0(handle);
    ((ItfMesSelection *)base)->count = (s16)visibleCount;
    flags = ((ItfMesWindow *)object)->flags.value & ~0x38;
    ((ItfMesWindow *)object)->flags.value = flags;
    activeFlags = flags | 0x10;
    ((ItfMesWindow *)object)->flags.value = activeFlags;
    modeFlags = activeFlags & ~0xC00;
    ((ItfMesWindow *)object)->flags.value = modeFlags;
    ((ItfMesWindow *)object)->flags.value = modeFlags | 0x400;
    ((ItfMesSelection *)base)->state = 1;
    ((ItfMesSelection *)base)->recordIndex.value = recordIndex;
}
// FUN_00277E80
void itfMesWindowEnd(s32 handle)
{
    itfMesWindowResetObject(D_00881808[handle].window);
}

/* Release choices and reset the selection cursor, count, mask and transition bits. */
// FUN_00277EC0
void itfMesWindowResetObject(u8 *window)
{
    u8 *base;
    s32 v;

    if (window == NULL)
        kAssertFail(D_0063BE10, 0x6F0);
    base = window + 0x3C;
    if (((ItfMesWindow *)window)->selection.list.value != 0) {
        frFontListKeepOrRelease(((ItfMesWindow *)window)->selection.list.value);
        ((ItfMesSelection *)base)->list.value = 0;
    }
    ((ItfMesSelection *)base)->state = 0;
    ((ItfMesSelection *)base)->count = 0;
    ((ItfMesSelection *)base)->cursor = -1;
    ((ItfMesSelection *)base)->hiddenMask.value = 0;
    v = ((ItfMesWindow *)window)->flags.value & ~0x38;
    ((ItfMesWindow *)window)->flags.value = v;
    v = v & ~0xC00;
    ((ItfMesWindow *)window)->flags.value = v;
    ((ItfMesWindow *)window)->flags.value = v & 0xFFFBFFFF;
}

/* Store the mask of hidden choices in an existing window. */
// FUN_00277F70
void itfMesWindowSetHandle(s32 handle, u32 hiddenMask)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x714);
    ((ItfMesWindow *)object)->selection.hiddenMask.bits = hiddenMask;
}

/* Translate a physical entry index into the visible-choice cursor using the hidden mask. */
// FUN_00277FD0
void itfMesWindowSetCursor(s32 handle, s32 entryIndex)
{
    u8 *object;
    u8 *base;
    u32 bits;
    s32 i;
    s32 zeros;
    s32 bit;
    s32 v;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x729);
    base = object + 0x3C;
    zeros = 0;
    bits = ((ItfMesWindow *)object)->selection.hiddenMask.bits;
    i = 0;
    while (1) {
        bit = bits & 1;
        if (bit == 0)
            zeros += 1;
        if (i >= entryIndex)
            break;
        i += 1;
        bits >>= 1;
    }
    if (bit != 0)
        v = 0;
    else
        v = zeros - 1;
    ((ItfMesSelection *)base)->cursor = (s16)v;
    ((ItfMesSelection *)base)->selected = (s16)v;
}

/* Move the row text list to the requested fixed-point coordinates. */
// FUN_00278090
void itfMesWindowMove(s32 handle, s32 x, s32 y)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x769);
    frFontMoveListTo(((ItfMesWindow *)object)->row.list.value, x, y);
}

/* Return the complete state/mode word of a checked window handle. */
// FUN_00278110
s32 itfMesWindowGetFlags(s32 handle)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x7A7);
    return ((ItfMesWindow *)object)->flags.value;
}

/* Set only caller-supplied high-word mode bits, leaving packed state groups unchanged. */
// FUN_00278170
void itfMesWindowSetFlagBits(s32 handle, s32 flags)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x7E8);
    ((ItfMesWindow *)object)->flags.bits |= (u32)flags & 0xFFFF0000;
}

/* Clear only caller-supplied high-word mode bits, leaving packed state groups unchanged. */
// FUN_002781E0
void itfMesWindowClearFlagBits(s32 handle, s32 flags)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x7FD);
    ((ItfMesWindow *)object)->flags.bits &= ~((u32)flags & 0xFFFF0000);
}

/* Return the signed selection cursor of a checked window handle. */
// FUN_00278260
s16 itfMesWindowGetCursor(s32 handle)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0x810);
    return ((ItfMesWindow *)object)->selection.cursor;
}

/* measured: re-measured 2026-08-03: nd 6 confirmed (verify normalized_diff
   10, bytes 80-91 = the case-0 arg order only; everything else byte-identical
   including the switch jtbl dispatch). New finding: the buf local must be
   u32 buf[4] (16B) to land at $sp+0x30 like retail - char buf[4] lands at
   0x3C (nd 7). The 3-word residual is unchanged from the floor: retail
   move $a0,$s1; move $a1,$s0; addiu $a2,$sp,0x30 (address-of last), mwcc b210
   always hoists the pure address-of addiu above the moves. Tried: (s32)buf,
   &buf[0], char buf[4], u32 buf[4] - identical. Address-of-in-argument-list
   scheduler floor (documented non-applicable case), not source-drivable. */
/* Case values decoded from jtbl_00748120 with tools/jtbl.py: eight dense
   entries, each with its own body, in the order written below (b210 lays case
   bodies out in declaration order). Case 1 calls func_002784e0 with $a0/$a1/$a2
   still holding the entry arguments, so it takes all three.
   measured: nd 10, obj 388 in a 400-byte window. The only residual is case 0's
   argument order -- retail materialises $a0 and $a1 before the sp+0x30 buffer
   address in $a2, b210 emits the addiu first (3 words). Naming the buffer in
   an int local and taking &sp30[0] both measure nd 10; schedule on is far
   worse (nd 203). Call-argument setup order floor. Committed at nd 10. */
/* object_size=388; window=400; normalized_diff=10; differing_word_offsets=80,84,88; first_diff_bytes=80,81,82,83,85,86,88,89,90,91. Corrected matched-callee declarations: datPersonaDisplayName(s16) and datGetItemNameId(s16), both with u32 return, replacing file-scope s64 declarations. Retail prologue checks for open callees confirmed func_00442088's existing variadic call shape and s32 signatures for func_00243840, func_002438b0 and func_00109220. Residual remains case-0 func_00278450 argument materialization: retail emits move a0,s1; move a1,s0; addiu a2,sp,0x30, while MWCC b210 emits addiu first. Probes retained from prior lane: char sp30[16]; u32/s32 sp30[4]; &sp30[0], integer/pointer casts; named a0/a1/a2 and dst/src/count locals with assignments in retail and reverse order; case-scoped/register locals; pointer local; comma-sequenced arguments; nested old-style callee declaration; fixed and variadic func_00442088 prototypes; optimization_level 1 (object 404, nd67); schedule-on (nd203); fresh permute (best nd10). No volatile or inline asm used. */
/* measured: the case-0 argument order (move a0 / move a1 / addiu a2,sp) is
   produced by passing the buffer to a pointer-typed parameter; casting it
   to an integer materialises the address first. Same lever as the "call-
   argument setup order" floor entry, which this closes. */
/* Resolve a numeric or data-table value to text, or store a numeric substitution directly. */
// FUN_002782C0
void itfMesWindowFormatValue(int handle, int slotIndex, int value, u32 format) {
    char textBuffer[16];

    switch (format) {
    case 0:
        sprintf(textBuffer, &iGpffffa760, value);
        itfMesWindowSetString(handle, slotIndex, textBuffer);
        break;
    case 1:
        itfMesWindowSetNumber(handle, slotIndex, value);
        break;
    case 2:
        itfMesWindowSetString(handle, slotIndex, (char *)(iGpffffb444 + value * 21));
        break;
    case 3:
        itfMesWindowSetString(handle, slotIndex, (char *)func_002438b0(value & 0xFF));
        break;
    case 4:
        itfMesWindowSetString(handle, slotIndex, (char *)datPersonaDisplayName((s16)value));
        break;
    case 5:
        itfMesWindowSetString(handle, slotIndex, (char *)datGetItemNameId((s16)value));
        break;
    case 6:
        itfMesWindowSetString(handle, slotIndex, (char *)func_00243840(value & 0xFFFF));
        break;
    case 7:
        itfMesWindowSetString(handle, slotIndex, (char *)datPersonaGetRow(value & 0xFFFF));
        break;
    }
}

/* Validate the handle and copy text into one of its substitution slots. */
// FUN_00278450
void itfMesWindowSetString(s32 handle, s32 slotIndex, char *text)
{
    if (handle < 0 || handle >= 0x40)
        kAssertFail(D_0063BE10, 0x134);
    itfMesObjectSetString(D_00881808[handle].window, slotIndex, (s32)text, 0);
}

/* Validate the handle and replace a substitution slot with an allocated integer. */
// FUN_002784E0
void itfMesWindowSetNumber(s32 handle, s32 slotIndex, s32 value)
{
    if (handle < 0 || handle >= 0x40)
        kAssertFail(D_0063BE10, 0x134);
    itfMesObjectSetNumber(D_00881808[handle].window, slotIndex, value);
}

/* Fix up the new message record in place, select its optional font and return the old record. */
// FUN_00278570
u8 *itfMesObjectSetRecord(u8 *window, u8 *record)
{
    u8 *old;
    u8 *temp;
    s32 v;

    if (window == NULL)
        kAssertFail(D_0063BE10, 0x8F4);
    old = ((ItfMesWindow *)window)->record.bytes;
    ((ItfMesWindow *)window)->record.bytes = record;
    itfMesRecordFixup(record);
    temp = (u8 *)itfMesRecordTail((int)record);
    if (((ItfMesRecord *)record)->magic == 0x3147534D)
        v = ((ItfMesRecordTail *)temp)->font.value;
    else
        v = 0;
    ((ItfMesWindow *)window)->font.value = v;
    return old;
}

/* Select a procedure kind through the common style application path. */
// FUN_00278610
s32 itfMesWindowSetStyle(s32 handle, s16 kind)
{
    itfMesWindowApplyStyle(handle, kind, 0);
    return 0;
}

/* Change the procedure kind only when no protected transition group is active. */
// FUN_00278640
void itfMesWindowApplyStyle(s32 handle, s16 kind, s32 unusedValue)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (!(((ItfMesWindow *)object)->flags.bits & 0x3300)) {
        ((ItfMesWindow *)object)->kind.value = kind;
        func_00440b68(D_0063BED0);
        itfMesWindowSetProcedure(object + 0x114, kind);
    }
}

/* Replace or append a button binding, rejecting reserved buttons and a full binding table. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 104; retain their original address/alias expressions. */
// FUN_002786C0
u32 itfMesWindowSetParam(int handle, int button, int entryIndex)
{
    s32 count;
    u8 *slot;
    u8 *base;
    s32 i;

    base = D_00881808[handle].window + 0x3C;
    slot = NULL;
    if (button < 0 || button >= 0x10)
        return 0;
    if (button == 6)
        button = 5;
    if (button == 0x40 || button == 0x1000 || button == 0x4000)
        return 0;
    i = 0;
    count = ((ItfMesSelection *)base)->bindingCount;
    while (i < count) {
        u8 *entry = base + i * 4;
        if (((ItfMesSelection *)base)->bindings[i].button == button) {
            slot = entry + 0x18;
            break;
        }
        i += 1;
    }
    if (slot == NULL) {
        if (count >= 0xF)
            return 0;
        slot = base + count * 4 + 0x18;
        *(s16 *)(base + 0x16) += 1;
    }
    *(s16 *)slot = (s16)button;
    ((ItfMesInputBinding *)slot)->entry = (s16)entryIndex;
    return 1;
}

/* MATCH (wave14): the old "$v0/$v1-coalescing + saved-reg-reuse floor" was
   a lever-1 miss - the function was INCLUDE_ASM with no prototype, but retail
   RETURNS a value (e.g. frFontBuildTextFull/0027a520 result). Writing the body as
   s32 func_002787d0(s32,s32,s32,s32) with the 9-arg frFontBuildTextFull call and
   returning func_0027a520's result matched byte-exact (nd 0). mwcc requires
   explicit casts (u8*<->int) at the func_00278de0/00279740 call sites. */
/* Build a temporary text list with the window slots/font, measure its width and release it. */
// FUN_002787D0
s32 itfMesWindowMeasureText(s32 handle, s32 recordIndex, s32 textIndex, s32 style) {
    u8 *obj;
    u8 *record;
    s32 textAddress;
    s32 list;
    s32 width;
    s32 savedFont;

    obj = D_00881808[handle].window;
    if (obj == NULL) {
        kAssertFail(D_0063BE10, 0x9AE);
    }
    record = (u8 *)itfMesRecordEntry((int)obj, recordIndex);
    if (*(s32 *)record != 0) {
        kAssertFail(D_0063BE10, 0x9B3);
    }
    record = ((ItfMesRecordEntry *)record)->data.bytes;
    if (((ItfMesTextRecord *)record)->count == 0) {
        return 0;
    }
    itfMesApplySlotTable(obj + 0x94);
    textAddress = ((ItfMesWindow *)obj)->font.value;
    if (textAddress != 0) {
        frFontLoadSystemSlot((u8 *)textAddress);
    }
    textAddress = itfMesRecordTextAt((int)record, textIndex);
    if (textAddress == 0) {
        return 0;
    }
    savedFont = iGpffffb4b0;
    if (savedFont == 0) {
        iGpffffb4b0 = 0x7B;
    }
    list = (s32)frFontBuildTextFull(0, 0, 0, style & 0xFF, 0, 0, 0xFF, textAddress, 0);
    iGpffffb4b0 = savedFont;
    width = itfMesListWidth(list);
    frFontListKeepOrRelease(list);
    return width;
}
/* Synchronously acquire the message directory and start the message-window subsystem. */
// FUN_00278940
void itfMesLoadData(void)
{
    func_00440b68(&DAT_00723858, D_0063BE10, 0xA00);
    H_Cdvd_ReadSync(H_Cdvd_AcquireDirectory(D_0063BF00, 1));
    msgWinStart(0);
}

/* Initialize the 64-entry pool and register the window update/destruction task. */
// FUN_002789A0
void itfMesInitManager(void)
{
    u8 *entry;

    *(u32 *)DAT_008817E0_abs = 0;
    *(u32 *)DAT_008817E4_abs = 0;
    *(u16 *)D_008817E8_abs = 0;
    fmGslContPoolInit(DAT_008817EC_abs, D_008817FC_abs, 0x40, 0x20);
    entry = D_008817F4_abs[0];
    while (entry != NULL) {
        ((ItfMesManagerEntry *)entry)->object.value = 0;
        entry = ((ItfMesManagerEntry *)entry)->next.bytes;
    }
    kwlnTaskCreate((const void *)(D_0063BF10), 0xF, 0, 0, itfMesWindowTaskUpdate, itfMesWindowFreeAll, (u8 *)(0));
    func_00440b68(D_0063BF20, D_0063BE10);
}

/* Release all four owned windows, unlink the manager entry and decrement the active count. */
// FUN_00278A70
void itfMesWindowFree(s32 handle)
{
    u8 *base;
    u8 *row;
    s32 i;
    s32 v;

    row = (u8 *)&DAT_008817E0_abs[handle * 0x20];
    base = row + 0x1C;
    if (((ItfMesManagerEntry *)(row + 0x1C))->object.value != 0)
        itfMesWindowClearStateField(((ItfMesManagerEntry *)(row + 0x1C))->object.value);
    func_0027b830(handle);
    ((ItfMesManagerEntry *)base)->object.value = 0;
    for (i = 0; i < 4; i++) {
        if (base == NULL || i < 0 || i >= 4)
            kAssertFail(D_0063BE10, 0x501);
        v = ((ItfMesManagerEntry *)base)->slots[i].value;
        if (v != 0) {
            ((ItfMesManagerEntry *)base)->slots[i].value = 0;
        } else {
            v = 0;
        }
        if (v != 0) {
            itfMesObjectFree((u8 *)v);
        }
    }
    fmGslContPoolUnlink(base, DAT_008817EC_abs);
    *(u32 *)DAT_008817E0_abs -= 1;
}

/* Release label, row, choice and substitution allocations before freeing the window. */
// FUN_00278B80
void itfMesObjectFree(u8 *window)
{
    u8 *base;
    s32 v;

    if (window != NULL) {
        itfMesWindowClearObject(window, 1);
        if (window == NULL)
            kAssertFail(D_0063BE10, 0x6F0);
        base = window + 0x3C;
        if (((ItfMesWindow *)window)->selection.list.value != 0) {
            frFontListKeepOrRelease(((ItfMesWindow *)window)->selection.list.value);
            ((ItfMesSelection *)base)->list.value = 0;
        }
        ((ItfMesSelection *)base)->state = 0;
        ((ItfMesSelection *)base)->count = 0;
        ((ItfMesSelection *)base)->cursor = -1;
        ((ItfMesSelection *)base)->hiddenMask.value = 0;
        v = ((ItfMesWindow *)window)->flags.value & ~0x38;
        ((ItfMesWindow *)window)->flags.value = v;
        v = v & ~0xC00;
        ((ItfMesWindow *)window)->flags.value = v;
        ((ItfMesWindow *)window)->flags.value = v & 0xFFFBFFFF;
        itfMesWindowFreeSlots(window + 0x94);
        ((ItfMesWindow *)window)->flags.value = 0;
        poolFree(window);
    }
}
/* Decode compact relocation deltas or runs and add the base address to each selected word. */
// FUN_00278C60
static void itfMesApplyRelocs(int *word, int baseAddress, u8 *relocations, int relocationSize)
{
  u8 code;
  u8 *cursor;
  int index;
  int count;
  int updateOffset;

  cursor = relocations;
  goto check;
  do {
    code = *cursor;
    cursor = cursor + 1;
    if ((code & 1) == 0) {
      updateOffset = (int)(u32)code >> 1;
      goto update;
    }
    if ((code & 2) == 0) {
      updateOffset = (code | ((int)*cursor << 8)) >> 2;
      cursor = cursor + 1;
      goto update;
    }
    if ((code & 4) == 0) {
      updateOffset = ((code | ((int)*cursor << 8)) | ((int)cursor[1] << 16)) >> 3;
      cursor = cursor + 2;
      goto update;
    }
    count = ((int)(u32)code >> 3) + 2;
    for (index = 0; index < count; index = index + 1) {
      word = word + 1;
      *word = *word + baseAddress;
    }
    goto check;
update:
    word = word + updateOffset;
    *word = *word + baseAddress;
check:
    updateOffset = ((int)cursor - (int)relocations < relocationSize);
    if (updateOffset == 0) {
      return;
    }
  } while (1);
}



/* Private helper knowledge keeps value in t3 across relocation. Staged
   arguments with propagation off preserve the load/move order.
   Measured: 76B of matching instructions and a 4B zero tail; helper 240B MATCH. */
/* Relocate message offsets exactly once, using the header relocation stream. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 15; retain their original address/alias expressions. */
// FUN_00278D50
#pragma push
#pragma opt_propagation off
void itfMesRecordFixup(u8 *record)
{
    u8 *base;
    u8 *fixups;
    s32 size;

    if (((ItfMesRecord *)record)->relocated == 0) {
        base = record + 0x20;
        fixups = record + ((ItfMesRecord *)record)->relocationOffset;
        size = ((ItfMesRecord *)record)->relocationSize;
        itfMesApplyRelocs((int *)base, (int)base, fixups, size);
        *(u8 *)(record + 0x1C) = 1;
    }
}
#pragma pop
/* Accept the two little-endian MSG0/MSG1 magic words used by the manager. */
// FUN_00278DA0
s32 itfMesRecordIsValid(u8 *record)
{
    s32 tag;
    s32 result;

    result = 1;
    /* Little-endian MSG0 and MSG1 identify the two message-file formats. */
    tag = *(s32 *)&((ItfMesRecord *)record)->magic;
    if ((tag != 0x3047534D) && (tag != 0x3147534D)) {
        result = 0;
    }
    return result != 0;
}
/* wave14: the former inline `volatile` on this load (which forced the
   `lw $v1, 4($a0)` ahead of the sll; removing it plain lost MATCH -> nd 9)
   is REPLACED by the lever-6 integer-domain spelling
   `(s32)*(s32 **)((u32)param_1 + 4)` - measured to tie the volatile byte-
   for-byte (fndiff 2 = benign tail padding; verify MATCH, decomp_lint clean).
   No volatile remains in this file. */
/* Return an eight-byte entry address from the window record and caller-supplied index. */
// FUN_00278DE0
int itfMesRecordEntry(int windowAddress,int entryIndex)
{
  s32 base;
  s32 index;

  base = (s32)((ItfMesWindow *)(u32)windowAddress)->record.words;
  index = entryIndex * 8;
  return index + base + 0x20;
}
/* Locate the auxiliary block immediately after the variable-length record entry table. */
// FUN_00278E00
int itfMesRecordTail(int recordAddress)
{
  int tableSize;

  tableSize = ((ItfMesRecord *)recordAddress)->entryCount * 8;
  return tableSize + recordAddress + 0x20;
}



/* Read the record kind at the requested index of a checked window. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 8; retain their original address/alias expressions. */
// FUN_00278E20
s32 itfMesWindowEntryValue(s32 handle, s32 recordIndex)
{
    u8 *object;
    s32 off;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0xB3E);
    off = recordIndex * 8;
    return *(s32 *)(off + (s32)(((ItfMesWindow *)object)->record.value) + 0x20);
}

/* Read the entry count of the message record bound to this window. */
// FUN_00278E90
s32 itfMesWindowRecordCount(s32 handle)
{
    u8 *object;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0xB55);
    return ((ItfMesRecord *)((ItfMesWindow *)object)->record.value)->entryCount;
}

/* Apply style to an existing row list or save its bytes until a row is built. */
// FUN_00278EF0
void itfMesWindowSetGlyphStyle(s32 handle, s32 slot, s32 effect, s32 flags, s64 nodeId)
{
    u8 *object;
    u8 *tmp;

    object = D_00881808[handle].window;
    tmp = ((ItfMesWindow *)object)->row.list.bytes;
    if (tmp != NULL) {
        frFontSetListFlag(tmp, flags & 0xFF);
        frFontSetNodeId(tmp, (s64)(s16)nodeId);
        frFontSetListSlot(tmp, slot);
        frFontSetGlyphAux(tmp, effect & 0xFF);
        return;
    }
    ((ItfMesWindow *)object)->row.style.value = slot;
    ((ItfMesWindow *)object)->row.palette.value = effect;
    ((ItfMesWindow *)object)->row.intensity.value = flags;
}
// FUN_00278FB0
s32 itfMesWindowGetTextList(s32 handle)
{
    return ((ItfMesWindow *)D_00881808[handle].window)->row.list.value;
}



// FUN_00278FD0
s32 itfMesWindowGetBodyList(s32 handle)
{
    return ((ItfMesWindow *)D_00881808[handle].window)->label.list.value;
}



// FUN_00278FF0
s32 itfMesWindowGetFontList(s32 handle)
{
    return ((ItfMesWindow *)D_00881808[handle].window)->selection.list.value;
}

// FUN_00279010
s32 itfMesWindowGetChoiceCount(s32 handle)
{
    return ((ItfMesWindow *)D_00881808[handle].window)->selection.count;
}

/* Measured: 448B/448B MATCH. The integer-address load preserves base-before-
   index evaluation; mixed byte cast/mask forms avoid call-crossing mask reuse.
   The unsigned index shift preserves EE wrapping arithmetic. */
/* Build one record entry at the requested screen position, then apply color/effect/scale. */
// FUN_00279030
u8 *itfMesWindowBuildEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex)
{
    u8 *obj;
    u8 *result;
    u8 *entry;
    u8 *slot;

    obj = D_00881808[handle].window;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0xBDD);
    slot = (u8 *)(((u32)recordIndex << 3) + (s32)((ItfMesWindow *)(u32)obj)->record.words + 0x20);
    if (slot == NULL)
        kAssertFail(D_0063BE10, 0xBE0);
    entry = ((ItfMesRecordEntry *)slot)->data.bytes;
    if (entry == NULL)
        kAssertFail(D_0063BE10, 0xBE3);
    result = (u8 *)itfMesRecordTextAt((s32)entry, 0);
    if (result == NULL)
        kAssertFail(D_0063BE10, 0xBE6);
    result = frFontBuildTextSimple(
        (s32)(16.0f * x),
        (s32)(8.0f * y),
        (u32)slotIndex & 0xFF,
        (u8)effect,
        0U,
        0xFFU,
        (u32)result,
        0U
    );
    if (flags & 1)
        frFontSetGlyphAux(result, (u32)effect & 0xFF);
    frFontSetGlyphColor(result, color);
    frFontExSetScale(result, scale);
    return result;
}
/* Build and immediately draw one entry using the window substitution table. */
// FUN_002791F0
s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex)
{
    u8 *obj;

    itfMesApplySlotTable(D_00881808[handle].window + 0x94);
    obj = itfMesWindowBuildEntry(x, y, scale, color, slotIndex, effect, flags, handle, recordIndex);
    frFontSetListSlot(obj, slotIndex);
    frFontDrawListMode(obj, 1);
    frFontListKeepOrRelease((s32)obj);
    return 0;
}

/* Draw the queued text list once and release its ownership afterward. */
// FUN_00279300
void itfMesWindowDrawCallback(u8 *unusedNode, s32 listHandle) {
    frFontDrawList((void *)listHandle, 1, 0);
    frFontListKeepOrRelease(listHandle);
}

/* Build an entry and queue a draw callback that will release the resulting text list. */
// FUN_00279350
s32 itfMesWindowQueueEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex, u8 *queue)
{
    u8 *obj;
    u8 *cb;

    itfMesApplySlotTable(D_00881808[handle].window + 0x94);
    obj = itfMesWindowBuildEntry(x, y, scale, color, slotIndex, effect, flags, handle, recordIndex);
    frFontSetListSlot(obj, slotIndex);
    cb = PrimAllocQueueNode();
    *(void (**)(void))&((PrimQueueNode *)cb)->callback = (void (*)(void))itfMesWindowDrawCallback;
    ((PrimQueueNode *)cb)->argument.data = obj;
    PrimAppendNode(queue, cb);
    return 0;
}

/* Build two entries on adjacent lines, append their lists and draw/release the combined text. */
// FUN_00279470
s32 itfMesWindowDrawPair(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex, s32 secondHandle, s32 secondRecordIndex)
{
    u8 *obj;
    u8 *r;
    u8 *r2;

    obj = D_00881808[handle].window;
    if (handle < 0)
        kAssertFail(D_0063BE10, 0xC32);
    if (secondHandle < 0)
        kAssertFail(D_0063BE10, 0xC33);
    itfMesApplySlotTable(obj + 0x94);
    r = itfMesWindowBuildEntry(x, y, scale, color, slotIndex, effect, flags, handle, recordIndex);
    if (secondRecordIndex != 0) {
        if (((FrFontTextRun *)r)->previous == 0) {
            r2 = itfMesWindowBuildEntry(x, 25.0f + y, scale, color, slotIndex, effect, flags, secondHandle, secondRecordIndex);
        } else {
            r2 = itfMesWindowBuildEntry(x + (f32)frFontNodeWidth(r), 25.0f + y, scale, color, slotIndex, effect, flags, secondHandle, secondRecordIndex);
        }
        r = frFontAppendList(r, r2, 0);
    }
    frFontSetListSlot(r, slotIndex);
    frFontDrawListMode(r, 1);
    frFontListKeepOrRelease((s32)r);
    return 0;
}

/* measured: integer-domain index-first address `(u8 *)(slotIndex * 8) + (u32)base` preserves retail's addu operand order; normalized_diff 0, object 172B/176B (trailing word is alignment padding). */
/* Execute a font command against the first text of the requested record entry. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 8; retain their original address/alias expressions. */
// FUN_00279690
s64 itfMesWindowRunEntry(s32 handle, s32 recordIndex, s32 command, s32 value)
{
    u8 *obj;
    u8 *base;
    u8 *address;

    obj = D_00881808[handle].window;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0xC50);
    base = (u8 *)((ItfMesWindow *)obj)->record.value;
    address = (u8 *)(recordIndex * 8) + (u32)base;
    return frFontRunCommand(itfMesRecordTextAt(*(s32 *)(address + 0x24), 0), command, value);
}
/* Return a text pointer for an in-range row, or zero for an invalid signed index. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 1; retain their original address/alias expressions. */
// FUN_00279740
u32 itfMesRecordTextAt(int recordAddress,int textIndex)
{
  u32 textAddress;
  int count = ((ItfMesTextRecord *)recordAddress)->count;

  if ((textIndex < 0) || (textIndex >= count)) {
    textAddress = 0;
  }
  else {
    int address = textIndex * 4;
    address = address + recordAddress;
    textAddress = *(u32 *)(address + 0x1c);
  }
  return textAddress;
}



/* Measured: 768B/window 768B, exact match. Named zero origins with
   opt_propagation off preserve constructor argument order. The binding
   helper consumes a text pointer; its pointer parameter also restores
   the final argument-move ordering. */
#pragma push
#pragma opt_propagation off
/* Build the current row, derive its mode flags, notify its procedure and update row metrics. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 1; retain their original address/alias expressions. */
// FUN_00279780
void itfMesWindowBuildRow(u8 *window)
{
    u8 *base;
    u8 *table;
    u8 *slot;
    u8 *obj;
    u8 *node;
    s32 index;
    s32 count;
    s32 flags;
    s32 found;

    base = window + 0x1C;
    if (((ItfMesWindow *)window)->row.list.value != 0) {
        frFontListKeepOrRelease(((ItfMesWindow *)window)->row.list.value);
        ((ItfMesRow *)base)->list.value = 0;
    }
    index = ((ItfMesRow *)base)->index;
    table = *(u8 **)base;
    count = ((ItfMesTextRecord *)table)->count;
    if (index < 0 || index >= count)
        slot = NULL;
    else
        slot = *(u8 **)(((u32)index << 2) + (s32)table + 0x1C);
    if (slot == NULL)
        kAssertFail(D_0063BE10, 0xC82);
    iGpffffb4b0 = 0x7B;
    {
        u32 originX = 0;
        u32 originY = 0;
        obj = frFontBuildTextSimple(
            originX, originY, ((ItfMesRow *)base)->style.bits, ((ItfMesRow *)base)->palette.bits,
            ((ItfMesRow *)base)->effect.bits, ((ItfMesRow *)base)->intensity.bits, (u32)slot, 0);
    }
    iGpffffb4b0 = 0;
    if (obj == NULL)
        kAssertFail(D_0063BE10, 0xCAA);
    ((ItfMesRow *)base)->list.bytes = obj;
    if (obj != NULL)
        ((ItfMesRow *)base)->lineCount = itfMesLineCount((u8 *)frFontListTail((s32)obj), obj);
    flags = frFontMaskFlags(3);
    ((ItfMesRow *)base)->flags.bits = (u8)flags;
    if (((ItfMesRow *)base)->flags.bits & 2U)
        ((ItfMesWindow *)window)->flags.value |= 0x10000;
    else
        ((ItfMesWindow *)window)->flags.value &= ~0x10000;
    flags = frFontMaskFlags(0x30);
    if (flags != 0)
        ((ItfMesWindow *)window)->flags.value |= 0x08000000;
    else
        ((ItfMesWindow *)window)->flags.value &= ~0x08000000;
    if (flags & 0x20)
        ((ItfMesWindow *)window)->flags.value |= 0x04000000;
    else
        ((ItfMesWindow *)window)->flags.value &= ~0x04000000;
    itfMesListSetValue(obj, ((ItfMesWindow *)window)->value.value);
    if (frFontMaskFlags(4) != 0)
        itfMesWindowSetLabel(window, D_00881530);
    node = *(u8 **)DAT_008817EC_abs;
    goto list_test;
list_body:
    if (((ItfMesManagerEntry *)node)->object.bytes == window) {
        found = ((ItfMesManagerEntry *)node)->handle.value;
        goto list_done;
    }
    node = ((ItfMesManagerEntry *)node)->next.bytes;
list_test:
    if (node != NULL)
        goto list_body;
    found = -1;
list_done:
    itfMesWindowSendLayoutLists(found);
    if ((((ItfMesWindow *)window)->flags.value & 0x400000) == 0 &&
        (*(u16 *)D_008817E8_abs & 1U) != 0)
        itfMesListEnableVisible((s32)obj);
    itfMesWindowSetMetrics((s32)obj, (s32)base);
    if ((((ItfMesWindow *)window)->flags.value & 0x300) == 0x200) {
        s32 value;

        index = ((ItfMesWindow *)window)->row.index;
        table = ((ItfMesWindow *)window)->row.record.bytes;
        count = ((ItfMesTextRecord *)table)->count;
        if (index < 0 || index >= count)
            value = 0;
        else
            value = *(s32 *)(((u32)index << 2) + (s32)table + 0x1C);
        frFontRunCommand(value, 1, 0);
    }
}
#pragma pop
/* Replace one of 32 owned substitution strings, rounding allocation size to four bytes. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 170, 248, 262; retain their original address/alias expressions. */
// FUN_00279A80
void itfMesObjectSetString(u8 *window, s32 slotIndex, s32 textAddress, s32 length)
{
    s32 size;
    s32 base;
    s32 *slot;
    s32 *res;

    if (window == NULL)
        kAssertFail(D_0063BE10, 0xCF1);
    if ((slotIndex < 0) || (slotIndex >= 0x20))
        kAssertFail(D_0063BE10, 0xCF2);
    base = (s32)window + 0x94;
    slot = (s32 *)(base + slotIndex * 4);
    if (*slot != 0) {
        poolFree(*slot);
        *slot = 0;
    }
    if (length <= 0) {
        size = (strlen((const void *)textAddress) + 4) & ~3;
        poolSetAllocationSite(D_0063BE10, 0xD0F);
        res = (s32 *)poolAlloc(size);
        *(s32 **)((u32)base + (u32)slotIndex * 4) = res;
        memcpy(res, (void *)textAddress, size);
    } else {
        size = (length + 5) & ~3;
        poolSetAllocationSite(D_0063BE10, 0xD22);
        res = (s32 *)poolAlloc(size);
        *(s32 **)((u32)base + (u32)slotIndex * 4) = res;
        memset(res, 0, size);
        memcpy(*(s32 **)((u32)base + (u32)slotIndex * 4), (void *)textAddress, length);
    }
}

/* MATCH (wave14): the old "CSE/allocator floor" was broken by lever 6 -
   spelling the POST-call slot store with integer-domain address arithmetic,
   `((ItfMesWord *)base)[slotIndex].words = res;`, so its CSE key differs from
   the pre-call `slot = (s32 *)(base + slotIndex * 4)` read. mwcc then RE-derives
   base+slotIndex*4 after the calls exactly like retail (sll $v1,$s3,2; addu
   $v1,$s2,$v1) instead of holding the full slot address live across the
   func_0046a2d0/func_0046a430 jals; base stays live in $s2 and the arg->$s
   mapping falls into retail's $s1/$s3/$s0. Prior attempts (slot local, bare
   expr, slotIndex<<2, s32/u8-star lvalue casts, opt_propagation off) all stayed
   nd 51; the DISTINCT-CAST address spelling is the only thing that worked.
   obj 220B vs window 224B (benign tail pad). */
/* Replace one substitution slot with an allocated four-byte integer value. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 39; retain their original address/alias expressions. */
// FUN_00279C00
void itfMesObjectSetNumber(u8 *window, s32 slotIndex, s32 value) {
    s32 base;
    s32 *slot;
    u8 *v;
    s32 *res;

    if (window == NULL) {
        kAssertFail(D_0063BE10, 0xD38);
    }
    if ((slotIndex < 0) || (slotIndex >= 0x20)) {
        kAssertFail(D_0063BE10, 0xD39);
    }
    base = (s32)window + 0x94;
    slot = (s32 *)(base + slotIndex * 4);
    v = *(u8 **)slot;
    if (v != NULL) {
        poolFree((s32)v);
        *(u8 **)slot = NULL;
    }
    poolSetAllocationSite(D_0063BE10, 0xD55);
    res = (s32 *)poolAlloc(4);
    *(s32 **)((u32)base + (u32)slotIndex * 4) = res;
    *res = value;
}
/* Publish all 32 substitution values to the font command processor. */
// FUN_00279CE0
void itfMesApplySlotTable(int slotsAddress)
{
  int slotIndex;

  for (slotIndex = 0; slotIndex < 0x20; slotIndex = slotIndex + 1) {
    datSetIndexedWord(slotIndex,((u32 *)slotsAddress)[slotIndex]);
  }

  return;
}



/* Publish substitution values from a checked window handle to the font processor. */
// FUN_00279D40
void itfMesWindowApplySlots(s32 handle)
{
    u8 *entry;
    s32 i;

    entry = D_00881808[handle].window;
    if (entry == 0) {
        kAssertFail(D_0063BE10, 0xD76);
    }
    for (i = 0; i < 0x20; i++) {
        datSetIndexedWord(i, ((ItfMesWindow *)entry)->slots[i].bits);
    }
}

/* Replace the label text and mark its source index unknown until the next record binding. */
// FUN_00279DD0
void itfMesWindowSetLabel(u8 *window, u8 *text)
{
    s32 global;
    u8 *base;

    if (window == NULL)
        kAssertFail(D_0063BE10, 0xD96);
    base = window + 0x14;
    if (((ItfMesWindow *)window)->label.list.value != 0)
        frFontListKeepOrRelease(((ItfMesWindow *)window)->label.list.value);
    global = iGpffffb4b0;
    if (global == 0)
        iGpffffb4b0 = 0x7B;
    ((ItfMesLabel *)base)->list.value = (s32)frFontBuildTextSimple(0, 0, 0, 2, 0, 0xFF, (u32)text, 0);
    iGpffffb4b0 = global;
    ((ItfMesLabel *)base)->index = 0xFFFF;
}

static inline s32 itfMesAddOffset(s32 off, s32 base) { return off + base; }

/* measured: func_00279e90 now matches exactly (object 316B, retail window
   320B, normalized_diff 0). The existing saved halfword/local and index-first
   itfMesAddOffset helper preserve retail's frame and address calculation. The
   first branch's unsigned handle load matches the canonical u32 constructor
   parameter without a conflicting local prototype. The second branch's
   explicit u32 cast preserves its load-before-argument-moves order. */
/* Rebuild a changed label from a substitution slot or the message auxiliary name table. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 1, 2, 218; retain their original address/alias expressions. */
// FUN_00279E90
void itfMesWindowSetSelectionText(u8 *window, u8 *record)
{
    s32 global;
    u8 *base;
    s32 unusedValue;
    u16 v;
    s32 masked;

    base = window + 0x14;
    v = ((ItfMesTextRecord *)record)->labelIndex;
    if (((ItfMesWindow *)window)->label.index == v)
        return;
    if (((ItfMesLabel *)base)->list.value != 0) {
        frFontListKeepOrRelease(((ItfMesLabel *)base)->list.value);
        ((ItfMesLabel *)base)->list.value = 0;
    }
    ((ItfMesLabel *)base)->index = v;
    global = iGpffffb4b0;
    if (global == 0)
        iGpffffb4b0 = 0x7B;
    masked = v & 0xFFFF;
    if (masked != 0xFFFF) {
        if (masked & 0x8000) {
            s32 off;
            u32 p7;
            off = (masked & 0x7FFF) << 2;
            p7 = *(u32 *)(itfMesAddOffset(off, (s32)window) + 0x94);
            ((ItfMesLabel *)base)->list.value = (s32)frFontBuildTextSimple(0, 0, 0, 0, 0, 0xFF, p7, 0);
        } else {
            s32 ep;
            s32 v2;
            v2 = *(u16 *)(window + 0x18);
            ep = *(s32 *)((((ItfMesRecord *)((ItfMesWindow *)window)->record.value)->entryCount << 3) + ((ItfMesWindow *)window)->record.value + 0x20);
            ((ItfMesLabel *)base)->list.value = (s32)frFontBuildTextSimple(0, 0, 0, 0, 0, 0xFF,
                (u32)((s32 *)ep)[v2], 0);
        }
        itfMesListSetValue((u8 *)((ItfMesLabel *)base)->list.value, ((ItfMesWindow *)window)->value.value);
    }
    iGpffffb4b0 = global;
}
/* Count visible entries in the low count bits of a hidden-entry mask. */
// FUN_00279FD0
int itfMesCountClearBits(int count,u32 mask)
{
  int clearCount;

  clearCount = 0;
  for (; 0 < count;) {
    if ((mask & 1) == 0) {
      clearCount = clearCount + 1;
    }
    count = count + -1;
    mask = mask >> 1;
  }
  return clearCount;
}



/* Append each unhidden text at successive vertical positions and set the combined list value/alpha. */
// FUN_0027A010
u8 *itfMesBuildGlyphRun(u32 *texts, s32 count, u32 hiddenMask, s32 x, s32 y, s32 value, s32 spacing, s32 style)
{
    s32 i;
    u8 *result;

    result = NULL;
    i = 0;
    while (i < count) {
        if (hiddenMask & 1) {
            hiddenMask >>= 1;
        } else {
            result = frFontBuildTextSimple(x, y, (u8)style, 5, 0, 0xFF, *texts, (u32)result);
            if (spacing == 0)
                y += ((FrFontTextRun *)result)->glyphHeight * 8;
            else
                y += spacing;
            hiddenMask >>= 1;
        }
        i++;
        texts++;
    }
    if (result != NULL) {
        itfMesListSetValue(result, value);
        itfMesListSetAlpha((int)result, 0xFF);
    }
    return result;
}

/* Detach one node before the release helper can consume its linked chain.
   Keep the successor locally: release may retain the node while glyphs fade. */
static inline void itfMesReleaseListNode(u8 **link)
{
    u8 *node = *link;
    u8 *next = *(u8 **)&((FrFontTextRun *)node)->previous;

    *(u8 **)&((FrFontTextRun *)node)->previous = NULL;
    *(u8 **)&((FrFontTextRun *)node)->next = NULL;
    *(u8 **)&((FrFontTextRun *)node)->root = node;
    frFontListKeepOrRelease((s32)node);
    *link = next;
}

/* measured: b210 -O2, 332 executable bytes / 336B window, all five
   relocations exact. Local traversal ownership and head-before-tail
   declarations close the saved-register floor; the final word is alignment. */
/* Keep the requested same-Y run and detach/release every run before and after it. */
// FUN_0027A150
u8 *itfMesReleaseTagRun(u8 *list, s32 firstLine, s32 lastLine)
{
    s32 remaining;
    s32 tag;
    u8 *head;
    u8 *tail;
    u8 *cursor;
    s32 value;
    u8 *current;

    current = list;
    if (current == NULL)
        kAssertFail(D_0063BE10, 0xE3E);
    remaining = lastLine - firstLine - 1;
    tag = ((FrFontTextRun *)current)->y;
    while (remaining > 0) {
        while (tag == ((FrFontTextRun *)current)->y) {
            itfMesReleaseListNode(&current);
            if (current == NULL)
                return NULL;
        }
        value = ((FrFontTextRun *)current)->y;
        remaining--;
        tag = value;
    }
    head = current;
    do {
        tail = current;
        current = *(u8 **)&((FrFontTextRun *)current)->previous;
    } while (current != NULL && tag == ((FrFontTextRun *)current)->y);
    while (current != NULL) {
        itfMesReleaseListNode(&current);
    }
    ((FrFontTextRun *)head)->next = 0;
    ((FrFontTextRun *)tail)->previous = 0;
    for (cursor = head; cursor != NULL; cursor = *(u8 **)&((FrFontTextRun *)cursor)->previous) {
        *(u8 **)&((FrFontTextRun *)cursor)->root = tail;
    }
    return head;
}
/* Copy intensity and the final glyph slot/palette/effect into row formatting work. */
// FUN_0027A2A0
void itfMesWindowSetMetrics(int listAddress, int rowAddress)
{
    int glyphAddress;

    glyphAddress = ((FrFontTextRun *)listAddress)->lastGlyph;
    ((ItfMesRow *)rowAddress)->intensity.value = (char)((int)(u32)((FrFontTextRun *)listAddress)->intensity >> 1);
    ((ItfMesRow *)rowAddress)->style.bits = ((FrFontGlyphData *)glyphAddress)->slot;
    ((ItfMesRow *)rowAddress)->palette.bits = ((FrFontGlyphData *)glyphAddress)->palette;
    ((ItfMesRow *)rowAddress)->effect.bits = ((FrFontGlyphData *)glyphAddress)->effect;
}

/* Derive the inclusive line count from fixed-point Y distance and glyph height. */
/* measured: individual typed rewrites of the remaining raw accesses give
 * normalized_diff 92; retain their original address/alias expressions. */
// FUN_0027A2D0
s32 itfMesLineCount(u8 *firstRun, u8 *lastRun)
{
    if (((FrFontTextRun *)lastRun)->glyphHeight <= 0) {
        kAssertFail(D_0063BE10, 0xE9F);
    }
    return ((((FrFontTextRun *)lastRun)->y - ((FrFontTextRun *)firstRun)->y) >> 3) /
               *(s16 *)(lastRun + 0x12) + 1;
}

/* Recovered after withdrawing the branch-landing boundary 0x0027A350: this
   function opens with `b 0x0027A350` into its own loop test, which spimdisasm
   recorded as a separate function, leaving only a 16-byte window here. 0x0027A340
   has 3 jal sites, 0x0027A350 none. See reconcile.BRANCH_LANDING_ENTRIES. */
// Sets field +0x14 of every entry in the list starting at firstRun to lastRun [inferred].
/* Set the per-run depth/value word across the linked text runs. */
// FUN_0027A340
void itfMesListSetValue(u8 *list, int value)
{
    while (list != NULL) {
        *(int *)&((FrFontTextRun *)list)->depth.bits = value;
        list = *(u8 **)&((FrFontTextRun *)list)->previous;
    }
}

/* Set the glyph palette for the requested same-Y run while preserving the donor K&R form. */
// FUN_0027A370
/* Not `static`: the symbol must stay global so the linker can resolve the
 * retail asm blob's jal to this address (measured: mwldps2 reports Undefined
 * "func_0027a370" if local).
 * The K&R parameter list below is the donor's form and is load-bearing. */
int itfMesListSetColor(listAddress,firstLine,lastLine,palette)
int listAddress;
int firstLine;
int lastLine;
u8 palette;
{
  int color;
  int diff;
  int cat;
  int candidate;

  diff = lastLine - firstLine;
  firstLine = diff - 1;
  cat = ((FrFontTextRun *)listAddress)->y;
  goto count_check;

advance:
  listAddress = ((FrFontTextRun *)listAddress)->previous;
  if (listAddress == 0) {
    goto done;
  }

load:
  candidate = ((FrFontTextRun *)listAddress)->y;
  if (cat == candidate) {
    goto advance;
  }
  firstLine = firstLine - 1;
  cat = candidate;

count_check:
  if (firstLine > 0) {
    goto load;
  }

set_start:
  color = (u8)palette;
set_load:
  candidate = ((FrFontTextRun *)listAddress)->firstGlyph;
  goto set_check;

set_store:
  ((FrFontGlyphData *)candidate)->palette = (u8)color;
  candidate = ((FrFontGlyphData *)candidate)->next;

set_check:
  if (candidate != 0) {
    goto set_store;
  }
  listAddress = ((FrFontTextRun *)listAddress)->previous;
  switch (listAddress) {
  case 0:
    goto done;
  }
  candidate = ((FrFontTextRun *)listAddress)->y;
  if (cat == candidate) {
    goto set_load;
  }
  goto done;
done:
  return;
}


/* Removing this loses FUN_0027A4D0 (MATCH nd0 -> MISMATCH nd24) - measured W161. */
#pragma opt_loop_invariants on

/* Replace only the low alpha byte of every glyph color in the linked text runs. */
// FUN_0027A4D0
void itfMesListSetAlpha(int listAddress,u32 alpha)
{
  int glyphAddress;

  for (; listAddress != 0; listAddress = ((FrFontTextRun *)listAddress)->previous) {
    for (glyphAddress = ((FrFontTextRun *)listAddress)->firstGlyph; glyphAddress != 0; glyphAddress = ((FrFontGlyphData *)glyphAddress)->next) {
      ((FrFontGlyphData *)glyphAddress)->color = ((FrFontGlyphData *)glyphAddress)->color & 0xffffff00 | alpha;
    }
  }
  return;
}
#pragma opt_loop_invariants off



/* Sum widths of runs sharing a Y position and return the maximum in sixteenth-pixel units. */
// FUN_0027A520
int itfMesListWidth(int listAddress)
{
  int maxWidth;
  int lineY;
  int lineWidth;

  maxWidth = 0;
  goto outer_test;
outer_body:
  lineY = ((FrFontTextRun *)listAddress)->y;
  lineWidth = 0;
  do {
    lineWidth += ((FrFontTextRun *)listAddress)->width;
    listAddress = ((FrFontTextRun *)listAddress)->previous;
    if (listAddress == 0) {
      break;
    }
  } while (lineY == ((FrFontTextRun *)listAddress)->y);
  if (maxWidth < lineWidth) {
    maxWidth = lineWidth;
  }
outer_test:
  if (listAddress != 0) {
    goto outer_body;
  }
  return maxWidth << 4;
}



/* Enable each text run whose first glyph has no effect byte set. */
// FUN_0027A580
void itfMesListEnableVisible(int listAddress)
{
  for (; listAddress != 0; listAddress = ((FrFontTextRun *)listAddress)->previous) {
    if (((FrFontGlyphData *)((FrFontTextRun *)listAddress)->firstGlyph)->effect == '\0') {
      frFontEnableList(listAddress);
    }
  }

  return;
}



/* Clear the 32 substitution handles without freeing their allocations. */
// FUN_0027A6C0
void itfMesClearSlots(int slotsAddress)
{
  int slotIndex;

  for (slotIndex = 0; slotIndex < 0x20; slotIndex = slotIndex + 1) {
    ((u32 *)slotsAddress)[slotIndex] = 0;
  }

  return;
}




/* Draw all active windows and advance the manager flush counter. */
// FUN_0027B620
u64 itfMesFlushPending(void)
{
    int current;
    u32 count;

    current = *(int*)DAT_008817EC_abs;
    while (current != 0) {
        itfMesWindowUpdateLists(((ItfMesManagerEntry *)current)->object.bits);
        current = ((ItfMesManagerEntry *)current)->next.value;
    }
    count = *(u32*)DAT_008817E4_abs;
    *(u32*)DAT_008817E4_abs = count + 1;
    return 0;
}
