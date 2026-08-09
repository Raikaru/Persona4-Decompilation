.section .text
.set noat
.set noreorder
glabel func_004d36e8
    /* 3D36E8 004D36E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D36EC 004D36EC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D36F0 004D36F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D36F4 004D36F4 6A361308 */  j          func_004cd9a8
    /* 3D36F8 004D36F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D36FC 004D36FC 00000000 */  nop
.size func_004d36e8, 0x18
