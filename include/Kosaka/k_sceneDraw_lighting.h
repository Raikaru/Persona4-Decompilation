#ifndef K_SCENEDRAW_LIGHTING_H
#define K_SCENEDRAW_LIGHTING_H

#include "scene_light_override_internal.h"

/* k_sceneDraw getters and resetters expose both light matrices and the
 * intervening tint. Character/NPC model resources share the 0x168 tail;
 * light-list resources use the same tail starting at 0x140. */
typedef struct FldModelLighting {
    SceneLightModel light;
    SceneLightVector tint;              /* 0x1D0 */
    SceneLightMatrix secondMatrix;      /* 0x1E0 */
} FldModelLighting;

typedef struct FldSceneLighting {
    SceneLightResource12 light;
    SceneLightVector tint;              /* 0x1A0 */
    SceneLightMatrix secondMatrix;      /* 0x1B0 */
} FldSceneLighting;

/* Alternate model resources place colors at 0x15C/0x16C, then align the
 * first matrix at 0x180 rather than placing it immediately after color B. */
typedef struct FldAlternateModelLighting {
    u8 pad000[0x15C];
    SceneLightVector firstColor;
    SceneLightVector secondColor;
    u8 pad17C[4];
    SceneLightMatrix firstMatrix;
    SceneLightVector tint;
    SceneLightMatrix secondMatrix;
} FldAlternateModelLighting;

#endif
