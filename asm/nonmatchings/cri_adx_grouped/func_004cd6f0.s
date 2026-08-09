.section .text
.set noat
.set noreorder
glabel func_004cd6f0
    /* 3CD6F0 004CD6F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD6F4 004CD6F4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD6F8 004CD6F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD6FC 004CD6FC 2EB21308 */  j          func_004ec8b8
    /* 3CD700 004CD700 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CD704 004CD704 00000000 */  nop
.size func_004cd6f0, 0x18
