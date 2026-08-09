.section .text
.set noat
.set noreorder
glabel func_005125e0
    /* 4125E0 005125E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4125E4 005125E4 0000BFFF */  sd         $31, 0x0($29)
    /* 4125E8 005125E8 0000BFDF */  ld         $31, 0x0($29)
    /* 4125EC 005125EC 7E491408 */  j          func_005125f8
    /* 4125F0 005125F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4125F4 005125F4 00000000 */  nop
.size func_005125e0, 0x18
