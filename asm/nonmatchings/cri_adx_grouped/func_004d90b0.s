.section .text
.set noat
.set noreorder
glabel func_004d90b0
    /* 3D90B0 004D90B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D90B4 004D90B4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D90B8 004D90B8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D90BC 004D90BC C6FD1208 */  j          func_004bf718
    /* 3D90C0 004D90C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D90C4 004D90C4 00000000 */  nop
.size func_004d90b0, 0x18
