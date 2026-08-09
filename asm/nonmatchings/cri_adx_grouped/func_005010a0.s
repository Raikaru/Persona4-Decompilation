.section .text
.set noat
.set noreorder
glabel func_005010a0
    /* 4010A0 005010A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4010A4 005010A4 0000BFFF */  sd         $31, 0x0($29)
    /* 4010A8 005010A8 0000BFDF */  ld         $31, 0x0($29)
    /* 4010AC 005010AC 04FE1008 */  j          func_0043f810
    /* 4010B0 005010B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4010B4 005010B4 00000000 */  nop
.size func_005010a0, 0x18
