/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Kernel/Kwln/kwln.c; members 00182310-001852f0 */

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
typedef char FldRainWorkSize[(sizeof(FldRainWork) == 0x78) ? 1 : -1];
typedef char FldFogWorkSize[(sizeof(FldFogWork) == 0x460) ? 1 : -1];
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

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void FldNoiseEmitTagged(void);
extern void func_003a2760(s32 arg0);
extern void func_003e9390(s32 arg0);
typedef struct RpMaterial *(*MaterialCallback)(struct RpMaterial *, void *);

extern void func_003f3eb0(s32 arg0, s32 arg1);
extern s32 FldFogUpdate(u8 *task);
extern void (*jtbl_008873EC[])(void *);
extern u64 iGpffffb8c8;
extern void func_003e0f40(s32 arg0);
extern struct RpMaterial *func_003c42b0(struct RpMaterial *material, RwTexture *texture);
extern RwTexDictionary *func_003ef6d0(void);
extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
extern u8 iGpffffb310;
extern void memset(void *dst, s32 value, s32 size);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 kwlnGetCamera(void);
extern s16 mdlGetLayerAnimation(s32 arg0, s32 arg1);
extern u8 *mdlGetMatrix(u32 arg0);
extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
extern f32 sinf(f32 arg0);
extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
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
// FUN_00182310
/* Broadcast a state value to the linked auxiliary task of each occupied, active actor slot. */
/* The auxiliary task at actor+0x1B0 and its state payload have no shared recovered owning type; keep those two offsets explicit. */
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
            task = *(u8 **)(slot + 0x1B0);
            if (task != NULL) {
                *(s32 *)(((KwlnTask *)task)->work + 4) = state;
            }
        }
        slotIndex += 1;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_00182390
void FldAmbientFlagClear(void)
{
    memset(&iGpffffb310, 0, 4);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// FUN_001823C0
u8 *FldAmbientFlagPtr(void)
{
    return &iGpffffb310;
}
#pragma pop

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

#pragma push
#pragma opt_loop_invariants off
// FUN_001823D0
/* Select an ambient surface cue from the containing area quad and trigger it at the actor animation footfall frames. */
/* The model status at +0xD4 has no recovered model-object type; the remaining area and matrix offsets are typed below. */
void FldAmbientTrigger(s32 model, u16 mode, u16 id)
{
    extern u8 *MT_Scene_GetResListHead(s32 model);
    extern s32 K_FldFrame_IsPointInTriangle(f32 *point, f32 **vertices, f32 *normal);
    extern s32 FldMoveAnimPrimary(s32 model);
    extern s32 FldMoveAnimSecondary(s32 model);
    extern u32 K_FldEvent_ArePosWithinDist(const struct RwV3d *posA, const struct RwV3d *posB, f32 maxDist);
    extern f32 mdlGetLayerWeight(s32 model, s32 arg1);
    extern u8 *D_005F08B0[];
    s32 area;
    f32 *position;
    SceneQuadResource *areaNode;
    u16 animation;
    u16 motionState;
    f32 animationFrame;
    s32 fieldId;
    s32 roomId;

    motionState = *(u16 *)(model + 0xD4);
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
                    func_001823d0_play(id, 1, area * 4);
                }
            } else if (animation == FldMoveAnimSecondary(mode)) {
                if ((animationFrame > 9.0f && animationFrame < 10.0f) || (animationFrame > 19.0f && animationFrame < 20.0f)) {
                    func_001823d0_play(id, 1, area * 4);
                }
            }
        } else if (motionState == 1) {
            if (animation == FldMoveAnimSecondary(mode)) {
                if ((animationFrame > 9.0f && animationFrame < 10.0f) || (animationFrame > 19.0f && animationFrame < 20.0f)) {
                    func_001823d0_play(id, 1, area * 4);
                }
            }
        }
        break;
    case 8:
        if (motionState == 1 &&
            K_FldEvent_ArePosWithinDist((struct RwV3d *)(mdlGetMatrix(model) + 0x30),
                                        (struct RwV3d *)(mdlGetMatrix(D_007EFA00[0]) + 0x30), 1600.0f) != 0 &&
            animation == FldMoveAnimSecondary(mode)) {
            if ((animationFrame > 8.0f && animationFrame < 9.0f) || (animationFrame > 18.0f && animationFrame < 19.0f)) {
                func_001823d0_play(id, 2, 0x18);
            }
        }
        break;
    default:
        if (motionState == 1 &&
            K_FldEvent_ArePosWithinDist((struct RwV3d *)(mdlGetMatrix(model) + 0x30),
                                        (struct RwV3d *)(mdlGetMatrix(D_007EFA00[0]) + 0x30), 1600.0f) != 0 &&
            animation == FldMoveAnimSecondary(mode)) {
            if ((animationFrame > 8.0f && animationFrame < 9.0f) || (animationFrame > 18.0f && animationFrame < 19.0f)) {
                func_001823d0_play(id, 2, area * 4);
            }
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
// FUN_00182B40
/* Install the depth, shade and blend states used for the rain PTank draw. */
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

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Rain stores real PTank locks, vectors and matrices. Pool indexing and the
 * shared trail/reset counter preserve the observed callback lifetimes.
 * Verified with all owner functions, relocations and owned data. */
// FUN_00182BC0
#pragma push
#pragma opt_loop_invariants on
/* Initialize the camera-facing rain pool, then spawn columns and update each drop trail before queueing its PTank. */
/* RenderWare frame/texture/PTank plugin words and strided lock streams remain raw: plugin offsets are runtime-selected, and integer identity stores preserve float bit patterns. */
/* Raw accesses preserve MATCH: the FldRainWork member rewrite changed instruction selection and allocation; the constructor-proven layout is documented above. */
s32 FldRainUpdate(u8 *task)
{
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
    extern void chkmemAllocSiteTag(const void *msg, s32 id);
    extern f32 RwV3dNormalize(RainVector *dst, const RainVector *previousMatrix);
    extern RainMatrix *RwMatrixScale(RainMatrix *matrix, const RainVector *scale, enum RwOpCombineType combine);
    extern s32 func_003a2770(struct RpAtomic *atomic, RainLock *lock, u32 dataFlags, enum RpPTankLockFlags lockFlags);
    extern struct RpAtomic *func_003a2920(struct RpAtomic *atomic);
    extern u8 *func_00460d80(u8 *list, s32 payload);
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

    work = *(u8 **)(task + 0x38);
    if (*(s32 *)(work + 4) != 0) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
    {
        u8 *setupCamera;
        f32 columnsNeeded;
        setupCamera = ((u8 *)(uintptr_t)kwlnGetCamera());
        *(u8 **)(work + 0x44) = setupCamera + 0x68;
        *(f32 *)(work + 0x54) = 2.0f * (*(f32 *)(setupCamera + 0x68) * *(f32 *)(work + 0x18));
        *(f32 *)(work + 0x58) = 2.0f * (*(f32 *)(*(u8 **)(work + 0x44) + 4) * *(f32 *)(work + 0x18));
        *(f32 *)(work + 0x48) = *(f32 *)(*(u8 **)(work + 0x44)) * *(f32 *)(work + 0x18);
        *(f32 *)(work + 0x4C) = *(f32 *)(*(u8 **)(work + 0x44) + 4) * *(f32 *)(work + 0x18) + *(f32 *)(work + 0x58) / 2.0f;
        *(f32 *)(work + 0x50) = *(f32 *)(work + 0x18);
        columnsNeeded = *(f32 *)(work + 0x54) / *(f32 *)(work + 0x20);
        *(s32 *)(work + 0x34) = (s32)columnsNeeded;
        if (!((*(f32 *)(work + 0x54) / *(f32 *)(work + 0x20)) <= (f32)*(s32 *)(work + 0x34))) {
            *(s32 *)(work + 0x34) = *(s32 *)(work + 0x34) + 1;
        }
        *(s32 *)(work + 0x34) = *(s32 *)(work + 0x34) + 1;
        *(s32 *)(work + 0x40) = *(s32 *)(work + 0x34) * 8;
        cosf(fGpffff815c);
        *(s32 *)(work + 0x60) = 0;
        *(f32 *)(work + 0x64) = *(f32 *)(work + 0x1C) * sinf(fGpffff815c);
        *(f32 *)(work + 0x68) = *(f32 *)(work + 0x6C) = *(f32 *)(work + 0x70) = *(f32 *)(work + 0x20);
        chkmemAllocSiteTag(D_005F1D80, 0x9D);
        allocator = (uintptr_t)D_008873F4;
        *(u8 **)(work + 0x5C) = (*(RainAllocate *)allocator)(*(s32 *)(work + 0x40), 0x10, 0x40000);
        for (columnIndex = 0; columnIndex < *(s32 *)(work + 0x40); columnIndex++) {
            u8 *dropStorage;
            void *motion;
            chkmemAllocSiteTag(D_005F1D80, 0xA2);
            motion = (*(RainAllocate *)allocator)(*(s32 *)(work + 0x2C), 8, 0x40000);
            dropStorage = *(u8 **)(work + 0x5C) + columnIndex * 0x10;
            *(void **)(dropStorage + 0x0C) = motion;
        }
        chkmemAllocSiteTag(D_005F1D80, 0xA6);
        *(u8 **)(work + 0x38) = (*(RainAllocate *)allocator)(*(s32 *)(work + 0x34), 4, 0x40000);
        for (timerIndex = 0; timerIndex < *(s32 *)(work + 0x34); timerIndex++) {
            *(s32 *)(*(u8 **)(work + 0x38) + timerIndex * 4) = (s32)(RpRandom() % (u32)*(s32 *)(work + 0x30));
        }
        *(s32 *)(work + 0x3C) = (s32)(fGpffff8198 * (f32)(u32)*(s32 *)(work + 0x30));
        if (*(s32 *)(work + 0x3C) == 0) {
            *(s32 *)(work + 0x3C) = 1;
        }
        *(struct RpAtomic **)(work + 8) = func_003a2340(*(s32 *)(work + 0x40) * *(s32 *)(work + 0x2C), 0x2008000A, 0);
        *(struct RwFrame **)(work + 0x0C) = func_003e9320();
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x38) = 0x3F800000;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x24) = 0x3F800000;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x10) = 0x3F800000;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x20) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x18) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x14) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x34) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x30) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x28) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x48) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x44) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x40) = 0;
        *(s32 *)(*(u8 **)(work + 0x0C) + 0x1C) |= 0x20003;
        RpAtomicSetFrame(*(struct RpAtomic **)(work + 8), *(struct RwFrame **)(work + 0x0C));
        *(s32 *)(*(u8 **)(*(u8 **)(work + 8) + iGpffffb610) + 0x40) |= 0x800000;
        *(s32 *)(*(u8 **)(*(u8 **)(work + 8) + iGpffffb610) + 4) = 0;
        *(s32 *)(*(u8 **)(*(u8 **)(work + 8) + iGpffffb610) + 0xB4) = 1;
        func_003a2950(*(struct RpAtomic **)(work + 8), 1, 0x44);
        func_003a2950(*(struct RpAtomic **)(work + 8), 2, 0x717FB);
        {
            u8 *texture;
            texture = (u8 *)func_003ef650(func_003ef6d0(), (const char *)(D_005F1D10 + *(s32 *)(work + 0x28) * 0x18));
            *(s32 *)(texture + 0x50) = (*(s32 *)(texture + 0x50) & ~0xFF) | 2;
            func_003c42b0(**(struct RpMaterial ***)(*(u8 **)(*(u8 **)(work + 8) + 0x18) + 0x20), (RwTexture *)texture);
            memcpy(*(u8 **)(*(u8 **)(work + 8) + iGpffffb610) + 0xE0, D_005F1D70, 0x10);
            *(s32 *)(*(u8 **)(*(u8 **)(work + 8) + iGpffffb610) + 0x40) |= 0x80000;
            *(RainMatrix **)(work + 0x10) = func_003e0f80();
        }
        *(s32 *)work = *(s32 *)work + 1;
        break;
    }
    case 1:
    {
        camera = ((u8 *)(uintptr_t)kwlnGetCamera());
        cameraMatrix = func_003e9700(*(struct RwFrame **)(camera + 4));
        for (columnIndex = 0; columnIndex < *(s32 *)(work + 0x34); columnIndex++) {
            s32 *columnTimer;
            s32 spawnTimer;
            columnTimer = *(s32 **)(work + 0x38);
            columnTimer += columnIndex;
            spawnTimer = *columnTimer;
            if (spawnTimer <= 0) {
                s32 dropCount;
                s32 candidateIndex;
                freeDrop = NULL;
                candidateIndex = 0;
                dropCount = *(s32 *)(work + 0x40);
                while (candidateIndex < dropCount) {
                    RainDrop *candidate;
                    candidate = *(RainDrop **)(work + 0x5C);
                    candidate += candidateIndex;
                    if (candidate->active == 0) {
                        freeDrop = candidate;
                        break;
                    }
                    candidateIndex += 1;
                }
                if (freeDrop != NULL) {
                    f32 spacing;
                    halfSpacing = (s32)(*(f32 *)(work + 0x20) / 2.0f);
                    freeDrop->active = 1;
                    freeDrop->count = (s32)(RpRandom() % (u32)*(s32 *)(work + 0x2C)) + 1;
                    spacing = *(f32 *)(work + 0x20);
                    freeDrop->x = (f32)columnIndex * spacing + (f32)(RpRandom() % (u32)halfSpacing) - spacing / 4.0f;
                }
                jitter = RpRandom() % (u32)(*(s32 *)(work + 0x3C) + 1);
                if ((RpRandom() & 1) != 0) {
                    jitterDirection = 1;
                } else {
                    jitterDirection = -1;
                }
                *(s32 *)(*(u8 **)(work + 0x38) + columnIndex * 4) = *(s32 *)(work + 0x30) + (s32)(jitter * jitterDirection);
            } else {
                *columnTimer = spawnTimer - 1;
            }
        }
        func_003a2770(*(struct RpAtomic **)(work + 8), &matrixLock, 8, 0x40000000);
        func_003a2770(*(struct RpAtomic **)(work + 8), &colorLock, 2, 0x40000000);
        *(s32 *)(work + 0x74) = 0;
        for (dropIndex = 0; dropIndex < *(s32 *)(work + 0x40); dropIndex++) {
            RainDrop *drop;
            drop = *(RainDrop **)(work + 0x5C);
            if (drop[(u32)dropIndex].active == 0) {
                continue;
            }
            trailIndex = 0;
            if ((*(RainDrop **)(work + 0x5C))[(u32)dropIndex].count <= 0) {
                continue;
            }
            cameraPosition = &cameraMatrix->pos;
            for (; trailIndex < (*(RainDrop **)(work + 0x5C))[(u32)dropIndex].count; trailIndex++) {

                *(s32 *)(*(u8 **)(work + 0x10) + 0x28) = 0x3F800000;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x14) = 0x3F800000;
                *(s32 *)(*(u8 **)(work + 0x10)) = 0x3F800000;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x10) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 8) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 4) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x24) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x20) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x18) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x38) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x34) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x30) = 0;
                *(s32 *)(*(u8 **)(work + 0x10) + 0x0C) |= 0x20003;
                right = cameraMatrix->right;
                up = cameraMatrix->up;
                at = cameraMatrix->at;
                RwV3dNormalize(&right, &right);
                RwV3dNormalize(&up, &up);
                RwV3dNormalize(&at, &at);
                **(RainMatrix **)(work + 0x10) = *cameraMatrix;
                RwMatrixScale(*(RainMatrix **)(work + 0x10), (RainVector *)(work + 0x68), rwCOMBINEPOSTCONCAT);
                if (trailIndex > 0) {
                    u8 *previousMatrix;
                    f32 trailSpacing;
                    previousMatrix = matrixLock.data - matrixLock.stride * trailIndex;
                    (*(RainMatrix **)(work + 0x10))->pos = ((RainMatrix *)previousMatrix)->pos;
                    trailSpacing = (f32)trailIndex * 2.0f;
                    up.x = up.x * trailSpacing;
                    up.y = up.y * trailSpacing;
                    up.z = up.z * trailSpacing;
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x30) = *(f32 *)(*(u8 **)(work + 0x10) + 0x30) + up.x;
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x34) = *(f32 *)(*(u8 **)(work + 0x10) + 0x34) + up.y;
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x38) = *(f32 *)(*(u8 **)(work + 0x10) + 0x38) + up.z;
                } else {
                    f32 offsetX;
                    f32 offsetY;
                    offsetX = *(f32 *)(work + 0x48) - (*(RainDrop **)(work + 0x5C))[(u32)dropIndex].x;
                    right.x = right.x * offsetX;
                    right.y = right.y * offsetX;
                    right.z = right.z * offsetX;
                    offsetY = *(f32 *)(work + 0x4C) - *(f32 *)((u8 *)(*(RainDrop **)(work + 0x5C))[(u32)dropIndex].motion + trailIndex * 8 + 4);
                    up.x = up.x * offsetY;
                    up.y = up.y * offsetY;
                    up.z = up.z * offsetY;
                    at.x = at.x * *(f32 *)(work + 0x18);
                    at.y = at.y * *(f32 *)(work + 0x18);
                    at.z = at.z * *(f32 *)(work + 0x18);
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x30) = at.x + (up.x + (cameraPosition->x + right.x));
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x34) = at.y + (up.y + (cameraPosition->y + right.y));
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x38) = at.z + (up.z + (cameraPosition->z + right.z));
                    {
                        f32 *motion;
                        f32 elapsed;
                        f32 acceleration;
                        motion = (f32 *)((u8 *)(*(RainDrop **)(work + 0x5C))[(u32)dropIndex].motion + trailIndex * 8);
                        elapsed = *motion;
                        acceleration = *(f32 *)(work + 0x14) * elapsed;
                        *(motion + 1) = *(motion + 1) - (*(f32 *)(work + 0x64) * elapsed - acceleration * elapsed);
                        motion = (f32 *)((u8 *)(*(RainDrop **)(work + 0x5C))[(u32)dropIndex].motion + trailIndex * 8);
                        *motion = *motion + fGpffff841c;
                    }
                }
                *(RainMatrix *)matrixLock.data = **(RainMatrix **)(work + 0x10);
                *(u8 *)(colorLock.data + 0) = 0xFF;
                *(u8 *)(colorLock.data + 1) = 0xFF;
                *(u8 *)(colorLock.data + 2) = 0xFF;
                *(u8 *)(colorLock.data + 3) = (u8)(*(s32 *)(work + 0x24) - trailIndex * 5);
                if ((trailIndex == (*(RainDrop **)(work + 0x5C))[(u32)dropIndex].count - 1) && (*(f32 *)(*(u8 **)(work + 0x10) + 0x34) < -*(f32 *)(work + 0x20))) {
                    (*(RainDrop **)(work + 0x5C))[(u32)dropIndex].active = 0;
                    for (trailIndex = 0; trailIndex < (*(RainDrop **)(work + 0x5C))[(u32)dropIndex].count; trailIndex++) {
                        *(s32 *)((u8 *)(*(RainDrop **)(work + 0x5C))[(u32)dropIndex].motion + trailIndex * 8 + 4) = 0;
                        *(s32 *)((u8 *)(*(RainDrop **)(work + 0x5C))[(u32)dropIndex].motion + trailIndex * 8) = 0;
                    }
                }
                matrixLock.data += matrixLock.stride;
                colorLock.data += colorLock.stride;
                *(s32 *)(work + 0x74) = *(s32 *)(work + 0x74) + 1;
            }
        }
        {
            u8 *plugin;
            plugin = *(u8 **)(*(u8 **)(work + 8) + iGpffffb610);
            *(s32 *)(plugin + 0x40) |= 0x800000;
            *(s32 *)(*(u8 **)(*(u8 **)(work + 8) + iGpffffb610) + 4) = *(s32 *)(work + 0x74);
        }
        func_003a2920(*(struct RpAtomic **)(work + 8));
        {
            u8 *drawNode;
            drawNode = func_00460d80(D_00794420, *(s32 *)(work + 8));
            *(void (**)(void))(drawNode + 8) = FldRainRenderStateSet;
            *(s32 *)(drawNode + 0x10) = 0;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}
#pragma pop
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_001837F0
#pragma opt_propagation off
/* Release each drop motion buffer, the rain pool, timers and RenderWare handles before freeing task work. */
/* Drop-buffer byte strides are retained so each motion pointer is freed using the original allocation address. */
/* Raw accesses preserve MATCH: the FldRainWork member rewrite changed instruction selection and allocation; the constructor-proven layout is documented above. */
void FldRainDestroy(u8 *task)
{
    u8 *work;
    s32 dropIndex;
    void (**release)(void *);

    work = *(u8 **)(task + 0x38);
    dropIndex = 0;
    while (dropIndex < *(s32 *)(work + 0x40)) {
        jtbl_008873EC[0](*(u8 **)(*(u8 **)(work + 0x5C) + dropIndex * 0x10 + 0xC));
        dropIndex += 1;
    }
    release = jtbl_008873EC;
    release[0](*(u8 **)(work + 0x5C));
    release[0](*(u8 **)(work + 0x38));
    func_003a2760(*(s32 *)(work + 8));
    func_003e9390(*(s32 *)(work + 0xC));
    if (*(s32 *)(work + 0x10) != 0) {
        func_003e0f40(*(s32 *)(work + 0x10));
    }
    release[0](*(u8 **)(task + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_001838D0
/* Create a rain child task with the requested texture, depth, motion, trail length and spawn interval. */
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
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
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
                                      *(s32 *)(((FldFogWork *)work)->texture));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
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
/* Quad byte cursors retain the measured signed/unsigned address trees documented above; UV slots lie in the shared vertex type padding. */
/* Raw accesses preserve MATCH: the FldFogWork member rewrite changed instruction selection and allocation; the constructor-proven layout is documented above. */
s32 FldFogUpdate(u8 *task)
{
    extern f32 fabsf(f32 x);
    /* Retail returns zero at 001850F0, 00183BD4. */
    extern s32 kwlnGetCamera(void);
    extern u32 RpRandom(void);
    extern RwTexDictionary *func_003ef6d0(void);
    extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
    extern u8 *PrimAllocQueueNode(void);
    extern void PrimAppendNode(u8 *, u8 *);
    extern u8 *PrimQueueDrawPrimitive(void *task, s32 arg1, void *arg2, s32 arg3);
    extern void FldRainRenderStateReset(u8 *task, u8 *arg1);
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

    work = *(u8 **)(task + 0x38);
    camera = ((u8 *)(uintptr_t)kwlnGetCamera());
    nearDepth = *(f32 *)(camera + 0x80);
    reciprocalDepth = 1.0f / nearDepth;
    if (*(s32 *)(work + 4) != 0) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
    {
        *(f32 *)(work + 0x428) = *(f32 *)(work + 0x424) * (f32)*(s16 *)(work + 0x43A) / (f32)*(s16 *)(work + 0x438);
        *(f32 *)(work + 0x450) = -*(f32 *)(work + 0x424) / 2.0f;
        *(f32 *)(work + 0x454) = -*(f32 *)(work + 0x428) / 2.0f;
        *(f32 *)(work + 0x458) = *(f32 *)(work + 0x424) / 2.0f;
        *(f32 *)(work + 0x45C) = *(f32 *)(work + 0x428) / 2.0f;
        if (*(f32 *)(work + 0x414) == 0.0f) {
            *(f32 *)(work + 0x414) = *(f32 *)(work + 0x418) / 5.0f;
            if ((RpRandom() & 1) != 0) {
                *(f32 *)(work + 0x414) = *(f32 *)(work + 0x414) * -1.0f;
            }
        }
        if (*(f32 *)(work + 0x418) == 0.0f) {
            *(f32 *)(work + 0x418) = *(f32 *)(work + 0x414) / 5.0f;
            if ((RpRandom() & 1) != 0) {
                *(f32 *)(work + 0x418) = *(f32 *)(work + 0x418) * -1.0f;
            }
        }
        for (rowIndex = 0; rowIndex < 2; rowIndex++) {
            columnIndex = 0;
            quadRow = work + (rowIndex << 9);
            for (; columnIndex < 2; columnIndex++) {
                quad = quadRow + (columnIndex << 8);
                halfExtent = *(s16 *)(work + 0x438) / 2;
                gridCoordinate = columnIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                *(f32 *)(quad + 0x10) = (f32)*(s16 *)(work + 0x434) + gridOffset;
                halfExtent = *(s16 *)(work + 0x43A) / 2;
                gridCoordinate = rowIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                *(f32 *)(quad + 0x14) = (f32)*(s16 *)(work + 0x436) + gridOffset;
                *(f32 *)(quad + 0x18) = nearDepth;
                halfExtent = *(s16 *)(work + 0x438) / 2;
                gridCoordinate = columnIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                *(f32 *)(quad + 0x50) = (f32)*(s16 *)(work + 0x438) / 2.0f + ((f32)*(s16 *)(work + 0x434) + gridOffset);
                halfExtent = *(s16 *)(work + 0x43A) / 2;
                gridCoordinate = rowIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                *(f32 *)(quad + 0x54) = (f32)*(s16 *)(work + 0x436) + gridOffset;
                *(f32 *)(quad + 0x58) = nearDepth;
                halfExtent = *(s16 *)(work + 0x438) / 2;
                gridCoordinate = columnIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                *(f32 *)(quad + 0x90) = (f32)*(s16 *)(work + 0x434) + gridOffset;
                halfExtent = *(s16 *)(work + 0x43A) / 2;
                gridCoordinate = rowIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                *(f32 *)(quad + 0x94) = (f32)*(s16 *)(work + 0x43A) / 2.0f + ((f32)*(s16 *)(work + 0x436) + gridOffset);
                *(f32 *)(quad + 0x98) = nearDepth;
                halfExtent = *(s16 *)(work + 0x438) / 2;
                gridCoordinate = columnIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                *(f32 *)(quad + 0xD0) = (f32)*(s16 *)(work + 0x438) / 2.0f + ((f32)*(s16 *)(work + 0x434) + gridOffset);
                halfExtent = *(s16 *)(work + 0x43A) / 2;
                gridCoordinate = rowIndex * halfExtent;
                gridOffset = (f32)(s32)(u32)gridCoordinate;
                *(f32 *)(quad + 0xD4) = (f32)*(s16 *)(work + 0x43A) / 2.0f + ((f32)*(s16 *)(work + 0x436) + gridOffset);
                *(f32 *)(quad + 0xD8) = nearDepth;
                *(f32 *)(quad + 0x28) = reciprocalDepth;
                *(f32 *)(quad + 0x68) = reciprocalDepth;
                *(f32 *)(quad + 0xA8) = reciprocalDepth;
                *(f32 *)(quad + 0xE8) = reciprocalDepth;
                lowChannel = *(u8 *)(work + 0x440);
                highChannel0 = (f32)(u32)*(u8 *)(work + 0x444);
                lowChannelFloat0 = (f32)(u32)lowChannel;
                channelDelta0 = highChannel0 - lowChannelFloat0;
                halfChannelDelta0 = channelDelta0 / 2.0f;
                red = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta0);
                lowChannel = *(u8 *)(work + 0x441);
                highChannel0 = (f32)(u32)*(u8 *)(work + 0x445);
                lowChannelFloat0 = (f32)(u32)lowChannel;
                channelDelta0 = highChannel0 - lowChannelFloat0;
                halfChannelDelta0 = channelDelta0 / 2.0f;
                green = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta0);
                lowChannel = *(u8 *)(work + 0x442);
                highChannel0 = (f32)(u32)*(u8 *)(work + 0x446);
                lowChannelFloat0 = (f32)(u32)lowChannel;
                channelDelta0 = highChannel0 - lowChannelFloat0;
                halfChannelDelta0 = channelDelta0 / 2.0f;
                blue = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta0);
                lowChannel = *(u8 *)(work + 0x443);
                highChannel0 = (f32)(u32)*(u8 *)(work + 0x447);
                lowChannelFloat0 = (f32)(u32)lowChannel;
                channelDelta0 = highChannel0 - lowChannelFloat0;
                halfChannelDelta0 = channelDelta0 / 2.0f;
                alpha = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta0);
                quad = quadRow + ((u32)columnIndex << 8);
                *(f32 *)(quad + 0x30) = (f32)red;
                *(f32 *)(quad + 0x34) = (f32)green;
                *(f32 *)(quad + 0x38) = (f32)blue;
                *(f32 *)(quad + 0x3C) = (f32)alpha;
                lowChannel = *(u8 *)(work + 0x440);
                highChannel1 = (f32)(u32)*(u8 *)(work + 0x444);
                lowChannelFloat1 = (f32)(u32)lowChannel;
                channelDelta1 = highChannel1 - lowChannelFloat1;
                halfChannelDelta1 = channelDelta1 / 2.0f;
                red = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta1);
                lowChannel = *(u8 *)(work + 0x441);
                highChannel1 = (f32)(u32)*(u8 *)(work + 0x445);
                lowChannelFloat1 = (f32)(u32)lowChannel;
                channelDelta1 = highChannel1 - lowChannelFloat1;
                halfChannelDelta1 = channelDelta1 / 2.0f;
                green = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta1);
                lowChannel = *(u8 *)(work + 0x442);
                highChannel1 = (f32)(u32)*(u8 *)(work + 0x446);
                lowChannelFloat1 = (f32)(u32)lowChannel;
                channelDelta1 = highChannel1 - lowChannelFloat1;
                halfChannelDelta1 = channelDelta1 / 2.0f;
                blue = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta1);
                lowChannel = *(u8 *)(work + 0x443);
                highChannel1 = (f32)(u32)*(u8 *)(work + 0x447);
                lowChannelFloat1 = (f32)(u32)lowChannel;
                channelDelta1 = highChannel1 - lowChannelFloat1;
                halfChannelDelta1 = channelDelta1 / 2.0f;
                alpha = (s32)((f32)(u32)lowChannel + (f32)rowIndex * halfChannelDelta1);
                quad = quadRow + ((s32)(u32)columnIndex << 8);
                *(f32 *)(quad + 0x70) = (f32)red;
                *(f32 *)(quad + 0x74) = (f32)green;
                *(f32 *)(quad + 0x78) = (f32)blue;
                *(f32 *)(quad + 0x7C) = (f32)alpha;
                lowChannel = *(u8 *)(work + 0x440);
                highChannel2 = (f32)(u32)*(u8 *)(work + 0x444);
                lowChannelFloat2 = (f32)(u32)lowChannel;
                channelDelta2 = highChannel2 - lowChannelFloat2;
                halfChannelDelta2 = channelDelta2 / 2.0f;
                red = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta2);
                lowChannel = *(u8 *)(work + 0x441);
                highChannel2 = (f32)(u32)*(u8 *)(work + 0x445);
                lowChannelFloat2 = (f32)(u32)lowChannel;
                channelDelta2 = highChannel2 - lowChannelFloat2;
                halfChannelDelta2 = channelDelta2 / 2.0f;
                green = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta2);
                lowChannel = *(u8 *)(work + 0x442);
                highChannel2 = (f32)(u32)*(u8 *)(work + 0x446);
                lowChannelFloat2 = (f32)(u32)lowChannel;
                channelDelta2 = highChannel2 - lowChannelFloat2;
                halfChannelDelta2 = channelDelta2 / 2.0f;
                blue = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta2);
                lowChannel = *(u8 *)(work + 0x443);
                highChannel2 = (f32)(u32)*(u8 *)(work + 0x447);
                lowChannelFloat2 = (f32)(u32)lowChannel;
                channelDelta2 = highChannel2 - lowChannelFloat2;
                halfChannelDelta2 = channelDelta2 / 2.0f;
                alpha = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta2);
                quad = quadRow + ((u32)columnIndex * 0x100);
                *(f32 *)(quad + 0xB0) = (f32)red;
                *(f32 *)(quad + 0xB4) = (f32)green;
                *(f32 *)(quad + 0xB8) = (f32)blue;
                *(f32 *)(quad + 0xBC) = (f32)alpha;
                lowChannel = *(u8 *)(work + 0x440);
                highChannel3 = (f32)(u32)*(u8 *)(work + 0x444);
                lowChannelFloat3 = (f32)(u32)lowChannel;
                channelDelta3 = highChannel3 - lowChannelFloat3;
                halfChannelDelta3 = channelDelta3 / 2.0f;
                red = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta3);
                lowChannel = *(u8 *)(work + 0x441);
                highChannel3 = (f32)(u32)*(u8 *)(work + 0x445);
                lowChannelFloat3 = (f32)(u32)lowChannel;
                channelDelta3 = highChannel3 - lowChannelFloat3;
                halfChannelDelta3 = channelDelta3 / 2.0f;
                green = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta3);
                lowChannel = *(u8 *)(work + 0x442);
                highChannel3 = (f32)(u32)*(u8 *)(work + 0x446);
                lowChannelFloat3 = (f32)(u32)lowChannel;
                channelDelta3 = highChannel3 - lowChannelFloat3;
                halfChannelDelta3 = channelDelta3 / 2.0f;
                blue = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta3);
                lowChannel = *(u8 *)(work + 0x443);
                highChannel3 = (f32)(u32)*(u8 *)(work + 0x447);
                lowChannelFloat3 = (f32)(u32)lowChannel;
                channelDelta3 = highChannel3 - lowChannelFloat3;
                halfChannelDelta3 = channelDelta3 / 2.0f;
                alpha = (s32)((f32)(u32)lowChannel + ((f32)(rowIndex + 1)) * halfChannelDelta3);
                quad = (u8 *)((s32)quadRow + ((s32)columnIndex << 8));
                *(f32 *)(quad + 0xF0) = (f32)red;
                *(f32 *)(quad + 0xF4) = (f32)green;
                *(f32 *)(quad + 0xF8) = (f32)blue;
                *(f32 *)(quad + 0xFC) = (f32)alpha;
            }
        }
        *(s32 *)(work + 0x410) = (s32)func_003ef650(func_003ef6d0(), (const char *)(D_005F1D10 + *(s32 *)(work + 0x420) * 0x18));
        *(f32 *)(work + 0x42C) = (*(f32 *)(work + 0x458) - *(f32 *)(work + 0x450)) / 2.0f;
        *(f32 *)(work + 0x430) = (*(f32 *)(work + 0x45C) - *(f32 *)(work + 0x454)) / 2.0f;
        *(s32 *)work = *(s32 *)work + 1;
        break;
    }
    case 1:
    {
    drawNode = PrimAllocQueueNode();
    *(void (**)(u8 *, u8 *))(drawNode + 8) = FldRainRenderStateReset;
    *(u8 **)(drawNode + 0x10) = work;
    PrimAppendNode(D_00794930, drawNode);
    for (rowIndex = 0; rowIndex < 2; rowIndex++) {
        for (columnIndex = 0; columnIndex < 2; columnIndex++) {
            f32 left;
            f32 right;
            f32 bottom;
            left = *(f32 *)(work + 0x42C) * (f32)columnIndex + *(f32 *)(work + 0x450);
            top = *(f32 *)(work + 0x430) * (f32)rowIndex + *(f32 *)(work + 0x454);
            right = *(f32 *)(work + 0x42C) * (f32)(columnIndex + 1) + *(f32 *)(work + 0x450);
            bottom = *(f32 *)(work + 0x430) * (f32)(rowIndex + 1) + *(f32 *)(work + 0x454);
            *(f32 *)(((work + (rowIndex << 9)) + (columnIndex << 8)) + 0x20) = left;
            *(f32 *)(((work + (rowIndex << 9)) + (columnIndex << 8)) + 0x24) = top;
            *(f32 *)(((work + (rowIndex << 9)) + (columnIndex << 8)) + 0x60) = right;
            *(f32 *)(((work + (rowIndex << 9)) + (columnIndex << 8)) + 0x64) = top;
            *(f32 *)(((work + (rowIndex << 9)) + (columnIndex << 8)) + 0xA0) = left;
            *(f32 *)(((work + (rowIndex << 9)) + (columnIndex << 8)) + 0xA4) = bottom;
            *(f32 *)(((work + (rowIndex << 9)) + (columnIndex << 8)) + 0xE0) = right;
            *(f32 *)(((work + (rowIndex << 9)) + (columnIndex << 8)) + 0xE4) = bottom;
            PrimQueueDrawPrimitive(D_00794930, 4, ((work + (rowIndex << 9)) + (columnIndex << 8)) + 0x10, 4);
        }
    }
    *(f32 *)(work + 0x450) = *(f32 *)(work + 0x450) + *(f32 *)(work + 0x414);
    *(f32 *)(work + 0x454) = *(f32 *)(work + 0x454) + *(f32 *)(work + 0x418);
    *(f32 *)(work + 0x458) = *(f32 *)(work + 0x458) + *(f32 *)(work + 0x414);
    *(f32 *)(work + 0x45C) = *(f32 *)(work + 0x45C) + *(f32 *)(work + 0x418);
    {
        f32 origin;

        origin = -*(f32 *)(work + 0x424) / 2.0f;
        if (!(fabsf(*(f32 *)(work + 0x450) - origin) < 1.0f)) {
            *(f32 *)(work + 0x450) = origin;
            *(f32 *)(work + 0x458) = *(f32 *)(work + 0x424) / 2.0f;
        }
        origin = -*(f32 *)(work + 0x428) / 2.0f;
        if (!(fabsf(*(f32 *)(work + 0x454) - origin) < 1.0f)) {
            *(f32 *)(work + 0x454) = origin;
            *(f32 *)(work + 0x45C) = *(f32 *)(work + 0x428) / 2.0f;
        }
    }
        break;
    }
    }
    return 0;
}
#pragma pop
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_00185120
void FldFogDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
// FUN_00185150
/* Create a textured fog task unless both endpoint colors are transparent; copy the viewport and scroll parameters. */
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
    dst = work + 0x440;
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
// FUN_001852F0
/* Append a GS A+D packet that writes the cached FRAME value to register 0x4C. */
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
