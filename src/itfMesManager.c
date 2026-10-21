#include "member_access.h"
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
s32 scrGetParamInt(s32 paramIdx);
void itfMesWindowSetHandle(s32 handle, u32 hiddenMask);
void func_00440b68();
extern char D_0063BE20[];
void itfMesWindowFormatValue(int handle,int slotIndex,int value,u32 format);
u32 itfMesWindowSetParam(int handle,int button,int entryIndex);
extern void itfMesWindowSetString(int handle, int slotIndex, char *text);
extern int func_002438b0(int value);
extern int func_00243840(int value);
extern char iGpffffa760;
extern int iGpffffb444;

extern void itfMesWindowApplyStyle(s32 handle, s16 kind, s32 unusedValue);

/* Interior alias of each manager entry at +0xC, retaining its 0x20-byte stride. */
typedef struct {
    u8 *window;
    u8 pad[28];
} ItfMesWindowSlot;

extern ItfMesWindowSlot D_00881808[];

void datSetIndexedWord(int index, u32 value);

void frFontEnableList(int node);
extern u8 DAT_008817EC_abs[];
extern u8 DAT_008817E4_abs[];
extern u16 D_008817E8_abs[];
extern u8 *D_008817F4_abs[];
extern u8 D_008817FC_abs[];
void itfMesWindowUpdateLists(u32 window);
extern char D_0063BE10[];
void kAssertFail(const char *file, s32 line);
void fmGslContPoolInit();

s32 itfMesWindowTaskUpdate(u8 *sdkTaskBytes);
void itfMesWindowFreeAll(u8 *unusedTask);
extern char D_0063BF10[];
extern char D_0063BF20[];
void itfMesWindowFreeSlots();
void poolFree();
void poolSetAllocationSite();
void *poolAlloc();
void memset();
void itfMesEntryReset();
void itfMesClearSlots();
void itfMesWindowClearStateField(s32 window); /* lint: allow H011 -- the caller passes the stored pointer as s32; the definition takes s32 *. */
void itfMesWindowSendClear(s32 handle);
void fmGslContPoolUnlink();
s8 frFontRunCommand(int stream, int mode, int command);
u8 *frFontBuildTextSimple(u32 x, u32 y, u32 style, u32 palette, u32 effect, u32 intensity, u32 stream, u32 list);
u32 itfMesRecordTextAt(int recordAddress, int textIndex);
void itfMesListSetValue(u8 *list, s32 value);
void itfMesListSetAlpha(int listAddress, u32 alpha);
void itfMesWindowSetString(s32 handle, s32 slotIndex, char *text);
void itfMesWindowSetNumber(s32 handle, s32 slotIndex, s32 value);
s32 sprintf(char *buf, const char *fmt, ...);
s32 func_002438b0(s32 value);
s32 func_00243840(s32 value);
u32 datPersonaDisplayName(s16 unitId);
u32 datGetItemNameId(s16 itemId);
extern char iGpffffa760;
extern s32 iGpffffb444;
int itfMesRecordEntry(int windowAddress, int entryIndex);
s32 itfMesListWidth(int listAddress);
void frFontLoadSystemSlot(u8 *fontData);
u8 *frFontBuildTextFull(u32 x, u32 y, u32 duration, u32 style, u32 palette, u32 effect, u32 intensity, u32 stream, u32 list);
void memcpy(void *value, void *index, u32 count);
s32 strlen(const void *value);
void frFontSetGlyphAux(u8 *list, s32 palette);
void frFontSetGlyphColor(u8 *list, s32 color);
void frFontExSetScale(u8 *font, f32 scale);
void *fmGslContPoolAlloc(void *pool);
extern char D_0063BE60[];
void itfMesWindowSendRecordBound(s32 handle);
void itfMesWindowSetSelectionText(u8 *window, u8 *record);
void itfMesWindowBuildRow(u8 *window);
s32 frFontNodeWidth(u8 *node);
u8 *frFontAppendList(u8 *tail, u8 *list, s32 moveAfter);
extern char D_0063BE80[];
extern char D_0063BEA0[];
typedef signed __int128 s128;
u32 frFontMaskFlags(u32 value);
s32 itfMesWindowGetProcedureParam(s32 handle, s32 index);
void itfMesWindowSendChoiceMeasure(s32 handle);
void itfMesWindowSendChoiceBuilt(s32 handle);
int itfMesCountClearBits(int count, u32 mask);
u8 *itfMesBuildGlyphRun(u32 *texts, s32 count, u32 hiddenMask, s32 x, s32 y, s32 value, s32 spacing, s32 style);
s32 frFontListTail(int list);
void itfMesWindowSendLayoutLists(s32 handle);
s32 itfMesLineCount(u8 *firstRun, u8 *lastRun);
void itfMesWindowSetMetrics(int listAddress, int rowAddress);
void itfMesListEnableVisible(int listAddress);
extern u8 D_00881530[];
void itfMesWindowSetLabel(u8 *window, u8 *text);
extern s32 iGpffffb4b0;
void itfMesApplySlotTable();
void frFontSetListSlot();
void frFontDrawListMode();
u8 *itfMesWindowBuildEntry(f32 x, f32 y, f32 scale, s32 color, s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex);
void itfMesWindowDrawCallback(u8 *unusedNode, s32 listHandle);
void *PrimAllocQueueNode();
void PrimAppendNode();
u8 *itfMesObjectSetRecord(u8 *window, u8 *record);
s32 itfMesWindowBindRecord(s32 handle, s32 recordIndex, s32 rowIndex);
s32 itfMesWindowSetStyle(s32 handle, s16 kind);
void itfMesWindowRelease(s32 handle);
void itfMesWindowSetFlagBits(s32 handle, s32 flags);
void itfMesWindowClearFlagBits(s32 handle, s32 flags);
extern s32 DAT_007245C4;
void itfMesWindowSetProcedureParam(s32 handle, s32 index, s32 value);
void itfMesWindowSendStyledParameter(s32 handle);
void itfMesWindowClear(s32 handle, s32 clearLabel);
void itfMesWindowLayout(s32 handle, s32 recordIndex);
void itfMesWindowEnd(s32 handle);
void scrSetReturnInt(s32 retVal);
void itfMesWindowFree(s32 handle);
void itfMesObjectFree(u8 *window);
s32 itfMesRecordIsValid(u8 *record);
u8 *itfMesObjectCreate(u8 *record);
extern u8 DAT_008817E0_abs[];
s32 frFontListKeepOrRelease(s32 list);
void itfMesSlotReset(void *value, s32 index);
void itfMesRecordReset(void *value, s32 index);
void itfMesWindowSendRelease(s32 handle);
void itfMesWindowClearObject(u8 *window, s32 clearLabel);
void frFontMoveListTo(s32 list, s32 x, s32 y);
void itfMesWindowResetObject(u8 *window);
void itfMesObjectSetString(u8 *window, s32 slotIndex, s32 textAddress, s32 length);
void itfMesObjectSetNumber(u8 *window, s32 slotIndex, s32 value);
void itfMesRecordFixup(u8 *record);
void itfMesWindowSetProcedure(void *record, s16 kind);
extern char D_0063BED0[];
s32 H_Cdvd_AcquireDirectory(char *path, s32 flags);
void H_Cdvd_ReadSync(s32 cdvd);
void msgWinStart(s32 parent);
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
        itfMesWindowSendStyledParameter(index);
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
    itfMesWindowSendRelease(v);

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


/* Install the first free slot, keeping retail's diagnostic and copy ordering. */
#pragma push
/* measured: propagation off keeps the scaled slot index live across the copy call, as retail does. */
#pragma opt_propagation off
/* Allocate a manager entry and its window, preserving the prior active window flags on replacement. */
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
    if (((ItfMesManagerEntry *)(manager))->slots[i].value == 0) {
        ((ItfMesManagerEntry *)(manager))->slots[i].bytes = obj;
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
        if (((ItfMesManagerEntry *)(i + (u32)manager))->slots[0].value != 0) {
            oldWindow = ((ItfMesManagerEntry *)manager)->object.words;
            if (oldWindow != NULL) {
                memcpy(savedWindow, oldWindow, 0x130);
                found = 1;
            }
            MEMBER(s32 *, manager, ItfMesManagerEntry, object.words) = ((ItfMesManagerEntry *)(manager + i))->slots[0].words;
            if (found)
                *MEMBER(s32 *, manager, ItfMesManagerEntry, object.words) = savedWindow[0];
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
    itfMesWindowSendRecordBound(handle);
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

/* Run choice predicates, build the unhidden choices and initialize selection transition state. */
// FUN_00277BE0
void itfMesWindowLayout(s32 handle, s32 recordIndex)
{
    ItfMesChoiceRecord *countFields;
    ItfMesChoiceRecord *countFieldsReload;
    ItfMesSelection *hiddenmaskBitsFields;

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
    mask = ((ItfMesSelection *)(base))->hiddenMask.bits | newMask;
    ((ItfMesSelection *)(base))->hiddenMask.bits = mask;
    visibleCount = itfMesCountClearBits((countFields = (ItfMesChoiceRecord *)(data), countFields)->count, mask);
    itfMesWindowSetProcedureParam(handle, 0, visibleCount);
    itfMesWindowSendChoiceMeasure(handle);
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
        (countFieldsReload = (ItfMesChoiceRecord *)(data), countFieldsReload)->count,
        (hiddenmaskBitsFields = (ItfMesSelection *)(base), hiddenmaskBitsFields)->hiddenMask.bits,
        x, y, ((ItfMesWindow *)object)->value.value, spacing, 0);
    iGpffffb4b0 = savedFont;
    itfMesWindowSendChoiceBuilt(handle);
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

/* Resolve a numeric or data-table value to text, or store a numeric substitution directly. Case
 * bodies follow the jump table order; case 1 forwards all three entry arguments. */
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
        MEMBER(s16, base, ItfMesSelection, bindingCount) += 1;
    }
    *(s16 *)slot = (s16)button;
    ((ItfMesInputBinding *)slot)->entry = (s16)entryIndex;
    return 1;
}

/* Build a temporary text list with the window slots/font, measure its width and release it. Returns
 * the width from func_0027a520. */
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
    itfMesWindowSendClear(handle);
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


/* Relocate message offsets exactly once, using the header relocation stream. */
// FUN_00278D50
#pragma push
/* measured: propagation off keeps retail's load/move order for the staged arguments. */
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
        MEMBER(u8, record, ItfMesRecord, relocated) = 1;
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


/* Read the record kind at the requested index of a checked window. The remaining raw address
 * expressions are kept because typed forms change the output. */
// FUN_00278E20
s32 itfMesWindowEntryValue(s32 handle, s32 recordIndex)
{
    u8 *object;
    s32 off;

    object = D_00881808[handle].window;
    if (object == NULL)
        kAssertFail(D_0063BE10, 0xB3E);
    off = recordIndex * 8;
    return ((ItfMesRecord *)(off + (s32)(((ItfMesWindow *)object)->record.value)))->entries[0].kind;
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

/* measured: the address is computed as index-first integer arithmetic so the add operands come out
 * in the same order as retail. Execute a font command against the first text of the requested
 * record entry. measured: the remaining raw accesses keep their original address expressions
 * because typed rewrites change the output. */
/* Run a font command with the given value against the first text of the record entry at recordIndex
 * in the window for handle. */
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
    return frFontRunCommand(itfMesRecordTextAt(((ItfMesRecord *)(address))->entries[0].data.value, 0), command, value);
}
/* Return a text pointer for an in-range row, or zero for an invalid signed index; the remaining raw
 * address casts are kept because typed field accesses change the output. */
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
    textAddress = ((ItfMesTextRecord *)(address))->texts[0].bits;
  }
  return textAddress;
}


/* Build the current row, derive its mode flags, notify its procedure and update row metrics. */
// FUN_00279780
#pragma push
/* measured: retail's register setup in this function needs constant propagation off. */
#pragma opt_propagation off
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
        slot = ((ItfMesTextRecord *)(((u32)index << 2) + (s32)table))->texts[0].bytes;
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
            value = ((ItfMesTextRecord *)(((u32)index << 2) + (s32)table))->texts[0].value;
        frFontRunCommand(value, 1, 0);
    }
}
#pragma pop
/* Replace one of 32 owned substitution strings, rounding allocation size to four bytes. */
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
        ((ItfMesWord *)((u32)base + (u32)slotIndex * 4))->words = res;
        memcpy(res, (void *)textAddress, size);
    } else {
        size = (length + 5) & ~3;
        poolSetAllocationSite(D_0063BE10, 0xD22);
        res = (s32 *)poolAlloc(size);
        ((ItfMesWord *)((u32)base + (u32)slotIndex * 4))->words = res;
        memset(res, 0, size);
        memcpy(((ItfMesWord *)((u32)base + (u32)slotIndex * 4))->words, (void *)textAddress, length);
    }
}

/* Replace one substitution slot with an allocated four-byte integer value. The post-call slot store
 * uses a separate cast so the slot address is recomputed after the calls, as retail does. */
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
    ((ItfMesWord *)((u32)base + (u32)slotIndex * 4))->words = res;
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


/* Rebuild a changed label from a substitution slot or the message auxiliary name table. */
// FUN_00279E90
void itfMesWindowSetSelectionText(u8 *window, u8 *record)
{
    ItfMesWindow *labelIndexFields;

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
            p7 = ((ItfMesWindow *)((off + (s32)window)))->slots[0].bits;
            ((ItfMesLabel *)base)->list.value = (s32)frFontBuildTextSimple(0, 0, 0, 0, 0, 0xFF, p7, 0);
        } else {
            s32 ep;
            s32 v2;
            v2 = (labelIndexFields = (ItfMesWindow *)(window), labelIndexFields)->label.index;
            ep = ((ItfMesRecordTail *)((((ItfMesRecord *)((ItfMesWindow *)window)->record.value)->entryCount << 3) + ((ItfMesWindow *)window)->record.value + 0x20))->names.value;
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
/* Detach the current text-run node, release it and advance the owning link. */
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

/* Derive the inclusive line count from fixed-point Y distance and glyph height. The cast and alias
 * expressions are kept because typed field accesses change the generated code. */
// FUN_0027A2D0
s32 itfMesLineCount(u8 *firstRun, u8 *lastRun)
{
    FrFontTextRun *glyphheightFields;

    if (((FrFontTextRun *)lastRun)->glyphHeight <= 0) {
        kAssertFail(D_0063BE10, 0xE9F);
    }
    return ((((FrFontTextRun *)lastRun)->y - ((FrFontTextRun *)firstRun)->y) >> 3) /
               (glyphheightFields = (FrFontTextRun *)(lastRun), glyphheightFields)->glyphHeight + 1;
}

/* Writes value into the depth word of every text run, following the previous links until NULL. */
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
/* Not static because the retail asm blob calls this address; the K&R parameter list is the original
 * form. */
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


/* Replace only the low alpha byte of every glyph color in the linked text runs. */
// FUN_0027A4D0
/* measured: retail hoists the color mask out of the glyph loop. */
#pragma opt_loop_invariants on
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
