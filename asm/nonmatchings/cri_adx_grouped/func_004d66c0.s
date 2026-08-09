.section .text
.set noat
.set noreorder
glabel func_004d66c0
    /* 3D66C0 004D66C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D66C4 004D66C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D66C8 004D66C8 0400848C */  lw         $4, 0x4($4)
    /* 3D66CC 004D66CC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D66D0 004D66D0 4A3B1308 */  j          func_004ced28
    /* 3D66D4 004D66D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d66c0, 0x18
