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


/* Actor table stride is 0x750; the movement callback wraps the history at 64. */
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
    u8 pad714[0x3c];
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
extern void chkmemAllocSiteTag(const void *msg, s32 line);
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
extern void mdlScale(void *task, void *value, s32 normal);
extern u8 D_005F12E0[];
extern u8 D_005F15F8[];
extern u8 D_005F1630[];
extern u8 D_005F1610[];
extern u8 D_007F00D8[];
extern u8 D_007E9328[];
extern s32 FldFrameTask_Update(u8 *task);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern void mdlAdvanceModelFromFlags(s32 task);
extern s32 iGpffff9f00;
extern char D_005F11E8[];
extern char D_005F1200[];
extern s32 iGpffff9f08;
extern u8 *iGpffff9db0;
extern s32 FldDayEventActive();
extern s32 D_005F1350[];
extern void mdlAttachSlotModelFromResource(void *task, u16 value, u32 normal, u16 arg3,
                           void *arg4, u32 arg5);
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
extern s32 FldFrame_RaycastFieldWorlds(RwV3d *task, RwV3d *value, f32 amount,
                         u16 normal);
extern void FldAmbientTrigger(s32 task, u16 value, u16 normal);




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
/* Raw payload/matrix accesses retained: typed access changed whole-file codegen;
 * proven layouts are documented above. */
// FUN_00167F00
s32 FldFrameTask_UpdateFollower(u8 *task)
{
    s32 resourceType;
    s32 model;
    u16 resourceKey;
    u8 *work;
    u8 *sourceMatrix;
    u8 *entry;
    u8 *secondaryEntry;
    u8 *targetEntry;

    work = *(u8 **)(task + 0x38);
    if (*(s32 *)(work + 0xC) == 0) {
        resourceKey = *(u16 *)(work + 4);
        resourceType = (resourceKey & 0xFFC00) >> 0xA;
        switch (resourceType) {
        case 1:
            entry = MT_Scene_GetRes(resourceKey);
            *(s32 *)(work + 8) = *(s32 *)(entry + 0x164);
            *(s32 *)(work + 0xC) = *(s32 *)(entry + 0x228);
            break;
        case 3:
            secondaryEntry = MT_Scene_GetRes(resourceKey);
            if ((*(s32 *)(secondaryEntry + 0x28) & 0x10000000) != 0) {
                *(s32 *)(work + 8) = *(s32 *)(secondaryEntry + 0x164);
                *(s32 *)(work + 0xC) = *(s32 *)(secondaryEntry + 0x22C);
            }
            break;
        }
    }
    model = *(s32 *)(work + 8);
    if ((model != 0) &&
        (*(s32 *)(work + 0xC) != 0) &&
        (((*(u16 *)(work + 4) & 0xFFC00) >> 0xA) == 3)) {
        sourceMatrix = (u8 *)mdlGetMatrix(model);
        targetEntry = (u8 *)mdlGetMatrix(*(s32 *)(work + 0xC));
        *(RwV3d *)(targetEntry + 0x30) =
            *(RwV3d *)(sourceMatrix + 0x30);
        mdlAdvanceModelFromFlags(*(s32 *)(work + 0xC));
    }
    return 0;
}

// FUN_00168030
void FldFrameTask_DestroyFollower(u8 *task)
{
    (*DAT_008873EC)(((FldTaskStorage *)task)->data);
}

/* Apply movement in three collision-tested steps and sample the actor history every five ticks. */
/* Raw payload/matrix accesses retained: typed access changed whole-file codegen;
 * proven layouts are documented above. */
// FUN_00168060
s32 FldFrameTask_Update(u8 *task)
{
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

    work = *(u8 **)(task + 0x38);
    if ((*(u32 *)(work + 4) & 0x08000000) != 0) {
        return 0;
    }

    state = *(s32 *)work;
    switch (state) {
    case 0:
        object = mdlGetMatrix(*(s32 *)(work + 0x10));
        stack.position = *(RwV3d *)(object + 0x30);

        if (((*(u32 *)(work + 4) & 0x40000000) != 0) &&
            ((*(u32 *)(work + 4) & 0x10000000) == 0)) {
            stack.rayEnd = stack.position;
            stack.rayStart = stack.rayEnd;
            if (FldMap_IsCurrentInBandA() != 0) {
                stack.rayStart.y += 600.0f;
            } else {
                stack.rayStart.y += 200.0f;
            }
            stack.rayEnd.y -= 1000.0f;
            if (FldFrame_RaycastSelectedWorld(&stack.rayStart, &stack.hitPoint) == 1) {
                *(f32 *)(work + 0x1C) = -(stack.position.y - stack.hitPoint.y);
            }
        }

        for (i = 0; i < 3; i++) {
            stack.moveStep.x = *(f32 *)(work + 0x18) / 3.0f;
            stack.moveStep.y = *(f32 *)(work + 0x1C) / 3.0f;
            stack.moveStep.z = *(f32 *)(work + 0x20) / 3.0f;
            source = mdlGetMatrix(*(s32 *)(work + 0x10));
            stack.position = *(RwV3d *)(source + 0x30);
            stack.position.y += *(f32 *)(work + 0x24);
            if ((*(u32 *)(work + 4) & 0x10000000) == 0) {
                FldFrame_RaycastFieldWorlds(&stack.position, &stack.moveStep,
                              *(f32 *)(work + 0x24), *(u16 *)(work + 8));
            }
            mdlTranslateMatrix((RwMatrix *)*(s32 *)(work + 0x10), &stack.moveStep, 2);
            if (*(s32 *)(work + 0x14) != 0) {
                source = mdlGetMatrix(*(s32 *)(work + 0x10));
                target = mdlGetMatrix(*(s32 *)(work + 0x14));
                *(RwV3d *)(target + 0x30) =
                    *(RwV3d *)(source + 0x30);
                mdlAdvanceModelFromFlags(*(s32 *)(work + 0x14));
            }
        }

        if (*(s32 *)(work + 0xC) != 0) {
            if ((*(u32 *)(work + 4) & 1) == 0) {
                counter = *(u32 *)(work + 0x3C);
                if (counter >= 5) {
                    target = *(u8 **)(work + 0xC);
                    *(u8 *)(*(s32 *)(target + 0x710) + (s32)target +
                            0x1D0) = 1;
                    target = *(u8 **)(work + 0xC);
                    *(f32 *)((*(u32 *)(target + 0x710) << 3) +
                             (u32)target + 0x210) =
                        *(f32 *)(object + 0x30);
                    target = *(u8 **)(work + 0xC);
                    *(f32 *)((*(u32 *)(target + 0x710) << 3) +
                             (u32)target + 0x214) =
                        *(f32 *)(object + 0x38);
                    target = *(u8 **)(work + 0xC);
                    offset = *(s32 *)(target + 0x710) * 12;
                    offset += (s32)target;
                    *(RwV3d *)(offset + 0x410) =
                        *(RwV3d *)(object + 0x20);
                    target = *(u8 **)(work + 0xC);
                    *(s32 *)(target + 0x710) += 1;
                    target = *(u8 **)(work + 0xC);
                    historyCounter = (s32 *)(target + 0x710);
                    if (*(s32 *)(target + 0x710) >= 0x40) {
                        *historyCounter = 0;
                    }
                    *(s32 *)(work + 0x3C) = 0;
                } else {
                    *(u32 *)(work + 0x3C) = counter + 1;
                }
            } else {
                *(s32 *)(work + 0x3C) = 0;
            }
        }

        *(s32 *)(work + 0x40) =
            (s32)((*(f32 *)(object + 0x30) + 600.0f) / 1200.0f);
        *(s32 *)(work + 0x44) =
            (s32)((*(f32 *)(object + 0x38) + 600.0f) / 1200.0f);
        if ((*(u16 *)(work + 8) & 0x3FF) < 100) {
            FldAmbientTrigger(*(s32 *)(work + 0x10), *(u16 *)(work + 0xA),
                          *(u16 *)(work + 8));
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
    /* Raw compound accesses retain byte-addressed ABI/table aliases and measured expression order. */
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
            ((FldMoveData *)entry)->model = *(s32 *)(secondaryEntry + 0x164);
        }
        partyIndex = 0;
        while (partyIndex < 4) {
            partyOffset = partyIndex * stride;
            record = D_007EF9B0 + partyOffset;
            if ((*(s32 *)(record + 0x48) != 0) &&
                (*(s32 *)(record + 0x50) == *(s32 *)(secondaryEntry + 0x164))) {
                ((FldMoveData *)entry)->actorId = *(u16 *)(D_007F00D8 + partyOffset);
                ((FldMoveData *)entry)->actor = record;
                break;
            }
            partyIndex += 1;
        }
        enemyIndex = 0;
        while (enemyIndex < 0xF) {
            enemyOffset = enemyIndex * stride;
            enemyRecord = D_007E8C00 + enemyOffset;
            if ((*(s32 *)(enemyRecord + 0x48) != 0) &&
                (*(s32 *)(enemyRecord + 0x50) == *(s32 *)(secondaryEntry + 0x164))) {
                ((FldMoveData *)entry)->actorId = *(u16 *)(D_007E9328 + enemyOffset);
                ((FldMoveData *)entry)->actor = enemyRecord;
                break;
            }
            enemyIndex += 1;
        }
    } else if (resourceType == 3) {
        targetEntry = MT_Scene_GetRes(key);
        if (targetEntry != NULL) {
            ((FldMoveData *)entry)->model = *(s32 *)(targetEntry + 0x164);
        }
    }
    chkmemAllocSiteTag(D_005F15F8, 0x83);
    base = ((u8 *(*)(s32, s32, s32))*(u32 *)base)(1, 0x10, 0x40000);
    if (base != NULL) {
        (s32)kwlnTaskCreateChild((void *)(taskHandle), (const void *)(D_005F1610), 0x10, 0, 0, FldFrameTask_UpdateFollower, FldFrameTask_DestroyFollower, (u8 *)(base));
        *(s16 *)(base + 4) = resourceKey;
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
    /* Raw compound accesses retain byte-addressed ABI/table aliases and measured expression order. */
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
    /* Raw payload/matrix accesses retained: typed fields changed whole-file codegen. */
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

    work = *(u8 **)(task + 0x38);
    clearCursor = (u8 *)&zeroPosition;
    clearRemaining = 0xC;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            clearRemaining -= 1;
        } while (clearRemaining != 0);
    }
    model = *(s32 *)(work + 0x10);
    if (model != 0) {
        entry = mdlGetMatrix(model);
        savedPosition = *(RwV3d *)(entry + 0x30);
        entry = mdlGetMatrix(*(s32 *)(work + 0x10));
        *(RwV3d *)(entry + 0x30) = zeroPosition;
        RwEngineGetMatrixTolerances(&initialTolerance);
        RwMatrixOptimize(
            mdlGetMatrix(*(s32 *)(work + 0x10)),
            &initialTolerance);
        RwMatrixUpdate(mdlGetMatrix(*(s32 *)(work + 0x10)));
        entry = mdlGetMatrix(*(s32 *)(work + 0x10));
        *(RwV3d *)entry = *(RwV3d *)orientation;
        entry = mdlGetMatrix(*(s32 *)(work + 0x10));
        *(RwV3d *)(entry + 0x10) = *(RwV3d *)(orientation + 0x10);
        entry = mdlGetMatrix(*(s32 *)(work + 0x10));
        *(RwV3d *)(entry + 0x20) = *(RwV3d *)(orientation + 0x20);
        RwEngineGetMatrixTolerances(&basisTolerance);
        RwMatrixOptimize(
            mdlGetMatrix(*(s32 *)(work + 0x10)),
            &basisTolerance);
        RwMatrixUpdate(mdlGetMatrix(*(s32 *)(work + 0x10)));
        record = *(u8 **)(work + 0xC);
        if (record != NULL) {
            mdlScale(
                *(void **)(work + 0x10),
                D_005F12E0 + *(u8 *)(record + 0x1CA) * 0x30 +
                    *(u8 *)(record + 0x1CB) * 0xC,
                2);
        }
        entry = mdlGetMatrix(*(s32 *)(work + 0x10));
        *(RwV3d *)(entry + 0x30) = savedPosition;
        RwEngineGetMatrixTolerances(&finalTolerance);
        RwMatrixOptimize(
            mdlGetMatrix(*(s32 *)(work + 0x10)),
            &finalTolerance);
        RwMatrixUpdate(mdlGetMatrix(*(s32 *)(work + 0x10)));
    }
}

// FUN_00168AE0
void FldFrameTask_SetPosition(u8 *task, u8 *position)
{
    /* Raw payload/matrix accesses retained: typed fields changed whole-file codegen. */
    RwV3d tolerance;
    s32 model;
    u8 *work;
    u8 *entry;

    work = *(u8 **)(task + 0x38);
    model = *(s32 *)(work + 0x10);
    if (model != 0) {
        entry = (u8 *)mdlGetMatrix(model);
        *(RwV3d *)(entry + 0x30) =
            *(RwV3d *)(position + 0x00);
        RwEngineGetMatrixTolerances(&tolerance);
        RwMatrixOptimize(
            (u8 *)mdlGetMatrix(*(s32 *)(work + 0x10)),
            &tolerance);
        RwMatrixUpdate(
            (u8 *)mdlGetMatrix(*(s32 *)(work + 0x10)));
        *(s32 *)(work + 0x40) =
            (s32)((600.0f +
                   *(f32 *)(mdlGetMatrix(*(s32 *)(work + 0x10)) +
                            0x30)) /
                  1200.0f);
        *(s32 *)(work + 0x44) =
            (s32)((600.0f +
                   *(f32 *)(mdlGetMatrix(*(s32 *)(work + 0x10)) +
                            0x38)) /
                  1200.0f);
    }
}

/* Raw payload/matrix accesses retained: typed fields changed whole-file codegen. */
// FUN_00168C00
void FldFrameTask_UpdateTile(u8 *task) {
    u8 *work;

    work = *(u8 **)(task + 0x38);
    *(s32 *)(work + 0x40) =
        (s32)((600.0f + *(f32 *)(mdlGetMatrix(*(s32 *)(work + 0x10)) + 0x30)) /
              1200.0f);
    *(s32 *)(work + 0x44) =
        (s32)((600.0f + *(f32 *)(mdlGetMatrix(*(s32 *)(work + 0x10)) + 0x38)) /
              1200.0f);
}

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
/* Raw payload/matrix accesses retained: typed fields changed whole-file codegen. */
// FUN_00168DE0
void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle) {
    RwV3d position;
    RwV3d negativePosition;
    s32 model;
    u8 *work;
    u8 *entry;

    work = *(u8 **)(task + 0x38);
    model = *(s32 *)(work + 0x10);
    if (model != 0) {
        entry = mdlGetMatrix(model);
        position = *(RwV3d *)(entry + 0x30);
        negativePosition.x = -1.0f * position.x;
        negativePosition.y = -1.0f * position.y;
        negativePosition.z = -1.0f * position.z;
        mdlTranslateMatrix((RwMatrix *)*(s32 *)(work + 0x10), &negativePosition, 2);
        mdlRotateMatrix((void *)(u32)*(s32 *)(work + 0x10), axis, angle, 2);
        mdlTranslateMatrix((RwMatrix *)*(s32 *)(work + 0x10), &position, 2);
    }
}

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

