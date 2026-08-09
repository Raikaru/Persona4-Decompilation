.section .text
.set noat
.set noreorder
glabel func_0051a6f0
    /* 41A6F0 0051A6F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41A6F4 0051A6F4 0000BFFF */  sd         $31, 0x0($29)
    /* 41A6F8 0051A6F8 0000BFDF */  ld         $31, 0x0($29)
    /* 41A6FC 0051A6FC C2691408 */  j          func_0051a708
    /* 41A700 0051A700 1000BD27 */   addiu     $29, $29, 0x10
    /* 41A704 0051A704 00000000 */  nop
.size func_0051a6f0, 0x18
