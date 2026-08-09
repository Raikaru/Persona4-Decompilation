.section .text
.set noat
.set noreorder
glabel func_0020ba30
    /* 10BA30 0020BA30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 10BA34 0020BA34 0000BFFF */  sd         $31, 0x0($29)
    /* 10BA38 0020BA38 5849110C */  jal        func_00452560
    /* 10BA3C 0020BA3C 00000000 */   nop
    /* 10BA40 0020BA40 120740A4 */  sh         $0, 0x712($2)
    /* 10BA44 0020BA44 0000BFDF */  ld         $31, 0x0($29)
    /* 10BA48 0020BA48 1000BD27 */  addiu      $29, $29, 0x10
    /* 10BA4C 0020BA4C 0800E003 */  jr         $31
    /* 10BA50 0020BA50 00000000 */   nop
    /* 10BA54 0020BA54 00000000 */  nop
    /* 10BA58 0020BA58 00000000 */  nop
    /* 10BA5C 0020BA5C 00000000 */  nop
.size func_0020ba30, 0x30
