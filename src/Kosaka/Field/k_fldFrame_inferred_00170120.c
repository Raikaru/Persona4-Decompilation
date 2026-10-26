#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "field_scene_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
struct RpGeometry;
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct RwRGBA RwRGBA;
typedef s32 (*FieldRenderStateSetFunction)(RwRenderState, void *);
struct Model;
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;
typedef struct
{
    u8 pad_00178590[0x144];
    u8 *field_144;
} S_00178590;
typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;
typedef struct
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FieldColor_0017;
extern s32 FldCharacterAnimSelect(s32 characterType);
extern s32 FldRoomIsListed(u16 field, u16 room);
extern u32 RpRandom(void);
extern s32 FldStepIndex(void);
/* Left unprototyped because retail masks the arguments in old-style default-promotion order;
 * Cmd_PickEncounter is the only caller. */
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
void FldSmapTileQueueQuad(u8 *queue, u8 *context, s32 tileType, s32 variant, s32 width,
                    s32 height, s32 flags, f32 x, f32 y, f32 depth);

extern f32 iGpffff8304;
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];


extern s32 FldShadow_DrawProjection(u8 *camera, s32 raster, s32 collisionKind, void *intersection,
                         f32 opacity, f32 depth, s32 fadeWithDepth, u8 *workData);
extern u8 D_007EFA00[];
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern f32 iGpffff826c;
extern f32 iGpffff8214;
extern f32 iGpffff8360;
extern u32 iGpffffb308;
extern u32 iGpffff9f4c;
extern u32 iGpffffb30c;
extern u32 iGpffff9f50;
extern s32 D_005F1930[];
extern s32 D_005F1934[];

extern u8 *D_007643D0;
extern FieldRenderStateSetFunction D_00887300[];
extern s32 iGpffffba48;


/* Select one of idle animations 6..8 for character type 1 in eligible rooms/steps;
 * otherwise retain animation 1. The preliminary selector call is preserved. */
// FUN_00170120
s32 FldPlayerRandomIdleAnimId(s32 characterType)
{
    u8 *scene;
    u8 *currentScene;

    FldCharacterAnimSelect(characterType);
    if (characterType != 1)
        return 1;
    scene = iGpffff9db0;
    if (FldRoomIsListed(((FieldSceneState *)scene)->field.half[0], ((FieldSceneState *)scene)->room.half[0]) == 1)
        return (RpRandom() % 3U) + 6;
    currentScene = iGpffff9db0;
    if ((((FieldSceneState *)currentScene)->field.value == 0x44) &&
        (((FieldSceneState *)currentScene)->room.value == 1))
        return (RpRandom() % 3U) + 6;
    if (FldStepIndex() != 0)
        return 1;
    return (RpRandom() % 3U) + 6;
}

