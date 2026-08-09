.section .text
.set noat
.set noreorder
glabel func_004e5e60
    /* 3E5E60 004E5E60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E5E64 004E5E64 2D280000 */  daddu      $5, $0, $0
    /* 3E5E68 004E5E68 0000BFFF */  sd         $31, 0x0($29)
    /* 3E5E6C 004E5E6C 48000624 */  addiu      $6, $0, 0x48
    /* 3E5E70 004E5E70 0000BFDF */  ld         $31, 0x0($29)
    /* 3E5E74 004E5E74 72FE1008 */  j          func_0043f9c8
    /* 3E5E78 004E5E78 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E5E7C 004E5E7C 00000000 */  nop
.size func_004e5e60, 0x20
