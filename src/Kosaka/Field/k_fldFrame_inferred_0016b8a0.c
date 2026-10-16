#include "mt_scene_internal.h"
#include "field_event_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "model_matrix_internal.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "Kosaka/k_model_internal.h"

typedef struct RwMatrix RwMatrix;

extern s32 iGpffff9ef8;
extern void func_003e9cb0(void *arg0, void *arg1, s32 arg2);
extern void K_View_SetFov(void *arg0, f32 arg1);
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
extern void chkmemAllocSiteTag(const void *msg, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 *kwlnGetCamera();
extern void func_003e9d50(u8 *arg0, void *arg1, f32 arg2, s32 arg3);
extern void K_ClumpLookAtBasis(u8 *arg0, void *arg1, void *arg2, s32 arg3);
extern void RwMatrixTranslate(void *arg0, void *arg1, s32 arg2);
extern void func_003e0e20(void *arg0, void *arg1, s32 arg2);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern u8 *func_003e9700(s32 arg0);
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
extern void func_003e9df0(void *arg0);
extern s32 func_003e0f80(void);
extern s32 FldCameraTaskUpdate(u8 *task);
extern s32 KDraw_CreateGroupTask(s32 arg0, s32 arg1, void *arg2);
extern s32 KDraw_CreateSphereTask(s32 arg0, void *arg1);
extern s32 KDraw_CreateCylinderTask(s32 arg0, void *arg1);
extern void KDraw_SetSphereColor(void *arg0, void *arg1);
extern f32 fabsf(f32 x);
extern f32 KDraw_MatrixYawDeg(u8 *arg0);
extern f32 K_View_GetFov(u8 *arg0);
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
extern void func_003e99a0(void *arg0);
extern void func_003e9390(void *arg0);
extern void func_003e9830(s32 arg0, s32 arg1);
extern void func_003e0f40(s32 arg0);
extern char D_005F11E8[];
extern char D_005F1200[];
extern s32 iGpffff9f08;
extern u8 *iGpffff9db0;
extern s32 datGetFlag();
extern s32 FldStepIndex();
extern s32 FldDayEventActive();
extern s32 FldRoomIsListed(u16 arg0, u16 arg1);
extern s32 D_005F1350[];
extern void mdlSetColor(void *arg0, void *arg1);
extern void mdlAttachSlotModelFromResource(void *arg0, u16 arg1, u32 arg2, u16 arg3,
                           void *arg4, u32 arg5);
extern u8 iGpffff9f10;
extern u8 D_005F13A0[];


typedef struct F8060Frame
{
    RwV3d sp50;
    RwV3d sp5c;
    u8 pad68[8];
    RwV3d sp70;
    u8 pad7c[4];
    RwV3d sp80;
    u8 pad8c[4];
    RwV3d sp90;
} F8060Frame;

extern s32 FldFrame_RaycastFieldWorlds(RwV3d *arg0, RwV3d *arg1, f32 fparg0,
                         u16 arg2);


typedef struct E8E0Frame
{
    s64 sp30;
    f32 sp38;
    u8 pad3c[4];
    u8 sp40[12];
    u8 pad4c[4];
    RwV3d sp50;
} E8E0Frame;
typedef struct EEE0Frame
{
    s64 sp40;
    f32 sp48;
    u8 pad4c[4];
    u8 sp50[12];
    u8 pad5c[4];
    RwV3d sp60;
    u8 pad6c[4];
    s64 sp70;
    f32 sp78;
    u8 pad7c[4];
    u8 sp80[12];
    u8 pad8c[4];
    RwV3d sp90;
} EEE0Frame;
extern f32 sinf(f32 arg0);
extern f32 iGpffff8094;

extern s32 RwEngineGetMatrixTolerances(RwV3d *arg0);
extern void RwMatrixOptimize(u8 *arg0, RwV3d *arg1);


typedef signed __int128 s128;

typedef struct F630Frame
{
    u8 work[0x40];
    f32 sp80;
    s16 sp84;
    u8 pad86[2];
    f32 sp88;
    f32 sp8c;
    f32 sp90;
    f32 sp94;
    f32 sp98;
    f32 sp9c;
    f32 spa0;
    f32 spa4;
    f32 spa8;
    u32 reserved6c; /* Cleared and copied with the seven-quadword snapshot. */
} __attribute__((aligned(16))) F630Frame;
static inline f32 code1_0016_cvt(s32 value) {
    return (f32)value;
}

/* Source unit: src/promoted/code1_0016.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0016.c; members 0016b8a0-0016ffd0 */

extern s32 FldEnemyLoadTable(u8 *arg0);
extern void FldPartyModelRelease(s32 arg0);
extern s32 FldDayEventActive(void);
extern s32 FldRoomIsListed(u16 arg0, u16 arg1);
typedef struct FldRaySelectionResource
{
    u32 flags;
    u32 unknown04;
    void *fallback;
    u32 unknown0c;
    u32 unknown10;
    void *preferred;
} FldRaySelectionResource;
static inline void fldRaySelectWorld(const FldRaySelectionResource *selected, void **destination)
{
    void *world = selected->preferred;
    if (world != NULL) {
        *destination = world;
        return;
    }
    *destination = selected->fallback;
}
extern u16 D_008C024C[];
extern u8 D_008C025C[];
extern u8 D_008C025D[];
extern u8 D_008C025E[];
extern u8 D_008C025F[];
extern f32 fGpffff8300;
extern f32 func_0044b920(f32 arg0);
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
    extern u8 *MT_Scene_GetResListHead(s32 arg0);
    extern s32 FldMap_IsCurrentInEitherBand(void);
    extern s32* MT_Scene_GetFrameState(void);
    extern void *FldFrame_RaycastWorldLocal(void *collisionWorld, void *ray);
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
    object = *(u8 **)(iGpffff9db0 + 0x28);
    if (object == NULL) {
        return 0;
    }
    if ((*(u32 *)object & 1) != 0) {
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
            if (*(u8 *)((u8 *)table + ((fieldZ + *zOffset) * 256) + 16 * (fieldX + offsets[0]) + 0x54) != 1) {
                goto next_cell;
            }
            offsets = &D_005F1670[2U * neighbor];
            table = ((u8*)MT_Scene_GetFrameState());
            storedKey = *(u16 *)((u8 *)table + ((fieldZ + *zOffset) * 256) + 16 * (fieldX + offsets[0]) + 0x56);
            modelNode = MT_Scene_GetResListHead(0xA);
            key = storedKey;
            while (modelNode != NULL) {
                u16 *modelId = *(u16 **)(modelNode + 0x140);
                if (modelId != NULL && *modelId == key && (*(s32 *)(modelNode + 0x28) & 2) != 0 && *(s32 *)(modelNode + 0x150) == 1) {
                    selectedWorld = mdlGetClump(*(void **)(modelNode + 0x144));
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
                modelNode = *(u8 **)(modelNode + 0x138);
            }
            if (result == 1) {
                goto query_complete;
            }
            entry = MT_Scene_GetResListHead(0xC);
            while (entry != NULL) {
                if (*(u16 *)entry == key) {
                    u8 *resource = *(u8 **)(entry + 0x1A0);
                    fldRaySelectWorld((const FldRaySelectionResource *)resource, &selectedWorld);
                    break;
                }
                entry = *(u8 **)(entry + 0x138);
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
        u8 *root = *(u8 **)(iGpffff9db0 + 0x28);
        void *preferredWorld = *(void **)(root + 0x14);
        collisionWorld = preferredWorld != NULL ? preferredWorld : *(void **)(root + 0x8);
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
            if ((*(s32 *)(node + 0x28) & 2) != 0 && *(s32 *)(node + 0x150) == 1) {
                void *modelWorld = mdlGetClump(*(void **)(node + 0x144));
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
            node = *(u8 **)(node + 0x138);
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
extern float D_00756510[]; /* 0x756510 */
extern float D_00756514[]; /* 0x756514 */
extern float D_00756518[]; /* 0x756518 */
extern u16 D_008C024C[];
extern u8 D_008C025E[];
extern float fGpffff84e4; /* 0xffff84e4 */
extern float fGpffff84e8; /* 0xffff84e8 */
extern unsigned int uGpffff9f2c; /* 0xffff9f2c */

extern u8 *FldCameraGetRecord(u8 *);
extern int KMisc_CreateRmdFade(int, int, int, int, int);
extern int KDraw_IsEffectDone(unsigned char *);
extern void KDraw_SetGroupFlags(u8 *, u32);
extern void KDraw_SetSphereFlags(u8 *, u32);
extern void KDraw_SetSphereCenter(unsigned char *, unsigned char *);
extern void KDraw_SetCylinderFlags(u8 *, u32);
extern void KDraw_SetCylinderCenter(unsigned char *, unsigned char *);
extern void KDraw_SetCylinderRadius(unsigned char *, float);
extern void KDraw_SetCylinderHeight(unsigned char *, float);
extern s32 FldFrame_CollideSphereSelected(const RwV3d *, f32, RwV3d *, RwV3d *);
extern void FldCameraSetDistance(u8 *, f32);
extern float FldEvent_GetMoveStep(void);
extern float RwV3dLength(float *);
extern void kAssertFail(void *, int);
extern void mdlSetAlphaBlend(void *);
extern void mdlClearAlphaBlend(void *);



extern float D_00756500[];
extern float D_00756510[];
extern float D_00756520[];
/* measured: scope the 39 -> 0 camera reconstruction to this function. */
#pragma push
/* measured: O3 early copy coalescing retains the declared float webs. */
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
s32 FldCameraTaskUpdate(u8 *param_1)

{
  extern int kwlnTaskDestroyWithHierarchy(void *);
  typedef struct { float x, y, z; } FldTriVec;
  typedef struct { u32 w[16]; } FldMtx64;
  extern float fabsf(float);
  typedef struct { float x, y, z; } FldCopyVec;
  typedef struct { float x, y, z; } FldCamVec;
  typedef struct {
    u8 prefix[0x28c];
    f32 desiredDistance, minimumDistance, currentDistance;
  } FldCameraDistanceView;
  typedef struct RwMatrixTolerance { f32 Normal, Orthogonal, Identity; } RwMatrixTolerance;
  extern s32 RwEngineGetMatrixTolerances(RwMatrixTolerance *tolerance);
  extern RwMatrix *RwMatrixOptimize(RwMatrix *matrix, const RwMatrixTolerance *tolerance);
  extern f32 sqrtf(f32 arg0);
  float stk10[3];
  typedef union { f32 value; u8 bytes[4]; } FldCameraColour;
  FldCameraColour fadeColour;
  FldCopyVec sv20;
  FldCopyVec cpv0;
  float stk40[3];
  float stk50[3];
  FldCopyVec sv60;
  float stk70[3];
  FldCopyVec sv80;
  float stk90[3];
  float stkA0[3];
  RwMatrixTolerance tolerance3;
  float stkC0[3];
  float stkD0[3];
  RwMatrixTolerance tolerance4;
  FldCopyVec stkF0;
  FldCopyVec sv100;
  float stk110[3];
  float stk120[3];
  float stk130[3];
  FldCopyVec cpv5;
  float stk150[3];
  float stk160[3];
  float stk170[3];
  float stk180[3];
  float stk190[3];
  float stk1A0[3];
  float stk1B0[3];
  float stk1C0[3];
  FldCopyVec sv1d0;
  float stk1E0[3];
  FldCamVec cv0;
  FldCopyVec sv200;
  FldCamVec stk210;
  float stk220[3];
  FldCamVec stk230;
  float stk240[3];
  float stk250[3];
  float stk260[3];
  float stk270[3];
  float stk280[3];
  float stk290[3];
  FldCopyVec segment[2];
  FldCamVec chaseSegment[2];
    /* Retail returns zero at 0016E1D0, 0016BE18, 0016BE34. */
  u8 *frameMatrix;
  unsigned char *pbVar7;
  float *pfVar8;
  unsigned char *pbVar9;
  unsigned char * pbVar9_s2;
  unsigned char * pbVar9_s3;
  unsigned int * puVar10_s7;
  unsigned int temp_v5;
  int temp_v6;
  int temp_v7;
  int temp_v8;
  float temp_v9;
  float temp_v12_s7;
  float temp_v10;
  float temp_v11;
  s32 moved;
  float temp_v11_s4;
  float temp_v14_s6;
  float temp_v11_s6;
  float temp_v11_s7;
  float cameraPositionZ;
  float temp_v11_s8;
  float targetX7, targetY7, targetZ7, deltaX7, deltaZ7;
  float horizontalLength7, horizontalZero7, horizontalRadius7;
  float verticalHeight7, verticalRadius7, verticalAmount7, correctionZero7;
  float *correctionVector7;
  float temp_v11_s20;
  float temp_v12;
  float temp_v12_s1;
  float temp_v12_s2;
  float temp_v12_s4;
  float temp_v9_s4;
  float temp_v12_s10;
  float temp_v12_s11;
  float temp_v12_s13;
  float temp_v13;
  float temp_v14;
  float temp_v14_s2;
  float temp_v14_s3;
  float temp_v14_s4;
  float temp_v14_s5;
  float temp_v11_s5;
  float temp_v14_s7;
  float temp_v14_s8;
  float temp_v14_s11;
  unsigned char *pbVar9_a;
  float *pfVar8_a;
  float targetX0, targetY0, targetZ0;
  float deltaX0, deltaZ0;
  float horizontalLength0, horizontalZero0, horizontalRadius0;
  float verticalHeight0, verticalRadius0, verticalAmount0, correctionZero0;
  float *correctionVector0;
  float temp_v11_a;
  float temp_v12_a;
  int temp_v4_a;
  s32 moved_a;
  unsigned char *pbVar9_b;
  float pathDirectionDot;
  float temp_v11_b;
  float targetX34, targetY34, targetZ34;
  float basisY34, basisZ34, projectionZero34;
  float originX34, originZ34, originY34;
  float projectionScale34, closestX34, closestY34, closestZ34;
  float pathRadius34;
  float temp_v12_b;
  float temp_v14_b;
  int count_b;
  int k_b;
  int node3_b;
  int node4_b;
  int temp_v8_b;
  unsigned char *pbVar9_c;
  float *pfVar8_c;
  float temp_v11_c;
  float temp_v12_c;
  float targetX6, targetY6, targetZ6, deltaX6, deltaZ6;
  float horizontalLength6, horizontalZero6, horizontalRadius6;
  float verticalHeight6, verticalRadius6, correctionZero6;
  float *correctionVector6;
  float temp_v14_c;
  int temp_v4_c;
  int followFrame;
  unsigned int temp_v5_c;
  int temp_v6_c;
  int temp_v8_c;
  s32 moved_c;
  unsigned char *pbVar9_d;
  float *pfVar8_d;
  float temp_v11_d;
  float chaseTargetY, chaseTargetZ;
  float temp_v14_d;
  int temp_v4_d;
  unsigned int temp_v5_d;
  int temp_v6_d;
  int temp_v8_d;
  s32 moved_d;
  signed char lo;
  int temp_v4_b;
  signed char hi;
  float resumeDistance;
  int pathLengthOffset;
  s32 pathMode34;
  int loPositionOffset;
  int hiPositionOffset;
  s32 refreshCount;
  s32 attachmentMode;
  u8 *detachedFrame;
  int *piVar1;
  piVar1 = *(int **)((int)param_1 + 0x38);
  if (piVar1[0xa2] == 0) {
    return 0;
  }
  if ((piVar1[1] & 1U) != 0) {
    return 0;
  }
  {

    refreshCount = piVar1[0xb];
    if (refreshCount < 0x80) {
      piVar1[0xb] = refreshCount + 1;
    }
    else {
      piVar1[0xb] = 0;
      frameMatrix = *(u8 **)(kwlnGetCamera() + 4);
      func_003e0670((u8 *)piVar1[0xb1],frameMatrix + 0x10);
      frameMatrix = *(u8 **)(kwlnGetCamera() + 4);
      *(FldMtx64 *)(frameMatrix + 0x10) = *(FldMtx64 *)(piVar1[0xb1]);
    }
    switch (*piVar1) {
    case 0:
    {
      switch(piVar1[2]) {
      case 0:
      case 2:
      case 5:
        FldFrameTask_GetPosition((unsigned char *)&stk260[0],*(unsigned char **)(piVar1[0xa2] + 0x220));
        sv20 = *(FldCopyVec *)stk260;
        pfVar8_a = (float *)FldCameraGetRecord(param_1);
        cpv0 = *(FldCopyVec *)(pfVar8_a);
        moved_a = 0;
        attachmentMode = piVar1[2];
        if ((attachmentMode == 0) || (attachmentMode == 5)) {
          temp_v4_a = (int)kwlnGetCamera();
          if (*(int *)(*(int *)(temp_v4_a + 4) + 4) == piVar1[4]) {
            temp_v4_a = (int)kwlnGetCamera();
            func_003e99a0((void *)*(unsigned int *)(temp_v4_a + 4));
            func_003e9830(piVar1[4],piVar1[3]);
            temp_v4_a = (int)kwlnGetCamera();
            func_003e9830(piVar1[3],*(int *)(temp_v4_a + 4));
          }
        }
        else {
          temp_v4_a = (int)kwlnGetCamera();
          if (*(int *)(*(int *)(temp_v4_a + 4) + 4) != 0) {
            temp_v4_a = (int)kwlnGetCamera();
            func_003e99a0((void *)*(unsigned int *)(temp_v4_a + 4));
          }
          detachedFrame = (u8 *)piVar1[3];
          if (*(int *)(detachedFrame + 4) != 0) {
            func_003e99a0(detachedFrame);
          }
          temp_v4_a = (int)kwlnGetCamera();
          func_003e9830(piVar1[4],*(int *)(temp_v4_a + 4));
        }
        targetX0 = (sv20.x += *(float *)((u8 *)(u32)piVar1 + 0x14));
        targetY0 = (sv20.y += *(float *)((u8 *)(u32)piVar1 + 0x18));
        targetZ0 = (sv20.z += *(float *)((u8 *)(u32)piVar1 + 0x1c));
        deltaX0 = targetX0 - cpv0.x;
        stk40[0] = deltaX0;
        temp_v12_a = targetY0 - cpv0.y;
        stk40[1] = temp_v12_a;
        deltaZ0 = targetZ0 - cpv0.z;
        stk40[2] = deltaZ0;
        {
          const float squaredZ0 = deltaZ0 * deltaZ0;
          horizontalZero0 = 0.0f;
          horizontalLength0 = sqrtf(deltaX0 * deltaX0 + squaredZ0);
        }
        horizontalRadius0 = *(float *)((u8 *)(u32)piVar1 + 0x20);
        if (!(horizontalLength0 <= horizontalRadius0)) {
          temp_v11_a = horizontalLength0 - horizontalRadius0;
          stk40[1] = horizontalZero0;
          correctionVector0 = &stk40[0];
          RwV3dNormalize((RwV3d *)correctionVector0,(const RwV3d *)correctionVector0);
          stk40[0] = stk40[0] * temp_v11_a;
          stk40[1] = stk40[1] * temp_v11_a;
          stk40[2] = stk40[2] * temp_v11_a;
          func_003e9c10((u8 *)piVar1[3],&stk40[0],2);
          moved_a = 1;
        }
        stk40[1] = temp_v12_a;
        if (temp_v12_a < 0.0f) {
          temp_v12_a = temp_v12_a * -1.0f;
        }
        verticalHeight0 = *(float *)((u8 *)(u32)piVar1 + 0x24);
        verticalRadius0 = verticalHeight0 / 2.0f;
        if (!(temp_v12_a <= verticalRadius0)) {
          verticalAmount0 = temp_v12_a - verticalRadius0;
          correctionZero0 = 0.0f;
          stk40[0] = 0.0f;
          stk40[2] = 0.0f;
          if (stk40[1] < correctionZero0) {
            stk40[1] = -verticalAmount0;
          }
          else {
            stk40[1] = verticalAmount0;
          }
          func_003e9c10((u8 *)piVar1[3],&stk40[0],2);
          moved_a = 1;
        }
        if ((moved_a == 1) && (piVar1[2] == 2)) {
          temp_v4_a = *(int *)(kwlnGetCamera() + 4);
          *(FldCopyVec *)stk50 = *(FldCopyVec *)(temp_v4_a + 0x40);
          pbVar9_a = (unsigned char *)kwlnGetCamera();
          pbVar7 = (unsigned char *)FldCameraGetRecord(param_1);
          K_ClumpLookAtBasis(pbVar9_a,(unsigned char *)((int *)&stk50[0]),pbVar7,0);
        }
        goto LAB_0016e0c0;
      case 3:
      case 4:
        FldFrameTask_GetPosition((unsigned char *)&stk270[0],*(unsigned char **)(piVar1[0xa2] + 0x220));
        sv60 = *(FldCopyVec *)stk270;
        count_b = piVar1[0xd] - 1;
        temp_v11_b = 1.0f / (float)count_b;
        if (*(int *)(*(int *)(iGpffff9db0 + 0x28) + 0xa20) == 0) goto LAB_0016e0c0;
        for (k_b = 0; k_b < count_b; k_b++) {
          if (*(char *)((int)piVar1 + k_b + 0xe8) != '\0') break;
        }
        if (k_b >= count_b) goto LAB_0016e0c0;
        /* Retail caches Y/Z across the path calls, but reloads X below. */
        targetX34 = (sv60.x += *(float *)((u8 *)(u32)piVar1 + 0x14));
        targetY34 = (sv60.y += *(float *)((u8 *)(u32)piVar1 + 0x18));
        targetZ34 = (sv60.z += *(float *)((u8 *)(u32)piVar1 + 0x1c));
        stk90[0] = targetX34 - *(float *)&piVar1[0x31];
        stk90[1] = targetY34 - ((float *)piVar1)[0x32];
        stk90[2] = targetZ34 - ((float *)piVar1)[0x33];
        RwV3dNormalize((RwV3d *)&stkA0[0],(const RwV3d *)&stk90[0]);
        sv80 = *(FldCopyVec *)((u8 *)(u32)piVar1 + 0xd0);
        basisY34 = sv80.y;
        basisZ34 = sv80.z;
        {
          const float directionZ = stkA0[2];
          float basisX34;
          float directionX, directionY;
          basisX34 = sv80.x;
          directionX = stkA0[0];
          directionY = stkA0[1];
          {
            const float yProduct = basisY34 * directionY;
            projectionZero34 = 0.0f;
            pathDirectionDot = basisX34 * directionX + yProduct + basisZ34 * directionZ;
          }
          originX34 = *(float *)((u8 *)(u32)piVar1 + 0xc4);
          originZ34 = *(float *)((u8 *)(u32)piVar1 + 0xcc);
          originY34 = *(float *)((u8 *)(u32)piVar1 + 0xc8);
          projectionScale34 = (originX34 * basisX34 - sv60.x * basisX34 + originY34 * basisY34 - targetY34 * basisY34 +
                               originZ34 * basisZ34 - targetZ34 * basisZ34) /
                              -(basisX34 * basisX34 + basisY34 * basisY34 + basisZ34 * basisZ34);
          {
            const float affineOrigin = projectionZero34 + originX34;
            const float scaledDirection = basisX34 * projectionScale34;
            closestX34 = (stk10[0] = affineOrigin + scaledDirection);
          }
          {
            const float affineOrigin = projectionZero34 + originY34;
            const float scaledDirection = basisY34 * projectionScale34;
            closestY34 = (stk10[1] = affineOrigin + scaledDirection);
          }
          {
            const float affineOrigin = projectionZero34 + originZ34;
            const float scaledDirection = basisZ34 * projectionScale34;
            closestZ34 = (stk10[2] = affineOrigin + scaledDirection);
          }
          stk70[0] = originX34 - closestX34;
          stk70[1] = originY34 - closestY34;
          stk70[2] = originZ34 - closestZ34;
        }
        temp_v14_b = RwV3dLength(&stk70[0]);
        {
          float acc = temp_v11_b;
          int last;

          temp_v4_b = 0;
          last = piVar1[0xd] - 1;
          for (; temp_v4_b < last; temp_v4_b++) {
            if (!(acc <= *(float *)((u8 *)(u32)piVar1 + 0xb8))) break;
            acc = acc + temp_v11_b;
          }
          if (temp_v4_b >= last) {
            kAssertFail(D_005F1698,0x15b);
          }
        }
        pathRadius34 = *(float *)((u8 *)(u32)piVar1 + 0x20);
        if (pathRadius34 < temp_v14_b) {
          float lengthRatio;
          pathLengthOffset = temp_v4_b * 4;
          lengthRatio = (temp_v14_b - pathRadius34) / *(float *)(pathLengthOffset + (u32)piVar1 + 0x38);
          temp_v12_s2 = lengthRatio * temp_v11_b;
          if (!(pathDirectionDot <= 0.0f)) {
            ((float *)piVar1)[0x2e] = ((float *)piVar1)[0x2e] + temp_v12_s2;
          }
          else if (pathDirectionDot < -0.0f) {
            ((float *)piVar1)[0x2e] = ((float *)piVar1)[0x2e] - temp_v12_s2;
          }
          {
            float pathTime;
            float maximumTime = ((float *)piVar1)[0x2f];
            pathTime = *(float *)((u8 *)(u32)piVar1 + 0xb8);
            if (!(pathTime < maximumTime)) {
              ((float *)piVar1)[0x2e] = maximumTime;
            }
            else {
              const float minimumTime = ((float *)piVar1)[0x30];
              if (pathTime <= minimumTime) {
                ((float *)piVar1)[0x2e] = minimumTime;
              }
            }
          }
          func_003bb5b0(*(u8 **)(*(int *)(iGpffff9db0 + 0x28) + 0xa20),10,((float *)piVar1)[0x2e],
                       piVar1 + 0x31,piVar1 + 0x34);
          {
            float *pathDirection = ((float *)piVar1) + 0x34;
            RwV3dNormalize((RwV3d *)pathDirection,(const RwV3d *)pathDirection);
          }
        }
        pathMode34 = piVar1[2];
        if (pathMode34 == 3) {
          int last;
          int keyCount, penultimateKey, nextKey;

          node3_b = *(int *)(kwlnGetCamera() + 4);
          temp_v7 = temp_v4_b;
          while (0 < temp_v7) {
            if (*(char *)((int)piVar1 + temp_v7 + 0xe8) != '\0') {
              lo = temp_v7;
              break;
            }
            temp_v7 = temp_v7 - 1;
          }
          if (temp_v7 < 1) {
            kAssertFail(D_005F1698,0x187);
          }
          keyCount = piVar1[0xd];
          penultimateKey = keyCount - 2;
          nextKey = temp_v4_b + 1;
          if (penultimateKey < nextKey) {
            temp_v7 = penultimateKey;
          }
          else {
            temp_v7 = nextKey;
          }
          last = keyCount;
          last--;
          for (; temp_v7 < last; temp_v7++) {
            if (*(char *)((int)piVar1 + temp_v7 + 0xe8) != '\0') {
              hi = temp_v7;
              break;
            }
          }
          if (temp_v7 >= last) {
            kAssertFail(D_005F1698,0x193);
          }
          {
            s32 lowIndex, highIndex;
            float span, loX, dx, loY, dy, loZ, dz, lowCoordinate;
            float interpolationZero, interpolationFraction;
            float *loData, *hiData;
            lowIndex = (s32)lo;
            highIndex = (s32)hi;
            span = temp_v11_b * (float)(highIndex - lowIndex);
            loPositionOffset = lowIndex * 12;
            loData = (float *)(loPositionOffset + (u32)piVar1);
            loX = loData[0x42];
            hiPositionOffset = highIndex * 12;
            hiData = (float *)(hiPositionOffset + (u32)piVar1);
            dx = hiData[0x42] - loX;
            loY = loData[0x43];
            dy = hiData[0x43] - loY;
            loZ = loData[0x44];
            dz = hiData[0x44] - loZ;
            lowCoordinate = (float)lo;
            {
              const float pathTime = ((float *)piVar1)[0x2e];
              interpolationZero = 0.0f;
              {
                const float seededTime = interpolationZero + pathTime;
                const float lowTime = temp_v11_b * lowCoordinate;
                interpolationFraction = (seededTime - lowTime) / span;
              }
            }
            {
              const float affineOrigin = interpolationZero + loX;
              const float scaledDelta = dx * interpolationFraction;
              temp_v13 = affineOrigin + scaledDelta;
            }
            {
              const float affineOrigin = interpolationZero + loY;
              const float scaledDelta = dy * interpolationFraction;
              temp_v10 = affineOrigin + scaledDelta;
            }
            {
              const float affineOrigin = interpolationZero + loZ;
              const float scaledDelta = dz * interpolationFraction;
              temp_v12_b = affineOrigin + scaledDelta;
            }
          }
          {
            u32 identityOne = 0x3f800000;
            *(unsigned int *)(piVar1[0xb0] + 0x28) = identityOne;
            *(unsigned int *)(piVar1[0xb0] + 0x14) = identityOne;
            *(unsigned int *)piVar1[0xb0] = identityOne;
          }
          *(unsigned int *)(piVar1[0xb0] + 0x10) = 0;
          *(unsigned int *)(piVar1[0xb0] + 8) = 0;
          *(unsigned int *)(piVar1[0xb0] + 4) = 0;
          *(unsigned int *)(piVar1[0xb0] + 0x24) = 0;
          *(unsigned int *)(piVar1[0xb0] + 0x20) = 0;
          *(unsigned int *)(piVar1[0xb0] + 0x18) = 0;
          *(unsigned int *)(piVar1[0xb0] + 0x38) = 0;
          *(unsigned int *)(piVar1[0xb0] + 0x34) = 0;
          *(unsigned int *)(piVar1[0xb0] + 0x30) = 0;
          *(unsigned int *)(piVar1[0xb0] + 0xc) = *(unsigned int *)(piVar1[0xb0] + 0xc) | 0x20003;
          RwMatrixRotate((RwMatrix *)piVar1[0xb0],(const RwV3d *)D_00756500,temp_v13,2);
          RwMatrixRotate((RwMatrix *)piVar1[0xb0],(const RwV3d *)D_00756510,temp_v10,2);
          RwMatrixRotate((RwMatrix *)piVar1[0xb0],(const RwV3d *)D_00756520,temp_v12_b,2);
          func_003e9cb0((void *)node3_b,(void *)piVar1[0xb0],0);
          *(FldCopyVec *)(node3_b + 0x40) = *(FldCopyVec *)((u8 *)piVar1 + 0xc4);
          RwEngineGetMatrixTolerances(&tolerance3);
          RwMatrixOptimize((RwMatrix *)(node3_b + 0x10),&tolerance3);
          func_003e9680((u8 *)node3_b);
        }
        else if (pathMode34 == 4) {

          node4_b = *(int *)(kwlnGetCamera() + 4);
          *(FldTriVec *)&stkC0[0] = *(FldTriVec *)(node4_b + 0x40);
          {
            u8 *frame = (u8 *)piVar1[3];
            stkD0[0] = sv60.x - *(float *)(frame + 0x40);
            stkD0[1] = targetY34 - *(float *)(frame + 0x44);
            stkD0[2] = targetZ34 - *(float *)(frame + 0x48);
          }
          pbVar9_b = (unsigned char *)kwlnGetCamera();
          K_ClumpLookAtBasis(pbVar9_b,(unsigned char *)((int *)&stkC0[0]),(unsigned char *)&stkD0[0],0);
          *(FldCopyVec *)(node4_b + 0x40) = *(FldCopyVec *)((u8 *)piVar1 + 0xc4);
          RwEngineGetMatrixTolerances(&tolerance4);
          RwMatrixOptimize((RwMatrix *)(node4_b + 0x10),&tolerance4);
          func_003e9680((u8 *)node4_b);
        }
        goto LAB_0016e0c0;
      case 6:
        FldFrameTask_GetPosition((unsigned char *)&stk280[0],*(unsigned char **)(piVar1[0xa2] + 0x220));
        *(FldTriVec *)&stkF0.x = *(FldTriVec *)&stk280[0];
        pfVar8_c = (float *)FldCameraGetRecord(param_1);
        sv100 = *(FldCopyVec *)pfVar8_c;
        temp_v11_s4 = (float)D_008C025E[0] - 128.0f;
        temp_v4_c = (int)kwlnGetCamera();
        if (*(int *)(*(int *)(temp_v4_c + 4) + 4) == piVar1[4]) {
          temp_v4_c = (int)kwlnGetCamera();
          func_003e99a0((void *)*(unsigned int *)(temp_v4_c + 4));
          func_003e9830(piVar1[4],piVar1[3]);
          temp_v4_c = (int)kwlnGetCamera();
          func_003e9830(piVar1[3],*(int *)(temp_v4_c + 4));
        }
        targetX6 = (stkF0.x += ((float *)piVar1)[0x5]);
        targetY6 = (stkF0.y += ((float *)piVar1)[0x6]);
        targetZ6 = (stkF0.z += ((float *)piVar1)[0x7]);
        deltaX6 = targetX6 - sv100.x;
        stk110[0] = deltaX6;
        temp_v12_s4 = sv100.y;
        stk110[1] = targetY6 - temp_v12_s4;
        deltaZ6 = targetZ6 - sv100.z;
        stk110[2] = deltaZ6;
        {
          const float squaredZ6 = deltaZ6 * deltaZ6;
          horizontalZero6 = 0.0f;
          horizontalLength6 = sqrtf(deltaX6 * deltaX6 + squaredZ6);
        }
        horizontalRadius6 = *(float *)((u8 *)(u32)piVar1 + 0x20);
        if (!(horizontalLength6 <= horizontalRadius6)) {
          temp_v14_s2 = horizontalLength6 - horizontalRadius6;
          stk110[1] = horizontalZero6;
          correctionVector6 = &stk110[0];
          RwV3dNormalize((RwV3d *)correctionVector6,(const RwV3d *)correctionVector6);
          stk110[0] = stk110[0] * temp_v14_s2;
          stk110[1] = stk110[1] * temp_v14_s2;
          stk110[2] = stk110[2] * temp_v14_s2;
          func_003e9c10((u8 *)piVar1[3],&stk110[0],2);
        }
        temp_v12_c = stkF0.y - temp_v12_s4;
        stk110[1] = temp_v12_c;
        if (temp_v12_c < 0.0f) {
          temp_v12_c = temp_v12_c * -1.0f;
        }
        verticalHeight6 = *(float *)((u8 *)(u32)piVar1 + 0x24);
        verticalRadius6 = verticalHeight6 / 2.0f;
        if (!(temp_v12_c <= verticalRadius6)) {
          temp_v12_c = temp_v12_c - verticalRadius6;
          correctionZero6 = 0.0f;
          stk110[0] = 0.0f;
          stk110[2] = 0.0f;
          if (stk110[1] < correctionZero6) {
            stk110[1] = -temp_v12_c;
          }
          else {
            stk110[1] = temp_v12_c;
          }
          func_003e9c10((u8 *)piVar1[3],&stk110[0],2);
        }
        followFrame = *(int *)(kwlnGetCamera() + 4);
        temp_v5_c = (unsigned int)func_003e9700(*(unsigned int *)(followFrame + 4));
        moved_c = 0;
        temp_v12_s7 = *(float *)&piVar1[0xa3];
        *(FldMtx64 *)(piVar1[0xb0]) = *(FldMtx64 *)((followFrame + 0x10));
        {
          float negativeX, negativeY, negativeZ, followDistance;
          float *pushVector;
          temp_v8_c = piVar1[0xb0];
          pushVector = &stk120[0];
          *(FldCopyVec *)stk120 = *(FldCopyVec *)(temp_v8_c + 0x20);
          RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
          negativeX = (stk120[0] = -stk120[0]);
          negativeY = (stk120[1] = -stk120[1]);
          negativeZ = (stk120[2] = -stk120[2]);
          followDistance = 55.0f + ((FldCameraDistanceView *)piVar1)->desiredDistance;
          stk120[0] = negativeX * followDistance;
          stk120[1] = negativeY * followDistance;
          stk120[2] = negativeZ * followDistance;
        }
        RwMatrixTranslate((void *)piVar1[0xb0],&stk120[0],0);
        func_003e0e20((void *)piVar1[0xb0],(void *)temp_v5_c,2);
        segment[0] = stkF0;
        temp_v8_c = piVar1[0xb0];
        segment[1] = *(FldCopyVec *)(temp_v8_c + 0x30);
        *(FldMtx64 *)(piVar1[0xb0]) = *(FldMtx64 *)((followFrame + 0x10));
        temp_v6_c = FldFrame_RaycastField((const RwV3d *)segment,(RwV3d *)&stk130[0]);
        if (temp_v6_c == 1) {
          stk130[0] = stk130[0] - segment[0].x;
          stk130[1] = stk130[1] - segment[0].y;
          stk130[2] = stk130[2] - segment[0].z;
          temp_v14_s4 = RwV3dLength(&stk130[0]);
          if (!(temp_v14_s4 <= 0.0f)) {
            {
              float negativeX, negativeY, negativeZ;
              float *pushVector;
              temp_v8_c = piVar1[0xb0];
              pushVector = &stk120[0];
              *(FldCopyVec *)stk120 = *(FldCopyVec *)(temp_v8_c + 0x20);
              RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
              negativeX = (stk120[0] = -stk120[0]);
              negativeY = (stk120[1] = -stk120[1]);
              negativeZ = (stk120[2] = -stk120[2]);
              stk120[0] = negativeX * temp_v14_s4;
              stk120[1] = negativeY * temp_v14_s4;
              stk120[2] = negativeZ * temp_v14_s4;
            }
            RwMatrixTranslate((void *)piVar1[0xb0],&stk120[0],0);
            temp_v8_c = piVar1[0xb0];
            *(FldCopyVec *)stk150 = *(FldCopyVec *)(temp_v8_c + 0x30);
            temp_v12_s7 = temp_v14_s4;
            moved_c = 1;
          }
        }
        if ((((D_008C024C[0] & 0xf) != 0) || (temp_v11_s4 < -48.0f)) || (!(temp_v11_s4 <= 48.0f))) {
          piVar1[0xab] = 0;
        }
        {
          float yawEntryZero;
          temp_v14_s5 = *(float *)&piVar1[0xab];
          yawEntryZero = 0.0f;
          if (!(yawEntryZero == temp_v14_s5)) {
            float clampZero;
            temp_v9 = 3.0f;
            if (temp_v14_s5 < yawEntryZero) {
              temp_v9 = temp_v9 * -1.0f;
            }
            clampZero = 0.0f;
            if (temp_v9 < clampZero) {
              const float remaining = temp_v14_s5 - temp_v9;
              if (!(remaining <= clampZero)) {
                temp_v9 = temp_v9 + remaining;
              }
            }
            else {
              const float remaining = temp_v14_s5 - temp_v9;
              if (remaining < clampZero) {
                temp_v9 = temp_v9 + remaining;
              }
            }
            temp_v8_c = (int)MT_Scene_GetFrameState();
            FldCameraSetDistance(*(unsigned char **)(temp_v8_c + 4),temp_v9);
            *(float *)((u8 *)(u32)piVar1 + 0x2ac) = (*(float *)((u8 *)(u32)piVar1 + 0x2ac) - temp_v9);
            {
              float completionZero = 0.0f;
              if (completionZero == temp_v9) {
                ((float *)piVar1)[0xab] = completionZero;
              }
            }
          }
        }
        {
          float wallZero, wallNormalX;
          wallNormalX = ((float *)piVar1)[0xac];
          wallZero = 0.0f;
          if ((((wallZero != wallNormalX || wallZero != *(float *)((u8 *)(u32)piVar1 + 0x2b4)) ||
               (wallZero != *(float *)((u8 *)(u32)piVar1 + 0x2b8))) &&
              ((*(float *)((u8 *)(u32)piVar1 + 0x294) < *(float *)((u8 *)(u32)piVar1 + 0x28c) && ((D_008C024C[0] & 0xf) == 0)))) &&
             ((!(temp_v11_s4 < -48.0f) && ((temp_v11_s4 <= 48.0f && (temp_v11_s4 = FldEvent_GetMoveStep(), temp_v11_s4 > 0.0f)))))) {
            {
              float forwardZ, forwardY, forwardX;
              float *forwardVector;
              temp_v8_c = (int)func_003e9700((s32)followFrame);
              forwardVector = &stk1A0[0];
              *(FldCopyVec *)stk1A0 = *(FldCopyVec *)(temp_v8_c + 0x20);
              stk1A0[1] = 0.0f;
              RwV3dNormalize((RwV3d *)forwardVector,(const RwV3d *)forwardVector);
              temp_v11_s5 = D_00756514[0];
              forwardZ = stk1A0[2];
              temp_v14_s6 = D_00756518[0];
              forwardY = stk1A0[1];
              stk190[0] = forwardY * temp_v14_s6 - forwardZ * temp_v11_s5;
              forwardX = stk1A0[0];
              temp_v9_s4 = D_00756510[0];
              stk190[1] = forwardZ * temp_v9_s4 - forwardX * temp_v14_s6;
              stk190[2] = forwardX * temp_v11_s5 - forwardY * temp_v9_s4;
              {
                float *rightVector = &stk190[0];
                RwV3dNormalize((RwV3d *)rightVector,(const RwV3d *)rightVector);
              }
            }
            {
              float normalZ, normalY, normalX;
              normalZ = *(float *)((u8 *)(u32)piVar1 + 0x2b8);
              normalY = *(float *)((u8 *)(u32)piVar1 + 0x2b4);
              stk180[0] = normalY * temp_v14_s6 - normalZ * temp_v11_s5;
              normalX = *(float *)((u8 *)(u32)piVar1 + 0x2b0);
              stk180[1] = normalZ * temp_v9_s4 - normalX * temp_v14_s6;
              stk180[2] = normalX * temp_v11_s5 - normalY * temp_v9_s4;
              {
                float *tangentVector = &stk180[0];
                RwV3dNormalize((RwV3d *)tangentVector,(const RwV3d *)tangentVector);
              }
            }
            {
              float forwardY, forwardX, forwardZ;
              float normalX, normalZ, normalY, facingZero, facingDot;
              forwardY = stk1A0[1];
              forwardX = stk1A0[0];
              normalX = stk180[0];
              forwardZ = stk1A0[2];
              normalZ = stk180[2];
              normalY = stk180[1];
              {
                const float yProduct = normalY * forwardY;
                facingZero = 0.0f;
                facingDot = normalX * forwardX + yProduct + normalZ * forwardZ;
              }
              if (facingDot < facingZero) {
                stk180[0] = -normalX;
                stk180[1] = -normalY;
                stk180[2] = -normalZ;
              }
              {
                float reloadedZ = stk180[2];
                float reloadedX = stk180[0];
                float reloadedY = stk180[1];
                float alignment = reloadedX * forwardX + reloadedY * forwardY + reloadedZ * forwardZ;
                temp_v14_s7 = 180.0f * (1.0f - alignment);
              }
            }
            temp_v11_s6 = *(float *)&piVar1[0xac] * stk190[0] +
                     ((float *)piVar1)[0xad] * stk190[1] + ((float *)piVar1)[0xae] * stk190[2];
            if (temp_v11_s6 < fGpffff84e4) {
              *(float *)((u8 *)(u32)piVar1 + 0x2ac) = -temp_v14_s7;
            }
            else if (!(temp_v11_s6 <= fGpffff84e8)) {
              *(float *)((u8 *)(u32)piVar1 + 0x2ac) = temp_v14_s7;
            }
          }
        }
        piVar1[0xac] = 0;
        piVar1[0xad] = 0;
        piVar1[0xae] = 0;
        func_003e0e20((void *)piVar1[0xb0],(void *)temp_v5_c,2);
        temp_v8_c = FldFrame_CollideSphereSelected((const RwV3d *)((u8 *)piVar1[0xb0] + 0x30),55.0f,(RwV3d *)&stk160[0],(RwV3d *)&stk170[0]);
        if (temp_v8_c == 1) {
          *(FldCopyVec *)&*(float *)((u8 *)(u32)piVar1 + 0x2b0) = *(FldCopyVec *)&stk160;
          {
            float upY, normalZ, upZ, normalY, normalX, upX;
            upY = D_00756514[0];
            normalZ = stk160[2];
            upZ = D_00756518[0];
            normalY = stk160[1];
            stk1B0[0] = normalY * upZ - normalZ * upY;
            normalX = stk160[0];
            upX = D_00756510[0];
            stk1B0[1] = normalZ * upX - normalX * upZ;
            stk1B0[2] = normalX * upY - normalY * upX;
            {
              float *tangentVector = &stk1B0[0];
              RwV3dNormalize((RwV3d *)tangentVector,(const RwV3d *)tangentVector);
            }
          }
          {
            float *forwardVector;
            temp_v8_c = piVar1[0xb0];
            forwardVector = &stk1C0[0];
            *(FldCopyVec *)stk1C0 = *(FldCopyVec *)(temp_v8_c + 0x20);
            RwV3dNormalize((RwV3d *)forwardVector,(const RwV3d *)forwardVector);
          }
          {
            float targetX, targetY, targetZ;
            float tangentY, tangentX, tangentZ;
            float hitX, hitY, hitZ, projectionZero, projectionScale;
            FldFrameTask_GetPosition((unsigned char *)&stkF0.x,*(unsigned char **)(piVar1[0xa2] + 0x220));
            targetX = (stkF0.x += *(float *)((u8 *)(u32)piVar1 + 0x14));
            targetY = (stkF0.y += *(float *)((u8 *)(u32)piVar1 + 0x18));
            targetZ = (stkF0.z += *(float *)((u8 *)(u32)piVar1 + 0x1c));
            temp_v8_c = piVar1[0xb0];
            sv1d0 = *(FldCopyVec *)(temp_v8_c + 0x30);
            tangentY = stk1B0[1];
            tangentX = stk1B0[0];
            tangentZ = stk1B0[2];
            hitX = stk170[0];
            hitY = stk170[1];
            hitZ = stk170[2];
            {
              const float numeratorStart = hitX * tangentX;
              projectionZero = 0.0f;
              projectionScale = (numeratorStart - targetX * tangentX + hitY * tangentY - targetY * tangentY +
                                 hitZ * tangentZ - targetZ * tangentZ) /
                               -(tangentX * tangentX + tangentY * tangentY + tangentZ * tangentZ);
            }
            {
              const float affineOrigin = projectionZero + hitX;
              const float scaledDirection = tangentX * projectionScale;
              stk10[0] = affineOrigin + scaledDirection;
            }
            {
              const float affineOrigin = projectionZero + hitY;
              const float scaledDirection = tangentY * projectionScale;
              stk10[1] = affineOrigin + scaledDirection;
            }
            {
              const float affineOrigin = projectionZero + hitZ;
              const float scaledDirection = tangentZ * projectionScale;
              stk10[2] = affineOrigin + scaledDirection;
            }
            stk1E0[0] = sv1d0.x - hitX;
            stk1E0[1] = sv1d0.y - hitY;
            /* Retail keeps camera Z across both vector-length calls. */
            cameraPositionZ = sv1d0.z;
            stk1E0[2] = cameraPositionZ - hitZ;
            temp_v11_s8 = RwV3dLength(&stk1E0[0]);
          }
          stk1E0[0] = stkF0.x - stk10[0];
          stk1E0[1] = stkF0.y - stk10[1];
          stk1E0[2] = stkF0.z - stk10[2];
          temp_v9 = RwV3dLength(&stk1E0[0]);
          temp_v14_s8 = (stkF0.z - cameraPositionZ) / stk1C0[2];
          temp_v11_s8 = (55.0f - temp_v11_s8) / ((temp_v9 - temp_v11_s8) / temp_v14_s8);
          if (temp_v14_s8 < 0.0f) {
            temp_v14_s8 = temp_v14_s8 * -1.0f;
          }
          if (temp_v11_s8 < 0.0f) {
            temp_v11_s8 = temp_v11_s8 * -1.0f;
          }
          if (temp_v12_s7 <= 0.0f) {
            temp_v12_s7 = *(float *)((u8 *)(u32)piVar1 + 0x28c);
          }
          {
            float wallRatio = fabsf((temp_v14_s8 - temp_v11_s8) / temp_v14_s8);
            {
              float maximumRatio = 1.0f;
              if (!(wallRatio <= maximumRatio)) {
                wallRatio = maximumRatio;
              }
            }
            {
              float normalThreshold, absoluteX;
              absoluteX = fabsf(stk160[0]);
              normalThreshold = 0.2f;
              if (!(absoluteX <= normalThreshold) && !(fabsf(stk160[2]) <= normalThreshold)) {
                wallRatio = wallRatio * 0.5f;
              }
            }
            temp_v12_s7 = temp_v12_s7 * wallRatio;
          }
          moved_c = 1;
        }
        if (moved_c == 1) {
          if (temp_v12_s7 < ((float *)piVar1)[0xa5]) {
            *(FldMtx64 *)(piVar1[0xb0]) = *(FldMtx64 *)((followFrame + 0x10));
            {
              float negativeX, negativeY, negativeZ;
              float *pushVector;
              temp_v8_c = piVar1[0xb0];
              pushVector = &stk120[0];
              *(FldCamVec *)stk120 = *(FldCamVec *)(temp_v8_c + 0x20);
              RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
              negativeX = (stk120[0] = -stk120[0]);
              negativeY = (stk120[1] = -stk120[1]);
              negativeZ = (stk120[2] = -stk120[2]);
              stk120[0] = negativeX * temp_v12_s7;
              stk120[1] = negativeY * temp_v12_s7;
              stk120[2] = negativeZ * temp_v12_s7;
            }
            RwMatrixTranslate((void *)piVar1[0xb0],&stk120[0],0);
            temp_v8_c = piVar1[0xb0];
            *(FldCopyVec *)stk150 = *(FldCopyVec *)(temp_v8_c + 0x30);
            pbVar9_s2 = (unsigned char *)kwlnGetCamera();
            K_ClumpLookAtBasis(pbVar9_s2,(unsigned char *)((int *)&stk150[0]),D_007F1710,0);
            *(float *)((u8 *)(u32)piVar1 + 0x294) = temp_v12_s7;
          }
          else if ((0.0f == *(float *)((u8 *)(u32)piVar1 + 0x2ac)) && ((piVar1[1] & 2U) == 0)) {
            {
              float maximumStep;
              if (0.0f == (temp_v11_c = ((maximumStep = 15.0f) > FldEvent_GetMoveStep()) ? FldEvent_GetMoveStep() : maximumStep)) {
                temp_v11_c = 15.0f;
              }
            }
            temp_v14_c = ((FldCameraDistanceView *)piVar1)->currentDistance;
            if (temp_v12_s7 <= temp_v14_c + temp_v11_c) {
              temp_v11_c = temp_v12_s7 - temp_v14_c;
            }
            *(float *)((u8 *)(u32)piVar1 + 0x294) = *(float *)((u8 *)(u32)piVar1 + 0x294) + temp_v11_c;
            if (!(*(float *)((u8 *)(u32)piVar1 + 0x294) < temp_v12_s7)) {
              *(float *)&piVar1[0xa5] = temp_v12_s7;
            }
            resumeDistance = *(float *)((u8 *)(u32)piVar1 + 0x28c);
            if (*(float *)&piVar1[0xa5] < resumeDistance) {
              *(FldMtx64 *)(piVar1[0xb0]) = *(FldMtx64 *)((followFrame + 0x10));
              {
                float negativeX, negativeY, negativeZ, followDistance;
                float *pushVector;
                temp_v8_c = piVar1[0xb0];
                pushVector = &stk120[0];
                *(FldCamVec *)stk120 = *(FldCamVec *)(temp_v8_c + 0x20);
                RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
                negativeX = (stk120[0] = -stk120[0]);
                negativeY = (stk120[1] = -stk120[1]);
                negativeZ = (stk120[2] = -stk120[2]);
                followDistance = *(float *)&piVar1[0xa5];
                stk120[0] = negativeX * followDistance;
                stk120[1] = negativeY * followDistance;
                stk120[2] = negativeZ * followDistance;
              }
              RwMatrixTranslate((void *)piVar1[0xb0],&stk120[0],0);
              temp_v8_c = piVar1[0xb0];
              *(FldCopyVec *)stk150 = *(FldCopyVec *)(temp_v8_c + 0x30);
              func_003e0e20((void *)piVar1[0xb0],(void *)temp_v5_c,2);
              temp_v8_c = FldFrame_CollideSphereSelected((const RwV3d *)((u8 *)piVar1[0xb0] + 0x30),55.0f,(RwV3d *)&stk160[0],(RwV3d *)&stk170[0]);
              if (temp_v8_c == 0) {
                *(FldCopyVec *)&*(float *)((u8 *)(u32)piVar1 + 0x2b0) = *(FldCopyVec *)&stk160;
                pbVar9_s3 = (unsigned char *)kwlnGetCamera();
                K_ClumpLookAtBasis(pbVar9_s3,(unsigned char *)((int *)&stk150[0]),D_007F1710,0);
              }
              else {
                *(float *)&piVar1[0xa5] = (*(float *)&piVar1[0xa5] - temp_v11_c);
              }
            }
            else {
              *(float *)&piVar1[0xa5] = resumeDistance;
            }
          }
        }
        else if (((*(float *)((u8 *)(u32)piVar1 + 0x2ac) == 0.0f) && ((piVar1[1] & 2U) == 0)) &&
                (*(float *)&piVar1[0xa5] < ((float *)piVar1)[0xa3])) {
          {
            float maximumStep;
            if (0.0f == (temp_v11_c = ((maximumStep = 15.0f) > FldEvent_GetMoveStep()) ? FldEvent_GetMoveStep() : maximumStep)) {
              temp_v11_c = 15.0f;
            }
          }
          {
            float currentDistance, desiredDistance;
            currentDistance = ((FldCameraDistanceView *)piVar1)->currentDistance;
            desiredDistance = *(float *)&piVar1[0xa3];
            if (desiredDistance <= currentDistance + temp_v11_c) {
              temp_v11_c = desiredDistance - currentDistance;
            }
          }
          *(float *)((u8 *)(u32)piVar1 + 0x294) = *(float *)((u8 *)(u32)piVar1 + 0x294) + temp_v11_c;
          {
            float desiredDistance, currentDistance;
            desiredDistance = ((FldCameraDistanceView *)piVar1)->desiredDistance;
            currentDistance = ((FldCameraDistanceView *)piVar1)->currentDistance;
            if (!(currentDistance < desiredDistance)) {
              ((float *)piVar1)[0xa5] = desiredDistance;
            }
          }
          {
            float negativeX, negativeY, negativeZ, followDistance;
            float *pushVector;
            temp_v8_c = piVar1[0xb0];
            pushVector = &stk120[0];
            *(FldCamVec *)stk120 = *(FldCamVec *)(temp_v8_c + 0x20);
            RwV3dNormalize((RwV3d *)pushVector,(const RwV3d *)pushVector);
            negativeX = (stk120[0] = -stk120[0]);
            negativeY = (stk120[1] = -stk120[1]);
            negativeZ = (stk120[2] = -stk120[2]);
            followDistance = ((float *)piVar1)[0xa5];
            stk120[0] = negativeX * followDistance;
            stk120[1] = negativeY * followDistance;
            stk120[2] = negativeZ * followDistance;
          }
          RwMatrixTranslate((void *)piVar1[0xb0],&stk120[0],0);
          temp_v8_c = piVar1[0xb0];
          *(FldCopyVec *)stk150 = *(FldCopyVec *)(temp_v8_c + 0x30);
          func_003e0e20((void *)piVar1[0xb0],(void *)temp_v5_c,2);
          temp_v8_c = FldFrame_CollideSphereSelected((const RwV3d *)((u8 *)piVar1[0xb0] + 0x30),55.0f,(RwV3d *)&stk160[0],(RwV3d *)&stk170[0]);
          if (temp_v8_c == 0) {
            pbVar9_c = (unsigned char *)kwlnGetCamera();
            K_ClumpLookAtBasis(pbVar9_c,(unsigned char *)((int *)&stk150[0]),D_007F1710,0);
          }
          else {
            *(float *)&piVar1[0xa5] = (*(float *)&piVar1[0xa5] - temp_v11_c);
            *(FldCopyVec *)&*(float *)((u8 *)(u32)piVar1 + 0x2b0) = *(FldCopyVec *)&stk160;
          }
        }
        FldFrameTask_GetPosition((unsigned char *)&stkF0.x,*(unsigned char **)(piVar1[0xa2] + 0x220));
        stkF0.y = stkF0.y + 180.0f;
        temp_v4_c = (int)func_003e9700((s32)followFrame);
        cpv5 = *(FldCopyVec *)(temp_v4_c + 0x30);
        stk110[0] = stkF0.x - cpv5.x;
        stk110[1] = stkF0.y - cpv5.y;
        stk110[2] = stkF0.z - cpv5.z;
        temp_v11_c = RwV3dLength(&stk110[0]);
        {
          unsigned char *fadeTask = (unsigned char *)piVar1[0xaa];
          if (fadeTask != (unsigned char *)0x0 &&
              (temp_v4_c = KDraw_IsEffectDone(fadeTask), temp_v4_c == 1)) {
            mdlClearAlphaBlend(*(unsigned char **)(piVar1[0xa2] + 0x164));
            kwlnTaskDestroyWithHierarchy((void *)piVar1[0xaa]);
            piVar1[0xaa] = 0;
          }
        }
        fadeColour = *(const FldCameraColour *)&uGpffff9f2c;
        if (temp_v11_c <= 55.0f + ((float *)piVar1)[0xa4]) {
          if (piVar1[0xaa] != 0) {
            mdlClearAlphaBlend(*(unsigned char **)(piVar1[0xa2] + 0x164));
            kwlnTaskDestroyWithHierarchy((void *)piVar1[0xaa]);
            piVar1[0xaa] = 0;
          }
          mdlSetColor((void *)*(unsigned int *)(piVar1[0xa2] + 0x164),((int *)&fadeColour));
          piVar1[0xa6] = 1;
        }
        if (piVar1[0xa6] != 1) goto LAB_0016e0c0;
        if (temp_v11_c <= 55.0f + *(float *)((u8 *)(u32)piVar1 + 0x290)) goto LAB_0016e0c0;
        mdlSetAlphaBlend(*(unsigned char **)(piVar1[0xa2] + 0x164));
        temp_v4_c = KMisc_CreateRmdFade((int)param_1,*(int *)(piVar1[0xa2] + 0x164),0,0xff,10);
        piVar1[0xaa] = temp_v4_c;
        piVar1[0xa6] = 0;
        goto LAB_0016e0c0;
      case 7:
        FldFrameTask_GetPosition((unsigned char *)&stk290[0],*(unsigned char **)(piVar1[0xa2] + 0x220));
        cv0 = *(FldCamVec *)(stk290);
        pfVar8_d = (float *)FldCameraGetRecord(param_1);
        sv200 = *(FldCopyVec *)pfVar8_d;
        temp_v4_d = (int)kwlnGetCamera();
        if (*(int *)(*(int *)(temp_v4_d + 4) + 4) == piVar1[4]) {
          temp_v4_d = (int)kwlnGetCamera();
          func_003e99a0((void *)*(unsigned int *)(temp_v4_d + 4));
          func_003e9830(piVar1[4],piVar1[3]);
          temp_v4_d = (int)kwlnGetCamera();
          func_003e9830(piVar1[3],*(int *)(temp_v4_d + 4));
        }
        targetX7 = (cv0.x += *(float *)((u8 *)(u32)piVar1 + 0x14));
        targetY7 = (cv0.y += *(float *)((u8 *)(u32)piVar1 + 0x18));
        targetZ7 = (cv0.z += *(float *)((u8 *)(u32)piVar1 + 0x1c));
        deltaX7 = targetX7 - sv200.x;
        stk220[0] = deltaX7;
        temp_v12_s13 = targetY7 - sv200.y;
        stk220[1] = temp_v12_s13;
        deltaZ7 = targetZ7 - sv200.z;
        stk220[2] = deltaZ7;
        {
          const float squaredZ7 = deltaZ7 * deltaZ7;
          horizontalZero7 = 0.0f;
          horizontalLength7 = sqrtf(deltaX7 * deltaX7 + squaredZ7);
        }
        horizontalRadius7 = *(float *)((u8 *)(u32)piVar1 + 0x20);
        if (!(horizontalLength7 <= horizontalRadius7)) {
          temp_v11_s20 = horizontalLength7 - horizontalRadius7;
          stk220[1] = horizontalZero7;
          correctionVector7 = &stk220[0];
          RwV3dNormalize((RwV3d *)correctionVector7,(const RwV3d *)correctionVector7);
          stk220[0] = stk220[0] * temp_v11_s20;
          stk220[1] = stk220[1] * temp_v11_s20;
          stk220[2] = stk220[2] * temp_v11_s20;
          func_003e9c10((u8 *)piVar1[3],&stk220[0],2);
        }
        stk220[1] = temp_v12_s13;
        if (temp_v12_s13 < 0.0f) {
          temp_v12_s13 = temp_v12_s13 * -1.0f;
        }
        verticalHeight7 = *(float *)((u8 *)(u32)piVar1 + 0x24);
        verticalRadius7 = verticalHeight7 / 2.0f;
        if (!(temp_v12_s13 <= verticalRadius7)) {
          verticalAmount7 = temp_v12_s13 - verticalRadius7;
          correctionZero7 = 0.0f;
          stk220[0] = 0.0f;
          stk220[2] = 0.0f;
          if (stk220[1] < correctionZero7) {
            stk220[1] = -verticalAmount7;
          }
          else {
            stk220[1] = verticalAmount7;
          }
          func_003e9c10((u8 *)piVar1[3],&stk220[0],2);
        }
        temp_v4_d = *(int *)(kwlnGetCamera() + 4);
        temp_v5_d = (unsigned int)func_003e9700(*(unsigned int *)(temp_v4_d + 4));
        moved_d = 0;
        temp_v11_d = ((float *)piVar1)[0xa3];
        *(FldMtx64 *)(piVar1[0xb0]) = *(FldMtx64 *)((temp_v4_d + 0x10));
        func_003e0e20((void *)piVar1[0xb0],(void *)temp_v5_d,2);
        /* Retail retains these Y/Z snapshots across camera calls; X is reloaded. */
        chaseTargetY = (cv0.y += *(float *)((u8 *)(u32)piVar1 + 0x2a0));
        temp_v8_d = piVar1[0xb0];
        stk210.x = *(float *)(temp_v8_d + 0x30) - cv0.x;
        stk210.y = *(float *)(temp_v8_d + 0x34) - chaseTargetY;
        chaseTargetZ = cv0.z;
        stk210.z = *(float *)(temp_v8_d + 0x38) - chaseTargetZ;
        {
          float scaledX, scaledY, scaledZ, chaseScale, directionX;
          float *chaseDirection = &stk210.x;
          RwV3dNormalize((RwV3d *)chaseDirection,(const RwV3d *)chaseDirection);
          directionX = stk210.x;
          chaseScale = *(float *)&piVar1[0xa3];
          scaledX = (stk210.x = directionX * chaseScale);
          scaledY = (stk210.y = stk210.y * chaseScale);
          scaledZ = (stk210.z = stk210.z * chaseScale);
          chaseSegment[0] = cv0;
          temp_v8_d = piVar1[0xb0];
          chaseSegment[1] = *(FldCamVec *)(temp_v8_d + 0x30);
          chaseSegment[1].x = chaseSegment[1].x + scaledX;
          chaseSegment[1].y = chaseSegment[1].y + scaledY;
          chaseSegment[1].z = chaseSegment[1].z + scaledZ;
        }
        *(FldMtx64 *)(piVar1[0xb0]) = *(FldMtx64 *)((temp_v4_d + 0x10));
        temp_v6_d = FldFrame_RaycastField((const RwV3d *)chaseSegment,(RwV3d *)&stk230.x);
        if (temp_v6_d == 1) {
          stk230.x = stk230.x - chaseSegment[0].x;
          stk230.y = stk230.y - chaseSegment[0].y;
          stk230.z = stk230.z - chaseSegment[0].z;
          {
            float *hitVector = &stk230.x;
            temp_v14_d = RwV3dNormalize((RwV3d *)hitVector,(const RwV3d *)hitVector);
          }
          if (!(temp_v14_d <= 0.0f)) {
            {
              float *chaseDirection = &stk210.x;
              stk210 = stk230;
              RwV3dNormalize((RwV3d *)chaseDirection,(const RwV3d *)chaseDirection);
            }
            stk210.x = stk210.x * temp_v14_d;
            stk210.y = stk210.y * temp_v14_d;
            stk210.z = stk210.z * temp_v14_d;
            RwMatrixTranslate((void *)piVar1[0xb0],&stk210.x,0);
            *(float *)(piVar1[0xb0] + 0x34) = ((float *)piVar1)[0xa8];
            temp_v4_d = piVar1[0xb0];
            *(FldCopyVec *)stk240 = *(FldCopyVec *)(temp_v4_d + 0x30);
            temp_v11_d = temp_v14_d;
            moved_d = 1;
          }
        }
        if (moved_d == 1) {
          if (temp_v11_d < ((float *)piVar1)[0xa5]) {
            pbVar9_d = (unsigned char *)kwlnGetCamera();
            K_ClumpLookAtBasis(pbVar9_d,(unsigned char *)((int *)&stk240[0]),D_007F1720,0);
            *(float *)((u8 *)(u32)piVar1 + 0x294) = temp_v11_d;
          }
        }
        else if (!(temp_v11_d <= *(float *)((u8 *)(u32)piVar1 + 0x294))) {
          {
            float maximumStep;
            if (0.0f == (temp_v14_d = ((maximumStep = 20.0f) > FldEvent_GetMoveStep()) ? FldEvent_GetMoveStep() : maximumStep)) {
              temp_v14_d = 20.0f;
            }
          }
          *(float *)((u8 *)(u32)piVar1 + 0x294) = *(float *)((u8 *)(u32)piVar1 + 0x294) + temp_v14_d;
          {
            float desiredDistance, currentDistance;
            desiredDistance = ((FldCameraDistanceView *)piVar1)->desiredDistance;
            currentDistance = ((FldCameraDistanceView *)piVar1)->currentDistance;
            if (!(currentDistance <= desiredDistance)) {
              ((float *)piVar1)[0xa5] = desiredDistance;
            }
          }
          func_003e0e20((void *)piVar1[0xb0],(void *)temp_v5_d,2);
          temp_v4_d = piVar1[0xb0];
          stk210.x = *(float *)(temp_v4_d + 0x30) - cv0.x;
          stk210.y = *(float *)(temp_v4_d + 0x34) - chaseTargetY;
          stk210.z = *(float *)(temp_v4_d + 0x38) - chaseTargetZ;
          {
            float chaseScale, directionX;
            float *chaseDirection = &stk210.x;
            RwV3dNormalize((RwV3d *)chaseDirection,(const RwV3d *)chaseDirection);
            directionX = stk210.x;
            chaseScale = ((float *)piVar1)[0xa5];
            stk210.x = directionX * chaseScale;
            stk210.y = stk210.y * chaseScale;
            stk210.z = stk210.z * chaseScale;
          }
          RwMatrixTranslate((void *)piVar1[0xb0],&stk210.x,0);
          *(FldCopyVec *)stk240 = *(FldCopyVec *)(piVar1[0xb0] + 0x30);
          stk240[1] = ((float *)piVar1)[0xa8];
          pbVar9_d = (unsigned char *)kwlnGetCamera();
          K_ClumpLookAtBasis(pbVar9_d,(unsigned char *)((int *)&stk240[0]),D_007F1720,0);
        }
        goto LAB_0016e0c0;
      default:
LAB_0016e0c0:
        KDraw_SetCylinderFlags((unsigned char *)piVar1[0xb2],(unsigned int)((piVar1[1] & 0x80000000U) != 0));
        puVar10_s7 = (unsigned int *)FldCameraGetRecord(param_1);
        {
          unsigned char *targetPosition = (unsigned char *)&stk250[0];
          *(FldCopyVec *)stk250 = *(FldCopyVec *)puVar10_s7;
          KDraw_SetCylinderCenter((unsigned char *)piVar1[0xb2],targetPosition);
        }
        KDraw_SetCylinderRadius((unsigned char *)piVar1[0xb2],*(float *)((u8 *)(u32)piVar1 + 0x20));
        KDraw_SetCylinderHeight((unsigned char *)piVar1[0xb2],*(float *)((u8 *)(u32)piVar1 + 0x24));
        if (*(int *)(*(int *)(iGpffff9db0 + 0x28) + 0xa20) != 0) {
          {
            unsigned char *cameraHelper = (unsigned char *)piVar1[0xb3];
            if (cameraHelper != (unsigned char *)0x0) {
              KDraw_SetGroupFlags(cameraHelper,(unsigned int)((piVar1[1] & 0x80000000U) != 0));
            }
          }
          {
            unsigned char *pathHelper = (unsigned char *)piVar1[0xb4];
            if (pathHelper != (unsigned char *)0x0) {
              KDraw_SetSphereFlags(pathHelper,(unsigned int)((piVar1[1] & 0x80000000U) != 0));
              KDraw_SetSphereCenter((unsigned char *)piVar1[0xb4],(unsigned char *)(piVar1 + 0x31));
            }
          }
          {
            unsigned char *projectionHelper = (unsigned char *)piVar1[0xb5];
            if (projectionHelper != (unsigned char *)0x0) {
              KDraw_SetSphereFlags(projectionHelper,(unsigned int)((piVar1[1] & 0x80000000U) != 0));
              KDraw_SetSphereCenter((unsigned char *)piVar1[0xb5],(unsigned char *)&stk10[0]);
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
// FUN_0016E210
void FldCameraTaskDestroy(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(*(u8 **)(kwlnGetCamera() + 4) + 4) != 0) {
        func_003e99a0(*(void **)(kwlnGetCamera() + 4));
    }
    if (*(s32 *)(*(u8 **)(temp_16 + 0xC) + 4) != 0) {
        func_003e99a0(*(void **)(temp_16 + 0xC));
    }
    func_003e9390(*(void **)(temp_16 + 0xC));
    func_003e9830(*(s32 *)(temp_16 + 0x10), *(s32 *)(kwlnGetCamera() + 4));
    func_003e0f40(*(s32 *)(temp_16 + 0x2BC));
    func_003e0f40(*(s32 *)(temp_16 + 0x2C0));
    func_003e0f40(*(s32 *)(temp_16 + 0x2C4));
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}

/* measured: opt_common_subs off preserves the retail per-call table address
   materialization and five-register frame in FldCameraTaskCreate. */
// FUN_0016E2E0
#pragma push
/* measured: FldCameraTaskCreate MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
s32 FldCameraTaskCreate(s32 arg0)
{
    s32 temp_18;
    s32 temp_5;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_2_3;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_19;

    chkmemAllocSiteTag(D_005F1698, 0x4CE);
    temp_2 = (u8 *)D_008873F4[0](1, 0x2D8, 0x40000);
    if (temp_2 == NULL) {
        return 0;
    }
    temp_18 = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F16B0), 0x11, 0, 0, FldCameraTaskUpdate, FldCameraTaskDestroy, (u8 *)(temp_2));
    temp_16 = temp_2 + 0xC;
    temp_2_2 = (u8 *)func_003e9320();
    *(u8 **)(temp_16 + 0) = temp_2_2;
    if (temp_2_2 == NULL) {
        kwlnTaskDestroyWithHierarchy(temp_18);
        return 0;
    }
    func_003e9df0(temp_2_2);
    temp_16 = temp_2 + 0x10;
    temp_2_3 = *(u8 **)(*(u8 **)(kwlnGetCamera() + 4) + 4);
    *(u8 **)(temp_16 + 0) = temp_2_3;
    if (temp_2_3 != NULL) {
        func_003e99a0(*(void **)(kwlnGetCamera() + 4));
        temp_17 = temp_2 + 0xC;
        func_003e9830(*(s32 *)(temp_16 + 0),
                      *(s32 *)(temp_17 + 0));
        func_003e9830(*(s32 *)(temp_17 + 0),
                      *(s32 *)(kwlnGetCamera() + 4));
    } else {
        kAssertFail(D_005F1698, 0x4F6);
    }
    *(s32 *)(temp_2 + 0x2BC) = func_003e0f80();
    *(s32 *)(temp_2 + 0x2C0) = func_003e0f80();
    *(s32 *)(temp_2 + 0x2C4) = func_003e0f80();
    *(s32 *)(temp_2 + 0x2C8) = KDraw_CreateCylinderTask(temp_18, D_007948D0);
    temp_5 = *(s32 *)(*(u8 **)(iGpffff9db0 + 0x28) + 0xA20);
    if (temp_5 != 0) {
        temp_19 = temp_2 + 0x2CC;
        *(s32 *)(temp_19 + 0) = KDraw_CreateGroupTask(temp_18, temp_5,
                                              D_007948D0);
        temp_17 = temp_2 + 0x2D0;
        *(s32 *)(temp_17 + 0) = KDraw_CreateSphereTask(temp_18,
                                              D_007948D0);
        temp_16 = temp_2 + 0x2D4;
        *(s32 *)(temp_16 + 0) = KDraw_CreateSphereTask(temp_18,
                                              D_007948D0);
        KDraw_SetGroupColor(*(void **)(temp_19 + 0),
                      (u8 *)&iGpffff9f00 + 0x30);
        KDraw_SetSphereColor(*(void **)(temp_17 + 0),
                      (u8 *)&iGpffff9f00 + 0x30);
        KDraw_SetSphereColor(*(void **)(temp_16 + 0),
                      (u8 *)&iGpffff9f00 + 0x34);
    }
    return temp_18;
}

#pragma pop
// FUN_0016E540
void FldFrame_SetStateFlags(u8 *arg0, s32 arg1)
{
    u8 *temp_0 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_0 + 4) = *(s32 *)(temp_0 + 4) | arg1;
}

// FUN_0016E560
void FldFrame_ClearStateFlags(u8 *arg0, s32 arg1)
{
    u8 *temp_0 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(temp_0 + 4) = *(s32 *)(temp_0 + 4) & ~arg1;
}

// FUN_0016E580
s32 FldFrame_GetStatus(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x8);
}

// FUN_0016E590
/* measured: object 804B/window 816B, nd 0. The 3/4 test is two separate compares
   (goto body / goto skip; `== 3 || == 4` folds to sltiu). The count guard is
   `> 0x20` for the $at slti form. Locals in stack order: diff, prev, cur, then
   the two 64-byte matrix copies (case 6 at sp+0x70, case 7 at sp+0x30), each a
   two-word copy loop from func_00457120()->frame + 0x10; `prev = cur` is the
   RwV3d struct copy (ld/sd + lwc1/swc1). */
void FldCameraAdvanceCurve(u8 *arg0, s32 arg1)
{
    extern s32 func_003bb330(u8 *arg0);
    extern void func_003bb3a0(u8 *arg0, s32 arg1, void *arg2);
    extern void func_003bb5b0(u8 *curve, s32 mode, f32 time, void *dst, void *aux);
    extern f32 RwV3dLength(void *arg0);
    extern void kAssertFail(const void *arg0, s32 arg1);
    RwV3d diff;
    RwV3d prev;
    RwV3d cur;
    u8 mat6[0x40];
    u8 mat7[0x40];
    u8 *work;
    s32 i;
    f32 t;
    u8 *src;
    u8 *dst;
    s32 n;
    s32 t1;
    s32 t2;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 8) = arg1;
    if (arg1 == 3) {
        goto body;
    }
    if (arg1 != 4) {
        goto skip;
    }
body:
    {
        if (*(s32 *)(*(u8 **)(iGpffff9db0 + 0x28) + 0xA20) != 0) {
            func_003e9df0(*(void **)(kwlnGetCamera() + 4));
            *(s32 *)(work + 0x34) = func_003bb330(*(u8 **)(*(u8 **)(iGpffff9db0 + 0x28) + 0xA20));
            if (*(s32 *)(work + 0x34) > 0x20) {
                kAssertFail(D_005F1698, 0x557);
            }
            func_003bb3a0(*(u8 **)(*(u8 **)(iGpffff9db0 + 0x28) + 0xA20), 0, &prev);
            for (i = 1; i < *(s32 *)(work + 0x34); i++) {
                func_003bb3a0(*(u8 **)(*(u8 **)(iGpffff9db0 + 0x28) + 0xA20), i, &cur);
                diff.x = cur.x - prev.x;
                diff.y = cur.y - prev.y;
                diff.z = cur.z - prev.z;
                *(f32 *)(work + i * 4 + 0x34) = RwV3dLength(&diff);
                prev = cur;
            }
            t = 1.0f / (f32)(*(s32 *)(work + 0x34) - 1);
            *(f32 *)(work + 0xBC) = 1.0f - t;
            *(f32 *)(work + 0xC0) = t;
            *(f32 *)(work + 0xB8) = 0.5f;
            func_003bb5b0(*(u8 **)(*(u8 **)(iGpffff9db0 + 0x28) + 0xA20), 0xA, *(f32 *)(work + 0xB8), work + 0xC4, work + 0xD0);
            RwV3dNormalize((RwV3d *)(work + 0xD0), (const RwV3d *)(work + 0xD0));
            if (*(s32 *)(*(u8 **)(kwlnGetCamera() + 4) + 4) != 0) {
                func_003e99a0(*(void **)(kwlnGetCamera() + 4));
            }
            if (*(s32 *)(*(u8 **)(work + 0xC) + 4) != 0) {
                func_003e99a0(*(void **)(work + 0xC));
            }
            func_003e9830(*(s32 *)(work + 0x10), *(s32 *)(kwlnGetCamera() + 4));
        }
    }
skip:
    if (*(s32 *)(work + 8) == 6) {
        src = *(u8 **)(kwlnGetCamera() + 4) + 0x10;
        dst = mat6;
        n = 8;
        do {
            t1 = *(s32 *)src;
            t2 = *(s32 *)(src + 4);
            src += 8;
            n -= 1;
            *(s32 *)dst = t1;
            *(s32 *)(dst + 4) = t2;
            dst += 8;
        } while (n > 0);
        t = RwV3dLength(mat6 + 0x30);
        *(f32 *)(work + 0x28C) = t;
        *(f32 *)(work + 0x294) = t;
        *(RwV3d *)(work + 0x29C) = *(RwV3d *)(mat6 + 0x30);
    } else if (*(s32 *)(work + 8) == 7) {
        src = *(u8 **)(kwlnGetCamera() + 4) + 0x10;
        dst = mat7;
        n = 8;
        do {
            t1 = *(s32 *)src;
            t2 = *(s32 *)(src + 4);
            src += 8;
            n -= 1;
            *(s32 *)dst = t1;
            *(s32 *)(dst + 4) = t2;
            dst += 8;
        } while (n > 0);
        *(RwV3d *)(work + 0x29C) = *(RwV3d *)(mat7 + 0x30);
        *(f32 *)(mat7 + 0x34) = 0.0f;
        t = RwV3dLength(mat7 + 0x30);
        *(f32 *)(work + 0x28C) = t;
        *(f32 *)(work + 0x294) = t;
    }
    *(f32 *)(work + 0x290) = *(f32 *)(kwlnGetCamera() + 0x80);
}

// FUN_0016E8C0
u8 *FldCameraGetRecord(u8 *arg0)
{
    return *(u8 **)(*(u8 **)(arg0 + 0x38) + 0xC) + 0x40;
}

/* measured: opt_propagation off preserves the retail early a1 pointer
   materialization in FldCameraSetDistance. */
/* measured: FldCameraSetDistance MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0016E8E0
void FldCameraSetDistance(u8 *arg0, f32 fparg0)
{
    E8E0Frame sp;
    void *temp_2;
    s64 temp_5;
    f32 temp_f0;
    f32 temp_f1;
    u8 *var_3;
    s32 temp_4;
    s32 var_2;
    u8 *temp_16;

    temp_4 = *(s32 *)(*(u8 **)(arg0 + 0x38) + 8);
    if (temp_4 == 0) {
        goto process;
    }
    if (temp_4 == 6) {
        goto process;
    }
    if (temp_4 != 7) {
        goto done;
    }
process:
    temp_16 = *(u8 **)(kwlnGetCamera(temp_4) + 4);
    sp.sp50 = *(RwV3d *)(temp_16 + 0x40);
    var_3 = &sp.sp40[0];
    var_2 = 0xC;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3 += 1;
            var_2 -= 1;
        } while (var_2 != 0);
    }
    temp_2 = &sp.sp30;
    temp_5 = *(s64 *)D_005F16C8;
    temp_f0 = *(f32 *)D_005F16D0;
    sp.sp30 = temp_5;
    sp.sp38 = temp_f0;
    temp_f1 = fparg0;
    func_003e9d50(temp_16, temp_2, temp_f1, 2);
    sp.sp50 = *(RwV3d *)(temp_16 + 0x40);
    K_ClumpLookAtBasis(kwlnGetCamera(), &sp.sp50, &sp.sp40[0], 0);
done:
    ;
}

/* measured: closes opt_propagation off for FldCameraSetDistance. */
// FUN_0016E9F0
void FldFrame_SetViewOffset(u8 *arg0, u8 *arg1)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    *(RwV3d *)(temp_3 + 0x14) = *(RwV3d *)(arg1 + 0x00);
}

// FUN_0016EA20
void FldFrame_SetViewDistance(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x20) = arg1;
}

// FUN_0016EA30
void func_0016ea30(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x24) = arg1;
}

// FUN_0016EA40
void FldFrame_BindTypedRes(u8 *arg0, u16 arg1)
{
    u8 *temp_16;
    s32 type;

    temp_16 = *(u8 **)(arg0 + 0x38);
    type = (arg1 & 0xFFC00) >> 10;
    if (type == 1)
        *(u8 **)(temp_16 + 0x288) = MT_Scene_GetRes(arg1);
}

// FUN_0016EAA0
/* The scaled offset is named in an s32 local and the base added TO it so the
   final addu comes out `index + base` as retail has it; folding the multiply
   into the pointer expression emits `base + index` (nd 1). The three floats
   are one RwV3d assignment because retail loads all three before storing
   any. */
void FldFrame_SetSlotVector(u8 *arg0, s32 arg1, RwV3d *arg2) {
    u8 *base;
    s32 i;
    s32 off;

    base = *(u8 **)(arg0 + 0x38);
    i = (s8)arg1;
    base[i + 0xE8] = 1;
    off = i * 12;
    *(RwV3d *)(off + (s32)base + 0x108) = *arg2;
}

// FUN_0016EAF0
s32 FldFrame_GetSlotBuffer(u8 *arg0)
{
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x2BC);
}

/* measured: opt_propagation off preserves global initialization ordering in FldCameraUpdateLookAt. */
// FUN_0016EB00
void FldCameraUpdateLookAt(u8 *arg0)
{
    E8E0Frame sp;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_2;
    u8 *var_3;
    u8 *temp_17;
    s32 temp_4;
    s32 var_2;
    s64 temp_5;
    f32 temp_f0;
    u32 temp_3;

    temp_3 = *(u32 *)(*(u8 **)(arg0 + 0x38) + 8);
    switch (temp_3) {
    case 0:
    case 5:
    case 6:
        temp_2 = ((u8*)MT_Scene_GetFrameState());
        if ((*(s32 *)(*(u8 **)(*(u8 **)(temp_2 + 4) + 0x38) + 8) == 0) ||
            (*(s32 *)(*(u8 **)(*(u8 **)(temp_2 + 4) + 0x38) + 8) == 6) ||
            (*(s32 *)(*(u8 **)(*(u8 **)(temp_2 + 4) + 0x38) + 8) == 7)) {
            temp_16 = *(u8 **)(kwlnGetCamera() + 4);
            sp.sp50 = *(RwV3d *)(temp_16 + 0x40);
            var_3 = &sp.sp40[0];
            var_2 = 0xC;
            if (var_3 != NULL) {
                do {
                    *var_3 = 0;
                    var_3 += 1;
                    var_2 -= 1;
                } while (var_2 != 0);
            }
            temp_2 = (u8 *)&sp.sp30;
            temp_5 = *(s64 *)D_005F16C8;
            temp_f0 = *(f32 *)D_005F16D0;
            sp.sp30 = temp_5;
            sp.sp38 = temp_f0;
            func_003e9d50(temp_16, temp_2, 0.0f, 2);
            sp.sp50 = *(RwV3d *)(temp_16 + 0x40);
            K_ClumpLookAtBasis(kwlnGetCamera(), &sp.sp50, &sp.sp40[0], 0);
        }
        break;
    case 2:
        temp_17 = *(u8 **)(kwlnGetCamera() + 4);
        temp_16_2 = (u8 *)(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) + 0x40);
        temp_2 = kwlnGetCamera();
        K_ClumpLookAtBasis(temp_2, temp_17 + 0x40, temp_16_2, 0);
        break;
    case 1:
    case 3:
    case 4:
    default:
        break;
    }
}

/* measured: restore opt_propagation after FldCameraUpdateLookAt. */
// FUN_0016EC90
void FldCameraUpdateOrbit(u8 *arg0)
{
    f32 sp50[3];
    f32 sp40[3];
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    s32 temp_2;
    s32 temp_3;
    s32 temp_4;
    u8 *var_6;
    u8 *var_5;
    s32 var_4;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_18;
    u8 *temp_2_2;
    u8 *temp_2_3;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s32 *)(temp_16 + 8);
    if (temp_4 == 6) {
        temp_18 = *(u8 **)(kwlnGetCamera() + 4);
        temp_17 = func_003e9700(*(s32 *)(temp_18 + 4));
        var_6 = temp_18 + 0x10;
        var_5 = *(u8 **)(temp_16 + 0x2C0);
        var_4 = 8;
        do {
            temp_3 = *(s32 *)(var_6 + 0);
            temp_2 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            var_4 -= 1;
            *(s32 *)(var_5 + 0) = temp_3;
            *(s32 *)(var_5 + 4) = temp_2;
            var_5 += 8;
        } while (var_4 > 0);
        temp_2_2 = *(u8 **)(temp_16 + 0x2C0);
        *(RwV3d *)&sp40[0] = *(RwV3d *)(temp_2_2 + 0x20);
        RwV3dNormalize((RwV3d *)&sp40[0], (const RwV3d *)&sp40[0]);
        temp_f4 = -sp40[0];
        sp40[0] = temp_f4;
        temp_f3 = -sp40[1];
        sp40[1] = temp_f3;
        temp_f2 = -sp40[2];
        sp40[2] = temp_f2;
        temp_f1 = *(f32 *)(temp_16 + 0x28C);
        sp40[0] = temp_f4 * temp_f1;
        sp40[1] = temp_f3 * temp_f1;
        sp40[2] = temp_f2 * temp_f1;
        *(f32 *)(temp_16 + 0x294) = temp_f1;
        RwMatrixTranslate(*(u8 **)(temp_16 + 0x2C0), &sp40[0], 0);
        temp_2_3 = *(u8 **)(temp_16 + 0x2C0);
        *(RwV3d *)&sp50[0] = *(RwV3d *)(temp_2_3 + 0x30);
        func_003e0e20(*(u8 **)(temp_16 + 0x2C0), temp_17, 2);
        K_ClumpLookAtBasis(kwlnGetCamera(), &sp50[0], &D_007F1730[0], 0);
    }
}

/* measured: opt_propagation off probe for retail pre-call address order. */
// FUN_0016EE00
s32 FldFrame_RotateTaskUpdate(u8 *arg0)
{
    EEE0Frame sp;
    void *temp_2;
    void *temp_2_2;
    s64 temp_5;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f20_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    u8 *var_3;
    u8 *var_3_2;
    s32 var_2;
    s32 var_2_2;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)(temp_16 + 0);
    switch (temp_3) {
    case 0:
        temp_f20 = *(f32 *)(temp_16 + 0xC);
        temp_3_2 = *(s32 *)(*(u8 **)(*(u8 **)(((u8*)MT_Scene_GetFrameState()) + 4) + 0x38) + 8);
        if (temp_3_2 == 0)
            goto process0;
        if (temp_3_2 == 6)
            goto process0;
        if (temp_3_2 != 7)
            goto skip_process0;
process0:
        temp_17 = *(u8 **)(kwlnGetCamera() + 4);
        sp.sp90 = *(RwV3d *)(temp_17 + 0x40);
        var_3 = &sp.sp80[0];
        var_2 = 0xC;
        if (var_3 != NULL) {
            do {
                *var_3 = 0;
                var_3 += 1;
                var_2 -= 1;
            } while (var_2 != 0);
        }
        temp_2 = &sp.sp70;
        temp_5 = *(s64 *)D_005F16C8;
        temp_f0 = *(f32 *)D_005F16D0;
        sp.sp70 = temp_5;
        sp.sp78 = temp_f0;
        temp_f1 = temp_f20;
        func_003e9d50(temp_17, temp_2, temp_f1, 2);
        sp.sp90 = *(RwV3d *)(temp_17 + 0x40);
        K_ClumpLookAtBasis(kwlnGetCamera(), &sp.sp90, &sp.sp80[0], 0);
skip_process0:
        *(s32 *)(temp_16 + 0) += 1;
        /* fallthrough */
    case 1:
        temp_3_3 = *(s32 *)(temp_16 + 8);
        if (temp_3_3 < *(s32 *)(temp_16 + 4)) {
            *(s32 *)(temp_16 + 8) = temp_3_3 + 1;
            temp_f21 = sinf((iGpffff8094 *
                                      (f32)*(s32 *)(temp_16 + 8)) /
                                     (f32)*(s32 *)(temp_16 + 4));
            if (*(s32 *)(((u8*)MT_Scene_GetFrameState()) + 4) != 0) {
                temp_f20_2 = *(f32 *)(temp_16 + 0x10) *
                             (temp_f21 - *(f32 *)(temp_16 + 0x14));
                temp_3_4 = *(s32 *)(*(u8 **)(*(u8 **)(((u8*)MT_Scene_GetFrameState()) + 4) +
                                             0x38) + 8);
                if (temp_3_4 == 0)
                    goto process1;
                if (temp_3_4 == 6)
                    goto process1;
                if (temp_3_4 != 7)
                    goto skip_process1;
process1:
                temp_17_2 = *(u8 **)(kwlnGetCamera() + 4);
                sp.sp60 = *(RwV3d *)(temp_17_2 + 0x40);
                var_3_2 = &sp.sp50[0];
                var_2_2 = 0xC;
                if (var_3_2 != NULL) {
                    do {
                        *var_3_2 = 0;
                        var_3_2 += 1;
                        var_2_2 -= 1;
                    } while (var_2_2 != 0);
                }
                temp_2_2 = &sp.sp40;
                temp_5 = *(s64 *)D_005F16C8;
                temp_f0 = *(f32 *)D_005F16D0;
                sp.sp40 = temp_5;
                sp.sp48 = temp_f0;
                temp_f1 = temp_f20_2;
                func_003e9d50(temp_17_2, temp_2_2, temp_f1, 2);
                sp.sp60 = *(RwV3d *)(temp_17_2 + 0x40);
                K_ClumpLookAtBasis(kwlnGetCamera(), &sp.sp60,
                              &sp.sp50[0], 0);
skip_process1:
                ;
            }
            *(f32 *)(temp_16 + 0x14) = temp_f21;
        } else {
            *(s32 *)(temp_16 + 0) += 1;
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
void FldFrame_RotateTaskDestroy(u8 *arg0)
{
    (*DAT_008873EC)(*(void **)(arg0 + 0x38));
}

/* measured: opt_loop_invariants on reproduces FldFrame_RotateTaskCreate's retail loop schedule. */
/* measured: FldFrame_RotateTaskCreate MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_0016F130
u8 *FldFrame_RotateTaskCreate(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *result;
    u8 *temp_2;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f3;
    f32 temp_f2;

    result = NULL;
    if (*(s32 *)D_007EF9F8 != 0) {
        chkmemAllocSiteTag(D_005F1698, 0x71C);
        temp_2 = (u8 *)D_008873F4[0](1, 0x18, 0x40000);
        if (temp_2 == NULL) {
            return NULL;
        }
            result = (u8 *)(s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F16E0), 0xF, 0, 0, FldFrame_RotateTaskUpdate, FldFrame_RotateTaskDestroy, (u8 *)(temp_2));
            *(s32 *)(temp_2 + 4) = arg1;
            temp_f20 = KDraw_MatrixYawDeg(
                mdlGetMatrix(*(s32 *)D_007EFA00));
            if (temp_f20 < 0.0f) {
                temp_f20 += 360.0f;
            }
            temp_f0 = KDraw_MatrixYawDeg(
                func_003e9700(*(s32 *)(kwlnGetCamera() + 4)));
            if (temp_f0 < 0.0f) {
                temp_f0 += 360.0f;
            }
            if (arg2 != -1) {
                temp_f20 += (f32)arg2;
                for (; temp_f20 > 360.0f; temp_f20 -= 360.0f) {
                }
            }
            temp_f4 = temp_f20 - temp_f0;
            if (temp_f0 > 180.0f) {
                temp_f3 = (360.0f - temp_f0) + temp_f20;
            } else {
                temp_f3 = -((360.0f - temp_f20) + temp_f0);
            }
            temp_f2 = 360.0f;
            while (temp_f4 > temp_f2) {
                temp_f4 -= temp_f2;
            }
            while (temp_f3 > temp_f2) {
                temp_f3 -= temp_f2;
            }
            if (fabsf(temp_f4) < fabsf(temp_f3)) {
                *(f32 *)(temp_2 + 0x10) = temp_f4;
            } else {
                *(f32 *)(temp_2 + 0x10) = temp_f3;
            }
    }
    return result;
}

/* measured: close opt_loop_invariants scope after FldFrame_RotateTaskCreate. */
/* measured: opt_loop_invariants on reproduces FldFrameRotateTaskCreate's loop schedule
   and FPU register allocation. */
#pragma push
// FUN_0016F3B0
u8 *FldFrameRotateTaskCreate(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *result;
    u8 *temp_2;
    f32 temp_f0;
    f32 temp_f4;
    f32 temp_f3;
    f32 temp_f2;

    result = NULL;
    if (*(s32 *)D_007EF9F8 != 0) {
        chkmemAllocSiteTag(D_005F1698, 0x774);
        temp_2 = (u8 *)D_008873F4[0](1, 0x18, 0x40000);
        if (temp_2 == NULL) {
            return NULL;
        }
        result = (u8 *)(s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_005F16E0), 0xF, 0, 0, FldFrame_RotateTaskUpdate, FldFrame_RotateTaskDestroy, (u8 *)(temp_2));
        *(s32 *)(temp_2 + 4) = arg1;
        KDraw_MatrixYawDeg(mdlGetMatrix(*(s32 *)D_007EFA00));
        temp_f0 = KDraw_MatrixYawDeg(
            func_003e9700(*(s32 *)(kwlnGetCamera() + 4)));
        if (temp_f0 < 0.0f) {
            temp_f0 += 360.0f;
        }
        temp_f4 = (f32)arg2;
        while (temp_f4 > 360.0f) {
            temp_f4 -= 360.0f;
        }
        while (temp_f4 < -360.0f) {
            temp_f4 += 360.0f;
        }
        temp_f3 = temp_f4 - temp_f0;
        if (temp_f0 > 180.0f) {
            temp_f2 = (360.0f - temp_f0) + temp_f4;
        } else {
            temp_f2 = -((360.0f - temp_f4) + temp_f0);
        }
        while (temp_f3 > 360.0f) {
            temp_f3 -= 360.0f;
        }
        while (temp_f2 > 360.0f) {
            temp_f2 -= 360.0f;
        }
        if (fabsf(temp_f3) < fabsf(temp_f2)) {
            *(f32 *)(temp_2 + 0x10) = temp_f3;
        } else {
            *(f32 *)(temp_2 + 0x10) = temp_f2;
        }
    }
    return result;
}

#pragma pop
/* measured: FldEventSnapshotCapture compiles to object 276B against the 288B retail
   window (normalized_diff 0; trailing zero padding is normalized). */
// FUN_0016F630
/* measured: optimization_level 1 reproduces FldEventSnapshotCapture register allocation. */
/* measured: FldEventSnapshotCapture MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
void FldEventSnapshotCapture(FldEventSnapshot *arg0, u8 *arg1)
{
    F630Frame sp;
    s128 *var_17;
    s128 *var_5_2;
    u8 *temp_16;
    u8 *var_7;
    u8 *var_6;
    u8 *temp_18;
    s32 var_4;
    s32 var_5;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    s128 temp_3_2;

    var_17 = (s128 *)arg0;
    temp_16 = *(u8 **)(arg1 + 0x38);
    temp_18 = *(u8 **)(kwlnGetCamera() + 4);
    memset(&sp, 0, sizeof(sp));
    sp.sp80 = K_View_GetFov(kwlnGetCamera());
    var_7 = (u8 *)(temp_18 + 0x10);
    var_6 = &sp.work[0];
    var_5 = 8;
    do {
        s32 temp_4;
        s32 temp_3;
        temp_4 = *(s32 *)(var_7 + 0);
        temp_3 = *(s32 *)(var_7 + 4);
        var_7 += 8;
        var_5 -= 1;
        *(s32 *)(var_6 + 0) = temp_4;
        *(s32 *)(var_6 + 4) = temp_3;
        var_6 += 8;
    } while (var_5 > 0);
    sp.sp84 = (s16)*(s32 *)(temp_16 + 8);
    temp_f2 = *(f32 *)(temp_16 + 0x14);
    temp_f1 = *(f32 *)(temp_16 + 0x18);
    temp_f0 = *(f32 *)(temp_16 + 0x1C);
    sp.sp88 = temp_f2;
    sp.sp8c = temp_f1;
    sp.sp90 = temp_f0;
    sp.sp94 = *(f32 *)(temp_16 + 0x20);
    sp.sp98 = *(f32 *)(temp_16 + 0x24);
    sp.sp9c = *(f32 *)(temp_16 + 0x28C);
    temp_f2 = *(f32 *)(temp_16 + 0x29C);
    temp_f1 = *(f32 *)(temp_16 + 0x2A0);
    temp_f0 = *(f32 *)(temp_16 + 0x2A4);
    sp.spa0 = temp_f2;
    sp.spa4 = temp_f1;
    sp.spa8 = temp_f0;
    var_5_2 = (s128 *)&sp;
    var_4 = 7;
    do {
        temp_3_2 = *var_5_2;
        var_5_2 = (s128 *)((u8 *)var_5_2 + 0x10);
        var_4 -= 1;
        *var_17 = temp_3_2;
        var_17 = (s128 *)((u8 *)var_17 + 0x10);
    } while (var_4 > 0);
}

/* measured: restore baseline optimization level after FldEventSnapshotCapture. */
/* measured: FldCameraApplyRecord, FldEvent_GetStickHeading, FldCharacterAnimSelect, FldMoveAnimPrimary, FldMoveAnimSecondary MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
/* measured: FldCameraApplyRecord compiles to object 348B against the 352B retail
   window (normalized_diff 0; pointer-typed hoist fixes final-call setup). */
// FUN_0016F750
void FldCameraApplyRecord(u8 *arg0, u8 *arg1)
{
    u8 *temp_16;
    u8 *temp_3;
    u32 temp_3_2;
    u16 temp_18;

    temp_16 = *(u8 **)(arg0 + 0x38);
    K_View_SetFov(kwlnGetCamera(), *(f32 *)(arg1 + 0x40));
    func_003e9cb0(*(void **)(kwlnGetCamera() + 4), arg1, 0);
    temp_18 = *(u16 *)(arg1 + 0x44);
    FldCameraAdvanceCurve(arg0, temp_18);
    temp_3 = *(u8 **)(arg0 + 0x38);
    *(RwV3d *)(temp_3 + 0x14) = *(RwV3d *)(arg1 + 0x48);
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x20) = *(f32 *)(arg1 + 0x54);
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x24) = *(f32 *)(arg1 + 0x58);
    *(f32 *)(temp_16 + 0x28C) = *(f32 *)(arg1 + 0x5C);
    *(RwV3d *)(temp_16 + 0x29C) = *(RwV3d *)(arg1 + 0x60);
    temp_3_2 = (u32)(*(u32 *)(*(u8 **)(arg0 + 0x38) + 8));
    switch (temp_3_2) {
    case 0:
    case 5:
    case 6:
        FldCameraSetDistance(*(u8 **)(((u8*)MT_Scene_GetFrameState()) + 4), 0.0f);
        return;
    case 2:
    {
        s32 temp_16_2_case;
        u8 *temp_16_2_arg;
        s32 temp_17_case;
        temp_16_2_case = *(s32 *)(kwlnGetCamera() + 4);
        temp_17_case = (s32)(*(u8 **)(*(u8 **)(arg0 + 0x38) + 0xC) + 0x40);
        temp_16_2_arg = (u8 *)temp_16_2_case + 0x40;
        temp_3 = kwlnGetCamera();
        K_ClumpLookAtBasis(temp_3, (void *)temp_16_2_arg,
                      (void *)temp_17_case, 0);
    }
        return;
    case 1:
    case 3:
    case 4:
    default:
        return;
    }
}

// FUN_0016F8B0
// MATCH: 1100B/1104B, 13 resolved relocations, four zero tail bytes.
f32 FldEvent_GetStickHeading(s32 arg0, s32 arg1)
{
    RwV3d normalized;
    RwV3d input;
    u8 *clear;
    s32 remaining;
    u32 offset;
    u16 buttons;
    f32 result;
    f32 comp_z;
    f32 comp_x;

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
    if (arg1 == 0) {
        offset = (u32)arg0 * 0x4A;
        input.z = (f32)(u32)D_008C025D[offset] - 128.0f;
        buttons = *(u16 *)((u8 *)D_008C024C + offset);
        if (buttons & 0x1000) {
            input.z = -128.0f;
        } else if (buttons & 0x4000) {
            input.z = 128.0f;
        }
        if ((buttons & 0xA000) && !(input.z < -48.0f) &&
            (input.z <= 48.0f)) {
            input.z = 0.0f;
        }

        input.x = (f32)(u32)D_008C025C[arg0 * 0x4A] - 128.0f;
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
        offset = (u32)arg0 * 0x4A;
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
        comp_z = normalized.z;
        comp_x = normalized.x;
        result = func_0044b920(comp_z /
                              sqrtf(comp_x * comp_x + comp_z * comp_z));
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

// FUN_0016FD00
s32 FldCharacterAnimSelect(s32 arg0)
{
    u8 *temp_2;
    u8 *temp_4;

    switch (arg0) {
    case 1:
        temp_2 = iGpffff9db0;
        if (FldRoomIsListed(*(u16 *)(temp_2 + 0), *(u16 *)(temp_2 + 4)) == 1) {
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
        temp_4 = iGpffff9db0;
        if ((*(s32 *)(temp_4 + 0) == 0x44) &&
            (*(s32 *)(temp_4 + 4) == 1)) {
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

// FUN_0016FE80
s32 FldMoveAnimPrimary(s32 arg0)
{
    s32 result;
    u8 *temp;

    switch (arg0) {
    case 1:
        temp = iGpffff9db0;
        if (FldRoomIsListed(*(u16 *)(temp + 0), *(u16 *)(temp + 4)) == 1) {
            result = 3;
            if (FldDayEventActive() == 1) {
                result = 0xA;
            } else if (datGetFlag(0xC01) != 0) {
                result--;
            }
        } else {
            temp = iGpffff9db0;
            if ((*(s32 *)(temp + 0) == 0x44) &&
                (*(s32 *)(temp + 4) == 1)) {
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

// FUN_0016FFD0
s32 FldMoveAnimSecondary(s32 arg0)
{
    s32 result;
    u8 *temp;

    switch (arg0) {
    case 1:
        temp = iGpffff9db0;
        if (FldRoomIsListed(*(u16 *)(temp + 0), *(u16 *)(temp + 4)) == 1) {
            result = 5;
            if (FldDayEventActive() == 1) {
                result = 0xB;
            } else if (datGetFlag(0xC01) != 0) {
                result--;
            }
        } else {
            temp = iGpffff9db0;
            if ((*(s32 *)(temp + 0) == 0x44) &&
                (*(s32 *)(temp + 4) == 1)) {
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

