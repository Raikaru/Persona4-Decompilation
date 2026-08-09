.section .text
.set noat
.set noreorder
glabel func_004ed530
    /* 3ED530 004ED530 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED534 004ED534 7400023C */  lui        $2, %hi(D_0073DB00)
    /* 3ED538 004ED538 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED53C 004ED53C 00DB5024 */  addiu      $16, $2, %lo(D_0073DB00)
    /* 3ED540 004ED540 0000028E */  lw         $2, 0x0($16)
    /* 3ED544 004ED544 07004014 */  bnez       $2, .L004ED564
    /* 3ED548 004ED548 0800BFFF */   sd        $31, 0x8($29)
    /* 3ED54C 004ED54C 7400043C */  lui        $4, %hi(D_0073DB08)
    /* 3ED550 004ED550 2D280000 */  daddu      $5, $0, $0
    /* 3ED554 004ED554 08DB8424 */  addiu      $4, $4, %lo(D_0073DB08)
    /* 3ED558 004ED558 72FE100C */  jal        func_0043f9c8
    /* 3ED55C 004ED55C 80040624 */   addiu     $6, $0, 0x480
    /* 3ED560 004ED560 0000028E */  lw         $2, 0x0($16)
  .L004ED564:
    /* 3ED564 004ED564 01004224 */  addiu      $2, $2, 0x1
    /* 3ED568 004ED568 0800BFDF */  ld         $31, 0x8($29)
    /* 3ED56C 004ED56C 000002AE */  sw         $2, 0x0($16)
    /* 3ED570 004ED570 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED574 004ED574 0800E003 */  jr         $31
    /* 3ED578 004ED578 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED57C 004ED57C 00000000 */  nop
.size func_004ed530, 0x50
