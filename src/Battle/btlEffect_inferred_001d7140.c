#include "btl_target_state_packet_internal.h"
/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
extern void btlFormationSetPlacement(u32 param_1);
extern u8* DAT_0076449c;
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern char D_00609558[];
extern void btlFormationResetState(u8* arg0);
extern void btlFormationCopyDefault(u8* arg0);
extern u8* btlFormationAllocEntry(u8* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00485b20(u32 arg0);
extern void mdlDestroyModelObject(u32 arg0);

/* Source unit: src/btlFormation/btlFormation_001d4120.c (8 function markers) */

/* Source unit: src/btlFormation/btlFormation_grouped.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/btlFormation/btlFormation_grouped.c; members 001d7140-001d7140 */

/* measured: live MATCH, object 372B/window 384B, normalized_diff 0; integer-domain global base plus source-driven addu operand order. */
// FUN_001D7140
void btlEffectRefreshPlacementState(u8* arg0)
{
    s16 temp_4_5;
    s32 temp_4;
    s32 temp_4_2;
    s32 temp_4_3;
    s32 temp_4_4;
    s32 temp_6;
    u8* temp_17;
    u8* temp_4_7;
    s32 temp_4_6;
    u8* temp_4_8;
    s32 temp_4_9;

    if ((*(u32*)((u8*)DAT_0076449c + 0xC) & 0x40000) != 0)
    {
        if ((*arg0 & 1) != 0)
        {
            temp_17 = *(u8**)(arg0 + 8);
            temp_4 = *(s32*)(temp_17 + 0x10);
            if (temp_4 != 0)
            {
                btlFormationResetState((u8*)temp_4);
                *(s32*)(temp_17 + 0x10) = 0;
            }
            temp_4_2 = *(s32*)(temp_17 + 0x14);
            if (temp_4_2 != 0)
            {
                func_00485b20((u32)temp_4_2);
                *(s32*)(temp_17 + 0x14) = 0;
            }
            temp_4_3 = *(s32*)(temp_17 + 0x18);
            if (temp_4_3 != 0)
            {
                mdlDestroyModelObject((u32)temp_4_3);
                *(s32*)(temp_17 + 0x18) = 0;
            }
            *(s32*)(temp_17 + 4) = -1;
            *(s8*)(temp_17 + 8) = 0x14;
            *(s32*)(temp_17 + 0xC) = 0;
            *(u16*)(temp_17 + 0) = 0x200;
            temp_4_4 = *(s32*)(arg0 + 0xC);
            if (temp_4_4 != 0)
            {
                btlFormationSetPlacement((u32)temp_4_4);
                *(s32*)(arg0 + 0xC) = 0;
            }
            temp_4_5 = *(s16*)(arg0 + 0x10);
            if (temp_4_5 != -1)
            {
                temp_4 = (s32)DAT_0076449c;
                temp_4_9 = temp_4_5 * 4;
                temp_4_6 = *(s32*)((u8*)(temp_4_9 + temp_4 + 0xD04));
                *(s32*)(arg0 + 0xC) = temp_4_6;
                btlFormationCopyDefault((u8*)temp_4_6);
                temp_6 = *(s32*)(arg0 + 4);
                *(s32*)(*(u8**)(arg0 + 8) + 0x10) =
                    (s32)btlFormationAllocEntry(*(u8**)(arg0 + 0xC), 1, temp_6, temp_6, 0);
            }
            *arg0 &= (u8)~1;
        }
        if (*(s16*)(arg0 + 0x10) != -1)
        {
            temp_4_7 = *(u8**)(arg0 + 8);
            *(u16*)temp_4_7 |= 0x30;
            *(s32*)(*(u8**)(arg0 + 8) + 4) = *(s32*)(arg0 + 0x14);
            return;
        }
        temp_4_8 = *(u8**)(arg0 + 8);
        *(u16*)temp_4_8 &= (u16)~0x30;
    }
}

