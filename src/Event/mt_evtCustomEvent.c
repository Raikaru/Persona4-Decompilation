/* Source unit: src/Event/mt_evtCustomEvent_00291900.c */
#include "type.h"
#include "scene_event_internal.h"

/* Ported from P3FES src/Event/mt_evtCustomEvent.c FUN_0039eb90 (verified MATCH
 * there). 003b5d10 -> func_00145270, 003b7090 -> func_00146630. */

// lint: allow H011 -- measured: u16 prototype regresses evtCustomEventReleaseRes (u32 id passed through, 53 diff)
extern u32 MT_Scene_GetRes(u32);
extern void MT_Scene_DestroyRes(u32);



// Intent: Releases the eight custom-event resources (ids from 0x38E in the 0xC00 range) that still exist [inferred]
// FUN_00291900
void evtCustomEventReleaseRes(void)
{
    int iVar3;
    u32 uVar1;
    u32 lVar2;

    for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
        uVar1 = iVar3 + 0x38eU & 0x3ff | 0xc00;
        lVar2 = MT_Scene_GetRes((u16)uVar1);
        if (lVar2 != 0) {
            MT_Scene_DestroyRes((u16)uVar1);
        }
    }
    return;
}

/* Source unit: src/Event/mt_evtCustomEvent_002919d0.c */
// Intent: Returns the custom-event resource id for index object (object + 0x38E) [inferred]
// FUN_002919D0
s32 evtCustomEventResId(s32 object)
{
    return object + 0x38e;
}
