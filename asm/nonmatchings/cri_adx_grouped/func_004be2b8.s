.section .text
.set noat
.set noreorder
glabel func_004be2b8
    /* 3BE2B8 004BE2B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE2BC 004BE2BC 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE2C0 004BE2C0 0400848C */  lw         $4, 0x4($4)
    /* 3BE2C4 004BE2C4 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE2C8 004BE2C8 587B1308 */  j          func_004ded60
    /* 3BE2CC 004BE2CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be2b8, 0x18
