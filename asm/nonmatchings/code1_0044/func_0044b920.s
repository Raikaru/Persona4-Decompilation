.section .text
.set noat
.set noreorder
glabel func_0044b920
    /* 34B920 0044B920 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B924 0044B924 0000BFFF */  sd         $31, 0x0($29)
    /* 34B928 0044B928 0000BFDF */  ld         $31, 0x0($29)
    /* 34B92C 0044B92C 44231108 */  j          func_00448d10
    /* 34B930 0044B930 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B934 0044B934 00000000 */  nop
.size func_0044b920, 0x18
