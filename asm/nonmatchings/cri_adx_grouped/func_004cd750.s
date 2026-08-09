.section .text
.set noat
.set noreorder
glabel func_004cd750
    /* 3CD750 004CD750 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD754 004CD754 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD758 004CD758 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD75C 004CD75C D0B21308 */  j          func_004ecb40
    /* 3CD760 004CD760 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD764 004CD764 00000000 */  nop
.size func_004cd750, 0x18
