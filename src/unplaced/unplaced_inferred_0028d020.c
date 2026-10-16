/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0028d020-0028d0a0 */

#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"
extern void sdkSndStopChannel(s16 arg0);
extern s32 D_008825F0[10];
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Event result slot: stores a call result in slot 'arg0' (0-9); out-of-range indices are ignored.
// FUN_0028D020
void evtResultSet(s32 arg0, s32 arg1) {
    if ((arg0 >= 0xA) || (arg0 < 0)) {
        return;
    }
    D_008825F0[arg0] = arg1;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Event result slot: reads slot 'arg0'; -1 for an out-of-range index.
// FUN_0028D060
s32 evtResultGet(s32 arg0) {
    if (arg0 >= 0xA) {
        return -1;
    }
    return D_008825F0[arg0];
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Event resource list: releases each resource id stored in the node's list.
// FUN_0028D0A0
void evtReleaseRes(u8 *arg0) {
    s32 i;

    i = 0;
    while (i < *(s32 *)(arg0 + 0xD4)) {
        sdkSndStopChannel(*(s16 *)(arg0 + i * 4 + 0xD8));
        i++;
    }
    *(s32 *)(arg0 + 0xD4) = 0;
}
#pragma pop
