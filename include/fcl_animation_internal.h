#ifndef FCL_ANIMATION_INTERNAL_H
#define FCL_ANIMATION_INTERNAL_H

#include "type.h"

/* Task setters store the low halfword of duration and delay. Their word
 * inputs remain words until those stores; task wrappers narrow delays
 * where the retail call boundary does. Floating arguments retain their
 * own EE register order. */
void func_002b82d0(u8 *work, u8 first, u8 second, u8 mode, s32 duration, s32 delay);
void func_002b8300(u8 *work, f32 firstX, f32 firstY, f32 secondX, f32 secondY,
                   u32 mode, u32 duration, s32 delay);
void func_002b8340(u8 *work, u8 mode, s32 duration, s16 delay, f32 first, f32 second);
void func_002b6b40(s16 resource, u8 mode, s32 duration, s32 delay, f32 first, f32 second);
u8 *func_002e04e0(u8 *task);
s8 func_002e0570(u8 *task, s32 bit);
void func_002e0660(u8 *task, u8 first, u8 second, u8 mode, s32 duration, s16 delay);
void func_002e0690(u8 *task, f32 first, f32 second, u32 mode, u32 duration, s64 delay);
void func_002e06d0(u8 *task, f32 firstX, f32 firstY, f32 secondX, f32 secondY,
                   u32 mode, u32 duration, s64 delay);
void func_002e0940(u8 *task, f32 first, f32 second, u8 mode, s32 duration, s64 delay);
void func_0033d4b0(u8 *task, u8 first, u8 second, u8 mode, s32 duration, s64 delay);
void func_0033d4e0(u8 *task, f32 first, f32 second, u32 mode, u32 duration, s64 delay);
void func_0033d520(u8 *task, f32 first, f32 second, u8 mode, s32 duration, s64 delay);

#endif
