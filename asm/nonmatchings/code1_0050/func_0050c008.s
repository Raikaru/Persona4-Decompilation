.section .text
.set noat
.set noreorder
glabel func_0050c008
    /* 40C008 0050C008 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C00C 0050C00C 0000BFFF */  sd         $31, 0x0($29)
    /* 40C010 0050C010 0000BFDF */  ld         $31, 0x0($29)
    /* 40C014 0050C014 08301408 */  j          func_0050c020
    /* 40C018 0050C018 1000BD27 */   addiu     $29, $29, 0x10
    /* 40C01C 0050C01C 00000000 */  nop
.size func_0050c008, 0x18
