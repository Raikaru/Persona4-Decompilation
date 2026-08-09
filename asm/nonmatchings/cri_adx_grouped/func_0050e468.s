.section .text
.set noat
.set noreorder
glabel func_0050e468
    /* 40E468 0050E468 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E46C 0050E46C 0000BFFF */  sd         $31, 0x0($29)
    /* 40E470 0050E470 0000BFDF */  ld         $31, 0x0($29)
    /* 40E474 0050E474 B2AD1408 */  j          func_0052b6c8
    /* 40E478 0050E478 1000BD27 */   addiu     $29, $29, 0x10
    /* 40E47C 0050E47C 00000000 */  nop
.size func_0050e468, 0x18
