#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
struct RwMatrixTag;
#include "rw_types_internal.h"
#include "psc_model_internal.h"
typedef struct {
    s32 lo;
    s32 hi;
} P4Pair;
typedef struct {
    f32 x;
    f32 y;
} PairF32;
typedef union {
    s64 raw;
    PairF32 f;
} PairBits;
typedef struct PersonaWork PersonaWork;


extern f32 iGpffff84a4;
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y,
                          u8 alphaSubtract, u8 red, u8 green, u8 blue,
                          f32 z, s32 setStates);
extern char D_005E5810[];
extern char D_005E57F0[];
extern char D_005E5850[];
extern char D_005E5830[];
extern char D_0064E460[];
extern char D_0064E280[];

extern f32 cosf(f32);
extern void sflDataInitPanel(u8 *work);
extern void pscLightInitQuad(u8 *dst);
extern f32 fGpffff8390;
extern f32 fGpffff8394;
extern u16 D_008C024E[];
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 pad0;
    f32 u;
    f32 v;
    f32 w;
    f32 pad1;
    f32 r;
    f32 g;
    f32 b;
    f32 a;
    f32 pad2[4];
} P4Vertex66C70;
typedef struct {
    s32 matrix[16];
    P4Vertex66C70 vertices[4];
    s32 config[8];
    u8 local[0x30];
} P4DrawFrame66C70;
typedef void (*P4RenderState66C70)(s32 state, s32 value);
extern RwV3d *func_003e4320(RwV3d *dst, const RwV3d *src,
                           const struct RwMatrixTag *matrix);
extern f32 sinf(f32);
extern s32 D_0064E440[];
extern f32 D_008872F8[];
extern P4RenderState66C70 D_00887300[];
extern s32 (*D_00887310[])(s32 arg0, void *arg1, s32 arg2);
extern f32 iGpffff8040;
extern f32 fGpffff8198;

extern void pscModelBuildTileVertices(u8 *mesh, u8 *model);
/* Keep the angle and shared scale local to each primitive call. */
#pragma push
#pragma pop
/* Initialises a shuffle-card panel model in mode 3: its sub-panel, light quad, corner positions,
 * colours and timing constants. */
// FUN_00368D30
void pscModelInitPanel(u8 *model)
{
    RwV3d upperRight;
    RwV3d upperLeft;
    RwV3d lowerLeft;
    RwV3d lowerRight;
    u8 color;

    sflDataInitPanel(model);
    ((PscModel *)model)->mode = 3;
    pscLightInitQuad(model + 0xE0);
    upperRight.x = 3.0f;
    upperRight.y = fGpffff8390;
    upperRight.z = 0.0f;
    *(RwV3d *)&((PscModel *)model)->u.w170[0].dir = upperRight;
    upperLeft.x = -3.0f;
    upperLeft.y = upperRight.y;
    upperLeft.z = 0.0f;
    *(RwV3d *)&((PscModel *)model)->u.w170[1].dir = upperLeft;
    lowerLeft.x = -3.0f;
    lowerLeft.y = fGpffff8394;
    lowerLeft.z = 0.0f;
    *(RwV3d *)&((PscModel *)model)->u.w170[2].dir = lowerLeft;
    lowerRight.x = 3.0f;
    lowerRight.y = lowerLeft.y;
    lowerRight.z = 0.0f;
    *(RwV3d *)&((PscModel *)model)->u.w170[3].dir = lowerRight;
    color = 0xFF;
    ((PscModel *)model)->u.w170[0].c[0] = color;
    ((PscModel *)model)->u.w170[0].c[1] = color;
    ((PscModel *)model)->u.w170[0].c[2] = color;
    ((PscModel *)model)->u.w170[0].c[3] = color;
    ((PscModel *)model)->u.w170[1].c[0] = color;
    ((PscModel *)model)->u.w170[1].c[1] = color;
    ((PscModel *)model)->u.w170[1].c[2] = color;
    ((PscModel *)model)->u.w170[1].c[3] = color;
    ((PscModel *)model)->u.w170[2].c[0] = color;
    ((PscModel *)model)->u.w170[2].c[1] = color;
    ((PscModel *)model)->u.w170[2].c[2] = color;
    ((PscModel *)model)->u.w170[2].c[3] = color;
    ((PscModel *)model)->u.w170[3].c[0] = color;
    ((PscModel *)model)->u.w170[3].c[1] = color;
    ((PscModel *)model)->u.w170[3].c[2] = color;
    ((PscModel *)model)->u.w170[3].c[3] = color;
    *(u32 *)&((PscModel *)model)->u.w170[0].f1c = 0x3F7E0000;
    *(u32 *)&((PscModel *)model)->u.w170[1].f1c = 0;
    *(u32 *)&((PscModel *)model)->u.w170[2].f1c = 0;
    *(u32 *)&((PscModel *)model)->u.w170[3].f1c = 0x3F7E0000;
    *(u32 *)&((PscModel *)model)->u.w170[0].f20 = 0x3C000000;
    *(u32 *)&((PscModel *)model)->u.w170[1].f20 = 0x3C000000;
    *(u32 *)&((PscModel *)model)->u.w170[2].f20 = 0x3F230000;
    *(u32 *)&((PscModel *)model)->u.w170[3].f20 = 0x3F230000;
}

/* measured: retail hoists the 0.5f loop constants out of the corner loops. */
#pragma push
/* measured: retail hoists loop-invariant corner-center values out of the tile loops in
 * pscModelStepAnimation. */
#pragma opt_loop_invariants on
// Advances a panel's animation timer and mode-specific UV and pulse phases, expires timed
// transitions, and rebuilds enabled tile meshes.
// FUN_00368E80
void pscModelStepAnimation(u8 *model)
{
    PscModel *panelModel;
    extern f32 D_007612D0;
    extern f32 fGpffff838c;
    extern void pscModelBuildTileVertices(u8 *mesh, u8 *model);
    u8 *base;
    s32 mode;
    f32 elapsedCycles;
    f32 fastPhase;
    f32 slowPhase;
    f32 pulsePhase;
    f32 bobPhase;
    f32 phaseProgress;
    f32 remainingPhase;
    f32 pulseSize;
    f32 pulseScale;
    f32 textureLow;
    f32 textureHigh;
    f32 angle;
    f32 pulseBase;
    s32 i;
    s32 j;
    s32 k;
    f32 rotatingUv[8];

    base = model;
    panelModel = (PscModel *)base;
    ((PscModel *)base)->elapsed += iGpffff8040;
    mode = ((PscModel *)base)->mode;
    switch (mode) {
    case 0:
    elapsedCycles = panelModel->elapsed / 3.0f;
    fastPhase = elapsedCycles - (f32)(s32)elapsedCycles;
    ((PscModel *)base)->u.m01.b2[0].f20 = fastPhase;
    ((PscModel *)base)->u.m01.b2[1].f20 = fastPhase;
    ((PscModel *)base)->u.m01.b2[2].f20 = 1.0f + fastPhase;
    ((PscModel *)base)->u.m01.b2[3].f20 = 1.0f + fastPhase;
    elapsedCycles = panelModel->elapsed / 16.0f;
    slowPhase = elapsedCycles - (f32)(s32)elapsedCycles;
    ((PscModel *)base)->u.m01.b3[0].f20 = slowPhase;
    ((PscModel *)base)->u.m01.b3[1].f20 = slowPhase;
    ((PscModel *)base)->u.m01.b3[2].f20 = 1.0f + slowPhase;
    ((PscModel *)base)->u.m01.b3[3].f20 = 1.0f + slowPhase;
    elapsedCycles = panelModel->elapsed / 4.0f;
    pulsePhase = elapsedCycles - (f32)(s32)elapsedCycles;
    if (pulsePhase < 0.5f) {
        pulseBase = fGpffff8198;
        ((PscModel *)base)->u.m01.b8[0].dir.y = pulseBase + ((pulseBase * pulsePhase) / 0.5f);
    } else {
        phaseProgress = (pulsePhase - 0.5f) / 0.5f;
        remainingPhase = 1.0f - phaseProgress;
        pulseBase = fGpffff8198;
        pulseSize = pulseBase + pulseBase * remainingPhase;
        ((PscModel *)base)->u.m01.b8[0].dir.y = pulseSize;
    }
    elapsedCycles = panelModel->elapsed / 2.0f;
    bobPhase = elapsedCycles - (f32)(s32)elapsedCycles;
    if (bobPhase < 0.5f) {
        ((PscModel *)base)->u.m01.b8[0].dir.x = (0.5f * bobPhase) / 0.5f;
    } else {
        ((PscModel *)base)->u.m01.b8[0].dir.x = 0.5f * (1.0f - ((bobPhase - 0.5f) / 0.5f));
    }
    pulseSize = 100.0f + 20.0f * bobPhase;
    pulseScale = pulseSize / 100.0f;
    textureHigh = 0.5f + (0.38671875f / pulseScale);
    ((PscModel *)base)->u.m01.b6[0].f1c = textureHigh;
    textureLow = 0.5f - (0.38671875f / pulseScale);
    ((PscModel *)base)->u.m01.b6[1].f1c = textureLow;
    ((PscModel *)base)->u.m01.b6[2].f1c = textureLow;
    ((PscModel *)base)->u.m01.b6[3].f1c = textureHigh;
    textureLow = 0.5f - (0.41015625f / pulseScale);
    ((PscModel *)base)->u.m01.b6[0].f20 = textureLow;
    ((PscModel *)base)->u.m01.b6[1].f20 = textureLow;
    textureLow = 0.5f + (0.41015625f / pulseScale);
    ((PscModel *)base)->u.m01.b6[2].f20 = textureLow;
    ((PscModel *)base)->u.m01.b6[3].f20 = textureLow;
        break;
    case 1:
    elapsedCycles = panelModel->elapsed / 2.0f;
    bobPhase = elapsedCycles - (f32)(s32)elapsedCycles;
    if (bobPhase < 0.5f) {
        ((PscModel *)base)->u.m01.b3[0].dir.y = (fGpffff838c * bobPhase) / 0.5f;
    } else {
        phaseProgress = (bobPhase - 0.5f) / 0.5f;
        remainingPhase = 1.0f - phaseProgress;
        ((PscModel *)base)->u.m01.b3[0].dir.y = fGpffff838c * remainingPhase;
    }
    pulseSize = 70.0f + 20.0f * bobPhase;
    pulseScale = pulseSize / 100.0f;
    textureHigh = 0.5f + (0.38671875f / pulseScale);
    ((PscModel *)base)->u.m01.b2[0].f1c = textureHigh;
    textureLow = 0.5f - (0.38671875f / pulseScale);
    ((PscModel *)base)->u.m01.b2[1].f1c = textureLow;
    ((PscModel *)base)->u.m01.b2[2].f1c = textureLow;
    ((PscModel *)base)->u.m01.b2[3].f1c = textureHigh;
    textureLow = 0.5f - (0.41015625f / pulseScale);
    ((PscModel *)base)->u.m01.b2[0].f20 = textureLow;
    ((PscModel *)base)->u.m01.b2[1].f20 = textureLow;
    textureLow = 0.5f + (0.41015625f / pulseScale);
    ((PscModel *)base)->u.m01.b2[2].f20 = textureLow;
    ((PscModel *)base)->u.m01.b2[3].f20 = textureLow;
        break;
    }
    if (((*(s32 *)base) & 2) != 0) {
        switch (panelModel->mode) {
        case 0: {
            f32 *uv;
            f32 *uvY;
            f32 y;
            f32 x;
            f32 nx;
            f32 ny;
            rotatingUv[0] = 1.0f;
            rotatingUv[1] = 1.0f;
            rotatingUv[2] = 0.0f;
            rotatingUv[3] = 1.0f;
            rotatingUv[4] = 0.0f;
            rotatingUv[5] = 0.0f;
            rotatingUv[6] = 1.0f;
            rotatingUv[7] = 0.0f;
            angle = D_007612D0 * (panelModel->elapsed / 4.0f);
            for (i = 0; i < 4; i++) {
                uv = &rotatingUv[i * 2];
                uv[0] -= 0.5f;
                uv[1] -= 0.5f;
            }
            for (j = 0; j < 4; j++) {
                uv = &rotatingUv[j * 2];
                uvY = uv + 1;
                y = uvY[0];
                x = uv[0];
                nx = x * cosf(angle) - y * sinf(angle);
                ny = x * sinf(angle) + y * cosf(angle);
                uv[0] = nx;
                uvY[0] = ny;
            }
            for (k = 0; k < 4; k++) {
                uv = &rotatingUv[k * 2];
                uv[0] += 0.5f;
                uv[1] += 0.5f;
            }
            ((PscModel *)base)->u.m01.b7[0].f1c = rotatingUv[0];
            ((PscModel *)base)->u.m01.b7[0].f20 = rotatingUv[1];
            ((PscModel *)base)->u.m01.b7[1].f1c = rotatingUv[2];
            ((PscModel *)base)->u.m01.b7[1].f20 = rotatingUv[3];
            ((PscModel *)base)->u.m01.b7[2].f1c = rotatingUv[4];
            ((PscModel *)base)->u.m01.b7[2].f20 = rotatingUv[5];
            ((PscModel *)base)->u.m01.b7[3].f1c = rotatingUv[6];
            ((PscModel *)base)->u.m01.b7[3].f20 = rotatingUv[7];
            break;
        }
        }
    }
    if (((*(s32 *)base) & 1) != 0) {
        ((PscModel *)base)->transitionTime += 0x10000;
        switch (((PscModel *)base)->unk48) {
        case 0:
            if ((u32)panelModel->transitionTime >= 0x1E0000U) {
                *(s32 *)base &= ~1;
            }
            break;
        case 1:
            break;
        }
    }
    if (((*(s32 *)base) & 8) != 0) {
        pscModelBuildTileVertices(((PscModel *)base)->unkDC, base);
    }
}

#pragma pop
