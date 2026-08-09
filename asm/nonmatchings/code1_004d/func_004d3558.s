.section .text
.set noat
.set noreorder
glabel func_004d3558
    /* 3D3558 004D3558 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D355C 004D355C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3560 004D3560 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3564 004D3564 20991308 */  j          func_004e6480
    /* 3D3568 004D3568 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D356C 004D356C 00000000 */  nop
.size func_004d3558, 0x18
