/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Kernel/Kwln/kwln.c; members 00182310-001852f0 */
#include "member_access.h"
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
#include "rw_types_internal.h"
#include "kwln_task_internal.h"
#include "field_event_internal.h"
#include "scene_resource_internal.h"
#include "Kosaka/k_fldFilter_internal.h"
#include "rw_frame_internal.h"
#include "rw_texture_internal.h"
#include "mdl_file_internal.h"
#include "primitive_queue_internal.h"

/* Unit settings: measured ambient/weather helpers use loop invariants off and propagation on. */
#pragma opt_loop_invariants off
#pragma opt_propagation on

/* Chaser (0x74 bytes) and patrol (0xA0 bytes) work share this prefix. */
typedef struct FldAITaskWork { s32 state, paused; } FldAITaskWork;
typedef RwV3d RainVector;

typedef RwMatrixTag RainMatrix;

/* The motion allocation has one elapsed/displacement pair per trail point. */
typedef struct RainMotionStep { f32 elapsed, y; } RainMotionStep;

typedef struct RainDrop {
    s32 active;
    s32 count;
    f32 x;
    union { f32 *motion; RainMotionStep *steps; };
} RainDrop;

typedef struct RpPTankLockStruct {
    u8 *data;
    s32 stride;
} RainLock;

typedef union FldRainHandle {
    s32 handle;
    u8 *bytes;
    RainMatrix *matrix;
    struct RpAtomic *atomic;
    struct RwFrame *frame;
    RainDrop *drops;
    s32 *timers;
    f32 *window;
} FldRainHandle;

/* FldRainTaskCreate allocates 0x78 bytes; update and destroy establish the
 * owned PTank handles, per-column timers and 0x10-byte drop records. */
typedef struct FldRainWork {
    s32 state, paused;
    FldRainHandle atomic, frame, matrix;
    f32 acceleration, distance, speed, spacing;
    s32 alpha, textureIndex, trailLength, spawnInterval;
    s32 columnCount;
    FldRainHandle columnTimers;
    s32 intervalJitter, dropCount;
    FldRainHandle viewWindow;
    RainVector origin;
    f32 spanX, spanY;
    FldRainHandle drops;
    s32 unk60;
    f32 verticalSpeed;
    RainVector scale;
    s32 particleCount;
} FldRainWork;

/* FldFogTaskCreate allocates 0x460 bytes. Four 0x100-byte quads precede
 * the texture, UV scroll, viewport, color endpoints and texture bounds. */
typedef struct FldFogWork {
    s32 state, paused;
    u8 pad08[8];
    FldFilterVertex quads[2][2][4];
    s32 texture;
    f32 scrollX, scrollY;
    u8 pad41C[4];
    s32 textureIndex;
    f32 width, height, halfWidth, halfHeight;
    s16 x, y, viewportWidth, viewportHeight;
    s32 blendMode;
    u8 colors[8];
    u8 pad448[8];
    f32 left, top, right, bottom;
} FldFogWork;
typedef char RainDropSize[sizeof(RainDrop) == 0x10 ? 1 : -1];
typedef char FldRainWorkSize[(sizeof(FldRainWork) == 0x78) ? 1 : -1];
typedef char FldFogWorkSize[(sizeof(FldFogWork) == 0x460) ? 1 : -1];
/* The SDK plugin offset selects this private PTank block at runtime. */
typedef struct RpPTankAtomicExtPrv {
    s32 maximumCount, activeCount;
    u8 pad08[0x38];
    u32 instanceFlags;
    u8 pad44[0x70];
    s32 unkB4;
    u8 padB8[0x28];
    u8 unkE0[0x10];
} RpPTankAtomicExtPrv;

typedef void *(*RainAllocate)(size_t count, size_t size, u32 hint);

/* SDK atomic/geometry prefixes used only to reach the first material. */
struct RpGeometry {
    u8 pad00[0x20];
    struct RpMaterial **materials;
};
struct RpAtomic {
    u8 pad00[0x18];
    struct RpGeometry *geometry;
};

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

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32, s32);
extern void FldNoiseEmitTagged(void);
extern void func_003a2760(s32);
extern void func_003e9390(s32);
typedef struct RpMaterial *(*MaterialCallback)(struct RpMaterial *, void *);

extern void func_003f3eb0(s32, s32);
extern s32 FldFogUpdate(u8 *task);
extern void (*jtbl_008873EC[])(void *);
extern u64 iGpffffb8c8;
extern void func_003e0f40(s32);
extern struct RpMaterial *func_003c42b0(struct RpMaterial *material, RwTexture *texture);
extern RwTexDictionary *func_003ef6d0(void);
extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
extern u8 iGpffffb310;
extern void memset(void *dst, s32 value, s32 size);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 kwlnGetCamera(void);
extern s16 mdlGetLayerAnimation(s32 model, s32 layer);
extern u8 *mdlGetMatrix(u32 model);
extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
extern f32 sinf(f32);
extern u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count);
extern u32 D_007EFA00[];
extern u8 D_005F1D80[];
extern u8 D_005F1D90[];
extern s32 iGpffff9f60;
extern s32 FldRainUpdate(u8 *task);
extern s32 kwlnGetCamera(void);
extern u8 D_007E8C00[];
extern u8 *iGpffff9db0;
extern s32 iGpffffb884;
#pragma push
#pragma opt_loop_invariants on
/* Broadcast a pause value to the linked chaser/patrol task of each occupied, active actor slot. */
// FUN_00182310
/* measured: inline and explicit actor-table base; best baseline residual 94 differing bytes. */
void FldSlotBroadcastState(s32 state)
{
    s32 slotIndex;
    s32 activeValue;
    s32 slotStride;
    s32 active;
    u8 *slot;
    u8 *task;

    slotIndex = 0;
    activeValue = 1;
    slotStride = 0x750;
    while (slotIndex < 0xF) {
        active = 0;
        slot = D_007E8C00 + slotIndex * slotStride;
        if (((FldEventActor *)slot)->unit != 0 && ((FldEventActor *)slot)->active != 0) {
            active = activeValue;
        }
        active = active != 0;
        if (active != 0) {
            task = ((FldEventActor *)slot)->auxiliaryTask;
            if (task != NULL) {
                ((FldAITaskWork *)((KwlnTask *)task)->work)->paused = state;
            }
        }
        slotIndex += 1;
    }
}
#pragma pop

// FUN_00182390
void FldAmbientFlagClear(void)
{
    memset(&iGpffffb310, 0, 4);
}

// FUN_001823C0
u8 *FldAmbientFlagPtr(void)
{
    return &iGpffffb310;
}

typedef struct {
    f32 x, y, z;
} FldAreaNormal;

/* Plays the ambient cue for slot `id` and advances that slot's four-step
   variation counter.  Inlined into every trigger arm of FldAmbientTrigger. */
/* Play an ambient cue and cycle the slot through four sound variations. */
static inline void fldPlayAmbientCue(u16 id, s16 bank, s32 base)
{
    extern s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);
    extern s32 D_007F1760[];
    s32 *slot = &D_007F1760[id & 0x3FF];

    sdkSndStartStream(0, (id & 0x3FF) + 4, bank, base + *slot);
    if (++*slot >= 4) {
        *slot = 0;
    }
}

/* Select an ambient surface cue from the containing area quad and trigger it at the actor animation footfall frames. */
// FUN_001823D0
void FldAmbientTrigger(s32 model, u16 mode, u16 id)
{
    extern u8 *MT_Scene_GetResListHead(s32 resourceType);
    extern s32 K_FldFrame_IsPointInTriangle(f32 *point, f32 **vertices, f32 *normal);
    extern s32 FldMoveAnimPrimary(s32 characterType);
    extern s32 FldMoveAnimSecondary(s32 characterType);
    extern u32 K_FldEvent_ArePosWithinDist(const struct RwV3d *posA, const struct RwV3d *posB, f32 maxDist);
    extern f32 mdlGetLayerWeight(s32 model, s32 layer);
    extern u8 *D_005F08B0[];
    s32 area;
    f32 *position;
    SceneQuadResource *areaNode;
    u16 animation;
    u16 motionState;
    f32 animationFrame;
    s32 fieldId;
    s32 roomId;

    motionState = ((MdlFileModel *)model)->type;
    animation = mdlGetLayerAnimation(model, 0);
    animationFrame = mdlGetLayerWeight(model, 0);
    if (((s32 *)iGpffff9db0)[0] >= 200) {
        return;
    }
    position = (f32 *)&((RainMatrix *)mdlGetMatrix(model))->pos;
    areaNode = (SceneQuadResource *)MT_Scene_GetResListHead(0x15);
    fieldId = ((s32 *)iGpffff9db0)[0];
    roomId = ((s32 *)iGpffff9db0)[1];
    if (D_005F08B0[fieldId] == NULL) {
        area = 0;
    } else {
        area = D_005F08B0[fieldId][roomId];
        for (; areaNode != NULL; areaNode = (SceneQuadResource *)areaNode->base.next) {
            f32 *tri[3];
            FldAreaNormal normal = {0.0f, 1.0f, 0.0f};

            tri[0] = (f32 *)&areaNode->corners[0];
            tri[1] = (f32 *)&areaNode->corners[1];
            tri[2] = (f32 *)&areaNode->corners[2];
            if (K_FldFrame_IsPointInTriangle(position, tri, &normal.x) == 1 &&
                position[1] < 100.0f + tri[0][1] && position[1] > tri[0][1] - 100.0f) {
                area = areaNode->terrain;
                break;
            }
            tri[0] = (f32 *)&areaNode->corners[1];
            tri[1] = (f32 *)&areaNode->corners[2];
            tri[2] = (f32 *)&areaNode->corners[3];
            if (K_FldFrame_IsPointInTriangle(position, tri, &normal.x) == 1 &&
                position[1] < 100.0f + tri[0][1] && position[1] > tri[0][1] - 100.0f) {
                area = areaNode->terrain;
                break;
            }
        }
    }
    switch (mode) {
    case 1:
        if (motionState == 9) {
            if (animation == FldMoveAnimPrimary(mode)) {
                if ((animationFrame > 7.0f && animationFrame < 8.0f) || (animationFrame > 21.0f && animationFrame < 22.0f)) {
                    fldPlayAmbientCue(id, 1, area * 4);
                }
            } else if (animation == FldMoveAnimSecondary(mode)) {
                if ((animationFrame > 9.0f && animationFrame < 10.0f) || (animationFrame > 19.0f && animationFrame < 20.0f)) {
                    fldPlayAmbientCue(id, 1, area * 4);
                }
            }
        } else if (motionState == 1) {
            if (animation == FldMoveAnimSecondary(mode)) {
                if ((animationFrame > 9.0f && animationFrame < 10.0f) || (animationFrame > 19.0f && animationFrame < 20.0f)) {
                    fldPlayAmbientCue(id, 1, area * 4);
                }
            }
        }
        break;
    case 8:
        if (motionState == 1 &&
            K_FldEvent_ArePosWithinDist(&((RainMatrix *)mdlGetMatrix(model))->pos,
                                        &((RainMatrix *)mdlGetMatrix(D_007EFA00[0]))->pos, 1600.0f) != 0 &&
            animation == FldMoveAnimSecondary(mode)) {
            if ((animationFrame > 8.0f && animationFrame < 9.0f) || (animationFrame > 18.0f && animationFrame < 19.0f)) {
                fldPlayAmbientCue(id, 2, 0x18);
            }
        }
        break;
    default:
        if (motionState == 1 &&
            K_FldEvent_ArePosWithinDist(&((RainMatrix *)mdlGetMatrix(model))->pos,
                                        &((RainMatrix *)mdlGetMatrix(D_007EFA00[0]))->pos, 1600.0f) != 0 &&
            animation == FldMoveAnimSecondary(mode)) {
            if ((animationFrame > 8.0f && animationFrame < 9.0f) || (animationFrame > 18.0f && animationFrame < 19.0f)) {
                fldPlayAmbientCue(id, 2, area * 4);
            }
        }
        break;
    }
}

#pragma push
#pragma opt_propagation off
/* Install the depth, shade and blend states used for the rain PTank draw. */
// FUN_00182B40
/* measured: local table pointer and direct callback-table calls; best baseline residual 59 differing bytes. */
void FldRainRenderStateSet(void)
{
    void (**fn)(s32, s32);

    fn = D_00887300;
    fn[0](7, 2);
    fn[0](6, 1);
    fn[0](8, 0);
    fn[0](0xC, 1);
}
#pragma pop

/* Rain stores real PTank locks, vectors and matrices. Pool indexing and the
 * shared trail/reset counter preserve the observed callback lifetimes.
 * Verified with all owner functions, relocations and owned data. */
// FUN_00182BC0
#pragma push
#pragma opt_loop_invariants on
/* Initialize the camera-facing rain pool, then spawn columns and update each drop trail before queueing its PTank. */
/* PTank plugin slots use a runtime offset; fixed frame, texture, material and strided-lock fields are typed. */
/* measured: access-site fields and existing typed rain alias; best baseline residual 664 differing bytes. */
s32 FldRainUpdate(u8 *task)
{
    FldRainWork *rainWork;
    extern s32 kwlnGetCamera(void);
    extern RainMatrix *func_003e9700(struct RwFrame *frame);
    extern u32 RpRandom(void);
    extern struct RpAtomic *func_003a2340(s32 count, u32 dataFlags, u32 platformFlags);
    extern struct RwFrame *func_003e9320(void);
    extern struct RpAtomic *RpAtomicSetFrame(struct RpAtomic *atomic, struct RwFrame *frame);
    extern s32 func_003a2950(struct RpAtomic *atomic, enum RpPTankSkyRenderState state, u32 value);
    extern RwTexDictionary *func_003ef6d0(void);
    extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
    extern struct RpMaterial *func_003c42b0(struct RpMaterial *material, RwTexture *texture);
    extern void *memcpy(void *dst, const void *previousMatrix, u32 size);
    extern RainMatrix *func_003e0f80(void);
    extern f32 cosf(f32 angle);
    extern f32 sinf(f32 angle);
    extern void chkmemAllocSiteTag(const void *file, s32 line);
    extern f32 RwV3dNormalize(RainVector *dst, const RainVector *previousMatrix);
    extern RainMatrix *RwMatrixScale(RainMatrix *matrix, const RainVector *scale, enum RwOpCombineType combine);
    extern s32 func_003a2770(struct RpAtomic *atomic, RainLock *lock, u32 dataFlags, enum RpPTankLockFlags lockFlags);
    extern struct RpAtomic *func_003a2920(struct RpAtomic *atomic);
    extern u8 *sdkOtQueueDrawObject(u8 *list, s32 stateId);
    extern void FldRainRenderStateSet(void);
    extern void *(*D_008873F4[])(size_t, size_t, u32);
    extern u8 D_005F1D80[];
    extern u8 D_005F1D10[];
    extern u8 D_005F1D70[];
    extern u8 D_00794420[];
    extern f32 fGpffff815c;
    extern f32 fGpffff8198;
    extern f32 fGpffff841c;
    extern s32 iGpffffb610;
    RainLock matrixLock;
    RainLock colorLock;
    RainVector right;
    RainVector up;
    RainVector at;
    RainVector *cameraPosition;
    uintptr_t allocator;
    u8 *work;
    u8 *camera;
    RainDrop *freeDrop;
    s32 columnIndex;
    s32 timerIndex;
    s32 trailIndex;
    RainMatrix *cameraMatrix;
    s32 dropIndex;
    s32 halfSpacing;
    u32 jitter;
    s32 jitterDirection;

    work = ((KwlnTask *)task)->work;
    rainWork = (FldRainWork *)work;
    if (((FldRainWork *)work)->paused != 0) {
        return 0;
    }
    switch (((FldRainWork *)work)->state) {
    case 0:
    {
        u8 *setupCamera;
        f32 columnsNeeded;
        setupCamera = ((u8 *)(uintptr_t)kwlnGetCamera());
        ((FldRainWork *)work)->viewWindow.bytes = (u8 *)((RwCamera *)setupCamera)->viewWindow;
        ((FldRainWork *)work)->spanX = 2.0f * (((RwCamera *)setupCamera)->viewWindow[0] * ((FldRainWork *)work)->distance);
        ((FldRainWork *)work)->spanY = 2.0f * (((FldRainWork *)work)->viewWindow.window[1] * ((FldRainWork *)work)->distance);
        ((FldRainWork *)work)->origin.x = ((FldRainWork *)work)->viewWindow.window[0] * ((FldRainWork *)work)->distance;
        ((FldRainWork *)work)->origin.y = ((FldRainWork *)work)->viewWindow.window[1] * ((FldRainWork *)work)->distance + ((FldRainWork *)work)->spanY / 2.0f;
        ((FldRainWork *)work)->origin.z = ((FldRainWork *)work)->distance;
        columnsNeeded = ((FldRainWork *)work)->spanX / ((FldRainWork *)work)->spacing;
        ((FldRainWork *)work)->columnCount = (s32)columnsNeeded;
        /* measured: typing each retained access on this line loses owner MATCH. */
        if (!((((FldRainWork *)work)->spanX / ((FldRainWork *)work)->spacing) <= (f32)MEMBER(s32, work, FldRainWork, columnCount))) {
            /* measured: typing each retained access on this line loses owner MATCH. */
            rainWork->columnCount = MEMBER(s32, work, FldRainWork, columnCount) + 1;
        }
        rainWork->columnCount = ((FldRainWork *)work)->columnCount + 1;
        ((FldRainWork *)work)->dropCount = ((FldRainWork *)work)->columnCount * 8;
        cosf(fGpffff815c);
        ((FldRainWork *)work)->unk60 = 0;
        ((FldRainWork *)work)->verticalSpeed = ((FldRainWork *)work)->speed * sinf(fGpffff815c);
        ((FldRainWork *)work)->scale.x = ((FldRainWork *)work)->scale.y = ((FldRainWork *)work)->scale.z = rainWork->spacing;
        chkmemAllocSiteTag(D_005F1D80, 0x9D);
        allocator = (uintptr_t)D_008873F4;
        ((FldRainWork *)work)->drops.bytes = (*(RainAllocate *)allocator)(rainWork->dropCount, 0x10, 0x40000);
        for (columnIndex = 0; columnIndex < rainWork->dropCount; columnIndex++) {
            u8 *dropStorage;
            void *motion;
            chkmemAllocSiteTag(D_005F1D80, 0xA2);
            motion = (*(RainAllocate *)allocator)(((FldRainWork *)work)->trailLength, 8, 0x40000);
            dropStorage = rainWork->drops.bytes + columnIndex * 0x10;
            ((RainDrop *)dropStorage)->motion = motion;
        }
        chkmemAllocSiteTag(D_005F1D80, 0xA6);
        ((FldRainWork *)work)->columnTimers.bytes = (*(RainAllocate *)allocator)(rainWork->columnCount, 4, 0x40000);
        for (timerIndex = 0; timerIndex < rainWork->columnCount; timerIndex++) {
            ((s32 *)rainWork->columnTimers.bytes)[timerIndex] = (s32)(RpRandom() % (u32)((FldRainWork *)work)->spawnInterval);
        }
        ((FldRainWork *)work)->intervalJitter = (s32)(fGpffff8198 * (f32)(u32)((FldRainWork *)work)->spawnInterval);
        if (rainWork->intervalJitter == 0) {
            rainWork->intervalJitter = 1;
        }
        ((FldRainWork *)work)->atomic.atomic = func_003a2340(rainWork->dropCount * ((FldRainWork *)work)->trailLength, 0x2008000A, 0);
        ((FldRainWork *)work)->frame.frame = func_003e9320();
        ((RwFrame *)(rainWork->frame.bytes))->modelling.at.z = 1.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.up.y = 1.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.right.x = 1.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.up.x = 0.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.right.z = 0.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.right.y = 0.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.at.y = 0.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.at.x = 0.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.up.z = 0.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.pos.z = 0.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.pos.y = 0.0f;
        ((RwFrame *)(rainWork->frame.bytes))->modelling.pos.x = 0.0f;
        ((RwFrame *)rainWork->frame.bytes)->modelling.flags |= 0x20003;
        RpAtomicSetFrame(rainWork->atomic.atomic, rainWork->frame.frame);
        /* Runtime-selected PTank plugin slot; work-handle typing loses MATCH. */
        ((RpPTankAtomicExtPrv *)(((u8 **)(rainWork->atomic.bytes + iGpffffb610))[0]))->instanceFlags |= 0x800000;
        /* Runtime-selected PTank plugin slot; work-handle typing loses MATCH. */
        ((RpPTankAtomicExtPrv *)(((u8 **)(rainWork->atomic.bytes + iGpffffb610))[0]))->activeCount = 0;
        /* Runtime-selected PTank plugin slot; work-handle typing loses MATCH. */
        ((RpPTankAtomicExtPrv *)(((u8 **)(rainWork->atomic.bytes + iGpffffb610))[0]))->unkB4 = 1;
        func_003a2950(rainWork->atomic.atomic, 1, 0x44);
        func_003a2950(rainWork->atomic.atomic, 2, 0x717FB);
        {
            u8 *texture;
            texture = (u8 *)func_003ef650(func_003ef6d0(), (const char *)(D_005F1D10 + ((FldRainWork *)work)->textureIndex * 0x18));
            ((RwTexture *)texture)->filterAddressing = (((RwTexture *)texture)->filterAddressing & ~0xFF) | 2;
            func_003c42b0(*((struct RpAtomic *)rainWork->atomic.bytes)->geometry->materials, (RwTexture *)texture);
            /* Runtime-selected PTank plugin slot; work-handle typing loses MATCH. */
            memcpy(((RpPTankAtomicExtPrv *)((u8 **)(rainWork->atomic.bytes + iGpffffb610))[0])->unkE0, D_005F1D70, 0x10);
            /* Runtime-selected PTank plugin slot; work-handle typing loses MATCH. */
            ((RpPTankAtomicExtPrv *)(((u8 **)(rainWork->atomic.bytes + iGpffffb610))[0]))->instanceFlags |= 0x80000;
            ((FldRainWork *)work)->matrix.matrix = func_003e0f80();
        }
        ((FldRainWork *)work)->state = ((FldRainWork *)work)->state + 1;
        break;
    }
    case 1:
    {
        camera = ((u8 *)(uintptr_t)kwlnGetCamera());
        cameraMatrix = func_003e9700(((RwFrame *)((RwCamera *)camera)->object.object.parent));
        for (columnIndex = 0; columnIndex < ((FldRainWork *)work)->columnCount; columnIndex++) {
            s32 *columnTimer;
            s32 spawnTimer;
            columnTimer = ((FldRainWork *)work)->columnTimers.timers;
            columnTimer += columnIndex;
            spawnTimer = *columnTimer;
            if (spawnTimer <= 0) {
                s32 dropCount;
                s32 candidateIndex;
                freeDrop = NULL;
                candidateIndex = 0;
                dropCount = ((FldRainWork *)work)->dropCount;
                while (candidateIndex < dropCount) {
                    RainDrop *candidate;
                    candidate = ((FldRainWork *)work)->drops.drops;
                    candidate += candidateIndex;
                    if (candidate->active == 0) {
                        freeDrop = candidate;
                        break;
                    }
                    candidateIndex += 1;
                }
                if (freeDrop != NULL) {
                    f32 spacing;
                    halfSpacing = (s32)(((FldRainWork *)work)->spacing / 2.0f);
                    freeDrop->active = 1;
                    freeDrop->count = (s32)(RpRandom() % (u32)((FldRainWork *)work)->trailLength) + 1;
                    spacing = rainWork->spacing;
                    freeDrop->x = (f32)columnIndex * spacing + (f32)(RpRandom() % (u32)halfSpacing) - spacing / 4.0f;
                }
                jitter = RpRandom() % (u32)(((FldRainWork *)work)->intervalJitter + 1);
                if ((RpRandom() & 1) != 0) {
                    jitterDirection = 1;
                } else {
                    jitterDirection = -1;
                }
                ((s32 *)rainWork->columnTimers.bytes)[columnIndex] = ((FldRainWork *)work)->spawnInterval + (s32)(jitter * jitterDirection);
            } else {
                *columnTimer = spawnTimer - 1;
            }
        }
        func_003a2770(((FldRainWork *)work)->atomic.atomic, &matrixLock, 8, 0x40000000);
        func_003a2770(rainWork->atomic.atomic, &colorLock, 2, 0x40000000);
        ((FldRainWork *)work)->particleCount = 0;
        for (dropIndex = 0; dropIndex < ((FldRainWork *)work)->dropCount; dropIndex++) {
            RainDrop *drop;
            /* measured: typing each retained access on this line loses owner MATCH. */
            drop = MEMBER(RainDrop *, work, FldRainWork, drops.drops);
            if (drop[(u32)dropIndex].active == 0) {
                continue;
            }
            trailIndex = 0;
            /* measured: typing each retained access on this line loses owner MATCH. */
            if ((MEMBER(RainDrop *, work, FldRainWork, drops.drops))[(u32)dropIndex].count <= 0) {
                continue;
            }
            cameraPosition = &cameraMatrix->pos;
            for (; trailIndex < (((FldRainWork *)work)->drops.drops)[(u32)dropIndex].count; trailIndex++) {

                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->at.z = 1.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->up.y = 1.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->right.x = 1.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->up.x = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->right.z = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->right.y = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->at.y = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->at.x = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->up.z = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.z = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.y = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.x = 0.0f;
                ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->flags |= 0x20003;
                right = cameraMatrix->right;
                up = cameraMatrix->up;
                at = cameraMatrix->at;
                RwV3dNormalize(&right, &right);
                RwV3dNormalize(&up, &up);
                RwV3dNormalize(&at, &at);
                *rainWork->matrix.matrix = *cameraMatrix;
                RwMatrixScale(rainWork->matrix.matrix, &((FldRainWork *)work)->scale, rwCOMBINEPOSTCONCAT);
                if (trailIndex > 0) {
                    u8 *previousMatrix;
                    f32 trailSpacing;
                    previousMatrix = matrixLock.data - matrixLock.stride * trailIndex;
                    (((FldRainWork *)work)->matrix.matrix)->pos = ((RainMatrix *)previousMatrix)->pos;
                    trailSpacing = (f32)trailIndex * 2.0f;
                    up.x = up.x * trailSpacing;
                    up.y = up.y * trailSpacing;
                    up.z = up.z * trailSpacing;
                    ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.x = ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.x + up.x;
                    ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.y = ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.y + up.y;
                    ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.z = ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.z + up.z;
                } else {
                    f32 offsetX;
                    f32 offsetY;
                    offsetX = ((FldRainWork *)work)->origin.x - (rainWork->drops.drops)[(u32)dropIndex].x;
                    right.x = right.x * offsetX;
                    right.y = right.y * offsetX;
                    right.z = right.z * offsetX;
                    offsetY = ((FldRainWork *)work)->origin.y - (((FldRainWork *)work)->drops.drops)[(u32)dropIndex].steps[trailIndex].y;
                    up.x = up.x * offsetY;
                    up.y = up.y * offsetY;
                    up.z = up.z * offsetY;
                    at.x = at.x * ((FldRainWork *)work)->distance;
                    at.y = at.y * ((FldRainWork *)work)->distance;
                    at.z = at.z * ((FldRainWork *)work)->distance;
                    ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.x = at.x + (up.x + (cameraPosition->x + right.x));
                    ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.y = at.y + (up.y + (cameraPosition->y + right.y));
                    ((RainMatrix *)(((FldRainWork *)work)->matrix.bytes))->pos.z = at.z + (up.z + (cameraPosition->z + right.z));
                    {
                        f32 *motion;
                        f32 elapsed;
                        f32 acceleration;
                        motion = (f32 *)((u8 *)(((FldRainWork *)work)->drops.drops)[(u32)dropIndex].motion + trailIndex * 8);
                        elapsed = ((RainMotionStep *)motion)->elapsed;
                        acceleration = ((FldRainWork *)work)->acceleration * elapsed;
                        ((RainMotionStep *)motion)->y = ((RainMotionStep *)motion)->y - (((FldRainWork *)work)->verticalSpeed * elapsed - acceleration * elapsed);
                        motion = (f32 *)((u8 *)(((FldRainWork *)work)->drops.drops)[(u32)dropIndex].motion + trailIndex * 8);
                        ((RainMotionStep *)motion)->elapsed = ((RainMotionStep *)motion)->elapsed + fGpffff841c;
                    }
                }
                *(RainMatrix *)matrixLock.data = *rainWork->matrix.matrix;
                ((RwRGBA *)colorLock.data)->red = 0xFF;
                ((RwRGBA *)colorLock.data)->green = 0xFF;
                ((RwRGBA *)colorLock.data)->blue = 0xFF;
                ((RwRGBA *)colorLock.data)->alpha = (u8)(((FldRainWork *)work)->alpha - trailIndex * 5);
                if ((trailIndex == (rainWork->drops.drops)[(u32)dropIndex].count - 1) && (((RainMatrix *)(rainWork->matrix.bytes))->pos.y < -((FldRainWork *)work)->spacing)) {
                    (rainWork->drops.drops)[(u32)dropIndex].active = 0;
                    /* measured: typing each retained access on this line loses owner MATCH. */
                    for (trailIndex = 0; trailIndex < (MEMBER(RainDrop *, work, FldRainWork, drops.drops))[(u32)dropIndex].count; trailIndex++) {
                        /* measured: typing each retained access on this line loses owner MATCH. */
                        (MEMBER(RainDrop *, work, FldRainWork, drops.drops))[(u32)dropIndex].steps[trailIndex].y = 0.0f;
                        (rainWork->drops.drops)[(u32)dropIndex].steps[trailIndex].elapsed = 0.0f;
                    }
                }
                matrixLock.data += matrixLock.stride;
                colorLock.data += colorLock.stride;
                rainWork->particleCount = rainWork->particleCount + 1;
            }
        }
        {
            u8 *plugin;
            /* Runtime-selected PTank plugin slot, not a fixed atomic member. */
            plugin = ((u8 **)(((FldRainWork *)work)->atomic.bytes + iGpffffb610))[0];
            ((RpPTankAtomicExtPrv *)(plugin))->instanceFlags |= 0x800000;
            /* Runtime-selected PTank plugin slot; work-handle typing loses MATCH. */
            ((RpPTankAtomicExtPrv *)(((u8 **)(((FldRainWork *)work)->atomic.bytes + iGpffffb610))[0]))->activeCount = rainWork->particleCount;
        }
        func_003a2920(((FldRainWork *)work)->atomic.atomic);
        {
            u8 *drawNode;
            drawNode = sdkOtQueueDrawObject(D_00794420, rainWork->atomic.handle);
            ((PrimQueueNode *)drawNode)->callback = FldRainRenderStateSet;
            ((PrimQueueNode *)drawNode)->argument.handle = 0;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
/* Release each drop motion buffer, the rain pool, timers and RenderWare handles before freeing task work. */
#pragma opt_propagation off
// FUN_001837F0
/* measured: typed task alias and direct task-work reload; best baseline residual 80 differing bytes. */
void FldRainDestroy(u8 *task)
{
    KwlnTask *rainTask = (KwlnTask *)task;
    u8 *work;
    s32 dropIndex;
    void (**release)(void *);

    work = ((KwlnTask *)task)->work;
    dropIndex = 0;
    while (dropIndex < ((FldRainWork *)work)->dropCount) {
        jtbl_008873EC[0]((u8 *)((RainDrop *)((FldRainWork *)work)->drops.bytes)[dropIndex].motion);
        dropIndex += 1;
    }
    release = jtbl_008873EC;
    release[0](((FldRainWork *)work)->drops.bytes);
    release[0](((FldRainWork *)work)->columnTimers.bytes);
    func_003a2760(((FldRainWork *)work)->atomic.handle);
    func_003e9390(((FldRainWork *)work)->frame.handle);
    if (((FldRainWork *)work)->matrix.handle != 0) {
        func_003e0f40(((FldRainWork *)work)->matrix.handle);
    }
    release[0](rainTask->work);
}
#pragma pop

/* Create a rain child task with the requested texture, depth, motion, trail length and spawn interval. */
// FUN_001838D0
void FldRainTaskCreate(u8 *parent, s32 textureIndex, f32 distance, f32 acceleration,
                   f32 speed, f32 spacing, s32 alpha, s32 trailLength, s32 spawnInterval)
{
    u8 *work;

    chkmemAllocSiteTag(&D_005F1D80, 0x17B);
    work = D_008873F4[0](1, 0x78, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(&iGpffff9f60), 0xF, 0, 0, FldRainUpdate, FldRainDestroy, (u8 *)(work));
    ((FldRainWork *)work)->textureIndex = textureIndex;
    ((FldRainWork *)work)->distance = distance;
    ((FldRainWork *)work)->acceleration = acceleration;
    ((FldRainWork *)work)->speed = speed;
    ((FldRainWork *)work)->spacing = spacing;
    ((FldRainWork *)work)->alpha = alpha;
    ((FldRainWork *)work)->trailLength = trailLength;
    ((FldRainWork *)work)->spawnInterval = spawnInterval;
}

// FUN_001839E0
/* Install the fog blend mode and bind its texture before drawing the queued quads. */
void FldRainRenderStateReset(u8 *unused, u8 *work)
{
    u8 *callback;
    s32 state;

    callback = (u8 *)D_00887300;
    (*(void (**)(s32, s32))callback)(0xE, 0);
    (*(void (**)(s32, s32))callback)(6, 0);
    (*(void (**)(s32, s32))callback)(8, 0);
    (*(void (**)(s32, s32))callback)(0xC, 1);
    (*(void (**)(s32, s32))callback)(7, 2);
    (*(void (**)(s32, s32))callback)(9, 2);
    (*(void (**)(s32, s32))callback)(2, 1);
    RpSkyRenderStateSet(3, 0x71801);
    state = ((FldFogWork *)work)->blendMode;
    switch (state) {
    case 0:
        RpSkyRenderStateSet(2, 0x44);
        break;
    case 1:
        RpSkyRenderStateSet(2, 0x44);
        break;
    case 2:
        RpSkyRenderStateSet(2, 0x71801);
        break;
    case 3:
        RpSkyRenderStateSet(2, 0x42);
        break;
    case 4:
        RpSkyRenderStateSet(2, 6);
        break;
    default:
        break;
    }
    /* The render-state interface consumes the texture handle's leading raster word. */
    (*(void (**)(s32, s32))callback)(1,
                                      /* measured: typing each retained access on this line loses owner MATCH. */
                                      MEMBER(s32, ((FldFogWork *)work)->texture, RwTexture, raster));
}

/* 2026-10-08: opt_lifetimes on lowers fnalign from 1427 to 879 edits. */
/* Matching notes: the state dispatch is a switch (retail tests 1 then 0 and
 * shares one return); the grid offsets convert i * half first ((s32)(u32));
 * the low colour byte is loaded into a u32 before the high byte; the 0xF0 row
 * pointer uses ((s32)columnIndex << 8), distinct from (u32)columnIndex * 0x100;
 * rowIndex is declared before columnIndex and converted inline; each of the
 * four colour-interpolation blocks retains separate channel-delta temporaries (a reused float
 * becomes late split ranges that rotate the temporaries).
 * opt_loop_invariants on is measured: without it b210 keeps the loop
 * invariants in the body and the object no longer fits retail's window.
 */
// FUN_00183B80
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
/* Build a two-by-two fog mesh with vertically interpolated colors, then scroll and wrap its texture coordinates. */
/* Typed quad fields retain the measured signed/unsigned cursor address trees documented above. */
/* measured: typed fog alias and independent lifetime/invariant bisection; best baseline residual 4588 differing bytes. */
s32 FldFogUpdate(u8 *task)
{
    FldFogWork *fogWork;
    extern f32 fabsf(f32 x);
    /* Retail returns zero at 001850F0, 00183BD4. */
    extern s32 kwlnGetCamera(void);
    extern u32 RpRandom(void);
    extern RwTexDictionary *func_003ef6d0(void);
    extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
    extern u8 *PrimAllocQueueNode(void);
    extern void PrimAppendNode(u8 *, u8 *);
    extern u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count);
    extern void FldRainRenderStateReset(u8 *unused, u8 *work);
    extern u8 D_005F1D10[];
    extern u8 D_00794930[];
    u8 *work;
    u8 *quadRow;
    u8 *quad;
    u8 *camera;
    u8 *drawNode;
    f32 gridOffset;
    f32 nearDepth;
    f32 reciprocalDepth;
    f32 highChannel;
    f32 lowChannelFloat;
    f32 channelDelta;
    f32 halfChannelDelta;
    s32 rowIndex;
    s32 columnIndex;
    s32 halfExtent;
    s32 gridCoordinate;
    s32 red;
    s32 green;
    s32 blue;
    s32 alpha;
    f32 top;
    u32 lowChannel;
    f32 highChannel0;
    f32 lowChannelFloat0;
    f32 channelDelta0;
    f32 halfChannelDelta0;
    f32 highChannel1;
    f32 lowChannelFloat1;
    f32 channelDelta1;
    f32 halfChannelDelta1;
    f32 highChannel2;
    f32 lowChannelFloat2;
    f32 channelDelta2;
    f32 halfChannelDelta2;
    f32 highChannel3;
    f32 lowChannelFloat3;
    f32 channelDelta3;
    f32 halfChannelDelta3;

    work = ((KwlnTask *)task)->work;
    fogWork = (FldFogWork *)work;
    camera = ((u8 *)(uintptr_t)kwlnGetCamera());
    nearDepth = ((RwCamera *)camera)->nearPlane;
    reciprocalDepth = 1.0f / nearDepth;
    if (((FldFogWork *)work)->paused != 0) {
        return 0;
    }
    switch (((FldFogWork *)work)->state) {
    case 0:
    {
        ((FldFogWork *)work)->height = ((FldFogWork *)work)->width * (f32)((FldFogWork *)work)->viewportHeight / (f32)((FldFogWork *)work)->viewportWidth;
        ((FldFogWork *)work)->left = -((FldFogWork *)work)->width / 2.0f;
        ((FldFogWork *)work)->top = -((FldFogWork *)work)->height / 2.0f;
        ((FldFogWork *)work)->right = ((FldFogWork *)work)->width / 2.0f;
        ((FldFogWork *)work)->bottom = ((FldFogWork *)work)->height / 2.0f;
        if (((FldFogWork *)work)->scrollX == 0.0f) {
            fogWork->scrollX = ((FldFogWork *)work)->scrollY / 5.0f;
            if ((RpRandom() & 1) != 0) {
                /* measured: typing each retained access on this line loses owner MATCH. */
                MEMBER(f32, work, FldFogWork, scrollX) = MEMBER(f32, work, FldFogWork, scrollX) * -1.0f;
            }
        }
        if (((FldFogWork *)work)->scrollY == 0.0f) {
            fogWork->scrollY = fogWork->scrollX / 5.0f;
            if ((RpRandom() & 1) != 0) {
                /* measured: typing each retained access on this line loses owner MATCH. */
                MEMBER(f32, work, FldFogWork, scrollY) = MEMBER(f32, work, FldFogWork, scrollY) * -1.0f;
            }
        }
        for (rowIndex = 0; rowIndex < 2; rowIndex++) {
            columnIndex = 0;
            quadRow = work + (rowIndex << 9);
            for (; columnIndex < 2; columnIndex++) {
                quad = quadRow + (columnIndex << 8);
                halfExtent = fogWork->viewportWidth / 2;
                gridCoordinate = columnIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                ((FldFogWork *)quad)->quads[0][0][0].x = (f32)((FldFogWork *)work)->x + gridOffset;
                halfExtent = fogWork->viewportHeight / 2;
                gridCoordinate = rowIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                ((FldFogWork *)quad)->quads[0][0][0].y = (f32)((FldFogWork *)work)->y + gridOffset;
                ((FldFogWork *)quad)->quads[0][0][0].z = nearDepth;
                /* measured: typing each retained access on this line loses owner MATCH. */
                halfExtent = MEMBER(s16, work, FldFogWork, viewportWidth) / 2;
                gridCoordinate = columnIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                /* measured: typing each retained access on this line loses owner MATCH. */
                ((FldFogWork *)quad)->quads[0][0][1].x = (f32)MEMBER(s16, work, FldFogWork, viewportWidth) / 2.0f + ((f32)fogWork->x + gridOffset);
                halfExtent = fogWork->viewportHeight / 2;
                gridCoordinate = rowIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                ((FldFogWork *)quad)->quads[0][0][1].y = (f32)fogWork->y + gridOffset;
                ((FldFogWork *)quad)->quads[0][0][1].z = nearDepth;
                halfExtent = fogWork->viewportWidth / 2;
                gridCoordinate = columnIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                ((FldFogWork *)quad)->quads[0][0][2].x = (f32)fogWork->x + gridOffset;
                /* measured: typing each retained access on this line loses owner MATCH. */
                halfExtent = MEMBER(s16, work, FldFogWork, viewportHeight) / 2;
                gridCoordinate = rowIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                /* measured: typing each retained access on this line loses owner MATCH. */
                ((FldFogWork *)quad)->quads[0][0][2].y = (f32)MEMBER(s16, work, FldFogWork, viewportHeight) / 2.0f + ((f32)fogWork->y + gridOffset);
                ((FldFogWork *)quad)->quads[0][0][2].z = nearDepth;
                halfExtent = ((FldFogWork *)work)->viewportWidth / 2;
                gridCoordinate = columnIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                ((FldFogWork *)quad)->quads[0][0][3].x = (f32)((FldFogWork *)work)->viewportWidth / 2.0f + ((f32)fogWork->x + gridOffset);
                halfExtent = ((FldFogWork *)work)->viewportHeight / 2;
                gridCoordinate = rowIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                ((FldFogWork *)quad)->quads[0][0][3].y = (f32)((FldFogWork *)work)->viewportHeight / 2.0f + ((f32)fogWork->y + gridOffset);
                ((FldFogWork *)quad)->quads[0][0][3].z = nearDepth;
                ((FldFogWork *)quad)->quads[0][0][0].reciprocalDepth = reciprocalDepth;
                ((FldFogWork *)quad)->quads[0][0][1].reciprocalDepth = reciprocalDepth;
                ((FldFogWork *)quad)->quads[0][0][2].reciprocalDepth = reciprocalDepth;
                ((FldFogWork *)quad)->quads[0][0][3].reciprocalDepth = reciprocalDepth;
                lowChannel = ((FldFogWork *)work)->colors[0];
                highChannel0 = (f32)(u32)((FldFogWork *)work)->colors[4];
                lowChannelFloat0 = (f32)(u32)lowChannel;
                channelDelta0 = highChannel0 - lowChannelFloat0;
                halfChannelDelta0 = channelDelta0 / 2.0f;
                red = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta0);
                lowChannel = ((FldFogWork *)work)->colors[1];
                highChannel0 = (f32)(u32)((FldFogWork *)work)->colors[5];
                lowChannelFloat0 = (f32)(u32)lowChannel;
                channelDelta0 = highChannel0 - lowChannelFloat0;
                halfChannelDelta0 = channelDelta0 / 2.0f;
                green = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta0);
                lowChannel = ((FldFogWork *)work)->colors[2];
                highChannel0 = (f32)(u32)((FldFogWork *)work)->colors[6];
                lowChannelFloat0 = (f32)(u32)lowChannel;
                channelDelta0 = highChannel0 - lowChannelFloat0;
                halfChannelDelta0 = channelDelta0 / 2.0f;
                blue = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta0);
                lowChannel = ((FldFogWork *)work)->colors[3];
                highChannel0 = (f32)(u32)((FldFogWork *)work)->colors[7];
                lowChannelFloat0 = (f32)(u32)lowChannel;
                channelDelta0 = highChannel0 - lowChannelFloat0;
                halfChannelDelta0 = channelDelta0 / 2.0f;
                alpha = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta0);
                quad = quadRow + ((u32)columnIndex << 8);
                ((FldFogWork *)quad)->quads[0][0][0].red = (f32)red;
                ((FldFogWork *)quad)->quads[0][0][0].green = (f32)green;
                ((FldFogWork *)quad)->quads[0][0][0].blue = (f32)blue;
                ((FldFogWork *)quad)->quads[0][0][0].alpha = (f32)alpha;
                lowChannel = fogWork->colors[0];
                highChannel1 = (f32)(u32)fogWork->colors[4];
                lowChannelFloat1 = (f32)(u32)lowChannel;
                channelDelta1 = highChannel1 - lowChannelFloat1;
                halfChannelDelta1 = channelDelta1 / 2.0f;
                red = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta1);
                lowChannel = fogWork->colors[1];
                highChannel1 = (f32)(u32)fogWork->colors[5];
                lowChannelFloat1 = (f32)(u32)lowChannel;
                channelDelta1 = highChannel1 - lowChannelFloat1;
                halfChannelDelta1 = channelDelta1 / 2.0f;
                green = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta1);
                lowChannel = fogWork->colors[2];
                highChannel1 = (f32)(u32)fogWork->colors[6];
                lowChannelFloat1 = (f32)(u32)lowChannel;
                channelDelta1 = highChannel1 - lowChannelFloat1;
                halfChannelDelta1 = channelDelta1 / 2.0f;
                blue = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta1);
                lowChannel = fogWork->colors[3];
                highChannel1 = (f32)(u32)fogWork->colors[7];
                lowChannelFloat1 = (f32)(u32)lowChannel;
                channelDelta1 = highChannel1 - lowChannelFloat1;
                halfChannelDelta1 = channelDelta1 / 2.0f;
                alpha = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta1);
                quad = quadRow + ((s32)(u32)columnIndex << 8);
                ((FldFogWork *)quad)->quads[0][0][1].red = (f32)red;
                ((FldFogWork *)quad)->quads[0][0][1].green = (f32)green;
                ((FldFogWork *)quad)->quads[0][0][1].blue = (f32)blue;
                ((FldFogWork *)quad)->quads[0][0][1].alpha = (f32)alpha;
                lowChannel = fogWork->colors[0];
                highChannel2 = (f32)(u32)fogWork->colors[4];
                lowChannelFloat2 = (f32)(u32)lowChannel;
                channelDelta2 = highChannel2 - lowChannelFloat2;
                halfChannelDelta2 = channelDelta2 / 2.0f;
                red = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta2);
                lowChannel = fogWork->colors[1];
                highChannel2 = (f32)(u32)fogWork->colors[5];
                lowChannelFloat2 = (f32)(u32)lowChannel;
                channelDelta2 = highChannel2 - lowChannelFloat2;
                halfChannelDelta2 = channelDelta2 / 2.0f;
                green = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta2);
                lowChannel = fogWork->colors[2];
                highChannel2 = (f32)(u32)fogWork->colors[6];
                lowChannelFloat2 = (f32)(u32)lowChannel;
                channelDelta2 = highChannel2 - lowChannelFloat2;
                halfChannelDelta2 = channelDelta2 / 2.0f;
                blue = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta2);
                lowChannel = fogWork->colors[3];
                highChannel2 = (f32)(u32)fogWork->colors[7];
                lowChannelFloat2 = (f32)(u32)lowChannel;
                channelDelta2 = highChannel2 - lowChannelFloat2;
                halfChannelDelta2 = channelDelta2 / 2.0f;
                alpha = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta2);
                quad = quadRow + ((u32)columnIndex * 0x100);
                ((FldFogWork *)quad)->quads[0][0][2].red = (f32)red;
                ((FldFogWork *)quad)->quads[0][0][2].green = (f32)green;
                ((FldFogWork *)quad)->quads[0][0][2].blue = (f32)blue;
                ((FldFogWork *)quad)->quads[0][0][2].alpha = (f32)alpha;
                lowChannel = fogWork->colors[0];
                highChannel3 = (f32)(u32)fogWork->colors[4];
                lowChannelFloat3 = (f32)(u32)lowChannel;
                channelDelta3 = highChannel3 - lowChannelFloat3;
                halfChannelDelta3 = channelDelta3 / 2.0f;
                red = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta3);
                lowChannel = fogWork->colors[1];
                highChannel3 = (f32)(u32)fogWork->colors[5];
                lowChannelFloat3 = (f32)(u32)lowChannel;
                channelDelta3 = highChannel3 - lowChannelFloat3;
                halfChannelDelta3 = channelDelta3 / 2.0f;
                green = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta3);
                lowChannel = fogWork->colors[2];
                highChannel3 = (f32)(u32)fogWork->colors[6];
                lowChannelFloat3 = (f32)(u32)lowChannel;
                channelDelta3 = highChannel3 - lowChannelFloat3;
                halfChannelDelta3 = channelDelta3 / 2.0f;
                blue = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta3);
                lowChannel = fogWork->colors[3];
                highChannel3 = (f32)(u32)fogWork->colors[7];
                lowChannelFloat3 = (f32)(u32)lowChannel;
                channelDelta3 = highChannel3 - lowChannelFloat3;
                halfChannelDelta3 = channelDelta3 / 2.0f;
                alpha = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta3);
                quad = (u8 *)((s32)quadRow + ((s32)columnIndex << 8));
                ((FldFogWork *)quad)->quads[0][0][3].red = (f32)red;
                ((FldFogWork *)quad)->quads[0][0][3].green = (f32)green;
                ((FldFogWork *)quad)->quads[0][0][3].blue = (f32)blue;
                ((FldFogWork *)quad)->quads[0][0][3].alpha = (f32)alpha;
            }
        }
        ((FldFogWork *)work)->texture = (s32)func_003ef650(func_003ef6d0(), (const char *)(D_005F1D10 + ((FldFogWork *)work)->textureIndex * 0x18));
        ((FldFogWork *)work)->halfWidth = (fogWork->right - fogWork->left) / 2.0f;
        ((FldFogWork *)work)->halfHeight = (fogWork->bottom - fogWork->top) / 2.0f;
        ((FldFogWork *)work)->state = ((FldFogWork *)work)->state + 1;
        break;
    }
    case 1:
    {
    drawNode = PrimAllocQueueNode();
    ((PrimQueueNode *)drawNode)->callback = FldRainRenderStateReset;
    ((PrimQueueNode *)drawNode)->argument.data = work;
    PrimAppendNode(D_00794930, drawNode);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            f32 left;
            f32 right;
            f32 bottom;
            /* measured: typing each retained access on this line loses owner MATCH. */
            left = MEMBER(f32, work, FldFogWork, halfWidth) * (f32)columnIndex + MEMBER(f32, work, FldFogWork, left);
            /* measured: typing each retained access on this line loses owner MATCH. */
            top = MEMBER(f32, work, FldFogWork, halfHeight) * (f32)rowIndex + MEMBER(f32, work, FldFogWork, top);
            /* measured: typing each retained access on this line loses owner MATCH. */
            right = MEMBER(f32, work, FldFogWork, halfWidth) * (f32)(columnIndex + 1) + MEMBER(f32, work, FldFogWork, left);
            /* measured: typing each retained access on this line loses owner MATCH. */
            bottom = MEMBER(f32, work, FldFogWork, halfHeight) * (f32)(rowIndex + 1) + MEMBER(f32, work, FldFogWork, top);
            ((FldFogWork *)((work + (rowIndex << 9)) + (columnIndex << 8)))->quads[0][0][0].u = left;
            ((FldFogWork *)((work + (rowIndex << 9)) + (columnIndex << 8)))->quads[0][0][0].v = top;
            ((FldFogWork *)((work + (rowIndex << 9)) + (columnIndex << 8)))->quads[0][0][1].u = right;
            ((FldFogWork *)((work + (rowIndex << 9)) + (columnIndex << 8)))->quads[0][0][1].v = top;
            ((FldFogWork *)((work + (rowIndex << 9)) + (columnIndex << 8)))->quads[0][0][2].u = left;
            ((FldFogWork *)((work + (rowIndex << 9)) + (columnIndex << 8)))->quads[0][0][2].v = bottom;
            ((FldFogWork *)((work + (rowIndex << 9)) + (columnIndex << 8)))->quads[0][0][3].u = right;
            ((FldFogWork *)((work + (rowIndex << 9)) + (columnIndex << 8)))->quads[0][0][3].v = bottom;
            PrimQueueDrawPrimitive(D_00794930, 4, ((work + (rowIndex << 9)) + (columnIndex << 8)) + 0x10, 4);
        }
    }
    ((FldFogWork *)work)->left = ((FldFogWork *)work)->left + ((FldFogWork *)work)->scrollX;
    ((FldFogWork *)work)->top = ((FldFogWork *)work)->top + ((FldFogWork *)work)->scrollY;
    /* measured: typing each retained access on this line loses owner MATCH. */
    MEMBER(f32, work, FldFogWork, right) = MEMBER(f32, work, FldFogWork, right) + fogWork->scrollX;
    /* measured: typing each retained access on this line loses owner MATCH. */
    MEMBER(f32, work, FldFogWork, bottom) = MEMBER(f32, work, FldFogWork, bottom) + fogWork->scrollY;
    {
        f32 origin;

        origin = -((FldFogWork *)work)->width / 2.0f;
        if (!(fabsf(((FldFogWork *)work)->left - origin) < 1.0f)) {
            fogWork->left = origin;
            ((FldFogWork *)work)->right = fogWork->width / 2.0f;
        }
        origin = -((FldFogWork *)work)->height / 2.0f;
        if (!(fabsf(fogWork->top - origin) < 1.0f)) {
            fogWork->top = origin;
            ((FldFogWork *)work)->bottom = fogWork->height / 2.0f;
        }
    }
        break;
    }
    }
    return 0;
}
#pragma pop

// FUN_00185120
void FldFogDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}

#pragma push
#pragma optimization_level 1
/* Create a textured fog task unless both endpoint colors are transparent; copy the viewport and scroll parameters. */
// FUN_00185150
s32 FldFogTaskCreate(s32 parent, s32 textureIndex, f32 width, f32 scrollX,
                  f32 scrollY, s16 x, s16 y, s16 viewportWidth, s16 viewportHeight,
                  s32 blendMode, u8 *colors)
{
    s32 taskHandle;
    u8 *work;
    register u8 *dst;
    register u8 byte0;
    register u8 byte1;
    register u8 byte2;
    register u8 byte3;
    register u8 byte4;
    register u8 byte5;
    register u8 byte6;
    register u8 byte7;

    if (colors[3] == 0 && colors[7] == 0) {
        return 0;
    }
    chkmemAllocSiteTag(&D_005F1D80, 0x43A);
    work = D_008873F4[0](1, 0x460, 0x40000);
    taskHandle = (s32)kwlnTaskCreateChild((void *)((u8 *)parent), (const void *)(&D_005F1D90), 0xF, 0, 0, FldFogUpdate, FldFogDestroy, (u8 *)(work));
    ((FldFogWork *)work)->textureIndex = textureIndex;
    ((FldFogWork *)work)->scrollX = scrollX;
    ((FldFogWork *)work)->scrollY = scrollY;
    ((FldFogWork *)work)->width = width;
    ((FldFogWork *)work)->height = width;
    ((FldFogWork *)work)->x = x;
    ((FldFogWork *)work)->y = y;
    ((FldFogWork *)work)->viewportWidth = viewportWidth;
    ((FldFogWork *)work)->viewportHeight = viewportHeight;
    ((FldFogWork *)work)->blendMode = blendMode;
    dst = ((FldFogWork *)work)->colors;
    byte0 = colors[0];
    byte1 = colors[1];
    byte2 = colors[2];
    byte3 = colors[3];
    dst[0] = byte0;
    dst[1] = byte1;
    dst[2] = byte2;
    dst[3] = byte3;
    byte4 = colors[4];
    byte5 = colors[5];
    byte6 = colors[6];
    byte7 = colors[7];
    dst[4] = byte4;
    dst[5] = byte5;
    dst[6] = byte6;
    dst[7] = byte7;
    return taskHandle;
}
#pragma pop

#pragma push
#pragma optimization_level 1
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
/* Append a GS A+D packet that writes the cached FRAME value to register 0x4C. */
// FUN_001852F0
void FldNoiseEmitTagged(void)
{
    u_long128 *packet;
    u_long128 packed;
    u64 a, b, c;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = (u_long128 *)(u32)iGpffffb884;
    *packet = packed;
    c = 0x4C;
    b = iGpffffb8c8 | 0xFF00000000000000ULL;
    packed = _pcpyld(c, b);
    packet[1] = packed;
    iGpffffb884 += 0x20;
}
#pragma pop

extern unsigned int D_007EFA00[];
extern u8 *MT_Scene_GetResListHead(s32);
extern u32 K_FldEvent_ArePosWithinDist(const RainVector *, const RainVector *, f32);
extern u32 RpRandom(void);
extern unsigned int func_003e0f80(void);
extern int func_003e9700(unsigned int);
extern s32 kwlnGetCamera(void);
extern s16 mdlGetLayerAnimation(s32, s32);
extern void *memcpy(void *dst, const void *src, u32 size);
