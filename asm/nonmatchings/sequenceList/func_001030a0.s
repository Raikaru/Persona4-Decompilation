.section .text
.set noat
.set noreorder
glabel func_001030a0
    /* 30A0 001030A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 30A4 001030A4 0000BFFF */  sd         $31, 0x0($29)
    /* 30A8 001030A8 A8B00A0C */  jal        func_002ac2a0
    /* 30AC 001030AC 00000000 */   nop
    /* 30B0 001030B0 0000BFDF */  ld         $31, 0x0($29)
    /* 30B4 001030B4 1000BD27 */  addiu      $29, $29, 0x10
    /* 30B8 001030B8 0800E003 */  jr         $31
    /* 30BC 001030BC 00000000 */   nop
.size func_001030a0, 0x20
