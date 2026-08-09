.section .text
.set noat
.set noreorder
glabel func_004f8558
    /* 3F8558 004F8558 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F855C 004F855C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F8560 004F8560 0000BFDF */  ld         $31, 0x0($29)
    /* 3F8564 004F8564 02C91308 */  j          func_004f2408
    /* 3F8568 004F8568 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F856C 004F856C 00000000 */  nop
.size func_004f8558, 0x18
