.section .text
.set noat
.set noreorder
glabel func_004d8da8
    /* 3D8DA8 004D8DA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8DAC 004D8DAC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8DB0 004D8DB0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8DB4 004D8DB4 4EFB1208 */  j          func_004bed38
    /* 3D8DB8 004D8DB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8DBC 004D8DBC 00000000 */  nop
.size func_004d8da8, 0x18
