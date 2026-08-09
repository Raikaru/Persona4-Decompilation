.section .text
.set noat
.set noreorder
glabel func_004cc200
    /* 3CC200 004CC200 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CC204 004CC204 0000BFFF */  sd         $31, 0x0($29)
    /* 3CC208 004CC208 0000BFDF */  ld         $31, 0x0($29)
    /* 3CC20C 004CC20C A0C31308 */  j          func_004f0e80
    /* 3CC210 004CC210 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CC214 004CC214 00000000 */  nop
.size func_004cc200, 0x18
