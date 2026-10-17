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
void FldSlotBroadcastState(s32 arg0)
{
    s32 i;
    s32 one;
    s32 stride;
    s32 hit;
    u8 *p;
    u8 *temp;

    i = 0;
    one = 1;
    stride = 0x750;
    while (i < 0xF) {
        hit = 0;
        p = D_007E8C00 + i * stride;
        if (*(s32 *)(p + 0x48) != 0 && *(s32 *)(p + 0x54) != 0) {
            hit = one;
        }
        hit = hit != 0;
        if (hit != 0) {
            temp = *(u8 **)(p + 0x1B0);
            if (temp != NULL) {
                *(s32 *)(*(u8 **)(temp + 0x38) + 4) = arg0;
            }
        }
        i += 1;
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
void FldAmbientTrigger(s32 arg0, u16 mode, u16 id)
{
    extern u8 *MT_Scene_GetResListHead(s32 arg0);
    extern s32 K_FldFrame_IsPointInTriangle(f32 *point, f32 **vertices, f32 *normal);
    extern s32 FldMoveAnimPrimary(s32 arg0);
    extern s32 FldMoveAnimSecondary(s32 arg0);
    extern u32 K_FldEvent_ArePosWithinDist(const struct RwV3d *posA, const struct RwV3d *posB, f32 maxDist);
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    extern u8 *D_005F08B0[];
    s32 area;
    f32 *pos;
    u8 *node;
    u16 stat;
    u16 status;
    f32 time;
    s32 index;
    s32 offset;

    status = *(u16 *)(arg0 + 0xD4);
    stat = mdlGetLayerAnimation(arg0, 0);
    time = mdlGetLayerWeight(arg0, 0);
    if (((s32 *)iGpffff9db0)[0] >= 200) {
        return;
    }
    pos = (f32 *)(mdlGetMatrix(arg0) + 0x30);
    node = MT_Scene_GetResListHead(0x15);
    index = ((s32 *)iGpffff9db0)[0];
    offset = ((s32 *)iGpffff9db0)[1];
    if (D_005F08B0[index] == NULL) {
        area = 0;
    } else {
        area = D_005F08B0[index][offset];
        for (; node != NULL; node = *(u8 **)(node + 0x138)) {
            f32 *tri[3];
            FldAreaNormal normal = {0.0f, 1.0f, 0.0f};

            tri[0] = (f32 *)(node + 0x15C);
            tri[1] = (f32 *)(node + 0x168);
            tri[2] = (f32 *)(node + 0x174);
            if (K_FldFrame_IsPointInTriangle(pos, tri, &normal.x) == 1 &&
                pos[1] < 100.0f + tri[0][1] && pos[1] > tri[0][1] - 100.0f) {
                area = *(s32 *)(node + 0x18C);
                break;
            }
            tri[0] = (f32 *)(node + 0x168);
            tri[1] = (f32 *)(node + 0x174);
            tri[2] = (f32 *)(node + 0x180);
            if (K_FldFrame_IsPointInTriangle(pos, tri, &normal.x) == 1 &&
                pos[1] < 100.0f + tri[0][1] && pos[1] > tri[0][1] - 100.0f) {
                area = *(s32 *)(node + 0x18C);
                break;
            }
        }
    }
    switch (mode) {
    case 1:
        if (status == 9) {
            if (stat == FldMoveAnimPrimary(mode)) {
                if ((time > 7.0f && time < 8.0f) || (time > 21.0f && time < 22.0f)) {
                    func_001823d0_play(id, 1, area * 4);
                }
            } else if (stat == FldMoveAnimSecondary(mode)) {
                if ((time > 9.0f && time < 10.0f) || (time > 19.0f && time < 20.0f)) {
                    func_001823d0_play(id, 1, area * 4);
                }
            }
        } else if (status == 1) {
            if (stat == FldMoveAnimSecondary(mode)) {
                if ((time > 9.0f && time < 10.0f) || (time > 19.0f && time < 20.0f)) {
                    func_001823d0_play(id, 1, area * 4);
                }
            }
        }
        break;
    case 8:
        if (status == 1 &&
            K_FldEvent_ArePosWithinDist((struct RwV3d *)(mdlGetMatrix(arg0) + 0x30),
                                        (struct RwV3d *)(mdlGetMatrix(D_007EFA00[0]) + 0x30), 1600.0f) != 0 &&
            stat == FldMoveAnimSecondary(mode)) {
            if ((time > 8.0f && time < 9.0f) || (time > 18.0f && time < 19.0f)) {
                func_001823d0_play(id, 2, 0x18);
            }
        }
        break;
    default:
        if (status == 1 &&
            K_FldEvent_ArePosWithinDist((struct RwV3d *)(mdlGetMatrix(arg0) + 0x30),
                                        (struct RwV3d *)(mdlGetMatrix(D_007EFA00[0]) + 0x30), 1600.0f) != 0 &&
            stat == FldMoveAnimSecondary(mode)) {
            if ((time > 8.0f && time < 9.0f) || (time > 18.0f && time < 19.0f)) {
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
    extern void *memcpy(void *dst, const void *src, u32 size);
    extern RainMatrix *func_003e0f80(void);
    extern f32 cosf(f32 angle);
    extern f32 sinf(f32 angle);
    extern void chkmemAllocSiteTag(const void *msg, s32 id);
    extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
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
        u8 *tmp;
        f32 f0;
        tmp = ((u8 *)(uintptr_t)kwlnGetCamera());
        *(u8 **)(work + 0x44) = tmp + 0x68;
        *(f32 *)(work + 0x54) = 2.0f * (*(f32 *)(tmp + 0x68) * *(f32 *)(work + 0x18));
        *(f32 *)(work + 0x58) = 2.0f * (*(f32 *)(*(u8 **)(work + 0x44) + 4) * *(f32 *)(work + 0x18));
        *(f32 *)(work + 0x48) = *(f32 *)(*(u8 **)(work + 0x44)) * *(f32 *)(work + 0x18);
        *(f32 *)(work + 0x4C) = *(f32 *)(*(u8 **)(work + 0x44) + 4) * *(f32 *)(work + 0x18) + *(f32 *)(work + 0x58) / 2.0f;
        *(f32 *)(work + 0x50) = *(f32 *)(work + 0x18);
        f0 = *(f32 *)(work + 0x54) / *(f32 *)(work + 0x20);
        *(s32 *)(work + 0x34) = (s32)f0;
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
            u8 *slotp;
            void *motion;
            chkmemAllocSiteTag(D_005F1D80, 0xA2);
            motion = (*(RainAllocate *)allocator)(*(s32 *)(work + 0x2C), 8, 0x40000);
            slotp = *(u8 **)(work + 0x5C) + columnIndex * 0x10;
            *(void **)(slotp + 0x0C) = motion;
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
            u8 *e;
            e = (u8 *)func_003ef650(func_003ef6d0(), (const char *)(D_005F1D10 + *(s32 *)(work + 0x28) * 0x18));
            *(s32 *)(e + 0x50) = (*(s32 *)(e + 0x50) & ~0xFF) | 2;
            func_003c42b0(**(struct RpMaterial ***)(*(u8 **)(*(u8 **)(work + 8) + 0x18) + 0x20), (RwTexture *)e);
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
            s32 *slot;
            s32 cur;
            slot = *(s32 **)(work + 0x38);
            slot += columnIndex;
            cur = *slot;
            if (cur <= 0) {
                s32 n;
                s32 idx;
                freeDrop = NULL;
                idx = 0;
                n = *(s32 *)(work + 0x40);
                while (idx < n) {
                    RainDrop *cand;
                    cand = *(RainDrop **)(work + 0x5C);
                    cand += idx;
                    if (cand->active == 0) {
                        freeDrop = cand;
                        break;
                    }
                    idx += 1;
                }
                if (freeDrop != NULL) {
                    f32 fw;
                    halfSpacing = (s32)(*(f32 *)(work + 0x20) / 2.0f);
                    freeDrop->active = 1;
                    freeDrop->count = (s32)(RpRandom() % (u32)*(s32 *)(work + 0x2C)) + 1;
                    fw = *(f32 *)(work + 0x20);
                    freeDrop->x = (f32)columnIndex * fw + (f32)(RpRandom() % (u32)halfSpacing) - fw / 4.0f;
                }
                jitter = RpRandom() % (u32)(*(s32 *)(work + 0x3C) + 1);
                if ((RpRandom() & 1) != 0) {
                    jitterDirection = 1;
                } else {
                    jitterDirection = -1;
                }
                *(s32 *)(*(u8 **)(work + 0x38) + columnIndex * 4) = *(s32 *)(work + 0x30) + (s32)(jitter * jitterDirection);
            } else {
                *slot = cur - 1;
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
                    u8 *src;
                    f32 sc;
                    src = matrixLock.data - matrixLock.stride * trailIndex;
                    (*(RainMatrix **)(work + 0x10))->pos = ((RainMatrix *)src)->pos;
                    sc = (f32)trailIndex * 2.0f;
                    up.x = up.x * sc;
                    up.y = up.y * sc;
                    up.z = up.z * sc;
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x30) = *(f32 *)(*(u8 **)(work + 0x10) + 0x30) + up.x;
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x34) = *(f32 *)(*(u8 **)(work + 0x10) + 0x34) + up.y;
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x38) = *(f32 *)(*(u8 **)(work + 0x10) + 0x38) + up.z;
                } else {
                    f32 d0;
                    f32 d1;
                    d0 = *(f32 *)(work + 0x48) - (*(RainDrop **)(work + 0x5C))[(u32)dropIndex].x;
                    right.x = right.x * d0;
                    right.y = right.y * d0;
                    right.z = right.z * d0;
                    d1 = *(f32 *)(work + 0x4C) - *(f32 *)((u8 *)(*(RainDrop **)(work + 0x5C))[(u32)dropIndex].motion + trailIndex * 8 + 4);
                    up.x = up.x * d1;
                    up.y = up.y * d1;
                    up.z = up.z * d1;
                    at.x = at.x * *(f32 *)(work + 0x18);
                    at.y = at.y * *(f32 *)(work + 0x18);
                    at.z = at.z * *(f32 *)(work + 0x18);
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x30) = at.x + (up.x + (cameraPosition->x + right.x));
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x34) = at.y + (up.y + (cameraPosition->y + right.y));
                    *(f32 *)(*(u8 **)(work + 0x10) + 0x38) = at.z + (up.z + (cameraPosition->z + right.z));
                    {
                        f32 *fp;
                        f32 vv;
                        f32 acceleration;
                        fp = (f32 *)((u8 *)(*(RainDrop **)(work + 0x5C))[(u32)dropIndex].motion + trailIndex * 8);
                        vv = *fp;
                        acceleration = *(f32 *)(work + 0x14) * vv;
                        *(fp + 1) = *(fp + 1) - (*(f32 *)(work + 0x64) * vv - acceleration * vv);
                        fp = (f32 *)((u8 *)(*(RainDrop **)(work + 0x5C))[(u32)dropIndex].motion + trailIndex * 8);
                        *fp = *fp + fGpffff841c;
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
            u8 *base;
            base = *(u8 **)(*(u8 **)(work + 8) + iGpffffb610);
            *(s32 *)(base + 0x40) |= 0x800000;
            *(s32 *)(*(u8 **)(*(u8 **)(work + 8) + iGpffffb610) + 4) = *(s32 *)(work + 0x74);
        }
        func_003a2920(*(struct RpAtomic **)(work + 8));
        {
            u8 *res;
            res = func_00460d80(D_00794420, *(s32 *)(work + 8));
            *(void (**)(void))(res + 8) = FldRainRenderStateSet;
            *(s32 *)(res + 0x10) = 0;
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
void FldRainDestroy(u8 *arg0)
{
    u8 *temp_16;
    s32 var_17;
    void (**base)(void *);

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_17 = 0;
    while (var_17 < *(s32 *)(temp_16 + 0x40)) {
        jtbl_008873EC[0](*(u8 **)(*(u8 **)(temp_16 + 0x5C) + var_17 * 0x10 + 0xC));
        var_17 += 1;
    }
    base = jtbl_008873EC;
    base[0](*(u8 **)(temp_16 + 0x5C));
    base[0](*(u8 **)(temp_16 + 0x38));
    func_003a2760(*(s32 *)(temp_16 + 8));
    func_003e9390(*(s32 *)(temp_16 + 0xC));
    if (*(s32 *)(temp_16 + 0x10) != 0) {
        func_003e0f40(*(s32 *)(temp_16 + 0x10));
    }
    base[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_001838D0
void FldRainTaskCreate(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *temp_2;

    chkmemAllocSiteTag(&D_005F1D80, 0x17B);
    temp_2 = D_008873F4[0](1, 0x78, 0x40000);
    (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&iGpffff9f60), 0xF, 0, 0, FldRainUpdate, FldRainDestroy, (u8 *)(temp_2));
    *(s32 *)(temp_2 + 0x28) = arg1;
    *(f32 *)(temp_2 + 0x18) = fparg0;
    *(f32 *)(temp_2 + 0x14) = fparg1;
    *(f32 *)(temp_2 + 0x1C) = fparg2;
    *(f32 *)(temp_2 + 0x20) = fparg3;
    *(s32 *)(temp_2 + 0x24) = arg2;
    *(s32 *)(temp_2 + 0x2C) = arg3;
    *(s32 *)(temp_2 + 0x30) = arg4;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_001839E0
void FldRainRenderStateReset(u8 *arg0, u8 *arg1)
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
    state = *(s32 *)(arg1 + 0x43C);
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
    (*(void (**)(s32, s32))callback)(1,
                                      *(s32 *)(*(u8 **)(arg1 + 0x410)));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* 2026-10-08: opt_lifetimes on lowers fnalign from 1427 to 879 edits. */
/* Matching notes: the state dispatch is a switch (retail tests 1 then 0 and
 * shares one return); the grid offsets convert i * half first ((s32)(u32));
 * the low colour byte is loaded into a u32 before the high byte; the 0xF0 row
 * pointer uses ((s32)k << 8) so b210 does not CSE it with (u32)k * 0x100;
 * m is declared before k; (f32)m is written inline; and each of the four
 * colour-interpolation blocks has its own fhi/flo/fdiff/fhalf (a reused float
 * becomes late split ranges that rotate the temporaries).
 * opt_loop_invariants on is measured: without it b210 keeps the loop
 * invariants in the body and the object no longer fits retail's window.
 */
// FUN_00183B80
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
s32 FldFogUpdate(u8 *arg0)
{
    extern f32 fabsf(f32 x);
    /* Retail returns zero at 001850F0, 00183BD4. */
    extern s32 kwlnGetCamera(void);
    extern u32 RpRandom(void);
    extern RwTexDictionary *func_003ef6d0(void);
    extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
    extern u8 *PrimAllocQueueNode(void);
    extern void PrimAppendNode(u8 *, u8 *);
    extern u8 *PrimQueueDrawPrimitive(void *arg0, s32 arg1, void *arg2, s32 arg3);
    extern void FldRainRenderStateReset(u8 *arg0, u8 *arg1);
    extern u8 D_005F1D10[];
    extern u8 D_00794930[];
    u8 *ctx;
    u8 *base;
    u8 *q;
    u8 *tmp;
    u8 *pkt;
    f32 fprod;
    f32 f21;
    f32 f20;
    f32 fhi;
    f32 flo;
    f32 fdiff;
    f32 fhalf;
    s32 m;
    s32 k;
    s32 half;
    s32 prod;
    s32 iv0;
    s32 iv1;
    s32 iv2;
    s32 iv3;
    f32 v1;
    u32 lo;
    f32 fhi_0;
    f32 flo_0;
    f32 fdiff_0;
    f32 fhalf_0;
    f32 fhi_1;
    f32 flo_1;
    f32 fdiff_1;
    f32 fhalf_1;
    f32 fhi_2;
    f32 flo_2;
    f32 fdiff_2;
    f32 fhalf_2;
    f32 fhi_3;
    f32 flo_3;
    f32 fdiff_3;
    f32 fhalf_3;

    ctx = *(u8 **)(arg0 + 0x38);
    tmp = ((u8 *)(uintptr_t)kwlnGetCamera());
    f21 = *(f32 *)(tmp + 0x80);
    f20 = 1.0f / f21;
    if (*(s32 *)(ctx + 4) != 0) {
        return 0;
    }
    switch (*(s32 *)ctx) {
    case 0:
    {
        *(f32 *)(ctx + 0x428) = *(f32 *)(ctx + 0x424) * (f32)*(s16 *)(ctx + 0x43A) / (f32)*(s16 *)(ctx + 0x438);
        *(f32 *)(ctx + 0x450) = -*(f32 *)(ctx + 0x424) / 2.0f;
        *(f32 *)(ctx + 0x454) = -*(f32 *)(ctx + 0x428) / 2.0f;
        *(f32 *)(ctx + 0x458) = *(f32 *)(ctx + 0x424) / 2.0f;
        *(f32 *)(ctx + 0x45C) = *(f32 *)(ctx + 0x428) / 2.0f;
        if (*(f32 *)(ctx + 0x414) == 0.0f) {
            *(f32 *)(ctx + 0x414) = *(f32 *)(ctx + 0x418) / 5.0f;
            if ((RpRandom() & 1) != 0) {
                *(f32 *)(ctx + 0x414) = *(f32 *)(ctx + 0x414) * -1.0f;
            }
        }
        if (*(f32 *)(ctx + 0x418) == 0.0f) {
            *(f32 *)(ctx + 0x418) = *(f32 *)(ctx + 0x414) / 5.0f;
            if ((RpRandom() & 1) != 0) {
                *(f32 *)(ctx + 0x418) = *(f32 *)(ctx + 0x418) * -1.0f;
            }
        }
        for (m = 0; m < 2; m++) {
            k = 0;
            base = ctx + (m << 9);
            for (; k < 2; k++) {
                q = base + (k << 8);
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = k * half;
                fprod = (f32)(s32)(u32)prod;
                *(f32 *)(q + 0x10) = (f32)*(s16 *)(ctx + 0x434) + fprod;
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = m * half;
                fprod = (f32)(s32)(u32)prod;
                *(f32 *)(q + 0x14) = (f32)*(s16 *)(ctx + 0x436) + fprod;
                *(f32 *)(q + 0x18) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = k * half;
                fprod = (f32)(s32)(u32)prod;
                *(f32 *)(q + 0x50) = (f32)*(s16 *)(ctx + 0x438) / 2.0f + ((f32)*(s16 *)(ctx + 0x434) + fprod);
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = m * half;
                fprod = (f32)(s32)(u32)prod;
                *(f32 *)(q + 0x54) = (f32)*(s16 *)(ctx + 0x436) + fprod;
                *(f32 *)(q + 0x58) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = k * half;
                fprod = (f32)(s32)(u32)prod;
                *(f32 *)(q + 0x90) = (f32)*(s16 *)(ctx + 0x434) + fprod;
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = m * half;
                fprod = (f32)(s32)(u32)prod;
                *(f32 *)(q + 0x94) = (f32)*(s16 *)(ctx + 0x43A) / 2.0f + ((f32)*(s16 *)(ctx + 0x436) + fprod);
                *(f32 *)(q + 0x98) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = k * half;
                fprod = (f32)(s32)(u32)prod;
                *(f32 *)(q + 0xD0) = (f32)*(s16 *)(ctx + 0x438) / 2.0f + ((f32)*(s16 *)(ctx + 0x434) + fprod);
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = m * half;
                fprod = (f32)(s32)(u32)prod;
                *(f32 *)(q + 0xD4) = (f32)*(s16 *)(ctx + 0x43A) / 2.0f + ((f32)*(s16 *)(ctx + 0x436) + fprod);
                *(f32 *)(q + 0xD8) = f21;
                *(f32 *)(q + 0x28) = f20;
                *(f32 *)(q + 0x68) = f20;
                *(f32 *)(q + 0xA8) = f20;
                *(f32 *)(q + 0xE8) = f20;
                lo = *(u8 *)(ctx + 0x440);
                fhi_0 = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo_0 = (f32)(u32)lo;
                fdiff_0 = fhi_0 - flo_0;
                fhalf_0 = fdiff_0 / 2.0f;
                iv0 = (s32)((f32)(u32)lo + (f32)m * fhalf_0);
                lo = *(u8 *)(ctx + 0x441);
                fhi_0 = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo_0 = (f32)(u32)lo;
                fdiff_0 = fhi_0 - flo_0;
                fhalf_0 = fdiff_0 / 2.0f;
                iv1 = (s32)((f32)(u32)lo + (f32)m * fhalf_0);
                lo = *(u8 *)(ctx + 0x442);
                fhi_0 = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo_0 = (f32)(u32)lo;
                fdiff_0 = fhi_0 - flo_0;
                fhalf_0 = fdiff_0 / 2.0f;
                iv2 = (s32)((f32)(u32)lo + (f32)m * fhalf_0);
                lo = *(u8 *)(ctx + 0x443);
                fhi_0 = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo_0 = (f32)(u32)lo;
                fdiff_0 = fhi_0 - flo_0;
                fhalf_0 = fdiff_0 / 2.0f;
                iv3 = (s32)((f32)(u32)lo + (f32)m * fhalf_0);
                q = base + ((u32)k << 8);
                *(f32 *)(q + 0x30) = (f32)iv0;
                *(f32 *)(q + 0x34) = (f32)iv1;
                *(f32 *)(q + 0x38) = (f32)iv2;
                *(f32 *)(q + 0x3C) = (f32)iv3;
                lo = *(u8 *)(ctx + 0x440);
                fhi_1 = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo_1 = (f32)(u32)lo;
                fdiff_1 = fhi_1 - flo_1;
                fhalf_1 = fdiff_1 / 2.0f;
                iv0 = (s32)((f32)(u32)lo + (f32)m * fhalf_1);
                lo = *(u8 *)(ctx + 0x441);
                fhi_1 = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo_1 = (f32)(u32)lo;
                fdiff_1 = fhi_1 - flo_1;
                fhalf_1 = fdiff_1 / 2.0f;
                iv1 = (s32)((f32)(u32)lo + (f32)m * fhalf_1);
                lo = *(u8 *)(ctx + 0x442);
                fhi_1 = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo_1 = (f32)(u32)lo;
                fdiff_1 = fhi_1 - flo_1;
                fhalf_1 = fdiff_1 / 2.0f;
                iv2 = (s32)((f32)(u32)lo + (f32)m * fhalf_1);
                lo = *(u8 *)(ctx + 0x443);
                fhi_1 = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo_1 = (f32)(u32)lo;
                fdiff_1 = fhi_1 - flo_1;
                fhalf_1 = fdiff_1 / 2.0f;
                iv3 = (s32)((f32)(u32)lo + (f32)m * fhalf_1);
                q = base + ((s32)(u32)k << 8);
                *(f32 *)(q + 0x70) = (f32)iv0;
                *(f32 *)(q + 0x74) = (f32)iv1;
                *(f32 *)(q + 0x78) = (f32)iv2;
                *(f32 *)(q + 0x7C) = (f32)iv3;
                lo = *(u8 *)(ctx + 0x440);
                fhi_2 = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo_2 = (f32)(u32)lo;
                fdiff_2 = fhi_2 - flo_2;
                fhalf_2 = fdiff_2 / 2.0f;
                iv0 = (s32)((f32)(u32)lo + ((f32)(m + 1)) * fhalf_2);
                lo = *(u8 *)(ctx + 0x441);
                fhi_2 = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo_2 = (f32)(u32)lo;
                fdiff_2 = fhi_2 - flo_2;
                fhalf_2 = fdiff_2 / 2.0f;
                iv1 = (s32)((f32)(u32)lo + ((f32)(m + 1)) * fhalf_2);
                lo = *(u8 *)(ctx + 0x442);
                fhi_2 = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo_2 = (f32)(u32)lo;
                fdiff_2 = fhi_2 - flo_2;
                fhalf_2 = fdiff_2 / 2.0f;
                iv2 = (s32)((f32)(u32)lo + ((f32)(m + 1)) * fhalf_2);
                lo = *(u8 *)(ctx + 0x443);
                fhi_2 = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo_2 = (f32)(u32)lo;
                fdiff_2 = fhi_2 - flo_2;
                fhalf_2 = fdiff_2 / 2.0f;
                iv3 = (s32)((f32)(u32)lo + ((f32)(m + 1)) * fhalf_2);
                q = base + ((u32)k * 0x100);
                *(f32 *)(q + 0xB0) = (f32)iv0;
                *(f32 *)(q + 0xB4) = (f32)iv1;
                *(f32 *)(q + 0xB8) = (f32)iv2;
                *(f32 *)(q + 0xBC) = (f32)iv3;
                lo = *(u8 *)(ctx + 0x440);
                fhi_3 = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo_3 = (f32)(u32)lo;
                fdiff_3 = fhi_3 - flo_3;
                fhalf_3 = fdiff_3 / 2.0f;
                iv0 = (s32)((f32)(u32)lo + ((f32)(m + 1)) * fhalf_3);
                lo = *(u8 *)(ctx + 0x441);
                fhi_3 = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo_3 = (f32)(u32)lo;
                fdiff_3 = fhi_3 - flo_3;
                fhalf_3 = fdiff_3 / 2.0f;
                iv1 = (s32)((f32)(u32)lo + ((f32)(m + 1)) * fhalf_3);
                lo = *(u8 *)(ctx + 0x442);
                fhi_3 = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo_3 = (f32)(u32)lo;
                fdiff_3 = fhi_3 - flo_3;
                fhalf_3 = fdiff_3 / 2.0f;
                iv2 = (s32)((f32)(u32)lo + ((f32)(m + 1)) * fhalf_3);
                lo = *(u8 *)(ctx + 0x443);
                fhi_3 = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo_3 = (f32)(u32)lo;
                fdiff_3 = fhi_3 - flo_3;
                fhalf_3 = fdiff_3 / 2.0f;
                iv3 = (s32)((f32)(u32)lo + ((f32)(m + 1)) * fhalf_3);
                q = (u8 *)((s32)base + ((s32)k << 8));
                *(f32 *)(q + 0xF0) = (f32)iv0;
                *(f32 *)(q + 0xF4) = (f32)iv1;
                *(f32 *)(q + 0xF8) = (f32)iv2;
                *(f32 *)(q + 0xFC) = (f32)iv3;
            }
        }
        *(s32 *)(ctx + 0x410) = (s32)func_003ef650(func_003ef6d0(), (const char *)(D_005F1D10 + *(s32 *)(ctx + 0x420) * 0x18));
        *(f32 *)(ctx + 0x42C) = (*(f32 *)(ctx + 0x458) - *(f32 *)(ctx + 0x450)) / 2.0f;
        *(f32 *)(ctx + 0x430) = (*(f32 *)(ctx + 0x45C) - *(f32 *)(ctx + 0x454)) / 2.0f;
        *(s32 *)ctx = *(s32 *)ctx + 1;
        break;
    }
    case 1:
    {
    pkt = PrimAllocQueueNode();
    *(void (**)(u8 *, u8 *))(pkt + 8) = FldRainRenderStateReset;
    *(u8 **)(pkt + 0x10) = ctx;
    PrimAppendNode(D_00794930, pkt);
    for (m = 0; m < 2; m++) {
        for (k = 0; k < 2; k++) {
            f32 v0;
            f32 v2;
            f32 v3;
            v0 = *(f32 *)(ctx + 0x42C) * (f32)k + *(f32 *)(ctx + 0x450);
            v1 = *(f32 *)(ctx + 0x430) * (f32)m + *(f32 *)(ctx + 0x454);
            v2 = *(f32 *)(ctx + 0x42C) * (f32)(k + 1) + *(f32 *)(ctx + 0x450);
            v3 = *(f32 *)(ctx + 0x430) * (f32)(m + 1) + *(f32 *)(ctx + 0x454);
            *(f32 *)(((ctx + (m << 9)) + (k << 8)) + 0x20) = v0;
            *(f32 *)(((ctx + (m << 9)) + (k << 8)) + 0x24) = v1;
            *(f32 *)(((ctx + (m << 9)) + (k << 8)) + 0x60) = v2;
            *(f32 *)(((ctx + (m << 9)) + (k << 8)) + 0x64) = v1;
            *(f32 *)(((ctx + (m << 9)) + (k << 8)) + 0xA0) = v0;
            *(f32 *)(((ctx + (m << 9)) + (k << 8)) + 0xA4) = v3;
            *(f32 *)(((ctx + (m << 9)) + (k << 8)) + 0xE0) = v2;
            *(f32 *)(((ctx + (m << 9)) + (k << 8)) + 0xE4) = v3;
            PrimQueueDrawPrimitive(D_00794930, 4, ((ctx + (m << 9)) + (k << 8)) + 0x10, 4);
        }
    }
    *(f32 *)(ctx + 0x450) = *(f32 *)(ctx + 0x450) + *(f32 *)(ctx + 0x414);
    *(f32 *)(ctx + 0x454) = *(f32 *)(ctx + 0x454) + *(f32 *)(ctx + 0x418);
    *(f32 *)(ctx + 0x458) = *(f32 *)(ctx + 0x458) + *(f32 *)(ctx + 0x414);
    *(f32 *)(ctx + 0x45C) = *(f32 *)(ctx + 0x45C) + *(f32 *)(ctx + 0x418);
    {
        f32 tmp0;

        tmp0 = -*(f32 *)(ctx + 0x424) / 2.0f;
        if (!(fabsf(*(f32 *)(ctx + 0x450) - tmp0) < 1.0f)) {
            *(f32 *)(ctx + 0x450) = tmp0;
            *(f32 *)(ctx + 0x458) = *(f32 *)(ctx + 0x424) / 2.0f;
        }
        tmp0 = -*(f32 *)(ctx + 0x428) / 2.0f;
        if (!(fabsf(*(f32 *)(ctx + 0x454) - tmp0) < 1.0f)) {
            *(f32 *)(ctx + 0x454) = tmp0;
            *(f32 *)(ctx + 0x45C) = *(f32 *)(ctx + 0x428) / 2.0f;
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
void FldFogDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
// FUN_00185150
s32 FldFogTaskCreate(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                  f32 fparg2, s16 arg2, s16 arg3, s16 arg4, s16 arg5,
                  s32 arg6, u8 *arg7)
{
    s32 temp_2;
    u8 *temp_2_2;
    register u8 *dst;
    register u8 byte0;
    register u8 byte1;
    register u8 byte2;
    register u8 byte3;
    register u8 byte4;
    register u8 byte5;
    register u8 byte6;
    register u8 byte7;

    if (arg7[3] == 0 && arg7[7] == 0) {
        return 0;
    }
    chkmemAllocSiteTag(&D_005F1D80, 0x43A);
    temp_2_2 = D_008873F4[0](1, 0x460, 0x40000);
    temp_2 = (s32)kwlnTaskCreateChild((void *)((u8 *)arg0), (const void *)(&D_005F1D90), 0xF, 0, 0, FldFogUpdate, FldFogDestroy, (u8 *)(temp_2_2));
    *(s32 *)(temp_2_2 + 0x420) = arg1;
    *(f32 *)(temp_2_2 + 0x414) = fparg1;
    *(f32 *)(temp_2_2 + 0x418) = fparg2;
    *(f32 *)(temp_2_2 + 0x424) = fparg0;
    *(f32 *)(temp_2_2 + 0x428) = fparg0;
    *(s16 *)(temp_2_2 + 0x434) = arg2;
    *(s16 *)(temp_2_2 + 0x436) = arg3;
    *(s16 *)(temp_2_2 + 0x438) = arg4;
    *(s16 *)(temp_2_2 + 0x43A) = arg5;
    *(s32 *)(temp_2_2 + 0x43C) = arg6;
    dst = temp_2_2 + 0x440;
    byte0 = arg7[0];
    byte1 = arg7[1];
    byte2 = arg7[2];
    byte3 = arg7[3];
    dst[0] = byte0;
    dst[1] = byte1;
    dst[2] = byte2;
    dst[3] = byte3;
    byte4 = arg7[4];
    byte5 = arg7[5];
    byte6 = arg7[6];
    byte7 = arg7[7];
    dst[4] = byte4;
    dst[5] = byte5;
    dst[6] = byte6;
    dst[7] = byte7;
    return temp_2;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
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
