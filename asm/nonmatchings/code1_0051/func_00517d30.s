.section .text
.set noat
.set noreorder
glabel func_00517d30
    /* 417D30 00517D30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417D34 00517D34 0000BFFF */  sd         $31, 0x0($29)
    /* 417D38 00517D38 0000BFDF */  ld         $31, 0x0($29)
    /* 417D3C 00517D3C E6B71308 */  j          func_004edf98
    /* 417D40 00517D40 1000BD27 */   addiu     $29, $29, 0x10
    /* 417D44 00517D44 00000000 */  nop
.size func_00517d30, 0x18
