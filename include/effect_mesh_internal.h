#ifndef EFFECT_MESH_INTERNAL_H
#define EFFECT_MESH_INTERNAL_H

#include "type.h"
#include "rw_geometry_internal.h"
#include "eff_geometry_block_internal.h"

typedef struct EffMeshColor {
    u8 c[4];
} EffMeshColor;

/* Native three-real material coefficients from rw/plcore/batypes.h. */
typedef struct RwSurfaceProperties {
    f32 ambient, specular, diffuse;
} RwSurfaceProperties;

/* Native RpMaterial layout from rw/world/bamateri.h. */
typedef struct RpMaterial {
    void *texture;
    EffMeshColor color;
    void *pipeline; /* 0x08, rw/world/bamateri.h */
    RwSurfaceProperties surfaceProps; /* 0x0C */
    s16 referenceCount;
    s16 pad1A;
} RpMaterial;

/* Native RenderWare prefixes from rw/sky2/rpworld.h. The SDK header itself
 * requires unavailable system headers; retain only the fields used by effects. */
typedef struct RpMorphTarget {
    RpGeometry *parentGeometry;
    f32 boundingSphere[4];
    f32 *vertices;
    f32 *normals;
} RpMorphTarget;

struct RpGeometry {
    u8 pad0[0xC];
    u16 lockedSinceLastInst;
    s16 referenceCount;
    s32 triangleCount, vertexCount, morphTargetCount, texCoordSetCount;
    u8 **materials;
    u8 pad24[8];
    void *triangles;
    u32 *colors;
    f32 *texCoords[8];
    void *mesh;
    void *resourceEntry;
    RpMorphTarget *morphTarget;
};

typedef struct RpAtomic RpAtomic;
struct RpAtomic {
    u8 pad0[4];
    void *frame; /* +0x04: object.object.parent in rw/world/baclump.h */
    u8 pad8[0x10];
    RpGeometry *geometry;
};

/* Wind strips advance four packed colors per row. */
typedef struct MdlEffectWindColorRow {
    u32 colors[4];
} MdlEffectWindColorRow;

#endif
