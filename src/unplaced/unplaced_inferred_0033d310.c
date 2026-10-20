
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
#include "kwln_view_internal.h"
#include "scr_internal.h"
#include "shd_misc_internal.h"
#include "fcl_combine_internal.h"
extern void (*jtbl_008873EC[])(void *);
typedef FclVec2 F2_0033;

/* Same four byte channels as the color constructor's output. */
typedef FclDrawColor Color_0033;

typedef struct {
    s32 entryValue;
    s16 room;
    s16 pad36;
    s32 roomId;
    s32 fieldId;
} FclEventRoom;

/* Work read by the event loader/return-to-combine state machine. */
typedef struct FclCombineEventWork {
    s8 state;
    u8 pad01[3];
    s32 reader, eventTask, gateTask;
    s8 eventIndex;
} FclCombineEventWork;

extern void fclSpriteStartPosition(u8 *, F2_0033 , F2_0033 ,
                           u32 , s32 , s32 );
extern s32 mtSceneResListPrepareAll(void);
extern s32 evtCreateEventTask(s32 , s32 , s32 ); /* lint: allow H011 -- caller stores the returned handle; the definition takes two arguments and ignores the third */
extern s32 evtPMFileReaderCreate(s32 , s32 , s32 , s32 );
extern s32 evtPMFileReaderIsDone(s32 );
extern s32 evtPMFileReaderGetFirstEntry(s32 , s32 *, s32 *,
                         s16 *, s32 *);
extern void fieldSceneLoad(s32 , s32 );
extern void fieldSceneRequestRoom(s32 );
extern void fieldSceneRequestSecondaryRoom(s32 );
extern s32 fieldSceneLoadStep(void);
extern void kwlnTaskDestroyWithHierarchy(s32 );
extern s32 kwlnTaskIsLinked(s32 );
extern u8 *kwlnGetCamera(void);
extern void K_View_SetFov(u8 *, f32 );
extern f32 MT_Scene_GetCameraFov(void);
extern s32 MT_Scene_GetCameraResFirst(void);
extern void func_003e9cb0(s32 , s32 , s32 );
extern s32 fadeStatus(void);
extern s32 fclCombineEventGateCreate(u8 *, s32 );
extern void PrimQueueBatchAlpha(void *, void *, f32, s32, s32, s32, s16, s16,
                         f32, f32, f32, void *);
extern u8 D_00794A80[];
extern u8 D_00794AB0[];
// Identical to fclObjectGetWork (code1_002e.c).
// FUN_0033D310
u8 *fclBustupObjGetWork(u8 *task)
{
    return (u8 *)fclObjWork(task);
}

// Identical to fclObjChangeFlagBit (code1_002e.c).
/* Set or clear the selected sprite flag according to the requested operation. */
// FUN_0033D320
void fclBustupObjChangeFlagBit(u8 *task, s32 bit, s8 clear) {
    FclObject *p = fclObjWork(task);

    if (clear == 0) {
        p->spriteFlags |= (s16)((1 << bit) & 0xFFFF);
    } else if (clear == 1) {
        p->spriteFlags &= (s16)((1 << bit) ^ 0xFFFF);
    }
}

// Identical to fclObjTestFlagBit (code1_002e.c).
// FUN_0033D390
s32 fclBustupObjTestFlagBit(u8 *task, s32 bit)
{
    return (((FclObject *)((KwlnTask *)(task))->work)->spriteFlags & ((1 << bit) & 0xFFFF)) >> bit;
}

// FUN_0033D3C0
void fclBustupObjSetAnchorValue(u8 *task, f32 value)
{
    fclObjWork(task)->anchorValue = value;
}

// FUN_0033D3D0
void fclBustupObjSetAnchorMode(u8 *task, s32 mode)
{
    fclObjWork(task)->anchorMode = mode;
}

// Identical to fclObjStartPosition (code1_002e.c).
/* Forward a position transition to the object sprite with its signed delay. */
// FUN_0033D3E0
void fclBustupObjStartPosition(u8 *task, F2_0033 start, F2_0033 end,
                   u32 easing, u32 duration, s16 delay)
{
    fclSpriteStartPosition(fclObjSprite(task), start, end, easing, duration, delay);
}

/* Start a sprite position transition and enable the requested object positioning mode. */
// FUN_0033D420
void fclBustupObjStartPositionMode(u8 *task, F2_0033 start, F2_0033 end,
                   u32 easing, s8 mode, u32 duration, s16 delay)
{
    FclObject *p;

    p = fclObjWork(task);
    fclSpriteStartPosition((u8 *)p + 4, start, end, easing, duration, delay);
    p->mode = mode;
    fclObjWork(task)->spriteFlags |= 0x400;
    fclObjWork(task)->spriteFlags &= (s16)~2;
}

// Identical to fclObjStartAlpha (code1_002e.c).
// FUN_0033D4B0
void fclBustupObjStartAlpha(u8 *task, u8 start, u8 end, u8 easing, s32 duration, s64 delay)
{
    fclSpriteStartAlpha(fclObjSprite(task), start, end, easing, duration, (s16)delay);
}

// Identical to fclObjStartUniformRevealScale (code1_002e.c).
// FUN_0033D4E0
void fclBustupObjStartUniformRevealScale(u8 *task, f32 start, f32 end, u32 easing, u32 duration, s64 delay)
{
    fclSpriteStartRevealScale(fclObjSprite(task), start, end, start, end, easing, duration, (s16)delay);
}

// Identical to fclObjStartTween (code1_002e.c).
// FUN_0033D520
void fclBustupObjStartTween(u8 *task, f32 start, f32 end, u8 easing, s32 duration, s64 delay)
{
    fclSpriteStartTween(fclObjSprite(task), easing, duration, delay, start, end);
}

/* Start position, alpha, tween and reveal-scale transitions from the object's current values to its stored targets. */
#pragma push
#pragma opt_propagation off
/* measured: retail's duration load order and shared reveal-duration lifetime need propagation off. */
// FUN_0033D550
/* measured: propagation off keeps the per-call field loads and the argument order for
 * fclSpriteStartRevealScale. */
void fclBustupStartSlide(u8 *task)
{
    s16 duration;
    u8 startAlpha;
    u8 endAlpha;
    f32 startValue;
    f32 endValue;
    u8 *sprite;

    fclObjWork(task)->spriteFlags |= 1;

    fclSpriteStartPosition(((KwlnTask *)(task))->work + 4,
                  fclObjWork(task)->anchorPosition,
                  fclObjWork(task)->targetPosition,
                  0,
                  fclObjWork(task)->positionDuration,
                  0);

    duration = fclObjWork(task)->alphaDuration;
    sprite = fclObjSprite(task);
    startAlpha = fclObjWork(task)->alpha;
    endAlpha = fclObjWork(task)->targetAlpha;
    fclSpriteStartAlpha(sprite, startAlpha, endAlpha, 0, duration, 0);

    duration = fclObjWork(task)->tweenDuration;
    sprite = fclObjSprite(task);
    startValue = fclObjWork(task)->tweenValue;
    endValue = fclObjWork(task)->targetTween;
    fclSpriteStartTween(sprite, 0, duration, 0, startValue, endValue);

    endValue = fclObjWork(task)->targetScale;
    startValue = fclObjWork(task)->scaleX;
    duration = fclObjWork(task)->revealDuration;
    sprite = fclObjSprite(task);
    fclSpriteStartRevealScale(sprite, startValue, endValue, startValue, endValue, 0, duration, 0);
}
#pragma pop

/* Draw the rotating five-point band and optional white highlight; return the wrapped rotation
 * angle. */
// FUN_0033D630
f32 fclBustupDrawRotatingBand(F2_0033 pos, s16 angleStep, f32 angleOffset, u8 alpha, s8 highlight)
{
    Color_0033 baseColor;
    Color_0033 highlightColor;
    F2_0033 points[5];
    Color_0033 colors[5];
    f32 rotation;
    f32 originX;
    f32 originY;
    f32 result;
    f32 inputY = pos.y;

    rotation = (f32)-(s16)angleStep - angleOffset;

    originX = 113.0f + pos.x;
    points[0].x = points[4].x = originX;

    originY = 113.0f + inputY;
    points[0].y = points[4].y = originY;

    points[1].x = 4.0f + points[0].x;
    points[1].y = 338.0f;

    points[2].x = 26.0f + points[1].x;
    points[2].y = -400.0f;

    points[3].x = originX - 26.0f;
    points[3].y = -400.0f;

    baseColor = fclMakeDrawColor(0x7E, 0, 8, alpha);
    colors[0] = colors[1] = colors[2] = colors[3] = colors[4] = baseColor;

    PrimQueueBatchAlpha(colors, points, 70.0f, 5, 4, 1, 0, 0, rotation, 1.0f, 1.0f, D_00794AB0);

    if ((s8)highlight == 1) {
        points[0].x = points[4].x = originX;
        points[0].y = points[4].y = originY;

        points[1].x = 4.0f + points[0].x;
        points[1].y = 338.0f;

        points[2].x = 7.0f + (26.0f + points[1].x);
        points[2].y = -400.0f;

        points[3].x = (originX - 26.0f) - 7.0f;
        points[3].y = -400.0f;

        highlightColor = fclMakeDrawColor(0xFF, 0xFF, 0xFF, alpha);
        colors[0] = colors[1] = colors[2] = colors[3] = colors[4] = highlightColor;

        PrimQueueBatchAlpha(colors, points, 69.0f, 5, 4, 1, 0, 0, 5.0f + rotation, 1.0f, 1.0f, D_00794A80);
    }

    result = (f32)angleStep + angleOffset;
    if (result >= 360.0f) {
        result -= 360.0f;
    }
    return result;
}

/* Load the selected fusion event room, run its event task, then reload the combine room and wait for the fade. */
// FUN_0033D9D0
 s32 fclCombineEventTaskUpdate(u8 *task)
 {
     FclEventRoom locals;
     s32 taskHandle;
     s8 state;
     u8 *work;
     u8 *view;
     u8 *viewRec;

     work = ((struct KwlnTask *)task)->work;
     state = ((FclCombineEventWork *)work)->state;
     switch (state) {
     case 0:
         ((FclCombineEventWork *)work)->reader = evtPMFileReaderCreate(
             0x5A, ((FclCombineEventWork *)work)->eventIndex + 1, 0, 0);
         ((FclCombineEventWork *)work)->state = ((FclCombineEventWork *)work)->state + 1;
     default:
         goto out;
     case 1:
         if ((evtPMFileReaderIsDone(((FclCombineEventWork *)work)->reader) != 0) &&
             (evtPMFileReaderGetFirstEntry(MEMBER(s32, work, FclCombineEventWork, reader), &locals.fieldId,
                            &locals.roomId, &locals.room, &locals.entryValue) == 1)) {
             fieldSceneLoad(locals.fieldId, locals.roomId);
             fieldSceneRequestRoom(locals.room);
             fieldSceneRequestSecondaryRoom(3);
             ((FclCombineEventWork *)work)->state = ((FclCombineEventWork *)work)->state + 1;
         }
         goto out;
     case 2:
         if (fieldSceneLoadStep() != 0) {
             ((FclCombineEventWork *)work)->eventTask = evtCreateEventTask(
                 0x5A, ((FclCombineEventWork *)work)->eventIndex + 1, 0);
             ((FclCombineEventWork *)work)->gateTask = fclCombineEventGateCreate(task, 0x58);
             ((FclCombineEventWork *)work)->state = ((FclCombineEventWork *)work)->state + 1;
         }
         goto out;
     case 3:
         if (kwlnTaskIsLinked(((FclCombineEventWork *)work)->eventTask) != 1) {
             taskHandle = ((FclCombineEventWork *)work)->reader;
             if (taskHandle != 0) {
                 kwlnTaskDestroyWithHierarchy(taskHandle);
             }
             ((FclCombineEventWork *)work)->state = ((FclCombineEventWork *)work)->state + 1;
         }
         goto out;
     case 4:
     case 5:
         ((FclCombineEventWork *)work)->state = (s8)(state + 1);
         goto out;
     case 6:
         fieldSceneLoad(8, 3);
         fieldSceneRequestRoom(1);
         ((FclCombineEventWork *)work)->state = ((FclCombineEventWork *)work)->state + 1;
         goto out;
     case 7:
         if (fieldSceneLoadStep() == 0) {
             goto out;
         }
         if (mtSceneResListPrepareAll() == 0) {
             goto out;
         }
         view = kwlnGetCamera();
         K_View_SetFov(view, MT_Scene_GetCameraFov());
         viewRec = kwlnGetCamera();
         func_003e9cb0(((KwlnView *)viewRec)->camera, MT_Scene_GetCameraResFirst(), 0);
         fadeBeginReturnTransition(1, 0xA);
         ((FclCombineEventWork *)work)->state = ((FclCombineEventWork *)work)->state + 1;
     case 8:
         if (fadeStatus() != 0) {
             return -1;
         }
         goto out;
     out:
         return 0;
     }
 }

// FUN_0033DC60
void fclCombineEventTaskDestroy(u8 *task)
{
    jtbl_008873EC[0](((struct KwlnTask *)task)->work);
}
