/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0025e9e0-0025ecd0 */

#include "include_asm.h"
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
#pragma push
#pragma opt_propagation on
// Intent: Draws a sprite node at unit scale with no size offset (wrapper of sdkSpriteDrawNow) [inferred]
// FUN_0025E9E0
void sdkSpriteDrawNowUnscaled(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void * pack, s32 setStates) {
    sdkSpriteDrawNow(x, y, depth, rgb, alpha, recordIndex, pack, setStates, 0, 0, 0.0f, 1.0f, 1.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* measured: plain `(u16)(4096.0f * scaleX)` and `(u16)(4096.0f * scaleY)` casts reproduce both compiler-generated float-to-unsigned conversion paths; MATCH object 484B/window 496B. Each retail site begins `lui 0x4580; mtc1; mul.s; lui 0x4F00; mtc1; c.ole.s`, then uses low `cvt.w.s; mfc1; andi` or high `sub.s; cvt.w.s; mfc1; lui 0x8000; or; andi` before `sh`. The `or` is after `mfc1`, and the 4096.0f `mul.s` is genuine scaling. */
// Intent: Creates a sprite node at a position with alpha, colour, texture and scale, and draws it when both scales are nonzero [inferred]
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
    /* Raw scale zero-tests avoid the member-address hoisting measured across unsigned conversions. */
    if ((*(u16 *)(sprite + 0x20) != 0) &&
        (*(u16 *)(sprite + 0x22) != 0)) {
        sdkSpriteDraw(sprite, setStates);
    }
    sdkSpriteFreeNode(sprite);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* measured: plain `(u16)(4096.0f * scaleX)` and `(u16)(4096.0f * scaleY)` casts reproduce both compiler-generated float-to-unsigned conversion paths; MATCH object 588B/window 592B. Each retail site begins `lui 0x4580; mtc1; mul.s; lui 0x4F00; mtc1; c.ole.s`, then uses low `cvt.w.s; mfc1; andi` or high `sub.s; cvt.w.s; mfc1; lui 0x8000; or; andi` before `sh`. The `or` is after `mfc1`, and the 4096.0f `mul.s` is genuine scaling. */
// Intent: Creates a sprite node like sdkSpriteDrawNow but queues its draw as a task callback; arg4 == 1 selects the flag-1 callback [inferred]
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
    /* Raw scale zero-tests avoid the member-address hoisting measured across unsigned conversions. */
    if (*(u16 *)(sprite + 0x20) == 0) {
        goto cleanup;
    }
    if (*(u16 *)(sprite + 0x22) == 0) {
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
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Queued draw callback: draws the sprite node with flag 1, then frees it [inferred]
// FUN_0025EC10
void sdkSpriteDrawAndFreeFlag1(s32 drawContext, u8 *sprite) {
    sdkSpriteDraw(sprite, 1);
    sdkSpriteFreeNode(sprite);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Queued draw callback: draws the sprite node with flag 0, then frees it [inferred]
// FUN_0025EC50
void sdkSpriteDrawAndFreeFlag0(s32 drawContext, u8 *sprite) {
    sdkSpriteDraw(sprite, 0);
    sdkSpriteFreeNode(sprite);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Queued unit-scale sprite draw (wrapper of sdkSpriteDrawQueued) [inferred]
// FUN_0025EC90
void sdkSpriteDrawQueuedUnscaled(f32 x, f32 y, f32 depth,
                   s32 rgb, u8 alpha, s32 recordIndex, void *pack, s32 setStates, void *queue) {
    sdkSpriteDrawQueued(x, y, depth, rgb, alpha, recordIndex, pack, setStates,
                  0, 0, 0.0f, 1.0f, 1.0f, queue);
}
#pragma pop
