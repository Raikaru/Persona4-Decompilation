#ifndef FCL_SCALE_TRANSITION_H
#define FCL_SCALE_TRANSITION_H

#include "type.h"

/* Four independent scale channels precede the mode and timing words. The
   setter stores low halfwords; forwarding wrappers perform their native
   signed-halfword conversion before submitting the delay. */
void func_002b8300(u8 *work, f32 firstX, f32 firstY, f32 secondX, f32 secondY,
                   u32 mode, u32 duration, s32 delay);
void func_002b6ac0(u8 *task, f32 firstX, f32 firstY, f32 secondX, f32 secondY,
                   u32 mode, u32 duration, s32 delay);
void func_002b6af0(s16 resource, f32 firstX, f32 firstY, f32 secondX, f32 secondY,
                   u32 mode, u32 duration, s16 delay);
void func_002e0690(u8 *task, f32 first, f32 second,
                   u32 mode, u32 duration, s64 delay);
void func_002e06d0(u8 *task, f32 firstX, f32 firstY, f32 secondX, f32 secondY,
                   u32 mode, u32 duration, s64 delay);
void func_0033d4e0(u8 *task, f32 first, f32 second,
                   u32 mode, u32 duration, s64 delay);

#endif
