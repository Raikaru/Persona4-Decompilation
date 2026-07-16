/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_001B5E60)
/* Source unit: src/Battle/btlMain_001b5e60.c */
#include "type.h"

typedef struct BtlMain BtlMain;
struct BtlMain
{
    u8 _pad00[0xc];
    u32 flags;
};

extern u32 D_00764580;
extern u32 func_00193c70(void);
extern u32 func_001f6290(void);
extern void func_001f75b0(void);

// FUN_001B5E60
u32 func_001b5e60(void* work)
{
    BtlMain* btl;

    if (func_00193c70() == 0 && func_001f6290() == 0)
    {
        func_001f75b0();
        btl = *(BtlMain**)((u8*)&D_00764580 - 0xe4);
        btl->flags &= ~1;
    }

    return 0;
}
#endif /* P4_UNIT_001B5E60 */

#if defined(P4_UNIT_001B7E20)
/* Source unit: src/Battle/btlMain_001b7e20.c */
#include "type.h"

typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x6c];
    BtlPacketFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
u32 func_001b7b30(void* work);

// FUN_001B7E20
void func_001b7e20(u32 value)
{
    BtlPacket* packet;

    packet = func_00194470(0x601, 0x28);
    packet->updateFunc = func_001b7b30;
    *(u32*)((u8*)packet->workData + 0x20) = value;
}
#endif /* P4_UNIT_001B7E20 */

#if defined(P4_UNIT_001B9360)
/* Source unit: src/Battle/btlMain_001b9360.c */
#include "type.h"

typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x6c];
    BtlPacketFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
u32 func_001b87e0(void* work);

// FUN_001B9360
void func_001b9360(s32 arg, s16 mode)
{
    BtlPacket* packet;
    u8* work;

    packet = func_00194470(0x603, 0x5c);
    packet->updateFunc = func_001b87e0;
    work = (u8*)packet->workData;
    *(s32*)(work + 0x50) = arg;
    *(s16*)(work + 0x58) = mode;
}
#endif /* P4_UNIT_001B9360 */

#if defined(P4_UNIT_001B99A0)
/* Source unit: src/Battle/btlMain_001b99a0.c */
#include "type.h"

typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x6c];
    BtlPacketFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
u32 func_001b96e0(void* work);

// FUN_001B99A0
void func_001b99a0(s32 arg)
{
    BtlPacket* packet;

    packet = func_00194470(0x605, 0x18);
    packet->updateFunc = func_001b96e0;
    *(s32*)((u8*)packet->workData + 0x10) = arg;
}
#endif /* P4_UNIT_001B99A0 */

#if defined(P4_UNIT_001B9DE0)
/* Source unit: src/Battle/btlMain_001b9de0.c */
#include "type.h"

typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x6c];
    BtlPacketFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
u32 func_001b99f0(void* work);

// FUN_001B9DE0
void func_001b9de0(s32 arg1, s16 arg2, s32 arg3)
{
    BtlPacket* packet;
    u8* work;

    packet = func_00194470(0x606, 0x10);
    packet->updateFunc = func_001b99f0;
    work = (u8*)packet->workData;
    *(s32*)(work + 0) = arg1;
    *(s32*)(work + 4) = arg3;
    *(s16*)(work + 0xc) = arg2;
    *(s32*)(work + 8) = 0;
}
#endif /* P4_UNIT_001B9DE0 */

#if defined(P4_UNIT_001BA090)
/* Source unit: src/Battle/btlMain_001ba090.c */
#include "type.h"

typedef u32 (*BtlPacketFunc)(void* work);
typedef struct BtlPacket {
    u8 padding_00[0x6c];
    BtlPacketFunc updateFunc;
    u8 padding_70[8];
    void* workData;
} BtlPacket;

BtlPacket* func_00194470(u32 type, u32 workSize);
u32 func_001b9e50(void* work);

// FUN_001BA090
void func_001ba090(s32 arg)
{
    BtlPacket* packet;

    packet = func_00194470(0x607, 8);
    packet->updateFunc = func_001b9e50;
    *(s32*)packet->workData = arg;
}
#endif /* P4_UNIT_001BA090 */

#if defined(P4_UNIT_001BBEF0)
/* Source unit: src/Battle/btlMain_001bbef0.c */
#include "type.h"

// FUN_001BBEF0
void func_001bbef0(u8* work, f32 value)
{
    *(f32*)(work + 0x84) = (value * 2.0f * 60.0f) / 2.0f;
    *(u32*)(work + 0x94) = 0x3f000000;
    *(u16*)work = *(u16*)work & 0xfff5;
    *(u16*)work = *(u16*)work | 4;
}
#endif /* P4_UNIT_001BBEF0 */
