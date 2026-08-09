#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(void *);

extern void func_004841c0(void *arg0);

extern void func_00484280();



// FUN_00490360
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00490360);
// FUN_004903C0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004903c0);
// FUN_00490BB0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00490bb0);
// FUN_00490C40
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00490c40);
// FUN_00491660
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00491660);
// FUN_004916F0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004916f0);
// FUN_00492080
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492080);
// FUN_00492100
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492100);
// FUN_00492A80
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492a80);
// FUN_00492B20
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492b20);
// FUN_00492CD0
void func_00492cd0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x28));
}



// FUN_00492D00
void func_00492d00(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}

// FUN_00492D10
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492d10);
// FUN_00492E30
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00492e30);
// FUN_004940D0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004940d0);
// FUN_004941F0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004941f0);
// FUN_00494680
void func_00494680(void *arg0)
{
    func_004841c0(*(void **)((u8 *)arg0 + 0x10));
    func_004841c0(*(void **)((u8 *)arg0 + 0x14));
    jtbl_008873EC[0](arg0);
}



// FUN_00494740
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00494740);
// FUN_00494F90
void func_00494f90(u8 *arg0) {
    func_0048a1f0();
    func_003c2290(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x10)) + 0x10)) + 0x18), 0xA);
    func_003c2290(*(u8 **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x14)) + 0x10)) + 0x18), 0xA);
}

// FUN_00494FF0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00494ff0);
// FUN_00495090
void func_00495090(u8 *arg0, u32 arg1)
{
    func_00484280(*(void **)(arg0 + 0x10));
    func_00484280(*(void **)(arg0 + 0x14), arg1);
}

// FUN_004950E0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_004950e0);
// FUN_00498AC0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498ac0);
// FUN_00498B20
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498b20);
// FUN_00498B50
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498b50);
// FUN_00498BA0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498ba0);
// FUN_00498C00
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498c00);
// FUN_00498CE0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498ce0);
// FUN_00498CF0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498cf0);
// FUN_00498D00
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498d00);
// FUN_00498D10
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498d10);
// FUN_00498D20
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_00498d20);
// FUN_0049A570
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a570);
// FUN_0049A5E0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a5e0);
// FUN_0049A610
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a610);
// FUN_0049A660
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a660);
// FUN_0049A6C0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a6c0);
// FUN_0049A7A0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a7a0);
// FUN_0049A7B0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a7b0);
// FUN_0049A7C0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a7c0);
// FUN_0049A7D0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a7d0);
// FUN_0049A7F0
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a7f0);
// FUN_0049A810
INCLUDE_ASM("asm/nonmatchings/code1_0049", func_0049a810);