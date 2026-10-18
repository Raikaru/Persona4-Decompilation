#ifndef K_SHADOW_LAYOUT_INTERNAL_H
#define K_SHADOW_LAYOUT_INTERNAL_H

#include "kwln_task_internal.h"

/* RwV3d/RwRGBA are supplied by each owning unit's existing RenderWare types.
 * FldShadow_CreateCaster allocates 0xe0 bytes, and all caster callbacks below
 * share these offsets. Resource IDs pack the list kind above bit nine. */
typedef struct FldShadowRing
{
    f32 radius;
    u8 *atomic;
    u8 *material;
} FldShadowRing;

typedef struct FldShadowCaster
{
    s32 state;
    s32 disabled;
    u16 resourceId;
    u16 mode;
    u8 *resource;
    u8 *model;
    void *largestAtomic;
    f32 height;
    u8 pad1C[0x10];
    RwV3d center;
    f32 radius;
    u8 *texture;
    u8 *raster;
    u8 *camera;
    RwRGBA savedColor;
    u8 *projection;
    FldShadowRing *ring;
    u8 pad54[0x2C];
    u8 savedMatrix[0x40];
    RwV3d mirrorPoint;
    union
    {
        RwV3d axis;
        u32 bits[3];
    } mirrorAxis;
    u8 padD8[8];
} FldShadowCaster;


#endif
