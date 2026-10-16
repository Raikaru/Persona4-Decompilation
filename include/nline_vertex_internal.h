#ifndef NLINE_VERTEX_INTERNAL_H
#define NLINE_VERTEX_INTERNAL_H

#include "type.h"

/* Write position, reciprocal depth and byte-derived color in one 0x40-byte vertex. */
void nLineSetLayer(u8 *vertex, f32 x, f32 y, f32 z, f32 reciprocal,
                  u8 red, u8 green, u8 blue, u8 alpha);

#endif
