#include "list_item_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"

#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
#include "btl_action_internal.h"
typedef struct BtlPacket BtlPacket;
typedef struct BtlTarget BtlTarget;
extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 kind, u32 a, u32 b, u32 c);
static inline u8 *actionTargetPacketBytes(u8 *action, u16 kind, u32 a, u32 b, u32 c)
{
    return (u8 *)btlTargetCreateTargetPacket((u32)action, kind, a, b, c);
}
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
static inline void actionSetDelayBytes(u8 *action, s32 state, s32 delay)
{
    btlActionSetStateWithDelay((BtlAction *)action, (u16)state, (u16)delay);
}
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
static inline u8 *actionRotatePacketBytes(u8 *unit, void *rot, s32 flags)
{
    return (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, (const RwV3d *)rot, (u32)flags);
}
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
static inline u8 *actionRecoveryPacketBytes(BtlUnit *unit)
{
    return (u8 *)btlUnitCreateMotionSettlePacket(unit);
}
extern BtlPacket *btlPacketCreateEffectCounter(s32 unit, s32 message);
static inline void *actionMessagePacketBytes(s32 unit, s32 message)
{
    return btlPacketCreateEffectCounter(unit, message);
}
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

static inline s32 func_001a_add_offset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 func_001a_fix_var(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}



void btlActionFinishPresentation(BtlAction *action);
BtlPacket *btlFormationCreateSlotPacket(u16 arg0, u16 arg1);
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);

extern u8 *iGpffffb3b8;
u8 func_0023e1f0(u8 *unitData);
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *target, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
u8 *btlUnitCreateMotionRequestPacket(u8 *arg0, u16 arg1);
extern f32 fGpffff811c;
BtlPacket *btlMainCreateColorSetPacket(s32 arg0);
BtlPacket *btlEffectCreateReleasePacket(u16 mode);
u8 *btlPacketCreateFinishEffect(void);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
s32 btlEffectFindUnitMatchingCallback(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));

extern f32 D_0076144C;

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001a0140-001a05f0 */

// FUN_001A0140
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: func_001a0140 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 func_001a0140(u8 *arg0)
{
    s32 i0;
    u8 unitKind;

    unitKind = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    switch (unitKind) {
    case 0:
    {
        s32 j0;
        s32 n0;
        s32 count0;
        s32 mask0;
        u8 *target0;

        i0 = 0;
        n0 = *(u16 *)(arg0 + 0x6A);
        mask0 = 0x100000;
        goto outer0_test;
outer0_body:
        target0 = *(u8 **)(arg0 + ((u16)i0 * 4) + 0x38);
        count0 = target0[0xD9];
        j0 = 0;
        goto inner0_test;
inner0_body:
        if ((*(s32 *)(target0 + ((u16)j0 << 5) + 0xF8) & mask0) != 0) {
            return 1;
        }
        j0 = (j0 + 1) & 0xFFFF;
inner0_test:
        if ((j0 & 0xFFFF) < count0) {
            goto inner0_body;
        }
        i0 = (i0 + 1) & 0xFFFF;
outer0_test:
        if ((i0 & 0xFFFF) >= n0) {
            goto block_20;
        }
        goto outer0_body;
    }
    case 1:
    {
        s32 i1;
        s32 j1;
        s32 n1;
        s32 count1;
        u8 *target1;

        i1 = 0;
        n1 = *(u16 *)(arg0 + 0x6A);
        goto outer1_test;
outer1_body:
        target1 = *(u8 **)(arg0 + ((u16)i1 * 4) + 0x38);
        count1 = target1[0xD9];
        j1 = 0;
        goto inner1_test;
inner1_body:
        if ((*(u16 *)(target1 + ((u16)j1 << 5) + 0x10E) & 4) != 0) {
            return 1;
        }
        j1 = (j1 + 1) & 0xFFFF;
inner1_test:
        if ((j1 & 0xFFFF) < count1) {
            goto inner1_body;
        }
        i1 = (i1 + 1) & 0xFFFF;
outer1_test:
        if ((i1 & 0xFFFF) < n1) {
            goto outer1_body;
        }
        goto block_20;
    }
    default:
        goto block_20;
    }
block_20:
    return 0;
}

/* measured: close loop-invariant probe for 001A0140. */
// FUN_001A0290
void func_001a0290(BtlAction *action, u16 arg1, u8 *arg2)
{
    s32 slotOffset;
    s32 category;
    BtlUnit *battleUnit;

    if (action->flags & 0x4000) {
        *(s16 *)arg2 = 0x24;
        *(s16 *)(arg2 + 2) = -1;
        return;
    }
    *(s16 *)arg2 = 0;
    *(s16 *)(arg2 + 2) = 3;
    slotOffset = (arg1 & 0xFFFF) * 0x28;
    if (*(u8 *)(iGpffffb3b8 + slotOffset) & 2) {
        battleUnit = action->unit;
        if (battleUnit->genus == 0) {
            category = func_0023e1f0(*(u8 **)((u8 *)battleUnit + 0xA64)) & 0xFF;
            switch (category) {
            case 0:
            case 1:
            case 6:
                *(s16 *)arg2 = 1;
                *(s16 *)(arg2 + 2) = 4;
                return;
            case 5:
                *(s16 *)arg2 = 2;
                *(s16 *)(arg2 + 2) = 5;
                return;
            case 2:
            case 3:
            case 4:
                break;
            }
        } else {
            switch (battleUnit->charId) {
            case 0x109:
                *(s16 *)arg2 = 2;
                *(s16 *)(arg2 + 2) = 5;
                break;
            }
        }
    }
}

// FUN_001A03B0
void btlActionFinishPresentation(BtlAction *action)
{
    u8 *lookAtDeactivatePacket;
    u8 *ambientPacket;
    u8 *unitPacket;
    u8 *effectPacket;
    u8 *subPacket;
    u8 *cameraPacket;
    u8 *endPacket;
    u8 *battleCtxAlt;
    u8 *battleCtx;
    u8 *battleCtxClear;
    u8 *listUnit;

    battleCtx = D_0076449C;
    if (*(s32 *)(battleCtx + 0xC) & 0x400000) {
        if (*(u16 *)(battleCtx + 0x18) & 0x20) {
            lookAtDeactivatePacket = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3);
            *(s64 *)(lookAtDeactivatePacket + 0x60) = *(s64 *)action;
            btlPacketEnqueue(lookAtDeactivatePacket, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 2) {
            ambientPacket = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
            *(s64 *)(ambientPacket + 0x60) = *(s64 *)action;
            btlPacketEnqueue(ambientPacket, 0);
        }
        battleCtxAlt = D_0076449C;
        if (*(u16 *)(battleCtxAlt + 0x18) & 1) {
            listUnit = *(u8 **)(battleCtxAlt + 0x174);
            goto loop_test;
loop_body:
            if ((*(u16 *)(listUnit + 0x1A) & 1) &&
                datCalcIsDead(*(s32 *)(*(u8 **)(listUnit + 0x30) + 0xA64), 0) == 0) {
                unitPacket = btlUnitCreateMotionRequestPacket(*(u8 **)(listUnit + 0x30), 0);
                *(s64 *)(unitPacket + 0x60) = *(s64 *)action;
                btlPacketEnqueue(unitPacket, 0);
            }
            listUnit = *(u8 **)(listUnit + 0x450);
loop_test:
            if (listUnit != NULL) {
                goto loop_body;
            }
        }
        if (*(u16 *)(D_0076449C + 0x18) & 0x10) {
            effectPacket = (u8 *)btlMainCreateColorSetPacket(0);
            *(s64 *)(effectPacket + 0x60) = *(s64 *)action;
            btlPacketEnqueue(effectPacket, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 8) {
            subPacket = (u8 *)btlEffectCreateReleasePacket(5);
            *(s64 *)(subPacket + 0x60) = *(s64 *)action;
            btlPacketEnqueue(subPacket, 1);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 4) {
            cameraPacket = (u8 *)btlCameraCreateSetStatePacket(action, 0x24);
            *(s64 *)(cameraPacket + 0x60) = *(s64 *)action;
            btlPacketEnqueue(cameraPacket, 0);
        }
        if (*(u16 *)(D_0076449C + 0x18) & 0x40) {
            endPacket = btlPacketCreateFinishEffect();
            *(s64 *)(endPacket + 0x60) = *(s64 *)action;
            btlPacketEnqueue(endPacket, 0);
        }
        *(u16 *)(D_0076449C + 0x18) = 0;
        battleCtxClear = D_0076449C;
        *(s32 *)(battleCtxClear + 0xC) &= 0xFFBFFFFF;
    }
}

// FUN_001A05F0
s32 func_001a05f0(BtlAction *action) {
    u16 flags;
    u8 *unitState;

    flags = action->unk_1a;
    if (flags & 1) {
        goto cont1;
    }
    return 0;
cont1:
    unitState = *(u8 **)((u8 *)action->unit + 0xA0C);
    if (flags & 0x10) {
        goto cont2;
    }
    return 0;
cont2:
    return (*(s32 *)(unitState + 0x98) & 2) != 0;
}

