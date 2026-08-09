.section .text
.set noat
.set noreorder
glabel func_004ced78
    /* 3CED78 004CED78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CED7C 004CED7C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CED80 004CED80 0400848C */  lw         $4, 0x4($4)
    /* 3CED84 004CED84 0000BFDF */  ld         $31, 0x0($29)
    /* 3CED88 004CED88 F00E1308 */  j          func_004c3bc0
    /* 3CED8C 004CED8C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ced78, 0x18
