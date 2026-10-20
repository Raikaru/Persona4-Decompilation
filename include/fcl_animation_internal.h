#ifndef FCL_ANIMATION_INTERNAL_H
#define FCL_ANIMATION_INTERNAL_H

#include "type.h"

/* Task setters store the low halfword of duration and delay. Their word
 * inputs remain words until those stores; task wrappers narrow delays
 * where the retail call boundary does. Floating arguments retain their
 * own EE register order. */
void fclSpriteStartAlpha(u8 *animation, u8 startAlpha, u8 endAlpha, u8 mode, s32 duration, s32 delay);
void fclSpriteStartRevealScale(u8 *animation, f32 startX, f32 endX, f32 startY, f32 endY,
                   u32 mode, u32 duration, s32 delay);
void fclSpriteStartTween(u8 *animation, u8 mode, s32 duration, s16 delay, f32 start, f32 end);
void fclSpriteStartTweenAt(s16 index, u8 mode, s32 duration, s32 delay, f32 start, f32 end);
u8 *fclObjectGetWork(u8 *task);
s8 fclObjTestFlagBit(u8 *task, s32 bitIndex);
void fclObjStartAlpha(u8 *task, u8 startAlpha, u8 endAlpha, u8 mode, s32 duration, s16 delay);
void fclObjStartUniformRevealScale(u8 *task, f32 startScale, f32 endScale, u32 mode, u32 duration, s64 delay);
void fclObjStartRevealScale(u8 *task, f32 startX, f32 endX, f32 startY, f32 endY,
                   u32 mode, u32 duration, s64 delay);
void fclObjStartTween(u8 *task, f32 first, f32 second, u8 mode, s32 duration, s64 delay);
void fclBustupObjStartAlpha(u8 *task, u8 start, u8 end, u8 easing, s32 duration, s64 delay);
void fclBustupObjStartUniformRevealScale(u8 *task, f32 start, f32 end, u32 easing, u32 duration, s64 delay);
void fclBustupObjStartTween(u8 *task, f32 start, f32 end, u8 easing, s32 duration, s64 delay);

#endif
