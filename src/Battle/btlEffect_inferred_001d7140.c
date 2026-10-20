#include "btl_effect_internal.h"
#include "btl_target_state_packet_internal.h"
/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
extern void btlFormationSetPlacement(u32 formation);
extern u8* DAT_0076449c;
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern char D_00609558[];
extern void btlFormationResetState(u8* work);
extern void btlFormationCopyDefault(u8* formation);
extern u8* btlFormationAllocEntry(u8* table, s32 tableIndex, s32 unit, s32 target, s32 flags);
extern void mdlEffectDestroyWithNodes(u32 effect);
extern void mdlDestroyModelObject(u32 model);

/* Source unit: src/btlFormation/btlFormation_001d4120.c (8 function markers) */

/* Source unit: src/btlFormation/btlFormation_grouped.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/btlFormation/btlFormation_grouped.c; members 001d7140-001d7140 */

/* measured: live MATCH, object 372B/window 384B, normalized_diff 0; integer-domain global base plus source-driven addu operand order. */
/* Rebuild dirty visible placements from the selected formation slot, then apply visibility flags and packed color. */
// FUN_001D7140
void btlEffectRefreshPlacementState(u8* placement)
{
    BtlEffectNode *nodeState;
    BtlEffectPlacement *placementState = (BtlEffectPlacement *)(placement);
    s16 slotIndex;
    s32 formationOrState;
    s32 effect;
    s32 model;
    s32 oldFormation;
    s32 unit;
    u8* node;
    u8* visibleNode;
    s32 formation;
    u8* hiddenNode;
    s32 slotOffset;

    if ((((BtlBattleState *)((u8*)DAT_0076449c))->flags & 0x40000) != 0)
    {
        if ((*placement & 1) != 0)
        {
            node = *(u8* *)&((BtlEffectPlacement *)(placement))->node;
            nodeState = (BtlEffectNode *)(node);
            formationOrState = *(s32 *)&((BtlEffectNode *)(node))->formation;
            if (formationOrState != 0)
            {
                btlFormationResetState((u8*)formationOrState);
                *(s32 *)&nodeState->formation = 0;
            }
            effect = *(s32 *)&((BtlEffectNode *)(node))->effect;
            if (effect != 0)
            {
                mdlEffectDestroyWithNodes((u32)effect);
                *(s32 *)&nodeState->effect = 0;
            }
            model = *(s32 *)&((BtlEffectNode *)(node))->model;
            if (model != 0)
            {
                mdlDestroyModelObject((u32)model);
                *(s32 *)&nodeState->model = 0;
            }
            *(s32 *)&((BtlEffectNode *)(node))->color = -1;
            *(s8 *)&((BtlEffectNode *)(node))->fadeStep = 0x14;
            *(s32 *)&((BtlEffectNode *)(node))->counter = 0;
            ((BtlEffectNode *)(node))->flags = 0x200;
            oldFormation = *(s32 *)&((BtlEffectPlacement *)(placement))->formation;
            if (oldFormation != 0)
            {
                btlFormationSetPlacement((u32)oldFormation);
                *(s32 *)&placementState->formation = 0;
            }
            slotIndex = ((BtlEffectPlacement *)(placement))->slotIndex;
            if (slotIndex != -1)
            {
                formationOrState = (s32)DAT_0076449c;
                slotOffset = slotIndex * 4;
                formation = *(s32 *)&((BtlBattleState *)((u8 *)(slotOffset + formationOrState)))->formations[0];
                *(s32 *)&placementState->formation = formation;
                btlFormationCopyDefault((u8*)formation);
                unit = ((BtlEffectPlacement *)(placement))->unit;
                *(s32 *)&((BtlEffectNode *)(*(u8* *)&placementState->node))->formation =
                    (s32)btlFormationAllocEntry(placementState->formation, 1, unit, unit, 0);
            }
            *placement &= (u8)~1;
        }
        if (((BtlEffectPlacement *)(placement))->slotIndex != -1)
        {
            visibleNode = *(u8* *)&((BtlEffectPlacement *)(placement))->node;
            *(u16*)visibleNode |= 0x30;
            *(s32 *)&((BtlEffectNode *)(*(u8* *)&((BtlEffectPlacement *)(placement))->node))->color = *(s32 *)&((BtlEffectPlacement *)(placement))->color;
            return;
        }
        hiddenNode = *(u8* *)&((BtlEffectPlacement *)(placement))->node;
        *(u16*)hiddenNode &= (u16)~0x30;
    }
}

