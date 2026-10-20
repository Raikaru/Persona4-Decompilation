
/* Unit optimizer settings shared by player-icon and map-tile functions. */
#pragma opt_loop_invariants off
#pragma opt_propagation on

#include "mt_scene_internal.h"
#include "field_frame_internal.h"
#include "rw_geometry_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} FldIconProjection;

/* Interior symbols name columns within fixed-stride records. */
typedef struct FldIconPositionColumn { s32 coordinate; u8 pad04[4]; } FldIconPositionColumn;
typedef struct FldSmapSizeColumn { s32 extent; u8 pad04[4]; } FldSmapSizeColumn;
typedef struct FldSmapUvColumn { f32 coordinate; u8 pad04[12]; } FldSmapUvColumn;

extern void *memset(void *dst, s32 value, s32 size);
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
void FldSmapTileQueueQuad(u8 *, u8 *, s32, s32, s32,
                    s32, s32, f32, f32, f32);
extern s32 FldPlayerIconUpdate(u8 *);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern f32 sinf(f32);
extern u8 *resourceFindByName(char *);
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];
extern u8 *kwlnGetCamera(void);
extern void *mdlGetMatrix(void *);
extern void func_003e42a0(void *dst, void *src, u8 *);
extern u8 D_007EFA00[];
extern void sprintf(void *dst, const void *src);
extern s32 func_003ef6d0(void);
extern s32 func_003ef650(s32, void *);
extern void FldRc_QueueScreenQuad(u8 *, u8 *,
                           f32, f32, f32, f32, f32,
                           void *, s32,
                           f32, f32, f32,
                           s32, void *, f32);
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern s32 D_005F1930[];
extern s32 D_005F1934[];

/* The __FILE__ evidence groups 0x0017B510..0x0017CCC0 as one translation unit
   named k_shadow.c (tu_audit HIGH, score 5). That span and its helpers
   0x0017ACC0 and 0x0017B350 now live in src/Kosaka/k_shadow.c. The existing
   src/Kosaka/Field/k_shadow.c is a different, already-linked TU at
   0x001026B0 and is not merged with it. */

#include "rw_types_internal.h"
#include "sdktask.h"
/* Partial layout: field widths and offsets are established by the accesses below. */
typedef struct {
    s32 state;
    s32 active; /* +0x4 */
    union { s32 integer; u32 word; } texture; /* +0x8 */
    union { s16 shortValue; u16 halfword; } x; /* +0xC */
    union { s16 shortValue; u16 halfword; } y; /* +0xE */
    u16 frame; /* +0x10 */
} FldPlayerIconWork;

/* Initialize or draw the three player-icon sprites with a repeating fifteen-frame sine animation;
 * frame updates stay unsigned and the draws stay in order. */
// FUN_0017CD60
s32 FldPlayerIconUpdate(u8 *task)
{
    FldPlayerIconWork *iconWork;
    u8 *work;
    f32 easing;
    f32 inverse;
    f32 frame;
    s32 opacity;
    u16 counter;
    f32 x;
    f32 y;

    work = ((SdkTask *)task)->work;
    iconWork = (FldPlayerIconWork *)work;
    if (((FldPlayerIconWork *)work)->active == 0) {
        return 0;
    }
    switch (((FldPlayerIconWork *)work)->state) {
    case 0:
        ((FldPlayerIconWork *)work)->texture.integer = (s32)resourceFindByName(D_005E5850);
        ((FldPlayerIconWork *)work)->x.halfword = 320;
        ((FldPlayerIconWork *)work)->y.halfword = 240;
        ((FldPlayerIconWork *)work)->state = ((FldPlayerIconWork *)work)->state + 1;
        goto done;
    case 1:
        counter = ((FldPlayerIconWork *)work)->frame;
        frame = (f32)(u16)counter;
        easing = sinf((iGpffff82fc * frame) / 15.0f);
        inverse = 1.0f - easing;
        sdkSpriteDrawQueued((f32)(((FldPlayerIconWork *)work)->x.halfword + 10),
                      (f32)(((FldPlayerIconWork *)work)->y.halfword + 25), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC4, (void *)(((FldPlayerIconWork *)work)->texture.word),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        opacity = (s32)(128.0f * easing) + 0x80;
        x = (f32)(iconWork->x.halfword + 0x6E);
        y = (f32)(iconWork->y.halfword + 0x22);
        opacity = (0xFF < opacity) ? 0xFF : opacity;
        sdkSpriteDrawQueued(x, y, 1000.0f,
                      0xFFFFFF, opacity & 0xFF, 0xC6, (void *)(iconWork->texture.word),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued((f32)(iconWork->x.halfword + 0x6E),
                      (f32)(iconWork->y.halfword + 0xF +
                            (s32)(3.0f * inverse)), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC5, (void *)(iconWork->texture.word),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        counter = iconWork->frame + 1;
        iconWork->frame = counter;
        if (0xF < iconWork->frame) {
            iconWork->frame = 0;
        }
        goto done;
    case 2:
        return -1;
    default:
        goto done;
    }
done:
    return 0;
}

// FUN_0017D060
/* The player-icon task owns no separately released resources. */
void FldPlayerIconDestroy(u8 *task)
{
}

/* Clear the fixed player-icon work block and register its child task. */
// FUN_0017D070
s32 FldPlayerIconTaskCreate(u8 *task)
{
    memset(D_007F1740, 0, 0x20);
    return (s32)kwlnTaskCreateChild((void *)(task), (const void *)(D_005F1950), 0x12, 0, 0, FldPlayerIconUpdate, FldPlayerIconDestroy, (u8 *)(D_007F1740));
}

// FUN_0017D0F0
/* Enable or disable player-icon drawing in the task work block. */
void FldPlayerIconSetActive(u8 *task, s32 active)
{
    ((FldPlayerIconWork *)((SdkTask *)task)->work)->active = active;
}

/* X/Y symbols name separate columns of interleaved eight-byte position records. */
// FUN_0017D100
/* Project the player model and choose one of three fixed icon positions from its horizontal screen region. */
void FldPlayerIconUpdatePos(u8 *task)
{
    FldIconProjection projectedPosition;
    f32 screenX;
    s32 cameraMatrix;
    s32 positionOffset;
    s32 screenRegion;
    u8 *work;

    work = ((SdkTask *)task)->work;
    cameraMatrix = (s32)(kwlnGetCamera() + 0x20);
    func_003e42a0(&projectedPosition, (u8 *)mdlGetMatrix(*(u8 **)D_007EFA00) + 0x30, (u8 *)cameraMatrix);
    screenX = 640.0f * (projectedPosition.first / projectedPosition.second);
    if (screenX <= 100.0f) {
        screenRegion = 0;
    } else if (screenX < 540.0f) {
        screenRegion = 1;
    } else {
        screenRegion = 2;
    }
    positionOffset = screenRegion * 8;
    ((FldPlayerIconWork *)work)->x.shortValue = ((FldIconPositionColumn *)((u8 *)D_005F1930 + positionOffset))->coordinate;
    ((FldPlayerIconWork *)work)->y.shortValue = ((FldIconPositionColumn *)((u8 *)D_005F1934 + positionOffset))->coordinate;
}

/* The two size columns are separate interior symbols of the same eight-byte records. */
// FUN_0017D1F0
/* Read the tile dimensions for its type and queue a quad, including the one-pixel size expansion. */
void FldSmapTileQueueByType(u8 *queue, u8 *context, s32 tileType, s32 variant,
                   f32 x, f32 y, f32 depth, s32 flags)
{
    s32 sizeOffset;

    sizeOffset = tileType * 8;
    FldSmapTileQueueQuad(queue, context, tileType, variant,
                  ((FldSmapSizeColumn *)(D_005F1A60 + sizeOffset))->extent + 1,
                  ((FldSmapSizeColumn *)(D_005F1A64 + sizeOffset))->extent + 1, flags,
                  x, y, depth);
}

#pragma push
#pragma optimization_level 1
/* UV symbols are interior aliases of sixteen-byte tuples; the draw API also receives the first-component pointer. */
// FUN_0017D240
/* Resolve the variant texture name and queue a tile with the type-specific UV tuple. */
void FldSmapTileQueueQuad(u8 *queue, u8 *context, s32 tileType, s32 variant, s32 width,
                   s32 height, s32 flags, f32 x, f32 y, f32 depth)
{
    struct {
        u8 data[0x10];
        u8 tail[0x10];
    } textureName;
    u8 *drawQueue;
    u8 *drawContext;
    s32 drawType;
    s32 drawWidth;
    s32 drawHeight;
    s32 drawFlags;
    f32 drawX;
    f32 drawY;
    f32 drawDepth;
    f32 quadWidth = (f32)width;
    f32 quadHeight = (f32)height;
    f32 *uvData;
    s32 texture;
    s32 dictionary;
    s32 uvOffset;
    drawQueue = queue;
    drawContext = context;
    drawType = tileType;
    drawX = x;
    drawY = y;
    drawDepth = depth;
    drawWidth = width;
    drawHeight = height;
    drawFlags = flags;
    if (variant == 0) {
        sprintf(textureName.data, D_005F1AE0);
    } else {
        sprintf(textureName.data, D_005F1B00);
    }
    uvOffset = drawType * 0x10;
    quadWidth = (f32)drawWidth;
    quadHeight = (f32)drawHeight;
    dictionary = func_003ef6d0();
    texture = func_003ef650(dictionary, textureName.data);
    FldRc_QueueScreenQuad(drawQueue, drawContext,
                  drawX, drawY, drawDepth, quadWidth, quadHeight,
                  (void *)&iGpffff9f54, texture,
                  *(uvData = &((FldSmapUvColumn *)(D_005F1970 + uvOffset))->coordinate),
                  ((FldSmapUvColumn *)(D_005F1974 + uvOffset))->coordinate,
                  ((FldSmapUvColumn *)(D_005F1978 + uvOffset))->coordinate,
                  drawFlags, uvData,
                  ((FldSmapUvColumn *)(D_005F197C + uvOffset))->coordinate);
}
#pragma pop
