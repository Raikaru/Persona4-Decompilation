.section .text
.set noat
.set noreorder
glabel func_004d8f70
    /* 3D8F70 004D8F70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8F74 004D8F74 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8F78 004D8F78 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8F7C 004D8F7C 8AFC1208 */  j          func_004bf228
    /* 3D8F80 004D8F80 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8F84 004D8F84 00000000 */  nop
.size func_004d8f70, 0x18
