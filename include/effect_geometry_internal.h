#ifndef EFFECT_GEOMETRY_INTERNAL_H
#define EFFECT_GEOMETRY_INTERNAL_H

#include "type.h"

struct RwMatrix;
struct RwV3d;
void GeometryMatrixBuild(struct RwMatrix *matrix, struct RwV3d *translation,
                         void *basis, f32 scale);
void GeometryMatrixBuildCombined(struct RwMatrix *matrix, struct RwV3d *translation,
                                 void *basis, struct RwV3d *scale);
void GeometryBlockSetFrameMatrix(u8 *block, struct RwV3d *translation,
                                void *basis, f32 scale);
void GeometryBlockSetFrameMatrixCombined(u8 *block, struct RwV3d *translation,
                                        void *basis, struct RwV3d *scale);

u8 *GeometryCreateTableGrid(s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow,
                  const void *indices, s32 flags);

#endif
