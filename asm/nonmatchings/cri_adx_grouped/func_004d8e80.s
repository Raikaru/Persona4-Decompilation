.section .text
.set noat
.set noreorder
glabel func_004d8e80
    /* 3D8E80 004D8E80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8E84 004D8E84 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8E88 004D8E88 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8E8C 004D8E8C 3AFC1208 */  j          func_004bf0e8
    /* 3D8E90 004D8E90 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8E94 004D8E94 00000000 */  nop
.size func_004d8e80, 0x18
