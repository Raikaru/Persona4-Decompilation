.section .text
.set noat
.set noreorder
glabel func_004d8fb8
    /* 3D8FB8 004D8FB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8FBC 004D8FBC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8FC0 004D8FC0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8FC4 004D8FC4 90FC1208 */  j          func_004bf240
    /* 3D8FC8 004D8FC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8FCC 004D8FCC 00000000 */  nop
.size func_004d8fb8, 0x18
