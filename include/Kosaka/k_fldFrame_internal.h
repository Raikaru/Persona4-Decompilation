#ifndef K_FLD_FRAME_INTERNAL_H
#define K_FLD_FRAME_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"



/* line contains two points; a miss leaves the three-component hit point unchanged. */
extern u32 FldFrame_RaycastSelectedWorld(const RwV3d* line, RwV3d* hitPointDst);

#endif
