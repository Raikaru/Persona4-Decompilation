#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "g_data_internal.h"
#include "field_frame_internal.h"
#include "field_panel_internal.h"
#include "field_npc_control_internal.h"
extern void *FldRc_ReplaceGeometryTextures(void *object, void *data);

#include "rw_types_internal.h"
typedef RwV3d RainVector;
typedef struct RwMatrixTag {
    RainVector right;
    u32 flags;
    RainVector up;
    u32 pad1;
    RainVector at;
    u32 pad2;
    RainVector pos;
    u32 pad3;
} RainMatrix;
typedef struct RainDrop {
    s32 active;
    s32 count;
    f32 x;
    f32 *motion;
} RainDrop;
typedef struct RpPTankLockStruct {
    u8 *data;
    s32 stride;
} RainLock;

typedef void *(*RainAllocate)(size_t count, size_t size, u32 hint);
struct RpAtomic;
struct RwFrame;
enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7fffffff
};
enum RpPTankLockFlags {
    rpPTANKLOCKWRITE = 0x40000000,
    rpPTANKLOCKREAD = (s32)0x80000000
};
enum RpPTankSkyRenderState {
    rpPTANKSKYRENDERSTATENARENDERSTATE = 0,
    rpPTANKSKYRENDERSTATEALPHA,
    rpPTANKSKYRENDERSTATEATEST,
    rpPTANKSKYRENDERSATEFORCEENUMSIZEINT = 0x7fffffff
};

typedef struct RwTexture RwTexture;
typedef struct RwTexDictionary RwTexDictionary;
#include "scene_event_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
static inline s32 code1_0018_shift4(s32 value)
{
    return value << 4;
}
static inline s32 code1_0018_add2(s32 first, s32 second)
{
    return first + second;
}
extern void mdlEffectEmitTagPair();
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void mdlEffectEmitMaskedTagPair(void);
extern void FldNoiseEmitTagged(void);
extern void func_003a2760(s32 arg0);
extern void func_003e9390(s32 arg0);
struct RpGeometry;
typedef struct RpMaterial *(*MaterialCallback)(struct RpMaterial *, void *);
extern struct RpGeometry *func_003c21e0(struct RpGeometry *geometry, MaterialCallback callback, void *data);
extern void mdlDestroyModelObject(s32 arg0);
extern void func_003f3eb0(s32 arg0, s32 arg1);
extern void FldNoiseEmitPlain();
extern s32 FldFogUpdate(u8 *task);

extern void (*jtbl_008873EC[])(void *);

extern u8 D_00756510[];
extern s32 D_0076428C;
extern s32 iGpffffb27c;
extern u64 iGpffffb8c8;
extern s32 iGpffffb278;
extern s32 scrGetWorkCount(void);
extern s32 iGpffffb268;
extern s32 iGpffffb250;
extern s16 iGpffffb390;
extern s16 iGpffffb394;
extern s16 iGpffffb398;
extern s16 iGpffffb39c;
extern s16 iGpffffb3a0;
extern s32 iGpffffb3a4;
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *handle);
extern const KWindowEntryDescriptor D_005F5830[];
extern const KWindowEntryDescriptor D_005F5730[];
extern u8 D_007E3720[];
extern u8 D_007966D0[];
extern s64 iGpffff9fd0;
extern s32 iGpffffb240;
extern void FldBoardGenerate(s32 mode, s32 value, s32 arg2);
extern void FldSmapTileQueueByType(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3,
                           f32 arg5, f32 arg6, f32 arg7, s32 arg4);
extern void FldRc_QueueScreenQuad(u8 *arg0, u8 *arg1,
                          f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                          f32 fparg4, u8 *arg2, s32 arg3,
                          f32 fparg5, f32 fparg6, f32 fparg7, s32 arg4,
                          f32 arg_sp0);
extern void FldSmapTileQueueQuad(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                          s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern u16 D_008C024E[];
extern s32 scrStartProcedureChecked(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 kwlnTaskIsLinked(s32 arg0);

void K_Test_Create(s32 arg0);

extern void func_003e0f40(s32 arg0);
extern s32 K_Clump_MatUsrDataHasData(u8 *arg0, u8 *arg1);
extern struct RpMaterial *func_003c42b0(struct RpMaterial *material, RwTexture *texture);
extern u8 D_005F5438[];
extern s32 *MT_Scene_GetFrameState(void);
extern void FldRc_SetPositionSlotLock(s32 a, s32 b, s32 c);
extern RwTexDictionary *func_003ef6d0(void);
extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
extern void RpSkyTextureSetMipmapK(s32 a, f32 fp);
extern u8 D_005F5360[];
extern u8 iGpffffb310;
extern void memset(void *dst, s32 value, s32 size);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F5340[];
extern u8 D_005F5350[];
extern u8 D_005F5320[];
extern u8 D_005F5330[];
extern s32 kwlnGetCamera(void);
extern f32 fGpffff8218;
extern s16 mdlGetLayerAnimation(s32 arg0, s32 arg1);
extern u8 *mdlGetMatrix(u32 arg0);
extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
extern u8 *K_ClumpLookAtBasis(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern s32 FldNpcControlUpdate(u8 *task);
extern s32 FldStepNotAtBoundary(void);
extern f32 sinf(f32 arg0);

extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern s32 frFontExDrawTextDeferredWithCharWidth(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id,
                         const char *str, s32 flags, s32 unused, void *param,
                         s32 charWidth);
extern f32 D_008872F8[];
extern f32 D_00761184;
extern u8 D_00794C60[];
extern u32 D_007EFA00[];
extern u8 D_005F54D8[];
extern s32 FldPanel2dUpdate(u8 *arg0);
extern void FldPanel2dSelectEntry(s32 arg0);
extern u8 D_005F54E8[];
extern s32 FldSupporterUpdate(u8 *arg0);
extern u8 D_005F1D80[];
extern u8 D_005F1D90[];
extern s32 iGpffff9f60;
extern s32 FldRainUpdate(u8 *task);

extern s32 FldNoiseUpdate(u8 *task);
extern void FldNoiseDestroy(u8 *arg0);
extern s32 FldMapTestUpdate(u8 *arg0);
extern void FldMapTestDestroy(u8 *arg0);
extern u8 D_005F1DF8[];
extern u8 D_005F1E08[];
extern u8 D_005F57B0[];
extern u8 D_005F57C0[];
extern s32 func_003bfae0();
extern s32 kwlnGetCamera(void);
extern s32 RwCameraFrustumTestSphere(u8 *arg0, s32 arg1);
extern void func_003f68a0(s32 arg0, s32 arg1);
extern u8 D_007E8C00[];
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 arg0, u32 arg1);
extern s32 clndIsDateInRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 FldStepIndex(void);
extern void sdkSndStopChannel(s32 arg0);
extern void sdkSndPlayCue(s16 arg0, s32 arg1);
extern s32 iGpffffb264;
extern u8 *iGpffff9db0;
extern s32 iGpffffb884;

/* measured: loop-invariant hoisting keeps the retail stride/base preheader for
   the 0x750 slot scan. */
#pragma opt_loop_invariants on
/* measured: close loop-invariant hoisting around the slot scan. */
#pragma opt_loop_invariants off
typedef struct {
    f32 x, y, z;
} FldAreaNormal;
/* Plays the ambient cue for slot `id` and advances that slot's four-step
   variation counter.  Inlined into every trigger arm of FldAmbientTrigger. */
static inline void func_001823d0_play(u16 id, s16 bank, s32 base)
{
    extern s32 sdkSndStartStream(s16 index, s16 stream, s16 arg2, s16 arg3);
    extern s32 D_007F1760[];
    s32 *slot = &D_007F1760[id & 0x3FF];

    sdkSndStartStream(0, (id & 0x3FF) + 4, bank, base + *slot);
    if (++*slot >= 4) {
        *slot = 0;
    }
}
/* measured probe: opt_propagation off tests caching the repeated render callback base. */
#pragma opt_propagation off
/* measured probe: restore opt_propagation after FldRainRenderStateSet. */
#pragma opt_propagation on

/* measured: propagation off preserves the cached jtbl_008873EC base for
   the post-loop callback sequence. */
/* measured: closing the single-function callback-base bracket. */
#pragma opt_propagation on
 

/* measured probe: O1 test for target byte-copy register allocation. */
#pragma optimization_level 1
/* measured probe: restore optimization level after target O1 test. */
#pragma optimization_level 2
/* measured: VU0 MMI builtins and O1 reproduce the target's pcpyld/sq packet. */
#pragma enable_vu0_registers on
/* measured: bind MMI packet registers as in retail. */
#pragma vu0_mmi_reg_binding on
/* measured: O1 preserves the target's packet construction order. */
#pragma optimization_level 1
/* measured: restore the file's O2 baseline after the target. */
#pragma optimization_level 2
/* measured: stop binding MMI packet registers after the target. */
#pragma vu0_mmi_reg_binding off
/* measured: stop VU0 register mode after the target. */
#pragma enable_vu0_registers off

#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
#pragma optimization_level 1
/* measured: closes the cluster pcpyld pragma scope and restores the file's -O2
   baseline. */
#pragma optimization_level 2
#pragma vu0_mmi_reg_binding off
#pragma enable_vu0_registers off

/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on

/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: retail hoists the D_00887300 base across nine indirect calls;
   opt_propagation off preserves the saved-register address materialization. */
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on

/* Sky2's complete 0x40-byte vertex record, with its native quadword
 * alignment. Fields follow rw/sky2/rwplcore.h; unused components stay intact. */
typedef struct {
    f32 x, y, z, cameraZ;
    f32 u, v, reciprocalZ, reservedFog;
    f32 red, green, blue, alpha;
    f32 normalX, normalY, normalZ, reservedAlignment;
} GridDrawVertex __attribute__((aligned(16)));

typedef struct {
    s32 state;
    s32 blocked;
    s32 phases[7][10];
    GridDrawVertex grid[7][10][4];
    GridDrawVertex bands[14][1][4];
    GridDrawVertex overlay[4];
    f32 uvValues[8];
    GridDrawVertex cover[4];
    GridDrawVertex rings[3][66];
    RwTexture *textures[2];
    u8 *raster;
} GridDrawWork;

/* measured: retail hoists the D_00887300 base across seven indirect calls;
   opt_propagation off preserves the saved-register address materialization. */
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
#pragma opt_loop_invariants off

/* measured: the inner mode/index selection assigns a scratch `p` and `base = p`
   follows the if/else: that copy keeps the join block alive so the two inner
   exits branch to it (retail's b -> b trampoline) instead of folding to the
   work setup. `slot` is a named local recomputed per store so the addu keeps
   index-first operand order and retail's repeated load. */
static inline s32 fldBothReady_0018a200(void)
{
    extern int D_007EF9F8[];
    extern int D_007EFA04[];

    return D_007EF9F8[0] != 0 && D_007EFA04[0] != 0;
}

/* measured 2026-10-12: fnalign 277 -> 0. Per-phase object/work snapshots and
 * vector lifetimes preserve retail's frame and register allocation. CSE shares
 * constants; disabling constant pullout avoids cross-phase hoists. */
#pragma push
#pragma opt_lifetimes on
#pragma opt_common_subs on
#pragma opt_pulloutconstants off
#pragma opt_propagation off
extern float D_00756520[];
extern float D_00756524[];
extern float D_00756528[];
extern int D_007EF9F8[];
extern unsigned int D_007EFA00[];
extern int D_007EFA04[];
extern float fGpffff8300; /* 0xffff8300 */
extern float fGpffff8420; /* 0xffff8420 */

extern u8 *MT_Scene_GetResListHead(s32);
extern u32 K_FldEvent_IsPosWithinFov(const RainMatrix *, const RainVector *, f32);
extern u32 K_FldEvent_ArePosWithinDist(const RainVector *, const RainVector *, f32);
extern u8 *cmmKindRecord(s32);
extern u32 RpRandom(void);
struct RpSpline;
extern struct RpSpline *func_003bbbe0(s32 count, s32 type, RainVector *points);
extern unsigned int func_003e0f80(void);
extern int func_003e9700(unsigned int);
extern f32 func_0044b920(f32);
extern s32 func_00102980(void);
extern f32 KDraw_MatrixYawDeg(void *);
extern f32 KDraw_MatrixPitchDeg(void *);
extern f32 KDraw_MatrixRollDeg(void *);
extern s32 KMisc_CreateRmdFade(s32, s32, s32, s32, s32);
extern s32 KDraw_IsEffectDone(unsigned char *);
extern u32 FldEvent_HasLineOfSight(void *, void *, f32, f32);
extern s32 FldRc_FileLoadIsReady(unsigned char *);
extern s32 FldRc_RequestPositionSlot(unsigned char *, float *);
extern void FldRc_SetPositionSlotPriority(unsigned char *, s32, s16);
extern void FldRc_SetPositionSlotVisibility(unsigned char *, s32, s32);
extern void FldFrameTask_GetPosition(unsigned char *, unsigned char *);
extern void FldFrameTask_SetOrientation(unsigned char *, unsigned char *);
extern void FldFrameTask_SetPosition(unsigned char *, unsigned char *);
extern void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle);
extern void FldNpcSetPositionLock(unsigned char *, s32);
extern s32 func_0018bf50(unsigned char *);
extern s64 cmmResolveCounterpart(s64);
extern float func_003e4180(float *);
extern s32 kwlnGetCamera(void);
extern void FldRc_SetClumpVector(void *, void *);
extern s32 mdlPrepareModel(unsigned char *);
extern void mdlAdvanceModelFromFlags(unsigned char *);
extern s16 mdlGetLayerAnimation(s32, s32);
extern s32 mdlComputeIndexedAttachMatrix(void *, s32, void *);
extern void mdlSetAlphaBlend(unsigned char *);
extern void mdlClearAlphaBlend(unsigned char *);
extern void mdlSetLookAtTargetPoint(void *, void *);
extern void mdlSetLookAtRequested(unsigned char *);
extern void mdlSetLookStateWord(unsigned char *, u16);
extern u16 mdlGetLookStateWord(unsigned char *);

extern unsigned char D_00763074[4];
extern int func_003bb3a0();
extern void func_003e0870(void *matrix, const void *axis, s32 mode, f32 angle);
extern int func_003e05d0();
extern int func_0047a2f0();
extern int func_0047a220();
extern void func_003bb5b0(void *curve, s32 mode, f32 time, f32 *dst, void *aux);
extern void mdlScale(void *model, const void *scale, s32 combineOp);
extern int func_0047a310();
typedef struct {
    u16 id;
    u8 unk002[0x162];
    u8 *model;
    u8 unk168[0xb8];
    u16 pathMode;
    u8 unk222[6];
    u8 *movementTask;
    u8 unk22c[8];
    s32 kind;
    u8 unk238[8];
    RainMatrix initialMatrix;
    u8 *kind1Data;
    u8 *kind2Data;
    u8 unk288[12];
    u8 *otherTask;
    u16 pointCount;
    u16 unk29a;
    RainVector points[16];
    f32 speed;
    u32 curve;
} FldActorObject;

typedef struct {
    u8 unk00[0x18];
    f32 progress;
    f32 step;
    f32 direction;
} FldActorWork;

s32 FldRcAtomicFrustumTest(s32 arg0, s32 *arg1);

/* Update field-actor visibility, animation, spline travel, and facing. */
// Kept in bucket: diff 35 when moved; cause not diagnosed (uses static inline fldBothReady_0018a200).
// FUN_0018A200
s32 FldNpcControlUpdate(u8 *param_1)
{
  typedef struct { float x, y, z; } FldCopyVec;
  s32 actorIndex;
  s32 objectKind;
  s32 splineMode;
  s32 closedLoopType;
  FldActorObject *transformObject;
  FldActorObject *initialPathObject;
  FldActorObject *movingObject;
  s32 updateAnimationKind;
  FldActorObject *initialAnimationObject;
  s32 initialAnimationId;
  unsigned int temp_v0;
  s32 temp_v1;
  unsigned short temp_v2;
  short temp_v3;
  u32 movementMode;
  s32 savedAnimation;
  u32 resourceKey;
  s32 eventResource;
  unsigned int resourceId;
  int temp_v4;
  u8 *effectTask;
  unsigned int temp_v5;
  u32 pauseRoll;
  unsigned int *puVar8;
  unsigned int temp_v6;
  int temp_v7;
  void *pvVar11;
  float *pfVar12;
  RainVector *facingNormal;
  RainVector *targetDirection;
  RainVector *lookTarget;
  RainVector *initialPathDirection;
  RainVector *pathDirection;
  RainVector *oscillatorDirection;
  RainVector *turnForward;
  RainVector *turnRight;
  u8 *finalModel;
  unsigned int temp_v8;
  u32 temp_v9;
  u32 fovResult;
  u32 distanceResult;
  long long temp_v10;
  unsigned int *puVar16;
  s32 actorOffset;
  unsigned int temp_v11_s3;
  float temp_v12;
  float temp_v13;
  f32 facingLimit;
  f32 proximityLimit;
  f32 interactionAngle;
  f32 interactionRange;
  f32 oscillatorHeading;
  f32 pathHeading;
  f32 initialHeading;
  f32 initialZero;
  f32 initialX;
  float one;
  float diff;
  float ny;
  float nx;
  float nz;
  f32 sideZ;
  f32 sideX;
  f32 sideY;
  f32 sideZero;
  f32 sideDot;
  unsigned int *puVar1;

  int iStack_4;
  float vec10[3];
  float vec20[3];
  float vec30[3];
  float vec40[3];
  float vec50[3];
  float vec60[3];
  float vec70[3];
  SVec3 transformAngles;
  float vec90[3];
  float vecA0[3];
  float vecB0[3];
  float vecC0[3];
  float vecD0[3];
  float vecE0[3];
  float vecF0[3];
  float vec100[3];
  float vec110[3];
  float vec120[3];
  float vec130[3];
  float vec140[3];
  float vec150[3];
  float vec160[3];  
  puVar1 = *(unsigned int **)(param_1 + 0x38);
  if (puVar1[2] == 1) {
    return 0;
  }
  if (*puVar1 >= 4) {
    if (*(int *)(puVar1[3] + 0x234) == 2) {
      iStack_4 = 0;
      temp_v8 = func_0047a310(*(unsigned int *)(puVar1[3] + 0x164));
      RpClumpForAllAtomics((void *)temp_v8, (KClumpCallback)FldRcAtomicFrustumTest, &iStack_4);
      temp_v4 = (s32)MT_Scene_GetFrameState();
      if (*(int *)(temp_v4 + puVar1[0x14] * 4 + 0x34) != 0) {
        s32 actorVisible;
        u8 *visibilityTarget;
        actorVisible = (iStack_4 != 0) ^ 1;
        temp_v4 = (s32)MT_Scene_GetFrameState();
        visibilityTarget = *(u8 **)(temp_v4 + puVar1[0x14] * 4 + 0x34);
        FldRc_SetPositionSlotVisibility(visibilityTarget,puVar1[0x15],actorVisible);
      }
      if ((*(unsigned int *)(puVar1[3] + 0x28) & 2) == 0) {
        FldNpcSetPositionLock(param_1,1);
      }
    }
    temp_v4 = *(int *)(puVar1[3] + 0x164);
    resourceId = *(unsigned short *)(temp_v4 + 0xd4);
    if ((((((resourceId != 5) || (*(unsigned short *)(temp_v4 + 0xd6) != 0x45ed)) &&
          ((resourceId != 5 || (*(unsigned short *)(temp_v4 + 0xd6) != 0x461f)))) &&
         ((resourceId != 5 || (*(unsigned short *)(temp_v4 + 0xd6) != 0x4651)))) &&
        ((resourceId != 5 || (*(unsigned short *)(temp_v4 + 0xd6) != 0x46b5)))) &&
       (((resourceId != 5 || (*(unsigned short *)(temp_v4 + 0xd6) != 0x46e7)) &&
        (fldBothReady_0018a200())))) {
      temp_v8 = func_0047a2f0(D_007EFA00[0]);
      temp_v4 = func_0047a2f0(temp_v4);
      facingLimit = 120.0f;
      fovResult = K_FldEvent_IsPosWithinFov((RainMatrix *)temp_v8, &((RainMatrix *)temp_v4)->pos, facingLimit);
      if (fovResult == 1) {
        temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        temp_v13 = *(float *)(temp_v4 + 0x30);
        temp_v4 = func_0047a2f0(D_007EFA00[0]);
        vec10[0] = temp_v13 - *(float *)(temp_v4 + 0x30);
        temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        temp_v13 = *(float *)(temp_v4 + 0x34);
        temp_v4 = func_0047a2f0(D_007EFA00[0]);
        vec10[1] = temp_v13 - *(float *)(temp_v4 + 0x34);
        temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        temp_v13 = *(float *)(temp_v4 + 0x38);
        temp_v4 = func_0047a2f0(D_007EFA00[0]);
        vec10[2] = temp_v13 - *(float *)(temp_v4 + 0x38);
        temp_v13 = func_003e4180(&vec10[0]);
        if (temp_v13 < 150.0f) {
          temp_v1 = 1;
          temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          *(FldCopyVec *)vec20 = *(FldCopyVec *)(temp_v4 + 0x20);
          temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          temp_v13 = *(float *)(temp_v4 + 0x30);
          temp_v4 = func_0047a2f0(D_007EFA00[0]);
          vec30[0] = *(float *)(temp_v4 + 0x30) - temp_v13;
          temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          temp_v13 = *(float *)(temp_v4 + 0x34);
          temp_v4 = func_0047a2f0(D_007EFA00[0]);
          vec30[1] = *(float *)(temp_v4 + 0x34) - temp_v13;
          temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          temp_v13 = *(float *)(temp_v4 + 0x38);
          temp_v4 = func_0047a2f0(D_007EFA00[0]);
          vec30[2] = *(float *)(temp_v4 + 0x38) - temp_v13;
          facingNormal = (RainVector *)vec20;
          RwV3dNormalize(facingNormal, facingNormal);
          targetDirection = (RainVector *)vec30;
          RwV3dNormalize(targetDirection, targetDirection);
          if ((vec20[0] * vec30[0] + vec20[1] * vec30[1] + vec20[2] * vec30[2] <= 0.0f) &&
             (*(unsigned short *)(puVar1[3] + 0x220) > 0)) {
            temp_v1 = 0;
          }
          temp_v4 = func_0018bf50(*(unsigned char **)(puVar1[3] + 0x294));
          if ((temp_v4 == 0) && (temp_v1 == 1)) {
            temp_v4 = func_0047a2f0(D_007EFA00[0]);
            lookTarget = (RainVector *)vec40;
            *(FldCopyVec *)vec40 = *(FldCopyVec *)(temp_v4 + 0x30);
            vec40[1] = vec40[1] + 140.0f;
            mdlSetLookAtTargetPoint(*(void **)(puVar1[3] + 0x164), lookTarget);
            temp_v2 = mdlGetLookStateWord(*(unsigned char **)(puVar1[3] + 0x164));
            temp_v2 |= 0x1000;
            mdlSetLookStateWord(*(unsigned char **)(puVar1[3] + 0x164), temp_v2);
          }
          else {
            mdlSetLookAtRequested(*(unsigned char **)(puVar1[3] + 0x164));
          }
        }
        else {
          mdlSetLookAtRequested(*(unsigned char **)(puVar1[3] + 0x164));
        }
      }
      else {
        mdlSetLookAtRequested(*(unsigned char **)(puVar1[3] + 0x164));
      }
    }
    temp_v4 = kwlnGetCamera();
    temp_v6 = *(unsigned int *)(temp_v4 + 4);
    FldFrameTask_GetPosition((unsigned char *)&vec160[0],*(unsigned char **)(puVar1[3] + 0x228));
    *(FldCopyVec *)vec50 = *(FldCopyVec *)vec160;
    vec50[1] = vec50[1] + 180.0f;
    temp_v4 = func_003e9700(temp_v6);
    *(FldCopyVec *)vec70 = *(FldCopyVec *)(temp_v4 + 0x30);
    vec60[0] = vec50[0] - vec70[0];
    vec60[1] = vec50[1] - vec70[1];
    vec60[2] = vec50[2] - vec70[2];
    temp_v13 = func_003e4180(&vec60[0]);
    effectTask = (u8 *)puVar1[4];
    if (effectTask != NULL && KDraw_IsEffectDone(effectTask) == 1) {
      mdlClearAlphaBlend(*(unsigned char **)(puVar1[3] + 0x164));
      kwlnTaskDestroyWithHierarchy((void *)puVar1[4]);
      puVar1[4] = 0;
    }
    if (temp_v13 <= ((float*)puVar1)[0x12] + 55.0f) {
      if (puVar1[4] != 0) {
        mdlClearAlphaBlend(*(unsigned char **)(puVar1[3] + 0x164));
        kwlnTaskDestroyWithHierarchy((void *)puVar1[4]);
        puVar1[4] = 0;
      }
      func_0047a220(*(unsigned int *)(puVar1[3] + 0x164),D_00763074);
      puVar1[0x13] = 1;
    }
    if ((puVar1[0x13] == 1) && (!(temp_v13 <= *(f32 *)((u32)puVar1 + 0x48) + 55.0f))) {
      mdlSetAlphaBlend(*(unsigned char **)(puVar1[3] + 0x164));
      temp_v5 = KMisc_CreateRmdFade((int)param_1,*(int *)(puVar1[3] + 0x164),0,0xff,10);
      puVar1[4] = temp_v5;
      puVar1[0x13] = 0;
    }
  }
  switch(*puVar1) {
  case 0:
    temp_v4 = mdlPrepareModel(*(unsigned char **)(puVar1[3] + 0x164));
    if (temp_v4 != 0) {
      temp_v5 = puVar1[3];
      if (*(int *)(temp_v5 + 0x234) != 3) {
        puVar8 = (unsigned int *)func_0047a2f0(*(unsigned int *)(temp_v5 + 0x164));
        puVar16 = (unsigned int *)(temp_v5 + 0x240);
        temp_v4 = 8;
        do {
          temp_v6 = *puVar16;
          temp_v0 = puVar16[1];
          puVar16 = puVar16 + 2;
          temp_v4 = temp_v4 - 1;
          *puVar8 = temp_v6;
          puVar8[1] = temp_v0;
          puVar8 = puVar8 + 2;
        } while (0 < temp_v4);
        mdlAdvanceModelFromFlags(*(unsigned char **)(puVar1[3] + 0x164));
        transformAngles.x = KDraw_MatrixPitchDeg((void *)(puVar1[3] + 0x240));
        transformAngles.y = KDraw_MatrixYawDeg((void *)(puVar1[3] + 0x240));
        transformAngles.z = KDraw_MatrixRollDeg((void *)(puVar1[3] + 0x240));
        transformObject = (FldActorObject *)puVar1[3];
        MT_Scene_SetResPlacement(transformObject->id, (u8 *)&transformObject->initialMatrix.pos, (u8 *)&transformAngles);
        temp_v8 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        func_003e05d0(temp_v8);
        func_0047a220(*(unsigned int *)(puVar1[3] + 0x164),D_00763074);
        temp_v4 = (s32)MT_Scene_GetResListHead(5);
        initialX = *(float *)(temp_v4 + 0x1f0);
        initialZero = 0.0f;
        if (((initialZero != initialX) || (initialZero != *(float *)(temp_v4 + 0x1f8))) ||
           (initialZero != *(float *)(temp_v4 + 500))) {
          pvVar11 = (void *)func_0047a310(*(unsigned int *)(puVar1[3] + 0x164));
          FldRc_SetClumpVector(pvVar11,(u8 *)temp_v4 + 0x1f0);
        }
      }
      temp_v5 = func_003e0f80();
      puVar1[5] = temp_v5;
      *puVar1 = *puVar1 + 1;
    }
    break;
  case 1:
    temp_v4 = func_00102980();
    if (temp_v4 == 9) {
      temp_v4 = (s32)MT_Scene_GetFrameState();
      if (*(int *)(temp_v4 + 0x34) == 0) {
        break;
      }
      temp_v4 = (s32)MT_Scene_GetFrameState();
      temp_v4 = FldRc_FileLoadIsReady(*(unsigned char **)(temp_v4 + 0x34));
      if (temp_v4 == 0) {
        break;
      }
      temp_v4 = (s32)MT_Scene_GetFrameState();
      if (*(int *)(temp_v4 + 0x38) == 0) {
        break;
      }
      temp_v4 = (s32)MT_Scene_GetFrameState();
      temp_v4 = FldRc_FileLoadIsReady(*(unsigned char **)(temp_v4 + 0x38));
      if (temp_v4 == 0) {
        break;
      }
      temp_v4 = (s32)MT_Scene_GetFrameState();
      if (*(int *)(temp_v4 + 0x3c) == 0) {
        break;
      }
      temp_v4 = (s32)MT_Scene_GetFrameState();
      temp_v4 = FldRc_FileLoadIsReady(*(unsigned char **)(temp_v4 + 0x3c));
      if (temp_v4 == 0) {
        break;
      }
    }
    temp_v5 = puVar1[3];
    objectKind = ((FldActorObject *)temp_v5)->kind;
    if (objectKind == 1) {
      temp_v13 = *(float *)(*(int *)(temp_v5 + 0x280) + 0x14);
      if (temp_v13 != 0.0f) {
        vec90[0] = vec90[1] = vec90[2] = temp_v13;
        mdlScale(*(void **)(temp_v5 + 0x164), vec90, 1);
      }
      initialAnimationObject = (FldActorObject *)puVar1[3];
      initialAnimationId = *(s16 *)(initialAnimationObject->kind1Data + 6);
      mdlDispatchAnimIfPresent(initialAnimationObject->model, 0, initialAnimationId, 0, 1);
    }
    else if (objectKind == 2) {
      temp_v5 = *(unsigned int *)(*(int *)(temp_v5 + 0x284) + 0x78);
      if (temp_v5 != 0) {
        actorIndex = 1;
        temp_v3 = (short)temp_v5;
        resourceKey = (u16)temp_v3;
        temp_v4 = (s32)cmmKindRecord(resourceKey);
        if ((*(unsigned int *)(temp_v4 + 4) & 1) != 0) {
          temp_v10 = cmmResolveCounterpart((s16)resourceKey);
          temp_v3 = (short)temp_v10;
        }
        eventResource = temp_v3;
        temp_v9 = datGetFlag(eventResource + 0x43f);
        if (temp_v9 != 0) {
          actorIndex = 2;
        } else {
          temp_v9 = datGetFlag(eventResource + 0x45f);
          if (temp_v9 != 0) {
            actorIndex = 0;
          }
        }
        temp_v4 = mdlComputeIndexedAttachMatrix(*(void **)(puVar1[3] + 0x164),2,&vecA0[0]);
        if (temp_v4 == 0) {
          temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          *(FldCopyVec *)vecA0 = *(FldCopyVec *)(temp_v4 + 0x30);
          vecA0[1] = vecA0[1] + 175.0f;
        }
        actorOffset = actorIndex * 4;
        temp_v4 = (s32)MT_Scene_GetFrameState();
        temp_v5 = FldRc_RequestPositionSlot(*(unsigned char **)(temp_v4 + actorOffset + 0x34),&vecA0[0]);
        temp_v4 = (s32)MT_Scene_GetFrameState();
        FldRc_SetPositionSlotPriority(*(unsigned char **)(temp_v4 + actorOffset + 0x34),temp_v5,4);
        puVar1[0x14] = actorIndex;
        puVar1[0x15] = temp_v5;
      }
      initialAnimationObject = (FldActorObject *)puVar1[3];
      initialAnimationId = *(s16 *)(initialAnimationObject->kind2Data + 0x6c);
      mdlDispatchAnimIfPresent(initialAnimationObject->model, 0, initialAnimationId, 0, 1);
    }
    initialPathObject = (FldActorObject *)puVar1[3];
    if (initialPathObject->pointCount < 4) {
      initialPathObject->pathMode = 0;
    }
    initialPathObject = (FldActorObject *)puVar1[3];
    splineMode = initialPathObject->pathMode;
    if (splineMode > 0) {
      closedLoopType = 2;
      if (splineMode == closedLoopType) {
        temp_v6 = (u32)func_003bbbe0(initialPathObject->pointCount,closedLoopType,initialPathObject->points);
        *(unsigned int *)(puVar1[3] + 0x360) = temp_v6;
      } else {
        temp_v6 = (u32)func_003bbbe0(initialPathObject->pointCount,1,initialPathObject->points);
        *(unsigned int *)(puVar1[3] + 0x360) = temp_v6;
      }
      puVar1[6] = 0;
      puVar1[8] = 0x3f800000;
      func_003bb3a0(*(unsigned int *)(puVar1[3] + 0x360),0,&vecC0[0]);
      func_003bb3a0(*(unsigned int *)(puVar1[3] + 0x360),1,&vecD0[0]);
      vecB0[0] = vecD0[0] - vecC0[0];
      vecB0[1] = vecD0[1] - vecC0[1];
      vecB0[2] = vecD0[2] - vecC0[2];
      temp_v13 = func_003e4180(&vecB0[0]);
      initialPathObject = (FldActorObject *)puVar1[3];
      temp_v13 = (1.0f / (initialPathObject->pointCount - 1)) *
               (initialPathObject->speed / temp_v13);
      ((float*)puVar1)[7] = temp_v13;
      ((float*)puVar1)[6] = (((float*)puVar1)[6] + temp_v13);
      mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,1,4,1);
      func_003bb5b0((void *)(u32)*(u32 *)(puVar1[3] + 0x360), 10, *(f32 *)((u32)puVar1 + 0x18), &vecD0[0], 0);
      temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
      *(FldCopyVec *)vecC0 = *(FldCopyVec *)(temp_v4 + 0x30);
      vecB0[0] = vecD0[0] - vecC0[0];
      vecB0[1] = vecD0[1] - vecC0[1];
      vecB0[2] = vecD0[2] - vecC0[2];
      initialPathDirection = (RainVector *)vecB0;
      RwV3dNormalize(initialPathDirection, initialPathDirection);
      temp_v13 = (float)func_0044b920(vecB0[0] * D_00756520[0] + vecB0[1] * D_00756524[0] + vecB0[2] * D_00756528[0]);
      initialHeading = fGpffff8300 * temp_v13;
      if (vecB0[0] < 0.0f) {
        initialHeading = initialHeading * -1.0f;
      }
      ((RainMatrix *)puVar1[5])->right.x =
          ((RainMatrix *)puVar1[5])->up.y =
          ((RainMatrix *)puVar1[5])->at.z = 1.0f;
      ((RainMatrix *)puVar1[5])->up.x = 0.0f;
      ((RainMatrix *)puVar1[5])->right.z = 0.0f;
      ((RainMatrix *)puVar1[5])->right.y = 0.0f;
      ((RainMatrix *)puVar1[5])->at.y = 0.0f;
      ((RainMatrix *)puVar1[5])->at.x = 0.0f;
      ((RainMatrix *)puVar1[5])->up.z = 0.0f;
      ((RainMatrix *)puVar1[5])->pos.z = 0.0f;
      ((RainMatrix *)puVar1[5])->pos.y = 0.0f;
      ((RainMatrix *)puVar1[5])->pos.x = 0.0f;
      ((RainMatrix *)puVar1[5])->flags |= 0x20003;
      func_003e0870((void *)(u32)puVar1[5], D_00756510, 2, initialHeading);
      FldFrameTask_SetOrientation(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)puVar1[5]);
    }
    puVar1[0xb] = 0xffffffff;
    *puVar1 = *puVar1 + 1;
    break;
  case 2:
    *(unsigned int *)(puVar1[3] + 0x28) = *(unsigned int *)(puVar1[3] + 0x28) | 0x10000000;
    mdlSetAlphaBlend(*(unsigned char **)(puVar1[3] + 0x164));
    temp_v5 = KMisc_CreateRmdFade((int)param_1,*(int *)(puVar1[3] + 0x164),0,0xff,8);
    puVar1[4] = temp_v5;
    *puVar1 = *puVar1 + 1;
    break;
  case 3:
    temp_v4 = KDraw_IsEffectDone((unsigned char *)puVar1[4]);
    if (temp_v4 != 0) {
      mdlClearAlphaBlend(*(unsigned char **)(puVar1[3] + 0x164));
      kwlnTaskDestroyWithHierarchy((void *)puVar1[4]);
      puVar1[4] = 0;
      *(unsigned int *)(puVar1[3] + 0x28) = *(unsigned int *)(puVar1[3] + 0x28) | 0x10000000;
      *puVar1 = *puVar1 + 1;
    }
    break;
  case 4:
    if (fldBothReady_0018a200()) {
      temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
      temp_v7 = func_0047a2f0(D_007EFA00[0]);
      proximityLimit = 500.0f;
      distanceResult = K_FldEvent_ArePosWithinDist((RainVector *)(temp_v4 + 0x30), (RainVector *)(temp_v7 + 0x30), proximityLimit);
      if (distanceResult == 1) {
        pvVar11 = (void *)func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        temp_v4 = func_0047a2f0(D_007EFA00[0]);
        interactionAngle = 90.0f;
        interactionRange = 250.0f;
        temp_v5 = FldEvent_HasLineOfSight(pvVar11,&((RainMatrix *)temp_v4)->pos,interactionAngle,interactionRange);
        if (temp_v5 != 0) {
          if (puVar1[0xb] != 0xffffffff) {
            break;
          }
          temp_v3 = mdlGetLayerAnimation(*(int *)(puVar1[3] + 0x164), 0);
          puVar1[0xb] = (int)temp_v3;
          temp_v5 = puVar1[3];
          updateAnimationKind = ((FldActorObject *)temp_v5)->kind;
          if (updateAnimationKind == 1) {
            mdlDispatchAnimIfPresent(*(unsigned char **)(temp_v5 + 0x164),0,(int)*(short *)(*(int *)(temp_v5 + 0x280) + 6),4
                          ,1);
            break;
          }
          if (updateAnimationKind != 2) {
            break;
          }
          mdlDispatchAnimIfPresent(*(unsigned char **)(temp_v5 + 0x164),0,(int)*(short *)(*(int *)(temp_v5 + 0x284) + 0x6c),
                        4,1);
          break;
        }
      }
      savedAnimation = puVar1[0xb];
      if (savedAnimation >= 0) {
        mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,(s16)savedAnimation,4,1);
        puVar1[0xb] = 0xffffffff;
      }
      temp_v5 = puVar1[3];
      movementMode = *(u16 *)(temp_v5 + 0x220);
      switch (movementMode) {
      case 0:
        break;
      case 1:
      case 2:
      case 4:
      {
        FldActorWork *pathWork;
        if (((movementMode != 4) || ((float *)puVar1)[6] != 1.0f) &&
            (temp_v3 = mdlGetLayerAnimation(*(int *)(temp_v5 + 0x164), 0), temp_v3 != 1)) {
          mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,1,4,1);
        }
        func_003bb5b0((void *)(u32)*(u32 *)(puVar1[3] + 0x360), 10, ((f32 *)puVar1)[6], &vecF0[0], 0);
        temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        *(FldCopyVec *)vecE0 = *(FldCopyVec *)(temp_v4 + 0x30);
        vec100[0] = vecF0[0] - vecE0[0];
        vec100[1] = vecF0[1] - vecE0[1];
        vec100[2] = vecF0[2] - vecE0[2];
        pathDirection = (RainVector *)vec100;
        RwV3dNormalize(pathDirection, pathDirection);
        temp_v13 = (float)func_0044b920(vec100[0] * D_00756520[0] + vec100[1] * D_00756524[0] + vec100[2] * D_00756528[0]);
        pathHeading = fGpffff8300 * temp_v13;
        if (vec100[0] < 0.0f) {
          pathHeading = pathHeading * -1.0f;
        }
        ((RainMatrix *)puVar1[5])->right.x =
            ((RainMatrix *)puVar1[5])->up.y =
            ((RainMatrix *)puVar1[5])->at.z = 1.0f;
        ((RainMatrix *)puVar1[5])->up.x = 0.0f;
        ((RainMatrix *)puVar1[5])->right.z = 0.0f;
        ((RainMatrix *)puVar1[5])->right.y = 0.0f;
        ((RainMatrix *)puVar1[5])->at.y = 0.0f;
        ((RainMatrix *)puVar1[5])->at.x = 0.0f;
        ((RainMatrix *)puVar1[5])->up.z = 0.0f;
        ((RainMatrix *)puVar1[5])->pos.z = 0.0f;
        ((RainMatrix *)puVar1[5])->pos.y = 0.0f;
        ((RainMatrix *)puVar1[5])->pos.x = 0.0f;
        ((RainMatrix *)puVar1[5])->flags |= 0x20003;
        func_003e0870((void *)(u32)puVar1[5], D_00756510, 2, pathHeading);
        pathWork = (FldActorWork *)puVar1;
        movingObject = (FldActorObject *)puVar1[3];
        if (movingObject->pathMode != 4 || pathWork->progress < 1.0f) {
          FldFrameTask_SetOrientation(movingObject->movementTask,(unsigned char *)puVar1[5]);
          FldFrameTask_SetPosition(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)&vecF0[0]);
          pathWork->progress = (pathWork->progress + pathWork->step);
        }
        if (*(unsigned short *)(puVar1[3] + 0x220) == 4) {
          if (!(pathWork->progress <= 1.0f)) {
            pathWork->progress = 1.0f;
            mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,0,4,1);
          }
        }
        else if (!(pathWork->progress <= 1.0f)) {
          pathWork->progress = 0.0f;
        }
      }
        break;
      case 3:
      {
        temp_v11_s3 = puVar1[10];
        if ((int)temp_v11_s3 >= 1) {
          puVar1[10] = temp_v11_s3 - 1;
        } else {
          if ((temp_v11_s3 == 0) && (temp_v3 = mdlGetLayerAnimation(*(int *)(temp_v5 + 0x164), 0), temp_v3 != 1)) {
            mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,1,4,1);
          }
          if ((int)puVar1[9] > 0) {
            FldFrameTask_Rotate(*(unsigned char **)(puVar1[3] + 0x228), D_00756510, 2.0f);
            puVar1[9] = puVar1[9] - 1;
          }
          else {
            func_003bb5b0((void *)(u32)*(u32 *)(puVar1[3] + 0x360), 10, *(f32 *)((u32)puVar1 + 0x18), &vec120[0], 0);
            temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
            *(FldCopyVec *)vec110 = *(FldCopyVec *)(temp_v4 + 0x30);
            vec130[0] = vec120[0] - vec110[0];
            vec130[1] = vec120[1] - vec110[1];
            vec130[2] = vec120[2] - vec110[2];
            oscillatorDirection = (RainVector *)vec130;
            RwV3dNormalize(oscillatorDirection, oscillatorDirection);
            temp_v13 = (float)func_0044b920(vec130[0] * D_00756520[0] + vec130[1] * D_00756524[0] + vec130[2] * D_00756528[0]);
            oscillatorHeading = fGpffff8300 * temp_v13;
            if (vec130[0] < 0.0f) {
              oscillatorHeading = oscillatorHeading * -1.0f;
            }
            ((RainMatrix *)puVar1[5])->right.x =
                ((RainMatrix *)puVar1[5])->up.y =
                ((RainMatrix *)puVar1[5])->at.z = 1.0f;
            ((RainMatrix *)puVar1[5])->up.x = 0.0f;
            ((RainMatrix *)puVar1[5])->right.z = 0.0f;
            ((RainMatrix *)puVar1[5])->right.y = 0.0f;
            ((RainMatrix *)puVar1[5])->at.y = 0.0f;
            ((RainMatrix *)puVar1[5])->at.x = 0.0f;
            ((RainMatrix *)puVar1[5])->up.z = 0.0f;
            ((RainMatrix *)puVar1[5])->pos.z = 0.0f;
            ((RainMatrix *)puVar1[5])->pos.y = 0.0f;
            ((RainMatrix *)puVar1[5])->pos.x = 0.0f;
            ((RainMatrix *)puVar1[5])->flags |= 0x20003;
            func_003e0870((void *)(u32)puVar1[5], D_00756510, 2, oscillatorHeading);
            FldFrameTask_SetOrientation(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)puVar1[5]);
            FldFrameTask_SetPosition(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)&vec120[0]);
            {
            FldActorWork *motionWork = (FldActorWork *)puVar1;
            f32 zero;
            f32 one;

            motionWork->progress = (motionWork->step * motionWork->direction + motionWork->progress);
            zero = 0.0f;
            if (!(motionWork->direction <= zero)) {
              f32 endProgress = motionWork->progress;
              one = 1.0f;
              if (!(endProgress <= one)) {
                motionWork->progress = (one - motionWork->step);
                motionWork->direction = -1.0f;
                puVar1[9] = 0x5a;
                pauseRoll = RpRandom();
                puVar1[10] = pauseRoll % 0x5a + 0x3c;
                mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,0,4,1);
              }
            }
            else if (motionWork->progress < zero) {
              motionWork->progress = motionWork->step;
              motionWork->direction = 1.0f;
              puVar1[9] = 0x5a;
              pauseRoll = RpRandom();
              puVar1[10] = pauseRoll % 0x5a + 0x3c;
              mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,0,4,1);
            }
            }
          }
        }
      }
        break;
      }
    }
    break;
  case 5:
  case 6:
    temp_v4 = func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
    *(FldCopyVec *)vec140 = *(FldCopyVec *)(temp_v4 + 0x20);
    pfVar12 = (float *)func_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
    *(FldCopyVec *)vec150 = *(FldCopyVec *)(pfVar12);
    turnForward = (RainVector *)vec140;
    RwV3dNormalize(turnForward, turnForward);
    turnRight = (RainVector *)vec150;
    RwV3dNormalize(turnRight, turnRight);
    mdlSetLookAtRequested(*(unsigned char **)(puVar1[3] + 0x164));
    ny = ((float*)puVar1)[0x10];
    nx = ((float*)puVar1)[0xf];
    nz = ((float*)puVar1)[0x11];
    temp_v13 = nx * vec140[0] + ny * vec140[1] + nz * vec140[2];
    one = 1.0f;
    if (temp_v13 < one) {
      temp_v12 = 15.0f;
      diff = one - temp_v13;
      if (diff < fGpffff8420) {
        temp_v12 = 180.0f * diff;
        temp_v13 = one;
      }
      sideZ = vec150[2];
      sideX = vec150[0];
      sideY = vec150[1];
      sideDot = nx * sideX + ny * sideY + nz * sideZ;
      sideZero = 0.0f;
      if (sideDot < sideZero) {
        temp_v12 = temp_v12 * -1.0f;
      }
      FldFrameTask_Rotate(*(unsigned char **)(puVar1[3] + 0x228), D_00756510, temp_v12);
    }
    if (temp_v13 == 1.0f) {
      if (*puVar1 == 5) {
        mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,3,8,0);
        *puVar1 = 7;
      }
      else {
        mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,0,8,1);
        *puVar1 = 4;
      }
    }
    break;
  case 7:
    finalModel = ((FldActorObject *)puVar1[3])->model;
    if (finalModel[0xee] == 1 &&
       (temp_v3 = mdlGetLayerAnimation((s32)finalModel, 0), temp_v3 != 0)) {
      mdlDispatchAnimIfPresent(*(unsigned char **)(puVar1[3] + 0x164),0,0,8,1);
    }
  
  case 8:
    break;
  }
  return 0;
}
#pragma pop

#pragma optimization_level 2
/* measured: optimization_level 1 preserves the retail FPU accumulator order. */
#pragma optimization_level 1
/* measured: close optimization_level 1 FPU accumulator probe. */
#pragma optimization_level 2
/* measured: opt_propagation off probe preserves retail's handle-load/result
   initialization order for the state predicate. */
#pragma opt_propagation off
// Kept in bucket: diff 8 when moved; cause not diagnosed (pragma replay checked, no explanation found).
// FUN_0018BEA0
s32 func_0018bea0(u8 *arg0)
{
    u8 *p;
    s32 r;
    s32 v;

    p = *(u8 **)(arg0 + 0x38);
    r = 0;
    v = *(s32 *)p;
    if (v == 5) {
        goto set;
    }
    if (v != 6) {
        goto rest;
    }
set:
    r = 1;
rest:
    return r;
}
/* measured: opt_propagation on closes the state-predicate probe. */
#pragma opt_propagation on

typedef struct MaterialTextureContext {
    s32 found;
    RwTexture *texture;
} MaterialTextureContext;

/* At the -O2 file baseline this function is normalized_diff 2: retail reads
   `mfc1 $a1` and `or $a1,$a1,$v1` where -O2 colours both one register lower.
   The bracket is closed back to the -O2 baseline immediately below the body.
   measured: optimization_level 1 for this function alone, plus materialising
   the 2147483648.0f constant into a named local AFTER the func_003ef650 call
   rather than inline, gives object 136B/window 144B, normalized_diff 0. */
#pragma optimization_level 1
/* measured: restore optimization level after FldMipmapSetFixedParam. */
#pragma optimization_level 2
/* MATCHED from a 40-word reconstruction.  Two source shapes carried it.
   The dungeon chain's dead final arm is `else if (dungeon < 0xA0) { res = 0; }`,
   not an empty arm: b210 drops the redundant store (res is already 0 on that
   path) but keeps the `slti $at, $s3, 0xa0` exactly as retail does, while a
   genuinely empty arm is removed compare and all, which cost three
   instructions and shifted every later branch displacement (40 words).  The
   first arm's range test is spelled `dungeon <= 5`, not `dungeon < 6`: both
   lower to `slti ..., $s3, 6`, but only the `<=` form puts the result in
   $at, which is what retail's branch-if-true uses; `< 6`, `6 > dungeon`,
   `!(dungeon >= 6)` and `(dungeon < 6) != 0` all pick $v0.  The declaration
   of calGetDayEntryByPhase above is also load-bearing - its first argument is a
   32-bit id and its second an unsigned flag word, not the s64/s32 pair m2c
   printed, and the s64 form costs a dsll32/dsra32 pair at every call site in
   this unit. */
/* MATCHED: the dispatch reads the pair at iGpffff9db0 with only the first
   word cached - retail reloads *(s32 *)(ctx + 4) at every test, so the
   long (major, minor) chains are written out rather than staged in a
   local.  The story flag is `s8`, which re-extends on each read the way
   retail does, and the sub-state is `u8`, whose reads carry the andi. */
/* MATCH: stage the s32 byte count without a conflicting callee prototype.
   Unsigned elapsed subtraction preserves retail timer wrap. 332B/336B,
   normalized_diff 0; only four zero-tail bytes are absent. */
#pragma push
#pragma opt_propagation off
// Kept in bucket: diff 7 when moved; cause not diagnosed.
// FUN_0018DDE0
s32 FldSupporterUpdate(u8 *arg0)
{
    u8 *work;
    s32 state;

    work = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(work + 4) == 1))
        return 0;
    if (scrGetWorkCount() > 0)
        return 0;
    state = *(s32 *)(work + 0);
    switch (state) {
    default:
        break;
    case 0:
        *(s32 *)(work + 0xC) = D_0076428C;
        *(s32 *)(work + 0) = *(s32 *)(work + 0) + 1;
        /* fallthrough */
    case 1:
        if (((u32)D_0076428C - (u32)*(s32 *)(work + 0xC)) > (u32)(*(s32 *)(work + 8))) {
            s32 size;

            size = iGpffffb278;
            *(s32 *)(work + 0x10) = scrStartProcedureChecked(0xF, iGpffffb27c, size, 0);
            *(s32 *)(work + 0) = 2;
            *(u32 *)(work + 8) = 0x384U;
            *(s32 *)(work + 0xC) = D_0076428C;
        }
        break;
    case 2:
        if (kwlnTaskIsLinked(*(s32 *)(work + 0x10)) == 1)
            return 0;
        *(s32 *)(work + 0x10) = 0;
        *(s32 *)(work + 0xC) = D_0076428C;
        *(s32 *)(work + 0) = 1;
        break;
    case 3:
        return -1;
    }
    return 0;
}
#pragma pop

/* One 0x4A-byte pad record; the pads start at 0x8C0240 (sdkPadInit). */
typedef struct {
    u8 unk00[0xC];
    u16 level;
    u16 trigger;
    u8 unk10[2];
    u16 repeat;
    u8 unk14[0x36];
} PadStatus;
typedef struct {
    u8 r, g, b, a;
} PanelColor;
typedef struct {
    u8 occupied;
    u8 flags;
    u16 resourceId;
    u8 shape;
    u8 rotation;
    u8 unknown06[10];
} MapTestCell;
typedef struct {
    u8 header[0x54];
    MapTestCell cells[24][16];
} MapTestGrid;

/* k_maptest.c: dungeon map generation test. The input image contains the
   button halfword; the map uses 16-byte cells and RGBA colors. Keep the
   row byte offset alive across its sixteen columns. */
#pragma opt_propagation off
#pragma opt_propagation on
// measured: probe propagation-off code shape with typed 16-bit operands
#pragma opt_propagation off
// Kept in bucket: diff 142 when moved; cause not diagnosed.
// FUN_0018F7B0
void FldMapTestCellsFill(u8 *arg0, s16 *arg1, u16 arg2, u16 arg3, s16 arg4)
{
    s32 i;
    s32 j;
    s32 one;
    u8 *data;
    s32 base;
    s32 row;
    s32 flags;
    s32 source_base;
    s32 cell;
    s32 source;

    data = (u8 *)arg1;
    one = (arg4 == arg4);
    base = (arg2) * 0x10 + (((arg3) << 8) + (s32)arg0);
    *(u8 *)(base + 0x2D) = one;
    i = 0;
    while (i < (s32)data[2]) {
        j = 0;
        row = base + (i << 8);
        flags = (s32)data + i * 3;
        source_base = (s32)data + i * 12;
        while (j < (s32)data[1]) {
            cell = row + (j << 4);
            if (*(u8 *)(cell + 0x2C) == 0) {
                *(u8 *)(cell + 0x2C) = one;
                *(u8 *)(cell + 0x2D) |= *(u8 *)(flags + j + 13);
                source = source_base + (j << 2);
                *(u8 *)(cell + 0x36) = *(u8 *)(source + 0x32);
                *(u8 *)(cell + 0x32) = data[1];
                *(u8 *)(cell + 0x33) = data[2];
                *(s8 *)(cell + 0x30) = *(s8 *)data;
                *(u8 *)(cell + 0x31) = arg4;
                *(u8 *)(cell + 0x37) = *(u8 *)(source + 0x33);
            }
            j += 1;
        }
        i += 1;
    }
}
// measured: restore propagation for following functions
#pragma opt_propagation on
extern u16 D_008C0252[];
extern u16 D_008C0298[];
extern const KWindowEntryDescriptor D_005F5FD0[];
extern void kwlnSetColorRgba(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
extern s32 sdkLboxAddEntry(u8 *arg0, u8 *arg1);
extern void sprintf(void *dst, const char *fmt, ...);
extern u8 *FldStepLoadFilePair(s32 arg0, s32 arg1);
extern s32 FldStepLoadHandleIsDone(u8 *arg0);
extern void FldStepLoadHandleDestroy(u8 *arg0);
extern s32 func_0015c630(u8 *arg0);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void FldTileRotateAttributes(void *arg0, u32 mask);
typedef struct {
    s16 data[0x2B];
} FieldPanelShape;
