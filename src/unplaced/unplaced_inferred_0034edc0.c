
#include "nline_vertex_internal.h"
#include "member_access.h"
#include "rw_camera_internal.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"

/* Same sample layout allocated by sdkSpriteNewNode in Kernel/sdkSpr.c. */
typedef struct SdkSpriteSample {
    u32 packAddress, recordIndex;
    f32 x, y;
    u8 alphaSubtract, fade;
    u8 pad12[2];
    s16 extendX, extendY;
    f32 angle;
    s16 pivotX, pivotY;
    u16 scaleX, scaleY; /* Q12, 0x1000 is unit scale */
    f32 depth;
    u8 red, green, blue, pad2B;
} SdkSpriteSample;

/* Each nLine layer occupies one immediate-mode vertex. */
typedef struct NLineVertex {
    f32 x, y, z;
    u8 padC[0xC];
    f32 reciprocal;
    u8 pad1C[4];
    f32 red, green, blue, alpha;
    u8 pad30[0x10];
} NLineVertex;

typedef struct NLineLayerWork {
    u8 pad0[0x790];
    NLineVertex layers[3];
    u8 pad850[0x140];
    s32 layersActive;
    u8 alpha;
    u8 pad995[7];
    f32 offsetX, offsetY;
} NLineLayerWork;

typedef struct DatCommunityEntry {
    s16 state, countdown;
    s32 value, radius, extent;
} DatCommunityEntry;

typedef struct CmpGridCell {
    s32 unk0;
    s32 x, y, width, height;
} CmpGridCell;

typedef struct DatSmoothTarget {
    s16 target, bound, countdown, current, stepCountdown;
} DatSmoothTarget;
extern s32 (*D_00887300[])(RwRenderState, void *);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern void sdkSpriteDraw(u8 *sample, s32 setStates);
extern void kAssertFail(const void *file, s32 line);
extern char D_0064B310[];
extern u32 RpRandom();
extern u8 *sdkSpriteNewNode(s32 packAddress, s32 recordIndex);
extern s32 kwlnGetCamera(void);
extern f32 fGpffff8224;
extern void sdkSpriteFreeNode(void *node);
extern f32 D_0088467C[];
extern f32 D_008872F8[];

void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                   u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                   u16 scaleY, s16 pivotX, f32 angle, s16 pivotY);
void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y, f32 depth,
                   u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX, u16 scaleY,
                   f32 angle, s16 pivotX, s16 pivotY);
/* One render-state setter slot; reload the callback itself before every call. */
typedef s32 (*SdkRenderStateSetterSlot[1])(RwRenderState, void *);
/* Unit setting: sprite, nLine and community helpers use propagation. */
#pragma opt_propagation on
// Set the base render states for nLine drawing.
// FUN_0034EDC0
void nLineSetRenderStateBase(void)
{
    SdkRenderStateSetterSlot *base;

    base = (SdkRenderStateSetterSlot *)D_00887300;
    (*base)[0](7, (void *)2);
    (*base)[0](6, (void *)0);
    (*base)[0](8, (void *)0);
    (*base)[0](1, (void *)0);
    (*base)[0](0xE, (void *)0);
    (*base)[0](0xA, (void *)5);
    (*base)[0](0xB, (void *)7);
    (*base)[0](0xC, (void *)1);
}

// Draw the three nLine layers, with the middle and right layers faded by the amount.
// FUN_0034EE90
void nLineDrawLayers(u8 *work, f32 originX, f32 originY, f32 amount)
{
    f32 alpha;
    f32 x;
    f32 delta;
    f32 invScale;
    f32 baseY;
    f32 baseX;
    f32 levelF;
    u8 level;
    u8 *unit;
    u8 *layers;

    level = (u8)((u8)(((NLineLayerWork *)work)->alpha));
    levelF = (f32)(u32)level;
    alpha = levelF / 255.0f;
    unit = (u8 *)(work);
    baseX = originX;
    if (!(amount <= 0.0f)) {
        delta = D_008872F8[0] - D_0088467C[0];
        /* The camera near plane supplies the projection divisor. */
        invScale = 1.0f / ((RwCamera *)((u8 *)kwlnGetCamera()))->nearPlane;
        layers = unit + 0x790;
        ((NLineLayerWork *)unit)->layersActive = 1;
        baseY = 448.0f + originY;
        x = baseX - 208.0f;
        x += ((NLineLayerWork *)(unit))->offsetX;
        nLineSetLayer(layers, x, baseY + ((NLineLayerWork *)(unit))->offsetY, delta, invScale, 0xFF, 0xE9, 0x36, 0);
        baseX = 640.0f + (f32)baseX;
        alpha = 51.0f * amount * (f32)alpha;
        nLineSetLayer(layers + 0x40, baseX + MEMBER(f32, unit, NLineLayerWork, offsetX), baseY + MEMBER(f32, unit, NLineLayerWork, offsetY), delta, invScale, 0xFF, 0xE9, 0x36, (u8)alpha);
        nLineSetLayer(layers + 0x80, baseX + MEMBER(f32, unit, NLineLayerWork, offsetX), originY + MEMBER(f32, unit, NLineLayerWork, offsetY), delta, invScale, 0xFF, 0xE9, 0x36, 0);
        return;
    }
    ((NLineLayerWork *)unit)->layersActive = 0;
}

// Store one nLine layer's position, scale and colour bytes.
// FUN_0034F0D0
void nLineSetLayer(u8 *vertex, f32 x, f32 y, f32 z,
                   f32 reciprocal, u8 red, u8 green, u8 blue, u8 alpha) {
    ((NLineVertex *)vertex)->x = x;
    ((NLineVertex *)vertex)->y = y;
    ((NLineVertex *)vertex)->z = z;
    ((NLineVertex *)vertex)->reciprocal = reciprocal;
    ((NLineVertex *)vertex)->red = (f32)red;
    ((NLineVertex *)vertex)->green = (f32)green;
    ((NLineVertex *)vertex)->blue = (f32)blue;
    ((NLineVertex *)vertex)->alpha = (f32)alpha;
}

// Set the default render states and the sky state values for sprite draws.
// FUN_0034F1E0
/* measured: retail keeps the dispatch table base cached in a local across all the setter calls. */
void sdkRenderStateSetDefault(void)
{
    SdkRenderStateSetterSlot *base;

    base = (SdkRenderStateSetterSlot *)D_00887300;
    (*base)[0](6, (void *)0);
    (*base)[0](7, (void *)2);
    (*base)[0](8, (void *)0);
    (*base)[0](9, (void *)2);
    (*base)[0](0xC, (void *)1);
    (*base)[0](0xB, (void *)6);
    (*base)[0](0xA, (void *)5);
    (*base)[0](2, (void *)4);
    (*base)[0](0xE, (void *)0);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    RpSkyRenderStateSet(2, (void *)0x44);
}

// Draw a sprite at a position with the given colour and opacity at unit size, skipping transparent
// sprites.
// FUN_0034F2E0
void sdkSpriteDrawAt(void *sprite, f32 x, f32 y,
                   u8 red, u8 green, u8 blue, u8 alpha) {
    sdkSpriteDrawSized(sprite, x, y, 0.0f, red, green, blue, alpha,
                  0x1000, 0x1000, 0, 0.0f, 0);
}

// Set the sprite's position, colour, opacity, size and extra fields, then draw it; zero opacity or
// zero size skips the draw.
// FUN_0034F320
void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth,
                   u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX,
                   u16 scaleY, s16 pivotX, f32 angle, s16 pivotY)
{
    u8 opacity;

    if (sprite == NULL)
        kAssertFail(D_0064B310, 0x6C);
    opacity = alpha & 0xFF;
    if ((opacity == 0) || ((scaleX & 0xFFFF) == 0) ||
        ((scaleY & 0xFFFF) == 0))
        return;
    ((SdkSpriteSample *)sprite)->x = x;
    ((SdkSpriteSample *)sprite)->y = y;
    ((SdkSpriteSample *)sprite)->red = red;
    ((SdkSpriteSample *)sprite)->green = green;
    ((SdkSpriteSample *)sprite)->blue = blue;
    ((SdkSpriteSample *)sprite)->alphaSubtract = 0;
    ((SdkSpriteSample *)sprite)->fade = 0xFF - opacity;
    ((SdkSpriteSample *)sprite)->depth = depth;
    ((SdkSpriteSample *)sprite)->scaleX = scaleX;
    ((SdkSpriteSample *)sprite)->scaleY = scaleY;
    ((SdkSpriteSample *)sprite)->pivotX = pivotX;
    ((SdkSpriteSample *)sprite)->pivotY = pivotY;
    ((SdkSpriteSample *)sprite)->angle = angle;
    sdkSpriteDraw(sprite, 0);
}

// Draw one sprite through a temporary node at the given position, with the given colour and
// opacity.
// FUN_0034F460
void sdkSpriteDrawOnceAt(s32 packAddress, s32 image, f32 x, f32 y,
                   u8 red, u8 green, u8 blue, u8 alpha) {
    sdkSpriteDrawOnceScaled(packAddress, image, x, y, 0.0f, red, green, blue, alpha,
                  0x1000, 0x1000, 0.0f, 0, 0);
}

// Draw one sprite through a temporary node: allocate it, draw with the transform arguments, then
// free it.
// FUN_0034F4A0
void sdkSpriteDrawOnceScaled(s32 packAddress, s32 image, f32 x, f32 y, f32 depth,
                   u8 red, u8 green, u8 blue, u8 alpha, u16 scaleX, u16 scaleY,
                   f32 angle, s16 pivotX, s16 pivotY)
{
    u8 *sprite;

    if (packAddress == 0)
        kAssertFail(D_0064B310, 0x94);
    sprite = sdkSpriteNewNode(packAddress, image);
    sdkSpriteDrawSized(sprite, x, y, depth, red, green, blue,
                  alpha, scaleX, scaleY, pivotX, angle, pivotY);
    sdkSpriteFreeNode(sprite);
}

// Countdown step for a community entry: on expiry, pick a random state of -1 or 0 to 2 by distance
// and reset the countdown to 2 to 6.
// FUN_0034F5D0
void datCommunityEntryStep(u8 *communityEntry)
{
    s32 extent;
    u32 random;
    s32 distance;
    s32 half;
    s32 span;
    u32 choice;

    if (--((DatCommunityEntry *)(communityEntry))->countdown <= 0) {
        extent = ((DatCommunityEntry *)communityEntry)->extent;
        random = RpRandom() % (u32)(extent / 2 + 1);
        distance = (s32)(extent - ((DatCommunityEntry *)communityEntry)->value - random);
        if (distance < 0) distance = 0;
        half = ((DatCommunityEntry *)communityEntry)->radius / 2;
        if (distance <= half) {
            span = 20 - half * 2 - distance;
            if (span > 0) {
                choice = RpRandom() % (u32)span;
                if (choice < 9U) {
                    ((DatCommunityEntry *)communityEntry)->state = (s16)(choice % 3U);
                } else {
                    ((DatCommunityEntry *)communityEntry)->state = -1;
                }
            } else {
                ((DatCommunityEntry *)communityEntry)->state = (s16)(RpRandom() % 3U);
            }
        } else {
            ((DatCommunityEntry *)communityEntry)->state = -1;
        }
        MEMBER(s16, communityEntry, DatCommunityEntry, countdown) = (s16)(RpRandom() % 5U + 2);
    }
}

// Fade of a grid cell: product of the two linear interpolations scaled by the amount, with range
// assertions.
// FUN_0034F720
f32 cmpGridCellFade(u8 *cell, f32 xFraction, f32 yFraction, f32 amount) {
    if ((xFraction < 0.0f) || !(xFraction <= 1.0f)) {
        kAssertFail(D_0064B310, 0xD0);
    }
    if ((yFraction < 0.0f) || !(yFraction <= 1.0f)) {
        kAssertFail(D_0064B310, 0xD1);
    }
    if ((amount < 0.0f) || !(amount <= 1.0f)) {
        kAssertFail(D_0064B310, 0xD2);
    }
    if ((((CmpGridCell *)(cell))->width - 1) <= 0) {
        kAssertFail(D_0064B310, 0xD3);
    }
    if ((((CmpGridCell *)(cell))->height - 1) <= 0) {
        kAssertFail(D_0064B310, 0xD4);
    }
    return amount *
           ((f32)(((CmpGridCell *)cell)->x) *
            ((1.0f - xFraction) / (f32)(MEMBER(s32, cell, CmpGridCell, width) - 1)) +
            xFraction) *
           ((f32)(((CmpGridCell *)cell)->y) *
            ((1.0f - yFraction) / (f32)(MEMBER(s32, cell, CmpGridCell, height) - 1)) +
            yFraction);
}

// Step a 16-bit value one unit toward its target on a timer, re-roll on expiry, and snap when it
// passes the bound.
// FUN_0034F8F0
void datSmoothTargetStep(u8 *transition)
{
  s32 difference;
  s32 magnitude;
  ((DatSmoothTarget *)transition)->stepCountdown -= 1;
  if (((DatSmoothTarget *)transition)->stepCountdown < 0)
  {
    difference = (short) ((s64) ((((DatSmoothTarget *)transition)->target) - (*((s16 *) (transition + 6)))));
    if (difference != 0)
    {
      if (difference < 0)
      {
        magnitude = -difference;
      }
      else
      {
        magnitude = difference;
      }
      *((s16 *) (transition + 6)) += (s16) (difference / magnitude);
    }
    RpRandom();
    difference = 8;
    *((s16 *) (transition + difference)) = 2;
  }
  *((s16 *) (transition + 4)) -= 1;
  if (((*((s16 *) (transition + 4))) < 0) || ((((DatSmoothTarget *)transition)->bound) < (*((s16 *) (transition + 6)))))
  {
    magnitude = 0;
    ((DatSmoothTarget *)transition)->bound = *((s16 *) (transition + 6));
    *((s16 *) (transition + 4)) = magnitude;
  }
}

// Draw the footer sprite group at the position with the given alpha, style and resource.
// FUN_0034F9D0
void sdkSpriteDrawFooter(FclVec2 unusedPosition, f32 depth, u8 alpha, s32 style, s32 packAddress) {
    u8 *footerSprite1;
    u8 *footerSprite100;
    u8 *footerSprite101;
    u8 *footerSprite102;
    u8 *footerSprite103;
    u8 *footerSprite104;
    u8 *footerSprite105;
    u8 *footerSprite106;
    u8 *footerSprite107;
    u8 *footerSprite108;
    u8 *footerSprite109;
    u8 *footerSprite10;
    u8 *footerSprite110;
    u8 *footerSprite111;
    u8 *footerSprite112;
    u8 *footerSprite113;
    u8 *footerSprite114;
    u8 *footerSprite115;
    u8 *footerSprite116;
    u8 *footerSprite117;
    u8 *footerSprite118;
    u8 *footerSprite119;
    u8 *footerSprite11;
    u8 *footerSprite120;
    u8 *footerSprite121;
    u8 *footerSprite122;
    u8 *footerSprite12;
    u8 *footerSprite13;
    u8 *footerSprite14;
    u8 *footerSprite15;
    u8 *footerSprite16;
    u8 *footerSprite17;
    u8 *footerSprite18;
    u8 *footerSprite19;
    u8 *footerSprite20;
    u8 *footerSprite21;
    u8 *footerSprite22;
    u8 *footerSprite23;
    u8 *footerSprite24;
    u8 *footerSprite25;
    u8 *footerSprite26;
    u8 *footerSprite27;
    u8 *footerSprite28;
    u8 *footerSprite29;
    u8 *footerSprite2;
    u8 *footerSprite30;
    u8 *footerSprite31;
    u8 *footerSprite32;
    u8 *footerSprite33;
    u8 *footerSprite34;
    u8 *footerSprite35;
    u8 *footerSprite36;
    u8 *footerSprite37;
    u8 *footerSprite38;
    u8 *footerSprite39;
    u8 *footerSprite3;
    u8 *footerSprite40;
    u8 *footerSprite41;
    u8 *footerSprite42;
    u8 *footerSprite43;
    u8 *footerSprite44;
    u8 *footerSprite45;
    u8 *footerSprite46;
    u8 *footerSprite47;
    u8 *footerSprite48;
    u8 *footerSprite49;
    u8 *footerSprite4;
    u8 *footerSprite50;
    u8 *footerSprite51;
    u8 *footerSprite52;
    u8 *footerSprite53;
    u8 *footerSprite54;
    u8 *footerSprite55;
    u8 *footerSprite56;
    u8 *footerSprite57;
    u8 *footerSprite58;
    u8 *footerSprite59;
    u8 *footerSprite5;
    u8 *footerSprite60;
    u8 *footerSprite61;
    u8 *footerSprite62;
    u8 *footerSprite63;
    u8 *footerSprite64;
    u8 *footerSprite65;
    u8 *footerSprite66;
    u8 *footerSprite67;
    u8 *footerSprite68;
    u8 *footerSprite69;
    u8 *footerSprite6;
    u8 *footerSprite70;
    u8 *footerSprite71;
    u8 *footerSprite72;
    u8 *footerSprite73;
    u8 *footerSprite74;
    u8 *footerSprite75;
    u8 *footerSprite76;
    u8 *footerSprite77;
    u8 *footerSprite78;
    u8 *footerSprite79;
    u8 *footerSprite7;
    u8 *footerSprite80;
    u8 *footerSprite81;
    u8 *footerSprite82;
    u8 *footerSprite83;
    u8 *footerSprite84;
    u8 *footerSprite85;
    u8 *footerSprite86;
    u8 *footerSprite87;
    u8 *footerSprite88;
    u8 *footerSprite89;
    u8 *footerSprite8;
    u8 *footerSprite90;
    u8 *footerSprite91;
    u8 *footerSprite92;
    u8 *footerSprite93;
    u8 *footerSprite94;
    u8 *footerSprite95;
    u8 *footerSprite96;
    u8 *footerSprite97;
    u8 *footerSprite98;
    u8 *footerSprite99;
    u8 *footerSprite9;

    if (packAddress != 0) {
        switch (style) {
        case -1:
            break;
        case 0:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite1 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite1, 496.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite1);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite2 = (u8 *)(sdkSpriteNewNode(packAddress, 0xF));
            sdkSpriteDrawSized(footerSprite2, 510.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite2);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite3 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite3, (f32) 0x227, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite3);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite4 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite4, (f32) 0x235, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite4);
            return;
        case 1:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite5 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite5, (f32) 0x1AD, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite5);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite6 = (u8 *)(sdkSpriteNewNode(packAddress, 0xF));
            sdkSpriteDrawSized(footerSprite6, (f32) 0x1BB, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite6);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite7 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite7, 484.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite7);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite8 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite8, 498.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite8);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite9 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite9, (f32) 0x216, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite9);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite10 = (u8 *)(sdkSpriteNewNode(packAddress, 0x11));
            sdkSpriteDrawSized(footerSprite10, 548.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite10);
            return;
        case 2:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite11 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite11, (f32) 0x1AD, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite11);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite12 = (u8 *)(sdkSpriteNewNode(packAddress, 0xF));
            sdkSpriteDrawSized(footerSprite12, (f32) 0x1BB, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite12);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite13 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite13, 484.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite13);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite14 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite14, 498.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite14);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite15 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite15, (f32) 0x216, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite15);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite16 = (u8 *)(sdkSpriteNewNode(packAddress, 0x12));
            sdkSpriteDrawSized(footerSprite16, 548.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite16);
            return;
        case 3:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite17 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite17, (f32) 0x141, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite17);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite18 = (u8 *)(sdkSpriteNewNode(packAddress, 0x18));
            sdkSpriteDrawSized(footerSprite18, 374.0f, 406.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite18);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite19 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite19, (f32) 0x1AD, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite19);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite20 = (u8 *)(sdkSpriteNewNode(packAddress, 0xF));
            sdkSpriteDrawSized(footerSprite20, (f32) 0x1BB, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite20);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite21 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite21, 484.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite21);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite22 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite22, 498.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite22);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite23 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite23, (f32) 0x216, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite23);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite24 = (u8 *)(sdkSpriteNewNode(packAddress, 0x11));
            sdkSpriteDrawSized(footerSprite24, 548.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite24);
            return;
        case 4:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite25 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite25, (f32) 0x141, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite25);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite26 = (u8 *)(sdkSpriteNewNode(packAddress, 0x18));
            sdkSpriteDrawSized(footerSprite26, 374.0f, 406.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite26);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite27 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite27, (f32) 0x1AD, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite27);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite28 = (u8 *)(sdkSpriteNewNode(packAddress, 0xF));
            sdkSpriteDrawSized(footerSprite28, (f32) 0x1BB, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite28);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite29 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite29, 484.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite29);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite30 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite30, 498.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite30);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite31 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite31, (f32) 0x216, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite31);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite32 = (u8 *)(sdkSpriteNewNode(packAddress, 0x12));
            sdkSpriteDrawSized(footerSprite32, 548.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite32);
            return;
        case 5:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite33 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite33, 370.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite33);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite34 = (u8 *)(sdkSpriteNewNode(packAddress, 0x18));
            sdkSpriteDrawSized(footerSprite34, 428.0f, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite34);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite35 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite35, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite35);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite36 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite36, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite36);
            return;
        case 6:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite37 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite37, 239.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite37);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite38 = (u8 *)(sdkSpriteNewNode(packAddress, 0x18));
            sdkSpriteDrawSized(footerSprite38, (f32) 0x129, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite38);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite39 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite39, (f32) 0x1A3, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite39);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite40 = (u8 *)(sdkSpriteNewNode(packAddress, 0x17));
            sdkSpriteDrawSized(footerSprite40, 438.0f, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite40);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite41 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite41, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite41);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite42 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite42, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite42);
            return;
        case 7:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite43 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite43, (f32) 0x1A3, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite43);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite44 = (u8 *)(sdkSpriteNewNode(packAddress, 0x17));
            sdkSpriteDrawSized(footerSprite44, 438.0f, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite44);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite45 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite45, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite45);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite46 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite46, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite46);
            return;
        case 8:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite47 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite47, (f32) 0x15F, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite47);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite48 = (u8 *)(sdkSpriteNewNode(packAddress, 0x15));
            sdkSpriteDrawSized(footerSprite48, (f32) 0x16D, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite48);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite49 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite49, 420.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite49);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite50 = (u8 *)(sdkSpriteNewNode(packAddress, 0x14));
            sdkSpriteDrawSized(footerSprite50, 434.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite50);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite51 = (u8 *)(sdkSpriteNewNode(packAddress, 0xC));
            sdkSpriteDrawSized(footerSprite51, (f32) 0x1ED, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite51);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite52 = (u8 *)(sdkSpriteNewNode(packAddress, 0x16));
            sdkSpriteDrawSized(footerSprite52, 508.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite52);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite53 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite53, (f32) 0x227, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite53);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite54 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite54, (f32) 0x235, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite54);
            return;
        case 9:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite55 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite55, 144.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite55);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite56 = (u8 *)(sdkSpriteNewNode(packAddress, 0x13));
            sdkSpriteDrawSized(footerSprite56, 202.0f, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite56);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite57 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite57, (f32) 0x12F, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite57);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite58 = (u8 *)(sdkSpriteNewNode(packAddress, 0x15));
            sdkSpriteDrawSized(footerSprite58, 322.0f, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite58);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite59 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite59, 430.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite59);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite60 = (u8 *)(sdkSpriteNewNode(packAddress, 0x1A));
            sdkSpriteDrawSized(footerSprite60, (f32) 0x1C1, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite60);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite61 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite61, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite61);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite62 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite62, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite62);
            return;
        case 11:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite63 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite63, (f32) 0x11F, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite63);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite64 = (u8 *)(sdkSpriteNewNode(packAddress, 0x13));
            sdkSpriteDrawSized(footerSprite64, (f32) 0x159, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite64);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite65 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite65, 430.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite65);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite66 = (u8 *)(sdkSpriteNewNode(packAddress, 0x1A));
            sdkSpriteDrawSized(footerSprite66, (f32) 0x1C1, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite66);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite67 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite67, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite67);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite68 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite68, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite68);
            return;
        case 12:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite69 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite69, 224.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite69);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite70 = (u8 *)(sdkSpriteNewNode(packAddress, 0x13));
            sdkSpriteDrawSized(footerSprite70, 282.0f, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite70);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite71 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite71, (f32) 0x16F, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite71);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite72 = (u8 *)(sdkSpriteNewNode(packAddress, 0xF));
            sdkSpriteDrawSized(footerSprite72, (f32) 0x183, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite72);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite73 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite73, 430.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite73);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite74 = (u8 *)(sdkSpriteNewNode(packAddress, 0x1A));
            sdkSpriteDrawSized(footerSprite74, (f32) 0x1C1, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite74);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite75 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite75, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite75);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite76 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite76, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite76);
            return;
        case 13:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite77 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite77, (f32) 0x12F, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite77);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite78 = (u8 *)(sdkSpriteNewNode(packAddress, 0x15));
            sdkSpriteDrawSized(footerSprite78, 322.0f, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite78);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite79 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite79, 430.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite79);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite80 = (u8 *)(sdkSpriteNewNode(packAddress, 0x1A));
            sdkSpriteDrawSized(footerSprite80, (f32) 0x1C1, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite80);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite81 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite81, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite81);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite82 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite82, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite82);
            return;
        case 10:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite83 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite83, 446.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite83);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite84 = (u8 *)(sdkSpriteNewNode(packAddress, 0x1A));
            sdkSpriteDrawSized(footerSprite84, (f32) 0x1D1, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite84);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite85 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite85, (f32) 0x236, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite85);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite86 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite86, (f32) 0x249, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite86);
            return;
        case 14:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite87 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite87, 250.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite87);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite88 = (u8 *)(sdkSpriteNewNode(packAddress, 0x18));
            sdkSpriteDrawSized(footerSprite88, 308.0f, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite88);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite89 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite89, 430.0f, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite89);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite90 = (u8 *)(sdkSpriteNewNode(packAddress, 0x1A));
            sdkSpriteDrawSized(footerSprite90, (f32) 0x1C1, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite90);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite91 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite91, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite91);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite92 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite92, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite92);
            return;
        case 15:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite93 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite93, (f32) 0x227, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite93);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite94 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite94, (f32) 0x235, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite94);
            return;
        case 16:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite95 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite95, 482.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite95);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite96 = (u8 *)(sdkSpriteNewNode(packAddress, 0x19));
            sdkSpriteDrawSized(footerSprite96, 496.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite96);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite97 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite97, (f32) 0x223, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite97);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite98 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite98, (f32) 0x231, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite98);
            return;
        case 17:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite99 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite99, (f32) 0x197, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite99);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite100 = (u8 *)(sdkSpriteNewNode(packAddress, 0x1B));
            sdkSpriteDrawSized(footerSprite100, (f32) 0x1D1, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite100);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite101 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite101, (f32) 0x226, 410.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite101);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite102 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite102, (f32) 0x239, 412.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite102);
            return;
        case 18:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite103 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite103, 496.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite103);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite104 = (u8 *)(sdkSpriteNewNode(packAddress, 0x1F));
            sdkSpriteDrawSized(footerSprite104, 510.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite104);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite105 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite105, (f32) 0x227, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite105);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite106 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite106, (f32) 0x235, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite106);
            return;
        case 19:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite107 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite107, (f32) 0x13B, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite107);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite108 = (u8 *)(sdkSpriteNewNode(packAddress, 0x20));
            sdkSpriteDrawSized(footerSprite108, 366.0f, 406.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite108);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite109 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite109, (f32) 0x1AD, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite109);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite110 = (u8 *)(sdkSpriteNewNode(packAddress, 0xF));
            sdkSpriteDrawSized(footerSprite110, (f32) 0x1BB, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite110);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite111 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite111, 484.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite111);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite112 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite112, 498.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite112);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite113 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite113, (f32) 0x216, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite113);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite114 = (u8 *)(sdkSpriteNewNode(packAddress, 0x11));
            sdkSpriteDrawSized(footerSprite114, 548.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite114);
            return;
        case 20:
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite115 = (u8 *)(sdkSpriteNewNode(packAddress, 0xE));
            sdkSpriteDrawSized(footerSprite115, (f32) 0x13B, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite115);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite116 = (u8 *)(sdkSpriteNewNode(packAddress, 0x20));
            sdkSpriteDrawSized(footerSprite116, 366.0f, 406.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite116);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite117 = (u8 *)(sdkSpriteNewNode(packAddress, 0xA));
            sdkSpriteDrawSized(footerSprite117, (f32) 0x1AD, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite117);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite118 = (u8 *)(sdkSpriteNewNode(packAddress, 0xF));
            sdkSpriteDrawSized(footerSprite118, (f32) 0x1BB, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite118);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite119 = (u8 *)(sdkSpriteNewNode(packAddress, 0xB));
            sdkSpriteDrawSized(footerSprite119, 484.0f, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite119);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite120 = (u8 *)(sdkSpriteNewNode(packAddress, 0x10));
            sdkSpriteDrawSized(footerSprite120, 498.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite120);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite121 = (u8 *)(sdkSpriteNewNode(packAddress, 0xD));
            sdkSpriteDrawSized(footerSprite121, (f32) 0x216, (f32) 0x195, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, 0.0f, (s16) 0);
            sdkSpriteFreeNode(footerSprite121);
            if (packAddress == 0) {
                kAssertFail(D_0064B310, 0x94);
            }
            footerSprite122 = (u8 *)(sdkSpriteNewNode(packAddress, 0x12));
            sdkSpriteDrawSized(footerSprite122, 548.0f, 404.0f, depth, 0xFF, 0xFF, 0xFF, alpha, 0x1000, 0x1000, 0, fGpffff8224, (s16) 0);
            sdkSpriteFreeNode(footerSprite122);
            return;
        default:
            kAssertFail(D_0064B310, 0x243);
            break;
        }
    }
}
