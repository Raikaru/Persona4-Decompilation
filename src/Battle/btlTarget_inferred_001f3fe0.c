#include "btl_action_internal.h"
#include "btl_effect_internal.h"
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
/* Force the offset operand into the first addu slot. */

/* Force the base operand into the first addu slot. */

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
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);



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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f3fe0-001f41e0 */

extern s32 btlActionAnyTargetHitRowStatus(u8 *action);
extern s32 btlActionSameGenusTargetsHaveDelta(u8 *action);
extern s32 btlActionAnyTargetClearsDeathStatus(u8 *action);
extern s32 btlActionTargetsHaveDamageResult(u8 *action, s32 mode);
extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlTargetGroupStateMatches(u8 *context);
extern s32 btlActionIsPendingBit(s32 context);
#pragma push
#pragma pop
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: closes the invariant-hoist bracket for func_001f0af0. */
/* measured: loop-invariant probe for func_001f0c50's shared true value. */
/* measured: close opt_loop_invariants after func_001f0c50 probe. */
/* measured: invariant mask materialisation needs opt_loop_invariants on to
   place the retail `lui` in the preheader. */
/* measured: closes the invariant-hoist bracket for func_001f0d30. */
/* measured: opt_loop_invariants on preserves the nonzero-path constant and loop preheaders for func_001f0dd0. */
/* measured: close opt_loop_invariants after func_001f0dd0. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
/* measured: opt_loop_invariants on preserves target loop preheaders and state materialisation. */
/* measured: close opt_loop_invariants after btlTargetGroupStateMatches probe. */
#pragma push
/* measured: normalized result/record snapshots need invariant motion for the retail 0x310 frame. */
#pragma pop
/* measured: opt_propagation off keeps the iGpffffb3b8 base load ahead of the
   index arithmetic and the 0x70 field load in a temporary before its saved copy. */
/* measured: restore propagation for the rest of the unit. */
/* Return the primary normal-party message, or -1 for another unit genus. */
// FUN_001F3FE0
s32 btlActionGetNormalStatePrimaryMsgCode(u8 *context)
{
    if (((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus != 0) {
        return -1;
    }
    return 0xCC;
}

/* Return the secondary normal-party message, or -1 for another unit genus. */
// FUN_001F4010
s32 btlActionGetNormalStateSecondaryMsgCode(u8 *context)
{
    if (((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus != 0) {
        return -1;
    }
    return 0x67;
}

/* Select the normal-party message according to the pending step-trigger bit. */
// FUN_001F4040
s32 btlActionGetPendingBitMsgCode(u8 *context) {
    if (((BtlAction *)context)->unit->genus != 0) {
        return -1;
    }
    if (btlActionIsPendingBit(0) != 0) {
        return 0xCD;
    }
    return 0xCE;
}

/* Map an enemy count from one through four to its message tier. */
// FUN_001F40A0
s32 btlActionGetRollTierMsgCode(void) {
    s32 enemyCount;

    enemyCount = func_001ef720(2, 0x80000) & 0xFFFF;
    if (enemyCount >= 5) {
        return -1;
    }
    if (enemyCount == 0) {
        return -1;
    }
    return 0x58 - enemyCount;
}

/* Map eligible party character ids to their status-message codes. */
// FUN_001F4100
s32 btlActionGetStatusMsgCode(u8 *action)
{
    u16 characterId;
    u8 *unit;

    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    characterId = ((BtlUnit *)unit)->charId;
    switch (characterId) {
    case 1:
        return -1;
    case 2:
        return 0x15F;
    case 3:
        return 0x160;
    case 4:
        return 0x161;
    case 6:
        return 0x162;
    case 7:
        return 0x163;
    case 8:
        return 0x164;
    default:
        return -1;
    }
}

/* Return the tertiary normal-party message, or -1 for another unit genus. */
// FUN_001F41B0
s32 btlActionGetNormalStateTertiaryMsgCode(u8 *context)
{
    if (((BtlUnit *)(u8 *)((BtlAction *)context)->unit)->genus != 0) {
        return -1;
    }
    return 0xCB;
}

/* Map an enemy count from two through five to its message band. */
// FUN_001F41E0
s32 btlActionGetRollTierBandMsgCode(void) {
    s32 enemyCount;

    enemyCount = func_001ef720(2, 0x80000) & 0xFFFF;
    if (enemyCount > 5) {
        return -1;
    }
    if (enemyCount < 2) {
        return -1;
    }
    return 0x5E - enemyCount;
}

