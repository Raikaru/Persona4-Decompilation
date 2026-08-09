.section .text
.set noat
.set noreorder
glabel func_004cedc0
    /* 3CEDC0 004CEDC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEDC4 004CEDC4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEDC8 004CEDC8 0400848C */  lw         $4, 0x4($4)
    /* 3CEDCC 004CEDCC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEDD0 004CEDD0 020F1308 */  j          func_004c3c08
    /* 3CEDD4 004CEDD4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cedc0, 0x18
