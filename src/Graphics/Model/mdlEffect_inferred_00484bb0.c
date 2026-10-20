#include "member_access.h"
#include "mdl_effect_dispatch_internal.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "mdl_effect_internal.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// Layout from P3FES RenderWare rwplcore.h.
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

extern void mdlEffectSetChildPositions(u8 *effect, f32 *value);
extern void mdlEffectSetChildScales(u8 *effect, f32 value);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern void mdlEffectCommitTreeFrame(u8 *effect);
extern void mdlEffectFlushTreeFrame(u8 *effect);
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

extern u_long128 mdlEffectInitParticleState(u8 *instance);
extern void mdlEffectSetChildPositions(u8 *effect, f32 *value);
extern void mdlEffectSetChildRotations(u8 *effect, u8 *value);
extern void mdlEffectSetChildScales(u8 *effect, f32 value);
extern void mdlEffectApplyPackedColor(u8 *effect, s32 value);
extern u8 *mdlEffectGetChildAtIndex(u8 *effect, s32 target);
extern s32 mdlEffectGetChildIndex(u8 *effect, u8 *target);
extern u_long128 mdlEffectResolveChildOffset(u8 *effect, u8 *target, u_long128 *output);
extern u_long128 mdlEffectResolveChildOrientation(u8 *effect, u8 *target, u_long128 *output);
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
/* measured: retail returns the copied quadword even though callers discard it; the four vf0 stores
 * produce (0,0,0,1), not zero. */
#pragma push
#pragma pop
/* The input and allocated result have separate construction lifetimes.
 * Both initial vectors use the first input quad, as in retail. */
// FUN_00484BB0
#pragma push
/* measured: retail register allocation for this function needs opt_lifetimes enabled; the default
 * allocation differs. */
#pragma opt_lifetimes on
/* measured: retail code generation for this function requires propagation disabled. */
#pragma opt_propagation off
u8 *mdlEffectBuildFromResource(u8 *effect)
{
    MdlEffectTree *cloneTree;

    extern void mdlEffectSetChildPositions(u8 *effect, f32 *value);
    extern void mdlEffectSetChildRotations(u8 *effect, u8 *value);
    extern void mdlEffectSetChildScales(u8 *effect, f32 value);
    extern void mdlEffectApplyPackedColor(u8 *effect, s32 value);
    extern char *strcpy(char *destination, const char *source);
    s32 mdlEffectGetChildIndex(u8 *effect, u8 *target);
    u8 *mdlEffectGetChildAtIndex(u8 *effect, s32 target);
    u_long128 vf0quad;
    void *(**alloc)(u32, u32);
    u8 *node;
    u8 *nodeClone;
    u8 *prim;
    u16 kind;
    u8 *found;
    s32 childIndex;
    u8 *childSource;
    s32 count;
    u8 *base;
    u8 *cur;
    s32 i;
    u8 *slot;
    u8 *target;
    u8 *parameterOffset;
    u8 *parameterCount;
    s32 sourceIndex;
    u8 *secondarySource;
    s32 nodeFlags;
    u8 *const input = effect;

    chkmemAllocSiteTag(D_00713470, 0x546);
    alloc = jtbl_008873E8;
    {
        u8 *const clone = (u8 *)alloc[0](0x90, 0x40000);
        if (clone == NULL) {
            kAssertFail(D_00713470, 0x547);
        }
        memset(clone, 0, 0x90);
        (cloneTree = (MdlEffectTree *)clone)->childCount = 0;
        *(s32 *)&((MdlEffectTree *)clone)->frame = 0;
        mdlEffectInitParticleState(clone);
        /* Retail initializes both vectors from the first input quad. */
        *(u_long128 *)clone = *(u_long128 *)input;
        *(u_long128 *)&((MdlEffectState *)clone)->rotation = *(u_long128 *)input; /* Transfer the complete quadword representation, including the VU W lane. */
        ((MdlEffectState *)clone)->multiplier = ((MdlEffectState *)input)->multiplier;
        ((MdlEffectState *)clone)->flags.signedValue = ((MdlEffectState *)input)->flags.signedValue;
        if (((MdlEffectNode *)input)->children != NULL) {
            u8 *linkedSource;
            for (node = ((MdlEffectNode *)input)->children; node != NULL; node = ((MdlEffectNode *)node)->next) {
                chkmemAllocSiteTag(D_00713470, 0x559);
                nodeClone = (u8 *)alloc[0](0xC0, 0x40000);
                if (nodeClone == NULL) {
                    kAssertFail(D_00713470, 0x55A);
                }
                memset(nodeClone, 0, 0xC0);
                memset(nodeClone, 0, 0x90);
                ((MdlEffectNode *)nodeClone)->flags = 1;
                ((MdlEffectNode *)nodeClone)->attributes[0] = 8;
                ((MdlEffectNode *)nodeClone)->attributes[1] = 0;
                ((MdlEffectNode *)nodeClone)->attributes[2] = 0;
                mdlEffectInitParticleState(nodeClone);
                if ((((MdlEffectNode *)node)->sourceFlags & 1) == 0) {
                    linkedSource = ((MdlEffectNode *)node)->primitive;
                    if (*(u32 *)linkedSource > 0xD2) {
                        kAssertFail(D_00713470, 0x2D7);
                    }
                    kind = ((MdlEffectPrimitiveRecord *)linkedSource)->kind;
                    chkmemAllocSiteTag(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        kAssertFail(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) = kind;
                    ((MdlEffectPrimitiveRecord *)prim)->id = ((MdlEffectPrimitiveRecord *)linkedSource)->id;
                    ((MdlEffectPrimitiveRecord *)prim)->sourceKind = ((MdlEffectPrimitiveRecord *)linkedSource)->sourceKind;
                    if (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) >= 0x21U) {
                        kAssertFail(D_00713470, 0x2DD);
                    }
                    if (((MdlEffectPrimitiveHandlers *)(D_00713480 + (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) << 6)))->create == NULL) {
                        kAssertFail(D_00713470, 0x2DE);
                    }
                    ((MdlEffectPrimitiveRecord *)prim)->instance.pointer =
                        (((MdlEffectPrimitiveHandlers *)(D_00713480 + (((MdlEffectPrimitiveRecord *)prim)->kind << 6)))->create)(linkedSource); /* The 0x40-byte kind table has slot-specific callback signatures. */
                    ((MdlEffectNode *)nodeClone)->primitive = prim;
                } else {
                    found = mdlEffectFindNodeById(input, ((MdlEffectNode *)node)->id);
                    childIndex = mdlEffectGetChildIndex(input, found);
                    childSource = ((MdlEffectNode *)mdlEffectGetChildAtIndex(clone, childIndex))->primitive;
                    if (*(u32 *)childSource > 0xD2) {
                        kAssertFail(D_00713470, 0x318);
                    }
                    kind = ((MdlEffectPrimitiveRecord *)childSource)->kind;
                    chkmemAllocSiteTag(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        kAssertFail(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) = kind;
                    ((MdlEffectPrimitiveRecord *)prim)->id = ((MdlEffectPrimitiveRecord *)childSource)->id;
                    ((MdlEffectPrimitiveRecord *)prim)->sourceKind = ((MdlEffectPrimitiveRecord *)childSource)->sourceKind;
                    if (((MdlEffectPrimitiveHandlers *)(D_00713480 + (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) << 6)))->clone == NULL) {
                        kAssertFail(D_00713470, 0x321);
                    }
                    ((MdlEffectPrimitiveRecord *)prim)->instance.pointer =
                        (((MdlEffectPrimitiveHandlers *)(D_00713480 + (((MdlEffectPrimitiveRecord *)prim)->kind << 6)))->clone)(((MdlEffectPrimitiveRecord *)childSource)->instance.pointer); /* The 0x40-byte kind table has slot-specific callback signatures. */
                    ((MdlEffectNode *)nodeClone)->primitive = prim;
                }
                mdlEffectCopyRecord(nodeClone, node);
                strcpy((char *)nodeClone + 0x9C, (const char *)node + 0x9C);
                *(s32 *)&((MdlEffectNode *)nodeClone)->next = 0;
                if (MEMBER(u8 *, clone, MdlEffectTree, lastChild) != NULL) {
                    ((MdlEffectNode *)((MdlEffectTree *)clone)->lastChild)->next = nodeClone;
                    ((MdlEffectNode *)nodeClone)->previous = ((MdlEffectTree *)clone)->lastChild;
                } else {
                    ((MdlEffectNode *)clone)->children = nodeClone;
                    ((MdlEffectNode *)nodeClone)->previous = NULL;
                }
                ((MdlEffectTree *)clone)->lastChild = nodeClone;
                ((MdlEffectTree *)clone)->childCount += 1;
            }
        } else {
            u8 *indexedSource;
            count = ((MdlEffectTree *)input)->childCount;
            base = input + *(s32 *)&((MdlEffectTree *)input)->lastChild;
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
            ((MdlEffectNode *)nodeClone)->flags = 1;
            ((MdlEffectNode *)nodeClone)->attributes[0] = 8;
            ((MdlEffectNode *)nodeClone)->attributes[1] = 0;
            ((MdlEffectNode *)nodeClone)->attributes[2] = 0;
            mdlEffectInitParticleState(nodeClone);
            nodeFlags = ((MdlEffectNode *)cur)->sourceFlags;
            if ((nodeFlags & 1) == 0) {
                indexedSource = input + ((MdlEffectNode *)cur)->id;
                if ((nodeFlags & 2) != 0) {
                    parameterCount = indexedSource + 0x24;
                    if (*(s32 *)parameterCount != 0) {
                        kAssertFail(D_00713470, 0x5BB);
                    }
                    parameterOffset = indexedSource + 0x20;
                    if (*(s32 *)parameterOffset != 0) {
                        kAssertFail(D_00713470, 0x5BC);
                    }
                    sourceIndex = ((MdlEffectNode *)cur)->sourceIndex;
                    slot = base + sourceIndex * 0xC0;
                    target = input + ((MdlEffectNode *)slot)->id;
                    if (MEMBER(s32, target, MdlEffectSource, secondaryCount) == 0) {
                        kAssertFail(D_00713470, 0x5BE);
                    }
                    *(s32 *)parameterCount = ((MdlEffectSource *)target)->secondaryCount;
                    if (((MdlEffectSource *)target)->secondaryAllocation.handle != 0) {
                        secondarySource = ((MdlEffectSource *)target)->secondaryParameters;
                    } else if (*(s32 *)&((MdlEffectSource *)target)->secondaryParameters != 0) {
                        secondarySource = target + *(s32 *)&((MdlEffectSource *)target)->secondaryParameters;
                    } else {
                        secondarySource = NULL;
                    }
                    *(u32 *)parameterOffset = (u32)secondarySource - (u32)indexedSource;
                    if (*(u32 *)indexedSource > 0xD2) {
                        kAssertFail(D_00713470, 0x2D7);
                    }
                    kind = ((MdlEffectPrimitiveRecord *)indexedSource)->kind;
                    chkmemAllocSiteTag(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        kAssertFail(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) = kind;
                    ((MdlEffectPrimitiveRecord *)prim)->id = ((MdlEffectPrimitiveRecord *)indexedSource)->id;
                    ((MdlEffectPrimitiveRecord *)prim)->sourceKind = ((MdlEffectPrimitiveRecord *)indexedSource)->sourceKind;
                    if (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) >= 0x21U) {
                        kAssertFail(D_00713470, 0x2DD);
                    }
                    if (((MdlEffectPrimitiveHandlers *)(D_00713480 + (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) << 6)))->create == NULL) {
                        kAssertFail(D_00713470, 0x2DE);
                    }
                    ((MdlEffectPrimitiveRecord *)prim)->instance.pointer =
                        (((MdlEffectPrimitiveHandlers *)(D_00713480 + (((MdlEffectPrimitiveRecord *)prim)->kind << 6)))->create)(indexedSource); /* The 0x40-byte kind table has slot-specific callback signatures. */
                    ((MdlEffectNode *)nodeClone)->primitive = prim;
                    *(s32 *)parameterCount = 0;
                    *(s32 *)parameterOffset = 0;
                } else {
                    if (*(u32 *)indexedSource > 0xD2) {
                        kAssertFail(D_00713470, 0x2D7);
                    }
                    kind = ((MdlEffectPrimitiveRecord *)indexedSource)->kind;
                    chkmemAllocSiteTag(D_00713470, 0x21);
                    prim = (u8 *)alloc[0](0x2C, 0x40000);
                    if (prim == NULL) {
                        kAssertFail(D_00713470, 0x22);
                    }
                    memset(prim, 0, 0x2C);
                    *(s32 *)prim = 0xD2;
                    MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) = kind;
                    ((MdlEffectPrimitiveRecord *)prim)->id = ((MdlEffectPrimitiveRecord *)indexedSource)->id;
                    ((MdlEffectPrimitiveRecord *)prim)->sourceKind = ((MdlEffectPrimitiveRecord *)indexedSource)->sourceKind;
                    if (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) >= 0x21U) {
                        kAssertFail(D_00713470, 0x2DD);
                    }
                    if (((MdlEffectPrimitiveHandlers *)(D_00713480 + (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) << 6)))->create == NULL) {
                        kAssertFail(D_00713470, 0x2DE);
                    }
                    ((MdlEffectPrimitiveRecord *)prim)->instance.pointer =
                        (((MdlEffectPrimitiveHandlers *)(D_00713480 + (((MdlEffectPrimitiveRecord *)prim)->kind << 6)))->create)(indexedSource); /* The 0x40-byte kind table has slot-specific callback signatures. */
                    ((MdlEffectNode *)nodeClone)->primitive = prim;
                }
            } else {
                childSource = ((MdlEffectNode *)mdlEffectGetChildAtIndex(clone, ((MdlEffectNode *)cur)->id))->primitive;
                if (*(u32 *)childSource > 0xD2) {
                    kAssertFail(D_00713470, 0x318);
                }
                kind = ((MdlEffectPrimitiveRecord *)childSource)->kind;
                chkmemAllocSiteTag(D_00713470, 0x21);
                prim = (u8 *)alloc[0](0x2C, 0x40000);
                if (prim == NULL) {
                    kAssertFail(D_00713470, 0x22);
                }
                memset(prim, 0, 0x2C);
                *(s32 *)prim = 0xD2;
                MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) = kind;
                ((MdlEffectPrimitiveRecord *)prim)->id = ((MdlEffectPrimitiveRecord *)childSource)->id;
                ((MdlEffectPrimitiveRecord *)prim)->sourceKind = ((MdlEffectPrimitiveRecord *)childSource)->sourceKind;
                if (((MdlEffectPrimitiveHandlers *)(D_00713480 + (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) << 6)))->clone == NULL) {
                    kAssertFail(D_00713470, 0x321);
                }
                ((MdlEffectPrimitiveRecord *)prim)->instance.pointer =
                    (((MdlEffectPrimitiveHandlers *)(D_00713480 + (((MdlEffectPrimitiveRecord *)prim)->kind << 6)))->clone)(((MdlEffectPrimitiveRecord *)childSource)->instance.pointer); /* The 0x40-byte kind table has slot-specific callback signatures. */
                ((MdlEffectNode *)nodeClone)->primitive = prim;
            }
            mdlEffectCopyRecord(nodeClone, cur);
            strcpy((char *)nodeClone + 0x9C, (const char *)cur + 0x9C);
            *(s32 *)&((MdlEffectNode *)nodeClone)->next = 0;
            if (MEMBER(u8 *, clone, MdlEffectTree, lastChild) != NULL) {
                ((MdlEffectNode *)((MdlEffectTree *)clone)->lastChild)->next = nodeClone;
                ((MdlEffectNode *)nodeClone)->previous = ((MdlEffectTree *)clone)->lastChild;
            } else {
                ((MdlEffectNode *)clone)->children = nodeClone;
                ((MdlEffectNode *)nodeClone)->previous = NULL;
            }
            ((MdlEffectTree *)clone)->lastChild = nodeClone;
            ((MdlEffectTree *)clone)->childCount += 1;
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
#pragma push
/* measured: retail does not propagate copied values across this function, so copy propagation is
 * turned off. */
#pragma opt_propagation off
/* Propagate the current tree transform to eligible children, commit each primitive and advance the frame. */
// FUN_00485630
void mdlEffectCommitTreeFrame(u8 *effect)
{
    extern u_long128 mdlEffectResolveChildOffset(u8 *effect, u8 *target, u_long128 *output);
    extern u_long128 mdlEffectResolveChildOrientation(u8 *effect, u8 *target, u_long128 *output);
    extern void mdlEffectSetChildRotations(u8 *effect, u8 *value);
    /* 00484b30 initializes the 0x80-byte state and 00484bb0 allocates a 0x90-byte root; the union
     * allows both field and quadword access. */
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

    root = (SceneRoot *)(void *)effect;
    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(effect), "m"(root->state.quad[4]) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(effect), "m"(root->state.quad[0]) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.origin) : "r"(&work.origin) : "memory");
    if ((root->state.fields.word68 & 0x60) != 0) {
        u_long128 *save_slot;
        u_long128 *restore_slot;
        save_slot = &work.savedRotation;
        *save_slot = root->state.quad[5];
        mdlEffectResolveChildOrientation(effect, (u8 *)&work.origin, &work.rotation);
        mdlEffectSetChildRotations(effect, (u8 *)&work.rotation);
        restore_slot = &work.savedRotation;
        /* lint: allow H009 -- retail copies the saved rotation quad through a fixed register after
         * the calls, which C cannot express. */
        __asm__ volatile("lq $2, 0(%0)\n\tsq $2, 0x50(%1)" : : "r"(restore_slot), "r"(root) : "$2", "memory");
    }
    count = (s32)root->frame;
    scale = root->state.fields.scalar60 * root->state.fields.scalar74;
    child = root->firstChild;
    five = 5.0f;
    for (; child != NULL; child = ((MdlEffectNode *)child)->next) {
        if (count < ((MdlEffectNode *)child)->startFrame) {
            continue;
        }
        if ((((MdlEffectNode *)child)->flags & 2) != 0) {
            continue;
        }
        if ((MEMBER(s32, child, MdlEffectState, flags.signedValue) & 0x18) != 0) {
            mdlEffectResolveChildOffset(child, (u8 *)&work.origin, &work.position);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&work.origin), "m"(work.origin) : "$vf10", "memory");
            childFlags = ((MdlEffectState *)child)->flags.signedValue;
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
            primitive = ((MdlEffectNode *)child)->primitive;
            positionCallback = *(void (**)(s32, void *))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x20);
            if (positionCallback != NULL) {
                positionCallback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, &work.position);
            }
        }
        if ((((MdlEffectState *)child)->flags.signedValue & 0x60) != 0) {
            mdlEffectResolveChildOrientation(child, (u8 *)&work.origin, &work.rotation);
            primitive = ((MdlEffectNode *)child)->primitive;
            rotationCallback = *(void (**)(s32, void *))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x24);
            if (rotationCallback != NULL) {
                rotationCallback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, &work.rotation);
            }
        }
        primitive = ((MdlEffectNode *)child)->primitive;
        (*(void (**)(s32))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x08))(((MdlEffectPrimitiveRecord *)primitive)->instance.handle);
    }
    root->state.fields.word68 |= 0x80000000;
    /* Retail ADDIU wraps the word even when its signed view reaches INT_MAX. */
    root->frame += 1U;
}

#pragma pop
#pragma push
/* measured: retail does not propagate copied values across this function, so copy propagation is
 * turned off. */
#pragma opt_propagation off
/* Flush eligible children for the previous frame, propagating transforms only if not already committed. */
// FUN_00485870
void mdlEffectFlushTreeFrame(u8 *effect)
{
    extern u_long128 mdlEffectResolveChildOffset(u8 *effect, u8 *target, u_long128 *output);
    extern u_long128 mdlEffectResolveChildOrientation(u8 *effect, u8 *target, u_long128 *output);
    extern void mdlEffectSetChildRotations(u8 *effect, u8 *value);
    /* 00484b30 initializes the 0x80-byte state and 00484bb0 allocates a 0x90-byte root; the union
     * allows both field and quadword access. */
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

    root = (SceneRoot *)(void *)effect;
    if ((s32)root->frame <= 0) {
        return;
    }
    flags = root->state.fields.word68;
    __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(effect), "m"(root->state.quad[4]) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(effect), "m"(root->state.quad[0]) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(work.origin) : "r"(&work.origin) : "memory");
    if ((flags & 0x60) != 0) {
        if ((flags & 0x80000000) == 0) {
            u_long128 *save_slot;
            u_long128 *restore_slot;
            save_slot = &work.savedRotation;
            *save_slot = root->state.quad[5];
            mdlEffectResolveChildOrientation(effect, (u8 *)&work.origin, &work.rotation);
            mdlEffectSetChildRotations(effect, (u8 *)&work.rotation);
            restore_slot = &work.savedRotation;
            /* lint: allow H009 -- retail copies the saved rotation quad through a fixed register
             * after the calls, which C cannot express. */
            __asm__ volatile("lq $2, 0(%0)\n\tsq $2, 0x50(%1)" : : "r"(restore_slot), "r"(root) : "$2", "memory");
        }
    }
    /* Reload after propagation, then subtract in the word's wrapping domain. */
    count_minus_1 = (s32)(root->frame - 1U);
    scale = root->state.fields.scalar60 * root->state.fields.scalar74;
    child = root->firstChild;
    mask = 0x80000000;
    five = 5.0f;
    for (; child != NULL; child = ((MdlEffectNode *)child)->next) {
        if (count_minus_1 < ((MdlEffectNode *)child)->startFrame) {
            continue;
        }
        if ((((MdlEffectNode *)child)->flags & 2) != 0) {
            continue;
        }
        if ((flags & mask) == 0) {
            if ((MEMBER(s32, child, MdlEffectState, flags.signedValue) & 0x18) != 0) {
                mdlEffectResolveChildOffset(child, (u8 *)&work.origin, &work.position);
                __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&work.origin), "m"(work.origin) : "$vf10", "memory");
                childFlags = ((MdlEffectState *)child)->flags.signedValue;
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
                primitive = ((MdlEffectNode *)child)->primitive;
                positionCallback = *(void (**)(s32, void *))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x20);
                if (positionCallback != NULL) {
                    positionCallback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, &work.position);
                }
            }
            if ((((MdlEffectState *)child)->flags.signedValue & 0x60) != 0) {
                mdlEffectResolveChildOrientation(child, (u8 *)&work.origin, &work.rotation);
                primitive = ((MdlEffectNode *)child)->primitive;
                rotationCallback = *(void (**)(s32, void *))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x24);
                if (rotationCallback != NULL) {
                    rotationCallback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, &work.rotation);
                }
            }
        }
        primitive = ((MdlEffectNode *)child)->primitive;
        (*(void (**)(s32))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x0C))(((MdlEffectPrimitiveRecord *)primitive)->instance.handle);
    }
    root->state.fields.word68 &= 0x7fffffffU;
}


#pragma pop
