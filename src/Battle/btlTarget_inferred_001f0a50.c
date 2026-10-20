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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f0a50-001f0f70 */

#pragma push
#pragma pop
// FUN_001F0A50
/* Report whether any selected target has hit-row flag 4. */
s32 btlActionAnyTargetHitRowFlagged(u8 *action)
{
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
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

/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: func_001f0af0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001F0AF0
/* Report whether any selected target has hit-row status bit 0x100000. */
s32 btlActionAnyTargetHitRowStatus(u8 *action)
{
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
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

/* measured: closes the invariant-hoist bracket for func_001f0af0. */
// FUN_001F0B90
/* The two 0xFFFF masks are spelled differently on purpose: retail re-masks
   the counter separately for the index and for the loop bound, and writing
   both as `i & 0xFFFF` lets b210 common-subexpression them into one andi
   (nd 57, one word short). */
/* Report whether any selected target records a special hit. */
s32 btlActionAnyTargetSpecialHit(u8 *action) {
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
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

// FUN_001F0BF0
/* Mask spelling as in func_001f0b90: `(u16)i` for the index and
   `i & 0xFFFF` for the bound, so b210 does not fold retail's two andi
   instructions into one. */
/* Report whether any selected target has critical/weak hit flags. */
s32 btlActionAnyTargetFlagged(u8 *action) {
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
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

/* measured: loop-invariant probe for func_001f0c50's shared true value. */
// FUN_001F0C50
/* Require same-genus non-self targets and detect positive HP/SP or status-clear changes. */
s32 btlActionSameGenusTargetsHaveDelta(u8 *action)
{
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
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

/* measured: close opt_loop_invariants after func_001f0c50 probe. */
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
// FUN_001F0D30
/* Report whether any target hit row clears status bit 0x80000. */
s32 btlActionAnyTargetClearsDeathStatus(u8 *action)
{
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
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

/* measured: closes the invariant-hoist bracket for func_001f0d30. */
/* measured: opt_loop_invariants on preserves the nonzero-path constant and loop preheaders for func_001f0dd0. */
// FUN_001F0DD0
/* Test target result rows for a negative HP change or status result, with mode-specific exclusions. */
s32 btlActionTargetsHaveDamageResult(u8 *action, s32 mode)
{
    /* Hit outcomes occupy the control halfword preceding the per-target hit rows. */
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
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

/* measured: close opt_loop_invariants after func_001f0dd0. */
// FUN_001F0F70
/* Report a special-hit target or target flags 0x500. */
u32 btlActionAnyTargetHasSpecialResult(u8 *action)
{
    /* Hit outcomes occupy the control halfword preceding the per-target hit rows. */
    /* Measured site, typed-local and stride forms changed retail code generation;
     * MEMBER names the proven field while preserving byte-pointer aliasing. */
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

