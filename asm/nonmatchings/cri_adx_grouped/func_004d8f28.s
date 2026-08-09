.section .text
.set noat
.set noreorder
glabel func_004d8f28
    /* 3D8F28 004D8F28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8F2C 004D8F2C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8F30 004D8F30 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8F34 004D8F34 84FC1208 */  j          func_004bf210
    /* 3D8F38 004D8F38 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8F3C 004D8F3C 00000000 */  nop
.size func_004d8f28, 0x18
