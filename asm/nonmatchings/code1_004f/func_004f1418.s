.section .text
.set noat
.set noreorder
glabel func_004f1418
    /* 3F1418 004F1418 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F141C 004F141C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F1420 004F1420 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1424 004F1424 28881308 */  j          func_004e20a0
    /* 3F1428 004F1428 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F142C 004F142C 00000000 */  nop
.size func_004f1418, 0x18
