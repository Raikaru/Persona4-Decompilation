#ifndef RW_CAMERA_INTERNAL_H
#define RW_CAMERA_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"

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

/* SDK layouts from rw/core/bacamera.h and baraster.h. Only the prefix
 * through fogPlane is needed here; camera frustum storage is omitted. */
typedef struct RwObject {
    u8 type;
    u8 subType;
    u8 flags;
    u8 privateFlags;
    void *parent;
} RwObject;

typedef struct RwObjectHasFrame {
    RwObject object;
    u8 pad08[0xC];
} RwObjectHasFrame;

typedef struct RwRaster {
    struct RwRaster *parent;
    u8 *cpPixels;
    u8 *palette;
    s32 width;
    s32 height;
    s32 depth;
} RwRaster;

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
