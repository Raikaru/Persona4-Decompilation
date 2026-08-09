.section .text
.set noat
.set noreorder
glabel func_004cb4b0
    /* 3CB4B0 004CB4B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB4B4 004CB4B4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB4B8 004CB4B8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB4BC 004CB4BC 2CC41308 */  j          func_004f10b0
    /* 3CB4C0 004CB4C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB4C4 004CB4C4 00000000 */  nop
.size func_004cb4b0, 0x18
