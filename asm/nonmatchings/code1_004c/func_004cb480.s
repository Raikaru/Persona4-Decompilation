.section .text
.set noat
.set noreorder
glabel func_004cb480
    /* 3CB480 004CB480 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB484 004CB484 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB488 004CB488 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB48C 004CB48C 20C41308 */  j          func_004f1080
    /* 3CB490 004CB490 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB494 004CB494 00000000 */  nop
.size func_004cb480, 0x18
