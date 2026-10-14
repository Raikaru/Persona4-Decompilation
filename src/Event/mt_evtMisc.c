/* Source unit: src/promoted/code1_0028.c */
#include "scene_light_override_internal.h"
#include "type.h"
#include "scene_event_internal.h"

extern s32 D_00882170[];
extern f32 iGpffff809c;
extern f32 iGpffff8218;
extern SceneLightSlot D_00882210[];
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
// FUN_00285330
s32 func_00285330(void) {
    s32 i;
    s32 c4;
    s32 c5;
    s32 c6;
    s32 *table;

    i = 0;
    table = D_00882170;
    c6 = 6;
    c5 = 5;
    c4 = 4;
    while (i < 0xD) {
        if ((i != 0) && (i != c4) && (i != c5) && (i != c6) && (table[i] != 0)) {
            return 0;
        }
        i++;
    }
    return 1;
}
/* measured: restore the translation unit optimization level after func_00285330. */
#pragma optimization_level 2
// FUN_0028BF90
f32 func_0028bf90(s32 arg0) {
    return (f32)arg0 + 2.0f;
}

/* measured: required for exact retail loop codegen in func_0028c370. */
#pragma push
#pragma opt_loop_invariants on

// FUN_0028C370
void func_0028c370(void)
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
/* measured: restore pragma state after func_0028c370. */
#pragma pop
// FUN_0028CED0
void func_0028ced0(s32 arg0, s32 arg1, s32 arg2, f32 *arg3,
                   f32 *arg4, f32 *arg5) {
    s32 temp_3;

    if (arg0 < 3) {
        temp_3 = arg0 << 6;
        *(f32 *)((u8 *)D_00882218 + temp_3) = arg3[0];
        *(f32 *)((u8 *)D_0088221C + temp_3) = arg3[1];
        *(f32 *)((u8 *)D_00882220 + temp_3) = arg3[2];
        *(u32 *)((u8 *)D_00882224 + temp_3) = 0;
        *(f32 *)((u8 *)D_00882228 + temp_3) = arg4[0];
        *(f32 *)((u8 *)D_0088222C + temp_3) = arg4[1];
        *(f32 *)((u8 *)D_00882230 + temp_3) = arg4[2];
        *(f32 *)((u8 *)D_00882234 + temp_3) = arg4[3];
        *(f32 *)((u8 *)D_00882238 + temp_3) = arg5[0];
        *(f32 *)((u8 *)D_0088223C + temp_3) = arg5[1];
        *(f32 *)((u8 *)D_00882240 + temp_3) = arg5[2];
        *(u32 *)((u8 *)D_00882244 + temp_3) = 0x3F800000;
        *(s32 *)((u8 *)D_00882210 + temp_3) = arg1;
        if (arg1 == 3) {
            *(s32 *)((u8 *)D_00882214 + temp_3) = arg2;
            return;
        }
        *(s32 *)((u8 *)D_00882214 + temp_3) = 0;
    }
}
