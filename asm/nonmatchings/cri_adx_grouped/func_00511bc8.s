.section .text
.set noat
.set noreorder
glabel func_00511bc8
    /* 411BC8 00511BC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411BCC 00511BCC 0000BFFF */  sd         $31, 0x0($29)
    /* 411BD0 00511BD0 0000BFDF */  ld         $31, 0x0($29)
    /* 411BD4 00511BD4 F8461408 */  j          func_00511be0
    /* 411BD8 00511BD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 411BDC 00511BDC 00000000 */  nop
.size func_00511bc8, 0x18
