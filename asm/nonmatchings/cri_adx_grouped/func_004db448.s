.section .text
.set noat
.set noreorder
glabel func_004db448
    /* 3DB448 004DB448 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DB44C 004DB44C 0000BFFF */  sd         $31, 0x0($29)
    /* 3DB450 004DB450 0000BFDF */  ld         $31, 0x0($29)
    /* 3DB454 004DB454 AC781308 */  j          func_004de2b0
    /* 3DB458 004DB458 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DB45C 004DB45C 00000000 */  nop
.size func_004db448, 0x18
