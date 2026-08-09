.section .text
.set noat
.set noreorder
glabel func_0050e488
    /* 40E488 0050E488 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E48C 0050E48C 0000BFFF */  sd         $31, 0x0($29)
    /* 40E490 0050E490 0000BFDF */  ld         $31, 0x0($29)
    /* 40E494 0050E494 CEAD1408 */  j          func_0052b738
    /* 40E498 0050E498 1000BD27 */   addiu     $29, $29, 0x10
    /* 40E49C 0050E49C 00000000 */  nop
.size func_0050e488, 0x18
