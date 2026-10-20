#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "field_frame_internal.h"
#include "field_scene_internal.h"
#include "scene_resource_internal.h"
#include "Kosaka/k_model_internal.h"
#include "resrc_manager_internal.h"
#include "rw_frame_internal.h"
#include "member_access.h"

typedef struct RwMatrix RwMatrix;

/* FldCameraTaskCreate allocates 0x2d8 bytes; curve setup bounds keys at 32.
 * Snapshot capture/apply establish the vector and distance fields below.
 * Shifted scalar/vector cursors read segmentLength[index] and slotVector[index]
 * through the corresponding zero-index member where byte-base aliasing matters. */
/* Adjacent frame/debug handles share their scalar ABI storage with pointers. */
typedef union FldCameraHandleSlot { u8 *pointer; s32 value; void *task; } FldCameraHandleSlot;
/* Eight two-word records transfer one 64-byte matrix without changing load order. */
typedef struct FldCameraMatrixPair { s32 first; s32 second; } FldCameraMatrixPair;
/* This linker interior alias starts at the button word of each 0x4A-byte pad record. */
typedef struct FldCameraPadRecord { u16 buttons; u8 pad02[0x48]; } FldCameraPadRecord;
/* Matrix snapshots are copied as sixteen words, retaining the SDK flag/pad bits. */
typedef struct FldCameraMatrix { u32 words[16]; } FldCameraMatrix;
typedef struct FldCameraData {
    s32 state;
    s32 flags;
    s32 mode;
    union {
        struct { s32 targetFrame; s32 parentFrame; };
        FldCameraHandleSlot frameSlots[2];
    };
    RwV3d offset;
    f32 radius;
    f32 height;
    s32 unk28;
    s32 refreshCount;
    s32 unk30;
    s32 keyCount;
    f32 segmentLength[32];
    f32 pathTime;
    f32 maximumTime;
    f32 minimumTime;
    RwV3d pathPosition;
    RwV3d pathDirection;
    u8 paddc[0x0c];
    s8 slotValid[32];
    RwV3d slotVector[32];
    s32 targetResource;
    f32 desiredDistance;
    f32 minimumDistance;
    f32 currentDistance;
    s32 faded;
    RwV3d anchor;
    s32 fadeTask;
    f32 remainingYaw;
    RwV3d wallNormal;
    s32 slotBuffer;
    union { s32 matrix; FldCameraMatrix *matrixData; };
    union { s32 cachedMatrix; FldCameraMatrix *cachedMatrixData; };
    s32 cylinderTask;
    union {
        struct { s32 pathGroup; s32 pathSphere; s32 projectionSphere; };
        FldCameraHandleSlot debugSlots[3];
    };
} FldCameraData;
typedef struct FldCameraTask {
    u8 pad00[0x38];
    u8 *data;
} FldCameraTask;
typedef struct FldCameraRotation {
    s32 state;
    s32 duration;
    s32 elapsed;
    f32 initialAngle;
    f32 angle;
    f32 previousSine;
} FldCameraRotation;


extern s32 iGpffff9ef8;
extern void func_003e9cb0(void *frame, void *transform, s32 combine);
extern void K_View_SetFov(void *camera, f32 fov);
extern void FldCameraAdvanceCurve();
extern s32 iGpffff9f08;

extern s32* MT_Scene_GetFrameState(void);
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
extern void memset(void *dst, s32 value, u32 size);
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
extern u8 *kwlnGetCamera();
extern void func_003e9d50(u8 *, void *, f32, s32);
extern void K_ClumpLookAtBasis(u8 *object, void *position, void *target, s32 referenceUp);
extern void RwMatrixTranslate(void *, void *, s32);
extern void func_003e0e20(void *, void *, s32);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern u8 *func_003e9700(s32);
extern f32 D_007F1730[];

extern u8 D_005F16C8[];
extern u8 D_005F16D0[];

extern u8 D_007EF9F8[];
extern u8 D_007EFA00[];
extern u8 D_005F1698[];
extern u8 D_005F16E0[];
extern char D_005F16B0[];
extern u8 D_007948D0[];
extern void *func_003e9320(void);
extern void func_003e9df0(void *);
extern s32 func_003e0f80(void);
extern s32 FldCameraTaskUpdate(u8 *task);
extern s32 KDraw_CreateGroupTask(s32 parent, s32 curve, void *drawList);
extern s32 KDraw_CreateSphereTask(s32 parent, void *drawList);
extern s32 KDraw_CreateCylinderTask(s32 parent, void *drawList);
extern void KDraw_SetSphereColor(void *task, void *color);
extern f32 fabsf(f32 x);
extern f32 KDraw_MatrixYawDeg(u8 *matrix);
extern f32 K_View_GetFov(u8 *camera);
extern u8 *iGpffffb2c8;
extern u8 *iGpffffb2cc;
extern u8 D_007E7B20[];
extern u8 *mdlGetMatrix();
extern u8 D_005F12E0[];
extern u8 D_005F15F8[];
extern u8 D_005F1630[];
extern u8 D_005F1610[];
extern u8 D_007F00D8[];
extern u8 D_007E9328[];
extern s32 iGpffff9f00;
extern void func_003e99a0(void *);
extern void func_003e9390(void *);
extern void func_003e9830(s32, s32);
extern void func_003e0f40(s32);
extern char D_005F11E8[];
extern char D_005F1200[];
extern s32 iGpffff9f08;
extern u8 *iGpffff9db0;
extern s32 datGetFlag();
extern s32 FldStepIndex();
extern s32 FldDayEventActive();
extern s32 FldRoomIsListed(u16 field, u16 room);
extern s32 D_005F1350[];
extern void mdlSetColor(void *model, void *color);
extern void mdlAttachSlotModelFromResource(void *model, u16 slotIndex, u32 type, u16 id,
                           void *resource, u32 flags);
extern u8 iGpffff9f10;
extern u8 D_005F13A0[];




extern s32 FldFrame_RaycastFieldWorlds(RwV3d *origin, RwV3d *vector, f32 fraction,
                         u16 fieldId);


typedef struct FldCameraAngleScratch
{
    s64 axisXY;
    f32 axisZ;
    u8 pad3c[4];
    u8 zeroPosition[12];
    u8 pad4c[4];
    RwV3d position;
} FldCameraAngleScratch;
typedef struct FldCameraRotationScratch
{
    s64 stepAxisXY;
    f32 stepAxisZ;
    u8 pad4c[4];
    u8 stepZero[12];
    u8 pad5c[4];
    RwV3d stepPosition;
    u8 pad6c[4];
    s64 initialAxisXY;
    f32 initialAxisZ;
    u8 pad7c[4];
    u8 initialZero[12];
    u8 pad8c[4];
    RwV3d initialPosition;
} FldCameraRotationScratch;
extern f32 sinf(f32);
extern f32 iGpffff8094;

extern s32 RwEngineGetMatrixTolerances(RwV3d *);
extern void RwMatrixOptimize(u8 *, RwV3d *);


typedef signed __int128 s128;

typedef struct FldCameraSnapshotScratch
{
    u8 work[0x40];
    f32 fov;
    s16 mode;
    u8 pad86[2];
    f32 offsetX;
    f32 offsetY;
    f32 offsetZ;
    f32 radius;
    f32 height;
    f32 distance;
    f32 targetX;
    f32 targetY;
    f32 targetZ;
    u32 reserved6c; /* Cleared and copied with the seven-quadword snapshot. */
} __attribute__((aligned(16))) FldCameraSnapshotScratch;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0016; members 0016b8a0-0016ffd0 */

extern s32 FldEnemyLoadTable(u8 *file);
extern void FldPartyModelRelease(s32 slot);
extern s32 FldDayEventActive(void);
extern s32 FldRoomIsListed(u16 field, u16 room);
typedef struct FldRaySelectionResource
{
    u32 flags;
    u32 unknown04;
    void *fallback;
    u32 unknown0c;
    u32 unknown10;
    void *preferred;
    u8 pad18[0xA08];
    u8 *cameraPath; /* 0xA20: curve passed to func_003bb330/func_003bb5b0. */
} FldRaySelectionResource;
/* Choose the preferred world or fallback; same preferred/fallback rule as fldFrameSelectWorld. */
static inline void fldRaySelectWorld(const FldRaySelectionResource *selected, void **destination)
{
    void *world = selected->preferred;
    if (world != NULL) {
        *destination = world;
        return;
    }
    *destination = selected->fallback;
}
extern FldCameraPadRecord D_008C024C[];
extern u8 D_008C025C[];
extern u8 D_008C025D[];
extern u8 D_008C025E[];
extern u8 D_008C025F[];
extern f32 fGpffff8300;
extern f32 func_0044b920(f32 value);
extern f32 sqrtf(f32 x);
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
/* Four real ray/intersection pairs keep each enumeration's callback state.
 * The resource selector shares the existing field selector's output contract.
 * Measured: 1324 retail instruction bytes and four zero alignment bytes. */
/* Find the nearest field-world ray hit, checking neighboring grid cells before fallback models. */
// FUN_0016B8A0
s32 FldFrame_RaycastField(const RwV3d *line, RwV3d *hitPointDst)
{
    typedef struct FldRayLine
    {
        RwV3d point[2];
    } FldRayLine;
    typedef struct FldRayIntersection
    {
        FldRayLine line;
        u32 type;
    } FldRayIntersection;
    typedef struct FldRayContext
    {
        RwV3d *dst;
        u32 hit;
        FldRayIntersection intersection;
        f32 nearest;
        void *obj;
    } FldRayContext;
    extern u8 *MT_Scene_GetResListHead(s32 resourceType);
    extern s32 FldMap_IsCurrentInEitherBand(void);
    extern s32* MT_Scene_GetFrameState(void);
    extern void *FldFrame_RaycastWorldLocal(void *collisionWorld, void *data);
    extern void *RpClumpForAllAtomics(void *collisionWorld, void *(*cb)(void *, void *), void *ray);
    extern void *mdlGetClump(void *model);
    extern f32 fGpffff82b4;
    extern u8 *iGpffff9db0;
    extern s32 D_005F1670[];
    FldRayLine lineCopy __attribute__((aligned(16)));
    FldRayIntersection modelIntersection __attribute__((aligned(16)));
    FldRayContext modelRay __attribute__((aligned(16)));
    FldRayIntersection resourceIntersection __attribute__((aligned(16)));
    FldRayContext resourceRay __attribute__((aligned(16)));
    FldRayIntersection worldIntersection __attribute__((aligned(16)));
    FldRayContext worldRay __attribute__((aligned(16)));
    FldRayIntersection fallbackIntersection __attribute__((aligned(16)));
    FldRayContext fallbackRay __attribute__((aligned(16)));
    s32 result;
    s32 neighbor;
    void *selectedWorld;
    u8 *modelNode;
    u16 storedKey;
    u32 key;
    s32 fieldX;
    s32 fieldZ;
    u8 *object;
    u8 *entry;
    u8 *node;
    void *collisionWorld;

    lineCopy = *(const FldRayLine *)line;
    result = 0;
    object = (u8 *)((FieldSceneState *)iGpffff9db0)->templates[0].resource;
    if (object == NULL) {
        return 0;
    }
    if ((((FldRaySelectionResource *)object)->flags & 1) != 0) {
        goto query_complete;
    }
    selectedWorld = 0;
    if (FldMap_IsCurrentInEitherBand() != 0) {
        fieldX = (s32)((600.0f + lineCopy.point[0].x) / 1200.0f);
        fieldZ = (s32)((600.0f + lineCopy.point[0].z) / 1200.0f);
        neighbor = 0;
        while (neighbor < 5) {
            s32 *offsets = &D_005F1670[2 * neighbor];
            s32 *zOffset = offsets + 1;
            void *table;
            table = ((u8*)MT_Scene_GetFrameState());
            if (FldFrameCellAt((u8 *)table, fieldZ + *zOffset, fieldX + offsets[0])->occupied != 1) {
                goto next_cell;
            }
            offsets = &D_005F1670[2U * neighbor];
            table = ((u8*)MT_Scene_GetFrameState());
            storedKey = FldFrameCellAt((u8 *)table, fieldZ + *zOffset, fieldX + offsets[0])->resourceId;
            modelNode = MT_Scene_GetResListHead(0xA);
            key = storedKey;
            while (modelNode != NULL) {
                u16 *modelId = (u16 *)((ResrcRecord *)(modelNode))->slotHandle[0];
                if (modelId != NULL && *modelId == key && (((ResrcHeader *)modelNode)->flags & 2) != 0 && ((ResrcRecord *)(modelNode))->value150 == 1) {
                    selectedWorld = mdlGetClump(((ResrcRecord *)(modelNode))->slotHandle[1]);
                    modelRay.dst = hitPointDst;
                    modelRay.hit = 0;
                    modelRay.nearest = fGpffff82b4;
                    modelIntersection.type = 1;
                    modelIntersection.line = lineCopy;
                    modelRay.intersection = modelIntersection;
                    if (selectedWorld == NULL) {
                        result = 0;
                    } else {
                        RpClumpForAllAtomics(selectedWorld, FldFrame_RaycastWorldLocal, &modelRay);
                        result = modelRay.hit;
                    }
                    if (result == 1) {
                        break;
                    }
                }
                modelNode = (u8 *)((ResrcHeader *)modelNode)->next;
            }
            if (result == 1) {
                goto query_complete;
            }
            entry = MT_Scene_GetResListHead(0xC);
            while (entry != NULL) {
                if (((ResrcHeader *)entry)->id == key) {
                    u8 *resource = (u8 *)((ResrcRecord *)(entry))->handle1A0;
                    fldRaySelectWorld((const FldRaySelectionResource *)resource, &selectedWorld);
                    break;
                }
                entry = (u8 *)((ResrcHeader *)entry)->next;
            }
            resourceRay.dst = hitPointDst;
            resourceRay.hit = 0;
            resourceRay.nearest = fGpffff82b4;
            resourceIntersection.type = 1;
            resourceIntersection.line = lineCopy;
            resourceRay.intersection = resourceIntersection;
            if (selectedWorld == NULL) {
                result = 0;
            } else {
                RpClumpForAllAtomics(selectedWorld, FldFrame_RaycastWorldLocal, &resourceRay);
                result = resourceRay.hit;
            }
            if (result == 1) {
                goto query_complete;
            }
next_cell:
            neighbor += 1;
        }
        goto query_complete;
    } else {
        u8 *root = (u8 *)((FieldSceneState *)iGpffff9db0)->templates[0].resource;
        void *preferredWorld = ((FldRaySelectionResource *)root)->preferred;
        collisionWorld = preferredWorld != NULL ? preferredWorld : ((FldRaySelectionResource *)root)->fallback;
        worldRay.dst = hitPointDst;
        worldRay.hit = 0;
        worldRay.nearest = fGpffff82b4;
        worldIntersection.type = 1;
        worldIntersection.line = lineCopy;
        worldRay.intersection = worldIntersection;
        if (collisionWorld == NULL) {
            result = 0;
        } else {
            RpClumpForAllAtomics(collisionWorld, FldFrame_RaycastWorldLocal, &worldRay);
            result = worldRay.hit;
        }
        if (result == 1) {
            return result;
        }
        node = MT_Scene_GetResListHead(0xA);
        while (node != NULL) {
            if ((((ResrcHeader *)node)->flags & 2) != 0 && ((ResrcRecord *)(node))->value150 == 1) {
                void *modelWorld = mdlGetClump(((ResrcRecord *)(node))->slotHandle[1]);
                fallbackRay.dst = hitPointDst;
                fallbackRay.hit = 0;
                fallbackRay.nearest = fGpffff82b4;
                fallbackIntersection.type = 1;
                fallbackIntersection.line = lineCopy;
                fallbackRay.intersection = fallbackIntersection;
                if (modelWorld == NULL) {
                    result = 0;
                } else {
                    RpClumpForAllAtomics(modelWorld, FldFrame_RaycastWorldLocal, &fallbackRay);
                    result = fallbackRay.hit;
                }
                if (result == 1) {
                    break;
                }
            }
            node = (u8 *)((ResrcHeader *)node)->next;
        }
    }
query_complete:
    return result;
}

/* Camera follow: cylindrical target correction, waypoint interpolation,
 * wall projection and collision-constrained chase easing.
 *
 * measured 2026-10-13: fnalign 39 -> 16 (dbff44d7) -> 0; 2320 instructions,
 * frame 0x360. O3's early copy coalescer plus CSE off preserves the declared
 * sqrt/zero webs. Real phase snapshots replace the sharing normally supplied
 * by CSE; partial products and explicit affine addends retain the shared zero
 * in the retail MULA/ADDA/MADD sequences. Aggregate decomposition stays off
 * for the stack-vector ld/sd copies. The final 16 edits were genuine vector
 * argument bindings and helper-pointer snapshots, not a compiler floor.
 * See the comments at the call-crossing coordinate snapshots for stale reads.
 */
// FUN_0016BDD0
extern RwMatrix *RwMatrixRotate(RwMatrix *matrix, const RwV3d *axis, f32 angle, s32 op);
extern u8 *func_003e9680(u8 *frame);
/* RwV3dNormalize returns its original vector length in f0. */
extern u8 D_007F1710[];
extern u8 D_007F1720[];
extern void func_003bb5b0(u8 *path, s32 mode, f32 time, void *out, void *rot);
extern u8 *func_003e9c10(u8 *frame, const f32 *translation, s32 combineOp);
extern u8 *func_003e0670(u8 *dst, u8 *src);
extern f32 D_00756510[]; /* 0x756510 */
extern f32 D_00756514[]; /* 0x756514 */
extern f32 D_00756518[]; /* 0x756518 */
extern FldCameraPadRecord D_008C024C[];
extern u8 D_008C025E[];
extern f32 fGpffff84e4; /* 0xffff84e4 */
extern f32 fGpffff84e8; /* 0xffff84e8 */
extern u32 uGpffff9f2c; /* 0xffff9f2c */

extern u8 *FldCameraGetRecord(u8 *);
extern s32 KMisc_CreateRmdFade(s32, s32, s32, s32, s32);
extern s32 KDraw_IsEffectDone(u8 *);
extern void KDraw_SetGroupFlags(u8 *, u32);
extern void KDraw_SetSphereFlags(u8 *, u32);
extern void KDraw_SetSphereCenter(u8 *, u8 *);
extern void KDraw_SetCylinderFlags(u8 *, u32);
extern void KDraw_SetCylinderCenter(u8 *, u8 *);
extern void KDraw_SetCylinderRadius(u8 *, f32);
extern void KDraw_SetCylinderHeight(u8 *, f32);
extern s32 FldFrame_CollideSphereSelected(const RwV3d *, f32, RwV3d *, RwV3d *);
extern void FldCameraSetDistance(u8 *, f32);
extern f32 FldEvent_GetMoveStep(void);
extern f32 RwV3dLength(f32 *);
extern void kAssertFail(void *, s32);
extern void mdlSetAlphaBlend(void *);
extern void mdlClearAlphaBlend(void *);



extern f32 D_00756500[];
extern f32 D_00756510[];
extern f32 D_00756520[];
/* measured: scope the 39 -> 0 camera reconstruction to this function. */
#pragma push
/* measured: O3 early copy coalescing retains the declared f32 webs. */
/* measured: FldCameraTaskUpdate MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 3
/* measured: the O3 profile preserves retail's unscheduled delay slots. */
/* measured: FldCameraTaskUpdate MATCH -> MISMATCH without this pragma. */
#pragma schedule off
/* measured: keep loop-invariant motion off in the 39 -> 0 profile. */
/* measured: keep loop rotation off in the 39 -> 0 profile. */
/* measured: retain framed calls in the 39 -> 0 O3 profile. */
#pragma tailcall off
/* measured: CSE off prevents the sqrt and zero copies from folding into late temps. */
/* measured: FldCameraTaskUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: decomposition off recovers the retail stack-vector ld/sd copies. */
/* measured: FldCameraTaskUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_decomposeaggregates off
/* measured: retain the existing per-role lifetime splitting (39 -> 0). */
/* measured: propagation off preserves the real phase-value bindings. */
/* measured: FldCameraTaskUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: pullout off keeps the 55.0f and phase constants at their retail uses. */
s32 FldCameraTaskUpdate(u8 *task)

{
    /* Whole-aggregate casts below copy matrix/vector snapshots, not unnamed scalar fields. */
  extern s32 kwlnTaskDestroyWithHierarchy(void *);
  typedef struct { f32 x, y, z; } FldTriVec;
  extern f32 fabsf(f32);
  typedef struct { f32 x, y, z; } FldCopyVec;
  typedef struct { f32 x, y, z; } FldCamVec;
  typedef union { f32 coordinates[3]; FldCamVec vector; } FldCameraPosition;
  typedef struct {
    u8 prefix[0x28c];
    f32 desiredDistance, minimumDistance, currentDistance;
  } FldCameraDistances;
  typedef struct RwMatrixTolerance { f32 Normal, Orthogonal, Identity; } RwMatrixTolerance;
  extern s32 RwEngineGetMatrixTolerances(RwMatrixTolerance *tolerance);
  extern RwMatrix *RwMatrixOptimize(RwMatrix *matrix, const RwMatrixTolerance *tolerance);
  extern f32 sqrtf(f32 task);
  f32 projectedPoint[3];
  typedef union { f32 value; u8 bytes[4]; } FldCameraColour;
  FldCameraColour fadeColour;
  FldCopyVec followTarget;
  FldCopyVec followPosition;
  f32 followCorrection[3];
  f32 followCameraPosition[3];
  FldCopyVec pathTarget;
  f32 pathProjectionDelta[3];
  FldCopyVec pathBasis;
  f32 pathTargetDelta[3];
  f32 pathTargetDirection[3];
  RwMatrixTolerance tolerance3;
  f32 pathCameraPosition[3];
  f32 pathLookDirection[3];
  RwMatrixTolerance tolerance4;
  FldCopyVec orbitTarget;
  FldCopyVec orbitPosition;
  f32 orbitCorrection[3];
  f32 orbitPush[3];
  f32 orbitRayHit[3];
  FldCopyVec orbitFramePosition;
  f32 orbitCameraPosition[3];
  f32 wallNormal[3];
  f32 wallHit[3];
  f32 wallTangent[3];
  f32 cameraRight[3];
  f32 cameraForward[3];
  f32 collisionTangent[3];
  f32 collisionForward[3];
  FldCopyVec collisionPosition;
  f32 wallDelta[3];
  FldCamVec chaseTarget;
  FldCopyVec chasePosition;
  FldCamVec chaseOffset;
  f32 chaseCorrection[3];
  FldCamVec chaseHit;
  f32 chaseCameraPosition[3];
  f32 helperPosition[3];
  f32 followTargetPosition[3];
  f32 pathTargetPosition[3];
  f32 orbitTargetPosition[3];
  f32 chaseTargetPosition[3];
  FldCopyVec segment[2];
  FldCamVec chaseSegment[2];
    /* Retail returns zero at 0016E1D0, 0016BE18, 0016BE34. */
  u8 *frameMatrix;
  u8 *targetPositionBytes;
  f32 *recordCoordinates;
  u8 *camera;
  u8 * nearWallCamera;
  u8 * resumingCamera;
  u32 * helperRecord;
  u32 flags;
  s32 result;
  s32 keyIndex;
  s32 objectHandle;
  f32 correctionAmount;
  f32 collisionDistance;
  f32 rotationY;
  f32 distance;
  s32 moved;
  f32 stickOrMoveAmount;
  f32 upAxisZ;
  f32 wallSideDot;
  f32 distanceLimit;
  f32 cameraPositionZ;
  f32 wallPushDistance;
  f32 targetX7, targetY7, targetZ7, deltaX7, deltaZ7;
  f32 horizontalLength7, horizontalZero7, horizontalRadius7;
  f32 verticalHeight7, verticalRadius7, verticalAmount7, correctionZero7;
  f32 *correctionVector7;
  f32 chaseHorizontalCorrection;
  f32 deltaY;
  f32 verticalDelta;
  f32 timeCorrection;
  f32 orbitPositionY;
  f32 upAxisX;
  f32 distanceRatio;
  f32 wallRatio;
  f32 chaseDeltaY;
  f32 rotationX;
  f32 length;
  f32 orbitHorizontalCorrection;
  f32 verticalCorrection;
  f32 orbitHitDistance;
  f32 remainingYaw;
  f32 upAxisY;
  f32 wallYaw;
  f32 forwardWallDistance;
  f32 chaseDistanceLimit;
  u8 *lookAtCamera;
  FldCopyVec *followRecord;
  f32 targetX0, targetY0, targetZ0;
  f32 deltaX0, deltaZ0;
  f32 horizontalLength0, horizontalZero0, horizontalRadius0;
  f32 verticalHeight0, verticalRadius0, verticalAmount0, correctionZero0;
  f32 *correctionVector0;
  f32 followHorizontalCorrection;
  f32 followDeltaY;
  s32 followCameraHandle;
  s32 followMoved;
  u8 *pathCamera;
  f32 pathDirectionDot;
  f32 keyTimeStep;
  f32 targetX34, targetY34, targetZ34;
  f32 basisY34, basisZ34, projectionZero34;
  f32 originX34, originZ34, originY34;
  f32 projectionScale34, closestX34, closestY34, closestZ34;
  f32 pathRadius34;
  f32 rotationZ;
  f32 pathDistance;
  s32 segmentCount;
  s32 firstValidKey;
  s32 rotationFrame;
  s32 lookAtFrame;
  s32 pathHandle;
  u8 *orbitCamera;
  f32 *orbitRecord;
  f32 orbitMoveAmount;
  f32 orbitDeltaY;
  f32 targetX6, targetY6, targetZ6, deltaX6, deltaZ6;
  f32 horizontalLength6, horizontalZero6, horizontalRadius6;
  f32 verticalHeight6, verticalRadius6, correctionZero6;
  f32 *correctionVector6;
  f32 currentOrbitDistance;
  s32 orbitHandleOrResult;
  s32 followFrame;
  u32 orbitParentMatrix;
  s32 orbitRayResult;
  s32 orbitMatrixOrResult;
  s32 orbitMoved;
  u8 *chaseCamera;
  f32 *chaseRecord;
  f32 chaseDistance;
  f32 chaseTargetY, chaseTargetZ;
  f32 chaseMoveAmount;
  s32 chaseFrameHandle;
  u32 chaseParentMatrix;
  s32 chaseRayResult;
  s32 chaseMatrixHandle;
  s32 chaseMoved;
  s8 lo;
  s32 pathSegment;
  s8 hi;
  f32 resumeDistance;
  s32 pathLengthOffset;
  s32 pathMode34;
  s32 loPositionOffset;
  s32 hiPositionOffset;
  s32 refreshCount;
  s32 attachmentMode;
  u8 *detachedFrame;
  s32 *cameraData;
  cameraData = (s32 *)((FldCameraTask *)task)->data;
  if (((FldCameraData *)cameraData)->targetResource == 0) {
    return 0;
  }
  if ((((FldCameraData *)cameraData)->flags & 1U) != 0) {
    return 0;
  }
  {

    refreshCount = ((FldCameraData *)cameraData)->refreshCount;
    if (refreshCount < 0x80) {
      ((FldCameraData *)cameraData)->refreshCount = refreshCount + 1;
    }
    else {
      ((FldCameraData *)cameraData)->refreshCount = 0;
      frameMatrix = (u8 *)((RwObject *)(kwlnGetCamera()))->parent;
      func_003e0670((u8 *)((FldCameraData *)cameraData)->cachedMatrix,frameMatrix + 0x10);
      frameMatrix = (u8 *)((RwObject *)(kwlnGetCamera()))->parent;
      *(FldCameraMatrix *)&((RwFrame *)frameMatrix)->modelling = *((FldCameraData *)cameraData)->cachedMatrixData;
    }
    switch (((FldCameraData *)cameraData)->state) {
    case 0:
    {
      switch(((FldCameraData *)cameraData)->mode) {
      case 0:
      case 2:
      case 5:
        FldFrameTask_GetPosition((u8 *)&followTargetPosition[0],(u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->handle220);
        followTarget = *(FldCopyVec *)followTargetPosition;
        followRecord = (FldCopyVec *)FldCameraGetRecord(task);
        followPosition = *followRecord;
        followMoved = 0;
        attachmentMode = ((FldCameraData *)cameraData)->mode;
        if ((attachmentMode == 0) || (attachmentMode == 5)) {
          followCameraHandle = (s32)kwlnGetCamera();
          if ((s32)((RwObject *)((s32)((RwObject *)(followCameraHandle))->parent))->parent == ((FldCameraData *)cameraData)->parentFrame) {
            followCameraHandle = (s32)kwlnGetCamera();
            func_003e99a0((void *)(u32)((RwObject *)(followCameraHandle))->parent);
            func_003e9830(((FldCameraData *)cameraData)->parentFrame,((FldCameraData *)cameraData)->targetFrame);
            followCameraHandle = (s32)kwlnGetCamera();
            /* Previous measurement: typing this access changed b210 output (normalized_diff 6); the access form below preserves MATCH. */
            func_003e9830(((FldCameraData *)cameraData)->targetFrame,MEMBER(s32, followCameraHandle, RwObject, parent));
          }
        }
        else {
          followCameraHandle = (s32)kwlnGetCamera();
          if ((s32)((RwObject *)((s32)((RwObject *)(followCameraHandle))->parent))->parent != 0) {
            followCameraHandle = (s32)kwlnGetCamera();
            func_003e99a0((void *)(u32)((RwObject *)(followCameraHandle))->parent);
          }
          detachedFrame = (u8 *)((FldCameraData *)cameraData)->targetFrame;
          if ((s32)((RwObject *)(detachedFrame))->parent != 0) {
            func_003e99a0(detachedFrame);
          }
          followCameraHandle = (s32)kwlnGetCamera();
          /* Previous measurement: typing this access changed b210 output (normalized_diff 6); the access form below preserves MATCH. */
          func_003e9830(((FldCameraData *)cameraData)->parentFrame,MEMBER(s32, followCameraHandle, RwObject, parent));
        }
        targetX0 = (followTarget.x += ((FldCameraData *)cameraData)->offset.x);
        targetY0 = (followTarget.y += ((FldCameraData *)cameraData)->offset.y);
        targetZ0 = (followTarget.z += ((FldCameraData *)cameraData)->offset.z);
        deltaX0 = targetX0 - followPosition.x;
        followCorrection[0] = deltaX0;
        followDeltaY = targetY0 - followPosition.y;
        followCorrection[1] = followDeltaY;
        deltaZ0 = targetZ0 - followPosition.z;
        followCorrection[2] = deltaZ0;
        {
          const f32 squaredZ0 = deltaZ0 * deltaZ0;
          horizontalZero0 = 0.0f;
          horizontalLength0 = sqrtf(deltaX0 * deltaX0 + squaredZ0);
        }
        horizontalRadius0 = ((FldCameraData *)cameraData)->radius;
        if (!(horizontalLength0 <= horizontalRadius0)) {
          followHorizontalCorrection = horizontalLength0 - horizontalRadius0;
          followCorrection[1] = horizontalZero0;
          correctionVector0 = &followCorrection[0];
          RwV3dNormalize((RwV3d *)correctionVector0,(const RwV3d *)correctionVector0);
          followCorrection[0] = followCorrection[0] * followHorizontalCorrection;
          followCorrection[1] = followCorrection[1] * followHorizontalCorrection;
          followCorrection[2] = followCorrection[2] * followHorizontalCorrection;
          func_003e9c10((u8 *)((FldCameraData *)cameraData)->targetFrame,&followCorrection[0],2);
          followMoved = 1;
        }
        followCorrection[1] = followDeltaY;
        if (followDeltaY < 0.0f) {
          followDeltaY = followDeltaY * -1.0f;
        }
        verticalHeight0 = ((FldCameraData *)cameraData)->height;
        verticalRadius0 = verticalHeight0 / 2.0f;
        if (!(followDeltaY <= verticalRadius0)) {
          verticalAmount0 = followDeltaY - verticalRadius0;
          correctionZero0 = 0.0f;
          followCorrection[0] = 0.0f;
          followCorrection[2] = 0.0f;
          if (followCorrection[1] < correctionZero0) {
            followCorrection[1] = -verticalAmount0;
          }
          else {
            followCorrection[1] = verticalAmount0;
          }
          func_003e9c10((u8 *)((FldCameraData *)cameraData)->targetFrame,&followCorrection[0],2);
          followMoved = 1;
        }
        if ((followMoved == 1) && (((FldCameraData *)cameraData)->mode == 2)) {
          followCameraHandle = (s32)((RwObject *)(kwlnGetCamera()))->parent;
          *(FldCopyVec *)followCameraPosition = *(FldCopyVec *)&((RwFrame *)(followCameraHandle))->modelling.pos;
          lookAtCamera = (u8 *)kwlnGetCamera();
          targetPositionBytes = (u8 *)FldCameraGetRecord(task);
          K_ClumpLookAtBasis(lookAtCamera,(u8 *)((s32 *)&followCameraPosition[0]),targetPositionBytes,0);
        }
        goto LAB_0016e0c0;
      case 3:
      case 4:
        FldFrameTask_GetPosition((u8 *)&pathTargetPosition[0],(u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->handle220);
        pathTarget = *(FldCopyVec *)pathTargetPosition;
        segmentCount = ((FldCameraData *)cameraData)->keyCount - 1;
        keyTimeStep = 1.0f / (f32)segmentCount;
        if ((s32)((FldRaySelectionResource *)(((FieldSceneState *)iGpffff9db0)->templates[0].signedAddress))->cameraPath == 0) goto LAB_0016e0c0;
        for (firstValidKey = 0; firstValidKey < segmentCount; firstValidKey++) {
          if (((FldCameraData *)cameraData)->slotValid[firstValidKey] != '\0') break;
        }
        if (firstValidKey >= segmentCount) goto LAB_0016e0c0;
        /* Retail caches Y/Z across the path calls, but reloads X below. */
        targetX34 = (pathTarget.x += ((FldCameraData *)cameraData)->offset.x);
        targetY34 = (pathTarget.y += ((FldCameraData *)cameraData)->offset.y);
        targetZ34 = (pathTarget.z += ((FldCameraData *)cameraData)->offset.z);
        pathTargetDelta[0] = targetX34 - ((FldCameraData *)cameraData)->pathPosition.x;
        pathTargetDelta[1] = targetY34 - ((FldCameraData *)cameraData)->pathPosition.y;
        pathTargetDelta[2] = targetZ34 - ((FldCameraData *)cameraData)->pathPosition.z;
        RwV3dNormalize((RwV3d *)&pathTargetDirection[0],(const RwV3d *)&pathTargetDelta[0]);
        pathBasis = *(FldCopyVec *)&((FldCameraData *)cameraData)->pathDirection;
        basisY34 = pathBasis.y;
        basisZ34 = pathBasis.z;
        {
          const f32 directionZ = pathTargetDirection[2];
          f32 basisX34;
          f32 directionX, directionY;
          basisX34 = pathBasis.x;
          directionX = pathTargetDirection[0];
          directionY = pathTargetDirection[1];
          {
            const f32 yProduct = basisY34 * directionY;
            projectionZero34 = 0.0f;
            pathDirectionDot = basisX34 * directionX + yProduct + basisZ34 * directionZ;
          }
          originX34 = ((FldCameraData *)cameraData)->pathPosition.x;
          originZ34 = ((FldCameraData *)cameraData)->pathPosition.z;
          originY34 = ((FldCameraData *)cameraData)->pathPosition.y;
          projectionScale34 = (originX34 * basisX34 - pathTarget.x * basisX34 + originY34 * basisY34 - targetY34 * basisY34 +
                               originZ34 * basisZ34 - targetZ34 * basisZ34) /
                              -(basisX34 * basisX34 + basisY34 * basisY34 + basisZ34 * basisZ34);
          {
            const f32 affineOrigin = projectionZero34 + originX34;
            const f32 scaledDirection = basisX34 * projectionScale34;
            closestX34 = (projectedPoint[0] = affineOrigin + scaledDirection);
          }
          {
            const f32 affineOrigin = projectionZero34 + originY34;
            const f32 scaledDirection = basisY34 * projectionScale34;
            closestY34 = (projectedPoint[1] = affineOrigin + scaledDirection);
          }
          {
            const f32 affineOrigin = projectionZero34 + originZ34;
            const f32 scaledDirection = basisZ34 * projectionScale34;
            closestZ34 = (projectedPoint[2] = affineOrigin + scaledDirection);
          }
          pathProjectionDelta[0] = originX34 - closestX34;
          pathProjectionDelta[1] = originY34 - closestY34;
          pathProjectionDelta[2] = originZ34 - closestZ34;
        }
        pathDistance = RwV3dLength(&pathProjectionDelta[0]);
        {
          f32 acc = keyTimeStep;
          s32 last;

          pathSegment = 0;
          last = ((FldCameraData *)cameraData)->keyCount - 1;
          for (; pathSegment < last; pathSegment++) {
            if (!(acc <= ((FldCameraData *)cameraData)->pathTime)) break;
            acc = acc + keyTimeStep;
          }
          if (pathSegment >= last) {
            kAssertFail(D_005F1698,0x15b);
          }
        }
        pathRadius34 = ((FldCameraData *)cameraData)->radius;
        if (pathRadius34 < pathDistance) {
          f32 lengthRatio;
          pathLengthOffset = pathSegment * 4;
          /* Previous measurement: typing this access changed b210 output (normalized_diff 2); the access form below preserves MATCH. */
          lengthRatio = (pathDistance - pathRadius34) / ((FldCameraData *)(pathLengthOffset + (u32)cameraData))[0].segmentLength[0];
          timeCorrection = lengthRatio * keyTimeStep;
          if (!(pathDirectionDot <= 0.0f)) {
            ((FldCameraData *)cameraData)->pathTime = ((FldCameraData *)cameraData)->pathTime + timeCorrection;
          }
          else if (pathDirectionDot < -0.0f) {
            ((FldCameraData *)cameraData)->pathTime = ((FldCameraData *)cameraData)->pathTime - timeCorrection;
          }
          {
            f32 pathTime;
            f32 maximumTime = ((FldCameraData *)cameraData)->maximumTime;
            pathTime = ((FldCameraData *)cameraData)->pathTime;
            if (!(pathTime < maximumTime)) {
              ((FldCameraData *)cameraData)->pathTime = maximumTime;
            }
            else {
              const f32 minimumTime = ((FldCameraData *)cameraData)->minimumTime;
              if (pathTime <= minimumTime) {
                ((FldCameraData *)cameraData)->pathTime = minimumTime;
              }
            }
          }
          func_003bb5b0(((FldRaySelectionResource *)(((FieldSceneState *)iGpffff9db0)->templates[0].signedAddress))->cameraPath,10,((FldCameraData *)cameraData)->pathTime,
                       cameraData + 0x31,cameraData + 0x34);
          {
            f32 *pathDirection = ((f32 *)cameraData) + 0x34;
            RwV3dNormalize((RwV3d *)pathDirection,(const RwV3d *)pathDirection);
          }
        }
        pathMode34 = ((FldCameraData *)cameraData)->mode;
        if (pathMode34 == 3) {
          s32 last;
          s32 keyCount, penultimateKey, nextKey;

          rotationFrame = (s32)((RwObject *)(kwlnGetCamera()))->parent;
          keyIndex = pathSegment;
          while (0 < keyIndex) {
            if (((FldCameraData *)cameraData)->slotValid[keyIndex] != '\0') {
              lo = keyIndex;
              break;
            }
            keyIndex = keyIndex - 1;
          }
          if (keyIndex < 1) {
            kAssertFail(D_005F1698,0x187);
          }
          keyCount = ((FldCameraData *)cameraData)->keyCount;
          penultimateKey = keyCount - 2;
          nextKey = pathSegment + 1;
          if (penultimateKey < nextKey) {
            keyIndex = penultimateKey;
          }
          else {
            keyIndex = nextKey;
          }
          last = keyCount;
          last--;
          for (; keyIndex < last; keyIndex++) {
            if (((FldCameraData *)cameraData)->slotValid[keyIndex] != '\0') {
              hi = keyIndex;
              break;
            }
          }
          if (keyIndex >= last) {
            kAssertFail(D_005F1698,0x193);
          }
          {
            s32 lowIndex, highIndex;
            f32 span, loX, dx, loY, dy, loZ, dz, lowCoordinate;
            f32 interpolationZero, interpolationFraction;
            f32 *loData, *hiData;
            lowIndex = (s32)lo;
            highIndex = (s32)hi;
            span = keyTimeStep * (f32)(highIndex - lowIndex);
            loPositionOffset = lowIndex * 12;
            loData = (f32 *)(loPositionOffset + (u32)cameraData);
            loX = loData[0x42];
            hiPositionOffset = highIndex * 12;
            hiData = (f32 *)(hiPositionOffset + (u32)cameraData);
            dx = hiData[0x42] - loX;
            loY = loData[0x43];
            dy = hiData[0x43] - loY;
            loZ = loData[0x44];
            dz = hiData[0x44] - loZ;
            lowCoordinate = (f32)lo;
            {
              const f32 pathTime = ((FldCameraData *)cameraData)->pathTime;
              interpolationZero = 0.0f;
              {
                const f32 seededTime = interpolationZero + pathTime;
                const f32 lowTime = keyTimeStep * lowCoordinate;
                interpolationFraction = (seededTime - lowTime) / span;
              }
            }
            {
              const f32 affineOrigin = interpolationZero + loX;
              const f32 scaledDelta = dx * interpolationFraction;
              rotationX = affineOrigin + scaledDelta;
            }
            {
              const f32 affineOrigin = interpolationZero + loY;
              const f32 scaledDelta = dy * interpolationFraction;
              rotationY = affineOrigin + scaledDelta;
            }
            {
              const f32 affineOrigin = interpolationZero + loZ;
              const f32 scaledDelta = dz * interpolationFraction;
              rotationZ = affineOrigin + scaledDelta;
            }
          }
          {
            u32 identityOne = 0x3f800000;
            *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->at.z = identityOne;
            *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->up.y = identityOne;
            *(u32 *)&((RwMatrixTag *)((FldCameraData *)cameraData)->matrix)->right.x = identityOne;
          }
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->up.x = 0;
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->right.z = 0;
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->right.y = 0;
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->at.y = 0;
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->at.x = 0;
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->up.z = 0;
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->pos.z = 0;
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->pos.y = 0;
          *(u32 *)&((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->pos.x = 0;
          ((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->flags = ((RwMatrixTag *)(((FldCameraData *)cameraData)->matrix))->flags | 0x20003;
          RwMatrixRotate((RwMatrix *)((FldCameraData *)cameraData)->matrix,(const RwV3d *)D_00756500,rotationX,2);
          RwMatrixRotate((RwMatrix *)((FldCameraData *)cameraData)->matrix,(const RwV3d *)D_00756510,rotationY,2);
          RwMatrixRotate((RwMatrix *)((FldCameraData *)cameraData)->matrix,(const RwV3d *)D_00756520,rotationZ,2);
          func_003e9cb0((void *)rotationFrame,(void *)((FldCameraData *)cameraData)->matrix,0);
          *(FldCopyVec *)&((RwFrame *)(rotationFrame))->modelling.pos = *(FldCopyVec *)&((FldCameraData *)cameraData)->pathPosition;
          RwEngineGetMatrixTolerances(&tolerance3);
          RwMatrixOptimize((RwMatrix *)(rotationFrame + 0x10),&tolerance3);
          func_003e9680((u8 *)rotationFrame);
        }
        else if (pathMode34 == 4) {

          lookAtFrame = (s32)((RwObject *)(kwlnGetCamera()))->parent;
          *(FldTriVec *)&pathCameraPosition[0] = *(FldTriVec *)&((RwFrame *)(lookAtFrame))->modelling.pos;
          {
            u8 *frame = (u8 *)((FldCameraData *)cameraData)->targetFrame;
            pathLookDirection[0] = pathTarget.x - ((RwFrame *)(frame))->modelling.pos.x;
            pathLookDirection[1] = targetY34 - ((RwFrame *)(frame))->modelling.pos.y;
            pathLookDirection[2] = targetZ34 - ((RwFrame *)(frame))->modelling.pos.z;
          }
          pathCamera = (u8 *)kwlnGetCamera();
          K_ClumpLookAtBasis(pathCamera,(u8 *)((s32 *)&pathCameraPosition[0]),(u8 *)&pathLookDirection[0],0);
          *(FldCopyVec *)&((RwFrame *)(lookAtFrame))->modelling.pos = *(FldCopyVec *)&((FldCameraData *)cameraData)->pathPosition;
          RwEngineGetMatrixTolerances(&tolerance4);
          RwMatrixOptimize((RwMatrix *)(lookAtFrame + 0x10),&tolerance4);
          func_003e9680((u8 *)lookAtFrame);
        }
        goto LAB_0016e0c0;
      case 6:
        FldFrameTask_GetPosition((u8 *)&orbitTargetPosition[0],(u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->handle220);
        *(FldTriVec *)&orbitTarget.x = *(FldTriVec *)&orbitTargetPosition[0];
        orbitRecord = (f32 *)FldCameraGetRecord(task);
        orbitPosition = *(FldCopyVec *)orbitRecord;
        stickOrMoveAmount = (f32)D_008C025E[0] - 128.0f;
        orbitHandleOrResult = (s32)kwlnGetCamera();
        if ((s32)((RwObject *)((s32)((RwObject *)(orbitHandleOrResult))->parent))->parent == ((FldCameraData *)cameraData)->parentFrame) {
          orbitHandleOrResult = (s32)kwlnGetCamera();
          func_003e99a0((void *)(u32)((RwObject *)(orbitHandleOrResult))->parent);
          func_003e9830(((FldCameraData *)cameraData)->parentFrame,((FldCameraData *)cameraData)->targetFrame);
          orbitHandleOrResult = (s32)kwlnGetCamera();
          /* Previous measurement: typing this access changed b210 output (normalized_diff 6); the access form below preserves MATCH. */
          func_003e9830(((FldCameraData *)cameraData)->targetFrame,MEMBER(s32, orbitHandleOrResult, RwObject, parent));
        }
        targetX6 = (orbitTarget.x += ((FldCameraData *)cameraData)->offset.x);
        targetY6 = (orbitTarget.y += ((FldCameraData *)cameraData)->offset.y);
        targetZ6 = (orbitTarget.z += ((FldCameraData *)cameraData)->offset.z);
        deltaX6 = targetX6 - orbitPosition.x;
        orbitCorrection[0] = deltaX6;
        orbitPositionY = orbitPosition.y;
        orbitCorrection[1] = targetY6 - orbitPositionY;
        deltaZ6 = targetZ6 - orbitPosition.z;
        orbitCorrection[2] = deltaZ6;
        {
          const f32 squaredZ6 = deltaZ6 * deltaZ6;
          horizontalZero6 = 0.0f;
          horizontalLength6 = sqrtf(deltaX6 * deltaX6 + squaredZ6);
        }
        horizontalRadius6 = ((FldCameraData *)cameraData)->radius;
        if (!(horizontalLength6 <= horizontalRadius6)) {
          orbitHorizontalCorrection = horizontalLength6 - horizontalRadius6;
          orbitCorrection[1] = horizontalZero6;
          correctionVector6 = &orbitCorrection[0];
          RwV3dNormalize((RwV3d *)correctionVector6,(const RwV3d *)correctionVector6);
          orbitCorrection[0] = orbitCorrection[0] * orbitHorizontalCorrection;
          orbitCorrection[1] = orbitCorrection[1] * orbitHorizontalCorrection;
          orbitCorrection[2] = orbitCorrection[2] * orbitHorizontalCorrection;
          func_003e9c10((u8 *)((FldCameraData *)cameraData)->targetFrame,&orbitCorrection[0],2);
        }
        orbitDeltaY = orbitTarget.y - orbitPositionY;
        orbitCorrection[1] = orbitDeltaY;
        if (orbitDeltaY < 0.0f) {
          orbitDeltaY = orbitDeltaY * -1.0f;
        }
        verticalHeight6 = ((FldCameraData *)cameraData)->height;
        verticalRadius6 = verticalHeight6 / 2.0f;
        if (!(orbitDeltaY <= verticalRadius6)) {
          orbitDeltaY = orbitDeltaY - verticalRadius6;
          correctionZero6 = 0.0f;
          orbitCorrection[0] = 0.0f;
          orbitCorrection[2] = 0.0f;
          if (orbitCorrection[1] < correctionZero6) {
            orbitCorrection[1] = -orbitDeltaY;
          }
          else {
            orbitCorrection[1] = orbitDeltaY;
          }
          func_003e9c10((u8 *)((FldCameraData *)cameraData)->targetFrame,&orbitCorrection[0],2);
        }
        followFrame = (s32)((RwObject *)(kwlnGetCamera()))->parent;
        orbitParentMatrix = (u32)func_003e9700((u32)((RwObject *)(followFrame))->parent);
        orbitMoved = 0;
        collisionDistance = ((FldCameraData *)cameraData)->desiredDistance;
        *((FldCameraData *)cameraData)->matrixData = *(FldCameraMatrix *)&((RwFrame *)followFrame)->modelling;
        {
          f32 negativeX, negativeY, negativeZ, followDistance;
          f32 *pushVector;
          orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
          pushVector = &orbitPush[0];
          *(FldCopyVec *)orbitPush = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->at;
          RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
          negativeX = (orbitPush[0] = -orbitPush[0]);
          negativeY = (orbitPush[1] = -orbitPush[1]);
          negativeZ = (orbitPush[2] = -orbitPush[2]);
          followDistance = 55.0f + ((FldCameraData *)cameraData)->desiredDistance;
          orbitPush[0] = negativeX * followDistance;
          orbitPush[1] = negativeY * followDistance;
          orbitPush[2] = negativeZ * followDistance;
        }
        RwMatrixTranslate((void *)((FldCameraData *)cameraData)->matrix,&orbitPush[0],0);
        func_003e0e20((void *)((FldCameraData *)cameraData)->matrix,(void *)orbitParentMatrix,2);
        segment[0] = orbitTarget;
        orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
        segment[1] = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->pos;
        *((FldCameraData *)cameraData)->matrixData = *(FldCameraMatrix *)&((RwFrame *)followFrame)->modelling;
        orbitRayResult = FldFrame_RaycastField((const RwV3d *)segment,(RwV3d *)&orbitRayHit[0]);
        if (orbitRayResult == 1) {
          orbitRayHit[0] = orbitRayHit[0] - segment[0].x;
          orbitRayHit[1] = orbitRayHit[1] - segment[0].y;
          orbitRayHit[2] = orbitRayHit[2] - segment[0].z;
          orbitHitDistance = RwV3dLength(&orbitRayHit[0]);
          if (!(orbitHitDistance <= 0.0f)) {
            {
              f32 negativeX, negativeY, negativeZ;
              f32 *pushVector;
              orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
              pushVector = &orbitPush[0];
              *(FldCopyVec *)orbitPush = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->at;
              RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
              negativeX = (orbitPush[0] = -orbitPush[0]);
              negativeY = (orbitPush[1] = -orbitPush[1]);
              negativeZ = (orbitPush[2] = -orbitPush[2]);
              orbitPush[0] = negativeX * orbitHitDistance;
              orbitPush[1] = negativeY * orbitHitDistance;
              orbitPush[2] = negativeZ * orbitHitDistance;
            }
            RwMatrixTranslate((void *)((FldCameraData *)cameraData)->matrix,&orbitPush[0],0);
            orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
            *(FldCopyVec *)orbitCameraPosition = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->pos;
            collisionDistance = orbitHitDistance;
            orbitMoved = 1;
          }
        }
        if ((((D_008C024C[0].buttons & 0xf) != 0) || (stickOrMoveAmount < -48.0f)) || (!(stickOrMoveAmount <= 48.0f))) {
          ((FldCameraData *)cameraData)->remainingYaw = 0;
        }
        {
          f32 yawEntryZero;
          remainingYaw = ((FldCameraData *)cameraData)->remainingYaw;
          yawEntryZero = 0.0f;
          if (!(yawEntryZero == remainingYaw)) {
            f32 clampZero;
            correctionAmount = 3.0f;
            if (remainingYaw < yawEntryZero) {
              correctionAmount = correctionAmount * -1.0f;
            }
            clampZero = 0.0f;
            if (correctionAmount < clampZero) {
              const f32 remaining = remainingYaw - correctionAmount;
              if (!(remaining <= clampZero)) {
                correctionAmount = correctionAmount + remaining;
              }
            }
            else {
              const f32 remaining = remainingYaw - correctionAmount;
              if (remaining < clampZero) {
                correctionAmount = correctionAmount + remaining;
              }
            }
            orbitMatrixOrResult = (s32)MT_Scene_GetFrameState();
            FldCameraSetDistance(((FldFrame *)orbitMatrixOrResult)->cameraTask,correctionAmount);
            ((FldCameraData *)cameraData)->remainingYaw = (((FldCameraData *)cameraData)->remainingYaw - correctionAmount);
            {
              f32 completionZero = 0.0f;
              if (completionZero == correctionAmount) {
                ((FldCameraData *)cameraData)->remainingYaw = completionZero;
              }
            }
          }
        }
        {
          f32 wallZero, wallNormalX;
          wallNormalX = ((FldCameraData *)cameraData)->wallNormal.x;
          wallZero = 0.0f;
          if ((((wallZero != wallNormalX || wallZero != ((FldCameraData *)cameraData)->wallNormal.y) ||
               (wallZero != ((FldCameraData *)cameraData)->wallNormal.z)) &&
              ((((FldCameraData *)cameraData)->currentDistance < ((FldCameraData *)cameraData)->desiredDistance && ((D_008C024C[0].buttons & 0xf) == 0)))) &&
             ((!(stickOrMoveAmount < -48.0f) && ((stickOrMoveAmount <= 48.0f && (stickOrMoveAmount = FldEvent_GetMoveStep(), stickOrMoveAmount > 0.0f)))))) {
            {
              f32 forwardZ, forwardY, forwardX;
              f32 *forwardVector;
              orbitMatrixOrResult = (s32)func_003e9700((s32)followFrame);
              forwardVector = &cameraForward[0];
              *(FldCopyVec *)cameraForward = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->at;
              cameraForward[1] = 0.0f;
              RwV3dNormalize((RwV3d *)forwardVector,(const RwV3d *)forwardVector);
              upAxisY = D_00756514[0];
              forwardZ = cameraForward[2];
              upAxisZ = D_00756518[0];
              forwardY = cameraForward[1];
              cameraRight[0] = forwardY * upAxisZ - forwardZ * upAxisY;
              forwardX = cameraForward[0];
              upAxisX = D_00756510[0];
              cameraRight[1] = forwardZ * upAxisX - forwardX * upAxisZ;
              cameraRight[2] = forwardX * upAxisY - forwardY * upAxisX;
              {
                f32 *rightVector = &cameraRight[0];
                RwV3dNormalize((RwV3d *)rightVector,(const RwV3d *)rightVector);
              }
            }
            {
              f32 normalZ, normalY, normalX;
              normalZ = ((FldCameraData *)cameraData)->wallNormal.z;
              normalY = ((FldCameraData *)cameraData)->wallNormal.y;
              wallTangent[0] = normalY * upAxisZ - normalZ * upAxisY;
              normalX = ((FldCameraData *)cameraData)->wallNormal.x;
              wallTangent[1] = normalZ * upAxisX - normalX * upAxisZ;
              wallTangent[2] = normalX * upAxisY - normalY * upAxisX;
              {
                f32 *tangentVector = &wallTangent[0];
                RwV3dNormalize((RwV3d *)tangentVector,(const RwV3d *)tangentVector);
              }
            }
            {
              f32 forwardY, forwardX, forwardZ;
              f32 normalX, normalZ, normalY, facingZero, facingDot;
              forwardY = cameraForward[1];
              forwardX = cameraForward[0];
              normalX = wallTangent[0];
              forwardZ = cameraForward[2];
              normalZ = wallTangent[2];
              normalY = wallTangent[1];
              {
                const f32 yProduct = normalY * forwardY;
                facingZero = 0.0f;
                facingDot = normalX * forwardX + yProduct + normalZ * forwardZ;
              }
              if (facingDot < facingZero) {
                wallTangent[0] = -normalX;
                wallTangent[1] = -normalY;
                wallTangent[2] = -normalZ;
              }
              {
                f32 reloadedZ = wallTangent[2];
                f32 reloadedX = wallTangent[0];
                f32 reloadedY = wallTangent[1];
                f32 alignment = reloadedX * forwardX + reloadedY * forwardY + reloadedZ * forwardZ;
                wallYaw = 180.0f * (1.0f - alignment);
              }
            }
            wallSideDot = ((FldCameraData *)cameraData)->wallNormal.x * cameraRight[0] +
                     ((FldCameraData *)cameraData)->wallNormal.y * cameraRight[1] + ((FldCameraData *)cameraData)->wallNormal.z * cameraRight[2];
            if (wallSideDot < fGpffff84e4) {
              ((FldCameraData *)cameraData)->remainingYaw = -wallYaw;
            }
            else if (!(wallSideDot <= fGpffff84e8)) {
              ((FldCameraData *)cameraData)->remainingYaw = wallYaw;
            }
          }
        }
        ((FldCameraData *)cameraData)->wallNormal.x = 0;
        ((FldCameraData *)cameraData)->wallNormal.y = 0;
        ((FldCameraData *)cameraData)->wallNormal.z = 0;
        func_003e0e20((void *)((FldCameraData *)cameraData)->matrix,(void *)orbitParentMatrix,2);
        orbitMatrixOrResult = FldFrame_CollideSphereSelected((const RwV3d *)((u8 *)((FldCameraData *)cameraData)->matrix + 0x30),55.0f,(RwV3d *)&wallNormal[0],(RwV3d *)&wallHit[0]);
        if (orbitMatrixOrResult == 1) {
          *(FldCopyVec *)&((FldCameraData *)cameraData)->wallNormal.x = *(FldCopyVec *)&wallNormal;
          {
            f32 upY, normalZ, upZ, normalY, normalX, upX;
            upY = D_00756514[0];
            normalZ = wallNormal[2];
            upZ = D_00756518[0];
            normalY = wallNormal[1];
            collisionTangent[0] = normalY * upZ - normalZ * upY;
            normalX = wallNormal[0];
            upX = D_00756510[0];
            collisionTangent[1] = normalZ * upX - normalX * upZ;
            collisionTangent[2] = normalX * upY - normalY * upX;
            {
              f32 *tangentVector = &collisionTangent[0];
              RwV3dNormalize((RwV3d *)tangentVector,(const RwV3d *)tangentVector);
            }
          }
          {
            f32 *forwardVector;
            orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
            forwardVector = &collisionForward[0];
            *(FldCopyVec *)collisionForward = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->at;
            RwV3dNormalize((RwV3d *)forwardVector,(const RwV3d *)forwardVector);
          }
          {
            f32 targetX, targetY, targetZ;
            f32 tangentY, tangentX, tangentZ;
            f32 hitX, hitY, hitZ, projectionZero, projectionScale;
            FldFrameTask_GetPosition((u8 *)&orbitTarget.x,(u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->handle220);
            targetX = (orbitTarget.x += ((FldCameraData *)cameraData)->offset.x);
            targetY = (orbitTarget.y += ((FldCameraData *)cameraData)->offset.y);
            targetZ = (orbitTarget.z += ((FldCameraData *)cameraData)->offset.z);
            orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
            collisionPosition = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->pos;
            tangentY = collisionTangent[1];
            tangentX = collisionTangent[0];
            tangentZ = collisionTangent[2];
            hitX = wallHit[0];
            hitY = wallHit[1];
            hitZ = wallHit[2];
            {
              const f32 numeratorStart = hitX * tangentX;
              projectionZero = 0.0f;
              projectionScale = (numeratorStart - targetX * tangentX + hitY * tangentY - targetY * tangentY +
                                 hitZ * tangentZ - targetZ * tangentZ) /
                               -(tangentX * tangentX + tangentY * tangentY + tangentZ * tangentZ);
            }
            {
              const f32 affineOrigin = projectionZero + hitX;
              const f32 scaledDirection = tangentX * projectionScale;
              projectedPoint[0] = affineOrigin + scaledDirection;
            }
            {
              const f32 affineOrigin = projectionZero + hitY;
              const f32 scaledDirection = tangentY * projectionScale;
              projectedPoint[1] = affineOrigin + scaledDirection;
            }
            {
              const f32 affineOrigin = projectionZero + hitZ;
              const f32 scaledDirection = tangentZ * projectionScale;
              projectedPoint[2] = affineOrigin + scaledDirection;
            }
            wallDelta[0] = collisionPosition.x - hitX;
            wallDelta[1] = collisionPosition.y - hitY;
            /* Retail keeps camera Z across both vector-length calls. */
            cameraPositionZ = collisionPosition.z;
            wallDelta[2] = cameraPositionZ - hitZ;
            wallPushDistance = RwV3dLength(&wallDelta[0]);
          }
          wallDelta[0] = orbitTarget.x - projectedPoint[0];
          wallDelta[1] = orbitTarget.y - projectedPoint[1];
          wallDelta[2] = orbitTarget.z - projectedPoint[2];
          correctionAmount = RwV3dLength(&wallDelta[0]);
          forwardWallDistance = (orbitTarget.z - cameraPositionZ) / collisionForward[2];
          wallPushDistance = (55.0f - wallPushDistance) / ((correctionAmount - wallPushDistance) / forwardWallDistance);
          if (forwardWallDistance < 0.0f) {
            forwardWallDistance = forwardWallDistance * -1.0f;
          }
          if (wallPushDistance < 0.0f) {
            wallPushDistance = wallPushDistance * -1.0f;
          }
          if (collisionDistance <= 0.0f) {
            collisionDistance = ((FldCameraData *)cameraData)->desiredDistance;
          }
          {
            f32 wallRatio = fabsf((forwardWallDistance - wallPushDistance) / forwardWallDistance);
            {
              f32 maximumRatio = 1.0f;
              if (!(wallRatio <= maximumRatio)) {
                wallRatio = maximumRatio;
              }
            }
            {
              f32 normalThreshold, absoluteX;
              absoluteX = fabsf(wallNormal[0]);
              normalThreshold = 0.2f;
              if (!(absoluteX <= normalThreshold) && !(fabsf(wallNormal[2]) <= normalThreshold)) {
                wallRatio = wallRatio * 0.5f;
              }
            }
            collisionDistance = collisionDistance * wallRatio;
          }
          orbitMoved = 1;
        }
        if (orbitMoved == 1) {
          if (collisionDistance < ((FldCameraData *)cameraData)->currentDistance) {
            *((FldCameraData *)cameraData)->matrixData = *(FldCameraMatrix *)&((RwFrame *)followFrame)->modelling;
            {
              f32 negativeX, negativeY, negativeZ;
              f32 *pushVector;
              orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
              pushVector = &orbitPush[0];
              *(FldCamVec *)orbitPush = *(FldCamVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->at;
              RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
              negativeX = (orbitPush[0] = -orbitPush[0]);
              negativeY = (orbitPush[1] = -orbitPush[1]);
              negativeZ = (orbitPush[2] = -orbitPush[2]);
              orbitPush[0] = negativeX * collisionDistance;
              orbitPush[1] = negativeY * collisionDistance;
              orbitPush[2] = negativeZ * collisionDistance;
            }
            RwMatrixTranslate((void *)((FldCameraData *)cameraData)->matrix,&orbitPush[0],0);
            orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
            *(FldCopyVec *)orbitCameraPosition = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->pos;
            nearWallCamera = (u8 *)kwlnGetCamera();
            K_ClumpLookAtBasis(nearWallCamera,(u8 *)((s32 *)&orbitCameraPosition[0]),D_007F1710,0);
            ((FldCameraData *)cameraData)->currentDistance = collisionDistance;
          }
          else if ((0.0f == ((FldCameraData *)cameraData)->remainingYaw) && ((((FldCameraData *)cameraData)->flags & 2U) == 0)) {
            {
              f32 maximumStep;
              if (0.0f == (orbitMoveAmount = ((maximumStep = 15.0f) > FldEvent_GetMoveStep()) ? FldEvent_GetMoveStep() : maximumStep)) {
                orbitMoveAmount = 15.0f;
              }
            }
            currentOrbitDistance = ((FldCameraData *)cameraData)->currentDistance;
            if (collisionDistance <= currentOrbitDistance + orbitMoveAmount) {
              orbitMoveAmount = collisionDistance - currentOrbitDistance;
            }
            ((FldCameraData *)cameraData)->currentDistance = ((FldCameraData *)cameraData)->currentDistance + orbitMoveAmount;
            if (!(((FldCameraData *)cameraData)->currentDistance < collisionDistance)) {
              ((FldCameraData *)cameraData)->currentDistance = collisionDistance;
            }
            resumeDistance = ((FldCameraData *)cameraData)->desiredDistance;
            if (((FldCameraData *)cameraData)->currentDistance < resumeDistance) {
              *((FldCameraData *)cameraData)->matrixData = *(FldCameraMatrix *)&((RwFrame *)followFrame)->modelling;
              {
                f32 negativeX, negativeY, negativeZ, followDistance;
                f32 *pushVector;
                orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
                pushVector = &orbitPush[0];
                *(FldCamVec *)orbitPush = *(FldCamVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->at;
                RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
                negativeX = (orbitPush[0] = -orbitPush[0]);
                negativeY = (orbitPush[1] = -orbitPush[1]);
                negativeZ = (orbitPush[2] = -orbitPush[2]);
                followDistance = ((FldCameraData *)cameraData)->currentDistance;
                orbitPush[0] = negativeX * followDistance;
                orbitPush[1] = negativeY * followDistance;
                orbitPush[2] = negativeZ * followDistance;
              }
              RwMatrixTranslate((void *)((FldCameraData *)cameraData)->matrix,&orbitPush[0],0);
              orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
              *(FldCopyVec *)orbitCameraPosition = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->pos;
              func_003e0e20((void *)((FldCameraData *)cameraData)->matrix,(void *)orbitParentMatrix,2);
              orbitMatrixOrResult = FldFrame_CollideSphereSelected((const RwV3d *)((u8 *)((FldCameraData *)cameraData)->matrix + 0x30),55.0f,(RwV3d *)&wallNormal[0],(RwV3d *)&wallHit[0]);
              if (orbitMatrixOrResult == 0) {
                *(FldCopyVec *)&((FldCameraData *)cameraData)->wallNormal.x = *(FldCopyVec *)&wallNormal;
                resumingCamera = (u8 *)kwlnGetCamera();
                K_ClumpLookAtBasis(resumingCamera,(u8 *)((s32 *)&orbitCameraPosition[0]),D_007F1710,0);
              }
              else {
                ((FldCameraData *)cameraData)->currentDistance = (((FldCameraData *)cameraData)->currentDistance - orbitMoveAmount);
              }
            }
            else {
              ((FldCameraData *)cameraData)->currentDistance = resumeDistance;
            }
          }
        }
        else if (((((FldCameraData *)cameraData)->remainingYaw == 0.0f) && ((((FldCameraData *)cameraData)->flags & 2U) == 0)) &&
                (((FldCameraData *)cameraData)->currentDistance < ((FldCameraData *)cameraData)->desiredDistance)) {
          {
            f32 maximumStep;
            if (0.0f == (orbitMoveAmount = ((maximumStep = 15.0f) > FldEvent_GetMoveStep()) ? FldEvent_GetMoveStep() : maximumStep)) {
              orbitMoveAmount = 15.0f;
            }
          }
          {
            f32 currentDistance, desiredDistance;
            currentDistance = ((FldCameraData *)cameraData)->currentDistance;
            desiredDistance = ((FldCameraData *)cameraData)->desiredDistance;
            if (desiredDistance <= currentDistance + orbitMoveAmount) {
              orbitMoveAmount = desiredDistance - currentDistance;
            }
          }
          ((FldCameraData *)cameraData)->currentDistance = ((FldCameraData *)cameraData)->currentDistance + orbitMoveAmount;
          {
            f32 desiredDistance, currentDistance;
            desiredDistance = ((FldCameraData *)cameraData)->desiredDistance;
            currentDistance = ((FldCameraData *)cameraData)->currentDistance;
            if (!(currentDistance < desiredDistance)) {
              ((FldCameraData *)cameraData)->currentDistance = desiredDistance;
            }
          }
          {
            f32 negativeX, negativeY, negativeZ, followDistance;
            f32 *pushVector;
            orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
            pushVector = &orbitPush[0];
            *(FldCamVec *)orbitPush = *(FldCamVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->at;
            RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
            negativeX = (orbitPush[0] = -orbitPush[0]);
            negativeY = (orbitPush[1] = -orbitPush[1]);
            negativeZ = (orbitPush[2] = -orbitPush[2]);
            followDistance = ((FldCameraData *)cameraData)->currentDistance;
            orbitPush[0] = negativeX * followDistance;
            orbitPush[1] = negativeY * followDistance;
            orbitPush[2] = negativeZ * followDistance;
          }
          RwMatrixTranslate((void *)((FldCameraData *)cameraData)->matrix,&orbitPush[0],0);
          orbitMatrixOrResult = ((FldCameraData *)cameraData)->matrix;
          *(FldCopyVec *)orbitCameraPosition = *(FldCopyVec *)&((RwMatrixTag *)(orbitMatrixOrResult))->pos;
          func_003e0e20((void *)((FldCameraData *)cameraData)->matrix,(void *)orbitParentMatrix,2);
          orbitMatrixOrResult = FldFrame_CollideSphereSelected((const RwV3d *)((u8 *)((FldCameraData *)cameraData)->matrix + 0x30),55.0f,(RwV3d *)&wallNormal[0],(RwV3d *)&wallHit[0]);
          if (orbitMatrixOrResult == 0) {
            orbitCamera = (u8 *)kwlnGetCamera();
            K_ClumpLookAtBasis(orbitCamera,(u8 *)((s32 *)&orbitCameraPosition[0]),D_007F1710,0);
          }
          else {
            ((FldCameraData *)cameraData)->currentDistance = (((FldCameraData *)cameraData)->currentDistance - orbitMoveAmount);
            *(FldCopyVec *)&((FldCameraData *)cameraData)->wallNormal.x = *(FldCopyVec *)&wallNormal;
          }
        }
        FldFrameTask_GetPosition((u8 *)&orbitTarget.x,(u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->handle220);
        orbitTarget.y = orbitTarget.y + 180.0f;
        orbitHandleOrResult = (s32)func_003e9700((s32)followFrame);
        orbitFramePosition = *(FldCopyVec *)&((RwMatrixTag *)(orbitHandleOrResult))->pos;
        orbitCorrection[0] = orbitTarget.x - orbitFramePosition.x;
        orbitCorrection[1] = orbitTarget.y - orbitFramePosition.y;
        orbitCorrection[2] = orbitTarget.z - orbitFramePosition.z;
        orbitMoveAmount = RwV3dLength(&orbitCorrection[0]);
        {
          u8 *fadeTask = (u8 *)((FldCameraData *)cameraData)->fadeTask;
          if (fadeTask != (u8 *)0x0 &&
              (orbitHandleOrResult = KDraw_IsEffectDone(fadeTask), orbitHandleOrResult == 1)) {
            mdlClearAlphaBlend((u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->modelHandle164);
            kwlnTaskDestroyWithHierarchy((void *)((FldCameraData *)cameraData)->fadeTask);
            ((FldCameraData *)cameraData)->fadeTask = 0;
          }
        }
        fadeColour = *(const FldCameraColour *)&uGpffff9f2c;
        if (orbitMoveAmount <= 55.0f + ((FldCameraData *)cameraData)->minimumDistance) {
          if (((FldCameraData *)cameraData)->fadeTask != 0) {
            mdlClearAlphaBlend((u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->modelHandle164);
            kwlnTaskDestroyWithHierarchy((void *)((FldCameraData *)cameraData)->fadeTask);
            ((FldCameraData *)cameraData)->fadeTask = 0;
          }
          mdlSetColor((void *)(u32)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->modelHandle164,((s32 *)&fadeColour));
          ((FldCameraData *)cameraData)->faded = 1;
        }
        if (((FldCameraData *)cameraData)->faded != 1) goto LAB_0016e0c0;
        if (orbitMoveAmount <= 55.0f + ((FldCameraData *)cameraData)->minimumDistance) goto LAB_0016e0c0;
        mdlSetAlphaBlend((u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->modelHandle164);
        orbitHandleOrResult = KMisc_CreateRmdFade((s32)task,((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->modelHandle164Value,0,0xff,10);
        ((FldCameraData *)cameraData)->fadeTask = orbitHandleOrResult;
        ((FldCameraData *)cameraData)->faded = 0;
        goto LAB_0016e0c0;
      case 7:
        /* measured: direct vector/array/union storage removes two copy instructions (nd1379);
         * the access-site position union preserves the original snapshot transfer. */
        FldFrameTask_GetPosition((u8 *)&chaseTargetPosition[0],(u8 *)((ResrcRecord *)(((FldCameraData *)cameraData)->targetResource))->handle220);
        chaseTarget = ((FldCameraPosition *)chaseTargetPosition)->vector;
        chaseRecord = (f32 *)FldCameraGetRecord(task);
        chasePosition = *(FldCopyVec *)chaseRecord;
        chaseFrameHandle = (s32)kwlnGetCamera();
        if ((s32)((RwObject *)((s32)((RwObject *)(chaseFrameHandle))->parent))->parent == ((FldCameraData *)cameraData)->parentFrame) {
          chaseFrameHandle = (s32)kwlnGetCamera();
          func_003e99a0((void *)(u32)((RwObject *)(chaseFrameHandle))->parent);
          func_003e9830(((FldCameraData *)cameraData)->parentFrame,((FldCameraData *)cameraData)->targetFrame);
          chaseFrameHandle = (s32)kwlnGetCamera();
          /* Previous measurement: typing this access changed b210 output (normalized_diff 6); the access form below preserves MATCH. */
          func_003e9830(((FldCameraData *)cameraData)->targetFrame,MEMBER(s32, chaseFrameHandle, RwObject, parent));
        }
        targetX7 = (chaseTarget.x += ((FldCameraData *)cameraData)->offset.x);
        targetY7 = (chaseTarget.y += ((FldCameraData *)cameraData)->offset.y);
        targetZ7 = (chaseTarget.z += ((FldCameraData *)cameraData)->offset.z);
        deltaX7 = targetX7 - chasePosition.x;
        chaseCorrection[0] = deltaX7;
        chaseDeltaY = targetY7 - chasePosition.y;
        chaseCorrection[1] = chaseDeltaY;
        deltaZ7 = targetZ7 - chasePosition.z;
        chaseCorrection[2] = deltaZ7;
        {
          const f32 squaredZ7 = deltaZ7 * deltaZ7;
          horizontalZero7 = 0.0f;
          horizontalLength7 = sqrtf(deltaX7 * deltaX7 + squaredZ7);
        }
        horizontalRadius7 = ((FldCameraData *)cameraData)->radius;
        if (!(horizontalLength7 <= horizontalRadius7)) {
          chaseHorizontalCorrection = horizontalLength7 - horizontalRadius7;
          chaseCorrection[1] = horizontalZero7;
          correctionVector7 = &chaseCorrection[0];
          RwV3dNormalize((RwV3d *)correctionVector7,(const RwV3d *)correctionVector7);
          chaseCorrection[0] = chaseCorrection[0] * chaseHorizontalCorrection;
          chaseCorrection[1] = chaseCorrection[1] * chaseHorizontalCorrection;
          chaseCorrection[2] = chaseCorrection[2] * chaseHorizontalCorrection;
          func_003e9c10((u8 *)((FldCameraData *)cameraData)->targetFrame,&chaseCorrection[0],2);
        }
        chaseCorrection[1] = chaseDeltaY;
        if (chaseDeltaY < 0.0f) {
          chaseDeltaY = chaseDeltaY * -1.0f;
        }
        verticalHeight7 = ((FldCameraData *)cameraData)->height;
        verticalRadius7 = verticalHeight7 / 2.0f;
        if (!(chaseDeltaY <= verticalRadius7)) {
          verticalAmount7 = chaseDeltaY - verticalRadius7;
          correctionZero7 = 0.0f;
          chaseCorrection[0] = 0.0f;
          chaseCorrection[2] = 0.0f;
          if (chaseCorrection[1] < correctionZero7) {
            chaseCorrection[1] = -verticalAmount7;
          }
          else {
            chaseCorrection[1] = verticalAmount7;
          }
          func_003e9c10((u8 *)((FldCameraData *)cameraData)->targetFrame,&chaseCorrection[0],2);
        }
        chaseFrameHandle = (s32)((RwObject *)(kwlnGetCamera()))->parent;
        chaseParentMatrix = (u32)func_003e9700((u32)((RwObject *)(chaseFrameHandle))->parent);
        chaseMoved = 0;
        chaseDistance = ((FldCameraData *)cameraData)->desiredDistance;
        *((FldCameraData *)cameraData)->matrixData = *(FldCameraMatrix *)&((RwFrame *)chaseFrameHandle)->modelling;
        func_003e0e20((void *)((FldCameraData *)cameraData)->matrix,(void *)chaseParentMatrix,2);
        /* Retail retains these Y/Z snapshots across camera calls; X is reloaded. */
        chaseTargetY = (chaseTarget.y += ((FldCameraData *)cameraData)->anchor.y);
        chaseMatrixHandle = ((FldCameraData *)cameraData)->matrix;
        chaseOffset.x = ((RwMatrixTag *)(chaseMatrixHandle))->pos.x - chaseTarget.x;
        chaseOffset.y = ((RwMatrixTag *)(chaseMatrixHandle))->pos.y - chaseTargetY;
        chaseTargetZ = chaseTarget.z;
        chaseOffset.z = ((RwMatrixTag *)(chaseMatrixHandle))->pos.z - chaseTargetZ;
        {
          f32 scaledX, scaledY, scaledZ, chaseScale, directionX;
          f32 *chaseDirection = &chaseOffset.x;
          RwV3dNormalize((RwV3d *)chaseDirection,(const RwV3d *)chaseDirection);
          directionX = chaseOffset.x;
          chaseScale = ((FldCameraData *)cameraData)->desiredDistance;
          scaledX = (chaseOffset.x = directionX * chaseScale);
          scaledY = (chaseOffset.y = chaseOffset.y * chaseScale);
          scaledZ = (chaseOffset.z = chaseOffset.z * chaseScale);
          chaseSegment[0] = chaseTarget;
          chaseMatrixHandle = ((FldCameraData *)cameraData)->matrix;
          chaseSegment[1] = *(FldCamVec *)&((RwMatrixTag *)(chaseMatrixHandle))->pos;
          chaseSegment[1].x = chaseSegment[1].x + scaledX;
          chaseSegment[1].y = chaseSegment[1].y + scaledY;
          chaseSegment[1].z = chaseSegment[1].z + scaledZ;
        }
        *((FldCameraData *)cameraData)->matrixData = *(FldCameraMatrix *)&((RwFrame *)chaseFrameHandle)->modelling;
        chaseRayResult = FldFrame_RaycastField((const RwV3d *)chaseSegment,(RwV3d *)&chaseHit.x);
        if (chaseRayResult == 1) {
          chaseHit.x = chaseHit.x - chaseSegment[0].x;
          chaseHit.y = chaseHit.y - chaseSegment[0].y;
          chaseHit.z = chaseHit.z - chaseSegment[0].z;
          {
            f32 *hitVector = &chaseHit.x;
            chaseMoveAmount = RwV3dNormalize((RwV3d *)hitVector,(const RwV3d *)hitVector);
          }
          if (!(chaseMoveAmount <= 0.0f)) {
            {
              f32 *chaseDirection = &chaseOffset.x;
              chaseOffset = chaseHit;
              RwV3dNormalize((RwV3d *)chaseDirection,(const RwV3d *)chaseDirection);
            }
            chaseOffset.x = chaseOffset.x * chaseMoveAmount;
            chaseOffset.y = chaseOffset.y * chaseMoveAmount;
            chaseOffset.z = chaseOffset.z * chaseMoveAmount;
            RwMatrixTranslate((void *)((FldCameraData *)cameraData)->matrix,&chaseOffset.x,0);
            ((RwMatrixTag *)((FldCameraData *)cameraData)->matrix)->pos.y = ((FldCameraData *)cameraData)->anchor.y;
            chaseFrameHandle = ((FldCameraData *)cameraData)->matrix;
            *(FldCopyVec *)chaseCameraPosition = *(FldCopyVec *)&((RwMatrixTag *)(chaseFrameHandle))->pos;
            chaseDistance = chaseMoveAmount;
            chaseMoved = 1;
          }
        }
        if (chaseMoved == 1) {
          if (chaseDistance < ((FldCameraData *)cameraData)->currentDistance) {
            chaseCamera = (u8 *)kwlnGetCamera();
            K_ClumpLookAtBasis(chaseCamera,(u8 *)((s32 *)&chaseCameraPosition[0]),D_007F1720,0);
            ((FldCameraData *)cameraData)->currentDistance = chaseDistance;
          }
        }
        else if (!(chaseDistance <= ((FldCameraData *)cameraData)->currentDistance)) {
          {
            f32 maximumStep;
            if (0.0f == (chaseMoveAmount = ((maximumStep = 20.0f) > FldEvent_GetMoveStep()) ? FldEvent_GetMoveStep() : maximumStep)) {
              chaseMoveAmount = 20.0f;
            }
          }
          ((FldCameraData *)cameraData)->currentDistance = ((FldCameraData *)cameraData)->currentDistance + chaseMoveAmount;
          {
            f32 desiredDistance, currentDistance;
            desiredDistance = ((FldCameraData *)cameraData)->desiredDistance;
            currentDistance = ((FldCameraData *)cameraData)->currentDistance;
            if (!(currentDistance <= desiredDistance)) {
              ((FldCameraData *)cameraData)->currentDistance = desiredDistance;
            }
          }
          func_003e0e20((void *)((FldCameraData *)cameraData)->matrix,(void *)chaseParentMatrix,2);
          chaseFrameHandle = ((FldCameraData *)cameraData)->matrix;
          chaseOffset.x = ((RwMatrixTag *)(chaseFrameHandle))->pos.x - chaseTarget.x;
          chaseOffset.y = ((RwMatrixTag *)(chaseFrameHandle))->pos.y - chaseTargetY;
          chaseOffset.z = ((RwMatrixTag *)(chaseFrameHandle))->pos.z - chaseTargetZ;
          {
            f32 chaseScale, directionX;
            f32 *chaseDirection = &chaseOffset.x;
            RwV3dNormalize((RwV3d *)chaseDirection,(const RwV3d *)chaseDirection);
            directionX = chaseOffset.x;
            chaseScale = ((FldCameraData *)cameraData)->currentDistance;
            chaseOffset.x = directionX * chaseScale;
            chaseOffset.y = chaseOffset.y * chaseScale;
            chaseOffset.z = chaseOffset.z * chaseScale;
          }
          RwMatrixTranslate((void *)((FldCameraData *)cameraData)->matrix,&chaseOffset.x,0);
          *(FldCopyVec *)chaseCameraPosition = *(FldCopyVec *)&((RwMatrixTag *)((FldCameraData *)cameraData)->matrix)->pos;
          chaseCameraPosition[1] = ((FldCameraData *)cameraData)->anchor.y;
          chaseCamera = (u8 *)kwlnGetCamera();
          K_ClumpLookAtBasis(chaseCamera,(u8 *)((s32 *)&chaseCameraPosition[0]),D_007F1720,0);
        }
        goto LAB_0016e0c0;
      default:
LAB_0016e0c0:
        KDraw_SetCylinderFlags((u8 *)((FldCameraData *)cameraData)->cylinderTask,(u32)((((FldCameraData *)cameraData)->flags & 0x80000000U) != 0));
        helperRecord = (u32 *)FldCameraGetRecord(task);
        {
          u8 *targetPosition = (u8 *)&helperPosition[0];
          *(FldCopyVec *)helperPosition = *(FldCopyVec *)helperRecord;
          KDraw_SetCylinderCenter((u8 *)((FldCameraData *)cameraData)->cylinderTask,targetPosition);
        }
        KDraw_SetCylinderRadius((u8 *)((FldCameraData *)cameraData)->cylinderTask,((FldCameraData *)cameraData)->radius);
        KDraw_SetCylinderHeight((u8 *)((FldCameraData *)cameraData)->cylinderTask,((FldCameraData *)cameraData)->height);
        if ((s32)((FldRaySelectionResource *)(((FieldSceneState *)iGpffff9db0)->templates[0].signedAddress))->cameraPath != 0) {
          {
            u8 *cameraHelper = (u8 *)((FldCameraData *)cameraData)->pathGroup;
            if (cameraHelper != (u8 *)0x0) {
              KDraw_SetGroupFlags(cameraHelper,(u32)((((FldCameraData *)cameraData)->flags & 0x80000000U) != 0));
            }
          }
          {
            u8 *pathHelper = (u8 *)((FldCameraData *)cameraData)->pathSphere;
            if (pathHelper != (u8 *)0x0) {
              KDraw_SetSphereFlags(pathHelper,(u32)((((FldCameraData *)cameraData)->flags & 0x80000000U) != 0));
              KDraw_SetSphereCenter((u8 *)((FldCameraData *)cameraData)->pathSphere,(u8 *)(cameraData + 0x31));
            }
          }
          {
            u8 *projectionHelper = (u8 *)((FldCameraData *)cameraData)->projectionSphere;
            if (projectionHelper != (u8 *)0x0) {
              KDraw_SetSphereFlags(projectionHelper,(u32)((((FldCameraData *)cameraData)->flags & 0x80000000U) != 0));
              KDraw_SetSphereCenter((u8 *)((FldCameraData *)cameraData)->projectionSphere,(u8 *)&projectedPoint[0]);
            }
          }
        }
        break;
      }
    }
      break;
    case 1:
      break;
    }
  }
  return 0;
}

/* measured: restore the surrounding translation-unit settings. */
#pragma pop
/* Detach camera frames, restore the parent hierarchy and release the three matrix buffers. */
// FUN_0016E210
void FldCameraTaskDestroy(u8 *task) {
    u8 *cameraData;

    /* Previous measurement: typing this access changed b210 output (normalized_diff 5); the access form below preserves MATCH. */
    cameraData = MEMBER(u8 *, task, FldCameraTask, data);
    if ((s32)((RwObject *)((u8 *)((RwObject *)kwlnGetCamera())->parent))->parent != 0) {
        func_003e99a0(((RwObject *)(kwlnGetCamera()))->parent);
    }
    /* Previous measurement: typing this access changed b210 output (normalized_diff 135); the access form below preserves MATCH. */
    if ((s32)((RwObject *)(MEMBER(u8 *, cameraData, FldCameraData, targetFrame)))->parent != 0) {
        func_003e99a0((void *)((FldCameraData *)cameraData)->targetFrame);
    }
    func_003e9390((void *)((FldCameraData *)cameraData)->targetFrame);
    /* Previous measurement: typing this access changed b210 output (normalized_diff 6); the access form below preserves MATCH. */
    func_003e9830(((FldCameraData *)cameraData)->parentFrame, MEMBER(s32, kwlnGetCamera(), RwObject, parent));
    func_003e0f40(((FldCameraData *)cameraData)->slotBuffer);
    func_003e0f40(((FldCameraData *)cameraData)->matrix);
    func_003e0f40(((FldCameraData *)cameraData)->cachedMatrix);
    (*DAT_008873EC)(((FldCameraTask *)task)->data);
}

/* measured: opt_common_subs off preserves the retail per-call table address
   materialization and five-register frame in FldCameraTaskCreate. */
/* Allocate the 0x2d8 camera payload, its frame/matrix buffers and optional path debug helpers. */
// FUN_0016E2E0
#pragma push
/* measured: FldCameraTaskCreate MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
s32 FldCameraTaskCreate(s32 parentTask)
{
    s32 taskHandle;
    s32 pathHandle;
    u8 *cameraData;
    u8 *targetFrame;
    u8 *parentFrame;
    u8 *slot;
    u8 *otherSlot;
    u8 *groupSlot;

    chkmemAllocSiteTag(D_005F1698, 0x4CE);
    cameraData = (u8 *)D_008873F4[0](1, 0x2D8, 0x40000);
    if (cameraData == NULL) {
        return 0;
    }
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F16B0), 0x11, 0, 0, FldCameraTaskUpdate, FldCameraTaskDestroy, (u8 *)(cameraData));
    slot = cameraData + 0xC;
    targetFrame = (u8 *)func_003e9320();
    /* Previous measurement: typing this access changed b210 output (normalized_diff 2..266); the access form below preserves MATCH. */
    ((FldCameraHandleSlot *)(slot))->pointer = targetFrame;
    if (targetFrame == NULL) {
        kwlnTaskDestroyWithHierarchy(taskHandle);
        return 0;
    }
    func_003e9df0(targetFrame);
    slot = cameraData + 0x10;
    parentFrame = (u8 *)((RwObject *)((u8 *)((RwObject *)kwlnGetCamera())->parent))->parent;
    /* Previous measurement: typing this access changed b210 output (normalized_diff 2..266); the access form below preserves MATCH. */
    ((FldCameraHandleSlot *)(slot))->pointer = parentFrame;
    if (parentFrame != NULL) {
        func_003e99a0(((RwObject *)(kwlnGetCamera()))->parent);
        otherSlot = cameraData + 0xC;
        /* Previous measurement: typing this access changed b210 output (normalized_diff 362); the access form below preserves MATCH. */
        func_003e9830(((FldCameraHandleSlot *)(slot))->value,
                      ((FldCameraData *)cameraData)->targetFrame);
        /* Previous measurement: typing this access changed b210 output (normalized_diff 363); the access form below preserves MATCH. */
        func_003e9830(((FldCameraHandleSlot *)(otherSlot))->value,
                      /* Previous measurement: typing this access changed b210 output (normalized_diff 6); the access form below preserves MATCH. */
                      MEMBER(s32, kwlnGetCamera(), RwObject, parent));
    } else {
        kAssertFail(D_005F1698, 0x4F6);
    }
    ((FldCameraData *)cameraData)->slotBuffer = func_003e0f80();
    ((FldCameraData *)cameraData)->matrix = func_003e0f80();
    ((FldCameraData *)cameraData)->cachedMatrix = func_003e0f80();
    ((FldCameraData *)cameraData)->cylinderTask = KDraw_CreateCylinderTask(taskHandle, D_007948D0);
    pathHandle = (s32)((FldRaySelectionResource *)((u8 *)((FieldSceneState *)iGpffff9db0)->templates[0].resource))->cameraPath;
    if (pathHandle != 0) {
        groupSlot = cameraData + 0x2CC;
        /* Previous measurement: typing this access changed b210 output (normalized_diff 371); the access form below preserves MATCH. */
        ((FldCameraHandleSlot *)(groupSlot))->value = KDraw_CreateGroupTask(taskHandle, pathHandle,
                                              D_007948D0);
        otherSlot = cameraData + 0x2D0;
        /* Previous measurement: typing this access changed b210 output (normalized_diff 363); the access form below preserves MATCH. */
        ((FldCameraHandleSlot *)(otherSlot))->value = KDraw_CreateSphereTask(taskHandle,
                                              D_007948D0);
        slot = cameraData + 0x2D4;
        /* Previous measurement: typing this access changed b210 output (normalized_diff 362); the access form below preserves MATCH. */
        ((FldCameraHandleSlot *)(slot))->value = KDraw_CreateSphereTask(taskHandle,
                                              D_007948D0);
        /* Previous measurement: typing this access changed b210 output (normalized_diff 371); the access form below preserves MATCH. */
        KDraw_SetGroupColor(((FldCameraHandleSlot *)(groupSlot))->task,
                      (u8 *)&iGpffff9f00 + 0x30);
        /* Previous measurement: typing this access changed b210 output (normalized_diff 364); the access form below preserves MATCH. */
        KDraw_SetSphereColor(((FldCameraHandleSlot *)(otherSlot))->task,
                      (u8 *)&iGpffff9f00 + 0x30);
        /* Previous measurement: typing this access changed b210 output (normalized_diff 3); the access form below preserves MATCH. */
        KDraw_SetSphereColor(((FldCameraHandleSlot *)(slot))->task,
                      (u8 *)&iGpffff9f00 + 0x34);
    }
    return taskHandle;
}

#pragma pop
/* Enable the requested camera-control and optional debug-helper flags without changing its mode. */
// FUN_0016E540
void FldFrame_SetStateFlags(u8 *task, s32 value)
{
    u8 *cameraData = ((FldCameraTask *)task)->data;
    ((FldCameraData *)cameraData)->flags = ((FldCameraData *)cameraData)->flags | value;
}

/* Disable only the requested camera-control flags, retaining the current mode and other options. */
// FUN_0016E560
void FldFrame_ClearStateFlags(u8 *task, s32 value)
{
    u8 *cameraData = ((FldCameraTask *)task)->data;
    ((FldCameraData *)cameraData)->flags = ((FldCameraData *)cameraData)->flags & ~value;
}

// FUN_0016E580
s32 FldFrame_GetStatus(u8 *task)
{
    return ((FldCameraData *)((FldCameraTask *)task)->data)->mode;
}

/* Switch camera mode; initialize curve segment lengths or snapshot chase/orbit distance. */
// FUN_0016E590
/* measured: object 804B/window 816B, nd 0. The 3/4 test is two separate compares
   (goto body / goto skip; `== 3 || == 4` folds to sltiu). The count guard is
   `> 0x20` for the $at slti form. Locals in stack order: difference, previousPoint, currentPoint, then
   the two 64-byte matrix copies (case 6 at sp+0x70, case 7 at sp+0x30), each a
   two-word copy loop from func_00457120()->frame + 0x10; `previousPoint = currentPoint` is the
   RwV3d struct copy (ld/sd + lwc1/swc1). */
void FldCameraAdvanceCurve(u8 *task, s32 mode)
{
    extern s32 func_003bb330(u8 *task);
    extern void func_003bb3a0(u8 *task, s32 mode, void *);
    extern void func_003bb5b0(u8 *curve, s32 mode, f32 time, void *copyDestination, void *aux);
    extern f32 RwV3dLength(void *task);
    extern void kAssertFail(const void *file, s32 line);
    RwV3d difference;
    RwV3d previousPoint;
    RwV3d currentPoint;
    u8 orbitMatrix[0x40];
    u8 chaseMatrix[0x40];
    u8 *work;
    s32 i;
    f32 timeOrDistance;
    u8 *copySource;
    u8 *copyDestination;

    work = ((FldCameraTask *)task)->data;
    /* Previous measurement: typing this access changed b210 output (normalized_diff 556); the access form below preserves MATCH. */
    MEMBER(s32, work, FldCameraData, mode) = mode;
    if (mode == 3) {
        goto body;
    }
    if (mode != 4) {
        goto skip;
    }
body:
    {
        if ((s32)((FldRaySelectionResource *)((u8 *)((FieldSceneState *)iGpffff9db0)->templates[0].resource))->cameraPath != 0) {
            func_003e9df0(((RwObject *)(kwlnGetCamera()))->parent);
            /* Previous measurement: typing this access changed b210 output (normalized_diff 584); the access form below preserves MATCH. */
            MEMBER(s32, work, FldCameraData, keyCount) = func_003bb330(((FldRaySelectionResource *)((u8 *)((FieldSceneState *)iGpffff9db0)->templates[0].resource))->cameraPath);
            /* Previous measurement: typing this access changed b210 output (normalized_diff 584); the access form below preserves MATCH. */
            if (MEMBER(s32, work, FldCameraData, keyCount) > 0x20) {
                kAssertFail(D_005F1698, 0x557);
            }
            func_003bb3a0(((FldRaySelectionResource *)((u8 *)((FieldSceneState *)iGpffff9db0)->templates[0].resource))->cameraPath, 0, &previousPoint);
            for (i = 1; i < ((FldCameraData *)work)->keyCount; i++) {
                func_003bb3a0(((FldRaySelectionResource *)((u8 *)((FieldSceneState *)iGpffff9db0)->templates[0].resource))->cameraPath, i, &currentPoint);
                difference.x = currentPoint.x - previousPoint.x;
                difference.y = currentPoint.y - previousPoint.y;
                difference.z = currentPoint.z - previousPoint.z;
                ((FldCameraData *)work)->segmentLength[i - 1] = RwV3dLength(&difference);
                previousPoint = currentPoint;
            }
            timeOrDistance = 1.0f / (f32)(((FldCameraData *)work)->keyCount - 1);
            ((FldCameraData *)work)->maximumTime = 1.0f - timeOrDistance;
            ((FldCameraData *)work)->minimumTime = timeOrDistance;
            ((FldCameraData *)work)->pathTime = 0.5f;
            func_003bb5b0(((FldRaySelectionResource *)((u8 *)((FieldSceneState *)iGpffff9db0)->templates[0].resource))->cameraPath, 0xA, ((FldCameraData *)work)->pathTime, work + 0xC4, work + 0xD0);
            RwV3dNormalize((RwV3d *)(work + 0xD0), (const RwV3d *)(work + 0xD0));
            if ((s32)((RwObject *)((u8 *)((RwObject *)kwlnGetCamera())->parent))->parent != 0) {
                func_003e99a0(((RwObject *)(kwlnGetCamera()))->parent);
            }
            if ((s32)((RwObject *)((u8 *)((FldCameraData *)work)->targetFrame))->parent != 0) {
                func_003e99a0((void *)((FldCameraData *)work)->targetFrame);
            }
            /* Previous measurement: typing this access changed b210 output (normalized_diff 6); the access form below preserves MATCH. */
            func_003e9830(((FldCameraData *)work)->parentFrame, MEMBER(s32, kwlnGetCamera(), RwObject, parent));
        }
    }
skip:
    if (((FldCameraData *)work)->mode == 6) {
        copySource = (u8 *)((RwObject *)(kwlnGetCamera()))->parent + 0x10;
        copyDestination = orbitMatrix;
        *(RwMatrixTag *)copyDestination = *(RwMatrixTag *)copySource;
        timeOrDistance = RwV3dLength(orbitMatrix + 0x30);
        ((FldCameraData *)work)->desiredDistance = timeOrDistance;
        ((FldCameraData *)work)->currentDistance = timeOrDistance;
        ((FldCameraData *)(work))->anchor = *(RwV3d *)&((RwMatrixTag *)(orbitMatrix))->pos;
    } else if (((FldCameraData *)work)->mode == 7) {
        copySource = (u8 *)((RwObject *)(kwlnGetCamera()))->parent + 0x10;
        copyDestination = chaseMatrix;
        *(RwMatrixTag *)copyDestination = *(RwMatrixTag *)copySource;
        ((FldCameraData *)(work))->anchor = *(RwV3d *)&((RwMatrixTag *)(chaseMatrix))->pos;
        ((RwMatrixTag *)(chaseMatrix))->pos.y = 0.0f;
        timeOrDistance = RwV3dLength(chaseMatrix + 0x30);
        ((FldCameraData *)work)->desiredDistance = timeOrDistance;
        ((FldCameraData *)work)->currentDistance = timeOrDistance;
    }
    ((FldCameraData *)work)->minimumDistance = ((RwCamera *)(kwlnGetCamera()))->nearPlane;
}

// FUN_0016E8C0
u8 *FldCameraGetRecord(u8 *task)
{
    return (u8 *)((FldCameraData *)(((FldCameraTask *)task)->data))->targetFrame + 0x40;
}

/* measured: opt_propagation off preserves the retail early a1 pointer
   materialization in FldCameraSetDistance. */
/* measured: FldCameraSetDistance MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Apply an angular camera adjustment in modes 0, 6 and 7 while looking at the zero target. */
// FUN_0016E8E0
void FldCameraSetDistance(u8 *task, f32 angle)
{
    RwFrame *orientationFrame;
    FldCameraAngleScratch rotation;
    void *axis;
    s64 axisXY;
    f32 axisZ;
    f32 rotationAngle;
    u8 *clearCursor;
    s32 mode;
    s32 clearRemaining;
    u8 *cameraFrame;

    mode = ((FldCameraData *)(((FldCameraTask *)task)->data))->mode;
    if (mode == 0) {
        goto process;
    }
    if (mode == 6) {
        goto process;
    }
    if (mode != 7) {
        goto done;
    }
process:
    cameraFrame = (u8 *)((RwObject *)(kwlnGetCamera(mode)))->parent;
    /* Previous measurement: typing this access changed b210 output (normalized_diff 72); the access form below preserves MATCH. */
    orientationFrame = (RwFrame *)cameraFrame;
    rotation.position = orientationFrame->modelling.pos;
    clearCursor = &rotation.zeroPosition[0];
    clearRemaining = 0xC;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            clearRemaining -= 1;
        } while (clearRemaining != 0);
    }
    axis = &rotation.axisXY;
    axisXY = *(s64 *)D_005F16C8;
    axisZ = *(f32 *)D_005F16D0;
    rotation.axisXY = axisXY;
    rotation.axisZ = axisZ;
    rotationAngle = angle;
    func_003e9d50(cameraFrame, axis, rotationAngle, 2);
    rotation.position = *(RwV3d *)&((RwFrame *)(cameraFrame))->modelling.pos;
    K_ClumpLookAtBasis(kwlnGetCamera(), &rotation.position, &rotation.zeroPosition[0], 0);
done:
    ;
}

/* measured: closes opt_propagation off for FldCameraSetDistance. */
// FUN_0016E9F0
void FldFrame_SetViewOffset(u8 *task, u8 *value)
{
    u8 *cameraData;

    cameraData = ((FldCameraTask *)task)->data;
    ((FldCameraData *)cameraData)->offset = *(RwV3d *)value;
}

// FUN_0016EA20
void FldFrame_SetViewDistance(u8 *task, f32 value)
{
    ((FldCameraData *)((FldCameraTask *)task)->data)->radius = value;
}

// FUN_0016EA30
void fldCameraSetFollowHeight(u8 *task, f32 value)
{
    ((FldCameraData *)((FldCameraTask *)task)->data)->height = value;
}

/* Bind only type-1 scene resources as the camera follow target. */
// FUN_0016EA40
void FldFrame_BindTypedRes(u8 *task, u16 resourceKey)
{
    u8 *cameraData;
    s32 type;

    cameraData = ((FldCameraTask *)task)->data;
    type = (resourceKey & 0xFFC00) >> 10;
    if (type == 1)
        ((FldCameraData *)cameraData)->targetResource = (s32)MT_Scene_GetRes(resourceKey);
}

/* Mark a signed-byte camera key slot valid and copy its three-component vector. */
// FUN_0016EAA0
/* The scaled offset is named in an s32 local and the base added TO it so the
   final addu comes out `index + base` as retail has it; folding the multiply
   into the pointer expression emits `base + index` (nd 1). The three floats
   are one RwV3d assignment because retail loads all three before storing
   any. */
void FldFrame_SetSlotVector(u8 *task, s32 slotIndex, RwV3d *vector) {
    u8 *base;
    s32 index;
    s32 offset;

    base = ((FldCameraTask *)task)->data;
    index = (s8)slotIndex;
    base[index + 0xE8] = 1;
    offset = index * 12;
    /* Previous measurement: typing this access changed b210 output (normalized_diff 1); the access form below preserves MATCH. */
    ((FldCameraData *)(offset + (s32)base))[0].slotVector[0] = *vector;
}

// FUN_0016EAF0
s32 FldFrame_GetSlotBuffer(u8 *task)
{
    return ((FldCameraData *)((FldCameraTask *)task)->data)->slotBuffer;
}

/* measured: opt_propagation off preserves global initialization ordering in FldCameraUpdateLookAt. */
/* Rebuild look-at orientation for follow modes or the mode-2 target frame. */
// FUN_0016EB00
void FldCameraUpdateLookAt(u8 *task)
{
    FldCameraTask *cameraTask;
    RwFrame *orientationFrame;
    FldCameraAngleScratch rotation;
    u8 *cameraFrame;
    u8 *targetPosition;
    u8 *frameOrAxis;
    u8 *clearCursor;
    u8 *lookAtFrame;
    s32 previousMode;
    s32 clearRemaining;
    s64 axisXY;
    f32 axisZ;
    u32 mode;

    /* Previous measurement: typing this access changed b210 output (normalized_diff 5); the access form below preserves MATCH. */
    cameraTask = (FldCameraTask *)task;
    mode = (u32)((FldCameraData *)(cameraTask->data))->mode;
    switch (mode) {
    case 0:
    case 5:
    case 6:
        frameOrAxis = ((u8*)MT_Scene_GetFrameState());
        if ((((FldCameraData *)(((FldCameraTask *)(((FldFrame *)frameOrAxis)->cameraTask))->data))->mode == 0) ||
            (((FldCameraData *)(((FldCameraTask *)(((FldFrame *)frameOrAxis)->cameraTask))->data))->mode == 6) ||
            (((FldCameraData *)(((FldCameraTask *)(((FldFrame *)frameOrAxis)->cameraTask))->data))->mode == 7)) {
            cameraFrame = (u8 *)((RwObject *)(kwlnGetCamera()))->parent;
            /* Previous measurement: typing this access changed b210 output (normalized_diff 76); the access form below preserves MATCH. */
            orientationFrame = (RwFrame *)cameraFrame;
    rotation.position = orientationFrame->modelling.pos;
            clearCursor = &rotation.zeroPosition[0];
            clearRemaining = 0xC;
            if (clearCursor != NULL) {
                do {
                    *clearCursor = 0;
                    clearCursor += 1;
                    clearRemaining -= 1;
                } while (clearRemaining != 0);
            }
            frameOrAxis = (u8 *)&rotation.axisXY;
            axisXY = *(s64 *)D_005F16C8;
            axisZ = *(f32 *)D_005F16D0;
            rotation.axisXY = axisXY;
            rotation.axisZ = axisZ;
            func_003e9d50(cameraFrame, frameOrAxis, 0.0f, 2);
            rotation.position = *(RwV3d *)&((RwFrame *)(cameraFrame))->modelling.pos;
            K_ClumpLookAtBasis(kwlnGetCamera(), &rotation.position, &rotation.zeroPosition[0], 0);
        }
        break;
    case 2:
        lookAtFrame = (u8 *)((RwObject *)(kwlnGetCamera()))->parent;
        targetPosition = (u8 *)(((FldCameraData *)(((FldCameraTask *)task)->data))->targetFrame + 0x40);
        frameOrAxis = kwlnGetCamera();
        K_ClumpLookAtBasis(frameOrAxis, lookAtFrame + 0x40, targetPosition, 0);
        break;
    case 1:
    case 3:
    case 4:
    default:
        break;
    }
}

/* measured: restore opt_propagation after FldCameraUpdateLookAt. */
/* Reposition the mode-6 orbit camera along its normalized negative forward axis. */
// FUN_0016EC90
void FldCameraUpdateOrbit(u8 *task)
{
    f32 cameraPosition[3];
    f32 push[3];
    f32 distance;
    f32 negativeZ;
    f32 negativeY;
    f32 negativeX;
    s32 secondWord;
    s32 firstWord;
    s32 mode;
    u8 *copySource;
    u8 *copyDestination;
    s32 copyRemaining;
    u8 *cameraData;
    u8 *parentMatrix;
    u8 *cameraFrame;
    u8 *sourceMatrix;
    u8 *positionMatrix;

    cameraData = ((FldCameraTask *)task)->data;
    mode = ((FldCameraData *)cameraData)->mode;
    if (mode == 6) {
        cameraFrame = (u8 *)((RwObject *)(kwlnGetCamera()))->parent;
        parentMatrix = func_003e9700((s32)((RwObject *)(cameraFrame))->parent);
        copySource = cameraFrame + 0x10;
        copyDestination = (u8 *)((FldCameraData *)cameraData)->matrix;
        copyRemaining = 8;
        /* measured: a typed whole-matrix copy gives normalized_diff 222; retain the native word-pair cursor. */
        do {
            firstWord = ((FldCameraMatrixPair *)(copySource))->first;
            secondWord = ((FldCameraMatrixPair *)(copySource))->second;
            copySource += 8;
            copyRemaining -= 1;
            ((FldCameraMatrixPair *)(copyDestination))->first = firstWord;
            ((FldCameraMatrixPair *)(copyDestination))->second = secondWord;
            copyDestination += 8;
        } while (copyRemaining > 0);
        /* Previous measurement: typing this access changed b210 output (normalized_diff 178); the access form below preserves MATCH. */
        sourceMatrix = MEMBER(u8 *, cameraData, FldCameraData, matrix);
        *(RwV3d *)&push[0] = *(RwV3d *)&((RwMatrixTag *)(sourceMatrix))->at;
        RwV3dNormalize((RwV3d *)&push[0], (const RwV3d *)&push[0]);
        negativeX = -push[0];
        push[0] = negativeX;
        negativeY = -push[1];
        push[1] = negativeY;
        negativeZ = -push[2];
        push[2] = negativeZ;
        distance = ((FldCameraData *)cameraData)->desiredDistance;
        push[0] = negativeX * distance;
        push[1] = negativeY * distance;
        push[2] = negativeZ * distance;
        ((FldCameraData *)cameraData)->currentDistance = distance;
        /* Previous measurement: typing this access changed b210 output (normalized_diff 178); the access form below preserves MATCH. */
        RwMatrixTranslate(MEMBER(u8 *, cameraData, FldCameraData, matrix), &push[0], 0);
        positionMatrix = (u8 *)((FldCameraData *)cameraData)->matrix;
        *(RwV3d *)&cameraPosition[0] = *(RwV3d *)&((RwMatrixTag *)(positionMatrix))->pos;
        func_003e0e20((u8 *)((FldCameraData *)cameraData)->matrix, parentMatrix, 2);
        K_ClumpLookAtBasis(kwlnGetCamera(), &cameraPosition[0], &D_007F1730[0], 0);
    }
}

/* measured: opt_propagation off probe for retail pre-call address order. */
/* Apply an initial camera angle followed by sine-eased incremental rotation until duration expires. */
// FUN_0016EE00
s32 FldFrame_RotateTaskUpdate(u8 *task)
{
    RwFrame *initialOrientationFrame;
    FldCameraRotation *elapsedRotation;
    FldCameraRotation *durationRotation;
    RwFrame *stepOrientationFrame;
    FldCameraRotationScratch rotation;
    void *initialAxis;
    void *stepAxis;
    s64 axisXY;
    f32 axisZ;
    f32 angle;
    f32 initialAngle;
    f32 sine;
    f32 stepAngle;
    s32 state;
    s32 initialMode;
    s32 elapsed;
    s32 stepMode;
    u8 *clearInitial;
    u8 *clearStep;
    s32 initialRemaining;
    s32 stepRemaining;
    u8 *rotationData;
    u8 *initialFrame;
    u8 *stepFrame;

    rotationData = ((FldCameraTask *)task)->data;
    state = ((FldCameraRotation *)rotationData)->state;
    switch (state) {
    case 0:
        initialAngle = ((FldCameraRotation *)rotationData)->initialAngle;
        initialMode = ((FldCameraData *)(((FldCameraTask *)(((FldFrame *)MT_Scene_GetFrameState())->cameraTask))->data))->mode;
        if (initialMode == 0)
            goto process0;
        if (initialMode == 6)
            goto process0;
        if (initialMode != 7)
            goto skip_process0;
process0:
        initialFrame = (u8 *)((RwObject *)(kwlnGetCamera()))->parent;
        /* Previous measurement: typing this access changed b210 output (normalized_diff 72); the access form below preserves MATCH. */
        initialOrientationFrame = (RwFrame *)initialFrame;
    rotation.initialPosition = initialOrientationFrame->modelling.pos;
        clearInitial = &rotation.initialZero[0];
        initialRemaining = 0xC;
        if (clearInitial != NULL) {
            do {
                *clearInitial = 0;
                clearInitial += 1;
                initialRemaining -= 1;
            } while (initialRemaining != 0);
        }
        initialAxis = &rotation.initialAxisXY;
        axisXY = *(s64 *)D_005F16C8;
        axisZ = *(f32 *)D_005F16D0;
        rotation.initialAxisXY = axisXY;
        rotation.initialAxisZ = axisZ;
        angle = initialAngle;
        func_003e9d50(initialFrame, initialAxis, angle, 2);
        rotation.initialPosition = *(RwV3d *)&((RwFrame *)(initialFrame))->modelling.pos;
        K_ClumpLookAtBasis(kwlnGetCamera(), &rotation.initialPosition, &rotation.initialZero[0], 0);
skip_process0:
        ((FldCameraRotation *)rotationData)->state += 1;
        /* fallthrough */
    case 1:
        /* Previous measurement: typing this access changed b210 output (normalized_diff 288); the access form below preserves MATCH. */
        elapsedRotation = (FldCameraRotation *)rotationData;
    elapsed = elapsedRotation->elapsed;
        /* Previous measurement: typing this access changed b210 output (normalized_diff 287); the access form below preserves MATCH. */
        durationRotation = (FldCameraRotation *)rotationData;
    if (elapsed < durationRotation->duration) {
            ((FldCameraRotation *)rotationData)->elapsed = elapsed + 1;
            sine = sinf((iGpffff8094 *
                                      (f32)((FldCameraRotation *)rotationData)->elapsed) /
                                     (f32)((FldCameraRotation *)rotationData)->duration);
            if (((FldFrame *)MT_Scene_GetFrameState())->cameraTask != 0) {
                stepAngle = ((FldCameraRotation *)rotationData)->angle *
                             (sine - ((FldCameraRotation *)rotationData)->previousSine);
                stepMode = ((FldCameraData *)(((FldCameraTask *)(((FldFrame *)MT_Scene_GetFrameState())->cameraTask))->data))->mode;
                if (stepMode == 0)
                    goto process1;
                if (stepMode == 6)
                    goto process1;
                if (stepMode != 7)
                    goto skip_process1;
process1:
                stepFrame = (u8 *)((RwObject *)(kwlnGetCamera()))->parent;
                /* Previous measurement: typing this access changed b210 output (normalized_diff 72); the access form below preserves MATCH. */
                stepOrientationFrame = (RwFrame *)stepFrame;
    rotation.stepPosition = stepOrientationFrame->modelling.pos;
                clearStep = &rotation.stepZero[0];
                stepRemaining = 0xC;
                if (clearStep != NULL) {
                    do {
                        *clearStep = 0;
                        clearStep += 1;
                        stepRemaining -= 1;
                    } while (stepRemaining != 0);
                }
                stepAxis = &rotation.stepAxisXY;
                axisXY = *(s64 *)D_005F16C8;
                axisZ = *(f32 *)D_005F16D0;
                rotation.stepAxisXY = axisXY;
                rotation.stepAxisZ = axisZ;
                angle = stepAngle;
                func_003e9d50(stepFrame, stepAxis, angle, 2);
                rotation.stepPosition = *(RwV3d *)&((RwFrame *)(stepFrame))->modelling.pos;
                K_ClumpLookAtBasis(kwlnGetCamera(), &rotation.stepPosition,
                              &rotation.stepZero[0], 0);
skip_process1:
                ;
            }
            ((FldCameraRotation *)rotationData)->previousSine = sine;
        } else {
            ((FldCameraRotation *)rotationData)->state += 1;
        }
        goto done;
    case 2:
        return -1;
    default:
done:
        return 0;
    }
}

/* measured: closing opt_propagation off probe for FldFrame_RotateTaskUpdate. */
/* measured: FldFrame_RotateTaskCreate, FldFrameRotateTaskCreate MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_0016F100
void FldFrame_RotateTaskDestroy(u8 *task)
{
    (*DAT_008873EC)(((FldCameraTask *)task)->data);
}

/* measured: opt_loop_invariants on reproduces FldFrame_RotateTaskCreate's retail loop schedule. */
/* measured: FldFrame_RotateTaskCreate MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Create a timed rotation toward the player yaw, optionally adding a relative angle. */
// FUN_0016F130
u8 *FldFrame_RotateTaskCreate(u8 *parentTask, s32 duration, s32 relativeAngle)
{
    u8 *result;
    u8 *rotationData;
    f32 targetYaw;
    f32 cameraYaw;
    f32 directAngle;
    f32 wrappedAngle;
    f32 fullTurn;

    result = NULL;
    if (*(s32 *)D_007EF9F8 != 0) {
        chkmemAllocSiteTag(D_005F1698, 0x71C);
        rotationData = (u8 *)D_008873F4[0](1, 0x18, 0x40000);
        if (rotationData == NULL) {
            return NULL;
        }
            result = (u8 *)(s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F16E0), 0xF, 0, 0, FldFrame_RotateTaskUpdate, FldFrame_RotateTaskDestroy, (u8 *)(rotationData));
            ((FldCameraRotation *)rotationData)->duration = duration;
            targetYaw = KDraw_MatrixYawDeg(
                mdlGetMatrix(*(s32 *)D_007EFA00));
            if (targetYaw < 0.0f) {
                targetYaw += 360.0f;
            }
            cameraYaw = KDraw_MatrixYawDeg(
                func_003e9700((s32)((RwObject *)(kwlnGetCamera()))->parent));
            if (cameraYaw < 0.0f) {
                cameraYaw += 360.0f;
            }
            if (relativeAngle != -1) {
                targetYaw += (f32)relativeAngle;
                for (; targetYaw > 360.0f; targetYaw -= 360.0f) {
                }
            }
            directAngle = targetYaw - cameraYaw;
            if (cameraYaw > 180.0f) {
                wrappedAngle = (360.0f - cameraYaw) + targetYaw;
            } else {
                wrappedAngle = -((360.0f - targetYaw) + cameraYaw);
            }
            fullTurn = 360.0f;
            while (directAngle > fullTurn) {
                directAngle -= fullTurn;
            }
            while (wrappedAngle > fullTurn) {
                wrappedAngle -= fullTurn;
            }
            if (fabsf(directAngle) < fabsf(wrappedAngle)) {
                ((FldCameraRotation *)rotationData)->angle = directAngle;
            } else {
                ((FldCameraRotation *)rotationData)->angle = wrappedAngle;
            }
    }
    return result;
}

/* measured: close opt_loop_invariants scope after FldFrame_RotateTaskCreate. */
/* measured: opt_loop_invariants on reproduces FldFrameRotateTaskCreate's loop schedule
   and FPU register allocation. */
#pragma push
/* Create a timed rotation toward an absolute yaw using the shorter angular difference. */
// FUN_0016F3B0
u8 *FldFrameRotateTaskCreate(u8 *parentTask, s32 duration, s32 absoluteAngle)
{
    u8 *result;
    u8 *rotationData;
    f32 cameraYaw;
    f32 targetYaw;
    f32 directAngle;
    f32 wrappedAngle;

    result = NULL;
    if (*(s32 *)D_007EF9F8 != 0) {
        chkmemAllocSiteTag(D_005F1698, 0x774);
        rotationData = (u8 *)D_008873F4[0](1, 0x18, 0x40000);
        if (rotationData == NULL) {
            return NULL;
        }
        result = (u8 *)(s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F16E0), 0xF, 0, 0, FldFrame_RotateTaskUpdate, FldFrame_RotateTaskDestroy, (u8 *)(rotationData));
        ((FldCameraRotation *)rotationData)->duration = duration;
        KDraw_MatrixYawDeg(mdlGetMatrix(*(s32 *)D_007EFA00));
        cameraYaw = KDraw_MatrixYawDeg(
            func_003e9700((s32)((RwObject *)(kwlnGetCamera()))->parent));
        if (cameraYaw < 0.0f) {
            cameraYaw += 360.0f;
        }
        targetYaw = (f32)absoluteAngle;
        while (targetYaw > 360.0f) {
            targetYaw -= 360.0f;
        }
        while (targetYaw < -360.0f) {
            targetYaw += 360.0f;
        }
        directAngle = targetYaw - cameraYaw;
        if (cameraYaw > 180.0f) {
            wrappedAngle = (360.0f - cameraYaw) + targetYaw;
        } else {
            wrappedAngle = -((360.0f - targetYaw) + cameraYaw);
        }
        while (directAngle > 360.0f) {
            directAngle -= 360.0f;
        }
        while (wrappedAngle > 360.0f) {
            wrappedAngle -= 360.0f;
        }
        if (fabsf(directAngle) < fabsf(wrappedAngle)) {
            ((FldCameraRotation *)rotationData)->angle = directAngle;
        } else {
            ((FldCameraRotation *)rotationData)->angle = wrappedAngle;
        }
    }
    return result;
}

#pragma pop
/* measured: FldEventSnapshotCapture compiles to object 276B against the 288B retail
   window (normalized_diff 0; trailing zero padding is normalized). */
/* Capture camera matrix, FOV, mode and follow parameters as a seven-quadword snapshot. */
// FUN_0016F630
/* measured: optimization_level 1 reproduces FldEventSnapshotCapture register allocation. */
/* measured: FldEventSnapshotCapture MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
void FldEventSnapshotCapture(FldEventSnapshot *destination, u8 *task)
{
    /* The typed matrix copy retains the two-word transfer loop; the snapshot is copied as seven aligned quadwords. */
    FldCameraSnapshotScratch snapshot;
    s128 *copyDestination;
    s128 *copySource;
    u8 *cameraData;
    u8 *matrixSource;
    u8 *matrixDestination;
    u8 *cameraFrame;
    s32 quadwordsRemaining;
    f32 componentX;
    f32 componentY;
    f32 componentZ;
    s128 quadword;

    copyDestination = (s128 *)destination;
    cameraData = ((FldCameraTask *)task)->data;
    cameraFrame = (u8 *)((RwObject *)(kwlnGetCamera()))->parent;
    memset(&snapshot, 0, sizeof(snapshot));
    snapshot.fov = K_View_GetFov(kwlnGetCamera());
    matrixSource = (u8 *)(cameraFrame + 0x10);
    matrixDestination = &snapshot.work[0];
    *(RwMatrixTag *)matrixDestination = *(RwMatrixTag *)matrixSource;
    snapshot.mode = (s16)((FldCameraData *)cameraData)->mode;
    componentX = ((FldCameraData *)cameraData)->offset.x;
    componentY = ((FldCameraData *)cameraData)->offset.y;
    componentZ = ((FldCameraData *)cameraData)->offset.z;
    snapshot.offsetX = componentX;
    snapshot.offsetY = componentY;
    snapshot.offsetZ = componentZ;
    snapshot.radius = ((FldCameraData *)cameraData)->radius;
    snapshot.height = ((FldCameraData *)cameraData)->height;
    snapshot.distance = ((FldCameraData *)cameraData)->desiredDistance;
    componentX = ((FldCameraData *)cameraData)->anchor.x;
    componentY = ((FldCameraData *)cameraData)->anchor.y;
    componentZ = ((FldCameraData *)cameraData)->anchor.z;
    snapshot.targetX = componentX;
    snapshot.targetY = componentY;
    snapshot.targetZ = componentZ;
    copySource = (s128 *)&snapshot;
    quadwordsRemaining = 7;
    do {
        quadword = *copySource;
        copySource = (s128 *)((u8 *)copySource + 0x10);
        quadwordsRemaining -= 1;
        *copyDestination = quadword;
        copyDestination = (s128 *)((u8 *)copyDestination + 0x10);
    } while (quadwordsRemaining > 0);
}

/* measured: restore baseline optimization level after FldEventSnapshotCapture. */
/* measured: FldCameraApplyRecord, FldEvent_GetStickHeading, FldCharacterAnimSelect, FldMoveAnimPrimary, FldMoveAnimSecondary MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* measured: FldCameraApplyRecord compiles to object 348B against the 352B retail
   window (normalized_diff 0; pointer-typed hoist fixes final-call setup). */
/* Restore camera matrix/FOV and follow parameters, then rebuild mode-specific orientation. */
// FUN_0016F750
void FldCameraApplyRecord(u8 *task, u8 *record)
{
    u8 *cameraData;
    u8 *frameOrCamera;
    u32 mode;
    u16 recordMode;

    /* Previous measurement: typing this access changed b210 output (normalized_diff 233); the access form below preserves MATCH. */
    cameraData = MEMBER(u8 *, task, FldCameraTask, data);
    K_View_SetFov(kwlnGetCamera(), ((FldCameraSnapshotScratch *)record)->fov);
    func_003e9cb0(((RwObject *)(kwlnGetCamera()))->parent, record, 0);
    recordMode = (u16)((FldCameraSnapshotScratch *)record)->mode;
    FldCameraAdvanceCurve(task, recordMode);
    /* Previous measurement: typing this access changed b210 output (normalized_diff 233); the access form below preserves MATCH. */
    frameOrCamera = MEMBER(u8 *, task, FldCameraTask, data);
    ((FldCameraData *)(frameOrCamera))->offset = *(RwV3d *)&((FldCameraSnapshotScratch *)record)->offsetX;
    /* Previous measurement: typing this access changed b210 output (normalized_diff 233); the access form below preserves MATCH. */
    ((FldCameraData *)(MEMBER(u8 *, task, FldCameraTask, data)))->radius = ((FldCameraSnapshotScratch *)record)->radius;
    /* Previous measurement: typing this access changed b210 output (normalized_diff 233); the access form below preserves MATCH. */
    ((FldCameraData *)(MEMBER(u8 *, task, FldCameraTask, data)))->height = ((FldCameraSnapshotScratch *)record)->height;
    ((FldCameraData *)cameraData)->desiredDistance = ((FldCameraSnapshotScratch *)record)->distance;
    ((FldCameraData *)(cameraData))->anchor = *(RwV3d *)&((FldCameraSnapshotScratch *)record)->targetX;
    /* Previous measurement: typing this access changed b210 output (normalized_diff 233); the access form below preserves MATCH. */
    mode = (u32)((u32)((FldCameraData *)(MEMBER(u8 *, task, FldCameraTask, data)))->mode);
    switch (mode) {
    case 0:
    case 5:
    case 6:
        FldCameraSetDistance(((FldFrame *)MT_Scene_GetFrameState())->cameraTask, 0.0f);
        return;
    case 2:
    {
        s32 cameraFrame;
        u8 *cameraPosition;
        s32 targetPosition;
        cameraFrame = (s32)((RwObject *)(kwlnGetCamera()))->parent;
        targetPosition = (s32)((u8 *)((FldCameraData *)(((FldCameraTask *)task)->data))->targetFrame + 0x40);
        cameraPosition = (u8 *)cameraFrame + 0x40;
        frameOrCamera = kwlnGetCamera();
        K_ClumpLookAtBasis(frameOrCamera, (void *)cameraPosition,
                      (void *)targetPosition, 0);
    }
        return;
    case 1:
    case 3:
    case 4:
    default:
        return;
    }
}

/* Compute a 0..360-degree stick heading with a 48-unit deadzone and D-pad overrides. */
// FUN_0016F8B0
// MATCH: 1100B/1104B, 13 resolved relocations, four zero tail bytes.
f32 FldEvent_GetStickHeading(s32 padIndex, s32 stickIndex)
{
    /* The typed interior alias starts at each pad record's button word, with a 0x4A-byte stride. */
    RwV3d normalized;
    RwV3d input;
    u8 *clear;
    s32 remaining;
    u32 offset;
    u16 buttons;
    f32 result;
    f32 componentZ;
    f32 componentX;

    clear = (u8 *)&input;
    remaining = sizeof(input);
    if (clear != NULL) {
        do {
            *clear = 0;
            clear += 1;
            remaining -= 1;
        } while (remaining != 0);
    }
    result = 0.0f;
    if (stickIndex == 0) {
        offset = (u32)padIndex * 0x4A;
        input.z = (f32)(u32)D_008C025D[offset] - 128.0f;
        buttons = ((FldCameraPadRecord *)((u8 *)D_008C024C + offset))[0].buttons;
        if (buttons & 0x1000) {
            input.z = -128.0f;
        } else if (buttons & 0x4000) {
            input.z = 128.0f;
        }
        if ((buttons & 0xA000) && !(input.z < -48.0f) &&
            (input.z <= 48.0f)) {
            input.z = 0.0f;
        }

        input.x = (f32)(u32)D_008C025C[padIndex * 0x4A] - 128.0f;
        if (buttons & 0x8000) {
            input.x = -128.0f;
        } else if (buttons & 0x2000) {
            input.x = 128.0f;
        }
        if ((buttons & 0x5000) && !(input.x < -48.0f) &&
            (input.x <= 48.0f)) {
            input.x = 0.0f;
        }
    } else {
        offset = (u32)padIndex * 0x4A;
        input.z = (f32)(u32)D_008C025F[offset] - 128.0f;
        if (!(input.z < -48.0f) && (input.z <= 48.0f)) {
            input.z = 0.0f;
        }
        input.x = (f32)(u32)D_008C025E[offset] - 128.0f;
        if (!(input.x < -48.0f) && (input.x <= 48.0f)) {
            input.x = 0.0f;
        }
    }

    if ((input.z < -48.0f) || !(input.z <= 48.0f) ||
        (input.x < -48.0f) || !(input.x <= 48.0f)) {
        RwV3dNormalize(&normalized, &input);
        componentZ = normalized.z;
        componentX = normalized.x;
        result = func_0044b920(componentZ /
                              sqrtf(componentX * componentX + componentZ * componentZ));
        result *= fGpffff8300;
        if (normalized.x < 0.0f) {
            result = 360.0f - result;
        }
        result += 180.0f;
        if (!(result <= 360.0f)) {
            result -= 360.0f;
        }
    }
    return result;
}

/* Select the character idle animation from room, step, day-event and flag state. */
// FUN_0016FD00
s32 FldCharacterAnimSelect(s32 characterType)
{
    u8 *scene;
    u8 *currentScene;

    switch (characterType) {
    case 1:
        scene = iGpffff9db0;
        if (FldRoomIsListed(((FieldSceneState *)scene)->field.half[0], ((FieldSceneState *)scene)->room.half[0]) == 1) {
            if (FldDayEventActive() == 1) {
                return 9;
            }
            if (datGetFlag(0xC01) != 0) {
                goto ret0_a;
            }
            goto ret1_a;
ret0_a:
            return 0;
ret1_a:
            return 1;
        }
        currentScene = iGpffff9db0;
        if ((((FieldSceneState *)currentScene)->field.value == 0x44) &&
            (((FieldSceneState *)currentScene)->room.value == 1)) {
            if (datGetFlag(0xC01, 1) != 0) {
                goto ret0_b;
            }
            goto ret1_b;
ret0_b:
            return 0;
ret1_b:
            return 1;
        }
        if (FldStepIndex() != 0) {
            return 0;
        }
        if (FldDayEventActive() == 1) {
            return 9;
        }
        if (datGetFlag(0xC01) != 0) {
            goto ret0_c;
        }
        goto ret1_c;
ret0_c:
        return 0;
ret1_c:
        return 1;
    case 2:
    case 3:
        return 0x1B;
    default:
        return 0;
    }
}

/* Choose the primary movement animation, with room and day-event variants. */
// FUN_0016FE80
s32 FldMoveAnimPrimary(s32 characterType)
{
    s32 result;
    u8 *scene;

    switch (characterType) {
    case 1:
        scene = iGpffff9db0;
        if (FldRoomIsListed(((FieldSceneState *)scene)->field.half[0], ((FieldSceneState *)scene)->room.half[0]) == 1) {
            result = 3;
            if (FldDayEventActive() == 1) {
                result = 0xA;
            } else if (datGetFlag(0xC01) != 0) {
                result--;
            }
        } else {
            scene = iGpffff9db0;
            if ((((FieldSceneState *)scene)->field.value == 0x44) &&
                (((FieldSceneState *)scene)->room.value == 1)) {
                result = 3;
                if (datGetFlag(0xC01, 1) != 0) {
                    result--;
                }
            } else if (FldStepIndex() != 0) {
                result = 2;
            } else {
                result = 3;
                if (FldDayEventActive() == 1) {
                    result = 0xA;
                } else if (datGetFlag(0xC01) != 0) {
                    result--;
                }
            }
        }
        break;
    default:
        result = 2;
        break;
    }
    return result;
}

/* Choose the secondary movement animation, with room and day-event variants. */
// FUN_0016FFD0
s32 FldMoveAnimSecondary(s32 characterType)
{
    s32 result;
    u8 *scene;

    switch (characterType) {
    case 1:
        scene = iGpffff9db0;
        if (FldRoomIsListed(((FieldSceneState *)scene)->field.half[0], ((FieldSceneState *)scene)->room.half[0]) == 1) {
            result = 5;
            if (FldDayEventActive() == 1) {
                result = 0xB;
            } else if (datGetFlag(0xC01) != 0) {
                result--;
            }
        } else {
            scene = iGpffff9db0;
            if ((((FieldSceneState *)scene)->field.value == 0x44) &&
                (((FieldSceneState *)scene)->room.value == 1)) {
                result = 5;
                if (datGetFlag(0xC01, 1) != 0) {
                    result--;
                }
            } else if (FldStepIndex() != 0) {
                result = 2;
            } else {
                result = 5;
                if (FldDayEventActive() == 1) {
                    result = 0xB;
                } else if (datGetFlag(0xC01) != 0) {
                    result--;
                }
            }
        }
        break;
    default:
        result = 2;
        break;
    }
    return result;
}

