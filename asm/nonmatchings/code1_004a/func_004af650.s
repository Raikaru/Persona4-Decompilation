.section .text
.set noat
.set noreorder
glabel func_004af650
    /* 3AF650 004AF650 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AF654 004AF654 0000BFFF */  sd         $31, 0x0($29)
    /* 3AF658 004AF658 08008CE4 */  swc1       $f12, 0x8($4)
    /* 3AF65C 004AF65C 5800848C */  lw         $4, 0x58($4)
    /* 3AF660 004AF660 8C4B120C */  jal        func_00492e30
    /* 3AF664 004AF664 00000000 */   nop
    /* 3AF668 004AF668 0000BFDF */  ld         $31, 0x0($29)
    /* 3AF66C 004AF66C 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AF670 004AF670 0800E003 */  jr         $31
    /* 3AF674 004AF674 00000000 */   nop
    /* 3AF678 004AF678 00000000 */  nop
    /* 3AF67C 004AF67C 00000000 */  nop
.size func_004af650, 0x30
