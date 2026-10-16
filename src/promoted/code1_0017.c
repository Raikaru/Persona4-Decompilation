#include "mt_scene_internal.h"
#include "rw_geometry_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
struct RpGeometry;
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct RwRGBA RwRGBA;
typedef s32 (*FieldRenderStateSetFunction)(RwRenderState, void *);
struct Model;
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;
typedef struct
{
    u8 pad_00178590[0x144];
    u8 *field_144;
} S_00178590;
typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;
typedef struct
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FieldColor_0017;
extern void FldStepResetTables();
extern void FldEvent_StepGridCell();
extern s32 func_0015f660();
extern void func_001029a0(s32 a, void *b, s32 c, s32 d);
extern s32 func_00102980(void);
extern void fieldSceneUnload(void);
extern void sdlSchedulerEnable(void);
extern void *memset(void *dst, s32 value, s32 size);
extern s32 calCaptureStateImage(void);
extern s32 *MT_Scene_GetFrameState(void);
extern s32 datGetFlag(s32 arg0);
extern s32 func_0016fd00(void);
extern s32 func_00162510(u16 arg0, u16 arg1);
extern u32 RpRandom(void);
extern s32 FldStepIndex(void);
/* measured: Cmd_PickEncounter needs this call unprototyped - retail masks $a2 (b)
   before the two lhu loads and $a3 (a) after them, which is the default-
   promotion order of an old-style call with a u16 local for b and an explicit
   (u16) cast on a; any prototyped u16 parameter hoists the a3 mask before the
   loads (nd4). Sole caller in this unit. */
extern s32 Encount_PickEncounter(s32 field, s32 room, s32 encounter, s32 level);
extern void func_00182310(s32 arg0);
extern void func_0018e030(s32 arg0, s32 arg1);
extern s32 func_0029da90(s32 arg0, s32 arg1, s32 arg2);
extern s32 kwlnTaskIsLinked(s32 arg0);
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern s32 FldMap_IsCurrentInBandA(void);
extern s32 FldMap_IsCurrentInBandB(void);
extern s32 func_00170f60(u8 *arg0, s32 arg1);
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern s32 FldMap_IsCurrentInEitherBand(void);
extern s32 func_0015a100(void);
extern s32 func_0015a130(void);
extern void func_0015a7c0(s32 arg0);
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
extern void func_0018a000(s32 arg0, s32 arg1);
extern void smapRefreshCells(u8 *arg0, s8 arg1);
extern void smapSetPhase(s32 arg0, s32 arg1);
extern s32 func_0012d000(s32 arg0, s32 arg1);
extern void datSetFlag(s32 arg0, s32 arg1);
s32 FldShadow_CasterStep(u8 *arg0);
void FldShadow_CasterDestroy(u8 *arg0);
void func_0017d240(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                    s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern s32 func_0017cd60(u8 *arg0);
extern void chkmemAllocSiteTag(const void *msg, s32 id);

extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 sinf(f32 arg0);
extern f32 cosf(f32 arg0);
extern f32 iGpffff8304;
extern struct RpGeometry *func_003c22f0(struct RpGeometry *geometry);
extern u8 *resourceFindByName(char *arg0);
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];

extern void (*jtbl_008873EC[])(void *);

extern s32 scrGetCmdTimer(void);
extern s32 calRestoreStateImage(void);
extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern s32 K_FldFrame_IsPointInTriangle(void *arg0, void *arg1, void *arg2);
extern void scrSetReturnInt(s32 arg0);
extern s32 sdlSchedulerTeardown(void);
extern s32 FldEvent_BeginEncounter(s32 arg0, s32 arg1, s32 arg2);
extern s32 sndRequestAreaTrack(void);
extern void sndPlayAreaCue(void);
extern s32 FldStepAdvance(s32 arg0);
extern s32 FldSceneLoadReady(void);
extern s32 FldRc_CreateTransitionTask(s32 arg0, s32 arg1);
extern s32 scrGetAiState(void);
extern void func_0029dfe0(s32 arg0, s32 arg1);
extern s32 kwlnTaskIsLinked(s32 arg0);

extern s32 scrGetParamInt(s32 arg0);
extern s64 datGetPartyId(s32 arg0);
extern u8 *scrGetContext(void);
extern void func_002bd240(s32 arg0);
extern void func_002bd270(s32 arg0);
extern void func_002bd280(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u8 *func_00457120(void);
extern void *mdlGetMatrix(void *arg0);
extern void mdlScale(void *arg0, void *arg1, s32 arg2);
extern s32 RwEngineGetMatrixTolerances(f32 *arg0);
extern u8 *RwMatrixOptimize(void *arg0, f32 *arg1);
extern u8 *RwMatrixUpdate(void *arg0);
extern void mdlUpdateModelMatrix(void *arg0);
extern void func_0047a320(void *arg0);
extern s32 FldShadow_DrawProjection(u8 *arg0, s32 arg1, s32 arg2, void *arg3,
                         f32 farg0, f32 farg1, s32 arg4, u8 *arg5);
extern S_00178590 *FldEvent_GetNearestEntry(void);
extern void RwV3dNormalize(void *arg0, void *arg1);
extern void func_003e42a0(void *dst, void *src, u8 *arg2);
extern u8 D_007EFA00[];
extern void sprintf(void *dst, const void *src);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32 arg0, void *arg1);
extern void FldRc_QueueScreenQuad(u8 *arg0, u8 *arg1,
                           f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                           void *arg7, s32 arg8,
                           f32 arg9, f32 arg10, f32 arg11,
                           s32 arg12, void *arg13, f32 arg14);
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern void *SceneDraw_GetList4Matrix(void);
extern u8 *func_003e81c0(u8 *, f32);
extern u8 *func_003e8180(u8 *, f32);
extern u8 *RwCameraSetViewWindow(u8 *, const f32 *);
extern u8 *func_003e9c10(u8 *, const f32 *, s32);
extern u8 *func_003e9700(u8 *);
extern u8 *func_003e0670(u8 *, u8 *);
extern u8 *RwCameraClear(u8 *, void *, s32);
extern u32 func_003e8120(u32);
extern void *mdlGetColor(void *);
extern void mdlSetColor(u8 *, const void *);
extern f32 iGpffff826c;
extern f32 iGpffff8214;
extern f32 iGpffff8360;
extern u32 iGpffffb308;
extern u32 iGpffff9f4c;
extern u32 iGpffffb30c;
extern u32 iGpffff9f50;
extern void kAssertFail(const void *, s32);
extern s32 D_005F1930[];
extern s32 D_005F1934[];
extern void func_002bd410(void);
extern void func_002bd3c0(void);

extern u8 *D_007643D0;
extern FieldRenderStateSetFunction D_00887300[];
extern s32 iGpffffba48;

extern void func_003c02e0(u8 *arg0);
extern void func_003c4220(s32 arg0);
extern void func_003cbc60(s32 arg0, u8 *arg1);
extern void func_003e8440(u8 *arg0);
extern void func_003e9390(s32 arg0);
extern void func_003ec330(s32 arg0);
extern void *func_003ef080(void *texture, void *raster);
extern void func_003ef3a0(u8 *arg0);
extern void func_003efd20(u8 *camera, u8 *frame);
extern s32 K_Clump_GetWorld(void);

extern u8 *K_Clump_GetLightA(void);
extern u8 *K_Clump_GetLightB(void);
extern u8 *K_Clump_GetLightC(void);



/* measured: ONE real defect, and it is the `slt $at` family. Retail emits
   `slti $at,$v0,4; bnez $at` where b210 emits `slti $v0,$v0,4; bnez $v0`,
   reusing the dead call result as the comparison destination. obj 92B vs
   window 96B, so the reported count also includes one padding word.
   `#pragma schedule off` and hoisting the call result into a local both leave
   it unchanged.

   Do NOT record this as a blanket floor. A census of the retail image shows the
   $at form in 276 first-party functions that ALREADY MATCH, so it is reachable
   from C -- it appears when the comparison feeds a short-circuit `&&`/`||`
   chain, or when its source register is still live afterwards (see the matched
   datCalc func_00231ef0: `if (arg1 > 99 && !(*(u16 *)arg0 & 4))` compiles to
   `andi $v1; slti $at,$v1,0x64; bnez $at`). What is NOT reachable is this
   shape: a single bare comparison on a dead call result, where b210 always
   recycles the source register. 359 of the remaining first-party ASM functions
   contain an $at comparison, so the distinction is worth knowing before writing
/* SOLVED by tools/permute.py; this previously carried a `slt $at` floor note
   and sat under #ifdef NON_MATCHING. The permuter found the shape from the
   preserved body. */


extern void FldShadow_CmdRender(u8 *arg0, u8 *arg1);
// FUN_00170960
s32 func_00170960(u8 *arg0)
{
    u8 *temp;

    temp = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18) != 0) && (D_008C024E[0] & 0x800)) {
        *(s32 *)(temp + 4) = 0;
        return 1;
    }
    return 0;
}

// FUN_001709C0
s32 func_001709c0(u8 *arg0)
{
    s32 state;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        func_00182310(1);
        func_002bd410();
        func_002bd3c0();
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 1);
        sdkSndStartStream(0, 0, 0, 3);
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        func_0018a000(*(s32 *)(temp_2 + 0x30), 1);
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        smapRefreshCells(*(u8 **)(temp_2 + 0x18), 1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (D_008C024E[0] & 0x820) {
            func_00182310(0);
            temp_2 = (u8 *)MT_Scene_GetFrameState();
            func_0018e030(*(s32 *)(temp_2 + 0x1C), 0);
            temp_2 = (u8 *)MT_Scene_GetFrameState();
            func_0018a000(*(s32 *)(temp_2 + 0x30), 0);
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
s32 func_00170b50(u8 *arg0)
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
s32 func_00170bc0(u8 *arg0)
{
    s32 temp_17;
    s32 state;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30) != 0)
            func_0018a000(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30), 1);
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C), 1);
        *(s32 *)(temp_16 + 0x10) = func_0012d000((s32)arg0, 1);
        if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18) != 0)
            smapSetPhase(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18), 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x10)) != 1) {
            if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30) != 0)
                func_0018a000(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30), 0);
            if (datGetFlag(0x1401) != 0) {
                func_0015a7c0(FldStepIndex());
                datSetFlag(0x1401, 0);
                temp_17 = func_0015a100();
                func_0029db50(0xF, temp_17, func_0015a130(), 5);
                *(s32 *)(temp_16 + 4) = 3;
            } else {
                if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18) != 0)
                    smapSetPhase(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x18), 0);
                func_00182310(0);
                func_0018e030(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C), 0);
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
s32 func_00170e10(u8 *arg0)
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
s32 func_00170e50(u8 *arg0)
{
    s32 state;
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    state = *(s32 *)(temp_16 + 4);
    switch (state) {
    case 0:
        func_002bd410();
        func_002bd3c0();
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 1);
        *(s32 *)(temp_16 + 0x10) = func_0029da90(0xF, iGpffffb284, 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x10)) == 1)
            break;
        temp_2 = (u8 *)MT_Scene_GetFrameState();
        func_0018e030(*(s32 *)(temp_2 + 0x1C), 0);
        func_00182310(0);
        *(s32 *)(temp_16 + 4) += 1;
    case 2:
        return 0;
    default:
        break;
    }
    return 1;
}

/* measured: the 12-byte D_005F1758 origin is a plain Vec3 struct assignment
   (retail ld + lwc1 with separate lui pairs, then sd + swc1); spelling it as
   an s64/f32 pair through separate globals is what cost the archived nd 8, and
   it also made a dead `sp60[0] = &sp50` necessary to hoist $a2. */
// FUN_00170F60
s32 func_00170f60(u8 *arg0, s32 arg1)
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
s32 func_001711b0(u8 *arg0)
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
    if (func_00170f60(D_007EF9B0, 0) == 1) {
        *(s32 *)(temp_16 + 0x14) = 1;
        if (D_008C024E[0] & 0x40) {
            *(s32 *)(temp_16 + 4) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_00171280
s32 func_00171280(u8 *arg0)
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
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C), 1);
        temp_17 = func_0015a100();
        *(s32 *)(temp_16 + 0x10) =
            func_0029db50(0xF, temp_17, func_0015a130(), 0);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x10)) != 1) {
            func_0018e030(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C), 0);
            func_00182310(0);
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
s32 func_001713e0(u8 *arg0)
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
    if (func_00170f60(D_007EF9B0, 1) == 1) {
        *(s32 *)(temp_16 + 0x14) = 1;
        if (D_008C024E[0] & 0x40) {
            *(s32 *)(temp_16 + 4) = 0;
            return 1;
        }
    }
    return 0;
}

// FUN_001714B0
s32 func_001714b0(u8 *arg0)
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
        func_002bd410();
        func_002bd3c0();
        func_0018e030(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C), 1);
        temp_17 = func_0015a100();
        *(s32 *)(temp_16 + 0x10) =
            func_0029db50(0xF, temp_17, func_0015a130(), 1);
        func_00182310(1);
        *(s32 *)(temp_16 + 4) += 1;
        break;
    case 1:
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x10)) != 1) {
            func_0018e030(*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x1C), 0);
            func_00182310(0);
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

/* 608/608 bytes; eight fully resolved GP relocations.
 * Aggregate matrix assignment preserves all 64 bytes. */
typedef struct { Vec3_00178590 right; u32 flags; Vec3_00178590 up; u32 pad1; Vec3_00178590 at; u32 pad2; Vec3_00178590 position; u32 pad3; } FieldMatrix_0017;









// FUN_00176880
s32 func_00176880(void)
{
    scrSetReturnInt(FldStepIndex());
    return 1;
}
// FUN_001768B0
s32 func_001768b0(void)
{
    scrSetReturnInt(FldSceneLoadReady());
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






// FUN_001789D0
s32 func_001789d0(void)
{
    func_002bd410();
    func_002bd3c0();
    return 1;
}



/* The __FILE__ evidence groups 0x0017B510..0x0017CCC0 as one translation unit
   named k_shadow.c (tu_audit HIGH, score 5). That span and its helpers
   0x0017ACC0 and 0x0017B350 now live in src/Kosaka/k_shadow.c. The existing
   src/Kosaka/Field/k_shadow.c is a different, already-linked TU at
   0x001026B0 and is not merged with it. */

typedef struct RwV3d { f32 x, y, z; } RwV3d;
struct RwMatrixTag;
struct RpWorld;
struct RpWorldSector;
struct RpIntersection;
struct RpCollisionTriangle;
struct Resrc;
typedef struct FldShadowProjectionWork FldShadowProjectionWork;
typedef struct FldShadowAtomicContext {
    void *geometry;
    FldShadowProjectionWork *work;
    void *atomic;
} FldShadowAtomicContext;
enum RwOpCombineType
{
    rwCOMBINEREPLACE = 0,   /**<Replace -
                                all previous transformations are lost */
    rwCOMBINEPRECONCAT,     /**<Pre-concatenation -
                                the given transformation is applied
                                before all others */
    rwCOMBINEPOSTCONCAT,    /**<Post-concatenation -
                                the given transformation is applied
                                after all others */
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7fffffff
};
enum RwPrimitiveType
{
    rwPRIMTYPENAPRIMTYPE = 0,   /**<Invalid primative type */
    rwPRIMTYPELINELIST = 1,     /**<Unconnected line segments, each line is specified by
                                 * both its start and end index, independently of other lines
                                 * (for example, 3 segments specified as 0-1, 2-3, 4-5) */
    rwPRIMTYPEPOLYLINE = 2,     /**<Connected line segments, each line's start index
                                 * (except the first) is specified by the index of the end of
                                 * the previous segment (for example, 3 segments specified as
                                 * 0-1, 1-2, 2-3) */
    rwPRIMTYPETRILIST = 3,      /**<Unconnected triangles: each triangle is specified by
                                 * three indices, independently of other triangles (for example,
                                 * 3 triangles specified as 0-1-2, 3-4-5, 6-7-8) */
    rwPRIMTYPETRISTRIP = 4,     /**<Connected triangles sharing an edge with, at most, one
                                 * other forming a series (for example, 3 triangles specified
                                 * as 0-2-1, 1-2-3-, 2-4-3) */
    rwPRIMTYPETRIFAN = 5 ,      /**<Connected triangles sharing an edge with, at most,
                                 * two others forming a fan (for example, 3 triangles specified
                                 * as 0-2-1, 0-3-2, 0-4-3) */
    rwPRIMTYPEPOINTLIST = 6,    /**<Points 1, 2, 3, etc. This is not
                                 * supported by the default RenderWare
                                 * immediate or retained-mode pipelines
                                 * (except on PlayStation 2), it is intended
                                 * for use by user-created pipelines */
    rwPRIMITIVETYPEFORCEENUMSIZEINT = 0x7fffffff
};
struct _RxObjSpace3DVertex;
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
/* measured: closing opt_propagation bracket for FldShadow_CmdRender. */
#pragma opt_propagation on
typedef struct RwSphere { RwV3d center; f32 radius; } RwSphere;
struct RpGeometry;
struct RpTriangle;
struct RpMorphTarget;

extern u8 D_005F18D0[];
extern const u64 D_005F18B0;
extern const f32 D_005F18B8;
extern u8 *func_003ef2e0(void *raster);
extern u8 *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern u8 *func_003e84a0(void);
extern struct RwFrame *func_003e9320(void);
extern struct RwFrame *func_003e9df0(struct RwFrame *frame);
extern void *RwCameraSetProjectionType(void *camera, s32 projection);
extern void FldShadow_DestroyCamera(void *camera);
extern void *func_003cbc10(s32 world, void *camera);
extern f32 fabsf(f32 x);



#pragma opt_propagation on
#pragma opt_loop_invariants off
/* 764/768 bytes; fourteen resolved relocations; four zero alignment bytes.
 * Preserve unsigned frame updates and the three ordered sprite draws. */
// FUN_0017CD60
s32 func_0017cd60(u8 *arg0)
{
    u8 *work;
    f32 easing;
    f32 inverse;
    f32 frame;
    s32 opacity;
    u16 counter;
    f32 x;
    f32 y;

    work = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(work + 4) == 0) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
        *(s32 *)(work + 8) = (s32)resourceFindByName(D_005E5850);
        *(u16 *)(work + 0xC) = 320;
        *(u16 *)(work + 0xE) = 240;
        *(s32 *)work = *(s32 *)work + 1;
        goto done;
    case 1:
        counter = *(u16 *)(work + 0x10);
        frame = (f32)(u16)counter;
        easing = sinf((iGpffff82fc * frame) / 15.0f);
        inverse = 1.0f - easing;
        sdkSpriteDrawQueued((f32)(*(u16 *)(work + 0xC) + 10),
                      (f32)(*(u16 *)(work + 0xE) + 25), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC4, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        opacity = (s32)(128.0f * easing) + 0x80;
        x = (f32)(*(u16 *)(work + 0xC) + 0x6E);
        y = (f32)(*(u16 *)(work + 0xE) + 0x22);
        opacity = (0xFF < opacity) ? 0xFF : opacity;
        sdkSpriteDrawQueued(x, y, 1000.0f,
                      0xFFFFFF, opacity & 0xFF, 0xC6, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued((f32)(*(u16 *)(work + 0xC) + 0x6E),
                      (f32)(*(u16 *)(work + 0xE) + 0xF +
                            (s32)(3.0f * inverse)), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC5, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        counter = *(u16 *)(work + 0x10) + 1;
        *(u16 *)(work + 0x10) = counter;
        if (0xF < *(u16 *)(work + 0x10)) {
            *(u16 *)(work + 0x10) = 0;
        }
        goto done;
    case 2:
        return -1;
    default:
        goto done;
    }
done:
    return 0;
}
// FUN_0017D060
void func_0017d060(u8 *arg0)
{
}
// FUN_0017D070
s32 func_0017d070(u8 *arg0)
{
    memset(D_007F1740, 0, 0x20);
    return (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F1950), 0x12, 0, 0, func_0017cd60, func_0017d060, (u8 *)(D_007F1740));
}
// FUN_0017D0F0
void func_0017d0f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 4) = arg1;
}
// FUN_0017D100
void func_0017d100(u8 *arg0)
{
    F2_0017 sp30;
    f32 temp_f1;
    s32 temp_17;
    s32 temp_4;
    s32 var_3;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_17 = (s32)(func_00457120() + 0x20);
    func_003e42a0(&sp30, (u8 *)mdlGetMatrix(*(u8 **)D_007EFA00) + 0x30, (u8 *)temp_17);
    temp_f1 = 640.0f * (sp30.first / sp30.second);
    if (temp_f1 <= 100.0f) {
        var_3 = 0;
    } else if (temp_f1 < 540.0f) {
        var_3 = 1;
    } else {
        var_3 = 2;
    }
    temp_4 = var_3 * 8;
    *(s16 *)(temp_16 + 0xC) = *(s32 *)((u8 *)D_005F1930 + temp_4);
    *(s16 *)(temp_16 + 0xE) = *(s32 *)((u8 *)D_005F1934 + temp_4);
}
// FUN_0017D1F0
void func_0017d1f0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3,
                   f32 arg5, f32 arg6, f32 arg7, s32 arg4)
{
    s32 temp_3;

    temp_3 = arg2 * 8;
    func_0017d240(arg0, arg1, arg2, arg3,
                  *(s32 *)(D_005F1A60 + temp_3) + 1,
                  *(s32 *)(D_005F1A64 + temp_3) + 1, arg4,
                  arg5, arg6, arg7);
}
/* measured: optimization_level 1 is required for func_0017d240 codegen. */
#pragma optimization_level 1
// FUN_0017D240
void func_0017d240(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9)
{
    struct {
        u8 data[0x10];
        u8 tail[0x10];
    } spA0;
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    s32 local_6;
    s32 local_5;
    s32 local_4;
    f32 temp_f24;
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21 = (f32)arg4;
    f32 temp_f20 = (f32)arg5;
    f32 *temp_9;
    s32 temp_2;
    s32 temp_1;
    s32 temp_18;
    local_0 = arg0;
    local_1 = arg1;
    local_2 = arg2;
    temp_f24 = arg7;
    temp_f23 = arg8;
    temp_f22 = arg9;
    local_6 = arg4;
    local_5 = arg5;
    local_4 = arg6;
    if (arg3 == 0) {
        sprintf(spA0.data, D_005F1AE0);
    } else {
        sprintf(spA0.data, D_005F1B00);
    }
    temp_18 = local_2 * 0x10;
    temp_f21 = (f32)local_6;
    temp_f20 = (f32)local_5;
    temp_1 = func_003ef6d0();
    temp_2 = func_003ef650(temp_1, spA0.data);
    FldRc_QueueScreenQuad(local_0, local_1,
                  temp_f24, temp_f23, temp_f22, temp_f21, temp_f20,
                  (void *)&iGpffff9f54, temp_2,
                  *(f32 *)(temp_9 = (f32 *)(D_005F1970 + temp_18)),
                  *(f32 *)(D_005F1974 + temp_18),
                  *(f32 *)(D_005F1978 + temp_18),
                  local_4, temp_9,
                  *(f32 *)(D_005F197C + temp_18));
}
/* measured: restore optimization_level 2 after func_0017d240. */
#pragma optimization_level 2
