.section .text
.set noat
.set noreorder
glabel func_004d3f90
    /* 3D3F90 004D3F90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3F94 004D3F94 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3F98 004D3F98 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3F9C 004D3F9C C24F1308 */  j          func_004d3f08
    /* 3D3FA0 004D3FA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3FA4 004D3FA4 00000000 */  nop
.size func_004d3f90, 0x18
