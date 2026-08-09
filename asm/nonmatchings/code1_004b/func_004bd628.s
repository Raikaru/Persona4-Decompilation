.section .text
.set noat
.set noreorder
glabel func_004bd628
    /* 3BD628 004BD628 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BD62C 004BD62C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BD630 004BD630 0000BFDF */  ld         $31, 0x0($29)
    /* 3BD634 004BD634 8EC11308 */  j          func_004f0638
    /* 3BD638 004BD638 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BD63C 004BD63C 00000000 */  nop
.size func_004bd628, 0x18
