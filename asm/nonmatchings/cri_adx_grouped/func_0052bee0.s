.section .text
.set noat
.set noreorder
glabel func_0052bee0
    /* 42BEE0 0052BEE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BEE4 0052BEE4 0000BFFF */  sd         $31, 0x0($29)
    /* 42BEE8 0052BEE8 0000BFDF */  ld         $31, 0x0($29)
    /* 42BEEC 0052BEEC 7EB31408 */  j          func_0052cdf8
    /* 42BEF0 0052BEF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 42BEF4 0052BEF4 00000000 */  nop
.size func_0052bee0, 0x18
