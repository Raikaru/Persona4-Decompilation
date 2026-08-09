.section .text
.set noat
.set noreorder
glabel func_004cd878
    /* 3CD878 004CD878 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD87C 004CD87C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD880 004CD880 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD884 004CD884 2EB41308 */  j          func_004ed0b8
    /* 3CD888 004CD888 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD88C 004CD88C 00000000 */  nop
.size func_004cd878, 0x18
