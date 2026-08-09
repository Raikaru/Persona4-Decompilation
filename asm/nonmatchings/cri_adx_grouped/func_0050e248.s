.section .text
.set noat
.set noreorder
glabel func_0050e248
    /* 40E248 0050E248 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E24C 0050E24C 2D30A000 */  daddu      $6, $5, $0
    /* 40E250 0050E250 0000BFFF */  sd         $31, 0x0($29)
    /* 40E254 0050E254 38000524 */  addiu      $5, $0, 0x38
    /* 40E258 0050E258 3C00848C */  lw         $4, 0x3C($4)
    /* 40E25C 0050E25C 0000BFDF */  ld         $31, 0x0($29)
    /* 40E260 0050E260 64931408 */  j          func_00524d90
    /* 40E264 0050E264 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e248, 0x20
