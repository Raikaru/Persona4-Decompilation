.section .text
.set noat
.set noreorder
glabel func_004ed468
    /* 3ED468 004ED468 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED46C 004ED46C 0000BFFF */  sd         $31, 0x0($29)
    /* 3ED470 004ED470 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED474 004ED474 88C11308 */  j          func_004f0620
    /* 3ED478 004ED478 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED47C 004ED47C 00000000 */  nop
.size func_004ed468, 0x18
