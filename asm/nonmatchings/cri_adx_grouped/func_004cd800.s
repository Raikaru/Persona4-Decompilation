.section .text
.set noat
.set noreorder
glabel func_004cd800
    /* 3CD800 004CD800 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD804 004CD804 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD808 004CD808 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD80C 004CD80C BAB31308 */  j          func_004ecee8
    /* 3CD810 004CD810 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD814 004CD814 00000000 */  nop
.size func_004cd800, 0x18
