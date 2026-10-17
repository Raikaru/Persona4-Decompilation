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
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
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
extern u16 *GeometryCreateTableGridMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
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
// FUN_004A1CA0
void func_004a1ca0(u8 *arg0)
{
    u8 *p5;
    u8 *p7;
    u32 count;
    u32 i;
    u8 *p11;
    u8 *p13;

    p5 = *(u8 **)(arg0 + 0x3C);
    p7 = *(u8 **)p5;
    count = *(u32 *)(*(u8 **)(arg0 + 0x40) + 0x38);
    i = 0;
    while (i < count) {
        p11 = *(u8 **)(p5 + 4);
        if (iGpffffbb64.c3 != 0xFF) {
            p13 = *(u8 **)(*(u8 **)(p11 + 0x54) + (i & 0xFFFF) * 4);
            *(PolygonWindColor *)(p13 + 4) = iGpffffbb64;
        } else {
            iGpffffbb64.c3 = 0xFE;
            p13 = *(u8 **)(*(u8 **)(p11 + 0x54) + (i & 0xFFFF) * 4);
            *(PolygonWindColor *)(p13 + 4) = iGpffffbb64;
            iGpffffbb64.c3 = 0xFF;
        }
        *(s32 *)p7 = -1;
        i++;
        p7 += 0x30;
    }
}

/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
// FUN_004A1D70
void func_004a1d70(u8 *arg0, u8 *arg1)
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

    meshCount = *(u32 *)(arg1 + 0x38);
    if (meshCount != 0) {
        geometry = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18);
        RpGeometryLock((RpGeometry *)geometry, 0xFF8);
        geometry = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 4) + 0x10) + 0x18);
        colorsBase = *(u8 **)(geometry + 0x30);
        colors = colorsBase;
        verticesBase = *(u8 **)(geometry + 0x34);
        vertices = verticesBase;
        step = *(f32 *)(arg1 + 0x90) / 3.0f;
        frames = *(s32 *)(arg1 + 0x8C);
        fadeIn = (s32)(*(f32 *)(arg1 + 0x78) * (f32)frames);
        fadeOut = (s32)(*(f32 *)(arg1 + 0x7C) * (f32)frames);
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
            *(u32 *)(colors + 0) = 0xFFFFFF;
            *(u32 *)(colors + 4) = ((u32)(opacity * 255.0f) << 24) | 0xFFFFFF;
            *(PolygonWindColor *)(colors + 8) = *(PolygonWindColor *)(colors + 4);
            *(u32 *)(colors + 12) = 0xFFFFFF;
            colors += 0x10;
            *(u32 *)(vertices + 0) = 0;
            *(f32 *)(vertices + 8) = step;
            *(f32 *)(vertices + 0x10) = step * 2.0f;
            *(f32 *)(vertices + 0x18) = step * 3.0f;
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
        model = *(u16 **)(arg0 + 4);
        geometry = *(u8 **)(*(u8 **)((u8 *)model + 0x10) + 0x18);
        func_003c22f0(geometry);
        if ((*model & 4) != 0) {
            *(u16 *)(geometry + 0xC) |= 1;
        }
    }
}

