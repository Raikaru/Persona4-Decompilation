#include "member_access.h"
#include "mdl_effect_drawable_internal.h"
#include "btl_action_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;
extern PolygonWindColor iGpffffbb64;
extern u8 D_0071413C[];
extern f32 iGpffff8080;


extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern f32 D_00922D80[];
extern u32 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];
extern u8 D_00714010[];
extern u8 D_00714024[];
extern u8 D_00714020[];
extern u8 D_00714018[];

extern u8 D_00714144[];



extern void memcpy(void *dst, void *src, u32 size);
extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern void func_003c22f0();
extern u16 *GeometryCreateTableGridMultiPart(s32 partCount, s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow,
                          void *indices, s32 flags);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004a1ca0-004a1d70 */

/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
/* measured: func_004a1ca0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Reset each wind entry age to -1 and initialize its material color from the global tint. */
// FUN_004A1CA0
void mdlEffectResetWindEntries(u8 *instance)
{
    u8 *work;
    u8 *entry;
    u32 count;
    u32 i;
    u8 *model;
    u8 *material;

    work = ((MdlEffectVectorInstance *)instance)->child;
    entry = *(u8 **)work;
    count = ((MdlEffectWindParameters *)((MdlEffectVectorInstance *)instance)->parameters)->meshCount;
    i = 0;
    while (i < count) {
        model = ((MdlEffectWindWork *)work)->geometry;
        if (iGpffffbb64.c3 != 0xFF) {
            material = ((u8 **)((MdlEffectMultipartGeometry *)model)->materials)[((i & 0xFFFF) * 4) / sizeof(u8 *)];
            *(PolygonWindColor *)&((RpMaterial *)material)->color = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = 0xFE;
            material = ((u8 **)((MdlEffectMultipartGeometry *)model)->materials)[((i & 0xFFFF) * 4) / sizeof(u8 *)];
            *(PolygonWindColor *)&((RpMaterial *)material)->color = iGpffffbb64;
            iGpffffbb64.c3 = 0xFF;
        }
        *(s32 *)entry = -1;
        i++;
        entry += 0x30;
    }
}

/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
/* Build fade-in/out vertex color rows and width coordinates, then replicate them for every mesh. */
// FUN_004A1D70
void mdlEffectBuildWindFadeRows(u8 *instance, u8 *parameters)
{
    u32 meshCount;
    u8 *geometry;
    u8 *colors;
    u8 *colorsBase;
    u8 *verticesBase;
    u8 *vertices;
    s32 frames;
    u32 fadeIn;
    u32 fadeOut;
    u32 pointCount;
    u32 i;
    f32 opacity;
    f32 step;
    u32 colorBytes;
    u32 wordCount;
    u32 vertexBytes;
    u32 copies;
    u16 *model;

    meshCount = ((MdlEffectWindParameters *)parameters)->meshCount;
    if (meshCount != 0) {
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        geometry = (u8 *)((RpAtomic *)((MdlEffectMultipartGeometry *)MEMBER(u8 *, instance, MdlEffectWindWork, geometry))->model)->geometry;
        RpGeometryLock((RpGeometry *)geometry, 0xFF8);
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        geometry = (u8 *)((RpAtomic *)((MdlEffectMultipartGeometry *)MEMBER(u8 *, instance, MdlEffectWindWork, geometry))->model)->geometry;
        colorsBase = (u8 *)((RpGeometry *)geometry)->colors;
        colors = colorsBase;
        verticesBase = (u8 *)((RpGeometry *)geometry)->texCoords[0];
        vertices = verticesBase;
        step = ((MdlEffectWindParameters *)parameters)->width / 3.0f;
        frames = ((MdlEffectWindParameters *)parameters)->duration;
        fadeIn = (s32)(((MdlEffectWindParameters *)parameters)->fadeIn * (f32)frames);
        fadeOut = (s32)(((MdlEffectWindParameters *)parameters)->fadeOut * (f32)frames);
        pointCount = frames + 1;
        wordCount = pointCount * 4;
        i = 0;
        while (i < pointCount) {
            if (i < fadeIn) {
                opacity = (f32)i / (f32)(s32)fadeIn;
            } else if (fadeOut < i) {
                opacity = (f32)(u32)(frames - i) / (f32)(s32)(frames - fadeOut);
            } else {
                opacity = 1.0f;
            }
            ((u32 *)colors)[0] = 0xFFFFFF;
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            MEMBER(u32, colors, MdlEffectWindColorRow, colors[1]) = ((u32)(opacity * 255.0f) << 24) | 0xFFFFFF;
            ((PolygonWindColor *)colors)[2] = ((PolygonWindColor *)colors)[1];
            ((u32 *)colors)[3] = 0xFFFFFF;
            colors += 0x10;
            /* The first texture coordinate is initialized through its integer zero bit pattern; retain that representation. */
            ((u32 *)vertices)[0] = 0;
            ((f32 *)vertices)[2] = step;
            ((f32 *)vertices)[4] = step * 2.0f;
            ((f32 *)vertices)[6] = step * 3.0f;
            vertices += 0x20;
            i += 1;
        }
        copies = 1;
        colorBytes = wordCount * 4;
        vertexBytes = wordCount * 8;
        while (copies < meshCount) {
            memcpy(colors, colorsBase, colorBytes);
            colors += colorBytes;
            memcpy(vertices, verticesBase, vertexBytes);
            vertices += vertexBytes;
            copies += 1;
        }
        model = (u16 *)((MdlEffectWindWork *)instance)->geometry;
        geometry = (u8 *)((RpAtomic *)((EffGeometryBlock *)(u8 *)model)->atomic)->geometry;
        func_003c22f0(geometry);
        if ((*model & 4) != 0) {
            ((RpGeometry *)geometry)->lockedSinceLastInst |= 1;
        }
    }
}

