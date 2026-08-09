.section .text
.set noat
.set noreorder
glabel func_004d3738
    /* 3D3738 004D3738 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D373C 004D373C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3740 004D3740 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3744 004D3744 70361308 */  j          func_004cd9c0
    /* 3D3748 004D3748 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D374C 004D374C 00000000 */  nop
.size func_004d3738, 0x18
