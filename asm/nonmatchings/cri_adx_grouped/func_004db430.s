.section .text
.set noat
.set noreorder
glabel func_004db430
    /* 3DB430 004DB430 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DB434 004DB434 0000BFFF */  sd         $31, 0x0($29)
    /* 3DB438 004DB438 0000BFDF */  ld         $31, 0x0($29)
    /* 3DB43C 004DB43C AA781308 */  j          func_004de2a8
    /* 3DB440 004DB440 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DB444 004DB444 00000000 */  nop
.size func_004db430, 0x18
