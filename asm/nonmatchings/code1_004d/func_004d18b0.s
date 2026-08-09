.section .text
.set noat
.set noreorder
glabel func_004d18b0
    /* 3D18B0 004D18B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D18B4 004D18B4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D18B8 004D18B8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D18BC 004D18BC 9EC41308 */  j          func_004f1278
    /* 3D18C0 004D18C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D18C4 004D18C4 00000000 */  nop
.size func_004d18b0, 0x18
