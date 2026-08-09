.section .text
.set noat
.set noreorder
glabel func_004cd7e8
    /* 3CD7E8 004CD7E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD7EC 004CD7EC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD7F0 004CD7F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD7F4 004CD7F4 AEB31308 */  j          func_004eceb8
    /* 3CD7F8 004CD7F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD7FC 004CD7FC 00000000 */  nop
.size func_004cd7e8, 0x18
