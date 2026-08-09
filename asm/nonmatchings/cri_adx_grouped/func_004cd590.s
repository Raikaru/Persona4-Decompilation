.section .text
.set noat
.set noreorder
glabel func_004cd590
    /* 3CD590 004CD590 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD594 004CD594 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD598 004CD598 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD59C 004CD59C 1AB01308 */  j          func_004ec068
    /* 3CD5A0 004CD5A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD5A4 004CD5A4 00000000 */  nop
.size func_004cd590, 0x18
