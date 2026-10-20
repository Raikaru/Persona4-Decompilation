#include "btl_effect_internal.h"
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
extern void btlEffectResetEntry(void* node);
extern void btlFormationSetPlacement(u32 formation);
extern u8* DAT_0076449c;
extern void (*jtbl_008873EC[])(void* ptr);
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern char D_00609558[];
extern void chkmemAllocSiteTag(const void* file, s32 line);
extern void memset(void* dst, s32 value, u32 size);

/* Allocate a 0x18-byte placement and its fade node, initialize the hidden slot, and link the node globally. */
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
    head = *(u8* *)&((BtlBattleState *)((u8*)DAT_0076449c))->effectNodes;
    if (head != 0)
    {
        *(u8**)&((BtlEffectNode *)head)->previous = node;
        *(u8**)&((BtlEffectNode *)node)->next = *(u8* *)&((BtlBattleState *)((u8*)DAT_0076449c))->effectNodes;
    }
    else
    {
        *(u8**)&((BtlEffectNode *)node)->next = 0;
    }
    *(u8* *)&((BtlBattleState *)((u8*)DAT_0076449c))->effectNodes = node;
    *(u8**)&((BtlEffectPlacement *)placement)->node = node;
    return placement;
}

/* Reset and unlink the placement's node, release its optional formation, and free both allocations. */
// FUN_001D7040
void btlEffectDestroyPlacementEntry(u8* placement)
{
    BtlEffectNode *nodeState;
    BtlEffectPlacement *placementState = (BtlEffectPlacement *)(placement);
    u8* node;
    u8* next;
    u8* previous;
    u32 formation;
    u32 table;

    node = *(u8* *)&((BtlEffectPlacement *)(placement))->node;
    nodeState = (BtlEffectNode *)(node);
    btlEffectResetEntry(node);
    next = *(u8* *)&((BtlEffectNode *)(node))->next;
    if (next != 0)
    {
        *(u8* *)&((BtlEffectNode *)(next))->previous = *(u8* *)&((BtlEffectNode *)(node))->previous;
    }
    previous = *(u8* *)&((BtlEffectNode *)(node))->previous;
    if (previous != 0)
    {
        *(u8* *)&((BtlEffectNode *)(previous))->next = *(u8* *)&nodeState->next;
    }
    else
    {
        *(u8* *)&((BtlBattleState *)((u8*)DAT_0076449c))->effectNodes = *(u8* *)&nodeState->next;
    }
    table = (u32)jtbl_008873EC;
    ((void (**)(void*))table)[0](node);
    formation = *(u32 *)&((BtlEffectPlacement *)(placement))->formation;
    if (formation != 0)
    {
        btlFormationSetPlacement(formation);
        *(u32 *)&placementState->formation = 0;
    }
    ((void (**)(void*))table)[0](placement);
}

