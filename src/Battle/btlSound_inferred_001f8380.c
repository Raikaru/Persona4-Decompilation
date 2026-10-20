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
#include "datPersona_internal.h"
#include "model_battle_internal.h"
#include "btl_voice_internal.h"
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
extern u32 datCalcChkBadStatus(s32, u32);
extern u8 *iGpffffb3c4;
extern u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern u8 *iGpffffb3d0;
extern u8 *iGpffffb3e0;

extern void (*jtbl_008873EC[])(void *ptr);
extern s32 (*D_00624FF0[])(u8 *, s32, s32);
extern s32 sdkSndIsChannelPlaying(s32);



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

extern void sdkSndFadeOutChannelFrames(s32, s32, s32);

extern s32 sdkSndStartIndexedSource(s32, s32, s32);

extern u8 iGpffffb468;
extern u8 iGpffffb469;
extern s16 iGpffffb46e;
extern u8 D_006251F0[];



extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);



extern s32 btlSoundMarkSlotReady(u8 **);

extern s32 btlSoundClearSlotReady(u8 **);
extern s32 iGpffffb464;
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void sprintf(void *dst, void *fmt, ...);
extern s32 H_Cdvd_StartStreamLoad(s32, void *, s32, void *);
extern s32 func_004c7ef8(s32);
extern u8 D_00624F50[];
extern u8 D_00624F60[];
extern u8 D_00624F80[];
extern u8 D_00624FA0[];




#pragma push
#pragma pop






/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f8380-001f9650 */

extern s32 btlActionHasNoTargetClass(u32);
extern s32 btlSoundRollStatusCure(u8 *);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *);
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
/* Set model flag 0x40 only for a unit with an active model. */
// FUN_001F8380
s32 btlSoundMarkSlotReady(u8 **work)
{
    /* Ready state shares the model motion flags halfword. */
    u8 *unit;
    u8 *model;

    unit = *work;
    if ((s32)(((BtlUnit *)unit)->flags2) & 2) {
        model = ((BtlUnit *)unit)->layerHandle;
        ((Model *)model)->motion.flags |= 0x40;
    }
    return 1;
}

/* Create packet 0x90B to set the active model ready bit on its unit. */
// FUN_001F83B0
u8 *btlSoundCreateMarkReadyPacket(u32 value)
{
    /* The packet payload holds one scalar unit address. */
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x90B, 0x4);
    ((BtlPacket *)packet)->updateFunc = (void *)btlSoundMarkSlotReady;
    *((u32 *)((BtlPacket *)packet)->workData) = value;
    return packet;
}

/* Clear model flag 0x40 only for a unit with an active model. */
// FUN_001F8400
s32 btlSoundClearSlotReady(u8 **work)
{
    /* Ready state shares the model motion flags halfword. */
    u8 *unit;
    u8 *model;

    unit = *work;
    if ((s32)(((BtlUnit *)unit)->flags2) & 2) {
        model = ((BtlUnit *)unit)->layerHandle;
        ((Model *)model)->motion.flags &= 0xFFBF;
    }
    return 1;
}

/* Create packet 0x90C to clear the active model ready bit on its unit. */
// FUN_001F8430
u8 *btlSoundCreateClearReadyPacket(u32 value)
{
    /* The packet payload holds one scalar unit address. */
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x90C, 0x4);
    ((BtlPacket *)packet)->updateFunc = (void *)btlSoundClearSlotReady;
    *((u32 *)((BtlPacket *)packet)->workData) = value;
    return packet;
}

/* Allocate and stream-load banks three through five, retrying requests that return state four. */
// FUN_001F8480
void btlSoundLoadBanks(void)
{
    void **allocator;
    u8 path[0x100];
    u8 *bankFive;
    u8 *bankThree;
    u8 *bankFour;
    s32 bankThreeStatus;
    s32 bankFourStatus;
    s32 bankFiveStatus;

    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    allocator = (void **)jtbl_008873E8;
    bankThree = ((u8 *(*)(u32, u32))allocator[0])(0xBE4, 0x40000);
    sprintf(path, &D_00624F60);
    H_Cdvd_StartStreamLoad(3, path, 0, bankThree);
    goto loop_3_test;
loop_3_retry:
    if (bankThreeStatus != 4) {
        goto loop_3_test;
    }
    H_Cdvd_StartStreamLoad(3, path, 0, bankThree);
loop_3_test:
    bankThreeStatus = func_004c7ef8(3);
    if (bankThreeStatus != 3) {
        goto loop_3_retry;
    }
    iGpffffb460 = 1;
    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    bankFour = ((u8 *(*)(u32, u32))allocator[0])(0x630, 0x40000);
    sprintf(path, &D_00624F80);
    H_Cdvd_StartStreamLoad(4, path, 0, bankFour);
    goto loop_7_test;
loop_7_retry:
    if (bankFourStatus != 4) {
        goto loop_7_test;
    }
    H_Cdvd_StartStreamLoad(4, path, 0, bankFour);
loop_7_test:
    bankFourStatus = func_004c7ef8(4);
    if (bankFourStatus != 3) {
        goto loop_7_retry;
    }
    chkmemAllocSiteTag(&D_00624F50, 0x3A);
    bankFive = ((u8 *(*)(u32, u32))allocator[0])(0x4A0, 0x40000);
    sprintf(path, &D_00624FA0);
    H_Cdvd_StartStreamLoad(5, path, 0, bankFive);
    goto loop_11_test;
loop_11_retry:
    if (bankFiveStatus != 4) {
        goto loop_11_test;
    }
    H_Cdvd_StartStreamLoad(5, path, 0, bankFive);
loop_11_test:
    bankFiveStatus = func_004c7ef8(5);
    if (bankFiveStatus != 3) {
        goto loop_11_retry;
    }
    iGpffffb464 = 1;
}

/* Play the narrowed voice index on bank/channel three using the stored sound selector. */
// FUN_001F8690
void btlSoundPlayIndexed(s32 voiceIndex) {
    /* The voice playback state supplies the indexed-source bank. */
    s32 value;
    u16 index;

    value = ((BtlVoicePlayback *)(iGpffffb3ac + 0xB2C))->bank;
    index = (u16)voiceIndex;
    sdkSndStartIndexedSource(value, 3, index);
}

// FUN_001F86D0
void btlSoundStopBank3(void) {
    sdkSndFadeOutChannelFrames(3, 0, 8);
}

/* Resolve a persona voice variant; missing child units and enemy units have no voice. */
// FUN_001F8700
s32 btlSoundGetPersonaVoiceIndex(u8 *action, s32 voiceIndex)
{
    BtlAction *actionState = (BtlAction *)(action);
    /* measured: access-site typing changes reloads; per-object typed aliases retain the retail sequence. */
    s32 personaId;
    u8 *unit;

    unit = (u8 *)(((BtlAction *)action)->unit);
    if ((s32)(((BtlUnit *)unit)->childUnit) == 0)
    {
        return -1;
    }
    if (((BtlUnit *)unit)->genus == 1)
    {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action)
    {
        return voiceIndex - 1;
    }
    personaId = datPersonaGetRecordId(((BtlUnit *)unit)->charId) & 0xFFFF;
    switch (personaId)
    {
    case 0xC0:
    case 0xC2:
    case 0xC4:
    case 0xC6:
    case 0xC8:
    case 0xCA:
    case 0xCC:
        return (s32)D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x22;
    case 0xC1:
    case 0xC3:
    case 0xC5:
    case 0xC7:
    case 0xC9:
    case 0xCB:
    case 0xCD:
        return (s32)D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x23;
    default:
        return -1;
    }
}

/* Resolve a party slot voice only for a living, status-eligible non-selected actor. */
// FUN_001F8810
s32 btlSoundGetSlotVoiceIndex(u8 *action, s32 slot)
{
    BtlAction *actionState = (BtlAction *)(action);
    /* measured: access-site typing changes reloads; per-object typed aliases retain the retail sequence. */
    u8 *unit;

    unit = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)unit)->genus == 1)
    {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action)
    {
        return -1;
    }
    if (slot >= 5)
    {
        return -1;
    }
    if (datCalcIsDead((s32)((u8 *)(s32)(((BtlUnit *)unit)->datUnit)), 0) != 0)
    {
        return -1;
    }
    if (datCalcChkBadStatus(*(s32 *)&((BtlUnit *)(u8 *)(actionState->unit))->datUnit, 0x1001D7) != 0)
    {
        return -1;
    }
    return (s32)D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] +
           (s32)D_00624FD8[slot];
}

/* Choose a random action voice from the unit-specific range, or return -1 when unavailable. */
// FUN_001F8920
s32 btlSoundPickActionVoice(u8 *action)
{
    BtlAction *actionState = (BtlAction *)(action);
    /* measured: access-site typing changes reloads; per-object typed aliases retain the retail sequence. */
    extern s32 btlEncounterIsBoss(void);
    s32 voiceBase;
    s32 voice;
    u16 unitId;
    u8 *unit;

    unit = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)unit)->genus == 0) {
        if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
            voice = -1;
        } else {
            voiceBase = (s32)D_00624FC0[((BtlUnit *)unit)->charId] + 7;
            voice = voiceBase + datCalcRandomBelow(3);
        }
        return voice;
    }
    if (btlEncounterIsBoss() == 0) {
        return -1;
    }
    unitId = ((BtlUnit *)(u8 *)(actionState->unit))->charId;
    switch (unitId) {
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

/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F8B00
s32 btlSoundPickIdleVoice(u8 *action)
{
    s32 value;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    value = D_00624FC0[((BtlUnit *)work)->charId] + 0x78;
    return value + datCalcRandomBelow(5);
}

/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F8B90
s32 btlSoundPickHurtVoice(u8 *action)
{
    s32 value;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    value = D_00624FC0[((BtlUnit *)work)->charId] + 0x63;
    return value + datCalcRandomBelow(3);
}

/* Select the unit-relative voice variant after excluding enemy and selected actors. */
// FUN_001F8C20
s32 btlSoundPickDamageVoice(u8 *action, s32 variant)
{
    s32 value;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    if (variant != 0) {
        value = D_00624FC0[((BtlUnit *)work)->charId] + 0x6F;
        return value + datCalcRandomBelow(3);
    }
    value = D_00624FC0[((BtlUnit *)work)->charId] + 0x72;
    return value + datCalcRandomBelow(3);
}

/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F8CE0
s32 btlSoundPickDownVoice(u8 *action)
{
    s32 value;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    value = D_00624FC0[((BtlUnit *)work)->charId] + 0x75;
    return value + datCalcRandomBelow(3);
}

/* Select the unit-relative voice variant after excluding enemy and selected actors. */
// FUN_001F8D70
s32 btlSoundPickCommandVoice(u8 *action, s32 variant)
{
    s32 value;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    if (variant != 0) {
        return -1;
    }
    value = D_00624FC0[((BtlUnit *)work)->charId] + 0x2C;
    return value + datCalcRandomBelow(3);
}

/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F8E10
s32 btlSoundPickStartVoice(u8 *action)
{
    s32 value;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    value = D_00624FC0[((BtlUnit *)work)->charId] + 0x29;
    return value + datCalcRandomBelow(3);
}

/* measured: opt_propagation off preserves btlSoundPickPartnerCallVoice's loop constants. */
/* measured: btlSoundPickPartnerCallVoice MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Select the unit-relative voice variant after excluding enemy and selected actors. */
// FUN_001F8EA0
s32 btlSoundPickPartnerCallVoice(u8 *action, s32 variant)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    value = 0x10;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == variant) {
            break;
        }
        if ((i != five) && (i != ((BtlUnit *)work)->charId)) {
            value += 1;
        }
        i += 1;
    }
done:
    return value + D_00624FC0[((BtlUnit *)work)->charId];
}

/* measured: close opt_propagation after btlSoundPickPartnerCallVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerReplyVoice's loop constants. */
/* Select the unit-relative voice variant after excluding enemy and selected actors. */
// FUN_001F8F40
s32 btlSoundPickPartnerReplyVoice(u8 *action, s32 variant)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    value = 0x16;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == variant) {
            break;
        }
        if ((i != five) && (i != ((BtlUnit *)work)->charId)) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[((BtlUnit *)work)->charId];
}

/* measured: close opt_propagation after btlSoundPickPartnerReplyVoice probe. */
/* measured: opt_propagation off preserves btlSoundPickPartnerAssistVoice's loop constants. */
/* Select the unit-relative voice variant after excluding enemy and selected actors. */
// FUN_001F8FE0
s32 btlSoundPickPartnerAssistVoice(u8 *action, s32 variant)
{
    s32 five;
    s32 value;
    s32 i;
    u8 *work;

    work = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)work)->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    value = 0x1C;
    i = 1;
    five = 5;
    while (i <= 8) {
        if (i == variant) {
            break;
        }
        if ((i != five) && (i != ((BtlUnit *)work)->charId)) {
            value += 1;
        }
        i += 1;
    }
    return value + D_00624FC0[((BtlUnit *)work)->charId];
}

/* measured: close opt_propagation after btlSoundPickPartnerAssistVoice probe. */
/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F9080
s32 btlSoundPickGuardVoice(u8 *action) {
    u8 *p;

    p = (u8 *)(((BtlAction *)action)->unit);
    if (p[0xA2] != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    return D_00624FC0[((BtlUnit *)p)->charId] + 0x45;
}

/* measured: opt_propagation off tested for btlSoundPickRandomPartnerVoice; retains loop constants. */
/* Choose a living eligible party partner while channel three is idle, then select its voice variant. */
// FUN_001F90E0
s32 btlSoundPickRandomPartnerVoice(u8 *action)
{
    BtlUnit *unitState;
    BtlAction *actionState = (BtlAction *)(action);
    /* measured: access-site typing changes reloads; per-object typed aliases retain the retail sequence. */
    s32 voiceBase;
    s32 count;
    u8 *candidate;
    s32 candidateCount;
    s32 unitId;
    u32 voiceOffset;
    s32 skippedId;
    u8 *unit;
    u8 *partner;
    u8 *candidates[12];

    if (sdkSndIsChannelPlaying(3) == 1) {
        return -1;
    }
    unit = (u8 *)(((BtlAction *)action)->unit);
    if (((BtlUnit *)unit)->genus != 0) {
        return -1;
    }
    if (datCalcChkBadStatus((s32)(((BtlUnit *)unit)->datUnit), 0x110) != 0) {
        return -1;
    }
    candidateCount = 0;
    candidate = ((BtlBattleState *)iGpffffb3ac)->unitLists[0];
    while (candidate != NULL) {
        unitState = (BtlUnit *)candidate;
        if ((datCalcIsDead((s32)((u8 *)(((BtlUnit *)candidate)->datUnit)), 0) == 0) &&
            (datCalcChkBadStatus(*(s32 *)&unitState->datUnit, 0x1001D7) == 0) &&
            (((BtlUnit *)candidate)->charId != 1) &&
            (candidate != (u8 *)(actionState->unit))) {
            candidates[(u16)candidateCount] = candidate;
            candidateCount = (u16)(candidateCount + 1);
        }
        candidate = (u8 *)(((BtlUnit *)candidate)->nextUnit);
    }
    count = (u16)candidateCount;
    if (count == 0) {
        return -1;
    }
    partner = candidates[datCalcRandomBelow(count)];
    if (partner == NULL) {
        return -1;
    }
    voiceOffset = 0x32;
    unitId = 1;
    skippedId = 5;
    while (unitId <= 8) {
        if (unitId == ((BtlUnit *)(u8 *)(actionState->unit))->charId) {
            break;
        }
        if ((unitId != skippedId) && (unitId != ((BtlUnit *)partner)->charId)) {
            voiceOffset += 3;
        }
        unitId += 1;
    }
    voiceBase = voiceOffset + D_00624FC0[((BtlUnit *)partner)->charId];
    return voiceBase + datCalcRandomBelow(3, unitId, voiceOffset);
}

/* measured: close opt_propagation after btlSoundPickRandomPartnerVoice. */
/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F92C0
s32 btlSoundPickStatusCueVoice(u8 *action)
{
    BtlAction *actionState = (BtlAction *)(action);
    /* measured: access-site typing changes reloads; per-object typed aliases retain the retail sequence. */
    s32 value;

    if (((s32)(((BtlBattleState *)iGpffffb3ac)->flags) & 0x200000) != 0) {
        return -1;
    }
    if (((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    if (datCalcChkBadStatus((s32)(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x51;
    return value + datCalcRandomBelow(3);
}

/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F93A0
s32 btlSoundPickHpTierVoice(u8 *action)
{
    BtlAction *actionState = (BtlAction *)(action);
    /* measured: access-site typing changes reloads; per-object typed aliases retain the retail sequence. */
    s32 type;
    s32 value;

    if (((s32)(((BtlBattleState *)iGpffffb3ac)->flags) & 0x200000) != 0) {
        return -1;
    }
    if (((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    if (datCalcChkBadStatus((s32)(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit),
                      0x1001D7) != 0) {
        return -1;
    }
    type = func_001ef720(2, 0x80000) & 0xFFFF;
    switch (type) {
    case 4:
        value = D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x54;
        return value + datCalcRandomBelow(3);
    case 3:
        value = D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x57;
        return value + datCalcRandomBelow(3);
    case 2:
        value = D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x5A;
        return value + datCalcRandomBelow(3);
    case 1:
        value = D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x5D;
        return value + datCalcRandomBelow(3);
    }
    return -1;
}

/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F9570
s32 btlSoundPickGroupVoice(u8 *action)
{
    BtlAction *actionState = (BtlAction *)(action);
    /* measured: access-site typing changes reloads; per-object typed aliases retain the retail sequence. */
    s32 value;

    if (((s32)(((BtlBattleState *)iGpffffb3ac)->flags) & 0x200000) != 0) {
        return -1;
    }
    if (((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    if (datCalcChkBadStatus((s32)(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x69;
    return value + datCalcRandomBelow(3);
}

/* Return a unit-relative voice index, or -1 when the actor is not eligible for this cue. */
// FUN_001F9650
s32 btlSoundPickKnockVoice(u8 *action)
{
    BtlAction *actionState = (BtlAction *)(action);
    /* measured: access-site typing changes reloads; per-object typed aliases retain the retail sequence. */
    s32 value;

    if (((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->genus != 0) {
        return -1;
    }
    if (((BtlBattleState *)iGpffffb3ac)->selectedAction == action) {
        return -1;
    }
    if (datCalcChkBadStatus((s32)(((BtlUnit *)((u8 *)(((BtlAction *)action)->unit)))->datUnit),
                      0x1001D7) != 0) {
        return -1;
    }
    value = D_00624FC0[((BtlUnit *)(u8 *)(actionState->unit))->charId] + 0x66;
    return value + datCalcRandomBelow(3);
}

