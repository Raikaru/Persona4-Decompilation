.section .text
.set noat
.set noreorder
glabel func_004f1448
    /* 3F1448 004F1448 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F144C 004F144C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F1450 004F1450 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1454 004F1454 90881308 */  j          func_004e2240
    /* 3F1458 004F1458 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F145C 004F145C 00000000 */  nop
.size func_004f1448, 0x18
