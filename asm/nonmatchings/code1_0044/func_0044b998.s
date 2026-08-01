.section .text
.set noat
.set noreorder
glabel func_0044b998
    /* 34B998 0044B998 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B99C 0044B99C 0000BFFF */  sd         $31, 0x0($29)
    /* 34B9A0 0044B9A0 0000BFDF */  ld         $31, 0x0($29)
    /* 34B9A4 0044B9A4 34291108 */  j          func_0044a4d0
    /* 34B9A8 0044B9A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B9AC 0044B9AC 00000000 */  nop
.size func_0044b998, 0x18
