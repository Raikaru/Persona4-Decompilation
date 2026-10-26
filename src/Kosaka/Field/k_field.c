#include "evt_internal.h"
#include "scr_context_internal.h"
#include "member_access.h"
#include "field_scene_internal.h"
#include "field_frame_internal.h"
#include "resrc_manager_internal.h"
#include "h_cdvd_request_internal.h"
#include "rw_frame_internal.h"
#include "Kosaka/k_fldStep_internal.h"
#include "mt_scene_internal.h"
#include "field_transition_internal.h"
/* Original translation unit k_field.c (from __FILE__ assert strings). */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdktask.h"

extern s32 iGpffffb20c;
extern s32 iGpffffb2e4;
extern u8 *iGpffff9db0;
extern s32 D_007E8060[];
extern u8 D_007E80A0[];
extern s32 D_007D2510[];

#define KFIELD_D_007D2540 (*(s32 *)0x007D2540)
#define KFIELD_D_007E8060 (D_007E8060)
#define KFIELD_D_007E80A0 (D_007E80A0)
#define KFIELD_D_007D2510 (D_007D2510)
#define KFIELD_JTBL_008873EC (*(void (**)(s32))((u8 *)0x00880000 + 0x73EC))

extern void calendarPopValue(void);
extern void FldUnit_ClearFlagBlock(void);
extern void fclMiscStopAndClose(void);
extern void fclMiscPruneGlobal(void);
extern void resrcMngSelectDrawSet(s32);
extern void kwlnTaskDestroyWithHierarchy(s32);
extern void FldResource_Destroy(s32);
extern s32 kwlnGetCurrentWorkValue(void);
extern void FldSlotTablesReset(void);
extern void FldUnit_ReleaseGroupSlots(void);
extern void FldUnit_ReleaseAllSlots(void);
extern void memset(void *, s32, s32);
extern void FldLoadTaskUnloadScene(u8 *);
extern u8 *kwlnGetCamera(void);
extern void func_003e9df0(s32);

/* Kept as ASM: retail moves task before loading field/room, which the C reconstruction does not
 * reproduce. */
typedef struct KFieldStateWork {
    s32 state;
    u8 reserved04[4];
    s32 exitRequested;
    s32 eventId;
    s32 eventMajor;
    s32 eventMinor;
    u16 field;
    u16 room;
    u16 entry;
    u8 reserved1e[2];
    s16 spawn;
    s16 direction;
    u8 reserved24[8];
    u8 *roomData;
    s32 loadTask;
    u8 reserved34[8];
    s32 eventReader;
    s32 eventTask;
    s32 scriptTask;
    u8 reserved48[4];
    s32 model;
    u8 reserved50[0x88];
    u8 transition[0x1C];
} KFieldStateWork;

extern s32 iGpffffb210;
extern s32 iGpffffb268;
extern u8 D_005EFF10[];
extern u8 D_005EFF20[];
extern u8 *D_007D3D64[];
extern s32 D_007D3D68[];
extern s32 D_007D2514[];
extern s32 D_007D2518[];
extern s32 D_007D2528[];
extern s32 D_007D252C[];
extern s32 D_007D2530[];
extern s32 D_007D253C[];
extern u16 *D_007EFA04[];
extern s32 datGetFlag(s32);
extern void loadingSpinnerRequestShow(void);
extern void loadingSpinnerRequestHide(void);
extern s32 evtPMFileReaderIsDone(s32);
extern s32 evtPMFileReaderGetFirstEntry(s32, s32 *, s32 *, s32 *, s32 *);
extern void kAssertFail(const void *, s32);
extern void FldResource_OpenPrimaryFile(u16, u16);
extern void FldPartyModelRelease(s32);
extern void fadeBegin(void);
extern void FldUnit_SpawnAtEntry(u16, u16, u16);
extern void resrcMngSetRenderSuppressed(s32);
extern s32 FldLoadTaskCreate(u8 *, u16, u16, s16, s16, s32, s32, s32);
extern s32 FldUnit_UpdateTable(void);
extern s32 kwlnTaskIsLinked(s32);
extern s32 FldFilterGetEntry(void);
extern void FldUnit_UpdateFacing(void);
extern void FldUnit_RequestSceneResource(void);
extern s32 FldMap_IsCurrentInEitherBand(void);
extern s32 sprintf(char *, const void *, ...);
extern void *mdlCreateModelObjectFromData(u32, u16, void *, u32);
extern s32 FldUnit_InstallResources(void);
extern s32 mdlPrepareModel(s32);
extern s32 fadeIsIdle(void);
extern s32 evtCreateEventTask(s32, s32, s32); /* lint: allow H011 -- caller stores the returned handle; the definition takes two arguments and ignores the third */
extern void FldFrame_BindTypedRes(s32, u16);
extern void FldFrame_RotateTaskCreate(u8 *, s32, s32);
extern u16 MT_Scene_FindFreeResId(s32);
extern s32 MT_Scene_CreateModelFldRes(u16, s32);
extern void SceneDraw_SetResVisible(u16, s32);
extern void fldBoardGetOccupiedCenter(f32 *);
extern void mdlTranslateMatrix(s32, f32 *, s32);
extern s32 scrStartProcedureIndex(s32, u8 *, s32);
extern s32 FldMap_IsCurrentInBandA(void);
extern u8 *FldStepEntry(void);
extern u8 *FldStepLoadNumberedFile(u8);
extern s32 FldStepLoadIdIsDone(u8 *);
extern s32 FldStepIndex(void);
extern s32 FldStepTableEntryFlag(s32);
extern void FldUnit_UpdateAllEnemySlots(void);
extern void FldUnit_UpdateEnemySlot(void);
extern s32 FldUnit_SpawnEncounterTask(u8 *, s32);
extern s32 FldMap_IsCurrentInBandB(void);
extern s32 smapCreateSymbols(u8 *);
extern void ySymbolSetEnabled(s32);
extern s32 sndRequestAreaTrack(void);
extern void sndPlayAreaCue(void);
extern void FldPanel2dTaskCreate(void);
extern s32 FldUnit_IsSettled(s32);
extern void fadeBeginReturnTransition(s32, s32);
extern s32 fadeStatus(void);
extern s32 scrStartProcedureChecked(s32, u8 *, s32, s32);
extern void H_Cdvd_Destroy(u8 *);
extern void MT_Scene_SetFadeForState(u16, u16);
extern s32 FldSupporterTaskCreate(u8 *);
extern s32 FldEvent_SpawnTrigger(u8 *);
extern void FldSlotBroadcastState(s32);
extern s32 evtMainIsFlagSet(void);
extern void sequenceRequest(s32, void *, s32, s32);

#pragma opt_propagation off
/* Advance field loading, scripts and task creation, then wait for an exit or event completion. */
/* Resource flags, step-file selection and CDVD payloads use their shared storage layouts. */
// FUN_00155360
s32 FldRootUpdate(u8 *task)
{
    s32 field;
    s32 room;
    s32 spawn;
    s32 direction;
    f32 position[3];
    char filename[32];
    s32 index;
    s32 eventMode;
    s32 scriptSize;
    s32 model;
    u16 modelId;
    u16 modelField;
    u8 *object;
    KFieldStateWork *work;

    work = (KFieldStateWork *)((SdkTask *)task)->work;
    if (work->state > 2 && work->state < 11 && datGetFlag(0x1470) == 0) {
        loadingSpinnerRequestShow();
    }
    switch (work->state) {
    case 0:
        if (evtPMFileReaderIsDone(work->eventReader) != 0) {
            if (evtPMFileReaderGetFirstEntry(work->eventReader, &field, &room, &spawn, &direction) == 1) {
                if (field == 0) {
                    kAssertFail(D_005EFF10, 0xD6);
                }
                work->field = field;
                work->room = room;
                work->spawn = spawn;
                work->direction = direction;
                FldResource_OpenPrimaryFile(work->field, work->room);
                for (index = 0; index < 4; index++) {
                    FldPartyModelRelease(index);
                }
                fadeBegin();
                work->state = 2;
            } else {
                kAssertFail(D_005EFF10, 0xE8);
            }
        }
        break;
    case 1:
        fadeBegin();
        work->state++;
        /* fallthrough */
    case 2:
        if (work->eventReader == 0) {
            FldUnit_SpawnAtEntry(work->field, work->room, work->entry);
        }
        resrcMngSetRenderSuppressed(1);
        eventMode = work->eventReader != 0;
        work->loadTask = FldLoadTaskCreate(task, work->field, work->room, work->spawn,
            work->direction, eventMode, work->eventId, work->eventMajor);
        work->state++;
        /* fallthrough */
    case 3:
        if (FldUnit_UpdateTable() != 0 && kwlnTaskIsLinked(work->loadTask) != 1) {
            if (FldFilterGetEntry() == 3) {
                resrcMngSelectDrawSet(1);
            }
            work->state = 4;
        }
        break;
    case 4:
        FldUnit_UpdateFacing();
        if (work->eventReader == 0) {
            FldUnit_RequestSceneResource();
            if (FldMap_IsCurrentInEitherBand() == 1) {
                modelField = work->field;
                if (modelField == 0x2C || modelField == 0x2E || modelField == 0x2F ||
                    modelField == 0x30 || modelField == 0x40 || modelField == 0x42 ||
                    modelField == 0x43 || modelField == 0x44) {
                    sprintf(filename, D_005EFF20,
                        modelField < 0x32 ? modelField : modelField - 0x14);
                    work->model = (s32)mdlCreateModelObjectFromData(4, 0xFFFD, filename, 0);
                }
            }
        }
        work->state++;
        break;
    case 5:
        if (FldUnit_InstallResources() == 0) break;
        if (work->model != 0 && mdlPrepareModel(work->model) == 0) break;
        if (work->eventReader != 0) {
            if (fadeIsIdle() != 0) {
                resrcMngSetRenderSuppressed(0);
                loadingSpinnerRequestHide();
                work->eventTask = evtCreateEventTask(work->eventId, work->eventMajor, work->eventMinor);
                work->state = 14;
            }
        } else {
            FldFrame_BindTypedRes(D_007D2514[0], *D_007EFA04[0]);
            FldFrame_RotateTaskCreate(task, 1, -1);
            model = work->model;
            if (model != 0) {
                modelId = MT_Scene_CreateModelFldRes(MT_Scene_FindFreeResId(10), model);
                SceneDraw_SetResVisible(modelId, 1);
                fldBoardGetOccupiedCenter(position);
                mdlTranslateMatrix(work->model, position, 2);
                object = MT_Scene_GetRes(modelId);
                ((ResrcRecord *)(object))->unk28 |= 0x02000000;
            }
            work->state++;
        }
        break;
    case 6:
        if (fadeIsIdle() != 0) {
            resrcMngSetRenderSuppressed(0);
            iGpffffb210 = 2;
            if (work->eventReader == 0) {
                if (D_007D3D64[0] != NULL && iGpffffb268 == 0) {
                    work->scriptTask = scrStartProcedureIndex(15, D_007D3D64[0], work->room - 1);
                }
                if (FldMap_IsCurrentInBandA() == 1) {
                    work->roomData = FldStepLoadNumberedFile(((FldStepRecord *)(FldStepEntry()))->fileId);
                }
            }
            work->state++;
        }
        break;
    case 7:
        if (work->eventReader == 0 && work->scriptTask != 0 && kwlnTaskIsLinked(work->scriptTask) == 1) break;
        work->state++;
        /* fallthrough */
    case 8:
        if (FldStepLoadIdIsDone(work->roomData) == 0) break;
        work->state++;
        /* fallthrough */
    case 9:
        if (FldStepTableEntryFlag(FldStepIndex()) != 0) {
            FldUnit_UpdateAllEnemySlots();
        } else {
            FldUnit_UpdateEnemySlot();
        }
        D_007D2530[0] = FldUnit_SpawnEncounterTask(task, -1);
        if ((FldMap_IsCurrentInBandA() == 1 || FldMap_IsCurrentInBandB() == 1) &&
            (((FieldSceneState *)(iGpffff9db0))->field.value != 0x44 || ((FieldSceneState *)(iGpffff9db0))->room.value != 1)) {
            D_007D2528[0] = smapCreateSymbols(task);
            ySymbolSetEnabled(1);
        }
        if (FldStepIndex() != 0) {
            D_007D253C[0] = FldNoiseTaskCreate(task);
        }
        if (sndRequestAreaTrack() == 0) {
            sndPlayAreaCue();
        }
        FldPanel2dTaskCreate();
        work->state++;
        /* fallthrough */
    case 10:
        if (FldUnit_IsSettled(D_007D2530[0]) == 0) break;
        loadingSpinnerRequestHide();
        fadeBeginReturnTransition(1, 0);
        work->state++;
        /* fallthrough */
    case 11:
        if (fadeStatus() == 0) break;
        iGpffffb210 = 3;
        if (FldMap_IsCurrentInBandA() == 1) {
            work->scriptTask = scrStartProcedureChecked(15, (u8 *)((HCdvdRequest *)(work->roomData))->data,
                ((HCdvdRequest *)(work->roomData))->signedSize, 0);
        } else if (D_007D3D64[0] != NULL && iGpffffb268 == 0) {
            scriptSize = D_007D3D68[0];
            work->scriptTask = scrStartProcedureChecked(15, D_007D3D64[0], scriptSize, work->room - 1);
        }
        work->state++;
        /* fallthrough */
    case 12:
        if (work->scriptTask != 0) {
            if (kwlnTaskIsLinked(work->scriptTask) == 1) break;
            if (work->roomData != NULL) {
                H_Cdvd_Destroy(work->roomData);
                work->roomData = NULL;
            }
        }
        MT_Scene_SetFadeForState(work->field, work->room);
        D_007D252C[0] = FldSupporterTaskCreate(task);
        D_007D2518[0] = FldEvent_SpawnTrigger(task);
        FldSlotBroadcastState(0);
        work->state++;
        /* fallthrough */
    case 13:
        if (work->exitRequested != 0) {
            work->state = 18;
        }
        break;
    case 14:
        if (kwlnTaskIsLinked(work->eventTask) != 1 && evtMainIsFlagSet() == 0) {
            work->state = 18;
        }
        break;
    case 17:
        if (fadeStatus() != 0) {
            sequenceRequest(9, work->transition, 0x1C, 0);
            work->state++;
        }
        break;
    case 18:
        D_007D2510[0] = 0;
        return -1;
    }
    return 0;
}

#pragma opt_propagation on


/* measured: the second range check is written as <= 0x1E because that gives retail's branch
 * temporary. Releases field resources and dependent tasks before resetting the camera frame. */
/* Tear down the field scene: release the event reader and its resources, slot tables, loaded scene,
 * and dependent frame tasks, then reset the camera frame. */
// FUN_00155BF0
void FldRootDestroy(u8 *task)
{
    KFieldStateWork *stateWork;
    u8 *work;
    s32 eventReader;
    s32 resource;
    s32 childTask;
    s32 offset;
    s32 *resourceSlot;
    s32 *frameSlot;
    s32 resourceIndex;

    work = ((SdkTask *)(task))->work;
    stateWork = (KFieldStateWork *)work;
    if (iGpffffb20c == 1) {
        calendarPopValue();
    }
    FldUnit_ClearFlagBlock();
    fclMiscStopAndClose();
    fclMiscPruneGlobal();
    KFIELD_D_007D2540 = 0;
    resrcMngSelectDrawSet(0);
    eventReader = ((KFieldStateWork *)(work))->eventReader;
    if (eventReader != 0) {
        kwlnTaskDestroyWithHierarchy(eventReader);
        resourceIndex = 0;
        while (resourceIndex < 0x10) {
            offset = resourceIndex * 4;
            resourceSlot = (s32 *)KFIELD_D_007E8060 + resourceIndex;
            resource = *resourceSlot;
            if (resource != 0) {
                FldResource_Destroy(resource);
                *resourceSlot = 0;
                ((FieldSceneState *)(iGpffff9db0 + offset))->templates[0].signedAddress = 0;
            }
            resourceIndex += 1;
        }
    }
    if (kwlnGetCurrentWorkValue() != 9 &&
        kwlnGetCurrentWorkValue() != 0xB &&
        kwlnGetCurrentWorkValue() != 0xA) {
        FldSlotTablesReset();
    }
    if ((u16)stateWork->field < 0x15) {
        goto field_special;
    }
    if (((KFieldStateWork *)(work))->field <= 0x1E) {
        goto field_call;
    }
field_special:
    if (stateWork->field != 6) {
        goto field_done;
    }
    if (((KFieldStateWork *)(work))->room != 1) {
        goto field_done;
    }
field_call:
    FldSlotTablesReset();
field_done:
    FldUnit_ReleaseGroupSlots();
    FldUnit_ReleaseAllSlots();
    memset(KFIELD_D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    FldLoadTaskUnloadScene(task);
    offset = 0;
    while (offset < 3) {
        frameSlot = (s32 *)KFIELD_D_007D2510 + offset;
        childTask = MEMBER(s32, (u8 *)frameSlot, FldFrame, dependentTasks[0]);
        if (childTask != 0) {
            kwlnTaskDestroyWithHierarchy(childTask);
            MEMBER(s32, (u8 *)frameSlot, FldFrame, dependentTasks[0]) = 0;
        }
        offset += 1;
    }
    func_003e9df0((s32)((RwCamera *)(kwlnGetCamera()))->object.object.parent);
    KFIELD_JTBL_008873EC(MEMBER(s32, task, SdkTask, work));
}

extern void kwlnTaskDumpAll(void);
extern u8 *D_007D3D64[];
extern u8 D_005EFF10[];
extern u8 D_005EFF48[];
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void resrcMngSetRenderSuppressed(s32 );
extern s32 evtPMFileReaderCreate(s32 eventId, s32 variantId, s32 value, s32 useAllocatedTables);
extern void FldResource_OpenPrimaryFile(u16 , u16 );
extern u8 D_007D255A[];
extern u8 D_007D255B[];
extern s32 D_007D255C[];
typedef struct { f32 x; f32 y; f32 z; } KFieldVec3;
extern s64 D_005EFF38[];
extern f32 D_005EFF40[];
extern void RwEngineGetMatrixTolerances(f32 *);
extern void RwMatrixOptimize(void *, f32 *);
extern void func_003e9680(void *);
extern s32 FldRootUpdate(u8 *);
/* measured: stack parameters are read in place through casts because retail reloads each one at
 * every use. */
// FUN_00155E10
/* measured: opt_propagation off keeps the scalar-pair copy's two loads ahead of its two stores, as
 * retail does. */
#pragma opt_propagation off
/* Allocate the field controller, select event-driven or direct entry, and reset camera placement.
 * The position locals have their address taken so they are kept as separate stack values and
 * reloaded from the stack. */
s32 FldRootCreate(u8 *parent, u16 field, u16 room, u16 entry, s16 spawn, s16 direction, s32 sceneFlags, u8 loadMode,
                  s64 secondaryMode, s64 transitionValue, s64 eventId, s64 eventMajor, s64 eventMinor, s64 eventFlags)
{
    f32 matrix[4];
    KFieldVec3 pos;
    s32 handle;
    u8 *work;
    s64 positionXY;
    f32 positionZ;
    u8 *cam;

    kwlnTaskDumpAll();
    if (D_007D3D64[0] != NULL) {
        KFIELD_JTBL_008873EC((s32)D_007D3D64[0]);
    }
    memset(D_007D2510, 0, 0x18DC);
    chkmemAllocSiteTag(D_005EFF10, 0x2AF);
    work = D_008873F4[0](1, 0xF4, 0x40000);
    if (work == NULL) {
        return 0;
    }
    handle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005EFF48), 0xF, 0, 0, FldRootUpdate, FldRootDestroy, (u8 *)(work));
    D_007D2510[0] = handle;
    resrcMngSetRenderSuppressed(0);
    if (*(s32 *)&eventId > 0) {
        ((KFieldStateWork *)work)->eventReader = evtPMFileReaderCreate(*(s32 *)&eventId, *(s32 *)&eventMajor, *(s32 *)&eventMinor, *(s32 *)&eventFlags);
        ((KFieldStateWork *)work)->state = 0;
        ((KFieldStateWork *)work)->eventId = *(s32 *)&eventId;
        ((KFieldStateWork *)work)->eventMajor = *(s32 *)&eventMajor;
        ((KFieldStateWork *)work)->eventMinor = *(s32 *)&eventMinor;
    } else {
        scrDebugDumpWorkList(*(s32 *)&eventId);
        ((KFieldStateWork *)work)->field = field;
        ((KFieldStateWork *)work)->room = room;
        ((KFieldStateWork *)work)->spawn = spawn;
        ((KFieldStateWork *)work)->direction = direction;
        ((KFieldStateWork *)work)->entry = entry;
        ((FieldSceneState *)(iGpffff9db0))->sceneFlags = sceneFlags;
        D_007D255A[0] = loadMode;
        D_007D255B[0] = *(u8 *)&secondaryMode;
        D_007D255C[0] = *(s32 *)&transitionValue;
        FldResource_OpenPrimaryFile(field, room);
        ((KFieldStateWork *)work)->state = 1;
    }
    positionXY = D_005EFF38[0];
    positionZ = D_005EFF40[0];
    *(s64 *)&pos.x = positionXY;
    pos.z = positionZ;
    func_003e9df0((s32)((RwCamera *)(kwlnGetCamera()))->object.object.parent);
    cam = (u8 *)((RwCamera *)(kwlnGetCamera()))->object.object.parent;
    *(KFieldVec3 *)&((RwFrame *)(cam))->modelling.pos = pos;
    RwEngineGetMatrixTolerances(matrix);
    RwMatrixOptimize((u8 *)((RwCamera *)(kwlnGetCamera()))->object.object.parent + 0x10, matrix);
    func_003e9680((u8 *)((RwCamera *)(kwlnGetCamera()))->object.object.parent);
    return handle;
}

#pragma opt_propagation on
