.section .text
.set noat
.set noreorder
glabel func_004d8f58
    /* 3D8F58 004D8F58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8F5C 004D8F5C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8F60 004D8F60 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8F64 004D8F64 88FC1208 */  j          func_004bf220
    /* 3D8F68 004D8F68 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8F6C 004D8F6C 00000000 */  nop
.size func_004d8f58, 0x18
