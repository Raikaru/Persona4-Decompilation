
/* Unit optimizer settings shared by the neighboring functions. */
#pragma opt_loop_invariants off
#pragma opt_propagation on

#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"

extern void sdkSndStopChannel(s16 );
extern s32 D_008825F0[10];
// Event result slot: stores a call result in slot (0-9); out-of-range indices are ignored.
// FUN_0028D020
void evtResultSet(s32 slot, s32 value) {
    if ((slot >= 0xA) || (slot < 0)) {
        return;
    }
    D_008825F0[slot] = value;
}

// Event result slot: reads slot; -1 for an out-of-range index.
// FUN_0028D060
s32 evtResultGet(s32 slot) {
    if (slot >= 0xA) {
        return -1;
    }
    return D_008825F0[slot];
}

// Event resource list: releases each resource id stored in the node's list.
// FUN_0028D0A0
void evtReleaseRes(u8 *work) {
    /* measured: channel ids are read through the full event-work array, as retail addresses them. */
    s32 i;

    i = 0;
    while (i < ((EvtSoundChannels *)(work + 0xD4))->count) {
        sdkSndStopChannel(((EvtEventWork *)work)->sound.entries[i].id);
        i++;
    }
    ((EvtSoundChannels *)(work + 0xD4))->count = 0;
}
