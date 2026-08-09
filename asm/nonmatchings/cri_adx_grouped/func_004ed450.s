.section .text
.set noat
.set noreorder
glabel func_004ed450
    /* 3ED450 004ED450 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED454 004ED454 0000BFFF */  sd         $31, 0x0($29)
    /* 3ED458 004ED458 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED45C 004ED45C 82C11308 */  j          func_004f0608
    /* 3ED460 004ED460 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED464 004ED464 00000000 */  nop
.size func_004ed450, 0x18
