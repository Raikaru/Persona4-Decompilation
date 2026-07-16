/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0022FCE0)
/* Source unit: src/Battle/btlBoss_0022fce0.c */
#include "type.h"

extern u8* DAT_0076449c;

// FUN_0022FCE0
u32 func_0022fce0(s32 first, s32 second)
{
    u8 value;

    if ((*(u32*)(DAT_0076449c + 0xc) & 0x200000) != 0)
    {
        value = *(u8*)(first + 0xa2);
        if (value == 1 && value == *(u8*)(second + 0xa2))
        {
            return 0;
        }
    }

    return 1;
}
#endif /* P4_UNIT_0022FCE0 */

#if defined(P4_UNIT_002304B0)
/* Source unit: src/Battle/btlBoss_002304b0.c */
#include "type.h"

typedef u32 (*BtlPacketFunc)(void* work);

typedef struct BtlPacket {
    u8 padding_00[0x47];
    u8 flags;
    u8 padding_48[0x20];
    BtlPacketFunc initFunc;
    BtlPacketFunc updateFunc;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
u32 func_002303e0(void* work);
u32 func_00230450(void* work);

// FUN_002304B0
BtlPacket* btlBossCreateLoadPakPacket(void)
{
    BtlPacket* packet;

    packet = func_00194470(0xe00, 0);
    packet->flags &= ~(1 << 0);
    packet->initFunc = func_002303e0;
    packet->updateFunc = func_00230450;

    return packet;
}
#endif /* P4_UNIT_002304B0 */
