.section .text
.set noat
.set noreorder
glabel func_0050d998
    /* 40D998 0050D998 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D99C 0050D99C 2D30A000 */  daddu      $6, $5, $0
    /* 40D9A0 0050D9A0 0000BFFF */  sd         $31, 0x0($29)
    /* 40D9A4 0050D9A4 2D100000 */  daddu      $2, $0, $0
    /* 40D9A8 0050D9A8 02008010 */  beqz       $4, .L0050D9B4
    /* 40D9AC 0050D9AC 03000524 */   addiu     $5, $0, 0x3
    /* 40D9B0 0050D9B0 3C00828C */  lw         $2, 0x3C($4)
  .L0050D9B4:
    /* 40D9B4 0050D9B4 0000BFDF */  ld         $31, 0x0($29)
    /* 40D9B8 0050D9B8 2D204000 */  daddu      $4, $2, $0
    /* 40D9BC 0050D9BC 70681408 */  j          func_0051a1c0
    /* 40D9C0 0050D9C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 40D9C4 0050D9C4 00000000 */  nop
.size func_0050d998, 0x30
