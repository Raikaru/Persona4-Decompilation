
#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_action_internal.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"
#include "datPersona_internal.h"
/* Unit setting for action target classification. */
#pragma push
#pragma opt_loop_invariants off
#pragma optimization_level 1
/* Return whether classification of the action's stored skill yields no target bits. */
// FUN_001F0FF0
s32 btlActionHasNoTargetClass(u32 action)
{
    s32 index;
    index = ((BtlAction *)action)->unk_6e;
    return (btlSkillClassifyTargets((u8 *)action, 0, index, 0) & 0xFFFF) == 0;
}
#pragma pop
