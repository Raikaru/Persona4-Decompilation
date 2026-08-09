.section .text
.set noat
.set noreorder
glabel func_004cce10
    /* 3CCE10 004CCE10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCE14 004CCE14 0000BFFF */  sd         $31, 0x0($29)
    /* 3CCE18 004CCE18 0000BFDF */  ld         $31, 0x0($29)
    /* 3CCE1C 004CCE1C 82C11308 */  j          func_004f0608
    /* 3CCE20 004CCE20 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCE24 004CCE24 00000000 */  nop
.size func_004cce10, 0x18
