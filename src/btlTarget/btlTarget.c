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

/* Both halfword pairs are copied independently; intervening state is unknown. */
typedef struct BtlTarget {
    u8 pad00[0x34];
    u16 unk34;
    u16 unk36;
    u8 pad38[0xC];
    u16 unk44;
    u16 unk46;
} BtlTarget;

u32 btlTargetSimpleCommand(BtlTargetSimpleWork* work);


/* Snapshot the two target halfwords into their saved pair. */
// FUN_001EB420
void btlTargetSavePair(u8* target)
{
    ((BtlTarget*)target)->unk44 = ((BtlTarget*)target)->unk34;
    ((BtlTarget*)target)->unk46 = ((BtlTarget*)target)->unk36;
}

/* Allocate packet 0x801 and initialize its eight-byte command work block. */
// FUN_001F6030
BtlPacket* btlTargetCreateSimplePacket(u16 command, u32 param)
{
    BtlPacket* packet = func_00194470(0x801, 8);
    BtlTargetSimpleWork* work;

    packet->updateFunc = (BtlPacketUpdateFunc)btlTargetSimpleCommand;
    work = (BtlTargetSimpleWork*)packet->workData;
    work->command = command;
    work->param = param;
    return packet;
}

