#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"

#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "datUnit_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern s32 btlActionQueuePush(u8 *);
extern s32 btlOrderRemoveActionAll(u8 *);
extern u32 datCalcIsDead(s32, s32);
extern void (*jtbl_008873EC[])(void *);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];
extern s32 btlUnitIsMoving(u8 *);
extern void btlUnitGetAnchorPose(u8 *unit, u8 *outPosition, f32 *outRotation, f32 *outTarget);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
extern s64 btlPacketEnqueue(u8 *, u32);
extern void btlActionSetState(BtlAction *, u16);

extern u8 *D_0076449C;
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *);
extern u32 datCalcChkBadStatus(s32, u32);
extern void btlBossCollectTargets(u8 *);
extern u32 iGpffffa0b8;
s64 btlPacketEnqueue(u8 *, u32);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern BtlPacket *btlFormationCreatePacket(u32, u32, u32, u16, u32);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern BtlPacket *btlUnitCreateColorPacket(BtlUnit *, u32, s16, s16, u8, u8);
extern BtlPacket *btlSoundCreateChannelCuePacket(u16, u16, u16);
extern void btlUnitUnlinkAndFree(u8 *);
extern void func_001b08f0(void *);
extern void btlCameraReleaseActionRefs(u8 *);
extern u32 datCalcClearBadStatus(s32, u32);
extern void datCalcClearAllBuffs(u8 *);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;

/* Partial encounter-slot descriptor; both scans agree on the +4 data pointer
 * and the +A live bit. No allocation size is inferred from this prefix. */
typedef struct BtlEncounterEntry {
    u8 pad00[4];
    DatUnit *unitData;
    u16 unk08;
    u16 flags;
} BtlEncounterEntry;

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001b; members 001b0020-001b07c0 */

/* 564/576 bytes; sixteen resolved relocations; twelve zero alignment bytes.
 * Named unsigned address terms retain table ordering without signed overflow. */
/* measured: func_001b0020 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001B0020
/* Return a surviving, non-active unit to its anchor unless another return sequence owns the camera. */
void btlActionEndHomeInit(u8 *action)
{
    /* Typed action/unit/packet fields changed MWCC codegen (592B trial); retain the proven byte offsets for MATCH. */
    extern s32 btlActionGetActiveOrQueueFront(void);
    extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
        extern f32 btlTargetVectorDistance(const RwV3d *first, const RwV3d *second);
    extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *targetPos, f32 speed, u32 flags);
    extern u8 *iGpffffb3b8;
    extern u8 *iGpffffb3cc;
    extern f32 D_005F6D20[];
    RwV3d position;
    u8 *unit;
    u8 *packet;
    u16 speed;
    u16 side;
    u16 id;
    u8 kind;
    u32 table;
    u32 offset;
    u32 record;
    u32 selector;

    unit = *(u8 **)(action + 0x30);
    *(s32 *)(action + 0x41C) = 0;
    if (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) != 0) {
        if ((*(u32 *)(unit + 0x9C) & 0x40) != 0) {
            *(u32 *)(iGpffffb3ac + 0xC) |= 0x400000;
            *(u16 *)(iGpffffb3ac + 0x18) |= 6;
        }
        btlActionSetState((BtlAction *)action, 1);
        return;
    }
    if (action == (u8 *)btlActionGetActiveOrQueueFront()) {
        btlActionSetState((BtlAction *)action, 1);
        return;
    }
    if ((*(u32 *)(iGpffffb3ac + 0xC) & 0x400000) != 0 &&
        (*(u16 *)(iGpffffb3ac + 0x18) & 2) != 0) return;
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64), 0x180001) != 0) return;
    btlUnitGetAnchorPose(unit, (u8 *)&position, NULL, NULL);
    if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
        *(s32 *)(action + 0x41C) = 1;
    }
    if (!(btlTargetVectorDistance((const RwV3d *)(unit + 4), &position) <= 75.0f)) {
        speed = 2;
        side = !(iGpffffb3b8[*(u16 *)(action + 0x6E) * 0x28] & 2);
        id = *(u16 *)(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64) + 2);
        kind = *(u8 *)(*(u8 **)(action + 0x30) + 0xA2);
        switch (kind) {
        case 0: break;
        case 1:
            table = (u32)iGpffffb3cc;
            offset = (u32)id * 0xE8;
            record = offset + table;
            selector = side * 4;
            speed = *(u16 *)(selector + record + 0x24);
            break;
        }
        packet = (u8 *)btlUnitCreateMovePacket(*(BtlUnit **)(action + 0x30), &position, D_005F6D20[speed], 0);
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
        *(s32 *)(action + 0x41C) = 1;
    }
}

// FUN_001B0260
/* After movement completes, restore the anchor direction and enter the idle action state. */
void btlActionEndHomeUpdate(u8 *action)
{
    /* Typed action/unit/packet fields changed MWCC codegen (168B trial); retain the proven byte offsets for MATCH. */
    f32 direction[3];
    u8 *packet;

    if (btlUnitIsMoving(*(u8 **)(action + 0x30)) == 0) {
        if (*(s32 *)(action + 0x41C) == 1) {
            btlUnitGetAnchorPose(*(u8 **)(action + 0x30), NULL, NULL, direction);
            packet = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)(*(u8 **)(action + 0x30)), (const RwV3d *)(direction), (u32)(0));
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            btlPacketEnqueue(packet, 1);
        }
        btlActionSetState((BtlAction *)action, 1);
    }
}

// FUN_001B0300
/* Remove the defeated action from orders; clear party buffs or queue enemy removal effects. */
void btlActionDeadInit(u8 *action)
{
    /* Typed action/unit/packet fields changed MWCC codegen (360B trial); retain the proven byte offsets for MATCH. */
    u8 *unit;
    u8 genus;
    u8 *packet;
    s32 flags;
    s32 updatedFlags;

    unit = *(u8 **)(action + 0x30);
    btlOrderRemoveActionAll(action);
    genus = *(u8 *)(unit + 0xA2);
    switch (genus) {
    case 0:
        datCalcClearAllBuffs(*(u8 **)(unit + 0xA64));
        return;
    case 1:
        btlTargetRecordDefeatReward(action);
        flags = *(s32 *)(unit + 0x9C);
        if ((flags & 0x20) == 0 && (flags & 0x100) == 0) {
            packet = (u8 *)btlUnitCreateColorPacket((BtlUnit *)unit, 0xFFFFFF, 6, 0, 4, 0);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            btlPacketEnqueue(packet, 1);
            packet = (u8 *)btlFormationCreatePacket((u32)*(s32 *)(iGpffffb3ac + 0xD48), (u32)unit, (u32)unit, 0, 0);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            btlPacketEnqueue(packet, 2);
            packet = (u8 *)btlSoundCreateChannelCuePacket(0xA, 2, 0xA);
            *(s64 *)(packet + 0x60) = *(s64 *)action;
            btlPacketEnqueue(packet, 1);
        }
        updatedFlags = *(s32 *)(unit + 0x9C);
        if ((updatedFlags & 0x40) == 0 && (updatedFlags & 8) != 0) {
            *(s32 *)(unit + 0x9C) = updatedFlags & ~8;
        }
        return;
    default:
        return;
    }
}

// FUN_001B0460
/* Wait for revival of retained units, otherwise transition defeated enemies to exit. */
void btlActionDeadUpdate(u8 *action)
{
    /* Typed action/unit/packet fields changed MWCC codegen (316B trial); retain the proven byte offsets for MATCH. */
    u8 genus;
    u8 *unit;

    unit = *(u8 **)(action + 0x30);
    genus = *(u8 *)(unit + 0xA2);
    switch (genus) {
    case 0:
        if (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) == 0) {
            *(s32 *)(unit + 0x9C) &= ~1;
            btlActionQueuePush(action);
            if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
                btlBossCollectTargets((u8 *)btlActionGetQueueFront());
            }
            btlActionSetState((BtlAction *)action, 1);
        }
        break;
    case 1:
        if ((*(s32 *)(unit + 0x9C) & 0x40) == 0) {
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) == 0) {
            *(s32 *)(unit + 0x9C) &= ~1;
            btlActionQueuePush(action);
            btlActionSetState((BtlAction *)action, 1);
        }
        break;
    default:
        break;
    }
}

// FUN_001B0590
/* Clear the displayed-unit bit before an attached unit exits. */
void btlActionExitInit(u8 *action)
{
    s32 flags;
    u8 *unit;
    s32 *unitFlags;

    if (((BtlAction *)action)->unk_1a & 1) {
        unit = *(u8 * *)&((BtlAction *)action)->unit;
        unitFlags = (s32 *)(unit + 0x9C);
        flags = *unitFlags;
        if (flags & 8) {
            *unitFlags = flags & ~8;
        }
    }
}

/* Retail allocates the scan as found=v1, base=v0, i=a3. The second scan walks
   a `table` copy of `base`; that copy use keeps `base` a declared local
   instead of folding into its gp load temporary. `found` declared first and
   `base` second give retail's v1/v0 pair. In the owner, the measured
   `opt_common_subs off` keeps the scan's offset and table reloads separate. */
#pragma push
/* measured: func_001b05d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_001B05D0
/* Wait for unit packets, release encounter references and the unit, then mark the action for deletion. */
void btlActionExitUpdate(u8 *action)
{
    /* Typed encounter-slot indexing changed codegen (500B trial); retain offset-first C74/C94 table reads. */
    u8 *found;
    u8 *base;
    u8 *unit;
    u8 *entry;
    u16 slotIndex;
    s32 offset;
    u8 genus;
    u8 *table;

    if (((BtlAction *)action)->unk_1a & 1) {
        unit = *(u8 * *)&((BtlAction *)action)->unit;
        if (((BtlUnit *)unit)->pendingPacketCount != 0) {
            return;
        }
        genus = ((BtlUnit *)unit)->genus;
        switch (genus) {
        case 0:
            if (((BtlAction *)action)->flags & 0x20) {
                found = NULL;
                slotIndex = 0;
                base = (u8 *)iGpffffb3ac;
                while (slotIndex < 4U) {
                    offset = slotIndex * 4;
                    entry = *(u8 **)(base + offset + 0xC74);
                    if (entry != NULL) {
                        if (((BtlEncounterEntry *)entry)->unitData ==
                            ((BtlUnit *)unit)->datUnit) {
                            found = *(u8 **)(func_001bf3a0_add(offset, base) + 0xC74);
                            break;
                        }
                    }
                    slotIndex++;
                }
                if (found == NULL) {
                    table = base;
                    slotIndex = 0;
                    while (slotIndex < 3U) {
                        offset = slotIndex * 8;
                        entry = *(u8 **)(table + offset + 0xC94);
                        if (entry != NULL &&
                            ((BtlEncounterEntry *)entry)->unitData == ((BtlUnit *)unit)->datUnit) {
                            found = entry;
                            break;
                        }
                        slotIndex++;
                    }
                }
                if (found != NULL) {
                    ((BtlEncounterEntry *)found)->flags &= 0xFFFE;
                }
                datCalcClearBadStatus(*(s32 *)&((BtlUnit *)unit)->datUnit, 0xFFF7FFFF);
                datCalcClearAllBuffs(*(u8 * *)&((BtlUnit *)unit)->datUnit);
            }
            break;
        case 1:
            if (datCalcIsDead(*(s32 *)&((BtlUnit *)unit)->datUnit, 0) != 0) {
                datUnitRemoveEncounterUnit(*(DatUnitEc * *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->encounterRecord,
                              ((BtlUnit *)*(u8 * *)&((BtlAction *)action)->unit)->datUnit);
            }
            break;
        }
        btlUnitUnlinkAndFree(*(u8 * *)&((BtlAction *)action)->unit);
        *(u8 * *)&((BtlAction *)action)->unit = NULL;
        ((BtlAction *)action)->unk_1a &= 0xFFFE;
    }
    func_001b08f0(action);
    btlCameraReleaseActionRefs(action);
    ((BtlAction *)action)->unk_1a |= 2;
}

#pragma pop
// FUN_001B07C0
void btlActionTestInit(void)
{
}

