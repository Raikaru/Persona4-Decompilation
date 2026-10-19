#ifndef RW_RASTER_INTERNAL_H
#define RW_RASTER_INTERNAL_H

#include "type.h"

/* RenderWare SDK layout from rw/core/baraster.h, using the project's scalar types. */
typedef struct RwRaster RwRaster;
struct RwRaster
{
    RwRaster *parent;
    u8 *cpPixels;
    u8 *palette;
    s32 width, height, depth;
    s32 stride;
    s16 nOffsetX, nOffsetY;
    u8 cType, cFlags, privateFlags, cFormat;
    u8 *originalPixels;
    s32 originalWidth, originalHeight, originalStride;
};

#endif
