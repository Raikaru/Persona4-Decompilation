.section .text
.set noat
.set noreorder
glabel func_004ced90
    /* 3CED90 004CED90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CED94 004CED94 0000BFFF */  sd         $31, 0x0($29)
    /* 3CED98 004CED98 0400848C */  lw         $4, 0x4($4)
    /* 3CED9C 004CED9C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEDA0 004CEDA0 F20E1308 */  j          func_004c3bc8
    /* 3CEDA4 004CEDA4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ced90, 0x18
