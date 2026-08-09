.section .text
.set noat
.set noreorder
glabel func_004d8f10
    /* 3D8F10 004D8F10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8F14 004D8F14 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8F18 004D8F18 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8F1C 004D8F1C 82FC1208 */  j          func_004bf208
    /* 3D8F20 004D8F20 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8F24 004D8F24 00000000 */  nop
.size func_004d8f10, 0x18
