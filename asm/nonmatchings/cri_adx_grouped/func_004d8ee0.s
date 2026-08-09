.section .text
.set noat
.set noreorder
glabel func_004d8ee0
    /* 3D8EE0 004D8EE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8EE4 004D8EE4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8EE8 004D8EE8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8EEC 004D8EEC 7EFC1208 */  j          func_004bf1f8
    /* 3D8EF0 004D8EF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8EF4 004D8EF4 00000000 */  nop
.size func_004d8ee0, 0x18
