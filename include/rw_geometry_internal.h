#ifndef RW_GEOMETRY_INTERNAL_H
#define RW_GEOMETRY_INTERNAL_H

#include "type.h"

/* ORs lockMode into the geometry's lock word; bit 0 also releases its cached buffer (code1_003c.c). */
u8 *RpGeometryLock(u8 *geometry, s32 lockMode);

#endif
