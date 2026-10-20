/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 001537c0-00153a30 */

/* Unit optimizer setting shared by all scene-resource functions. */
#pragma opt_loop_invariants on

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
extern u8 *MT_Scene_GetResListHead(s32);
extern void FldRc_SetClumpVector(s32, s32);
extern void FldRc_SetObjectVector(s32, s32);
extern s32 mdlGetClump(s32);
#include "resrc_manager_internal.h"
/* Scene render resources: +8 object, +0x18 clump count, followed by clump handles. */
typedef struct {
    u32 flags;
    u8 pad4[4];
    u32 object;
    u8 padC[0xC];
    u32 clumpCount;
    u32 clumps[1];
} SceneRenderResources;

// Intent: Set the vector on the scene's object, its clumps and the resource list 0xA entries [inferred]
// FUN_001537C0
void MT_Scene_SetResVector(u8 *resource, s32 vector)
{
    s32 index;
    u8 *work;

    work = MT_Scene_GetResListHead(0xA);
    if ((((SceneRenderResources *)resource)->flags & 1) != 0) {
        FldRc_SetObjectVector(((SceneRenderResources *)resource)->object, vector);
    }
    index = 0;
    while ((u32)index < ((SceneRenderResources *)resource)->clumpCount) {
        FldRc_SetClumpVector(((SceneRenderResources *)resource)->clumps[index], vector);
        index += 1;
    }
    while (work != NULL) {
        FldRc_SetClumpVector(mdlGetClump((s32)((ResrcRecord *)work)->slotHandle[1]), vector);
        work = (u8 *)((ResrcRecord *)work)->next;
    }
}

// Intent: Scale the colours of the scene's object and clumps by the given colour, then set the resource list's model colours [inferred]
// FUN_001538A0
void MT_Scene_ScaleResColors(u32 *resource, const f32 *color)
{
    u32 i;
    s32 node;
    RwRGBA rgba;
    u32 model;

    node = (s32)MT_Scene_GetResListHead(10);
    if ((((SceneRenderResources *)resource)->flags & 1) != 0)
    {
        FldRc_ScaleObjectColors(((SceneRenderResources *)resource)->object, color);
    }
    for (i = 0; i < ((SceneRenderResources *)resource)->clumpCount; i++)
    {
        FldRc_ScaleClumpColors(((SceneRenderResources *)resource)->clumps[i], color);
    }
    while (node != 0)
    {
        rgba.red = (s32)(color[0] * 255.0f + 0.5f);
        rgba.green = (s32)(color[1] * 255.0f + 0.5f);
        rgba.blue = (s32)(color[2] * 255.0f + 0.5f);
        rgba.alpha = (s32)(color[3] * 255.0f + 0.5f);
        model = (u32)((ResrcRecord *)node)->slotHandle[1];
        mdlSetColor(model, &rgba);
        node = (s32)((ResrcRecord *)node)->next;
    }
}

// Intent: Task update for the colour cross-fade: run one cross-fade step and continue [inferred]
// FUN_00153A00
s32 FldColorCrossfadeUpdate(u8 *unusedTask)
{
    FldColorCrossfadeStep();
    return 0;
}

// Intent: Call the task's hook from the hook table with the work block at +0x38 [inferred]
// FUN_00153A30
void MT_Scene_CallTaskHook(u8 *task)
{
    (*DAT_008873EC)(((SdkTask *)task)->work);
}

#include "Kosaka/k_fldFrame_internal.h"
#include "scene_event_internal.h"
