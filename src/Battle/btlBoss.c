/* Source unit: src/Battle/btlBoss_0022fb90.c */
#include "type.h"
#include "include_asm.h"

/* Partial view of BtlUnit: genus lives at 0xa2 (see P3 include/Battle/btlUnit.h). */
typedef struct BtlUnit {
    u8 padding_00[0xa2];
    u8 genus; // 0xa2
} BtlUnit;

/* UNIT_GENUS_EC = 1 (include/Main/Battle/Data/datUnit.h in P3). */
enum { UNIT_GENUS_EC = 1 };

extern u8* DAT_0076449c;

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
s32 func_001ef9a0(void);
void func_0022c430(void);
void func_00440b68();
void func_00442088();
extern u8* func_00454a60(u8* param, s32 mode);
s32 func_004553c0(u8* ptr);
extern char iGpffffa5e8;
extern char D_00635620[];
extern char D_00635638[];
extern char D_00635650[];
extern char D_00635668[];



// FUN_0022FB90
u8 func_0022fb90(BtlUnit* first, BtlUnit* second)
{
    if ((*(u32*)(DAT_0076449c + 0xc) & 0x200000) == 0)
    {
        return 0;
    }
    if (first->genus == UNIT_GENUS_EC)
    {
        return 0;
    }
    if (first == second)
    {
        return 0;
    }
    return first->genus == second->genus;
}



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





// FUN_002303E0
u32 func_002303e0(void* work)
{
    u8 buf[0x80];

    func_00442088(buf, D_00635620, func_001ef9a0());
    func_00440b68(&iGpffffa5e8, D_00635638, 0x997);
    *(u32*)(DAT_0076449c + 0xB90) = (u32)func_00454a60(buf, 1);
}



// FUN_00230450
u32 func_00230450(void* work)
{
    u32 handle;

    handle = *(u32*)(DAT_0076449c + 0xB90);
    if (handle == 0)
    {
        return 1;
    }
    if (func_004553c0((u8*)handle) != 0)
    {
        func_0022c430();
        return 1;
    }
    return 0;
}

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



typedef struct BtlBossEndBgmWork {
    u32 encountId; // 0x00
    u32 loaded;    // 0x04
} BtlBossEndBgmWork;

// FUN_00230500
u32 func_00230500(BtlBossEndBgmWork* work)
{
    u8 buf[0x80];

    if (work->loaded == 0)
    {
        func_00442088(buf, D_00635650, D_00635668, work->encountId);
        func_00440b68(&iGpffffa5e8, D_00635638, 0x9C6);
        *(u32*)(DAT_0076449c + 0xB94) = (u32)func_00454a60(buf, 0);
        work->loaded = 1;
        goto done;
    }
    if (func_004553c0((u8*)*(u32*)(DAT_0076449c + 0xB94)) != 0)
    {
        return 1;
    }
done:
    return 0;
}
