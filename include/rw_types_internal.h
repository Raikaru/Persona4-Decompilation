#ifndef RW_TYPES_INTERNAL_H
#define RW_TYPES_INTERNAL_H

#include "type.h"

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

typedef struct RwRGBA RwRGBA;
struct RwRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
};

#endif
