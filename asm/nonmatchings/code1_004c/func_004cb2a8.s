.section .text
.set noat
.set noreorder
glabel func_004cb2a8
    /* 3CB2A8 004CB2A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB2AC 004CB2AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB2B0 004CB2B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB2B4 004CB2B4 F0A41308 */  j          func_004e93c0
    /* 3CB2B8 004CB2B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB2BC 004CB2BC 00000000 */  nop
.size func_004cb2a8, 0x18
