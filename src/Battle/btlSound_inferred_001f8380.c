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

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *arg0, s32 arg1, s32 arg2);
extern s32 sdkSndIsChannelPlaying(s32 arg0);



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

extern void sdkSndFadeOutChannelFrames(s32 arg0, s32 arg1, s32 arg2);

extern s32 func_0045ae10(s32 arg0, s32 arg1, s32 arg2);

extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];



extern u16 datPersonaGetRecordId(u16 arg0);
extern u8 *btlPacketAlloc(s32 type, s32 workSize);



extern s32 btlSoundMarkSlotReady(u8 **arg0);

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




#pragma push
#pragma pop






/* Source unit: src/promoted/code1_001f.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001f.c; members 001f8380-001f9650 */

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
// FUN_001F8380
s32 btlSoundMarkSlotReady(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) |= 0x40;
    }
    return 1;
}

// FUN_001F83B0
u8 *btlSoundCreateMarkReadyPacket(u32 value)
{
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x90B, 0x4);
    *(void **)(packet + 0x6C) = (void *)btlSoundMarkSlotReady;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
    return packet;
}

// FUN_001F8400
s32 btlSoundClearSlotReady(u8 **arg0)
{
    u8 *temp_3;
    u8 *temp_3_2;

    temp_3 = *arg0;
    if (*(s32 *)(temp_3 + 0x98) & 2) {
        temp_3_2 = *(u8 **)(temp_3 + 0xA00);
        *(u16 *)(temp_3_2 + 0x2E0) &= 0xFFBF;
    }
    return 1;
}

// FUN_001F8430
u8 *btlSoundCreateClearReadyPacket(u32 value)
{
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x90C, 0x4);
    *(void **)(packet + 0x6C) = (void *)btlSoundClearSlotReady;
    *(u32 *)*(u8 **)(packet + 0x78) = value;
    return packet;
}

// FUN_001F8480
void btlSoundLoadBanks(void)
{
    void **allocator;
    u8 sp30[0x100];
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;
    s32 temp_2;
    s32 temp_2_2;
    s32 temp_2_3;

    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    allocator = (void **)jtbl_008873E8;
    temp_17 = ((u8 *(*)(u32, u32))allocator[0])(0xBE4, 0x40000);
    sprintf(sp30, &D_00624F60);
    H_Cdvd_StartStreamLoad(3, sp30, 0, temp_17);
    goto loop_3_test;
loop_3_retry:
    if (temp_2 != 4) {
        goto loop_3_test;
    }
    H_Cdvd_StartStreamLoad(3, sp30, 0, temp_17);
loop_3_test:
    temp_2 = func_004c7ef8(3);
    if (temp_2 != 3) {
        goto loop_3_retry;
    }
    iGpffffb460 = 1;
    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    temp_17_2 = ((u8 *(*)(u32, u32))allocator[0])(0x630, 0x40000);
    sprintf(sp30, &D_00624F80);
    H_Cdvd_StartStreamLoad(4, sp30, 0, temp_17_2);
    goto loop_7_test;
loop_7_retry:
    if (temp_2_2 != 4) {
        goto loop_7_test;
    }
    H_Cdvd_StartStreamLoad(4, sp30, 0, temp_17_2);
loop_7_test:
    temp_2_2 = func_004c7ef8(4);
    if (temp_2_2 != 3) {
        goto loop_7_retry;
    }
    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    temp_16 = ((u8 *(*)(u32, u32))allocator[0])(0x4A0, 0x40000);
    sprintf(sp30, &D_00624FA0);
    H_Cdvd_StartStreamLoad(5, sp30, 0, temp_16);
    goto loop_11_test;
loop_11_retry:
    if (temp_2_3 != 4) {
        goto loop_11_test;
    }
    H_Cdvd_StartStreamLoad(5, sp30, 0, temp_16);
loop_11_test:
    temp_2_3 = func_004c7ef8(5);
    if (temp_2_3 != 3) {
        goto loop_11_retry;
    }
    iGpffffb464 = 1;
}

// FUN_001F8690
void btlSoundPlayIndexed(s32 arg0) {
    s32 value;
    u16 index;

    value = *(u16 *)(iGpffffb3ac + 0xB30);
    index = (u16)arg0;
    func_0045ae10(value, 3, index);
}

// FUN_001F86D0
void btlSoundStopBank3(void) {
    sdkSndFadeOutChannelFrames(3, 0, 8);
}

// FUN_001F8700
s32 btlSoundGetPersonaVoiceIndex(u8 *arg0, s32 arg1)
{
    s32 temp_2;
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(s32 *)(temp_4 + 0xA0C) == 0)
    {
        return -1;
    }
    if (*(u8 *)(temp_4 + 0xA2) == 1)
    {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0)
    {
        return arg1 - 1;
    }
    temp_2 = datPersonaGetRecordId(*(u16 *)(temp_4 + 0xA4)) & 0xFFFF;
    switch (temp_2)
    {
    case 0xC0:
    case 0xC2:
    case 0xC4:
    case 0xC6:
    case 0xC8:
    case 0xCA:
    case 0xCC:
        return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x22;
    case 0xC1:
    case 0xC3:
    case 0xC5:
    case 0xC7:
    case 0xC9:
    case 0xCB:
    case 0xCD:
        return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x23;
    default:
        return -1;
    }
}

// FUN_001F8810
s32 btlSoundGetSlotVoiceIndex(u8 *arg0, s32 arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_4 + 0xA2) == 1)
    {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0)
    {
        return -1;
    }
    if (arg1 >= 5)
    {
        return -1;
    }
    if (datCalcIsDead((s32)((u8 *)*(s32 *)(temp_4 + 0xA64)), 0) != 0)
    {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x1001D7) != 0)
    {
        return -1;
    }
    return (s32)D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] +
           (s32)D_00624FD8[arg1];
}

// FUN_001F8920
s32 btlSoundPickActionVoice(u8 *arg0)
{
    extern s32 func_0022bd20(void);
    s32 temp_16;
    s32 var_2;
    u16 temp_2;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) == 0) {
        if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
            var_2 = -1;
        } else {
            temp_16 = (s32)D_00624FC0[*(u16 *)(temp_3 + 0xA4)] + 7;
            var_2 = temp_16 + datCalcRandomBelow(3);
        }
        return var_2;
    }
    if (func_0022bd20() == 0) {
        return -1;
    }
    temp_2 = *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4);
    switch (temp_2) {
    case 0x100:
        return datCalcRandomBelow(3) + 0x417;
    case 0x101:
        return datCalcRandomBelow(3) + 0x429;
    case 0x102:
        return datCalcRandomBelow(3) + 0x43C;
    case 0x103:
        return datCalcRandomBelow(3) + 0x44F;
    case 0x104:
        return datCalcRandomBelow(3) + 0x462;
    case 0x105:
        return datCalcRandomBelow(3) + 0x475;
    case 0x106:
        return datCalcRandomBelow(3) + 0x488;
    case 0x107:
        return datCalcRandomBelow(3) + 0x49B;
    case 0x108:
        return datCalcRandomBelow(3) + 0x4AE;
    case 0x109:
        return datCalcRandomBelow(3) + 0x4C3;
    case 0x112:
        return datCalcRandomBelow(3) + 0x4FC;
    case 0x10A:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x10F:
    case 0x110:
    case 0x111:
    default:
        return -1;
    }
}

// FUN_001F8B00
s32 btlSoundPickIdleVoice(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x78;
    return value + datCalcRandomBelow(5);
}

// FUN_001F8B90
s32 btlSoundPickHurtVoice(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x63;
    return value + datCalcRandomBelow(3);
}

// FUN_001F8C20
s32 btlSoundPickDamageVoice(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (arg1 != 0) {
        value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x6F;
        return value + datCalcRandomBelow(3);
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x72;
    return value + datCalcRandomBelow(3);
}

// FUN_001F8CE0
s32 btlSoundPickDownVoice(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x75;
    return value + datCalcRandomBelow(3);
}

// FUN_001F8D70
s32 btlSoundPickCommandVoice(u8 *arg0, s32 arg1)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (arg1 != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x2C;
    return value + datCalcRandomBelow(3);
}

// FUN_001F8E10
s32 btlSoundPickStartVoice(u8 *arg0)
{
    s32 value;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(work + 0xA4)] + 0x29;
    return value + datCalcRandomBelow(3);
}

/* measured: opt_propagation off preserves btlSoundPickPartnerCallVoice's loop constants. */
/* measured: btlSoundPickPartnerCallVoice MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001F8EA0
s32 btlSoundPickPartnerCallVoice(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x10;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
done:
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}

/* measured: close opt_propagation after btlSoundPickPartnerCallVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerReplyVoice's loop constants. */
// FUN_001F8F40
s32 btlSoundPickPartnerReplyVoice(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x16;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}

/* measured: close opt_propagation after btlSoundPickPartnerReplyVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerAssistVoice's loop constants. */
// FUN_001F8FE0
s32 btlSoundPickPartnerAssistVoice(u8 *arg0, s32 arg1)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(work + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    value = 0x1C;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == arg1) {
            break;
        }
        if ((i != five) && (i != *(u16 *)(work + 0xA4))) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[*(u16 *)(work + 0xA4)];
}

/* measured: close opt_propagation after btlSoundPickPartnerAssistVoice probe. */
// FUN_001F9080
s32 btlSoundPickGuardVoice(u8 *arg0) {
    u8 *p;

    p = *(u8 **)(arg0 + 0x30);
    if (p[0xA2] != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    return D_00624FC0[*(u16 *)(p + 0xA4)] + 0x45;
}

/* measured: opt_propagation off tested for btlSoundPickRandomPartnerVoice; retains loop constants. */
// FUN_001F90E0
s32 btlSoundPickRandomPartnerVoice(u8 *arg0)
{
    s32 temp_16;
    s32 temp_4;
    u8 *var_17;
    s32 var_16;
    s32 var_5;
    u32 var_6;
    s32 var_7;
    u8 *temp_3;
    u8 *temp_4_2;
    u8 *sp60[12];

    if (sdkSndIsChannelPlaying(3) == 1) {
        return -1;
    }
    temp_3 = *(u8 **)(arg0 + 0x30);
    if (*(u8 *)(temp_3 + 0xA2) != 0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(temp_3 + 0xA64), 0x110) != 0) {
        return -1;
    }
    var_16 = 0;
    var_17 = *(u8 **)(iGpffffb3ac + 0x178);
    while (var_17 != NULL) {
        if ((datCalcIsDead((s32)(*(u8 **)(var_17 + 0xA64)), 0) == 0) &&
            (datCalcChkBadStatus(*(s32 *)(var_17 + 0xA64), 0x1001D7) == 0) &&
            (*(u16 *)(var_17 + 0xA4) != 1) &&
            (var_17 != *(u8 **)(arg0 + 0x30))) {
            sp60[(u16)var_16] = var_17;
            var_16 = (u16)(var_16 + 1);
        }
        var_17 = *(u8 **)(var_17 + 0xA6C);
    }
    temp_4 = (u16)var_16;
    if (temp_4 == 0) {
        return -1;
    }
    temp_4_2 = sp60[datCalcRandomBelow(temp_4)];
    if (temp_4_2 == NULL) {
        return -1;
    }
    var_6 = 0x32;
    var_5 = 1;
    var_7 = 5;
    while (var_5 <= 8) {
        if (var_5 == *(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)) {
            break;
        }
        if ((var_5 != var_7) && (var_5 != *(u16 *)(temp_4_2 + 0xA4))) {
            var_6 += 3;
        }
        var_5 += 1;
    }
    temp_16 = var_6 + D_00624FC0[*(u16 *)(temp_4_2 + 0xA4)];
    return temp_16 + datCalcRandomBelow(3, var_5, var_6);
}

/* measured: close opt_propagation after btlSoundPickRandomPartnerVoice. */
// FUN_001F92C0
s32 btlSoundPickStatusCueVoice(u8 *arg0)
{
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x51;
    return value + datCalcRandomBelow(3);
}

// FUN_001F93A0
s32 btlSoundPickHpTierVoice(u8 *arg0)
{
    s32 type;
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    type = func_001ef720(2, 0x80000) & 0xFFFF;
    switch (type) {
    case 4:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x54;
        return value + datCalcRandomBelow(3);
    case 3:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x57;
        return value + datCalcRandomBelow(3);
    case 2:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x5A;
        return value + datCalcRandomBelow(3);
    case 1:
        value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x5D;
        return value + datCalcRandomBelow(3);
    }
    return -1;
}

// FUN_001F9570
s32 btlSoundPickGroupVoice(u8 *arg0)
{
    s32 value;

    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0) {
        return -1;
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x69;
    return value + datCalcRandomBelow(3);
}

// FUN_001F9650
s32 btlSoundPickKnockVoice(u8 *arg0)
{
    s32 value;

    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0) {
        return -1;
    }
    if (*(u8 **)(iGpffffb3ac + 0x170) == arg0) {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[*(u16 *)(*(u8 **)(arg0 + 0x30) + 0xA4)] + 0x66;
    return value + datCalcRandomBelow(3);
}

