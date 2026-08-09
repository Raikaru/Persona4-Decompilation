.section .text
.set noat
.set noreorder
glabel func_004d8d90
    /* 3D8D90 004D8D90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8D94 004D8D94 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8D98 004D8D98 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8D9C 004D8D9C FCFA1208 */  j          func_004bebf0
    /* 3D8DA0 004D8DA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8DA4 004D8DA4 00000000 */  nop
.size func_004d8d90, 0x18
