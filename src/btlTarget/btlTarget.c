/* Source unit: src/btlTarget/btlTarget_001eb420.c (1 function markers) */
#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"

typedef u32 (*BtlPacketUpdateFunc)(void* work);

typedef struct BtlPacket
{
    u8 data_00[0x6c];
    BtlPacketUpdateFunc updateFunc;
    u8 data_70[8];
    void* workData;
} BtlPacket;

extern BtlPacket* func_00194470(u32 id, s32 workDataSize);

typedef struct BtlTargetSimpleWork
{
    u16 command;
    u16 pad_02;
    u32 param;
} BtlTargetSimpleWork;

u32 func_001f6000(BtlTargetSimpleWork* work);



// FUN_001EB420
void func_001eb420(u8* target)
{
    *(u16*)(target + 0x44) = *(u16*)(target + 0x34);
    *(u16*)(target + 0x46) = *(u16*)(target + 0x36);
}

// FUN_001F6030
BtlPacket* func_001f6030(u16 command, u32 param)
{
    BtlPacket* packet = func_00194470(0x801, 8);
    BtlTargetSimpleWork* work;

    packet->updateFunc = (BtlPacketUpdateFunc)func_001f6000;
    work = (BtlTargetSimpleWork*)packet->workData;
    work->command = command;
    work->param = param;
    return packet;
}

