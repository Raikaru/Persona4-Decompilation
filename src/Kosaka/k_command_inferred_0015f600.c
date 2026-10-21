#include "resrc_manager_internal.h"

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
extern u8 *MT_Scene_GetResListHead(s32 resourceType);
extern void func_003e8110(s32 camera);
extern s32 func_003e8120(s32 camera);
extern s32 kwlnGetCamera(void);
extern s32 mdlPrepareModel(s32 model);
#include "Kosaka/k_fldFrame_internal.h"
#include "scene_event_internal.h"
#pragma push
/* measured: retail hoists loop invariants in this list scan; the default setting produces different
 * code. */
#pragma opt_loop_invariants on
// Return 1 when every resource in list 3 has flag 0x10000000 set, otherwise 0.
// FUN_0015F600
s32 MT_Scene_AllResFlagSet(void)
{
    u8 *work;
    s32 result;

    work = MT_Scene_GetResListHead(3);
    result = 1;
    while (work != NULL) {
        if (!((s32)((ResrcRecord *)work)->unk28 & 0x10000000)) {
            result = 0;
            break;
        }
        work = (u8 *)((ResrcRecord *)work)->next;
    }
    return result;
}
#pragma pop

// Prepares each unprepared model in scene resource list 3 and marks it prepared; returns 1 only
// when every model is ready.
// FUN_0015F660
s32 mtSceneResListPrepareAll(void)
{
    u8 *work;
    s32 result;
    ResrcRecord *resource;

    work = MT_Scene_GetResListHead(3);
    result = 1;
    while (work != NULL) {
        resource = (ResrcRecord *)work;
        if (!(((ResrcRecord *)work)->unk28 & 0x10000000)) {
            if (mdlPrepareModel((s32)((ResrcRecord *)work)->modelHandle164) != 0) {
                resource->unk28 |= 0x10000000;
            }
            result = 0;
        }
        work = (u8 *)((ResrcRecord *)work)->next;
    }
    if (func_003e8120(kwlnGetCamera()) != 0) {
        func_003e8110(kwlnGetCamera());
    }
    return result;
}
