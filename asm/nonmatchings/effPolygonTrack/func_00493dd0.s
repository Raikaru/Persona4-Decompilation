.section .text
.set noat
.set noreorder
glabel func_00493dd0
    /* 393DD0 00493DD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 393DD4 00493DD4 0000BFFF */  sd         $31, 0x0($29)
    /* 393DD8 00493DD8 3000848C */  lw         $4, 0x30($4)
    /* 393DDC 00493DDC 844B120C */  jal        func_00492e10
    /* 393DE0 00493DE0 00000000 */   nop
    /* 393DE4 00493DE4 0000BFDF */  ld         $31, 0x0($29)
    /* 393DE8 00493DE8 1000BD27 */  addiu      $29, $29, 0x10
    /* 393DEC 00493DEC 0800E003 */  jr         $31
    /* 393DF0 00493DF0 00000000 */   nop
    /* 393DF4 00493DF4 00000000 */  nop
    /* 393DF8 00493DF8 00000000 */  nop
    /* 393DFC 00493DFC 00000000 */  nop
.size func_00493dd0, 0x30
