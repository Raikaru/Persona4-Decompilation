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
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern void memset(void *dst, s32 value, s32 size);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
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

extern u8 *D_0076449C;
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void btlTargetClearRecord(u8 *);
extern s64 btlGetUID(void);
extern u32 datCalcRandomBelow(u32);
extern u32 iGpffffa0b8;
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern u16 D_008C024C[];
extern u16 D_008C024E[];
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001b; members 001b0930-001b0cc0 */

/* 564/576 bytes; sixteen resolved relocations; twelve zero alignment bytes.
 * Named unsigned address terms retain table ordering without signed overflow. */
/* Retail allocates the scan as found=v1, base=v0, i=a3. The second scan walks
   a `table` copy of `base`; that copy use keeps `base` a declared local
   instead of folding into its gp load temporary. `found` declared first and
   `base` second give retail's v1/v0 pair. In the owner, the measured
   `opt_common_subs off` keeps the scan's offset and table reloads separate. */
#pragma push
#pragma pop
// FUN_001B0930
/* Allocate and initialize a 0x458-byte action, then link it at the action-list head. */
u8 *btlActionCreate(void)
{
    u32 actionId;
    u8 *action;
    u8 *listHead;

    chkmemAllocSiteTag(&D_005F6FE8, 0x3A);
    action = (u8 *)(*jtbl_008873E8)(0x458, 0x40000);
    memset(action, 0, 0x458);
    btlTargetClearRecord(action + 0x38);
    *(s16 *)&((BtlAction *)action)->pendingState = 0;
    *(s16 *)&((BtlAction *)action)->state = 8;
    *(s64 *)&((BtlAction *)action)->uid = btlGetUID();
    if (iGpffffa0b8 >= 0x0FFFFFFFU) {
        iGpffffa0b8 = 1;
    }
    actionId = iGpffffa0b8;
    iGpffffa0b8 = actionId + 1;
    ((BtlAction *)action)->id = actionId;
    ((BtlAction *)action)->idleWeaponAnimTimer = -1;
    *(s16 *)&((BtlAction *)action)->unk_34[2] = (s16)datCalcRandomBelow(0x3C);
    *(s32 *)&((BtlAction *)action)->previous = 0;
    listHead = ((BtlBattleState *)iGpffffb3ac)->actions;
    if (listHead != NULL) {
        *(u8 * *)&((BtlAction *)listHead)->previous = action;
        *(u8 * *)&((BtlAction *)action)->next = ((BtlBattleState *)iGpffffb3ac)->actions;
    } else {
        *(u8 * *)&((BtlAction *)action)->next = NULL;
    }
    ((BtlBattleState *)iGpffffb3ac)->actions = action;
    ((BtlAction *)action)->oldState = ((BtlAction *)action)->currState;
    ((BtlAction *)action)->currState = 0;
    *(s32 *)&((BtlAction *)action)->stateTimer = 0;
    D_005F6E20[0](action);
    return action;
}

/* measured: compound field decrement preserves retail addiu/sh/andi order; normalized_diff 0 in the 400-byte retail window. */
// FUN_001B0A60
/* Apply expired state delays, run enabled updates, and unlink actions marked for release. */
void btlActionListUpdate(void)
{
    /* Typed action/unit/packet fields changed MWCC codegen (428B trial); retain the proven byte offsets for MATCH. */
    u8 *action;
    u16 delay;
    u16 pendingState;
    u16 flags;
    u8 *nextAction;
    u8 *nextNode;
    u8 *previousNode;
    s32 updateReady;
    u8 *base;

    base = (u8 *)iGpffffb3ac;
    action = *(u8 **)(base + 0x174);
    goto loop_check;
loop_body:
    nextAction = *(u8 **)(action + 0x450);
    updateReady = 1;
    if (*(u16 *)(action + 0xE) != 0) {
        delay = *(u16 *)(action + 0x12);
        if ((s32)delay > 0) {
            if ((*(u16 *)(action + 0x12) -= 1) != 0) goto decrement_not_zero;
            pendingState = *(u16 *)(action + 0xE);
            *(u16 *)(action + 0x10) = *(u16 *)(action + 0xC);
            *(u16 *)(action + 0xC) = pendingState;
            *(s32 *)(action + 0x1C) = 0;
            (*(void (**)(u8 *))((u8 *)D_005F6E20 + pendingState * 0xC))(action);
            *(u16 *)(action + 0xE) = 0;
            goto decrement_done;
decrement_not_zero:
            updateReady = 0;
decrement_done:
            ;
        }
    }
    if (updateReady != 0) {
        flags = *(u16 *)(action + 0x1A);
        if ((flags & 4) == 0) {
            if ((*(u16 *)(action + 0x18) & 1) != 0) {
                (*(void (**)(u8 *))((u8 *)D_005F6E20 + *(u16 *)(action + 0xC) * 0xC + 4))(action);
                *(s32 *)(action + 0x1C) += 2;
            } else if ((flags & 2) != 0) {
                nextNode = *(u8 **)(action + 0x450);
                if (nextNode != NULL) {
                    *(u8 **)(nextNode + 0x44C) = *(u8 **)(action + 0x44C);
                }
                previousNode = *(u8 **)(action + 0x44C);
                if (previousNode != NULL) {
                    *(u8 **)(previousNode + 0x450) = *(u8 **)(action + 0x450);
                } else {
                    *(u8 **)(iGpffffb3ac + 0x174) = *(u8 **)(action + 0x450);
                }
                (*jtbl_008873EC)(action);
            }
        }
    }
    action = nextAction;
loop_check:
    if (action != NULL) goto loop_body;
}

// FUN_001B0BF0
/* Unlink and free every action while preserving the next pointer across the release callback. */
void btlActionListDestroyAll(void)
{
    /* Typed action/unit/packet fields changed MWCC codegen (140B trial); retain the proven byte offsets for MATCH. */
    u8 *nextAction;
    u8 *previousAction;
    u8 *action;

    action = *(u8 **)(iGpffffb3ac + 0x174);
    goto loop_check;
loop_body:
    nextAction = *(u8 **)(action + 0x450);
    if (nextAction != NULL) {
        *(u8 **)(nextAction + 0x44C) = *(u8 **)(action + 0x44C);
    }
    previousAction = *(u8 **)(action + 0x44C);
    if (previousAction != NULL) {
        *(u8 **)(previousAction + 0x450) = *(u8 **)(action + 0x450);
    } else {
        *(u8 **)(iGpffffb3ac + 0x174) = *(u8 **)(action + 0x450);
    }
    (*jtbl_008873EC)(action);
    action = nextAction;
loop_check:
    if (action != NULL) goto loop_body;
}

/* measured: returning directly from the compare branch preserves retail's
   bne/branch-to-tail layout; the C object is 60B/64B with nd 0 and only the
   retail alignment nop remains. */
// FUN_001B0C80
/* Search the action list for the unit pointer; return NULL when no action owns it. */
u8 *btlActionFindByUnit(s32 unit)
{
    u8 *action;

    action = ((BtlBattleState *)iGpffffb3ac)->actions;
    goto check;
loop:
    if (*(s32 *)&((BtlAction *)action)->unit == unit) {
        return action;
    }
    action = *(u8 * *)&((BtlAction *)action)->next;
check:
    if (action != NULL) goto loop;
    return NULL;
}

/* measured: 0cc0 shares the pointer-chain branch shape above; only its
   compare-field displacement changes, with nd 0 in a 60B/64B object. */
// FUN_001B0CC0
/* Search the action list for its monotonically assigned ID; return NULL when absent. */
u8 *btlActionFindById(s32 id)
{
    u8 *action;

    action = ((BtlBattleState *)iGpffffb3ac)->actions;
    goto check;
loop:
    if (*(s32 *)&((BtlAction *)action)->id == id) {
        return action;
    }
    action = *(u8 * *)&((BtlAction *)action)->next;
check:
    if (action != NULL) goto loop;
    return NULL;
}

