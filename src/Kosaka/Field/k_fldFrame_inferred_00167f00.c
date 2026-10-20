#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "scene_render_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"
#include "resrc_manager_internal.h"
#include "member_access.h"

typedef struct RwMatrix RwMatrix;

/* Task payload sizes are established by FldFrameTask_Spawn (0x48 and 0x10).
 * Model resources expose the model at 0x164 and follower models at 0x228/0x22c. */
typedef struct FldMoveData {
    s32 state;
    u32 flags;
    u16 resourceKey;
    u16 actorId;
    u8 *actor;
    s32 model;
    s32 followerModel;
    RwV3d displacement;
    f32 height;
    s32 unk28;
    u8 pad2c[0x0c];
    s32 distance;
    u32 historyTicks;
    s32 tileX;
    s32 tileZ;
} FldMoveData;
typedef struct FldFollowerData {
    s32 unk00;
    u16 resourceKey;
    u8 pad06[2];
    s32 model;
    s32 followerModel;
} FldFollowerData;
typedef struct FldTaskStorage {
    u8 pad00[0x38];
    u8 *data;
} FldTaskStorage;


/* Actor table stride is 0x750; the movement callback wraps the history at 64.
 * Shifted byte cursors select valid[index], position[index], and forward[index]
 * through the corresponding zero-index member when alias-sensitive. */
typedef struct FldActorHistory {
    u8 pad00[0x48];
    s32 active;
    u8 pad4c[4];
    s32 model;
    u8 pad54[0x176];
    u8 scaleGroup;
    u8 scaleIndex;
    u8 pad1cc[4];
    u8 valid[64];
    struct { f32 x, z; } position[64];
    RwV3d forward[64];
    s32 writeIndex;
    u8 pad714[0x14];
    u16 actorId;
    u8 pad72A[0x26];
} FldActorHistory;


extern s32 iGpffff9ef8;
extern s32 iGpffff9f08;

extern void (*DAT_008873EC[])(void *);
extern u8 D_007EF9B0[];
extern u8 D_007F16F0[];
extern u8 D_007E4320[];
extern u8 D_007F16F2[];
extern u8 D_007F16F4[];
extern u8 D_007E8C00[];
extern char D_005F1218[];
extern char D_005F1230[];
extern char D_005F1248[];
extern s32 iGpffffb2e8;
extern s32 iGpffffb2e4;
extern s32 iGpffffb2e0;
extern u8 D_007E8BE0[];
extern u8 D_007E8BE8[];
extern u8 D_007E8BF8[];
extern u8 D_007E80A0[];
extern u8 D_007E8060[];
extern u8 D_007E8020[];
extern u8 *iGpffffb2b0;
extern s32 iGpffffb2b8;
extern s32 D_007643A4;
extern s32 D_007643AC;
extern f32 D_007643B0;
extern f32 D_007643B4;
extern u8 D_007943C0[];
extern u8 D_00794960[];
extern s32 iGpffffba48;
extern u8 iGpffffba4c;
extern u8 iGpffffba50;
extern u8 iGpffffba54;
extern u8 iGpffffba58;
extern void (*D_00887300[])(u32, u32);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 D_007F1730[];

extern u8 D_005F16C8[];
extern u8 D_005F16D0[];

extern u8 D_007EF9F8[];
extern u8 D_007EFA00[];
extern u8 D_005F1698[];
extern u8 D_005F16E0[];
extern char D_005F16B0[];
extern u8 D_007948D0[];
extern f32 fabsf(f32 x);
extern u8 *iGpffffb2c8;
extern u8 *iGpffffb2cc;
extern u8 D_007E7B20[];
extern u8 *mdlGetMatrix();
extern void mdlScale(void *model, void *scale, s32 combineOp);
extern u8 D_005F12E0[];
extern u8 D_005F15F8[];
extern u8 D_005F1630[];
extern u8 D_005F1610[];
typedef struct FldActorIdSlot { u16 actorId; u8 pad02[0x74E]; } FldActorIdSlot;
extern FldActorIdSlot D_007F00D8[];
extern FldActorIdSlot D_007E9328[];
extern s32 FldFrameTask_Update(u8 *task);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern void mdlAdvanceModelFromFlags(s32 model);
extern s32 iGpffff9f00;
extern char D_005F11E8[];
extern char D_005F1200[];
extern s32 iGpffff9f08;
extern u8 *iGpffff9db0;
extern s32 FldDayEventActive();
extern s32 D_005F1350[];
extern void mdlAttachSlotModelFromResource(void *model, u16 slotIndex, u32 type, u16 id,
                           void *resource, u32 flags);
extern u8 iGpffff9f10;
extern u8 D_005F13A0[];


typedef struct FldMoveScratch
{
    RwV3d rayStart;
    RwV3d rayEnd;
    u8 pad68[8];
    RwV3d position;
    u8 pad7c[4];
    RwV3d moveStep;
    u8 pad8c[4];
    RwV3d hitPoint;
} FldMoveScratch;

extern s32 FldMap_IsCurrentInBandA(void);
extern s32 FldFrame_RaycastFieldWorlds(RwV3d *origin, RwV3d *vector, f32 fraction,
                         u16 fieldId);
extern void FldAmbientTrigger(s32 model, u16 mode, u16 id);




extern f32 iGpffff8094;

extern s32 RwEngineGetMatrixTolerances(RwV3d *task);
extern void RwMatrixOptimize(u8 *task, RwV3d *value);
extern void RwMatrixUpdate(u8 *task);


typedef signed __int128 s128;


static inline f32 code1_0016_cvt(s32 value) {
    return (f32)value;
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0016; members 00167f00-00168ec0 */

/* Build a 7-by-8 grid of 80-by-64 quads, snapshotting depth before any stores.
   measured: natural vertex assignment order, invariant hoisting and disabled
   propagation preserve retail's coordinate preparation and float registers.
   Object 252B/window 256B; exact instructions and a four-byte zero tail. */
/* measured: restore propagation and invariant baselines after the exact grid. */
/* measured: closing the single-function address-hoist bracket. */
/* measured: opt_propagation off preserves the render-state table base across calls. */
/* measured: closes the function-scoped opt_propagation probe. */
/* Matched full 759-instruction retail body.  The state accessor preserves the
 * read before the row-offset calculations across the branch join. */
#pragma push
#pragma pop
/* measured: opt_propagation off probe for retail field-load order in FldEnemyLoadTable */
/* measured: opt_propagation on closes the FldEnemyLoadTable load-order probe */
/* measured: opt_propagation off preserves the retail recomputed index and live register set in FldPartyModelRelease. */
/* measured: closes the opt_propagation bracket for FldPartyModelRelease. */
/* measured: direct global address expressions preserve retail bases while
   opt_loop_invariants hoists the stride (nd 14 -> 0). */
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
/* measured: closes the loop-invariant scope at the file baseline. */
/* measured: direct global address expression preserves retail base/stride
   register assignment while loop invariants hoist the stride (nd 0). */
/* measured: closes the loop-invariant scope at the file baseline. */
/* measured: optimization_level 1 reproduces FldDayEventActive's register coloring. */
/* measured: restore baseline optimization level after FldDayEventActive. */
/* Resolve the follower model lazily, then copy the owner position for type-3 resources. */
/* Byte-base fallbacks retain the measured payload/matrix aliasing;
 * proven layouts are documented above. */
// FUN_00167F00
s32 FldFrameTask_UpdateFollower(u8 *task)
{
    FldFollowerData *followerWork;
    s32 resourceType;
    s32 model;
    u16 resourceKey;
    u8 *work;
    u8 *sourceMatrix;
    u8 *entry;
    u8 *secondaryEntry;
    u8 *targetEntry;

    work = ((FldTaskStorage *)(task))->data;
    if (((FldFollowerData *)(work))->followerModel == 0) {
        resourceKey = ((FldFollowerData *)(work))->resourceKey;
        resourceType = (resourceKey & 0xFFC00) >> 0xA;
        switch (resourceType) {
        case 1:
            entry = MT_Scene_GetRes(resourceKey);
            ((FldFollowerData *)(work))->model = ((ResrcRecord *)(entry))->modelHandle164Value;
            MEMBER(s32, work, FldFollowerData, followerModel) = (s32)((ResrcRecord *)(entry))->handle228;
            break;
        case 3:
            secondaryEntry = MT_Scene_GetRes(resourceKey);
            if (((s32)((ResrcRecord *)(secondaryEntry))->unk28 & 0x10000000) != 0) {
                ((FldFollowerData *)(work))->model = ((ResrcRecord *)(secondaryEntry))->modelHandle164Value;
                MEMBER(s32, work, FldFollowerData, followerModel) = (s32)((ResrcRecord *)(secondaryEntry))->handle22C;
            }
            break;
        }
    }
    model = ((FldFollowerData *)(work))->model;
    followerWork = (FldFollowerData *)work;
    if ((model != 0) &&
        (followerWork->followerModel != 0) &&
        (((((FldFollowerData *)(work))->resourceKey & 0xFFC00) >> 0xA) == 3)) {
        sourceMatrix = (u8 *)mdlGetMatrix(model);
        targetEntry = (u8 *)mdlGetMatrix(MEMBER(s32, work, FldFollowerData, followerModel));
        ((RwMatrix *)(targetEntry))->pos =
            ((RwMatrix *)(sourceMatrix))->pos;
        mdlAdvanceModelFromFlags(MEMBER(s32, work, FldFollowerData, followerModel));
    }
    return 0;
}

// FUN_00168030
void FldFrameTask_DestroyFollower(u8 *task)
{
    (*DAT_008873EC)(((FldTaskStorage *)task)->data);
}

/* Apply movement in three collision-tested steps and sample the actor history every five ticks. */
/* Byte-base fallbacks retain the measured payload/matrix aliasing;
 * proven layouts are documented above. */
// FUN_00168060
s32 FldFrameTask_Update(u8 *task)
{
    FldMoveData *movementWork;
    FldActorHistory *historySample;
    FldMoveScratch stack;
    s32 state;
    s32 i;
    s32 offset;
    s32 *historyCounter;
    u32 counter;
    u8 *object;
    u8 *source;
    u8 *target;
    u8 *work;

    work = ((FldTaskStorage *)(task))->data;
    if ((((FldMoveData *)(work))->flags & 0x08000000) != 0) {
        return 0;
    }

    state = *(s32 *)work;
    switch (state) {
    case 0:
        object = mdlGetMatrix(((FldMoveData *)(work))->model);
        stack.position = ((RwMatrix *)(object))->pos;

        movementWork = (FldMoveData *)work;
    if (((MEMBER(u32, work, FldMoveData, flags) & 0x40000000) != 0) &&
            ((movementWork->flags & 0x10000000) == 0)) {
            stack.rayEnd = stack.position;
            stack.rayStart = stack.rayEnd;
            if (FldMap_IsCurrentInBandA() != 0) {
                stack.rayStart.y += 600.0f;
            } else {
                stack.rayStart.y += 200.0f;
            }
            stack.rayEnd.y -= 1000.0f;
            if (FldFrame_RaycastSelectedWorld(&stack.rayStart, &stack.hitPoint) == 1) {
                ((FldMoveData *)(work))->displacement.y = -(stack.position.y - stack.hitPoint.y);
            }
        }

        for (i = 0; i < 3; i++) {
            stack.moveStep.x = ((FldMoveData *)(work))->displacement.x / 3.0f;
            stack.moveStep.y = ((FldMoveData *)(work))->displacement.y / 3.0f;
            stack.moveStep.z = ((FldMoveData *)(work))->displacement.z / 3.0f;
            source = mdlGetMatrix(MEMBER(s32, work, FldMoveData, model));
            stack.position = ((RwMatrix *)(source))->pos;
            stack.position.y += ((FldMoveData *)(work))->height;
            if ((MEMBER(u32, work, FldMoveData, flags) & 0x10000000) == 0) {
                FldFrame_RaycastFieldWorlds(&stack.position, &stack.moveStep,
                              MEMBER(f32, work, FldMoveData, height), ((FldMoveData *)(work))->resourceKey);
            }
            mdlTranslateMatrix((RwMatrix *)MEMBER(s32, work, FldMoveData, model), &stack.moveStep, 2);
            if (((FldMoveData *)(work))->followerModel != 0) {
                source = mdlGetMatrix(MEMBER(s32, work, FldMoveData, model));
                target = mdlGetMatrix(MEMBER(s32, work, FldMoveData, followerModel));
                ((RwMatrix *)(target))->pos =
                    ((RwMatrix *)(source))->pos;
                mdlAdvanceModelFromFlags(MEMBER(s32, work, FldMoveData, followerModel));
            }
        }

        if ((s32)((FldMoveData *)(work))->actor != 0) {
            if ((MEMBER(u32, work, FldMoveData, flags) & 1) == 0) {
                counter = ((FldMoveData *)(work))->historyTicks;
                if (counter >= 5) {
                    target = ((FldMoveData *)(work))->actor;
                    ((FldActorHistory *)(((FldActorHistory *)(target))->writeIndex + (s32)target))[0].valid[0] = 1;
                    target = MEMBER(u8 *, work, FldMoveData, actor);
                    ((FldActorHistory *)(((u32)((FldActorHistory *)(target))->writeIndex << 3) +
                             (u32)target))[0].position[0].x =
                        MEMBER(f32, object, RwMatrix, pos.x);
                    target = MEMBER(u8 *, work, FldMoveData, actor);
                    ((FldActorHistory *)(((u32)((FldActorHistory *)(target))->writeIndex << 3) +
                             (u32)target))[0].position[0].z =
                        ((RwMatrix *)(object))->pos.z;
                    target = MEMBER(u8 *, work, FldMoveData, actor);
                    offset = ((FldActorHistory *)(target))->writeIndex * 12;
                    offset += (s32)target;
                    historySample = (FldActorHistory *)offset;
    historySample->forward[0] =
                        ((RwMatrix *)(object))->at;
                    target = MEMBER(u8 *, work, FldMoveData, actor);
                    ((FldActorHistory *)(target))->writeIndex += 1;
                    target = MEMBER(u8 *, work, FldMoveData, actor);
                    historyCounter = (s32 *)(target + 0x710);
                    if (((FldActorHistory *)(target))->writeIndex >= 0x40) {
                        *historyCounter = 0;
                    }
                    MEMBER(s32, work, FldMoveData, historyTicks) = 0;
                } else {
                    MEMBER(u32, work, FldMoveData, historyTicks) = counter + 1;
                }
            } else {
                ((FldMoveData *)(work))->historyTicks = 0;
            }
        }

        ((FldMoveData *)(work))->tileX =
            (s32)((MEMBER(f32, object, RwMatrix, pos.x) + 600.0f) / 1200.0f);
        ((FldMoveData *)(work))->tileZ =
            (s32)((((RwMatrix *)(object))->pos.z + 600.0f) / 1200.0f);
        if ((((FldMoveData *)(work))->resourceKey & 0x3FF) < 100) {
            FldAmbientTrigger(MEMBER(s32, work, FldMoveData, model), ((FldMoveData *)(work))->actorId,
                          ((FldMoveData *)(work))->resourceKey);
        }
        *(s32 *)work += 1;
        break;
    case 1:
    case 2:
    default:
        break;
    }
    return 0;
}

// FUN_00168470
void FldFrameTask_Destroy(u8 *task)
{
    (*DAT_008873EC)(((FldTaskStorage *)task)->data);
}

/* Allocate movement/follower tasks; raw actor-table aliases retain the measured stride/base expression order. */
// FUN_001684A0
/* measured: opt_loop_invariants hoists the two resource-table strides and
   their absolute bases for FldFrameTask_Spawn. */
/* measured: FldFrameTask_Spawn MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 FldFrameTask_Spawn(s32 parentTask, s32 resourceKey, f32 height)
{
    /* Named ABI/table accesses retain the measured byte-address expression order. */
    s32 taskHandle;
    s32 partyOffset;
    s32 enemyOffset;
    s32 partyIndex;
    s32 enemyIndex;
    s32 stride;
    u16 key;
    u32 resourceType;
    u8 *base;
    u8 *entry;
    u8 *secondaryEntry;
    u8 *targetEntry;
    u8 *record;
    u8 *enemyRecord;

    stride = 0x750;
    chkmemAllocSiteTag(D_005F15F8, 0x182);
    base = (u8 *)D_008873F4;
    entry = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x48, 0x40000);
    if (entry == NULL) {
        return 0;
    }
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F1630), 0xF, 0, 0, FldFrameTask_Update, FldFrameTask_Destroy, (u8 *)(entry));
    ((FldMoveData *)entry)->state = 1;
    key = resourceKey & 0xFFFF;
    ((FldMoveData *)entry)->resourceKey = resourceKey;
    ((FldMoveData *)entry)->height = height;
    ((FldMoveData *)entry)->unk28 = 0;
    resourceType = (u32)(resourceKey & 0xFFC00) >> 0xA;
    if (resourceType == 1) {
        secondaryEntry = MT_Scene_GetRes(key);
        if (secondaryEntry != NULL) {
            ((FldMoveData *)entry)->model = ((ResrcRecord *)(secondaryEntry))->modelHandle164Value;
        }
        partyIndex = 0;
        while (partyIndex < 4) {
            partyOffset = partyIndex * stride;
            record = D_007EF9B0 + partyOffset;
            if ((((FldActorHistory *)(record))->active != 0) &&
                (((FldActorHistory *)(record))->model == ((ResrcRecord *)(secondaryEntry))->modelHandle164Value)) {
                ((FldMoveData *)entry)->actorId = D_007F00D8[partyIndex].actorId;
                ((FldMoveData *)entry)->actor = record;
                break;
            }
            partyIndex += 1;
        }
        enemyIndex = 0;
        while (enemyIndex < 0xF) {
            enemyOffset = enemyIndex * stride;
            enemyRecord = D_007E8C00 + enemyOffset;
            if ((((FldActorHistory *)(enemyRecord))->active != 0) &&
                (((FldActorHistory *)(enemyRecord))->model == ((ResrcRecord *)(secondaryEntry))->modelHandle164Value)) {
                ((FldMoveData *)entry)->actorId = D_007E9328[enemyIndex].actorId;
                ((FldMoveData *)entry)->actor = enemyRecord;
                break;
            }
            enemyIndex += 1;
        }
    } else if (resourceType == 3) {
        targetEntry = MT_Scene_GetRes(key);
        if (targetEntry != NULL) {
            ((FldMoveData *)entry)->model = ((ResrcRecord *)(targetEntry))->modelHandle164Value;
        }
    }
    chkmemAllocSiteTag(D_005F15F8, 0x83);
    base = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x10, 0x40000);
    if (base != NULL) {
        (s32)kwlnTaskCreateChild((void *)(taskHandle), (const void *)(D_005F1610), 0x10, 0, 0, FldFrameTask_UpdateFollower, FldFrameTask_DestroyFollower, (u8 *)(base));
        ((FldFollowerData *)(base))->resourceKey = resourceKey;
    }
    return taskHandle;
}

/* measured: closes the opt_loop_invariants scope for FldFrameTask_Spawn. */
/* measured: FldFrameTask_GetPosition, FldFrameTask_SetOrientation, FldFrameTask_StartMove MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants off
// FUN_00168730
void FldFrameTask_SetFlags(u8 *task, s32 flags)
{
    u8 *work = ((FldTaskStorage *)task)->data;
    ((FldMoveData *)work)->flags = ((FldMoveData *)work)->flags | flags;
}

/* Clear only the requested movement/collision-control bits in the task payload. */
// FUN_00168750
void FldFrameTask_ClearFlags(u8 *task, s32 flags)
{
    u8 *work = ((FldTaskStorage *)task)->data;
    ((FldMoveData *)work)->flags = ((FldMoveData *)work)->flags & ~flags;
}

// FUN_00168770
f32 FldFrameTask_GetHeight(u8 *task)
{
    return ((FldMoveData *)((FldTaskStorage *)task)->data)->height;
}

/* Set height and disable collision when it is zero. */
// FUN_00168780
void FldFrameTask_SetHeight(u8 *task, f32 height) {
    u8 *record;

    record = (u8 *)(((FldTaskStorage *)task)->data);
    ((FldMoveData *)record)->height = height;
    if (height == 0.0f) {
        ((FldMoveData *)record)->flags = (s32) (((FldMoveData *)record)->flags | 0x10000000);
        return;
    }
    ((FldMoveData *)record)->flags = (s32) (((FldMoveData *)record)->flags & 0xEFFFFFFF);
}

// FUN_001687D0
s32 FldFrameTask_GetTileX(u8 *task)
{
    return ((FldMoveData *)((FldTaskStorage *)task)->data)->tileX;
}

// FUN_001687E0
s32 FldFrameTask_GetTileZ(u8 *task)
{
    return ((FldMoveData *)((FldTaskStorage *)task)->data)->tileZ;
}

/* Read the model position, returning zero when no model is bound. */
// FUN_001687F0
void FldFrameTask_GetPosition(u8 *destination, u8 *task)
{
    /* Named ABI/table accesses retain the measured byte-address expression order. */
    RwV3d position;
    u8 *clearCursor;
    s32 clearRemaining;
    s32 model;
    u8 *entry;
    u8 *record;

    record = ((FldTaskStorage *)task)->data;
    clearCursor = (u8 *)&position;
    clearRemaining = 0xC;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            clearRemaining -= 1;
        } while (clearRemaining != 0);
    }
    model = ((FldMoveData *)record)->model;
    if (model != 0) {
        entry = mdlGetMatrix(model, record);
        position = ((RwMatrix *)entry )->pos;
    }
    *(RwV3d *)destination = position;
}

/* Replace orientation while retaining position and actor scale; scale-table aliases retain their original byte addressing. */
// FUN_00168890
void FldFrameTask_SetOrientation(u8 *task, u8 *orientation)
{
    /* Byte-base fallbacks retain the measured payload/matrix aliasing. */
    RwV3d savedPosition;
    RwV3d zeroPosition;
    RwV3d initialTolerance;
    RwV3d basisTolerance;
    RwV3d finalTolerance;
    u8 *clearCursor;
    s32 clearRemaining;
    s32 model;
    u8 *work;
    u8 *entry;
    u8 *record;

    work = ((FldTaskStorage *)(task))->data;
    clearCursor = (u8 *)&zeroPosition;
    clearRemaining = 0xC;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            clearRemaining -= 1;
        } while (clearRemaining != 0);
    }
    model = ((FldMoveData *)(work))->model;
    if (model != 0) {
        entry = mdlGetMatrix(model);
        savedPosition = ((RwMatrix *)(entry))->pos;
        entry = mdlGetMatrix(MEMBER(s32, work, FldMoveData, model));
        ((RwMatrix *)(entry))->pos = zeroPosition;
        RwEngineGetMatrixTolerances(&initialTolerance);
        RwMatrixOptimize(
            mdlGetMatrix(MEMBER(s32, work, FldMoveData, model)),
            &initialTolerance);
        RwMatrixUpdate(mdlGetMatrix(MEMBER(s32, work, FldMoveData, model)));
        entry = mdlGetMatrix(MEMBER(s32, work, FldMoveData, model));
        *(RwV3d *)entry = *(RwV3d *)orientation;
        entry = mdlGetMatrix(MEMBER(s32, work, FldMoveData, model));
        ((RwMatrix *)(entry))->up = ((RwMatrix *)(orientation))->up;
        entry = mdlGetMatrix(MEMBER(s32, work, FldMoveData, model));
        ((RwMatrix *)(entry))->at = ((RwMatrix *)(orientation))->at;
        RwEngineGetMatrixTolerances(&basisTolerance);
        RwMatrixOptimize(
            mdlGetMatrix(MEMBER(s32, work, FldMoveData, model)),
            &basisTolerance);
        RwMatrixUpdate(mdlGetMatrix(MEMBER(s32, work, FldMoveData, model)));
        record = ((FldMoveData *)(work))->actor;
        if (record != NULL) {
            mdlScale(
                MEMBER(void *, work, FldMoveData, model),
                D_005F12E0 + ((FldActorHistory *)(record))->scaleGroup * 0x30 +
                    ((FldActorHistory *)(record))->scaleIndex * 0xC,
                2);
        }
        entry = mdlGetMatrix(MEMBER(s32, work, FldMoveData, model));
        ((RwMatrix *)(entry))->pos = savedPosition;
        RwEngineGetMatrixTolerances(&finalTolerance);
        RwMatrixOptimize(
            mdlGetMatrix(MEMBER(s32, work, FldMoveData, model)),
            &finalTolerance);
        RwMatrixUpdate(mdlGetMatrix(MEMBER(s32, work, FldMoveData, model)));
    }
}

/* Replace the model position, optimize its matrix, and refresh the cached field-cell coordinates. */
// FUN_00168AE0
void FldFrameTask_SetPosition(u8 *task, u8 *position)
{
    /* Byte-base fallbacks retain the measured payload/matrix aliasing. */
    RwV3d tolerance;
    s32 model;
    u8 *work;
    u8 *entry;

    work = ((FldTaskStorage *)(task))->data;
    model = ((FldMoveData *)(work))->model;
    if (model != 0) {
        entry = (u8 *)mdlGetMatrix(model);
        ((RwMatrix *)(entry))->pos =
            ((RwV3d *)position)[0];
        RwEngineGetMatrixTolerances(&tolerance);
        RwMatrixOptimize(
            (u8 *)mdlGetMatrix(MEMBER(s32, work, FldMoveData, model)),
            &tolerance);
        RwMatrixUpdate(
            (u8 *)mdlGetMatrix(MEMBER(s32, work, FldMoveData, model)));
        ((FldMoveData *)(work))->tileX =
            (s32)((600.0f +
                   ((RwMatrix *)(mdlGetMatrix(MEMBER(s32, work, FldMoveData, model))))->pos.x) /
                  1200.0f);
        ((FldMoveData *)(work))->tileZ =
            (s32)((600.0f +
                   ((RwMatrix *)(mdlGetMatrix(MEMBER(s32, work, FldMoveData, model))))->pos.z) /
                  1200.0f);
    }
}

/* Byte-base fallbacks retain the measured payload/matrix aliasing. */
/* Refresh the cached 1200-unit field-cell coordinates from the model's current world position. */
// FUN_00168C00
void FldFrameTask_UpdateTile(u8 *task) {
    u8 *work;

    work = ((FldTaskStorage *)(task))->data;
    ((FldMoveData *)(work))->tileX =
        (s32)((600.0f + ((RwMatrix *)(mdlGetMatrix(((FldMoveData *)(work))->model)))->pos.x) /
              1200.0f);
    ((FldMoveData *)(work))->tileZ =
        (s32)((600.0f + ((RwMatrix *)(mdlGetMatrix(MEMBER(s32, work, FldMoveData, model))))->pos.z) /
              1200.0f);
}

/* Queue a forward displacement and return the movement task to its collision-update state. */
// FUN_00168CB0
void FldFrameTask_StartMove(u8 *task, f32 distance)
{
    RwV3d displacement;
    u8 *clearCursor;
    s32 clearRemaining;
    s32 distanceIncrement;
    u8 *work;
    u8 *entry;

    work = ((FldTaskStorage *)task)->data;
    clearCursor = (u8 *)&displacement;
    clearRemaining = 0xC;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            clearRemaining -= 1;
        } while (clearRemaining != 0);
    }
    if (((FldMoveData *)work)->state == 1) {
        entry = mdlGetMatrix(((FldMoveData *)work)->model);
        displacement = ((RwMatrix *)entry)->at;
        RwV3dNormalize(&displacement, &displacement);
        displacement.x *= distance;
        displacement.y *= distance;
        displacement.z *= distance;
        if (!(2147483648.0f <= distance)) {
            distanceIncrement = (s32)distance;
        } else {
            distanceIncrement = (s32)(distance - 2147483648.0f);
            distanceIncrement |= (s32)0x80000000;
        }
        ((FldMoveData *)work)->distance += distanceIncrement;
        ((FldMoveData *)work)->displacement = displacement;
        ((FldMoveData *)work)->state = 0;
    }
}

/* Rotate around the model origin, retaining world position. */
/* Byte-base fallbacks retain the measured payload/matrix aliasing. */
// FUN_00168DE0
void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle) {
    RwV3d position;
    RwV3d negativePosition;
    s32 model;
    u8 *work;
    u8 *entry;

    work = ((FldTaskStorage *)(task))->data;
    model = ((FldMoveData *)(work))->model;
    if (model != 0) {
        entry = mdlGetMatrix(model);
        position = ((RwMatrix *)(entry))->pos;
        negativePosition.x = -1.0f * position.x;
        negativePosition.y = -1.0f * position.y;
        negativePosition.z = -1.0f * position.z;
        mdlTranslateMatrix((RwMatrix *)MEMBER(s32, work, FldMoveData, model), &negativePosition, 2);
        mdlRotateMatrix((void *)(u32)MEMBER(s32, work, FldMoveData, model), axis, angle, 2);
        mdlTranslateMatrix((RwMatrix *)MEMBER(s32, work, FldMoveData, model), &position, 2);
    }
}

/* Project onto the plane perpendicular to the dominant normal component and test triangle crossing parity. */
// FUN_00168EC0
s32 K_FldFrame_IsPointInTriangle(f32 *point, f32 **vertices, f32 *normal)
{
    f32 absoluteX;
    f32 absoluteY;
    f32 absoluteZ;
    s32 axis;
    s32 previous;
    s32 result;



    result = 0;
    absoluteX = fabsf(normal[0]);
    absoluteY = fabsf(normal[1]);
    absoluteZ = fabsf(normal[2]);
    axis = 0x7FFFFFFF;
    if (absoluteZ > absoluteY) {
        axis = (absoluteZ > absoluteX) ? 2 : 0;
    } else {
        if (absoluteY > absoluteX) {
            axis = 1;
        } else {
            axis = 0;
        }
    }
    if (axis != 0x7FFFFFFF) {
        previous = 2;
        switch (axis) {
        case 0: {
            f32 coord;
            s32 i;
            i = 0;
            coord = point[1];
            while (i < 3) {
                if ((vertices[i][1] <= coord && coord < vertices[previous][1]) ||
                    (vertices[previous][1] <= coord && coord < vertices[i][1])) {
                    if (point[2] <
                        vertices[i][2] +
                            ((coord - vertices[i][1]) *
                             (vertices[previous][2] - vertices[i][2])) /
                                (vertices[previous][1] - vertices[i][1])) {
                        result = !result;
                    }
                }
                previous = i;
                i += 1;
            }
            break;
        }
        case 1: {
            f32 coord;
            s32 i;
            i = 0;
            coord = point[2];
            while (i < 3) {
                if ((vertices[i][2] <= coord && coord < vertices[previous][2]) ||
                    (vertices[previous][2] <= coord && coord < vertices[i][2])) {
                    if (point[0] <
                        vertices[i][0] +
                            ((coord - vertices[i][2]) *
                             (vertices[previous][0] - vertices[i][0])) /
                                (vertices[previous][2] - vertices[i][2])) {
                        result = !result;
                    }
                }
                previous = i;
                i += 1;
            }
            break;
        }
        case 2: {
            f32 coord;
            s32 i;
            i = 0;
            coord = point[1];
            while (i < 3) {
                if ((vertices[i][1] <= coord && coord < vertices[previous][1]) ||
                    (vertices[previous][1] <= coord && coord < vertices[i][1])) {
                    if (point[0] <
                        vertices[i][0] +
                            ((coord - vertices[i][1]) *
                             (vertices[previous][0] - vertices[i][0])) /
                                (vertices[previous][1] - vertices[i][1])) {
                        result = !result;
                    }
                }
                previous = i;
                i += 1;
            }
            break;
        }
    }
    }
    return result;
}

