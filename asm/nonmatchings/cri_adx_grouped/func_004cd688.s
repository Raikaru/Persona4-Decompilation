.section .text
.set noat
.set noreorder
glabel func_004cd688
    /* 3CD688 004CD688 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD68C 004CD68C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD690 004CD690 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD694 004CD694 FAB01308 */  j          func_004ec3e8
    /* 3CD698 004CD698 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD69C 004CD69C 00000000 */  nop
.size func_004cd688, 0x18
