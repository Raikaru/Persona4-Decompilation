.section .text
.set noat
.set noreorder
glabel func_004d9068
    /* 3D9068 004D9068 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D906C 004D906C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9070 004D9070 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9074 004D9074 78FD1208 */  j          func_004bf5e0
    /* 3D9078 004D9078 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D907C 004D907C 00000000 */  nop
.size func_004d9068, 0x18
