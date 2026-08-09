.section .text
.set noat
.set noreorder
glabel func_004d6340
    /* 3D6340 004D6340 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6344 004D6344 0000BFFF */  sd         $31, 0x0($29)
    /* 3D6348 004D6348 0400848C */  lw         $4, 0x4($4)
    /* 3D634C 004D634C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D6350 004D6350 4C371308 */  j          func_004cdd30
    /* 3D6354 004D6354 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d6340, 0x18
