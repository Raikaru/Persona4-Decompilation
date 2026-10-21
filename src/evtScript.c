#include "byte_address_internal.h"
#include "model_callbacks_internal.h"
/* Original translation unit evtScript.c (from __FILE__ assert strings). */
#include "type.h"
#include "fr_font_objects.h"
#include "mdl_file_internal.h"
#include "primitive_queue_internal.h"
#include "resrc_manager_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "scene_event_internal.h"
#include "scr_internal.h"
extern void datSetFlag();
extern void (*jtbl_008873EC[])(void *ptr);

typedef int (*code)();
extern code DAT_008873ec_abs[];


extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void kAssertFail(const void *file, u32 line);
extern u8 D_0063CF80[];
extern u8 D_0063CF90[];
extern u8 D_0063CFA0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u16 D_008C024E[];
extern u8 D_00795E60[];

extern void *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *list, void *node);
extern s32 kwlnTaskDestroyWithHierarchy(void *task);
extern u8 *kwlnTaskGetTaskByName(s8 *name);
extern s32 kwlnTaskIsLinked(void *target);
extern void MT_Scene_DestroyRes(u32);
extern void MT_Scene_SetResActiveById(s32, s32);
// lint: allow H011 -- a u16 prototype adds masking on the wide id arguments retail passes.
extern u16 *MT_Scene_GetRes(s32);
extern s32 mdlPrepareModel(u32 model);
extern u8 *mdlGetColor(s32);
extern void evtNodeSetRes(u8 *, s32, u16 *);
extern s32 evtEnsureEventTask(); /* lint: allow H011 -- caller stores the returned value; the definition is void */
extern s32 evtGetEventTaskWork();
extern u8 *evtFindSlotEntry();
extern void *mdlFindOrCreateModelObject(u32, u16, u32);
extern s32 evtFindTask();
extern void itfMesWindowApplySlots(s32 handle);
extern u8 *itfMesWindowBuildEntry(f32 x, f32 y, f32 scale, s32 color,
                         s32 slotIndex, s32 effect, s32 flags, s32 handle, s32 recordIndex);
extern u8 *frFontSplitRun(u8 **listAddress, s32 runIndex);
extern s32 frFontNodeWidth(u8 *node);
extern void frFontMoveListToFloat(u8 *list, f32 x, f32 y);
extern void frFontSetGlyphColor(u8 *list, s32 color);

/* measured: passing the operands through this helper's parameters keeps retail's offset-first add
 * order; expand it at each use. */


extern void frFontListKeepOrRelease(u8 *list);
extern f32 sinf(f32 floatInput);
extern f32 iGpffff8094;
/* INCLUDE_ASM fallback below; address taken by evtCmdNpcModelLoad. */
extern s32 evtNpcModelTaskUpdate(u8 *unusedTask);
/* INCLUDE_ASM fallback below; address stored by evtRestartTaskUpdate. */
extern void evtRestartTaskDraw(s32 unused, s32 task);

// Matches P3FES comuTimerSequence. kwlnTaskGetWork stays undeclared because a typed prototype adds
// zero-extension code that retail does not have.

/* The NPC loader allocates two words: model handle followed by event slot. */
typedef struct EvtNpcLoadWork {
    s32 model;
    s32 slot;
} EvtNpcLoadWork;

typedef struct EvtRestartWork {
    s32 unk00;
    s32 frame;
} EvtRestartWork;

// NPC model task update: waits for the model, replaces the NPC shadow resource, and copies its
// colour into the event node; returns -1 when done.
// FUN_00298370
s32 evtNpcModelTaskUpdate(u8 *unusedTask) {
    EvtNpcLoadWork *slotFields;
    EvtNpcLoadWork *slotFieldsReload;

    /* Loader/resource offsets are proven by EvtNpcLoadWork and ResrcRecord; typed access changes MWCC scheduling. */
    s32 taskOrSlot;
    u8 *resource;
    s32 modelOrResource;
    u8 *eventWorkOrColor;
    u8 *workOrNode;

    workOrNode = (u8 *)kwlnTaskGetWork();
    modelOrResource = ((EvtNpcLoadWork *)(workOrNode))->model;
    if (mdlPrepareModel(modelOrResource) == 1) {
        MT_Scene_DestroyRes((u16)((( ((EvtNpcLoadWork *)(workOrNode))->slot + 0x384) & 0x3FF) | 0xC00));
        modelOrResource = (s32)(MT_Scene_CreateModelNpcShadowRes(((slotFields = (EvtNpcLoadWork *)(workOrNode), slotFields)->slot + 0x384) & 0xFFFF, 3, modelOrResource) & 0xFFFF);
        if (modelOrResource == 0) {
            kAssertFail(D_0063CF80, 0x34);
        }
        MT_Scene_SetResActiveById(modelOrResource, 1);
        resource = (u8 *)MT_Scene_GetRes(modelOrResource);
        taskOrSlot = evtEnsureEventTask();
        if (taskOrSlot == 0) {
            kAssertFail(D_0063CF80, 0x39);
        }
        eventWorkOrColor = (u8 *)evtGetEventTaskWork(kwlnTaskGetWork(taskOrSlot));
        taskOrSlot = (slotFieldsReload = (EvtNpcLoadWork *)(workOrNode), slotFieldsReload)->slot;
        workOrNode = (u8 *)evtFindSlotEntry(eventWorkOrColor, taskOrSlot);
        if (workOrNode == NULL) {
            kAssertFail(D_0063CF80, 0x3D);
        }
        evtNodeSetRes(workOrNode, modelOrResource, (u16 *)resource);
        eventWorkOrColor = mdlGetColor(((ResrcRecord *)(resource))->modelHandle164Value);
        ((EvtNode *)workOrNode)->color = *(EvtColor *)eventWorkOrColor;
        return -1;
    }
    return 0;
}
// NPC model task destroy: frees the task's work block.
// FUN_00298510
void evtNpcModelTaskDestroy(u8 *unusedTask)
{
    int work;

    work = kwlnTaskGetWork();
    DAT_008873ec_abs[0](work);
}
// Event command 0x3000 EVT_NPC_MODEL_LOAD (2 params): activates the NPC model resource when it
// matches, otherwise creates it.
// FUN_00298550
s32 evtCmdNpcModelLoad(void)
{
    s32 slot;
    s32 modelId;
    u16 id;
    u8 *resource;
    u8 *work;

    slot = scrGetParamInt(0);
    modelId = scrGetParamInt(1);
    if (scrGetCmdTimer() == 0) {
        id = (u16)(((slot + 0x384) & 0x3FF) | 0xC00);
        /* The nested model identity is a type/id halfword pair; the full model layout is
         * unresolved. */
        if (MT_Scene_GetRes(id) != 0) {
            resource = (u8 *)MT_Scene_GetRes(id);
            if (((MdlFileModel *)(((ResrcRecord *)(resource))->modelHandle164Value))->type == 5 &&
                ((MdlFileModel *)(((ResrcRecord *)(resource))->modelHandle164Value))->id == modelId) {
                MT_Scene_SetResActiveById(id, 1);
                return 1;
            }
        }
        chkmemAllocSiteTag(D_0063CF80, 0x4F);
        work = D_008873F4[0](1, 8, 0x40000);
        ((EvtNpcLoadWork *)work)->model = (s32)mdlFindOrCreateModelObject(5, modelId & 0xFFFF, 0);
        ((EvtNpcLoadWork *)work)->slot = slot;
        if (((EvtNpcLoadWork *)work)->model == 0) {
            kAssertFail(D_0063CF80, 0x52);
        }
        (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_0063CF90), 0xF, 0, 0, evtNpcModelTaskUpdate, evtNpcModelTaskDestroy, (u8 *)(work));
    } else {
        if (kwlnTaskIsLinked(kwlnTaskGetTaskByName((s8 *)D_0063CF90)) != 0) {
            goto done;
        }
        return 1;
    }
done:
    return 0;
}
/* Event command 0x300C (EVT_FUNCTION_000C, 2 params): writes the value into the event node's slot
 * when the slot is below 5. The evtSlot helper keeps the address operand order, which a named local
 * or inline expression would canonicalize to base-first. */
// FUN_00298700
s32 evtCmdSetEventSlot(void) {
    s32 slot;
    s32 value;
    s32 kind;
    u8 *p;

    slot = scrGetParamInt(0);
    value = scrGetParamInt(1);
    if (slot >= 5) {
        return 1;
    }
    kind = evtFindTask();
    if (kind == 0) {
        return 1;
    }
    p = (u8 *)kwlnTaskGetWork(kind);
    if (evtMessageWindowIsOpen((u32 *)((EvtEventWork *)p)->messageWindow) == 0) {
        return 1;
    }
    ((EvtEventWork *)((u8 *)((u32)byteAddressAdd((slot * 4), (u8 *)(u32)p))))->messageControl.slots[0] = value;
    return 1;
}

// Draws one centred window text line: applies the window slots, builds the entry, splits the run
// and draws it centred at x.
// FUN_002987D0
/* Font list nodes expose a next pointer; the remaining glyph-node layout is not established here. */
void evtDrawCenteredWindowText(f32 x, f32 y, f32 depth, s32 color, s32 alpha,
                   s32 style, s32 flags, s32 kind, s32 messageManager, s32 entryIndex, s32 lineIndex)
{
    u8 *node;
    s32 sum;
    u8 *p;
    u8 *remainingText;

    itfMesWindowApplySlots(messageManager);
    remainingText = (u8 *)itfMesWindowBuildEntry(x, y, depth, (color << 8) | alpha,
                               style, flags, kind, messageManager, entryIndex);
    if (remainingText != NULL) {
        p = (u8 *)frFontSplitRun(&remainingText, lineIndex);
        if (p == NULL) {
            p = remainingText;
            remainingText = NULL;
        }
        node = p;
        sum = 0;
        while (node != NULL) {
            sum += frFontNodeWidth(node);
            node = *(u8 * *)&((FrFontTextRun *)(node))->previous;
        }
        frFontMoveListToFloat(p, x - (f32)sum / 2.0f, y);
        frFontSetGlyphColor(p, alpha | ~0xFF);
        if (remainingText != NULL) {
            frFontDrawList(p, 1, 0);
        }
        frFontListKeepOrRelease(p);
        if (remainingText != NULL) {
            frFontListKeepOrRelease(remainingText);
        }
    }
}
/* Draws one restart label row, alpha-faded by the row's position within each 0x28-step window. The
 * multiply operands are named locals assigned in retail order: converted delta first, then the GP
 * scale. */
// FUN_00298990
void evtRestartTaskDraw(s32 unused, s32 task) {
    f32 phase;
    f32 exitDelta;
    f32 elapsedFloat;
    f32 angleScale;
    s32 alpha;
    s32 elapsed;
    s32 messageManager;
    s32 frame;
    s32 rowStart;
    s32 rowIndex;
    u8 *work;

    work = (u8 *)kwlnTaskGetWork(task);
    /* Message-window +8 is the manager handle; the containing window layout is not recovered here. */
    messageManager = ((EvtEventWork *)((u8 *)evtGetEventTaskWork(kwlnTaskGetWork(evtEnsureEventTask()))))->messageControl.manager;
    rowIndex = 0;
    while (rowIndex < 0xF) {
        rowStart = rowIndex * 0x28;
        frame = ((EvtRestartWork *)work)->frame;
        if ((rowStart < frame) && (frame < (rowStart + 0x12C))) {
            elapsed = frame - rowStart;
            if (elapsed < 0xB4) {
                alpha = (s32)(255.0f * sinf((iGpffff8094 * (f32)elapsed) / 180.0f));
            } else if (elapsed > 0x10E) {
                exitDelta = (f32)(elapsed - 0x10E);
                elapsedFloat = exitDelta;
                angleScale = iGpffff8094;
                phase = angleScale;
                alpha = (s32)(255.0f * sinf(phase + ((angleScale * elapsedFloat) / 30.0f)));
            } else {
                alpha = 255;
            }
            evtDrawCenteredWindowText(320.0f, 300.0f - ((230.0f * (f32)elapsed) / 300.0f), 0.0f,
                          0xFFFFFF, alpha, 0, 0, 0, messageManager, 0, rowIndex);
        }
        rowIndex += 1;
    }
}
// Restart task update: advances its counter, sets flag 0x1211 while input is held, and queues the
// draw callback.
// FUN_00298B80
s32 evtRestartTaskUpdate(u8 *sdkTaskBytes)
{
    s32 taskHandle = (s32)sdkTaskBytes;
    u8 *base;
    u8 *p;

    base = (u8 *)kwlnTaskGetWork();
    ((EvtRestartWork *)base)->frame += 1;
    if (D_008C024E[0] & 0x9FF) {
        datSetFlag(0x1211, 1);
    }
    p = (u8 *)PrimAllocQueueNode();
    ((PrimQueueNode *)p)->callback = (void *)evtRestartTaskDraw;
    ((PrimQueueNode *)p)->argument.handle = taskHandle;
    PrimAppendNode(D_00795E60, p);
    return 0;
}
// Restart task destroy: clears flag 0x1211 and frees the task's work block.
// FUN_00298C10
void evtRestartTaskDestroy(u8 *unusedTask) {
    u8 *p = (u8 *)kwlnTaskGetWork();

    datSetFlag(0x1211, 0);
    jtbl_008873EC[0](p);
}

// Event command 0x3032 (EVT_FUNCTION_0032, 0 params): clears flag 0x1211, destroys any existing
// restart task and creates a new one.
// FUN_00298C60
s32 evtCmdRestartTask(void)
{
    s32 task;
    s32 eventTask;
    u8 *work;

    datSetFlag(0x1211, 0);
    task = (s32)kwlnTaskGetTaskByName((s8 *)D_0063CFA0);
    if (task != 0) {
        kwlnTaskDestroyWithHierarchy((void *)task);
    }
    eventTask = evtEnsureEventTask();
    chkmemAllocSiteTag(D_0063CF80, 0xF6);
    (s32)kwlnTaskCreateChild((void *)(eventTask), (const void *)(D_0063CFA0), 0xF, 0, 0, evtRestartTaskUpdate, evtRestartTaskDestroy, (u8 *)(D_008873F4[0](1, 8, 0x40000)));
    return 1;
}
