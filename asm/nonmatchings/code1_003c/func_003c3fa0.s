.section .text
.set noat
.set noreorder
glabel func_003c3fa0
    /* 2C3FA0 003C3FA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2C3FA4 003C3FA4 0800C28C */  lw         $2, 0x8($6)
    /* 2C3FA8 003C3FA8 2000BFFF */  sd         $31, 0x20($29)
    /* 2C3FAC 003C3FAC 1000B17F */  sq         $17, 0x10($29)
    /* 2C3FB0 003C3FB0 0000B07F */  sq         $16, 0x0($29)
    /* 2C3FB4 003C3FB4 2D888000 */  daddu      $17, $4, $0
    /* 2C3FB8 003C3FB8 2D80C000 */  daddu      $16, $6, $0
    /* 2C3FBC 003C3FBC 2C004524 */  addiu      $5, $2, 0x2C
    /* 2C3FC0 003C3FC0 907C0F0C */  jal        func_003df240
    /* 2C3FC4 003C3FC4 04000624 */   addiu     $6, $0, 0x4
    /* 2C3FC8 003C3FC8 03004014 */  bnez       $2, .L003C3FD8
    /* 2C3FCC 003C3FCC 00000000 */   nop
    /* 2C3FD0 003C3FD0 08000010 */  b          .L003C3FF4
    /* 2C3FD4 003C3FD4 2D100000 */   daddu     $2, $0, $0
  .L003C3FD8:
    /* 2C3FD8 003C3FD8 0800028E */  lw         $2, 0x8($16)
    /* 2C3FDC 003C3FDC 2D202002 */  daddu      $4, $17, $0
    /* 2C3FE0 003C3FE0 04000624 */  addiu      $6, $0, 0x4
    /* 2C3FE4 003C3FE4 907C0F0C */  jal        func_003df240
    /* 2C3FE8 003C3FE8 30004524 */   addiu     $5, $2, 0x30
    /* 2C3FEC 003C3FEC 0A880200 */  movz       $17, $0, $2
    /* 2C3FF0 003C3FF0 2D102002 */  daddu      $2, $17, $0
  .L003C3FF4:
    /* 2C3FF4 003C3FF4 2000BFDF */  ld         $31, 0x20($29)
    /* 2C3FF8 003C3FF8 1000B17B */  lq         $17, 0x10($29)
    /* 2C3FFC 003C3FFC 0000B07B */  lq         $16, 0x0($29)
    /* 2C4000 003C4000 0800E003 */  jr         $31
    /* 2C4004 003C4004 3000BD27 */   addiu     $29, $29, 0x30
    /* 2C4008 003C4008 00000000 */  nop
    /* 2C400C 003C400C 00000000 */  nop
.size func_003c3fa0, 0x70
