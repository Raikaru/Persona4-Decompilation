#ifndef FIELD_SHADOW_INTERNAL_H
#define FIELD_SHADOW_INTERNAL_H

#include "rw_collision_internal.h"

/* These callbacks receive caller-owned shadow accumulation and projection
 * records through the same generic data pointer as the clump iterators. */
void *FldShadow_AccumulateAtomicBounds(void *atomic, void *data);
void *FldShadow_ProjectAtomic(void *atomic, void *data);

struct RpCollisionTriangle *FldShadow_ProjectTriangle(
    struct RpIntersection *intersection, struct RpWorldSector *sector,
    struct RpCollisionTriangle *triangle, f32 distance, void *data);
struct RpCollisionTriangle *FldShadow_ProjectSkinnedTriangle(
    struct RpIntersection *intersection, struct RpCollisionTriangle *triangle,
    f32 distance, void *data);

#endif
