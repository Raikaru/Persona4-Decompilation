#include "operand_order_internal.h"
/* Original translation unit effPolygonThunder.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "rw_geometry_internal.h"
#include "polygon_thunder_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
#include "rw_types_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

/* 0x004833f0 is a texture release helper shared by the eff* units. */
extern void GeometryBlockDestroy(void *block);
extern void kAssertFail(const char *file, s32 line);
extern void chkmemAllocSiteTag(const char *file, s32 line);
extern void memcpy(void *dst, void *src, u32 size);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *);
extern char D_00713E50[];
extern u32 D_00713E70[]; /* kind initializer callbacks, six-word stride */
extern u32 D_00713E74[]; /* kind geometry constructors, six-word stride */
extern u32 D_00713E84[]; /* parameter byte counts, six words per kind */
/* iGpffff8044 is an anonymous gp-relative slot in retail (-0x7FBC($28)), not a
   defined link symbol; the VU0 funcs load it via C so the verifier masks the
   GPREL16 reloc. */
extern f32 iGpffff8044;
extern u32 D_00713360[];
extern u8 *GeometryCreateStripGrid(u16 rowCount, void *indices, s32 verticesPerRow, s32 flags);

/* 4-byte color, copied field-by-field by retail. */
typedef EffMeshColor Color4;
/* Five packed colors per 0x14-byte strip row; retail also copies RGBA bytes. */
typedef struct EffThunderColorRow {
    union { u32 packed; Color4 rgba; } colors[5];
} EffThunderColorRow;
extern s32 mdlEffectSamplePackedColor(u8 *colorData, u8 *opacityData, s32 frame, s32 duration);
extern void GeometryMatrixBuild(void *matrix, void *translation, void *basis, f32 scale);
extern void func_003e9cb0(void *frame, void *transform, s32 combine);
extern void GeometryBlockBindResource(void *block, u16 resourceId);


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Native b210 O2: 1216/1216 bytes, eleven resolved relocations,
 * 0 zero alignment bytes. Recompute each sample fade and
 * copy complete four-byte colors into the five-color row.
 * See docs/probe_archive/Thunder_constructors_20260924.md. */
// Creates a thunder bolt geometry: recalculates opacity per sample and writes five-colour rows.
// FUN_00495160
u8 *ThunderGeometryCreate(u8 *parameters)
{
    /* Earlier parameter-only probe: normalized_diff 767; separate typed locals now preserve the original reload lifetimes. */
    u32 rgb0;
    u32 rgb1;
    u32 rgb2;
    u32 fadeEnd;
    u8 *list;
    u8 *entry;
    u32 copyCount;
    u32 copyIndex;
    u32 color0;
    u32 color1;
    u32 color2;
    u32 alpha0;
    u32 alpha1;
    u32 alpha2;
    s32 fadeStart;
    f32 sampleTotal;
    u8 *geometry;
    s32 sampleCount;
    s32 endIndex;
    s32 fadeOutCount;
    f32 scaledAlpha;
    f32 fade;
    u32 alpha;
    EffThunderParameters *settings = (EffThunderParameters *)parameters;

    copyCount = settings->copies.value;
    chkmemAllocSiteTag(D_00713E50, 0x50);
    list = (*jtbl_008873E8)(copyCount * 0x10 + 4, 0x40000);
    if (list == 0) {
        kAssertFail(D_00713E50, 0x51);
    }
    ((EffThunderList *)list)->entries = list + 4;
    if (settings->segments.value < 3) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        settings->segments.value = 3;
    }
    color0 = settings->centerColor;
    rgb0 = color0 & 0xFFFFFF;
    color1 = settings->innerColor;
    rgb1 = color1 & 0xFFFFFF;
    color2 = settings->outerColor;
    rgb2 = color2 & 0xFFFFFF;
    alpha0 = color0 >> 24;
    alpha1 = color1 >> 24;
    alpha2 = color2 >> 24;
    entry = ((EffThunderList *)list)->entries;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    sampleTotal = (f32)(settings->segments.signedValue + 1);
    fadeStart = (s32)(settings->fadeStart * sampleTotal);
    endIndex = (s32)(settings->fadeEnd * sampleTotal);
    fadeEnd = (u32)endIndex;
    copyIndex = 0;
    while (copyIndex < copyCount) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        geometry = GeometryCreateStripGrid(settings->segments.low, D_00713360, 5, 0x48);
        ((EffThunderBolt *)entry)->geometry = geometry;
        sampleCount = ((EffGeometryBlock *)geometry)->vertexCount / 5;
        {
            u32 sampleIndex;
            u8 *colors;
            EffThunderColorRow *colorRow;

            colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry->colors;
            sampleIndex = 0;
            fadeOutCount = sampleCount - (s32)fadeEnd;
            while (sampleIndex < (u32)sampleCount) {
                colorRow = (EffThunderColorRow *)colors;
                if (sampleIndex < (u32)fadeStart) {
                    scaledAlpha = (f32)sampleIndex;
                    fade = scaledAlpha / (f32)fadeStart;
                } else if (fadeEnd < sampleIndex) {
                    s32 remainingSamples = sampleCount - (s32)sampleIndex;
                    f32 remainingFade = (f32)(u32)remainingSamples;
                    f32 fadeLength = (f32)(u32)fadeOutCount;
                    fade = remainingFade / fadeLength;
                } else {
                    fade = 1.0f;
                }
                scaledAlpha = (f32)alpha2 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[0].packed = rgb2 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha1 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[1].packed = rgb1 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha0 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[2].packed = rgb0 | ((u32)alpha << 24);
                {
                    Color4 color1;
                    Color4 color0;
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    color1 = colorRow->colors[1].rgba;
                    colorRow->colors[3].rgba = color1;
                    color0 = colorRow->colors[0].rgba;
                    colorRow->colors[4].rgba = color0;
                }
                sampleIndex += 1;
                colors += 0x14;
            }
        }
        {
            s32 value = -1;
            value -= (s32)(copyIndex * 4);
            ((EffThunderBolt *)entry)->age = value;
        }
        *(s32 *)&((EffThunderBolt *)entry)->baseAngle = 0;
        copyIndex += 1;
        entry += 0x10;
    }
    return list;
}
#pragma pop


// Frees each thunder geometry copy, then the block.
// FUN_00495620
void ThunderGeometryDestroy(u8 *effect)
{
    u8 *block;
    u8 **geometrySlot;
    u32 copyCount;
    u32 copyIndex;

    block = ((EffThunderInstance *)effect)->work.bytes;
    geometrySlot = *(u8 ***)block;
    copyCount = ((EffThunderParameters *)((EffThunderInstance *)effect)->parameters.bytes)->copies.value;
    copyIndex = 0;
    while (copyIndex < copyCount)
    {
        GeometryBlockDestroy(*geometrySlot);
        copyIndex++;
        geometrySlot += 4;
    }
    jtbl_008873EC[0](block);
}


/* Thunder bolt update. A live bolt rebuilds its strip: the first row is the
 * bolt cross-section from the forward/up cross products, and each further
 * row follows a sine-wave heading, rotated by effMiscAxisAngleVU and pushed along
 * the transformed forward axis with per-column drift. The two
 * 5-column loops use separate counters, as retail's $t2/$v0 show. FPR
 * declarations follow the order a regalloc_whatif.py replay derived.
 * effMiscAxisAngleVU is declared angle-first here: retail sets $f12 before $a0,
 * and b210 emits argument setup in declaration order (handoff 7a-bis). */

#pragma push
#pragma opt_loop_invariants on
// Rebuilds a live thunder bolt's strip: the first row across the travel direction, each further row along a sine-wave heading.
// FUN_004956B0
void ThunderBoltUpdateStrip(u8 *effect)
{
    /* Earlier whole-layout probe: normalized_diff 1277; separate typed locals now preserve the original reload lifetimes. */
    extern void mdlEffectCopyCameraOrigin(f32 *output);
    extern void effMiscBuildRotationVU(void);
    extern f32 sinf(f32 angle);
    extern f32 cosf(f32 angle);
    extern f32 sqrtf(f32 value);
    extern f32 func_0044b938(f32 value);
    extern void effMiscAxisAngleVU(f32 axis, f32 *angle);
    extern void func_003c22f0(u8 *geometry);
    extern f32 fGpffff8084;
    extern f32 iGpffff8084;
    extern f32 fGpffff80e4;
    extern f32 fGpffff80e8;
    extern f32 fGpffff80ec;
    extern EffectVuVector D_00713D00;
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    f32 drift[5];
    f32 widths[5];
    EffectVuVector forward;
    EffectVuVector up;
    EffectVuVector axis;
    f32 segmentLength;
    f32 segmentScale;
    f32 phase;
    f32 wave;
    f32 amplitude;
    f32 previous;
    f32 angle;
    f32 jitter;
    f32 offset;
    f32 length;
    f32 negone;
    f32 zero;
    f32 phaseStep;
    f32 shift;
    f32 base;
    f32 lengthScale;
    f32 lengthSpread;
    f32 hypot;
    f32 one;
    f32 twoPi;
    f32 waveRange;
    f32 waveBase;
    f32 jitterRange;
    f32 jitterBase;
    f32 half;
    f32 next;
    f32 nextAngle;
    u8 *parameters;
    u8 *bolt;
    EffThunderBolt *boltEntry;
    u8 *block;
    u32 state;
    s32 copyIndex;
    s32 copyCount;
    s32 respawnRange;
    u8 *geometry;
    EffGeometryBlock *geometryBlock;
    s32 rowIndex;
    u8 *vertices;
    s32 rowCount;
    s32 columnIndex;
    s32 nextColumnIndex;

    block = ((EffThunderInstance *)effect)->work.bytes;
    parameters = ((EffThunderInstance *)effect)->parameters.bytes;
    bolt = ((EffThunderList *)block)->entries;
    if ((((EffThunderParameters *)parameters)->duration.value < ((EffThunderInstance *)effect)->age.value) && (((EffThunderParameters *)parameters)->duration.value != 0)) {
        return;
    }
    copyCount = ((EffThunderParameters *)parameters)->copies.signedValue;
    respawnRange = ((EffThunderParameters *)parameters)->respawnRange;
    lengthScale = ((EffThunderParameters *)parameters)->lengthScale;
    lengthSpread = ((EffThunderParameters *)parameters)->lengthSpread;
    segmentScale = (f32)((EffThunderParameters *)parameters)->segments.value;
    segmentLength = ((EffThunderParameters *)parameters)->length / segmentScale;
    twoPi = fGpffff8084;
    /* Retail reloads the 2pi literal here instead of reusing twoPi. */
    phaseStep = (iGpffff8084 * (f32)((EffThunderParameters *)parameters)->waves) / segmentScale;
    amplitude = ((EffThunderParameters *)parameters)->amplitude;
    if (segmentLength <= 0.0f) {
        return;
    }
    mdlEffectCopyCameraOrigin(up.lane);
    effectVuLoad10((EffectVuVector *)(effect + 0x10));
    effMiscBuildRotationVU();
    effectVuLoad10(&D_00713D00);
    __asm__ volatile(
        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
    effectVuStore10(&forward);
    jitter = fGpffff80e4;
    zero = 0.0f;
    widths[0] = 0.0f;
    widths[1] = ((EffThunderParameters *)parameters)->outerWidth;
    widths[2] = widths[1] + ((EffThunderParameters *)parameters)->innerWidth;
    widths[3] = widths[2] + ((EffThunderParameters *)parameters)->innerWidth;
    widths[4] = widths[3] + widths[1];
    copyIndex = 0;
    one = 1.0f;
    negone = -1.0f;
    waveRange = fGpffff80e8;
    waveBase = fGpffff80ec;
    jitterRange = 0.75f;
    jitterBase = 0.25f;
    half = 0.5f;
    for (; copyIndex < copyCount; copyIndex++, bolt += 0x10) {
        boltEntry = (EffThunderBolt *)bolt;
        if (boltEntry->age == -1) {
            boltEntry->color.signedValue = -1;
            goto advance;
        }
        length = (lengthScale * ((one - lengthSpread) + lengthSpread * effMiscRandFloat(0))) / segmentScale;
        base = boltEntry->baseAngle;
        if ((effMiscRand(0) & 1) != 0) {
            length = length * negone;
        }
        offset = length;
        state = boltEntry->color.value;
        if ((state & 0xFF000000) > 0x40000000U) {
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            boltEntry->color.value = state + 0xC0000000;
        } else {
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            boltEntry->age = -1;
            if (respawnRange > 0) {
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                boltEntry->age = boltEntry->age - effMiscRand(0) % respawnRange;
            }
            continue;
        }
        geometry = boltEntry->geometry;
        geometryBlock = (EffGeometryBlock *)geometry;
        rowCount = geometryBlock->vertexCount / 5;
        RpGeometryLock(((RpAtomic *)geometryBlock->atomic)->geometry, 2);
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry->morphTarget->vertices;
        if ((effMiscRand(0) & 1) != 0) {
            amplitude = amplitude * negone;
        }
        phase = twoPi * effMiscRandFloat(0);
        wave = amplitude * (waveBase + waveRange * effMiscRandFloat(0));
        angle = wave * sinf(phase);
        phase += phaseStep;
        previous = wave * sinf(phase);
        {
            f32 rise = previous - angle;
            f32 inner;
            f32 outer;

            angle = func_0044b938(rise / sqrtf(rise * rise + segmentLength * segmentLength));
            inner = ((EffThunderParameters *)parameters)->innerWidth;
            outer = inner + ((EffThunderParameters *)parameters)->outerWidth;
            angle = angle + base;
            effectVuLoad10(&forward);
            effectVuLoad11(&up);
            __asm__ volatile(
                "vopmula.xyz $ACC, $vf10, $vf11\n"
                "vopmsub.xyz $vf10, $vf11, $vf10\n"
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n"
                "vmove.xyzw $vf12, $vf10\n" : : : "$vf2", "$vf10", "$vf12");
            effectVuLoad11(&forward);
            __asm__ volatile(
                "vopmula.xyz $ACC, $vf10, $vf11\n"
                "vopmsub.xyz $vf10, $vf11, $vf10\n" : : : "$vf10");
            effectVuStore10(&axis);
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vmove.xyzw $vf11, $vf12\n" : : : "$vf10", "$vf11");
            effectVuScale10(outer);
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[0].x = D_00713D10[0];
            ((RwV3d *)vertices)[0].y = D_00713D14[0];
            ((RwV3d *)vertices)[0].z = D_00713D18[0];
            __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[4].x = D_00713D10[0];
            ((RwV3d *)vertices)[4].y = D_00713D14[0];
            ((RwV3d *)vertices)[4].z = D_00713D18[0];
            effectVuScale11(inner);
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[1].x = D_00713D10[0];
            ((RwV3d *)vertices)[1].y = D_00713D14[0];
            ((RwV3d *)vertices)[1].z = D_00713D18[0];
            __asm__ volatile("vsub.xyz $vf11, $vf0, $vf11" : : : "$vf11");
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[3].x = D_00713D10[0];
            ((RwV3d *)vertices)[3].y = D_00713D14[0];
            ((RwV3d *)vertices)[3].z = D_00713D18[0];
            ((RwV3d *)vertices)[2].x = zero;
            ((RwV3d *)vertices)[2].y = zero;
            ((RwV3d *)vertices)[2].z = zero;
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11");
            effectVuScale11(previous);
        }
        for (columnIndex = 0; columnIndex < 5; columnIndex++) {
            u8 *vertex = vertices + columnIndex * 12;
            D_00713D10[0] = ((RwV3d *)vertex)[0].x;
            D_00713D14[0] = ((RwV3d *)vertex)[0].y;
            D_00713D18[0] = ((RwV3d *)vertex)[0].z;
            effectVuLoad10((EffectVuVector *)D_00713D10);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertex)[0].x = D_00713D10[0];
            ((RwV3d *)vertex)[0].y = D_00713D14[0];
            ((RwV3d *)vertex)[0].z = D_00713D18[0];
            drift[columnIndex] = zero;
        }
        vertices += 0x3C;
        for (rowIndex = 1; rowIndex < rowCount; rowIndex++, vertices += 0x3C) {
            f32 slope;

            shift = jitter * (jitterBase + jitterRange * effMiscRandFloat(0));
            if ((effMiscRand(0) & 1) != 0) {
                jitter = jitter * negone;
            }
            phase += phaseStep;
            if (!(phase < twoPi)) {
                phase -= twoPi;
                amplitude = amplitude * negone;
                wave = amplitude * (waveBase + waveRange * effMiscRandFloat(0));
            }
            next = wave * sinf(phase);
            {
                f32 rise = next - previous;

                hypot = sqrtf(rise * rise + segmentLength * segmentLength);
                nextAngle = operandOrderAddFloat(operandOrderAddFloat(func_0044b938(rise / hypot), shift + offset), base);
            }
            effMiscAxisAngleVU(angle, axis.lane);
            effectVuLoad10(&forward);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            previous = half * (nextAngle - angle);
            angle = sinf(previous);
            slope = angle / cosf(previous);
            previous = next;
            angle = nextAngle;
            offset += length;
            __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
            for (nextColumnIndex = 0; nextColumnIndex < 5; nextColumnIndex++) {
                u8 *vertex;
                f32 step = slope * widths[nextColumnIndex];

                drift[nextColumnIndex] = drift[nextColumnIndex] + step;
                __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11");
                vertex = vertices + nextColumnIndex * 12;
                D_00713D10[0] = ((RwV3d *)vertex)[-5].x;
                D_00713D14[0] = ((RwV3d *)vertex)[-5].y;
                D_00713D18[0] = ((RwV3d *)vertex)[-5].z;
                effectVuLoad10((EffectVuVector *)D_00713D10);
                effectVuScale11(hypot + drift[nextColumnIndex]);
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                ((RwV3d *)vertex)[0].x = D_00713D10[0];
                ((RwV3d *)vertex)[0].y = D_00713D14[0];
                ((RwV3d *)vertex)[0].z = D_00713D18[0];
                drift[nextColumnIndex] = step;
            }
        }
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry;
        func_003c22f0(vertices);
        if ((geometryBlock->kind & 4) != 0) {
            ((RpGeometry *)vertices)->lockedSinceLastInst |= 1;
        }
advance:
        boltEntry->age = boltEntry->age + 1;
    }
}
#pragma pop


// Writes the thunder bolt colour rows from the bolt state (union colour pack).
// FUN_00495F80
void ThunderBoltWriteRows(u8 *effect)
{
    u8 *block;
    u8 *parameters;
    u8 *bolt;
    s32 age;
    s32 durationOrCopies;
    u8 materialColor[4];
    s32 baseColor;
    s32 sampledColor;
    s32 boltColor;
    s32 modulatedColor;
    f32 colorFactors[4];
    s32 sample;
    f32 scale;
    s32 copyIndex;
    u8 *geometry;
    u8 *material;
    f32 matrix[16];

    block = ((EffThunderInstance *)effect)->work.bytes;
    parameters = ((EffThunderInstance *)effect)->parameters.bytes;
    bolt = ((EffThunderList *)block)->entries;
    age = ((EffThunderInstance *)effect)->age.signedValue;
    durationOrCopies = ((EffThunderParameters *)parameters)->duration.signedValue;
    if ((durationOrCopies >= age) || (durationOrCopies == 0))
    {
        s32 *colorWord;

        durationOrCopies = ((EffThunderParameters *)parameters)->copies.signedValue;
        sample = (s32)mdlEffectSamplePackedColor(parameters, parameters + 0x24, age, ((EffThunderParameters *)parameters)->duration.signedValue);
        baseColor = ((EffThunderInstance *)effect)->packedColor.signedValue;
        colorWord = &baseColor;
        scale = iGpffff8044;
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
            : "r"(colorWord), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = sample;
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
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(colorFactors) : "memory");
        GeometryMatrixBuild(&matrix[0], effect, 0, ((EffThunderInstance *)effect)->scale.value);
        copyIndex = 0;
        while (copyIndex < durationOrCopies)
        {
            if (((EffThunderBolt *)bolt)->age > 0)
            {
                geometry = ((EffThunderBolt *)bolt)->geometry;
                func_003e9cb0(((EffGeometryBlock *)geometry)->frame, &matrix[0], 0);
                boltColor = ((EffThunderBolt *)bolt)->color.signedValue;
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
                    :
                    : "r"(&boltColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)     \n"
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0xCC($sp)      \n"
                    :
                    : "r"(colorFactors)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: mwcc b210 hoists the modulatedColor reload above the inline COP2
                   store and serves a stale value, so the post-asm read is volatile. */
                *(s32 *)materialColor = *(volatile s32 *)&modulatedColor;
                if (materialColor[3] != 0xFF)
                {
                    material = ((EffGeometryBlock *)geometry)->material;
                    ((RpMaterial *)material)->color = *(Color4 *)materialColor;
                }
                else
                {
                    materialColor[3] = 0xFE;
                    material = ((EffGeometryBlock *)geometry)->material;
                    ((RpMaterial *)material)->color = *(Color4 *)materialColor;
                    materialColor[3] = 0xFF;
                }
                if (((EffThunderParameters *)parameters)->visible != 0)
                {
                    ((EffGeometryBlock *)geometry)->kind = ((EffGeometryBlock *)geometry)->kind | 1;
                }
                else
                {
                    ((EffGeometryBlock *)geometry)->kind = ((EffGeometryBlock *)geometry)->kind & 0xFFFE;
                }
                {
                    s32 resource = ((EffThunderParameters *)parameters)->resource;
                    GeometryBlockBindResource(geometry, resource);
                }
            }
            copyIndex++;
            bolt += 0x10;
        }
    }
}



// Seeds the orbit radius and its per-frame step, then gives each orbit bolt a random negative counter.
// FUN_004961F0
void ThunderBoltInitFade(u8 *effect)
{
    u8 *block;
    u8 *parameters;
    u32 *boltWords;
    s32 durationOrCopies;
    f32 spread;
    f32 startRadius;
    u32 copyIndex;

    block = ((EffThunderInstance *)effect)->work.bytes;
    parameters = ((EffThunderInstance *)effect)->parameters.bytes;
    boltWords = *(u32 **)block;
    durationOrCopies = ((EffThunderParameters *)parameters)->duration.signedValue;
    spread = ((EffThunderOrbitParameters *)parameters)->startRadiusSpread;
    startRadius = ((EffThunderOrbitParameters *)parameters)->startRadius * (spread * effMiscRandFloat(0) + (1.0f - spread));
    if (durationOrCopies > 0)
    {
        f32 endSpread = ((EffThunderOrbitParameters *)parameters)->endRadiusSpread;
        f32 endRadius = ((EffThunderOrbitParameters *)parameters)->endRadius * (endSpread * effMiscRandFloat(0) + (1.0f - endSpread));
        ((EffThunderOrbitList *)block)->radius = startRadius;
        ((EffThunderOrbitList *)block)->radiusStep = (endRadius - startRadius) / (f32)durationOrCopies;
    }
    else
    {
        ((EffThunderOrbitList *)block)->radius = startRadius;
        ((EffThunderOrbitList *)block)->radiusStep = 0.0f;
    }
    durationOrCopies = ((EffThunderParameters *)parameters)->copies.signedValue;
    copyIndex = 0;
    while (copyIndex < (u32)durationOrCopies)
    {
        boltWords[5] = -1 - (effMiscRand(0) & 7);
        copyIndex++;
        boltWords += 0xC;
    }
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Native b210 O2: 1224/1232 bytes, eleven resolved relocations,
 * 8 zero alignment bytes. Recompute each sample fade and
 * copy complete four-byte colors into the five-color row.
 * See docs/probe_archive/Thunder_constructors_20260924.md. */
// Creates orbit-bolt geometry with a 0x10-byte list header, 0x30-byte entries and per-sample opacity.
// FUN_00496340
u8 *ThunderGeometryCreatePadded(u8 *parameters)
{
    /* Earlier parameter-only probe: normalized_diff 762; separate typed locals now preserve the original reload lifetimes. */
    u32 rgb0;
    u32 rgb1;
    u32 rgb2;
    u32 fadeEnd;
    u8 *list;
    u8 *entry;
    u32 copyCount;
    u32 copyIndex;
    u32 color0;
    u32 color1;
    u32 color2;
    u32 alpha0;
    u32 alpha1;
    u32 alpha2;
    s32 fadeStart;
    f32 sampleTotal;
    u8 *geometry;
    s32 sampleCount;
    s32 endIndex;
    s32 fadeOutCount;
    f32 scaledAlpha;
    f32 fade;
    u32 alpha;
    EffThunderParameters *settings = (EffThunderParameters *)parameters;

    copyCount = settings->copies.value;
    chkmemAllocSiteTag(D_00713E50, 0x2B5);
    list = (*jtbl_008873E8)(copyCount * 0x30 + 0x10, 0x40000);
    if (list == 0) {
        kAssertFail(D_00713E50, 0x2B6);
    }
    ((EffThunderOrbitList *)list)->entries = list + 0x10;
    ((EffThunderOrbitList *)list)->allocation = list;
    if (settings->segments.value < 3) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        settings->segments.value = 3;
    }
    color0 = settings->centerColor;
    rgb0 = color0 & 0xFFFFFF;
    color1 = settings->innerColor;
    rgb1 = color1 & 0xFFFFFF;
    color2 = settings->outerColor;
    rgb2 = color2 & 0xFFFFFF;
    alpha0 = color0 >> 24;
    alpha1 = color1 >> 24;
    alpha2 = color2 >> 24;
    entry = ((EffThunderOrbitList *)list)->entries;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    sampleTotal = (f32)(settings->segments.signedValue + 1);
    fadeStart = (s32)(settings->fadeStart * sampleTotal);
    endIndex = (s32)(settings->fadeEnd * sampleTotal);
    fadeEnd = (u32)endIndex;
    copyIndex = 0;
    while (copyIndex < copyCount) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        geometry = GeometryCreateStripGrid(settings->segments.low, D_00713360, 5, 0x48);
        ((EffThunderOrbitBolt *)entry)->geometry = geometry;
        sampleCount = ((EffGeometryBlock *)geometry)->vertexCount / 5;
        {
            u32 sampleIndex;
            u8 *colors;
            EffThunderColorRow *colorRow;

            colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry->colors;
            sampleIndex = 0;
            fadeOutCount = sampleCount - (s32)fadeEnd;
            while (sampleIndex < (u32)sampleCount) {
                colorRow = (EffThunderColorRow *)colors;
                if (sampleIndex < (u32)fadeStart) {
                    scaledAlpha = (f32)sampleIndex;
                    fade = scaledAlpha / (f32)fadeStart;
                } else if (fadeEnd < sampleIndex) {
                    s32 remainingSamples = sampleCount - (s32)sampleIndex;
                    f32 remainingFade = (f32)(u32)remainingSamples;
                    f32 fadeLength = (f32)(u32)fadeOutCount;
                    fade = remainingFade / fadeLength;
                } else {
                    fade = 1.0f;
                }
                scaledAlpha = (f32)alpha2 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[0].packed = rgb2 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha1 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[1].packed = rgb1 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha0 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[2].packed = rgb0 | ((u32)alpha << 24);
                {
                    Color4 color1;
                    Color4 color0;
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    color1 = colorRow->colors[1].rgba;
                    colorRow->colors[3].rgba = color1;
                    color0 = colorRow->colors[0].rgba;
                    colorRow->colors[4].rgba = color0;
                }
                sampleIndex += 1;
                colors += 0x14;
            }
        }
        {
            s32 value = -1;
            value -= (s32)(copyIndex * 4);
            ((EffThunderOrbitBolt *)entry)->age = value;
        }
        copyIndex += 1;
        entry += 0x30;
    }
    return list;
}
#pragma pop


// Frees each padded thunder geometry copy, then the block.
// FUN_00496810
void ThunderPaddedGeometryDestroy(u8 *effect)
{
    u8 *block;
    u8 **geometrySlot;
    u32 copyCount;
    u32 copyIndex;

    block = ((EffThunderInstance *)effect)->work.bytes;
    geometrySlot = *(u8 ***)block;
    copyCount = ((EffThunderParameters *)((EffThunderInstance *)effect)->parameters.bytes)->copies.value;
    copyIndex = 0;
    while (copyIndex < copyCount)
    {
        GeometryBlockDestroy(*geometrySlot);
        copyIndex++;
        geometrySlot += 0xC;
    }
    jtbl_008873EC[0](((EffThunderOrbitList *)block)->allocation);
}


/* Orbiting thunder bolt update, the ThunderBoltUpdateStrip sibling. A bolt in its
 * spawn state picks an orbit and places its anchor through the VU0 matrix;
 * a live bolt advances the orbit, builds its first row across the travel
 * direction and steps each further row along the rotated travel vector,
 * whose length comes from VU0 vsqrt. The two 5-column loops use separate
 * counters. The spilled locals are declared in retail's spill-slot order.
 * effMiscAxisAngleVU is declared angle-first, as for ThunderBoltUpdateStrip. */
#pragma push
#pragma opt_loop_invariants on
// Updates the orbiting thunder bolt: a spawn-state bolt picks an orbit through the VU0 matrix, a live bolt advances the orbit and rebuilds its strip.
// FUN_004968A0
void ThunderOrbitBoltUpdateStrip(u8 *effect)
{
    /* Earlier whole-layout probe: normalized_diff 1868; separate typed locals now preserve the original reload lifetimes. */
    extern void mdlEffectCopyCameraOrigin(f32 *output);
    extern f32 sinf(f32 angle);
    extern f32 cosf(f32 angle);
    extern f32 sqrtf(f32 value);
    extern f32 func_0044b938(f32 value);
    extern f32 func_0044b340(f32 angle);
    extern void effMiscRotateXVU(f32 angle);
    extern void effMiscRotateYVU(f32 angle);
    extern void effMiscCombineRotationVU(void);
    extern void effMiscAxisAngleVU(f32 axis, f32 *angle);
    extern void func_003c22f0(u8 *geometry);
    extern f32 fGpffff804c;
    extern f32 fGpffff8084;
    extern f32 fGpffff8098;
    extern f32 fGpffff809c;
    extern f32 iGpffff80d4;
    extern f32 fGpffff80d8;
    extern f32 fGpffff80dc;
    extern f32 fGpffff80e0;
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    f32 drift[5];
    f32 widths[5];
    EffectVuVector delta;
    EffectVuVector heading;
    EffectVuVector side;
    EffectVuVector up;
    EffectVuVector point;
    EffectVuVector position;
    EffectVuVector step;
    f32 segmentLength;
    f32 phase;
    f32 wave;
    f32 amplitude;
    f32 previous;
    f32 angle;
    f32 jitter;
    f32 radius;
    f32 zero;
    f32 half;
    f32 two;
    f32 twoPi;
    f32 outer;
    f32 inner;
    f32 phaseStep;
    f32 shift;
    f32 spin;
    f32 dropScale;
    f32 drop;
    f32 stepLength;
    f32 one;
    f32 tilt;
    f32 negone;
    f32 waveRange;
    f32 waveBase;
    f32 dropRange;
    f32 dropBase;
    f32 jitterRange;
    f32 jitterBase;
    f32 orbit;
    f32 next;
    f32 nextAngle;
    u8 *parameters;
    u8 *bolt;
    EffThunderOrbitBolt *boltEntry;
    u8 *block;
    u32 state;
    s32 copyIndex;
    s32 copyCount;
    s32 respawnRange;
    u8 *geometry;
    EffGeometryBlock *geometryBlock;
    s32 rowIndex;
    u8 *vertices;
    s32 rowCount;
    s32 columnIndex;
    s32 nextColumnIndex;
    u8 mode;

    block = ((EffThunderInstance *)effect)->work.bytes;
    parameters = ((EffThunderInstance *)effect)->parameters.bytes;
    bolt = ((EffThunderOrbitList *)block)->entries;
    if ((((EffThunderParameters *)parameters)->duration.value < ((EffThunderInstance *)effect)->age.value) && (((EffThunderParameters *)parameters)->duration.value != 0)) {
        return;
    }
    copyCount = ((EffThunderParameters *)parameters)->copies.signedValue;
    respawnRange = ((EffThunderParameters *)parameters)->respawnRange;
    {
        f32 segmentScale = (f32)((EffThunderParameters *)parameters)->segments.value;

        segmentLength = ((EffThunderParameters *)parameters)->length / segmentScale;
        phaseStep = (fGpffff8084 * (f32)((EffThunderParameters *)parameters)->waves) / segmentScale;
    }
    amplitude = ((EffThunderParameters *)parameters)->amplitude;
    spin = ((EffThunderOrbitParameters *)parameters)->orbitAcceleration;
    mode = ((EffThunderOrbitParameters *)parameters)->orbitMode;
    if (segmentLength <= 0.0f) {
        return;
    }
    mdlEffectCopyCameraOrigin(up.lane);
    jitter = fGpffff80d8;
    dropScale = -(fGpffff804c * (segmentLength / 10.0f));
    zero = 0.0f;
    widths[0] = 0.0f;
    widths[1] = ((EffThunderParameters *)parameters)->outerWidth;
    widths[2] = widths[1] + ((EffThunderParameters *)parameters)->innerWidth;
    widths[3] = widths[2] + ((EffThunderParameters *)parameters)->innerWidth;
    widths[4] = widths[3] + widths[1];
    one = 1.0f;
    delta.lane[3] = 1.0f;
    point.lane[3] = 1.0f;
    radius = ((EffThunderOrbitList *)block)->radius;
    ((EffThunderOrbitList *)block)->radius = radius + ((EffThunderOrbitList *)block)->radiusStep;
    copyIndex = 0;
    half = 0.5f;
    two = 2.0f;
    twoPi = fGpffff8084;
    tilt = fGpffff80dc;
    negone = -1.0f;
    waveRange = iGpffff80d4;
    waveBase = fGpffff80e0;
    dropRange = fGpffff809c;
    dropBase = fGpffff8098;
    jitterRange = 0.75f;
    jitterBase = 0.25f;
    for (; copyIndex < copyCount; copyIndex++, bolt += 0x30) {
        boltEntry = (EffThunderOrbitBolt *)bolt;
        if (boltEntry->age == -1) {
            f32 t = ((EffThunderOrbitParameters *)parameters)->orbitSpeedSpread;

            boltEntry->speed = ((EffThunderOrbitParameters *)parameters)->orbitSpeed * ((one - t) + t * effMiscRandFloat(0));
            boltEntry->angle = zero;
            if (mode == 0) {
                boltEntry->tilt = twoPi * (two * (effMiscRandFloat(0) - half));
                boltEntry->height = zero;
            } else {
                boltEntry->tilt = tilt * (two * (effMiscRandFloat(0) - half));
                boltEntry->height = ((EffThunderOrbitParameters *)parameters)->heightRange * effMiscRandFloat(0);
            }
            boltEntry->yaw = twoPi * (two * (effMiscRandFloat(0) - half));
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            effMiscRotateXVU(boltEntry->tilt);
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            effMiscRotateYVU(boltEntry->yaw);
            effMiscCombineRotationVU();
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            angle = boltEntry->angle;
            point.lane[0] = radius * cosf(angle);
            point.lane[1] = zero;
            point.lane[2] = radius * sinf(angle);
            effectVuLoad10(&point);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            effectVuStore10(&point);
            boltEntry->previousPosition[0] = point.lane[0];
            boltEntry->previousPosition[1] = point.lane[1];
            boltEntry->previousPosition[2] = point.lane[2];
            boltEntry->color.signedValue = -1;
            goto advance;
        }
        state = boltEntry->color.value;
        if ((state & 0xFF000000) > 0x40000000U) {
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            boltEntry->color.value = state + 0xC0000000;
        } else {
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            boltEntry->age = -1;
            if (respawnRange > 0) {
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                boltEntry->age = boltEntry->age - effMiscRand(0) % respawnRange;
            }
            continue;
        }
        geometry = boltEntry->geometry;
        geometryBlock = (EffGeometryBlock *)geometry;
        rowCount = geometryBlock->vertexCount / 5;
        RpGeometryLock(((RpAtomic *)geometryBlock->atomic)->geometry, 2);
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry->morphTarget->vertices;
        if ((effMiscRand(0) & 1) != 0) {
            amplitude = amplitude * negone;
        }
        phase = twoPi * effMiscRandFloat(0);
        wave = amplitude * (waveBase + waveRange * effMiscRandFloat(0));
        angle = wave * sinf(phase);
        phase += phaseStep;
        previous = wave * sinf(phase);
        {
            f32 rise = previous - angle;

            f32 tilted = func_0044b938(rise / sqrtf(rise * rise + segmentLength * segmentLength));

            inner = ((EffThunderParameters *)parameters)->innerWidth;
            outer = inner + ((EffThunderParameters *)parameters)->outerWidth;
            angle = tilted;
        }
        drop = dropScale * (dropBase + dropRange * effMiscRandFloat(0));
        {
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            f32 t = (f32)(boltEntry->age + 1);

            orbit = t * (boltEntry->speed + half * (spin * t));
            orbit += boltEntry->angle;
        }
        effMiscRotateXVU(boltEntry->tilt);
        effMiscRotateYVU(boltEntry->yaw);
        effMiscCombineRotationVU();
        point.lane[0] = radius * cosf(orbit);
        point.lane[1] = zero;
        point.lane[2] = radius * sinf(orbit);
        effectVuLoad10(&point);
        __asm__ volatile(
            "vmulax.xyzw $ACC, $vf28, $vf10x\n"
            "vmadday.xyzw $ACC, $vf29, $vf10y\n"
            "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
        effectVuStore10(&point);
        effectVuStore10(&position);
        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
        effectVuStore10(&heading);
        delta.lane[0] = position.lane[0] - boltEntry->previousPosition[0];
        delta.lane[1] = position.lane[1] - boltEntry->previousPosition[1];
        delta.lane[2] = position.lane[2] - boltEntry->previousPosition[2];
        effectVuLoad10(&delta);
        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n"
            "vmove.xyzw $vf12, $vf10\n" : : : "$vf2", "$vf10", "$vf12");
        effectVuLoad11(&heading);
        effectVuStore10(&delta);
        __asm__ volatile(
            "vopmula.xyz $ACC, $vf10, $vf11\n"
            "vopmsub.xyz $vf10, $vf11, $vf10\n" : : : "$vf10");
        effectVuStore10(&side);
        effectVuLoad11(&up);
        __asm__ volatile(
            "vmove.xyzw $vf10, $vf12\n"
            "vopmula.xyz $ACC, $vf10, $vf11\n"
            "vopmsub.xyz $vf10, $vf11, $vf10\n"
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n"
            "vmove.xyzw $vf12, $vf10\n"
            "vmove.xyzw $vf11, $vf10\n" : : : "$vf2", "$vf10", "$vf11", "$vf12");
        effectVuScale10(outer);
        __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
        ((RwV3d *)vertices)[0].x = D_00713D10[0];
        ((RwV3d *)vertices)[0].y = D_00713D14[0];
        ((RwV3d *)vertices)[0].z = D_00713D18[0];
        __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10");
        __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
        ((RwV3d *)vertices)[4].x = D_00713D10[0];
        ((RwV3d *)vertices)[4].y = D_00713D14[0];
        ((RwV3d *)vertices)[4].z = D_00713D18[0];
        effectVuScale11(inner);
        __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
        ((RwV3d *)vertices)[1].x = D_00713D10[0];
        ((RwV3d *)vertices)[1].y = D_00713D14[0];
        ((RwV3d *)vertices)[1].z = D_00713D18[0];
        __asm__ volatile("vsub.xyz $vf11, $vf0, $vf11" : : : "$vf11");
        __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
        ((RwV3d *)vertices)[3].x = D_00713D10[0];
        ((RwV3d *)vertices)[3].y = D_00713D14[0];
        ((RwV3d *)vertices)[3].z = D_00713D18[0];
        ((RwV3d *)vertices)[2].x = zero;
        ((RwV3d *)vertices)[2].y = zero;
        ((RwV3d *)vertices)[2].z = zero;
        point.lane[1] = point.lane[1] + boltEntry->height;
        effectVuLoad11(&point);
        for (columnIndex = 0; columnIndex < 5; columnIndex++) {
            u8 *vertex = vertices + columnIndex * 12;
            D_00713D10[0] = ((RwV3d *)vertex)[0].x;
            D_00713D14[0] = ((RwV3d *)vertex)[0].y;
            D_00713D18[0] = ((RwV3d *)vertex)[0].z;
            effectVuLoad10((EffectVuVector *)D_00713D10);
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertex)[0].x = D_00713D10[0];
            ((RwV3d *)vertex)[0].y = D_00713D14[0];
            ((RwV3d *)vertex)[0].z = D_00713D18[0];
            drift[columnIndex] = zero;
        }
        vertices += 0x3C;
        boltEntry->previousPosition[0] = position.lane[0];
        boltEntry->previousPosition[1] = position.lane[1];
        boltEntry->previousPosition[2] = position.lane[2];
        for (rowIndex = 1; rowIndex < rowCount; rowIndex++, vertices += 0x3C) {
            f32 slope;

            shift = jitter * (jitterBase + jitterRange * effMiscRandFloat(0));
            if ((effMiscRand(0) & 1) != 0) {
                jitter = jitter * negone;
            }
            phase += phaseStep;
            if (!(phase < twoPi)) {
                phase -= twoPi;
                amplitude = amplitude * negone;
                wave = amplitude * (waveBase + waveRange * effMiscRandFloat(0));
                drop = dropScale * (dropBase + dropRange * effMiscRandFloat(0));
            }
            next = wave * sinf(phase);
            {
                f32 rise = next - previous;

                nextAngle = operandOrderAddFloat(func_0044b938(rise / sqrtf(rise * rise + segmentLength * segmentLength)), shift);
            }
            effMiscAxisAngleVU(angle, heading.lane);
            effectVuLoad10(&delta);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            effectVuStore10(&step);
            effMiscAxisAngleVU(drop, side.lane);
            effectVuLoad10(&delta);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
            effectVuStore10(&delta);
            effectVuLoad10(&position);
            __asm__ volatile(
                "vmove.xyzw $vf11, $vf10\n"
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10", "$vf11");
            effectVuStore10(&position);
            /* Retail moves the vsqrt result through $2 (cfc2/mtc1 bridge). */
            __asm__ volatile(
                "vsub.xyzw $vf10, $vf10, $vf11\n"
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vaddy.x $vf2, $vf2, $vf2y\n"
                "vaddz.x $vf2, $vf2, $vf2z\n"
                "vsqrt $Q, $vf2x\n"
                "vwaitq\n"
                "cfc2.ni $2, $vi22\n"
                "mtc1 $2, %0\n" : "=f"(stepLength) : : "$2", "$vf2", "$vf10");
            slope = func_0044b340(half * (nextAngle - angle));
            previous = next;
            angle = nextAngle;
            __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&step), "m"(step) : "$vf12");
            for (nextColumnIndex = 0; nextColumnIndex < 5; nextColumnIndex++) {
                u8 *vertex;
                f32 offset = slope * widths[nextColumnIndex];

                drift[nextColumnIndex] = drift[nextColumnIndex] + offset;
                __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11");
                vertex = vertices + nextColumnIndex * 12;
                D_00713D10[0] = ((RwV3d *)vertex)[-5].x;
                D_00713D14[0] = ((RwV3d *)vertex)[-5].y;
                D_00713D18[0] = ((RwV3d *)vertex)[-5].z;
                effectVuLoad10((EffectVuVector *)D_00713D10);
                effectVuScale11(stepLength + drift[nextColumnIndex]);
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
                ((RwV3d *)vertex)[0].x = D_00713D10[0];
                ((RwV3d *)vertex)[0].y = D_00713D14[0];
                ((RwV3d *)vertex)[0].z = D_00713D18[0];
                drift[nextColumnIndex] = offset;
            }
        }
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry;
        func_003c22f0(vertices);
        if ((geometryBlock->kind & 4) != 0) {
            ((RpGeometry *)vertices)->lockedSinceLastInst |= 1;
        }
advance:
        boltEntry->age = boltEntry->age + 1;
    }
}
#pragma pop


// Writes the orbiting thunder bolt colour rows from the bolt state (union colour pack).
// FUN_00497460
void ThunderOrbitBoltWriteRows(u8 *effect)
{
    u8 *block;
    u8 *parameters;
    u8 *bolt;
    s32 age;
    s32 durationOrCopies;
    u8 materialColor[4];
    s32 baseColor;
    s32 sampledColor;
    s32 boltColor;
    s32 modulatedColor;
    f32 colorFactors[4];
    s32 sample;
    f32 scale;
    s32 copyIndex;
    u8 *geometry;
    u8 *material;
    f32 matrix[16];

    block = ((EffThunderInstance *)effect)->work.bytes;
    parameters = ((EffThunderInstance *)effect)->parameters.bytes;
    bolt = ((EffThunderOrbitList *)block)->entries;
    age = ((EffThunderInstance *)effect)->age.signedValue;
    durationOrCopies = ((EffThunderParameters *)parameters)->duration.signedValue;
    if ((durationOrCopies >= age) || (durationOrCopies == 0))
    {
        s32 *colorWord;

        durationOrCopies = ((EffThunderParameters *)parameters)->copies.signedValue;
        sample = (s32)mdlEffectSamplePackedColor(parameters, parameters + 0x24, age, ((EffThunderParameters *)parameters)->duration.signedValue);
        baseColor = ((EffThunderInstance *)effect)->packedColor.signedValue;
        colorWord = &baseColor;
        scale = iGpffff8044;
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
            : "r"(colorWord), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = sample;
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
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(colorFactors) : "memory");
        GeometryMatrixBuild(&matrix[0], effect, effect + 0x10, ((EffThunderInstance *)effect)->scale.value);
        copyIndex = 0;
        while (copyIndex < durationOrCopies)
        {
            if (((EffThunderOrbitBolt *)bolt)->age > 0)
            {
                geometry = ((EffThunderOrbitBolt *)bolt)->geometry;
                func_003e9cb0(((EffGeometryBlock *)geometry)->frame, &matrix[0], 0);
                boltColor = ((EffThunderOrbitBolt *)bolt)->color.signedValue;
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
                    :
                    : "r"(&boltColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)     \n"
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0xCC($sp)      \n"
                    :
                    : "r"(colorFactors)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: mwcc b210 hoists the modulatedColor reload above the inline COP2
                   store and serves a stale value, so the post-asm read is volatile. */
                *(s32 *)materialColor = *(volatile s32 *)&modulatedColor;
                if (materialColor[3] != 0xFF)
                {
                    material = ((EffGeometryBlock *)geometry)->material;
                    ((RpMaterial *)material)->color = *(Color4 *)materialColor;
                }
                else
                {
                    materialColor[3] = 0xFE;
                    material = ((EffGeometryBlock *)geometry)->material;
                    ((RpMaterial *)material)->color = *(Color4 *)materialColor;
                    materialColor[3] = 0xFF;
                }
                if (((EffThunderParameters *)parameters)->visible != 0)
                {
                    ((EffGeometryBlock *)geometry)->kind = ((EffGeometryBlock *)geometry)->kind | 1;
                }
                else
                {
                    ((EffGeometryBlock *)geometry)->kind = ((EffGeometryBlock *)geometry)->kind & 0xFFFE;
                }
                {
                    s32 resource = ((EffThunderParameters *)parameters)->resource;
                    GeometryBlockBindResource(geometry, resource);
                }
            }
            copyIndex++;
            bolt += 0x30;
        }
    }
}



// Initialises each paired thunder state word to a random negative value from -1 to -4.
// FUN_004976D0
void ThunderPairedInitStates(u8 *effect)
{
    u32 *boltWords;
    u32 copyCount;
    u32 copyIndex;

    boltWords = (u32 *)((EffThunderList *)((EffThunderInstance *)effect)->work.bytes)->entries;
    copyCount = ((EffThunderParameters *)((EffThunderInstance *)effect)->parameters.bytes)->copies.value;
    copyIndex = 0;
    while (copyIndex < copyCount)
    {
        boltWords[1] = -1 - (effMiscRand(0) & 3);
        copyIndex++;
        boltWords += 3;
    }
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Native b210 O2: 1280/1280 bytes and eleven resolved relocations.
 * Sample zero and odd samples calculate a new fade; the following even
 * sample reuses it. The five packed colors form one twenty-byte row.
 * See docs/probe_archive/Thunder_constructor_00497750_20260924.md. */
// Creates a paired thunder geometry: makes the segment count odd, allocates the geometry copies and writes five-colour rows.
// FUN_00497750
u8 *ThunderPairedGeometryCreate(u8 *parameters)
{
    /* Earlier parameter-only probe: normalized_diff 804; separate typed locals now preserve the original reload lifetimes. */
    u32 rgb0;
    u32 rgb1;
    u32 rgb2;
    u32 fadeEnd;
    u8 *list;
    u8 *entry;
    u32 copyCount;
    u32 copyIndex;
    u32 color0;
    u32 color1;
    u32 color2;
    u32 alpha0;
    u32 alpha1;
    u32 alpha2;
    s32 fadeStart;
    f32 sampleTotal;
    u8 *geometry;
    s32 sampleCount;
    s32 endIndex;
    s32 fadeOutCount;
    f32 scaledAlpha;
    f32 fade;
    u32 alpha;
    EffThunderParameters *settings = (EffThunderParameters *)parameters;

    copyCount = settings->copies.value;
    chkmemAllocSiteTag(D_00713E50, 0x499);
    list = (*jtbl_008873E8)(copyCount * 0x0C + 4, 0x40000);
    if (list == 0) {
        kAssertFail(D_00713E50, 0x49A);
    }
    ((EffThunderList *)list)->entries = list + 4;
    if (settings->segments.value < 3) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        settings->segments.value = 3;
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    if ((settings->segments.value & 1) == 0) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        settings->segments.value += 1;
    }
    color0 = settings->centerColor;
    rgb0 = color0 & 0xFFFFFF;
    color1 = settings->innerColor;
    rgb1 = color1 & 0xFFFFFF;
    color2 = settings->outerColor;
    rgb2 = color2 & 0xFFFFFF;
    alpha0 = color0 >> 24;
    alpha1 = color1 >> 24;
    alpha2 = color2 >> 24;
    entry = ((EffThunderList *)list)->entries;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    sampleTotal = (f32)(settings->segments.signedValue + 1);
    fadeStart = (s32)(settings->fadeStart * sampleTotal);
    endIndex = (s32)(settings->fadeEnd * sampleTotal);
    fadeEnd = (u32)endIndex;
    /* Retail retains this initial value across geometry allocations. */
    fade = 0.0f;
    copyIndex = 0;
    while (copyIndex < copyCount) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        geometry = GeometryCreateStripGrid(settings->segments.low, D_00713360, 5, 0x48);
        ((EffThunderPairedBolt *)entry)->geometry = geometry;
        sampleCount = ((EffGeometryBlock *)geometry)->vertexCount / 5;
        {
            u32 sampleIndex;
            u8 *colors;
            EffThunderColorRow *colorRow;

            colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry->colors;
            sampleIndex = 0;
            fadeOutCount = sampleCount - (s32)fadeEnd;
            while (sampleIndex < (u32)sampleCount) {
                colorRow = (EffThunderColorRow *)colors;
                if ((sampleIndex & 1) || (sampleIndex == 0)) {
                    if (sampleIndex < (u32)fadeStart) {
                        scaledAlpha = (f32)sampleIndex;
                        fade = scaledAlpha / (f32)fadeStart;
                    } else if (fadeEnd < sampleIndex) {
                        s32 remainingSamples = sampleCount - (s32)sampleIndex - 1;
                        f32 remainingFade = (f32)(u32)remainingSamples;
                        f32 fadeLength = (f32)(u32)fadeOutCount;
                        fade = remainingFade / fadeLength;
                    } else {
                        fade = 1.0f;
                    }
                }
                scaledAlpha = (f32)alpha2 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[0].packed = rgb2 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha1 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[1].packed = rgb1 | ((u32)alpha << 24);
                scaledAlpha = (f32)alpha0 * fade;
                alpha = (u32)scaledAlpha;
                colorRow->colors[2].packed = rgb0 | ((u32)alpha << 24);
                {
                    Color4 color1;
                    Color4 color0;
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    color1 = colorRow->colors[1].rgba;
                    colorRow->colors[3].rgba = color1;
                    color0 = colorRow->colors[0].rgba;
                    colorRow->colors[4].rgba = color0;
                }
                colors += 0x14;
                sampleIndex += 1;
            }
        }
        {
            s32 value = -1;
            value -= (s32)(copyIndex * 4);
            ((EffThunderPairedBolt *)entry)->age = value;
        }
        copyIndex += 1;
        entry += 0x0C;
    }
    return list;
}
#pragma pop


// Frees each paired thunder geometry copy, then the block.
// FUN_00497C50
void ThunderPairedGeometryDestroy(u8 *effect)
{
    u8 *block;
    u8 **geometrySlot;
    u32 copyCount;
    u32 copyIndex;

    block = ((EffThunderInstance *)effect)->work.bytes;
    geometrySlot = *(u8 ***)block;
    copyCount = ((EffThunderParameters *)((EffThunderInstance *)effect)->parameters.bytes)->copies.value;
    copyIndex = 0;
    while (copyIndex < copyCount)
    {
        GeometryBlockDestroy(*geometrySlot);
        copyIndex++;
        geometrySlot += 3;
    }
    jtbl_008873EC[0](block);
}


/* The row loop's two vector carries (tangent -> previousTangent,
 * nextPosition -> position) are lq/sq copies through $2, as in
 * func_00485630; the $2 clobber is what moves every pointer live across
 * them up one register in retail. `invalid` is assigned first in the
 * preheader because retail hoists the -1 before the float constants. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
// Updates the paired thunder strip: a row loop carries the tangent and position vectors and rebuilds each row.
// FUN_00497CE0
void ThunderPairedUpdateStrip(u8 *effect)
{
    /* Earlier whole-layout probe: normalized_diff 1305; separate typed locals now preserve the original reload lifetimes. */
    extern void mdlEffectCopyCameraOrigin(f32 *output);
    extern void effMiscBuildRotationVU(void);
    extern f32 sinf(f32 angle);
    extern void effMiscAxisAngleVU(f32 axis, f32 *angle);
    extern void func_003c22f0(u8 *geometry);
    extern f32 fGpffff8084;
    extern f32 fGpffff80d0;
    extern f32 fGpffff80d8;
    extern f32 iGpffff80d4;
    extern EffectVuVector D_00713CE0;
    extern EffectVuVector D_00713D00;
    extern f32 D_00713D10[];
    extern f32 D_00713D14[];
    extern f32 D_00713D18[];
    EffectVuVector innerExtent;
    EffectVuVector outerExtent;
    EffectVuVector outerFlip;
    EffectVuVector direction;
    EffectVuVector side;
    EffectVuVector tangent;
    EffectVuVector previousTangent;
    EffectVuVector position;
    EffectVuVector nextPosition;
    EffectVuVector up;
    EffectVuVector step;
    f32 spacing;
    f32 phase;
    f32 cycle;
    f32 sample;
    f32 wave;
    f32 amplitude;
    f32 period;
    f32 twoPi;
    f32 four;
    f32 waveRange;
    f32 two;
    f32 current;
    f32 one;
    f32 half;
    f32 swing;
    f32 zero;
    f32 previous;
    u8 *parameters;
    u8 *block;
    u8 *bolt;
    EffThunderPairedBolt *boltEntry;
    s32 copyCount;
    s32 respawnRange;
    s32 rowIndex;
    s32 copyIndex;
    u8 *geometry;
    EffGeometryBlock *geometryBlock;
    s32 rowCount;
    u8 *vertices;
    u32 state;
    u32 invalid;

    block = ((EffThunderInstance *)effect)->work.bytes;
    parameters = ((EffThunderInstance *)effect)->parameters.bytes;
    bolt = ((EffThunderList *)block)->entries;
    if ((((EffThunderParameters *)parameters)->duration.value < ((EffThunderInstance *)effect)->age.value) && (((EffThunderParameters *)parameters)->duration.value != 0)) {
        return;
    }
    copyCount = ((EffThunderParameters *)parameters)->copies.signedValue;
    respawnRange = ((EffThunderParameters *)parameters)->respawnRange;
    mdlEffectCopyCameraOrigin(up.lane);
    effectVuLoad10(&D_00713CE0);
    __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
    {
        f32 inner = ((EffThunderParameters *)parameters)->innerWidth;

        effectVuScale10(inner);
        effectVuStore10(&innerExtent);
        __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10");
        effectVuScale10(inner + ((EffThunderParameters *)parameters)->outerWidth);
    }
    effectVuStore10(&outerExtent);
    __asm__ volatile("vsub.xyz $vf10, $vf0, $vf10" : : : "$vf10");
    effectVuStore10(&outerFlip);
    effectVuLoad10((EffectVuVector *)(effect + 0x10));
    effMiscBuildRotationVU();
    effectVuLoad10(&D_00713D00);
    __asm__ volatile(
        "vmulax.xyzw $ACC, $vf28, $vf10x\n"
        "vmadday.xyzw $ACC, $vf29, $vf10y\n"
        "vmaddz.xyzw $vf10, $vf30, $vf10z\n" : : : "$vf10");
    effectVuScale10(((EffThunderParameters *)parameters)->length);
    {
        f32 length;

        /* Retail moves the vsqrt result through $2 (cfc2/mtc1 bridge). */
        __asm__ volatile(
            "vmove.xyzw $vf11, $vf0\n"
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vaddy.x $vf2, $vf2, $vf2y\n"
            "vaddz.x $vf2, $vf2, $vf2z\n"
            "vsqrt $Q, $vf2x\n"
            "vwaitq\n"
            "cfc2.ni $2, $vi22\n"
            "mtc1 $2, %0\n"
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n" : "=f"(length) : : "$2", "$vf2", "$vf10", "$vf11");
        effectVuStore10(&direction);
        spacing = (f32)((EffThunderParameters *)parameters)->segments.value;
        two = 2.0f;
        spacing = (two * length) / spacing;
    }
    amplitude = ((EffThunderParameters *)parameters)->pairedAmplitude;
    wave = amplitude;
    copyIndex = 0;
    invalid = 0xFFFFFFFF;
    period = fGpffff80d0;
    zero = 0.0f;
    twoPi = fGpffff8084;
    four = 4.0f;
    waveRange = iGpffff80d4;
    one = 1.0f;
    half = 0.5f;
    swing = fGpffff80d8;
    for (; copyIndex < copyCount; copyIndex++, bolt += 0xC) {
        boltEntry = (EffThunderPairedBolt *)bolt;
        if (boltEntry->age == -1) {
            boltEntry->color.value = invalid;
            goto advance;
        }
        state = boltEntry->color.value;
        if ((state & 0xFF000000) > 0x40000000U) {
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            boltEntry->color.value = state + 0xC0000000;
        } else {
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            boltEntry->age = -1;
            if (respawnRange > 0) {
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                boltEntry->age = boltEntry->age - effMiscRand(0) % respawnRange;
            }
            continue;
        }
        geometry = boltEntry->geometry;
        geometryBlock = (EffGeometryBlock *)geometry;
        rowCount = (geometryBlock->vertexCount / 5) >> 1;
        RpGeometryLock(((RpAtomic *)geometryBlock->atomic)->geometry, 2);
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry->morphTarget->vertices;
        effectVuLoad10(&up);
        effectVuLoad11(&direction);
        __asm__ volatile(
            "vopmula.xyz $ACC, $vf10, $vf11\n"
            "vopmsub.xyz $vf10, $vf11, $vf10\n"
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
        effectVuStore10(&side);
        phase = period * effMiscRandFloat(0);
        cycle = phase - period;
        sample = wave * sinf(phase);
        effectVuLoad10(&side);
        effectVuScale10(sample);
        effectVuStore10(&position);
        current = wave * sinf(phase);
        {
            f32 rise = current - sample;

            effectVuLoad10(&direction);
            effectVuScale10(spacing);
            __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
            effectVuLoad10(&side);
            effectVuScale10(rise);
        }
        __asm__ volatile(
            "vadd.xyzw $vf10, $vf10, $vf12\n"
            "vmove.xyzw $vf12, $vf10\n" : : : "$vf10", "$vf12");
        effectVuLoad11(&position);
        __asm__ volatile("vadd.xyzw $vf11, $vf11, $vf10" : : : "$vf11");
        effectVuStore11(&nextPosition);
        __asm__ volatile(
            "vmove.xyzw $vf10, $vf12\n"
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vmulax.w $ACC, $vf0, $vf2x\n"
            "vmadday.w $ACC, $vf0, $vf2y\n"
            "vmaddz.w $vf2, $vf0, $vf2z\n"
            "vrsqrt $Q, $vf0w, $vf2w\n"
            "vwaitq\n"
            "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
        effectVuStore10(&tangent);
        sample = four * (twoPi / (f32)rowCount);
        for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
            u8 *nextRow;

            effectVuLoad10(&tangent);
            effectVuLoad11(&up);
            __asm__ volatile(
                "vopmula.xyz $ACC, $vf10, $vf11\n"
                "vopmsub.xyz $vf10, $vf11, $vf10\n"
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
            effectVuStore10(&tangent);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            effectVuLoad10(&position);
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[2].x = D_00713D10[0];
            ((RwV3d *)vertices)[2].y = D_00713D14[0];
            ((RwV3d *)vertices)[2].z = D_00713D18[0];
            __asm__ volatile("vmove.xyzw $vf10, $vf11" : : : "$vf10");
            effectVuLoad11(&innerExtent);
            __asm__ volatile(
                "vmul.xyzw $vf10, $vf10, $vf11\n"
                "vmove.xyzw $vf12, $vf10\n" : : : "$vf10", "$vf12");
            effectVuLoad10(&position);
            __asm__ volatile(
                "vmove.xyzw $vf11, $vf10\n"
                "vadd.xyzw $vf10, $vf10, $vf12\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[1].x = D_00713D10[0];
            ((RwV3d *)vertices)[1].y = D_00713D14[0];
            ((RwV3d *)vertices)[1].z = D_00713D18[0];
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vsub.xyzw $vf11, $vf11, $vf10\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[3].x = D_00713D10[0];
            ((RwV3d *)vertices)[3].y = D_00713D14[0];
            ((RwV3d *)vertices)[3].z = D_00713D18[0];
            effectVuLoad10(&tangent);
            effectVuLoad11(&outerExtent);
            __asm__ volatile(
                "vmul.xyzw $vf10, $vf10, $vf11\n"
                "vmove.xyzw $vf12, $vf10\n" : : : "$vf10", "$vf12");
            effectVuLoad10(&position);
            __asm__ volatile(
                "vmove.xyzw $vf11, $vf10\n"
                "vadd.xyzw $vf10, $vf10, $vf12\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[0].x = D_00713D10[0];
            ((RwV3d *)vertices)[0].y = D_00713D14[0];
            ((RwV3d *)vertices)[0].z = D_00713D18[0];
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vsub.xyzw $vf11, $vf11, $vf10\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[4].x = D_00713D10[0];
            ((RwV3d *)vertices)[4].y = D_00713D14[0];
            ((RwV3d *)vertices)[4].z = D_00713D18[0];
            nextRow = vertices + 0x3C;
            {
                u_long128 *dst = (u_long128 *)&previousTangent;
                u_long128 *src = (u_long128 *)&tangent;

                /* lint: allow H009 -- retail copies this quad through $2 at 0x0049825C; b210 keeps $v0 live (user-approved 2026-10-09) */
                __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(dst), "r"(src) : "$2", "memory");
            }
            {
                u_long128 *dst = (u_long128 *)&position;
                u_long128 *src = (u_long128 *)&nextPosition;

                /* lint: allow H009 -- retail copies this quad through $2 at 0x00498268; b210 keeps $v0 live (user-approved 2026-10-09) */
                __asm__ volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(dst), "r"(src) : "$2", "memory");
            }
            effectVuLoad10(&position);
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[7].x = D_00713D10[0];
            ((RwV3d *)vertices)[7].y = D_00713D14[0];
            ((RwV3d *)vertices)[7].z = D_00713D18[0];
            effectVuLoad10(&tangent);
            effectVuLoad11(&innerExtent);
            __asm__ volatile(
                "vmul.xyzw $vf10, $vf10, $vf11\n"
                "vmove.xyzw $vf12, $vf10\n" : : : "$vf10", "$vf12");
            effectVuLoad10(&position);
            __asm__ volatile(
                "vmove.xyzw $vf11, $vf10\n"
                "vadd.xyzw $vf10, $vf10, $vf12\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[6].x = D_00713D10[0];
            ((RwV3d *)vertices)[6].y = D_00713D14[0];
            ((RwV3d *)vertices)[6].z = D_00713D18[0];
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vsub.xyzw $vf11, $vf11, $vf10\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[8].x = D_00713D10[0];
            ((RwV3d *)vertices)[8].y = D_00713D14[0];
            ((RwV3d *)vertices)[8].z = D_00713D18[0];
            effectVuLoad10(&tangent);
            effectVuLoad11(&outerExtent);
            __asm__ volatile(
                "vmul.xyzw $vf10, $vf10, $vf11\n"
                "vmove.xyzw $vf12, $vf10\n" : : : "$vf10", "$vf12");
            effectVuLoad10(&position);
            __asm__ volatile(
                "vmove.xyzw $vf11, $vf10\n"
                "vadd.xyzw $vf10, $vf10, $vf12\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[5].x = D_00713D10[0];
            ((RwV3d *)vertices)[5].y = D_00713D14[0];
            ((RwV3d *)vertices)[5].z = D_00713D18[0];
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vsub.xyzw $vf11, $vf11, $vf10\n" : : : "$vf10", "$vf11");
            __asm__ volatile("sqc2 $vf11, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[9].x = D_00713D10[0];
            ((RwV3d *)vertices)[9].y = D_00713D14[0];
            ((RwV3d *)vertices)[9].z = D_00713D18[0];
            vertices = nextRow + 0x3C;
            phase += sample;
            cycle += sample;
            if (!(cycle <= twoPi)) {
                cycle -= twoPi;
                wave = amplitude * (one - waveRange * effMiscRandFloat(0));
            }
            previous = current;
            current = wave * sinf(phase);
            {
                f32 rise = current - previous;

                effectVuLoad10(&direction);
                effectVuScale10(spacing);
                __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
                effectVuLoad10(&side);
                effectVuScale10(rise);
            }
            __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf12" : : : "$vf10");
            effectVuStore10(&step);
            effMiscAxisAngleVU(swing * (two * (effMiscRandFloat(0) - half)), up.lane);
            effectVuLoad10(&step);
            __asm__ volatile(
                "vmulax.xyzw $ACC, $vf28, $vf10x\n"
                "vmadday.xyzw $ACC, $vf29, $vf10y\n"
                "vmaddz.xyzw $vf10, $vf30, $vf10z\n"
                "vmove.xyzw $vf12, $vf10\n" : : : "$vf10", "$vf12");
            effectVuLoad11(&position);
            __asm__ volatile("vadd.xyzw $vf11, $vf11, $vf10" : : : "$vf11");
            effectVuStore11(&nextPosition);
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf12\n"
                "vmul.xyz $vf2, $vf10, $vf10\n"
                "vmulax.w $ACC, $vf0, $vf2x\n"
                "vmadday.w $ACC, $vf0, $vf2y\n"
                "vmaddz.w $vf2, $vf0, $vf2z\n"
                "vrsqrt $Q, $vf0w, $vf2w\n"
                "vwaitq\n"
                "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
            effectVuStore10(&tangent);
            {
                f32 dot;
                u8 *anchor;

                effectVuLoad10(&nextPosition);
                effectVuLoad11(&position);
                __asm__ volatile(
                    "vsub.xyzw $vf10, $vf10, $vf11\n"
                    "vmul.xyz $vf2, $vf10, $vf10\n"
                    "vmulax.w $ACC, $vf0, $vf2x\n"
                    "vmadday.w $ACC, $vf0, $vf2y\n"
                    "vmaddz.w $vf2, $vf0, $vf2z\n"
                    "vrsqrt $Q, $vf0w, $vf2w\n"
                    "vwaitq\n"
                    "vmulq.xyz $vf10, $vf10, $Q\n" : : : "$vf2", "$vf10");
                effectVuLoad11(&previousTangent);
                /* Retail moves the dot product through $2 (qmfc2/mtc1 bridge). */
                __asm__ volatile(
                    "vmul.xyz $vf2, $vf10, $vf11\n"
                    "vaddy.x $vf2, $vf2, $vf2y\n"
                    "vaddz.x $vf2, $vf2, $vf2z\n"
                    "qmfc2.ni $2, $vf2\n"
                    "mtc1 $2, %0\n" : "=f"(dot) : : "$2", "$vf2");
                if (dot < zero) {
                    anchor = vertices - 0xC;
                    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&outerExtent), "m"(outerExtent) : "$vf12");
                } else {
                    anchor = vertices - 0x3C;
                    __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&outerFlip), "m"(outerFlip) : "$vf12");
                }
                effectVuLoad10(&tangent);
                effectVuLoad11(&up);
                __asm__ volatile(
                    "vopmula.xyz $ACC, $vf10, $vf11\n"
                    "vopmsub.xyz $vf10, $vf11, $vf10\n"
                    "vmul.xyz $vf2, $vf10, $vf10\n"
                    "vmulax.w $ACC, $vf0, $vf2x\n"
                    "vmadday.w $ACC, $vf0, $vf2y\n"
                    "vmaddz.w $vf2, $vf0, $vf2z\n"
                    "vrsqrt $Q, $vf0w, $vf2w\n"
                    "vwaitq\n"
                    "vmulq.xyz $vf10, $vf10, $Q\n"
                    "vmove.xyzw $vf11, $vf12\n"
                    "vmul.xyzw $vf10, $vf10, $vf11\n" : : : "$vf2", "$vf10", "$vf11");
                D_00713D10[0] = ((RwV3d *)anchor)[0].x;
                D_00713D14[0] = ((RwV3d *)anchor)[0].y;
                D_00713D18[0] = ((RwV3d *)anchor)[0].z;
                effectVuLoad11((EffectVuVector *)D_00713D10);
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                effectVuStore10(&position);
            }
        }
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry;
        func_003c22f0(vertices);
        if ((geometryBlock->kind & 4) != 0) {
            ((RpGeometry *)vertices)->lockedSinceLastInst |= 1;
        }
advance:
        boltEntry->age = boltEntry->age + 1;
    }
}
#pragma pop


// Writes the paired thunder colour rows from the strip state (union colour pack).
// FUN_00498650
void ThunderPairedWriteRows(u8 *effect)
{
    u8 *block;
    u8 *parameters;
    u8 *bolt;
    s32 age;
    s32 durationOrCopies;
    u8 materialColor[4];
    s32 baseColor;
    s32 sampledColor;
    s32 boltColor;
    s32 modulatedColor;
    f32 colorFactors[4];
    s32 sample;
    f32 scale;
    s32 copyIndex;
    u8 *geometry;
    u8 *material;
    f32 matrix[16];

    block = ((EffThunderInstance *)effect)->work.bytes;
    parameters = ((EffThunderInstance *)effect)->parameters.bytes;
    bolt = ((EffThunderList *)block)->entries;
    age = ((EffThunderInstance *)effect)->age.signedValue;
    durationOrCopies = ((EffThunderParameters *)parameters)->duration.signedValue;
    if ((durationOrCopies >= age) || (durationOrCopies == 0))
    {
        s32 *colorWord;

        durationOrCopies = ((EffThunderParameters *)parameters)->copies.signedValue;
        sample = (s32)mdlEffectSamplePackedColor(parameters, parameters + 0x24, age, ((EffThunderParameters *)parameters)->duration.signedValue);
        baseColor = ((EffThunderInstance *)effect)->packedColor.signedValue;
        colorWord = &baseColor;
        scale = iGpffff8044;
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
            : "r"(colorWord), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sampledColor = sample;
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
            :
            : "r"(&sampledColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(colorFactors) : "memory");
        GeometryMatrixBuild(&matrix[0], effect, 0, ((EffThunderInstance *)effect)->scale.value);
        copyIndex = 0;
        while (copyIndex < durationOrCopies)
        {
            if (((EffThunderPairedBolt *)bolt)->age > 0)
            {
                geometry = ((EffThunderPairedBolt *)bolt)->geometry;
                func_003e9cb0(((EffGeometryBlock *)geometry)->frame, &matrix[0], 0);
                boltColor = ((EffThunderPairedBolt *)bolt)->color.signedValue;
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
                    :
                    : "r"(&boltColor), "f"(scale)
                    : "$2", "$vf2", "$vf10", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)     \n"
                    "vmul.xyzw $vf10, $vf10, $vf11 \n"
                    "lui $2, 0x437F        \n"
                    "qmtc2.ni $2, $vf2     \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni $2, $vf10    \n"
                    "ppach $2, $0, $2      \n"
                    "ppacb $2, $0, $2      \n"
                    "sw $2, 0xCC($sp)      \n"
                    :
                    : "r"(colorFactors)
                    : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: mwcc b210 hoists the modulatedColor reload above the inline COP2
                   store and serves a stale value, so the post-asm read is volatile. */
                *(s32 *)materialColor = *(volatile s32 *)&modulatedColor;
                if (materialColor[3] != 0xFF)
                {
                    material = ((EffGeometryBlock *)geometry)->material;
                    ((RpMaterial *)material)->color = *(Color4 *)materialColor;
                }
                else
                {
                    materialColor[3] = 0xFE;
                    material = ((EffGeometryBlock *)geometry)->material;
                    ((RpMaterial *)material)->color = *(Color4 *)materialColor;
                    materialColor[3] = 0xFF;
                }
                if (((EffThunderParameters *)parameters)->visible != 0)
                {
                    ((EffGeometryBlock *)geometry)->kind = ((EffGeometryBlock *)geometry)->kind | 1;
                }
                else
                {
                    ((EffGeometryBlock *)geometry)->kind = ((EffGeometryBlock *)geometry)->kind & 0xFFFE;
                }
                {
                    s32 resource = ((EffThunderParameters *)parameters)->resource;
                    GeometryBlockBindResource(geometry, resource);
                }
            }
            copyIndex++;
            bolt += 0xC;
        }
    }
}



// Allocates a thunder effect for a kind below five, copies its parameters and runs the kind initializer.
// FUN_004988C0
u8 *ThunderTextureForIndex(u16 kind, u8 *parameters)
{
    u8 *effect;
    s32 parameterSize;
    u32 kindIndex;

    if (kind >= 5)
    {
        kAssertFail(D_00713E50, 0x6A1);
    }
    kindIndex = kind;
    parameterSize = D_00713E84[kindIndex * 6];
    chkmemAllocSiteTag(D_00713E50, 0x6A5);
    effect = (u8 *)(*jtbl_008873E8)(parameterSize + 0x40, 0x40000);
    if (effect == NULL)
    {
        kAssertFail(D_00713E50, 0x6A6);
    }
    ((EffThunderInstance *)effect)->parameters.bytes = effect + 0x40;
    ((EffThunderInstance *)effect)->age.value = 0;
    ((EffThunderInstance *)effect)->kind = kindIndex;
    ((EffThunderInstance *)effect)->packedColor.value = -1;
    ((EffThunderInstance *)effect)->scale.bits = 0x3F800000;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(effect) : "memory");
    __asm__ volatile("sqc2 vf0, 0x10(%0)" : : "r"(effect) : "memory");
    memcpy(((EffThunderInstance *)effect)->parameters.pointer, parameters, parameterSize);
    ((EffThunderInstance *)effect)->work.value = ((u32 (*)(u8 *))D_00713E74[kind * 6])(parameters);
    ((void (*)(u8 *))D_00713E70[kind * 6])(effect);
    return effect;
}


// Resolves an object's thunder parameters and creates the effect selected by the source descriptor kind.
// FUN_00498A30
void *ThunderTextureForObject(void *source)
{
    u8 *effect;

    effect = mdlEffectResolveRelPtrA(source);
    if (effect == NULL)
    {
        kAssertFail(D_00713E50, 0x6C9);
    }
    effect = ThunderTextureForIndex(((EffSourceDescriptor *)source)->id, effect);
    if (effect == NULL)
    {
        kAssertFail(D_00713E50, 0x6CB);
    }
    return effect;
}
