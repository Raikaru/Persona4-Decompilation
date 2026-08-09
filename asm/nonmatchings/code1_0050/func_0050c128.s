.section .text
.set noat
.set noreorder
glabel func_0050c128
    /* 40C128 0050C128 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C12C 0050C12C 0000BFFF */  sd         $31, 0x0($29)
    /* 40C130 0050C130 0000BFDF */  ld         $31, 0x0($29)
    /* 40C134 0050C134 50301408 */  j          func_0050c140
    /* 40C138 0050C138 1000BD27 */   addiu     $29, $29, 0x10
    /* 40C13C 0050C13C 00000000 */  nop
.size func_0050c128, 0x18
