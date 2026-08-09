.section .text
.set noat
.set noreorder
glabel func_0050d408
    /* 40D408 0050D408 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D40C 0050D40C 2D30A000 */  daddu      $6, $5, $0
    /* 40D410 0050D410 0000BFFF */  sd         $31, 0x0($29)
    /* 40D414 0050D414 2C000524 */  addiu      $5, $0, 0x2C
    /* 40D418 0050D418 3C00848C */  lw         $4, 0x3C($4)
    /* 40D41C 0050D41C 0000BFDF */  ld         $31, 0x0($29)
    /* 40D420 0050D420 64931408 */  j          func_00524d90
    /* 40D424 0050D424 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050d408, 0x20
