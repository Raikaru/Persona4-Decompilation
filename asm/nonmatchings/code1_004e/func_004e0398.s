.section .text
.set noat
.set noreorder
glabel func_004e0398
    /* 3E0398 004E0398 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E039C 004E039C 0000BFFF */  sd         $31, 0x0($29)
    /* 3E03A0 004E03A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3E03A4 004E03A4 88C11308 */  j          func_004f0620
    /* 3E03A8 004E03A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E03AC 004E03AC 00000000 */  nop
.size func_004e0398, 0x18
