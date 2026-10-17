#include "scene_light_override_internal.h"
#include "type.h"
#include "scene_event_internal.h"
#include "evt_internal.h"

extern f32 D_00882214[];
extern f32 D_00882218[];
extern f32 D_0088221C[];
extern f32 D_00882220[];
extern f32 D_00882224[];
extern f32 D_00882228[];
extern f32 D_0088222C[];
extern f32 D_00882230[];
extern f32 D_00882234[];
extern f32 D_00882238[];
extern f32 D_0088223C[];
extern f32 D_00882240[];
extern f32 D_00882244[];
/* measured: retail window 128 bytes; derived from complete retail disassembly. */
/* measured: O1 probe preserves the retail comparison constants. */
#pragma optimization_level 1
// Returns 1 when the light-slot table is idle: every entry except slot 0 and slots 4-6 is zero.
// FUN_00285330
s32 evtSlotTableIdle(void) {
    s32 i;
    s32 exemptSlot4;
    s32 exemptSlot5;
    s32 exemptSlot6;
    s32 *table;

    i = 0;
    table = D_00882170;
    exemptSlot6 = 6;
    exemptSlot5 = 5;
    exemptSlot4 = 4;
    while (i < 0xD) {
        if ((i != 0) && (i != exemptSlot4) && (i != exemptSlot5) && (i != exemptSlot6) && (table[i] != 0)) {
            return 0;
        }
        i++;
    }
    return 1;
}
/* measured: restore the translation unit optimization level after evtSlotTableIdle. */
#pragma optimization_level 2
// Returns the command parameter as f32, biased by +2.0.
// FUN_0028BF90
f32 evtCommandParamF32(s32 param) {
    return (f32)param + 2.0f;
}

/* measured: required for exact retail loop codegen in sceneLightSlotsReset. */
#pragma push
#pragma opt_loop_invariants on

// Resets the first three light slots to default colours, mode 0, and no resource.
// FUN_0028C370
void sceneLightSlotsReset(void)
{
    f32 secondColor;
    f32 firstColor;
    s32 index;
    SceneLightSlot *entry;
    SceneLightSlot *slots;
    f32 unknown38;

    index = 0;
    slots = D_00882210;
    secondColor = iGpffff809c;
    firstColor = iGpffff8218;
    unknown38 = 7.0f;
    for (; index < 3; index = index + 1) {
        entry = &slots[index];
        entry->secondColor.x = secondColor;
        entry->secondColor.y = secondColor;
        entry->secondColor.z = secondColor;
        entry->secondColor.w = 0.0f;
        entry->angles.x = 0.0f;
        entry->angles.y = 0.0f;
        entry->angles.z = 0.0f;
        entry->angles.w = 0.0f;
        entry->firstColor.x = firstColor;
        entry->firstColor.y = firstColor;
        entry->firstColor.z = firstColor;
        entry->firstColor.w = 0.0f;
        entry->unknown38 = unknown38;
        entry->unknown3c = 0.0f;
        entry->mode = 0;
        entry->resource = NULL;
    }
}
/* measured: restore pragma state after sceneLightSlotsReset. */
#pragma pop
// Writes slot `slot` (0-2) of the light slot table: position, colour, and mode value.
// FUN_0028CED0
void sceneLightSlotSet(s32 slot, s32 mode, s32 modeValue, f32 *arg3,
                       f32 *arg4, f32 *arg5) {
    s32 slotOffset;

    if (slot < 3) {
        slotOffset = slot << 6;
        *(f32 *)((u8 *)D_00882218 + slotOffset) = arg3[0];
        *(f32 *)((u8 *)D_0088221C + slotOffset) = arg3[1];
        *(f32 *)((u8 *)D_00882220 + slotOffset) = arg3[2];
        *(u32 *)((u8 *)D_00882224 + slotOffset) = 0;
        *(f32 *)((u8 *)D_00882228 + slotOffset) = arg4[0];
        *(f32 *)((u8 *)D_0088222C + slotOffset) = arg4[1];
        *(f32 *)((u8 *)D_00882230 + slotOffset) = arg4[2];
        *(f32 *)((u8 *)D_00882234 + slotOffset) = arg4[3];
        *(f32 *)((u8 *)D_00882238 + slotOffset) = arg5[0];
        *(f32 *)((u8 *)D_0088223C + slotOffset) = arg5[1];
        *(f32 *)((u8 *)D_00882240 + slotOffset) = arg5[2];
        *(u32 *)((u8 *)D_00882244 + slotOffset) = 0x3F800000;
        *(s32 *)((u8 *)D_00882210 + slotOffset) = mode;
        if (mode == 3) {
            *(s32 *)((u8 *)D_00882214 + slotOffset) = modeValue;
            return;
        }
        *(s32 *)((u8 *)D_00882214 + slotOffset) = 0;
    }
}
