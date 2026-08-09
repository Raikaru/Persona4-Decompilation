.section .text
.set noat
.set noreorder
glabel func_004e73d8
    /* 3E73D8 004E73D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E73DC 004E73DC 0000BFFF */  sd         $31, 0x0($29)
    /* 3E73E0 004E73E0 0000BFDF */  ld         $31, 0x0($29)
    /* 3E73E4 004E73E4 BC911308 */  j          func_004e46f0
    /* 3E73E8 004E73E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E73EC 004E73EC 00000000 */  nop
.size func_004e73d8, 0x18
