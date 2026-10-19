/* Source unit: src/Battle/btlVoice_001f99c0.c */
#include "type.h"
#include "btl_voice_internal.h"
#include "btl_effect_internal.h"

BtlPacket* btlPacketAlloc(s32 type, s32 workSize);
s32 btlVoicePacketUpdate(void* work);
s32 btlVoiceIdPacketUpdate(BtlVoiceIdWork* work);
void btlCameraFrameUnitPair(BtlCamera* camera);



/* Allocate an action-voice request; flags bit 0 leaves model talk state alone. */
// FUN_001F99C0
BtlPacket* btlVoiceCreatePacket(BtlAction* action, u16 callbackIndex, s32 argument,
                                s32 extraArgument, s32 flags)
{
    BtlPacket* packet;
    BtlVoicePacketWork* work;

    packet = btlPacketAlloc(0xa01, sizeof(BtlVoicePacketWork));
    packet->updateFunc = (BtlPacketFunc)btlVoicePacketUpdate;
    work = (BtlVoicePacketWork*)packet->workData;
    work->action = action;
    work->callbackIndex = callbackIndex;
    work->argument = argument;
    work->extraArgument = extraArgument;
    work->flags = flags;
    work->started = 0;
    return packet;
}



/* Queue an ID-selected voice without the packet's default flag bit 0. */
// FUN_001F9B80
BtlPacket* btlVoiceCreateIdPacket(u16 voiceId)
{
    BtlPacket* packet;
    BtlVoiceIdWork* work;

    packet = btlPacketAlloc(0xa03, sizeof(BtlVoiceIdWork));
    packet->flags &= 0xfe;
    packet->updateFunc = (BtlPacketFunc)btlVoiceIdPacketUpdate;
    work = (BtlVoiceIdWork*)packet->workData;
    work->voiceId = voiceId;
    work->result = 0;
    work->state = 0;
    return packet;
}



/* Only nonparty, valid actions request actor/target-pair camera framing. */
// FUN_00225E00
void btlCameraFrameNonpartyActionPair(BtlCamera* camera)
{
    BtlAction* action;

    action = camera->action;
    if (((action != NULL) && ((action->unk_1a & 1) != 0)) &&
        (action->unit->genus != 0)) {
        btlCameraFrameUnitPair(camera);
    }
    return;
}
extern u8 *DAT_0076449c; /* active battle context */
extern u8 *btlUnitRecordFindByActionUID(u64 uid, u64 mask);
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma pop
/* 896/896 bytes and all 17 relocations resolve exactly.
 * Keep the opaque byte branch-local, snapshot coordinates before opacity
 * conversion, and pack the color before preparing the overlay dimensions. */
#pragma push
#pragma opt_propagation off
#pragma pop
/* 1036/1040 bytes; 26 code relocations and all nine switch entries exact. */
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_propagation off
#pragma pop
/* 1688/1696 bytes; all 36 resolved code relocations exact. */
#pragma opt_scalarize off
#pragma opt_scalarize on
/* Measured: 800/800 bytes, 20 resolved relocations, zero differences.
 * Disabling common-subexpression folding preserves the wrapping target walk. */
#pragma opt_common_subs off
#pragma opt_common_subs on
/* measured 00225d00 plain-C reconstruction matches the complete 256-byte retail window at normalized_diff 0. */
#pragma optimization_level 1
#pragma optimization_level 2
#pragma opt_scalarize off
#pragma opt_scalarize on
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma opt_scalarize off
#pragma opt_scalarize on
#pragma opt_propagation off
#pragma opt_propagation on
// Intent: Wait until the presentation is idle, then clear its flag. [inferred]
// FUN_0022B040
s32 btlEncounterWaitIdle(s64 *actionUid)
{
    u8 *battle;

    if (btlUnitRecordFindByActionUID(*actionUid,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        battle = DAT_0076449c;
        ((BtlBattleState *)battle)->flags &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

#pragma optimization_level 2

