.section .text
.set noat
.set noreorder
glabel func_004d3540
    /* 3D3540 004D3540 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3544 004D3544 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3548 004D3548 0000BFDF */  ld         $31, 0x0($29)
    /* 3D354C 004D354C 18991308 */  j          func_004e6460
    /* 3D3550 004D3550 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3554 004D3554 00000000 */  nop
.size func_004d3540, 0x18
