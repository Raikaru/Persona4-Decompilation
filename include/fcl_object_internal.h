#ifndef FCL_OBJECT_INTERNAL_H
#define FCL_OBJECT_INTERNAL_H

#include "type.h"
#include "fcl_draw_types.h"

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
    u8 unk34[0x28];
    u8 unk5C[0x6];
    u8 alpha;
    u8 unk63[0x3D];
    f32 scale;
    u8 unkA4[0x48];
    f32 holdTimer;
    s16 holdFrames;
    s16 holdLimit;
    u8 unkF4[0x4];
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
