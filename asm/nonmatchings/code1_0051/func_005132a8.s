.section .text
.set noat
.set noreorder
glabel func_005132a8
    /* 4132A8 005132A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4132AC 005132AC 2D30A000 */  daddu      $6, $5, $0
    /* 4132B0 005132B0 0000BFFF */  sd         $31, 0x0($29)
    /* 4132B4 005132B4 1020858C */  lw         $5, 0x2010($4)
    /* 4132B8 005132B8 0000BFDF */  ld         $31, 0x0($29)
    /* 4132BC 005132BC 60561408 */  j          func_00515980
    /* 4132C0 005132C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4132C4 005132C4 00000000 */  nop
.size func_005132a8, 0x20
