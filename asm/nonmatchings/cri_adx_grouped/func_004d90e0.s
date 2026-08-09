.section .text
.set noat
.set noreorder
glabel func_004d90e0
    /* 3D90E0 004D90E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D90E4 004D90E4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D90E8 004D90E8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D90EC 004D90EC 4CFE1208 */  j          func_004bf930
    /* 3D90F0 004D90F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D90F4 004D90F4 00000000 */  nop
.size func_004d90e0, 0x18
