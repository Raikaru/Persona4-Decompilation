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
#include "btl_sound_internal.h"
/* Force the offset operand into the first addu slot. */
static inline u32 addOffsetFirst(u32 offset, u32 base) {
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
extern s32 (*D_00624FF0[])(u8 *input, s32 value, s32 option);



extern u8 D_0060AB08[];
extern s16 datGetDateIndex(void);
extern s32 calGetDayWindowFlags(s32 day);
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






/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001f; members 001f7650-001f7b40 */

extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlSoundRollStatusCure(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *action);
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
/* Select the character voice bank for the calendar window or supported enemy character ID. */
// FUN_001F7650
u8 *btlSoundGetCharacterBank(u8 *unit)
{
    u8 *bank;
    u32 characterId;

    if (((BtlUnit *)unit)->genus == 0) {
        if (calGetDayWindowFlags((s16)datGetDateIndex()) & 1) {
            bank = D_0060AC00 + (((BtlUnit *)unit)->charId * 0xA20);
        } else {
            bank = D_0060AC00 + (((BtlUnit *)unit)->charId * 0xA20) + 0x6F60;
        }
        return bank;
    }
    characterId = ((BtlUnit *)unit)->charId;
    if ((s32)characterId < 0x100) {
        return NULL;
    }
    if ((s32)characterId <= 0x112) {
        goto dispatch;
    }
    return NULL;
dispatch:
    if (characterId == 0x214) {
        goto return_214;
    } else if (characterId == 0x112) {
        goto return_group;
    } else if (characterId == 0x10E) {
        goto return_group;
    } else if (characterId == 0x10B) {
        goto return_group;
    } else if (characterId == 0x10A) {
        goto return_group;
    } else if (characterId == 0x109) {
        goto return_group;
    } else if (characterId == 0x108) {
        goto return_group;
    } else if (characterId == 0x107) {
        goto return_group;
    } else if (characterId == 0x106) {
        goto return_group;
    } else if (characterId == 0x105) {
        goto return_group;
    } else if (characterId == 0x104) {
        goto return_group;
    } else if (characterId == 0x103) {
        goto return_group;
    } else if (characterId == 0x102) {
        goto return_group;
    } else if (characterId == 0x101) {
        goto return_group;
    } else {
        switch (characterId) {
        case 0x100:
            goto return_group;
        default:
            goto return_null;
        }
    }
return_group:
    return D_00618AC0 + ((characterId - 0x100) * 0xA20);
return_214:
    return D_0061F000;
return_null:
    bank = NULL;
    return bank;
}

/* Resolve primary persona voice slots, suppressing the unsupported special action. */
// FUN_001F7830
void btlSoundGetPrimaryVoiceSlots(u8 *unit, s32 actionKind, s32 special, s16 *bankOut, s16 *slotOut)
{
    s32 personaId;

    if (((BtlUnit *)unit)->genus == 0) {
        personaId = (s32)datCalcPrimaryPersonaId(*(u8 **)&((BtlUnit *)unit)->datUnit) & 0xFFFF;
        switch (((BtlUnit *)unit)->charId) {
        case 7:
            if (special != 0) {
                if (actionKind == 3) {
                    *bankOut = -1;
                    *slotOut = -1;
                    goto done;
                }
            }
        default:
            *bankOut = 0;
            *slotOut = ((BtlSoundPersonaVoice *)(D_00624B20 + personaId * 4))->primary;
            goto done;
        }
    }
    *bankOut = -1;
    *slotOut = -1;
done:
    ;
}

/* Resolve secondary voice slots with character-specific special-action overrides. */
// FUN_001F7910
void btlSoundGetSecondaryVoiceSlots(u8 *unit, u32 actionKind, s32 special, s16 *bankOut, s16 *slotOut)
{
    s32 personaId;
    u16 characterId;

    if (((BtlUnit *)unit)->genus == 0) {
        personaId = (s32)datCalcPrimaryPersonaId(*(u8 **)&((BtlUnit *)unit)->datUnit) & 0xFFFF;
        *bankOut = 0;
        characterId = ((BtlUnit *)unit)->charId;
        switch (characterId) {
        case 4:
            if ((special != 0) && (actionKind < 2U)) {
                *slotOut = 4;
                return;
            }
            *slotOut = ((BtlSoundPersonaVoice *)(D_00624B22 - 2 + personaId * 4))->secondary;
            return;
        case 6:
            if ((special != 0) && ((u32)(actionKind - 1) < 2U)) {
                *slotOut = 4;
                return;
            }
            *slotOut = ((BtlSoundPersonaVoice *)(D_00624B22 - 2 + personaId * 4))->secondary;
            return;
        case 7:
            if ((special != 0) && (actionKind == 3)) {
                *slotOut = 4;
                return;
            }
            *slotOut = ((BtlSoundPersonaVoice *)(D_00624B22 - 2 + personaId * 4))->secondary;
            return;
        default:
            *slotOut = ((BtlSoundPersonaVoice *)(D_00624B22 - 2 + personaId * 4))->secondary;
            return;
        }
    }
    *bankOut = 0;
    switch (((BtlUnit *)unit)->charId) {
    case 0x109:
        *slotOut = 8;
        break;
    default:
        *slotOut = 0;
        break;
    }
}

/* Stop the cached voice channel when either requested selector has changed. */
// FUN_001F7AD0
void btlSoundRefreshSlotChannel(u8 *work)
{
    u16 channel;
    u8 *slotBase;
    u32 offset;

    channel = ((BtlSoundCueWork *)work)->channel;
    offset = channel * 6;
    slotBase = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((((BtlSoundQueue *)(slotBase + 0xAC8))->channels[0].cue != ((BtlSoundCueWork *)work)->cue) ||
        (((BtlSoundQueue *)(slotBase + 0xAC8))->channels[0].variant != ((BtlSoundCueWork *)work)->variant)) {
        sdkSndStopStream(1, (s16)channel);
    }
}

/* Start a changed voice cue, cache its selectors and reset the expiry timer. */
// FUN_001F7B40
s32 btlSoundSetSlotChannel(u8 *work)
{
    BtlSoundCueWork *cueWork = (BtlSoundCueWork *)(work);
    u16 channel;
    u16 cue;
    u8 *slotBase;
    u32 offset;

    /* measured: typing this request reload grows SetSlotChannel from 224 to 232 bytes; later cache accesses are typed. */
    cue = cueWork->cue;
    channel = ((BtlSoundCueWork *)work)->channel;
    offset = channel * 6;
    slotBase = (u8 *)(offset + (u32)iGpffffb3ac);
    if ((((BtlSoundQueue *)(slotBase + 0xAC8))->channels[0].cue != cue) ||
        (((BtlSoundQueue *)(slotBase + 0xAC8))->channels[0].variant != ((BtlSoundCueWork *)work)->variant)) {
        sdkSndStartStream(1, (s16)channel, (s16)cue,
                      (s16)cueWork->variant);
        cue = ((BtlSoundCueWork *)work)->cue;
        slotBase = iGpffffb3ac;
        offset = (u32)slotBase;
        channel = ((BtlSoundCueWork *)work)->channel;
        offset = addOffsetFirst(channel * 6, offset);
        *(u16 *)&((BtlSoundQueue *)((u8 *)offset + 0xAC8))->channels[0].cue = cue;
        cue = ((BtlSoundCueWork *)work)->variant;
        slotBase = iGpffffb3ac;
        offset = (u32)slotBase;
        channel = ((BtlSoundCueWork *)work)->channel;
        offset = addOffsetFirst(channel * 6, offset);
        *(u16 *)&((BtlSoundQueue *)((u8 *)offset + 0xAC8))->channels[0].variant = cue;
        slotBase = iGpffffb3ac;
        offset = (u32)slotBase;
        channel = ((BtlSoundCueWork *)work)->channel;
        offset = addOffsetFirst(channel * 6, offset);
        *(u8 *)&((BtlSoundQueue *)((u8 *)offset + 0xAC8))->channels[0].frame = 0;
    }
    return 1;
}
