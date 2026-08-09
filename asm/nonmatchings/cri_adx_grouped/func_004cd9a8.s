.section .text
.set noat
.set noreorder
glabel func_004cd9a8
    /* 3CD9A8 004CD9A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD9AC 004CD9AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD9B0 004CD9B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD9B4 004CD9B4 000D1308 */  j          func_004c3400
    /* 3CD9B8 004CD9B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD9BC 004CD9BC 00000000 */  nop
.size func_004cd9a8, 0x18
