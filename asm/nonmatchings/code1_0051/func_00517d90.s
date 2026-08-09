.section .text
.set noat
.set noreorder
glabel func_00517d90
    /* 417D90 00517D90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417D94 00517D94 0000BFFF */  sd         $31, 0x0($29)
    /* 417D98 00517D98 0000BFDF */  ld         $31, 0x0($29)
    /* 417D9C 00517D9C 82C11308 */  j          func_004f0608
    /* 417DA0 00517DA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 417DA4 00517DA4 00000000 */  nop
.size func_00517d90, 0x18
