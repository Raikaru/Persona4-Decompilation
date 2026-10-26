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
#include "mdl_file_internal.h"
#include "rw_object_internal.h"
#include "resrc_manager_internal.h"
#include "cmm_internal.h"
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
extern void mdlEffectEmitTagPair();
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32, s32);
extern void mdlEffectEmitMaskedTagPair(void);
extern void FldNoiseEmitTagged(void);
extern void func_003a2760(u8 *object);
extern void func_003e9390(s32);
struct RpGeometry;
typedef struct RpMaterial *(*MaterialCallback)(struct RpMaterial *, void *);
extern struct RpGeometry *func_003c21e0(struct RpGeometry *geometry, MaterialCallback callback, void *data);
extern void mdlDestroyModelObject(s32 model);
extern void func_003f3eb0(s32, s32);
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
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);
extern const KWindowEntryDescriptor D_005F5830[];
extern const KWindowEntryDescriptor D_005F5730[];
extern u8 D_007E3720[];
extern u8 D_007966D0[];
extern s64 iGpffff9fd0;
extern s32 iGpffffb240;
extern void FldBoardGenerate(s32 mode, s32 seed, s32 unused);
extern void FldSmapTileQueueByType(u8 *queue, u8 *context, s32 tileType, s32 variant,
                           f32 x, f32 y, f32 depth, s32 flags);
extern void FldRc_QueueScreenQuad(u8 *queue, u8 *quad,
                          f32 left, f32 top, f32 depthOffset, f32 width,
                          f32 height, u8 *color, s32 texture,
                          f32 uMin, f32 vMin, f32 uMax, s32 orientation,
                          f32 vMax);
extern void FldSmapTileQueueQuad(u8 *queue, u8 *context, s32 tileType, s32 variant, s32 width,
                          s32 height, s32 flags, f32 x, f32 y, f32 depth);
extern u16 D_008C024E[];
extern s32 scrStartProcedureChecked(s32 priority, s32 source, s32 size, s32 procedureIndex);
extern s32 kwlnTaskIsLinked(s32 target);

void K_Test_Create(s32 parentTask);

extern void func_003e0f40(s32);
extern s32 K_Clump_MatUsrDataHasData(u8 *material, u8 *name);
extern struct RpMaterial *func_003c42b0(struct RpMaterial *material, RwTexture *texture);
extern u8 D_005F5438[];
extern s32 *MT_Scene_GetFrameState(void);
extern void FldRc_SetPositionSlotLock(s32 task, s32 slotIndex, s32 locked);
extern RwTexDictionary *func_003ef6d0(void);
extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
extern void RpSkyTextureSetMipmapK(s32 a, f32 fp);
extern u8 D_005F5360[];
extern u8 iGpffffb310;
extern void memset(void *dst, s32 value, s32 size);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F5340[];
extern u8 D_005F5350[];
extern u8 D_005F5320[];
extern u8 D_005F5330[];
extern s32 kwlnGetCamera(void);
extern f32 fGpffff8218;
extern s16 mdlGetLayerAnimation(s32 model, s32 layer);
extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
extern u8 *K_ClumpLookAtBasis(u8 *object, u8 *position, u8 *target, s32 referenceUp);
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern s32 FldNpcControlUpdate(u8 *task);
extern s32 FldStepNotAtBoundary(void);
extern f32 sinf(f32);

extern u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count);
extern s32 frFontExDrawTextDeferredWithCharWidth(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id,
                         const char *str, s32 flags, s32 unused, void *param,
                         s32 charWidth);
extern f32 D_008872F8[];
extern f32 D_00761184;
extern u8 D_00794C60[];
extern u32 D_007EFA00[];
extern u8 D_005F54D8[];
extern s32 FldPanel2dUpdate(u8 *task);
extern void FldPanel2dSelectEntry(s32 entryIndex);
extern u8 D_005F54E8[];
extern s32 FldSupporterUpdate(u8 *task);
extern u8 D_005F1D80[];
extern u8 D_005F1D90[];
extern s32 iGpffff9f60;
extern s32 FldRainUpdate(u8 *task);

extern s32 FldNoiseUpdate(u8 *task);
extern void FldNoiseDestroy(u8 *task);
extern s32 FldMapTestUpdate(u8 *task);
extern void FldMapTestDestroy(u8 *task);
extern u8 D_005F1DF8[];
extern u8 D_005F1E08[];
extern u8 D_005F57B0[];
extern u8 D_005F57C0[];
extern s32 func_003bfae0();
extern s32 kwlnGetCamera(void);
extern s32 RwCameraFrustumTestSphere(u8 *, s32);
extern void func_003f68a0(s32, s32);
extern u8 D_007E8C00[];
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern s64 calGetDayEntryByPhase(s32 day, u32 phase);
extern s32 clndIsDateInRange(s32 startMonth, s32 startDay, s32 endMonth, s32 endDay);
extern s32 FldStepIndex(void);
extern s32 iGpffffb264;
extern u8 *iGpffff9db0;
extern s32 iGpffffb884;

typedef struct {
    f32 x, y, z;
} FldAreaNormal;


/* measured: O1 gives retail's register allocation for the byte copy. */
#pragma optimization_level 1
#pragma optimization_level 2
/* measured: VU0 MMI builtins reproduce retail's pcpyld/sq packet build. */
#pragma enable_vu0_registers on
/* measured: retail binds the MMI packet registers. */
#pragma vu0_mmi_reg_binding on
/* measured: O1 keeps retail's packet construction order. */
#pragma optimization_level 1
#pragma optimization_level 2
#pragma vu0_mmi_reg_binding off
/* measured: restores the unit setting after the MMI packet function. */
#pragma enable_vu0_registers off

#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
#pragma optimization_level 1
#pragma optimization_level 2
#pragma vu0_mmi_reg_binding off
#pragma enable_vu0_registers off

/* Unit setting: propagation off; reapply it after the preserved optimization-level resets. */
#pragma opt_propagation off


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


/* measured: tests whether both field readiness state words are nonzero; kept as an inline wrapper
 * because expanding the call changes FldNpcControlUpdate's register allocation and branches. */
static inline s32 fldBothReady(void)
{
    extern int D_007EF9F8[];
    extern int D_007EFA04[];

    return D_007EF9F8[0] != 0 && D_007EFA04[0] != 0;
}

/* Per-phase object/work snapshots and vector lifetimes preserve retail's frame; disabling constant
 * pullout avoids cross-phase hoists. */
#pragma push
/* measured: lifetimes keeps retail's frame and register allocation. */
#pragma opt_lifetimes on
/* measured: retail does not hoist constants across phases. */
#pragma opt_pulloutconstants off
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


s32 FldRcAtomicFrustumTest(s32 atomic, s32 *visible);

/* Update field-actor visibility, animation, spline travel, and facing. */
// Kept in bucket: diff 35 when moved; cause not diagnosed (uses static inline fldBothReady).
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
      /* The scene frame owns three position-slot tasks in dependentTasks. */
      value = (s32)MT_Scene_GetFrameState();
      if ((s32)((FldFrame *)value)->dependentTasks[work->actorIndex] != 0) {
        s32 actorVisible;
        u8 *visibilityTarget;
        actorVisible = (outsideFrustum != 0) ^ 1;
        value = (s32)MT_Scene_GetFrameState();
        visibilityTarget = ((FldFrame *)value)->dependentTasks[work->actorIndex];
        FldRc_SetPositionSlotVisibility(visibilityTarget,work->positionSlot,actorVisible);
      }
      if ((((FldActorObject *)work->actor)->flags & 2) == 0) {
        FldNpcSetPositionLock(task,1);
      }
    }
    actorModel = ((FldActorObject *)work->actor)->model;
    /* Model-file type and ID select the actors excluded from automatic look-at. */
    resourceId = ((MdlFileModel *)actorModel)->type;
    if ((((((resourceId != 5) || (((MdlFileModel *)actorModel)->id != 0x45ed)) &&
          ((resourceId != 5 || (((MdlFileModel *)actorModel)->id != 0x461f)))) &&
         ((resourceId != 5 || (((MdlFileModel *)actorModel)->id != 0x4651)))) &&
        ((resourceId != 5 || (((MdlFileModel *)actorModel)->id != 0x46b5)))) &&
       (((resourceId != 5 || (((MdlFileModel *)actorModel)->id != 0x46e7)) &&
        (fldBothReady())))) {
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
    /* Follow the camera parent frame to its matrix position. */
    value = kwlnGetCamera();
    matrixFirstWord = (u32)((RwObject *)value)->parent;
    FldFrameTask_GetPosition((u8 *)&movementPosition[0],((FldActorObject *)work->actor)->movementTask);
    *(FldCopyVec *)cameraTarget = *(FldCopyVec *)movementPosition;
    cameraTarget[1] = cameraTarget[1] + 180.0f;
    value = func_003e9700(matrixFirstWord);
    *(FldCopyVec *)cameraPosition = *(FldCopyVec *)&((RainMatrix *)value)->pos;
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
      objectAddress = KMisc_CreateRmdFade((s32)task,((ResrcRecord *)work->actor)->modelHandle164Value,0,0xff,10);
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
        /* The type-5 resource supplies the clump lighting scale vector. */
        initialX = ((ResrcRecord *)value)->lightScale[0];
        initialZero = 0.0f;
        if (((initialZero != initialX) || (initialZero != ((ResrcRecord *)value)->lightScale[2])) ||
           (initialZero != ((ResrcRecord *)value)->lightScale[1])) {
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
      if ((s32)((FldFrame *)value)->dependentTasks[0] == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      value = FldRc_FileLoadIsReady(((FldFrame *)value)->dependentTasks[0]);
      if (value == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      if ((s32)((FldFrame *)value)->dependentTasks[1] == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      value = FldRc_FileLoadIsReady(((FldFrame *)value)->dependentTasks[1]);
      if (value == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      if ((s32)((FldFrame *)value)->dependentTasks[2] == 0) {
        break;
      }
      value = (s32)MT_Scene_GetFrameState();
      value = FldRc_FileLoadIsReady(((FldFrame *)value)->dependentTasks[2]);
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
        /* Community-kind flag 1 enables counterpart resolution before testing event flags. */
        if ((((CmmKindRecord *)value)->flags & 1) != 0) {
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
        objectAddress = FldRc_RequestPositionSlot(((FldFrame *)(value + actorOffset))->dependentTasks[0],&attachPosition[0]);
        value = (s32)MT_Scene_GetFrameState();
        FldRc_SetPositionSlotPriority(((FldFrame *)(value + actorOffset))->dependentTasks[0],objectAddress,4);
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
    objectAddress = KMisc_CreateRmdFade((s32)task,((ResrcRecord *)work->actor)->modelHandle164Value,0,0xff,8);
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
    if (fldBothReady()) {
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
          animationId = mdlGetLayerAnimation(((ResrcRecord *)work->actor)->modelHandle164Value, 0);
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
            (animationId = mdlGetLayerAnimation(((ResrcRecord *)objectAddress)->modelHandle164Value, 0), animationId != 1)) {
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
          if ((pauseFrames == 0) && (animationId = mdlGetLayerAnimation(((ResrcRecord *)objectAddress)->modelHandle164Value, 0), animationId != 1)) {
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
    *(FldCopyVec *)turnRightVector = *(FldCopyVec *)&((RainMatrix *)modelBasis)->right;
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
    if (((MdlFileModel *)finalModel)->finished == 1 &&
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
/* measured: retail's FPU accumulator order needs optimization level 1. */
#pragma optimization_level 1
#pragma optimization_level 2
/* measured: the level reset turns propagation back on, so the unit setting is reapplied. */
#pragma opt_propagation off
/* measured: propagation off keeps retail's order of loading the handle and initializing the result
 * for the state check. */
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
    /* Shared success/return labels follow retail's branch chain; a structured || test does not. */
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

typedef struct MaterialTextureContext {
    s32 found;
    RwTexture *texture;
} MaterialTextureContext;

/* measured: retail's register choice around the float-to-int conversion is only reproduced at O1,
 * with the 2147483648.0f constant loaded into a local after the call. */
#pragma optimization_level 1
#pragma optimization_level 2
/* measured: the level reset turns propagation back on, so the unit setting is reapplied. */
#pragma opt_propagation off

/* The supporter constructor allocates 0x14 bytes; its last word owns the script task. */
typedef struct FldSupporterWork {
    s32 state;
    s32 active;
    union { s32 timer; u32 timerBits; };
    s32 frame;
    s32 scriptTask;
} FldSupporterWork;
// Kept in bucket: diff 7 when moved; cause not diagnosed.
/* Run the support procedure after its delay, then wait for that script to finish. */
// FUN_0018DDE0
/* A separate support pointer is used for the remaining stores; timerBits keeps the timer store
 * unsigned so the elapsed subtraction wraps. */
s32 FldSupporterUpdate(u8 *task)
{
    u8 *work;
    s32 state;
    FldSupporterWork *support;

    work = (u8 *)((KwlnTask *)task)->work;
    support = (FldSupporterWork *)work;
    if ((((FldSupporterWork *)work)->active == 1))
        return 0;
    if (scrGetWorkCount() > 0)
        return 0;
    state = ((FldSupporterWork *)work)->state;
    switch (state) {
    default:
        break;
    case 0:
        ((FldSupporterWork *)work)->frame = D_0076428C;
        ((FldSupporterWork *)work)->state = ((FldSupporterWork *)work)->state + 1;
        /* fallthrough */
    case 1:
        if (((u32)D_0076428C - (u32)((FldSupporterWork *)work)->frame) > (u32)(((FldSupporterWork *)work)->timer)) {
            s32 size;

            size = iGpffffb278;
            ((FldSupporterWork *)work)->scriptTask = scrStartProcedureChecked(0xF, iGpffffb27c, size, 0);
            ((FldSupporterWork *)work)->state = 2;
            support->timerBits = 0x384U;
            support->frame = D_0076428C;
        }
        break;
    case 2:
        if (kwlnTaskIsLinked(((FldSupporterWork *)work)->scriptTask) == 1)
            return 0;
        support->scriptTask = 0;
        ((FldSupporterWork *)work)->frame = D_0076428C;
        ((FldSupporterWork *)work)->state = 1;
        break;
    case 3:
        return -1;
    }
    return 0;
}

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
/* Unlike FldFrame, the map-test work places its cell array at +0x2C. */
typedef struct MapTestGrid {
    u8 header[0x2C];
    FldFrameCell cells[24][16];
} MapTestGrid;

/* Rotation preserves a 0x56-byte pattern: 3-byte flag rows and 12-byte attribute rows. */
typedef struct FldMapShapeAttribute {
    u8 exits;
    u8 unk1;
    u8 pad2[2];
} FldMapShapeAttribute;
typedef struct FldMapShape {
    s8 type;
    u8 width;
    u8 height;
    u8 pad3[0xA];
    u8 flags[3][3];
    u8 pad16[0x1C];
    FldMapShapeAttribute attributes[3][3];
} FldMapShape;

/* k_maptest.c: dungeon map generation test. The input image holds the button halfword; the map uses
 * 16-byte cells and RGBA colors. */
// FUN_0018F7B0
/* Fill the unoccupied cells of a rotated map-test shape at (x, y). Cell rows are 0x100 bytes;
 * pattern flags and attributes use different strides. */
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
    FldMapShape *shape;

    pattern = (u8 *)shapeData;
    shape = (FldMapShape *)pattern;
    occupied = (rotation == rotation);
    originAddress = (x) * 0x10 + (((y) << 8) + (s32)grid);
    ((FldFrameCell *)(originAddress + 0x2C))->flags = occupied;
    rowIndex = 0;
    while (rowIndex < (s32)shape->height) {
        columnIndex = 0;
        rowAddress = originAddress + (rowIndex << 8);
        flagsAddress = (s32)pattern + rowIndex * 3;
        sourceRowAddress = (s32)pattern + rowIndex * 12;
        while (columnIndex < (s32)shape->width) {
            cellAddress = rowAddress + (columnIndex << 4);
            if (((FldFrameCell *)(cellAddress + 0x2C))->occupied == 0) {
                ((FldFrameCell *)(cellAddress + 0x2C))->occupied = occupied;
                ((MapTestGrid *)cellAddress)->cells[0][0].flags |= ((FldMapShape *)(flagsAddress + columnIndex))->flags[0][0];
                sourceAddress = sourceRowAddress + (columnIndex << 2);
                ((MapTestGrid *)cellAddress)->cells[0][0].exits = ((FldMapShape *)sourceAddress)->attributes[0][0].exits;
                ((MapTestGrid *)cellAddress)->cells[0][0].shapeX = shape->width;
                ((MapTestGrid *)cellAddress)->cells[0][0].shapeZ = shape->height;
                ((MapTestGrid *)cellAddress)->cells[0][0].type = shape->type;
                ((MapTestGrid *)cellAddress)->cells[0][0].kind = rotation;
                ((MapTestGrid *)cellAddress)->cells[0][0].unk0B = ((FldMapShape *)sourceAddress)->attributes[0][0].unk1;
            }
            columnIndex += 1;
        }
        rowIndex += 1;
    }
}
extern u16 D_008C0252[];
extern u16 D_008C0298[];
extern const KWindowEntryDescriptor D_005F5FD0[];
extern void kwlnSetColorRgba(u8 red, u8 green, u8 blue, u8 alpha);
extern s32 sdkLboxAddEntry(u8 *task, u8 *text);
extern u8 *FldStepLoadFilePair(s32 fieldId, s32 roomId);
extern s32 FldStepLoadHandleIsDone(u8 *handle);
extern void FldStepLoadHandleDestroy(u8 *handle);
extern s32 fldStepLoadHandleAlwaysReady(u8 *unusedHandle);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void FldTileRotateAttributes(void *templateData, u32 directionMask);
typedef struct {
    s16 data[0x2B];
} FieldPanelShape;
