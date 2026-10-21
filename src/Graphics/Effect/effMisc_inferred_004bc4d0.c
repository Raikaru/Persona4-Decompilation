#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"
#include "effect_mesh_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);


extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;

/* The six framed tail-jump wrappers func_004bd628 through func_004bd6a0 stay in assembly; plain C
 * cannot emit that ABI shape. */


extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *progress, s32 input);
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void *(*jtbl_008873E8[])(u32 progress, u32 input);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

typedef struct {
    s32 centerXBits;
    s32 centerYBits;
    s32 centerZBits;
    f32 radius;
} EffMiscBounds;

/* Reset traverses the native twelve-byte XYZ vertex as integer bit patterns. */
typedef struct EffMiscVertex {
    s32 xBits, yBits, zBits;
} EffMiscVertex;
#pragma push
#pragma pop
#pragma push
#pragma pop
typedef struct EffMiscProgressSource {
    u8 pad0[4];
    u8 *colorTable;
    u8 pad8[4];
    s32 segmentCount;
} EffMiscProgressSource;

/* Progress state: offsets are shared by start/reset/advance and color fading. */
typedef struct EffMiscProgress {
    u8 *source;
    s32 flags;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x18];
    s32 unk28;
    union {
        f32 elapsed;
        s32 elapsedBits;
    };
    f32 start;
    f32 duration;
    s16 kind;
} EffMiscProgress;

/* Start the fade at the current elapsed value; bit zero enables fading. */
// FUN_004BC4D0
void effMiscProgressStart(u8 *progress, f32 duration)
{
    ((EffMiscProgress *)progress)->unk28 = 0;
    ((EffMiscProgress *)progress)->start = ((EffMiscProgress *)progress)->elapsed;
    ((EffMiscProgress *)progress)->duration = duration;
    ((EffMiscProgress *)progress)->flags |= 1;
}

/* Clear fade flags, elapsed bits and both work selectors. */
// FUN_004BC500
void effMiscProgressReset(u8 *progress)
{
    ((EffMiscProgress *)progress)->flags = 0;
    /* Reset the elapsed float through its original integer bit store. */
    ((EffMiscProgress *)progress)->elapsedBits = 0;
    ((EffMiscProgress *)progress)->unk8 = 0;
    ((EffMiscProgress *)progress)->unkC = 0;
}

// FUN_004BC520
void effMiscProgressAdvance(u8 *progress, f32 *elapsedStep)
{
    ((EffMiscProgress *)progress)->elapsed += *elapsedStep;
}

/* measured: retail shifts keyIndex before the color table loads, which copy propagation would
 * reorder. Interpolates two byte colors, optionally attenuated by the remaining fade. */
// FUN_004BC540
/* measured: retail code generation needs copy propagation disabled for this function's color loads. */
#pragma opt_propagation off
void effMiscProgressBlendColor(u8 *progress, s32 keyIndex, f32 secondWeight, u8 *output)
{
    u8 *colorPair;
    struct {
        u8 *firstColor;
        u8 *secondColor;
    } stack;
    u8 *clearCursor;
    s32 bytesRemaining;
    f32 firstWeight;
    f32 fade;
    f32 channel;
    f32 duration;

    clearCursor = (u8 *)&stack;
    bytesRemaining = 8;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor++;
            bytesRemaining--;
        } while (bytesRemaining != 0);
    }
    keyIndex = keyIndex << 3;
    /* Each color key occupies two adjacent four-byte RGBA entries. */
    colorPair = ((EffMiscProgressSource *)((EffMiscProgress *)progress)->source)->colorTable + keyIndex;
    stack.firstColor = colorPair + 8;
    stack.secondColor = colorPair + 0xC;
    firstWeight = 1.0f - secondWeight;

    if (((EffMiscProgress *)progress)->flags & 1) {
        duration = ((EffMiscProgress *)progress)->duration;
        if (duration > 0.0f) {
            fade = 1.0f - ((((EffMiscProgress *)progress)->elapsed - ((EffMiscProgress *)progress)->start) / duration);
            if (fade < 0.0f) {
                fade = 0.0f;
            }
        } else if (duration == 0.0f) {
            if (((EffMiscProgress *)progress)->elapsed < ((EffMiscProgress *)progress)->start) {
                goto set_one;
            }
            fade = 0.0f;
            goto set_progress;
        set_one:
            fade = 1.0f;
        set_progress:
            ;
        }
        channel = fade * (secondWeight * (f32)stack.secondColor[0] + firstWeight * (f32)stack.firstColor[0]);
        output[0] = (u8)channel;
        channel = fade * (secondWeight * (f32)stack.secondColor[1] + firstWeight * (f32)stack.firstColor[1]);
        output[1] = (u8)channel;
        channel = fade * (secondWeight * (f32)stack.secondColor[2] + firstWeight * (f32)stack.firstColor[2]);
        output[2] = (u8)channel;
        channel = fade * (secondWeight * (f32)stack.secondColor[3] + firstWeight * (f32)stack.firstColor[3]);
        output[3] = (u8)channel;
        return;
    }
    channel = secondWeight * (f32)stack.secondColor[0] + firstWeight * (f32)stack.firstColor[0];
    output[0] = (u8)channel;
    channel = secondWeight * (f32)stack.secondColor[1] + firstWeight * (f32)stack.firstColor[1];
    output[1] = (u8)channel;
    channel = secondWeight * (f32)stack.secondColor[2] + firstWeight * (f32)stack.firstColor[2];
    output[2] = (u8)channel;
    channel = secondWeight * (f32)stack.secondColor[3] + firstWeight * (f32)stack.firstColor[3];
    output[3] = (u8)channel;
}

/* Clears geometry colors and positions in separate passes, then resets the bounds; kind selects the
 * generated vertex count. */
// FUN_004BCCF0
void effMiscProgressResetWork(u8 *progress, u8 *geometry, u8 *unusedSource, s32 vertexCount)
{
    EffMiscBounds bounds;
    s16 kind;
    u8 *positionCursor;
    s32 colorIndex;
    s32 workCount;
    u8 *morphTarget;
    u8 *colorCursor;
    s32 positionIndex;
    RpGeometry *mesh = (RpGeometry *)geometry;
    EffMiscVertex *vertex;

    workCount = vertexCount;
    kind = ((EffMiscProgress *)progress)->kind;
    switch (kind) {
    case 0:
        workCount = (((EffMiscProgressSource *)((EffMiscProgress *)progress)->source)->segmentCount * 2) + 1;
        break;
    case 1:
        workCount = (((EffMiscProgressSource *)((EffMiscProgress *)progress)->source)->segmentCount * 3) + 6;
        break;
    case 2:
        workCount = (((EffMiscProgressSource *)((EffMiscProgress *)progress)->source)->segmentCount * 3) + 6;
        break;
    }
    colorCursor = (u8 *)mesh->colors;
    colorIndex = 0;
    while (colorIndex < workCount) {
        colorCursor[0] = 0;
        colorCursor[1] = 0;
        colorCursor[2] = 0;
        colorCursor[3] = 0;
        colorIndex += 1;
        colorCursor += 4;
    }
    positionCursor = (u8 *)mesh->morphTarget->vertices;
    vertex = (EffMiscVertex *)positionCursor;
    positionIndex = 0;
    while (positionIndex < workCount) {
        vertex->xBits = 0;
        vertex->yBits = 0;
        vertex->zBits = 0;
        positionIndex += 1;
        positionCursor += 0xC;
        vertex = (EffMiscVertex *)positionCursor;
    }
    bounds.centerXBits = 0;
    bounds.centerYBits = 0;
    bounds.centerZBits = 0;
    bounds.radius = (f32)1000000000;
    morphTarget = (u8 *)mesh->morphTarget;
    /* Bounding-sphere XYZ are cleared with the original integer bit stores. */
    ((EffMiscBounds *)((RpMorphTarget *)morphTarget)->boundingSphere)[0] = bounds;
}

