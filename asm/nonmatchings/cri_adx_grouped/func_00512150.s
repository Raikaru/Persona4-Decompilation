.section .text
.set noat
.set noreorder
glabel func_00512150
    /* 412150 00512150 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 412154 00512154 0000BFFF */  sd         $31, 0x0($29)
    /* 412158 00512158 0000BFDF */  ld         $31, 0x0($29)
    /* 41215C 0051215C 3A471308 */  j          func_004d1ce8
    /* 412160 00512160 1000BD27 */   addiu     $29, $29, 0x10
    /* 412164 00512164 00000000 */  nop
.size func_00512150, 0x18
