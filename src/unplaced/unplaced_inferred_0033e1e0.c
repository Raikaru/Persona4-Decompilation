/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0033e1e0-0033e5a0 */

#include "fcl_object_internal.h"
#include "member_access.h"
#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "scr_internal.h"
#include "shd_misc_internal.h"
#include "fcl_combine_internal.h"
extern void (*jtbl_008873EC[])(void *);
extern void sdkSpriteRelease(void *node);
typedef FclVec2 F2_0033;

/* Allocated as 0x2C bytes by fclBustupCreate; start/end/current are Vec2 pairs. */
typedef struct FclBustupWork {
    s8 state;
    u8 pad01[3];
    union { s32 handle; void *pointer; } sprite;
    u8 pad08[4];
    FclVec2 start;
    FclVec2 end;
    FclVec2 position;
    s16 duration, frame, delay;
    s8 easing;
    u8 pad2B;
} FclBustupWork;

extern void chkmemAllocSiteTag(const void *, s32 );
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 sdkSpriteRequestLoad(void *);
extern u8 D_0064A458[];
extern u8 D_0064A470[];
extern u8 D_0064A480[];
extern s32 fclBustupUpdate(u8 *);
extern void fclBustupDraw(u8 *);
extern s32 fclPackRgba(u8, u8, u8, u8);
extern f32 fclEaseInterpolate(s32 , f32 , f32 , f32 , f32 );
extern s32 fclAddClamped(s32 , s32 , s32 , s32 , s8 );
extern s16 fclSubClamped(s32 , s32 , s32 , s32 , s8 );
extern s32 hMaestroDecodeIsReady(s32 , s32 );
extern s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 D_007955C0[];
#pragma push
#pragma opt_propagation on
/* Wait for the portrait sprite to load, then advance its delayed position transition and draw active states. */
// FUN_0033E1E0
s32 fclBustupUpdate(u8 *task)
{
    /* measured: remaining bustup fields preserve b210 reload/scheduling; individual typed substitutions lose MATCH. */
    u8 *p;
    s16 value;

    p = (((struct KwlnTask *)task)->work);
    switch (((FclBustupWork *)p)->state) {
    case 0:
        if (hMaestroDecodeIsReady(((FclBustupWork *)p)->sprite.handle, 3) == 0) {
            return 0;
        }
        ((FclBustupWork *)p)->state = 1;
        break;
    case 1:
        break;
    default:
        break;
    case 2:
        if (((FclBustupWork *)p)->duration > ((FclBustupWork *)p)->frame) {
            goto update;
        }
        ((FclBustupWork *)p)->state = 3;
        if (((FclBustupWork *)p)->position.x >= 640.0f) {
            ((FclBustupWork *)p)->state = 1;
            return 0;
        }
    update:
        ((FclBustupWork *)p)->position.x = fclEaseInterpolate(
            ((FclBustupWork *)p)->easing, ((FclBustupWork *)p)->start.x, ((FclBustupWork *)p)->end.x,
            (f32)MEMBER(s16, p, FclBustupWork, frame), (f32)MEMBER(s16, p, FclBustupWork, duration));
        ((FclBustupWork *)p)->position.y = fclEaseInterpolate(
            MEMBER(s8, p, FclBustupWork, easing), ((FclBustupWork *)(p))->start.y, ((FclBustupWork *)(p))->end.y,
            (f32)MEMBER(s16, p, FclBustupWork, frame), (f32)MEMBER(s16, p, FclBustupWork, duration));
        value = ((FclBustupWork *)p)->delay;
        if (value > 0) {
            MEMBER(s16, p, FclBustupWork, delay) = fclSubClamped(value, 1, 0, 0, 1);
        } else {
            MEMBER(s16, p, FclBustupWork, frame) = fclAddClamped(
                MEMBER(s16, p, FclBustupWork, frame), 1, MEMBER(s16, p, FclBustupWork, duration), 0, 1);
        }
        fclBustupDraw(task);
        break;
    case 3:
        fclBustupDraw(task);
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Release the portrait sprite and free the task work, reloading the work pointer after release. */
// FUN_0033E3A0
void fclBustupDestroy(u8 *task)
{
    /* measured: MEMBER reloads task work after sprite release before invoking the free callback. */
    sdkSpriteRelease(((FclBustupWork *)((KwlnTask *)(task))->work)->sprite.pointer);
    jtbl_008873EC[0](MEMBER(u8 *, task, KwlnTask, work));
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Allocate the 0x2C-byte portrait work and create its child task before requesting the sprite resource. */
// FUN_0033E3F0
s32 fclBustupCreate(u8 *parent)
{
    s32 result;
    u8 *work;

    chkmemAllocSiteTag(D_0064A458, 0x85);
    work = D_008873F4[0](1, 0x2C, 0x40000);
    result = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_0064A470), 0xF, 0, 0, fclBustupUpdate, fclBustupDestroy, (u8 *)(work));
    ((FclBustupWork *)work)->state = 0;
    ((FclBustupWork *)work)->sprite.handle = sdkSpriteRequestLoad(D_0064A480);
    return result;
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Draw the portrait at the current interpolated position with opaque white modulation. */
// FUN_0033E4B0
void fclBustupDraw(u8 *task)
{
    u8 *work;
    s32 color;
    f32 x;
    f32 y;

    work = (((struct KwlnTask *)task)->work);
    color = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
    x = ((FclBustupWork *)work)->position.x;
    y = ((FclBustupWork *)work)->position.y;
    sdkSpriteDrawQueued(x, y, 104.0f, color, 0xFF, 1, ((FclBustupWork *)work)->sprite.pointer,
                  1, 0, 0, 0.0f, 1.0f, 1.0f, D_007955C0);
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Store position endpoints, duration and delay, then activate the portrait movement state. */
// FUN_0033E540
void fclCombineStartMove(u8 *task, F2_0033 start, F2_0033 end, s16 duration, s16 delay)
{
    u8 *work;

    work = (((struct KwlnTask *)task)->work);
    ((FclBustupWork *)work)->position = start;
    ((FclBustupWork *)work)->start = ((FclBustupWork *)work)->position;
    ((FclBustupWork *)work)->end = end;
    ((FclBustupWork *)work)->duration = duration;
    ((FclBustupWork *)work)->frame = 0;
    ((FclBustupWork *)work)->delay = delay;
    ((FclBustupWork *)work)->state = 2;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0033E5A0
s32 fclBustupIsActive(u8 *task)
{
    return ((FclBustupWork *)((struct KwlnTask *)task)->work)->state != 0;
}
#pragma pop
