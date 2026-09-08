#ifndef K_FLD_FRAME_INTERNAL_H
#define K_FLD_FRAME_INTERNAL_H

#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

/* line contains two points; a miss leaves the three-component hit point unchanged. */
extern u32 func_0016b540(const RwV3d* line, RwV3d* hitPointDst);

#endif
