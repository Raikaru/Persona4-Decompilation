.section .text
.set noat
.set noreorder
glabel func_004cb498
    /* 3CB498 004CB498 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB49C 004CB49C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB4A0 004CB4A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB4A4 004CB4A4 26C41308 */  j          func_004f1098
    /* 3CB4A8 004CB4A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB4AC 004CB4AC 00000000 */  nop
.size func_004cb498, 0x18
