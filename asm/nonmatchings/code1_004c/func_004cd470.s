.section .text
.set noat
.set noreorder
glabel func_004cd470
    /* 3CD470 004CD470 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD474 004CD474 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD478 004CD478 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD47C 004CD47C C6AC1308 */  j          func_004eb318
    /* 3CD480 004CD480 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD484 004CD484 00000000 */  nop
.size func_004cd470, 0x18
