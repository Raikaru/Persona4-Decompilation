.section .text
.set noat
.set noreorder
glabel func_0050ad38
    /* 40AD38 0050AD38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40AD3C 0050AD3C 0000BFFF */  sd         $31, 0x0($29)
    /* 40AD40 0050AD40 0000BFDF */  ld         $31, 0x0($29)
    /* 40AD44 0050AD44 8C2C1408 */  j          func_0050b230
    /* 40AD48 0050AD48 1000BD27 */   addiu     $29, $29, 0x10
    /* 40AD4C 0050AD4C 00000000 */  nop
.size func_0050ad38, 0x18
