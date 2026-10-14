#ifndef SCENE_LIGHT_OVERRIDE_INTERNAL_H
#define SCENE_LIGHT_OVERRIDE_INTERNAL_H

#include "type.h"

typedef struct SceneLightVector { f32 x, y, z, w; } SceneLightVector;
typedef struct RwV3d { f32 x, y, z; } SceneLightAxis;
/* RenderWare's real 64-byte layout, including its three reserved words. */
typedef struct RwMatrixTag {
    SceneLightAxis right;
    u32 flags;
    SceneLightAxis up;
    u32 pad1;
    SceneLightAxis at;
    u32 pad2;
    SceneLightAxis pos;
    u32 pad3;
} SceneLightMatrix;

typedef struct SceneLightSlot {
    s32 mode;
    u8 *resource;
    SceneLightVector secondColor;
    SceneLightVector angles;
    SceneLightVector firstColor;
    f32 unknown38;
    f32 unknown3c;
} SceneLightSlot;

typedef struct SceneLightModel {
    u16 resourceId;
    u8 unknown02[0x166];
    SceneLightVector firstColor;
    SceneLightVector secondColor;
    u8 unknown188[8];
    SceneLightMatrix matrix;
} SceneLightModel;

typedef struct SceneLightResource12 {
    u16 resourceId;
    u8 unknown02[0x13e];
    SceneLightVector firstColor;
    SceneLightVector secondColor;
    SceneLightMatrix matrix;
} SceneLightResource12;

typedef struct SceneLightWork {
    u8 unknown00[0x6f0];
    SceneLightVector firstColor;
    SceneLightVector secondColor;
    SceneLightMatrix matrix;
} SceneLightWork;

typedef char SceneLightVectorSize[sizeof(SceneLightVector) == 0x10 ? 1 : -1];
typedef char SceneLightMatrixSize[sizeof(SceneLightMatrix) == 0x40 ? 1 : -1];
typedef char SceneLightSlotSize[sizeof(SceneLightSlot) == 0x40 ? 1 : -1];
typedef char SceneLightModelSize[sizeof(SceneLightModel) == 0x1d0 ? 1 : -1];
typedef char SceneLightResource12Size[sizeof(SceneLightResource12) == 0x1a0 ? 1 : -1];
typedef char SceneLightWorkSize[sizeof(SceneLightWork) == 0x750 ? 1 : -1];

static inline void sceneLightIdentity(SceneLightMatrix *matrix)
{
    matrix->right.x = matrix->up.y = matrix->at.z = 1.0f;
    matrix->right.y = matrix->right.z = matrix->up.x = 0.0f;
    matrix->up.z = matrix->at.x = matrix->at.y = 0.0f;
    matrix->pos.x = matrix->pos.y = matrix->pos.z = 0.0f;
    /* Retail reads unwritten local flags at 0028cac8/0028ccc8/0028ce28
     * before ORing 0x20003. The three reserved words are also not initialized
     * here. This deliberately reproduces those documented retail reads;
     * it does not assert host-C definedness or choose incoming W-lane values. */
    matrix->flags |= 0x20003;
}

#endif
