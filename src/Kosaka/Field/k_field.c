#include "mt_scene_internal.h"
#include "field_transition_internal.h"
/* Original translation unit k_field.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"

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
extern void func_002bd410(void);
extern void func_002bd3e0(void);
extern void resrcMngSelectDrawSet(s32);
extern void kwlnTaskDestroyWithHierarchy(s32);
extern void FldResource_Destroy(s32);
extern s32 func_00102980(void);
extern void FldSlotTablesReset(void);
extern void FldUnit_ReleaseGroupSlots(void);
extern void FldUnit_ReleaseAllSlots(void);
extern void memset(void *, s32, s32);
extern void FldLoadTaskUnloadScene(u8 *);
extern u8 *kwlnGetCamera(void);
extern void func_003e9df0(s32);

/* Fresh reconstruction retained in FFS_00155360_body.c: 2192/2192 bytes,
   112 resolved code relocations and all 19 switch targets match except the
   three argument-setup instructions at +0x1B0..+0x1B8. Retail moves task
   before loading field/room; the candidate loads them first. Remains ASM. */
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
extern s32 func_00293fc0(s32);
extern s32 func_002940a0(s32, s32 *, s32 *, s32 *, s32 *);
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
extern void func_0015a350(f32 *);
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
extern void func_002b2950(s32);
extern s32 sndRequestAreaTrack(void);
extern void sndPlayAreaCue(void);
extern void func_00189ec0(void);
extern s32 FldUnit_IsSettled(s32);
extern void func_00122640(s32, s32);
extern s32 fadeStatus(void);
extern s32 scrStartProcedureChecked(s32, u8 *, s32, s32);
extern void H_Cdvd_Destroy(u8 *);
extern void MT_Scene_SetFadeForState(u16, u16);
extern s32 func_0018df60(u8 *);
extern s32 FldEvent_SpawnTrigger(u8 *);
extern void FldSlotBroadcastState(s32);
extern s32 func_0028b260(void);
extern void func_001029a0(s32, void *, s32, s32);

#pragma opt_propagation off
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

    work = *(KFieldStateWork **)(task + 0x38);
    if (work->state > 2 && work->state < 11 && datGetFlag(0x1470) == 0) {
        loadingSpinnerRequestShow();
    }
    switch (work->state) {
    case 0:
        if (func_00293fc0(work->eventReader) != 0) {
            if (func_002940a0(work->eventReader, &field, &room, &spawn, &direction) == 1) {
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
                func_0015a350(position);
                mdlTranslateMatrix(work->model, position, 2);
                object = MT_Scene_GetRes(modelId);
                *(u32 *)(object + 0x28) |= 0x02000000;
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
                    work->roomData = FldStepLoadNumberedFile(*(u8 *)(FldStepEntry() + 0xC));
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
            (*(s32 *)(iGpffff9db0 + 0) != 0x44 || *(s32 *)(iGpffff9db0 + 4) != 1)) {
            D_007D2528[0] = smapCreateSymbols(task);
            func_002b2950(1);
        }
        if (FldStepIndex() != 0) {
            D_007D253C[0] = FldNoiseTaskCreate(task);
        }
        if (sndRequestAreaTrack() == 0) {
            sndPlayAreaCue();
        }
        func_00189ec0();
        work->state++;
        /* fallthrough */
    case 10:
        if (FldUnit_IsSettled(D_007D2530[0]) == 0) break;
        loadingSpinnerRequestHide();
        func_00122640(1, 0);
        work->state++;
        /* fallthrough */
    case 11:
        if (fadeStatus() == 0) break;
        iGpffffb210 = 3;
        if (FldMap_IsCurrentInBandA() == 1) {
            work->scriptTask = scrStartProcedureChecked(15, *(u8 **)(work->roomData + 0x110),
                *(s32 *)(work->roomData + 0x118), 0);
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
        D_007D252C[0] = func_0018df60(task);
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
        if (kwlnTaskIsLinked(work->eventTask) != 1 && func_0028b260() == 0) {
            work->state = 18;
        }
        break;
    case 17:
        if (fadeStatus() != 0) {
            func_001029a0(9, work->transition, 0x1C, 0);
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


/* measured: FldRootDestroy now matches at normalized_diff 0 (object 540B/window 544B); spelling the second range as <= 0x1E makes MWCCPS2 use the retail $at branch temporary, with the same trailing window nop. */
// Committed at nd 0.
// FUN_00155BF0
void FldRootDestroy(u8 *arg0)
{
    u8 *temp_17;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_16;
    s32 *temp_20;
    s32 *temp_2;
    s32 var_18;

    temp_17 = *(u8 **)(arg0 + 0x38);
    if (iGpffffb20c == 1) {
        calendarPopValue();
    }
    FldUnit_ClearFlagBlock();
    func_002bd410();
    func_002bd3e0();
    KFIELD_D_007D2540 = 0;
    resrcMngSelectDrawSet(0);
    temp_4 = *(s32 *)(temp_17 + 0x3C);
    if (temp_4 != 0) {
        kwlnTaskDestroyWithHierarchy(temp_4);
        var_18 = 0;
        while (var_18 < 0x10) {
            temp_16 = var_18 * 4;
            temp_20 = (s32 *)KFIELD_D_007E8060 + var_18;
            temp_4_2 = *temp_20;
            if (temp_4_2 != 0) {
                FldResource_Destroy(temp_4_2);
                *temp_20 = 0;
                *(s32 *)(iGpffff9db0 + temp_16 + 0x28) = 0;
            }
            var_18 += 1;
        }
    }
    if (func_00102980() != 9 &&
        func_00102980() != 0xB &&
        func_00102980() != 0xA) {
        FldSlotTablesReset();
    }
    if ((u16)*(u16 *)(temp_17 + 0x18) < 0x15) {
        goto field_special;
    }
    if (*(u16 *)(temp_17 + 0x18) <= 0x1E) {
        goto field_call;
    }
field_special:
    if (*(u16 *)(temp_17 + 0x18) != 6) {
        goto field_done;
    }
    if (*(u16 *)(temp_17 + 0x1A) != 1) {
        goto field_done;
    }
field_call:
    FldSlotTablesReset();
field_done:
    FldUnit_ReleaseGroupSlots();
    FldUnit_ReleaseAllSlots();
    memset(KFIELD_D_007E80A0, 0, 0xB40);
    iGpffffb2e4 = 0;
    FldLoadTaskUnloadScene(arg0);
    temp_16 = 0;
    while (temp_16 < 3) {
        temp_2 = (s32 *)KFIELD_D_007D2510 + temp_16;
        temp_4_3 = *(s32 *)((u8 *)temp_2 + 0x34);
        if (temp_4_3 != 0) {
            kwlnTaskDestroyWithHierarchy(temp_4_3);
            *(s32 *)((u8 *)temp_2 + 0x34) = 0;
        }
        temp_16 += 1;
    }
    func_003e9df0(*(s32 *)(kwlnGetCamera() + 4));
    KFIELD_JTBL_008873EC(*(s32 *)(arg0 + 0x38));
}

extern void kwlnTaskDumpAll(void);
extern u8 *D_007D3D64[];
extern u8 D_005EFF10[];
extern u8 D_005EFF48[];
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void resrcMngSetRenderSuppressed(s32 arg0);
extern s32 func_00293ed0(s32 a, s32 b, s32 c, s32 d);
extern void func_0029ddb0(s32 arg0);
extern void FldResource_OpenPrimaryFile(u16 arg0, u16 arg1);
extern u8 D_007D255A[];
extern u8 D_007D255B[];
extern s32 D_007D255C[];
typedef struct { f32 x; f32 y; f32 z; } KFieldVec3;
extern s64 D_005EFF38[];
extern f32 D_005EFF40[];
extern void RwEngineGetMatrixTolerances(f32 *arg0);
extern void RwMatrixOptimize(void *arg0, f32 *arg1);
extern void func_003e9680(void *arg0);
extern s32 FldRootUpdate(u8 *arg0);
/* measured: object 648B/window 656B, nd 0. The six stack parameters are s64
   slots read in place through `*(s32 *)&argN` / `*(u8 *)&arg8`: an s32
   stack parameter with several uses gets homed into $s2 at entry and pushes
   the u8 register parameter out to a byte spill, while the address-taken
   slot reads are plain lw/lbu every time exactly as retail reloads them.
   Register parameters colour $s1,$s4,$s3,$s2,$s5-$s8 with the work pointer in
   $s0 and the handle reusing $s1. The camera position constant is copied as
   an s64 + f32 scalar pair (two lui, both loads before both stores, which
   needs opt_propagation off) into a Vec3 local that is then assigned as a
   12-byte aggregate (three lwc1 then three swc1). FldResource_OpenPrimaryFile takes the
   two u16 parameters unmasked. */
// FUN_00155E10
/* measured: opt_propagation off keeps the scalar-pair copy's two loads ahead
   of its two stores. */
#pragma opt_propagation off
s32 FldRootCreate(u8 *arg0, u16 arg1, u16 arg2, u16 arg3, s16 arg4, s16 arg5, s32 arg6, u8 arg7,
                  s64 arg8, s64 arg9, s64 arg10, s64 arg11, s64 arg12, s64 arg13)
{
    f32 matrix[4];
    KFieldVec3 pos;
    s32 handle;
    u8 *work;
    s64 copy_s64;
    f32 copy_f32;
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
    handle = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005EFF48), 0xF, 0, 0, FldRootUpdate, FldRootDestroy, (u8 *)(work));
    D_007D2510[0] = handle;
    resrcMngSetRenderSuppressed(0);
    if (*(s32 *)&arg10 > 0) {
        *(s32 *)(work + 0x3C) = func_00293ed0(*(s32 *)&arg10, *(s32 *)&arg11, *(s32 *)&arg12, *(s32 *)&arg13);
        *(s32 *)(work + 0) = 0;
        *(s32 *)(work + 0xC) = *(s32 *)&arg10;
        *(s32 *)(work + 0x10) = *(s32 *)&arg11;
        *(s32 *)(work + 0x14) = *(s32 *)&arg12;
    } else {
        func_0029ddb0(*(s32 *)&arg10);
        *(u16 *)(work + 0x18) = arg1;
        *(u16 *)(work + 0x1A) = arg2;
        *(s16 *)(work + 0x20) = arg4;
        *(s16 *)(work + 0x22) = arg5;
        *(u16 *)(work + 0x1C) = arg3;
        *(s32 *)(iGpffff9db0 + 0x88) = arg6;
        D_007D255A[0] = arg7;
        D_007D255B[0] = *(u8 *)&arg8;
        D_007D255C[0] = *(s32 *)&arg9;
        FldResource_OpenPrimaryFile(arg1, arg2);
        *(s32 *)(work + 0) = 1;
    }
    copy_s64 = D_005EFF38[0];
    copy_f32 = D_005EFF40[0];
    *(s64 *)&pos.x = copy_s64;
    pos.z = copy_f32;
    func_003e9df0(*(s32 *)(kwlnGetCamera() + 4));
    cam = *(u8 **)(kwlnGetCamera() + 4);
    *(KFieldVec3 *)(cam + 0x40) = pos;
    RwEngineGetMatrixTolerances(matrix);
    RwMatrixOptimize(*(u8 **)(kwlnGetCamera() + 4) + 0x10, matrix);
    func_003e9680(*(u8 **)(kwlnGetCamera() + 4));
    return handle;
}

/* measured: closes the propagation bracket; the unit default is on. */
#pragma opt_propagation on
