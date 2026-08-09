.section .text
.set noat
.set noreorder
glabel func_004ca6e0
    /* 3CA6E0 004CA6E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA6E4 004CA6E4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CA6E8 004CA6E8 CC56130C */  jal        func_004d5b30
    /* 3CA6EC 004CA6EC 00000000 */   nop
    /* 3CA6F0 004CA6F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CA6F4 004CA6F4 2D100000 */  daddu      $2, $0, $0
    /* 3CA6F8 004CA6F8 0800E003 */  jr         $31
    /* 3CA6FC 004CA6FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ca6e0, 0x20
