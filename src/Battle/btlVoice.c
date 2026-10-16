/* Source unit: src/Battle/btlVoice_001f99c0.c */
#include "type.h"
#include "btl_action_internal.h"

typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 unk_47;
    u8 padding_48[0x24];
    BtlPacketUpdateFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

typedef struct BtlVoicePacket001f99c0 {
    BtlAction* action; // 0x00
    u16 unk_04;        // 0x04: cue index, read unsigned by callback
    u8 unkData1[2];
    s32 unk_08;        // 0x08
    s32 unk_0c;        // 0x0c
    s16 unk_10;        // 0x10
    u8 unkData2[2];
    s32 unk_14;        // 0x14
} BtlVoicePacket001f99c0;

BtlPacket* btlPacketAlloc(u32 type, s32 workSize);
u32 btlVoicePacketUpdate(void* work);

typedef struct BtlVoicePacketA03Work {
    u32 result;
    u32 state;
    u16 voiceId;
} BtlVoicePacketA03Work;
u32 btlVoiceIdPacketUpdate(BtlVoicePacketA03Work* work);

typedef struct BtlCamera {
    u8 padding_00[0xe0];
    BtlAction* action;
} BtlCamera;

void btlCameraFrameUnitPair(BtlCamera* camera);



// FUN_001F99C0
BtlPacket* btlVoiceCreatePacket(BtlAction* action, u16 param_2, s32 param_3,
                                s32 param_4, s32 param_5)
{
    BtlPacket* packet;
    BtlVoicePacket001f99c0* work;

    packet = btlPacketAlloc(0xa01, sizeof(BtlVoicePacket001f99c0));
    packet->updateFunc = btlVoicePacketUpdate;
    work = (BtlVoicePacket001f99c0*)packet->workData;
    work->action = action;
    work->unk_04 = param_2;
    work->unk_08 = param_3;
    work->unk_0c = param_4;
    work->unk_10 = param_5;
    work->unk_14 = 0;
    return packet;
}



// FUN_001F9B80
BtlPacket* btlVoiceCreateIdPacket(u16 voiceId)
{
    BtlPacket* packet;
    BtlVoicePacketA03Work* work;

    packet = btlPacketAlloc(0xa03, sizeof(BtlVoicePacketA03Work));
    packet->unk_47 &= 0xfe;
    packet->updateFunc = (BtlPacketUpdateFunc)btlVoiceIdPacketUpdate;
    work = (BtlVoicePacketA03Work*)packet->workData;
    work->voiceId = voiceId;
    work->result = 0;
    work->state = 0;
    return packet;
}



// FUN_00225E00
void func_00225e00(BtlCamera* camera)
{
    BtlAction* action;

    action = camera->action;
    if (((action != NULL) && ((action->unk_1a & 1) != 0)) &&
        (action->unit->genus != 0)) {
        btlCameraFrameUnitPair(camera);
    }
    return;
}
extern u8 *DAT_0076449c;
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
s32 btlEncounterWaitIdle(s64 *arg0)
{
    u8 *temp_4;

    if (btlUnitRecordFindByActionUID(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

#pragma optimization_level 2

