.section .text
.set noat
.set noreorder
glabel func_004cec68
    /* 3CEC68 004CEC68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEC6C 004CEC6C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEC70 004CEC70 0400848C */  lw         $4, 0x4($4)
    /* 3CEC74 004CEC74 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEC78 004CEC78 880F1308 */  j          func_004c3e20
    /* 3CEC7C 004CEC7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cec68, 0x18
