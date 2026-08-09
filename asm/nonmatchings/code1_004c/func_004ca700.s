.section .text
.set noat
.set noreorder
glabel func_004ca700
    /* 3CA700 004CA700 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA704 004CA704 0000BFFF */  sd         $31, 0x0($29)
    /* 3CA708 004CA708 5227130C */  jal        func_004c9d48
    /* 3CA70C 004CA70C 00000000 */   nop
    /* 3CA710 004CA710 0000BFDF */  ld         $31, 0x0($29)
    /* 3CA714 004CA714 2D100000 */  daddu      $2, $0, $0
    /* 3CA718 004CA718 0800E003 */  jr         $31
    /* 3CA71C 004CA71C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ca700, 0x20
