.section .text
.set noat
.set noreorder
glabel func_004be2d0
    /* 3BE2D0 004BE2D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE2D4 004BE2D4 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE2D8 004BE2D8 0400848C */  lw         $4, 0x4($4)
    /* 3BE2DC 004BE2DC 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE2E0 004BE2E0 887C1308 */  j          func_004df220
    /* 3BE2E4 004BE2E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be2d0, 0x18
