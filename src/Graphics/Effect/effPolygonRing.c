#include "effect_geometry_internal.h"
#include "polygon_ring_internal.h"
#include "rw_geometry_internal.h"
/* Original translation unit effPolygonRing.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "member_access.h"

/* Same spelling as mdlEffect.c: a 128-bit type makes mwcc emit the lq/sq
   quadword copy retail uses, with no inline asm. */
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} LineNovaColor;

#include "rw_types_internal.h"

/* The simple handle allocation stores one geometry pointer. */
typedef struct EffRingHandle { u8 *geometry; } EffRingHandle;

/* Four packed colors per 0x10-byte strip row. */
typedef struct EffRingColorRow {
    s32 colors[4];
} EffRingColorRow;

extern void kAssertFail();
extern u8 D_00713EF0[];
extern void GeometryBlockDestroy(void *block);
extern void (*jtbl_008873EC[])(void *);
extern void RingInstanceDestroy(void *instance);

extern void chkmemAllocSiteTag();
extern void memcpy(void *dst, void *src, u32 size);
extern u8 D_00713390[];
extern s32 mdlEffectSamplePackedColor();
extern void GeometryBlockSetFrameMatrixCombined(void *geometry, void *position, void *rotation, void *scale);
extern void GeometryBlockBindResource(s32 block, s32 resourceId);
extern f32 iGpffff8044;
extern f32 fGpffff8044;
extern void RingInstanceStop(void *instance);
extern u8 *GeometryCreateStripGrid(u16 rowCount, void *indices, s32 verticesPerRow, s32 flags);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00713330[];
extern LineNovaColor iGpffffbb64; /* default packed material color */
extern u_long128 D_00713CE0[];
extern s32 D_00713F24[]; /* parameter byte counts, six words per kind */
extern u32 D_00713F14[]; /* kind constructor callbacks, six-word stride */
extern u32 D_00713F10[]; /* kind initializer callbacks, six-word stride */
extern void RingInstanceUpdateIfActive(void *instance);
extern void func_003c22f0(void *geometry);
extern f32 cosf(f32 angle);
extern f32 sinf(f32 angle);
extern f32 fGpffff80d0;
extern f32 fabsf(f32 x);
extern f32 D_00713D10[];
extern f32 D_00713D14[];
extern f32 D_00713D18[];
extern void RingInstanceAdvance(u8 *instance);



// Creates a ring handle: a 4-byte handle plus geometry copies with per-vertex colour rows (minimum three segments).
// FUN_00498DA0
u8 *RingCreateHandle(u8 *parameters) {
    /* Earlier whole-layout probe: normalized_diff 123; separate typed locals now preserve the original reload lifetimes. */
    u8 *handle;
    u8 *geometry;
    s32 rowCount;
    s32 innerColor;
    s32 middleColor;
    s32 outerColor;
    u32 rowIndex;
    u8 *colors;
    EffRingParameters *ringParameters = (EffRingParameters *)parameters;

    chkmemAllocSiteTag(D_00713EF0, 0x39);
    handle = (u8 *)(*jtbl_008873E8)(4, 0x40000);
    if (handle == NULL) {
        kAssertFail(D_00713EF0, 0x3A);
    }
    if (((EffRingParameters *)parameters)->segments.count < 3) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        ringParameters->segments.count = 3;
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    geometry = GeometryCreateStripGrid(ringParameters->segments.low, D_00713330, 4, 0x48);
    *(u32 *)handle = (u32)geometry;
    rowCount = ((EffGeometryBlock *)geometry)->vertexCount / 4;
    colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry->colors;
    innerColor = ((EffRingParameters *)parameters)->innerColor;
    middleColor = ((EffRingParameters *)parameters)->middleColor;
    outerColor = ((EffRingParameters *)parameters)->outerColor;
    rowIndex = 0;
    while (rowIndex < (u32)rowCount) {
        ((EffRingColorRow *)colors)->colors[0] = innerColor;
        ((EffRingColorRow *)colors)->colors[1] = middleColor;
        ((EffRingColorRow *)colors)->colors[2] = middleColor;
        ((EffRingColorRow *)colors)->colors[3] = outerColor;
        rowIndex++;
        colors += 0x10;
    }
    return handle;
}
// Frees a ring handle: its geometry handle, then the handle block.
// FUN_00498EC0
void RingDestroyHandle(void **handle)
{
    GeometryBlockDestroy(*handle);
    jtbl_008873EC[0](handle);
}



/* measured: b210 -O2 matches with signed vertex-count division, the
   work/parameter/geometry load order, and propagation disabled for
   the unsigned segment-count conversion. */
#pragma push
#pragma opt_propagation off
// Rebuilds a ring circle: locks the geometry, samples cos and sin around the fade radius, writes the vertex rows, then unlocks.
// FUN_00498F10
void RingRebuildCircle(u8 *instance)
{
    /* Earlier whole-layout probe: normalized_diff 462; separate typed locals now preserve the original reload lifetimes. */
    u_long128 direction;
    u_long128 innerRadiusVector;
    u_long128 middleRadiusVector;
    u_long128 outerRadiusVector;
    f32 elapsed;
    f32 radialTerm;
    f32 acceleration;
    f32 speed;
    f32 segmentCount;
    f32 radius;
    f32 angle;
    f32 angleStep;
    f32 innerRadius;
    f32 middleRadius;
    f32 outerRadius;
    s32 duration;
    s32 age;
    s16 vertexCount;
    s32 rowCount;
    u32 rowIndex;
    u8 *handle;
    u8 *geometry;
    u8 *parameters;
    u8 *vertices;
    EffGeometryBlock *geometryBlock;

    handle = ((EffRingInstance *)instance)->work.bytes;
    parameters = ((EffRingInstance *)instance)->parameters;
    geometry = *(u8 **)handle;
    geometryBlock = (EffGeometryBlock *)geometry;
    age = ((EffRingInstance *)instance)->age;
    duration = ((EffRingParameters *)parameters)->duration;
    if ((duration >= age) || (duration == 0)) {
        if (((EffRingCircleParameters *)parameters)->reverse != 0) {
            elapsed = (f32)(duration - age);
        } else {
            elapsed = (f32)age;
        }
        speed = fabsf(((EffRingCircleParameters *)parameters)->speed);
        acceleration = ((EffRingCircleParameters *)parameters)->acceleration;
        if (acceleration < 0.0f) {
            radialTerm = 0.5f * (-speed / (0.5f * acceleration));
            if (!(elapsed <= radialTerm)) {
                elapsed = radialTerm;
            }
        }
        outerRadius = acceleration * elapsed;
        radialTerm = 0.5f * outerRadius + speed;
        radius = elapsed * radialTerm;
        radius += ((EffRingParameters *)parameters)->radius;
        vertexCount = ((EffGeometryBlock *)geometry)->vertexCount;
        rowCount = vertexCount / 4;
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry, 2);
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry->morphTarget->vertices;
        angle = 0.0f;
        segmentCount = (f32)((EffRingParameters *)parameters)->segments.count;
        angleStep = fGpffff80d0 / segmentCount;
        ((s32 *)&direction)[1] = 0;
        ((s32 *)&direction)[3] = 0x3F800000;
        innerRadius = ((EffRingParameters *)parameters)->innerWidth + radius;
        middleRadius = innerRadius + ((EffRingParameters *)parameters)->middleWidth;
        outerRadius = middleRadius + ((EffRingParameters *)parameters)->outerWidth;
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vmove.xyzw $vf11, $vf10 \n"
            "mfc1 $2, %1 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            :
            : "r"(D_00713CE0), "f"(innerRadius)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&innerRadiusVector) : "memory");
        __asm__ volatile(
            "vmove.xyzw $vf10, $vf11 \n"
            "mfc1 $2, %0 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "mfc1 $2, %1 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            :
            : "f"(middleRadius), "f"(outerRadius)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&middleRadiusVector) : "memory");
        __asm__ volatile("sqc2 $vf11, 0(%0)" : : "r"(&outerRadiusVector) : "memory");
        rowIndex = 0;
        while (rowIndex < (u32)rowCount) {
            ((f32 *)&direction)[0] = cosf(angle);
            ((f32 *)&direction)[2] = sinf(angle);
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "vmove.xyzw $vf11, $vf10 \n"
                "mfc1 $2, %1 \n"
                "nop \n"
                "qmtc2.ni $2, $vf2 \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                :
                : "r"(&direction), "f"(radius)
                : "$2", "$vf2", "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[0].x = D_00713D10[0];
            ((RwV3d *)vertices)[0].y = D_00713D14[0];
            ((RwV3d *)vertices)[0].z = D_00713D18[0];
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                :
                : "r"(&innerRadiusVector)
                : "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[1].x = D_00713D10[0];
            ((RwV3d *)vertices)[1].y = D_00713D14[0];
            ((RwV3d *)vertices)[1].z = D_00713D18[0];
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                :
                : "r"(&middleRadiusVector)
                : "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[2].x = D_00713D10[0];
            ((RwV3d *)vertices)[2].y = D_00713D14[0];
            ((RwV3d *)vertices)[2].z = D_00713D18[0];
            __asm__ volatile(
                "lqc2 $vf10, 0(%0) \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                :
                : "r"(&outerRadiusVector)
                : "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
            ((RwV3d *)vertices)[3].x = D_00713D10[0];
            ((RwV3d *)vertices)[3].y = D_00713D14[0];
            ((RwV3d *)vertices)[3].z = D_00713D18[0];
            angle += angleStep;
            rowIndex += 1;
            vertices += 0x30;
        }
        handle = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry;
        func_003c22f0(handle);
        if (((EffGeometryBlock *)geometry)->kind & 4) {
            ((RpGeometry *)handle)->lockedSinceLastInst = ((RpGeometry *)handle)->lockedSinceLastInst | 1;
        }
    }
}
#pragma pop

/* Ported from P3FES mdlEffect.c 0x00338360 (twin of RingUpdateRowColourAlt).
   The VU0 colour-modulate block is genuine hardware asm (Category B) ported
   as inline asm with the pointer passed via a "r" constraint, not a bare
   addiu block. MATCH. */
// Samples the ring colour fade and writes it to the row; when the row's flag is set, updates the geometry and visible flag.
// FUN_004992A0
void RingUpdateRowColour(u8 *instance)
{
  /* Earlier whole-layout probe: normalized_diff 160; color scratch still stores packed VU0 words. */
  u8 *ring;
  u8 *parameters;
  u16 *geometry;
  u8 colourStack[16];
  s32 value;
  s32 duration;
  s32 age;
  u8 *material;
  f32 scale;
  u8 *baseColor;
  EffGeometryBlock *geometryBlock;

  ring = (u8 *)instance;
  value = ((EffRingInstance *)ring)->work.signedBits;
  parameters = ((EffRingInstance *)ring)->parameters;
  geometry = *(u16 **)value;
  geometryBlock = (EffGeometryBlock *)geometry;
  age = ((EffRingInstance *)ring)->age;
  duration = ((EffRingParameters *)parameters)->duration;
  if (((u32)age <= (u32)duration) || (duration == 0)) {
    value = mdlEffectSamplePackedColor((char *)parameters, (u32 *)(parameters + 0x24), age, duration);
    *(u32 *)&colourStack[8] = ((EffRingInstance *)ring)->packedColor;
    baseColor = &colourStack[8];
    scale = iGpffff8044;
    __asm__ volatile (
        ".set noreorder                  \n"
        "lw          $2, 0(%0)           \n"
        "pextlb      $2, $zero, $2       \n"
        "pextlh      $2, $zero, $2       \n"
        "qmtc2       $2, $vf10           \n"
        "vitof0.xyzw $vf10, $vf10        \n"
        "mfc1        $2, %2              \n"
        "nop                               \n"
        "qmtc2       $2, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vmove.xyzw  $vf11, $vf10        \n"
        "sw          %1, 0x44($sp)       \n"
        "addiu       $2, $sp, 0x44       \n"
        "lw          $2, 0($2)           \n"
        "pextlb      $2, $zero, $2       \n"
        "pextlh      $2, $zero, $2       \n"
        "qmtc2       $2, $vf10           \n"
        "vitof0.xyzw $vf10, $vf10        \n"
        "mfc1        $3, %2              \n"
        "nop                               \n"
        "qmtc2       $3, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vmul.xyzw   $vf10, $vf10, $vf11 \n"
        "lui         $3, 0x437F          \n"
        "qmtc2       $3, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vftoi0.xyzw $vf10, $vf10        \n"
        "qmfc2       $3, $vf10           \n"
        "ppach       $3, $zero, $3       \n"
        "ppacb       $3, $zero, $3       \n"
        "sw          $3, 0x40($sp)       \n"
        ".set reorder"
        :
        : "r"(baseColor), "r"((u32)value), "f"(scale)
        : "$2", "$3", "memory");
    *(u32 *)&colourStack[12] = *(u32 *)&colourStack[0];
    if (colourStack[15] != 0xff) {
      material = ((EffGeometryBlock *)geometry)->material;
      *(RwRGBA *)&((RpMaterial *)material)->color = *(RwRGBA *)&colourStack[12];
    }
    else {
      colourStack[15] = 0xfe;
      material = ((EffGeometryBlock *)geometry)->material;
      *(RwRGBA *)&((RpMaterial *)material)->color = *(RwRGBA *)&colourStack[12];
      colourStack[15] = 0xff;
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    if (((RpMaterial *)geometryBlock->material)->color.c[3] != 0) {
      GeometryBlockSetFrameMatrixCombined(geometry, ring, ring + 0x10, ring + 0x20);
      if (((EffRingParameters *)parameters)->visible != 0) {
        *geometry = *geometry | 1;
      }
      else {
        *geometry = *geometry & 0xfffe;
      }
      GeometryBlockBindResource((s32)geometry, ((EffRingParameters *)parameters)->resource);
    }
  }
}
// Writes the line colour into its row; alpha 0xFF is reserved as the marker value, so 0xFE is written in its place.
// FUN_00499470
void RingWriteLineColour(u8 *instance) {
    u8 *block;
    u8 *geometry;
    u8 *material;

    block = ((EffRingInstance *)instance)->work.bytes;
    geometry = ((EffRingRandomBlock *)block)->geometry;
    if (iGpffffbb64.c3 != 0xFF) {
        material = ((EffGeometryBlock *)geometry)->material;
        *(LineNovaColor *)&((RpMaterial *)material)->color = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        material = ((EffGeometryBlock *)geometry)->material;
        *(LineNovaColor *)&((RpMaterial *)material)->color = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
    RingInstanceStop(((EffRingRandomBlock *)block)->sourceInstance);
}

// Creates a ring with a per-vertex random scale and a texture from the kind table.
// FUN_00499510
u8 *RingCreateRandomScaled(u8 *parameters) {
    /* Earlier parameter-only probe: normalized_diff 286; separate typed locals now preserve the original reload lifetimes. */
    u8 *block;
    u8 *scales;
    u32 segmentCount;
    u32 scaleBytes;
    u32 rowIndex;
    u8 *colors;
    s32 innerColor;
    s32 outerColor;
    s32 middleColor;
    f32 spread;
    f32 randomFactor;
    EffRingParameters *ringParameters = (EffRingParameters *)parameters;

    if (((EffRingParameters *)parameters)->segments.count < 3) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        ringParameters->segments.count = 3;
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    segmentCount = ringParameters->segments.count;
    chkmemAllocSiteTag(D_00713EF0, 0x10F);
    scaleBytes = segmentCount * 4;
    scales = (u8 *)(*jtbl_008873E8)(scaleBytes + 0x10, 0x40000);
    if (scales == NULL) {
        kAssertFail(D_00713EF0, 0x110);
    }
    block = scales + scaleBytes;
    ((EffRingRandomBlock *)block)->scales = scales;
    ((EffRingRandomBlock *)block)->allocation = scales;
    memcpy(parameters + 0x5C, parameters, 0x5C);
    ((EffRingRandomBlock *)block)->sourceInstance = RingCreateKindInstance(1, parameters + 0x5C);
    /* Typed pointer/integer stores, a typed local, and array form all reorder the following color loads (181 differing bytes). */
    MEMBER(u32, block, EffRingRandomBlock, geometry) = (u32)GeometryCreateTableGrid(segmentCount & 0xFFFF, 2, 4, D_00713390, 0x48);
    colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)((EffRingRandomBlock *)block)->geometry)->atomic)->geometry->colors;
    innerColor = ((EffRingParameters *)parameters)->innerColor;
    outerColor = ((EffRingParameters *)parameters)->middleColor;
    rowIndex = 0;
    middleColor = (innerColor & outerColor) + (s32)(((u32)(innerColor ^ outerColor) & 0xFEFEFEFE) >> 1);
    while (rowIndex < segmentCount) {
        ((EffRingColorRow *)colors)->colors[0] = innerColor;
        ((EffRingColorRow *)colors)->colors[1] = innerColor;
        ((EffRingColorRow *)colors)->colors[2] = middleColor;
        ((EffRingColorRow *)colors)->colors[3] = innerColor;
        spread = ((EffRingRandomParameters *)parameters)->radialSpread;
        randomFactor = effMiscRandFloat(0);
        ((f32 *)scales)[0] = ((EffRingRandomParameters *)parameters)->radialScale * ((1.0f - spread) + spread * randomFactor);
        rowIndex++;
        colors += 0x10;
        scales += 4;
    }
    return block;
}
// Frees a ring block: its geometry handle, its second handle, then the block itself.
// FUN_004996E0
void RingDestroyBlock(u8 *block)
{
    GeometryBlockDestroy(((EffRingRandomBlock *)block)->geometry);
    RingInstanceDestroy(((EffRingRandomBlock *)block)->sourceInstance);
    jtbl_008873EC[0](((EffRingRandomBlock *)block)->allocation);
}



/* measured: loop invariants hoist the vector-scratch bases. Keeping
   the wrap stride at its use preserves its lifetime through the
   FPU-to-VU bridge, which declares its actual scratch output. */
#pragma push
#pragma opt_loop_invariants on
// Rebuilds the ring strip vertices from the two geometry handles, locking and unlocking each geometry around the vertex loop.
// FUN_00499730
void RingRebuildStrip(u8 *instance)
{
    /* Earlier whole-layout probe: normalized_diff 428; separate typed locals now preserve the original reload lifetimes. */
    u8 *block;
    u8 *sourceInstance;
    u8 **sourceHandle;
    u8 *parameters;
    u8 *geometry;
    u8 *scales;
    s32 age;
    s32 duration;
    f32 step;
    u32 limit;
    u8 *sourceGeometry;
    s32 lastVertex;
    u32 counter;
    u8 *vertices;
    u8 *sourceVertices;
    s32 bias;
    u8 *wrapVertex;
    f32 radialOffset;
    s32 transfer;
    f32 x;
    f32 y;
    f32 z;
    u8 *updatedSource;
    u8 *sourceRwGeometry;
    u8 *rwGeometry;
    EffGeometryBlock *geometryBlock;

    block = ((EffRingInstance *)instance)->work.bytes;
    sourceInstance = ((EffRingRandomBlock *)block)->sourceInstance;
    sourceHandle = (u8 **)((EffRingInstance *)sourceInstance)->work.bytes;
    parameters = ((EffRingInstance *)instance)->parameters;
    geometry = ((EffRingRandomBlock *)block)->geometry;
    geometryBlock = (EffGeometryBlock *)geometry;
    scales = ((EffRingRandomBlock *)block)->scales;
    age = ((EffRingInstance *)instance)->age;
    duration = ((EffRingParameters *)parameters)->duration;
    if ((duration >= age) || (duration == 0)) {
        RingInstanceAdvance(sourceInstance);
        step = (f32)age / (f32)duration;
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry, 2);
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)*sourceHandle)->atomic)->geometry, 2);
        limit = ((EffRingParameters *)parameters)->segments.count;
        sourceGeometry = *sourceHandle;
        lastVertex = ((EffGeometryBlock *)sourceGeometry)->vertexCount - 1;
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry->morphTarget->vertices;
        sourceVertices = (u8 *)((RpAtomic *)((EffGeometryBlock *)sourceGeometry)->atomic)->geometry->morphTarget->vertices;
        if (((EffRingRandomParameters *)parameters)->skipVertices == 0) {
            counter = 0;
            bias = -0x48;
            while (counter < limit) {
                D_00713D10[0] = ((RwV3d *)sourceVertices)[1].x;
                D_00713D14[0] = ((RwV3d *)sourceVertices)[1].y;
                D_00713D18[0] = ((RwV3d *)sourceVertices)[1].z;
                __asm__ volatile(
                    "lqc2 $vf10, 0(%0) \n"
                    "vmove.xyzw $vf12, $vf10 \n"
                    :
                    : "r"(D_00713D10)
                    : "$vf10", "$vf12", "memory");
                D_00713D10[0] = ((RwV3d *)sourceVertices)[3].x;
                D_00713D14[0] = ((RwV3d *)sourceVertices)[3].y;
                D_00713D18[0] = ((RwV3d *)sourceVertices)[3].z;
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0) \n"
                    "sqc2 $vf10, 0(%0) \n"
                    :
                    : "r"(D_00713D10)
                    : "$vf10", "$vf11", "memory");
                ((RwV3d *)vertices)[2].x = D_00713D10[0];
                ((RwV3d *)vertices)[2].y = D_00713D14[0];
                ((RwV3d *)vertices)[2].z = D_00713D18[0];
                __asm__ volatile(
                    "vsub.xyzw $vf10, $vf10, $vf11 \n"
                    "vmul.xyz $vf2, $vf10, $vf10 \n"
                    "vmulax.w $ACC, $vf0, $vf2x \n"
                    "vmadday.w $ACC, $vf0, $vf2y \n"
                    "vmaddz.w $vf2, $vf0, $vf2z \n"
                    "vrsqrt $Q, $vf0w, $vf2w \n"
                    "vwaitq \n"
                    "vmulq.xyz $vf10, $vf10, $Q \n"
                    :
                    :
                    : "$vf2", "$vf10", "$vf11", "$vf12", "ACC", "Q", "memory");
                radialOffset = *(f32 *)scales * step;
                /* The FPU-to-VU bridge writes its scratch before consuming it. */
                __asm__ volatile(
                    "mfc1 %0, %1 \n"
                    "nop \n"
                    "qmtc2.ni %0, $vf2 \n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                    "vadd.xyzw $vf10, $vf10, $vf12 \n"
                    : "=&r"(transfer)
                    : "f"(radialOffset)
                    : "$vf2", "$vf10", "memory");
                __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "memory");
                ((RwV3d *)vertices)[0].x = D_00713D10[0];
                ((RwV3d *)vertices)[0].y = D_00713D14[0];
                ((RwV3d *)vertices)[0].z = D_00713D18[0];
                x = ((RwV3d *)sourceVertices)[5].x;
                y = ((RwV3d *)sourceVertices)[5].y;
                z = ((RwV3d *)sourceVertices)[5].z;
                ((RwV3d *)vertices)[1].x = x;
                ((RwV3d *)vertices)[1].y = y;
                ((RwV3d *)vertices)[1].z = z;
                if (counter == 0) {
                    wrapVertex = sourceVertices + lastVertex * 12 + bias;
                    x = ((RwV3d *)wrapVertex)[0].x;
                    y = ((RwV3d *)wrapVertex)[0].y;
                    z = ((RwV3d *)wrapVertex)[0].z;
                    ((RwV3d *)vertices)[3].x = x;
                    ((RwV3d *)vertices)[3].y = y;
                    ((RwV3d *)vertices)[3].z = z;
                } else {
                    x = ((RwV3d *)sourceVertices)[-3].x;
                    y = ((RwV3d *)sourceVertices)[-3].y;
                    z = ((RwV3d *)sourceVertices)[-3].z;
                    ((RwV3d *)vertices)[3].x = x;
                    ((RwV3d *)vertices)[3].y = y;
                    ((RwV3d *)vertices)[3].z = z;
                }
                counter += 1;
                vertices += 0x30;
                sourceVertices += 0x30;
                scales += 4;
            }
        }
        updatedSource = *sourceHandle;
        sourceRwGeometry = (u8 *)((RpAtomic *)((EffGeometryBlock *)updatedSource)->atomic)->geometry;
        func_003c22f0(sourceRwGeometry);
        if (((EffGeometryBlock *)updatedSource)->kind & 4) {
            ((RpGeometry *)sourceRwGeometry)->lockedSinceLastInst = ((RpGeometry *)sourceRwGeometry)->lockedSinceLastInst | 1;
        }
        rwGeometry = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry;
        func_003c22f0(rwGeometry);
        if (((EffGeometryBlock *)geometry)->kind & 4) {
            ((RpGeometry *)rwGeometry)->lockedSinceLastInst = ((RpGeometry *)rwGeometry)->lockedSinceLastInst | 1;
        }
    }
}
#pragma pop

// Updates a line-nova segment from the source's state block when the row is live.
// FUN_00499A30
void RingUpdateLineSegment(u8 *instance)
{
    /* Earlier whole-layout probe: normalized_diff 196; color scratch still stores packed VU0 words. */
    u8 *block;
    u8 *parameters;
    u8 *geometry;
    u8 colourStack[16];
    s32 sampledColor;
    u8 *material;
    u8 *baseColor;
    f32 scale;
    u_long128 *destinationQuad;
    EffGeometryBlock *geometryBlock;

    block = ((EffRingInstance *)instance)->work.bytes;
    parameters = ((EffRingInstance *)instance)->parameters;
    geometry = ((EffRingRandomBlock *)block)->geometry;
    geometryBlock = (EffGeometryBlock *)geometry;
    if (((u32)((EffRingParameters *)parameters)->duration >= (u32)((EffRingInstance *)instance)->age) ||
        (((EffRingParameters *)parameters)->duration == 0)) {
        sampledColor = mdlEffectSamplePackedColor(parameters, parameters + 0x24,
                               ((EffRingInstance *)instance)->age,
                               ((EffRingParameters *)parameters)->duration);
        *(u32 *)&colourStack[8] = ((EffRingInstance *)instance)->packedColor;
        baseColor = &colourStack[8];
        scale = fGpffff8044;
        __asm__ volatile(
            ".set noreorder              \n"
            "lw $2, 0(%0)                 \n"
            "pextlb $2, $0, $2            \n"
            "pextlh $2, $0, $2            \n"
            "qmtc2.ni $2, $vf10           \n"
            "vitof0.xyzw $vf10, $vf10     \n"
            "mfc1 $2, %2                 \n"
            "nop                         \n"
            "qmtc2.ni $2, $vf2            \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10      \n"
            "sw %1, 0x54($sp)             \n"
            "addiu $2, $sp, 0x54          \n"
            "lw $2, 0($2)                 \n"
            "pextlb $2, $0, $2            \n"
            "pextlh $2, $0, $2            \n"
            "qmtc2.ni $2, $vf10           \n"
            "vitof0.xyzw $vf10, $vf10     \n"
            "mfc1 $3, %2                 \n"
            "nop                         \n"
            "qmtc2.ni $3, $vf2            \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437F               \n"
            "qmtc2.ni $3, $vf2            \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10    \n"
            "qmfc2.ni $3, $vf10           \n"
            "ppach $3, $0, $3             \n"
            "ppacb $3, $0, $3             \n"
            "sw $3, 0x50($sp)             \n"
            ".set reorder                \n"
            :
            : "r"(baseColor), "r"(sampledColor), "f"(scale)
            : "$2", "$3", "memory");
        *(u32 *)&colourStack[12] = *(u32 *)&colourStack[0];
        if (colourStack[15] != 0xFF) {
            material = ((EffGeometryBlock *)geometry)->material;
            *(LineNovaColor *)&((RpMaterial *)material)->color =
                *(LineNovaColor *)&colourStack[12];
        } else {
            colourStack[15] = 0xFE;
            material = ((EffGeometryBlock *)geometry)->material;
            *(LineNovaColor *)&((RpMaterial *)material)->color =
                *(LineNovaColor *)&colourStack[12];
            colourStack[15] = 0xFF;
        }
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        if (((RpMaterial *)geometryBlock->material)->color.c[3] != 0) {
            ((EffRingInstance *)((EffRingRandomBlock *)block)->sourceInstance)->packedColor =
                ((EffRingInstance *)instance)->packedColor;
            destinationQuad = (u_long128 *)(((EffRingRandomBlock *)block)->sourceInstance + 0x20);
            *destinationQuad = ((EffRingInstance *)instance)->scale;
            destinationQuad = (u_long128 *)(((EffRingRandomBlock *)block)->sourceInstance + 0x0);
            *destinationQuad = ((EffRingInstance *)instance)->position;
            material = ((EffRingRandomBlock *)block)->sourceInstance;
            destinationQuad = (u_long128 *)(material + 0x10);
            *destinationQuad = ((EffRingInstance *)instance)->rotation;
            RingInstanceUpdateIfActive(((EffRingRandomBlock *)block)->sourceInstance);
            GeometryBlockSetFrameMatrixCombined(geometry, instance, instance + 0x10, instance + 0x20);
            if (((EffRingParameters *)parameters)->visible != 0) {
                ((EffGeometryBlock *)geometry)->kind = ((EffGeometryBlock *)geometry)->kind | 1;
            } else {
                ((EffGeometryBlock *)geometry)->kind = ((EffGeometryBlock *)geometry)->kind & 0xFFFE;
            }
            GeometryBlockBindResource((s32)geometry, ((EffRingParameters *)parameters)->resource);
        }
    }
}

// Writes the line colour into its row; alpha 0xFF is reserved as the marker value, so 0xFE is written in its place.
// FUN_00499C50
void RingWriteLineColourAlt(u8 *instance) {
    u8 *geometry;
    u8 *material;

    geometry = ((EffRingHandle *)((EffRingInstance *)instance)->work.bytes)->geometry;
    if (iGpffffbb64.c3 != 0xFF) {
        material = ((EffGeometryBlock *)geometry)->material;
        *(LineNovaColor *)&((RpMaterial *)material)->color = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        material = ((EffGeometryBlock *)geometry)->material;
        *(LineNovaColor *)&((RpMaterial *)material)->color = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
}

// Creates a ring handle with geometry copies and per-vertex colour rows. Same body as RingCreateHandle.
// FUN_00499CD0
u8 *RingCreateHandleAlt(u8 *parameters) {
    /* Earlier whole-layout probe: normalized_diff 123; separate typed locals now preserve the original reload lifetimes. */
    u8 *handle;
    u8 *geometry;
    s32 rowCount;
    s32 innerColor;
    s32 middleColor;
    s32 outerColor;
    u32 rowIndex;
    u8 *colors;
    EffRingParameters *ringParameters = (EffRingParameters *)parameters;

    chkmemAllocSiteTag(D_00713EF0, 0x1E6);
    handle = (u8 *)(*jtbl_008873E8)(4, 0x40000);
    if (handle == NULL) {
        kAssertFail(D_00713EF0, 0x1E7);
    }
    if (((EffRingParameters *)parameters)->segments.count < 3) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        ringParameters->segments.count = 3;
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    geometry = GeometryCreateStripGrid(ringParameters->segments.low, D_00713330, 4, 0x48);
    *(u32 *)handle = (u32)geometry;
    rowCount = ((EffGeometryBlock *)geometry)->vertexCount / 4;
    colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry->colors;
    innerColor = ((EffRingParameters *)parameters)->innerColor;
    middleColor = ((EffRingParameters *)parameters)->middleColor;
    outerColor = ((EffRingParameters *)parameters)->outerColor;
    rowIndex = 0;
    while (rowIndex < (u32)rowCount) {
        ((EffRingColorRow *)colors)->colors[0] = innerColor;
        ((EffRingColorRow *)colors)->colors[1] = middleColor;
        ((EffRingColorRow *)colors)->colors[2] = middleColor;
        ((EffRingColorRow *)colors)->colors[3] = outerColor;
        rowIndex++;
        colors += 0x10;
    }
    return handle;
}
// Frees a ring handle: its geometry, then the handle block. Same body as RingDestroyHandle.
// FUN_00499DF0
void RingDestroyHandleAlt(void **handle)
{
    GeometryBlockDestroy(*handle);
    jtbl_008873EC[0](handle);
}

/* measured: quadword locals retain the VU copy storage. Store each
   trig result before the next call, and defer the middle-vector
   store until the independent outer-vector multiply completes. */
#pragma push
#pragma opt_propagation off
// Rebuilds a scaled ring circle: samples cos and sin around the fade radius and writes the vertex and colour rows.
// FUN_00499E40
void RingRebuildCircleScaled(u8 *instance)
{
    /* Earlier whole-layout probe: normalized_diff 434; separate typed locals now preserve the original reload lifetimes. */
    u8 *parameters;
    u8 *geometry;
    s32 age;
    s32 duration;
    s16 vertexCount;
    s32 rowCount;
    u32 rowIndex;
    u8 *vertices;
    f32 elapsed;
    f32 radialTerm;
    f32 acceleration;
    f32 speed;
    f32 segmentCount;
    f32 phase;
    f32 step;
    f32 zero;
    f32 fade;
    f32 innerRadius;
    f32 middleRadius;
    f32 outerRadius;
    u_long128 direction;
    u_long128 innerRadiusVector;
    u_long128 middleRadiusVector;
    u_long128 outerRadiusVector;
    u8 *rwGeometry;
    EffGeometryBlock *geometryBlock;

    {
        u8 *handle = ((EffRingInstance *)instance)->work.bytes;
        parameters = ((EffRingInstance *)instance)->parameters;
        geometry = *(u8 **)handle;
        geometryBlock = (EffGeometryBlock *)geometry;
        age = ((EffRingInstance *)instance)->age;
        duration = ((EffRingParameters *)parameters)->duration;
    }
    if ((duration >= age) || (duration == 0)) {
        if (((EffRingScaledParameters *)parameters)->reverse != 0) {
            elapsed = (f32)(duration - age);
        } else {
            elapsed = (f32)age;
        }
        speed = fabsf(((EffRingScaledParameters *)parameters)->speed);
        acceleration = ((EffRingScaledParameters *)parameters)->acceleration;
        if (acceleration < 0.0f) {
            radialTerm = 0.5f * (-speed / (0.5f * acceleration));
            if (elapsed > radialTerm) {
                elapsed = radialTerm;
            }
        }
        innerRadius = acceleration * elapsed;
        outerRadius = speed + 0.5f * innerRadius;
        middleRadius = elapsed * outerRadius;
        fade = middleRadius + ((EffRingParameters *)parameters)->radius;
        vertexCount = ((EffGeometryBlock *)geometry)->vertexCount;
        rowCount = vertexCount / 4;
        RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry, 2);
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        vertices = (u8 *)((RpAtomic *)geometryBlock->atomic)->geometry->morphTarget->vertices;
        phase = 0.0f;
        segmentCount = (f32)((EffRingParameters *)parameters)->segments.count;
        step = fGpffff80d0 / segmentCount;
        zero = 0.0f;
        ((s32 *)&direction)[1] = 0;
        ((s32 *)&direction)[3] = 0x3F800000;
        innerRadius = ((EffRingParameters *)parameters)->innerWidth + fade;
        middleRadius = innerRadius + ((EffRingParameters *)parameters)->middleWidth;
        outerRadius = middleRadius + ((EffRingParameters *)parameters)->outerWidth;
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            "vmove.xyzw $vf11, $vf10 \n"
            "mfc1 $2, %1 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            : : "r"(D_00713CE0), "f"(innerRadius) : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&innerRadiusVector) : "$vf10", "memory");
        __asm__ volatile(
            "vmove.xyzw $vf10, $vf11 \n"
            "mfc1 $2, %0 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            : : "f"(middleRadius) : "$2", "$vf2", "$vf10", "$vf11", "memory");
        __asm__ volatile(
            "mfc1 $2, %0 \n"
            "nop \n"
            "qmtc2.ni $2, $vf2 \n"
            "vmulx.xyzw $vf11, $vf11, $vf2x \n"
            : : "f"(outerRadius) : "$2", "$vf2", "$vf11", "memory");
        __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(&middleRadiusVector) : "$vf10", "memory");
        __asm__ volatile("sqc2 $vf11, 0(%0)" : : "r"(&outerRadiusVector) : "$vf11", "memory");
        rowIndex = 0;
        while (rowIndex < (u32)rowCount) {
            ((f32 *)&direction)[0] = cosf(phase);
            ((f32 *)&direction)[2] = sinf(phase);
            ((RwV3d *)vertices)[0].x = zero;
            ((RwV3d *)vertices)[0].y = zero;
            ((RwV3d *)vertices)[0].z = zero;
            __asm__ volatile("lqc2 $vf11, 0(%0)" : : "r"(&direction) : "$vf11", "memory");
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&innerRadiusVector) : "$vf10", "memory");
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" ::: "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "$vf10", "memory");
            ((RwV3d *)vertices)[1].x = D_00713D10[0];
            ((RwV3d *)vertices)[1].y = D_00713D14[0];
            ((RwV3d *)vertices)[1].z = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&middleRadiusVector) : "$vf10", "memory");
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" ::: "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "$vf10", "memory");
            ((RwV3d *)vertices)[2].x = D_00713D10[0];
            ((RwV3d *)vertices)[2].y = D_00713D14[0];
            ((RwV3d *)vertices)[2].z = D_00713D18[0];
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(&outerRadiusVector) : "$vf10", "memory");
            __asm__ volatile("vmul.xyzw $vf10, $vf10, $vf11" ::: "$vf10", "$vf11", "memory");
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(D_00713D10) : "$vf10", "memory");
            ((RwV3d *)vertices)[3].x = D_00713D10[0];
            ((RwV3d *)vertices)[3].y = D_00713D14[0];
            ((RwV3d *)vertices)[3].z = D_00713D18[0];
            phase = phase + step;
            rowIndex += 1;
            vertices += 0x30;
        }
        rwGeometry = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometry)->atomic)->geometry;
        func_003c22f0(rwGeometry);
        if (((EffGeometryBlock *)geometry)->kind & 4) {
            ((RpGeometry *)rwGeometry)->lockedSinceLastInst = ((RpGeometry *)rwGeometry)->lockedSinceLastInst | 1;
        }
    }
}
#pragma pop

/* Ported from P3FES mdlEffect.c 0x00338360 (twin of RingUpdateRowColour).
   Same VU0 inline-asm + constraint-pointer shape as its twin. MATCH. */
// Updates a ring row colour and geometry: the second caller's copy of RingUpdateRowColour.
// FUN_0049A1A0
void RingUpdateRowColourAlt(u8 *instance)
{
  /* Earlier whole-layout probe: normalized_diff 160; color scratch still stores packed VU0 words. */
  u8 *ring;
  u8 *parameters;
  u16 *geometry;
  u8 colourStack[16];
  s32 value;
  s32 duration;
  s32 age;
  u8 *material;
  f32 scale;
  u8 *baseColor;
  EffGeometryBlock *geometryBlock;

  ring = (u8 *)instance;
  value = ((EffRingInstance *)ring)->work.signedBits;
  parameters = ((EffRingInstance *)ring)->parameters;
  geometry = *(u16 **)value;
  geometryBlock = (EffGeometryBlock *)geometry;
  age = ((EffRingInstance *)ring)->age;
  duration = ((EffRingParameters *)parameters)->duration;
  if (((u32)age <= (u32)duration) || (duration == 0)) {
    value = mdlEffectSamplePackedColor((char *)parameters, (u32 *)(parameters + 0x24), age, duration);
    *(u32 *)&colourStack[8] = ((EffRingInstance *)ring)->packedColor;
    baseColor = &colourStack[8];
    scale = iGpffff8044;
    __asm__ volatile (
        ".set noreorder                  \n"
        "lw          $2, 0(%0)           \n"
        "pextlb      $2, $zero, $2       \n"
        "pextlh      $2, $zero, $2       \n"
        "qmtc2       $2, $vf10           \n"
        "vitof0.xyzw $vf10, $vf10        \n"
        "mfc1        $2, %2              \n"
        "nop                               \n"
        "qmtc2       $2, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vmove.xyzw  $vf11, $vf10        \n"
        "sw          %1, 0x44($sp)       \n"
        "addiu       $2, $sp, 0x44       \n"
        "lw          $2, 0($2)           \n"
        "pextlb      $2, $zero, $2       \n"
        "pextlh      $2, $zero, $2       \n"
        "qmtc2       $2, $vf10           \n"
        "vitof0.xyzw $vf10, $vf10        \n"
        "mfc1        $3, %2              \n"
        "nop                               \n"
        "qmtc2       $3, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vmul.xyzw   $vf10, $vf10, $vf11 \n"
        "lui         $3, 0x437F          \n"
        "qmtc2       $3, $vf2            \n"
        "vmulx.xyzw  $vf10, $vf10, $vf2x \n"
        "vftoi0.xyzw $vf10, $vf10        \n"
        "qmfc2       $3, $vf10           \n"
        "ppach       $3, $zero, $3       \n"
        "ppacb       $3, $zero, $3       \n"
        "sw          $3, 0x40($sp)       \n"
        ".set reorder"
        :
        : "r"(baseColor), "r"((u32)value), "f"(scale)
        : "$2", "$3", "memory");
    *(u32 *)&colourStack[12] = *(u32 *)&colourStack[0];
    if (colourStack[15] != 0xff) {
      material = ((EffGeometryBlock *)geometry)->material;
      *(RwRGBA *)&((RpMaterial *)material)->color = *(RwRGBA *)&colourStack[12];
    }
    else {
      colourStack[15] = 0xfe;
      material = ((EffGeometryBlock *)geometry)->material;
      *(RwRGBA *)&((RpMaterial *)material)->color = *(RwRGBA *)&colourStack[12];
      colourStack[15] = 0xff;
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    if (((RpMaterial *)geometryBlock->material)->color.c[3] != 0) {
      GeometryBlockSetFrameMatrixCombined(geometry, ring, ring + 0x10, ring + 0x20);
      if (((EffRingParameters *)parameters)->visible != 0) {
        *geometry = *geometry | 1;
      }
      else {
        *geometry = *geometry & 0xfffe;
      }
      GeometryBlockBindResource((s32)geometry, ((EffRingParameters *)parameters)->resource);
    }
  }
}
// Creates a kind instance (kind below four): allocates the instance block, copies the kind's parameters and runs its init callback.
// FUN_0049A370
/* measured: opt_propagation off keeps the named D_00713CE0 pointer's
   lui/addiu/lq sequence instead of folding the low half into lq. */
#pragma opt_propagation off
u8 *RingCreateKindInstance(u16 kind, u8 *parameters)
{
    u8 *instance;
    u_long128 *quadSrc;
    u_long128 quad;
    s32 parameterSize;
    u32 kindIndex;

    if (kind >= 4) {
        kAssertFail(D_00713EF0, 0x2BD);
    }
    kindIndex = kind;
    parameterSize = D_00713F24[kindIndex * 6];
    chkmemAllocSiteTag(D_00713EF0, 0x2C1);
    instance = (u8 *)(*jtbl_008873E8)(parameterSize + 0x50, 0x40000);
    if (instance == NULL) {
        kAssertFail(D_00713EF0, 0x2C2);
    }
    ((EffRingInstance *)instance)->parameters = instance + 0x50;
    ((EffRingInstance *)instance)->age = 0;
    ((EffRingInstance *)instance)->kind = kindIndex;
    ((EffRingInstance *)instance)->packedColor = -1;
    quadSrc = (u_long128 *)D_00713CE0;
    quad = *quadSrc;
    ((EffRingInstance *)instance)->scale = quad;
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(instance) : "memory");
    __asm__ volatile("sqc2 vf0, 0x10(%0)" : : "r"(instance) : "memory");
    memcpy(((EffRingInstance *)instance)->parameters, parameters, parameterSize);
    ((EffRingInstance *)instance)->work.bits =
        ((u32 (*)(u8 *))D_00713F14[kind * 6])(parameters);
    ((void (*)(u8 *))D_00713F10[kind * 6])(instance);
    return instance;
}
#pragma opt_propagation on
// Creates a kind instance for an object: resolves the object's record, then builds the instance for its kind (asserts on a missing record).
// FUN_0049A4E0
void *RingCreateKindInstanceFromObject(void *source) {
    u8 *instance;

    instance = mdlEffectResolveRelPtrA(source);
    if (instance == NULL) {
        kAssertFail(D_00713EF0, 0x2E5);
    }
    instance = RingCreateKindInstance(((EffSourceDescriptor *)source)->id, instance);
    if (instance == NULL) {
        kAssertFail(D_00713EF0, 0x2E7);
    }
    return instance;
}
