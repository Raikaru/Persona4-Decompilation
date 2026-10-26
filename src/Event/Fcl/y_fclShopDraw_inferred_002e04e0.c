
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
#include "fcl_bank_internal.h"
#include "fcl_object_internal.h"
#include "datPersona_internal.h"
/* List-manager payload pointer: nmListAllocManager stores the allocation's payload address here. */
typedef struct NmlistManager {
    u8 pad00[0x24];
    u8 *data;
} NmlistManager;

extern void fclSpriteStartPosition(u8 *animation, FclVec2 start, FclVec2 end, u32 mode, s32 duration, s32 delay);
extern u8 *iGpffffb588;
extern u8 *nmListAllocManager(s32 payloadSize, s32 onInsert, s32 onRemove, s32 onUpdate);
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern s32 resourceFindByName(const void *name);
extern u8 D_0063FB50[];
extern u8 D_0063FAA0[];
extern u8 D_0063FB90[];
extern u8 D_0063F560[];
/* Return the sprite-object work carried by the task. */
// FUN_002E04E0
u8 *fclObjectGetWork(u8 *task)
{
    return (u8 *)fclObjWork(task);
}

/* Set a sprite-status bit for operation 0, or clear it for operation 1. */
// FUN_002E04F0
void fclObjChangeFlagBit(u8 *task, u32 bitIndex, s8 operation) {
    u8 *base = (u8 *)fclObjWork(task);
    if (operation == 0) {
        ((FclObject *)base)->spriteFlags |= (s16)((1 << (bitIndex & 0xffff)) & 0xffff);
        return;
    }
    if (operation == 1) {
        ((FclObject *)base)->spriteFlags &= (s16)((1 << (bitIndex & 0xffff)) ^ 0xffff);
        return;
    }
}

/* Read one status bit; the bit index is narrowed to a halfword. */
// FUN_002E0570
s8 fclObjTestFlagBit(u8 *task, s32 bitIndex)
{
    s16 flags;

    flags = fclObjWork(task)->spriteFlags;
    return (s8)((flags & ((1 << (bitIndex & 0xFFFF)) & 0xFFFF)) >> (bitIndex & 0xFFFF));
}

/* Report whether any of sprite status bits 1..4 is active. */
// FUN_002E05A0
s8 fclObjHasStatusFlags(u8 *task) {
    s16 flags = fclObjWork(task)->spriteFlags;
    if (((s8)((flags & 2) >> 1)) == 0 && ((s8)((flags & 4) >> 2)) == 0 &&
        ((s8)((flags & 8) >> 3)) == 0 && ((s8)((flags & 0x10) >> 4)) == 0) {
        return 0;
    }
    return 1;
}

/* Start the object sprite position transition with the supplied endpoints. */
// FUN_002E0620
void fclObjStartPosition(u8 *task, FclVec2 start, FclVec2 end, u32 mode, u32 duration, s16 delay) {
    fclSpriteStartPosition((u8 *)fclObjWork(task) + 4, start, end, mode, duration, delay);
}

/* Start the object sprite alpha transition. */
// FUN_002E0660
void fclObjStartAlpha(u8 *task, u8 startAlpha, u8 endAlpha, u8 mode, s32 duration, s16 delay)
{
    fclSpriteStartAlpha((u8 *)fclObjWork(task) + 4, startAlpha, endAlpha, mode, duration, (s16)delay);
}

/* Apply the same reveal-scale endpoints to both axes. */
// FUN_002E0690
/* Float parameters come before the int ones to follow the caller fclShopSlideInFromRight; the EABI
 * puts ints and floats in separate registers either way. */
void fclObjStartUniformRevealScale(u8 *task, f32 startScale, f32 endScale, u32 mode, u32 duration, s64 delay)
{
    fclSpriteStartRevealScale(fclObjSprite(task), startScale, endScale, startScale, endScale, mode, duration, (s16)delay);
}

/* Start independent X/Y reveal-scale transitions on the object sprite. */
// FUN_002E06D0
void fclObjStartRevealScale(u8 *task, f32 startX, f32 endX, f32 startY, f32 endY, u32 mode, u32 duration, s64 delay)
{
    fclSpriteStartRevealScale(fclObjSprite(task), startX, endX, startY, endY, mode, duration, (s16)delay);
}

#pragma push
#pragma opt_propagation off
/* Slide by half the sprite height while fading and revealing vertically; show selects the upward fade-in path. */
// FUN_002E0700
void fclObjStartSlideFade(u8 *task, s64 spriteId, f32 startScaleY, f32 endScaleY,
                   s32 duration, s32 delay, s64 show)
{
    FclVec2 pos;
    FclVec2 upPosition;
    FclVec2 downPosition;
    FclVec2 upTarget;
    FclVec2 downTarget;
    f32 upX;
    f32 upY;
    f32 downX;
    f32 downY;
    f32 positionX;
    f32 positionY;
    u8 *handle;
    u8 *work;
    extern u8 *sdkSpriteNewNode(u32 packAddress, u32 recordIndex);
    extern f32 sdkSpriteScaledHeight(u8 *sprite);
    u8 *base;
    extern void sdkSpriteFreeNode(void *node);
    work = (u8 *)fclObjWork(task);
    positionX = ((FclObject *)work)->anchorPosition.x;
    positionY = ((FclObject *)work)->anchorPosition.y;
    pos.x = positionX;
    pos.y = positionY;
    if ((s8)show == 1) {
        handle = sdkSpriteNewNode(((FclObject *)work)->spriteResource, (s16)spriteId);
        upPosition = fclMakeVec2(pos.x,
                             pos.y - (sdkSpriteScaledHeight(handle) / 2.0f));
        upX = upPosition.x;
        upY = upPosition.y;
        upTarget.x = upX;
        upTarget.y = upY;
        delay = (s16)delay;
        fclSpriteStartPosition((u8 *)fclObjWork(task) + 4, pos, upTarget, 0, duration,
                       delay);
        sdkSpriteFreeNode(handle);
        fclSpriteStartAlpha((u8 *)fclObjWork(task) + 4, 0, 0xFF, 0, duration, delay);
    } else {
        handle = sdkSpriteNewNode(((FclObject *)work)->spriteResource, (s16)spriteId);
        downPosition = fclMakeVec2(pos.x,
                             pos.y + (sdkSpriteScaledHeight(handle) / 2.0f));
        downX = downPosition.x;
        downY = downPosition.y;
        downTarget.x = downX;
        downTarget.y = downY;
        delay = (s16)delay;
        fclSpriteStartPosition((u8 *)fclObjWork(task) + 4, pos, downTarget, 0, duration,
                       delay);
        sdkSpriteFreeNode(handle);
        fclSpriteStartAlpha((u8 *)fclObjWork(task) + 4, 0xFF, 0, 0, 0,
                       (s16)((s32)delay + duration));
    }
    base = (u8 *)fclObjWork(task);
    fclSpriteStartRevealScale(base + 4, 1.0f, 1.0f, startScaleY, endScaleY, 0, duration, delay);
}
#pragma pop

/* Start the object sprite scalar tween. */
// FUN_002E0940
void fclObjStartTween(u8 *task, f32 first, f32 second, u8 mode, s32 duration, s64 delay)
{
    fclSpriteStartTween((u8 *)fclObjWork(task) + 4, mode, duration, delay, first, second);
}

/* Start the object sprite color transition. */
// FUN_002E0970
void fclObjStartColor(u8 *task, FclDrawColor startColor, FclDrawColor endColor, u8 mode, s16 duration, s64 delay)
{
    extern void fclSpriteStartColor(u8 *animation, FclDrawColor start, FclDrawColor end, u8 mode, s16 duration, s16 delay);
    fclSpriteStartColor(fclObjSprite(task), startColor, endColor, mode, duration, delay);
}

/* Enable the hold timer, clear its elapsed frame count and install the new limit. */
// FUN_002E09B0
void fclObjSetHoldTimer(u8 *task, f32 timer, s16 limit)
{
    FclObject *obj = fclObjWork(task);
    s16 flags = obj->spriteFlags;
    obj->spriteFlags = flags | 0x80;
    obj->holdFrames = 0;
    obj->holdTimer = timer;
    obj->holdLimit = limit;
}

/* Enable anchor positioning and copy the indexed anchor-table position. */
// FUN_002E09E0
void fclObjSetAnchorPosition(u8 *task, s32 mode, f32 value) {
    FclObject *work = fclObjWork(task);
    f32 *entry = (f32 *)(D_0063F560 + work->anchorIndex * 8);
    FclVec2 out;
    work->spriteFlags |= 1;
    fclObjWork(task)->anchorValue = value;
    fclObjWork(task)->anchorMode = mode;
    work = fclObjWork(task);
    out = fclMakeVec2(entry[0], entry[1]);
    work->anchorPosition = out;
}

/* Set the anchor position and restore opaque, unit-scale sprite state. */
// FUN_002E0A60
void fclObjSetAnchorAlphaFull(u8 *task, s32 mode, f32 value)
{
    FclObject *work;
    u8 *entry;
    FclVec2 out;

    work = fclObjWork(task);
    entry = D_0063F560 + work->anchorIndex * 8;
    work->spriteFlags |= 1;
    fclObjWork(task)->anchorValue = value;
    fclObjWork(task)->anchorMode = mode;
    work = fclObjWork(task);
    out = fclMakeVec2(((FclVec2 *)entry)->x, ((FclVec2 *)entry)->y);
    work->anchorPosition = out;
    work = fclObjWork(task);
    work->alpha = 0xFF;
    work = fclObjWork(task);
    *(s32 *)&work->scale = 0x3F800000;
    *(s32 *)&work->scaleX = 0x3F800000;
    work = fclObjWork(task);
    work->tweenLoop = 0;
    /* Reset the two otherwise unidentified anchor-state bytes. */
    ((FclObject *)(u8 *)work)->unkA7 = 0;
    ((FclObject *)(u8 *)work)->unk67 = 0;
    work->mode = 0;
}

/* Queue a sprite from the equipment resource bank at the supplied screen position. */
// FUN_002E0B20
void fclDrawEquipSprite(s32 spriteId, FclVec2 position, f32 depth, s32 layer, u8 alpha,
                   s32 flags, u8 *drawContext)
{
    sdkSpriteDrawQueued(position.x, position.y, depth, layer, alpha, spriteId & 0xFFFF, (void *)(u32)resourceFindByName(D_0063FB50), flags, 0, 0, 0.0f, 1.0f, 1.0f, drawContext);
}

/* Queue a sprite from the resource bank identified by D_0063FAA0. */
// FUN_002E0BE0
void fclDrawResourceSprite(s32 spriteId, FclVec2 position, f32 depth, s32 layer, u8 alpha,
                   s32 flags, u8 *drawContext)
{
    sdkSpriteDrawQueued(position.x, position.y, depth, layer, alpha, spriteId & 0xFFFF, (void *)(u32)resourceFindByName(D_0063FAA0), flags, 0, 0, 0.0f, 1.0f, 1.0f, drawContext);
}

/* Queue a sprite from the equipment-help resource bank. */
// FUN_002E0CA0
void fclDrawEquipHelpSprite(s32 spriteId, FclVec2 position, f32 depth, s32 layer, u8 alpha,
                   s32 flags, u8 *drawContext)
{
    sdkSpriteDrawQueued(position.x, position.y, depth, layer, alpha, spriteId & 0xFFFF, (void *)(u32)resourceFindByName(D_0063FB90), flags, 0, 0, 0.0f, 1.0f, 1.0f, drawContext);
}

/* Create the bank list manager with a 0x30-byte inline payload and return that payload. */
// FUN_002E0D60
s32 fclBankManagerCreate(void)
{
    u8 *manager = nmListAllocManager(0x30, 0, 0, 0);
    iGpffffb588 = manager;
    return (s32)((NmlistManager *)manager)->data;
}

/* Narrow the bank queue helper result to a signed halfword predicate. */
// FUN_002E0DA0
s64 fclBankTryQueueRequest(s32 descriptor, s64 flags, s64 unusedKey)
{
    return (s64)(fclBankQueueRequest(descriptor, flags) != 0) << 0x30 >> 0x30;
}
