.section .text
.set noat
.set noreorder
glabel func_0044b980
    /* 34B980 0044B980 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B984 0044B984 0000BFFF */  sd         $31, 0x0($29)
    /* 34B988 0044B988 0000BFDF */  ld         $31, 0x0($29)
    /* 34B98C 0044B98C 4E261108 */  j          func_00449938
    /* 34B990 0044B990 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B994 0044B994 00000000 */  nop
.size func_0044b980, 0x18
