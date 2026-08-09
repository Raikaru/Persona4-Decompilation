.section .text
.set noat
.set noreorder
glabel func_004d5320
    /* 3D5320 004D5320 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5324 004D5324 0000BFFF */  sd         $31, 0x0($29)
    /* 3D5328 004D5328 0400848C */  lw         $4, 0x4($4)
    /* 3D532C 004D532C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5330 004D5330 EE3B1308 */  j          func_004cefb8
    /* 3D5334 004D5334 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5320, 0x18
