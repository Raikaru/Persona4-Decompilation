#ifndef FCL_DRAW_TYPES_H
#define FCL_DRAW_TYPES_H

#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} FclVec2;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} FclVec3;

/* Value constructors. The struct is returned through the hidden result
   pointer in $a0, ahead of the coordinates in $f12/$f13/$f14. */
FclVec2 func_002b2970(f32 x, f32 y);
FclVec3 func_002b29a0(f32 x, f32 y, f32 z);

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
