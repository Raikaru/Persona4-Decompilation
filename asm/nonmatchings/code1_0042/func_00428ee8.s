.section .text
.set noat
.set noreorder
glabel func_00428ee8
    /* 328EE8 00428EE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 328EEC 00428EEC 0000BFFF */  sd         $31, 0x0($29)
    /* 328EF0 00428EF0 769F100C */  jal        func_00427dd8
    /* 328EF4 00428EF4 12000524 */   addiu     $5, $0, 0x12
    /* 328EF8 00428EF8 0000BFDF */  ld         $31, 0x0($29)
    /* 328EFC 00428EFC 0800E003 */  jr         $31
    /* 328F00 00428F00 1000BD27 */   addiu     $29, $29, 0x10
    /* 328F04 00428F04 00000000 */  nop
.size func_00428ee8, 0x20
