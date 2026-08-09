.section .text
.set noat
.set noreorder
glabel func_004ed480
    /* 3ED480 004ED480 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED484 004ED484 0000BFFF */  sd         $31, 0x0($29)
    /* 3ED488 004ED488 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED48C 004ED48C F8C11308 */  j          func_004f07e0
    /* 3ED490 004ED490 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED494 004ED494 00000000 */  nop
.size func_004ed480, 0x18
