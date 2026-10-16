/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00222210-00222d20 */

#include "rw_types_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
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

extern void sdkSpriteDrawOnceScaled(s32 arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7, f32 fparg3, s16 arg_sp0, s16 arg_sp8);
static inline void logoDrawTitle(u8 *work, LogoVec2 ofs, LogoColor col, LogoVec2 pos)
{
    s32 res = *(s32 *)(work + 0x50);
    f32 x;
    f32 y;
    f32 qx;

    x = ofs.x + pos.x;
    y = ofs.y + pos.y;
    sdkSpriteDrawOnceScaled(*(s32 *)(work + 0x54), 0x1D, x, y, 0.0f, col.r, col.g, col.b, col.a, 0x1000, 0x1000, 37.0f, (s16)(pos.x - x), (s16)(pos.y - y));
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
// FUN_00222210
void btlLogoDrawTitle(u8 *work, u32 alpha)
{
    extern f32 btlShuffleCalcWave(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern s32 RpSkyRenderStateSet(s32 arg0, s32 arg1);
    extern void shdEnableBlendFlag(void);
    extern void shdDisableBlendFlag(void);
    extern void PrimDrawPoints(u8 *arg0, u8 *arg1, f32 fparg0, s32 arg2, s32 arg3, s32 arg4);
    extern f32 fGpffff8384;
    extern f32 fGpffff8388;
    f32 var_f24;
    f32 var_f22;
    f32 var_f21;
    f32 var_f23;
    f32 var_f20;
    f32 coords[6];
    LogoVec2 pos;
    LogoVec2 base;
    LogoColor colors[3];
    LogoColor color;
    s32 i;

    if ((*(u16 *)work & 8) == 0) {
        var_f24 = 1.0f - btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 0.0f, 6.0f, 1);
        var_f22 = 1.0f - btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 0.0f, 6.0f, 1);
        var_f21 = 1.0f - btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 7.0f, 17.0f, 1);
        var_f23 = 1.0f - btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 13.0f, 25.0f, 1);
        if (*(u16 *)(work + 0x46) >= 7) {
            if (++*(u16 *)(work + 0x48) >= 0x28) {
                *(u16 *)(work + 0x48) = 0;
            }
            var_f20 = btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x48), 0.0f, 40.0f, 0);
        }
    } else {
        var_f24 = 0.0f;
        var_f22 = 0.0f;
        var_f21 = 0.0f;
        var_f23 = 0.0f;
        if (++*(u16 *)(work + 0x48) >= 0x28) {
            *(u16 *)(work + 0x48) = 0;
        }
        var_f20 = btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x48), 0.0f, 40.0f, 0);
    }
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);

    pos.x = (f32)0x109 + (f32)0x177 * var_f22;
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

    pos.x = 348.0f + 292.0f * var_f24;
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

    base.x = (220.0f + fGpffff8384 * var_f21) - 9.0f;
    base.y = -94.0f + fGpffff8388 * var_f21;
    pos.x = -(394.0f * var_f20);
    pos.y = 0.0f;
    color.r = 0xFF;
    color.g = 0xD4;
    color.b = 0;
    color.a = alpha;
    for (i = 0; i < 3; i++) {
        logoDrawTitle(work, pos, color, base);
        pos.x = pos.x + 394.0f;
    }

    base.x = 1.0f + ((f32)0x185 + fGpffff8384 * var_f23);
    base.y = (-5.0f + fGpffff8388 * var_f23) - 1.0f;
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
// FUN_00222D20
void btlLogoDraw(u8 *drawData, s32 workAddress, void *callback)
{
    typedef struct { f32 x, y; } Vec2fLocal;
    typedef struct { s32 lo, hi; } DescriptorPair;
    typedef union { Vec2fLocal draw; DescriptorPair descriptor; } OriginPair;
    extern void btlLogoDrawTitle(u8 *work, u32 alpha);
    extern void sdkRenderStateSetDefault(void);
    extern void nLineDrawSet(Vec2fLocal arg0, s32 arg1, s32 arg2, f32 arg3);
    extern void datScreenWipeDraw(u8 *arg0);
    extern s32 datScreenWipeTexture(u8 *arg0);
    extern void datScreenWipeGetPositions(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
    extern void datScreenWipeGetScale(u8 *arg0, f32 *arg1);
    extern f32 btlShuffleCalcWave(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);
    extern void shdDrawColourQuad(f32 depth, f32 x, f32 y, f32 shadowX, f32 shadowY,
                              f32 width, f32 height, s32 color, s32 texture,
                              s32 shadow, s32 mode);
    extern void sflDataDrawEntry(DescriptorPair origin, f32 depth, s32 alpha, s16 *descriptor);
    extern s32 RpSkyRenderStateSet(s32 state, s32 value);
    extern s32 sdkSndStartChannel(s16 channel, const char *name);
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
    if ((*(u16 *)work & 2) != 0) {
        if ((*(u16 *)work & 8) == 0) {
            if (++*(u16 *)(work + 0x46) >= 54) {
                *(u16 *)work |= 8;
            }
            alpha = (u8)(255.0f * btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 0.0f, 5.0f, 1));
            if (*(u16 *)(work + 0x46) == 14) {
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
        datScreenWipeDraw(*(u8 **)(work + 0x4C));
        origin.draw.x = 0.0f;
        origin.draw.y = 0.0f;
        texture = datScreenWipeTexture(*(u8 **)(work + 0x4C));
        if (texture != 0) {
            if (*(u16 *)(work + 0x46) >= 24) {
                u32 overlayAlpha;
                f32 opacity;
                f32 drawX;
                f32 drawY;
                s32 color;
                phase = btlShuffleCalcWave((f32)(u32)*(u16 *)(work + 0x46), 27.0f, 54.0f, 2);
                datScreenWipeGetPositions(*(u8 **)(work + 0x4C), 0, (u8 *)position, 0);
                datScreenWipeGetScale(*(u8 **)(work + 0x4C), scale);
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
        sflDataDrawEntry(origin.descriptor, 0.0f, alpha, (s16 *)(work + 0x58));
    }
}
#pragma pop
