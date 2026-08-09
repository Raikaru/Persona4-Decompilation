.section .text
.set noat
.set noreorder
glabel func_004f1430
    /* 3F1430 004F1430 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1434 004F1434 0000BFFF */  sd         $31, 0x0($29)
    /* 3F1438 004F1438 0000BFDF */  ld         $31, 0x0($29)
    /* 3F143C 004F143C 5C881308 */  j          func_004e2170
    /* 3F1440 004F1440 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1444 004F1444 00000000 */  nop
.size func_004f1430, 0x18
