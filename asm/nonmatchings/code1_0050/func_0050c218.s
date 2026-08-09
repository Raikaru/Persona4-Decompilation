.section .text
.set noat
.set noreorder
glabel func_0050c218
    /* 40C218 0050C218 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C21C 0050C21C 0000BFFF */  sd         $31, 0x0($29)
    /* 40C220 0050C220 0000BFDF */  ld         $31, 0x0($29)
    /* 40C224 0050C224 8C301408 */  j          func_0050c230
    /* 40C228 0050C228 1000BD27 */   addiu     $29, $29, 0x10
    /* 40C22C 0050C22C 00000000 */  nop
.size func_0050c218, 0x18
