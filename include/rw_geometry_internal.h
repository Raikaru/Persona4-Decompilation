#ifndef RW_GEOMETRY_INTERNAL_H
#define RW_GEOMETRY_INTERNAL_H

#include "type.h"

typedef struct RpGeometry RpGeometry;

/* ORs lockMode into the geometry's lock word; bit 0 also releases its cached buffer (code1_003c.c). */
RpGeometry *RpGeometryLock(RpGeometry *geometry, s32 lockMode);

#endif
