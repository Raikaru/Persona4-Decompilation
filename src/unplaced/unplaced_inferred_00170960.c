/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00170960-001714b0 */

#include "mt_scene_internal.h"
#include "field_frame_internal.h"
#include "rw_geometry_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;

extern s32 *MT_Scene_GetFrameState(void);
extern s32 datGetFlag(s32 arg0);
extern s32 FldStepIndex(void);
extern void FldSlotBroadcastState(s32 arg0);
extern void FldFrameObjSetActive(s32 arg0, s32 arg1);
extern s32 scrStartProcedureIndex(s32 arg0, u8 *arg1, s32 arg2);
extern s32 kwlnTaskIsLinked(s32 arg0);
extern s32 iGpffffb284;
extern s32 FldMap_IsCurrentInBandA(void);
extern s32 FldMap_IsCurrentInBandB(void);
extern s32 FldResAreaHitTest(u8 *arg0, s32 arg1);
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern s32 FldMap_IsCurrentInEitherBand(void);
extern s32 FldStepGetScriptData(void);
extern s32 FldStepGetScriptSize(void);
extern void func_0015a7c0(s32 arg0);
extern s32 scrStartProcedureChecked(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u16 D_008C024E[];
extern void FldPanel2dSetState(s32 arg0, s32 arg1);
extern void smapRefreshCells(u8 *arg0, s8 arg1);
extern void smapSetPhase(s32 arg0, s32 arg1);
extern s32 cmpMainTaskCreate(s32 arg0, s32 arg1);
extern void datSetFlag(s32 arg0, s32 arg1);
extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern s32 K_FldFrame_IsPointInTriangle(void *arg0, void *arg1, void *arg2);
extern s32 kwlnTaskIsLinked(s32 arg0);
extern void *mdlGetMatrix(void *arg0);
extern void fclMiscStopAndClose(void);
extern void fclMiscSetDoneFlag(void);
// FUN_00170960
s32 FldSmapViewTriggerTest(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if ((((FldFrame *)MT_Scene_GetFrameState())->smapObject != 0) && (D_008C024E[0] & 0x800)) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_001709C0
s32 FldSmapViewTriggerRun(u8 *arg0)
{
    s32 state;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        FldSlotBroadcastState(1);
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        FldFrameObjSetActive(*(s32 *)(temp_2 + 0x1C), 1);
        sdkSndStartStream(0, 0, 0, 3);
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        FldPanel2dSetState(*(s32 *)(temp_2 + 0x30), 1);
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        smapRefreshCells(*(u8 **)(temp_2 + 0x18), 1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (D_008C024E[0] & 0x820) {
            FldSlotBroadcastState(0);
            temp_2 = (u8 *)MT_Scene_GetFrameState();
            FldFrameObjSetActive(*(s32 *)(temp_2 + 0x1C), 0);
            temp_2 = (u8 *)MT_Scene_GetFrameState();
            FldPanel2dSetState(*(s32 *)(temp_2 + 0x30), 0);
            temp_2 = (u8 *)MT_Scene_GetFrameState();
            smapRefreshCells(*(u8 **)(temp_2 + 0x18), 0);
            sdkSndStartStream(0, 0, 0, 4);
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 4) += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_00170B50
s32 FldCampTriggerTest(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if (datGetFlag(0x37) == 1) {
        return 0;
    }
    if (D_008C024E[0] & 0x10) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_00170BC0
s32 FldCampTriggerRun(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (((FldFrame *)MT_Scene_GetFrameState())->panelTask != 0)
            FldPanel2dSetState((s32)((FldFrame *)MT_Scene_GetFrameState())->panelTask, 1);
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 1);
        *(s32 *)(temp_16 + 0x10) = cmpMainTaskCreate((s32)arg0, 1);
        if (((FldFrame *)MT_Scene_GetFrameState())->smapObject != 0)
            smapSetPhase((s32)((FldFrame *)MT_Scene_GetFrameState())->smapObject, 1);
        FldSlotBroadcastState(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x10)) != 1) {
            if (((FldFrame *)MT_Scene_GetFrameState())->panelTask != 0)
                FldPanel2dSetState((s32)((FldFrame *)MT_Scene_GetFrameState())->panelTask, 0);
            if (datGetFlag(0x1401) != 0) {
                func_0015a7c0(FldStepIndex());
                datSetFlag(0x1401, 0);
                temp_17 = FldStepGetScriptData();
                scrStartProcedureChecked(0xF, temp_17, FldStepGetScriptSize(), 5);
                *(s32 *)(temp_16 + 4) = 3;
            } else {
                if (((FldFrame *)MT_Scene_GetFrameState())->smapObject != 0)
                    smapSetPhase((s32)((FldFrame *)MT_Scene_GetFrameState())->smapObject, 0);
                FldSlotBroadcastState(0);
                FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 0);
                *(s32 *)(temp_16 + 0x10) = 0;
                *(s32 *)(temp_16 + 4) += 1;
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

// FUN_00170E10
s32 FldFieldScriptTriggerTest(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if (D_008C024E[0] & 0x80) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_00170E50
s32 FldFieldScriptTriggerRun(u8 *arg0)
{
    s32 state;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        FldFrameObjSetActive(*(s32 *)(temp_2 + 0x1C), 1);
        *(s32 *)(temp_16 + 0x10) = scrStartProcedureIndex(0xF, (u8 *)iGpffffb284, 1);
        FldSlotBroadcastState(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x10)) == 1)
            break;
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        FldFrameObjSetActive(*(s32 *)(temp_2 + 0x1C), 0);
        FldSlotBroadcastState(0);
        *(s32 *)(temp_16 + 4) += 1;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_00170F60
s32 FldResAreaHitTest(u8 *arg0, s32 arg1)
{
    Vec3_00178590 sp70;
    u8 *sp60[3];
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    f32 temp_f3;
    f32 temp_f3_2;
    s32 var_17;
    u8 *temp_2;
    u8 *var_16;

    var_17 = 0;
    var_16 = MT_Scene_GetResListHead(0xD);
    if ((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0))
        return 0;
    temp_2 = mdlGetMatrix(*(u8 **)(arg0 + 0x50));
    sp70 = *(Vec3_00178590 *)(temp_2 + 0x30);
    goto loop_21_cond;
loop_21_body:
    {
        extern Vec3_00178590 D_005F1758;
        Vec3_00178590 sp50;

        sp50 = D_005F1758;
        sp60[0] = var_16 + 0x15C;
        sp60[1] = var_16 + 0x168;
        sp60[2] = var_16 + 0x174;
        if ((K_FldFrame_IsPointInTriangle(&sp70, sp60, &sp50) == 1) &&
            (temp_f3 = *(f32 *)(sp60[0] + 4), (sp70.y < (200.0f + temp_f3))) &&
            !(sp70.y <= (temp_f3 - 200.0f))) {
            if (arg1 == 0) {
                if ((*(u16 *)var_16 & 0x3FF) == 0x3FF)
                    goto loop_21_found1;
            }
            if (arg1 != 1)
                goto loop_21_done;
            if ((*(u16 *)var_16 & 0x3FF) != 0x3FE)
                goto loop_21_done;
loop_21_found1:
            var_17 = 1;
            goto loop_21_done;
        }
        sp60[0] = var_16 + 0x168;
        sp60[1] = var_16 + 0x174;
        sp60[2] = var_16 + 0x180;
        if ((K_FldFrame_IsPointInTriangle(&sp70, sp60, &sp50) == 1) &&
            (temp_f3_2 = *(f32 *)(sp60[0] + 4),
             (sp70.y < (200.0f + temp_f3_2))) &&
            !(sp70.y <= (temp_f3_2 - 200.0f))) {
            if (arg1 == 0) {
                if ((*(u16 *)var_16 & 0x3FF) == 0x3FF)
                    goto loop_21_found2;
            }
            if (arg1 != 1)
                goto loop_21_done;
            if ((*(u16 *)var_16 & 0x3FF) != 0x3FE)
                goto loop_21_done;
loop_21_found2:
            var_17 = 1;
            goto loop_21_done;
        }
        var_16 = *(u8 **)(var_16 + 0x138);
    }
loop_21_cond:
    if (var_16 != NULL)
        goto loop_21_body;
loop_21_done:
    return var_17;
}

// FUN_001711B0
s32 FldStepAreaTriggerTest(u8 *arg0)
{
    s32 var_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if ((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0))
        return 0;
    var_2 = D_007EF9F8[0] != 0;
    if (var_2 != 0)
        var_2 = D_007EFA04[0] != 0;
    if (var_2 == 0)
        return 0;
    if (FldResAreaHitTest(D_007EF9B0, 0) == 1) {
        *(s32 *)(temp_16 + 0x14) = 1;
        if (D_008C024E[0] & 0x40) {
            *(s32 *)(temp_16 + 4) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00171280
s32 FldStepAreaTriggerRun(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (FldMap_IsCurrentInEitherBand() == 1)
            func_0015a7c0(FldStepIndex());
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 1);
        temp_17 = FldStepGetScriptData();
        *(s32 *)(temp_16 + 0x10) =
            scrStartProcedureChecked(0xF, temp_17, FldStepGetScriptSize(), 0);
        FldSlotBroadcastState(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x10)) != 1) {
            FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 0);
            FldSlotBroadcastState(0);
            *(s32 *)(temp_16 + 4) += 1;
        }
        break;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

// FUN_001713E0
s32 FldStepAreaAltTriggerTest(u8 *arg0)
{
    s32 var_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if ((FldMap_IsCurrentInBandA() == 0) && (FldMap_IsCurrentInBandB() == 0))
        return 0;
    var_2 = D_007EF9F8[0] != 0;
    if (var_2 != 0)
        var_2 = D_007EFA04[0] != 0;
    if (var_2 == 0)
        return 0;
    if (FldResAreaHitTest(D_007EF9B0, 1) == 1) {
        *(s32 *)(temp_16 + 0x14) = 1;
        if (D_008C024E[0] & 0x40) {
            *(s32 *)(temp_16 + 4) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_001714B0
s32 FldStepAreaAltTriggerRun(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (FldMap_IsCurrentInEitherBand() == 1)
            func_0015a7c0(FldStepIndex());
        fclMiscStopAndClose();
        fclMiscSetDoneFlag();
        FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 1);
        temp_17 = FldStepGetScriptData();
        *(s32 *)(temp_16 + 0x10) =
            scrStartProcedureChecked(0xF, temp_17, FldStepGetScriptSize(), 1);
        FldSlotBroadcastState(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x10)) != 1) {
            FldFrameObjSetActive((s32)((FldFrame *)MT_Scene_GetFrameState())->supporterTask, 0);
            FldSlotBroadcastState(0);
            *(s32 *)(temp_16 + 0x10) = 0;
            *(s32 *)(temp_16 + 4) += 1;
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
