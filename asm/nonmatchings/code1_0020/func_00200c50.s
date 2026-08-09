.section .text
.set noat
.set noreorder
glabel func_00200c50
    /* 100C50 00200C50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 100C54 00200C54 0000BFFF */  sd         $31, 0x0($29)
    /* 100C58 00200C58 404D040C */  jal        func_00113500
    /* 100C5C 00200C5C 00000000 */   nop
    /* 100C60 00200C60 0000BFDF */  ld         $31, 0x0($29)
    /* 100C64 00200C64 1000BD27 */  addiu      $29, $29, 0x10
    /* 100C68 00200C68 0800E003 */  jr         $31
    /* 100C6C 00200C6C 00000000 */   nop
.size func_00200c50, 0x20
