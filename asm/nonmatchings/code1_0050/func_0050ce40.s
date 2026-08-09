.section .text
.set noat
.set noreorder
glabel func_0050ce40
    /* 40CE40 0050CE40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CE44 0050CE44 2D30A000 */  daddu      $6, $5, $0
    /* 40CE48 0050CE48 0000BFFF */  sd         $31, 0x0($29)
    /* 40CE4C 0050CE4C 05000524 */  addiu      $5, $0, 0x5
    /* 40CE50 0050CE50 3C00848C */  lw         $4, 0x3C($4)
    /* 40CE54 0050CE54 0000BFDF */  ld         $31, 0x0($29)
    /* 40CE58 0050CE58 64931408 */  j          func_00524d90
    /* 40CE5C 0050CE5C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050ce40, 0x20
