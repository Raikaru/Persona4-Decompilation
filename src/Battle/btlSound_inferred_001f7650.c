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
extern u8 *iGpffffb3c4;
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);



extern u8 D_0060AB08[];
extern s16 datGetDateIndex(void);
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






/* Source unit: src/promoted/code1_001f.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001f.c; members 001f7650-001f7b40 */

extern s32 btlActionHasNoTargetClass(u32 arg0);
extern s32 btlSoundRollStatusCure(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *arg0);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *arg0);
extern void btlSoundAdvanceSlotQueue(void);
/* measured: optimization_level 1 probe for func_001f0ff0 call materialization. */
/* measured: close optimization_level 1 probe for func_001f0ff0. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test. */
/* measured: close opt_loop_invariants after btlSoundRollStatusCure. */
/* measured: every instruction matches and the object is exactly the 80-byte
   window; the only residual is that retail materialises the shift constant
   (`addiu $v1,$zero,1`) BEFORE the branch into the loop test while b210 puts
   it after, which also shifts the back-edge displacement by one word (nd 9).
   Measured identical at nd 9: an inline `1 << i`, a hoisted `one` local, and
   an explicit goto loop with the test at the bottom. Preheader hoist-order
   floor. Committed at nd 9. */

#pragma push
#pragma pop
/* measured: retail materialises this loop's invariant in the preheader; plain
   -O2 rematerialises it in the body (nd 9 -> byte-exact with the hoist). */
/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
/* measured: opt_rebuildconditionals off probe for btlSoundPickStatusTalkVoiceA final branch. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceA probe. */
/* measured: opt_rebuildconditionals off preserves btlSoundPickStatusTalkVoiceB's positive flag branch. */
/* measured: close opt_rebuildconditionals after btlSoundPickStatusTalkVoiceB. */
/* measured: optimization_level 1 required for exact btlSoundAdvanceSlotQueue codegen. */
/* measured: opt_loop_invariants off baseline for btlSoundAdvanceSlotQueue. */
/* measured: restore optimization_level 2 after btlSoundAdvanceSlotQueue. */
// FUN_001F7650
u8 *btlSoundGetCharacterBank(u8 *arg0)
{
    u8 *var_2;
    u32 temp_3;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        if (func_00110d60((s16)datGetDateIndex()) & 1) {
            var_2 = D_0060AC00 + (*(u16 *)(arg0 + 0xA4) * 0xA20);
        } else {
            var_2 = D_0060AC00 + (*(u16 *)(arg0 + 0xA4) * 0xA20) + 0x6F60;
        }
        return var_2;
    }
    temp_3 = *(u16 *)(arg0 + 0xA4);
    if ((s32)temp_3 < 0x100) {
        return NULL;
    }
    if ((s32)temp_3 <= 0x112) {
        goto dispatch;
    }
    return NULL;
dispatch:
    if (temp_3 == 0x214) {
        goto return_214;
    } else if (temp_3 == 0x112) {
        goto return_group;
    } else if (temp_3 == 0x10E) {
        goto return_group;
    } else if (temp_3 == 0x10B) {
        goto return_group;
    } else if (temp_3 == 0x10A) {
        goto return_group;
    } else if (temp_3 == 0x109) {
        goto return_group;
    } else if (temp_3 == 0x108) {
        goto return_group;
    } else if (temp_3 == 0x107) {
        goto return_group;
    } else if (temp_3 == 0x106) {
        goto return_group;
    } else if (temp_3 == 0x105) {
        goto return_group;
    } else if (temp_3 == 0x104) {
        goto return_group;
    } else if (temp_3 == 0x103) {
        goto return_group;
    } else if (temp_3 == 0x102) {
        goto return_group;
    } else if (temp_3 == 0x101) {
        goto return_group;
    } else {
        switch (temp_3) {
        case 0x100:
            goto return_group;
        default:
            goto return_null;
        }
    }
return_group:
    return D_00618AC0 + ((temp_3 - 0x100) * 0xA20);
return_214:
    return D_0061F000;
return_null:
    var_2 = NULL;
    return var_2;
}

// FUN_001F7830
void btlSoundGetPrimaryVoiceSlots(u8 *arg0, s32 arg1, s32 arg2, s16 *arg3, s16 *arg4)
{
    s32 temp_5;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        temp_5 = (s32)datCalcPrimaryPersonaId(*(u8 **)(arg0 + 0xA64)) & 0xFFFF;
        switch (*(u16 *)(arg0 + 0xA4)) {
        case 7:
            if (arg2 != 0) {
                if (arg1 == 3) {
                    *arg3 = -1;
                    *arg4 = -1;
                    goto done;
                }
            }
        default:
            *arg3 = 0;
            *arg4 = *(s16 *)(D_00624B20 + (temp_5 * 4));
            goto done;
        }
    }
    *arg3 = -1;
    *arg4 = -1;
done:
    ;
}

// FUN_001F7910
void btlSoundGetSecondaryVoiceSlots(u8 *arg0, u32 arg1, s32 arg2, s16 *arg3, s16 *arg4)
{
    s32 temp_5;
    u16 temp_4;

    if (*(u8 *)(arg0 + 0xA2) == 0) {
        temp_5 = (s32)datCalcPrimaryPersonaId(*(u8 **)(arg0 + 0xA64)) & 0xFFFF;
        *arg3 = 0;
        temp_4 = *(u16 *)(arg0 + 0xA4);
        switch (temp_4) {
        case 4:
            if ((arg2 != 0) && (arg1 < 2U)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        case 6:
            if ((arg2 != 0) && ((u32)(arg1 - 1) < 2U)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        case 7:
            if ((arg2 != 0) && (arg1 == 3)) {
                *arg4 = 4;
                return;
            }
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        default:
            *arg4 = *(s16 *)(D_00624B22 + (temp_5 * 4));
            return;
        }
    }
    *arg3 = 0;
    switch (*(u16 *)(arg0 + 0xA4)) {
    case 0x109:
        *arg4 = 8;
        break;
    default:
        *arg4 = 0;
        break;
    }
}

// FUN_001F7AD0
void btlSoundRefreshSlotChannel(u8 *arg0)
{
    u16 temp_7;
    u8 *temp_6;
    u32 offset;

    temp_7 = *(u16 *)arg0;
    offset = temp_7 * 6;
    temp_6 = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((*(s16 *)(temp_6 + 0xACC) != *(u16 *)(arg0 + 2)) ||
        (*(s16 *)(temp_6 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045aa90(1, (s16)temp_7);
    }
}

// FUN_001F7B40
s32 btlSoundSetSlotChannel(u8 *arg0)
{
    u16 temp_4;
    u16 temp_6;
    u8 *temp_3;
    u32 offset;

    temp_6 = *(u16 *)(arg0 + 2);
    temp_4 = *(u16 *)arg0;
    offset = temp_4 * 6;
    temp_3 = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((*(s16 *)(temp_3 + 0xACC) != temp_6) ||
        (*(s16 *)(temp_3 + 0xACE) != *(u16 *)(arg0 + 4))) {
        func_0045af60(1, (s16)temp_4, (s16)temp_6,
                      (s16)*(u16 *)(arg0 + 4));
        temp_6 = *(u16 *)(arg0 + 2);
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u16 *)((u8 *)offset + 0xACC) = temp_6;
        temp_6 = *(u16 *)(arg0 + 4);
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u16 *)((u8 *)offset + 0xACE) = temp_6;
        temp_3 = iGpffffb3ac;
        offset = (u32)temp_3;
        temp_4 = *(u16 *)arg0;
        offset = addOffsetFirst(temp_4 * 6, offset);
        *(u8 *)((u8 *)offset + 0xAD0) = 0;
    }
    return 1;
}

