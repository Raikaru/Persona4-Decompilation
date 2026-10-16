/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0025e9e0-0025ecd0 */

#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
extern void sdkSpriteDraw(u8 *arg0, s32 arg1);
extern void sdkSpriteFreeNode(void *arg0);
extern u8 *sdkSpriteNewNode(u32 arg0, u32 arg1);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(u8 *arg0, u8 *arg1);
extern void sdkSpriteDrawAndFreeFlag1(s32 arg0, u8 *arg1);
extern void sdkSpriteDrawAndFreeFlag0(s32 arg0, u8 *arg1);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
#pragma push
#pragma opt_propagation on
// Intent: Draws a sprite node at unit scale with no size offset (wrapper of sdkSpriteDrawNow) [inferred]
// FUN_0025E9E0
void sdkSpriteDrawNowUnscaled(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4) {
    sdkSpriteDrawNow(farg0, farg1, farg2, arg0, arg1, arg2, arg3, arg4, 0, 0, 0.0f, 1.0f, 1.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* measured: plain `(u16)(4096.0f * farg4)` and `(u16)(4096.0f * farg5)` casts reproduce both compiler-generated float-to-unsigned conversion paths; MATCH object 484B/window 496B. Each retail site begins `lui 0x4580; mtc1; mul.s; lui 0x4F00; mtc1; c.ole.s`, then uses low `cvt.w.s; mfc1; andi` or high `sub.s; cvt.w.s; mfc1; lui 0x8000; or; andi` before `sh`. The `or` is after `mfc1`, and the 4096.0f `mul.s` is genuine scaling. */
// Intent: Creates a sprite node at a position with alpha, colour, texture and scale, and draws it when both scales are nonzero [inferred]
// FUN_0025EA20
s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5) {
    u8 *temp_2;

    temp_2 = sdkSpriteNewNode((u32)arg3, arg2);
    *(f32 *)(temp_2 + 8) = farg0;
    *(f32 *)(temp_2 + 0xC) = farg1;
    *(f32 *)(temp_2 + 0x24) = farg2;
    *(s8 *)(temp_2 + 0x11) = (s8)(0xFF - arg1);
    *(s8 *)(temp_2 + 0x28) = (s8)((u32)arg0 >> 0x10);
    *(s8 *)(temp_2 + 0x29) = (s8)((u32)arg0 >> 8);
    *(u8 *)(temp_2 + 0x2A) = (u8)arg0;
    *(s16 *)(temp_2 + 0x1C) = (s16)arg5;
    *(s16 *)(temp_2 + 0x1E) = (s16)arg6;
    *(f32 *)(temp_2 + 0x18) = farg3;
    *(u16 *)(temp_2 + 0x20) = (u16)(4096.0f * farg4);
    *(u16 *)(temp_2 + 0x22) = (u16)(4096.0f * farg5);
    if ((*(u16 *)(temp_2 + 0x20) != 0) &&
        (*(u16 *)(temp_2 + 0x22) != 0)) {
        sdkSpriteDraw(temp_2, arg4);
    }
    sdkSpriteFreeNode(temp_2);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* measured: plain `(u16)(4096.0f * farg4)` and `(u16)(4096.0f * farg5)` casts reproduce both compiler-generated float-to-unsigned conversion paths; MATCH object 588B/window 592B. Each retail site begins `lui 0x4580; mtc1; mul.s; lui 0x4F00; mtc1; c.ole.s`, then uses low `cvt.w.s; mfc1; andi` or high `sub.s; cvt.w.s; mfc1; lui 0x8000; or; andi` before `sh`. The `or` is after `mfc1`, and the 4096.0f `mul.s` is genuine scaling. */
// Intent: Creates a sprite node like sdkSpriteDrawNow but queues its draw as a task callback; arg4 == 1 selects the flag-1 callback [inferred]
// FUN_0025ECD0
s32 sdkSpriteDrawQueued(f32 farg0, f32 farg1, f32 farg2,
                  s32 arg0, u8 arg1, s32 arg2, void *arg3,
                  s32 arg4, s16 arg5, s16 arg6,
                  f32 farg3, f32 farg4, f32 farg5, void *arg7) {
    u8 *temp_16;
    u8 *temp_2;

    temp_16 = PrimAllocQueueNode();
    temp_2 = sdkSpriteNewNode((u32)arg3, arg2);
    *(f32 *)(temp_2 + 8) = farg0;
    *(f32 *)(temp_2 + 0xC) = farg1;
    *(f32 *)(temp_2 + 0x24) = farg2;
    *(s8 *)(temp_2 + 0x11) = (s8)(0xFF - arg1);
    *(s8 *)(temp_2 + 0x28) = (s8)((u32)arg0 >> 0x10);
    *(s8 *)(temp_2 + 0x29) = (s8)((u32)arg0 >> 8);
    *(u8 *)(temp_2 + 0x2A) = arg0;
    *(s16 *)(temp_2 + 0x1C) = arg5;
    *(s16 *)(temp_2 + 0x1E) = arg6;
    *(f32 *)(temp_2 + 0x18) = farg3;
    *(u16 *)(temp_2 + 0x20) = (u16)(4096.0f * farg4);
    *(u16 *)(temp_2 + 0x22) = (u16)(4096.0f * farg5);
    if (*(u16 *)(temp_2 + 0x20) == 0) {
        goto cleanup;
    }
    if (*(u16 *)(temp_2 + 0x22) == 0) {
        goto cleanup;
    }
    if (arg4 != 1) {
        goto callback_2;
    }
    *(void **)(temp_16 + 8) = (void *)sdkSpriteDrawAndFreeFlag1;
    *(u8 **)(temp_16 + 0x10) = temp_2;
    goto callback_call;
callback_2:
    *(void **)(temp_16 + 8) = (void *)sdkSpriteDrawAndFreeFlag0;
    *(u8 **)(temp_16 + 0x10) = temp_2;
callback_call:
    PrimAppendNode(arg7, temp_16);
    goto done;
cleanup:
    sdkSpriteFreeNode(temp_2);
done:
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Queued draw callback: draws the sprite node with flag 1, then frees it [inferred]
// FUN_0025EC10
void sdkSpriteDrawAndFreeFlag1(s32 arg0, u8 *arg1) {
    sdkSpriteDraw(arg1, 1);
    sdkSpriteFreeNode(arg1);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Queued draw callback: draws the sprite node with flag 0, then frees it [inferred]
// FUN_0025EC50
void sdkSpriteDrawAndFreeFlag0(s32 arg0, u8 *arg1) {
    sdkSpriteDraw(arg1, 0);
    sdkSpriteFreeNode(arg1);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Queued unit-scale sprite draw (wrapper of sdkSpriteDrawQueued) [inferred]
// FUN_0025EC90
void sdkSpriteDrawQueuedUnscaled(f32 farg0, f32 farg1, f32 farg2,
                   s32 arg0, u8 arg1, s32 arg2, void *arg3, s32 arg4, void *arg5) {
    sdkSpriteDrawQueued(farg0, farg1, farg2, arg0, arg1, arg2, arg3, arg4,
                  0, 0, 0.0f, 1.0f, 1.0f, arg5);
}
#pragma pop
