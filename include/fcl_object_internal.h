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
    u8 unk0C[0x20];
    FclVec2 anchorPosition;
    u8 unk34[0x7];
    s8 mode;
    u8 unk3C[0x20];
    u8 unk5C[0x6];
    u8 alpha;
    u8 unk63[0x16];
    FclDrawColor color;
    u8 unk7D[0x8];
    s8 colorLoop;
    u8 unk86[0xE];
    f32 scaleX;
    u8 unk98[0x8];
    f32 scale;
    u8 unkA4[0x20];
    f32 tweenValue;
    u8 unkC8[0x7];
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
