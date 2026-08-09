.section .text
.set noat
.set noreorder
glabel func_004ceda8
    /* 3CEDA8 004CEDA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEDAC 004CEDAC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEDB0 004CEDB0 0400848C */  lw         $4, 0x4($4)
    /* 3CEDB4 004CEDB4 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEDB8 004CEDB8 F40E1308 */  j          func_004c3bd0
    /* 3CEDBC 004CEDBC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ceda8, 0x18
