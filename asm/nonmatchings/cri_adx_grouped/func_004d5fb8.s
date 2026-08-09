.section .text
.set noat
.set noreorder
glabel func_004d5fb8
    /* 3D5FB8 004D5FB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5FBC 004D5FBC 06008014 */  bnez       $4, .L004D5FD8
    /* 3D5FC0 004D5FC0 0000BFFF */   sd        $31, 0x0($29)
    /* 3D5FC4 004D5FC4 7600043C */  lui        $4, %hi(D_00759190)
    /* 3D5FC8 004D5FC8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5FCC 004D5FCC 90918424 */  addiu      $4, $4, %lo(D_00759190)
    /* 3D5FD0 004D5FD0 A61A1308 */  j          func_004c6a98
    /* 3D5FD4 004D5FD4 1000BD27 */   addiu     $29, $29, 0x10
  .L004D5FD8:
    /* 3D5FD8 004D5FD8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5FDC 004D5FDC 700085A0 */  sb         $5, 0x70($4)
    /* 3D5FE0 004D5FE0 0800E003 */  jr         $31
    /* 3D5FE4 004D5FE4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5fb8, 0x30
