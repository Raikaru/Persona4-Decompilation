#include "kwln_task_internal.h"
#include "model_access_internal.h"
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
extern s32 kwlnGetCurrentWorkValue(void);
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
extern s32 fldNpcControlIsBusy(unsigned char *);
extern s64 cmmResolveCounterpart(s64);
extern f32 RwV3dLength(const RainVector *vector);
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

extern RwRGBA D_00763074;
extern int func_003bb3a0();
extern RainMatrix *RwMatrixRotate(RainMatrix *matrix, const RainVector *axis, f32 angle, enum RwOpCombineType mode);
extern RainMatrix *RwMatrixUpdate(RainMatrix *matrix);
extern void func_003bb5b0(void *curve, s32 mode, f32 time, f32 *dst, void *aux);
extern void mdlScale(void *model, const void *scale, s32 combineOp);
typedef struct FldActorKindOne {
    u8 pad00[6];
    s16 animationId;
    u8 pad08[0xC];
    f32 scale;
} FldActorKindOne;
typedef struct FldActorKindTwo {
    u8 pad00[0x6C];
    s16 animationId;
    u8 pad6E[0xA];
    u32 resourceId;
} FldActorKindTwo;

typedef struct {
    u16 id;
    u8 unk002[0x26];
    u32 flags; /* 0x28: visibility and update flags */
    u8 unk02C[0x138];
    void *model;
    u8 unk168[0xb8];
    u16 pathMode;
    u8 unk222[6];
    u8 *movementTask;
    u8 unk22c[8];
    s32 kind;
    u8 unk238[8];
    RainMatrix initialMatrix;
    FldActorKindOne *kind1Data;
    FldActorKindTwo *kind2Data;
    u8 unk288[12];
    u8 *otherTask;
    u16 pointCount;
    u16 unk29a;
    RainVector points[16];
    f32 speed;
    u32 curve;
} FldActorObject;


s32 FldRcAtomicFrustumTest(s32 arg0, s32 *arg1);

/* Update field-actor visibility, animation, spline travel, and facing. */
// Kept in bucket: diff 35 when moved; cause not diagnosed (uses static inline fldBothReady_0018a200).
// FUN_0018A200
s32 FldNpcControlUpdate(u8 *task)
{
  typedef struct { f32 x, y, z; } FldCopyVec;
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
  u32 matrixSecondWord;
  s32 canLookAt;
  u16 lookFlags;
  s16 animationId;
  u32 movementMode;
  s32 savedAnimation;
  u32 resourceKey;
  s32 eventResource;
  u32 resourceId;
  s32 value;
  RainMatrix *actorMatrix;
  u8 *actorModel;
  u8 *effectTask;
  u32 objectAddress;
  u32 pauseRoll;
  u32 *matrixDestination;
  u32 matrixFirstWord;
  RainMatrix *playerMatrix;
  void *objectData;
  f32 *modelBasis;
  RainVector *facingNormal;
  RainVector *targetDirection;
  RainVector *lookTarget;
  RainVector *initialPathDirection;
  RainVector *pathDirection;
  RainVector *oscillatorDirection;
  RainVector *turnForward;
  RainVector *turnRight;
  u8 *finalModel;
  void *renderObject;
  u32 eventFlag;
  u32 fovResult;
  u32 distanceResult;
  s64 counterpartId;
  u32 *matrixSource;
  s32 actorOffset;
  u32 pauseFrames;
  f32 turnAngle;
  f32 distance;
  f32 facingLimit;
  f32 proximityLimit;
  f32 interactionAngle;
  f32 interactionRange;
  f32 oscillatorHeading;
  f32 pathHeading;
  f32 initialHeading;
  f32 initialZero;
  f32 initialX;
  f32 one;
  f32 diff;
  f32 ny;
  f32 nx;
  f32 nz;
  f32 sideZ;
  f32 sideX;
  f32 sideY;
  f32 sideZero;
  f32 sideDot;
  FldNpcControlWork *work;

  s32 outsideFrustum;
  f32 playerDelta[3];
  f32 actorForward[3];
  f32 actorToPlayer[3];
  f32 lookPosition[3];
  f32 cameraTarget[3];
  f32 cameraDelta[3];
  f32 cameraPosition[3];
  SVec3 transformAngles;
  f32 modelScale[3];
  f32 attachPosition[3];
  f32 pathSpan[3];
  f32 pathStart[3];
  f32 pathEnd[3];
  f32 pathPosition[3];
  f32 pathSample[3];
  f32 pathDelta[3];
  f32 oscillatorPosition[3];
  f32 oscillatorSample[3];
  f32 oscillatorDelta[3];
  f32 turnForwardVector[3];
  f32 turnRightVector[3];
  f32 movementPosition[3];  
  work = (FldNpcControlWork *)((KwlnTask *)task)->work;
  if (work->hidden == 1) {
    return 0;
  }
  if (work->state >= 4) {
    if (((FldActorObject *)work->actor)->kind == 2) {
      outsideFrustum = 0;
      renderObject = mdlGetClump(((FldActorObject *)work->actor)->model);
      RpClumpForAllAtomics((void *)renderObject, (KClumpCallback)FldRcAtomicFrustumTest, &outsideFrustum);
      /* Scene state has three position-slot tasks at +0x34; no shared layout exists. */
      value = (s32)MT_Scene_GetFrameState();
      if (*(s32 *)(value + work->actorIndex * 4 + 0x34) != 0) {
        s32 actorVisible;
        u8 *visibilityTarget;
        actorVisible = (outsideFrustum != 0) ^ 1;
        value = (s32)MT_Scene_GetFrameState();
        visibilityTarget = *(u8 **)(value + work->actorIndex * 4 + 0x34);
        FldRc_SetPositionSlotVisibility(visibilityTarget,work->positionSlot,actorVisible);
      }
      if ((((FldActorObject *)work->actor)->flags & 2) == 0) {
        FldNpcSetPositionLock(task,1);
      }
    }
    actorModel = ((FldActorObject *)work->actor)->model;
    /* Model resource type/ID are private prefix halfwords at +0xD4/+0xD6. */
    resourceId = *(u16 *)(actorModel + 0xd4);
    if ((((((resourceId != 5) || (*(u16 *)(actorModel + 0xd6) != 0x45ed)) &&
          ((resourceId != 5 || (*(u16 *)(actorModel + 0xd6) != 0x461f)))) &&
         ((resourceId != 5 || (*(u16 *)(actorModel + 0xd6) != 0x4651)))) &&
        ((resourceId != 5 || (*(u16 *)(actorModel + 0xd6) != 0x46b5)))) &&
       (((resourceId != 5 || (*(u16 *)(actorModel + 0xd6) != 0x46e7)) &&
        (fldBothReady_0018a200())))) {
      renderObject = mdlGetMatrix(((void **)D_007EFA00)[0]);
      actorMatrix = mdlGetMatrix(actorModel);
      facingLimit = 120.0f;
      fovResult = K_FldEvent_IsPosWithinFov((RainMatrix *)renderObject, &actorMatrix->pos, facingLimit);
      if (fovResult == 1) {
        actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
        distance = actorMatrix->pos.x;
        actorMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
        playerDelta[0] = distance - actorMatrix->pos.x;
        actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
        distance = actorMatrix->pos.y;
        actorMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
        playerDelta[1] = distance - actorMatrix->pos.y;
        actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
        distance = actorMatrix->pos.z;
        actorMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
        playerDelta[2] = distance - actorMatrix->pos.z;
        distance = RwV3dLength((RainVector *)playerDelta);
        if (distance < 150.0f) {
          canLookAt = 1;
          actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
          *(FldCopyVec *)actorForward = *(FldCopyVec *)&actorMatrix->at;
          actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
          distance = actorMatrix->pos.x;
          actorMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
          actorToPlayer[0] = actorMatrix->pos.x - distance;
          actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
          distance = actorMatrix->pos.y;
          actorMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
          actorToPlayer[1] = actorMatrix->pos.y - distance;
          actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
          distance = actorMatrix->pos.z;
          actorMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
          actorToPlayer[2] = actorMatrix->pos.z - distance;
          facingNormal = (RainVector *)actorForward;
          RwV3dNormalize(facingNormal, facingNormal);
          targetDirection = (RainVector *)actorToPlayer;
          RwV3dNormalize(targetDirection, targetDirection);
          if ((actorForward[0] * actorToPlayer[0] + actorForward[1] * actorToPlayer[1] + actorForward[2] * actorToPlayer[2] <= 0.0f) &&
             (((FldActorObject *)work->actor)->pathMode > 0)) {
            canLookAt = 0;
          }
          value = fldNpcControlIsBusy(((FldActorObject *)work->actor)->otherTask);
          if ((value == 0) && (canLookAt == 1)) {
            actorMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
            lookTarget = (RainVector *)lookPosition;
            *(FldCopyVec *)lookPosition = *(FldCopyVec *)&actorMatrix->pos;
            lookPosition[1] = lookPosition[1] + 140.0f;
            mdlSetLookAtTargetPoint(((FldActorObject *)work->actor)->model, lookTarget);
            lookFlags = mdlGetLookStateWord(((FldActorObject *)work->actor)->model);
            lookFlags |= 0x1000;
            mdlSetLookStateWord(((FldActorObject *)work->actor)->model, lookFlags);
          }
          else {
            mdlSetLookAtRequested(((FldActorObject *)work->actor)->model);
          }
        }
        else {
          mdlSetLookAtRequested(((FldActorObject *)work->actor)->model);
        }
      }
      else {
        mdlSetLookAtRequested(((FldActorObject *)work->actor)->model);
      }
    }
    /* Camera/frame prefixes are opaque here: frame at +4, frame position at +0x30. */
    value = kwlnGetCamera();
    matrixFirstWord = *(u32 *)(value + 4);
    FldFrameTask_GetPosition((u8 *)&movementPosition[0],((FldActorObject *)work->actor)->movementTask);
    *(FldCopyVec *)cameraTarget = *(FldCopyVec *)movementPosition;
    cameraTarget[1] = cameraTarget[1] + 180.0f;
    value = func_003e9700(matrixFirstWord);
    *(FldCopyVec *)cameraPosition = *(FldCopyVec *)(value + 0x30);
    cameraDelta[0] = cameraTarget[0] - cameraPosition[0];
    cameraDelta[1] = cameraTarget[1] - cameraPosition[1];
    cameraDelta[2] = cameraTarget[2] - cameraPosition[2];
    distance = RwV3dLength((RainVector *)cameraDelta);
    effectTask = (u8 *)work->effectTask;
    if (effectTask != NULL && KDraw_IsEffectDone(effectTask) == 1) {
      mdlClearAlphaBlend(((FldActorObject *)work->actor)->model);
      kwlnTaskDestroyWithHierarchy((void *)work->effectTask);
      work->effectTask = 0;
    }
    if (distance <= work->cameraHeight + 55.0f) {
      if (work->effectTask != 0) {
        mdlClearAlphaBlend(((FldActorObject *)work->actor)->model);
        kwlnTaskDestroyWithHierarchy((void *)work->effectTask);
        work->effectTask = 0;
      }
      mdlSetColor(((FldActorObject *)work->actor)->model, &D_00763074);
      work->cameraNear = 1;
    }
    if ((work->cameraNear == 1) && (!(distance <= work->cameraHeight + 55.0f))) {
      mdlSetAlphaBlend(((FldActorObject *)work->actor)->model);
      /* The fade API and animation query accept the model address as an integer handle. */
      objectAddress = KMisc_CreateRmdFade((s32)task,*(s32 *)(work->actor + 0x164),0,0xff,10);
      work->effectTask = objectAddress;
      work->cameraNear = 0;
    }
  }
  switch(work->state) {
  case 0:
    value = mdlPrepareModel(((FldActorObject *)work->actor)->model);
    if (value != 0) {
      objectAddress = work->actor;
      if (((FldActorObject *)objectAddress)->kind != 3) {
        /* Retail copies the 0x40-byte matrix as eight pairs of words. */
        matrixDestination = (u32 *)mdlGetMatrix(((FldActorObject *)objectAddress)->model);
        matrixSource = (u32 *)(objectAddress + 0x240);
        value = 8;
        do {
          matrixFirstWord = *matrixSource;
          matrixSecondWord = matrixSource[1];
          matrixSource = matrixSource + 2;
          value = value - 1;
          *matrixDestination = matrixFirstWord;
          matrixDestination[1] = matrixSecondWord;
          matrixDestination = matrixDestination + 2;
        } while (0 < value);
        mdlAdvanceModelFromFlags(((FldActorObject *)work->actor)->model);
        transformAngles.x = KDraw_MatrixPitchDeg((void *)(work->actor + 0x240));
        transformAngles.y = KDraw_MatrixYawDeg((void *)(work->actor + 0x240));
        transformAngles.z = KDraw_MatrixRollDeg((void *)(work->actor + 0x240));
        transformObject = (FldActorObject *)work->actor;
        MT_Scene_SetResPlacement(transformObject->id, (u8 *)&transformObject->initialMatrix.pos, (u8 *)&transformAngles);
        renderObject = mdlGetMatrix(((FldActorObject *)work->actor)->model);
        RwMatrixUpdate(renderObject);
        mdlSetColor(((FldActorObject *)work->actor)->model, &D_00763074);
        value = (s32)MT_Scene_GetResListHead(5);
        /* Resource-list records expose a vector at +0x1F0; remaining layout is unknown. */
        initialX = *(f32 *)(value + 0x1f0);
        initialZero = 0.0f;
        if (((initialZero != initialX) || (initialZero != *(f32 *)(value + 0x1f8))) ||
           (initialZero != *(f32 *)(value + 500))) {
          objectData = (void *)mdlGetClump(((FldActorObject *)work->actor)->model);
          FldRc_SetClumpVector(objectData,(u8 *)value + 0x1f0);
        }
      }
      objectAddress = func_003e0f80();
      work->handle = objectAddress;
      work->state = work->state + 1;
    }
    break;
  case 1:
    value = kwlnGetCurrentWorkValue();
    if (value == 9) {
      value = (s32)MT_Scene_GetFrameState();
      if (*(s32 *)(value + 0x34) == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      value = FldRc_FileLoadIsReady(*(u8 **)(value + 0x34));
      if (value == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      if (*(s32 *)(value + 0x38) == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      value = FldRc_FileLoadIsReady(*(u8 **)(value + 0x38));
      if (value == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      if (*(s32 *)(value + 0x3c) == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      value = FldRc_FileLoadIsReady(*(u8 **)(value + 0x3c));
      if (value == 0) {
        break;
      }
    }
    objectAddress = work->actor;
    objectKind = ((FldActorObject *)objectAddress)->kind;
    if (objectKind == 1) {
      distance = ((FldActorObject *)objectAddress)->kind1Data->scale;
      if (distance != 0.0f) {
        modelScale[0] = modelScale[1] = modelScale[2] = distance;
        mdlScale(((FldActorObject *)objectAddress)->model, modelScale, 1);
      }
      initialAnimationObject = (FldActorObject *)work->actor;
      initialAnimationId = initialAnimationObject->kind1Data->animationId;
      mdlDispatchAnimIfPresent(initialAnimationObject->model, 0, initialAnimationId, 0, 1);
    }
    else if (objectKind == 2) {
      objectAddress = ((FldActorObject *)objectAddress)->kind2Data->resourceId;
      if (objectAddress != 0) {
        actorIndex = 1;
        animationId = (s16)objectAddress;
        resourceKey = (u16)animationId;
        value = (s32)cmmKindRecord(resourceKey);
        /* cmmKindRecord exposes flags at +4; its record layout is not declared here. */
        if ((*(u32 *)(value + 4) & 1) != 0) {
          counterpartId = cmmResolveCounterpart((s16)resourceKey);
          animationId = (s16)counterpartId;
        }
        eventResource = animationId;
        eventFlag = datGetFlag(eventResource + 0x43f);
        if (eventFlag != 0) {
          actorIndex = 2;
        } else {
          eventFlag = datGetFlag(eventResource + 0x45f);
          if (eventFlag != 0) {
            actorIndex = 0;
          }
        }
        value = mdlComputeIndexedAttachMatrix(((FldActorObject *)work->actor)->model,2,&attachPosition[0]);
        if (value == 0) {
          actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
          *(FldCopyVec *)attachPosition = *(FldCopyVec *)&actorMatrix->pos;
          attachPosition[1] = attachPosition[1] + 175.0f;
        }
        actorOffset = actorIndex * 4;
        value = (s32)MT_Scene_GetFrameState();
        objectAddress = FldRc_RequestPositionSlot(*(u8 **)(value + actorOffset + 0x34),&attachPosition[0]);
        value = (s32)MT_Scene_GetFrameState();
        FldRc_SetPositionSlotPriority(*(u8 **)(value + actorOffset + 0x34),objectAddress,4);
        work->actorIndex = actorIndex;
        work->positionSlot = objectAddress;
      }
      initialAnimationObject = (FldActorObject *)work->actor;
      initialAnimationId = initialAnimationObject->kind2Data->animationId;
      mdlDispatchAnimIfPresent(initialAnimationObject->model, 0, initialAnimationId, 0, 1);
    }
    initialPathObject = (FldActorObject *)work->actor;
    if (initialPathObject->pointCount < 4) {
      initialPathObject->pathMode = 0;
    }
    initialPathObject = (FldActorObject *)work->actor;
    splineMode = initialPathObject->pathMode;
    if (splineMode > 0) {
      closedLoopType = 2;
      if (splineMode == closedLoopType) {
        matrixFirstWord = (u32)func_003bbbe0(initialPathObject->pointCount,closedLoopType,initialPathObject->points);
        ((FldActorObject *)work->actor)->curve = matrixFirstWord;
      } else {
        matrixFirstWord = (u32)func_003bbbe0(initialPathObject->pointCount,1,initialPathObject->points);
        ((FldActorObject *)work->actor)->curve = matrixFirstWord;
      }
      work->progress.bits = 0;
      work->direction.bits = 0x3f800000;
      func_003bb3a0(((FldActorObject *)work->actor)->curve,0,&pathStart[0]);
      func_003bb3a0(((FldActorObject *)work->actor)->curve,1,&pathEnd[0]);
      pathSpan[0] = pathEnd[0] - pathStart[0];
      pathSpan[1] = pathEnd[1] - pathStart[1];
      pathSpan[2] = pathEnd[2] - pathStart[2];
      distance = RwV3dLength((RainVector *)pathSpan);
      initialPathObject = (FldActorObject *)work->actor;
      distance = (1.0f / (initialPathObject->pointCount - 1)) *
               (initialPathObject->speed / distance);
      work->step.value = distance;
      work->progress.value = (work->progress.value + distance);
      mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,1,4,1);
      func_003bb5b0((void *)(u32)((FldActorObject *)work->actor)->curve, 10, work->progress.value, &pathEnd[0], 0);
      actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
      *(FldCopyVec *)pathStart = *(FldCopyVec *)&actorMatrix->pos;
      pathSpan[0] = pathEnd[0] - pathStart[0];
      pathSpan[1] = pathEnd[1] - pathStart[1];
      pathSpan[2] = pathEnd[2] - pathStart[2];
      initialPathDirection = (RainVector *)pathSpan;
      RwV3dNormalize(initialPathDirection, initialPathDirection);
      distance = (f32)func_0044b920(pathSpan[0] * D_00756520[0] + pathSpan[1] * D_00756524[0] + pathSpan[2] * D_00756528[0]);
      initialHeading = fGpffff8300 * distance;
      if (pathSpan[0] < 0.0f) {
        initialHeading = initialHeading * -1.0f;
      }
      ((RainMatrix *)work->handle)->right.x =
          ((RainMatrix *)work->handle)->up.y =
          ((RainMatrix *)work->handle)->at.z = 1.0f;
      ((RainMatrix *)work->handle)->up.x = 0.0f;
      ((RainMatrix *)work->handle)->right.z = 0.0f;
      ((RainMatrix *)work->handle)->right.y = 0.0f;
      ((RainMatrix *)work->handle)->at.y = 0.0f;
      ((RainMatrix *)work->handle)->at.x = 0.0f;
      ((RainMatrix *)work->handle)->up.z = 0.0f;
      ((RainMatrix *)work->handle)->pos.z = 0.0f;
      ((RainMatrix *)work->handle)->pos.y = 0.0f;
      ((RainMatrix *)work->handle)->pos.x = 0.0f;
      ((RainMatrix *)work->handle)->flags |= 0x20003;
      RwMatrixRotate((RainMatrix *)work->handle, (const RainVector *)D_00756510, initialHeading, rwCOMBINEPOSTCONCAT);
      FldFrameTask_SetOrientation(((FldActorObject *)work->actor)->movementTask,(u8 *)work->handle);
    }
    work->savedAnimation = 0xffffffff;
    work->state = work->state + 1;
    break;
  case 2:
    ((FldActorObject *)work->actor)->flags = ((FldActorObject *)work->actor)->flags | 0x10000000;
    mdlSetAlphaBlend(((FldActorObject *)work->actor)->model);
    objectAddress = KMisc_CreateRmdFade((s32)task,*(s32 *)(work->actor + 0x164),0,0xff,8);
    work->effectTask = objectAddress;
    work->state = work->state + 1;
    break;
  case 3:
    value = KDraw_IsEffectDone((u8 *)work->effectTask);
    if (value != 0) {
      mdlClearAlphaBlend(((FldActorObject *)work->actor)->model);
      kwlnTaskDestroyWithHierarchy((void *)work->effectTask);
      work->effectTask = 0;
      ((FldActorObject *)work->actor)->flags = ((FldActorObject *)work->actor)->flags | 0x10000000;
      work->state = work->state + 1;
    }
    break;
  case 4:
    if (fldBothReady_0018a200()) {
      actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
      playerMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
      proximityLimit = 500.0f;
      distanceResult = K_FldEvent_ArePosWithinDist(&actorMatrix->pos, &playerMatrix->pos, proximityLimit);
      if (distanceResult == 1) {
        objectData = (void *)mdlGetMatrix(((FldActorObject *)work->actor)->model);
        actorMatrix = mdlGetMatrix(((void **)D_007EFA00)[0]);
        interactionAngle = 90.0f;
        interactionRange = 250.0f;
        objectAddress = FldEvent_HasLineOfSight(objectData,&actorMatrix->pos,interactionAngle,interactionRange);
        if (objectAddress != 0) {
          if (work->savedAnimation != 0xffffffff) {
            break;
          }
          animationId = mdlGetLayerAnimation(*(s32 *)(work->actor + 0x164), 0);
          work->savedAnimation = (s32)animationId;
          objectAddress = work->actor;
          updateAnimationKind = ((FldActorObject *)objectAddress)->kind;
          if (updateAnimationKind == 1) {
            mdlDispatchAnimIfPresent(((FldActorObject *)objectAddress)->model,0,(s32)((FldActorObject *)objectAddress)->kind1Data->animationId,4
                          ,1);
            break;
          }
          if (updateAnimationKind != 2) {
            break;
          }
          mdlDispatchAnimIfPresent(((FldActorObject *)objectAddress)->model,0,(s32)((FldActorObject *)objectAddress)->kind2Data->animationId,
                        4,1);
          break;
        }
      }
      savedAnimation = work->savedAnimation;
      if (savedAnimation >= 0) {
        mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,(s16)savedAnimation,4,1);
        work->savedAnimation = 0xffffffff;
      }
      objectAddress = work->actor;
      movementMode = ((FldActorObject *)objectAddress)->pathMode;
      switch (movementMode) {
      case 0:
        break;
      case 1:
      case 2:
      case 4:
      {
        FldNpcControlWork *pathWork;
        if (((movementMode != 4) || work->progress.value != 1.0f) &&
            (animationId = mdlGetLayerAnimation(*(s32 *)(objectAddress + 0x164), 0), animationId != 1)) {
          mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,1,4,1);
        }
        func_003bb5b0((void *)(u32)((FldActorObject *)work->actor)->curve, 10, work->progress.value, &pathSample[0], 0);
        actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
        *(FldCopyVec *)pathPosition = *(FldCopyVec *)&actorMatrix->pos;
        pathDelta[0] = pathSample[0] - pathPosition[0];
        pathDelta[1] = pathSample[1] - pathPosition[1];
        pathDelta[2] = pathSample[2] - pathPosition[2];
        pathDirection = (RainVector *)pathDelta;
        RwV3dNormalize(pathDirection, pathDirection);
        distance = (f32)func_0044b920(pathDelta[0] * D_00756520[0] + pathDelta[1] * D_00756524[0] + pathDelta[2] * D_00756528[0]);
        pathHeading = fGpffff8300 * distance;
        if (pathDelta[0] < 0.0f) {
          pathHeading = pathHeading * -1.0f;
        }
        ((RainMatrix *)work->handle)->right.x =
            ((RainMatrix *)work->handle)->up.y =
            ((RainMatrix *)work->handle)->at.z = 1.0f;
        ((RainMatrix *)work->handle)->up.x = 0.0f;
        ((RainMatrix *)work->handle)->right.z = 0.0f;
        ((RainMatrix *)work->handle)->right.y = 0.0f;
        ((RainMatrix *)work->handle)->at.y = 0.0f;
        ((RainMatrix *)work->handle)->at.x = 0.0f;
        ((RainMatrix *)work->handle)->up.z = 0.0f;
        ((RainMatrix *)work->handle)->pos.z = 0.0f;
        ((RainMatrix *)work->handle)->pos.y = 0.0f;
        ((RainMatrix *)work->handle)->pos.x = 0.0f;
        ((RainMatrix *)work->handle)->flags |= 0x20003;
        RwMatrixRotate((RainMatrix *)work->handle, (const RainVector *)D_00756510, pathHeading, rwCOMBINEPOSTCONCAT);
        pathWork = work;
        movingObject = (FldActorObject *)work->actor;
        if (movingObject->pathMode != 4 || pathWork->progress.value < 1.0f) {
          FldFrameTask_SetOrientation(movingObject->movementTask,(u8 *)work->handle);
          FldFrameTask_SetPosition(((FldActorObject *)work->actor)->movementTask,(u8 *)&pathSample[0]);
          pathWork->progress.value = (pathWork->progress.value + pathWork->step.value);
        }
        if (((FldActorObject *)work->actor)->pathMode == 4) {
          if (!(pathWork->progress.value <= 1.0f)) {
            pathWork->progress.value = 1.0f;
            mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,0,4,1);
          }
        }
        else if (!(pathWork->progress.value <= 1.0f)) {
          pathWork->progress.value = 0.0f;
        }
      }
        break;
      case 3:
      {
        pauseFrames = work->pauseFrames;
        if ((s32)pauseFrames >= 1) {
          work->pauseFrames = pauseFrames - 1;
        } else {
          if ((pauseFrames == 0) && (animationId = mdlGetLayerAnimation(*(s32 *)(objectAddress + 0x164), 0), animationId != 1)) {
            mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,1,4,1);
          }
          if ((s32)work->turnFrames > 0) {
            FldFrameTask_Rotate(((FldActorObject *)work->actor)->movementTask, D_00756510, 2.0f);
            work->turnFrames = work->turnFrames - 1;
          }
          else {
            func_003bb5b0((void *)(u32)((FldActorObject *)work->actor)->curve, 10, work->progress.value, &oscillatorSample[0], 0);
            actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
            *(FldCopyVec *)oscillatorPosition = *(FldCopyVec *)&actorMatrix->pos;
            oscillatorDelta[0] = oscillatorSample[0] - oscillatorPosition[0];
            oscillatorDelta[1] = oscillatorSample[1] - oscillatorPosition[1];
            oscillatorDelta[2] = oscillatorSample[2] - oscillatorPosition[2];
            oscillatorDirection = (RainVector *)oscillatorDelta;
            RwV3dNormalize(oscillatorDirection, oscillatorDirection);
            distance = (f32)func_0044b920(oscillatorDelta[0] * D_00756520[0] + oscillatorDelta[1] * D_00756524[0] + oscillatorDelta[2] * D_00756528[0]);
            oscillatorHeading = fGpffff8300 * distance;
            if (oscillatorDelta[0] < 0.0f) {
              oscillatorHeading = oscillatorHeading * -1.0f;
            }
            ((RainMatrix *)work->handle)->right.x =
                ((RainMatrix *)work->handle)->up.y =
                ((RainMatrix *)work->handle)->at.z = 1.0f;
            ((RainMatrix *)work->handle)->up.x = 0.0f;
            ((RainMatrix *)work->handle)->right.z = 0.0f;
            ((RainMatrix *)work->handle)->right.y = 0.0f;
            ((RainMatrix *)work->handle)->at.y = 0.0f;
            ((RainMatrix *)work->handle)->at.x = 0.0f;
            ((RainMatrix *)work->handle)->up.z = 0.0f;
            ((RainMatrix *)work->handle)->pos.z = 0.0f;
            ((RainMatrix *)work->handle)->pos.y = 0.0f;
            ((RainMatrix *)work->handle)->pos.x = 0.0f;
            ((RainMatrix *)work->handle)->flags |= 0x20003;
            RwMatrixRotate((RainMatrix *)work->handle, (const RainVector *)D_00756510, oscillatorHeading, rwCOMBINEPOSTCONCAT);
            FldFrameTask_SetOrientation(((FldActorObject *)work->actor)->movementTask,(u8 *)work->handle);
            FldFrameTask_SetPosition(((FldActorObject *)work->actor)->movementTask,(u8 *)&oscillatorSample[0]);
            {
            FldNpcControlWork *motionWork = work;
            f32 zero;
            f32 one;

            motionWork->progress.value = (motionWork->step.value * motionWork->direction.value + motionWork->progress.value);
            zero = 0.0f;
            if (!(motionWork->direction.value <= zero)) {
              f32 endProgress = motionWork->progress.value;
              one = 1.0f;
              if (!(endProgress <= one)) {
                motionWork->progress.value = (one - motionWork->step.value);
                motionWork->direction.value = -1.0f;
                work->turnFrames = 0x5a;
                pauseRoll = RpRandom();
                work->pauseFrames = pauseRoll % 0x5a + 0x3c;
                mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,0,4,1);
              }
            }
            else if (motionWork->progress.value < zero) {
              motionWork->progress.value = motionWork->step.value;
              motionWork->direction.value = 1.0f;
              work->turnFrames = 0x5a;
              pauseRoll = RpRandom();
              work->pauseFrames = pauseRoll % 0x5a + 0x3c;
              mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,0,4,1);
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
    actorMatrix = mdlGetMatrix(((FldActorObject *)work->actor)->model);
    *(FldCopyVec *)turnForwardVector = *(FldCopyVec *)&actorMatrix->at;
    /* Preserve the retail two-word cursor copy of the matrix basis. */
    modelBasis = (f32 *)mdlGetMatrix(((FldActorObject *)work->actor)->model);
    *(FldCopyVec *)turnRightVector = *(FldCopyVec *)(modelBasis);
    turnForward = (RainVector *)turnForwardVector;
    RwV3dNormalize(turnForward, turnForward);
    turnRight = (RainVector *)turnRightVector;
    RwV3dNormalize(turnRight, turnRight);
    mdlSetLookAtRequested(((FldActorObject *)work->actor)->model);
    ny = work->headingY;
    nx = work->headingX;
    nz = work->headingZ;
    distance = nx * turnForwardVector[0] + ny * turnForwardVector[1] + nz * turnForwardVector[2];
    one = 1.0f;
    if (distance < one) {
      turnAngle = 15.0f;
      diff = one - distance;
      if (diff < fGpffff8420) {
        turnAngle = 180.0f * diff;
        distance = one;
      }
      sideZ = turnRightVector[2];
      sideX = turnRightVector[0];
      sideY = turnRightVector[1];
      sideDot = nx * sideX + ny * sideY + nz * sideZ;
      sideZero = 0.0f;
      if (sideDot < sideZero) {
        turnAngle = turnAngle * -1.0f;
      }
      FldFrameTask_Rotate(((FldActorObject *)work->actor)->movementTask, D_00756510, turnAngle);
    }
    if (distance == 1.0f) {
      if (work->state == 5) {
        mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,3,8,0);
        work->state = 7;
      }
      else {
        mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,0,8,1);
        work->state = 4;
      }
    }
    break;
  case 7:
    finalModel = ((FldActorObject *)work->actor)->model;
    if (finalModel[0xee] == 1 &&
       (animationId = mdlGetLayerAnimation((s32)finalModel, 0), animationId != 0)) {
      mdlDispatchAnimIfPresent(((FldActorObject *)work->actor)->model,0,0,8,1);
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
/* Return whether the actor is turning toward or away from its stored heading. */
s32 fldNpcControlIsTurning(u8 *task)
{
    u8 *work;
    s32 result;
    s32 state;

    work = ((KwlnTask *)task)->work;
    result = 0;
    state = ((FldNpcControlWork *)work)->state;
    /* A structured || test differed by 22 normalized bytes; keep the shared
     * success/return labels that match the retail branch chain. */
    if (state == 5) {
        goto ready;
    }
    if (state != 6) {
        goto done;
    }
ready:
    result = 1;
done:
    return result;
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
/* Run the support procedure after its delay, then wait for that script to finish. */
// FUN_0018DDE0
/* Work is {state, hidden, delay, startFrame, scriptTask} at 0x00..0x10.
 * Member access produced 360B in the 336B window (normalized_diff 240);
 * preserve the mixed signed/unsigned byte accesses instead of steering. */
s32 FldSupporterUpdate(u8 *task)
{
    u8 *work;
    s32 state;

    work = *(u8 **)(task + 0x38);
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
/* Cells start at grid+0x2C with 0x10-byte columns/0x100-byte rows.
 * Pattern flags have 3-byte rows, attributes 12-byte rows at +0x32.
 * Typed cell/pattern traversal kept the 240-byte size but differed by 169
 * normalized bytes; retain these offset cursors, not allocation steering. */
void FldMapTestCellsFill(u8 *grid, s16 *shapeData, u16 x, u16 y, s16 rotation)
{
    s32 rowIndex;
    s32 columnIndex;
    s32 occupied;
    u8 *pattern;
    s32 originAddress;
    s32 rowAddress;
    s32 flagsAddress;
    s32 sourceRowAddress;
    s32 cellAddress;
    s32 sourceAddress;

    pattern = (u8 *)shapeData;
    occupied = (rotation == rotation);
    originAddress = (x) * 0x10 + (((y) << 8) + (s32)grid);
    *(u8 *)(originAddress + 0x2D) = occupied;
    rowIndex = 0;
    while (rowIndex < (s32)pattern[2]) {
        columnIndex = 0;
        rowAddress = originAddress + (rowIndex << 8);
        flagsAddress = (s32)pattern + rowIndex * 3;
        sourceRowAddress = (s32)pattern + rowIndex * 12;
        while (columnIndex < (s32)pattern[1]) {
            cellAddress = rowAddress + (columnIndex << 4);
            if (*(u8 *)(cellAddress + 0x2C) == 0) {
                *(u8 *)(cellAddress + 0x2C) = occupied;
                *(u8 *)(cellAddress + 0x2D) |= *(u8 *)(flagsAddress + columnIndex + 13);
                sourceAddress = sourceRowAddress + (columnIndex << 2);
                *(u8 *)(cellAddress + 0x36) = *(u8 *)(sourceAddress + 0x32);
                *(u8 *)(cellAddress + 0x32) = pattern[1];
                *(u8 *)(cellAddress + 0x33) = pattern[2];
                *(s8 *)(cellAddress + 0x30) = *(s8 *)pattern;
                *(u8 *)(cellAddress + 0x31) = rotation;
                *(u8 *)(cellAddress + 0x37) = *(u8 *)(sourceAddress + 0x33);
            }
            columnIndex += 1;
        }
        rowIndex += 1;
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
