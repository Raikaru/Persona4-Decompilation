.section .text
.set noat
.set noreorder
glabel func_00312b60
    /* 212B60 00312B60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 212B64 00312B64 0000BFFF */  sd         $31, 0x0($29)
    /* 212B68 00312B68 FFFFA530 */  andi       $5, $5, 0xFFFF
    /* 212B6C 00312B6C FFFFC630 */  andi       $6, $6, 0xFFFF
    /* 212B70 00312B70 28490C0C */  jal        func_003124a0
    /* 212B74 00312B74 00000000 */   nop
    /* 212B78 00312B78 FF004230 */  andi       $2, $2, 0xFF
    /* 212B7C 00312B7C 0000BFDF */  ld         $31, 0x0($29)
    /* 212B80 00312B80 1000BD27 */  addiu      $29, $29, 0x10
    /* 212B84 00312B84 0800E003 */  jr         $31
    /* 212B88 00312B88 00000000 */   nop
    /* 212B8C 00312B8C 00000000 */  nop
.size func_00312b60, 0x30
