.section .text
.set noat
.set noreorder
glabel func_004d8e20
    /* 3D8E20 004D8E20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8E24 004D8E24 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8E28 004D8E28 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8E2C 004D8E2C B0FB1208 */  j          func_004beec0
    /* 3D8E30 004D8E30 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8E34 004D8E34 00000000 */  nop
.size func_004d8e20, 0x18
