.section .text
.set noat
.set noreorder
glabel func_004cd650
    /* 3CD650 004CD650 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD654 004CD654 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD658 004CD658 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD65C 004CD65C 00AF1308 */  j          func_004ebc00
    /* 3CD660 004CD660 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD664 004CD664 00000000 */  nop
.size func_004cd650, 0x18
