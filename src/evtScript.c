#include "model_callbacks_internal.h"
/* Original translation unit evtScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
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
// lint: allow H011 -- measured: u16 prototype regresses evtNpcModelTaskUpdate and evtCmdNpcModelLoad (andi on wide id args)
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

/* measured: the operands must travel through this helper's parameters to get
   retail's offset-first `addu $v0,$v0,$s0`; every callsite spelling (p+scaled,
   scaled+p, a named s32 local) is canonicalized back to base-first. Expand it at
   the use rather than through a local, so nothing stays live across a call. */
static inline u32 evtSlot(u32 offset, u32 base)
{
    return offset + base;
}

extern void frFontListKeepOrRelease(u8 *list);
extern f32 sinf(f32 floatInput);
extern f32 iGpffff8094;
/* INCLUDE_ASM fallback below; address taken by evtCmdNpcModelLoad. */
extern s32 evtNpcModelTaskUpdate(u8 *unusedTask);
/* INCLUDE_ASM fallback below; address stored by evtRestartTaskUpdate. */
extern void evtRestartTaskDraw(s32 unused, s32 task);

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// kwlnTaskGetWork is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

/* The NPC loader allocates two words: model handle followed by event slot. */
typedef struct EvtNpcLoadWork {
    s32 model;
    s32 slot;
} EvtNpcLoadWork;

typedef struct EvtRestartWork {
    s32 unk00;
    s32 frame;
} EvtRestartWork;

// Intent: NPC model task update: waits for the model, replaces the NPC shadow resource, and copies its colour into the event node; returns -1 when done [inferred]
// FUN_00298370
s32 evtNpcModelTaskUpdate(u8 *unusedTask) {
    /* Loader/resource offsets are proven by EvtNpcLoadWork and ResrcRecord; typed access changes MWCC scheduling. */
    s32 taskOrSlot;
    u8 *resource;
    s32 modelOrResource;
    u8 *eventWorkOrColor;
    u8 *workOrNode;

    workOrNode = (u8 *)kwlnTaskGetWork();
    modelOrResource = *(s32 *)(workOrNode + 0);
    if (mdlPrepareModel(modelOrResource) == 1) {
        MT_Scene_DestroyRes((u16)((( *(s32 *)(workOrNode + 4) + 0x384) & 0x3FF) | 0xC00));
        modelOrResource = (s32)(MT_Scene_CreateModelNpcShadowRes((*(s32 *)(workOrNode + 4) + 0x384) & 0xFFFF, 3, modelOrResource) & 0xFFFF);
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
        taskOrSlot = *(s32 *)(workOrNode + 4);
        workOrNode = (u8 *)evtFindSlotEntry(eventWorkOrColor, taskOrSlot);
        if (workOrNode == NULL) {
            kAssertFail(D_0063CF80, 0x3D);
        }
        evtNodeSetRes(workOrNode, modelOrResource, (u16 *)resource);
        eventWorkOrColor = mdlGetColor(*(s32 *)(resource + 0x164));
        ((EvtNode *)workOrNode)->color = *(EvtColor *)eventWorkOrColor;
        return -1;
    }
    return 0;
}
// Intent: NPC model task destroy: frees the task's work block [inferred]
// FUN_00298510
void evtNpcModelTaskDestroy(u8 *unusedTask)
{
    int work;

    work = kwlnTaskGetWork();
    DAT_008873ec_abs[0](work);
}
// Intent: Event command 0x3000, EVT_NPC_MODEL_LOAD (2 params): group 3 table entry 0x3000 in p4flow Event.json. Activates the NPC model resource when it matches, otherwise creates it [inferred]
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
        /* The nested model identity is a kind/id halfword pair at +0xD4/+0xD6; full model layout is unresolved. */
        if (MT_Scene_GetRes(id) != 0) {
            resource = (u8 *)MT_Scene_GetRes(id);
            if (*(u16 *)(*(s32 *)(resource + 0x164) + 0xD4) == 5 &&
                *(u16 *)(*(s32 *)(resource + 0x164) + 0xD6) == modelId) {
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
/* The addu operand order this note called an allocator floor is fixed by the
   `evtSlot` helper above, expanded at the use. The note was right that a named
   s32 local and every p+scaled / scaled+p callsite spelling get canonicalized
   back to base-first; only carrying the operands through a helper's parameters
   holds the order, and expanding it per use keeps nothing live across a call. */
// Intent: Event command 0x300C (EVT_FUNCTION_000C, 2 params): group 3 table entry 0x300C in Event.json. Writes the value into the event node's slot when the slot is below 5 [inferred]
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
    *(s32 *)((u8 *)evtSlot(slot * 4, (u32)p) + 0x698) = value;
    return 1;
}

// Intent: Draws one centred window text line: applies the window slots, builds the entry, splits the run and draws it centred at fparg0 [inferred]
// FUN_002987D0
/* Font list nodes expose next at +0x24; the remaining glyph-node layout is not established here. */
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
            node = *(u8 **)(node + 0x24);
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
/* Measured: object 488B / retail window 496B / normalized_diff 0. Named
   multiply-operand locals, assigned in retail order (converted delta first,
   then the GP scale), reproduce the retail conversion/load sequence. The
   prior archived nd8 claim was a differing-word count, not a body result.
   Also ruled out: first-argument hoist/local forms, declaration reversal,
   direct global load, comma assignment, schedule-off, inline evtMulScale and
   evtRamp helpers, reversed multiply operands, alternate float casts, and
   interleaved-parameter order (inapplicable: both target inputs are s32). */
// Intent: Draws one restart label row, alpha-faded by the row's position within each 0x28-step window [inferred]
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
    messageManager = *(s32 *)((u8 *)evtGetEventTaskWork(kwlnTaskGetWork(evtEnsureEventTask())) + 0x680);
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
// Intent: Restart task update: advances its counter, sets flag 0x1211 while input is held, and queues the draw callback [inferred]
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
// Intent: Restart task destroy: clears flag 0x1211 and frees the task's work block [inferred]
// FUN_00298C10
void evtRestartTaskDestroy(u8 *unusedTask) {
    u8 *p = (u8 *)kwlnTaskGetWork();

    datSetFlag(0x1211, 0);
    jtbl_008873EC[0](p);
}

// Intent: Event command 0x3032 (EVT_FUNCTION_0032, 0 params): group 3 table entry 0x3032 in Event.json. Clears flag 0x1211, destroys any existing restart task and creates a new one [inferred]
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
