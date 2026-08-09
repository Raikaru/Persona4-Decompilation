.section .text
.set noat
.set noreorder
glabel func_004e6560
    /* 3E6560 004E6560 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E6564 004E6564 0000BFFF */  sd         $31, 0x0($29)
    /* 3E6568 004E6568 0000BFDF */  ld         $31, 0x0($29)
    /* 3E656C 004E656C 24991308 */  j          func_004e6490
    /* 3E6570 004E6570 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E6574 004E6574 00000000 */  nop
.size func_004e6560, 0x18
