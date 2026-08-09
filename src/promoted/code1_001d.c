#include "include_asm.h"
#include "type.h"

extern s64 func_0023a6b0(s32 arg0, s64 arg1);
extern u16 func_00231f80(u8 *arg0);
extern u16 func_00232290(u8 *arg0);
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *D_0076449C;
extern s32 func_00232710(s32 arg0, s32 arg1);
extern void func_001d6de0(s32 arg0, s32 arg1);
extern void func_001d3e00(s32 arg0);
extern void func_001d6910(u8 *arg0);
extern void func_001d75d0(u8 *arg0);
extern void func_00454bd0(u8 *arg0);



extern void func_001d9b60(u8 *arg0);
extern u8 *func_00457120(void);
extern void func_003e8110(u8 *arg0);
extern void func_003e8120(u8 *arg0);
extern void func_003e9cb0(s32 arg0, u8 *arg1, s32 arg2);
extern u8 D_008813B0[];

typedef int (*code)(...);

extern int func_001d94d0(int param_1, int param_2, int param_3, int param_4, int param_5, code param_6);
extern s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1);



extern s32 func_001da230(u8 *arg0, s16 arg1);

extern s32 func_001d9740(u8 *arg0, s32 arg1);

extern s32 func_001d97b0(u8 *arg0, s32 arg1);

extern void func_001d7bb0(void);
extern void *func_00194470();

extern void func_001d7b30(void);

// FUN_001D01C0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d01c0);
// FUN_001D1310
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d1310);
// FUN_001D14B0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d14b0);
// FUN_001D1540
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d1540);
// FUN_001D15A0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d15a0);
// FUN_001D1680
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d1680);
// FUN_001D1CC0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d1cc0);
// FUN_001D41B0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d41b0);
// FUN_001D44A0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d44a0);
// FUN_001D4780
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d4780);
// FUN_001D48B0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d48b0);
// FUN_001D49C0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d49c0);
// FUN_001D4B00
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d4b00);
// FUN_001D4C40
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d4c40);
// FUN_001D4CF0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d4cf0);
// FUN_001D4DC0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d4dc0);
// FUN_001D4E90
void func_001d4e90(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    *(s32 *)((u8 *)arg3 + 0) = 0;
    *(s32 *)((u8 *)arg3 + 4) = 0;
    *(s32 *)((u8 *)arg3 + 8) = 0;
    *(s32 *)((u8 *)arg3 + 0xC) = 0;
}



// FUN_001D4EB0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d4eb0);
// FUN_001D5130
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d5130);
// FUN_001D53E0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d53e0);
// FUN_001D5990
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d5990);
// FUN_001D5AC0
void func_001d5ac0(void) {
    func_003e8110(func_00457120());
    func_003e9cb0(*(s32 *)(func_00457120() + 4), D_008813B0, 0);
    func_003e8120(func_00457120());
}

// FUN_001D5B20
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d5b20);
// FUN_001D6300
void func_001d6300(u8 *arg0) {
    u8 *temp_3;

    *(s32 *)(arg0 + 0x1C) = 0;
    func_001d40d0(*(u8 **)(arg0 + 0));
    temp_3 = (u8 *)(*(u8 **)(arg0 + 4));
    *(u16 *)(temp_3 + 0xA0) = (u16) (*(u16 *)(temp_3 + 0xA0) + 1);
    *(s32 *)(arg0 + 0x18) = func_001d6ce0(*(s32 *)((u8 *)(*(u8 **)(arg0 + 4)) + 0xA08));
}

// FUN_001D6360
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6360);
// FUN_001D6570
void func_001d6570(u8 *arg0)
{
    func_001d6de0(*(s32 *)(*(u8 **)(arg0 + 4) + 0xA08), *(s32 *)(arg0 + 0x18));
    func_001d3e00(*(s32 *)arg0);
    *(u16 *)(*(u8 **)(arg0 + 4) + 0xA0) =
        *(u16 *)(*(u8 **)(arg0 + 4) + 0xA0) - 1;
}

// FUN_001D65D0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d65d0);
// FUN_001D6680
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6680);
// FUN_001D6910
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6910);
// FUN_001D6A60
void func_001d6a60(void)
{
}

// FUN_001D6A70
void func_001d6a70(void)
{
    u8 *temp_16;
    u8 *var_4;

    var_4 = *(u8 **)(iGpffffb3ac + 0x1B8);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x20);
        func_001d6910(var_4);
        var_4 = temp_16;
    }
    func_001d75d0(var_4);
}

// FUN_001D6AD0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6ad0);
// FUN_001D6C10
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6c10);
// FUN_001D72E0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d72e0);
// FUN_001D7400
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7400);
// FUN_001D75D0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d75d0);
// FUN_001D7700
void func_001d7700(void)
{
    u8 *temp_4;
    u8 *temp_5;

    temp_5 = iGpffffb3ac;
    if ((*(s32 *)(temp_5 + 0x14) & 0x4000000) == 0) {
        temp_4 = *(u8 **)(temp_5 + 0xDC4);
        if (temp_4 != NULL) {
            func_00454bd0(temp_4);
        }
        *(u8 **)(iGpffffb3ac + 0xDC4) = NULL;
        return;
    }
    *(u8 **)(temp_5 + 0xDC4) = NULL;
}

// FUN_001D7A60
s32 func_001d7a60(u8 *arg0) {
    func_00122520(1, *(u16 *)(arg0 + 4));
    func_001228a0(*(u8 *)(arg0 + 0), *(u8 *)(arg0 + 1), *(u8 *)(arg0 + 2));
    return 1;
}

// FUN_001D7B30
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7b30);
// FUN_001D7B60
void func_001d7b60(u16 param_1)
{
  int iVar1 = 0;

  iVar1 = (int)func_00194470(0x30B, 2);
  *(code *)(iVar1 + 0x6c) = (code)func_001d7b30;
  **(u16 **)(iVar1 + 0x78) = param_1;
  return;
}

// FUN_001D7BF0
void func_001d7bf0(u32 param_1, u32 param_2, u32 param_3)
{
    u32 *work;
    u32 packet;

    packet = (u32)func_00194470(0x309, 0xc);
    *(code **)(packet + 0x6c) = (code *)func_001d7bb0;
    work = *(u32 **)(packet + 0x78);
    work[0] = param_1;
    work[1] = param_2;
    work[2] = param_3;
}

// FUN_001D7C60
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7c60);
// FUN_001D7F10
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7f10);
// FUN_001D8010
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d8010);
// FUN_001D8C00
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d8c00);
// FUN_001D8CB0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d8cb0);
// FUN_001D8E50
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d8e50);
// FUN_001D9280
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9280);
// FUN_001D9390
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9390);
// FUN_001D94D0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d94d0);
// FUN_001D9740
s32 func_001d9740(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 8);
    uVar2 = func_00231f80(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return (u32)uVar1 * 100 <= (uVar2 & 0xFFFF) * arg1;
}

// FUN_001D97B0
s32 func_001d97b0(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 8);
    uVar2 = func_00231f80(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return !((u32)uVar1 * 100 < (uVar2 & 0xFFFF) * arg1);
}

// FUN_001D9820
s32 func_001d9820(u8 *arg0, s32 arg1)
{
    u32 uVar2 = 0;
    u32 uVar1 = 0;

    uVar1 = *(u16 *)(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64) + 0xA);
    uVar2 = func_00232290(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
    return (u32)uVar1 * 100 <= (uVar2 & 0xFFFF) * arg1;
}

// FUN_001D9890
void func_001d9890(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)func_001d9740);
}

// FUN_001D98E0
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void func_001d98e0(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001d9740);
}
#pragma opt_rebuildconditionals on

// FUN_001D9940
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void func_001d9940(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001d97b0);
}
#pragma opt_rebuildconditionals on

// FUN_001D99A0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d99a0);
// FUN_001D9B60
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9b60);
// FUN_001D9B90
void func_001d9b90(u8 *arg0, u32 arg1)
{
    u32 mask;

    mask = (1 << *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2)) & 0xFFFF;
    if ((arg1 & 0x80000) != 0) {
        func_001d94d0((int)arg0, arg1, mask, 0, 0, (code)func_001d9b60);
    } else {
        func_001d94d0((int)arg0, arg1, mask, 0x80000, 0, (code)func_001d9b60);
    }
}

// FUN_001D9C00
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9c00);
// FUN_001D9CA0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9ca0);
// FUN_001D9DB0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9db0);
// FUN_001D9E80
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9e80);
// FUN_001D9F60
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9f60);
// FUN_001DA040
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da040);
// FUN_001DA130
s32 func_001da130(u8 *arg0) {
    s32 r;

    if (func_00232710(*(s32 *)(*(u8 **)(arg0 + 0x30) + 0xA64), 0x180010) != 0) {
        r = 0;
    } else {
        r = (*(s32 *)(iGpffffb414 + *(u16 *)(*(u8 **)(D_0076449C + 0xC68) + 8) * 0x18) & 1) != 0;
    }
    return r;
}

// FUN_001DA1A0
s32 func_001da1a0(void)
{
    return 0;
}

// FUN_001DA1B0
s32 func_001da1b0(u8 *arg0)
{
    u8 genus;

    if (*(s32 *)(arg0 + 0x20) > 0)
        return 0;
    genus = *(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2);
    switch (genus) {
    case 0:
        return *(u16 *)(iGpffffb3ac + 0x1A) == 1;
    case 1:
        return *(u16 *)(iGpffffb3ac + 0x1A) == 2;
    default:
        return 0;
    }
}

// FUN_001DA230
s32 btlCond_MYHANSYA(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x02000000) != 0);
}



// FUN_001DA270
s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x04000000) != 0);
}



// FUN_001DA2B0
s32 btlCond_MYMUKOU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x01000000) != 0);
}



// FUN_001DA2F0
s32 btlCond_MYWEAK(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x08000000) != 0);
}



// FUN_001DA330
void func_001da330(u8 *arg0, u32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2))) & 0xFFFF, 0x80000, 0, (code)func_001da230);
}

// FUN_001DA380
#pragma opt_rebuildconditionals off
/* Same shape as btlAICommand func_001db990, whose note records that removing this
   pragma costs the match (nd 0 -> 43) - measured there, inherited here. */
void func_001da380(u8 *arg0, u32 arg1) {
    u32 shift;
    {
        if (*(u8 *)(*(u8 **)(arg0 + 0x30) + 0xA2) != 0)
            goto nonzero;
        shift = 1;
        goto done;
    nonzero:
        shift = 0;
    done:
        ;
    }
    func_001d94d0((int)arg0, arg1, (1 << (shift & 0xffff)) & 0xffff, 0x80000, 0, (code)func_001da230);
}
#pragma opt_rebuildconditionals on

// FUN_001DA3E0
void btlCond_FRKYUSYU(u8 *arg0, s32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << *(u8 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA2)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYKYUSYU);
}

// FUN_001DA430
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da430);
// FUN_001DA490
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da490);
// FUN_001DA4E0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da4e0);
// FUN_001DA540
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da540);
// FUN_001DA590
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da590);
// FUN_001DA5F0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da5f0);
// FUN_001DA640
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da640);
// FUN_001DA690
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da690);
// FUN_001DA930
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da930);
// FUN_001DAA00
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001daa00);
// FUN_001DAA50
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001daa50);
// FUN_001DAAB0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001daab0);
// FUN_001DAB00
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001dab00);
// FUN_001DAB60
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001dab60);
// FUN_001DABB0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001dabb0);
// FUN_001DAC10
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001dac10);
// FUN_001DAC60
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001dac60);
// FUN_001DACE0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001dace0);
// FUN_001DAE00
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001dae00);