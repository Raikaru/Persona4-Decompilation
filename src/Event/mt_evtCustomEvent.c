#include "type.h"
#include "scene_event_internal.h"

/* Matches P3FES func_0039eb90. */

// lint: allow H011 -- measured: retail passes the u32 id through; a u16 prototype changes
// evtCustomEventReleaseRes.
extern u32 MT_Scene_GetRes(u32);
extern void MT_Scene_DestroyRes(u32);


// Releases the eight custom-event resources (ids from 0x38E in the 0xC00 range) that still exist.
// FUN_00291900
void evtCustomEventReleaseRes(void)
{
    int resourceIndex;
    u32 resourceId;
    u32 resource;

    for (resourceIndex = 0; resourceIndex < 8; resourceIndex = resourceIndex + 1) {
        resourceId = resourceIndex + 0x38eU & 0x3ff | 0xc00;
        resource = MT_Scene_GetRes((u16)resourceId);
        if (resource != 0) {
            MT_Scene_DestroyRes((u16)resourceId);
        }
    }
    return;
}

/* Returns the custom-event resource id for the given object index (object + 0x38E). */
// FUN_002919D0
s32 evtCustomEventResId(s32 object)
{
    return object + 0x38e;
}
