.section .text
.set noat
.set noreorder
glabel func_0050e228
    /* 40E228 0050E228 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E22C 0050E22C 2D30A000 */  daddu      $6, $5, $0
    /* 40E230 0050E230 0000BFFF */  sd         $31, 0x0($29)
    /* 40E234 0050E234 49000524 */  addiu      $5, $0, 0x49
    /* 40E238 0050E238 3C00848C */  lw         $4, 0x3C($4)
    /* 40E23C 0050E23C 0000BFDF */  ld         $31, 0x0($29)
    /* 40E240 0050E240 64931408 */  j          func_00524d90
    /* 40E244 0050E244 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e228, 0x20
