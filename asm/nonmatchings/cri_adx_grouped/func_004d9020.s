.section .text
.set noat
.set noreorder
glabel func_004d9020
    /* 3D9020 004D9020 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9024 004D9024 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9028 004D9028 0000BFDF */  ld         $31, 0x0($29)
    /* 3D902C 004D902C 26FD1208 */  j          func_004bf498
    /* 3D9030 004D9030 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D9034 004D9034 00000000 */  nop
.size func_004d9020, 0x18
