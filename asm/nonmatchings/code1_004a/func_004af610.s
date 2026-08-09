.section .text
.set noat
.set noreorder
glabel func_004af610
    /* 3AF610 004AF610 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AF614 004AF614 0000BFFF */  sd         $31, 0x0($29)
    /* 3AF618 004AF618 5800848C */  lw         $4, 0x58($4)
    /* 3AF61C 004AF61C 844B120C */  jal        func_00492e10
    /* 3AF620 004AF620 00000000 */   nop
    /* 3AF624 004AF624 0000BFDF */  ld         $31, 0x0($29)
    /* 3AF628 004AF628 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AF62C 004AF62C 0800E003 */  jr         $31
    /* 3AF630 004AF630 00000000 */   nop
    /* 3AF634 004AF634 00000000 */  nop
    /* 3AF638 004AF638 00000000 */  nop
    /* 3AF63C 004AF63C 00000000 */  nop
.size func_004af610, 0x30
