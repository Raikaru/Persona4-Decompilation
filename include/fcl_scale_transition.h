#ifndef FCL_SCALE_TRANSITION_H
#define FCL_SCALE_TRANSITION_H

#include "type.h"

/* Four independent scale channels precede the mode and timing words. The
   setter stores low halfwords; forwarding wrappers perform their native
   signed-halfword conversion before submitting the delay. */
void fclSpriteStartRevealScale(u8 *animation, f32 startX, f32 endX, f32 startY, f32 endY,
                   u32 mode, u32 duration, s32 delay);
void fclSpriteStartRevealScaleTask(u8 *task, f32 startX, f32 endX, f32 startY, f32 endY,
                   u32 mode, u32 duration, s32 delay);
void fclSpriteStartRevealScaleAt(s16 index, f32 startX, f32 endX, f32 startY, f32 endY,
                   u32 mode, u32 duration, s16 delay);
void fclObjStartUniformRevealScale(u8 *task, f32 startScale, f32 endScale,
                   u32 mode, u32 duration, s64 delay);
void fclObjStartRevealScale(u8 *task, f32 startX, f32 endX, f32 startY, f32 endY,
                   u32 mode, u32 duration, s64 delay);
void fclBustupObjStartUniformRevealScale(u8 *task, f32 start, f32 end,
                   u32 easing, u32 duration, s64 delay);

#endif
