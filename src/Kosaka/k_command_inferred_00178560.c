#include "scene_task_internal.h"
#include "Kosaka/k_field_state_internal.h"
#include "btl_target_state_packet_internal.h"
#include "Kosaka/k_command_internal.h"
#include "mt_scene_internal.h"
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
extern void FldEvent_StepGridCell();
extern s32 *MT_Scene_GetFrameState(void);
extern s32 FldStepIndex(void);
/* measured: Cmd_PickEncounter needs this call unprototyped - retail masks $a2 (b)
   before the two lhu loads and $a3 (a) after them, which is the default-
   promotion order of an old-style call with a u16 local for b and an explicit
   (u16) cast on a; any prototyped u16 parameter hoists the a3 mask before the
   loads (nd4). Sole caller in this unit. */
extern s32 Encount_PickEncounter(s32 field, s32 room, s32 encounter, s32 level);
extern s32 kwlnTaskIsLinked(s32 target);
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
void FldSmapTileQueueQuad(u8 *queue, u8 *context, s32 tileType, s32 variant, s32 width,
                    s32 height, s32 flags, f32 x, f32 y, f32 depth);

extern f32 iGpffff8304;
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];


extern s32 FldEvent_BeginEncounter(s32 task, s32 encounterId, s32 battleFlags);
extern s32 FldRc_CreateTransitionTask(s32 parent, s32 mode);
extern s32 scrGetAiState(void);
extern void scrSetTaskProc(s32 task, s32 proc);
extern s32 kwlnTaskIsLinked(s32 target);

extern u8 *scrGetContext(void);
extern void fclMiscOrStateFlags(s32 flags);
extern void fclMiscSetStatusCode(s32 value);
extern void fclMiscAddRecord(s32 slotIndex, s32 record, s32 value, s32 entryFlags);
extern void *mdlGetMatrix(void *model);
extern s32 FldShadow_DrawProjection(u8 *camera, s32 raster, s32 collisionKind, void *intersection,
                         f32 opacity, f32 depth, s32 fadeWithDepth, u8 *workData);
extern S_00178590 *FldEvent_GetNearestEntry(void);
extern void RwV3dNormalize(void *, void *);
extern u8 D_007EFA00[];
extern void FldRc_QueueScreenQuad(u8 *, u8 *,
                           f32, f32, f32, f32, f32,
                           void *, s32,
                           f32, f32, f32,
                           s32, void *, f32);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0017; members 00178560-001788e0 */

struct RwMatrixTag {
    Vec3_00178590 right; u32 flags;
    Vec3_00178590 up; u32 pad1;
    Vec3_00178590 at; u32 pad2;
    Vec3_00178590 pos; u32 pad3;
};

/* Request the field event grid-cell step and finish the script command. */
// FUN_00178560
s32 Cmd_StepGridCell(void)
{
    FldEvent_StepGridCell();
    return 1;
}

/* Compare the nearest entry forward axis to the direction from the player; return facing code 1 or 3. */
// FUN_00178590
s32 Cmd_GetNearestEntryFacing(void) {
    Vec3_00178590 direction;
    Vec3_00178590 forward;
    f32 targetX;
    f32 targetY;
    f32 targetZ;
    S_00178590 *entry;
    s32 facing;
    u8 *matrix;

    facing = 1;
    entry = FldEvent_GetNearestEntry();
    if (entry != NULL) {
        matrix = mdlGetMatrix(entry->field_144);
        forward = ((struct RwMatrixTag *)(matrix))->at;
        targetX = ((struct RwMatrixTag *)((u8 *)mdlGetMatrix(entry->field_144)))->pos.x;
        direction.x = targetX - ((struct RwMatrixTag *)((u8 *)mdlGetMatrix(*(u8 **)D_007EFA00)))->pos.x;
        targetY = ((struct RwMatrixTag *)((u8 *)mdlGetMatrix(entry->field_144)))->pos.y;
        direction.y = targetY - ((struct RwMatrixTag *)((u8 *)mdlGetMatrix(*(u8 **)D_007EFA00)))->pos.y;
        targetZ = ((struct RwMatrixTag *)((u8 *)mdlGetMatrix(entry->field_144)))->pos.z;
        direction.z = targetZ - ((struct RwMatrixTag *)((u8 *)mdlGetMatrix(*(u8 **)D_007EFA00)))->pos.z;
        RwV3dNormalize(&direction, &direction);
        RwV3dNormalize(&forward, &forward);
        if ((direction.x * forward.x + direction.y * forward.y + direction.z * forward.z) < 0.0f) {
            facing = 1;
        } else {
            facing = 3;
        }
    }
    scrSetReturnInt(facing);
    return 1;
}

/* P4 flowscript library (build/p4flow/Field.json, index 0x1028): FLD_EFFECT_TRAESTO_START(), no parameters. Creates the transition task and waits for it. */
/* Start the transition task once, then wait until the scheduler unlinks it. */
/* The script context's +148 task tail has no shared layout; ScrData remains privately defined in
 * scrTraceCode.c and does not describe this tail. */
// FUN_001786F0
s32 K_Cmd_FLD_EFFECT_TRAESTO_START(void)
{
    s32 transitionTask;
    u8 *context;

    context = scrGetContext();
    transitionTask = scrGetAiState();
    if (transitionTask == 0) {
        scrSetTaskProc(*(s32 *)(context + 0x148), FldRc_CreateTransitionTask(0, 1));
        return 0;
    }
    if (kwlnTaskIsLinked(transitionTask) == 1) {
        return 0;
    }
    scrSetTaskProc(*(s32 *)(context + 0x148), 0);
    return 1;
}

/* P4 flowscript library (build/p4flow/Field.json, index 0x1016): CALL_BATTLE(encounterId, param2). Starts the encounter and yields until it returns. */
/* Poll the encounter transition and expose its completion flags as script result codes. */
// FUN_00178790
s32 K_Cmd_CALL_BATTLE(void)
{
    s32 flags;
    s32 encounterId;
    s32 encounterState;

    encounterId = scrGetParamInt(0);
    flags = scrGetParamInt(1);
    encounterState = FldEvent_BeginEncounter(((FldSceneTasks *)MT_Scene_GetFrameState())->event, encounterId & 0xFFFF,
                           flags & 0xFFFF);
    if (encounterState & 1) {
        return 0;
    }
    if (encounterState & 0x80000000) {
        scrSetReturnInt(1);
    } else if (encounterState & 0x40000000) {
        scrSetReturnInt(2);
    } else {
        scrSetReturnInt(0);
    }
    return 1;
}

/* Select a weighted encounter using current field, room, step index, and script level. */
// FUN_00178870
s32 Cmd_PickEncounter(void)
{
    s32 level = scrGetParamInt(0);
    u8 *fieldState = iGpffff9db0;
    u16 encounterIndex = FldStepIndex();

    scrSetReturnInt(Encount_PickEncounter((u16)((SceneContext *)fieldState)->majorId, (u16)((SceneContext *)fieldState)->minorId, encounterIndex, (u16)level) & 0xFFFF);
    return 1;
}

/* Set the sequence status from the current script context and append its two operands. */
/* The script context's +124 status word has no shared layout; retain this access rather than introducing an
 * incompatible second ScrData definition. */
// FUN_001788E0
s32 Cmd_StartFieldSequence(void)
{
    s32 sequenceId;
    s32 value;

    sequenceId = scrGetParamInt(0);
    value = scrGetParamInt(1);
    fclMiscOrStateFlags(1);
    fclMiscSetStatusCode(*(s32 *)(scrGetContext() + 0x124));
    fclMiscAddRecord(sequenceId, value, 0, 0);
    return 1;
}

