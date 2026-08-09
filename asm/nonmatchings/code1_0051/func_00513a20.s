.section .text
.set noat
.set noreorder
glabel func_00513a20
    /* 413A20 00513A20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 413A24 00513A24 0000BFFF */  sd         $31, 0x0($29)
    /* 413A28 00513A28 364F130C */  jal        func_004d3cd8
    /* 413A2C 00513A2C 00000000 */   nop
    /* 413A30 00513A30 0000BFDF */  ld         $31, 0x0($29)
    /* 413A34 00513A34 2D100000 */  daddu      $2, $0, $0
    /* 413A38 00513A38 0800E003 */  jr         $31
    /* 413A3C 00513A3C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00513a20, 0x20
