.section .text
.set noat
.set noreorder
glabel func_003bfe60
    /* 2BFE60 003BFE60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2BFE64 003BFE64 3C00053C */  lui        $5, %hi(func_003be940)
    /* 2BFE68 003BFE68 0000BFFF */  sd         $31, 0x0($29)
    /* 2BFE6C 003BFE6C 40E9A524 */  addiu      $5, $5, %lo(func_003be940)
    /* 2BFE70 003BFE70 1C00A627 */  addiu      $6, $29, 0x1C
    /* 2BFE74 003BFE74 CCFF0E0C */  jal        func_003bff30
    /* 2BFE78 003BFE78 1C00A0AF */   sw        $0, 0x1C($29)
    /* 2BFE7C 003BFE7C 1C00A28F */  lw         $2, 0x1C($29)
    /* 2BFE80 003BFE80 0000BFDF */  ld         $31, 0x0($29)
    /* 2BFE84 003BFE84 0800E003 */  jr         $31
    /* 2BFE88 003BFE88 2000BD27 */   addiu     $29, $29, 0x20
    /* 2BFE8C 003BFE8C 00000000 */  nop
.size func_003bfe60, 0x30
