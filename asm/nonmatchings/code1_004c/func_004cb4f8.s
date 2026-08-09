.section .text
.set noat
.set noreorder
glabel func_004cb4f8
    /* 3CB4F8 004CB4F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB4FC 004CB4FC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB500 004CB500 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB504 004CB504 3EC41308 */  j          func_004f10f8
    /* 3CB508 004CB508 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB50C 004CB50C 00000000 */  nop
.size func_004cb4f8, 0x18
