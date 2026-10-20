#ifndef RW_GEOMETRY_LAYOUT_INTERNAL_H
#define RW_GEOMETRY_LAYOUT_INTERNAL_H

#include "rw_types_internal.h"

/* SDK rpworld.h geometry/morph layouts and material prefix; opaque spans are not accessed here. */
typedef struct RwSphere {
    RwV3d center;
    f32 radius;
} RwSphere;

struct RpGeometry;
struct RpMorphTarget {
    struct RpGeometry *parentGeom;
    RwSphere boundingSphere;
    RwV3d *verts;
    RwV3d *normals;
};

struct RpGeometry {
    u8 pad00[0x2C];
    struct RpTriangle *triangles;
    RwRGBA *preLitLum;
    u8 pad34[0x28];
    struct RpMorphTarget *morphTarget;
};

struct RpMaterial {
    void *texture;
    RwRGBA color;
};

#endif
