.section .text
.set noat
.set noreorder
glabel func_005074f0
    /* 4074F0 005074F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4074F4 005074F4 0000BFFF */  sd         $31, 0x0($29)
    /* 4074F8 005074F8 0000BFDF */  ld         $31, 0x0($29)
    /* 4074FC 005074FC 8AEC1308 */  j          func_004fb228
    /* 407500 00507500 1000BD27 */   addiu     $29, $29, 0x10
    /* 407504 00507504 00000000 */  nop
.size func_005074f0, 0x18
