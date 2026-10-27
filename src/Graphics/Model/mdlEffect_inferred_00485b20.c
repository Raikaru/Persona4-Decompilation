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

extern void mdlEffectSetChildPositions(u8 *effect, f32 *value);
extern void effMiscQuatMultiplyVU(void);
extern void effMiscBuildRotationVU(void);
extern void mdlEffectSetChildScales(u8 *effect, f32 value);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
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
extern void mdlEffectSetChildRotations(u8 *effect, u8 *value);
extern void mdlEffectApplyPackedColor(u8 *effect, s32 value);
/* Unpack packed RGBA bytes and scale all four channels into VU0 VF10. */
static inline void mdlEffectNormalizePackedColor(const u32 *source, f32 scale)
{
    u32 scaleBits;
    __asm__ volatile(
        "lw $2, 0(%1)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2 $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 %0, %2\n"
        "nop\n"
        "qmtc2 %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : "=&r"(scaleBits)
        : "r"(source), "f"(scale), "m"(*source)
        : "$2", "$vf2", "$vf10", "memory");
}
/* measured: retail leaves the copied quadword live in the return register, which callers ignore;
 * the four vf0 stores produce (0,0,0,1), not zero. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
// Destroys a node tree: for each child without sourceFlags bit 0, runs the kind's destroy callback,
// frees the payload blocks and node, then frees the root.
// FUN_00485B20
void mdlEffectDestroyWithNodes(u8 *effect)
{
    u8 *node;
    u8 *nextNode;
    u8 *record;
    u8 *primitive;
    u8 *secondaryAllocation;

    node = ((MdlEffectNode *)effect)->children;
    goto loop_00485b20_check;
loop_00485b20_body:
    nextNode = ((MdlEffectNode *)node)->next;
    if ((((MdlEffectNode *)node)->sourceFlags & 1) == 0) {
        record = ((MdlEffectNode *)node)->primitive;
        if (MEMBER(s32, record, MdlEffectPrimitiveRecord, instance.handle) != 0) {
            if (((MdlEffectPrimitiveHandlers *)(D_00713480 + (MEMBER(u16, record, MdlEffectPrimitiveRecord, kind) << 6)))->destroy.value == 0) {
                kAssertFail(D_00713470, 0x2EB);
            }
            (*(void (**)(s32))(D_00713480 + (((MdlEffectPrimitiveRecord *)record)->kind << 6) + 0x10))(
                ((MdlEffectPrimitiveRecord *)record)->instance.handle);
        }
        primitive = MEMBER(u8 *, record, MdlEffectSource, allocation.pointer);
        if (primitive != NULL) {
            jtbl_008873EC[0](primitive);
            *(s32 *)&((MdlEffectSource *)record)->parameters = 0;
            ((MdlEffectSource *)record)->count = 0;
            ((MdlEffectSource *)record)->allocation.pointer = NULL;
        }
        secondaryAllocation = MEMBER(u8 *, record, MdlEffectSource, secondaryAllocation.pointer);
        if (secondaryAllocation != NULL) {
            jtbl_008873EC[0](secondaryAllocation);
            *(s32 *)&((MdlEffectSource *)record)->secondaryParameters = 0;
            ((MdlEffectSource *)record)->secondaryCount = 0;
            ((MdlEffectSource *)record)->secondaryAllocation.pointer = NULL;
        }
        jtbl_008873EC[0](record);
    }
    jtbl_008873EC[0](node);
    node = nextNode;
loop_00485b20_check:
    if (node != NULL) {
        goto loop_00485b20_body;
    }
    jtbl_008873EC[0](effect);
}

/* Clones a node tree: copies the root header, then allocates a clone per source node, rebuilds its
 * primitive record via the kind's constructor, and copies it with mdlEffectCopyRecord. */
// FUN_00485C80
/* measured: with propagation off, retail keeps the allocator pointer live across all three
 * allocations instead of reloading the table address at first use. */
#pragma opt_propagation off
u8 *mdlEffectCloneWithNodes(u8 *effect)
{
    MdlEffectTree *sourceTree;
    MdlEffectTree *cloneTree;

    u_long128 identity;
    u8 *clone;
    u8 *node;
    u8 *nodeClone;
    u8 *src;
    u8 *prim;
    u16 kind;
    void *(**alloc)(u32, u32);

    if ((sourceTree = (MdlEffectTree *)effect)->firstChild == NULL) {
        kAssertFail(D_00713470, 0x6B7);
    }
    chkmemAllocSiteTag(D_00713470, 0x546);
    alloc = jtbl_008873E8;
    clone = (u8 *)alloc[0](0x90, 0x40000);
    if (clone == NULL) {
        kAssertFail(D_00713470, 0x547);
    }
    memset(clone, 0, 0x90);
    (cloneTree = (MdlEffectTree *)clone)->childCount = 0;
    *(s32 *)&((MdlEffectTree *)clone)->frame = 0;
    mdlEffectInitParticleState(clone);
    *(u_long128 *)clone = *(u_long128 *)effect;
    *(u_long128 *)&((MdlEffectState *)clone)->rotation = *(u_long128 *)&((MdlEffectState *)effect)->rotation; /* Transfer the complete quadword representation, including the VU W lane. */
    ((MdlEffectState *)clone)->multiplier = ((MdlEffectState *)effect)->multiplier;
    ((MdlEffectState *)clone)->flags.signedValue = ((MdlEffectState *)effect)->flags.signedValue;
    for (node = ((MdlEffectNode *)effect)->children; node != NULL; node = ((MdlEffectNode *)node)->next) {
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
        src = ((MdlEffectNode *)node)->primitive;
        if (*(u32 *)src > 0xD2) {
            kAssertFail(D_00713470, 0x318);
        }
        kind = ((MdlEffectPrimitiveRecord *)src)->kind;
        chkmemAllocSiteTag(D_00713470, 0x21);
        prim = (u8 *)alloc[0](0x2C, 0x40000);
        if (prim == NULL) {
            kAssertFail(D_00713470, 0x22);
        }
        memset(prim, 0, 0x2C);
        *(s32 *)prim = 0xD2;
        MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) = kind;
        ((MdlEffectPrimitiveRecord *)prim)->id = ((MdlEffectPrimitiveRecord *)src)->id;
        ((MdlEffectPrimitiveRecord *)prim)->sourceKind = ((MdlEffectPrimitiveRecord *)src)->sourceKind;
        if (((MdlEffectPrimitiveHandlers *)(D_00713480 + (MEMBER(u16, prim, MdlEffectPrimitiveRecord, kind) << 6)))->clone == NULL) {
            kAssertFail(D_00713470, 0x321);
        }
        ((MdlEffectPrimitiveRecord *)prim)->instance.pointer =
            (((MdlEffectPrimitiveHandlers *)(D_00713480 + (((MdlEffectPrimitiveRecord *)prim)->kind << 6)))->clone)(((MdlEffectPrimitiveRecord *)src)->instance.pointer); /* The 0x40-byte kind table has slot-specific callback signatures. */
        ((MdlEffectNode *)nodeClone)->primitive = prim;
        mdlEffectCopyRecord(nodeClone, node);
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
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(&identity) : "memory");
    mdlEffectSetChildPositions(clone, (f32 *)&identity);
    mdlEffectSetChildRotations(clone, (u8 *)&identity);
    mdlEffectSetChildScales(clone, 1.0f);
    mdlEffectApplyPackedColor(clone, -1);
    return clone;
}

/* Start every child primitive and reset the parent frame. */
// FUN_00485FE0
void mdlEffectStartChildren(u8 *effect) {
    u8 *n = ((MdlEffectNode *)effect)->children;
    u8 *o;
    void (*fn)(s32);

    while (n != NULL) {
        o = ((MdlEffectNode *)n)->primitive;
        fn = *(void (**)(s32))(D_00713480 + (((MdlEffectPrimitiveRecord *)o)->kind << 6) + 0x1C);
        if (fn != NULL) {
            fn(((MdlEffectPrimitiveRecord *)o)->instance.handle);
        }
        n = ((MdlEffectNode *)n)->next;
    }
    *(s32 *)&((MdlEffectTree *)effect)->frame = 0;
}

/* Return true only when every child with a completion callback reports done. */
// FUN_00486060
s32 mdlEffectChildrenAllDone(u8 *effect) {
    s32 (*callback)(s32);
    s32 result;
    u8 *primitive;
    u8 *child;

    child = ((MdlEffectNode *)effect)->children;
    goto loop_00486060_check;
loop_00486060_body:
    primitive = ((MdlEffectNode *)child)->primitive;
    callback = *(s32 (**)(s32))(D_00713480 +
        (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x34);
    if (callback != NULL) {
        result = callback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle);
    } else {
        result = 1;
    }
    if (result == 0) {
        return 0;
    }
    child = ((MdlEffectNode *)child)->next;
loop_00486060_check:
    if (child != NULL) {
        goto loop_00486060_body;
    }
    return 1;
}

/* Return true when any child activity callback reports active. */
// FUN_004860F0
s32 mdlEffectAnyChildActive(u8 *effect) {
    s32 (*callback)(s32);
    s32 result;
    u8 *primitive;
    u8 *child;

    child = ((MdlEffectNode *)effect)->children;
    goto loop_004860f0_check;
loop_004860f0_body:
    primitive = ((MdlEffectNode *)child)->primitive;
    callback = *(s32 (**)(s32))(D_00713480 +
        (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x38);
    if (callback != NULL) {
        result = callback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle);
    } else {
        result = 0;
    }
    if (result != 0) {
        return 1;
    }
    child = ((MdlEffectNode *)child)->next;
loop_004860f0_check:
    if (child != NULL) {
        goto loop_004860f0_body;
    }
    return 0;
}

/* Forward each primitive record to its optional kind-specific update callback. */
// FUN_00486180
void mdlEffectUpdateChildren(u8 *effect)
{
    u8 *child = ((MdlEffectNode *)effect)->children;

    while (child != NULL) {
        u8 *record = ((MdlEffectNode *)child)->primitive;
        void (*updateCallback)(s32, u8 *) =
            *(void (**)(s32, u8 *))(D_00713480 + (((MdlEffectPrimitiveRecord *)record)->kind << 6) + 0x3C);

        if (updateCallback != NULL) {
            updateCallback(((MdlEffectPrimitiveRecord *)record)->instance.handle, record);
        }
        child = ((MdlEffectNode *)child)->next;
    }
}

/* Transform child offsets by the parent rotation and scale, then forward their world positions. */
// FUN_004861F0
void mdlEffectSetChildPositions(u8 *effect, f32 *value)
{
    u_long128 transform[4];
    u_long128 origin;
    u_long128 position;
    f32 parentScale;
    f32 heightOffset;
    s32 flags;
    u8 *primitive;
    s32 (*callback)(s32, void *, u8 *);

    __asm__ volatile("lqc2 $vf10, 0($5)" : : : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0x40(%0)" : : "r"(effect) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(effect) : "$vf11", "memory");
    __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&origin) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf10, 0x50(%0)" : : "r"(effect) : "$vf10", "memory");
    effMiscBuildRotationVU();
    __asm__ volatile(
        "sqc2 $vf28, 0(%0)     \n"
        "sqc2 $vf29, 16(%0)    \n"
        "sqc2 $vf30, 32(%0)    \n"
        "sqc2 $vf31, 48(%0)    \n"
        :
        : "r"(&transform)
        : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
    parentScale = ((MdlEffectState *)effect)->scale * ((MdlEffectState *)effect)->multiplier;
    effect = ((MdlEffectNode *)effect)->children;
    heightOffset = 5.0f;
    goto loop_004861f0_check;
loop_004861f0_body:
    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&origin) : "$vf10", "memory");
    flags = ((MdlEffectState *)effect)->flags.signedValue;
    if ((flags & 4) != 0) {
        __asm__ volatile(
            "mfc1 $2, %0       \n"
            "nop               \n"
            "qmtc2.ni $2, $vf2 \n"
            "vaddx.y $vf10, $vf0, $vf2x \n"
            :
            : "f"(heightOffset)
            : "$2", "$vf2", "$vf10", "memory");
    }
    __asm__ volatile("lqc2 $vf11, 0x40(%0)" : : "r"(effect) : "$vf11", "memory");
    if ((flags & 0x80) != 0) {
        __asm__ volatile(
            "mfc1 $3, %0       \n"
            "nop               \n"
            "qmtc2.ni $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(parentScale)
            : "$3", "$vf2", "$vf11", "memory");
    }
    __asm__ volatile(
        "lqc2 $vf28, 0(%0)     \n"
        "lqc2 $vf29, 16(%0)    \n"
        "lqc2 $vf30, 32(%0)    \n"
        "lqc2 $vf31, 48(%0)    \n"
        :
        : "r"(&transform)
        : "$vf28", "$vf29", "$vf30", "$vf31", "memory");
    __asm__ volatile(
        "vmulax.xyzw $ACC, $vf28, $vf11x \n"
        "vmadday.xyzw $ACC, $vf29, $vf11y \n"
        "vmaddz.xyzw $vf11, $vf30, $vf11z \n"
        "vadd.xyzw $vf10, $vf10, $vf11 \n"
        :
        :
        : "$vf10", "$vf11", "ACC", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&position) : "$vf10", "memory");
    primitive = ((MdlEffectNode *)effect)->primitive;
    callback = *(s32 (**)(s32, void *, u8 *))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x20);
    if (callback != NULL) {
        callback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, &position, primitive);
    }
    effect = ((MdlEffectNode *)effect)->next;
loop_004861f0_check:
    if (effect != NULL) {
        goto loop_004861f0_body;
    }
}

/* Compose parent and child rotations, then refresh child positions. */
// FUN_00486330
void mdlEffectSetChildRotations(u8 *effect, u8 *value)
{
    u_long128 scratch[2];
    u8 *primitive;
    u8 *child;
    void (*callback)(s32, void *);

    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(value) : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0x50(%0)" : : "r"(effect) : "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(scratch + 1) : "$vf10", "memory");
    effMiscBuildRotationVU();
    __asm__ volatile(
        "lqc2 $vf10, 0x10(%0)       \n"
        "vmulax.xyzw $ACC, $vf28, $vf10x \n"
        "vmadday.xyzw $ACC, $vf29, $vf10y \n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z \n"
        "sqc2 $vf10, 0(%0)          \n"
        :
        : "r"(effect)
        : "$vf10", "ACC", "memory");
    child = ((MdlEffectNode *)effect)->children;
    goto loop_00486330_check;
loop_00486330_body:
    __asm__ volatile("lqc2 $vf10, 0x50(%0)" : : "r"(child) : "$vf10", "memory");
    __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(scratch + 1) : "$vf11", "memory");
    effMiscQuatMultiplyVU();
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(scratch) : "$vf10", "memory");
    primitive = ((MdlEffectNode *)child)->primitive;
    callback = *(void (**)(s32, void *))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x24);
    if (callback != NULL) {
        callback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, scratch);
    }
    child = ((MdlEffectNode *)child)->next;
loop_00486330_check:
    if (child != NULL) {
        goto loop_00486330_body;
    }
    mdlEffectSetChildPositions(effect, (f32 *)(effect + 0x40));
}

/* Apply scalar or vector child scales and refresh positions that inherit scale. */
// FUN_00486400
void mdlEffectSetChildScales(u8 *effect, f32 value)
{
    u_long128 transform;
    u_long128 origin;
    f32 parentScale;
    f32 heightOffset;
    f32 scalarScale;
    f32 vectorScale;
    s32 flags;
    u8 *primitive;
    u8 *child;
    void (*updateCallback)(s32, u8 *, f32);
    void (*vectorScaleCallback)(s32, void *, u8 *);
    void (*positionCallback)(s32, void *, u8 *);

    ((MdlEffectState *)effect)->scale = value;
    parentScale = value * ((MdlEffectState *)effect)->multiplier;
    child = ((MdlEffectNode *)effect)->children;
    heightOffset = 5.0f;
    goto loop_00486400_check;
loop_00486400_body:
    flags = ((MdlEffectState *)child)->flags.signedValue;
    if ((flags & 0x100) == 0) {
        scalarScale = ((MdlEffectState *)child)->scale;
        if ((((MdlEffectNode *)child)->flags & 1) != 0) {
            scalarScale *= parentScale;
        }
        primitive = ((MdlEffectNode *)child)->primitive;
        updateCallback = *(void (**)(s32, u8 *, f32))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x28);
        if (updateCallback != NULL) {
            updateCallback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, primitive, scalarScale);
        }
        goto loop_00486400_tail;
    }
    __asm__ volatile("lqc2 $vf10, 0x20(%0)" : : "r"(child) : "$vf10", "memory");
    vectorScale = ((MdlEffectState *)child)->scale;
    if ((((MdlEffectNode *)child)->flags & 1) != 0) {
        vectorScale *= parentScale;
    }
    __asm__ volatile(
        "mfc1 $3, %0       \n"
        "nop               \n"
        "qmtc2.ni $3, $vf2 \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        :
        : "f"(vectorScale)
        : "$3", "$vf2", "$vf10", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&origin) : "$vf10", "memory");
    primitive = ((MdlEffectNode *)child)->primitive;
    vectorScaleCallback = *(void (**)(s32, void *, u8 *))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x2C);
    if (vectorScaleCallback != NULL) {
        vectorScaleCallback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, &origin, primitive);
    }
loop_00486400_tail:
    flags = ((MdlEffectState *)child)->flags.signedValue;
    if ((flags & 0x80) != 0) {
        __asm__ volatile("lqc2 $vf10, 0x40(%0)" : : "r"(effect) : "$vf10", "memory");
        __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(effect) : "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        if ((flags & 4) != 0) {
            __asm__ volatile(
                "mfc1 $2, %0       \n"
                "nop               \n"
                "qmtc2.ni $2, $vf2 \n"
                "vaddx.y $vf10, $vf0, $vf2x \n"
                :
                : "f"(heightOffset)
                : "$2", "$vf2", "$vf10", "memory");
        }
        __asm__ volatile("lqc2 $vf11, 0x40(%0)" : : "r"(child) : "$vf11", "memory");
        __asm__ volatile(
            "mfc1 $3, %0       \n"
            "nop               \n"
            "qmtc2.ni $3, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(parentScale)
            : "$3", "$vf2", "$vf11", "memory");
        __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&transform) : "$vf10", "memory");
        primitive = ((MdlEffectNode *)child)->primitive;
        positionCallback = *(void (**)(s32, void *, u8 *))(D_00713480 + (((MdlEffectPrimitiveRecord *)primitive)->kind << 6) + 0x20);
        if (positionCallback != NULL) {
            positionCallback(((MdlEffectPrimitiveRecord *)primitive)->instance.handle, &transform, primitive);
        }
    }
    child = ((MdlEffectNode *)child)->next;
loop_00486400_check:
    if (child != NULL) {
        goto loop_00486400_body;
    }
}

// Stores value at +0x64 and normalises it into each child node's packed colour (node +0x64), walking the child list at +0x8C.
// FUN_004865C0
/* Only the packed-word and VU bridges are inline assembly; locals and traversal stay in C. */
void mdlEffectApplyPackedColor(u8 *effect, s32 value)
{
    u32 baseColor;
    u32 childColor;
    u32 packedColor;
    f32 parent[4] __attribute__((aligned(16)));
    f32 scale;
    const u32 *source;
    u8 *node;
    u8 *data;
    void (*callback)(s32, u32);
    u32 color;
    u32 work;

    ((MdlEffectState *)effect)->packedColor.signedValue = value;
    baseColor = (u32)value;
    source = &baseColor;
    scale = fGpffff8044;
    mdlEffectNormalizePackedColor(source, scale);
    __asm__ volatile("sqc2 $vf10, 0(%1)\n"
        : "=m"(parent) : "r"(parent) : "memory");

    node = ((MdlEffectNode *)effect)->children;
    if (node != NULL) {
        while (node != NULL) {
            childColor = ((MdlEffectState *)node)->packedColor.value;
            source = &childColor;
            mdlEffectNormalizePackedColor(source, scale);
            __asm__ volatile(
                "lqc2 $vf11, 0(%0)\n"
                "vmul.xyzw $vf10, $vf10, $vf11\n"
                : : "r"(parent), "m"(parent)
                : "$vf10", "$vf11", "memory");
            work = 0x437F0000U; /* Binary32 255.0f, transferred to VF2.x. */
            __asm__ volatile(
                "qmtc2 %0, $vf2\n"
                "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                "vftoi0.xyzw $vf10, $vf10\n"
                "qmfc2 %0, $vf10\n"
                "ppach %0, $zero, %0\n"
                "ppacb %0, $zero, %0\n"
                "sw %0, packedColor\n"
                : "+r"(work), "=m"(packedColor)
                : : "$vf2", "$vf10", "memory");
            color = packedColor;
            data = ((MdlEffectNode *)node)->primitive;
            callback = *(void (**)(s32, u32))(
                D_00713480 + ((MdlEffectPrimitiveRecord *)data)->kind * 0x40 + 0x30);
            if (callback != NULL) {
                callback(((MdlEffectPrimitiveRecord *)data)->instance.handle, color);
            }
            node = ((MdlEffectNode *)node)->next;
        }
    }
}


