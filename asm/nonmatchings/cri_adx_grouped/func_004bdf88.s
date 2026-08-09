.section .text
.set noat
.set noreorder
glabel func_004bdf88
    /* 3BDF88 004BDF88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDF8C 004BDF8C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BDF90 004BDF90 0400848C */  lw         $4, 0x4($4)
    /* 3BDF94 004BDF94 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDF98 004BDF98 70581308 */  j          func_004d61c0
    /* 3BDF9C 004BDF9C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bdf88, 0x18
