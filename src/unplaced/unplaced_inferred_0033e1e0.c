/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0033e1e0-0033e5a0 */

#include "fcl_object_internal.h"
#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "shd_misc_internal.h"
#include "fcl_combine_internal.h"
extern void (*jtbl_008873EC[])(void *);
extern void sdkSpriteRelease(void *ptr);
typedef FclVec2 F2_0033;

extern void chkmemAllocSiteTag(const void *arg0, s32 arg1);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 sdkSpriteRequestLoad(void *arg0);
extern u8 D_0064A458[];
extern u8 D_0064A470[];
extern u8 D_0064A480[];
extern s32 fclBustupUpdate(u8 *arg0);
extern void fclBustupDraw(u8 *arg0);
extern s32 fclPackRgba(u8, u8, u8, u8);
extern f32 fclEaseInterpolate(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 fclAddClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s16 fclSubClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s32 func_0046a750(s32 arg0, s32 arg1);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 D_007955C0[];
#pragma push
#pragma opt_propagation on
// FUN_0033E1E0
s32 fclBustupUpdate(u8 *arg0)
{
    u8 *p;
    s16 value;

    p = *(u8 **)(arg0 + 0x38);
    switch (*(s8 *)p) {
    case 0:
        if (func_0046a750(*(s32 *)(p + 4), 3) == 0) {
            return 0;
        }
        *(s8 *)p = 1;
        break;
    case 1:
        break;
    default:
        break;
    case 2:
        if (*(s16 *)(p + 0x24) > *(s16 *)(p + 0x26)) {
            goto update;
        }
        *(s8 *)p = 3;
        if (*(f32 *)(p + 0x1C) >= 640.0f) {
            *(s8 *)p = 1;
            return 0;
        }
    update:
        *(f32 *)(p + 0x1C) = fclEaseInterpolate(
            *(s8 *)(p + 0x2A), *(f32 *)(p + 0x0C), *(f32 *)(p + 0x14),
            (f32)*(s16 *)(p + 0x26), (f32)*(s16 *)(p + 0x24));
        *(f32 *)(p + 0x20) = fclEaseInterpolate(
            *(s8 *)(p + 0x2A), *(f32 *)(p + 0x10), *(f32 *)(p + 0x18),
            (f32)*(s16 *)(p + 0x26), (f32)*(s16 *)(p + 0x24));
        value = *(s16 *)(p + 0x28);
        if (value > 0) {
            *(s16 *)(p + 0x28) = fclSubClamped(value, 1, 0, 0, 1);
        } else {
            *(s16 *)(p + 0x26) = fclAddClamped(
                *(s16 *)(p + 0x26), 1, *(s16 *)(p + 0x24), 0, 1);
        }
        fclBustupDraw(arg0);
        break;
    case 3:
        fclBustupDraw(arg0);
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0033E3A0
void fclBustupDestroy(u8 *arg0)
{
    sdkSpriteRelease((void *)*(u8 **)(*(u8 **)(arg0 + 0x38) + 4));
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0033E3F0
s32 fclBustupCreate(u8 *arg0)
{
    s32 result;
    u8 *work;

    chkmemAllocSiteTag(D_0064A458, 0x85);
    work = D_008873F4[0](1, 0x2C, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(D_0064A470), 0xF, 0, 0, fclBustupUpdate, fclBustupDestroy, (u8 *)(work));
    work[0] = 0;
    *(s32 *)(work + 4) = sdkSpriteRequestLoad(D_0064A480);
    return result;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0033E4B0
void fclBustupDraw(u8 *arg0)
{
    u8 *work;
    s32 color;
    f32 x;
    f32 y;

    work = *(u8 **)(arg0 + 0x38);
    color = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
    x = *(f32 *)(work + 0x1C);
    y = *(f32 *)(work + 0x20);
    sdkSpriteDrawQueued(x, y, 104.0f, color, 0xFF, 1, *(void **)(work + 4),
                  1, 0, 0, 0.0f, 1.0f, 1.0f, D_007955C0);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0033E540
void fclCombineStartMove(u8 *arg0, F2_0033 arg1, F2_0033 arg2, s16 arg3, s16 arg4)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(F2_0033 *)(work + 0x1C) = arg1;
    *(F2_0033 *)(work + 0x0C) = *(F2_0033 *)(work + 0x1C);
    *(F2_0033 *)(work + 0x14) = arg2;
    *(s16 *)(work + 0x24) = arg3;
    *(s16 *)(work + 0x26) = 0;
    *(s16 *)(work + 0x28) = arg4;
    *(s8 *)work = 2;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0033E5A0
s32 fclBustupIsActive(u8 *arg0)
{
    return *(s8 *)(*(u8 **)(arg0 + 0x38)) != 0;
}
#pragma pop
