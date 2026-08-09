.section .text
.set noat
.set noreorder
glabel func_004ceee0
    /* 3CEEE0 004CEEE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEEE4 004CEEE4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEEE8 004CEEE8 0400848C */  lw         $4, 0x4($4)
    /* 3CEEEC 004CEEEC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEEF0 004CEEF0 320F1308 */  j          func_004c3cc8
    /* 3CEEF4 004CEEF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ceee0, 0x18
