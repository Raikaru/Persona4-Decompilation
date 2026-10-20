/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00383c00-0038d330 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "kwln_task_internal.h"
#include "btl_effect_internal.h"
#include "mdl_effect_internal.h"
#include "type.h"
#include "btl_shuffle_state_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_shuffle_draw_internal.h"
#include "shd_misc_internal.h"
#include "sdk_snd_internal.h"
#include "ed_staff_internal.h"
#include "datPersona_internal.h"
extern void (*jtbl_008873EC[])(void *);
extern void (*D_008873ec[])(s32);
void btlShuffleDrawViewRequestStep(u8 *drawWork, u8 input, u8 green, u8 blue);
void btlShuffleDrawViewRequestWhiteStep(u8 *drawWork);
extern void memset(void *dst, s32 value, u32 size);
extern s32 btlShuffleDrawCheck(u8 *context, u8 *output);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_0064ECA0[];
extern u8 D_0064EED0[];
extern void btlShuffleInitWaveStrips(u8 *drawWork);
extern void btlShuffleDrawCardReset(u8 *drawWork);
extern void btlShuffleDrawViewForeground(s32 drawWork, u8 *input);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void btlShuffleDrawViewClearFlags(u8 *drawWork);
extern void btlShuffleDrawViewBackground(s32 drawWork, u8 *input);
extern s32 btlShuffleDrawViewStep(u8 *drawWork);
extern void btlShuffleDrawViewDestroy(u8 *drawWork);
extern u8 D_00794990[];
extern u8 D_00794E40[];
extern u8 D_00795E30[];
extern u8 D_00795EF0[];
extern u8 D_0064EEB0[];
extern void PrimAppendNode(u8 *list, u8 *node);
extern void kAssertFail(void *file, s32 line);
extern void sdkRenderStateSetDefault(void);
extern void btlShuffleDrawRevealBands(u8 *drawWork);
extern void btlShuffleDrawDetailBars(u8 *drawWork);
extern void btlShuffleDrawCountTransition(u8 *drawWork);
extern void btlShuffleDrawCardShadow(u8 *drawWork);
extern void btlShuffleDrawSelectionColumn(u8 *drawWork);
extern f32 D_00761470;
extern f32 D_008872F8[];
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern s32 (*D_00887310[])(s32, void *, s32);
extern s32 kwlnGetCamera(void);
extern f32 cosf(f32 angle);
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern u8 D_0064F0E0[];
extern u8 D_0064EEF0[];
extern void btlShuffleDrawBackgroundPulse();
extern void btlShuffleDrawBackgroundRings();
extern void btlShuffleDrawWave();
extern void btlShuffleUpdateRing();
extern void btlShuffleDrawSpriteCues();
extern void sdkSpriteDrawOnceAt(s32 packAddress, s32 image, f32 x, f32 y,
                          u8 red, u8 green, u8 blue, u8 alpha);
extern void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y,
                          f32 depth, u8 red, u8 green, u8 blue, u8 alpha,
                          u16 scaleX, u16 scaleY, f32 angle, s16 pivotX,
                          s16 pivotY);
/* Each 0x30-byte wave strip has two endpoint pairs and independent phase counters. */
typedef struct BtlShuffleWaveStrip {
    Vec2f start[2];
    Vec2f end[2];
    u16 frame[2];
    u16 duration[2];
    f32 amplitude;
    u8 color[4];
} BtlShuffleWaveStrip;

/* Read-only draw tables have explicit 12-, 16-, 20- and 48-byte strides. */
typedef struct BtlShuffleParticlePoint { f32 x, y, phase; } BtlShuffleParticlePoint;
typedef struct BtlShuffleRevealBand { f32 distance, width, start, end; } BtlShuffleRevealBand;
typedef struct BtlShuffleBackgroundRing {
    u16 frame, duration;
    u8 alpha;
    u8 pad5[3];
    f32 angle;
} BtlShuffleBackgroundRing;
typedef struct BtlShuffleSpriteCue { f32 x, y; s32 start, end, sprite; } BtlShuffleSpriteCue;
typedef struct BtlShuffleWaveDefault {
    Vec2f start0, end0, start1, end1;
    f32 duration[2];
    f32 amplitude;
    u8 color[4];
} BtlShuffleWaveDefault;

static inline u32 btlShuffleAddWorkOffset(u32 offset, u32 base)
{
    return offset + base;
}

/* Test whether the roster task has a nonzero result. */
// FUN_00383C00
s32 btlShuffleRosterHasResult(u8 *drawWork)
{
    return ((BtlShuffleRosterWork *)((KwlnTask *)drawWork)->work)->result != 0;
}

/* Set the roster task request flag and return its result word. */
// FUN_00383C20
u32 btlShuffleRosterRequestResult(u8 *drawWork)
{
    u8 *p;

    p = ((KwlnTask *)drawWork)->work;
    ((BtlShuffleRosterWork *)p)->flags = ((BtlShuffleRosterWork *)p)->flags | 4;
    return ((BtlShuffleRosterWork *)p)->result;
}

// FUN_00383C40
void btlShuffleDrawCardSet(u8 *drawWork)
{
    u8 *base;
    s32 value;
    u8 colors[4];

    base = ((BtlShuffleDrawViewWork *)drawWork)->context;
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    switch (((BtlShuffleContext *)base)->pattern) {
    case 0:
    case 1:
    case 2:
        value = btlShuffleDrawCheck(base, 0);
        break;
    case 3:
        value = ((BtlShuffleContext *)base)->sequenceChoice;
        break;
    default:
        kAssertFail(D_0064EEB0, 0x103);
        break;
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    btlShuffleDrawCardSprites(base, value, 0, colors, 1);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

/* Pulse the opacity of the queued glow cards unless the sequence disables highlights. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 374..374); retain only the failing byte-base accesses. */
// FUN_00383D70
void btlShuffleDrawGlowCards(u8 *drawWork)
{
    extern f32 sinf(f32 angle);
    extern f32 iGpffff81e0;
    extern f32 fGpffff8198;
    extern f32 fGpffff809c;
    u8 *state;
    u8 *base;
    u8 *flags;
    s32 value;
    s32 i;
    u8 colors[4];
    f32 alpha;

    state = drawWork + 0x28;
    base = ((BtlShuffleDrawViewWork *)drawWork)->context;
    flags = base + 0x1F1D0;
    if ((*(u16 *)flags & 2) != 0 ||
        (*(u16 *)flags & 4) != 0) {
        return;
    }
    if (((BtlShuffleGlow *)state)->count <= 0) {
        return;
    }
    value = (((BtlShuffleGlow *)state)->frame + 1) % 30;
    ((BtlShuffleGlow *)state)->frame = value;
    colors[0] = 0;
    colors[1] = 70;
    colors[2] = 120;
    alpha = 255.0f *
        (fGpffff8198 * sinf((iGpffff81e0 *
                                     (f32)((BtlShuffleGlow *)state)->frame) / 30.0f) +
         fGpffff809c + 0.0f);
    colors[3] = (u8)alpha;
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    for (i = 0; i < *(s32 *)(state + 0x14); i++) {
        btlShuffleDrawCardSprites(base, ((BtlShuffleGlow *)state)->cards[i], 0,
                      colors, 0);
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

/* Fade grouped card frames and draw the two boundary strips for the current group. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 2325..2498); retain only the failing byte-base accesses. */
// FUN_00383F80
void btlShuffleDrawFrameFade(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern s32 btlShuffleDrawTableLookup(s32 cardCount, s32 pattern);
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
        u32 pad0;
        u32 pad1;
        u32 pad2;
        f32 scale;
        u32 pad3;
        f32 color[4];
        u32 tail[4];
    } Vertex;
    u8 *ctx;
    u8 *state;
    u8 *info;
    u8 colors[4];
    Vertex work[4];
    f32 depth;
    f32 reciprocalZ;
    f32 scale;
    u8 alpha;
    s32 stride;
    s32 count;
    s32 groupCount;
    s32 i;
    s32 lo;
    u32 draw;
    s32 j;
    s32 hi;
    u16 flags;
    s32 groupIndex;

    state = drawWork + 0x20;
    ctx = ((BtlShuffleDrawViewWork *)drawWork)->context;
    info = ctx + 0x1F1D0;
    flags = ((BtlShuffleAnimation *)state)->flags;
    if (!(flags & 1)) {
        scale = btlShuffleCalcWave((f32)(u32)((BtlShuffleAnimation *)state)->frame, 0.0f, 10.0f, 1);
        alpha = 255.0f * scale;
        if (++*(u16 *)(state + 2) >= 0xA) {
            ((BtlShuffleAnimation *)state)->flags = ((BtlShuffleAnimation *)state)->flags | 1;
            *(u16 *)(state + 2) = 0;
        }
    } else if (flags & 2) {
        scale = 1.0f - btlShuffleCalcWave((f32)(u32)((BtlShuffleAnimation *)state)->frame, 0.0f, 10.0f, 1);
        alpha = 255.0f * scale;
        if (++*(u16 *)(state + 2) >= 0xA) {
            ((BtlShuffleDrawViewWork *)drawWork)->flags = ((BtlShuffleDrawViewWork *)drawWork)->flags & 0xFFDF;
        }
    } else {
        scale = 1.0f;
        alpha = 0xFF;
    }
    groupIndex = *(u16 *)(info + 4);
    groupIndex = (groupIndex < 3) ? groupIndex : 2;
    groupCount = ((BtlShuffleContext *)ctx)->cardCount;
    stride = (groupCount < 6) ? groupCount * 2 : groupCount;
    count = btlShuffleDrawTableLookup(groupCount, ((BtlShuffleContext *)ctx)->pattern);
    depth = D_008872F8[0];
    reciprocalZ = 1.0f / ((MdlEffectCamera *)kwlnGetCamera())->nearPlane;
    colors[0] = 0x5F;
    colors[1] = 0x31;
    colors[2] = 0;
    colors[3] = (u8)(((alpha & 0xFF) * 0xC0) / 255);
    lo = stride * (groupIndex + 1);
    hi = count;
    for (i = lo; i < hi; i++) {
        btlShuffleDrawCardSprites(ctx, i, 0, colors, 0);
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    colors[0] = 0x50;
    colors[1] = 0x4B;
    colors[2] = 0x3C;
    colors[3] = (u8)(((alpha & 0xFF) << 7) / 255);
    lo = stride * groupIndex;
    hi = stride * (groupIndex + 1);
    for (j = lo; j < hi; j++) {
        btlShuffleDrawCardSprites(ctx, j, 0, colors, 0);
    }
    colors[0] = 0xFF;
    colors[1] = 0xC5;
    colors[2] = 0x50;
    work[0].x = 156.0f;
    work[0].y = 0.0f;
    work[0].z = depth;
    work[0].color[0] = (f32)(u32)colors[0];
    work[0].color[1] = (f32)(u32)colors[1];
    work[0].color[2] = (f32)(u32)colors[2];
    work[0].color[3] = (u8)(192.0f * scale);
    work[0].scale = reciprocalZ;
    work[1].x = (f32)0x1D9;
    work[1].y = 0.0f;
    work[1].z = depth;
    work[1].color[0] = (f32)(u32)colors[0];
    work[1].color[1] = (f32)(u32)colors[1];
    work[1].color[2] = (f32)(u32)colors[2];
    work[1].color[3] = (u8)(192.0f * scale);
    work[1].scale = reciprocalZ;
    work[2].x = 156.0f;
    work[2].y = 84.0f;
    work[2].z = depth;
    work[2].color[0] = (f32)(u32)colors[0];
    work[2].color[1] = (f32)(u32)colors[1];
    work[2].color[2] = (f32)(u32)colors[2];
    work[2].color[3] = 0.0f;
    work[2].scale = reciprocalZ;
    work[3].x = (f32)0x1D9;
    work[3].y = 84.0f;
    work[3].z = depth;
    work[3].color[0] = (f32)(u32)colors[0];
    work[3].color[1] = (f32)(u32)colors[1];
    work[3].color[2] = (f32)(u32)colors[2];
    work[3].color[3] = 0.0f;
    work[3].scale = reciprocalZ;
    draw = (u32)D_00887310;
    (*(s32 (**)(s32, void *, s32))draw)(4, work, 4);
    work[0].x = 156.0f;
    work[0].y = 364.0f;
    work[0].z = depth;
    work[0].color[0] = (f32)(u32)colors[0];
    work[0].color[1] = (f32)(u32)colors[1];
    work[0].color[2] = (f32)(u32)colors[2];
    work[0].color[3] = 0.0f;
    work[0].scale = reciprocalZ;
    work[1].x = (f32)0x1D9;
    work[1].y = 364.0f;
    work[1].z = depth;
    work[1].color[0] = (f32)(u32)colors[0];
    work[1].color[1] = (f32)(u32)colors[1];
    work[1].color[2] = (f32)(u32)colors[2];
    work[1].color[3] = 0.0f;
    work[1].scale = reciprocalZ;
    work[2].x = 156.0f;
    work[2].y = 448.0f;
    work[2].z = depth;
    work[2].color[0] = (f32)(u32)colors[0];
    work[2].color[1] = (f32)(u32)colors[1];
    work[2].color[2] = (f32)(u32)colors[2];
    work[2].color[3] = (u8)(192.0f * scale);
    work[2].scale = reciprocalZ;
    work[3].x = (f32)0x1D9;
    work[3].y = 448.0f;
    work[3].z = depth;
    work[3].color[0] = (f32)(u32)colors[0];
    work[3].color[1] = (f32)(u32)colors[1];
    work[3].color[2] = (f32)(u32)colors[2];
    work[3].color[3] = (u8)(192.0f * scale);
    work[3].scale = reciprocalZ;
    (*(s32 (**)(s32, void *, s32))draw)(4, work, 4);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

/* Line and icon fade for the selected shuffle pattern.
 * The halfword frame increment wraps before the phase test; byte
 * opacities and the shared point preserve the native call boundaries. */
// FUN_00384CC0
void btlShuffleDrawPatternLineFade(u8 *work)
{
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern f32 fGpffff83c0;
    extern f32 fGpffff83c4;
    extern const Vec2f D_0064ECC0[13];
    struct LineAnimation { u16 flags; u16 frame; } *state;
    u8 *base;
    u16 *patternFlags;
    s32 texture;
    Vec2f point;
    u16 flags;
    u16 nextFrame;
    f32 progress;
    u8 lineAlpha;
    u8 iconAlpha;
    u8 overlayAlpha;
    s32 packed;
    u16 mask;
    u32 selectedMask;
    u32 drawOverlay;
    s32 i;
    const Vec2f *entry;
    state = (struct LineAnimation *)(work + 0x24);
    base = *(u8 **)work;
    patternFlags = (u16 *)(base + 0x1F1D0);
    texture = ((BtlShuffleContext *)base)->spriteResource;
    mask = 0;
    if (((BtlShuffleContext *)base)->pattern != 4) {
        kAssertFail(D_0064EEB0, 459);
    }
    flags = state->flags;
    if ((flags & 1) == 0) {
        lineAlpha = 0;
        progress = (f32)state->frame;
        iconAlpha = (u8)(255.0f * btlShuffleCalcWave(progress, 0.0f, 5.0f, 1));
        overlayAlpha = 0;
        nextFrame = ++state->frame;
        if ((nextFrame & 0xFFFF) >= 5) {
            state->flags = state->flags | 1;
            state->flags = state->flags | 2;
            state->frame = 0;
        }
    } else if (flags & 2) {
        progress = (f32)state->frame;
        lineAlpha = (u8)(255.0f * btlShuffleCalcWave(progress, 0.0f, 3.0f, 1));
        iconAlpha = 0xFF;
        progress = (f32)state->frame;
        overlayAlpha = (u8)(255.0f * (1.0f - btlShuffleCalcWave(progress, 5.0f, 10.0f, 1)));
        nextFrame = ++state->frame;
        if ((nextFrame & 0xFFFF) >= 10) {
            state->flags = state->flags & 0xFFFD;
            state->frame = 0;
        }
    } else if (flags & 4) {
        progress = (f32)state->frame;
        lineAlpha = (u8)(255.0f * (1.0f - btlShuffleCalcWave(progress, 0.0f, 5.0f, 1)));
        overlayAlpha = lineAlpha;
        iconAlpha = lineAlpha;
        nextFrame = ++state->frame;
        if ((nextFrame & 0xFFFF) >= 10) {
            ((BtlShuffleDrawViewWork *)work)->flags = ((BtlShuffleDrawViewWork *)work)->flags & 0xFFBF;
            state->frame = 0;
        }
    } else {
        lineAlpha = 0xFF;
        iconAlpha = lineAlpha;
        overlayAlpha = 0;
    }
    point.x = 314.0f;
    point.y = 237.0f;
    packed = (lineAlpha & 0xFF) | 0x3767FF00;
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    if (*patternFlags & 0x20) {
        if (lineAlpha != 0) {
            shdDrawRotatedRect(point, 0.0f, packed, 403.0f, 2.0f, 0.0f, 1);
        }
        mask |= 0x1F;
    }
    point.x = 314.0f;
    point.y = 236.0f;
    if (*patternFlags & 0x10) {
        if (lineAlpha != 0) {
            shdDrawRotatedRect(point, 0.0f, packed, 485.0f, 2.0f, fGpffff83c0, 1);
        }
        mask |= 0x1E1;
    }
    point.x = 316.0f;
    point.y = 236.0f;
    if (*patternFlags & 0x40) {
        if (lineAlpha != 0) {
            shdDrawRotatedRect(point, 0.0f, packed, 485.0f, 2.0f, fGpffff83c4, 1);
        }
        mask |= 0x1E01;
    }
    i = 0;
    selectedMask = (u16)mask;
    drawOverlay = (u8)overlayAlpha;
    for (; i < 13; i++) {
        if (selectedMask & (1 << i)) {
            entry = D_0064ECC0 + i;
            point.x = entry->x;
            point.y = entry->y;
            sdkSpriteDrawOnceAt(texture, 55, point.x, point.y, 0xFF, 0xFF, 0xFF, iconAlpha);
            if (drawOverlay != 0) {
                sdkSpriteDrawOnceAt(texture, 55, point.x, point.y, 0xFF, 0xFF, 0xFF, overlayAlpha);
            }
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

/* Animate the tilted cue banner and sprite, clearing the cue bit after eighteen frames. */
// FUN_00385380
void btlShuffleDrawCueBanner(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern f32 sinf(f32 angle);
    u8 alpha;
    u16 *counter = (u16 *)(drawWork + 0x1E);
    s32 resource = ((BtlShuffleContext *)((BtlShuffleDrawViewWork *)drawWork)->context)->spriteResource;
    Vec2f point;
    f32 ratio;
    f32 extent;
    f32 blend;
    f32 inv;
    f32 halfHeight;
    f32 s;
    u16 scaleX;
    u16 scaleY;

    extent = btlShuffleCalcWave((f32)*counter, 14.0f, 18.0f, 2);
    ratio = btlShuffleCalcWave((f32)*counter, 5.0f, 6.0f, 1);
    blend = 0.1f * ratio + (1.3f - 0.4f * btlShuffleCalcWave((f32)*counter, 0.0f, 5.0f, 1));
    point.x = 318.0f;
    point.y = 231.0f;
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    shdDrawRotatedRect(point, 0.0f, 0x71BA00FF, 270.0f * (blend - extent), 45.0f * blend, -0.2617994f, 0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);

    ratio = btlShuffleCalcWave((f32)*counter, 5.0f, 6.0f, 1);
    blend = 0.1f * ratio + (1.3f - 0.4f * btlShuffleCalcWave((f32)*counter, 2.0f, 5.0f, 1));
    ratio = blend - extent;
    alpha = 255.0f * btlShuffleCalcWave((f32)*counter, 2.0f, 5.0f, 1);
    inv = 1.0f - ratio;
    extent = (190.0f * inv) / 2.0f;
    s = sinf(-0.2617994f);
    halfHeight = (39.0f * inv) / 2.0f;
    point.x = 221.0f + extent * cosf(-0.2617994f) - halfHeight * s;
    s = sinf(-0.2617994f);
    point.y = 2.0f + (235.0f + ((39.0f * (1.0f - blend)) / 2.0f) * cosf(-0.2617994f) + extent * s);
    scaleX = 4096.0f * ratio;
    scaleY = 4096.0f * blend;
    sdkSpriteDrawOnceScaled(resource, 0x12, point.x, point.y, 0.0f, 0, 0, 0, alpha, scaleX, scaleY, -15.0f, 0, 0);
    if (++*counter >= 0x12) {
        ((BtlShuffleDrawViewWork *)drawWork)->flags &= ~8;
    }
}

/* Draw the paired shuffle-screen quads, corner sprites and fifteen particles.
 * The shared position is a real Vec2f snapshot. Keep both color-blend weights
 * (including black), and reuse the finished trail extent for the base quads.
 * Native b210 O2: 4752/4752 bytes, all 47 relocations resolved; no zero tail.
 * See docs/probe_archive/Shuffle_side_quads_00385970_20260930.md. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 555..3507); retain only the failing byte-base accesses. */
// FUN_00385970
void btlShuffleDrawSideQuads(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y, f32 depth, u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX, u16 scaleY, f32 angle, s16 pivotX, s16 pivotY);
    extern u32 RpRandom(void);
    extern f32 sinf(f32 angle);
    extern f32 fGpffff8374;
    extern f32 fGpffff83cc;
    extern f32 fGpffff81e0;
    extern u8 D_0064ED30[];
    u8 *base;
    u8 *state;
    s32 spriteResource;
    f32 quadTransition;
    f32 cornerTransition;
    f32 quadExtent;
    f32 trailExpansion;
    f32 particleOpacity;
    f32 desaturation;
    Vec2f position;
    base = ((BtlShuffleDrawViewWork *)drawWork)->context;
    state = drawWork + 4;
    spriteResource = ((BtlShuffleContext *)base)->spriteResource;
    if ((((BtlShuffleAnimation *)state)->flags & 1) == 0) {
        quadTransition = 1.0f - btlShuffleCalcWave((f32)((BtlShuffleAnimation *)state)->frame, 10.0f, 21.0f, 2);
        cornerTransition = 1.0f - btlShuffleCalcWave((f32)*(u16 *)(state + 2), 19.0f, 21.0f, 2);
        quadExtent = 0.0f;
        trailExpansion = 0.0f;
        particleOpacity = btlShuffleCalcWave((f32)*(u16 *)(state + 2), 21.0f, 25.0f, 1);
        {
            u16 next;
            next = ++*(u16 *)(state + 2);
            if ((next & 0xFFFF) < 0x20) {
            } else {
                ((BtlShuffleAnimation *)state)->flags = ((BtlShuffleAnimation *)state)->flags | 1;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else if ((((BtlShuffleAnimation *)state)->flags & 4) != 0) {
        quadTransition = 0.0f;
        cornerTransition = 0.0f;
        quadExtent = btlShuffleCalcWave((f32)((BtlShuffleAnimation *)state)->frame, 0.0f, 10.0f, 2);
        trailExpansion = 0.0f;
        particleOpacity = 1.0f;
        {
            u16 next;
            next = ++*(u16 *)(state + 2);
            if ((next & 0xFFFF) < 0xA) {
            } else {
                ((BtlShuffleAnimation *)state)->flags = ((BtlShuffleAnimation *)state)->flags & 0xFFFB;
                ((BtlShuffleAnimation *)state)->flags = ((BtlShuffleAnimation *)state)->flags | 8;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else if ((((BtlShuffleAnimation *)state)->flags & 8) != 0) {
        quadTransition = 0.0f;
        cornerTransition = 0.0f;
        quadExtent = 1.0f;
        trailExpansion = btlShuffleCalcWave((f32)((BtlShuffleAnimation *)state)->frame, 0.0f, 5.0f, 0);
        particleOpacity = 1.0f;
        {
            u16 next;
            next = ++*(u16 *)(state + 2);
            if ((next & 0xFFFF) < 5) {
            } else {
                *(u16 *)(state + 2) = 0;
            }
        }
    } else if ((((BtlShuffleAnimation *)state)->flags & 2) != 0) {
        quadTransition = btlShuffleCalcWave((f32)((BtlShuffleAnimation *)state)->frame, 4.0f, 10.0f, 2);
        cornerTransition = btlShuffleCalcWave((f32)*(u16 *)(state + 2), 0.0f, 6.0f, 2);
        quadExtent = 0.0f;
        trailExpansion = 0.0f;
        particleOpacity = 1.0f - btlShuffleCalcWave((f32)*(u16 *)(state + 2), 0.0f, 0.0f, 1);
        {
            u16 next;
            next = ++*(u16 *)(state + 2);
            if ((next & 0xFFFF) < 0xA) {
            } else {
                ((BtlShuffleDrawViewWork *)drawWork)->flags = ((BtlShuffleDrawViewWork *)drawWork)->flags & 0xFFFE;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else {
        quadTransition = 0.0f;
        cornerTransition = 0.0f;
        quadExtent = 0.0f;
        trailExpansion = 0.0f;
        particleOpacity = 1.0f;
    }

    if ((((BtlShuffleAnimation *)state)->flags & 0x10) != 0) {
        if (((BtlShuffleAnimation *)state)->desaturation < 0x1E) {
            *(u16 *)(state + 6) = ((BtlShuffleAnimation *)state)->desaturation + 1;
        }
    }
    desaturation = btlShuffleCalcWave((f32)((BtlShuffleAnimation *)state)->desaturation, 0.0f, 30.0f, 0);
    if (((((BtlShuffleAnimation *)state)->flags & 4) != 0) || ((((BtlShuffleAnimation *)state)->flags & 8) != 0)) {
        f32 grayComponent;
        f32 colorWeight;
        const f32 unity = 1.0f;
        u8 red;
        u8 green;
        u8 blue;
        s32 trailColor;
        s32 opaqueTrailColor;
        f32 rightX;
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        grayComponent = desaturation * 108.0f;
        colorWeight = unity - desaturation;
        red = (u8)(colorWeight * 255.0f + grayComponent);
        green = (u8)(colorWeight * 32.0f + grayComponent);
        blue = (u8)(colorWeight * 26.0f + grayComponent);
        trailColor = ((u32)red << 24) | ((u32)green << 16) | ((u32)blue << 8);
        opaqueTrailColor = trailColor | 0xFF;
        rightX = 603.0f - 20.0f * trailExpansion;
        position.x = rightX;
        position.y = 224.0f;
        shdDrawWedge(position, 0.0f, opaqueTrailColor, fGpffff8374, 0, 0);
        position.x = 56.0f + 20.0f * trailExpansion;
        position.y = 224.0f;
        shdDrawWedge(position, 0.0f, opaqueTrailColor, fGpffff83cc, 0, 0);
        {
            u8 alpha;
            s32 fadingColor;
            f32 rightX;
            f32 leftX;
            alpha = (u8)(255.0f + -102.0f * trailExpansion);
            fadingColor = trailColor | alpha;
            rightX = 603.0f - 20.0f * quadExtent - 30.0f * trailExpansion;
            leftX = 56.0f + 20.0f * quadExtent + 30.0f * trailExpansion;
            position.x = rightX;
            position.y = 224.0f;
            shdDrawWedge(position, 0.0f, fadingColor, fGpffff8374, 0, 0);
            position.x = leftX;
            position.y = 224.0f;
            shdDrawWedge(position, 0.0f, fadingColor, fGpffff83cc, 0, 0);
        }
        {
            u8 alpha;
            s32 fadingColor;
            f32 rightX;
            f32 leftX;
            alpha = (u8)(153.0f + -51.0f * trailExpansion);
            fadingColor = trailColor | alpha;
            rightX = 603.0f - 50.0f * quadExtent - 40.0f * trailExpansion;
            leftX = 56.0f + 50.0f * quadExtent + 40.0f * trailExpansion;
            position.x = rightX;
            position.y = 224.0f;
            shdDrawWedge(position, 0.0f, fadingColor, fGpffff8374, 0, 0);
            position.x = leftX;
            position.y = 224.0f;
            shdDrawWedge(position, 0.0f, fadingColor, fGpffff83cc, 0, 0);
        }
        {
            u8 alpha;
            s32 fadingColor;
            f32 rightX;
            f32 leftX;
            alpha = (u8)(102.0f + -102.0f * trailExpansion);
            fadingColor = trailColor | alpha;
            rightX = 603.0f - 90.0f * quadExtent - 50.0f * trailExpansion;
            leftX = 56.0f + 90.0f * quadExtent + 50.0f * trailExpansion;
            position.x = rightX;
            position.y = 224.0f;
            shdDrawWedge(position, 0.0f, fadingColor, fGpffff8374, 0, 0);
            position.x = leftX;
            position.y = 224.0f;
            shdDrawWedge(position, 0.0f, fadingColor, fGpffff83cc, 0, 0);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
    }
    {
        f32 darkWeight;
        /* Keep both weights of the RGB blend, including its black endpoint. */
        f32 blackComponent = 0.0f;
        u8 red;
        u8 green;
        u8 blue;
        s32 baseColor;
        darkWeight = 1.0f - desaturation;
        red = (u8)(darkWeight * 74.0f + blackComponent * desaturation);
        green = (u8)(darkWeight * 36.0f + blackComponent * desaturation);
        blue = (u8)(blackComponent * darkWeight + blackComponent * desaturation);
        baseColor = ((u32)red << 24) | ((u32)green << 16) | ((u32)blue << 8) | 0xFF;
        /* Reuse the completed trail extent for the base-quad displacement. */
        quadExtent = quadTransition * 300.0f;
        position.x = 603.0f - quadExtent;
        position.y = 224.0f - quadExtent;
        shdDrawWedge(position, 0.0f, baseColor, fGpffff8374, 0, 1);
        position.x = 56.0f + quadExtent;
        position.y = 224.0f + quadExtent;
        shdDrawWedge(position, 0.0f, baseColor, fGpffff83cc, 0, 1);
    }
    {
        f32 cornerWeight;
        u8 red;
        u8 green;
        u8 blue;
        f32 cornerDisplacement;
        cornerWeight = 1.0f - desaturation;
        red = (u8)(cornerWeight * 255.0f + desaturation * 255.0f);
        green = (u8)(cornerWeight * 218.0f + desaturation * 70.0f);
        blue = (u8)(cornerWeight * 136.0f + desaturation * 80.0f);
        cornerDisplacement = cornerTransition * 300.0f;
        position.x = 407.0f - cornerDisplacement;
        position.y = 40.0f - cornerDisplacement;
        sdkSpriteDrawOnceScaled(spriteResource, 0x38, position.x, position.y, 0.0f, red, green, blue, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
        position.x = cornerDisplacement + 103.0f;
        position.y = cornerDisplacement + 186.0f;
        sdkSpriteDrawOnceScaled(spriteResource, 0x39, position.x, position.y, 0.0f, red, green, blue, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    ((BtlShuffleAnimation *)state)->pulse = (((BtlShuffleAnimation *)state)->pulse + 1) % 10;
    {
        s32 particleIndex;
        u8 particleGreen;
        particleIndex = 0;
        particleGreen = (u8)(255.0f - desaturation * 30.0f);
        for (; particleIndex < 15; particleIndex++) {
            f32 phaseOffset;
            f32 wave;
            f32 pulse;
            f32 alpha;
            phaseOffset = ((BtlShuffleParticlePoint *)(D_0064ED30 + particleIndex * 12))->phase;
            wave = sinf((fGpffff81e0 * (phaseOffset * 10.0f + (f32)*(u16 *)(state + 4))) / 10.0f);
            pulse = (wave + 1.0f) / 2.0f;
            if (*(u16 *)(state + 4) == 0) {
                f32 randomValue;
                f32 randomAlpha;
                randomValue = (f32)(u32)(RpRandom() & 0xFFF);
                randomAlpha = randomValue / 4096.0f * 224.0f + 32.0f;
                *(u8 *)(state + 8 + particleIndex) = (u8)randomAlpha;
            }
            /* Snapshot coordinates after the animation and random callbacks. */
            position.x = ((BtlShuffleParticlePoint *)(D_0064ED30 + particleIndex * 12))->x;
            position.y = ((BtlShuffleParticlePoint *)(D_0064ED30 + particleIndex * 12))->y;
            alpha = particleOpacity * ((f32)*(u8 *)(state + 8 + particleIndex) * pulse);
            sdkSpriteDrawOnceScaled(spriteResource, 0x3B, position.x, position.y, 0.0f, 0xFF, particleGreen, 0xFF, (u8)alpha, 0x1000, 0x1000, 0.0f, 0, 0);
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

/* This helper retains the radius-scale operation with the same operand
 * order as the other circular drawing primitives. */
static inline f32 btlShuffleScaleRadius(f32 value, f32 scale)
{
    return scale * value;
}

/* Native b210 O2: 2228/2240 bytes, 27 resolved relocations, 12 zero tail
 * bytes. Entry/exit radius values and sprite opacity keep distinct
 * lifetimes; the final alpha is converted once at the byte provider.
 * See docs/probe_archive/Menu_shuffle_batch_20260923.md. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 382..1663); retain only the failing byte-base accesses. */
// FUN_00386C00
void btlShuffleDrawMenuBatch(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern s32 RpSkyRenderStateSet(s32 state, void *value);
    extern void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y, f32 depth, u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX, u16 scaleY, f32 angle, s16 pivotX, s16 pivotY);
    extern f32 sinf(f32 angle);
    extern f32 fGpffff812c;
    extern f32 fGpffff83d0;
    extern f32 fGpffff837c;
    extern f32 fGpffff81e0;
    extern u8 D_0064EDF0[];
    u8 *base;
    u8 *state;
    s32 resource;
    Vec2f pos;
    f32 innerAngleScale;
    f32 cornerScale;
    f32 outerRadius;
    f32 innerRadius;
    f32 particleOpacity;
    f32 outerAngle;
    f32 innerAngle;
    f32 cornerDisplacement;
    state = drawWork + 4;
    base = ((BtlShuffleDrawViewWork *)drawWork)->context;
    resource = ((BtlShuffleContext *)base)->spriteResource;
    if ((((BtlShuffleAnimation *)state)->flags & 1) == 0) {
        f32 overshootWeight;
        outerRadius = btlShuffleCalcWave((f32)((BtlShuffleAnimation *)state)->frame, 10.0f, 20.0f, 2);
        innerRadius = btlShuffleCalcWave((f32)*(u16 *)(state + 2), 10.0f, 20.0f, 2);
        cornerScale = btlShuffleCalcWave((f32)*(u16 *)(state + 2), 19.0f, 21.0f, 2);
        overshootWeight = fGpffff83d0;
        cornerScale = fGpffff812c * btlShuffleCalcWave((f32)*(u16 *)(state + 2), 14.0f, 19.0f, 1)
                  - overshootWeight * cornerScale;
        particleOpacity = btlShuffleCalcWave((f32)*(u16 *)(state + 2), 13.0f, 20.0f, 1);
        innerAngleScale = innerRadius;
        {
            u16 next;
            next = ++*(u16 *)(state + 2);
            if ((next & 0xFFFF) < 0x1C) {
            } else {
                ((BtlShuffleAnimation *)state)->flags = ((BtlShuffleAnimation *)state)->flags | 1;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else if (((BtlShuffleAnimation *)state)->flags & 2) {
        f32 t0;
        f32 t1;
        f32 t2;
        t0 = btlShuffleCalcWave((f32)((BtlShuffleAnimation *)state)->frame, 0.0f, 13.0f, 2);
        outerRadius = (0.0f + 1.0f) + 3.0f * t0;
        t1 = btlShuffleCalcWave((f32)*(u16 *)(state + 2), 0.0f, 13.0f, 2);
        innerRadius = (0.0f + 1.0f) + 3.0f * t1;
        t2 = btlShuffleCalcWave((f32)*(u16 *)(state + 2), 0.0f, 10.0f, 2);
        cornerScale = (0.0f + 1.0f) + 2.0f * t2;
        particleOpacity = 1.0f - btlShuffleCalcWave((f32)*(u16 *)(state + 2), 0.0f, 10.0f, 1);
        innerAngleScale = innerRadius;
        {
            u16 next;
            next = ++*(u16 *)(state + 2);
            if ((next & 0xFFFF) < 0x14) {
            } else {
                ((BtlShuffleDrawViewWork *)drawWork)->flags = ((BtlShuffleDrawViewWork *)drawWork)->flags & 0xFFFD;
                *(u16 *)(state + 2) = 0;
            }
        }
    } else {
        outerRadius = 1.0f;
        innerRadius = outerRadius;
        innerAngleScale = outerRadius;
        cornerScale = outerRadius;
        particleOpacity = outerRadius;
    }
    pos.x = 316.0f;
    pos.y = 211.0f;
    if (outerRadius > 0.0f) {
        outerAngle = fGpffff837c * (1.0f + outerRadius);
        outerRadius = btlShuffleScaleRadius(outerRadius, 111.5f);
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        shdDrawRectOutline(pos, 0.0f, 0xAE545AFF, outerAngle, outerRadius, 92.0f, 0);
    }
    if (innerRadius > 0.0f) {
        innerAngle = fGpffff837c * (1.0f + innerAngleScale);
        innerRadius = btlShuffleScaleRadius(innerRadius, 98.0f);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        shdDrawRectOutline(pos, 0.0f, 0x4A2400FF, innerAngle, innerRadius, 18.0f, 1);
    }
    cornerDisplacement = (cornerScale - 1.0f) * 300.0f;
    pos.x = (f32)359 + cornerDisplacement;
    pos.y = 14.0f + cornerDisplacement;
    sdkSpriteDrawOnceScaled(resource, 0x3A, pos.x, pos.y, 0.0f, 0x4A, 0x24, 0, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
    pos.x = 119.0f - cornerDisplacement;
    pos.y = 184.0f - cornerDisplacement;
    sdkSpriteDrawOnceScaled(resource, 0x39, pos.x, pos.y, 0.0f, 0x4A, 0x24, 0, 0xFF, 0x1000, 0x1000, 45.0f, 0, 0);
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    ((BtlShuffleAnimation *)state)->pulse = (((BtlShuffleAnimation *)state)->pulse + 1) % 60;
    {
        s32 i;
        for (i = 0; i < 16; i++) {
            u8 *entry;
            f32 ff;
            f32 s;
            f32 t;
            f32 af;
            f32 one;
            f32 two;
            entry = D_0064EDF0 + i * 12;
            ff = ((BtlShuffleParticlePoint *)entry)->phase;
            s = sinf((fGpffff81e0 * ((0.0f + (f32)*(u16 *)(state + 4)) + 60.0f * ff)) / 60.0f);
            one = 1.0f;
            t = one + s;
            two = 2.0f;
            t = t / two;
            pos.x = ((BtlShuffleParticlePoint *)entry)->x;
            pos.y = ((BtlShuffleParticlePoint *)entry)->y;
            af = (255.0f * (one + t)) / two;
            af *= particleOpacity;
            sdkSpriteDrawOnceScaled(resource, 0x3C, pos.x, pos.y, 0.0f, 0xFF, 0xFF, 0xFF, (u8)af, 0x1000, 0x1000, 0.0f, 0, 0);
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

/* Dispatch background view components and fade the listed cards according to view flags. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 476..476); retain only the failing byte-base accesses. */
// FUN_003874C0
void btlShuffleDrawViewBackground(s32 drawWork, u8 *input)
{
    extern void btlShuffleDrawCardSet(u8 *drawWork);
    extern void btlShuffleDrawFrameFade(u8 *drawWork);
    extern void btlShuffleDrawGlowCards(u8 *drawWork);
    extern void btlShuffleDrawPatternLineFade(u8 *work);
    extern void btlShuffleDrawCueBanner(u8 *drawWork);
    extern void btlShuffleDrawSideQuads(u8 *drawWork);
    extern void btlShuffleDrawMenuBatch(u8 *drawWork);
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    u8 *base;
    u8 *entry;
    s32 value;
    f32 ramp;
    f32 alphaF;
    u8 alpha;
    s32 i;

    sdkRenderStateSetDefault();
    if ((((BtlShuffleDrawViewWork *)input)->flags & 0x200) != 0) {
        base = ((BtlShuffleDrawViewWork *)input)->context;
        entry = input + 0x46;
        value = *(u16 *)entry;
        if (value < 0x23) {
            value = ++*(u16 *)entry;
            ramp = (f32)(u16)value;
            alphaF = 255.0f *
                btlShuffleCalcWave(ramp, 0.0f, 30.0f, 0);
            alpha = (u8)alphaF;
            *(u8 *)(entry + 5) = alpha;
        }
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);
        for (i = 0; i < ((BtlShuffleContext *)base)->fadeCardCount; i++) {
            btlShuffleDrawCardSprites(base,
                          *(s32 *)(base + (i * 4) + 0x1F214),
                          0, entry + 2, 1);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
    }
    if ((*(u16 *)(input + 0x4C) & 0x10) != 0) {
        btlShuffleDrawCardSet(input);
    }
    if ((*(u16 *)(input + 0x4C) & 0x20) != 0) {
        btlShuffleDrawFrameFade(input);
    }
    if ((*(u16 *)(input + 0x4C) & 0x80) != 0) {
        btlShuffleDrawGlowCards(input);
    }
    if ((*(u16 *)(input + 0x4C) & 0x40) != 0) {
        btlShuffleDrawPatternLineFade(input);
    }
    if ((*(u16 *)(input + 0x4C) & 8) != 0) {
        btlShuffleDrawCueBanner(input);
    }
    if ((*(u16 *)(input + 0x4C) & 1) != 0) {
        btlShuffleDrawSideQuads(input);
    }
    if ((*(u16 *)(input + 0x4C) & 2) != 0) {
        btlShuffleDrawMenuBatch(input);
    }
}

static inline f32 btlShuffleQuarterTurnOffset(s32 index)
{
    extern f32 fGpffff83d8;
    return fGpffff83d8 * (f32)index;
}

/* Draw the selected card and two rotating four-vertex reveal fans. */
/* measured: typing revealCard changes the second masked draw reload schedule (normalized_diff 751); keep its byte-base loads. */
// FUN_00387750
void btlShuffleDrawRevealFan(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern f32 sinf(f32 angle);
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern void effMiscDrawScreenColor(void *colors, s32 enabled);
    extern f32 fGpffff82cc;
    extern f32 fGpffff82fc;
    extern f32 fGpffff83d8;
    u8 *base;
    u8 *state;
    struct { f32 depth; f32 recipZ; f32 phase; } view;
    f32 blend0;
    f32 blend1;
    u8 colors[4];
    BtlShuffleSkyVertex work[4];
    typedef struct {
        s32 (*draw)(s32 primitive, void *vertices, s32 count);
    } BtlShufflePrimitiveDispatch;
    BtlShufflePrimitiveDispatch *dispatch;
    s32 alpha;
    base = ((BtlShuffleDrawViewWork *)drawWork)->context;
    state = drawWork + 0x46;
    view.depth = D_008872F8[0];
    view.recipZ = 1.0f / ((MdlEffectCamera *)kwlnGetCamera())->nearPlane;
    *(u16 *)(state + 2) = (*(u16 *)(state + 2) + 1) % 10;
    view.phase = (fGpffff82fc * (f32)*(u16 *)(state + 2)) / 10.0f;
    if ((*(u16 *)(state + 4) & 1) == 0) {
        blend0 = btlShuffleCalcWave((f32)*(u16 *)state, 0.0f, 15.0f, 0);
        blend1 = 0.0f;
        {
            if (++*(u16 *)state >= 0xF) {
                *(u16 *)state = 0;
                *(u16 *)(state + 4) = *(u16 *)(state + 4) | 1;
            }
        }
    } else if (*(u16 *)(state + 4) & 2) {
        blend0 = 1.0f - btlShuffleCalcWave((f32)*(u16 *)state, 0.0f, 28.0f, 0);
        blend1 = btlShuffleCalcWave((f32)*(u16 *)state, 0.0f, 30.0f, 0);
        {
            if (++*(u16 *)state >= 0x23) {
                ((BtlShuffleDrawViewWork *)drawWork)->flags = ((BtlShuffleDrawViewWork *)drawWork)->flags & 0xFBFF;
                btlShuffleDrawViewRequestWhiteStep(((BtlShuffleContext *)base)->viewTask);
            }
        }
    } else {
        blend0 = 1.0f;
        blend1 = 0.0f;
    }
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = (u8)(255.0f * (fGpffff82cc * blend0 + blend1));
    btlShuffleDrawCardSprites(base, *(s32 *)(base + 0x1F308), 0, colors, 0);
    colors[0] = 0xFF;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0;
    mdlEffectEmitMaskedTagPair();
    RpSkyRenderStateSet(3, (void *)0x31801);
    effMiscDrawScreenColor(colors, 0);
    colors[3] = 0xFF;
    btlShuffleDrawCardSprites(base, *(s32 *)(base + 0x1F308), 0, colors, 0);
    mdlEffectEmitTagPair();
    RpSkyRenderStateSet(3, (void *)0x3F801);
    RpSkyRenderStateSet(2, (void *)0x48);
    {
        s32 i;
        for (i = 0; i < 4; i++) {
            f32 ang;
            f32 y;
            f32 x;
            BtlShuffleSkyVertex *vertex;
            alpha = (u8)(255.0f * ((f32)(i & 1) * blend0));
            {
                f32 offset;
                offset = btlShuffleQuarterTurnOffset(i);
                ang = view.phase + offset;
            }
            y = (0.0f + 211.0f) + 192.0f * sinf(ang);
            x = (0.0f + 316.0f) + 192.0f * cosf(ang);
            vertex = &work[i];
            vertex->u.els.scrVertex.x = x;
            vertex->u.els.scrVertex.y = y;
            vertex->u.els.scrVertex.z = view.depth;
            vertex->u.els.color.r = 255.0f;
            vertex->u.els.color.g = 0.0f;
            vertex->u.els.color.b = 0.0f;
            vertex->u.els.color.a = (f32)(u32)alpha;
            vertex->u.els.recipZ = view.recipZ;
        }
    }
    dispatch = (BtlShufflePrimitiveDispatch *)D_00887310;
    dispatch->draw(5, work, 4);
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            f32 ang;
            f32 y;
            f32 x;
            BtlShuffleSkyVertex *vertex;
            f32 edgeAlpha;
            edgeAlpha = fGpffff82cc * (f32)(j & 1);
            edgeAlpha *= blend0;
            alpha = (u8)(255.0f * edgeAlpha);
            {
                f32 offset;
                offset = btlShuffleQuarterTurnOffset(j);
                ang = view.phase + offset;
            }
            y = (0.0f + 211.0f) + 192.0f * sinf(ang);
            x = (0.0f + 316.0f) + 192.0f * cosf(ang);
            vertex = &work[j];
            vertex->u.els.scrVertex.x = x;
            vertex->u.els.scrVertex.y = y;
            vertex->u.els.scrVertex.z = view.depth;
            vertex->u.els.color.r = 255.0f;
            vertex->u.els.color.g = 0.0f;
            vertex->u.els.color.b = 0.0f;
            vertex->u.els.color.a = (f32)(u32)alpha;
            vertex->u.els.recipZ = view.recipZ;
        }
    }
    dispatch->draw(5, work, 4);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

/* Draw the expanding roster list with arcana icons, persona names and levels. */
/* Roster entries are opaque persona records here; only the ID halfword at +2 is known, with no record extent established. */
// FUN_00387E70
void btlShuffleDrawRoster(u8 *drawWork)
{
    extern u8 *resourceFindByName(char *name);
    extern u8 datPersonaGetLevel(int persona);
    extern int frFontExDrawTextWithCharWidth(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                             const char *str, int flags, int charWidth);
    extern u8 D_005E5810[];
    extern u8 D_005E5850[];
    extern f32 fGpffff83b0;
    u8 *base;
    s32 *state;
    s32 resource;
    s32 fonts[2];
    s32 selected;
    f32 t;
    f32 x;
    f32 y;
    f32 fade;
    f32 slide;
    s32 slot;
    Vec2f pos;
    s32 idx;
    u8 barA;
    u8 alpha;
    u8 r;
    u8 barB;
    u8 g;
    u8 b;

    base = ((BtlShuffleDrawViewWork *)drawWork)->context;
    state = (s32 *)(((KwlnTask *)((BtlShuffleContext *)base)->rosterTask)->work + 0x18);
    resource = ((BtlShuffleContext *)base)->spriteResource;
    /* Retail tests the handle array's address before filling it. */
    if (fonts == NULL) {
        kAssertFail(D_0064EEB0, 0x50B);
    }
    fonts[0] = (s32)resourceFindByName((char *)D_005E5810);
    fonts[1] = (s32)resourceFindByName((char *)D_005E5850);
    selected = state[1] + state[2];
    t = (f32)(state[4] - 12) / 12.0f;
    if (t > 1.0f) {
        slide = 1.0f;
    } else if (t < 0.0f) {
        slide = 0.0f;
    } else {
        slide = 0.0f + 2.0f * t - t * t;
    }
    if (slide == 1.0f) {
        fade = (f32)(state[4] - 28) / 12.0f;
        if (fade > 1.0f) {
            fade = 1.0f;
        } else if (fade < 0.0f) {
            fade = 0.0f;
        }
        switch ((u16)datPersonaRosterCapacity()) {
        case 6:
            slot = 0x3D;
            x = 154.0f;
            pos.x = x;
            pos.y = 218.0f;
            break;
        case 8:
            slot = 0x3E;
            x = 154.0f;
            pos.x = x;
            pos.y = 274.0f;
            break;
        case 10:
            slot = 0x3F;
            x = 154.0f;
            pos.x = x;
            pos.y = 330.0f;
            break;
        case 12:
        default:
            slot = 0x19;
            x = 154.0f;
            pos.x = x;
            pos.y = 386.0f;
            break;
        }
        y = 178.5f * fade;
        sdkSpriteDrawOnceAt(resource, slot, x, 43.0f, 0xEA, 0x7C, 0, y);
        sdkSpriteDrawOnceAt(resource, 0x1A, pos.x, pos.y, 0xEA, 0x7C, 0, y);
    } else {
        fade = 0.0f;
    }
    idx = state[3] - 1;
    pos.y = idx * 28;
    while (idx >= 0) {
        y = pos.y * slide;
        if (idx == selected && state[5] == 0) {
            barA = 0x2D;
            barB = 0x2D;
            r = 0xFF;
            g = 0xFF;
            b = 0xFF;
        } else {
            barA = 0xFF;
            barB = 0x81;
            r = 0xE7;
            g = 0x8C;
            b = 0x20;
        }
        if (idx == 0) {
            sdkSpriteDrawOnceAt(resource, 0x17, 154.0f, 49.0f + y, 0xFF, 0, 0, 0xFF);
            sdkSpriteDrawOnceAt(resource, 0x18, 526, 49.0f + y, 0xFF, 0, 0, 0xFF);
            r = 0xFF;
            g = 0xFF;
            b = 0xFF;
        }
        if (idx != 0 || (selected == 0 && state[5] == 0)) {
            sdkSpriteDrawOnceAt(resource, 0x15, 154.0f, 49.0f + y, barA, barA, barB, 0xFF);
            sdkSpriteDrawOnceAt(resource, 0x16, 526, 49.0f + y, barA, barA, barB, 0xFF);
        }
        if (idx != 0) {
            f32 in;

            in = (f32)(state[4] - 18 - idx) / 6.0f;
            if (in > 1.0f) {
                in = 1.0f;
            } else if (in < 0.0f) {
                in = 0.0f;
            }
            alpha = 255.0f * in;
            if (idx == state[3] - 1 && alpha == 0xFF) {
                state[5] = 0;
            }
        } else {
            alpha = 0xFF;
        }
        if (alpha != 0) {
            s32 *entry;
            s32 id;
            s32 icon;
            u16 value;

            entry = (s32 *)((u8 *)&state[idx] + 0x4C);
            id = *(u16 *)(*entry + 2);
            icon = datPersonaGetArcana(id);
            if (icon <= 0 || icon >= 0x20) {
                kAssertFail(D_0064EEB0, 0x588);
            }
            sdkSpriteDrawOnceAt(fonts[0], (u16)((u16)icon - 1) + 0x21, 168.0f, 55.0f + y, r, g, b, alpha);
            frFontExDrawTextWithCharWidth(269, 55.0f + y - 3.0f, 0.0f,
                          (r << 24) | (g << 16) | (b << 8) | alpha, 0, 1,
                          (const char *)datPersonaGetRow(id), 0, -1);
            value = datPersonaGetLevel(*entry);
            if (value > 99) {
                value = 99;
            }
            if (value >= 10) {
                sdkSpriteDrawOnceAt(fonts[1], value / 10 + 0x1D, 471, 58.0f + y, r, g, b, alpha);
            }
            sdkSpriteDrawOnceAt(fonts[1], value % 10 + 0x1D, 493, 58.0f + y, r, g, b, alpha);
        }
        pos.y -= 28.0f;
        idx--;
    }
    t = (f32)state[4] / 6.0f;
    if (t > 1.0f) {
        t = 1.0f;
    }
    t = 1.0f - (2.0f * t - t * t);
    pos.x = -116.0f;
    pos.y = 30.0f - 160.0f * t;
    shdDrawRotatedRect(pos, 0.0f, 0xFF0000FF, 684.0f, 313, fGpffff83b0, 1);
    pos.x = -132.0f;
    pos.y = 14.0f - 160.0f * t;
    shdDrawRotatedRect(pos, 0.0f, 0xFF, 684.0f, 313, fGpffff83b0, 1);
    t = (f32)(state[4] - 14) / 6.0f;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    t = 1.0f - (2.0f * t - t * t);
    pos.x = 0.0f + 6.0f + 200.0f * t;
    pos.y = 0.0f + 90.0f - 120.0f * t;
    sdkSpriteDrawOnceScaled(resource, 0x1C, pos.x, pos.y, 0.0f, 0xFF, 0, 0, 0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
    t = (f32)(state[4] - 6) / 6.0f;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    t = 1.0f - (2.0f * t - t * t);
    pos.x = 0.0f + 109.0f + 170.0f * t;
    pos.y = 0.0f + 19.0f - 90.0f * t;
    sdkSpriteDrawOnceAt(resource, 0x1B, pos.x, pos.y, 0xFF, 0xFF, 0xFF, 0xFF);
    if (state[5] != 0 || fade < 1.0f) {
        state[4]++;
    }
}

/* Dispatch roster and reveal drawing and animate the pending color step. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 285..300); retain only the failing byte-base accesses. */
// FUN_003889B0
void btlShuffleDrawViewForeground(s32 drawWork, u8 *input)
{
    extern void btlShuffleDrawRevealFan(u8 *drawWork);
    extern void btlShuffleDrawRoster(u8 *drawWork);
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern void effMiscDrawScreenColor(void *colors, s32 enabled);
    u8 colors[4];
    f32 alphaF;
    f32 ramp;
    u16 *counter;
    u16 ticks;

    sdkRenderStateSetDefault();
    if ((((BtlShuffleDrawViewWork *)input)->flags & 0x400) != 0) {
        btlShuffleDrawRevealFan(input);
    }
    if ((*(u16 *)(input + 0x4C) & 4) != 0) {
        btlShuffleDrawRoster(input);
    }
    if ((*(u16 *)(input + 0x4C) & 0x100) != 0) {
        counter = (u16 *)(input + 0x40);
        colors[0] = ((BtlShuffleDrawViewWork *)input)->stepColor[0];
        colors[1] = ((BtlShuffleDrawViewWork *)input)->stepColor[1];
        colors[2] = ((BtlShuffleDrawViewWork *)input)->stepColor[2];
        ramp = (f32)(u16)*counter;
        alphaF = 128.0f *
            (1.0f - btlShuffleCalcWave(ramp, 0.0f, 30.0f, 2));
        colors[3] = (u8)alphaF;
        effMiscDrawScreenColor(colors, 1);
        ticks = ++*counter;
        if (ticks >= 0x1E) {
            *(u16 *)(input + 0x4C) =
                *(u16 *)(input + 0x4C) & 0xFEFF;
        }
    }
}

/* Append both embedded view primitive nodes to their drawing queues for this frame. */
// FUN_00388B40
s32 btlShuffleDrawViewStep(u8 *drawWork)
{
    u8 *p;

    p = ((KwlnTask *)drawWork)->work;
    ((BtlRenderNode *)(p + 0x50))->unk00 = 0;
    ((BtlRenderNode *)(p + 0x50))->unk04 = 0;
    PrimAppendNode(D_00795E30, p + 0x50);
    ((BtlRenderNode *)(p + 0x80))->unk00 = 0;
    ((BtlRenderNode *)(p + 0x80))->unk04 = 0;
    PrimAppendNode(D_00795EF0, p + 0x80);
    return 0;
}

// FUN_00388BA0
void btlShuffleDrawViewDestroy(u8 *drawWork) {
    D_008873ec[0]((s32)((KwlnTask *)drawWork)->work);
}

/* Allocate the 0xB0-byte view work and register its two primitive callbacks with a child task. */
// FUN_00388BD0
u8 *btlShuffleDrawViewCreate(s32 drawWork)
{
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(D_0064EEB0, 0x63F);
    work = D_008873F4[0](1, 0xB0, 0x40000);
    if (work == NULL) {
        kAssertFail(D_0064EEB0, 0x640);
    }
    task = kwlnTaskCreateChild((void *)(drawWork), (const void *)(D_0064ECA0), 0x13, 0, 0, btlShuffleDrawViewStep, btlShuffleDrawViewDestroy, (u8 *)(work));
    if (task == NULL) {
        kAssertFail(D_0064EEB0, 0x64A);
    }
    *(s32 *)work = btlShuffleGetDrawContext(drawWork);
    memset(work + 0x50, 0, 0x30);
    memset(work + 0x80, 0, 0x30);
    ((BtlRenderNode *)(work + 0x50))->callback = (void *)btlShuffleDrawViewBackground;
    ((BtlRenderNode *)(work + 0x50))->work = (void *)work;
    ((BtlRenderNode *)(work + 0x80))->callback = (void *)btlShuffleDrawViewForeground;
    ((BtlRenderNode *)(work + 0x80))->work = (void *)work;
    btlShuffleDrawViewClearFlags(task);
    return task;
}

// FUN_00388D10
void btlShuffleDrawViewClearFlags(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags = 0;
}

// FUN_00388D20
void btlShuffleDrawViewSetActive(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags | 0x4;
}

// FUN_00388D40
void btlShuffleDrawViewClearActive(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags & 0xFFFB;
}

/* Reset menu entrance timing, enable menu drawing and play its startup sound. */
// FUN_00388D60
void btlShuffleDrawViewSetMenuBusy(u8 *drawWork) {
    u8 *p = ((KwlnTask *)drawWork)->work;

    memset(p + 4, 0, 6);
    ((BtlShuffleDrawViewWork *)p)->flags |= BTL_SHUFFLE_VIEW_FLAG_MENU_BUSY;
    btlShuffleDrawViewRequestWhiteStep(drawWork);
    sdkSndStartStream(1, 3, 5, 0xD);
}

// FUN_00388DE0
s32 btlShuffleDrawViewIsMenuReady(u8 *drawWork)
{
    return (((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->animation.flags & BTL_SHUFFLE_VIEW_STATE_READY) != 0;
}

/* Request the menu animation exit phase. */
// FUN_00388E00
void btlShuffleDrawViewEndMenu(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->animation.flags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->animation.flags | 0x2;
}

// FUN_00388E20
s32 btlShuffleDrawViewIsMenuIdle(u8 *drawWork) {
    return !(((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags & BTL_SHUFFLE_VIEW_FLAG_MENU_BUSY);
}

/* Clear run animation work, enable its draw bit and request a white step. */
// FUN_00388E40
void btlShuffleDrawViewStartRun(u8 *drawWork) {
    u8 *p = ((KwlnTask *)drawWork)->work;

    memset(p + 4, 0, 0x18);
    ((BtlShuffleDrawViewWork *)p)->flags |= 1;
    btlShuffleDrawViewRequestWhiteStep(drawWork);
    sdkSndStartStream(1, 3, 5, 0xD);
}

// FUN_00388EC0
s32 btlShuffleDrawViewIsRunReady(u8 *drawWork)
{
    return (((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->animation.flags & BTL_SHUFFLE_VIEW_STATE_READY) != 0;
}

/* Request the run animation expansion phase. */
// FUN_00388EE0
void btlShuffleDrawViewExpandRun(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->animation.flags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->animation.flags | 0x4;
}

/* Reset the desaturation counter and enable the run color transition. */
// FUN_00388F00
void btlShuffleDrawViewStartDesaturation(u8 *drawWork)
{
    u8 *p;

    p = ((KwlnTask *)drawWork)->work;
    ((BtlShuffleDrawViewWork *)p)->animation.desaturation = 0;
    ((BtlShuffleDrawViewWork *)p)->animation.flags = ((BtlShuffleDrawViewWork *)p)->animation.flags | 0x10;
}

// FUN_00388F20
void btlShuffleDrawViewSetHold(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags | 0x10;
}

// FUN_00388F40
void btlShuffleDrawViewClearHold(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags & 0xFFEF;
}

/* Clear the frame animation and enable its drawing component. */
// FUN_00388F60
void btlShuffleDrawViewStartFrameFade(u8 *drawWork) {
    u8 *work;

    work = (u8 *)(((KwlnTask *)drawWork)->work);
    memset(work + 0x20, 0, 4);
    ((BtlShuffleDrawViewWork *)work)->flags = (u16) (((BtlShuffleDrawViewWork *)work)->flags | 0x20);
}

/* Request the frame animation fade-out phase. */
// FUN_00388FB0
void btlShuffleDrawViewEndFrameFade(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->frameFlags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->frameFlags | 0x2;
}

/* Reset the pattern animation and enable its drawing component. */
// FUN_00388FD0
void btlShuffleDrawViewStartPatternFade(u8 *drawWork) {
    u8 *work;

    work = (u8 *)(((KwlnTask *)drawWork)->work);
    memset(work + 0x24, 0, 4);
    ((BtlShuffleDrawViewWork *)work)->flags = (u16) (((BtlShuffleDrawViewWork *)work)->flags | 0x40);
}

/* Request the pattern animation exit phase. */
// FUN_00389020
void btlShuffleDrawViewEndPatternFade(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->patternFlags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->patternFlags | 0x4;
}

/* Clear the glow list and enable its drawing component. */
// FUN_00389040
void btlShuffleDrawViewStartGlow(u8 *drawWork) {
    u8 *work;

    work = (u8 *)(((KwlnTask *)drawWork)->work);
    memset(work + 0x28, 0, 0x18);
    ((BtlShuffleDrawViewWork *)work)->flags = (u16) (((BtlShuffleDrawViewWork *)work)->flags | 0x80);
}

/* Append a card index to the four-entry glow list and assert its capacity. */
// FUN_00389090
void btlShuffleDrawViewAddGlowCard(u8 *drawWork, s32 input) {
    u8 *p = ((KwlnTask *)drawWork)->work;
    s32 *slot = (s32 *)(p + 0x28);
    s32 n = ((BtlShuffleDrawViewWork *)p)->glow.count;

    ((BtlShuffleDrawViewWork *)p)->glow.count = n + 1;
    slot = (s32 *)((u32)(n << 2) + (u32)slot);
    slot[1] = input;
    if (((BtlShuffleDrawViewWork *)p)->glow.count > 4) {
        kAssertFail(D_0064EEB0, 0x745);
    }
  }

/* Disable the glow drawing component. */
// FUN_003890F0
void btlShuffleDrawViewClearGlow(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags & 0xFF7F;
}

/* Restart the eighteen-frame cue animation and play its sound. */
// FUN_00389110
void btlShuffleDrawViewStartCue(u8 *drawWork) {
    u8 *work;

    work = (u8 *)(((KwlnTask *)drawWork)->work);
    ((BtlShuffleDrawViewWork *)work)->cueFrame = 0;
    ((BtlShuffleDrawViewWork *)work)->flags = (u16) (((BtlShuffleDrawViewWork *)work)->flags | BTL_SHUFFLE_VIEW_FLAG_CUE);
    sdkSndStartStream(1, 5, 5, 0);
}

// FUN_00389160
s32 btlShuffleDrawViewIsCueIdle(u8 *drawWork) {
    return !(((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags & BTL_SHUFFLE_VIEW_FLAG_CUE);
}

/* Request a color step with all three components set to white. */
// FUN_00389180
void btlShuffleDrawViewRequestWhiteStep(u8 *drawWork) {
    btlShuffleDrawViewRequestStep(drawWork, 0xFF, 0xFF, 0xFF);
}

/* Reset the color-step clock, store its RGB endpoint and mark the step pending. */
// FUN_003891B0
void btlShuffleDrawViewRequestStep(u8 *drawWork, u8 input, u8 green, u8 blue)
{
    u8 *p;

    p = ((KwlnTask *)drawWork)->work;
    ((BtlShuffleDrawViewWork *)p)->stepFrame = 0;
    ((BtlShuffleDrawViewWork *)p)->stepColor[0] = input;
    ((BtlShuffleDrawViewWork *)p)->stepColor[1] = green;
    ((BtlShuffleDrawViewWork *)p)->stepColor[2] = blue;
    ((BtlShuffleDrawViewWork *)p)->flags = ((BtlShuffleDrawViewWork *)p)->flags | BTL_SHUFFLE_VIEW_FLAG_STEP_PENDING;
}

// FUN_003891E0
s32 btlShuffleDrawViewIsStepIdle(u8 *drawWork) {
    return !(((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags & BTL_SHUFFLE_VIEW_FLAG_STEP_PENDING);
}

/* Clear the shared fade state, store the requested color and enable card fading. */
// FUN_00389200
void btlShuffleDrawViewSetFade(u8 *drawWork, s8 input, s8 green, s8 blue) {
    u8 *params;
    u8 *work;

    work = (u8 *)(((KwlnTask *)drawWork)->work);
    params = (u8 *)(work + 0x46);
    memset(params, 0, 6);
    ((BtlShuffleFade *)params)->payload.color[0] = input;
    ((BtlShuffleFade *)params)->payload.color[1] = green;
    ((BtlShuffleFade *)params)->payload.color[2] = blue;
    ((BtlShuffleDrawViewWork *)work)->flags = (u16) (((BtlShuffleDrawViewWork *)work)->flags | BTL_SHUFFLE_VIEW_FLAG_FADE);
}

#pragma push
#pragma opt_rebuildconditionals off
/* Report completion when fading is disabled or its clock reaches thirty-five frames. */
// FUN_00389280
s32 btlShuffleDrawViewIsFadeDone(u8 *drawWork)
{
    u8 *p;
    u16 *field;
    u16 flags;

    p = ((KwlnTask *)drawWork)->work;
    field = (u16 *)(p + 0x46);
    flags = ((BtlShuffleDrawViewWork *)p)->flags;
    if (!(flags & BTL_SHUFFLE_VIEW_FLAG_FADE)) {
        return 1;
    }
    return *field >= 0x23;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
// FUN_003892C0
void btlShuffleDrawViewClearFade(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags & 0xFDFF;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
/* Clear the shared fade/reveal state and enable the reveal component. */
// FUN_003892E0
void btlShuffleDrawViewStartReveal(u8 *drawWork) {
    u8 *work;

    work = (u8 *)(((KwlnTask *)drawWork)->work);
    memset(work + 0x46, 0, 6);
    ((BtlShuffleDrawViewWork *)work)->flags = (u16) (((BtlShuffleDrawViewWork *)work)->flags | BTL_SHUFFLE_VIEW_FLAG_REVEAL);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
// FUN_00389330
s32 btlShuffleDrawViewIsRevealFinished(u8 *drawWork) {
    return !(((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->flags & BTL_SHUFFLE_VIEW_FLAG_REVEAL);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
/* Request the reveal animation exit phase. */
// FUN_00389350
void btlShuffleDrawViewEndReveal(u8 *drawWork)
{
    ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->fade.payload.words[1] = ((BtlShuffleDrawViewWork *)((KwlnTask *)drawWork)->work)->fade.payload.words[1] | 0x2;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
/* Draw a cosine-scaled background sprite using the wrapping eight-hundred-frame clock. */
// FUN_00389370
void btlShuffleDrawBackgroundPulse(u8 **drawWork)
{
    u16 *tick;
    s32 palette;
    u16 phase;
    f32 t;
    f32 value0;
    f32 q0;
    f32 q1;
    f32 width;
    f32 height;
    s32 size0;
    s32 size1;

    tick = (u16 *)((u8 *)drawWork + 0x68);
    palette = ((BtlShuffleContext *)*drawWork)->backgroundResource;

    *tick += 1;
    if (*tick >= 0x320) {
        *tick = 0;
    }

    phase = (u16)(*tick % 100);
    if (phase < 50) {
        t = (f32)phase;
        value0 = 1.0f - cosf((D_00761470 * t) / 50.0f);
    } else {
        t = (f32)(phase - 50);
        value0 = cosf((D_00761470 * t) / 50.0f);
    }

    if (value0 < 0.0f) {
        value0 = 0.0f;
    }

    q0 = (0.0f + 644.0f + 584.0f * value0) / 254.0f;
    q1 = (0.0f + 454.0f + 404.0f * value0) / 254.0f;

    width = 127.0f * q0;
    height = 127.0f * q1;

    size0 = (s32)width;
    size1 = (s32)height;

    {
        sdkSpriteDrawOnceScaled(palette, 0, 320.0f - width, 224.0f - height, 0.0f,
                      0xFF, 0xFF, 0xFF, (u8)0xFF,
                      (u16)(4096.0f * q0), (u16)(4096.0f * q1),
                      0.0f, (s16)size0, (s16)size1);
    }
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
/* Spawn four staggered randomized rings and animate their size, rotation and opacity. */
// FUN_00389640
void btlShuffleDrawBackgroundRings(u8 **drawWork)
{
    extern u32 RpRandom(void);
    extern f32 sinf(f32 angle);
    extern f32 D_007613EC;
    extern f32 fGpffff82cc;
    extern f32 fGpffff8170;
    extern f32 fGpffff8218;
    u8 *base;
    s32 palette;
    s32 slot;
    s32 i;
    u16 *tickp;
    base = (u8 *)drawWork + 0x6C;
    palette = ((BtlShuffleContext *)*drawWork)->backgroundResource;
    tickp = (u16 *)base;
    if ((*tickp % 80) == 0) {
        slot = *tickp / 80;
        if (slot >= 4) {
            kAssertFail(D_0064F0E0, 0xEB);
        }
        {
            u8 *entry;
            u32 rnd;
            f32 ratio;
            entry = base + slot * 12 + 4;
            ((BtlShuffleBackgroundRing *)entry)->frame = 0;
            rnd = RpRandom() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            ((BtlShuffleBackgroundRing *)entry)->duration = (u16)(200.0f * ((0.0f + fGpffff8170) + fGpffff82cc * ratio));
            rnd = RpRandom() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            ((BtlShuffleBackgroundRing *)entry)->alpha = (u8)(255.0f * ((0.0f + fGpffff8218) + fGpffff8218 * ratio));
            rnd = RpRandom() & 0xFFF;
            ratio = (f32)rnd / 4096.0f;
            ((BtlShuffleBackgroundRing *)entry)->angle = 40.0f * ratio - 20.0f;
        }
    }
    *tickp += 1;
    if (*tickp >= 0x140) {
        *tickp = 0;
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    for (i = 0; i < 4; i++) {
        u8 *entry;
        u16 counter;
        u16 limit;
        entry = base + i * 12 + 4;
        limit = ((BtlShuffleBackgroundRing *)entry)->duration;
        counter = ((BtlShuffleBackgroundRing *)entry)->frame;
        if (counter <= limit) {
            f32 fnext;
            f32 flimit;
            f32 s;
            f32 inv;
            f32 q0;
            f32 q1;
            f32 width;
            f32 height;
            f32 eased;
            fnext = (f32)(u32)(++((BtlShuffleBackgroundRing *)entry)->frame);
            flimit = (f32)limit;
            s = sinf(D_00761470 * (fnext / flimit));
            inv = 1.0f - s;
            q0 = ((0.0f + 992.0f) + (f32)1218 * inv) / 254.0f;
            q1 = ((0.0f + 696.0f) + (f32)854 * inv) / 254.0f;
            width = 127.0f * q0;
            height = 127.0f * q1;
            eased = sinf(D_007613EC * inv);
            if (eased < 0.0f) {
                eased = 0.0f;
            }
            sdkSpriteDrawOnceScaled(palette, 1, 320.0f - width, 224.0f - height, 0.0f,
                          0xFF, 0xAE, 0x49, (u8)((f32)(u32)((BtlShuffleBackgroundRing *)entry)->alpha * eased),
                          (u16)(4096.0f * q0), (u16)(4096.0f * q1),
                          ((BtlShuffleBackgroundRing *)entry)->angle, (s16)(s32)width, (s16)(s32)height);
        }
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants on
/* Initialize four wave strips from the read-only defaults, scaling periods and amplitudes. */
// FUN_00389CB0
void btlShuffleInitWaveStrips(u8 *drawWork)
{
    u8 *dst;
    s32 i;
    f32 scale300;
    f32 scale20;
    f32 scaled;

    dst = drawWork + 0xA0;
    i = 0;
    scale300 = 300.0f;
    scale20 = 20.0f;
    for (; i < 4; i++) {
        u8 *s;
        u8 *d;
        d = dst + i * 0x30 + 4;
        s = D_0064EEF0 + i * 0x30;
        ((BtlShuffleWaveStrip *)d)->start[0].x = ((BtlShuffleWaveDefault *)s)->start0.x;
        ((BtlShuffleWaveStrip *)d)->start[0].y = ((BtlShuffleWaveDefault *)s)->start0.y;
        ((BtlShuffleWaveStrip *)d)->end[0].x = ((BtlShuffleWaveDefault *)s)->end0.x;
        ((BtlShuffleWaveStrip *)d)->end[0].y = ((BtlShuffleWaveDefault *)s)->end0.y;
        ((BtlShuffleWaveStrip *)d)->start[1].x = ((BtlShuffleWaveDefault *)s)->start1.x;
        ((BtlShuffleWaveStrip *)d)->start[1].y = ((BtlShuffleWaveDefault *)s)->start1.y;
        ((BtlShuffleWaveStrip *)d)->end[1].x = ((BtlShuffleWaveDefault *)s)->end1.x;
        ((BtlShuffleWaveStrip *)d)->end[1].y = ((BtlShuffleWaveDefault *)s)->end1.y;
        scaled = scale300 * ((BtlShuffleWaveDefault *)s)->duration[0];
        ((BtlShuffleWaveStrip *)d)->duration[0] = (u16)scaled;
        scaled = scale300 * ((BtlShuffleWaveDefault *)s)->duration[1];
        ((BtlShuffleWaveStrip *)d)->duration[1] = (u16)scaled;
        ((BtlShuffleWaveStrip *)d)->amplitude = scale20 * ((BtlShuffleWaveDefault *)s)->amplitude;
        ((BtlShuffleWaveStrip *)d)->color[0] = ((BtlShuffleWaveDefault *)s)->color[0];
        ((BtlShuffleWaveStrip *)d)->color[1] = ((BtlShuffleWaveDefault *)s)->color[1];
        ((BtlShuffleWaveStrip *)d)->color[2] = ((BtlShuffleWaveDefault *)s)->color[2];
        ((BtlShuffleWaveStrip *)d)->color[3] = ((BtlShuffleWaveDefault *)s)->color[3];
    }
}
#pragma pop

typedef union BtlShuffleWavePhase {
    Vec2f direction[2];
    Vec2f pair[2];
} BtlShuffleWavePhase;

typedef struct BtlShuffleWaveWorkspace {
    Vec2f normal[2];
    BtlShuffleWavePhase phase;
    BtlShuffleSkyVertex vertices[62];
    /* Retail leaves sp+0x1030..0x1037 unused; this layout places delta at sp+0x1038. */
    u32 pad[2];
    Vec2f delta;
} BtlShuffleWaveWorkspace;

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Native b210 O2: 1488/1488 bytes, 26 resolved relocations. The
 * 62-vertex workspace preserves the original allocation and vector
 * lifetimes. Its explicit gap has no read or written value.
 * See docs/probe_archive/Shuffle_wave_00389e10_20260923.md. */
// FUN_00389E10
void btlShuffleDrawWave(u8 **drawWork)
{
    extern f32 D_007612D0;
    extern f32 D_007613EC;
    extern f32 sinf(f32);
    extern f32 func_003e41e0(Vec2f *out, const Vec2f *in);
    extern f32 RwV2dLength(const Vec2f *value);
    s32 outer;
    s32 j;
    s32 m;
    s32 idx;
    s32 half;
    s32 found;
    u8 *raw;
    u8 *entry;
    f32 scale;
    f32 z;
    BtlShuffleWaveWorkspace work;

    raw = (u8 *)drawWork + 0xA0;
    z = D_008872F8[0];
    scale = 1.0f / ((MdlEffectCamera *)kwlnGetCamera())->nearPlane;
    D_00887300[0]((RwRenderState)1, (void *)0);
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    for (outer = 0; outer < 4; outer++) {
        entry = raw + outer * 0x30 + 4;
        if (outer == 2) {
            RpSkyRenderStateSet(3, (void *)0x717FB);
            RpSkyRenderStateSet(2, (void *)0x44);
        }
        for (j = 0; j < 2; j++) {
            u16 *cnt;
            u16 *max;
            f32 *fp;
            Vec2f *direction;
            Vec2f *normal;
            cnt = &((BtlShuffleWaveStrip *)entry)->frame[j];
            max = &((BtlShuffleWaveStrip *)entry)->duration[j];
            *cnt = *cnt + 1;
            if (*cnt >= *max) {
                *cnt = 0;
            }
            fp = (f32 *)(entry + j * 8);
            direction = &work.phase.direction[j];
            direction->x = fp[4] - fp[0];
            direction->y = fp[5] - fp[1];
            normal = &((Vec2f *)&work.normal)[j];
            normal->x = -direction->y;
            normal->y = direction->x;
            func_003e41e0(normal, normal);
        }
        {
            s32 k;
            for (k = 0; k < 62; k++) {
                f32 cntf;
                f32 maxf;
                f32 ratio;
                f32 ang;
                f32 w;
                f32 *inp;
                Vec2f *direction;
                Vec2f *normal;
                BtlShuffleSkyVertex *vertex;
                f32 fraction;
                f32 offsetX;
                f32 offsetY;
                f32 productX;
                f32 productY;
                f32 rx;
                f32 ry;
                f32 baseX;
                f32 baseY;
                u8 alpha;
                u8 blue;
                u8 green;
                u8 red;
                idx = k % 2;
                half = k / 2;
                cntf = (f32)((BtlShuffleWaveStrip *)entry)->frame[idx];
                maxf = (f32)((BtlShuffleWaveStrip *)entry)->duration[idx];
                ratio = cntf / maxf;
                ang = D_007612D0 * ratio + D_007613EC * (f32)half / 30.0f;
                w = ((BtlShuffleWaveStrip *)entry)->amplitude * sinf(ang);
                direction = &work.phase.direction[idx];
                fraction = (f32)half / 30.0f;
                offsetX = fraction * direction->x;
                offsetY = fraction * direction->y;
                productX = offsetX;
                productY = offsetY;
                inp = (f32 *)(entry + idx * 8);
                ry = productY + inp[1];
                rx = productX + inp[0];
                baseX = rx;
                baseY = ry;
                normal = &((Vec2f *)&work.normal)[idx];
                baseX = (0.0f + baseX) + w * normal->x;
                baseY = (0.0f + baseY) + w * normal->y;
                alpha = ((BtlShuffleWaveStrip *)entry)->color[3];
                blue = ((BtlShuffleWaveStrip *)entry)->color[2];
                green = ((BtlShuffleWaveStrip *)entry)->color[1];
                red = ((BtlShuffleWaveStrip *)entry)->color[0];
                vertex = &work.vertices[k];
                vertex->u.els.scrVertex.x = baseX;
                vertex->u.els.scrVertex.y = baseY;
                vertex->u.els.scrVertex.z = z;
                vertex->u.els.color.r = (f32)red;
                vertex->u.els.color.g = (f32)green;
                vertex->u.els.color.b = (f32)blue;
                vertex->u.els.color.a = (f32)alpha;
                vertex->u.els.recipZ = scale;
            }
        }
        if (outer < 2) {
            found = 0;
            for (m = 0; m <= 30; m++) {
                BtlShuffleSkyVertex *pair;
                pair = &((BtlShuffleSkyVertex *)&work.vertices)[m * 2];
                work.phase.pair[0].x = pair[0].u.els.scrVertex.x;
                work.phase.pair[0].y = pair[0].u.els.scrVertex.y;
                work.phase.pair[1].x = pair[1].u.els.scrVertex.x;
                work.phase.pair[1].y = pair[1].u.els.scrVertex.y;
                work.delta.x = work.phase.pair[0].x - work.phase.pair[1].x;
                work.delta.y = work.phase.pair[0].y - work.phase.pair[1].y;
                if (RwV2dLength(&work.delta) > 1.0f) {
                    found = 1;
                    break;
                }
            }
        }
        shdEnableBlendFlag();
        if (outer < 2) {
            if (found != 0) {
                RpSkyRenderStateSet(3, (void *)0x71801);
                RpSkyRenderStateSet(2, (void *)0x42);
            }
            D_00887310[0](2, work.vertices, 62);
            if (found != 0) {
                RpSkyRenderStateSet(3, (void *)0x71801);
                RpSkyRenderStateSet(2, (void *)0x48);
            }
        }
        D_00887310[0](4, work.vertices, 62);
        shdDisableBlendFlag();
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Ring work starts four bytes into the 0x28-byte state cleared by its initializer. */
typedef struct BtlShuffleCounter {
    u16 frame;
    u16 flags;
} BtlShuffleCounter;

typedef struct BtlShuffleCount {
    BtlShuffleCounter timing;
    u16 count;
} BtlShuffleCount;

typedef struct BtlShuffleDetail {
    u16 frame, elapsed, flags;
    u8 pad6[2];
    s32 kind, previousKind;
} BtlShuffleDetail;

typedef struct BtlShuffleRing {
    u16 frame;
    u8 pad2[2];
    union { f32 value; s32 bits; } nearRadius, farRadius, angle;
    union { f32 value; s32 bits; } centerX, centerY, scaleX, scaleY;
    u8 color[4];
} BtlShuffleRing;

/* Clear the ring state and initialize its radii, center, scales and color. */
// FUN_0038A3E0
void btlShuffleInitRing(u8 *drawWork)
{
    u8 *rec;

    drawWork += 0x168;
    rec = (u8 *)btlShuffleAddWorkOffset(4, (u32)drawWork);
    memset(drawWork, 0, 0x28);
    *(s16 *)rec = 0;
    ((BtlShuffleRing *)rec)->centerX.value = (f32)0x13D;
    ((BtlShuffleRing *)rec)->centerY.bits = 0x43880000;
    ((BtlShuffleRing *)rec)->scaleX.bits = 0x3F800000;
    ((BtlShuffleRing *)rec)->scaleY.bits = 0x3E800000;
    ((BtlShuffleRing *)rec)->nearRadius.bits = 0x43330000;
    ((BtlShuffleRing *)rec)->farRadius.bits = 0x43610000;
    ((BtlShuffleRing *)rec)->color[0] = 0xD7;
    ((BtlShuffleRing *)rec)->color[1] = 0x84;
    ((BtlShuffleRing *)rec)->color[2] = 0x15;
    ((BtlShuffleRing *)rec)->color[3] = 0xFF;
}
#pragma pop

/* Ring samples use complete three-component vectors and two vertices per
 * sample. The 65 samples occupy the entire 130-vertex buffer. */
typedef struct BtlShuffleRingVertex {
    f32 x, y, z;
    u32 pad0, pad1, pad2;
    f32 reciprocalZ;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} BtlShuffleRingVertex;

static inline void btlShuffleSetRingVertex(BtlShuffleRingVertex *vertex,
    f32 x, f32 y, f32 depth, f32 reciprocalZ, u32 r, u32 g, u32 b, u32 a)
{
    vertex->x = x;
    vertex->y = y;
    vertex->z = depth;
    vertex->color[0] = (f32)r;
    vertex->color[1] = (f32)g;
    vertex->color[2] = (f32)b;
    vertex->color[3] = (f32)a;
    vertex->reciprocalZ = reciprocalZ;
}

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
/* Native b210 O2: 1204/1216 bytes, 19 resolved relocations, 12 zero tail bytes. */
/* Build and draw two vertices for each of sixty-five ring samples. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 823..994); retain only the failing byte-base accesses. */
// FUN_0038A480
void btlShuffleDrawRing(u8 *drawWork)
{
    extern BtlShuffleMatrix *func_003e0f80(void);
    extern BtlShuffleMatrix *RwMatrixRotate(BtlShuffleMatrix *, const BtlShuffleVec3 *, f32, BtlShuffleCombine);
    extern BtlShuffleVec3 *func_003e42a0(BtlShuffleVec3 *, const BtlShuffleVec3 *, const BtlShuffleMatrix *);
    extern s32 func_003e0f40(BtlShuffleMatrix *);
    extern f32 sinf(f32);
    extern f32 cosf(f32);
    extern f32 iGpffff81e0;
    BtlShuffleRingVertex vertices[130];
    BtlShuffleVec3 position;
    BtlShuffleVec3 axis;
    f32 angle;
    f32 depth;
    f32 reciprocalZ;
    f32 displacement;
    f32 blend;
    f32 nearRadius;
    f32 farRadius;
    BtlShuffleMatrix *matrix;
    s32 i;
    s32 count;

    depth = D_008872F8[0];
    reciprocalZ = 1.0f / ((MdlEffectCamera *)kwlnGetCamera())->nearPlane;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    blend = *(f32 *)(drawWork + 0x1C);
    nearRadius = ((BtlShuffleRing *)drawWork)->nearRadius.value;
    farRadius = ((BtlShuffleRing *)drawWork)->farRadius.value;
    displacement = (1.0f - blend * blend) * (farRadius * blend - nearRadius * blend);
    matrix = func_003e0f80();
    RwMatrixRotate(matrix, &axis, ((BtlShuffleRing *)drawWork)->angle.value, rwCOMBINEREPLACE);
    i = 0;
    count = 0;
    for (; i <= 64; i++) {
        f32 negativeSine;
        angle = (iGpffff81e0 * (f32)i) / 64.0f;
        negativeSine = sinf(angle);
        angle = cosf(angle);
        negativeSine = -negativeSine;
        position.x = negativeSine * *(f32 *)(drawWork + 0x18);
        position.y = angle * *(f32 *)(drawWork + 0x1C);
        position.z = 0.0f;
        func_003e42a0(&position, &position, matrix);
        btlShuffleSetRingVertex(&vertices[count++],
            (0.0f + *(f32 *)(drawWork + 0x10)) + position.x * ((BtlShuffleRing *)drawWork)->farRadius.value,
            (0.0f + *(f32 *)(drawWork + 0x14)) + position.y * ((BtlShuffleRing *)drawWork)->farRadius.value,
            depth, reciprocalZ, *(u8 *)(drawWork + 0x20), *(u8 *)(drawWork + 0x21),
            *(u8 *)(drawWork + 0x22), *(u8 *)(drawWork + 0x23));
        position.x = negativeSine * *(f32 *)(drawWork + 0x18);
        position.y = angle * *(f32 *)(drawWork + 0x1C);
        position.z = 0.0f;
        func_003e42a0(&position, &position, matrix);
        btlShuffleSetRingVertex(&vertices[count++],
            (0.0f + *(f32 *)(drawWork + 0x10)) + position.x * ((BtlShuffleRing *)drawWork)->nearRadius.value,
            ((0.0f + *(f32 *)(drawWork + 0x14)) + position.y * ((BtlShuffleRing *)drawWork)->nearRadius.value) - displacement,
            depth, reciprocalZ, *(u8 *)(drawWork + 0x20), *(u8 *)(drawWork + 0x21),
            *(u8 *)(drawWork + 0x22), *(u8 *)(drawWork + 0x23));
    }
    if (count <= 130) {
    } else {
        kAssertFail(D_0064F0E0, 0x21E);
    }
    func_003e0f40(matrix);
    D_00887300[0]((RwRenderState)1, (void *)0);
    shdEnableBlendFlag();
    D_00887310[0](4, vertices, count);
    shdDisableBlendFlag();
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation off
/* Update the ring center and shape for its active, exit or idle phase, then draw it. */
// FUN_0038A940
void btlShuffleUpdateRing(u8 **drawWork)
{
    extern f32 D_00761288;
    extern f32 D_00761300;
    extern f32 D_00761490;
    extern f32 D_007612D0;
    extern f32 DAT_007613f8;
    extern f32 btlShuffleCalcWave(f32, f32, f32, s32);
    extern f32 sinf(f32);
    extern void btlShuffleDrawRing(u8 *);
    u8 *state = (u8 *)drawWork + 0x168;
    u8 *work = state + 4;
    u16 flags = *(u16 *)state;
    f32 t;
    if (flags & 1) {
        f32 c10 = 317.0f;
        f32 old10 = ((BtlShuffleRing *)work)->centerX.value;
        f32 diff10 = c10 - old10;
        f32 k = D_00761288;
        ((BtlShuffleRing *)work)->centerX.value = k * diff10 + old10;
        {
            f32 old14 = ((BtlShuffleRing *)work)->centerY.value;
            f32 diff14 = 212.0f - old14;
            ((BtlShuffleRing *)work)->centerY.value = k * diff14 + old14;
        }
        {
            f32 old18 = ((BtlShuffleRing *)work)->scaleX.value;
            f32 diff18 = D_00761300 - old18;
            ((BtlShuffleRing *)work)->scaleX.value = k * diff18 + old18;
        }
        {
            f32 old1C = ((BtlShuffleRing *)work)->scaleY.value;
            f32 diff1C = 1.0f - old1C;
            ((BtlShuffleRing *)work)->scaleY.value = k * diff1C + old1C;
        }
        ((BtlShuffleRing *)work)->nearRadius.value += 144.0f - ((BtlShuffleRing *)work)->nearRadius.value;
        ((BtlShuffleRing *)work)->farRadius.value += 165.0f - ((BtlShuffleRing *)work)->farRadius.value;
        {
            f32 old0C = ((BtlShuffleRing *)work)->angle.value;
            f32 neg0C = -old0C;
            ((BtlShuffleRing *)work)->angle.value = k * neg0C + old0C;
        }
    } else if (flags & 2) {
        t = btlShuffleCalcWave((f32)((BtlShuffleRing *)work)->frame, 0.0f, 5.0f, 2);
        ((BtlShuffleRing *)work)->centerX.value = (f32)0x13D;
        ((BtlShuffleRing *)work)->centerY.value = 212.0f + 60.0f * t;
        ((BtlShuffleRing *)work)->scaleX.value = D_00761300 + D_00761490 * t;
        ((BtlShuffleRing *)work)->scaleY.value = 1.0f + (-0.75f) * t;
        ((BtlShuffleRing *)work)->nearRadius.value = 144.0f + 35.0f * t;
        ((BtlShuffleRing *)work)->farRadius.value = 165.0f + 60.0f * t;
        if (++((BtlShuffleRing *)work)->frame >= 5) {
            *(u16 *)state &= (u16)0xFFFD;
            ((BtlShuffleRing *)work)->frame = 0;
        }
    } else {
        ++((BtlShuffleRing *)work)->frame;
        if (((BtlShuffleRing *)work)->frame >= 300) {
            ((BtlShuffleRing *)work)->frame = 0;
        }
        ((BtlShuffleRing *)work)->scaleY.value = 0.25f + DAT_007613f8 * sinf(D_007612D0 * (f32)((BtlShuffleRing *)work)->frame / 150.0f);
        ((BtlShuffleRing *)work)->angle.value = 15.0f * sinf(D_007612D0 * (f32)((BtlShuffleRing *)work)->frame / 300.0f);
    }
    btlShuffleDrawRing(work);
}
#pragma pop

typedef struct BtlShuffleRevealWeight {
    f32 value;
} BtlShuffleRevealWeight;

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants on
#pragma opt_propagation on
/* Animate five paired reveal bands and their center fill for the current pattern. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 963..963); retain only the failing byte-base accesses. */
// FUN_0038ACD0
void btlShuffleDrawRevealBands(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern f32 fGpffff83a4;
    extern u8 D_0064F090[];
    BtlShuffleRevealWeight factors[5];
    Vec2f point;
    u8 *state;
    u8 *entry;
    s32 span;
    s32 i;
    s32 j;
    s32 k;
    s32 type;
    u16 flags;
    u16 counter;
    f32 tail;
    f32 lower;
    f32 upper;
    f32 elapsed;
    f32 width;
    f32 off;
    f32 half;
    f32 fac;
    f32 distance;

    state = drawWork + 0x1B4;
    type = ((BtlShuffleContext *)((BtlShuffleCardWork *)drawWork)->context)->pattern;
    switch (type) {
    case 3:
        span = 20;
        lower = 196.0f;
        upper = 320.0f;
        break;
    case 4:
        span = 20;
        lower = 185.0f;
        upper = fGpffff83a4;
        break;
    }
    flags = ((BtlShuffleCounter *)state)->flags;
    if ((flags & 1) == 0) {
        for (i = 0; i < 5; i++) {
            entry = D_0064F090 + i * 0x10;
            elapsed = (f32)(u32)((BtlShuffleCounter *)state)->frame;
            factors[i].value = btlShuffleCalcWave(elapsed, (f32)span * ((BtlShuffleRevealBand *)entry)->start, (f32)span * ((BtlShuffleRevealBand *)entry)->end, 1);
        }
        elapsed = (f32)(u32)((BtlShuffleCounter *)state)->frame;
        tail = btlShuffleCalcWave(elapsed, 0.25f * (f32)span, (f32)span, 1);
        counter = ++((BtlShuffleCounter *)state)->frame;
        if (counter >= span) {
            *(u16 *)(state + 2) |= 1;
            ((BtlShuffleCounter *)state)->frame = 0;
        }
    } else if (flags & 2) {
        for (i = 0; i < 5; i++) {
            entry = D_0064F090 + i * 0x10;
            elapsed = (f32)(u32)((BtlShuffleCounter *)state)->frame;
            factors[i].value = 1.0f - btlShuffleCalcWave(elapsed, (f32)span * ((BtlShuffleRevealBand *)entry)->start, (f32)span * ((BtlShuffleRevealBand *)entry)->end, 1);
        }
        elapsed = (f32)(u32)((BtlShuffleCounter *)state)->frame;
        tail = 1.0f - btlShuffleCalcWave(elapsed, 0.25f * (f32)span, (f32)span, 1);
        counter = ++((BtlShuffleCounter *)state)->frame;
        if (counter >= span) {
            ((BtlShuffleCardWork *)drawWork)->flags &= (u16)0xFFDF;
        }
    } else {
        j = 0;
        for (; j < 5; j++) {
            factors[j].value = 1.0f;
        }
        tail = 1.0f;
    }
    RpSkyRenderStateSet(3, (void *)0x71801);
    RpSkyRenderStateSet(2, (void *)0x48);
    point.y = 224.0f;
    k = 0;
    half = lower / 2.0f;
    for (; k < 5; k++) {
        entry = (u8 *)&factors[k];
        fac = ((BtlShuffleRevealWeight *)entry)->value;
        entry = D_0064F090 + k * 0x10;
        width = ((BtlShuffleRevealBand *)entry)->width * fac;
        distance = half + ((BtlShuffleRevealBand *)entry)->distance;
        off = distance * fac;
        point.x = upper + off;
        shdDrawRotatedRect(point, 0.0f, 0xFF403DFF, width, 448.0f, 0.0f, 0);
        point.x = upper - off;
        shdDrawRotatedRect(point, 0.0f, 0xFF403DFF, width, 448.0f, 0.0f, 0);
    }
    width = lower * tail;
    point.x = upper;
    shdDrawRotatedRect(point, 0.0f, 0xFF403DFF, width, 448.0f, 0.0f, 0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Draw eleven timed sprites with sliding positions and two color groups. */
// FUN_0038B1C0
void btlShuffleDrawSpriteCues(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame,
                             s32 curve);
    extern s32 D_0064EFB0[];
    u8 *base;
    s32 palette;
    s32 i;
    u16 *counter;
    f32 alpha;
    f32 scaled;
    u8 alphaByte;
    u8 red;
    u8 green;
    u8 blue;
    counter = (u16 *)(drawWork + 0x164);
    base = ((BtlShuffleCardWork *)drawWork)->context;
    palette = ((BtlShuffleContext *)base)->spriteResource;
    if (*counter < 30) {
        ++*counter;
    }
    for (i = 0; i < 11; i++) {
        u8 *entry;
        entry = (u8 *)D_0064EFB0 + i * 0x14;
        if (*counter < ((BtlShuffleSpriteCue *)entry)->start) {
            alpha = 0.0f;
        } else if (*counter < ((BtlShuffleSpriteCue *)entry)->end) {
            alpha = btlShuffleCalcWave(
                (f32)*counter,
                (f32)((BtlShuffleSpriteCue *)entry)->start,
                (f32)((BtlShuffleSpriteCue *)entry)->end,
                1);
        } else {
            alpha = 1.0f;
        }
        if (i == 5) {
            RpSkyRenderStateSet(3, (void *)0x71801);
            RpSkyRenderStateSet(2, (void *)0x48);
        }
        if (i < 5) {
            red = 0xFF;
            green = 0xBE;
            blue = 0x5A;
            scaled = 206.0f * alpha;
            alphaByte = (u8)scaled;
        } else {
            red = 0x2B;
            green = 0x26;
            blue = 0x1E;
            scaled = 255.0f * alpha;
            alphaByte = (u8)scaled;
        }
        sdkSpriteDrawOnceAt(
            palette,
            ((BtlShuffleSpriteCue *)((u8 *)D_0064EFB0 + i * 0x14))->sprite,
            30.0f * (1.0f - alpha) +
                ((BtlShuffleSpriteCue *)((u8 *)D_0064EFB0 + i * 0x14))->x + 0.0f,
            ((BtlShuffleSpriteCue *)((u8 *)D_0064EFB0 + i * 0x14))->y,
            red, green, blue, alphaByte);
    }
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation off
/* Draw the card-task background pulse, rings, wave strips and sprite cues. */
// FUN_0038B490
void btlShuffleDrawCardBackground(s32 drawWork, u8 **input)
{
    s32 resource;
    sdkRenderStateSetDefault();
    btlShuffleDrawBackgroundPulse(input);
    btlShuffleDrawBackgroundRings(input);
    resource = ((BtlShuffleContext *)*input)->backdropResource;
    sdkSpriteDrawOnceAt(resource, 0, 0.0f, 0.0f, 0xDA, 0x8C, 0x17, 0xC0);
    btlShuffleDrawWave(input);
    btlShuffleUpdateRing(input);
    btlShuffleDrawSpriteCues((u8 *)input);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Draw the detail-kind sprite group translated by the supplied XY offset. */
// FUN_0038B530
void btlShuffleDrawDetailSprites(u8 *drawWork, s32 input, const Vec2f *offset)
{
    s32 handle;
    f32 x;
    f32 y;

    handle = ((BtlShuffleContext *)((BtlShuffleCardWork *)drawWork)->context)->spriteResource;
    switch (input) {
    case 1:
        sdkSpriteDrawOnceAt(handle, 0x40, 492.0f + offset->x,
                      407.0f + offset->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 507.0f + offset->x;
        y = 403.0f + offset->y;
        sdkSpriteDrawOnceScaled(handle, 0x41, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        sdkSpriteDrawOnceAt(handle, 6, 528.0f + offset->x,
                      416.0f + offset->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 541.0f + offset->x;
        y = 414.0f + offset->y;
        sdkSpriteDrawOnceScaled(handle, 1, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 2:
        sdkSpriteDrawOnceAt(handle, 6, 528.0f + offset->x,
                      417.0f + offset->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 541.0f + offset->x;
        y = 414.0f + offset->y;
        sdkSpriteDrawOnceScaled(handle, 3, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 3:
        sdkSpriteDrawOnceAt(handle, 7, 493.0f + offset->x,
                      361.0f + offset->y, 0xB4, 0xB4, 0xB4, 0xFF);
        x = 504.0f + offset->x;
        y = 358.0f + offset->y;
        sdkSpriteDrawOnceScaled(handle, 4, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        sdkSpriteDrawOnceAt(handle, 6, 479.0f + offset->x,
                      397.0f + offset->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 492.0f + offset->x;
        y = 394.0f + offset->y;
        sdkSpriteDrawOnceScaled(handle, 5, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    case 4:
        sdkSpriteDrawOnceAt(handle, 0x14, 483.0f + offset->x,
                      413.0f + offset->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 498.0f + offset->x;
        y = 410.0f + offset->y;
        sdkSpriteDrawOnceScaled(handle, 0x1D, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        sdkSpriteDrawOnceAt(handle, 6, 528.0f + offset->x,
                      414.0f + offset->y, 0xFF, 0xFF, 0xFF, 0xFF);
        x = 542.0f + offset->x;
        y = 414.0f + offset->y;
        sdkSpriteDrawOnceScaled(handle, 0x13, x, y, 0.0f, 0xFF, 0xDB, 0x76,
                      0xFF, 0x1000, 0x1000, -30.0f, 0, 0);
        break;
    default:
        kAssertFail(D_0064F0E0, 0x3B2);
        break;
    }
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Native b210 O2: 1608/1616 bytes with eight zero alignment bytes.
 * The complete point owns the centered X coordinate before it is retained
 * for the second strip. The detail renderer consumes the same two-float point.
 * See docs/probe_archive/First_party_field_menu_shuffle_20260923.md. */
/* Animate detail bars and their separately timed sprite-group entrance and exit. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 1190..1245); retain only the failing byte-base accesses. */
// FUN_0038BAB0
void btlShuffleDrawDetailBars(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32, f32, f32, s32);
    extern f32 fGpffff83a8;
    extern f32 fGpffff83ac;
    extern f32 fGpffff83b0;
    extern f32 fGpffff83b4;
    extern f32 fGpffff83b8;
    u8 *state;
    u16 flags;
    f32 mainFactor;
    f32 detailEnter;
    f32 detailExit;
    f32 verticalTravel;
    f32 detailX;
    f32 detailY;
    f32 verticalOffset;
    f32 trailingFactor;
    f32 horizontalOffset;
    f32 centerX;
    f32 shiftedY;
    f32 displacement;
    Vec2f point;

    state = drawWork + 0x190;
    flags = ((BtlShuffleCardWork *)drawWork)->detailFlags;
    if (!(flags & 1)) {
        mainFactor = btlShuffleCalcWave((f32)(u32)((BtlShuffleDetail *)state)->frame, 0.0f, 8.0f, 2);
        trailingFactor = btlShuffleCalcWave((f32)(u32)((BtlShuffleDetail *)state)->frame, 2.0f, 10.0f, 2);
        if (++((BtlShuffleDetail *)state)->frame >= 10) {
            ((BtlShuffleDetail *)state)->flags |= 1;
            ((BtlShuffleDetail *)state)->frame = 0;
        } else if (((BtlShuffleDetail *)state)->frame == 8) {
            ((BtlShuffleDetail *)state)->flags |= 0x10;
        }
    } else if (!(flags & 0x20) && (flags & 4)) {
        mainFactor = 1.0f - btlShuffleCalcWave((f32)(u32)((BtlShuffleDetail *)state)->frame, 0.0f, 5.0f, 2);
        trailingFactor = 1.0f - btlShuffleCalcWave((f32)(u32)((BtlShuffleDetail *)state)->frame, 2.0f, 7.0f, 2);
        if (++((BtlShuffleDetail *)state)->frame >= 7) {
            ((BtlShuffleCardWork *)drawWork)->flags &= 0xFFFE;
        }
    } else {
        mainFactor = 1.0f;
        trailingFactor = mainFactor;
    }

    flags = ((BtlShuffleDetail *)state)->flags;
    if (flags & 0x10) {
        if (!(flags & 8)) {
            detailEnter = btlShuffleCalcWave((f32)(u32)((BtlShuffleDetail *)state)->elapsed, 0.0f, 5.0f, 1);
            if (++*(u16 *)(state + 2) >= 5) {
                *(u16 *)(state + 4) |= 8;
                *(u16 *)(state + 2) = 0;
            }
        } else {
            detailEnter = 1.0f;
        }
        if (*(u16 *)(state + 4) & 0x20) {
            detailExit = btlShuffleCalcWave((f32)(u32)((BtlShuffleDetail *)state)->elapsed, 0.0f, 5.0f, 1);
            if (++*(u16 *)(state + 2) >= 5) {
                *(u16 *)(state + 4) &= 0xFFDF;
                *(u16 *)(state + 4) &= 0xFFEF;
                *(u16 *)(state + 2) = 0;
            }
        } else {
            detailExit = 0.0f;
        }
    } else {
        detailEnter = 0.0f;
        detailExit = detailEnter;
    }
    if (((BtlShuffleDetail *)state)->kind == 3) {
        horizontalOffset = 0.0f;
        verticalOffset = -48.0f;
    } else {
        horizontalOffset = 0.0f;
        verticalOffset = horizontalOffset;
    }
    if (*(u16 *)(state + 4) & 2) {
        verticalTravel = 130.0f;
        detailX = 170.0f;
        detailY = -100.0f;
    } else {
        verticalTravel = 100.0f;
        detailX = 120.0f;
        detailY = -70.0f;
    }
    point.x = fGpffff83a8 + (410.0f + horizontalOffset);
    {
        f32 remainder = 1.0f - trailingFactor;
        f32 base = fGpffff83ac + ((f32)517 + verticalOffset);
        point.y = (0.0f + base) + verticalTravel * remainder;
    }
    shdDrawRotatedRect(point, 0.0f, 0xFF0000FF, 430.0f, 5.0f, fGpffff83b0, 1);
    centerX = 300.0f + horizontalOffset;
    point.x = fGpffff83b4 + centerX;
    centerX = point.x;
    displacement = verticalTravel * (1.0f - mainFactor);
    shiftedY = fGpffff83b8 + ((f32)553 + verticalOffset);
    point.y = shiftedY + displacement;
    shdDrawRotatedRect(point, 0.0f, 0xFF, 430.0f, 21.0f, fGpffff83b0, 1);
    if (*(u16 *)(state + 4) & 2) {
        point.x = centerX;
        shiftedY = fGpffff83b8 + (524.0f + verticalOffset);
        point.y = shiftedY + displacement;
        shdDrawRotatedRect(point, 0.0f, 0xFF, 430.0f, 21.0f, fGpffff83b0, 1);
    }
    {
        s32 mode = *(s32 *)(state + 8);
        if (mode) {
            f32 t = (1.0f - detailEnter) - detailExit;
            point.x = detailX * t;
            point.y = detailY * t;
            btlShuffleDrawDetailSprites(drawWork, mode, &point);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Eight-frame count transition; five-frame fade-out. Extent and remainder
 * values preserve the two independently scaled sprite coordinates. */
/* Native b210 O2: 1640/1648 bytes, 12 resolved relocations, eight zero tail bytes. */
/* Animate count entrance, exit and changes, latching the new count midway. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 1174..1287); retain only the failing byte-base accesses. */
// FUN_0038C100
void btlShuffleDrawCountTransition(u8 *drawWork)
{
    extern f32 btlShuffleCalcWave(f32, f32, f32, s32);
    u8 *ctx;
    u8 *state;
    u8 *info;
    u8 alpha;
    s32 handle;
    f32 scale;
    f32 first;
    f32 scaleY;
    f32 remainderX;
    f32 remainderY;
    f32 extentX;
    f32 extentY;
    f32 drawX;
    f32 drawY;
    u16 flags;
    u16 step;

    state = drawWork + 0x1A4;
    ctx = ((BtlShuffleCardWork *)drawWork)->context;
    handle = ((BtlShuffleContext *)ctx)->spriteResource;
    if (((BtlShuffleContext *)ctx)->pattern != 3) {
        kAssertFail(D_0064F0E0, 0x44D);
    }
    info = ctx + 0x1F1D0;
    flags = ((BtlShuffleCounter *)state)->flags;
    if (!(flags & 1)) {
        scale = btlShuffleCalcWave((f32)(u32)((BtlShuffleCounter *)state)->frame, 4.0f, 8.0f, 0);
        scaleY = 1.0f;
        alpha = (u8)(255.0f * btlShuffleCalcWave((f32)(u32)((BtlShuffleCounter *)state)->frame, 0.0f, 8.0f, 1));
        step = ++((BtlShuffleCounter *)state)->frame;
        if (step >= 8) {
            *(u16 *)(state + 2) = *(u16 *)(state + 2) | 1;
            ((BtlShuffleCounter *)state)->frame = 0;
        }
    } else if (flags & 2) {
        scale = 1.0f;
        scaleY = scale;
        alpha = (u8)(255.0f * (1.0f - btlShuffleCalcWave((f32)(u32)((BtlShuffleCounter *)state)->frame, 0.0f, 5.0f, 1)));
        step = ++((BtlShuffleCounter *)state)->frame;
        if (step >= 5) {
            ((BtlShuffleCardWork *)drawWork)->flags = ((BtlShuffleCardWork *)drawWork)->flags & 0xFFFD;
        }
    } else if (flags & 4) {
        first = btlShuffleCalcWave((f32)(u32)((BtlShuffleCounter *)state)->frame, 4.0f, 8.0f, 0);
        first = first - btlShuffleCalcWave((f32)(u32)((BtlShuffleCounter *)state)->frame, 0.0f, 4.0f, 0);
        scaleY = 1.0f;
        scale = scaleY + first;
        alpha = (u8)255.0f;
        step = ++((BtlShuffleCounter *)state)->frame;
        if (step >= 8) {
            *(u16 *)(state + 2) = *(u16 *)(state + 2) & 0xFFFB;
            ((BtlShuffleCounter *)state)->frame = 0;
        } else if (((BtlShuffleCounter *)state)->frame == 4) {
            *(u16 *)(state + 4) = *(u16 *)(info + 8);
        }
    } else {
        scale = 1.0f;
        scaleY = scale;
        alpha = (u8)255.0f;
        if (*(u16 *)(info + 8) != *(u16 *)(state + 4)) {
            *(u16 *)(state + 2) = flags | 4;
        }
    }
    sdkSpriteDrawOnceAt(handle, 0x2B, (f32)578, (f32)417, 0x8E, 0x31, 0, alpha);
    sdkSpriteDrawOnceAt(handle, 0x2A, (f32)543, 408.0f, 0x8E, 0x31, 0, alpha);
    sdkSpriteDrawOnceAt(handle, *(u16 *)(info + 0xA) + 0x1F, (f32)559, 414.0f, 0x8E, 0x31, 0, alpha);
    remainderX = 1.0f - scale;
    extentX = 29.0f;
    drawX = (f32)515 + (remainderX * extentX) / 2.0f;
    remainderY = 1.0f - scaleY;
    extentY = 26.0f;
    drawY = (f32)407 + (remainderY * extentY) / 2.0f;
    sdkSpriteDrawOnceScaled(handle, (*(u16 *)(info + 0xA) + 0x2D) - *(u16 *)(state + 4), drawX, drawY, 0, 0, 0, 0, alpha, (u16)(4096.0f * scale), (u16)(4096.0f * scaleY), 0.0f, 0, 0);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Project each card, offset its screen position, and draw a fading colored copy. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 630..630); retain only the failing byte-base accesses. */
// FUN_0038C770
void btlShuffleDrawCardShadow(u8 *drawWork)
{
    extern void btlShuffleCalcScaleStep(u8 *screen, f32 depth, u8 *output);
    extern s32 btlShuffleCalcUpdateSpeed(u8 *point, u8 *screen);
    extern f32 btlShuffleCalcWave(f32 frame, f32 startFrame, f32 endFrame, s32 curve);
    extern s32 btlShuffleDrawTableLookup(s32 cardCount, s32 pattern);
    struct Work {
        BtlShuffleVec3 input;
        f32 pad0;
        f32 out0;
        f32 out1;
        f32 pad1;
        u8 colors[4];
    };
    struct Work work;
    f32 inRamp;
    f32 outRamp;
    f32 inAlpha;
    f32 outAlpha;
    u8 *base;
    s32 count;
    s32 i;

    {
        u8 *state;
        u16 flags;
        u16 value;
        u16 next;

        state = drawWork + 0x1A0;
        base = ((BtlShuffleCardWork *)drawWork)->context;
        count = btlShuffleDrawTableLookup(((BtlShuffleContext *)base)->cardCount,
                              ((BtlShuffleContext *)base)->pattern);
        flags = ((BtlShuffleCounter *)state)->flags;
        if ((flags & 1) == 0) {
            value = ((BtlShuffleCounter *)state)->frame;
            inRamp = (f32)(u16)value;
            inAlpha = 102.0f *
                btlShuffleCalcWave(inRamp, 0.0f, 20.0f, 1);
            work.colors[3] = (u8)inAlpha;
            next = ++((BtlShuffleCounter *)state)->frame;
            if (next >= 0x14) {
                *(u16 *)(state + 2) |= 1;
                ((BtlShuffleCounter *)state)->frame = 0;
            }
        } else if ((flags & 2) != 0) {
            value = ((BtlShuffleCounter *)state)->frame;
            outRamp = (f32)(u16)value;
            outAlpha = 102.0f *
                (1.0f - btlShuffleCalcWave(outRamp, 0.0f, 20.0f, 1));
            work.colors[3] = (u8)outAlpha;
            next = ++((BtlShuffleCounter *)state)->frame;
            if (next >= 0x14) {
                ((BtlShuffleCardWork *)drawWork)->flags &= 0xFFFB;
            }
        } else {
            work.colors[3] = 0x66;
        }
    }
    work.colors[0] = 0xDC;
    work.colors[1] = 0x8D;
    work.colors[2] = 0;
    for (i = 0; i < count; i++) {
        {
            u8 *entry;
            entry = base + (i * 0xE8) + 0x1D6B8;
            work.input = *(BtlShuffleVec3 *)entry;
        }
        btlShuffleCalcUpdateSpeed((u8 *)&work.input, (u8 *)&work.out0);
        work.out0 += 6.0f;
        work.out1 += 5.0f;
        btlShuffleCalcScaleStep((u8 *)&work.out0, work.input.z, (u8 *)&work.input);
        {
            u8 *drawBase;
            s32 drawIndex;
            const BtlShuffleVec3 *drawInput;
            u8 *drawColors;
            s32 drawMode;
            drawBase = base;
            drawIndex = i;
            drawInput = &work.input;
            drawColors = work.colors;
            drawMode = 1;
            btlShuffleDrawCardSprites(drawBase, drawIndex, drawInput, drawColors, drawMode);
        }
    }
}
#pragma pop

typedef union BtlShuffleSelectionValue { f32 value; s32 bits; } BtlShuffleSelectionValue;
typedef struct BtlShuffleSelection {
    u16 counter;
    u16 pad;
    BtlShuffleSelectionValue centerX, top, width, targetWidth;
} BtlShuffleSelection;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u32 pad0;
    u32 pad1;
    u32 pad2;
    f32 scale;
    u32 pad3;
    f32 color[4];
    u32 tail[4];
} BtlShuffleSelectionVertex;

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Ease the selected column position and width and render its full-height quad. */
// FUN_0038CAB0
void btlShuffleDrawSelectionColumn(u8 *drawWork)
{
    u8 *base;
    s32 mode;
    f32 depth;
    f32 reciprocalZ;
    f32 blend;
    f32 fade;
    f32 centerX;
    f32 half;
    f32 left;
    f32 right;
    f32 y2;
    BtlShuffleSelectionVertex work[4];
    BtlShuffleSelection *state;

    state = (BtlShuffleSelection *)(drawWork + 0x1A0);
    base = ((BtlShuffleCardWork *)drawWork)->context + 0x1F1D0;
    depth = D_008872F8[0];
    reciprocalZ = 1.0f / ((MdlEffectCamera *)kwlnGetCamera())->nearPlane;
    mode = ((BtlShuffleSequence *)base)->choice;
    mode = (mode < 3) ? mode : 2;
    if (state->counter < 10) {
        state->counter += 1;
        blend = 1.0f - cosf((D_00761470 * (f32)state->counter) / 10.0f);
    } else {
        blend = 1.0f;
        if (state->targetWidth.value == 0.0f) {
            ((BtlShuffleCardWork *)drawWork)->flags &= 0xFFF7;
        }
    }
    state->centerX.value = state->centerX.value + 0.25f * (207.0f + 107.0f * (f32)mode - state->centerX.value);
    state->width.value += blend * (state->targetWidth.value - state->width.value);
    fade = state->top.value;
    centerX = state->centerX.value;
    half = state->width.value / 2.0f;
    left = centerX - half;
    work[0].x = left;
    work[0].y = fade;
    work[0].z = depth;
    work[0].color[0] = 224.0f;
    work[0].color[1] = 127.0f;
    work[0].color[2] = 0.0f;
    work[0].color[3] = 255.0f;
    work[0].scale = reciprocalZ;
    right = centerX + half;
    work[1].x = right;
    work[1].y = fade;
    work[1].z = depth;
    work[1].color[0] = 224.0f;
    work[1].color[1] = 127.0f;
    work[1].color[2] = 0.0f;
    work[1].color[3] = 255.0f;
    work[1].scale = reciprocalZ;
    y2 = fade + 448.0f;
    work[2].x = left;
    work[2].y = y2;
    work[2].z = depth;
    work[2].color[0] = 224.0f;
    work[2].color[1] = 127.0f;
    work[2].color[2] = 0.0f;
    work[2].color[3] = 255.0f;
    work[2].scale = reciprocalZ;
    work[3].x = right;
    work[3].y = y2;
    work[3].z = depth;
    work[3].color[0] = 224.0f;
    work[3].color[1] = 127.0f;
    work[3].color[2] = 0.0f;
    work[3].color[3] = 255.0f;
    work[3].scale = reciprocalZ;
    D_00887300[0]((RwRenderState)1, (void *)0);
    shdEnableBlendFlag();
    D_00887310[0](4, &work[0], 4);
    shdDisableBlendFlag();
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Dispatch enabled card-task foreground components after restoring render state. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 138..138); retain only the failing byte-base accesses. */
// FUN_0038CD70
void btlShuffleDrawCardForeground(u8 *drawWork, u8 *input)
{
    u8 *p;

    p = input;
    sdkRenderStateSetDefault();
    if (*(u16 *)(p + 4) & 0x20) {
        btlShuffleDrawRevealBands(p);
    }
    if (*(u16 *)(p + 4) & 1) {
        btlShuffleDrawDetailBars(p);
    }
    if (*(u16 *)(p + 4) & 2) {
        btlShuffleDrawCountTransition(p);
    }
    if (*(u16 *)(p + 4) & 4) {
        btlShuffleDrawCardShadow(p);
    }
    if (*(u16 *)(p + 4) & 8) {
        btlShuffleDrawSelectionColumn(p);
    }
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Append the card task background and foreground primitive nodes to their queues. */
// FUN_0038CE30
s32 btlShuffleDrawCardStep(u8 *drawWork) {
    u8 *p = ((KwlnTask *)drawWork)->work;

    ((BtlRenderNode *)(p + 8))->unk00 = 0;
    ((BtlRenderNode *)(p + 0x8))->unk04 = 0;
    PrimAppendNode(D_00794990, p + 8);
    ((BtlRenderNode *)(p + 0x38))->unk00 = 0;
    ((BtlRenderNode *)(p + 0x38))->unk04 = 0;
    PrimAppendNode(D_00794E40, p + 0x38);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_0038CE90
void btlShuffleDrawCardDestroy(u8 *drawWork)
{
    jtbl_008873EC[0](((KwlnTask *)drawWork)->work);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Allocate 0x1B8 bytes of card work, initialize its ring and waves, and register both drawing callbacks. */
// FUN_0038CEC0
u8 *btlShuffleDrawCardCreate(s32 drawWork)
{
    u8 *work;
    u8 *task;

    chkmemAllocSiteTag(D_0064F0E0, 0x59D);
    work = D_008873F4[0](1, 0x1B8, 0x40000);
    if (work == NULL) {
        kAssertFail(D_0064F0E0, 0x59E);
    }
    task = kwlnTaskCreateChild((void *)(drawWork), (const void *)(D_0064EED0), 0x13, 0, 0, btlShuffleDrawCardStep, btlShuffleDrawCardDestroy, (u8 *)(work));
    if (task == NULL) {
        kAssertFail(D_0064F0E0, 0x5A8);
    }
    *(s32 *)work = btlShuffleGetDrawContext(drawWork);
    btlShuffleInitRing(work);
    btlShuffleInitWaveStrips(work);
    memset(work + 8, 0, 0x30);
    ((BtlRenderNode *)(work + 0x8))->callback = (void *)btlShuffleDrawCardBackground;
    ((BtlRenderNode *)(work + 8))->work = work;
    memset(work + 0x38, 0, 0x30);
    ((BtlRenderNode *)(work + 0x38))->callback = (void *)btlShuffleDrawCardForeground;
    ((BtlRenderNode *)(work + 0x38))->work = work;
    btlShuffleDrawCardReset(task);
    return task;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_0038D020
void btlShuffleDrawCardReset(u8 *drawWork)
{
    u8 *p;
    u16 *field;
    u16 value;

    p = ((KwlnTask *)drawWork)->work;
    field = (u16 *)(p + 0x168);
    ((BtlShuffleCardWork *)p)->flags = 0;
    value = *field;
    if (value & 1) {
        *field = value & 0xFFFE;
        *field = *field | 2;
        field[2] = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Enable detail drawing and reset the complete sixteen-byte detail animation. */
// FUN_0038D060
void btlShuffleDrawCardActivate(u8 *drawWork)
{
    u8 *p;

    p = ((KwlnTask *)drawWork)->work;
    ((BtlShuffleCardWork *)p)->flags = ((BtlShuffleCardWork *)p)->flags | 1;
    memset(p + 0x190, 0, 0x10);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Request both detail-group and bar exit phases. */
// FUN_0038D0A0
void btlShuffleDrawCardEndDetail(u8 *drawWork)
{
    u8 *p;
    u16 value;

    p = ((KwlnTask *)drawWork)->work;
    value = ((BtlShuffleCardWork *)p)->detailFlags;
    ((BtlShuffleCardWork *)p)->detailFlags = value | 0x20;
    value = ((BtlShuffleCardWork *)p)->detailFlags;
    ((BtlShuffleCardWork *)p)->detailFlags = value | 4;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Change detail kind, preserve the previous kind and reset both animation clocks. */
// FUN_0038D0D0
void btlShuffleDrawCardSetDetail(u8 *drawWork, s32 input)
{
    s32 prevKind;
    s32 flagOn;
    u8 *work;
    u8 *state;

    work = ((KwlnTask *)drawWork)->work;
    state = work + 0x190;
    prevKind = ((BtlShuffleCardWork *)work)->detailKind;
    if (prevKind != input) {
        ((BtlShuffleDetail *)state)->previousKind = prevKind;
        ((BtlShuffleDetail *)state)->kind = input;
        *(s16 *)state = 0;
        ((BtlShuffleDetail *)state)->elapsed = 0;
        ((BtlShuffleDetail *)state)->flags = ((BtlShuffleDetail *)state)->flags & 0xFFF7;
        switch (input) {
        case 1:
        case 3:
        case 4:
            flagOn = 1;
            break;
        default:
            flagOn = 0;
            break;
        }
        if (flagOn != 0) {
            ((BtlShuffleDetail *)state)->flags = ((BtlShuffleDetail *)state)->flags | 2;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Reset count animation state and latch the current sequence count. */
// FUN_0038D160
void btlShuffleDrawCardStartCount(u8 *drawWork) {
    u8 *work;
    u8 *params;

    work = (u8 *)(((KwlnTask *)drawWork)->work);
    params = (u8 *)(work + 0x1A4);
    memset(params, 0, 6);
    ((BtlShuffleCount *)params)->count = (u16) ((BtlShuffleContext *)((BtlShuffleCardWork *)work)->context)->sequenceCount.low;
    ((BtlShuffleCardWork *)work)->flags = (u16) (((BtlShuffleCardWork *)work)->flags | 2);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Request the count component exit phase. */
// FUN_0038D1D0
void btlShuffleDrawCardEndCount(u8 *drawWork)
{
    ((BtlShuffleCounter *)(((KwlnTask *)drawWork)->work + 0x1A4))->flags = ((BtlShuffleCounter *)(((KwlnTask *)drawWork)->work + 0x1A4))->flags | 0x2;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Initialize the selection column for pattern four and enable its draw bit. */
// FUN_0038D1F0
void btlShuffleDrawCardStartSelection(u8 *drawWork)
{
    u8 *selection;
    u8 *cardWork;

    cardWork = ((KwlnTask *)drawWork)->work;
    selection = cardWork + 0x1A0;
    if (((BtlShuffleContext *)((BtlShuffleCardWork *)cardWork)->context)->pattern != 4) {
        kAssertFail(D_0064F0E0, 0x641);
    }
    ((BtlShuffleCardWork *)cardWork)->flags = ((BtlShuffleCardWork *)cardWork)->flags | 8;
    ((BtlShuffleSelection *)selection)->centerX.bits = 0x434F0000;
    ((BtlShuffleSelection *)selection)->top.bits = 0;
    ((BtlShuffleSelection *)selection)->targetWidth.bits = 0x42C40000;
    *(s16 *)selection = 0;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Set the column target width to zero and restart its clock. */
// FUN_0038D280
void btlShuffleDrawCardEndSelection(u8 *drawWork)
{
    u8 *p;

    p = ((KwlnTask *)drawWork)->work;
    ((BtlShuffleSelection *)(p + 0x1A0))->targetWidth.bits = 0;
    ((BtlShuffleSelection *)(p + 0x1A0))->counter = 0;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Enable the ring active phase. */
// FUN_0038D2A0
void btlShuffleDrawCardActivateRing(u8 *drawWork)
{
    ((BtlShuffleCardWork *)((KwlnTask *)drawWork)->work)->ringFlags = ((BtlShuffleCardWork *)((KwlnTask *)drawWork)->work)->ringFlags | 0x1;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Reset reveal-band timing and enable the component. */
// FUN_0038D2C0
void btlShuffleDrawCardStartBands(u8 *drawWork) {
    u8 *work;

    work = (u8 *)(((KwlnTask *)drawWork)->work);
    memset(work + 0x1B4, 0, 4);
    ((BtlShuffleCardWork *)work)->flags = (u16) (((BtlShuffleCardWork *)work)->flags | 0x20);
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Request the reveal-band exit phase. */
// FUN_0038D310
void btlShuffleDrawCardEndBands(u8 *drawWork)
{
    ((BtlShuffleCardWork *)((KwlnTask *)drawWork)->work)->revealFlags = ((BtlShuffleCardWork *)((KwlnTask *)drawWork)->work)->revealFlags | 0x2;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Six timed effect handles expire at 90 frames; three additional handles persist. */
typedef struct BtlShuffleTimedEffect {
    u16 frame;
    u8 pad2[2];
    s32 handle;
} BtlShuffleTimedEffect;

typedef struct BtlShuffleEffects {
    u8 *context;
    u16 flags;
    u8 pad6[2];
    BtlShuffleTimedEffect timed[6];
    s32 unk38, handle3C, unk40, handle44, unk48, handle4C;
} BtlShuffleEffects;

/* Update reward effect transforms, expiring each of six timed handles after ninety frames. */
/* measured: field/access-site typing changes alias-driven reloads or scheduling (normalized_diff 534..566); retain only the failing byte-base accesses. */
// FUN_0038D330
void btlShuffleUpdateRewardEffects(s32 *effectWork)
{
    extern void mdlEffectDestroy(s32 drawWork, u8 *input);
    extern void mdlEffectAdvanceAndFlushWithTable(void *table, s32 effect);
    extern u8 D_005DC824[];
    extern u8 D_005DC974[];
    extern u8 D_005DC9C8[];
    u8 *drawWork;
    u8 *timer;
    s32 handle;

    drawWork = (u8 *)effectWork;
    if (*(u16 *)(drawWork + 4) & 1) {
        timer = (u8 *)(drawWork + 8);
        if (++((BtlShuffleEffects *)drawWork)->timed[0].frame >= 0x5A) {
            handle = *(s32 *)(drawWork + 0xC);
            if (handle != 0) {
                mdlEffectDestroy(handle, timer);
                *(s32 *)(drawWork + 0xC) = 0;
            }
            *(u16 *)(drawWork + 4) = *(u16 *)(drawWork + 4) & 0xFFFE;
        } else {
            mdlEffectAdvanceAndFlushWithTable(D_005DC974, ((BtlShuffleTimedEffect *)timer)->handle);
        }
    }
    if (*(u16 *)(drawWork + 4) & 2) {
        timer = (u8 *)(drawWork + 0x10);
        if (++((BtlShuffleEffects *)drawWork)->timed[1].frame >= 0x5A) {
            handle = *(s32 *)(drawWork + 0x14);
            if (handle != 0) {
                mdlEffectDestroy(handle, timer);
                *(s32 *)(drawWork + 0x14) = 0;
            }
            *(u16 *)(drawWork + 4) = *(u16 *)(drawWork + 4) & 0xFFFD;
        } else {
            mdlEffectAdvanceAndFlushWithTable(D_005DC974, ((BtlShuffleTimedEffect *)timer)->handle);
        }
    }
    if (*(u16 *)(drawWork + 4) & 4) {
        timer = (u8 *)(drawWork + 0x18);
        if (++((BtlShuffleEffects *)drawWork)->timed[2].frame >= 0x5A) {
            handle = *(s32 *)(drawWork + 0x1C);
            if (handle != 0) {
                mdlEffectDestroy(handle, timer);
                *(s32 *)(drawWork + 0x1C) = 0;
            }
            *(u16 *)(drawWork + 4) = *(u16 *)(drawWork + 4) & 0xFFFB;
        } else {
            mdlEffectAdvanceAndFlushWithTable(D_005DC974, ((BtlShuffleTimedEffect *)timer)->handle);
        }
    }
    if (*(u16 *)(drawWork + 4) & 8) {
        timer = (u8 *)(drawWork + 0x20);
        if (++((BtlShuffleEffects *)drawWork)->timed[3].frame >= 0x5A) {
            handle = *(s32 *)(drawWork + 0x24);
            if (handle != 0) {
                mdlEffectDestroy(handle, timer);
                *(s32 *)(drawWork + 0x24) = 0;
            }
            *(u16 *)(drawWork + 4) = *(u16 *)(drawWork + 4) & 0xFFF7;
        } else {
            mdlEffectAdvanceAndFlushWithTable(D_005DC974, ((BtlShuffleTimedEffect *)timer)->handle);
        }
    }
    if (*(u16 *)(drawWork + 4) & 0x10) {
        timer = (u8 *)(drawWork + 0x28);
        if (++((BtlShuffleEffects *)drawWork)->timed[4].frame >= 0x5A) {
            handle = *(s32 *)(drawWork + 0x2C);
            if (handle != 0) {
                mdlEffectDestroy(handle, timer);
                *(s32 *)(drawWork + 0x2C) = 0;
            }
            *(u16 *)(drawWork + 4) = *(u16 *)(drawWork + 4) & 0xFFEF;
        } else {
            mdlEffectAdvanceAndFlushWithTable(D_005DC974, ((BtlShuffleTimedEffect *)timer)->handle);
        }
    }
    if (*(u16 *)(drawWork + 4) & 0x20) {
        timer = (u8 *)(drawWork + 0x30);
        if (++((BtlShuffleEffects *)drawWork)->timed[5].frame >= 0x5A) {
            handle = *(s32 *)(drawWork + 0x34);
            if (handle != 0) {
                mdlEffectDestroy(handle, timer);
                *(s32 *)(drawWork + 0x34) = 0;
            }
            *(u16 *)(drawWork + 4) = *(u16 *)(drawWork + 4) & 0xFFDF;
        } else {
            mdlEffectAdvanceAndFlushWithTable(D_005DC974, ((BtlShuffleTimedEffect *)timer)->handle);
        }
    }
    if (*(u16 *)(drawWork + 4) & 0x40) {
        mdlEffectAdvanceAndFlushWithTable(D_005DC9C8, ((BtlShuffleEffects *)drawWork)->handle3C);
    }
    if (*(u16 *)(drawWork + 4) & 0x80) {
        mdlEffectAdvanceAndFlushWithTable(D_005DC9C8, ((BtlShuffleEffects *)drawWork)->handle44);
    }
    if (*(u16 *)(drawWork + 4) & 0x100) {
        mdlEffectAdvanceAndFlushWithTable(D_005DC824, ((BtlShuffleEffects *)drawWork)->handle4C);
    }
}
#pragma pop
