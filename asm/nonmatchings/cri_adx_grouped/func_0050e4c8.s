.section .text
.set noat
.set noreorder
glabel func_0050e4c8
    /* 40E4C8 0050E4C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E4CC 0050E4CC 0000BFFF */  sd         $31, 0x0($29)
    /* 40E4D0 0050E4D0 0000BFDF */  ld         $31, 0x0($29)
    /* 40E4D4 0050E4D4 38391408 */  j          func_0050e4e0
    /* 40E4D8 0050E4D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 40E4DC 0050E4DC 00000000 */  nop
.size func_0050e4c8, 0x18
