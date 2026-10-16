/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0033d310-0033dc60 */

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
typedef FclVec2 F2_0033;

/* Same four byte channels as the color constructor's output. */
typedef FclDrawColor Color_0033;

typedef struct {
    s32 sp30;
    s16 sp34;
    s16 pad36;
    s32 sp38;
    s32 sp3c;
} D9D0Locals;

extern void fclSpriteStartPosition(u8 *arg0, F2_0033 arg1, F2_0033 arg2,
                           u32 arg3, s32 arg4, s32 arg5);
extern s32 mtSceneResListPrepareAll(void);
extern s32 evtCreateEventTask(s32 arg0, s32 arg1, s32 arg2); /* lint: allow H011 -- caller stores the returned handle; the definition takes two arguments and ignores the third */
extern s32 evtPMFileReaderCreate(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 evtPMFileReaderIsDone(s32 arg0);
extern s32 evtPMFileReaderGetFirstEntry(s32 arg0, s32 *arg1, s32 *arg2,
                         s16 *arg3, s32 *arg4);
extern void fieldSceneLoad(s32 arg0, s32 arg1);
extern void fieldSceneRequestRoom(s32 arg0);
extern void fieldSceneRequestSecondaryRoom(s32 arg0);
extern s32 fieldSceneLoadStep(void);
extern void kwlnTaskDestroyWithHierarchy(s32 arg0);
extern s32 kwlnTaskIsLinked(s32 arg0);
extern u8 *kwlnGetCamera(void);
extern void K_View_SetFov(u8 *arg0, f32 arg1);
extern f32 MT_Scene_GetCameraFov(void);
extern s32 MT_Scene_GetCameraResFirst(void);
extern void func_003e9cb0(s32 arg0, s32 arg1, s32 arg2);
extern s32 fadeStatus(void);
extern s32 fclCombineEventGateCreate(u8 *arg0, s32 arg1);
extern void PrimQueueBatchAlpha(void *, void *, f32, s32, s32, s32, s16, s16,
                         f32, f32, f32, void *);
extern u8 D_00794A80[];
extern u8 D_00794AB0[];
// Identical to fclObjectGetWork (code1_002e.c).
// FUN_0033D310
u8 *fclBustupObjGetWork(u8 *arg0)
{
    return (u8 *)fclObjWork(arg0);
}

// Identical to fclObjChangeFlagBit (code1_002e.c).
// FUN_0033D320
void fclBustupObjChangeFlagBit(u8 *arg0, s32 arg1, s8 arg2) {
    FclObject *p = fclObjWork(arg0);

    if (arg2 == 0) {
        p->spriteFlags |= (s16)((1 << arg1) & 0xFFFF);
    } else if (arg2 == 1) {
        p->spriteFlags &= (s16)((1 << arg1) ^ 0xFFFF);
    }
}

// Identical to fclObjTestFlagBit (code1_002e.c).
// FUN_0033D390
s32 fclBustupObjTestFlagBit(u8 *arg0, s32 arg1)
{
    return (*(s16 *)(*(u8 **)(arg0 + 0x38) + 4) & ((1 << arg1) & 0xFFFF)) >> arg1;
}

// FUN_0033D3C0
void func_0033d3c0(u8 *arg0, f32 arg1)
{
    fclObjWork(arg0)->anchorValue = arg1;
}

// FUN_0033D3D0
void func_0033d3d0(u8 *arg0, s32 arg1)
{
    fclObjWork(arg0)->anchorMode = arg1;
}

// Identical to fclObjStartPosition (code1_002e.c).
// FUN_0033D3E0
void fclBustupObjStartPosition(u8 *arg0, F2_0033 p1, F2_0033 p2,
                   u32 arg3, u32 arg4, s16 arg5)
{
    fclSpriteStartPosition(fclObjSprite(arg0), p1, p2, arg3, arg4, arg5);
}

// FUN_0033D420
void fclBustupObjStartPositionMode(u8 *arg0, F2_0033 p1, F2_0033 p2,
                   u32 arg3, s8 arg4, u32 arg5, s16 arg6)
{
    FclObject *p;

    p = fclObjWork(arg0);
    fclSpriteStartPosition((u8 *)p + 4, p1, p2, arg3, arg5, arg6);
    p->mode = arg4;
    fclObjWork(arg0)->spriteFlags |= 0x400;
    fclObjWork(arg0)->spriteFlags &= (s16)~2;
}

// Identical to fclObjStartAlpha (code1_002e.c).
// FUN_0033D4B0
void fclBustupObjStartAlpha(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4, s64 arg5)
{
    fclSpriteStartAlpha(fclObjSprite(arg0), arg1, arg2, arg3, arg4, (s16)arg5);
}

// Identical to fclObjStartUniformRevealScale (code1_002e.c).
// FUN_0033D4E0
void fclBustupObjStartUniformRevealScale(u8 *arg0, f32 fparg0, f32 fparg1, u32 arg1, u32 arg2, s64 arg3)
{
    fclSpriteStartRevealScale(fclObjSprite(arg0), fparg0, fparg1, fparg0, fparg1, arg1, arg2, (s16)arg3);
}

// Identical to fclObjStartTween (code1_002e.c).
// FUN_0033D520
void fclBustupObjStartTween(u8 *arg0, f32 fparg0, f32 fparg1, u8 arg1, s32 arg2, s64 arg3)
{
    fclSpriteStartTween(fclObjSprite(arg0), arg1, arg2, arg3, fparg0, fparg1);
}

// FUN_0033D550
/* measured: opt_propagation off preserves the per-call field loads and the
   argument materialisation order for fclSpriteStartRevealScale. */
#pragma opt_propagation off
void fclBustupStartSlide(u8 *arg0)
{
    s16 h;
    u8 b1;
    u8 b2;
    f32 f0;
    f32 f1;
    u8 *p;

    *(s16 *)(*(u8 **)(arg0 + 0x38) + 4) |= 1;

    fclSpriteStartPosition(*(u8 **)(arg0 + 0x38) + 4,
                  *(F2_0033 *)(*(u8 **)(arg0 + 0x38) + 0x2C),
                  *(F2_0033 *)(*(u8 **)(arg0 + 0x38) + 0x1C),
                  0,
                  *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x36),
                  0);

    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x5E);
    p = *(u8 **)(arg0 + 0x38) + 4;
    b1 = *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x62);
    b2 = *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x60);
    fclSpriteStartAlpha(p, b1, b2, 0, h, 0);

    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0xC8);
    p = *(u8 **)(arg0 + 0x38) + 4;
    f0 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0xC4);
    f1 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0xBC);
    fclSpriteStartTween(p, 0, h, 0, f0, f1);

    f1 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x8C);
    f0 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x94);
    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x88);
    p = *(u8 **)(arg0 + 0x38) + 4;
    fclSpriteStartRevealScale(p, f0, f1, f0, f1, 0, h, 0);
}

#pragma push
#pragma opt_propagation on
/*
 * measured: 924/928 bytes, eight resolved relocations, four zero alignment bytes.
 * The point-anchor dependency rebuilds both passes without retaining x + 4.
 * Keep the input-Y snapshot and the real color/point object lifetimes.
 */
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
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0033D9D0
 s32 fclCombineEventTaskUpdate(u8 *arg0)
 {
     D9D0Locals locals;
     s32 taskHandle;
     s8 state;
     u8 *work;
     u8 *view;
     u8 *viewRec;

     work = *(u8 **)(arg0 + 0x38);
     state = *(s8 *)work;
     switch (state) {
     case 0:
         *(s32 *)(work + 4) = evtPMFileReaderCreate(
             0x5A, *(s8 *)(work + 0x10) + 1, 0, 0);
         *(s8 *)work = *(s8 *)work + 1;
     default:
         goto out;
     case 1:
         if ((evtPMFileReaderIsDone(*(s32 *)(work + 4)) != 0) &&
             (evtPMFileReaderGetFirstEntry(*(s32 *)(work + 4), &locals.sp3c,
                            &locals.sp38, &locals.sp34, &locals.sp30) == 1)) {
             fieldSceneLoad(locals.sp3c, locals.sp38);
             fieldSceneRequestRoom(locals.sp34);
             fieldSceneRequestSecondaryRoom(3);
             *(s8 *)work = *(s8 *)work + 1;
         }
         goto out;
     case 2:
         if (fieldSceneLoadStep() != 0) {
             *(s32 *)(work + 8) = evtCreateEventTask(
                 0x5A, *(s8 *)(work + 0x10) + 1, 0);
             *(s32 *)(work + 0xC) = fclCombineEventGateCreate(arg0, 0x58);
             *(s8 *)work = *(s8 *)work + 1;
         }
         goto out;
     case 3:
         if (kwlnTaskIsLinked(*(s32 *)(work + 8)) != 1) {
             taskHandle = *(s32 *)(work + 4);
             if (taskHandle != 0) {
                 kwlnTaskDestroyWithHierarchy(taskHandle);
             }
             *(s8 *)work = *(s8 *)work + 1;
         }
         goto out;
     case 4:
     case 5:
         *(s8 *)work = (s8)(state + 1);
         goto out;
     case 6:
         fieldSceneLoad(8, 3);
         fieldSceneRequestRoom(1);
         *(s8 *)work = *(s8 *)work + 1;
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
         func_003e9cb0(*(s32 *)(viewRec + 4), MT_Scene_GetCameraResFirst(), 0);
         func_00122640(1, 0xA);
         *(s8 *)work = *(s8 *)work + 1;
     case 8:
         if (fadeStatus() != 0) {
             return -1;
         }
         goto out;
     out:
         return 0;
     }
 }
#pragma pop

#pragma push
#pragma opt_propagation on
// FUN_0033DC60
void fclCombineEventTaskDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop
