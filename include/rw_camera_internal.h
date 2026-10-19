#ifndef RW_CAMERA_INTERNAL_H
#define RW_CAMERA_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"
#include "rw_object_internal.h"
#include "rw_raster_internal.h"

typedef struct RwMatrixTag {
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
} RwMatrixTag;

/* SDK bacamera.h prefix through fogPlane; camera frustum storage is omitted.
 * The raster member uses the shared baraster.h layout. */

typedef struct RwCamera {
    RwObjectHasFrame object;
    s32 projectionType;
    void *beginUpdate;
    void *endUpdate;
    u8 viewMatrix[0x40];
    RwRaster *frameBuffer;
    RwRaster *zBuffer;
    f32 viewWindow[2];
    f32 recipViewWindow[2];
    f32 viewOffset[2];
    f32 nearPlane;
    f32 farPlane;
    f32 fogPlane;
} RwCamera;

#endif
