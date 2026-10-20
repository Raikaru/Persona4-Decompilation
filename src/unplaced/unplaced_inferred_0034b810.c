/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0034b810-0034b950 */

#include "nline_vertex_internal.h"
#include "include_asm.h"
#include "fcl_combine_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "kwln_task_internal.h"
#include "fcl_color.h"

/* Setter-owned fields in the combine sprite task's work allocation. */
typedef struct FclCombineSpriteWork {
    s16 image;
    u8 pad2[0xE0E];
    s16 flags;
    u8 padE12[2];
    f32 scale;
    u8 padE18[0x20];
    FclVec2 position;
    u8 padE40[0x28];
    s16 alphaDuration;
    s16 alphaElapsed;
    u8 alphaStart;
    u8 alphaEnd;
    u8 alpha;
    u8 padE6F;
    s16 alphaDelay;
    u8 alphaMode;
    u8 padE73[0x12];
    u8 red, green, blue;
} FclCombineSpriteWork;
extern void nLineDrawCurrent();
void nLineUpdate();
void PrimAppendNode(u8 *list, u8 *node);
extern u8 D_00793E80[];
extern s32 D_00882FC0[];
extern s32 D_00882FC4[];
extern s32 D_00884670[];
extern s32 D_00884684[];
extern u16 iGpffffb5a4;
extern u8 D_00793E80[];

// Intent: Return the combine object's work block pointer, the same body as fclCombineGetWork [inferred]
// FUN_0034B810
s32 fclCombineGetWorkAlt(u8 *task)
{
    return (s32)((KwlnTask *)task)->work;
}

// Intent: Set the combine sprite's position, sprite id, colour and scale, and flag the sprite as changed [inferred]
// FUN_0034B820
void fclCombineSetSprite(u8 *task, FclVec2 position, s16 image, FclDrawColor color, f32 scale)
{
    u8 *work = ((KwlnTask *)task)->work;
    ((FclCombineSpriteWork *)work)->position = position;
    ((FclCombineSpriteWork *)work)->scale = scale;
    ((FclCombineSpriteWork *)work)->image = image;
    ((FclCombineSpriteWork *)work)->alpha = color.c3;
    ((FclCombineSpriteWork *)work)->red = color.c0;
    ((FclCombineSpriteWork *)work)->green = color.c1;
    ((FclCombineSpriteWork *)work)->blue = color.c2;
    ((FclCombineSpriteWork *)work)->flags |= 1;
}

// Intent: Set the combine's tint bytes and timing and flag the tint as changed [inferred]
// FUN_0034B880
void fclCombineSetTint(u8 *task, u8 startAlpha, u8 endAlpha, u8 mode, s16 duration, s16 delay)
{
    u8 *work;

    work = ((KwlnTask *)task)->work;
    ((FclCombineSpriteWork *)work)->alphaStart = startAlpha;
    ((FclCombineSpriteWork *)work)->alphaEnd = endAlpha;
    ((FclCombineSpriteWork *)work)->alpha = startAlpha;
    ((FclCombineSpriteWork *)work)->alphaElapsed = 0;
    ((FclCombineSpriteWork *)work)->alphaDuration = duration;
    ((FclCombineSpriteWork *)work)->alphaDelay = delay;
    ((FclCombineSpriteWork *)work)->alphaMode = mode;
    ((FclCombineSpriteWork *)work)->flags |= 4;
}

// FUN_0034B8C0
void fclCombineSpriteNoop(void)
{
}

// Intent: Refresh the nLine task: when both state flags are set, run the nLine setup and reset its counters [inferred]
// FUN_0034B8D0
s32 nLineRefreshTask(u8 *unusedTask)
{
    if ((D_00884684[0] != 0) && (D_00884670[0] != 0)) {
        nLineUpdate();
        D_00882FC0[0] = 0;
        D_00882FC4[0] = 0;
        PrimAppendNode(D_00793E80 + iGpffffb5a4 * 0x30, (u8 *)D_00882FC0);
    }
    return 0;
}

// Intent: Registered nLine callback that draws the layer at the origin [inferred]
// FUN_0034B950
void nLineDrawOriginCallback(void)
{
    nLineDrawCurrent();
}
