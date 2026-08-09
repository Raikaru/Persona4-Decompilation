.section .text
.set noat
.set noreorder
glabel func_004d90c8
    /* 3D90C8 004D90C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D90CC 004D90CC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D90D0 004D90D0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D90D4 004D90D4 D6FD1208 */  j          func_004bf758
    /* 3D90D8 004D90D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D90DC 004D90DC 00000000 */  nop
.size func_004d90c8, 0x18
