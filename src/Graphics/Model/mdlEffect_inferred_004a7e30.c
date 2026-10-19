#include "rw_camera_internal.h"
#include "mdl_effect_drawable_internal.h"
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
extern u8 *mdlEffectCreateGridForRecord(u8 *parameters);
extern u8 D_0071413C[];
extern f32 iGpffff8080;

extern void (*D_008873ec[])(void *);

extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern s32 kwlnGetCamera(void);
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



extern void RpSkyRenderStateGet(s32 param, void *out);
extern void RpSkyRenderStateSet(s32 param, s32 value);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887314[])(s32, void *, s32, void *, s32);
extern u8 D_00714368[];
extern void mdlEffectEmitValuePacket(s64 arg);
extern void mdlEffectEmitSlotPacket(void);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 parameters, s32 vertices, s32 count, s32 flags,
                          void *data, s32 options);
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
extern void (*jtbl_008873EC[])(void *);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004a7e30-004a8890 */

/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: close loop-invariant hoisting after mdlEffectCreateGridForRecord. */
#pragma push
#pragma tailcall off
/* measured: restore the enclosing options; owner verification is 92/92 MATCH. */
#pragma pop
/* measured: the byte->float sites are `(f32)(u32)x`; the eight rotated-corner stores add the
   centre offset inside the store expression (`*(f32 *)(vertices + 0x10) = centerU + component;`):
   assigning back into component makes mwcc put the coalesced operand first (add.s f1,f1,f26),
   a fresh destination keeps retail's add.s f1,f26,f1. */
/* measured: loop-invariant conversion preloads for func_004a7e30. */
/* measured: func_004a7e30 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_004A7E30
s32 mdlEffectProjectBillboardQuad(u8 *parameters, u8 *vertices)
{
    extern f32 cosf(f32 parameters);
    extern f32 sinf(f32 parameters);
    extern f32 fabsf(f32 parameters);
    f32 value;
    f32 sine;
    f32 component;
    f32 centerU;
    f32 centerV;
    f32 leftU;
    f32 topV;
    f32 rightU;
    f32 bottomV;
    f32 cosine;
    f32 secondComponent;
    f32 firstComponent;
    f32 coordinate;
    f32 reciprocalDepth;
    f32 screenDepth;
    f32 firstValue;
    f32 secondValue;
    f32 thirdValue;
    f32 fourthValue;
    s32 firstWord;
    s32 secondWord;
    s32 thirdWord;
    s32 fourthWord;
    u32 vertexIndex;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;
    u8 *vertex;

    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    if (*(f32 *)(parameters + 0x18) > 640.0f ||
        ((MdlEffectBillboardParameters *)parameters)->top > 448.0f ||
        ((MdlEffectBillboardParameters *)parameters)->right < 0.0f ||
        ((MdlEffectBillboardParameters *)parameters)->bottom < 0.0f) {
        return 0;
    }
    red = ((MdlEffectBillboardParameters *)parameters)->color[0];
    green = ((MdlEffectBillboardParameters *)parameters)->color[1];
    blue = ((MdlEffectBillboardParameters *)parameters)->color[2];
    alpha = ((MdlEffectBillboardParameters *)parameters)->color[3];
    reciprocalDepth = 1.0f / ((RwCamera *)((u8 *)(u32)kwlnGetCamera()))->nearPlane;
    screenDepth = D_008872F8[0];
    vertexIndex = 0;
    goto loop_004a7e30_check;
loop_004a7e30_body:
    vertex = vertices + (vertexIndex << 6);
    ((MdlEffectScreenVertex *)vertex)[0].reciprocalDepth = reciprocalDepth;
    ((MdlEffectScreenVertex *)vertex)[0].red = (f32)(u32)red;
    ((MdlEffectScreenVertex *)vertex)[0].green = (f32)(u32)green;
    ((MdlEffectScreenVertex *)vertex)[0].blue = (f32)(u32)blue;
    ((MdlEffectScreenVertex *)vertex)[0].alpha = (f32)(u32)alpha;
    ((MdlEffectScreenVertex *)vertex)[0].z = screenDepth;
    vertexIndex += 1;
loop_004a7e30_check:
    if (vertexIndex < 4U) {
        goto loop_004a7e30_body;
    }
    centerU = ((MdlEffectBillboardParameters *)parameters)->centerX / D_00922D94[0];
    centerV = ((MdlEffectBillboardParameters *)parameters)->centerY / D_00922D98[0];
    reciprocalDepth = ((MdlEffectBillboardParameters *)parameters)->scale;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    screenDepth = *(f32 *)(parameters + 0x18);
    coordinate = screenDepth / D_00922D94[0];
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    firstComponent = *(f32 *)(parameters + 0x1C) / D_00922D98[0];
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    secondComponent = *(f32 *)(parameters + 0x20) / D_00922D94[0];
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    component = *(f32 *)(parameters + 0x24) / D_00922D98[0];
    value = coordinate - centerU;
    leftU = reciprocalDepth * value;
    value = firstComponent - centerV;
    topV = reciprocalDepth * value;
    value = secondComponent - centerU;
    rightU = reciprocalDepth * value;
    value = component - centerV;
    bottomV = reciprocalDepth * value;
    value = leftU - rightU;
    firstComponent = fabsf(value);
    value = topV - bottomV;
    secondComponent = fabsf(value);
    if (!(firstComponent > 0.0f &&
          secondComponent > 0.0f &&
          firstComponent < 7.0f &&
          secondComponent < 7.0f)) {
        return 0;
    }
    ((MdlEffectScreenVertex *)vertices)[0].x = screenDepth;
    ((MdlEffectScreenVertex *)vertices)[0].y = ((MdlEffectBillboardParameters *)parameters)->top;
    ((MdlEffectScreenVertex *)vertices)[1].x = ((MdlEffectBillboardParameters *)parameters)->left;
    ((MdlEffectScreenVertex *)vertices)[1].y = ((MdlEffectBillboardParameters *)parameters)->bottom;
    ((MdlEffectScreenVertex *)vertices)[2].x = ((MdlEffectBillboardParameters *)parameters)->right;
    ((MdlEffectScreenVertex *)vertices)[2].y = ((MdlEffectBillboardParameters *)parameters)->bottom;
    ((MdlEffectScreenVertex *)vertices)[3].x = ((MdlEffectBillboardParameters *)parameters)->right;
    ((MdlEffectScreenVertex *)vertices)[3].y = ((MdlEffectBillboardParameters *)parameters)->top;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    if (*(f32 *)(parameters + 8) == 0.0f) {
        firstComponent = leftU + centerU;
        secondComponent = rightU + centerU;
        component = topV + centerV;
        value = bottomV + centerV;
        ((MdlEffectScreenVertex *)vertices)[0].u.value = firstComponent;
        ((MdlEffectScreenVertex *)vertices)[0].v.value = component;
        ((MdlEffectScreenVertex *)vertices)[1].u.value = firstComponent;
        ((MdlEffectScreenVertex *)vertices)[1].v.value = value;
        ((MdlEffectScreenVertex *)vertices)[2].u.value = secondComponent;
        ((MdlEffectScreenVertex *)vertices)[2].v.value = value;
        ((MdlEffectScreenVertex *)vertices)[3].u.value = secondComponent;
        ((MdlEffectScreenVertex *)vertices)[3].v.value = component;
    } else {
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        cosine = cosf(*(f32 *)(parameters + 8));
        sine = sinf(((MdlEffectBillboardParameters *)parameters)->angle);
        reciprocalDepth = topV * sine;
        firstComponent = leftU * cosine;
        component = firstComponent - reciprocalDepth;
                ((MdlEffectScreenVertex *)vertices)[0].u.value = centerU + component;
        screenDepth = topV * cosine;
        secondComponent = leftU * sine;
        component = secondComponent + screenDepth;
                ((MdlEffectScreenVertex *)vertices)[0].v.value = centerV + component;
        coordinate = bottomV * sine;
        component = firstComponent - coordinate;
                ((MdlEffectScreenVertex *)vertices)[1].u.value = centerU + component;
        firstComponent = bottomV * cosine;
        component = secondComponent + firstComponent;
                ((MdlEffectScreenVertex *)vertices)[1].v.value = centerV + component;
        secondComponent = rightU * cosine;
        component = secondComponent - coordinate;
                ((MdlEffectScreenVertex *)vertices)[2].u.value = centerU + component;
        component = rightU * sine;
        value = component + firstComponent;
                ((MdlEffectScreenVertex *)vertices)[2].v.value = centerV + value;
        value = secondComponent - reciprocalDepth;
                ((MdlEffectScreenVertex *)vertices)[3].u.value = centerU + value;
        value = component + screenDepth;
                ((MdlEffectScreenVertex *)vertices)[3].v.value = centerV + value;
    }
    return 1;
}

/* measured: close the loop-invariant bracket after func_004a7e30. */
/* Build four screen vertices with rectangle coordinates, normalized UV corners and the input tint. */
// FUN_004A8250
/* measured: loop-invariant conversion preloads for func_004a8250. */
void mdlEffectBuildRectQuad(u8 *parameters, u8 *vertices)
{
    f32 reciprocalDepth;
    f32 screenDepth;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;
    u32 index;
    u8 *currentVertex;

    red = ((MdlEffectBillboardParameters *)parameters)->color[0];
    green = ((MdlEffectBillboardParameters *)parameters)->color[1];
    blue = ((MdlEffectBillboardParameters *)parameters)->color[2];
    alpha = ((MdlEffectBillboardParameters *)parameters)->color[3];
    reciprocalDepth = 1.0f / ((RwCamera *)((u8 *)(u32)kwlnGetCamera()))->nearPlane;
    screenDepth = D_008872F8[0];
    index = 0;
    goto loop_004a8250_check;
loop_004a8250_body:
    currentVertex = vertices + (index << 6);
    ((MdlEffectScreenVertex *)currentVertex)[0].reciprocalDepth = reciprocalDepth;
    ((MdlEffectScreenVertex *)currentVertex)[0].red = (f32)(u32)red;
    ((MdlEffectScreenVertex *)currentVertex)[0].green = (f32)(u32)green;
    ((MdlEffectScreenVertex *)currentVertex)[0].blue = (f32)(u32)blue;
    ((MdlEffectScreenVertex *)currentVertex)[0].alpha = (f32)(u32)alpha;
    ((MdlEffectScreenVertex *)currentVertex)[0].z = screenDepth;
    index += 1;
loop_004a8250_check:
    if (index < 4U) {
        goto loop_004a8250_body;
    }
    ((MdlEffectScreenVertex *)vertices)[0].x = ((MdlEffectBillboardParameters *)parameters)->left;
    ((MdlEffectScreenVertex *)vertices)[0].y = ((MdlEffectBillboardParameters *)parameters)->top;
    ((MdlEffectScreenVertex *)vertices)[1].x = ((MdlEffectBillboardParameters *)parameters)->left;
    ((MdlEffectScreenVertex *)vertices)[1].y = ((MdlEffectBillboardParameters *)parameters)->bottom;
    ((MdlEffectScreenVertex *)vertices)[2].x = ((MdlEffectBillboardParameters *)parameters)->right;
    ((MdlEffectScreenVertex *)vertices)[2].y = ((MdlEffectBillboardParameters *)parameters)->bottom;
    ((MdlEffectScreenVertex *)vertices)[3].x = ((MdlEffectBillboardParameters *)parameters)->right;
    ((MdlEffectScreenVertex *)vertices)[3].y = ((MdlEffectBillboardParameters *)parameters)->top;
    ((MdlEffectScreenVertex *)vertices)[0].u.bits = 0;
    ((MdlEffectScreenVertex *)vertices)[0].v.bits = 0;
    ((MdlEffectScreenVertex *)vertices)[1].u.bits = 0;
    ((MdlEffectScreenVertex *)vertices)[1].v.bits = 0x3F800000;
    ((MdlEffectScreenVertex *)vertices)[2].u.bits = 0x3F800000;
    ((MdlEffectScreenVertex *)vertices)[2].v.bits = 0x3F800000;
    ((MdlEffectScreenVertex *)vertices)[3].u.bits = 0x3F800000;
    ((MdlEffectScreenVertex *)vertices)[3].v.bits = 0;
}

/* measured: close loop-invariant conversion scope for func_004a8250. */
/* Build rectangle vertices with UVs shifted by the angle and magnitude in the input parameters. */
// FUN_004A8440
/* measured: loop-invariant conversion preloads for func_004a8440. */
void mdlEffectBuildOffsetQuad(u8 *parameters, u8 *vertices)
{
    extern f32 fGpffff8090;
    extern f32 sinf(f32 parameters);
    extern f32 cosf(f32 parameters);
    f32 value;
    f32 component;
    f32 verticalOffset;
    f32 horizontalOffset;
    f32 angleRadians;
    f32 secondComponent;
    f32 coordinate;
    f32 reciprocalDepth;
    f32 screenDepth;
    f32 firstValue;
    f32 secondValue;
    f32 thirdValue;
    f32 fourthValue;
    u32 index;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;
    u8 *currentVertex;

    red = ((MdlEffectBillboardParameters *)parameters)->color[0];
    green = ((MdlEffectBillboardParameters *)parameters)->color[1];
    blue = ((MdlEffectBillboardParameters *)parameters)->color[2];
    alpha = ((MdlEffectBillboardParameters *)parameters)->color[3];
    angleRadians = fGpffff8090 * ((MdlEffectBillboardParameters *)parameters)->angle;
    horizontalOffset = ((MdlEffectBillboardParameters *)parameters)->scale;
    verticalOffset = horizontalOffset * sinf(angleRadians);
    horizontalOffset = horizontalOffset * cosf(angleRadians);
    reciprocalDepth = 1.0f / ((RwCamera *)((u8 *)(u32)kwlnGetCamera()))->nearPlane;
    screenDepth = D_008872F8[0];
    index = 0;
    goto loop_004a8440_check;
loop_004a8440_body:
    currentVertex = vertices + (index << 6);
    ((MdlEffectScreenVertex *)currentVertex)[0].reciprocalDepth = reciprocalDepth;
    ((MdlEffectScreenVertex *)currentVertex)[0].red = (f32)(u32)red;
    ((MdlEffectScreenVertex *)currentVertex)[0].green = (f32)(u32)green;
    ((MdlEffectScreenVertex *)currentVertex)[0].blue = (f32)(u32)blue;
    ((MdlEffectScreenVertex *)currentVertex)[0].alpha = (f32)(u32)alpha;
    ((MdlEffectScreenVertex *)currentVertex)[0].z = screenDepth;
    index += 1;
loop_004a8440_check:
    if (index < 4U) {
        goto loop_004a8440_body;
    }
    ((MdlEffectScreenVertex *)vertices)[0].x = ((MdlEffectBillboardParameters *)parameters)->left;
    ((MdlEffectScreenVertex *)vertices)[0].y = ((MdlEffectBillboardParameters *)parameters)->top;
    ((MdlEffectScreenVertex *)vertices)[1].x = ((MdlEffectBillboardParameters *)parameters)->left;
    ((MdlEffectScreenVertex *)vertices)[1].y = ((MdlEffectBillboardParameters *)parameters)->bottom;
    ((MdlEffectScreenVertex *)vertices)[2].x = ((MdlEffectBillboardParameters *)parameters)->right;
    ((MdlEffectScreenVertex *)vertices)[2].y = ((MdlEffectBillboardParameters *)parameters)->bottom;
    ((MdlEffectScreenVertex *)vertices)[3].x = ((MdlEffectBillboardParameters *)parameters)->right;
    ((MdlEffectScreenVertex *)vertices)[3].y = ((MdlEffectBillboardParameters *)parameters)->top;
    coordinate = (((MdlEffectBillboardParameters *)parameters)->left + verticalOffset) / D_00922D94[0];
    secondComponent = (((MdlEffectBillboardParameters *)parameters)->top + horizontalOffset) / D_00922D98[0];
    component = (((MdlEffectBillboardParameters *)parameters)->right + verticalOffset) / D_00922D94[0];
    value = (((MdlEffectBillboardParameters *)parameters)->bottom + horizontalOffset) / D_00922D98[0];
    ((MdlEffectScreenVertex *)vertices)[0].u.value = coordinate;
    ((MdlEffectScreenVertex *)vertices)[0].v.value = secondComponent;
    ((MdlEffectScreenVertex *)vertices)[1].u.value = coordinate;
    ((MdlEffectScreenVertex *)vertices)[1].v.value = value;
    ((MdlEffectScreenVertex *)vertices)[2].u.value = component;
    ((MdlEffectScreenVertex *)vertices)[2].v.value = value;
    ((MdlEffectScreenVertex *)vertices)[3].u.value = component;
    ((MdlEffectScreenVertex *)vertices)[3].v.value = secondComponent;
}

/* measured: close loop-invariant conversion scope for func_004a8440. */
/* Copy rectangle bounds and tint to four screen vertices without modifying UVs. */
// FUN_004A86C0
/* measured: loop-invariant conversion preloads for func_004a86c0. */
void mdlEffectBuildDirectRectQuad(u8 *parameters, u8 *vertices)
{
    f32 reciprocalDepth;
    f32 screenDepth;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;
    u32 index;
    u8 *currentVertex;

    red = ((MdlEffectBillboardParameters *)parameters)->color[0];
    green = ((MdlEffectBillboardParameters *)parameters)->color[1];
    blue = ((MdlEffectBillboardParameters *)parameters)->color[2];
    alpha = ((MdlEffectBillboardParameters *)parameters)->color[3];
    reciprocalDepth = 1.0f / ((RwCamera *)((u8 *)(u32)kwlnGetCamera()))->nearPlane;
    screenDepth = D_008872F8[0];
    index = 0;
    goto loop_004a86c0_check;
loop_004a86c0_body:
    currentVertex = vertices + (index << 6);
    ((MdlEffectScreenVertex *)currentVertex)[0].reciprocalDepth = reciprocalDepth;
    ((MdlEffectScreenVertex *)currentVertex)[0].red = (f32)(u32)red;
    ((MdlEffectScreenVertex *)currentVertex)[0].green = (f32)(u32)green;
    ((MdlEffectScreenVertex *)currentVertex)[0].blue = (f32)(u32)blue;
    ((MdlEffectScreenVertex *)currentVertex)[0].alpha = (f32)(u32)alpha;
    ((MdlEffectScreenVertex *)currentVertex)[0].z = screenDepth;
    index += 1;
loop_004a86c0_check:
    if (index < 4U) {
        goto loop_004a86c0_body;
    }
    ((MdlEffectScreenVertex *)vertices)[0].x = ((MdlEffectBillboardParameters *)parameters)->angle;
    ((MdlEffectScreenVertex *)vertices)[0].y = ((MdlEffectBillboardParameters *)parameters)->scale;
    ((MdlEffectScreenVertex *)vertices)[1].x = ((MdlEffectBillboardParameters *)parameters)->angle;
    ((MdlEffectScreenVertex *)vertices)[1].y = ((MdlEffectBillboardParameters *)parameters)->centerY;
    ((MdlEffectScreenVertex *)vertices)[2].x = ((MdlEffectBillboardParameters *)parameters)->centerX;
    ((MdlEffectScreenVertex *)vertices)[2].y = ((MdlEffectBillboardParameters *)parameters)->centerY;
    ((MdlEffectScreenVertex *)vertices)[3].x = ((MdlEffectBillboardParameters *)parameters)->centerX;
    ((MdlEffectScreenVertex *)vertices)[3].y = ((MdlEffectBillboardParameters *)parameters)->scale;
}

/* measured: close loop-invariant conversion scope for func_004a86c0. */
/* Draw the base and projected billboard passes while saving and restoring the sky render state. */
// FUN_004A8890
void mdlEffectDrawProjectedBillboard(u8 *effect, s32 *textureSource) {
    s32 savedTest;
    s32 savedAlpha;
    u8 baseVertices[0xFC];
    u8 projectedVertices[0x100];
    s32 *textureHandle;
    u8 *unusedGeometry;
    u8 *unusedWork;
    void (**setState)(u32, u32);
    void (**sendPacket)(s32, void *, s32, void *, s32);

    textureHandle = textureSource;
    RpSkyRenderStateGet(2, &savedTest);
    RpSkyRenderStateGet(3, &savedAlpha);
    setState = (void (**)(u32, u32))D_00887300;
    (*setState)((u32)1, *(u32 *)textureHandle);
    mdlEffectEmitMaskedTagPair();
    RpSkyRenderStateSet(2, 0x44);
    RpSkyRenderStateSet(3, 0x31001);
    mdlEffectBuildRectQuad(effect + 4, baseVertices);
    sendPacket = (void (**)(s32, void *, s32, void *, s32))D_00887314;
    (*sendPacket)(3, baseVertices, 4, D_00714368, 6);
    mdlEffectEmitTagPair();
    RpSkyRenderStateSet(2, savedTest | 0x10);
    if (mdlEffectProjectBillboardQuad(effect + 4, projectedVertices) != 0) {
        (*setState)(1, D_00922D90[0]);
        RpSkyRenderStateSet(3, 0x31001);
        mdlEffectEmitValuePacket(0x9FC00A | ((s64)0x6FC << 0x20));
        (*sendPacket)(3, projectedVertices, 4, D_00714368, 6);
        mdlEffectEmitSlotPacket();
    }
    (*setState)(1, 0);
    RpSkyRenderStateSet(3, savedAlpha);
    RpSkyRenderStateSet(2, savedTest);
}

