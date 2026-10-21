
#include "include_asm.h"
#include "member_access.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
extern void sdkSpriteDraw(u8 *, s32);
extern void sdkSpriteFreeNode(void *);
extern u8 *sdkSpriteNewNode(u32, u32);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(u8 *, u8 *);

#include "primitive_queue_internal.h"
/* Layout shared with Kernel/sdkSpr.c; sdkSpriteNewNode allocates 0x2C bytes. */
typedef struct SdkSpriteSample {
    u32 packAddress;
    u32 recordIndex;
    f32 x, y;
    u8 alphaSubtract, fade;
    u8 pad12[2];
    s16 extendX, extendY;
    f32 angle;
    s16 pivotX, pivotY;
    u16 scaleX, scaleY; /* Q12: 4096 is unit scale. */
    f32 depth;
    u8 red, green, blue, pad2B;
} SdkSpriteSample;
extern void sdkSpriteDrawAndFreeFlag1(s32 drawContext, u8 *sprite);
extern void sdkSpriteDrawAndFreeFlag0(s32 drawContext, u8 *sprite);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
s32 sdkSpriteDrawNow(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void * pack, s32 setStates, s16 pivotX, s16 pivotY, f32 angle, f32 scaleX, f32 scaleY);
/* Unit setting: propagate ordinary local values. */
#pragma opt_propagation on
// Draws a sprite at unit scale with no pivot or rotation; wrapper of sdkSpriteDrawNow.
// FUN_0025E9E0
void sdkSpriteDrawNowUnscaled(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void * pack, s32 setStates) {
    sdkSpriteDrawNow(x, y, depth, rgb, alpha, recordIndex, pack, setStates, 0, 0, 0.0f, 1.0f, 1.0f);
}

/* Creates a sprite node with position, alpha, colour, texture and scale, and draws it when both
 * scales are nonzero. */
// FUN_0025EA20
s32 sdkSpriteDrawNow(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void * pack, s32 setStates, s16 pivotX, s16 pivotY, f32 angle, f32 scaleX, f32 scaleY) {
    u8 *sprite;

    sprite = sdkSpriteNewNode((u32)pack, recordIndex);
    ((SdkSpriteSample *)sprite)->x = x;
    ((SdkSpriteSample *)sprite)->y = y;
    ((SdkSpriteSample *)sprite)->depth = depth;
    ((SdkSpriteSample *)sprite)->fade = (s8)(0xFF - alpha);
    ((SdkSpriteSample *)sprite)->red = (s8)((u32)rgb >> 0x10);
    ((SdkSpriteSample *)sprite)->green = (s8)((u32)rgb >> 8);
    ((SdkSpriteSample *)sprite)->blue = (u8)rgb;
    ((SdkSpriteSample *)sprite)->pivotX = (s16)pivotX;
    ((SdkSpriteSample *)sprite)->pivotY = (s16)pivotY;
    ((SdkSpriteSample *)sprite)->angle = angle;
    ((SdkSpriteSample *)sprite)->scaleX = (u16)(4096.0f * scaleX);
    ((SdkSpriteSample *)sprite)->scaleY = (u16)(4096.0f * scaleY);
    if ((MEMBER(u16, sprite, SdkSpriteSample, scaleX) != 0) &&
        (MEMBER(u16, sprite, SdkSpriteSample, scaleY) != 0)) {
        sdkSpriteDraw(sprite, setStates);
    }
    sdkSpriteFreeNode(sprite);
    return 0;
}

/* Creates a sprite node like sdkSpriteDrawNow but queues its draw as a task callback; scales are
 * stored as 4.12 fixed point via plain (u16) casts. */
// FUN_0025ECD0
s32 sdkSpriteDrawQueued(f32 x, f32 y, f32 depth,
                  s32 rgb, u8 alpha, s32 recordIndex, void *pack,
                  s32 setStates, s16 pivotX, s16 pivotY,
                  f32 angle, f32 scaleX, f32 scaleY, void *queue) {
    u8 *drawNode;
    u8 *sprite;

    drawNode = PrimAllocQueueNode();
    sprite = sdkSpriteNewNode((u32)pack, recordIndex);
    ((SdkSpriteSample *)sprite)->x = x;
    ((SdkSpriteSample *)sprite)->y = y;
    ((SdkSpriteSample *)sprite)->depth = depth;
    ((SdkSpriteSample *)sprite)->fade = (s8)(0xFF - alpha);
    ((SdkSpriteSample *)sprite)->red = (s8)((u32)rgb >> 0x10);
    ((SdkSpriteSample *)sprite)->green = (s8)((u32)rgb >> 8);
    ((SdkSpriteSample *)sprite)->blue = rgb;
    ((SdkSpriteSample *)sprite)->pivotX = pivotX;
    ((SdkSpriteSample *)sprite)->pivotY = pivotY;
    ((SdkSpriteSample *)sprite)->angle = angle;
    ((SdkSpriteSample *)sprite)->scaleX = (u16)(4096.0f * scaleX);
    ((SdkSpriteSample *)sprite)->scaleY = (u16)(4096.0f * scaleY);
    if (MEMBER(u16, sprite, SdkSpriteSample, scaleX) == 0) {
        goto cleanup;
    }
    if (MEMBER(u16, sprite, SdkSpriteSample, scaleY) == 0) {
        goto cleanup;
    }
    if (setStates != 1) {
        goto drawWithoutStates;
    }
    ((PrimQueueNode *)drawNode)->callback = (void *)sdkSpriteDrawAndFreeFlag1;
    ((PrimQueueNode *)drawNode)->argument.data = sprite;
    goto enqueue;
drawWithoutStates:
    ((PrimQueueNode *)drawNode)->callback = (void *)sdkSpriteDrawAndFreeFlag0;
    ((PrimQueueNode *)drawNode)->argument.data = sprite;
enqueue:
    PrimAppendNode(queue, drawNode);
    goto done;
cleanup:
    sdkSpriteFreeNode(sprite);
done:
    return 0;
}

// Queued draw callback: draws the sprite node with flag 1, then frees it.
// FUN_0025EC10
void sdkSpriteDrawAndFreeFlag1(s32 drawContext, u8 *sprite) {
    sdkSpriteDraw(sprite, 1);
    sdkSpriteFreeNode(sprite);
}

// Queued draw callback: draws the sprite node with flag 0, then frees it.
// FUN_0025EC50
void sdkSpriteDrawAndFreeFlag0(s32 drawContext, u8 *sprite) {
    sdkSpriteDraw(sprite, 0);
    sdkSpriteFreeNode(sprite);
}

// Queued unit-scale sprite draw; wrapper of sdkSpriteDrawQueued.
// FUN_0025EC90
void sdkSpriteDrawQueuedUnscaled(f32 x, f32 y, f32 depth,
                   s32 rgb, u8 alpha, s32 recordIndex, void *pack, s32 setStates, void *queue) {
    sdkSpriteDrawQueued(x, y, depth, rgb, alpha, recordIndex, pack, setStates,
                  0, 0, 0.0f, 1.0f, 1.0f, queue);
}
