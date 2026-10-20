#ifndef RW_GEOMETRY_LAYOUT_INTERNAL_H
#define RW_GEOMETRY_LAYOUT_INTERNAL_H

#include "rw_types_internal.h"
#include "rw_object_internal.h"

/* SDK batextur.h texture-coordinate pair. */
typedef struct RwTexCoords { f32 u, v; } RwTexCoords;

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
    RwObject object;
    u32 flags;
    u16 lockedSinceLastInst;
    s16 refCount;
    s32 numTriangles;
    s32 numVertices;
    s32 numMorphTargets;
    s32 numTexCoordSets;
    struct { struct RpMaterial **materials; s32 numMaterials, space; } matList;
    struct RpTriangle *triangles;
    RwRGBA *preLitLum;
    RwTexCoords *texCoords[8];
    struct RpMeshHeader *mesh;
    struct RwResEntry *repEntry;
    struct RpMorphTarget *morphTarget;
};

struct RpMaterial {
    void *texture;
    RwRGBA color;
};

#endif
