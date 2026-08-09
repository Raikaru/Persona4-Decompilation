.section .text
.set noat
.set noreorder
glabel func_003deff0
    /* 2DEFF0 003DEFF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2DEFF4 003DEFF4 FFFF0231 */  andi       $2, $8, 0xFFFF
    /* 2DEFF8 003DEFF8 0000BFFF */  sd         $31, 0x0($29)
    /* 2DEFFC 003DEFFC FDFF033C */  lui        $3, (0xFFFD0000 >> 16)
    /* 2DF000 003DF000 2140E300 */  addu       $8, $7, $3
    /* 2DF004 003DF004 1400A6AF */  sw         $6, 0x14($29)
    /* 2DF008 003DF008 3F00E330 */  andi       $3, $7, 0x3F
    /* 2DF00C 003DF00C 0300063C */  lui        $6, (0x3FF00 >> 16)
    /* 2DF010 003DF010 00FFC734 */  ori        $7, $6, (0x3FF00 & 0xFFFF)
    /* 2DF014 003DF014 1000A5AF */  sw         $5, 0x10($29)
    /* 2DF018 003DF018 24380701 */  and        $7, $8, $7
    /* 2DF01C 003DF01C 001C0300 */  sll        $3, $3, 16
    /* 2DF020 003DF020 803B0700 */  sll        $7, $7, 14
    /* 2DF024 003DF024 1000A527 */  addiu      $5, $29, 0x10
    /* 2DF028 003DF028 2518E300 */  or         $3, $7, $3
    /* 2DF02C 003DF02C 0C000624 */  addiu      $6, $0, 0xC
    /* 2DF030 003DF030 25104300 */  or         $2, $2, $3
    /* 2DF034 003DF034 AC8A0F0C */  jal        func_003e2ab0
    /* 2DF038 003DF038 1800A2AF */   sw        $2, 0x18($29)
    /* 2DF03C 003DF03C 0000BFDF */  ld         $31, 0x0($29)
    /* 2DF040 003DF040 0800E003 */  jr         $31
    /* 2DF044 003DF044 2000BD27 */   addiu     $29, $29, 0x20
    /* 2DF048 003DF048 00000000 */  nop
    /* 2DF04C 003DF04C 00000000 */  nop
.size func_003deff0, 0x60
