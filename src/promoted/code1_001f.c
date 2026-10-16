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
#include "datPersona_internal.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
    return offset + base;
}

/* Force the base operand into the first addu slot. */
static inline u32 addBaseFirst(u32 base, u32 offset) {
    return base + offset;
}
static inline s32 promoteS16(s16 value) {
    return value;
}
static inline u32 addOffsetAfterBase(u32 base, u32 offset) {
    return offset + base;
}

extern RwRenderState D_00625210[];
typedef s32 (*BattleRenderStateFunction)(RwRenderState state, void *value);
extern BattleRenderStateFunction D_00887300[];
extern BattleRenderStateFunction D_00887304[];
extern void func_001fb480(f32 scale, u8 *arg0, s32 arg1, s32 arg2, u8 *arg3);
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern void func_00122640(s32 arg0, s32 arg1);
extern s32 fadeStatus(void);
extern void btlPanelDrawCircle(u8 *unused, f32 scaleX, f32 scaleY, f32 depth, s32 color);
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern s32 kwlnGetCamera(void);
extern void func_0045c870(u8 *arg0, s32 arg1);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern s32 datCalcGetBadStatus(s32 arg0);
extern s32 func_00243ce0(s32 arg0);
extern u8 *iGpffffb3c4;
extern s32 datCalcGetHp(u8 *arg0);
extern s32 datCalcGetSp(u8 *arg0);
extern s32 datCalcMaxHp(u8 *arg0);
extern u16 datCalcMaxSp(u8 *arg0);
extern s32 datCalcGetBadStatusNoDown(u8 *arg0);
extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern s32 datTestBitmapBit(s32 arg0, s32 arg1);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern s32 btlActionRunTargetCallback(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void btlSoundCancelPlayback();
extern void btlActionStepMessagePhase();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);
extern s32 sdkSndIsChannelPlaying(s32 arg0);

extern void memset(void *destination, s32 value, u32 size);

extern s32 btlSideAverageBattleStat(s32 arg0, s32 arg1, s32 arg2);

extern u32 datCalcRandomBelow();
extern s32 datCalcEnemyExp(s32 arg0);
extern s32 func_002439c0(s32 arg0);
extern u16 datCalcPickWeightedSkill(u8 *arg0, s32 *arg1);
extern void kAssertFail(void *arg0, s32 arg1);
extern u8 D_0060AB08[];
extern void sdkSndPlayCue(s32 arg0, s32 arg1);
extern s16 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s32 arg0);
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
extern s32 btlSoundLoadPlaybackFile(u8 *arg0);
extern u8 D_00624B20[];
extern u8 D_00624B22[];
extern s32 btlCurrentUnitId(void);
extern void sdkSndResetChannel(s32 arg0, s32 arg1);
extern s32 sdkSndStopMainChannel(void);

extern void H_Cdvd_Destroy(u8 *arg0);
extern void datCalcClearFlaggedBuffs(s32 arg0);
extern void sdkSndFadeOutChannelFrames(s32 arg0, s32 arg1, s32 arg2);
extern void fclMiscSetDoneFlag(void);

extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);
extern void fclMiscPruneGlobal(void);
extern void fclMiscStopAndClose(void);
extern s32 btlUnitStatusWindowShow(u8 *arg0, s16 arg1);
extern s32 btlTaskSlotIsLinked(s32 arg0);
extern s32 btlSoundLoadPoll(s32 *arg0);
extern s32 btlSoundStopStep(void);
extern s32 btlSoundReleaseStep(void);
extern s32 btlTaskSlotIsSet(void);
extern s32 taskRecordIsDone(s32 arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern void datCalcClearStatusBlocked(s32 arg0);
extern void datCalcSetHp(s32 arg0, s32 arg1);
extern void datCalcClearBadStatus(s32 arg0, s32 arg1);
extern void datCalcSetBadStatus(s32 arg0, s32 arg1);

extern void mdlEffectDestroyWithNodes(s32 arg0);
extern void func_00486180(s32 arg0);
extern void func_00120f20(s32 arg0);
extern s32 func_00122520(s32 arg0, s32 arg1);
extern void H_Fade_SetCustomColor(s32 arg0, s32 arg1, s32 arg2);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void func_001fa490(void);
extern s32 btlCdvdLoadPoll(void);
extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];
extern s32 kwlnTaskGetTaskByName(void *arg0);

extern s32 hFadeTaskUpdate(u8 *arg0);


extern void btlTargetAdvanceWorkPtr(u8 **arg0);
extern u16 datPersonaGetRecordId(u16 arg0);
extern s32 datPersonaFindSkillSlot(u8 *persona, u16 skill);
extern s32 btlTargetClearFlaggedBuffs(u8 **arg0);
extern void btlTargetAdvanceWorkCount(void);
extern u8 *btlPacketAlloc(s32 type, s32 workSize);

extern void btlTargetRewindWorkPtr(u8 **arg0);

extern s32 func_001f39d0(u8 **arg0);
extern void btlTargetRewindWorkCount(void);

extern s32 btlSoundMarkSlotReady(u8 **arg0);
extern s32 datItemCount(s16 arg0);
extern s32 datCalcAddHp(s32 arg0, s32 arg1);
extern s32 datCalcAddSp(s32 arg0, s32 arg1);
extern u32 datCalcSkillCost(u8 *arg0, s32 arg1);

extern s32 btlSoundClearSlotReady(u8 **arg0);
extern s32 iGpffffb464;
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void sprintf(void *dst, void *fmt, ...);
extern s32 H_Cdvd_StartStreamLoad(s32 arg0, void *arg1, s32 arg2, void *arg3);
extern s32 func_004c7ef8(s32 arg0);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];

extern s32 func_001f0950(s32 arg0, s32 arg1);



#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_rebuildconditionals on
#pragma pop



#pragma opt_loop_invariants on
#pragma opt_loop_invariants off


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

extern s32 btlSoundPickStatusTalkVoiceA(u8 *arg0);
extern void btlSoundResetSlotQueue(void);
/* measured: compiler residual in call argument materialization. Committed at nd 3. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
#pragma optimization_level 1
// FUN_001F0FF0
s32 btlActionHasNoTargetClass(u32 arg0)
{
    s32 index;
    index = *(u16 *)(arg0 + 0x6E);
    return (btlSkillClassifyTargets((u8 *)arg0, 0, index, 0) & 0xFFFF) == 0;
}
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma optimization_level 2

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_pulloutconstants off

#pragma pop

#pragma opt_propagation off
#pragma opt_propagation on














extern u32 datCalcIsLowHp(s32 unit);
extern u8 *btlActionFindByUnit(s32 arg0);
#pragma push
#pragma opt_propagation off
#pragma opt_propagation on
#pragma pop











/* 728/736 bytes; thirteen resolved code relocations and seven jump-table
 * entries; eight zero tail bytes. Preserve eligibility-argument timing. */
struct EffRandState;

static inline s32 battleMessageBand(s32 value, s32 band)
{
    return value + band;
}


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

#pragma push
#pragma opt_propagation off
#pragma opt_propagation on
#pragma pop
#pragma opt_loop_invariants on
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
#pragma opt_loop_invariants off

// measured: required for exact retail loop codegen in btlSoundResetSlotQueue.
#pragma opt_loop_invariants on



#pragma opt_rebuildconditionals off
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceA probe. */
#pragma opt_rebuildconditionals on

#pragma opt_rebuildconditionals off
#pragma opt_rebuildconditionals on
#pragma optimization_level 1
#pragma opt_loop_invariants off
#pragma optimization_level 2




#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_propagation off
#pragma opt_propagation on

#pragma opt_propagation off
#pragma opt_propagation on


#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma pop
