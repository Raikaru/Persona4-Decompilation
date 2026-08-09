.section .text
.set noat
.set noreorder
glabel func_0050d2b8
    /* 40D2B8 0050D2B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D2BC 0050D2BC 0000BFFF */  sd         $31, 0x0($29)
    /* 40D2C0 0050D2C0 3C00828C */  lw         $2, 0x3C($4)
    /* 40D2C4 0050D2C4 06004014 */  bnez       $2, .L0050D2E0
    /* 40D2C8 0050D2C8 2D20A000 */   daddu     $4, $5, $0
    /* 40D2CC 0050D2CC 0000BFDF */  ld         $31, 0x0($29)
    /* 40D2D0 0050D2D0 2D280000 */  daddu      $5, $0, $0
    /* 40D2D4 0050D2D4 A8000624 */  addiu      $6, $0, 0xA8
    /* 40D2D8 0050D2D8 72FE1008 */  j          func_0043f9c8
    /* 40D2DC 0050D2DC 1000BD27 */   addiu     $29, $29, 0x10
  .L0050D2E0:
    /* 40D2E0 0050D2E0 0000BFDF */  ld         $31, 0x0($29)
    /* 40D2E4 0050D2E4 2D204000 */  daddu      $4, $2, $0
    /* 40D2E8 0050D2E8 60941408 */  j          func_00525180
    /* 40D2EC 0050D2EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050d2b8, 0x38
