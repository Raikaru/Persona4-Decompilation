.section .text
.set noat
.set noreorder
glabel func_004e7378
    /* 3E7378 004E7378 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E737C 004E737C 0000BFFF */  sd         $31, 0x0($29)
    /* 3E7380 004E7380 0000BFDF */  ld         $31, 0x0($29)
    /* 3E7384 004E7384 DC911308 */  j          func_004e4770
    /* 3E7388 004E7388 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E738C 004E738C 00000000 */  nop
.size func_004e7378, 0x18
