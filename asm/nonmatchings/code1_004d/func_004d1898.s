.section .text
.set noat
.set noreorder
glabel func_004d1898
    /* 3D1898 004D1898 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D189C 004D189C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D18A0 004D18A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D18A4 004D18A4 88C11308 */  j          func_004f0620
    /* 3D18A8 004D18A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D18AC 004D18AC 00000000 */  nop
.size func_004d1898, 0x18
