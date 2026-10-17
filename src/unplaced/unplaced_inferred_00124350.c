/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00124350-0012b940 */

#include "model_motion_internal.h"
typedef signed __int128 s128;

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern void PrimDrawFlatRectangle(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern s32 mdlCopyIndexedMatrix(void *arg0, s32 arg1, void *arg2);
extern void mdlApplyModelMatrix(void *arg0, void *arg1, s32 arg2);
extern void func_002ab550(void *arg0, void *arg1);
extern void mdlAdvanceModelFromFlags(void *arg0);
static inline s32 code1_0012_stride(s32 index, s32 base)
{
    return index + base;
}

extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffb1e8;
extern s64 datGetDateIndex(void);
extern s32 datGetTimeSlot(void);
extern void sdkListStateConfigure(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void sdkListStateSetSecondaryMasks(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 sdkListStateHandleInput(void *arg0);
extern s32 sdkListStateGetCursor(void *arg0);
extern u16 D_008C024E[];
extern void sprintf(void *arg0, const char *arg1, ...);
extern s32 H_Cdvd_LookupRequest(void *arg0, s32 *arg1);
extern void *mdlCreateModelObjectFromMemory(u32 arg0, u16 arg1, void *arg2, u32 arg3, u32 arg4);
extern s32 mdlPrepareModel(void *arg0);
extern u8 D_005E5560[];
extern u8 D_005E5570[];
typedef struct {
    u8 pad0[0x18];
    s32 field_18;
} B810Obj;

extern s32 kwlnTaskIsLinked();
extern void *kwlnTaskGetWork();
extern void kwlnTaskDestroyWithHierarchy();
extern void func_003ef3a0(void *arg0);
extern s32 chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 func_004669d0(s32 arg0, s32 *arg1, s32 arg2);
extern void kAssertFail(const void *file, s32 line);
extern u8 D_005E5548[];
extern u8 D_005E5720[];
extern s32 func_0012aa70(u8 *arg0);
extern void titleLoaderTeardown(u8 *task);
extern void sdkSpritePackDestroy(s32 arg0);
extern void H_Cdvd_Destroy(s32 arg0);
extern void sdkSndStopChannel(s32 arg0);
extern void mdlDestroyModelObject(s32 arg0);
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00124350
extern u32 RpRandom(void);
s32 func_00124350(u8 *unusedWork)
{
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    s32 var_16;
    u32 var_3;
    u32 var_3_2;
    u32 var_3_3;
    u32 var_3_4;
    u32 var_3_5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;

    var_16 = 0;
    if (iGpffffb1e8 > 1) {
        temp_2 = RpRandom();
        var_f0 = (f32)(u32)temp_2;
        temp_f0 = 100.0f * (var_f0 / 2147483648.0f);
        var_3 = (u32)temp_f0;
        if (var_3 > 0x3B)
            goto block_second;
    }
block_8:
    var_16 = 0;
    goto block_end;
block_second:
    temp_2_2 = RpRandom();
    var_f0_2 = (f32)(u32)temp_2_2;
    temp_f0_2 = 100.0f * (var_f0_2 / 2147483648.0f);
    var_3_2 = (u32)temp_f0_2;
    if (var_3_2 < 0x32) {
        temp_2_3 = RpRandom();
        var_f0_3 = (f32)(u32)temp_2_3;
        temp_f0_3 = 3.0f * (var_f0_3 / 2147483648.0f);
        var_3_3 = (u32)temp_f0_3;
        var_16 = var_3_3 + 1;
    } else {
        temp_2_4 = RpRandom();
        var_f0_4 = (f32)(u32)temp_2_4;
        temp_f0_4 = 100.0f * (var_f0_4 / 2147483648.0f);
        var_3_4 = (u32)temp_f0_4;
        if (var_3_4 < 0xA) {
            var_16 = 7;
        } else if (iGpffffb1e8 >= 0xA) {
            temp_2_5 = RpRandom();
            var_f0_5 = (f32)(u32)temp_2_5;
            temp_f0_5 = 3.0f * (var_f0_5 / 2147483648.0f);
            var_3_5 = (u32)temp_f0_5;
            var_16 = var_3_5 + 4;
        }
    }
block_end:
    if (var_16 >= 8) {
        var_16 = 8;
    }
    return var_16 + 0xB;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_001246D0
s32 taskLoadSlotModels(u8 *arg0)
{
    u32 sp7C;
    u8 sp50[0x2C];
    s32 var_16;
    s32 var_17;
    u8 *temp_2;
    u8 *temp_4;

    var_17 = 1;
    if (arg0 == NULL) {
        kAssertFail(D_005E5548, 0xF4);
    }
    var_16 = 0;
    goto loop_14;
loop_18:
    temp_2 = arg0 + (var_16 * 4);
    temp_4 = temp_2 + 0x44;
    if (*(u8 **)temp_4 == NULL) {
        if (var_16 < 8) {
            sprintf(sp50, (const char *)D_005E5560, var_16 + 1);
        } else {
            sprintf(sp50, (const char *)D_005E5570, var_16 - 7);
        }
        var_17 = H_Cdvd_LookupRequest(sp50, (s32 *)&sp7C);
        if (var_17 == 0) {
            kAssertFail(D_005E5548, 0xFE);
        }
        *(u8 **)temp_4 =
            mdlCreateModelObjectFromMemory(9, 0xFF01, (void *)var_17, sp7C, 0);
        var_17 = 0;
    }
    if ((*(u8 **)temp_4 != NULL) &&
        (mdlPrepareModel(*(u8 **)temp_4) == 0)) {
        var_17 = 0;
        goto done;
    }
    var_16++;
    goto loop_14;
loop_14:
    if (var_16 < 0xF) {
        goto loop_18;
    }
done:
    return var_17;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00124830
s32 titleMusicStreamStep(u8 *arg0)
{
    u8 sp40[0x30];
    s32 temp_18;
    s32 temp_2;
    s32 temp_2_2;
    s32 var_16;

    var_16 = 0;
    sdkListStateConfigure(sp40, 3, 3, *(s32 *)(arg0 + 0x20), 0);
    sdkListStateSetSecondaryMasks(sp40, 0x4000, 0x1000, 0, 0);
    temp_2 = sdkListStateHandleInput(sp40);
    switch (temp_2) {
    case 1:
        var_16 = 1;
        break;
    case 2:
        var_16 = 1;
        break;
    }
    temp_18 = *(s32 *)(arg0 + 0x20);
    temp_2_2 = sdkListStateGetCursor(sp40);
    *(s32 *)(arg0 + 0x20) = temp_2_2;
    if (temp_2_2 != temp_18) {
        *(s32 *)(arg0 + 0x24) = temp_18;
        *(s32 *)(arg0 + 0x28) = temp_18 << 16;
    }
    if (D_008C024E[0] & 0x40) {
        sdkSndStartStream(0, 0, 0, 1);
        return *(s32 *)(arg0 + 0x20) + 1;
    }
    if (var_16 != 0) {
        sdkSndStartStream(0, 0, 0, 0);
        return 0;
    }
    return -1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00124970
void taskPrepareSlotModel(s32 arg0, u32 arg1, s32 arg2, u32 *arg3)
{
    u8 spAC[4];
    u8 sp60[0x4C];
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *var_17;
    u8 *var_16;

    if (arg0 >= 0xF) {
        var_17 = NULL;
    } else {
        temp_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg3);
        var_17 = temp_2 + 0x44;
        if (mdlPrepareModel(*(u8 **)var_17) != 0) {
            var_17 = *(u8 **)var_17;
        } else {
            var_17 = NULL;
        }
    }
    if (var_17 != NULL) {
        if ((arg0 + 8) >= 0xF) {
            var_16 = NULL;
        } else {
            temp_2_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg3);
            var_16 = temp_2_2 + 0x64;
            if (mdlPrepareModel(*(u8 **)var_16) != 0) {
                var_16 = *(u8 **)var_16;
            } else {
                var_16 = NULL;
            }
        }
        if ((var_16 != NULL) && (mdlCopyIndexedMatrix(var_17, 0x64, sp60) != 0)) {
            spAC[0] = arg1 >> 0x18;
            spAC[1] = arg1 >> 0x10;
            spAC[2] = arg1 >> 8;
            spAC[3] = arg1;
            mdlApplyModelMatrix(var_16, sp60, 0);
            if (arg2 & 1) {
                *(s32 *)(var_16 + 0xD8) |= 8;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~8;
            }
            if (arg2 & 2) {
                *(s32 *)(var_16 + 0xD8) |= 0x10;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x10;
            }
            if (arg2 & 0x10) {
                *(s32 *)(var_16 + 0xD8) |= 0x100000;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x100000;
            }
            if (arg2 & 0x40) {
                *(s32 *)(var_16 + 0xD8) |= 0x40000;
            } else {
                *(s32 *)(var_16 + 0xD8) &= ~0x40000;
            }
            func_002ab550(var_16, spAC);
            if (!(arg2 & 0x10000)) {
                mdlAdvanceModelFromFlags(var_16);
            }
        }
    }
}
#pragma pop

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
    u8 q[8];
    f32 f;
} Code1GlobalPair12;

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00124BB0
/* 956/960 bytes; twenty-five resolved relocations and one zero alignment word. */
#pragma push
#pragma opt_propagation off
void func_00124bb0(s32 arg0,
                   f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                   f32 fparg4, f32 fparg5,
                   u32 arg1, u32 arg2,
                   f32 fparg6,
                   s32 arg3, u32 *arg4)
{
    u8 color[4];
    Code1GlobalPair12 global_pair;
    u8 vec_f[0x10];
    u8 vec_e[0x10];
    u8 vec_d[0x10];
    u8 matrix[0x40];
    u8 *temp_2;
    u8 *var_16;

    {
        s64 q = *(s64 *)D_005E55B0;
        f32 f = *(f32 *)D_005E55B8;
        *(s64 *)global_pair.q = q;
        global_pair.f = f;
    }
    {
        s64 q = *(s64 *)D_005E55C0;
        f32 f = *(f32 *)D_005E55C8;
        *(s64 *)vec_f = q;
        *(f32 *)(vec_f + 8) = f;
    }
    {
        s64 q = *(s64 *)D_005E55D0;
        f32 f = *(f32 *)D_005E55D8;
        *(s64 *)vec_e = q;
        *(f32 *)(vec_e + 8) = f;
    }
    if (arg0 >= 0xF) {
        var_16 = NULL;
    } else {
        temp_2 = (u8 *)code1_0012_stride(arg0 * 4, (s32)arg4);
        var_16 = temp_2 + 0x44;
        if (mdlPrepareModel(*(u8 **)var_16) != 0) {
            var_16 = *(u8 **)var_16;
        } else {
            var_16 = NULL;
        }
    }
    if (var_16 != NULL) {
        *(s32 *)(matrix + 0x28) = 0x3F800000;
        *(s32 *)(matrix + 0x14) = 0x3F800000;
        *(s32 *)(matrix + 0x00) = 0x3F800000;
        *(s32 *)(matrix + 0x10) = 0;
        *(s32 *)(matrix + 0x08) = 0;
        *(s32 *)(matrix + 0x04) = 0;
        *(s32 *)(matrix + 0x24) = 0;
        *(s32 *)(matrix + 0x20) = 0;
        *(s32 *)(matrix + 0x18) = 0;
        *(s32 *)(matrix + 0x38) = 0;
        *(s32 *)(matrix + 0x34) = 0;
        *(s32 *)(matrix + 0x30) = 0;
        *(s32 *)(matrix + 0x0C) |= 0x20003;
        RwMatrixRotate(matrix, &global_pair, fparg4, 0);
        *(s32 *)(vec_f + 0x00) = 0x3F800000;
        *(s32 *)(vec_f + 0x04) = 0;
        *(s32 *)(vec_f + 0x08) = 0;
        func_003e4320(vec_f, vec_f, matrix);
        RwMatrixRotate(matrix, vec_f, fparg3, 2);
        *(s32 *)(vec_e + 0x00) = 0;
        *(s32 *)(vec_e + 0x04) = 0;
        *(s32 *)(vec_e + 0x08) = 0x3F800000;
        func_003e4320(vec_e, vec_e, matrix);
        RwMatrixRotate(matrix, vec_e, fparg5, 2);
        *(f32 *)(vec_d + 0x00) = fparg6;
        *(f32 *)(vec_d + 0x04) = fparg6;
        *(f32 *)(vec_d + 0x08) = fparg6;
        RwMatrixScale(matrix, vec_d, 2);
        *(f32 *)(vec_d + 0x00) = fparg0;
        *(f32 *)(vec_d + 0x04) = fparg1;
        *(f32 *)(vec_d + 0x08) = fparg2;
        RwMatrixTranslate(matrix, vec_d, 2);
        mdlApplyModelMatrix(var_16, matrix, 0);
        color[0] = arg1 >> 0x18;
        color[1] = arg1 >> 0x10;
        color[2] = arg1 >> 8;
        color[3] = arg1;
        if (arg3 & 1) {
            *(s32 *)(var_16 + 0xD8) |= 8;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~8;
        }
        if (arg3 & 2) {
            *(s32 *)(var_16 + 0xD8) |= 0x10;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x10;
        }
        if (arg3 & 0x10) {
            *(s32 *)(var_16 + 0xD8) |= 0x100000;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x100000;
        }
        if (arg3 & 0x40) {
            *(s32 *)(var_16 + 0xD8) |= 0x40000;
        } else {
            *(s32 *)(var_16 + 0xD8) &= ~0x40000;
        }
        if (!(arg3 & 0x10000)) {
            mdlAdvanceModelFromFlags(var_16);
        }
        taskPrepareSlotModel(arg0, arg2, arg3 | 2, arg4);
        func_002ab550(var_16, color);
        taskPrepareSlotModel(arg0, arg2, arg3 | 1, arg4);
    }
}
#pragma pop
#pragma pop

/* Floor: 844 differing words (was 900), 967 of 964 instrs (+3, +0.3% well inside 3% band, 26 slack to 993 edge; was 993/+29 edge), 932 fnalign edits (was 1077). Surplus was 6 extra clamped float->u8 (cvt.w.s/mfc1 +12, c.ole/sub/bc1t +6, lui +6) from double-converting white via f intermediates + a2; fix is u32 r/g/b for retail's unsigned bltz/srl doubling, a0 as (s32)(f32)*(s32 *) for lwc1/cvt.s.w/cvt.w.s/mfc1, and 5 of 6 f intermediates folded to direct sums (first f0 double retained to center count). Cheap causes ruled out: all literals f-suffixed, 13 jals both with no __ soft-float relocs, no 2.0f in body (mul.s 3/3). Gate 8 inside 0 outside. Body also at docs/probe_archive/Lane0012_00124f70_body.c; production stays ASM. */
/* measured 2026-09-18: reconstructed from bare marker (retail 0x00124F70, 3856B window, 964 instrs). v1c baseline 921 (Ghidra-direct, [6] frame exact at 0x360; [8] gave 0x370 at 922). v2 908 (-13: D_5530/40 array not scalar + 002aaf20 640/448 not 512/480,512/1216). v3 904 (-4: flag beqz polarity + col order + buffers address-ascending). v4 903 (-1: buffers descending, first-declared highest per micro stacktest2). v5 900 (-3: explicit p5234/5230/524C/5248/5244/5240/523C/5238 locals, first two spill to 0xA0/0xB0). Free pragmas tie/worse: loopinv 922 (+1), nounroll 921 tie, sched 921 tie, propoff 943 (+22), commonsubs 940 (+19). 7o eight skipped: body already in 7o form (bare decls + statement assigns, no Type name = ...; initialisers). Full proof in archive. */
/* Title palettes contain six complete four-byte RGBA values. Native value
 * assignment through the byte-storage view preserves the copied object.
 * Measured: 3852/3856 bytes, with one zero alignment word. */

typedef union { f32 value; u8 bytes[4]; } TitleDrawColor;

static inline u8 *titleCopyValue(u8 *destination, const u8 *source)
{
    *(TitleDrawColor *)destination = *(const TitleDrawColor *)source;
    return destination;
}

static inline void titleRectangle(u8 *color, f32 x, f32 y, f32 depth, f32 width, f32 height, s32 flags, void *parent)
{
    extern void func_002aaf20(f32 x, f32 y, f32 depth, u8 *color, f32 width, f32 height, s32 flags, void *parent);
    func_002aaf20(x, y, depth, color, width, height, flags, parent);
}

static inline f32 titleBlend(f32 delta, f32 blend, f32 value)
{
    return value + delta * blend;
}

static inline u8 titlePaletteChannel(u32 value, u32 target, f32 blend)
{
    return (u8)titleBlend((f32)(target - value), blend, (f32)value);
}

typedef struct { u32 words[6]; } TitlePalette;

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

static inline u32 titleCopySelect(u8 *destination, const u8 *source, s32 byteOffset)
{
    *(TitlePalette *)destination = *(const TitlePalette *)source;
    return *(u32 *)(destination + byteOffset);
}

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma always_inline on
// FUN_00124F70
void titleDrawScene(s32 titleIndex, s32 brightness, s32 unusedArgument, s32 drawMode, u8 *sceneContext)
{
    extern void func_002aaf20(f32 x, f32 y, f32 depth, u8 *color, f32 width, f32 height, s32 flags, void *parent);
    extern s32 shdSpriteDrawNow(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha,
        s32 spriteIndex, s32 frame, u8 *sprites, s32 flags);
    extern void titleSkyApplyBasePreset(void);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void func_00124bb0(s32 modelIndex, f32 x, f32 y, f32 z,
        f32 pitch, f32 yaw, f32 roll, u32 baseColor, u32 highlightColor,
        f32 scale, s32 flags, u32 *models);
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
    titleRectangle(titleCopyValue((u8 *)&color, (const u8 *)&zero), 0.0f, 0.0f, 0.0f, 640.0f, 448.0f, 0x12, NULL);
    /* Each value copy preserves all six RGBA palette entries. */
    firstPalette = D_005E5530;
    titlePaletteCopy(&firstHighlight, &firstPalette);
    layoutOffset = titleIndex * 0x28;
    paletteSelection = (s32 *)(D_005E524C + layoutOffset);
    paletteOffset = *paletteSelection * 4;
    packedColor = *(u32 *)((u8 *)firstHighlight.words + paletteOffset);
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
        func_00124bb0(a0, *(f32 *)xField, 0.0f, *(f32 *)zField, *(f32 *)pitchField, *(f32 *)yawField, *(f32 *)rollField, a1, a2, *(f32 *)scaleField, 0x10052, (u32 *)sceneContext);
    }
    secondPalette = D_005E5530;
    titlePaletteCopy(&secondHighlight, &secondPalette);
    paletteOffset = *paletteSelection * 4;
    packedColor = *(u32 *)((u8 *)secondHighlight.words + paletteOffset);
    packedBaseColor = titleCopySelect((u8 *)&secondBase, (const u8 *)&secondPalette, paletteOffset);
    green = (packedColor >> 0x10) & 0xFF;
    red = (packedColor >> 0x18) & 0xFF;
    blue = (packedColor >> 8) & 0xFF;
    {
        s32 a0 = (s32)(f32)*(s32 *)modelIndexField;
        u32 a1 = (packedBaseColor & 0xFFFFFF00) | 0xFF;
        u32 a2 = ((u32)titlePaletteChannel(red, 0xFF, 1.0f) << 0x18) | ((u32)titlePaletteChannel(green, 0xFF, 1.0f) << 0x10) | ((u32)titlePaletteChannel(blue, 0xFF, 1.0f) << 8) | 0xFF;
        func_00124bb0(a0, *(f32 *)xField, 0.0f, *(f32 *)zField, *(f32 *)pitchField, *(f32 *)yawField, *(f32 *)rollField, a1, a2, *(f32 *)scaleField, modelFlags | 0x12, (u32 *)sceneContext);
    }
    flatPalette = D_005E5530;
    titlePaletteCopy(&flatRed, &flatPalette);
    paletteOffset = *paletteSelection * 4;
    color.bytes[0] = (u8)(*(u32 *)((u8 *)flatRed.words + paletteOffset) >> 0x18);
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
        shdSpriteDrawNow(-1.0f, -1.0f, 0.0f, rep >> 8, 0xFF, 0, 0, (u8 *)(*(s32 *)(sceneContext + 0x3C)), 0);
    }
    /* Preserve sequential byte stores while applying RGB brightness. */
    shadePalette = D_005E5530;
    titlePaletteCopy(&shadeRed, &shadePalette);
    paletteOffset = *paletteSelection * 4;
    color.bytes[0] = (u8)(*(u32 *)((u8 *)shadeRed.words + paletteOffset) >> 0x18);
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
    func_002aaf20(0.0f, 0.0f, 0.0f, (u8 *)color.bytes, 640.0f, 448.0f, 0x300, NULL);
    /* Retail ORs the full brightness word into the selected color. */
    opacityPalette = D_005E5530;
    titlePaletteCopy(&opacityRed, &opacityPalette);
    paletteOffset = *paletteSelection * 4;
    {
        u32 w0 = *(u32 *)((u8 *)opacityRed.words + paletteOffset);
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
    func_002aaf20(0.0f, 0.0f, 1.0f, (u8 *)color.bytes, 640.0f, 448.0f, 1, NULL);
}
#pragma pop

extern s32 shdSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 * arg4, s32 arg5);
extern void titleSkyApplyBasePreset(void);
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern s32 D_005E55E0[];
extern s8 D_005E5610[];
extern void (*D_00887300[])(s32 arg0, s32 arg1);
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00125E80
void titleBuildPointRows(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0, u8 *arg1)
{
    u8 spCC[4];
    PrimPointRow sp90[6];
    s8 sp70[0x20];
    PrimPoint sp40[6];
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
    dst = sp90;
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
    dst8 = sp70;
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

    p = spCC;
    n = 4;
    if (p != NULL) {
        do {
            *p = 0;
            p++;
            n--;
        } while (n != 0);
    }

    mdlEffectEmitMaskedTagPair();
    shdSpriteDrawNow(0.0f, 0.0f, fparg2, 0xFFFFFF, arg0 & 0xFF, 0x1000D, 0, (u8 *)(*(s32 *)(arg1 + 0x3C)), 1);
    mdlEffectEmitTagPair();

    i = 0;
    x = -100.0f + fparg0;
    y = -200.0f + fparg1;
    while ((u32)i < 6) {
        in = &sp90[i];
        out = sp40[i].v;
        out[0] = x + in->point.v[0];
        out[1] = y + in->point.v[1];
        i++;
    }

    titleSkyApplyBasePreset();
    D_00887300[0](6, 1);
    RpSkyRenderStateSet(3, 0x5000D);
    RpSkyRenderStateSet(2, 0x58);
    PrimDrawTransformed(sp70, sp40, fparg2, 6, 4, 0, 0, 0,
                  -20.0f, 1.0f, 1.0f);
}
#pragma pop

extern s32 shdSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5);
extern s32 shdSpriteDrawNowEx(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 *arg4, s32 arg5,
                         s16 arg6, s16 arg7, f32 farg3, f32 farg5, f32 farg4);
extern void titleSkyApplyBasePreset(void);
extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
typedef struct { u8 c0, c1, c2, c3; } __attribute__((aligned(4))) TitleColor;

typedef struct { s128 bits; } TitleRect;

extern TitleRect D_005E5590;
extern TitleRect D_005E55A0;
static inline void titleRing(f32 x, f32 y, s32 color, f32 scale, f32 angle, u8 *texture)
{
    f32 size = 64.0f * scale;

    shdSpriteDrawNowEx(x - size, y - size, 0.0f, color, 0x80, 0x1000F, 0, texture, 0, (s16)size, (s16)size, angle,
                  scale, scale);
}

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_00126090
void titleDrawShadeBars(f32 x, f32 y, f32 depth, s32 arg0, u8 *arg1)
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
    titleRectangle((u8 *)&fillColor, 0.0f, 0.0f, 0.0f, 640.0f, 480.0f, 0x12, NULL);
    mdlEffectEmitMaskedTagPair();
    shdSpriteDrawNow(0.0f, 0.0f, 0.0f, 0xFFFFFF, arg0 & 0xFF, 0x1000C, 0, (u8 *)(*(s32 *)(arg1 + 0x3C)), 1);
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
    frame = *(s32 *)(arg1 + 0x80) + 1;
    *(s32 *)(arg1 + 0x80) = frame;
    if (frame >= 200) {
        *(s32 *)(arg1 + 0x80) = 0;
    }
    phase = (f32)*(s32 *)(arg1 + 0x80) / 200.0f;
    titleSkyApplyBasePreset();
    RpSkyRenderStateSet(3, 0x53001);
    RpSkyRenderStateSet(2, 0x58);
    angle = 360.0f * phase;
    titleRing(35.0f, 152.0f, 0x202020, 2.4f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(233.0f, 102.0f, 0x808080, 1.8f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(377.0f, 93.0f, 0x808080, 1.4f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(626.0f, 110.0f, 0x808080, 1.1f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    angle = -360.0f * phase;
    titleRing(35.0f, 152.0f, 0x808080, 2.2f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(233.0f, 102.0f, 0x808080, 1.45f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(377.0f, 93.0f, 0x808080, 1.0f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
    titleRing(626.0f, 110.0f, 0x808080, 1.55f, angle, (u8 *)(*(s32 *)(arg1 + 0x3C)));
}
#pragma pop

#include "btl_shuffle_draw_internal.h"
typedef struct Code12FrameVector { f32 x, y, z; } Code12FrameVector;

typedef union Code12FrameVectorTransfer {
    struct { s64 xy; f32 z; } words;
    f32 value[3];
    Code12FrameVector vector;
} Code12FrameVectorTransfer;

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012B660
void titleLoaderTeardown(u8 *unusedTask)
{
    u8 *temp_2;
    s32 temp_3;
    s32 temp_4;
    s32 var_17;

    temp_2 = kwlnTaskGetWork();
    temp_3 = *(s32 *)(temp_2 + 0x1C);
    switch (temp_3) {
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
    var_17 = 0;
    goto loop_10_test;
loop_10_body:
    temp_4 = *(s32 *)(temp_2 + var_17 * 4 + 0x44);
    if (temp_4 != 0) {
        mdlDestroyModelObject(temp_4);
    }
    var_17 += 1;
loop_10_test:
    if (var_17 < 0xF) {
        goto loop_10_body;
    }
    sdkSpritePackDestroy(*(s32 *)(temp_2 + 0x3C));
    H_Cdvd_Destroy(*(s32 *)(temp_2 + 0x38));
    jtbl_008873EC[0](temp_2);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012B760
s32 titleStartLoader(void)
{
    u8 *temp_2;
    chkmemAllocSiteTag(D_005E5548, 0x728);
    temp_2 = D_008873F4[0](1, 0x90, 0x40000);
    if (temp_2 == NULL)
        kAssertFail(D_005E5548, 0x729);
    *(s32 *)(temp_2 + 0x18) = 0;
    kwlnTaskCreate((const void *)(D_005E5720), 0xF, 0, 0, func_0012aa70, titleLoaderTeardown, (u8 *)(temp_2));
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012B810
s32 titleLoaderReap(s32 arg0)
{
    B810Obj *temp_2;

    if ((arg0 == 0) || (kwlnTaskIsLinked() == 0)) {
        return -1;
    }
    temp_2 = (B810Obj *)(kwlnTaskGetWork(arg0));
    if (temp_2->field_18 != 0) {
        kwlnTaskDestroyWithHierarchy(arg0);
    }
    return temp_2->field_18;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012B890
s32 titleFileLoadStep(u8 *unusedTask)
{
    s32 sp2C;
    u8 *temp_2;
    s32 temp_3;
    temp_2 = (u8 *)kwlnTaskGetWork();
    temp_3 = *(s32 *)(temp_2 + 0);
    switch (temp_3) {
    case 0:
        *(s32 *)(temp_2 + 0) = 1;
    case 1:
        *(s32 *)(temp_2 + 0) = 2;
    case 2:
        *(s32 *)(temp_2 + 8) = func_004669d0(*(s32 *)(temp_2 + 4), &sp2C, 0);
        if (sp2C != 0) {
            *(s32 *)(temp_2 + 0) = 3;
            *(s32 *)(temp_2 + 4) = 0;
        }
        break;
    case 3:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// FUN_0012B940
void titleLoaderDestroy(u8 *arg0) {
    u8 *p;
    s32 v;

    p = kwlnTaskGetWork();
    v = *(s32 *)(p + 8);
    if (v != 0) {
        func_003ef3a0((void *)v);
    }
    jtbl_008873EC[0](p);
}
#pragma pop
