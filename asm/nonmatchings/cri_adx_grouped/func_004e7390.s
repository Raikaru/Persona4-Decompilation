.section .text
.set noat
.set noreorder
glabel func_004e7390
    /* 3E7390 004E7390 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E7394 004E7394 0000BFFF */  sd         $31, 0x0($29)
    /* 3E7398 004E7398 0000BFDF */  ld         $31, 0x0($29)
    /* 3E739C 004E739C 92911308 */  j          func_004e4648
    /* 3E73A0 004E73A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E73A4 004E73A4 00000000 */  nop
.size func_004e7390, 0x18
