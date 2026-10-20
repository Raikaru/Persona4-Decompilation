/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0017cd60-0017d240 */

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
/* measured: best plain-C body is 108B in the 112B retail window (112B),
   normalized_diff 4; the sole residual bytes at offset 56 are retail
   `andi $a3,$s1,0xffff` versus candidate `move $a3,$s1`. The file-scope
   Encount_PickEncounter declaration remains (u16, u16, u16, s32) for matching
   FldUnit_SpawnEncounter. Probed a block-scope fourth-parameter u16 prototype at
   the function top, after locals, in an inner block, unnamed, and with
   explicit narrowed locals/casts: each moved the mask before the two lhu
   loads (nd 10); mixed third s32/fourth u16 gave nd 6. O1, schedule off,
   and function-pointer casts did not improve it. Best body remains archived
   at build/D178_00178870_body.c; committed form is bare INCLUDE_ASM. */

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

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
/* 764/768 bytes; fourteen resolved relocations; four zero alignment bytes.
 * Preserve unsigned frame updates and the three ordered sprite draws. */
// FUN_0017CD60
/* Measured: typed field access changed the retail instruction image; retain byte accesses at the documented work-layout offsets. */
/* Initialize or draw the three player-icon sprites with a repeating fifteen-frame sine animation. */
s32 FldPlayerIconUpdate(u8 *task)
{
    u8 *work;
    f32 easing;
    f32 inverse;
    f32 frame;
    s32 opacity;
    u16 counter;
    f32 x;
    f32 y;

    work = *(u8 **)(task + 0x38);
    if (*(s32 *)(work + 4) == 0) {
        return 0;
    }
    switch (*(s32 *)work) {
    case 0:
        *(s32 *)(work + 8) = (s32)resourceFindByName(D_005E5850);
        *(u16 *)(work + 0xC) = 320;
        *(u16 *)(work + 0xE) = 240;
        *(s32 *)work = *(s32 *)work + 1;
        goto done;
    case 1:
        counter = *(u16 *)(work + 0x10);
        frame = (f32)(u16)counter;
        easing = sinf((iGpffff82fc * frame) / 15.0f);
        inverse = 1.0f - easing;
        sdkSpriteDrawQueued((f32)(*(u16 *)(work + 0xC) + 10),
                      (f32)(*(u16 *)(work + 0xE) + 25), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC4, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        opacity = (s32)(128.0f * easing) + 0x80;
        x = (f32)(*(u16 *)(work + 0xC) + 0x6E);
        y = (f32)(*(u16 *)(work + 0xE) + 0x22);
        opacity = (0xFF < opacity) ? 0xFF : opacity;
        sdkSpriteDrawQueued(x, y, 1000.0f,
                      0xFFFFFF, opacity & 0xFF, 0xC6, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        sdkSpriteDrawQueued((f32)(*(u16 *)(work + 0xC) + 0x6E),
                      (f32)(*(u16 *)(work + 0xE) + 0xF +
                            (s32)(3.0f * inverse)), 1000.0f,
                      0xFFFFFF, 0xFF, 0xC5, (void *)(*(u32 *)(work + 8)),
                      1, 0, 0, 0.0f, 1.0f, 1.0f, D_00794E70);
        counter = *(u16 *)(work + 0x10) + 1;
        *(u16 *)(work + 0x10) = counter;
        if (0xF < *(u16 *)(work + 0x10)) {
            *(u16 *)(work + 0x10) = 0;
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
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D060
/* The player-icon task owns no separately released resources. */
void FldPlayerIconDestroy(u8 *task)
{
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D070
/* Clear the fixed player-icon work block and register its child task. */
s32 FldPlayerIconTaskCreate(u8 *task)
{
    memset(D_007F1740, 0, 0x20);
    return (s32)kwlnTaskCreateChild((void *)(task), (const void *)(D_005F1950), 0x12, 0, 0, FldPlayerIconUpdate, FldPlayerIconDestroy, (u8 *)(D_007F1740));
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D0F0
/* Enable or disable player-icon drawing in the task work block. */
void FldPlayerIconSetActive(u8 *task, s32 active)
{
    ((FldPlayerIconWork *)((SdkTask *)task)->work)->active = active;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D100
/* Project the player model and choose one of three fixed icon positions from its horizontal screen region. */
/* Raw access: The X/Y globals name separate components of interleaved 8-byte position records; retain each component symbol in the indexed loads. */
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
    ((FldPlayerIconWork *)work)->x.shortValue = *(s32 *)((u8 *)D_005F1930 + positionOffset);
    ((FldPlayerIconWork *)work)->y.shortValue = *(s32 *)((u8 *)D_005F1934 + positionOffset);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_0017D1F0
/* Read the tile dimensions for its type and queue a quad, including the one-pixel size expansion. */
/* Raw access: The size globals name separate components of interleaved 8-byte records; keep their distinct native relocation symbols. */
void FldSmapTileQueueByType(u8 *queue, u8 *context, s32 tileType, s32 variant,
                   f32 x, f32 y, f32 depth, s32 flags)
{
    s32 sizeOffset;

    sizeOffset = tileType * 8;
    FldSmapTileQueueQuad(queue, context, tileType, variant,
                  *(s32 *)(D_005F1A60 + sizeOffset) + 1,
                  *(s32 *)(D_005F1A64 + sizeOffset) + 1, flags,
                  x, y, depth);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants off
#pragma optimization_level 1
// FUN_0017D240
/* Resolve the variant texture name and queue a tile with the type-specific UV tuple. */
/* Raw access: The four UV globals are interior aliases of 16-byte tuples; the draw API also consumes the first-component pointer, so retain the component-relative addressing. */
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
                  *(f32 *)(uvData = (f32 *)(D_005F1970 + uvOffset)),
                  *(f32 *)(D_005F1974 + uvOffset),
                  *(f32 *)(D_005F1978 + uvOffset),
                  drawFlags, uvData,
                  *(f32 *)(D_005F197C + uvOffset));
}
#pragma pop
