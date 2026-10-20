/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00222210-00222d20 */

#include "rw_types_internal.h"
#include "member_access.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
#include "btl_result_ui_internal.h"
extern void btlLogoDraw(u8 *drawData, s32 workAddress, void *callback);
typedef struct LogoVec2 {
    f32 x;
    f32 y;
} LogoVec2;

typedef struct LogoColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} LogoColor;

extern void sdkSpriteDrawOnceScaled(s32, s32, f32, f32, f32, u8, u8, u8, u8, u16, u16, f32, s16, s16);
/* Draw the title logo and its three trailing glyph sprites. */
static inline void logoDrawTitle(u8 *work, LogoVec2 ofs, LogoColor col, LogoVec2 pos)
{
    s32 res = ((BtlLogoWork *)work)->sprite;
    f32 x;
    f32 y;
    f32 qx;

    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    sdkSpriteDrawOnceScaled(((BtlLogoWork *)work)->titleSprite, 0x1D, x, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - x), (s16)(pos.y - y));
    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    qx = (207.0f + x) - 6.0f;
    sdkSpriteDrawOnceScaled(res, 0xB2, qx, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - qx), (s16)(pos.y - y));
    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    qx = (300.0f + x) - 6.0f;
    sdkSpriteDrawOnceScaled(res, 0xB3, qx, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - qx), (s16)(pos.y - y));
    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    qx = (314.0f + x) - 6.0f;
    sdkSpriteDrawOnceScaled(res, 0xB3, qx, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - qx), (s16)(pos.y - y));
}

#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// Intent: Draw the logo title sprites at the given alpha. [inferred]
/* MEMBER frame reloads/resets avoid the b210 member-address hoisting measured across float conversions. */
// FUN_00222210
void btlLogoDrawTitle(u8 *work, u32 alpha)
{
    extern f32 btlShuffleCalcWave(f32, f32, f32, s32);
    extern s32 RpSkyRenderStateSet(s32, s32);
    extern void shdEnableBlendFlag(void);
    extern void shdDisableBlendFlag(void);
    extern void PrimDrawPoints(u8 *, u8 *, f32, s32, s32, s32);
    extern f32 fGpffff8384;
    extern f32 fGpffff8388;
    f32 redSlide;
    f32 whiteSlide;
    f32 yellowSlide;
    f32 titleSlide;
    f32 scrollPhase;
    f32 coords[6];
    LogoVec2 pos;
    LogoVec2 base;
    LogoColor colors[3];
    LogoColor color;
    s32 i;

    if ((((BtlLogoWork *)work)->flags & 8) == 0) {
        redSlide = 1.0f - btlShuffleCalcWave((f32)(u32)((BtlLogoWork *)work)->animationFrame, 0.0f, 6.0f, 1);
        whiteSlide = 1.0f - btlShuffleCalcWave((f32)(u32)MEMBER(u16, work, BtlLogoWork, animationFrame), 0.0f, 6.0f, 1);
        yellowSlide = 1.0f - btlShuffleCalcWave((f32)(u32)MEMBER(u16, work, BtlLogoWork, animationFrame), 7.0f, 17.0f, 1);
        titleSlide = 1.0f - btlShuffleCalcWave((f32)(u32)MEMBER(u16, work, BtlLogoWork, animationFrame), 13.0f, 25.0f, 1);
        if (MEMBER(u16, work, BtlLogoWork, animationFrame) >= 7) {
            if (++((BtlLogoWork *)work)->waveFrame >= 0x28) {
                MEMBER(u16, work, BtlLogoWork, waveFrame) = 0;
            }
            scrollPhase = btlShuffleCalcWave((f32)(u32)MEMBER(u16, work, BtlLogoWork, waveFrame), 0.0f, 40.0f, 0);
        }
    } else {
        redSlide = 0.0f;
        whiteSlide = 0.0f;
        yellowSlide = 0.0f;
        titleSlide = 0.0f;
        if (++((BtlLogoWork *)work)->waveFrame >= 0x28) {
            MEMBER(u16, work, BtlLogoWork, waveFrame) = 0;
        }
        scrollPhase = btlShuffleCalcWave((f32)(u32)MEMBER(u16, work, BtlLogoWork, waveFrame), 0.0f, 40.0f, 0);
    }
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);

    pos.x = (f32)0x109 + (f32)0x177 * whiteSlide;
    pos.y = 0.0f;
    coords[0] = pos.x;
    coords[1] = pos.y;
    coords[2] = (f32)0x177 + pos.x;
    coords[3] = pos.y;
    coords[4] = (f32)0x177 + pos.x;
    coords[5] = (f32)0x119 + pos.y;
    for (i = 0; i < 3; i++) {
        colors[i].r = 0xFF;
        colors[i].g = 0xFF;
        colors[i].b = 0xFF;
        colors[i].a = alpha;
    }
    shdEnableBlendFlag();
    PrimDrawPoints((u8 *)colors, (u8 *)coords, 0.0f, 3, 5, 0);
    shdDisableBlendFlag();

    pos.x = 348.0f + 292.0f * redSlide;
    pos.y = 0.0f;
    coords[0] = pos.x;
    coords[1] = pos.y;
    coords[2] = 292.0f + pos.x;
    coords[3] = pos.y;
    coords[4] = 292.0f + pos.x;
    coords[5] = 220.0f + pos.y;
    for (i = 0; i < 3; i++) {
        colors[i].r = 0xED;
        colors[i].g = 0x36;
        colors[i].b = 0x11;
        colors[i].a = alpha;
    }
    shdEnableBlendFlag();
    PrimDrawPoints((u8 *)colors, (u8 *)coords, 0.0f, 3, 5, 0);
    shdDisableBlendFlag();

    base.x = (220.0f + fGpffff8384 * yellowSlide) - 9.0f;
    base.y = -94.0f + fGpffff8388 * yellowSlide;
    pos.x = -(394.0f * scrollPhase);
    pos.y = 0.0f;
    color.r = 0xFF;
    color.g = 0xD4;
    color.b = 0;
    color.a = alpha;
    for (i = 0; i < 3; i++) {
        logoDrawTitle(work, pos, color, base);
        pos.x = pos.x + 394.0f;
    }

    base.x = 1.0f + ((f32)0x185 + fGpffff8384 * titleSlide);
    base.y = (-5.0f + fGpffff8388 * titleSlide) - 1.0f;
    pos.x = 0.0f;
    pos.y = 0.0f;
    color.r = 0xFF;
    color.g = 0xFF;
    color.b = 0xFF;
    color.a = alpha;
    logoDrawTitle(work, pos, color, base);
}
#pragma pop

#pragma push
#pragma opt_propagation off
// Intent: Draw the logo scene and title for one frame. [inferred]
/* b210: remaining frame and wipe-pointer reloads individually change instructions when typed. */
// FUN_00222D20
void btlLogoDraw(u8 *drawData, s32 workAddress, void *callback)
{
    typedef struct { f32 x, y; } Vec2fLocal;
    typedef struct { s32 lo, hi; } DescriptorPair;
    typedef union { Vec2fLocal draw; DescriptorPair descriptor; } OriginPair;
    extern void btlLogoDrawTitle(u8 *work, u32 alpha);
    extern void sdkRenderStateSetDefault(void);
    extern void nLineDrawSet(Vec2fLocal, s32, s32, f32);
    extern void datScreenWipeDraw(u8 *);
    extern s32 datScreenWipeTexture(u8 *);
    extern void datScreenWipeGetPositions(u8 *, u8 *, u8 *, u8 *);
    extern void datScreenWipeGetScale(u8 *, f32 *);
    extern f32 btlShuffleCalcWave(f32, f32, f32, s32);
    extern void shdDrawColourQuad(f32 depth, f32 color, f32 x, f32 y, f32 maskX,
                              f32 maskY, f32 width, s32 height, s32 texture,
                              s32 drawMask, s32 blendMode);
    extern void sflDataDrawEntry(DescriptorPair position, f32 depth, s32 opacity, s16 *state);
    extern s32 RpSkyRenderStateSet(s32 state, s32 value);
    extern s32 sdkSndStartChannel(s16 channelIndex, const char *path);
    extern u8 D_00629680[];
    extern f32 fGpffff838c;
    u8 *work;
    u32 alpha;
    s32 texture;
    f32 phase;
    OriginPair origin;
    f32 position[2];
    f32 scale[2];

    work = (u8 *)workAddress;
    if ((((BtlLogoWork *)work)->flags & 2) != 0) {
        if ((((BtlLogoWork *)work)->flags & 8) == 0) {
            if (++((BtlLogoWork *)work)->animationFrame >= 54) {
                ((BtlLogoWork *)work)->flags |= 8;
            }
            alpha = (u8)(255.0f * btlShuffleCalcWave((f32)(u32)MEMBER(u16, work, BtlLogoWork, animationFrame), 0.0f, 5.0f, 1));
            if (MEMBER(u16, work, BtlLogoWork, animationFrame) == 14) {
                sdkSndStartChannel(2, (const char *)D_00629680);
            }
        } else {
            u8 opaque = 255;
            alpha = opaque;
        }
        sdkRenderStateSetDefault();
        origin.draw.x = 0.0f;
        origin.draw.y = 0.0f;
        nLineDrawSet(origin.draw, alpha, 0x16, 0.0f);
        btlLogoDrawTitle(work, alpha);
        datScreenWipeDraw(((BtlLogoWork *)work)->wipe);
        origin.draw.x = 0.0f;
        origin.draw.y = 0.0f;
        texture = datScreenWipeTexture(MEMBER(u8 *, work, BtlLogoWork, wipe));
        if (texture != 0) {
            if (((BtlLogoWork *)work)->animationFrame >= 24) {
                u32 overlayAlpha;
                f32 opacity;
                f32 drawX;
                f32 drawY;
                s32 color;
                phase = btlShuffleCalcWave((f32)(u32)((BtlLogoWork *)work)->animationFrame, 27.0f, 54.0f, 2);
                datScreenWipeGetPositions(MEMBER(u8 *, work, BtlLogoWork, wipe), 0, (u8 *)position, 0);
                datScreenWipeGetScale(MEMBER(u8 *, work, BtlLogoWork, wipe), scale);
                drawY = position[1];
                drawX = position[0];
                opacity = fGpffff838c * (f32)alpha;
                overlayAlpha = (u8)(opacity * (1.0f - phase));
                color = (s32)(overlayAlpha | 0xFFFFFF00U);
                shdDrawColourQuad(0.0f, drawX, drawY, drawX, drawY,
                              256.0f * scale[0], 512.0f * scale[1],
                              color, texture, 0, 1);
                RpSkyRenderStateSet(3, 0x717FB);
                RpSkyRenderStateSet(2, 0x44);
            }
        }
        sflDataDrawEntry(origin.descriptor, 0.0f, alpha, ((BtlLogoWork *)work)->descriptor);
    }
}
#pragma pop
