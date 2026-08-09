.section .text
.set noat
.set noreorder
glabel func_004cecb0
    /* 3CECB0 004CECB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CECB4 004CECB4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CECB8 004CECB8 0400848C */  lw         $4, 0x4($4)
    /* 3CECBC 004CECBC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CECC0 004CECC0 5E0E1308 */  j          func_004c3978
    /* 3CECC4 004CECC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cecb0, 0x18
