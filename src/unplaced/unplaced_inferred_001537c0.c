/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 001537c0-00153a30 */

#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "type.h"
#include "field_light_internal.h"
#include "field_frame_internal.h"
#include "rw_types_internal.h"
extern void (*DAT_008873EC[])(void *);
extern void FldColorCrossfadeStep(void);
extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern void FldRc_SetClumpVector(s32 arg0, s32 arg1);
extern void FldRc_SetObjectVector(s32 arg0, s32 arg1);
extern s32 mdlGetClump(s32 arg0);
#pragma push
#pragma opt_loop_invariants on
// Intent: Set the vector on the scene's object, its clumps and the resource list 0xA entries [inferred]
// FUN_001537C0
void MT_Scene_SetResVector(u8 *arg0, s32 arg1)
{
    s32 index;
    u8 *work;

    work = MT_Scene_GetResListHead(0xA);
    if ((*(s32 *)(arg0 + 0) & 1) != 0) {
        FldRc_SetObjectVector(*(s32 *)(arg0 + 8), arg1);
    }
    index = 0;
    while ((u32)index < *(u32 *)(arg0 + 0x18)) {
        FldRc_SetClumpVector(*(s32 *)(arg0 + (index * 4) + 0x1C), arg1);
        index += 1;
    }
    while (work != NULL) {
        FldRc_SetClumpVector(mdlGetClump(*(s32 *)(work + 0x144)), arg1);
        work = *(u8 **)(work + 0x138);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// Intent: Scale the colours of the scene's object and clumps by the given colour, then set the resource list's model colours [inferred]
// FUN_001538A0
void MT_Scene_ScaleResColors(u32 *resource, const f32 *color)
{
    u32 i;
    s32 node;
    RwRGBA rgba;
    u32 model;

    node = (s32)MT_Scene_GetResListHead(10);
    if ((*resource & 1) != 0)
    {
        FldRc_ScaleObjectColors(resource[2], color);
    }
    for (i = 0; i < resource[6]; i++)
    {
        FldRc_ScaleClumpColors(*(u32 *)((u8 *)resource + i * 4 + 0x1C), color);
    }
    while (node != 0)
    {
        rgba.red = (s32)(color[0] * 255.0f + 0.5f);
        rgba.green = (s32)(color[1] * 255.0f + 0.5f);
        rgba.blue = (s32)(color[2] * 255.0f + 0.5f);
        rgba.alpha = (s32)(color[3] * 255.0f + 0.5f);
        model = *(u32 *)(node + 0x144);
        mdlSetColor(model, &rgba);
        node = *(s32 *)(node + 0x138);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// Intent: Task update for the colour cross-fade: run one cross-fade step and continue [inferred]
// FUN_00153A00
s32 FldColorCrossfadeUpdate(u8 *unusedTask)
{
    FldColorCrossfadeStep();
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// Intent: Call the task's hook from the hook table with the work block at +0x38 [inferred]
// FUN_00153A30
void MT_Scene_CallTaskHook(u8 *arg0)
{
    (*DAT_008873EC)(*(u8 **)(arg0 + 0x38));
}
#pragma pop

#include "Kosaka/k_fldFrame_internal.h"
#include "scene_event_internal.h"
