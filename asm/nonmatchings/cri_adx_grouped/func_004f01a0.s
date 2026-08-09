.section .text
.set noat
.set noreorder
glabel func_004f01a0
    /* 3F01A0 004F01A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F01A4 004F01A4 0000BFFF */  sd         $31, 0x0($29)
    /* 3F01A8 004F01A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F01AC 004F01AC 6A961308 */  j          func_004e59a8
    /* 3F01B0 004F01B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F01B4 004F01B4 00000000 */  nop
.size func_004f01a0, 0x18
