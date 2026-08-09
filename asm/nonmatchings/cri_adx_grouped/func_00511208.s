.section .text
.set noat
.set noreorder
glabel func_00511208
    /* 411208 00511208 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41120C 0051120C 0000BFFF */  sd         $31, 0x0($29)
    /* 411210 00511210 0000BFDF */  ld         $31, 0x0($29)
    /* 411214 00511214 9EC41308 */  j          func_004f1278
    /* 411218 00511218 1000BD27 */   addiu     $29, $29, 0x10
    /* 41121C 0051121C 00000000 */  nop
.size func_00511208, 0x18
