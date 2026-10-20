/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00124350-0012b940 */

#include "model_motion_internal.h"
typedef signed __int128 s128;

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "byte_address_internal.h"
#include "operand_order_internal.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
#include "mdl_file_internal.h"
#include "rw_camera_internal.h"

/* Unit setting shared by the title-scene callbacks and model renderers. */
#pragma opt_propagation on
extern void PrimDrawFlatRectangle(void *, void *, f32 , s32 );
extern s32 mdlCopyIndexedMatrix(void *, s32 , void *);
extern void mdlApplyModelMatrix(void *, void *, s32 );
extern void titleVisualDrawTintedModel(void *, void *);
extern void titleVisualSubmitRect(f32 x, f32 y, f32 depth, u8 *color, f32 width, f32 height, s32 flags, void *queue);
extern void mdlAdvanceModelFromFlags(void *);
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffb1e8;
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern void sdkListStateConfigure(void *, s32 , s32 , s32 , s32 );
extern void sdkListStateSetSecondaryMasks(void *, s32 , s32 , s32 , s32 );
extern s32 sdkListStateHandleInput(void *);
extern s32 sdkListStateGetCursor(void *);
extern u16 D_008C024E[];
extern void sprintf(void *, const char *, ...);
extern s32 H_Cdvd_LookupRequest(void *, s32 *);
extern void *mdlCreateModelObjectFromMemory(u32 , u16 , void *, u32 , u32 );
extern s32 mdlPrepareModel(void *);
extern u8 D_005E5560[];
extern u8 D_005E5570[];

/* Allocation at titleStartLoader is 0x90 bytes; model slots are 15 words. */
typedef struct TitleScene {
    u8 pad0[0x18];
    s32 complete;
    s32 mode;
    s32 cursor;
    s32 previousCursor;
    s32 cursorFixed;
    u8 pad2C[0xC];
    s32 file;
    s32 sprites;
    s32 unk40;
    u8 *models[15];
    s32 ringFrame;
    u8 pad84[0xC];
} TitleScene;

typedef struct TitleFileWork {
    s32 state;
    s32 request;
    s32 resource;
} TitleFileWork;


extern s32 kwlnTaskIsLinked();
extern void *kwlnTaskGetWork();
extern void kwlnTaskDestroyWithHierarchy();
extern void func_003ef3a0(void *);
extern s32 chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 filerTakeCompletedRequest(s32 , s32 *, s32 );
extern void kAssertFail(const void *file, s32 line);
extern u8 D_005E5548[];
extern u8 D_005E5720[];
extern s32 titleTaskUpdate(u8 *);
extern void titleLoaderTeardown(u8 *unusedTask);
extern void sdkSpritePackDestroy(s32 );
extern void H_Cdvd_Destroy(s32 );
extern void sdkSndStopChannel(s32 );
extern void mdlDestroyModelObject(s32 );
#pragma optimization_level 2
/* Choose a title scene variant using weighted random branches and the global progression value. */
// FUN_00124350
extern u32 RpRandom(void);
s32 titleChooseSceneVariant(u8 *unusedWork)
{
    f32 entryChance;
    f32 groupChance;
    f32 lowChoice;
    f32 rareChance;
    f32 highChoice;
    s32 selection;
    u32 entryRoll;
    u32 groupRoll;
    u32 lowRoll;
    u32 rareRoll;
    u32 highRoll;
    f32 entrySample;
    f32 groupSample;
    f32 lowSample;
    f32 rareSample;
    f32 highSample;
    s32 entryRandom;
    s32 groupRandom;
    s32 lowRandom;
    s32 rareRandom;
    s32 highRandom;

    selection = 0;
    if (iGpffffb1e8 > 1) {
        entryRandom = RpRandom();
        entrySample = (f32)(u32)entryRandom;
        entryChance = 100.0f * (entrySample / 2147483648.0f);
        entryRoll = (u32)entryChance;
        if (entryRoll > 0x3B)
            goto block_second;
    }
block_8:
    selection = 0;
    goto block_end;
block_second:
    groupRandom = RpRandom();
    groupSample = (f32)(u32)groupRandom;
    groupChance = 100.0f * (groupSample / 2147483648.0f);
    groupRoll = (u32)groupChance;
    if (groupRoll < 0x32) {
        lowRandom = RpRandom();
        lowSample = (f32)(u32)lowRandom;
        lowChoice = 3.0f * (lowSample / 2147483648.0f);
        lowRoll = (u32)lowChoice;
        selection = lowRoll + 1;
    } else {
        rareRandom = RpRandom();
        rareSample = (f32)(u32)rareRandom;
        rareChance = 100.0f * (rareSample / 2147483648.0f);
        rareRoll = (u32)rareChance;
        if (rareRoll < 0xA) {
            selection = 7;
        } else if (iGpffffb1e8 >= 0xA) {
            highRandom = RpRandom();
            highSample = (f32)(u32)highRandom;
            highChoice = 3.0f * (highSample / 2147483648.0f);
            highRoll = (u32)highChoice;
            selection = highRoll + 4;
        }
    }
block_end:
    if (selection >= 8) {
        selection = 8;
    }
    return selection + 0xB;
}

#pragma optimization_level 2
/* Request and prepare all fifteen slot models; return nonzero only when all are ready. */
// FUN_001246D0
s32 taskLoadSlotModels(u8 *context)
{
    u32 fileSize;
    u8 filename[0x2C];
    s32 modelIndex;
    s32 ready;
    u8 **modelSlot;

    ready = 1;
    if (context == NULL) {
        kAssertFail(D_005E5548, 0xF4);
    }
    modelIndex = 0;
    goto loop_14;
loop_18:
    modelSlot = &((TitleScene *)context)->models[modelIndex];
    if (*modelSlot == NULL) {
        if (modelIndex < 8) {
            sprintf(filename, (const char *)D_005E5560, modelIndex + 1);
        } else {
            sprintf(filename, (const char *)D_005E5570, modelIndex - 7);
        }
        ready = H_Cdvd_LookupRequest(filename, (s32 *)&fileSize);
        if (ready == 0) {
            kAssertFail(D_005E5548, 0xFE);
        }
        *modelSlot =
            mdlCreateModelObjectFromMemory(9, 0xFF01, (void *)ready, fileSize, 0);
        ready = 0;
    }
    if ((*modelSlot != NULL) &&
        (mdlPrepareModel(*modelSlot) == 0)) {
        ready = 0;
        goto done;
    }
    modelIndex++;
    goto loop_14;
loop_14:
    if (modelIndex < 0xF) {
        goto loop_18;
    }
done:
    return ready;
}

#pragma optimization_level 2
/* Process the three-entry title music selector and retain the previous cursor for animation. */
// FUN_00124830
/* Earlier whole-layout typing probe: TitleScene access changed codegen (nd 229).; access-site and typed-local forms now match. */
s32 titleMusicStreamStep(u8 *context)
{
    u8 listState[0x30];
    s32 previousCursor;
    s32 inputResult;
    s32 cursor;
    s32 confirmed;
    TitleScene *titleScene = (TitleScene *)(context);

    confirmed = 0;
    sdkListStateConfigure(listState, 3, 3, ((TitleScene *)(context))->cursor, 0);
    sdkListStateSetSecondaryMasks(listState, 0x4000, 0x1000, 0, 0);
    inputResult = sdkListStateHandleInput(listState);
    switch (inputResult) {
    case 1:
        confirmed = 1;
        break;
    case 2:
        confirmed = 1;
        break;
    }
    previousCursor = titleScene->cursor;
    cursor = sdkListStateGetCursor(listState);
    titleScene->cursor = cursor;
    if (cursor != previousCursor) {
        ((TitleScene *)(context))->previousCursor = previousCursor;
        ((TitleScene *)(context))->cursorFixed = previousCursor << 16;
    }
    if (D_008C024E[0] & 0x40) {
        sdkSndStartStream(0, 0, 0, 1);
        return titleScene->cursor + 1;
    }
    if (confirmed != 0) {
        sdkSndStartStream(0, 0, 0, 0);
        return 0;
    }
    return -1;
}

#pragma optimization_level 2
/* Attach the companion slot model to frame 0x64, then apply color and draw flags. */
// FUN_00124970
/* Earlier whole-layout typing probe: model flags at +0xD8 changed codegen (nd 229).; access-site and typed-local forms now match. */
void taskPrepareSlotModel(s32 modelIndex, u32 packedColor, s32 flags, u32 *context)
{
    u8 color[4];
    u8 matrix[0x4C];
    u8 *baseCursor;
    u8 *attachedCursor;
    u8 *baseModel;
    u8 *attachedModel;
    MdlFileModel *attachedObject;

    if (modelIndex >= 0xF) {
        baseModel = NULL;
    } else {
        baseCursor = (u8 *)(s32)byteAddressAdd(modelIndex * 4, (u8 *)((s32)context));
        baseModel = baseCursor + 0x44;
        if (mdlPrepareModel(*(u8 **)baseModel) != 0) {
            baseModel = *(u8 **)baseModel;
        } else {
            baseModel = NULL;
        }
    }
    if (baseModel != NULL) {
        if ((modelIndex + 8) >= 0xF) {
            attachedModel = NULL;
        } else {
            attachedCursor = (u8 *)(s32)byteAddressAdd(modelIndex * 4, (u8 *)((s32)context));
            attachedModel = attachedCursor + 0x64;
            if (mdlPrepareModel(*(u8 **)attachedModel) != 0) {
                attachedModel = *(u8 **)attachedModel;
            } else {
                attachedModel = NULL;
            }
        }
        if ((attachedModel != NULL) && (mdlCopyIndexedMatrix(baseModel, 0x64, matrix) != 0)) {
            color[0] = packedColor >> 0x18;
            color[1] = packedColor >> 0x10;
            color[2] = packedColor >> 8;
            color[3] = packedColor;
            mdlApplyModelMatrix(attachedModel, matrix, 0);
            attachedObject = (MdlFileModel *)(attachedModel);
            if (flags & 1) {
                ((MdlFileModel *)(attachedModel))->flags |= 8;
            } else {
                ((MdlFileModel *)(attachedModel))->flags &= ~8;
            }
            if (flags & 2) {
                attachedObject->flags |= 0x10;
            } else {
                attachedObject->flags &= ~0x10;
            }
            if (flags & 0x10) {
                attachedObject->flags |= 0x100000;
            } else {
                attachedObject->flags &= ~0x100000;
            }
            if (flags & 0x40) {
                attachedObject->flags |= 0x40000;
            } else {
                attachedObject->flags &= ~0x40000;
            }
            titleVisualDrawTintedModel(attachedModel, color);
            if (!(flags & 0x10000)) {
                mdlAdvanceModelFromFlags(attachedModel);
            }
        }
    }
}

extern void *RwMatrixRotate(void *m, void *src, f32 angle, s32 mode);
extern void *func_003e4320(void *dst, void *src, void *m);
extern void *RwMatrixScale(void *m, void *v, s32 mode);
extern void *RwMatrixTranslate(void *m, void *v, s32 mode);
extern u8 D_005E55B0[];
extern u8 D_005E55B8[];
extern u8 D_005E55C0[];
extern u8 D_005E55C8[];
extern u8 D_005E55D0[];
extern u8 D_005E55D8[];
typedef struct {
    union { u8 q[8]; struct { s32 xBits, yBits; }; };
    union { f32 f; s32 zBits; };
} TitleAxisPair;

#pragma optimization_level 2
/* Transform, tint and update a title slot model and its companion passes. */
// FUN_00124BB0
/* 956/960 bytes; twenty-five resolved relocations and one zero alignment word. */
/* measured: baseline propagation with initialized/reordered/staged axis snapshots or direct copies leaves at least 15 differing bytes. */
#pragma push
#pragma opt_propagation off
/* Earlier whole-layout typing probe: TitleScene/model fields changed codegen (nd 307).; access-site and typed-local forms now match. */
void titleTransformSlotModel(s32 modelIndex,
                   f32 x, f32 y, f32 z, f32 pitch,
                   f32 yaw, f32 roll,
                   u32 baseColor, u32 highlightColor,
                   f32 scale,
                   s32 flags, u32 *context)
{
    u8 color[4];
    TitleAxisPair yawAxis;
    /* Packed XYZ axes use component 2 for Z; integer stores preserve their float bit patterns. */
    u8 pitchAxis[0x10];
    u8 rollAxis[0x10];
    /* This packed XYZ vector is reused for scale, then translation. */
    u8 transformVector[0x10];
    u8 matrix[0x40];
    u8 *modelCursor;
    u8 *model;
    MdlFileModel *modelObject;

    {
        s64 q = *(s64 *)D_005E55B0;
        f32 f = *(f32 *)D_005E55B8;
        *(s64 *)yawAxis.q = q;
        yawAxis.f = f;
    }
    {
        s64 q = *(s64 *)D_005E55C0;
        f32 f = *(f32 *)D_005E55C8;
        *(s64 *)pitchAxis = q;
        ((TitleAxisPair *)(pitchAxis))->f = f;
    }
    {
        s64 q = *(s64 *)D_005E55D0;
        f32 f = *(f32 *)D_005E55D8;
        *(s64 *)rollAxis = q;
        ((TitleAxisPair *)(rollAxis))->f = f;
    }
    if (modelIndex >= 0xF) {
        model = NULL;
    } else {
        modelCursor = (u8 *)(s32)byteAddressAdd(modelIndex * 4, (u8 *)((s32)context));
        model = modelCursor + 0x44;
        if (mdlPrepareModel(*(u8 **)model) != 0) {
            model = *(u8 **)model;
        } else {
            model = NULL;
        }
    }
    if (model != NULL) {
        ((RwMatrixTag *)(matrix))->atZBits = 0x3F800000;
        ((RwMatrixTag *)(matrix))->upYBits = 0x3F800000;
        ((RwMatrixTag *)(matrix))->rightXBits = 0x3F800000;
        ((RwMatrixTag *)(matrix))->upXBits = 0;
        ((RwMatrixTag *)(matrix))->rightZBits = 0;
        ((RwMatrixTag *)(matrix))->rightYBits = 0;
        ((RwMatrixTag *)(matrix))->atYBits = 0;
        ((RwMatrixTag *)(matrix))->atXBits = 0;
        ((RwMatrixTag *)(matrix))->upZBits = 0;
        ((RwMatrixTag *)(matrix))->posZBits = 0;
        ((RwMatrixTag *)(matrix))->posYBits = 0;
        ((RwMatrixTag *)(matrix))->posXBits = 0;
        ((RwMatrixTag *)(matrix))->flags |= 0x20003;
        RwMatrixRotate(matrix, &yawAxis, yaw, 0);
        ((TitleAxisPair *)(pitchAxis))->xBits = 0x3F800000;
        ((TitleAxisPair *)(pitchAxis))->yBits = 0;
        ((s32 *)pitchAxis)[2] = 0;
        func_003e4320(pitchAxis, pitchAxis, matrix);
        RwMatrixRotate(matrix, pitchAxis, pitch, 2);
        ((TitleAxisPair *)(rollAxis))->xBits = 0;
        ((TitleAxisPair *)(rollAxis))->yBits = 0;
        ((s32 *)rollAxis)[2] = 0x3F800000;
        func_003e4320(rollAxis, rollAxis, matrix);
        RwMatrixRotate(matrix, rollAxis, roll, 2);
        ((RwV3d *)(transformVector))->x = scale;
        ((RwV3d *)(transformVector))->y = scale;
        ((RwV3d *)(transformVector))->z = scale;
        RwMatrixScale(matrix, transformVector, 2);
        ((RwV3d *)(transformVector))->x = x;
        ((f32 *)transformVector)[1] = y;
        ((f32 *)transformVector)[2] = z;
        RwMatrixTranslate(matrix, transformVector, 2);
        mdlApplyModelMatrix(model, matrix, 0);
        modelObject = (MdlFileModel *)(model);
        color[0] = baseColor >> 0x18;
        color[1] = baseColor >> 0x10;
        color[2] = baseColor >> 8;
        color[3] = baseColor;
        if (flags & 1) {
            ((MdlFileModel *)(model))->flags |= 8;
        } else {
            ((MdlFileModel *)(model))->flags &= ~8;
        }
        if (flags & 2) {
            modelObject->flags |= 0x10;
        } else {
            modelObject->flags &= ~0x10;
        }
        if (flags & 0x10) {
            modelObject->flags |= 0x100000;
        } else {
            modelObject->flags &= ~0x100000;
        }
        if (flags & 0x40) {
            modelObject->flags |= 0x40000;
        } else {
            modelObject->flags &= ~0x40000;
        }
        if (!(flags & 0x10000)) {
            mdlAdvanceModelFromFlags(model);
        }
        taskPrepareSlotModel(modelIndex, highlightColor, flags | 2, context);
        titleVisualDrawTintedModel(model, color);
        taskPrepareSlotModel(modelIndex, highlightColor, flags | 1, context);
    }
}
#pragma pop

/* Floor: 844 differing words (was 900), 967 of 964 instrs (+3, +0.3% well inside 3% band, 26 slack to 993 edge; was 993/+29 edge), 932 fnalign edits (was 1077). Surplus was 6 extra clamped float->u8 (cvt.w.s/mfc1 +12, c.ole/sub/bc1t +6, lui +6) from double-converting white via f intermediates + a2; fix is u32 r/g/b for retail's unsigned bltz/srl doubling, a0 as (s32)(f32)*(s32 *) for lwc1/cvt.s.w/cvt.w.s/mfc1, and 5 of 6 f intermediates folded to direct sums (first f0 double retained to center count). Cheap causes ruled out: all literals f-suffixed, 13 jals both with no __ soft-float relocs, no 2.0f in body (mul.s 3/3). Gate 8 inside 0 outside. Body also at docs/probe_archive/Lane0012_00124f70_body.c; production stays ASM. */
/* measured 2026-09-18: reconstructed from bare marker (retail 0x00124F70, 3856B window, 964 instrs). v1c baseline 921 (Ghidra-direct, [6] frame exact at 0x360; [8] gave 0x370 at 922). v2 908 (-13: D_5530/40 array not scalar + 002aaf20 640/448 not 512/480,512/1216). v3 904 (-4: flag beqz polarity + col order + buffers address-ascending). v4 903 (-1: buffers descending, first-declared highest per micro stacktest2). v5 900 (-3: explicit p5234/5230/524C/5248/5244/5240/523C/5238 locals, first two spill to 0xA0/0xB0). Free pragmas tie/worse: loopinv 922 (+1), nounroll 921 tie, sched 921 tie, propoff 943 (+22), commonsubs 940 (+19). 7o eight skipped: body already in 7o form (bare decls + statement assigns, no Type name = ...; initialisers). Full proof in archive. */
/* Title palettes contain six complete four-byte RGBA values. Native value
 * assignment through the byte-storage view preserves the copied object.
 * Measured: 3852/3856 bytes, with one zero alignment word. */

typedef union { f32 value; u8 bytes[4]; } TitleDrawColor;

/* Copy one complete draw color and return its destination storage. */
static inline u8 *titleCopyValue(u8 *destination, const u8 *source)
{
    *(TitleDrawColor *)destination = *(const TitleDrawColor *)source;
    return destination;
}

/* Interpolate an unsigned palette channel and narrow it to a byte. */
static inline u8 titlePaletteChannel(u32 value, u32 target, f32 blend)
{
    return (u8)operandOrderProductAddend((f32)(target - value), blend, (f32)value);
}

typedef union { u32 words[6]; u8 bytes[24]; } TitlePalette;

/* Copy all six palette words in three two-word iterations. */
static inline void titlePaletteCopy(TitlePalette *destination, const TitlePalette *source)
{
    const s32 *src = (const s32 *)source->words;
    s32 *dst = (s32 *)destination->words;
    s32 count = 3;
    do {
        s32 first = src[0];
        s32 second = src[1];
        src += 2;
        count--;
        dst[0] = first;
        dst[1] = second;
        dst += 2;
    } while (count > 0);
}

/* Copy the palette and return the word at the supplied byte offset. */
static inline u32 titleCopySelect(u8 *destination, const u8 *source, s32 byteOffset)
{
    *(TitlePalette *)destination = *(const TitlePalette *)source;
    /* Indexed-word selection changed titleDrawScene (nd 2808); retain the byte offset. */
    return *(u32 *)&((TitlePalette *)destination)->bytes[byteOffset];
}

#pragma push
#pragma optimization_level 2
#pragma always_inline on
/* Draw the title scene model passes and full-screen palette/brightness layers.
 * Packed palette byte members retain the measured copy/selection codegen (indexed words: nd 2808). */
// FUN_00124F70
void titleDrawScene(s32 titleIndex, s32 brightness, s32 unusedArgument, s32 drawMode, u8 *sceneContext)
{
    extern void titleVisualSubmitRect(f32 x, f32 y, f32 depth, u8 *color, f32 width, f32 height, s32 flags, void *queue);
    extern s32 shdSpriteDrawNow(f32 x, f32 y, f32 depth, s32 color, u8 alpha,
        s32 entryId, s32 entryOffset, u8 *pack, s32 flags);
    extern void titleSkyApplyBasePreset(void);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void titleTransformSlotModel(s32 modelIndex, f32 x, f32 y, f32 z,
        f32 pitch, f32 yaw, f32 roll, u32 baseColor, u32 highlightColor,
        f32 scale, s32 flags, u32 *context);
    extern TitlePalette D_005E5530;
    extern u8 D_005E5230[];
    extern u8 D_005E5234[];
    extern u8 D_005E5238[];
    extern u8 D_005E523C[];
    extern u8 D_005E5240[];
    extern u8 D_005E5244[];
    extern u8 D_005E5248[];
    extern u8 D_005E524C[];
    TitlePalette flatRed;
    TitlePalette flatGreen;
    TitlePalette flatBlue;
    TitlePalette flatAlpha;
    TitlePalette shadeRed;
    TitlePalette shadeGreen;
    TitlePalette shadeBlue;
    TitlePalette shadeAlpha;
    TitlePalette opacityRed;
    TitlePalette opacityGreen;
    TitlePalette opacityBlue;
    TitlePalette opacityAlpha;
    TitlePalette firstHighlight;
    TitlePalette firstBase;
    TitlePalette secondHighlight;
    TitlePalette secondBase;
    TitlePalette firstPalette;
    TitlePalette secondPalette;
    TitlePalette flatPalette;
    TitlePalette shadePalette;
    TitlePalette opacityPalette;
    TitleDrawColor color;
    TitleDrawColor zero;
    u8 *clearByte;
    s32 clearCount;
    s32 layoutOffset;
    s32 *paletteSelection;
    s32 paletteOffset;
    u32 packedColor;
    u32 packedBaseColor;
    u32 red;
    u32 green;
    u32 blue;
    u8 *xField;
    u8 *modelIndexField;
    u8 *scaleField;
    u8 *rollField;
    u8 *yawField;
    u8 *pitchField;
    u8 *zField;
    s32 modelFlags;
    (void)unusedArgument;
    if (drawMode != 0) {
        modelFlags = 0;
    } else {
        modelFlags = 0x10000;
    }
    clearByte = zero.bytes;
    clearCount = 4;
    if (clearByte != NULL) {
        do {
            *clearByte = 0;
            clearByte++;
            clearCount--;
        } while (clearCount != 0);
    }
    titleVisualSubmitRect(0.0f, 0.0f, 0.0f, titleCopyValue((u8 *)&color, (const u8 *)&zero), 640.0f, 448.0f, 0x12, NULL);
    /* Each value copy preserves all six RGBA palette entries. */
    firstPalette = D_005E5530;
    titlePaletteCopy(&firstHighlight, &firstPalette);
    layoutOffset = titleIndex * 0x28;
    paletteSelection = (s32 *)(D_005E524C + layoutOffset);
    paletteOffset = *paletteSelection * 4;
    packedColor = *(u32 *)&firstHighlight.bytes[paletteOffset];
    packedBaseColor = titleCopySelect((u8 *)&firstBase, (const u8 *)&firstPalette, paletteOffset);
    scaleField = D_005E5248 + layoutOffset;
    green = (packedColor >> 0x10) & 0xFF;
    red = (packedColor >> 0x18) & 0xFF;
    blue = (packedColor >> 8) & 0xFF;
    rollField = D_005E5244 + layoutOffset;
    yawField = D_005E5240 + layoutOffset;
    pitchField = D_005E523C + layoutOffset;
    zField = D_005E5238 + layoutOffset;
    xField = D_005E5234 + layoutOffset;
    modelIndexField = D_005E5230 + layoutOffset;
    {
        s32 a0 = (s32)(f32)*(s32 *)modelIndexField;
        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
        titleTransformSlotModel(a0, *(f32 *)xField, 0.0f, *(f32 *)zField, *(f32 *)pitchField, *(f32 *)yawField, *(f32 *)rollField, a1, a2, *(f32 *)scaleField, 0x10052, (u32 *)sceneContext);
    }
    secondPalette = D_005E5530;
    titlePaletteCopy(&secondHighlight, &secondPalette);
    paletteOffset = *paletteSelection * 4;
    packedColor = *(u32 *)&secondHighlight.bytes[paletteOffset];
    packedBaseColor = titleCopySelect((u8 *)&secondBase, (const u8 *)&secondPalette, paletteOffset);
    green = (packedColor >> 0x10) & 0xFF;
    red = (packedColor >> 0x18) & 0xFF;
    blue = (packedColor >> 8) & 0xFF;
    {
        s32 a0 = (s32)(f32)*(s32 *)modelIndexField;
        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
        titleTransformSlotModel(a0, *(f32 *)xField, 0.0f, *(f32 *)zField, *(f32 *)pitchField, *(f32 *)yawField, *(f32 *)rollField, a1, a2, *(f32 *)scaleField, modelFlags | 0x12, (u32 *)sceneContext);
    }
    flatPalette = D_005E5530;
    titlePaletteCopy(&flatRed, &flatPalette);
    paletteOffset = *paletteSelection * 4;
    color.bytes[0] = (u8)(*(u32 *)&flatRed.bytes[paletteOffset] >> 0x18);
    color.bytes[1] = (u8)(titleCopySelect((u8 *)&flatGreen, (const u8 *)&flatPalette, paletteOffset) >> 0x10);
    color.bytes[2] = (u8)(titleCopySelect((u8 *)&flatBlue, (const u8 *)&flatPalette, paletteOffset) >> 8);
    color.bytes[3] = (u8)titleCopySelect((u8 *)&flatAlpha, (const u8 *)&flatPalette, paletteOffset);
    color.bytes[0] = (u8)brightness;
    color.bytes[1] = (u8)brightness;
    color.bytes[2] = (u8)brightness;
    titleSkyApplyBasePreset();
    RpSkyRenderStateSet(3, (void *)0x53001);
    RpSkyRenderStateSet(2, (void *)0x52);
    {
        u32 c = brightness & 0xFF;
        u32 rep = (c << 24) | (c << 16) | (c << 8) | 0xFF;
        shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, rep >> 8, 0xFF, 0, 0, (u8 *)(((TitleScene *)sceneContext)->sprites), 0);
    }
    /* Preserve sequential byte stores while applying RGB brightness. */
    shadePalette = D_005E5530;
    titlePaletteCopy(&shadeRed, &shadePalette);
    paletteOffset = *paletteSelection * 4;
    color.bytes[0] = (u8)(*(u32 *)&shadeRed.bytes[paletteOffset] >> 0x18);
    color.bytes[1] = (u8)(titleCopySelect((u8 *)&shadeGreen, (const u8 *)&shadePalette, paletteOffset) >> 0x10);
    color.bytes[2] = (u8)(titleCopySelect((u8 *)&shadeBlue, (const u8 *)&shadePalette, paletteOffset) >> 8);
    color.bytes[3] = (u8)titleCopySelect((u8 *)&shadeAlpha, (const u8 *)&shadePalette, paletteOffset);
    {
        f32 base = (f32)brightness / 255.0f;
        color.bytes[0] = (u8)((f32)color.bytes[0] * base);
        color.bytes[1] = (u8)((f32)color.bytes[1] * base);
        color.bytes[2] = (u8)((f32)color.bytes[2] * base);
    }
    titleSkyApplyBasePreset();
    RpSkyRenderStateSet(3, (void *)0x53001);
    RpSkyRenderStateSet(2, (void *)0x58);
    titleVisualSubmitRect(0.0f, 0.0f, 0.0f, (u8 *)color.bytes, 640.0f, 448.0f, 0x300, NULL);
    /* Retail ORs the full brightness word into the selected color. */
    opacityPalette = D_005E5530;
    titlePaletteCopy(&opacityRed, &opacityPalette);
    paletteOffset = *paletteSelection * 4;
    {
        u32 w0 = *(u32 *)&opacityRed.bytes[paletteOffset];
        color.bytes[0] = (u8)(((u32)brightness | (w0 & 0xFFFFFF00)) >> 0x18);
    }
    {
        u32 w1 = titleCopySelect((u8 *)&opacityGreen, (const u8 *)&opacityPalette, paletteOffset);
        color.bytes[1] = (u8)(((u32)brightness | (w1 & 0xFFFFFF00)) >> 0x10);
    }
    {
        u32 w2 = titleCopySelect((u8 *)&opacityBlue, (const u8 *)&opacityPalette, paletteOffset);
        color.bytes[2] = (u8)(((u32)brightness | (w2 & 0xFFFFFF00)) >> 8);
    }
    {
        u32 w3 = titleCopySelect((u8 *)&opacityAlpha, (const u8 *)&opacityPalette, paletteOffset);
        color.bytes[3] = (u8)((u32)brightness | (w3 & 0xFFFFFF00));
    }
    titleSkyApplyBasePreset();
    titleVisualSubmitRect(0.0f, 0.0f, 1.0f, (u8 *)color.bytes, 640.0f, 448.0f, 1, NULL);
}
#pragma pop

extern s32 shdSpriteDrawNow(f32 , f32 , f32 , s32 , u8 , s32 , s32 , u8 * , s32 );
extern void titleSkyApplyBasePreset(void);
extern s32 RpSkyRenderStateSet(s32 , s32 );
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern s32 D_005E55E0[];
extern s8 D_005E5610[];
extern void (*D_00887300[])(s32 , s32 );
#pragma optimization_level 2
/* Translate six point rows and draw the title backdrop with transformed vertex colors. */
// FUN_00125E80
void titleBuildPointRows(f32 originX, f32 originY, f32 depth, s32 opacity, u8 *context)
{
    u8 clearColor[4];
    PrimPointRow sourcePoints[6];
    s8 colors[0x20];
    PrimPoint points[6];
    s32 *src;
    PrimPointRow *dst;
    s32 count;
    s32 temp1;
    s32 temp2;
    s8 *src8;
    s8 *dst8;
    s32 count8;
    s8 temp8_1;
    s8 temp8_2;
    u8 *p;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    f32 *out;
    PrimPointRow *in;

    src = D_005E55E0;
    dst = sourcePoints;
    count = 6;
    do {
        temp1 = src[0];
        temp2 = src[1];
        src += 2;
        count--;
        dst->words.w0 = temp1;
        dst->words.w1 = temp2;
        dst++;
    } while (count > 0);

    src8 = D_005E5610;
    dst8 = colors;
    count8 = 0xC;
    do {
        temp8_1 = src8[0];
        temp8_2 = src8[1];
        src8 += 2;
        count8--;
        dst8[0] = temp8_1;
        dst8[1] = temp8_2;
        dst8 += 2;
    } while (count8 > 0);

    p = clearColor;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }

    mdlEffectEmitMaskedTagPair();
    shdSpriteDrawNow(0.0f, 0.0f, depth, 0xFFFFFF, opacity & 0xFF, 0x1000D, 0, (u8 *)(((TitleScene *)context)->sprites), 1);
    mdlEffectEmitTagPair();

    i = 0;
    x = -100.0f + originX;
    y = -200.0f + originY;
    while ((u32)i < 6) {
        in = &sourcePoints[i];
        out = points[i].v;
        out[0] = x + in->point.v[0];
        out[1] = y + in->point.v[1];
        i++;
    }

    titleSkyApplyBasePreset();
    D_00887300[0](6, 1);
    RpSkyRenderStateSet(3, 0x5000D);
    RpSkyRenderStateSet(2, 0x58);
    PrimDrawTransformed(colors, points, depth, 6, 4, 0, 0, 0,
                  -20.0f, 1.0f, 1.0f);
}

extern s32 shdSpriteDrawNow(f32 , f32 , f32 , s32 opacity, u8 context, s32 , s32 , u8 *, s32 );
extern s32 shdSpriteDrawNowEx(f32 , f32 , f32 , s32 opacity, u8 context, s32 , s32 , u8 *, s32 ,
                         s16 , s16 , f32 , f32 , f32 );
extern void titleSkyApplyBasePreset(void);
extern s32 RpSkyRenderStateSet(s32 opacity, s32 context);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
typedef struct { u8 c0, c1, c2, c3; } __attribute__((aligned(4))) TitleColor;

typedef struct { s128 bits; } TitleRect;

extern TitleRect D_005E5590;
extern TitleRect D_005E55A0;
/* Draw a scaled ring centered at the supplied screen position. */
static inline void titleRing(f32 x, f32 y, s32 color, f32 scale, f32 angle, u8 *texture)
{
    f32 size = 64.0f * scale;

    shdSpriteDrawNowEx(x - size, y - size, 0.0f, color, 0x80, 0x1000F, 0, texture, 0, (s16)size, (s16)size, angle,
                  scale, scale);
}

#pragma optimization_level 2
/* Draw title shade bars and counter-rotating rings on a 200-frame cycle. */
// FUN_00126090
/* Earlier whole-layout typing probe: TitleScene access changed codegen (nd 663).; access-site and typed-local forms now match. */
void titleDrawShadeBars(f32 x, f32 y, f32 depth, s32 opacity, u8 *context)
{
    TitleColor fillColor;
    TitleColor black;
    TitleColor shade;
    TitleColor clear;
    TitleRect rect;
    TitleRect upper;
    TitleRect lower;
    s32 frame;
    f32 phase;
    f32 angle;
    u8 *p;
    s32 n;
    TitleScene *titleScene = (TitleScene *)(context);

    p = (u8 *)&black;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    fillColor = black;
    titleVisualSubmitRect(0.0f, 0.0f, 0.0f, (u8 *)&fillColor, 640.0f, 480.0f, 0x12, NULL);
    mdlEffectEmitMaskedTagPair();
    shdSpriteDrawNow(0.0f, 0.0f, 0.0f, 0xFFFFFF, opacity & 0xFF, 0x1000C, 0, (u8 *)(((TitleScene *)(context))->sprites), 1);
    mdlEffectEmitTagPair();
    mdlEffectEmitMaskedTagPair();
    p = (u8 *)&clear;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }
    clear.c3 = 0;
    shade = clear;
    upper.bits = D_005E5590.bits;
    rect = upper;
    PrimDrawFlatRectangle(&shade, &rect, 0.0f, 0);
    lower.bits = D_005E55A0.bits;
    rect = lower;
    PrimDrawFlatRectangle(&shade, &rect, 0.0f, 0);
    mdlEffectEmitTagPair();
    frame = ((TitleScene *)(context))->ringFrame + 1;
    ((TitleScene *)(context))->ringFrame = frame;
    if (frame >= 200) {
        titleScene->ringFrame = 0;
    }
    phase = (f32)titleScene->ringFrame / 200.0f;
    titleSkyApplyBasePreset();
    RpSkyRenderStateSet(3, 0x53001);
    RpSkyRenderStateSet(2, 0x58);
    angle = 360.0f * phase;
    titleRing(35.0f, 152.0f, 0x202020, 2.4f, angle, (u8 *)(titleScene->sprites));
    titleRing(233.0f, 102.0f, 0x808080, 1.8f, angle, (u8 *)(titleScene->sprites));
    titleRing(377.0f, 93.0f, 0x808080, 1.4f, angle, (u8 *)(titleScene->sprites));
    titleRing(626.0f, 110.0f, 0x808080, 1.1f, angle, (u8 *)(titleScene->sprites));
    angle = -360.0f * phase;
    titleRing(35.0f, 152.0f, 0x808080, 2.2f, angle, (u8 *)(titleScene->sprites));
    titleRing(233.0f, 102.0f, 0x808080, 1.45f, angle, (u8 *)(titleScene->sprites));
    titleRing(377.0f, 93.0f, 0x808080, 1.0f, angle, (u8 *)(titleScene->sprites));
    titleRing(626.0f, 110.0f, 0x808080, 1.55f, angle, (u8 *)(titleScene->sprites));
}

#include "btl_shuffle_draw_internal.h"
typedef struct Code12FrameVector { f32 x, y, z; } Code12FrameVector;

typedef union Code12FrameVectorTransfer {
    struct { s64 xy; f32 z; } words;
    f32 value[3];
    Code12FrameVector vector;
} Code12FrameVectorTransfer;

#pragma optimization_level 2
/* Release fifteen models, the sprite pack, the file request and the title work. */
// FUN_0012B660
void titleLoaderTeardown(u8 *unusedTask)
{
    u8 *context;
    s32 mode;
    s32 model;
    s32 modelIndex;

    context = kwlnTaskGetWork();
    mode = ((TitleScene *)context)->mode;
    switch (mode) {
    case 2:
        break;
    case 3:
        if ((s64)(s16)datGetDateIndex() == 9 &&
            (datGetTimeSlot() & 0xFF) == 5) {
            break;
        }
        goto error;
    default:
error:
        sdkSndStopChannel(0x1E);
        break;
    }
    modelIndex = 0;
    goto loop_10_test;
loop_10_body:
    model = (s32)((TitleScene *)context)->models[modelIndex];
    if (model != 0) {
        mdlDestroyModelObject(model);
    }
    modelIndex += 1;
loop_10_test:
    if (modelIndex < 0xF) {
        goto loop_10_body;
    }
    sdkSpritePackDestroy(((TitleScene *)context)->sprites);
    H_Cdvd_Destroy(((TitleScene *)context)->file);
    jtbl_008873EC[0](context);
}

#pragma optimization_level 2
/* Allocate the 0x90-byte title work and register its loader callbacks. */
// FUN_0012B760
s32 titleStartLoader(void)
{
    u8 *context;
    chkmemAllocSiteTag(D_005E5548, 0x728);
    context = D_008873F4[0](1, 0x90, 0x40000);
    if (context == NULL)
        kAssertFail(D_005E5548, 0x729);
    ((TitleScene *)context)->complete = 0;
    kwlnTaskCreate((const void *)(D_005E5720), 0xF, 0, 0, titleTaskUpdate, titleLoaderTeardown, (u8 *)(context));
}

#pragma optimization_level 2
/* Destroy a linked loader once its completion word is nonzero; return that word. */
// FUN_0012B810
s32 titleLoaderReap(s32 task)
{
    TitleScene *context;

    if ((task == 0) || (kwlnTaskIsLinked() == 0)) {
        return -1;
    }
    context = (TitleScene *)(kwlnTaskGetWork(task));
    if (context->complete != 0) {
        kwlnTaskDestroyWithHierarchy(task);
    }
    return context->complete;
}

#pragma optimization_level 2
/* Advance the asynchronous file request and keep its resource until destruction. */
// FUN_0012B890
/* Earlier whole-layout typing probe: TitleFileWork access changed codegen (nd 116).; access-site and typed-local forms now match. */
s32 titleFileLoadStep(u8 *unusedTask)
{
    s32 complete;
    u8 *work;
    s32 state;
    TitleFileWork *fileWork;
    work = (u8 *)kwlnTaskGetWork();
    fileWork = (TitleFileWork *)(work);
    state = ((TitleFileWork *)(work))->state;
    switch (state) {
    case 0:
        ((TitleFileWork *)(work))->state = 1;
    case 1:
        ((TitleFileWork *)(work))->state = 2;
    case 2:
        ((TitleFileWork *)(work))->resource = filerTakeCompletedRequest(((TitleFileWork *)(work))->request, &complete, 0);
        if (complete != 0) {
            ((TitleFileWork *)(work))->state = 3;
            fileWork->request = 0;
        }
        break;
    case 3:
        break;
    }
    return 0;
}

#pragma optimization_level 2
/* Release a loaded resource, if present, then free the file task work. */
// FUN_0012B940
void titleLoaderDestroy(u8 *unusedTask) {
    u8 *work;
    s32 resource;

    work = kwlnTaskGetWork();
    resource = ((TitleFileWork *)work)->resource;
    if (resource != 0) {
        func_003ef3a0((void *)resource);
    }
    jtbl_008873EC[0](work);
}
