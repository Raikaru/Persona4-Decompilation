.section .text
.set noat
.set noreorder
glabel func_004cb4e0
    /* 3CB4E0 004CB4E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB4E4 004CB4E4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB4E8 004CB4E8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB4EC 004CB4EC 38C41308 */  j          func_004f10e0
    /* 3CB4F0 004CB4F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB4F4 004CB4F4 00000000 */  nop
.size func_004cb4e0, 0x18
