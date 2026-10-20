#ifndef SCENE_RENDER_INTERNAL_H
#define SCENE_RENDER_INTERNAL_H

#include "scene_resource_internal.h"

/* RenderWare matrix layout: four vectors interleaved with flags/pad words. */
struct RwMatrix {
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1C;
    RwV3d at;
    u32 pad2C;
    RwV3d pos;
    u32 pad3C;
};

/* RpLight prefix from the SDK: object.parent is the frame pointer, color
 * follows radius at +0x18. The scene passes the color as four floats. */
typedef struct SceneRenderLight {
    u8 pad00[4];
    s32 frame;
    u8 pad08[0x10];
    f32 color[4];
} SceneRenderLight;

/* Camera wrappers and lights both expose their frame through object.parent. */
typedef struct SceneRenderObject {
    u8 pad00[4];
    s32 frame;
} SceneRenderObject;

/* Saved light state packets used by the camera draw callbacks: 0xB0 bytes. */
typedef struct SceneLightingState {
    f32 primary[4];
    f32 secondary[4];
    struct RwMatrix secondaryMatrix;
    f32 tertiary[4];
    struct RwMatrix tertiaryMatrix;
} SceneLightingState;

/* Type-12 environment resource prefix. The field handle follows at +0x1A0
 * (ResrcRecord.handle1A0); only the lighting prefix is described here. */
typedef struct SceneEnvironmentResource {
    ResrcHeader base;
    f32 colorValue[4];
    f32 colorTarget[4];
    struct RwMatrix transform;
} SceneEnvironmentResource;

#endif
