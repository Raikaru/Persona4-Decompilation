/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/Event/Fcl/y_fclShopDraw.c); members 002e04e0-002e0da0 */

#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "fcl_bounds_packet.h"
#include "fcl_draw_task.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "fr_font_internal.h"
#include "fcl_object_internal.h"
#include "datPersona_internal.h"
typedef FclVec2 f2;

typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} u4;

extern void fclSpriteStartPosition(u8 *arg0, f2 p1, f2 p2, u32 arg3, s32 arg4, s32 arg5);
extern u8 *iGpffffb588;
extern u8 *func_002e1db0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 fclBankQueueRequest();
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern s32 resourceFindByName(const void *arg0);
extern u8 D_0063FB50[];
extern u8 D_0063FAA0[];
extern u8 D_0063FB90[];
extern u8 D_0063F560[];
// FUN_002E04E0
u8 *fclObjectGetWork(u8 *arg0)
{
    return *(u8 **)(arg0 + 0x38);
}

// FUN_002E04F0
void fclObjChangeFlagBit(u8 *arg0, u32 arg1, s8 arg2) {
    u8 *base = *(u8 **)(arg0 + 0x38);
    if (arg2 == 0) {
        *(s16 *)(base + 4) |= (s16)((1 << (arg1 & 0xffff)) & 0xffff);
        return;
    }
    if (arg2 == 1) {
        *(s16 *)(base + 4) &= (s16)((1 << (arg1 & 0xffff)) ^ 0xffff);
        return;
    }
}

// FUN_002E0570
s8 fclObjTestFlagBit(u8 *arg0, s32 arg1)
{
    s16 flags;

    flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 4);
    return (s8)((flags & ((1 << (arg1 & 0xFFFF)) & 0xFFFF)) >> (arg1 & 0xFFFF));
}

// FUN_002E05A0
s8 fclObjHasStatusFlags(u8 *arg0) {
    s16 flags = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x4);
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

// FUN_002E0620
void fclObjStartPosition(u8 *arg0, f2 p1, f2 p2, u32 arg3, u32 arg4, s16 arg5) {
    fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4, p1, p2, arg3, arg4, arg5);
}

// FUN_002E0660
void fclObjStartAlpha(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, s16 arg5)
{
    fclSpriteStartAlpha(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, (s16)arg5);
}

// FUN_002E0690
/* Parameter order taken from the caller at fclShopSlideInFromRight in
   src/Event/Fcl/y_fclShopDraw.c: b210 emits argument setup in source order, and
   retail emits `mov.s $f13, $f12` between `lw $a0` and `move $a1`, which only
   happens when the two floats are arguments 2 and 3.  The EABI assigns integer
   and float arguments to their own register files, so this order compiles to
   the same object as the ints-first spelling (measured: identical bytes). */
void fclObjStartUniformRevealScale(u8 *arg0, f32 fparg0, f32 fparg1, u32 arg1, u32 arg2, s64 arg3)
{
    fclSpriteStartRevealScale(fclObjSprite(arg0), fparg0, fparg1, fparg0, fparg1, arg1, arg2, (s16)arg3);
}

// FUN_002E06D0
void fclObjStartRevealScale(u8 *arg0, f32 scale0, f32 scale1, f32 scale2, f32 scale3, u32 arg1, u32 arg2, s64 arg3)
{
    fclSpriteStartRevealScale(fclObjSprite(arg0), scale0, scale1, scale2, scale3, arg1, arg2, (s16)arg3);
}

#pragma push
#pragma opt_propagation off
// FUN_002E0700
void fclObjStartSlideFade(u8 *arg0, s64 arg1, f32 fparg0, f32 fparg1,
                   s32 arg2, s32 arg3, s64 arg4)
{
    f2 pos;
    f2 out1;
    f2 out2;
    f2 draw1;
    f2 draw2;
    f32 out1_x;
    f32 out1_y;
    f32 out2_x;
    f32 out2_y;
    f32 pos_x;
    f32 pos_y;
    u8 *handle;
    u8 *temp;
    extern u8 *sdkSpriteNewNode(u32 arg0, u32 arg1);
    extern f32 sdkSpriteScaledHeight(u8 *arg0);
    u8 *base;
    extern void sdkSpriteFreeNode(void *node);
    temp = *(u8 **)(arg0 + 0x38);
    pos_x = *(f32 *)(temp + 0x2C);
    pos_y = *(f32 *)(temp + 0x30);
    pos.x = pos_x;
    pos.y = pos_y;
    if ((s8)arg4 == 1) {
        handle = sdkSpriteNewNode(*(u32 *)(temp + 0xF4), (s16)arg1);
        out1 = fclMakeVec2(pos.x,
                             pos.y - (sdkSpriteScaledHeight(handle) / 2.0f));
        out1_x = out1.x;
        out1_y = out1.y;
        draw1.x = out1_x;
        draw1.y = out1_y;
        arg3 = (s16)arg3;
        fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4, pos, draw1, 0, arg2,
                       arg3);
        sdkSpriteFreeNode(handle);
        fclSpriteStartAlpha(*(u8 **)(arg0 + 0x38) + 4, 0, 0xFF, 0, arg2, arg3);
    } else {
        handle = sdkSpriteNewNode(*(u32 *)(temp + 0xF4), (s16)arg1);
        out2 = fclMakeVec2(pos.x,
                             pos.y + (sdkSpriteScaledHeight(handle) / 2.0f));
        out2_x = out2.x;
        out2_y = out2.y;
        draw2.x = out2_x;
        draw2.y = out2_y;
        arg3 = (s16)arg3;
        fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4, pos, draw2, 0, arg2,
                       arg3);
        sdkSpriteFreeNode(handle);
        fclSpriteStartAlpha(*(u8 **)(arg0 + 0x38) + 4, 0xFF, 0, 0, 0,
                       (s16)((s32)arg3 + arg2));
    }
    base = *(u8 **)(arg0 + 0x38);
    fclSpriteStartRevealScale(base + 4, 1.0f, 1.0f, fparg0, fparg1, 0, arg2, arg3);
}
#pragma pop

// FUN_002E0940
void fclObjStartTween(u8 *arg0, f32 first, f32 second, u8 mode, s32 duration, s64 delay)
{
    fclSpriteStartTween(*(u8 **)(arg0 + 0x38) + 4, mode, duration, delay, first, second);
}

// FUN_002E0970
void fclObjStartColor(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s64 arg5)
{
    extern void fclSpriteStartColor(u8 *arg0, u4 arg1, u4 arg2, u8 arg3, s16 arg4, s16 arg5);
    fclSpriteStartColor(fclObjSprite(arg0), arg1, arg2, arg3, arg4, arg5);
}

// FUN_002E09B0
void fclObjSetHoldTimer(u8 *arg0, f32 fparg0, s16 arg1)
{
    FclObject *obj = fclObjWork(arg0);
    s16 flags = obj->spriteFlags;
    obj->spriteFlags = flags | 0x80;
    obj->holdFrames = 0;
    obj->holdTimer = fparg0;
    obj->holdLimit = arg1;
}

// FUN_002E09E0
void fclObjSetAnchorPosition(u8 *arg0, s32 arg1, f32 fparg0) {
    FclObject *work = fclObjWork(arg0);
    f32 *entry = (f32 *)(D_0063F560 + work->anchorIndex * 8);
    f2 out;
    work->spriteFlags |= 1;
    fclObjWork(arg0)->anchorValue = fparg0;
    fclObjWork(arg0)->anchorMode = arg1;
    work = fclObjWork(arg0);
    out = fclMakeVec2(entry[0], entry[1]);
    work->anchorPosition = out;
}

// FUN_002E0A60
void fclObjSetAnchorAlphaFull(u8 *arg0, s32 arg1, f32 fparg0)
{
    FclObject *work;
    u8 *entry;
    f2 out;

    work = fclObjWork(arg0);
    entry = D_0063F560 + work->anchorIndex * 8;
    work->spriteFlags |= 1;
    fclObjWork(arg0)->anchorValue = fparg0;
    fclObjWork(arg0)->anchorMode = arg1;
    work = fclObjWork(arg0);
    out = fclMakeVec2(*(f32 *)entry, *(f32 *)(entry + 4));
    work->anchorPosition = out;
    work = fclObjWork(arg0);
    work->alpha = 0xFF;
    work = fclObjWork(arg0);
    *(s32 *)&work->scale = 0x3F800000;
    *(s32 *)((u8 *)work + 0x94) = 0x3F800000;
    work = fclObjWork(arg0);
    *(s8 *)((u8 *)work + 0xCF) = 0;
    *(s8 *)((u8 *)work + 0xA7) = 0;
    *(s8 *)((u8 *)work + 0x67) = 0;
    work->mode = 0;
}

// FUN_002E0B20
void fclDrawEquipSprite(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, u8 arg3,
                   s32 arg4, u8 *arg5)
{
    sdkSpriteDrawQueued(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF, (void *)(u32)resourceFindByName(D_0063FB50), arg4, 0, 0, 0.0f, 1.0f, 1.0f, arg5);
}

// FUN_002E0BE0
void fclDrawResourceSprite(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, u8 arg3,
                   s32 arg4, u8 *arg5)
{
    sdkSpriteDrawQueued(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF, (void *)(u32)resourceFindByName(D_0063FAA0), arg4, 0, 0, 0.0f, 1.0f, 1.0f, arg5);
}

// FUN_002E0CA0
void fclDrawEquipHelpSprite(s32 arg0, f2 arg1, f32 fparg0, s32 arg2, u8 arg3,
                   s32 arg4, u8 *arg5)
{
    sdkSpriteDrawQueued(arg1.x, arg1.y, fparg0, arg2, arg3, arg0 & 0xFFFF, (void *)(u32)resourceFindByName(D_0063FB90), arg4, 0, 0, 0.0f, 1.0f, 1.0f, arg5);
}

// FUN_002E0D60
s32 fclBankManagerCreate(void)
{
    u8 *temp = func_002e1db0(0x30, 0, 0, 0);
    iGpffffb588 = temp;
    return *(s32 *)(temp + 0x24);
}

// FUN_002E0DA0
s64 fclBankTryQueueRequest(void)
{
    return (s64)(fclBankQueueRequest() != 0) << 0x30 >> 0x30;
}
