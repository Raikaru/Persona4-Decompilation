.section .text
.set noat
.set noreorder
glabel func_0050ee10
    /* 40EE10 0050EE10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40EE14 0050EE14 0000BFFF */  sd         $31, 0x0($29)
    /* 40EE18 0050EE18 0000BFDF */  ld         $31, 0x0($29)
    /* 40EE1C 0050EE1C 5E3B1408 */  j          func_0050ed78
    /* 40EE20 0050EE20 1000BD27 */   addiu     $29, $29, 0x10
    /* 40EE24 0050EE24 00000000 */  nop
.size func_0050ee10, 0x18
