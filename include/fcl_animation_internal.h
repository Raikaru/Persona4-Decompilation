#ifndef FCL_ANIMATION_INTERNAL_H
#define FCL_ANIMATION_INTERNAL_H

#include "type.h"

/* Task setters store the low halfword of duration and delay. Their word
 * inputs remain words until those stores; task wrappers narrow delays
 * where the retail call boundary does. Floating arguments retain their
 * own EE register order. */
void fclSpriteStartAlpha(u8 *work, u8 first, u8 second, u8 mode, s32 duration, s32 delay);
void fclSpriteStartRevealScale(u8 *work, f32 firstX, f32 firstY, f32 secondX, f32 secondY,
                   u32 mode, u32 duration, s32 delay);
void fclSpriteStartTween(u8 *work, u8 mode, s32 duration, s16 delay, f32 first, f32 second);
void fclSpriteStartTweenAt(s16 resource, u8 mode, s32 duration, s32 delay, f32 first, f32 second);
u8 *fclObjectGetWork(u8 *task);
s8 fclObjTestFlagBit(u8 *task, s32 bit);
void fclObjStartAlpha(u8 *task, u8 first, u8 second, u8 mode, s32 duration, s16 delay);
void fclObjStartUniformRevealScale(u8 *task, f32 first, f32 second, u32 mode, u32 duration, s64 delay);
void fclObjStartRevealScale(u8 *task, f32 firstX, f32 firstY, f32 secondX, f32 secondY,
                   u32 mode, u32 duration, s64 delay);
void fclObjStartTween(u8 *task, f32 first, f32 second, u8 mode, s32 duration, s64 delay);
void fclBustupObjStartAlpha(u8 *task, u8 first, u8 second, u8 mode, s32 duration, s64 delay);
void fclBustupObjStartUniformRevealScale(u8 *task, f32 first, f32 second, u32 mode, u32 duration, s64 delay);
void fclBustupObjStartTween(u8 *task, f32 first, f32 second, u8 mode, s32 duration, s64 delay);

#endif
