#ifndef FCL_OBJECT_INTERNAL_H
#define FCL_OBJECT_INTERNAL_H

#include "type.h"
#include "fcl_draw_types.h"
#include "fcl_color.h"

/* Sprite object work. The task keeps this block at +0x38; the sprite routines
   take the block starting at +4, so spriteFlags is the first sprite halfword.
   Offsets are the measured ones; unnamed ranges are padding. */
typedef struct FclObject {
    u8 unk00[4];
    s16 spriteFlags;
    u8 unk06[0x2];
    f32 anchorValue;
    u8 pad0C[0x10];
    FclVec2 targetPosition;      /* +0x1C: slide destination */
    u8 pad24[8];
    FclVec2 anchorPosition;
    u8 pad34[2];
    s16 positionDuration;
    u8 pad38[3];
    s8 mode;
    u8 unk3C[0x20];
    u8 pad5C[2];
    s16 alphaDuration;
    u8 targetAlpha;
    u8 pad61;
    u8 alpha;
    u8 unk63[0x16];
    FclDrawColor color;
    u8 unk7D[0x8];
    s8 colorLoop;
    u8 pad86[2];
    s16 revealDuration;
    u8 pad8A[2];
    f32 targetScale;
    u8 pad90[4];
    f32 scaleX;
    u8 unk98[0x8];
    f32 scale;
    u8 padA4[0x18];
    f32 targetTween;
    u8 padC0[4];
    f32 tweenValue;
    s16 tweenDuration;
    u8 padCA[5];
    u8 tweenLoop;
    u8 unkD0[0x1C];
    f32 holdTimer;
    s16 holdFrames;
    s16 holdLimit;
    u32 spriteResource;
    s16 anchorIndex;
    u8 unkFA[0x2];
    s32 anchorMode;
} FclObject;

static inline FclObject *fclObjWork(u8 *task)
{
    return *(FclObject **)(task + 0x38);
}

static inline u8 *fclObjSprite(u8 *task)
{
    return (u8 *)fclObjWork(task) + 4;
}

#endif
