/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001F99C0)
/* Source unit: src/Battle/btlVoice_001f99c0.c */
#include "type.h"
#include "include_asm.h"

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
INCLUDE_ASM("asm/nonmatchings", btlVoiceCreatePacket);
#endif /* P4_UNIT_001F99C0 */
