.section .text
.set noat
.set noreorder
glabel func_004cb4c8
    /* 3CB4C8 004CB4C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB4CC 004CB4CC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB4D0 004CB4D0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB4D4 004CB4D4 32C41308 */  j          func_004f10c8
    /* 3CB4D8 004CB4D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB4DC 004CB4DC 00000000 */  nop
.size func_004cb4c8, 0x18
