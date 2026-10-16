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
extern u16 D_0076455C;
extern u16 D_0076455A;
extern f32 D_007613E0;
extern f32 D_007613E4;
extern f32 D_008872FC_abs[];
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern u8 *iGpffffb3c4;
extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern s32 btlActionRunTargetCallback(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void btlSoundCancelPlayback();
extern void btlActionStepMessagePhase();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);


extern s32 btlSideAverageBattleStat(s32 arg0, s32 arg1, s32 arg2);

extern u32 datCalcRandomBelow();
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
extern s32 btlCurrentUnitId(void);



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

/* Source unit: src/promoted/code1_001f.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001f.c; members 001f42a0-001f5ed0 */

extern s32 btlActionAnyTargetHitRowStatus(u8 *arg0);
extern s32 btlActionSameGenusTargetsHaveDelta(u8 *arg0);
extern s32 func_001f0d30(u8 *arg0);
extern s32 func_001f0dd0(u8 *arg0, s32 arg1);
extern s32 btlActionHasNoTargetClass(u32 arg0);
extern s32 btlTargetGroupStateMatches(u8 *arg0);
extern s32 btlSoundRequestPlayback(s16 arg0, s32 arg1);
extern void btlSoundCancelPlayback(void);
extern u32 datCalcIsLowHp(s32 unit);
extern u8 *btlActionFindByUnit(s32 arg0);
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
// FUN_001F42A0
s32 btlActionGetCurrentActorMsgCode(s32 arg0) {
    if (*(s32 *)(iGpffffb3ac + 0x170) != arg0) {
        return -1;
    }
    return 0x173;
}

// FUN_001F42D0
s32 btlActionGetDefaultMsgCode(void) {
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) != 0) {
        if (btlCurrentUnitId() == 0x20B) {
            return 0x18B;
        }
    }
    return 0x165;
}

// FUN_001F4330
s32 btlActionGetSideMsgCode(u8 *arg0)
{
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return 0x99;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) == 1) {
        return 0x5D;
    }
    return -1;
}

// FUN_001F4380
s32 func_001f4380(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x68;
    case 2:
        return 0x69;
    case 3:
        return 0x6A;
    case 4:
        return 0x6B;
    case 6:
        return 0x6C;
    case 7:
        return 0x6D;
    case 8:
        return 0x6E;
    default:
        return -1;
    }
}

// FUN_001F4430
s32 btlActionGetCharacterLevelMsg(u8 *arg0, s32 arg1) {
    s32 temp_4;
    u16 temp_2;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (arg1 <= 0) {
        return -1;
    }
    if (!(func_001ef720(2, 0x80000) & 0xFFFF)) {
        return -1;
    }
    temp_4 = (5 - arg1) * 7;
    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 1:
        return temp_4 + 0xFD;
    case 2:
        return temp_4 + 0xFE;
    case 3:
        return temp_4 + 0xFF;
    case 4:
        return temp_4 + 0x100;
    case 6:
        return temp_4 + 0x101;
    case 7:
        return temp_4 + 0x102;
    case 8:
        return temp_4 + 0x103;
    default:
        return -1;
    }
}

// FUN_001F4550
s32 func_001f4550(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x3D;
    case 2:
        return 0x3E;
    case 3:
        return 0x3F;
    case 4:
        return 0x40;
    case 6:
        return 0x41;
    case 7:
        return 0x42;
    case 8:
        return 0x43;
    default:
        return -1;
    }
}

// FUN_001F4600
s32 func_001f4600(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x35;
    case 2:
        return 0x36;
    case 3:
        return 0x37;
    case 4:
        return 0x38;
    case 6:
        return 0x39;
    case 7:
        return 0x3A;
    case 8:
        return 0x3B;
    default:
        return -1;
    }
}

// FUN_001F46B0
s32 func_001f46b0(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x14A;
    case 2:
        return 0x14B;
    case 3:
        return 0x14C;
    case 4:
        return 0x14D;
    case 6:
        return 0x14E;
    case 7:
        return 0x14F;
    case 8:
        return 0x150;
    default:
        return -1;
    }
}

// FUN_001F4760
s32 func_001f4760(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x143;
    case 2:
        return 0x144;
    case 3:
        return 0x145;
    case 4:
        return 0x146;
    case 6:
        return 0x147;
    case 7:
        return 0x148;
    case 8:
        return 0x149;
    default:
        return -1;
    }
}

// FUN_001F4810
s32 btlActionPickMsgCodeByRoll(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_4;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if ((arg2 >= 6) || (arg2 <= 0)) {
        return -1;
    }
    if (arg2 == 1) {
        if ((arg1 & 2) && (datCalcRandomBelow(0x64) < 0x1E)) {
            s32 var_2_2;
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
                var_2_2 = -1;
            } else {
                switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
                case 1:
                    var_2_2 = 0x14A;
                    break;
                case 2:
                    var_2_2 = 0x14B;
                    break;
                case 3:
                    var_2_2 = 0x14C;
                    break;
                case 4:
                    var_2_2 = 0x14D;
                    break;
                case 6:
                    var_2_2 = 0x14E;
                    break;
                case 7:
                    var_2_2 = 0x14F;
                    break;
                case 8:
                    var_2_2 = 0x150;
                    break;
                default:
                    var_2_2 = -1;
                    break;
                }
            }
            return var_2_2;
        }
        if ((arg1 & 4) && (datCalcRandomBelow(0x64) < 0x1E)) {
            s32 var_2;
            if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
                var_2 = -1;
            } else {
                switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
                case 1:
                    var_2 = 0x143;
                    break;
                case 2:
                    var_2 = 0x144;
                    break;
                case 3:
                    var_2 = 0x145;
                    break;
                case 4:
                    var_2 = 0x146;
                    break;
                case 6:
                    var_2 = 0x147;
                    break;
                case 7:
                    var_2 = 0x148;
                    break;
                case 8:
                    var_2 = 0x149;
                    break;
                default:
                    var_2 = -1;
                    break;
                }
            }
            return var_2;
        }
    }
    temp_4 = (5 - arg2) * 7;
    switch (*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
    case 1:
        return temp_4 + 0x120;
    case 2:
        return temp_4 + 0x121;
    case 3:
        return temp_4 + 0x122;
    case 4:
        return temp_4 + 0x123;
    case 6:
        return temp_4 + 0x124;
    case 7:
        return temp_4 + 0x125;
    case 8:
        return temp_4 + 0x126;
    default:
        return -1;
    }
}

// FUN_001F4AD0
s32 func_001f4ad0(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x158;
    case 2:
        return 0x159;
    case 3:
        return 0x15A;
    case 4:
        return 0x15B;
    case 6:
        return 0x15C;
    case 7:
        return 0x15D;
    case 8:
        return 0x15E;
    default:
        return -1;
    }
}

// FUN_001F4B80
s32 func_001f4b80(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x4D;
    case 2:
        return 0x4E;
    case 3:
        return 0x4F;
    case 4:
        return 0x50;
    case 6:
        return 0x51;
    case 7:
        return 0x52;
    case 8:
        return 0x53;
    default:
        return -1;
    }
}

// FUN_001F4C30
s32 func_001f4c30(u8 *arg0)
{
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    temp_2 = *(u16 *)(temp_3 + 0xA4);
    switch (temp_2) {
    case 1:
        return 0x2D;
    case 2:
        return 0x2E;
    case 3:
        return 0x2F;
    case 4:
        return 0x30;
    case 6:
        return 0x31;
    case 7:
        return 0x32;
    case 8:
        return 0x33;
    default:
        return -1;
    }
}

// FUN_001F4CE0
s32 func_001f4ce0(u8 *arg0)
{
    u16 temp_2;
    u16 temp_2_2;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (temp_4[0xA2] != 0) {
        return -1;
    }
    if ((*(s32 *)(iGpffffb3ac + 0x10) & 0x20000000) != 0) {
        if (btlCurrentUnitId() != 0x20B) {
            goto high_default_4ce0;
        }
        temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
        switch (temp_2) {
        case 2:
            return 0x18C;
        case 3:
            return 0x18D;
        case 4:
            return 0x18E;
        case 6:
            return 0x18F;
        case 7:
            return 0x190;
        case 8:
            return 0x18A;
        case 0:
        case 1:
        case 5:
        default:
            goto high_default_4ce0;
        }
    }
    goto low_switch_4ce0;
high_default_4ce0:
    return -1;
low_switch_4ce0:
    temp_2_2 = *(u16 *)(temp_4 + 0xA4);
    switch (temp_2_2) {
    case 2:
        return 0x26;
    case 3:
        return 0x27;
    case 4:
        return 0x28;
    case 6:
        return 0x29;
    case 7:
        return 0x2A;
    case 8:
        return 0x2B;
    case 0:
    case 1:
    case 5:
    default:
        return -1;
    }
}

/* Native b210 -O2 recovery: 1876 bytes plus 12 zero tail bytes.
   Each selected field has its own uintptr_t address, derived from that
   field's array base. The byte offset stays live across the previous-code
   check; the actor address is formed after recording the selected code.
   This preserves both addiu/LH-at-zero pairs and the signed actor guard.
   The owned nine-entry switch table resolves to retail at 0x00747500.
   See docs/probe_archive/BattleAction_20260922_resume.md. */
// FUN_001F4E50
s64 btlActionPickRandomStatusMsg(u8 *arg0) {
    struct ActionMessageChoice {
        s16 code;
        s16 actor;
    } choices[64];
    s16 selectedCode;
    u8 *unit;
    s32 choiceCount;
    s32 code8ACount;
    s32 enemyCount;
    u8 *battle;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    choiceCount = 0;
    code8ACount = 0;
    battle = iGpffffb3ac;
    unit = *(u8 **)(battle + 0x178);
    while (unit != NULL) {
        if (datCalcIsDead((s32)(*(u8 **)(unit + 0xA64)), 0) == 0) {
            u8 *unitWork = (u8 *)btlActionFindByUnit((s32)unit);
            if ((unitWork == NULL) || !(*(u16 *)(unitWork + 0x18) & 0x20)) {
                if (datCalcIsLowHp((s32)((void *)*(u8 **)(unit + 0xA64))) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x8A;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                    code8ACount = (code8ACount + 1) & 0xFFFF;
                }
                if (*(u16 *)(unit + 0xA4) != 1) {
                    if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x10) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0x99;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x20) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0x9f;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x4) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xa5;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x2) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xab;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x1) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xb1;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x40) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xb7;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x80) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xbd;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x8) != 0) {
                        struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                        choice->code = 0xc3;
                        choice->actor = *(u16 *)(unit + 0xA4);
                        choiceCount = (choiceCount + 1) & 0xFFFF;
                    }
                }
                if (datCalcHasBuffMask((u8 *)(*(s32 *)(unit + 0xA64)), 0xA) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x6F;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
                if (datCalcHasBuffMask((u8 *)(*(s32 *)(unit + 0xA64)), 0x80) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x76;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
                if (datCalcHasBuffMask((u8 *)(*(s32 *)(unit + 0xA64)), 0x220) != 0) {
                    struct ActionMessageChoice *choice = &choices[choiceCount & 0xFFFF];
                    choice->code = 0x7D;
                    choice->actor = *(u16 *)(unit + 0xA4);
                    choiceCount = (choiceCount + 1) & 0xFFFF;
                }
            }
        }
        unit = *(u8 **)(unit + 0xA6C);
    }
    {
        u8 *sourceUnit = *(u8 **)(arg0 + 0x30);
        if (*(u16 *)(sourceUnit + 0xA4) == 1) {
            if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x20) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x92;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x2) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x94;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x1) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x95;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x40) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x96;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x80) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x97;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            } else if (datCalcChkBadStatus(*(s32 *)(sourceUnit + 0xA64), 0x8) != 0) {
                choices[choiceCount & 0xFFFF].code = 0x98;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            }
        }
    }
    if ((code8ACount & 0xFFFF) >= 2) {
        choices[choiceCount & 0xFFFF].code = 0x89;
        choices[choiceCount & 0xFFFF].actor = -1;
        choiceCount = (choiceCount + 1) & 0xFFFF;
    }
    enemyCount = func_001ef720(2, 0x80000) & 0xFFFF;
    {
        u8 *battleCounts = iGpffffb3ac;
        s16 *savedEnemyCount = (s16 *)(battleCounts + 0xA6C);
        if (*(s16 *)(battleCounts + 0xA6C) == enemyCount) {
            if ((enemyCount < 6) && (enemyCount > 0)) {
                choices[choiceCount & 0xFFFF].code = 0x89 - enemyCount;
                choices[choiceCount & 0xFFFF].actor = -1;
                choiceCount = (choiceCount + 1) & 0xFFFF;
            }
        } else {
            *savedEnemyCount = enemyCount;
        }
    }
    if ((choiceCount & 0xFFFF) <= 0) {
        return -1;
    }
    {
        u32 selectedOffset = (datCalcRandomBelow(choiceCount & 0xFFFF) & 0xFFFF) * 4;
        /* These are two field addresses within the same selected row. */
        uintptr_t codeAddress = (uintptr_t)((u8 *)choices + selectedOffset);
        s16 actorId;
        uintptr_t actorAddress;
        u8 *battleSelection;
        s32 *previousCode;
        selectedCode = *(s16 *)codeAddress;
        battleSelection = iGpffffb3ac;
        previousCode = (s32 *)(battleSelection + 0xA68);
        if (*(s32 *)(battleSelection + 0xA68) == selectedCode) {
            return -1;
        }
        *previousCode = selectedCode;
        actorAddress = (uintptr_t)((u8 *)&choices[0].actor + selectedOffset);
        actorId = *(s16 *)actorAddress;
        if (actorId >= 0) {
            switch (actorId) {
            case 2:
                selectedCode = selectedCode + 1;
                break;
            case 3:
                selectedCode = selectedCode + 2;
                break;
            case 4:
                selectedCode = selectedCode + 3;
                break;
            case 6:
                selectedCode = selectedCode + 4;
                break;
            case 7:
                selectedCode = selectedCode + 5;
                break;
            case 8:
                selectedCode = selectedCode + 6;
                break;
            }
        }
    }
    return selectedCode;
}

// FUN_001F55B0
s32 btlActionGetPendingMsgCode(u8 *arg0)
{
    u8 *work;

    if (*(u8 **)(iGpffffb3ac + 0x170) != arg0) {
        return -1;
    }
    work = *(u8 **)(arg0 + 0x30);
    switch (*(u16 *)(arg0 + 0x6C)) {
    case 0xB:
        if (datCalcChkBadStatus(*(s32 *)(work + 0xA64), 0x10) != 0) {
            return 0x91;
        }
        if (datCalcChkBadStatus(*(s32 *)(work + 0xA64), 4) != 0) {
            return 0x93;
        }
        if (datCalcChkBadStatus(*(s32 *)(work + 0xA64), 2) != 0) {
            return 0x94;
        }
        break;
    default:
        break;
    }
    return -1;
}

// FUN_001F5680
/* The `return -1` and `return v + 0x11` blocks are reached by goto so they
   land in retail's order; writing both as plain returns emits them the other
   way round. */
s32 btlActionGetSlotMsgCode(void) {
    u8 *p;
    s32 v;

    p = *(u8 **)(iGpffffb3ac + 0xC68);
    if (p == NULL) {
        return -1;
    }
    v = *(u16 *)(p + 2);
    if (v < 6) {
        if (v != 0) {
            goto add;
        }
    }
    return -1;
add:
    return v + 0x11;
}

// FUN_001F56D0
s32 btlActionRunTargetCallback(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 flags;
    s32 mode;
    s32 index;
    s32 value;
    s32 (*callback)(s32, s32, s32, s32);
    s32 result;
    u8 *table;

    extern s32 (*D_0060AB20[])(s32, s32, s32, s32);
    extern s32 btlSoundRequestPlayback(u16, s32);

    flags = *(s32 *)(iGpffffb3ac + 0xC);
    if ((flags & 0x1000000) == 0) {
        return 1;
    }
    if (*(u16 *)(iGpffffb3ac + 0xA50) != 0) {
        return 0;
    }
    mode = arg4 & 6;
    if ((mode == 0) && ((*(u16 *)(iGpffffb3ac + 0xA4E) & 1) != 0)) {
        return 1;
    }
    table = iGpffffb414 + (*(u16 *)(*(u8 **)(iGpffffb3ac + 0xC68) + 8) * 0x18);
    if ((*(s32 *)table & 0x400) != 0) {
        return 1;
    }
    if ((*(u16 *)(iGpffffb3ac + 0xA4E) & 1) != 0) {
        index = arg1 & 0xFFFF;
        if (*(s16 *)(iGpffffb3ac + 0xA5C) == index) {
            return 1;
        }
        if (*(s16 *)(iGpffffb3ac + 0xA64) == index) {
            return 1;
        }
    }
    callback = D_0060AB20[arg1 & 0xFFFF];
    if (callback == NULL) {
        return 1;
    }
    value = callback(arg0, arg2, arg3, 0);
    if (value < 0) {
        return 1;
    }
    if ((*(s32 *)table & 0x1000) != 0) {
        u8 *pool;
        u8 *entries;
        s32 slot;
        pool = *(u8 **)(iGpffffb3ac + 0xA54);
        slot = value & 0xFFFF;
        entries = *(u8 **)(pool + 0x110);
        if (*(u8 *)(entries + slot * 0xC) != 0) {
            return 1;
        }
    }
    if ((arg4 & 2) != 0) {
        btlSoundCancelPlayback();
        *(u16 *)(iGpffffb3ac + 0xA6E) = 2;
    } else {
        *(u16 *)(iGpffffb3ac + 0xA6E) = 0;
    }
    result = btlSoundRequestPlayback(arg1, value);
    return result;
}

// FUN_001F58D0
void btlActionStepMessagePhase(void)
{
    s16 temp_2;
    u8 *state_ptr;
    u8 *temp_2_ptr;
    u8 *temp_16;
    u8 *temp_4;
    u16 temp_3;
    u8 *temp_3_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *temp_4_2;
    u8 *temp_6;

    temp_6 = iGpffffb3ac;
    state_ptr = temp_6 + 0xA50;
    temp_3 = *(u16 *)state_ptr;
    switch (temp_3) {
    case 0:
        goto done;
    case 1:
        goto case1;
    case 2:
        goto case2;
    default:
        goto done;
    }
case1:
    temp_2_ptr = temp_6 + 0xA6E;
    temp_2 = *(s16 *)temp_2_ptr;
    if (temp_2 > 0) {
        *(s16 *)temp_2_ptr = (s16)(temp_2 - 1);
        goto done;
    }
    *(u16 *)state_ptr = 2;
case2:
    temp_3_2 = iGpffffb3ac;
    temp_4 = *(u8 **)(*(u8 **)(temp_3_2 + 0xA54) + 0x110);
    temp_16 = temp_4 + ((s32 *)(temp_4 + 4))[*(u16 *)(temp_3_2 + 0xA60) * 3];
    func_002bd270(temp_16, state_ptr, temp_6);
    func_002bd280(*(u16 *)(iGpffffb3ac + 0xA4C),
                  datCalcRandomBelow(itfMesRecordCount(temp_16)), 0, 0);
    temp_3_3 = iGpffffb3ac;
    *(s32 *)(temp_3_3 + 0xA58) = *(s32 *)(temp_3_3 + 0xA60);
    temp_3_4 = iGpffffb3ac;
    *(s16 *)(temp_3_4 + 0xA5C) = *(s16 *)(temp_3_4 + 0xA64);
    temp_3_5 = iGpffffb3ac;
    *(u16 *)(temp_3_5 + 0xA4E) =
        (u16)(*(u16 *)(temp_3_5 + 0xA4E) | 1);
    *(u16 *)(iGpffffb3ac + 0xA50) = 0;
done:
    if (func_002bd340() == 0) {
        temp_4_2 = iGpffffb3ac;
        *(u16 *)(temp_4_2 + 0xA4E) =
            (u16)(*(u16 *)(temp_4_2 + 0xA4E) & 0xFFFE);
    }
}

// FUN_001F5A00
void btlActionCheckStepTrigger(s32 arg0)
{
    extern s32 btlActionGetQueueFront(void);
    extern s32 btlActionGetActive(void);
    extern s32 btlActionActiveListPush(s32 arg0);
    s32 i;
    s32 result;
    u8 *current;
    u8 *global;

    result = 0;
    i = 0;
    while (((i & 0xFFFF) <= 0) && (result == 0)) {
        if ((*(u16 *)(iGpffffb3ac + 0xA48) &
             ((1 << (i & 0xFFFF)) & 0xFFFF)) != 0) {
            switch (((1 << (i & 0xFFFF)) & 0xFFFF)) {
            case 1:
                current = (u8 *)btlActionGetQueueFront();
                if ((current != NULL) &&
                    ((*(u16 *)(current + 0x1A) & 1) != 0) &&
                    (arg0 != 0) &&
                    (*(u8 *)(*(u8 **)(current + 0x30) + 0xA2) == 0)) {
                    *(u16 *)(iGpffffb3ac + ((i & 0xFFFF) * 4) + 0xA44) =
                        (u16)(*(u16 *)(iGpffffb3ac +
                                       ((i & 0xFFFF) * 4) + 0xA44) + 1);
                    if ((arg0 != 0) &&
                        (*(u16 *)(iGpffffb3ac +
                                  ((i & 0xFFFF) * 4) + 0xA46) >= 4) &&
                        (*(u16 *)(iGpffffb3ac +
                                  ((i & 0xFFFF) * 4) + 0xA44) ==
                         (*(u16 *)(iGpffffb3ac +
                                   ((i & 0xFFFF) * 4) + 0xA46) >> 1))) {
                        btlActionRunTargetCallback(
                            *(s32 *)(iGpffffb3ac + 0x170), 4, 0, 0, 4);
                    } else {
                        global = iGpffffb3ac;
                        if ((*(u16 *)(global +
                                      ((i & 0xFFFF) * 4) + 0xA44) >=
                             *(u16 *)(global +
                                      ((i & 0xFFFF) * 4) + 0xA46)) &&
                            (datCalcChkBadStatus(
                                 *(s32 *)(*(u8 **)(*(u8 **)(global + 0x170) +
                                                   0x30) + 0xA64),
                                 0x180010) == 0) &&
                            (btlActionGetActive() == 0)) {
                            *(u16 *)(*(u8 **)(iGpffffb3ac + 0x170) + 0x16) =
                                0x1C;
                            btlActionActiveListPush(
                                *(s32 *)(iGpffffb3ac + 0x170));
                            result = 1;
                            *(u16 *)(iGpffffb3ac + 0xA48) =
                                (u16)(*(u16 *)(iGpffffb3ac + 0xA48) &
                                      0xFFFE);
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
        i = (i + 1) & 0xFFFF;
    }
}

/* measured: 708/720B MATCH; the remaining 12 bytes are zero tail padding.
   Paired group statistics stay in FPRs and preserve the retail operation
   tree and unsigned conversions without additional storage. */
// FUN_001F5BD0
#pragma push
/* measured: btlActionRollGroupRatio MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void btlActionRollGroupRatio(s32 arg0)
{
    u32 mask;
    unsigned int random_value;
    struct { f32 stat3; f32 stat4; } group1, group2;
    f32 random_ratio;
    f32 ratio;
    u16 result;

    mask = ((1 << (u16)arg0) & 0xFFFF);
    *(u16 *)(iGpffffb3ac + 0xA48) =
        (u16)(*(u16 *)(iGpffffb3ac + 0xA48) | mask);
    switch ((u16)arg0) {
    case 0:
        goto body;
    default:
        goto done;
    }
body:
    group1.stat3 = (f32)(u32)btlSideAverageBattleStat(1, 3, 0x80000);
    group2.stat3 = (f32)(u32)btlSideAverageBattleStat(2, 3, 0x80000);
    group1.stat4 = (f32)(u32)btlSideAverageBattleStat(1, 4, 0x80000);
    group2.stat4 = (f32)(u32)btlSideAverageBattleStat(2, 4, 0x80000);

    random_value = datCalcRandomBelow(0xF) + 5;
    random_ratio = (f32)random_value;
    random_ratio /= 10.0f;
    ratio = random_ratio * (30.0f * ((group1.stat3 / group2.stat3) * (group1.stat4 / group2.stat4)));
    if (ratio > 50.0f) {
        ratio = 50.0f;
    } else if (ratio < 10.0f) {
        ratio = 10.0f;
    }
    {
        s32 offset;
        u8 *p;
        offset = (u16)arg0 * 4;
        p = (u8 *)(offset + (s32)iGpffffb3ac);
        *(u16 *)(p + 0xA44) = 0;
        result = (u16)(100.0f / ratio);
        offset = (u16)arg0 * 4;
        p = (u8 *)(offset + (s32)iGpffffb3ac);
        *(u16 *)(p + 0xA46) = result;
    }
done:
    ;
}

#pragma pop
// FUN_001F5EA0
s32 btlActionIsPendingBit(s32 arg0) {
    return (s32)((*(u16 *)((u8 *)iGpffffb3ac + 0xA48) & (1 << (arg0 & 0xFFFF))) != 0);
}

// FUN_001F5ED0
s32 btlActionCachedDispatch(u8 *arg0)
{
    s32 result;
    u8 *global;

    if (*(s32 *)(arg0 + 0x14) == 0) {
        *(s32 *)(arg0 + 0x14) = btlActionRunTargetCallback(
            *(s32 *)(arg0 + 0),
            *(u16 *)(arg0 + 4),
            *(s32 *)(arg0 + 8),
            *(s32 *)(arg0 + 0xC),
            *(s32 *)(arg0 + 0x10));
    }
    result = *(s32 *)(arg0 + 0x14);
    if ((result == 1) && (*(s32 *)(arg0 + 0x10) & 1) != 0) {
        global = iGpffffb3ac;
        if (((*(u16 *)(global + 0xA4E) & 1) != 0) ||
            (*(u16 *)(global + 0xA50) != 0)) {
            result = 0;
        }
    }
    return result;
}

