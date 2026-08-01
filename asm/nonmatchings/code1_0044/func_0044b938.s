.section .text
.set noat
.set noreorder
glabel func_0044b938
    /* 34B938 0044B938 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B93C 0044B93C 0000BFFF */  sd         $31, 0x0($29)
    /* 34B940 0044B940 0000BFDF */  ld         $31, 0x0($29)
    /* 34B944 0044B944 48241108 */  j          func_00449120
    /* 34B948 0044B948 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B94C 0044B94C 00000000 */  nop
.size func_0044b938, 0x18
