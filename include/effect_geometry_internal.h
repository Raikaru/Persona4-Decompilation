#ifndef EFFECT_GEOMETRY_INTERNAL_H
#define EFFECT_GEOMETRY_INTERNAL_H

#include "type.h"

u8 *GeometryCreateTableGrid(s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow,
                  const void *indices, s32 flags);

#endif
