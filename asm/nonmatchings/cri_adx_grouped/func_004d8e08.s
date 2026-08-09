.section .text
.set noat
.set noreorder
glabel func_004d8e08
    /* 3D8E08 004D8E08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8E0C 004D8E0C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8E10 004D8E10 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8E14 004D8E14 AEFB1208 */  j          func_004beeb8
    /* 3D8E18 004D8E18 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8E1C 004D8E1C 00000000 */  nop
.size func_004d8e08, 0x18
