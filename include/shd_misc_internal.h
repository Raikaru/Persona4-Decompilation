#ifndef SHD_MISC_INTERNAL_H
#define SHD_MISC_INTERNAL_H

#include "type.h"
#include "fcl_draw_types.h"

/* Screen positions share the Fcl draw library's two-float type. */
typedef FclVec2 Vec2f;

typedef union {
    Vec2f xy;
    s64 packed;
} PackedVec2f;

typedef union {
    u8 rgba[4];
    s32 packed;
} PackedColor4;

void shdDrawNumberText(Vec2f pos, f32 z, s32 color, s32 num);

void shdDrawRotatedRect(Vec2f position, f32 depth, s32 color,
                   f32 width, f32 height, f32 angle, s32 mode);
void shdDrawWedge(Vec2f position, f32 depth, s32 color,
                   f32 angle, s32 blend, s32 farColumn);
void shdDrawRotatingQuad(Vec2f position, f32 depth, s32 color,
                   f32 radius, f32 initialAngle, s32 blend);
void shdDrawRectOutline(Vec2f position, f32 depth, s32 color,
                   f32 angle, f32 width, f32 height, s32 mode);

void shdDrawRadialFan(Vec2f position, f32 depth, s32 centerColor, s32 edgeColor,
                   f32 radius, f32 angle, u32 segments, f32 xscale, f32 yscale,
                   s32 mode);

void sdkDbprtPrint(PackedVec2f position, f32 depth, const void *format, ...);
void sdkDbprtPrintColor(PackedColor4 color, PackedVec2f position, f32 depth,
                   const void *format, ...);

#endif
