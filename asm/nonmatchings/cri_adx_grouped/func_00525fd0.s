.section .text
.set noat
.set noreorder
glabel func_00525fd0
    /* 425FD0 00525FD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 425FD4 00525FD4 0000BFFF */  sd         $31, 0x0($29)
    /* 425FD8 00525FD8 3A98140C */  jal        func_005260e8
    /* 425FDC 00525FDC 00000000 */   nop
    /* 425FE0 00525FE0 0000BFDF */  ld         $31, 0x0($29)
    /* 425FE4 00525FE4 2D100000 */  daddu      $2, $0, $0
    /* 425FE8 00525FE8 0800E003 */  jr         $31
    /* 425FEC 00525FEC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00525fd0, 0x20
