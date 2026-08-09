.section .text
.set noat
.set noreorder
glabel func_004ea9f8
    /* 3EA9F8 004EA9F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA9FC 004EA9FC 2D280000 */  daddu      $5, $0, $0
    /* 3EAA00 004EAA00 0000BFFF */  sd         $31, 0x0($29)
    /* 3EAA04 004EAA04 2C000624 */  addiu      $6, $0, 0x2C
    /* 3EAA08 004EAA08 0000BFDF */  ld         $31, 0x0($29)
    /* 3EAA0C 004EAA0C 72FE1008 */  j          func_0043f9c8
    /* 3EAA10 004EAA10 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EAA14 004EAA14 00000000 */  nop
.size func_004ea9f8, 0x20
