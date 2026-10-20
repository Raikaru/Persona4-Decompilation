#include "operand_order_internal.h"
#include "effect_vu0_internal.h"
#include "rw_geometry_internal.h"
#include "effect_geometry_internal.h"
/* Original translation unit effLineNova.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "effect_mesh_internal.h"
#include "rw_camera_internal.h"

void GeometryBlockDestroy(void *block);
void chkmemAllocSiteTag(u8 *file, s32 line);
void kAssertFail(u8 *file, s32 line);
void *TnGetOffset1C(u16 slotIndex);
void *TnGetIndexedWord(u16 slotIndex);
void PrimAppendNode(void *list, void *node);
void memcpy(void *dst, const void *src, u32 size);
void LineNovaUpdateVertices(u8 *unused, u8 *effect);

extern u8 D_00713310[];
extern u8 D_00714628[];
extern u8 D_00714650[];
extern u8 D_00714654[];
extern u8 D_00714664[];
extern u8 D_00724C54[];

/* 4-byte color state at 0x00724C54..57, accessed gp-relative in retail */
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} LineNovaColor;

extern LineNovaColor iGpffffbb64;  // 0x00724C54
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);


typedef struct LineNovaMaterial {
    u32 texture;
    LineNovaColor color;
} LineNovaMaterial;

/* Linker aliases address descriptor columns at a 0x18-byte stride. */
typedef struct LineNovaTypeSize {
    s32 dataBytes;
    u8 pad04[0x14];
} LineNovaTypeSize;
typedef struct LineNovaTypeInitializer {
    s32 (*initialize)(u8 *parameters);
    u8 pad04[0x14];
} LineNovaTypeInitializer;
typedef struct LineNovaTypeSetup {
    void (*setup)(u8 *effect);
    u8 pad04[0x14];
} LineNovaTypeSetup;

/* Allocations prove the effect (0x30), state (0x10) and particle (8 or 6)
 * sizes. The two nova modes interpret the configuration tail differently;
 * unions retain those observed word, halfword and byte representations. */
typedef struct LineNovaConfiguration {
    u8 pad00[0x28];
    u16 resourceId; /* +0x28 */
    u8 pad2A[0xA];
    union {
        s32 signedValue;
        u32 unsignedValue;
    } duration; /* +0x34 */
    union {
        s32 signedValue;
        u32 unsignedValue;
    } particleCount; /* +0x38 */
    u8 pad3C[0x10];
    s32 delay; /* +0x4C */
    u8 pad50[0x4];
    u32 firstColor; /* +0x54 */
    u32 secondColor; /* +0x58 */
    f32 width; /* +0x5C */
    f32 spread; /* +0x60 */
    f32 alphaVariation; /* +0x64 */
    u8 resourceKind; /* +0x68 */
    u8 pad69[0x13];
    union {
        s16 signedHalf[2];
        u32 unsignedValue;
        u8 byte[4];
    } unk7C; /* +0x7C */
    union {
        s16 signedHalf[2];
    } unk80; /* +0x80 */
    union {
        f32 scalar;
        s16 signedHalf[2];
    } unk84; /* +0x84 */
    union {
        f32 scalar;
        s16 signedHalf[2];
    } unk88; /* +0x88 */
    union {
        s16 signedHalf[2];
    } unk8C; /* +0x8C */
    union {
        s16 signedHalf[2];
        u8 byte[4];
    } unk90; /* +0x90 */
    f32 unk94; /* +0x94 */
} LineNovaConfiguration;

typedef struct LineNovaState {
    union {
        u16 * u16Pointer;
        u8 * bytes;
    } particles; /* +0x00 */
    union {
        u16 * u16Pointer;
        u8 * bytes;
        void * pointer;
    } geometry; /* +0x04 */
    union {
        u8 * bytes;
        void * pointer;
    } allocation; /* +0x08 */
    u8 pad0C[0x4];
} LineNovaState;

typedef struct LineNovaColors {
    union {
        s32 signedValue;
        u32 unsignedValue;
    } unk00; /* +0x00 */
    union {
        s32 signedValue;
        u32 unsignedValue;
    } unk04; /* +0x04 */
    union {
        s32 signedValue;
        u32 unsignedValue;
    } unk08; /* +0x08 */
    u32 unk0C; /* +0x0C */
    u32 unk10; /* +0x10 */
    u32 unk14; /* +0x14 */
} LineNovaColors;

typedef struct LineNovaEffect {
    u8 pad00[0x10];
    union {
        s32 signedValue;
        u32 unsignedValue;
    } color; /* +0x10 */
    union {
        s32 signedValue;
        u32 unsignedValue;
    } elapsed; /* +0x14 */
    s32 kind; /* +0x18 */
    s32 delay; /* +0x1C */
    union {
        s32 signedValue;
        u8 * bytes;
    } state; /* +0x20 */
    union {
        u8 * bytes;
        void * pointer;
    } configuration; /* +0x24 */
    u8 pad28[0x8];
} LineNovaEffect;

typedef struct LineNovaParticle {
    u16 edgePosition;
    u8 alpha;
    u8 pad03;
    union { f32 scalar; u32 bits; } scale;
} LineNovaParticle;

typedef struct LineNovaGeometry {
    u16 kind; /* +0x00 */
    u8 pad02[0xA];
    u8 * frame; /* +0x0C */
    u8 * atomic; /* +0x10 */
    u8 * material; /* +0x14 */
    s32 nodeNext; /* +0x18 */
    s32 nodePrevious; /* +0x1C */
    s32 update; /* +0x20 */
    u8 pad24[0x4];
    s32 owner; /* +0x28 */
    u8 pad2C[0x1C];
} LineNovaGeometry;

typedef struct LineNovaCameraWindow {
    f32 x; /* +0x00 */
    union {
        const f32 constf32;
        f32 scalar;
    } y; /* +0x04 */
} LineNovaCameraWindow;

typedef struct LineNovaVertexParticle {
    u16 alpha;
    u16 verticalPosition;
    u16 horizontalPosition;
} LineNovaVertexParticle;

typedef struct LineNovaMatrix {
    u8 pad00[0x30];
    f32 xTranslation; /* +0x30 */
    f32 yTranslation; /* +0x34 */
} LineNovaMatrix;

/* measured: retail colors the 7 loop-carried temps count2=$a3 v8=$t0 v6=$a2
   v5=$a1 v4=$a0 v3=$v1 i=$t1; mwcc b210 colors count2=$a1 v8=$a3 v6=$a0
   v5=$t1 v4=$v1 v3=$t0 i=$a2 (nd 20, all rows pure register renaming; object
   is otherwise byte-identical incl. hoisted count2 reload before the chain,
   the `(u32)x << 8 >> 8` dsll32/dsrl32 byte extraction, and the i++,v8+=0x18
   increment order). Tried declaration orders, s32/u32 counter+count2,
   raw-memory loop bound (mwcc rematerializes at loop bottom instead of
   hoisting to the preheader), loads-before-calls (adds a 4th saved reg),
   u64 shift spellings (all add sext+canonicalize pairs). Saved-register
   rotation floor family. */
// Creates a line-nova instance: a block for n entries, a geometry copy, then the colour rows.
// FUN_004B32F0
u8 *LineNovaCreate(u8 *config)
{
    /* Access-site typing differed by 216 normalized bytes; separate typed locals preserve the original cursor lifetimes. */
    s32 particleCount;
    u8 *state;
    u16 *geometryBlock;
    u32 particleIndex;
    u8 *colors;
    u32 firstTransparentColor;
    u32 firstColor;
    u32 secondTransparentColor;
    u32 secondColor;
    u32 count;
    LineNovaConfiguration *settings = (LineNovaConfiguration *)config;
    LineNovaState *workState;
    LineNovaColors *colorRow;

    particleCount = settings->particleCount.signedValue;
    chkmemAllocSiteTag(D_00714628, 0x43);
    state = (u8 *)(*jtbl_008873E8)(particleCount * 8 + 0x10, 0x40000);
    workState = (LineNovaState *)state;
    if (state == NULL) {
        kAssertFail(D_00714628, 0x44);
    }
    workState->particles.bytes = state + 0x10;
    workState->allocation.bytes = state;
    geometryBlock = (u16 *)GeometryCreateTableGrid(particleCount & 0xFFFF, 4, 6, D_00713310, 0x48);
    workState->geometry.u16Pointer = geometryBlock;
    *geometryBlock = *geometryBlock & 0xFFFE;
    count = settings->particleCount.signedValue;
    colors = (u8 *)((RpAtomic *)((LineNovaGeometry *)workState->geometry.bytes)->atomic)->geometry->colors;
    firstColor = settings->firstColor;
    firstTransparentColor = firstColor & 0xFFFFFF;
    secondColor = settings->secondColor;
    secondTransparentColor = secondColor & 0xFFFFFF;
    particleIndex = 0;
    while (particleIndex < count) {
        colorRow = (LineNovaColors *)colors;
        colorRow->unk00.unsignedValue = firstTransparentColor;
        colorRow->unk04.unsignedValue = firstColor;
        colorRow->unk08.unsignedValue = firstTransparentColor;
        colorRow->unk0C = secondTransparentColor;
        colorRow->unk10 = secondColor;
        colorRow->unk14 = secondTransparentColor;
        particleIndex++;
        colors += 0x18;
    }
    return state;
}

// Frees a line-nova instance: its geometry handle, then the instance block.
// FUN_004B3420
void LineNovaDestroy(u8 *state) {
    GeometryBlockDestroy(((LineNovaState *)state)->geometry.pointer);
    (*jtbl_008873EC)(((LineNovaState *)state)->allocation.pointer);
}


// Reseeds the eight-byte particle records: random 16-bit position, alpha byte and scale, then resets the delay from the emitter.
// FUN_004B3470
void LineNovaReseedParticles(u8 *effect) {
    /* Access-site typing differed by 51 normalized bytes; separate typed locals preserve the original cursor lifetimes. */
    u8 *state;
    u8 *config;
    u32 count;
    s32 progress;
    s32 delay;
    u16 *particle;
    u32 particleIndex;
    f32 scaleVariation;
    f32 alphaVariation;
    f32 minimumScale;
    f32 minimumAlpha;
    f32 minimumRandomScale;
    f32 scaleRange;
    f32 randomValue;

    LineNovaEffect *node = (LineNovaEffect *)effect;
    LineNovaConfiguration *settings;
    LineNovaParticle *entry;

    state = node->state.bytes;
    config = node->configuration.bytes;
    settings = (LineNovaConfiguration *)config;
    count = settings->particleCount.unsignedValue;
    progress = settings->duration.signedValue;
    if (progress >= node->elapsed.signedValue || progress == 0) {
        delay = node->delay - 1;
        node->delay = delay;
        if (delay <= 0) {
            minimumScale = settings->unk84.scalar / 100.0f;
            scaleVariation = settings->unk88.scalar;
            alphaVariation = settings->alphaVariation;
            particle = *(u16 **)state;
            particleIndex = 0;
            minimumAlpha = 1.0f - alphaVariation;
            minimumRandomScale = 1.0f - scaleVariation;
            scaleRange = 1.0f - minimumScale;
            while (particleIndex < count) {
                entry = (LineNovaParticle *)particle;
                randomValue = 65535.0f * effMiscRandFloat(0);
                *(u16 *)particle = (u16)randomValue;
                randomValue = 255.0f * (minimumAlpha + alphaVariation * effMiscRandFloat(0));
                entry->alpha = (u8)randomValue;
                randomValue = minimumRandomScale + scaleVariation * effMiscRandFloat(0);
                entry->scale.scalar =
                    minimumScale + scaleRange * (1.0f - randomValue);
                particleIndex++;
                particle = (u16 *)((u8 *)particle + 8);
            }
            delay = settings->delay;
            switch (delay) {
            case 0:
                delay = 0x7FFFFFFF;
                break;
            default:
                break;
            }
            node->delay = delay;
        }
    }
}




/* Project a camera-relative displacement using depth and the screen scale. */
static inline f32 novaCameraOffset(f32 center, const f32 *scale, f32 depth, f32 screen, f32 origin)
{
    f32 difference = origin - center;
    f32 factor = 2.0f * *scale;
    factor = factor * depth;
    return difference * factor / screen;
}

/* Eight-byte particles follow the four camera corners; the VU computes the
 * edge length, normalized cross product and six real XYZ vertices. Both
 * VU0 bridges that retail writes through $v0 (the colour unpack and the
 * edge-length cfc2/mtc1) name $2: the retail call result moves to $v1 before
 * the first unpack, and no loop invariant takes $v0. The call's last two
 * arguments are (s32) conversions so they load before the first two; the
 * screen products use operandOrderMultiply for retail's operand order. */
#pragma push
/* measured: baseline C nd 1287B; adjacent-local declaration probe nd 1287B; retain settings for owner MATCH. */
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
// Builds the eight-byte camera-corner particle quads (see the note above).
// FUN_004B36B0
void LineNovaUpdateCameraQuads(u8 *unused, u8 *effect)
{
    /* Access-site typing differed by 1103 normalized bytes; separate typed locals preserve the original cursor lifetimes. */

    extern s32 mdlEffectSamplePackedColor(u8 *, u8 *, s32, s32);
    extern u8 *kwlnGetCamera(void);
    extern u8 *func_003c22f0(u8 *);
    extern u8 *func_003e9700(u8 *);
    extern u8 *func_003e9cb0(u8 *, u8 *, s32);
    extern f32 fGpffff8044;
    extern u8 D_00713CF0[], D_00713D10[], D_00713D14[], D_00713D18[];
    typedef struct { u8 r, g, b, a; } NovaRgba;
    union { u32 word; u8 byte[4]; NovaRgba color; } rgba;
    u32 effectColor, sampled, packed;
    u32 sampleResult;
    const u32 *colorInput;
    u8 *instance, *state, *config, *owner;
    u8 *cameraDimensions;
    u8 *particle;
    f32 normalization;
    u32 count, index;
    f32 *vertices;

    extern u8 *func_003e42a0(u8 *, u8 *, u8 *);
    EffectVuVector projected;
    union { EffectVuVector vector; u32 word[4]; } center;
    EffectVuVector corners[4], interpolated;
    f32 farClip, xScale, yScale, xExtent, yExtent, minusX, minusY;
    f32 width, spread, divisor;
    u8 mode;

    LineNovaEffect *node;
    LineNovaConfiguration *settings;
    LineNovaState *workState;
    LineNovaGeometry *geometryBlock;
    LineNovaCameraWindow *window;

    instance = effect;
    node = (LineNovaEffect *)instance;
    state = node->state.bytes;
    workState = (LineNovaState *)state;
    config = node->configuration.bytes;
    settings = (LineNovaConfiguration *)config;
    owner = workState->geometry.bytes;
    geometryBlock = (LineNovaGeometry *)owner;

    sampleResult = (u32)mdlEffectSamplePackedColor(config, config + 0x24, (s32)node->elapsed.unsignedValue, (s32)settings->duration.unsignedValue);
    effectColor = node->color.unsignedValue;
    colorInput = &effectColor;
    normalization = fGpffff8044;
    effectVuUnpackColor10V0(colorInput, normalization);
    __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
    sampled = sampleResult;
    effectVuUnpackColor10V0(&sampled, normalization);
    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
    {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "vftoi0.xyzw $vf10, $vf10\n"
            "qmfc2.ni %0, $vf10\n"
            "ppach %0, $zero, %0\n"
            "ppacb %0, $zero, %0\n"
            "sw %0, packed\n"
            : "=&r"(transfer), "=m"(packed) : "r"(255.0f) : "$vf2", "$vf10", "memory");
    }
    rgba.word = packed;
    if (rgba.byte[3] != 255) {
        u8 *target = geometryBlock->material;
        *(NovaRgba *)&((LineNovaMaterial *)target)->color = rgba.color;
    } else {
        u8 *target;
        rgba.byte[3] = 254;
        target = geometryBlock->material;
        *(NovaRgba *)&((LineNovaMaterial *)target)->color = rgba.color;
        rgba.byte[3] = 255;
    }
    if (((LineNovaMaterial *)geometryBlock->material)->color.c3 == 0) return;

    cameraDimensions = kwlnGetCamera() + 0x68;
    window = (LineNovaCameraWindow *)cameraDimensions;
    farClip = ((RwCamera *)kwlnGetCamera())->nearPlane;
    xScale = *(f32 *)cameraDimensions;
    xExtent = xScale * farClip;
    yScale = window->y.scalar;
    yExtent = yScale * farClip;
    minusX = -xExtent;
    corners[0].lane[0] = minusX;
    minusY = -yExtent;
    corners[0].lane[1] = minusY; corners[0].lane[2] = farClip;
    corners[1].lane[0] = xExtent; corners[1].lane[1] = minusY; corners[1].lane[2] = farClip;
    corners[2].lane[0] = xExtent; corners[2].lane[1] = yExtent; corners[2].lane[2] = farClip;
    corners[3].lane[0] = minusX; corners[3].lane[1] = yExtent; corners[3].lane[2] = farClip;
    center.word[0] = 0; center.word[1] = 0; center.vector.lane[2] = farClip;
    mode = settings->unk7C.byte[0];
    switch (mode) {
    case 0: {
        f32 depth, x, y;
        {
            u8 *view = kwlnGetCamera() + 0x20;
            func_003e42a0((u8 *)&interpolated, instance, view);
        }
        depth = interpolated.lane[2];
        x = *(f32 *)cameraDimensions * depth;
        y = window->y.scalar * depth;
        projected.lane[0] = (2.0f * -x) * (interpolated.lane[0] / depth - 0.5f);
        projected.lane[1] = (2.0f * -y) * (interpolated.lane[1] / depth - 0.5f);
        projected.lane[2] = depth;
    } break;
    case 1: {
        f32 x, y;
        f32 half, two;
        farClip = operandOrderMultiply(300.0f, farClip);
        xScale = xScale * farClip;
        yScale = yScale * farClip;
        half = 0.5f;
        two = 2.0f;
        x = (f32)settings->unk7C.signedHalf[1];
        x = (x / 640.0f) - half;
        projected.lane[0] = operandOrderMultiply(two * -xScale, x);
        y = (f32)settings->unk80.signedHalf[0];
        y = (y / 448.0f) - half;
        projected.lane[1] = operandOrderMultiply(two * -yScale, y);
        projected.lane[2] = farClip;
    } break;
    }
    particle = *(u8 **)state;
    count = settings->particleCount.unsignedValue;
    RpGeometryLock(((RpAtomic *)geometryBlock->atomic)->geometry, 2);
    vertices = ((RpAtomic *)geometryBlock->atomic)->geometry->morphTarget->vertices;
    {
        f32 opacity = (f32)(u32)particle[2] / 255.0f;
        width = settings->width * opacity;
        spread = settings->spread * opacity;
    }
    index = 0;
    divisor = (f32)65535;
    for (; index < count; index++, particle += 8, vertices += 18) {
        LineNovaParticle *entry = (LineNovaParticle *)particle;
        f32 length, factor;
        effectVuLoad10(&corners[index & 3]);
        effectVuLoad11(&corners[(index + 1) & 3]);
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        __asm__ volatile(
            "vmul.xyz $vf2, $vf10, $vf10\n"
            "vaddy.x $vf2, $vf2, $vf2y\n"
            "vaddz.x $vf2, $vf2, $vf2z\n"
            ".word 0x4a0203bd\n"
            "vwaitq\n"
            "cfc2.ni $2, $vi22\n"
            "mtc1 $2, %0\n"
            : "=f"(length) : : "$2", "$vf2", "Q");
        factor = length * ((f32)(u32)*(u16 *)particle / divisor);
__asm__ volatile(
    "vmul.xyz $vf2, $vf10, $vf10\n"
    "vmulax.w $ACC, $vf0, $vf2x\n"
    "vmadday.w $ACC, $vf0, $vf2y\n"
    "vmaddz.w $vf2, $vf0, $vf2z\n"
    "vrsqrt $Q, $vf0w, $vf2w\n"
    "vwaitq\n"
    "vmulq.xyz $vf10, $vf10, $Q\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuScale10(factor);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11\n"
    "vmove.xyzw $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuLoad11(&projected);
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        {
            __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf10, $vf10, $vf2x\n"
                : : "r"(entry->scale.bits) : "$vf2", "$vf10");
        }
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuStore10(&interpolated);
__asm__ volatile(
    "vmove.xyzw $vf10, $vf12\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuLoad11(&center.vector);
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11\n"
    "vmul.xyz $vf2, $vf10, $vf10\n"
    "vmulax.w $ACC, $vf0, $vf2x\n"
    "vmadday.w $ACC, $vf0, $vf2y\n"
    "vmaddz.w $vf2, $vf0, $vf2z\n"
    "vrsqrt $Q, $vf0w, $vf2w\n"
    "vwaitq\n"
    "vmulq.xyz $vf10, $vf10, $Q\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuLoad11((EffectVuVector *)D_00713CF0);
__asm__ volatile(
    "vopmula.xyz $ACC, $vf10, $vf11\n"
    "vopmsub.xyz $vf10, $vf11, $vf10\n"
    "vmove.xyzw $vf11, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        effectVuScale10(spread);
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[12] = *(f32 *)D_00713D10;
vertices[13] = *(f32 *)D_00713D14;
vertices[14] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vadd.xyzw $vf12, $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[9] = *(f32 *)D_00713D10;
vertices[10] = *(f32 *)D_00713D14;
vertices[11] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vsub.xyzw $vf12, $vf12, $vf10\n"
    "vsub.xyzw $vf12, $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[15] = *(f32 *)D_00713D10;
vertices[16] = *(f32 *)D_00713D14;
vertices[17] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vmove.xyzw $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        __asm__ volatile("lqc2 $vf12, 0(%0)" : : "r"(&interpolated), "m"(interpolated) : "$vf12");
        effectVuScale10(width);
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[3] = *(f32 *)D_00713D10;
vertices[4] = *(f32 *)D_00713D14;
vertices[5] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vadd.xyzw $vf12, $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[0] = *(f32 *)D_00713D10;
vertices[1] = *(f32 *)D_00713D14;
vertices[2] = *(f32 *)D_00713D18;
__asm__ volatile(
    "vsub.xyzw $vf12, $vf12, $vf10\n"
    "vsub.xyzw $vf12, $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[6] = *(f32 *)D_00713D10;
vertices[7] = *(f32 *)D_00713D14;
vertices[8] = *(f32 *)D_00713D18;

    }

    {
        u8 *geometry = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry;
        func_003c22f0(geometry);
        if (*(u16 *)owner & 4) ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
    }

    {
        u8 *matrix = func_003e9700((u8 *)((RwCamera *)kwlnGetCamera())->object.object.parent);
        func_003e9cb0(geometryBlock->frame, matrix, 0);
    }
}
#pragma pop


// Binds the line-nova resource for the kind: looks up the kind's resource handle and stores it in the entry.
// FUN_004B3D90
void LineNovaBindResource(u8 *effect) {
    u8 *config;
    u8 *geometryBlock;
    u32 duration;
    void *resourceList;

    config = ((LineNovaEffect *)effect)->configuration.bytes;
    geometryBlock = ((LineNovaState *)((LineNovaEffect *)effect)->state.bytes)->geometry.bytes;
    duration = ((LineNovaConfiguration *)config)->duration.unsignedValue;
    if (duration >= ((LineNovaEffect *)effect)->elapsed.unsignedValue || duration == 0) {
        switch (((LineNovaConfiguration *)config)->resourceKind) {
        case 0:
            resourceList = TnGetIndexedWord(((LineNovaConfiguration *)config)->resourceId);
            ((LineNovaGeometry *)geometryBlock)->nodeNext = 0;
            ((LineNovaGeometry *)geometryBlock)->nodePrevious = 0;
            PrimAppendNode(resourceList, geometryBlock + 0x18);
            break;
        default:
            resourceList = TnGetOffset1C(((LineNovaConfiguration *)config)->resourceId);
            ((LineNovaGeometry *)geometryBlock)->nodeNext = 0;
            ((LineNovaGeometry *)geometryBlock)->nodePrevious = 0;
            PrimAppendNode(resourceList, geometryBlock + 0x18);
            break;
        }
    }
}


// Writes the line colour into the row and selects the six-byte vertex update as the entry's callback.
// FUN_004B3E40
void LineNovaUseVertexUpdate(u8 *effect) {
    u8 *geometryBlock;
    u8 *material;

    geometryBlock = ((LineNovaState *)((LineNovaEffect *)effect)->state.bytes)->geometry.bytes;
    if (iGpffffbb64.c3 != 0xFF) {
        material = ((LineNovaGeometry *)geometryBlock)->material;
        ((LineNovaMaterial *)material)->color = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        material = ((LineNovaGeometry *)geometryBlock)->material;
        ((LineNovaMaterial *)material)->color = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
    ((LineNovaGeometry *)geometryBlock)->update = (s32)LineNovaUpdateVertices;
    ((LineNovaGeometry *)geometryBlock)->owner = (s32)effect;
}


// Creates a line-nova instance whose colour alpha comes from the source's alpha byte, then fills one colour row per entry.
// FUN_004B3ED0
u8 *LineNovaCreateAlpha(u8 *config)
{
    /* Access-site typing differed by 474 normalized bytes; separate typed locals preserve the original cursor lifetimes. */
    f32 firstScaledAlpha;
    f32 secondScaledAlpha;
    f32 alphaScale;
    f32 firstAlphaFloat;
    f32 secondAlphaFloat;
    f32 sourceAlphaFloat;
    s32 firstFadedColor;
    s32 secondFadedColor;
    s32 firstAlpha;
    s32 secondAlpha;
    u16 *geometryBlock;
    u32 particleCount;
    u32 cnt;
    u32 firstSourceAlpha;
    u32 secondSourceAlpha;
    u32 firstColor;
    u32 secondColor;
    u32 particleIndex;
    u8 sourceAlpha;
    u8 *state;
    u8 *colors;

    LineNovaConfiguration *settings = (LineNovaConfiguration *)config;
    LineNovaState *workState;
    LineNovaColors *colorRow;

    particleCount = settings->particleCount.unsignedValue;
    chkmemAllocSiteTag(D_00714628, 0x16D);
    state = (u8 *)(*jtbl_008873E8)(particleCount * 6 + 0x10, 0x40000);
    workState = (LineNovaState *)state;
    if (state == NULL) {
        kAssertFail(D_00714628, 0x16E);
    }
    workState->particles.bytes = state + 0x10;
    workState->allocation.bytes = state;
    geometryBlock = (u16 *)GeometryCreateTableGrid(particleCount & 0xFFFF, 4, 6, D_00713310, 0x48);
    workState->geometry.u16Pointer = geometryBlock;
    *geometryBlock &= 0xFFFE;
    cnt = settings->particleCount.unsignedValue;
    colors = (u8 *)((RpAtomic *)((LineNovaGeometry *)workState->geometry.bytes)->atomic)->geometry->colors;
    sourceAlpha = settings->unk90.byte[2];
    sourceAlphaFloat = (f32)(u32)sourceAlpha;
    alphaScale = sourceAlphaFloat / 255.0f;
    firstColor = settings->firstColor;
    firstSourceAlpha = firstColor >> 0x18;
    firstAlphaFloat = (f32)(u32)firstSourceAlpha;
    firstScaledAlpha = firstAlphaFloat * alphaScale;
    firstAlpha = (u32)firstScaledAlpha;
    firstFadedColor = (firstColor & 0xFFFFFF) | (firstAlpha << 24);
    secondColor = settings->secondColor;
    secondSourceAlpha = secondColor >> 0x18;
    secondAlphaFloat = (f32)(u32)secondSourceAlpha;
    secondScaledAlpha = secondAlphaFloat * alphaScale;
    secondAlpha = (u32)secondScaledAlpha;
    secondFadedColor = (secondColor & 0xFFFFFF) | (secondAlpha << 24);
    particleIndex = 0;
    while (particleIndex < cnt) {
        colorRow = (LineNovaColors *)colors;
        colorRow->unk00.signedValue = secondFadedColor;
        colorRow->unk04.signedValue = firstFadedColor;
        colorRow->unk08.signedValue = secondFadedColor;
        colorRow->unk0C = settings->secondColor;
        colorRow->unk10 = settings->firstColor;
        colorRow->unk14 = settings->secondColor;
        particleIndex++;
        colors += 0x18;
    }
    return state;
}

// Frees a line-nova instance: same body as LineNovaDestroy.
// FUN_004B4170
void LineNovaDestroyAlt(u8 *state) {
    GeometryBlockDestroy(((LineNovaState *)state)->geometry.pointer);
    (*jtbl_008873EC)(((LineNovaState *)state)->allocation.pointer);
}


// Reseeds the six-byte vertex records: three random 16-bit components, then resets the delay from the emitter.
// FUN_004B41C0
void LineNovaReseedVertices(u8 *effect) {
    /* Access-site typing differed by 51 normalized bytes; separate typed locals preserve the original cursor lifetimes. */
    u8 *state;
    u8 *config;
    u32 count;
    s32 progress;
    s32 delay;
    u16 *particle;
    u32 particleIndex;
    f32 alphaVariation;
    f32 positionVariation;
    f32 minimumAlpha;
    f32 minimumPosition;
    f32 randomValue;

    LineNovaEffect *node = (LineNovaEffect *)effect;
    LineNovaConfiguration *settings;
    LineNovaVertexParticle *entry;

    state = node->state.bytes;
    config = node->configuration.bytes;
    settings = (LineNovaConfiguration *)config;
    count = settings->particleCount.unsignedValue;
    progress = settings->duration.signedValue;
    if (progress >= node->elapsed.signedValue || progress == 0) {
        delay = node->delay - 1;
        node->delay = delay;
        if (delay <= 0) {
            alphaVariation = settings->alphaVariation;
            positionVariation = settings->unk94;
            particle = *(u16 **)state;
            particleIndex = 0;
            minimumAlpha = 1.0f - alphaVariation;
            minimumPosition = 1.0f - positionVariation;
            while (particleIndex < count) {
                entry = (LineNovaVertexParticle *)particle;
                randomValue = 65535.0f * (minimumAlpha + alphaVariation * effMiscRandFloat(0));
                *(u16 *)particle = (u16)randomValue;
                randomValue = 65535.0f * effMiscRandFloat(0);
                entry->verticalPosition = (u16)randomValue;
                randomValue = 65535.0f * (minimumPosition + positionVariation * effMiscRandFloat(0));
                entry->horizontalPosition = (u16)randomValue;
                particleIndex++;
                particle = (u16 *)((u8 *)particle + 6);
            }
            delay = settings->delay;
            switch (delay) {
            case 0:
                delay = 0x7FFFFFFF;
                break;
            default:
                break;
            }
            node->delay = delay;
        }
    }
}

/* Six-byte particles place six XYZ vertices between the projected endpoints.
 * The rotation axis is twelve bytes, with both source parts loaded first.
 * As in LineNovaUpdateCameraQuads: (s32) conversions on the last two sampler arguments,
 * effectVuUnpackColor10V0 for the $v0 colour transfers, and the vertex pointer
 * declared after the loop counter. The Y camera offset forms its depth factor
 * before the 224 difference, unlike the X call through novaCameraOffset. */
#pragma push
/* measured: baseline C nd 722B; adjacent-local declaration probe nd 722B; retain settings for owner MATCH. */
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
// Places six XYZ vertices per particle between the projected endpoints (the six-byte particle update).
// FUN_004B4430
void LineNovaUpdateVertices(u8 *unused, u8 *effect)
{
    /* Access-site typing differed by 1470 normalized bytes; separate typed locals preserve the original cursor lifetimes. */

    extern s32 mdlEffectSamplePackedColor(u8 *, u8 *, s32, s32);
    extern u8 *kwlnGetCamera(void);
    extern u8 *func_003c22f0(u8 *);
    extern u8 *func_003e9700(u8 *);
    extern u8 *func_003e9cb0(u8 *, u8 *, s32);
    extern f32 fGpffff8044;
    extern u8 D_00713CF0[], D_00713D10[], D_00713D14[], D_00713D18[];
    typedef struct { u8 r, g, b, a; } NovaRgba;
    union { u32 word; u8 byte[4]; NovaRgba color; } rgba;
    u32 effectColor, sampled, packed;
    u32 sampleResult;
    const u32 *colorInput;
    u8 *instance, *state, *config, *owner;
    u8 *cameraDimensions;
    u8 *particle;
    f32 normalization;
    u32 count, index;
    f32 *vertices;

    extern u8 *RwMatrixMultiply(u8 *, u8 *, u8 *);
    extern u8 *RwMatrixRotate(u8 *, const u8 *, f32, s32);
    extern u8 D_00714638[], D_00714640[];
    #pragma push
    #pragma pack(4)
    typedef struct { s64 xy; f32 z; } NovaAxis;
    #pragma pop
    NovaAxis axis;
    s64 axisXY;
    f32 axisZ;
    EffectVuVector top, bottom;
    u8 rotation[64] __attribute__((aligned(16)));
    u8 transform[64] __attribute__((aligned(16)));
    f32 centerX, centerY, depth, extentX, extentY;
    f32 width, spread, screenX, screenY;
    u32 progress, duration;
    u8 *matrix;
    LineNovaEffect *node;
    LineNovaConfiguration *settings;
    LineNovaState *workState;
    LineNovaGeometry *geometryBlock;
    LineNovaCameraWindow *window;

    axisXY = *(s64 *)D_00714638;
    axisZ = *(f32 *)D_00714640;
    axis.xy = axisXY;
    axis.z = axisZ;

    instance = effect;
    node = (LineNovaEffect *)instance;
    state = node->state.bytes;
    workState = (LineNovaState *)state;
    config = node->configuration.bytes;
    settings = (LineNovaConfiguration *)config;
    owner = workState->geometry.bytes;
    geometryBlock = (LineNovaGeometry *)owner;

    progress = node->elapsed.unsignedValue;

    sampleResult = (u32)mdlEffectSamplePackedColor(config, config + 0x24, (s32)node->elapsed.unsignedValue, (s32)settings->duration.unsignedValue);
    effectColor = node->color.unsignedValue;
    colorInput = &effectColor;
    normalization = fGpffff8044;
    effectVuUnpackColor10V0(colorInput, normalization);
    __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
    sampled = sampleResult;
    effectVuUnpackColor10V0(&sampled, normalization);
    __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
    {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "vftoi0.xyzw $vf10, $vf10\n"
            "qmfc2.ni %0, $vf10\n"
            "ppach %0, $zero, %0\n"
            "ppacb %0, $zero, %0\n"
            "sw %0, packed\n"
            : "=&r"(transfer), "=m"(packed) : "r"(255.0f) : "$vf2", "$vf10", "memory");
    }
    rgba.word = packed;
    if (rgba.byte[3] != 255) {
        u8 *target = geometryBlock->material;
        *(NovaRgba *)&((LineNovaMaterial *)target)->color = rgba.color;
    } else {
        u8 *target;
        rgba.byte[3] = 254;
        target = geometryBlock->material;
        *(NovaRgba *)&((LineNovaMaterial *)target)->color = rgba.color;
        rgba.byte[3] = 255;
    }
    if (((LineNovaMaterial *)geometryBlock->material)->color.c3 == 0) return;

    duration = settings->unk7C.unsignedValue;
    if (duration != 0) {
        if (progress < duration) {
            f32 time = (f32)progress / (f32)duration;
            centerX = 0.0f + (f32)settings->unk80.signedHalf[0] + time * (f32)(settings->unk88.signedHalf[0] - settings->unk80.signedHalf[0]);
            centerY = 0.0f + (f32)settings->unk80.signedHalf[1] + time * (f32)(settings->unk88.signedHalf[1] - settings->unk80.signedHalf[1]);
            extentX = 0.0f + (f32)settings->unk84.signedHalf[0] + time * (f32)(settings->unk8C.signedHalf[0] - settings->unk84.signedHalf[0]);
            extentY = 0.0f + (f32)settings->unk84.signedHalf[1] + time * (f32)(settings->unk8C.signedHalf[1] - settings->unk84.signedHalf[1]);
        } else {
            centerX = (f32)settings->unk88.signedHalf[0];
            centerY = (f32)settings->unk88.signedHalf[1];
            extentX = (f32)settings->unk8C.signedHalf[0];
            extentY = (f32)settings->unk8C.signedHalf[1];
        }
    } else {
        centerX = (f32)settings->unk80.signedHalf[0];
        centerY = (f32)settings->unk80.signedHalf[1];
        extentX = (f32)settings->unk84.signedHalf[0];
        extentY = (f32)settings->unk84.signedHalf[1];
    }
    cameraDimensions = kwlnGetCamera() + 0x68;
    window = (LineNovaCameraWindow *)cameraDimensions;
    depth = operandOrderAddFloat(((RwCamera *)kwlnGetCamera())->nearPlane, 1.0f);
    screenX = 640.0f;
    {
        f32 x = extentX * (*(f32 *)cameraDimensions * depth) / screenX;
        f32 y;
        screenY = 448.0f;
        y = extentY * (window->y.scalar * depth) / screenY;
        bottom.lane[0] = -x; bottom.lane[1] = -y; bottom.lane[2] = depth;
        top.lane[0] = -x; top.lane[1] = y; top.lane[2] = depth;
        extentX = operandOrderMultiply(y, 2.0f);
        extentY = operandOrderMultiply(x, 2.0f);
    }
    particle = *(u8 **)state;
    count = settings->particleCount.unsignedValue;
    RpGeometryLock(((RpAtomic *)geometryBlock->atomic)->geometry, 2);
    vertices = ((RpAtomic *)geometryBlock->atomic)->geometry->morphTarget->vertices;
    width = settings->width / 10.0f;
    spread = settings->spread / 10.0f;
    index = 0;
    for (; index < count; index++, particle += 6, vertices += 18) {
        LineNovaVertexParticle *entry = (LineNovaVertexParticle *)particle;
        const f32 divisor = (f32)65535;
        f32 opacity = (f32)(u32)*(u16 *)particle / divisor;
        f32 horizontalWidth = width * opacity;
        f32 verticalWidth = spread * opacity;
        f32 horizontalPosition = extentY * (f32)(u32)entry->horizontalPosition / divisor;
        f32 verticalPosition;
        effectVuLoad10(&bottom);
        effectVuLoad11(&top);
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11\n"
    "vmul.xyz $vf2, $vf10, $vf10\n"
    "vmulax.w $ACC, $vf0, $vf2x\n"
    "vmadday.w $ACC, $vf0, $vf2y\n"
    "vmaddz.w $vf2, $vf0, $vf2z\n"
    "vrsqrt $Q, $vf0w, $vf2w\n"
    "vwaitq\n"
    "vmulq.xyz $vf10, $vf10, $Q\n"
    "vmove.xyzw $vf12, $vf10\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");

        verticalPosition = extentX * (f32)(u32)entry->verticalPosition / divisor;
        effectVuScale10(verticalPosition);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11\n"
    : : : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q");
__asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[12] = *(f32 *)D_00713D10;
vertices[13] = *(f32 *)D_00713D14;
vertices[14] = *(f32 *)D_00713D18;
__asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[9] = *(f32 *)D_00713D10;
vertices[10] = *(f32 *)D_00713D14;
vertices[11] = *(f32 *)D_00713D18;
__asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(*(EffectVuVector *)D_00713D10) : "r"(D_00713D10) : "memory");
vertices[15] = *(f32 *)D_00713D10;
vertices[16] = *(f32 *)D_00713D14;
vertices[17] = *(f32 *)D_00713D18;

        vertices[1] = vertices[10] - verticalWidth;
        vertices[7] = vertices[16] + verticalWidth;
        vertices[10] = vertices[10] - horizontalWidth;
        vertices[16] = vertices[16] + horizontalWidth;
        vertices[0] = vertices[9] + horizontalPosition;
        vertices[2] = vertices[11];
        vertices[3] = vertices[12] + horizontalPosition;
        vertices[4] = vertices[13]; vertices[5] = vertices[14];
        vertices[6] = vertices[15] + horizontalPosition;
        vertices[8] = vertices[17];
    }

    {
        u8 *geometry = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry;
        func_003c22f0(geometry);
        if (*(u16 *)owner & 4) ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
    }

    matrix = func_003e9700((u8 *)((RwCamera *)kwlnGetCamera())->object.object.parent);
    RwMatrixRotate(rotation, (const u8 *)&axis, (f32)settings->unk90.signedHalf[0], 0);
    ((LineNovaMatrix *)rotation)->xTranslation += novaCameraOffset(centerX, (const f32 *)cameraDimensions, depth, screenX, 320.0f);
    {
        f32 factor = 2.0f * window->y.constf32;
        factor = factor * depth;
        ((LineNovaMatrix *)rotation)->yTranslation += (224.0f - centerY) * factor / screenY;
    }
    RwMatrixMultiply(transform, rotation, matrix);
    func_003e9cb0(geometryBlock->frame, transform, 0);
}
#pragma pop




// Binds the line-nova resource for its kind; same body as LineNovaBindResource.
// FUN_004B4C00
void LineNovaBindResourceAlt(u8 *effect) {
    u8 *config;
    u8 *geometryBlock;
    u32 duration;
    void *resourceList;

    config = ((LineNovaEffect *)effect)->configuration.bytes;
    geometryBlock = ((LineNovaState *)((LineNovaEffect *)effect)->state.bytes)->geometry.bytes;
    duration = ((LineNovaConfiguration *)config)->duration.unsignedValue;
    if (duration >= ((LineNovaEffect *)effect)->elapsed.unsignedValue || duration == 0) {
        switch (((LineNovaConfiguration *)config)->resourceKind) {
        case 0:
            resourceList = TnGetIndexedWord(((LineNovaConfiguration *)config)->resourceId);
            ((LineNovaGeometry *)geometryBlock)->nodeNext = 0;
            ((LineNovaGeometry *)geometryBlock)->nodePrevious = 0;
            PrimAppendNode(resourceList, geometryBlock + 0x18);
            break;
        default:
            resourceList = TnGetOffset1C(((LineNovaConfiguration *)config)->resourceId);
            ((LineNovaGeometry *)geometryBlock)->nodeNext = 0;
            ((LineNovaGeometry *)geometryBlock)->nodePrevious = 0;
            PrimAppendNode(resourceList, geometryBlock + 0x18);
            break;
        }
    }
}


// Creates a line-nova kind instance (kind below three): allocates the instance block, copies the kind's parameters and runs its init callback.
// FUN_004B4CB0
u8 *LineNovaCreateKindInstance(s32 kind, u8 *parameters) {
    u8 *effect;
    s32 size;
    u32 typeIndex;
    u32 tableOffset;

    if ((u16)kind >= 3) {
        kAssertFail(D_00714628, 0x28C);
    }
    typeIndex = (u16)kind;
    size = ((LineNovaTypeSize *)D_00714664)[typeIndex].dataBytes;
    chkmemAllocSiteTag(D_00714628, 0x290);
    effect = (u8 *)(*jtbl_008873E8)(size + 0x30, 0x40000);
    if (effect == NULL) {
        kAssertFail(D_00714628, 0x291);
    }
    ((LineNovaEffect *)effect)->configuration.bytes = effect + 0x30;
    ((LineNovaEffect *)effect)->elapsed.signedValue = 0;
    ((LineNovaEffect *)effect)->kind = typeIndex;
    ((LineNovaEffect *)effect)->color.signedValue = -1;
    ((LineNovaEffect *)effect)->delay = 0;
    __asm__ volatile ("sqc2 vf0, 0(%0)" : : "r"(effect) : "memory");
    memcpy(((LineNovaEffect *)effect)->configuration.pointer, parameters, size);
    tableOffset = (u16)kind * 0x18;
    ((LineNovaEffect *)effect)->state.signedValue = ((LineNovaTypeInitializer *)(D_00714654 + tableOffset))->initialize(parameters);
    ((LineNovaTypeSetup *)(D_00714650 + tableOffset))->setup(effect);
    return effect;
}
// Creates a line-nova kind instance for an object: resolves the object's record (asserts on a missing record), then builds the kind instance.
// FUN_004B4E10
void *LineNovaCreateKindInstanceFromObject(void *source) {
    u8 *effect;

    effect = mdlEffectResolveRelPtrA(source);
    if (effect == NULL) {
        kAssertFail(D_00714628, 0x2B3);
    }
    effect = LineNovaCreateKindInstance(((EffSourceDescriptor *)source)->id, effect);
    if (effect == NULL) {
        kAssertFail(D_00714628, 0x2B5);
    }
    return effect;
}
