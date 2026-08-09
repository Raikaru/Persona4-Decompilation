.section .text
.set noat
.set noreorder
glabel func_0050e208
    /* 40E208 0050E208 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E20C 0050E20C 2D30A000 */  daddu      $6, $5, $0
    /* 40E210 0050E210 0000BFFF */  sd         $31, 0x0($29)
    /* 40E214 0050E214 50000524 */  addiu      $5, $0, 0x50
    /* 40E218 0050E218 3C00848C */  lw         $4, 0x3C($4)
    /* 40E21C 0050E21C 0000BFDF */  ld         $31, 0x0($29)
    /* 40E220 0050E220 64931408 */  j          func_00524d90
    /* 40E224 0050E224 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e208, 0x20
