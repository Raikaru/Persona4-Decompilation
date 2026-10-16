/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00285cc0-002866c0 */

#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"
s32 kwlnTaskGetTaskByName(void *arg0);
extern s32 D_0063C368[];
extern u32 kwlnTaskGetWork(void *task);
void memset(void *arg0, s32 arg1, s32 arg2);
void evtMenuClearSlots(void);
extern s32 fieldRoomFileExists(s32 arg0, s32 arg1);
extern void fieldSceneLoad(s32 arg0, s32 arg1);
extern void fieldSceneRequestRoom(s64 arg0);
extern void fieldSceneRequestSecondaryRoom(s16 arg0);
extern s32 fieldSceneLoadStep(void);
extern void func_00440b68();
extern u8 D_0063C310[];
typedef struct {
    u8 pad[0x76C];
    s32 field_76C[15];
} UnkStruct_002865E0;

extern void evtDestroy(s32 arg0, s32 arg1);
extern u8 *evtCreateEventState(void);
extern s32 evtStepEventTask(u8 *task);
extern void evtDestroyEventScene(u8 *arg0, s32 arg1);
extern void evtApplyEventBlock(UnkStruct_002865E0 *arg0);
extern u8 *kwlnGetCamera(void);
extern f32 K_View_GetFov(u8 *arg0);
extern s32 evtPMFileReaderCreate(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 evtPMFileReaderIsDone(s32 arg0);
extern u8 *evtPMFileReaderGetWork(s32 arg0);
extern u8 *evtPolygonMovieAlloc(void);
extern u8 *evtPolygonMovieBind(u8 *messageContext, u8 *work, u8 *primary,
                         u8 *secondary, u8 *overlay);
extern s32 evtEffectTableCreate(void);
extern void mtMiscAppendEntry(s32 arg0, u32 arg1);
extern void evtEffectSequenceReset(s32 arg0);
extern s32 evtEffectLoadStep(s32 arg0);
extern void mtMiscBuildScene(s32 arg0, u8 *arg1);
extern s32 mtMiscDispatchKeyAction(s32 arg0, s32 arg1);
extern s32 cmmTableLookupValue(s32 arg0, s32 arg1, s32 arg2);
extern void mtMiscPlayCue(s32 arg0); /* lint: allow H011 -- measured: retyping to the u64(s16) definition changes evtStepEventTask codegen (nd 89); keep the caller's s32 argument */
extern void evtLoadEventTables(u8 *arg0);
extern void evtEnvSlotSave(u8 *arg0, s32 arg1);
extern void evtCamPosSave(u8 *arg0);
extern void sprintf(void *arg0, ...);
extern s32 sdkSndStreamTaskReap(s32 arg0);
extern s32 sdkSndCreateStreamTask(s32 arg0, s32 arg1, s32 arg2, void *arg3);
extern char D_0063C340[];
extern char D_0063C380[];
extern char D_0063C350[];
s32 evtCheckCondition(u8 *arg0);
extern u8 *MT_Scene_GetResListHead(s32 arg0);
#pragma push
#pragma opt_loop_invariants off
// Requests the field room for the event's room record (and the secondary room when set), loading it when the room file exists [inferred].
// FUN_00285CC0
s32 evtRequestFieldRoom(u8 *arg0) {
    s64 temp_19;
    s32 temp_19_raw;
    s16 temp_18;
    s32 temp_17;
    s32 temp_16;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x90);
    temp_17 = *(s32 *)(temp_3 + 0x10);
    temp_16 = *(s32 *)(temp_3 + 0x14);
    temp_19_raw = *(u8 *)(temp_3 + 0x1A);
    temp_19 = (s16)temp_19_raw;
    temp_18 = *(s16 *)(temp_3 + 0x1C);
    if ((temp_17 == 0) && (temp_16 == 0)) {
        return 0;
    }
    if (fieldRoomFileExists(temp_17, temp_16) == 0) {
        return 0;
    }
    fieldSceneLoad(temp_17, temp_16);
    fieldSceneRequestRoom(temp_19);
    if (temp_18 != 0) {
        fieldSceneRequestSecondaryRoom(temp_18);
    } else {
        fieldSceneRequestSecondaryRoom((s16)FldEnvStateFromCalendar(temp_17 & 0xFFFF, temp_16 & 0xFFFF));
    }
    func_00440b68(D_0063C310, temp_17, temp_16);
    return 1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event task step: runs the event's state machine (stream, file and room loads) for the current state [inferred].
// FUN_00285DD0
s32 evtStepEventTask(u8 *sdkTaskBytes) {
    s32 arg0 = (s32)sdkTaskBytes;
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
    switch (*(s32 *)(data + 0x76C)) {
    case 0:
        *(s32 *)(data + 0x76C) = 1;
        *(u32 *)(data + 0x770) |= 2;
    case 1:
        if ((*(u32 *)(data + 0x770) & 2) &&
            (*(u32 *)(data + 0x770) & 1)) {
            *(s32 *)(data + 0x76C) = 2;
            *(u32 *)(data + 0x770) &= ~2;
        }
        break;
    case 2:
        *(s32 *)(data + 0x76C) = 3;
        if (*(s32 *)(data + 0x77C) == 0) {
            evtDestroyEventScene(data, (*(u32 *)data & 0x80000000) != 0);
            evtApplyEventBlock((UnkStruct_002865E0 *)data);
            *(u32 *)data |= 1;
            *(f32 *)(data + 0x750) = K_View_GetFov(kwlnGetCamera());
            *(s32 *)(data + 0x77C) =
                evtPMFileReaderCreate(*(s32 *)(data + 0x78C),
                              *(s32 *)(data + 0x790),
                              *(s32 *)(data + 0x794),
                              *(s32 *)(data + 0x788));
        }
    case 3:
        if (evtPMFileReaderIsDone(*(s32 *)(data + 0x77C)) != 0) {
            flag = (*(u32 *)data & 0x80000000) != 0;
            if (flag != 0) {
                *(s32 *)(data + 0x76C) = 4;
            } else {
                *(s32 *)(data + 0x76C) = 8;
            }
            info = evtPMFileReaderGetWork(*(s32 *)(data + 0x77C));
            *(u8 **)(data + 4) = evtPolygonMovieAlloc();
            evtPolygonMovieBind(data + 0x678, *(u8 **)(data + 4),
                          *(u8 **)(info + 0x34), *(u8 **)(info + 0x38),
                          *(u8 **)(info + 0x3C));
        }
        break;
    case 4:
        if (evtRequestFieldRoom(*(u8 **)(data + 4)) != 0) {
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
            node = *(u8 **)(node + 0x138);
        }
    case 9:
        *(s32 *)(data + 0x76C) = 10;
        *(s32 *)(data + 0x5D0) = evtEffectTableCreate();
        i = 0;
        goto func_00285dd0_loop_check;
func_00285dd0_loop_body:
        resource = *(u8 **)(resource + 0x40);
        entry = resource + i * 0x10;
        switch (*(s32 *)(entry + 8)) {
        case 4:
            mtMiscAppendEntry(*(s32 *)(data + 0x5D0),
                          *(s32 *)(*(u8 **)(data + 4) + 0x10) +
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
        if (evtEffectLoadStep(*(s32 *)(data + 0x5D0)) != 0) {
            *(s32 *)(data + 0x76C) = 11;
        }
        break;
    case 11:
        *(s32 *)(data + 0x76C) = 12;
        mtMiscBuildScene(*(s32 *)(data + 4), data);
    case 12:
        *(s32 *)(data + 0x76C) = 13;
        if (*(s8 *)(data + 0x44) & 1) {
            if (*(s32 *)(data + 0x78C) >= 500) {
                sprintf(path, D_0063C340,
                              *(s32 *)(data + 0x78C));
            } else {
                sprintf(path, D_0063C350,
                              *(s32 *)(data + 0x78C),
                              *(s32 *)(data + 0x790));
            }
            *(s32 *)(data + 0x780) = sdkSndCreateStreamTask(arg0, 2, 0, path);
        } else {
            *(s32 *)(data + 0x76C) = 14;
            break;
        }
    case 13:
        if (sdkSndStreamTaskReap(*(s32 *)(data + 0x780)) != 0) {
            *(s32 *)(data + 0x76C) = 14;
        }
        break;
    case 14:
        *(s32 *)(data + 0x76C) = 0;
        *(u32 *)(data + 0x770) &= ~1;
        result = mtMiscDispatchKeyAction(*(s32 *)(data + 0x78C),
                               *(s32 *)(data + 0x790));
        if ((result != 1) && (result != 2)) {
            evtPMFileReaderGetWork(arg0);
            result = cmmTableLookupValue(*(s32 *)(data + 0x78C),
                                   *(s32 *)(data + 0x790),
                                   *(s32 *)(data + 0x794));
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
// Event start: creates the event task for owner 'arg0' and returns its id; arg1 != 0 sets flag bit 31.
// FUN_002862A0
s32 evtStart(s32 arg0, s32 arg1) {
    s32 *p;
    s32 task;

    p = (s32 *)evtCreateEventState();
    p[0x76C / 4] = 0;
    p[0x77C / 4] = arg0;
    if (arg0 != 0) {
        p[0] |= 0x40000000;
    }
    // Event player task named D_0063C368 = "evtEditLoad" (retail string at VA 0x63C368); update is evtStepEventTask.
    task = (s32)kwlnTaskCreate((const void *)(D_0063C368), 0, 0, 0, evtStepEventTask, evtTaskDestroy, (u8 *)(p));
    if (arg1 != 0) {
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
    *(s32 *)(p + 0x770) = *(s32 *)(p + 0x770) | 0x1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Returns 1 when the loader is idle (loadFlags bit 0x2, +0x770), else 0 [inferred].
// FUN_002863B0
s32 evtLoaderIsIdle(s32 task) {
    return (*(s32 *)((u8 *)kwlnTaskGetWork((void *)task) + 0x770) & 2) != 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event id: stores the three id words (+0x78C..+0x794) that label the event.
// FUN_002863E0
void evtSetId(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_2;

    temp_2 = (s32 *)kwlnTaskGetWork((void *)arg0);
    *(s32 *)((u8 *)temp_2 + 0x78C) = arg1;
    *(s32 *)((u8 *)temp_2 + 0x790) = arg2;
    *(s32 *)((u8 *)temp_2 + 0x794) = arg3;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Event condition: evaluates the block at 'arg0'; kind 0 always passes, kind 1 compares a result slot.
// FUN_00286430
s32 evtCheckCondition(u8 *arg0) {
    s16 expected;
    u8 *ptr;
    s32 val;
    s32 a1;
    u8 subtype;
    s32 case_zero;

    a1 = 0;
    switch (*(s8 *)(arg0 + 0xC)) {
    case 0:
        return 1;
    case 1:
        expected = *(s16 *)(arg0 + 0xA);
        if (expected != evtResultGet(*(s16 *)(arg0 + 8))) {
            goto fail;
        }
        return 1;
    case 2:
        subtype = *(u8 *)(arg0 + 0xE);
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
        if (*(s16 *)(arg0 + 0xA) == 0) {
            case_zero = datGetFlag(*(s16 *)(arg0 + 8) + a1) == 0;
            return case_zero;
        }
        val = datGetFlag(*(s16 *)(arg0 + 8) + a1) == 1;
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
        func_00440b68(D_0063C380, *(s32 *)(arg0 + 0x38));
        memset(arg0 + 8, 0, 8);
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
void evtApplyEventBlock(UnkStruct_002865E0 *arg0) {
    s32 sp30[15];
    s32 *var_5;
    s32 *var_4;
    s32 *var_5_2;
    s32 *var_4_2;
    s32 temp_17;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_3;
    s32 var_3_2;

    var_5 = arg0->field_76C;
    var_4 = sp30;
    var_3 = 0xF;
    do {
        temp_2 = *var_5;
        var_5++;
        var_3--;
        *var_4 = temp_2;
        var_4++;
    } while (var_3 > 0);
    temp_17 = *(s32 *)((u8 *)arg0 + 0);
    memset(arg0, 0, 0x7B0);
    var_5_2 = sp30;
    var_4_2 = (s32 *)((u8 *)arg0 + 0x76C);
    var_3_2 = 0xF;
    do {
        temp_2_2 = *var_5_2;
        var_5_2++;
        var_3_2--;
        *var_4_2 = temp_2_2;
        var_4_2++;
    } while (var_3_2 > 0);
    *(s32 *)((u8 *)arg0 + 0) = temp_17;
    evtMenuClearSlots();
    *(s32 *)((u8 *)arg0 + 0) |= 1;
    *(s32 *)((u8 *)arg0 + 8) = 0x21C;
    *(s32 *)((u8 *)arg0 + 0x10) = *(s32 *)((u8 *)arg0 + 8) - 1;
    if (*(s32 *)((u8 *)arg0 + 0) & 0x80000000) {
        *(s32 *)((u8 *)arg0 + 0x54) = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Appends a node to the event's node list (head and tail pointers at +0x68/+0x6C) [inferred].
// FUN_002866C0
void evtAppendNodeToList(u8 *arg0, u8 *arg1) {
    u8 *temp_3;
    u8 *var_7;

    var_7 = *(u8 **)(arg0 + 0x68);
    if (var_7 == NULL) {
        *(u8 **)(arg0 + 0x68) = (u8 *)arg1;
        *(u8 **)(arg0 + 0x6C) = (u8 *)arg1;
        *(u8 **)((u8 *)arg1 + 0x4C) = NULL;
        *(u8 **)((u8 *)arg1 + 0x50) = NULL;
        goto done;
    }
    goto loop_7_check;
loop_7_body:
    if ((s32)*(u16 *)arg1 < (s32)*(u16 *)var_7) {
        temp_3 = *(u8 **)(var_7 + 0x50);
        if (temp_3 == NULL) {
            *(u8 **)(arg0 + 0x68) = (u8 *)arg1;
            *(u8 **)(var_7 + 0x50) = (u8 *)arg1;
            *(u8 **)((u8 *)arg1 + 0x50) = NULL;
            *(u8 **)((u8 *)arg1 + 0x4C) = var_7;
        } else {
            *(u8 **)(temp_3 + 0x4C) = (u8 *)arg1;
            *(u8 **)((u8 *)arg1 + 0x50) = *(u8 **)(var_7 + 0x50);
            *(u8 **)((u8 *)arg1 + 0x4C) = var_7;
            *(u8 **)(var_7 + 0x50) = (u8 *)arg1;
        }
        goto block_24;
    }
loop_7_next:
    var_7 = *(u8 **)(var_7 + 0x4C);
loop_7_check:
    if (var_7 != NULL) {
        goto loop_7_body;
    }
block_24:
    if (var_7 != NULL) {
        goto done;
    }
    *(u8 **)(*(u8 **)(arg0 + 0x6C) + 0x4C) = (u8 *)arg1;
    *(u8 **)((u8 *)arg1 + 0x50) = *(u8 **)(arg0 + 0x6C);
    *(u8 **)((u8 *)arg1 + 0x4C) = NULL;
    *(u8 **)(arg0 + 0x6C) = (u8 *)arg1;
done:
    *(s32 *)(arg0 + 0x64) = *(s32 *)(arg0 + 0x64) + 1;
}
#pragma pop
