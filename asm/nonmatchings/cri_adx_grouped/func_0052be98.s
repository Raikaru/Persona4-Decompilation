.section .text
.set noat
.set noreorder
glabel func_0052be98
    /* 42BE98 0052BE98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BE9C 0052BE9C 0000BFFF */  sd         $31, 0x0($29)
    /* 42BEA0 0052BEA0 0000BFDF */  ld         $31, 0x0($29)
    /* 42BEA4 0052BEA4 E2E61308 */  j          func_004f9b88
    /* 42BEA8 0052BEA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 42BEAC 0052BEAC 00000000 */  nop
.size func_0052be98, 0x18
