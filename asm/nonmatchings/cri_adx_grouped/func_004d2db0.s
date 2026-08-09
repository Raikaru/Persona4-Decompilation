.section .text
.set noat
.set noreorder
glabel func_004d2db0
    /* 3D2DB0 004D2DB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2DB4 004D2DB4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D2DB8 004D2DB8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D2DBC 004D2DBC D8881308 */  j          func_004e2360
    /* 3D2DC0 004D2DC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D2DC4 004D2DC4 00000000 */  nop
.size func_004d2db0, 0x18
