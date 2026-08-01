/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00291900)
/* Source unit: src/Event/mt_evtCustomEvent_00291900.c */
#include "type.h"

/* Ported from P3FES src/Event/mt_evtCustomEvent.c FUN_0039eb90 (verified MATCH
 * there). 003b5d10 -> func_00145270, 003b7090 -> func_00146630. */

extern u32 MT_Scene_GetRes(u32);
extern void func_00146630(u32);

// FUN_00291900
void func_00291900(void)
{
    int iVar3;
    u32 uVar1;
    u32 lVar2;

    for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
        uVar1 = iVar3 + 0x38eU & 0x3ff | 0xc00;
        lVar2 = MT_Scene_GetRes((u16)uVar1);
        if (lVar2 != 0) {
            func_00146630((u16)uVar1);
        }
    }
    return;
}
#endif /* P4_UNIT_00291900 */
