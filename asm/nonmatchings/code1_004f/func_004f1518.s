.section .text
.set noat
.set noreorder
glabel func_004f1518
    /* 3F1518 004F1518 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F151C 004F151C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F1520 004F1520 A688130C */  jal        func_004e2298
    /* 3F1524 004F1524 00000000 */   nop
    /* 3F1528 004F1528 0000BFDF */  ld         $31, 0x0($29)
    /* 3F152C 004F152C 9CE61308 */  j          func_004f9a70
    /* 3F1530 004F1530 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F1534 004F1534 00000000 */  nop
.size func_004f1518, 0x20
