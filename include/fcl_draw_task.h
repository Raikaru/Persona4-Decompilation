#ifndef FCL_DRAW_TASK_H
#define FCL_DRAW_TASK_H

#include "fcl_draw_types.h"
#include "fcl_color.h"

/* Creators return the SDK task handle; the handle is stored in EE word fields. */
s32 func_002b5c90(s32 parent, FclVec2 position);
s32 func_0034ad70(s32 parent, u8 count, s16 order);
s32 func_0034b740(s32 parent);
s32 func_002b8150(s32 parent);
s32 func_002b9f90(s32 parent, s16 count, s32 resource);

void func_002b5e30(u8 *task, FclDrawColor color);
u8 *func_002b5da0(u8 *task);

/* Integer and floating arguments keep their separate EE register order. */
void func_002b6af0(s16 resource, f32 scale0, f32 scale1, f32 scale2, f32 scale3,
                   u32 mode, u32 duration, s32 delay);
/* The draw takes its position by value. The mode arrives as a full word and
   is narrowed where it is tested; the reverse flag is a signed byte. */
void func_002b83e0(u8 *draw, FclVec2 position, FclDrawColor color0,
                   FclDrawColor color1, u8 alpha0, u8 alpha1, f32 height,
                   f32 depth, s32 duration, s32 delay, s32 mode, s8 reverse);

static inline FclDrawColor fclPacketColor(u32 bits)
{
    union { u32 bits; FclDrawColor color; } packet;
    packet.bits = bits;
    return packet.color;
}

#endif
