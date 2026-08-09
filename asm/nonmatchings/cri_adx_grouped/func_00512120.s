.section .text
.set noat
.set noreorder
glabel func_00512120
    /* 412120 00512120 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 412124 00512124 0000BFFF */  sd         $31, 0x0($29)
    /* 412128 00512128 0000BFDF */  ld         $31, 0x0($29)
    /* 41212C 0051212C 7A4C1308 */  j          func_004d31e8
    /* 412130 00512130 1000BD27 */   addiu     $29, $29, 0x10
    /* 412134 00512134 00000000 */  nop
.size func_00512120, 0x18
