.section .text
.set noat
.set noreorder
glabel func_004ccb38
    /* 3CCB38 004CCB38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCB3C 004CCB3C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CCB40 004CCB40 0000BFDF */  ld         $31, 0x0($29)
    /* 3CCB44 004CCB44 84321308 */  j          func_004cca10
    /* 3CCB48 004CCB48 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCB4C 004CCB4C 00000000 */  nop
.size func_004ccb38, 0x18
