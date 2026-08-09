.section .text
.set noat
.set noreorder
glabel func_004d8f40
    /* 3D8F40 004D8F40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8F44 004D8F44 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8F48 004D8F48 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8F4C 004D8F4C 86FC1208 */  j          func_004bf218
    /* 3D8F50 004D8F50 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8F54 004D8F54 00000000 */  nop
.size func_004d8f40, 0x18
