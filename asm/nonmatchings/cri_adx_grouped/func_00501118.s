.section .text
.set noat
.set noreorder
glabel func_00501118
    /* 401118 00501118 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40111C 0050111C 0000BFFF */  sd         $31, 0x0($29)
    /* 401120 00501120 0000BFDF */  ld         $31, 0x0($29)
    /* 401124 00501124 2E041408 */  j          func_005010b8
    /* 401128 00501128 1000BD27 */   addiu     $29, $29, 0x10
    /* 40112C 0050112C 00000000 */  nop
.size func_00501118, 0x18
