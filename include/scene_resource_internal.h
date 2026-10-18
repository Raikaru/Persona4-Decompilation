#ifndef SCENE_RESOURCE_INTERNAL_H
#define SCENE_RESOURCE_INTERNAL_H

#include "type.h"
#include "rw_types_internal.h"
#include "resrc_manager_internal.h"

/* Common resource prefix and kind-specific tails recovered from the P4
 * setters and MT_Scene_UpdateResource. The common prefix ends at 0x140;
 * the actual allocation size is selected by resource kind. */

typedef struct SceneScaleUpdate {
    RwV3d start;
    RwV3d end;
    u32 duration;
    u32 elapsed;
} SceneScaleUpdate;

typedef struct SceneFootstepUpdate {
    u8 mode;
    u8 sequence;
    u8 surface;
    u8 sound;
    u16 elapsed;
    u16 period;
    u16 delay;
    u16 unknown0a;
} SceneFootstepUpdate;

typedef union SceneMoveTime {
    u32 frame;
    f32 distance;
} SceneMoveTime;

typedef struct SceneQueuedAnimation {
    s32 layer;
    s32 animation;
    s32 frame;
    s32 flags;
    s32 blend;
    f32 speed;
} SceneQueuedAnimation;

typedef struct SceneUpdateResource {
    u16 id;
    u16 unknown02;
    RwV3d position;
    RwV3d rotation;
    RwV3d scale;
    u32 flags;
    u8 moveEase;
    u8 unknown2d[3];
    RwV3d moveStart;
    RwV3d moveEnd;
    u8 unknown48[12];
    u8 moveKind;
    u8 unknown55[3];
    s8 *path;
    f32 moveSpeed;
    SceneMoveTime moveElapsed;
    SceneMoveTime moveDuration;
    RwV3d rotationStart;
    RwV3d rotationEnd;
    u8 unknown80;
    u8 rotationEase;
    u16 unknown82;
    u32 rotationDuration;
    u32 rotationElapsed;
    u8 orbitEase;
    u8 unknown8d[3];
    RwV3d orbitStart;
    RwV3d orbitEnd;
    f32 yawStart;
    f32 yawEnd;
    f32 pitchStart;
    f32 pitchEnd;
    f32 distanceStart;
    f32 distanceEnd;
    u32 orbitDuration;
    u32 orbitElapsed;
    SceneScaleUpdate scaleUpdate;
    SceneFootstepUpdate footsteps;
    u8 alphaStart;
    u8 alphaEnd;
    u16 unknownf6;
    u32 alphaDuration;
    u32 alphaElapsed;
    s8 alphaBlend;
    u8 unknown101[3];
    f32 fovStart;
    f32 fovEnd;
    s32 fovDuration;
    s32 fovElapsed;
    u8 unknown114[0x20];
    s32 forcedFrames;
    struct SceneUpdateResource *next;
    struct SceneUpdateResource *previous;
} SceneUpdateResource;

typedef struct SceneCharacterUpdate {
    SceneUpdateResource base;
    u8 *effects[2];
    u32 unknown148;
    SceneQueuedAnimation animation;
    u8 *model;
} SceneCharacterUpdate;

typedef struct SceneObjectUpdate {
    SceneUpdateResource base;
    SceneQueuedAnimation animation;
    u8 *model;
} SceneObjectUpdate;

typedef struct SceneEffectUpdate {
    SceneUpdateResource base;
    u32 unknown140;
    u8 *effect;
} SceneEffectUpdate;

typedef struct SceneCameraUpdate {
    SceneUpdateResource base;
    f32 fov;
} SceneCameraUpdate;

/* Point/quad constructors and terrain sampling prove these resource tails. */
typedef struct ScenePointResource {
    SceneUpdateResource base;
    RwV3d point;
    f32 radius;
} ScenePointResource;

typedef struct SceneQuadResource {
    SceneUpdateResource base;
    RwRGBA color;
    RwV3d center;
    f32 width, height, angle;
    RwV3d corners[4];
    s32 terrain;
} SceneQuadResource;

/* Type 20 owns two separately allocated RenderWare matrices. */
typedef struct SceneCaptureCameraResource {
    SceneUpdateResource base;
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
