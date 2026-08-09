.section .text
.set noat
.set noreorder
glabel func_0050e4a0
    /* 40E4A0 0050E4A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E4A4 0050E4A4 0000BFFF */  sd         $31, 0x0($29)
    /* 40E4A8 0050E4A8 0000BFDF */  ld         $31, 0x0($29)
    /* 40E4AC 0050E4AC 54AE1408 */  j          func_0052b950
    /* 40E4B0 0050E4B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 40E4B4 0050E4B4 00000000 */  nop
.size func_0050e4a0, 0x18
