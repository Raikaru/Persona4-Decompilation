#ifndef FCL_DRAW_TYPES_H
#define FCL_DRAW_TYPES_H

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

#endif
