.section .text
.set noat
.set noreorder
glabel func_00517da8
    /* 417DA8 00517DA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 417DAC 00517DAC 0000BFFF */  sd         $31, 0x0($29)
    /* 417DB0 00517DB0 0000BFDF */  ld         $31, 0x0($29)
    /* 417DB4 00517DB4 88C11308 */  j          func_004f0620
    /* 417DB8 00517DB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 417DBC 00517DBC 00000000 */  nop
.size func_00517da8, 0x18
