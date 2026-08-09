.section .text
.set noat
.set noreorder
glabel func_004f86c8
    /* 3F86C8 004F86C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F86CC 004F86CC 0000BFFF */  sd         $31, 0x0($29)
    /* 3F86D0 004F86D0 08C6130C */  jal        func_004f1820
    /* 3F86D4 004F86D4 00000000 */   nop
    /* 3F86D8 004F86D8 FFFF0324 */  addiu      $3, $0, -0x1
    /* 3F86DC 004F86DC 0000BFDF */  ld         $31, 0x0($29)
    /* 3F86E0 004F86E0 0A180200 */  movz       $3, $0, $2
    /* 3F86E4 004F86E4 2D106000 */  daddu      $2, $3, $0
    /* 3F86E8 004F86E8 0800E003 */  jr         $31
    /* 3F86EC 004F86EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f86c8, 0x28
