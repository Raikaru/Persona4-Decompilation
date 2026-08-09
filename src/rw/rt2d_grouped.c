/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
void func_003d5830(void);
void func_003d5990(s32 object, u32 first, u32 second);
u32 func_003d60e0(u32 object, u32 value);
u32 func_003d7b30(void);

/* Source unit: src/rw/rt2d_003d5830.c (1 function markers) */

extern void (*DAT_008873ec_abs[])(void);

#pragma optimization_level 3
// FUN_003D5830
void func_003d5830(void)
{
    DAT_008873ec_abs[0]();
}
#pragma optimization_level 2

/* Source unit: src/rw/rt2d_003d5990.c (1 function markers) */
#pragma optimization_level 3

// FUN_003D5840
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d5840);
// FUN_003D5990
void func_003d5990(s32 object, u32 first, u32 second)
{
    *(u32*)(object + 0x18) = first;
    *(u32*)(object + 0x1c) = second;
}
#pragma optimization_level 2

/* Source unit: src/rw/rt2d_003d60e0.c (1 function markers) */

#pragma schedule on
// FUN_003D60E0
u32 func_003d60e0(u32 object, u32 value)
{
    *(u32 *)(object + 0x14) = value;
    return object;
}
#pragma schedule off

/* Source unit: src/rw/rt2d_003d7b30.c (1 function markers) */
#pragma optimization_level 3

// FUN_003D60F0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d60f0);
// FUN_003D6170
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6170);
// FUN_003D6230
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6230);
// FUN_003D6350
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6350);
// FUN_003D65E0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d65e0);
// FUN_003D6680
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6680);
// FUN_003D6790
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6790);
// FUN_003D68B0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d68b0);
// FUN_003D6900
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6900);
// FUN_003D6950
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6950);
// FUN_003D6A00
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6a00);
// FUN_003D6AA0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6aa0);
// FUN_003D6B70
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6b70);
// FUN_003D6C10
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6c10);
// FUN_003D6C50
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6c50);
// FUN_003D6D50
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6d50);
// FUN_003D6E80
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6e80);
// FUN_003D6F90
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6f90);
// FUN_003D6FA0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6fa0);
// FUN_003D6FB0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6fb0);
// FUN_003D70C0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d70c0);
// FUN_003D7150
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7150);
// FUN_003D71B0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d71b0);
// FUN_003D7260
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7260);
// FUN_003D72A0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d72a0);
// FUN_003D7350
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7350);
// FUN_003D7490
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7490);
// FUN_003D75B0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d75b0);
// FUN_003D76D0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d76d0);
// FUN_003D77F0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d77f0);
// FUN_003D79B0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d79b0);
// FUN_003D7A20
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7a20);
// FUN_003D7AC0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7ac0);
// FUN_003D7B30
u32 func_003d7b30(void)
{
    return 0x40;
}
#pragma optimization_level 2
