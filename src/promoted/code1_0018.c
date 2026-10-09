#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"

typedef struct RwV3d {
    f32 x, y, z;
} RainVector;
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
extern void func_0048a000();
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_001852f0(void);
extern void func_003a2760(s32 arg0);
extern void func_003e9390(s32 arg0);
struct RpGeometry;
typedef struct RpMaterial *(*MaterialCallback)(struct RpMaterial *, void *);
extern struct RpGeometry *func_003c21e0(struct RpGeometry *geometry, MaterialCallback callback, void *data);
extern void func_004787e0(s32 arg0);
extern void func_003f3eb0(s32 arg0, s32 arg1);
extern void func_00185370();
extern s32 func_00183b80(u8 *task);

extern void (*jtbl_008873EC[])(void *);

extern u8 D_00756510[];
extern s32 D_0076428C;
extern s32 iGpffffb27c;
extern u64 iGpffffb8c8;
extern s32 iGpffffb278;
extern s32 func_0029d2e0(void);
extern s32 iGpffffb268;
extern s32 iGpffffb250;
extern s16 iGpffffb390;
extern s16 iGpffffb394;
extern s16 iGpffffb398;
extern s16 iGpffffb39c;
extern s16 iGpffffb3a0;
extern s32 iGpffffb3a4;
extern s32 func_00452080(KwlnTask *handle);
extern const KWindowEntryDescriptor D_005F5830[];
extern const KWindowEntryDescriptor D_005F5730[];
extern u8 D_007E3720[];
extern u8 D_007966D0[];
extern s64 iGpffff9fd0;
extern s32 iGpffffb240;
extern void func_001582f0(s32 mode, s32 value, s32 arg2);
extern void func_0017d1f0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3,
                           f32 arg5, f32 arg6, f32 arg7, s32 arg4);
extern void func_0014def0(u8 *arg0, u8 *arg1,
                          f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                          f32 fparg4, u8 *arg2, s32 arg3,
                          f32 fparg5, f32 fparg6, f32 fparg7, s32 arg4,
                          f32 arg_sp0);
extern void func_0017d240(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                          s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);
extern u16 D_008C024E[];
extern s32 func_0029db50(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00452490(s32 arg0);

void func_0018e780(s32 arg0);



extern void func_003e0f40(s32 arg0);
extern s32 K_Clump_MatUsrDataHasData(u8 *arg0, u8 *arg1);
extern struct RpMaterial *func_003c42b0(struct RpMaterial *material, RwTexture *texture);
extern u8 D_005F5438[];
extern s32 *func_00155280(void);
extern void func_0014e8f0(s32 a, s32 b, s32 c);
extern RwTexDictionary *func_003ef6d0(void);
extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
extern void func_003f6800(s32 a, f32 fp);
extern u8 D_005F5360[];
extern u8 iGpffffb310;
extern void memset(void *dst, s32 value, s32 size);
extern void func_0044ea90(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F5340[];
extern u8 D_005F5350[];
extern u8 D_005F5320[];
extern u8 D_005F5330[];
extern s32 func_00457120(void);
extern f32 fGpffff8218;
extern s16 func_00479c30(s32 arg0, s32 arg1);
extern u8 *mdlGetMatrix(u32 arg0);
extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
extern u8 *func_00457630(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern s32 func_0018a200(u8 *task);
extern s32 func_0015a560(void);
extern f32 sinf(f32 arg0);

extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
extern s32 func_00275680(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id,
                         const char *str, s32 flags, s32 unused, void *param,
                         s32 charWidth);
extern f32 D_008872F8[];
extern f32 D_00761184;
extern u8 D_00794C60[];
extern u32 D_007EFA00[];
extern u8 D_005F54D8[];
extern s32 func_00189940(u8 *arg0);
extern void func_0018a010(s32 arg0);
extern u8 D_005F54E8[];
extern s32 func_0018dde0(u8 *arg0);
extern u8 D_005F1D80[];
extern u8 D_005F1D90[];
extern s32 iGpffff9f60;
extern s32 func_00182bc0(u8 *task);

extern s32 func_00185850(u8 *task);
extern void func_00186610(u8 *arg0);
extern s32 func_0018e810(u8 *arg0);
extern void func_0018ef20(u8 *arg0);
extern u8 D_005F1DF8[];
extern u8 D_005F1E08[];
extern u8 D_005F57B0[];
extern u8 D_005F57C0[];
extern s32 func_003bfae0();
extern s32 func_00457120(void);
extern s32 RwCameraFrustumTestSphere(u8 *arg0, s32 arg1);
extern void func_003f68a0(s32 arg0, s32 arg1);
extern u8 D_007E8C00[];
extern s64 func_001060b0(void);
extern s32 func_001060c0(void);
extern s64 func_00110960(s32 arg0, u32 arg1);
extern s32 datGetFlag(s32 arg0);
extern s32 clndIsDateInRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_0015a160(void);
extern void func_004598e0(s32 arg0);
extern void func_0045a3e0(s16 arg0, s32 arg1);
extern s32 iGpffffb264;
extern u8 *iGpffff9db0;
extern s32 iGpffffb884;

/* measured: loop-invariant hoisting keeps the retail stride/base preheader for
   the 0x750 slot scan. */
#pragma opt_loop_invariants on
// FUN_00182310
void func_00182310(s32 arg0)
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
/* measured: close loop-invariant hoisting around the slot scan. */
#pragma opt_loop_invariants off
// FUN_00182390
void func_00182390(void)
{
    memset(&iGpffffb310, 0, 4);
}
// FUN_001823C0
u8 *func_001823c0(void)
{
    return &iGpffffb310;
}
typedef struct {
    f32 x, y, z;
} FldAreaNormal;
/* Plays the ambient cue for slot `id` and advances that slot's four-step
   variation counter.  Inlined into every trigger arm of func_001823d0. */
static inline void func_001823d0_play(u16 id, s16 bank, s32 base)
{
    extern s32 func_0045af60(s16 index, s16 stream, s16 arg2, s16 arg3);
    extern s32 D_007F1760[];
    s32 *slot = &D_007F1760[id & 0x3FF];

    func_0045af60(0, (id & 0x3FF) + 4, bank, base + *slot);
    if (++*slot >= 4) {
        *slot = 0;
    }
}
// FUN_001823D0
void func_001823d0(s32 arg0, u16 mode, u16 id)
{
    extern u8 *func_001452b0(s32 arg0);
    extern s32 K_FldFrame_IsPointInTriangle(f32 *point, f32 **vertices, f32 *normal);
    extern s32 func_0016fe80(s32 arg0);
    extern s32 func_0016ffd0(s32 arg0);
    extern u32 K_FldEvent_ArePosWithinDist(const struct RwV3d *posA, const struct RwV3d *posB, f32 maxDist);
    extern f32 func_0047a080(s32 arg0, s32 arg1);
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
    stat = func_00479c30(arg0, 0);
    time = func_0047a080(arg0, 0);
    if (((s32 *)iGpffff9db0)[0] >= 200) {
        return;
    }
    pos = (f32 *)(mdlGetMatrix(arg0) + 0x30);
    node = func_001452b0(0x15);
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
            if (stat == func_0016fe80(mode)) {
                if ((time > 7.0f && time < 8.0f) || (time > 21.0f && time < 22.0f)) {
                    func_001823d0_play(id, 1, area * 4);
                }
            } else if (stat == func_0016ffd0(mode)) {
                if ((time > 9.0f && time < 10.0f) || (time > 19.0f && time < 20.0f)) {
                    func_001823d0_play(id, 1, area * 4);
                }
            }
        } else if (status == 1) {
            if (stat == func_0016ffd0(mode)) {
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
            stat == func_0016ffd0(mode)) {
            if ((time > 8.0f && time < 9.0f) || (time > 18.0f && time < 19.0f)) {
                func_001823d0_play(id, 2, 0x18);
            }
        }
        break;
    default:
        if (status == 1 &&
            K_FldEvent_ArePosWithinDist((struct RwV3d *)(mdlGetMatrix(arg0) + 0x30),
                                        (struct RwV3d *)(mdlGetMatrix(D_007EFA00[0]) + 0x30), 1600.0f) != 0 &&
            stat == func_0016ffd0(mode)) {
            if ((time > 8.0f && time < 9.0f) || (time > 18.0f && time < 19.0f)) {
                func_001823d0_play(id, 2, area * 4);
            }
        }
        break;
    }
}
/* measured probe: opt_propagation off tests caching the repeated render callback base. */
#pragma opt_propagation off
// FUN_00182B40
void func_00182b40(void)
{
    void (**fn)(s32, s32);

    fn = D_00887300;
    fn[0](7, 2);
    fn[0](6, 1);
    fn[0](8, 0);
    fn[0](0xC, 1);
}
/* measured probe: restore opt_propagation after func_00182b40. */
#pragma opt_propagation on
/* Rain stores real PTank locks, vectors and matrices. Pool indexing and the
 * shared trail/reset counter preserve the observed callback lifetimes.
 * Verified with all owner functions, relocations and owned data. */
// FUN_00182BC0
#pragma push
#pragma opt_loop_invariants on
s32 func_00182bc0(u8 *task)
{
    extern s32 func_00457120(void);
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
    extern void func_0044ea90(const void *msg, s32 id);
    extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
    extern RainMatrix *RwMatrixScale(RainMatrix *matrix, const RainVector *scale, enum RwOpCombineType combine);
    extern s32 func_003a2770(struct RpAtomic *atomic, RainLock *lock, u32 dataFlags, enum RpPTankLockFlags lockFlags);
    extern struct RpAtomic *func_003a2920(struct RpAtomic *atomic);
    extern u8 *func_00460d80(u8 *list, s32 payload);
    extern void func_00182b40(void);
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
        tmp = ((u8 *)(uintptr_t)func_00457120());
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
        func_0044ea90(D_005F1D80, 0x9D);
        allocator = (uintptr_t)D_008873F4;
        *(u8 **)(work + 0x5C) = (*(RainAllocate *)allocator)(*(s32 *)(work + 0x40), 0x10, 0x40000);
        for (columnIndex = 0; columnIndex < *(s32 *)(work + 0x40); columnIndex++) {
            u8 *slotp;
            void *motion;
            func_0044ea90(D_005F1D80, 0xA2);
            motion = (*(RainAllocate *)allocator)(*(s32 *)(work + 0x2C), 8, 0x40000);
            slotp = *(u8 **)(work + 0x5C) + columnIndex * 0x10;
            *(void **)(slotp + 0x0C) = motion;
        }
        func_0044ea90(D_005F1D80, 0xA6);
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
        camera = ((u8 *)(uintptr_t)func_00457120());
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
            *(void (**)(void))(res + 8) = func_00182b40;
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
/* measured: propagation off preserves the cached jtbl_008873EC base for
   the post-loop callback sequence. */
// FUN_001837F0
#pragma opt_propagation off
void func_001837f0(u8 *arg0)
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
/* measured: closing the single-function callback-base bracket. */
#pragma opt_propagation on
// FUN_001838D0
void func_001838d0(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, s32 arg2, s32 arg3, s32 arg4)
{
    u8 *temp_2;

    func_0044ea90(&D_005F1D80, 0x17B);
    temp_2 = D_008873F4[0](1, 0x78, 0x40000);
    (s32)func_00451fc0((void *)(arg0), (const void *)(&iGpffff9f60), 0xF, 0, 0, func_00182bc0, func_001837f0, (u8 *)(temp_2));
    *(s32 *)(temp_2 + 0x28) = arg1;
    *(f32 *)(temp_2 + 0x18) = fparg0;
    *(f32 *)(temp_2 + 0x14) = fparg1;
    *(f32 *)(temp_2 + 0x1C) = fparg2;
    *(f32 *)(temp_2 + 0x20) = fparg3;
    *(s32 *)(temp_2 + 0x24) = arg2;
    *(s32 *)(temp_2 + 0x2C) = arg3;
    *(s32 *)(temp_2 + 0x30) = arg4;
}
// FUN_001839E0
void func_001839e0(u8 *arg0, u8 *arg1)
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
 
/* 2026-10-08: opt_lifetimes on lowers fnalign from 1427 to 879 edits. */
/* 2026-10-09: 879 -> 826 edits: the state dispatch is a switch (retail tests 1 then 0 and shares one return), the edge clamps use fabsf, and the grid offsets multiply i * half with the converted product first.
   2026-10-09: 826 -> 787: the row/cell base pointers and (f32)(j + 1) are
   written inline at their uses (pure expressions; no operand changes in
   between). */
// FUN_00183B80 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
s32 func_00183b80(u8 *arg0)
{
    extern f32 fabsf(f32 x);
    /* Retail returns zero at 001850F0, 00183BD4. */
    extern s32 func_00457120(void);
    extern u32 RpRandom(void);
    extern RwTexDictionary *func_003ef6d0(void);
    extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
    extern u8 *func_00460990(void);
    extern void func_00460ac0(u8 *, u8 *);
    extern u8 *func_00461390(void *arg0, s32 arg1, void *arg2, s32 arg3);
    extern void func_001839e0(u8 *arg0, u8 *arg1);
    extern u8 D_005F1D10[];
    extern u8 D_00794930[];
    u8 *ctx;
    u8 *base;
    u8 *q;
    u8 *tmp;
    u8 *pkt;
    f32 f21;
    f32 f20;
    f32 fj;
    f32 fj1;
    f32 fhi;
    f32 flo;
    f32 fdiff;
    f32 fhalf;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 half;
    s32 prod;
    s32 iv0;
    s32 iv1;
    s32 iv2;
    s32 iv3;

    ctx = *(u8 **)(arg0 + 0x38);
    tmp = ((u8 *)(uintptr_t)func_00457120());
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
        for (j = 0; j < 2; j++) {
            base = ctx + (j << 9);
            fj = (f32)j;
            for (i = 0; i < 2; i++) {
                q = base + (i << 8);
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = i * half;
                *(f32 *)(q + 0x10) = (f32)prod + (f32)*(s16 *)(ctx + 0x434);
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = j * half;
                *(f32 *)(q + 0x14) = (f32)prod + (f32)*(s16 *)(ctx + 0x436);
                *(f32 *)(q + 0x18) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = i * half;
                *(f32 *)(q + 0x50) = (f32)*(s16 *)(ctx + 0x438) / 2.0f + ((f32)prod + (f32)*(s16 *)(ctx + 0x434));
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = j * half;
                *(f32 *)(q + 0x54) = (f32)prod + (f32)*(s16 *)(ctx + 0x436);
                *(f32 *)(q + 0x58) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = i * half;
                *(f32 *)(q + 0x90) = (f32)prod + (f32)*(s16 *)(ctx + 0x434);
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = j * half;
                *(f32 *)(q + 0x94) = (f32)*(s16 *)(ctx + 0x43A) / 2.0f + ((f32)prod + (f32)*(s16 *)(ctx + 0x436));
                *(f32 *)(q + 0x98) = f21;
                half = *(s16 *)(ctx + 0x438) / 2;
                prod = i * half;
                *(f32 *)(q + 0xD0) = (f32)*(s16 *)(ctx + 0x438) / 2.0f + ((f32)prod + (f32)*(s16 *)(ctx + 0x434));
                half = *(s16 *)(ctx + 0x43A) / 2;
                prod = j * half;
                *(f32 *)(q + 0xD4) = (f32)*(s16 *)(ctx + 0x43A) / 2.0f + ((f32)prod + (f32)*(s16 *)(ctx + 0x436));
                *(f32 *)(q + 0xD8) = f21;
                *(f32 *)(q + 0x28) = f20;
                *(f32 *)(q + 0x68) = f20;
                *(f32 *)(q + 0xA8) = f20;
                *(f32 *)(q + 0xE8) = f20;
                fhi = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo = (f32)(u32)*(u8 *)(ctx + 0x440);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv0 = (s32)((f32)(u32)*(u8 *)(ctx + 0x440) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo = (f32)(u32)*(u8 *)(ctx + 0x441);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv1 = (s32)((f32)(u32)*(u8 *)(ctx + 0x441) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo = (f32)(u32)*(u8 *)(ctx + 0x442);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv2 = (s32)((f32)(u32)*(u8 *)(ctx + 0x442) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo = (f32)(u32)*(u8 *)(ctx + 0x443);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv3 = (s32)((f32)(u32)*(u8 *)(ctx + 0x443) + fj * fhalf);
                *(f32 *)(q + 0x30) = (f32)iv0;
                *(f32 *)(q + 0x34) = (f32)iv1;
                *(f32 *)(q + 0x38) = (f32)iv2;
                *(f32 *)(q + 0x3C) = (f32)iv3;
                fhi = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo = (f32)(u32)*(u8 *)(ctx + 0x440);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv0 = (s32)((f32)(u32)*(u8 *)(ctx + 0x440) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo = (f32)(u32)*(u8 *)(ctx + 0x441);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv1 = (s32)((f32)(u32)*(u8 *)(ctx + 0x441) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo = (f32)(u32)*(u8 *)(ctx + 0x442);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv2 = (s32)((f32)(u32)*(u8 *)(ctx + 0x442) + fj * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo = (f32)(u32)*(u8 *)(ctx + 0x443);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv3 = (s32)((f32)(u32)*(u8 *)(ctx + 0x443) + fj * fhalf);
                *(f32 *)(q + 0x70) = (f32)iv0;
                *(f32 *)(q + 0x74) = (f32)iv1;
                *(f32 *)(q + 0x78) = (f32)iv2;
                *(f32 *)(q + 0x7C) = (f32)iv3;
                fhi = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo = (f32)(u32)*(u8 *)(ctx + 0x440);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv0 = (s32)((f32)(u32)*(u8 *)(ctx + 0x440) + ((f32)(j + 1)) * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo = (f32)(u32)*(u8 *)(ctx + 0x441);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv1 = (s32)((f32)(u32)*(u8 *)(ctx + 0x441) + ((f32)(j + 1)) * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo = (f32)(u32)*(u8 *)(ctx + 0x442);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv2 = (s32)((f32)(u32)*(u8 *)(ctx + 0x442) + ((f32)(j + 1)) * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo = (f32)(u32)*(u8 *)(ctx + 0x443);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv3 = (s32)((f32)(u32)*(u8 *)(ctx + 0x443) + ((f32)(j + 1)) * fhalf);
                *(f32 *)(q + 0xB0) = (f32)iv0;
                *(f32 *)(q + 0xB4) = (f32)iv1;
                *(f32 *)(q + 0xB8) = (f32)iv2;
                *(f32 *)(q + 0xBC) = (f32)iv3;
                fhi = (f32)(u32)*(u8 *)(ctx + 0x444);
                flo = (f32)(u32)*(u8 *)(ctx + 0x440);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv0 = (s32)((f32)(u32)*(u8 *)(ctx + 0x440) + ((f32)(j + 1)) * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x445);
                flo = (f32)(u32)*(u8 *)(ctx + 0x441);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv1 = (s32)((f32)(u32)*(u8 *)(ctx + 0x441) + ((f32)(j + 1)) * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x446);
                flo = (f32)(u32)*(u8 *)(ctx + 0x442);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv2 = (s32)((f32)(u32)*(u8 *)(ctx + 0x442) + ((f32)(j + 1)) * fhalf);
                fhi = (f32)(u32)*(u8 *)(ctx + 0x447);
                flo = (f32)(u32)*(u8 *)(ctx + 0x443);
                fdiff = fhi - flo;
                fhalf = fdiff / 2.0f;
                iv3 = (s32)((f32)(u32)*(u8 *)(ctx + 0x443) + ((f32)(j + 1)) * fhalf);
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
    pkt = func_00460990();
    *(void (**)(u8 *, u8 *))(pkt + 8) = func_001839e0;
    *(u8 **)(pkt + 0x10) = ctx;
    func_00460ac0(D_00794930, pkt);
    for (m = 0; m < 2; m++) {
        for (k = 0; k < 2; k++) {
            f32 v0;
            f32 v1;
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
            func_00461390(D_00794930, 4, ((ctx + (m << 9)) + (k << 8)) + 0x10, 4);
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

#pragma opt_loop_invariants off
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_00183b80);
#endif
// FUN_00185120
void func_00185120(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



/* measured probe: O1 test for target byte-copy register allocation. */
#pragma optimization_level 1
// FUN_00185150
s32 func_00185150(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1,
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
    func_0044ea90(&D_005F1D80, 0x43A);
    temp_2_2 = D_008873F4[0](1, 0x460, 0x40000);
    temp_2 = (s32)func_00451fc0((void *)((u8 *)arg0), (const void *)(&D_005F1D90), 0xF, 0, 0, func_00183b80, func_00185120, (u8 *)(temp_2_2));
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
/* measured probe: restore optimization level after target O1 test. */
#pragma optimization_level 2
/* measured: VU0 MMI builtins and O1 reproduce the target's pcpyld/sq packet. */
#pragma enable_vu0_registers on
/* measured: bind MMI packet registers as in retail. */
#pragma vu0_mmi_reg_binding on
/* measured: O1 preserves the target's packet construction order. */
#pragma optimization_level 1
// FUN_001852F0
void func_001852f0(void)
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
/* measured: restore the file's O2 baseline after the target. */
#pragma optimization_level 2
/* measured: stop binding MMI packet registers after the target. */
#pragma vu0_mmi_reg_binding off
/* measured: stop VU0 register mode after the target. */
#pragma enable_vu0_registers off

/* measured: enable_vu0_registers + vu0_mmi_reg_binding with optimization_level 1
   reproduces the sibling 112-byte pcpyld/sq skeleton; direct _pcpyld on separate
   u64 pairs gives the retail register order and reload. */
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
/* measured: optimization_level 1 is required with the VU0 pragmas above;
   at -O2 the packet stores are reordered and the pcpyld pairs are folded. */
#pragma optimization_level 1
// FUN_00185370
void func_00185370(void)
{
    u_long128 *packet;
    u_long128 packed;
    u64 a, b, c, d;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = (u_long128 *)(u32)iGpffffb884;
    *packet = packed;
    c = 0x4C;
    d = iGpffffb8c8;
    packed = _pcpyld(c, d);
    packet[1] = packed;
    iGpffffb884 += 0x20;
}
/* measured: closes the cluster pcpyld pragma scope and restores the file's -O2
   baseline. */
#pragma optimization_level 2
#pragma vu0_mmi_reg_binding off
#pragma enable_vu0_registers off

/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_001853E0
#pragma opt_propagation off
void func_001853e0(u8 *arg0, u8 *arg1)
{
    s32 *value;
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 1);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x54);
    value = *(s32 **)(arg1 + 0x88C0);
    base[0](1, *value);
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_001854F0
#pragma opt_propagation off
void func_001854f0(u8 *arg0, u8 *arg1)
{
    s32 *value;
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 1);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 1);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x54);
    value = *(s32 **)(arg1 + 0x88C4);
    base[0](1, *value);
    func_001852f0();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00185600
void func_00185600(void)
{
    func_00185370();
}

/* measured: the saved callback argument and D_00887300 base reproduce the
   retail s17/s16 frame layout under opt_propagation off. */
// FUN_00185620
#pragma opt_propagation off
void func_00185620(u8 *arg0, u8 *arg1)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 3);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x54);
    base[0](1, *(s32 *)(arg1 + 0x88C8));
    func_001852f0();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
/* measured: retail hoists the D_00887300 base across nine indirect calls;
   opt_propagation off preserves the saved-register address materialization. */
// FUN_00185730
#pragma opt_propagation off
void func_00185730(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 3);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
    func_00489f80();
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00185830
void func_00185830(void)
{
    func_0048a000();
}

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

/* Build the grid, horizontal strips and three concentric ring pairs, then
 * queue their draw and state callbacks. The constant reciprocal depth is
 * 1/1000, matching each vertex's depth and the retail literal at 0x761304.
 * Separate loop lifetimes and complete work/vertex records recover the
 * retail 0x90 frame without artificial storage. */
// FUN_00185850
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
s32 func_00185850(u8 *task)
{
    extern u8 D_00794930[];
    extern u8 D_005F1DA0[];
    extern u8 D_005F1DC0[];
    extern u8 D_005F1DE0[];
    extern f32 iGpffff8424;
    extern f32 fGpffff84d4;
    extern f32 fGpffff84d8;
    extern f32 fGpffff84dc;
    extern s32 uGpffffb314;
    extern u32 RpRandom(void);
    extern RwTexDictionary *func_003ef6d0(void);
    extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
    extern s32 func_00401b80(void);
    extern f32 cosf(f32 angle);
    extern f32 sinf(f32 angle);
    extern u8 *func_00460990(void);
    extern void func_00460ac0(u8 *, u8 *);
    extern u8 *func_00461390(void *task, s32 arg1, void *arg2, s32 arg3);
    extern void func_001853e0(u8 *task, u8 *arg1);
    extern void func_001854f0(u8 *task, u8 *arg1);
    extern void func_00185600(void);
    extern void func_00185620(u8 *task, u8 *arg1);
    extern void func_00185730(void);
    extern void func_00185830(void);
    u8 *node;

    GridDrawWork *work;
    s32 index;
    u32 randomValue;
    u8 *callbackNode;
    s32 *phaseSlot;
    s32 vertex;
    s32 corner;
    s32 column;
    f32 value;
    f32 value2;

    work = *(GridDrawWork **)(task + 0x38);
    if (work->blocked != 0) {
        return 0;
    }
    switch (work->state) {
    case 0:
        work->textures[0] = func_003ef650(func_003ef6d0(), (const char *)D_005F1DC0);
        work->textures[1] = func_003ef650(func_003ef6d0(), (const char *)D_005F1DE0);
        node = (u8 *)func_00401b80();
        work->raster = node;
        for (index = 0; index < 7; index = index + 1) {
            column = 0;
            while (column < 10) {
                work->grid[index][column][0].x = (float)(column << 6);
                work->grid[index][column][0].y = (float)(index << 6);
                work->grid[index][column][0].z = 1000.0f;
                value2 = (float)((column + 1) * 0x40);
                work->grid[index][column][1].x = value2;
                work->grid[index][column][1].y = (float)(index << 6);
                work->grid[index][column][1].z = 1000.0f;
                work->grid[index][column][2].x = (float)(column << 6);
                work->grid[index][column][2].y = (f32)((index + 1) * 0x40);
                work->grid[index][column][2].z = 1000.0f;
                work->grid[index][column][3].x = value2;
                work->grid[index][column][3].y = (f32)((index + 1) * 0x40);
                work->grid[index][column][3].z = 1000.0f;
                work->grid[index][column][0].reciprocalZ = 0.001f;
                work->grid[index][column][1].reciprocalZ = 0.001f;
                work->grid[index][column][2].reciprocalZ = 0.001f;
                work->grid[index][column][3].reciprocalZ = 0.001f;
                work->grid[index][column][0].red = 255.0f;
                work->grid[index][column][0].green = 255.0f;
                work->grid[index][column][0].blue = 255.0f;
                work->grid[index][column][0].alpha = 64.0f;
                work->grid[index][column][1].red = 255.0f;
                work->grid[index][column][1].green = 255.0f;
                work->grid[index][column][1].blue = 255.0f;
                work->grid[index][column][1].alpha = 64.0f;
                work->grid[index][column][2].red = 255.0f;
                work->grid[index][column][2].green = 255.0f;
                work->grid[index][column][2].blue = 255.0f;
                work->grid[index][column][2].alpha = 64.0f;
                work->grid[index][column][3].red = 255.0f;
                work->grid[index][column][3].green = 255.0f;
                work->grid[index][column][3].blue = 255.0f;
                work->grid[index][column][3].alpha = 64.0f;
                randomValue = RpRandom();
                work->phases[index][column] = randomValue & 3;
                column++;
            }
        }
        for (index = 0; index < 0xe; index = index + 1) {
            column = 0;
            while (column < 1) {
                work->bands[index][column][0].x = (float)(column * 0x280);
                work->bands[index][column][0].y = (float)(index << 5);
                work->bands[index][column][0].z = 1000.0f;
                value = (float)((column + 1) * 0x280);
                work->bands[index][column][1].x = value;
                work->bands[index][column][1].y = (float)(index << 5);
                work->bands[index][column][1].z = 1000.0f;
                work->bands[index][column][2].x = (float)(column * 0x280);
                work->bands[index][column][2].y = (f32)((index + 1) * 0x20);
                work->bands[index][column][2].z = 1000.0f;
                work->bands[index][column][3].x = value;
                work->bands[index][column][3].y = (f32)((index + 1) * 0x20);
                work->bands[index][column][3].z = 1000.0f;
                work->bands[index][column][0].reciprocalZ = 0.001f;
                work->bands[index][column][1].reciprocalZ = 0.001f;
                work->bands[index][column][2].reciprocalZ = 0.001f;
                work->bands[index][column][3].reciprocalZ = 0.001f;
                work->bands[index][column][0].red = 255.0f;
                work->bands[index][column][0].green = 255.0f;
                work->bands[index][column][0].blue = 255.0f;
                work->bands[index][column][0].alpha = 32.0f;
                work->bands[index][column][1].red = 255.0f;
                work->bands[index][column][1].green = 255.0f;
                work->bands[index][column][1].blue = 255.0f;
                work->bands[index][column][1].alpha = 32.0f;
                work->bands[index][column][2].red = 255.0f;
                work->bands[index][column][2].green = 255.0f;
                work->bands[index][column][2].blue = 255.0f;
                work->bands[index][column][2].alpha = 32.0f;
                work->bands[index][column][3].red = 255.0f;
                work->bands[index][column][3].green = 255.0f;
                work->bands[index][column][3].blue = 255.0f;
                work->bands[index][column][3].alpha = 32.0f;
                work->bands[index][column][0].u = 0.0f;
                work->bands[index][column][0].v = 0.0f;
                work->bands[index][column][1].u = 1.0f;
                work->bands[index][column][1].v = 0.0f;
                work->bands[index][column][2].u = 0.0f;
                work->bands[index][column][2].v = 1.0f;
                work->bands[index][column][3].u = 1.0f;
                work->bands[index][column][3].v = 1.0f;
                column = column + 1;
            }
        }
        index = 0;
        value2 = 0.0f;
        for (; index < 0x42; index = index + 2) {
            work->rings[0][index + 0].x = (cosf(value2) * 850.0f * 0.5f + 320.0f);
            value = (float)sinf(value2);
            work->rings[0][index + 0].y = (value * 750.0f * 0.5f + 224.0f);
            work->rings[0][index + 0].z = 1000.0f;
            work->rings[0][index + 0].reciprocalZ = 0.001f;
            work->rings[0][index + 0].red = 0.0f;
            work->rings[0][index + 0].green = 255.0f;
            work->rings[0][index + 0].blue = 0.0f;
            work->rings[0][index + 0].alpha = 128.0f;
            value = 450.0f * cosf(value2);
            work->rings[0][index + 1].x = (value * 0.5f + 320.0f);
            value = 250.0f * sinf(value2);
            work->rings[0][index + 1].y = (value * 0.5f + 224.0f);
            work->rings[0][index + 1].z = 1000.0f;
            work->rings[0][index + 1].reciprocalZ = 0.001f;
            work->rings[0][index + 1].red = 0.0f;
            work->rings[0][index + 1].green = 255.0f;
            work->rings[0][index + 1].blue = 0.0f;
            work->rings[0][index + 1].alpha = 0.0f;
            value2 = value2 + fGpffff84d4;
        }
        value2 = 0.0f;
        work->cover[0].x = 0.0f;
        work->cover[0].y = 0.0f;
        work->cover[0].z = 1000.0f;
        work->cover[1].x = 640.0f;
        work->cover[1].y = 0.0f;
        work->cover[1].z = 1000.0f;
        work->cover[2].x = 0.0f;
        work->cover[2].y = 448.0f;
        work->cover[2].z = 1000.0f;
        work->cover[3].x = 640.0f;
        work->cover[3].y = 448.0f;
        work->cover[3].z = 1000.0f;
        work->cover[0].reciprocalZ = 0.001f;
        work->cover[1].reciprocalZ = 0.001f;
        work->cover[2].reciprocalZ = 0.001f;
        work->cover[3].reciprocalZ = 0.001f;
        work->cover[0].red = 255.0f;
        work->cover[0].green = 255.0f;
        work->cover[0].blue = 255.0f;
        work->cover[0].alpha = 0.0f;
        work->cover[1].red = 255.0f;
        work->cover[1].green = 255.0f;
        work->cover[1].blue = 255.0f;
        work->cover[1].alpha = 0.0f;
        work->cover[2].red = 255.0f;
        work->cover[2].green = 255.0f;
        work->cover[2].blue = 255.0f;
        work->cover[2].alpha = 0.0f;
        work->cover[3].red = 255.0f;
        work->cover[3].green = 255.0f;
        work->cover[3].blue = 255.0f;
        work->cover[3].alpha = 0.0f;
        for (index = 0; index < 0x42; index = index + 2) {
            work->rings[1][index + 0].x = (cosf(value2) * 850.0f * 0.5f + 320.0f);
            value = (float)sinf(value2);
            work->rings[1][index + 0].y = (value * 750.0f * 0.5f + 224.0f);
            work->rings[1][index + 0].z = 1000.0f;
            work->rings[1][index + 0].reciprocalZ = 0.001f;
            work->rings[1][index + 0].red = 0.0f;
            work->rings[1][index + 0].green = 255.0f;
            work->rings[1][index + 0].blue = 0.0f;
            work->rings[1][index + 0].alpha = 64.0f;
            value = 500.0f * cosf(value2);
            work->rings[1][index + 1].x = (value * 0.5f + 320.0f);
            value = 300.0f * sinf(value2);
            work->rings[1][index + 1].y = (value * 0.5f + 224.0f);
            work->rings[1][index + 1].z = 1000.0f;
            work->rings[1][index + 1].reciprocalZ = 0.001f;
            work->rings[1][index + 1].red = 0.0f;
            work->rings[1][index + 1].green = 255.0f;
            work->rings[1][index + 1].blue = 0.0f;
            work->rings[1][index + 1].alpha = 0.0f;
            value2 = value2 + fGpffff84d4;
        }
        index = 0;
        value2 = 0.0f;
        for (; index < 0x42; index = index + 2) {
            work->rings[2][index + 0].x = (cosf(value2) * 850.0f * 0.5f + 320.0f);
            value = (float)sinf(value2);
            work->rings[2][index + 0].y = (value * 750.0f * 0.5f + 224.0f);
            work->rings[2][index + 0].z = 1000.0f;
            work->rings[2][index + 0].reciprocalZ = 0.001f;
            work->rings[2][index + 0].red = 0.0f;
            work->rings[2][index + 0].green = 255.0f;
            work->rings[2][index + 0].blue = 0.0f;
            work->rings[2][index + 0].alpha = 240.0f;
            value = 450.0f * cosf(value2);
            work->rings[2][index + 1].x = (value * 0.5f + 320.0f);
            value = 250.0f * sinf(value2);
            work->rings[2][index + 1].y = (value * 0.5f + 224.0f);
            work->rings[2][index + 1].z = 1000.0f;
            work->rings[2][index + 1].reciprocalZ = 0.001f;
            work->rings[2][index + 1].red = 0.0f;
            work->rings[2][index + 1].green = 255.0f;
            work->rings[2][index + 1].blue = 0.0f;
            work->rings[2][index + 1].alpha = 0.0f;
            value2 = value2 + fGpffff84d4;
        }
        work->overlay[0].x = 0.0f;
        work->overlay[0].y = 0.0f;
        work->overlay[0].z = 1000.0f;
        work->overlay[1].x = 640.0f;
        work->overlay[1].y = 0.0f;
        work->overlay[1].z = 1000.0f;
        work->overlay[2].x = 0.0f;
        work->overlay[2].y = 448.0f;
        work->overlay[2].z = 1000.0f;
        work->overlay[3].x = 640.0f;
        work->overlay[3].y = 448.0f;
        work->overlay[3].z = 1000.0f;
        work->overlay[0].reciprocalZ = 0.001f;
        work->overlay[1].reciprocalZ = 0.001f;
        work->overlay[2].reciprocalZ = 0.001f;
        work->overlay[3].reciprocalZ = 0.001f;
        work->overlay[0].red = 255.0f;
        work->overlay[0].green = 255.0f;
        work->overlay[0].blue = 255.0f;
        work->overlay[0].alpha = 96.0f;
        work->overlay[1].red = 255.0f;
        work->overlay[1].green = 255.0f;
        work->overlay[1].blue = 255.0f;
        work->overlay[1].alpha = 96.0f;
        work->overlay[2].red = 255.0f;
        work->overlay[2].green = 255.0f;
        work->overlay[2].blue = 255.0f;
        work->overlay[2].alpha = 96.0f;
        work->overlay[3].red = 255.0f;
        work->overlay[3].green = 255.0f;
        work->overlay[3].blue = 255.0f;
        work->overlay[3].alpha = 96.0f;
        work->uvValues[2] = (0.5f / (float)*(int *)(work->raster + 0xc));
        work->uvValues[3] = (0.5f / (float)*(int *)(work->raster + 0x10));
        work->uvValues[4] = (fGpffff84d8 / (float)*(int *)(work->raster + 0xc));
        work->uvValues[5] = (fGpffff84dc / (float)*(int *)(work->raster + 0x10));
        work->uvValues[1] = iGpffff8424;
        work->overlay[0].u = (work->uvValues[2] + work->uvValues[1]);
        work->overlay[0].v = (work->uvValues[3] + work->uvValues[1]);
        work->overlay[1].u = (work->uvValues[4] - work->uvValues[1]);
        work->overlay[1].v = (work->uvValues[3] + work->uvValues[1]);
        work->overlay[2].u = (work->uvValues[2] + work->uvValues[1]);
        work->overlay[2].v = (work->uvValues[5] - work->uvValues[1]);
        work->overlay[3].u = (work->uvValues[4] - work->uvValues[1]);
        work->overlay[3].v = (work->uvValues[5] - work->uvValues[1]);
        work->state = work->state + 1;
        break;
    case 1:
        node = func_00461390(D_00794930,4,work->cover,4);
        *(void (**)(void))(node + 8) = func_00185730;
        *(GridDrawWork **)(node + 0x10) = work;
        node = func_00461390(D_00794930,4,work->rings[2],0x42);
        *(void (**)(void))(node + 8) = func_00185730;
        *(GridDrawWork **)(node + 0x10) = work;
        *(void (**)(void))(node + 0xc) = func_00185830;
        *(GridDrawWork **)(node + 0x14) = work;
        node = func_00461390(D_00794930,4,work->overlay,4);
        *(void (**)(u8 *, u8 *))(node + 8) = func_00185620;
        *(GridDrawWork **)(node + 0x10) = work;
        callbackNode = (u8 *)func_00460990();
        *(void (**)(void))(callbackNode + 8) = func_00185600;
        *(GridDrawWork **)(callbackNode + 0x10) = work;
        func_00460ac0(D_00794930,callbackNode);
        node = func_00461390(D_00794930,4,work->cover,4);
        *(void (**)(void))(node + 8) = func_00185730;
        *(GridDrawWork **)(node + 0x10) = work;
        node = func_00461390(D_00794930,4,work->rings[1],0x42);
        *(void (**)(void))(node + 8) = func_00185730;
        *(GridDrawWork **)(node + 0x10) = work;
        *(void (**)(void))(node + 0xc) = func_00185830;
        *(GridDrawWork **)(node + 0x14) = work;
        callbackNode = (u8 *)func_00460990();
        *(void (**)(u8 *, u8 *))(callbackNode + 8) = func_001854f0;
        *(GridDrawWork **)(callbackNode + 0x10) = work;
        func_00460ac0(D_00794930,callbackNode);
        for (index = 0; index < 0xe; index = index + 1) {
            for (column = 0; column < 1; column = column + 1) {
                func_00461390(D_00794930,4,work->bands[index][column],4);
            }
        }
        callbackNode = (u8 *)func_00460990();
        *(void (**)(void))(callbackNode + 8) = func_00185600;
        *(GridDrawWork **)(callbackNode + 0x10) = work;
        func_00460ac0(D_00794930,callbackNode);
        node = func_00461390(D_00794930,4,work->rings[0],0x42);
        *(void (**)(void))(node + 0xc) = func_00185830;
        *(GridDrawWork **)(node + 0x14) = work;
        uGpffffb314 = uGpffffb314 != 0 ^ 1;
        callbackNode = (u8 *)func_00460990();
        *(void (**)(u8 *, u8 *))(callbackNode + 8) = func_001853e0;
        *(GridDrawWork **)(callbackNode + 0x10) = work;
        func_00460ac0(D_00794930,callbackNode);
        for (index = 0; index < 7; index = index + 1) {
            for (column = 0; column < 10; column = column + 1) {
                phaseSlot = &work->phases[index][column];
                corner = work->phases[index][column];
                vertex = 0;
                while (vertex < 4) {
                    if (corner >= 4) {
                        corner = 0;
                    }
                    work->grid[index][column][vertex].u =
                        *(f32 *)(D_005F1DA0 + corner * 8);
                    work->grid[index][column][vertex].v =
                        *(f32 *)(D_005F1DA0 + corner * 8 + 4);
                    vertex++;
                    corner = corner + 1;
                }
                if (uGpffffb314 != 0) {
                    *phaseSlot = *phaseSlot + 1;
                }
                if (*phaseSlot >= 4) {
                    *phaseSlot = 0;
                }
                func_00461390(D_00794930,4,work->grid[index][column],4);
            }
        }
        break;
    }
    return 0;
}


#pragma pop

// FUN_00186610
void func_00186610(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00186640
s32 func_00186640(u8 *arg0)
{
    func_0044ea90(&D_005F1DF8, 0x299);
    return (s32)func_00451fc0((void *)(arg0), (const void *)(&D_005F1E08), 0xF, 0, 0, func_00185850, func_00186610, (u8 *)(D_008873F4[0](1, 0x88D0, 0x40000)));
}
// FUN_00189600
void func_00189600(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 v32[4];
    f32 v31[4];
    f32 temp_f0;
    f32 temp_f20;
    s32 temp_16;
    s32 temp_3;
    s32 temp_4;
    u8 *temp_18;
    u8 *temp_16_2;
    u8 *temp_17;

    temp_17 = *(u8 **)(arg0 + 0x38);
    func_00457120();
    temp_4 = *(s32 *)temp_17;
    if ((temp_4 != 1) || (*(s32 *)(temp_17 + 0x30) != arg2)) {
        if (fparg0 != 0.0f) {
            *(s32 *)(temp_17 + 0x2C) = arg1;
            *(s32 *)(temp_17 + 0x30) = arg2;
            temp_16 = arg2 * 0x18;
            v32[0] = *(f32 *)((u8 *)D_005F2190 + temp_16) -
                     *(f32 *)(temp_17 + 4);
            v32[1] = *(f32 *)((u8 *)D_005F2194 + temp_16) -
                     *(f32 *)(temp_17 + 8);
            v32[2] = *(f32 *)((u8 *)D_005F2198 + temp_16) -
                     *(f32 *)(temp_17 + 0xC);
            temp_f20 = RwV3dNormalize((RainVector *)&v32[0], (const RainVector *)&v32[0]);
            v31[0] = *(f32 *)((u8 *)D_005F219C + temp_16) -
                     *(f32 *)(temp_17 + 0x10);
            v31[1] = *(f32 *)((u8 *)D_005F21A0 + temp_16) -
                     *(f32 *)(temp_17 + 0x14);
            v31[2] = *(f32 *)((u8 *)D_005F21A4 + temp_16) -
                     *(f32 *)(temp_17 + 0x18);
            temp_f0 = RwV3dNormalize((RainVector *)&v31[0], (const RainVector *)&v31[0]);
            if (!(temp_f20 <= temp_f0)) {
                *(s32 *)(temp_17 + 0x28) = (s32)(temp_f20 / fparg0) + 1;
            } else {
                *(s32 *)(temp_17 + 0x28) = (s32)(temp_f0 / fparg0) + 1;
            }
            *(f32 *)(temp_17 + 0x1C) =
                temp_f20 / (f32)*(s32 *)(temp_17 + 0x28);
            *(f32 *)(temp_17 + 0x20) =
                temp_f0 / (f32)*(s32 *)(temp_17 + 0x28);
            *(s32 *)(temp_17 + 0x24) = 0;
            *(s32 *)temp_17 = 2;
            return;
        }
        *(s32 *)(temp_17 + 0x30) = arg2;
        temp_3 = arg2 * 0x18;
        temp_18 = (u8 *)D_005F2190 + temp_3;
        *(struct Vec3 *)(temp_17 + 4) = *(struct Vec3 *)temp_18;
        temp_16_2 = (u8 *)D_005F219C + temp_3;
        *(struct Vec3 *)(temp_17 + 0x10) = *(struct Vec3 *)temp_16_2;
        func_00457630(((u8 *)(uintptr_t)func_00457120()), temp_18, temp_16_2, 0);
    }
}
/* measured: retail hoists the D_00887300 base across seven indirect calls;
   opt_propagation off preserves the saved-register address materialization. */
// FUN_00189870
#pragma opt_propagation off
void func_00189870(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](6, 1);
    base[0](8, 1);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
}
/* measured: closing the single-function address-hoist bracket. */
#pragma opt_propagation on
// FUN_00189940
/* Measured: 1348 executable bytes, 26 resolved relocations, 12 zero tail bytes.
 * Preserve integer-to-float conversions and reloads across rendering callbacks.
 * Indexed addresses stay integer-valued until their final pointer conversion. */
#pragma opt_loop_invariants on
s32 func_00189940(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_2;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f1;
    f32 temp_f0;
    s32 i;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(temp_16 + 4) == 1) {
        return 0;
    }

    switch (*(s32 *)temp_16) {
    case 0:
        temp_f2 = D_008872F8[0] - (f32)58980;
        temp_f3 = 1.0f / temp_f2;
        *(s32 *)(temp_16 + 8) = 0;
        *(f32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x18)) = 175.0f;
        *(f32 *)(temp_16 + 0x20) = 0.0f;
        temp_f1 = (f32)401;
        *(f32 *)(temp_16 + 0x24) = temp_f1;
        *(f32 *)(temp_16 + 0x28) = temp_f2;
        *(f32 *)(temp_16 + 0x60) = 25.0f;
        *(f32 *)(temp_16 + 0x64) = temp_f1;
        *(f32 *)(temp_16 + 0x68) = temp_f2;
        *(f32 *)(temp_16 + 0xA0) = 0.0f;
        temp_f0 = (f32)427;
        *(f32 *)(temp_16 + 0xA4) = temp_f0;
        *(f32 *)(temp_16 + 0xA8) = temp_f2;
        *(f32 *)(temp_16 + 0xE0) = 25.0f;
        *(f32 *)(temp_16 + 0xE4) = temp_f0;
        *(f32 *)(temp_16 + 0xE8) = temp_f2;
        *(f32 *)(temp_16 + 0x120) = 326.0f;
        *(f32 *)(temp_16 + 0x124) = temp_f1;
        *(f32 *)(temp_16 + 0x128) = temp_f2;
        *(f32 *)(temp_16 + 0x160) = 660.0f;
        *(f32 *)(temp_16 + 0x164) = temp_f1;
        *(f32 *)(temp_16 + 0x168) = temp_f2;
        *(f32 *)(temp_16 + 0x1A0) = 326.0f;
        *(f32 *)(temp_16 + 0x1A4) = temp_f0;
        *(f32 *)(temp_16 + 0x1A8) = temp_f2;
        *(f32 *)(temp_16 + 0x1E0) = 660.0f;
        *(f32 *)(temp_16 + 0x1E4) = temp_f0;
        *(f32 *)(temp_16 + 0x1E8) = temp_f2;
        for (i = 0; i < 4; i++) {
            temp_2 = temp_16 + (i << 6);
            *(f32 *)(temp_2 + 0x38) = temp_f3;
            *(f32 *)(temp_2 + 0x138) = temp_f3;
            *(f32 *)(temp_2 + 0x40) = 255.0f;
            *(f32 *)(temp_2 + 0x44) = 0.0f;
            *(f32 *)(temp_2 + 0x48) = 0.0f;
            *(f32 *)(temp_2 + 0x4C) = 0.0f;
            *(f32 *)(temp_2 + 0x140) = 255.0f;
            *(f32 *)(temp_2 + 0x144) = 0.0f;
            *(f32 *)(temp_2 + 0x148) = 0.0f;
            *(f32 *)(temp_2 + 0x14C) = 0.0f;
        }
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        *(f32 *)(temp_16 + 0x22C) = sinf((D_00761184 * (f32)*(s32 *)(temp_16 + 0x220)) / 10.0f);
        if (*(s32 *)(temp_16 + 0x220) < 10) {
            *(s32 *)(temp_16 + 0x220) += 1;
        } else {
            *(s32 *)temp_16 += 1;
        }
        *(f32 *)(temp_16 + 0x224) = (-300.0f + 0.0f) + 316.0f * *(f32 *)(temp_16 + 0x22C);
        *(f32 *)(temp_16 + 0x228) = ((f32)371 + 0.0f) + 30.0f * *(f32 *)(temp_16 + 0x22C);
        /* fallthrough */
    case 2:
        func_00366380((s32)*(f32 *)(temp_16 + 0x224), (s32)*(f32 *)(temp_16 + 0x228), (f32)59000, 301, 26, 0xFAFF20, 255, 1, 150, 13, D_00794C60, -5.0f, 1.0f, 1.0f);
        func_00366380(25, 401, (f32)59000, 301, 26, 0x191919, 255, 1, 150, 13, D_00794C60, 0.0f, 1.0f, *(f32 *)(temp_16 + 0x22C));
        if (!(*(f32 *)(temp_16 + 0x22C) < 1.0f)) {
            if (*(s32 *)((((!(u32)*(s32 *)(temp_16 + 8)) << 2) + (u32)temp_16 + 0x10)) != 0) {
                temp_f0 = sinf((D_00761184 * (f32)*(s32 *)(temp_16 + 0xC)) / 10.0f);
                *(f32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x18)) = 175.0f + 336.0f * temp_f0;
                *(f32 *)((((!(u32)*(s32 *)(temp_16 + 8)) << 2) + (u32)temp_16 + 0x18)) = -161.0f + 336.0f * temp_f0;
                if (*(s32 *)(temp_16 + 0xC) < 10) {
                    *(s32 *)(temp_16 + 0xC) += 1;
                } else {
                    *(s32 *)(((*(s32 *)(temp_16 + 8) << 2) + (u32)temp_16 + 0x10)) = 0;
                    *(s32 *)(temp_16 + 8) = !(u32)*(s32 *)(temp_16 + 8);
                }
            }
            temp_2 = func_00461390(D_00794C60, 4, temp_16 + 0x20, 4);
            *(void (**)(void))(temp_2 + 8) = func_00189870;
            *(s32 *)(temp_2 + 0x10) = 0;
            func_00461390(D_00794C60, 4, temp_16 + 0x120, 4);
            if (*(const char **)(temp_16 + 0x10) != NULL) {
                func_00275680((f32)(s32)*(f32 *)(temp_16 + 0x18), (f32)399, (f32)58990, -1, 0, 1, *(const char **)(temp_16 + 0x10), 8, 0, D_00794C60, -1);
            }
            if (*(const char **)(temp_16 + 0x14) != NULL) {
                func_00275680((f32)(s32)*(f32 *)(temp_16 + 0x1C), (f32)399, (f32)58990, -1, 0, 1, *(const char **)(temp_16 + 0x14), 8, 0, D_00794C60, -1);
            }
        }
        break;
    case 3:
    default:
        break;
    }
    return 0;
}
#pragma opt_loop_invariants off
// FUN_00189E90
void func_00189e90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_00189EC0
void func_00189ec0(void)
{
    u8 *temp_16;
    u8 *temp_2;
    s32 var_16;
    if (*(s32 *)((u8 *)func_00155280() + 0x30) == 0) {
        temp_16 = *(u8 **)func_00155280();
        func_0044ea90(&D_005F5320, 0x17C);
        temp_2 = D_008873F4[0](1, 0x230, 0x40000);
        if (temp_2 == NULL) {
            var_16 = 0;
        } else {
            var_16 = (s32)func_00451fc0((void *)(temp_16), (const void *)(&D_005F5330), 0xF, 0, 0, func_00189940, func_00189e90, (u8 *)(temp_2));
        }
        *(s32 *)((u8 *)func_00155280() + 0x30) = var_16;
        func_0018a010(-1);
    }
}
// FUN_00189FA0
s32 func_00189fa0(void) {
    if (*(s32 *)((u8 *)(func_00155280()) + 0x30) == 0) {
        return 0;
    }
    func_00452080(*(KwlnTask **)((u8 *)(func_00155280()) + 0x30));
    *(s32 *)((u8 *)(func_00155280()) + 0x30) = 0;
    return 1;
}

// FUN_0018A000
void func_0018a000(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4) = arg1;
}

/* measured: the inner mode/index selection assigns a scratch `p` and `base = p`
   follows the if/else: that copy keeps the join block alive so the two inner
   exits branch to it (retail's b -> b trampoline) instead of folding to the
   work setup. `slot` is a named local recomputed per store so the addu keeps
   index-first operand order and retail's repeated load. */
// FUN_0018A010
void func_0018a010(s32 arg0)
{
    extern u8 D_005F2210[];
    extern u8 D_005F4090[];
    extern u8 D_005F51E0[];
    s32 mode;
    s32 *save;
    s32 *entry;
    s32 index;
    u8 *base;
    u8 *work;
    s32 slot;
    u8 *p;

    if (*(s32 *)((u8 *)func_00155280() + 0x30) == 0) {
        return;
    }
    if (arg0 == -1) {
        mode = func_0015a160();
        if (mode == 0) {
            index = 0;
            save = (s32 *)iGpffff9db0;
            if (*save >= 0x28) {
                p = NULL;
            } else {
                entry = (s32 *)(D_005F51E0 + *save * 4);
                if (*entry != 0) {
                    index = *(u16 *)((u8 *)*entry + *(save + 1) * 2);
                }
                p = D_005F2210 + index * 0x1A;
            }
        } else {
            p = D_005F4090 + mode * 0x1B;
        }
        base = p;
    } else {
        base = D_005F2210 + arg0 * 0x1A;
    }
    work = *(u8 **)(*(u8 **)((u8 *)func_00155280() + 0x30) + 0x38);
    slot = ((*(s32 *)(work + 8) != 0) ^ 1) * 4;
    *(u8 **)(slot + (s32)work + 0x10) = base;
    slot = ((*(s32 *)(work + 8) != 0) ^ 1) * 4;
    *(s32 *)(slot + (s32)work + 0x18) = (s32)0xC3210000;
    *(s32 *)(work + 0xC) = 0;
}
// FUN_0018A170
s32 func_0018a170(s32 arg0, s32 *arg1)
{
    u8 *temp_16;

    func_003bfae0();
    temp_16 = ((u8 *)(uintptr_t)func_00457120());
    if (RwCameraFrustumTestSphere(temp_16, func_003bfae0(arg0)) != 0) {
        *arg1 = 1;
        return 0;
    }
    return arg0;
}
/* measured 0018a200 (owner, romwright R1 + doubles-to-float + float-read fix): fndiff obj 6452B vs window 6352B (+100B); fnalign retail 1588 vs object 1613 (+25, +1.6%, band 1540-1636, inside); edits 1113; GUARDED_SCORE 1404. Frame retail -0x1C0 vs object -0xC0 (-256B). `#pragma opt_common_subs off` scoped to this function and closed after it (CSE off, +73 over v4a base 1540 vs 1587). Residual is 3 fptodp helpers, cvt/mtc1 vs direct loads, and saved-reg colour. Same file idioms as 00183b80 noted (u8* ctx at +0x38 for next step; current uint* preserves count).
   2026-10-08: opt_lifetimes on lowers fnalign from 1063 to 1007 edits. */
/* 2026-10-09: corrected two Ghidra artefacts against retail: the five puVar1[6]/[7] stores are float stores (retail swc1, no float-to-unsigned conversion), and func_0014bff0/func_0014c4c0 take their 120.0f/500.0f first argument in $f12. fnalign 1007 -> 969; the frame is still 0xF0 smaller than retail's 0x1C0, so retail has stack locals this body lacks.
 * 2026-10-09: 969 -> 901: the scalarised Ghidra stack floats are grouped back into
 * `float vecN[3]` locals declared in retail stack order (later declarations sit
 * lower). Retail still has four more 16-byte slots (frame 0x1C0 vs 0x180).
 */
// FUN_0018A200 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_lifetimes on
#pragma opt_common_subs off
extern float DAT_00756520; /* 0x756520 */
extern float DAT_00756524; /* 0x756524 */
extern float DAT_00756528; /* 0x756528 */
extern int DAT_007ef9f8; /* 0x7ef9f8 */
extern unsigned int DAT_007efa00; /* 0x7efa00 */
extern int DAT_007efa04; /* 0x7efa04 */
extern float fGpffff8300; /* 0xffff8300 */
extern float fGpffff8420; /* 0xffff8420 */

extern long FUN_00106330(int);
extern int FUN_001452b0(unsigned long long);
extern long FUN_0014bff0(float, unsigned long long, int);
extern long FUN_0014c4c0(float, int, int);
extern int FUN_00155280(void);
extern int FUN_002467b0(unsigned int);
extern int FUN_003b7060(void);
/* Supplied declaration required: FUN_003bb3a0. */
/* Supplied declaration required: FUN_003bb5b0. */
extern unsigned int FUN_003bbbe0(unsigned short, unsigned long long, unsigned int);
/* Supplied declaration required: FUN_003bff30. */
/* Supplied declaration required: FUN_003e05d0. */
/* Supplied declaration required: FUN_003e0870. */
extern unsigned int FUN_003e0f80(void);
/* Supplied declaration required: FUN_003e40b0. */
extern int FUN_003e9700(unsigned int);
extern float FUN_0044b920(float);
/* Supplied declaration required: FUN_0047a1e0. */
/* Supplied declaration required: FUN_0047a220. */
/* Supplied declaration required: FUN_0047a2f0. */
/* Supplied declaration required: FUN_0047a310. */
extern int FUN_00102980(void);
extern float FUN_0014b5d0(void *);
extern float FUN_0014b660(void *);
extern float FUN_0014b6f0(void *);
extern int FUN_0014bbe0(int, int, int, int, int);
extern int FUN_0014bd90(unsigned char *);
extern unsigned int FUN_0014c240(void *, void *, float, float);
extern int FUN_0014e710(unsigned char *);
extern int FUN_0014e740(unsigned char *, float *);
extern void FUN_0014e880(unsigned char *, int, short);
extern void FUN_0014e920(unsigned char *, int, int);
extern void FUN_001687f0(unsigned char *, unsigned char *);
extern void FUN_00168890(unsigned char *, unsigned char *);
extern void FUN_00168ae0(unsigned char *, unsigned char *);
extern void func_00168de0(u8 *task, const void *axis, f32 angle);
extern void FUN_0018bed0(unsigned char *, int);
extern int FUN_0018bf50(unsigned char *);
extern long long FUN_00248d80(long long);
extern float FUN_003e4180(float *);
extern int FUN_00452080(void *);
extern int FUN_00457120(void);
extern void FUN_00458f40(void *, void *);
extern int FUN_004782b0(unsigned char *);
extern void FUN_00478e70(unsigned char *);
extern short FUN_00479c30(int, int);
extern int FUN_0047a6d0(void *, int, void *);
extern void FUN_0047a850(unsigned char *);
extern void FUN_0047a870(unsigned char *);
extern void FUN_0047a8b0(void *, void *);
extern void FUN_0047a990(unsigned char *);
extern void FUN_0047a9f0(unsigned char *, short);
extern unsigned short FUN_0047aa00(unsigned char *);


extern unsigned char D_00763074[];
extern int FUN_003bb3a0();
extern int FUN_003e0870();
extern int FUN_003e05d0();
extern int FUN_003bff30();
extern int FUN_0047a2f0();
extern int FUN_0047a220();
extern int FUN_003bb5b0();
extern int FUN_003e40b0();
extern int FUN_0047a1e0();
extern int FUN_0047a310();
s32 func_0018a200(u8 *param_1)

{
    /* Retail returns zero at 0018BAA8, 0018A234. */
/* irregular: 10 native warning(s); review required */
  unsigned int *puVar1;
  unsigned int temp_v0;
  unsigned char temp_v1;
  unsigned short temp_v2;
  short temp_v3;
  int temp_v4;
  unsigned int temp_v5;
  unsigned int *puVar8;
  unsigned int temp_v6;
  int temp_v7;
  void *pvVar11;
  float *pfVar12;
  unsigned long long temp_v8;
  long temp_v9;
  long long temp_v10;
  unsigned int *puVar16;
  unsigned int temp_v11;
  float temp_v12;
  float temp_v13;

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
  if (3 < *puVar1) {
    if (*(int *)(puVar1[3] + 0x234) == 2) {
      iStack_4 = 0;
      temp_v8 = FUN_0047a310(*(unsigned int *)(puVar1[3] + 0x164));
      FUN_003bff30(temp_v8,0x18a170,&iStack_4);
      temp_v4 = FUN_00155280();
      if (*(int *)(temp_v4 + puVar1[0x14] * 4 + 0x34) != 0) {
        temp_v1 = iStack_4 != 0;
        temp_v4 = FUN_00155280();
        FUN_0014e920(*(unsigned char **)(temp_v4 + puVar1[0x14] * 4 + 0x34),puVar1[0x15],temp_v1 ^ 1);
      }
      if ((*(unsigned int *)(puVar1[3] + 0x28) & 2) == 0) {
        FUN_0018bed0(param_1,1);
      }
    }
    temp_v4 = *(int *)(puVar1[3] + 0x164);
    temp_v3 = *(short *)(temp_v4 + 0xd4);
    if ((((((temp_v3 != 5) || (*(short *)(temp_v4 + 0xd6) != 0x45ed)) &&
          ((temp_v3 != 5 || (*(short *)(temp_v4 + 0xd6) != 0x461f)))) &&
         ((temp_v3 != 5 || (*(short *)(temp_v4 + 0xd6) != 0x4651)))) &&
        ((temp_v3 != 5 || (*(short *)(temp_v4 + 0xd6) != 0x46b5)))) &&
       (((temp_v3 != 5 || (*(short *)(temp_v4 + 0xd6) != 0x46e7)) &&
        (DAT_007ef9f8 != 0 && DAT_007efa04 != 0)))) {
      temp_v8 = FUN_0047a2f0(DAT_007efa00);
      temp_v4 = FUN_0047a2f0(temp_v4);
      temp_v9 = FUN_0014bff0(120.0f,temp_v8,temp_v4 + 0x30);
      if (temp_v9 == 1) {
        temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        temp_v13 = *(float *)(temp_v4 + 0x30);
        temp_v4 = FUN_0047a2f0(DAT_007efa00);
        vec10[0] = temp_v13 - *(float *)(temp_v4 + 0x30);
        temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        temp_v13 = *(float *)(temp_v4 + 0x34);
        temp_v4 = FUN_0047a2f0(DAT_007efa00);
        vec10[1] = temp_v13 - *(float *)(temp_v4 + 0x34);
        temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        temp_v13 = *(float *)(temp_v4 + 0x38);
        temp_v4 = FUN_0047a2f0(DAT_007efa00);
        vec10[2] = temp_v13 - *(float *)(temp_v4 + 0x38);
        temp_v13 = FUN_003e4180(&vec10[0]);
        if (temp_v13 < 150.0f) {
          temp_v1 = 1;
          temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          vec20[0] = *(float *)(temp_v4 + 0x20);
          vec20[1] = *(float *)(temp_v4 + 0x24);
          vec20[2] = *(float *)(temp_v4 + 0x28);
          temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          temp_v13 = *(float *)(temp_v4 + 0x30);
          temp_v4 = FUN_0047a2f0(DAT_007efa00);
          vec30[0] = *(float *)(temp_v4 + 0x30) - temp_v13;
          temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          temp_v13 = *(float *)(temp_v4 + 0x34);
          temp_v4 = FUN_0047a2f0(DAT_007efa00);
          vec30[1] = *(float *)(temp_v4 + 0x34) - temp_v13;
          temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          temp_v13 = *(float *)(temp_v4 + 0x38);
          temp_v4 = FUN_0047a2f0(DAT_007efa00);
          vec30[2] = *(float *)(temp_v4 + 0x38) - temp_v13;
          FUN_003e40b0(&vec20[0],&vec20[0]);
          FUN_003e40b0(&vec30[0],&vec30[0]);
          if ((vec20[2] * vec30[2] + vec20[0] * vec30[0] + vec20[1] * vec30[1] <= 0.0f) &&
             (*(short *)(puVar1[3] + 0x220) != 0)) {
            temp_v1 = 0;
          }
          temp_v4 = FUN_0018bf50(*(unsigned char **)(puVar1[3] + 0x294));
          if ((temp_v4 == 0) && (temp_v1)) {
            temp_v4 = FUN_0047a2f0(DAT_007efa00);
            (*(int *)&vec40[0]) = *(unsigned int *)(temp_v4 + 0x30);
            (*(unsigned int *)&vec40[2]) = *(unsigned int *)(temp_v4 + 0x38);
            vec40[1] = *(float *)(temp_v4 + 0x34) + 140.0f;
            FUN_0047a8b0(*(void **)(puVar1[3] + 0x164),&(*(int *)&vec40[0]));
            temp_v2 = FUN_0047aa00(*(unsigned char **)(puVar1[3] + 0x164));
            FUN_0047a9f0(*(unsigned char **)(puVar1[3] + 0x164),temp_v2 | 0x1000);
          }
          else {
            FUN_0047a990(*(unsigned char **)(puVar1[3] + 0x164));
          }
        }
        else {
          FUN_0047a990(*(unsigned char **)(puVar1[3] + 0x164));
        }
      }
      else {
        FUN_0047a990(*(unsigned char **)(puVar1[3] + 0x164));
      }
    }
    temp_v4 = FUN_00457120();
    temp_v6 = *(unsigned int *)(temp_v4 + 4);
    FUN_001687f0((unsigned char *)&vec160[0],*(unsigned char **)(puVar1[3] + 0x228));
    vec50[0] = vec160[0];
    vec50[2] = vec160[2];
    vec50[1] = vec160[1] + 180.0f;
    temp_v4 = FUN_003e9700(temp_v6);
    vec70[0] = *(float *)(temp_v4 + 0x30);
    vec70[1] = *(float *)(temp_v4 + 0x34);
    vec70[2] = *(float *)(temp_v4 + 0x38);
    vec60[0] = vec50[0] - vec70[0];
    vec60[1] = vec50[1] - vec70[1];
    vec60[2] = vec50[2] - vec70[2];
    temp_v13 = FUN_003e4180(&vec60[0]);
    if (((unsigned char *)puVar1[4] != (unsigned char *)0x0) && (temp_v4 = FUN_0014bd90((unsigned char *)puVar1[4]), temp_v4 == 1)
       ) {
      FUN_0047a870(*(unsigned char **)(puVar1[3] + 0x164));
      FUN_00452080((void *)puVar1[4]);
      puVar1[4] = 0;
    }
    if (temp_v13 <= ((float*)puVar1)[0x12] + 55.0f) {
      if (puVar1[4] != 0) {
        FUN_0047a870(*(unsigned char **)(puVar1[3] + 0x164));
        FUN_00452080((void *)puVar1[4]);
        puVar1[4] = 0;
      }
      FUN_0047a220(*(unsigned int *)(puVar1[3] + 0x164),D_00763074);
      puVar1[0x13] = 1;
    }
    if ((puVar1[0x13] == 1) && (((float*)puVar1)[0x12] + 55.0f < temp_v13)) {
      FUN_0047a850(*(unsigned char **)(puVar1[3] + 0x164));
      temp_v5 = FUN_0014bbe0((int)param_1,*(int *)(puVar1[3] + 0x164),0,0xff,10);
      puVar1[4] = temp_v5;
      puVar1[0x13] = 0;
    }
  }
  switch(*puVar1) {
  case 0:
    temp_v4 = FUN_004782b0(*(unsigned char **)(puVar1[3] + 0x164));
    if (temp_v4 != 0) {
      temp_v5 = puVar1[3];
      if (*(int *)(temp_v5 + 0x234) != 3) {
        puVar8 = (unsigned int *)FUN_0047a2f0(*(unsigned int *)(temp_v5 + 0x164));
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
        FUN_00478e70(*(unsigned char **)(puVar1[3] + 0x164));
        transformAngles.x = FUN_0014b660((void *)(puVar1[3] + 0x240));
        transformAngles.y = FUN_0014b5d0((void *)(puVar1[3] + 0x240));
        transformAngles.z = FUN_0014b6f0((void *)(puVar1[3] + 0x240));
        func_00146e60(*(u16 *)puVar1[3], (u8 *)puVar1[3] + 0x270, (u8 *)&transformAngles);
        temp_v8 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        FUN_003e05d0(temp_v8);
        FUN_0047a220(*(unsigned int *)(puVar1[3] + 0x164),D_00763074);
        temp_v4 = FUN_001452b0(5);
        if (((*(float *)(temp_v4 + 0x1f0) != 0.0f) || (*(float *)(temp_v4 + 0x1f8) != 0.0f)) ||
           (*(float *)(temp_v4 + 500) != 0.0f)) {
          pvVar11 = (void *)FUN_0047a310(*(unsigned int *)(puVar1[3] + 0x164));
          FUN_00458f40(pvVar11,(void *)(temp_v4 + 0x1f0));
        }
      }
      temp_v5 = FUN_003e0f80();
      puVar1[5] = temp_v5;
      *puVar1 = *puVar1 + 1;
    }
    break;
  case 1:
    temp_v4 = FUN_00102980();
    if (temp_v4 == 9) {
      temp_v4 = FUN_00155280();
      if (*(int *)(temp_v4 + 0x34) == 0) {
        return 0;
      }
      temp_v4 = FUN_00155280();
      temp_v4 = FUN_0014e710(*(unsigned char **)(temp_v4 + 0x34));
      if (temp_v4 == 0) {
        return 0;
      }
      temp_v4 = FUN_00155280();
      if (*(int *)(temp_v4 + 0x38) == 0) {
        return 0;
      }
      temp_v4 = FUN_00155280();
      temp_v4 = FUN_0014e710(*(unsigned char **)(temp_v4 + 0x38));
      if (temp_v4 == 0) {
        return 0;
      }
      temp_v4 = FUN_00155280();
      if (*(int *)(temp_v4 + 0x3c) == 0) {
        return 0;
      }
      temp_v4 = FUN_00155280();
      temp_v4 = FUN_0014e710(*(unsigned char **)(temp_v4 + 0x3c));
      if (temp_v4 == 0) {
        return 0;
      }
    }
    temp_v5 = puVar1[3];
    temp_v11 = 1;
    if (*(int *)(temp_v5 + 0x234) == 1) {
      temp_v13 = *(float *)(*(int *)(temp_v5 + 0x280) + 0x14);
      if (temp_v13 != 0.0f) {
        vec90[0] = temp_v13;
        vec90[1] = temp_v13;
        vec90[2] = temp_v13;
        FUN_0047a1e0(*(unsigned int *)(temp_v5 + 0x164),&vec90[0]);
      }
      func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,(int)*(short *)(*(int *)(puVar1[3] + 0x280) + 6)
                    ,0,1);
    }
    else if (*(int *)(temp_v5 + 0x234) == 2) {
      temp_v5 = *(unsigned int *)(*(int *)(temp_v5 + 0x284) + 0x78);
      if (temp_v5 != 0) {
        temp_v3 = (short)temp_v5;
        temp_v4 = FUN_002467b0(temp_v5 & 0xffff);
        if ((*(unsigned int *)(temp_v4 + 4) & 1) != 0) {
          temp_v10 = FUN_00248d80((long)temp_v3);
          temp_v3 = (short)temp_v10;
        }
        temp_v9 = FUN_00106330(temp_v3 + 0x43f);
        if (temp_v9 == 0) {
          temp_v9 = FUN_00106330(temp_v3 + 0x45f);
          if (temp_v9 != 0) {
            temp_v11 = 0;
          }
        }
        else {
          temp_v11 = 2;
        }
        temp_v4 = FUN_0047a6d0(*(void **)(puVar1[3] + 0x164),2,&vecA0[0]);
        if (temp_v4 == 0) {
          temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
          vecA0[0] = *(float *)(temp_v4 + 0x30);
          (*(unsigned int *)&vecA0[2]) = *(unsigned int *)(temp_v4 + 0x38);
          vecA0[1] = *(float *)(temp_v4 + 0x34) + 175.0f;
        }
        temp_v4 = FUN_00155280();
        temp_v5 = FUN_0014e740(*(unsigned char **)(temp_v4 + temp_v11 * 4 + 0x34),&vecA0[0]);
        temp_v4 = FUN_00155280();
        FUN_0014e880(*(unsigned char **)(temp_v4 + temp_v11 * 4 + 0x34),temp_v5,4);
        puVar1[0x14] = temp_v11;
        puVar1[0x15] = temp_v5;
      }
      func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,
                    (int)*(short *)(*(int *)(puVar1[3] + 0x284) + 0x6c),0,1);
    }
    if (*(unsigned short *)(puVar1[3] + 0x298) < 4) {
      *(unsigned short *)(puVar1[3] + 0x220) = 0;
    }
    temp_v5 = puVar1[3];
    if (*(short *)(temp_v5 + 0x220) != 0) {
      if (*(short *)(temp_v5 + 0x220) == 2) {
        temp_v6 = FUN_003bbbe0(*(unsigned short *)(temp_v5 + 0x298),2,temp_v5 + 0x29c);
        *(unsigned int *)(puVar1[3] + 0x360) = temp_v6;
      }
      else {
        temp_v6 = FUN_003bbbe0(*(unsigned short *)(temp_v5 + 0x298),1,temp_v5 + 0x29c);
        *(unsigned int *)(puVar1[3] + 0x360) = temp_v6;
      }
      puVar1[6] = 0;
      puVar1[8] = 0x3f800000;
      FUN_003bb3a0(*(unsigned int *)(puVar1[3] + 0x360),0,&vecC0[0]);
      FUN_003bb3a0(*(unsigned int *)(puVar1[3] + 0x360),1,&vecD0[0]);
      vecB0[0] = vecD0[0] - vecC0[0];
      vecB0[1] = vecD0[1] - vecC0[1];
      vecB0[2] = vecD0[2] - vecC0[2];
      temp_v13 = FUN_003e4180(&vecB0[0]);
      temp_v13 = (1.0f / (float)(int)(*(unsigned short *)(puVar1[3] + 0x298) - 1)) *
               (*(float *)(puVar1[3] + 0x35c) / temp_v13);
      ((float*)puVar1)[7] = temp_v13;
      ((float*)puVar1)[6] = (((float*)puVar1)[6] + temp_v13);
      func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,1,4,1);
      FUN_003bb5b0(puVar1[6],*(unsigned int *)(puVar1[3] + 0x360),10,&vecD0[0],0);
      temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
      vecC0[0] = *(float *)(temp_v4 + 0x30);
      vecC0[1] = *(float *)(temp_v4 + 0x34);
      vecC0[2] = *(float *)(temp_v4 + 0x38);
      vecB0[0] = vecD0[0] - vecC0[0];
      vecB0[1] = vecD0[1] - vecC0[1];
      vecB0[2] = vecD0[2] - vecC0[2];
      FUN_003e40b0(&vecB0[0],&vecB0[0]);
      temp_v13 = (float)FUN_0044b920(vecB0[2] * DAT_00756528 +
                                   vecB0[0] * DAT_00756520 + vecB0[1] * DAT_00756524);
      temp_v13 = fGpffff8300 * temp_v13;
      if (vecB0[0] < 0.0f) {
        temp_v13 = temp_v13 * -1.0f;
      }
      *(unsigned int *)(puVar1[5] + 0x28) = 0x3f800000;
      *(unsigned int *)(puVar1[5] + 0x14) = 0x3f800000;
      *(unsigned int *)puVar1[5] = 0x3f800000;
      *(unsigned int *)(puVar1[5] + 0x10) = 0;
      *(unsigned int *)(puVar1[5] + 8) = 0;
      *(unsigned int *)(puVar1[5] + 4) = 0;
      *(unsigned int *)(puVar1[5] + 0x24) = 0;
      *(unsigned int *)(puVar1[5] + 0x20) = 0;
      *(unsigned int *)(puVar1[5] + 0x18) = 0;
      *(unsigned int *)(puVar1[5] + 0x38) = 0;
      *(unsigned int *)(puVar1[5] + 0x34) = 0;
      *(unsigned int *)(puVar1[5] + 0x30) = 0;
      *(unsigned int *)(puVar1[5] + 0xc) = *(unsigned int *)(puVar1[5] + 0xc) | 0x20003;
      FUN_003e0870(temp_v13,puVar1[5],0x756510,2);
      FUN_00168890(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)puVar1[5]);
    }
    puVar1[0xb] = 0xffffffff;
    *puVar1 = *puVar1 + 1;
    break;
  case 2:
    *(unsigned int *)(puVar1[3] + 0x28) = *(unsigned int *)(puVar1[3] + 0x28) | 0x10000000;
    FUN_0047a850(*(unsigned char **)(puVar1[3] + 0x164));
    temp_v5 = FUN_0014bbe0((int)param_1,*(int *)(puVar1[3] + 0x164),0,0xff,8);
    puVar1[4] = temp_v5;
    *puVar1 = *puVar1 + 1;
    break;
  case 3:
    temp_v4 = FUN_0014bd90((unsigned char *)puVar1[4]);
    if (temp_v4 != 0) {
      FUN_0047a870(*(unsigned char **)(puVar1[3] + 0x164));
      FUN_00452080((void *)puVar1[4]);
      puVar1[4] = 0;
      *(unsigned int *)(puVar1[3] + 0x28) = *(unsigned int *)(puVar1[3] + 0x28) | 0x10000000;
      *puVar1 = *puVar1 + 1;
    }
    break;
  case 4:
    if (DAT_007ef9f8 != 0 && DAT_007efa04 != 0) {
      temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
      temp_v7 = FUN_0047a2f0(DAT_007efa00);
      temp_v9 = FUN_0014c4c0(500.0f,temp_v4 + 0x30,temp_v7 + 0x30);
      if (temp_v9 == 1) {
        pvVar11 = (void *)FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        temp_v4 = FUN_0047a2f0(DAT_007efa00);
        temp_v5 = FUN_0014c240(pvVar11,(void *)(temp_v4 + 0x30),90.0f,250.0f);
        if (temp_v5 != 0) {
          if (puVar1[0xb] != 0xffffffff) {
            return 0;
          }
          temp_v3 = FUN_00479c30(*(int *)(puVar1[3] + 0x164),0);
          puVar1[0xb] = (int)temp_v3;
          temp_v5 = puVar1[3];
          if (*(int *)(temp_v5 + 0x234) == 1) {
            func_00479940(*(unsigned char **)(temp_v5 + 0x164),0,(int)*(short *)(*(int *)(temp_v5 + 0x280) + 6),4
                          ,1);
            return 0;
          }
          if (*(int *)(temp_v5 + 0x234) != 2) {
            return 0;
          }
          func_00479940(*(unsigned char **)(temp_v5 + 0x164),0,(int)*(short *)(*(int *)(temp_v5 + 0x284) + 0x6c),
                        4,1);
          return 0;
        }
      }
      if (-1 < (int)puVar1[0xb]) {
        func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,(int)(short)puVar1[0xb],4,1);
        puVar1[0xb] = 0xffffffff;
      }
      temp_v5 = puVar1[3];
      temp_v3 = *(short *)(temp_v5 + 0x220);
      if (temp_v3 == 3) {
        temp_v11 = puVar1[10];
        if ((int)temp_v11 < 1) {
          if ((temp_v11 == 0) && (temp_v3 = FUN_00479c30(*(int *)(temp_v5 + 0x164),0), temp_v3 != 1)) {
            func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,1,4,1);
          }
          if ((int)puVar1[9] < 1) {
            FUN_003bb5b0(puVar1[6],*(unsigned int *)(puVar1[3] + 0x360),10,&vec120[0],0);
            temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
            vec110[0] = *(float *)(temp_v4 + 0x30);
            vec110[1] = *(float *)(temp_v4 + 0x34);
            vec110[2] = *(float *)(temp_v4 + 0x38);
            vec130[0] = vec120[0] - vec110[0];
            vec130[1] = vec120[1] - vec110[1];
            vec130[2] = vec120[2] - vec110[2];
            FUN_003e40b0(&vec130[0],&vec130[0]);
            temp_v13 = (float)FUN_0044b920(vec130[2] * DAT_00756528 +
                                         vec130[0] * DAT_00756520 + vec130[1] * DAT_00756524);
            temp_v13 = fGpffff8300 * temp_v13;
            if (vec130[0] < 0.0f) {
              temp_v13 = temp_v13 * -1.0f;
            }
            *(unsigned int *)(puVar1[5] + 0x28) = 0x3f800000;
            *(unsigned int *)(puVar1[5] + 0x14) = 0x3f800000;
            *(unsigned int *)puVar1[5] = 0x3f800000;
            *(unsigned int *)(puVar1[5] + 0x10) = 0;
            *(unsigned int *)(puVar1[5] + 8) = 0;
            *(unsigned int *)(puVar1[5] + 4) = 0;
            *(unsigned int *)(puVar1[5] + 0x24) = 0;
            *(unsigned int *)(puVar1[5] + 0x20) = 0;
            *(unsigned int *)(puVar1[5] + 0x18) = 0;
            *(unsigned int *)(puVar1[5] + 0x38) = 0;
            *(unsigned int *)(puVar1[5] + 0x34) = 0;
            *(unsigned int *)(puVar1[5] + 0x30) = 0;
            *(unsigned int *)(puVar1[5] + 0xc) = *(unsigned int *)(puVar1[5] + 0xc) | 0x20003;
            FUN_003e0870(temp_v13,puVar1[5],0x756510,2);
            FUN_00168890(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)puVar1[5]);
            FUN_00168ae0(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)&vec120[0]);
            ((float*)puVar1)[6] = (((float*)puVar1)[7] * ((float*)puVar1)[8] + ((float*)puVar1)[6] + 0.0f);
            if (0.0f < ((float*)puVar1)[8]) {
              if (1.0f < ((float*)puVar1)[6]) {
                ((float*)puVar1)[6] = (1.0f - ((float*)puVar1)[7]);
                puVar1[8] = 0xbf800000;
                puVar1[9] = 0x5a;
                temp_v4 = FUN_003b7060();
                puVar1[10] = temp_v4 % 0x5a + 0x3c;
                func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,0,4,1);
              }
            }
            else if (((float*)puVar1)[6] < 0.0f) {
              puVar1[6] = puVar1[7];
              puVar1[8] = 0x3f800000;
              puVar1[9] = 0x5a;
              temp_v4 = FUN_003b7060();
              puVar1[10] = temp_v4 % 0x5a + 0x3c;
              func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,0,4,1);
            }
          }
          else {
            func_00168de0(*(unsigned char **)(puVar1[3] + 0x228), D_00756510, 2.0f);
            puVar1[9] = puVar1[9] - 1;
          }
        }
        else {
          puVar1[10] = temp_v11 - 1;
        }
      }
      else if (((temp_v3 == 4) || (temp_v3 == 2)) || (temp_v3 == 1)) {
        if (((temp_v3 != 4) || (((float*)puVar1)[6] != 1.0f)) &&
           (temp_v3 = FUN_00479c30(*(int *)(temp_v5 + 0x164),0), temp_v3 != 1)) {
          func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,1,4,1);
        }
        FUN_003bb5b0(puVar1[6],*(unsigned int *)(puVar1[3] + 0x360),10,&vecF0[0],0);
        temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
        vecE0[0] = *(float *)(temp_v4 + 0x30);
        vecE0[1] = *(float *)(temp_v4 + 0x34);
        vecE0[2] = *(float *)(temp_v4 + 0x38);
        vec100[0] = vecF0[0] - vecE0[0];
        vec100[1] = vecF0[1] - vecE0[1];
        vec100[2] = vecF0[2] - vecE0[2];
        FUN_003e40b0(&vec100[0],&vec100[0]);
        temp_v13 = (float)FUN_0044b920(vec100[2] * DAT_00756528 +
                                     vec100[0] * DAT_00756520 + vec100[1] * DAT_00756524);
        temp_v13 = fGpffff8300 * temp_v13;
        if (vec100[0] < 0.0f) {
          temp_v13 = temp_v13 * -1.0f;
        }
        *(unsigned int *)(puVar1[5] + 0x28) = 0x3f800000;
        *(unsigned int *)(puVar1[5] + 0x14) = 0x3f800000;
        *(unsigned int *)puVar1[5] = 0x3f800000;
        *(unsigned int *)(puVar1[5] + 0x10) = 0;
        *(unsigned int *)(puVar1[5] + 8) = 0;
        *(unsigned int *)(puVar1[5] + 4) = 0;
        *(unsigned int *)(puVar1[5] + 0x24) = 0;
        *(unsigned int *)(puVar1[5] + 0x20) = 0;
        *(unsigned int *)(puVar1[5] + 0x18) = 0;
        *(unsigned int *)(puVar1[5] + 0x38) = 0;
        *(unsigned int *)(puVar1[5] + 0x34) = 0;
        *(unsigned int *)(puVar1[5] + 0x30) = 0;
        *(unsigned int *)(puVar1[5] + 0xc) = *(unsigned int *)(puVar1[5] + 0xc) | 0x20003;
        FUN_003e0870(temp_v13,puVar1[5],0x756510,2);
        if ((*(short *)(puVar1[3] + 0x220) != 4) || (((float*)puVar1)[6] < 1.0f)) {
          FUN_00168890(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)puVar1[5]);
          FUN_00168ae0(*(unsigned char **)(puVar1[3] + 0x228),(unsigned char *)&vecF0[0]);
          ((float*)puVar1)[6] = (((float*)puVar1)[6] + ((float*)puVar1)[7]);
        }
        if (*(short *)(puVar1[3] + 0x220) == 4) {
          if (1.0f < ((float*)puVar1)[6]) {
            puVar1[6] = 0x3f800000;
            func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,0,4,1);
          }
        }
        else if (1.0f < ((float*)puVar1)[6]) {
          puVar1[6] = 0;
        }
      }
    }
    break;
  case 5:
  case 6:
    temp_v4 = FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
    vec140[0] = *(float *)(temp_v4 + 0x20);
    vec140[1] = *(float *)(temp_v4 + 0x24);
    vec140[2] = *(float *)(temp_v4 + 0x28);
    pfVar12 = (float *)FUN_0047a2f0(*(unsigned int *)(puVar1[3] + 0x164));
    vec150[0] = *pfVar12;
    vec150[1] = pfVar12[1];
    vec150[2] = pfVar12[2];
    FUN_003e40b0(&vec140[0],&vec140[0]);
    FUN_003e40b0(&vec150[0],&vec150[0]);
    FUN_0047a990(*(unsigned char **)(puVar1[3] + 0x164));
    temp_v13 = ((float*)puVar1)[0x11] * vec140[2] +
             ((float*)puVar1)[0xf] * vec140[0] + ((float*)puVar1)[0x10] * vec140[1];
    if (temp_v13 < 1.0f) {
      temp_v12 = 15.0f;
      if (1.0f - temp_v13 < fGpffff8420) {
        temp_v12 = (1.0f - temp_v13) * 180.0f;
        temp_v13 = 1.0f;
      }
      if (((float*)puVar1)[0x11] * vec150[2] +
          ((float*)puVar1)[0xf] * vec150[0] + ((float*)puVar1)[0x10] * vec150[1] < 0.0f) {
        temp_v12 = temp_v12 * -1.0f;
      }
      func_00168de0(*(unsigned char **)(puVar1[3] + 0x228), D_00756510, temp_v12);
    }
    if (temp_v13 == 1.0f) {
      if (*puVar1 == 5) {
        func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,3,8,0);
        *puVar1 = 7;
      }
      else {
        func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,0,8,1);
        *puVar1 = 4;
      }
    }
    break;
  case 7:
    if ((*(char *)(*(int *)(puVar1[3] + 0x164) + 0xee) == '\x01') &&
       (temp_v3 = FUN_00479c30(*(int *)(puVar1[3] + 0x164),0), temp_v3 != 0)) {
      func_00479940(*(unsigned char **)(puVar1[3] + 0x164),0,0,8,1);
    }
  }
  return 0;
}
#pragma opt_common_subs on
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/code1_0018", func_0018a200);
#endif
// FUN_0018BAD0
void func_0018bad0(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x14);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0018BB20
s32 func_0018bb20(s32 arg0, s32 arg1)
{
    s32 temp_17;
    u8 *temp_2;

    func_0044ea90(&D_005F5340, 0x2E6);
    temp_2 = D_008873F4[0](1, 0x58, 0x40000);
    if (temp_2 == NULL)
        return 0;
    temp_17 = (s32)func_00451fc0((void *)((u8 *)arg0), (const void *)(&D_005F5350), 0xF, 0, 0, func_0018a200, func_0018bad0, (u8 *)(temp_2));
    *(s32 *)(temp_2 + 0xC) = arg1;
    *(f32 *)(temp_2 + 0x48) = *(f32 *)(((u8 *)(uintptr_t)func_00457120()) + 0x80);
    return temp_17;
}
// FUN_0018BBF0
s32 func_0018bbf0(u8 *arg0)
{
    u32 value;

    if (arg0 == NULL) {
        return 1;
    }
    value = *(u32 *)(*(u8 **)(arg0 + 0x38));
    return value >= 4;
}
/* Shared animation contracts: CSE retains the common transition constant.
 * The O1 profile still preserves the retail FPU accumulator order. */
// FUN_0018BC20
/* measured: optimization_level 1 preserves retail's FPU scheduling for this
   vector normalize; -O2 reorders it into a mismatching form. */
#pragma optimization_level 1
#pragma push
#pragma opt_common_subs on
void func_0018bc20(u8 *arg0)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 *temp_4;
    f32 *temp_4_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 guard38;
    f32 guard44;
    f32 guard30;
    f32 guard3c;
    f32 guard34;
    f32 guard40;
    u8 *temp_16;
    u8 *temp_2;
    void *target;
    s32 zero;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = mdlGetMatrix(*(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164));
    temp_4 = (f32 *)(temp_16 + 0x30);
    *(struct Vec3 *)temp_4 = *(struct Vec3 *)(temp_2 + 0x20);
    RwV3dNormalize((RainVector *)temp_4, (const RainVector *)temp_4);
    temp_f20 = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x30);
    *(f32 *)(temp_16 + 0x3C) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x30) - temp_f20;
    temp_f20_2 = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x34);
    *(f32 *)(temp_16 + 0x40) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x34) - temp_f20_2;
    temp_f20_3 = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164)) + 0x38);
    *(f32 *)(temp_16 + 0x44) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x38) - temp_f20_3;
    temp_4_2 = (f32 *)(temp_16 + 0x3C);
    RwV3dNormalize((RainVector *)temp_4_2, (const RainVector *)temp_4_2);
    guard38 = *(f32 *)(temp_16 + 0x38);
    guard44 = *(f32 *)(temp_16 + 0x44);
    guard30 = *(f32 *)(temp_16 + 0x30);
    guard3c = *(f32 *)(temp_16 + 0x3C);
    guard34 = *(f32 *)(temp_16 + 0x34);
    guard40 = *(f32 *)(temp_16 + 0x40);
    if ((guard30 * guard3c + guard34 * guard40) +
        guard38 * guard44 <
        fGpffff8218) {
        *(s32 *)(temp_16 + 0x2C) =
            (s16)func_00479c30(
                *(u32 *)(*(u8 **)(temp_16 + 0xC) + 0x164), 0);
        target = *(void **)(*(u8 **)(temp_16 + 0xC) + 0x164);
        zero = 0;
        func_00479940(target, zero, 1, 4, 1);
        *(s32 *)temp_16 = 5;
        return;
    }
    func_00479940(
        *(void **)(*(u8 **)(temp_16 + 0xC) + 0x164), 0, 3, 8, 0);
    *(s32 *)temp_16 = 7;
}
#pragma pop
#pragma optimization_level 2
/* measured: optimization_level 1 preserves the retail FPU accumulator order. */
#pragma optimization_level 1
/* Copy the complete direction vector when starting the transition. The
 * aggregate retains all three source loads with shared constants enabled. */
// FUN_0018BDD0
#pragma push
#pragma opt_common_subs on
void func_0018bdd0(u8 *arg0)
{
    struct Direction {
        f32 x;
        f32 y;
        f32 z;
    };
    u8 *temp_16;
    u8 *target;
    f32 guard38;
    f32 guard44;
    f32 guard30;
    f32 guard3c;
    f32 guard34;
    f32 guard40;
    s32 zero;

    temp_16 = *(u8 **)(arg0 + 0x38);
    guard38 = *(f32 *)(temp_16 + 0x38);
    guard44 = *(f32 *)(temp_16 + 0x44);
    guard30 = *(f32 *)(temp_16 + 0x30);
    guard3c = *(f32 *)(temp_16 + 0x3C);
    guard34 = *(f32 *)(temp_16 + 0x34);
    guard40 = *(f32 *)(temp_16 + 0x40);
    if ((guard30 * guard3c + guard34 * guard40) + guard38 * guard44 <
        fGpffff8218) {
        *(struct Direction *)(temp_16 + 0x3C) = *(struct Direction *)(temp_16 + 0x30);
        target = *(u8 **)(*(u8 **)(temp_16 + 0xC) + 0x164);
        zero = 0;
        func_00479940(target, zero, 1, 4, 1);
        *(s32 *)temp_16 = 6;
        return;
    }
    func_00479940(*(u8 **)(*(u8 **)(temp_16 + 0xC) + 0x164),
                  0, 0, 8, 1);
    *(s32 *)temp_16 = 4;
}
#pragma pop
/* measured: close optimization_level 1 FPU accumulator probe. */
#pragma optimization_level 2
/* measured: opt_propagation off probe preserves retail's handle-load/result
   initialization order for the state predicate. */
#pragma opt_propagation off
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
// FUN_0018BED0
void func_0018bed0(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (*(s32 *)((u8 *)func_00155280() + *(s32 *)(p + 0x50) * 4 + 0x34) == 0) {
        return;
    }
    func_0014e8f0(*(s32 *)((u8 *)func_00155280() + *(s32 *)(p + 0x50) * 4 + 0x34),
                  *(s32 *)(p + 0x54), arg1);
}

// FUN_0018BF50
s32 func_0018bf50(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);
    s32 r = 0;
    s32 v = *(s32 *)p;
    if (v == 5) {
        goto set;
    }
    if (v != 6) {
        goto rest;
    }
set:
    r = 1;
rest:
    if (*(u16 *)(*(u8 **)(p + 0xC) + 0x220) == 3) {
        if (*(s32 *)(p + 0x24) > 0) {
            r = 1;
        }
    }
    return r;
}

typedef struct MaterialTextureContext {
    s32 found;
    RwTexture *texture;
} MaterialTextureContext;

// FUN_0018C610
struct RpMaterial *func_0018c610(struct RpMaterial *material, void *data) {
    MaterialTextureContext *context = data;

    if (K_Clump_MatUsrDataHasData((u8 *)material, D_005F5438) != 0) {
        context->found = 1;
        func_003c42b0(material, context->texture);
    }
    return material;
}

// FUN_0018C680
void *func_0018c680(void *object, void *data)
{
    u8 *arg0 = object;
    func_003c21e0(*(struct RpGeometry **)(arg0 + 0x18), func_0018c610, data);
    return object;
}
// FUN_0018C6C0
s32 func_0018c6c0(u8 *arg0, s32 arg1)
{
    MaterialTextureContext context;

    context.found = 0;
    context.texture = (RwTexture *)(uintptr_t)arg1;
    func_003bff30(arg0, func_0018c680, &context);
    return context.found;
}
// FUN_0018C700
void func_0018c700(f32 fp0) {
    s32 a;
    s32 b;

    a = (s32)func_003ef6d0();
    b = (s32)func_003ef650((RwTexDictionary *)a, (const char *)D_005F5360);
    func_003f6800(b, fp0);
}

/* At the -O2 file baseline this function is normalized_diff 2: retail reads
   `mfc1 $a1` and `or $a1,$a1,$v1` where -O2 colours both one register lower.
   The bracket is closed back to the -O2 baseline immediately below the body.
   measured: optimization_level 1 for this function alone, plus materialising
   the 2147483648.0f constant into a named local AFTER the func_003ef650 call
   rather than inline, gives object 136B/window 144B, normalized_diff 0. */
#pragma optimization_level 1
// FUN_0018C750
void func_0018c750(f32 fparg0)
{
    s32 temp_2;
    s32 var_5;
    f32 constant;

    temp_2 = (s32)func_003ef650(func_003ef6d0(), (const char *)D_005F5360);
    constant = 2147483648.0f;
    if (constant <= fparg0) {
        goto positive;
    }
    var_5 = (s32)fparg0;
    goto done;
positive:
    var_5 = (s32)(fparg0 - constant);
    var_5 |= (s32)0x80000000;
done:
    func_003f68a0(temp_2, var_5);
}
/* measured: restore optimization level after func_0018c750. */
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
   of func_00110960 above is also load-bearing - its first argument is a
   32-bit id and its second an unsigned flag word, not the s64/s32 pair m2c
   printed, and the s64 form costs a dsll32/dsra32 pair at every call site in
   this unit. */
// FUN_0018C7E0
s32 func_0018c7e0(void) {
    s32 dungeon;
    s32 date;
    s32 w1;
    s32 phase;
    s32 res;

    dungeon = func_0015a160();
    res = 0;
    date = (s16)func_001060b0();
    w1 = (s8)func_00110960(date, func_001060c0() & 0xFF);
    phase = func_001060c0() & 0xFF;
    if (iGpffffb264 == 1) {
        return 0;
    }
    if (datGetFlag(0x3E0) == 1) {
        func_0045a3e0(0x2C, 1);
        return 1;
    }
    if (dungeon == 0) {
        if ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 3)) {
            res = 0x14;
        } else if ((*(s32 *)iGpffff9db0 == 7) && ((*(s32 *)(iGpffff9db0 + 4) == 2) || (*(s32 *)(iGpffff9db0 + 4) == 3))) {
            s32 t;
            t = func_001060c0() & 0xFF;
            if (*(s32 *)(iGpffff9db0 + 4) == 2) {
                if (clndIsDateInRange(4, 1, 0xB, 4) == 1) {
                    res = 0x19;
                } else {
                    res = 0x1A;
                }
            } else if ((*(s32 *)(iGpffff9db0 + 4) == 3) && (((t & 0xFF) == 3) || ((t & 0xFF) == 4))) {
                if (clndIsDateInRange(4, 1, 0xB, 4) == 1) {
                    res = 0x19;
                } else {
                    res = 0x1A;
                }
            }
        } else if (((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 3)) || ((*(s32 *)iGpffff9db0 == 9) && (*(s32 *)(iGpffff9db0 + 4) == 4))) {
            res = 0;
        } else {
            s32 t2;
            s32 w2;
            dungeon = (s16)func_001060b0();
            t2 = func_001060c0() & 0xFF;
            w2 = (s8)func_00110960(dungeon, t2);
            switch (w2) {
            case 0:
                res = 0x16;
                break;
            case 1:
                break;
            case 3:
                break;
            case 2:
                res = 0x17;
                break;
            case 4:
                break;
            }
            if (datGetFlag(0x8A) == 1) {
                res = 0x18;
            }
        }
        if (((s8)w1 == 0) && (((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 9)) || ((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 0xE)) || ((*(s32 *)iGpffff9db0 == 6) && (*(s32 *)(iGpffff9db0 + 4) == 0xF)) || ((*(s32 *)iGpffff9db0 == 7) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 8) && (*(s32 *)(iGpffff9db0 + 4) == 9)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 2)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 3)) || ((*(s32 *)iGpffff9db0 == 0xA) && (*(s32 *)(iGpffff9db0 + 4) == 4)) || ((*(s32 *)iGpffff9db0 == 0xB) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0xD) && (*(s32 *)(iGpffff9db0 + 4) == 8)) || ((*(s32 *)iGpffff9db0 == 0x11) && (*(s32 *)(iGpffff9db0 + 4) == 1)) || ((*(s32 *)iGpffff9db0 == 0x11) && (*(s32 *)(iGpffff9db0 + 4) == 3)))) {
            if ((clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) && (((phase & 0xFF) == 3) || ((phase & 0xFF) == 4))) {
                res = 0;
            } else if ((phase & 0xFF) == 4) {
                if (clndIsDateInRange(9, 1, 9, 7) == 1) {
                    res = 0;
                } else if (clndIsDateInRange(9, 8, 0xA, 5) == 1) {
                    res = 0;
                }
            }
        }
    } else if ((dungeon <= 5) || (dungeon == 0x14) || (dungeon == 0x28) || (dungeon == 0x3C) || (dungeon == 0x50) || (dungeon == 0x64) || (dungeon == 0x78) || (dungeon == 0x8C)) {
        res = 0x1B;
    } else if (dungeon < 0x14) {
        res = 0x1C;
    } else if (dungeon < 0x28) {
        res = 0x1D;
    } else if (dungeon < 0x3C) {
        res = 0x1E;
    } else if (dungeon < 0x50) {
        res = 0x1F;
    } else if (dungeon < 0x64) {
        res = 0x20;
    } else if (dungeon < 0x78) {
        res = 0x21;
    } else if (dungeon < 0x8C) {
        res = 0x22;
    } else if (dungeon < 0x9F) {
        res = 0x23;
    } else if (dungeon < 0xA0) {
        res = 0;
    }
    if (res > 0) {
        func_0045a3e0((s16)res, 1);
        return 1;
    }
    func_004598e0(0x1E);
    return 0;
}
/* MATCHED: the dispatch reads the pair at iGpffff9db0 with only the first
   word cached - retail reloads *(s32 *)(ctx + 4) at every test, so the
   long (major, minor) chains are written out rather than staged in a
   local.  The story flag is `s8`, which re-extends on each read the way
   retail does, and the sub-state is `u8`, whose reads carry the andi. */
// FUN_0018CED0
s32 func_0018ced0(void)
{
    extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
    extern void func_0045b2e0(s32 arg0);
    u8 *ctx;
    s32 major;
    s32 result;
    s32 mode;
    s8 kind;
    u8 sub;

    result = 0;
    mode = func_0015a160();
    kind = (s8)func_00110960((s16)func_001060b0(), func_001060c0() & 0xFF);
    sub = (u8)func_001060c0();
    if (datGetFlag(0x3E0) == 1) {
        func_0045aac0(3, 0, 0x1E);
        return 0;
    }
    if (mode == 0) {
        ctx = iGpffff9db0;
        major = *(s32 *)ctx;
        if (major == 7 && *(s32 *)(ctx + 4) == 3) {
            if (kind == 1 || kind == 3) {
                result = 0x3D;
            } else if (sub == 0) {
                if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) {
                    if (kind == 0) {
                        result = 2;
                    } else if (kind == 2) {
                        result = 6;
                    }
                } else {
                    result = 6;
                }
            } else if (sub == 5) {
                if (clndIsDateInRange(7, 0x17, 8, 0x1F) == 1) {
                    result = 0xB;
                } else if (clndIsDateInRange(9, 1, 0xA, 0x12) == 1) {
                    result = 4;
                } else {
                    result = 0xA;
                }
            }
        } else if (((major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
                    (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
                    (major == 0xA && *(s32 *)(ctx + 4) == 4)) &&
                   (kind == 0 || kind == 2) && sub == 0) {
            if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1) {
                if (kind == 0) {
                    result = 2;
                } else if (kind == 2) {
                    result = 6;
                }
            } else {
                result = 6;
            }
        } else if ((major == 9 && *(s32 *)(ctx + 4) == 1) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 2) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 3) ||
                   (major == 9 && *(s32 *)(ctx + 4) == 4)) {
            result = 0x3F;
        } else if (kind == 1 || kind == 3) {
            if (major == 1 ||
            (major == 6 && *(s32 *)(ctx + 4) == 9) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xE) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
            (major == 7 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 2) ||
            (major == 8 && *(s32 *)(ctx + 4) == 9) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 8) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 1) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 3)) {
                result = 8;
            } else if (major == 7 && *(s32 *)(ctx + 4) == 2) {
                result = 0x3D;
            } else if ((major == 4 && *(s32 *)(ctx + 4) == 1) ||
            (major == 4 && *(s32 *)(ctx + 4) == 2) ||
            (major == 4 && *(s32 *)(ctx + 4) == 3) ||
            (major == 6 && *(s32 *)(ctx + 4) == 1) ||
            (major == 6 && *(s32 *)(ctx + 4) == 2) ||
            (major == 6 && *(s32 *)(ctx + 4) == 3) ||
            (major == 6 && *(s32 *)(ctx + 4) == 4) ||
            (major == 6 && *(s32 *)(ctx + 4) == 5) ||
            (major == 6 && *(s32 *)(ctx + 4) == 6) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xA) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xB) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xC) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xD) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0x10) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0x11) ||
            (major == 8 && *(s32 *)(ctx + 4) == 5) ||
            (major == 8 && *(s32 *)(ctx + 4) == 7) ||
            (major == 8 && *(s32 *)(ctx + 4) == 8) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xC && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 1)) {
                result = 0x3E;
            }
        } else if (kind == 0) {
            if ((major == 6 && *(s32 *)(ctx + 4) == 9) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xE) ||
            (major == 6 && *(s32 *)(ctx + 4) == 0xF) ||
            (major == 7 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 1) ||
            (major == 8 && *(s32 *)(ctx + 4) == 2) ||
            (major == 8 && *(s32 *)(ctx + 4) == 9) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 2) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 3) ||
            (major == 0xA && *(s32 *)(ctx + 4) == 4) ||
            (major == 0xB && *(s32 *)(ctx + 4) == 1) ||
            (major == 0xD && *(s32 *)(ctx + 4) == 8) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 1) ||
            (major == 0x11 && *(s32 *)(ctx + 4) == 3)) {
                if (clndIsDateInRange(7, 0x1B, 8, 0x1F) == 1 && (sub == 3 || sub == 4)) {
                    result = 2;
                } else if (sub == 4) {
                    if (clndIsDateInRange(9, 1, 9, 7) == 1) {
                        result = 3;
                    } else if (clndIsDateInRange(9, 8, 0xA, 5) == 1) {
                        result = 4;
                    }
                }
            }
        }
    } else if (mode == 0x9F) {
        result = 0x15;
    }
    if (result > 0) {
        func_004598e0(0x1E);
        func_0045b2e0(result);
        return 1;
    }
    func_0045aac0(3, 0, 0x1E);
    return 0;
}
/* MATCH: stage the s32 byte count without a conflicting callee prototype.
   Unsigned elapsed subtraction preserves retail timer wrap. 332B/336B,
   normalized_diff 0; only four zero-tail bytes are absent. */
#pragma push
#pragma opt_propagation off
// FUN_0018DDE0
s32 func_0018dde0(u8 *arg0)
{
    u8 *work;
    s32 state;

    work = *(u8 **)(arg0 + 0x38);
    if ((*(s32 *)(work + 4) == 1))
        return 0;
    if (func_0029d2e0() > 0)
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
            *(s32 *)(work + 0x10) = func_0029db50(0xF, iGpffffb27c, size, 0);
            *(s32 *)(work + 0) = 2;
            *(u32 *)(work + 8) = 0x384U;
            *(s32 *)(work + 0xC) = D_0076428C;
        }
        break;
    case 2:
        if (func_00452490(*(s32 *)(work + 0x10)) == 1)
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
// FUN_0018DF30
void func_0018df30(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}



// FUN_0018DF60
s32 func_0018df60(s32 arg0)
{
    s32 temp_2;
    u8 *temp_2_2;

    if (func_0015a560() == 0)
        return 0;
    func_0044ea90(&D_005F54D8, 0x91);
    temp_2_2 = D_008873F4[0](1, 0x14, 0x40000);
    if (temp_2_2 == NULL)
        return 0;
    temp_2 = (s32)func_00451fc0((void *)((u8 *)arg0), (const void *)(&D_005F54E8), 0xF, 0, 0, func_0018dde0, func_0018df30, (u8 *)(temp_2_2));
    *(s32 *)(temp_2_2 + 8) = 0x1E;
    return temp_2;
}
// FUN_0018E030
void func_0018e030(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        u8 *p = *(u8 **)(arg0 + 0x38);
        *(s32 *)(p + 4) = arg1;
        *(s32 *)(p + 0xC) = D_0076428C;
    }
}



// FUN_0018E450
s32 func_0018e450(u8 *arg0)
{
    s32 *p;
    s32 state;

    p = *(s32 **)(arg0 + 0x38);
    state = *p;
    switch (state) {
    case 0:
        *p = state + 1;
        break;
    case 1:
        func_0018e780(0);
        *p += 1;
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}

// FUN_0018E4D0
void func_0018e4d0(u8 *arg0)
{
    s32 value;
    value = *(s32 *)(*(u8 **)(arg0 + 0x38) + 4);
    if (value != 0) {
        func_004787e0(value);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

/* One 0x4A-byte pad record; the pads start at 0x8C0240 (func_00452760). */
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
// FUN_0018E810
s32 func_0018e810(u8 *arg0)
{
    extern PadStatus D_008C0240[2];
    extern s64 iGpffff9fd0;
    extern PanelColor iGpffff9fd8;
    extern char iGpffff9fdc[3];
    extern s32 iGpffffb240;
    extern void func_001582f0(s32 mode, s32 value, s32 arg2);
    PanelColor color;
    u8 *state;
    s32 v0;

    state = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)state) {
    case 0:
        *(KwlnTask **)(state + 0x1B438) = func_00470250((KwlnTask *)arg0, 0x100, 0x40);
        func_00470810(*(KwlnTask **)(state + 0x1B438), D_005F5730, 4);
        func_00470430(*(u8 **)(state + 0x1B438), 0x14);
        func_004703c0(*(u8 **)(state + 0x1B438), 4);
        func_004703d0(*(u8 **)(state + 0x1B438), 1);
        *(u8 **)(state + 0x1B434) = D_007E3720;
        *(s32 *)state += 1;
        break;
    case 1:
        if (D_008C0240[0].trigger & 0x40) {
            switch (func_00470e20(*(u8 **)(state + 0x1B438))) {
            case 0:
                *((u8 *)func_00155280() + 0x4A) =
                    *(*(u8 **)(state + 0x1B434) +
                      *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *(*(u8 **)(state + 0x1B434) +
                      *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(state + 4) = 2;
                v0 = *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 0);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(KwlnTask **)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            case 1:
                *((u8 *)func_00155280() + 0x4A) =
                    *(*(u8 **)(state + 0x1B434) +
                      *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *(*(u8 **)(state + 0x1B434) +
                      *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(state + 4) = 0;
                v0 = *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 1);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(KwlnTask **)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            case 2:
                *((u8 *)func_00155280() + 0x4A) =
                    *(*(u8 **)(state + 0x1B434) +
                      *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)func_00155280() + 0x4B) =
                    *(*(u8 **)(state + 0x1B434) +
                      *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(state + 4) = 1;
                v0 = *func_00470bd0(*(KwlnTask **)(state + 0x1B438), 2);
                func_001582f0(*(s32 *)(state + 4), v0, 0);
                func_00452080(*(KwlnTask **)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            }
        }
        break;
    case 2:
        *(s32 *)state += 1;
        break;
    case 3:
        *(s32 *)state += 1;
        break;
    case 4:
        if (D_008C0240[0].trigger & 0x8000) {
            *(s32 *)(state + 0x1B430) -= 1;
        } else if (D_008C0240[0].trigger & 0x2000) {
            *(s32 *)(state + 0x1B430) += 1;
        }
        if (*(s32 *)(state + 0x1B430) < 0) {
            *(s32 *)(state + 0x1B430) = 3;
        }
        if (*(s32 *)(state + 0x1B430) > 3) {
            *(s32 *)(state + 0x1B430) = 0;
        }
        if (D_008C0240[0].trigger & 0x40) {
            func_001582f0(*(s32 *)(state + 4), 0, 0);
        }
        func_00450340(iGpffff9fd0, iGpffff9fdc, iGpffffb240);
        {
            s32 y;
            s32 x;
            s32 ty;
            s32 rowOffset;
            u8 *panels;
            s32 type;
            s32 off;
            f32 fx;
            f32 fy;

            for (y = 0; y < 0x18; y++) {
                for (x = 0, rowOffset = y * 0x100, ty = y * 0x12,
                     panels = state + y * 0x1200; x < 0x10; x++) {
                    if (((MapTestGrid *)(rowOffset + (intptr_t)func_00155280()))->cells[0][x].occupied != 0 &&
                        (((MapTestGrid *)(rowOffset + (intptr_t)func_00155280()))->cells[0][x].flags & 0xF) == 1) {
                        off = x;
                        type = ((MapTestGrid *)(rowOffset + (intptr_t)func_00155280()))->cells[0][off].shape;
                        fx = (f32)(x * 0x12);
                        fy = (f32)ty;
                        func_0017d1f0(D_007966D0, panels + x * 0x120 + 0x10, type, 0, fx, fy, 0.0f, ((MapTestGrid *)(rowOffset + (intptr_t)func_00155280()))->cells[0][off].rotation);
                    }
                    if (((MapTestGrid *)(rowOffset + (intptr_t)func_00155280()))->cells[0][x].occupied == 2) {
                        color = iGpffff9fd8;
                        func_0014def0(D_007966D0, panels + x * 0x120 + 0x10,
                                      (f32)(x * 0x12), (f32)ty, 0.0f, 18.0f, 18.0f,
                                      (u8 *)&color, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
                    }
                }
            }
        }
        if (D_008C0240[0].trigger & 0x20) {
            *(s32 *)state = 0;
        }
        break;
    }
    return 0;
}
// FUN_0018EF20
void func_0018ef20(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0018EF50
void func_0018ef50(s32 arg0)
{
    func_0044ea90(&D_005F57B0, 0x101);
    (s32)func_00451fc0((void *)((u8 *)arg0), (const void *)(&D_005F57C0), 0xF, 0, 0, func_0018e810, func_0018ef20, (u8 *)(D_008873F4[0](1, 0x1B440, 0x40000)));
}
#pragma opt_propagation off
// FUN_0018EFE0
s32 func_0018efe0(u8 *arg0)
{
    u8 packet[0x20];
    u8 *temp_16;
    s32 temp_17;

    temp_16 = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)temp_16) {
    case 0:
        *(KwlnTask **)(temp_16 + 4) = func_00470250((KwlnTask *)arg0, 0xDC, 0xA0);
        func_00470810(*(KwlnTask **)(temp_16 + 4), D_005F5830, 0xB);
        temp_17 = iGpffffb268 != 0;
        *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 5) = temp_17 ^ 1;
        *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 0) = iGpffffb3a0;
        *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 1) = iGpffffb39c;
        *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 2) = iGpffffb398;
        *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 3) = iGpffffb394;
        *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 4) = iGpffffb390;
        *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 6) = iGpffffb250;
        func_00470430(*(u8 **)(temp_16 + 4), 0x14);
        func_004703c0(*(u8 **)(temp_16 + 4), 4);
        func_004703d0(*(u8 **)(temp_16 + 4), 1);
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        iGpffffb268 = *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 5) != 1;
        iGpffffb250 = *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 6);
        if (D_008C024E[0] & 0x40) {
            if (*func_00470bd0(*(KwlnTask **)(temp_16 + 4), 8) == -1) {
                *(u16 *)(packet + 0) =
                    (u16)*func_00470bd0(*(KwlnTask **)(temp_16 + 4), 0);
                *(u16 *)(packet + 2) =
                    (u16)*func_00470bd0(*(KwlnTask **)(temp_16 + 4), 1);
                *(u16 *)(packet + 4) =
                    (u16)*func_00470bd0(*(KwlnTask **)(temp_16 + 4), 2);
                *(s16 *)(packet + 6) =
                    (s16)*func_00470bd0(*(KwlnTask **)(temp_16 + 4), 3);
                *(s16 *)(packet + 8) =
                    (s16)*func_00470bd0(*(KwlnTask **)(temp_16 + 4), 4);
                iGpffffb3a0 = *(u16 *)(packet + 0);
                iGpffffb39c = *(u16 *)(packet + 2);
                iGpffffb398 = *(u16 *)(packet + 4);
                iGpffffb394 = *(s16 *)(packet + 6);
                iGpffffb390 = *(s16 *)(packet + 8);
                func_001029a0(9, packet, 0x1C, 0);
                func_004703d0(*(u8 **)(temp_16 + 4), 0);
                *(s32 *)temp_16 = 2;
            } else {
                *(s32 *)(packet + 0xC) =
                    *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 8);
                *(s32 *)(packet + 0x10) =
                    *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 9);
                *(s32 *)(packet + 0x14) =
                    *func_00470bd0(*(KwlnTask **)(temp_16 + 4), 0xA);
                func_001029a0(0xA, packet, 0x1C, 0);
                func_004703d0(*(u8 **)(temp_16 + 4), 0);
                *(s32 *)temp_16 = 2;
            }
        } else if (D_008C024E[0] & 0x20) {
            *(s32 *)temp_16 = 3;
        }
        break;
    case 2:
        if (func_00102980() == 0) {
            iGpffffb3a4 = 0;
            func_004703d0(*(u8 **)(temp_16 + 4), 1);
            *(s32 *)temp_16 = 1;
        }
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}
#pragma opt_propagation on
// FUN_0018F390
void func_0018f390(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// measured: probe propagation-off code shape with typed 16-bit operands
#pragma opt_propagation off
// FUN_0018F7B0
void func_0018f7b0(u8 *arg0, s16 *arg1, u16 arg2, u16 arg3, s16 arg4)
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
// FUN_0018F8A0
void func_0018f8a0(u8 *arg0, u16 arg1, u16 arg2)
{
    s32 var_9;
    s32 var_8;
    u8 *temp_5;
    u8 *temp_6;
    u8 *temp_7;
    u8 *field;

    temp_7 = (u8 *)code1_0018_add2(
        code1_0018_shift4(arg1 & 0xFFFF),
        ((arg2 & 0xFFFF) << 8) + (s32)arg0);
    if (temp_7[0x2C] != 0 && (temp_7[0x2D] & 0xF) != 0) {
        var_9 = 0;
        while (var_9 < (s32)temp_7[0x33]) {
            var_8 = 0;
            temp_6 = temp_7 + (var_9 << 8);
            while (var_8 < (s32)temp_7[0x32]) {
                temp_5 = temp_6 + var_8 * 0x10;
                field = temp_5 + 0x2C;
                if (*field != 0) {
                    *field = 0;
                    temp_5[0x2D] = 0;
                }
                var_8 += 1;
            }
            var_9 += 1;
        }
    }
}
extern u16 D_008C0252[];
extern u16 D_008C0298[];
extern const KWindowEntryDescriptor D_005F5FD0[];
extern void func_00457140(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
extern s32 func_00470970(u8 *arg0, u8 *arg1);
extern void sprintf(void *dst, const char *fmt, ...);
extern u8 *func_0015c640(s32 arg0, s32 arg1);
extern s32 func_0015c6f0(u8 *arg0);
extern void func_0015c730(u8 *arg0);
extern s32 func_0015c630(u8 *arg0);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void func_00156800(void *arg0, u32 mask);
typedef struct {
    s16 data[0x2B];
} FieldPanelShape;
// FUN_0018F950
s32 func_0018f950(u8 *arg0)
{
    extern PadStatus D_008C0240[2];
    extern FieldPanelShape D_005F5AC0[];
    static PanelColor board_color = {0x40, 0x40, 0x40, 0xFF};
    static PanelColor icon_color = {0x40, 0x40, 0x40, 0xFF};
    u8 *work;
    u8 *image;
    s32 value;
    u8 text[0x48];
    FieldPanelShape shape;
    PanelColor icon;
    PanelColor board;

    work = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)work) {
    case 0:
        func_00457140(0, 0x52, 0x76, 0xFF);
        *(s32 *)(work + 0x1D00) = 1;
        *(s32 *)work += 1;
        break;
    case 1:
        *(KwlnTask **)(work + 0x1CD10) = func_00470250((KwlnTask *)arg0, 0xDC, 0xC8);
        func_00470810(*(KwlnTask **)(work + 0x1CD10), D_005F5FD0, 2);
        func_004703d0(*(u8 **)(work + 0x1CD10), 1);
        *(s32 *)work += 1;
        break;
    case 2:
        if (D_008C0240[0].trigger & 0x40) {
            *(s16 *)(work + 0x28) = *func_00470bd0(*(KwlnTask **)(work + 0x1CD10), 0);
            *(s16 *)(work + 0x2A) = *func_00470bd0(*(KwlnTask **)(work + 0x1CD10), 1);
            func_00452080(*(KwlnTask **)(work + 0x1CD10));
            *(u8 **)(work + 0x1CD14) = func_0015c640(*(u16 *)(work + 0x28), *(u16 *)(work + 0x2A));
            *(s32 *)(work + 0x1CD10) = func_00470280(arg0, 0x22E, 0x28, 2);
            sprintf(text, "%d-%d", *(u16 *)(work + 0x28), *(u16 *)(work + 0x2A));
            func_004703c0(*(u8 **)(work + 0x1CD10), 1);
            func_00470970(*(u8 **)(work + 0x1CD10), text);
            func_004703d0(*(u8 **)(work + 0x1CD10), 1);
            *(s32 *)work += 1;
        }
        break;
    case 3:
        if (func_0015c6f0(*(u8 **)(work + 0x1CD14)) != 0) {
            image = *(u8 **)(work + 0x1CD14);
            if (image != NULL) {
                memcpy(work + 0x2C, *(u8 **)(image + 0x110) + 4, *(s32 *)(image + 0x118) - 4);
                func_0015c730(*(u8 **)(work + 0x1CD14));
                *(u8 **)(work + 0x1CD14) = NULL;
            }
            *(s32 *)work += 1;
        }
        break;
    case 4:
        if (D_008C0240[0].repeat & 0x1000) {
            if (*(s32 *)(work + 0x1AB4) > 0) {
                *(s32 *)(work + 0x1AB4) -= 1;
            }
        } else if (D_008C0240[0].repeat & 0x4000) {
            if (*(s32 *)(work + 0x1AB4) < 0x17) {
                *(s32 *)(work + 0x1AB4) += 1;
            }
        }
        if (D_008C0240[0].repeat & 0x8000) {
            if (*(s32 *)(work + 0x1AB0) > 0) {
                *(s32 *)(work + 0x1AB0) -= 1;
            }
        } else if (D_008C0240[0].repeat & 0x2000) {
            if (*(s32 *)(work + 0x1AB0) < 0xF) {
                *(s32 *)(work + 0x1AB0) += 1;
            }
        }
        if (D_008C0240[0].repeat & 1) {
            value = *(s32 *)(work + 0x1D00) - 1;
            *(s32 *)(work + 0x1D00) = value;
            if (value <= 0) {
                *(s32 *)(work + 0x1D00) = 0xE;
            }
        } else if (D_008C0240[0].repeat & 2) {
            value = *(s32 *)(work + 0x1D00) + 1;
            *(s32 *)(work + 0x1D00) = value;
            if (value > 0xE) {
                *(s32 *)(work + 0x1D00) = 1;
            }
        }
        if (D_008C0240[0].repeat & 8) {
            value = *(s32 *)(work + 0x1AB8) - 1;
            *(s32 *)(work + 0x1AB8) = value;
            if (value < 0) {
                *(s32 *)(work + 0x1AB8) = 3;
            }
        } else if (D_008C0240[0].repeat & 4) {
            value = *(s32 *)(work + 0x1AB8) + 1;
            *(s32 *)(work + 0x1AB8) = value;
            if (value > 3) {
                *(s32 *)(work + 0x1AB8) = 0;
            }
        }
        if (D_008C0240[0].trigger & 0x40) {
            shape = D_005F5AC0[*(s32 *)(work + 0x1D00)];
            func_00156800(&shape, 1 << *(s32 *)(work + 0x1AB8));
            func_0018f7b0(work, shape.data, *(s32 *)(work + 0x1AB0), *(s32 *)(work + 0x1AB4),
                          *(s32 *)(work + 0x1AB8));
        } else if (D_008C0240[0].trigger & 0x20) {
            func_0018f8a0(work, *(s32 *)(work + 0x1AB0), *(s32 *)(work + 0x1AB4));
        } else if (D_008C0240[1].trigger & 0x40) {
            func_0015c630(work + 0x28);
        }
        board = board_color;
        func_0014def0(D_007966D0, work + 0x1870, 80.0f, 6.0f, 0.0f, 288.0f, 432.0f,
                      (u8 *)&board, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
        icon = icon_color;
        func_0014def0(D_007966D0, work + 0x1BE0, 452.0f, 52.0f, 0.0f, 70.0f, 70.0f,
                      (u8 *)&icon, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
        func_0017d240(D_007966D0, work + 0x1AC0, *(s32 *)(work + 0x1D00), 0, 0x36, 0x36,
                      *(s32 *)(work + 0x1AB8), 460.0f, 60.0f, 0.0f);
        {
            s32 y;

            for (y = 0; y < 0x18; y++) {
                s32 x = 0;
                u8 *cells = work + (y << 8);
                f32 fy = 6.0f + (f32)(y * 0x12);
                u8 *panels = work + y * 0x1200;

                for (; x < 0x10; x++) {
                    u8 *cell = cells + x * 0x10;

                    if (cell[0x2C] != 0 && (cell[0x2D] & 0xF) == 1) {
                        func_0017d1f0(D_007966D0, panels + x * 0x120 + 0x1D10, cell[0x30], 0,
                                      80.0f + (f32)(x * 0x12), fy, 0.0f, cell[0x31]);
                    }
                }
            }
        }
        func_0017d1f0(D_007966D0, work + 0x1990, *(s32 *)(work + 0x1D00), 0,
                      80.0f + 18.0f * (f32)*(s32 *)(work + 0x1AB0),
                      6.0f + 18.0f * (f32)*(s32 *)(work + 0x1AB4), 0.0f, *(s32 *)(work + 0x1AB8));
        break;
    case 5:
        return -1;
    }
    return 0;
}
