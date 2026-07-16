/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001F99C0)
/* Source unit: src/Battle/btlVoice_001f99c0.c */
#include "type.h"

typedef struct BtlAction BtlAction;
typedef u32 (*BtlPacketFunc)(void* work);

typedef struct BtlPacket {
    u8 padding_00[0x6c];
    BtlPacketFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

typedef struct BtlVoiceWork {
    BtlAction* action;
    s16 unk_04;
    u8 padding_06[2];
    s32 unk_08;
    s32 unk_0c;
    s16 unk_10;
    u8 padding_12[2];
    s32 unk_14;
} BtlVoiceWork;

BtlPacket* func_00194470(u32 type, u32 workSize);
u32 func_001f9800(void* work);

// FUN_001F99C0
BtlPacket* btlVoiceCreatePacket(BtlAction* action, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    BtlPacket* packet;
    BtlVoiceWork* work;

    packet = func_00194470(0xa01, sizeof(BtlVoiceWork));
    packet->updateFunc = func_001f9800;

    work = (BtlVoiceWork*)packet->workData;
    work->action = action;
    work->unk_04 = arg2;
    work->unk_08 = arg3;
    work->unk_0c = arg4;
    work->unk_10 = arg5;
    work->unk_14 = 0;

    return packet;
}
#endif /* P4_UNIT_001F99C0 */
