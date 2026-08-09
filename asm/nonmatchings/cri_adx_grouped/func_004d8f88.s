.section .text
.set noat
.set noreorder
glabel func_004d8f88
    /* 3D8F88 004D8F88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8F8C 004D8F8C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8F90 004D8F90 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8F94 004D8F94 8CFC1208 */  j          func_004bf230
    /* 3D8F98 004D8F98 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8F9C 004D8F9C 00000000 */  nop
.size func_004d8f88, 0x18
