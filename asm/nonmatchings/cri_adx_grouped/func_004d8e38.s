.section .text
.set noat
.set noreorder
glabel func_004d8e38
    /* 3D8E38 004D8E38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8E3C 004D8E3C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8E40 004D8E40 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8E44 004D8E44 B2FB1208 */  j          func_004beec8
    /* 3D8E48 004D8E48 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8E4C 004D8E4C 00000000 */  nop
.size func_004d8e38, 0x18
