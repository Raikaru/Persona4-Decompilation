/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00285cc0-002866c0 */

#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"
#include "scene_resource_internal.h"
s32 kwlnTaskGetTaskByName(void *);
extern s32 D_0063C368[];
extern u32 kwlnTaskGetWork(void *task);
void memset(void *, s32 , s32 );
void evtMenuClearSlots(void);
extern s32 fieldRoomFileExists(s32 , s32 );
extern void fieldSceneLoad(s32 , s32 );
extern void fieldSceneRequestRoom(s64 );
extern void fieldSceneRequestSecondaryRoom(s16 );
extern s32 fieldSceneLoadStep(void);
extern void func_00440b68();
extern u8 D_0063C310[];
typedef struct {
    u8 pad[0x76C];
    s32 loadWords[15];
} EvtLoaderBlock;

extern void evtDestroy(s32 , s32 );
extern u8 *evtCreateEventState(void);
extern s32 evtStepEventTask(u8 *sdkTaskBytes);
extern void evtDestroyEventScene(u8 *, s32 );
extern void evtApplyEventBlock(EvtLoaderBlock *);
extern u8 *kwlnGetCamera(void);
extern f32 K_View_GetFov(u8 *);
extern s32 evtPMFileReaderCreate(s32 , s32 , s32 , s32 );
extern s32 evtPMFileReaderIsDone(s32 );
extern u8 *evtPMFileReaderGetWork(s32 );
extern u8 *evtPolygonMovieAlloc(void);
extern u8 *evtPolygonMovieBind(u8 *messageContext, u8 *work, u8 *primary,
                         u8 *secondary, u8 *overlay);
extern s32 evtEffectTableCreate(void);
extern void mtMiscAppendEntry(s32 , u32 );
extern void evtEffectSequenceReset(s32 );
extern s32 evtEffectLoadStep(s32 );
extern void mtMiscBuildScene(s32 , u8 *);
extern s32 mtMiscDispatchKeyAction(s32 , s32 );
extern s32 cmmTableLookupValue(s32 , s32 , s32 );
extern void mtMiscPlayCue(s32 ); /* lint: allow H011 -- measured: retyping to the u64(s16) definition changes evtStepEventTask codegen (nd 89); keep the caller's s32 argument */
extern void evtLoadEventTables(u8 *);
extern void evtEnvSlotSave(u8 *, s32 );
extern void evtCamPosSave(u8 *);
extern void sprintf(void *, ...);
extern s32 sdkSndStreamTaskReap(s32 );
extern s32 sdkSndCreateStreamTask(s32 , s32 , s32 , void *);
extern char D_0063C340[];
extern char D_0063C380[];
extern char D_0063C350[];
s32 evtCheckCondition(u8 *);
typedef struct EvtRoomRecord {
    u8 pad00[0x10];
    s32 fieldId, roomId;
    u8 pad18[2];
    u8 room;
    u8 pad1B;
    s16 secondaryRoom;
} EvtRoomRecord;
typedef struct EvtMovieRoomSource {
    u8 pad00[0x90];
    u8 *room;
} EvtMovieRoomSource;
typedef struct EvtCondition {
    s16 index, expected;
    s8 kind;
    u8 pad05;
    u8 subtype;
    u8 pad07;
} EvtCondition;
extern u8 *MT_Scene_GetResListHead(s32 );
#pragma push
#pragma opt_loop_invariants off
// Requests the field room for the event's room record (and the secondary room when set), loading it when the room file exists [inferred].
// FUN_00285CC0
s32 evtRequestFieldRoom(u8 *source) {
    s64 room;
    s32 roomByte;
    s16 secondaryRoom;
    s32 fieldId;
    s32 roomId;
    u8 *record;

    record = ((EvtMovieRoomSource *)source)->room;
    fieldId = ((EvtRoomRecord *)record)->fieldId;
    roomId = ((EvtRoomRecord *)record)->roomId;
    roomByte = ((EvtRoomRecord *)record)->room;
    room = (s16)roomByte;
    secondaryRoom = ((EvtRoomRecord *)record)->secondaryRoom;
    if ((fieldId == 0) && (roomId == 0)) {
        return 0;
    }
    if (fieldRoomFileExists(fieldId, roomId) == 0) {
        return 0;
    }
    fieldSceneLoad(fieldId, roomId);
    fieldSceneRequestRoom(room);
    if (secondaryRoom != 0) {
        fieldSceneRequestSecondaryRoom(secondaryRoom);
    } else {
        fieldSceneRequestSecondaryRoom((s16)FldEnvStateFromCalendar(fieldId & 0xFFFF, roomId & 0xFFFF));
    }
    func_00440b68(D_0063C310, fieldId, roomId);
    return 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event task step: runs the event's state machine (stream, file and room loads) for the current state [inferred].
// FUN_00285DD0
s32 evtStepEventTask(u8 *sdkTaskBytes) {
    /* measured: remaining loader fields preserve b210 pointer/address scheduling; individual typed substitutions move instructions. */
    /* measured: remaining event-state byte accesses preserve b210 reload/address ordering; individual typed sites change instructions. */
    s32 taskAddress = (s32)sdkTaskBytes;
    u8 *data;
    u8 *entry;
    u8 *node;
    u8 *resource;
    u8 *info;
    s32 i;
    s32 flag;
    s32 result;
    char path[64];

    data = (u8 *)kwlnTaskGetWork(sdkTaskBytes);
    switch (((EvtEventWork *)data)->loadState) {
    case 0:
        *(s32 *)(data + 0x76C) = 1;
        ((EvtEventWork *)data)->loadFlags |= 2;
    case 1:
        if ((((EvtEventWork *)data)->loadFlags & 2) &&
            (((EvtEventWork *)data)->loadFlags & 1)) {
            *(s32 *)(data + 0x76C) = 2;
            *(u32 *)(data + 0x770) &= ~2;
        }
        break;
    case 2:
        *(s32 *)(data + 0x76C) = 3;
        if (((EvtEventWork *)data)->readerHandle == 0) {
            evtDestroyEventScene(data, (*(u32 *)data & 0x80000000) != 0);
            evtApplyEventBlock((EvtLoaderBlock *)data);
            *(u32 *)data |= 1;
            ((EvtEventWork *)data)->fov = K_View_GetFov(kwlnGetCamera());
            *(s32 *)(data + 0x77C) =
                evtPMFileReaderCreate(((EvtEventWork *)data)->eventId[0],
                              ((EvtEventWork *)data)->eventId[1],
                              ((EvtEventWork *)data)->eventId[2],
                              *(s32 *)(data + 0x788));
        }
    case 3:
        if (evtPMFileReaderIsDone(((EvtEventWork *)data)->readerHandle) != 0) {
            flag = (*(u32 *)data & 0x80000000) != 0;
            if (flag != 0) {
                *(s32 *)(data + 0x76C) = 4;
            } else {
                *(s32 *)(data + 0x76C) = 8;
            }
            info = evtPMFileReaderGetWork(*(s32 *)(data + 0x77C));
            ((EvtEventWork *)data)->sceneSource = evtPolygonMovieAlloc();
            evtPolygonMovieBind(data + 0x678, *(u8 **)(data + 4),
                          *(u8 **)(info + 0x34), *(u8 **)(info + 0x38),
                          *(u8 **)(info + 0x3C));
        }
        break;
    case 4:
        if (evtRequestFieldRoom(((EvtEventWork *)data)->sceneSource) != 0) {
            *(s32 *)(data + 0x76C) = 5;
        } else {
            *(s32 *)(data + 0x76C) = 8;
            break;
        }
    case 5:
        if (fieldSceneLoadStep() != 0) {
            *(s32 *)(data + 0x76C) = 8;
        }
        break;
    case 8:
        *(s32 *)(data + 0x76C) = 9;
        node = MT_Scene_GetResListHead(3);
        while (node != NULL) {
            node = (u8 *)((SceneUpdateResource *)node)->next;
        }
    case 9:
        *(s32 *)(data + 0x76C) = 10;
        ((EvtEventWork *)data)->effectTable = evtEffectTableCreate();
        i = 0;
        goto func_00285dd0_loop_check;
func_00285dd0_loop_body:
        resource = *(u8 **)(resource + 0x40);
        entry = resource + i * 0x10;
        switch (*(s32 *)(entry + 8)) {
        case 4:
            mtMiscAppendEntry(*(s32 *)(data + 0x5D0),
                          *(s32 *)(((EvtEventWork *)data)->sceneSource + 0x10) +
                              *(s32 *)(entry + 4));
            break;
        }
        i++;
func_00285dd0_loop_check:
        resource = (u8 *)((s32 *)data)[1];
        if (i < *(s32 *)(resource + 0x44)) {
            goto func_00285dd0_loop_body;
        }
        evtEffectSequenceReset(*(s32 *)(data + 0x5D0));
    case 10:
        if (evtEffectLoadStep(((EvtEventWork *)data)->effectTable) != 0) {
            *(s32 *)(data + 0x76C) = 11;
        }
        break;
    case 11:
        *(s32 *)(data + 0x76C) = 12;
        mtMiscBuildScene((s32)((EvtEventWork *)data)->sceneSource, data);
    case 12:
        *(s32 *)(data + 0x76C) = 13;
        if (((EvtEventWork *)data)->flags44 & 1) {
            if (((EvtEventWork *)data)->eventId[0] >= 500) {
                sprintf(path, D_0063C340,
                              ((EvtEventWork *)data)->eventId[0]);
            } else {
                sprintf(path, D_0063C350,
                              ((EvtEventWork *)data)->eventId[0],
                              ((EvtEventWork *)data)->eventId[1]);
            }
            ((EvtEventWork *)data)->streamTask = sdkSndCreateStreamTask(taskAddress, 2, 0, path);
        } else {
            *(s32 *)(data + 0x76C) = 14;
            break;
        }
    case 13:
        if (sdkSndStreamTaskReap(((EvtEventWork *)data)->streamTask) != 0) {
            *(s32 *)(data + 0x76C) = 14;
        }
        break;
    case 14:
        *(s32 *)(data + 0x76C) = 0;
        ((EvtEventWork *)data)->loadFlags &= ~1;
        result = mtMiscDispatchKeyAction(((EvtEventWork *)data)->eventId[0],
                               ((EvtEventWork *)data)->eventId[1]);
        if ((result != 1) && (result != 2)) {
            evtPMFileReaderGetWork(taskAddress);
            result = cmmTableLookupValue(*(s32 *)(data + 0x78C),
                                   *(s32 *)(data + 0x790),
                                   ((EvtEventWork *)data)->eventId[2]);
            if (result > 0) {
                mtMiscPlayCue(result);
            }
        }
        flag = (*(u32 *)data & 0x80000000) != 0;
        if (flag != 0) {
            evtLoadEventTables(data);
        }
        evtEnvSlotSave(data, 0);
        evtCamPosSave(data);
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event task destroy callback: releases the event, passing flag bit 31 to evtDestroy.
// FUN_00286240
void evtTaskDestroy(u8 *task) {
    s32 *p;

    p = (s32 *)kwlnTaskGetWork(task);
    if (*p & 0x80000000) {
        evtDestroy((s32)p, 1);
    } else {
        evtDestroy((s32)p, 0);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event start: creates the event task for owner and returns its id;  != 0 sets flag bit 31.
// FUN_002862A0
s32 evtStart(s32 owner, s32 loadField) {
    s32 *p;
    s32 task;

    p = (s32 *)evtCreateEventState();
    p[0x76C / 4] = 0;
    p[0x77C / 4] = owner;
    if (owner != 0) {
        p[0] |= 0x40000000;
    }
    // Event player task named D_0063C368 = "evtEditLoad" (retail string at VA 0x63C368); update is evtStepEventTask.
    task = (s32)kwlnTaskCreate((const void *)(D_0063C368), 0, 0, 0, evtStepEventTask, evtTaskDestroy, (u8 *)(p));
    if (loadField != 0) {
        p[0] |= 0x80000000;
    }
    return task;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event task lookup: returns the id of the event player task named "evtEditLoad" (D_0063C368).
// FUN_00286350
s32 evtFindTask(void) {
    return kwlnTaskGetTaskByName(D_0063C368);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Sets the load-request bit (loadFlags 0x1, +0x770); evtStepEventTask state 14 clears it.
// FUN_00286380
void evtRequestLoad(s32 task)
{
    u8 *p;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    ((EvtEventWork *)p)->loadFlags = ((EvtEventWork *)p)->loadFlags | 0x1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Returns 1 when the loader is idle (loadFlags bit 0x2, +0x770), else 0 [inferred].
// FUN_002863B0
s32 evtLoaderIsIdle(s32 task) {
    return (((EvtEventWork *)kwlnTaskGetWork((void *)task))->loadFlags & 2) != 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event id: stores the three id words (+0x78C..+0x794) that label the event.
// FUN_002863E0
void evtSetId(u32 task, s32 firstId, s32 secondId, s32 thirdId) {
    s32 *work;

    work = (s32 *)kwlnTaskGetWork((void *)task);
    ((EvtEventWork *)(u8 *)work)->eventId[0] = firstId;
    ((EvtEventWork *)(u8 *)work)->eventId[1] = secondId;
    ((EvtEventWork *)(u8 *)work)->eventId[2] = thirdId;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event condition: evaluates the supplied block; kind 0 always passes, kind 1 compares a result slot.
// FUN_00286430
s32 evtCheckCondition(u8 *key) {
    /* measured: remaining diagnostic kind load preserves b210 address scheduling. */
    s16 expected;
    u8 *ptr;
    s32 val;
    s32 a1;
    u8 subtype;
    s32 case_zero;

    a1 = 0;
    switch (((EvtCondition *)(key + 8))->kind) {
    case 0:
        return 1;
    case 1:
        expected = ((EvtCondition *)(key + 8))->expected;
        if (expected != evtResultGet(((EvtCondition *)(key + 8))->index)) {
            goto fail;
        }
        return 1;
    case 2:
        subtype = ((EvtCondition *)(key + 8))->subtype;
        if ((s32)subtype >= 3) {
            return 0;
        }
        switch (subtype) {
        case 0:
            a1 = 0;
            break;
        case 1:
            a1 = 0x400;
            break;
        case 2:
            a1 = 0x1200;
            break;
        }
        if (((EvtCondition *)(key + 8))->expected == 0) {
            case_zero = datGetFlag(((EvtCondition *)(key + 8))->index + a1) == 0;
            return case_zero;
        }
        val = datGetFlag(((EvtCondition *)(key + 8))->index + a1) == 1;
        return val;
    case 3:
        val = evtFindTask();
        if (val != 0) {
            ptr = (u8 *)kwlnTaskGetWork((void *)val);
            if (ptr != NULL) {
                return evtMessageWindowIsDone(ptr + 0x678) != 0;
            }
        }
        goto fail;
    default:
        func_00440b68(D_0063C380, *(s32 *)(key + 0x38));
        memset(key + 8, 0, 8);
        return 1;
    }
fail:
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Applies an event block to the event's state table, clearing and refilling the working copy [inferred].
// FUN_002865E0
void evtApplyEventBlock(EvtLoaderBlock *work) {
    s32 block[15];
    s32 *cursor;
    s32 *wordCount;
    s32 *secondCursor;
    s32 *secondWordCount;
    s32 source;
    s32 value;
    s32 secondValue;
    s32 remaining;
    s32 secondRemaining;

    cursor = work->loadWords;
    wordCount = block;
    remaining = 0xF;
    do {
        value = *cursor;
        cursor++;
        remaining--;
        *wordCount = value;
        wordCount++;
    } while (remaining > 0);
    source = ((EvtEventWork *)(u8 *)work)->waitFlags;
    memset(work, 0, 0x7B0);
    secondCursor = block;
    secondWordCount = (s32 *)((u8 *)work + 0x76C);
    secondRemaining = 0xF;
    do {
        secondValue = *secondCursor;
        secondCursor++;
        secondRemaining--;
        *secondWordCount = secondValue;
        secondWordCount++;
    } while (secondRemaining > 0);
    ((EvtEventWork *)(u8 *)work)->waitFlags = source;
    evtMenuClearSlots();
    ((EvtEventWork *)(u8 *)work)->waitFlags |= 1;
    ((EvtEventWork *)(u8 *)work)->frameCount = 0x21C;
    ((EvtEventWork *)(u8 *)work)->frameLimit = ((EvtEventWork *)(u8 *)work)->frameCount - 1;
    if (((EvtEventWork *)(u8 *)work)->waitFlags & 0x80000000) {
        ((EvtEventWork *)(u8 *)work)->initialized = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Appends a node to the event's node list (head and tail pointers at +0x68/+0x6C) [inferred].
// FUN_002866C0
void evtAppendNodeToList(u8 *owner, u8 *child) {
    /* measured: remaining child-list fields preserve b210 pointer reload ordering; typed substitutions move instructions. */
    /* measured: remaining child-list byte accesses preserve b210 alias-driven pointer reloads; typed sites change instructions. */
    u8 *node;
    u8 *previous;

    previous = (u8 *)((EvtNode *)owner)->childHead;
    if (previous == NULL) {
        *(u8 **)(owner + 0x68) = (u8 *)child;
        ((EvtNode *)owner)->childTail = (EvtChildNode *)((u8 *)child);
        ((EvtChildNode *)(u8 *)child)->childNext = NULL;
        ((EvtChildNode *)(u8 *)child)->childPrev = NULL;
        goto done;
    }
    goto loop_7_check;
loop_7_body:
    if ((s32)*(u16 *)child < (s32)*(u16 *)previous) {
        node = *(u8 **)(previous + 0x50);
        if (node == NULL) {
            *(u8 **)(owner + 0x68) = (u8 *)child;
            ((EvtChildNode *)previous)->childPrev = (EvtChildNode *)((u8 *)child);
            ((EvtChildNode *)(u8 *)child)->childPrev = NULL;
            ((EvtChildNode *)(u8 *)child)->childNext = (EvtChildNode *)(previous);
        } else {
            ((EvtChildNode *)node)->childNext = (EvtChildNode *)((u8 *)child);
            ((EvtChildNode *)(u8 *)child)->childPrev = ((EvtChildNode *)previous)->childPrev;
            ((EvtChildNode *)(u8 *)child)->childNext = (EvtChildNode *)(previous);
            ((EvtChildNode *)previous)->childPrev = (EvtChildNode *)((u8 *)child);
        }
        goto block_24;
    }
loop_7_next:
    previous = (u8 *)((EvtChildNode *)previous)->childNext;
loop_7_check:
    if (previous != NULL) {
        goto loop_7_body;
    }
block_24:
    if (previous != NULL) {
        goto done;
    }
    *(u8 **)((u8 *)((EvtNode *)owner)->childTail + 0x4C) = (u8 *)child;
    ((EvtChildNode *)(u8 *)child)->childPrev = ((EvtNode *)owner)->childTail;
    ((EvtChildNode *)(u8 *)child)->childNext = NULL;
    ((EvtNode *)owner)->childTail = (EvtChildNode *)((u8 *)child);
done:
    ((EvtNode *)owner)->childCount = ((EvtNode *)owner)->childCount + 1;
}
#pragma pop
