#ifndef RW_COLLISION_INTERNAL_H
#define RW_COLLISION_INTERNAL_H

#include "type.h"

struct RpAtomic;
struct RpWorld;
struct RpWorldSector;
struct RpIntersection;
struct RpCollisionTriangle;

/* RenderWare's distance argument belongs to both callback interfaces even
 * when a particular callback computes its own distance or ignores it. */
typedef struct RpCollisionTriangle *(*RwWorldTriangleCallback)(
    struct RpIntersection *, struct RpWorldSector *,
    struct RpCollisionTriangle *, f32 distance, void *data);
typedef struct RpCollisionTriangle *(*RwAtomicTriangleCallback)(
    struct RpIntersection *, struct RpCollisionTriangle *,
    f32 distance, void *data);

struct RpWorld *func_00394d70(struct RpWorld *world,
    struct RpIntersection *intersection, RwWorldTriangleCallback callback,
    void *data);
struct RpAtomic *func_00394e70(struct RpAtomic *atomic,
    struct RpIntersection *intersection, RwAtomicTriangleCallback callback,
    void *data);

#endif
