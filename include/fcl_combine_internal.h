#ifndef FCL_COMBINE_INTERNAL_H
#define FCL_COMBINE_INTERNAL_H

#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} FclVec2;

/* Constructors also expose the same position as an eight-byte packet. */
typedef union {
    FclVec2 position;
    s64 bits;
} FclPackedPosition;

static inline FclVec2 fclPacketPosition(s64 bits)
{
    FclPackedPosition packet;
    packet.bits = bits;
    return packet.position;
}

void func_002b6c30(s64 resource, FclVec2 position, s32 order, f32 depth);

void func_002b2970(u8 *out, f32 x, f32 y);

void func_003147e0(u8 *task, s8 slot, FclVec2 position, s16 resource,
                   s32 order, s32 mode);

#endif
