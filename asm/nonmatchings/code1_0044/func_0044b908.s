.section .text
.set noat
.set noreorder
glabel func_0044b908
    /* 34B908 0044B908 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B90C 0044B90C 0000BFFF */  sd         $31, 0x0($29)
    /* 34B910 0044B910 0000BFDF */  ld         $31, 0x0($29)
    /* 34B914 0044B914 401F1108 */  j          func_00447d00
    /* 34B918 0044B918 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B91C 0044B91C 00000000 */  nop
.size func_0044b908, 0x18
