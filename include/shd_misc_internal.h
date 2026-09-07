#ifndef SHD_MISC_INTERNAL_H
#define SHD_MISC_INTERNAL_H

#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

void func_00364c90(Vec2f position, f32 depth, s32 color,
                   f32 width, f32 height, f32 angle, s32 mode);

#endif
