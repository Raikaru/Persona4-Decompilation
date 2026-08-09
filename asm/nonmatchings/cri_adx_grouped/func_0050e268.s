.section .text
.set noat
.set noreorder
glabel func_0050e268
    /* 40E268 0050E268 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E26C 0050E26C 2D30A000 */  daddu      $6, $5, $0
    /* 40E270 0050E270 0000BFFF */  sd         $31, 0x0($29)
    /* 40E274 0050E274 39000524 */  addiu      $5, $0, 0x39
    /* 40E278 0050E278 3C00848C */  lw         $4, 0x3C($4)
    /* 40E27C 0050E27C 0000BFDF */  ld         $31, 0x0($29)
    /* 40E280 0050E280 64931408 */  j          func_00524d90
    /* 40E284 0050E284 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e268, 0x20
