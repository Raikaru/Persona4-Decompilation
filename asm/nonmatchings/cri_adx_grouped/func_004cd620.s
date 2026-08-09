.section .text
.set noat
.set noreorder
glabel func_004cd620
    /* 3CD620 004CD620 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD624 004CD624 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD628 004CD628 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD62C 004CD62C 9EB01308 */  j          func_004ec278
    /* 3CD630 004CD630 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD634 004CD634 00000000 */  nop
.size func_004cd620, 0x18
