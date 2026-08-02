.section .text
.set noat
.set noreorder
glabel func_00493da0
    /* 393DA0 00493DA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 393DA4 00493DA4 0000BFFF */  sd         $31, 0x0($29)
    /* 393DA8 00493DA8 3000848C */  lw         $4, 0x30($4)
    /* 393DAC 00493DAC 744B120C */  jal        func_00492dd0
    /* 393DB0 00493DB0 00000000 */   nop
    /* 393DB4 00493DB4 0000BFDF */  ld         $31, 0x0($29)
    /* 393DB8 00493DB8 1000BD27 */  addiu      $29, $29, 0x10
    /* 393DBC 00493DBC 0800E003 */  jr         $31
    /* 393DC0 00493DC0 00000000 */   nop
    /* 393DC4 00493DC4 00000000 */  nop
    /* 393DC8 00493DC8 00000000 */  nop
    /* 393DCC 00493DCC 00000000 */  nop
.size func_00493da0, 0x30
