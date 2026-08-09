.section .text
.set noat
.set noreorder
glabel func_004cedd8
    /* 3CEDD8 004CEDD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEDDC 004CEDDC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEDE0 004CEDE0 0400848C */  lw         $4, 0x4($4)
    /* 3CEDE4 004CEDE4 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEDE8 004CEDE8 1A0F1308 */  j          func_004c3c68
    /* 3CEDEC 004CEDEC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cedd8, 0x18
