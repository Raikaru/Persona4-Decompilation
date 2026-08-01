.section .text
.set noat
.set noreorder
glabel func_0044b8d8
    /* 34B8D8 0044B8D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B8DC 0044B8DC 0000BFFF */  sd         $31, 0x0($29)
    /* 34B8E0 0044B8E0 0000BFDF */  ld         $31, 0x0($29)
    /* 34B8E4 0044B8E4 3C1C1108 */  j          func_004470f0
    /* 34B8E8 0044B8E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B8EC 0044B8EC 00000000 */  nop
.size func_0044b8d8, 0x18
