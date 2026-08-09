.section .text
.set noat
.set noreorder
glabel func_0051a6d0
    /* 41A6D0 0051A6D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41A6D4 0051A6D4 0000BFFF */  sd         $31, 0x0($29)
    /* 41A6D8 0051A6D8 2A1C140C */  jal        func_005070a8
    /* 41A6DC 0051A6DC 00000000 */   nop
    /* 41A6E0 0051A6E0 0000BFDF */  ld         $31, 0x0($29)
    /* 41A6E4 0051A6E4 2D100000 */  daddu      $2, $0, $0
    /* 41A6E8 0051A6E8 0800E003 */  jr         $31
    /* 41A6EC 0051A6EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0051a6d0, 0x20
