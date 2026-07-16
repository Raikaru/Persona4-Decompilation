/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0025C6D0)
/* Source unit: src/Kosaka/k_command_0025c6d0.c (1 function markers) */
#include "type.h"

extern s32 func_0029cc00(s32 index);
extern void func_0026bc10(u16 resourceId, u8 value);

// FUN_0025C6D0
u32 func_0025c6d0(void)
{
    s32 rawResourceId;
    u16 resourceId;
    s32 value;

    rawResourceId = func_0029cc00(0);
    value = func_0029cc00(1);
    resourceId = (u16)(rawResourceId & 0x3ff) | 0x400;
    func_0026bc10(resourceId, (u8)value);
    return 1;
}
#endif /* P4_UNIT_0025C6D0 */
