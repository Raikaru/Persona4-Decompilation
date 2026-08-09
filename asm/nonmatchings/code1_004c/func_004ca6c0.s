.section .text
.set noat
.set noreorder
glabel func_004ca6c0
    /* 3CA6C0 004CA6C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA6C4 004CA6C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CA6C8 004CA6C8 A02C130C */  jal        func_004cb280
    /* 3CA6CC 004CA6CC 00000000 */   nop
    /* 3CA6D0 004CA6D0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CA6D4 004CA6D4 2D100000 */  daddu      $2, $0, $0
    /* 3CA6D8 004CA6D8 0800E003 */  jr         $31
    /* 3CA6DC 004CA6DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ca6c0, 0x20
