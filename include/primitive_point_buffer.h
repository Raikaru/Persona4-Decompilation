#ifndef PRIMITIVE_POINT_BUFFER_H
#define PRIMITIVE_POINT_BUFFER_H

#include "type.h"

typedef struct { f32 v[2]; } PrimFloat2;

typedef union {
    struct { u32 w0, w1; } words;
    PrimFloat2 point;
} PrimPointRow;

/* Immediate input buffers: four color bytes and a two-float point per vertex. */
void func_0045e6a0(const void *colors, const void *positions,
                  f32 depth, u32 count, s32 primitive, s32 saveState,
                  s32 offsetX, s32 offsetY, f32 rotation, f32 scaleX, f32 scaleY);

#endif
