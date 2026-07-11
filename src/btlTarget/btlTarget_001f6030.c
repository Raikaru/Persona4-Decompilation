#include "type.h"

typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket {
    u8 data_00[0x6c];
    BtlPacketUpdateFunc updateFunc;
    u8 data_70[8];
    void* workData;
} BtlPacket;

typedef struct BtlTargetSimpleWork {
    u16 command;
    u16 pad_02;
    u32 param;
} BtlTargetSimpleWork;

BtlPacket* func_00194470(u32 id, s32 workDataSize);
u32 func_001f6000(void* work);

// FUN_001F6030
BtlPacket* func_001f6030(u16 command, u32 param)
{
    BtlPacket* packet = func_00194470(0x801, 8);
    BtlTargetSimpleWork* work;

    packet->updateFunc = func_001f6000;
    work = (BtlTargetSimpleWork*)packet->workData;
    work->command = command;
    work->param = param;
    return packet;
}
