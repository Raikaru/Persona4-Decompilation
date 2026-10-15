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
extern s32 func_00122720(void);
extern void btlPanelDrawCircle(u8 *unused, f32 scaleX, f32 scaleY, f32 depth, s32 color);
extern void func_003e8110(s32 arg0);
extern s32 func_003e8120(s32 arg0);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern s32 func_00457120(void);
extern void func_0045c870(u8 *arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0048a000(void);
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
extern s32 func_0010f420(s32 arg0, s32 arg1);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern s32 func_001f56d0(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_001f62b0();
extern void func_001f58d0();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);
extern s32 func_0045af90(s32 arg0);

extern void memset(void *destination, s32 value, u32 size);

extern s32 func_001ef5f0(s32 arg0, s32 arg1, s32 arg2);

extern u32 datCalcRandomBelow();
extern s32 datCalcEnemyExp(s32 arg0);
extern s32 func_002439c0(s32 arg0);
extern u16 datCalcPickWeightedSkill(u8 *arg0, s32 *arg1);
extern void kAssertFail(void *arg0, s32 arg1);
extern u8 D_0060AB08[];
extern void func_0045a3e0(s32 arg0, s32 arg1);
extern s16 func_001060b0(void);
extern s32 func_00110d60(s32 arg0);
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
extern s32 func_001f65d0(u8 *arg0);
extern u8 D_00624B20[];
extern u8 D_00624B22[];
extern s32 func_001ef9a0(void);
extern void func_0045a9a0(s32 arg0, s32 arg1);
extern s32 func_00459880(void);

extern void H_Cdvd_Destroy(u8 *arg0);
extern void datCalcClearFlaggedBuffs(s32 arg0);
extern void func_0045aac0(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bd3c0(void);

extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);
extern void func_002bd3e0(void);
extern void func_002bd410(void);
extern s32 btlUnitStatusWindowShow(u8 *arg0, s16 arg1);
extern s32 btlTaskSlotIsLinked(s32 arg0);
extern s32 func_001fa7a0(s32 *arg0);
extern s32 func_001fa940(void);
extern s32 func_001faa00(void);
extern s32 btlTaskSlotIsSet(void);
extern s32 func_00120ee0(s32 arg0);
extern s32 H_Cdvd_IsFileLoaded(u8 *arg0);
extern void datCalcClearStatusBlocked(s32 arg0);
extern void datCalcSetHp(s32 arg0, s32 arg1);
extern void datCalcClearBadStatus(s32 arg0, s32 arg1);
extern void datCalcSetBadStatus(s32 arg0, s32 arg1);

extern void func_00485b20(s32 arg0);
extern void func_00486180(s32 arg0);
extern void func_00120f20(s32 arg0);
extern s32 func_00122520(s32 arg0, s32 arg1);
extern void H_Fade_SetCustomColor(s32 arg0, s32 arg1, s32 arg2);
extern void memcpy(void *arg0, void *arg1, u32 arg2);
extern void func_001fa490(void);
extern s32 func_001fa660(void);
extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];
extern s32 kwlnTaskGetTaskByName(void *arg0);

extern s32 hFadeTaskUpdate(u8 *arg0);


extern void btlTargetAdvanceWorkPtr(u8 **arg0);
extern u16 datPersonaGetRecordId(u16 arg0);
extern u16 *datPersonaGetRecord(u16 character);
extern s32 datPersonaFindSkillSlot(u8 *persona, u16 skill);
extern s32 func_001f3900(u8 **arg0);
extern void btlTargetAdvanceWorkCount(void);
extern u8 *btlPacketAlloc(s32 type, s32 workSize);

extern void btlTargetRewindWorkPtr(u8 **arg0);

extern s32 func_001f39d0(u8 **arg0);
extern void btlTargetRewindWorkCount(void);

extern s32 func_001f8380(u8 **arg0);
extern s32 func_00106600(s16 arg0);
extern s32 datCalcAddHp(s32 arg0, s32 arg1);
extern s32 datCalcAddSp(s32 arg0, s32 arg1);
extern u32 datCalcSkillCost(u8 *arg0, s32 arg1);

extern s32 func_001f8400(u8 **arg0);
extern s32 iGpffffb464;
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void sprintf(void *dst, void *fmt, ...);
extern s32 func_00456250(s32 arg0, void *arg1, s32 arg2, void *arg3);
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

extern s32 func_001f6f60(u8 *arg0);
extern void func_001f7260(void);
/* measured: compiler residual in call argument materialization. Committed at nd 3. */
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
#pragma optimization_level 1
// FUN_001F0FF0
s32 func_001f0ff0(u32 arg0)
{
    s32 index;
    index = *(u16 *)(arg0 + 0x6E);
    return (func_001d7f10((u8 *)arg0, 0, index, 0) & 0xFFFF) == 0;
}
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma optimization_level 2

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
typedef struct BtlHit_001f14f0 {
    s32 damageA;
    s32 damageB;
    s32 maskA;
    s32 maskB;
    s32 bonus;
    s32 effect;
    u16 absoluteA;
    u16 absoluteB;
    s8 reaction;
    u8 pad1D;
    u16 flags;
} BtlHit_001f14f0;

static inline s32 btlAnyUnitE4_001f14f0(u8 *arg0, s32 n)
{
    u16 k;

    for (k = 0; k < n; k++) {
        if (*(s32 *)(*((u8 **)arg0 + 0xE + k) + 0xE4) != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_pulloutconstants off

#pragma pop

#pragma opt_propagation off
#pragma opt_propagation on














extern u32 datCalcIsLowHp(s32 unit);
extern u8 *func_001b0c80(s32 arg0);
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

// measured: required for exact retail loop codegen in func_001f7260.
#pragma opt_loop_invariants on



#pragma opt_rebuildconditionals off
/* measured: close opt_rebuildconditionals after func_001f6f60 probe. */
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
/* Native b210 -O2 recovery: 1620 bytes plus 12 zero tail bytes.
   The state table is addressed through uintptr_t so ordinary propagation
   retains its base while reloading each callback. Ordinary common-subexpression
   optimization gives both unsigned alpha conversions their retail temporaries.
   The radial draw takes depth before packed color in both owners.
   See docs/probe_archive/BattleAction_20260922_resume.md. */
// FUN_001FBB50
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
s32 hFadeTaskUpdate(u8 *work) {
    void *savedStates[7];
    struct {
        union { s32 word; u8 bytes[4]; } radial;
        u8 screen[4];
    } colors;
    f32 fadeProgress;
    f32 layerScale;
    s32 result;
    u32 stateIndex;

    if (func_003e8120(func_00457120()) == 0) {
        return 0;
    }
    result = 0;
    for (stateIndex = 0; stateIndex < 7; stateIndex++) {
        u32 offset = stateIndex * sizeof(savedStates[0]);
        D_00887304[0](*(RwRenderState *)((u8 *)D_00625210 + offset), (u8 *)savedStates + offset);
    }
    work = *(u8 **)(work + 0x38);
    {
        u32 state = *work;
        switch (state) {
        case 0:
            break;
        case 1: {
            u32 countdown = D_0076455C;
            if (countdown == 0) {
                f32 square;
                uintptr_t stateInterface;

                D_0076455A++;
                fadeProgress = (f32)(u32)D_0076455A / 20.0f;
                /* Keep the table address; each draw state reloads its callback. */
                stateInterface = (uintptr_t)D_00887300;
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATESHADEMODE, (void *)2);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATECULLMODE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEFOGENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZTESTENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZWRITEENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATETEXTURERASTER, (void *)0);
                RpSkyRenderStateSet(2, (void *)0x44);
                RpSkyRenderStateSet(3, (void *)0x31801);
                func_00489f80();
                colors.screen[2] = colors.screen[1] = colors.screen[0] = 0xFF;
                square = fadeProgress * fadeProgress;
                {
                    f32 progressCubed = fadeProgress * square;
                    f32 progressFourth = fadeProgress * progressCubed;
                    f32 progressFifth = fadeProgress * progressFourth;
                    f32 screenOpacity = 255.0f * (1.0f - fadeProgress * progressFifth);
                    u8 screenAlpha = (u8)screenOpacity;
                    colors.screen[3] = screenAlpha;
                }
                func_0045c870(colors.screen, 0);
                colors.radial.bytes[2] = colors.radial.bytes[1] = colors.radial.bytes[0] = 0xFF;
                {
                    f32 radialOpacity = 160.0f * (1.0f - square);
                    u8 radialAlpha = (u8)radialOpacity;
                    colors.radial.bytes[3] = radialAlpha;
                }
                layerScale = 1.5f * ((f32)(u32)D_0076455A / 20.0f);
                func_00457120();
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATESHADEMODE, (void *)2);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATECULLMODE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEFOGENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZTESTENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEZWRITEENABLE, (void *)0);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATEVERTEXALPHAENABLE, (void *)1);
                (*(BattleRenderStateFunction *)stateInterface)(rwRENDERSTATETEXTURERASTER, (void *)0);
                RpSkyRenderStateSet(2, (void *)0x44);
                RpSkyRenderStateSet(3, (void *)0x31801);
                btlPanelDrawCircle(0, layerScale, layerScale, D_008872FC_abs[0], colors.radial.word);
                func_0048a000();
                func_001fb480(1.0f, (u8 *)&D_007635C8, 0x54, 0x31801, (u8 *)1);
                if ((s32)D_0076455A >= 0x14) {
                    *work = 3;
                }
                break;
            }
            D_0076455C = countdown - 1;
            /* Continue the waiting-state draw after decrementing. */
        }
        case 2: {
            if (iGpffffb469 == 0) {
                func_001fb480(1.0f, (u8 *)&D_007635C8, 0x44, 0x31801, (u8 *)1);
                if (*(u16 *)(work + 6) == 1) {
                    layerScale = D_007613E0;
                } else {
                    layerScale = D_007613E4;
                }
                colors.screen[2] = colors.screen[1] = colors.screen[0] = 0xFF;
                {
                    u8 alpha;

                    if (*(u16 *)(work + 6) == 1) {
                        alpha = 6;
                    } else {
                        alpha = 0x0A;
                    }
                    colors.screen[3] = alpha;
                }
                func_001fb480(layerScale, colors.screen, 0x44, 0x31801, (u8 *)2);
                colors.screen[3] = 5;
                func_001fb480(layerScale, colors.screen, 0x48, 0x31801, (u8 *)2);
            }
            break;
        }
        case 3: {
            if (func_00122720() != 0) {
                func_00122640(1, 0x1E);
                iGpffffb468 = 0;
                result = -1;
            }
            break;
        }
        default:
            break;
        }
        {
            u32 k;

            for (k = 0; k < 7; k++) {
                u32 offset = k * sizeof(savedStates[0]);
                D_00887300[0](*(RwRenderState *)((u8 *)D_00625210 + offset), *(void **)((u8 *)savedStates + offset));
            }
        }
        D_00887300[0](rwRENDERSTATETEXTURERASTER, NULL);
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        func_003e8110(func_00457120());
    }
    return result;
}
#pragma pop
// FUN_001FC1B0
void hFadeTaskStart(s16 arg0) {
    if (kwlnTaskGetTaskByName(&D_006251F0) == 0) {
        iGpffffb468 = 2;
        iGpffffb46e = arg0;
        iGpffffb469 = 0;
        (s32)kwlnTaskCreate((const void *)(&D_006251F0), 0xC9, 0, 0, hFadeTaskUpdate, 0, (u8 *)((void *)&iGpffffb468));
    }
}
// FUN_001FC270
s32 func_001fc270(void)
{
    return 1;
}
// FUN_001FC280
void hFadeSetCustomWhite(void) {
    iGpffffb469 = 1;
    func_00122520(1, 1);
    H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
}
