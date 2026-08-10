/* Source unit: src/Battle/battle_00192560.c */
#include "include_asm.h"
#include "type.h"

static u64 iGpffffa090 = 1;

extern void* MT_Scene_GetRes(u16 resTypeId);

static u16 iGpffffa098 = 0x100;

extern void func_001949d0(u32 layer);
extern void func_001b6ab0(void);
extern void func_001b5fe0(void);
extern void func_001b0a60(void);
extern void func_001b15b0(void);
extern void func_001b6a20(void);
extern void func_001bd7d0(void);
extern void func_0019c0d0(void);
extern void func_001f6190(void);
extern void func_001f9be0(void);
extern void func_001f72e0(void);
extern void func_001eb8d0(void);
extern void func_00192ae0(void);
extern s32 func_00457120(void);
extern s32 func_003e8120(s32 arg0);
extern void func_0019cfb0(void);
extern void func_0019d150(void);
extern void func_001d6680(void);
extern void func_001bd9e0(void);
extern void func_00460ac0(void *arg0, void *arg1);
extern void func_003e8110(s32 arg0);
extern u8 D_007940C0[];
extern u8 D_00794120[];

extern s32 func_0029d020(void);
extern u32 func_001fc270(void);

typedef struct Battle Battle;
struct Battle
{
    u8 _pad00[0xc];
    u32 flags;
};

typedef struct BtlBattleFlagPacket BtlBattleFlagPacket;
struct BtlBattleFlagPacket
{
    u32 flags;
};
extern Battle* iGpffffb3ac;

typedef struct BtlPacket BtlPacket;
struct BtlPacket
{
    u8 _pad00[0x6c];
    u32 (*updateFunc)(void* work);
    u8 _pad70[8];
    void* workData;
};

extern BtlPacket* func_00194470(u32 type, u32 workSize);
extern u32 func_00193750(void* work);
extern u32 func_001937c0(void* work);



// FUN_00192560
u64 btlGetUID(void)
{
    iGpffffa090++;

    if (iGpffffa090 >= 0x3FFFFFFFFFFFFFFF)
    {
        iGpffffa090 = 1;
    }

    return iGpffffa090;
}



// FUN_001925B0
u16 btlFindFreeCharResId(void)
{
    do
    {
        if (++iGpffffa098 >= 0x200)
        {
            iGpffffa098 = 0x100;
        }
    } while (MT_Scene_GetRes((iGpffffa098 & 0x3ff) | 0x400) != NULL);

    return iGpffffa098;
}



// FUN_00192610
u32 func_00192610(void)
{
    if (iGpffffb3ac->flags & 1) {
        func_001949d0(0);
        func_001b5fe0();
        func_001b0a60();
        func_001b15b0();
        func_001b6a20();
        func_001bd7d0();
        func_0019c0d0();
        func_001f6190();
        func_001f9be0();
        func_001f72e0();
        func_001949d0(1);
        func_001eb8d0();
    } else {
        func_00192ae0();
    }
    return 0;
}
// FUN_001926C0
u32 func_001926c0(void)
{
    if (func_003e8120(func_00457120()) != 0) {
        func_001949d0(2);
        func_0019cfb0();
        func_0019d150();
        func_001d6680();
        func_001bd9e0();
        *(s32 *)((u8 *)iGpffffb3ac + 0xE18) = 0;
        *(s32 *)((u8 *)iGpffffb3ac + 0xE1C) = 0;
        func_00460ac0(D_007940C0, (u8 *)iGpffffb3ac + 0xE18);
        *(s32 *)((u8 *)iGpffffb3ac + 0xE48) = 0;
        *(s32 *)((u8 *)iGpffffb3ac + 0xE4C) = 0;
        func_00460ac0(D_00794120, (u8 *)iGpffffb3ac + 0xE48);
        func_003e8110(func_00457120());
    }
    return 0;
}
// FUN_00192790
void* btlUpdateDraw3DFrontTask(void* task)
{
    func_001949d0(3);
    func_001b6ab0();

    return 0;
}



// FUN_001935F0
u32 func_001935f0(void)
{
    if (func_0029d020() > 0)
    {
        return func_001fc270() != 0;
    }

    return 0;
}



// FUN_00193750
u32 func_00193750(void* work)
{
    BtlBattleFlagPacket* packet;

    packet = (BtlBattleFlagPacket*)work;
    iGpffffb3ac->flags |= packet->flags;

    return 1;
}



// FUN_00193770
BtlPacket* btlCreateSetFlagsPacket(u32 flags)
{
    BtlPacket* packet;

    packet = func_00194470(0xFF02, sizeof(BtlBattleFlagPacket));
    packet->updateFunc = func_00193750;
    ((BtlBattleFlagPacket*)packet->workData)->flags = flags;

    return packet;
}


/* measured: removing this pragma takes func_001937c0 nd 0 -> nd 13. */
#pragma optimization_level 1

// FUN_001937C0
u32 func_001937c0(void* work)
{
    BtlBattleFlagPacket* packet;
    Battle* btl;

    btl = iGpffffb3ac;
    packet = (BtlBattleFlagPacket*)work;
    btl->flags &= ~packet->flags;

    return 1;
}
#pragma optimization_level 2



// FUN_001937F0
BtlPacket* btlCreateRemoveFlagsPacket(u32 flags)
{
    BtlPacket* packet;

    packet = func_00194470(0xFF03, sizeof(BtlBattleFlagPacket));
    packet->updateFunc = func_001937c0;
    ((BtlBattleFlagPacket*)packet->workData)->flags = flags;

    return packet;
}
