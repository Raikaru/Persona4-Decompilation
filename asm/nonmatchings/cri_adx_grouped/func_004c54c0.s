.section .text
.set noat
.set noreorder
glabel func_004c54c0
    /* 3C54C0 004C54C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C54C4 004C54C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3C54C8 004C54C8 0000BFDF */  ld         $31, 0x0($29)
    /* 3C54CC 004C54CC 88C11308 */  j          func_004f0620
    /* 3C54D0 004C54D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C54D4 004C54D4 00000000 */  nop
.size func_004c54c0, 0x18
