#ifndef RW_TYPES_INTERNAL_H
#define RW_TYPES_INTERNAL_H

#include "type.h"

/* RenderWare SDK scalar types (include/rw/inc/rwplcore.h, rw/ps2/ostypes.h). */
typedef f32 RwReal;
typedef u8 RwUInt8;

/* Field names and layout follow the SDK: batypes.h (RwV3d), rtquat.h (RtQuat),
   bacolor.h (RwRGBA). */
typedef struct RwV3d RwV3d;
struct RwV3d
{
    RwReal x;
    RwReal y;
    RwReal z;
};

typedef struct RtQuat RtQuat;
struct RtQuat
{
    RwV3d imag;
    RwReal real;
};

typedef struct RwRGBA RwRGBA;
struct RwRGBA
{
    RwUInt8 red;
    RwUInt8 green;
    RwUInt8 blue;
    RwUInt8 alpha;
};

#endif
