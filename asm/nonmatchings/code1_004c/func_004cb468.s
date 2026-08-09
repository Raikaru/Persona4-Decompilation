.section .text
.set noat
.set noreorder
glabel func_004cb468
    /* 3CB468 004CB468 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB46C 004CB46C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB470 004CB470 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB474 004CB474 1AC41308 */  j          func_004f1068
    /* 3CB478 004CB478 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB47C 004CB47C 00000000 */  nop
.size func_004cb468, 0x18
