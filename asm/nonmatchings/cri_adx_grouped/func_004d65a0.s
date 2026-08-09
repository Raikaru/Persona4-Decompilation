.section .text
.set noat
.set noreorder
glabel func_004d65a0
    /* 3D65A0 004D65A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D65A4 004D65A4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D65A8 004D65A8 0400848C */  lw         $4, 0x4($4)
    /* 3D65AC 004D65AC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D65B0 004D65B0 323B1308 */  j          func_004cecc8
    /* 3D65B4 004D65B4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d65a0, 0x18
