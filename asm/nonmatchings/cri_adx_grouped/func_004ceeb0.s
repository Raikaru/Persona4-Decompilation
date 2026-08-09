.section .text
.set noat
.set noreorder
glabel func_004ceeb0
    /* 3CEEB0 004CEEB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEEB4 004CEEB4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEEB8 004CEEB8 0400848C */  lw         $4, 0x4($4)
    /* 3CEEBC 004CEEBC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEEC0 004CEEC0 2E0F1308 */  j          func_004c3cb8
    /* 3CEEC4 004CEEC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ceeb0, 0x18
