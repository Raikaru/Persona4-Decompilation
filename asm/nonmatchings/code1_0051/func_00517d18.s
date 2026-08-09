.section .text
.set noat
.set noreorder
glabel func_00517d18
    /* 417D18 00517D18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417D1C 00517D1C 0000BFFF */  sd         $31, 0x0($29)
    /* 417D20 00517D20 0000BFDF */  ld         $31, 0x0($29)
    /* 417D24 00517D24 C6B71308 */  j          func_004edf18
    /* 417D28 00517D28 1000BD27 */   addiu     $29, $29, 0x10
    /* 417D2C 00517D2C 00000000 */  nop
.size func_00517d18, 0x18
