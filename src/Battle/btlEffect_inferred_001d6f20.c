/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
extern void btlEffectResetEntry(void* param_1);
extern void btlFormationSetPlacement(u32 param_1);
extern u8* DAT_0076449c;
extern void (*jtbl_008873EC[])(void* ptr);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern char D_00609558[];
extern void chkmemAllocSiteTag(const void* msg, s32 id);
extern void memset(void* dst, s32 value, u32 size);

/* Source unit: src/btlFormation/btlFormation_001d4120.c (8 function markers) */

/* Source unit: src/btlFormation/btlFormation_grouped.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/btlFormation/btlFormation_grouped.c; members 001d6f20-001d7040 */

// FUN_001D6F20
u8* btlEffectCreatePlacementEntry(s32 arg0)
{
    u8* temp_2;
    u8* temp_2_2;
    u8* temp_2_3;
    u32 table;

    chkmemAllocSiteTag(D_00609558, 0x48);
    table = (u32)jtbl_008873E8;
    temp_2 = (u8*)((void* (*)(u32, u32))*(u32*)table)(0x18, 0x40000);
    *(s32*)(temp_2 + 4) = arg0;
    *(s16*)(temp_2 + 0x10) = -1;
    *(s8*)(temp_2 + 0) = 0;
    *(s32*)(temp_2 + 0x14) = -1;
    *(s32*)(temp_2 + 0xC) = 0;
    chkmemAllocSiteTag(D_00609558, 0x51);
    temp_2_2 = (u8*)((void* (*)(u32, u32))*(u32*)table)(0x24, 0x40000);
    memset(temp_2_2, 0, 0x24);
    *(s32*)(temp_2_2 + 4) = -1;
    *(s8*)(temp_2_2 + 8) = 0x14;
    *(s32*)(temp_2_2 + 0xC) = 0;
    *(u16*)(temp_2_2 + 0) = 0x200;
    *(s32*)(temp_2_2 + 0x1C) = 0;
    temp_2_3 = *(u8**)((u8*)DAT_0076449c + 0x1B8);
    if (temp_2_3 != 0)
    {
        *(u8**)(temp_2_3 + 0x1C) = temp_2_2;
        *(u8**)(temp_2_2 + 0x20) = *(u8**)((u8*)DAT_0076449c + 0x1B8);
    }
    else
    {
        *(u8**)(temp_2_2 + 0x20) = 0;
    }
    *(u8**)((u8*)DAT_0076449c + 0x1B8) = temp_2_2;
    *(u8**)(temp_2 + 8) = temp_2_2;
    return temp_2;
}

// FUN_001D7040
void btlEffectDestroyPlacementEntry(u8* arg0)
{
    u8* temp_16;
    u8* temp_3;
    u8* temp_3_2;
    u32 temp_4;
    u32 table;

    temp_16 = *(u8**)(arg0 + 8);
    btlEffectResetEntry(temp_16);
    temp_3 = *(u8**)(temp_16 + 0x20);
    if (temp_3 != 0)
    {
        *(u8**)(temp_3 + 0x1C) = *(u8**)(temp_16 + 0x1C);
    }
    temp_3_2 = *(u8**)(temp_16 + 0x1C);
    if (temp_3_2 != 0)
    {
        *(u8**)(temp_3_2 + 0x20) = *(u8**)(temp_16 + 0x20);
    }
    else
    {
        *(u8**)((u8*)DAT_0076449c + 0x1B8) = *(u8**)(temp_16 + 0x20);
    }
    table = (u32)jtbl_008873EC;
    ((void (**)(void*))table)[0](temp_16);
    temp_4 = *(u32*)(arg0 + 0xC);
    if (temp_4 != 0)
    {
        btlFormationSetPlacement(temp_4);
        *(u32*)(arg0 + 0xC) = 0;
    }
    ((void (**)(void*))table)[0](arg0);
}

