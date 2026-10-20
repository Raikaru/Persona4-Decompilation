/* Original translation unit sdkLbox.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "sdk_lbox_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
/* Allocated sizes are 0x190 for the listbox and 0x22C for each entry. */
typedef struct SdkLboxEntry {
    s32 id, type;
    u8 name[0x100];
    u8 text[0x100];
    u8 *unk208;
    f32 floatValue;
    u8 pad210[8];
    s32 valueFormat;
    u8 pad21C[8];
    s32 previousAddress;
    u8 *next;
} SdkLboxEntry;

typedef struct SdkLboxWork {
    s32 unk00, state, mode, selection, refresh, unk14;
    s32 x, y, width, height;
    s32 cellWidth, lineHeight;
    u8 pad30[0x100];
    u8 *window;
    u8 pad134[8];
    s32 visibleRows, count;
    u8 *entries;
    s32 nextId;
    u8 pad14C[8];
    s32 useMeasure;
    s32 (*measure)(u8 *);
    u8 pad15C[8];
    u8 list[0x2C];
} SdkLboxWork;
typedef char SdkLboxEntrySizeCheck[sizeof(SdkLboxEntry) == 0x22C ? 1 : -1];
typedef char SdkLboxWorkSizeCheck[sizeof(SdkLboxWork) == 0x190 ? 1 : -1];

extern void sdkListStateSetVisible(u8 *state, s32 value);
extern s32 sdkListStateGetVisible(u8 *state);
extern void sdkLboxRecalcLayout(u8 *task);
extern void sdkWindowSetCommand();
extern void sdkWindowSetRect();
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void sdkListStateInit(u8 *state, s32 value, s32 itemCount);
extern void sdkListStateSetPrimaryMasks(u8 *state, s32 value, s32 itemCount, s32 cursor, s32 scroll);
extern u8 D_00713118[];
extern void strcpy(u8 *dst, u8 *src);
extern void sdkListStateAddItem(u8 *state);
extern s32 sdkListStateGetCount(u8 *state);
extern u8 D_00713128[];
extern s32 sdkLboxUpdate(u8 *task);
extern void sdkLboxDestroy(u8 *task);
extern void sprintf(void *buf, const void *fmt, ...);
extern s32 strlen(const void *str);
extern s32 fptodp(f32 value);
extern u8 iGpffffb06c;
extern u8 iGpffffb070;
extern u8 iGpffffb0c0;
extern u8 iGpffffb090;
extern u8 iGpffffb0c8;
extern u8 iGpffffb0a8;
extern u8 D_007641F8;

/* measured: `handle` must be declared before `mem`, exactly as in sdkWrap
   func_004672c0. With `mem` first, b210 colours arg0 into $s0 and mem into
   $s1 -- the mirror of retail -- and all 20 differing words are that swap
   (20 -> 3, the rest being window padding). Any order that puts `handle`
   ahead of `mem` works; the relative position of `vec` does not matter. */
/* Allocate a listbox with its origin, default cell dimensions, and list state. */
// FUN_00470280
s32 sdkLboxCreateEx(u8 *parent, s32 x, s32 y, s32 mode)
{
    s32 handle;
    u8 *work;
    u8 *list;

    chkmemAllocSiteTag(D_00713118, 0x299);
    work = D_008873F4[0](1, 0x190, 0x40000);
    if (work == NULL) {
        return 0;
    }
    handle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_00713128), 0x102, 0, 0, sdkLboxUpdate, sdkLboxDestroy, (u8 *)(work));
    ((SdkLboxWork *)work)->x = x;
    ((SdkLboxWork *)work)->y = y;
    ((SdkLboxWork *)work)->width = 0x80;
    ((SdkLboxWork *)work)->height = 0x80;
    ((SdkLboxWork *)work)->cellWidth = 0xC;
    ((SdkLboxWork *)work)->lineHeight = 0xC;
    ((SdkLboxWork *)work)->visibleRows = 0xA;
    ((SdkLboxWork *)work)->mode = mode;
    list = ((SdkLboxWork *)work)->list;
    sdkListStateInit(list, ((SdkLboxWork *)work)->visibleRows, 0);
    sdkListStateSetPrimaryMasks(list, 0x4000, 0x1000, 0, 0);
    return handle;
}

// FUN_004703C0
void sdkLboxSetState(u8 *task, s32 state) {
    ((SdkLboxWork *)((KwlnTask *)task)->work)->state = state;
}

/* Recalculate bounds, update selection, and forward it to an existing window. */
// FUN_004703D0
void sdkLboxSetSelection(u8 *task, s32 selection) {
    u8 *work = ((KwlnTask *)task)->work;
    u8 *window;

    sdkLboxRecalcLayout(task);
    ((SdkLboxWork *)work)->selection = selection;
    ((SdkLboxWork *)work)->refresh = 2;
    window = ((SdkLboxWork *)work)->window;
    if (window != NULL) {
        sdkWindowSetCommand(window, selection);
    }
}

/* Change the row limit and resize to the effective visible row count. */
/* The separate typed alias retains the measured window/list address lifetimes. */
// FUN_00470430
void sdkLboxSetVisibleRows(u8 *task, s32 visibleRows) {
    SdkLboxWork *listbox = (SdkLboxWork *)((KwlnTask *)task)->work;
    u8 *work = ((KwlnTask *)task)->work;

    sdkListStateSetVisible(((SdkLboxWork *)work)->list, visibleRows);
    ((SdkLboxWork *)work)->visibleRows = sdkListStateGetVisible(listbox->list);
    sdkLboxRecalcLayout(task);
}

/* Move the listbox and update the existing window rectangle. */
/* The separate typed alias retains the measured window/list address lifetimes. */
// FUN_00470490
void sdkLboxSetOrigin(u8 *task, s32 x, s32 y) {
    SdkLboxWork *listbox = (SdkLboxWork *)((KwlnTask *)task)->work;
    u8 *work = ((KwlnTask *)task)->work;
    u8 *window;

    ((SdkLboxWork *)work)->x = x;
    ((SdkLboxWork *)work)->y = y;
    window = ((SdkLboxWork *)work)->window;
    if (window != NULL) {
        sdkWindowSetRect(window, (u8 *)&listbox->x);
    }
}

/* Measure each entry and its optional value, then fit the visible rows. */
/* The separate typed alias retains the measured entry-field address hoisting. */
// FUN_004704D0
void sdkLboxRecalcLayout(u8 *task)
{
    SdkLboxWork *listbox = (SdkLboxWork *)((KwlnTask *)task)->work;
    u8 text[0x100];
    s32 cellWidth;
    s32 visibleHeight;
    s32 valueType;
    s32 fixedValueType;
    s32 contentHeight;
    s32 lineHeight;
    u8 *entry;
    u32 maxWidth;
    s32 entryWidth;
    u32 paddedWidth;
    u8 *work;
    u8 *window;

    work = ((KwlnTask *)task)->work;
    entry = ((SdkLboxWork *)work)->entries;
    maxWidth = 0;
    goto loop_29_check;
loop_29_body:
    if (((SdkLboxWork *)work)->useMeasure != 0) {
        entryWidth = (((SdkLboxWork *)work)->measure)(((SdkLboxEntry *)entry)->name);
        valueType = ((SdkLboxEntry *)entry)->type;
        switch (valueType) {
        case 0:
            break;
        case 1:
            sprintf(text, &iGpffffb06c, ((SdkLboxEntry *)entry)->text);
            entryWidth += ((SdkLboxWork *)work)->cellWidth +
                     (listbox->measure)(text);
            break;
        case 2:
            strcpy(text, &iGpffffb070);
            entryWidth += ((SdkLboxWork *)work)->cellWidth +
                     (listbox->measure)(text);
            break;
        case 3:
            if (((SdkLboxEntry *)entry)->valueFormat == 0) {
                sprintf(text, &iGpffffb0c0,
                              ((SdkLboxEntry *)entry)->unk208);
                entryWidth += ((SdkLboxWork *)work)->cellWidth +
                         (listbox->measure)(text);
            } else {
                sprintf(text, &iGpffffb090,
                              ((SdkLboxEntry *)entry)->unk208);
                entryWidth += ((SdkLboxWork *)work)->cellWidth +
                         (listbox->measure)(text);
            }
            break;
        case 4:
            cellWidth = fptodp(((SdkLboxEntry *)entry)->floatValue);
            sprintf(text, &iGpffffb0c8, cellWidth);
            entryWidth += ((SdkLboxWork *)work)->cellWidth +
                     (listbox->measure)(text);
            break;
        }
    } else {
        cellWidth = ((SdkLboxWork *)work)->cellWidth;
        entryWidth = cellWidth * strlen(((SdkLboxEntry *)entry)->name);
        fixedValueType = ((SdkLboxEntry *)entry)->type;
        switch (fixedValueType) {
        case 0:
            break;
        case 1:
            entryWidth += listbox->cellWidth *
                     (strlen(((SdkLboxEntry *)entry)->text) + 1);
            break;
        case 2:
            entryWidth += listbox->cellWidth *
                     (strlen(&iGpffffb0a8) + 1);
            break;
        case 3:
            if (((SdkLboxEntry *)entry)->valueFormat == 0) {
                entryWidth += cellWidth * 9;
            } else {
                entryWidth += cellWidth * 0xB;
            }
            break;
        case 4:
            entryWidth += cellWidth * 8;
            break;
        }
    }
    paddedWidth = entryWidth + 4;
    if (maxWidth < paddedWidth) {
        maxWidth = paddedWidth;
    }
    entry = ((SdkLboxEntry *)entry)->next;
loop_29_check:
    if (entry != NULL) {
        goto loop_29_body;
    }
    ((SdkLboxWork *)work)->width = maxWidth;
    lineHeight = ((SdkLboxWork *)work)->lineHeight;
    contentHeight = ((SdkLboxWork *)work)->count * lineHeight + 4;
    visibleHeight = ((SdkLboxWork *)work)->visibleRows * lineHeight + 4;
    ((SdkLboxWork *)work)->height = visibleHeight;
    if (contentHeight < visibleHeight) {
        listbox->height = contentHeight;
    }
    window = ((SdkLboxWork *)work)->window;
    if (window != NULL) {
        sdkWindowSetRect(window, (u8 *)&((SdkLboxWork *)work)->x);
    }
}

/* measured: nd 18, obj 288B == window 288B, and every one of those words is the
   SAME $s0/$s1 swap -- retail colours `work` into $s0 and the allocation into
   $s1, b210 does the reverse. Logic, frame, call sequence and the list-walk loop
   all match exactly.

   Unlike sdkLboxCreateEx above (and sdkWrap func_004672c0, sdkUttmx tmxLoadFile),
   this mirror is NOT declaration-order drivable: node-first, p-first,
   work-last, and the initialised-declaration idiom this file uses elsewhere
   (`u8 *work = ((KwlnTask *)task)->work;`) all score 18. Retail gives $s0 to the
   more heavily used of the two pointers; b210 gives it to whichever is assigned
   first, and no source ordering flips that here. Seven spellings.

   Note: do NOT #include "sdktask.h" in this file to reach `((SdkTask *)task)->work`
   -- it conflicts with the local declarations and breaks the whole TU.
/* SOLVED. This carried an nd-18 "saved-register colouring floor" verdict backed by
   seven hand spellings, and tools/permute.py re-confirmed 18 after 1,687 compiles.
   tools/permute_ast.py cracked it, and the essential change reduces to one honest
   line: materialize the node pointer as an s32 BEFORE the list walk and store that
   local afterwards, rather than casting inline at the store. That single hoist
   fixes the whole $s0/$s1 mirror. Nothing else about the body changed. */
/* Append a text entry, returning its monotonically assigned identifier. */
/* The separate typed alias retains the measured entry-field address hoisting. */
// FUN_00470970
s32 sdkLboxAddEntry(u8 *task, u8 *text)
{
    SdkLboxWork *listbox = (SdkLboxWork *)((KwlnTask *)task)->work;
    u8 *work;
    u8 *node;
    s32 *link;
    s32 handle;

    work = ((KwlnTask *)task)->work;
    chkmemAllocSiteTag(D_00713118, 0x37D);
    node = D_008873F4[0](1, 0x22C, 0x40000);
    if (node == NULL) {
        kAssertFail(D_00713118, 0x37F);
    }
    strcpy(((SdkLboxEntry *)node)->name, text);
    ((SdkLboxEntry *)node)->type = 0;
    ((SdkLboxEntry *)node)->id = ((SdkLboxWork *)work)->nextId;
    ((SdkLboxWork *)work)->nextId = ((SdkLboxWork *)work)->nextId + 1;
    handle = (s32)node;
    link = (s32 *)&((SdkLboxWork *)work)->entries;
    while (*link != 0) {
        ((SdkLboxEntry *)node)->previousAddress = *link;
        link = (s32 *)&((SdkLboxEntry *)*link)->next;
    }
    *link = handle;
    ((SdkLboxWork *)work)->count = ((SdkLboxWork *)work)->count + 1;
    sdkLboxRecalcLayout(task);
    sdkListStateAddItem(((SdkLboxWork *)work)->list);
    listbox->count = sdkListStateGetCount(listbox->list);
    return ((SdkLboxEntry *)node)->id;
}

