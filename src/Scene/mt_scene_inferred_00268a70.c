#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
#include "scene_task_internal.h"
#include "kwln_task_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void qsort(u32 *, s32, s32,
                           s32 (*)(u8 **arg0, u8 **arg1));
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern u8 D_0088152F[];
typedef struct { s32 value[19]; } Code1_00267800ShapeTable;
extern Code1_00267800ShapeTable D_00638FD0;
typedef union { f32 value[19]; u32 words[19]; } Code1_00267800ScaleTable;
extern Code1_00267800ScaleTable D_00639020;
extern f32 fGpffff8218;
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u8 pad18[0x18];
    s32 field18;
    s32 field1C;
    s32 field20;
} Code1_00263220State;

extern void PrimDrawContour(f32 x, f32 y, f32 depth,
                          s32 rgb, s32 alpha, s32 unusedMode, s32 shape,
                          s32 originX, s32 originY,
                          f32 rotation, f32 scaleX, f32 scaleY);
extern char iGpffffa6c4;
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);


extern u8 D_00637420[];


extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern u8 D_00638F90[];
extern char D_00637348[];
extern void calDrawWeather(s32 x, s32 y, f32 depth, u8 opacity,
                           s32 weather, s32 highlight, f32 scaleX, f32 scaleY,
                           s32 clipLeft, s32 clipWidth, s32 font,
                           s32 forcedHighlight);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern u8 iGpffffa734;

extern f32 D_007612C4;
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_loop_invariants hoists the (u8)opacity conversion out of the fade block into a
 * spill, as retail does. */
#pragma push
#pragma pop
/* The switch arms are in retail's jump-table order. Locals with disjoint live ranges share one
 * variable, following retail's register reuse across cases. */
#pragma push
#pragma pop
/* Scene icon task update, the callback created by MT_Scene_SpawnIconTask. */
// FUN_00268A70
s32 MT_Scene_IconTaskUpdate(u8 *task)
{
    s32 remainingFrames;
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    remainingFrames = ((SceneIconWork *)work)->remainingFrames - 1;
    ((SceneIconWork *)work)->remainingFrames = remainingFrames;
    if (remainingFrames < 0) {
        mdlEffectDestroy((u8 *)*(s32 *)&((SceneIconWork *)work)->value.handle);
        MEMBER(s32, work, SceneIconWork, value.handle) = 0;
        return -1;
    }
    return 0;
}

// Scene icon task destroy: releases the icon resource and the task work block.
// FUN_00268AD0
void MT_Scene_IconTaskDestroy(u8 *task)
{
    u8 *work;
    u8 *effect;

    work = ((struct KwlnTask *)task)->work;
    effect = *(u8 **)&((SceneIconWork *)work)->value.effect;
    if (effect != NULL) {
        mdlEffectDestroy(effect);
        MEMBER(u8 *, work, SceneIconWork, value.effect) = NULL;
    }
    jtbl_008873EC[0](work);
}

