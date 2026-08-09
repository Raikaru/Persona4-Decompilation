.section .text
.set noat
.set noreorder
glabel func_004d62a8
    /* 3D62A8 004D62A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D62AC 004D62AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D62B0 004D62B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D62B4 004D62B4 4C361308 */  j          func_004cd930
    /* 3D62B8 004D62B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D62BC 004D62BC 00000000 */  nop
.size func_004d62a8, 0x18
