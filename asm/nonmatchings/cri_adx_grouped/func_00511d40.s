.section .text
.set noat
.set noreorder
glabel func_00511d40
    /* 411D40 00511D40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411D44 00511D44 0000BFFF */  sd         $31, 0x0($29)
    /* 411D48 00511D48 4846140C */  jal        func_00511920
    /* 411D4C 00511D4C 00000000 */   nop
    /* 411D50 00511D50 0000BFDF */  ld         $31, 0x0($29)
    /* 411D54 00511D54 2D100000 */  daddu      $2, $0, $0
    /* 411D58 00511D58 0800E003 */  jr         $31
    /* 411D5C 00511D5C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511d40, 0x20
