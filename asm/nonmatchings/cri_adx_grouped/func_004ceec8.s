.section .text
.set noat
.set noreorder
glabel func_004ceec8
    /* 3CEEC8 004CEEC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEECC 004CEECC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEED0 004CEED0 0400848C */  lw         $4, 0x4($4)
    /* 3CEED4 004CEED4 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEED8 004CEED8 300F1308 */  j          func_004c3cc0
    /* 3CEEDC 004CEEDC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ceec8, 0x18
