/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00170960-001714b0 */

#include "mt_scene_internal.h"
#include "field_frame_internal.h"
#include "field_event_internal.h"
#include "sdktask.h"
#include "resrc_manager_internal.h"
#include "rw_geometry_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "scr_internal.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
#include "scene_light_override_internal.h"
typedef RwV3d FldAreaPosition;

extern s32 *MT_Scene_GetFrameState(void);
extern s32 datGetFlag(s32);
extern s32 FldStepIndex(void);
extern void FldSlotBroadcastState(s32);
extern void FldFrameObjSetActive(s32, s32);
extern s32 scrStartProcedureIndex(s32, u8 *, s32);
extern s32 kwlnTaskIsLinked(s32);
extern s32 iGpffffb284;
extern s32 FldMap_IsCurrentInBandA(void);
extern s32 FldMap_IsCurrentInBandB(void);
extern s32 FldResAreaHitTest(u8 *, s32);
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern s32 FldMap_IsCurrentInEitherBand(void);
extern s32 FldStepGetScriptData(void);
extern s32 FldStepGetScriptSize(void);
extern void fldStepSaveBoard(s32);
extern s32 scrStartProcedureChecked(s32, s32, s32, s32);
extern u16 D_008C024E[];
extern void FldPanel2dSetState(s32, s32);
extern void smapRefreshCells(u8 *, s8);
extern void smapSetPhase(s32, s32);
extern s32 cmpMainTaskCreate(s32, s32);
extern void datSetFlag(s32, s32);
extern u8 *MT_Scene_GetResListHead(s32);
extern s32 K_FldFrame_IsPointInTriangle(void *, void *, void *);
extern s32 kwlnTaskIsLinked(s32);
extern void *mdlGetMatrix(void *);
extern void fclMiscStopAndClose(void);
extern void fclMiscSetDoneFlag(void);
/* Start map-view input handling when the map exists and the map button is pressed. */
// FUN_00170960
s32 FldSmapViewTriggerTest(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if ((((FldFrame *)MT_Scene_GetFrameState())->smapObject != 0) && (D_008C024E[0] & 0x800)) {
        ((FldEventWork *)work)->state = 0;
        return 1;
    }
    return 0;
}

/* Open the map view, suspend field controls, then restore them when the close input arrives. */
// FUN_001709C0
/* Trigger work fields share the existing field-event task layout. */
s32 FldSmapViewTriggerRun(u8 *task)
{
    FldEventWork *eventWork;
    s32 state;
    u8 *work;
    u8 *frame;

    work = ((SdkTask *)task)->work;
    eventWork = (FldEventWork *)work;
    state = ((FldEventWork *)work)->state;
    switch (state) {
    case 0:
        FldSlotBroadcastState(1);
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        frame = (u8 *)MT_Scene_GetFrameState();
        FldFrameObjSetActive((s32)((FldFrame *)frame)->supporterTask, 1);
        sdkSndStartStream(0, 0, 0, 3);
        frame = (u8 *)MT_Scene_GetFrameState();
        FldPanel2dSetState((s32)((FldFrame *)frame)->panelTask, 1);
        frame = (u8 *)MT_Scene_GetFrameState();
        smapRefreshCells(((FldFrame *)frame)->smapObject, 1);
        eventWork->state += 1;
        break;
    case 1:
        if (D_008C024E[0] & 0x820) {
            FldSlotBroadcastState(0);
            frame = (u8 *)MT_Scene_GetFrameState();
            FldFrameObjSetActive((s32)((FldFrame *)frame)->supporterTask, 0);
            frame = (u8 *)MT_Scene_GetFrameState();
            FldPanel2dSetState((s32)((FldFrame *)frame)->panelTask, 0);
            frame = (u8 *)MT_Scene_GetFrameState();
            smapRefreshCells(((FldFrame *)frame)->smapObject, 0);
            sdkSndStartStream(0, 0, 0, 4);
            ((FldEventWork *)work)->scriptTask = 0;
            eventWork->state += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

/* Start the camp menu on its button unless flag 0x37 blocks access. */
// FUN_00170B50
s32 FldCampTriggerTest(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (datGetFlag(0x37) == 1) {
        return 0;
    }
    if (D_008C024E[0] & 0x10) {
        ((FldEventWork *)work)->state = 0;
        return 1;
    }
    return 0;
}

/* Run the camp task and restore field controls, or launch the requested field script on exit. */
// FUN_00170BC0
s32 FldCampTriggerRun(u8 *task)
{
    FldEventWork *eventWork;
    s32 scriptData;
    s32 state;
    u8 *work;

    work = ((SdkTask *)task)->work;
    eventWork = (FldEventWork *)work;
    state = ((FldEventWork *)work)->state;
    switch (state) {
    case 0:
        if (((FldFrame *)MT_Scene_GetFrameState())->panelTask != 0)
            FldPanel2dSetState((s32)((FldFrame *)MT_Scene_GetFrameState())->panelTask, 1);
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 1);
        ((FldEventWork *)work)->scriptTask = cmpMainTaskCreate((s32)task, 1);
        if (((FldFrame *)MT_Scene_GetFrameState())->smapObject != 0)
            smapSetPhase((s32)((FldFrame *)MT_Scene_GetFrameState())->smapObject, 1);
        FldSlotBroadcastState(1);
        eventWork->state += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(((FldEventWork *)work)->scriptTask) != 1) {
            if (((FldFrame *)MT_Scene_GetFrameState())->panelTask != 0)
                FldPanel2dSetState((s32)((FldFrame *)MT_Scene_GetFrameState())->panelTask, 0);
            if (datGetFlag(0x1401) != 0) {
                fldStepSaveBoard(FldStepIndex());
                datSetFlag(0x1401, 0);
                scriptData = FldStepGetScriptData();
                scrStartProcedureChecked(0xF, scriptData, FldStepGetScriptSize(), 5);
                eventWork->state = 3;
            } else {
                if (((FldFrame *)MT_Scene_GetFrameState())->smapObject != 0)
                    smapSetPhase((s32)((FldFrame *)MT_Scene_GetFrameState())->smapObject, 0);
                FldSlotBroadcastState(0);
                FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 0);
                eventWork->scriptTask = 0;
                eventWork->state += 1;
            }
        }
        break;
    case 2:
        return 0;
    case 3:
        break;
    default:
        break;
    }
    return 1;
}

/* Reset the trigger state when the field-script button is pressed. */
// FUN_00170E10
s32 FldFieldScriptTriggerTest(u8 *task)
{
    u8 *work;

    work = ((SdkTask *)task)->work;
    if (D_008C024E[0] & 0x80) {
        ((FldEventWork *)work)->state = 0;
        return 1;
    }
    return 0;
}

/* Run the indexed field procedure while field controls are suspended; finish when its task exits. */
// FUN_00170E50
s32 FldFieldScriptTriggerRun(u8 *task)
{
    FldEventWork *eventWork;
    s32 state;
    u8 *work;
    u8 *frame;

    work = ((SdkTask *)task)->work;
    eventWork = (FldEventWork *)work;
    state = ((FldEventWork *)work)->state;
    switch (state) {
    case 0:
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        frame = (u8 *)MT_Scene_GetFrameState();
        FldFrameObjSetActive((s32)((FldFrame *)frame)->supporterTask, 1);
        ((FldEventWork *)work)->scriptTask = scrStartProcedureIndex(0xF, (u8 *)iGpffffb284, 1);
        FldSlotBroadcastState(1);
        eventWork->state += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(((FldEventWork *)work)->scriptTask) == 1)
            break;
        frame = (u8 *)MT_Scene_GetFrameState();
        FldFrameObjSetActive((s32)((FldFrame *)frame)->supporterTask, 0);
        FldSlotBroadcastState(0);
        eventWork->state += 1;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

/* Test the model position against each resource quad and a 200-unit vertical band; filter by area kind. */
// FUN_00170F60
s32 FldResAreaHitTest(u8 *unit, s32 areaKind)
{
    FldAreaPosition position;
    u8 *triangle[3];
    f32 unusedScale;
    f32 unusedY;
    f32 unusedX;
    f32 unusedZ;
    f32 firstHeight;
    f32 secondHeight;
    s32 hit;
    u8 *matrix;
    u8 *area;

    hit = 0;
    area = MT_Scene_GetResListHead(0xD);
    if ((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0))
        return 0;
    matrix = mdlGetMatrix((u8 *)((FldEventActor *)unit)->model);
    position = ((SceneLightMatrix *)matrix)->pos;
    goto loop_21_cond;
loop_21_body:
    {
        extern FldAreaPosition D_005F1758;
        FldAreaPosition direction;

        direction = D_005F1758;
        triangle[0] = area + 0x15C;
        triangle[1] = area + 0x168;
        triangle[2] = area + 0x174;
        if ((K_FldFrame_IsPointInTriangle(&position, triangle, &direction) == 1) &&
            (firstHeight = ((FldAreaPosition *)triangle[0])->y, (position.y < (200.0f + firstHeight))) &&
            !(position.y <= (firstHeight - 200.0f))) {
            if (areaKind == 0) {
                if ((*(u16 *)area & 0x3FF) == 0x3FF)
                    goto loop_21_found1;
            }
            if (areaKind != 1)
                goto loop_21_done;
            if ((*(u16 *)area & 0x3FF) != 0x3FE)
                goto loop_21_done;
loop_21_found1:
            hit = 1;
            goto loop_21_done;
        }
        triangle[0] = area + 0x168;
        triangle[1] = area + 0x174;
        triangle[2] = area + 0x180;
        if ((K_FldFrame_IsPointInTriangle(&position, triangle, &direction) == 1) &&
            (secondHeight = ((FldAreaPosition *)triangle[0])->y,
             (position.y < (200.0f + secondHeight))) &&
            !(position.y <= (secondHeight - 200.0f))) {
            if (areaKind == 0) {
                if ((*(u16 *)area & 0x3FF) == 0x3FF)
                    goto loop_21_found2;
            }
            if (areaKind != 1)
                goto loop_21_done;
            if ((*(u16 *)area & 0x3FF) != 0x3FE)
                goto loop_21_done;
loop_21_found2:
            hit = 1;
            goto loop_21_done;
        }
        area = (u8 *)((ResrcRecord *)area)->next;
    }
loop_21_cond:
    if (area != NULL)
        goto loop_21_body;
loop_21_done:
    return hit;
}

/* Arm the step-area script for resource id 0x3FF when the action button is pressed. */
// FUN_001711B0
s32 FldStepAreaTriggerTest(u8 *task)
{
    s32 ready;
    u8 *work;

    work = ((SdkTask *)task)->work;
    if ((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0))
        return 0;
    ready = D_007EF9F8[0] != 0;
    if (ready != 0)
        ready = D_007EFA04[0] != 0;
    if (ready == 0)
        return 0;
    if (FldResAreaHitTest(D_007EF9B0, 0) == 1) {
        ((FldEventWork *)work)->unknown14 = 1;
        if (D_008C024E[0] & 0x40) {
            ((FldEventWork *)work)->state = 0;
            return 1;
        }
    }
    return 0;
}

/* Run the step script with mode zero while field controls are suspended. */
// FUN_00171280
s32 FldStepAreaTriggerRun(u8 *task)
{
    FldEventWork *eventWork;
    s32 scriptData;
    s32 state;
    u8 *work;

    work = ((SdkTask *)task)->work;
    eventWork = (FldEventWork *)work;
    state = ((FldEventWork *)work)->state;
    switch (state) {
    case 0:
        if (FldMap_IsCurrentInEitherBand() == 1)
            fldStepSaveBoard(FldStepIndex());
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 1);
        scriptData = FldStepGetScriptData();
        ((FldEventWork *)work)->scriptTask =
            scrStartProcedureChecked(0xF, scriptData, FldStepGetScriptSize(), 0);
        FldSlotBroadcastState(1);
        eventWork->state += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(((FldEventWork *)work)->scriptTask) != 1) {
            FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 0);
            FldSlotBroadcastState(0);
            eventWork->state += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

/* Arm the alternate step-area script for resource id 0x3FE on action input. */
// FUN_001713E0
s32 FldStepAreaAltTriggerTest(u8 *task)
{
    s32 ready;
    u8 *work;

    work = ((SdkTask *)task)->work;
    if ((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0))
        return 0;
    ready = D_007EF9F8[0] != 0;
    if (ready != 0)
        ready = D_007EFA04[0] != 0;
    if (ready == 0)
        return 0;
    if (FldResAreaHitTest(D_007EF9B0, 1) == 1) {
        ((FldEventWork *)work)->unknown14 = 1;
        if (D_008C024E[0] & 0x40) {
            ((FldEventWork *)work)->state = 0;
            return 1;
        }
    }
    return 0;
}

/* Run the alternate step script with mode one and restore field controls after its task exits. */
// FUN_001714B0
s32 FldStepAreaAltTriggerRun(u8 *task)
{
    FldEventWork *eventWork;
    s32 scriptData;
    s32 state;
    u8 *work;

    work = ((SdkTask *)task)->work;
    eventWork = (FldEventWork *)work;
    state = ((FldEventWork *)work)->state;
    switch (state) {
    case 0:
        if (FldMap_IsCurrentInEitherBand() == 1)
            fldStepSaveBoard(FldStepIndex());
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 1);
        scriptData = FldStepGetScriptData();
        ((FldEventWork *)work)->scriptTask =
            scrStartProcedureChecked(0xF, scriptData, FldStepGetScriptSize(), 1);
        FldSlotBroadcastState(1);
        eventWork->state += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(((FldEventWork *)work)->scriptTask) != 1) {
            FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 0);
            FldSlotBroadcastState(0);
            eventWork->scriptTask = 0;
            eventWork->state += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

/* measured: best plain-C body is 108B in the 112B retail window (112B),
   normalized_diff 4; the sole residual bytes at offset 56 are retail
   `andi $a3,$s1,0xffff` versus candidate `move $a3,$s1`. The file-scope
   Encount_PickEncounter declaration remains (u16, u16, u16, s32) for matching
   FldUnit_SpawnEncounter. Probed a block-scope fourth-parameter u16 prototype at
   the function top, after locals, in an inner block, unnamed, and with
   explicit narrowed locals/casts: each moved the mask before the two lhu
   loads (nd 10); mixed third s32/fourth u16 gave nd 6. O1, schedule off,
   and function-pointer casts did not improve it. Best body remains archived
   at build/D178_00178870_body.c; committed form is bare INCLUDE_ASM. */

/* The __FILE__ evidence groups 0x0017B510..0x0017CCC0 as one translation unit
   named k_shadow.c (tu_audit HIGH, score 5). That span and its helpers
   0x0017ACC0 and 0x0017B350 now live in src/Kosaka/k_shadow.c. The existing
   src/Kosaka/Field/k_shadow.c is a different, already-linked TU at
   0x001026B0 and is not merged with it. */

#include "rw_types_internal.h"
