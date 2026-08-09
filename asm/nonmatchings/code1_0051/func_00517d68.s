.section .text
.set noat
.set noreorder
glabel func_00517d68
    /* 417D68 00517D68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417D6C 00517D6C 0000BFFF */  sd         $31, 0x0($29)
    /* 417D70 00517D70 0000BFDF */  ld         $31, 0x0($29)
    /* 417D74 00517D74 6E5B1408 */  j          func_00516db8
    /* 417D78 00517D78 1000BD27 */   addiu     $29, $29, 0x10
    /* 417D7C 00517D7C 00000000 */  nop
.size func_00517d68, 0x18
