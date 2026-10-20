#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
/* Original translation unit effPolygonFlash.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "effect_vu0_internal.h"
#include "effect_instance_internal.h"
#include "effect_mesh_internal.h"

/* Same spelling as mdlEffect.c: a 128-bit type makes mwcc emit the lq/sq
   quadword copy retail uses, with no inline asm. */
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef signed __int128 s128;

extern f32 cosf(f32);
extern f32 sinf(f32);
/* Anonymous gp-relative float slots (-0x7FBC / -0x7F30 of $28), same
   convention as effPolygonThunder.c's iGpffff8044. */
extern f32 fGpffff8044;
extern f32 fGpffff80d0;
/* Scratch color quads, addressed absolutely by retail (lui/addiu). */
extern f32 D_00713D10[4];
extern f32 D_00713D14[4];
extern f32 D_00713D18[4];
extern u32 D_00713F70[];
extern u32 D_00713FB0[];

extern void GeometryBlockDestroy();
extern void (*jtbl_008873EC[])(void *);
extern void (*D_008873ec[])(void *);
extern void func_003c22f0(void *);
extern s32 TnSlotObject(s32);
extern void func_003c42b0(void *, void *);
extern void GeometryBlockSetTextureFromHandle(void *, void *);
extern char D_00713408[];
extern char D_00714028[];
extern char D_00713CE0[];
extern void memcpy(void *, void *, void *);
extern char D_00714014[];
extern char D_00714010[];
extern void *FlashQuadCopyAlloc(s32, void *);

extern u8 *(*jtbl_008873E8[])(s32, s32);
extern void chkmemAllocSiteTag(char *, s32);
extern void kAssertFail(char *, s32);
extern s32 mdlEffectSamplePackedColor(u8 *, u8 *, s32, s32);
extern void GeometryBlockSetFrameMatrixCombined(void *, void *, void *, void *);
extern void GeometryBlockBindResource(void *, u16);

/* 4-byte color, copied field-by-field by retail. */
typedef EffMeshColor Color4;
extern char D_00713FF0[];
extern char D_007133A0[];
extern char D_007133C0[];
extern u8 *GeometryCloneBlock(void *);
extern void FlashEvolvingRadialInitEntries(u8 *, u8 *);
extern void FlashTexturedInitEntries(u8 *, u8 *);
extern void FlashCenteredStripInitEntries(u8 *, u8 *);
extern void FlashAgedBoxInitEntries(u8 *, u8 *);

/* Common flash instance header: the quad-copy allocator reserves 0x50 bytes
 * before its variable parameter payload; all emitters read these same slots. */
typedef struct FlashEffect {
    f32 position[4], rotation[4];
    union { f32 lanes[4]; u_long128 quad; } scale;
    s32 color;
    u32 frame;
    u32 kind;
    u8 *state;
    u8 *parameters;
    u8 pad44[0xC];
} FlashEffect;

/* The allocation header precedes the variant-sized particle array at +0x10. */
typedef struct FlashBlock {
    union { u8 *bytes; u32 word; } particles;
    union { u8 *bytes; u32 word; void *pointer; } geometry;
    union { void *pointer; u32 word; } allocation;
    u8 padC[4];
} FlashBlock;

/* Shared parameter prefix. Variant motion fields follow the two colors. */
typedef struct FlashParameters {
    u8 pad0[0x28];
    u16 resourceId;
    u8 pad2A[0xA];
    u32 lastFrame;
    union { s32 signedCount; u16 low; u32 count; } vertexCount;
    u8 pad3C[8];
    f32 fadeIn, fadeOut;
    s32 life, births;
    u8 recycle, burst, geometryFlag;
    u8 pad57;
    u32 innerColor, outerColor;
    /* Motion payloads vary by flash kind. Preserve the observed scalar types;
     * the period/reverse alternatives occupy the same slots in other kinds. */
    f32 unk60, unk64, unk68, unk6C;
    union { f32 scalar; s32 period; u32 bits; } unk70;
    f32 unk74, unk78, unk7C, unk80;
    union { f32 scalar; u8 reverse; } unk84;
    f32 unk88, unk8C, unk90;
    union { f32 scalar; u8 reverse; } unk94;
    f32 unk98, unk9C, unkA0, unkA4;
} FlashParameters;

/* Four texture-coordinate pairs are filled per 0x20-byte quad. */
typedef struct FlashUvQuad {
    f32 coordinates[8];
} FlashUvQuad;

/* Particle ages -1/-2 mean awaiting birth/disabled; nonnegative ages are live.
 * Access-site trials recovered the native mesh chain without retyping byte cursors.
 * Only the individually measured raw loads/stores below still differ when typed. */
// Allocates a rotating-flash block: count * 24 particle bytes, a geometry handle, and an owner link.
// FUN_0049A900
void *FlashRotatingAllocBlock(u8 *input, s32 resource)
{
    u32 id;
    u8 *mem;

    if (resource) {
        kAssertFail(D_00713FF0, 0x89);
    }
    id = (u32)((FlashParameters *)input)->vertexCount.signedCount;
    chkmemAllocSiteTag(D_00713FF0, 0x90);
    mem = jtbl_008873E8[0](id * 24 + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x91);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.pointer = (void *)mem;
    ((FlashBlock *)mem)->geometry.bytes = (u8 *)GeometryCreateTableGrid(id & 0xFFFF, 3, 5, D_007133A0, 0x48);
    return mem;
}




// Frees a rotating-flash block: its geometry handle, then the block itself.
// FUN_0049A9E0
void FlashRotatingFreeBlock(u8 *input)
{
    GeometryBlockDestroy(((FlashBlock *)input)->geometry.bytes);
    jtbl_008873EC[0](((FlashBlock *)input)->allocation.pointer);
}

typedef struct FlashRotatingParticle {
    s32 age;
    f32 angularVelocity;
    f32 angle;
    f32 radius;
    f32 width;
    f32 length;
} FlashRotatingParticle;

typedef struct FlashRotatingState {
    FlashRotatingParticle *particles;
    u8 *geometryOwner;
    u8 reserved[8];
} FlashRotatingState;

typedef struct FlashRotatingConfig {
    u8 prefix[0x34];
    u32 lastFrame;
    s32 count;
    u8 reserved3c[8];
    f32 fadeIn;
    f32 fadeOut;
    s32 life;
    s32 births;
    u8 recycle;
    u8 burst;
    u8 reserved56[2];
    u32 innerColor;
    u32 outerColor;
    f32 width;
    f32 length;
    f32 sizeRandomness;
    f32 radius;
    f32 radiusRandomness;
    f32 angularVelocity;
    f32 angularRandomness;
    f32 angularAcceleration;
} FlashRotatingConfig;

typedef struct FlashVertex {
    f32 x, y, z;
} FlashVertex;

typedef char FlashRotatingParticleSize[(sizeof(FlashRotatingParticle) == 0x18) ? 1 : -1];
typedef char FlashRotatingStateSize[(sizeof(FlashRotatingState) == 0x10) ? 1 : -1];
typedef char FlashRotatingConfigSize[(sizeof(FlashRotatingConfig) == 0x80) ? 1 : -1];
typedef char FlashVertexSize[(sizeof(FlashVertex) == 0x0c) ? 1 : -1];

/* Particle age is scalar state. Its wide spill slots are generated by MWCC;
 * the vector/color transfers use the Effect VU0 object boundaries.
 */
// Emits the rotating flash quads for one effect, using the particle angle, radius and width.
// FUN_0049AA30
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void FlashRotatingEmitQuads(u8 *effect)
{
    u32 innerWord;
    u32 outerWord;
    u32 innerPacked;
    u32 outerPacked;
    EffectVuVector innerColor;
    EffectVuVector outerColor;
    EffectVuVector direction;
    EffectVuVector radial;
    EffectVuVector side;
    EffectVuVector end;
    s32 firstFrame;
    s32 count;
    s32 fadeIn;
    s32 fadeOut;
    s32 recycle;
    FlashRotatingState *state;
    FlashRotatingParticle *particle;
    FlashRotatingConfig *config;
    u8 *owner;
    s32 life;
    FlashVertex *vertices;
    u32 *colors;
    f32 randomness;
    f32 angle;
    f32 acceleration;
    f32 fullTurn;
    f32 normalization;
    const u32 *colorInput;
    u32 frame;
    u32 lastFrame;
    s32 index;
    s32 births;

    config = (FlashRotatingConfig *)((FlashEffect *)effect)->parameters;
    lastFrame = config->lastFrame;
    frame = ((FlashEffect *)effect)->frame;
    if (lastFrame < frame && lastFrame != 0) {
        return;
    }
    state = (FlashRotatingState *)((FlashEffect *)effect)->state;
    particle = state->particles;
    owner = state->geometryOwner;
    count = config->count;
    life = config->life;
    if (life == 0) {
        return;
    }
    if (config->burst != 0 && frame == 0) {
        firstFrame = 1;
        births = count;
    } else {
        firstFrame = 0;
        births = config->births;
    }
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry, 0xa);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    vertices = (FlashVertex*)((RpMorphTarget *)(u8*)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->morphTarget)->vertices;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    colors = ((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->colors;
    direction.lane[1] = 0.0f;
    direction.lane[3] = 0.0f;
    innerWord = config->innerColor & 0x00ffffff;
    colorInput = &innerWord;
    normalization = fGpffff8044;
    effectVuUnpackColor10(colorInput, normalization);
    effectVuStore10(&innerColor);
    outerWord = config->outerColor & 0x00ffffff;
    effectVuUnpackColor10(&outerWord, normalization);
    effectVuStore10(&outerColor);
    fadeIn = (s32)(config->fadeIn * (f32)life);
    fadeOut = (s32)(config->fadeOut * (f32)life);
    acceleration = config->angularAcceleration;
    recycle = config->recycle;
    for (index = 0, fullTurn = fGpffff80d0; index < count; index++, particle++, vertices += 5, colors += 5) {
        s32 age = particle->age;
        if (age == -2) {
            continue;
        }
        if (age == -1) {
            if (births != 0) {
                f32 factor;
                particle->angle = fullTurn * effMiscRandFloat(0);
                randomness = config->angularRandomness;
                factor = 0.0f + (1.0f - randomness) + randomness * effMiscRandFloat(0);
                particle->angularVelocity = config->angularVelocity * factor;
                if (effMiscRand(0) & 1) {
                    particle->angularVelocity *= -1.0f;
                }
                randomness = config->radiusRandomness;
                factor = 0.0f + (1.0f - randomness) + randomness * effMiscRandFloat(0);
                particle->radius = config->radius * factor;
                randomness = config->sizeRandomness;
                factor = 0.0f + (1.0f - randomness) + randomness * effMiscRandFloat(0);
                particle->width = config->width * factor;
                particle->length = config->length * factor;
                if (firstFrame) {
                    particle->age = effMiscRand(0) % (u32)life;
                } else {
                    particle->age = 0;
                }
                births--;
            }
            continue;
        }
        if (age >= life) {
            s32 vertex;
            for (vertex = 0; vertex < 5; vertex++) {
                vertices[vertex].x = 0.0f;
                vertices[vertex].y = 0.0f;
                vertices[vertex].z = 0.0f;
                colors[vertex] = 0;
            }
            particle->age = recycle ? -1 : -2;
        } else {
            f32 time = (f32)age;
            f32 x;
            f32 z;
            f32 fade;
            u32 innerValue;
            EffectVuVector *sidePointer;
            EffectVuVector *endPointer;
            EffectVuVector *scratch;
            if (particle->angularVelocity > 0.0f) {
                angle = time * (0.0f + particle->angularVelocity + 0.5f * (acceleration * time));
            } else {
                angle = time * (0.0f + particle->angularVelocity - 0.5f * (acceleration * time));
            }
            angle += particle->angle;
            effectVuLoad10((EffectVuVector *)D_00713CE0);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            effectVuScale10(particle->radius);
            effectVuStore10(&radial);
            __asm__ volatile("vmove.xyzw $vf10, $vf11" : : : "$vf10");
            effectVuScale10(particle->width);
            effectVuScale11(particle->length);
            effectVuStore10(&side);
            effectVuStore11(&end);
            direction.lane[0] = cosf(angle);
            direction.lane[2] = sinf(angle);
            effectVuLoad10(&direction);
            __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
            x = effectVuGetX10();
            z = effectVuGetZ10();
            effectVuSetX10(z);
            effectVuSetZ10(-x);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            sidePointer = &side;
            effectVuLoad10(sidePointer);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            effectVuStore10(sidePointer);
            endPointer = &end;
            effectVuLoad10(endPointer);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            effectVuStore10(endPointer);
            __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10");
            effectVuLoad11(&radial);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11\nvmove.xyzw $vf12, $vf10"
                : : : "$vf10", "$vf12");
            effectVuLoad10(sidePointer);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            scratch = (EffectVuVector *)D_00713D10;
            effectVuStore10(scratch);
            vertices[2].x = D_00713D10[0];
            vertices[2].y = D_00713D14[0];
            vertices[2].z = D_00713D18[0];
            __asm__ volatile("vsub.xyz $vf11, $vf0, $vf11" : : : "$vf11");
            effectVuStore11(scratch);
            vertices[4].x = D_00713D10[0];
            vertices[4].y = D_00713D14[0];
            vertices[4].z = D_00713D18[0];
            effectVuLoad10(endPointer);
            __asm__ volatile("vmove.xyzw $vf11, $vf10\nvadd.xyzw $vf10, $vf10, $vf12\nvsub.xyz $vf11, $vf0, $vf11"
                : : : "$vf10", "$vf11");
            effectVuStore10(scratch);
            vertices[0].x = D_00713D10[0];
            vertices[0].y = D_00713D14[0];
            vertices[0].z = D_00713D18[0];
            __asm__ volatile("vadd.xyzw $vf11, $vf11, $vf12" : : : "$vf11");
            effectVuStore11(scratch);
            vertices[1].x = D_00713D10[0];
            vertices[1].y = D_00713D14[0];
            vertices[1].z = D_00713D18[0];
            if (age < fadeIn) {
                fade = (f32)age / (f32)fadeIn;
            } else if (age > fadeOut) {
                fade = (f32)(life - age) / (f32)(life - fadeOut);
            } else {
                fade = 1.0f;
            }
            effectVuLoad11((EffectVuVector *)D_00713CE0);
            effectVuScale11(fade);
            effectVuLoad10(&outerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 transfer;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni %0, $vf10 \n"
                    "ppach %0, $zero, %0 \n"
                    "ppacb %0, $zero, %0 \n"
                    "sw %0, outerPacked \n"
                    : "=&r"(transfer), "=m"(outerPacked)
                    : "r"(255.0f) : "$vf2", "$vf10");
            }
            colors[0] = outerPacked;
            ((Color4 *)colors)[1] = *(Color4 *)colors;
            effectVuLoad10(&innerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 transfer;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni %0, $vf10 \n"
                    "ppach %0, $zero, %0 \n"
                    "ppacb %0, $zero, %0 \n"
                    "sw %0, innerPacked \n"
                    : "=&r"(transfer), "=m"(innerPacked)
                    : "r"(255.0f) : "$vf2", "$vf10");
            }
            innerValue = innerPacked;
            if (index & 1) {
                u32 alpha;
                colors[3] = innerValue | 0xff000000;
                alpha = (u32)(128.0f * fade) << 24;
                colors[2] = alpha;
                colors[4] = alpha;
            } else {
                u32 alpha;
                colors[3] = innerValue | 0x40000000;
                alpha = (u32)(255.0f * fade) << 24;
                colors[2] = alpha;
                colors[4] = alpha;
            }
            particle->age = age + 1;
        }
    }
    {
        u8 *geometry = (u8*)((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry;
        func_003c22f0(geometry);
        if (((EffGeometryBlock *)owner)->kind & 4) {
            ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
        }
    }
}
#pragma opt_loop_invariants off


#pragma opt_dead_assignments on
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// Packs the rotating flash vertex colours from the inner and outer colour words.
// FUN_0049B2B0
void FlashRotatingPackColors(u8 *input)
{
    union
    {
        s32 w;
        u8 b[4];
    } packedColor;
    s32 parentColor;
    s32 sampleColor;
    s32 combinedColor;
    s32 sampledColor;
    u8 *state;
    u8 *config;
    u8 *geometryOwner;
    u32 frame;
    u32 lastFrame;
    f32 scale;

    state = ((FlashEffect *)input)->state;
    config = ((FlashEffect *)input)->parameters;
    geometryOwner = ((FlashBlock *)state)->geometry.bytes;
    frame = ((FlashEffect *)input)->frame;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    if ((lastFrame >= frame) || (lastFrame == 0))
    {
        s32 *pt;

        sampledColor = mdlEffectSamplePackedColor(config, config + 0x24, frame, lastFrame);
        parentColor = ((FlashEffect *)input)->color;
        pt = &parentColor;
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
        sampleColor = sampledColor;
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
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sampleColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        packedColor.w = *(s32 *)&combinedColor;
        if (packedColor.b[3] != 0xFF)
        {
            u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
            ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
        }
        else
        {
            packedColor.b[3] = 0xFE;
            {
                u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
                ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
            }
            packedColor.b[3] = 0xFF;
        }
        GeometryBlockSetFrameMatrixCombined(geometryOwner, input, input + 0x10, input + 0x20);
        if (((FlashParameters *)config)->geometryFlag != 0)
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind | 1;
        }
        else
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind & 0xFFFE;
        }
        {
            s32 resourceId = ((FlashParameters *)config)->resourceId;
            GeometryBlockBindResource(geometryOwner, resourceId);
        }
    }
}
/* measured: with #pragma opt_loop_invariants on, the fill loop matches retail
 * exactly (including the preheader -1 hoist and the slt/nop/bnez tail); the
 * residual is 8 words in the func_0043f9c8 argument block: retail completes
 * the four-load chain (resourceData->0x10->0x18->0x5C->0x14) before computing the size
 * operand, mwcc b210 splits the chain around the size computation (chain1-3,
 * size, chain4) regardless of spelling (inline chain, explicit temps, locals,
 * opt_propagation off). Argument-evaluation-order/scheduling floor.
 * measured: #pragma schedule was probed and does NOT move the residual (best
 * stays 8 differing words): schedule off at function scope = 8 (no-op, it is
 * the default), schedule on at function scope = 49, schedule off scoped around
 * the memset call = 49, schedule on scoped around the call = 8 (no-op).
 * optimization_level 3 = 49, optimization_level 1 = 46, opt_lifetimes on/off =
 * 8 (no-op). The chain split is a register-allocation artifact (retail loads
 * chain3 into $v0 and chain4 into $a0; mwcc reuses $a0 for both, forcing the
 * chain4 load after the size arithmetic), not a scheduling toggle. */
/* measured: three separate defects, each worth a note.  m2c wrote the entry
   pointer as `s32 *` advancing by 0x1C, which walks 112 bytes where retail
   walks 28 - the loop still compiled and still looked right.  The -1 stored in
   the loop is loop-invariant and retail hoists it; b210 at -O2 rematerialises
   it inside instead, so opt_loop_invariants is what retail was built with here
   (nd 60 -> 17, and the hoisted addiu appears in the preheader exactly as
   retail has it).  The last 8 words were argument order: writing the texture
   handle as tex[5] instead of *(s32 *)(tex + 0x14) makes b210 finish the
   pointer chain before evaluating the size argument, which is what retail
   does; the cast-and-offset spelling lets the second load sink below the
   multiply and no declaration order fixes it.
   measured: without opt_loop_invariants the residual is nd 17, not 0. */
// Updates the rotating flash geometry: locks the model geometry and clears its vertex buffer before the rebuild.
// FUN_0049B470
#pragma opt_loop_invariants on
void FlashRotatingUpdateGeometry(u8 *input)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = ((FlashEffect *)input)->state;
    entry = *(s32 **)state;
    work = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)((FlashEffect *)input)->parameters)->vertexCount.signedCount;
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)work)->atomic)->geometry, 2);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    tex = (s32**)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry)->morphTarget;
    memset((s32)tex[5], 0, ((EffGeometryBlock *)work)->vertexCount * 0xC);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    model = (u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry;
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        ((RpGeometry *)model)->lockedSinceLastInst = ((RpGeometry *)model)->lockedSinceLastInst | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 7;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// Allocates a radial-flash block: count * 28 entry bytes, a geometry handle, and an owner link.
// FUN_0049B560
void *FlashRadialAllocBlock(u8 *input, s32 resource)
{
    u32 id;
    u8 *mem;

    if (resource) {
        kAssertFail(D_00713FF0, 0x1DE);
    }
    id = (u32)((FlashParameters *)input)->vertexCount.signedCount;
    chkmemAllocSiteTag(D_00713FF0, 0x1E5);
    mem = jtbl_008873E8[0](id * 28 + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x1E6);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.pointer = (void *)mem;
    ((FlashBlock *)mem)->geometry.bytes = (u8 *)GeometryCreateTableGrid(id & 0xFFFF, 0xC, 0xD, D_007133C0, 0x48);
    return mem;
}




// Frees a radial-flash block: its geometry handle, then the block itself.
// FUN_0049B640
void FlashRadialFreeBlock(u8 *input)
{
    GeometryBlockDestroy(((FlashBlock *)input)->geometry.bytes);
    jtbl_008873EC[0](((FlashBlock *)input)->allocation.pointer);
}

/* The inclusive color-fill bound selects retail's assembler-temp branch.
 * See docs/matching.md, "slt $at vs slt $v0".
 */
typedef struct FlashRadialParticle {
    s32 age;
    f32 velocity;
    f32 angle;
    f32 firstRadius;
    f32 secondRadius;
    f32 baseRadius;
    f32 width;
} FlashRadialParticle;

typedef struct FlashRadialState {
    FlashRadialParticle *particles;
    u8 *geometryOwner;
    u8 reserved[8];
} FlashRadialState;

typedef struct FlashRadialConfig {
    u8 prefix[0x34];
    u32 lastFrame;
    s32 count;
    u8 reserved3c[8];
    f32 fadeIn;
    f32 fadeOut;
    s32 life;
    s32 births;
    u8 recycle;
    u8 burst;
    u8 reserved56[2];
    u32 innerColor;
    u32 outerColor;
    f32 width;
    f32 unused64;
    f32 sizeRandomness;
    f32 radius;
    f32 radiusRandomness;
    f32 baseRadius;
    f32 baseRandomness;
    f32 velocity;
    f32 velocityRandomness;
    f32 acceleration;
    u8 reverse;
    u8 reserved89[3];
} FlashRadialConfig;

typedef char FlashRadialStateSize[(sizeof(FlashRadialState) == 0x10) ? 1 : -1];
typedef char FlashRadialParticleSize[(sizeof(FlashRadialParticle) == 0x1c) ? 1 : -1];
typedef char FlashRadialConfigSize[(sizeof(FlashRadialConfig) == 0x8c) ? 1 : -1];

// Emits the radial flash quads for one effect, from the radial particle state and config.
// FUN_0049B690
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void FlashRadialEmitQuads(u8 *effect)
{
    u32 innerWord;
    u32 outerWord;
    u32 outerPacked;
    u32 innerPacked;
    EffectVuVector innerColor;
    EffectVuVector outerColor;
    EffectVuVector center;
    EffectVuVector direction;
    EffectVuVector width;
    EffectVuVector second;
    EffectVuVector first;
    s32 firstFrame;
    s32 count;
    s32 index;
    s32 fadeIn;
    s32 fadeOut;
    s32 initialAge;
    s32 terminalAge;
    s32 ageStep;
    s32 recycle;
    FlashRadialState *state;
    FlashRadialParticle *particle;
    FlashRadialConfig *config;
    u8 *owner;
    s32 life;
    FlashVertex *vertices;
    u32 *colors;
    f32 acceleration;
    f32 distance;
    f32 radiusRandomness;
    f32 fullTurn;
    f32 unit;
    f32 zero;
    f32 half;
    f32 byteScale;
    f32 phase;
    f32 normalization;
    const u32 *colorInput;
    u32 frame;
    u32 lastFrame;
    s32 births;

    config = (FlashRadialConfig *)((FlashEffect *)effect)->parameters;
    lastFrame = config->lastFrame;
    frame = ((FlashEffect *)effect)->frame;
    if (lastFrame < frame && lastFrame != 0) {
        return;
    }
    state = (FlashRadialState *)((FlashEffect *)effect)->state;
    particle = state->particles;
    owner = state->geometryOwner;
    count = config->count;
    life = config->life;
    if (life == 0) {
        return;
    }
    if (config->reverse) {
        initialAge = life;
        terminalAge = 0;
        ageStep = -1;
        fadeIn = (s32)((1.0f - config->fadeOut) * (f32)life);
        fadeOut = (s32)((1.0f - config->fadeIn) * (f32)life);
    } else {
        initialAge = 0;
        terminalAge = life;
        ageStep = 1;
        fadeIn = (s32)(config->fadeIn * (f32)life);
        fadeOut = (s32)(config->fadeOut * (f32)life);
    }
    if (config->burst != 0 && frame == 0) {
        firstFrame = 1;
        births = count;
    } else {
        firstFrame = 0;
        births = config->births;
    }
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry, 0xa);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    vertices = (FlashVertex*)((RpMorphTarget *)(u8*)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->morphTarget)->vertices;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    colors = ((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->colors;
    zero = 0.0f;
    direction.lane[1] = zero;
    direction.lane[3] = zero;
    innerWord = config->innerColor & 0x00ffffff;
    colorInput = &innerWord;
    normalization = fGpffff8044;
    effectVuUnpackColor10(colorInput, normalization);
    effectVuStore10(&innerColor);
    outerWord = config->outerColor & 0x00ffffff;
    effectVuUnpackColor10(&outerWord, normalization);
    effectVuStore10(&outerColor);
    acceleration = config->acceleration;
    recycle = config->recycle;
    index = 0;
    fullTurn = fGpffff80d0;
    unit = 1.0f;
    half = 0.5f;
    byteScale = 255.0f;
    for (; index < count; index++, particle++, vertices += 13, colors += 13) {
        s32 age = particle->age;
        if (age == -2) {
            continue;
        }
        if (age == -1) {
            if (births != 0) {
                f32 factor;
                particle->angle = fullTurn * effMiscRandFloat(0);
                radiusRandomness = config->radiusRandomness;
                phase = unit - radiusRandomness;
                factor = 0.0f + phase + radiusRandomness * effMiscRandFloat(0);
                particle->firstRadius = config->radius * factor;
                factor = 0.0f + phase + radiusRandomness * effMiscRandFloat(0);
                particle->secondRadius = config->radius * factor;
                phase = config->baseRandomness;
                factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
                particle->baseRadius = config->baseRadius * factor;
                phase = config->velocityRandomness;
                factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
                particle->velocity = config->velocity * factor;
                phase = config->sizeRandomness;
                factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
                particle->width = config->width * factor;
                if (firstFrame) {
                    particle->age = effMiscRand(0) % (u32)life;
                } else {
                    particle->age = initialAge;
                }
                births--;
            }
            continue;
        }
        if (age == terminalAge) {
            s32 vertex;
            for (vertex = 0; vertex < 13; vertex++) {
                vertices[vertex].x = zero;
                vertices[vertex].y = zero;
                vertices[vertex].z = zero;
                colors[vertex] = 0;
            }
            particle->age = recycle ? -1 : -2;
        } else {
            f32 time = (f32)age;
            f32 x;
            f32 z;
            f32 fade;
            u32 innerValue;
            u32 outerValue;
            s32 vertex;
            EffectVuVector *firstPointer;
            EffectVuVector *widthPointer;
            EffectVuVector *scratch;
            s32 secondVertex;
            phase = particle->angle;
            if (acceleration < zero) {
                f32 maximumTime = half * (-particle->velocity / (half * acceleration));
                if (!(time <= maximumTime)) {
                    time = maximumTime;
                }
            }
            distance = time * (0.0f + particle->velocity + half * (acceleration * time));
            distance += particle->baseRadius;
            effectVuLoad10((EffectVuVector *)D_00713CE0);
            effectVuScale10(particle->width);
            effectVuStore10(&width);
            direction.lane[0] = cosf(phase);
            direction.lane[2] = sinf(phase);
            effectVuLoad10(&direction);
            __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
            effectVuScale10(particle->firstRadius);
            __asm__ volatile("vmove.xyzw $vf11, $vf12" : : : "$vf11");
            firstPointer = &first;
            effectVuStore10(firstPointer);
            effectVuScale11(particle->secondRadius);
            effectVuStore11(&second);
            __asm__ volatile("vmove.xyzw $vf10, $vf12" : : : "$vf10");
            effectVuScale10(distance);
            effectVuStore10(&center);
            __asm__ volatile("vmove.xyzw $vf2, $vf10\nvmove.xyzw $vf10, $vf12\nvmove.xyzw $vf12, $vf2"
                : : : "$vf2", "$vf10", "$vf12");
            x = effectVuGetX10();
            z = effectVuGetZ10();
            effectVuSetX10(z);
            effectVuSetZ10(-x);
            widthPointer = &width;
            effectVuLoad11(widthPointer);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            effectVuStore10(widthPointer);
            scratch = (EffectVuVector *)D_00713D10;
            __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*scratch) : "r"(scratch) : "memory");
            vertices[0].x = D_00713D10[0];
            vertices[0].y = D_00713D14[0];
            vertices[0].z = D_00713D18[0];
            /* The tables contain raw IEEE-754 words. The transfer latency
             * nop belongs to the COP2 bridge, not to scalar computation. */
            for (vertex = 0; vertex < 6; vertex++) {
                effectVuLoad10(firstPointer);
                __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf10, $vf10, $vf2x"
                    : : "r"(D_00713FB0[vertex]) : "$vf2", "$vf10");
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf12" : : : "$vf10");
                effectVuLoad11(widthPointer);
                __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf11, $vf11, $vf2x"
                    : : "r"(D_00713F70[vertex]) : "$vf2", "$vf11");
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                effectVuStore10(scratch);
                vertices[vertex + 1].x = D_00713D10[0];
                vertices[vertex + 1].y = D_00713D14[0];
                vertices[vertex + 1].z = D_00713D18[0];
            }
            for (secondVertex = 6; secondVertex < 12; secondVertex++) {
                effectVuLoad10(&second);
                __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf10, $vf10, $vf2x"
                    : : "r"(D_00713FB0[secondVertex]) : "$vf2", "$vf10");
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf12" : : : "$vf10");
                effectVuLoad11(&width);
                __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf11, $vf11, $vf2x"
                    : : "r"(D_00713F70[secondVertex]) : "$vf2", "$vf11");
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                effectVuStore10((EffectVuVector *)D_00713D10);
                vertices[secondVertex + 1].x = D_00713D10[0];
                vertices[secondVertex + 1].y = D_00713D14[0];
                vertices[secondVertex + 1].z = D_00713D18[0];
            }
            if (age < fadeIn) {
                fade = (f32)age / (f32)fadeIn;
            } else if (age > fadeOut) {
                fade = (f32)(life - age) / (f32)(life - fadeOut);
            } else {
                fade = unit;
            }
            effectVuLoad11((EffectVuVector *)D_00713CE0);
            effectVuScale11(fade);
            effectVuLoad10(&outerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 transfer;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni %0, $vf10 \n"
                    "ppach %0, $zero, %0 \n"
                    "ppacb %0, $zero, %0 \n"
                    "sw %0, outerPacked \n"
                    : "=&r"(transfer), "=m"(outerPacked)
                    : "r"(byteScale) : "$vf2", "$vf10");
            }
            {
                s32 colorIndex;
                outerValue = outerPacked;
                for (colorIndex = 1; colorIndex <= 12; colorIndex++) {
                    colors[colorIndex] = outerValue;
                }
            }
            effectVuLoad10(&innerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 transfer;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni %0, $vf10 \n"
                    "ppach %0, $zero, %0 \n"
                    "ppacb %0, $zero, %0 \n"
                    "sw %0, innerPacked \n"
                    : "=&r"(transfer), "=m"(innerPacked)
                    : "r"(byteScale) : "$vf2", "$vf10");
            }
            innerValue = innerPacked;
            colors[0] = innerValue | ((u32)(byteScale * fade) << 24);
            particle->age = age + ageStep;
        }
    }
    {
        u8 *geometry = (u8*)((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry;
        func_003c22f0(geometry);
        if (((EffGeometryBlock *)owner)->kind & 4) {
            ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
        }
    }
}
#pragma pop
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// Packs the radial flash vertex colours from the inner and outer colour words.
// FUN_0049BFF0
void FlashRadialPackColors(u8 *input)
{
    union
    {
        s32 w;
        u8 b[4];
    } packedColor;
    s32 parentColor;
    s32 sampleColor;
    s32 combinedColor;
    s32 sampledColor;
    u8 *state;
    u8 *config;
    u8 *geometryOwner;
    u32 frame;
    u32 lastFrame;
    f32 scale;

    state = ((FlashEffect *)input)->state;
    config = ((FlashEffect *)input)->parameters;
    geometryOwner = ((FlashBlock *)state)->geometry.bytes;
    frame = ((FlashEffect *)input)->frame;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    if ((lastFrame >= frame) || (lastFrame == 0))
    {
        s32 *pt;

        sampledColor = mdlEffectSamplePackedColor(config, config + 0x24, frame, lastFrame);
        parentColor = ((FlashEffect *)input)->color;
        pt = &parentColor;
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
        sampleColor = sampledColor;
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
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sampleColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        packedColor.w = *(s32 *)&combinedColor;
        if (packedColor.b[3] != 0xFF)
        {
            u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
            ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
        }
        else
        {
            packedColor.b[3] = 0xFE;
            {
                u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
                ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
            }
            packedColor.b[3] = 0xFF;
        }
        GeometryBlockSetFrameMatrixCombined(geometryOwner, input, input + 0x10, input + 0x20);
        if (((FlashParameters *)config)->geometryFlag != 0)
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind | 1;
        }
        else
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind & 0xFFFE;
        }
        {
            s32 resourceId = ((FlashParameters *)config)->resourceId;
            GeometryBlockBindResource(geometryOwner, resourceId);
        }
    }
}

/* measured: shares FlashRotatingUpdateGeometry's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see 0x0049b470). */
/* measured: same shape as FlashRotatingUpdateGeometry above; see that note. */
// Updates the radial flash geometry: locks the model geometry and clears its vertex buffer before the rebuild.
// FUN_0049C1B0
#pragma opt_loop_invariants on
void FlashRadialUpdateGeometry(u8 *input)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = ((FlashEffect *)input)->state;
    entry = *(s32 **)state;
    work = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)((FlashEffect *)input)->parameters)->vertexCount.signedCount;
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)work)->atomic)->geometry, 2);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    tex = (s32**)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry)->morphTarget;
    memset((s32)tex[5], 0, ((EffGeometryBlock *)work)->vertexCount * 0xC);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    model = (u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry;
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        ((RpGeometry *)model)->lockedSinceLastInst = ((RpGeometry *)model)->lockedSinceLastInst | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 11;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
// Allocates a wide radial-flash block: count * 44 entry bytes, with the radial geometry handle.
// FUN_0049C2A0
void *FlashRadialAllocBlockWide(u8 *input, s32 resource)
{
    u32 id;
    u8 *mem;

    if (resource) {
        kAssertFail(D_00713FF0, 0x349);
    }
    id = (u32)((FlashParameters *)input)->vertexCount.signedCount;
    chkmemAllocSiteTag(D_00713FF0, 0x350);
    mem = jtbl_008873E8[0](id * 44 + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x351);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.pointer = (void *)mem;
    ((FlashBlock *)mem)->geometry.bytes = (u8 *)GeometryCreateTableGrid(id & 0xFFFF, 0xC, 0xD, D_007133C0, 0x48);
    return mem;
}




// Frees a wide radial-flash block: its geometry handle, then the block itself.
// FUN_0049C380
void FlashRadialFreeBlockWide(u8 *input)
{
    GeometryBlockDestroy(((FlashBlock *)input)->geometry.bytes);
    jtbl_008873EC[0](((FlashBlock *)input)->allocation.pointer);
}

typedef struct FlashEvolvingRadialParticle {
    s32 age;
    f32 angularVelocity, verticalVelocity, angle;
    f32 firstRadius, secondRadius, baseRadius, radiusStep, width;
    u8 reserved24[8];
} FlashEvolvingRadialParticle;
typedef struct FlashEvolvingRadialState {
    FlashEvolvingRadialParticle *particles;
    u8 *geometryOwner;
    u8 reserved[8];
} FlashEvolvingRadialState;
typedef struct FlashEvolvingRadialConfig {
    u8 prefix[0x34];
    u32 lastFrame;
    s32 count;
    u8 reserved3c[8];
    f32 fadeIn, fadeOut;
    s32 life, births;
    u8 recycle, burst;
    u8 reserved56[2];
    u32 innerColor, outerColor;
    f32 width, unused64, sizeRandomness;
    f32 radius, radiusRandomness;
    f32 startRadius, startRadiusRandomness, endRadius, endRadiusRandomness;
    f32 verticalVelocity, verticalRandomness, angularAcceleration;
    f32 angularVelocity, angularRandomness, gravity;
} FlashEvolvingRadialConfig;
typedef char FlashEvolvingRadialParticleSize[(sizeof(FlashEvolvingRadialParticle)==0x2c)?1:-1];
typedef char FlashEvolvingRadialConfigSize[(sizeof(FlashEvolvingRadialConfig)==0x9c)?1:-1];
// Emits the evolving radial flash quads for one effect, from the evolving particle state.
// FUN_0049C3D0
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void FlashEvolvingRadialEmitQuads(u8 *effect)
{
    u32 innerWord;
    u32 outerWord;
    u32 outerPacked;
    u32 innerPacked;
    EffectVuVector innerColor;
    EffectVuVector outerColor;
    EffectVuVector direction;
    EffectVuVector width;
    EffectVuVector second;
    EffectVuVector first;
    s32 firstFrame;
    s32 count;
    s32 index;
    s32 fadeIn;
    s32 fadeOut;
    s32 recycle;
    FlashEvolvingRadialState *state;
    FlashEvolvingRadialParticle *particle;
    FlashEvolvingRadialConfig *config;
    u8 *owner;
    s32 life;
    FlashVertex *vertices;
    u32 *colors;
    f32 acceleration;
    f32 gravity;
    f32 height;
    f32 distance;
    f32 radiusRandomness;
    f32 phase;
    f32 fullTurn;
    f32 unit;
    f32 zero;
    f32 half;
    f32 byteScale;
    f32 normalization;
    const u32 *colorInput;
    u32 frame;
    u32 lastFrame;
    s32 births;

    config = (FlashEvolvingRadialConfig *)((FlashEffect *)effect)->parameters;
    lastFrame = config->lastFrame;
    frame = ((FlashEffect *)effect)->frame;
    if (lastFrame < frame && lastFrame != 0) {
        return;
    }
    state = (FlashEvolvingRadialState *)((FlashEffect *)effect)->state;
    particle = state->particles;
    owner = state->geometryOwner;
    count = config->count;
    life = config->life;
    if (life == 0) {
        return;
    }
    fadeIn = (s32)(config->fadeIn * (f32)life);
    fadeOut = (s32)(config->fadeOut * (f32)life);
    if (config->burst != 0 && frame == 0) {
        firstFrame = 1;
        births = count;
    } else {
        firstFrame = 0;
        births = config->births;
    }
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry, 0xa);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    vertices = (FlashVertex*)((RpMorphTarget *)(u8*)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->morphTarget)->vertices;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    colors = ((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->colors;
    zero = 0.0f;
    direction.lane[1] = zero;
    direction.lane[3] = zero;
    innerWord = config->innerColor & 0x00ffffff;
    colorInput = &innerWord;
    normalization = fGpffff8044;
    effectVuUnpackColor10(colorInput, normalization);
    effectVuStore10(&innerColor);
    outerWord = config->outerColor & 0x00ffffff;
    effectVuUnpackColor10(&outerWord, normalization);
    effectVuStore10(&outerColor);
    acceleration = config->angularAcceleration;
    gravity = config->gravity;
    recycle = config->recycle;
    __asm__ volatile("sqc2 $vf0, 0(%1)" : "=m"(first) : "r"(&first) : "memory");
    __asm__ volatile("sqc2 $vf0, 0(%1)" : "=m"(second) : "r"(&second) : "memory");
    index = 0;
    fullTurn = fGpffff80d0;
    unit = 1.0f;
    half = 0.5f;
    byteScale = 255.0f;
    for (; index < count; index++, particle++, vertices += 13, colors += 13) {
        s32 age = particle->age;
        if (age == -2) {
            continue;
        }
        if (age == -1) {
            if (births != 0) {
                f32 factor;
                f32 endpoint;
                particle->angle = fullTurn * effMiscRandFloat(0);
                phase = config->radiusRandomness;
                radiusRandomness = unit - phase;
                factor = 0.0f + radiusRandomness + phase * effMiscRandFloat(0);
                particle->firstRadius = config->radius * factor;
                factor = 0.0f + radiusRandomness + phase * effMiscRandFloat(0);
                particle->secondRadius = config->radius * factor;
                radiusRandomness = config->startRadiusRandomness;
            factor = 0.0f + (unit - radiusRandomness) + radiusRandomness * effMiscRandFloat(0);
            radiusRandomness = config->startRadius * factor;
            phase = config->endRadiusRandomness;
            factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
            endpoint = config->endRadius * factor;
            particle->baseRadius = radiusRandomness;
            particle->radiusStep = (endpoint - radiusRandomness) / (f32)life;
            radiusRandomness = config->angularRandomness;
            factor = 0.0f + (unit - radiusRandomness) + radiusRandomness * effMiscRandFloat(0);
            particle->angularVelocity = config->angularVelocity * factor;
            radiusRandomness = config->verticalRandomness;
            factor = 0.0f + (unit - radiusRandomness) + radiusRandomness * effMiscRandFloat(0);
            particle->verticalVelocity = config->verticalVelocity * factor;
            radiusRandomness = config->sizeRandomness;
            factor = 0.0f + (unit - radiusRandomness) + radiusRandomness * effMiscRandFloat(0);
            particle->width = config->width * factor;
            if (firstFrame) {
                    particle->age = effMiscRand(0) % (u32)life;
                } else {
                    particle->age = 0;
                }
                births--;
            }
            continue;
        }
        if (age >= life) {
            s32 vertex;
            for (vertex = 0; vertex < 13; vertex++) {
                vertices[vertex].x = zero;
                vertices[vertex].y = zero;
                vertices[vertex].z = zero;
                colors[vertex] = 0;
            }
            particle->age = recycle ? -1 : -2;
        } else {
            f32 time = (f32)age;
            f32 x;
            f32 z;
            f32 fade;
            u32 innerValue;
            u32 outerValue;
            s32 vertex;
            EffectVuVector *widthPointer;
            EffectVuVector *scratch;
            EffectVuVector *firstPointer;
            s32 secondVertex;
            f32 offset = half * (acceleration * time);
            phase = time * (particle->verticalVelocity + offset);
            phase += particle->angle;
            height = time * (particle->angularVelocity + offset);
            { f32 falling; f32 fallen; falling = gravity * time; fallen = time * falling; height = height - half * fallen; }
            distance = 0.0f + particle->baseRadius + particle->radiusStep * time;
            first.lane[1] = particle->firstRadius;
            second.lane[1] = particle->secondRadius;
            effectVuLoad10((EffectVuVector *)D_00713CE0);
            effectVuScale10(particle->width);
            effectVuStore10(&width);
            direction.lane[0] = cosf(phase);
            direction.lane[2] = sinf(phase);
            effectVuLoad10(&direction);
            __asm__ volatile("vmove.xyzw $vf12, $vf10" : : : "$vf12");
            effectVuScale10(distance);
            __asm__ volatile("qmtc2.ni %0, $vf2\n"
                             "vaddx.y $vf10, $vf0, $vf2x\n"
                             : : "r"(height) : "$vf2", "$vf10");
            __asm__ volatile("vmove.xyzw $vf2, $vf10\n"
                             "vmove.xyzw $vf10, $vf12\n"
                             "vmove.xyzw $vf12, $vf2\n"
                             : : : "$vf2", "$vf10", "$vf12");
            x = effectVuGetX10();
            z = effectVuGetZ10();
            effectVuSetX10(z);
            effectVuSetZ10(-x);
            widthPointer = &width;
            effectVuLoad11(widthPointer);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            effectVuStore10(widthPointer);
            scratch = (EffectVuVector *)D_00713D10;
            __asm__ volatile("sqc2 $vf12, 0(%1)" : "=m"(*scratch) : "r"(scratch) : "memory");
            vertices[0].x = D_00713D10[0];
            vertices[0].y = D_00713D14[0];
            vertices[0].z = D_00713D18[0];
            /* The tables contain raw IEEE-754 words. The transfer latency
             * nop belongs to the COP2 bridge, not to scalar computation. */
            vertex = 0;
            firstPointer = &first;
            for (; vertex < 6; vertex++) {
                effectVuLoad10(firstPointer);
                __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf10, $vf10, $vf2x"
                    : : "r"(D_00713FB0[vertex]) : "$vf2", "$vf10");
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf12" : : : "$vf10");
                effectVuLoad11(widthPointer);
                __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf11, $vf11, $vf2x"
                    : : "r"(D_00713F70[vertex]) : "$vf2", "$vf11");
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                effectVuStore10(scratch);
                vertices[vertex + 1].x = D_00713D10[0];
                vertices[vertex + 1].y = D_00713D14[0];
                vertices[vertex + 1].z = D_00713D18[0];
            }
            for (secondVertex = 6; secondVertex < 12; secondVertex++) {
                effectVuLoad10(&second);
                __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf10, $vf10, $vf2x"
                    : : "r"(D_00713FB0[secondVertex]) : "$vf2", "$vf10");
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf12" : : : "$vf10");
                effectVuLoad11(&width);
                __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf11, $vf11, $vf2x"
                    : : "r"(D_00713F70[secondVertex]) : "$vf2", "$vf11");
                __asm__ volatile("vadd.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                effectVuStore10((EffectVuVector *)D_00713D10);
                vertices[secondVertex + 1].x = D_00713D10[0];
                vertices[secondVertex + 1].y = D_00713D14[0];
                vertices[secondVertex + 1].z = D_00713D18[0];
            }
            if (age < fadeIn) {
                fade = (f32)age / (f32)fadeIn;
            } else if (age > fadeOut) {
                fade = (f32)(life - age) / (f32)(life - fadeOut);
            } else {
                fade = unit;
            }
            effectVuLoad11((EffectVuVector *)D_00713CE0);
            effectVuScale11(fade);
            effectVuLoad10(&outerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 transfer;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni %0, $vf10 \n"
                    "ppach %0, $zero, %0 \n"
                    "ppacb %0, $zero, %0 \n"
                    "sw %0, outerPacked \n"
                    : "=&r"(transfer), "=m"(outerPacked)
                    : "r"(byteScale) : "$vf2", "$vf10");
            }
            {
                s32 colorIndex;
                outerValue = outerPacked;
                for (colorIndex = 1; colorIndex <= 12; colorIndex++) {
                    colors[colorIndex] = outerValue;
                }
            }
            effectVuLoad10(&innerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 transfer;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni %0, $vf10 \n"
                    "ppach %0, $zero, %0 \n"
                    "ppacb %0, $zero, %0 \n"
                    "sw %0, innerPacked \n"
                    : "=&r"(transfer), "=m"(innerPacked)
                    : "r"(byteScale) : "$vf2", "$vf10");
            }
            innerValue = innerPacked;
            colors[0] = innerValue | ((u32)(byteScale * fade) << 24);
            particle->age = age + 1;
        }
    }
    {
        u8 *geometry = (u8*)((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry;
        func_003c22f0(geometry);
        if (((EffGeometryBlock *)owner)->kind & 4) {
            ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
        }
    }
}
#pragma pop
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// Packs the evolving radial flash vertex colours from the inner and outer colour words.
// FUN_0049CD10
void FlashEvolvingRadialPackColors(u8 *input)
{
    union
    {
        s32 w;
        u8 b[4];
    } packedColor;
    s32 parentColor;
    s32 sampleColor;
    s32 combinedColor;
    s32 sampledColor;
    u8 *state;
    u8 *config;
    u8 *geometryOwner;
    u32 frame;
    u32 lastFrame;
    f32 scale;

    state = ((FlashEffect *)input)->state;
    config = ((FlashEffect *)input)->parameters;
    geometryOwner = ((FlashBlock *)state)->geometry.bytes;
    frame = ((FlashEffect *)input)->frame;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    if ((lastFrame >= frame) || (lastFrame == 0))
    {
        s32 *pt;

        sampledColor = mdlEffectSamplePackedColor(config, config + 0x24, frame, lastFrame);
        parentColor = ((FlashEffect *)input)->color;
        pt = &parentColor;
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
        sampleColor = sampledColor;
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
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sampleColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        packedColor.w = *(s32 *)&combinedColor;
        if (packedColor.b[3] != 0xFF)
        {
            u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
            ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
        }
        else
        {
            packedColor.b[3] = 0xFE;
            {
                u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
                ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
            }
            packedColor.b[3] = 0xFF;
        }
        GeometryBlockSetFrameMatrixCombined(geometryOwner, input, input + 0x10, input + 0x20);
        if (((FlashParameters *)config)->geometryFlag != 0)
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind | 1;
        }
        else
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind & 0xFFFE;
        }
        {
            s32 resourceId = ((FlashParameters *)config)->resourceId;
            GeometryBlockBindResource(geometryOwner, resourceId);
        }
    }
}

/* measured: shares FlashRotatingUpdateGeometry's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see 0x0049b470). */
/* measured: same shape as FlashRotatingUpdateGeometry above; see that note. */
// Updates the evolving radial flash geometry: locks the model geometry and clears its vertex buffer before the rebuild.
// FUN_0049CED0
#pragma opt_loop_invariants on
void FlashEvolvingRadialUpdateGeometry(u8 *input)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = ((FlashEffect *)input)->state;
    entry = *(s32 **)state;
    work = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)((FlashEffect *)input)->parameters)->vertexCount.signedCount;
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)work)->atomic)->geometry, 2);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    tex = (s32**)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry)->morphTarget;
    memset((s32)tex[5], 0, ((EffGeometryBlock *)work)->vertexCount * 0xC);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    model = (u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry;
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        ((RpGeometry *)model)->lockedSinceLastInst = ((RpGeometry *)model)->lockedSinceLastInst | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// Initialises the evolving radial entries from the config (asserts when the entry array is missing).
// FUN_0049CFC0
/* Earlier whole-chain trial: 320 -> 308 bytes, 38 normalized bytes changed; individual culprits remain below. */
#pragma opt_loop_invariants on
void FlashEvolvingRadialInitEntries(u8 *input, u8 *resource)
{
    u32 count;
    u8 *sourceObject;
    u8 *workCursor;
    u32 i;

    count = (u32)((FlashParameters *)resource)->vertexCount.signedCount;
    if (count != 0) {
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)((FlashBlock *)input)->geometry.bytes)->atomic)->geometry, 0xFF0);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        workCursor = *(u8 **)((u8*)((RpAtomic *)((EffGeometryBlock *)*(u8 **)(input + 4))->atomic)->geometry + 0x34);
        if (workCursor == NULL) {
            kAssertFail(D_00713FF0, 0x4BE);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                ((FlashUvQuad *)workCursor)->coordinates[0] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[1] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[2] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[3] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[4] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[5] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[6] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[7] = 1.0f;
            } else {
                ((FlashUvQuad *)workCursor)->coordinates[0] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[1] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[2] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[3] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[4] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[5] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[6] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[7] = 1.0f;
            }
            i++;
            workCursor += 0x20;
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        workCursor = *(u8 **)(input + 4);
        sourceObject = (u8*)((RpAtomic *)((EffGeometryBlock *)workCursor)->atomic)->geometry;
        func_003c22f0(sourceObject);
        if (((EffGeometryBlock *)workCursor)->kind & 4) {
            ((RpGeometry *)sourceObject)->lockedSinceLastInst |= 1;
        }
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// Allocates an evolving radial flash block with a texture (default texture 0x12 when none is given).
// FUN_0049D100
/* Keep the pointer-bit and halfword-count accesses below: typed replacement
 * changed this constructor's instruction stream despite the proven layout. */
/* Earlier constructor-wide typing grew 304 -> 312 bytes; access-site trials retain only the culprits below. */
void *FlashEvolvingRadialAllocBlock(u8 *input, void *resource)
{
    u32 size;
    u8 *mem;

    size = ((FlashParameters *)input)->vertexCount.count * 24;
    chkmemAllocSiteTag(D_00713FF0, 0x4A3);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x4A4);
    }
    ((FlashBlock *)mem)->particles.word = (u32)(mem + 0x10);
    ((FlashBlock *)mem)->allocation.word = (u32)mem;
    if (((FlashParameters *)input)->unk70.bits == 0) {
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u32 *)(input + 0x70) = 1;
    }
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    *(u32 *)(mem + 4) = (u32)GeometryCreateTableGrid(*(u16 *)(input + 0x38), 2, 4, D_00713408, 0x4C);
    if (resource == NULL) {
        func_003c42b0(((EffGeometryBlock *)((FlashBlock *)mem)->geometry.bytes)->material, (void *)TnSlotObject(0x12));
    } else {
        GeometryBlockSetTextureFromHandle(((FlashBlock *)mem)->geometry.bytes, resource);
    }
    FlashEvolvingRadialInitEntries(mem, input);
    return mem;
}
// Allocates an evolving radial flash block that inherits its texture from a parent block.
// FUN_0049D230
/* Keep the pointer-bit and halfword-count accesses below: typed replacement
 * changed this constructor's instruction stream despite the proven layout. */
void *FlashEvolvingRadialAllocFromParent(u8 *input)
{
    u8 *sourceObject;
    u8 *workCursor;
    u32 size;
    u8 *mem;

    sourceObject = (void *)((FlashEffect *)input)->state;
    workCursor = (void *)((FlashEffect *)input)->parameters;
    size = (u32)((FlashParameters *)workCursor)->vertexCount.signedCount * 24;
    chkmemAllocSiteTag(D_00713FF0, 0x4A3);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x4A4);
    }
    ((FlashBlock *)mem)->particles.word = (u32)(mem + 0x10);
    ((FlashBlock *)mem)->allocation.pointer = (void *)mem;
    if (((FlashParameters *)workCursor)->unk70.bits == 0) {
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        *(u32 *)(workCursor + 0x70) = 1;
    }
    ((FlashBlock *)mem)->geometry.bytes = (u8 *)GeometryCloneBlock(((FlashBlock *)sourceObject)->geometry.pointer);
    FlashEvolvingRadialInitEntries(mem, workCursor);
    return mem;
}
// Frees an evolving radial flash block: its geometry handle, then the block itself.
// FUN_0049D310
void FlashEvolvingRadialFreeBlock(u8 *input)
{
    GeometryBlockDestroy(((FlashBlock *)input)->geometry.bytes);
    jtbl_008873EC[0](((FlashBlock *)input)->allocation.pointer);
}
// Emits quads from the direction, length and width vectors (no centre) for one evolving radial flash effect.
// FUN_0049D360
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
    void FlashEvolvingRadialEmitDirectionalQuads(u8 *effect)
    {
        u32 innerWord, outerWord, outerPacked, innerPacked;
        EffectVuVector innerColor, outerColor;
        EffectVuVector direction, lengthVector, widthVector;
        s32 firstFrame, count, index, fadeIn, fadeOut, recycle;
        u8 *state, *owner, *config;
        s32 *particle;
        f32 *particleData;
        s32 life, period;
        FlashVertex *vertices;
        u32 *colors;
        f32 phase, acceleration, factor, fullTurn, unit, negativeUnit, zero, half, byteScale, normalization;
        const u32 *colorInput;
        u32 frame, lastFrame;
        s32 births;

        config = ((FlashEffect *)effect)->parameters;
        lastFrame = ((FlashParameters *)config)->lastFrame;
        frame = ((FlashEffect *)effect)->frame;
        if (lastFrame < frame && lastFrame != 0) return;
        state = ((FlashEffect *)effect)->state;
        particle = *(s32 **)state;
        owner = ((FlashBlock *)state)->geometry.bytes;
        count = ((FlashParameters *)config)->vertexCount.signedCount;
        life = ((FlashParameters *)config)->life;
        if (life == 0) return;
        
        if (((FlashParameters *)config)->burst != 0 && frame == 0) {
            firstFrame = 1;
            births = count;
        } else {
            firstFrame = 0;
            births = ((FlashParameters *)config)->births;
        }
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry, 10);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        vertices = (FlashVertex*)((RpMorphTarget *)(u8*)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->morphTarget)->vertices;
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        colors = ((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->colors;
        zero = 0.0f;
        direction.lane[1] = zero;
        direction.lane[3] = zero;
        innerWord = ((FlashParameters *)config)->innerColor;
        colorInput = &innerWord;
        normalization = fGpffff8044;
        effectVuUnpackColor10(colorInput, normalization);
        effectVuStore10(&innerColor);
        outerWord = ((FlashParameters *)config)->outerColor;
        effectVuUnpackColor10(&outerWord, normalization);
        effectVuStore10(&outerColor);

    fadeIn = (s32)(((FlashParameters *)config)->fadeIn * (f32)life);
    fadeOut = (s32)(((FlashParameters *)config)->fadeOut * (f32)life);
        acceleration = ((FlashParameters *)config)->unk7C;
    period = ((FlashParameters *)config)->unk70.period;
        recycle = ((FlashParameters *)config)->recycle;
        index = 0;
        fullTurn = fGpffff80d0;
        unit = 1.0f;
        negativeUnit = -1.0f;
        half = 0.5f;
        byteScale = 255.0f;
        for (; index < count; index++, particle += 6, vertices += 4, colors += 4) {
            s32 age = *particle;
            particleData = (f32 *)particle;
            if (age == -2) continue;
            if (age == -1) {
                if (births == 0) continue;
                particleData[2] = fullTurn * effMiscRandFloat(0);
    phase = ((FlashParameters *)config)->unk78;
    factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
    particleData[1] = ((FlashParameters *)config)->unk74 * factor;
    if (effMiscRand(0) & 1) particleData[1] *= negativeUnit;
    particleData[3] = zero;
    phase = ((FlashParameters *)config)->unk6C;
    factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
    particleData[4] = (((FlashParameters *)config)->unk68 * factor) / (f32)period;
    phase = ((FlashParameters *)config)->unk64;
    factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
    particleData[5] = ((FlashParameters *)config)->unk60 * factor;

                if (firstFrame) {
                    *particle = effMiscRand(0) % (u32)life;
                    particleData[3] = 0.0f + particleData[3] + particleData[4] * (f32)(*particle % period);
                } else {
                    *particle = 0;
                }
                births--;
                continue;
            }
            if (age >= life) {
                s32 vertex;
                for (vertex = 0; vertex < 4; vertex++) {
                    vertices[vertex].x = zero;
                    vertices[vertex].y = zero;
                    vertices[vertex].z = zero;
                    colors[vertex] = 0;
                }
                *particle = recycle ? -1 : -2;
            } else {
                f32 time = (f32)age;
                f32 distance;
                f32 fade;
                f32 sine, cosine;
                if (particleData[1] > zero) distance = time * (0.0f + particleData[1] + half * (acceleration * time));
    else distance = time * (0.0f + particleData[1] - half * (acceleration * time));
    distance += particleData[2];
    if (age < period) particleData[3] = particleData[3] + particleData[4];
    effectVuLoad10((EffectVuVector *)D_00713CE0);
    __asm__ volatile(
        "vmove.xyzw $vf11, $vf10 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuScale10(particleData[3]);
    effectVuStore10(&lengthVector);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuScale10(particleData[5]);
    effectVuStore10(&widthVector);
    direction.lane[0] = cosf(distance);
    direction.lane[2] = sinf(distance);
    effectVuLoad10(&direction);
    __asm__ volatile(
        "vmove.xyzw $vf12, $vf10 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    cosine = effectVuGetX10();
    sine = effectVuGetZ10();
    effectVuSetX10(sine);
    effectVuSetZ10(-cosine);
    __asm__ volatile(
        "vmove.xyzw $vf11, $vf10 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuLoad10(&widthVector);
    __asm__ volatile(
        "vmul.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10(&widthVector);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf12 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuLoad11(&lengthVector);
    __asm__ volatile(
        "vmul.xyzw $vf10, $vf10, $vf11 \n"
        "vmove.xyzw $vf12, $vf10 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuLoad10(&widthVector);
    __asm__ volatile(
        "vmove.xyzw $vf11, $vf10 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10((EffectVuVector *)D_00713D10);
    vertices[2].x = D_00713D10[0];
    vertices[2].y = D_00713D14[0];
    vertices[2].z = D_00713D18[0];
    __asm__ volatile(
        "vsub.xyz $vf11, $vf0, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore11((EffectVuVector *)D_00713D10);
    vertices[3].x = D_00713D10[0];
    vertices[3].y = D_00713D14[0];
    vertices[3].z = D_00713D18[0];
    effectVuLoad10(&widthVector);
    __asm__ volatile(
        "vmove.xyzw $vf11, $vf10 \n"
        "vadd.xyzw $vf10, $vf10, $vf12 \n"
        "vsub.xyz $vf11, $vf0, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10((EffectVuVector *)D_00713D10);
    vertices[0].x = D_00713D10[0];
    vertices[0].y = D_00713D14[0];
    vertices[0].z = D_00713D18[0];
    __asm__ volatile(
        "vadd.xyzw $vf11, $vf11, $vf12 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore11((EffectVuVector *)D_00713D10);
    vertices[1].x = D_00713D10[0];
    vertices[1].y = D_00713D14[0];
    vertices[1].z = D_00713D18[0];

                if (age < fadeIn) fade = (f32)age / (f32)fadeIn;
                else if (age > fadeOut) fade = (f32)(life - age) / (f32)(life - fadeOut);
                else fade = unit;
                effectVuLoad11((EffectVuVector *)D_00713CE0);
                effectVuScale11(fade);
                effectVuLoad10(&outerColor);
                __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni %0, $vf10 \n"
            "ppach %0, $zero, %0 \n"
            "ppacb %0, $zero, %0 \n"
            "sw %0, outerPacked \n"
            : "=&r"(transfer), "=m"(outerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
    }

                colors[0] = outerPacked;
                colors[1] = outerPacked;
                effectVuLoad10(&innerColor);
                __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni %0, $vf10 \n"
            "ppach %0, $zero, %0 \n"
            "ppacb %0, $zero, %0 \n"
            "sw %0, innerPacked \n"
            : "=&r"(transfer), "=m"(innerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
    }

                colors[2] = innerPacked;
                colors[3] = innerPacked;
                *particle = age + 1;
            }
        }
        {
            u8 *geometry = (u8*)((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry;
            func_003c22f0(geometry);
            if (((EffGeometryBlock *)owner)->kind & 4) ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
        }
    }
#pragma pop





// Packs the textured flash vertex colours from the inner and outer colour words.
// FUN_0049DB20
void FlashTexturedPackColors(u8 *input)
{
    union
    {
        s32 w;
        u8 b[4];
    } packedColor;
    s32 parentColor;
    s32 sampleColor;
    s32 combinedColor;
    s32 sampledColor;
    u8 *state;
    u8 *config;
    u8 *geometryOwner;
    u32 frame;
    u32 lastFrame;
    f32 scale;

    state = ((FlashEffect *)input)->state;
    config = ((FlashEffect *)input)->parameters;
    geometryOwner = ((FlashBlock *)state)->geometry.bytes;
    frame = ((FlashEffect *)input)->frame;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    if ((lastFrame >= frame) || (lastFrame == 0))
    {
        s32 *pt;

        sampledColor = mdlEffectSamplePackedColor(config, config + 0x24, frame, lastFrame);
        parentColor = ((FlashEffect *)input)->color;
        pt = &parentColor;
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
        sampleColor = sampledColor;
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
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sampleColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        packedColor.w = *(s32 *)&combinedColor;
        if (packedColor.b[3] != 0xFF)
        {
            u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
            ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
        }
        else
        {
            packedColor.b[3] = 0xFE;
            {
                u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
                ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
            }
            packedColor.b[3] = 0xFF;
        }
        GeometryBlockSetFrameMatrixCombined(geometryOwner, input, input + 0x10, input + 0x20);
        if (((FlashParameters *)config)->geometryFlag != 0)
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind | 1;
        }
        else
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind & 0xFFFE;
        }
        {
            s32 resourceId = ((FlashParameters *)config)->resourceId;
            GeometryBlockBindResource(geometryOwner, resourceId);
        }
    }
}

/* measured: shares FlashRotatingUpdateGeometry's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see 0x0049b470). */
/* measured: same shape as FlashRotatingUpdateGeometry above; see that note. */
// Updates the textured flash geometry: locks the model geometry and clears its vertex buffer before the rebuild.
// FUN_0049DCE0
#pragma opt_loop_invariants on
void FlashTexturedUpdateGeometry(u8 *input)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = ((FlashEffect *)input)->state;
    entry = *(s32 **)state;
    work = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)((FlashEffect *)input)->parameters)->vertexCount.signedCount;
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)work)->atomic)->geometry, 2);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    tex = (s32**)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry)->morphTarget;
    memset((s32)tex[5], 0, ((EffGeometryBlock *)work)->vertexCount * 0xC);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    model = (u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry;
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        ((RpGeometry *)model)->lockedSinceLastInst = ((RpGeometry *)model)->lockedSinceLastInst | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 6;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// Initialises the textured flash entries from the config: per-entry geometry and offsets.
// FUN_0049DDD0
/* Earlier whole-chain trial: 320 -> 308 bytes, 38 normalized bytes changed; individual culprits remain below. */
#pragma opt_loop_invariants on
void FlashTexturedInitEntries(u8 *input, u8 *resource)
{
    u32 count;
    u8 *sourceObject;
    u8 *workCursor;
    u32 i;

    count = (u32)((FlashParameters *)resource)->vertexCount.signedCount;
    if (count != 0) {
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)((FlashBlock *)input)->geometry.bytes)->atomic)->geometry, 0xFF0);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        workCursor = *(u8 **)((u8*)((RpAtomic *)((EffGeometryBlock *)*(u8 **)(input + 4))->atomic)->geometry + 0x34);
        if (workCursor == NULL) {
            kAssertFail(D_00713FF0, 0x65A);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                ((FlashUvQuad *)workCursor)->coordinates[0] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[1] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[2] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[3] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[4] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[5] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[6] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[7] = 1.0f;
            } else {
                ((FlashUvQuad *)workCursor)->coordinates[0] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[1] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[2] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[3] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[4] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[5] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[6] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[7] = 1.0f;
            }
            i++;
            workCursor += 0x20;
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        workCursor = *(u8 **)(input + 4);
        sourceObject = (u8*)((RpAtomic *)((EffGeometryBlock *)workCursor)->atomic)->geometry;
        func_003c22f0(sourceObject);
        if (((EffGeometryBlock *)workCursor)->kind & 4) {
            ((RpGeometry *)sourceObject)->lockedSinceLastInst |= 1;
        }
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// Allocates a textured flash block (default texture 0x13 when none is given).
// FUN_0049DF10
/* Earlier count/pointer trial: 288 -> 292 bytes; individual raw culprits remain below. */
void *FlashTexturedAllocBlock(u8 *input, void *resource)
{
    u32 size;
    u8 *mem;

    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    size = *(u32 *)(input + 0x38) * 24;
    chkmemAllocSiteTag(D_00713FF0, 0x643);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x644);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.word = (u32)mem;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    *(u32 *)(mem + 4) = (u32)GeometryCreateTableGrid(((FlashParameters *)input)->vertexCount.low, 2, 4, D_00713408, 0x4C);
    if (resource == NULL) {
        func_003c42b0(((EffGeometryBlock *)((FlashBlock *)mem)->geometry.bytes)->material, (void *)TnSlotObject(0x13));
    } else {
        GeometryBlockSetTextureFromHandle(((FlashBlock *)mem)->geometry.bytes, resource);
    }
    FlashTexturedInitEntries(mem, input);
    return mem;
}
// Allocates a textured flash block that inherits its texture from a parent block.
// FUN_0049E030
void *FlashTexturedAllocFromParent(u8 *input)
{
    u8 *sourceObject;
    u8 *workCursor;
    u32 size;
    u8 *mem;

    sourceObject = (void *)((FlashEffect *)input)->state;
    workCursor = (void *)((FlashEffect *)input)->parameters;
    size = (u32)((FlashParameters *)workCursor)->vertexCount.signedCount * 24;
    chkmemAllocSiteTag(D_00713FF0, 0x643);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x644);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.pointer = (void *)mem;
    ((FlashBlock *)mem)->geometry.bytes = (u8 *)GeometryCloneBlock(((FlashBlock *)sourceObject)->geometry.bytes);
    FlashTexturedInitEntries(mem, workCursor);
    return mem;
}
// Frees a textured flash block: its geometry handle, then the block itself.
// FUN_0049E100
void FlashTexturedFreeBlock(u8 *input)
{
    GeometryBlockDestroy(((FlashBlock *)input)->geometry.bytes);
    jtbl_008873EC[0](((FlashBlock *)input)->allocation.pointer);
}
// Emits quads from the direction, length and width vectors (no centre) for one textured flash effect.
// FUN_0049E150
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
    void FlashTexturedEmitDirectionalQuads(u8 *effect)
    {
        u32 innerWord, outerWord, outerPacked, innerPacked;
        EffectVuVector innerColor, outerColor;
        EffectVuVector direction, widthVector, lengthVector;
        s32 firstFrame, count, index, fadeIn, fadeOut, initialAge, terminalAge, ageStep, recycle;
        u8 *state, *owner, *config;
        s32 *particle;
        f32 *particleData;
        s32 life;
        FlashVertex *vertices;
        u32 *colors;
        f32 acceleration, phase, factor, fullTurn, unit, zero, half, byteScale, normalization;
        const u32 *colorInput;
        u32 frame, lastFrame;
        s32 births;

        config = ((FlashEffect *)effect)->parameters;
        lastFrame = ((FlashParameters *)config)->lastFrame;
        frame = ((FlashEffect *)effect)->frame;
        if (lastFrame < frame && lastFrame != 0) return;
        state = ((FlashEffect *)effect)->state;
        particle = *(s32 **)state;
        owner = ((FlashBlock *)state)->geometry.bytes;
        count = ((FlashParameters *)config)->vertexCount.signedCount;
        life = ((FlashParameters *)config)->life;
        if (life == 0) return;
        if (((FlashParameters *)config)->unk84.reverse) {
            initialAge = life; terminalAge = 0; ageStep = -1;
            fadeIn = (s32)((1.0f - ((FlashParameters *)config)->fadeOut) * (f32)life);
            fadeOut = (s32)((1.0f - ((FlashParameters *)config)->fadeIn) * (f32)life);
        } else {
            initialAge = 0; terminalAge = life; ageStep = 1;
            fadeIn = (s32)(((FlashParameters *)config)->fadeIn * (f32)life);
            fadeOut = (s32)(((FlashParameters *)config)->fadeOut * (f32)life);
        }
        if (((FlashParameters *)config)->burst != 0 && frame == 0) {
            firstFrame = 1;
            births = count;
        } else {
            firstFrame = 0;
            births = ((FlashParameters *)config)->births;
        }
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry, 10);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        vertices = (FlashVertex*)((RpMorphTarget *)(u8*)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->morphTarget)->vertices;
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        colors = ((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->colors;
        zero = 0.0f;
        direction.lane[1] = zero;
        direction.lane[3] = zero;
        innerWord = ((FlashParameters *)config)->innerColor;
        colorInput = &innerWord;
        normalization = fGpffff8044;
        effectVuUnpackColor10(colorInput, normalization);
        effectVuStore10(&innerColor);
        outerWord = ((FlashParameters *)config)->outerColor;
        effectVuUnpackColor10(&outerWord, normalization);
        effectVuStore10(&outerColor);
        acceleration = ((FlashParameters *)config)->unk80;
        recycle = ((FlashParameters *)config)->recycle;
        index = 0;
        fullTurn = fGpffff80d0;
        unit = 1.0f;
        half = 0.5f;
        byteScale = 255.0f;
        for (; index < count; index++, particle += 6, vertices += 4, colors += 4) {
            s32 age = *particle;
            particleData = (f32 *)particle;
            if (age == -2) continue;
            if (age == -1) {
                if (births == 0) continue;
                particleData[2] = fullTurn * effMiscRandFloat(0);
    phase = ((FlashParameters *)config)->unk6C;
    factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
    particleData[3] = ((FlashParameters *)config)->unk68 * factor;
    phase = ((FlashParameters *)config)->unk74;
    factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
    particleData[4] = ((FlashParameters *)config)->unk70.scalar * factor;
    phase = ((FlashParameters *)config)->unk7C;
    factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
    particleData[1] = ((FlashParameters *)config)->unk78 * factor;
    phase = ((FlashParameters *)config)->unk64;
    factor = 0.0f + (unit - phase) + phase * effMiscRandFloat(0);
    particleData[5] = ((FlashParameters *)config)->unk60 * factor;

                if (firstFrame) {
                    *particle = effMiscRand(0) % (u32)life;
                    
                } else {
                    *particle = initialAge;
                }
                births--;
                continue;
            }
            if (age == terminalAge) {
                s32 vertex;
                for (vertex = 0; vertex < 4; vertex++) {
                    vertices[vertex].x = zero;
                    vertices[vertex].y = zero;
                    vertices[vertex].z = zero;
                    colors[vertex] = 0;
                }
                *particle = recycle ? -1 : -2;
            } else {
                f32 time = (f32)age;
                f32 distance;
                f32 fade;
                f32 sine, cosine;
                phase = particleData[2];
    if (acceleration < zero) {
        f32 maximum = half * (-particleData[1] / (half * acceleration));
        if (time > maximum) time = maximum;
    }
    distance = time * (0.0f + particleData[1] + half * (acceleration * time));
    distance += particleData[4];
    direction.lane[0] = cosf(phase);
    direction.lane[2] = sinf(phase);
    effectVuLoad10(&direction);
    __asm__ volatile(
        "vmove.xyzw $vf11, $vf10 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuScale10(particleData[3]);
    effectVuStore10(&lengthVector);
    __asm__ volatile(
        "vmove.xyzw $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuScale10(distance);
    __asm__ volatile(
        "vmove.xyzw $vf12, $vf10 \n"
        "vmove.xyzw $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    cosine = effectVuGetX10();
    sine = effectVuGetZ10();
    effectVuSetX10(sine);
    effectVuSetZ10(-cosine);
    effectVuScale10(particleData[5]);
    effectVuStore10(&widthVector);
    effectVuLoad10(&lengthVector);
    __asm__ volatile(
        "vadd.xyzw $vf10, $vf10, $vf12 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuLoad11(&widthVector);
    __asm__ volatile(
        "vadd.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10((EffectVuVector *)D_00713D10);
    vertices[0].x = D_00713D10[0];
    vertices[0].y = D_00713D14[0];
    vertices[0].z = D_00713D18[0];
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10((EffectVuVector *)D_00713D10);
    vertices[1].x = D_00713D10[0];
    vertices[1].y = D_00713D14[0];
    vertices[1].z = D_00713D18[0];
    effectVuLoad10(&lengthVector);
    __asm__ volatile(
        "vsub.xyz $vf10, $vf0, $vf10 \n"
        "vadd.xyzw $vf10, $vf10, $vf12 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuLoad11(&widthVector);
    __asm__ volatile(
        "vadd.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10((EffectVuVector *)D_00713D10);
    vertices[2].x = D_00713D10[0];
    vertices[2].y = D_00713D14[0];
    vertices[2].z = D_00713D18[0];
    __asm__ volatile(
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        : :  : "$vf10", "$vf11", "$vf12");
    effectVuStore10((EffectVuVector *)D_00713D10);
    vertices[3].x = D_00713D10[0];
    vertices[3].y = D_00713D14[0];
    vertices[3].z = D_00713D18[0];

                if (age < fadeIn) fade = (f32)age / (f32)fadeIn;
                else if (age > fadeOut) fade = (f32)(life - age) / (f32)(life - fadeOut);
                else fade = unit;
                effectVuLoad11((EffectVuVector *)D_00713CE0);
                effectVuScale11(fade);
                effectVuLoad10(&outerColor);
                __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni %0, $vf10 \n"
            "ppach %0, $zero, %0 \n"
            "ppacb %0, $zero, %0 \n"
            "sw %0, outerPacked \n"
            : "=&r"(transfer), "=m"(outerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
    }

                colors[0] = outerPacked;
                colors[1] = outerPacked;
                effectVuLoad10(&innerColor);
                __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
                {
        u32 transfer;
        __asm__ volatile(
            "qmtc2.ni %2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni %0, $vf10 \n"
            "ppach %0, $zero, %0 \n"
            "ppacb %0, $zero, %0 \n"
            "sw %0, innerPacked \n"
            : "=&r"(transfer), "=m"(innerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
    }

                colors[2] = innerPacked;
                colors[3] = innerPacked;
                *particle = age + ageStep;
            }
        }
        {
            u8 *geometry = (u8*)((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry;
            func_003c22f0(geometry);
            if (((EffGeometryBlock *)owner)->kind & 4) ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
        }
    }
#pragma pop
// Packs the centred-strip flash vertex colours from the inner and outer colour words.
// FUN_0049E920
void FlashCenteredStripPackColors(u8 *input)
{
    union
    {
        s32 w;
        u8 b[4];
    } packedColor;
    s32 parentColor;
    s32 sampleColor;
    s32 combinedColor;
    s32 sampledColor;
    u8 *state;
    u8 *config;
    u8 *geometryOwner;
    u32 frame;
    u32 lastFrame;
    f32 scale;

    state = ((FlashEffect *)input)->state;
    config = ((FlashEffect *)input)->parameters;
    geometryOwner = ((FlashBlock *)state)->geometry.bytes;
    frame = ((FlashEffect *)input)->frame;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    if ((lastFrame >= frame) || (lastFrame == 0))
    {
        s32 *pt;

        sampledColor = mdlEffectSamplePackedColor(config, config + 0x24, frame, lastFrame);
        parentColor = ((FlashEffect *)input)->color;
        pt = &parentColor;
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
        sampleColor = sampledColor;
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
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sampleColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        packedColor.w = *(s32 *)&combinedColor;
        if (packedColor.b[3] != 0xFF)
        {
            u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
            ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
        }
        else
        {
            packedColor.b[3] = 0xFE;
            {
                u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
                ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
            }
            packedColor.b[3] = 0xFF;
        }
        GeometryBlockSetFrameMatrixCombined(geometryOwner, input, input + 0x10, input + 0x20);
        if (((FlashParameters *)config)->geometryFlag != 0)
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind | 1;
        }
        else
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind & 0xFFFE;
        }
        {
            s32 resourceId = ((FlashParameters *)config)->resourceId;
            GeometryBlockBindResource(geometryOwner, resourceId);
        }
    }
}

/* measured: shares FlashRotatingUpdateGeometry's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see 0x0049b470). */
/* measured: same shape as FlashRotatingUpdateGeometry above; see that note. */
// Updates the centred-strip flash geometry: locks the model geometry and clears its vertex buffer before the rebuild.
// FUN_0049EAE0
#pragma opt_loop_invariants on
void FlashCenteredStripUpdateGeometry(u8 *input)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = ((FlashEffect *)input)->state;
    entry = *(s32 **)state;
    work = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)((FlashEffect *)input)->parameters)->vertexCount.signedCount;
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)work)->atomic)->geometry, 2);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    tex = (s32**)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry)->morphTarget;
    memset((s32)tex[5], 0, ((EffGeometryBlock *)work)->vertexCount * 0xC);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    model = (u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry;
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        ((RpGeometry *)model)->lockedSinceLastInst = ((RpGeometry *)model)->lockedSinceLastInst | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 10;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// Initialises the centred-strip entries from the config: per-entry geometry and offsets.
// FUN_0049EBD0
/* Earlier whole-chain trial: 320 -> 308 bytes, 38 normalized bytes changed; individual culprits remain below. */
#pragma opt_loop_invariants on
void FlashCenteredStripInitEntries(u8 *input, u8 *resource)
{
    u32 count;
    u8 *sourceObject;
    u8 *workCursor;
    u32 i;

    count = (u32)((FlashParameters *)resource)->vertexCount.signedCount;
    if (count != 0) {
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)((FlashBlock *)input)->geometry.bytes)->atomic)->geometry, 0xFF0);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        workCursor = *(u8 **)((u8*)((RpAtomic *)((EffGeometryBlock *)*(u8 **)(input + 4))->atomic)->geometry + 0x34);
        if (workCursor == NULL) {
            kAssertFail(D_00713FF0, 0x803);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                ((FlashUvQuad *)workCursor)->coordinates[0] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[1] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[2] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[3] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[4] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[5] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[6] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[7] = 1.0f;
            } else {
                ((FlashUvQuad *)workCursor)->coordinates[0] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[1] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[2] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[3] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[4] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[5] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[6] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[7] = 1.0f;
            }
            i++;
            workCursor += 0x20;
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        workCursor = *(u8 **)(input + 4);
        sourceObject = (u8*)((RpAtomic *)((EffGeometryBlock *)workCursor)->atomic)->geometry;
        func_003c22f0(sourceObject);
        if (((EffGeometryBlock *)workCursor)->kind & 4) {
            ((RpGeometry *)sourceObject)->lockedSinceLastInst |= 1;
        }
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// Allocates a centred-strip flash block: count * 40 entry bytes and a geometry handle.
// FUN_0049ED10
/* Earlier count/pointer trial: 288 -> 292 bytes; individual raw culprits remain below. */
void *FlashCenteredStripAllocBlock(u8 *input, void *resource)
{
    u32 size;
    u8 *mem;

    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    size = *(u32 *)(input + 0x38) * 40;
    chkmemAllocSiteTag(D_00713FF0, 0x7EC);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x7ED);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.word = (u32)mem;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    *(u32 *)(mem + 4) = (u32)GeometryCreateTableGrid(((FlashParameters *)input)->vertexCount.low, 2, 4, D_00713408, 0x4C);
    if (resource == NULL) {
        func_003c42b0(((EffGeometryBlock *)((FlashBlock *)mem)->geometry.bytes)->material, (void *)TnSlotObject(0x12));
    } else {
        GeometryBlockSetTextureFromHandle(((FlashBlock *)mem)->geometry.bytes, resource);
    }
    FlashCenteredStripInitEntries(mem, input);
    return mem;
}
// Allocates a centred-strip flash block that inherits its texture from a parent block.
// FUN_0049EE30
void *FlashCenteredStripAllocFromParent(u8 *input)
{
    u8 *sourceObject;
    u8 *workCursor;
    u32 size;
    u8 *mem;

    sourceObject = (void *)((FlashEffect *)input)->state;
    workCursor = (void *)((FlashEffect *)input)->parameters;
    size = (u32)((FlashParameters *)workCursor)->vertexCount.signedCount * 40;
    chkmemAllocSiteTag(D_00713FF0, 0x7EC);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x7ED);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.pointer = (void *)mem;
    ((FlashBlock *)mem)->geometry.bytes = (u8 *)GeometryCloneBlock(((FlashBlock *)sourceObject)->geometry.bytes);
    FlashCenteredStripInitEntries(mem, workCursor);
    return mem;
}
// Frees a centred-strip flash block: its geometry handle, then the block itself.
// FUN_0049EF00
void FlashCenteredStripFreeBlock(u8 *input)
{
    GeometryBlockDestroy(((FlashBlock *)input)->geometry.bytes);
    jtbl_008873EC[0](((FlashBlock *)input)->allocation.pointer);
}
// Emits centred-strip flash quads from the centre, direction and width vectors.
// FUN_0049EF50
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void FlashCenteredStripEmitQuads(u8 *effect)
{
    u32 innerWord, outerWord, outerPacked, innerPacked;
    EffectVuVector innerColor, outerColor;
    EffectVuVector center, direction, widthVector;
    s32 firstFrame, count, index, fadeIn, fadeOut, recycle;
    u8 *state, *owner, *config;
    s32 *particle;
    f32 *particleData;
    s32 life;
    FlashVertex *vertices;
    u32 *colors;
    f32 acceleration, phase, factor, endpoint, inclination, fullTurn, unit, zero, half, byteScale, normalization, cosine, radialPosition;
    const u32 *colorInput;
    u32 frame, lastFrame;
    s32 births;

    config = ((FlashEffect *)effect)->parameters;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    frame = ((FlashEffect *)effect)->frame;
    if (lastFrame < frame && lastFrame != 0) return;
    state = ((FlashEffect *)effect)->state;
    particle = *(s32 **)state;
    owner = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)config)->vertexCount.signedCount;
    life = ((FlashParameters *)config)->life;
    if (life == 0) return;
    
    if (((FlashParameters *)config)->burst != 0 && frame == 0) {
        firstFrame = 1;
        births = count;
    } else {
        firstFrame = 0;
        births = ((FlashParameters *)config)->births;
    }
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry, 10);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    vertices = (FlashVertex*)((RpMorphTarget *)(u8*)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->morphTarget)->vertices;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    colors = ((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->colors;
    zero = 0.0f;
    center.lane[1] = zero;
    center.lane[3] = zero;
    innerWord = ((FlashParameters *)config)->innerColor;
    colorInput = &innerWord;
    normalization = fGpffff8044;
    effectVuUnpackColor10(colorInput, normalization);
    effectVuStore10(&innerColor);
    outerWord = ((FlashParameters *)config)->outerColor;
    effectVuUnpackColor10(&outerWord, normalization);
    effectVuStore10(&outerColor);

fadeIn = (s32)(((FlashParameters *)config)->fadeIn * (f32)life);
fadeOut = (s32)(((FlashParameters *)config)->fadeOut * (f32)life);
    acceleration = ((FlashParameters *)config)->unkA0;
    recycle = ((FlashParameters *)config)->recycle;
    index = 0;
    fullTurn = fGpffff80d0;
    unit = 1.0f;
    half = 0.5f;
    byteScale = 255.0f;
    for (; index < count; index++, particle += 10, vertices += 4, colors += 4) {
        s32 age = *particle;
        particleData = (f32 *)particle;
        if (age == -2) continue;
        if (age == -1) {
            if (births == 0) continue;
            particleData[1] = fullTurn * effMiscRandFloat(0);
cosine = ((FlashParameters *)config)->unk6C;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
cosine = ((FlashParameters *)config)->unk68 * factor;
inclination = ((FlashParameters *)config)->unk74;
 factor = 0.0f + (unit - inclination) + inclination * effMiscRandFloat(0);
 endpoint = ((FlashParameters *)config)->unk70.scalar * factor;
particleData[3] = cosine;
particleData[4] = (endpoint - cosine) / (f32)life;
cosine = ((FlashParameters *)config)->unk7C;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
cosine = ((FlashParameters *)config)->unk78 * factor;
inclination = ((FlashParameters *)config)->unk84.scalar;
 factor = 0.0f + (unit - inclination) + inclination * effMiscRandFloat(0);
 endpoint = ((FlashParameters *)config)->unk80 * factor;
particleData[5] = cosine;
particleData[6] = (endpoint - cosine) / (f32)life;
cosine = ((FlashParameters *)config)->unk8C;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
cosine = ((FlashParameters *)config)->unk88 * factor;
inclination = ((FlashParameters *)config)->unk94.scalar;
 factor = 0.0f + (unit - inclination) + inclination * effMiscRandFloat(0);
 endpoint = ((FlashParameters *)config)->unk90 * factor;
particleData[7] = cosine;
particleData[8] = (endpoint - cosine) / (f32)life;
cosine = ((FlashParameters *)config)->unk64;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
particleData[9] = ((FlashParameters *)config)->unk60 * factor;
cosine = ((FlashParameters *)config)->unk9C;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
particleData[2] = ((FlashParameters *)config)->unk98 * factor;

if (firstFrame) {
    f32 remainder = (f32)(u32)(effMiscRand(0) % (u32)life);
    particleData[3] = particleData[3] + particleData[4] * remainder;
    particleData[5] = particleData[5] + particleData[6] * remainder;
    particleData[7] = particleData[7] + particleData[8] * remainder;
    *particle = (s32)remainder;
} else { *particle = 0; }

            births--;
            continue;
        }
        if (age >= life) {
            s32 vertex;
            for (vertex = 0; vertex < 4; vertex++) {
                vertices[vertex].x = zero;
                vertices[vertex].y = zero;
                vertices[vertex].z = zero;
                colors[vertex] = 0;
            }
            *particle = recycle ? -1 : -2;
        } else {
            f32 time = (f32)age;
            f32 fade;
            f32 sine;
            factor = 0.0f + particleData[2] + half * (acceleration * time);
phase = time * factor;
phase += particleData[1];
inclination = particleData[7];
radialPosition = particleData[5];
cosine = cosf(phase);
sine = sinf(phase);
center.lane[0] = cosine * radialPosition;
center.lane[2] = sine * radialPosition;
direction.lane[0] = cosine * inclination;
direction.lane[1] = unit - inclination;
direction.lane[2] = sine * inclination;
effectVuLoad10(&direction);
__asm__ volatile(
    "vmul.xyz $vf2, $vf10, $vf10 \n"
    "vmulax.w $ACC, $vf0, $vf2x \n"
    "vmadday.w $ACC, $vf0, $vf2y \n"
    "vmaddz.w $vf2, $vf0, $vf2z \n"
    "vrsqrt $Q, $vf0w, $vf2w \n"
    "vwaitq \n"
    "vmulq.xyz $vf10, $vf10, $Q \n"
    "vmove.xyzw $vf12, $vf10 \n"
    : :  : "$vf2", "$vf10", "$vf12", "ACC", "Q");
direction.lane[0] = sine;
direction.lane[1] = zero;
direction.lane[2] = -cosine;
effectVuLoad10(&direction);
effectVuScale10(particleData[9]);
effectVuStore10(&widthVector);
effectVuLoad10(&center);
effectVuLoad11(&widthVector);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[2].x = D_00713D10[0];
vertices[2].y = D_00713D14[0];
vertices[2].z = D_00713D18[0];
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11 \n"
    "vsub.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[3].x = D_00713D10[0];
vertices[3].y = D_00713D14[0];
vertices[3].z = D_00713D18[0];
__asm__ volatile(
    "vmove.xyzw $vf11, $vf12 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuScale11(particleData[3]);
effectVuLoad10(&center);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuLoad11(&widthVector);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[0].x = D_00713D10[0];
vertices[0].y = D_00713D14[0];
vertices[0].z = D_00713D18[0];
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11 \n"
    "vsub.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[1].x = D_00713D10[0];
vertices[1].y = D_00713D14[0];
vertices[1].z = D_00713D18[0];
particleData[3] = particleData[3] + particleData[4];
particleData[7] = particleData[7] + particleData[8];
particleData[5] = particleData[5] + particleData[6];

            if (age < fadeIn) fade = (f32)age / (f32)fadeIn;
            else if (age > fadeOut) fade = (f32)(life - age) / (f32)(life - fadeOut);
            else fade = unit;
            effectVuLoad11((EffectVuVector *)D_00713CE0);
            effectVuScale11(fade);
            effectVuLoad10(&outerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
    u32 transfer;
    __asm__ volatile(
        "qmtc2.ni %2, $vf2 \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "vftoi0.xyzw $vf10, $vf10 \n"
        "qmfc2.ni %0, $vf10 \n"
        "ppach %0, $zero, %0 \n"
        "ppacb %0, $zero, %0 \n"
        "sw %0, outerPacked \n"
        : "=&r"(transfer), "=m"(outerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
}

            colors[0] = outerPacked;
            colors[1] = outerPacked;
            effectVuLoad10(&innerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
    u32 transfer;
    __asm__ volatile(
        "qmtc2.ni %2, $vf2 \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "vftoi0.xyzw $vf10, $vf10 \n"
        "qmfc2.ni %0, $vf10 \n"
        "ppach %0, $zero, %0 \n"
        "ppacb %0, $zero, %0 \n"
        "sw %0, innerPacked \n"
        : "=&r"(transfer), "=m"(innerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
}

            colors[2] = innerPacked;
            colors[3] = innerPacked;
            *particle = age + 1;
        }
    }
    {
        u8 *geometry = (u8*)((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry;
        func_003c22f0(geometry);
        if (((EffGeometryBlock *)owner)->kind & 4) ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
    }
}
#pragma pop
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// Packs the box flash vertex colours from the inner and outer colour words.
// FUN_0049F820
void FlashBoxPackColors(u8 *input)
{
    union
    {
        s32 w;
        u8 b[4];
    } packedColor;
    s32 parentColor;
    s32 sampleColor;
    s32 combinedColor;
    s32 sampledColor;
    u8 *state;
    u8 *config;
    u8 *geometryOwner;
    u32 frame;
    u32 lastFrame;
    f32 scale;

    state = ((FlashEffect *)input)->state;
    config = ((FlashEffect *)input)->parameters;
    geometryOwner = ((FlashBlock *)state)->geometry.bytes;
    frame = ((FlashEffect *)input)->frame;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    if ((lastFrame >= frame) || (lastFrame == 0))
    {
        s32 *pt;

        sampledColor = mdlEffectSamplePackedColor(config, config + 0x24, frame, lastFrame);
        parentColor = ((FlashEffect *)input)->color;
        pt = &parentColor;
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
        sampleColor = sampledColor;
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
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sampleColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        packedColor.w = *(s32 *)&combinedColor;
        if (packedColor.b[3] != 0xFF)
        {
            u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
            ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
        }
        else
        {
            packedColor.b[3] = 0xFE;
            {
                u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
                ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
            }
            packedColor.b[3] = 0xFF;
        }
        GeometryBlockSetFrameMatrixCombined(geometryOwner, input, input + 0x10, input + 0x20);
        if (((FlashParameters *)config)->geometryFlag != 0)
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind | 1;
        }
        else
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind & 0xFFFE;
        }
        {
            s32 resourceId = ((FlashParameters *)config)->resourceId;
            GeometryBlockBindResource(geometryOwner, resourceId);
        }
    }
}

/* measured: shares FlashRotatingUpdateGeometry's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see 0x0049b470). */
/* measured: same shape as FlashRotatingUpdateGeometry above; see that note. */
// Updates the box flash geometry: locks the model geometry and clears its vertex buffer before the rebuild.
// FUN_0049F9E0
#pragma opt_loop_invariants on
void FlashBoxUpdateGeometry(u8 *input)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = ((FlashEffect *)input)->state;
    entry = *(s32 **)state;
    work = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)((FlashEffect *)input)->parameters)->vertexCount.signedCount;
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)work)->atomic)->geometry, 2);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    tex = (s32**)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry)->morphTarget;
    memset((s32)tex[5], 0, ((EffGeometryBlock *)work)->vertexCount * 0xC);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    model = (u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry;
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        ((RpGeometry *)model)->lockedSinceLastInst = ((RpGeometry *)model)->lockedSinceLastInst | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 11;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
// Allocates a box flash block: count * 44 entry bytes and a geometry handle.
// FUN_0049FAD0
/* Keep the pointer-bit and halfword-count accesses below: typed replacement
 * changed this constructor's instruction stream despite the proven layout. */
void *FlashBoxAllocBlock(u8 *input)
{
    u32 size;
    u8 *mem;

    size = (u32)((FlashParameters *)input)->vertexCount.signedCount * 44;
    chkmemAllocSiteTag(D_00713FF0, 0x98E);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0x98F);
    }
    ((FlashBlock *)mem)->particles.word = (u32)(mem + 0x10);
    ((FlashBlock *)mem)->allocation.pointer = (void *)mem;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    ((FlashBlock *)mem)->geometry.bytes = (u8 *)GeometryCreateTableGrid(*(u16 *)(input + 0x38), 3, 5, D_007133A0, 0x48);
    return mem;
}
// Frees a box flash block: its geometry handle, then the block itself.
// FUN_0049FBA0
void FlashBoxFreeBlock(u8 *input)
{
    GeometryBlockDestroy(((FlashBlock *)input)->geometry.bytes);
    jtbl_008873EC[0](((FlashBlock *)input)->allocation.pointer);
}
// Emits box flash quads from the centre, direction, length and width vectors.
// FUN_0049FBF0
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
void FlashBoxEmitQuads(u8 *effect)
{
    u32 innerWord, outerWord, outerPacked, innerPacked;
    EffectVuVector innerColor, outerColor;
    EffectVuVector center, direction, lengthVector, widthVector;
    s32 firstFrame, count, index, fadeIn, fadeOut, recycle;
    u8 *state, *owner, *config;
    s32 *particle;
    f32 *particleData;
    s32 life;
    FlashVertex *vertices;
    u32 *colors;
    f32 acceleration, phase, factor, endpoint, inclination, fullTurn, unit, zero, half, byteScale, normalization, cosine, radialPosition;
    const u32 *colorInput;
    u32 frame, lastFrame;
    s32 births;

    config = ((FlashEffect *)effect)->parameters;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    frame = ((FlashEffect *)effect)->frame;
    if (lastFrame < frame && lastFrame != 0) return;
    state = ((FlashEffect *)effect)->state;
    particle = *(s32 **)state;
    owner = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)config)->vertexCount.signedCount;
    life = ((FlashParameters *)config)->life;
    if (life == 0) return;
    
    if (((FlashParameters *)config)->burst != 0 && frame == 0) {
        firstFrame = 1;
        births = count;
    } else {
        firstFrame = 0;
        births = ((FlashParameters *)config)->births;
    }
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry, 10);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    vertices = (FlashVertex*)((RpMorphTarget *)(u8*)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->morphTarget)->vertices;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    colors = ((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->colors;
    zero = 0.0f;
    center.lane[1] = zero;
    center.lane[3] = zero;
    innerWord = ((FlashParameters *)config)->innerColor & 0x00ffffff;
    colorInput = &innerWord;
    normalization = fGpffff8044;
    effectVuUnpackColor10(colorInput, normalization);
    effectVuStore10(&innerColor);
    outerWord = ((FlashParameters *)config)->outerColor & 0x00ffffff;
    effectVuUnpackColor10(&outerWord, normalization);
    effectVuStore10(&outerColor);

fadeIn = (s32)(((FlashParameters *)config)->fadeIn * (f32)life);
fadeOut = (s32)(((FlashParameters *)config)->fadeOut * (f32)life);
    acceleration = ((FlashParameters *)config)->unkA4;
    recycle = ((FlashParameters *)config)->recycle;
    index = 0;
    fullTurn = fGpffff80d0;
    unit = 1.0f;
    half = 0.5f;
    byteScale = 255.0f;
    for (; index < count; index++, particle += 11, vertices += 5, colors += 5) {
        s32 age = *particle;
        particleData = (f32 *)particle;
        if (age == -2) continue;
        if (age == -1) {
            if (births == 0) continue;
            particleData[1] = fullTurn * effMiscRandFloat(0);
cosine = ((FlashParameters *)config)->unk70.scalar;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
cosine = ((FlashParameters *)config)->unk6C * factor;
inclination = ((FlashParameters *)config)->unk78;
 factor = 0.0f + (unit - inclination) + inclination * effMiscRandFloat(0);
 endpoint = ((FlashParameters *)config)->unk74 * factor;
particleData[3] = cosine;
particleData[4] = (endpoint - cosine) / (f32)life;
cosine = ((FlashParameters *)config)->unk80;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
cosine = ((FlashParameters *)config)->unk7C * factor;
inclination = ((FlashParameters *)config)->unk88;
 factor = 0.0f + (unit - inclination) + inclination * effMiscRandFloat(0);
 endpoint = ((FlashParameters *)config)->unk84.scalar * factor;
particleData[5] = cosine;
particleData[6] = (endpoint - cosine) / (f32)life;
cosine = ((FlashParameters *)config)->unk90;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
cosine = ((FlashParameters *)config)->unk8C * factor;
inclination = ((FlashParameters *)config)->unk98;
 factor = 0.0f + (unit - inclination) + inclination * effMiscRandFloat(0);
 endpoint = ((FlashParameters *)config)->unk94.scalar * factor;
particleData[7] = cosine;
particleData[8] = (endpoint - cosine) / (f32)life;
cosine = ((FlashParameters *)config)->unk68;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
particleData[9] = ((FlashParameters *)config)->unk60 * factor;
particleData[10] = ((FlashParameters *)config)->unk64 * factor;
cosine = ((FlashParameters *)config)->unkA0;
factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
particleData[2] = ((FlashParameters *)config)->unk9C * factor;

if (firstFrame) {
    f32 remainder = (f32)(u32)(effMiscRand(0) % (u32)life);
    particleData[3] = particleData[3] + particleData[4] * remainder;
    particleData[5] = particleData[5] + particleData[6] * remainder;
    particleData[7] = particleData[7] + particleData[8] * remainder;
    *particle = (s32)remainder;
} else { *particle = 0; }

            births--;
            continue;
        }
        if (age >= life) {
            s32 vertex;
            for (vertex = 0; vertex < 5; vertex++) {
                vertices[vertex].x = zero;
                vertices[vertex].y = zero;
                vertices[vertex].z = zero;
                colors[vertex] = 0;
            }
            *particle = recycle ? -1 : -2;
        } else {
            f32 time = (f32)age;
            f32 fade;
            f32 sine;
            factor = 0.0f + particleData[2] + half * (acceleration * time);
phase = time * factor;
phase += particleData[1];
inclination = particleData[7];
radialPosition = particleData[5];
cosine = cosf(phase);
sine = sinf(phase);
center.lane[0] = cosine * radialPosition;
center.lane[2] = sine * radialPosition;
direction.lane[0] = cosine * inclination;
direction.lane[1] = unit - inclination;
direction.lane[2] = sine * inclination;
effectVuLoad10(&direction);
__asm__ volatile(
    "vmul.xyz $vf2, $vf10, $vf10 \n"
    "vmulax.w $ACC, $vf0, $vf2x \n"
    "vmadday.w $ACC, $vf0, $vf2y \n"
    "vmaddz.w $vf2, $vf0, $vf2z \n"
    "vrsqrt $Q, $vf0w, $vf2w \n"
    "vwaitq \n"
    "vmulq.xyz $vf10, $vf10, $Q \n"
    "vmove.xyzw $vf12, $vf10 \n"
    : :  : "$vf2", "$vf10", "$vf12", "ACC", "Q");
direction.lane[0] = sine;
direction.lane[1] = zero;
direction.lane[2] = -cosine;
effectVuLoad10(&direction);
__asm__ volatile(
    "vmove.xyzw $vf11, $vf10 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuScale10(particleData[9]);
effectVuScale11(particleData[10]);
effectVuStore10(&lengthVector);
effectVuStore11(&widthVector);
effectVuLoad10(&center);
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[3].x = D_00713D10[0];
vertices[3].y = D_00713D14[0];
vertices[3].z = D_00713D18[0];
effectVuLoad11(&lengthVector);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[2].x = D_00713D10[0];
vertices[2].y = D_00713D14[0];
vertices[2].z = D_00713D18[0];
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11 \n"
    "vsub.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[4].x = D_00713D10[0];
vertices[4].y = D_00713D14[0];
vertices[4].z = D_00713D18[0];
__asm__ volatile(
    "vmove.xyzw $vf11, $vf12 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuScale11(particleData[3]);
effectVuLoad10(&center);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuLoad11(&widthVector);
__asm__ volatile(
    "vadd.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[0].x = D_00713D10[0];
vertices[0].y = D_00713D14[0];
vertices[0].z = D_00713D18[0];
__asm__ volatile(
    "vsub.xyzw $vf10, $vf10, $vf11 \n"
    "vsub.xyzw $vf10, $vf10, $vf11 \n"
    : :  : "$vf10", "$vf11", "$vf12");
effectVuStore10((EffectVuVector *)D_00713D10);
vertices[1].x = D_00713D10[0];
vertices[1].y = D_00713D14[0];
vertices[1].z = D_00713D18[0];
particleData[3] = particleData[3] + particleData[4];
particleData[7] = particleData[7] + particleData[8];
particleData[5] = particleData[5] + particleData[6];

            if (age < fadeIn) fade = (f32)age / (f32)fadeIn;
            else if (age > fadeOut) fade = (f32)(life - age) / (f32)(life - fadeOut);
            else fade = unit;
            effectVuLoad11((EffectVuVector *)D_00713CE0);
            effectVuScale11(fade);
            effectVuLoad10(&outerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
    u32 transfer;
    __asm__ volatile(
        "qmtc2.ni %2, $vf2 \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "vftoi0.xyzw $vf10, $vf10 \n"
        "qmfc2.ni %0, $vf10 \n"
        "ppach %0, $zero, %0 \n"
        "ppacb %0, $zero, %0 \n"
        "sw %0, outerPacked \n"
        : "=&r"(transfer), "=m"(outerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
}

            colors[0] = outerPacked;
            colors[1] = outerPacked;
            effectVuLoad10(&innerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
    u32 transfer;
    __asm__ volatile(
        "qmtc2.ni %2, $vf2 \n"
        "vmulx.xyzw $vf10, $vf10, $vf2x \n"
        "vftoi0.xyzw $vf10, $vf10 \n"
        "qmfc2.ni %0, $vf10 \n"
        "ppach %0, $zero, %0 \n"
        "ppacb %0, $zero, %0 \n"
        "sw %0, innerPacked \n"
        : "=&r"(transfer), "=m"(innerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
}

            {
                u32 innerValue = innerPacked;
                u32 alpha;
                if ((index & 1) != 0) {
                    colors[3] = innerValue | 0xff000000;
                    alpha = ((u32)(128.0f * fade)) << 24;
                    colors[2] = alpha;
                    colors[4] = alpha;
                } else {
                    colors[3] = innerValue | 0x80000000;
                    alpha = ((u32)(byteScale * fade)) << 24;
                    colors[2] = alpha;
                    colors[4] = alpha;
                }
            }
            *particle = age + 1;
        }
    }
    {
        u8 *geometry = (u8*)((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry;
        func_003c22f0(geometry);
        if (((EffGeometryBlock *)owner)->kind & 4) ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
    }
}
#pragma pop
/* measured: retail's else-branch restores 0xFF to the alpha byte after the
   color copy. That store is load-bearing -- dropping it measures nd 32 -- and a
   plain sp4C.b[3] = 0xFF; keeps it, because the union is already memory-resident
   where the copy takes its address. An earlier wave wrote it through a volatile
   byte access, which was never necessary. */
// Packs the aged-box flash vertex colours from the inner and outer colour words.
// FUN_004A05F0
void FlashAgedBoxPackColors(u8 *input)
{
    union
    {
        s32 w;
        u8 b[4];
    } packedColor;
    s32 parentColor;
    s32 sampleColor;
    s32 combinedColor;
    s32 sampledColor;
    u8 *state;
    u8 *config;
    u8 *geometryOwner;
    u32 frame;
    u32 lastFrame;
    f32 scale;

    state = ((FlashEffect *)input)->state;
    config = ((FlashEffect *)input)->parameters;
    geometryOwner = ((FlashBlock *)state)->geometry.bytes;
    frame = ((FlashEffect *)input)->frame;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    if ((lastFrame >= frame) || (lastFrame == 0))
    {
        s32 *pt;

        sampledColor = mdlEffectSamplePackedColor(config, config + 0x24, frame, lastFrame);
        parentColor = ((FlashEffect *)input)->color;
        pt = &parentColor;
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
        sampleColor = sampledColor;
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
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sampleColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        packedColor.w = *(s32 *)&combinedColor;
        if (packedColor.b[3] != 0xFF)
        {
            u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
            ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
        }
        else
        {
            packedColor.b[3] = 0xFE;
            {
                u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
                ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
            }
            packedColor.b[3] = 0xFF;
        }
        GeometryBlockSetFrameMatrixCombined(geometryOwner, input, input + 0x10, input + 0x20);
        if (((FlashParameters *)config)->geometryFlag != 0)
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind | 1;
        }
        else
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind & 0xFFFE;
        }
        {
            s32 resourceId = ((FlashParameters *)config)->resourceId;
            GeometryBlockBindResource(geometryOwner, resourceId);
        }
    }
}

/* measured: shares FlashRotatingUpdateGeometry's recorded floor - the fill loop matches
   retail with opt_loop_invariants, but the func_0043f9c8 four-load chain
   splits around the size computation (8-word residual). schedule pragmas
   measured, no help (see 0x0049b470). */
/* measured: same shape as FlashRotatingUpdateGeometry above; see that note. */
// Updates the aged-box flash geometry: locks the model geometry and clears its vertex buffer before the rebuild.
// FUN_004A07B0
#pragma opt_loop_invariants on
void FlashAgedBoxUpdateGeometry(u8 *input)
{
    u8 *state;
    u8 *work;
    u8 *model;
    s32 **tex;
    s32 *entry;
    s32 count;
    s32 i;
    s32 value;

    state = ((FlashEffect *)input)->state;
    entry = *(s32 **)state;
    work = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)((FlashEffect *)input)->parameters)->vertexCount.signedCount;
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)work)->atomic)->geometry, 2);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    tex = (s32**)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry)->morphTarget;
    memset((s32)tex[5], 0, ((EffGeometryBlock *)work)->vertexCount * 0xC);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    model = (u8*)((RpAtomic *)*(u8 **)(work + 0x10))->geometry;
    func_003c22f0(model);
    if (*(u16 *)work & 4) {
        ((RpGeometry *)model)->lockedSinceLastInst = ((RpGeometry *)model)->lockedSinceLastInst | 1;
    }
    i = 0;
    value = -1;
    while (i < count) {
        *entry = value;
        entry += 8;
        i++;
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */
/* measured: without opt_loop_invariants mwcc rematerializes the 0.5f/1.0f
 * constants inside the loop instead of hoisting them to the preheader
 * (14+ differing words); with it the loop matches. */
// Initialises the aged-box entries from the config: per-entry geometry and offsets.
// FUN_004A08A0
/* Earlier whole-chain trial: 320 -> 308 bytes, 38 normalized bytes changed; individual culprits remain below. */
#pragma opt_loop_invariants on
void FlashAgedBoxInitEntries(u8 *input, u8 *resource)
{
    u32 count;
    u8 *sourceObject;
    u8 *workCursor;
    u32 i;

    count = (u32)((FlashParameters *)resource)->vertexCount.signedCount;
    if (count != 0) {
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)((FlashBlock *)input)->geometry.bytes)->atomic)->geometry, 0xFF0);
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        workCursor = *(u8 **)((u8*)((RpAtomic *)((EffGeometryBlock *)*(u8 **)(input + 4))->atomic)->geometry + 0x34);
        if (workCursor == NULL) {
            kAssertFail(D_00713FF0, 0xB08);
        }
        i = 0;
        while (i < count) {
            if (i & 1) {
                ((FlashUvQuad *)workCursor)->coordinates[0] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[1] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[2] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[3] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[4] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[5] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[6] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[7] = 1.0f;
            } else {
                ((FlashUvQuad *)workCursor)->coordinates[0] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[1] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[2] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[3] = 0.0f;
                ((FlashUvQuad *)workCursor)->coordinates[4] = 0.5f;
                ((FlashUvQuad *)workCursor)->coordinates[5] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[6] = 1.0f;
                ((FlashUvQuad *)workCursor)->coordinates[7] = 1.0f;
            }
            i++;
            workCursor += 0x20;
        }
        /* measured: this access-site member conversion makes the owning function MISMATCH. */
        workCursor = *(u8 **)(input + 4);
        sourceObject = (u8*)((RpAtomic *)((EffGeometryBlock *)workCursor)->atomic)->geometry;
        func_003c22f0(sourceObject);
        if (((EffGeometryBlock *)workCursor)->kind & 4) {
            ((RpGeometry *)sourceObject)->lockedSinceLastInst |= 1;
        }
    }
}
#pragma opt_loop_invariants off
/* measured: paired with the `on` above; scoped so the rest of the file
   keeps b210 stock -O2 behaviour. */

// Allocates an aged-box flash block: count * 32 entry bytes and a geometry handle.
// FUN_004A09E0
/* Earlier count/pointer trial: 272 -> 284 bytes; individual raw culprits remain below. */
void *FlashAgedBoxAllocBlock(u8 *input, void *resource)
{
    u32 size;
    u8 *mem;

    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    size = *(u32 *)(input + 0x38) * 32;
    chkmemAllocSiteTag(D_00713FF0, 0xAF1);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0xAF2);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.word = (u32)mem;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    *(u32 *)(mem + 4) = (u32)GeometryCreateTableGrid(((FlashParameters *)input)->vertexCount.low, 2, 4, D_00713408, 0x4C);
    if (resource == NULL) {
        func_003c42b0(((EffGeometryBlock *)((FlashBlock *)mem)->geometry.bytes)->material, (void *)TnSlotObject(0x13));
    } else {
        GeometryBlockSetTextureFromHandle(((FlashBlock *)mem)->geometry.bytes, resource);
    }
    FlashAgedBoxInitEntries(mem, input);
    return mem;
}
// Allocates an aged-box flash block that inherits its texture from a parent block.
// FUN_004A0AF0
void *FlashAgedBoxAllocFromParent(u8 *input)
{
    u8 *sourceObject;
    u8 *workCursor;
    u32 size;
    u8 *mem;

    sourceObject = (void *)((FlashEffect *)input)->state;
    workCursor = (void *)((FlashEffect *)input)->parameters;
    size = (u32)((FlashParameters *)workCursor)->vertexCount.signedCount * 32;
    chkmemAllocSiteTag(D_00713FF0, 0xAF1);
    mem = jtbl_008873E8[0](size + 0x10, 0x40000);
    if (mem == NULL) {
        kAssertFail(D_00713FF0, 0xAF2);
    }
    ((FlashBlock *)mem)->particles.bytes = mem + 0x10;
    ((FlashBlock *)mem)->allocation.pointer = (void *)mem;
    ((FlashBlock *)mem)->geometry.bytes = (u8 *)GeometryCloneBlock(((FlashBlock *)sourceObject)->geometry.bytes);
    FlashAgedBoxInitEntries(mem, workCursor);
    return mem;
}




// Frees an aged-box flash block: its geometry handle, then the block itself.
// FUN_004A0BB0
void FlashAgedBoxFreeBlock(u8 *input) {
    GeometryBlockDestroy((s32)((FlashBlock *)input)->geometry.bytes);
    D_008873ec[0](((FlashBlock *)input)->allocation.pointer);
}

/* The length scale reaches VF2 as `nop; qmtc2.ni` on a C load of the
 * field's bits, as in FlashRadialEmitQuads. Loading it inside the asm block (`lw %0`)
 * made the asm output a long-lived virtual and swapped $v0/$v1 across the
 * whole direction block (16 words). */
#pragma push
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
// Emits aged-box flash quads from the direction, width and length vectors, with age and fade terms.
// FUN_004A0C00
void FlashAgedBoxEmitQuads(u8 *effect)
{
    u32 innerWord, outerWord, outerPacked, innerPacked;
    EffectVuVector innerColor, outerColor;
    EffectVuVector direction, widthVector, lengthVector;
    s32 firstFrame, count, index, fadeIn, fadeOut, initialAge, terminalAge, ageStep, recycle;
    u8 *state, *owner, *config;
    /* 004a09e0/004a0af0 allocate 0x20 bytes per particle; 004a07b0
     * advances eight words. Retail loads the age as a word and the
     * seven remaining fields as floats. Keep those types in one record. */
    typedef struct FlashInclinedParticle {
        s32 age;
        f32 velocity;
        f32 phase;
        f32 length;
        f32 radius;
        f32 radiusStep;
        f32 inclination;
        f32 width;
    } FlashInclinedParticle;
    typedef char FlashInclinedParticleExtent[sizeof(FlashInclinedParticle) == 0x20 ? 1 : -1];
    FlashInclinedParticle *particle;
    s32 life;
    FlashVertex *vertices;
    u32 *colors;
    f32 acceleration, distance, phase, inclination, fullTurn, unit, zero, half, byteScale, normalization, radius, cosine, factor, endpoint;
    const u32 *colorInput;
    u32 frame, lastFrame;
    s32 births;

    config = ((FlashEffect *)effect)->parameters;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    frame = ((FlashEffect *)effect)->frame;
    if (lastFrame < frame && lastFrame != 0) return;
    state = ((FlashEffect *)effect)->state;
    particle = *(FlashInclinedParticle **)state;
    owner = ((FlashBlock *)state)->geometry.bytes;
    count = ((FlashParameters *)config)->vertexCount.signedCount;
    life = ((FlashParameters *)config)->life;
    if (life == 0) return;
    if (((FlashParameters *)config)->unk94.reverse) {
        initialAge = life; terminalAge = 0; ageStep = -1;
        fadeIn = (s32)((1.0f - ((FlashParameters *)config)->fadeOut) * (f32)life);
        fadeOut = (s32)((1.0f - ((FlashParameters *)config)->fadeIn) * (f32)life);
    } else {
        initialAge = 0; terminalAge = life; ageStep = 1;
        fadeIn = (s32)(((FlashParameters *)config)->fadeIn * (f32)life);
        fadeOut = (s32)(((FlashParameters *)config)->fadeOut * (f32)life);
    }
    if (((FlashParameters *)config)->burst != 0 && frame == 0) {
        firstFrame = 1;
        births = count;
    } else {
        firstFrame = 0;
        births = ((FlashParameters *)config)->births;
    }
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry, 10);
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    vertices = (FlashVertex*)((RpMorphTarget *)(u8*)((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->morphTarget)->vertices;
    /* measured: this access-site member conversion makes the owning function MISMATCH. */
    colors = ((RpGeometry *)(u8*)((RpAtomic *)*(u8 **)(owner + 0x10))->geometry)->colors;
    zero = 0.0f;
    direction.lane[1] = zero;
    direction.lane[3] = zero;
    innerWord = ((FlashParameters *)config)->innerColor;
    colorInput = &innerWord;
    normalization = fGpffff8044;
    effectVuUnpackColor10(colorInput, normalization);
    effectVuStore10(&innerColor);
    outerWord = ((FlashParameters *)config)->outerColor;
    effectVuUnpackColor10(&outerWord, normalization);
    effectVuStore10(&outerColor);
    acceleration = ((FlashParameters *)config)->unk90;
    recycle = ((FlashParameters *)config)->recycle;
    index = 0;
    fullTurn = fGpffff80d0;
    unit = 1.0f;
    half = 0.5f;
    byteScale = 255.0f;
    for (; index < count; index++, particle++, vertices += 4, colors += 4) {
        s32 age = particle->age;
        if (age == -2) continue;
        if (age == -1) {
            if (births == 0) continue;
            particle->phase = fullTurn * effMiscRandFloat(0);
            cosine = ((FlashParameters *)config)->unk6C;
            factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
            particle->length = ((FlashParameters *)config)->unk68 * factor;
            cosine = ((FlashParameters *)config)->unk74;
            factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
            cosine = ((FlashParameters *)config)->unk70.scalar * factor;
            radius = ((FlashParameters *)config)->unk7C;
            factor = 0.0f + (unit - radius) + radius * effMiscRandFloat(0);
            endpoint = ((FlashParameters *)config)->unk78 * factor;
            particle->radius = cosine;
            particle->radiusStep = (endpoint - cosine) / (f32)life;
            cosine = ((FlashParameters *)config)->unk8C;
            factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
            particle->velocity = ((FlashParameters *)config)->unk88 * factor;
            cosine = ((FlashParameters *)config)->unk64;
            factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
            particle->width = ((FlashParameters *)config)->unk60 * factor;
            cosine = ((FlashParameters *)config)->unk84.scalar;
            factor = 0.0f + (unit - cosine) + cosine * effMiscRandFloat(0);
            particle->inclination = ((FlashParameters *)config)->unk80 * factor;
            if (firstFrame) {
                particle->age = effMiscRand(0) % (u32)life;

            } else {
                particle->age = initialAge;
            }
            births--;
            continue;
        }
        if (age == terminalAge) {
            s32 vertex;
            for (vertex = 0; vertex < 4; vertex++) {
                vertices[vertex].x = zero;
                vertices[vertex].y = zero;
                vertices[vertex].z = zero;
                colors[vertex] = 0;
            }
            particle->age = recycle ? -1 : -2;
        } else {
            EffectVuVector *scratch;
            f32 time = (f32)age;
            f32 fade;
            f32 sine;
            phase = particle->phase;
            if (acceleration < zero) {
                f32 maximum = half * (-particle->velocity / (half * acceleration));
                if (time > maximum) time = maximum;
            }
            distance = time * (0.0f + particle->velocity + half * (acceleration * time));
            radius = 0.0f + particle->radius + particle->radiusStep * time;
            inclination = particle->inclination;
            cosine = cosf(phase);
            sine = sinf(phase);
            direction.lane[0] = cosine * inclination;
            direction.lane[1] = unit - inclination;
            direction.lane[2] = sine * inclination;
            scratch = &direction;
            effectVuLoad10(scratch);
            __asm__ volatile("vmove.xyzw $vf11, $vf10" : : : "$vf11");
            __asm__ volatile("nop\nqmtc2.ni %0, $vf2\nvmulx.xyzw $vf10, $vf10, $vf2x"
                : : "r"(*(u32 *)&particle->length) : "$vf2", "$vf10");
            effectVuStore10(&lengthVector);
            __asm__ volatile(
                "vmove.xyzw $vf10, $vf11 \n"
                : :  : "$vf10", "$vf11", "$vf12");
            effectVuScale10(distance);
            effectVuStore10(scratch);
            direction.lane[0] = 0.0f + direction.lane[0] + cosine * radius;
            direction.lane[2] = 0.0f + direction.lane[2] + sine * radius;
            effectVuSetX10(sine);
            __asm__ volatile(
                "qmtc2.ni %0, $vf2 \n"
                "vaddx.y $vf10, $vf0, $vf2x \n"
                : : "r"(zero) : "$vf2", "$vf10");
            effectVuSetZ10(-cosine);
            effectVuScale10(particle->width);
            effectVuStore10(&widthVector);
            __asm__ volatile(
                "lqc2 $vf12, 0(%0) \n"
                : : "r"(scratch), "m"(*scratch) : "$vf12");
            effectVuLoad10(&lengthVector);
            __asm__ volatile(
                "vadd.xyzw $vf10, $vf10, $vf12 \n"
                : :  : "$vf10", "$vf11", "$vf12");
            effectVuLoad11(&widthVector);
            __asm__ volatile(
                "vadd.xyzw $vf10, $vf10, $vf11 \n"
                : :  : "$vf10", "$vf11", "$vf12");
            scratch = (EffectVuVector *)D_00713D10;
            effectVuStore10(scratch);
            vertices[0].x = D_00713D10[0];
            vertices[0].y = D_00713D14[0];
            vertices[0].z = D_00713D18[0];
            __asm__ volatile(
                "vsub.xyzw $vf10, $vf10, $vf11 \n"
                "vsub.xyzw $vf10, $vf10, $vf11 \n"
                : :  : "$vf10", "$vf11", "$vf12");
            effectVuStore10(scratch);
            vertices[1].x = D_00713D10[0];
            vertices[1].y = D_00713D14[0];
            vertices[1].z = D_00713D18[0];
            effectVuLoad10(&lengthVector);
            __asm__ volatile(
                "vsub.xyz $vf10, $vf0, $vf10 \n"
                "vadd.xyzw $vf10, $vf10, $vf12 \n"
                : :  : "$vf10", "$vf11", "$vf12");
            effectVuLoad11(&widthVector);
            __asm__ volatile(
                "vadd.xyzw $vf10, $vf10, $vf11 \n"
                : :  : "$vf10", "$vf11", "$vf12");
            effectVuStore10(scratch);
            vertices[2].x = D_00713D10[0];
            vertices[2].y = D_00713D14[0];
            vertices[2].z = D_00713D18[0];
            __asm__ volatile(
                "vsub.xyzw $vf10, $vf10, $vf11 \n"
                "vsub.xyzw $vf10, $vf10, $vf11 \n"
                : :  : "$vf10", "$vf11", "$vf12");
            effectVuStore10(scratch);
            vertices[3].x = D_00713D10[0];
            vertices[3].y = D_00713D14[0];
            vertices[3].z = D_00713D18[0];

            if (age < fadeIn) fade = (f32)age / (f32)fadeIn;
            else if (age > fadeOut) fade = (f32)(life - age) / (f32)(life - fadeOut);
            else fade = unit;
            effectVuLoad11((EffectVuVector *)D_00713CE0);
            effectVuScale11(fade);
            effectVuLoad10(&outerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 transfer;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni %0, $vf10 \n"
                    "ppach %0, $zero, %0 \n"
                    "ppacb %0, $zero, %0 \n"
                    "sw %0, outerPacked \n"
                    : "=&r"(transfer), "=m"(outerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
            }

            colors[0] = outerPacked;
            colors[1] = outerPacked;
            effectVuLoad10(&innerColor);
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" : : : "$vf10");
            {
                u32 transfer;
                __asm__ volatile(
                    "qmtc2.ni %2, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vftoi0.xyzw $vf10, $vf10 \n"
                    "qmfc2.ni %0, $vf10 \n"
                    "ppach %0, $zero, %0 \n"
                    "ppacb %0, $zero, %0 \n"
                    "sw %0, innerPacked \n"
                    : "=&r"(transfer), "=m"(innerPacked) : "r"(byteScale) : "$vf2", "$vf10", "memory");
            }

            colors[2] = innerPacked;
            colors[3] = innerPacked;
            particle->age = age + ageStep;
        }
    }
    {
        u8 *geometry = (u8*)((RpAtomic *)((EffGeometryBlock *)owner)->atomic)->geometry;
        func_003c22f0(geometry);
        if (((EffGeometryBlock *)owner)->kind & 4) ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
    }
}
#pragma pop
/* Native resolved residual: sixteen $v0/$v1 words in the VU address/transfer live range. */
// Packs the quad-copy flash vertex colours from the inner and outer colour words.
// FUN_004A14A0
void FlashQuadCopyPackColors(u8 *input)
{
    union
    {
        s32 w;
        u8 b[4];
    } packedColor;
    s32 parentColor;
    s32 sampleColor;
    s32 combinedColor;
    s32 sampledColor;
    u8 *state;
    u8 *config;
    u8 *geometryOwner;
    u32 frame;
    u32 lastFrame;
    f32 scale;

    state = ((FlashEffect *)input)->state;
    config = ((FlashEffect *)input)->parameters;
    geometryOwner = ((FlashBlock *)state)->geometry.bytes;
    frame = ((FlashEffect *)input)->frame;
    lastFrame = ((FlashParameters *)config)->lastFrame;
    if ((lastFrame >= frame) || (lastFrame == 0))
    {
        s32 *pt;

        sampledColor = mdlEffectSamplePackedColor(config, config + 0x24, frame, lastFrame);
        parentColor = ((FlashEffect *)input)->color;
        pt = &parentColor;
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
        sampleColor = sampledColor;
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
            "sw $2, 0x40($sp)      \n"
            :
            : "r"(&sampleColor), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        packedColor.w = *(s32 *)&combinedColor;
        if (packedColor.b[3] != 0xFF)
        {
            u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
            ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
        }
        else
        {
            packedColor.b[3] = 0xFE;
            {
                u8 *dst = ((EffGeometryBlock *)geometryOwner)->material;
                ((RpMaterial *)dst)->color = *(Color4 *)&packedColor;
            }
            packedColor.b[3] = 0xFF;
        }
        GeometryBlockSetFrameMatrixCombined(geometryOwner, input, input + 0x10, input + 0x20);
        if (((FlashParameters *)config)->geometryFlag != 0)
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind | 1;
        }
        else
        {
            ((EffGeometryBlock *)geometryOwner)->kind = ((EffGeometryBlock *)geometryOwner)->kind & 0xFFFE;
        }
        {
            s32 resourceId = ((FlashParameters *)config)->resourceId;
            GeometryBlockBindResource(geometryOwner, resourceId);
        }
    }
}

// Allocates a quad-copy flash block, copying the source quad into the block.
// FUN_004A1660
/* measured: without opt_propagation off, mwcc folds the %lo of D_00713CE0
 * into the lq offset (lui+lq); retail materializes lui+addiu+lq. */
#pragma opt_propagation off
void *FlashQuadCopyAlloc(s32 input, void *resource)
{
    u8 *effect;
    u_long128 *quadSrc;
    u_long128 quad;
    s32 kind;
    s32 parameterSize;

    if ((u16)input >= 0xA) {
        kAssertFail(D_00713FF0, 0xCD2);
    }
    kind = input & 0xFFFF;
    /* Dispatch records are interleaved 0x1C-byte tables with separate linker symbols. */
    /* Linker interior alias: this symbol names a column in interleaved 0x1C-byte records. */
    parameterSize = *(s32 *)(D_00714028 + kind * 0x1C);
    chkmemAllocSiteTag(D_00713FF0, 0xCD6);
    effect = jtbl_008873E8[0](parameterSize + 0x50, 0x40000);
    if (effect == NULL) {
        kAssertFail(D_00713FF0, 0xCD7);
    }
    /* Integer stores preserve the original pointer-bit initialization shape. */
    ((FlashEffect *)effect)->parameters = effect + 0x50;
    ((FlashEffect *)effect)->frame = 0;
    ((FlashEffect *)effect)->kind = (u32)kind;
    ((FlashEffect *)effect)->color = -1;
    quadSrc = (u_long128 *)D_00713CE0;
    quad = *quadSrc;
    /* Preserve the native quadword scale copy (lq/sq), not scalar float stores. */
    ((FlashEffect *)effect)->scale.quad = quad;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(effect) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(effect) : "memory");
    memcpy(((FlashEffect *)effect)->parameters, resource, (void *)parameterSize);
    return effect;
}
#pragma opt_propagation on

// Allocates a quad-copy flash block that inherits its texture from a parent block.
// FUN_004A1780
void *FlashQuadCopyAllocFromParent(void *input)
{
    u8 *kindArgument;
    u8 *parameters;
    u8 *resource;
    u8 *instance;
    u32 idx;

    resource = mdlEffectResolveRelPtrB(input);
    if (resource == NULL) {
        kAssertFail(D_00713FF0, 0xD08);
    }
    switch (((EffSourceDescriptor *)input)->kind) {
    case 1:
        break;
    case 4:
        resource = NULL;
        break;
    default:
        kAssertFail(D_00713FF0, 0xD11);
        break;
    }
    parameters = mdlEffectResolveRelPtrA(input);
    if (parameters == NULL) {
        kAssertFail(D_00713FF0, 0xD16);
    }
    kindArgument = (u8 *)(((EffSourceDescriptor *)input)->id & 0xFFFF);
    instance = FlashQuadCopyAlloc((s32)kindArgument, parameters);
    /* Allocator and initializer are separate linker-symbol columns of a 0x1C-strided table. */
    idx = ((u32)kindArgument & 0xFFFF) * 28;
    /* Linker interior alias: this symbol names a column in interleaved 0x1C-byte records. */
    ((FlashEffect *)instance)->state = (u8 *)((void *(*)(void *, void *))(*(void **)(D_00714014 + idx)))(parameters, resource);
    /* Linker interior alias: this symbol names a column in interleaved 0x1C-byte records. */
    ((void (*)(void *))(*(void **)(D_00714010 + idx)))(instance);
    if (instance == NULL) {
        kAssertFail(D_00713FF0, 0xD18);
    }
    return instance;
}
