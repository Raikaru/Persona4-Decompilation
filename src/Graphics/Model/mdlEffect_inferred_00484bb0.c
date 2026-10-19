#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

extern void mdlEffectSetChildPositions(u8 *arg0, f32 *arg1);
extern void mdlEffectSetChildScales(u8 *arg0, f32 arg1);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern void func_00485630(u8 *arg0);
extern void func_00485870(u8 *arg0);
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern void *memset(void *dst, s32 value, u32 size);
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00484bb0-00485870 */

extern u_long128 mdlEffectInitParticleState(u8 *arg0);
extern void mdlEffectSetChildPositions(u8 *arg0, f32 *arg1);
extern void mdlEffectSetChildRotations(u8 *arg0, u8 *arg1);
extern void mdlEffectSetChildScales(u8 *arg0, f32 arg1);
extern void mdlEffectApplyPackedColor(u8 *arg0, s32 arg1);
extern u8 *func_00486780(u8 *arg0, s32 arg1);
extern s32 func_004867e0(u8 *arg0, u8 *arg1);
extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
typedef struct Code48InitialState {
    f32 vector00[4];
    f32 vector10[4];
    u_long128 quad20;
    u8 unknown30[0x10];
    f32 vector40[4];
    f32 vector50[4];
    f32 scalar60;
    u32 word64;
    u32 word68;
    u32 unknown6c;
    u32 unknown70;
    f32 scalar74;
    u32 unknown78[2];
} Code48InitialState;
/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-out; the current C callers discard it. The four hardware vf0 stores
 * produce (0,0,0,1), not a zero quadword. */
#pragma push
#pragma pop
/* The input and allocated result have separate construction lifetimes.
 * Both initial vectors use the first input quad, as in retail. */
// FUN_00484BB0
#pragma push
/* measured: func_00484bb0 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* measured: func_00484bb0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
u8 *mdlEffectBuildFromResource(u8 *arg0)
{
    extern void mdlEffectSetChildPositions(u8 *arg0, f32 *arg1);
    extern void mdlEffectSetChildRotations(u8 *arg0, u8 *arg1);
    extern void mdlEffectSetChildScales(u8 *arg0, f32 arg1);
    extern void mdlEffectApplyPackedColor(u8 *arg0, s32 arg1);
    extern char *strcpy(char *destination, const char *source);
    s32 func_004867e0(u8 *arg0, u8 *arg1);
    u8 *func_00486780(u8 *arg0, s32 arg1);
    u_long128 vf0quad;
    void *(**alloc)(u32, u32);
    u8 *node;
    u8 *nodeClone;
    u8 *prim;
    u16 kind;
    u8 *found;
    s32 idx;
    u8 *csrc;
    s32 count;
    u8 *base;
    u8 *cur;
    s32 i;
    u8 *slot;
    u8 *target;
    u8 *addr20;
    u8 *addr24;
    s32 idx94;
    u8 *var2;
    s32 tmp;
    u8 *const input = arg0;

    chkmemAllocSiteTag(D_00713470, 0x546);
    alloc = jtbl_008873E8;
    {
        u8 *const clone = (u8 *)alloc[0](0x90, 0x40000);
        if (clone == NULL) {
            kAssertFail(D_00713470, 0x547);
        }
        memset(clone, 0, 0x90);
        *(s32 *)(clone + 0x80) = 0;
        *(s32 *)(clone + 0x84) = 0;
        mdlEffectInitParticleState(clone);
        /* Retail initializes both vectors from the first input quad. */
        *(u_long128 *)clone = *(u_long128 *)input;
        *(u_long128 *)(clone + 0x10) = *(u_long128 *)input;
        *(f32 *)(clone + 0x74) = *(f32 *)(input + 0x74);
        *(s32 *)(clone + 0x68) = *(s32 *)(input + 0x68);
        if (*(u8 **)(input + 0x8C) != NULL) {
            u8 *linkedSource;
            for (node = *(u8 **)(input + 0x8C); node != NULL; node = *(u8 **)(node + 0xAC)) {
                chkmemAllocSiteTag(D_00713470, 0x559);
                nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
                if (nodeClone == NULL) {
                    kAssertFail(D_00713470, 0x55A);
                }
                memset(nodeClone, 0, 0xC0);
                memset(nodeClone, 0, 0x90);
                *(s32 *)(nodeClone + 0x84) = 1;
                *(u8 *)(nodeClone + 0x88) = 8;
                *(u8 *)(nodeClone + 0x89) = 0;
                *(u8 *)(nodeClone + 0x8A) = 0;
                mdlEffectInitParticleState(nodeClone);
                if ((*(s32 *)(node + 0x98) & 1) == 0) {
                    linkedSource = *(u8 **)(node + 0x90);
                    if (*(u32 *)linkedSource > 0xD2) {
                        kAssertFail(D_00713470, 0x2D7);
                    }
                    kind = *(u16 *)(linkedSource + 4);
                    chkmemAllocSiteTag(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        kAssertFail(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    *(u16 *)(prim + 4) = kind;
                    *(u16 *)(prim + 0xC) = *(u16 *)(linkedSource + 0xC);
                    *(u16 *)(prim + 0x1C) = *(u16 *)(linkedSource + 0x1C);
                    if (*(u16 *)(prim + 4) >= 0x21U) {
                        kAssertFail(D_00713470, 0x2DD);
                    }
                    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == NULL) {
                        kAssertFail(D_00713470, 0x2DE);
                    }
                    *(void **)(prim + 8) =
                        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)))(linkedSource);
                    *(u8 **)(nodeClone + 0x90) = prim;
                } else {
                    found = mdlEffectFindNodeById(input, *(s32 *)(node + 0x90));
                    idx = func_004867e0(input, found);
                    csrc = *(u8 **)(func_00486780(clone, idx) + 0x90);
                    if (*(u32 *)csrc > 0xD2) {
                        kAssertFail(D_00713470, 0x318);
                    }
                    kind = *(u16 *)(csrc + 4);
                    chkmemAllocSiteTag(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        kAssertFail(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    *(u16 *)(prim + 4) = kind;
                    *(u16 *)(prim + 0xC) = *(u16 *)(csrc + 0xC);
                    *(u16 *)(prim + 0x1C) = *(u16 *)(csrc + 0x1C);
                    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == NULL) {
                        kAssertFail(D_00713470, 0x321);
                    }
                    *(void **)(prim + 8) =
                        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(void **)(csrc + 8));
                    *(u8 **)(nodeClone + 0x90) = prim;
                }
                mdlEffectCopyRecord(nodeClone, node);
                strcpy((char *)nodeClone + 0x9C, (const char *)node + 0x9C);
                *(s32 *)(nodeClone + 0xAC) = 0;
                if (*(u8 **)(clone + 0x88) != NULL) {
                    *(u8 **)(*(u8 **)(clone + 0x88) + 0xAC) = nodeClone;
                    *(u8 **)(nodeClone + 0xB0) = *(u8 **)(clone + 0x88);
                } else {
                    *(u8 **)(clone + 0x8C) = nodeClone;
                    *(u8 **)(nodeClone + 0xB0) = NULL;
                }
                *(u8 **)(clone + 0x88) = nodeClone;
                *(s32 *)(clone + 0x80) += 1;
            }
        } else {
            u8 *indexedSource;
            count = *(s32 *)(input + 0x80);
            base = input + *(s32 *)(input + 0x88);
            cur = base;
            i = 0;
            goto indexed_check;
    indexed_body:
            chkmemAllocSiteTag(D_00713470, 0x559);
            nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
            if (nodeClone == NULL) {
                kAssertFail(D_00713470, 0x55A);
            }
            memset(nodeClone, 0, 0xC0);
            memset(nodeClone, 0, 0x90);
            *(s32 *)(nodeClone + 0x84) = 1;
            *(u8 *)(nodeClone + 0x88) = 8;
            *(u8 *)(nodeClone + 0x89) = 0;
            *(u8 *)(nodeClone + 0x8A) = 0;
            mdlEffectInitParticleState(nodeClone);
            tmp = *(s32 *)(cur + 0x98);
            if ((tmp & 1) == 0) {
                indexedSource = input + *(s32 *)(cur + 0x90);
                if ((tmp & 2) != 0) {
                    addr24 = indexedSource + 0x24;
                    if (*(s32 *)addr24 != 0) {
                        kAssertFail(D_00713470, 0x5BB);
                    }
                    addr20 = indexedSource + 0x20;
                    if (*(s32 *)addr20 != 0) {
                        kAssertFail(D_00713470, 0x5BC);
                    }
                    idx94 = *(s32 *)(cur + 0x94);
                    slot = base + idx94 * 0xC0;
                    target = input + *(s32 *)(slot + 0x90);
                    if (*(s32 *)(target + 0x24) == 0) {
                        kAssertFail(D_00713470, 0x5BE);
                    }
                    *(s32 *)addr24 = *(s32 *)(target + 0x24);
                    if (*(s32 *)(target + 0x28) != 0) {
                        var2 = *(u8 **)(target + 0x20);
                    } else if (*(s32 *)(target + 0x20) != 0) {
                        var2 = target + *(s32 *)(target + 0x20);
                    } else {
                        var2 = NULL;
                    }
                    *(u32 *)addr20 = (u32)var2 - (u32)indexedSource;
                    if (*(u32 *)indexedSource > 0xD2) {
                        kAssertFail(D_00713470, 0x2D7);
                    }
                    kind = *(u16 *)(indexedSource + 4);
                    chkmemAllocSiteTag(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        kAssertFail(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    *(u16 *)(prim + 4) = kind;
                    *(u16 *)(prim + 0xC) = *(u16 *)(indexedSource + 0xC);
                    *(u16 *)(prim + 0x1C) = *(u16 *)(indexedSource + 0x1C);
                    if (*(u16 *)(prim + 4) >= 0x21U) {
                        kAssertFail(D_00713470, 0x2DD);
                    }
                    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == NULL) {
                        kAssertFail(D_00713470, 0x2DE);
                    }
                    *(void **)(prim + 8) =
                        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)))(indexedSource);
                    *(u8 **)(nodeClone + 0x90) = prim;
                    *(s32 *)addr24 = 0;
                    *(s32 *)addr20 = 0;
                } else {
                    if (*(u32 *)indexedSource > 0xD2) {
                        kAssertFail(D_00713470, 0x2D7);
                    }
                    kind = *(u16 *)(indexedSource + 4);
                    chkmemAllocSiteTag(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        kAssertFail(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    *(u16 *)(prim + 4) = kind;
                    *(u16 *)(prim + 0xC) = *(u16 *)(indexedSource + 0xC);
                    *(u16 *)(prim + 0x1C) = *(u16 *)(indexedSource + 0x1C);
                    if (*(u16 *)(prim + 4) >= 0x21U) {
                        kAssertFail(D_00713470, 0x2DD);
                    }
                    if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)) == NULL) {
                        kAssertFail(D_00713470, 0x2DE);
                    }
                    *(void **)(prim + 8) =
                        (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6)))(indexedSource);
                    *(u8 **)(nodeClone + 0x90) = prim;
                }
            } else {
                csrc = *(u8 **)(func_00486780(clone, *(s32 *)(cur + 0x90)) + 0x90);
                if (*(u32 *)csrc > 0xD2) {
                    kAssertFail(D_00713470, 0x318);
                }
                kind = *(u16 *)(csrc + 4);
                chkmemAllocSiteTag(D_00713470, 0x21);
                prim = (u8 *)alloc[0](0x2C, 0x40000);
                if (prim == NULL) {
                    kAssertFail(D_00713470, 0x22);
                }
                memset(prim, 0, 0x2C);
                *(s32 *)prim = 0xD2;
                *(u16 *)(prim + 4) = kind;
                *(u16 *)(prim + 0xC) = *(u16 *)(csrc + 0xC);
                *(u16 *)(prim + 0x1C) = *(u16 *)(csrc + 0x1C);
                if (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14) == NULL) {
                    kAssertFail(D_00713470, 0x321);
                }
                *(void **)(prim + 8) =
                    (*(EffectInstanceConstructor *)(D_00713480 + (*(u16 *)(prim + 4) << 6) + 0x14))(*(void **)(csrc + 8));
                *(u8 **)(nodeClone + 0x90) = prim;
            }
            mdlEffectCopyRecord(nodeClone, cur);
            strcpy((char *)nodeClone + 0x9C, (const char *)cur + 0x9C);
            *(s32 *)(nodeClone + 0xAC) = 0;
            if (*(u8 **)(clone + 0x88) != NULL) {
                *(u8 **)(*(u8 **)(clone + 0x88) + 0xAC) = nodeClone;
                *(u8 **)(nodeClone + 0xB0) = *(u8 **)(clone + 0x88);
            } else {
                *(u8 **)(clone + 0x8C) = nodeClone;
                *(u8 **)(nodeClone + 0xB0) = NULL;
            }
            *(u8 **)(clone + 0x88) = nodeClone;
            *(s32 *)(clone + 0x80) += 1;
            cur += 0xC0;
            i += 1;
    indexed_check:
            if (i < count) {
                goto indexed_body;
            }
        }
        /* VU0's fixed vector is (0, 0, 0, 1). */
        __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(&vf0quad) : "memory");
        mdlEffectSetChildPositions(clone, (f32 *)&vf0quad);
        mdlEffectSetChildRotations(clone, (u8 *)&vf0quad);
        mdlEffectSetChildScales(clone, 1.0f);
        mdlEffectApplyPackedColor(clone, -1);
        return clone;
    }
}

#pragma pop
/* The saved-rotation restore is written as an lq/sq that names $2, as
 * retail does at 0x0048569C: b210 keeps $v0 live from every call to the end
 * of an int or void function, so no C copy can use it there (measured on
 * plain, struct, union and inline-helper copies, `return;`, a K&R
 * definition and discarded-result calls; all give $v1). Allowed by the
 * user on 2026-10-09 after no other match was found. */
#pragma push
/* measured: func_00485630 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00485630
void func_00485630(u8 *arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void mdlEffectSetChildRotations(u8 *arg0, u8 *arg1);
    /* 00484b30 initializes the 0x80-byte state; 00484bb0 allocates a
     * 0x90-byte root. The union keeps field and quadword transfers in the
     * same object, including all four components of the saved rotation. */
    typedef union SceneStateStorage {
        Code48InitialState fields;
        u_long128 quad[8];
    } SceneStateStorage;
    typedef struct SceneRoot {
        SceneStateStorage state;
        s32 childCount;
        u32 frame; /* Wrapping storage, read as signed for selection. */
        u8 *lastChild;
        u8 *firstChild;
    } SceneRoot;
    typedef char SceneRootExtent[sizeof(SceneRoot) == 0x90 ? 1 : -1];
    SceneRoot *root;
    /* The saved parent rotation survives both propagation calls. */
    struct {
        u_long128 savedRotation;
        u_long128 rotation;
        u_long128 position;
        u_long128 origin;
    } work;
    f32 scale;
    f32 five;
    u8 *child;
    s32 count;
    u8 *primitive;
    void (*positionCallback)(s32, void *);
    void (*rotationCallback)(s32, void *);
    s32 childFlags;

    root = (SceneRoot *)(void *)arg0;
    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(arg0), "m"(root->state.quad[4]) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0), "m"(root->state.quad[0]) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.origin) : "r"(&work.origin) : "memory");
    if ((root->state.fields.word68 & 0x60) != 0) {
        u_long128 *save_slot;
        u_long128 *restore_slot;
        save_slot = &work.savedRotation;
        *save_slot = root->state.quad[5];
        func_00486970(arg0, (u8 *)&work.origin, &work.rotation);
        mdlEffectSetChildRotations(arg0, (u8 *)&work.rotation);
        restore_slot = &work.savedRotation;
        /* lint: allow H009 -- retail copies this quad through $2 at 0x0048569C; b210 keeps $v0 live after calls (user-approved 2026-10-09) */
        __asm__ volatile("lq $2, 0(%0)\n\tsq $2, 0x50(%1)" : : "r"(restore_slot), "r"(root) : "$2", "memory");
    }
    count = (s32)root->frame;
    scale = root->state.fields.scalar60 * root->state.fields.scalar74;
    child = root->firstChild;
    five = 5.0f;
    for (; child != NULL; child = *(u8 **)(child + 0xAC)) {
        if (count < *(s32 *)(child + 0x80)) {
            continue;
        }
        if ((*(s32 *)(child + 0x84) & 2) != 0) {
            continue;
        }
        if ((*(s32 *)(child + 0x68) & 0x18) != 0) {
            func_00486840(child, (u8 *)&work.origin, &work.position);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&work.origin), "m"(work.origin) : "$vf10", "memory");
            childFlags = *(s32 *)(child + 0x68);
            if ((childFlags & 4) != 0) {
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2 \n"
                    "vaddx.y $vf10, $vf0, $vf2x \n"
                    :
                    : "r"(five)
                    : "$vf2", "$vf10", "memory");
            }
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&work.position), "m"(work.position) : "$vf11", "memory");
            if ((childFlags & 0x80) != 0) {
                __asm__ volatile(
                    "qmtc2.ni %0, $vf2 \n"
                    "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                    :
                    : "r"(scale)
                    : "$vf2", "$vf11", "memory");
            }
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.position) : "r"(&work.position) : "memory");
            primitive = *(u8 **)(child + 0x90);
            positionCallback = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x20);
            if (positionCallback != NULL) {
                positionCallback(*(s32 *)(primitive + 8), &work.position);
            }
        }
        if ((*(s32 *)(child + 0x68) & 0x60) != 0) {
            func_00486970(child, (u8 *)&work.origin, &work.rotation);
            primitive = *(u8 **)(child + 0x90);
            rotationCallback = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x24);
            if (rotationCallback != NULL) {
                rotationCallback(*(s32 *)(primitive + 8), &work.rotation);
            }
        }
        primitive = *(u8 **)(child + 0x90);
        (*(void (**)(s32))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x08))(*(s32 *)(primitive + 8));
    }
    root->state.fields.word68 |= 0x80000000;
    /* Retail ADDIU wraps the word even when its signed view reaches INT_MAX. */
    root->frame += 1U;
}

#pragma pop
/* As in func_00485630, the saved-rotation restore at 0x00485900 is an
 * lq/sq that names $2; no C copy can use $v0 after the propagation calls. */
#pragma push
/* measured: func_00485870 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00485870
void func_00485870(u8 *arg0)
{
    extern u_long128 func_00486840(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern u_long128 func_00486970(u8 *arg0, u8 *arg1, u_long128 *arg2);
    extern void mdlEffectSetChildRotations(u8 *arg0, u8 *arg1);
    /* 00484b30 initializes the 0x80-byte state; 00484bb0 allocates a
     * 0x90-byte root. The union keeps field and quadword transfers in the
     * same object, including all four components of the saved rotation. */
    typedef union SceneStateStorage {
        Code48InitialState fields;
        u_long128 quad[8];
    } SceneStateStorage;
    typedef struct SceneRoot {
        SceneStateStorage state;
        s32 childCount;
        u32 frame; /* Wrapping storage, read as signed for selection. */
        u8 *lastChild;
        u8 *firstChild;
    } SceneRoot;
    typedef char SceneRootExtent[sizeof(SceneRoot) == 0x90 ? 1 : -1];
    SceneRoot *root;
    /* The saved parent rotation survives both propagation calls. */
    struct {
        u_long128 savedRotation;
        u_long128 rotation;
        u_long128 position;
        u_long128 origin;
    } work;
    f32 scale;
    f32 five;
    u8 *child;
    s32 flags;
    s32 count_minus_1;
    u8 *primitive;
    void (*positionCallback)(s32, void *);
    void (*rotationCallback)(s32, void *);
    s32 childFlags;
    u32 mask;

    root = (SceneRoot *)(void *)arg0;
    if ((s32)root->frame <= 0) {
        return;
    }
    flags = root->state.fields.word68;
    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(arg0), "m"(root->state.quad[4]) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(arg0), "m"(root->state.quad[0]) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.origin) : "r"(&work.origin) : "memory");
    if ((flags & 0x60) != 0) {
        if ((flags & 0x80000000) == 0) {
            u_long128 *save_slot;
            u_long128 *restore_slot;
            save_slot = &work.savedRotation;
            *save_slot = root->state.quad[5];
            func_00486970(arg0, (u8 *)&work.origin, &work.rotation);
            mdlEffectSetChildRotations(arg0, (u8 *)&work.rotation);
            restore_slot = &work.savedRotation;
            /* lint: allow H009 -- retail copies this quad through $2 at 0x00485900; b210 keeps $v0 live after calls (user-approved 2026-10-09) */
            __asm__ volatile("lq $2, 0(%0)\n\tsq $2, 0x50(%1)" : : "r"(restore_slot), "r"(root) : "$2", "memory");
        }
    }
    /* Reload after propagation, then subtract in the word's wrapping domain. */
    count_minus_1 = (s32)(root->frame - 1U);
    scale = root->state.fields.scalar60 * root->state.fields.scalar74;
    child = root->firstChild;
    mask = 0x80000000;
    five = 5.0f;
    for (; child != NULL; child = *(u8 **)(child + 0xAC)) {
        if (count_minus_1 < *(s32 *)(child + 0x80)) {
            continue;
        }
        if ((*(s32 *)(child + 0x84) & 2) != 0) {
            continue;
        }
        if ((flags & mask) == 0) {
            if ((*(s32 *)(child + 0x68) & 0x18) != 0) {
                func_00486840(child, (u8 *)&work.origin, &work.position);
                __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&work.origin), "m"(work.origin) : "$vf10", "memory");
                childFlags = *(s32 *)(child + 0x68);
                if ((childFlags & 4) != 0) {
                    __asm__ volatile(
                        "qmtc2.ni %0, $vf2 \n"
                        "vaddx.y $vf10, $vf0, $vf2x \n"
                        :
                        : "r"(five)
                        : "$vf2", "$vf10", "memory");
                }
                __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&work.position), "m"(work.position) : "$vf11", "memory");
                if ((childFlags & 0x80) != 0) {
                    __asm__ volatile(
                        "qmtc2.ni %0, $vf2 \n"
                        "vmulx.xyzw $vf11, $vf11, $vf2x \n"
                        :
                        : "r"(scale)
                        : "$vf2", "$vf11", "memory");
                }
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.position) : "r"(&work.position) : "memory");
                primitive = *(u8 **)(child + 0x90);
                positionCallback = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x20);
                if (positionCallback != NULL) {
                    positionCallback(*(s32 *)(primitive + 8), &work.position);
                }
            }
            if ((*(s32 *)(child + 0x68) & 0x60) != 0) {
                func_00486970(child, (u8 *)&work.origin, &work.rotation);
                primitive = *(u8 **)(child + 0x90);
                rotationCallback = *(void (**)(s32, void *))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x24);
                if (rotationCallback != NULL) {
                    rotationCallback(*(s32 *)(primitive + 8), &work.rotation);
                }
            }
        }
        primitive = *(u8 **)(child + 0x90);
        (*(void (**)(s32))(D_00713480 + (*(u16 *)(primitive + 4) << 6) + 0x0C))(*(s32 *)(primitive + 8));
    }
    root->state.fields.word68 &= 0x7fffffffU;
}

