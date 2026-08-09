.section .text
.set noat
.set noreorder
glabel func_0042a920
    /* 32A920 0042A920 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32A924 0042A924 0000BFFF */  sd         $31, 0x0($29)
    /* 32A928 0042A928 CCA8100C */  jal        func_0042a330
    /* 32A92C 0042A92C 00000000 */   nop
    /* 32A930 0042A930 0000BFDF */  ld         $31, 0x0($29)
    /* 32A934 0042A934 0800E003 */  jr         $31
    /* 32A938 0042A938 1000BD27 */   addiu     $29, $29, 0x10
    /* 32A93C 0042A93C 00000000 */  nop
.size func_0042a920, 0x20
