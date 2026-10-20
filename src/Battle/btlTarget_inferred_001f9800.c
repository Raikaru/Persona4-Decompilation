#include "member_access.h"
#include "model_battle_internal.h"
#include "btl_voice_internal.h"
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
extern s32 sdkSndIsChannelPlaying(s16 channelIndex);


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
/* measured: opt_loop_invariants on hoists the loop's one constant before the entry test, as retail
 * does. */

#pragma push
#pragma pop
/* Run the voice selector once, wait for channel 3, and bracket the unit/model talk flags; model
 * motion flag 0x20 gates talk animation. */
// FUN_001F9800
s32 btlVoicePacketUpdate(u8 *packetData)
{
    s32 voiceId;
    u8 *action;
    u8 *finishingUnit;
    u8 *finishingModel;
    u8 *speakingUnit;
    u8 *speakingModel;

    if ((((BtlVoicePlayback *)(iGpffffb3ac + 0xB2C))->flags & 1) == 0) {
        return 1;
    }
    action = *(u8 **)packetData;
    if (((BtlVoicePacketWork *)packetData)->started == 0) {
        if ((action != NULL) &&
            ((((BtlAction *)action)->unk_1a & 1) == 0)) {
            return 1;
        }
        voiceId = D_00624FF0[((BtlVoicePacketWork *)packetData)->callbackIndex](
            action, ((BtlVoicePacketWork *)packetData)->argument, ((BtlVoicePacketWork *)packetData)->extraArgument);
        if (voiceId == -1) {
            return 1;
        }
        sdkSndStartIndexedSource(((BtlVoicePlayback *)(iGpffffb3ac + 0xB2C))->bank, 3, (u16)voiceId);
        MEMBER(s32, packetData, BtlVoicePacketWork, started) = 1;
        goto block_15_9800;
    }
    if (sdkSndIsChannelPlaying(3) != 1) {
        if ((((BtlVoicePacketWork *)packetData)->flags & 1) == 0 && (action != NULL)) {
            finishingUnit = MEMBER(u8 *, action, BtlAction, unit);
            if ((((BtlUnit *)finishingUnit)->flags2 & 2) != 0) {
                ((BtlUnit *)finishingUnit)->unk_9d8 &= 0xFFEF;
                finishingModel = ((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->layerHandle;
                (((Model *)(finishingModel))->motion.flags) |= 0x20;
            }
        }
        return 1;
    }
block_15_9800:
    if ((((BtlVoicePacketWork *)packetData)->flags & 1) == 0 &&
        MEMBER(s32, packetData, BtlVoicePacketWork, started) == 1 && (action != NULL)) {
        speakingUnit = MEMBER(u8 *, action, BtlAction, unit);
        if ((((BtlUnit *)speakingUnit)->flags2 & 2) != 0) {
            ((BtlUnit *)speakingUnit)->unk_9d8 |= 0x10;
            speakingModel = ((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->layerHandle;
            (((Model *)(speakingModel))->motion.flags) &= 0xFFDF;
        }
    }
    return 0;
}

