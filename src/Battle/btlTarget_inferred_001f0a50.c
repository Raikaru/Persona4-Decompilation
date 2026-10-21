#include "btl_target_internal.h"
#include "datCalc_unit_internal.h"
#include "list_item_internal.h"
#include "btl_camera_palette_internal.h"
#include "btl_skill_target_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "rw/plcore/barenderstate.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "sdk_snd_internal.h"
#include "btl_target_state_packet_internal.h"
#include "g_data_internal.h"


extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern u8 *iGpffffb3c4;
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *, s32, s32);


extern u8 D_0060AB08[];
extern u8 D_0060AC00[];
extern u8 D_00618AC0[];
extern u8 D_0061F000[];

extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern u8 *iGpffffb414;
extern s32 iGpffffb460;
extern u8 *D_0076449C;
extern u16 D_00624FC0[];
extern u16 D_00624FD8[];
extern u8 D_00624B20[];
extern u8 D_00624B22[];


extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];


extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

#pragma push
#pragma pop
/* Return 1 if any hit row of any of the action's targets has flag 4 set, otherwise 0. */
// FUN_001F0A50
/* Report whether any selected target has hit-row flag 4. */
s32 btlActionAnyTargetHitRowFlagged(u8 *action)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    u8 *target;

    i = 0;
    n = ((BtlAction *)action)->unk_6a;
    goto outer_test;
outer:
    target = (((BtlAction *)(action))->targets[(u16)i]);
    j = 0;
    innerCount = ((BtlAction *)target)->targetBlock.hitRowCount;
    goto inner_test;
inner:
    if ((((BtlAction *)target)->targetBlock.hitRows[(u16)j].flags & 4) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}

/* measured: loop-invariant hoisting places the retail mask load in the loop preheader; it stays
 * enabled for the following seven target predicates. */
#pragma opt_loop_invariants on
/* Return 1 if any hit row of any of the action's targets added status bit 0x100000, otherwise 0. */
// FUN_001F0AF0
/* Report whether any selected target has hit-row status bit 0x100000. */
s32 btlActionAnyTargetHitRowStatus(u8 *action)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    s32 mask;
    u8 *target;

    i = 0;
    n = ((BtlAction *)action)->unk_6a;
    mask = 0x100000;
    goto outer_test;
outer:
    target = (((BtlAction *)(action))->targets[(u16)i]);
    j = 0;
    innerCount = ((BtlAction *)target)->targetBlock.hitRowCount;
    goto inner_test;
inner:
    if (((s32)(((BtlAction *)target)->targetBlock.hitRows[(u16)j].addedStatus) & mask) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}

/* Return 1 if any of the action's targets has its special-hit flag set, otherwise 0. */
// FUN_001F0B90
/* The two 0xFFFF masks are spelled differently on purpose: retail masks the counter separately for
 * the index and the loop bound, and identical spellings merge into one. Reports whether any
 * selected target records a special hit. */
s32 btlActionAnyTargetSpecialHit(u8 *action) {
    s32 i;
    s32 n;

    i = 0;
    n = ((BtlAction *)action)->unk_6a;
    goto test;
loop:
    if ((((BtlAction *)((((BtlAction *)(action))->targets[(u16)i])))->targetBlock.specialHitFlag) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

/* Return 1 if any of the action's targets has target flag bit 1 or 2 set, otherwise 0. */
// FUN_001F0BF0
/* Like func_001f0b90, the index is masked as `(u16)i` and the bound as `i & 0xFFFF` so both of
 * retail's andi masks are kept. Reports whether any selected target has critical/weak hit flags. */
s32 btlActionAnyTargetFlagged(u8 *action) {
    s32 i;
    s32 n;

    i = 0;
    n = ((BtlAction *)action)->unk_6a;
    goto test;
loop:
    if (((((BtlAction *)((((BtlAction *)(action))->targets[(u16)i])))->targetBlock.targetFlags) & 6) != 0) {
        return 1;
    }
    i = (i + 1) & 0xFFFF;
test:
    if ((i & 0xFFFF) < n) {
        goto loop;
    }
    return 0;
}

/* Return 0 if any other target belongs to a different genus than the acting unit. Otherwise return
 * 1 if any of those targets has a hit row that restores HP or SP or removes a status, and 0 if none
 * does. */
// FUN_001F0C50
/* Require same-genus non-self targets and detect positive HP/SP or status-clear changes. */
s32 btlActionSameGenusTargetsHaveDelta(u8 *action)
{
    s32 result;
    s32 i;
    s32 n;
    u8 *target;
    s32 j;
    s32 innerCount;
    s32 one;

    result = 0;
    i = 0;
    n = ((BtlAction *)action)->unk_6a;
    one = 0x10000 >> 16;
    while ((i & 0xFFFF) < n) {
        target = (((BtlAction *)(action))->targets[(u16)i]);
        if (target != action) {
            if (((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->genus !=
                ((BtlUnit *)((u8 *)(((BtlAction *)target)->unit)))->genus) {
                return 0;
            }
            if (result == 0) {
                j = 0;
                innerCount = ((BtlAction *)target)->targetBlock.hitRowCount;
                while ((j & 0xFFFF) < innerCount) {
                    if ((((BtlAction *)(target))->targetBlock.hitRows[(u16)j].hpDelta) > 0) {
                        result = one;
                    }
                    if ((((BtlAction *)(target))->targetBlock.hitRows[(u16)j].spDelta) > 0) {
                        result = one;
                    }
                    if (((s32)(((BtlAction *)(target))->targetBlock.hitRows[(u16)j].removedStatus)) != 0) {
                        result = one;
                    }
                    j = (j + 1) & 0xFFFF;
                }
            }
        }
        i = (i + 1) & 0xFFFF;
    }
    return result;
}

/* measured: loop-invariant optimisation must stay on so the invariant mask's upper half is loaded
 * once before the loop, as in retail. */
/* Return 1 if any hit row on any of the action's targets removes the death status bit, otherwise 0. */
// FUN_001F0D30
/* Report whether any target hit row clears status bit 0x80000. */
s32 btlActionAnyTargetClearsDeathStatus(u8 *action)
{
    s32 i;
    s32 j;
    s32 n;
    s32 innerCount;
    s32 mask;
    u8 *target;

    i = 0;
    n = ((BtlAction *)action)->unk_6a;
    mask = 0x80000;
    goto outer_test;
outer:
    target = (((BtlAction *)(action))->targets[(u16)i]);
    j = 0;
    innerCount = ((BtlAction *)target)->targetBlock.hitRowCount;
    goto inner_test;
inner:
    if (((s32)(((BtlAction *)target)->targetBlock.hitRows[(u16)j].removedStatus) & mask) != 0) {
        return 1;
    }
    j = (j + 1) & 0xFFFF;
inner_test:
    if ((j & 0xFFFF) < innerCount) {
        goto inner;
    }
    i = (i + 1) & 0xFFFF;
outer_test:
    if ((i & 0xFFFF) < n) {
        goto outer;
    }
    return 0;
}

/* measured: loop-invariant hoisting stays on so retail keeps the nonzero-path constant and loop
 * preheaders in func_001f0dd0. */
// FUN_001F0DD0
/* Test target result rows for a negative HP change or status result, with mode-specific exclusions. */
s32 btlActionTargetsHaveDamageResult(u8 *action, s32 mode)
{
    /* Hit outcomes occupy the control halfword preceding the per-target hit rows. */
    s32 result;
    s32 one;
    s32 targetIndex;
    s32 rowIndex;
    s32 n;
    u8 *target;
    s32 innerCount;
    u8 *entry;
    s32 otherTargetIndex;
    s32 otherRowIndex;

    result = 0;
    if (mode == 0) {
        goto path_zero;
    }
targetIndex = 0;
n = ((BtlAction *)action)->unk_6a;
one = 1;
while ((targetIndex & 0xFFFF) < n) {
    target = (((BtlAction *)(action))->targets[(u16)targetIndex]);
    if (((BtlAction *)target)->targetBlock.specialHitFlag != 0) {
        result = 0;
        goto done;
    }
    if (((((BtlAction *)(target))->targetBlock.hitOutcome) & 0x500) != 0) {
        result = 0;
        goto done;
    }
    if (result == 0) {
        innerCount = ((BtlAction *)target)->targetBlock.hitRowCount;
        rowIndex = 0;
        goto inner_test_one;
inner_one:
        if (((BtlAction *)target)->targetBlock.hitRows[(u16)rowIndex].hpDelta < 0) {
            result = one;
            goto outer_step_one;
        }
        rowIndex = (rowIndex + 1) & 0xFFFF;
inner_test_one:
        if ((rowIndex & 0xFFFF) < innerCount) {
            goto inner_one;
        }
    }
outer_step_one:
    targetIndex = (targetIndex + 1) & 0xFFFF;
}
goto done;

path_zero:
    otherTargetIndex = 0;
    n = ((BtlAction *)action)->unk_6a;
    goto outer_test_zero;
outer_zero:
    target = (((BtlAction *)(action))->targets[(u16)otherTargetIndex]);
    if (((((BtlAction *)(target))->targetBlock.hitOutcome) & 0x106) != 0) {
        result = 1;
        goto done;
    }
    innerCount = ((BtlAction *)target)->targetBlock.hitRowCount;
    otherRowIndex = 0;
    goto inner_test_zero;
inner_zero:
    entry = target + ((u16)otherRowIndex << 5);
    if (((BtlAction *)entry)->targetBlock.hitRows[0].hpDelta == 0) {
        if ((s32)(((BtlAction *)entry)->targetBlock.hitRows[0].addedStatus) != 0) {
            result = 1;
            goto done;
        }
    } else if (((BtlAction *)entry)->targetBlock.hitRows[0].hpDelta < 0) {
        result = 1;
        goto done;
    }
    otherRowIndex = (otherRowIndex + 1) & 0xFFFF;
inner_test_zero:
    if ((otherRowIndex & 0xFFFF) < innerCount) {
        goto inner_zero;
    }
    otherTargetIndex = (otherTargetIndex + 1) & 0xFFFF;
outer_test_zero:
    if ((otherTargetIndex & 0xFFFF) < n) {
        goto outer_zero;
    }
done:
    return result;
}

// FUN_001F0F70
/* Report a special-hit target or target flags 0x500. */
u32 btlActionAnyTargetHasSpecialResult(u8 *action)
{
    /* Hit outcomes occupy the control halfword preceding the per-target hit rows. */
    u8 *target;
    s32 targetCount;
    s32 targetIndex;

    targetIndex = 0;
    targetCount = ((BtlAction *)action)->unk_6a;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = (((BtlAction *)(action))->targets[(u32)(u16)targetIndex]);
        if (((BtlAction *)target)->targetBlock.specialHitFlag != 0) {
            return 1;
        }
        if (((((BtlAction *)(target))->targetBlock.hitOutcome) & 0x500) != 0) {
            return 1;
        }
    }
    return 0;
}

