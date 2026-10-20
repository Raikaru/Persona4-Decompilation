#include "model_motion_internal.h"
#include "include_asm.h"
/* Original translation unit effModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "member_access.h"
#include "effect_instance_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

/* Same spelling as mdlEffect.c: a 128-bit type makes mwcc emit retail's lq/sq
   quadword copy, with no inline asm. */
typedef unsigned int u_long128 __attribute__((mode(TI)));

/* Work extents are proven by the 0x9C/0xBC constructors and model ID accesses. */
typedef struct MdlDrawableEffect {
    u8 pad0[0xC];
    s32 tint; /* +0xC */
    u8 pad10[0x60];
    s32 firstFrame; /* +0x70 */
    s32 lastFrame; /* +0x74 */
    u8 pad78[0x28];
    u8 visible; /* +0xA0 */
    u8 padA1[0x3];
    union { s32 signedWord; u32 word; } modelFlag; /* +0xA4 */
    u8 padA8[0xC];
    union { u32 word; u8 * bytes; void * pointer; } model; /* +0xB4 */
    union { s8 signedByte; u8 byte; } validFrameRange; /* +0xB8 */
} MdlDrawableEffect;

typedef struct MdlEffectModel {
    u8 pad0[0xD4];
    u16 id; /* +0xD4 */
    u16 subId; /* +0xD6 */
    union { s32 signedWord; u32 word; } flags; /* +0xD8 */
} MdlEffectModel;

typedef struct MdlEffectInstance {
    f32 positionX; /* +0x0 */
    f32 positionY; /* +0x4 */
    f32 positionZ; /* +0x8 */
    u8 padC[0x14];
    f32 scale; /* +0x20 */
    union { f32 scalar; s32 signedWord; } layerWeight; /* +0x24 */
    union { int value0; s32 signedWord; } tint; /* +0x28 */
    u8 pad2C[0x28];
    u16 drawSlot; /* +0x54 */
    u8 pad56[0x36];
    u32 duration; /* +0x8C */
    u8 drawFlags; /* +0x90 */
    u8 pad91[0x3];
    union { u32 word; u8 * bytes; void * pointer; } model; /* +0x94 */
    union { s32 signedWord; u32 word; } elapsed; /* +0x98 */
} MdlEffectInstance;

extern void mdlSetLayerTime(u8 *model, s32 layer, f32 frameValue);

extern void TnInvokeCallback(void);
extern void EffModelResetCallback(void);
extern s32 TnGetOffset1C(s32 slotIndex);
extern void *mdlFindOrCreateModelObject(u32 type, u16 id, u32 flags);
extern void kAssertFail(const char *file, s32 line);
extern void mdlInitIdentityMatrix(void *matrixWords);
extern s32 mdlLayerIsPresent(void *model, s32 layer);
extern void mdlSetLayerWeight(void *model, s32 layer, f32 speed);
extern void mdlSetResetCallback(void *model, void (*callback)(void), void *context);
extern void mdlDestroyModelObject(u32 model);
extern void memcpy(void *destination, void *source, s32 size);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_007144A8[];
extern void EffModelRebindModel(u8 *dst, u8 *src);
extern void EffModelUpdate(s32 drawList, u8 *effect);
extern void EffModelRebindDrawable(u8 *dst, u8 *src);
extern void mdlSetDrawCallback(u8 *model, void (*callback)(u8 *), void *context);
extern void mdlClearAtomicFlags(void *model, s32 flags);
extern void *mdlFindModelObject(u32 type, u16 id, u32 flags);
extern void *mdlCreateModelObjectFromMemory(u32 type, u16 id, void *memory, u32 size, u32 flags);
extern u16 iGpffffbb90; /* next candidate ID for embedded type-six models */
extern char D_007144B8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);



/* Finds the source model by its IDs, resets its transform and layer zero, and installs the effect reset callback. */
// FUN_004ABD80
void *EffModelFindOrCreate(void *effect)
{
    void *work;

    work = mdlFindOrCreateModelObject(((MdlEffectModel *)effect)->id, ((MdlEffectModel *)effect)->subId, 1);
    if (work == 0) {
        kAssertFail(D_007144A8, 0x55);
    }
    mdlInitIdentityMatrix(work);
    if (mdlLayerIsPresent(work, 0) != 0) {
        mdlDispatchAnimIfPresent(work, 0, 0, 0, 0);
        mdlSetLayerWeight(work, 0, 1.0f);
    }
    ((MdlEffectModel *)work)->flags.word &= 0xFFFFFFFD;
    mdlSetResetCallback(work, EffModelResetCallback, work);
    return work;
}

// FUN_004ABE60
void EffModelResetCallback(void) {
    TnInvokeCallback();
}

/* Measured: propagation-off and a staged type preserve constant-first lookup
   arguments with the canonical u32 model-lookup prototype. */
#pragma push
#pragma opt_propagation off
/* Allocates a 0x9C-byte effect and optionally creates its embedded model resource with a free type-six ID. */
// FUN_004ABE80
void *EffModelCreate(void *source) {
    f32 unitWeight;
    s32 resourceSize;
    s32 modelResource;
    u8 *effect;
    u32 lookupType;
    u8 *parameters;
    u8 *model;

    chkmemAllocSiteTag(D_007144B8, 0x171);
    effect = (u8 *)jtbl_008873E8[0](0x9C, 0x40000);
    memset(effect, 0, 0x9C);
    if (effect == NULL) {
        kAssertFail(D_007144A8, 0x73);
    }
    ((MdlEffectInstance *)effect)->elapsed.signedWord = 0;
    ((MdlEffectInstance *)effect)->tint.signedWord = -1;
    unitWeight = 1.0f;
    ((MdlEffectInstance *)effect)->scale = unitWeight;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(effect) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(effect) : "memory");
    if (source != NULL) {
        parameters = mdlEffectResolveRelPtrA(source);
        if (parameters == NULL) {
            kAssertFail(D_007144A8, 0x83);
        }
        memcpy(effect + 0x2C, parameters, 0x68);
        modelResource = (s32)mdlEffectResolveRelPtrB(source);
        if (modelResource != 0) {
            if (((EffSourceDescriptor *)source)->kind != 3) {
                kAssertFail(D_007144A8, 0x8A);
            }
            resourceSize = (s32)((EffSourceDescriptor *)source)->clumpInput;
            while ((lookupType = 6, mdlFindModelObject(lookupType, iGpffffbb90, 0)) != 0) {
                iGpffffbb90 += 1;
            }
            model = mdlCreateModelObjectFromMemory(6, iGpffffbb90, (void *)modelResource, (u32)resourceSize, 1);
            mdlInitIdentityMatrix(model);
            if (mdlLayerIsPresent(model, 0) != 0) {
                mdlDispatchAnimIfPresent(model, 0, 0, 0, 0);
                mdlSetLayerWeight(model, 0, unitWeight);
            }
            ((MdlEffectModel *)model)->flags.word &= ~2U;
            mdlSetResetCallback(model, EffModelResetCallback, model);
            iGpffffbb90 += 1;
            ((MdlEffectInstance *)effect)->model.bytes = model;
        }
    }
    return effect;
}
#pragma pop
/* Destroys the owned model before releasing its effect allocation. */
// FUN_004AC0B0
void EffModelFree(void *effect)
{
    if (((MdlEffectInstance *)effect)->model.pointer != 0) {
        mdlDestroyModelObject(((MdlEffectInstance *)effect)->model.word);
    }
    jtbl_008873EC[0](effect);
}

/* Copies effect parameters and acquires a separate model object for the clone. */
// FUN_004AC100
void *EffModelClone(void *effect)
{
    void *work;

    work = EffModelCreate(0);
    memcpy((u8 *)work + 0x2C, (u8 *)effect + 0x2C, 0x68);
    EffModelRebindModel(work, effect);
    return work;
}

/* Replaces the destination model with a reference acquired from the source model IDs. */
// FUN_004AC170
void EffModelRebindModel(u8 *dst, u8 *src)
{
    /* Earlier whole-layout comparison: 191 differing bytes.
     * Per-access probes retain named MEMBER accesses only where all typed forms differ. */
    void *work;

    if (((MdlEffectInstance *)src)->model.pointer == 0) {
        kAssertFail(D_007144A8, 0xBB);
    }
    if (((MdlEffectInstance *)dst)->model.pointer != 0) {
        mdlDestroyModelObject(((MdlEffectInstance *)dst)->model.word);
    }
    work = mdlFindOrCreateModelObject(((MdlEffectModel *)MEMBER(u32, src, MdlEffectInstance, model.word))->id, ((MdlEffectModel *)MEMBER(u32, src, MdlEffectInstance, model.word))->subId, 0);
    if (work == 0) {
        kAssertFail(D_007144A8, 0xC5);
    }
    mdlInitIdentityMatrix(work);
    if (mdlLayerIsPresent(work, 0) != 0) {
        mdlDispatchAnimIfPresent(work, 0, 0, 0, 0);
        mdlSetLayerWeight(work, 0, 1.0f);
    }
    ((MdlEffectModel *)(u8 *)work)->flags.word &= 0xFFFFFFFD;
    mdlSetResetCallback(work, EffModelResetCallback, work);
    MEMBER(void *, dst, MdlEffectInstance, model.pointer) = work;
}

// FUN_004AC290
void EffModelResetLayerTime(u8 *effect) {
    mdlSetLayerTime(((MdlEffectInstance *)effect)->model.bytes, 0, 0.0f);
}



/* Advances the effect age while its configured duration permits another update. */
// FUN_004AC2C0
void EffModelRollCycle(u32 *effect)
{
    MdlEffectInstance *ageFields3;
    MdlEffectInstance *ageFields4;

    /* Earlier whole-layout comparison: 44 differing bytes.
     * Per-access probes retain named MEMBER accesses only where all typed forms differ. */
  if ((((MdlEffectInstance *)effect)->duration >= ((MdlEffectInstance *)effect)->elapsed.word) || (((MdlEffectInstance *)effect)->duration == 0)) {
    ((MdlEffectInstance *)effect)->layerWeight.scalar = 1.0f;
    (ageFields3 = (MdlEffectInstance *)(effect))->elapsed.word = (ageFields4 = (MdlEffectInstance *)(effect))->elapsed.word + 1;
  }
}



extern void EffModelDrawCallback(u8 *drawable);
extern char D_007144B8[];
extern void mdlSetAlphaBlend(void *model);
extern s32 mdlEffectSamplePackedColor(u8 *colorData, u8 *opacityData, s32 frame, s32 duration);
extern void mdlSetColor(void *model, s32 *color);
extern f32 mdlEffectSampleScalarKeys(void *keys, u32 frame, u32 duration);
extern void mdlEffectBuildBasisRows(void *output, void *orientation);
extern void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp);
extern void mdlScale(void *model, f32 *scale, s32 combineOp);
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
extern void mdlSetAttachedOwner(void *model, s32 owner);
extern s32 TnGetTableBase(void);
extern void mdlQueueModelForDraw(s32 queue, void *model);
extern f32 D_00761134;

/* Samples colour and scale keys, applies the effect transform and layer weight, then queues its model for drawing. */
// FUN_004AC300
void EffModelUpdate(s32 drawList, u8 *effect)
{
    /* Earlier whole-layout comparison: 428 differing bytes.
     * Per-access probes retain named MEMBER accesses only where all typed forms differ. */
    /* VU/MMI packing writes combinedColor via its retail stack slot; retain this order. */
    s32 outputColor;
    s32 tintColor;
    s32 sampledColor;
    s32 combinedColor;
    f32 vector[3];
    u8 matrix[0x40];
    s32 *pt;
    f32 uniformScale;
    f32 keyScale;
    s32 value;
    s32 color;
    u32 elapsed;
    u32 duration;
    u8 *enabledModel;
    u8 *disabledModel;
    f32 scale;

    elapsed = ((MdlEffectInstance *)effect)->elapsed.word;
    duration = ((MdlEffectInstance *)effect)->duration;
    if ((duration >= elapsed) || (duration == 0)) {
        if (duration == 0x4C9) {
            mdlSetAlphaBlend(((MdlEffectInstance *)effect)->model.bytes);
        }
        color = mdlEffectSamplePackedColor(effect + 0x2C, effect + 0x50, elapsed, duration);
        tintColor = ((MdlEffectInstance *)effect)->tint.signedWord;
        pt = &tintColor;
        scale = D_00761134;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10   \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = color;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10   \n"
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
            "sw $2, 176($sp)       \n"
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        outputColor = *(s32 *)&combinedColor;
        mdlSetColor(((MdlEffectInstance *)effect)->model.bytes, &outputColor);
        keyScale = mdlEffectSampleScalarKeys(effect + 0x60, elapsed, duration) / 10.0f;
        mdlEffectBuildBasisRows(matrix, effect + 0x10);
        mdlApplyModelMatrix(MEMBER(u8 *, effect, MdlEffectInstance, model.bytes), matrix, 0);
        uniformScale = ((MdlEffectInstance *)effect)->scale * keyScale;
        vector[2] = uniformScale;
        vector[1] = uniformScale;
        vector[0] = uniformScale;
        mdlScale(MEMBER(u8 *, effect, MdlEffectInstance, model.bytes), vector, 2);
        vector[0] = ((MdlEffectInstance *)effect)->positionX;
        vector[1] = ((MdlEffectInstance *)effect)->positionY;
        vector[2] = ((MdlEffectInstance *)effect)->positionZ;
        mdlTranslateMatrix((RwMatrix *)MEMBER(u8 *, effect, MdlEffectInstance, model.bytes), (const RwV3d *)vector, 2);
        if (((MdlEffectInstance *)effect)->drawFlags != 0) {
            enabledModel = MEMBER(u8 *, effect, MdlEffectInstance, model.bytes);
            ((MdlEffectModel *)enabledModel)->flags.signedWord = ((MdlEffectModel *)enabledModel)->flags.signedWord | 0x18;
        } else {
            disabledModel = MEMBER(u8 *, effect, MdlEffectInstance, model.bytes);
            ((MdlEffectModel *)disabledModel)->flags.signedWord = ((MdlEffectModel *)disabledModel)->flags.signedWord & ~0x18;
        }
        mdlSetLayerWeight(MEMBER(u8 *, effect, MdlEffectInstance, model.bytes), 0, ((MdlEffectInstance *)effect)->layerWeight.scalar);
        mdlSetAttachedOwner(MEMBER(u8 *, effect, MdlEffectInstance, model.bytes), TnGetTableBase());
        mdlQueueModelForDraw(drawList, MEMBER(u8 *, effect, MdlEffectInstance, model.bytes));
        MEMBER(s32, effect, MdlEffectInstance, layerWeight.signedWord) = 0;
    }
}
// FUN_004AC550
void EffModelUpdateByOffset(void *effect)
{
    EffModelUpdate(TnGetOffset1C(((MdlEffectInstance *)effect)->drawSlot), effect);
}

/* Advances the permitted effect age and queues it using its mapped draw-list slot. */
// FUN_004AC590
void EffModelRollAndUpdate(u32 *effect)
{
    MdlEffectInstance *ageFields3;
    MdlEffectInstance *ageFields4;

    /* Earlier whole-layout comparison: 73 differing bytes.
     * Per-access probes retain named MEMBER accesses only where all typed forms differ. */
    if ((((MdlEffectInstance *)effect)->duration >= ((MdlEffectInstance *)effect)->elapsed.word) || (((MdlEffectInstance *)effect)->duration == 0)) {
        ((MdlEffectInstance *)effect)->layerWeight.scalar = 1.0f;
        (ageFields3 = (MdlEffectInstance *)(effect))->elapsed.word = (ageFields4 = (MdlEffectInstance *)(effect))->elapsed.word + 1;
    }
    EffModelUpdate(TnGetOffset1C(((MdlEffectInstance *)effect)->drawSlot), (u8 *)effect);
}

// FUN_004AC600
u_long128 EffModelCopyQuad(u_long128 *dst, u_long128 *src) {
    return *dst = *src;
}

// FUN_004AC610
u_long128 EffModelCopyQuadSecond(u_long128 *dst, u_long128 *src) {
    return dst[1] = *src;
}

// FUN_004AC630
void EffModelSetScale(void *effect, f32 scale)
{
    ((MdlEffectInstance *)effect)->scale = scale;
}

// FUN_004AC620
void EffModelSetLookupIndex(int effect, int packedColor)
{
  ((MdlEffectInstance *)effect)->tint.value0 = packedColor;
}

/* Measured: the same staged lookup type preserves this constructor's call order. */
#pragma push
#pragma opt_propagation off
/* Allocates a 0xBC-byte drawable effect, creates the embedded model and configures its draw callback and frame range. */
// FUN_004AC640
void *EffModelCreateDrawable(void *source) {
    /* Earlier whole-layout comparison: 130 differing bytes.
     * Per-access probes retain named MEMBER accesses only where all typed forms differ. */
    s32 resourceSize;
    s32 modelResource;
    s32 lastFrame;
    s32 firstFrame;
    u8 *effect;
    u32 lookupType;
    u8 *parameters;
    u8 *model;
    u8 *flaggedModel;

    chkmemAllocSiteTag(D_007144B8, 0x171);
    effect = (u8 *)jtbl_008873E8[0](0xBC, 0x40000);
    memset(effect, 0, 0xBC);
    if (effect == NULL) {
        kAssertFail(D_007144A8, 0x18A);
    }
    ((MdlDrawableEffect *)effect)->tint = -1;
    if (source != NULL) {
        parameters = mdlEffectResolveRelPtrA(source);
        if (parameters == NULL) {
            kAssertFail(D_007144A8, 0x196);
        }
        memcpy(effect + 0x10, parameters, 0xA4);
        modelResource = (s32)mdlEffectResolveRelPtrB(source);
        if (modelResource != 0) {
            if (((EffSourceDescriptor *)(u8 *)source)->kind != 3) {
                kAssertFail(D_007144A8, 0x19D);
            }
            resourceSize = ((EffSourceDescriptor *)(u8 *)source)->clumpInput;
            while ((lookupType = 6, mdlFindModelObject(lookupType, iGpffffbb90, 0)) != 0) {
                iGpffffbb90 += 1;
            }
            model = mdlCreateModelObjectFromMemory(6, iGpffffbb90, (void *)modelResource, (u32)resourceSize, 1);
            mdlInitIdentityMatrix(model);
            if (mdlLayerIsPresent(model, 0) != 0) {
                mdlDispatchAnimIfPresent(model, 0, 0, 0, 0);
                mdlSetLayerWeight(model, 0, 1.0f);
            }
            ((MdlEffectModel *)model)->flags.word &= ~2U;
            mdlSetResetCallback(model, EffModelResetCallback, model);
            iGpffffbb90 += 1;
            ((MdlDrawableEffect *)effect)->model.bytes = model;
            mdlSetDrawCallback(model, EffModelDrawCallback, effect);
            if (((MdlDrawableEffect *)effect)->visible == 0) {
                mdlClearAtomicFlags(MEMBER(u8 *, effect, MdlDrawableEffect, model.bytes), 0x20);
            }
            if (((MdlDrawableEffect *)effect)->modelFlag.signedWord != 0) {
                flaggedModel = MEMBER(u8 *, effect, MdlDrawableEffect, model.bytes);
                ((MdlEffectModel *)flaggedModel)->flags.word |= 0x40000;
            }
            firstFrame = ((MdlDrawableEffect *)effect)->firstFrame;
            if ((firstFrame >= 0) && (lastFrame = ((MdlDrawableEffect *)effect)->lastFrame, lastFrame >= 0) && (lastFrame >= firstFrame)) {
                ((MdlDrawableEffect *)effect)->validFrameRange.signedByte = 1;
            } else {
                ((MdlDrawableEffect *)effect)->validFrameRange.signedByte = 0;
            }
        }
    }
    return effect;
}
#pragma pop
/* Destroys the drawable model before releasing its effect allocation. */
// FUN_004AC8E0
void EffModelFreeDrawable(void *effect)
{
    if (((MdlDrawableEffect *)effect)->model.pointer != 0) {
        mdlDestroyModelObject(((MdlDrawableEffect *)effect)->model.word);
    }
    jtbl_008873EC[0](effect);
}

/* Copies drawable parameters and acquires a separate model for the clone. */
// FUN_004AC930
void *EffModelCloneDrawable(void *effect)
{
    void *work;

    work = EffModelCreateDrawable(0);
    memcpy((u8 *)work + 0x10, (u8 *)effect + 0x10, 0xA4);
    EffModelRebindDrawable(work, effect);
    return work;
}

/* Replaces the drawable model by source IDs and reapplies its callback, visibility and frame-range flags. */
// FUN_004AC9A0
void EffModelRebindDrawable(u8 *dst, u8 *src)
{
    MdlDrawableEffect *sourceForModelId;
    MdlDrawableEffect *sourceForModelSubId;

    /* Earlier whole-layout comparison: 294 differing bytes.
     * Per-access probes retain named MEMBER accesses only where all typed forms differ. */
    void *work;

    if (((MdlDrawableEffect *)src)->model.pointer == 0) {
        kAssertFail(D_007144A8, 0x1D0);
    }
    if (((MdlDrawableEffect *)dst)->model.pointer != 0) {
        mdlDestroyModelObject(((MdlDrawableEffect *)dst)->model.word);
    }
    work = mdlFindOrCreateModelObject(((MdlEffectModel *)(sourceForModelId = (MdlDrawableEffect *)(src))->model.word)->id, ((MdlEffectModel *)(sourceForModelSubId = (MdlDrawableEffect *)(src))->model.word)->subId, 0);
    if (work == 0) {
        kAssertFail(D_007144A8, 0x1DA);
    }
    mdlInitIdentityMatrix(work);
    if (mdlLayerIsPresent(work, 0) != 0) {
        mdlDispatchAnimIfPresent(work, 0, 0, 0, 0);
        mdlSetLayerWeight(work, 0, 1.0f);
    }
    ((MdlEffectModel *)(u8 *)work)->flags.word &= 0xFFFFFFFD;
    mdlSetResetCallback(work, EffModelResetCallback, work);
    MEMBER(void *, dst, MdlDrawableEffect, model.pointer) = work;
    mdlSetDrawCallback(work, EffModelDrawCallback, dst);
    if (((MdlDrawableEffect *)dst)->visible == 0) {
        mdlClearAtomicFlags(MEMBER(void *, dst, MdlDrawableEffect, model.pointer), 0x20);
    }
    if (((MdlDrawableEffect *)dst)->modelFlag.word != 0) {
        ((MdlEffectModel *)MEMBER(u32, dst, MdlDrawableEffect, model.word))->flags.word |= 0x40000;
    }
    if ((((MdlDrawableEffect *)dst)->firstFrame >= 0) && (((MdlDrawableEffect *)dst)->lastFrame >= 0) && (((MdlDrawableEffect *)dst)->lastFrame >= ((MdlDrawableEffect *)dst)->firstFrame)) {
        ((MdlDrawableEffect *)dst)->validFrameRange.byte = 1;
    } else {
        ((MdlDrawableEffect *)dst)->validFrameRange.byte = 0;
    }
}
