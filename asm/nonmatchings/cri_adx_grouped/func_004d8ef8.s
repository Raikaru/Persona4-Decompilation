.section .text
.set noat
.set noreorder
glabel func_004d8ef8
    /* 3D8EF8 004D8EF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8EFC 004D8EFC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8F00 004D8F00 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8F04 004D8F04 80FC1208 */  j          func_004bf200
    /* 3D8F08 004D8F08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8F0C 004D8F0C 00000000 */  nop
.size func_004d8ef8, 0x18
