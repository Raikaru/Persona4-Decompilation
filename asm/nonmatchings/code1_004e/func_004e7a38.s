.section .text
.set noat
.set noreorder
glabel func_004e7a38
    /* 3E7A38 004E7A38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E7A3C 004E7A3C 2D280000 */  daddu      $5, $0, $0
    /* 3E7A40 004E7A40 0000BFFF */  sd         $31, 0x0($29)
    /* 3E7A44 004E7A44 30000624 */  addiu      $6, $0, 0x30
    /* 3E7A48 004E7A48 0000BFDF */  ld         $31, 0x0($29)
    /* 3E7A4C 004E7A4C 72FE1008 */  j          func_0043f9c8
    /* 3E7A50 004E7A50 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E7A54 004E7A54 00000000 */  nop
.size func_004e7a38, 0x20
