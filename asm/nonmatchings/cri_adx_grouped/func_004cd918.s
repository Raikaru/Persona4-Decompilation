.section .text
.set noat
.set noreorder
glabel func_004cd918
    /* 3CD918 004CD918 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD91C 004CD91C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD920 004CD920 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD924 004CD924 78B21308 */  j          func_004ec9e0
    /* 3CD928 004CD928 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD92C 004CD92C 00000000 */  nop
.size func_004cd918, 0x18
