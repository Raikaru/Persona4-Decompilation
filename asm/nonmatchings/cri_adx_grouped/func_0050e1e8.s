.section .text
.set noat
.set noreorder
glabel func_0050e1e8
    /* 40E1E8 0050E1E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E1EC 0050E1EC 2D30A000 */  daddu      $6, $5, $0
    /* 40E1F0 0050E1F0 0000BFFF */  sd         $31, 0x0($29)
    /* 40E1F4 0050E1F4 4F000524 */  addiu      $5, $0, 0x4F
    /* 40E1F8 0050E1F8 3C00848C */  lw         $4, 0x3C($4)
    /* 40E1FC 0050E1FC 0000BFDF */  ld         $31, 0x0($29)
    /* 40E200 0050E200 64931408 */  j          func_00524d90
    /* 40E204 0050E204 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e1e8, 0x20
