/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001F99C0)
/* Source unit: src/Battle/btlVoice_001f99c0.c */
#include "type.h"

typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket {
    u8 padding_00[0x6c];
    BtlPacketUpdateFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

typedef struct BtlAction BtlAction;

typedef struct BtlVoicePacket001f99c0 {
    BtlAction* action; // 0x00
    s16 unk_04;        // 0x04
    u8 unkData1[2];
    s32 unk_08;        // 0x08
    s32 unk_0c;        // 0x0c
    s16 unk_10;        // 0x10
    u8 unkData2[2];
    s32 unk_14;        // 0x14
} BtlVoicePacket001f99c0;

BtlPacket* func_00194470(u32 type, s32 workSize);
u32 func_001f9800(void* work);

// FUN_001F99C0
BtlPacket* btlVoiceCreatePacket(BtlAction* action, s32 param_2, s32 param_3,
                                s32 param_4, s32 param_5)
{
    BtlPacket* packet;
    BtlVoicePacket001f99c0* work;

    packet = func_00194470(0xa01, sizeof(BtlVoicePacket001f99c0));
    packet->updateFunc = func_001f9800;
    work = (BtlVoicePacket001f99c0*)packet->workData;
    work->action = action;
    work->unk_04 = param_2;
    work->unk_08 = param_3;
    work->unk_0c = param_4;
    work->unk_10 = param_5;
    work->unk_14 = 0;
    return packet;
}
#endif /* P4_UNIT_001F99C0 */

#if defined(P4_UNIT_001F9B80)
/* Source unit: src/Battle/btlVoice_001f9b80.c */
#include "type.h"

typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 unk_47;
    u8 padding_48[0x24];
    BtlPacketUpdateFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

typedef struct BtlVoicePacketA03Work {
    u32 result;
    u32 state;
    u16 voiceId;
} BtlVoicePacketA03Work;

BtlPacket* func_00194470(u32 type, s32 workSize);
u32 func_001f9ac0(BtlVoicePacketA03Work* work);

// FUN_001F9B80
BtlPacket* func_001f9b80(u16 voiceId)
{
    BtlPacket* packet;
    BtlVoicePacketA03Work* work;

    packet = func_00194470(0xa03, sizeof(BtlVoicePacketA03Work));
    packet->unk_47 &= 0xfe;
    packet->updateFunc = (BtlPacketUpdateFunc)func_001f9ac0;
    work = (BtlVoicePacketA03Work*)packet->workData;
    work->voiceId = voiceId;
    work->result = 0;
    work->state = 0;
    return packet;
}
#endif /* P4_UNIT_001F9B80 */

#if defined(P4_UNIT_00225E00)
/* Source unit: src/Battle/btlVoice_00225e00.c */
#include "type.h"

typedef struct BtlUnit {
    u8 padding_00[0xa2];
    u8 genus;
} BtlUnit;

typedef struct BtlAction {
    u8 padding_00[0x1a];
    u16 unk_1a;
    u8 padding_1c[0x14];
    BtlUnit* unit;
} BtlAction;

typedef struct BtlCamera {
    u8 padding_00[0xe0];
    BtlAction* action;
} BtlCamera;

void func_00225740(BtlCamera* camera);

// FUN_00225E00
void func_00225e00(BtlCamera* camera)
{
    BtlAction* action;

    action = camera->action;
    if (((action != NULL) && ((action->unk_1a & 1) != 0)) &&
        (action->unit->genus != 0)) {
        func_00225740(camera);
    }
    return;
}
#endif /* P4_UNIT_00225E00 */
