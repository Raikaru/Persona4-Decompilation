.section .text
.set noat
.set noreorder
glabel func_004cd6d8
    /* 3CD6D8 004CD6D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD6DC 004CD6DC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD6E0 004CD6E0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD6E4 004CD6E4 1CB21308 */  j          func_004ec870
    /* 3CD6E8 004CD6E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD6EC 004CD6EC 00000000 */  nop
.size func_004cd6d8, 0x18
