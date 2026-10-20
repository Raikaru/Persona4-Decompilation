#include "member_access.h"
#include "rw_object_internal.h"
#include "rw_camera_internal.h"
#include "rw_frame_internal.h"
#include "resrc_manager_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdktask.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "field_frame_internal.h"
extern u8 D_00756510[];
extern s32 FldCharacterAnimSelect();
extern void func_003e0f40();
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1B18[];
extern u8 D_005F1B28[];
extern u8 D_005F1CF0[];
extern f32 iGpffffba6c;
extern void chkmemAllocSiteTag(const void *file, s32 line);

extern s32 kwlnGetCamera(void);
extern s32 FldAI_ChaserUpdate(u8 *);
extern s32 FldAI_PatrolUpdate(u8 *);
extern u8 *D_007EFA00[];
extern s32 iGpffffb25c;
extern u8 *iGpffffb2c8;
extern s32 K_FldEvent_IsPosWithinFov(u8 *, u8 *, f32 );
extern s32 K_FldEvent_ArePosWithinDist(u8 *, u8 *, f32 );
extern s32 FldFrame_RaycastField(const RwV3d *line, RwV3d *hitPointDst);
extern f32 RwV3dLength(f32 *);
extern u8 *mdlGetMatrix(u8 *);

typedef RwV3d FldAIVec3;
typedef struct { f32 x, y, z, w; } FldAIVec4;
typedef struct {
    FldAIVec3 right; u32 flags;
    FldAIVec3 up; u32 pad1c;
    FldAIVec3 forward; u32 pad2c;
    FldAIVec3 pos; u32 pad3c;
} FldAIMatrix;
typedef struct {
    u8 unk00[0x40];
    u32 flags;
    u32 unk44;
    s32 used;
    u32 unk4c;
    u8 *model;
    u8 *movement;
    u8 unk58[0x144];
    FldAIVec3 origin;
    u8 pad1a8[8];
    u8 *chaserTask;              /* 0x1B0 */
    u8 pad1b4[0x14];
    u16 configIndex;
    u8 kind;
    u8 heightSlot;
    u8 pad1cc[4];
    u8 historyActive[64];        /* 0x1D0 */
    struct { f32 x, z; } historySamples[64]; /* 0x210 */
    u8 pad410[0x300];
    s32 historyIndex;            /* 0x710 */
    u8 pad714[0x14];
    u16 animationId;             /* 0x728 */
    u8 pad72a[0x12];
    s32 unk73c;
    u8 pad740[0x10];
} FldAINpc;

/* Partial model/attachment layouts used by patrol alpha propagation; unknown tails are not modeled. */
typedef struct FldAIModelEffect {
    u8 pad00[8];
    void *effect;
    u8 pad0c[4];
    struct FldAIModelEffect *next;
} FldAIModelEffect;

typedef struct FldAIModel {
    u8 pad00[0xD8];
    u32 flags;
    u8 paddc[0x1F0];
    FldAIModelEffect **effects; /* 0x2CC */
} FldAIModel;

/* Follower work is the 0x74-byte allocation in FldAI_SpawnChaser. */
typedef struct FldAIChaserWork {
    s32 state;
    s32 paused;
    s32 positioned;
    s32 movementEnabled;
    union { s32 follower; u8 *followerPtr; };
    union { s32 leader; u8 *leaderPtr; };
    s32 formation;
    s32 previousFormation;
    s32 followerIndex;
    f32 visibleDistance;
    f32 visibleAngle;
    s32 neighborCount;
    FldAIVec3 positionSum;
    FldAIVec3 forwardSum;
    s32 lateralDirection;
    s32 unk4c;
    union { s32 transform; u8 *transformPtr; };
    u8 pad54[4];
    s32 unk58;
    s32 unk5c;
    s32 idleFrames;
    f32 cameraNearPlane;
    s32 cameraNear;
    union { s32 fadeTask; u8 *fadeTaskPtr; KwlnTask *fadeTaskHandle; };
    u8 pad70[4];
} FldAIChaserWork;


typedef struct {
    FldAIVec3 max;
    FldAIVec3 min;
} FldAIPatrolBounds;

/* The patrol constructor allocates 0xA0 bytes; bounds samples share this work. */
typedef struct FldAIPatrolWork {
    s32 state;
    s32 paused;
    s32 behavior;
    s32 actor;
    s32 transform;
    s32 config;
    FldAIVec3 boundsMax;
    FldAIVec3 boundsMin;
    FldAIVec3 alternateMax;
    FldAIVec3 alternateMin;
    s32 boundsIndex;
    s32 sampleStep;
    FldAIVec3 destination;
    s32 walkCount;
    s32 speedFrames;
    s32 fastWalk;
    f32 speed;
    f32 targetSpeed;
    union { s32 word; f32 value; } accumulatedTurn;
    union { s32 word; f32 value; } turnDirection;
    union { s32 word; f32 value; } weavePhase;
    f32 alpha;
    f32 cameraNearPlane;
    f32 fadeDistance;
    union { s32 fadeTask; u8 *fadeTaskPtr; KwlnTask *fadeTaskHandle; };
    s32 timer;
    s32 returnDelay;
    s32 approachFrames;
    s32 axesTask;
    u8 pad9c[4];
} FldAIPatrolWork;

/* Each kind/config pair selects one 0x40-byte record in the AI table. */
typedef struct FldAIConfig {
    f32 returnDistance;
    f32 sightAngle;
    f32 sightDistance;
    f32 fieldOfView;
    f32 visibleDistance;
    f32 nearbyDistance;
    f32 walkSpeed;
    f32 fastWalkSpeed;
    f32 chaseSpeed;
    f32 unk24;
    f32 approachSpeed;
    s32 hiddenFrames;
    s32 noticeFrames;
    s32 returnFrames;
    u8 pad38[8];
} FldAIConfig;

typedef char FldAINpcSize[sizeof(FldAINpc) == 0x750 ? 1 : -1];
typedef char FldAIChaserWorkSize[sizeof(FldAIChaserWork) == 0x74 ? 1 : -1];
typedef char FldAIPatrolWorkSize[sizeof(FldAIPatrolWork) == 0xA0 ? 1 : -1];
typedef char FldAIConfigSize[sizeof(FldAIConfig) == 0x40 ? 1 : -1];

extern u8 D_005F1B40[];
extern u8 D_005F1B4C[];

extern s32 *MT_Scene_GetFrameState(void);

/* Field follower update. Readiness is a byte predicate; model-slot and
 * history addresses keep their storage boundaries. Position providers write
 * complete XYZ objects, and each model query keeps its native pointer ABI.
 */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
typedef union FldFollowerPositionOutput {
    RwV3d value;
    u8 bytes[sizeof(RwV3d)];
} FldFollowerPositionOutput;

static inline u8 *fldFollowerStorageOffset(u32 offset, u8 *entry)
{
    return (u8 *)(offset + (uintptr_t)entry);
}

static inline u8 **fldFollowerModelSlot(u8 *entry)
{
    return (u8 **)&((FldAINpc *)entry)->model;
}

/* Earlier whole-layout probe: 5392/5248 bytes. Named MEMBER accesses keep the independently measured alias-sensitive sites. */
// FUN_0017D3C0
s32 FldAI_ChaserUpdate(u8 *task)
{
    struct RwFrame;
    struct RwMatrix;
    extern u8 D_007EF9B0[];
    extern u32 iGpffff9f58;
    extern f32 iGpffff84e0;
    extern f32 iGpffff830c;
    extern f32 iGpffff82fc;
    extern u8 D_00756510[];
    extern void *func_003e0f80(void);
    extern struct RwMatrix *func_003e9700(struct RwFrame *);
    extern f32 RwV3dNormalize(RwV3d *, const RwV3d *);
    extern f32 FldEvent_GetVisibleDistance(const struct RwMatrix *, const RwV3d *, f32, f32, f32);
    extern f32 FldEvent_GetMoveStep(void);
    extern f32 func_0044b920(f32);
    extern s32 KMisc_CreateRmdFade(s32, s32, s32, s32, s32);
    extern s32 KDraw_IsEffectDone(u8 *);
    extern s32 FldFrameTask_GetTileX(u8 *);
    extern s32 FldFrameTask_GetTileZ(u8 *);
    extern void FldFrameTask_ClearFlags(u8 *, s32);
    extern void FldFrameTask_GetPosition(u8 *, u8 *);
    extern void FldFrameTask_SetPosition(u8 *, u8 *);
    extern void FldFrameTask_StartMove(u8 *, f32);
    extern void FldFrameTask_Rotate(u8 *, const void *, f32);
    extern s32 FldCharacterAnimSelect(s32);
    extern s32 FldMoveAnimSecondary(s32);
    extern s32 FldAI_ChaserGetState(u8 *);
    extern u32 RpRandom(void);
    extern void *memset(void *, int, size_t);
    extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *);
    extern void kAssertFail(const void *, s32);
    extern s16 mdlGetLayerAnimation(s32, s32);
    extern void mdlSetColor(void *, const void *);
    extern void mdlSetAlphaBlend(void *);
    extern void mdlClearAlphaBlend(void *);

    u8 *work;
    u8 *entry;
    u8 *matrix;
    s32 index;
    s32 active;
    s32 tileX;
    s32 tileZ;
    s32 historyIndex;
    s32 action;
    s32 currentAnimation;
    s32 desiredAnimation;
    f32 distance;
    f32 speed;
    f32 turn;
    f32 limit;
    f32 ratio;
    f32 dot;
    f32 turnAmount;
    RwV3d selfForward;
    RwV3d selfRight;
    RwV3d separation;
    RwV3d leaderDelta;
    RwV3d offset;
    RwV3d leaderRight;
    RwV3d focusPosition;
    RwV3d cameraDelta;
    RwV3d cameraPosition;
    RwV3d historyDelta;
    FldFollowerPositionOutput historyPoint;
    FldFollowerPositionOutput selfPosition;

    work = ((SdkTask *)task)->work;
    speed = 0.0f;
    turn = 0.0f;
    if (((FldAIChaserWork *)work)->paused == 1)
        return 0;
    {
        s32 firstUsed;
        s32 secondUsed;
        u8 firstReady;
        u8 secondReady;
        firstUsed = 0;
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        entry = MEMBER(u8 *, work, FldAIChaserWork, followerPtr); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
        if (((FldAINpc *)entry)->used == 0)
            goto firstAvailabilityDone;
        if ((void *)((FldAINpc *)entry)->movement == NULL)
            goto firstAvailabilityDone;
        firstUsed = 1;
firstAvailabilityDone:
        firstReady = firstUsed != 0;
        if (firstReady == 0)
            goto unavailable;
        secondUsed = 0;
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        entry = MEMBER(u8 *, work, FldAIChaserWork, leaderPtr); /* measured: FldAIChaserWork.leaderPtr: local nd3650; MEMBER retains reload behavior. */
        if (((FldAINpc *)entry)->used == 0)
            goto secondAvailabilityDone;
        if ((void *)((FldAINpc *)entry)->movement == NULL)
            goto secondAvailabilityDone;
        secondUsed = 1;
secondAvailabilityDone:
        secondReady = secondUsed != 0;
        if (secondReady != 0)
            goto available;
unavailable:
        return 0;
available:
        ;
    }

    switch (((FldAIChaserWork *)work)->state) {
    case 0: {
        s32 discoveryIndex;
        s32 discoveryAvailable;
        u8 discoveryReady;
        u8 *discoveryEntry;
        ((FldAIChaserWork *)work)->transformPtr = func_003e0f80();
        for (discoveryIndex = 0; discoveryIndex < 4; discoveryIndex++) {
            discoveryAvailable = 0;
            discoveryEntry = D_007EF9B0 + discoveryIndex * 0x750;
            if (((FldAINpc *)discoveryEntry)->used == 0)
                goto discoveryAvailabilityDone;
            if ((void *)((FldAINpc *)discoveryEntry)->movement == NULL)
                goto discoveryAvailabilityDone;
            discoveryAvailable = 1;
discoveryAvailabilityDone:
            discoveryReady = discoveryAvailable != 0;
            if (discoveryReady && (u8 *)((FldAIChaserWork *)work)->follower == discoveryEntry)
                break;
        }
        if (discoveryIndex >= 4)
            kAssertFail(D_005F1B18, 0x97);
        ((FldAIChaserWork *)work)->followerIndex = discoveryIndex;
        ((FldAIChaserWork *)work)->visibleDistance = 2800.0f;
        ((FldAIChaserWork *)work)->visibleAngle = 360.0f;
        ((FldAIChaserWork *)work)->unk58 = 0;
        ((FldAIChaserWork *)work)->unk5c = 0;
        ((FldAIChaserWork *)work)->unk4c = -1;
        ((FldAIChaserWork *)work)->state += 1;
        break;

    }
    case 1:
        tileX = FldFrameTask_GetTileX((u8 *)((ResrcRecord *)D_007EFA00[1])->handle220);
        tileZ = FldFrameTask_GetTileZ((u8 *)((ResrcRecord *)D_007EFA00[1])->handle220);
        {
            struct RwFrame *frame = (struct RwFrame *)((struct RwCamera *)(u8 *)(u32)kwlnGetCamera())->object.object.parent;
            FldFrameTask_GetPosition(selfPosition.bytes,
                /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                (u8 *)((ResrcRecord *)(((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->movement))->handle220); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            focusPosition = *(RwV3d *)selfPosition.bytes;
            focusPosition.y += 180.0f;
            matrix = (u8 *)func_003e9700(frame);
            cameraPosition = ((FldAIMatrix *)matrix)->pos;
        }
        cameraDelta.x = focusPosition.x - cameraPosition.x;
        cameraDelta.y = focusPosition.y - cameraPosition.y;
        cameraDelta.z = focusPosition.z - cameraPosition.z;
        distance = RwV3dLength(&cameraDelta.x);
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        if (MEMBER(u8 *, work, FldAIChaserWork, fadeTaskPtr) != NULL && KDraw_IsEffectDone((u8 *)((FldAIChaserWork *)work)->fadeTask) == 1) { /* measured: FldAIChaserWork.fadeTaskPtr: local nd3287; MEMBER retains reload behavior. */
            mdlClearAlphaBlend(((ResrcRecord *)(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->movement))->modelHandle164);
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            kwlnTaskDestroyWithHierarchy(MEMBER(KwlnTask *, work, FldAIChaserWork, fadeTaskHandle)); /* measured: FldAIChaserWork.fadeTaskHandle: local nd3281; MEMBER retains reload behavior. */
            MEMBER(u8 *, work, FldAIChaserWork, fadeTaskPtr) = NULL; /* measured: FldAIChaserWork.fadeTaskPtr: local nd3287; MEMBER retains reload behavior. */
        }
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        if (distance <= 110.0f + MEMBER(f32, work, FldAIChaserWork, cameraNearPlane)) { /* measured: FldAIChaserWork.cameraNearPlane: local nd3199; MEMBER retains reload behavior. */
            if ((u8 *)((FldAIChaserWork *)work)->fadeTask != NULL) {
                mdlClearAlphaBlend(((ResrcRecord *)(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->movement))->modelHandle164);
                /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                kwlnTaskDestroyWithHierarchy(MEMBER(KwlnTask *, work, FldAIChaserWork, fadeTaskHandle)); /* measured: FldAIChaserWork.fadeTaskHandle: local nd3281; MEMBER retains reload behavior. */
                MEMBER(u8 *, work, FldAIChaserWork, fadeTaskPtr) = NULL; /* measured: FldAIChaserWork.fadeTaskPtr: local nd3287; MEMBER retains reload behavior. */
            }
            mdlSetColor(((ResrcRecord *)(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->movement))->modelHandle164, &iGpffff9f58);
            ((FldAIChaserWork *)work)->cameraNear = 1;
        }
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        if (MEMBER(s32, work, FldAIChaserWork, cameraNear) == 1 && !(distance <= 110.0f + ((FldAIChaserWork *)work)->cameraNearPlane)) { /* measured: FldAIChaserWork.cameraNear: local nd3181; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            mdlSetAlphaBlend(((ResrcRecord *)(((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->movement))->modelHandle164); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            ((FldAIChaserWork *)work)->fadeTask = KMisc_CreateRmdFade((s32)task,
                ((ResrcRecord *)(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->movement))->modelHandle164Value, 0, 255, 10);
            ((FldAIChaserWork *)work)->cameraNear = 0;
        }
        if (!(FldEvent_GetMoveStep() <= 0.0f))
            ((FldAIChaserWork *)work)->movementEnabled = 1;
        if (((FldAIChaserWork *)work)->movementEnabled == 0) {
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            currentAnimation = (s16)mdlGetLayerAnimation((s32)((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->model, 0); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            desiredAnimation = FldCharacterAnimSelect(((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->animationId); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            if (currentAnimation != desiredAnimation) {
                /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                desiredAnimation = (s16)FldCharacterAnimSelect(((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->animationId); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                mdlDispatchAnimIfPresent(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->model, 0, (s16)desiredAnimation, 0, 1);
            }
            break;
        }
        {
            if (((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 2 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 9 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 10 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 11 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 12 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 13 ||
                ((FldFrame *)MT_Scene_GetFrameState())->cells[tileZ][tileX].type == 14) {
                ((FldAIChaserWork *)work)->unk58 = 0;
                ((FldAIChaserWork *)work)->unk5c = 0;
                ((FldAIChaserWork *)work)->unk4c = -1;
                FldFrameTask_ClearFlags((u8 *)((ResrcRecord *)((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->movement)->handle220, 1);
                MEMBER(s32, work, FldAIChaserWork, formation) = 1; /* measured: FldAIChaserWork.formation: local nd2762; MEMBER retains reload behavior. */
                /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                if (MEMBER(s32, work, FldAIChaserWork, previousFormation) != MEMBER(s32, work, FldAIChaserWork, formation)) { /* measured: FldAIChaserWork.previousFormation: local nd2755; FldAIChaserWork.formation: local nd2762; MEMBER retains reload behavior. */
                    u32 random = RpRandom() & 1;
                    u8 *otherTask = ((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->leader)->chaserTask;
                    if (otherTask != NULL) {
                        if (random != 0) {
                            action = FldAI_ChaserGetState(otherTask);
                            if (action > 0) ((FldAIChaserWork *)work)->lateralDirection = -1;
                            else if (action < 0) ((FldAIChaserWork *)work)->lateralDirection = 1;
                            else ((FldAIChaserWork *)work)->lateralDirection = 0;
                        } else ((FldAIChaserWork *)work)->lateralDirection = 0;
                    } else if (random != 0) ((FldAIChaserWork *)work)->lateralDirection = 1;
                    else ((FldAIChaserWork *)work)->lateralDirection = -1;
                    ((FldAIChaserWork *)work)->previousFormation = ((FldAIChaserWork *)work)->formation;
                }
            } else {
                MEMBER(s32, work, FldAIChaserWork, formation) = 0; /* measured: FldAIChaserWork.formation: local nd2762; MEMBER retains reload behavior. */
                /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                if (MEMBER(s32, work, FldAIChaserWork, previousFormation) != MEMBER(s32, work, FldAIChaserWork, formation)) { /* measured: FldAIChaserWork.previousFormation: local nd2755; FldAIChaserWork.formation: local nd2762; MEMBER retains reload behavior. */
                    u32 random = RpRandom() & 1;
                    u8 *otherTask = ((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->leader)->chaserTask;
                    if (otherTask != NULL) {
                        if (random != 0) {
                            action = FldAI_ChaserGetState(otherTask);
                            if (action > 0) ((FldAIChaserWork *)work)->lateralDirection = -1;
                            else if (action < 0) ((FldAIChaserWork *)work)->lateralDirection = 1;
                            else ((FldAIChaserWork *)work)->lateralDirection = 0;
                        } else ((FldAIChaserWork *)work)->lateralDirection = 0;
                    } else if (random != 0) ((FldAIChaserWork *)work)->lateralDirection = 1;
                    else ((FldAIChaserWork *)work)->lateralDirection = -1;
                    ((FldAIChaserWork *)work)->previousFormation = ((FldAIChaserWork *)work)->formation;
                }
            }
        }
        MEMBER(s32, work, FldAIChaserWork, formation) = 0; /* measured: FldAIChaserWork.formation: local nd2762; MEMBER retains reload behavior. */
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        matrix = mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
        selfForward = ((FldAIMatrix *)matrix)->forward;
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        matrix = mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
        selfRight = ((FldAIMatrix *)matrix)->right;
        RwV3dNormalize(&selfForward, &selfForward);
        RwV3dNormalize(&selfRight, &selfRight);
        memset(work + 0x30, 0, 12);
        memset(work + 0x3C, 0, 12);
        MEMBER(s32, work, FldAIChaserWork, neighborCount) = 0; /* measured: FldAIChaserWork.neighborCount: local nd3680; MEMBER retains reload behavior. */
        for (index = 0; index < 4; index++) {
            s32 neighborActive;
            u8 neighborReady;
            neighborActive = 0;
            entry = D_007EF9B0 + index * 0x750;
            if (((FldAINpc *)entry)->used == 0)
                goto neighborAvailabilityDone;
            if ((void *)((FldAINpc *)entry)->movement == NULL)
                goto neighborAvailabilityDone;
            neighborActive = 1;
neighborAvailabilityDone:
            neighborReady = neighborActive != 0;
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            if (neighborReady && MEMBER(u8 *, work, FldAIChaserWork, followerPtr) != entry) { /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                u8 **otherModel = fldFollowerModelSlot(entry);
                f32 candidate = FldEvent_GetVisibleDistance(
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    (const struct RwMatrix *)mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model), /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                    (const RwV3d *)&((FldAIMatrix *)mdlGetMatrix(*otherModel))->pos,
                    ((FldAIChaserWork *)work)->visibleAngle, ((FldAIChaserWork *)work)->visibleDistance, 0.0f);
                if (!(candidate < 0.0f) && candidate <= 80.0f) {
                    u8 **nearbyModel = (u8 **)&((FldAINpc *)(D_007EF9B0 + (u32)index * 0x750u))->model;
                    f32 coordinate;
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    coordinate = ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.x; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                    separation.x = ((FldAIMatrix *)mdlGetMatrix(*nearbyModel))->pos.x - coordinate;
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    coordinate = ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.y; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                    separation.y = ((FldAIMatrix *)mdlGetMatrix(*nearbyModel))->pos.y - coordinate;
                    coordinate = ((FldAIMatrix *)mdlGetMatrix(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->model))->pos.z;
                    separation.z = ((FldAIMatrix *)mdlGetMatrix(*nearbyModel))->pos.z - coordinate;
                    RwV3dNormalize(&separation, &separation);
                    turnAmount = 800.0f / candidate;
                    speed = iGpffff84e0;
                    dot = separation.x * selfRight.x + separation.y * selfRight.y + separation.z * selfRight.z;
                    if (!(dot < 0.0f)) turnAmount *= -1.0f;
                    turn += turnAmount;
                }
                if ((u8 *)((FldAIChaserWork *)work)->leader == entry && !(candidate < 0.0f)) {
                    u8 **leaderModel = (u8 **)&((FldAINpc *)(D_007EF9B0 + (u32)index * 0x750u))->model;
                    ((FldAIChaserWork *)work)->positionSum.x += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->pos.x;
                    ((FldAIChaserWork *)work)->positionSum.y += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->pos.y;
                    ((FldAIChaserWork *)work)->positionSum.z += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->pos.z;
                    ((FldAIChaserWork *)work)->forwardSum.x += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->forward.x;
                    ((FldAIChaserWork *)work)->forwardSum.y += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->forward.y;
                    ((FldAIChaserWork *)work)->forwardSum.z += ((FldAIMatrix *)mdlGetMatrix(*leaderModel))->forward.z;
                    ((FldAIChaserWork *)work)->neighborCount += 1;
                }
            }
        }
        {
            f32 coordinate;
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            coordinate = ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, leaderPtr))->model)))->pos.x; /* measured: FldAIChaserWork.leaderPtr: local nd3650; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            leaderDelta.x = coordinate - ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.x; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            coordinate = ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, leaderPtr))->model)))->pos.y; /* measured: FldAIChaserWork.leaderPtr: local nd3650; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            leaderDelta.y = coordinate - ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.y; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            coordinate = ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, leaderPtr))->model)))->pos.z; /* measured: FldAIChaserWork.leaderPtr: local nd3650; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            leaderDelta.z = coordinate - ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.z; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
        }
        distance = RwV3dNormalize(&leaderDelta, &leaderDelta);
        if (FldEvent_GetMoveStep() <= 0.0f)
            goto idleDistance;
        limit = 400.0f;
        goto distanceChosen;
idleDistance:
        limit = 150.0f;
distanceChosen:
        if (!(distance <= limit)) {
            ratio = distance / limit;
            if (!(ratio <= 1.0f)) ratio = 1.0f;
            speed += iGpffff830c * ratio;
        }
        if (((FldAIChaserWork *)work)->neighborCount > 0) {
            memset(&offset, 0, sizeof(offset));
            if (((FldAIChaserWork *)work)->formation == 0) {
                matrix = mdlGetMatrix(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->leader)->model);
                leaderRight = ((FldAIMatrix *)matrix)->right;
                RwV3dNormalize(&leaderRight, &leaderRight);
                switch (((FldAIChaserWork *)work)->followerIndex) {
                case 1:
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    if (MEMBER(s32, work, FldAIChaserWork, lateralDirection) < 0) { /* measured: FldAIChaserWork.lateralDirection: local nd1595; MEMBER retains reload behavior. */
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (((FldAIChaserWork *)work)->lateralDirection != 0) {
                        offset.x = 100.0f * leaderRight.x;
                        offset.y = 100.0f * leaderRight.y;
                        offset.z = 100.0f * leaderRight.z;
                    }
                    break;
                case 2:
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    if (MEMBER(s32, work, FldAIChaserWork, lateralDirection) < 0) { /* measured: FldAIChaserWork.lateralDirection: local nd1595; MEMBER retains reload behavior. */
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (((FldAIChaserWork *)work)->lateralDirection != 0) {
                        offset.x = 100.0f * leaderRight.x;
                        offset.y = 100.0f * leaderRight.y;
                        offset.z = 100.0f * leaderRight.z;
                    }
                    break;
                case 3:
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    if (MEMBER(s32, work, FldAIChaserWork, lateralDirection) < 0) { /* measured: FldAIChaserWork.lateralDirection: local nd1595; MEMBER retains reload behavior. */
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (((FldAIChaserWork *)work)->lateralDirection != 0) {
                        offset.x = 100.0f * leaderRight.x;
                        offset.y = 100.0f * leaderRight.y;
                        offset.z = 100.0f * leaderRight.z;
                    }
                    break;
                default:
                    kAssertFail(D_005F1B18, 0x19F);
                    break;
                }
            } else {
                matrix = mdlGetMatrix(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->leader)->model);
                leaderRight = ((FldAIMatrix *)matrix)->right;
                RwV3dNormalize(&leaderRight, &leaderRight);
                switch (((FldAIChaserWork *)work)->followerIndex) {
                case 1:
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    if (MEMBER(s32, work, FldAIChaserWork, lateralDirection) < 0) { /* measured: FldAIChaserWork.lateralDirection: local nd1595; MEMBER retains reload behavior. */
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (((FldAIChaserWork *)work)->lateralDirection != 0) {
                        offset.x = 50.0f * leaderRight.x;
                        offset.y = 50.0f * leaderRight.y;
                        offset.z = 50.0f * leaderRight.z;
                    }
                    break;
                case 2:
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    if (MEMBER(s32, work, FldAIChaserWork, lateralDirection) < 0) { /* measured: FldAIChaserWork.lateralDirection: local nd1595; MEMBER retains reload behavior. */
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (((FldAIChaserWork *)work)->lateralDirection != 0) {
                        offset.x = 50.0f * leaderRight.x;
                        offset.y = 50.0f * leaderRight.y;
                        offset.z = 50.0f * leaderRight.z;
                    }
                    break;
                case 3:
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    if (MEMBER(s32, work, FldAIChaserWork, lateralDirection) < 0) { /* measured: FldAIChaserWork.lateralDirection: local nd1595; MEMBER retains reload behavior. */
                        leaderRight.x = -leaderRight.x;
                        leaderRight.y = -leaderRight.y;
                        leaderRight.z = -leaderRight.z;
                    }
                    if (((FldAIChaserWork *)work)->lateralDirection != 0) {
                        offset.x = 50.0f * leaderRight.x;
                        offset.y = 50.0f * leaderRight.y;
                        offset.z = 50.0f * leaderRight.z;
                    }
                    break;
                default:
                    kAssertFail(D_005F1B18, 0x1B6);
                    break;
                }
            }
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            offset.x += ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.x; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            offset.y += ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.y; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            offset.z += ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.z; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            MEMBER(f32, work, FldAIChaserWork, positionSum.x) += offset.x; /* measured: FldAIChaserWork.positionSum.x: local nd904; MEMBER retains reload behavior. */
            MEMBER(f32, work, FldAIChaserWork, positionSum.y) += offset.y; /* measured: FldAIChaserWork.positionSum.y: local nd891; MEMBER retains reload behavior. */
            MEMBER(f32, work, FldAIChaserWork, positionSum.z) += offset.z; /* measured: FldAIChaserWork.positionSum.z: local nd878; MEMBER retains reload behavior. */
            MEMBER(f32, work, FldAIChaserWork, positionSum.x) /= (f32)(((FldAIChaserWork *)work)->neighborCount + 1); /* measured: FldAIChaserWork.positionSum.x: local nd904; MEMBER retains reload behavior. */
            MEMBER(f32, work, FldAIChaserWork, positionSum.y) /= (f32)(((FldAIChaserWork *)work)->neighborCount + 1); /* measured: FldAIChaserWork.positionSum.y: local nd891; MEMBER retains reload behavior. */
            MEMBER(f32, work, FldAIChaserWork, positionSum.z) /= (f32)(((FldAIChaserWork *)work)->neighborCount + 1); /* measured: FldAIChaserWork.positionSum.z: local nd878; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            separation.x = ((FldAIChaserWork *)work)->positionSum.x - ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.x; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            separation.y = ((FldAIChaserWork *)work)->positionSum.y - ((FldAIMatrix *)(mdlGetMatrix(((FldAINpc *)MEMBER(u8 *, work, FldAIChaserWork, followerPtr))->model)))->pos.y; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            separation.z = ((FldAIChaserWork *)work)->positionSum.z - ((FldAIMatrix *)mdlGetMatrix(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->model))->pos.z;
            RwV3dNormalize(&separation, &separation);
            dot = selfForward.x * separation.x + selfForward.y * separation.y + selfForward.z * separation.z;
            if (dot < 1.0f) {
                turnAmount = 20.0f * func_0044b920(dot) / iGpffff82fc;
                if (1.0f - dot < turnAmount / 180.0f) turnAmount = 180.0f * (1.0f - dot);
                ratio = separation.x * selfRight.x + separation.y * selfRight.y + separation.z * selfRight.z;
                if (ratio < 0.0f) turnAmount *= -1.0f;
                turn += turnAmount;
            }
        }
        if (distance <= 2800.0f)
            goto moveFollower;
        if (((FldAIChaserWork *)work)->positioned != 0)
            goto moveFollower;
            matrix = mdlGetMatrix((u8 *)((ResrcRecord *)D_007EFA00[1])->modelHandle164);
            FldFrameTask_SetPosition((u8 *)((ResrcRecord *)((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->movement)->handle220, matrix + 0x30);
            ((FldAIChaserWork *)work)->unk4c = -1;
            ((FldAIChaserWork *)work)->unk58 = 0;
            ((FldAIChaserWork *)work)->unk5c = 0;
        goto movementComplete;
moveFollower:
        {
            active = 0;
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            historyIndex = ((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->historyIndex - 1; /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            if (turn != 0.0f && speed != 0.0f)
                FldFrameTask_Rotate((u8 *)((ResrcRecord *)((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->movement)->handle220, D_00756510, turn);
            if (speed != 0.0f)
                FldFrameTask_StartMove((u8 *)((ResrcRecord *)((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->movement)->handle220, speed);
            if (historyIndex < 0) historyIndex = 63;
            /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
            entry = MEMBER(u8 *, work, FldAIChaserWork, followerPtr); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
            if (((FldAINpc *)fldFollowerStorageOffset(historyIndex, entry))->historyActive[0] != 0) {
                FldFrameTask_GetPosition(historyPoint.bytes, (u8 *)((ResrcRecord *)((FldAINpc *)entry)->movement)->handle220);
                historyDelta = *(RwV3d *)historyPoint.bytes;
                {
                    u8 *historySample = fldFollowerStorageOffset(historyIndex * 8, ((FldAIChaserWork *)work)->followerPtr);
                    historyPoint.value.x = ((FldAINpc *)historySample)->historySamples[0].x;
                    historyPoint.value.z = ((FldAINpc *)historySample)->historySamples[0].z;
                }
                historyDelta.x = historyPoint.value.x - historyDelta.x;
                historyDelta.y = historyPoint.value.y - historyDelta.y;
                historyDelta.z = historyPoint.value.z - historyDelta.z;
                if (RwV3dLength(&historyDelta.x) < speed) active = 1;
            }
            if (speed == 0.0f || active == 1) {
                /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                if (MEMBER(s32, work, FldAIChaserWork, idleFrames) < 30) ((FldAIChaserWork *)work)->idleFrames += 1; /* measured: FldAIChaserWork.idleFrames: local nd242; MEMBER retains reload behavior. */
                else {
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    currentAnimation = (s16)mdlGetLayerAnimation((s32)((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->model, 0); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    desiredAnimation = FldCharacterAnimSelect(((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->animationId); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                    if (currentAnimation != desiredAnimation) {
                        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                        desiredAnimation = (s16)FldCharacterAnimSelect(((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->animationId); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                        mdlDispatchAnimIfPresent(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->model, 0, (s16)desiredAnimation, 16, 1);
                    }
                    ((FldAIChaserWork *)work)->idleFrames = 0;
                }
            } else {
                /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                currentAnimation = (s16)mdlGetLayerAnimation((s32)((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->model, 0); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                desiredAnimation = FldMoveAnimSecondary(((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->animationId); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                if (currentAnimation != desiredAnimation) {
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    desiredAnimation = (s16)FldMoveAnimSecondary(((FldAINpc *)(MEMBER(u8 *, work, FldAIChaserWork, followerPtr)))->animationId); /* measured: FldAIChaserWork.followerPtr: local nd3647; MEMBER retains reload behavior. */
                    mdlDispatchAnimIfPresent(((FldAINpc *)(u8 *)((FldAIChaserWork *)work)->follower)->model, 0, (s16)desiredAnimation, 8, 1);
                    ((FldAIChaserWork *)work)->idleFrames = 0;
                }
            }
        }
movementComplete:
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        if (MEMBER(s32, work, FldAIChaserWork, positioned) == 0) ((FldAIChaserWork *)work)->positioned = 1; /* measured: FldAIChaserWork.positioned: local nd59; MEMBER retains reload behavior. */
        break;
    case 2:
    default:
        break;
    }
    return 0;
}


#pragma pop
/* Release the follower transform and task-owned work. */
/* measured: the final task-work reload requires MEMBER to preserve callback aliasing. */
// FUN_0017E840
void FldAI_ChaserDestroy(u8 *task) {
    s32 h = ((FldAIChaserWork *)(((SdkTask *)task)->work))->transform;

    if (h != 0) {
        func_003e0f40(h);
    }
    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
    jtbl_008873EC[0](MEMBER(void *, task, SdkTask, work)); /* measured: SdkTask.work: local nd5; MEMBER retains reload behavior. */
}

/* Create a follower controller linking a follower actor to its leader. */
/* Access-site fields are typed below; individual remaining exceptions carry their measurements. */
// FUN_0017E890
s32 FldAI_SpawnChaser(s32 parent, s32 follower, s32 leader)
{
    s32 ret;
    u8 *work;

    chkmemAllocSiteTag(D_005F1B18, 0x3D9);
    work = D_008873F4[0](1, 0x74, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F1B28), 0xF, 0, 0, FldAI_ChaserUpdate, FldAI_ChaserDestroy, (u8 *)(work));
    ((FldAIChaserWork *)work)->follower = follower;
    ((FldAIChaserWork *)work)->leader = leader;
    ((FldAIChaserWork *)work)->previousFormation = -1;
    ((FldAIChaserWork *)work)->cameraNearPlane = ((struct RwCamera *)(u8 *)(u32)kwlnGetCamera())->nearPlane;
    return ret;
}

/* Return the follower's selected lateral formation direction. */
/* The follower work exposes its lateral state at +0x48. */
// FUN_0017E980
s32 FldAI_ChaserGetState(u8 *task) {
    return ((FldAIChaserWork *)((SdkTask *)task)->work)->lateralDirection;
}

/* Enable follower movement processing. */
/* The follower work movement-enable word is +0x0C. */
// FUN_0017E990
void FldAI_ChaserEnable(u8 *task) {
    ((FldAIChaserWork *)((SdkTask *)task)->work)->movementEnabled = 1;
}

/* Restore the idle animation and stop follower movement processing. */
/* Access-site fields are typed below; individual remaining exceptions carry their measurements. */
// FUN_0017E9B0
void FldAI_ChaserDisable(u8 *task) {
    u8 *p = ((SdkTask *)task)->work;

    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
    mdlDispatchAnimIfPresent(((FldAINpc *)(MEMBER(u8 *, p, FldAIChaserWork, followerPtr)))->model, 0, /* measured: FldAIChaserWork.followerPtr: local nd75; MEMBER retains reload behavior. */
                  (s16)FldCharacterAnimSelect(((FldAINpc *)(u8 *)((FldAIChaserWork *)p)->follower)->animationId), 0, 1);
    ((FldAIChaserWork *)p)->movementEnabled = 0;
}

/* Measured near-match archived at object 808B/window 816B, normalized_diff 6.
 * The corrected func_003e4180(f32 *) declaration is required at this callsite.
 * Residual: retail orders ld 0x50(sp), lwc1 0x58(sp), sd 0x70(sp), while
 * MWCCPS2 emits ld, sd, lwc1, swc1 for the stack projection copy.
 * Probed scalar/aggregate copies, assignment reversal, temporary/comma and
 * shared-pointer staging, field-width variants, and volatile stack staging;
 * volatile reached nd0 but is rejected as an ordinary-memory claim. */
/* measured: the ld/lwc1/sd/swc1 projection copy is `out = ab[0]` between
   two FldAIVec3-typed locals (ab is a FldAIVec3[2], slot 0x50; out slot 0x70);
   ab[1] copies (0x5c, unaligned) are the three-lwc1 form. Casting f32 ab[6]
   to FldAIVec3 blinds the alignment and gives three lwc1 (nd290); the
   archive's {s64; f32} out type gives scalar order ld/sd/lwc1/swc1 (nd4). */
/* Test player visibility using configured distance/FOV limits and raycasts in both directions. */
/* Access-site fields are typed below; individual remaining exceptions carry their measurements. */
// FUN_0017EA10
s32 FldAI_ChaserCanSeeTarget(u8 *actor)
{
    FldAIVec3 separation;
    FldAIVec3 hitPoint;
    FldAIVec3 line[2];
    f32 selfCoordinate;
    s32 visible;
    u8 *config;
    u8 *selfMatrix;
    u8 *distanceMatrix;
    u8 *lineSource;
    u8 *lineDestination;

    visible = 0;
    config = iGpffffb2c8 + (((FldAINpc *)actor)->kind * 0x180) +
              (((FldAINpc *)actor)->configIndex << 6);
    if (iGpffffb25c == 1) {
        return 0;
    }
    if (((FldAINpc *)actor)->heightSlot == 0) {
        distanceMatrix = mdlGetMatrix(((FldAINpc *)actor)->model);
        if (K_FldEvent_ArePosWithinDist(distanceMatrix + 0x30,
                          mdlGetMatrix(D_007EFA00[0]) + 0x30,
                          ((FldAIConfig *)config)->nearbyDistance / 3.0f) == 1) {
            visible = 1;
        }
        return visible;
    }
    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
    lineSource = mdlGetMatrix(MEMBER(u8 *, actor, FldAINpc, model)); /* measured: FldAINpc.model: local nd543; MEMBER retains reload behavior. */
    line[0] = ((FldAIMatrix *)lineSource)->pos;
    lineDestination = mdlGetMatrix(D_007EFA00[0]);
    line[1] = ((FldAIMatrix *)lineDestination)->pos;
    line[0].y += 90.0f;
    line[1].y += 90.0f;
    if (FldFrame_RaycastField(line, &hitPoint) == 1) {
        return 0;
    }
    lineSource = (u8 *)line;
    lineDestination = (u8 *)&hitPoint;
    hitPoint = line[0];
    line[0] = line[1];
    line[1] = hitPoint;
    if (FldFrame_RaycastField((const RwV3d *)lineSource, (RwV3d *)lineDestination) == 1) {
        return 0;
    }
    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
    selfMatrix = mdlGetMatrix(MEMBER(u8 *, actor, FldAINpc, model)); /* measured: FldAINpc.model: local nd543; MEMBER retains reload behavior. */
    if (K_FldEvent_IsPosWithinFov(selfMatrix, mdlGetMatrix(D_007EFA00[0]) + 0x30,
                      ((FldAIConfig *)config)->fieldOfView) == 1) {
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        selfCoordinate = ((FldAIMatrix *)(mdlGetMatrix(MEMBER(u8 *, actor, FldAINpc, model))))->pos.x; /* measured: FldAINpc.model: local nd543; MEMBER retains reload behavior. */
        separation.x = ((FldAIMatrix *)mdlGetMatrix(D_007EFA00[0]))->pos.x - selfCoordinate;
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        selfCoordinate = ((FldAIMatrix *)(mdlGetMatrix(MEMBER(u8 *, actor, FldAINpc, model))))->pos.y; /* measured: FldAINpc.model: local nd543; MEMBER retains reload behavior. */
        separation.y = ((FldAIMatrix *)mdlGetMatrix(D_007EFA00[0]))->pos.y - selfCoordinate;
        selfCoordinate = ((FldAIMatrix *)mdlGetMatrix(((FldAINpc *)actor)->model))->pos.z;
        separation.z = ((FldAIMatrix *)mdlGetMatrix(D_007EFA00[0]))->pos.z - selfCoordinate;
        if (RwV3dLength((f32 *)&separation) < ((FldAIConfig *)config)->visibleDistance) {
            return 1;
        }
    }
    selfMatrix = mdlGetMatrix(((FldAINpc *)actor)->model);
    if (K_FldEvent_ArePosWithinDist(selfMatrix + 0x30,
                      mdlGetMatrix(D_007EFA00[0]) + 0x30,
                      ((FldAIConfig *)config)->nearbyDistance) == 1) {
        return 1;
    }
    return 0;
}

// FUN_0017ED40
/* Advance one of sixteen field-AI bounds samples. The ray query consumes
 * both endpoints, which must remain one contiguous two-vector array.
 * Steps 0-7 gather both bounds; later steps correct the selected x/z bound.
 * Measured b210 -O2: 1868/1872 bytes and seven resolved relocations.
 * Retained propagation preserves the copied vectors and centered coordinates.
 * Load each comparison value separately, and name the bound-array base before
 * each single-bound correction, to preserve the retail address lifetimes. */
#pragma push
#pragma opt_propagation off
/* Bounds are two max/min XYZ pairs at +0x18/+0x30; scaled integer cursors preserve the documented comparison/address lifetimes. */
s32 FldAI_AdvanceBoundsSample(u8 *work)
{
    FldAIVec3 hit;
    FldAIVec3 line[2];
    FldAIVec3 offsets[2];
    FldAIVec4 cell;
    f32 originZ;
    f32 originY;
    f32 originX;
    f32 endpointZ;
    f32 endpointX;
    s32 directionMask;
    s32 tableStep;
    s32 cachedStep;
    s32 axis;
    s32 result;
    s32 direction;
    u8 *unit;
    FldFrameCell *sourceCell;
    u8 *firstOffset;
    u8 *secondOffset;
    s32 cellX;
    s32 cellZ;

    result = 1;
    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
    if (MEMBER(s32, work, FldAIPatrolWork, sampleStep) < 0x10) { /* measured: FldAIPatrolWork.sampleStep: local nd1406; MEMBER retains reload behavior. */
        unit = (u8 *)((FldAIPatrolWork *)work)->actor;
        originX = ((FldAINpc *)unit)->origin.x;
        originY = ((FldAINpc *)unit)->origin.y;
        originZ = ((FldAINpc *)unit)->origin.z;
        line[0].x = originX;
        line[0].y = originY;
        line[0].z = originZ;
        line[1] = line[0];
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        cachedStep = MEMBER(s32, work, FldAIPatrolWork, sampleStep); /* measured: FldAIPatrolWork.sampleStep: local nd1406; MEMBER retains reload behavior. */
        if (cachedStep >= 4) {
            f32 centeredX = 600.0f + line[0].x;
            cellX = (s32)(centeredX / 1200.0f);
            cellZ = (s32)((600.0f + line[0].z) / 1200.0f);
            sourceCell = &((FldFrame *)MT_Scene_GetFrameState())->cells[cellZ][cellX];
            cell = *(FldAIVec4 *)sourceCell;
            cachedStep = ((FldAIPatrolWork *)work)->sampleStep;
            direction = cachedStep & 3;
            if ((cachedStep < 0) && (direction != 0)) {
                direction -= 4;
            }
            directionMask = 1 << direction;
            if ((((u8 *)&cell)[10] & directionMask) == 0 || ((((u8 *)&cell)[11] & directionMask) != 0)) {
                goto tail;
            }
        }
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        tableStep = (s32)MEMBER(u32, work, FldAIPatrolWork, sampleStep); /* measured: FldAIPatrolWork.sampleStep: local nd1415; MEMBER retains reload behavior. */
        firstOffset = D_005F1B40 + (tableStep * 0x18);
        offsets[0] = *(FldAIVec3 *)firstOffset;
        if ((tableStep >= 4) && (cachedStep < 8)) {
            if (offsets[0].x < 0.0f) {
                offsets[0].x = (1200.0f * (f32)(cellX - 1)) - line[0].x;
            } else if (!(offsets[0].x <= 0.0f)) {
                offsets[0].x = (1200.0f * (f32)(cellX + 1)) - line[0].x;
            }
            if (offsets[0].z < 0.0f) {
                offsets[0].z = (1200.0f * (f32)(cellZ - 1)) - line[0].z;
            } else if (!(offsets[0].z <= 0.0f)) {
                offsets[0].z = (1200.0f * (f32)(cellZ + 1)) - line[0].z;
            }
        }
        endpointX = line[0].x + offsets[0].x;
        line[0].x = endpointX;
        {
            f32 value = line[0].y + offsets[0].y;
            line[0].y = value;
        }
        endpointZ = line[0].z + offsets[0].z;
        line[0].z = endpointZ;
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        secondOffset = D_005F1B4C + (MEMBER(s32, work, FldAIPatrolWork, sampleStep) * 0x18); /* measured: FldAIPatrolWork.sampleStep: local nd1406; MEMBER retains reload behavior. */
        offsets[1] = *(FldAIVec3 *)secondOffset;
        {
            f32 value = line[1].x + offsets[1].x;
            line[1].x = value;
        }
        {
            f32 value = line[1].y + offsets[1].y;
            line[1].y = value;
        }
        {
            f32 value = line[1].z + offsets[1].z;
            line[1].z = value;
        }
        {
            f32 centeredX = 600.0f + endpointX;
            s32 endpointCellX = (s32)(centeredX / 1200.0f);
            s32 endpointCellZ = (s32)((600.0f + endpointZ) / 1200.0f);
            FldFrameCell *cellB = &((FldFrame *)MT_Scene_GetFrameState())->cells[endpointCellZ][endpointCellX];
            if (cellB->occupied == 1) {
                axis = 0;
                if (FldFrame_RaycastField(line, &hit) == 1) {
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    s32 hitStep = MEMBER(s32, work, FldAIPatrolWork, sampleStep); /* measured: FldAIPatrolWork.sampleStep: local nd1406; MEMBER retains reload behavior. */
                    if (hitStep >= 4) {
                        axis = hitStep & 1;
                        if ((hitStep < 0) && (axis != 0)) {
                            axis -= 2;
                        }
                    }
                    if (hitStep < 8) {
                        f32 *bounds = (f32 *)work;
                        {
                            f32 value = hit.x;
                            if (bounds[axis * 6 + 6] < value) {
                                bounds[axis * 6 + 6] = value;
                            }
                        }
                        {
                            f32 value = hit.y;
                            if (bounds[axis * 6 + 7] < value) {
                                bounds[axis * 6 + 7] = value;
                            }
                        }
                        {
                            f32 value = hit.z;
                            if (bounds[axis * 6 + 8] < value) {
                                bounds[axis * 6 + 8] = value;
                            }
                        }
                        {
                            f32 value = hit.x;
                            if (!(bounds[axis * 6 + 9] <= value)) {
                                bounds[axis * 6 + 9] = value;
                            }
                        }
                        {
                            f32 value = hit.y;
                            if (!(bounds[axis * 6 + 10] <= value)) {
                                bounds[axis * 6 + 10] = value;
                            }
                        }
                        {
                            f32 value = hit.z;
                            if (!(bounds[axis * 6 + 11] <= value)) {
                                bounds[axis * 6 + 11] = value;
                            }
                        }
                        if (((FldAIPatrolWork *)work)->sampleStep < 4) {
                            ((FldAIPatrolWork *)work)->alternateMax = ((FldAIPatrolWork *)work)->boundsMax;
                            ((FldAIPatrolWork *)work)->alternateMin = ((FldAIPatrolWork *)work)->boundsMin;
                        }
                    } else if (hitStep < 0xC) {
                        if (axis == 0) {
                            {
                                f32 *bounds = (f32 *)work;
                                f32 value = hit.x;
                                if (bounds[axis * 6 + 9] < value) {
                                    bounds[axis * 6 + 9] = value;
                                }
                            }
                        } else {
                            {
                                f32 *bounds = (f32 *)work;
                                f32 value = hit.z;
                                if (bounds[axis * 6 + 11] < value) {
                                    bounds[axis * 6 + 11] = value;
                                }
                            }
                        }
                    } else if (axis == 0) {
                        {
                            f32 *bounds = (f32 *)work;
                            f32 value = hit.x;
                            if (!(bounds[axis * 6 + 6] <= value)) {
                                bounds[axis * 6 + 6] = value;
                            }
                        }
                    } else {
                        {
                            f32 *bounds = (f32 *)work;
                            f32 value = hit.z;
                            if (!(bounds[axis * 6 + 8] <= value)) {
                                bounds[axis * 6 + 8] = value;
                            }
                        }
                    }
                } else {
                    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
                    s32 missStep = MEMBER(s32, work, FldAIPatrolWork, sampleStep); /* measured: FldAIPatrolWork.sampleStep: local nd1406; MEMBER retains reload behavior. */
                    if (missStep >= 4) {
                        axis = missStep & 1;
                        if ((missStep < 0) && (axis != 0)) {
                            axis -= 2;
                        }
                    }
                    if (missStep < 8) {
                        f32 *bounds = (f32 *)work;
                        {
                            f32 value = line[1].x;
                            if (bounds[axis * 6 + 6] < value) {
                                bounds[axis * 6 + 6] = value;
                            }
                        }
                        {
                            f32 value = line[1].y;
                            if (bounds[axis * 6 + 7] < value) {
                                bounds[axis * 6 + 7] = value;
                            }
                        }
                        {
                            f32 value = line[1].z;
                            if (bounds[axis * 6 + 8] < value) {
                                bounds[axis * 6 + 8] = value;
                            }
                        }
                        {
                            f32 value = line[1].x;
                            if (!(bounds[axis * 6 + 9] <= value)) {
                                bounds[axis * 6 + 9] = value;
                            }
                        }
                        {
                            f32 value = line[1].y;
                            if (!(bounds[axis * 6 + 10] <= value)) {
                                bounds[axis * 6 + 10] = value;
                            }
                        }
                        {
                            f32 value = line[1].z;
                            if (!(bounds[axis * 6 + 11] <= value)) {
                                bounds[axis * 6 + 11] = value;
                            }
                        }
                        if (((FldAIPatrolWork *)work)->sampleStep < 4) {
                            ((FldAIPatrolWork *)work)->alternateMax = ((FldAIPatrolWork *)work)->boundsMax;
                            ((FldAIPatrolWork *)work)->alternateMin = ((FldAIPatrolWork *)work)->boundsMin;
                        }
                    }
                }
            }
        }
tail:
        ((FldAIPatrolWork *)work)->sampleStep = ((FldAIPatrolWork *)work)->sampleStep + 1;
    } else {
        result = 0;
    }
    return result;
}

#pragma pop

/* Field NPC patrol, steering, visibility and player-approach state machine.
 * Match: fnalign 369 -> 0. Preserve phase-specific vector lifetimes and snapshots;
 * propagation/pullout stay off while CSE stays on for retail's shared constants. */
#pragma push
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma opt_pulloutconstants off
static inline f32 fldAIScale(f32 scale, f32 speed)
{
    return scale * speed;
}
static inline f32 fldAIAccumulateTurn(f32 *angle, f32 turn)
{
    f32 total = *angle + turn;
    *angle = total;
    return total;
}
extern u32 RpRandom(void);
extern void mdlSetColor(void *, const void *);
/* SDK vector normalization reads and writes complete three-float objects and
   returns their original length through the floating-point return register. */
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern unsigned char D_005F1CE0[];
extern float fGpffff80f0; /* 0xffff80f0 */
extern float fGpffff811c; /* 0xffff811c */
extern float fGpffff8218; /* 0xffff8218 */
extern float fGpffff825c; /* 0xffff825c */
extern float fGpffff8308; /* 0xffff8308 */
extern float iGpffff830c; /* 0xffff830c */
extern float fGpffff8310; /* 0xffff8310 */
extern int D_00764348; /* 0xffffb258 */
extern int iGpffffb310; /* 0xffffb310 */

struct RwFrame;
struct RwMatrix;
extern void *func_003e0f80(void);
extern struct RwMatrix *func_003e9700(struct RwFrame *);
extern f32 sinf(f32 angle);
extern void *mdlGetColor(void *);
extern int KMisc_CreateRmdFade(int, int, int, int, int);
extern int KDraw_IsEffectDone(unsigned char *);
extern unsigned int FldEvent_HasLineOfSight(void *, void *, float, float);
extern s32 KDraw_CreateAxesTask(void *, void *);
extern void FldRc_SetAxesTargeted(unsigned char *, int);
extern void FldRc_SetAxesColor(unsigned char *, unsigned char *);
extern void FldRc_SetAxesPosition(unsigned char *, unsigned char *);
extern int FldRc_RequestPositionSlot(unsigned char *, float *);
extern int FldStepFileTask(int);
extern void FldFrameTask_SetPosition(unsigned char *, unsigned char *);
extern void FldFrameTask_StartMove(unsigned char *, float);
extern void FldFrameTask_Rotate(u8 *task, const void *axis, f32 angle);
extern float FldEvent_GetMoveStep(void);
extern int kwlnTaskDestroyWithHierarchy(void *);
extern int sdkSndStartStream(short, short, short, short);
extern void mdlSetAlphaBlend(unsigned char *);
extern void mdlClearAlphaBlend(unsigned char *);
extern void mdlEffectSetPackedColor(void *, int *);
extern void mdlEffectGetPackedColor(void *, int *);

extern unsigned char D_00794420[];
extern unsigned char D_005F1CC0[];
/* Earlier whole-layout probe: 11784/11584 bytes. Access-site fields below retain only measured word/float exceptions. */
// FUN_0017F490
int FldAI_PatrolUpdate(unsigned char *task)
{
  typedef struct { unsigned char r, g, b, a; } FldAIColor;
  float distVec[3];
  int *work;
  const FldAIPatrolBounds *patrolBounds;
  int value;
  unsigned char *modelColor;
  int otherValue;
  float *vector;
  unsigned char *effectTask;
  float *matrix;
  void *object;
  unsigned int randomBits;
  int action;
  unsigned char ready;
  int accepted;
  int configAddress;
  unsigned int unsignedValue;
  float distance;
  float factor;
  float distanceRange;
  float turnAmount;
  FldAIVec3 aiPos;
  FldAIVec3 state2Forward;
  FldAIVec3 state2Right;
  FldAIVec3 state2Delta;
  FldAIVec3 patrolPosition;
  float patrolNoticePosition[3];
  float turnNoticePosition[3];
  FldAIVec3 state6Delta;
  FldAIVec3 state6Direction;
  FldAIVec3 approachOrigin;
  FldAIVec3 state7Forward;
  FldAIVec3 state7Right;
  FldAIVec3 state7Delta;
  FldAIVec3 chasePosition;
  FldAIVec3 state8Forward;
  FldAIVec3 state8Right;
  FldAIVec3 state8Delta;
  FldAIVec3 predictionPosition;
  FldAIVec3 aiPos2;
  FldAIVec3 state9Forward;
  FldAIVec3 state9Right;
  FldAIVec3 state9Delta;
  FldAIVec3 state9Direction;
  FldAIVec3 weavePosition;
  FldAIVec3 state10Forward;
  FldAIVec3 state10Right;
  FldAIVec3 state10Delta;
  FldAIVec3 chargePosition;
  FldAIVec3 state11Forward;
  FldAIVec3 state11Right;
  FldAIVec3 state11Delta;
  FldAIVec3 returnPosition;
  FldAIVec3 picked;
  FldAIVec3 pick;
  FldAIVec3 aiPos6;
  FldAIVec3 aiPos8;
  FldAIVec3 aiHere;
  FldAIColor color;
  
  work = (int *)((SdkTask *)task)->work;
  if (((FldAIPatrolWork *)work)->paused == 1) {
    return 0;
  }
  accepted = 0;
  value = work[3];
  if (((FldAINpc *)value)->used == 0)
    goto availabilityDone;
  if ((void *)((FldAINpc *)value)->movement == NULL)
    goto availabilityDone;
  accepted = 1;
availabilityDone:
  ready = accepted != 0;
  if (ready == 0)
    return 0;
  {
    if ((((FldAINpc *)value)->flags & 1) == 0) {
      return 0;
    }
    value = kwlnGetCamera();
    value = (int)func_003e9700((struct RwFrame *)(unsigned int)((struct RwCamera *)value)->object.object.parent);
    modelColor = (unsigned char *)mdlGetColor((void *)(unsigned int)((FldAINpc *)work[3])->model);
    {
        typedef struct { unsigned char c[4]; } FldAIColorBytes;
        color = *(FldAIColor *)modelColor;
    }
    distance = ((FldAIPatrolWork *)work)->cameraNearPlane;
    distanceRange = ((FldAIPatrolWork *)work)->fadeDistance - distance;
    if (((FldAINpc *)work[3])->kind == '\0') {
      distance = fGpffff80f0 * distanceRange + distance + 0.0f;
    }
    else {
      distance = fGpffff811c * distanceRange + distance + 0.0f;
    }
    turnAmount = ((FldAIPatrolWork *)work)->fadeDistance - distance;
    otherValue = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
    distVec[0] = ((FldAIMatrix *)otherValue)->pos.x - ((FldAIMatrix *)value)->pos.x;
    otherValue = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
    distVec[1] = ((FldAIMatrix *)otherValue)->pos.y - ((FldAIMatrix *)value)->pos.y;
    otherValue = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
    distVec[2] = ((FldAIMatrix *)otherValue)->pos.z - ((FldAIMatrix *)value)->pos.z;
    distanceRange = RwV3dLength(&distVec[0]);
    if (!(distanceRange < ((float *)(int *)(u32)work)[0x21])) {
      ((FldAIPatrolWork *)work)->alpha = (float)(color.a = 0);
    }
    else if (distanceRange >= distance) {
      if (((FldAINpc *)((FldAIPatrolWork *)work)->actor)->kind == '\0') {
        distance = 1.0f - fGpffff825c * ((distanceRange - distance) / turnAmount);
        factor = (distance < 0.0f) ? 0.0f : distance;
      }
      else {
        factor = 1.0f - (distanceRange - distance) / turnAmount;
      }
      ((FldAIPatrolWork *)work)->alpha = (float)(color.a = (unsigned char)(factor * 255.0f));
    }
    else {
      ((FldAIPatrolWork *)((u8 *)(u32)work))->alpha = (float)(color.a = 0xff);
    }
    if (((FldAINpc *)work[3])->kind == '\x01') {
      mdlSetColor((void *)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,&color);
    }
    for (value = (int)((FldAIModel *)(int)((FldAINpc *)work[3])->model)->effects[0]; value != 0;
        value = (int)((FldAIModelEffect *)value)->next) {
      /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
      if (MEMBER(void *, value, FldAIModelEffect, effect) != (void *)0x0) { /* measured: FldAIModelEffect.effect: local nd7733; MEMBER retains reload behavior. */
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        mdlEffectGetPackedColor(MEMBER(void *, value, FldAIModelEffect, effect),(int *)&color); /* measured: FldAIModelEffect.effect: local nd7733; MEMBER retains reload behavior. */
        distance = ((FldAIPatrolWork *)work)->alpha;
        color.a = (unsigned char)distance;
        mdlEffectSetPackedColor(((FldAIModelEffect *)value)->effect,(int *)&color);
      }
    }
    switch(((FldAIPatrolWork *)work)->state) {
    case 0:
      value = (int)func_003e0f80();
      ((FldAIPatrolWork *)work)->transform = value;
      mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,0,0,1);
      work[5] = (u32)iGpffffb2c8 + (unsigned int)((FldAINpc *)work[3])->kind * 0x180 + (unsigned int)((FldAINpc *)work[3])->configIndex * 0x40;
      value = work[3];
      ((FldAIPatrolWork *)work)->boundsMin = ((FldAINpc *)value)->origin;
      value = work[3];
      ((FldAIPatrolWork *)work)->boundsMax = ((FldAINpc *)value)->origin;
      value = work[3];
      ((FldAIPatrolWork *)work)->alternateMin = ((FldAINpc *)value)->origin;
      value = work[3];
      ((FldAIPatrolWork *)work)->alternateMax = ((FldAINpc *)value)->origin;
      value = RpRandom();
      ((FldAIPatrolWork *)work)->walkCount = (int)((unsigned int)value % 3) + 1;
      ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
      ((FldAIPatrolWork *)work)->targetSpeed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
      effectTask = (unsigned char *)KDraw_CreateAxesTask(task,D_00794420);
      work[0x26] = (int)effectTask;
      FldRc_SetAxesPosition(effectTask,(u8 *)&((FldAINpc *)((FldAIPatrolWork *)work)->actor)->origin);
      FldRc_SetAxesColor((unsigned char *)work[0x26],(unsigned char *)D_005F1CE0);
      FldRc_SetAxesTargeted((unsigned char *)((FldAIPatrolWork *)work)->axesTask,0);
      ((FldAIPatrolWork *)work)->state = ((FldAIPatrolWork *)work)->state + 1;
      break;
    case 1:
      action = FldAI_AdvanceBoundsSample((u8 *)work);
      if (action == 0) {
        value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
        aiPos = ((FldAIMatrix *)value)->pos;
        if (((FldAINpc *)work[3])->unk73c != 0) {
          FldRc_SetAxesTargeted((unsigned char *)work[0x26],1);
          FldRc_SetAxesPosition((unsigned char *)work[0x26],(unsigned char *)(work + 0x14));
          FldRc_SetAxesColor((unsigned char *)((FldAIPatrolWork *)work)->axesTask,(unsigned char *)(D_005F1CE0 + ((FldAIPatrolWork *)work)->boundsIndex * 4));
        }
        else {
          FldRc_SetAxesTargeted((unsigned char *)((FldAIPatrolWork *)work)->axesTask,0);
        }
        value = (unsigned int)RpRandom() % 100;
        action = 0;
        if (((FldAIPatrolWork *)work)->behavior == 0) {
          if ((unsigned int)value < 5) {
            action = 1;
          }
        }
        else if ((((FldAIPatrolWork *)work)->behavior == 1) && ((unsigned int)value < 0x1e)) {
          action = 1;
        }
        if (action == 1) {
          randomBits = RpRandom();
          if ((randomBits & 1) != 0) {
            ((FldAIPatrolWork *)work)->turnDirection.word = 0x3f800000;
          }
          else {
            ((FldAIPatrolWork *)work)->turnDirection.word = -0x40800000;
          }
          value = RpRandom();
          ((FldAIPatrolWork *)work)->timer = (int)((unsigned int)value % 0x1e) + 0x1e;
          ((FldAIPatrolWork *)work)->state = 3;
        }
        else if (action == 2) {
          ((FldAIPatrolWork *)work)->timer = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->hiddenFrames;
          ((FldAINpc *)work[3])->flags = ((FldAINpc *)work[3])->flags | 2;
          distance = ((FldAIPatrolWork *)work)->alpha;
          unsignedValue = (unsigned int)distance;
          /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
          value = KMisc_CreateRmdFade((int)task,MEMBER(int, ((FldAIPatrolWork *)work)->actor, FldAINpc, model),unsignedValue,0,10); /* measured: FldAINpc.model: local instruction mismatch; MEMBER retains reload behavior. */
          ((FldAIPatrolWork *)work)->fadeTask = value;
          ((FldAIPatrolWork *)work)->state = 4;
        }
        else {
          {
          int cur = work[0x12];
          unsignedValue = cur != 0 ^ 1;
          accepted = 0;
          if ((!(aiPos.x < ((float *)fldFollowerStorageOffset(unsignedValue * 24, (u8 *)work))[9]) &&
               (aiPos.x <= ((float *)fldFollowerStorageOffset(unsignedValue * 24, (u8 *)work))[6])) &&
              (!(aiPos.z < ((float *)fldFollowerStorageOffset(unsignedValue * 24, (u8 *)work))[0xb])) &&
             (aiPos.z <= ((float *)fldFollowerStorageOffset(unsignedValue * 24, (u8 *)work))[8])) {
            accepted = 1;
          }
          if (accepted == 1) {
            ((FldAIPatrolWork *)work)->boundsIndex = !cur;
          }
          }
          value = RpRandom();
          distance = fGpffff8308 + (float)((unsigned int)value % 0x50) / 100.0f;
          otherValue = RpRandom();
          distanceRange = fGpffff8308 + (float)((unsigned int)otherValue % 0x50) / 100.0f;
          patrolBounds = (const FldAIPatrolBounds *)((float *)work + ((FldAIPatrolWork *)work)->boundsIndex * 6 + 6);
          {
            const FldAIPatrolBounds *bounds;
            unsigned char *clearByte = (unsigned char *)&pick;
            int clearCount = 0xc;

            if (clearByte != NULL) {
              do {
                *clearByte = 0;
                clearByte++;
                clearCount--;
              } while (clearCount != 0);
            }
            bounds = patrolBounds;
            pick.x = distance * (bounds->max.x - bounds->min.x) + bounds->min.x + 0.0f;
            pick.z = distanceRange * (bounds->max.z - bounds->min.z) + bounds->min.z + 0.0f;
            picked = pick;
            ((FldAIPatrolWork *)work)->destination = picked;
          }
          if (work[0x17] < 1) {
            unsignedValue = ((FldAIPatrolWork *)work)->fastWalk != 0 ^ 1;
            ((FldAIPatrolWork *)work)->fastWalk = unsignedValue;
            if (unsignedValue != 0) {
              ((FldAIPatrolWork *)work)->targetSpeed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->fastWalkSpeed;
            }
            else {
              ((FldAIPatrolWork *)work)->targetSpeed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
            }
            ((FldAIPatrolWork *)work)->speedFrames = 0xf;
            value = RpRandom();
            ((FldAIPatrolWork *)work)->walkCount = (int)((unsigned int)value % 3) + 1;
          }
          else {
            ((FldAIPatrolWork *)work)->walkCount = ((FldAIPatrolWork *)work)->walkCount - 1;
          }
          ((FldAIPatrolWork *)work)->accumulatedTurn.word = 0;
          ((FldAIPatrolWork *)work)->state = 2;
        }
      }
      break;
    case 2:
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state2Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state2Forward,&state2Forward);
      matrix = (float *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state2Right = ((FldAIMatrix *)matrix)->right;
      RwV3dNormalize(&state2Right,&state2Right);
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      patrolPosition = ((FldAIMatrix *)value)->pos;
      patrolPosition.y = 0.0f;
      state2Delta.x = ((FldAIPatrolWork *)work)->destination.x - patrolPosition.x;
      state2Delta.y = ((FldAIPatrolWork *)work)->destination.y - patrolPosition.y;
      state2Delta.z = ((FldAIPatrolWork *)work)->destination.z - patrolPosition.z;
      distance = RwV3dNormalize(&state2Delta,&state2Delta);
      /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
      factor = ((FldAIPatrolWork *)((u8 *)(u32)work))->speed;
      factor = fldAIScale(iGpffff830c, factor);
      if (!(distance <= factor)) {
        distance = factor;
      }
      else {
        ((FldAIPatrolWork *)work)->state = 1;
      }
      factor = state2Delta.x * state2Forward.x + state2Delta.y * state2Forward.y + state2Delta.z * state2Forward.z;
      if (factor < 1.0f) {
        turnAmount = ((FldAIPatrolWork *)work)->speed * 10.0f;
        factor = 1.0f - factor;
        if (factor < turnAmount / 180.0f) {
          turnAmount = factor * 180.0f;
        }
        if (state2Delta.x * state2Right.x + state2Delta.y * state2Right.y + state2Delta.z * state2Right.z < 0.0f) {
          turnAmount = turnAmount * -1.0f;
        }
        FldFrameTask_Rotate((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->movement)->handle220, D_00756510, turnAmount);
        turnAmount = fldAIAccumulateTurn(&((FldAIPatrolWork *)work)->accumulatedTurn.value, turnAmount);
        if ((!(turnAmount <= 360.0f)) || (turnAmount < -360.0f)) {
          ((FldAIPatrolWork *)work)->state = 1;
        }
      }
      FldFrameTask_StartMove((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220,distance);
      if (0 < work[0x18]) {
        if (((FldAIPatrolWork *)work)->fastWalk != 0) {
          ((FldAIPatrolWork *)work)->speed = (((FldAIPatrolWork *)work)->speed +
                              (((FldAIConfig *)((FldAIPatrolWork *)work)->config)->fastWalkSpeed - ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed) / 15.0f);
        }
        else {
          ((FldAIPatrolWork *)work)->speed = (((FldAIPatrolWork *)work)->speed -
                              (((FldAIConfig *)((FldAIPatrolWork *)work)->config)->fastWalkSpeed - ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed) / 15.0f);
        }
        ((FldAIPatrolWork *)work)->speedFrames = ((FldAIPatrolWork *)work)->speedFrames - 1;
      }
else {
        ((FldAIPatrolWork *)work)->speed = ((FldAIPatrolWork *)work)->targetSpeed;
      }
      value = FldAI_ChaserCanSeeTarget((unsigned char *)((FldAIPatrolWork *)work)->actor);
      if (value == 1) {
        value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
        *(FldAIVec3 *)patrolNoticePosition = ((FldAIMatrix *)value)->pos;
        patrolNoticePosition[1] = patrolNoticePosition[1] +
                    ((float (*)[4])D_005F1CC0)[((FldAINpc *)((FldAIPatrolWork *)work)->actor)->kind][((FldAINpc *)((FldAIPatrolWork *)work)->actor)->heightSlot];
        effectTask = (unsigned char *)FldStepFileTask(1);
        FldRc_RequestPositionSlot(effectTask,&patrolNoticePosition[0]);
        sdkSndStartStream(1,0xb,3,5);
        ((FldAIPatrolWork *)work)->timer = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->noticeFrames;
        ((FldAIPatrolWork *)work)->state = 6;
      }
      break;
    case 3:
      if (work[0x23] >= 0) {
        FldFrameTask_Rotate((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220, D_00756510,
                      ((FldAIConfig *)work[5])->walkSpeed * 10.0f * ((FldAIPatrolWork *)work)->turnDirection.value);
        value = FldAI_ChaserCanSeeTarget((unsigned char *)((FldAIPatrolWork *)work)->actor);
        if (value == 1) {
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
          *(FldAIVec3 *)turnNoticePosition = ((FldAIMatrix *)value)->pos;
          turnNoticePosition[1] = turnNoticePosition[1] +
                      ((float (*)[4])D_005F1CC0)[((FldAINpc *)((FldAIPatrolWork *)work)->actor)->kind][((FldAINpc *)((FldAIPatrolWork *)work)->actor)->heightSlot];
          effectTask = (unsigned char *)FldStepFileTask(1);
          FldRc_RequestPositionSlot(effectTask,&turnNoticePosition[0]);
          sdkSndStartStream(1,0xb,3,5);
          ((FldAIPatrolWork *)work)->timer = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->noticeFrames;
          ((FldAIPatrolWork *)work)->state = 6;
        }
        else {
          ((FldAIPatrolWork *)work)->timer = ((FldAIPatrolWork *)work)->timer - 1;
        }
      }
      else {
        ((FldAIPatrolWork *)work)->state = 1;
      }
      break;
    case 4:
      if ((unsigned char *)work[0x22] != (unsigned char *)0x0) {
        value = KDraw_IsEffectDone((unsigned char *)work[0x22]);
        if (value == 0) {
          break;
        }
        kwlnTaskDestroyWithHierarchy((void *)work[0x22]);
        ((FldAIPatrolWork *)work)->fadeTask = 0;
      }
      if (work[0x23] >= 0) {
        ((FldAIPatrolWork *)work)->timer = ((FldAIPatrolWork *)work)->timer - 1;
      }
      else {
        distance = ((FldAIPatrolWork *)work)->alpha;
        unsignedValue = (unsigned int)distance;
        /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
        value = KMisc_CreateRmdFade((int)task,MEMBER(int, ((FldAIPatrolWork *)work)->actor, FldAINpc, model),0,unsignedValue,10); /* measured: FldAINpc.model: local instruction mismatch; MEMBER retains reload behavior. */
        ((FldAIPatrolWork *)work)->fadeTask = value;
        ((FldAIPatrolWork *)work)->state = ((FldAIPatrolWork *)work)->state + 1;
      }
      break;
    case 5:
      value = KDraw_IsEffectDone((unsigned char *)work[0x22]);
      if (value != 0) {
        kwlnTaskDestroyWithHierarchy((void *)work[0x22]);
        ((FldAIPatrolWork *)work)->fadeTask = 0;
        ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags = ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags & 0xfffffffd;
        ((FldAIPatrolWork *)work)->state = 1;
      }
      break;
    case 6:
      if (work[0x23] >= 0) {
        ((FldAIPatrolWork *)work)->timer = ((FldAIPatrolWork *)work)->timer - 1;
      }
      else {
        ((FldAINpc *)work[3])->flags = ((FldAINpc *)work[3])->flags | 4;
        mdlDispatchAnimIfPresent(((FldAINpc *)work[3])->model,0,1,8,1);
        value = RpRandom();
        unsignedValue = (unsigned int)value % 100;
        action = 0;
        if (((FldAIPatrolWork *)work)->behavior == 0) {
          if (unsignedValue < 0x28) {
            action = 2;
          }
          else if (unsignedValue < 0x50) {
            action = 3;
          }
        }
        else if ((((FldAIPatrolWork *)work)->behavior == 1) && (unsignedValue < 0x14)) {
          action = 2;
        }
        if (action == 0) {
          ((FldAIPatrolWork *)work)->state = 7;
          ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
          ((FldAIPatrolWork *)work)->targetSpeed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->chaseSpeed;
          ((FldAIPatrolWork *)work)->speedFrames = 0xf;
          ((FldAIPatrolWork *)work)->timer = 0xd2;
        }
        else if (action == 2) {
          ((FldAIPatrolWork *)work)->accumulatedTurn.word = 0;
          ((FldAIPatrolWork *)work)->weavePhase.word = 0;
          ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)work[5])->walkSpeed;
          ((FldAIPatrolWork *)work)->targetSpeed = ((FldAIConfig *)work[5])->approachSpeed;
          ((FldAIPatrolWork *)work)->speedFrames = 0xf;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
          approachOrigin = ((FldAIMatrix *)value)->pos;
          approachOrigin.y = 0.0f;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.x = ((FldAIMatrix *)value)->pos.x - approachOrigin.x;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.y = ((FldAIMatrix *)value)->pos.y - approachOrigin.y;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state6Direction.z = ((FldAIMatrix *)value)->pos.z - approachOrigin.z;
          RwV3dNormalize(&state6Direction,&state6Direction);
          state6Direction.x = state6Direction.x * 200.0f;
          state6Direction.y = state6Direction.y * 200.0f;
          state6Direction.z = state6Direction.z * 200.0f;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          ((FldAIPatrolWork *)((u8 *)(u32)work))->destination.x = (state6Direction.x + ((FldAIMatrix *)value)->pos.x);
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          ((FldAIPatrolWork *)((u8 *)(u32)work))->destination.y = (state6Direction.y + ((FldAIMatrix *)value)->pos.y);
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          ((FldAIPatrolWork *)((u8 *)(u32)work))->destination.z = (state6Direction.z + ((FldAIMatrix *)value)->pos.z);
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model);
          aiPos6 = ((FldAIMatrix *)value)->pos;
          aiPos6.y = 0.0f;
          state6Delta.x = ((FldAIPatrolWork *)work)->destination.x - aiPos6.x;
          state6Delta.y = ((FldAIPatrolWork *)work)->destination.y - aiPos6.y;
          state6Delta.z = ((FldAIPatrolWork *)work)->destination.z - aiPos6.z;
          distance = RwV3dNormalize(&state6Delta,&state6Delta);
          ((FldAIPatrolWork *)work)->approachFrames = (int)(distance / (iGpffff830c * ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->approachSpeed));
          ((FldAIPatrolWork *)work)->state = 9;
        }
        else if (action == 3) {
          ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
          ((FldAIPatrolWork *)work)->targetSpeed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->approachSpeed;
          ((FldAIPatrolWork *)work)->speedFrames = 0xf;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          ((FldAIPatrolWork *)work)->destination = ((FldAIMatrix *)value)->pos;
          ((FldAIPatrolWork *)work)->state = 10;
        }
      }
      break;
    case 7:
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state7Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state7Forward,&state7Forward);
      matrix = (float *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state7Right = ((FldAIMatrix *)matrix)->right;
      RwV3dNormalize(&state7Right,&state7Right);
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      chasePosition = ((FldAIMatrix *)value)->pos;
      chasePosition.y = 0.0f;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.x = ((FldAIMatrix *)value)->pos.x - chasePosition.x;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.y = ((FldAIMatrix *)value)->pos.y - chasePosition.y;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state7Delta.z = ((FldAIMatrix *)value)->pos.z - chasePosition.z;
      distance = RwV3dNormalize(&state7Delta,&state7Delta);
      factor = iGpffff830c * ((FldAIPatrolWork *)work)->speed;
      if (!(distance <= factor)) {
        distance = factor;
      }
      factor = state7Delta.x * state7Forward.x + state7Delta.y * state7Forward.y + state7Delta.z * state7Forward.z;
      if (factor < 1.0f) {
        turnAmount = ((FldAIPatrolWork *)work)->speed * 10.0f;
        factor = 1.0f - factor;
        if (factor < turnAmount / 180.0f) {
          turnAmount = factor * 180.0f;
        }
        if (state7Delta.x * state7Right.x + state7Delta.y * state7Right.y + state7Delta.z * state7Right.z < 0.0f) {
          turnAmount = turnAmount * -1.0f;
        }
        FldFrameTask_Rotate((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->movement)->handle220, D_00756510, turnAmount);
      }
      FldFrameTask_StartMove((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220,distance);
      if (0 < work[0x18]) {
        ((FldAIPatrolWork *)((u8 *)(u32)work))->speed = (((FldAIPatrolWork *)((u8 *)(u32)work))->speed +
                            (((FldAIConfig *)((FldAIPatrolWork *)work)->config)->chaseSpeed - ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed) / 15.0f);
        ((FldAIPatrolWork *)work)->speedFrames = ((FldAIPatrolWork *)work)->speedFrames - 1;
      }
else {
        ((FldAIPatrolWork *)((u8 *)(u32)work))->speed = ((FldAIPatrolWork *)work)->targetSpeed;
      }
      if ((D_00764348 == 0) && (value = ((FldAIPatrolWork *)work)->actor, iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)((FldAINpc *)value)->kind * 0x180 + (unsigned int)((FldAINpc *)value)->configIndex * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)value)->model),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         ((FldAIConfig *)configAddress)->sightDistance, ((FldAIConfig *)configAddress)->sightAngle) == 1) {
          iGpffffb310 = value;
        }
      }
      if ((work[0x23] < 1) && (value = FldAI_ChaserCanSeeTarget((unsigned char *)work[3]), value == 0)) {
        ((FldAIPatrolWork *)work)->timer = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->returnFrames;
        ((FldAIPatrolWork *)work)->state = 0xb;
        mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,0,8,1);
      }
      else {
        if (0 < work[0x23]) {
          ((FldAIPatrolWork *)work)->timer = ((FldAIPatrolWork *)work)->timer - 1;
        }
        value = work[0x24];
        if (value < 1) {
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
          state7Delta.x = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.x - ((FldAINpc *)work[3])->origin.x;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
          state7Delta.y = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.y - ((FldAINpc *)work[3])->origin.y;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
          state7Delta.z = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.z - ((FldAINpc *)work[3])->origin.z;
          distance = RwV3dNormalize(&state7Delta,&state7Delta);
          if (distance >= ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->returnDistance) {
            ((FldAIPatrolWork *)work)->timer = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->returnFrames;
            mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,0,8,1);
            ((FldAIPatrolWork *)work)->state = 0xb;
          }
        }
        else if (0 < value) {
          ((FldAIPatrolWork *)work)->returnDelay = value - 1;
        }
      }
      break;
    case 8:
      distance = FldEvent_GetMoveStep();
      if (distance == 0.0f) {
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        aiPos2 = ((FldAIMatrix *)value)->pos;
      }
      else {
        f32 facingZ;
        f32 playerFacingZ;
        f32 facingX;
        f32 playerFacingX;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
        facingZ = ((FldAIMatrix *)value)->forward.z;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        playerFacingZ = ((FldAIMatrix *)value)->forward.z;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
        facingX = ((FldAIMatrix *)value)->forward.x;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        playerFacingX = ((FldAIMatrix *)value)->forward.x;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
        otherValue = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        if (playerFacingX * facingX + ((FldAIMatrix *)otherValue)->forward.y * ((FldAIMatrix *)value)->forward.y + playerFacingZ * facingZ > fGpffff8310)
        {
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          aiPos2 = ((FldAIMatrix *)value)->pos;
          ((FldAIPatrolWork *)work)->state = 7;
        }
        else {
          distance = FldEvent_GetMoveStep();
          distance = distance - ((FldAIPatrolWork *)work)->speed;
          if (distance < 0.0f) {
            distance = distance * -1.0f;
          }
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model);
          predictionPosition = ((FldAIMatrix *)value)->pos;
          predictionPosition.y = 0.0f;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.x = ((FldAIMatrix *)value)->pos.x - predictionPosition.x;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.y = ((FldAIMatrix *)value)->pos.y - predictionPosition.y;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Delta.z = ((FldAIMatrix *)value)->pos.z - predictionPosition.z;
          factor = RwV3dNormalize(&state8Delta,&state8Delta);
          factor = factor / distance;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          state8Forward = ((FldAIMatrix *)value)->forward;
          state8Forward.x = state8Forward.x * (factor * FldEvent_GetMoveStep());
          state8Forward.y = state8Forward.y * (factor * FldEvent_GetMoveStep());
          state8Forward.z = state8Forward.z * (factor * FldEvent_GetMoveStep());
          value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
          aiPos2 = ((FldAIMatrix *)value)->pos;
          aiPos2.x = aiPos2.x + state8Forward.x;
          aiPos2.y = aiPos2.y + state8Forward.y;
          aiPos2.z = aiPos2.z + state8Forward.z;
        }
      }
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state8Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state8Forward,&state8Forward);
      matrix = (float *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state8Right = ((FldAIMatrix *)matrix)->right;
      RwV3dNormalize(&state8Right,&state8Right);
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      aiPos8 = ((FldAIMatrix *)value)->pos;
      aiPos8.y = 0.0f;
      state8Delta.x = aiPos2.x - aiPos8.x;
      state8Delta.y = aiPos2.y - aiPos8.y;
      state8Delta.z = aiPos2.z - aiPos8.z;
      distance = RwV3dNormalize(&state8Delta,&state8Delta);
      factor = iGpffff830c * ((FldAIPatrolWork *)work)->speed;
      if (!(distance <= factor)) {
        distance = factor;
      }
      factor = state8Delta.x * state8Forward.x + state8Delta.y * state8Forward.y + state8Delta.z * state8Forward.z;
      if (factor < 1.0f) {
        turnAmount = ((FldAIPatrolWork *)work)->speed * 10.0f;
        factor = 1.0f - factor;
        if (factor < turnAmount / 180.0f) {
          turnAmount = factor * 180.0f;
        }
        if (state8Delta.x * state8Right.x + state8Delta.y * state8Right.y + state8Delta.z * state8Right.z < 0.0f) {
          turnAmount = turnAmount * -1.0f;
        }
        FldFrameTask_Rotate((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->movement)->handle220, D_00756510, turnAmount);
      }
      FldFrameTask_StartMove((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220,distance);
      if (0 < work[0x18]) {
        ((FldAIPatrolWork *)((u8 *)(u32)work))->speed = (((FldAIPatrolWork *)((u8 *)(u32)work))->speed +
                            (((FldAIConfig *)((FldAIPatrolWork *)work)->config)->chaseSpeed - ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed) / 15.0f);
        ((FldAIPatrolWork *)work)->speedFrames = ((FldAIPatrolWork *)work)->speedFrames - 1;
      }
else {
        ((FldAIPatrolWork *)((u8 *)(u32)work))->speed = ((FldAIPatrolWork *)work)->targetSpeed;
      }
      if ((D_00764348 == 0) && (value = ((FldAIPatrolWork *)work)->actor, iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)((FldAINpc *)value)->kind * 0x180 + (unsigned int)((FldAINpc *)value)->configIndex * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)value)->model),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         ((FldAIConfig *)configAddress)->sightDistance, ((FldAIConfig *)configAddress)->sightAngle) == 1) {
          iGpffffb310 = value;
        }
      }
      if ((work[0x23] < 1) && (value = FldAI_ChaserCanSeeTarget((unsigned char *)work[3]), value == 0)) {
        ((FldAIPatrolWork *)work)->timer = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->returnFrames;
        ((FldAIPatrolWork *)work)->state = 0xb;
        mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,0,8,1);
      }
      else {
        if (0 < work[0x23]) {
          ((FldAIPatrolWork *)work)->timer = ((FldAIPatrolWork *)work)->timer - 1;
        }
        value = work[0x24];
        if (value < 1) {
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
          state8Delta.x = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.x - ((FldAINpc *)work[3])->origin.x;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
          state8Delta.y = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.y - ((FldAINpc *)work[3])->origin.y;
          value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
          state8Delta.z = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.z - ((FldAINpc *)work[3])->origin.z;
          distance = RwV3dNormalize(&state8Delta,&state8Delta);
          if (distance >= ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->returnDistance) {
            ((FldAIPatrolWork *)work)->timer = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->returnFrames;
            ((FldAIPatrolWork *)work)->state = 0xb;
            mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,0,8,1);
          }
        }
        else if (0 < value) {
          ((FldAIPatrolWork *)work)->returnDelay = value - 1;
        }
      }
      break;
    case 9:
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state9Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state9Forward,&state9Forward);
      matrix = (float *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state9Right = ((FldAIMatrix *)matrix)->right;
      RwV3dNormalize(&state9Right,&state9Right);
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      weavePosition = ((FldAIMatrix *)value)->pos;
      weavePosition.y = 0.0f;
      turnAmount = sinf(((FldAIPatrolWork *)work)->weavePhase.value);
      ((FldAIPatrolWork *)((u8 *)(u32)work))->weavePhase.value = (((FldAIPatrolWork *)((u8 *)(u32)work))->weavePhase.value + fGpffff8218);
      /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
      state9Direction.x = ((FldAIPatrolWork *)((u8 *)(u32)work))->destination.x - weavePosition.x;
      distance = weavePosition.y;
      /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
      state9Direction.y = ((FldAIPatrolWork *)((u8 *)(u32)work))->destination.y - distance;
      factor = weavePosition.z;
      /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
      state9Direction.z = ((FldAIPatrolWork *)((u8 *)(u32)work))->destination.z - factor;
      RwV3dNormalize(&state9Direction,&state9Direction);
      state9Direction.x = state9Direction.x * 200.0f;
      state9Direction.y = state9Direction.y * 200.0f;
      state9Direction.z = state9Direction.z * 200.0f;
      state9Direction.x = state9Direction.x + ((FldAIPatrolWork *)work)->destination.x;
      state9Direction.y = state9Direction.y + ((FldAIPatrolWork *)work)->destination.y;
      state9Direction.z = state9Direction.z + ((FldAIPatrolWork *)work)->destination.z;
      turnAmount = fldAIScale(400.0f, turnAmount);
      state9Delta.x = state9Right.x * turnAmount;
      state9Delta.y = state9Right.y * turnAmount;
      state9Delta.z = state9Right.z * turnAmount;
      state9Delta.x = state9Delta.x + state9Direction.x;
      state9Delta.y = state9Delta.y + state9Direction.y;
      state9Delta.z = state9Delta.z + state9Direction.z;
      state9Delta.x = state9Delta.x - weavePosition.x;
      state9Delta.y = state9Delta.y - distance;
      state9Delta.z = state9Delta.z - factor;
      distance = RwV3dNormalize(&state9Delta,&state9Delta);
      factor = *(float *)&work[0x1a];
      factor = fldAIScale(iGpffff830c, factor);
      if (!(distance <= factor)) {
        distance = factor;
      }
      if (work[0x25] < 1) {
        ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags = ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags & 0xfffffffb;
        ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
        ((FldAIPatrolWork *)work)->state = 1;
        mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,0,8,1);
      }
      else {
        ((FldAIPatrolWork *)work)->approachFrames = ((FldAIPatrolWork *)work)->approachFrames - 1;
      }
      factor = state9Delta.x * state9Forward.x + state9Delta.y * state9Forward.y + state9Delta.z * state9Forward.z;
      /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
      turnAmount = 5.0f * (10.0f * ((FldAIPatrolWork *)((u8 *)(u32)work))->speed);
      factor = 1.0f - factor;
      if (factor < turnAmount / 180.0f) {
        turnAmount = factor * 180.0f;
      }
      if (state9Delta.x * state9Right.x + state9Delta.y * state9Right.y + state9Delta.z * state9Right.z < 0.0f) {
        turnAmount = turnAmount * -1.0f;
      }
      FldFrameTask_Rotate((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220, D_00756510, turnAmount);
      FldFrameTask_StartMove((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220,distance);
      if (0 < work[0x18]) {
        ((FldAIPatrolWork *)work)->speed = (((FldAIPatrolWork *)work)->speed +
                            (((FldAIConfig *)((FldAIPatrolWork *)work)->config)->chaseSpeed - ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed) / 15.0f);
        ((FldAIPatrolWork *)work)->speedFrames = ((FldAIPatrolWork *)work)->speedFrames - 1;
      }
else {
        ((FldAIPatrolWork *)work)->speed = ((FldAIPatrolWork *)work)->targetSpeed;
      }
      if ((D_00764348 == 0) && (value = ((FldAIPatrolWork *)work)->actor, iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)((FldAINpc *)value)->kind * 0x180 + (unsigned int)((FldAINpc *)value)->configIndex * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)value)->model),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         ((FldAIConfig *)configAddress)->sightDistance, ((FldAIConfig *)configAddress)->sightAngle) == 1) {
          iGpffffb310 = value;
        }
      }
      break;
    case 10:
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state10Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state10Forward,&state10Forward);
      matrix = (float *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state10Right = ((FldAIMatrix *)matrix)->right;
      RwV3dNormalize(&state10Right,&state10Right);
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      chargePosition = ((FldAIMatrix *)value)->pos;
      chargePosition.y = 0.0f;
      state10Delta.x = ((FldAIPatrolWork *)work)->destination.x - chargePosition.x;
      state10Delta.y = ((FldAIPatrolWork *)work)->destination.y - chargePosition.y;
      state10Delta.z = ((FldAIPatrolWork *)work)->destination.z - chargePosition.z;
      distance = RwV3dNormalize(&state10Delta,&state10Delta);
      factor = *(float *)&work[0x1a];
      factor = fldAIScale(iGpffff830c, factor);
      if (!(distance <= factor)) {
        distance = factor;
      }
      else {
        ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags = ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags & 0xfffffffb;
        ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
        ((FldAIPatrolWork *)work)->state = 1;
        mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,0,8,1);
      }
      turnAmount = state10Delta.x * state10Forward.x + state10Delta.y * state10Forward.y + state10Delta.z * state10Forward.z;
      /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
      factor = 10.0f * ((FldAIPatrolWork *)((u8 *)(u32)work))->speed;
      turnAmount = 1.0f - turnAmount;
      if (turnAmount < factor / 180.0f) {
        factor = turnAmount * 180.0f;
      }
      if (state10Delta.x * state10Right.x + state10Delta.y * state10Right.y + state10Delta.z * state10Right.z < 0.0f) {
        factor = factor * -1.0f;
      }
      FldFrameTask_Rotate((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220, D_00756510, factor);
      factor = fldAIAccumulateTurn(&((FldAIPatrolWork *)work)->accumulatedTurn.value, factor);
      if ((!(factor <= 360.0f)) || (factor < -360.0f)) {
        ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags = ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags & 0xfffffffb;
        ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
        ((FldAIPatrolWork *)work)->state = 1;
      }
      FldFrameTask_StartMove((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220,distance);
      if (0 < work[0x18]) {
        ((FldAIPatrolWork *)work)->speed = (((FldAIPatrolWork *)work)->speed +
                            (((FldAIConfig *)((FldAIPatrolWork *)work)->config)->chaseSpeed - ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed) / 15.0f);
        ((FldAIPatrolWork *)work)->speedFrames = ((FldAIPatrolWork *)work)->speedFrames - 1;
      }
else {
        ((FldAIPatrolWork *)work)->speed = ((FldAIPatrolWork *)work)->targetSpeed;
      }
      if ((D_00764348 == 0) && (value = ((FldAIPatrolWork *)work)->actor, iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)((FldAINpc *)value)->kind * 0x180 + (unsigned int)((FldAINpc *)value)->configIndex * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)value)->model),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         ((FldAIConfig *)configAddress)->sightDistance, ((FldAIConfig *)configAddress)->sightAngle) == 1) {
          iGpffffb310 = value;
        }
      }
      break;
    case 0xb:
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state11Forward = ((FldAIMatrix *)value)->forward;
      RwV3dNormalize(&state11Forward,&state11Forward);
      matrix = (float *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      state11Right = ((FldAIMatrix *)matrix)->right;
      RwV3dNormalize(&state11Right,&state11Right);
      value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
      returnPosition = ((FldAIMatrix *)value)->pos;
      returnPosition.y = 0.0f;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.x = ((FldAIMatrix *)value)->pos.x - returnPosition.x;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.y = ((FldAIMatrix *)value)->pos.y - returnPosition.y;
      value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
      state11Delta.z = ((FldAIMatrix *)value)->pos.z - returnPosition.z;
      RwV3dNormalize(&state11Delta,&state11Delta);
      distance = state11Delta.x * state11Forward.x + state11Delta.y * state11Forward.y + state11Delta.z * state11Forward.z;
      if (distance < 1.0f) {
        factor = ((FldAIPatrolWork *)work)->speed * 10.0f;
        distance = 1.0f - distance;
        if (distance < factor / 180.0f) {
          factor = distance * 180.0f;
        }
        if (state11Delta.x * state11Right.x + state11Delta.y * state11Right.y + state11Delta.z * state11Right.z < 0.0f) {
          factor = factor * -1.0f;
        }
        FldFrameTask_Rotate((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->movement)->handle220, D_00756510, factor);
      }
      value = FldAI_ChaserCanSeeTarget((unsigned char *)work[3]);
      if (value == 1) {
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.x = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.x - ((FldAINpc *)work[3])->origin.x;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.y = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.y - ((FldAINpc *)work[3])->origin.y;
        value = (int)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]);
        state11Delta.z = ((FldAIMatrix *)(u8 *)(u32)(value))->pos.z - ((FldAINpc *)work[3])->origin.z;
        distance = RwV3dNormalize(&state11Delta,&state11Delta);
        if (distance < ((FldAIConfig *)work[5])->returnDistance) {
          ((FldAIPatrolWork *)work)->speed = ((float *)((FldAIPatrolWork *)work)->config)[6];
          ((FldAIPatrolWork *)work)->targetSpeed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->chaseSpeed;
          ((FldAIPatrolWork *)work)->speedFrames = 1;
          ((FldAIPatrolWork *)work)->timer = 0xd2;
          ((FldAIPatrolWork *)work)->returnDelay = 0x3c;
          ((FldAIPatrolWork *)work)->state = 7;
          mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,1,8,1);
          break;
        }
      }
      if ((D_00764348 == 0) && (value = ((FldAIPatrolWork *)work)->actor, iGpffffb310 == 0)) {
        configAddress = (u32)iGpffffb2c8 + (unsigned int)((FldAINpc *)value)->kind * 0x180 + (unsigned int)((FldAINpc *)value)->configIndex * 0x40;
        if (FldEvent_HasLineOfSight((void *)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)value)->model),
                         &((FldAIMatrix *)mdlGetMatrix((u8 *)(unsigned int)D_007EFA00[0]))->pos,
                         ((FldAIConfig *)configAddress)->sightDistance, ((FldAIConfig *)configAddress)->sightAngle) == 1) {
          iGpffffb310 = value;
        }
      }
      if (work[0x23] >= 0) {
        ((FldAIPatrolWork *)work)->timer = ((FldAIPatrolWork *)work)->timer - 1;
      }
      else {
        value = (int)mdlGetMatrix((u8 *)(unsigned int)((FldAINpc *)work[3])->model);
        aiHere = ((FldAIMatrix *)value)->pos;
        accepted = 0;
        if ((!(aiHere.x < ((FldAIPatrolWork *)work)->boundsMin.x) && (aiHere.x <= ((FldAIPatrolWork *)work)->boundsMax.x)) &&
            !(aiHere.z < ((FldAIPatrolWork *)work)->boundsMin.z) && (aiHere.z <= ((FldAIPatrolWork *)work)->boundsMax.z)) {
          accepted = 1;
        }
        if (accepted == 0) {
          accepted = 0;
          if ((!(aiHere.x < ((FldAIPatrolWork *)work)->alternateMin.x) && (aiHere.x <= ((FldAIPatrolWork *)work)->alternateMax.x)) &&
             !(aiHere.z < ((FldAIPatrolWork *)work)->alternateMin.z) && (aiHere.z <= ((FldAIPatrolWork *)work)->alternateMax.z)) {
            accepted = 1;
          }
          if (accepted == 0) {
            ((FldAINpc *)work[3])->flags = ((FldAINpc *)work[3])->flags | 2;
            if (((FldAINpc *)work[3])->kind == '\x01') {
              value = (int)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model;
              ((FldAIModel *)value)->flags = ((FldAIModel *)value)->flags & 0xffffff7f;
            }
            mdlSetAlphaBlend(((FldAINpc *)work[3])->model);
            value = work[3];
            if (((FldAINpc *)value)->kind == '\0') {
              /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
              value = KMisc_CreateRmdFade((int)task,MEMBER(int, value, FldAINpc, model),0xff,0,10); /* measured: FldAINpc.model: local instruction mismatch; MEMBER retains reload behavior. */
              ((FldAIPatrolWork *)work)->fadeTask = value;
            }
            else if (((FldAINpc *)value)->kind == '\x01') {
              distance = ((FldAIPatrolWork *)work)->alpha;
              unsignedValue = (unsigned int)distance;
              /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
              value = KMisc_CreateRmdFade((int)task,MEMBER(int, value, FldAINpc, model),unsignedValue,0,10); /* measured: FldAINpc.model: local instruction mismatch; MEMBER retains reload behavior. */
              ((FldAIPatrolWork *)work)->fadeTask = value;
            }
            ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
            ((FldAIPatrolWork *)work)->state = 0xc;
            mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,0,8,1);
            break;
          }
        }
        ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags = ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags & 0xfffffffb;
        ((FldAIPatrolWork *)work)->speed = ((FldAIConfig *)((FldAIPatrolWork *)work)->config)->walkSpeed;
        ((FldAIPatrolWork *)work)->state = 1;
        mdlDispatchAnimIfPresent(((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model,0,0,8,1);
      }
      break;
    case 0xc:
      value = KDraw_IsEffectDone((unsigned char *)work[0x22]);
      if (value != 0) {
        kwlnTaskDestroyWithHierarchy((void *)work[0x22]);
        work[0x22] = 0;
        FldFrameTask_SetPosition((unsigned char *)((ResrcRecord *)(int)((FldAINpc *)work[3])->movement)->handle220,(u8 *)&((FldAINpc *)work[3])->origin);
        value = ((FldAIPatrolWork *)work)->actor;
        if (((FldAINpc *)value)->kind == '\0') {
          /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
          value = KMisc_CreateRmdFade((int)task,MEMBER(int, value, FldAINpc, model),0,0xff,10); /* measured: FldAINpc.model: local instruction mismatch; MEMBER retains reload behavior. */
          ((FldAIPatrolWork *)work)->fadeTask = value;
        }
        else if (((FldAINpc *)value)->kind == '\x01') {
          distance = ((FldAIPatrolWork *)work)->alpha;
          unsignedValue = (unsigned int)distance;
          /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
          value = KMisc_CreateRmdFade((int)task,MEMBER(int, value, FldAINpc, model),0,unsignedValue,10); /* measured: FldAINpc.model: local instruction mismatch; MEMBER retains reload behavior. */
          ((FldAIPatrolWork *)work)->fadeTask = value;
        }
        ((FldAIPatrolWork *)work)->state = 0xd;
      }
      break;
    case 0xd:
      value = KDraw_IsEffectDone((unsigned char *)work[0x22]);
      if (value != 0) {
        if (((FldAINpc *)work[3])->kind == '\x01') {
          value = (int)((FldAINpc *)((FldAIPatrolWork *)work)->actor)->model;
          ((FldAIModel *)value)->flags = ((FldAIModel *)value)->flags | 0x80;
        }
        mdlClearAlphaBlend(((FldAINpc *)work[3])->model);
        ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags = ((FldAINpc *)((FldAIPatrolWork *)work)->actor)->flags & 0xfffffff9;
        kwlnTaskDestroyWithHierarchy((void *)work[0x22]);
        ((FldAIPatrolWork *)work)->fadeTask = 0;
        ((FldAIPatrolWork *)work)->state = 1;
      }
      break;
    case 14:
      break;
    }
    return 0;
  }
  return 0;
}
#pragma pop

/* Release the patrol transform and task-owned work. */
/* measured: the final task-work reload requires MEMBER to preserve callback aliasing. */
// FUN_001821D0
void FldAI_PatrolDestroy(u8 *task) {
    s32 h = ((FldAIPatrolWork *)(((SdkTask *)task)->work))->transform;

    if (h != 0) {
        func_003e0f40(h);
    }
    /* Earlier typing probe changed instruction bytes here; the remaining access forms were remeasured individually. */
    jtbl_008873EC[0](MEMBER(void *, task, SdkTask, work)); /* measured: SdkTask.work: local nd5; MEMBER retains reload behavior. */
}

/* Create a disabled patrol controller and capture its camera-distance fade range. */
/* The 0xA0-byte patrol allocation stores actor/paused/behavior and camera fade limits; remaining fields are initialized by the update. */
// FUN_00182220
s32 FldAI_SpawnPatrol(s32 parent, s32 actor, s32 behavior)
{
    s32 ret;
    u8 *work;

    chkmemAllocSiteTag(D_005F1B18, 0xA50);
    work = D_008873F4[0](1, 0xA0, 0x40000);
    if (work == NULL) {
        return 0;
    }
    ret = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005F1CF0), 0xF, 0, 0, FldAI_PatrolUpdate, FldAI_PatrolDestroy, (u8 *)(work));
    ((FldAIPatrolWork *)work)->actor = actor;
    ((FldAIPatrolWork *)work)->paused = 1;
    ((FldAIPatrolWork *)work)->behavior = behavior;
    ((FldAIPatrolWork *)work)->cameraNearPlane = ((struct RwCamera *)(u8 *)(u32)kwlnGetCamera())->nearPlane;
    ((FldAIPatrolWork *)work)->fadeDistance = iGpffffba6c;
    return ret;
}
