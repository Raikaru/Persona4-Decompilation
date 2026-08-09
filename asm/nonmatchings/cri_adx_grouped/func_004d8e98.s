.section .text
.set noat
.set noreorder
glabel func_004d8e98
    /* 3D8E98 004D8E98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8E9C 004D8E9C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8EA0 004D8EA0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8EA4 004D8EA4 4EFC1208 */  j          func_004bf138
    /* 3D8EA8 004D8EA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8EAC 004D8EAC 00000000 */  nop
.size func_004d8e98, 0x18
