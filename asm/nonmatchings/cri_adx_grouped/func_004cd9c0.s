.section .text
.set noat
.set noreorder
glabel func_004cd9c0
    /* 3CD9C0 004CD9C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD9C4 004CD9C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD9C8 004CD9C8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD9CC 004CD9CC 040D1308 */  j          func_004c3410
    /* 3CD9D0 004CD9D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD9D4 004CD9D4 00000000 */  nop
.size func_004cd9c0, 0x18
