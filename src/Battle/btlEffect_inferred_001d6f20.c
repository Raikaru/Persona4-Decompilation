#include "btl_effect_internal.h"
/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
extern void btlEffectResetEntry(void* input);
extern void btlFormationSetPlacement(u32 input);
extern u8* DAT_0076449c;
extern void (*jtbl_008873EC[])(void* ptr);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern char D_00609558[];
extern void chkmemAllocSiteTag(const void* msg, s32 id);
extern void memset(void* dst, s32 value, u32 size);

/* Source unit: src/btlFormation/btlFormation_001d4120.c (8 function markers) */

/* Source unit: src/btlFormation/btlFormation_grouped.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/btlFormation/btlFormation_grouped.c; members 001d6f20-001d7040 */

/* Allocate a 0x18-byte placement and its fade node, initialize the hidden slot, and link the node globally.
 * Raw offsets retained: Member access changes MWCC code generation; retain the proven offsets and original access types. */
// FUN_001D6F20
u8* btlEffectCreatePlacementEntry(s32 unit)
{
    u8* placement;
    u8* node;
    u8* head;
    u32 table;

    chkmemAllocSiteTag(D_00609558, 0x48);
    table = (u32)jtbl_008873E8;
    placement = (u8*)((void* (*)(u32, u32))*(u32*)table)(0x18, 0x40000);
    ((BtlEffectPlacement *)placement)->unit = unit;
    ((BtlEffectPlacement *)placement)->slotIndex = -1;
    *(s8*)&((BtlEffectPlacement *)placement)->flags = 0;
    *(s32*)&((BtlEffectPlacement *)placement)->color = -1;
    *(s32*)&((BtlEffectPlacement *)placement)->formation = 0;
    chkmemAllocSiteTag(D_00609558, 0x51);
    node = (u8*)((void* (*)(u32, u32))*(u32*)table)(0x24, 0x40000);
    memset(node, 0, 0x24);
    *(s32*)&((BtlEffectNode *)node)->color = -1;
    *(s8*)&((BtlEffectNode *)node)->fadeStep = 0x14;
    *(s32*)&((BtlEffectNode *)node)->counter = 0;
    ((BtlEffectNode *)node)->flags = 0x200;
    *(s32*)&((BtlEffectNode *)node)->previous = 0;
    head = *(u8**)((u8*)DAT_0076449c + 0x1B8);
    if (head != 0)
    {
        *(u8**)&((BtlEffectNode *)head)->previous = node;
        *(u8**)&((BtlEffectNode *)node)->next = *(u8**)((u8*)DAT_0076449c + 0x1B8);
    }
    else
    {
        *(u8**)&((BtlEffectNode *)node)->next = 0;
    }
    *(u8**)((u8*)DAT_0076449c + 0x1B8) = node;
    *(u8**)&((BtlEffectPlacement *)placement)->node = node;
    return placement;
}

/* Reset and unlink the placement's node, release its optional formation, and free both allocations.
 * Raw offsets retained: Typed members change MWCC instruction selection/allocation; retain the proven byte offsets for the match. */
// FUN_001D7040
void btlEffectDestroyPlacementEntry(u8* placement)
{
    u8* node;
    u8* next;
    u8* previous;
    u32 formation;
    u32 table;

    node = *(u8**)(placement + 8);
    btlEffectResetEntry(node);
    next = *(u8**)(node + 0x20);
    if (next != 0)
    {
        *(u8**)(next + 0x1C) = *(u8**)(node + 0x1C);
    }
    previous = *(u8**)(node + 0x1C);
    if (previous != 0)
    {
        *(u8**)(previous + 0x20) = *(u8**)(node + 0x20);
    }
    else
    {
        *(u8**)((u8*)DAT_0076449c + 0x1B8) = *(u8**)(node + 0x20);
    }
    table = (u32)jtbl_008873EC;
    ((void (**)(void*))table)[0](node);
    formation = *(u32*)(placement + 0xC);
    if (formation != 0)
    {
        btlFormationSetPlacement(formation);
        *(u32*)(placement + 0xC) = 0;
    }
    ((void (**)(void*))table)[0](placement);
}

