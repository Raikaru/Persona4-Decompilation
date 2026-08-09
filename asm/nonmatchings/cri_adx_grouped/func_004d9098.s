.section .text
.set noat
.set noreorder
glabel func_004d9098
    /* 3D9098 004D9098 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D909C 004D909C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D90A0 004D90A0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D90A4 004D90A4 AAFD1208 */  j          func_004bf6a8
    /* 3D90A8 004D90A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D90AC 004D90AC 00000000 */  nop
.size func_004d9098, 0x18
