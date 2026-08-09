.section .text
.set noat
.set noreorder
glabel func_004d8e50
    /* 3D8E50 004D8E50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8E54 004D8E54 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8E58 004D8E58 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8E5C 004D8E5C 38FC1208 */  j          func_004bf0e0
    /* 3D8E60 004D8E60 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8E64 004D8E64 00000000 */  nop
.size func_004d8e50, 0x18
