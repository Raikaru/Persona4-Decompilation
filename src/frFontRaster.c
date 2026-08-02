#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"

// Ported from P3FES FUN_003b3d60 (verified MATCH there). Calls use the
// donor's implicit old-style declarations (FUN_003b3e00_raw/FUN_003b3e60_raw)
// so the arguments are passed without prototype-driven zero-extension.

// FUN_00275A60
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00275a60);

// FUN_00275BD0
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00275bd0);

// FUN_00275C00
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00275c00);

// FUN_00275D80
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00275d80);
// FUN_002761F0
u32 func_002761f0(u32 param_1, u32 param_2, u32 param_3)
{
    u32 result;

    result = FUN_003b3e00_raw(param_1, param_3);
    if (result == 0) {
        result = FUN_003b3e60_raw(param_1, param_2, param_3);
        if (result == 0) {
            result = 0;
        }
    }

    return result;
}

// Ported from P3FES FUN_003b3dd0 (verified MATCH there). Call uses the
// donor's implicit old-style declaration (FUN_003b3e00_typed).

// FUN_00276260
u32 func_00276260(u32 param_1, int param_2)
{
    u32 result;

    result = FUN_003b3e00_typed(param_1, param_2);
    if (result == 0) {
        result = 0;
    }

    return result;
}

// Ported from P3FES FUN_003b3e00 (verified MATCH there). The goto shape is
// the donor's exact loop layout: test entry!=0 first, then walk entry[6].

extern u8 *D_007645b8;
#define iGpffffb954 D_007645b8

// FUN_00276290
u32 func_00276290(u32 param_1, int param_2)
{
    u32 *entry;

    entry = *(u32 **)(iGpffffb954 + 8);
    goto check;
body:
    if (entry[1] != param_1) {
        goto next;
    }
    if (*(s16 *)((u8 *)entry + 8) != param_2) {
        goto next;
    }
    *(u16 *)((u8 *)entry + 10) = 1;
    entry[0] |= 1;
    goto done;
next:
    entry = (u32 *)entry[6];
check:
    if (entry != 0) {
        goto body;
    }
    entry = 0;
done:
    return (u32)entry;
}

// FUN_002762F0
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_002762f0);

// FUN_00276420
INCLUDE_ASM("asm/nonmatchings/frFontRaster", func_00276420);