#include "Kosaka/k_field_state_internal.h"
#include "kwln_task_internal.h"
#include "btl_target_state_packet_internal.h"
#include "Kosaka/k_command_internal.h"
#include "mt_scene_internal.h"
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
extern s32 mtSceneResListPrepareAll();
extern void sequenceRequest(s32 a, void *b, s32 c, s32 d);
extern s32 kwlnGetCurrentWorkValue(void);
extern void fieldSceneUnload(void);
extern void sdlSchedulerEnable(void);
extern void *memset(void *dst, s32 value, s32 size);
extern s32 calCaptureStateImage(void);
/* measured: Cmd_PickEncounter needs this call unprototyped - retail masks $a2 (b)
   before the two lhu loads and $a3 (a) after them, which is the default-
   promotion order of an old-style call with a u16 local for b and an explicit
   (u16) cast on a; any prototyped u16 parameter hoists the a3 mask before the
   loads (nd4). Sole caller in this unit. */
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
void FldSmapTileQueueQuad(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                    s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);

extern f32 iGpffff8304;
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];


extern s32 calRestoreStateImage(void);
extern s32 sdlSchedulerTeardown(void);
extern s32 sndRequestAreaTrack(void);
extern void sndPlayAreaCue(void);
extern s32 FldStepAdvance(s32 arg0);

extern s32 FldShadow_DrawProjection(u8 *arg0, s32 arg1, s32 arg2, void *arg3,
                         f32 farg0, f32 farg1, s32 arg4, u8 *arg5);
extern u8 D_007EFA00[];
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
extern f32 iGpffff826c;
extern f32 iGpffff8214;
extern f32 iGpffff8360;
extern u32 iGpffffb308;
extern u32 iGpffff9f4c;
extern u32 iGpffffb30c;
extern u32 iGpffff9f50;
extern s32 D_005F1930[];
extern s32 D_005F1934[];

extern u8 *D_007643D0;
extern FieldRenderStateSetFunction D_00887300[];
extern s32 iGpffffba48;





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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0017; members 00175f70-00176850 */

typedef struct { Vec3_00178590 right; u32 flags; Vec3_00178590 up; u32 pad1; Vec3_00178590 at; u32 pad2; Vec3_00178590 position; u32 pad3; } FieldMatrix_0017;
extern f32 fabsf(f32 x);
/* Choose the shorter wrapped heading arc and start a stepped turn for angles exceeding 45 degrees. */
typedef struct FldHeadingTurnWork {
    FieldMatrix_0017 matrix;
    s32 state;
    u8 pad44[8];
    f32 startHeading, endHeading, headingStep;
    s32 frame, frameCount;
} FldHeadingTurnWork;

/* measured: typing the remaining turn-state and step accesses individually loses MATCH; keep their byte
 * aliases around the angle calculations. */
// FUN_00175F70
s32 FldEvent_BeginHeadingTurn(const u8 *task, const FieldMatrix_0017 *matrix, f32 startHeading, f32 endHeading)
{
    extern f32 fGpffff8558;
    extern f32 fabsf(f32);
    s32 state;
    u8 *work;
    s32 count;
    s32 descending;
    f32 first;
    f32 second;
    f32 direct;
    f32 wrapped;
    work = ((KwlnTask *)task)->work;
    state = *(s32 *)(work + 0x40);
    if (state == 1)
        return 0;
    first = startHeading;
    second = endHeading;
    *(FieldMatrix_0017 *)work = *matrix;
    if (!(first <= 360.0f))
        first -= 360.0f;
    ((FldHeadingTurnWork *)work)->startHeading = first;
    if (!(second <= 360.0f))
        second -= 360.0f;
    ((FldHeadingTurnWork *)work)->endHeading = second;
    if (first < second) {
        if (!(first <= fGpffff8558))
            first = 0.0f;
        if (!(second <= *(const f32 *)&fGpffff8558))
            second = 360.0f;
        if (first < iGpffff8214)
            first = 0.0f;
        if (second < *(const f32 *)&iGpffff8214)
            second = 360.0f;
        direct = second - first;
        wrapped = first + (360.0f - second);
        descending = 0;
    } else {
        if (!(first <= fGpffff8558))
            first = 360.0f;
        if (!(second <= *(const f32 *)&fGpffff8558))
            second = 0.0f;
        if (first < iGpffff8214)
            first = 360.0f;
        if (second < *(const f32 *)&iGpffff8214)
            second = 0.0f;
        direct = first - second;
        wrapped = second + (360.0f - first);
        descending = 1;
    }
    if (fabsf(direct) < fabsf(wrapped)) {
        *(f32 *)(work + 0x54) = direct;
        if (descending == 1)
            *(f32 *)(work + 0x54) = *(f32 *)(work + 0x54) * -1.0f;
    } else {
        ((FldHeadingTurnWork *)work)->headingStep = wrapped;
        if (descending == 0)
            *(f32 *)(work + 0x54) = *(f32 *)(work + 0x54) * -1.0f;
    }
    if (!(fabsf(*(f32 *)(work + 0x54)) <= 45.0f)) {
        count = (s32)fabsf(*(f32 *)(work + 0x54)) / 30;
        if (count <= 0)
            count = 1;
        ((FldHeadingTurnWork *)work)->frameCount = count;
        ((FldHeadingTurnWork *)work)->frame = 0;
        ((FldHeadingTurnWork *)work)->headingStep =
            ((FldHeadingTurnWork *)work)->headingStep / (f32) ((FldHeadingTurnWork *)work)->frameCount;
        ((FldHeadingTurnWork *)work)->state = 1;
        return 1;
    }
    return 0;
}

// FUN_001761D0
s32 FldEvent_IsHeadingTurning(u8 *task)
{
    return ((FldHeadingTurnWork *)((KwlnTask *)task)->work)->state == 1;
}

/* Capture the calendar state image for later restoration by the matching script command. */
// FUN_001761F0
s32 K_Cmd_CAL_CAPTURE_STATE(void)
{
    calCaptureStateImage();
    return 1;
}

/* Delay until command frame four, then return the saved-calendar restoration result. */
// FUN_00176220
s32 K_Cmd_CAL_RESTORE_STATE(void)
{
    if (scrGetCmdTimer() > 3) {
        scrSetReturnInt(calRestoreStateImage());
        return 1;
    }
    scrSetReturnInt(0);
    return 0;
}

// FUN_00176280
void K_Cmd_RES_LIST_PREPARE(void)
{
    mtSceneResListPrepareAll();
}

/* Play the pending area cue only when no area-track request remains. */
// FUN_001762A0
s32 K_Cmd_AREA_TRACK_PLAY(void)
{
    if (sndRequestAreaTrack() == 0) {
        sndPlayAreaCue();
    }
    return 1;
}

/* Wait for every resource model to prepare before tearing down the sequence scheduler. */
// FUN_001762E0
s32 K_Cmd_CALL_TITLE(void)
{
    if (mtSceneResListPrepareAll() == 0) {
        return 0;
    }
    sdlSchedulerTeardown();
    return 1;
}

/* Wait for model preparation before requesting the television sequence. */
// FUN_00176320
s32 K_Cmd_CALL_TV(void) {
    if (mtSceneResListPrepareAll() == 0) {
        return 0;
    }
    sequenceRequest(0x19, NULL, 0, 0);
    return 1;
}

/* Prepare resources, enable scheduling, and request the local map using the script map identifier. */
// FUN_00176370
s32 K_Cmd_CALL_LMAP(void) {
    s32 mapId;

    if (mtSceneResListPrepareAll() == 0) {
        return 0;
    }
    sdlSchedulerEnable();
    memset(&mapId, 0, 4);
    mapId = scrGetParamInt(0);
    sequenceRequest(0xC, &mapId, 4, 2);
    return 1;
}

/* Prepare resources and request the food-court sequence with no payload. */
// FUN_001763F0
s32 K_Cmd_CALL_FOOD_COURT(void) {
    if (mtSceneResListPrepareAll() == 0) {
        return 0;
    }
    sdlSchedulerEnable();
    sequenceRequest(0xD, NULL, 0, 2);
    return 1;
}

/* Prepare resources and request a field sequence with a cleared 0x1C-byte parameter block. */
// FUN_00176450
s32 K_Cmd_CALL_FIELD(void)
{
    s16 fieldParameters[14];

    if (mtSceneResListPrepareAll() == 0) {
        return 0;
    }
    sdlSchedulerEnable();
    memset(fieldParameters, 0, 0x1C);
    fieldParameters[0] = (s16)scrGetParamInt(0);
    fieldParameters[1] = (s16)scrGetParamInt(1);
    fieldParameters[2] = (s16)scrGetParamInt(2);
    fieldParameters[4] = (s16)scrGetParamInt(3);
    sequenceRequest(9, fieldParameters, 0x1C, 2);
    return 1;
}

/* The cached-selection halfword at +10 is inside SceneContext's reserved span; its owning member is not
 * established, so retain the narrow store. */
// FUN_00176500
s32 K_Cmd_CALL_FIELD_RESET(void)
{
    s16 fieldParameters[14];

    if (mtSceneResListPrepareAll() == 0) {
        return 0;
    }
    sdlSchedulerEnable();
    *(s16 *)(iGpffff9db0 + 0x10) = -1;
    memset(fieldParameters, 0, 0x1C);
    fieldParameters[0] = (s16)scrGetParamInt(0);
    fieldParameters[1] = (s16)scrGetParamInt(1);
    fieldParameters[2] = (s16)scrGetParamInt(2);
    fieldParameters[4] = (s16)scrGetParamInt(3);
    sequenceRequest(9, fieldParameters, 0x1C, 2);
    return 1;
}

/* Wait for resource preparation, request the event sequence, then poll its completion. */
// FUN_001765C0
s32 K_Cmd_CALL_EVENT(void)
{
    s32 eventParameters[7];
    s32 commandFrame;
    s32 transitionFrame;
    s32 complete;


    complete = 0;
    commandFrame = scrGetCmdTimer();
    if (mtSceneResListPrepareAll() == 0) {
        iGpffffb304 = scrGetCmdTimer();
        return 0;
    }
    if ((commandFrame == 0) || ((commandFrame - 1) == iGpffffb304))
        iGpffffb300 = 0;
    eventParameters[3] = scrGetParamInt(0);
    eventParameters[4] = scrGetParamInt(1);
    eventParameters[5] = scrGetParamInt(2);
    transitionFrame = iGpffffb300;
    if (transitionFrame == 3) {
        sequenceRequest(0xA, eventParameters, 0x1C, 2);
    } else if (transitionFrame > 0xA) {
        if (kwlnGetCurrentWorkValue() == -1) {
            iGpffffb300 = 0;
            complete = 1;
        } else {
            complete = 0;
        }
    }
    iGpffffb300 += 1;
    return complete;
}

/* Unload the previous non-dungeon scene and request the floor with room FFFF. */
// FUN_001766E0
s32 K_Cmd_CALL_DNG_FLOOR_ONLY(void)
{
    s32 floorParameters[2];

    if (mtSceneResListPrepareAll() == 0) {
        return 0;
    }
    sdlSchedulerEnable();
    if (kwlnGetCurrentWorkValue() != 0xB) {
        fieldSceneUnload();
    }
    floorParameters[0] = scrGetParamInt(0);
    floorParameters[1] = 0xFFFF;
    sequenceRequest(0xB, floorParameters, 8, 4);
    return 1;
}

/* Unload the previous non-dungeon scene and request the script-selected floor and room. */
// FUN_00176770
s32 K_Cmd_CALL_DNG_FLOOR(void)
{
    s32 floorParameters[2];

    if (mtSceneResListPrepareAll() == 0) {
        return 0;
    }
    if (kwlnGetCurrentWorkValue() != 0xB) {
        fieldSceneUnload();
    }
    sdlSchedulerEnable();
    floorParameters[0] = scrGetParamInt(0);
    floorParameters[1] = scrGetParamInt(1);
    sequenceRequest(0xB, floorParameters, 8, 4);
    return 1;
}

/* Advance the field step table by the script-selected amount. */
// FUN_00176810
s32 K_Cmd_FLD_MAP_STEP(void)
{
    FldStepAdvance(scrGetParamInt(0));
    return 1;
}

/* Reset the field step tables and finish the script command. */
// FUN_00176850
s32 K_Cmd_FLD_MAP_RESET(void)
{
    FldStepResetTables();
    return 1;
}

