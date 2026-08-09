.section .text
.set noat
.set noreorder
glabel func_004d6d00
    /* 3D6D00 004D6D00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6D04 004D6D04 0000BFFF */  sd         $31, 0x0($29)
    /* 3D6D08 004D6D08 0400848C */  lw         $4, 0x4($4)
    /* 3D6D0C 004D6D0C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D6D10 004D6D10 2C3B1308 */  j          func_004cecb0
    /* 3D6D14 004D6D14 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d6d00, 0x18
