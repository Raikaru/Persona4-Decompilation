.section .text
.set noat
.set noreorder
glabel func_004b10c0
    /* 3B10C0 004B10C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3B10C4 004B10C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3B10C8 004B10C8 5C00848C */  lw         $4, 0x5C($4)
    /* 3B10CC 004B10CC 844B120C */  jal        func_00492e10
    /* 3B10D0 004B10D0 00000000 */   nop
    /* 3B10D4 004B10D4 0000BFDF */  ld         $31, 0x0($29)
    /* 3B10D8 004B10D8 1000BD27 */  addiu      $29, $29, 0x10
    /* 3B10DC 004B10DC 0800E003 */  jr         $31
    /* 3B10E0 004B10E0 00000000 */   nop
    /* 3B10E4 004B10E4 00000000 */  nop
    /* 3B10E8 004B10E8 00000000 */  nop
    /* 3B10EC 004B10EC 00000000 */  nop
.size func_004b10c0, 0x30
