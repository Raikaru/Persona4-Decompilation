/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0028d020-0028d0a0 */

#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"

extern void sdkSndStopChannel(s16 );
extern s32 D_008825F0[10];
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Event result slot: stores a call result in slot (0-9); out-of-range indices are ignored.
// FUN_0028D020
void evtResultSet(s32 slot, s32 value) {
    if ((slot >= 0xA) || (slot < 0)) {
        return;
    }
    D_008825F0[slot] = value;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Event result slot: reads slot; -1 for an out-of-range index.
// FUN_0028D060
s32 evtResultGet(s32 slot) {
    if (slot >= 0xA) {
        return -1;
    }
    return D_008825F0[slot];
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
// Event resource list: releases each resource id stored in the node's list.
// FUN_0028D0A0
void evtReleaseRes(u8 *work) {
    /* measured: the standalone channel-subobject form differs; the full event-work array form preserves MATCH. */
    s32 i;

    i = 0;
    while (i < ((EvtSoundChannels *)(work + 0xD4))->count) {
        sdkSndStopChannel(((EvtEventWork *)work)->sound.entries[i].id);
        i++;
    }
    ((EvtSoundChannels *)(work + 0xD4))->count = 0;
}
#pragma pop
