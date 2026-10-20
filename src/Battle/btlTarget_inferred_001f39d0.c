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





extern s32 btlTargetConsumeActionCost(u8 **actionPacket);

extern s32 datItemCount(s16 itemId);
extern s32 datCalcAddHp(DatUnit *unit, s32 hpDelta);
extern s32 datCalcAddSp(DatUnit *unit, s32 spDelta);
extern u32 datCalcSkillCost(u8 *unit, s32 skillId);

extern s32 iGpffffb464;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f39d0-001f39d0 */

extern s32 btlActionAnyTargetHitRowStatus(u8 *action);
extern s32 btlActionSameGenusTargetsHaveDelta(u8 *action);
extern s32 btlActionAnyTargetClearsDeathStatus(u8 *action);
extern s32 btlActionTargetsHaveDamageResult(u8 *action, s32 mode);
extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlTargetGroupStateMatches(u8 *context);
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
/* Consume HP/SP skill cost or one inventory item for the action held by the packet. */
/* measured: the remaining cost-record reloads changed MATCH when replaced with BtlUnit.datUnit fields. */
// FUN_001F39D0
/* measured: opt_propagation off keeps the iGpffffb3b8 base load ahead of the
   index arithmetic and the 0x70 field load in a temporary before its saved copy. */
/* measured: func_001f39d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
s32 btlTargetConsumeActionCost(u8 **actionPacket) {
    u8 *action;
    u16 skillId;
    u8 *unit;
    s32 cost;
    u16 actionKind;
    u8 costKind;
    s32 off;
    u8 *base;
    u8 *ptr;
    s16 itemId;

    action = *actionPacket;
    unit = (u8 *)((BtlAction *)action)->unit;
    actionKind = ((BtlAction *)action)->unk_6c;
    switch (actionKind) {
    case 2:
        skillId = ((BtlAction *)action)->unk_6e;
        cost = datCalcSkillCost((u8 *)((BtlUnit *)unit)->datUnit, skillId);
        if (cost != 0) {
            base = iGpffffb3b8;
            off = (s32)((skillId & 0xFFFF) * 0x28);
            ptr = (u8 *)(off + (s32)base);
            costKind = ptr[3];
            switch (costKind) {
            case 1:
                datCalcAddHp((DatUnit *)*(s32 *)(unit + 0xA64), -cost);
                break;
            case 2:
                datCalcAddSp((DatUnit *)*(s32 *)(unit + 0xA64), -cost);
                break;
            }
        }
        break;
    case 3:
        if (((BtlUnit *)unit)->genus == 0) {
            actionKind = ((BtlActionParameters *)((BtlAction *)action)->unk_70)->item;
            itemId = (s16)actionKind;
            datItemSetCount(itemId, ((datItemCount((s16)actionKind) & 0xFF) - 1) & 0xFF);
        }
        break;
    case 9:
    case 1:
        break;
    }
    return 1;
}

