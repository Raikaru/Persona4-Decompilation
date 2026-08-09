.section .text
.set noat
.set noreorder
glabel func_004d8fd0
    /* 3D8FD0 004D8FD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8FD4 004D8FD4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8FD8 004D8FD8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8FDC 004D8FDC D4FC1208 */  j          func_004bf350
    /* 3D8FE0 004D8FE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8FE4 004D8FE4 00000000 */  nop
.size func_004d8fd0, 0x18
