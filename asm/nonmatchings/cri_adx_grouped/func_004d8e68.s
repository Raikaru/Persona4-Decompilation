.section .text
.set noat
.set noreorder
glabel func_004d8e68
    /* 3D8E68 004D8E68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8E6C 004D8E6C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8E70 004D8E70 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8E74 004D8E74 F4FB1208 */  j          func_004befd0
    /* 3D8E78 004D8E78 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8E7C 004D8E7C 00000000 */  nop
.size func_004d8e68, 0x18
