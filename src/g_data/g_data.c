#include "include_asm.h"
#include "type.h"
extern u8 D_007973A0[];

extern s16 D_00797F88[];

extern u32 D_0079B68C[];

typedef struct DatGlobal {
    u8 padding[0x3c6c];
    u32 flags[1];
    u8 padding2[0x4c0];
    s16 partyIds[1];
} DatGlobal;

extern DatGlobal D_00797560;

extern s16 D_00797B7A[];

extern u8 D_00797B7C[];

extern s32 D_00797B80[];

extern u16 D_0079B6A4[];

extern u8 D_0079B6A8[];

extern u8 D_0079757A[];

extern u32 D_005E2200[];

extern u8 D_0079BF00[];

typedef struct GDataEntry {
    u32 f00;
    u32 f04;
    u16 f08;
    u16 f0A;
    u8 f0C;
    u8 f0D;
    u8 f0E;
    u8 f0F;
    u16 f10;
    u16 f12;
    u8 f14[0x10];
    u32 f24;
    u16 f28;
    u16 f2A;
    u16 f2C;
    u16 f2E;
    u32 f30;
    u32 f34;
    s8 f38;
    s8 f39;
    u8 f3A;
    u8 f3B;
    u32 f3C;
    u32 f40;
} GDataEntry;

extern GDataEntry* D_007242A0;

extern u8 D_007981CC[];

extern u8 D_0079BE2C[];

extern void func_00232a40(void);

extern void func_0010b610(s32 arg0);

extern void func_00193ad0(void* arg0);

extern s16 D_007973F4[];

extern u32 D_0079BCD8[];

extern u32 D_005E4480[];

extern s32 D_005DD6E0[];

extern s32 D_005DD6DC[];

extern s16 func_00104f50(s16 arg0, s16 arg1);

extern s32 func_00246a50(s16 arg0, s16 arg1);

extern void func_0044ea90(void* msg, s32 id);

extern u8 D_005E4298[];

extern u8 D_005E42B0[];

extern void* (*jtbl_008873E8[])(u32 size, u32 align);

extern u32 D_00764298;

extern u16 func_00107890(u8 arg0);

extern void func_0043f810(void* arg0, void* arg1, u32 arg2);

extern u8 func_00231e20(void* arg0);
extern u32 func_00231ed0(void* arg0);
extern u32 func_00231ee0(void* arg0);
extern u32 func_00231f80(void* arg0);
extern u32 func_00232290(void* arg0);
extern void func_002326c0(void* arg0);
extern void func_00231dc0(void* arg0, s16 arg1);
extern void func_00232680(void* arg0);
extern void func_002326f0(void* arg0);
extern void func_002428f0(void* arg0, s32 arg1);

extern u8 D_007973C4[];
extern u8 D_00796E50[];
extern u8 D_00796D4C[];
extern u8 D_00796D4E[];
extern u8 D_00796D84[];
extern u8 D_00796D8C[];
extern u8 D_00796D74[];
extern u8 D_00796D54[];
extern s16 D_00797574[];
extern u8 D_007973CA[];
extern u16 D_007973CC[];
extern u16 D_007973CE[];
extern u32 D_00797400[];
extern u16 D_00797404[];
extern s8 D_007973D4[];
extern u32 D_0079B48C[];
extern u8* DAT_007644A8;

extern u32 D_005E4540[];

extern u32 D_005E4570[];

extern u8 D_00796D96[];

extern u8 D_005DD844[];

extern u8 D_005DD846[];

extern u8 D_00797410[];

extern u8 D_00797F8E[];

extern u8* DAT_007644D0;

extern void func_0023dd90(void* arg0, u8* arg1);

extern void func_0023d9b0(void* arg0, u8* arg1);

extern s16 D_00797B84[];

extern u8 D_00797B86[];

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

extern char D_005e4308[];
extern long func_00452380(void* path);
extern void func_00452080(long handle);

extern void FUN_0046d730(const char* file, s32 line);

#define K_ASSERT(condition, line) do { if (!(condition)) { FUN_0046d730(__FILE__, (line)); } } while (0)

extern u8* DAT_00764530;

extern u8* DAT_007644c4;

typedef struct PersonaWork {
    u16 flags;
    u16 id;
    u8 level;
    u8 pad[3];
    u32 nextExp;
    u16 skills[8];
    u8 naturalStats[5];
    u8 bonusStats[5];
} PersonaWork;

extern PersonaWork* func_0010a900(u16 pcId);

extern u32 func_0010c750(PersonaWork* persona, u16 level);

extern u32 datPersonaGetNextExp(int persona);

extern void FUN_0043f9c8(void* destination, s32 value, u32 size);
extern void func_0010d560(void);
extern u8 DAT_007973a0[0x24];

// FUN_00104900
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104900);

// FUN_00104A00
void func_00104a00(s32 arg0)
{
    K_ASSERT(arg0 != 0, 0xC2);
    DAT_008873ec_abs[0](arg0);
}

// FUN_00104A60
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104a60);

// FUN_00104C50
void func_00104c50(void)
{
    D_007242A0 = (GDataEntry*)((u32)&D_0079BF00[0] + 0x10);
}

// FUN_00104C70
void func_00104c70(s16 arg0)
{
    if (arg0 == 1)
    {
        func_00231e20(D_007973C4);
    }
    else
    {
        func_00231e20((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00104CE0
void func_00104ce0(s16 arg0)
{
    if (arg0 == 1)
    {
        func_00231ed0(D_007973C4);
    }
    else
    {
        func_00231ed0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00104D50
void func_00104d50(s16 arg0)
{
    if (arg0 == 1)
    {
        func_00231ee0(D_007973C4);
    }
    else
    {
        func_00231ee0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00104DC0
void func_00104dc0(s16 arg0)
{
    if (arg0 == 1)
    {
        func_00231f80(D_007973C4);
    }
    else
    {
        func_00231f80((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00104E30
void func_00104e30(s16 arg0)
{
    if (arg0 == 1)
    {
        func_00232290(D_007973C4);
    }
    else
    {
        func_00232290((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00104EA0
s16 func_00104ea0(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        return D_007973F4[arg1];
    }
    else
    {
        return *(s16*)((u8*)D_00796D74 + (s32)arg0 * 0x88 + (s32)arg1 * 2);
    }
}

// FUN_00104F10
void func_00104f10(s16 arg0)
{
    func_00104f50(arg0, D_007973F4[arg0]);
}

// FUN_00104F50
s16 func_00104f50(s16 arg0, s16 arg1)
{
    s32 sum = 0;
    s32 i = 0;
    s32 limit = arg1;

    while (i < 5)
    {
        sum = (s16)(sum + func_00246a50(arg0, (s16)(i + 1)));
        if (sum > limit)
        {
            break;
        }
        i++;
    }
    if (i >= 5)
    {
        return 5;
    }
    else
    {
        return (s16)(i + 1);
    }
}

/* measured: retail colors the call-result local v5 into $a1 (the just-clobbered
   arg2 slot) and emits the tail as [a-chain][b-chain][addu]; mwcc b210 always
   colors v5 into $a0, reuses the slt's v17 extension for the subu, and
   schedules the float division chain before the (i+1) chain. Tried: v17<v5 /
   v5>v17 comparison forms, all local declaration orders, named s32 locals for
   the tail subexpressions, explicit (s16)/(s32) casts, if/else-break
   restructure, named arg temp, x-copy of v17 — all give the identical nd 31.
   Register-coloring + scheduling floor. */
// FUN_00105010
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105010);

// FUN_001051A0
void func_001051a0(s16 arg0, s16 arg1, s16 arg2)
{
    if (arg0 == 1)
    {
        D_007973F4[arg1] = arg2;
    }
    else
    {
        *(s16*)((u8*)D_00796D74 + (s32)arg0 * 0x88 + (s32)arg1 * 2) = arg2;
    }
}

// FUN_00105210
u32 func_00105210(s16 arg0)
{
    if (arg0 == 1)
    {
        return D_00797400[0];
    }
    else
    {
        PersonaWork* persona = func_0010a900(arg0);

        K_ASSERT(persona != 0, 0x1B8);
        return datPersonaGetNextExp((int)persona);
    }
}

// FUN_00105290
u16 func_00105290(s16 arg0)
{
    if (arg0 == 1)
    {
        s32 v = D_00797F88[0];

        K_ASSERT(v < 0xC, 0x1C3);
        return *(u16*)((u8*)D_00797F8E + v * 0x30);
    }
    else
    {
        return *(u16*)((u8*)D_00796D96 + (s32)arg0 * 0x88);
    }
}

/* Ported from the P3FES donor func_00177410, which carries opt_loop_invariants on
 * around this function to hoist the gGlobalWork base out of both copy loops.
 * Removing this loses func_0010d490 (MATCH nd0 -> MISMATCH nd59, size 200 -> 200)
 * - measured W161 (donor's own P3 measurement: nd89). */

#pragma opt_loop_invariants on
extern u32 memcpy();
extern u32 sprintf();
extern u8 DAT_00796de0[];
extern u8 DAT_00796e00[];
extern u8 DAT_00796e20[];
extern u8 DAT_007973a0[];
extern u8 DAT_007973b2[];
extern u32 DAT_00762ca0;



// FUN_00105330
s16 func_00105330(void)
{
    return D_00797F88[0];
}



// FUN_00105340
void func_00105340(s16 arg0)
{
    if (arg0 == 1)
    {
        func_002326c0(D_007973C4);
    }
    else
    {
        func_002326c0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_001053B0
u16 func_001053b0(s16 arg0)
{
    u8 r;

    if (arg0 == 1)
    {
        r = func_00231e20(D_007973C4);
    }
    else
    {
        r = func_00231e20((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    return *(u16*)((u8*)D_005DD844 + r * 0x2C + (s32)arg0 * 4);
}

// FUN_00105460
u16 func_00105460(s16 arg0)
{
    u8 r;

    if (arg0 == 1)
    {
        r = func_00231e20(D_007973C4);
    }
    else
    {
        r = func_00231e20((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    return *(u16*)((u8*)D_005DD846 + r * 0x2C + (s32)arg0 * 4);
}

// FUN_00105510
u8* func_00105510(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u8*)D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        return (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
}

// FUN_001055A0
void func_001055a0(s16 arg0)
{
    if (arg0 == 1)
    {
        func_00231dc0(D_007973C4, arg0);
    }
    else
    {
        func_00231dc0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4, arg0);
    }
}
// FUN_00105610
void func_00105610(s16 arg0)
{
    if (arg0 == 1)
    {
        func_002428f0(D_007973C4, 0);
    }
    else
    {
        func_002428f0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4, 0);
    }
}

// FUN_00105690
void func_00105690(s16 arg0, u8 arg1)
{
    if (arg0 == 1)
    {
        D_007973CA[0] = arg1;
    }
    else
    {
        K_ASSERT(0, 0x260);
    }
}

// FUN_001056E0
void func_001056e0(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        D_007973CC[0] = arg1;
    }
    else
    {
        *(s16*)((u8*)D_00796D4C + (s32)arg0 * 0x88) = arg1;
    }
}

// FUN_00105730
void func_00105730(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        D_007973CE[0] = arg1;
    }
    else
    {
        *(s16*)((u8*)D_00796D4E + (s32)arg0 * 0x88) = arg1;
    }
}

// FUN_00105780
void func_00105780(s16 arg0)
{
    u32 r;
    u16 v1;
    u16 v2;

    if (arg0 == 1)
    {
        r = func_00231ed0(D_007973C4);
    }
    else
    {
        r = func_00231ed0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    v1 = (u16)r;
    if (arg0 == 1)
    {
        r = func_00231f80(D_007973C4);
    }
    else
    {
        r = func_00231f80((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    v2 = (u16)r;
    if (v2 < v1)
    {
        s16 t = (s16)v2;
        if (arg0 == 1)
        {
            D_007973CC[0] = t;
        }
        else
        {
            *(s16*)((u8*)D_00796D4C + (s32)arg0 * 0x88) = t;
        }
    }
    if (arg0 == 1)
    {
        r = func_00231ee0(D_007973C4);
    }
    else
    {
        r = func_00231ee0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    v1 = (u16)r;
    if (arg0 == 1)
    {
        r = func_00232290(D_007973C4);
    }
    else
    {
        r = func_00232290((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
    v2 = (u16)r;
    if (v2 < v1)
    {
        s16 t = (s16)v2;
        if (arg0 == 1)
        {
            D_007973CE[0] = t;
        }
        else
        {
            *(s16*)((u8*)D_00796D4E + (s32)arg0 * 0x88) = t;
        }
    }
}

// FUN_00105990
void func_00105990(s16 arg0, u32 arg1)
{
    if (arg0 == 1)
    {
        D_00797400[0] = arg1;
    }
    else
    {
        K_ASSERT(0, 0x297);
    }
}

// FUN_00105A50
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105a50);

// FUN_00105C90
void func_00105c90(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        D_00797404[0] = arg1;
    }
    else
    {
        *(s16*)((u8*)D_00796D84 + (s32)arg0 * 0x88) = arg1;
    }
}

// FUN_00105CE0
void func_00105ce0(s16 arg0)
{
    if (arg0 == 1)
    {
        func_00232680(D_007973C4);
    }
    else
    {
        func_00232680((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00105D50
void func_00105d50(s16 arg0)
{
    if (arg0 == 1)
    {
        func_002326f0(D_007973C4);
    }
    else
    {
        func_002326f0((u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4);
    }
}

// FUN_00105DC0
void func_00105dc0(s16 arg0, s16 arg1, s16 arg2)
{
    if (arg0 == 1)
    {
        D_00797574[arg1] = arg2;
    }
    else
    {
        *(s16*)((u8*)D_00796D8C + (s32)arg0 * 0x88 + (s32)arg1 * 2) = arg2;
    }
}

// FUN_00105E30
void func_00105e30(s16 arg0, s16 arg1)
{
    K_ASSERT(arg1 < 5, 0x322);
    if (arg0 == 1)
    {
        D_007973D4[0] = arg1;
    }
    else
    {
        *(s8*)((u8*)D_00796D54 + (s32)arg0 * 0x88) = arg1;
    }
}

// FUN_00105ED0
u32 func_00105ed0(void)
{
    return D_0079B68C[0];
}



// FUN_00105EE0
s16 datGetPartyId(s32 idx)
{
    return D_00797560.partyIds[idx];
}



// FUN_00105F00
s8 func_00105f00(s16 arg0)
{
    if (arg0 == 1)
    {
        return D_007973D4[0];
    }
    else
    {
        return *(s8*)((u8*)D_00796D54 + (s32)arg0 * 0x88);
    }
}

// FUN_00105F50
s8 func_00105f50(u16 arg0)
{
    u8* table = DAT_007644c4;
    u16 id = arg0;

    return (s8)func_00107890(table[id * 0xE + 2]);
}

// FUN_00105FA0
void func_00105fa0(u32 arg0)
{
    if (arg0 > 0x98967F)
    {
        FUN_0046d730(__FILE__, 0x359);
    }
    D_0079B68C[0] = arg0;
}

// FUN_00106000
void datSetPartyId(s32 idx, s16 pcId)
{
    D_00797560.partyIds[idx] = pcId;
}



// FUN_00106020
s32 func_00106020(s32 arg0)
{
    s32 value = arg0 + D_0079B68C[0];

    if (value > 0x98967F)
    {
        value = 0x98967F;
    }
    else if (value < 0)
    {
        value = 0;
    }

    if ((u32)value > 0x98967Fu)
    {
        FUN_0046d730(__FILE__, 0x359);
    }
    D_0079B68C[0] = value;
    return value;
}
// FUN_001060B0
s16 func_001060b0(void)
{
    return D_00797B7A[0];
}



// FUN_001060C0
u8 func_001060c0(void)
{
    return D_00797B7C[0];
}



// FUN_001060D0
s16 func_001060d0(void)
{
    return D_00797B84[0];
}



// FUN_001060E0
u8 func_001060e0(void)
{
    return D_00797B86[0];
}



// FUN_001060F0
s32 func_001060f0(void)
{
    return D_00797B80[0];
}

// FUN_00106100
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106100);

// FUN_001062F0
void func_001062f0(u8 arg0)
{
    D_00797B7C[0] = arg0;
}

// FUN_00106300
void func_00106300(s16 arg0)
{
    D_00797B84[0] = arg0;
}

// FUN_00106310
void func_00106310(u8 arg0)
{
    D_00797B86[0] = arg0;
}

// FUN_00106320
void func_00106320(u32 arg0)
{
    D_00797B80[0] = arg0;
}

// FUN_00106330
u32 datGetFlag(s32 bit)
{
    s32 mask;
    s32 idx;

    idx = bit / 32;
    mask = bit % 32;

    return (D_00797560.flags[idx] & (1 << mask)) != 0;
}



// FUN_00106390
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106390);

// FUN_00106480
void func_00106480(void)
{
    s32 i = 0;

    while (i < 0xB0)
    {
        *(u32*)((u8*)DAT_007973a0 + i * 4 + 0x3E2C) = 0;
        i = i + 1;
    }
}

// FUN_001064C0
void func_001064c0(void)
{
    func_0010b610(0);
}

// FUN_001064F0
u32 func_001064f0(s32 arg0)
{
    K_ASSERT(arg0 < 0x80, 0x4AE);
    return D_0079B48C[arg0];
}

// FUN_00106550
void func_00106550(s32 arg0, u32 arg1)
{
    K_ASSERT(arg0 < 0x80, 0x4B9);
    D_0079B48C[arg0] = arg1;
}

// FUN_001065C0
void func_001065c0(void)
{
    s32 i = 0;

    while (i < 0x7F)
    {
        *(u32*)((u8*)DAT_007973a0 + i * 4 + 0x40EC) = 0;
        i = i + 1;
    }
}

// FUN_00106600
u8 func_00106600(s16 arg0)
{
    return D_0079757A[arg0];
}

// FUN_00106620
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106620);

// FUN_001067F0
u32 func_001067f0(s16 arg0)
{
    return D_005E2200[arg0];
}

// FUN_00106820
GDataEntry* func_00106820(s16 arg0)
{
    return (GDataEntry*)((u8*)D_007242A0 + (s32)arg0 * 68);
}

// FUN_00106850
u32 func_00106850(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68);
}

// FUN_00106880
u32 func_00106880(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 4);
}

// FUN_001068B0
u16 func_001068b0(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 8);
}

// FUN_001068E0
u16 func_001068e0(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0xA);
}

// FUN_00106910
u8 func_00106910(s16 arg0)
{
    return *(u8*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0xE);
}

// FUN_00106940
u16 func_00106940(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x10);
}

// FUN_00106970
u16 func_00106970(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x12);
}

// FUN_001069A0
u32 func_001069a0(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x24);
}

// FUN_001069D0
u16 func_001069d0(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x28);
}

// FUN_00106A00
u16 func_00106a00(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x2A);
}

// FUN_00106A30
u16 func_00106a30(s16 arg0)
{
    return *(u16*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x2C);
}

// FUN_00106A60
u32 func_00106a60(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x30);
}

// FUN_00106A90
u32 func_00106a90(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x34);
}

// FUN_00106AC0
s8 func_00106ac0(s16 arg0)
{
    return *(s8*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x38);
}

// FUN_00106AF0
s8 func_00106af0(s16 arg0)
{
    return *(s8*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x39);
}

// FUN_00106B20
u32 func_00106b20(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x3C);
}

// FUN_00106B50
u32 func_00106b50(s16 arg0)
{
    return *(u32*)((u8*)D_007242A0 + (s32)arg0 * 68 + 0x40);
}

// FUN_00106B80
s64 func_00106b80(s64 arg0)
{
    s16 temp_2;

    temp_2 = (s16)arg0;
    if (temp_2 < 0x100) {
        return temp_2;
    }
    if (temp_2 < 0x200) {
        return (s16)(temp_2 - 0x100);
    }
    if (temp_2 < 0x300) {
        return (s16)(temp_2 - 0x200);
    }
    if (temp_2 < 0x400) {
        return (s16)(temp_2 - 0x300);
    }
    if (temp_2 < 0x500) {
        return (s16)(temp_2 - 0x400);
    }
    return (s16)(temp_2 - 0x500);
}


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_00106C30
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106c30);

// FUN_00106C80
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106c80);

// FUN_00106CD0
s16 func_00106cd0(s16 arg0, s16 arg1)
{
    if (arg0 == 1)
    {
        return D_00797574[arg1];
    }
    else
    {
        return *(s16*)((u8*)D_00796D8C + (s32)arg0 * 0x88 + (s32)arg1 * 2);
    }
}

// FUN_00106D40
void func_00106d40(s16 arg0, s16 arg1, s16 arg2)
{
    if (arg0 == 1)
    {
        D_00797574[arg1] = arg2;
    }
    else
    {
        *(s16*)((u8*)D_00796D8C + (s32)arg0 * 0x88 + (s32)arg1 * 2) = arg2;
    }
}

// FUN_00108CB0
void func_00108cb0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}



// FUN_00108D80
void func_00108d80(void)
{
  long handle;

  if ((handle = func_00452380(D_005e4308)) == 0) {
    return;
  }
  func_00452080(handle);
  return;
}



// FUN_001090F0
void datResetTotalBtl(void)
{
    *(u32*)&D_00797560 = 0;
}



// FUN_00109190
INCLUDE_ASM("asm/nonmatchings/g_data", func_00109190);

// FUN_00109220
u8* func_00109220(s32 personaId)
{
    u16 id;

    K_ASSERT((personaId & 0xffff) < 0x100, 0x18);
    id = personaId;
    return DAT_00764530 + id * 0x11;
}



// FUN_00109280
u8 func_00109280(s32 personaId)
{
    u8* table;
    u16 id;

    K_ASSERT((personaId & 0xffff) < 0x100, 0x26);
    table = DAT_007644c4;
    id = personaId;
    return table[id * 0xE + 2];
}



// FUN_00109390
u8 datPersonaGetLevel(int persona)
{
    return *(u8*)(persona + 4);
}



// FUN_00109400
u8 datPersonaGetLevelByPcId(u16 pcId)
{
    PersonaWork* persona = func_0010a900(pcId);
    return persona->level;
}



// FUN_00109430
u32 datPersonaGetNextExp(int persona)
{
    return *(u32*)(persona + 8);
}



// FUN_00109440
void func_00109440(PersonaWork* persona)
{
    func_0010c750(persona, (u16)(persona->level + 1));
}



// FUN_001094D0
u16* datPersonaGetSkills(int persona)
{
    return (u16*)(persona + 0xc);
}



// FUN_001094E0
u16* datPersonaGetSkillsByPcId(u16 pcId)
{
    PersonaWork* persona = func_0010a900(pcId);

    return persona->skills;
}



// FUN_00109D80
void datPersonaAddToBonusStatByPcId(u16 pcId, u16 statId, s8 amount)
{
    PersonaWork* persona = func_0010a900(pcId);

    persona->bonusStats[statId] += amount;
}



// FUN_0010C6F0
u8 func_0010c6f0(PersonaWork* persona)
{
    if (persona->level >= 99) {
        return 0;
    }
    return func_0010c750(persona, persona->level + 1) <= persona->nextExp;
}



// FUN_0010D360
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d360);

// FUN_0010D480
void func_0010d480(void)
{
}

// FUN_0010D490
void func_0010d490(u8* param_1, u8* param_2)
{
    s32 index;
    s8 value;

    FUN_0043f9c8(DAT_007973a0, 0, 0x24);
    index = 0;

    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_1 + index);
        if (value == '\0')
        {
            break;
        }
        DAT_007973a0[index] = value;
    }

    index = 0;
    for (; index < 0x12; index = index + 1)
    {
        value = *(s8*)(param_2 + index);
        if (value == '\0')
        {
            break;
        }
        DAT_007973a0[index + 0x12] = value;
    }

    func_0010d560();
}
/* measured: see the annotation above the matching `on` pragma (func_0010d490). */
#pragma opt_loop_invariants off



// FUN_0010D560
void func_0010d560(void)
{
    FUN_0043f9c8(DAT_00796de0, 0, 0x12);
    FUN_0043f9c8(DAT_00796e00, 0, 0x12);
    FUN_0043f9c8(DAT_00796e20, 0, 0x24);
    memcpy(DAT_00796de0, DAT_007973a0, 0x12);
    memcpy(DAT_00796e00, DAT_007973b2, 0x12);
    sprintf(DAT_00796e20, &DAT_00762ca0, DAT_00796e00, DAT_00796de0);
}

// FUN_0010D620
u32 func_0010d620(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u32)DAT_00796e20;
    }
    else
    {
        return D_005E4480[arg0];
    }
}

// FUN_0010D660
u32 func_0010d660(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u32)DAT_00796de0;
    }
    if (arg0 < 0xB)
    {
        return D_005E4540[arg0];
    }
    return D_005E4480[arg0];
}

// FUN_0010D6D0
u32 func_0010d6d0(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u32)DAT_00796e00;
    }
    if (arg0 < 0xB)
    {
        return D_005E4570[arg0];
    }
    return D_005E4480[arg0];
}

// FUN_0010D740
u32 func_0010d740(s16 arg0)
{
    if (arg0 == 1)
    {
        return (u32)DAT_00796e00;
    }
    if (arg0 < 0xB)
    {
        return D_005E4570[arg0];
    }
    return D_005E4480[arg0];
}

// FUN_0010D7B0
void func_0010d7b0(void)
{
}

// FUN_0010D7C0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d7c0);

// FUN_0010E710
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010e710);

// FUN_0010E880
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010e880);

// FUN_0010E9E0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010e9e0);

// FUN_0010F390
void func_0010f390(void)
{
    u32 i = 0;
    u8* p = (u8*)DAT_007973a0;

    while (i < 0x55)
    {
        *(u32*)(p + i * 4 + 0x4938) = 0;
        i = i + 1;
    }
}

// FUN_0010F3D0
void func_0010f3d0(u32 arg0, u32 arg1)
{
    u32 bit = (arg1 & 0xffff) + (arg0 & 0xffff) * 8;

    *(u32*)((u8*)D_0079BCD8 + (bit >> 5) * 4) |= 1 << (bit & 0x1f);
}

// FUN_0010F420
u32 func_0010f420(u32 arg0, u32 arg1)
{
    u32 bit = (arg1 & 0xffff) + (arg0 & 0xffff) * 8;
    u32* p = &D_0079BCD8[bit >> 5];

    return *p & (1 << (bit & 0x1f));
}
// FUN_0010F460
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f460);

// FUN_0010F4C0
void func_0010f4c0(void)
{
    func_00193ad0(D_0079BE2C);
}

// FUN_0010F4F0
u8 *func_0010f4f0(s32 arg0) {
    s32 v = (s16)arg0;

    if ((v == 0) || (v >= 0xB)) {
        return NULL;
    }
    return (u8 *)(((s32)D_007973A0 + ((v - 1) * 0x14)) + 0x4A8C);
}

// FUN_0010F540
void func_0010f540(void)
{
    func_00232a40();
}

// FUN_0010F560
void func_0010f560(s16 arg0, u8* arg1)
{
    u8* p;

    if (arg0 == 1)
    {
        p = (u8*)D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        p = (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
    func_0023dd90(p, arg1);
}

// FUN_0010F600
void func_0010f600(s16 arg0, u8* arg1)
{
    u8* p;

    if (arg0 == 1)
    {
        p = (u8*)D_007973C4;
    }
    else
    {
        K_ASSERT(arg0 < 0xB, 0x234);
        p = (u8*)D_00796E50 + (arg0 - 2) * 0x88 + 4;
    }
    func_0023d9b0(p, arg1);
}

// FUN_0010F6A0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f6a0);

// FUN_0010F770
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f770);

// FUN_0010F8C0
u8 func_0010f8c0(s32 arg0)
{
    u8* table;
    u16 id;

    K_ASSERT((arg0 & 0xffff) < 0x1B8, 0xE87);
    table = DAT_007644A8;
    id = arg0;
    return table[id * 0x28 + 8];
}

// FUN_0010F930
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f930);

// FUN_0010FA80
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010fa80);

// FUN_0010FBD0
u32 func_0010fbd0(u32 arg0)
{
    u16 f;

    K_ASSERT(arg0 < 0x100, 0xF04);
    f = *(u16*)((u8*)DAT_007644D0 + arg0 * 0x58);
    if (f & 2)
    {
        return 2;
    }
    if (f & 4)
    {
        return 4;
    }
    if (f & 8)
    {
        return 8;
    }
    return 0;
}

// FUN_0010FC80
void func_0010fc80(void)
{
    FUN_0043f9c8(D_007981CC, 0, 0x3000);
}

// FUN_0010FCB0
u8* func_0010fcb0(s32 arg0)
{
    u16 v;

    K_ASSERT(arg0 >= 0 && arg0 < 0x100, 0xF1D);
    v = *(u16*)((u8*)D_007981CC + arg0 * 0x30);
    if (v & 1)
    {
        return (u8*)DAT_007973a0 + arg0 * 0x30 + 0xE2C;
    }
    return 0;
}

// FUN_0010FD40
void func_0010fd40(u8* src)
{
    s32 index;

    K_ASSERT(src != 0, 0xF27);
    index = *(u16*)(src + 2);
    K_ASSERT(index >= 0 && index < 0x100, 0xF28);
    func_0043f810((u8*)DAT_007973a0 + *(u16*)(src + 2) * 48 + 0xE2C, src, 0x30);
}

// FUN_0010FDE0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010fde0);

// FUN_0010FFA0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010ffa0);

// FUN_00110140
INCLUDE_ASM("asm/nonmatchings/g_data", func_00110140);

// FUN_00110270
void func_00110270(u8* src, u16 arg1)
{
    func_0043f810(D_0079B6A8, src, 0x30);
    D_0079B6A4[0] = arg1;
}

// FUN_001102C0
void func_001102c0(s16 arg0)
{
    D_0079B6A4[0] = arg0;
}

// FUN_001102D0
u16 func_001102d0(void)
{
    return D_0079B6A4[0];
}

// FUN_001102E0
u8* func_001102e0(void)
{
    return D_0079B6A8;
}

// FUN_001102F0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001102f0);
