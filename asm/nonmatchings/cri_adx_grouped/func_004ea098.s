.section .text
.set noat
.set noreorder
glabel func_004ea098
    /* 3EA098 004EA098 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EA09C 004EA09C 2D280000 */  daddu      $5, $0, $0
    /* 3EA0A0 004EA0A0 0000BFFF */  sd         $31, 0x0($29)
    /* 3EA0A4 004EA0A4 38000624 */  addiu      $6, $0, 0x38
    /* 3EA0A8 004EA0A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3EA0AC 004EA0AC 72FE1008 */  j          func_0043f9c8
    /* 3EA0B0 004EA0B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EA0B4 004EA0B4 00000000 */  nop
.size func_004ea098, 0x20
