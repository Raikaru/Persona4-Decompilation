#include "include_asm.h"
/* Persona 4 USA decompilation - effBlurFilter.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "effect_instance_internal.h"

extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);

/* Defined below in this file; called above its definition. */
extern u8 *effBlurFilterCreateRefObj(u16 *object, u16 slot);

extern char D_00714380[];
extern char D_00714450[];

extern void kAssertFail(const char *file, s32 line);
extern void chkmemAllocSiteTag(const char *file, s32 line);
extern void RpSkyRenderStateGet(s32 param, void *out);
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887314[])(s32, void *, s32, void *, s32);
extern u32 D_00922D90[];
extern u8 D_00714368[];
extern void mdlEffectEmitValuePacket(s64 instance);
extern void mdlEffectEmitSlotPacket(void);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern s32 mdlEffectProjectBillboardQuad(u8 *parameters, void *vertices);
extern void mdlEffectBuildRectQuad(u8 *parameters, void *vertices);
extern void mdlEffectBuildOffsetQuad(u8 *parameters, void *vertices);
extern void mdlEffectBuildDirectRectQuad(u8 *parameters, void *vertices);
extern void PrimAppendNode(s32 list, void *node);
extern s32 TnGetOffset38(u16 slotIndex);
extern void *memset(void *dest, s32 value, s32 size);
extern void memcpy(void *dst, const void *src, u32 size);
extern void func_003ef3a0(void *ptr);
extern f32 fGpffff80f8;
extern void mdlEffectInitRandomQuad(u8 *parameters, u8 *entry);
extern void effBlurFilterSpawnSlot(u8 *object, u8 *slot);
extern void mdlEffectDrawProjectedBillboard(u8 *effect, s32 *textureSource);
extern s32 TnUploadStreamTagged(void *stream);
extern s32 TnSlotObject(u16 slotIndex);
extern u8 D_00714394[];
extern u8 D_00714398[];
extern u8 D_0071439C[];
extern u8 D_007143A0[];
extern u8 D_00714464[];
extern u8 D_00714468[];
extern u8 D_0071446C[];
extern u8 D_00714470[];
extern u8 D_00714474[];
extern u8 D_00714390[];
extern u8 D_007143A4[];
extern u8 D_00714460[];

/* Layouts follow the node constructors (0x60 bytes), slot stride (0x34)
 * and configuration readers. Mode-dependent integer, float and alpha-byte
 * representations share unions; unknown resource spans stay uninterpreted. */
typedef struct BlurFilterParameters {
    union {
        s32 signedValue;
        s8 signedByte[4];
        u32 unsignedValue;
    } unk00; /* +0x00 */
    union {
        f32 scalar;
        s32 signedValue;
        s8 signedByte[4];
    } unk04; /* +0x04 */
    union {
        f32 scalar;
        s32 signedValue;
    } unk08; /* +0x08 */
    union {
        f32 scalar;
        s32 signedValue;
        s8 signedByte[4];
    } unk0C; /* +0x0C */
    union {
        f32 scalar;
        s32 signedValue;
    } unk10; /* +0x10 */
    union {
        f32 scalar;
        s32 signedValue;
    } unk14; /* +0x14 */
    union {
        f32 scalar;
        s32 signedValue;
    } unk18; /* +0x18 */
    union {
        f32 scalar;
        s32 signedValue;
    } unk1C; /* +0x1C */
    union {
        f32 scalar;
        s32 signedValue;
    } unk20; /* +0x20 */
    union {
        f32 scalar;
        s32 signedValue;
    } unk24; /* +0x24 */
    union {
        f32 scalar;
        s32 signedValue;
    } unk28; /* +0x28 */
    f32 unk2C; /* +0x2C */
    f32 unk30; /* +0x30 */
} BlurFilterParameters;

typedef struct BlurFilterSlot {
    union {
        f32 scalar;
        s32 signedValue;
        u32 unsignedValue;
    } unk00; /* +0x00 */
    union {
        f32 scalar;
        s32 signedValue;
    } unk04; /* +0x04 */
    u8 pad08[0x4];
    union {
        s32 signedValue;
        u8 byte[4];
    } unk0C; /* +0x0C */
    s32 unk10; /* +0x10 */
    f32 unk14; /* +0x14 */
    f32 unk18; /* +0x18 */
    f32 unk1C; /* +0x1C */
    f32 unk20; /* +0x20 */
    f32 unk24; /* +0x24 */
    f32 unk28; /* +0x28 */
    f32 unk2C; /* +0x2C */
    f32 unk30; /* +0x30 */
} BlurFilterSlot;

typedef struct BlurFilterQuad {
    u8 pad00[0x14];
    f32 unk14; /* +0x14 */
    f32 unk18; /* +0x18 */
    f32 unk1C; /* +0x1C */
    f32 unk20; /* +0x20 */
    f32 unk24; /* +0x24 */
    f32 unk28; /* +0x28 */
} BlurFilterQuad;

typedef struct BlurFilterNode {
    u8 pad00[0x10];
    s32 color; /* +0x10 */
    union {
        f32 scalar;
        s32 signedValue;
    } scale; /* +0x14 */
    union {
        s32 signedValue;
        u16 half[2];
    } kind; /* +0x18 */
    s32 elapsed; /* +0x1C */
    union {
        s32 signedValue;
        u8 * bytes;
        void * pointer;
    } slots; /* +0x20 */
    union {
        const void * constPointer;
        u8 * bytes;
    } configuration; /* +0x24 */
    union {
        s32 signedValue;
        u8 * bytes;
        void * pointer;
    } reference; /* +0x28 */
    s32 nodeNext; /* +0x2C */
    s32 nodePrevious; /* +0x30 */
    u8 pad34[0x10];
    s16 tag; /* +0x44 */
    u8 pad46[0x2];
    u8 * owner; /* +0x48 */
    u8 pad4C[0x14];
} BlurFilterNode;

typedef struct BlurFilterConfiguration {
    u8 pad00[0x28];
    union {
        s32 signedValue;
        u16 half[2];
    } resourceId; /* +0x28 */
    u8 pad2C[0x8C];
    s32 duration; /* +0xB8 */
    u8 screenSpace; /* +0xBC */
    u8 padBD[0x3];
    union {
        u8 byte[4];
    } unkC0; /* +0xC0 */
    union {
        u8 byte[4];
    } unkC4; /* +0xC4 */
    f32 unkC8; /* +0xC8 */
    union {
        s32 signedValue;
        u8 byte[4];
    } unkCC; /* +0xCC */
    s32 unkD0; /* +0xD0 */
    f32 unkD4; /* +0xD4 */
} BlurFilterConfiguration;

typedef struct BlurFilterRef {
    s32 kind; /* +0x00 */
    s32 references; /* +0x04 */
    union {
        s32 signedValue;
        s32 * words;
        u8 * bytes;
        void * pointer;
    } resource; /* +0x08 */
} BlurFilterRef;

/* Six-word descriptors: initializer, destructor, tick, draw, reference
 * flag and copied-data byte count. The D_... labels below name their columns. */
typedef struct BlurFilterType {
    u32 initialize;
    u32 destroy;
    u32 update;
    u32 draw;
    s8 usesReference;
    u8 pad11[3];
    s32 dataBytes;
} BlurFilterType;

/* These linker labels point into descriptor columns, not separate
 * allocations. Each column repeats at the descriptor's 0x18-byte stride;
 * using its own alias preserves the retail symbol-relative load immediate. */
typedef struct BlurFilterCallbackEntry {
    u32 callback;
    u8 pad04[0x14];
} BlurFilterCallbackEntry;
typedef struct BlurFilterFlagEntry {
    s8 usesReference;
    u8 pad01[0x17];
} BlurFilterFlagEntry;
typedef struct BlurFilterSizeEntry {
    s32 dataBytes;
    u8 pad04[0x14];
} BlurFilterSizeEntry;

extern void *effBlurFilterRetainRefObj(BlurFilterRef *object);
extern void effBlurFilterReleaseRefObj(void *object);

extern f32 sinf(f32 scalar);
extern s32 fptodp(f32 a);
extern s32 func_0044b310(s32 a);
extern s32 dpsub(s64 a, s32 b);
extern s32 func_0044e168(s64 a, s32 b);
extern f32 dptofp(s32 a);
extern f32 fGpffff8084;
extern s64 fGpffff8018;
extern s64 fGpffff8010;
extern s64 fGpffff8020;
extern s64 fGpffff8010;
extern s64 fGpffff8020;

extern s32 mdlEffectSamplePackedColor(u8 *colorData, u8 *opacityData, s32 frame, s32 duration);
extern f32 mdlEffectSampleScalarKeys(u8 *keys, s32 frame, s32 duration);
extern f32 mdlEffectAnchorScreenScale(f32 inputScale);
extern f32 fGpffff8044;
extern f32 fGpffff80f0;
extern void effBlurFilterTickSlotsA(u8 *a, u8 *b);
extern void effBlurFilterTickSlotsB(u8 *a, u8 *b);
extern void effBlurFilterAdvanceSlots(u8 *a, u8 *b);

/* measured: optimization_level 1 plus the swapped integer declaration order and
   a block-local threshold produce object 488B/window 496B and only the two
   zero-padding tail words differ in the standalone probe (nd 2). Compound
   overflow masking keeps the OR/ANDI result in the retail destination
   register; the candidate body follows the 004A8F90 sibling skeleton. */
/* measured: effBlurFilterTickSlotsA O1 bracket, standalone probe object 488B/window 496B,
   normalized_diff 2 (retail-only zero-padding tail). */
#pragma optimization_level 1
// Ticks a blur slot table with the first alpha ramp (fGpffff8018 and fGpffff8020 constants).
// FUN_004A8BB0
void effBlurFilterTickSlotsA(u8 *a, u8 *b) {
    BlurFilterParameters *parameters = (BlurFilterParameters *)a;
    BlurFilterSlot *slot = (BlurFilterSlot *)b;
    int slotIndex;
    union { struct { u8 r; u8 g; u8 b2; u8 a; } rgba; u32 packed; } color;
    int slotCount;
    float wave;
    float alphaF;
    float fadedAlpha;
    u32 alpha;
    s32 alphaByte;

    slotCount = parameters->unk00.signedValue;
    if (!(slotCount <= 0x64)) {
        kAssertFail(D_00714380, 0x190);
    }
    color.packed = (u32)parameters->unk0C.signedValue;
    alpha = (u32)color.rgba.a;
    if (alpha >= 0) {
        alphaF = (float)alpha;
    } else {
        alpha = (alpha >> 1) | (alpha & 1);
        alphaF = (float)alpha;
        alphaF += alphaF;
    }

    for (slotIndex = 0; slotIndex < slotCount; slotIndex = slotIndex + 1) {
        if (slot->unk00.signedValue == 0) {
            float threshold;
            if (!(slot->unk04.scalar <= fGpffff8084)) {
                mdlEffectInitRandomQuad(a, (u8 *)slot);
            }
            wave = sinf(slot->unk04.scalar);
            slot->unk18 = 1.0f + parameters->unk18.scalar * wave;
            fadedAlpha = alphaF * dptofp(func_0044e168(fGpffff8018, dpsub(fGpffff8020, func_0044b310(fptodp(slot->unk04.scalar)))));
            threshold = 2.1474836e9f;
            if (threshold <= fadedAlpha) {
                goto alpha_big;
            }
            alphaByte = (s32)fadedAlpha;
            alphaByte &= 0xFF;
            goto alpha_done;
        alpha_big:
            alphaByte = (s32)(fadedAlpha - threshold);
            alphaByte |= 0x80000000;
            alphaByte &= 0xFF;
        alpha_done:
            slot->unk0C.byte[3] = (u8)alphaByte;
            slot->unk04.scalar = slot->unk04.scalar + parameters->unk08.scalar;
        } else {
            slot->unk0C.byte[3] = 0;
            slot->unk00.signedValue = slot->unk00.signedValue - 1;
        }
        slot = slot + 1;
    }
}
/* measured: closes effBlurFilterTickSlotsA O1 bracket; restore O2 for the next function. */
#pragma optimization_level 2

extern f32 cosf(f32 param);
extern f32 fGpffff80f4;
extern f32 fGpffff80cc;
/* measured: re-measured this wave at nd 12 (6 rows, one block) with a full
   candidate rebuilt from the m2c (int literals 810/650 -> addiu+mtc1+cvt,
   reverse decl order t23..t1, chains written `t21 + (810 - t20 - t21) *
   rand` with the product as the madd's fs operand). Chain 1, chain 2's
   adda/madd, the 4th/5th madd sites and all stores match byte-for-byte.
   Residual is exactly two coupled facts: (1) mwcc b210 CSEs fGpffff80cc*t20
   across the `t21 = t21 + fcc*t20; t23 = 0.5f*t1 + fcc*t20;` pair - it
   emits mul.s(prod); adda.s 0+prod; madd.s(0.5f,t1); add.s, where retail
   mula-seeds 0.5f*t1 first, then mul.s(prod), add.s, madd.s(fcc,t20)
   re-deriving the product; (2) the chain-2 sub-chain temps swap ($f1/$f2
   vs retail $f2/$f1) as a knock-on of the CSE block's $f1 use. New
   spellings this wave: f32 prod local (2 placements, nd 108-111), (f32)
   cast on one product (folds, nd 12), &fGpffff80cc deref (nd 46). Both
   statement orders tried. FMA-CSE fusion floor. */
// Spawns one blur slot: random index, random jitter and sine/cosine offsets from the object parameters.
// FUN_004A8DA0
void effBlurFilterSpawnSlot(u8 *object, u8 *slot) {
    f32 centerY;
    f32 angle;
    f32 centerX;
    f32 halfSize;
    u8 *drawData;

    ((BlurFilterSlot *)slot)->unk00.unsignedValue = effMiscRand(0) % (u32)(((BlurFilterParameters *)object)->unk04.signedValue + 1);
    ((BlurFilterSlot *)slot)->unk04.scalar = fGpffff80f4;
    drawData = slot + 8;
    ((BlurFilterSlot *)slot)->unk10 = ((BlurFilterParameters *)object)->unk10.signedValue;
    ((BlurFilterSlot *)slot)->unk14 = ((BlurFilterParameters *)object)->unk14.scalar;
    ((BlurFilterSlot *)slot)->unk0C.signedValue = ((BlurFilterParameters *)object)->unk0C.signedValue;
    halfSize = 0.5f * (f32)((BlurFilterParameters *)object)->unk28.signedValue;
    angle = fGpffff8084 * (2.0f * (effMiscRandFloat(0) - 0.5f));
    centerX = ((BlurFilterParameters *)object)->unk30;
    centerX = centerX + (810.0f - halfSize - centerX) * effMiscRandFloat(0);
    centerX = (f32)(0.5f * centerX);
    centerY = ((BlurFilterParameters *)object)->unk2C;
    centerY = centerY + (650.0f - halfSize - centerY) * effMiscRandFloat(0);
    centerY = (f32)(0.5f * centerY);
    centerX = centerX + fGpffff80cc * halfSize;
    centerY = centerY + fGpffff80cc * halfSize;
    centerX = ((BlurFilterParameters *)object)->unk1C.scalar + centerX * cosf(angle);
    centerY = ((BlurFilterParameters *)object)->unk20.scalar + centerY * sinf(angle);
    ((BlurFilterQuad *)drawData)->unk14 = centerX;
    ((BlurFilterQuad *)drawData)->unk18 = centerY;
    ((BlurFilterQuad *)drawData)->unk1C = centerX - halfSize;
    ((BlurFilterQuad *)drawData)->unk20 = centerY - halfSize;
    ((BlurFilterQuad *)drawData)->unk24 = centerX + halfSize;
    ((BlurFilterQuad *)drawData)->unk28 = centerY + halfSize;
}

/* measured: cluster transfer from effBlurFilterTickSlotsA - changing only the assert
   line to 575 and the recursive helper to effBlurFilterSpawnSlot preserves the exact
   488B candidate body/window 496B with only the two retail zero-padding tail
   words outside the standalone object (nd 2). */
/* measured: effBlurFilterTickSlotsB O1 bracket, standalone probe object 488B/window 496B,
   normalized_diff 2 (retail-only zero-padding tail). */
#pragma optimization_level 1
// Ticks a blur slot table with the second alpha ramp (fGpffff8018 and fGpffff8010 constants).
// FUN_004A8F90
void effBlurFilterTickSlotsB(u8 *a, u8 *b) {
    BlurFilterParameters *parameters = (BlurFilterParameters *)a;
    BlurFilterSlot *slot = (BlurFilterSlot *)b;
    int slotIndex;
    union { struct { u8 r; u8 g; u8 b2; u8 a; } rgba; u32 packed; } color;
    int slotCount;
    float wave;
    float alphaF;
    float fadedAlpha;
    u32 alpha;
    s32 alphaByte;

    slotCount = parameters->unk00.signedValue;
    if (!(slotCount <= 0x64)) {
        kAssertFail(D_00714380, 575);
    }
    color.packed = (u32)parameters->unk0C.signedValue;
    alpha = (u32)color.rgba.a;
    if (alpha >= 0) {
        alphaF = (float)alpha;
    } else {
        alpha = (alpha >> 1) | (alpha & 1);
        alphaF = (float)alpha;
        alphaF += alphaF;
    }

    for (slotIndex = 0; slotIndex < slotCount; slotIndex = slotIndex + 1) {
        if (slot->unk00.signedValue == 0) {
            float threshold;
            if (!(slot->unk04.scalar <= fGpffff8084)) {
                effBlurFilterSpawnSlot(a, (u8 *)slot);
            }
            wave = sinf(slot->unk04.scalar);
            slot->unk18 = 1.0f + parameters->unk18.scalar * wave;
            fadedAlpha = alphaF * dptofp(func_0044e168(fGpffff8018, dpsub(fGpffff8010, func_0044b310(fptodp(slot->unk04.scalar)))));
            threshold = 2.1474836e9f;
            if (threshold <= fadedAlpha) {
                goto alpha_big;
            }
            alphaByte = (s32)fadedAlpha;
            alphaByte &= 0xFF;
            goto alpha_done;
        alpha_big:
            alphaByte = (s32)(fadedAlpha - threshold);
            alphaByte |= 0x80000000;
            alphaByte &= 0xFF;
        alpha_done:
            slot->unk0C.byte[3] = (u8)alphaByte;
            slot->unk04.scalar = slot->unk04.scalar + parameters->unk08.scalar;
        } else {
            slot->unk0C.byte[3] = 0;
            slot->unk00.signedValue = slot->unk00.signedValue - 1;
        }
        slot = slot + 1;
    }
}
/* measured: closes effBlurFilterTickSlotsB O1 bracket; restore O2 for the next function. */
#pragma optimization_level 2
// Advances a slot table in place with 13-word slots, fading alpha by the slot fraction.
// FUN_004A9180
void effBlurFilterAdvanceSlots(u8 *a, u8 *b) {
    BlurFilterParameters *parameters = (BlurFilterParameters *)a;
    BlurFilterSlot *slot = (BlurFilterSlot *)b;
    int slotCount;
    union { struct { u8 r; u8 g; u8 b2; u8 a; } rgba; u32 packed; } color;
    int slotIndex;
    int centerY;
    float wave;
    int radius;
    float fraction;
    float alphaF;
    int centerX;
    u32 alpha;

    slotCount = parameters->unk00.signedValue;
    color.packed = (u32)parameters->unk0C.signedValue;
    alpha = (u32)color.rgba.a;
    if (alpha >= 0) {
        alphaF = (float)alpha;
    } else {
        alpha = (alpha >> 1) | (alpha & 1);
        alphaF = (float)alpha;
        alphaF += alphaF;
    }

    for (slotIndex = 0; slotIndex < slotCount; slotIndex = slotIndex + 1) {
        if (!(slot->unk00.scalar < 0.0f)) {
            wave = sinf(slot->unk04.scalar);
            slot->unk18 = parameters->unk18.scalar * wave * (1.0f - slot->unk00.scalar) + 1.0f;
            slot->unk0C.signedValue = parameters->unk0C.signedValue;
            wave = alphaF * (1.0f - slot->unk00.scalar);
            slot->unk0C.byte[3] = (u8)(u32)wave;
            radius = (int)((float)parameters->unk28.signedValue * slot->unk00.scalar);
            centerX = (int)parameters->unk20.scalar;
            centerY = (int)parameters->unk24.scalar;
            slot->unk1C = (float)centerX;
            slot->unk20 = (float)centerY;
            slot->unk24 = (float)(centerX - radius);
            slot->unk28 = (float)(centerY - radius);
            slot->unk2C = (float)(centerX + radius);
            slot->unk30 = (float)(centerY + radius);
            slot->unk04.scalar = slot->unk04.scalar + parameters->unk1C.scalar;
            wave = parameters->unk04.scalar;
            fraction = slot->unk00.scalar;
            slot->unk00.scalar = fraction + wave;
            if (!(fraction + wave <= 1.0f)) {
                slot->unk04.scalar = 0.0f;
                slot->unk00.scalar = 0.0f;
                slot->unk10 = parameters->unk10.signedValue;
                slot->unk14 = parameters->unk14.scalar;
            }
        }
        else {
            slot->unk00.scalar = slot->unk00.scalar + parameters->unk04.scalar;
        }
        slot = slot + 1;
    }
}
// Refreshes the screen-rect block: default constants on first use, then recomputed from the tracker, with the flag byte cleared below the threshold.
// FUN_004A93D0
void effBlurFilterUpdateScreenRect(u8 *object) {
    s32 effectColor;
    s32 sampledColor;
    s32 combinedColor;
    u8 *base;
    u8 *obj;
    s32 a;
    s32 b;
    s32 tmp;
    s32 *pt;
    f32 scale;

    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    a = ((BlurFilterConfiguration *)obj)->duration;
    if (a == 0) {
        b = 0;
    } else {
        b = ((BlurFilterNode *)object)->elapsed;
    }
    if (b == 0) {
        ((BlurFilterParameters *)base)->unk10.signedValue = 0x43A00000;
        ((BlurFilterParameters *)base)->unk14.signedValue = 0x43600000;
        ((BlurFilterParameters *)base)->unk18.signedValue = 0;
        ((BlurFilterParameters *)base)->unk1C.signedValue = 0;
        ((BlurFilterParameters *)base)->unk20.signedValue = 0x44200000;
        ((BlurFilterParameters *)base)->unk24.signedValue = 0x43E00000;
        ((BlurFilterParameters *)base)->unk04.signedValue = ((BlurFilterConfiguration *)obj)->resourceId.signedValue;
    }
    if (a >= b) {
        tmp = mdlEffectSamplePackedColor(obj, obj + 0x24, b, a);
        effectColor = ((BlurFilterNode *)object)->color;
        pt = &effectColor;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x64($sp)      \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
        ((BlurFilterParameters *)base)->unk00.signedValue = *(volatile s32 *)&combinedColor;
        ((BlurFilterParameters *)base)->unk0C.scalar = 1.0f + fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x34, b, a);
        ((BlurFilterParameters *)base)->unk08.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x60, b, a);
        return;
    }
    ((BlurFilterParameters *)base)->unk00.signedByte[3] = 0;
}

// Submits the sky pass when the draw count is positive, bracketing the render-state changes.
// FUN_004A9590
void effBlurFilterDrawSlotPass(u8 *object) {
    s32 savedState;
    u8 vertices[0x108];
    u8 *base;

    base = ((BlurFilterNode *)object)->configuration.bytes + 0xC0;
    if (((BlurFilterConfiguration *)((BlurFilterNode *)object)->configuration.bytes)->unkC0.byte[3] > 0) {
        RpSkyRenderStateGet(3, &savedState);
        if (mdlEffectProjectBillboardQuad(base, vertices) != 0) {
            D_00887300[0](1, D_00922D90[0]);
            RpSkyRenderStateSet(3, 0x31001);
            mdlEffectEmitValuePacket(0x9FC00A | ((s64)0x6FC << 0x20));
            D_00887314[0](3, vertices, 4, D_00714368, 6);
            mdlEffectEmitSlotPacket();
        }
        RpSkyRenderStateSet(3, savedState);
        D_00887300[0](1, 0);
    }
}

// Updates the quad corners from the scale parameter, running the scaled radius through the VU helper.
// FUN_004A9690
void effBlurFilterUpdateRectFromScale(u8 *object) {
    f32 vec[4];
    s32 effectColor;
    s32 sampledColor;
    s32 combinedColor;
    u8 *base;
    u8 *obj;
    s32 b;
    s32 a;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 g;
    f32 prod;

    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    a = ((BlurFilterConfiguration *)obj)->duration;
    if (a == 0) {
        b = 0;
    } else {
        b = ((BlurFilterNode *)object)->elapsed;
    }
    if (a >= b) {
        f = mdlEffectSampleScalarKeys(obj + 0x8C, b, a);
        if (((BlurFilterConfiguration *)obj)->screenSpace != 0) {
            ((BlurFilterParameters *)base)->unk14.scalar = 320.0f;
            ((BlurFilterParameters *)base)->unk18.scalar = 224.0f;
            ((BlurFilterParameters *)base)->unk1C.scalar = 320.0f - f;
            ((BlurFilterParameters *)base)->unk20.scalar = 224.0f - f;
            ((BlurFilterParameters *)base)->unk24.scalar = 320.0f + f;
            ((BlurFilterParameters *)base)->unk28.scalar = 224.0f + f;
        } else {
            prod = f * ((BlurFilterNode *)object)->scale.scalar;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(object) : "$vf10", "memory");
            g = mdlEffectAnchorScreenScale(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            ((BlurFilterParameters *)base)->unk14.scalar = vec[0];
            ((BlurFilterParameters *)base)->unk18.scalar = vec[1];
            ((BlurFilterParameters *)base)->unk1C.scalar = vec[0] - g;
            ((BlurFilterParameters *)base)->unk20.scalar = vec[1] - g;
            ((BlurFilterParameters *)base)->unk24.scalar = vec[0] + g;
            ((BlurFilterParameters *)base)->unk28.scalar = vec[1] + g;
        }
        tmp = mdlEffectSamplePackedColor(obj, obj + 0x24, b, a);
        effectColor = ((BlurFilterNode *)object)->color;
        pt = &effectColor;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x74($sp)      \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
((BlurFilterParameters *)base)->unk04.signedValue = *(volatile s32 *)&combinedColor;
        ((BlurFilterParameters *)base)->unk10.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x34, b, a) + 1.0f;
        ((BlurFilterParameters *)base)->unk0C.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x60, b, a);
        ((BlurFilterParameters *)base)->unk08.signedValue = ((BlurFilterConfiguration *)obj)->resourceId.signedValue;
    } else {
        ((BlurFilterParameters *)base)->unk04.signedByte[3] = 0;
    }
}

typedef struct BlurSkyVertex {
    u8 pad00[0x10];
    s32 uBits;
    s32 vBits;
    u8 pad18[0x28];
} BlurSkyVertex;

typedef struct BlurGsQuad {
    f32 x, y;
    u8 pad0[0x38];
    f32 x1, y1;
    u8 pad1[0x38];
    f32 x2, y2;
    u8 pad2[0x38];
    f32 x3, y3;
    u8 pad3[0x38];
} BlurGsQuad;

// Draws the reference pass with the two saved render states and the slot packet.
// FUN_004A98D0
void effBlurFilterDrawRefPass(u8 *object) {
    s32 savedTextureState;
    s32 savedBlendState;
    u8 referenceVertices[0xFC];
    u8 overlayVertices[0x100];
    s32 *drawData;
    u8 *parameters;
    u8 *configuration;
    void (**setState)(u32, u32);
    void (**sendPacket)(s32, void *, s32, void *, s32);

    configuration = ((BlurFilterNode *)object)->configuration.bytes;
    parameters = configuration + 0xC0;
    if (((BlurFilterConfiguration *)configuration)->unkC4.byte[3] > 0) {
        drawData = ((BlurFilterRef *)((BlurFilterNode *)object)->reference.bytes)->resource.words;
        RpSkyRenderStateGet(2, &savedTextureState);
        RpSkyRenderStateGet(3, &savedBlendState);
        setState = (void (**)(u32, u32))D_00887300;
        (*setState)((u32)1, *(u32 *)drawData);
        mdlEffectEmitMaskedTagPair();
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x31001);
        mdlEffectBuildRectQuad(parameters + 4, referenceVertices);
        sendPacket = (void (**)(s32, void *, s32, void *, s32))D_00887314;
        (*sendPacket)(3, referenceVertices, 4, D_00714368, 6);
        mdlEffectEmitTagPair();
        RpSkyRenderStateSet(2, savedTextureState | 0x10);
        if (mdlEffectProjectBillboardQuad(parameters + 4, overlayVertices) != 0) {
            (*setState)(1, D_00922D90[0]);
            RpSkyRenderStateSet(3, 0x31001);
            mdlEffectEmitValuePacket(0x9FC00A | ((s64)0x6FC << 0x20));
            (*sendPacket)(3, overlayVertices, 4, D_00714368, 6);
            mdlEffectEmitSlotPacket();
        }
        (*setState)(1, 0);
        RpSkyRenderStateSet(3, savedBlendState);
        RpSkyRenderStateSet(2, savedTextureState);
    }
}

// Allocates a slot table (up to 100 entries) and initialises each slot through the init helper.
// FUN_004A9AA0
u8 *effBlurFilterAllocSlots(u8 *object) {
    s32 i;
    u8 *alloc;
    u8 *base;
    u32 count;

    base = object + 0xC0;
    if (!(((BlurFilterParameters *)base)->unk00.unsignedValue <= 0x64)) {
        kAssertFail(D_00714380, 0x169);
    }
    count = ((BlurFilterParameters *)base)->unk00.unsignedValue;
    chkmemAllocSiteTag(D_00714380, 0x16F);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        mdlEffectInitRandomQuad(base, item);
        ((BlurFilterSlot *)item)->unk04.scalar = fGpffff80f8;
    }
    return alloc;
}

// Frees a slot table through the engine's free callback.
// FUN_004A9BA0
void effBlurFilterFreeSlots(void *object) {
    (*jtbl_008873EC)(object);
}

// Steps the first slot-list update: refreshes the screen rect and ticks the list with TickSlotsA.
// FUN_004A9BD0
void effBlurFilterStepSlotsA(u8 *object) {
    f32 vec[4];
    s32 effectColor;
    s32 sampledColor;
    s32 combinedColor;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = ((BlurFilterNode *)object)->slots.bytes;
    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    a = ((BlurFilterConfiguration *)obj)->duration;
    if (a == 0) {
        b = 0;
    } else {
        b = ((BlurFilterNode *)object)->elapsed;
    }
    if (a >= b) {
        f = mdlEffectSampleScalarKeys(obj + 0x8C, b, a);
        if (((BlurFilterConfiguration *)obj)->screenSpace != 0) {
            ((BlurFilterParameters *)base)->unk1C.signedValue = 0x43A00000;
            ((BlurFilterParameters *)base)->unk20.signedValue = 0x43600000;
            ((BlurFilterParameters *)base)->unk24.scalar = f;
        } else {
            prod = f * ((BlurFilterNode *)object)->scale.scalar;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(object) : "$vf10", "memory");
            ((BlurFilterParameters *)base)->unk24.scalar = mdlEffectAnchorScreenScale(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            ((BlurFilterParameters *)base)->unk1C.scalar = vec[0];
            ((BlurFilterParameters *)base)->unk20.scalar = vec[1];
        }
        tmp = mdlEffectSamplePackedColor(obj, obj + 0x24, b, a);
        effectColor = ((BlurFilterNode *)object)->color;
        pt = &effectColor;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
((BlurFilterParameters *)base)->unk0C.signedValue = *(volatile s32 *)&combinedColor;
        ((BlurFilterParameters *)base)->unk18.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x34, b, a);
        ((BlurFilterParameters *)base)->unk14.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x60, b, a);
        ((BlurFilterParameters *)base)->unk10.signedValue = ((BlurFilterConfiguration *)obj)->resourceId.signedValue;
        effBlurFilterTickSlotsA(base, list);
    } else {
        ((BlurFilterParameters *)base)->unk0C.signedValue = 0;
    }
}
// Submits every slot with a zero timer and a positive alpha byte to the draw table.
// FUN_004A9DD0
void effBlurFilterSubmitZeroTimerSlots(u8 *object) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 count;
    s32 *table;
    s32 i;

    list = ((BlurFilterNode *)object)->slots.bytes;
    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    if (((BlurFilterConfiguration *)obj)->unkCC.signedValue & 0xFF000000) {
        table = ((BlurFilterRef *)((BlurFilterNode *)object)->reference.bytes)->resource.words;
        count = ((BlurFilterParameters *)base)->unk00.signedValue;
        if (!(count <= 0x64)) {
            kAssertFail(D_00714380, 0x1BA);
        }
        for (i = 0; i < count; i++) {
            if (((BlurFilterSlot *)list)->unk00.signedValue == 0 && ((BlurFilterSlot *)list)->unk0C.byte[3] > 0) {
                mdlEffectDrawProjectedBillboard(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// Allocates a small slot table (up to 40 entries) with zeroed timers and per-index base offsets.
// FUN_004A9EA0
void effBlurFilterAllocSlotsSmall(u8 *object) {
    u8 *base;
    u32 count;
    u8 *alloc;
    s32 i;

    base = object + 0xC0;
    if (!(((BlurFilterParameters *)base)->unk00.unsignedValue <= 0x28)) {
        kAssertFail(D_00714380, 0x292);
    }
    count = ((BlurFilterParameters *)base)->unk00.unsignedValue;
    chkmemAllocSiteTag(D_00714380, 0x298);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        ((BlurFilterSlot *)item)->unk04.signedValue = 0;
        ((BlurFilterSlot *)item)->unk00.signedValue = 0;
        ((BlurFilterSlot *)item)->unk10 = ((BlurFilterConfiguration *)object)->unkD0;
        ((BlurFilterSlot *)item)->unk14 = ((BlurFilterConfiguration *)object)->unkD4;
        ((BlurFilterSlot *)item)->unk00.scalar = -(((BlurFilterConfiguration *)object)->unkC8 * (f32)i);
    }
}

// Frees a small slot table through the engine's free callback.
// FUN_004A9FA0
void effBlurFilterFreeSlotsSmall(void *object) {
    (*jtbl_008873EC)(object);
}

// Steps the third slot-list update: refreshes the screen rect and advances the table with AdvanceSlots.
// FUN_004A9FD0
void effBlurFilterStepSlotsC(u8 *object) {
    f32 vec[4];
    s32 effectColor;
    s32 sampledColor;
    s32 combinedColor;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = ((BlurFilterNode *)object)->slots.bytes;
    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    a = ((BlurFilterConfiguration *)obj)->duration;
    if (a == 0) {
        b = 0;
    } else {
        b = ((BlurFilterNode *)object)->elapsed;
    }
    if (a >= b) {
        f = mdlEffectSampleScalarKeys(obj + 0x8C, b, a);
        if (((BlurFilterConfiguration *)obj)->screenSpace != 0) {
            ((BlurFilterParameters *)base)->unk20.signedValue = 0x43A00000;
            ((BlurFilterParameters *)base)->unk24.signedValue = 0x43600000;
            ((BlurFilterParameters *)base)->unk28.signedValue = (s32)f;
        } else {
            prod = f * ((BlurFilterNode *)object)->scale.scalar;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(object) : "$vf10", "memory");
            ((BlurFilterParameters *)base)->unk28.signedValue = (s32)mdlEffectAnchorScreenScale(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            ((BlurFilterParameters *)base)->unk20.scalar = vec[0];
            ((BlurFilterParameters *)base)->unk24.scalar = vec[1];
        }
        tmp = mdlEffectSamplePackedColor(obj, obj + 0x24, b, a);
        effectColor = ((BlurFilterNode *)object)->color;
        pt = &effectColor;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
((BlurFilterParameters *)base)->unk0C.signedValue = *(volatile s32 *)&combinedColor;
        ((BlurFilterParameters *)base)->unk1C.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x34, b, a);
        ((BlurFilterParameters *)base)->unk14.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x60, b, a);
        ((BlurFilterParameters *)base)->unk10.signedValue = ((BlurFilterConfiguration *)obj)->resourceId.signedValue;
        effBlurFilterAdvanceSlots(base, list);
    } else {
        ((BlurFilterParameters *)base)->unk0C.signedValue = 0;
    }
}

// Submits every slot with a non-negative alpha and a positive alpha byte to the draw table.
// FUN_004AA1F0
void effBlurFilterSubmitActiveSlots(u8 *object) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 *table;
    s32 count;
    s32 i;

    list = ((BlurFilterNode *)object)->slots.bytes;
    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    if (((BlurFilterConfiguration *)obj)->unkCC.signedValue & 0xFF000000) {
        table = ((BlurFilterRef *)((BlurFilterNode *)object)->reference.bytes)->resource.words;
        count = ((BlurFilterParameters *)base)->unk00.signedValue;
        for (i = 0; i < count; i++) {
            if (!(((BlurFilterSlot *)list)->unk00.scalar < 0.0f) && (((BlurFilterSlot *)list)->unk0C.byte[3] > 0)) {
                mdlEffectDrawProjectedBillboard(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// Refreshes the screen-rect block with the simple variant: default constants on first use, no flag-byte update.
// FUN_004AA2B0
void effBlurFilterUpdateScreenRectSimple(u8 *object) {
    s32 effectColor;
    s32 sampledColor;
    s32 combinedColor;
    u8 *base;
    u8 *obj;
    s32 a;
    s32 b;
    s32 tmp;
    s32 *pt;
    f32 scale;

    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    a = ((BlurFilterConfiguration *)obj)->duration;
    if (a == 0) {
        b = 0;
    } else {
        b = ((BlurFilterNode *)object)->elapsed;
    }
    if (b == 0) {
        ((BlurFilterParameters *)base)->unk10.signedValue = 0x43A00000;
        ((BlurFilterParameters *)base)->unk14.signedValue = 0x43600000;
        ((BlurFilterParameters *)base)->unk18.signedValue = 0;
        ((BlurFilterParameters *)base)->unk1C.signedValue = 0;
        ((BlurFilterParameters *)base)->unk20.signedValue = 0x44200000;
        ((BlurFilterParameters *)base)->unk24.signedValue = 0x43E00000;
        ((BlurFilterParameters *)base)->unk04.signedValue = ((BlurFilterConfiguration *)obj)->resourceId.signedValue;
    }
    if (a >= b) {
        tmp = mdlEffectSamplePackedColor(obj, obj + 0x24, b, a);
        effectColor = ((BlurFilterNode *)object)->color;
        pt = &effectColor;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x64($sp)      \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
((BlurFilterParameters *)base)->unk00.signedValue = *(volatile s32 *)&combinedColor;
        ((BlurFilterParameters *)base)->unk0C.scalar = 1.0f + mdlEffectSampleScalarKeys(obj + 0x34, b, a);
        ((BlurFilterParameters *)base)->unk08.scalar = mdlEffectSampleScalarKeys(obj + 0x60, b, a);
    } else {
        ((BlurFilterParameters *)base)->unk00.signedByte[3] = 0;
    }
}

// Draws the overlay pass, bracketed by render-state changes around one slot packet.
// FUN_004AA460
void effBlurFilterDrawOverlay(u8 *object) {
    s32 savedState;
    u8 vertices[0x108];
    void *setState;
    u8 *base;

    base = ((BlurFilterNode *)object)->configuration.bytes + 0xC0;
    if (((BlurFilterConfiguration *)((BlurFilterNode *)object)->configuration.bytes)->unkC0.byte[3] > 0) {
        RpSkyRenderStateGet(3, &savedState);
        mdlEffectBuildOffsetQuad(base, vertices);
        setState = (void *)D_00887300;
        (*(void (**)(u32, u32))setState)(1, D_00922D90[0]);
        RpSkyRenderStateSet(3, 0x31001);
        mdlEffectEmitValuePacket(0x9FC00A | ((s64)0x6FC << 0x20));
        D_00887314[0](3, vertices, 4, D_00714368, 6);
        mdlEffectEmitSlotPacket();
        (*(void (**)(u32, u32))setState)(1, 0);
        RpSkyRenderStateSet(3, savedState);
    }
}
// Allocates a spawn-mode slot table (up to 100 entries) and initialises each slot through SpawnSlot.
// FUN_004AA560
u8 *effBlurFilterAllocSpawnSlots(u8 *object) {
    s32 i;
    u8 *alloc;
    u8 *base;
    u32 count;

    base = object + 0xC0;
    if (!(((BlurFilterParameters *)base)->unk00.unsignedValue <= 0x64)) {
        kAssertFail(D_00714380, 0x218);
    }
    count = ((BlurFilterParameters *)base)->unk00.unsignedValue;
    chkmemAllocSiteTag(D_00714380, 0x21E);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        effBlurFilterSpawnSlot(base, item);
        ((BlurFilterSlot *)item)->unk04.scalar = fGpffff80f8;
    }
    return alloc;
}

// Frees a spawn-mode slot table through the engine's free callback.
// FUN_004AA660
void effBlurFilterFreeSpawnSlots(void *object) {
    (*jtbl_008873EC)(object);
}

// Steps the second slot-list update: refreshes the screen rect and ticks the list with TickSlotsB.
// FUN_004AA690
void effBlurFilterStepSlotsB(u8 *object) {
    f32 vec[4];
    s32 effectColor;
    s32 sampledColor;
    s32 combinedColor;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = ((BlurFilterNode *)object)->slots.bytes;
    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    a = ((BlurFilterConfiguration *)obj)->duration;
    if (a == 0) {
        b = 0;
    } else {
        b = ((BlurFilterNode *)object)->elapsed;
    }
    if (a >= b) {
        f = mdlEffectSampleScalarKeys(obj + 0x8C, b, a);
        if (((BlurFilterConfiguration *)obj)->screenSpace != 0) {
            ((BlurFilterParameters *)base)->unk1C.signedValue = 0x43A00000;
            ((BlurFilterParameters *)base)->unk20.signedValue = 0x43600000;
            ((BlurFilterParameters *)base)->unk24.scalar = f;
        } else {
            prod = f * ((BlurFilterNode *)object)->scale.scalar;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(object) : "$vf10", "memory");
            ((BlurFilterParameters *)base)->unk24.scalar = mdlEffectAnchorScreenScale(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            ((BlurFilterParameters *)base)->unk1C.scalar = vec[0];
            ((BlurFilterParameters *)base)->unk20.scalar = vec[1];
        }
        tmp = mdlEffectSamplePackedColor(obj, obj + 0x24, b, a);
        effectColor = ((BlurFilterNode *)object)->color;
        pt = &effectColor;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
((BlurFilterParameters *)base)->unk0C.signedValue = *(volatile s32 *)&combinedColor;
        ((BlurFilterParameters *)base)->unk18.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x34, b, a);
        ((BlurFilterParameters *)base)->unk14.scalar = fGpffff80f0 * mdlEffectSampleScalarKeys(obj + 0x60, b, a);
        ((BlurFilterParameters *)base)->unk10.signedValue = ((BlurFilterConfiguration *)obj)->resourceId.signedValue;
        effBlurFilterTickSlotsB(base, list);
    } else {
        ((BlurFilterParameters *)base)->unk0C.signedValue = 0;
    }
}

// Submits zero-timer slots after checking the slot count against the 100-entry limit.
// FUN_004AA890
void effBlurFilterSubmitZeroTimerSlotsChecked(u8 *object) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 count;
    s32 *table;
    s32 i;

    list = ((BlurFilterNode *)object)->slots.bytes;
    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    if (((BlurFilterConfiguration *)obj)->unkCC.signedValue & 0xFF000000) {
        table = ((BlurFilterRef *)((BlurFilterNode *)object)->reference.bytes)->resource.words;
        count = ((BlurFilterParameters *)base)->unk00.signedValue;
        if (!(count <= 0x64)) {
            kAssertFail(D_00714380, 0x269);
        }
        for (i = 0; i < count; i++) {
            if (((BlurFilterSlot *)list)->unk00.signedValue == 0 && ((BlurFilterSlot *)list)->unk0C.byte[3] > 0) {
                mdlEffectDrawProjectedBillboard(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// Refreshes the screen-rect block from the defaults on first use, then clears the flag byte at offset 3 when the count is below the threshold.
// FUN_004AA960
void effBlurFilterUpdateScreenRectFlagged(u8 *object) {
    s32 effectColor;
    s32 sampledColor;
    s32 combinedColor;
    u8 *obj;
    u8 *base;
    s32 a;
    s32 b;
    s32 tmp;
    s32 *pt;
    f32 scale;

    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    a = ((BlurFilterConfiguration *)obj)->duration;
    if (a == 0) {
        b = 0;
    } else {
        b = ((BlurFilterNode *)object)->elapsed;
    }
    if (b == 0) {
        ((BlurFilterParameters *)base)->unk08.signedValue = 0;
        ((BlurFilterParameters *)base)->unk0C.signedValue = 0;
        ((BlurFilterParameters *)base)->unk10.signedValue = 0x44200000;
        ((BlurFilterParameters *)base)->unk14.signedValue = 0x43E00000;
        ((BlurFilterParameters *)base)->unk04.signedValue = ((BlurFilterConfiguration *)obj)->resourceId.signedValue;
    }
    if (a >= b) {
        tmp = mdlEffectSamplePackedColor(obj, obj + 0x24, b, a);
        effectColor = ((BlurFilterNode *)object)->color;
        pt = &effectColor;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $3, %1           \n"
            "nop                   \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437F        \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $3, $vf10    \n"
            "ppach $3, $0, $3      \n"
            "ppacb $3, $0, $3      \n"
            "sw $3, 0x34($sp)      \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
((BlurFilterParameters *)base)->unk00.signedValue = *(volatile s32 *)&combinedColor;
    } else {
        ((BlurFilterParameters *)base)->unk00.signedByte[3] = 0;
    }
}
/* Draws the auxiliary quad while preserving the active blend state. */
// FUN_004AAA90
void effBlurFilterDrawAux(u8 *object) {
    s32 savedState;
    u8 vertices[0x108];
    u8 *base;

    base = ((BlurFilterNode *)object)->configuration.bytes + 0xC0;
    if (((BlurFilterConfiguration *)((BlurFilterNode *)object)->configuration.bytes)->unkC0.byte[3] > 0) {
        RpSkyRenderStateGet(3, &savedState);
        mdlEffectBuildDirectRectQuad(base, vertices);
        D_00887300[0](1, 0);
        RpSkyRenderStateSet(3, 0x31001);
        D_00887314[0](3, vertices, 4, D_00714368, 6);
        RpSkyRenderStateSet(3, savedState);
    }
}

// Updates the screen-rect corners from the scale parameter; this variant also writes the corner pairs at offsets 4 and 8.
// FUN_004AAB50
void effBlurFilterUpdateRectFromScaleAux(u8 *object) {
    f32 vec[4];
    s32 effectColor;
    s32 sampledColor;
    s32 combinedColor;
    u8 *base;
    u8 *obj;
    s32 b;
    s32 a;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 g;
    f32 prod;

    obj = ((BlurFilterNode *)object)->configuration.bytes;
    base = obj + 0xC0;
    a = ((BlurFilterConfiguration *)obj)->duration;
    if (a == 0) {
        b = 0;
    } else {
        b = ((BlurFilterNode *)object)->elapsed;
    }
    if (a >= b) {
        f = mdlEffectSampleScalarKeys(obj + 0x8C, b, a);
        if (((BlurFilterConfiguration *)obj)->screenSpace != 0) {
            ((BlurFilterParameters *)base)->unk04.scalar = 320.0f;
            ((BlurFilterParameters *)base)->unk08.scalar = 224.0f;
            ((BlurFilterParameters *)base)->unk14.scalar = 320.0f - f;
            ((BlurFilterParameters *)base)->unk18.scalar = 224.0f - f;
            ((BlurFilterParameters *)base)->unk1C.scalar = 320.0f + f;
            ((BlurFilterParameters *)base)->unk20.scalar = 224.0f + f;
        } else {
            prod = f * ((BlurFilterNode *)object)->scale.scalar;
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(object) : "$vf10", "memory");
            g = mdlEffectAnchorScreenScale(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            ((BlurFilterParameters *)base)->unk04.scalar = vec[0];
            ((BlurFilterParameters *)base)->unk08.scalar = vec[1];
            ((BlurFilterParameters *)base)->unk14.scalar = vec[0] - g;
            ((BlurFilterParameters *)base)->unk18.scalar = vec[1] - g;
            ((BlurFilterParameters *)base)->unk1C.scalar = vec[0] + g;
            ((BlurFilterParameters *)base)->unk20.scalar = vec[1] + g;
        }
        tmp = mdlEffectSamplePackedColor(obj, obj + 0x24, b, a);
        effectColor = ((BlurFilterNode *)object)->color;
        pt = &effectColor;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $3, %1           \n"
            "nop                   \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437F        \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $3, $vf10    \n"
            "ppach $3, $0, $3      \n"
            "ppacb $3, $0, $3      \n"
            "sw $3, 0x74($sp)      \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
((BlurFilterParameters *)base)->unk0C.signedValue = *(volatile s32 *)&combinedColor;
        ((BlurFilterParameters *)base)->unk10.signedValue = ((BlurFilterConfiguration *)obj)->resourceId.signedValue;
    } else {
        ((BlurFilterParameters *)base)->unk0C.signedByte[3] = 0;
    }
}
// Draws the second sky pass, bracketed by render-state changes around one slot packet.
// FUN_004AAD30
void effBlurFilterDrawPassB(u8 *object) {
    s32 savedTextureState;
    s32 savedBlendState;
    u8 referenceVertices[0xFC];
    u8 overlayVertices[0xF8];
    u8 *drawData;
    u8 *parameters;
    u8 *configuration;
    void *setState;

    configuration = ((BlurFilterNode *)object)->configuration.bytes;
    parameters = configuration + 0xC0;
    if (((BlurFilterConfiguration *)configuration)->unkCC.byte[3] > 0) {
        drawData = ((BlurFilterRef *)((BlurFilterNode *)object)->reference.bytes)->resource.bytes;
        RpSkyRenderStateGet(2, &savedTextureState);
        RpSkyRenderStateGet(3, &savedBlendState);
        setState = (void *)D_00887300;
        (*(void (**)(u32, u32))setState)((u32)1, *(u32 *)drawData);
        mdlEffectEmitMaskedTagPair();
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x31001);
        mdlEffectBuildDirectRectQuad(parameters + 0xC, referenceVertices);
        ((BlurSkyVertex *)referenceVertices)[0].uBits = 0;
        ((BlurSkyVertex *)referenceVertices)[0].vBits = 0;
        ((BlurSkyVertex *)referenceVertices)[1].uBits = 0;
        ((BlurSkyVertex *)referenceVertices)[1].vBits = 0x3F800000;
        ((BlurSkyVertex *)referenceVertices)[2].uBits = 0x3F800000;
        ((BlurSkyVertex *)referenceVertices)[2].vBits = 0x3F800000;
        ((BlurSkyVertex *)referenceVertices)[3].uBits = 0x3F800000;
        ((BlurSkyVertex *)referenceVertices)[3].vBits = 0;
        drawData = (u8 *)D_00887314;
        (*(void (**)(s32, void *, s32, void *, s32))drawData)(3, referenceVertices, 4, D_00714368, 6);
        mdlEffectEmitTagPair();
        RpSkyRenderStateSet(2, savedTextureState | 0x10);
        mdlEffectBuildDirectRectQuad(parameters + 0xC, overlayVertices);
        (*((void (**)(u32, u32))setState))(1, 0);
        RpSkyRenderStateSet(3, 0x31001);
        (*(void (**)(s32, void *, s32, void *, s32))drawData)(3, overlayVertices, 4, D_00714368, 6);
        RpSkyRenderStateSet(3, savedBlendState);
        RpSkyRenderStateSet(2, savedTextureState);
    }
}

/* measured: 372B/window 384B; only three zero-padding words remain.
   As in effBlurFilterDirectCreate, the narrowed callback index and one-use header span
   retain 0x60 in the saved constant register. This initializer receives
   the copied-data pointer reloaded from the object, not initialData. */
/* Creates a node whose initializer receives the node's own copy of the parameter block. */
// FUN_004AAEE0
u8 *effBlurFilterCopiedCreate(u32 type, const void *initialData)
{
    s32 (*initialize)(u8 *);
    s32 kind;
    u8 *allocated;
    s32 dataSize;
    u8 *data;
    u8 *object;
    s32 headerBytes = 0x60;
    BlurFilterNode *node;

    /* A separate typed node preserves constructor allocation; access-site casts alone differed by 112 bytes. */
    kind = type & 0xFFFF;
    dataSize = ((BlurFilterSizeEntry *)D_007143A4)[kind].dataBytes;
    if ((u32)dataSize + 0x60 >= 0x200U)
        kAssertFail(D_00714450, 0x170);
    chkmemAllocSiteTag(D_00714450, 0x171);
    allocated = (u8 *)(*jtbl_008873E8)(dataSize + 0x60, 0x40000);
    object = allocated;
    node = (BlurFilterNode *)object;
    memset(object, 0, dataSize + 0x60);
    if (object == (u8 *)0)
        kAssertFail(D_00714380, 0x63B);
    node->kind.signedValue = kind;
    node->color = -1;
    node->scale.signedValue = 0x3F800000;
    node->reference.signedValue = 0;
    __asm__ ("sqc2 vf0, 0(%0)" : : "r"(object) : "memory");
    data = object + headerBytes;
    node->configuration.bytes = data;
    memcpy(data, initialData, dataSize);
    initialize = (s32 (*)(u8 *))((BlurFilterCallbackEntry *)D_00714390)[(u16)type].callback;
    if (initialize != (s32 (*)(u8 *))0)
        node->slots.signedValue = initialize(node->configuration.bytes);
    node->tag = 0x16;
    node->owner = object;
    return object;
}
/* measured: re-measured this wave at nd 4 (2 rows) with a full candidate
   body (separate obj/obj2 locals; rest of function byte-identical). The
   only residual is the pre-jal arg-materialisation order: retail emits
   `daddu $a0,$v0` (bare local) before `lhu $a1,0x1c($s1)` (load); mwcc
   b210 always emits the load first — its complexity rule materialises
   loaded/computed args early, bare locals late. Tried 8 prior spellings
   plus this wave: load hoisted into a local pre-call, load before the
   if-block (nd 24), obj2-first declaration order, s32 obj2 + cast,
   nested-if, #pragma schedule on (nd 46) — all nd 4. Same shape as the
   documented bpc 00245420 floor (retail move-before-load). */
/* Rebuilds a node from a record's parameter block and attaches its texture sub-object. */
// FUN_004AB060
void *effBlurFilterCopiedInstantiate(void *object) {
    s32 sourceData;
    s32 textureData;
    u8 *instance;

    sourceData = (s32)mdlEffectResolveRelPtrA(object);
    if (sourceData == 0) {
        kAssertFail(D_00714380, 0x660);
    }
    instance = (u8 *)effBlurFilterCopiedCreate(((EffSourceDescriptor *)object)->id, (const void *)sourceData);
    if (instance == 0) {
        kAssertFail(D_00714380, 0x662);
    }
    textureData = (s32)mdlEffectResolveRelPtrB(object);
    if ((textureData != 0) && (((BlurFilterFlagEntry *)D_007143A0)[((BlurFilterNode *)instance)->kind.signedValue].usesReference != 0)) {
        ((BlurFilterNode *)instance)->reference.signedValue = (s32)effBlurFilterCreateRefObj((u16 *)textureData, ((EffSourceDescriptor *)object)->kind);
    }
    return instance;
}

/* Rebuilds a node from a record's data pointer and attaches its texture sub-object. */
// FUN_004AB5A0
void *effBlurFilterDirectInstantiate(void *object) {
    u8 *tmp;
    u16 *tex;

    tmp = (u8 *)mdlEffectResolveRelPtrA(object);
    if (tmp == 0) {
        kAssertFail(D_00714380, 0x72B);
    }
    tmp = effBlurFilterDirectCreate(((EffSourceDescriptor *)object)->id, tmp);
    if (tmp == 0) {
        kAssertFail(D_00714380, 0x72D);
    }
    tex = mdlEffectResolveRelPtrB(object);
    if ((tex != 0) && (((BlurFilterFlagEntry *)D_00714470)[((BlurFilterNode *)tmp)->kind.signedValue].usesReference != 0)) {
        ((BlurFilterNode *)tmp)->reference.signedValue = (s32)effBlurFilterCreateRefObj(tex, ((EffSourceDescriptor *)object)->kind);
    }
    return tmp;
}

/* Destroys a node: runs the type's destructor, releases its sub-object, and frees it. */
// FUN_004AB140
void effBlurFilterCopiedDestroy(void *object) {
    if (((BlurFilterNode *)object)->slots.pointer != 0) {
        ((void (*)(void *))(((BlurFilterCallbackEntry *)D_00714394)[((BlurFilterNode *)object)->kind.signedValue].callback))(((BlurFilterNode *)object)->slots.pointer);
    }
    if (((BlurFilterNode *)object)->reference.pointer != 0) {
        effBlurFilterReleaseRefObj(((BlurFilterNode *)object)->reference.pointer);
    }
    (*jtbl_008873EC)(object);
}

/* Duplicates a node from its own type and copied parameter block and takes a reference on its sub-object. */
// FUN_004AB1C0
void *effBlurFilterCopiedDuplicate(void *object) {
    u8 *tmp;

    tmp = effBlurFilterCopiedCreate(((BlurFilterNode *)object)->kind.half[0], ((BlurFilterNode *)object)->configuration.constPointer);
    if ((((BlurFilterNode *)object)->reference.pointer != 0) && (((BlurFilterFlagEntry *)D_007143A0)[((BlurFilterNode *)tmp)->kind.signedValue].usesReference != 0)) {
        ((BlurFilterNode *)tmp)->reference.signedValue = (s32)effBlurFilterRetainRefObj(((BlurFilterNode *)object)->reference.pointer);
    }
    return tmp;
}

/* Clears the step counter at +0x1C. */
// FUN_004AB250
void effBlurFilterCopiedResetCounter(void *object) {
    ((BlurFilterNode *)object)->elapsed = 0;
}

/* Runs the type's update handler, then increments the step counter at +0x1C. */
// FUN_004AB260
void effBlurFilterCopiedAdvance(void *object) {
    ((void (*)(void *))(((BlurFilterCallbackEntry *)D_00714398)[((BlurFilterNode *)object)->kind.signedValue].callback))(object);
    ((BlurFilterNode *)object)->elapsed += 1;
}

/* Calls the type's secondary handler for the node. */
// FUN_004AB2C0
void effBlurFilterCopiedDispatch(void *object) {
    ((void (*)(void *))(((BlurFilterCallbackEntry *)D_0071439C)[((BlurFilterNode *)object)->kind.signedValue].callback))(object);
}

/* When the step counter is positive, resets the sync words at +0x2C/+0x30 and passes the resolved entry to PrimAppendNode. */
// FUN_004AB300
void effBlurFilterCopiedSync(u8 *object) {
    u8 *p;
    if (((BlurFilterNode *)object)->elapsed > 0) {
        p = ((BlurFilterNode *)object)->configuration.bytes;
        ((BlurFilterNode *)object)->nodeNext = 0;
        ((BlurFilterNode *)object)->nodePrevious = 0;
        PrimAppendNode(TnGetOffset38(((BlurFilterConfiguration *)p)->resourceId.half[0]), object + 0x2C);
    }
}
/* Runs the update handler, increments the step counter, and syncs once it is positive. */
// FUN_004AB360
void effBlurFilterCopiedAdvanceAndSync(u8 *object) {
    s32 count;
    u8 *p;
    ((void (*)(void *))(((BlurFilterCallbackEntry *)D_00714398)[((BlurFilterNode *)object)->kind.signedValue].callback))(object);
    count = ((BlurFilterNode *)object)->elapsed + 1;
    ((BlurFilterNode *)object)->elapsed = count;
    if (count > 0) {
        p = ((BlurFilterNode *)object)->configuration.bytes;
        ((BlurFilterNode *)object)->nodeNext = 0;
        ((BlurFilterNode *)object)->nodePrevious = 0;
        PrimAppendNode(TnGetOffset38(((BlurFilterConfiguration *)p)->resourceId.half[0]), object + 0x2C);
    }
}
typedef signed __int128 s128;

/* Copies a 128-bit value into the node's first field and returns it. */
// FUN_004AB3F0
s128 effBlurFilterCopiedStoreVector(void *object, const void *value) {
    s128 temp = *(const s128 *)value;
    *(s128 *)object = temp;
    return temp;
}

/* Stores an s32 at +0x10 of the node. */
// FUN_004AB400
void effBlurFilterCopiedSetCount(void *object, s32 value) {
    ((BlurFilterNode *)object)->color = value;
}

/* Stores an f32 at +0x14 of the node (1.0f from the constructor by default). */
// FUN_004AB410
void effBlurFilterCopiedSetScale(void *object, f32 value) {
    ((BlurFilterNode *)object)->scale.scalar = value;
}

/* measured: 372B/window 384B; only three zero-padding words remain.
   Narrow the callback index with u16 and keep the one-use header span
   named so b210 retains 0x60, not 0xFFFF, in the saved constant register.
   The unsigned size assertion and allocation-before-size declaration
   order preserve the remaining retail allocation and call sequence. */
/* Creates a node whose initializer receives the caller's data pointer rather than a copy. */
// FUN_004AB420
u8 *effBlurFilterDirectCreate(u32 type, const void *initialData)
{
    s32 (*initialize)(const void *);
    s32 kind;
    u8 *allocated;
    s32 dataSize;
    u8 *data;
    u8 *object;
    s32 headerBytes = 0x60;

    kind = type & 0xFFFF;
    dataSize = ((BlurFilterSizeEntry *)D_00714474)[kind].dataBytes;
    if ((u32)dataSize + 0x60 >= 0x200U)
        kAssertFail(D_00714450, 0x170);
    chkmemAllocSiteTag(D_00714450, 0x171);
    allocated = (u8 *)(*jtbl_008873E8)(dataSize + 0x60, 0x40000);
    object = allocated;
    memset(object, 0, dataSize + 0x60);
    if (object == (u8 *)0)
        kAssertFail(D_00714380, 0x706);
    ((BlurFilterNode *)object)->kind.signedValue = kind;
    ((BlurFilterNode *)object)->color = -1;
    ((BlurFilterNode *)object)->scale.signedValue = 0x3F800000;
    ((BlurFilterNode *)object)->reference.signedValue = 0;
    __asm__ ("sqc2 vf0, 0(%0)" : : "r"(object) : "memory");
    data = object + headerBytes;
    ((BlurFilterNode *)object)->configuration.bytes = data;
    memcpy(data, initialData, dataSize);
    initialize = (s32 (*)(const void *))((BlurFilterType *)D_00714460)[(u16)type].initialize;
    if (initialize != (s32 (*)(const void *))0)
        ((BlurFilterNode *)object)->slots.signedValue = initialize(initialData);
    ((BlurFilterNode *)object)->tag = 0x17;
    ((BlurFilterNode *)object)->owner = object;
    return object;
}

/* Destroys a node: runs the type's destructor, releases its sub-object, and frees it. */
// FUN_004AB680
void effBlurFilterDirectDestroy(void *object) {
    if (((BlurFilterNode *)object)->slots.pointer != 0) {
        ((void (*)(void *))(((BlurFilterCallbackEntry *)D_00714464)[((BlurFilterNode *)object)->kind.signedValue].callback))(((BlurFilterNode *)object)->slots.pointer);
    }
    if (((BlurFilterNode *)object)->reference.pointer != 0) {
        effBlurFilterReleaseRefObj(((BlurFilterNode *)object)->reference.pointer);
    }
    (*jtbl_008873EC)(object);
}

/* Duplicates a node from its own type and direct data pointer and takes a reference on its sub-object. */
// FUN_004AB700
void *effBlurFilterDirectDuplicate(void *object) {
    u8 *tmp;

    tmp = effBlurFilterDirectCreate(((BlurFilterNode *)object)->kind.half[0], ((BlurFilterNode *)object)->configuration.constPointer);
    if ((((BlurFilterNode *)object)->reference.pointer != 0) && (((BlurFilterFlagEntry *)D_00714470)[((BlurFilterNode *)tmp)->kind.signedValue].usesReference != 0)) {
        ((BlurFilterNode *)tmp)->reference.signedValue = (s32)effBlurFilterRetainRefObj(((BlurFilterNode *)object)->reference.pointer);
    }
    return tmp;
}

/* Clears the step counter at +0x1C. */
// FUN_004AB790
void effBlurFilterDirectResetCounter(void *object) {
    ((BlurFilterNode *)object)->elapsed = 0;
}

/* Runs the type's update handler, then increments the step counter at +0x1C. */
// FUN_004AB7A0
void effBlurFilterDirectAdvance(void *object) {
    ((void (*)(void *))(((BlurFilterCallbackEntry *)D_00714468)[((BlurFilterNode *)object)->kind.signedValue].callback))(object);
    ((BlurFilterNode *)object)->elapsed += 1;
}

/* Calls the type's secondary handler for the node. */
// FUN_004AB800
void effBlurFilterDirectDispatch(void *object) {
    ((void (*)(void *))(((BlurFilterCallbackEntry *)D_0071446C)[((BlurFilterNode *)object)->kind.signedValue].callback))(object);
}

/* When the step counter is positive, resets the sync words at +0x2C/+0x30 and passes the resolved entry to PrimAppendNode. */
// FUN_004AB840
void effBlurFilterDirectSync(u8 *object) {
    u8 *p;
    if (((BlurFilterNode *)object)->elapsed > 0) {
        p = ((BlurFilterNode *)object)->configuration.bytes;
        ((BlurFilterNode *)object)->nodeNext = 0;
        ((BlurFilterNode *)object)->nodePrevious = 0;
        PrimAppendNode(TnGetOffset38(((BlurFilterConfiguration *)p)->resourceId.half[0]), object + 0x2C);
    }
}
/* Runs the update handler, increments the step counter, and syncs once it is positive. */
// FUN_004AB8A0
void effBlurFilterDirectAdvanceAndSync(u8 *object) {
    s32 count;
    u8 *p;
    ((void (*)(void *))(((BlurFilterCallbackEntry *)D_00714468)[((BlurFilterNode *)object)->kind.signedValue].callback))(object);
    count = ((BlurFilterNode *)object)->elapsed + 1;
    ((BlurFilterNode *)object)->elapsed = count;
    if (count > 0) {
        p = ((BlurFilterNode *)object)->configuration.bytes;
        ((BlurFilterNode *)object)->nodeNext = 0;
        ((BlurFilterNode *)object)->nodePrevious = 0;
        PrimAppendNode(TnGetOffset38(((BlurFilterConfiguration *)p)->resourceId.half[0]), object + 0x2C);
    }
}
/* Copies a 128-bit value into the node's first field and returns it. */
// FUN_004AB930
s128 effBlurFilterDirectStoreVector(void *object, const void *value) {
    s128 temp = *(const s128 *)value;
    *(s128 *)object = temp;
    return temp;
}

/* Stores an s32 at +0x10 of the node. */
// FUN_004AB940
void effBlurFilterDirectSetCount(void *object, s32 value) {
    ((BlurFilterNode *)object)->color = value;
}

/* Stores an f32 at +0x14 of the node (1.0f from the constructor by default). */
// FUN_004AB950
void effBlurFilterDirectSetScale(void *object, f32 value) {
    ((BlurFilterNode *)object)->scale.scalar = value;
}

// Creates a blur resource: type 1 and type 4 resolve their handle through different lookups; other types assert.
// FUN_004AB960
u8 *effBlurFilterCreateRefObj(u16 *object, u16 slot) {
    u8 *tmp;
    s32 t;

    chkmemAllocSiteTag(D_00714450, 0x171);
    tmp = (u8 *)(*jtbl_008873E8)(0xC, 0x40000);
    memset(tmp, 0, 0xC);
    if (tmp == 0) {
        kAssertFail(D_00714380, 0x7B0);
    }
    t = slot & 0xFFFF;
    ((BlurFilterRef *)tmp)->kind = t;
    ((BlurFilterRef *)tmp)->references = 1;
    switch (t) {
    case 1:
        ((BlurFilterRef *)tmp)->resource.signedValue = TnUploadStreamTagged(object);
        break;
    case 4:
        ((BlurFilterRef *)tmp)->resource.signedValue = TnSlotObject(*object);
        break;
    default:
        kAssertFail(D_00714380, 0x7BC);
        break;
    }
    return tmp;
}

// Drops one reference; at zero it releases the handle (unless the type is 4) and frees the block.
// FUN_004ABA70
void effBlurFilterReleaseRefObj(void *object) {
    s32 n;

    if (((BlurFilterRef *)object)->references == 0) {
        kAssertFail(D_00714380, 0x7C5);
    }
    n = ((BlurFilterRef *)object)->references - 1;
    ((BlurFilterRef *)object)->references = n;
    if (n == 0) {
        if (((BlurFilterRef *)object)->kind != 4) {
            func_003ef3a0(((BlurFilterRef *)object)->resource.pointer);
        }
        (*jtbl_008873EC)(object);
    }
}

// Adds one reference to a blur resource; the second word holds the count.
// FUN_004ABB00
void *effBlurFilterRetainRefObj(BlurFilterRef *object) {
    if (object->references == 0) {
        kAssertFail(D_00714380, 0x7D7);
    }
    object->references += 1;
    return object;
}

