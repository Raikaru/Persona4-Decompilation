.section .text
.set noat
.set noreorder
glabel func_004cd7d0
    /* 3CD7D0 004CD7D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD7D4 004CD7D4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD7D8 004CD7D8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD7DC 004CD7DC 9CB31308 */  j          func_004ece70
    /* 3CD7E0 004CD7E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD7E4 004CD7E4 00000000 */  nop
.size func_004cd7d0, 0x18
