.section .text
.set noat
.set noreorder
glabel func_004af5e0
    /* 3AF5E0 004AF5E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AF5E4 004AF5E4 0000BFFF */  sd         $31, 0x0($29)
    /* 3AF5E8 004AF5E8 5800848C */  lw         $4, 0x58($4)
    /* 3AF5EC 004AF5EC 744B120C */  jal        func_00492dd0
    /* 3AF5F0 004AF5F0 00000000 */   nop
    /* 3AF5F4 004AF5F4 0000BFDF */  ld         $31, 0x0($29)
    /* 3AF5F8 004AF5F8 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AF5FC 004AF5FC 0800E003 */  jr         $31
    /* 3AF600 004AF600 00000000 */   nop
    /* 3AF604 004AF604 00000000 */  nop
    /* 3AF608 004AF608 00000000 */  nop
    /* 3AF60C 004AF60C 00000000 */  nop
.size func_004af5e0, 0x30
