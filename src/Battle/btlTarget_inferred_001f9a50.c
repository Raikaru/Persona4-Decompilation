#include "member_access.h"
#include "btl_voice_internal.h"
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

extern s32 sdkSndFadeOutChannelFrames(s16 channelIndex, s16 requestValue, s32 fadeFrames);

extern s32 sdkSndStartIndexedSource(s32 sourceAux, s32 channelIndex, s32 cueId);

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


extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlSoundRollStatusCure(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *action);
extern void btlSoundAdvanceSlotQueue(void);
extern s32 btlSoundPickPartnerCallVoice(u8 *action, s32 variant);
extern s32 btlSoundPickPartnerReplyVoice(u8 *action, s32 variant);
extern s32 btlSoundPickPartnerAssistVoice(u8 *action, s32 variant);
extern s32 btlSoundPickRandomPartnerVoice(u8 *action);
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: retail loads the shift constant before branching into the loop test; no source form
 * reproduces that order. */

#pragma push
#pragma pop
/* Play a cue from the bank selected by the voice-id packet. */
// FUN_001F9A50
void btlVoicePlayIdCue(s32 context, s32 value) {
    s32 f = ((BtlVoicePlayback *)((u8 *)iGpffffb3ac + 0xB2C))->idBank;
    sdkSndStartIndexedSource((u16)f, (u16)value, (u16)context);
}

/* Fade sound channel 1 over eight frames. */
// FUN_001F9A90
void btlVoiceFadeOut(void) {
    sdkSndFadeOutChannelFrames(1, 0, 8);
}

/* Select the voice-id bank once and wait for the result/playback-completion condition. */
// FUN_001F9AC0
s32 btlVoiceIdPacketUpdate(u8 *context)
{
    s32 value;
    s32 code;
    s32 flag;

    if (((BtlVoiceIdWork *)context)->state == 0) {
        if (((BtlVoiceIdWork *)context)->voiceId == 0) {
            value = 0x6C;
        } else {
            value = 0x69;
        }
        code = value & 0xFFFF;
        switch (code) {
        case 0x6C:
            ((BtlVoicePlayback *)(iGpffffb3ac + 0xB2C))->idBank = 5;
            break;
        case 0x69:
            ((BtlVoicePlayback *)(iGpffffb3ac + 0xB2C))->idBank = 4;
            break;
        default:
            break;
        }
        ((BtlVoiceIdWork *)context)->result = 0;
        MEMBER(s32, context, BtlVoiceIdWork, state) = 1;
    }
    if (((BtlVoiceIdWork *)context)->result == 0) {
        goto return_one_a;
    }
    flag = (((BtlVoicePlayback *)(iGpffffb3ac + 0xB2C))->idFlags & 1) != 0;
    /* The flag test is written as a switch to reproduce retail's branch layout. */
    switch (flag) {
    case 0:
        goto return_zero;
    default:
        goto return_one_b;
    }
return_one_b:
    return 1;
return_one_a:
    return 1;
return_zero:
    return 0;
}

