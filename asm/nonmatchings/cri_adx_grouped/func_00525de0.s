.section .text
.set noat
.set noreorder
glabel func_00525de0
    /* 425DE0 00525DE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 425DE4 00525DE4 0000BFFF */  sd         $31, 0x0($29)
    /* 425DE8 00525DE8 0000BFDF */  ld         $31, 0x0($29)
    /* 425DEC 00525DEC 7E971408 */  j          func_00525df8
    /* 425DF0 00525DF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 425DF4 00525DF4 00000000 */  nop
.size func_00525de0, 0x18
