#ifndef SCENE_RESOURCE_INTERNAL_H
#define SCENE_RESOURCE_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"
#include "resrc_manager_internal.h"

/* Common resource prefix and kind-specific tails recovered from the P4
 * setters and MT_Scene_UpdateResource. The common prefix ends at 0x140;
 * the actual allocation size is selected by resource kind. */


typedef struct SceneQueuedAnimation {
    s32 layer;
    s32 animation;
    s32 frame;
    s32 flags;
    s32 blend;
    f32 speed;
} SceneQueuedAnimation;


typedef struct SceneCharacterUpdate {
    ResrcHeader base;
    u8 *effects[2];
    u32 unknown148;
    SceneQueuedAnimation animation;
    u8 *model;
} SceneCharacterUpdate;

typedef struct SceneObjectUpdate {
    ResrcHeader base;
    SceneQueuedAnimation animation;
    u8 *model;
} SceneObjectUpdate;

typedef struct SceneEffectUpdate {
    ResrcHeader base;
    u32 unknown140;
    u8 *effect;
} SceneEffectUpdate;

typedef struct SceneCameraUpdate {
    ResrcHeader base;
    f32 fov;
} SceneCameraUpdate;

/* Point/quad constructors and terrain sampling prove these resource tails. */
typedef struct ScenePointResource {
    ResrcHeader base;
    RwV3d point;
    f32 radius;
} ScenePointResource;

typedef struct SceneQuadResource {
    ResrcHeader base;
    RwRGBA color;
    RwV3d center;
    f32 width, height, angle;
    RwV3d corners[4];
    s32 terrain;
} SceneQuadResource;

/* Type 20 owns two separately allocated RenderWare matrices. */
typedef struct SceneCaptureCameraResource {
    ResrcHeader base;
    s32 kind;
    f32 value;
    u8 *matrices[2];
    RwV3d position;
    f32 nearValue, farValue;
    u8 parameters[0x20];
    u8 data[0x180];
} SceneCaptureCameraResource;

/* Packed cubic path: signed segment count, then 3*n+1 shared endpoints.
 * Adjacent cubic segments advance by three 12-byte control points. */
typedef struct ScenePathPoint { f32 x, y, z; } ScenePathPoint;
typedef struct ScenePath {
    s8 count;
    u8 pad01[3];
    ScenePathPoint points[1];
} ScenePath;
#endif
