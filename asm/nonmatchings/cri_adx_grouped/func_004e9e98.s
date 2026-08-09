.section .text
.set noat
.set noreorder
glabel func_004e9e98
    /* 3E9E98 004E9E98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E9E9C 004E9E9C 0000BFFF */  sd         $31, 0x0($29)
    /* 3E9EA0 004E9EA0 0000BFDF */  ld         $31, 0x0($29)
    /* 3E9EA4 004E9EA4 16111108 */  j          func_00444458
    /* 3E9EA8 004E9EA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E9EAC 004E9EAC 00000000 */  nop
.size func_004e9e98, 0x18
