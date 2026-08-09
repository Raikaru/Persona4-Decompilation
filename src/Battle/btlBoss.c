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
extern s32 func_001f0ff0();
extern s32 func_00232710(u8* arg0, u32 arg1);
extern s32 func_0019fc70();
extern u16 func_001d7f10();
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



// FUN_0022FC00
s32 func_0022fc00(u8* arg0)
{
    u8 temp_4;
    u8* temp_3;
    u8* temp_4_2;
    u8* temp_5;

    if ((*(s32*)(DAT_0076449c + 0xc) & 0x200000) == 0)
    {
        return 1;
    }
    if (func_001f0ff0() == 0)
    {
        return 1;
    }
    temp_5 = *(u8**)(arg0 + 0x30);
    temp_3 = *(u8**)(*(u8**)(arg0 + 0x38) + 0x30);
    temp_4 = *(u8*)(temp_5 + 0xa2);
    if (temp_4 == 1)
    {
        return 1;
    }
    if (temp_5 == temp_3)
    {
        return 1;
    }
    if (temp_4 != *(u8*)(temp_3 + 0xa2))
    {
        return 1;
    }
    temp_4_2 = *(u8**)(temp_5 + 0xa64);
    if ((temp_4_2 != NULL) && (func_00232710(temp_4_2, 0x100) != 0))
    {
        return 1;
    }
    return 0;
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





// FUN_0022FD30
s32 func_0022fd30(u8* arg0)
{
    if ((*(s32*)(DAT_0076449c + 0xc) & 0x200000) == 0)
    {
        return 1;
    }
    if ((*(u16*)(arg0 + 0x1a) & 1) == 0)
    {
        return 1;
    }
    if (*(u8*)(*(u8**)(arg0 + 0x30) + 0xa2) != 1)
    {
        return 1;
    }
    return !((u32)func_0019fc70());
}
// FUN_0022FDC0
INCLUDE_ASM("asm/nonmatchings/btlBoss", func_0022fdc0);
// FUN_0022FF70
s32 func_0022ff70(u8 *arg0)
{
    s32 temp_3;
    u16 value;

    if ((*(s32 *)(DAT_0076449c + 0xc) & 0x200000) == 0)
        return 0;
    if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xa2) == 1)
        return 0;
    value = *(u16 *)(arg0 + 0x6e);
    temp_3 = (s32)(func_001d7f10(0, 0, value, 0) & 0xffff);
    if ((temp_3 != 2) && (temp_3 != 1))
        return 0;
    return 1;
}
// FUN_00230020
INCLUDE_ASM("asm/nonmatchings/btlBoss", func_00230020);
// FUN_002300F0
u32 func_002300f0(u8 *arg0, u16 *out1, u16 *out2)
{
    if ((*(u32 *)(DAT_0076449c + 0xc) & 0x200000) == 0)
        return 0;
    if (arg0[0xa2] != 1)
        return 0;
    if (*(u16 *)(arg0 + 0xa4) != 0x111)
        return 0;
    *out1 = arg0[0xa2] + 1;
    *out2 = 0x110;
    return 1;
}
/* measured probe: opt_loop_invariants on for func_00230170 */
#pragma opt_loop_invariants on
// FUN_00230170
void func_00230170(u8 *arg0)
{
    u8 *temp_6;
    u8 *var_6;
    u16 target = 0x10f;

    temp_6 = DAT_0076449c;
    if ((*(s32 *)(temp_6 + 0xc) & 0x200000) &&
        (*(u16 *)(arg0 + 0xa4) == 0x106) &&
        ((*(s32 *)(arg0 + 0x9c) & 8) == 0))
    {
        var_6 = *(u8 **)(temp_6 + 0x180);
        goto loop_cond;
loop_body:
        if (*(u16 *)(var_6 + 0xa4) == target)
            goto loop_done;
        var_6 = *(u8 **)(var_6 + 0xa6c);
loop_cond:
        if (var_6 != NULL)
            goto loop_body;
loop_done:
        if ((var_6 != NULL) && ((*(u16 *)var_6 & 2) != 0))
        {
            *(u16 *)arg0 = *(u16 *)arg0 | 2;
            *(u8 *)(arg0 + 0x37) = *(u8 *)(var_6 + 0x37);
        }
    }
}

#pragma opt_loop_invariants off
// FUN_00230210
INCLUDE_ASM("asm/nonmatchings/btlBoss", func_00230210);
// FUN_00230340
void func_00230340(u8 *arg0)
{
    u8 *temp_5;
    u8 *temp_6;
    u16 temp_4;

    temp_6 = DAT_0076449c;
    if ((*(s32 *)(temp_6 + 0xc) & 0x200000) != 0)
    {
        temp_5 = *(u8 **)(arg0 + 0x30);
        if (*(u8 *)(temp_5 + 0xa2) == 1)
        {
            temp_4 = *(u16 *)(temp_5 + 0xa4);
            switch (temp_4)
            {
            case 0x102:
            case 0x104:
            case 0x105:
            case 0x106:
            case 0x107:
            case 0x10b:
            case 0x112:
                *(s8 *)(temp_6 + 0xc12) = -1;
                break;
            default:
                break;
            }
        }
    }
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
