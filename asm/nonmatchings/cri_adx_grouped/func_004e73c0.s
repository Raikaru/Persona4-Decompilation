.section .text
.set noat
.set noreorder
glabel func_004e73c0
    /* 3E73C0 004E73C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E73C4 004E73C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3E73C8 004E73C8 0000BFDF */  ld         $31, 0x0($29)
    /* 3E73CC 004E73CC A6911308 */  j          func_004e4698
    /* 3E73D0 004E73D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E73D4 004E73D4 00000000 */  nop
.size func_004e73c0, 0x18
