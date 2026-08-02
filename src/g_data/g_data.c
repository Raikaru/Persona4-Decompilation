#include "include_asm.h"
#include "type.h"

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

extern void FUN_0043f9c8(void* destination, s32 value, u32 size);
extern void func_0010d560(void);
extern u8 DAT_007973a0[0x24];

// FUN_00104900
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104900);

// FUN_00104A00
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104a00);

// FUN_00104A60
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104a60);

// FUN_00104C50
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104c50);

// FUN_00104C70
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104c70);

// FUN_00104CE0
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104ce0);

// FUN_00104D50
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104d50);

// FUN_00104DC0
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104dc0);

// FUN_00104E30
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104e30);

// FUN_00104EA0
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104ea0);

// FUN_00104F10
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104f10);

// FUN_00104F50
INCLUDE_ASM("asm/nonmatchings/g_data", func_00104f50);

// FUN_00105010
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105010);

// FUN_001051A0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001051a0);

// FUN_00105210
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105210);

// FUN_00105290
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105290);

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
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105340);

// FUN_001053B0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001053b0);

// FUN_00105460
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105460);

// FUN_00105510
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105510);

// FUN_001055A0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001055a0);

// FUN_00105610
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105610);

// FUN_00105690
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105690);

// FUN_001056E0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001056e0);

// FUN_00105730
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105730);

// FUN_00105780
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105780);

// FUN_00105990
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105990);

// FUN_00105A50
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105a50);

// FUN_00105C90
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105c90);

// FUN_00105CE0
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105ce0);

// FUN_00105D50
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105d50);

// FUN_00105DC0
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105dc0);

// FUN_00105E30
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105e30);

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
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105f00);

// FUN_00105F50
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105f50);

// FUN_00105FA0
INCLUDE_ASM("asm/nonmatchings/g_data", func_00105fa0);

// FUN_00106000
void datSetPartyId(s32 idx, s16 pcId)
{
    D_00797560.partyIds[idx] = pcId;
}



// FUN_00106020
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106020);

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
INCLUDE_ASM("asm/nonmatchings/g_data", func_001060f0);

// FUN_00106100
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106100);

// FUN_001062F0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001062f0);

// FUN_00106300
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106300);

// FUN_00106310
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106310);

// FUN_00106320
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106320);

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
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106480);

// FUN_001064C0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001064c0);

// FUN_001064F0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001064f0);

// FUN_00106550
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106550);

// FUN_001065C0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001065c0);

// FUN_00106600
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106600);

// FUN_00106620
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106620);

// FUN_001067F0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001067f0);

// FUN_00106820
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106820);

// FUN_00106850
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106850);

// FUN_00106880
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106880);

// FUN_001068B0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001068b0);

// FUN_001068E0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001068e0);

// FUN_00106910
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106910);

// FUN_00106940
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106940);

// FUN_00106970
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106970);

// FUN_001069A0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001069a0);

// FUN_001069D0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001069d0);

// FUN_00106A00
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106a00);

// FUN_00106A30
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106a30);

// FUN_00106A60
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106a60);

// FUN_00106A90
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106a90);

// FUN_00106AC0
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106ac0);

// FUN_00106AF0
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106af0);

// FUN_00106B20
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106b20);

// FUN_00106B50
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106b50);

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
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106cd0);

// FUN_00106D40
INCLUDE_ASM("asm/nonmatchings/g_data", func_00106d40);

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
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d480);

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
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d620);

// FUN_0010D660
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d660);

// FUN_0010D6D0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d6d0);

// FUN_0010D740
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d740);

// FUN_0010D7B0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d7b0);

// FUN_0010D7C0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010d7c0);

// FUN_0010E710
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010e710);

// FUN_0010E880
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010e880);

// FUN_0010E9E0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010e9e0);

// FUN_0010F390
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f390);

// FUN_0010F3D0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f3d0);

// FUN_0010F420
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f420);

// FUN_0010F460
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f460);

// FUN_0010F4C0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f4c0);

// FUN_0010F4F0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f4f0);

// FUN_0010F540
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f540);

// FUN_0010F560
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f560);

// FUN_0010F600
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f600);

// FUN_0010F6A0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f6a0);

// FUN_0010F770
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f770);

// FUN_0010F8C0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f8c0);

// FUN_0010F930
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010f930);

// FUN_0010FA80
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010fa80);

// FUN_0010FBD0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010fbd0);

// FUN_0010FC80
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010fc80);

// FUN_0010FCB0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010fcb0);

// FUN_0010FD40
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010fd40);

// FUN_0010FDE0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010fde0);

// FUN_0010FFA0
INCLUDE_ASM("asm/nonmatchings/g_data", func_0010ffa0);

// FUN_00110140
INCLUDE_ASM("asm/nonmatchings/g_data", func_00110140);

// FUN_00110270
INCLUDE_ASM("asm/nonmatchings/g_data", func_00110270);

// FUN_001102C0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001102c0);

// FUN_001102D0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001102d0);

// FUN_001102E0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001102e0);

// FUN_001102F0
INCLUDE_ASM("asm/nonmatchings/g_data", func_001102f0);
