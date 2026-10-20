#ifndef PRIMITIVE_POINT_BUFFER_H
#define PRIMITIVE_POINT_BUFFER_H

#include "type.h"

typedef struct { f32 v[2]; } PrimPoint;

typedef union {
    struct { u32 w0, w1; } words;
    PrimPoint point;
} PrimPointRow;

/* Immediate input buffers: four color bytes and a two-float point per vertex. */
void PrimDrawTransformed(const void *colors, const void *positions,
                  f32 depth, u32 count, s32 primitiveType, s32 preserveState,
                  s32 offsetX, s32 offsetY, f32 rotation, f32 scaleX, f32 scaleY);

#endif
