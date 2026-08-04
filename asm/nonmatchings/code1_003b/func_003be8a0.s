.section .text
.set noat
.set noreorder
glabel func_003be8a0
    /* 2BE8A0 003BE8A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BE8A4 003BE8A4 6C00C28C */  lw         $2, 0x6C($6)
    /* 2BE8A8 003BE8A8 2000BFFF */  sd         $31, 0x20($29)
    /* 2BE8AC 003BE8AC 1000B17F */  sq         $17, 0x10($29)
    /* 2BE8B0 003BE8B0 0000B07F */  sq         $16, 0x0($29)
    /* 2BE8B4 003BE8B4 2D888000 */  daddu      $17, $4, $0
    /* 2BE8B8 003BE8B8 2D80C000 */  daddu      $16, $6, $0
    /* 2BE8BC 003BE8BC 2C004524 */  addiu      $5, $2, 0x2C
    /* 2BE8C0 003BE8C0 907C0F0C */  jal        func_003df240
    /* 2BE8C4 003BE8C4 04000624 */   addiu     $6, $0, 0x4
    /* 2BE8C8 003BE8C8 03004014 */  bnez       $2, .L003BE8D8
    /* 2BE8CC 003BE8CC 00000000 */   nop
    /* 2BE8D0 003BE8D0 08000010 */  b          .L003BE8F4
    /* 2BE8D4 003BE8D4 2D100000 */   daddu     $2, $0, $0
  .L003BE8D8:
    /* 2BE8D8 003BE8D8 6C00028E */  lw         $2, 0x6C($16)
    /* 2BE8DC 003BE8DC 2D202002 */  daddu      $4, $17, $0
    /* 2BE8E0 003BE8E0 04000624 */  addiu      $6, $0, 0x4
    /* 2BE8E4 003BE8E4 907C0F0C */  jal        func_003df240
    /* 2BE8E8 003BE8E8 30004524 */   addiu     $5, $2, 0x30
    /* 2BE8EC 003BE8EC 0A880200 */  movz       $17, $0, $2
    /* 2BE8F0 003BE8F0 2D102002 */  daddu      $2, $17, $0
  .L003BE8F4:
    /* 2BE8F4 003BE8F4 2000BFDF */  ld         $31, 0x20($29)
    /* 2BE8F8 003BE8F8 1000B17B */  lq         $17, 0x10($29)
    /* 2BE8FC 003BE8FC 0000B07B */  lq         $16, 0x0($29)
    /* 2BE900 003BE900 0800E003 */  jr         $31
    /* 2BE904 003BE904 3000BD27 */   addiu     $29, $29, 0x30
    /* 2BE908 003BE908 00000000 */  nop
    /* 2BE90C 003BE90C 00000000 */  nop
.size func_003be8a0, 0x70
