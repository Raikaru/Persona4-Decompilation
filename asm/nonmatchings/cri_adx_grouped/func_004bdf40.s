.section .text
.set noat
.set noreorder
glabel func_004bdf40
    /* 3BDF40 004BDF40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDF44 004BDF44 0000BFFF */  sd         $31, 0x0($29)
    /* 3BDF48 004BDF48 0400848C */  lw         $4, 0x4($4)
    /* 3BDF4C 004BDF4C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDF50 004BDF50 585C1308 */  j          func_004d7160
    /* 3BDF54 004BDF54 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bdf40, 0x18
