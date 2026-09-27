#ifndef FIELD_SHADOW_INTERNAL_H
#define FIELD_SHADOW_INTERNAL_H

#include "rw_collision_internal.h"

/* These callbacks receive caller-owned shadow accumulation and projection
 * records through the same generic data pointer as the clump iterators. */
void *func_00179130(void *atomic, void *data);
void *func_00179f70(void *atomic, void *data);

struct RpCollisionTriangle *func_001791d0(
    struct RpIntersection *intersection, struct RpWorldSector *sector,
    struct RpCollisionTriangle *triangle, f32 distance, void *data);
struct RpCollisionTriangle *func_00179860(
    struct RpIntersection *intersection, struct RpCollisionTriangle *triangle,
    f32 distance, void *data);

#endif
