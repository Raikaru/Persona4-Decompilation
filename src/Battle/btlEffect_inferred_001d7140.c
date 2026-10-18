#include "btl_effect_internal.h"
#include "btl_target_state_packet_internal.h"
/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
extern void btlFormationSetPlacement(u32 input);
extern u8* DAT_0076449c;
extern void* (*jtbl_008873E8[])(u32 size, u32 align);
extern char D_00609558[];
extern void btlFormationResetState(u8* input);
extern void btlFormationCopyDefault(u8* input);
extern u8* btlFormationAllocEntry(u8* input, s32 value, s32 options, s32 flags, s32 mode);
extern void mdlEffectDestroyWithNodes(u32 input);
extern void mdlDestroyModelObject(u32 input);

/* Source unit: src/btlFormation/btlFormation_001d4120.c (8 function markers) */

/* Source unit: src/btlFormation/btlFormation_grouped.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/btlFormation/btlFormation_grouped.c; members 001d7140-001d7140 */

/* measured: live MATCH, object 372B/window 384B, normalized_diff 0; integer-domain global base plus source-driven addu operand order. */
/* Rebuild dirty visible placements from the selected formation slot, then apply visibility flags and packed color.
 * Raw offsets retained: Typed members change MWCC instruction selection/allocation; retain the proven byte offsets for the match. */
// FUN_001D7140
void btlEffectRefreshPlacementState(u8* placement)
{
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

    if ((*(u32*)((u8*)DAT_0076449c + 0xC) & 0x40000) != 0)
    {
        if ((*placement & 1) != 0)
        {
            node = *(u8**)(placement + 8);
            formationOrState = *(s32*)(node + 0x10);
            if (formationOrState != 0)
            {
                btlFormationResetState((u8*)formationOrState);
                *(s32*)(node + 0x10) = 0;
            }
            effect = *(s32*)(node + 0x14);
            if (effect != 0)
            {
                mdlEffectDestroyWithNodes((u32)effect);
                *(s32*)(node + 0x14) = 0;
            }
            model = *(s32*)(node + 0x18);
            if (model != 0)
            {
                mdlDestroyModelObject((u32)model);
                *(s32*)(node + 0x18) = 0;
            }
            *(s32*)(node + 4) = -1;
            *(s8*)(node + 8) = 0x14;
            *(s32*)(node + 0xC) = 0;
            *(u16*)(node + 0) = 0x200;
            oldFormation = *(s32*)(placement + 0xC);
            if (oldFormation != 0)
            {
                btlFormationSetPlacement((u32)oldFormation);
                *(s32*)(placement + 0xC) = 0;
            }
            slotIndex = *(s16*)(placement + 0x10);
            if (slotIndex != -1)
            {
                formationOrState = (s32)DAT_0076449c;
                slotOffset = slotIndex * 4;
                formation = *(s32*)((u8*)(slotOffset + formationOrState + 0xD04));
                *(s32*)(placement + 0xC) = formation;
                btlFormationCopyDefault((u8*)formation);
                unit = *(s32*)(placement + 4);
                *(s32*)(*(u8**)(placement + 8) + 0x10) =
                    (s32)btlFormationAllocEntry(*(u8**)(placement + 0xC), 1, unit, unit, 0);
            }
            *placement &= (u8)~1;
        }
        if (*(s16*)(placement + 0x10) != -1)
        {
            visibleNode = *(u8**)(placement + 8);
            *(u16*)visibleNode |= 0x30;
            *(s32*)(*(u8**)(placement + 8) + 4) = *(s32*)(placement + 0x14);
            return;
        }
        hiddenNode = *(u8**)(placement + 8);
        *(u16*)hiddenNode &= (u16)~0x30;
    }
}

