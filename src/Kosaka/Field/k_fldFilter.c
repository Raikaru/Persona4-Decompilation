/* Source unit: src/Kosaka/Field/k_fldFilter.c */
#include "type.h"

/* Filter controller small-BSS block (P3 donor names sFilterFile /
 * sFilterCurrent / sFilterBlendDuration / sFilterBlend / sFilterPrevious). */
extern void* D_007643A0;
extern s32 D_007643A8;
extern s32 D_007643AC;
extern f32 D_007643B0;
extern f32 D_007643B4;



// FUN_00161460
void FUN_00161460(s32 index, u32 type, s32 duration)
{
    if (duration == 0)
    {
        D_007643B0 = 1.0f;
        D_007643AC = index;
        D_007643B4 = 1.0f;
    }
    else
    {
        D_007643B0 = 0.0f;
        D_007643AC = D_007643A8;
        D_007643B4 = (f32)duration;
    }
    D_007643A8 = index;
    *(u32*)((u8*)D_007643A0 + index * 0x124) = type;
}
