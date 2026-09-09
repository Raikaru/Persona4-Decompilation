#ifndef SHD_MISC_INTERNAL_H
#define SHD_MISC_INTERNAL_H

#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

typedef union {
    Vec2f xy;
    s64 packed;
} PackedVec2f;

typedef union {
    u8 rgba[4];
    s32 packed;
} PackedColor4;

void func_00364320(Vec2f position, f32 depth, s32 color, s32 number);

void func_00364c90(Vec2f position, f32 depth, s32 color,
                   f32 width, f32 height, f32 angle, s32 mode);
void func_003657d0(Vec2f position, f32 depth, s32 color,
                   f32 radius, f32 angle, s32 mode);
void func_00365f00(Vec2f position, f32 depth, s32 centerColor, s32 edgeColor,
                   f32 radius, f32 angle, u32 segments, f32 xscale, f32 yscale,
                   s32 mode);

void func_00450dd0(PackedVec2f position, f32 depth, const void *format, ...);
void func_00450e80(PackedColor4 color, PackedVec2f position, f32 depth,
                   const void *format, ...);

#endif
